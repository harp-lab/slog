
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const0122baa3ac55f1b433944eb1;
extern u64 v_const0453462f31b2bcf68e33a91f;
extern u64 v_const06abaa100ecef791ce028c56;
extern u64 v_const1064263932db82f2cf6d4ac2;
extern u64 v_const1b2483991f3f37e4463261cd;
extern u64 v_const3fdba35f04dc8c462986c992;
extern u64 v_const4a44dc15364204a80fe80e90;
extern u64 v_const4a59dbb9cb3129dfcc75170b;
extern u64 v_const4fc82b26aecb47d2868c4efb;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const60e3114d9b4b6577eea8cbc0;
extern u64 v_const624b60c58c9d8bfb6ff1886c;
extern u64 v_const6b51d431df5d7f141cbececc;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const844546be553b9dcbf71ae163;
extern u64 v_const8c6798fa821ed573f6b89759;
extern u64 v_constaa218622af4adb846b2d6244;
extern u64 v_constb9e118781cea1f9fa01462e0;
extern u64 v_constcd2a69ce5ca278db1d6da969;
extern u64 v_constd01925b37634a1a9d24159d8;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_constda53dc5001ef1e872bd575bd;
extern u64 v_constde34af73616246ffdc2cc593;
extern u64 v_constdede4476644eb06b5a48b866;
extern u64 v_conste25572d3e5a4cc456a779178;
extern u64 v_consted725292f5f32d61535958c1;
extern u64 v_constf5ca38f748a1d6eaf726b8a4;
extern u64 v_constf6cdc3db4b71e0cdeda6912e;
extern u64 v_constfdb0a95399e17c48d6f65653;


void slog_rules_cdd64258ef82da591(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre (let __tconst35Xg1071 const0122baa3ac55f1b433944eb1) (let __tconst3u5R106 const06abaa100ecef791ce028c56) (let _00024sqc9bdu903 constd4735e3a265e16eee03f5971) (let _00024sqc9U0q904 const5feceb66ffc86f38d952786c) (let _00024sqc3xmn905 const6b86b273ff34fce19d6b804e) (let _00024sqo7aO7906 const5feceb66ffc86f38d952786c) (let _00024sqo8pFe907 const6b86b273ff34fce19d6b804e) (let _00024sqo3hRp908 const6b86b273ff34fce19d6b804e) (let _00024sqo4hee909 const5feceb66ffc86f38d952786c)) (probe $seq_atr (1 0 2) 1 _00024sqo3hRp908 __t5IbK109 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo7aO7906 __t5IbK109 _00024seq2) (join $seq_at (1 0 2) 3 _00024sqo8pFe907 __t5IbK109 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo4hee909 __t5IbK109 _00024seq2) (exists _enum (1 0) 1 __tconst35Xg1071) (join delta (1 2 0) 2 __tconst3u5R106 _00024seq2 __t8l3B107) (join _enum (1 0) 1 __tconst35Xg1071 __t6gQ5104) (join boolval (0 1) 1 __t5IbK109 b) (letp _00024sql6c1M901 (aslst _00024seq2)) (let chk9DaV1967 (llen _00024sql6c1M901)) (eq _00024sqc9bdu903 chk9DaV1967) (letp chk0KTY1968 (lref _00024sql6c1M901 _00024sqc9U0q904)) (eq __t5IbK109 chk0KTY1968) (letp chk8hQU1969 (lref _00024sql6c1M901 _00024sqc3xmn905)) (eq __t5IbK109 chk8hQU1969)) (head (emit-temp temp1yql1955 __t8l3B107) (mkstruct boolval (1 0) __t274c105 __t6gQ5104)) interp.slog:122 #f)
  class ReadTask8 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex0;  slog::Index** $seq_atindex1;  slog::Index** $seq_atrindex2;  slog::Index** _enumindex3;  slog::Index** deltaindex4;  slog::Index** _enumindex5;  slog::Index** boolvalindex6;  slog::Index** $seq_atrdelta7;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp1yql1955");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord9({1, 0, 2});
      slog::Relation* readrel10 = db->getRelation("$seq_atr");
      driver_index = readrel10->getIndex(ord9, true);
      std::vector<u16> ord11({1, 0, 2});
      slog::Relation* readrel12 = db->getRelation("$seq_at");
      $seq_atindex0 = readrel12->getIndex(ord11, false);
      std::vector<u16> ord13({1, 0, 2});
      slog::Relation* readrel14 = db->getRelation("$seq_at");
      $seq_atindex1 = readrel14->getIndex(ord13, false);
      std::vector<u16> ord15({1, 0, 2});
      slog::Relation* readrel16 = db->getRelation("$seq_atr");
      $seq_atrindex2 = readrel16->getIndex(ord15, false);
      std::vector<u16> ord17({1, 0, 2});
      slog::Relation* readrel18 = db->getRelation("$seq_atr");
      $seq_atrdelta7 = readrel18->getIndex(ord17, true);
      std::vector<u16> ord19({1, 0});
      slog::Relation* readrel20 = db->getRelation("_enum");
      _enumindex3 = readrel20->getIndex(ord19, false);
      std::vector<u16> ord21({1, 2, 0});
      slog::Relation* readrel22 = db->getRelation("delta");
      deltaindex4 = readrel22->getIndex(ord21, false);
      std::vector<u16> ord23({1, 0});
      slog::Relation* readrel24 = db->getRelation("_enum");
      _enumindex5 = readrel24->getIndex(ord23, false);
      std::vector<u16> ord25({0, 1});
      slog::Relation* readrel26 = db->getRelation("boolval");
      boolvalindex6 = readrel26->getIndex(ord25, false);
  
    }
    ReadTask8(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c1 = v_const06abaa100ecef791ce028c56;
      u64 v_c2 = v_constd4735e3a265e16eee03f5971;
      u64 v_c3 = v_const5feceb66ffc86f38d952786c;
      u64 v_c4 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c5 = v_const5feceb66ffc86f38d952786c;
      u64 v_c6 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c7 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c8 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c7, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m27) {
        u64 v_c9 = m27[1];
        u64 v_c10 = m27[2];
        if (buckethash(v_c9) != bucket) return;
        slog::join_probe<3,3>($seq_atindex0, std::array<u64,3>{v_c5, v_c9, v_c10}, [&](const std::array<u64,3>& m28) {
          slog::join_probe<3,3>($seq_atindex1, std::array<u64,3>{v_c6, v_c9, v_c10}, [&](const std::array<u64,3>& m29) {
            slog::join_probe_old<3,3>($seq_atrindex2, $seq_atrdelta7, std::array<u64,3>{v_c8, v_c9, v_c10}, [&](const std::array<u64,3>& m30) {
              if (!slog::exists_probe<2,1>(_enumindex3, std::array<u64,2>{v_c0, 0})) return;
              slog::join_probe<3,2>(deltaindex4, std::array<u64,3>{v_c1, v_c10, 0}, [&](const std::array<u64,3>& m31) {
                u64 v_c11 = m31[2];
                slog::join_probe<2,1>(_enumindex5, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m32) {
                  u64 v_c12 = m32[1];
                  slog::join_probe<2,1>(boolvalindex6, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m33) {
                    u64 v_c13 = m33[1];
                    bool ok34 = true;
                    u64 v_c14 = _prim_aslst(db, v_c10, &ok34);
                    if (!ok34) return;
                    u64 v_c15 = _prim_llen(db, v_c14);
                    if (v_c15 == slog_error) { slog::emit_pending_error(db, "interp.slog:122"); return; }
                    if (v_c2 != v_c15) return;
                    bool ok35 = true;
                    u64 v_c16 = _prim_lref(db, v_c14, v_c3, &ok35);
                    if (!ok35) return;
                    if (v_c9 != v_c16) return;
                    bool ok36 = true;
                    u64 v_c17 = _prim_lref(db, v_c14, v_c4, &ok36);
                    if (!ok36) return;
                    if (v_c9 != v_c17) return;
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c11});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c12}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:122", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask8* _cont = new ReadTask8(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask8(db,b), false);
  // (crule (pre (let __trid9BBj1454 const1b2483991f3f37e4463261cd) (let __trel6r6b1455 const1064263932db82f2cf6d4ac2) (let __tcol2VgI1456 const5feceb66ffc86f38d952786c) (let __trel3pfc1457 const1064263932db82f2cf6d4ac2) (let __tcol2rsw1458 const6b86b273ff34fce19d6b804e)) (scan $sup5638x40x0x0x1 __d0 __d1 k l m p r v) (body) (head (tycheck l (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid9BBj1454 __trel6r6b1455 __tcol2VgI1456 (1 2 3 4 0)) (tycheck k (accept int) __trid9BBj1454 __trel3pfc1457 __tcol2rsw1458 (1 2 3 4 0)) (mkstruct mp_put (1 2 3 0) __2dPB1453 l k v)) map.slog:41 #f)
  class ReadTask40 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid38;  u32 sid37;  u32 sid39;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("mp_put");
      outer_rel = db->getRelation("$sup5638x40x0x0x1");
      sid38 = db->getRelation("_enum")->getStructId();
      sid37 = db->getRelation("mbranch")->getStructId();
      sid39 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask40(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c18 = v_const1b2483991f3f37e4463261cd;
      u64 v_c19 = v_const1064263932db82f2cf6d4ac2;
      u64 v_c20 = v_const5feceb66ffc86f38d952786c;
      u64 v_c21 = v_const1064263932db82f2cf6d4ac2;
      u64 v_c22 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c23 = _t[0];
        u64 v_c24 = _t[1];
        u64 v_c25 = _t[2];
        u64 v_c26 = _t[3];
        u64 v_c27 = _t[4];
        u64 v_c28 = _t[5];
        u64 v_c29 = _t[6];
        u64 v_c30 = _t[7];
        ++_fires;
        if (!((is_struct(v_c26) && (decode_struct_id(v_c26) == sid37 || decode_struct_id(v_c26) == sid38 || decode_struct_id(v_c26) == sid39))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c18, v_c19, v_c20, v_c26}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c25)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c18, v_c21, v_c22, v_c25}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<4>(head_rel[2], newbatch[2], std::array<u64,3>{v_c26, v_c25, v_c30}, std::array<u16,4>{1, 2, 3, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:41", "delta:$sup5638x40x0x0x1", _fires);
  
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
  // (crule (pre (let __tconst49Ln1134 constd01925b37634a1a9d24159d8) (let _00024sqc3J0X912 const5feceb66ffc86f38d952786c)) (probe _enum (1 0) 1 __tconst49Ln1134 __t398w689) (body (join mp_fromlist (0 1) 0 __t12Lo690 _00024seq0) (letp _00024sql2i9s910 (aslst _00024seq0)) (let chk9NYO2050 (llen _00024sql2i9s910)) (eq _00024sqc3J0X912 chk9NYO2050)) (head (emit mp_fromlist_ans (1 0) __t398w689 __t12Lo690)) map.slog:127 #f)
  class ReadTask42 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** mp_fromlistindex41;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_fromlist_ans");
      std::vector<u16> ord43({1, 0});
      slog::Relation* readrel44 = db->getRelation("mp_fromlist_ans");
      head_index[0] = readrel44->getIndex(ord43, false);
      std::vector<u16> ord45({1, 0});
      slog::Relation* readrel46 = db->getRelation("_enum");
      driver_index = readrel46->getIndex(ord45, true);
      std::vector<u16> ord47({0, 1});
      slog::Relation* readrel48 = db->getRelation("mp_fromlist");
      mp_fromlistindex41 = readrel48->getIndex(ord47, false);
  
    }
    ReadTask42(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c31 = v_constd01925b37634a1a9d24159d8;
      u64 v_c32 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c31, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m49) {
        u64 v_c33 = m49[1];
        if (buckethash(v_c33) != bucket) return;
        slog::join_all<2>(mp_fromlistindex41, [&](const std::array<u64,2>& m50) {
          u64 v_c34 = m50[0]; u64 v_c35 = m50[1];
          bool ok51 = true;
          u64 v_c36 = _prim_aslst(db, v_c35, &ok51);
          if (!ok51) return;
          u64 v_c37 = _prim_llen(db, v_c36);
          if (v_c37 == slog_error) { slog::emit_pending_error(db, "map.slog:127"); return; }
          if (v_c32 != v_c37) return;
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c33, v_c34}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:127", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask42* _cont = new ReadTask42(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask42(db,b), true);
  // (crule (pre (let __tconst5vD0184 const4a44dc15364204a80fe80e90) (let __tconst5BWV176 const6b51d431df5d7f141cbececc)) (scan temp4DFq1995 __t2pQQ168 __t9GVo175 __t9kRL183) (body (join let (1 2 3 0) 3 __tconst5BWV176 __t9GVo175 __t2pQQ168 __t9uEv177)) (head (emit-temp temp7ay71996 __t9kRL183 __t9uEv177) (mkstruct let (1 2 3 0) __t7w5s185 __tconst5vD0184 __t9kRL183 __t9uEv177)) kcfa.slog:29 #f)
  class ReadTask53 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letindex52;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7ay71996");
      head_rel[1] = db->getRelation("let");
      outer_rel = db->getRelation("temp4DFq1995");
      std::vector<u16> ord54({1, 2, 3, 0});
      slog::Relation* readrel55 = db->getRelation("let");
      letindex52 = readrel55->getIndex(ord54, false);
  
    }
    ReadTask53(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c38 = v_const4a44dc15364204a80fe80e90;
      u64 v_c39 = v_const6b51d431df5d7f141cbececc;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c40 = _t[0];
        u64 v_c41 = _t[1];
        u64 v_c42 = _t[2];
        slog::join_probe<4,3>(letindex52, std::array<u64,4>{v_c39, v_c41, v_c40, 0}, [&](const std::array<u64,4>& m56) {
          u64 v_c43 = m56[3];
          ++_fires;
          slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c42, v_c43});
          slog::emit_struct<4>(head_rel[1], newbatch[1], std::array<u64,3>{v_c38, v_c42, v_c43}, std::array<u16,4>{1, 2, 3, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("kcfa.slog:29", "delta:temp4DFq1995", _fires);
  
      if (!_done)
      {
        ReadTask53* _cont = new ReadTask53(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask53(db,b), false);
  // (crule (pre) (scan temp53kK1916 l m p r v) (body (join mbranch (1 2 3 4 0) 4 p m l r __t4yht230)) (head (mkstruct mp_union (1 2 0) __44Tn1284 __t4yht230 v)) map.slog:108 #f)
  class ReadTask58 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex57;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union");
      outer_rel = db->getRelation("temp53kK1916");
      std::vector<u16> ord59({1, 2, 3, 4, 0});
      slog::Relation* readrel60 = db->getRelation("mbranch");
      mbranchindex57 = readrel60->getIndex(ord59, false);
  
    }
    ReadTask58(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c27 = _t[1];
        u64 v_c28 = _t[2];
        u64 v_c29 = _t[3];
        u64 v_c30 = _t[4];
        slog::join_probe<5,4>(mbranchindex57, std::array<u64,5>{v_c28, v_c27, v_c26, v_c29, 0}, [&](const std::array<u64,5>& m61) {
          u64 v_c44 = m61[4];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c44, v_c30}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:108", "delta:temp53kK1916", _fires);
  
      if (!_done)
      {
        ReadTask58* _cont = new ReadTask58(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask58(db,b), false);
  // (crule (pre (let __tconst00GP779 const6b86b273ff34fce19d6b804e)) (probe mp_has0_ans (1 0) 1 __tconst00GP779 __t3FES778) (body (join-old mp_has0 (0 2 1) 1 (0 2 1) __t3FES778 k t) (exists mp_put_soft (1 2 3 0) 2 t k) (join-old $sup5638x67x0x0x0 (1 2 0 3) 2 (1 2 0 3) k t __t8RYZ777 v) (join-old mp_put_soft (1 2 3 0) 4 (1 2 3 0) t k v __t8RYZ777)) (head (emit mp_put_soft_ans (0 1) __t8RYZ777 t)) map.slog:68 #f)
  class ReadTask69 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** mp_has0index62;  slog::Index** mp_put_softindex63;  slog::Index** $sup5638x67x0x0x0index64;  slog::Index** mp_put_softindex65;  slog::Index** mp_has0delta66;  slog::Index** $sup5638x67x0x0x0delta67;  slog::Index** mp_put_softdelta68;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_soft_ans");
      std::vector<u16> ord70({0, 1});
      slog::Relation* readrel71 = db->getRelation("mp_put_soft_ans");
      head_index[0] = readrel71->getIndex(ord70, false);
      std::vector<u16> ord72({1, 0});
      slog::Relation* readrel73 = db->getRelation("mp_has0_ans");
      driver_index = readrel73->getIndex(ord72, true);
      std::vector<u16> ord74({0, 2, 1});
      slog::Relation* readrel75 = db->getRelation("mp_has0");
      mp_has0index62 = readrel75->getIndex(ord74, false);
      std::vector<u16> ord76({0, 2, 1});
      slog::Relation* readrel77 = db->getRelation("mp_has0");
      mp_has0delta66 = readrel77->getIndex(ord76, true);
      std::vector<u16> ord78({1, 2, 3, 0});
      slog::Relation* readrel79 = db->getRelation("mp_put_soft");
      mp_put_softindex63 = readrel79->getIndex(ord78, false);
      std::vector<u16> ord80({1, 2, 0, 3});
      slog::Relation* readrel81 = db->getRelation("$sup5638x67x0x0x0");
      $sup5638x67x0x0x0index64 = readrel81->getIndex(ord80, false);
      std::vector<u16> ord82({1, 2, 0, 3});
      slog::Relation* readrel83 = db->getRelation("$sup5638x67x0x0x0");
      $sup5638x67x0x0x0delta67 = readrel83->getIndex(ord82, true);
      std::vector<u16> ord84({1, 2, 3, 0});
      slog::Relation* readrel85 = db->getRelation("mp_put_soft");
      mp_put_softindex65 = readrel85->getIndex(ord84, false);
      std::vector<u16> ord86({1, 2, 3, 0});
      slog::Relation* readrel87 = db->getRelation("mp_put_soft");
      mp_put_softdelta68 = readrel87->getIndex(ord86, true);
  
    }
    ReadTask69(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c45 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c45, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m88) {
        u64 v_c46 = m88[1];
        if (buckethash(v_c46) != bucket) return;
        slog::join_probe_old<3,1>(mp_has0index62, mp_has0delta66, std::array<u64,3>{v_c46, 0, 0}, [&](const std::array<u64,3>& m89) {
          u64 v_c25 = m89[1]; u64 v_c47 = m89[2];
          if (!slog::exists_probe<4,2>(mp_put_softindex63, std::array<u64,4>{v_c47, v_c25, 0, 0})) return;
          slog::join_probe_old<4,2>($sup5638x67x0x0x0index64, $sup5638x67x0x0x0delta67, std::array<u64,4>{v_c25, v_c47, 0, 0}, [&](const std::array<u64,4>& m90) {
            u64 v_c48 = m90[2]; u64 v_c30 = m90[3];
            slog::join_probe_old<4,4>(mp_put_softindex65, mp_put_softdelta68, std::array<u64,4>{v_c47, v_c25, v_c30, v_c48}, [&](const std::array<u64,4>& m91) {
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c48, v_c47}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:68", "delta:mp_has0_ans", _fires);
  
      if (!_done)
      {
        ReadTask69* _cont = new ReadTask69(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask69(db,b), false);
  // (crule (pre (let __tconst2mJz511 constf5ca38f748a1d6eaf726b8a4) (let __tconst6GsZ491 consted725292f5f32d61535958c1) (let __tconst0Ob1494 const6b86b273ff34fce19d6b804e)) (scan temp2A5g2006 __t0Vtj505 __t0cTh509 __t0f2O482 __t2zNy470 __t3yjA501) (body (exists num (1 0) 1 __tconst0Ob1494) (exists ref (1 0) 1 __tconst2mJz511) (exists app (2 0 1) 1 __t0f2O482) (join primref (1 0) 1 __tconst6GsZ491 __t3x0f492) (join num (1 0) 1 __tconst0Ob1494 __t1oVV472) (join ref (1 0) 1 __tconst2mJz511 __t1y5d469) (join app (1 2 0) 2 __t1y5d469 __t0f2O482 __t2wOF485) (let __t9oQ4490 (lpush __t3yjA501 __t2wOF485))) (head (emit-temp temp65cH2007 __t0Vtj505 __t0cTh509 __t2zNy470 __t9oQ4490)) kcfa.slog:40 #f)
  class ReadTask99 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** numindex92;  slog::Index** refindex93;  slog::Index** appindex94;  slog::Index** primrefindex95;  slog::Index** numindex96;  slog::Index** refindex97;  slog::Index** appindex98;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp65cH2007");
      outer_rel = db->getRelation("temp2A5g2006");
      std::vector<u16> ord100({1, 0});
      slog::Relation* readrel101 = db->getRelation("num");
      numindex92 = readrel101->getIndex(ord100, false);
      std::vector<u16> ord102({1, 0});
      slog::Relation* readrel103 = db->getRelation("ref");
      refindex93 = readrel103->getIndex(ord102, false);
      std::vector<u16> ord104({2, 0, 1});
      slog::Relation* readrel105 = db->getRelation("app");
      appindex94 = readrel105->getIndex(ord104, false);
      std::vector<u16> ord106({1, 0});
      slog::Relation* readrel107 = db->getRelation("primref");
      primrefindex95 = readrel107->getIndex(ord106, false);
      std::vector<u16> ord108({1, 0});
      slog::Relation* readrel109 = db->getRelation("num");
      numindex96 = readrel109->getIndex(ord108, false);
      std::vector<u16> ord110({1, 0});
      slog::Relation* readrel111 = db->getRelation("ref");
      refindex97 = readrel111->getIndex(ord110, false);
      std::vector<u16> ord112({1, 2, 0});
      slog::Relation* readrel113 = db->getRelation("app");
      appindex98 = readrel113->getIndex(ord112, false);
  
    }
    ReadTask99(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c49 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c50 = v_consted725292f5f32d61535958c1;
      u64 v_c51 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c52 = _t[0];
        u64 v_c53 = _t[1];
        u64 v_c54 = _t[2];
        u64 v_c55 = _t[3];
        u64 v_c56 = _t[4];
        if (!slog::exists_probe<2,1>(numindex92, std::array<u64,2>{v_c51, 0})) return;
        if (!slog::exists_probe<2,1>(refindex93, std::array<u64,2>{v_c49, 0})) return;
        if (!slog::exists_probe<3,1>(appindex94, std::array<u64,3>{v_c54, 0, 0})) return;
        slog::join_probe<2,1>(primrefindex95, std::array<u64,2>{v_c50, 0}, [&](const std::array<u64,2>& m114) {
          u64 v_c57 = m114[1];
          slog::join_probe<2,1>(numindex96, std::array<u64,2>{v_c51, 0}, [&](const std::array<u64,2>& m115) {
            u64 v_c58 = m115[1];
            slog::join_probe<2,1>(refindex97, std::array<u64,2>{v_c49, 0}, [&](const std::array<u64,2>& m116) {
              u64 v_c59 = m116[1];
              slog::join_probe<3,2>(appindex98, std::array<u64,3>{v_c59, v_c54, 0}, [&](const std::array<u64,3>& m117) {
                u64 v_c60 = m117[2];
                u64 v_c61 = _prim_lpush(db, v_c56, v_c60);
                if (v_c61 == slog_error) { slog::emit_pending_error(db, "kcfa.slog:40"); return; }
                ++_fires;
                slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c52, v_c53, v_c55, v_c61});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("kcfa.slog:40", "delta:temp2A5g2006", _fires);
  
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
  // (crule (pre) (scan mp_put_soft __t5GLK605 s k v) (body (exists mp_union (1 2 0) 1 s) (exists mp_put_soft_ans (0 1) 1 __t5GLK605) (join mleaf (1 2 0) 2 k v __t5Ivz603) (join mp_union (1 2 0) 2 s __t5Ivz603 __t7E2l604) (join mp_put_soft_ans (0 1) 1 __t5GLK605 r)) (head (emit mp_union_ans (0 1) __t7E2l604 r)) map.slog:93 #f)
  class ReadTask123 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex118;  slog::Index** mp_put_soft_ansindex119;  slog::Index** mleafindex120;  slog::Index** mp_unionindex121;  slog::Index** mp_put_soft_ansindex122;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord124({0, 1});
      slog::Relation* readrel125 = db->getRelation("mp_union_ans");
      head_index[0] = readrel125->getIndex(ord124, false);
      outer_rel = db->getRelation("mp_put_soft");
      std::vector<u16> ord126({1, 2, 0});
      slog::Relation* readrel127 = db->getRelation("mp_union");
      mp_unionindex118 = readrel127->getIndex(ord126, false);
      std::vector<u16> ord128({0, 1});
      slog::Relation* readrel129 = db->getRelation("mp_put_soft_ans");
      mp_put_soft_ansindex119 = readrel129->getIndex(ord128, false);
      std::vector<u16> ord130({1, 2, 0});
      slog::Relation* readrel131 = db->getRelation("mleaf");
      mleafindex120 = readrel131->getIndex(ord130, false);
      std::vector<u16> ord132({1, 2, 0});
      slog::Relation* readrel133 = db->getRelation("mp_union");
      mp_unionindex121 = readrel133->getIndex(ord132, false);
      std::vector<u16> ord134({0, 1});
      slog::Relation* readrel135 = db->getRelation("mp_put_soft_ans");
      mp_put_soft_ansindex122 = readrel135->getIndex(ord134, false);
  
    }
    ReadTask123(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c63 = _t[1];
        u64 v_c25 = _t[2];
        u64 v_c30 = _t[3];
        if (!slog::exists_probe<3,1>(mp_unionindex118, std::array<u64,3>{v_c63, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_put_soft_ansindex119, std::array<u64,2>{v_c62, 0})) return;
        slog::join_probe<3,2>(mleafindex120, std::array<u64,3>{v_c25, v_c30, 0}, [&](const std::array<u64,3>& m136) {
          u64 v_c64 = m136[2];
          slog::join_probe<3,2>(mp_unionindex121, std::array<u64,3>{v_c63, v_c64, 0}, [&](const std::array<u64,3>& m137) {
            u64 v_c65 = m137[2];
            slog::join_probe<2,1>(mp_put_soft_ansindex122, std::array<u64,2>{v_c62, 0}, [&](const std::array<u64,2>& m138) {
              u64 v_c29 = m138[1];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c65, v_c29}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:93", "delta:mp_put_soft", _fires);
  
      if (!_done)
      {
        ReadTask123* _cont = new ReadTask123(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask123(db,b), false);
  // (crule (pre (let __tconst9a82241 const6b86b273ff34fce19d6b804e)) (scan mp_msk __t0CZp243 k m) (body (exists $sup5638x40x0x0x0 (1 3 4 0 2 5 6) 2 k m) (exists mbranch (2 0 1 3 4) 1 m) (exists mp_put (2 3 0 1) 1 k) (exists mp_msk_ans (0 1) 1 __t0CZp243) (join $sup5638x40x0x0x1 (1 2 4 5 0 3 6 7) 3 __t0CZp243 k m p __t8K90240 l r v) (join $sup5638x40x0x0x0 (4 2 3 5 0 1 6) 7 p l m r __t8K90240 k v) (exists mp_put (3 0 2 1) 3 v __t8K90240 k) (exists mp_put (1 2 3 0) 3 l k v) (exists mp_msk_ans (0 1) 2 __t0CZp243 p) (join mbranch (1 2 3 4 0) 4 p m l r __t3kyC239) (join mp_put (0 2 1 3) 4 __t8K90240 k __t3kyC239 v) (join-old mp_put (1 2 3 0) 3 (1 2 3 0) l k v __t630X244) (join mp_msk_ans (0 1) 2 __t0CZp243 p) (join mp_put_ans (0 1) 1 __t630X244 __v0) (let __t9Ap1242 (band k m)) (cmp lt __t9Ap1242 __tconst9a82241)) (head (emit-temp temp636D1974 __t8K90240 __v0 m p r) (mkstruct mbranch (1 2 3 4 0) __t2hPi238 p m __v0 r)) map.slog:41 #f)
  class ReadTask154 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x40x0x0x0index139;  slog::Index** mbranchindex140;  slog::Index** mp_putindex141;  slog::Index** mp_msk_ansindex142;  slog::Index** $sup5638x40x0x0x1index143;  slog::Index** $sup5638x40x0x0x0index144;  slog::Index** mp_putindex145;  slog::Index** mp_putindex146;  slog::Index** mp_msk_ansindex147;  slog::Index** mbranchindex148;  slog::Index** mp_putindex149;  slog::Index** mp_putindex150;  slog::Index** mp_msk_ansindex151;  slog::Index** mp_put_ansindex152;  slog::Index** mp_putdelta153;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp636D1974");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_msk");
      std::vector<u16> ord155({1, 3, 4, 0, 2, 5, 6});
      slog::Relation* readrel156 = db->getRelation("$sup5638x40x0x0x0");
      $sup5638x40x0x0x0index139 = readrel156->getIndex(ord155, false);
      std::vector<u16> ord157({2, 0, 1, 3, 4});
      slog::Relation* readrel158 = db->getRelation("mbranch");
      mbranchindex140 = readrel158->getIndex(ord157, false);
      std::vector<u16> ord159({2, 3, 0, 1});
      slog::Relation* readrel160 = db->getRelation("mp_put");
      mp_putindex141 = readrel160->getIndex(ord159, false);
      std::vector<u16> ord161({0, 1});
      slog::Relation* readrel162 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex142 = readrel162->getIndex(ord161, false);
      std::vector<u16> ord163({1, 2, 4, 5, 0, 3, 6, 7});
      slog::Relation* readrel164 = db->getRelation("$sup5638x40x0x0x1");
      $sup5638x40x0x0x1index143 = readrel164->getIndex(ord163, false);
      std::vector<u16> ord165({4, 2, 3, 5, 0, 1, 6});
      slog::Relation* readrel166 = db->getRelation("$sup5638x40x0x0x0");
      $sup5638x40x0x0x0index144 = readrel166->getIndex(ord165, false);
      std::vector<u16> ord167({3, 0, 2, 1});
      slog::Relation* readrel168 = db->getRelation("mp_put");
      mp_putindex145 = readrel168->getIndex(ord167, false);
      std::vector<u16> ord169({1, 2, 3, 0});
      slog::Relation* readrel170 = db->getRelation("mp_put");
      mp_putindex146 = readrel170->getIndex(ord169, false);
      std::vector<u16> ord171({0, 1});
      slog::Relation* readrel172 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex147 = readrel172->getIndex(ord171, false);
      std::vector<u16> ord173({1, 2, 3, 4, 0});
      slog::Relation* readrel174 = db->getRelation("mbranch");
      mbranchindex148 = readrel174->getIndex(ord173, false);
      std::vector<u16> ord175({0, 2, 1, 3});
      slog::Relation* readrel176 = db->getRelation("mp_put");
      mp_putindex149 = readrel176->getIndex(ord175, false);
      std::vector<u16> ord177({1, 2, 3, 0});
      slog::Relation* readrel178 = db->getRelation("mp_put");
      mp_putindex150 = readrel178->getIndex(ord177, false);
      std::vector<u16> ord179({1, 2, 3, 0});
      slog::Relation* readrel180 = db->getRelation("mp_put");
      mp_putdelta153 = readrel180->getIndex(ord179, true);
      std::vector<u16> ord181({0, 1});
      slog::Relation* readrel182 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex151 = readrel182->getIndex(ord181, false);
      std::vector<u16> ord183({0, 1});
      slog::Relation* readrel184 = db->getRelation("mp_put_ans");
      mp_put_ansindex152 = readrel184->getIndex(ord183, false);
  
    }
    ReadTask154(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c66 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c67 = _t[0];
        u64 v_c25 = _t[1];
        u64 v_c27 = _t[2];
        if (!slog::exists_probe<7,2>($sup5638x40x0x0x0index139, std::array<u64,7>{v_c25, v_c27, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex140, std::array<u64,5>{v_c27, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(mp_putindex141, std::array<u64,4>{v_c25, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex142, std::array<u64,2>{v_c67, 0})) return;
        slog::join_probe<8,3>($sup5638x40x0x0x1index143, std::array<u64,8>{v_c67, v_c25, v_c27, 0, 0, 0, 0, 0}, [&](const std::array<u64,8>& m185) {
          u64 v_c28 = m185[3]; u64 v_c68 = m185[4]; u64 v_c26 = m185[5]; u64 v_c29 = m185[6]; u64 v_c30 = m185[7];
          slog::join_probe<7,7>($sup5638x40x0x0x0index144, std::array<u64,7>{v_c28, v_c26, v_c27, v_c29, v_c68, v_c25, v_c30}, [&](const std::array<u64,7>& m186) {
            if (!slog::exists_probe<4,3>(mp_putindex145, std::array<u64,4>{v_c30, v_c68, v_c25, 0})) return;
            if (!slog::exists_probe<4,3>(mp_putindex146, std::array<u64,4>{v_c26, v_c25, v_c30, 0})) return;
            if (!slog::exists_probe<2,2>(mp_msk_ansindex147, std::array<u64,2>{v_c67, v_c28})) return;
            slog::join_probe<5,4>(mbranchindex148, std::array<u64,5>{v_c28, v_c27, v_c26, v_c29, 0}, [&](const std::array<u64,5>& m187) {
              u64 v_c69 = m187[4];
              slog::join_probe<4,4>(mp_putindex149, std::array<u64,4>{v_c68, v_c25, v_c69, v_c30}, [&](const std::array<u64,4>& m188) {
                slog::join_probe_old<4,3>(mp_putindex150, mp_putdelta153, std::array<u64,4>{v_c26, v_c25, v_c30, 0}, [&](const std::array<u64,4>& m189) {
                  u64 v_c70 = m189[3];
                  slog::join_probe<2,2>(mp_msk_ansindex151, std::array<u64,2>{v_c67, v_c28}, [&](const std::array<u64,2>& m190) {
                    slog::join_probe<2,1>(mp_put_ansindex152, std::array<u64,2>{v_c70, 0}, [&](const std::array<u64,2>& m191) {
                      u64 v_c71 = m191[1];
                      u64 v_c72 = _prim_band(db, v_c25, v_c27);
                      if (v_c72 == slog_error) { slog::emit_pending_error(db, "map.slog:41"); return; }
                      u64 v_c73 = _prim_lt(db, v_c72, v_c66);
                      if (v_c73 == slog_error) { slog::emit_pending_error(db, "map.slog:41"); return; }
                      if (!v_c73) return;
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c68, v_c71, v_c27, v_c28, v_c29});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c28, v_c27, v_c71, v_c29}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:41", "delta:mp_msk", _fires);
  
      if (!_done)
      {
        ReadTask154* _cont = new ReadTask154(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask154(db,b), false);
  // (crule (pre (let __tconst9a82241 const6b86b273ff34fce19d6b804e)) (scan mp_put __t8K90240 __t3kyC239 k v) (body (exists $sup5638x40x0x0x1 (0 2 7 1 3 4 5 6) 3 __t8K90240 k v) (exists mp_msk (1 2 0) 1 k) (exists mp_put (2 3 0 1) 2 k v) (join $sup5638x40x0x0x0 (0 1 6 2 3 4 5) 3 __t8K90240 k v l m p r) (exists mbranch (1 2 3 4 0) 5 p m l r __t3kyC239) (exists mp_msk (1 2 0) 2 k m) (exists mp_put (1 2 3 0) 3 l k v) (exists mp_msk_ans (1 0) 1 p) (join $sup5638x40x0x0x1 (3 4 5 6 0 2 7 1) 7 l m p r __t8K90240 k v __t0CZp243) (join mbranch (1 2 3 4 0) 5 p m l r __t3kyC239) (join-old mp_msk (1 2 0) 3 (1 2 0) k m __t0CZp243) (exists mp_msk_ans (0 1) 2 __t0CZp243 p) (join-old mp_put (1 2 3 0) 3 (1 2 3 0) l k v __t630X244) (join mp_msk_ans (0 1) 2 __t0CZp243 p) (join mp_put_ans (0 1) 1 __t630X244 __v0) (let __t9Ap1242 (band k m)) (cmp lt __t9Ap1242 __tconst9a82241)) (head (emit-temp temp636D1974 __t8K90240 __v0 m p r) (mkstruct mbranch (1 2 3 4 0) __t2hPi238 p m __v0 r)) map.slog:41 #f)
  class ReadTask210 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x40x0x0x1index193;  slog::Index** mp_mskindex194;  slog::Index** mp_putindex195;  slog::Index** $sup5638x40x0x0x0index196;  slog::Index** mbranchindex197;  slog::Index** mp_mskindex198;  slog::Index** mp_putindex199;  slog::Index** mp_msk_ansindex200;  slog::Index** $sup5638x40x0x0x1index201;  slog::Index** mbranchindex202;  slog::Index** mp_mskindex203;  slog::Index** mp_msk_ansindex204;  slog::Index** mp_putindex205;  slog::Index** mp_msk_ansindex206;  slog::Index** mp_put_ansindex207;  slog::Index** mp_mskdelta208;  slog::Index** mp_putdelta209;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp636D1974");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_put");
      std::vector<u16> ord211({0, 2, 7, 1, 3, 4, 5, 6});
      slog::Relation* readrel212 = db->getRelation("$sup5638x40x0x0x1");
      $sup5638x40x0x0x1index193 = readrel212->getIndex(ord211, false);
      std::vector<u16> ord213({1, 2, 0});
      slog::Relation* readrel214 = db->getRelation("mp_msk");
      mp_mskindex194 = readrel214->getIndex(ord213, false);
      std::vector<u16> ord215({2, 3, 0, 1});
      slog::Relation* readrel216 = db->getRelation("mp_put");
      mp_putindex195 = readrel216->getIndex(ord215, false);
      std::vector<u16> ord217({0, 1, 6, 2, 3, 4, 5});
      slog::Relation* readrel218 = db->getRelation("$sup5638x40x0x0x0");
      $sup5638x40x0x0x0index196 = readrel218->getIndex(ord217, false);
      std::vector<u16> ord219({1, 2, 3, 4, 0});
      slog::Relation* readrel220 = db->getRelation("mbranch");
      mbranchindex197 = readrel220->getIndex(ord219, false);
      std::vector<u16> ord221({1, 2, 0});
      slog::Relation* readrel222 = db->getRelation("mp_msk");
      mp_mskindex198 = readrel222->getIndex(ord221, false);
      std::vector<u16> ord223({1, 2, 3, 0});
      slog::Relation* readrel224 = db->getRelation("mp_put");
      mp_putindex199 = readrel224->getIndex(ord223, false);
      std::vector<u16> ord225({1, 0});
      slog::Relation* readrel226 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex200 = readrel226->getIndex(ord225, false);
      std::vector<u16> ord227({3, 4, 5, 6, 0, 2, 7, 1});
      slog::Relation* readrel228 = db->getRelation("$sup5638x40x0x0x1");
      $sup5638x40x0x0x1index201 = readrel228->getIndex(ord227, false);
      std::vector<u16> ord229({1, 2, 3, 4, 0});
      slog::Relation* readrel230 = db->getRelation("mbranch");
      mbranchindex202 = readrel230->getIndex(ord229, false);
      std::vector<u16> ord231({1, 2, 0});
      slog::Relation* readrel232 = db->getRelation("mp_msk");
      mp_mskindex203 = readrel232->getIndex(ord231, false);
      std::vector<u16> ord233({1, 2, 0});
      slog::Relation* readrel234 = db->getRelation("mp_msk");
      mp_mskdelta208 = readrel234->getIndex(ord233, true);
      std::vector<u16> ord235({0, 1});
      slog::Relation* readrel236 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex204 = readrel236->getIndex(ord235, false);
      std::vector<u16> ord237({1, 2, 3, 0});
      slog::Relation* readrel238 = db->getRelation("mp_put");
      mp_putindex205 = readrel238->getIndex(ord237, false);
      std::vector<u16> ord239({1, 2, 3, 0});
      slog::Relation* readrel240 = db->getRelation("mp_put");
      mp_putdelta209 = readrel240->getIndex(ord239, true);
      std::vector<u16> ord241({0, 1});
      slog::Relation* readrel242 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex206 = readrel242->getIndex(ord241, false);
      std::vector<u16> ord243({0, 1});
      slog::Relation* readrel244 = db->getRelation("mp_put_ans");
      mp_put_ansindex207 = readrel244->getIndex(ord243, false);
  
    }
    ReadTask210(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c66 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c69 = _t[1];
        u64 v_c25 = _t[2];
        u64 v_c30 = _t[3];
        if (!slog::exists_probe<8,3>($sup5638x40x0x0x1index193, std::array<u64,8>{v_c68, v_c25, v_c30, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex194, std::array<u64,3>{v_c25, 0, 0})) return;
        if (!slog::exists_probe<4,2>(mp_putindex195, std::array<u64,4>{v_c25, v_c30, 0, 0})) return;
        slog::join_probe<7,3>($sup5638x40x0x0x0index196, std::array<u64,7>{v_c68, v_c25, v_c30, 0, 0, 0, 0}, [&](const std::array<u64,7>& m245) {
          u64 v_c26 = m245[3]; u64 v_c27 = m245[4]; u64 v_c28 = m245[5]; u64 v_c29 = m245[6];
          if (!slog::exists_probe<5,5>(mbranchindex197, std::array<u64,5>{v_c28, v_c27, v_c26, v_c29, v_c69})) return;
          if (!slog::exists_probe<3,2>(mp_mskindex198, std::array<u64,3>{v_c25, v_c27, 0})) return;
          if (!slog::exists_probe<4,3>(mp_putindex199, std::array<u64,4>{v_c26, v_c25, v_c30, 0})) return;
          if (!slog::exists_probe<2,1>(mp_msk_ansindex200, std::array<u64,2>{v_c28, 0})) return;
          slog::join_probe<8,7>($sup5638x40x0x0x1index201, std::array<u64,8>{v_c26, v_c27, v_c28, v_c29, v_c68, v_c25, v_c30, 0}, [&](const std::array<u64,8>& m246) {
            u64 v_c67 = m246[7];
            slog::join_probe<5,5>(mbranchindex202, std::array<u64,5>{v_c28, v_c27, v_c26, v_c29, v_c69}, [&](const std::array<u64,5>& m247) {
              slog::join_probe_old<3,3>(mp_mskindex203, mp_mskdelta208, std::array<u64,3>{v_c25, v_c27, v_c67}, [&](const std::array<u64,3>& m248) {
                if (!slog::exists_probe<2,2>(mp_msk_ansindex204, std::array<u64,2>{v_c67, v_c28})) return;
                slog::join_probe_old<4,3>(mp_putindex205, mp_putdelta209, std::array<u64,4>{v_c26, v_c25, v_c30, 0}, [&](const std::array<u64,4>& m249) {
                  u64 v_c70 = m249[3];
                  slog::join_probe<2,2>(mp_msk_ansindex206, std::array<u64,2>{v_c67, v_c28}, [&](const std::array<u64,2>& m250) {
                    slog::join_probe<2,1>(mp_put_ansindex207, std::array<u64,2>{v_c70, 0}, [&](const std::array<u64,2>& m251) {
                      u64 v_c71 = m251[1];
                      u64 v_c72 = _prim_band(db, v_c25, v_c27);
                      if (v_c72 == slog_error) { slog::emit_pending_error(db, "map.slog:41"); return; }
                      u64 v_c74 = _prim_lt(db, v_c72, v_c66);
                      if (v_c74 == slog_error) { slog::emit_pending_error(db, "map.slog:41"); return; }
                      if (!v_c74) return;
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c68, v_c71, v_c27, v_c28, v_c29});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c28, v_c27, v_c71, v_c29}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:41", "delta:mp_put", _fires);
  
      if (!_done)
      {
        ReadTask210* _cont = new ReadTask210(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask210(db,b), false);
  // (crule (pre) (scan mp_has0 __t4ZKg610 __t0JuJ609 k) (body (join mbranch (0 1 2 3 4) 1 __t0JuJ609 p m l r)) (head (emit $sup5638x59x0x0x0 (0 1 2 3 4 5) __t4ZKg610 k l m p r)) map.slog:60 #f)
  class ReadTask254 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex253;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x59x0x0x0");
      std::vector<u16> ord255({0, 1, 2, 3, 4, 5});
      slog::Relation* readrel256 = db->getRelation("$sup5638x59x0x0x0");
      head_index[0] = readrel256->getIndex(ord255, false);
      outer_rel = db->getRelation("mp_has0");
      std::vector<u16> ord257({0, 1, 2, 3, 4});
      slog::Relation* readrel258 = db->getRelation("mbranch");
      mbranchindex253 = readrel258->getIndex(ord257, false);
  
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
        u64 v_c75 = _t[0];
        u64 v_c76 = _t[1];
        u64 v_c25 = _t[2];
        slog::join_probe<5,1>(mbranchindex253, std::array<u64,5>{v_c76, 0, 0, 0, 0}, [&](const std::array<u64,5>& m259) {
          u64 v_c28 = m259[1]; u64 v_c27 = m259[2]; u64 v_c26 = m259[3]; u64 v_c29 = m259[4];
          ++_fires;
          slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c75, v_c25, v_c26, v_c27, v_c28, v_c29}, std::array<u16,6>{0, 1, 2, 3, 4, 5});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:60", "delta:mp_has0", _fires);
  
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
  // (crule (pre) (scan mp_msk __t827P393 p n) (body (exists mbranch (1 2 3 4 0) 1 p) (exists $sup5638x110x0x0x0 (3 4 0 1 2 5 6 7 8 9 10) 2 n p) (exists mbranch (2 0 1 3 4) 1 n) (exists mp_join (1 2 3 4 0) 1 p) (join mp_msk_ans (0 1) 1 __t827P393 __v0) (join mbranch (1 2 3 4 0) 1 p m l r __t6AX6390) (cmp lt m n) (exists mp_join (1 2 3 4 0) 2 p __t6AX6390) (exists mp_union (1 2 0) 1 __t6AX6390) (join $sup5638x110x0x0x0 (1 2 4 6 7 3 0 5 8 9 10) 6 l m p r __t6AX6390 n __t5Qtl389 q __t46nL391 u v) (neq q __v0) (join mbranch (1 2 3 4 0) 5 q n u v __t46nL391) (exists mp_union (0 1 2) 3 __t5Qtl389 __t6AX6390 __t46nL391) (join mp_join (1 2 3 4 0) 4 p __t6AX6390 q __t46nL391 __t6UVn392) (join mp_union (0 1 2) 3 __t5Qtl389 __t6AX6390 __t46nL391) (join mp_join_ans (0 1) 1 __t6UVn392 res)) (head (emit mp_union_ans (0 1) __t5Qtl389 res)) map.slog:111 #f)
  class ReadTask274 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex260;  slog::Index** $sup5638x110x0x0x0index261;  slog::Index** mbranchindex262;  slog::Index** mp_joinindex263;  slog::Index** mp_msk_ansindex264;  slog::Index** mbranchindex265;  slog::Index** mp_joinindex266;  slog::Index** mp_unionindex267;  slog::Index** $sup5638x110x0x0x0index268;  slog::Index** mbranchindex269;  slog::Index** mp_unionindex270;  slog::Index** mp_joinindex271;  slog::Index** mp_unionindex272;  slog::Index** mp_join_ansindex273;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord275({0, 1});
      slog::Relation* readrel276 = db->getRelation("mp_union_ans");
      head_index[0] = readrel276->getIndex(ord275, false);
      outer_rel = db->getRelation("mp_msk");
      std::vector<u16> ord277({1, 2, 3, 4, 0});
      slog::Relation* readrel278 = db->getRelation("mbranch");
      mbranchindex260 = readrel278->getIndex(ord277, false);
      std::vector<u16> ord279({3, 4, 0, 1, 2, 5, 6, 7, 8, 9, 10});
      slog::Relation* readrel280 = db->getRelation("$sup5638x110x0x0x0");
      $sup5638x110x0x0x0index261 = readrel280->getIndex(ord279, false);
      std::vector<u16> ord281({2, 0, 1, 3, 4});
      slog::Relation* readrel282 = db->getRelation("mbranch");
      mbranchindex262 = readrel282->getIndex(ord281, false);
      std::vector<u16> ord283({1, 2, 3, 4, 0});
      slog::Relation* readrel284 = db->getRelation("mp_join");
      mp_joinindex263 = readrel284->getIndex(ord283, false);
      std::vector<u16> ord285({0, 1});
      slog::Relation* readrel286 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex264 = readrel286->getIndex(ord285, false);
      std::vector<u16> ord287({1, 2, 3, 4, 0});
      slog::Relation* readrel288 = db->getRelation("mbranch");
      mbranchindex265 = readrel288->getIndex(ord287, false);
      std::vector<u16> ord289({1, 2, 3, 4, 0});
      slog::Relation* readrel290 = db->getRelation("mp_join");
      mp_joinindex266 = readrel290->getIndex(ord289, false);
      std::vector<u16> ord291({1, 2, 0});
      slog::Relation* readrel292 = db->getRelation("mp_union");
      mp_unionindex267 = readrel292->getIndex(ord291, false);
      std::vector<u16> ord293({1, 2, 4, 6, 7, 3, 0, 5, 8, 9, 10});
      slog::Relation* readrel294 = db->getRelation("$sup5638x110x0x0x0");
      $sup5638x110x0x0x0index268 = readrel294->getIndex(ord293, false);
      std::vector<u16> ord295({1, 2, 3, 4, 0});
      slog::Relation* readrel296 = db->getRelation("mbranch");
      mbranchindex269 = readrel296->getIndex(ord295, false);
      std::vector<u16> ord297({0, 1, 2});
      slog::Relation* readrel298 = db->getRelation("mp_union");
      mp_unionindex270 = readrel298->getIndex(ord297, false);
      std::vector<u16> ord299({1, 2, 3, 4, 0});
      slog::Relation* readrel300 = db->getRelation("mp_join");
      mp_joinindex271 = readrel300->getIndex(ord299, false);
      std::vector<u16> ord301({0, 1, 2});
      slog::Relation* readrel302 = db->getRelation("mp_union");
      mp_unionindex272 = readrel302->getIndex(ord301, false);
      std::vector<u16> ord303({0, 1});
      slog::Relation* readrel304 = db->getRelation("mp_join_ans");
      mp_join_ansindex273 = readrel304->getIndex(ord303, false);
  
    }
    ReadTask274(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c28 = _t[1];
        u64 v_c78 = _t[2];
        if (!slog::exists_probe<5,1>(mbranchindex260, std::array<u64,5>{v_c28, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<11,2>($sup5638x110x0x0x0index261, std::array<u64,11>{v_c78, v_c28, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex262, std::array<u64,5>{v_c78, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mp_joinindex263, std::array<u64,5>{v_c28, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(mp_msk_ansindex264, std::array<u64,2>{v_c77, 0}, [&](const std::array<u64,2>& m305) {
          u64 v_c71 = m305[1];
          slog::join_probe<5,1>(mbranchindex265, std::array<u64,5>{v_c28, 0, 0, 0, 0}, [&](const std::array<u64,5>& m306) {
            u64 v_c27 = m306[1]; u64 v_c26 = m306[2]; u64 v_c29 = m306[3]; u64 v_c79 = m306[4];
            u64 v_c80 = _prim_lt(db, v_c27, v_c78);
            if (v_c80 == slog_error) { slog::emit_pending_error(db, "map.slog:111"); return; }
            if (!v_c80) return;
            if (!slog::exists_probe<5,2>(mp_joinindex266, std::array<u64,5>{v_c28, v_c79, 0, 0, 0})) return;
            if (!slog::exists_probe<3,1>(mp_unionindex267, std::array<u64,3>{v_c79, 0, 0})) return;
            slog::join_probe<11,6>($sup5638x110x0x0x0index268, std::array<u64,11>{v_c26, v_c27, v_c28, v_c29, v_c79, v_c78, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m308) {
              u64 v_c81 = m308[6]; u64 v_c82 = m308[7]; u64 v_c83 = m308[8]; u64 v_c84 = m308[9]; u64 v_c30 = m308[10];
              if (v_c82 == v_c71) return;
              slog::join_probe<5,5>(mbranchindex269, std::array<u64,5>{v_c82, v_c78, v_c84, v_c30, v_c83}, [&](const std::array<u64,5>& m309) {
                if (!slog::exists_probe<3,3>(mp_unionindex270, std::array<u64,3>{v_c81, v_c79, v_c83})) return;
                slog::join_probe<5,4>(mp_joinindex271, std::array<u64,5>{v_c28, v_c79, v_c82, v_c83, 0}, [&](const std::array<u64,5>& m310) {
                  u64 v_c85 = m310[4];
                  slog::join_probe<3,3>(mp_unionindex272, std::array<u64,3>{v_c81, v_c79, v_c83}, [&](const std::array<u64,3>& m311) {
                    slog::join_probe<2,1>(mp_join_ansindex273, std::array<u64,2>{v_c85, 0}, [&](const std::array<u64,2>& m312) {
                      u64 v_c86 = m312[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c81, v_c86}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:111", "delta:mp_msk", _fires);
  
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
  // (crule (pre) (scan eval_ans __t63JF360 v) (body (join-old eval (0 1 2 3) 1 (0 1 2 3) __t63JF360 eb rho2 t) (exists $sup70016x95x0x0x1 (2 5 6 3 0 1 4 7) 3 eb rho2 t) (exists $sup70016x95x0x0x0 (1 4 2 0 3 5) 2 eb t) (exists mp_put (3 0 2 1) 1 t) (exists letrec (3 0 1 2) 1 eb) (exists eval (3 1 0 2) 1 t) (exists mp_put_ans (1 0) 1 rho2) (join-old eval (2 3 0 1) 2 (2 3 0 1) rho2 t __t6HuT359 er) (exists $sup70016x95x0x0x0 (1 4 2 0 3 5) 3 eb t er) (exists letrec (2 3 0 1) 2 er eb) (exists eval_ans (0 1) 1 __t6HuT359) (join-old $sup70016x95x0x0x1 (2 5 6 3 0 1 4 7) 4 (2 5 6 3 0 1 4 7) eb rho2 t er __t7DhJ358 __t0Rig361 rho x) (join-old $sup70016x95x0x0x0 (0 3 4 1 2 5) 6 (0 3 4 1 2 5) __t7DhJ358 rho t eb er x) (join-old mp_put (0 2 1 3) 4 (0 2 1 3) __t0Rig361 x rho t) (exists eval (2 3 0 1) 3 rho t __t7DhJ358) (exists mp_put_ans (0 1) 2 __t0Rig361 rho2) (join-old letrec (1 2 3 0) 3 (1 2 3 0) x er eb __t0Sks357) (join-old eval (2 3 0 1) 4 (2 3 0 1) rho t __t7DhJ358 __t0Sks357) (join-old mp_put_ans (0 1) 2 (0 1) __t0Rig361 rho2) (join eval_ans (0 1) 1 __t6HuT359 vr)) (head (emit eval_ans (0 1) __t7DhJ358 v)) interp.slog:96 #f)
  class ReadTask341 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex313;  slog::Index** $sup70016x95x0x0x1index314;  slog::Index** $sup70016x95x0x0x0index315;  slog::Index** mp_putindex316;  slog::Index** letrecindex317;  slog::Index** evalindex318;  slog::Index** mp_put_ansindex319;  slog::Index** evalindex320;  slog::Index** $sup70016x95x0x0x0index321;  slog::Index** letrecindex322;  slog::Index** eval_ansindex323;  slog::Index** $sup70016x95x0x0x1index324;  slog::Index** $sup70016x95x0x0x0index325;  slog::Index** mp_putindex326;  slog::Index** evalindex327;  slog::Index** mp_put_ansindex328;  slog::Index** letrecindex329;  slog::Index** evalindex330;  slog::Index** mp_put_ansindex331;  slog::Index** eval_ansindex332;  slog::Index** evaldelta333;  slog::Index** evaldelta334;  slog::Index** $sup70016x95x0x0x1delta335;  slog::Index** $sup70016x95x0x0x0delta336;  slog::Index** mp_putdelta337;  slog::Index** letrecdelta338;  slog::Index** evaldelta339;  slog::Index** mp_put_ansdelta340;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord342({0, 1});
      slog::Relation* readrel343 = db->getRelation("eval_ans");
      head_index[0] = readrel343->getIndex(ord342, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord344({0, 1, 2, 3});
      slog::Relation* readrel345 = db->getRelation("eval");
      evalindex313 = readrel345->getIndex(ord344, false);
      std::vector<u16> ord346({0, 1, 2, 3});
      slog::Relation* readrel347 = db->getRelation("eval");
      evaldelta333 = readrel347->getIndex(ord346, true);
      std::vector<u16> ord348({2, 5, 6, 3, 0, 1, 4, 7});
      slog::Relation* readrel349 = db->getRelation("$sup70016x95x0x0x1");
      $sup70016x95x0x0x1index314 = readrel349->getIndex(ord348, false);
      std::vector<u16> ord350({1, 4, 2, 0, 3, 5});
      slog::Relation* readrel351 = db->getRelation("$sup70016x95x0x0x0");
      $sup70016x95x0x0x0index315 = readrel351->getIndex(ord350, false);
      std::vector<u16> ord352({3, 0, 2, 1});
      slog::Relation* readrel353 = db->getRelation("mp_put");
      mp_putindex316 = readrel353->getIndex(ord352, false);
      std::vector<u16> ord354({3, 0, 1, 2});
      slog::Relation* readrel355 = db->getRelation("letrec");
      letrecindex317 = readrel355->getIndex(ord354, false);
      std::vector<u16> ord356({3, 1, 0, 2});
      slog::Relation* readrel357 = db->getRelation("eval");
      evalindex318 = readrel357->getIndex(ord356, false);
      std::vector<u16> ord358({1, 0});
      slog::Relation* readrel359 = db->getRelation("mp_put_ans");
      mp_put_ansindex319 = readrel359->getIndex(ord358, false);
      std::vector<u16> ord360({2, 3, 0, 1});
      slog::Relation* readrel361 = db->getRelation("eval");
      evalindex320 = readrel361->getIndex(ord360, false);
      std::vector<u16> ord362({2, 3, 0, 1});
      slog::Relation* readrel363 = db->getRelation("eval");
      evaldelta334 = readrel363->getIndex(ord362, true);
      std::vector<u16> ord364({1, 4, 2, 0, 3, 5});
      slog::Relation* readrel365 = db->getRelation("$sup70016x95x0x0x0");
      $sup70016x95x0x0x0index321 = readrel365->getIndex(ord364, false);
      std::vector<u16> ord366({2, 3, 0, 1});
      slog::Relation* readrel367 = db->getRelation("letrec");
      letrecindex322 = readrel367->getIndex(ord366, false);
      std::vector<u16> ord368({0, 1});
      slog::Relation* readrel369 = db->getRelation("eval_ans");
      eval_ansindex323 = readrel369->getIndex(ord368, false);
      std::vector<u16> ord370({2, 5, 6, 3, 0, 1, 4, 7});
      slog::Relation* readrel371 = db->getRelation("$sup70016x95x0x0x1");
      $sup70016x95x0x0x1index324 = readrel371->getIndex(ord370, false);
      std::vector<u16> ord372({2, 5, 6, 3, 0, 1, 4, 7});
      slog::Relation* readrel373 = db->getRelation("$sup70016x95x0x0x1");
      $sup70016x95x0x0x1delta335 = readrel373->getIndex(ord372, true);
      std::vector<u16> ord374({0, 3, 4, 1, 2, 5});
      slog::Relation* readrel375 = db->getRelation("$sup70016x95x0x0x0");
      $sup70016x95x0x0x0index325 = readrel375->getIndex(ord374, false);
      std::vector<u16> ord376({0, 3, 4, 1, 2, 5});
      slog::Relation* readrel377 = db->getRelation("$sup70016x95x0x0x0");
      $sup70016x95x0x0x0delta336 = readrel377->getIndex(ord376, true);
      std::vector<u16> ord378({0, 2, 1, 3});
      slog::Relation* readrel379 = db->getRelation("mp_put");
      mp_putindex326 = readrel379->getIndex(ord378, false);
      std::vector<u16> ord380({0, 2, 1, 3});
      slog::Relation* readrel381 = db->getRelation("mp_put");
      mp_putdelta337 = readrel381->getIndex(ord380, true);
      std::vector<u16> ord382({2, 3, 0, 1});
      slog::Relation* readrel383 = db->getRelation("eval");
      evalindex327 = readrel383->getIndex(ord382, false);
      std::vector<u16> ord384({0, 1});
      slog::Relation* readrel385 = db->getRelation("mp_put_ans");
      mp_put_ansindex328 = readrel385->getIndex(ord384, false);
      std::vector<u16> ord386({1, 2, 3, 0});
      slog::Relation* readrel387 = db->getRelation("letrec");
      letrecindex329 = readrel387->getIndex(ord386, false);
      std::vector<u16> ord388({1, 2, 3, 0});
      slog::Relation* readrel389 = db->getRelation("letrec");
      letrecdelta338 = readrel389->getIndex(ord388, true);
      std::vector<u16> ord390({2, 3, 0, 1});
      slog::Relation* readrel391 = db->getRelation("eval");
      evalindex330 = readrel391->getIndex(ord390, false);
      std::vector<u16> ord392({2, 3, 0, 1});
      slog::Relation* readrel393 = db->getRelation("eval");
      evaldelta339 = readrel393->getIndex(ord392, true);
      std::vector<u16> ord394({0, 1});
      slog::Relation* readrel395 = db->getRelation("mp_put_ans");
      mp_put_ansindex331 = readrel395->getIndex(ord394, false);
      std::vector<u16> ord396({0, 1});
      slog::Relation* readrel397 = db->getRelation("mp_put_ans");
      mp_put_ansdelta340 = readrel397->getIndex(ord396, true);
      std::vector<u16> ord398({0, 1});
      slog::Relation* readrel399 = db->getRelation("eval_ans");
      eval_ansindex332 = readrel399->getIndex(ord398, false);
  
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
        u64 v_c87 = _t[0];
        u64 v_c30 = _t[1];
        slog::join_probe_old<4,1>(evalindex313, evaldelta333, std::array<u64,4>{v_c87, 0, 0, 0}, [&](const std::array<u64,4>& m400) {
          u64 v_c88 = m400[1]; u64 v_c89 = m400[2]; u64 v_c47 = m400[3];
          if (!slog::exists_probe<8,3>($sup70016x95x0x0x1index314, std::array<u64,8>{v_c88, v_c89, v_c47, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<6,2>($sup70016x95x0x0x0index315, std::array<u64,6>{v_c88, v_c47, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<4,1>(mp_putindex316, std::array<u64,4>{v_c47, 0, 0, 0})) return;
          if (!slog::exists_probe<4,1>(letrecindex317, std::array<u64,4>{v_c88, 0, 0, 0})) return;
          if (!slog::exists_probe<4,1>(evalindex318, std::array<u64,4>{v_c47, 0, 0, 0})) return;
          if (!slog::exists_probe<2,1>(mp_put_ansindex319, std::array<u64,2>{v_c89, 0})) return;
          slog::join_probe_old<4,2>(evalindex320, evaldelta334, std::array<u64,4>{v_c89, v_c47, 0, 0}, [&](const std::array<u64,4>& m401) {
            u64 v_c90 = m401[2]; u64 v_c91 = m401[3];
            if (!slog::exists_probe<6,3>($sup70016x95x0x0x0index321, std::array<u64,6>{v_c88, v_c47, v_c91, 0, 0, 0})) return;
            if (!slog::exists_probe<4,2>(letrecindex322, std::array<u64,4>{v_c91, v_c88, 0, 0})) return;
            if (!slog::exists_probe<2,1>(eval_ansindex323, std::array<u64,2>{v_c90, 0})) return;
            slog::join_probe_old<8,4>($sup70016x95x0x0x1index324, $sup70016x95x0x0x1delta335, std::array<u64,8>{v_c88, v_c89, v_c47, v_c91, 0, 0, 0, 0}, [&](const std::array<u64,8>& m402) {
              u64 v_c92 = m402[4]; u64 v_c93 = m402[5]; u64 v_c94 = m402[6]; u64 v_c95 = m402[7];
              slog::join_probe_old<6,6>($sup70016x95x0x0x0index325, $sup70016x95x0x0x0delta336, std::array<u64,6>{v_c92, v_c94, v_c47, v_c88, v_c91, v_c95}, [&](const std::array<u64,6>& m403) {
                slog::join_probe_old<4,4>(mp_putindex326, mp_putdelta337, std::array<u64,4>{v_c93, v_c95, v_c94, v_c47}, [&](const std::array<u64,4>& m404) {
                  if (!slog::exists_probe<4,3>(evalindex327, std::array<u64,4>{v_c94, v_c47, v_c92, 0})) return;
                  if (!slog::exists_probe<2,2>(mp_put_ansindex328, std::array<u64,2>{v_c93, v_c89})) return;
                  slog::join_probe_old<4,3>(letrecindex329, letrecdelta338, std::array<u64,4>{v_c95, v_c91, v_c88, 0}, [&](const std::array<u64,4>& m405) {
                    u64 v_c96 = m405[3];
                    slog::join_probe_old<4,4>(evalindex330, evaldelta339, std::array<u64,4>{v_c94, v_c47, v_c92, v_c96}, [&](const std::array<u64,4>& m406) {
                      slog::join_probe_old<2,2>(mp_put_ansindex331, mp_put_ansdelta340, std::array<u64,2>{v_c93, v_c89}, [&](const std::array<u64,2>& m407) {
                        slog::join_probe<2,1>(eval_ansindex332, std::array<u64,2>{v_c90, 0}, [&](const std::array<u64,2>& m408) {
                          u64 v_c97 = m408[1];
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c92, v_c30}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:96", "delta:eval_ans", _fires);
  
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
  // (crule (pre (let __tconst00GP779 const6b86b273ff34fce19d6b804e)) (scan mp_has0 __t3FES778 t k) (body (join mp_has0_ans (0 1) 2 __t3FES778 __tconst00GP779) (exists mp_put_soft (1 2 3 0) 2 t k) (join $sup5638x67x0x0x0 (1 2 0 3) 2 k t __t8RYZ777 v) (join mp_put_soft (1 2 3 0) 4 t k v __t8RYZ777)) (head (emit mp_put_soft_ans (0 1) __t8RYZ777 t)) map.slog:68 #f)
  class ReadTask413 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_has0_ansindex409;  slog::Index** mp_put_softindex410;  slog::Index** $sup5638x67x0x0x0index411;  slog::Index** mp_put_softindex412;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_soft_ans");
      std::vector<u16> ord414({0, 1});
      slog::Relation* readrel415 = db->getRelation("mp_put_soft_ans");
      head_index[0] = readrel415->getIndex(ord414, false);
      outer_rel = db->getRelation("mp_has0");
      std::vector<u16> ord416({0, 1});
      slog::Relation* readrel417 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex409 = readrel417->getIndex(ord416, false);
      std::vector<u16> ord418({1, 2, 3, 0});
      slog::Relation* readrel419 = db->getRelation("mp_put_soft");
      mp_put_softindex410 = readrel419->getIndex(ord418, false);
      std::vector<u16> ord420({1, 2, 0, 3});
      slog::Relation* readrel421 = db->getRelation("$sup5638x67x0x0x0");
      $sup5638x67x0x0x0index411 = readrel421->getIndex(ord420, false);
      std::vector<u16> ord422({1, 2, 3, 0});
      slog::Relation* readrel423 = db->getRelation("mp_put_soft");
      mp_put_softindex412 = readrel423->getIndex(ord422, false);
  
    }
    ReadTask413(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c45 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c25 = _t[2];
        slog::join_probe<2,2>(mp_has0_ansindex409, std::array<u64,2>{v_c46, v_c45}, [&](const std::array<u64,2>& m424) {
          if (!slog::exists_probe<4,2>(mp_put_softindex410, std::array<u64,4>{v_c47, v_c25, 0, 0})) return;
          slog::join_probe<4,2>($sup5638x67x0x0x0index411, std::array<u64,4>{v_c25, v_c47, 0, 0}, [&](const std::array<u64,4>& m425) {
            u64 v_c48 = m425[2]; u64 v_c30 = m425[3];
            slog::join_probe<4,4>(mp_put_softindex412, std::array<u64,4>{v_c47, v_c25, v_c30, v_c48}, [&](const std::array<u64,4>& m426) {
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c48, v_c47}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:68", "delta:mp_has0", _fires);
  
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
  // (crule (pre (let __tconst9a82241 const6b86b273ff34fce19d6b804e)) (scan mp_put_ans __t630X244 __v0) (body (join-old mp_put (0 2 1 3) 1 (0 2 1 3) __t630X244 k l v) (exists $sup5638x40x0x0x1 (2 3 7 0 1 4 5 6) 3 k l v) (exists mbranch (3 0 1 2 4) 1 l) (exists mp_put (2 3 0 1) 2 k v) (exists mp_msk (1 2 0) 1 k) (join-old $sup5638x40x0x0x0 (1 2 6 0 3 4 5) 3 (1 2 6 0 3 4 5) k l v __t8K90240 m p r) (exists mbranch (1 2 3 4 0) 4 p m l r) (exists mp_put (3 0 2 1) 3 v __t8K90240 k) (exists mp_msk (1 2 0) 2 k m) (exists mp_msk_ans (1 0) 1 p) (join-old $sup5638x40x0x0x1 (3 4 5 6 0 2 7 1) 7 (3 4 5 6 0 2 7 1) l m p r __t8K90240 k v __t0CZp243) (exists mp_msk (1 2 0) 3 k m __t0CZp243) (exists mp_msk_ans (0 1) 2 __t0CZp243 p) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t3kyC239) (join-old mp_put (0 2 1 3) 4 (0 2 1 3) __t8K90240 k __t3kyC239 v) (join-old mp_msk (1 2 0) 3 (1 2 0) k m __t0CZp243) (join mp_msk_ans (0 1) 2 __t0CZp243 p) (let __t9Ap1242 (band k m)) (cmp lt __t9Ap1242 __tconst9a82241)) (head (emit-temp temp636D1974 __t8K90240 __v0 m p r) (mkstruct mbranch (1 2 3 4 0) __t2hPi238 p m __v0 r)) map.slog:41 #f)
  class ReadTask450 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_putindex427;  slog::Index** $sup5638x40x0x0x1index428;  slog::Index** mbranchindex429;  slog::Index** mp_putindex430;  slog::Index** mp_mskindex431;  slog::Index** $sup5638x40x0x0x0index432;  slog::Index** mbranchindex433;  slog::Index** mp_putindex434;  slog::Index** mp_mskindex435;  slog::Index** mp_msk_ansindex436;  slog::Index** $sup5638x40x0x0x1index437;  slog::Index** mp_mskindex438;  slog::Index** mp_msk_ansindex439;  slog::Index** mbranchindex440;  slog::Index** mp_putindex441;  slog::Index** mp_mskindex442;  slog::Index** mp_msk_ansindex443;  slog::Index** mp_putdelta444;  slog::Index** $sup5638x40x0x0x0delta445;  slog::Index** $sup5638x40x0x0x1delta446;  slog::Index** mbranchdelta447;  slog::Index** mp_putdelta448;  slog::Index** mp_mskdelta449;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp636D1974");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_put_ans");
      std::vector<u16> ord451({0, 2, 1, 3});
      slog::Relation* readrel452 = db->getRelation("mp_put");
      mp_putindex427 = readrel452->getIndex(ord451, false);
      std::vector<u16> ord453({0, 2, 1, 3});
      slog::Relation* readrel454 = db->getRelation("mp_put");
      mp_putdelta444 = readrel454->getIndex(ord453, true);
      std::vector<u16> ord455({2, 3, 7, 0, 1, 4, 5, 6});
      slog::Relation* readrel456 = db->getRelation("$sup5638x40x0x0x1");
      $sup5638x40x0x0x1index428 = readrel456->getIndex(ord455, false);
      std::vector<u16> ord457({3, 0, 1, 2, 4});
      slog::Relation* readrel458 = db->getRelation("mbranch");
      mbranchindex429 = readrel458->getIndex(ord457, false);
      std::vector<u16> ord459({2, 3, 0, 1});
      slog::Relation* readrel460 = db->getRelation("mp_put");
      mp_putindex430 = readrel460->getIndex(ord459, false);
      std::vector<u16> ord461({1, 2, 0});
      slog::Relation* readrel462 = db->getRelation("mp_msk");
      mp_mskindex431 = readrel462->getIndex(ord461, false);
      std::vector<u16> ord463({1, 2, 6, 0, 3, 4, 5});
      slog::Relation* readrel464 = db->getRelation("$sup5638x40x0x0x0");
      $sup5638x40x0x0x0index432 = readrel464->getIndex(ord463, false);
      std::vector<u16> ord465({1, 2, 6, 0, 3, 4, 5});
      slog::Relation* readrel466 = db->getRelation("$sup5638x40x0x0x0");
      $sup5638x40x0x0x0delta445 = readrel466->getIndex(ord465, true);
      std::vector<u16> ord467({1, 2, 3, 4, 0});
      slog::Relation* readrel468 = db->getRelation("mbranch");
      mbranchindex433 = readrel468->getIndex(ord467, false);
      std::vector<u16> ord469({3, 0, 2, 1});
      slog::Relation* readrel470 = db->getRelation("mp_put");
      mp_putindex434 = readrel470->getIndex(ord469, false);
      std::vector<u16> ord471({1, 2, 0});
      slog::Relation* readrel472 = db->getRelation("mp_msk");
      mp_mskindex435 = readrel472->getIndex(ord471, false);
      std::vector<u16> ord473({1, 0});
      slog::Relation* readrel474 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex436 = readrel474->getIndex(ord473, false);
      std::vector<u16> ord475({3, 4, 5, 6, 0, 2, 7, 1});
      slog::Relation* readrel476 = db->getRelation("$sup5638x40x0x0x1");
      $sup5638x40x0x0x1index437 = readrel476->getIndex(ord475, false);
      std::vector<u16> ord477({3, 4, 5, 6, 0, 2, 7, 1});
      slog::Relation* readrel478 = db->getRelation("$sup5638x40x0x0x1");
      $sup5638x40x0x0x1delta446 = readrel478->getIndex(ord477, true);
      std::vector<u16> ord479({1, 2, 0});
      slog::Relation* readrel480 = db->getRelation("mp_msk");
      mp_mskindex438 = readrel480->getIndex(ord479, false);
      std::vector<u16> ord481({0, 1});
      slog::Relation* readrel482 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex439 = readrel482->getIndex(ord481, false);
      std::vector<u16> ord483({1, 2, 3, 4, 0});
      slog::Relation* readrel484 = db->getRelation("mbranch");
      mbranchindex440 = readrel484->getIndex(ord483, false);
      std::vector<u16> ord485({1, 2, 3, 4, 0});
      slog::Relation* readrel486 = db->getRelation("mbranch");
      mbranchdelta447 = readrel486->getIndex(ord485, true);
      std::vector<u16> ord487({0, 2, 1, 3});
      slog::Relation* readrel488 = db->getRelation("mp_put");
      mp_putindex441 = readrel488->getIndex(ord487, false);
      std::vector<u16> ord489({0, 2, 1, 3});
      slog::Relation* readrel490 = db->getRelation("mp_put");
      mp_putdelta448 = readrel490->getIndex(ord489, true);
      std::vector<u16> ord491({1, 2, 0});
      slog::Relation* readrel492 = db->getRelation("mp_msk");
      mp_mskindex442 = readrel492->getIndex(ord491, false);
      std::vector<u16> ord493({1, 2, 0});
      slog::Relation* readrel494 = db->getRelation("mp_msk");
      mp_mskdelta449 = readrel494->getIndex(ord493, true);
      std::vector<u16> ord495({0, 1});
      slog::Relation* readrel496 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex443 = readrel496->getIndex(ord495, false);
  
    }
    ReadTask450(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c66 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c70 = _t[0];
        u64 v_c71 = _t[1];
        slog::join_probe_old<4,1>(mp_putindex427, mp_putdelta444, std::array<u64,4>{v_c70, 0, 0, 0}, [&](const std::array<u64,4>& m497) {
          u64 v_c25 = m497[1]; u64 v_c26 = m497[2]; u64 v_c30 = m497[3];
          if (!slog::exists_probe<8,3>($sup5638x40x0x0x1index428, std::array<u64,8>{v_c25, v_c26, v_c30, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>(mbranchindex429, std::array<u64,5>{v_c26, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<4,2>(mp_putindex430, std::array<u64,4>{v_c25, v_c30, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_mskindex431, std::array<u64,3>{v_c25, 0, 0})) return;
          slog::join_probe_old<7,3>($sup5638x40x0x0x0index432, $sup5638x40x0x0x0delta445, std::array<u64,7>{v_c25, v_c26, v_c30, 0, 0, 0, 0}, [&](const std::array<u64,7>& m498) {
            u64 v_c68 = m498[3]; u64 v_c27 = m498[4]; u64 v_c28 = m498[5]; u64 v_c29 = m498[6];
            if (!slog::exists_probe<5,4>(mbranchindex433, std::array<u64,5>{v_c28, v_c27, v_c26, v_c29, 0})) return;
            if (!slog::exists_probe<4,3>(mp_putindex434, std::array<u64,4>{v_c30, v_c68, v_c25, 0})) return;
            if (!slog::exists_probe<3,2>(mp_mskindex435, std::array<u64,3>{v_c25, v_c27, 0})) return;
            if (!slog::exists_probe<2,1>(mp_msk_ansindex436, std::array<u64,2>{v_c28, 0})) return;
            slog::join_probe_old<8,7>($sup5638x40x0x0x1index437, $sup5638x40x0x0x1delta446, std::array<u64,8>{v_c26, v_c27, v_c28, v_c29, v_c68, v_c25, v_c30, 0}, [&](const std::array<u64,8>& m499) {
              u64 v_c67 = m499[7];
              if (!slog::exists_probe<3,3>(mp_mskindex438, std::array<u64,3>{v_c25, v_c27, v_c67})) return;
              if (!slog::exists_probe<2,2>(mp_msk_ansindex439, std::array<u64,2>{v_c67, v_c28})) return;
              slog::join_probe_old<5,4>(mbranchindex440, mbranchdelta447, std::array<u64,5>{v_c28, v_c27, v_c26, v_c29, 0}, [&](const std::array<u64,5>& m500) {
                u64 v_c69 = m500[4];
                slog::join_probe_old<4,4>(mp_putindex441, mp_putdelta448, std::array<u64,4>{v_c68, v_c25, v_c69, v_c30}, [&](const std::array<u64,4>& m501) {
                  slog::join_probe_old<3,3>(mp_mskindex442, mp_mskdelta449, std::array<u64,3>{v_c25, v_c27, v_c67}, [&](const std::array<u64,3>& m502) {
                    slog::join_probe<2,2>(mp_msk_ansindex443, std::array<u64,2>{v_c67, v_c28}, [&](const std::array<u64,2>& m503) {
                      u64 v_c72 = _prim_band(db, v_c25, v_c27);
                      if (v_c72 == slog_error) { slog::emit_pending_error(db, "map.slog:41"); return; }
                      u64 v_c98 = _prim_lt(db, v_c72, v_c66);
                      if (v_c98 == slog_error) { slog::emit_pending_error(db, "map.slog:41"); return; }
                      if (!v_c98) return;
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c68, v_c71, v_c27, v_c28, v_c29});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c28, v_c27, v_c71, v_c29}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:41", "delta:mp_put_ans", _fires);
  
      if (!_done)
      {
        ReadTask450* _cont = new ReadTask450(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask450(db,b), false);
  // (crule (pre (let __tconst8wKO1349 constb9e118781cea1f9fa01462e0)) (scan boolval __t3WHU428 __t1Q0o427) (body (join _enum (0 1) 2 __t1Q0o427 __tconst8wKO1349) (join-old select_branch (1 0 2 3) 1 (1 0 2 3) __t3WHU428 __t6mHg429 e2 e3)) (head (emit select_branch_ans (0 1) __t6mHg429 e3)) interp.slog:85 #f)
  class ReadTask508 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex505;  slog::Index** select_branchindex506;  slog::Index** select_branchdelta507;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("select_branch_ans");
      std::vector<u16> ord509({0, 1});
      slog::Relation* readrel510 = db->getRelation("select_branch_ans");
      head_index[0] = readrel510->getIndex(ord509, false);
      outer_rel = db->getRelation("boolval");
      std::vector<u16> ord511({0, 1});
      slog::Relation* readrel512 = db->getRelation("_enum");
      _enumindex505 = readrel512->getIndex(ord511, false);
      std::vector<u16> ord513({1, 0, 2, 3});
      slog::Relation* readrel514 = db->getRelation("select_branch");
      select_branchindex506 = readrel514->getIndex(ord513, false);
      std::vector<u16> ord515({1, 0, 2, 3});
      slog::Relation* readrel516 = db->getRelation("select_branch");
      select_branchdelta507 = readrel516->getIndex(ord515, true);
  
    }
    ReadTask508(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c99 = v_constb9e118781cea1f9fa01462e0;
  
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
        slog::join_probe<2,2>(_enumindex505, std::array<u64,2>{v_c101, v_c99}, [&](const std::array<u64,2>& m517) {
          slog::join_probe_old<4,1>(select_branchindex506, select_branchdelta507, std::array<u64,4>{v_c100, 0, 0, 0}, [&](const std::array<u64,4>& m518) {
            u64 v_c102 = m518[1]; u64 v_c103 = m518[2]; u64 v_c104 = m518[3];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c102, v_c104}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:85", "delta:boolval", _fires);
  
      if (!_done)
      {
        ReadTask508* _cont = new ReadTask508(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask508(db,b), false);
  // (crule (pre (let __tconst7YVO1086 constb9e118781cea1f9fa01462e0)) (scan temp6YY41815 __t4KDF438) (body (join _enum (1 0) 1 __tconst7YVO1086 __t2dgW435) (join boolval (1 0) 1 __t2dgW435 __t83Bj436)) (head (emit delta_ans (0 1) __t4KDF438 __t83Bj436)) interp.slog:119 #f)
  class ReadTask521 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex519;  slog::Index** boolvalindex520;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("delta_ans");
      std::vector<u16> ord522({0, 1});
      slog::Relation* readrel523 = db->getRelation("delta_ans");
      head_index[0] = readrel523->getIndex(ord522, false);
      outer_rel = db->getRelation("temp6YY41815");
      std::vector<u16> ord524({1, 0});
      slog::Relation* readrel525 = db->getRelation("_enum");
      _enumindex519 = readrel525->getIndex(ord524, false);
      std::vector<u16> ord526({1, 0});
      slog::Relation* readrel527 = db->getRelation("boolval");
      boolvalindex520 = readrel527->getIndex(ord526, false);
  
    }
    ReadTask521(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c105 = v_constb9e118781cea1f9fa01462e0;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c106 = _t[0];
        slog::join_probe<2,1>(_enumindex519, std::array<u64,2>{v_c105, 0}, [&](const std::array<u64,2>& m528) {
          u64 v_c107 = m528[1];
          slog::join_probe<2,1>(boolvalindex520, std::array<u64,2>{v_c107, 0}, [&](const std::array<u64,2>& m529) {
            u64 v_c108 = m529[1];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c106, v_c108}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:119", "delta:temp6YY41815", _fires);
  
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
  // (crule (pre (let __tconst00GP779 const6b86b273ff34fce19d6b804e)) (scan mp_put_soft __t8RYZ777 t k v) (body (join $sup5638x67x0x0x0 (1 2 0 3) 4 k t __t8RYZ777 v) (exists mp_has0_ans (1 0) 1 __tconst00GP779) (join-old mp_has0 (1 2 0) 2 (1 2 0) t k __t3FES778) (join mp_has0_ans (0 1) 2 __t3FES778 __tconst00GP779)) (head (emit mp_put_soft_ans (0 1) __t8RYZ777 t)) map.slog:68 #f)
  class ReadTask535 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x67x0x0x0index530;  slog::Index** mp_has0_ansindex531;  slog::Index** mp_has0index532;  slog::Index** mp_has0_ansindex533;  slog::Index** mp_has0delta534;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_soft_ans");
      std::vector<u16> ord536({0, 1});
      slog::Relation* readrel537 = db->getRelation("mp_put_soft_ans");
      head_index[0] = readrel537->getIndex(ord536, false);
      outer_rel = db->getRelation("mp_put_soft");
      std::vector<u16> ord538({1, 2, 0, 3});
      slog::Relation* readrel539 = db->getRelation("$sup5638x67x0x0x0");
      $sup5638x67x0x0x0index530 = readrel539->getIndex(ord538, false);
      std::vector<u16> ord540({1, 0});
      slog::Relation* readrel541 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex531 = readrel541->getIndex(ord540, false);
      std::vector<u16> ord542({1, 2, 0});
      slog::Relation* readrel543 = db->getRelation("mp_has0");
      mp_has0index532 = readrel543->getIndex(ord542, false);
      std::vector<u16> ord544({1, 2, 0});
      slog::Relation* readrel545 = db->getRelation("mp_has0");
      mp_has0delta534 = readrel545->getIndex(ord544, true);
      std::vector<u16> ord546({0, 1});
      slog::Relation* readrel547 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex533 = readrel547->getIndex(ord546, false);
  
    }
    ReadTask535(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c45 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c25 = _t[2];
        u64 v_c30 = _t[3];
        slog::join_probe<4,4>($sup5638x67x0x0x0index530, std::array<u64,4>{v_c25, v_c47, v_c48, v_c30}, [&](const std::array<u64,4>& m548) {
          if (!slog::exists_probe<2,1>(mp_has0_ansindex531, std::array<u64,2>{v_c45, 0})) return;
          slog::join_probe_old<3,2>(mp_has0index532, mp_has0delta534, std::array<u64,3>{v_c47, v_c25, 0}, [&](const std::array<u64,3>& m549) {
            u64 v_c46 = m549[2];
            slog::join_probe<2,2>(mp_has0_ansindex533, std::array<u64,2>{v_c46, v_c45}, [&](const std::array<u64,2>& m550) {
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c48, v_c47}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:68", "delta:mp_put_soft", _fires);
  
      if (!_done)
      {
        ReadTask535* _cont = new ReadTask535(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask535(db,b), false);
  // (crule (pre) (scan eval_args_ans __t2ycT266 vs) (body (join-old eval_args (0 1 2 3) 1 (0 1 2 3) __t2ycT266 es rho t) (exists eval (2 3 0 1) 2 rho t) (exists app (2 0 1) 1 es) (exists tick (2 0 1) 1 t) (join $sup70016x51x0x0x0 (2 3 4 0 1) 3 es rho t __d0 ef) (exists app (1 2 0) 2 ef es) (join-old eval (1 2 3 0) 3 (1 2 3 0) ef rho t __t1jZw263) (exists eval_ans (0 1) 1 __t1jZw263) (join-old app (1 2 0) 2 (1 2 0) ef es __t4H6p267) (join-old tick (1 2 0) 2 (1 2 0) __t4H6p267 t __t8A6X268) (exists tick_ans (0 1) 1 __t8A6X268) (join eval_ans (0 1) 1 __t1jZw263 __t5Yru265) (join-old tick_ans (0 1) 1 (0 1) __t8A6X268 t2) (join-old closure (0 1 2) 1 (0 1 2) __t5Yru265 __t3Nsh264 rhoc) (join-old lambda (0 1 2) 1 (0 1 2) __t3Nsh264 xs eb)) (head (emit $sup70016x51x0x0x1 (1 8 0 2 3 4 5 6 7 9 10 11 12) __t1jZw263 rhoc __d0 __t2ycT266 __t8A6X268 eb ef es rho t t2 vs xs)) interp.slog:52 #f)
  class ReadTask573 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eval_argsindex551;  slog::Index** evalindex552;  slog::Index** appindex553;  slog::Index** tickindex554;  slog::Index** $sup70016x51x0x0x0index555;  slog::Index** appindex556;  slog::Index** evalindex557;  slog::Index** eval_ansindex558;  slog::Index** appindex559;  slog::Index** tickindex560;  slog::Index** tick_ansindex561;  slog::Index** eval_ansindex562;  slog::Index** tick_ansindex563;  slog::Index** closureindex564;  slog::Index** lambdaindex565;  slog::Index** eval_argsdelta566;  slog::Index** evaldelta567;  slog::Index** appdelta568;  slog::Index** tickdelta569;  slog::Index** tick_ansdelta570;  slog::Index** closuredelta571;  slog::Index** lambdadelta572;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup70016x51x0x0x1");
      std::vector<u16> ord574({1, 8, 0, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12});
      slog::Relation* readrel575 = db->getRelation("$sup70016x51x0x0x1");
      head_index[0] = readrel575->getIndex(ord574, false);
      outer_rel = db->getRelation("eval_args_ans");
      std::vector<u16> ord576({0, 1, 2, 3});
      slog::Relation* readrel577 = db->getRelation("eval_args");
      eval_argsindex551 = readrel577->getIndex(ord576, false);
      std::vector<u16> ord578({0, 1, 2, 3});
      slog::Relation* readrel579 = db->getRelation("eval_args");
      eval_argsdelta566 = readrel579->getIndex(ord578, true);
      std::vector<u16> ord580({2, 3, 0, 1});
      slog::Relation* readrel581 = db->getRelation("eval");
      evalindex552 = readrel581->getIndex(ord580, false);
      std::vector<u16> ord582({2, 0, 1});
      slog::Relation* readrel583 = db->getRelation("app");
      appindex553 = readrel583->getIndex(ord582, false);
      std::vector<u16> ord584({2, 0, 1});
      slog::Relation* readrel585 = db->getRelation("tick");
      tickindex554 = readrel585->getIndex(ord584, false);
      std::vector<u16> ord586({2, 3, 4, 0, 1});
      slog::Relation* readrel587 = db->getRelation("$sup70016x51x0x0x0");
      $sup70016x51x0x0x0index555 = readrel587->getIndex(ord586, false);
      std::vector<u16> ord588({1, 2, 0});
      slog::Relation* readrel589 = db->getRelation("app");
      appindex556 = readrel589->getIndex(ord588, false);
      std::vector<u16> ord590({1, 2, 3, 0});
      slog::Relation* readrel591 = db->getRelation("eval");
      evalindex557 = readrel591->getIndex(ord590, false);
      std::vector<u16> ord592({1, 2, 3, 0});
      slog::Relation* readrel593 = db->getRelation("eval");
      evaldelta567 = readrel593->getIndex(ord592, true);
      std::vector<u16> ord594({0, 1});
      slog::Relation* readrel595 = db->getRelation("eval_ans");
      eval_ansindex558 = readrel595->getIndex(ord594, false);
      std::vector<u16> ord596({1, 2, 0});
      slog::Relation* readrel597 = db->getRelation("app");
      appindex559 = readrel597->getIndex(ord596, false);
      std::vector<u16> ord598({1, 2, 0});
      slog::Relation* readrel599 = db->getRelation("app");
      appdelta568 = readrel599->getIndex(ord598, true);
      std::vector<u16> ord600({1, 2, 0});
      slog::Relation* readrel601 = db->getRelation("tick");
      tickindex560 = readrel601->getIndex(ord600, false);
      std::vector<u16> ord602({1, 2, 0});
      slog::Relation* readrel603 = db->getRelation("tick");
      tickdelta569 = readrel603->getIndex(ord602, true);
      std::vector<u16> ord604({0, 1});
      slog::Relation* readrel605 = db->getRelation("tick_ans");
      tick_ansindex561 = readrel605->getIndex(ord604, false);
      std::vector<u16> ord606({0, 1});
      slog::Relation* readrel607 = db->getRelation("eval_ans");
      eval_ansindex562 = readrel607->getIndex(ord606, false);
      std::vector<u16> ord608({0, 1});
      slog::Relation* readrel609 = db->getRelation("tick_ans");
      tick_ansindex563 = readrel609->getIndex(ord608, false);
      std::vector<u16> ord610({0, 1});
      slog::Relation* readrel611 = db->getRelation("tick_ans");
      tick_ansdelta570 = readrel611->getIndex(ord610, true);
      std::vector<u16> ord612({0, 1, 2});
      slog::Relation* readrel613 = db->getRelation("closure");
      closureindex564 = readrel613->getIndex(ord612, false);
      std::vector<u16> ord614({0, 1, 2});
      slog::Relation* readrel615 = db->getRelation("closure");
      closuredelta571 = readrel615->getIndex(ord614, true);
      std::vector<u16> ord616({0, 1, 2});
      slog::Relation* readrel617 = db->getRelation("lambda");
      lambdaindex565 = readrel617->getIndex(ord616, false);
      std::vector<u16> ord618({0, 1, 2});
      slog::Relation* readrel619 = db->getRelation("lambda");
      lambdadelta572 = readrel619->getIndex(ord618, true);
  
    }
    ReadTask573(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c109 = _t[0];
        u64 v_c110 = _t[1];
        slog::join_probe_old<4,1>(eval_argsindex551, eval_argsdelta566, std::array<u64,4>{v_c109, 0, 0, 0}, [&](const std::array<u64,4>& m620) {
          u64 v_c111 = m620[1]; u64 v_c94 = m620[2]; u64 v_c47 = m620[3];
          if (!slog::exists_probe<4,2>(evalindex552, std::array<u64,4>{v_c94, v_c47, 0, 0})) return;
          if (!slog::exists_probe<3,1>(appindex553, std::array<u64,3>{v_c111, 0, 0})) return;
          if (!slog::exists_probe<3,1>(tickindex554, std::array<u64,3>{v_c47, 0, 0})) return;
          slog::join_probe<5,3>($sup70016x51x0x0x0index555, std::array<u64,5>{v_c111, v_c94, v_c47, 0, 0}, [&](const std::array<u64,5>& m621) {
            u64 v_c23 = m621[3]; u64 v_c112 = m621[4];
            if (!slog::exists_probe<3,2>(appindex556, std::array<u64,3>{v_c112, v_c111, 0})) return;
            slog::join_probe_old<4,3>(evalindex557, evaldelta567, std::array<u64,4>{v_c112, v_c94, v_c47, 0}, [&](const std::array<u64,4>& m622) {
              u64 v_c113 = m622[3];
              if (!slog::exists_probe<2,1>(eval_ansindex558, std::array<u64,2>{v_c113, 0})) return;
              slog::join_probe_old<3,2>(appindex559, appdelta568, std::array<u64,3>{v_c112, v_c111, 0}, [&](const std::array<u64,3>& m623) {
                u64 v_c114 = m623[2];
                slog::join_probe_old<3,2>(tickindex560, tickdelta569, std::array<u64,3>{v_c114, v_c47, 0}, [&](const std::array<u64,3>& m624) {
                  u64 v_c115 = m624[2];
                  if (!slog::exists_probe<2,1>(tick_ansindex561, std::array<u64,2>{v_c115, 0})) return;
                  slog::join_probe<2,1>(eval_ansindex562, std::array<u64,2>{v_c113, 0}, [&](const std::array<u64,2>& m625) {
                    u64 v_c116 = m625[1];
                    slog::join_probe_old<2,1>(tick_ansindex563, tick_ansdelta570, std::array<u64,2>{v_c115, 0}, [&](const std::array<u64,2>& m626) {
                      u64 v_c117 = m626[1];
                      slog::join_probe_old<3,1>(closureindex564, closuredelta571, std::array<u64,3>{v_c116, 0, 0}, [&](const std::array<u64,3>& m627) {
                        u64 v_c118 = m627[1]; u64 v_c119 = m627[2];
                        slog::join_probe_old<3,1>(lambdaindex565, lambdadelta572, std::array<u64,3>{v_c118, 0, 0}, [&](const std::array<u64,3>& m628) {
                          u64 v_c120 = m628[1]; u64 v_c88 = m628[2];
                          ++_fires;
                          slog::emit<13>(head_rel[0], head_index[0], newbatch[0], std::array<u64,13>{v_c113, v_c119, v_c23, v_c109, v_c115, v_c88, v_c112, v_c111, v_c94, v_c47, v_c117, v_c110, v_c120}, std::array<u16,13>{1, 8, 0, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12});
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
  
      if (_fires) db->bumpFires("interp.slog:52", "delta:eval_args_ans", _fires);
  
      if (!_done)
      {
        ReadTask573* _cont = new ReadTask573(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask573(db,b), false);
  // (crule (pre) (scan $sup5638x40x0x0x0 __d0 k l m p r v) (body (exists mp_msk_ans (1 0) 1 p) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t4Cp5299) (join-old mp_msk_ans (0 1) 2 (0 1) __t4Cp5299 p)) (head (emit $sup5638x40x0x0x1 (1 5 0 2 3 4 6 7) __t4Cp5299 p __d0 k l m r v)) map.slog:41 #f)
  class ReadTask634 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_msk_ansindex629;  slog::Index** mp_mskindex630;  slog::Index** mp_msk_ansindex631;  slog::Index** mp_mskdelta632;  slog::Index** mp_msk_ansdelta633;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x40x0x0x1");
      std::vector<u16> ord635({1, 5, 0, 2, 3, 4, 6, 7});
      slog::Relation* readrel636 = db->getRelation("$sup5638x40x0x0x1");
      head_index[0] = readrel636->getIndex(ord635, false);
      outer_rel = db->getRelation("$sup5638x40x0x0x0");
      std::vector<u16> ord637({1, 0});
      slog::Relation* readrel638 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex629 = readrel638->getIndex(ord637, false);
      std::vector<u16> ord639({1, 2, 0});
      slog::Relation* readrel640 = db->getRelation("mp_msk");
      mp_mskindex630 = readrel640->getIndex(ord639, false);
      std::vector<u16> ord641({1, 2, 0});
      slog::Relation* readrel642 = db->getRelation("mp_msk");
      mp_mskdelta632 = readrel642->getIndex(ord641, true);
      std::vector<u16> ord643({0, 1});
      slog::Relation* readrel644 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex631 = readrel644->getIndex(ord643, false);
      std::vector<u16> ord645({0, 1});
      slog::Relation* readrel646 = db->getRelation("mp_msk_ans");
      mp_msk_ansdelta633 = readrel646->getIndex(ord645, true);
  
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
        u64 v_c23 = _t[0];
        u64 v_c25 = _t[1];
        u64 v_c26 = _t[2];
        u64 v_c27 = _t[3];
        u64 v_c28 = _t[4];
        u64 v_c29 = _t[5];
        u64 v_c30 = _t[6];
        if (!slog::exists_probe<2,1>(mp_msk_ansindex629, std::array<u64,2>{v_c28, 0})) return;
        slog::join_probe_old<3,2>(mp_mskindex630, mp_mskdelta632, std::array<u64,3>{v_c25, v_c27, 0}, [&](const std::array<u64,3>& m647) {
          u64 v_c121 = m647[2];
          slog::join_probe_old<2,2>(mp_msk_ansindex631, mp_msk_ansdelta633, std::array<u64,2>{v_c121, v_c28}, [&](const std::array<u64,2>& m648) {
            ++_fires;
            slog::emit<8>(head_rel[0], head_index[0], newbatch[0], std::array<u64,8>{v_c121, v_c28, v_c23, v_c25, v_c26, v_c27, v_c29, v_c30}, std::array<u16,8>{1, 5, 0, 2, 3, 4, 6, 7});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:41", "delta:$sup5638x40x0x0x0", _fires);
  
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
  // (crule (pre (let __tconst5vD0184 const4a44dc15364204a80fe80e90) (let __tconst2wxb180 const4fc82b26aecb47d2868c4efb) (let __tconst5BWV176 const6b51d431df5d7f141cbececc) (let __tconst2n7e169 conste25572d3e5a4cc456a779178) (let __tconst1XI2167 const3fdba35f04dc8c462986c992) (let __tconst8wlK160 constda53dc5001ef1e872bd575bd) (let __tconst5TvD157 const06abaa100ecef791ce028c56) (let __t89SV181 (lempty))) (once) (body) (head (emit-temp temp6MYu1990 __t89SV181) (mkstruct ref (1 0) __t1BW9179 __tconst2wxb180) (mkstruct sym (1 0) __t93en170 __tconst2n7e169) (mkstruct ref (1 0) __t1od9165 __tconst5vD0184) (mkstruct sym (1 0) __t3Wf9161 __tconst8wlK160) (mkstruct primref (1 0) __t2ZGf158 __tconst5TvD157) (mkstruct ref (1 0) __t2CIh153 __tconst5BWV176) (mkstruct ref (1 0) __t8RaS151 __tconst1XI2167)) kcfa.slog:29 #f)
  class ReadTask649 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[8];
    slog::Index** head_index[8];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp6MYu1990");
      head_rel[1] = db->getRelation("ref");
      head_rel[2] = db->getRelation("sym");
      head_rel[3] = db->getRelation("ref");
      head_rel[4] = db->getRelation("sym");
      head_rel[5] = db->getRelation("primref");
      head_rel[6] = db->getRelation("ref");
      head_rel[7] = db->getRelation("ref");
  
    }
    ReadTask649(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c38 = v_const4a44dc15364204a80fe80e90;
      u64 v_c122 = v_const4fc82b26aecb47d2868c4efb;
      u64 v_c39 = v_const6b51d431df5d7f141cbececc;
      u64 v_c123 = v_conste25572d3e5a4cc456a779178;
      u64 v_c124 = v_const3fdba35f04dc8c462986c992;
      u64 v_c125 = v_constda53dc5001ef1e872bd575bd;
      u64 v_c126 = v_const06abaa100ecef791ce028c56;
      u64 v_c127 = _prim_lempty(db);
      if (v_c127 == slog_error) { slog::emit_pending_error(db, "kcfa.slog:29"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[8];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
      newbatch[4] = new slog::InsertBatch();
      newbatch[5] = new slog::InsertBatch();
      newbatch[6] = new slog::InsertBatch();
      newbatch[7] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c127});
      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c122}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[2], newbatch[2], std::array<u64,1>{v_c123}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[3], newbatch[3], std::array<u64,1>{v_c38}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[4], newbatch[4], std::array<u64,1>{v_c125}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[5], newbatch[5], std::array<u64,1>{v_c126}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[6], newbatch[6], std::array<u64,1>{v_c39}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[7], newbatch[7], std::array<u64,1>{v_c124}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
        head_rel[5]->sendBatch(newbatch[5]);
        head_rel[6]->sendBatch(newbatch[6]);
        head_rel[7]->sendBatch(newbatch[7]);
  
      if (_fires) db->bumpFires("kcfa.slog:29", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask649(db,b), true);
  // (crule (pre) (scan mp_union __t32Fx98 __t8vmP99 __t9QK9100) (body (join-old mbranch (0 1 2 3 4) 1 (0 1 2 3 4) __t8vmP99 p m l r) (join-old mbranch (0 1 2 3 4) 1 (0 1 2 3 4) __t9QK9100 q n u v) (cmp lt m n)) (head (emit $sup5638x110x0x0x0 (3 4 0 1 2 5 6 7 8 9 10) n p __t32Fx98 l m q r __t8vmP99 __t9QK9100 u v)) map.slog:111 #f)
  class ReadTask654 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex650;  slog::Index** mbranchindex651;  slog::Index** mbranchdelta652;  slog::Index** mbranchdelta653;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x110x0x0x0");
      std::vector<u16> ord655({3, 4, 0, 1, 2, 5, 6, 7, 8, 9, 10});
      slog::Relation* readrel656 = db->getRelation("$sup5638x110x0x0x0");
      head_index[0] = readrel656->getIndex(ord655, false);
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord657({0, 1, 2, 3, 4});
      slog::Relation* readrel658 = db->getRelation("mbranch");
      mbranchindex650 = readrel658->getIndex(ord657, false);
      std::vector<u16> ord659({0, 1, 2, 3, 4});
      slog::Relation* readrel660 = db->getRelation("mbranch");
      mbranchdelta652 = readrel660->getIndex(ord659, true);
      std::vector<u16> ord661({0, 1, 2, 3, 4});
      slog::Relation* readrel662 = db->getRelation("mbranch");
      mbranchindex651 = readrel662->getIndex(ord661, false);
      std::vector<u16> ord663({0, 1, 2, 3, 4});
      slog::Relation* readrel664 = db->getRelation("mbranch");
      mbranchdelta653 = readrel664->getIndex(ord663, true);
  
    }
    ReadTask654(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c128 = _t[0];
        u64 v_c129 = _t[1];
        u64 v_c130 = _t[2];
        slog::join_probe_old<5,1>(mbranchindex650, mbranchdelta652, std::array<u64,5>{v_c129, 0, 0, 0, 0}, [&](const std::array<u64,5>& m665) {
          u64 v_c28 = m665[1]; u64 v_c27 = m665[2]; u64 v_c26 = m665[3]; u64 v_c29 = m665[4];
          slog::join_probe_old<5,1>(mbranchindex651, mbranchdelta653, std::array<u64,5>{v_c130, 0, 0, 0, 0}, [&](const std::array<u64,5>& m666) {
            u64 v_c82 = m666[1]; u64 v_c78 = m666[2]; u64 v_c84 = m666[3]; u64 v_c30 = m666[4];
            u64 v_c131 = _prim_lt(db, v_c27, v_c78);
            if (v_c131 == slog_error) { slog::emit_pending_error(db, "map.slog:111"); return; }
            if (!v_c131) return;
            ++_fires;
            slog::emit<11>(head_rel[0], head_index[0], newbatch[0], std::array<u64,11>{v_c78, v_c28, v_c128, v_c26, v_c27, v_c82, v_c29, v_c129, v_c130, v_c84, v_c30}, std::array<u16,11>{3, 4, 0, 1, 2, 5, 6, 7, 8, 9, 10});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:111", "delta:mp_union", _fires);
  
      if (!_done)
      {
        ReadTask654* _cont = new ReadTask654(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask654(db,b), false);
  // (crule (pre (let __trid1aRe1173 constaa218622af4adb846b2d6244) (let __trel90Y91174 constf6cdc3db4b71e0cdeda6912e) (let __tcol2p1T1175 const6b86b273ff34fce19d6b804e) (let __trel6kaB1176 constf6cdc3db4b71e0cdeda6912e) (let __tcol9YXV1177 constd4735e3a265e16eee03f5971)) (scan $sup70016x87x0x0x0 __d0 e1 e2 e3 rho t) (body (join-old eval (1 2 3 0) 3 (1 2 3 0) e1 rho t __t77Vk298) (join-old eval_ans (0 1) 1 (0 1) __t77Vk298 __v0)) (head (tycheck e2 (accept (struct app) (struct boolean) (struct if) (struct lambda) (struct let) (struct letrec) (struct num) (struct primref) (struct ref) (struct sym)) __trid1aRe1173 __trel90Y91174 __tcol2p1T1175 (1 2 3 4 0)) (tycheck e3 (accept (struct app) (struct boolean) (struct if) (struct lambda) (struct let) (struct letrec) (struct num) (struct primref) (struct ref) (struct sym)) __trid1aRe1173 __trel6kaB1176 __tcol9YXV1177 (1 2 3 4 0)) (mkstruct select_branch (2 3 1 0) __7Jff1172 e2 e3 __v0)) interp.slog:88 #f)
  class ReadTask682 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex668;  slog::Index** eval_ansindex669;  slog::Index** evaldelta670;  slog::Index** eval_ansdelta671;
    u32 sid672;  u32 sid673;  u32 sid674;  u32 sid675;  u32 sid676;  u32 sid677;  u32 sid678;  u32 sid679;  u32 sid680;  u32 sid681;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("select_branch");
      outer_rel = db->getRelation("$sup70016x87x0x0x0");
      std::vector<u16> ord683({1, 2, 3, 0});
      slog::Relation* readrel684 = db->getRelation("eval");
      evalindex668 = readrel684->getIndex(ord683, false);
      std::vector<u16> ord685({1, 2, 3, 0});
      slog::Relation* readrel686 = db->getRelation("eval");
      evaldelta670 = readrel686->getIndex(ord685, true);
      std::vector<u16> ord687({0, 1});
      slog::Relation* readrel688 = db->getRelation("eval_ans");
      eval_ansindex669 = readrel688->getIndex(ord687, false);
      std::vector<u16> ord689({0, 1});
      slog::Relation* readrel690 = db->getRelation("eval_ans");
      eval_ansdelta671 = readrel690->getIndex(ord689, true);
      sid672 = db->getRelation("app")->getStructId();
      sid673 = db->getRelation("boolean")->getStructId();
      sid674 = db->getRelation("if")->getStructId();
      sid675 = db->getRelation("lambda")->getStructId();
      sid676 = db->getRelation("let")->getStructId();
      sid677 = db->getRelation("letrec")->getStructId();
      sid678 = db->getRelation("num")->getStructId();
      sid679 = db->getRelation("primref")->getStructId();
      sid680 = db->getRelation("ref")->getStructId();
      sid681 = db->getRelation("sym")->getStructId();
  
    }
    ReadTask682(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c132 = v_constaa218622af4adb846b2d6244;
      u64 v_c133 = v_constf6cdc3db4b71e0cdeda6912e;
      u64 v_c134 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c135 = v_constf6cdc3db4b71e0cdeda6912e;
      u64 v_c136 = v_constd4735e3a265e16eee03f5971;
  
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
        u64 v_c23 = _t[0];
        u64 v_c137 = _t[1];
        u64 v_c103 = _t[2];
        u64 v_c104 = _t[3];
        u64 v_c94 = _t[4];
        u64 v_c47 = _t[5];
        slog::join_probe_old<4,3>(evalindex668, evaldelta670, std::array<u64,4>{v_c137, v_c94, v_c47, 0}, [&](const std::array<u64,4>& m691) {
          u64 v_c138 = m691[3];
          slog::join_probe_old<2,1>(eval_ansindex669, eval_ansdelta671, std::array<u64,2>{v_c138, 0}, [&](const std::array<u64,2>& m692) {
            u64 v_c71 = m692[1];
            ++_fires;
            if (!((is_struct(v_c103) && (decode_struct_id(v_c103) == sid672 || decode_struct_id(v_c103) == sid673 || decode_struct_id(v_c103) == sid674 || decode_struct_id(v_c103) == sid675 || decode_struct_id(v_c103) == sid676 || decode_struct_id(v_c103) == sid677 || decode_struct_id(v_c103) == sid678 || decode_struct_id(v_c103) == sid679 || decode_struct_id(v_c103) == sid680 || decode_struct_id(v_c103) == sid681))))
            {
              slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c132, v_c133, v_c134, v_c103}, std::array<u16,5>{1, 2, 3, 4, 0});
              return;
            }
            if (!((is_struct(v_c104) && (decode_struct_id(v_c104) == sid672 || decode_struct_id(v_c104) == sid673 || decode_struct_id(v_c104) == sid674 || decode_struct_id(v_c104) == sid675 || decode_struct_id(v_c104) == sid676 || decode_struct_id(v_c104) == sid677 || decode_struct_id(v_c104) == sid678 || decode_struct_id(v_c104) == sid679 || decode_struct_id(v_c104) == sid680 || decode_struct_id(v_c104) == sid681))))
            {
              slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c132, v_c135, v_c136, v_c104}, std::array<u16,5>{1, 2, 3, 4, 0});
              return;
            }
            slog::emit_struct<4>(head_rel[2], newbatch[2], std::array<u64,3>{v_c103, v_c104, v_c71}, std::array<u16,4>{2, 3, 1, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("interp.slog:88", "delta:$sup70016x87x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask682* _cont = new ReadTask682(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask682(db,b), false);
  // (crule (pre) (scan select_branch_ans __t1Vli649 __v1) (body (exists eval (1 2 3 0) 1 __v1) (join-old select_branch (0 1 2 3) 1 (0 1 2 3) __t1Vli649 __v0 e2 e3) (exists $sup70016x87x0x0x0 (2 3 1 0 4 5) 2 e2 e3) (exists eval_ans (1 0) 1 __v0) (join-old if (2 3 0 1) 2 (2 3 0 1) e2 e3 __t71xd646 e1) (exists eval (1 2 3 0) 1 __t71xd646) (exists eval (1 2 3 0) 1 e1) (join-old $sup70016x87x0x0x0 (2 3 1 0 4 5) 3 (2 3 1 0 4 5) e2 e3 e1 __t7kdB647 rho t) (join-old eval (2 3 0 1) 4 (2 3 0 1) rho t __t7kdB647 __t71xd646) (exists eval (1 2 3 0) 3 __v1 rho t) (join-old eval (1 2 3 0) 3 (1 2 3 0) e1 rho t __t2MYH648) (exists eval_ans (0 1) 2 __t2MYH648 __v0) (join-old eval (1 2 3 0) 3 (1 2 3 0) __v1 rho t __t4Rxn650) (join eval_ans (0 1) 2 __t2MYH648 __v0) (join-old eval_ans (0 1) 1 (0 1) __t4Rxn650 __v2)) (head (emit eval_ans (0 1) __t7kdB647 __v2)) interp.slog:88 #f)
  class ReadTask715 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex693;  slog::Index** select_branchindex694;  slog::Index** $sup70016x87x0x0x0index695;  slog::Index** eval_ansindex696;  slog::Index** ifindex697;  slog::Index** evalindex698;  slog::Index** evalindex699;  slog::Index** $sup70016x87x0x0x0index700;  slog::Index** evalindex701;  slog::Index** evalindex702;  slog::Index** evalindex703;  slog::Index** eval_ansindex704;  slog::Index** evalindex705;  slog::Index** eval_ansindex706;  slog::Index** eval_ansindex707;  slog::Index** select_branchdelta708;  slog::Index** ifdelta709;  slog::Index** $sup70016x87x0x0x0delta710;  slog::Index** evaldelta711;  slog::Index** evaldelta712;  slog::Index** evaldelta713;  slog::Index** eval_ansdelta714;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord716({0, 1});
      slog::Relation* readrel717 = db->getRelation("eval_ans");
      head_index[0] = readrel717->getIndex(ord716, false);
      outer_rel = db->getRelation("select_branch_ans");
      std::vector<u16> ord718({1, 2, 3, 0});
      slog::Relation* readrel719 = db->getRelation("eval");
      evalindex693 = readrel719->getIndex(ord718, false);
      std::vector<u16> ord720({0, 1, 2, 3});
      slog::Relation* readrel721 = db->getRelation("select_branch");
      select_branchindex694 = readrel721->getIndex(ord720, false);
      std::vector<u16> ord722({0, 1, 2, 3});
      slog::Relation* readrel723 = db->getRelation("select_branch");
      select_branchdelta708 = readrel723->getIndex(ord722, true);
      std::vector<u16> ord724({2, 3, 1, 0, 4, 5});
      slog::Relation* readrel725 = db->getRelation("$sup70016x87x0x0x0");
      $sup70016x87x0x0x0index695 = readrel725->getIndex(ord724, false);
      std::vector<u16> ord726({1, 0});
      slog::Relation* readrel727 = db->getRelation("eval_ans");
      eval_ansindex696 = readrel727->getIndex(ord726, false);
      std::vector<u16> ord728({2, 3, 0, 1});
      slog::Relation* readrel729 = db->getRelation("if");
      ifindex697 = readrel729->getIndex(ord728, false);
      std::vector<u16> ord730({2, 3, 0, 1});
      slog::Relation* readrel731 = db->getRelation("if");
      ifdelta709 = readrel731->getIndex(ord730, true);
      std::vector<u16> ord732({1, 2, 3, 0});
      slog::Relation* readrel733 = db->getRelation("eval");
      evalindex698 = readrel733->getIndex(ord732, false);
      std::vector<u16> ord734({1, 2, 3, 0});
      slog::Relation* readrel735 = db->getRelation("eval");
      evalindex699 = readrel735->getIndex(ord734, false);
      std::vector<u16> ord736({2, 3, 1, 0, 4, 5});
      slog::Relation* readrel737 = db->getRelation("$sup70016x87x0x0x0");
      $sup70016x87x0x0x0index700 = readrel737->getIndex(ord736, false);
      std::vector<u16> ord738({2, 3, 1, 0, 4, 5});
      slog::Relation* readrel739 = db->getRelation("$sup70016x87x0x0x0");
      $sup70016x87x0x0x0delta710 = readrel739->getIndex(ord738, true);
      std::vector<u16> ord740({2, 3, 0, 1});
      slog::Relation* readrel741 = db->getRelation("eval");
      evalindex701 = readrel741->getIndex(ord740, false);
      std::vector<u16> ord742({2, 3, 0, 1});
      slog::Relation* readrel743 = db->getRelation("eval");
      evaldelta711 = readrel743->getIndex(ord742, true);
      std::vector<u16> ord744({1, 2, 3, 0});
      slog::Relation* readrel745 = db->getRelation("eval");
      evalindex702 = readrel745->getIndex(ord744, false);
      std::vector<u16> ord746({1, 2, 3, 0});
      slog::Relation* readrel747 = db->getRelation("eval");
      evalindex703 = readrel747->getIndex(ord746, false);
      std::vector<u16> ord748({1, 2, 3, 0});
      slog::Relation* readrel749 = db->getRelation("eval");
      evaldelta712 = readrel749->getIndex(ord748, true);
      std::vector<u16> ord750({0, 1});
      slog::Relation* readrel751 = db->getRelation("eval_ans");
      eval_ansindex704 = readrel751->getIndex(ord750, false);
      std::vector<u16> ord752({1, 2, 3, 0});
      slog::Relation* readrel753 = db->getRelation("eval");
      evalindex705 = readrel753->getIndex(ord752, false);
      std::vector<u16> ord754({1, 2, 3, 0});
      slog::Relation* readrel755 = db->getRelation("eval");
      evaldelta713 = readrel755->getIndex(ord754, true);
      std::vector<u16> ord756({0, 1});
      slog::Relation* readrel757 = db->getRelation("eval_ans");
      eval_ansindex706 = readrel757->getIndex(ord756, false);
      std::vector<u16> ord758({0, 1});
      slog::Relation* readrel759 = db->getRelation("eval_ans");
      eval_ansindex707 = readrel759->getIndex(ord758, false);
      std::vector<u16> ord760({0, 1});
      slog::Relation* readrel761 = db->getRelation("eval_ans");
      eval_ansdelta714 = readrel761->getIndex(ord760, true);
  
    }
    ReadTask715(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c140 = _t[1];
        if (!slog::exists_probe<4,1>(evalindex693, std::array<u64,4>{v_c140, 0, 0, 0})) return;
        slog::join_probe_old<4,1>(select_branchindex694, select_branchdelta708, std::array<u64,4>{v_c139, 0, 0, 0}, [&](const std::array<u64,4>& m762) {
          u64 v_c71 = m762[1]; u64 v_c103 = m762[2]; u64 v_c104 = m762[3];
          if (!slog::exists_probe<6,2>($sup70016x87x0x0x0index695, std::array<u64,6>{v_c103, v_c104, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<2,1>(eval_ansindex696, std::array<u64,2>{v_c71, 0})) return;
          slog::join_probe_old<4,2>(ifindex697, ifdelta709, std::array<u64,4>{v_c103, v_c104, 0, 0}, [&](const std::array<u64,4>& m763) {
            u64 v_c141 = m763[2]; u64 v_c137 = m763[3];
            if (!slog::exists_probe<4,1>(evalindex698, std::array<u64,4>{v_c141, 0, 0, 0})) return;
            if (!slog::exists_probe<4,1>(evalindex699, std::array<u64,4>{v_c137, 0, 0, 0})) return;
            slog::join_probe_old<6,3>($sup70016x87x0x0x0index700, $sup70016x87x0x0x0delta710, std::array<u64,6>{v_c103, v_c104, v_c137, 0, 0, 0}, [&](const std::array<u64,6>& m764) {
              u64 v_c142 = m764[3]; u64 v_c94 = m764[4]; u64 v_c47 = m764[5];
              slog::join_probe_old<4,4>(evalindex701, evaldelta711, std::array<u64,4>{v_c94, v_c47, v_c142, v_c141}, [&](const std::array<u64,4>& m765) {
                if (!slog::exists_probe<4,3>(evalindex702, std::array<u64,4>{v_c140, v_c94, v_c47, 0})) return;
                slog::join_probe_old<4,3>(evalindex703, evaldelta712, std::array<u64,4>{v_c137, v_c94, v_c47, 0}, [&](const std::array<u64,4>& m766) {
                  u64 v_c143 = m766[3];
                  if (!slog::exists_probe<2,2>(eval_ansindex704, std::array<u64,2>{v_c143, v_c71})) return;
                  slog::join_probe_old<4,3>(evalindex705, evaldelta713, std::array<u64,4>{v_c140, v_c94, v_c47, 0}, [&](const std::array<u64,4>& m767) {
                    u64 v_c144 = m767[3];
                    slog::join_probe<2,2>(eval_ansindex706, std::array<u64,2>{v_c143, v_c71}, [&](const std::array<u64,2>& m768) {
                      slog::join_probe_old<2,1>(eval_ansindex707, eval_ansdelta714, std::array<u64,2>{v_c144, 0}, [&](const std::array<u64,2>& m769) {
                        u64 v_c145 = m769[1];
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c142, v_c145}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:88", "delta:select_branch_ans", _fires);
  
      if (!_done)
      {
        ReadTask715* _cont = new ReadTask715(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask715(db,b), false);
  // (crule (pre) (scan temp1h2m2046 __t9B8M434) (body) (head (mkstruct mp_hsb (1 0) __9uHQ1202 __t9B8M434)) map.slog:30 #f)
  class ReadTask770 : public slog::Task
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
      head_rel[0] = db->getRelation("mp_hsb");
      outer_rel = db->getRelation("temp1h2m2046");
  
    }
    ReadTask770(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        ++_fires;
        slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c146}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:30", "delta:temp1h2m2046", _fires);
  
      if (!_done)
      {
        ReadTask770* _cont = new ReadTask770(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask770(db,b), false);
  // (crule (pre (let __tconst8hOq309 const6b86b273ff34fce19d6b804e)) (scan mp_del __t0iNt308 __t62gM307 k) (body (exists mp_msk (1 2 0) 1 k) (exists mp_del (2 0 1) 1 k) (join $sup5638x82x0x0x0 (0 1 2 3 4 5) 2 __t0iNt308 k l m p r) (join mbranch (1 2 3 4 0) 5 p m l r __t62gM307) (exists mp_msk (1 2 0) 2 k m) (exists mp_msk_ans (1 0) 1 p) (exists mp_del (1 2 0) 2 l k) (join-old mp_bld (2 1 4 0 3) 3 (2 1 4 0 3) m p r __t8pI6311 __v0) (exists mp_del_ans (1 0) 1 __v0) (exists mp_bld_ans (0 1) 1 __t8pI6311) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t8vNz312) (join mp_msk_ans (0 1) 2 __t8vNz312 p) (join-old mp_del (1 2 0) 2 (1 2 0) l k __t1hIi313) (join mp_del_ans (0 1) 2 __t1hIi313 __v0) (join mp_bld_ans (0 1) 1 __t8pI6311 res) (let __t3mg0310 (band k m)) (cmp lt __t3mg0310 __tconst8hOq309)) (head (emit mp_del_ans (0 1) __t0iNt308 res)) map.slog:83 #f)
  class ReadTask789 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_mskindex771;  slog::Index** mp_delindex772;  slog::Index** $sup5638x82x0x0x0index773;  slog::Index** mbranchindex774;  slog::Index** mp_mskindex775;  slog::Index** mp_msk_ansindex776;  slog::Index** mp_delindex777;  slog::Index** mp_bldindex778;  slog::Index** mp_del_ansindex779;  slog::Index** mp_bld_ansindex780;  slog::Index** mp_mskindex781;  slog::Index** mp_msk_ansindex782;  slog::Index** mp_delindex783;  slog::Index** mp_del_ansindex784;  slog::Index** mp_bld_ansindex785;  slog::Index** mp_blddelta786;  slog::Index** mp_mskdelta787;  slog::Index** mp_deldelta788;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord790({0, 1});
      slog::Relation* readrel791 = db->getRelation("mp_del_ans");
      head_index[0] = readrel791->getIndex(ord790, false);
      outer_rel = db->getRelation("mp_del");
      std::vector<u16> ord792({1, 2, 0});
      slog::Relation* readrel793 = db->getRelation("mp_msk");
      mp_mskindex771 = readrel793->getIndex(ord792, false);
      std::vector<u16> ord794({2, 0, 1});
      slog::Relation* readrel795 = db->getRelation("mp_del");
      mp_delindex772 = readrel795->getIndex(ord794, false);
      std::vector<u16> ord796({0, 1, 2, 3, 4, 5});
      slog::Relation* readrel797 = db->getRelation("$sup5638x82x0x0x0");
      $sup5638x82x0x0x0index773 = readrel797->getIndex(ord796, false);
      std::vector<u16> ord798({1, 2, 3, 4, 0});
      slog::Relation* readrel799 = db->getRelation("mbranch");
      mbranchindex774 = readrel799->getIndex(ord798, false);
      std::vector<u16> ord800({1, 2, 0});
      slog::Relation* readrel801 = db->getRelation("mp_msk");
      mp_mskindex775 = readrel801->getIndex(ord800, false);
      std::vector<u16> ord802({1, 0});
      slog::Relation* readrel803 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex776 = readrel803->getIndex(ord802, false);
      std::vector<u16> ord804({1, 2, 0});
      slog::Relation* readrel805 = db->getRelation("mp_del");
      mp_delindex777 = readrel805->getIndex(ord804, false);
      std::vector<u16> ord806({2, 1, 4, 0, 3});
      slog::Relation* readrel807 = db->getRelation("mp_bld");
      mp_bldindex778 = readrel807->getIndex(ord806, false);
      std::vector<u16> ord808({2, 1, 4, 0, 3});
      slog::Relation* readrel809 = db->getRelation("mp_bld");
      mp_blddelta786 = readrel809->getIndex(ord808, true);
      std::vector<u16> ord810({1, 0});
      slog::Relation* readrel811 = db->getRelation("mp_del_ans");
      mp_del_ansindex779 = readrel811->getIndex(ord810, false);
      std::vector<u16> ord812({0, 1});
      slog::Relation* readrel813 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex780 = readrel813->getIndex(ord812, false);
      std::vector<u16> ord814({1, 2, 0});
      slog::Relation* readrel815 = db->getRelation("mp_msk");
      mp_mskindex781 = readrel815->getIndex(ord814, false);
      std::vector<u16> ord816({1, 2, 0});
      slog::Relation* readrel817 = db->getRelation("mp_msk");
      mp_mskdelta787 = readrel817->getIndex(ord816, true);
      std::vector<u16> ord818({0, 1});
      slog::Relation* readrel819 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex782 = readrel819->getIndex(ord818, false);
      std::vector<u16> ord820({1, 2, 0});
      slog::Relation* readrel821 = db->getRelation("mp_del");
      mp_delindex783 = readrel821->getIndex(ord820, false);
      std::vector<u16> ord822({1, 2, 0});
      slog::Relation* readrel823 = db->getRelation("mp_del");
      mp_deldelta788 = readrel823->getIndex(ord822, true);
      std::vector<u16> ord824({0, 1});
      slog::Relation* readrel825 = db->getRelation("mp_del_ans");
      mp_del_ansindex784 = readrel825->getIndex(ord824, false);
      std::vector<u16> ord826({0, 1});
      slog::Relation* readrel827 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex785 = readrel827->getIndex(ord826, false);
  
    }
    ReadTask789(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c147 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c148 = _t[0];
        u64 v_c149 = _t[1];
        u64 v_c25 = _t[2];
        if (!slog::exists_probe<3,1>(mp_mskindex771, std::array<u64,3>{v_c25, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_delindex772, std::array<u64,3>{v_c25, 0, 0})) return;
        slog::join_probe<6,2>($sup5638x82x0x0x0index773, std::array<u64,6>{v_c148, v_c25, 0, 0, 0, 0}, [&](const std::array<u64,6>& m828) {
          u64 v_c26 = m828[2]; u64 v_c27 = m828[3]; u64 v_c28 = m828[4]; u64 v_c29 = m828[5];
          slog::join_probe<5,5>(mbranchindex774, std::array<u64,5>{v_c28, v_c27, v_c26, v_c29, v_c149}, [&](const std::array<u64,5>& m829) {
            if (!slog::exists_probe<3,2>(mp_mskindex775, std::array<u64,3>{v_c25, v_c27, 0})) return;
            if (!slog::exists_probe<2,1>(mp_msk_ansindex776, std::array<u64,2>{v_c28, 0})) return;
            if (!slog::exists_probe<3,2>(mp_delindex777, std::array<u64,3>{v_c26, v_c25, 0})) return;
            slog::join_probe_old<5,3>(mp_bldindex778, mp_blddelta786, std::array<u64,5>{v_c27, v_c28, v_c29, 0, 0}, [&](const std::array<u64,5>& m830) {
              u64 v_c150 = m830[3]; u64 v_c71 = m830[4];
              if (!slog::exists_probe<2,1>(mp_del_ansindex779, std::array<u64,2>{v_c71, 0})) return;
              if (!slog::exists_probe<2,1>(mp_bld_ansindex780, std::array<u64,2>{v_c150, 0})) return;
              slog::join_probe_old<3,2>(mp_mskindex781, mp_mskdelta787, std::array<u64,3>{v_c25, v_c27, 0}, [&](const std::array<u64,3>& m831) {
                u64 v_c151 = m831[2];
                slog::join_probe<2,2>(mp_msk_ansindex782, std::array<u64,2>{v_c151, v_c28}, [&](const std::array<u64,2>& m832) {
                  slog::join_probe_old<3,2>(mp_delindex783, mp_deldelta788, std::array<u64,3>{v_c26, v_c25, 0}, [&](const std::array<u64,3>& m833) {
                    u64 v_c152 = m833[2];
                    slog::join_probe<2,2>(mp_del_ansindex784, std::array<u64,2>{v_c152, v_c71}, [&](const std::array<u64,2>& m834) {
                      slog::join_probe<2,1>(mp_bld_ansindex785, std::array<u64,2>{v_c150, 0}, [&](const std::array<u64,2>& m835) {
                        u64 v_c86 = m835[1];
                        u64 v_c153 = _prim_band(db, v_c25, v_c27);
                        if (v_c153 == slog_error) { slog::emit_pending_error(db, "map.slog:83"); return; }
                        u64 v_c154 = _prim_lt(db, v_c153, v_c147);
                        if (v_c154 == slog_error) { slog::emit_pending_error(db, "map.slog:83"); return; }
                        if (!v_c154) return;
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c148, v_c86}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("map.slog:83", "delta:mp_del", _fires);
  
      if (!_done)
      {
        ReadTask789* _cont = new ReadTask789(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask789(db,b), false);
  // (crule (pre) (scan lambda __t6iPm534 xs eb) (body (exists extend_env (2 3 0 1) 1 xs) (exists eval (1 2 3 0) 1 eb) (exists $sup70016x51x0x0x1 (4 12 8 1 10 0 2 3 5 6 7 9 11) 2 eb xs) (join-old closure (1 2 0) 1 (1 2 0) __t6iPm534 rhoc __t9dfl535) (exists $sup70016x51x0x0x1 (4 12 8 1 10 0 2 3 5 6 7 9 11) 3 eb xs rhoc) (exists eval_ans (1 0) 1 __t9dfl535) (join-old extend_env (1 2 3 0) 2 (1 2 3 0) rhoc xs t2 __t5fzh540) (exists extend_env_ans (0 1) 1 __t5fzh540) (exists $sup70016x51x0x0x1 (4 10 8 12 0 1 2 3 5 6 7 9 11) 4 eb t2 rhoc xs) (exists tick_ans (1 0) 1 t2) (join-old eval (3 1 0 2) 2 (3 1 0 2) t2 eb __t7TaT537 __v0) (join extend_env_ans (0 1) 2 __t5fzh540 __v0) (exists eval_ans (0 1) 1 __t7TaT537) (join $sup70016x51x0x0x1 (4 10 8 12 0 1 2 3 5 6 7 9 11) 4 eb t2 rhoc xs __t2z6s532 __t5qy8533 __t2srV536 __t0CD9539 ef es rho t vs) (join $sup70016x51x0x0x0 (4 0 3 1 2) 5 t __t2z6s532 rho ef es) (join eval (2 3 0 1) 4 rho t __t5qy8533 ef) (join-old eval_args (3 2 0 1) 4 (3 2 0 1) t rho __t2srV536 es) (exists app (1 2 0) 2 ef es) (exists tick (0 2 1) 2 __t0CD9539 t) (exists eval_ans (0 1) 2 __t5qy8533 __t9dfl535) (exists eval_args_ans (0 1) 2 __t2srV536 vs) (exists tick_ans (0 1) 2 __t0CD9539 t2) (join eval (2 3 0 1) 3 rho t __t2z6s532 __t5a7h538) (join-old app (0 1 2) 3 (0 1 2) __t5a7h538 ef es) (join-old tick (0 2 1) 3 (0 2 1) __t0CD9539 t __t5a7h538) (join eval_ans (0 1) 2 __t5qy8533 __t9dfl535) (join eval_args_ans (0 1) 2 __t2srV536 vs) (join tick_ans (0 1) 2 __t0CD9539 t2) (join eval_ans (0 1) 1 __t7TaT537 v)) (head (emit eval_ans (0 1) __t2z6s532 v)) interp.slog:52 #f)
  class ReadTask872 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** extend_envindex837;  slog::Index** evalindex838;  slog::Index** $sup70016x51x0x0x1index839;  slog::Index** closureindex840;  slog::Index** $sup70016x51x0x0x1index841;  slog::Index** eval_ansindex842;  slog::Index** extend_envindex843;  slog::Index** extend_env_ansindex844;  slog::Index** $sup70016x51x0x0x1index845;  slog::Index** tick_ansindex846;  slog::Index** evalindex847;  slog::Index** extend_env_ansindex848;  slog::Index** eval_ansindex849;  slog::Index** $sup70016x51x0x0x1index850;  slog::Index** $sup70016x51x0x0x0index851;  slog::Index** evalindex852;  slog::Index** eval_argsindex853;  slog::Index** appindex854;  slog::Index** tickindex855;  slog::Index** eval_ansindex856;  slog::Index** eval_args_ansindex857;  slog::Index** tick_ansindex858;  slog::Index** evalindex859;  slog::Index** appindex860;  slog::Index** tickindex861;  slog::Index** eval_ansindex862;  slog::Index** eval_args_ansindex863;  slog::Index** tick_ansindex864;  slog::Index** eval_ansindex865;  slog::Index** closuredelta866;  slog::Index** extend_envdelta867;  slog::Index** evaldelta868;  slog::Index** eval_argsdelta869;  slog::Index** appdelta870;  slog::Index** tickdelta871;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord873({0, 1});
      slog::Relation* readrel874 = db->getRelation("eval_ans");
      head_index[0] = readrel874->getIndex(ord873, false);
      outer_rel = db->getRelation("lambda");
      std::vector<u16> ord875({2, 3, 0, 1});
      slog::Relation* readrel876 = db->getRelation("extend_env");
      extend_envindex837 = readrel876->getIndex(ord875, false);
      std::vector<u16> ord877({1, 2, 3, 0});
      slog::Relation* readrel878 = db->getRelation("eval");
      evalindex838 = readrel878->getIndex(ord877, false);
      std::vector<u16> ord879({4, 12, 8, 1, 10, 0, 2, 3, 5, 6, 7, 9, 11});
      slog::Relation* readrel880 = db->getRelation("$sup70016x51x0x0x1");
      $sup70016x51x0x0x1index839 = readrel880->getIndex(ord879, false);
      std::vector<u16> ord881({1, 2, 0});
      slog::Relation* readrel882 = db->getRelation("closure");
      closureindex840 = readrel882->getIndex(ord881, false);
      std::vector<u16> ord883({1, 2, 0});
      slog::Relation* readrel884 = db->getRelation("closure");
      closuredelta866 = readrel884->getIndex(ord883, true);
      std::vector<u16> ord885({4, 12, 8, 1, 10, 0, 2, 3, 5, 6, 7, 9, 11});
      slog::Relation* readrel886 = db->getRelation("$sup70016x51x0x0x1");
      $sup70016x51x0x0x1index841 = readrel886->getIndex(ord885, false);
      std::vector<u16> ord887({1, 0});
      slog::Relation* readrel888 = db->getRelation("eval_ans");
      eval_ansindex842 = readrel888->getIndex(ord887, false);
      std::vector<u16> ord889({1, 2, 3, 0});
      slog::Relation* readrel890 = db->getRelation("extend_env");
      extend_envindex843 = readrel890->getIndex(ord889, false);
      std::vector<u16> ord891({1, 2, 3, 0});
      slog::Relation* readrel892 = db->getRelation("extend_env");
      extend_envdelta867 = readrel892->getIndex(ord891, true);
      std::vector<u16> ord893({0, 1});
      slog::Relation* readrel894 = db->getRelation("extend_env_ans");
      extend_env_ansindex844 = readrel894->getIndex(ord893, false);
      std::vector<u16> ord895({4, 10, 8, 12, 0, 1, 2, 3, 5, 6, 7, 9, 11});
      slog::Relation* readrel896 = db->getRelation("$sup70016x51x0x0x1");
      $sup70016x51x0x0x1index845 = readrel896->getIndex(ord895, false);
      std::vector<u16> ord897({1, 0});
      slog::Relation* readrel898 = db->getRelation("tick_ans");
      tick_ansindex846 = readrel898->getIndex(ord897, false);
      std::vector<u16> ord899({3, 1, 0, 2});
      slog::Relation* readrel900 = db->getRelation("eval");
      evalindex847 = readrel900->getIndex(ord899, false);
      std::vector<u16> ord901({3, 1, 0, 2});
      slog::Relation* readrel902 = db->getRelation("eval");
      evaldelta868 = readrel902->getIndex(ord901, true);
      std::vector<u16> ord903({0, 1});
      slog::Relation* readrel904 = db->getRelation("extend_env_ans");
      extend_env_ansindex848 = readrel904->getIndex(ord903, false);
      std::vector<u16> ord905({0, 1});
      slog::Relation* readrel906 = db->getRelation("eval_ans");
      eval_ansindex849 = readrel906->getIndex(ord905, false);
      std::vector<u16> ord907({4, 10, 8, 12, 0, 1, 2, 3, 5, 6, 7, 9, 11});
      slog::Relation* readrel908 = db->getRelation("$sup70016x51x0x0x1");
      $sup70016x51x0x0x1index850 = readrel908->getIndex(ord907, false);
      std::vector<u16> ord909({4, 0, 3, 1, 2});
      slog::Relation* readrel910 = db->getRelation("$sup70016x51x0x0x0");
      $sup70016x51x0x0x0index851 = readrel910->getIndex(ord909, false);
      std::vector<u16> ord911({2, 3, 0, 1});
      slog::Relation* readrel912 = db->getRelation("eval");
      evalindex852 = readrel912->getIndex(ord911, false);
      std::vector<u16> ord913({3, 2, 0, 1});
      slog::Relation* readrel914 = db->getRelation("eval_args");
      eval_argsindex853 = readrel914->getIndex(ord913, false);
      std::vector<u16> ord915({3, 2, 0, 1});
      slog::Relation* readrel916 = db->getRelation("eval_args");
      eval_argsdelta869 = readrel916->getIndex(ord915, true);
      std::vector<u16> ord917({1, 2, 0});
      slog::Relation* readrel918 = db->getRelation("app");
      appindex854 = readrel918->getIndex(ord917, false);
      std::vector<u16> ord919({0, 2, 1});
      slog::Relation* readrel920 = db->getRelation("tick");
      tickindex855 = readrel920->getIndex(ord919, false);
      std::vector<u16> ord921({0, 1});
      slog::Relation* readrel922 = db->getRelation("eval_ans");
      eval_ansindex856 = readrel922->getIndex(ord921, false);
      std::vector<u16> ord923({0, 1});
      slog::Relation* readrel924 = db->getRelation("eval_args_ans");
      eval_args_ansindex857 = readrel924->getIndex(ord923, false);
      std::vector<u16> ord925({0, 1});
      slog::Relation* readrel926 = db->getRelation("tick_ans");
      tick_ansindex858 = readrel926->getIndex(ord925, false);
      std::vector<u16> ord927({2, 3, 0, 1});
      slog::Relation* readrel928 = db->getRelation("eval");
      evalindex859 = readrel928->getIndex(ord927, false);
      std::vector<u16> ord929({0, 1, 2});
      slog::Relation* readrel930 = db->getRelation("app");
      appindex860 = readrel930->getIndex(ord929, false);
      std::vector<u16> ord931({0, 1, 2});
      slog::Relation* readrel932 = db->getRelation("app");
      appdelta870 = readrel932->getIndex(ord931, true);
      std::vector<u16> ord933({0, 2, 1});
      slog::Relation* readrel934 = db->getRelation("tick");
      tickindex861 = readrel934->getIndex(ord933, false);
      std::vector<u16> ord935({0, 2, 1});
      slog::Relation* readrel936 = db->getRelation("tick");
      tickdelta871 = readrel936->getIndex(ord935, true);
      std::vector<u16> ord937({0, 1});
      slog::Relation* readrel938 = db->getRelation("eval_ans");
      eval_ansindex862 = readrel938->getIndex(ord937, false);
      std::vector<u16> ord939({0, 1});
      slog::Relation* readrel940 = db->getRelation("eval_args_ans");
      eval_args_ansindex863 = readrel940->getIndex(ord939, false);
      std::vector<u16> ord941({0, 1});
      slog::Relation* readrel942 = db->getRelation("tick_ans");
      tick_ansindex864 = readrel942->getIndex(ord941, false);
      std::vector<u16> ord943({0, 1});
      slog::Relation* readrel944 = db->getRelation("eval_ans");
      eval_ansindex865 = readrel944->getIndex(ord943, false);
  
    }
    ReadTask872(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c155 = _t[0];
        u64 v_c120 = _t[1];
        u64 v_c88 = _t[2];
        if (!slog::exists_probe<4,1>(extend_envindex837, std::array<u64,4>{v_c120, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(evalindex838, std::array<u64,4>{v_c88, 0, 0, 0})) return;
        if (!slog::exists_probe<13,2>($sup70016x51x0x0x1index839, std::array<u64,13>{v_c88, v_c120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(closureindex840, closuredelta866, std::array<u64,3>{v_c155, 0, 0}, [&](const std::array<u64,3>& m945) {
          u64 v_c119 = m945[1]; u64 v_c156 = m945[2];
          if (!slog::exists_probe<13,3>($sup70016x51x0x0x1index841, std::array<u64,13>{v_c88, v_c120, v_c119, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<2,1>(eval_ansindex842, std::array<u64,2>{v_c156, 0})) return;
          slog::join_probe_old<4,2>(extend_envindex843, extend_envdelta867, std::array<u64,4>{v_c119, v_c120, 0, 0}, [&](const std::array<u64,4>& m946) {
            u64 v_c117 = m946[2]; u64 v_c157 = m946[3];
            if (!slog::exists_probe<2,1>(extend_env_ansindex844, std::array<u64,2>{v_c157, 0})) return;
            if (!slog::exists_probe<13,4>($sup70016x51x0x0x1index845, std::array<u64,13>{v_c88, v_c117, v_c119, v_c120, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<2,1>(tick_ansindex846, std::array<u64,2>{v_c117, 0})) return;
            slog::join_probe_old<4,2>(evalindex847, evaldelta868, std::array<u64,4>{v_c117, v_c88, 0, 0}, [&](const std::array<u64,4>& m947) {
              u64 v_c158 = m947[2]; u64 v_c71 = m947[3];
              slog::join_probe<2,2>(extend_env_ansindex848, std::array<u64,2>{v_c157, v_c71}, [&](const std::array<u64,2>& m948) {
                if (!slog::exists_probe<2,1>(eval_ansindex849, std::array<u64,2>{v_c158, 0})) return;
                slog::join_probe<13,4>($sup70016x51x0x0x1index850, std::array<u64,13>{v_c88, v_c117, v_c119, v_c120, 0, 0, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,13>& m949) {
                  u64 v_c159 = m949[4]; u64 v_c160 = m949[5]; u64 v_c161 = m949[6]; u64 v_c162 = m949[7]; u64 v_c112 = m949[8]; u64 v_c111 = m949[9]; u64 v_c94 = m949[10]; u64 v_c47 = m949[11]; u64 v_c110 = m949[12];
                  slog::join_probe<5,5>($sup70016x51x0x0x0index851, std::array<u64,5>{v_c47, v_c159, v_c94, v_c112, v_c111}, [&](const std::array<u64,5>& m950) {
                    slog::join_probe<4,4>(evalindex852, std::array<u64,4>{v_c94, v_c47, v_c160, v_c112}, [&](const std::array<u64,4>& m951) {
                      slog::join_probe_old<4,4>(eval_argsindex853, eval_argsdelta869, std::array<u64,4>{v_c47, v_c94, v_c161, v_c111}, [&](const std::array<u64,4>& m952) {
                        if (!slog::exists_probe<3,2>(appindex854, std::array<u64,3>{v_c112, v_c111, 0})) return;
                        if (!slog::exists_probe<3,2>(tickindex855, std::array<u64,3>{v_c162, v_c47, 0})) return;
                        if (!slog::exists_probe<2,2>(eval_ansindex856, std::array<u64,2>{v_c160, v_c156})) return;
                        if (!slog::exists_probe<2,2>(eval_args_ansindex857, std::array<u64,2>{v_c161, v_c110})) return;
                        if (!slog::exists_probe<2,2>(tick_ansindex858, std::array<u64,2>{v_c162, v_c117})) return;
                        slog::join_probe<4,3>(evalindex859, std::array<u64,4>{v_c94, v_c47, v_c159, 0}, [&](const std::array<u64,4>& m953) {
                          u64 v_c163 = m953[3];
                          slog::join_probe_old<3,3>(appindex860, appdelta870, std::array<u64,3>{v_c163, v_c112, v_c111}, [&](const std::array<u64,3>& m954) {
                            slog::join_probe_old<3,3>(tickindex861, tickdelta871, std::array<u64,3>{v_c162, v_c47, v_c163}, [&](const std::array<u64,3>& m955) {
                              slog::join_probe<2,2>(eval_ansindex862, std::array<u64,2>{v_c160, v_c156}, [&](const std::array<u64,2>& m956) {
                                slog::join_probe<2,2>(eval_args_ansindex863, std::array<u64,2>{v_c161, v_c110}, [&](const std::array<u64,2>& m957) {
                                  slog::join_probe<2,2>(tick_ansindex864, std::array<u64,2>{v_c162, v_c117}, [&](const std::array<u64,2>& m958) {
                                    slog::join_probe<2,1>(eval_ansindex865, std::array<u64,2>{v_c158, 0}, [&](const std::array<u64,2>& m959) {
                                      u64 v_c30 = m959[1];
                                      ++_fires;
                                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c159, v_c30}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:52", "delta:lambda", _fires);
  
      if (!_done)
      {
        ReadTask872* _cont = new ReadTask872(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask872(db,b), false);
  // (crule (pre (let __tconst7FS91443 constcd2a69ce5ca278db1d6da969)) (scan num __t1Nbh247 n) (body (exists eval (1 2 3 0) 1 __t1Nbh247) (join _enum (1 0) 1 __tconst7FS91443 __t49OJ246) (join-old eval (1 2 3 0) 1 (1 2 3 0) __t1Nbh247 rho t __t7Kqt248)) (head (emit eval_ans (0 1) __t7Kqt248 __t49OJ246)) interp.slog:30 #f)
  class ReadTask964 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex960;  slog::Index** _enumindex961;  slog::Index** evalindex962;  slog::Index** evaldelta963;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord965({0, 1});
      slog::Relation* readrel966 = db->getRelation("eval_ans");
      head_index[0] = readrel966->getIndex(ord965, false);
      outer_rel = db->getRelation("num");
      std::vector<u16> ord967({1, 2, 3, 0});
      slog::Relation* readrel968 = db->getRelation("eval");
      evalindex960 = readrel968->getIndex(ord967, false);
      std::vector<u16> ord969({1, 0});
      slog::Relation* readrel970 = db->getRelation("_enum");
      _enumindex961 = readrel970->getIndex(ord969, false);
      std::vector<u16> ord971({1, 2, 3, 0});
      slog::Relation* readrel972 = db->getRelation("eval");
      evalindex962 = readrel972->getIndex(ord971, false);
      std::vector<u16> ord973({1, 2, 3, 0});
      slog::Relation* readrel974 = db->getRelation("eval");
      evaldelta963 = readrel974->getIndex(ord973, true);
  
    }
    ReadTask964(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c164 = v_constcd2a69ce5ca278db1d6da969;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c165 = _t[0];
        u64 v_c78 = _t[1];
        if (!slog::exists_probe<4,1>(evalindex960, std::array<u64,4>{v_c165, 0, 0, 0})) return;
        slog::join_probe<2,1>(_enumindex961, std::array<u64,2>{v_c164, 0}, [&](const std::array<u64,2>& m975) {
          u64 v_c166 = m975[1];
          slog::join_probe_old<4,1>(evalindex962, evaldelta963, std::array<u64,4>{v_c165, 0, 0, 0}, [&](const std::array<u64,4>& m976) {
            u64 v_c94 = m976[1]; u64 v_c47 = m976[2]; u64 v_c167 = m976[3];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c167, v_c166}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:30", "delta:num", _fires);
  
      if (!_done)
      {
        ReadTask964* _cont = new ReadTask964(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask964(db,b), false);
  // (crule (pre) (scan app __t4vgN655 ef es) (body (join eval (1 2 3 0) 1 __t4vgN655 rho t __9j5V1330)) (head (mkstruct tick (1 2 0) __49qT1331 __t4vgN655 t)) interp.slog:59 #f)
  class ReadTask978 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex977;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("tick");
      outer_rel = db->getRelation("app");
      std::vector<u16> ord979({1, 2, 3, 0});
      slog::Relation* readrel980 = db->getRelation("eval");
      evalindex977 = readrel980->getIndex(ord979, false);
  
    }
    ReadTask978(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c168 = _t[0];
        u64 v_c112 = _t[1];
        u64 v_c111 = _t[2];
        slog::join_probe<4,1>(evalindex977, std::array<u64,4>{v_c168, 0, 0, 0}, [&](const std::array<u64,4>& m981) {
          u64 v_c94 = m981[1]; u64 v_c47 = m981[2]; u64 v_c169 = m981[3];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c168, v_c47}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:59", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask978* _cont = new ReadTask978(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask978(db,b), false);
  // (crule (pre (let __tconst7oJb145 const6b86b273ff34fce19d6b804e)) (scan $sup5638x104x0x0x0 __t0kfV144 l m n p q r u v) (body (cmp lt m n) (exists mbranch (1 2 3 4 0) 4 q n u v) (exists mbranch (1 2 3 4 0) 4 p m l r) (exists mp_msk (1 2 0) 2 p n) (exists mp_msk_ans (1 0) 1 q) (exists mp_union (2 0 1) 1 u) (join-old $sup5638x104x0x0x1 (8 4 6 9 0 2 3 5 7 1) 9 (8 4 6 9 0 2 3 5 7 1) u n q v __t0kfV144 l m p r __t7PVf147) (exists mp_msk (1 2 0) 3 p n __t7PVf147) (exists mp_msk_ans (0 1) 2 __t7PVf147 q) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t2NO6142) (exists mp_union (2 0 1) 2 __t2NO6142 __t0kfV144) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t5mfE148) (join-old mp_union (0 1 2) 3 (0 1 2) __t0kfV144 __t5mfE148 __t2NO6142) (join-old mp_msk (1 2 0) 3 (1 2 0) p n __t7PVf147) (join mp_msk_ans (0 1) 2 __t7PVf147 q) (join-old mp_union (1 2 0) 2 (1 2 0) __t5mfE148 u __t221b149) (join mp_union_ans (0 1) 1 __t221b149 __v0) (let __t5ygO146 (band p n)) (cmp lt __t5ygO146 __tconst7oJb145)) (head (emit-temp temp9IEi1871 __t0kfV144 __v0 n q v) (mkstruct mbranch (1 2 3 4 0) __t4DAr141 q n __v0 v)) map.slog:105 #f)
  class ReadTask1004 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex982;  slog::Index** mbranchindex983;  slog::Index** mp_mskindex984;  slog::Index** mp_msk_ansindex985;  slog::Index** mp_unionindex986;  slog::Index** $sup5638x104x0x0x1index987;  slog::Index** mp_mskindex988;  slog::Index** mp_msk_ansindex989;  slog::Index** mbranchindex990;  slog::Index** mp_unionindex991;  slog::Index** mbranchindex992;  slog::Index** mp_unionindex993;  slog::Index** mp_mskindex994;  slog::Index** mp_msk_ansindex995;  slog::Index** mp_unionindex996;  slog::Index** mp_union_ansindex997;  slog::Index** $sup5638x104x0x0x1delta998;  slog::Index** mbranchdelta999;  slog::Index** mbranchdelta1000;  slog::Index** mp_uniondelta1001;  slog::Index** mp_mskdelta1002;  slog::Index** mp_uniondelta1003;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9IEi1871");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("$sup5638x104x0x0x0");
      std::vector<u16> ord1005({1, 2, 3, 4, 0});
      slog::Relation* readrel1006 = db->getRelation("mbranch");
      mbranchindex982 = readrel1006->getIndex(ord1005, false);
      std::vector<u16> ord1007({1, 2, 3, 4, 0});
      slog::Relation* readrel1008 = db->getRelation("mbranch");
      mbranchindex983 = readrel1008->getIndex(ord1007, false);
      std::vector<u16> ord1009({1, 2, 0});
      slog::Relation* readrel1010 = db->getRelation("mp_msk");
      mp_mskindex984 = readrel1010->getIndex(ord1009, false);
      std::vector<u16> ord1011({1, 0});
      slog::Relation* readrel1012 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex985 = readrel1012->getIndex(ord1011, false);
      std::vector<u16> ord1013({2, 0, 1});
      slog::Relation* readrel1014 = db->getRelation("mp_union");
      mp_unionindex986 = readrel1014->getIndex(ord1013, false);
      std::vector<u16> ord1015({8, 4, 6, 9, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel1016 = db->getRelation("$sup5638x104x0x0x1");
      $sup5638x104x0x0x1index987 = readrel1016->getIndex(ord1015, false);
      std::vector<u16> ord1017({8, 4, 6, 9, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel1018 = db->getRelation("$sup5638x104x0x0x1");
      $sup5638x104x0x0x1delta998 = readrel1018->getIndex(ord1017, true);
      std::vector<u16> ord1019({1, 2, 0});
      slog::Relation* readrel1020 = db->getRelation("mp_msk");
      mp_mskindex988 = readrel1020->getIndex(ord1019, false);
      std::vector<u16> ord1021({0, 1});
      slog::Relation* readrel1022 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex989 = readrel1022->getIndex(ord1021, false);
      std::vector<u16> ord1023({1, 2, 3, 4, 0});
      slog::Relation* readrel1024 = db->getRelation("mbranch");
      mbranchindex990 = readrel1024->getIndex(ord1023, false);
      std::vector<u16> ord1025({1, 2, 3, 4, 0});
      slog::Relation* readrel1026 = db->getRelation("mbranch");
      mbranchdelta999 = readrel1026->getIndex(ord1025, true);
      std::vector<u16> ord1027({2, 0, 1});
      slog::Relation* readrel1028 = db->getRelation("mp_union");
      mp_unionindex991 = readrel1028->getIndex(ord1027, false);
      std::vector<u16> ord1029({1, 2, 3, 4, 0});
      slog::Relation* readrel1030 = db->getRelation("mbranch");
      mbranchindex992 = readrel1030->getIndex(ord1029, false);
      std::vector<u16> ord1031({1, 2, 3, 4, 0});
      slog::Relation* readrel1032 = db->getRelation("mbranch");
      mbranchdelta1000 = readrel1032->getIndex(ord1031, true);
      std::vector<u16> ord1033({0, 1, 2});
      slog::Relation* readrel1034 = db->getRelation("mp_union");
      mp_unionindex993 = readrel1034->getIndex(ord1033, false);
      std::vector<u16> ord1035({0, 1, 2});
      slog::Relation* readrel1036 = db->getRelation("mp_union");
      mp_uniondelta1001 = readrel1036->getIndex(ord1035, true);
      std::vector<u16> ord1037({1, 2, 0});
      slog::Relation* readrel1038 = db->getRelation("mp_msk");
      mp_mskindex994 = readrel1038->getIndex(ord1037, false);
      std::vector<u16> ord1039({1, 2, 0});
      slog::Relation* readrel1040 = db->getRelation("mp_msk");
      mp_mskdelta1002 = readrel1040->getIndex(ord1039, true);
      std::vector<u16> ord1041({0, 1});
      slog::Relation* readrel1042 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex995 = readrel1042->getIndex(ord1041, false);
      std::vector<u16> ord1043({1, 2, 0});
      slog::Relation* readrel1044 = db->getRelation("mp_union");
      mp_unionindex996 = readrel1044->getIndex(ord1043, false);
      std::vector<u16> ord1045({1, 2, 0});
      slog::Relation* readrel1046 = db->getRelation("mp_union");
      mp_uniondelta1003 = readrel1046->getIndex(ord1045, true);
      std::vector<u16> ord1047({0, 1});
      slog::Relation* readrel1048 = db->getRelation("mp_union_ans");
      mp_union_ansindex997 = readrel1048->getIndex(ord1047, false);
  
    }
    ReadTask1004(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c170 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c26 = _t[1];
        u64 v_c27 = _t[2];
        u64 v_c78 = _t[3];
        u64 v_c28 = _t[4];
        u64 v_c82 = _t[5];
        u64 v_c29 = _t[6];
        u64 v_c84 = _t[7];
        u64 v_c30 = _t[8];
        u64 v_c172 = _prim_lt(db, v_c27, v_c78);
        if (v_c172 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
        if (!v_c172) return;
        if (!slog::exists_probe<5,4>(mbranchindex982, std::array<u64,5>{v_c82, v_c78, v_c84, v_c30, 0})) return;
        if (!slog::exists_probe<5,4>(mbranchindex983, std::array<u64,5>{v_c28, v_c27, v_c26, v_c29, 0})) return;
        if (!slog::exists_probe<3,2>(mp_mskindex984, std::array<u64,3>{v_c28, v_c78, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex985, std::array<u64,2>{v_c82, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex986, std::array<u64,3>{v_c84, 0, 0})) return;
        slog::join_probe_old<10,9>($sup5638x104x0x0x1index987, $sup5638x104x0x0x1delta998, std::array<u64,10>{v_c84, v_c78, v_c82, v_c30, v_c171, v_c26, v_c27, v_c28, v_c29, 0}, [&](const std::array<u64,10>& m1050) {
          u64 v_c173 = m1050[9];
          if (!slog::exists_probe<3,3>(mp_mskindex988, std::array<u64,3>{v_c28, v_c78, v_c173})) return;
          if (!slog::exists_probe<2,2>(mp_msk_ansindex989, std::array<u64,2>{v_c173, v_c82})) return;
          slog::join_probe_old<5,4>(mbranchindex990, mbranchdelta999, std::array<u64,5>{v_c82, v_c78, v_c84, v_c30, 0}, [&](const std::array<u64,5>& m1051) {
            u64 v_c174 = m1051[4];
            if (!slog::exists_probe<3,2>(mp_unionindex991, std::array<u64,3>{v_c174, v_c171, 0})) return;
            slog::join_probe_old<5,4>(mbranchindex992, mbranchdelta1000, std::array<u64,5>{v_c28, v_c27, v_c26, v_c29, 0}, [&](const std::array<u64,5>& m1052) {
              u64 v_c175 = m1052[4];
              slog::join_probe_old<3,3>(mp_unionindex993, mp_uniondelta1001, std::array<u64,3>{v_c171, v_c175, v_c174}, [&](const std::array<u64,3>& m1053) {
                slog::join_probe_old<3,3>(mp_mskindex994, mp_mskdelta1002, std::array<u64,3>{v_c28, v_c78, v_c173}, [&](const std::array<u64,3>& m1054) {
                  slog::join_probe<2,2>(mp_msk_ansindex995, std::array<u64,2>{v_c173, v_c82}, [&](const std::array<u64,2>& m1055) {
                    slog::join_probe_old<3,2>(mp_unionindex996, mp_uniondelta1003, std::array<u64,3>{v_c175, v_c84, 0}, [&](const std::array<u64,3>& m1056) {
                      u64 v_c176 = m1056[2];
                      slog::join_probe<2,1>(mp_union_ansindex997, std::array<u64,2>{v_c176, 0}, [&](const std::array<u64,2>& m1057) {
                        u64 v_c71 = m1057[1];
                        u64 v_c177 = _prim_band(db, v_c28, v_c78);
                        if (v_c177 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
                        u64 v_c178 = _prim_lt(db, v_c177, v_c170);
                        if (v_c178 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
                        if (!v_c178) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c171, v_c71, v_c78, v_c82, v_c30});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c82, v_c78, v_c71, v_c30}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:105", "delta:$sup5638x104x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1004* _cont = new ReadTask1004(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1004(db,b), false);
  // (crule (pre) (scan eval __8En81526 __t4Erg439 rho t) (body (join-old let (0 2 1 3) 1 (0 2 1 3) __t4Erg439 er x eb)) (head (mkstruct eval (1 2 3 0) __1wQ81527 er rho t)) interp.slog:94 #f)
  class ReadTask1061 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letindex1059;  slog::Index** letdelta1060;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord1062({0, 2, 1, 3});
      slog::Relation* readrel1063 = db->getRelation("let");
      letindex1059 = readrel1063->getIndex(ord1062, false);
      std::vector<u16> ord1064({0, 2, 1, 3});
      slog::Relation* readrel1065 = db->getRelation("let");
      letdelta1060 = readrel1065->getIndex(ord1064, true);
  
    }
    ReadTask1061(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c179 = _t[0];
        u64 v_c180 = _t[1];
        u64 v_c94 = _t[2];
        u64 v_c47 = _t[3];
        slog::join_probe_old<4,1>(letindex1059, letdelta1060, std::array<u64,4>{v_c180, 0, 0, 0}, [&](const std::array<u64,4>& m1066) {
          u64 v_c91 = m1066[1]; u64 v_c95 = m1066[2]; u64 v_c88 = m1066[3];
          ++_fires;
          slog::emit_struct<4>(head_rel[0], newbatch[0], std::array<u64,3>{v_c91, v_c94, v_c47}, std::array<u16,4>{1, 2, 3, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:94", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask1061* _cont = new ReadTask1061(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1061(db,b), false);
  // (crule (pre) (scan mbranch __t7Hza25 p m l r) (body (exists mbranch (2 0 1 3 4) 1 m) (exists mp_union (1 2 0) 1 __t7Hza25) (join-old mp_join (1 2 3 4 0) 2 (1 2 3 4 0) p __t7Hza25 q __t3dlR26 __t77mZ27) (neq p q) (exists mp_union (1 2 0) 2 __t7Hza25 __t3dlR26) (exists mp_join_ans (0 1) 1 __t77mZ27) (join-old mbranch (0 1 2 3 4) 3 (0 1 2 3 4) __t3dlR26 q m u v) (join mp_union (1 2 0) 2 __t7Hza25 __t3dlR26 __t2vfE24) (join mp_join_ans (0 1) 1 __t77mZ27 res)) (head (emit mp_union_ans (0 1) __t2vfE24 res)) map.slog:114 #f)
  class ReadTask1077 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex1067;  slog::Index** mp_unionindex1068;  slog::Index** mp_joinindex1069;  slog::Index** mp_unionindex1070;  slog::Index** mp_join_ansindex1071;  slog::Index** mbranchindex1072;  slog::Index** mp_unionindex1073;  slog::Index** mp_join_ansindex1074;  slog::Index** mp_joindelta1075;  slog::Index** mbranchdelta1076;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord1078({0, 1});
      slog::Relation* readrel1079 = db->getRelation("mp_union_ans");
      head_index[0] = readrel1079->getIndex(ord1078, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord1080({2, 0, 1, 3, 4});
      slog::Relation* readrel1081 = db->getRelation("mbranch");
      mbranchindex1067 = readrel1081->getIndex(ord1080, false);
      std::vector<u16> ord1082({1, 2, 0});
      slog::Relation* readrel1083 = db->getRelation("mp_union");
      mp_unionindex1068 = readrel1083->getIndex(ord1082, false);
      std::vector<u16> ord1084({1, 2, 3, 4, 0});
      slog::Relation* readrel1085 = db->getRelation("mp_join");
      mp_joinindex1069 = readrel1085->getIndex(ord1084, false);
      std::vector<u16> ord1086({1, 2, 3, 4, 0});
      slog::Relation* readrel1087 = db->getRelation("mp_join");
      mp_joindelta1075 = readrel1087->getIndex(ord1086, true);
      std::vector<u16> ord1088({1, 2, 0});
      slog::Relation* readrel1089 = db->getRelation("mp_union");
      mp_unionindex1070 = readrel1089->getIndex(ord1088, false);
      std::vector<u16> ord1090({0, 1});
      slog::Relation* readrel1091 = db->getRelation("mp_join_ans");
      mp_join_ansindex1071 = readrel1091->getIndex(ord1090, false);
      std::vector<u16> ord1092({0, 1, 2, 3, 4});
      slog::Relation* readrel1093 = db->getRelation("mbranch");
      mbranchindex1072 = readrel1093->getIndex(ord1092, false);
      std::vector<u16> ord1094({0, 1, 2, 3, 4});
      slog::Relation* readrel1095 = db->getRelation("mbranch");
      mbranchdelta1076 = readrel1095->getIndex(ord1094, true);
      std::vector<u16> ord1096({1, 2, 0});
      slog::Relation* readrel1097 = db->getRelation("mp_union");
      mp_unionindex1073 = readrel1097->getIndex(ord1096, false);
      std::vector<u16> ord1098({0, 1});
      slog::Relation* readrel1099 = db->getRelation("mp_join_ans");
      mp_join_ansindex1074 = readrel1099->getIndex(ord1098, false);
  
    }
    ReadTask1077(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c181 = _t[0];
        u64 v_c28 = _t[1];
        u64 v_c27 = _t[2];
        u64 v_c26 = _t[3];
        u64 v_c29 = _t[4];
        if (!slog::exists_probe<5,1>(mbranchindex1067, std::array<u64,5>{v_c27, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex1068, std::array<u64,3>{v_c181, 0, 0})) return;
        slog::join_probe_old<5,2>(mp_joinindex1069, mp_joindelta1075, std::array<u64,5>{v_c28, v_c181, 0, 0, 0}, [&](const std::array<u64,5>& m1100) {
          u64 v_c82 = m1100[2]; u64 v_c182 = m1100[3]; u64 v_c183 = m1100[4];
          if (v_c28 == v_c82) return;
          if (!slog::exists_probe<3,2>(mp_unionindex1070, std::array<u64,3>{v_c181, v_c182, 0})) return;
          if (!slog::exists_probe<2,1>(mp_join_ansindex1071, std::array<u64,2>{v_c183, 0})) return;
          slog::join_probe_old<5,3>(mbranchindex1072, mbranchdelta1076, std::array<u64,5>{v_c182, v_c82, v_c27, 0, 0}, [&](const std::array<u64,5>& m1101) {
            u64 v_c84 = m1101[3]; u64 v_c30 = m1101[4];
            slog::join_probe<3,2>(mp_unionindex1073, std::array<u64,3>{v_c181, v_c182, 0}, [&](const std::array<u64,3>& m1102) {
              u64 v_c184 = m1102[2];
              slog::join_probe<2,1>(mp_join_ansindex1074, std::array<u64,2>{v_c183, 0}, [&](const std::array<u64,2>& m1103) {
                u64 v_c86 = m1103[1];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c184, v_c86}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:114", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask1077* _cont = new ReadTask1077(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1077(db,b), false);
  // (crule (pre (let __tconst35Xg1071 const0122baa3ac55f1b433944eb1) (let __tconst3u5R106 const06abaa100ecef791ce028c56) (let _00024sqc9bdu903 constd4735e3a265e16eee03f5971) (let _00024sqc9U0q904 const5feceb66ffc86f38d952786c) (let _00024sqc3xmn905 const6b86b273ff34fce19d6b804e) (let _00024sqo7aO7906 const5feceb66ffc86f38d952786c) (let _00024sqo8pFe907 const6b86b273ff34fce19d6b804e) (let _00024sqo3hRp908 const6b86b273ff34fce19d6b804e) (let _00024sqo4hee909 const5feceb66ffc86f38d952786c)) (probe delta (1 2 0) 1 __tconst3u5R106 _00024seq2 __t8l3B107) (body (letp _00024sql6c1M901 (aslst _00024seq2)) (letp __t5IbK109 (lref _00024sql6c1M901 _00024sqc9U0q904)) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo7aO7906 __t5IbK109 _00024seq2) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo8pFe907 __t5IbK109 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo3hRp908 __t5IbK109 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo4hee909 __t5IbK109 _00024seq2) (join _enum (1 0) 1 __tconst35Xg1071 __t6gQ5104) (join-old boolval (0 1) 1 (0 1) __t5IbK109 b) (let chk49Xf1956 (llen _00024sql6c1M901)) (eq _00024sqc9bdu903 chk49Xf1956) (letp chk8myb1957 (lref _00024sql6c1M901 _00024sqc3xmn905)) (eq __t5IbK109 chk8myb1957)) (head (emit-temp temp1yql1955 __t8l3B107) (mkstruct boolval (1 0) __t274c105 __t6gQ5104)) interp.slog:122 #f)
  class ReadTask1115 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex1104;  slog::Index** $seq_atindex1105;  slog::Index** $seq_atrindex1106;  slog::Index** $seq_atrindex1107;  slog::Index** _enumindex1108;  slog::Index** boolvalindex1109;  slog::Index** $seq_atdelta1110;  slog::Index** $seq_atdelta1111;  slog::Index** $seq_atrdelta1112;  slog::Index** $seq_atrdelta1113;  slog::Index** boolvaldelta1114;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp1yql1955");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord1116({1, 2, 0});
      slog::Relation* readrel1117 = db->getRelation("delta");
      driver_index = readrel1117->getIndex(ord1116, true);
      std::vector<u16> ord1118({1, 0, 2});
      slog::Relation* readrel1119 = db->getRelation("$seq_at");
      $seq_atindex1104 = readrel1119->getIndex(ord1118, false);
      std::vector<u16> ord1120({1, 0, 2});
      slog::Relation* readrel1121 = db->getRelation("$seq_at");
      $seq_atdelta1110 = readrel1121->getIndex(ord1120, true);
      std::vector<u16> ord1122({1, 0, 2});
      slog::Relation* readrel1123 = db->getRelation("$seq_at");
      $seq_atindex1105 = readrel1123->getIndex(ord1122, false);
      std::vector<u16> ord1124({1, 0, 2});
      slog::Relation* readrel1125 = db->getRelation("$seq_at");
      $seq_atdelta1111 = readrel1125->getIndex(ord1124, true);
      std::vector<u16> ord1126({1, 0, 2});
      slog::Relation* readrel1127 = db->getRelation("$seq_atr");
      $seq_atrindex1106 = readrel1127->getIndex(ord1126, false);
      std::vector<u16> ord1128({1, 0, 2});
      slog::Relation* readrel1129 = db->getRelation("$seq_atr");
      $seq_atrdelta1112 = readrel1129->getIndex(ord1128, true);
      std::vector<u16> ord1130({1, 0, 2});
      slog::Relation* readrel1131 = db->getRelation("$seq_atr");
      $seq_atrindex1107 = readrel1131->getIndex(ord1130, false);
      std::vector<u16> ord1132({1, 0, 2});
      slog::Relation* readrel1133 = db->getRelation("$seq_atr");
      $seq_atrdelta1113 = readrel1133->getIndex(ord1132, true);
      std::vector<u16> ord1134({1, 0});
      slog::Relation* readrel1135 = db->getRelation("_enum");
      _enumindex1108 = readrel1135->getIndex(ord1134, false);
      std::vector<u16> ord1136({0, 1});
      slog::Relation* readrel1137 = db->getRelation("boolval");
      boolvalindex1109 = readrel1137->getIndex(ord1136, false);
      std::vector<u16> ord1138({0, 1});
      slog::Relation* readrel1139 = db->getRelation("boolval");
      boolvaldelta1114 = readrel1139->getIndex(ord1138, true);
  
    }
    ReadTask1115(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c1 = v_const06abaa100ecef791ce028c56;
      u64 v_c2 = v_constd4735e3a265e16eee03f5971;
      u64 v_c3 = v_const5feceb66ffc86f38d952786c;
      u64 v_c4 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c5 = v_const5feceb66ffc86f38d952786c;
      u64 v_c6 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c7 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c8 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c1, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1140) {
        u64 v_c10 = m1140[1];
        u64 v_c11 = m1140[2];
        if (buckethash(v_c10) != bucket) return;
        bool ok1141 = true;
        u64 v_c14 = _prim_aslst(db, v_c10, &ok1141);
        if (!ok1141) return;
        bool ok1142 = true;
        u64 v_c9 = _prim_lref(db, v_c14, v_c3, &ok1142);
        if (!ok1142) return;
        slog::join_probe_old<3,3>($seq_atindex1104, $seq_atdelta1110, std::array<u64,3>{v_c5, v_c9, v_c10}, [&](const std::array<u64,3>& m1143) {
          slog::join_probe_old<3,3>($seq_atindex1105, $seq_atdelta1111, std::array<u64,3>{v_c6, v_c9, v_c10}, [&](const std::array<u64,3>& m1144) {
            slog::join_probe_old<3,3>($seq_atrindex1106, $seq_atrdelta1112, std::array<u64,3>{v_c7, v_c9, v_c10}, [&](const std::array<u64,3>& m1145) {
              slog::join_probe_old<3,3>($seq_atrindex1107, $seq_atrdelta1113, std::array<u64,3>{v_c8, v_c9, v_c10}, [&](const std::array<u64,3>& m1146) {
                slog::join_probe<2,1>(_enumindex1108, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m1147) {
                  u64 v_c12 = m1147[1];
                  slog::join_probe_old<2,1>(boolvalindex1109, boolvaldelta1114, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m1148) {
                    u64 v_c13 = m1148[1];
                    u64 v_c185 = _prim_llen(db, v_c14);
                    if (v_c185 == slog_error) { slog::emit_pending_error(db, "interp.slog:122"); return; }
                    if (v_c2 != v_c185) return;
                    bool ok1149 = true;
                    u64 v_c186 = _prim_lref(db, v_c14, v_c4, &ok1149);
                    if (!ok1149) return;
                    if (v_c9 != v_c186) return;
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c11});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c12}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:122", "delta:delta", _fires);
  
      if (!_done)
      {
        ReadTask1115* _cont = new ReadTask1115(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1115(db,b), false);
  // (crule (pre (let __tconst6uLy1418 constcd2a69ce5ca278db1d6da969) (let _00024sqc5ZED979 constd4735e3a265e16eee03f5971) (let _00024sqc8Ktf980 const5feceb66ffc86f38d952786c) (let _00024sqc1r6Y981 const6b86b273ff34fce19d6b804e) (let _00024sqo4ml8982 const5feceb66ffc86f38d952786c) (let _00024sqo9GuQ983 const6b86b273ff34fce19d6b804e) (let _00024sqo9DrV984 const6b86b273ff34fce19d6b804e) (let _00024sqo0wvc985 const5feceb66ffc86f38d952786c) (let __trid2ZoU1419 constfdb0a95399e17c48d6f65653) (let __trel2kf41420 constdede4476644eb06b5a48b866) (let __tcol0QrU1421 const6b86b273ff34fce19d6b804e)) (scan delta __t9b4a431 op _00024seq2) (body (letp _00024sql4NVe977 (aslst _00024seq2)) (letp __t0ebd433 (lref _00024sql4NVe977 _00024sqc8Ktf980)) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo4ml8982 __t0ebd433 _00024seq2) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo9GuQ983 __t0ebd433 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo9DrV984 __t0ebd433 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo0wvc985 __t0ebd433 _00024seq2) (join _enum (0 1) 2 __t0ebd433 __tconst6uLy1418) (join arithmetic_op (0) 1 op) (let chk8rer1857 (llen _00024sql4NVe977)) (eq _00024sqc5ZED979 chk8rer1857) (letp chk2CgV1858 (lref _00024sql4NVe977 _00024sqc1r6Y981)) (eq __t0ebd433 chk2CgV1858)) (head (tycheck __t0ebd433 (accept (struct boolval) (struct closure) (struct _enum) (struct prim) (struct symval)) __trid2ZoU1419 __trel2kf41420 __tcol0QrU1421 (1 2 3 4 0)) (emit delta_ans (0 1) __t9b4a431 __t0ebd433)) interp.slog:116 #f)
  class ReadTask1165 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $seq_atindex1150;  slog::Index** $seq_atindex1151;  slog::Index** $seq_atrindex1152;  slog::Index** $seq_atrindex1153;  slog::Index** _enumindex1154;  slog::Index** arithmetic_opindex1155;  slog::Index** $seq_atdelta1156;  slog::Index** $seq_atdelta1157;  slog::Index** $seq_atrdelta1158;  slog::Index** $seq_atrdelta1159;
    u32 sid1162;  u32 sid1160;  u32 sid1161;  u32 sid1163;  u32 sid1164;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("delta_ans");
      std::vector<u16> ord1166({0, 1});
      slog::Relation* readrel1167 = db->getRelation("delta_ans");
      head_index[1] = readrel1167->getIndex(ord1166, false);
      outer_rel = db->getRelation("delta");
      std::vector<u16> ord1168({1, 0, 2});
      slog::Relation* readrel1169 = db->getRelation("$seq_at");
      $seq_atindex1150 = readrel1169->getIndex(ord1168, false);
      std::vector<u16> ord1170({1, 0, 2});
      slog::Relation* readrel1171 = db->getRelation("$seq_at");
      $seq_atdelta1156 = readrel1171->getIndex(ord1170, true);
      std::vector<u16> ord1172({1, 0, 2});
      slog::Relation* readrel1173 = db->getRelation("$seq_at");
      $seq_atindex1151 = readrel1173->getIndex(ord1172, false);
      std::vector<u16> ord1174({1, 0, 2});
      slog::Relation* readrel1175 = db->getRelation("$seq_at");
      $seq_atdelta1157 = readrel1175->getIndex(ord1174, true);
      std::vector<u16> ord1176({1, 0, 2});
      slog::Relation* readrel1177 = db->getRelation("$seq_atr");
      $seq_atrindex1152 = readrel1177->getIndex(ord1176, false);
      std::vector<u16> ord1178({1, 0, 2});
      slog::Relation* readrel1179 = db->getRelation("$seq_atr");
      $seq_atrdelta1158 = readrel1179->getIndex(ord1178, true);
      std::vector<u16> ord1180({1, 0, 2});
      slog::Relation* readrel1181 = db->getRelation("$seq_atr");
      $seq_atrindex1153 = readrel1181->getIndex(ord1180, false);
      std::vector<u16> ord1182({1, 0, 2});
      slog::Relation* readrel1183 = db->getRelation("$seq_atr");
      $seq_atrdelta1159 = readrel1183->getIndex(ord1182, true);
      std::vector<u16> ord1184({0, 1});
      slog::Relation* readrel1185 = db->getRelation("_enum");
      _enumindex1154 = readrel1185->getIndex(ord1184, false);
      std::vector<u16> ord1186({0});
      slog::Relation* readrel1187 = db->getRelation("arithmetic_op");
      arithmetic_opindex1155 = readrel1187->getIndex(ord1186, false);
      sid1162 = db->getRelation("_enum")->getStructId();
      sid1160 = db->getRelation("boolval")->getStructId();
      sid1161 = db->getRelation("closure")->getStructId();
      sid1163 = db->getRelation("prim")->getStructId();
      sid1164 = db->getRelation("symval")->getStructId();
  
    }
    ReadTask1165(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c187 = v_constcd2a69ce5ca278db1d6da969;
      u64 v_c188 = v_constd4735e3a265e16eee03f5971;
      u64 v_c189 = v_const5feceb66ffc86f38d952786c;
      u64 v_c190 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c191 = v_const5feceb66ffc86f38d952786c;
      u64 v_c192 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c193 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c194 = v_const5feceb66ffc86f38d952786c;
      u64 v_c195 = v_constfdb0a95399e17c48d6f65653;
      u64 v_c196 = v_constdede4476644eb06b5a48b866;
      u64 v_c197 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c198 = _t[0];
        u64 v_c199 = _t[1];
        u64 v_c10 = _t[2];
        bool ok1188 = true;
        u64 v_c200 = _prim_aslst(db, v_c10, &ok1188);
        if (!ok1188) return;
        bool ok1189 = true;
        u64 v_c201 = _prim_lref(db, v_c200, v_c189, &ok1189);
        if (!ok1189) return;
        slog::join_probe_old<3,3>($seq_atindex1150, $seq_atdelta1156, std::array<u64,3>{v_c191, v_c201, v_c10}, [&](const std::array<u64,3>& m1190) {
          slog::join_probe_old<3,3>($seq_atindex1151, $seq_atdelta1157, std::array<u64,3>{v_c192, v_c201, v_c10}, [&](const std::array<u64,3>& m1191) {
            slog::join_probe_old<3,3>($seq_atrindex1152, $seq_atrdelta1158, std::array<u64,3>{v_c193, v_c201, v_c10}, [&](const std::array<u64,3>& m1192) {
              slog::join_probe_old<3,3>($seq_atrindex1153, $seq_atrdelta1159, std::array<u64,3>{v_c194, v_c201, v_c10}, [&](const std::array<u64,3>& m1193) {
                slog::join_probe<2,2>(_enumindex1154, std::array<u64,2>{v_c201, v_c187}, [&](const std::array<u64,2>& m1194) {
                  slog::join_probe<1,1>(arithmetic_opindex1155, std::array<u64,1>{v_c199}, [&](const std::array<u64,1>& m1195) {
                    u64 v_c202 = _prim_llen(db, v_c200);
                    if (v_c202 == slog_error) { slog::emit_pending_error(db, "interp.slog:116"); return; }
                    if (v_c188 != v_c202) return;
                    bool ok1196 = true;
                    u64 v_c203 = _prim_lref(db, v_c200, v_c190, &ok1196);
                    if (!ok1196) return;
                    if (v_c201 != v_c203) return;
                    ++_fires;
                    if (!((is_struct(v_c201) && (decode_struct_id(v_c201) == sid1160 || decode_struct_id(v_c201) == sid1161 || decode_struct_id(v_c201) == sid1162 || decode_struct_id(v_c201) == sid1163 || decode_struct_id(v_c201) == sid1164))))
                    {
                      slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c195, v_c196, v_c197, v_c201}, std::array<u16,5>{1, 2, 3, 4, 0});
                      return;
                    }
                    slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c198, v_c201}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:116", "delta:delta", _fires);
  
      if (!_done)
      {
        ReadTask1165* _cont = new ReadTask1165(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1165(db,b), false);
  // (crule (pre (let __tconst14HM709 const60e3114d9b4b6577eea8cbc0) (let __tconst9fQa703 const844546be553b9dcbf71ae163) (let __tconst09sA701 const0453462f31b2bcf68e33a91f) (let __tconst6VAa1189 constb9e118781cea1f9fa01462e0)) (scan temp3ow11811 __t7ua0707) (body (exists sym (1 0) 1 __tconst09sA701) (exists sym (1 0) 1 __tconst9fQa703) (exists primref (1 0) 1 __tconst14HM709) (join _enum (1 0) 1 __tconst6VAa1189 __t2zPu705) (exists boolean (1 0) 1 __t2zPu705) (join sym (1 0) 1 __tconst09sA701 __t1F7O702) (join sym (1 0) 1 __tconst9fQa703 __t3RPz704) (join boolean (1 0) 1 __t2zPu705 __t5X6z706) (join primref (1 0) 1 __tconst14HM709 __t8M3S710) (let __t8Hit708 (lpush __t7ua0707 __t5X6z706))) (head (emit-temp temp6rU11812 __t8Hit708)) kcfa.slog:52 #f)
  class ReadTask1206 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** symindex1197;  slog::Index** symindex1198;  slog::Index** primrefindex1199;  slog::Index** _enumindex1200;  slog::Index** booleanindex1201;  slog::Index** symindex1202;  slog::Index** symindex1203;  slog::Index** booleanindex1204;  slog::Index** primrefindex1205;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp6rU11812");
      outer_rel = db->getRelation("temp3ow11811");
      std::vector<u16> ord1207({1, 0});
      slog::Relation* readrel1208 = db->getRelation("sym");
      symindex1197 = readrel1208->getIndex(ord1207, false);
      std::vector<u16> ord1209({1, 0});
      slog::Relation* readrel1210 = db->getRelation("sym");
      symindex1198 = readrel1210->getIndex(ord1209, false);
      std::vector<u16> ord1211({1, 0});
      slog::Relation* readrel1212 = db->getRelation("primref");
      primrefindex1199 = readrel1212->getIndex(ord1211, false);
      std::vector<u16> ord1213({1, 0});
      slog::Relation* readrel1214 = db->getRelation("_enum");
      _enumindex1200 = readrel1214->getIndex(ord1213, false);
      std::vector<u16> ord1215({1, 0});
      slog::Relation* readrel1216 = db->getRelation("boolean");
      booleanindex1201 = readrel1216->getIndex(ord1215, false);
      std::vector<u16> ord1217({1, 0});
      slog::Relation* readrel1218 = db->getRelation("sym");
      symindex1202 = readrel1218->getIndex(ord1217, false);
      std::vector<u16> ord1219({1, 0});
      slog::Relation* readrel1220 = db->getRelation("sym");
      symindex1203 = readrel1220->getIndex(ord1219, false);
      std::vector<u16> ord1221({1, 0});
      slog::Relation* readrel1222 = db->getRelation("boolean");
      booleanindex1204 = readrel1222->getIndex(ord1221, false);
      std::vector<u16> ord1223({1, 0});
      slog::Relation* readrel1224 = db->getRelation("primref");
      primrefindex1205 = readrel1224->getIndex(ord1223, false);
  
    }
    ReadTask1206(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c204 = v_const60e3114d9b4b6577eea8cbc0;
      u64 v_c205 = v_const844546be553b9dcbf71ae163;
      u64 v_c206 = v_const0453462f31b2bcf68e33a91f;
      u64 v_c207 = v_constb9e118781cea1f9fa01462e0;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c208 = _t[0];
        if (!slog::exists_probe<2,1>(symindex1197, std::array<u64,2>{v_c206, 0})) return;
        if (!slog::exists_probe<2,1>(symindex1198, std::array<u64,2>{v_c205, 0})) return;
        if (!slog::exists_probe<2,1>(primrefindex1199, std::array<u64,2>{v_c204, 0})) return;
        slog::join_probe<2,1>(_enumindex1200, std::array<u64,2>{v_c207, 0}, [&](const std::array<u64,2>& m1225) {
          u64 v_c209 = m1225[1];
          if (!slog::exists_probe<2,1>(booleanindex1201, std::array<u64,2>{v_c209, 0})) return;
          slog::join_probe<2,1>(symindex1202, std::array<u64,2>{v_c206, 0}, [&](const std::array<u64,2>& m1226) {
            u64 v_c210 = m1226[1];
            slog::join_probe<2,1>(symindex1203, std::array<u64,2>{v_c205, 0}, [&](const std::array<u64,2>& m1227) {
              u64 v_c211 = m1227[1];
              slog::join_probe<2,1>(booleanindex1204, std::array<u64,2>{v_c209, 0}, [&](const std::array<u64,2>& m1228) {
                u64 v_c212 = m1228[1];
                slog::join_probe<2,1>(primrefindex1205, std::array<u64,2>{v_c204, 0}, [&](const std::array<u64,2>& m1229) {
                  u64 v_c213 = m1229[1];
                  u64 v_c214 = _prim_lpush(db, v_c208, v_c212);
                  if (v_c214 == slog_error) { slog::emit_pending_error(db, "kcfa.slog:52"); return; }
                  ++_fires;
                  slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c214});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("kcfa.slog:52", "delta:temp3ow11811", _fires);
  
      if (!_done)
      {
        ReadTask1206* _cont = new ReadTask1206(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1206(db,b), false);
  // (crule (pre) (scan if __t71xd646 e1 e2 e3) (body (exists eval (1 2 3 0) 1 __t71xd646) (exists eval (1 2 3 0) 1 e1) (exists select_branch (2 3 1 0) 2 e2 e3) (join $sup70016x87x0x0x0 (2 3 1 0 4 5) 3 e2 e3 e1 __t7kdB647 rho t) (join-old eval (2 3 0 1) 4 (2 3 0 1) rho t __t7kdB647 __t71xd646) (exists eval (2 3 0 1) 2 rho t) (join-old eval (1 2 3 0) 3 (1 2 3 0) e1 rho t __t2MYH648) (exists eval_ans (0 1) 1 __t2MYH648) (join-old select_branch (2 3 1 0) 2 (2 3 1 0) e2 e3 __v0 __t1Vli649) (join eval_ans (0 1) 2 __t2MYH648 __v0) (exists select_branch_ans (0 1) 1 __t1Vli649) (join-old eval (2 3 0 1) 2 (2 3 0 1) rho t __t4Rxn650 __v1) (join select_branch_ans (0 1) 2 __t1Vli649 __v1) (join eval_ans (0 1) 1 __t4Rxn650 __v2)) (head (emit eval_ans (0 1) __t7kdB647 __v2)) interp.slog:88 #f)
  class ReadTask1248 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1230;  slog::Index** evalindex1231;  slog::Index** select_branchindex1232;  slog::Index** $sup70016x87x0x0x0index1233;  slog::Index** evalindex1234;  slog::Index** evalindex1235;  slog::Index** evalindex1236;  slog::Index** eval_ansindex1237;  slog::Index** select_branchindex1238;  slog::Index** eval_ansindex1239;  slog::Index** select_branch_ansindex1240;  slog::Index** evalindex1241;  slog::Index** select_branch_ansindex1242;  slog::Index** eval_ansindex1243;  slog::Index** evaldelta1244;  slog::Index** evaldelta1245;  slog::Index** select_branchdelta1246;  slog::Index** evaldelta1247;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1249({0, 1});
      slog::Relation* readrel1250 = db->getRelation("eval_ans");
      head_index[0] = readrel1250->getIndex(ord1249, false);
      outer_rel = db->getRelation("if");
      std::vector<u16> ord1251({1, 2, 3, 0});
      slog::Relation* readrel1252 = db->getRelation("eval");
      evalindex1230 = readrel1252->getIndex(ord1251, false);
      std::vector<u16> ord1253({1, 2, 3, 0});
      slog::Relation* readrel1254 = db->getRelation("eval");
      evalindex1231 = readrel1254->getIndex(ord1253, false);
      std::vector<u16> ord1255({2, 3, 1, 0});
      slog::Relation* readrel1256 = db->getRelation("select_branch");
      select_branchindex1232 = readrel1256->getIndex(ord1255, false);
      std::vector<u16> ord1257({2, 3, 1, 0, 4, 5});
      slog::Relation* readrel1258 = db->getRelation("$sup70016x87x0x0x0");
      $sup70016x87x0x0x0index1233 = readrel1258->getIndex(ord1257, false);
      std::vector<u16> ord1259({2, 3, 0, 1});
      slog::Relation* readrel1260 = db->getRelation("eval");
      evalindex1234 = readrel1260->getIndex(ord1259, false);
      std::vector<u16> ord1261({2, 3, 0, 1});
      slog::Relation* readrel1262 = db->getRelation("eval");
      evaldelta1244 = readrel1262->getIndex(ord1261, true);
      std::vector<u16> ord1263({2, 3, 0, 1});
      slog::Relation* readrel1264 = db->getRelation("eval");
      evalindex1235 = readrel1264->getIndex(ord1263, false);
      std::vector<u16> ord1265({1, 2, 3, 0});
      slog::Relation* readrel1266 = db->getRelation("eval");
      evalindex1236 = readrel1266->getIndex(ord1265, false);
      std::vector<u16> ord1267({1, 2, 3, 0});
      slog::Relation* readrel1268 = db->getRelation("eval");
      evaldelta1245 = readrel1268->getIndex(ord1267, true);
      std::vector<u16> ord1269({0, 1});
      slog::Relation* readrel1270 = db->getRelation("eval_ans");
      eval_ansindex1237 = readrel1270->getIndex(ord1269, false);
      std::vector<u16> ord1271({2, 3, 1, 0});
      slog::Relation* readrel1272 = db->getRelation("select_branch");
      select_branchindex1238 = readrel1272->getIndex(ord1271, false);
      std::vector<u16> ord1273({2, 3, 1, 0});
      slog::Relation* readrel1274 = db->getRelation("select_branch");
      select_branchdelta1246 = readrel1274->getIndex(ord1273, true);
      std::vector<u16> ord1275({0, 1});
      slog::Relation* readrel1276 = db->getRelation("eval_ans");
      eval_ansindex1239 = readrel1276->getIndex(ord1275, false);
      std::vector<u16> ord1277({0, 1});
      slog::Relation* readrel1278 = db->getRelation("select_branch_ans");
      select_branch_ansindex1240 = readrel1278->getIndex(ord1277, false);
      std::vector<u16> ord1279({2, 3, 0, 1});
      slog::Relation* readrel1280 = db->getRelation("eval");
      evalindex1241 = readrel1280->getIndex(ord1279, false);
      std::vector<u16> ord1281({2, 3, 0, 1});
      slog::Relation* readrel1282 = db->getRelation("eval");
      evaldelta1247 = readrel1282->getIndex(ord1281, true);
      std::vector<u16> ord1283({0, 1});
      slog::Relation* readrel1284 = db->getRelation("select_branch_ans");
      select_branch_ansindex1242 = readrel1284->getIndex(ord1283, false);
      std::vector<u16> ord1285({0, 1});
      slog::Relation* readrel1286 = db->getRelation("eval_ans");
      eval_ansindex1243 = readrel1286->getIndex(ord1285, false);
  
    }
    ReadTask1248(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c137 = _t[1];
        u64 v_c103 = _t[2];
        u64 v_c104 = _t[3];
        if (!slog::exists_probe<4,1>(evalindex1230, std::array<u64,4>{v_c141, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(evalindex1231, std::array<u64,4>{v_c137, 0, 0, 0})) return;
        if (!slog::exists_probe<4,2>(select_branchindex1232, std::array<u64,4>{v_c103, v_c104, 0, 0})) return;
        slog::join_probe<6,3>($sup70016x87x0x0x0index1233, std::array<u64,6>{v_c103, v_c104, v_c137, 0, 0, 0}, [&](const std::array<u64,6>& m1287) {
          u64 v_c142 = m1287[3]; u64 v_c94 = m1287[4]; u64 v_c47 = m1287[5];
          slog::join_probe_old<4,4>(evalindex1234, evaldelta1244, std::array<u64,4>{v_c94, v_c47, v_c142, v_c141}, [&](const std::array<u64,4>& m1288) {
            if (!slog::exists_probe<4,2>(evalindex1235, std::array<u64,4>{v_c94, v_c47, 0, 0})) return;
            slog::join_probe_old<4,3>(evalindex1236, evaldelta1245, std::array<u64,4>{v_c137, v_c94, v_c47, 0}, [&](const std::array<u64,4>& m1289) {
              u64 v_c143 = m1289[3];
              if (!slog::exists_probe<2,1>(eval_ansindex1237, std::array<u64,2>{v_c143, 0})) return;
              slog::join_probe_old<4,2>(select_branchindex1238, select_branchdelta1246, std::array<u64,4>{v_c103, v_c104, 0, 0}, [&](const std::array<u64,4>& m1290) {
                u64 v_c71 = m1290[2]; u64 v_c139 = m1290[3];
                slog::join_probe<2,2>(eval_ansindex1239, std::array<u64,2>{v_c143, v_c71}, [&](const std::array<u64,2>& m1291) {
                  if (!slog::exists_probe<2,1>(select_branch_ansindex1240, std::array<u64,2>{v_c139, 0})) return;
                  slog::join_probe_old<4,2>(evalindex1241, evaldelta1247, std::array<u64,4>{v_c94, v_c47, 0, 0}, [&](const std::array<u64,4>& m1292) {
                    u64 v_c144 = m1292[2]; u64 v_c140 = m1292[3];
                    slog::join_probe<2,2>(select_branch_ansindex1242, std::array<u64,2>{v_c139, v_c140}, [&](const std::array<u64,2>& m1293) {
                      slog::join_probe<2,1>(eval_ansindex1243, std::array<u64,2>{v_c144, 0}, [&](const std::array<u64,2>& m1294) {
                        u64 v_c145 = m1294[1];
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c142, v_c145}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:88", "delta:if", _fires);
  
      if (!_done)
      {
        ReadTask1248* _cont = new ReadTask1248(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1248(db,b), false);
  // (crule (pre) (scan mp_msk __t84wf697 q m) (body (exists mbranch (2 0 1 3 4) 1 m) (exists $sup5638x101x0x0x0 (2 5 0 1 3 4 6 7 8 9 10) 2 m q) (exists mbranch (1 2 3 4 0) 1 q) (exists mp_join (3 4 1 0 2) 1 q) (join mp_msk_ans (0 1) 1 __t84wf697 __v0) (join mbranch (2 0 1 3 4) 1 m __t1ouF694 p l r) (neq p __v0) (exists mp_join (1 2 3 4 0) 3 p __t1ouF694 q) (exists mp_union (1 2 0) 1 __t1ouF694) (join $sup5638x101x0x0x0 (1 2 4 6 7 5 0 3 8 9 10) 6 l m p r __t1ouF694 q __t5awj693 n __t1a8C695 u v) (cmp lt n m) (join mbranch (1 2 3 4 0) 5 q n u v __t1a8C695) (exists mp_union (0 1 2) 3 __t5awj693 __t1ouF694 __t1a8C695) (join mp_join (1 2 3 4 0) 4 p __t1ouF694 q __t1a8C695 __t8BsD696) (join mp_union (0 1 2) 3 __t5awj693 __t1ouF694 __t1a8C695) (join mp_join_ans (0 1) 1 __t8BsD696 res)) (head (emit mp_union_ans (0 1) __t5awj693 res)) map.slog:102 #f)
  class ReadTask1309 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex1295;  slog::Index** $sup5638x101x0x0x0index1296;  slog::Index** mbranchindex1297;  slog::Index** mp_joinindex1298;  slog::Index** mp_msk_ansindex1299;  slog::Index** mbranchindex1300;  slog::Index** mp_joinindex1301;  slog::Index** mp_unionindex1302;  slog::Index** $sup5638x101x0x0x0index1303;  slog::Index** mbranchindex1304;  slog::Index** mp_unionindex1305;  slog::Index** mp_joinindex1306;  slog::Index** mp_unionindex1307;  slog::Index** mp_join_ansindex1308;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord1310({0, 1});
      slog::Relation* readrel1311 = db->getRelation("mp_union_ans");
      head_index[0] = readrel1311->getIndex(ord1310, false);
      outer_rel = db->getRelation("mp_msk");
      std::vector<u16> ord1312({2, 0, 1, 3, 4});
      slog::Relation* readrel1313 = db->getRelation("mbranch");
      mbranchindex1295 = readrel1313->getIndex(ord1312, false);
      std::vector<u16> ord1314({2, 5, 0, 1, 3, 4, 6, 7, 8, 9, 10});
      slog::Relation* readrel1315 = db->getRelation("$sup5638x101x0x0x0");
      $sup5638x101x0x0x0index1296 = readrel1315->getIndex(ord1314, false);
      std::vector<u16> ord1316({1, 2, 3, 4, 0});
      slog::Relation* readrel1317 = db->getRelation("mbranch");
      mbranchindex1297 = readrel1317->getIndex(ord1316, false);
      std::vector<u16> ord1318({3, 4, 1, 0, 2});
      slog::Relation* readrel1319 = db->getRelation("mp_join");
      mp_joinindex1298 = readrel1319->getIndex(ord1318, false);
      std::vector<u16> ord1320({0, 1});
      slog::Relation* readrel1321 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1299 = readrel1321->getIndex(ord1320, false);
      std::vector<u16> ord1322({2, 0, 1, 3, 4});
      slog::Relation* readrel1323 = db->getRelation("mbranch");
      mbranchindex1300 = readrel1323->getIndex(ord1322, false);
      std::vector<u16> ord1324({1, 2, 3, 4, 0});
      slog::Relation* readrel1325 = db->getRelation("mp_join");
      mp_joinindex1301 = readrel1325->getIndex(ord1324, false);
      std::vector<u16> ord1326({1, 2, 0});
      slog::Relation* readrel1327 = db->getRelation("mp_union");
      mp_unionindex1302 = readrel1327->getIndex(ord1326, false);
      std::vector<u16> ord1328({1, 2, 4, 6, 7, 5, 0, 3, 8, 9, 10});
      slog::Relation* readrel1329 = db->getRelation("$sup5638x101x0x0x0");
      $sup5638x101x0x0x0index1303 = readrel1329->getIndex(ord1328, false);
      std::vector<u16> ord1330({1, 2, 3, 4, 0});
      slog::Relation* readrel1331 = db->getRelation("mbranch");
      mbranchindex1304 = readrel1331->getIndex(ord1330, false);
      std::vector<u16> ord1332({0, 1, 2});
      slog::Relation* readrel1333 = db->getRelation("mp_union");
      mp_unionindex1305 = readrel1333->getIndex(ord1332, false);
      std::vector<u16> ord1334({1, 2, 3, 4, 0});
      slog::Relation* readrel1335 = db->getRelation("mp_join");
      mp_joinindex1306 = readrel1335->getIndex(ord1334, false);
      std::vector<u16> ord1336({0, 1, 2});
      slog::Relation* readrel1337 = db->getRelation("mp_union");
      mp_unionindex1307 = readrel1337->getIndex(ord1336, false);
      std::vector<u16> ord1338({0, 1});
      slog::Relation* readrel1339 = db->getRelation("mp_join_ans");
      mp_join_ansindex1308 = readrel1339->getIndex(ord1338, false);
  
    }
    ReadTask1309(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c215 = _t[0];
        u64 v_c82 = _t[1];
        u64 v_c27 = _t[2];
        if (!slog::exists_probe<5,1>(mbranchindex1295, std::array<u64,5>{v_c27, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<11,2>($sup5638x101x0x0x0index1296, std::array<u64,11>{v_c27, v_c82, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex1297, std::array<u64,5>{v_c82, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mp_joinindex1298, std::array<u64,5>{v_c82, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(mp_msk_ansindex1299, std::array<u64,2>{v_c215, 0}, [&](const std::array<u64,2>& m1340) {
          u64 v_c71 = m1340[1];
          slog::join_probe<5,1>(mbranchindex1300, std::array<u64,5>{v_c27, 0, 0, 0, 0}, [&](const std::array<u64,5>& m1341) {
            u64 v_c216 = m1341[1]; u64 v_c28 = m1341[2]; u64 v_c26 = m1341[3]; u64 v_c29 = m1341[4];
            if (v_c28 == v_c71) return;
            if (!slog::exists_probe<5,3>(mp_joinindex1301, std::array<u64,5>{v_c28, v_c216, v_c82, 0, 0})) return;
            if (!slog::exists_probe<3,1>(mp_unionindex1302, std::array<u64,3>{v_c216, 0, 0})) return;
            slog::join_probe<11,6>($sup5638x101x0x0x0index1303, std::array<u64,11>{v_c26, v_c27, v_c28, v_c29, v_c216, v_c82, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m1342) {
              u64 v_c217 = m1342[6]; u64 v_c78 = m1342[7]; u64 v_c218 = m1342[8]; u64 v_c84 = m1342[9]; u64 v_c30 = m1342[10];
              u64 v_c219 = _prim_lt(db, v_c78, v_c27);
              if (v_c219 == slog_error) { slog::emit_pending_error(db, "map.slog:102"); return; }
              if (!v_c219) return;
              slog::join_probe<5,5>(mbranchindex1304, std::array<u64,5>{v_c82, v_c78, v_c84, v_c30, v_c218}, [&](const std::array<u64,5>& m1344) {
                if (!slog::exists_probe<3,3>(mp_unionindex1305, std::array<u64,3>{v_c217, v_c216, v_c218})) return;
                slog::join_probe<5,4>(mp_joinindex1306, std::array<u64,5>{v_c28, v_c216, v_c82, v_c218, 0}, [&](const std::array<u64,5>& m1345) {
                  u64 v_c220 = m1345[4];
                  slog::join_probe<3,3>(mp_unionindex1307, std::array<u64,3>{v_c217, v_c216, v_c218}, [&](const std::array<u64,3>& m1346) {
                    slog::join_probe<2,1>(mp_join_ansindex1308, std::array<u64,2>{v_c220, 0}, [&](const std::array<u64,2>& m1347) {
                      u64 v_c86 = m1347[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c217, v_c86}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:102", "delta:mp_msk", _fires);
  
      if (!_done)
      {
        ReadTask1309* _cont = new ReadTask1309(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1309(db,b), false);
  // (crule (pre) (scan temp7LDM2048 n q r u v) (body (join mbranch (1 2 3 4 0) 4 q n u v __t0LfW530)) (head (mkstruct mp_union (1 2 0) __3p4H1136 r __t0LfW530)) map.slog:99 #f)
  class ReadTask1349 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex1348;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union");
      outer_rel = db->getRelation("temp7LDM2048");
      std::vector<u16> ord1350({1, 2, 3, 4, 0});
      slog::Relation* readrel1351 = db->getRelation("mbranch");
      mbranchindex1348 = readrel1351->getIndex(ord1350, false);
  
    }
    ReadTask1349(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c82 = _t[1];
        u64 v_c29 = _t[2];
        u64 v_c84 = _t[3];
        u64 v_c30 = _t[4];
        slog::join_probe<5,4>(mbranchindex1348, std::array<u64,5>{v_c82, v_c78, v_c84, v_c30, 0}, [&](const std::array<u64,5>& m1352) {
          u64 v_c221 = m1352[4];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c29, v_c221}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:99", "delta:temp7LDM2048", _fires);
  
      if (!_done)
      {
        ReadTask1349* _cont = new ReadTask1349(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1349(db,b), false);
  // (crule (pre (let __tconst2PAJ212 const624b60c58c9d8bfb6ff1886c)) (scan temp7ssb1953 __t1aBM195 __t7nIl205 __t9Ps2210) (body (join lambda (1 2 0) 2 __t9Ps2210 __t7nIl205 __t9JFW211)) (head (emit-temp temp7F9y1954 __t1aBM195 __t9JFW211) (mkstruct let (1 2 3 0) __t0C5k213 __tconst2PAJ212 __t9JFW211 __t1aBM195)) kcfa.slog:59 #f)
  class ReadTask1354 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lambdaindex1353;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7F9y1954");
      head_rel[1] = db->getRelation("let");
      outer_rel = db->getRelation("temp7ssb1953");
      std::vector<u16> ord1355({1, 2, 0});
      slog::Relation* readrel1356 = db->getRelation("lambda");
      lambdaindex1353 = readrel1356->getIndex(ord1355, false);
  
    }
    ReadTask1354(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c222 = v_const624b60c58c9d8bfb6ff1886c;
  
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
        slog::join_probe<3,2>(lambdaindex1353, std::array<u64,3>{v_c225, v_c224, 0}, [&](const std::array<u64,3>& m1357) {
          u64 v_c226 = m1357[2];
          ++_fires;
          slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c223, v_c226});
          slog::emit_struct<4>(head_rel[1], newbatch[1], std::array<u64,3>{v_c222, v_c226, v_c223}, std::array<u16,4>{1, 2, 3, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("kcfa.slog:59", "delta:temp7ssb1953", _fires);
  
      if (!_done)
      {
        ReadTask1354* _cont = new ReadTask1354(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1354(db,b), false);
  // (crule (pre (let __tconst7oJb145 const6b86b273ff34fce19d6b804e)) (scan $sup5638x104x0x0x1 __t0kfV144 __t7PVf147 l m n p q r u v) (body (cmp lt m n) (join $sup5638x104x0x0x0 (5 3 7 8 0 1 2 4 6) 9 q n u v __t0kfV144 l m p r) (exists mbranch (1 2 3 4 0) 4 p m l r) (exists mp_msk (1 2 0) 3 p n __t7PVf147) (exists mp_msk_ans (0 1) 2 __t7PVf147 q) (exists mp_union (2 0 1) 1 u) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t2NO6142) (exists mp_union (2 0 1) 2 __t2NO6142 __t0kfV144) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t5mfE148) (join-old mp_union (0 1 2) 3 (0 1 2) __t0kfV144 __t5mfE148 __t2NO6142) (join-old mp_msk (1 2 0) 3 (1 2 0) p n __t7PVf147) (join mp_msk_ans (0 1) 2 __t7PVf147 q) (join-old mp_union (1 2 0) 2 (1 2 0) __t5mfE148 u __t221b149) (join mp_union_ans (0 1) 1 __t221b149 __v0) (let __t5ygO146 (band p n)) (cmp lt __t5ygO146 __tconst7oJb145)) (head (emit-temp temp9IEi1871 __t0kfV144 __v0 n q v) (mkstruct mbranch (1 2 3 4 0) __t4DAr141 q n __v0 v)) map.slog:105 #f)
  class ReadTask1376 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x104x0x0x0index1358;  slog::Index** mbranchindex1359;  slog::Index** mp_mskindex1360;  slog::Index** mp_msk_ansindex1361;  slog::Index** mp_unionindex1362;  slog::Index** mbranchindex1363;  slog::Index** mp_unionindex1364;  slog::Index** mbranchindex1365;  slog::Index** mp_unionindex1366;  slog::Index** mp_mskindex1367;  slog::Index** mp_msk_ansindex1368;  slog::Index** mp_unionindex1369;  slog::Index** mp_union_ansindex1370;  slog::Index** mbranchdelta1371;  slog::Index** mbranchdelta1372;  slog::Index** mp_uniondelta1373;  slog::Index** mp_mskdelta1374;  slog::Index** mp_uniondelta1375;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9IEi1871");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("$sup5638x104x0x0x1");
      std::vector<u16> ord1377({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel1378 = db->getRelation("$sup5638x104x0x0x0");
      $sup5638x104x0x0x0index1358 = readrel1378->getIndex(ord1377, false);
      std::vector<u16> ord1379({1, 2, 3, 4, 0});
      slog::Relation* readrel1380 = db->getRelation("mbranch");
      mbranchindex1359 = readrel1380->getIndex(ord1379, false);
      std::vector<u16> ord1381({1, 2, 0});
      slog::Relation* readrel1382 = db->getRelation("mp_msk");
      mp_mskindex1360 = readrel1382->getIndex(ord1381, false);
      std::vector<u16> ord1383({0, 1});
      slog::Relation* readrel1384 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1361 = readrel1384->getIndex(ord1383, false);
      std::vector<u16> ord1385({2, 0, 1});
      slog::Relation* readrel1386 = db->getRelation("mp_union");
      mp_unionindex1362 = readrel1386->getIndex(ord1385, false);
      std::vector<u16> ord1387({1, 2, 3, 4, 0});
      slog::Relation* readrel1388 = db->getRelation("mbranch");
      mbranchindex1363 = readrel1388->getIndex(ord1387, false);
      std::vector<u16> ord1389({1, 2, 3, 4, 0});
      slog::Relation* readrel1390 = db->getRelation("mbranch");
      mbranchdelta1371 = readrel1390->getIndex(ord1389, true);
      std::vector<u16> ord1391({2, 0, 1});
      slog::Relation* readrel1392 = db->getRelation("mp_union");
      mp_unionindex1364 = readrel1392->getIndex(ord1391, false);
      std::vector<u16> ord1393({1, 2, 3, 4, 0});
      slog::Relation* readrel1394 = db->getRelation("mbranch");
      mbranchindex1365 = readrel1394->getIndex(ord1393, false);
      std::vector<u16> ord1395({1, 2, 3, 4, 0});
      slog::Relation* readrel1396 = db->getRelation("mbranch");
      mbranchdelta1372 = readrel1396->getIndex(ord1395, true);
      std::vector<u16> ord1397({0, 1, 2});
      slog::Relation* readrel1398 = db->getRelation("mp_union");
      mp_unionindex1366 = readrel1398->getIndex(ord1397, false);
      std::vector<u16> ord1399({0, 1, 2});
      slog::Relation* readrel1400 = db->getRelation("mp_union");
      mp_uniondelta1373 = readrel1400->getIndex(ord1399, true);
      std::vector<u16> ord1401({1, 2, 0});
      slog::Relation* readrel1402 = db->getRelation("mp_msk");
      mp_mskindex1367 = readrel1402->getIndex(ord1401, false);
      std::vector<u16> ord1403({1, 2, 0});
      slog::Relation* readrel1404 = db->getRelation("mp_msk");
      mp_mskdelta1374 = readrel1404->getIndex(ord1403, true);
      std::vector<u16> ord1405({0, 1});
      slog::Relation* readrel1406 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1368 = readrel1406->getIndex(ord1405, false);
      std::vector<u16> ord1407({1, 2, 0});
      slog::Relation* readrel1408 = db->getRelation("mp_union");
      mp_unionindex1369 = readrel1408->getIndex(ord1407, false);
      std::vector<u16> ord1409({1, 2, 0});
      slog::Relation* readrel1410 = db->getRelation("mp_union");
      mp_uniondelta1375 = readrel1410->getIndex(ord1409, true);
      std::vector<u16> ord1411({0, 1});
      slog::Relation* readrel1412 = db->getRelation("mp_union_ans");
      mp_union_ansindex1370 = readrel1412->getIndex(ord1411, false);
  
    }
    ReadTask1376(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c170 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c173 = _t[1];
        u64 v_c26 = _t[2];
        u64 v_c27 = _t[3];
        u64 v_c78 = _t[4];
        u64 v_c28 = _t[5];
        u64 v_c82 = _t[6];
        u64 v_c29 = _t[7];
        u64 v_c84 = _t[8];
        u64 v_c30 = _t[9];
        u64 v_c227 = _prim_lt(db, v_c27, v_c78);
        if (v_c227 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
        if (!v_c227) return;
        slog::join_probe<9,9>($sup5638x104x0x0x0index1358, std::array<u64,9>{v_c82, v_c78, v_c84, v_c30, v_c171, v_c26, v_c27, v_c28, v_c29}, [&](const std::array<u64,9>& m1414) {
          if (!slog::exists_probe<5,4>(mbranchindex1359, std::array<u64,5>{v_c28, v_c27, v_c26, v_c29, 0})) return;
          if (!slog::exists_probe<3,3>(mp_mskindex1360, std::array<u64,3>{v_c28, v_c78, v_c173})) return;
          if (!slog::exists_probe<2,2>(mp_msk_ansindex1361, std::array<u64,2>{v_c173, v_c82})) return;
          if (!slog::exists_probe<3,1>(mp_unionindex1362, std::array<u64,3>{v_c84, 0, 0})) return;
          slog::join_probe_old<5,4>(mbranchindex1363, mbranchdelta1371, std::array<u64,5>{v_c82, v_c78, v_c84, v_c30, 0}, [&](const std::array<u64,5>& m1415) {
            u64 v_c174 = m1415[4];
            if (!slog::exists_probe<3,2>(mp_unionindex1364, std::array<u64,3>{v_c174, v_c171, 0})) return;
            slog::join_probe_old<5,4>(mbranchindex1365, mbranchdelta1372, std::array<u64,5>{v_c28, v_c27, v_c26, v_c29, 0}, [&](const std::array<u64,5>& m1416) {
              u64 v_c175 = m1416[4];
              slog::join_probe_old<3,3>(mp_unionindex1366, mp_uniondelta1373, std::array<u64,3>{v_c171, v_c175, v_c174}, [&](const std::array<u64,3>& m1417) {
                slog::join_probe_old<3,3>(mp_mskindex1367, mp_mskdelta1374, std::array<u64,3>{v_c28, v_c78, v_c173}, [&](const std::array<u64,3>& m1418) {
                  slog::join_probe<2,2>(mp_msk_ansindex1368, std::array<u64,2>{v_c173, v_c82}, [&](const std::array<u64,2>& m1419) {
                    slog::join_probe_old<3,2>(mp_unionindex1369, mp_uniondelta1375, std::array<u64,3>{v_c175, v_c84, 0}, [&](const std::array<u64,3>& m1420) {
                      u64 v_c176 = m1420[2];
                      slog::join_probe<2,1>(mp_union_ansindex1370, std::array<u64,2>{v_c176, 0}, [&](const std::array<u64,2>& m1421) {
                        u64 v_c71 = m1421[1];
                        u64 v_c177 = _prim_band(db, v_c28, v_c78);
                        if (v_c177 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
                        u64 v_c228 = _prim_lt(db, v_c177, v_c170);
                        if (v_c228 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
                        if (!v_c228) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c171, v_c71, v_c78, v_c82, v_c30});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c82, v_c78, v_c71, v_c30}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:105", "delta:$sup5638x104x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask1376* _cont = new ReadTask1376(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1376(db,b), false);
  // (crule (pre) (scan type_mismatch __erre21wk1763 __errf1OPt1764 __errf0xDg1765 __errf2YZ41766 __errf4okS1767) (body) (head (emit error (0) __erre21wk1763)) <internal>:1 #f)
  class ReadTask1423 : public slog::Task
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
      std::vector<u16> ord1424({0});
      slog::Relation* readrel1425 = db->getRelation("error");
      head_index[0] = readrel1425->getIndex(ord1424, false);
      outer_rel = db->getRelation("type_mismatch");
  
    }
    ReadTask1423(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c229 = _t[0];
        u64 v_c230 = _t[1];
        u64 v_c231 = _t[2];
        u64 v_c232 = _t[3];
        u64 v_c233 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c229}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:type_mismatch", _fires);
  
      if (!_done)
      {
        ReadTask1423* _cont = new ReadTask1423(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1423(db,b), false);
  // (crule (pre) (scan lookup_ans __t03bu666 __v0) (body (join-old lookup (0 1 2) 1 (0 1 2) __t03bu666 x rho) (exists eval (2 3 0 1) 1 rho) (exists ref (1 0) 1 x) (join-old $sup70016x33x0x0x0 (3 1 0 2) 2 (3 1 0 2) x rho __t5crG665 t) (join-old eval (2 3 0 1) 3 (2 3 0 1) rho t __t5crG665 __t4vms664) (join-old ref (0 1) 2 (0 1) __t4vms664 x)) (head (emit eval_ans (0 1) __t5crG665 __v0)) interp.slog:34 #f)
  class ReadTask1436 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lookupindex1426;  slog::Index** evalindex1427;  slog::Index** refindex1428;  slog::Index** $sup70016x33x0x0x0index1429;  slog::Index** evalindex1430;  slog::Index** refindex1431;  slog::Index** lookupdelta1432;  slog::Index** $sup70016x33x0x0x0delta1433;  slog::Index** evaldelta1434;  slog::Index** refdelta1435;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1437({0, 1});
      slog::Relation* readrel1438 = db->getRelation("eval_ans");
      head_index[0] = readrel1438->getIndex(ord1437, false);
      outer_rel = db->getRelation("lookup_ans");
      std::vector<u16> ord1439({0, 1, 2});
      slog::Relation* readrel1440 = db->getRelation("lookup");
      lookupindex1426 = readrel1440->getIndex(ord1439, false);
      std::vector<u16> ord1441({0, 1, 2});
      slog::Relation* readrel1442 = db->getRelation("lookup");
      lookupdelta1432 = readrel1442->getIndex(ord1441, true);
      std::vector<u16> ord1443({2, 3, 0, 1});
      slog::Relation* readrel1444 = db->getRelation("eval");
      evalindex1427 = readrel1444->getIndex(ord1443, false);
      std::vector<u16> ord1445({1, 0});
      slog::Relation* readrel1446 = db->getRelation("ref");
      refindex1428 = readrel1446->getIndex(ord1445, false);
      std::vector<u16> ord1447({3, 1, 0, 2});
      slog::Relation* readrel1448 = db->getRelation("$sup70016x33x0x0x0");
      $sup70016x33x0x0x0index1429 = readrel1448->getIndex(ord1447, false);
      std::vector<u16> ord1449({3, 1, 0, 2});
      slog::Relation* readrel1450 = db->getRelation("$sup70016x33x0x0x0");
      $sup70016x33x0x0x0delta1433 = readrel1450->getIndex(ord1449, true);
      std::vector<u16> ord1451({2, 3, 0, 1});
      slog::Relation* readrel1452 = db->getRelation("eval");
      evalindex1430 = readrel1452->getIndex(ord1451, false);
      std::vector<u16> ord1453({2, 3, 0, 1});
      slog::Relation* readrel1454 = db->getRelation("eval");
      evaldelta1434 = readrel1454->getIndex(ord1453, true);
      std::vector<u16> ord1455({0, 1});
      slog::Relation* readrel1456 = db->getRelation("ref");
      refindex1431 = readrel1456->getIndex(ord1455, false);
      std::vector<u16> ord1457({0, 1});
      slog::Relation* readrel1458 = db->getRelation("ref");
      refdelta1435 = readrel1458->getIndex(ord1457, true);
  
    }
    ReadTask1436(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c234 = _t[0];
        u64 v_c71 = _t[1];
        slog::join_probe_old<3,1>(lookupindex1426, lookupdelta1432, std::array<u64,3>{v_c234, 0, 0}, [&](const std::array<u64,3>& m1459) {
          u64 v_c95 = m1459[1]; u64 v_c94 = m1459[2];
          if (!slog::exists_probe<4,1>(evalindex1427, std::array<u64,4>{v_c94, 0, 0, 0})) return;
          if (!slog::exists_probe<2,1>(refindex1428, std::array<u64,2>{v_c95, 0})) return;
          slog::join_probe_old<4,2>($sup70016x33x0x0x0index1429, $sup70016x33x0x0x0delta1433, std::array<u64,4>{v_c95, v_c94, 0, 0}, [&](const std::array<u64,4>& m1460) {
            u64 v_c235 = m1460[2]; u64 v_c47 = m1460[3];
            slog::join_probe_old<4,3>(evalindex1430, evaldelta1434, std::array<u64,4>{v_c94, v_c47, v_c235, 0}, [&](const std::array<u64,4>& m1461) {
              u64 v_c236 = m1461[3];
              slog::join_probe_old<2,2>(refindex1431, refdelta1435, std::array<u64,2>{v_c236, v_c95}, [&](const std::array<u64,2>& m1462) {
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c235, v_c71}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:34", "delta:lookup_ans", _fires);
  
      if (!_done)
      {
        ReadTask1436* _cont = new ReadTask1436(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1436(db,b), false);
  // (crule (pre (let _00024sqc1mig1050 const5feceb66ffc86f38d952786c) (let __t0r8J513 (lempty))) (scan eval_args __t30pJ514 _00024seq0 rho t) (body (letp _00024sql6nAJ1048 (aslst _00024seq0)) (let chk6C3q1794 (llen _00024sql6nAJ1048)) (eq _00024sqc1mig1050 chk6C3q1794)) (head (emit-temp temp0Rhp1793 __t0r8J513 __t30pJ514)) interp.slog:43 #f)
  class ReadTask1463 : public slog::Task
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
      head_rel[0] = db->getRelation("temp0Rhp1793");
      outer_rel = db->getRelation("eval_args");
  
    }
    ReadTask1463(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c237 = v_const5feceb66ffc86f38d952786c;
      u64 v_c238 = _prim_lempty(db);
      if (v_c238 == slog_error) { slog::emit_pending_error(db, "interp.slog:43"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c239 = _t[0];
        u64 v_c35 = _t[1];
        u64 v_c94 = _t[2];
        u64 v_c47 = _t[3];
        bool ok1464 = true;
        u64 v_c240 = _prim_aslst(db, v_c35, &ok1464);
        if (!ok1464) return;
        u64 v_c241 = _prim_llen(db, v_c240);
        if (v_c241 == slog_error) { slog::emit_pending_error(db, "interp.slog:43"); return; }
        if (v_c237 != v_c241) return;
        ++_fires;
        slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c238, v_c239});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:43", "delta:eval_args", _fires);
  
      if (!_done)
      {
        ReadTask1463* _cont = new ReadTask1463(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1463(db,b), false);
  // (crule (pre (let __trid9VtR1429 constde34af73616246ffdc2cc593) (let __trel1gbY1430 const4a59dbb9cb3129dfcc75170b) (let __tcol8OFq1431 const5feceb66ffc86f38d952786c) (let __trel2ZB31432 const4a59dbb9cb3129dfcc75170b) (let __tcol9JYj1433 const6b86b273ff34fce19d6b804e) (let __trel3xx01434 const4a59dbb9cb3129dfcc75170b) (let __tcol8Zfj1435 constd4735e3a265e16eee03f5971)) (scan $sup70016x43x0x0x0 _00024seq0 __d0 e es rho t) (body) (head (tycheck e (accept (struct app) (struct boolean) (struct if) (struct lambda) (struct let) (struct letrec) (struct num) (struct primref) (struct ref) (struct sym)) __trid9VtR1429 __trel1gbY1430 __tcol8OFq1431 (1 2 3 4 0)) (tycheck rho (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid9VtR1429 __trel2ZB31432 __tcol9JYj1433 (1 2 3 4 0)) (tycheck t (accept seq) __trid9VtR1429 __trel3xx01434 __tcol8Zfj1435 (1 2 3 4 0)) (mkstruct eval (1 2 3 0) __7iTn1428 e rho t)) interp.slog:44 #f)
  class ReadTask1478 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[4];
    slog::Index** head_index[4];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid1476;  u32 sid1465;  u32 sid1466;  u32 sid1467;  u32 sid1468;  u32 sid1469;  u32 sid1470;  u32 sid1475;  u32 sid1477;  u32 sid1471;  u32 sid1472;  u32 sid1473;  u32 sid1474;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("malformed_deduction");
      head_rel[3] = db->getRelation("eval");
      outer_rel = db->getRelation("$sup70016x43x0x0x0");
      sid1476 = db->getRelation("_enum")->getStructId();
      sid1465 = db->getRelation("app")->getStructId();
      sid1466 = db->getRelation("boolean")->getStructId();
      sid1467 = db->getRelation("if")->getStructId();
      sid1468 = db->getRelation("lambda")->getStructId();
      sid1469 = db->getRelation("let")->getStructId();
      sid1470 = db->getRelation("letrec")->getStructId();
      sid1475 = db->getRelation("mbranch")->getStructId();
      sid1477 = db->getRelation("mleaf")->getStructId();
      sid1471 = db->getRelation("num")->getStructId();
      sid1472 = db->getRelation("primref")->getStructId();
      sid1473 = db->getRelation("ref")->getStructId();
      sid1474 = db->getRelation("sym")->getStructId();
  
    }
    ReadTask1478(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c242 = v_constde34af73616246ffdc2cc593;
      u64 v_c243 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c244 = v_const5feceb66ffc86f38d952786c;
      u64 v_c245 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c246 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c247 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c248 = v_constd4735e3a265e16eee03f5971;
  
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
        u64 v_c35 = _t[0];
        u64 v_c23 = _t[1];
        u64 v_c249 = _t[2];
        u64 v_c111 = _t[3];
        u64 v_c94 = _t[4];
        u64 v_c47 = _t[5];
        ++_fires;
        if (!((is_struct(v_c249) && (decode_struct_id(v_c249) == sid1465 || decode_struct_id(v_c249) == sid1466 || decode_struct_id(v_c249) == sid1467 || decode_struct_id(v_c249) == sid1468 || decode_struct_id(v_c249) == sid1469 || decode_struct_id(v_c249) == sid1470 || decode_struct_id(v_c249) == sid1471 || decode_struct_id(v_c249) == sid1472 || decode_struct_id(v_c249) == sid1473 || decode_struct_id(v_c249) == sid1474))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c242, v_c243, v_c244, v_c249}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c94) && (decode_struct_id(v_c94) == sid1475 || decode_struct_id(v_c94) == sid1476 || decode_struct_id(v_c94) == sid1477))))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c242, v_c245, v_c246, v_c94}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_seq(v_c47)))
        {
          slog::emit_struct<5>(head_rel[2], newbatch[2], std::array<u64,4>{v_c242, v_c247, v_c248, v_c47}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<4>(head_rel[3], newbatch[3], std::array<u64,3>{v_c249, v_c94, v_c47}, std::array<u16,4>{1, 2, 3, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
  
      if (_fires) db->bumpFires("interp.slog:44", "delta:$sup70016x43x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1478* _cont = new ReadTask1478(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1478(db,b), false);
  // (crule (pre (let __tconst2b6r460 const5feceb66ffc86f38d952786c)) (scan mbranch __t9ixF458 p m l r) (body (exists $sup5638x42x0x0x1 (3 4 5 6 0 2 7 1) 4 l m p r) (exists mp_put (1 2 3 0) 1 __t9ixF458) (exists mp_msk (2 0 1) 1 m) (exists mp_put (1 2 3 0) 1 r) (exists mp_msk_ans (1 0) 1 p) (join $sup5638x42x0x0x0 (4 2 3 5 0 1 6) 4 p l m r __t6Bbs459 k v) (exists mp_put (0 2 1 3) 4 __t6Bbs459 k __t9ixF458 v) (exists mp_msk (1 2 0) 2 k m) (exists mp_put (1 2 3 0) 3 r k v) (join $sup5638x42x0x0x1 (3 4 5 6 0 2 7 1) 7 l m p r __t6Bbs459 k v __t5aM3462) (join-old mp_put (0 2 1 3) 4 (0 2 1 3) __t6Bbs459 k __t9ixF458 v) (join-old mp_msk (1 2 0) 3 (1 2 0) k m __t5aM3462) (exists mp_msk_ans (0 1) 2 __t5aM3462 p) (join-old mp_put (1 2 3 0) 3 (1 2 3 0) r k v __t9vSj463) (join mp_msk_ans (0 1) 2 __t5aM3462 p) (join mp_put_ans (0 1) 1 __t9vSj463 __v0) (let __t1jZ6461 (band k m)) (cmp gt __t1jZ6461 __tconst2b6r460)) (head (emit-temp temp7Xjy1975 __t6Bbs459 __v0 l m p) (mkstruct mbranch (1 2 3 4 0) __t8oL5457 p m l __v0)) map.slog:43 #f)
  class ReadTask1498 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x42x0x0x1index1479;  slog::Index** mp_putindex1480;  slog::Index** mp_mskindex1481;  slog::Index** mp_putindex1482;  slog::Index** mp_msk_ansindex1483;  slog::Index** $sup5638x42x0x0x0index1484;  slog::Index** mp_putindex1485;  slog::Index** mp_mskindex1486;  slog::Index** mp_putindex1487;  slog::Index** $sup5638x42x0x0x1index1488;  slog::Index** mp_putindex1489;  slog::Index** mp_mskindex1490;  slog::Index** mp_msk_ansindex1491;  slog::Index** mp_putindex1492;  slog::Index** mp_msk_ansindex1493;  slog::Index** mp_put_ansindex1494;  slog::Index** mp_putdelta1495;  slog::Index** mp_mskdelta1496;  slog::Index** mp_putdelta1497;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7Xjy1975");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord1499({3, 4, 5, 6, 0, 2, 7, 1});
      slog::Relation* readrel1500 = db->getRelation("$sup5638x42x0x0x1");
      $sup5638x42x0x0x1index1479 = readrel1500->getIndex(ord1499, false);
      std::vector<u16> ord1501({1, 2, 3, 0});
      slog::Relation* readrel1502 = db->getRelation("mp_put");
      mp_putindex1480 = readrel1502->getIndex(ord1501, false);
      std::vector<u16> ord1503({2, 0, 1});
      slog::Relation* readrel1504 = db->getRelation("mp_msk");
      mp_mskindex1481 = readrel1504->getIndex(ord1503, false);
      std::vector<u16> ord1505({1, 2, 3, 0});
      slog::Relation* readrel1506 = db->getRelation("mp_put");
      mp_putindex1482 = readrel1506->getIndex(ord1505, false);
      std::vector<u16> ord1507({1, 0});
      slog::Relation* readrel1508 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1483 = readrel1508->getIndex(ord1507, false);
      std::vector<u16> ord1509({4, 2, 3, 5, 0, 1, 6});
      slog::Relation* readrel1510 = db->getRelation("$sup5638x42x0x0x0");
      $sup5638x42x0x0x0index1484 = readrel1510->getIndex(ord1509, false);
      std::vector<u16> ord1511({0, 2, 1, 3});
      slog::Relation* readrel1512 = db->getRelation("mp_put");
      mp_putindex1485 = readrel1512->getIndex(ord1511, false);
      std::vector<u16> ord1513({1, 2, 0});
      slog::Relation* readrel1514 = db->getRelation("mp_msk");
      mp_mskindex1486 = readrel1514->getIndex(ord1513, false);
      std::vector<u16> ord1515({1, 2, 3, 0});
      slog::Relation* readrel1516 = db->getRelation("mp_put");
      mp_putindex1487 = readrel1516->getIndex(ord1515, false);
      std::vector<u16> ord1517({3, 4, 5, 6, 0, 2, 7, 1});
      slog::Relation* readrel1518 = db->getRelation("$sup5638x42x0x0x1");
      $sup5638x42x0x0x1index1488 = readrel1518->getIndex(ord1517, false);
      std::vector<u16> ord1519({0, 2, 1, 3});
      slog::Relation* readrel1520 = db->getRelation("mp_put");
      mp_putindex1489 = readrel1520->getIndex(ord1519, false);
      std::vector<u16> ord1521({0, 2, 1, 3});
      slog::Relation* readrel1522 = db->getRelation("mp_put");
      mp_putdelta1495 = readrel1522->getIndex(ord1521, true);
      std::vector<u16> ord1523({1, 2, 0});
      slog::Relation* readrel1524 = db->getRelation("mp_msk");
      mp_mskindex1490 = readrel1524->getIndex(ord1523, false);
      std::vector<u16> ord1525({1, 2, 0});
      slog::Relation* readrel1526 = db->getRelation("mp_msk");
      mp_mskdelta1496 = readrel1526->getIndex(ord1525, true);
      std::vector<u16> ord1527({0, 1});
      slog::Relation* readrel1528 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1491 = readrel1528->getIndex(ord1527, false);
      std::vector<u16> ord1529({1, 2, 3, 0});
      slog::Relation* readrel1530 = db->getRelation("mp_put");
      mp_putindex1492 = readrel1530->getIndex(ord1529, false);
      std::vector<u16> ord1531({1, 2, 3, 0});
      slog::Relation* readrel1532 = db->getRelation("mp_put");
      mp_putdelta1497 = readrel1532->getIndex(ord1531, true);
      std::vector<u16> ord1533({0, 1});
      slog::Relation* readrel1534 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1493 = readrel1534->getIndex(ord1533, false);
      std::vector<u16> ord1535({0, 1});
      slog::Relation* readrel1536 = db->getRelation("mp_put_ans");
      mp_put_ansindex1494 = readrel1536->getIndex(ord1535, false);
  
    }
    ReadTask1498(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c250 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c251 = _t[0];
        u64 v_c28 = _t[1];
        u64 v_c27 = _t[2];
        u64 v_c26 = _t[3];
        u64 v_c29 = _t[4];
        if (!slog::exists_probe<8,4>($sup5638x42x0x0x1index1479, std::array<u64,8>{v_c26, v_c27, v_c28, v_c29, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(mp_putindex1480, std::array<u64,4>{v_c251, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex1481, std::array<u64,3>{v_c27, 0, 0})) return;
        if (!slog::exists_probe<4,1>(mp_putindex1482, std::array<u64,4>{v_c29, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex1483, std::array<u64,2>{v_c28, 0})) return;
        slog::join_probe<7,4>($sup5638x42x0x0x0index1484, std::array<u64,7>{v_c28, v_c26, v_c27, v_c29, 0, 0, 0}, [&](const std::array<u64,7>& m1537) {
          u64 v_c252 = m1537[4]; u64 v_c25 = m1537[5]; u64 v_c30 = m1537[6];
          if (!slog::exists_probe<4,4>(mp_putindex1485, std::array<u64,4>{v_c252, v_c25, v_c251, v_c30})) return;
          if (!slog::exists_probe<3,2>(mp_mskindex1486, std::array<u64,3>{v_c25, v_c27, 0})) return;
          if (!slog::exists_probe<4,3>(mp_putindex1487, std::array<u64,4>{v_c29, v_c25, v_c30, 0})) return;
          slog::join_probe<8,7>($sup5638x42x0x0x1index1488, std::array<u64,8>{v_c26, v_c27, v_c28, v_c29, v_c252, v_c25, v_c30, 0}, [&](const std::array<u64,8>& m1538) {
            u64 v_c253 = m1538[7];
            slog::join_probe_old<4,4>(mp_putindex1489, mp_putdelta1495, std::array<u64,4>{v_c252, v_c25, v_c251, v_c30}, [&](const std::array<u64,4>& m1539) {
              slog::join_probe_old<3,3>(mp_mskindex1490, mp_mskdelta1496, std::array<u64,3>{v_c25, v_c27, v_c253}, [&](const std::array<u64,3>& m1540) {
                if (!slog::exists_probe<2,2>(mp_msk_ansindex1491, std::array<u64,2>{v_c253, v_c28})) return;
                slog::join_probe_old<4,3>(mp_putindex1492, mp_putdelta1497, std::array<u64,4>{v_c29, v_c25, v_c30, 0}, [&](const std::array<u64,4>& m1541) {
                  u64 v_c254 = m1541[3];
                  slog::join_probe<2,2>(mp_msk_ansindex1493, std::array<u64,2>{v_c253, v_c28}, [&](const std::array<u64,2>& m1542) {
                    slog::join_probe<2,1>(mp_put_ansindex1494, std::array<u64,2>{v_c254, 0}, [&](const std::array<u64,2>& m1543) {
                      u64 v_c71 = m1543[1];
                      u64 v_c255 = _prim_band(db, v_c25, v_c27);
                      if (v_c255 == slog_error) { slog::emit_pending_error(db, "map.slog:43"); return; }
                      u64 v_c256 = _prim_gt(db, v_c255, v_c250);
                      if (v_c256 == slog_error) { slog::emit_pending_error(db, "map.slog:43"); return; }
                      if (!v_c256) return;
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c252, v_c71, v_c26, v_c27, v_c28});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c28, v_c27, v_c26, v_c71}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:43", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask1498* _cont = new ReadTask1498(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1498(db,b), false);
  // (crule (pre (let __tconst959m1238 constd01925b37634a1a9d24159d8)) (scan mp_put __t3rqG10 __t2rup9 k v) (body (join _enum (0 1) 2 __t2rup9 __tconst959m1238)) (head (emit-temp temp5qo21875 __t3rqG10 k v) (mkstruct mleaf (1 2 0) __t1xsL8 k v)) map.slog:37 #f)
  class ReadTask1546 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex1545;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5qo21875");
      head_rel[1] = db->getRelation("mleaf");
      outer_rel = db->getRelation("mp_put");
      std::vector<u16> ord1547({0, 1});
      slog::Relation* readrel1548 = db->getRelation("_enum");
      _enumindex1545 = readrel1548->getIndex(ord1547, false);
  
    }
    ReadTask1546(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c257 = v_constd01925b37634a1a9d24159d8;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c258 = _t[0];
        u64 v_c259 = _t[1];
        u64 v_c25 = _t[2];
        u64 v_c30 = _t[3];
        slog::join_probe<2,2>(_enumindex1545, std::array<u64,2>{v_c259, v_c257}, [&](const std::array<u64,2>& m1549) {
          ++_fires;
          slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c258, v_c25, v_c30});
          slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c25, v_c30}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("map.slog:37", "delta:mp_put", _fires);
  
      if (!_done)
      {
        ReadTask1546* _cont = new ReadTask1546(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1546(db,b), false);
  // (crule (pre (let __tconst8hOq309 const6b86b273ff34fce19d6b804e)) (scan mp_bld __t8pI6311 p m __v0 r) (body (exists $sup5638x82x0x0x0 (4 3 5 2 0 1) 3 p m r) (exists mp_msk (2 0 1) 1 m) (exists mp_msk_ans (1 0) 1 p) (exists mp_del_ans (1 0) 1 __v0) (exists mp_bld_ans (0 1) 1 __t8pI6311) (join mbranch (1 2 4 0 3) 3 p m r __t62gM307 l) (exists mp_del (1 2 0) 1 __t62gM307) (exists mp_del (1 2 0) 1 l) (join $sup5638x82x0x0x0 (4 3 5 2 0 1) 4 p m r l __t0iNt308 k) (join mp_del (0 2 1) 3 __t0iNt308 k __t62gM307) (exists mp_del (1 2 0) 2 l k) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t8vNz312) (join mp_msk_ans (0 1) 2 __t8vNz312 p) (join-old mp_del (1 2 0) 2 (1 2 0) l k __t1hIi313) (join mp_del_ans (0 1) 2 __t1hIi313 __v0) (join mp_bld_ans (0 1) 1 __t8pI6311 res) (let __t3mg0310 (band k m)) (cmp lt __t3mg0310 __tconst8hOq309)) (head (emit mp_del_ans (0 1) __t0iNt308 res)) map.slog:83 #f)
  class ReadTask1568 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x82x0x0x0index1550;  slog::Index** mp_mskindex1551;  slog::Index** mp_msk_ansindex1552;  slog::Index** mp_del_ansindex1553;  slog::Index** mp_bld_ansindex1554;  slog::Index** mbranchindex1555;  slog::Index** mp_delindex1556;  slog::Index** mp_delindex1557;  slog::Index** $sup5638x82x0x0x0index1558;  slog::Index** mp_delindex1559;  slog::Index** mp_delindex1560;  slog::Index** mp_mskindex1561;  slog::Index** mp_msk_ansindex1562;  slog::Index** mp_delindex1563;  slog::Index** mp_del_ansindex1564;  slog::Index** mp_bld_ansindex1565;  slog::Index** mp_mskdelta1566;  slog::Index** mp_deldelta1567;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord1569({0, 1});
      slog::Relation* readrel1570 = db->getRelation("mp_del_ans");
      head_index[0] = readrel1570->getIndex(ord1569, false);
      outer_rel = db->getRelation("mp_bld");
      std::vector<u16> ord1571({4, 3, 5, 2, 0, 1});
      slog::Relation* readrel1572 = db->getRelation("$sup5638x82x0x0x0");
      $sup5638x82x0x0x0index1550 = readrel1572->getIndex(ord1571, false);
      std::vector<u16> ord1573({2, 0, 1});
      slog::Relation* readrel1574 = db->getRelation("mp_msk");
      mp_mskindex1551 = readrel1574->getIndex(ord1573, false);
      std::vector<u16> ord1575({1, 0});
      slog::Relation* readrel1576 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1552 = readrel1576->getIndex(ord1575, false);
      std::vector<u16> ord1577({1, 0});
      slog::Relation* readrel1578 = db->getRelation("mp_del_ans");
      mp_del_ansindex1553 = readrel1578->getIndex(ord1577, false);
      std::vector<u16> ord1579({0, 1});
      slog::Relation* readrel1580 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex1554 = readrel1580->getIndex(ord1579, false);
      std::vector<u16> ord1581({1, 2, 4, 0, 3});
      slog::Relation* readrel1582 = db->getRelation("mbranch");
      mbranchindex1555 = readrel1582->getIndex(ord1581, false);
      std::vector<u16> ord1583({1, 2, 0});
      slog::Relation* readrel1584 = db->getRelation("mp_del");
      mp_delindex1556 = readrel1584->getIndex(ord1583, false);
      std::vector<u16> ord1585({1, 2, 0});
      slog::Relation* readrel1586 = db->getRelation("mp_del");
      mp_delindex1557 = readrel1586->getIndex(ord1585, false);
      std::vector<u16> ord1587({4, 3, 5, 2, 0, 1});
      slog::Relation* readrel1588 = db->getRelation("$sup5638x82x0x0x0");
      $sup5638x82x0x0x0index1558 = readrel1588->getIndex(ord1587, false);
      std::vector<u16> ord1589({0, 2, 1});
      slog::Relation* readrel1590 = db->getRelation("mp_del");
      mp_delindex1559 = readrel1590->getIndex(ord1589, false);
      std::vector<u16> ord1591({1, 2, 0});
      slog::Relation* readrel1592 = db->getRelation("mp_del");
      mp_delindex1560 = readrel1592->getIndex(ord1591, false);
      std::vector<u16> ord1593({1, 2, 0});
      slog::Relation* readrel1594 = db->getRelation("mp_msk");
      mp_mskindex1561 = readrel1594->getIndex(ord1593, false);
      std::vector<u16> ord1595({1, 2, 0});
      slog::Relation* readrel1596 = db->getRelation("mp_msk");
      mp_mskdelta1566 = readrel1596->getIndex(ord1595, true);
      std::vector<u16> ord1597({0, 1});
      slog::Relation* readrel1598 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1562 = readrel1598->getIndex(ord1597, false);
      std::vector<u16> ord1599({1, 2, 0});
      slog::Relation* readrel1600 = db->getRelation("mp_del");
      mp_delindex1563 = readrel1600->getIndex(ord1599, false);
      std::vector<u16> ord1601({1, 2, 0});
      slog::Relation* readrel1602 = db->getRelation("mp_del");
      mp_deldelta1567 = readrel1602->getIndex(ord1601, true);
      std::vector<u16> ord1603({0, 1});
      slog::Relation* readrel1604 = db->getRelation("mp_del_ans");
      mp_del_ansindex1564 = readrel1604->getIndex(ord1603, false);
      std::vector<u16> ord1605({0, 1});
      slog::Relation* readrel1606 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex1565 = readrel1606->getIndex(ord1605, false);
  
    }
    ReadTask1568(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c147 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c150 = _t[0];
        u64 v_c28 = _t[1];
        u64 v_c27 = _t[2];
        u64 v_c71 = _t[3];
        u64 v_c29 = _t[4];
        if (!slog::exists_probe<6,3>($sup5638x82x0x0x0index1550, std::array<u64,6>{v_c28, v_c27, v_c29, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex1551, std::array<u64,3>{v_c27, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex1552, std::array<u64,2>{v_c28, 0})) return;
        if (!slog::exists_probe<2,1>(mp_del_ansindex1553, std::array<u64,2>{v_c71, 0})) return;
        if (!slog::exists_probe<2,1>(mp_bld_ansindex1554, std::array<u64,2>{v_c150, 0})) return;
        slog::join_probe<5,3>(mbranchindex1555, std::array<u64,5>{v_c28, v_c27, v_c29, 0, 0}, [&](const std::array<u64,5>& m1607) {
          u64 v_c149 = m1607[3]; u64 v_c26 = m1607[4];
          if (!slog::exists_probe<3,1>(mp_delindex1556, std::array<u64,3>{v_c149, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_delindex1557, std::array<u64,3>{v_c26, 0, 0})) return;
          slog::join_probe<6,4>($sup5638x82x0x0x0index1558, std::array<u64,6>{v_c28, v_c27, v_c29, v_c26, 0, 0}, [&](const std::array<u64,6>& m1608) {
            u64 v_c148 = m1608[4]; u64 v_c25 = m1608[5];
            slog::join_probe<3,3>(mp_delindex1559, std::array<u64,3>{v_c148, v_c25, v_c149}, [&](const std::array<u64,3>& m1609) {
              if (!slog::exists_probe<3,2>(mp_delindex1560, std::array<u64,3>{v_c26, v_c25, 0})) return;
              slog::join_probe_old<3,2>(mp_mskindex1561, mp_mskdelta1566, std::array<u64,3>{v_c25, v_c27, 0}, [&](const std::array<u64,3>& m1610) {
                u64 v_c151 = m1610[2];
                slog::join_probe<2,2>(mp_msk_ansindex1562, std::array<u64,2>{v_c151, v_c28}, [&](const std::array<u64,2>& m1611) {
                  slog::join_probe_old<3,2>(mp_delindex1563, mp_deldelta1567, std::array<u64,3>{v_c26, v_c25, 0}, [&](const std::array<u64,3>& m1612) {
                    u64 v_c152 = m1612[2];
                    slog::join_probe<2,2>(mp_del_ansindex1564, std::array<u64,2>{v_c152, v_c71}, [&](const std::array<u64,2>& m1613) {
                      slog::join_probe<2,1>(mp_bld_ansindex1565, std::array<u64,2>{v_c150, 0}, [&](const std::array<u64,2>& m1614) {
                        u64 v_c86 = m1614[1];
                        u64 v_c153 = _prim_band(db, v_c25, v_c27);
                        if (v_c153 == slog_error) { slog::emit_pending_error(db, "map.slog:83"); return; }
                        u64 v_c260 = _prim_lt(db, v_c153, v_c147);
                        if (v_c260 == slog_error) { slog::emit_pending_error(db, "map.slog:83"); return; }
                        if (!v_c260) return;
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c148, v_c86}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("map.slog:83", "delta:mp_bld", _fires);
  
      if (!_done)
      {
        ReadTask1568* _cont = new ReadTask1568(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1568(db,b), false);
  // (crule (pre (let __tconst70WV799 const5feceb66ffc86f38d952786c)) (scan mp_bld_ans __t2Csk801 res) (body (join-old mp_bld (0 1 2 3 4) 1 (0 1 2 3 4) __t2Csk801 p m l __v0) (exists $sup5638x84x0x0x0 (4 2 3 5 0 1) 3 p l m) (exists mp_msk (2 0 1) 1 m) (exists mp_msk_ans (1 0) 1 p) (exists mp_del_ans (1 0) 1 __v0) (join-old mbranch (1 2 3 4 0) 3 (1 2 3 4 0) p m l r __t29Nf797) (exists mp_del (1 2 0) 1 __t29Nf797) (exists mp_del (1 2 0) 1 r) (join-old $sup5638x84x0x0x0 (4 2 3 5 0 1) 4 (4 2 3 5 0 1) p l m r __t2paO798 k) (join-old mp_del (0 2 1) 3 (0 2 1) __t2paO798 k __t29Nf797) (exists mp_del (1 2 0) 2 r k) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t4hJg802) (join-old mp_msk_ans (0 1) 2 (0 1) __t4hJg802 p) (join-old mp_del (1 2 0) 2 (1 2 0) r k __t1FSo803) (join-old mp_del_ans (0 1) 2 (0 1) __t1FSo803 __v0) (let __t1QoP800 (band k m)) (cmp gt __t1QoP800 __tconst70WV799)) (head (emit mp_del_ans (0 1) __t2paO798 res)) map.slog:85 #f)
  class ReadTask1639 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_bldindex1616;  slog::Index** $sup5638x84x0x0x0index1617;  slog::Index** mp_mskindex1618;  slog::Index** mp_msk_ansindex1619;  slog::Index** mp_del_ansindex1620;  slog::Index** mbranchindex1621;  slog::Index** mp_delindex1622;  slog::Index** mp_delindex1623;  slog::Index** $sup5638x84x0x0x0index1624;  slog::Index** mp_delindex1625;  slog::Index** mp_delindex1626;  slog::Index** mp_mskindex1627;  slog::Index** mp_msk_ansindex1628;  slog::Index** mp_delindex1629;  slog::Index** mp_del_ansindex1630;  slog::Index** mp_blddelta1631;  slog::Index** mbranchdelta1632;  slog::Index** $sup5638x84x0x0x0delta1633;  slog::Index** mp_deldelta1634;  slog::Index** mp_mskdelta1635;  slog::Index** mp_msk_ansdelta1636;  slog::Index** mp_deldelta1637;  slog::Index** mp_del_ansdelta1638;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord1640({0, 1});
      slog::Relation* readrel1641 = db->getRelation("mp_del_ans");
      head_index[0] = readrel1641->getIndex(ord1640, false);
      outer_rel = db->getRelation("mp_bld_ans");
      std::vector<u16> ord1642({0, 1, 2, 3, 4});
      slog::Relation* readrel1643 = db->getRelation("mp_bld");
      mp_bldindex1616 = readrel1643->getIndex(ord1642, false);
      std::vector<u16> ord1644({0, 1, 2, 3, 4});
      slog::Relation* readrel1645 = db->getRelation("mp_bld");
      mp_blddelta1631 = readrel1645->getIndex(ord1644, true);
      std::vector<u16> ord1646({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel1647 = db->getRelation("$sup5638x84x0x0x0");
      $sup5638x84x0x0x0index1617 = readrel1647->getIndex(ord1646, false);
      std::vector<u16> ord1648({2, 0, 1});
      slog::Relation* readrel1649 = db->getRelation("mp_msk");
      mp_mskindex1618 = readrel1649->getIndex(ord1648, false);
      std::vector<u16> ord1650({1, 0});
      slog::Relation* readrel1651 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1619 = readrel1651->getIndex(ord1650, false);
      std::vector<u16> ord1652({1, 0});
      slog::Relation* readrel1653 = db->getRelation("mp_del_ans");
      mp_del_ansindex1620 = readrel1653->getIndex(ord1652, false);
      std::vector<u16> ord1654({1, 2, 3, 4, 0});
      slog::Relation* readrel1655 = db->getRelation("mbranch");
      mbranchindex1621 = readrel1655->getIndex(ord1654, false);
      std::vector<u16> ord1656({1, 2, 3, 4, 0});
      slog::Relation* readrel1657 = db->getRelation("mbranch");
      mbranchdelta1632 = readrel1657->getIndex(ord1656, true);
      std::vector<u16> ord1658({1, 2, 0});
      slog::Relation* readrel1659 = db->getRelation("mp_del");
      mp_delindex1622 = readrel1659->getIndex(ord1658, false);
      std::vector<u16> ord1660({1, 2, 0});
      slog::Relation* readrel1661 = db->getRelation("mp_del");
      mp_delindex1623 = readrel1661->getIndex(ord1660, false);
      std::vector<u16> ord1662({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel1663 = db->getRelation("$sup5638x84x0x0x0");
      $sup5638x84x0x0x0index1624 = readrel1663->getIndex(ord1662, false);
      std::vector<u16> ord1664({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel1665 = db->getRelation("$sup5638x84x0x0x0");
      $sup5638x84x0x0x0delta1633 = readrel1665->getIndex(ord1664, true);
      std::vector<u16> ord1666({0, 2, 1});
      slog::Relation* readrel1667 = db->getRelation("mp_del");
      mp_delindex1625 = readrel1667->getIndex(ord1666, false);
      std::vector<u16> ord1668({0, 2, 1});
      slog::Relation* readrel1669 = db->getRelation("mp_del");
      mp_deldelta1634 = readrel1669->getIndex(ord1668, true);
      std::vector<u16> ord1670({1, 2, 0});
      slog::Relation* readrel1671 = db->getRelation("mp_del");
      mp_delindex1626 = readrel1671->getIndex(ord1670, false);
      std::vector<u16> ord1672({1, 2, 0});
      slog::Relation* readrel1673 = db->getRelation("mp_msk");
      mp_mskindex1627 = readrel1673->getIndex(ord1672, false);
      std::vector<u16> ord1674({1, 2, 0});
      slog::Relation* readrel1675 = db->getRelation("mp_msk");
      mp_mskdelta1635 = readrel1675->getIndex(ord1674, true);
      std::vector<u16> ord1676({0, 1});
      slog::Relation* readrel1677 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1628 = readrel1677->getIndex(ord1676, false);
      std::vector<u16> ord1678({0, 1});
      slog::Relation* readrel1679 = db->getRelation("mp_msk_ans");
      mp_msk_ansdelta1636 = readrel1679->getIndex(ord1678, true);
      std::vector<u16> ord1680({1, 2, 0});
      slog::Relation* readrel1681 = db->getRelation("mp_del");
      mp_delindex1629 = readrel1681->getIndex(ord1680, false);
      std::vector<u16> ord1682({1, 2, 0});
      slog::Relation* readrel1683 = db->getRelation("mp_del");
      mp_deldelta1637 = readrel1683->getIndex(ord1682, true);
      std::vector<u16> ord1684({0, 1});
      slog::Relation* readrel1685 = db->getRelation("mp_del_ans");
      mp_del_ansindex1630 = readrel1685->getIndex(ord1684, false);
      std::vector<u16> ord1686({0, 1});
      slog::Relation* readrel1687 = db->getRelation("mp_del_ans");
      mp_del_ansdelta1638 = readrel1687->getIndex(ord1686, true);
  
    }
    ReadTask1639(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c261 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c262 = _t[0];
        u64 v_c86 = _t[1];
        slog::join_probe_old<5,1>(mp_bldindex1616, mp_blddelta1631, std::array<u64,5>{v_c262, 0, 0, 0, 0}, [&](const std::array<u64,5>& m1688) {
          u64 v_c28 = m1688[1]; u64 v_c27 = m1688[2]; u64 v_c26 = m1688[3]; u64 v_c71 = m1688[4];
          if (!slog::exists_probe<6,3>($sup5638x84x0x0x0index1617, std::array<u64,6>{v_c28, v_c26, v_c27, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_mskindex1618, std::array<u64,3>{v_c27, 0, 0})) return;
          if (!slog::exists_probe<2,1>(mp_msk_ansindex1619, std::array<u64,2>{v_c28, 0})) return;
          if (!slog::exists_probe<2,1>(mp_del_ansindex1620, std::array<u64,2>{v_c71, 0})) return;
          slog::join_probe_old<5,3>(mbranchindex1621, mbranchdelta1632, std::array<u64,5>{v_c28, v_c27, v_c26, 0, 0}, [&](const std::array<u64,5>& m1689) {
            u64 v_c29 = m1689[3]; u64 v_c263 = m1689[4];
            if (!slog::exists_probe<3,1>(mp_delindex1622, std::array<u64,3>{v_c263, 0, 0})) return;
            if (!slog::exists_probe<3,1>(mp_delindex1623, std::array<u64,3>{v_c29, 0, 0})) return;
            slog::join_probe_old<6,4>($sup5638x84x0x0x0index1624, $sup5638x84x0x0x0delta1633, std::array<u64,6>{v_c28, v_c26, v_c27, v_c29, 0, 0}, [&](const std::array<u64,6>& m1690) {
              u64 v_c264 = m1690[4]; u64 v_c25 = m1690[5];
              slog::join_probe_old<3,3>(mp_delindex1625, mp_deldelta1634, std::array<u64,3>{v_c264, v_c25, v_c263}, [&](const std::array<u64,3>& m1691) {
                if (!slog::exists_probe<3,2>(mp_delindex1626, std::array<u64,3>{v_c29, v_c25, 0})) return;
                slog::join_probe_old<3,2>(mp_mskindex1627, mp_mskdelta1635, std::array<u64,3>{v_c25, v_c27, 0}, [&](const std::array<u64,3>& m1692) {
                  u64 v_c265 = m1692[2];
                  slog::join_probe_old<2,2>(mp_msk_ansindex1628, mp_msk_ansdelta1636, std::array<u64,2>{v_c265, v_c28}, [&](const std::array<u64,2>& m1693) {
                    slog::join_probe_old<3,2>(mp_delindex1629, mp_deldelta1637, std::array<u64,3>{v_c29, v_c25, 0}, [&](const std::array<u64,3>& m1694) {
                      u64 v_c266 = m1694[2];
                      slog::join_probe_old<2,2>(mp_del_ansindex1630, mp_del_ansdelta1638, std::array<u64,2>{v_c266, v_c71}, [&](const std::array<u64,2>& m1695) {
                        u64 v_c267 = _prim_band(db, v_c25, v_c27);
                        if (v_c267 == slog_error) { slog::emit_pending_error(db, "map.slog:85"); return; }
                        u64 v_c268 = _prim_gt(db, v_c267, v_c261);
                        if (v_c268 == slog_error) { slog::emit_pending_error(db, "map.slog:85"); return; }
                        if (!v_c268) return;
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c264, v_c86}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("map.slog:85", "delta:mp_bld_ans", _fires);
  
      if (!_done)
      {
        ReadTask1639* _cont = new ReadTask1639(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1639(db,b), false);
  // (crule (pre) (scan temp8lYe1877 __t7knf810) (body) (head (mkstruct mp_hsb (1 0) __5i5y1348 __t7knf810)) map.slog:30 #f)
  class ReadTask1697 : public slog::Task
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
      head_rel[0] = db->getRelation("mp_hsb");
      outer_rel = db->getRelation("temp8lYe1877");
  
    }
    ReadTask1697(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c269 = _t[0];
        ++_fires;
        slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c269}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:30", "delta:temp8lYe1877", _fires);
  
      if (!_done)
      {
        ReadTask1697* _cont = new ReadTask1697(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1697(db,b), false);
  // (crule (pre) (scan mp_msk_ans __t827P393 __v0) (body (join-old mp_msk (0 1 2) 1 (0 1 2) __t827P393 p n) (exists $sup5638x110x0x0x0 (3 4 0 1 2 5 6 7 8 9 10) 2 n p) (exists mbranch (2 0 1 3 4) 1 n) (exists mp_join (1 2 3 4 0) 1 p) (join-old mbranch (1 2 3 4 0) 1 (1 2 3 4 0) p m l r __t6AX6390) (cmp lt m n) (exists mp_join (1 2 3 4 0) 2 p __t6AX6390) (exists mp_union (1 2 0) 1 __t6AX6390) (join-old $sup5638x110x0x0x0 (1 2 4 6 7 3 0 5 8 9 10) 6 (1 2 4 6 7 3 0 5 8 9 10) l m p r __t6AX6390 n __t5Qtl389 q __t46nL391 u v) (neq q __v0) (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) q n u v __t46nL391) (exists mp_union (0 1 2) 3 __t5Qtl389 __t6AX6390 __t46nL391) (join-old mp_join (1 2 3 4 0) 4 (1 2 3 4 0) p __t6AX6390 q __t46nL391 __t6UVn392) (join-old mp_union (0 1 2) 3 (0 1 2) __t5Qtl389 __t6AX6390 __t46nL391) (join mp_join_ans (0 1) 1 __t6UVn392 res)) (head (emit mp_union_ans (0 1) __t5Qtl389 res)) map.slog:111 #f)
  class ReadTask1717 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_mskindex1698;  slog::Index** $sup5638x110x0x0x0index1699;  slog::Index** mbranchindex1700;  slog::Index** mp_joinindex1701;  slog::Index** mbranchindex1702;  slog::Index** mp_joinindex1703;  slog::Index** mp_unionindex1704;  slog::Index** $sup5638x110x0x0x0index1705;  slog::Index** mbranchindex1706;  slog::Index** mp_unionindex1707;  slog::Index** mp_joinindex1708;  slog::Index** mp_unionindex1709;  slog::Index** mp_join_ansindex1710;  slog::Index** mp_mskdelta1711;  slog::Index** mbranchdelta1712;  slog::Index** $sup5638x110x0x0x0delta1713;  slog::Index** mbranchdelta1714;  slog::Index** mp_joindelta1715;  slog::Index** mp_uniondelta1716;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord1718({0, 1});
      slog::Relation* readrel1719 = db->getRelation("mp_union_ans");
      head_index[0] = readrel1719->getIndex(ord1718, false);
      outer_rel = db->getRelation("mp_msk_ans");
      std::vector<u16> ord1720({0, 1, 2});
      slog::Relation* readrel1721 = db->getRelation("mp_msk");
      mp_mskindex1698 = readrel1721->getIndex(ord1720, false);
      std::vector<u16> ord1722({0, 1, 2});
      slog::Relation* readrel1723 = db->getRelation("mp_msk");
      mp_mskdelta1711 = readrel1723->getIndex(ord1722, true);
      std::vector<u16> ord1724({3, 4, 0, 1, 2, 5, 6, 7, 8, 9, 10});
      slog::Relation* readrel1725 = db->getRelation("$sup5638x110x0x0x0");
      $sup5638x110x0x0x0index1699 = readrel1725->getIndex(ord1724, false);
      std::vector<u16> ord1726({2, 0, 1, 3, 4});
      slog::Relation* readrel1727 = db->getRelation("mbranch");
      mbranchindex1700 = readrel1727->getIndex(ord1726, false);
      std::vector<u16> ord1728({1, 2, 3, 4, 0});
      slog::Relation* readrel1729 = db->getRelation("mp_join");
      mp_joinindex1701 = readrel1729->getIndex(ord1728, false);
      std::vector<u16> ord1730({1, 2, 3, 4, 0});
      slog::Relation* readrel1731 = db->getRelation("mbranch");
      mbranchindex1702 = readrel1731->getIndex(ord1730, false);
      std::vector<u16> ord1732({1, 2, 3, 4, 0});
      slog::Relation* readrel1733 = db->getRelation("mbranch");
      mbranchdelta1712 = readrel1733->getIndex(ord1732, true);
      std::vector<u16> ord1734({1, 2, 3, 4, 0});
      slog::Relation* readrel1735 = db->getRelation("mp_join");
      mp_joinindex1703 = readrel1735->getIndex(ord1734, false);
      std::vector<u16> ord1736({1, 2, 0});
      slog::Relation* readrel1737 = db->getRelation("mp_union");
      mp_unionindex1704 = readrel1737->getIndex(ord1736, false);
      std::vector<u16> ord1738({1, 2, 4, 6, 7, 3, 0, 5, 8, 9, 10});
      slog::Relation* readrel1739 = db->getRelation("$sup5638x110x0x0x0");
      $sup5638x110x0x0x0index1705 = readrel1739->getIndex(ord1738, false);
      std::vector<u16> ord1740({1, 2, 4, 6, 7, 3, 0, 5, 8, 9, 10});
      slog::Relation* readrel1741 = db->getRelation("$sup5638x110x0x0x0");
      $sup5638x110x0x0x0delta1713 = readrel1741->getIndex(ord1740, true);
      std::vector<u16> ord1742({1, 2, 3, 4, 0});
      slog::Relation* readrel1743 = db->getRelation("mbranch");
      mbranchindex1706 = readrel1743->getIndex(ord1742, false);
      std::vector<u16> ord1744({1, 2, 3, 4, 0});
      slog::Relation* readrel1745 = db->getRelation("mbranch");
      mbranchdelta1714 = readrel1745->getIndex(ord1744, true);
      std::vector<u16> ord1746({0, 1, 2});
      slog::Relation* readrel1747 = db->getRelation("mp_union");
      mp_unionindex1707 = readrel1747->getIndex(ord1746, false);
      std::vector<u16> ord1748({1, 2, 3, 4, 0});
      slog::Relation* readrel1749 = db->getRelation("mp_join");
      mp_joinindex1708 = readrel1749->getIndex(ord1748, false);
      std::vector<u16> ord1750({1, 2, 3, 4, 0});
      slog::Relation* readrel1751 = db->getRelation("mp_join");
      mp_joindelta1715 = readrel1751->getIndex(ord1750, true);
      std::vector<u16> ord1752({0, 1, 2});
      slog::Relation* readrel1753 = db->getRelation("mp_union");
      mp_unionindex1709 = readrel1753->getIndex(ord1752, false);
      std::vector<u16> ord1754({0, 1, 2});
      slog::Relation* readrel1755 = db->getRelation("mp_union");
      mp_uniondelta1716 = readrel1755->getIndex(ord1754, true);
      std::vector<u16> ord1756({0, 1});
      slog::Relation* readrel1757 = db->getRelation("mp_join_ans");
      mp_join_ansindex1710 = readrel1757->getIndex(ord1756, false);
  
    }
    ReadTask1717(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c71 = _t[1];
        slog::join_probe_old<3,1>(mp_mskindex1698, mp_mskdelta1711, std::array<u64,3>{v_c77, 0, 0}, [&](const std::array<u64,3>& m1758) {
          u64 v_c28 = m1758[1]; u64 v_c78 = m1758[2];
          if (!slog::exists_probe<11,2>($sup5638x110x0x0x0index1699, std::array<u64,11>{v_c78, v_c28, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>(mbranchindex1700, std::array<u64,5>{v_c78, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>(mp_joinindex1701, std::array<u64,5>{v_c28, 0, 0, 0, 0})) return;
          slog::join_probe_old<5,1>(mbranchindex1702, mbranchdelta1712, std::array<u64,5>{v_c28, 0, 0, 0, 0}, [&](const std::array<u64,5>& m1759) {
            u64 v_c27 = m1759[1]; u64 v_c26 = m1759[2]; u64 v_c29 = m1759[3]; u64 v_c79 = m1759[4];
            u64 v_c270 = _prim_lt(db, v_c27, v_c78);
            if (v_c270 == slog_error) { slog::emit_pending_error(db, "map.slog:111"); return; }
            if (!v_c270) return;
            if (!slog::exists_probe<5,2>(mp_joinindex1703, std::array<u64,5>{v_c28, v_c79, 0, 0, 0})) return;
            if (!slog::exists_probe<3,1>(mp_unionindex1704, std::array<u64,3>{v_c79, 0, 0})) return;
            slog::join_probe_old<11,6>($sup5638x110x0x0x0index1705, $sup5638x110x0x0x0delta1713, std::array<u64,11>{v_c26, v_c27, v_c28, v_c29, v_c79, v_c78, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m1761) {
              u64 v_c81 = m1761[6]; u64 v_c82 = m1761[7]; u64 v_c83 = m1761[8]; u64 v_c84 = m1761[9]; u64 v_c30 = m1761[10];
              if (v_c82 == v_c71) return;
              slog::join_probe_old<5,5>(mbranchindex1706, mbranchdelta1714, std::array<u64,5>{v_c82, v_c78, v_c84, v_c30, v_c83}, [&](const std::array<u64,5>& m1762) {
                if (!slog::exists_probe<3,3>(mp_unionindex1707, std::array<u64,3>{v_c81, v_c79, v_c83})) return;
                slog::join_probe_old<5,4>(mp_joinindex1708, mp_joindelta1715, std::array<u64,5>{v_c28, v_c79, v_c82, v_c83, 0}, [&](const std::array<u64,5>& m1763) {
                  u64 v_c85 = m1763[4];
                  slog::join_probe_old<3,3>(mp_unionindex1709, mp_uniondelta1716, std::array<u64,3>{v_c81, v_c79, v_c83}, [&](const std::array<u64,3>& m1764) {
                    slog::join_probe<2,1>(mp_join_ansindex1710, std::array<u64,2>{v_c85, 0}, [&](const std::array<u64,2>& m1765) {
                      u64 v_c86 = m1765[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c81, v_c86}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:111", "delta:mp_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask1717* _cont = new ReadTask1717(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1717(db,b), false);
  // (crule (pre (let __trid7kZ41383 const8c6798fa821ed573f6b89759) (let __trel4Hl31384 const4a59dbb9cb3129dfcc75170b) (let __tcol0jkv1385 const5feceb66ffc86f38d952786c) (let __trel4njw1386 const4a59dbb9cb3129dfcc75170b) (let __tcol1xYP1387 const6b86b273ff34fce19d6b804e) (let __trel7h0r1388 const4a59dbb9cb3129dfcc75170b) (let __tcol8V0A1389 constd4735e3a265e16eee03f5971)) (scan $sup70016x51x0x0x0 __d0 ef es rho t) (body) (head (tycheck ef (accept (struct app) (struct boolean) (struct if) (struct lambda) (struct let) (struct letrec) (struct num) (struct primref) (struct ref) (struct sym)) __trid7kZ41383 __trel4Hl31384 __tcol0jkv1385 (1 2 3 4 0)) (tycheck rho (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid7kZ41383 __trel4njw1386 __tcol1xYP1387 (1 2 3 4 0)) (tycheck t (accept seq) __trid7kZ41383 __trel7h0r1388 __tcol8V0A1389 (1 2 3 4 0)) (mkstruct eval (1 2 3 0) __4iY91382 ef rho t)) interp.slog:52 #f)
  class ReadTask1779 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[4];
    slog::Index** head_index[4];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid1777;  u32 sid1766;  u32 sid1767;  u32 sid1768;  u32 sid1769;  u32 sid1770;  u32 sid1771;  u32 sid1776;  u32 sid1778;  u32 sid1772;  u32 sid1773;  u32 sid1774;  u32 sid1775;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("malformed_deduction");
      head_rel[3] = db->getRelation("eval");
      outer_rel = db->getRelation("$sup70016x51x0x0x0");
      sid1777 = db->getRelation("_enum")->getStructId();
      sid1766 = db->getRelation("app")->getStructId();
      sid1767 = db->getRelation("boolean")->getStructId();
      sid1768 = db->getRelation("if")->getStructId();
      sid1769 = db->getRelation("lambda")->getStructId();
      sid1770 = db->getRelation("let")->getStructId();
      sid1771 = db->getRelation("letrec")->getStructId();
      sid1776 = db->getRelation("mbranch")->getStructId();
      sid1778 = db->getRelation("mleaf")->getStructId();
      sid1772 = db->getRelation("num")->getStructId();
      sid1773 = db->getRelation("primref")->getStructId();
      sid1774 = db->getRelation("ref")->getStructId();
      sid1775 = db->getRelation("sym")->getStructId();
  
    }
    ReadTask1779(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c271 = v_const8c6798fa821ed573f6b89759;
      u64 v_c272 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c273 = v_const5feceb66ffc86f38d952786c;
      u64 v_c274 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c275 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c276 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c277 = v_constd4735e3a265e16eee03f5971;
  
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
        u64 v_c23 = _t[0];
        u64 v_c112 = _t[1];
        u64 v_c111 = _t[2];
        u64 v_c94 = _t[3];
        u64 v_c47 = _t[4];
        ++_fires;
        if (!((is_struct(v_c112) && (decode_struct_id(v_c112) == sid1766 || decode_struct_id(v_c112) == sid1767 || decode_struct_id(v_c112) == sid1768 || decode_struct_id(v_c112) == sid1769 || decode_struct_id(v_c112) == sid1770 || decode_struct_id(v_c112) == sid1771 || decode_struct_id(v_c112) == sid1772 || decode_struct_id(v_c112) == sid1773 || decode_struct_id(v_c112) == sid1774 || decode_struct_id(v_c112) == sid1775))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c271, v_c272, v_c273, v_c112}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c94) && (decode_struct_id(v_c94) == sid1776 || decode_struct_id(v_c94) == sid1777 || decode_struct_id(v_c94) == sid1778))))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c271, v_c274, v_c275, v_c94}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_seq(v_c47)))
        {
          slog::emit_struct<5>(head_rel[2], newbatch[2], std::array<u64,4>{v_c271, v_c276, v_c277, v_c47}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<4>(head_rel[3], newbatch[3], std::array<u64,3>{v_c112, v_c94, v_c47}, std::array<u16,4>{1, 2, 3, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
  
      if (_fires) db->bumpFires("interp.slog:52", "delta:$sup70016x51x0x0x0", _fires);
  
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
  // (crule (pre) (scan app __t6NLj559 ef es) (body (join eval (1 2 3 0) 1 __t6NLj559 rho t __1OTt1444)) (head (mkstruct eval (1 2 3 0) __7bjK1445 ef rho t)) interp.slog:59 #f)
  class ReadTask1781 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1780;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("app");
      std::vector<u16> ord1782({1, 2, 3, 0});
      slog::Relation* readrel1783 = db->getRelation("eval");
      evalindex1780 = readrel1783->getIndex(ord1782, false);
  
    }
    ReadTask1781(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c278 = _t[0];
        u64 v_c112 = _t[1];
        u64 v_c111 = _t[2];
        slog::join_probe<4,1>(evalindex1780, std::array<u64,4>{v_c278, 0, 0, 0}, [&](const std::array<u64,4>& m1784) {
          u64 v_c94 = m1784[1]; u64 v_c47 = m1784[2]; u64 v_c279 = m1784[3];
          ++_fires;
          slog::emit_struct<4>(head_rel[0], newbatch[0], std::array<u64,3>{v_c112, v_c94, v_c47}, std::array<u16,4>{1, 2, 3, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:59", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask1781* _cont = new ReadTask1781(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1781(db,b), false);
}

