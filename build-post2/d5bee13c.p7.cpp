
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const0122baa3ac55f1b433944eb1;
extern u64 v_const06abaa100ecef791ce028c56;
extern u64 v_const0933fb667296882d8c45abca;
extern u64 v_const1064263932db82f2cf6d4ac2;
extern u64 v_const1ca60a80dbae6414bef23d65;
extern u64 v_const1ef5dd96b7ac876a994a9ca1;
extern u64 v_const3d914f9348c9cc0ff8a79716;
extern u64 v_const3fdba35f04dc8c462986c992;
extern u64 v_const4a44dc15364204a80fe80e90;
extern u64 v_const4a59dbb9cb3129dfcc75170b;
extern u64 v_const4e07408562bedb8b60ce05c1;
extern u64 v_const52b5e20f559958f34e533431;
extern u64 v_const5d6ab4fefffae2e4c15033db;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const60e3114d9b4b6577eea8cbc0;
extern u64 v_const65c80aac3433a01ef8a7f298;
extern u64 v_const6b51d431df5d7f141cbececc;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const73475cb40a568e8da8a045ce;
extern u64 v_const76237108756d80d8c9f21f56;
extern u64 v_const8c6798fa821ed573f6b89759;
extern u64 v_const90d5df9a2327146dec6b6cee;
extern u64 v_const90fb9068eda6f2d68bb61c33;
extern u64 v_consta0e8b3efb8cecb7adf11ee61;
extern u64 v_consta24220c5193376967f1fa95e;
extern u64 v_constb177cd86b4c517da8099d6e4;
extern u64 v_constb642bb32c0b8fd35118770e8;
extern u64 v_constb9e118781cea1f9fa01462e0;
extern u64 v_constc8dd3fe14ad7db61de7362fc;
extern u64 v_constcd2a69ce5ca278db1d6da969;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_constd59eced1ded07f84c145592f;
extern u64 v_constdd7bbf31ce5f578b9805e840;
extern u64 v_conste711e3685c3e87fc5763620f;


void slog_rules_cf29fd125e424f92b(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre (let __tconst6pJx1346 constb9e118781cea1f9fa01462e0) (let __tconst62iD1347 const0122baa3ac55f1b433944eb1) (let __tconst3W5V576 const60e3114d9b4b6577eea8cbc0) (let _00024sqc0LoQ973 const6b86b273ff34fce19d6b804e) (let _00024sqc1LSK974 const5feceb66ffc86f38d952786c) (let _00024sqo9raf975 const5feceb66ffc86f38d952786c) (let _00024sqo4FnC976 const5feceb66ffc86f38d952786c)) (probe $seq_atr (1 0 2) 1 _00024sqo4FnC976 __t9AVR579 _00024seq1) (body (join $seq_at (1 0 2) 3 _00024sqo9raf975 __t9AVR579 _00024seq1) (exists _enum (1 0) 1 __tconst6pJx1346) (exists _enum (1 0) 1 __tconst62iD1347) (join delta (1 2 0) 2 __tconst3W5V576 _00024seq1 __t9o8A577) (join _enum (1 0) 1 __tconst6pJx1346 __t18UG578) (join boolval (0 1) 2 __t9AVR579 __t18UG578) (join _enum (1 0) 1 __tconst62iD1347 __t2cB8574) (letp _00024sql99sk971 (aslst _00024seq1)) (let chk2O8A2069 (llen _00024sql99sk971)) (eq _00024sqc0LoQ973 chk2O8A2069) (letp chk5r1O2070 (lref _00024sql99sk971 _00024sqc1LSK974)) (eq __t9AVR579 chk5r1O2070)) (head (emit-temp temp7pkd2063 __t9o8A577) (mkstruct boolval (1 0) __t7CgS575 __t2cB8574)) interp.slog:118 #f)
  class ReadTask7 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex0;  slog::Index** _enumindex1;  slog::Index** _enumindex2;  slog::Index** deltaindex3;  slog::Index** _enumindex4;  slog::Index** boolvalindex5;  slog::Index** _enumindex6;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7pkd2063");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord8({1, 0, 2});
      slog::Relation* readrel9 = db->getRelation("$seq_atr");
      driver_index = readrel9->getIndex(ord8, true);
      std::vector<u16> ord10({1, 0, 2});
      slog::Relation* readrel11 = db->getRelation("$seq_at");
      $seq_atindex0 = readrel11->getIndex(ord10, false);
      std::vector<u16> ord12({1, 0});
      slog::Relation* readrel13 = db->getRelation("_enum");
      _enumindex1 = readrel13->getIndex(ord12, false);
      std::vector<u16> ord14({1, 0});
      slog::Relation* readrel15 = db->getRelation("_enum");
      _enumindex2 = readrel15->getIndex(ord14, false);
      std::vector<u16> ord16({1, 2, 0});
      slog::Relation* readrel17 = db->getRelation("delta");
      deltaindex3 = readrel17->getIndex(ord16, false);
      std::vector<u16> ord18({1, 0});
      slog::Relation* readrel19 = db->getRelation("_enum");
      _enumindex4 = readrel19->getIndex(ord18, false);
      std::vector<u16> ord20({0, 1});
      slog::Relation* readrel21 = db->getRelation("boolval");
      boolvalindex5 = readrel21->getIndex(ord20, false);
      std::vector<u16> ord22({1, 0});
      slog::Relation* readrel23 = db->getRelation("_enum");
      _enumindex6 = readrel23->getIndex(ord22, false);
  
    }
    ReadTask7(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_constb9e118781cea1f9fa01462e0;
      u64 v_c1 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c2 = v_const60e3114d9b4b6577eea8cbc0;
      u64 v_c3 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c4 = v_const5feceb66ffc86f38d952786c;
      u64 v_c5 = v_const5feceb66ffc86f38d952786c;
      u64 v_c6 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c6, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m24) {
        u64 v_c7 = m24[1];
        u64 v_c8 = m24[2];
        if (buckethash(v_c7) != bucket) return;
        slog::join_probe<3,3>($seq_atindex0, std::array<u64,3>{v_c5, v_c7, v_c8}, [&](const std::array<u64,3>& m25) {
          if (!slog::exists_probe<2,1>(_enumindex1, std::array<u64,2>{v_c0, 0})) return;
          if (!slog::exists_probe<2,1>(_enumindex2, std::array<u64,2>{v_c1, 0})) return;
          slog::join_probe<3,2>(deltaindex3, std::array<u64,3>{v_c2, v_c8, 0}, [&](const std::array<u64,3>& m26) {
            u64 v_c9 = m26[2];
            slog::join_probe<2,1>(_enumindex4, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m27) {
              u64 v_c10 = m27[1];
              slog::join_probe<2,2>(boolvalindex5, std::array<u64,2>{v_c7, v_c10}, [&](const std::array<u64,2>& m28) {
                slog::join_probe<2,1>(_enumindex6, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m29) {
                  u64 v_c11 = m29[1];
                  bool ok30 = true;
                  u64 v_c12 = _prim_aslst(db, v_c8, &ok30);
                  if (!ok30) return;
                  u64 v_c13 = _prim_llen(db, v_c12);
                  if (v_c13 == slog_error) { slog::emit_pending_error(db, "interp.slog:118"); return; }
                  if (v_c3 != v_c13) return;
                  bool ok31 = true;
                  u64 v_c14 = _prim_lref(db, v_c12, v_c4, &ok31);
                  if (!ok31) return;
                  if (v_c7 != v_c14) return;
                  ++_fires;
                  slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c9});
                  slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c11}, std::array<u16,2>{1, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:118", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask7* _cont = new ReadTask7(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask7(db,b), false);
  // (crule (pre (let __trid1hXk1529 conste711e3685c3e87fc5763620f) (let __trel5lBK1530 const4a59dbb9cb3129dfcc75170b) (let __tcol3jCh1531 const5feceb66ffc86f38d952786c) (let __trel2te41532 const4a59dbb9cb3129dfcc75170b) (let __tcol09lb1533 const6b86b273ff34fce19d6b804e) (let __trel20Bo1534 const4a59dbb9cb3129dfcc75170b) (let __tcol7YlO1535 constd4735e3a265e16eee03f5971)) (scan $sup70016x95x0x0x1 __d0 __d3 eb er rho rho2 t x) (body) (head (tycheck eb (accept (struct app) (struct boolean) (struct if) (struct lambda) (struct let) (struct letrec) (struct num) (struct primref) (struct ref) (struct sym)) __trid1hXk1529 __trel5lBK1530 __tcol3jCh1531 (1 2 3 4 0)) (tycheck rho2 (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid1hXk1529 __trel2te41532 __tcol09lb1533 (1 2 3 4 0)) (tycheck t (accept seq) __trid1hXk1529 __trel20Bo1534 __tcol7YlO1535 (1 2 3 4 0)) (mkstruct eval (1 2 3 0) __0MKd1528 eb rho2 t)) interp.slog:96 #f)
  class ReadTask45 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[4];
    slog::Index** head_index[4];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid43;  u32 sid32;  u32 sid33;  u32 sid34;  u32 sid35;  u32 sid36;  u32 sid37;  u32 sid42;  u32 sid44;  u32 sid38;  u32 sid39;  u32 sid40;  u32 sid41;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("malformed_deduction");
      head_rel[3] = db->getRelation("eval");
      outer_rel = db->getRelation("$sup70016x95x0x0x1");
      sid43 = db->getRelation("_enum")->getStructId();
      sid32 = db->getRelation("app")->getStructId();
      sid33 = db->getRelation("boolean")->getStructId();
      sid34 = db->getRelation("if")->getStructId();
      sid35 = db->getRelation("lambda")->getStructId();
      sid36 = db->getRelation("let")->getStructId();
      sid37 = db->getRelation("letrec")->getStructId();
      sid42 = db->getRelation("mbranch")->getStructId();
      sid44 = db->getRelation("mleaf")->getStructId();
      sid38 = db->getRelation("num")->getStructId();
      sid39 = db->getRelation("primref")->getStructId();
      sid40 = db->getRelation("ref")->getStructId();
      sid41 = db->getRelation("sym")->getStructId();
  
    }
    ReadTask45(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c15 = v_conste711e3685c3e87fc5763620f;
      u64 v_c16 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c17 = v_const5feceb66ffc86f38d952786c;
      u64 v_c18 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c19 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c20 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c21 = v_constd4735e3a265e16eee03f5971;
  
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
        u64 v_c22 = _t[0];
        u64 v_c23 = _t[1];
        u64 v_c24 = _t[2];
        u64 v_c25 = _t[3];
        u64 v_c26 = _t[4];
        u64 v_c27 = _t[5];
        u64 v_c28 = _t[6];
        u64 v_c29 = _t[7];
        ++_fires;
        if (!((is_struct(v_c24) && (decode_struct_id(v_c24) == sid32 || decode_struct_id(v_c24) == sid33 || decode_struct_id(v_c24) == sid34 || decode_struct_id(v_c24) == sid35 || decode_struct_id(v_c24) == sid36 || decode_struct_id(v_c24) == sid37 || decode_struct_id(v_c24) == sid38 || decode_struct_id(v_c24) == sid39 || decode_struct_id(v_c24) == sid40 || decode_struct_id(v_c24) == sid41))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c15, v_c16, v_c17, v_c24}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c27) && (decode_struct_id(v_c27) == sid42 || decode_struct_id(v_c27) == sid43 || decode_struct_id(v_c27) == sid44))))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c15, v_c18, v_c19, v_c27}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_seq(v_c28)))
        {
          slog::emit_struct<5>(head_rel[2], newbatch[2], std::array<u64,4>{v_c15, v_c20, v_c21, v_c28}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<4>(head_rel[3], newbatch[3], std::array<u64,3>{v_c24, v_c27, v_c28}, std::array<u16,4>{1, 2, 3, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
  
      if (_fires) db->bumpFires("interp.slog:96", "delta:$sup70016x95x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask45* _cont = new ReadTask45(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask45(db,b), false);
  // (crule (pre (let _00024sqc4455954 const6b86b273ff34fce19d6b804e) (let _00024sqc5dHY955 const5feceb66ffc86f38d952786c) (let _00024sqc3mQW956 const6b86b273ff34fce19d6b804e) (let _00024sqc1Quw957 const5feceb66ffc86f38d952786c)) (scan eval_args __t3b2p321 _00024seq0 rho t) (body (letp _00024sql0ZwN952 (aslst _00024seq0)) (let _00024sqn55gv953 (llen _00024sql0ZwN952)) (cmp ge _00024sqn55gv953 _00024sqc4455954) (letp e (lref _00024sql0ZwN952 _00024sqc5dHY955)) (let _00024sqp7qmy958 (_0002d _00024sqn55gv953 _00024sqc1Quw957)) (let es (lslice _00024sql0ZwN952 _00024sqc3mQW956 _00024sqp7qmy958))) (head (emit $sup70016x43x0x0x0 (0 2 3 4 5 1) _00024seq0 e es rho t __t3b2p321)) interp.slog:44 #f)
  class ReadTask46 : public slog::Task
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
      head_rel[0] = db->getRelation("$sup70016x43x0x0x0");
      std::vector<u16> ord47({0, 2, 3, 4, 5, 1});
      slog::Relation* readrel48 = db->getRelation("$sup70016x43x0x0x0");
      head_index[0] = readrel48->getIndex(ord47, false);
      outer_rel = db->getRelation("eval_args");
  
    }
    ReadTask46(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c30 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c31 = v_const5feceb66ffc86f38d952786c;
      u64 v_c32 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c33 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c26 = _t[2];
        u64 v_c28 = _t[3];
        bool ok49 = true;
        u64 v_c36 = _prim_aslst(db, v_c35, &ok49);
        if (!ok49) return;
        u64 v_c37 = _prim_llen(db, v_c36);
        if (v_c37 == slog_error) { slog::emit_pending_error(db, "interp.slog:44"); return; }
        u64 v_c38 = _prim_ge(db, v_c37, v_c30);
        if (v_c38 == slog_error) { slog::emit_pending_error(db, "interp.slog:44"); return; }
        if (!v_c38) return;
        bool ok51 = true;
        u64 v_c39 = _prim_lref(db, v_c36, v_c31, &ok51);
        if (!ok51) return;
        u64 v_c40 = _prim__0002d(db, v_c37, v_c33);
        if (v_c40 == slog_error) { slog::emit_pending_error(db, "interp.slog:44"); return; }
        u64 v_c41 = _prim_lslice(db, v_c36, v_c32, v_c40);
        if (v_c41 == slog_error) { slog::emit_pending_error(db, "interp.slog:44"); return; }
        ++_fires;
        slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c35, v_c39, v_c41, v_c26, v_c28, v_c34}, std::array<u16,6>{0, 2, 3, 4, 5, 1});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:44", "delta:eval_args", _fires);
  
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
  // (crule (pre) (scan temp2Uly1937 __t2Q40639 __t8cgD644 k) (body (let __t8xy6642 (_0002f k __t2Q40639))) (head (emit-temp temp6y8Y1938 __t2Q40639 __t8cgD644 __t8xy6642)) map.slog:22 #f)
  class ReadTask52 : public slog::Task
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
      head_rel[0] = db->getRelation("temp6y8Y1938");
      outer_rel = db->getRelation("temp2Uly1937");
  
    }
    ReadTask52(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c45 = _prim__0002f(db, v_c44, v_c42);
        if (v_c45 == slog_error) { slog::emit_pending_error(db, "map.slog:22"); return; }
        ++_fires;
        slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c42, v_c43, v_c45});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:22", "delta:temp2Uly1937", _fires);
  
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
  // (crule (pre) (scan mp_put_ans __t0mp6672 __v0) (body (exists $sup70016x92x0x0x1 (2 3 0 1 4 5 6 7 8 9) 2 __t0mp6672 __v0) (join-old eval (2 3 0 1) 1 (2 3 0 1) __v0 t __t3BcP671 eb) (exists $sup70016x92x0x0x0 (1 4 0 2 3 5) 2 eb t) (exists eval (3 1 0 2) 1 t) (exists mp_put (3 0 2 1) 2 t __t0mp6672) (exists let (3 0 1 2) 1 eb) (exists eval_ans (0 1) 1 __t3BcP671) (join-old $sup70016x92x0x0x1 (3 4 7 2 0 1 5 6 8 9) 4 (3 4 7 2 0 1 5 6 8 9) __v0 eb t __t0mp6672 __t5vg0669 __t7GLg670 er rho vr x) (join-old $sup70016x92x0x0x0 (0 3 4 1 2 5) 6 (0 3 4 1 2 5) __t5vg0669 rho t eb er x) (join-old eval (2 3 0 1) 4 (2 3 0 1) rho t __t7GLg670 er) (join-old mp_put (0 2 1 3) 4 (0 2 1 3) __t0mp6672 x rho t) (exists eval (2 3 0 1) 3 rho t __t5vg0669) (exists eval_ans (0 1) 2 __t7GLg670 vr) (join-old let (1 2 3 0) 3 (1 2 3 0) x er eb __t2w2P668) (join-old eval (2 3 0 1) 4 (2 3 0 1) rho t __t5vg0669 __t2w2P668) (join eval_ans (0 1) 2 __t7GLg670 vr) (join eval_ans (0 1) 1 __t3BcP671 v)) (head (emit eval_ans (0 1) __t5vg0669 v)) interp.slog:93 #f)
  class ReadTask77 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup70016x92x0x0x1index53;  slog::Index** evalindex54;  slog::Index** $sup70016x92x0x0x0index55;  slog::Index** evalindex56;  slog::Index** mp_putindex57;  slog::Index** letindex58;  slog::Index** eval_ansindex59;  slog::Index** $sup70016x92x0x0x1index60;  slog::Index** $sup70016x92x0x0x0index61;  slog::Index** evalindex62;  slog::Index** mp_putindex63;  slog::Index** evalindex64;  slog::Index** eval_ansindex65;  slog::Index** letindex66;  slog::Index** evalindex67;  slog::Index** eval_ansindex68;  slog::Index** eval_ansindex69;  slog::Index** evaldelta70;  slog::Index** $sup70016x92x0x0x1delta71;  slog::Index** $sup70016x92x0x0x0delta72;  slog::Index** evaldelta73;  slog::Index** mp_putdelta74;  slog::Index** letdelta75;  slog::Index** evaldelta76;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord78({0, 1});
      slog::Relation* readrel79 = db->getRelation("eval_ans");
      head_index[0] = readrel79->getIndex(ord78, false);
      outer_rel = db->getRelation("mp_put_ans");
      std::vector<u16> ord80({2, 3, 0, 1, 4, 5, 6, 7, 8, 9});
      slog::Relation* readrel81 = db->getRelation("$sup70016x92x0x0x1");
      $sup70016x92x0x0x1index53 = readrel81->getIndex(ord80, false);
      std::vector<u16> ord82({2, 3, 0, 1});
      slog::Relation* readrel83 = db->getRelation("eval");
      evalindex54 = readrel83->getIndex(ord82, false);
      std::vector<u16> ord84({2, 3, 0, 1});
      slog::Relation* readrel85 = db->getRelation("eval");
      evaldelta70 = readrel85->getIndex(ord84, true);
      std::vector<u16> ord86({1, 4, 0, 2, 3, 5});
      slog::Relation* readrel87 = db->getRelation("$sup70016x92x0x0x0");
      $sup70016x92x0x0x0index55 = readrel87->getIndex(ord86, false);
      std::vector<u16> ord88({3, 1, 0, 2});
      slog::Relation* readrel89 = db->getRelation("eval");
      evalindex56 = readrel89->getIndex(ord88, false);
      std::vector<u16> ord90({3, 0, 2, 1});
      slog::Relation* readrel91 = db->getRelation("mp_put");
      mp_putindex57 = readrel91->getIndex(ord90, false);
      std::vector<u16> ord92({3, 0, 1, 2});
      slog::Relation* readrel93 = db->getRelation("let");
      letindex58 = readrel93->getIndex(ord92, false);
      std::vector<u16> ord94({0, 1});
      slog::Relation* readrel95 = db->getRelation("eval_ans");
      eval_ansindex59 = readrel95->getIndex(ord94, false);
      std::vector<u16> ord96({3, 4, 7, 2, 0, 1, 5, 6, 8, 9});
      slog::Relation* readrel97 = db->getRelation("$sup70016x92x0x0x1");
      $sup70016x92x0x0x1index60 = readrel97->getIndex(ord96, false);
      std::vector<u16> ord98({3, 4, 7, 2, 0, 1, 5, 6, 8, 9});
      slog::Relation* readrel99 = db->getRelation("$sup70016x92x0x0x1");
      $sup70016x92x0x0x1delta71 = readrel99->getIndex(ord98, true);
      std::vector<u16> ord100({0, 3, 4, 1, 2, 5});
      slog::Relation* readrel101 = db->getRelation("$sup70016x92x0x0x0");
      $sup70016x92x0x0x0index61 = readrel101->getIndex(ord100, false);
      std::vector<u16> ord102({0, 3, 4, 1, 2, 5});
      slog::Relation* readrel103 = db->getRelation("$sup70016x92x0x0x0");
      $sup70016x92x0x0x0delta72 = readrel103->getIndex(ord102, true);
      std::vector<u16> ord104({2, 3, 0, 1});
      slog::Relation* readrel105 = db->getRelation("eval");
      evalindex62 = readrel105->getIndex(ord104, false);
      std::vector<u16> ord106({2, 3, 0, 1});
      slog::Relation* readrel107 = db->getRelation("eval");
      evaldelta73 = readrel107->getIndex(ord106, true);
      std::vector<u16> ord108({0, 2, 1, 3});
      slog::Relation* readrel109 = db->getRelation("mp_put");
      mp_putindex63 = readrel109->getIndex(ord108, false);
      std::vector<u16> ord110({0, 2, 1, 3});
      slog::Relation* readrel111 = db->getRelation("mp_put");
      mp_putdelta74 = readrel111->getIndex(ord110, true);
      std::vector<u16> ord112({2, 3, 0, 1});
      slog::Relation* readrel113 = db->getRelation("eval");
      evalindex64 = readrel113->getIndex(ord112, false);
      std::vector<u16> ord114({0, 1});
      slog::Relation* readrel115 = db->getRelation("eval_ans");
      eval_ansindex65 = readrel115->getIndex(ord114, false);
      std::vector<u16> ord116({1, 2, 3, 0});
      slog::Relation* readrel117 = db->getRelation("let");
      letindex66 = readrel117->getIndex(ord116, false);
      std::vector<u16> ord118({1, 2, 3, 0});
      slog::Relation* readrel119 = db->getRelation("let");
      letdelta75 = readrel119->getIndex(ord118, true);
      std::vector<u16> ord120({2, 3, 0, 1});
      slog::Relation* readrel121 = db->getRelation("eval");
      evalindex67 = readrel121->getIndex(ord120, false);
      std::vector<u16> ord122({2, 3, 0, 1});
      slog::Relation* readrel123 = db->getRelation("eval");
      evaldelta76 = readrel123->getIndex(ord122, true);
      std::vector<u16> ord124({0, 1});
      slog::Relation* readrel125 = db->getRelation("eval_ans");
      eval_ansindex68 = readrel125->getIndex(ord124, false);
      std::vector<u16> ord126({0, 1});
      slog::Relation* readrel127 = db->getRelation("eval_ans");
      eval_ansindex69 = readrel127->getIndex(ord126, false);
  
    }
    ReadTask77(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c46 = _t[0];
        u64 v_c47 = _t[1];
        if (!slog::exists_probe<10,2>($sup70016x92x0x0x1index53, std::array<u64,10>{v_c46, v_c47, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<4,1>(evalindex54, evaldelta70, std::array<u64,4>{v_c47, 0, 0, 0}, [&](const std::array<u64,4>& m128) {
          u64 v_c28 = m128[1]; u64 v_c48 = m128[2]; u64 v_c24 = m128[3];
          if (!slog::exists_probe<6,2>($sup70016x92x0x0x0index55, std::array<u64,6>{v_c24, v_c28, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<4,1>(evalindex56, std::array<u64,4>{v_c28, 0, 0, 0})) return;
          if (!slog::exists_probe<4,2>(mp_putindex57, std::array<u64,4>{v_c28, v_c46, 0, 0})) return;
          if (!slog::exists_probe<4,1>(letindex58, std::array<u64,4>{v_c24, 0, 0, 0})) return;
          if (!slog::exists_probe<2,1>(eval_ansindex59, std::array<u64,2>{v_c48, 0})) return;
          slog::join_probe_old<10,4>($sup70016x92x0x0x1index60, $sup70016x92x0x0x1delta71, std::array<u64,10>{v_c47, v_c24, v_c28, v_c46, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,10>& m129) {
            u64 v_c49 = m129[4]; u64 v_c50 = m129[5]; u64 v_c25 = m129[6]; u64 v_c26 = m129[7]; u64 v_c51 = m129[8]; u64 v_c29 = m129[9];
            slog::join_probe_old<6,6>($sup70016x92x0x0x0index61, $sup70016x92x0x0x0delta72, std::array<u64,6>{v_c49, v_c26, v_c28, v_c24, v_c25, v_c29}, [&](const std::array<u64,6>& m130) {
              slog::join_probe_old<4,4>(evalindex62, evaldelta73, std::array<u64,4>{v_c26, v_c28, v_c50, v_c25}, [&](const std::array<u64,4>& m131) {
                slog::join_probe_old<4,4>(mp_putindex63, mp_putdelta74, std::array<u64,4>{v_c46, v_c29, v_c26, v_c28}, [&](const std::array<u64,4>& m132) {
                  if (!slog::exists_probe<4,3>(evalindex64, std::array<u64,4>{v_c26, v_c28, v_c49, 0})) return;
                  if (!slog::exists_probe<2,2>(eval_ansindex65, std::array<u64,2>{v_c50, v_c51})) return;
                  slog::join_probe_old<4,3>(letindex66, letdelta75, std::array<u64,4>{v_c29, v_c25, v_c24, 0}, [&](const std::array<u64,4>& m133) {
                    u64 v_c52 = m133[3];
                    slog::join_probe_old<4,4>(evalindex67, evaldelta76, std::array<u64,4>{v_c26, v_c28, v_c49, v_c52}, [&](const std::array<u64,4>& m134) {
                      slog::join_probe<2,2>(eval_ansindex68, std::array<u64,2>{v_c50, v_c51}, [&](const std::array<u64,2>& m135) {
                        slog::join_probe<2,1>(eval_ansindex69, std::array<u64,2>{v_c48, 0}, [&](const std::array<u64,2>& m136) {
                          u64 v_c53 = m136[1];
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c49, v_c53}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:93", "delta:mp_put_ans", _fires);
  
      if (!_done)
      {
        ReadTask77* _cont = new ReadTask77(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask77(db,b), false);
  // (crule (pre) (scan app __t5a7h538 ef es) (body (exists eval (1 2 3 0) 1 __t5a7h538) (exists eval (1 2 3 0) 1 ef) (exists $sup70016x51x0x0x1 (5 6 0 7 9 1 2 3 4 8 10 11 12) 2 ef es) (exists eval_args (1 3 2 0) 1 es) (exists tick (1 2 0) 1 __t5a7h538) (join $sup70016x51x0x0x0 (1 2 4 0 3) 2 ef es t __t2z6s532 rho) (join eval (2 3 0 1) 4 rho t __t2z6s532 __t5a7h538) (exists $sup70016x51x0x0x1 (5 6 0 7 9 1 2 3 4 8 10 11 12) 5 ef es __t2z6s532 rho t) (exists eval_args (1 3 2 0) 3 es t rho) (exists tick (1 2 0) 2 __t5a7h538 t) (join eval (1 2 3 0) 3 ef rho t __t5qy8533) (exists eval_ans (0 1) 1 __t5qy8533) (join $sup70016x51x0x0x1 (5 6 0 7 9 1 2 3 4 8 10 11 12) 6 ef es __t2z6s532 rho t __t5qy8533 __t2srV536 __t0CD9539 eb rhoc t2 vs xs) (join eval_args (3 2 0 1) 4 t rho __t2srV536 es) (join-old tick (0 2 1) 3 (0 2 1) __t0CD9539 t __t5a7h538) (exists eval_args_ans (0 1) 2 __t2srV536 vs) (exists tick_ans (0 1) 2 __t0CD9539 t2) (exists lambda (1 2 0) 2 xs eb) (exists closure (2 0 1) 1 rhoc) (exists eval (3 1 0 2) 2 t2 eb) (join-old extend_env (1 2 3 0) 3 (1 2 3 0) rhoc xs t2 __t5fzh540) (join eval_args_ans (0 1) 2 __t2srV536 vs) (join tick_ans (0 1) 2 __t0CD9539 t2) (exists extend_env_ans (0 1) 1 __t5fzh540) (join lambda (1 2 0) 2 xs eb __t6iPm534) (join closure (1 2 0) 2 __t6iPm534 rhoc __t9dfl535) (join eval_ans (0 1) 2 __t5qy8533 __t9dfl535) (join eval (3 1 0 2) 2 t2 eb __t7TaT537 __v0) (join extend_env_ans (0 1) 2 __t5fzh540 __v0) (join eval_ans (0 1) 1 __t7TaT537 v)) (head (emit eval_ans (0 1) __t2z6s532 v)) interp.slog:52 #f)
  class ReadTask169 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex137;  slog::Index** evalindex138;  slog::Index** $sup70016x51x0x0x1index139;  slog::Index** eval_argsindex140;  slog::Index** tickindex141;  slog::Index** $sup70016x51x0x0x0index142;  slog::Index** evalindex143;  slog::Index** $sup70016x51x0x0x1index144;  slog::Index** eval_argsindex145;  slog::Index** tickindex146;  slog::Index** evalindex147;  slog::Index** eval_ansindex148;  slog::Index** $sup70016x51x0x0x1index149;  slog::Index** eval_argsindex150;  slog::Index** tickindex151;  slog::Index** eval_args_ansindex152;  slog::Index** tick_ansindex153;  slog::Index** lambdaindex154;  slog::Index** closureindex155;  slog::Index** evalindex156;  slog::Index** extend_envindex157;  slog::Index** eval_args_ansindex158;  slog::Index** tick_ansindex159;  slog::Index** extend_env_ansindex160;  slog::Index** lambdaindex161;  slog::Index** closureindex162;  slog::Index** eval_ansindex163;  slog::Index** evalindex164;  slog::Index** extend_env_ansindex165;  slog::Index** eval_ansindex166;  slog::Index** tickdelta167;  slog::Index** extend_envdelta168;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord170({0, 1});
      slog::Relation* readrel171 = db->getRelation("eval_ans");
      head_index[0] = readrel171->getIndex(ord170, false);
      outer_rel = db->getRelation("app");
      std::vector<u16> ord172({1, 2, 3, 0});
      slog::Relation* readrel173 = db->getRelation("eval");
      evalindex137 = readrel173->getIndex(ord172, false);
      std::vector<u16> ord174({1, 2, 3, 0});
      slog::Relation* readrel175 = db->getRelation("eval");
      evalindex138 = readrel175->getIndex(ord174, false);
      std::vector<u16> ord176({5, 6, 0, 7, 9, 1, 2, 3, 4, 8, 10, 11, 12});
      slog::Relation* readrel177 = db->getRelation("$sup70016x51x0x0x1");
      $sup70016x51x0x0x1index139 = readrel177->getIndex(ord176, false);
      std::vector<u16> ord178({1, 3, 2, 0});
      slog::Relation* readrel179 = db->getRelation("eval_args");
      eval_argsindex140 = readrel179->getIndex(ord178, false);
      std::vector<u16> ord180({1, 2, 0});
      slog::Relation* readrel181 = db->getRelation("tick");
      tickindex141 = readrel181->getIndex(ord180, false);
      std::vector<u16> ord182({1, 2, 4, 0, 3});
      slog::Relation* readrel183 = db->getRelation("$sup70016x51x0x0x0");
      $sup70016x51x0x0x0index142 = readrel183->getIndex(ord182, false);
      std::vector<u16> ord184({2, 3, 0, 1});
      slog::Relation* readrel185 = db->getRelation("eval");
      evalindex143 = readrel185->getIndex(ord184, false);
      std::vector<u16> ord186({5, 6, 0, 7, 9, 1, 2, 3, 4, 8, 10, 11, 12});
      slog::Relation* readrel187 = db->getRelation("$sup70016x51x0x0x1");
      $sup70016x51x0x0x1index144 = readrel187->getIndex(ord186, false);
      std::vector<u16> ord188({1, 3, 2, 0});
      slog::Relation* readrel189 = db->getRelation("eval_args");
      eval_argsindex145 = readrel189->getIndex(ord188, false);
      std::vector<u16> ord190({1, 2, 0});
      slog::Relation* readrel191 = db->getRelation("tick");
      tickindex146 = readrel191->getIndex(ord190, false);
      std::vector<u16> ord192({1, 2, 3, 0});
      slog::Relation* readrel193 = db->getRelation("eval");
      evalindex147 = readrel193->getIndex(ord192, false);
      std::vector<u16> ord194({0, 1});
      slog::Relation* readrel195 = db->getRelation("eval_ans");
      eval_ansindex148 = readrel195->getIndex(ord194, false);
      std::vector<u16> ord196({5, 6, 0, 7, 9, 1, 2, 3, 4, 8, 10, 11, 12});
      slog::Relation* readrel197 = db->getRelation("$sup70016x51x0x0x1");
      $sup70016x51x0x0x1index149 = readrel197->getIndex(ord196, false);
      std::vector<u16> ord198({3, 2, 0, 1});
      slog::Relation* readrel199 = db->getRelation("eval_args");
      eval_argsindex150 = readrel199->getIndex(ord198, false);
      std::vector<u16> ord200({0, 2, 1});
      slog::Relation* readrel201 = db->getRelation("tick");
      tickindex151 = readrel201->getIndex(ord200, false);
      std::vector<u16> ord202({0, 2, 1});
      slog::Relation* readrel203 = db->getRelation("tick");
      tickdelta167 = readrel203->getIndex(ord202, true);
      std::vector<u16> ord204({0, 1});
      slog::Relation* readrel205 = db->getRelation("eval_args_ans");
      eval_args_ansindex152 = readrel205->getIndex(ord204, false);
      std::vector<u16> ord206({0, 1});
      slog::Relation* readrel207 = db->getRelation("tick_ans");
      tick_ansindex153 = readrel207->getIndex(ord206, false);
      std::vector<u16> ord208({1, 2, 0});
      slog::Relation* readrel209 = db->getRelation("lambda");
      lambdaindex154 = readrel209->getIndex(ord208, false);
      std::vector<u16> ord210({2, 0, 1});
      slog::Relation* readrel211 = db->getRelation("closure");
      closureindex155 = readrel211->getIndex(ord210, false);
      std::vector<u16> ord212({3, 1, 0, 2});
      slog::Relation* readrel213 = db->getRelation("eval");
      evalindex156 = readrel213->getIndex(ord212, false);
      std::vector<u16> ord214({1, 2, 3, 0});
      slog::Relation* readrel215 = db->getRelation("extend_env");
      extend_envindex157 = readrel215->getIndex(ord214, false);
      std::vector<u16> ord216({1, 2, 3, 0});
      slog::Relation* readrel217 = db->getRelation("extend_env");
      extend_envdelta168 = readrel217->getIndex(ord216, true);
      std::vector<u16> ord218({0, 1});
      slog::Relation* readrel219 = db->getRelation("eval_args_ans");
      eval_args_ansindex158 = readrel219->getIndex(ord218, false);
      std::vector<u16> ord220({0, 1});
      slog::Relation* readrel221 = db->getRelation("tick_ans");
      tick_ansindex159 = readrel221->getIndex(ord220, false);
      std::vector<u16> ord222({0, 1});
      slog::Relation* readrel223 = db->getRelation("extend_env_ans");
      extend_env_ansindex160 = readrel223->getIndex(ord222, false);
      std::vector<u16> ord224({1, 2, 0});
      slog::Relation* readrel225 = db->getRelation("lambda");
      lambdaindex161 = readrel225->getIndex(ord224, false);
      std::vector<u16> ord226({1, 2, 0});
      slog::Relation* readrel227 = db->getRelation("closure");
      closureindex162 = readrel227->getIndex(ord226, false);
      std::vector<u16> ord228({0, 1});
      slog::Relation* readrel229 = db->getRelation("eval_ans");
      eval_ansindex163 = readrel229->getIndex(ord228, false);
      std::vector<u16> ord230({3, 1, 0, 2});
      slog::Relation* readrel231 = db->getRelation("eval");
      evalindex164 = readrel231->getIndex(ord230, false);
      std::vector<u16> ord232({0, 1});
      slog::Relation* readrel233 = db->getRelation("extend_env_ans");
      extend_env_ansindex165 = readrel233->getIndex(ord232, false);
      std::vector<u16> ord234({0, 1});
      slog::Relation* readrel235 = db->getRelation("eval_ans");
      eval_ansindex166 = readrel235->getIndex(ord234, false);
  
    }
    ReadTask169(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c54 = _t[0];
        u64 v_c55 = _t[1];
        u64 v_c41 = _t[2];
        if (!slog::exists_probe<4,1>(evalindex137, std::array<u64,4>{v_c54, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(evalindex138, std::array<u64,4>{v_c55, 0, 0, 0})) return;
        if (!slog::exists_probe<13,2>($sup70016x51x0x0x1index139, std::array<u64,13>{v_c55, v_c41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(eval_argsindex140, std::array<u64,4>{v_c41, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(tickindex141, std::array<u64,3>{v_c54, 0, 0})) return;
        slog::join_probe<5,2>($sup70016x51x0x0x0index142, std::array<u64,5>{v_c55, v_c41, 0, 0, 0}, [&](const std::array<u64,5>& m236) {
          u64 v_c28 = m236[2]; u64 v_c56 = m236[3]; u64 v_c26 = m236[4];
          slog::join_probe<4,4>(evalindex143, std::array<u64,4>{v_c26, v_c28, v_c56, v_c54}, [&](const std::array<u64,4>& m237) {
            if (!slog::exists_probe<13,5>($sup70016x51x0x0x1index144, std::array<u64,13>{v_c55, v_c41, v_c56, v_c26, v_c28, 0, 0, 0, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<4,3>(eval_argsindex145, std::array<u64,4>{v_c41, v_c28, v_c26, 0})) return;
            if (!slog::exists_probe<3,2>(tickindex146, std::array<u64,3>{v_c54, v_c28, 0})) return;
            slog::join_probe<4,3>(evalindex147, std::array<u64,4>{v_c55, v_c26, v_c28, 0}, [&](const std::array<u64,4>& m238) {
              u64 v_c57 = m238[3];
              if (!slog::exists_probe<2,1>(eval_ansindex148, std::array<u64,2>{v_c57, 0})) return;
              slog::join_probe<13,6>($sup70016x51x0x0x1index149, std::array<u64,13>{v_c55, v_c41, v_c56, v_c26, v_c28, v_c57, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,13>& m239) {
                u64 v_c58 = m239[6]; u64 v_c59 = m239[7]; u64 v_c24 = m239[8]; u64 v_c60 = m239[9]; u64 v_c61 = m239[10]; u64 v_c62 = m239[11]; u64 v_c63 = m239[12];
                slog::join_probe<4,4>(eval_argsindex150, std::array<u64,4>{v_c28, v_c26, v_c58, v_c41}, [&](const std::array<u64,4>& m240) {
                  slog::join_probe_old<3,3>(tickindex151, tickdelta167, std::array<u64,3>{v_c59, v_c28, v_c54}, [&](const std::array<u64,3>& m241) {
                    if (!slog::exists_probe<2,2>(eval_args_ansindex152, std::array<u64,2>{v_c58, v_c62})) return;
                    if (!slog::exists_probe<2,2>(tick_ansindex153, std::array<u64,2>{v_c59, v_c61})) return;
                    if (!slog::exists_probe<3,2>(lambdaindex154, std::array<u64,3>{v_c63, v_c24, 0})) return;
                    if (!slog::exists_probe<3,1>(closureindex155, std::array<u64,3>{v_c60, 0, 0})) return;
                    if (!slog::exists_probe<4,2>(evalindex156, std::array<u64,4>{v_c61, v_c24, 0, 0})) return;
                    slog::join_probe_old<4,3>(extend_envindex157, extend_envdelta168, std::array<u64,4>{v_c60, v_c63, v_c61, 0}, [&](const std::array<u64,4>& m242) {
                      u64 v_c64 = m242[3];
                      slog::join_probe<2,2>(eval_args_ansindex158, std::array<u64,2>{v_c58, v_c62}, [&](const std::array<u64,2>& m243) {
                        slog::join_probe<2,2>(tick_ansindex159, std::array<u64,2>{v_c59, v_c61}, [&](const std::array<u64,2>& m244) {
                          if (!slog::exists_probe<2,1>(extend_env_ansindex160, std::array<u64,2>{v_c64, 0})) return;
                          slog::join_probe<3,2>(lambdaindex161, std::array<u64,3>{v_c63, v_c24, 0}, [&](const std::array<u64,3>& m245) {
                            u64 v_c65 = m245[2];
                            slog::join_probe<3,2>(closureindex162, std::array<u64,3>{v_c65, v_c60, 0}, [&](const std::array<u64,3>& m246) {
                              u64 v_c66 = m246[2];
                              slog::join_probe<2,2>(eval_ansindex163, std::array<u64,2>{v_c57, v_c66}, [&](const std::array<u64,2>& m247) {
                                slog::join_probe<4,2>(evalindex164, std::array<u64,4>{v_c61, v_c24, 0, 0}, [&](const std::array<u64,4>& m248) {
                                  u64 v_c67 = m248[2]; u64 v_c47 = m248[3];
                                  slog::join_probe<2,2>(extend_env_ansindex165, std::array<u64,2>{v_c64, v_c47}, [&](const std::array<u64,2>& m249) {
                                    slog::join_probe<2,1>(eval_ansindex166, std::array<u64,2>{v_c67, 0}, [&](const std::array<u64,2>& m250) {
                                      u64 v_c53 = m250[1];
                                      ++_fires;
                                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c56, v_c53}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:52", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask169* _cont = new ReadTask169(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask169(db,b), false);
  // (crule (pre) (scan temp0Tjz1856 __t14N0222 __v0 l m p) (body (join mbranch (1 2 3 4 0) 4 p m l __v0 __t1O3D219)) (head (emit mp_union_ans (0 1) __t14N0222 __t1O3D219)) map.slog:99 #f)
  class ReadTask252 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex251;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord253({0, 1});
      slog::Relation* readrel254 = db->getRelation("mp_union_ans");
      head_index[0] = readrel254->getIndex(ord253, false);
      outer_rel = db->getRelation("temp0Tjz1856");
      std::vector<u16> ord255({1, 2, 3, 4, 0});
      slog::Relation* readrel256 = db->getRelation("mbranch");
      mbranchindex251 = readrel256->getIndex(ord255, false);
  
    }
    ReadTask252(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c68 = _t[0];
        u64 v_c47 = _t[1];
        u64 v_c69 = _t[2];
        u64 v_c70 = _t[3];
        u64 v_c71 = _t[4];
        slog::join_probe<5,4>(mbranchindex251, std::array<u64,5>{v_c71, v_c70, v_c69, v_c47, 0}, [&](const std::array<u64,5>& m257) {
          u64 v_c72 = m257[4];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c68, v_c72}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:99", "delta:temp0Tjz1856", _fires);
  
      if (!_done)
      {
        ReadTask252* _cont = new ReadTask252(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask252(db,b), false);
  // (crule (pre (let __tconst49eD1184 constcd2a69ce5ca278db1d6da969) (let __tconst7GbT659 const06abaa100ecef791ce028c56) (let _00024sqc0jJd1013 constd4735e3a265e16eee03f5971) (let _00024sqc54us1014 const5feceb66ffc86f38d952786c) (let _00024sqc6uOX1015 const6b86b273ff34fce19d6b804e) (let _00024sqo8ZRa1016 const5feceb66ffc86f38d952786c) (let _00024sqo9lkw1017 const6b86b273ff34fce19d6b804e) (let _00024sqo8so11018 const6b86b273ff34fce19d6b804e) (let _00024sqo0qa11019 const5feceb66ffc86f38d952786c)) (probe delta (1 2 0) 1 __tconst7GbT659 _00024seq2 __t6erK660) (body (letp _00024sql99Ol1011 (aslst _00024seq2)) (letp __t013P662 (lref _00024sql99Ol1011 _00024sqc54us1014)) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo8ZRa1016 __t013P662 _00024seq2) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo9lkw1017 __t013P662 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo8so11018 __t013P662 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo0qa11019 __t013P662 _00024seq2) (join _enum (0 1) 2 __t013P662 __tconst49eD1184) (join any_bool (0) 0 b) (let chk8MfP1779 (llen _00024sql99Ol1011)) (eq _00024sqc0jJd1013 chk8MfP1779) (letp chk1d7v1780 (lref _00024sql99Ol1011 _00024sqc6uOX1015)) (eq __t013P662 chk1d7v1780)) (head (emit-temp temp3q8l1778 __t6erK660 b) (mkstruct boolval (1 0) __t5eIx658 b)) interp.slog:125 #f)
  class ReadTask268 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex258;  slog::Index** $seq_atindex259;  slog::Index** $seq_atrindex260;  slog::Index** $seq_atrindex261;  slog::Index** _enumindex262;  slog::Index** any_boolindex263;  slog::Index** $seq_atdelta264;  slog::Index** $seq_atdelta265;  slog::Index** $seq_atrdelta266;  slog::Index** $seq_atrdelta267;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3q8l1778");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord269({1, 2, 0});
      slog::Relation* readrel270 = db->getRelation("delta");
      driver_index = readrel270->getIndex(ord269, true);
      std::vector<u16> ord271({1, 0, 2});
      slog::Relation* readrel272 = db->getRelation("$seq_at");
      $seq_atindex258 = readrel272->getIndex(ord271, false);
      std::vector<u16> ord273({1, 0, 2});
      slog::Relation* readrel274 = db->getRelation("$seq_at");
      $seq_atdelta264 = readrel274->getIndex(ord273, true);
      std::vector<u16> ord275({1, 0, 2});
      slog::Relation* readrel276 = db->getRelation("$seq_at");
      $seq_atindex259 = readrel276->getIndex(ord275, false);
      std::vector<u16> ord277({1, 0, 2});
      slog::Relation* readrel278 = db->getRelation("$seq_at");
      $seq_atdelta265 = readrel278->getIndex(ord277, true);
      std::vector<u16> ord279({1, 0, 2});
      slog::Relation* readrel280 = db->getRelation("$seq_atr");
      $seq_atrindex260 = readrel280->getIndex(ord279, false);
      std::vector<u16> ord281({1, 0, 2});
      slog::Relation* readrel282 = db->getRelation("$seq_atr");
      $seq_atrdelta266 = readrel282->getIndex(ord281, true);
      std::vector<u16> ord283({1, 0, 2});
      slog::Relation* readrel284 = db->getRelation("$seq_atr");
      $seq_atrindex261 = readrel284->getIndex(ord283, false);
      std::vector<u16> ord285({1, 0, 2});
      slog::Relation* readrel286 = db->getRelation("$seq_atr");
      $seq_atrdelta267 = readrel286->getIndex(ord285, true);
      std::vector<u16> ord287({0, 1});
      slog::Relation* readrel288 = db->getRelation("_enum");
      _enumindex262 = readrel288->getIndex(ord287, false);
      std::vector<u16> ord289({0});
      slog::Relation* readrel290 = db->getRelation("any_bool");
      any_boolindex263 = readrel290->getIndex(ord289, false);
  
    }
    ReadTask268(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c73 = v_constcd2a69ce5ca278db1d6da969;
      u64 v_c74 = v_const06abaa100ecef791ce028c56;
      u64 v_c75 = v_constd4735e3a265e16eee03f5971;
      u64 v_c76 = v_const5feceb66ffc86f38d952786c;
      u64 v_c77 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c78 = v_const5feceb66ffc86f38d952786c;
      u64 v_c79 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c80 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c81 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c74, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m291) {
        u64 v_c82 = m291[1];
        u64 v_c83 = m291[2];
        if (buckethash(v_c82) != bucket) return;
        bool ok292 = true;
        u64 v_c84 = _prim_aslst(db, v_c82, &ok292);
        if (!ok292) return;
        bool ok293 = true;
        u64 v_c85 = _prim_lref(db, v_c84, v_c76, &ok293);
        if (!ok293) return;
        slog::join_probe_old<3,3>($seq_atindex258, $seq_atdelta264, std::array<u64,3>{v_c78, v_c85, v_c82}, [&](const std::array<u64,3>& m294) {
          slog::join_probe_old<3,3>($seq_atindex259, $seq_atdelta265, std::array<u64,3>{v_c79, v_c85, v_c82}, [&](const std::array<u64,3>& m295) {
            slog::join_probe_old<3,3>($seq_atrindex260, $seq_atrdelta266, std::array<u64,3>{v_c80, v_c85, v_c82}, [&](const std::array<u64,3>& m296) {
              slog::join_probe_old<3,3>($seq_atrindex261, $seq_atrdelta267, std::array<u64,3>{v_c81, v_c85, v_c82}, [&](const std::array<u64,3>& m297) {
                slog::join_probe<2,2>(_enumindex262, std::array<u64,2>{v_c85, v_c73}, [&](const std::array<u64,2>& m298) {
                  slog::join_all<1>(any_boolindex263, [&](const std::array<u64,1>& m299) {
                    u64 v_c86 = m299[0];
                    u64 v_c87 = _prim_llen(db, v_c84);
                    if (v_c87 == slog_error) { slog::emit_pending_error(db, "interp.slog:125"); return; }
                    if (v_c75 != v_c87) return;
                    bool ok300 = true;
                    u64 v_c88 = _prim_lref(db, v_c84, v_c77, &ok300);
                    if (!ok300) return;
                    if (v_c85 != v_c88) return;
                    ++_fires;
                    slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c83, v_c86});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c86}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:125", "delta:delta", _fires);
  
      if (!_done)
      {
        ReadTask268* _cont = new ReadTask268(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask268(db,b), false);
  // (crule (pre (let __tconst25r1527 const5feceb66ffc86f38d952786c)) (scan mp_has0 __t5miQ526 t k) (body (join mp_has0_ans (0 1) 2 __t5miQ526 __tconst25r1527) (exists mp_put_soft (1 2 3 0) 2 t k) (exists mp_put (1 2 3 0) 2 t k) (join $sup5638x68x0x0x0 (1 2 3 0) 2 k t v __t94M4525) (join mp_put_soft (1 2 3 0) 4 t k v __t94M4525) (join-old mp_put (1 2 3 0) 3 (1 2 3 0) t k v __t7U64528) (join mp_put_ans (0 1) 1 __t7U64528 r)) (head (emit mp_put_soft_ans (0 1) __t94M4525 r)) map.slog:69 #f)
  class ReadTask309 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_has0_ansindex301;  slog::Index** mp_put_softindex302;  slog::Index** mp_putindex303;  slog::Index** $sup5638x68x0x0x0index304;  slog::Index** mp_put_softindex305;  slog::Index** mp_putindex306;  slog::Index** mp_put_ansindex307;  slog::Index** mp_putdelta308;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_soft_ans");
      std::vector<u16> ord310({0, 1});
      slog::Relation* readrel311 = db->getRelation("mp_put_soft_ans");
      head_index[0] = readrel311->getIndex(ord310, false);
      outer_rel = db->getRelation("mp_has0");
      std::vector<u16> ord312({0, 1});
      slog::Relation* readrel313 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex301 = readrel313->getIndex(ord312, false);
      std::vector<u16> ord314({1, 2, 3, 0});
      slog::Relation* readrel315 = db->getRelation("mp_put_soft");
      mp_put_softindex302 = readrel315->getIndex(ord314, false);
      std::vector<u16> ord316({1, 2, 3, 0});
      slog::Relation* readrel317 = db->getRelation("mp_put");
      mp_putindex303 = readrel317->getIndex(ord316, false);
      std::vector<u16> ord318({1, 2, 3, 0});
      slog::Relation* readrel319 = db->getRelation("$sup5638x68x0x0x0");
      $sup5638x68x0x0x0index304 = readrel319->getIndex(ord318, false);
      std::vector<u16> ord320({1, 2, 3, 0});
      slog::Relation* readrel321 = db->getRelation("mp_put_soft");
      mp_put_softindex305 = readrel321->getIndex(ord320, false);
      std::vector<u16> ord322({1, 2, 3, 0});
      slog::Relation* readrel323 = db->getRelation("mp_put");
      mp_putindex306 = readrel323->getIndex(ord322, false);
      std::vector<u16> ord324({1, 2, 3, 0});
      slog::Relation* readrel325 = db->getRelation("mp_put");
      mp_putdelta308 = readrel325->getIndex(ord324, true);
      std::vector<u16> ord326({0, 1});
      slog::Relation* readrel327 = db->getRelation("mp_put_ans");
      mp_put_ansindex307 = readrel327->getIndex(ord326, false);
  
    }
    ReadTask309(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c28 = _t[1];
        u64 v_c44 = _t[2];
        slog::join_probe<2,2>(mp_has0_ansindex301, std::array<u64,2>{v_c90, v_c89}, [&](const std::array<u64,2>& m328) {
          if (!slog::exists_probe<4,2>(mp_put_softindex302, std::array<u64,4>{v_c28, v_c44, 0, 0})) return;
          if (!slog::exists_probe<4,2>(mp_putindex303, std::array<u64,4>{v_c28, v_c44, 0, 0})) return;
          slog::join_probe<4,2>($sup5638x68x0x0x0index304, std::array<u64,4>{v_c44, v_c28, 0, 0}, [&](const std::array<u64,4>& m329) {
            u64 v_c53 = m329[2]; u64 v_c91 = m329[3];
            slog::join_probe<4,4>(mp_put_softindex305, std::array<u64,4>{v_c28, v_c44, v_c53, v_c91}, [&](const std::array<u64,4>& m330) {
              slog::join_probe_old<4,3>(mp_putindex306, mp_putdelta308, std::array<u64,4>{v_c28, v_c44, v_c53, 0}, [&](const std::array<u64,4>& m331) {
                u64 v_c92 = m331[3];
                slog::join_probe<2,1>(mp_put_ansindex307, std::array<u64,2>{v_c92, 0}, [&](const std::array<u64,2>& m332) {
                  u64 v_c93 = m332[1];
                  ++_fires;
                  slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c91, v_c93}, std::array<u16,2>{0, 1});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:69", "delta:mp_has0", _fires);
  
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
  // (crule (pre (let _00024sqc14mW850 constd4735e3a265e16eee03f5971) (let _00024sqc9wRs851 const5feceb66ffc86f38d952786c) (let _00024sqc75fJ852 const6b86b273ff34fce19d6b804e) (let _00024sqc4blY855 const6b86b273ff34fce19d6b804e) (let _00024sqc1OgI856 const5feceb66ffc86f38d952786c) (let _00024sqc52iL857 const6b86b273ff34fce19d6b804e) (let _00024sqc4E2e858 const5feceb66ffc86f38d952786c) (let __trid5h3K1186 const1ef5dd96b7ac876a994a9ca1) (let __trel6FqW1187 const1064263932db82f2cf6d4ac2) (let __tcol1aXn1188 const6b86b273ff34fce19d6b804e)) (scan mp_fromlist_ans __t3F8P645 __v0) (body (join mp_fromlist (0 1) 1 __t3F8P645 xs) (join $sup5638x127x0x0x0 (5 0 1 2 3 4) 1 xs _00024seq0 _00024seq1 __d0 k v) (letp _00024sql8EfA853 (aslst _00024seq1)) (let _00024sqn8QbH854 (llen _00024sql8EfA853)) (cmp ge _00024sqn8QbH854 _00024sqc4blY855) (letp _00024sql2Csk848 (aslst _00024seq0)) (let chk8mlj1891 (llen _00024sql2Csk848)) (eq _00024sqc14mW850 chk8mlj1891) (letp chk7Yvh1892 (lref _00024sql2Csk848 _00024sqc9wRs851)) (eq k chk7Yvh1892) (letp chk7Bpf1893 (lref _00024sql2Csk848 _00024sqc75fJ852)) (eq v chk7Bpf1893) (letp chk1meH1894 (lref _00024sql8EfA853 _00024sqc1OgI856)) (eq _00024seq0 chk1meH1894) (let _00024sqp4sHb859 (_0002d _00024sqn8QbH854 _00024sqc4E2e858)) (let chk1RKU1895 (lslice _00024sql8EfA853 _00024sqc52iL857 _00024sqp4sHb859)) (eq xs chk1RKU1895)) (head (tycheck k (accept int) __trid5h3K1186 __trel6FqW1187 __tcol1aXn1188 (1 2 3 4 0)) (mkstruct mp_put (1 2 3 0) __9wKJ1185 __v0 k v)) map.slog:128 #f)
  class ReadTask335 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_fromlistindex333;  slog::Index** $sup5638x127x0x0x0index334;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("mp_put");
      outer_rel = db->getRelation("mp_fromlist_ans");
      std::vector<u16> ord336({0, 1});
      slog::Relation* readrel337 = db->getRelation("mp_fromlist");
      mp_fromlistindex333 = readrel337->getIndex(ord336, false);
      std::vector<u16> ord338({5, 0, 1, 2, 3, 4});
      slog::Relation* readrel339 = db->getRelation("$sup5638x127x0x0x0");
      $sup5638x127x0x0x0index334 = readrel339->getIndex(ord338, false);
  
    }
    ReadTask335(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c94 = v_constd4735e3a265e16eee03f5971;
      u64 v_c95 = v_const5feceb66ffc86f38d952786c;
      u64 v_c96 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c97 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c98 = v_const5feceb66ffc86f38d952786c;
      u64 v_c99 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c100 = v_const5feceb66ffc86f38d952786c;
      u64 v_c101 = v_const1ef5dd96b7ac876a994a9ca1;
      u64 v_c102 = v_const1064263932db82f2cf6d4ac2;
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
        u64 v_c47 = _t[1];
        slog::join_probe<2,1>(mp_fromlistindex333, std::array<u64,2>{v_c104, 0}, [&](const std::array<u64,2>& m340) {
          u64 v_c63 = m340[1];
          slog::join_probe<6,1>($sup5638x127x0x0x0index334, std::array<u64,6>{v_c63, 0, 0, 0, 0, 0}, [&](const std::array<u64,6>& m341) {
            u64 v_c35 = m341[1]; u64 v_c8 = m341[2]; u64 v_c22 = m341[3]; u64 v_c44 = m341[4]; u64 v_c53 = m341[5];
            bool ok342 = true;
            u64 v_c105 = _prim_aslst(db, v_c8, &ok342);
            if (!ok342) return;
            u64 v_c106 = _prim_llen(db, v_c105);
            if (v_c106 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
            u64 v_c107 = _prim_ge(db, v_c106, v_c97);
            if (v_c107 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
            if (!v_c107) return;
            bool ok344 = true;
            u64 v_c108 = _prim_aslst(db, v_c35, &ok344);
            if (!ok344) return;
            u64 v_c109 = _prim_llen(db, v_c108);
            if (v_c109 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
            if (v_c94 != v_c109) return;
            bool ok345 = true;
            u64 v_c110 = _prim_lref(db, v_c108, v_c95, &ok345);
            if (!ok345) return;
            if (v_c44 != v_c110) return;
            bool ok346 = true;
            u64 v_c111 = _prim_lref(db, v_c108, v_c96, &ok346);
            if (!ok346) return;
            if (v_c53 != v_c111) return;
            bool ok347 = true;
            u64 v_c112 = _prim_lref(db, v_c105, v_c98, &ok347);
            if (!ok347) return;
            if (v_c35 != v_c112) return;
            u64 v_c113 = _prim__0002d(db, v_c106, v_c100);
            if (v_c113 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
            u64 v_c114 = _prim_lslice(db, v_c105, v_c99, v_c113);
            if (v_c114 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
            if (v_c63 != v_c114) return;
            ++_fires;
            if (!(is_int(v_c44)))
            {
              slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c101, v_c102, v_c103, v_c44}, std::array<u16,5>{1, 2, 3, 4, 0});
              return;
            }
            slog::emit_struct<4>(head_rel[1], newbatch[1], std::array<u64,3>{v_c47, v_c44, v_c53}, std::array<u16,4>{1, 2, 3, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("map.slog:128", "delta:mp_fromlist_ans", _fires);
  
      if (!_done)
      {
        ReadTask335* _cont = new ReadTask335(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask335(db,b), false);
  // (crule (pre (let __tconst5vD0184 const4a44dc15364204a80fe80e90) (let __tconst5BWV176 const6b51d431df5d7f141cbececc) (let __tconst1XI2167 const3fdba35f04dc8c462986c992)) (scan temp14ub1994 __t3ORQ166 __t9GVo175 __t9KE7159 __t9kRL183) (body (join let (1 2 3 0) 3 __tconst1XI2167 __t3ORQ166 __t9KE7159 __t2pQQ168)) (head (emit-temp temp4DFq1995 __t2pQQ168 __t9GVo175 __t9kRL183) (mkstruct let (1 2 3 0) __t9uEv177 __tconst5BWV176 __t9GVo175 __t2pQQ168)) kcfa.slog:29 #f)
  class ReadTask349 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letindex348;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4DFq1995");
      head_rel[1] = db->getRelation("let");
      outer_rel = db->getRelation("temp14ub1994");
      std::vector<u16> ord350({1, 2, 3, 0});
      slog::Relation* readrel351 = db->getRelation("let");
      letindex348 = readrel351->getIndex(ord350, false);
  
    }
    ReadTask349(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c115 = v_const4a44dc15364204a80fe80e90;
      u64 v_c116 = v_const6b51d431df5d7f141cbececc;
      u64 v_c117 = v_const3fdba35f04dc8c462986c992;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c118 = _t[0];
        u64 v_c119 = _t[1];
        u64 v_c120 = _t[2];
        u64 v_c121 = _t[3];
        slog::join_probe<4,3>(letindex348, std::array<u64,4>{v_c117, v_c118, v_c120, 0}, [&](const std::array<u64,4>& m352) {
          u64 v_c122 = m352[3];
          ++_fires;
          slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c122, v_c119, v_c121});
          slog::emit_struct<4>(head_rel[1], newbatch[1], std::array<u64,3>{v_c116, v_c119, v_c122}, std::array<u16,4>{1, 2, 3, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("kcfa.slog:29", "delta:temp14ub1994", _fires);
  
      if (!_done)
      {
        ReadTask349* _cont = new ReadTask349(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask349(db,b), false);
  // (crule (pre (let __tconst9Msd523 const6b86b273ff34fce19d6b804e)) (scan mbranch __t333H520 q n u v) (body (join-old mp_union (2 0 1) 1 (2 0 1) __t333H520 __t0OqE522 __t8ZnZ521) (join-old mbranch (0 1 2 3 4) 1 (0 1 2 3 4) __t8ZnZ521 p m l r) (cmp lt m n) (let __t9LcB524 (band p n)) (cmp lt __t9LcB524 __tconst9Msd523)) (head (emit $sup5638x104x0x0x0 (0 7 1 2 3 4 5 6 8) __t0OqE522 u l m n p q r v)) map.slog:105 #f)
  class ReadTask357 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex353;  slog::Index** mbranchindex354;  slog::Index** mp_uniondelta355;  slog::Index** mbranchdelta356;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x104x0x0x0");
      std::vector<u16> ord358({0, 7, 1, 2, 3, 4, 5, 6, 8});
      slog::Relation* readrel359 = db->getRelation("$sup5638x104x0x0x0");
      head_index[0] = readrel359->getIndex(ord358, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord360({2, 0, 1});
      slog::Relation* readrel361 = db->getRelation("mp_union");
      mp_unionindex353 = readrel361->getIndex(ord360, false);
      std::vector<u16> ord362({2, 0, 1});
      slog::Relation* readrel363 = db->getRelation("mp_union");
      mp_uniondelta355 = readrel363->getIndex(ord362, true);
      std::vector<u16> ord364({0, 1, 2, 3, 4});
      slog::Relation* readrel365 = db->getRelation("mbranch");
      mbranchindex354 = readrel365->getIndex(ord364, false);
      std::vector<u16> ord366({0, 1, 2, 3, 4});
      slog::Relation* readrel367 = db->getRelation("mbranch");
      mbranchdelta356 = readrel367->getIndex(ord366, true);
  
    }
    ReadTask357(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c123 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c124 = _t[0];
        u64 v_c125 = _t[1];
        u64 v_c126 = _t[2];
        u64 v_c127 = _t[3];
        u64 v_c53 = _t[4];
        slog::join_probe_old<3,1>(mp_unionindex353, mp_uniondelta355, std::array<u64,3>{v_c124, 0, 0}, [&](const std::array<u64,3>& m368) {
          u64 v_c128 = m368[1]; u64 v_c129 = m368[2];
          slog::join_probe_old<5,1>(mbranchindex354, mbranchdelta356, std::array<u64,5>{v_c129, 0, 0, 0, 0}, [&](const std::array<u64,5>& m369) {
            u64 v_c71 = m369[1]; u64 v_c70 = m369[2]; u64 v_c69 = m369[3]; u64 v_c93 = m369[4];
            u64 v_c130 = _prim_lt(db, v_c70, v_c126);
            if (v_c130 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
            if (!v_c130) return;
            u64 v_c131 = _prim_band(db, v_c71, v_c126);
            if (v_c131 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
            u64 v_c132 = _prim_lt(db, v_c131, v_c123);
            if (v_c132 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
            if (!v_c132) return;
            ++_fires;
            slog::emit<9>(head_rel[0], head_index[0], newbatch[0], std::array<u64,9>{v_c128, v_c127, v_c69, v_c70, v_c126, v_c71, v_c125, v_c93, v_c53}, std::array<u16,9>{0, 7, 1, 2, 3, 4, 5, 6, 8});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:105", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask357* _cont = new ReadTask357(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask357(db,b), false);
  // (crule (pre) (scan lookup __t58t3572 x rho) (body (join store (0 1 2) 1 x tx v)) (head (mkstruct mp_get (1 2 0) __37aV1208 rho x)) interp.slog:39 #f)
  class ReadTask373 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** storeindex372;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_get");
      outer_rel = db->getRelation("lookup");
      std::vector<u16> ord374({0, 1, 2});
      slog::Relation* readrel375 = db->getRelation("store");
      storeindex372 = readrel375->getIndex(ord374, false);
  
    }
    ReadTask373(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c133 = _t[0];
        u64 v_c29 = _t[1];
        u64 v_c26 = _t[2];
        slog::join_probe<3,1>(storeindex372, std::array<u64,3>{v_c29, 0, 0}, [&](const std::array<u64,3>& m376) {
          u64 v_c134 = m376[1]; u64 v_c53 = m376[2];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c26, v_c29}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:39", "delta:lookup", _fires);
  
      if (!_done)
      {
        ReadTask373* _cont = new ReadTask373(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask373(db,b), false);
  // (crule (pre (let __tconst4CIq418 const5feceb66ffc86f38d952786c)) (scan mbranch __t9vor415 q n u v) (body (join-old mp_union (2 0 1) 1 (2 0 1) __t9vor415 __t6aCH417 __t2QpY416) (join-old mbranch (0 1 2 3 4) 1 (0 1 2 3 4) __t2QpY416 p m l r) (cmp lt m n) (let __t1cei419 (band p n)) (cmp gt __t1cei419 __tconst4CIq418)) (head (emit $sup5638x107x0x0x0 (0 8 1 2 3 4 5 6 7) __t6aCH417 v l m n p q r u)) map.slog:108 #f)
  class ReadTask381 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex377;  slog::Index** mbranchindex378;  slog::Index** mp_uniondelta379;  slog::Index** mbranchdelta380;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x107x0x0x0");
      std::vector<u16> ord382({0, 8, 1, 2, 3, 4, 5, 6, 7});
      slog::Relation* readrel383 = db->getRelation("$sup5638x107x0x0x0");
      head_index[0] = readrel383->getIndex(ord382, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord384({2, 0, 1});
      slog::Relation* readrel385 = db->getRelation("mp_union");
      mp_unionindex377 = readrel385->getIndex(ord384, false);
      std::vector<u16> ord386({2, 0, 1});
      slog::Relation* readrel387 = db->getRelation("mp_union");
      mp_uniondelta379 = readrel387->getIndex(ord386, true);
      std::vector<u16> ord388({0, 1, 2, 3, 4});
      slog::Relation* readrel389 = db->getRelation("mbranch");
      mbranchindex378 = readrel389->getIndex(ord388, false);
      std::vector<u16> ord390({0, 1, 2, 3, 4});
      slog::Relation* readrel391 = db->getRelation("mbranch");
      mbranchdelta380 = readrel391->getIndex(ord390, true);
  
    }
    ReadTask381(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c135 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c136 = _t[0];
        u64 v_c125 = _t[1];
        u64 v_c126 = _t[2];
        u64 v_c127 = _t[3];
        u64 v_c53 = _t[4];
        slog::join_probe_old<3,1>(mp_unionindex377, mp_uniondelta379, std::array<u64,3>{v_c136, 0, 0}, [&](const std::array<u64,3>& m392) {
          u64 v_c137 = m392[1]; u64 v_c138 = m392[2];
          slog::join_probe_old<5,1>(mbranchindex378, mbranchdelta380, std::array<u64,5>{v_c138, 0, 0, 0, 0}, [&](const std::array<u64,5>& m393) {
            u64 v_c71 = m393[1]; u64 v_c70 = m393[2]; u64 v_c69 = m393[3]; u64 v_c93 = m393[4];
            u64 v_c139 = _prim_lt(db, v_c70, v_c126);
            if (v_c139 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
            if (!v_c139) return;
            u64 v_c140 = _prim_band(db, v_c71, v_c126);
            if (v_c140 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
            u64 v_c141 = _prim_gt(db, v_c140, v_c135);
            if (v_c141 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
            if (!v_c141) return;
            ++_fires;
            slog::emit<9>(head_rel[0], head_index[0], newbatch[0], std::array<u64,9>{v_c137, v_c53, v_c69, v_c70, v_c126, v_c71, v_c125, v_c93, v_c127}, std::array<u16,9>{0, 8, 1, 2, 3, 4, 5, 6, 7});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:108", "delta:mbranch", _fires);
  
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
  // (crule (pre (let __tconst84Si675 const6b86b273ff34fce19d6b804e)) (scan mp_get __t4yhY674 __t9W40673 k) (body (join mbranch (0 1 2 3 4) 1 __t9W40673 p m l r) (let __t0O9f676 (band k m)) (cmp lt __t0O9f676 __tconst84Si675)) (head (emit $sup5638x51x0x0x0 (0 1 2 3 4 5) __t4yhY674 k l m p r)) map.slog:52 #f)
  class ReadTask397 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex396;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x51x0x0x0");
      std::vector<u16> ord398({0, 1, 2, 3, 4, 5});
      slog::Relation* readrel399 = db->getRelation("$sup5638x51x0x0x0");
      head_index[0] = readrel399->getIndex(ord398, false);
      outer_rel = db->getRelation("mp_get");
      std::vector<u16> ord400({0, 1, 2, 3, 4});
      slog::Relation* readrel401 = db->getRelation("mbranch");
      mbranchindex396 = readrel401->getIndex(ord400, false);
  
    }
    ReadTask397(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c142 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c143 = _t[0];
        u64 v_c144 = _t[1];
        u64 v_c44 = _t[2];
        slog::join_probe<5,1>(mbranchindex396, std::array<u64,5>{v_c144, 0, 0, 0, 0}, [&](const std::array<u64,5>& m402) {
          u64 v_c71 = m402[1]; u64 v_c70 = m402[2]; u64 v_c69 = m402[3]; u64 v_c93 = m402[4];
          u64 v_c145 = _prim_band(db, v_c44, v_c70);
          if (v_c145 == slog_error) { slog::emit_pending_error(db, "map.slog:52"); return; }
          u64 v_c146 = _prim_lt(db, v_c145, v_c142);
          if (v_c146 == slog_error) { slog::emit_pending_error(db, "map.slog:52"); return; }
          if (!v_c146) return;
          ++_fires;
          slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c143, v_c44, v_c69, v_c70, v_c71, v_c93}, std::array<u16,6>{0, 1, 2, 3, 4, 5});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:52", "delta:mp_get", _fires);
  
      if (!_done)
      {
        ReadTask397* _cont = new ReadTask397(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask397(db,b), false);
  // (crule (pre (let __trid2tNc1248 consta0e8b3efb8cecb7adf11ee61) (let __trel42Nh1249 constdd7bbf31ce5f578b9805e840) (let __tcol31O11250 const5feceb66ffc86f38d952786c) (let __trel4bsj1251 constdd7bbf31ce5f578b9805e840) (let __tcol1RCH1252 const6b86b273ff34fce19d6b804e)) (scan $sup5638x59x0x0x0 __d0 k l m p r) (body) (head (tycheck k (accept int) __trid2tNc1248 __trel42Nh1249 __tcol31O11250 (1 2 3 4 0)) (tycheck m (accept int) __trid2tNc1248 __trel4bsj1251 __tcol1RCH1252 (1 2 3 4 0)) (mkstruct mp_msk (1 2 0) __1ual1247 k m)) map.slog:60 #f)
  class ReadTask404 : public slog::Task
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
      outer_rel = db->getRelation("$sup5638x59x0x0x0");
  
    }
    ReadTask404(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c147 = v_consta0e8b3efb8cecb7adf11ee61;
      u64 v_c148 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c149 = v_const5feceb66ffc86f38d952786c;
      u64 v_c150 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c151 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c22 = _t[0];
        u64 v_c44 = _t[1];
        u64 v_c69 = _t[2];
        u64 v_c70 = _t[3];
        u64 v_c71 = _t[4];
        u64 v_c93 = _t[5];
        ++_fires;
        if (!(is_int(v_c44)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c147, v_c148, v_c149, v_c44}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c70)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c147, v_c150, v_c151, v_c70}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c44, v_c70}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:60", "delta:$sup5638x59x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask404* _cont = new ReadTask404(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask404(db,b), false);
  // (crule (pre (let __tconst2EWQ349 const6b86b273ff34fce19d6b804e)) (scan mp_get __t50Md348 __t5IXI347 k) (body (exists mp_get (2 0 1) 1 k) (join $sup5638x51x0x0x0 (0 1 2 3 4 5) 2 __t50Md348 k l m p r) (join mbranch (1 2 3 4 0) 5 p m l r __t5IXI347) (join-old mp_get (1 2 0) 2 (1 2 0) l k __t7Zfl351) (join mp_get_ans (0 1) 1 __t7Zfl351 v) (let __t51z6350 (band k m)) (cmp lt __t51z6350 __tconst2EWQ349)) (head (emit mp_get_ans (0 1) __t50Md348 v)) map.slog:52 #f)
  class ReadTask411 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_getindex405;  slog::Index** $sup5638x51x0x0x0index406;  slog::Index** mbranchindex407;  slog::Index** mp_getindex408;  slog::Index** mp_get_ansindex409;  slog::Index** mp_getdelta410;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_get_ans");
      std::vector<u16> ord412({0, 1});
      slog::Relation* readrel413 = db->getRelation("mp_get_ans");
      head_index[0] = readrel413->getIndex(ord412, false);
      outer_rel = db->getRelation("mp_get");
      std::vector<u16> ord414({2, 0, 1});
      slog::Relation* readrel415 = db->getRelation("mp_get");
      mp_getindex405 = readrel415->getIndex(ord414, false);
      std::vector<u16> ord416({0, 1, 2, 3, 4, 5});
      slog::Relation* readrel417 = db->getRelation("$sup5638x51x0x0x0");
      $sup5638x51x0x0x0index406 = readrel417->getIndex(ord416, false);
      std::vector<u16> ord418({1, 2, 3, 4, 0});
      slog::Relation* readrel419 = db->getRelation("mbranch");
      mbranchindex407 = readrel419->getIndex(ord418, false);
      std::vector<u16> ord420({1, 2, 0});
      slog::Relation* readrel421 = db->getRelation("mp_get");
      mp_getindex408 = readrel421->getIndex(ord420, false);
      std::vector<u16> ord422({1, 2, 0});
      slog::Relation* readrel423 = db->getRelation("mp_get");
      mp_getdelta410 = readrel423->getIndex(ord422, true);
      std::vector<u16> ord424({0, 1});
      slog::Relation* readrel425 = db->getRelation("mp_get_ans");
      mp_get_ansindex409 = readrel425->getIndex(ord424, false);
  
    }
    ReadTask411(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c152 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c153 = _t[0];
        u64 v_c154 = _t[1];
        u64 v_c44 = _t[2];
        if (!slog::exists_probe<3,1>(mp_getindex405, std::array<u64,3>{v_c44, 0, 0})) return;
        slog::join_probe<6,2>($sup5638x51x0x0x0index406, std::array<u64,6>{v_c153, v_c44, 0, 0, 0, 0}, [&](const std::array<u64,6>& m426) {
          u64 v_c69 = m426[2]; u64 v_c70 = m426[3]; u64 v_c71 = m426[4]; u64 v_c93 = m426[5];
          slog::join_probe<5,5>(mbranchindex407, std::array<u64,5>{v_c71, v_c70, v_c69, v_c93, v_c154}, [&](const std::array<u64,5>& m427) {
            slog::join_probe_old<3,2>(mp_getindex408, mp_getdelta410, std::array<u64,3>{v_c69, v_c44, 0}, [&](const std::array<u64,3>& m428) {
              u64 v_c155 = m428[2];
              slog::join_probe<2,1>(mp_get_ansindex409, std::array<u64,2>{v_c155, 0}, [&](const std::array<u64,2>& m429) {
                u64 v_c53 = m429[1];
                u64 v_c156 = _prim_band(db, v_c44, v_c70);
                if (v_c156 == slog_error) { slog::emit_pending_error(db, "map.slog:52"); return; }
                u64 v_c157 = _prim_lt(db, v_c156, v_c152);
                if (v_c157 == slog_error) { slog::emit_pending_error(db, "map.slog:52"); return; }
                if (!v_c157) return;
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c153, v_c53}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:52", "delta:mp_get", _fires);
  
      if (!_done)
      {
        ReadTask411* _cont = new ReadTask411(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask411(db,b), false);
  // (crule (pre) (scan mp_put __t1iR2591 __t4G0B592 k v) (body (join-old mbranch (0 1 2 3 4) 1 (0 1 2 3 4) __t4G0B592 p m l r)) (head (emit $sup5638x44x0x0x0 (1 3 7 0 2 4 5 6) k m v __t1iR2591 l p r __t4G0B592)) map.slog:45 #f)
  class ReadTask433 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex431;  slog::Index** mbranchdelta432;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x44x0x0x0");
      std::vector<u16> ord434({1, 3, 7, 0, 2, 4, 5, 6});
      slog::Relation* readrel435 = db->getRelation("$sup5638x44x0x0x0");
      head_index[0] = readrel435->getIndex(ord434, false);
      outer_rel = db->getRelation("mp_put");
      std::vector<u16> ord436({0, 1, 2, 3, 4});
      slog::Relation* readrel437 = db->getRelation("mbranch");
      mbranchindex431 = readrel437->getIndex(ord436, false);
      std::vector<u16> ord438({0, 1, 2, 3, 4});
      slog::Relation* readrel439 = db->getRelation("mbranch");
      mbranchdelta432 = readrel439->getIndex(ord438, true);
  
    }
    ReadTask433(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c158 = _t[0];
        u64 v_c159 = _t[1];
        u64 v_c44 = _t[2];
        u64 v_c53 = _t[3];
        slog::join_probe_old<5,1>(mbranchindex431, mbranchdelta432, std::array<u64,5>{v_c159, 0, 0, 0, 0}, [&](const std::array<u64,5>& m440) {
          u64 v_c71 = m440[1]; u64 v_c70 = m440[2]; u64 v_c69 = m440[3]; u64 v_c93 = m440[4];
          ++_fires;
          slog::emit<8>(head_rel[0], head_index[0], newbatch[0], std::array<u64,8>{v_c44, v_c70, v_c53, v_c158, v_c69, v_c71, v_c93, v_c159}, std::array<u16,8>{1, 3, 7, 0, 2, 4, 5, 6});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:45", "delta:mp_put", _fires);
  
      if (!_done)
      {
        ReadTask433* _cont = new ReadTask433(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask433(db,b), false);
  // (crule (pre) (scan $sup70016x87x0x0x0 __t7kdB647 e1 e2 e3 rho t) (body (exists eval (2 3 0 1) 3 rho t __t7kdB647) (exists eval (1 2 3 0) 3 e1 rho t) (exists select_branch (2 3 1 0) 2 e2 e3) (exists eval (2 3 0 1) 2 rho t) (join-old if (1 3 2 0) 3 (1 3 2 0) e1 e3 e2 __t71xd646) (join-old eval (2 3 0 1) 4 (2 3 0 1) rho t __t7kdB647 __t71xd646) (join-old eval (1 2 3 0) 3 (1 2 3 0) e1 rho t __t2MYH648) (exists eval_ans (0 1) 1 __t2MYH648) (join-old select_branch (2 3 1 0) 2 (2 3 1 0) e2 e3 __v0 __t1Vli649) (join eval_ans (0 1) 2 __t2MYH648 __v0) (exists select_branch_ans (0 1) 1 __t1Vli649) (join-old eval (2 3 0 1) 2 (2 3 0 1) rho t __t4Rxn650 __v1) (join select_branch_ans (0 1) 2 __t1Vli649 __v1) (join eval_ans (0 1) 1 __t4Rxn650 __v2)) (head (emit eval_ans (0 1) __t7kdB647 __v2)) interp.slog:88 #f)
  class ReadTask460 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex441;  slog::Index** evalindex442;  slog::Index** select_branchindex443;  slog::Index** evalindex444;  slog::Index** ifindex445;  slog::Index** evalindex446;  slog::Index** evalindex447;  slog::Index** eval_ansindex448;  slog::Index** select_branchindex449;  slog::Index** eval_ansindex450;  slog::Index** select_branch_ansindex451;  slog::Index** evalindex452;  slog::Index** select_branch_ansindex453;  slog::Index** eval_ansindex454;  slog::Index** ifdelta455;  slog::Index** evaldelta456;  slog::Index** evaldelta457;  slog::Index** select_branchdelta458;  slog::Index** evaldelta459;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord461({0, 1});
      slog::Relation* readrel462 = db->getRelation("eval_ans");
      head_index[0] = readrel462->getIndex(ord461, false);
      outer_rel = db->getRelation("$sup70016x87x0x0x0");
      std::vector<u16> ord463({2, 3, 0, 1});
      slog::Relation* readrel464 = db->getRelation("eval");
      evalindex441 = readrel464->getIndex(ord463, false);
      std::vector<u16> ord465({1, 2, 3, 0});
      slog::Relation* readrel466 = db->getRelation("eval");
      evalindex442 = readrel466->getIndex(ord465, false);
      std::vector<u16> ord467({2, 3, 1, 0});
      slog::Relation* readrel468 = db->getRelation("select_branch");
      select_branchindex443 = readrel468->getIndex(ord467, false);
      std::vector<u16> ord469({2, 3, 0, 1});
      slog::Relation* readrel470 = db->getRelation("eval");
      evalindex444 = readrel470->getIndex(ord469, false);
      std::vector<u16> ord471({1, 3, 2, 0});
      slog::Relation* readrel472 = db->getRelation("if");
      ifindex445 = readrel472->getIndex(ord471, false);
      std::vector<u16> ord473({1, 3, 2, 0});
      slog::Relation* readrel474 = db->getRelation("if");
      ifdelta455 = readrel474->getIndex(ord473, true);
      std::vector<u16> ord475({2, 3, 0, 1});
      slog::Relation* readrel476 = db->getRelation("eval");
      evalindex446 = readrel476->getIndex(ord475, false);
      std::vector<u16> ord477({2, 3, 0, 1});
      slog::Relation* readrel478 = db->getRelation("eval");
      evaldelta456 = readrel478->getIndex(ord477, true);
      std::vector<u16> ord479({1, 2, 3, 0});
      slog::Relation* readrel480 = db->getRelation("eval");
      evalindex447 = readrel480->getIndex(ord479, false);
      std::vector<u16> ord481({1, 2, 3, 0});
      slog::Relation* readrel482 = db->getRelation("eval");
      evaldelta457 = readrel482->getIndex(ord481, true);
      std::vector<u16> ord483({0, 1});
      slog::Relation* readrel484 = db->getRelation("eval_ans");
      eval_ansindex448 = readrel484->getIndex(ord483, false);
      std::vector<u16> ord485({2, 3, 1, 0});
      slog::Relation* readrel486 = db->getRelation("select_branch");
      select_branchindex449 = readrel486->getIndex(ord485, false);
      std::vector<u16> ord487({2, 3, 1, 0});
      slog::Relation* readrel488 = db->getRelation("select_branch");
      select_branchdelta458 = readrel488->getIndex(ord487, true);
      std::vector<u16> ord489({0, 1});
      slog::Relation* readrel490 = db->getRelation("eval_ans");
      eval_ansindex450 = readrel490->getIndex(ord489, false);
      std::vector<u16> ord491({0, 1});
      slog::Relation* readrel492 = db->getRelation("select_branch_ans");
      select_branch_ansindex451 = readrel492->getIndex(ord491, false);
      std::vector<u16> ord493({2, 3, 0, 1});
      slog::Relation* readrel494 = db->getRelation("eval");
      evalindex452 = readrel494->getIndex(ord493, false);
      std::vector<u16> ord495({2, 3, 0, 1});
      slog::Relation* readrel496 = db->getRelation("eval");
      evaldelta459 = readrel496->getIndex(ord495, true);
      std::vector<u16> ord497({0, 1});
      slog::Relation* readrel498 = db->getRelation("select_branch_ans");
      select_branch_ansindex453 = readrel498->getIndex(ord497, false);
      std::vector<u16> ord499({0, 1});
      slog::Relation* readrel500 = db->getRelation("eval_ans");
      eval_ansindex454 = readrel500->getIndex(ord499, false);
  
    }
    ReadTask460(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c160 = _t[0];
        u64 v_c161 = _t[1];
        u64 v_c162 = _t[2];
        u64 v_c163 = _t[3];
        u64 v_c26 = _t[4];
        u64 v_c28 = _t[5];
        if (!slog::exists_probe<4,3>(evalindex441, std::array<u64,4>{v_c26, v_c28, v_c160, 0})) return;
        if (!slog::exists_probe<4,3>(evalindex442, std::array<u64,4>{v_c161, v_c26, v_c28, 0})) return;
        if (!slog::exists_probe<4,2>(select_branchindex443, std::array<u64,4>{v_c162, v_c163, 0, 0})) return;
        if (!slog::exists_probe<4,2>(evalindex444, std::array<u64,4>{v_c26, v_c28, 0, 0})) return;
        slog::join_probe_old<4,3>(ifindex445, ifdelta455, std::array<u64,4>{v_c161, v_c163, v_c162, 0}, [&](const std::array<u64,4>& m501) {
          u64 v_c164 = m501[3];
          slog::join_probe_old<4,4>(evalindex446, evaldelta456, std::array<u64,4>{v_c26, v_c28, v_c160, v_c164}, [&](const std::array<u64,4>& m502) {
            slog::join_probe_old<4,3>(evalindex447, evaldelta457, std::array<u64,4>{v_c161, v_c26, v_c28, 0}, [&](const std::array<u64,4>& m503) {
              u64 v_c165 = m503[3];
              if (!slog::exists_probe<2,1>(eval_ansindex448, std::array<u64,2>{v_c165, 0})) return;
              slog::join_probe_old<4,2>(select_branchindex449, select_branchdelta458, std::array<u64,4>{v_c162, v_c163, 0, 0}, [&](const std::array<u64,4>& m504) {
                u64 v_c47 = m504[2]; u64 v_c166 = m504[3];
                slog::join_probe<2,2>(eval_ansindex450, std::array<u64,2>{v_c165, v_c47}, [&](const std::array<u64,2>& m505) {
                  if (!slog::exists_probe<2,1>(select_branch_ansindex451, std::array<u64,2>{v_c166, 0})) return;
                  slog::join_probe_old<4,2>(evalindex452, evaldelta459, std::array<u64,4>{v_c26, v_c28, 0, 0}, [&](const std::array<u64,4>& m506) {
                    u64 v_c167 = m506[2]; u64 v_c168 = m506[3];
                    slog::join_probe<2,2>(select_branch_ansindex453, std::array<u64,2>{v_c166, v_c168}, [&](const std::array<u64,2>& m507) {
                      slog::join_probe<2,1>(eval_ansindex454, std::array<u64,2>{v_c167, 0}, [&](const std::array<u64,2>& m508) {
                        u64 v_c169 = m508[1];
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c160, v_c169}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:88", "delta:$sup70016x87x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask460* _cont = new ReadTask460(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask460(db,b), false);
  // (crule (pre (let __tconst0xOc223 const5feceb66ffc86f38d952786c)) (scan mp_msk_ans __t4NVE225 p) (body (exists $sup5638x98x0x0x1 (1 5 0 2 3 4 6 7 8 9) 2 __t4NVE225 p) (exists $sup5638x98x0x0x0 (4 1 2 6 0 3 5 7 8) 1 p) (exists mbranch (1 2 3 4 0) 1 p) (join-old mp_msk (0 1 2) 1 (0 1 2) __t4NVE225 q m) (exists $sup5638x98x0x0x0 (2 5 4 0 1 3 6 7 8) 3 m q p) (exists mbranch (1 2 3 4 0) 2 p m) (exists mbranch (1 2 3 4 0) 1 q) (join-old $sup5638x98x0x0x1 (1 3 6 5 0 2 4 7 8 9) 4 (1 3 6 5 0 2 4 7 8 9) __t4NVE225 m q p __t14N0222 l n r u v) (cmp lt n m) (join-old $sup5638x98x0x0x0 (4 1 2 6 0 3 5 7 8) 9 (4 1 2 6 0 3 5 7 8) p l m r __t14N0222 n q u v) (exists mbranch (1 2 3 4 0) 4 q n u v) (exists mp_union (1 2 0) 1 r) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t006N221) (exists mp_union (0 1 2) 2 __t14N0222 __t006N221) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t5FeR226) (join-old mp_union (0 1 2) 3 (0 1 2) __t14N0222 __t006N221 __t5FeR226) (join-old mp_union (1 2 0) 2 (1 2 0) r __t5FeR226 __t6Lp3227) (join-old mp_union_ans (0 1) 1 (0 1) __t6Lp3227 __v0) (let __t91c5224 (band q m)) (cmp gt __t91c5224 __tconst0xOc223)) (head (emit-temp temp0Tjz1856 __t14N0222 __v0 l m p) (mkstruct mbranch (1 2 3 4 0) __t1O3D219 p m l __v0)) map.slog:99 #f)
  class ReadTask534 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x98x0x0x1index509;  slog::Index** $sup5638x98x0x0x0index510;  slog::Index** mbranchindex511;  slog::Index** mp_mskindex512;  slog::Index** $sup5638x98x0x0x0index513;  slog::Index** mbranchindex514;  slog::Index** mbranchindex515;  slog::Index** $sup5638x98x0x0x1index516;  slog::Index** $sup5638x98x0x0x0index517;  slog::Index** mbranchindex518;  slog::Index** mp_unionindex519;  slog::Index** mbranchindex520;  slog::Index** mp_unionindex521;  slog::Index** mbranchindex522;  slog::Index** mp_unionindex523;  slog::Index** mp_unionindex524;  slog::Index** mp_union_ansindex525;  slog::Index** mp_mskdelta526;  slog::Index** $sup5638x98x0x0x1delta527;  slog::Index** $sup5638x98x0x0x0delta528;  slog::Index** mbranchdelta529;  slog::Index** mbranchdelta530;  slog::Index** mp_uniondelta531;  slog::Index** mp_uniondelta532;  slog::Index** mp_union_ansdelta533;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0Tjz1856");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_msk_ans");
      std::vector<u16> ord535({1, 5, 0, 2, 3, 4, 6, 7, 8, 9});
      slog::Relation* readrel536 = db->getRelation("$sup5638x98x0x0x1");
      $sup5638x98x0x0x1index509 = readrel536->getIndex(ord535, false);
      std::vector<u16> ord537({4, 1, 2, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel538 = db->getRelation("$sup5638x98x0x0x0");
      $sup5638x98x0x0x0index510 = readrel538->getIndex(ord537, false);
      std::vector<u16> ord539({1, 2, 3, 4, 0});
      slog::Relation* readrel540 = db->getRelation("mbranch");
      mbranchindex511 = readrel540->getIndex(ord539, false);
      std::vector<u16> ord541({0, 1, 2});
      slog::Relation* readrel542 = db->getRelation("mp_msk");
      mp_mskindex512 = readrel542->getIndex(ord541, false);
      std::vector<u16> ord543({0, 1, 2});
      slog::Relation* readrel544 = db->getRelation("mp_msk");
      mp_mskdelta526 = readrel544->getIndex(ord543, true);
      std::vector<u16> ord545({2, 5, 4, 0, 1, 3, 6, 7, 8});
      slog::Relation* readrel546 = db->getRelation("$sup5638x98x0x0x0");
      $sup5638x98x0x0x0index513 = readrel546->getIndex(ord545, false);
      std::vector<u16> ord547({1, 2, 3, 4, 0});
      slog::Relation* readrel548 = db->getRelation("mbranch");
      mbranchindex514 = readrel548->getIndex(ord547, false);
      std::vector<u16> ord549({1, 2, 3, 4, 0});
      slog::Relation* readrel550 = db->getRelation("mbranch");
      mbranchindex515 = readrel550->getIndex(ord549, false);
      std::vector<u16> ord551({1, 3, 6, 5, 0, 2, 4, 7, 8, 9});
      slog::Relation* readrel552 = db->getRelation("$sup5638x98x0x0x1");
      $sup5638x98x0x0x1index516 = readrel552->getIndex(ord551, false);
      std::vector<u16> ord553({1, 3, 6, 5, 0, 2, 4, 7, 8, 9});
      slog::Relation* readrel554 = db->getRelation("$sup5638x98x0x0x1");
      $sup5638x98x0x0x1delta527 = readrel554->getIndex(ord553, true);
      std::vector<u16> ord555({4, 1, 2, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel556 = db->getRelation("$sup5638x98x0x0x0");
      $sup5638x98x0x0x0index517 = readrel556->getIndex(ord555, false);
      std::vector<u16> ord557({4, 1, 2, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel558 = db->getRelation("$sup5638x98x0x0x0");
      $sup5638x98x0x0x0delta528 = readrel558->getIndex(ord557, true);
      std::vector<u16> ord559({1, 2, 3, 4, 0});
      slog::Relation* readrel560 = db->getRelation("mbranch");
      mbranchindex518 = readrel560->getIndex(ord559, false);
      std::vector<u16> ord561({1, 2, 0});
      slog::Relation* readrel562 = db->getRelation("mp_union");
      mp_unionindex519 = readrel562->getIndex(ord561, false);
      std::vector<u16> ord563({1, 2, 3, 4, 0});
      slog::Relation* readrel564 = db->getRelation("mbranch");
      mbranchindex520 = readrel564->getIndex(ord563, false);
      std::vector<u16> ord565({1, 2, 3, 4, 0});
      slog::Relation* readrel566 = db->getRelation("mbranch");
      mbranchdelta529 = readrel566->getIndex(ord565, true);
      std::vector<u16> ord567({0, 1, 2});
      slog::Relation* readrel568 = db->getRelation("mp_union");
      mp_unionindex521 = readrel568->getIndex(ord567, false);
      std::vector<u16> ord569({1, 2, 3, 4, 0});
      slog::Relation* readrel570 = db->getRelation("mbranch");
      mbranchindex522 = readrel570->getIndex(ord569, false);
      std::vector<u16> ord571({1, 2, 3, 4, 0});
      slog::Relation* readrel572 = db->getRelation("mbranch");
      mbranchdelta530 = readrel572->getIndex(ord571, true);
      std::vector<u16> ord573({0, 1, 2});
      slog::Relation* readrel574 = db->getRelation("mp_union");
      mp_unionindex523 = readrel574->getIndex(ord573, false);
      std::vector<u16> ord575({0, 1, 2});
      slog::Relation* readrel576 = db->getRelation("mp_union");
      mp_uniondelta531 = readrel576->getIndex(ord575, true);
      std::vector<u16> ord577({1, 2, 0});
      slog::Relation* readrel578 = db->getRelation("mp_union");
      mp_unionindex524 = readrel578->getIndex(ord577, false);
      std::vector<u16> ord579({1, 2, 0});
      slog::Relation* readrel580 = db->getRelation("mp_union");
      mp_uniondelta532 = readrel580->getIndex(ord579, true);
      std::vector<u16> ord581({0, 1});
      slog::Relation* readrel582 = db->getRelation("mp_union_ans");
      mp_union_ansindex525 = readrel582->getIndex(ord581, false);
      std::vector<u16> ord583({0, 1});
      slog::Relation* readrel584 = db->getRelation("mp_union_ans");
      mp_union_ansdelta533 = readrel584->getIndex(ord583, true);
  
    }
    ReadTask534(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c170 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c171 = _t[0];
        u64 v_c71 = _t[1];
        if (!slog::exists_probe<10,2>($sup5638x98x0x0x1index509, std::array<u64,10>{v_c171, v_c71, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<9,1>($sup5638x98x0x0x0index510, std::array<u64,9>{v_c71, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex511, std::array<u64,5>{v_c71, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(mp_mskindex512, mp_mskdelta526, std::array<u64,3>{v_c171, 0, 0}, [&](const std::array<u64,3>& m585) {
          u64 v_c125 = m585[1]; u64 v_c70 = m585[2];
          if (!slog::exists_probe<9,3>($sup5638x98x0x0x0index513, std::array<u64,9>{v_c70, v_c125, v_c71, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,2>(mbranchindex514, std::array<u64,5>{v_c71, v_c70, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>(mbranchindex515, std::array<u64,5>{v_c125, 0, 0, 0, 0})) return;
          slog::join_probe_old<10,4>($sup5638x98x0x0x1index516, $sup5638x98x0x0x1delta527, std::array<u64,10>{v_c171, v_c70, v_c125, v_c71, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,10>& m586) {
            u64 v_c68 = m586[4]; u64 v_c69 = m586[5]; u64 v_c126 = m586[6]; u64 v_c93 = m586[7]; u64 v_c127 = m586[8]; u64 v_c53 = m586[9];
            u64 v_c172 = _prim_lt(db, v_c126, v_c70);
            if (v_c172 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
            if (!v_c172) return;
            slog::join_probe_old<9,9>($sup5638x98x0x0x0index517, $sup5638x98x0x0x0delta528, std::array<u64,9>{v_c71, v_c69, v_c70, v_c93, v_c68, v_c126, v_c125, v_c127, v_c53}, [&](const std::array<u64,9>& m588) {
              if (!slog::exists_probe<5,4>(mbranchindex518, std::array<u64,5>{v_c125, v_c126, v_c127, v_c53, 0})) return;
              if (!slog::exists_probe<3,1>(mp_unionindex519, std::array<u64,3>{v_c93, 0, 0})) return;
              slog::join_probe_old<5,4>(mbranchindex520, mbranchdelta529, std::array<u64,5>{v_c71, v_c70, v_c69, v_c93, 0}, [&](const std::array<u64,5>& m589) {
                u64 v_c173 = m589[4];
                if (!slog::exists_probe<3,2>(mp_unionindex521, std::array<u64,3>{v_c68, v_c173, 0})) return;
                slog::join_probe_old<5,4>(mbranchindex522, mbranchdelta530, std::array<u64,5>{v_c125, v_c126, v_c127, v_c53, 0}, [&](const std::array<u64,5>& m590) {
                  u64 v_c174 = m590[4];
                  slog::join_probe_old<3,3>(mp_unionindex523, mp_uniondelta531, std::array<u64,3>{v_c68, v_c173, v_c174}, [&](const std::array<u64,3>& m591) {
                    slog::join_probe_old<3,2>(mp_unionindex524, mp_uniondelta532, std::array<u64,3>{v_c93, v_c174, 0}, [&](const std::array<u64,3>& m592) {
                      u64 v_c175 = m592[2];
                      slog::join_probe_old<2,1>(mp_union_ansindex525, mp_union_ansdelta533, std::array<u64,2>{v_c175, 0}, [&](const std::array<u64,2>& m593) {
                        u64 v_c47 = m593[1];
                        u64 v_c176 = _prim_band(db, v_c125, v_c70);
                        if (v_c176 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
                        u64 v_c177 = _prim_gt(db, v_c176, v_c170);
                        if (v_c177 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
                        if (!v_c177) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c68, v_c47, v_c69, v_c70, v_c71});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c71, v_c70, v_c69, v_c47}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:99", "delta:mp_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask534* _cont = new ReadTask534(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask534(db,b), false);
  // (crule (pre) (scan eval __t5vg0669 __t2w2P668 rho t) (body (exists $sup70016x92x0x0x1 (0 6 7 4 5 9 1 2 3 8) 3 __t5vg0669 rho t) (exists eval (2 3 0 1) 2 rho t) (exists mp_put (1 3 0 2) 2 rho t) (exists eval (3 1 0 2) 1 t) (join $sup70016x92x0x0x0 (0 3 4 1 2 5) 3 __t5vg0669 rho t eb er x) (exists let (1 2 3 0) 4 x er eb __t2w2P668) (exists eval (1 2 3 0) 3 er rho t) (exists mp_put (1 2 3 0) 3 rho x t) (exists eval (3 1 0 2) 2 t eb) (join $sup70016x92x0x0x1 (0 6 7 4 5 9 1 2 3 8) 6 __t5vg0669 rho t eb er x __t7GLg670 __t0mp6672 __v0 vr) (join let (1 2 3 0) 4 x er eb __t2w2P668) (join-old eval (2 3 0 1) 4 (2 3 0 1) rho t __t7GLg670 er) (join-old mp_put (0 2 1 3) 4 (0 2 1 3) __t0mp6672 x rho t) (exists eval_ans (0 1) 2 __t7GLg670 vr) (exists mp_put_ans (0 1) 2 __t0mp6672 __v0) (join-old eval (1 2 3 0) 3 (1 2 3 0) eb __v0 t __t3BcP671) (join eval_ans (0 1) 2 __t7GLg670 vr) (join mp_put_ans (0 1) 2 __t0mp6672 __v0) (join eval_ans (0 1) 1 __t3BcP671 v)) (head (emit eval_ans (0 1) __t5vg0669 v)) interp.slog:93 #f)
  class ReadTask617 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup70016x92x0x0x1index595;  slog::Index** evalindex596;  slog::Index** mp_putindex597;  slog::Index** evalindex598;  slog::Index** $sup70016x92x0x0x0index599;  slog::Index** letindex600;  slog::Index** evalindex601;  slog::Index** mp_putindex602;  slog::Index** evalindex603;  slog::Index** $sup70016x92x0x0x1index604;  slog::Index** letindex605;  slog::Index** evalindex606;  slog::Index** mp_putindex607;  slog::Index** eval_ansindex608;  slog::Index** mp_put_ansindex609;  slog::Index** evalindex610;  slog::Index** eval_ansindex611;  slog::Index** mp_put_ansindex612;  slog::Index** eval_ansindex613;  slog::Index** evaldelta614;  slog::Index** mp_putdelta615;  slog::Index** evaldelta616;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord618({0, 1});
      slog::Relation* readrel619 = db->getRelation("eval_ans");
      head_index[0] = readrel619->getIndex(ord618, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord620({0, 6, 7, 4, 5, 9, 1, 2, 3, 8});
      slog::Relation* readrel621 = db->getRelation("$sup70016x92x0x0x1");
      $sup70016x92x0x0x1index595 = readrel621->getIndex(ord620, false);
      std::vector<u16> ord622({2, 3, 0, 1});
      slog::Relation* readrel623 = db->getRelation("eval");
      evalindex596 = readrel623->getIndex(ord622, false);
      std::vector<u16> ord624({1, 3, 0, 2});
      slog::Relation* readrel625 = db->getRelation("mp_put");
      mp_putindex597 = readrel625->getIndex(ord624, false);
      std::vector<u16> ord626({3, 1, 0, 2});
      slog::Relation* readrel627 = db->getRelation("eval");
      evalindex598 = readrel627->getIndex(ord626, false);
      std::vector<u16> ord628({0, 3, 4, 1, 2, 5});
      slog::Relation* readrel629 = db->getRelation("$sup70016x92x0x0x0");
      $sup70016x92x0x0x0index599 = readrel629->getIndex(ord628, false);
      std::vector<u16> ord630({1, 2, 3, 0});
      slog::Relation* readrel631 = db->getRelation("let");
      letindex600 = readrel631->getIndex(ord630, false);
      std::vector<u16> ord632({1, 2, 3, 0});
      slog::Relation* readrel633 = db->getRelation("eval");
      evalindex601 = readrel633->getIndex(ord632, false);
      std::vector<u16> ord634({1, 2, 3, 0});
      slog::Relation* readrel635 = db->getRelation("mp_put");
      mp_putindex602 = readrel635->getIndex(ord634, false);
      std::vector<u16> ord636({3, 1, 0, 2});
      slog::Relation* readrel637 = db->getRelation("eval");
      evalindex603 = readrel637->getIndex(ord636, false);
      std::vector<u16> ord638({0, 6, 7, 4, 5, 9, 1, 2, 3, 8});
      slog::Relation* readrel639 = db->getRelation("$sup70016x92x0x0x1");
      $sup70016x92x0x0x1index604 = readrel639->getIndex(ord638, false);
      std::vector<u16> ord640({1, 2, 3, 0});
      slog::Relation* readrel641 = db->getRelation("let");
      letindex605 = readrel641->getIndex(ord640, false);
      std::vector<u16> ord642({2, 3, 0, 1});
      slog::Relation* readrel643 = db->getRelation("eval");
      evalindex606 = readrel643->getIndex(ord642, false);
      std::vector<u16> ord644({2, 3, 0, 1});
      slog::Relation* readrel645 = db->getRelation("eval");
      evaldelta614 = readrel645->getIndex(ord644, true);
      std::vector<u16> ord646({0, 2, 1, 3});
      slog::Relation* readrel647 = db->getRelation("mp_put");
      mp_putindex607 = readrel647->getIndex(ord646, false);
      std::vector<u16> ord648({0, 2, 1, 3});
      slog::Relation* readrel649 = db->getRelation("mp_put");
      mp_putdelta615 = readrel649->getIndex(ord648, true);
      std::vector<u16> ord650({0, 1});
      slog::Relation* readrel651 = db->getRelation("eval_ans");
      eval_ansindex608 = readrel651->getIndex(ord650, false);
      std::vector<u16> ord652({0, 1});
      slog::Relation* readrel653 = db->getRelation("mp_put_ans");
      mp_put_ansindex609 = readrel653->getIndex(ord652, false);
      std::vector<u16> ord654({1, 2, 3, 0});
      slog::Relation* readrel655 = db->getRelation("eval");
      evalindex610 = readrel655->getIndex(ord654, false);
      std::vector<u16> ord656({1, 2, 3, 0});
      slog::Relation* readrel657 = db->getRelation("eval");
      evaldelta616 = readrel657->getIndex(ord656, true);
      std::vector<u16> ord658({0, 1});
      slog::Relation* readrel659 = db->getRelation("eval_ans");
      eval_ansindex611 = readrel659->getIndex(ord658, false);
      std::vector<u16> ord660({0, 1});
      slog::Relation* readrel661 = db->getRelation("mp_put_ans");
      mp_put_ansindex612 = readrel661->getIndex(ord660, false);
      std::vector<u16> ord662({0, 1});
      slog::Relation* readrel663 = db->getRelation("eval_ans");
      eval_ansindex613 = readrel663->getIndex(ord662, false);
  
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
        u64 v_c49 = _t[0];
        u64 v_c52 = _t[1];
        u64 v_c26 = _t[2];
        u64 v_c28 = _t[3];
        if (!slog::exists_probe<10,3>($sup70016x92x0x0x1index595, std::array<u64,10>{v_c49, v_c26, v_c28, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<4,2>(evalindex596, std::array<u64,4>{v_c26, v_c28, 0, 0})) return;
        if (!slog::exists_probe<4,2>(mp_putindex597, std::array<u64,4>{v_c26, v_c28, 0, 0})) return;
        if (!slog::exists_probe<4,1>(evalindex598, std::array<u64,4>{v_c28, 0, 0, 0})) return;
        slog::join_probe<6,3>($sup70016x92x0x0x0index599, std::array<u64,6>{v_c49, v_c26, v_c28, 0, 0, 0}, [&](const std::array<u64,6>& m664) {
          u64 v_c24 = m664[3]; u64 v_c25 = m664[4]; u64 v_c29 = m664[5];
          if (!slog::exists_probe<4,4>(letindex600, std::array<u64,4>{v_c29, v_c25, v_c24, v_c52})) return;
          if (!slog::exists_probe<4,3>(evalindex601, std::array<u64,4>{v_c25, v_c26, v_c28, 0})) return;
          if (!slog::exists_probe<4,3>(mp_putindex602, std::array<u64,4>{v_c26, v_c29, v_c28, 0})) return;
          if (!slog::exists_probe<4,2>(evalindex603, std::array<u64,4>{v_c28, v_c24, 0, 0})) return;
          slog::join_probe<10,6>($sup70016x92x0x0x1index604, std::array<u64,10>{v_c49, v_c26, v_c28, v_c24, v_c25, v_c29, 0, 0, 0, 0}, [&](const std::array<u64,10>& m665) {
            u64 v_c50 = m665[6]; u64 v_c46 = m665[7]; u64 v_c47 = m665[8]; u64 v_c51 = m665[9];
            slog::join_probe<4,4>(letindex605, std::array<u64,4>{v_c29, v_c25, v_c24, v_c52}, [&](const std::array<u64,4>& m666) {
              slog::join_probe_old<4,4>(evalindex606, evaldelta614, std::array<u64,4>{v_c26, v_c28, v_c50, v_c25}, [&](const std::array<u64,4>& m667) {
                slog::join_probe_old<4,4>(mp_putindex607, mp_putdelta615, std::array<u64,4>{v_c46, v_c29, v_c26, v_c28}, [&](const std::array<u64,4>& m668) {
                  if (!slog::exists_probe<2,2>(eval_ansindex608, std::array<u64,2>{v_c50, v_c51})) return;
                  if (!slog::exists_probe<2,2>(mp_put_ansindex609, std::array<u64,2>{v_c46, v_c47})) return;
                  slog::join_probe_old<4,3>(evalindex610, evaldelta616, std::array<u64,4>{v_c24, v_c47, v_c28, 0}, [&](const std::array<u64,4>& m669) {
                    u64 v_c48 = m669[3];
                    slog::join_probe<2,2>(eval_ansindex611, std::array<u64,2>{v_c50, v_c51}, [&](const std::array<u64,2>& m670) {
                      slog::join_probe<2,2>(mp_put_ansindex612, std::array<u64,2>{v_c46, v_c47}, [&](const std::array<u64,2>& m671) {
                        slog::join_probe<2,1>(eval_ansindex613, std::array<u64,2>{v_c48, 0}, [&](const std::array<u64,2>& m672) {
                          u64 v_c53 = m672[1];
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c49, v_c53}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:93", "delta:eval", _fires);
  
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
  // (crule (pre (let __tconst6BXE233 const5feceb66ffc86f38d952786c)) (scan mp_has0_ans __t2sXu235 a) (body (join-old mp_has0 (0 2 1) 1 (0 2 1) __t2sXu235 k r) (exists mbranch (4 0 1 2 3) 1 r) (exists mp_has0 (2 0 1) 1 k) (exists mp_msk (1 2 0) 1 k) (join-old $sup5638x62x0x0x0 (1 5 0 2 3 4) 2 (1 5 0 2 3 4) k r __t7cml232 l m p) (exists mp_has0 (0 2 1) 2 __t7cml232 k) (exists mp_msk (1 2 0) 2 k m) (exists mp_msk_ans (1 0) 1 p) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t5gI3231) (join-old mp_has0 (0 2 1) 3 (0 2 1) __t7cml232 k __t5gI3231) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t9BfR236) (join-old mp_msk_ans (0 1) 2 (0 1) __t9BfR236 p) (let __t2LqG234 (band k m)) (cmp gt __t2LqG234 __tconst6BXE233)) (head (emit mp_has0_ans (0 1) __t7cml232 a)) map.slog:63 #f)
  class ReadTask691 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_has0index673;  slog::Index** mbranchindex674;  slog::Index** mp_has0index675;  slog::Index** mp_mskindex676;  slog::Index** $sup5638x62x0x0x0index677;  slog::Index** mp_has0index678;  slog::Index** mp_mskindex679;  slog::Index** mp_msk_ansindex680;  slog::Index** mbranchindex681;  slog::Index** mp_has0index682;  slog::Index** mp_mskindex683;  slog::Index** mp_msk_ansindex684;  slog::Index** mp_has0delta685;  slog::Index** $sup5638x62x0x0x0delta686;  slog::Index** mbranchdelta687;  slog::Index** mp_has0delta688;  slog::Index** mp_mskdelta689;  slog::Index** mp_msk_ansdelta690;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_has0_ans");
      std::vector<u16> ord692({0, 1});
      slog::Relation* readrel693 = db->getRelation("mp_has0_ans");
      head_index[0] = readrel693->getIndex(ord692, false);
      outer_rel = db->getRelation("mp_has0_ans");
      std::vector<u16> ord694({0, 2, 1});
      slog::Relation* readrel695 = db->getRelation("mp_has0");
      mp_has0index673 = readrel695->getIndex(ord694, false);
      std::vector<u16> ord696({0, 2, 1});
      slog::Relation* readrel697 = db->getRelation("mp_has0");
      mp_has0delta685 = readrel697->getIndex(ord696, true);
      std::vector<u16> ord698({4, 0, 1, 2, 3});
      slog::Relation* readrel699 = db->getRelation("mbranch");
      mbranchindex674 = readrel699->getIndex(ord698, false);
      std::vector<u16> ord700({2, 0, 1});
      slog::Relation* readrel701 = db->getRelation("mp_has0");
      mp_has0index675 = readrel701->getIndex(ord700, false);
      std::vector<u16> ord702({1, 2, 0});
      slog::Relation* readrel703 = db->getRelation("mp_msk");
      mp_mskindex676 = readrel703->getIndex(ord702, false);
      std::vector<u16> ord704({1, 5, 0, 2, 3, 4});
      slog::Relation* readrel705 = db->getRelation("$sup5638x62x0x0x0");
      $sup5638x62x0x0x0index677 = readrel705->getIndex(ord704, false);
      std::vector<u16> ord706({1, 5, 0, 2, 3, 4});
      slog::Relation* readrel707 = db->getRelation("$sup5638x62x0x0x0");
      $sup5638x62x0x0x0delta686 = readrel707->getIndex(ord706, true);
      std::vector<u16> ord708({0, 2, 1});
      slog::Relation* readrel709 = db->getRelation("mp_has0");
      mp_has0index678 = readrel709->getIndex(ord708, false);
      std::vector<u16> ord710({1, 2, 0});
      slog::Relation* readrel711 = db->getRelation("mp_msk");
      mp_mskindex679 = readrel711->getIndex(ord710, false);
      std::vector<u16> ord712({1, 0});
      slog::Relation* readrel713 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex680 = readrel713->getIndex(ord712, false);
      std::vector<u16> ord714({1, 2, 3, 4, 0});
      slog::Relation* readrel715 = db->getRelation("mbranch");
      mbranchindex681 = readrel715->getIndex(ord714, false);
      std::vector<u16> ord716({1, 2, 3, 4, 0});
      slog::Relation* readrel717 = db->getRelation("mbranch");
      mbranchdelta687 = readrel717->getIndex(ord716, true);
      std::vector<u16> ord718({0, 2, 1});
      slog::Relation* readrel719 = db->getRelation("mp_has0");
      mp_has0index682 = readrel719->getIndex(ord718, false);
      std::vector<u16> ord720({0, 2, 1});
      slog::Relation* readrel721 = db->getRelation("mp_has0");
      mp_has0delta688 = readrel721->getIndex(ord720, true);
      std::vector<u16> ord722({1, 2, 0});
      slog::Relation* readrel723 = db->getRelation("mp_msk");
      mp_mskindex683 = readrel723->getIndex(ord722, false);
      std::vector<u16> ord724({1, 2, 0});
      slog::Relation* readrel725 = db->getRelation("mp_msk");
      mp_mskdelta689 = readrel725->getIndex(ord724, true);
      std::vector<u16> ord726({0, 1});
      slog::Relation* readrel727 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex684 = readrel727->getIndex(ord726, false);
      std::vector<u16> ord728({0, 1});
      slog::Relation* readrel729 = db->getRelation("mp_msk_ans");
      mp_msk_ansdelta690 = readrel729->getIndex(ord728, true);
  
    }
    ReadTask691(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c178 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c179 = _t[0];
        u64 v_c180 = _t[1];
        slog::join_probe_old<3,1>(mp_has0index673, mp_has0delta685, std::array<u64,3>{v_c179, 0, 0}, [&](const std::array<u64,3>& m730) {
          u64 v_c44 = m730[1]; u64 v_c93 = m730[2];
          if (!slog::exists_probe<5,1>(mbranchindex674, std::array<u64,5>{v_c93, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_has0index675, std::array<u64,3>{v_c44, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_mskindex676, std::array<u64,3>{v_c44, 0, 0})) return;
          slog::join_probe_old<6,2>($sup5638x62x0x0x0index677, $sup5638x62x0x0x0delta686, std::array<u64,6>{v_c44, v_c93, 0, 0, 0, 0}, [&](const std::array<u64,6>& m731) {
            u64 v_c181 = m731[2]; u64 v_c69 = m731[3]; u64 v_c70 = m731[4]; u64 v_c71 = m731[5];
            if (!slog::exists_probe<3,2>(mp_has0index678, std::array<u64,3>{v_c181, v_c44, 0})) return;
            if (!slog::exists_probe<3,2>(mp_mskindex679, std::array<u64,3>{v_c44, v_c70, 0})) return;
            if (!slog::exists_probe<2,1>(mp_msk_ansindex680, std::array<u64,2>{v_c71, 0})) return;
            slog::join_probe_old<5,4>(mbranchindex681, mbranchdelta687, std::array<u64,5>{v_c71, v_c70, v_c69, v_c93, 0}, [&](const std::array<u64,5>& m732) {
              u64 v_c182 = m732[4];
              slog::join_probe_old<3,3>(mp_has0index682, mp_has0delta688, std::array<u64,3>{v_c181, v_c44, v_c182}, [&](const std::array<u64,3>& m733) {
                slog::join_probe_old<3,2>(mp_mskindex683, mp_mskdelta689, std::array<u64,3>{v_c44, v_c70, 0}, [&](const std::array<u64,3>& m734) {
                  u64 v_c183 = m734[2];
                  slog::join_probe_old<2,2>(mp_msk_ansindex684, mp_msk_ansdelta690, std::array<u64,2>{v_c183, v_c71}, [&](const std::array<u64,2>& m735) {
                    u64 v_c184 = _prim_band(db, v_c44, v_c70);
                    if (v_c184 == slog_error) { slog::emit_pending_error(db, "map.slog:63"); return; }
                    u64 v_c185 = _prim_gt(db, v_c184, v_c178);
                    if (v_c185 == slog_error) { slog::emit_pending_error(db, "map.slog:63"); return; }
                    if (!v_c185) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c181, v_c180}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:63", "delta:mp_has0_ans", _fires);
  
      if (!_done)
      {
        ReadTask691* _cont = new ReadTask691(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask691(db,b), false);
  // (crule (pre) (scan temp77vn1973 __t4uJJ293 l m p r) (body (join mbranch (1 2 3 4 0) 4 p m l r __t2dgA292)) (head (emit mp_bld_ans (0 1) __t4uJJ293 __t2dgA292)) map.slog:75 #f)
  class ReadTask738 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex737;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_bld_ans");
      std::vector<u16> ord739({0, 1});
      slog::Relation* readrel740 = db->getRelation("mp_bld_ans");
      head_index[0] = readrel740->getIndex(ord739, false);
      outer_rel = db->getRelation("temp77vn1973");
      std::vector<u16> ord741({1, 2, 3, 4, 0});
      slog::Relation* readrel742 = db->getRelation("mbranch");
      mbranchindex737 = readrel742->getIndex(ord741, false);
  
    }
    ReadTask738(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c69 = _t[1];
        u64 v_c70 = _t[2];
        u64 v_c71 = _t[3];
        u64 v_c93 = _t[4];
        slog::join_probe<5,4>(mbranchindex737, std::array<u64,5>{v_c71, v_c70, v_c69, v_c93, 0}, [&](const std::array<u64,5>& m743) {
          u64 v_c187 = m743[4];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c186, v_c187}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:75", "delta:temp77vn1973", _fires);
  
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
  // (crule (pre (let __tconst0xOc223 const5feceb66ffc86f38d952786c)) (scan mp_union __t14N0222 __t006N221 __t5FeR226) (body (exists $sup5638x98x0x0x0 (0 6 1 2 3 4 5 7 8) 1 __t14N0222) (exists $sup5638x98x0x0x1 (0 7 1 2 3 4 5 6 8 9) 1 __t14N0222) (join-old mp_union (2 0 1) 1 (2 0 1) __t5FeR226 __t6Lp3227 r) (exists $sup5638x98x0x0x0 (0 6 1 2 3 4 5 7 8) 2 __t14N0222 r) (exists $sup5638x98x0x0x1 (0 7 1 2 3 4 5 6 8 9) 2 __t14N0222 r) (exists mp_union_ans (0 1) 1 __t6Lp3227) (join mbranch (4 0 1 2 3) 2 r __t006N221 p m l) (exists $sup5638x98x0x0x1 (7 2 3 5 0 4 6 8 9 1) 5 r l m p __t14N0222) (exists mp_msk (2 0 1) 1 m) (exists mp_msk_ans (1 0) 1 p) (join $sup5638x98x0x0x0 (4 1 2 6 0 3 5 7 8) 5 p l m r __t14N0222 n q u v) (cmp lt n m) (exists mbranch (1 2 3 4 0) 5 q n u v __t5FeR226) (exists mp_msk (1 2 0) 2 q m) (join $sup5638x98x0x0x1 (7 2 3 5 0 4 6 8 9 1) 9 r l m p __t14N0222 n q u v __t4NVE225) (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) q n u v __t5FeR226) (join-old mp_msk (1 2 0) 3 (1 2 0) q m __t4NVE225) (join mp_msk_ans (0 1) 2 __t4NVE225 p) (join mp_union_ans (0 1) 1 __t6Lp3227 __v0) (let __t91c5224 (band q m)) (cmp gt __t91c5224 __tconst0xOc223)) (head (emit-temp temp0Tjz1856 __t14N0222 __v0 l m p) (mkstruct mbranch (1 2 3 4 0) __t1O3D219 p m l __v0)) map.slog:99 #f)
  class ReadTask765 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x98x0x0x0index744;  slog::Index** $sup5638x98x0x0x1index745;  slog::Index** mp_unionindex746;  slog::Index** $sup5638x98x0x0x0index747;  slog::Index** $sup5638x98x0x0x1index748;  slog::Index** mp_union_ansindex749;  slog::Index** mbranchindex750;  slog::Index** $sup5638x98x0x0x1index751;  slog::Index** mp_mskindex752;  slog::Index** mp_msk_ansindex753;  slog::Index** $sup5638x98x0x0x0index754;  slog::Index** mbranchindex755;  slog::Index** mp_mskindex756;  slog::Index** $sup5638x98x0x0x1index757;  slog::Index** mbranchindex758;  slog::Index** mp_mskindex759;  slog::Index** mp_msk_ansindex760;  slog::Index** mp_union_ansindex761;  slog::Index** mp_uniondelta762;  slog::Index** mbranchdelta763;  slog::Index** mp_mskdelta764;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0Tjz1856");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord766({0, 6, 1, 2, 3, 4, 5, 7, 8});
      slog::Relation* readrel767 = db->getRelation("$sup5638x98x0x0x0");
      $sup5638x98x0x0x0index744 = readrel767->getIndex(ord766, false);
      std::vector<u16> ord768({0, 7, 1, 2, 3, 4, 5, 6, 8, 9});
      slog::Relation* readrel769 = db->getRelation("$sup5638x98x0x0x1");
      $sup5638x98x0x0x1index745 = readrel769->getIndex(ord768, false);
      std::vector<u16> ord770({2, 0, 1});
      slog::Relation* readrel771 = db->getRelation("mp_union");
      mp_unionindex746 = readrel771->getIndex(ord770, false);
      std::vector<u16> ord772({2, 0, 1});
      slog::Relation* readrel773 = db->getRelation("mp_union");
      mp_uniondelta762 = readrel773->getIndex(ord772, true);
      std::vector<u16> ord774({0, 6, 1, 2, 3, 4, 5, 7, 8});
      slog::Relation* readrel775 = db->getRelation("$sup5638x98x0x0x0");
      $sup5638x98x0x0x0index747 = readrel775->getIndex(ord774, false);
      std::vector<u16> ord776({0, 7, 1, 2, 3, 4, 5, 6, 8, 9});
      slog::Relation* readrel777 = db->getRelation("$sup5638x98x0x0x1");
      $sup5638x98x0x0x1index748 = readrel777->getIndex(ord776, false);
      std::vector<u16> ord778({0, 1});
      slog::Relation* readrel779 = db->getRelation("mp_union_ans");
      mp_union_ansindex749 = readrel779->getIndex(ord778, false);
      std::vector<u16> ord780({4, 0, 1, 2, 3});
      slog::Relation* readrel781 = db->getRelation("mbranch");
      mbranchindex750 = readrel781->getIndex(ord780, false);
      std::vector<u16> ord782({7, 2, 3, 5, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel783 = db->getRelation("$sup5638x98x0x0x1");
      $sup5638x98x0x0x1index751 = readrel783->getIndex(ord782, false);
      std::vector<u16> ord784({2, 0, 1});
      slog::Relation* readrel785 = db->getRelation("mp_msk");
      mp_mskindex752 = readrel785->getIndex(ord784, false);
      std::vector<u16> ord786({1, 0});
      slog::Relation* readrel787 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex753 = readrel787->getIndex(ord786, false);
      std::vector<u16> ord788({4, 1, 2, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel789 = db->getRelation("$sup5638x98x0x0x0");
      $sup5638x98x0x0x0index754 = readrel789->getIndex(ord788, false);
      std::vector<u16> ord790({1, 2, 3, 4, 0});
      slog::Relation* readrel791 = db->getRelation("mbranch");
      mbranchindex755 = readrel791->getIndex(ord790, false);
      std::vector<u16> ord792({1, 2, 0});
      slog::Relation* readrel793 = db->getRelation("mp_msk");
      mp_mskindex756 = readrel793->getIndex(ord792, false);
      std::vector<u16> ord794({7, 2, 3, 5, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel795 = db->getRelation("$sup5638x98x0x0x1");
      $sup5638x98x0x0x1index757 = readrel795->getIndex(ord794, false);
      std::vector<u16> ord796({1, 2, 3, 4, 0});
      slog::Relation* readrel797 = db->getRelation("mbranch");
      mbranchindex758 = readrel797->getIndex(ord796, false);
      std::vector<u16> ord798({1, 2, 3, 4, 0});
      slog::Relation* readrel799 = db->getRelation("mbranch");
      mbranchdelta763 = readrel799->getIndex(ord798, true);
      std::vector<u16> ord800({1, 2, 0});
      slog::Relation* readrel801 = db->getRelation("mp_msk");
      mp_mskindex759 = readrel801->getIndex(ord800, false);
      std::vector<u16> ord802({1, 2, 0});
      slog::Relation* readrel803 = db->getRelation("mp_msk");
      mp_mskdelta764 = readrel803->getIndex(ord802, true);
      std::vector<u16> ord804({0, 1});
      slog::Relation* readrel805 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex760 = readrel805->getIndex(ord804, false);
      std::vector<u16> ord806({0, 1});
      slog::Relation* readrel807 = db->getRelation("mp_union_ans");
      mp_union_ansindex761 = readrel807->getIndex(ord806, false);
  
    }
    ReadTask765(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c170 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c173 = _t[1];
        u64 v_c174 = _t[2];
        if (!slog::exists_probe<9,1>($sup5638x98x0x0x0index744, std::array<u64,9>{v_c68, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<10,1>($sup5638x98x0x0x1index745, std::array<u64,10>{v_c68, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(mp_unionindex746, mp_uniondelta762, std::array<u64,3>{v_c174, 0, 0}, [&](const std::array<u64,3>& m808) {
          u64 v_c175 = m808[1]; u64 v_c93 = m808[2];
          if (!slog::exists_probe<9,2>($sup5638x98x0x0x0index747, std::array<u64,9>{v_c68, v_c93, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<10,2>($sup5638x98x0x0x1index748, std::array<u64,10>{v_c68, v_c93, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<2,1>(mp_union_ansindex749, std::array<u64,2>{v_c175, 0})) return;
          slog::join_probe<5,2>(mbranchindex750, std::array<u64,5>{v_c93, v_c173, 0, 0, 0}, [&](const std::array<u64,5>& m809) {
            u64 v_c71 = m809[2]; u64 v_c70 = m809[3]; u64 v_c69 = m809[4];
            if (!slog::exists_probe<10,5>($sup5638x98x0x0x1index751, std::array<u64,10>{v_c93, v_c69, v_c70, v_c71, v_c68, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<3,1>(mp_mskindex752, std::array<u64,3>{v_c70, 0, 0})) return;
            if (!slog::exists_probe<2,1>(mp_msk_ansindex753, std::array<u64,2>{v_c71, 0})) return;
            slog::join_probe<9,5>($sup5638x98x0x0x0index754, std::array<u64,9>{v_c71, v_c69, v_c70, v_c93, v_c68, 0, 0, 0, 0}, [&](const std::array<u64,9>& m810) {
              u64 v_c126 = m810[5]; u64 v_c125 = m810[6]; u64 v_c127 = m810[7]; u64 v_c53 = m810[8];
              u64 v_c188 = _prim_lt(db, v_c126, v_c70);
              if (v_c188 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
              if (!v_c188) return;
              if (!slog::exists_probe<5,5>(mbranchindex755, std::array<u64,5>{v_c125, v_c126, v_c127, v_c53, v_c174})) return;
              if (!slog::exists_probe<3,2>(mp_mskindex756, std::array<u64,3>{v_c125, v_c70, 0})) return;
              slog::join_probe<10,9>($sup5638x98x0x0x1index757, std::array<u64,10>{v_c93, v_c69, v_c70, v_c71, v_c68, v_c126, v_c125, v_c127, v_c53, 0}, [&](const std::array<u64,10>& m812) {
                u64 v_c171 = m812[9];
                slog::join_probe_old<5,5>(mbranchindex758, mbranchdelta763, std::array<u64,5>{v_c125, v_c126, v_c127, v_c53, v_c174}, [&](const std::array<u64,5>& m813) {
                  slog::join_probe_old<3,3>(mp_mskindex759, mp_mskdelta764, std::array<u64,3>{v_c125, v_c70, v_c171}, [&](const std::array<u64,3>& m814) {
                    slog::join_probe<2,2>(mp_msk_ansindex760, std::array<u64,2>{v_c171, v_c71}, [&](const std::array<u64,2>& m815) {
                      slog::join_probe<2,1>(mp_union_ansindex761, std::array<u64,2>{v_c175, 0}, [&](const std::array<u64,2>& m816) {
                        u64 v_c47 = m816[1];
                        u64 v_c176 = _prim_band(db, v_c125, v_c70);
                        if (v_c176 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
                        u64 v_c189 = _prim_gt(db, v_c176, v_c170);
                        if (v_c189 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
                        if (!v_c189) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c68, v_c47, v_c69, v_c70, v_c71});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c71, v_c70, v_c69, v_c47}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:99", "delta:mp_union", _fires);
  
      if (!_done)
      {
        ReadTask765* _cont = new ReadTask765(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask765(db,b), false);
  // (crule (pre (let __trid2QGL1273 const90d5df9a2327146dec6b6cee) (let __trel0efT1274 constb642bb32c0b8fd35118770e8) (let __tcol5lpV1275 const5feceb66ffc86f38d952786c) (let __trel5wGq1276 constb642bb32c0b8fd35118770e8) (let __tcol36wm1277 const6b86b273ff34fce19d6b804e)) (scan $sup5638x52x0x0x0 __d0 k l m p r) (body) (head (tycheck r (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid2QGL1273 __trel0efT1274 __tcol5lpV1275 (1 2 3 4 0)) (tycheck k (accept int) __trid2QGL1273 __trel5wGq1276 __tcol36wm1277 (1 2 3 4 0)) (mkstruct mp_get (1 2 0) __3YBs1272 r k)) map.slog:53 #f)
  class ReadTask821 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid819;  u32 sid818;  u32 sid820;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("mp_get");
      outer_rel = db->getRelation("$sup5638x52x0x0x0");
      sid819 = db->getRelation("_enum")->getStructId();
      sid818 = db->getRelation("mbranch")->getStructId();
      sid820 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask821(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c190 = v_const90d5df9a2327146dec6b6cee;
      u64 v_c191 = v_constb642bb32c0b8fd35118770e8;
      u64 v_c192 = v_const5feceb66ffc86f38d952786c;
      u64 v_c193 = v_constb642bb32c0b8fd35118770e8;
      u64 v_c194 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c22 = _t[0];
        u64 v_c44 = _t[1];
        u64 v_c69 = _t[2];
        u64 v_c70 = _t[3];
        u64 v_c71 = _t[4];
        u64 v_c93 = _t[5];
        ++_fires;
        if (!((is_struct(v_c93) && (decode_struct_id(v_c93) == sid818 || decode_struct_id(v_c93) == sid819 || decode_struct_id(v_c93) == sid820))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c190, v_c191, v_c192, v_c93}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c44)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c190, v_c193, v_c194, v_c44}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c93, v_c44}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:53", "delta:$sup5638x52x0x0x0", _fires);
  
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
  // (crule (pre (let __tconst7pEc129 const6b86b273ff34fce19d6b804e)) (scan mp_msk_ans __t40jf135 __v2) (body (join-old mp_msk (0 1 2) 1 (0 1 2) __t40jf135 p0 __v1) (exists $sup5638x25x0x0x2 (5 7 1 0 2 3 4 6 8 9 10) 2 __v1 p0) (exists $sup5638x25x0x0x1 (3 1 0 2 4 5 6) 1 p0) (exists $sup5638x25x0x0x0 (1 0 2 3 4) 1 p0) (exists mp_join (1 2 3 4 0) 1 p0) (join-old mp_hsb_ans (1 0) 1 (1 0) __v1 __t0Ayb132) (exists $sup5638x25x0x0x2 (5 7 1 0 2 3 4 6 8 9 10) 3 __v1 p0 __t0Ayb132) (exists $sup5638x25x0x0x1 (3 1 0 2 4 5 6) 2 p0 __t0Ayb132) (exists mp_hsb_ans (0 1) 1 __t0Ayb132) (join mp_hsb_ans (0 1) 1 __t0Ayb132 __v3) (join $sup5638x25x0x0x2 (1 5 6 7 0 2 3 4 8 9 10) 4 __t0Ayb132 __v1 __v3 p0 __t8CpS128 dup4t6F1978 dup2J5X1979 __v0 p1 t0 t1) (eq __t0Ayb132 dup2J5X1979) (eq __t0Ayb132 dup4t6F1978) (join $sup5638x25x0x0x1 (0 3 4 5 6 1 2) 7 __t8CpS128 p0 p1 t0 t1 __t0Ayb132 __v0) (join $sup5638x25x0x0x0 (1 0 2 3 4) 5 p0 __t8CpS128 p1 t0 t1) (join-old mp_join (1 2 3 4 0) 5 (1 2 3 4 0) p0 t0 p1 t1 __t8CpS128) (join-old mp_hsb_ans (0 1) 2 (0 1) __t0Ayb132 __v0) (let __t867d136 (bxor p0 p1)) (join-old mp_hsb (0 1) 2 (0 1) __t0Ayb132 __t867d136) (let __t8HR0130 (band p0 __v0)) (cmp lt __t8HR0130 __tconst7pEc129)) (head (emit-temp temp0yve1977 __t8CpS128 __v2 __v3 t0 t1) (mkstruct mbranch (1 2 3 4 0) __t3nlL127 __v2 __v3 t0 t1)) map.slog:26 #f)
  class ReadTask843 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_mskindex822;  slog::Index** $sup5638x25x0x0x2index823;  slog::Index** $sup5638x25x0x0x1index824;  slog::Index** $sup5638x25x0x0x0index825;  slog::Index** mp_joinindex826;  slog::Index** mp_hsb_ansindex827;  slog::Index** $sup5638x25x0x0x2index828;  slog::Index** $sup5638x25x0x0x1index829;  slog::Index** mp_hsb_ansindex830;  slog::Index** mp_hsb_ansindex831;  slog::Index** $sup5638x25x0x0x2index832;  slog::Index** $sup5638x25x0x0x1index833;  slog::Index** $sup5638x25x0x0x0index834;  slog::Index** mp_joinindex835;  slog::Index** mp_hsb_ansindex836;  slog::Index** mp_hsbindex837;  slog::Index** mp_mskdelta838;  slog::Index** mp_hsb_ansdelta839;  slog::Index** mp_joindelta840;  slog::Index** mp_hsb_ansdelta841;  slog::Index** mp_hsbdelta842;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0yve1977");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_msk_ans");
      std::vector<u16> ord844({0, 1, 2});
      slog::Relation* readrel845 = db->getRelation("mp_msk");
      mp_mskindex822 = readrel845->getIndex(ord844, false);
      std::vector<u16> ord846({0, 1, 2});
      slog::Relation* readrel847 = db->getRelation("mp_msk");
      mp_mskdelta838 = readrel847->getIndex(ord846, true);
      std::vector<u16> ord848({5, 7, 1, 0, 2, 3, 4, 6, 8, 9, 10});
      slog::Relation* readrel849 = db->getRelation("$sup5638x25x0x0x2");
      $sup5638x25x0x0x2index823 = readrel849->getIndex(ord848, false);
      std::vector<u16> ord850({3, 1, 0, 2, 4, 5, 6});
      slog::Relation* readrel851 = db->getRelation("$sup5638x25x0x0x1");
      $sup5638x25x0x0x1index824 = readrel851->getIndex(ord850, false);
      std::vector<u16> ord852({1, 0, 2, 3, 4});
      slog::Relation* readrel853 = db->getRelation("$sup5638x25x0x0x0");
      $sup5638x25x0x0x0index825 = readrel853->getIndex(ord852, false);
      std::vector<u16> ord854({1, 2, 3, 4, 0});
      slog::Relation* readrel855 = db->getRelation("mp_join");
      mp_joinindex826 = readrel855->getIndex(ord854, false);
      std::vector<u16> ord856({1, 0});
      slog::Relation* readrel857 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex827 = readrel857->getIndex(ord856, false);
      std::vector<u16> ord858({1, 0});
      slog::Relation* readrel859 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta839 = readrel859->getIndex(ord858, true);
      std::vector<u16> ord860({5, 7, 1, 0, 2, 3, 4, 6, 8, 9, 10});
      slog::Relation* readrel861 = db->getRelation("$sup5638x25x0x0x2");
      $sup5638x25x0x0x2index828 = readrel861->getIndex(ord860, false);
      std::vector<u16> ord862({3, 1, 0, 2, 4, 5, 6});
      slog::Relation* readrel863 = db->getRelation("$sup5638x25x0x0x1");
      $sup5638x25x0x0x1index829 = readrel863->getIndex(ord862, false);
      std::vector<u16> ord864({0, 1});
      slog::Relation* readrel865 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex830 = readrel865->getIndex(ord864, false);
      std::vector<u16> ord866({0, 1});
      slog::Relation* readrel867 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex831 = readrel867->getIndex(ord866, false);
      std::vector<u16> ord868({1, 5, 6, 7, 0, 2, 3, 4, 8, 9, 10});
      slog::Relation* readrel869 = db->getRelation("$sup5638x25x0x0x2");
      $sup5638x25x0x0x2index832 = readrel869->getIndex(ord868, false);
      std::vector<u16> ord870({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel871 = db->getRelation("$sup5638x25x0x0x1");
      $sup5638x25x0x0x1index833 = readrel871->getIndex(ord870, false);
      std::vector<u16> ord872({1, 0, 2, 3, 4});
      slog::Relation* readrel873 = db->getRelation("$sup5638x25x0x0x0");
      $sup5638x25x0x0x0index834 = readrel873->getIndex(ord872, false);
      std::vector<u16> ord874({1, 2, 3, 4, 0});
      slog::Relation* readrel875 = db->getRelation("mp_join");
      mp_joinindex835 = readrel875->getIndex(ord874, false);
      std::vector<u16> ord876({1, 2, 3, 4, 0});
      slog::Relation* readrel877 = db->getRelation("mp_join");
      mp_joindelta840 = readrel877->getIndex(ord876, true);
      std::vector<u16> ord878({0, 1});
      slog::Relation* readrel879 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex836 = readrel879->getIndex(ord878, false);
      std::vector<u16> ord880({0, 1});
      slog::Relation* readrel881 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta841 = readrel881->getIndex(ord880, true);
      std::vector<u16> ord882({0, 1});
      slog::Relation* readrel883 = db->getRelation("mp_hsb");
      mp_hsbindex837 = readrel883->getIndex(ord882, false);
      std::vector<u16> ord884({0, 1});
      slog::Relation* readrel885 = db->getRelation("mp_hsb");
      mp_hsbdelta842 = readrel885->getIndex(ord884, true);
  
    }
    ReadTask843(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c195 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c196 = _t[0];
        u64 v_c169 = _t[1];
        slog::join_probe_old<3,1>(mp_mskindex822, mp_mskdelta838, std::array<u64,3>{v_c196, 0, 0}, [&](const std::array<u64,3>& m886) {
          u64 v_c197 = m886[1]; u64 v_c168 = m886[2];
          if (!slog::exists_probe<11,2>($sup5638x25x0x0x2index823, std::array<u64,11>{v_c168, v_c197, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<7,1>($sup5638x25x0x0x1index824, std::array<u64,7>{v_c197, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>($sup5638x25x0x0x0index825, std::array<u64,5>{v_c197, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>(mp_joinindex826, std::array<u64,5>{v_c197, 0, 0, 0, 0})) return;
          slog::join_probe_old<2,1>(mp_hsb_ansindex827, mp_hsb_ansdelta839, std::array<u64,2>{v_c168, 0}, [&](const std::array<u64,2>& m887) {
            u64 v_c198 = m887[1];
            if (!slog::exists_probe<11,3>($sup5638x25x0x0x2index828, std::array<u64,11>{v_c168, v_c197, v_c198, 0, 0, 0, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<7,2>($sup5638x25x0x0x1index829, std::array<u64,7>{v_c197, v_c198, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<2,1>(mp_hsb_ansindex830, std::array<u64,2>{v_c198, 0})) return;
            slog::join_probe<2,1>(mp_hsb_ansindex831, std::array<u64,2>{v_c198, 0}, [&](const std::array<u64,2>& m888) {
              u64 v_c199 = m888[1];
              slog::join_probe<11,4>($sup5638x25x0x0x2index832, std::array<u64,11>{v_c198, v_c168, v_c199, v_c197, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m889) {
                u64 v_c200 = m889[4]; u64 v_c201 = m889[5]; u64 v_c202 = m889[6]; u64 v_c47 = m889[7]; u64 v_c203 = m889[8]; u64 v_c204 = m889[9]; u64 v_c205 = m889[10];
                if (v_c198 != v_c202) return;
                if (v_c198 != v_c201) return;
                slog::join_probe<7,7>($sup5638x25x0x0x1index833, std::array<u64,7>{v_c200, v_c197, v_c203, v_c204, v_c205, v_c198, v_c47}, [&](const std::array<u64,7>& m890) {
                  slog::join_probe<5,5>($sup5638x25x0x0x0index834, std::array<u64,5>{v_c197, v_c200, v_c203, v_c204, v_c205}, [&](const std::array<u64,5>& m891) {
                    slog::join_probe_old<5,5>(mp_joinindex835, mp_joindelta840, std::array<u64,5>{v_c197, v_c204, v_c203, v_c205, v_c200}, [&](const std::array<u64,5>& m892) {
                      slog::join_probe_old<2,2>(mp_hsb_ansindex836, mp_hsb_ansdelta841, std::array<u64,2>{v_c198, v_c47}, [&](const std::array<u64,2>& m893) {
                        u64 v_c206 = _prim_bxor(db, v_c197, v_c203);
                        if (v_c206 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                        slog::join_probe_old<2,2>(mp_hsbindex837, mp_hsbdelta842, std::array<u64,2>{v_c198, v_c206}, [&](const std::array<u64,2>& m894) {
                          u64 v_c207 = _prim_band(db, v_c197, v_c47);
                          if (v_c207 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                          u64 v_c208 = _prim_lt(db, v_c207, v_c195);
                          if (v_c208 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                          if (!v_c208) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c200, v_c169, v_c199, v_c204, v_c205});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c169, v_c199, v_c204, v_c205}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:26", "delta:mp_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask843* _cont = new ReadTask843(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask843(db,b), false);
  // (crule (pre (let __t0SOq399 (lempty))) (scan lst_take_ans __t4nP5402 __v0) (body (join-old lst_take (0 1 2) 1 (0 1 2) __t4nP5402 __t3PGq401 k) (join klimit (0) 1 k) (join-old tick (0 2 1) 0 (0 2 1) __t7qQQ398 t site) (let __t7jWC400 (lpush __t0SOq399 site)) (let chk7WSg1917 (lcat __t7jWC400 t)) (eq __t3PGq401 chk7WSg1917)) (head (emit tick_ans (0 1) __t7qQQ398 __v0)) context.slog:11 #f)
  class ReadTask901 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lst_takeindex896;  slog::Index** klimitindex897;  slog::Index** tickindex898;  slog::Index** lst_takedelta899;  slog::Index** tickdelta900;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("tick_ans");
      std::vector<u16> ord902({0, 1});
      slog::Relation* readrel903 = db->getRelation("tick_ans");
      head_index[0] = readrel903->getIndex(ord902, false);
      outer_rel = db->getRelation("lst_take_ans");
      std::vector<u16> ord904({0, 1, 2});
      slog::Relation* readrel905 = db->getRelation("lst_take");
      lst_takeindex896 = readrel905->getIndex(ord904, false);
      std::vector<u16> ord906({0, 1, 2});
      slog::Relation* readrel907 = db->getRelation("lst_take");
      lst_takedelta899 = readrel907->getIndex(ord906, true);
      std::vector<u16> ord908({0});
      slog::Relation* readrel909 = db->getRelation("klimit");
      klimitindex897 = readrel909->getIndex(ord908, false);
      std::vector<u16> ord910({0, 2, 1});
      slog::Relation* readrel911 = db->getRelation("tick");
      tickindex898 = readrel911->getIndex(ord910, false);
      std::vector<u16> ord912({0, 2, 1});
      slog::Relation* readrel913 = db->getRelation("tick");
      tickdelta900 = readrel913->getIndex(ord912, true);
  
    }
    ReadTask901(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c209 = _prim_lempty(db);
      if (v_c209 == slog_error) { slog::emit_pending_error(db, "context.slog:11"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c210 = _t[0];
        u64 v_c47 = _t[1];
        slog::join_probe_old<3,1>(lst_takeindex896, lst_takedelta899, std::array<u64,3>{v_c210, 0, 0}, [&](const std::array<u64,3>& m914) {
          u64 v_c211 = m914[1]; u64 v_c44 = m914[2];
          slog::join_probe<1,1>(klimitindex897, std::array<u64,1>{v_c44}, [&](const std::array<u64,1>& m915) {
            slog::join_all_old<3>(tickindex898, tickdelta900, [&](const std::array<u64,3>& m916) {
              u64 v_c212 = m916[0]; u64 v_c28 = m916[1]; u64 v_c213 = m916[2];
              u64 v_c214 = _prim_lpush(db, v_c209, v_c213);
              if (v_c214 == slog_error) { slog::emit_pending_error(db, "context.slog:11"); return; }
              u64 v_c215 = _prim_lcat(db, v_c214, v_c28);
              if (v_c215 == slog_error) { slog::emit_pending_error(db, "context.slog:11"); return; }
              if (v_c211 != v_c215) return;
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c212, v_c47}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("context.slog:11", "delta:lst_take_ans", _fires);
  
      if (!_done)
      {
        ReadTask901* _cont = new ReadTask901(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask901(db,b), false);
  // (crule (pre (let __tconst2b6r460 const5feceb66ffc86f38d952786c)) (scan mp_put __t6Bbs459 __t9ixF458 k v) (body (exists $sup5638x42x0x0x1 (0 2 7 1 3 4 5 6) 3 __t6Bbs459 k v) (exists mp_msk (1 2 0) 1 k) (exists mp_put (2 3 0 1) 2 k v) (join $sup5638x42x0x0x0 (0 1 6 2 3 4 5) 3 __t6Bbs459 k v l m p r) (exists mbranch (1 2 3 4 0) 5 p m l r __t9ixF458) (exists mp_msk (1 2 0) 2 k m) (exists mp_put (1 2 3 0) 3 r k v) (exists mp_msk_ans (1 0) 1 p) (join $sup5638x42x0x0x1 (3 4 5 6 0 2 7 1) 7 l m p r __t6Bbs459 k v __t5aM3462) (join mbranch (1 2 3 4 0) 5 p m l r __t9ixF458) (join-old mp_msk (1 2 0) 3 (1 2 0) k m __t5aM3462) (exists mp_msk_ans (0 1) 2 __t5aM3462 p) (join-old mp_put (1 2 3 0) 3 (1 2 3 0) r k v __t9vSj463) (join mp_msk_ans (0 1) 2 __t5aM3462 p) (join mp_put_ans (0 1) 1 __t9vSj463 __v0) (let __t1jZ6461 (band k m)) (cmp gt __t1jZ6461 __tconst2b6r460)) (head (emit-temp temp7Xjy1975 __t6Bbs459 __v0 l m p) (mkstruct mbranch (1 2 3 4 0) __t8oL5457 p m l __v0)) map.slog:43 #f)
  class ReadTask934 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x42x0x0x1index917;  slog::Index** mp_mskindex918;  slog::Index** mp_putindex919;  slog::Index** $sup5638x42x0x0x0index920;  slog::Index** mbranchindex921;  slog::Index** mp_mskindex922;  slog::Index** mp_putindex923;  slog::Index** mp_msk_ansindex924;  slog::Index** $sup5638x42x0x0x1index925;  slog::Index** mbranchindex926;  slog::Index** mp_mskindex927;  slog::Index** mp_msk_ansindex928;  slog::Index** mp_putindex929;  slog::Index** mp_msk_ansindex930;  slog::Index** mp_put_ansindex931;  slog::Index** mp_mskdelta932;  slog::Index** mp_putdelta933;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7Xjy1975");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_put");
      std::vector<u16> ord935({0, 2, 7, 1, 3, 4, 5, 6});
      slog::Relation* readrel936 = db->getRelation("$sup5638x42x0x0x1");
      $sup5638x42x0x0x1index917 = readrel936->getIndex(ord935, false);
      std::vector<u16> ord937({1, 2, 0});
      slog::Relation* readrel938 = db->getRelation("mp_msk");
      mp_mskindex918 = readrel938->getIndex(ord937, false);
      std::vector<u16> ord939({2, 3, 0, 1});
      slog::Relation* readrel940 = db->getRelation("mp_put");
      mp_putindex919 = readrel940->getIndex(ord939, false);
      std::vector<u16> ord941({0, 1, 6, 2, 3, 4, 5});
      slog::Relation* readrel942 = db->getRelation("$sup5638x42x0x0x0");
      $sup5638x42x0x0x0index920 = readrel942->getIndex(ord941, false);
      std::vector<u16> ord943({1, 2, 3, 4, 0});
      slog::Relation* readrel944 = db->getRelation("mbranch");
      mbranchindex921 = readrel944->getIndex(ord943, false);
      std::vector<u16> ord945({1, 2, 0});
      slog::Relation* readrel946 = db->getRelation("mp_msk");
      mp_mskindex922 = readrel946->getIndex(ord945, false);
      std::vector<u16> ord947({1, 2, 3, 0});
      slog::Relation* readrel948 = db->getRelation("mp_put");
      mp_putindex923 = readrel948->getIndex(ord947, false);
      std::vector<u16> ord949({1, 0});
      slog::Relation* readrel950 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex924 = readrel950->getIndex(ord949, false);
      std::vector<u16> ord951({3, 4, 5, 6, 0, 2, 7, 1});
      slog::Relation* readrel952 = db->getRelation("$sup5638x42x0x0x1");
      $sup5638x42x0x0x1index925 = readrel952->getIndex(ord951, false);
      std::vector<u16> ord953({1, 2, 3, 4, 0});
      slog::Relation* readrel954 = db->getRelation("mbranch");
      mbranchindex926 = readrel954->getIndex(ord953, false);
      std::vector<u16> ord955({1, 2, 0});
      slog::Relation* readrel956 = db->getRelation("mp_msk");
      mp_mskindex927 = readrel956->getIndex(ord955, false);
      std::vector<u16> ord957({1, 2, 0});
      slog::Relation* readrel958 = db->getRelation("mp_msk");
      mp_mskdelta932 = readrel958->getIndex(ord957, true);
      std::vector<u16> ord959({0, 1});
      slog::Relation* readrel960 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex928 = readrel960->getIndex(ord959, false);
      std::vector<u16> ord961({1, 2, 3, 0});
      slog::Relation* readrel962 = db->getRelation("mp_put");
      mp_putindex929 = readrel962->getIndex(ord961, false);
      std::vector<u16> ord963({1, 2, 3, 0});
      slog::Relation* readrel964 = db->getRelation("mp_put");
      mp_putdelta933 = readrel964->getIndex(ord963, true);
      std::vector<u16> ord965({0, 1});
      slog::Relation* readrel966 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex930 = readrel966->getIndex(ord965, false);
      std::vector<u16> ord967({0, 1});
      slog::Relation* readrel968 = db->getRelation("mp_put_ans");
      mp_put_ansindex931 = readrel968->getIndex(ord967, false);
  
    }
    ReadTask934(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c216 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c217 = _t[0];
        u64 v_c218 = _t[1];
        u64 v_c44 = _t[2];
        u64 v_c53 = _t[3];
        if (!slog::exists_probe<8,3>($sup5638x42x0x0x1index917, std::array<u64,8>{v_c217, v_c44, v_c53, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex918, std::array<u64,3>{v_c44, 0, 0})) return;
        if (!slog::exists_probe<4,2>(mp_putindex919, std::array<u64,4>{v_c44, v_c53, 0, 0})) return;
        slog::join_probe<7,3>($sup5638x42x0x0x0index920, std::array<u64,7>{v_c217, v_c44, v_c53, 0, 0, 0, 0}, [&](const std::array<u64,7>& m969) {
          u64 v_c69 = m969[3]; u64 v_c70 = m969[4]; u64 v_c71 = m969[5]; u64 v_c93 = m969[6];
          if (!slog::exists_probe<5,5>(mbranchindex921, std::array<u64,5>{v_c71, v_c70, v_c69, v_c93, v_c218})) return;
          if (!slog::exists_probe<3,2>(mp_mskindex922, std::array<u64,3>{v_c44, v_c70, 0})) return;
          if (!slog::exists_probe<4,3>(mp_putindex923, std::array<u64,4>{v_c93, v_c44, v_c53, 0})) return;
          if (!slog::exists_probe<2,1>(mp_msk_ansindex924, std::array<u64,2>{v_c71, 0})) return;
          slog::join_probe<8,7>($sup5638x42x0x0x1index925, std::array<u64,8>{v_c69, v_c70, v_c71, v_c93, v_c217, v_c44, v_c53, 0}, [&](const std::array<u64,8>& m970) {
            u64 v_c219 = m970[7];
            slog::join_probe<5,5>(mbranchindex926, std::array<u64,5>{v_c71, v_c70, v_c69, v_c93, v_c218}, [&](const std::array<u64,5>& m971) {
              slog::join_probe_old<3,3>(mp_mskindex927, mp_mskdelta932, std::array<u64,3>{v_c44, v_c70, v_c219}, [&](const std::array<u64,3>& m972) {
                if (!slog::exists_probe<2,2>(mp_msk_ansindex928, std::array<u64,2>{v_c219, v_c71})) return;
                slog::join_probe_old<4,3>(mp_putindex929, mp_putdelta933, std::array<u64,4>{v_c93, v_c44, v_c53, 0}, [&](const std::array<u64,4>& m973) {
                  u64 v_c220 = m973[3];
                  slog::join_probe<2,2>(mp_msk_ansindex930, std::array<u64,2>{v_c219, v_c71}, [&](const std::array<u64,2>& m974) {
                    slog::join_probe<2,1>(mp_put_ansindex931, std::array<u64,2>{v_c220, 0}, [&](const std::array<u64,2>& m975) {
                      u64 v_c47 = m975[1];
                      u64 v_c221 = _prim_band(db, v_c44, v_c70);
                      if (v_c221 == slog_error) { slog::emit_pending_error(db, "map.slog:43"); return; }
                      u64 v_c222 = _prim_gt(db, v_c221, v_c216);
                      if (v_c222 == slog_error) { slog::emit_pending_error(db, "map.slog:43"); return; }
                      if (!v_c222) return;
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c217, v_c47, v_c69, v_c70, v_c71});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c71, v_c70, v_c69, v_c47}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:43", "delta:mp_put", _fires);
  
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
  // (crule (pre) (scan mp_hsb_ans __t15yE714 __v1) (body (join mp_hsb_ans (0 1) 1 __t15yE714 __v3) (join-old mp_hsb (0 1) 1 (0 1) __t15yE714 __t4JMu715) (join-old $sup5638x25x0x0x1 (1 2 0 3 4 5 6) 0 (1 2 0 3 4 5 6) __d1 __v0 __d0 p0 p1 t0 t1) (let chk6WnJ1941 (bxor p0 p1)) (eq __t4JMu715 chk6WnJ1941)) (head (emit $sup5638x25x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) __d1 __v0 __v3 __v1 __d0 __t15yE714 __t15yE714 p0 p1 t0 t1)) map.slog:26 #f)
  class ReadTask982 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_hsb_ansindex977;  slog::Index** mp_hsbindex978;  slog::Index** $sup5638x25x0x0x1index979;  slog::Index** mp_hsbdelta980;  slog::Index** $sup5638x25x0x0x1delta981;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x25x0x0x2");
      std::vector<u16> ord983({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel984 = db->getRelation("$sup5638x25x0x0x2");
      head_index[0] = readrel984->getIndex(ord983, false);
      outer_rel = db->getRelation("mp_hsb_ans");
      std::vector<u16> ord985({0, 1});
      slog::Relation* readrel986 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex977 = readrel986->getIndex(ord985, false);
      std::vector<u16> ord987({0, 1});
      slog::Relation* readrel988 = db->getRelation("mp_hsb");
      mp_hsbindex978 = readrel988->getIndex(ord987, false);
      std::vector<u16> ord989({0, 1});
      slog::Relation* readrel990 = db->getRelation("mp_hsb");
      mp_hsbdelta980 = readrel990->getIndex(ord989, true);
      std::vector<u16> ord991({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel992 = db->getRelation("$sup5638x25x0x0x1");
      $sup5638x25x0x0x1index979 = readrel992->getIndex(ord991, false);
      std::vector<u16> ord993({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel994 = db->getRelation("$sup5638x25x0x0x1");
      $sup5638x25x0x0x1delta981 = readrel994->getIndex(ord993, true);
  
    }
    ReadTask982(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c223 = _t[0];
        u64 v_c168 = _t[1];
        slog::join_probe<2,1>(mp_hsb_ansindex977, std::array<u64,2>{v_c223, 0}, [&](const std::array<u64,2>& m995) {
          u64 v_c199 = m995[1];
          slog::join_probe_old<2,1>(mp_hsbindex978, mp_hsbdelta980, std::array<u64,2>{v_c223, 0}, [&](const std::array<u64,2>& m996) {
            u64 v_c224 = m996[1];
            slog::join_all_old<7>($sup5638x25x0x0x1index979, $sup5638x25x0x0x1delta981, [&](const std::array<u64,7>& m997) {
              u64 v_c225 = m997[0]; u64 v_c47 = m997[1]; u64 v_c22 = m997[2]; u64 v_c197 = m997[3]; u64 v_c203 = m997[4]; u64 v_c204 = m997[5]; u64 v_c205 = m997[6];
              u64 v_c226 = _prim_bxor(db, v_c197, v_c203);
              if (v_c226 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
              if (v_c224 != v_c226) return;
              ++_fires;
              slog::emit<11>(head_rel[0], head_index[0], newbatch[0], std::array<u64,11>{v_c225, v_c47, v_c199, v_c168, v_c22, v_c223, v_c223, v_c197, v_c203, v_c204, v_c205}, std::array<u16,11>{1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:26", "delta:mp_hsb_ans", _fires);
  
      if (!_done)
      {
        ReadTask982* _cont = new ReadTask982(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask982(db,b), false);
  // (crule (pre) (scan eval_args __t2srV536 es rho t) (body (exists $sup70016x51x0x0x1 (2 6 7 9 11 0 1 3 4 5 8 10 12) 4 __t2srV536 es rho t) (exists eval (2 3 0 1) 2 rho t) (exists app (2 0 1) 1 es) (exists tick (2 0 1) 1 t) (exists eval_args_ans (0 1) 1 __t2srV536) (join $sup70016x51x0x0x0 (2 3 4 0 1) 3 es rho t __t2z6s532 ef) (exists eval (1 2 3 0) 3 ef rho t) (exists eval (2 3 0 1) 3 rho t __t2z6s532) (exists app (1 2 0) 2 ef es) (join $sup70016x51x0x0x1 (0 2 5 6 7 9 11 1 3 4 8 10 12) 6 __t2z6s532 __t2srV536 ef es rho t vs __t5qy8533 __t0CD9539 eb rhoc t2 xs) (join eval (2 3 0 1) 4 rho t __t5qy8533 ef) (exists tick (0 2 1) 2 __t0CD9539 t) (exists extend_env (1 2 3 0) 3 rhoc xs t2) (exists eval_args_ans (0 1) 2 __t2srV536 vs) (exists tick_ans (0 1) 2 __t0CD9539 t2) (exists lambda (1 2 0) 2 xs eb) (exists closure (2 0 1) 1 rhoc) (exists eval_ans (0 1) 1 __t5qy8533) (exists eval (3 1 0 2) 2 t2 eb) (join eval (2 3 0 1) 3 rho t __t2z6s532 __t5a7h538) (join-old app (0 1 2) 3 (0 1 2) __t5a7h538 ef es) (join-old tick (0 2 1) 3 (0 2 1) __t0CD9539 t __t5a7h538) (join-old extend_env (1 2 3 0) 3 (1 2 3 0) rhoc xs t2 __t5fzh540) (join eval_args_ans (0 1) 2 __t2srV536 vs) (join tick_ans (0 1) 2 __t0CD9539 t2) (exists extend_env_ans (0 1) 1 __t5fzh540) (join lambda (1 2 0) 2 xs eb __t6iPm534) (join closure (1 2 0) 2 __t6iPm534 rhoc __t9dfl535) (join eval_ans (0 1) 2 __t5qy8533 __t9dfl535) (join-old eval (3 1 0 2) 2 (3 1 0 2) t2 eb __t7TaT537 __v0) (join extend_env_ans (0 1) 2 __t5fzh540 __v0) (join eval_ans (0 1) 1 __t7TaT537 v)) (head (emit eval_ans (0 1) __t2z6s532 v)) interp.slog:52 #f)
  class ReadTask1034 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup70016x51x0x0x1index998;  slog::Index** evalindex999;  slog::Index** appindex1000;  slog::Index** tickindex1001;  slog::Index** eval_args_ansindex1002;  slog::Index** $sup70016x51x0x0x0index1003;  slog::Index** evalindex1004;  slog::Index** evalindex1005;  slog::Index** appindex1006;  slog::Index** $sup70016x51x0x0x1index1007;  slog::Index** evalindex1008;  slog::Index** tickindex1009;  slog::Index** extend_envindex1010;  slog::Index** eval_args_ansindex1011;  slog::Index** tick_ansindex1012;  slog::Index** lambdaindex1013;  slog::Index** closureindex1014;  slog::Index** eval_ansindex1015;  slog::Index** evalindex1016;  slog::Index** evalindex1017;  slog::Index** appindex1018;  slog::Index** tickindex1019;  slog::Index** extend_envindex1020;  slog::Index** eval_args_ansindex1021;  slog::Index** tick_ansindex1022;  slog::Index** extend_env_ansindex1023;  slog::Index** lambdaindex1024;  slog::Index** closureindex1025;  slog::Index** eval_ansindex1026;  slog::Index** evalindex1027;  slog::Index** extend_env_ansindex1028;  slog::Index** eval_ansindex1029;  slog::Index** appdelta1030;  slog::Index** tickdelta1031;  slog::Index** extend_envdelta1032;  slog::Index** evaldelta1033;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1035({0, 1});
      slog::Relation* readrel1036 = db->getRelation("eval_ans");
      head_index[0] = readrel1036->getIndex(ord1035, false);
      outer_rel = db->getRelation("eval_args");
      std::vector<u16> ord1037({2, 6, 7, 9, 11, 0, 1, 3, 4, 5, 8, 10, 12});
      slog::Relation* readrel1038 = db->getRelation("$sup70016x51x0x0x1");
      $sup70016x51x0x0x1index998 = readrel1038->getIndex(ord1037, false);
      std::vector<u16> ord1039({2, 3, 0, 1});
      slog::Relation* readrel1040 = db->getRelation("eval");
      evalindex999 = readrel1040->getIndex(ord1039, false);
      std::vector<u16> ord1041({2, 0, 1});
      slog::Relation* readrel1042 = db->getRelation("app");
      appindex1000 = readrel1042->getIndex(ord1041, false);
      std::vector<u16> ord1043({2, 0, 1});
      slog::Relation* readrel1044 = db->getRelation("tick");
      tickindex1001 = readrel1044->getIndex(ord1043, false);
      std::vector<u16> ord1045({0, 1});
      slog::Relation* readrel1046 = db->getRelation("eval_args_ans");
      eval_args_ansindex1002 = readrel1046->getIndex(ord1045, false);
      std::vector<u16> ord1047({2, 3, 4, 0, 1});
      slog::Relation* readrel1048 = db->getRelation("$sup70016x51x0x0x0");
      $sup70016x51x0x0x0index1003 = readrel1048->getIndex(ord1047, false);
      std::vector<u16> ord1049({1, 2, 3, 0});
      slog::Relation* readrel1050 = db->getRelation("eval");
      evalindex1004 = readrel1050->getIndex(ord1049, false);
      std::vector<u16> ord1051({2, 3, 0, 1});
      slog::Relation* readrel1052 = db->getRelation("eval");
      evalindex1005 = readrel1052->getIndex(ord1051, false);
      std::vector<u16> ord1053({1, 2, 0});
      slog::Relation* readrel1054 = db->getRelation("app");
      appindex1006 = readrel1054->getIndex(ord1053, false);
      std::vector<u16> ord1055({0, 2, 5, 6, 7, 9, 11, 1, 3, 4, 8, 10, 12});
      slog::Relation* readrel1056 = db->getRelation("$sup70016x51x0x0x1");
      $sup70016x51x0x0x1index1007 = readrel1056->getIndex(ord1055, false);
      std::vector<u16> ord1057({2, 3, 0, 1});
      slog::Relation* readrel1058 = db->getRelation("eval");
      evalindex1008 = readrel1058->getIndex(ord1057, false);
      std::vector<u16> ord1059({0, 2, 1});
      slog::Relation* readrel1060 = db->getRelation("tick");
      tickindex1009 = readrel1060->getIndex(ord1059, false);
      std::vector<u16> ord1061({1, 2, 3, 0});
      slog::Relation* readrel1062 = db->getRelation("extend_env");
      extend_envindex1010 = readrel1062->getIndex(ord1061, false);
      std::vector<u16> ord1063({0, 1});
      slog::Relation* readrel1064 = db->getRelation("eval_args_ans");
      eval_args_ansindex1011 = readrel1064->getIndex(ord1063, false);
      std::vector<u16> ord1065({0, 1});
      slog::Relation* readrel1066 = db->getRelation("tick_ans");
      tick_ansindex1012 = readrel1066->getIndex(ord1065, false);
      std::vector<u16> ord1067({1, 2, 0});
      slog::Relation* readrel1068 = db->getRelation("lambda");
      lambdaindex1013 = readrel1068->getIndex(ord1067, false);
      std::vector<u16> ord1069({2, 0, 1});
      slog::Relation* readrel1070 = db->getRelation("closure");
      closureindex1014 = readrel1070->getIndex(ord1069, false);
      std::vector<u16> ord1071({0, 1});
      slog::Relation* readrel1072 = db->getRelation("eval_ans");
      eval_ansindex1015 = readrel1072->getIndex(ord1071, false);
      std::vector<u16> ord1073({3, 1, 0, 2});
      slog::Relation* readrel1074 = db->getRelation("eval");
      evalindex1016 = readrel1074->getIndex(ord1073, false);
      std::vector<u16> ord1075({2, 3, 0, 1});
      slog::Relation* readrel1076 = db->getRelation("eval");
      evalindex1017 = readrel1076->getIndex(ord1075, false);
      std::vector<u16> ord1077({0, 1, 2});
      slog::Relation* readrel1078 = db->getRelation("app");
      appindex1018 = readrel1078->getIndex(ord1077, false);
      std::vector<u16> ord1079({0, 1, 2});
      slog::Relation* readrel1080 = db->getRelation("app");
      appdelta1030 = readrel1080->getIndex(ord1079, true);
      std::vector<u16> ord1081({0, 2, 1});
      slog::Relation* readrel1082 = db->getRelation("tick");
      tickindex1019 = readrel1082->getIndex(ord1081, false);
      std::vector<u16> ord1083({0, 2, 1});
      slog::Relation* readrel1084 = db->getRelation("tick");
      tickdelta1031 = readrel1084->getIndex(ord1083, true);
      std::vector<u16> ord1085({1, 2, 3, 0});
      slog::Relation* readrel1086 = db->getRelation("extend_env");
      extend_envindex1020 = readrel1086->getIndex(ord1085, false);
      std::vector<u16> ord1087({1, 2, 3, 0});
      slog::Relation* readrel1088 = db->getRelation("extend_env");
      extend_envdelta1032 = readrel1088->getIndex(ord1087, true);
      std::vector<u16> ord1089({0, 1});
      slog::Relation* readrel1090 = db->getRelation("eval_args_ans");
      eval_args_ansindex1021 = readrel1090->getIndex(ord1089, false);
      std::vector<u16> ord1091({0, 1});
      slog::Relation* readrel1092 = db->getRelation("tick_ans");
      tick_ansindex1022 = readrel1092->getIndex(ord1091, false);
      std::vector<u16> ord1093({0, 1});
      slog::Relation* readrel1094 = db->getRelation("extend_env_ans");
      extend_env_ansindex1023 = readrel1094->getIndex(ord1093, false);
      std::vector<u16> ord1095({1, 2, 0});
      slog::Relation* readrel1096 = db->getRelation("lambda");
      lambdaindex1024 = readrel1096->getIndex(ord1095, false);
      std::vector<u16> ord1097({1, 2, 0});
      slog::Relation* readrel1098 = db->getRelation("closure");
      closureindex1025 = readrel1098->getIndex(ord1097, false);
      std::vector<u16> ord1099({0, 1});
      slog::Relation* readrel1100 = db->getRelation("eval_ans");
      eval_ansindex1026 = readrel1100->getIndex(ord1099, false);
      std::vector<u16> ord1101({3, 1, 0, 2});
      slog::Relation* readrel1102 = db->getRelation("eval");
      evalindex1027 = readrel1102->getIndex(ord1101, false);
      std::vector<u16> ord1103({3, 1, 0, 2});
      slog::Relation* readrel1104 = db->getRelation("eval");
      evaldelta1033 = readrel1104->getIndex(ord1103, true);
      std::vector<u16> ord1105({0, 1});
      slog::Relation* readrel1106 = db->getRelation("extend_env_ans");
      extend_env_ansindex1028 = readrel1106->getIndex(ord1105, false);
      std::vector<u16> ord1107({0, 1});
      slog::Relation* readrel1108 = db->getRelation("eval_ans");
      eval_ansindex1029 = readrel1108->getIndex(ord1107, false);
  
    }
    ReadTask1034(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c41 = _t[1];
        u64 v_c26 = _t[2];
        u64 v_c28 = _t[3];
        if (!slog::exists_probe<13,4>($sup70016x51x0x0x1index998, std::array<u64,13>{v_c58, v_c41, v_c26, v_c28, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<4,2>(evalindex999, std::array<u64,4>{v_c26, v_c28, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex1000, std::array<u64,3>{v_c41, 0, 0})) return;
        if (!slog::exists_probe<3,1>(tickindex1001, std::array<u64,3>{v_c28, 0, 0})) return;
        if (!slog::exists_probe<2,1>(eval_args_ansindex1002, std::array<u64,2>{v_c58, 0})) return;
        slog::join_probe<5,3>($sup70016x51x0x0x0index1003, std::array<u64,5>{v_c41, v_c26, v_c28, 0, 0}, [&](const std::array<u64,5>& m1109) {
          u64 v_c56 = m1109[3]; u64 v_c55 = m1109[4];
          if (!slog::exists_probe<4,3>(evalindex1004, std::array<u64,4>{v_c55, v_c26, v_c28, 0})) return;
          if (!slog::exists_probe<4,3>(evalindex1005, std::array<u64,4>{v_c26, v_c28, v_c56, 0})) return;
          if (!slog::exists_probe<3,2>(appindex1006, std::array<u64,3>{v_c55, v_c41, 0})) return;
          slog::join_probe<13,6>($sup70016x51x0x0x1index1007, std::array<u64,13>{v_c56, v_c58, v_c55, v_c41, v_c26, v_c28, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,13>& m1110) {
            u64 v_c62 = m1110[6]; u64 v_c57 = m1110[7]; u64 v_c59 = m1110[8]; u64 v_c24 = m1110[9]; u64 v_c60 = m1110[10]; u64 v_c61 = m1110[11]; u64 v_c63 = m1110[12];
            slog::join_probe<4,4>(evalindex1008, std::array<u64,4>{v_c26, v_c28, v_c57, v_c55}, [&](const std::array<u64,4>& m1111) {
              if (!slog::exists_probe<3,2>(tickindex1009, std::array<u64,3>{v_c59, v_c28, 0})) return;
              if (!slog::exists_probe<4,3>(extend_envindex1010, std::array<u64,4>{v_c60, v_c63, v_c61, 0})) return;
              if (!slog::exists_probe<2,2>(eval_args_ansindex1011, std::array<u64,2>{v_c58, v_c62})) return;
              if (!slog::exists_probe<2,2>(tick_ansindex1012, std::array<u64,2>{v_c59, v_c61})) return;
              if (!slog::exists_probe<3,2>(lambdaindex1013, std::array<u64,3>{v_c63, v_c24, 0})) return;
              if (!slog::exists_probe<3,1>(closureindex1014, std::array<u64,3>{v_c60, 0, 0})) return;
              if (!slog::exists_probe<2,1>(eval_ansindex1015, std::array<u64,2>{v_c57, 0})) return;
              if (!slog::exists_probe<4,2>(evalindex1016, std::array<u64,4>{v_c61, v_c24, 0, 0})) return;
              slog::join_probe<4,3>(evalindex1017, std::array<u64,4>{v_c26, v_c28, v_c56, 0}, [&](const std::array<u64,4>& m1112) {
                u64 v_c54 = m1112[3];
                slog::join_probe_old<3,3>(appindex1018, appdelta1030, std::array<u64,3>{v_c54, v_c55, v_c41}, [&](const std::array<u64,3>& m1113) {
                  slog::join_probe_old<3,3>(tickindex1019, tickdelta1031, std::array<u64,3>{v_c59, v_c28, v_c54}, [&](const std::array<u64,3>& m1114) {
                    slog::join_probe_old<4,3>(extend_envindex1020, extend_envdelta1032, std::array<u64,4>{v_c60, v_c63, v_c61, 0}, [&](const std::array<u64,4>& m1115) {
                      u64 v_c64 = m1115[3];
                      slog::join_probe<2,2>(eval_args_ansindex1021, std::array<u64,2>{v_c58, v_c62}, [&](const std::array<u64,2>& m1116) {
                        slog::join_probe<2,2>(tick_ansindex1022, std::array<u64,2>{v_c59, v_c61}, [&](const std::array<u64,2>& m1117) {
                          if (!slog::exists_probe<2,1>(extend_env_ansindex1023, std::array<u64,2>{v_c64, 0})) return;
                          slog::join_probe<3,2>(lambdaindex1024, std::array<u64,3>{v_c63, v_c24, 0}, [&](const std::array<u64,3>& m1118) {
                            u64 v_c65 = m1118[2];
                            slog::join_probe<3,2>(closureindex1025, std::array<u64,3>{v_c65, v_c60, 0}, [&](const std::array<u64,3>& m1119) {
                              u64 v_c66 = m1119[2];
                              slog::join_probe<2,2>(eval_ansindex1026, std::array<u64,2>{v_c57, v_c66}, [&](const std::array<u64,2>& m1120) {
                                slog::join_probe_old<4,2>(evalindex1027, evaldelta1033, std::array<u64,4>{v_c61, v_c24, 0, 0}, [&](const std::array<u64,4>& m1121) {
                                  u64 v_c67 = m1121[2]; u64 v_c47 = m1121[3];
                                  slog::join_probe<2,2>(extend_env_ansindex1028, std::array<u64,2>{v_c64, v_c47}, [&](const std::array<u64,2>& m1122) {
                                    slog::join_probe<2,1>(eval_ansindex1029, std::array<u64,2>{v_c67, 0}, [&](const std::array<u64,2>& m1123) {
                                      u64 v_c53 = m1123[1];
                                      ++_fires;
                                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c56, v_c53}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:52", "delta:eval_args", _fires);
  
      if (!_done)
      {
        ReadTask1034* _cont = new ReadTask1034(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1034(db,b), false);
  // (crule (pre) (scan eval __t1jZw263 ef rho t) (body (exists eval_args (3 2 0 1) 2 t rho) (exists app (1 2 0) 1 ef) (exists tick (2 0 1) 1 t) (exists eval_ans (0 1) 1 __t1jZw263) (join $sup70016x51x0x0x0 (1 3 4 0 2) 3 ef rho t __d0 es) (exists app (1 2 0) 2 ef es) (join-old eval_args (1 3 2 0) 3 (1 3 2 0) es t rho __t2ycT266) (exists eval_args_ans (0 1) 1 __t2ycT266) (join-old app (1 2 0) 2 (1 2 0) ef es __t4H6p267) (join-old tick (1 2 0) 2 (1 2 0) __t4H6p267 t __t8A6X268) (exists tick_ans (0 1) 1 __t8A6X268) (join eval_ans (0 1) 1 __t1jZw263 __t5Yru265) (join eval_args_ans (0 1) 1 __t2ycT266 vs) (join tick_ans (0 1) 1 __t8A6X268 t2) (join-old closure (0 1 2) 1 (0 1 2) __t5Yru265 __t3Nsh264 rhoc) (join-old lambda (0 1 2) 1 (0 1 2) __t3Nsh264 xs eb)) (head (emit $sup70016x51x0x0x1 (1 8 0 2 3 4 5 6 7 9 10 11 12) __t1jZw263 rhoc __d0 __t2ycT266 __t8A6X268 eb ef es rho t t2 vs xs)) interp.slog:52 #f)
  class ReadTask1145 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eval_argsindex1124;  slog::Index** appindex1125;  slog::Index** tickindex1126;  slog::Index** eval_ansindex1127;  slog::Index** $sup70016x51x0x0x0index1128;  slog::Index** appindex1129;  slog::Index** eval_argsindex1130;  slog::Index** eval_args_ansindex1131;  slog::Index** appindex1132;  slog::Index** tickindex1133;  slog::Index** tick_ansindex1134;  slog::Index** eval_ansindex1135;  slog::Index** eval_args_ansindex1136;  slog::Index** tick_ansindex1137;  slog::Index** closureindex1138;  slog::Index** lambdaindex1139;  slog::Index** eval_argsdelta1140;  slog::Index** appdelta1141;  slog::Index** tickdelta1142;  slog::Index** closuredelta1143;  slog::Index** lambdadelta1144;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup70016x51x0x0x1");
      std::vector<u16> ord1146({1, 8, 0, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12});
      slog::Relation* readrel1147 = db->getRelation("$sup70016x51x0x0x1");
      head_index[0] = readrel1147->getIndex(ord1146, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord1148({3, 2, 0, 1});
      slog::Relation* readrel1149 = db->getRelation("eval_args");
      eval_argsindex1124 = readrel1149->getIndex(ord1148, false);
      std::vector<u16> ord1150({1, 2, 0});
      slog::Relation* readrel1151 = db->getRelation("app");
      appindex1125 = readrel1151->getIndex(ord1150, false);
      std::vector<u16> ord1152({2, 0, 1});
      slog::Relation* readrel1153 = db->getRelation("tick");
      tickindex1126 = readrel1153->getIndex(ord1152, false);
      std::vector<u16> ord1154({0, 1});
      slog::Relation* readrel1155 = db->getRelation("eval_ans");
      eval_ansindex1127 = readrel1155->getIndex(ord1154, false);
      std::vector<u16> ord1156({1, 3, 4, 0, 2});
      slog::Relation* readrel1157 = db->getRelation("$sup70016x51x0x0x0");
      $sup70016x51x0x0x0index1128 = readrel1157->getIndex(ord1156, false);
      std::vector<u16> ord1158({1, 2, 0});
      slog::Relation* readrel1159 = db->getRelation("app");
      appindex1129 = readrel1159->getIndex(ord1158, false);
      std::vector<u16> ord1160({1, 3, 2, 0});
      slog::Relation* readrel1161 = db->getRelation("eval_args");
      eval_argsindex1130 = readrel1161->getIndex(ord1160, false);
      std::vector<u16> ord1162({1, 3, 2, 0});
      slog::Relation* readrel1163 = db->getRelation("eval_args");
      eval_argsdelta1140 = readrel1163->getIndex(ord1162, true);
      std::vector<u16> ord1164({0, 1});
      slog::Relation* readrel1165 = db->getRelation("eval_args_ans");
      eval_args_ansindex1131 = readrel1165->getIndex(ord1164, false);
      std::vector<u16> ord1166({1, 2, 0});
      slog::Relation* readrel1167 = db->getRelation("app");
      appindex1132 = readrel1167->getIndex(ord1166, false);
      std::vector<u16> ord1168({1, 2, 0});
      slog::Relation* readrel1169 = db->getRelation("app");
      appdelta1141 = readrel1169->getIndex(ord1168, true);
      std::vector<u16> ord1170({1, 2, 0});
      slog::Relation* readrel1171 = db->getRelation("tick");
      tickindex1133 = readrel1171->getIndex(ord1170, false);
      std::vector<u16> ord1172({1, 2, 0});
      slog::Relation* readrel1173 = db->getRelation("tick");
      tickdelta1142 = readrel1173->getIndex(ord1172, true);
      std::vector<u16> ord1174({0, 1});
      slog::Relation* readrel1175 = db->getRelation("tick_ans");
      tick_ansindex1134 = readrel1175->getIndex(ord1174, false);
      std::vector<u16> ord1176({0, 1});
      slog::Relation* readrel1177 = db->getRelation("eval_ans");
      eval_ansindex1135 = readrel1177->getIndex(ord1176, false);
      std::vector<u16> ord1178({0, 1});
      slog::Relation* readrel1179 = db->getRelation("eval_args_ans");
      eval_args_ansindex1136 = readrel1179->getIndex(ord1178, false);
      std::vector<u16> ord1180({0, 1});
      slog::Relation* readrel1181 = db->getRelation("tick_ans");
      tick_ansindex1137 = readrel1181->getIndex(ord1180, false);
      std::vector<u16> ord1182({0, 1, 2});
      slog::Relation* readrel1183 = db->getRelation("closure");
      closureindex1138 = readrel1183->getIndex(ord1182, false);
      std::vector<u16> ord1184({0, 1, 2});
      slog::Relation* readrel1185 = db->getRelation("closure");
      closuredelta1143 = readrel1185->getIndex(ord1184, true);
      std::vector<u16> ord1186({0, 1, 2});
      slog::Relation* readrel1187 = db->getRelation("lambda");
      lambdaindex1139 = readrel1187->getIndex(ord1186, false);
      std::vector<u16> ord1188({0, 1, 2});
      slog::Relation* readrel1189 = db->getRelation("lambda");
      lambdadelta1144 = readrel1189->getIndex(ord1188, true);
  
    }
    ReadTask1145(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c227 = _t[0];
        u64 v_c55 = _t[1];
        u64 v_c26 = _t[2];
        u64 v_c28 = _t[3];
        if (!slog::exists_probe<4,2>(eval_argsindex1124, std::array<u64,4>{v_c28, v_c26, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex1125, std::array<u64,3>{v_c55, 0, 0})) return;
        if (!slog::exists_probe<3,1>(tickindex1126, std::array<u64,3>{v_c28, 0, 0})) return;
        if (!slog::exists_probe<2,1>(eval_ansindex1127, std::array<u64,2>{v_c227, 0})) return;
        slog::join_probe<5,3>($sup70016x51x0x0x0index1128, std::array<u64,5>{v_c55, v_c26, v_c28, 0, 0}, [&](const std::array<u64,5>& m1190) {
          u64 v_c22 = m1190[3]; u64 v_c41 = m1190[4];
          if (!slog::exists_probe<3,2>(appindex1129, std::array<u64,3>{v_c55, v_c41, 0})) return;
          slog::join_probe_old<4,3>(eval_argsindex1130, eval_argsdelta1140, std::array<u64,4>{v_c41, v_c28, v_c26, 0}, [&](const std::array<u64,4>& m1191) {
            u64 v_c228 = m1191[3];
            if (!slog::exists_probe<2,1>(eval_args_ansindex1131, std::array<u64,2>{v_c228, 0})) return;
            slog::join_probe_old<3,2>(appindex1132, appdelta1141, std::array<u64,3>{v_c55, v_c41, 0}, [&](const std::array<u64,3>& m1192) {
              u64 v_c229 = m1192[2];
              slog::join_probe_old<3,2>(tickindex1133, tickdelta1142, std::array<u64,3>{v_c229, v_c28, 0}, [&](const std::array<u64,3>& m1193) {
                u64 v_c230 = m1193[2];
                if (!slog::exists_probe<2,1>(tick_ansindex1134, std::array<u64,2>{v_c230, 0})) return;
                slog::join_probe<2,1>(eval_ansindex1135, std::array<u64,2>{v_c227, 0}, [&](const std::array<u64,2>& m1194) {
                  u64 v_c231 = m1194[1];
                  slog::join_probe<2,1>(eval_args_ansindex1136, std::array<u64,2>{v_c228, 0}, [&](const std::array<u64,2>& m1195) {
                    u64 v_c62 = m1195[1];
                    slog::join_probe<2,1>(tick_ansindex1137, std::array<u64,2>{v_c230, 0}, [&](const std::array<u64,2>& m1196) {
                      u64 v_c61 = m1196[1];
                      slog::join_probe_old<3,1>(closureindex1138, closuredelta1143, std::array<u64,3>{v_c231, 0, 0}, [&](const std::array<u64,3>& m1197) {
                        u64 v_c232 = m1197[1]; u64 v_c60 = m1197[2];
                        slog::join_probe_old<3,1>(lambdaindex1139, lambdadelta1144, std::array<u64,3>{v_c232, 0, 0}, [&](const std::array<u64,3>& m1198) {
                          u64 v_c63 = m1198[1]; u64 v_c24 = m1198[2];
                          ++_fires;
                          slog::emit<13>(head_rel[0], head_index[0], newbatch[0], std::array<u64,13>{v_c227, v_c60, v_c22, v_c228, v_c230, v_c24, v_c55, v_c41, v_c26, v_c28, v_c61, v_c62, v_c63}, std::array<u16,13>{1, 8, 0, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12});
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
  
      if (_fires) db->bumpFires("interp.slog:52", "delta:eval", _fires);
  
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
  // (crule (pre) (scan eval_ans __t1jZw263 __t5Yru265) (body (join-old closure (0 1 2) 1 (0 1 2) __t5Yru265 __t3Nsh264 rhoc) (join-old lambda (0 1 2) 1 (0 1 2) __t3Nsh264 xs eb) (join-old eval (0 1 2 3) 1 (0 1 2 3) __t1jZw263 ef rho t) (exists eval_args (3 2 0 1) 2 t rho) (exists app (1 2 0) 1 ef) (exists tick (2 0 1) 1 t) (join $sup70016x51x0x0x0 (1 3 4 0 2) 3 ef rho t __d0 es) (exists app (1 2 0) 2 ef es) (join-old eval_args (1 3 2 0) 3 (1 3 2 0) es t rho __t2ycT266) (exists eval_args_ans (0 1) 1 __t2ycT266) (join-old app (1 2 0) 2 (1 2 0) ef es __t4H6p267) (join-old tick (1 2 0) 2 (1 2 0) __t4H6p267 t __t8A6X268) (exists tick_ans (0 1) 1 __t8A6X268) (join-old eval_args_ans (0 1) 1 (0 1) __t2ycT266 vs) (join-old tick_ans (0 1) 1 (0 1) __t8A6X268 t2)) (head (emit $sup70016x51x0x0x1 (1 8 0 2 3 4 5 6 7 9 10 11 12) __t1jZw263 rhoc __d0 __t2ycT266 __t8A6X268 eb ef es rho t t2 vs xs)) interp.slog:52 #f)
  class ReadTask1222 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** closureindex1199;  slog::Index** lambdaindex1200;  slog::Index** evalindex1201;  slog::Index** eval_argsindex1202;  slog::Index** appindex1203;  slog::Index** tickindex1204;  slog::Index** $sup70016x51x0x0x0index1205;  slog::Index** appindex1206;  slog::Index** eval_argsindex1207;  slog::Index** eval_args_ansindex1208;  slog::Index** appindex1209;  slog::Index** tickindex1210;  slog::Index** tick_ansindex1211;  slog::Index** eval_args_ansindex1212;  slog::Index** tick_ansindex1213;  slog::Index** closuredelta1214;  slog::Index** lambdadelta1215;  slog::Index** evaldelta1216;  slog::Index** eval_argsdelta1217;  slog::Index** appdelta1218;  slog::Index** tickdelta1219;  slog::Index** eval_args_ansdelta1220;  slog::Index** tick_ansdelta1221;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup70016x51x0x0x1");
      std::vector<u16> ord1223({1, 8, 0, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12});
      slog::Relation* readrel1224 = db->getRelation("$sup70016x51x0x0x1");
      head_index[0] = readrel1224->getIndex(ord1223, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord1225({0, 1, 2});
      slog::Relation* readrel1226 = db->getRelation("closure");
      closureindex1199 = readrel1226->getIndex(ord1225, false);
      std::vector<u16> ord1227({0, 1, 2});
      slog::Relation* readrel1228 = db->getRelation("closure");
      closuredelta1214 = readrel1228->getIndex(ord1227, true);
      std::vector<u16> ord1229({0, 1, 2});
      slog::Relation* readrel1230 = db->getRelation("lambda");
      lambdaindex1200 = readrel1230->getIndex(ord1229, false);
      std::vector<u16> ord1231({0, 1, 2});
      slog::Relation* readrel1232 = db->getRelation("lambda");
      lambdadelta1215 = readrel1232->getIndex(ord1231, true);
      std::vector<u16> ord1233({0, 1, 2, 3});
      slog::Relation* readrel1234 = db->getRelation("eval");
      evalindex1201 = readrel1234->getIndex(ord1233, false);
      std::vector<u16> ord1235({0, 1, 2, 3});
      slog::Relation* readrel1236 = db->getRelation("eval");
      evaldelta1216 = readrel1236->getIndex(ord1235, true);
      std::vector<u16> ord1237({3, 2, 0, 1});
      slog::Relation* readrel1238 = db->getRelation("eval_args");
      eval_argsindex1202 = readrel1238->getIndex(ord1237, false);
      std::vector<u16> ord1239({1, 2, 0});
      slog::Relation* readrel1240 = db->getRelation("app");
      appindex1203 = readrel1240->getIndex(ord1239, false);
      std::vector<u16> ord1241({2, 0, 1});
      slog::Relation* readrel1242 = db->getRelation("tick");
      tickindex1204 = readrel1242->getIndex(ord1241, false);
      std::vector<u16> ord1243({1, 3, 4, 0, 2});
      slog::Relation* readrel1244 = db->getRelation("$sup70016x51x0x0x0");
      $sup70016x51x0x0x0index1205 = readrel1244->getIndex(ord1243, false);
      std::vector<u16> ord1245({1, 2, 0});
      slog::Relation* readrel1246 = db->getRelation("app");
      appindex1206 = readrel1246->getIndex(ord1245, false);
      std::vector<u16> ord1247({1, 3, 2, 0});
      slog::Relation* readrel1248 = db->getRelation("eval_args");
      eval_argsindex1207 = readrel1248->getIndex(ord1247, false);
      std::vector<u16> ord1249({1, 3, 2, 0});
      slog::Relation* readrel1250 = db->getRelation("eval_args");
      eval_argsdelta1217 = readrel1250->getIndex(ord1249, true);
      std::vector<u16> ord1251({0, 1});
      slog::Relation* readrel1252 = db->getRelation("eval_args_ans");
      eval_args_ansindex1208 = readrel1252->getIndex(ord1251, false);
      std::vector<u16> ord1253({1, 2, 0});
      slog::Relation* readrel1254 = db->getRelation("app");
      appindex1209 = readrel1254->getIndex(ord1253, false);
      std::vector<u16> ord1255({1, 2, 0});
      slog::Relation* readrel1256 = db->getRelation("app");
      appdelta1218 = readrel1256->getIndex(ord1255, true);
      std::vector<u16> ord1257({1, 2, 0});
      slog::Relation* readrel1258 = db->getRelation("tick");
      tickindex1210 = readrel1258->getIndex(ord1257, false);
      std::vector<u16> ord1259({1, 2, 0});
      slog::Relation* readrel1260 = db->getRelation("tick");
      tickdelta1219 = readrel1260->getIndex(ord1259, true);
      std::vector<u16> ord1261({0, 1});
      slog::Relation* readrel1262 = db->getRelation("tick_ans");
      tick_ansindex1211 = readrel1262->getIndex(ord1261, false);
      std::vector<u16> ord1263({0, 1});
      slog::Relation* readrel1264 = db->getRelation("eval_args_ans");
      eval_args_ansindex1212 = readrel1264->getIndex(ord1263, false);
      std::vector<u16> ord1265({0, 1});
      slog::Relation* readrel1266 = db->getRelation("eval_args_ans");
      eval_args_ansdelta1220 = readrel1266->getIndex(ord1265, true);
      std::vector<u16> ord1267({0, 1});
      slog::Relation* readrel1268 = db->getRelation("tick_ans");
      tick_ansindex1213 = readrel1268->getIndex(ord1267, false);
      std::vector<u16> ord1269({0, 1});
      slog::Relation* readrel1270 = db->getRelation("tick_ans");
      tick_ansdelta1221 = readrel1270->getIndex(ord1269, true);
  
    }
    ReadTask1222(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c227 = _t[0];
        u64 v_c231 = _t[1];
        slog::join_probe_old<3,1>(closureindex1199, closuredelta1214, std::array<u64,3>{v_c231, 0, 0}, [&](const std::array<u64,3>& m1271) {
          u64 v_c232 = m1271[1]; u64 v_c60 = m1271[2];
          slog::join_probe_old<3,1>(lambdaindex1200, lambdadelta1215, std::array<u64,3>{v_c232, 0, 0}, [&](const std::array<u64,3>& m1272) {
            u64 v_c63 = m1272[1]; u64 v_c24 = m1272[2];
            slog::join_probe_old<4,1>(evalindex1201, evaldelta1216, std::array<u64,4>{v_c227, 0, 0, 0}, [&](const std::array<u64,4>& m1273) {
              u64 v_c55 = m1273[1]; u64 v_c26 = m1273[2]; u64 v_c28 = m1273[3];
              if (!slog::exists_probe<4,2>(eval_argsindex1202, std::array<u64,4>{v_c28, v_c26, 0, 0})) return;
              if (!slog::exists_probe<3,1>(appindex1203, std::array<u64,3>{v_c55, 0, 0})) return;
              if (!slog::exists_probe<3,1>(tickindex1204, std::array<u64,3>{v_c28, 0, 0})) return;
              slog::join_probe<5,3>($sup70016x51x0x0x0index1205, std::array<u64,5>{v_c55, v_c26, v_c28, 0, 0}, [&](const std::array<u64,5>& m1274) {
                u64 v_c22 = m1274[3]; u64 v_c41 = m1274[4];
                if (!slog::exists_probe<3,2>(appindex1206, std::array<u64,3>{v_c55, v_c41, 0})) return;
                slog::join_probe_old<4,3>(eval_argsindex1207, eval_argsdelta1217, std::array<u64,4>{v_c41, v_c28, v_c26, 0}, [&](const std::array<u64,4>& m1275) {
                  u64 v_c228 = m1275[3];
                  if (!slog::exists_probe<2,1>(eval_args_ansindex1208, std::array<u64,2>{v_c228, 0})) return;
                  slog::join_probe_old<3,2>(appindex1209, appdelta1218, std::array<u64,3>{v_c55, v_c41, 0}, [&](const std::array<u64,3>& m1276) {
                    u64 v_c229 = m1276[2];
                    slog::join_probe_old<3,2>(tickindex1210, tickdelta1219, std::array<u64,3>{v_c229, v_c28, 0}, [&](const std::array<u64,3>& m1277) {
                      u64 v_c230 = m1277[2];
                      if (!slog::exists_probe<2,1>(tick_ansindex1211, std::array<u64,2>{v_c230, 0})) return;
                      slog::join_probe_old<2,1>(eval_args_ansindex1212, eval_args_ansdelta1220, std::array<u64,2>{v_c228, 0}, [&](const std::array<u64,2>& m1278) {
                        u64 v_c62 = m1278[1];
                        slog::join_probe_old<2,1>(tick_ansindex1213, tick_ansdelta1221, std::array<u64,2>{v_c230, 0}, [&](const std::array<u64,2>& m1279) {
                          u64 v_c61 = m1279[1];
                          ++_fires;
                          slog::emit<13>(head_rel[0], head_index[0], newbatch[0], std::array<u64,13>{v_c227, v_c60, v_c22, v_c228, v_c230, v_c24, v_c55, v_c41, v_c26, v_c28, v_c61, v_c62, v_c63}, std::array<u16,13>{1, 8, 0, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12});
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
  
      if (_fires) db->bumpFires("interp.slog:52", "delta:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask1222* _cont = new ReadTask1222(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1222(db,b), false);
  // (crule (pre) (scan mp_put_ans __t1yia422 r) (body (join-old mp_put (0 2 1 3) 1 (0 2 1 3) __t1yia422 k t v) (exists mp_union (2 0 1) 1 t) (join-old mleaf (1 2 0) 2 (1 2 0) k v __t4XKi420) (join-old mp_union (1 2 0) 2 (1 2 0) __t4XKi420 t __t5GHT421)) (head (emit mp_union_ans (0 1) __t5GHT421 r)) map.slog:92 #f)
  class ReadTask1287 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_putindex1280;  slog::Index** mp_unionindex1281;  slog::Index** mleafindex1282;  slog::Index** mp_unionindex1283;  slog::Index** mp_putdelta1284;  slog::Index** mleafdelta1285;  slog::Index** mp_uniondelta1286;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord1288({0, 1});
      slog::Relation* readrel1289 = db->getRelation("mp_union_ans");
      head_index[0] = readrel1289->getIndex(ord1288, false);
      outer_rel = db->getRelation("mp_put_ans");
      std::vector<u16> ord1290({0, 2, 1, 3});
      slog::Relation* readrel1291 = db->getRelation("mp_put");
      mp_putindex1280 = readrel1291->getIndex(ord1290, false);
      std::vector<u16> ord1292({0, 2, 1, 3});
      slog::Relation* readrel1293 = db->getRelation("mp_put");
      mp_putdelta1284 = readrel1293->getIndex(ord1292, true);
      std::vector<u16> ord1294({2, 0, 1});
      slog::Relation* readrel1295 = db->getRelation("mp_union");
      mp_unionindex1281 = readrel1295->getIndex(ord1294, false);
      std::vector<u16> ord1296({1, 2, 0});
      slog::Relation* readrel1297 = db->getRelation("mleaf");
      mleafindex1282 = readrel1297->getIndex(ord1296, false);
      std::vector<u16> ord1298({1, 2, 0});
      slog::Relation* readrel1299 = db->getRelation("mleaf");
      mleafdelta1285 = readrel1299->getIndex(ord1298, true);
      std::vector<u16> ord1300({1, 2, 0});
      slog::Relation* readrel1301 = db->getRelation("mp_union");
      mp_unionindex1283 = readrel1301->getIndex(ord1300, false);
      std::vector<u16> ord1302({1, 2, 0});
      slog::Relation* readrel1303 = db->getRelation("mp_union");
      mp_uniondelta1286 = readrel1303->getIndex(ord1302, true);
  
    }
    ReadTask1287(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c233 = _t[0];
        u64 v_c93 = _t[1];
        slog::join_probe_old<4,1>(mp_putindex1280, mp_putdelta1284, std::array<u64,4>{v_c233, 0, 0, 0}, [&](const std::array<u64,4>& m1304) {
          u64 v_c44 = m1304[1]; u64 v_c28 = m1304[2]; u64 v_c53 = m1304[3];
          if (!slog::exists_probe<3,1>(mp_unionindex1281, std::array<u64,3>{v_c28, 0, 0})) return;
          slog::join_probe_old<3,2>(mleafindex1282, mleafdelta1285, std::array<u64,3>{v_c44, v_c53, 0}, [&](const std::array<u64,3>& m1305) {
            u64 v_c234 = m1305[2];
            slog::join_probe_old<3,2>(mp_unionindex1283, mp_uniondelta1286, std::array<u64,3>{v_c234, v_c28, 0}, [&](const std::array<u64,3>& m1306) {
              u64 v_c235 = m1306[2];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c235, v_c93}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:92", "delta:mp_put_ans", _fires);
  
      if (!_done)
      {
        ReadTask1287* _cont = new ReadTask1287(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1287(db,b), false);
  // (crule (pre) (scan select_branch_ans __t4JBz631 __v1) (body (join-old select_branch (0 1 2 3) 1 (0 1 2 3) __t4JBz631 __v0 e2 e3) (exists $sup70016x87x0x0x0 (2 3 1 0 4 5) 2 e2 e3) (join eval_ans (1 0) 1 __v0 __t5mTH630) (join $sup70016x87x0x0x0 (2 3 1 0 4 5) 2 e2 e3 e1 __d0 rho t) (join-old eval (2 3 0 1) 4 (2 3 0 1) rho t __t5mTH630 e1)) (head (mkstruct eval (1 2 3 0) __226z1519 __v1 rho t)) interp.slog:88 #f)
  class ReadTask1314 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** select_branchindex1307;  slog::Index** $sup70016x87x0x0x0index1308;  slog::Index** eval_ansindex1309;  slog::Index** $sup70016x87x0x0x0index1310;  slog::Index** evalindex1311;  slog::Index** select_branchdelta1312;  slog::Index** evaldelta1313;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("select_branch_ans");
      std::vector<u16> ord1315({0, 1, 2, 3});
      slog::Relation* readrel1316 = db->getRelation("select_branch");
      select_branchindex1307 = readrel1316->getIndex(ord1315, false);
      std::vector<u16> ord1317({0, 1, 2, 3});
      slog::Relation* readrel1318 = db->getRelation("select_branch");
      select_branchdelta1312 = readrel1318->getIndex(ord1317, true);
      std::vector<u16> ord1319({2, 3, 1, 0, 4, 5});
      slog::Relation* readrel1320 = db->getRelation("$sup70016x87x0x0x0");
      $sup70016x87x0x0x0index1308 = readrel1320->getIndex(ord1319, false);
      std::vector<u16> ord1321({1, 0});
      slog::Relation* readrel1322 = db->getRelation("eval_ans");
      eval_ansindex1309 = readrel1322->getIndex(ord1321, false);
      std::vector<u16> ord1323({2, 3, 1, 0, 4, 5});
      slog::Relation* readrel1324 = db->getRelation("$sup70016x87x0x0x0");
      $sup70016x87x0x0x0index1310 = readrel1324->getIndex(ord1323, false);
      std::vector<u16> ord1325({2, 3, 0, 1});
      slog::Relation* readrel1326 = db->getRelation("eval");
      evalindex1311 = readrel1326->getIndex(ord1325, false);
      std::vector<u16> ord1327({2, 3, 0, 1});
      slog::Relation* readrel1328 = db->getRelation("eval");
      evaldelta1313 = readrel1328->getIndex(ord1327, true);
  
    }
    ReadTask1314(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c236 = _t[0];
        u64 v_c168 = _t[1];
        slog::join_probe_old<4,1>(select_branchindex1307, select_branchdelta1312, std::array<u64,4>{v_c236, 0, 0, 0}, [&](const std::array<u64,4>& m1329) {
          u64 v_c47 = m1329[1]; u64 v_c162 = m1329[2]; u64 v_c163 = m1329[3];
          if (!slog::exists_probe<6,2>($sup70016x87x0x0x0index1308, std::array<u64,6>{v_c162, v_c163, 0, 0, 0, 0})) return;
          slog::join_probe<2,1>(eval_ansindex1309, std::array<u64,2>{v_c47, 0}, [&](const std::array<u64,2>& m1330) {
            u64 v_c237 = m1330[1];
            slog::join_probe<6,2>($sup70016x87x0x0x0index1310, std::array<u64,6>{v_c162, v_c163, 0, 0, 0, 0}, [&](const std::array<u64,6>& m1331) {
              u64 v_c161 = m1331[2]; u64 v_c22 = m1331[3]; u64 v_c26 = m1331[4]; u64 v_c28 = m1331[5];
              slog::join_probe_old<4,4>(evalindex1311, evaldelta1313, std::array<u64,4>{v_c26, v_c28, v_c237, v_c161}, [&](const std::array<u64,4>& m1332) {
                ++_fires;
                slog::emit_struct<4>(head_rel[0], newbatch[0], std::array<u64,3>{v_c168, v_c26, v_c28}, std::array<u16,4>{1, 2, 3, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:88", "delta:select_branch_ans", _fires);
  
      if (!_done)
      {
        ReadTask1314* _cont = new ReadTask1314(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1314(db,b), false);
  // (crule (pre (let __trid6DUz1244 const8c6798fa821ed573f6b89759) (let __trel85wC1245 const4a59dbb9cb3129dfcc75170b) (let __tcol5KOf1246 const5feceb66ffc86f38d952786c)) (scan extend_env __t753P32 rhoc xs t2) (body (exists $sup70016x51x0x0x1 (8 10 12 3 4 0 1 2 5 6 7 9 11) 3 rhoc t2 xs) (join extend_env_ans (0 1) 1 __t753P32 __v0) (join $sup70016x51x0x0x1 (8 10 12 3 4 0 1 2 5 6 7 9 11) 3 rhoc t2 xs __d4 eb __d0 __d1 __d2 ef es rho t vs)) (head (tycheck eb (accept (struct app) (struct boolean) (struct if) (struct lambda) (struct let) (struct letrec) (struct num) (struct primref) (struct ref) (struct sym)) __trid6DUz1244 __trel85wC1245 __tcol5KOf1246 (1 2 3 4 0)) (mkstruct eval (1 2 3 0) __3Qtr1243 eb __v0 t2)) interp.slog:52 #f)
  class ReadTask1346 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup70016x51x0x0x1index1333;  slog::Index** extend_env_ansindex1334;  slog::Index** $sup70016x51x0x0x1index1335;
    u32 sid1336;  u32 sid1337;  u32 sid1338;  u32 sid1339;  u32 sid1340;  u32 sid1341;  u32 sid1342;  u32 sid1343;  u32 sid1344;  u32 sid1345;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("eval");
      outer_rel = db->getRelation("extend_env");
      std::vector<u16> ord1347({8, 10, 12, 3, 4, 0, 1, 2, 5, 6, 7, 9, 11});
      slog::Relation* readrel1348 = db->getRelation("$sup70016x51x0x0x1");
      $sup70016x51x0x0x1index1333 = readrel1348->getIndex(ord1347, false);
      std::vector<u16> ord1349({0, 1});
      slog::Relation* readrel1350 = db->getRelation("extend_env_ans");
      extend_env_ansindex1334 = readrel1350->getIndex(ord1349, false);
      std::vector<u16> ord1351({8, 10, 12, 3, 4, 0, 1, 2, 5, 6, 7, 9, 11});
      slog::Relation* readrel1352 = db->getRelation("$sup70016x51x0x0x1");
      $sup70016x51x0x0x1index1335 = readrel1352->getIndex(ord1351, false);
      sid1336 = db->getRelation("app")->getStructId();
      sid1337 = db->getRelation("boolean")->getStructId();
      sid1338 = db->getRelation("if")->getStructId();
      sid1339 = db->getRelation("lambda")->getStructId();
      sid1340 = db->getRelation("let")->getStructId();
      sid1341 = db->getRelation("letrec")->getStructId();
      sid1342 = db->getRelation("num")->getStructId();
      sid1343 = db->getRelation("primref")->getStructId();
      sid1344 = db->getRelation("ref")->getStructId();
      sid1345 = db->getRelation("sym")->getStructId();
  
    }
    ReadTask1346(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c238 = v_const8c6798fa821ed573f6b89759;
      u64 v_c239 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c240 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c241 = _t[0];
        u64 v_c60 = _t[1];
        u64 v_c63 = _t[2];
        u64 v_c61 = _t[3];
        if (!slog::exists_probe<13,3>($sup70016x51x0x0x1index1333, std::array<u64,13>{v_c60, v_c61, v_c63, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(extend_env_ansindex1334, std::array<u64,2>{v_c241, 0}, [&](const std::array<u64,2>& m1353) {
          u64 v_c47 = m1353[1];
          slog::join_probe<13,3>($sup70016x51x0x0x1index1335, std::array<u64,13>{v_c60, v_c61, v_c63, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,13>& m1354) {
            u64 v_c242 = m1354[3]; u64 v_c24 = m1354[4]; u64 v_c22 = m1354[5]; u64 v_c225 = m1354[6]; u64 v_c243 = m1354[7]; u64 v_c55 = m1354[8]; u64 v_c41 = m1354[9]; u64 v_c26 = m1354[10]; u64 v_c28 = m1354[11]; u64 v_c62 = m1354[12];
            ++_fires;
            if (!((is_struct(v_c24) && (decode_struct_id(v_c24) == sid1336 || decode_struct_id(v_c24) == sid1337 || decode_struct_id(v_c24) == sid1338 || decode_struct_id(v_c24) == sid1339 || decode_struct_id(v_c24) == sid1340 || decode_struct_id(v_c24) == sid1341 || decode_struct_id(v_c24) == sid1342 || decode_struct_id(v_c24) == sid1343 || decode_struct_id(v_c24) == sid1344 || decode_struct_id(v_c24) == sid1345))))
            {
              slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c238, v_c239, v_c240, v_c24}, std::array<u16,5>{1, 2, 3, 4, 0});
              return;
            }
            slog::emit_struct<4>(head_rel[1], newbatch[1], std::array<u64,3>{v_c24, v_c47, v_c61}, std::array<u16,4>{1, 2, 3, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:52", "delta:extend_env", _fires);
  
      if (!_done)
      {
        ReadTask1346* _cont = new ReadTask1346(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1346(db,b), false);
  // (crule (pre (let __tconst3ZiI681 const5feceb66ffc86f38d952786c)) (scan mbranch __t0Aux684 p m l r) (body (exists $sup5638x107x0x0x1 (2 3 5 7 0 1 4 6 8 9) 4 l m p r) (exists mp_union (1 2 0) 1 __t0Aux684) (exists mp_msk (1 2 0) 1 p) (join $sup5638x107x0x0x0 (1 2 4 6 0 3 5 7 8) 4 l m p r __t5Sgr680 n q u v) (cmp lt m n) (exists mbranch (1 2 3 4 0) 4 q n u v) (exists mp_union (0 1 2) 2 __t5Sgr680 __t0Aux684) (exists mp_msk (1 2 0) 2 p n) (exists mp_msk_ans (1 0) 1 q) (exists mp_union (1 2 0) 2 __t0Aux684 v) (join $sup5638x107x0x0x1 (9 4 6 8 0 2 3 5 7 1) 9 v n q u __t5Sgr680 l m p r __t78qG683) (exists mp_msk (1 2 0) 3 p n __t78qG683) (exists mp_msk_ans (0 1) 2 __t78qG683 q) (join mbranch (1 2 3 4 0) 4 q n u v __t105R678) (join mp_union (0 1 2) 3 __t5Sgr680 __t0Aux684 __t105R678) (join mp_msk (1 2 0) 3 p n __t78qG683) (join mp_msk_ans (0 1) 2 __t78qG683 q) (join-old mp_union (1 2 0) 2 (1 2 0) __t0Aux684 v __t6NDF685) (join mp_union_ans (0 1) 1 __t6NDF685 __v0) (let __t90AV682 (band p n)) (cmp gt __t90AV682 __tconst3ZiI681)) (head (emit-temp temp9jSj1946 __t5Sgr680 __v0 n q u) (mkstruct mbranch (1 2 3 4 0) __t287h677 q n u __v0)) map.slog:108 #f)
  class ReadTask1374 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x107x0x0x1index1355;  slog::Index** mp_unionindex1356;  slog::Index** mp_mskindex1357;  slog::Index** $sup5638x107x0x0x0index1358;  slog::Index** mbranchindex1359;  slog::Index** mp_unionindex1360;  slog::Index** mp_mskindex1361;  slog::Index** mp_msk_ansindex1362;  slog::Index** mp_unionindex1363;  slog::Index** $sup5638x107x0x0x1index1364;  slog::Index** mp_mskindex1365;  slog::Index** mp_msk_ansindex1366;  slog::Index** mbranchindex1367;  slog::Index** mp_unionindex1368;  slog::Index** mp_mskindex1369;  slog::Index** mp_msk_ansindex1370;  slog::Index** mp_unionindex1371;  slog::Index** mp_union_ansindex1372;  slog::Index** mp_uniondelta1373;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9jSj1946");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord1375({2, 3, 5, 7, 0, 1, 4, 6, 8, 9});
      slog::Relation* readrel1376 = db->getRelation("$sup5638x107x0x0x1");
      $sup5638x107x0x0x1index1355 = readrel1376->getIndex(ord1375, false);
      std::vector<u16> ord1377({1, 2, 0});
      slog::Relation* readrel1378 = db->getRelation("mp_union");
      mp_unionindex1356 = readrel1378->getIndex(ord1377, false);
      std::vector<u16> ord1379({1, 2, 0});
      slog::Relation* readrel1380 = db->getRelation("mp_msk");
      mp_mskindex1357 = readrel1380->getIndex(ord1379, false);
      std::vector<u16> ord1381({1, 2, 4, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel1382 = db->getRelation("$sup5638x107x0x0x0");
      $sup5638x107x0x0x0index1358 = readrel1382->getIndex(ord1381, false);
      std::vector<u16> ord1383({1, 2, 3, 4, 0});
      slog::Relation* readrel1384 = db->getRelation("mbranch");
      mbranchindex1359 = readrel1384->getIndex(ord1383, false);
      std::vector<u16> ord1385({0, 1, 2});
      slog::Relation* readrel1386 = db->getRelation("mp_union");
      mp_unionindex1360 = readrel1386->getIndex(ord1385, false);
      std::vector<u16> ord1387({1, 2, 0});
      slog::Relation* readrel1388 = db->getRelation("mp_msk");
      mp_mskindex1361 = readrel1388->getIndex(ord1387, false);
      std::vector<u16> ord1389({1, 0});
      slog::Relation* readrel1390 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1362 = readrel1390->getIndex(ord1389, false);
      std::vector<u16> ord1391({1, 2, 0});
      slog::Relation* readrel1392 = db->getRelation("mp_union");
      mp_unionindex1363 = readrel1392->getIndex(ord1391, false);
      std::vector<u16> ord1393({9, 4, 6, 8, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel1394 = db->getRelation("$sup5638x107x0x0x1");
      $sup5638x107x0x0x1index1364 = readrel1394->getIndex(ord1393, false);
      std::vector<u16> ord1395({1, 2, 0});
      slog::Relation* readrel1396 = db->getRelation("mp_msk");
      mp_mskindex1365 = readrel1396->getIndex(ord1395, false);
      std::vector<u16> ord1397({0, 1});
      slog::Relation* readrel1398 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1366 = readrel1398->getIndex(ord1397, false);
      std::vector<u16> ord1399({1, 2, 3, 4, 0});
      slog::Relation* readrel1400 = db->getRelation("mbranch");
      mbranchindex1367 = readrel1400->getIndex(ord1399, false);
      std::vector<u16> ord1401({0, 1, 2});
      slog::Relation* readrel1402 = db->getRelation("mp_union");
      mp_unionindex1368 = readrel1402->getIndex(ord1401, false);
      std::vector<u16> ord1403({1, 2, 0});
      slog::Relation* readrel1404 = db->getRelation("mp_msk");
      mp_mskindex1369 = readrel1404->getIndex(ord1403, false);
      std::vector<u16> ord1405({0, 1});
      slog::Relation* readrel1406 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1370 = readrel1406->getIndex(ord1405, false);
      std::vector<u16> ord1407({1, 2, 0});
      slog::Relation* readrel1408 = db->getRelation("mp_union");
      mp_unionindex1371 = readrel1408->getIndex(ord1407, false);
      std::vector<u16> ord1409({1, 2, 0});
      slog::Relation* readrel1410 = db->getRelation("mp_union");
      mp_uniondelta1373 = readrel1410->getIndex(ord1409, true);
      std::vector<u16> ord1411({0, 1});
      slog::Relation* readrel1412 = db->getRelation("mp_union_ans");
      mp_union_ansindex1372 = readrel1412->getIndex(ord1411, false);
  
    }
    ReadTask1374(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c244 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c245 = _t[0];
        u64 v_c71 = _t[1];
        u64 v_c70 = _t[2];
        u64 v_c69 = _t[3];
        u64 v_c93 = _t[4];
        if (!slog::exists_probe<10,4>($sup5638x107x0x0x1index1355, std::array<u64,10>{v_c69, v_c70, v_c71, v_c93, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex1356, std::array<u64,3>{v_c245, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex1357, std::array<u64,3>{v_c71, 0, 0})) return;
        slog::join_probe<9,4>($sup5638x107x0x0x0index1358, std::array<u64,9>{v_c69, v_c70, v_c71, v_c93, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m1413) {
          u64 v_c246 = m1413[4]; u64 v_c126 = m1413[5]; u64 v_c125 = m1413[6]; u64 v_c127 = m1413[7]; u64 v_c53 = m1413[8];
          u64 v_c247 = _prim_lt(db, v_c70, v_c126);
          if (v_c247 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
          if (!v_c247) return;
          if (!slog::exists_probe<5,4>(mbranchindex1359, std::array<u64,5>{v_c125, v_c126, v_c127, v_c53, 0})) return;
          if (!slog::exists_probe<3,2>(mp_unionindex1360, std::array<u64,3>{v_c246, v_c245, 0})) return;
          if (!slog::exists_probe<3,2>(mp_mskindex1361, std::array<u64,3>{v_c71, v_c126, 0})) return;
          if (!slog::exists_probe<2,1>(mp_msk_ansindex1362, std::array<u64,2>{v_c125, 0})) return;
          if (!slog::exists_probe<3,2>(mp_unionindex1363, std::array<u64,3>{v_c245, v_c53, 0})) return;
          slog::join_probe<10,9>($sup5638x107x0x0x1index1364, std::array<u64,10>{v_c53, v_c126, v_c125, v_c127, v_c246, v_c69, v_c70, v_c71, v_c93, 0}, [&](const std::array<u64,10>& m1415) {
            u64 v_c248 = m1415[9];
            if (!slog::exists_probe<3,3>(mp_mskindex1365, std::array<u64,3>{v_c71, v_c126, v_c248})) return;
            if (!slog::exists_probe<2,2>(mp_msk_ansindex1366, std::array<u64,2>{v_c248, v_c125})) return;
            slog::join_probe<5,4>(mbranchindex1367, std::array<u64,5>{v_c125, v_c126, v_c127, v_c53, 0}, [&](const std::array<u64,5>& m1416) {
              u64 v_c249 = m1416[4];
              slog::join_probe<3,3>(mp_unionindex1368, std::array<u64,3>{v_c246, v_c245, v_c249}, [&](const std::array<u64,3>& m1417) {
                slog::join_probe<3,3>(mp_mskindex1369, std::array<u64,3>{v_c71, v_c126, v_c248}, [&](const std::array<u64,3>& m1418) {
                  slog::join_probe<2,2>(mp_msk_ansindex1370, std::array<u64,2>{v_c248, v_c125}, [&](const std::array<u64,2>& m1419) {
                    slog::join_probe_old<3,2>(mp_unionindex1371, mp_uniondelta1373, std::array<u64,3>{v_c245, v_c53, 0}, [&](const std::array<u64,3>& m1420) {
                      u64 v_c250 = m1420[2];
                      slog::join_probe<2,1>(mp_union_ansindex1372, std::array<u64,2>{v_c250, 0}, [&](const std::array<u64,2>& m1421) {
                        u64 v_c47 = m1421[1];
                        u64 v_c251 = _prim_band(db, v_c71, v_c126);
                        if (v_c251 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
                        u64 v_c252 = _prim_gt(db, v_c251, v_c244);
                        if (v_c252 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
                        if (!v_c252) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c246, v_c47, v_c126, v_c125, v_c127});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c125, v_c126, v_c127, v_c47}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:108", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask1374* _cont = new ReadTask1374(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1374(db,b), false);
  // (crule (pre) (scan $sup70016x33x0x0x0 __t5crG665 rho t x) (body (exists ref (1 0) 1 x) (exists lookup (1 2 0) 2 x rho) (join-old eval (2 3 0 1) 3 (2 3 0 1) rho t __t5crG665 __t4vms664) (join-old ref (0 1) 2 (0 1) __t4vms664 x) (join-old lookup (1 2 0) 2 (1 2 0) x rho __t03bu666) (join lookup_ans (0 1) 1 __t03bu666 __v0)) (head (emit eval_ans (0 1) __t5crG665 __v0)) interp.slog:34 #f)
  class ReadTask1432 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex1423;  slog::Index** lookupindex1424;  slog::Index** evalindex1425;  slog::Index** refindex1426;  slog::Index** lookupindex1427;  slog::Index** lookup_ansindex1428;  slog::Index** evaldelta1429;  slog::Index** refdelta1430;  slog::Index** lookupdelta1431;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1433({0, 1});
      slog::Relation* readrel1434 = db->getRelation("eval_ans");
      head_index[0] = readrel1434->getIndex(ord1433, false);
      outer_rel = db->getRelation("$sup70016x33x0x0x0");
      std::vector<u16> ord1435({1, 0});
      slog::Relation* readrel1436 = db->getRelation("ref");
      refindex1423 = readrel1436->getIndex(ord1435, false);
      std::vector<u16> ord1437({1, 2, 0});
      slog::Relation* readrel1438 = db->getRelation("lookup");
      lookupindex1424 = readrel1438->getIndex(ord1437, false);
      std::vector<u16> ord1439({2, 3, 0, 1});
      slog::Relation* readrel1440 = db->getRelation("eval");
      evalindex1425 = readrel1440->getIndex(ord1439, false);
      std::vector<u16> ord1441({2, 3, 0, 1});
      slog::Relation* readrel1442 = db->getRelation("eval");
      evaldelta1429 = readrel1442->getIndex(ord1441, true);
      std::vector<u16> ord1443({0, 1});
      slog::Relation* readrel1444 = db->getRelation("ref");
      refindex1426 = readrel1444->getIndex(ord1443, false);
      std::vector<u16> ord1445({0, 1});
      slog::Relation* readrel1446 = db->getRelation("ref");
      refdelta1430 = readrel1446->getIndex(ord1445, true);
      std::vector<u16> ord1447({1, 2, 0});
      slog::Relation* readrel1448 = db->getRelation("lookup");
      lookupindex1427 = readrel1448->getIndex(ord1447, false);
      std::vector<u16> ord1449({1, 2, 0});
      slog::Relation* readrel1450 = db->getRelation("lookup");
      lookupdelta1431 = readrel1450->getIndex(ord1449, true);
      std::vector<u16> ord1451({0, 1});
      slog::Relation* readrel1452 = db->getRelation("lookup_ans");
      lookup_ansindex1428 = readrel1452->getIndex(ord1451, false);
  
    }
    ReadTask1432(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c253 = _t[0];
        u64 v_c26 = _t[1];
        u64 v_c28 = _t[2];
        u64 v_c29 = _t[3];
        if (!slog::exists_probe<2,1>(refindex1423, std::array<u64,2>{v_c29, 0})) return;
        if (!slog::exists_probe<3,2>(lookupindex1424, std::array<u64,3>{v_c29, v_c26, 0})) return;
        slog::join_probe_old<4,3>(evalindex1425, evaldelta1429, std::array<u64,4>{v_c26, v_c28, v_c253, 0}, [&](const std::array<u64,4>& m1453) {
          u64 v_c254 = m1453[3];
          slog::join_probe_old<2,2>(refindex1426, refdelta1430, std::array<u64,2>{v_c254, v_c29}, [&](const std::array<u64,2>& m1454) {
            slog::join_probe_old<3,2>(lookupindex1427, lookupdelta1431, std::array<u64,3>{v_c29, v_c26, 0}, [&](const std::array<u64,3>& m1455) {
              u64 v_c255 = m1455[2];
              slog::join_probe<2,1>(lookup_ansindex1428, std::array<u64,2>{v_c255, 0}, [&](const std::array<u64,2>& m1456) {
                u64 v_c47 = m1456[1];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c253, v_c47}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:34", "delta:$sup70016x33x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1432* _cont = new ReadTask1432(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1432(db,b), false);
  // (crule (pre (let __trid7szQ1351 const1ca60a80dbae6414bef23d65) (let __trel6YqS1352 consta24220c5193376967f1fa95e) (let __tcol4xJ61353 const5feceb66ffc86f38d952786c) (let __trel5Bmi1354 consta24220c5193376967f1fa95e) (let __tcol1Wt71355 constd4735e3a265e16eee03f5971) (let __trel2FbC1356 consta24220c5193376967f1fa95e) (let __tcol4Ick1357 const4e07408562bedb8b60ce05c1) (let __trel3j9f1358 const76237108756d80d8c9f21f56) (let __tcol7wJz1359 const5feceb66ffc86f38d952786c)) (scan $sup5638x44x0x0x0 __d0 k l m p r t v) (body) (head (tycheck k (accept int) __trid7szQ1351 __trel6YqS1352 __tcol4xJ61353 (1 2 3 4 0)) (tycheck p (accept int) __trid7szQ1351 __trel5Bmi1354 __tcol1Wt71355 (1 2 3 4 0)) (tycheck t (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid7szQ1351 __trel2FbC1356 __tcol4Ick1357 (1 2 3 4 0)) (tycheck k (accept int) __trid7szQ1351 __trel3j9f1358 __tcol7wJz1359 (1 2 3 4 0)) (emit-temp temp3yhj1777 k p t v) (mkstruct mleaf (1 2 0) __t8Woy284 k v)) map.slog:45 #f)
  class ReadTask1460 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[6];
    slog::Index** head_index[6];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid1458;  u32 sid1457;  u32 sid1459;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("malformed_deduction");
      head_rel[3] = db->getRelation("malformed_deduction");
      head_rel[4] = db->getRelation("temp3yhj1777");
      head_rel[5] = db->getRelation("mleaf");
      outer_rel = db->getRelation("$sup5638x44x0x0x0");
      sid1458 = db->getRelation("_enum")->getStructId();
      sid1457 = db->getRelation("mbranch")->getStructId();
      sid1459 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask1460(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c256 = v_const1ca60a80dbae6414bef23d65;
      u64 v_c257 = v_consta24220c5193376967f1fa95e;
      u64 v_c258 = v_const5feceb66ffc86f38d952786c;
      u64 v_c259 = v_consta24220c5193376967f1fa95e;
      u64 v_c260 = v_constd4735e3a265e16eee03f5971;
      u64 v_c261 = v_consta24220c5193376967f1fa95e;
      u64 v_c262 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c263 = v_const76237108756d80d8c9f21f56;
      u64 v_c264 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[6];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
      newbatch[4] = new slog::InsertBatch();
      newbatch[5] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c22 = _t[0];
        u64 v_c44 = _t[1];
        u64 v_c69 = _t[2];
        u64 v_c70 = _t[3];
        u64 v_c71 = _t[4];
        u64 v_c93 = _t[5];
        u64 v_c28 = _t[6];
        u64 v_c53 = _t[7];
        ++_fires;
        if (!(is_int(v_c44)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c256, v_c257, v_c258, v_c44}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c71)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c256, v_c259, v_c260, v_c71}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c28) && (decode_struct_id(v_c28) == sid1457 || decode_struct_id(v_c28) == sid1458 || decode_struct_id(v_c28) == sid1459))))
        {
          slog::emit_struct<5>(head_rel[2], newbatch[2], std::array<u64,4>{v_c256, v_c261, v_c262, v_c28}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c44)))
        {
          slog::emit_struct<5>(head_rel[3], newbatch[3], std::array<u64,4>{v_c256, v_c263, v_c264, v_c44}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_temp<4>(head_rel[4], newbatch[4], std::array<u64,4>{v_c44, v_c71, v_c28, v_c53});
        slog::emit_struct<3>(head_rel[5], newbatch[5], std::array<u64,2>{v_c44, v_c53}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
        head_rel[5]->sendBatch(newbatch[5]);
  
      if (_fires) db->bumpFires("map.slog:45", "delta:$sup5638x44x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1460* _cont = new ReadTask1460(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1460(db,b), false);
  // (crule (pre) (scan eval_args __t11mn554 es rho t) (body (exists eval (2 3 0 1) 2 rho t) (exists eval_args_ans (0 1) 1 __t11mn554) (join $sup70016x75x0x0x0 (2 3 4 0 1) 3 es rho t __d0 ef) (join eval (1 2 3 0) 3 ef rho t __t6oYx552) (join eval_ans (0 1) 1 __t6oYx552 __t21iW553) (join eval_args_ans (0 1) 1 __t11mn554 vs) (join prim (0 1) 1 __t21iW553 op)) (head (mkstruct delta (1 2 0) __5Kx31559 op vs)) interp.slog:76 #f)
  class ReadTask1468 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1461;  slog::Index** eval_args_ansindex1462;  slog::Index** $sup70016x75x0x0x0index1463;  slog::Index** evalindex1464;  slog::Index** eval_ansindex1465;  slog::Index** eval_args_ansindex1466;  slog::Index** primindex1467;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("delta");
      outer_rel = db->getRelation("eval_args");
      std::vector<u16> ord1469({2, 3, 0, 1});
      slog::Relation* readrel1470 = db->getRelation("eval");
      evalindex1461 = readrel1470->getIndex(ord1469, false);
      std::vector<u16> ord1471({0, 1});
      slog::Relation* readrel1472 = db->getRelation("eval_args_ans");
      eval_args_ansindex1462 = readrel1472->getIndex(ord1471, false);
      std::vector<u16> ord1473({2, 3, 4, 0, 1});
      slog::Relation* readrel1474 = db->getRelation("$sup70016x75x0x0x0");
      $sup70016x75x0x0x0index1463 = readrel1474->getIndex(ord1473, false);
      std::vector<u16> ord1475({1, 2, 3, 0});
      slog::Relation* readrel1476 = db->getRelation("eval");
      evalindex1464 = readrel1476->getIndex(ord1475, false);
      std::vector<u16> ord1477({0, 1});
      slog::Relation* readrel1478 = db->getRelation("eval_ans");
      eval_ansindex1465 = readrel1478->getIndex(ord1477, false);
      std::vector<u16> ord1479({0, 1});
      slog::Relation* readrel1480 = db->getRelation("eval_args_ans");
      eval_args_ansindex1466 = readrel1480->getIndex(ord1479, false);
      std::vector<u16> ord1481({0, 1});
      slog::Relation* readrel1482 = db->getRelation("prim");
      primindex1467 = readrel1482->getIndex(ord1481, false);
  
    }
    ReadTask1468(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c265 = _t[0];
        u64 v_c41 = _t[1];
        u64 v_c26 = _t[2];
        u64 v_c28 = _t[3];
        if (!slog::exists_probe<4,2>(evalindex1461, std::array<u64,4>{v_c26, v_c28, 0, 0})) return;
        if (!slog::exists_probe<2,1>(eval_args_ansindex1462, std::array<u64,2>{v_c265, 0})) return;
        slog::join_probe<5,3>($sup70016x75x0x0x0index1463, std::array<u64,5>{v_c41, v_c26, v_c28, 0, 0}, [&](const std::array<u64,5>& m1483) {
          u64 v_c22 = m1483[3]; u64 v_c55 = m1483[4];
          slog::join_probe<4,3>(evalindex1464, std::array<u64,4>{v_c55, v_c26, v_c28, 0}, [&](const std::array<u64,4>& m1484) {
            u64 v_c266 = m1484[3];
            slog::join_probe<2,1>(eval_ansindex1465, std::array<u64,2>{v_c266, 0}, [&](const std::array<u64,2>& m1485) {
              u64 v_c267 = m1485[1];
              slog::join_probe<2,1>(eval_args_ansindex1466, std::array<u64,2>{v_c265, 0}, [&](const std::array<u64,2>& m1486) {
                u64 v_c62 = m1486[1];
                slog::join_probe<2,1>(primindex1467, std::array<u64,2>{v_c267, 0}, [&](const std::array<u64,2>& m1487) {
                  u64 v_c268 = m1487[1];
                  ++_fires;
                  slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c268, v_c62}, std::array<u16,3>{1, 2, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:76", "delta:eval_args", _fires);
  
      if (!_done)
      {
        ReadTask1468* _cont = new ReadTask1468(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1468(db,b), false);
  // (crule (pre (let __trid0pCJ1092 constb177cd86b4c517da8099d6e4) (let __trel38Pv1093 const4a59dbb9cb3129dfcc75170b) (let __tcol5Fwx1094 const5feceb66ffc86f38d952786c) (let __trel1XE11095 const4a59dbb9cb3129dfcc75170b) (let __tcol1Xpj1096 const6b86b273ff34fce19d6b804e) (let __trel365H1097 const4a59dbb9cb3129dfcc75170b) (let __tcol6DvI1098 constd4735e3a265e16eee03f5971)) (scan $sup70016x92x0x0x0 __d0 eb er rho t x) (body) (head (tycheck er (accept (struct app) (struct boolean) (struct if) (struct lambda) (struct let) (struct letrec) (struct num) (struct primref) (struct ref) (struct sym)) __trid0pCJ1092 __trel38Pv1093 __tcol5Fwx1094 (1 2 3 4 0)) (tycheck rho (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid0pCJ1092 __trel1XE11095 __tcol1Xpj1096 (1 2 3 4 0)) (tycheck t (accept seq) __trid0pCJ1092 __trel365H1097 __tcol6DvI1098 (1 2 3 4 0)) (mkstruct eval (1 2 3 0) __94dP1091 er rho t)) interp.slog:93 #f)
  class ReadTask1501 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[4];
    slog::Index** head_index[4];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid1499;  u32 sid1488;  u32 sid1489;  u32 sid1490;  u32 sid1491;  u32 sid1492;  u32 sid1493;  u32 sid1498;  u32 sid1500;  u32 sid1494;  u32 sid1495;  u32 sid1496;  u32 sid1497;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("malformed_deduction");
      head_rel[3] = db->getRelation("eval");
      outer_rel = db->getRelation("$sup70016x92x0x0x0");
      sid1499 = db->getRelation("_enum")->getStructId();
      sid1488 = db->getRelation("app")->getStructId();
      sid1489 = db->getRelation("boolean")->getStructId();
      sid1490 = db->getRelation("if")->getStructId();
      sid1491 = db->getRelation("lambda")->getStructId();
      sid1492 = db->getRelation("let")->getStructId();
      sid1493 = db->getRelation("letrec")->getStructId();
      sid1498 = db->getRelation("mbranch")->getStructId();
      sid1500 = db->getRelation("mleaf")->getStructId();
      sid1494 = db->getRelation("num")->getStructId();
      sid1495 = db->getRelation("primref")->getStructId();
      sid1496 = db->getRelation("ref")->getStructId();
      sid1497 = db->getRelation("sym")->getStructId();
  
    }
    ReadTask1501(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c269 = v_constb177cd86b4c517da8099d6e4;
      u64 v_c270 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c271 = v_const5feceb66ffc86f38d952786c;
      u64 v_c272 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c273 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c274 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c275 = v_constd4735e3a265e16eee03f5971;
  
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
        u64 v_c22 = _t[0];
        u64 v_c24 = _t[1];
        u64 v_c25 = _t[2];
        u64 v_c26 = _t[3];
        u64 v_c28 = _t[4];
        u64 v_c29 = _t[5];
        ++_fires;
        if (!((is_struct(v_c25) && (decode_struct_id(v_c25) == sid1488 || decode_struct_id(v_c25) == sid1489 || decode_struct_id(v_c25) == sid1490 || decode_struct_id(v_c25) == sid1491 || decode_struct_id(v_c25) == sid1492 || decode_struct_id(v_c25) == sid1493 || decode_struct_id(v_c25) == sid1494 || decode_struct_id(v_c25) == sid1495 || decode_struct_id(v_c25) == sid1496 || decode_struct_id(v_c25) == sid1497))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c269, v_c270, v_c271, v_c25}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c26) && (decode_struct_id(v_c26) == sid1498 || decode_struct_id(v_c26) == sid1499 || decode_struct_id(v_c26) == sid1500))))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c269, v_c272, v_c273, v_c26}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_seq(v_c28)))
        {
          slog::emit_struct<5>(head_rel[2], newbatch[2], std::array<u64,4>{v_c269, v_c274, v_c275, v_c28}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<4>(head_rel[3], newbatch[3], std::array<u64,3>{v_c25, v_c26, v_c28}, std::array<u16,4>{1, 2, 3, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
  
      if (_fires) db->bumpFires("interp.slog:93", "delta:$sup70016x92x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1501* _cont = new ReadTask1501(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1501(db,b), false);
  // (crule (pre (let __tconst8WcI1085 const0122baa3ac55f1b433944eb1) (let __tconst9cNI595 const06abaa100ecef791ce028c56) (let _00024sqc696g1041 constd4735e3a265e16eee03f5971) (let _00024sqc3XnD1042 const5feceb66ffc86f38d952786c) (let _00024sqc4UkF1043 const6b86b273ff34fce19d6b804e) (let _00024sqo05pe1044 const5feceb66ffc86f38d952786c) (let _00024sqo5XjX1045 const6b86b273ff34fce19d6b804e) (let _00024sqo0BYf1046 const6b86b273ff34fce19d6b804e) (let _00024sqo9pUp1047 const5feceb66ffc86f38d952786c)) (probe $seq_atr (1 0 2) 1 _00024sqo9pUp1047 __t7ye2598 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo05pe1044 __t7ye2598 _00024seq2) (join $seq_at (1 0 2) 3 _00024sqo5XjX1045 __t7ye2598 _00024seq2) (join $seq_atr (1 0 2) 3 _00024sqo0BYf1046 __t7ye2598 _00024seq2) (exists _enum (1 0) 1 __tconst8WcI1085) (join delta (1 2 0) 2 __tconst9cNI595 _00024seq2 __t0WVv596) (join _enum (1 0) 1 __tconst8WcI1085 __t8vy6593) (join symval (0 1) 1 __t7ye2598 s) (letp _00024sql2mO51039 (aslst _00024seq2)) (let chk14uX2027 (llen _00024sql2mO51039)) (eq _00024sqc696g1041 chk14uX2027) (letp chk2DX32028 (lref _00024sql2mO51039 _00024sqc3XnD1042)) (eq __t7ye2598 chk2DX32028) (letp chk8RjB2029 (lref _00024sql2mO51039 _00024sqc4UkF1043)) (eq __t7ye2598 chk8RjB2029)) (head (emit-temp temp7W0m2012 __t0WVv596) (mkstruct boolval (1 0) __t17ui594 __t8vy6593)) interp.slog:121 #f)
  class ReadTask1509 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex1502;  slog::Index** $seq_atindex1503;  slog::Index** $seq_atrindex1504;  slog::Index** _enumindex1505;  slog::Index** deltaindex1506;  slog::Index** _enumindex1507;  slog::Index** symvalindex1508;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7W0m2012");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord1510({1, 0, 2});
      slog::Relation* readrel1511 = db->getRelation("$seq_atr");
      driver_index = readrel1511->getIndex(ord1510, true);
      std::vector<u16> ord1512({1, 0, 2});
      slog::Relation* readrel1513 = db->getRelation("$seq_at");
      $seq_atindex1502 = readrel1513->getIndex(ord1512, false);
      std::vector<u16> ord1514({1, 0, 2});
      slog::Relation* readrel1515 = db->getRelation("$seq_at");
      $seq_atindex1503 = readrel1515->getIndex(ord1514, false);
      std::vector<u16> ord1516({1, 0, 2});
      slog::Relation* readrel1517 = db->getRelation("$seq_atr");
      $seq_atrindex1504 = readrel1517->getIndex(ord1516, false);
      std::vector<u16> ord1518({1, 0});
      slog::Relation* readrel1519 = db->getRelation("_enum");
      _enumindex1505 = readrel1519->getIndex(ord1518, false);
      std::vector<u16> ord1520({1, 2, 0});
      slog::Relation* readrel1521 = db->getRelation("delta");
      deltaindex1506 = readrel1521->getIndex(ord1520, false);
      std::vector<u16> ord1522({1, 0});
      slog::Relation* readrel1523 = db->getRelation("_enum");
      _enumindex1507 = readrel1523->getIndex(ord1522, false);
      std::vector<u16> ord1524({0, 1});
      slog::Relation* readrel1525 = db->getRelation("symval");
      symvalindex1508 = readrel1525->getIndex(ord1524, false);
  
    }
    ReadTask1509(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c276 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c277 = v_const06abaa100ecef791ce028c56;
      u64 v_c278 = v_constd4735e3a265e16eee03f5971;
      u64 v_c279 = v_const5feceb66ffc86f38d952786c;
      u64 v_c280 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c281 = v_const5feceb66ffc86f38d952786c;
      u64 v_c282 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c283 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c284 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c284, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1526) {
        u64 v_c285 = m1526[1];
        u64 v_c82 = m1526[2];
        if (buckethash(v_c285) != bucket) return;
        slog::join_probe<3,3>($seq_atindex1502, std::array<u64,3>{v_c281, v_c285, v_c82}, [&](const std::array<u64,3>& m1527) {
          slog::join_probe<3,3>($seq_atindex1503, std::array<u64,3>{v_c282, v_c285, v_c82}, [&](const std::array<u64,3>& m1528) {
            slog::join_probe<3,3>($seq_atrindex1504, std::array<u64,3>{v_c283, v_c285, v_c82}, [&](const std::array<u64,3>& m1529) {
              if (!slog::exists_probe<2,1>(_enumindex1505, std::array<u64,2>{v_c276, 0})) return;
              slog::join_probe<3,2>(deltaindex1506, std::array<u64,3>{v_c277, v_c82, 0}, [&](const std::array<u64,3>& m1530) {
                u64 v_c286 = m1530[2];
                slog::join_probe<2,1>(_enumindex1507, std::array<u64,2>{v_c276, 0}, [&](const std::array<u64,2>& m1531) {
                  u64 v_c287 = m1531[1];
                  slog::join_probe<2,1>(symvalindex1508, std::array<u64,2>{v_c285, 0}, [&](const std::array<u64,2>& m1532) {
                    u64 v_c288 = m1532[1];
                    bool ok1533 = true;
                    u64 v_c289 = _prim_aslst(db, v_c82, &ok1533);
                    if (!ok1533) return;
                    u64 v_c290 = _prim_llen(db, v_c289);
                    if (v_c290 == slog_error) { slog::emit_pending_error(db, "interp.slog:121"); return; }
                    if (v_c278 != v_c290) return;
                    bool ok1534 = true;
                    u64 v_c291 = _prim_lref(db, v_c289, v_c279, &ok1534);
                    if (!ok1534) return;
                    if (v_c285 != v_c291) return;
                    bool ok1535 = true;
                    u64 v_c292 = _prim_lref(db, v_c289, v_c280, &ok1535);
                    if (!ok1535) return;
                    if (v_c285 != v_c292) return;
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c286});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c287}, std::array<u16,2>{1, 0});
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
        ReadTask1509* _cont = new ReadTask1509(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1509(db,b), false);
  // (crule (pre) (scan mp_join __t6jFY835 k __t5lKq834 p __t6oBk833) (body (exists mp_put (1 2 3 0) 2 __t6oBk833 k) (exists $sup5638x44x0x0x0 (1 4 6 7 0 2 3 5) 3 k p __t6oBk833) (exists mbranch (0 1 2 3 4) 2 __t6oBk833 p) (exists mp_msk (1 2 0) 1 k) (exists mp_join_ans (0 1) 1 __t6jFY835) (join mleaf (0 1 2) 2 __t5lKq834 k v) (exists $sup5638x44x0x0x0 (1 4 6 7 0 2 3 5) 4 k p __t6oBk833 v) (join mp_put (1 2 3 0) 3 __t6oBk833 k v __t6Fc5832) (join $sup5638x44x0x0x0 (1 7 0 6 4 2 3 5) 5 k v __t6Fc5832 __t6oBk833 p l m r) (join mbranch (1 2 3 4 0) 5 p m l r __t6oBk833) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t2nZc836) (join mp_msk_ans (0 1) 1 __t2nZc836 __v0) (neq p __v0) (join mp_join_ans (0 1) 1 __t6jFY835 res)) (head (emit mp_put_ans (0 1) __t6Fc5832 res)) map.slog:45 #f)
  class ReadTask1550 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_putindex1536;  slog::Index** $sup5638x44x0x0x0index1537;  slog::Index** mbranchindex1538;  slog::Index** mp_mskindex1539;  slog::Index** mp_join_ansindex1540;  slog::Index** mleafindex1541;  slog::Index** $sup5638x44x0x0x0index1542;  slog::Index** mp_putindex1543;  slog::Index** $sup5638x44x0x0x0index1544;  slog::Index** mbranchindex1545;  slog::Index** mp_mskindex1546;  slog::Index** mp_msk_ansindex1547;  slog::Index** mp_join_ansindex1548;  slog::Index** mp_mskdelta1549;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_ans");
      std::vector<u16> ord1551({0, 1});
      slog::Relation* readrel1552 = db->getRelation("mp_put_ans");
      head_index[0] = readrel1552->getIndex(ord1551, false);
      outer_rel = db->getRelation("mp_join");
      std::vector<u16> ord1553({1, 2, 3, 0});
      slog::Relation* readrel1554 = db->getRelation("mp_put");
      mp_putindex1536 = readrel1554->getIndex(ord1553, false);
      std::vector<u16> ord1555({1, 4, 6, 7, 0, 2, 3, 5});
      slog::Relation* readrel1556 = db->getRelation("$sup5638x44x0x0x0");
      $sup5638x44x0x0x0index1537 = readrel1556->getIndex(ord1555, false);
      std::vector<u16> ord1557({0, 1, 2, 3, 4});
      slog::Relation* readrel1558 = db->getRelation("mbranch");
      mbranchindex1538 = readrel1558->getIndex(ord1557, false);
      std::vector<u16> ord1559({1, 2, 0});
      slog::Relation* readrel1560 = db->getRelation("mp_msk");
      mp_mskindex1539 = readrel1560->getIndex(ord1559, false);
      std::vector<u16> ord1561({0, 1});
      slog::Relation* readrel1562 = db->getRelation("mp_join_ans");
      mp_join_ansindex1540 = readrel1562->getIndex(ord1561, false);
      std::vector<u16> ord1563({0, 1, 2});
      slog::Relation* readrel1564 = db->getRelation("mleaf");
      mleafindex1541 = readrel1564->getIndex(ord1563, false);
      std::vector<u16> ord1565({1, 4, 6, 7, 0, 2, 3, 5});
      slog::Relation* readrel1566 = db->getRelation("$sup5638x44x0x0x0");
      $sup5638x44x0x0x0index1542 = readrel1566->getIndex(ord1565, false);
      std::vector<u16> ord1567({1, 2, 3, 0});
      slog::Relation* readrel1568 = db->getRelation("mp_put");
      mp_putindex1543 = readrel1568->getIndex(ord1567, false);
      std::vector<u16> ord1569({1, 7, 0, 6, 4, 2, 3, 5});
      slog::Relation* readrel1570 = db->getRelation("$sup5638x44x0x0x0");
      $sup5638x44x0x0x0index1544 = readrel1570->getIndex(ord1569, false);
      std::vector<u16> ord1571({1, 2, 3, 4, 0});
      slog::Relation* readrel1572 = db->getRelation("mbranch");
      mbranchindex1545 = readrel1572->getIndex(ord1571, false);
      std::vector<u16> ord1573({1, 2, 0});
      slog::Relation* readrel1574 = db->getRelation("mp_msk");
      mp_mskindex1546 = readrel1574->getIndex(ord1573, false);
      std::vector<u16> ord1575({1, 2, 0});
      slog::Relation* readrel1576 = db->getRelation("mp_msk");
      mp_mskdelta1549 = readrel1576->getIndex(ord1575, true);
      std::vector<u16> ord1577({0, 1});
      slog::Relation* readrel1578 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1547 = readrel1578->getIndex(ord1577, false);
      std::vector<u16> ord1579({0, 1});
      slog::Relation* readrel1580 = db->getRelation("mp_join_ans");
      mp_join_ansindex1548 = readrel1580->getIndex(ord1579, false);
  
    }
    ReadTask1550(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c293 = _t[0];
        u64 v_c44 = _t[1];
        u64 v_c294 = _t[2];
        u64 v_c71 = _t[3];
        u64 v_c295 = _t[4];
        if (!slog::exists_probe<4,2>(mp_putindex1536, std::array<u64,4>{v_c295, v_c44, 0, 0})) return;
        if (!slog::exists_probe<8,3>($sup5638x44x0x0x0index1537, std::array<u64,8>{v_c44, v_c71, v_c295, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,2>(mbranchindex1538, std::array<u64,5>{v_c295, v_c71, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex1539, std::array<u64,3>{v_c44, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_join_ansindex1540, std::array<u64,2>{v_c293, 0})) return;
        slog::join_probe<3,2>(mleafindex1541, std::array<u64,3>{v_c294, v_c44, 0}, [&](const std::array<u64,3>& m1581) {
          u64 v_c53 = m1581[2];
          if (!slog::exists_probe<8,4>($sup5638x44x0x0x0index1542, std::array<u64,8>{v_c44, v_c71, v_c295, v_c53, 0, 0, 0, 0})) return;
          slog::join_probe<4,3>(mp_putindex1543, std::array<u64,4>{v_c295, v_c44, v_c53, 0}, [&](const std::array<u64,4>& m1582) {
            u64 v_c296 = m1582[3];
            slog::join_probe<8,5>($sup5638x44x0x0x0index1544, std::array<u64,8>{v_c44, v_c53, v_c296, v_c295, v_c71, 0, 0, 0}, [&](const std::array<u64,8>& m1583) {
              u64 v_c69 = m1583[5]; u64 v_c70 = m1583[6]; u64 v_c93 = m1583[7];
              slog::join_probe<5,5>(mbranchindex1545, std::array<u64,5>{v_c71, v_c70, v_c69, v_c93, v_c295}, [&](const std::array<u64,5>& m1584) {
                slog::join_probe_old<3,2>(mp_mskindex1546, mp_mskdelta1549, std::array<u64,3>{v_c44, v_c70, 0}, [&](const std::array<u64,3>& m1585) {
                  u64 v_c297 = m1585[2];
                  slog::join_probe<2,1>(mp_msk_ansindex1547, std::array<u64,2>{v_c297, 0}, [&](const std::array<u64,2>& m1586) {
                    u64 v_c47 = m1586[1];
                    if (v_c71 == v_c47) return;
                    slog::join_probe<2,1>(mp_join_ansindex1548, std::array<u64,2>{v_c293, 0}, [&](const std::array<u64,2>& m1587) {
                      u64 v_c298 = m1587[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c296, v_c298}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:45", "delta:mp_join", _fires);
  
      if (!_done)
      {
        ReadTask1550* _cont = new ReadTask1550(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1550(db,b), false);
  // (crule (pre (let __tconst58wu717 const4e07408562bedb8b60ce05c1) (let __tconst0hQe724 const6b86b273ff34fce19d6b804e) (let __tconst7lpr731 const0933fb667296882d8c45abca) (let __tconst9wm7741 const73475cb40a568e8da8a045ce) (let __tconst4vHk745 const5feceb66ffc86f38d952786c) (let __tconst1Nf0752 const90fb9068eda6f2d68bb61c33) (let __tconst5hIJ756 const3d914f9348c9cc0ff8a79716) (let __tconst6I9K760 constd59eced1ded07f84c145592f) (let __t75NQ757 (lempty))) (once) (body) (head (emit-temp temp58Bx1898 __t75NQ757) (mkstruct num (1 0) __t4oVz718 __tconst58wu717) (mkstruct ref (1 0) __t9NO9722 __tconst6I9K760) (mkstruct num (1 0) __t8m96725 __tconst0hQe724) (mkstruct ref (1 0) __t64lX727 __tconst5hIJ756) (mkstruct primref (1 0) __t1nv4732 __tconst7lpr731) (mkstruct ref (1 0) __t6TM2740 __tconst9wm7741) (mkstruct num (1 0) __t8vxv746 __tconst4vHk745) (mkstruct primref (1 0) __t6Asn753 __tconst1Nf0752)) kcfa.slog:70 #f)
  class ReadTask1588 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[9];
    slog::Index** head_index[9];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp58Bx1898");
      head_rel[1] = db->getRelation("num");
      head_rel[2] = db->getRelation("ref");
      head_rel[3] = db->getRelation("num");
      head_rel[4] = db->getRelation("ref");
      head_rel[5] = db->getRelation("primref");
      head_rel[6] = db->getRelation("ref");
      head_rel[7] = db->getRelation("num");
      head_rel[8] = db->getRelation("primref");
  
    }
    ReadTask1588(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c299 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c300 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c301 = v_const0933fb667296882d8c45abca;
      u64 v_c302 = v_const73475cb40a568e8da8a045ce;
      u64 v_c303 = v_const5feceb66ffc86f38d952786c;
      u64 v_c304 = v_const90fb9068eda6f2d68bb61c33;
      u64 v_c305 = v_const3d914f9348c9cc0ff8a79716;
      u64 v_c306 = v_constd59eced1ded07f84c145592f;
      u64 v_c307 = _prim_lempty(db);
      if (v_c307 == slog_error) { slog::emit_pending_error(db, "kcfa.slog:70"); return true; }
  
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
      slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c307});
      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c299}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[2], newbatch[2], std::array<u64,1>{v_c306}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[3], newbatch[3], std::array<u64,1>{v_c300}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[4], newbatch[4], std::array<u64,1>{v_c305}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[5], newbatch[5], std::array<u64,1>{v_c301}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[6], newbatch[6], std::array<u64,1>{v_c302}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[7], newbatch[7], std::array<u64,1>{v_c303}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[8], newbatch[8], std::array<u64,1>{v_c304}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
        head_rel[5]->sendBatch(newbatch[5]);
        head_rel[6]->sendBatch(newbatch[6]);
        head_rel[7]->sendBatch(newbatch[7]);
        head_rel[8]->sendBatch(newbatch[8]);
  
      if (_fires) db->bumpFires("kcfa.slog:70", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask1588(db,b), true);
  // (crule (pre (let __tconst2b6r460 const5feceb66ffc86f38d952786c)) (scan mp_msk __t5aM3462 k m) (body (exists $sup5638x42x0x0x0 (1 3 4 0 2 5 6) 2 k m) (exists mbranch (2 0 1 3 4) 1 m) (exists mp_put (2 3 0 1) 1 k) (exists mp_msk_ans (0 1) 1 __t5aM3462) (join $sup5638x42x0x0x1 (1 2 4 5 0 3 6 7) 3 __t5aM3462 k m p __t6Bbs459 l r v) (join $sup5638x42x0x0x0 (4 2 3 5 0 1 6) 7 p l m r __t6Bbs459 k v) (exists mp_put (3 0 2 1) 3 v __t6Bbs459 k) (exists mp_put (1 2 3 0) 3 r k v) (exists mp_msk_ans (0 1) 2 __t5aM3462 p) (join mbranch (1 2 3 4 0) 4 p m l r __t9ixF458) (join mp_put (0 2 1 3) 4 __t6Bbs459 k __t9ixF458 v) (join-old mp_put (1 2 3 0) 3 (1 2 3 0) r k v __t9vSj463) (join mp_msk_ans (0 1) 2 __t5aM3462 p) (join mp_put_ans (0 1) 1 __t9vSj463 __v0) (let __t1jZ6461 (band k m)) (cmp gt __t1jZ6461 __tconst2b6r460)) (head (emit-temp temp7Xjy1975 __t6Bbs459 __v0 l m p) (mkstruct mbranch (1 2 3 4 0) __t8oL5457 p m l __v0)) map.slog:43 #f)
  class ReadTask1604 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x42x0x0x0index1589;  slog::Index** mbranchindex1590;  slog::Index** mp_putindex1591;  slog::Index** mp_msk_ansindex1592;  slog::Index** $sup5638x42x0x0x1index1593;  slog::Index** $sup5638x42x0x0x0index1594;  slog::Index** mp_putindex1595;  slog::Index** mp_putindex1596;  slog::Index** mp_msk_ansindex1597;  slog::Index** mbranchindex1598;  slog::Index** mp_putindex1599;  slog::Index** mp_putindex1600;  slog::Index** mp_msk_ansindex1601;  slog::Index** mp_put_ansindex1602;  slog::Index** mp_putdelta1603;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7Xjy1975");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_msk");
      std::vector<u16> ord1605({1, 3, 4, 0, 2, 5, 6});
      slog::Relation* readrel1606 = db->getRelation("$sup5638x42x0x0x0");
      $sup5638x42x0x0x0index1589 = readrel1606->getIndex(ord1605, false);
      std::vector<u16> ord1607({2, 0, 1, 3, 4});
      slog::Relation* readrel1608 = db->getRelation("mbranch");
      mbranchindex1590 = readrel1608->getIndex(ord1607, false);
      std::vector<u16> ord1609({2, 3, 0, 1});
      slog::Relation* readrel1610 = db->getRelation("mp_put");
      mp_putindex1591 = readrel1610->getIndex(ord1609, false);
      std::vector<u16> ord1611({0, 1});
      slog::Relation* readrel1612 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1592 = readrel1612->getIndex(ord1611, false);
      std::vector<u16> ord1613({1, 2, 4, 5, 0, 3, 6, 7});
      slog::Relation* readrel1614 = db->getRelation("$sup5638x42x0x0x1");
      $sup5638x42x0x0x1index1593 = readrel1614->getIndex(ord1613, false);
      std::vector<u16> ord1615({4, 2, 3, 5, 0, 1, 6});
      slog::Relation* readrel1616 = db->getRelation("$sup5638x42x0x0x0");
      $sup5638x42x0x0x0index1594 = readrel1616->getIndex(ord1615, false);
      std::vector<u16> ord1617({3, 0, 2, 1});
      slog::Relation* readrel1618 = db->getRelation("mp_put");
      mp_putindex1595 = readrel1618->getIndex(ord1617, false);
      std::vector<u16> ord1619({1, 2, 3, 0});
      slog::Relation* readrel1620 = db->getRelation("mp_put");
      mp_putindex1596 = readrel1620->getIndex(ord1619, false);
      std::vector<u16> ord1621({0, 1});
      slog::Relation* readrel1622 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1597 = readrel1622->getIndex(ord1621, false);
      std::vector<u16> ord1623({1, 2, 3, 4, 0});
      slog::Relation* readrel1624 = db->getRelation("mbranch");
      mbranchindex1598 = readrel1624->getIndex(ord1623, false);
      std::vector<u16> ord1625({0, 2, 1, 3});
      slog::Relation* readrel1626 = db->getRelation("mp_put");
      mp_putindex1599 = readrel1626->getIndex(ord1625, false);
      std::vector<u16> ord1627({1, 2, 3, 0});
      slog::Relation* readrel1628 = db->getRelation("mp_put");
      mp_putindex1600 = readrel1628->getIndex(ord1627, false);
      std::vector<u16> ord1629({1, 2, 3, 0});
      slog::Relation* readrel1630 = db->getRelation("mp_put");
      mp_putdelta1603 = readrel1630->getIndex(ord1629, true);
      std::vector<u16> ord1631({0, 1});
      slog::Relation* readrel1632 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1601 = readrel1632->getIndex(ord1631, false);
      std::vector<u16> ord1633({0, 1});
      slog::Relation* readrel1634 = db->getRelation("mp_put_ans");
      mp_put_ansindex1602 = readrel1634->getIndex(ord1633, false);
  
    }
    ReadTask1604(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c216 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c219 = _t[0];
        u64 v_c44 = _t[1];
        u64 v_c70 = _t[2];
        if (!slog::exists_probe<7,2>($sup5638x42x0x0x0index1589, std::array<u64,7>{v_c44, v_c70, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex1590, std::array<u64,5>{v_c70, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(mp_putindex1591, std::array<u64,4>{v_c44, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex1592, std::array<u64,2>{v_c219, 0})) return;
        slog::join_probe<8,3>($sup5638x42x0x0x1index1593, std::array<u64,8>{v_c219, v_c44, v_c70, 0, 0, 0, 0, 0}, [&](const std::array<u64,8>& m1635) {
          u64 v_c71 = m1635[3]; u64 v_c217 = m1635[4]; u64 v_c69 = m1635[5]; u64 v_c93 = m1635[6]; u64 v_c53 = m1635[7];
          slog::join_probe<7,7>($sup5638x42x0x0x0index1594, std::array<u64,7>{v_c71, v_c69, v_c70, v_c93, v_c217, v_c44, v_c53}, [&](const std::array<u64,7>& m1636) {
            if (!slog::exists_probe<4,3>(mp_putindex1595, std::array<u64,4>{v_c53, v_c217, v_c44, 0})) return;
            if (!slog::exists_probe<4,3>(mp_putindex1596, std::array<u64,4>{v_c93, v_c44, v_c53, 0})) return;
            if (!slog::exists_probe<2,2>(mp_msk_ansindex1597, std::array<u64,2>{v_c219, v_c71})) return;
            slog::join_probe<5,4>(mbranchindex1598, std::array<u64,5>{v_c71, v_c70, v_c69, v_c93, 0}, [&](const std::array<u64,5>& m1637) {
              u64 v_c218 = m1637[4];
              slog::join_probe<4,4>(mp_putindex1599, std::array<u64,4>{v_c217, v_c44, v_c218, v_c53}, [&](const std::array<u64,4>& m1638) {
                slog::join_probe_old<4,3>(mp_putindex1600, mp_putdelta1603, std::array<u64,4>{v_c93, v_c44, v_c53, 0}, [&](const std::array<u64,4>& m1639) {
                  u64 v_c220 = m1639[3];
                  slog::join_probe<2,2>(mp_msk_ansindex1601, std::array<u64,2>{v_c219, v_c71}, [&](const std::array<u64,2>& m1640) {
                    slog::join_probe<2,1>(mp_put_ansindex1602, std::array<u64,2>{v_c220, 0}, [&](const std::array<u64,2>& m1641) {
                      u64 v_c47 = m1641[1];
                      u64 v_c221 = _prim_band(db, v_c44, v_c70);
                      if (v_c221 == slog_error) { slog::emit_pending_error(db, "map.slog:43"); return; }
                      u64 v_c308 = _prim_gt(db, v_c221, v_c216);
                      if (v_c308 == slog_error) { slog::emit_pending_error(db, "map.slog:43"); return; }
                      if (!v_c308) return;
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c217, v_c47, v_c69, v_c70, v_c71});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c71, v_c70, v_c69, v_c47}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:43", "delta:mp_msk", _fires);
  
      if (!_done)
      {
        ReadTask1604* _cont = new ReadTask1604(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1604(db,b), false);
  // (crule (pre (let __trid7Cd61100 const8c6798fa821ed573f6b89759) (let __trel1q4N1101 constc8dd3fe14ad7db61de7362fc) (let __tcol2cGE1102 const5feceb66ffc86f38d952786c) (let __trel57py1103 constc8dd3fe14ad7db61de7362fc) (let __tcol4q6t1104 const6b86b273ff34fce19d6b804e) (let __trel3rok1105 constc8dd3fe14ad7db61de7362fc) (let __tcol45so1106 constd4735e3a265e16eee03f5971)) (scan $sup70016x51x0x0x1 __d0 __d1 __d2 __d4 eb ef es rho rhoc t t2 vs xs) (body) (head (tycheck rhoc (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid7Cd61100 __trel1q4N1101 __tcol2cGE1102 (1 2 3 4 0)) (tycheck xs (accept seq) __trid7Cd61100 __trel57py1103 __tcol4q6t1104 (1 2 3 4 0)) (tycheck t2 (accept seq) __trid7Cd61100 __trel3rok1105 __tcol45so1106 (1 2 3 4 0)) (mkstruct extend_env (1 2 3 0) __8INx1099 rhoc xs t2)) interp.slog:52 #f)
  class ReadTask1646 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[4];
    slog::Index** head_index[4];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid1644;  u32 sid1643;  u32 sid1645;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("malformed_deduction");
      head_rel[3] = db->getRelation("extend_env");
      outer_rel = db->getRelation("$sup70016x51x0x0x1");
      sid1644 = db->getRelation("_enum")->getStructId();
      sid1643 = db->getRelation("mbranch")->getStructId();
      sid1645 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask1646(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c309 = v_const8c6798fa821ed573f6b89759;
      u64 v_c310 = v_constc8dd3fe14ad7db61de7362fc;
      u64 v_c311 = v_const5feceb66ffc86f38d952786c;
      u64 v_c312 = v_constc8dd3fe14ad7db61de7362fc;
      u64 v_c313 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c314 = v_constc8dd3fe14ad7db61de7362fc;
      u64 v_c315 = v_constd4735e3a265e16eee03f5971;
  
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
        u64 v_c22 = _t[0];
        u64 v_c225 = _t[1];
        u64 v_c243 = _t[2];
        u64 v_c242 = _t[3];
        u64 v_c24 = _t[4];
        u64 v_c55 = _t[5];
        u64 v_c41 = _t[6];
        u64 v_c26 = _t[7];
        u64 v_c60 = _t[8];
        u64 v_c28 = _t[9];
        u64 v_c61 = _t[10];
        u64 v_c62 = _t[11];
        u64 v_c63 = _t[12];
        ++_fires;
        if (!((is_struct(v_c60) && (decode_struct_id(v_c60) == sid1643 || decode_struct_id(v_c60) == sid1644 || decode_struct_id(v_c60) == sid1645))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c309, v_c310, v_c311, v_c60}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_seq(v_c63)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c309, v_c312, v_c313, v_c63}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_seq(v_c61)))
        {
          slog::emit_struct<5>(head_rel[2], newbatch[2], std::array<u64,4>{v_c309, v_c314, v_c315, v_c61}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<4>(head_rel[3], newbatch[3], std::array<u64,3>{v_c60, v_c63, v_c61}, std::array<u16,4>{1, 2, 3, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
  
      if (_fires) db->bumpFires("interp.slog:52", "delta:$sup70016x51x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask1646* _cont = new ReadTask1646(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1646(db,b), false);
  // (crule (pre (let _00024sqc250U943 const6b86b273ff34fce19d6b804e) (let _00024sqc6BYS944 const5feceb66ffc86f38d952786c) (let _00024sqc0VjW945 const6b86b273ff34fce19d6b804e) (let _00024sqc8uew946 const5feceb66ffc86f38d952786c) (let _00024sqo2y2x951 const5feceb66ffc86f38d952786c) (let __t6qtm791 (lempty))) (scan eval __t7vCW795 e rho t) (body (exists eval_args (3 2 0 1) 2 t rho) (exists $seq_at (1 0 2) 2 _00024sqo2y2x951 e) (exists eval_ans (0 1) 1 __t7vCW795) (join $sup70016x43x0x0x0 (2 4 5 0 1 3) 3 e rho t _00024seq0 __t7ZV0794 es) (join eval_args (3 2 0 1) 4 t rho __t7ZV0794 _00024seq0) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo2y2x951 e _00024seq0) (join-old eval_args (1 3 2 0) 3 (1 3 2 0) es t rho __t9m2L796) (exists eval_args_ans (0 1) 1 __t9m2L796) (join eval_ans (0 1) 1 __t7vCW795 __v0) (join eval_args_ans (0 1) 1 __t9m2L796 __v1) (letp _00024sql7raK941 (aslst _00024seq0)) (let _00024sqn1wbQ942 (llen _00024sql7raK941)) (cmp ge _00024sqn1wbQ942 _00024sqc250U943) (letp chk6CZP2040 (lref _00024sql7raK941 _00024sqc6BYS944)) (eq e chk6CZP2040) (let _00024sqp9fgp947 (_0002d _00024sqn1wbQ942 _00024sqc8uew946)) (let chk2thb2041 (lslice _00024sql7raK941 _00024sqc0VjW945 _00024sqp9fgp947)) (eq es chk2thb2041)) (head (emit-temp temp2swd2033 __t6qtm791 __t7ZV0794 __v0 __v1)) interp.slog:44 #f)
  class ReadTask1659 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eval_argsindex1647;  slog::Index** $seq_atindex1648;  slog::Index** eval_ansindex1649;  slog::Index** $sup70016x43x0x0x0index1650;  slog::Index** eval_argsindex1651;  slog::Index** $seq_atindex1652;  slog::Index** eval_argsindex1653;  slog::Index** eval_args_ansindex1654;  slog::Index** eval_ansindex1655;  slog::Index** eval_args_ansindex1656;  slog::Index** $seq_atdelta1657;  slog::Index** eval_argsdelta1658;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2swd2033");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord1660({3, 2, 0, 1});
      slog::Relation* readrel1661 = db->getRelation("eval_args");
      eval_argsindex1647 = readrel1661->getIndex(ord1660, false);
      std::vector<u16> ord1662({1, 0, 2});
      slog::Relation* readrel1663 = db->getRelation("$seq_at");
      $seq_atindex1648 = readrel1663->getIndex(ord1662, false);
      std::vector<u16> ord1664({0, 1});
      slog::Relation* readrel1665 = db->getRelation("eval_ans");
      eval_ansindex1649 = readrel1665->getIndex(ord1664, false);
      std::vector<u16> ord1666({2, 4, 5, 0, 1, 3});
      slog::Relation* readrel1667 = db->getRelation("$sup70016x43x0x0x0");
      $sup70016x43x0x0x0index1650 = readrel1667->getIndex(ord1666, false);
      std::vector<u16> ord1668({3, 2, 0, 1});
      slog::Relation* readrel1669 = db->getRelation("eval_args");
      eval_argsindex1651 = readrel1669->getIndex(ord1668, false);
      std::vector<u16> ord1670({1, 0, 2});
      slog::Relation* readrel1671 = db->getRelation("$seq_at");
      $seq_atindex1652 = readrel1671->getIndex(ord1670, false);
      std::vector<u16> ord1672({1, 0, 2});
      slog::Relation* readrel1673 = db->getRelation("$seq_at");
      $seq_atdelta1657 = readrel1673->getIndex(ord1672, true);
      std::vector<u16> ord1674({1, 3, 2, 0});
      slog::Relation* readrel1675 = db->getRelation("eval_args");
      eval_argsindex1653 = readrel1675->getIndex(ord1674, false);
      std::vector<u16> ord1676({1, 3, 2, 0});
      slog::Relation* readrel1677 = db->getRelation("eval_args");
      eval_argsdelta1658 = readrel1677->getIndex(ord1676, true);
      std::vector<u16> ord1678({0, 1});
      slog::Relation* readrel1679 = db->getRelation("eval_args_ans");
      eval_args_ansindex1654 = readrel1679->getIndex(ord1678, false);
      std::vector<u16> ord1680({0, 1});
      slog::Relation* readrel1681 = db->getRelation("eval_ans");
      eval_ansindex1655 = readrel1681->getIndex(ord1680, false);
      std::vector<u16> ord1682({0, 1});
      slog::Relation* readrel1683 = db->getRelation("eval_args_ans");
      eval_args_ansindex1656 = readrel1683->getIndex(ord1682, false);
  
    }
    ReadTask1659(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c316 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c317 = v_const5feceb66ffc86f38d952786c;
      u64 v_c318 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c319 = v_const5feceb66ffc86f38d952786c;
      u64 v_c320 = v_const5feceb66ffc86f38d952786c;
      u64 v_c321 = _prim_lempty(db);
      if (v_c321 == slog_error) { slog::emit_pending_error(db, "interp.slog:44"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c322 = _t[0];
        u64 v_c39 = _t[1];
        u64 v_c26 = _t[2];
        u64 v_c28 = _t[3];
        if (!slog::exists_probe<4,2>(eval_argsindex1647, std::array<u64,4>{v_c28, v_c26, 0, 0})) return;
        if (!slog::exists_probe<3,2>($seq_atindex1648, std::array<u64,3>{v_c320, v_c39, 0})) return;
        if (!slog::exists_probe<2,1>(eval_ansindex1649, std::array<u64,2>{v_c322, 0})) return;
        slog::join_probe<6,3>($sup70016x43x0x0x0index1650, std::array<u64,6>{v_c39, v_c26, v_c28, 0, 0, 0}, [&](const std::array<u64,6>& m1684) {
          u64 v_c35 = m1684[3]; u64 v_c323 = m1684[4]; u64 v_c41 = m1684[5];
          slog::join_probe<4,4>(eval_argsindex1651, std::array<u64,4>{v_c28, v_c26, v_c323, v_c35}, [&](const std::array<u64,4>& m1685) {
            slog::join_probe_old<3,3>($seq_atindex1652, $seq_atdelta1657, std::array<u64,3>{v_c320, v_c39, v_c35}, [&](const std::array<u64,3>& m1686) {
              slog::join_probe_old<4,3>(eval_argsindex1653, eval_argsdelta1658, std::array<u64,4>{v_c41, v_c28, v_c26, 0}, [&](const std::array<u64,4>& m1687) {
                u64 v_c324 = m1687[3];
                if (!slog::exists_probe<2,1>(eval_args_ansindex1654, std::array<u64,2>{v_c324, 0})) return;
                slog::join_probe<2,1>(eval_ansindex1655, std::array<u64,2>{v_c322, 0}, [&](const std::array<u64,2>& m1688) {
                  u64 v_c47 = m1688[1];
                  slog::join_probe<2,1>(eval_args_ansindex1656, std::array<u64,2>{v_c324, 0}, [&](const std::array<u64,2>& m1689) {
                    u64 v_c168 = m1689[1];
                    bool ok1690 = true;
                    u64 v_c325 = _prim_aslst(db, v_c35, &ok1690);
                    if (!ok1690) return;
                    u64 v_c326 = _prim_llen(db, v_c325);
                    if (v_c326 == slog_error) { slog::emit_pending_error(db, "interp.slog:44"); return; }
                    u64 v_c327 = _prim_ge(db, v_c326, v_c316);
                    if (v_c327 == slog_error) { slog::emit_pending_error(db, "interp.slog:44"); return; }
                    if (!v_c327) return;
                    bool ok1692 = true;
                    u64 v_c328 = _prim_lref(db, v_c325, v_c317, &ok1692);
                    if (!ok1692) return;
                    if (v_c39 != v_c328) return;
                    u64 v_c329 = _prim__0002d(db, v_c326, v_c319);
                    if (v_c329 == slog_error) { slog::emit_pending_error(db, "interp.slog:44"); return; }
                    u64 v_c330 = _prim_lslice(db, v_c325, v_c318, v_c329);
                    if (v_c330 == slog_error) { slog::emit_pending_error(db, "interp.slog:44"); return; }
                    if (v_c41 != v_c330) return;
                    ++_fires;
                    slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c321, v_c323, v_c47, v_c168});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:44", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask1659* _cont = new ReadTask1659(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1659(db,b), false);
  // (crule (pre (let __tconst19gx36 const6b86b273ff34fce19d6b804e)) (scan mp_union __t4pAf35 __t4rR634 __t9QG833) (body (join mbranch (0 1 2 3 4) 1 __t9QG833 q n u v) (join mbranch (0 1 2 3 4) 1 __t4rR634 p m l r) (cmp lt n m) (let __t204137 (band q m)) (cmp lt __t204137 __tconst19gx36)) (head (emit $sup5638x95x0x0x0 (0 1 2 3 4 5 6 7 8) __t4pAf35 l m n p q r u v)) map.slog:96 #f)
  class ReadTask1695 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex1693;  slog::Index** mbranchindex1694;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x95x0x0x0");
      std::vector<u16> ord1696({0, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel1697 = db->getRelation("$sup5638x95x0x0x0");
      head_index[0] = readrel1697->getIndex(ord1696, false);
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord1698({0, 1, 2, 3, 4});
      slog::Relation* readrel1699 = db->getRelation("mbranch");
      mbranchindex1693 = readrel1699->getIndex(ord1698, false);
      std::vector<u16> ord1700({0, 1, 2, 3, 4});
      slog::Relation* readrel1701 = db->getRelation("mbranch");
      mbranchindex1694 = readrel1701->getIndex(ord1700, false);
  
    }
    ReadTask1695(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c331 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c332 = _t[0];
        u64 v_c333 = _t[1];
        u64 v_c334 = _t[2];
        slog::join_probe<5,1>(mbranchindex1693, std::array<u64,5>{v_c334, 0, 0, 0, 0}, [&](const std::array<u64,5>& m1702) {
          u64 v_c125 = m1702[1]; u64 v_c126 = m1702[2]; u64 v_c127 = m1702[3]; u64 v_c53 = m1702[4];
          slog::join_probe<5,1>(mbranchindex1694, std::array<u64,5>{v_c333, 0, 0, 0, 0}, [&](const std::array<u64,5>& m1703) {
            u64 v_c71 = m1703[1]; u64 v_c70 = m1703[2]; u64 v_c69 = m1703[3]; u64 v_c93 = m1703[4];
            u64 v_c335 = _prim_lt(db, v_c126, v_c70);
            if (v_c335 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
            if (!v_c335) return;
            u64 v_c336 = _prim_band(db, v_c125, v_c70);
            if (v_c336 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
            u64 v_c337 = _prim_lt(db, v_c336, v_c331);
            if (v_c337 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
            if (!v_c337) return;
            ++_fires;
            slog::emit<9>(head_rel[0], head_index[0], newbatch[0], std::array<u64,9>{v_c332, v_c69, v_c70, v_c126, v_c71, v_c125, v_c93, v_c127, v_c53}, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:96", "delta:mp_union", _fires);
  
      if (!_done)
      {
        ReadTask1695* _cont = new ReadTask1695(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1695(db,b), false);
  // (crule (pre (let __t4XRi123 (lempty))) (scan tick __t2KyZ126 site t) (body (join klimit (0) 0 k)) (head (emit-temp temp5onR1943 __t4XRi123 k site t)) context.slog:11 #f)
  class ReadTask1707 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** klimitindex1706;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5onR1943");
      outer_rel = db->getRelation("tick");
      std::vector<u16> ord1708({0});
      slog::Relation* readrel1709 = db->getRelation("klimit");
      klimitindex1706 = readrel1709->getIndex(ord1708, false);
  
    }
    ReadTask1707(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c338 = _prim_lempty(db);
      if (v_c338 == slog_error) { slog::emit_pending_error(db, "context.slog:11"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c339 = _t[0];
        u64 v_c213 = _t[1];
        u64 v_c28 = _t[2];
        slog::join_all<1>(klimitindex1706, [&](const std::array<u64,1>& m1710) {
          u64 v_c44 = m1710[0];
          ++_fires;
          slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c338, v_c44, v_c213, v_c28});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("context.slog:11", "delta:tick", _fires);
  
      if (!_done)
      {
        ReadTask1707* _cont = new ReadTask1707(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1707(db,b), false);
  // (crule (pre) (scan mp_hsb __t15yE714 __t4JMu715) (body (exists mp_hsb_ans (0 1) 1 __t15yE714) (join mp_hsb_ans (0 1) 1 __t15yE714 __v3) (join mp_hsb_ans (0 1) 1 __t15yE714 __v1) (join $sup5638x25x0x0x1 (1 2 0 3 4 5 6) 0 __d1 __v0 __d0 p0 p1 t0 t1) (let chk0TQO1942 (bxor p0 p1)) (eq __t4JMu715 chk0TQO1942)) (head (emit $sup5638x25x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) __d1 __v0 __v3 __v1 __d0 __t15yE714 __t15yE714 p0 p1 t0 t1)) map.slog:26 #f)
  class ReadTask1715 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_hsb_ansindex1711;  slog::Index** mp_hsb_ansindex1712;  slog::Index** mp_hsb_ansindex1713;  slog::Index** $sup5638x25x0x0x1index1714;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x25x0x0x2");
      std::vector<u16> ord1716({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel1717 = db->getRelation("$sup5638x25x0x0x2");
      head_index[0] = readrel1717->getIndex(ord1716, false);
      outer_rel = db->getRelation("mp_hsb");
      std::vector<u16> ord1718({0, 1});
      slog::Relation* readrel1719 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex1711 = readrel1719->getIndex(ord1718, false);
      std::vector<u16> ord1720({0, 1});
      slog::Relation* readrel1721 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex1712 = readrel1721->getIndex(ord1720, false);
      std::vector<u16> ord1722({0, 1});
      slog::Relation* readrel1723 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex1713 = readrel1723->getIndex(ord1722, false);
      std::vector<u16> ord1724({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel1725 = db->getRelation("$sup5638x25x0x0x1");
      $sup5638x25x0x0x1index1714 = readrel1725->getIndex(ord1724, false);
  
    }
    ReadTask1715(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c223 = _t[0];
        u64 v_c224 = _t[1];
        if (!slog::exists_probe<2,1>(mp_hsb_ansindex1711, std::array<u64,2>{v_c223, 0})) return;
        slog::join_probe<2,1>(mp_hsb_ansindex1712, std::array<u64,2>{v_c223, 0}, [&](const std::array<u64,2>& m1726) {
          u64 v_c199 = m1726[1];
          slog::join_probe<2,1>(mp_hsb_ansindex1713, std::array<u64,2>{v_c223, 0}, [&](const std::array<u64,2>& m1727) {
            u64 v_c168 = m1727[1];
            slog::join_all<7>($sup5638x25x0x0x1index1714, [&](const std::array<u64,7>& m1728) {
              u64 v_c225 = m1728[0]; u64 v_c47 = m1728[1]; u64 v_c22 = m1728[2]; u64 v_c197 = m1728[3]; u64 v_c203 = m1728[4]; u64 v_c204 = m1728[5]; u64 v_c205 = m1728[6];
              u64 v_c340 = _prim_bxor(db, v_c197, v_c203);
              if (v_c340 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
              if (v_c224 != v_c340) return;
              ++_fires;
              slog::emit<11>(head_rel[0], head_index[0], newbatch[0], std::array<u64,11>{v_c225, v_c47, v_c199, v_c168, v_c22, v_c223, v_c223, v_c197, v_c203, v_c204, v_c205}, std::array<u16,11>{1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:26", "delta:mp_hsb", _fires);
  
      if (!_done)
      {
        ReadTask1715* _cont = new ReadTask1715(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1715(db,b), false);
  // (crule (pre (let __trid3uoS1058 const5d6ab4fefffae2e4c15033db) (let __trel6yFB1059 const52b5e20f559958f34e533431) (let __tcol6Bcn1060 const6b86b273ff34fce19d6b804e) (let __trel6nqp1061 const65c80aac3433a01ef8a7f298) (let __tcol0oGB1062 const6b86b273ff34fce19d6b804e) (let __trel25zN1063 const65c80aac3433a01ef8a7f298) (let __tcol34iC1064 constd4735e3a265e16eee03f5971)) (scan eval __7yeU1057 __t4cK3622 rho t) (body (exists eval (3 1 0 2) 1 t) (join-old mp_put (1 3 0 2) 2 (1 3 0 2) rho t __t5ODE624 x) (exists mp_put_ans (0 1) 1 __t5ODE624) (join-old letrec (0 1 2 3) 2 (0 1 2 3) __t4cK3622 x er eb) (join-old eval (3 1 0 2) 2 (3 1 0 2) t er __t4Pyv623 rho2) (join-old mp_put_ans (0 1) 2 (0 1) __t5ODE624 rho2) (join-old eval_ans (0 1) 1 (0 1) __t4Pyv623 vr)) (head (tycheck t (accept seq) __trid3uoS1058 __trel6yFB1059 __tcol6Bcn1060 (1 2 3 4 0)) (tycheck t (accept seq) __trid3uoS1058 __trel6nqp1061 __tcol0oGB1062 (1 2 3 4 0)) (tycheck t (accept seq) __trid3uoS1058 __trel25zN1063 __tcol34iC1064 (1 2 3 4 0)) (emit store (0 1 2) x t vr) (emit binding_event (0 1 2) x t t)) interp.slog:98 #f)
  class ReadTask1741 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[5];
    slog::Index** head_index[5];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1729;  slog::Index** mp_putindex1730;  slog::Index** mp_put_ansindex1731;  slog::Index** letrecindex1732;  slog::Index** evalindex1733;  slog::Index** mp_put_ansindex1734;  slog::Index** eval_ansindex1735;  slog::Index** mp_putdelta1736;  slog::Index** letrecdelta1737;  slog::Index** evaldelta1738;  slog::Index** mp_put_ansdelta1739;  slog::Index** eval_ansdelta1740;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("malformed_deduction");
      head_rel[3] = db->getRelation("store");
      std::vector<u16> ord1742({0, 1, 2});
      slog::Relation* readrel1743 = db->getRelation("store");
      head_index[3] = readrel1743->getIndex(ord1742, false);
      head_rel[4] = db->getRelation("binding_event");
      std::vector<u16> ord1744({0, 1, 2});
      slog::Relation* readrel1745 = db->getRelation("binding_event");
      head_index[4] = readrel1745->getIndex(ord1744, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord1746({3, 1, 0, 2});
      slog::Relation* readrel1747 = db->getRelation("eval");
      evalindex1729 = readrel1747->getIndex(ord1746, false);
      std::vector<u16> ord1748({1, 3, 0, 2});
      slog::Relation* readrel1749 = db->getRelation("mp_put");
      mp_putindex1730 = readrel1749->getIndex(ord1748, false);
      std::vector<u16> ord1750({1, 3, 0, 2});
      slog::Relation* readrel1751 = db->getRelation("mp_put");
      mp_putdelta1736 = readrel1751->getIndex(ord1750, true);
      std::vector<u16> ord1752({0, 1});
      slog::Relation* readrel1753 = db->getRelation("mp_put_ans");
      mp_put_ansindex1731 = readrel1753->getIndex(ord1752, false);
      std::vector<u16> ord1754({0, 1, 2, 3});
      slog::Relation* readrel1755 = db->getRelation("letrec");
      letrecindex1732 = readrel1755->getIndex(ord1754, false);
      std::vector<u16> ord1756({0, 1, 2, 3});
      slog::Relation* readrel1757 = db->getRelation("letrec");
      letrecdelta1737 = readrel1757->getIndex(ord1756, true);
      std::vector<u16> ord1758({3, 1, 0, 2});
      slog::Relation* readrel1759 = db->getRelation("eval");
      evalindex1733 = readrel1759->getIndex(ord1758, false);
      std::vector<u16> ord1760({3, 1, 0, 2});
      slog::Relation* readrel1761 = db->getRelation("eval");
      evaldelta1738 = readrel1761->getIndex(ord1760, true);
      std::vector<u16> ord1762({0, 1});
      slog::Relation* readrel1763 = db->getRelation("mp_put_ans");
      mp_put_ansindex1734 = readrel1763->getIndex(ord1762, false);
      std::vector<u16> ord1764({0, 1});
      slog::Relation* readrel1765 = db->getRelation("mp_put_ans");
      mp_put_ansdelta1739 = readrel1765->getIndex(ord1764, true);
      std::vector<u16> ord1766({0, 1});
      slog::Relation* readrel1767 = db->getRelation("eval_ans");
      eval_ansindex1735 = readrel1767->getIndex(ord1766, false);
      std::vector<u16> ord1768({0, 1});
      slog::Relation* readrel1769 = db->getRelation("eval_ans");
      eval_ansdelta1740 = readrel1769->getIndex(ord1768, true);
  
    }
    ReadTask1741(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c341 = v_const5d6ab4fefffae2e4c15033db;
      u64 v_c342 = v_const52b5e20f559958f34e533431;
      u64 v_c343 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c344 = v_const65c80aac3433a01ef8a7f298;
      u64 v_c345 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c346 = v_const65c80aac3433a01ef8a7f298;
      u64 v_c347 = v_constd4735e3a265e16eee03f5971;
  
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
        u64 v_c348 = _t[0];
        u64 v_c349 = _t[1];
        u64 v_c26 = _t[2];
        u64 v_c28 = _t[3];
        if (!slog::exists_probe<4,1>(evalindex1729, std::array<u64,4>{v_c28, 0, 0, 0})) return;
        slog::join_probe_old<4,2>(mp_putindex1730, mp_putdelta1736, std::array<u64,4>{v_c26, v_c28, 0, 0}, [&](const std::array<u64,4>& m1770) {
          u64 v_c350 = m1770[2]; u64 v_c29 = m1770[3];
          if (!slog::exists_probe<2,1>(mp_put_ansindex1731, std::array<u64,2>{v_c350, 0})) return;
          slog::join_probe_old<4,2>(letrecindex1732, letrecdelta1737, std::array<u64,4>{v_c349, v_c29, 0, 0}, [&](const std::array<u64,4>& m1771) {
            u64 v_c25 = m1771[2]; u64 v_c24 = m1771[3];
            slog::join_probe_old<4,2>(evalindex1733, evaldelta1738, std::array<u64,4>{v_c28, v_c25, 0, 0}, [&](const std::array<u64,4>& m1772) {
              u64 v_c351 = m1772[2]; u64 v_c27 = m1772[3];
              slog::join_probe_old<2,2>(mp_put_ansindex1734, mp_put_ansdelta1739, std::array<u64,2>{v_c350, v_c27}, [&](const std::array<u64,2>& m1773) {
                slog::join_probe_old<2,1>(eval_ansindex1735, eval_ansdelta1740, std::array<u64,2>{v_c351, 0}, [&](const std::array<u64,2>& m1774) {
                  u64 v_c51 = m1774[1];
                  ++_fires;
                  if (!(is_seq(v_c28)))
                  {
                    slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c341, v_c342, v_c343, v_c28}, std::array<u16,5>{1, 2, 3, 4, 0});
                    return;
                  }
                  if (!(is_seq(v_c28)))
                  {
                    slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c341, v_c344, v_c345, v_c28}, std::array<u16,5>{1, 2, 3, 4, 0});
                    return;
                  }
                  if (!(is_seq(v_c28)))
                  {
                    slog::emit_struct<5>(head_rel[2], newbatch[2], std::array<u64,4>{v_c341, v_c346, v_c347, v_c28}, std::array<u16,5>{1, 2, 3, 4, 0});
                    return;
                  }
                  slog::emit<3>(head_rel[3], head_index[3], newbatch[3], std::array<u64,3>{v_c29, v_c28, v_c51}, std::array<u16,3>{0, 1, 2});
                  slog::emit<3>(head_rel[4], head_index[4], newbatch[4], std::array<u64,3>{v_c29, v_c28, v_c28}, std::array<u16,3>{0, 1, 2});
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
        head_rel[4]->sendBatch(newbatch[4]);
  
      if (_fires) db->bumpFires("interp.slog:98", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask1741* _cont = new ReadTask1741(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1741(db,b), false);
  // (crule (pre) (scan $sup5638x29x0x0x1 __d0 __d1 __v0 p0 p1 t0 t1) (body (join mp_hsb_ans (0 1) 0 __t16An260 __v3) (join mp_hsb_ans (0 1) 1 __t16An260 __v1) (let __t7Dpg261 (bxor p0 p1)) (join-old mp_hsb (0 1) 2 (0 1) __t16An260 __t7Dpg261)) (head (emit $sup5638x29x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) __d1 __v0 __v3 __v1 __d0 __t16An260 __t16An260 p0 p1 t0 t1)) map.slog:30 #f)
  class ReadTask1779 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_hsb_ansindex1775;  slog::Index** mp_hsb_ansindex1776;  slog::Index** mp_hsbindex1777;  slog::Index** mp_hsbdelta1778;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x29x0x0x2");
      std::vector<u16> ord1780({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel1781 = db->getRelation("$sup5638x29x0x0x2");
      head_index[0] = readrel1781->getIndex(ord1780, false);
      outer_rel = db->getRelation("$sup5638x29x0x0x1");
      std::vector<u16> ord1782({0, 1});
      slog::Relation* readrel1783 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex1775 = readrel1783->getIndex(ord1782, false);
      std::vector<u16> ord1784({0, 1});
      slog::Relation* readrel1785 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex1776 = readrel1785->getIndex(ord1784, false);
      std::vector<u16> ord1786({0, 1});
      slog::Relation* readrel1787 = db->getRelation("mp_hsb");
      mp_hsbindex1777 = readrel1787->getIndex(ord1786, false);
      std::vector<u16> ord1788({0, 1});
      slog::Relation* readrel1789 = db->getRelation("mp_hsb");
      mp_hsbdelta1778 = readrel1789->getIndex(ord1788, true);
  
    }
    ReadTask1779(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c225 = _t[1];
        u64 v_c47 = _t[2];
        u64 v_c197 = _t[3];
        u64 v_c203 = _t[4];
        u64 v_c204 = _t[5];
        u64 v_c205 = _t[6];
        slog::join_all<2>(mp_hsb_ansindex1775, [&](const std::array<u64,2>& m1790) {
          u64 v_c352 = m1790[0]; u64 v_c199 = m1790[1];
          slog::join_probe<2,1>(mp_hsb_ansindex1776, std::array<u64,2>{v_c352, 0}, [&](const std::array<u64,2>& m1791) {
            u64 v_c168 = m1791[1];
            u64 v_c353 = _prim_bxor(db, v_c197, v_c203);
            if (v_c353 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
            slog::join_probe_old<2,2>(mp_hsbindex1777, mp_hsbdelta1778, std::array<u64,2>{v_c352, v_c353}, [&](const std::array<u64,2>& m1792) {
              ++_fires;
              slog::emit<11>(head_rel[0], head_index[0], newbatch[0], std::array<u64,11>{v_c225, v_c47, v_c199, v_c168, v_c22, v_c352, v_c352, v_c197, v_c203, v_c204, v_c205}, std::array<u16,11>{1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:30", "delta:$sup5638x29x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask1779* _cont = new ReadTask1779(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1779(db,b), false);
}

