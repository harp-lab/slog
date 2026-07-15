
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const057ff4484e1f56ff3c82c82e;
extern u64 v_const2f1258ada6e0e63820dc0fe2;
extern u64 v_const3f73d01b1816cdbaa7e90747;
extern u64 v_const434dac19a4d598622b9c67d7;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const9ac63e4426dab2edcc97bcf7;
extern u64 v_constbbd5c1cc5d64a17fabdfe5a2;
extern u64 v_constc46b28403aa820d86ed70496;
extern u64 v_constde3f85f3da4637dccad01619;
extern u64 v_constf4f38a14dc105d05f231e2bf;


void slog_rules_cbdf1c850d9e95d30(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre) (scan seed i l) (body) (head (mkstruct ol_fromlst (1 0) __2o7m325 l)) seq_oracle.slog:49 #f)
  class ReadTask0 : public slog::Task
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
      head_rel[0] = db->getRelation("ol_fromlst");
      outer_rel = db->getRelation("seed");
  
    }
    ReadTask0(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        ++_fires;
        slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c1}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:49", "all:seed", _fires);
  
      if (!_done)
      {
        ReadTask0* _cont = new ReadTask0(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask0(db,b), true);
  // (crule (pre (let __tconst4rci413 const9ac63e4426dab2edcc97bcf7) (let __tconst98Ss85 const5feceb66ffc86f38d952786c)) (probe ol_take (2 0 1) 1 __tconst98Ss85 __t87bV86 l) (body (join _enum (1 0) 1 __tconst4rci413 __t0ta284)) (head (emit ol_take_ans (0 1) __t87bV86 __t0ta284)) list-cons.slog:42 #f)
  class ReadTask2 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** _enumindex1;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ol_take_ans");
      std::vector<u16> ord3({0, 1});
      slog::Relation* readrel4 = db->getRelation("ol_take_ans");
      head_index[0] = readrel4->getIndex(ord3, false);
      std::vector<u16> ord5({2, 0, 1});
      slog::Relation* readrel6 = db->getRelation("ol_take");
      driver_index = readrel6->getIndex(ord5, true);
      std::vector<u16> ord7({1, 0});
      slog::Relation* readrel8 = db->getRelation("_enum");
      _enumindex1 = readrel8->getIndex(ord7, false);
  
    }
    ReadTask2(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c2 = v_const9ac63e4426dab2edcc97bcf7;
      u64 v_c3 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c3, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m9) {
        u64 v_c4 = m9[1];
        u64 v_c1 = m9[2];
        if (buckethash(v_c4) != bucket) return;
        slog::join_probe<2,1>(_enumindex1, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m10) {
          u64 v_c5 = m10[1];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c4, v_c5}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("list-cons.slog:42", "delta:ol_take", _fires);
  
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
  // (crule (pre (let __trid3uLb396 const3f73d01b1816cdbaa7e90747) (let __trel2Wp0397 constde3f85f3da4637dccad01619) (let __tcol9Vmk398 const5feceb66ffc86f38d952786c)) (scan $sup59985x12x0x0x0 _00024seq0 __d0 x xs) (body) (head (tycheck xs (accept seq) __trid3uLb396 __trel2Wp0397 __tcol9Vmk398 (1 2 3 4 0)) (mkstruct ol_fromlst (1 0) __4Yoe395 xs)) list-cons.slog:13 #f)
  class ReadTask11 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("ol_fromlst");
      outer_rel = db->getRelation("$sup59985x12x0x0x0");
  
    }
    ReadTask11(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c6 = v_const3f73d01b1816cdbaa7e90747;
      u64 v_c7 = v_constde3f85f3da4637dccad01619;
      u64 v_c8 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c9 = _t[0];
        u64 v_c10 = _t[1];
        u64 v_c11 = _t[2];
        u64 v_c12 = _t[3];
        ++_fires;
        if (!(is_seq(v_c12)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c6, v_c7, v_c8, v_c12}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c12}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("list-cons.slog:13", "delta:$sup59985x12x0x0x0", _fires);
  
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
  // (crule (pre (let __trid83LO327 const057ff4484e1f56ff3c82c82e) (let __trel3L9D328 constc46b28403aa820d86ed70496) (let __tcol4Cje329 const5feceb66ffc86f38d952786c) (let __tconst2aTd107 const6b86b273ff34fce19d6b804e)) (scan $sup59985x43x0x0x0 __d0 n x xs) (body (let __t0YLQ108 (_0002d n __tconst2aTd107))) (head (tycheck xs (accept (struct ccons) (struct _enum)) __trid83LO327 __trel3L9D328 __tcol4Cje329 (1 2 3 4 0)) (emit-temp temp2DKT786 __t0YLQ108 xs)) list-cons.slog:44 #f)
  class ReadTask14 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid13;  u32 sid12;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("temp2DKT786");
      outer_rel = db->getRelation("$sup59985x43x0x0x0");
      sid13 = db->getRelation("_enum")->getStructId();
      sid12 = db->getRelation("ccons")->getStructId();
  
    }
    ReadTask14(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c13 = v_const057ff4484e1f56ff3c82c82e;
      u64 v_c14 = v_constc46b28403aa820d86ed70496;
      u64 v_c15 = v_const5feceb66ffc86f38d952786c;
      u64 v_c16 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c10 = _t[0];
        u64 v_c17 = _t[1];
        u64 v_c11 = _t[2];
        u64 v_c12 = _t[3];
        u64 v_c18 = _prim__0002d(db, v_c17, v_c16);
        if (v_c18 == slog_error) { slog::emit_pending_error(db, "list-cons.slog:44"); return; }
        ++_fires;
        if (!((is_struct(v_c12) && (decode_struct_id(v_c12) == sid12 || decode_struct_id(v_c12) == sid13))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c13, v_c14, v_c15, v_c12}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_temp<2>(head_rel[1], newbatch[1], std::array<u64,2>{v_c18, v_c12});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("list-cons.slog:44", "delta:$sup59985x43x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask14* _cont = new ReadTask14(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask14(db,b), false);
  // (crule (pre) (scan ol_rev_acc __t1DOS26 __t1KbX25 acc) (body (join ccons (0 1 2) 1 __t1KbX25 x xs)) (head (emit-temp temp5iul788 acc x xs) (mkstruct ccons (2 1 0) __t2R1C24 acc x)) list-cons.slog:54 #f)
  class ReadTask16 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** cconsindex15;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5iul788");
      head_rel[1] = db->getRelation("ccons");
      outer_rel = db->getRelation("ol_rev_acc");
      std::vector<u16> ord17({0, 1, 2});
      slog::Relation* readrel18 = db->getRelation("ccons");
      cconsindex15 = readrel18->getIndex(ord17, false);
  
    }
    ReadTask16(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c19 = _t[0];
        u64 v_c20 = _t[1];
        u64 v_c21 = _t[2];
        slog::join_probe<3,1>(cconsindex15, std::array<u64,3>{v_c20, 0, 0}, [&](const std::array<u64,3>& m19) {
          u64 v_c11 = m19[1]; u64 v_c12 = m19[2];
          ++_fires;
          slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c21, v_c11, v_c12});
          slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c21, v_c11}, std::array<u16,3>{2, 1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("list-cons.slog:54", "delta:ol_rev_acc", _fires);
  
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
  // (crule (pre (let __tconst5CoZ46 const5feceb66ffc86f38d952786c) (let __tconst91dC47 const6b86b273ff34fce19d6b804e)) (scan ol_take_ans __t8pjA49 __v0) (body (join-old ol_take (0 2 1) 1 (0 2 1) __t8pjA49 __t2oh148 xs) (exists $sup59985x43x0x0x0 (3 2 0 1) 1 xs) (join-old ccons (2 1 0) 1 (2 1 0) xs x __t30ob44) (exists ol_take (1 2 0) 1 __t30ob44) (join-old $sup59985x43x0x0x0 (3 2 0 1) 2 (3 2 0 1) xs x __t1IJu45 n) (cmp lt __tconst5CoZ46 n) (join-old ol_take (0 2 1) 3 (0 2 1) __t1IJu45 n __t30ob44) (let chk0jjV791 (_0002d n __tconst91dC47)) (eq __t2oh148 chk0jjV791)) (head (emit-temp temp2mRb790 __t1IJu45 __v0 x) (mkstruct ccons (2 1 0) __t0pq643 __v0 x)) list-cons.slog:44 #f)
  class ReadTask30 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ol_takeindex20;  slog::Index** $sup59985x43x0x0x0index21;  slog::Index** cconsindex22;  slog::Index** ol_takeindex23;  slog::Index** $sup59985x43x0x0x0index24;  slog::Index** ol_takeindex25;  slog::Index** ol_takedelta26;  slog::Index** cconsdelta27;  slog::Index** $sup59985x43x0x0x0delta28;  slog::Index** ol_takedelta29;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2mRb790");
      head_rel[1] = db->getRelation("ccons");
      outer_rel = db->getRelation("ol_take_ans");
      std::vector<u16> ord31({0, 2, 1});
      slog::Relation* readrel32 = db->getRelation("ol_take");
      ol_takeindex20 = readrel32->getIndex(ord31, false);
      std::vector<u16> ord33({0, 2, 1});
      slog::Relation* readrel34 = db->getRelation("ol_take");
      ol_takedelta26 = readrel34->getIndex(ord33, true);
      std::vector<u16> ord35({3, 2, 0, 1});
      slog::Relation* readrel36 = db->getRelation("$sup59985x43x0x0x0");
      $sup59985x43x0x0x0index21 = readrel36->getIndex(ord35, false);
      std::vector<u16> ord37({2, 1, 0});
      slog::Relation* readrel38 = db->getRelation("ccons");
      cconsindex22 = readrel38->getIndex(ord37, false);
      std::vector<u16> ord39({2, 1, 0});
      slog::Relation* readrel40 = db->getRelation("ccons");
      cconsdelta27 = readrel40->getIndex(ord39, true);
      std::vector<u16> ord41({1, 2, 0});
      slog::Relation* readrel42 = db->getRelation("ol_take");
      ol_takeindex23 = readrel42->getIndex(ord41, false);
      std::vector<u16> ord43({3, 2, 0, 1});
      slog::Relation* readrel44 = db->getRelation("$sup59985x43x0x0x0");
      $sup59985x43x0x0x0index24 = readrel44->getIndex(ord43, false);
      std::vector<u16> ord45({3, 2, 0, 1});
      slog::Relation* readrel46 = db->getRelation("$sup59985x43x0x0x0");
      $sup59985x43x0x0x0delta28 = readrel46->getIndex(ord45, true);
      std::vector<u16> ord47({0, 2, 1});
      slog::Relation* readrel48 = db->getRelation("ol_take");
      ol_takeindex25 = readrel48->getIndex(ord47, false);
      std::vector<u16> ord49({0, 2, 1});
      slog::Relation* readrel50 = db->getRelation("ol_take");
      ol_takedelta29 = readrel50->getIndex(ord49, true);
  
    }
    ReadTask30(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c22 = v_const5feceb66ffc86f38d952786c;
      u64 v_c23 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c24 = _t[0];
        u64 v_c25 = _t[1];
        slog::join_probe_old<3,1>(ol_takeindex20, ol_takedelta26, std::array<u64,3>{v_c24, 0, 0}, [&](const std::array<u64,3>& m51) {
          u64 v_c26 = m51[1]; u64 v_c12 = m51[2];
          if (!slog::exists_probe<4,1>($sup59985x43x0x0x0index21, std::array<u64,4>{v_c12, 0, 0, 0})) return;
          slog::join_probe_old<3,1>(cconsindex22, cconsdelta27, std::array<u64,3>{v_c12, 0, 0}, [&](const std::array<u64,3>& m52) {
            u64 v_c11 = m52[1]; u64 v_c27 = m52[2];
            if (!slog::exists_probe<3,1>(ol_takeindex23, std::array<u64,3>{v_c27, 0, 0})) return;
            slog::join_probe_old<4,2>($sup59985x43x0x0x0index24, $sup59985x43x0x0x0delta28, std::array<u64,4>{v_c12, v_c11, 0, 0}, [&](const std::array<u64,4>& m53) {
              u64 v_c28 = m53[2]; u64 v_c17 = m53[3];
              u64 v_c29 = _prim_lt(db, v_c22, v_c17);
              if (v_c29 == slog_error) { slog::emit_pending_error(db, "list-cons.slog:44"); return; }
              if (!v_c29) return;
              slog::join_probe_old<3,3>(ol_takeindex25, ol_takedelta29, std::array<u64,3>{v_c28, v_c17, v_c27}, [&](const std::array<u64,3>& m55) {
                u64 v_c30 = _prim__0002d(db, v_c17, v_c23);
                if (v_c30 == slog_error) { slog::emit_pending_error(db, "list-cons.slog:44"); return; }
                if (v_c26 != v_c30) return;
                ++_fires;
                slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c28, v_c25, v_c11});
                slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c25, v_c11}, std::array<u16,3>{2, 1, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("list-cons.slog:44", "delta:ol_take_ans", _fires);
  
      if (!_done)
      {
        ReadTask30* _cont = new ReadTask30(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask30(db,b), false);
  // (crule (pre (let __tconst36rT16 const5feceb66ffc86f38d952786c)) (scan ol_take __t7n5Y15 __t5cks14 n) (body (cmp lt __tconst36rT16 n) (join ccons (0 1 2) 1 __t5cks14 x xs)) (head (emit $sup59985x43x0x0x0 (3 2 0 1) xs x __t7n5Y15 n)) list-cons.slog:44 #f)
  class ReadTask57 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** cconsindex56;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup59985x43x0x0x0");
      std::vector<u16> ord58({3, 2, 0, 1});
      slog::Relation* readrel59 = db->getRelation("$sup59985x43x0x0x0");
      head_index[0] = readrel59->getIndex(ord58, false);
      outer_rel = db->getRelation("ol_take");
      std::vector<u16> ord60({0, 1, 2});
      slog::Relation* readrel61 = db->getRelation("ccons");
      cconsindex56 = readrel61->getIndex(ord60, false);
  
    }
    ReadTask57(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c31 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c32 = _t[0];
        u64 v_c33 = _t[1];
        u64 v_c17 = _t[2];
        u64 v_c34 = _prim_lt(db, v_c31, v_c17);
        if (v_c34 == slog_error) { slog::emit_pending_error(db, "list-cons.slog:44"); return; }
        if (!v_c34) return;
        slog::join_probe<3,1>(cconsindex56, std::array<u64,3>{v_c33, 0, 0}, [&](const std::array<u64,3>& m63) {
          u64 v_c11 = m63[1]; u64 v_c12 = m63[2];
          ++_fires;
          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c12, v_c11, v_c32, v_c17}, std::array<u16,4>{3, 2, 0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("list-cons.slog:44", "delta:ol_take", _fires);
  
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
  // (crule (pre (let __trid1mcT351 constf4f38a14dc105d05f231e2bf) (let __trel26uD352 constde3f85f3da4637dccad01619) (let __tcol3QnY353 const5feceb66ffc86f38d952786c)) (scan $sup76318x27x0x0x0 a b i j) (body) (head (tycheck a (accept seq) __trid1mcT351 __trel26uD352 __tcol3QnY353 (1 2 3 4 0)) (mkstruct ol_fromlst (1 0) __6H0N350 a)) seq_oracle.slog:28 #f)
  class ReadTask64 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("ol_fromlst");
      outer_rel = db->getRelation("$sup76318x27x0x0x0");
  
    }
    ReadTask64(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c35 = v_constf4f38a14dc105d05f231e2bf;
      u64 v_c36 = v_constde3f85f3da4637dccad01619;
      u64 v_c37 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c38 = _t[0];
        u64 v_c39 = _t[1];
        u64 v_c0 = _t[2];
        u64 v_c40 = _t[3];
        ++_fires;
        if (!(is_seq(v_c38)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c35, v_c36, v_c37, v_c38}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c38}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:28", "all:$sup76318x27x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask64* _cont = new ReadTask64(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask64(db,b), true);
  // (crule (pre) (scan ol_append __t3t1M97 __t6cAF96 r) (body (exists ol_append (2 0 1) 1 r) (join $sup59985x22x0x0x0 (0 1 2 3) 2 __t3t1M97 r x xs) (join ccons (2 1 0) 3 xs x __t6cAF96) (join-old ol_append (1 2 0) 2 (1 2 0) xs r __t4evy98) (join ol_append_ans (0 1) 1 __t4evy98 z)) (head (emit-temp temp9VKb789 __t3t1M97 x z) (mkstruct ccons (2 1 0) __t7O1j95 z x)) list-cons.slog:23 #f)
  class ReadTask71 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ol_appendindex65;  slog::Index** $sup59985x22x0x0x0index66;  slog::Index** cconsindex67;  slog::Index** ol_appendindex68;  slog::Index** ol_append_ansindex69;  slog::Index** ol_appenddelta70;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9VKb789");
      head_rel[1] = db->getRelation("ccons");
      outer_rel = db->getRelation("ol_append");
      std::vector<u16> ord72({2, 0, 1});
      slog::Relation* readrel73 = db->getRelation("ol_append");
      ol_appendindex65 = readrel73->getIndex(ord72, false);
      std::vector<u16> ord74({0, 1, 2, 3});
      slog::Relation* readrel75 = db->getRelation("$sup59985x22x0x0x0");
      $sup59985x22x0x0x0index66 = readrel75->getIndex(ord74, false);
      std::vector<u16> ord76({2, 1, 0});
      slog::Relation* readrel77 = db->getRelation("ccons");
      cconsindex67 = readrel77->getIndex(ord76, false);
      std::vector<u16> ord78({1, 2, 0});
      slog::Relation* readrel79 = db->getRelation("ol_append");
      ol_appendindex68 = readrel79->getIndex(ord78, false);
      std::vector<u16> ord80({1, 2, 0});
      slog::Relation* readrel81 = db->getRelation("ol_append");
      ol_appenddelta70 = readrel81->getIndex(ord80, true);
      std::vector<u16> ord82({0, 1});
      slog::Relation* readrel83 = db->getRelation("ol_append_ans");
      ol_append_ansindex69 = readrel83->getIndex(ord82, false);
  
    }
    ReadTask71(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c41 = _t[0];
        u64 v_c42 = _t[1];
        u64 v_c43 = _t[2];
        if (!slog::exists_probe<3,1>(ol_appendindex65, std::array<u64,3>{v_c43, 0, 0})) return;
        slog::join_probe<4,2>($sup59985x22x0x0x0index66, std::array<u64,4>{v_c41, v_c43, 0, 0}, [&](const std::array<u64,4>& m84) {
          u64 v_c11 = m84[2]; u64 v_c12 = m84[3];
          slog::join_probe<3,3>(cconsindex67, std::array<u64,3>{v_c12, v_c11, v_c42}, [&](const std::array<u64,3>& m85) {
            slog::join_probe_old<3,2>(ol_appendindex68, ol_appenddelta70, std::array<u64,3>{v_c12, v_c43, 0}, [&](const std::array<u64,3>& m86) {
              u64 v_c44 = m86[2];
              slog::join_probe<2,1>(ol_append_ansindex69, std::array<u64,2>{v_c44, 0}, [&](const std::array<u64,2>& m87) {
                u64 v_c45 = m87[1];
                ++_fires;
                slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c41, v_c11, v_c45});
                slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c45, v_c11}, std::array<u16,3>{2, 1, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("list-cons.slog:23", "delta:ol_append", _fires);
  
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
  // (crule (pre (let __tconst5CoZ46 const5feceb66ffc86f38d952786c) (let __tconst91dC47 const6b86b273ff34fce19d6b804e)) (scan $sup59985x43x0x0x0 __t1IJu45 n x xs) (body (cmp lt __tconst5CoZ46 n) (exists ol_take (0 2 1) 2 __t1IJu45 n) (exists ol_take (1 2 0) 1 xs) (join-old ccons (2 1 0) 2 (2 1 0) xs x __t30ob44) (join-old ol_take (0 2 1) 3 (0 2 1) __t1IJu45 n __t30ob44) (let __t2oh148 (_0002d n __tconst91dC47)) (join-old ol_take (1 2 0) 2 (1 2 0) xs __t2oh148 __t8pjA49) (join ol_take_ans (0 1) 1 __t8pjA49 __v0)) (head (emit-temp temp2mRb790 __t1IJu45 __v0 x) (mkstruct ccons (2 1 0) __t0pq643 __v0 x)) list-cons.slog:44 #f)
  class ReadTask97 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ol_takeindex88;  slog::Index** ol_takeindex89;  slog::Index** cconsindex90;  slog::Index** ol_takeindex91;  slog::Index** ol_takeindex92;  slog::Index** ol_take_ansindex93;  slog::Index** cconsdelta94;  slog::Index** ol_takedelta95;  slog::Index** ol_takedelta96;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2mRb790");
      head_rel[1] = db->getRelation("ccons");
      outer_rel = db->getRelation("$sup59985x43x0x0x0");
      std::vector<u16> ord98({0, 2, 1});
      slog::Relation* readrel99 = db->getRelation("ol_take");
      ol_takeindex88 = readrel99->getIndex(ord98, false);
      std::vector<u16> ord100({1, 2, 0});
      slog::Relation* readrel101 = db->getRelation("ol_take");
      ol_takeindex89 = readrel101->getIndex(ord100, false);
      std::vector<u16> ord102({2, 1, 0});
      slog::Relation* readrel103 = db->getRelation("ccons");
      cconsindex90 = readrel103->getIndex(ord102, false);
      std::vector<u16> ord104({2, 1, 0});
      slog::Relation* readrel105 = db->getRelation("ccons");
      cconsdelta94 = readrel105->getIndex(ord104, true);
      std::vector<u16> ord106({0, 2, 1});
      slog::Relation* readrel107 = db->getRelation("ol_take");
      ol_takeindex91 = readrel107->getIndex(ord106, false);
      std::vector<u16> ord108({0, 2, 1});
      slog::Relation* readrel109 = db->getRelation("ol_take");
      ol_takedelta95 = readrel109->getIndex(ord108, true);
      std::vector<u16> ord110({1, 2, 0});
      slog::Relation* readrel111 = db->getRelation("ol_take");
      ol_takeindex92 = readrel111->getIndex(ord110, false);
      std::vector<u16> ord112({1, 2, 0});
      slog::Relation* readrel113 = db->getRelation("ol_take");
      ol_takedelta96 = readrel113->getIndex(ord112, true);
      std::vector<u16> ord114({0, 1});
      slog::Relation* readrel115 = db->getRelation("ol_take_ans");
      ol_take_ansindex93 = readrel115->getIndex(ord114, false);
  
    }
    ReadTask97(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c22 = v_const5feceb66ffc86f38d952786c;
      u64 v_c23 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c28 = _t[0];
        u64 v_c17 = _t[1];
        u64 v_c11 = _t[2];
        u64 v_c12 = _t[3];
        u64 v_c46 = _prim_lt(db, v_c22, v_c17);
        if (v_c46 == slog_error) { slog::emit_pending_error(db, "list-cons.slog:44"); return; }
        if (!v_c46) return;
        if (!slog::exists_probe<3,2>(ol_takeindex88, std::array<u64,3>{v_c28, v_c17, 0})) return;
        if (!slog::exists_probe<3,1>(ol_takeindex89, std::array<u64,3>{v_c12, 0, 0})) return;
        slog::join_probe_old<3,2>(cconsindex90, cconsdelta94, std::array<u64,3>{v_c12, v_c11, 0}, [&](const std::array<u64,3>& m117) {
          u64 v_c27 = m117[2];
          slog::join_probe_old<3,3>(ol_takeindex91, ol_takedelta95, std::array<u64,3>{v_c28, v_c17, v_c27}, [&](const std::array<u64,3>& m118) {
            u64 v_c26 = _prim__0002d(db, v_c17, v_c23);
            if (v_c26 == slog_error) { slog::emit_pending_error(db, "list-cons.slog:44"); return; }
            slog::join_probe_old<3,2>(ol_takeindex92, ol_takedelta96, std::array<u64,3>{v_c12, v_c26, 0}, [&](const std::array<u64,3>& m119) {
              u64 v_c24 = m119[2];
              slog::join_probe<2,1>(ol_take_ansindex93, std::array<u64,2>{v_c24, 0}, [&](const std::array<u64,2>& m120) {
                u64 v_c25 = m120[1];
                ++_fires;
                slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c28, v_c25, v_c11});
                slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c25, v_c11}, std::array<u16,3>{2, 1, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("list-cons.slog:44", "delta:$sup59985x43x0x0x0", _fires);
  
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
  // (crule (pre (let __tconst06T7421 const9ac63e4426dab2edcc97bcf7)) (scan ol_append __t4iYb261 __t1HV1260 r) (body (join _enum (0 1) 2 __t1HV1260 __tconst06T7421)) (head (emit ol_append_ans (0 1) __t4iYb261 r)) list-cons.slog:22 #f)
  class ReadTask122 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex121;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ol_append_ans");
      std::vector<u16> ord123({0, 1});
      slog::Relation* readrel124 = db->getRelation("ol_append_ans");
      head_index[0] = readrel124->getIndex(ord123, false);
      outer_rel = db->getRelation("ol_append");
      std::vector<u16> ord125({0, 1});
      slog::Relation* readrel126 = db->getRelation("_enum");
      _enumindex121 = readrel126->getIndex(ord125, false);
  
    }
    ReadTask122(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c47 = v_const9ac63e4426dab2edcc97bcf7;
  
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
        u64 v_c43 = _t[2];
        slog::join_probe<2,2>(_enumindex121, std::array<u64,2>{v_c49, v_c47}, [&](const std::array<u64,2>& m127) {
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c48, v_c43}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("list-cons.slog:22", "delta:ol_append", _fires);
  
      if (!_done)
      {
        ReadTask122* _cont = new ReadTask122(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask122(db,b), false);
  // (crule (pre) (scan ol_fromlst_ans __t3SE22 c) (body (join-old ol_fromlst (0 1) 1 (0 1) __t3SE22 l) (exists lst_rev (1 0) 1 l) (join seed (1 0) 1 l i) (join lst_rev (1 0) 1 l __t3V4l1) (join lst_rev_ans (0 1) 1 __t3V4l1 r)) (head (mkstruct ol_fromlst (1 0) __2yQv333 r)) seq_oracle.slog:59 #f)
  class ReadTask134 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ol_fromlstindex128;  slog::Index** lst_revindex129;  slog::Index** seedindex130;  slog::Index** lst_revindex131;  slog::Index** lst_rev_ansindex132;  slog::Index** ol_fromlstdelta133;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ol_fromlst");
      outer_rel = db->getRelation("ol_fromlst_ans");
      std::vector<u16> ord135({0, 1});
      slog::Relation* readrel136 = db->getRelation("ol_fromlst");
      ol_fromlstindex128 = readrel136->getIndex(ord135, false);
      std::vector<u16> ord137({0, 1});
      slog::Relation* readrel138 = db->getRelation("ol_fromlst");
      ol_fromlstdelta133 = readrel138->getIndex(ord137, true);
      std::vector<u16> ord139({1, 0});
      slog::Relation* readrel140 = db->getRelation("lst_rev");
      lst_revindex129 = readrel140->getIndex(ord139, false);
      std::vector<u16> ord141({1, 0});
      slog::Relation* readrel142 = db->getRelation("seed");
      seedindex130 = readrel142->getIndex(ord141, false);
      std::vector<u16> ord143({1, 0});
      slog::Relation* readrel144 = db->getRelation("lst_rev");
      lst_revindex131 = readrel144->getIndex(ord143, false);
      std::vector<u16> ord145({0, 1});
      slog::Relation* readrel146 = db->getRelation("lst_rev_ans");
      lst_rev_ansindex132 = readrel146->getIndex(ord145, false);
  
    }
    ReadTask134(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c50 = _t[0];
        u64 v_c51 = _t[1];
        slog::join_probe_old<2,1>(ol_fromlstindex128, ol_fromlstdelta133, std::array<u64,2>{v_c50, 0}, [&](const std::array<u64,2>& m147) {
          u64 v_c1 = m147[1];
          if (!slog::exists_probe<2,1>(lst_revindex129, std::array<u64,2>{v_c1, 0})) return;
          slog::join_probe<2,1>(seedindex130, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m148) {
            u64 v_c0 = m148[1];
            slog::join_probe<2,1>(lst_revindex131, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m149) {
              u64 v_c52 = m149[1];
              slog::join_probe<2,1>(lst_rev_ansindex132, std::array<u64,2>{v_c52, 0}, [&](const std::array<u64,2>& m150) {
                u64 v_c43 = m150[1];
                ++_fires;
                slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c43}, std::array<u16,2>{1, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:59", "delta:ol_fromlst_ans", _fires);
  
      if (!_done)
      {
        ReadTask134* _cont = new ReadTask134(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask134(db,b), false);
  // (crule (pre) (scan modulo_by_zero __erre4LiV751 __errf0Oie752 __errf1bOY753) (body) (head (emit error (0) __erre4LiV751)) <internal>:1 #f)
  class ReadTask151 : public slog::Task
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
      std::vector<u16> ord152({0});
      slog::Relation* readrel153 = db->getRelation("error");
      head_index[0] = readrel153->getIndex(ord152, false);
      outer_rel = db->getRelation("modulo_by_zero");
  
    }
    ReadTask151(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c53 = _t[0];
        u64 v_c54 = _t[1];
        u64 v_c55 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c53}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:modulo_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask151* _cont = new ReadTask151(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask151(db,b), false);
  // (crule (pre (let _00024sqc043G284 const6b86b273ff34fce19d6b804e) (let _00024sqc0Ftc285 const5feceb66ffc86f38d952786c) (let _00024sqc4Arr286 const6b86b273ff34fce19d6b804e) (let _00024sqc1a9l287 const5feceb66ffc86f38d952786c) (let _00024sqo2g9r292 const5feceb66ffc86f38d952786c)) (scan ol_fromlst __t9Mc169 xs) (body (exists $seq_at (1 0 2) 1 _00024sqo2g9r292) (exists $sup59985x12x0x0x0 (3 0 2 1) 1 xs) (join ol_fromlst_ans (0 1) 1 __t9Mc169 __v0) (join-old $seq_at (1 0 2) 1 (1 0 2) _00024sqo2g9r292 x _00024seq0) (exists ol_fromlst (1 0) 1 _00024seq0) (join $sup59985x12x0x0x0 (3 0 2 1) 3 xs _00024seq0 x __t0Thi68) (join ol_fromlst (0 1) 2 __t0Thi68 _00024seq0) (letp _00024sql34b9282 (aslst _00024seq0)) (let _00024sqn2tQo283 (llen _00024sql34b9282)) (cmp ge _00024sqn2tQo283 _00024sqc043G284) (letp chk05IK783 (lref _00024sql34b9282 _00024sqc0Ftc285)) (eq x chk05IK783) (let _00024sqp8Anj288 (_0002d _00024sqn2tQo283 _00024sqc1a9l287)) (let chk5l8G784 (lslice _00024sql34b9282 _00024sqc4Arr286 _00024sqp8Anj288)) (eq xs chk5l8G784)) (head (emit-temp temp3vIA778 __t0Thi68 __v0 x) (mkstruct ccons (2 1 0) __t3yQa67 __v0 x)) list-cons.slog:13 #f)
  class ReadTask162 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $seq_atindex154;  slog::Index** $sup59985x12x0x0x0index155;  slog::Index** ol_fromlst_ansindex156;  slog::Index** $seq_atindex157;  slog::Index** ol_fromlstindex158;  slog::Index** $sup59985x12x0x0x0index159;  slog::Index** ol_fromlstindex160;  slog::Index** $seq_atdelta161;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3vIA778");
      head_rel[1] = db->getRelation("ccons");
      outer_rel = db->getRelation("ol_fromlst");
      std::vector<u16> ord163({1, 0, 2});
      slog::Relation* readrel164 = db->getRelation("$seq_at");
      $seq_atindex154 = readrel164->getIndex(ord163, false);
      std::vector<u16> ord165({3, 0, 2, 1});
      slog::Relation* readrel166 = db->getRelation("$sup59985x12x0x0x0");
      $sup59985x12x0x0x0index155 = readrel166->getIndex(ord165, false);
      std::vector<u16> ord167({0, 1});
      slog::Relation* readrel168 = db->getRelation("ol_fromlst_ans");
      ol_fromlst_ansindex156 = readrel168->getIndex(ord167, false);
      std::vector<u16> ord169({1, 0, 2});
      slog::Relation* readrel170 = db->getRelation("$seq_at");
      $seq_atindex157 = readrel170->getIndex(ord169, false);
      std::vector<u16> ord171({1, 0, 2});
      slog::Relation* readrel172 = db->getRelation("$seq_at");
      $seq_atdelta161 = readrel172->getIndex(ord171, true);
      std::vector<u16> ord173({1, 0});
      slog::Relation* readrel174 = db->getRelation("ol_fromlst");
      ol_fromlstindex158 = readrel174->getIndex(ord173, false);
      std::vector<u16> ord175({3, 0, 2, 1});
      slog::Relation* readrel176 = db->getRelation("$sup59985x12x0x0x0");
      $sup59985x12x0x0x0index159 = readrel176->getIndex(ord175, false);
      std::vector<u16> ord177({0, 1});
      slog::Relation* readrel178 = db->getRelation("ol_fromlst");
      ol_fromlstindex160 = readrel178->getIndex(ord177, false);
  
    }
    ReadTask162(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c56 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c57 = v_const5feceb66ffc86f38d952786c;
      u64 v_c58 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c59 = v_const5feceb66ffc86f38d952786c;
      u64 v_c60 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c61 = _t[0];
        u64 v_c12 = _t[1];
        if (!slog::exists_probe<3,1>($seq_atindex154, std::array<u64,3>{v_c60, 0, 0})) return;
        if (!slog::exists_probe<4,1>($sup59985x12x0x0x0index155, std::array<u64,4>{v_c12, 0, 0, 0})) return;
        slog::join_probe<2,1>(ol_fromlst_ansindex156, std::array<u64,2>{v_c61, 0}, [&](const std::array<u64,2>& m179) {
          u64 v_c25 = m179[1];
          slog::join_probe_old<3,1>($seq_atindex157, $seq_atdelta161, std::array<u64,3>{v_c60, 0, 0}, [&](const std::array<u64,3>& m180) {
            u64 v_c11 = m180[1]; u64 v_c9 = m180[2];
            if (!slog::exists_probe<2,1>(ol_fromlstindex158, std::array<u64,2>{v_c9, 0})) return;
            slog::join_probe<4,3>($sup59985x12x0x0x0index159, std::array<u64,4>{v_c12, v_c9, v_c11, 0}, [&](const std::array<u64,4>& m181) {
              u64 v_c62 = m181[3];
              slog::join_probe<2,2>(ol_fromlstindex160, std::array<u64,2>{v_c62, v_c9}, [&](const std::array<u64,2>& m182) {
                bool ok183 = true;
                u64 v_c63 = _prim_aslst(db, v_c9, &ok183);
                if (!ok183) return;
                u64 v_c64 = _prim_llen(db, v_c63);
                if (v_c64 == slog_error) { slog::emit_pending_error(db, "list-cons.slog:13"); return; }
                u64 v_c65 = _prim_ge(db, v_c64, v_c56);
                if (v_c65 == slog_error) { slog::emit_pending_error(db, "list-cons.slog:13"); return; }
                if (!v_c65) return;
                bool ok185 = true;
                u64 v_c66 = _prim_lref(db, v_c63, v_c57, &ok185);
                if (!ok185) return;
                if (v_c11 != v_c66) return;
                u64 v_c67 = _prim__0002d(db, v_c64, v_c59);
                if (v_c67 == slog_error) { slog::emit_pending_error(db, "list-cons.slog:13"); return; }
                u64 v_c68 = _prim_lslice(db, v_c63, v_c58, v_c67);
                if (v_c68 == slog_error) { slog::emit_pending_error(db, "list-cons.slog:13"); return; }
                if (v_c12 != v_c68) return;
                ++_fires;
                slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c62, v_c25, v_c11});
                slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c25, v_c11}, std::array<u16,3>{2, 1, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("list-cons.slog:13", "delta:ol_fromlst", _fires);
  
      if (!_done)
      {
        ReadTask162* _cont = new ReadTask162(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask162(db,b), false);
  // (crule (pre (let __tconst8pyJ402 const9ac63e4426dab2edcc97bcf7) (let _00024sqc2GcD295 const5feceb66ffc86f38d952786c)) (scan ol_fromlst __t8Kyg53 _00024seq0) (body (join _enum (1 0) 1 __tconst8pyJ402 __t9fm652) (letp _00024sql4Gf2293 (aslst _00024seq0)) (let chk2b3O787 (llen _00024sql4Gf2293)) (eq _00024sqc2GcD295 chk2b3O787)) (head (emit ol_fromlst_ans (0 1) __t8Kyg53 __t9fm652)) list-cons.slog:12 #f)
  class ReadTask187 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex186;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ol_fromlst_ans");
      std::vector<u16> ord188({0, 1});
      slog::Relation* readrel189 = db->getRelation("ol_fromlst_ans");
      head_index[0] = readrel189->getIndex(ord188, false);
      outer_rel = db->getRelation("ol_fromlst");
      std::vector<u16> ord190({1, 0});
      slog::Relation* readrel191 = db->getRelation("_enum");
      _enumindex186 = readrel191->getIndex(ord190, false);
  
    }
    ReadTask187(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c69 = v_const9ac63e4426dab2edcc97bcf7;
      u64 v_c70 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c71 = _t[0];
        u64 v_c9 = _t[1];
        slog::join_probe<2,1>(_enumindex186, std::array<u64,2>{v_c69, 0}, [&](const std::array<u64,2>& m192) {
          u64 v_c72 = m192[1];
          bool ok193 = true;
          u64 v_c73 = _prim_aslst(db, v_c9, &ok193);
          if (!ok193) return;
          u64 v_c74 = _prim_llen(db, v_c73);
          if (v_c74 == slog_error) { slog::emit_pending_error(db, "list-cons.slog:12"); return; }
          if (v_c70 != v_c74) return;
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c71, v_c72}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("list-cons.slog:12", "delta:ol_fromlst", _fires);
  
      if (!_done)
      {
        ReadTask187* _cont = new ReadTask187(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask187(db,b), false);
  // (crule (pre) (scan temp3vIA778 __t0Thi68 __v0 x) (body (join ccons (2 1 0) 2 __v0 x __t3yQa67)) (head (emit ol_fromlst_ans (0 1) __t0Thi68 __t3yQa67)) list-cons.slog:13 #f)
  class ReadTask195 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** cconsindex194;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ol_fromlst_ans");
      std::vector<u16> ord196({0, 1});
      slog::Relation* readrel197 = db->getRelation("ol_fromlst_ans");
      head_index[0] = readrel197->getIndex(ord196, false);
      outer_rel = db->getRelation("temp3vIA778");
      std::vector<u16> ord198({2, 1, 0});
      slog::Relation* readrel199 = db->getRelation("ccons");
      cconsindex194 = readrel199->getIndex(ord198, false);
  
    }
    ReadTask195(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c25 = _t[1];
        u64 v_c11 = _t[2];
        slog::join_probe<3,2>(cconsindex194, std::array<u64,3>{v_c25, v_c11, 0}, [&](const std::array<u64,3>& m200) {
          u64 v_c75 = m200[2];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c62, v_c75}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("list-cons.slog:13", "delta:temp3vIA778", _fires);
  
      if (!_done)
      {
        ReadTask195* _cont = new ReadTask195(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask195(db,b), false);
  // (crule (pre (let __trid3ovs404 const434dac19a4d598622b9c67d7) (let __trel1G3U405 constde3f85f3da4637dccad01619) (let __tcol6MC1406 const5feceb66ffc86f38d952786c)) (scan $sup76318x38x0x0x0 i l y) (body) (head (tycheck l (accept seq) __trid3ovs404 __trel1G3U405 __tcol6MC1406 (1 2 3 4 0)) (mkstruct ol_fromlst (1 0) __5DDO403 l)) seq_oracle.slog:39 #f)
  class ReadTask201 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("ol_fromlst");
      outer_rel = db->getRelation("$sup76318x38x0x0x0");
  
    }
    ReadTask201(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c76 = v_const434dac19a4d598622b9c67d7;
      u64 v_c77 = v_constde3f85f3da4637dccad01619;
      u64 v_c78 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c79 = _t[2];
        ++_fires;
        if (!(is_seq(v_c1)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c76, v_c77, v_c78, v_c1}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c1}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:39", "all:$sup76318x38x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask201* _cont = new ReadTask201(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask201(db,b), true);
  // (crule (pre (let __trid32HO408 constbbd5c1cc5d64a17fabdfe5a2) (let __trel4Hof409 const2f1258ada6e0e63820dc0fe2) (let __tcol7RHO410 const5feceb66ffc86f38d952786c) (let __trel3qBy411 const2f1258ada6e0e63820dc0fe2) (let __tcol7PVr412 const6b86b273ff34fce19d6b804e)) (scan $sup59985x22x0x0x0 __d0 r x xs) (body) (head (tycheck xs (accept (struct ccons) (struct _enum)) __trid32HO408 __trel4Hof409 __tcol7RHO410 (1 2 3 4 0)) (tycheck r (accept (struct ccons) (struct _enum)) __trid32HO408 __trel3qBy411 __tcol7PVr412 (1 2 3 4 0)) (mkstruct ol_append (1 2 0) __5jvB407 xs r)) list-cons.slog:23 #f)
  class ReadTask204 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid203;  u32 sid202;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("ol_append");
      outer_rel = db->getRelation("$sup59985x22x0x0x0");
      sid203 = db->getRelation("_enum")->getStructId();
      sid202 = db->getRelation("ccons")->getStructId();
  
    }
    ReadTask204(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c80 = v_constbbd5c1cc5d64a17fabdfe5a2;
      u64 v_c81 = v_const2f1258ada6e0e63820dc0fe2;
      u64 v_c82 = v_const5feceb66ffc86f38d952786c;
      u64 v_c83 = v_const2f1258ada6e0e63820dc0fe2;
      u64 v_c84 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c10 = _t[0];
        u64 v_c43 = _t[1];
        u64 v_c11 = _t[2];
        u64 v_c12 = _t[3];
        ++_fires;
        if (!((is_struct(v_c12) && (decode_struct_id(v_c12) == sid202 || decode_struct_id(v_c12) == sid203))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c80, v_c81, v_c82, v_c12}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c43) && (decode_struct_id(v_c43) == sid202 || decode_struct_id(v_c43) == sid203))))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c80, v_c83, v_c84, v_c43}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c12, v_c43}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("list-cons.slog:23", "delta:$sup59985x22x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask204* _cont = new ReadTask204(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask204(db,b), false);
  // (crule (pre) (scan mpz_overflow __erre0eMJ770 __errf7D3C771 __errf3oJv772 __errf7SZW773 __errf6lND774) (body) (head (emit error (0) __erre0eMJ770)) <internal>:1 #f)
  class ReadTask205 : public slog::Task
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
      std::vector<u16> ord206({0});
      slog::Relation* readrel207 = db->getRelation("error");
      head_index[0] = readrel207->getIndex(ord206, false);
      outer_rel = db->getRelation("mpz_overflow");
  
    }
    ReadTask205(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c86 = _t[1];
        u64 v_c87 = _t[2];
        u64 v_c88 = _t[3];
        u64 v_c89 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c85}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_overflow", _fires);
  
      if (!_done)
      {
        ReadTask205* _cont = new ReadTask205(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask205(db,b), false);
  // (crule (pre) (scan ccons __t0rFD105 x xs) (body (join-old ol_append (1 2 0) 1 (1 2 0) __t0rFD105 r __t3Inl106)) (head (emit $sup59985x22x0x0x0 (0 1 2 3) __t3Inl106 r x xs)) list-cons.slog:23 #f)
  class ReadTask210 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ol_appendindex208;  slog::Index** ol_appenddelta209;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup59985x22x0x0x0");
      std::vector<u16> ord211({0, 1, 2, 3});
      slog::Relation* readrel212 = db->getRelation("$sup59985x22x0x0x0");
      head_index[0] = readrel212->getIndex(ord211, false);
      outer_rel = db->getRelation("ccons");
      std::vector<u16> ord213({1, 2, 0});
      slog::Relation* readrel214 = db->getRelation("ol_append");
      ol_appendindex208 = readrel214->getIndex(ord213, false);
      std::vector<u16> ord215({1, 2, 0});
      slog::Relation* readrel216 = db->getRelation("ol_append");
      ol_appenddelta209 = readrel216->getIndex(ord215, true);
  
    }
    ReadTask210(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c11 = _t[1];
        u64 v_c12 = _t[2];
        slog::join_probe_old<3,1>(ol_appendindex208, ol_appenddelta209, std::array<u64,3>{v_c90, 0, 0}, [&](const std::array<u64,3>& m217) {
          u64 v_c43 = m217[1]; u64 v_c91 = m217[2];
          ++_fires;
          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c91, v_c43, v_c11, v_c12}, std::array<u16,4>{0, 1, 2, 3});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("list-cons.slog:23", "delta:ccons", _fires);
  
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
  // (crule (pre) (scan ol_append __t3Inl106 __t0rFD105 r) (body (join ccons (0 1 2) 1 __t0rFD105 x xs)) (head (emit $sup59985x22x0x0x0 (0 1 2 3) __t3Inl106 r x xs)) list-cons.slog:23 #f)
  class ReadTask219 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** cconsindex218;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup59985x22x0x0x0");
      std::vector<u16> ord220({0, 1, 2, 3});
      slog::Relation* readrel221 = db->getRelation("$sup59985x22x0x0x0");
      head_index[0] = readrel221->getIndex(ord220, false);
      outer_rel = db->getRelation("ol_append");
      std::vector<u16> ord222({0, 1, 2});
      slog::Relation* readrel223 = db->getRelation("ccons");
      cconsindex218 = readrel223->getIndex(ord222, false);
  
    }
    ReadTask219(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c91 = _t[0];
        u64 v_c90 = _t[1];
        u64 v_c43 = _t[2];
        slog::join_probe<3,1>(cconsindex218, std::array<u64,3>{v_c90, 0, 0}, [&](const std::array<u64,3>& m224) {
          u64 v_c11 = m224[1]; u64 v_c12 = m224[2];
          ++_fires;
          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c91, v_c43, v_c11, v_c12}, std::array<u16,4>{0, 1, 2, 3});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("list-cons.slog:23", "delta:ol_append", _fires);
  
      if (!_done)
      {
        ReadTask219* _cont = new ReadTask219(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask219(db,b), false);
  // (crule (pre (let _00024sqc043G284 const6b86b273ff34fce19d6b804e) (let _00024sqc0Ftc285 const5feceb66ffc86f38d952786c) (let _00024sqc4Arr286 const6b86b273ff34fce19d6b804e) (let _00024sqc1a9l287 const5feceb66ffc86f38d952786c) (let _00024sqo2g9r292 const5feceb66ffc86f38d952786c)) (scan ol_fromlst __t0Thi68 _00024seq0) (body (letp _00024sql34b9282 (aslst _00024seq0)) (letp x (lref _00024sql34b9282 _00024sqc0Ftc285)) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo2g9r292 x _00024seq0) (let _00024sqn2tQo283 (llen _00024sql34b9282)) (cmp ge _00024sqn2tQo283 _00024sqc043G284) (let _00024sqp8Anj288 (_0002d _00024sqn2tQo283 _00024sqc1a9l287)) (let xs (lslice _00024sql34b9282 _00024sqc4Arr286 _00024sqp8Anj288)) (join $sup59985x12x0x0x0 (3 0 2 1) 4 xs _00024seq0 x __t0Thi68) (join-old ol_fromlst (1 0) 1 (1 0) xs __t9Mc169) (join ol_fromlst_ans (0 1) 1 __t9Mc169 __v0)) (head (emit-temp temp3vIA778 __t0Thi68 __v0 x) (mkstruct ccons (2 1 0) __t3yQa67 __v0 x)) list-cons.slog:13 #f)
  class ReadTask231 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $seq_atindex225;  slog::Index** $sup59985x12x0x0x0index226;  slog::Index** ol_fromlstindex227;  slog::Index** ol_fromlst_ansindex228;  slog::Index** $seq_atdelta229;  slog::Index** ol_fromlstdelta230;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3vIA778");
      head_rel[1] = db->getRelation("ccons");
      outer_rel = db->getRelation("ol_fromlst");
      std::vector<u16> ord232({1, 0, 2});
      slog::Relation* readrel233 = db->getRelation("$seq_at");
      $seq_atindex225 = readrel233->getIndex(ord232, false);
      std::vector<u16> ord234({1, 0, 2});
      slog::Relation* readrel235 = db->getRelation("$seq_at");
      $seq_atdelta229 = readrel235->getIndex(ord234, true);
      std::vector<u16> ord236({3, 0, 2, 1});
      slog::Relation* readrel237 = db->getRelation("$sup59985x12x0x0x0");
      $sup59985x12x0x0x0index226 = readrel237->getIndex(ord236, false);
      std::vector<u16> ord238({1, 0});
      slog::Relation* readrel239 = db->getRelation("ol_fromlst");
      ol_fromlstindex227 = readrel239->getIndex(ord238, false);
      std::vector<u16> ord240({1, 0});
      slog::Relation* readrel241 = db->getRelation("ol_fromlst");
      ol_fromlstdelta230 = readrel241->getIndex(ord240, true);
      std::vector<u16> ord242({0, 1});
      slog::Relation* readrel243 = db->getRelation("ol_fromlst_ans");
      ol_fromlst_ansindex228 = readrel243->getIndex(ord242, false);
  
    }
    ReadTask231(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c56 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c57 = v_const5feceb66ffc86f38d952786c;
      u64 v_c58 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c59 = v_const5feceb66ffc86f38d952786c;
      u64 v_c60 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c9 = _t[1];
        bool ok244 = true;
        u64 v_c63 = _prim_aslst(db, v_c9, &ok244);
        if (!ok244) return;
        bool ok245 = true;
        u64 v_c11 = _prim_lref(db, v_c63, v_c57, &ok245);
        if (!ok245) return;
        slog::join_probe_old<3,3>($seq_atindex225, $seq_atdelta229, std::array<u64,3>{v_c60, v_c11, v_c9}, [&](const std::array<u64,3>& m246) {
          u64 v_c64 = _prim_llen(db, v_c63);
          if (v_c64 == slog_error) { slog::emit_pending_error(db, "list-cons.slog:13"); return; }
          u64 v_c92 = _prim_ge(db, v_c64, v_c56);
          if (v_c92 == slog_error) { slog::emit_pending_error(db, "list-cons.slog:13"); return; }
          if (!v_c92) return;
          u64 v_c67 = _prim__0002d(db, v_c64, v_c59);
          if (v_c67 == slog_error) { slog::emit_pending_error(db, "list-cons.slog:13"); return; }
          u64 v_c12 = _prim_lslice(db, v_c63, v_c58, v_c67);
          if (v_c12 == slog_error) { slog::emit_pending_error(db, "list-cons.slog:13"); return; }
          slog::join_probe<4,4>($sup59985x12x0x0x0index226, std::array<u64,4>{v_c12, v_c9, v_c11, v_c62}, [&](const std::array<u64,4>& m248) {
            slog::join_probe_old<2,1>(ol_fromlstindex227, ol_fromlstdelta230, std::array<u64,2>{v_c12, 0}, [&](const std::array<u64,2>& m249) {
              u64 v_c61 = m249[1];
              slog::join_probe<2,1>(ol_fromlst_ansindex228, std::array<u64,2>{v_c61, 0}, [&](const std::array<u64,2>& m250) {
                u64 v_c25 = m250[1];
                ++_fires;
                slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c62, v_c25, v_c11});
                slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c25, v_c11}, std::array<u16,3>{2, 1, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("list-cons.slog:13", "delta:ol_fromlst", _fires);
  
      if (!_done)
      {
        ReadTask231* _cont = new ReadTask231(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask231(db,b), false);
  // (crule (pre (let _00024sqc5IUt274 const6b86b273ff34fce19d6b804e) (let _00024sqc1evu275 const5feceb66ffc86f38d952786c) (let _00024sqc5lDa276 const6b86b273ff34fce19d6b804e) (let _00024sqc8vMm277 const5feceb66ffc86f38d952786c)) (scan ol_fromlst __t0CLk87 _00024seq0) (body (letp _00024sql9Ba0272 (aslst _00024seq0)) (let _00024sqn2zXa273 (llen _00024sql9Ba0272)) (cmp ge _00024sqn2zXa273 _00024sqc5IUt274) (letp x (lref _00024sql9Ba0272 _00024sqc1evu275)) (let _00024sqp78n4278 (_0002d _00024sqn2zXa273 _00024sqc8vMm277)) (let xs (lslice _00024sql9Ba0272 _00024sqc5lDa276 _00024sqp78n4278))) (head (emit $sup59985x12x0x0x0 (3 0 2 1) xs _00024seq0 x __t0CLk87)) list-cons.slog:13 #f)
  class ReadTask251 : public slog::Task
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
      head_rel[0] = db->getRelation("$sup59985x12x0x0x0");
      std::vector<u16> ord252({3, 0, 2, 1});
      slog::Relation* readrel253 = db->getRelation("$sup59985x12x0x0x0");
      head_index[0] = readrel253->getIndex(ord252, false);
      outer_rel = db->getRelation("ol_fromlst");
  
    }
    ReadTask251(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c93 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c94 = v_const5feceb66ffc86f38d952786c;
      u64 v_c95 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c96 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c97 = _t[0];
        u64 v_c9 = _t[1];
        bool ok254 = true;
        u64 v_c98 = _prim_aslst(db, v_c9, &ok254);
        if (!ok254) return;
        u64 v_c99 = _prim_llen(db, v_c98);
        if (v_c99 == slog_error) { slog::emit_pending_error(db, "list-cons.slog:13"); return; }
        u64 v_c100 = _prim_ge(db, v_c99, v_c93);
        if (v_c100 == slog_error) { slog::emit_pending_error(db, "list-cons.slog:13"); return; }
        if (!v_c100) return;
        bool ok256 = true;
        u64 v_c11 = _prim_lref(db, v_c98, v_c94, &ok256);
        if (!ok256) return;
        u64 v_c101 = _prim__0002d(db, v_c99, v_c96);
        if (v_c101 == slog_error) { slog::emit_pending_error(db, "list-cons.slog:13"); return; }
        u64 v_c12 = _prim_lslice(db, v_c98, v_c95, v_c101);
        if (v_c12 == slog_error) { slog::emit_pending_error(db, "list-cons.slog:13"); return; }
        ++_fires;
        slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c12, v_c9, v_c11, v_c97}, std::array<u16,4>{3, 0, 2, 1});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("list-cons.slog:13", "delta:ol_fromlst", _fires);
  
      if (!_done)
      {
        ReadTask251* _cont = new ReadTask251(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask251(db,b), false);
  // (crule (pre (let __trid7j8A317 constf4f38a14dc105d05f231e2bf) (let __trel8a66318 constde3f85f3da4637dccad01619) (let __tcol5Xvt319 const5feceb66ffc86f38d952786c)) (scan $sup76318x27x0x0x0 a b i j) (body) (head (tycheck b (accept seq) __trid7j8A317 __trel8a66318 __tcol5Xvt319 (1 2 3 4 0)) (mkstruct ol_fromlst (1 0) __5SHW316 b)) seq_oracle.slog:28 #f)
  class ReadTask257 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("ol_fromlst");
      outer_rel = db->getRelation("$sup76318x27x0x0x0");
  
    }
    ReadTask257(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c102 = v_constf4f38a14dc105d05f231e2bf;
      u64 v_c103 = v_constde3f85f3da4637dccad01619;
      u64 v_c104 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c38 = _t[0];
        u64 v_c39 = _t[1];
        u64 v_c0 = _t[2];
        u64 v_c40 = _t[3];
        ++_fires;
        if (!(is_seq(v_c39)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c102, v_c103, v_c104, v_c39}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c39}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:28", "all:$sup76318x27x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask257* _cont = new ReadTask257(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask257(db,b), true);
  // (crule (pre) (scan ol_append_ans __t4evy98 z) (body (join-old ol_append (0 2 1) 1 (0 2 1) __t4evy98 r xs) (exists ccons (2 1 0) 1 xs) (exists ol_append (2 0 1) 1 r) (join-old $sup59985x22x0x0x0 (1 3 0 2) 2 (1 3 0 2) r xs __t3t1M97 x) (exists ol_append (0 2 1) 2 __t3t1M97 r) (join-old ccons (2 1 0) 2 (2 1 0) xs x __t6cAF96) (join-old ol_append (0 2 1) 3 (0 2 1) __t3t1M97 r __t6cAF96)) (head (emit-temp temp9VKb789 __t3t1M97 x z) (mkstruct ccons (2 1 0) __t7O1j95 z x)) list-cons.slog:23 #f)
  class ReadTask269 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ol_appendindex258;  slog::Index** cconsindex259;  slog::Index** ol_appendindex260;  slog::Index** $sup59985x22x0x0x0index261;  slog::Index** ol_appendindex262;  slog::Index** cconsindex263;  slog::Index** ol_appendindex264;  slog::Index** ol_appenddelta265;  slog::Index** $sup59985x22x0x0x0delta266;  slog::Index** cconsdelta267;  slog::Index** ol_appenddelta268;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9VKb789");
      head_rel[1] = db->getRelation("ccons");
      outer_rel = db->getRelation("ol_append_ans");
      std::vector<u16> ord270({0, 2, 1});
      slog::Relation* readrel271 = db->getRelation("ol_append");
      ol_appendindex258 = readrel271->getIndex(ord270, false);
      std::vector<u16> ord272({0, 2, 1});
      slog::Relation* readrel273 = db->getRelation("ol_append");
      ol_appenddelta265 = readrel273->getIndex(ord272, true);
      std::vector<u16> ord274({2, 1, 0});
      slog::Relation* readrel275 = db->getRelation("ccons");
      cconsindex259 = readrel275->getIndex(ord274, false);
      std::vector<u16> ord276({2, 0, 1});
      slog::Relation* readrel277 = db->getRelation("ol_append");
      ol_appendindex260 = readrel277->getIndex(ord276, false);
      std::vector<u16> ord278({1, 3, 0, 2});
      slog::Relation* readrel279 = db->getRelation("$sup59985x22x0x0x0");
      $sup59985x22x0x0x0index261 = readrel279->getIndex(ord278, false);
      std::vector<u16> ord280({1, 3, 0, 2});
      slog::Relation* readrel281 = db->getRelation("$sup59985x22x0x0x0");
      $sup59985x22x0x0x0delta266 = readrel281->getIndex(ord280, true);
      std::vector<u16> ord282({0, 2, 1});
      slog::Relation* readrel283 = db->getRelation("ol_append");
      ol_appendindex262 = readrel283->getIndex(ord282, false);
      std::vector<u16> ord284({2, 1, 0});
      slog::Relation* readrel285 = db->getRelation("ccons");
      cconsindex263 = readrel285->getIndex(ord284, false);
      std::vector<u16> ord286({2, 1, 0});
      slog::Relation* readrel287 = db->getRelation("ccons");
      cconsdelta267 = readrel287->getIndex(ord286, true);
      std::vector<u16> ord288({0, 2, 1});
      slog::Relation* readrel289 = db->getRelation("ol_append");
      ol_appendindex264 = readrel289->getIndex(ord288, false);
      std::vector<u16> ord290({0, 2, 1});
      slog::Relation* readrel291 = db->getRelation("ol_append");
      ol_appenddelta268 = readrel291->getIndex(ord290, true);
  
    }
    ReadTask269(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c44 = _t[0];
        u64 v_c45 = _t[1];
        slog::join_probe_old<3,1>(ol_appendindex258, ol_appenddelta265, std::array<u64,3>{v_c44, 0, 0}, [&](const std::array<u64,3>& m292) {
          u64 v_c43 = m292[1]; u64 v_c12 = m292[2];
          if (!slog::exists_probe<3,1>(cconsindex259, std::array<u64,3>{v_c12, 0, 0})) return;
          if (!slog::exists_probe<3,1>(ol_appendindex260, std::array<u64,3>{v_c43, 0, 0})) return;
          slog::join_probe_old<4,2>($sup59985x22x0x0x0index261, $sup59985x22x0x0x0delta266, std::array<u64,4>{v_c43, v_c12, 0, 0}, [&](const std::array<u64,4>& m293) {
            u64 v_c41 = m293[2]; u64 v_c11 = m293[3];
            if (!slog::exists_probe<3,2>(ol_appendindex262, std::array<u64,3>{v_c41, v_c43, 0})) return;
            slog::join_probe_old<3,2>(cconsindex263, cconsdelta267, std::array<u64,3>{v_c12, v_c11, 0}, [&](const std::array<u64,3>& m294) {
              u64 v_c42 = m294[2];
              slog::join_probe_old<3,3>(ol_appendindex264, ol_appenddelta268, std::array<u64,3>{v_c41, v_c43, v_c42}, [&](const std::array<u64,3>& m295) {
                ++_fires;
                slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c41, v_c11, v_c45});
                slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c45, v_c11}, std::array<u16,3>{2, 1, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("list-cons.slog:23", "delta:ol_append_ans", _fires);
  
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
  // (crule (pre) (scan int_overflow __erre5BXP754 __errf9WX3755 __errf04A6756 __errf63IZ757) (body) (head (emit error (0) __erre5BXP754)) <internal>:1 #f)
  class ReadTask296 : public slog::Task
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
      std::vector<u16> ord297({0});
      slog::Relation* readrel298 = db->getRelation("error");
      head_index[0] = readrel298->getIndex(ord297, false);
      outer_rel = db->getRelation("int_overflow");
  
    }
    ReadTask296(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c105 = _t[0];
        u64 v_c106 = _t[1];
        u64 v_c107 = _t[2];
        u64 v_c108 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c105}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:int_overflow", _fires);
  
      if (!_done)
      {
        ReadTask296* _cont = new ReadTask296(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask296(db,b), false);
  // (crule (pre) (scan malformed_deduction __erre53EW743 __errf79VB744 __errf7cN8745 __errf8OIr746 __errf6Vux747) (body) (head (emit error (0) __erre53EW743)) <internal>:1 #f)
  class ReadTask299 : public slog::Task
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
      std::vector<u16> ord300({0});
      slog::Relation* readrel301 = db->getRelation("error");
      head_index[0] = readrel301->getIndex(ord300, false);
      outer_rel = db->getRelation("malformed_deduction");
  
    }
    ReadTask299(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c111 = _t[2];
        u64 v_c112 = _t[3];
        u64 v_c113 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c109}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:malformed_deduction", _fires);
  
      if (!_done)
      {
        ReadTask299* _cont = new ReadTask299(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask299(db,b), false);
  // (crule (pre) (scan ol_fromlst __t6ptU21 l) (body (exists $sup76318x53x0x0x0 (2 0 1) 1 l) (exists lst_take (1 2 0) 1 l) (join ol_fromlst_ans (0 1) 1 __t6ptU21 c) (join $sup76318x53x0x0x0 (2 0 1) 1 l i k) (join lst_take (1 2 0) 2 l k __t9s8U20) (join lst_take_ans (0 1) 1 __t9s8U20 r)) (head (mkstruct ol_take (1 2 0) __0P0b311 c k)) seq_oracle.slog:54 #f)
  class ReadTask308 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup76318x53x0x0x0index302;  slog::Index** lst_takeindex303;  slog::Index** ol_fromlst_ansindex304;  slog::Index** $sup76318x53x0x0x0index305;  slog::Index** lst_takeindex306;  slog::Index** lst_take_ansindex307;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ol_take");
      outer_rel = db->getRelation("ol_fromlst");
      std::vector<u16> ord309({2, 0, 1});
      slog::Relation* readrel310 = db->getRelation("$sup76318x53x0x0x0");
      $sup76318x53x0x0x0index302 = readrel310->getIndex(ord309, false);
      std::vector<u16> ord311({1, 2, 0});
      slog::Relation* readrel312 = db->getRelation("lst_take");
      lst_takeindex303 = readrel312->getIndex(ord311, false);
      std::vector<u16> ord313({0, 1});
      slog::Relation* readrel314 = db->getRelation("ol_fromlst_ans");
      ol_fromlst_ansindex304 = readrel314->getIndex(ord313, false);
      std::vector<u16> ord315({2, 0, 1});
      slog::Relation* readrel316 = db->getRelation("$sup76318x53x0x0x0");
      $sup76318x53x0x0x0index305 = readrel316->getIndex(ord315, false);
      std::vector<u16> ord317({1, 2, 0});
      slog::Relation* readrel318 = db->getRelation("lst_take");
      lst_takeindex306 = readrel318->getIndex(ord317, false);
      std::vector<u16> ord319({0, 1});
      slog::Relation* readrel320 = db->getRelation("lst_take_ans");
      lst_take_ansindex307 = readrel320->getIndex(ord319, false);
  
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
        u64 v_c114 = _t[0];
        u64 v_c1 = _t[1];
        if (!slog::exists_probe<3,1>($sup76318x53x0x0x0index302, std::array<u64,3>{v_c1, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lst_takeindex303, std::array<u64,3>{v_c1, 0, 0})) return;
        slog::join_probe<2,1>(ol_fromlst_ansindex304, std::array<u64,2>{v_c114, 0}, [&](const std::array<u64,2>& m321) {
          u64 v_c51 = m321[1];
          slog::join_probe<3,1>($sup76318x53x0x0x0index305, std::array<u64,3>{v_c1, 0, 0}, [&](const std::array<u64,3>& m322) {
            u64 v_c0 = m322[1]; u64 v_c115 = m322[2];
            slog::join_probe<3,2>(lst_takeindex306, std::array<u64,3>{v_c1, v_c115, 0}, [&](const std::array<u64,3>& m323) {
              u64 v_c116 = m323[2];
              slog::join_probe<2,1>(lst_take_ansindex307, std::array<u64,2>{v_c116, 0}, [&](const std::array<u64,2>& m324) {
                u64 v_c43 = m324[1];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c51, v_c115}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:54", "delta:ol_fromlst", _fires);
  
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
  // (crule (pre) (scan temp2DKT786 __t0YLQ108 xs) (body) (head (mkstruct ol_take (1 2 0) __9AHN326 xs __t0YLQ108)) list-cons.slog:44 #f)
  class ReadTask325 : public slog::Task
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
      head_rel[0] = db->getRelation("ol_take");
      outer_rel = db->getRelation("temp2DKT786");
  
    }
    ReadTask325(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c18 = _t[0];
        u64 v_c12 = _t[1];
        ++_fires;
        slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c12, v_c18}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("list-cons.slog:44", "delta:temp2DKT786", _fires);
  
      if (!_done)
      {
        ReadTask325* _cont = new ReadTask325(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask325(db,b), false);
  // (crule (pre) (scan temp5iul788 acc x xs) (body (join ccons (2 1 0) 2 acc x __t2R1C24)) (head (mkstruct ol_rev_acc (1 2 0) __936K302 xs __t2R1C24)) list-cons.slog:54 #f)
  class ReadTask327 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** cconsindex326;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ol_rev_acc");
      outer_rel = db->getRelation("temp5iul788");
      std::vector<u16> ord328({2, 1, 0});
      slog::Relation* readrel329 = db->getRelation("ccons");
      cconsindex326 = readrel329->getIndex(ord328, false);
  
    }
    ReadTask327(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c11 = _t[1];
        u64 v_c12 = _t[2];
        slog::join_probe<3,2>(cconsindex326, std::array<u64,3>{v_c21, v_c11, 0}, [&](const std::array<u64,3>& m330) {
          u64 v_c117 = m330[2];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c12, v_c117}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("list-cons.slog:54", "delta:temp5iul788", _fires);
  
      if (!_done)
      {
        ReadTask327* _cont = new ReadTask327(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask327(db,b), false);
  // (crule (pre (let __tconst36rT16 const5feceb66ffc86f38d952786c)) (scan ccons __t5cks14 x xs) (body (join-old ol_take (1 2 0) 1 (1 2 0) __t5cks14 n __t7n5Y15) (cmp lt __tconst36rT16 n)) (head (emit $sup59985x43x0x0x0 (3 2 0 1) xs x __t7n5Y15 n)) list-cons.slog:44 #f)
  class ReadTask333 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ol_takeindex331;  slog::Index** ol_takedelta332;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup59985x43x0x0x0");
      std::vector<u16> ord334({3, 2, 0, 1});
      slog::Relation* readrel335 = db->getRelation("$sup59985x43x0x0x0");
      head_index[0] = readrel335->getIndex(ord334, false);
      outer_rel = db->getRelation("ccons");
      std::vector<u16> ord336({1, 2, 0});
      slog::Relation* readrel337 = db->getRelation("ol_take");
      ol_takeindex331 = readrel337->getIndex(ord336, false);
      std::vector<u16> ord338({1, 2, 0});
      slog::Relation* readrel339 = db->getRelation("ol_take");
      ol_takedelta332 = readrel339->getIndex(ord338, true);
  
    }
    ReadTask333(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c31 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c12 = _t[2];
        slog::join_probe_old<3,1>(ol_takeindex331, ol_takedelta332, std::array<u64,3>{v_c33, 0, 0}, [&](const std::array<u64,3>& m340) {
          u64 v_c17 = m340[1]; u64 v_c32 = m340[2];
          u64 v_c118 = _prim_lt(db, v_c31, v_c17);
          if (v_c118 == slog_error) { slog::emit_pending_error(db, "list-cons.slog:44"); return; }
          if (!v_c118) return;
          ++_fires;
          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c12, v_c11, v_c32, v_c17}, std::array<u16,4>{3, 2, 0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("list-cons.slog:44", "delta:ccons", _fires);
  
      if (!_done)
      {
        ReadTask333* _cont = new ReadTask333(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask333(db,b), false);
  // (crule (pre) (scan nan_result __erre6UXd758 __errf6aJQ759 __errf5fsW760 __errf3LGl761) (body) (head (emit error (0) __erre6UXd758)) <internal>:1 #f)
  class ReadTask342 : public slog::Task
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
      std::vector<u16> ord343({0});
      slog::Relation* readrel344 = db->getRelation("error");
      head_index[0] = readrel344->getIndex(ord343, false);
      outer_rel = db->getRelation("nan_result");
  
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
        u64 v_c119 = _t[0];
        u64 v_c120 = _t[1];
        u64 v_c121 = _t[2];
        u64 v_c122 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c119}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:nan_result", _fires);
  
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
  // (crule (pre) (scan ol_fromlst __t4wzo101 b) (body (exists lst_append (2 0 1) 1 b) (exists $sup76318x27x0x0x0 (1 0 2 3) 1 b) (join ol_fromlst_ans (0 1) 1 __t4wzo101 cb) (join lst_append (2 0 1) 1 b __t2Gaw99 a) (exists lst_append_ans (0 1) 1 __t2Gaw99) (exists ol_fromlst (1 0) 1 a) (join $sup76318x27x0x0x0 (0 1 2 3) 2 a b i j) (join lst_append_ans (0 1) 1 __t2Gaw99 r) (join ol_fromlst (1 0) 1 a __t1dzp100) (join ol_fromlst_ans (0 1) 1 __t1dzp100 ca)) (head (mkstruct ol_fromlst (1 0) __3XFq393 r)) seq_oracle.slog:28 #f)
  class ReadTask355 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lst_appendindex345;  slog::Index** $sup76318x27x0x0x0index346;  slog::Index** ol_fromlst_ansindex347;  slog::Index** lst_appendindex348;  slog::Index** lst_append_ansindex349;  slog::Index** ol_fromlstindex350;  slog::Index** $sup76318x27x0x0x0index351;  slog::Index** lst_append_ansindex352;  slog::Index** ol_fromlstindex353;  slog::Index** ol_fromlst_ansindex354;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ol_fromlst");
      outer_rel = db->getRelation("ol_fromlst");
      std::vector<u16> ord356({2, 0, 1});
      slog::Relation* readrel357 = db->getRelation("lst_append");
      lst_appendindex345 = readrel357->getIndex(ord356, false);
      std::vector<u16> ord358({1, 0, 2, 3});
      slog::Relation* readrel359 = db->getRelation("$sup76318x27x0x0x0");
      $sup76318x27x0x0x0index346 = readrel359->getIndex(ord358, false);
      std::vector<u16> ord360({0, 1});
      slog::Relation* readrel361 = db->getRelation("ol_fromlst_ans");
      ol_fromlst_ansindex347 = readrel361->getIndex(ord360, false);
      std::vector<u16> ord362({2, 0, 1});
      slog::Relation* readrel363 = db->getRelation("lst_append");
      lst_appendindex348 = readrel363->getIndex(ord362, false);
      std::vector<u16> ord364({0, 1});
      slog::Relation* readrel365 = db->getRelation("lst_append_ans");
      lst_append_ansindex349 = readrel365->getIndex(ord364, false);
      std::vector<u16> ord366({1, 0});
      slog::Relation* readrel367 = db->getRelation("ol_fromlst");
      ol_fromlstindex350 = readrel367->getIndex(ord366, false);
      std::vector<u16> ord368({0, 1, 2, 3});
      slog::Relation* readrel369 = db->getRelation("$sup76318x27x0x0x0");
      $sup76318x27x0x0x0index351 = readrel369->getIndex(ord368, false);
      std::vector<u16> ord370({0, 1});
      slog::Relation* readrel371 = db->getRelation("lst_append_ans");
      lst_append_ansindex352 = readrel371->getIndex(ord370, false);
      std::vector<u16> ord372({1, 0});
      slog::Relation* readrel373 = db->getRelation("ol_fromlst");
      ol_fromlstindex353 = readrel373->getIndex(ord372, false);
      std::vector<u16> ord374({0, 1});
      slog::Relation* readrel375 = db->getRelation("ol_fromlst_ans");
      ol_fromlst_ansindex354 = readrel375->getIndex(ord374, false);
  
    }
    ReadTask355(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c39 = _t[1];
        if (!slog::exists_probe<3,1>(lst_appendindex345, std::array<u64,3>{v_c39, 0, 0})) return;
        if (!slog::exists_probe<4,1>($sup76318x27x0x0x0index346, std::array<u64,4>{v_c39, 0, 0, 0})) return;
        slog::join_probe<2,1>(ol_fromlst_ansindex347, std::array<u64,2>{v_c123, 0}, [&](const std::array<u64,2>& m376) {
          u64 v_c124 = m376[1];
          slog::join_probe<3,1>(lst_appendindex348, std::array<u64,3>{v_c39, 0, 0}, [&](const std::array<u64,3>& m377) {
            u64 v_c125 = m377[1]; u64 v_c38 = m377[2];
            if (!slog::exists_probe<2,1>(lst_append_ansindex349, std::array<u64,2>{v_c125, 0})) return;
            if (!slog::exists_probe<2,1>(ol_fromlstindex350, std::array<u64,2>{v_c38, 0})) return;
            slog::join_probe<4,2>($sup76318x27x0x0x0index351, std::array<u64,4>{v_c38, v_c39, 0, 0}, [&](const std::array<u64,4>& m378) {
              u64 v_c0 = m378[2]; u64 v_c40 = m378[3];
              slog::join_probe<2,1>(lst_append_ansindex352, std::array<u64,2>{v_c125, 0}, [&](const std::array<u64,2>& m379) {
                u64 v_c43 = m379[1];
                slog::join_probe<2,1>(ol_fromlstindex353, std::array<u64,2>{v_c38, 0}, [&](const std::array<u64,2>& m380) {
                  u64 v_c126 = m380[1];
                  slog::join_probe<2,1>(ol_fromlst_ansindex354, std::array<u64,2>{v_c126, 0}, [&](const std::array<u64,2>& m381) {
                    u64 v_c127 = m381[1];
                    ++_fires;
                    slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c43}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:28", "delta:ol_fromlst", _fires);
  
      if (!_done)
      {
        ReadTask355* _cont = new ReadTask355(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask355(db,b), false);
  // (crule (pre) (scan ol_fromlst __t56aw4 l) (body (exists ol_fromlst_ans (0 1) 1 __t56aw4) (exists lst_rev (1 0) 1 l) (join seed (1 0) 1 l i) (join ol_fromlst_ans (0 1) 1 __t56aw4 c) (join lst_rev (1 0) 1 l __t5hLI3) (join lst_rev_ans (0 1) 1 __t5hLI3 r)) (head (mkstruct ol_rev (1 0) __9mwF303 c)) seq_oracle.slog:59 #f)
  class ReadTask388 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ol_fromlst_ansindex382;  slog::Index** lst_revindex383;  slog::Index** seedindex384;  slog::Index** ol_fromlst_ansindex385;  slog::Index** lst_revindex386;  slog::Index** lst_rev_ansindex387;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ol_rev");
      outer_rel = db->getRelation("ol_fromlst");
      std::vector<u16> ord389({0, 1});
      slog::Relation* readrel390 = db->getRelation("ol_fromlst_ans");
      ol_fromlst_ansindex382 = readrel390->getIndex(ord389, false);
      std::vector<u16> ord391({1, 0});
      slog::Relation* readrel392 = db->getRelation("lst_rev");
      lst_revindex383 = readrel392->getIndex(ord391, false);
      std::vector<u16> ord393({1, 0});
      slog::Relation* readrel394 = db->getRelation("seed");
      seedindex384 = readrel394->getIndex(ord393, false);
      std::vector<u16> ord395({0, 1});
      slog::Relation* readrel396 = db->getRelation("ol_fromlst_ans");
      ol_fromlst_ansindex385 = readrel396->getIndex(ord395, false);
      std::vector<u16> ord397({1, 0});
      slog::Relation* readrel398 = db->getRelation("lst_rev");
      lst_revindex386 = readrel398->getIndex(ord397, false);
      std::vector<u16> ord399({0, 1});
      slog::Relation* readrel400 = db->getRelation("lst_rev_ans");
      lst_rev_ansindex387 = readrel400->getIndex(ord399, false);
  
    }
    ReadTask388(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c1 = _t[1];
        if (!slog::exists_probe<2,1>(ol_fromlst_ansindex382, std::array<u64,2>{v_c128, 0})) return;
        if (!slog::exists_probe<2,1>(lst_revindex383, std::array<u64,2>{v_c1, 0})) return;
        slog::join_probe<2,1>(seedindex384, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m401) {
          u64 v_c0 = m401[1];
          slog::join_probe<2,1>(ol_fromlst_ansindex385, std::array<u64,2>{v_c128, 0}, [&](const std::array<u64,2>& m402) {
            u64 v_c51 = m402[1];
            slog::join_probe<2,1>(lst_revindex386, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m403) {
              u64 v_c129 = m403[1];
              slog::join_probe<2,1>(lst_rev_ansindex387, std::array<u64,2>{v_c129, 0}, [&](const std::array<u64,2>& m404) {
                u64 v_c43 = m404[1];
                ++_fires;
                slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c51}, std::array<u16,2>{1, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:59", "delta:ol_fromlst", _fires);
  
      if (!_done)
      {
        ReadTask388* _cont = new ReadTask388(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask388(db,b), false);
}

