
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const154aa17dce57824acb89891d;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const9ac63e4426dab2edcc97bcf7;
extern u64 v_constc0b63bd612a3529319444133;
extern u64 v_constcff65e3a987ac3b552474055;
extern u64 v_constde3f85f3da4637dccad01619;


void slog_rules_c8cc1d9f9b87ffafc(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre (let _00024sqc043G284 const6b86b273ff34fce19d6b804e) (let _00024sqc0Ftc285 const5feceb66ffc86f38d952786c) (let _00024sqc4Arr286 const6b86b273ff34fce19d6b804e) (let _00024sqc1a9l287 const5feceb66ffc86f38d952786c) (let _00024sqo2g9r292 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo2g9r292 x _00024seq0) (body (letp _00024sql34b9282 (aslst _00024seq0)) (let _00024sqn2tQo283 (llen _00024sql34b9282)) (cmp ge _00024sqn2tQo283 _00024sqc043G284) (let _00024sqp8Anj288 (_0002d _00024sqn2tQo283 _00024sqc1a9l287)) (let xs (lslice _00024sql34b9282 _00024sqc4Arr286 _00024sqp8Anj288)) (exists ol_fromlst (1 0) 1 _00024seq0) (exists ol_fromlst (1 0) 1 xs) (join $sup59985x12x0x0x0 (3 0 2 1) 3 xs _00024seq0 x __t0Thi68) (join ol_fromlst (0 1) 2 __t0Thi68 _00024seq0) (join ol_fromlst (1 0) 1 xs __t9Mc169) (join ol_fromlst_ans (0 1) 1 __t9Mc169 __v0) (letp chk5MNX785 (lref _00024sql34b9282 _00024sqc0Ftc285)) (eq x chk5MNX785)) (head (emit-temp temp3vIA778 __t0Thi68 __v0 x) (mkstruct ccons (2 1 0) __t3yQa67 __v0 x)) list-cons.slog:13 #f)
  class ReadTask6 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** ol_fromlstindex0;  slog::Index** ol_fromlstindex1;  slog::Index** $sup59985x12x0x0x0index2;  slog::Index** ol_fromlstindex3;  slog::Index** ol_fromlstindex4;  slog::Index** ol_fromlst_ansindex5;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3vIA778");
      head_rel[1] = db->getRelation("ccons");
      std::vector<u16> ord7({1, 0, 2});
      slog::Relation* readrel8 = db->getRelation("$seq_at");
      driver_index = readrel8->getIndex(ord7, true);
      std::vector<u16> ord9({1, 0});
      slog::Relation* readrel10 = db->getRelation("ol_fromlst");
      ol_fromlstindex0 = readrel10->getIndex(ord9, false);
      std::vector<u16> ord11({1, 0});
      slog::Relation* readrel12 = db->getRelation("ol_fromlst");
      ol_fromlstindex1 = readrel12->getIndex(ord11, false);
      std::vector<u16> ord13({3, 0, 2, 1});
      slog::Relation* readrel14 = db->getRelation("$sup59985x12x0x0x0");
      $sup59985x12x0x0x0index2 = readrel14->getIndex(ord13, false);
      std::vector<u16> ord15({0, 1});
      slog::Relation* readrel16 = db->getRelation("ol_fromlst");
      ol_fromlstindex3 = readrel16->getIndex(ord15, false);
      std::vector<u16> ord17({1, 0});
      slog::Relation* readrel18 = db->getRelation("ol_fromlst");
      ol_fromlstindex4 = readrel18->getIndex(ord17, false);
      std::vector<u16> ord19({0, 1});
      slog::Relation* readrel20 = db->getRelation("ol_fromlst_ans");
      ol_fromlst_ansindex5 = readrel20->getIndex(ord19, false);
  
    }
    ReadTask6(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c1 = v_const5feceb66ffc86f38d952786c;
      u64 v_c2 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c3 = v_const5feceb66ffc86f38d952786c;
      u64 v_c4 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c4, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m21) {
        u64 v_c5 = m21[1];
        u64 v_c6 = m21[2];
        if (buckethash(v_c5) != bucket) return;
        bool ok22 = true;
        u64 v_c7 = _prim_aslst(db, v_c6, &ok22);
        if (!ok22) return;
        u64 v_c8 = _prim_llen(db, v_c7);
        if (v_c8 == slog_error) { slog::emit_pending_error(db, "list-cons.slog:13"); return; }
        u64 v_c9 = _prim_ge(db, v_c8, v_c0);
        if (v_c9 == slog_error) { slog::emit_pending_error(db, "list-cons.slog:13"); return; }
        if (!v_c9) return;
        u64 v_c10 = _prim__0002d(db, v_c8, v_c3);
        if (v_c10 == slog_error) { slog::emit_pending_error(db, "list-cons.slog:13"); return; }
        u64 v_c11 = _prim_lslice(db, v_c7, v_c2, v_c10);
        if (v_c11 == slog_error) { slog::emit_pending_error(db, "list-cons.slog:13"); return; }
        if (!slog::exists_probe<2,1>(ol_fromlstindex0, std::array<u64,2>{v_c6, 0})) return;
        if (!slog::exists_probe<2,1>(ol_fromlstindex1, std::array<u64,2>{v_c11, 0})) return;
        slog::join_probe<4,3>($sup59985x12x0x0x0index2, std::array<u64,4>{v_c11, v_c6, v_c5, 0}, [&](const std::array<u64,4>& m24) {
          u64 v_c12 = m24[3];
          slog::join_probe<2,2>(ol_fromlstindex3, std::array<u64,2>{v_c12, v_c6}, [&](const std::array<u64,2>& m25) {
            slog::join_probe<2,1>(ol_fromlstindex4, std::array<u64,2>{v_c11, 0}, [&](const std::array<u64,2>& m26) {
              u64 v_c13 = m26[1];
              slog::join_probe<2,1>(ol_fromlst_ansindex5, std::array<u64,2>{v_c13, 0}, [&](const std::array<u64,2>& m27) {
                u64 v_c14 = m27[1];
                bool ok28 = true;
                u64 v_c15 = _prim_lref(db, v_c7, v_c1, &ok28);
                if (!ok28) return;
                if (v_c5 != v_c15) return;
                ++_fires;
                slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c12, v_c14, v_c5});
                slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c14, v_c5}, std::array<u16,3>{2, 1, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("list-cons.slog:13", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask6* _cont = new ReadTask6(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask6(db,b), false);
  // (crule (pre) (scan ol_fromlst __t1qQi104 b) (body (exists lst_append (2 0 1) 1 b) (exists $sup76318x27x0x0x0 (1 0 2 3) 1 b) (join ol_fromlst_ans (0 1) 1 __t1qQi104 cb) (join lst_append (2 0 1) 1 b __t5oTD102 a) (exists lst_append_ans (0 1) 1 __t5oTD102) (exists ol_fromlst (1 0) 1 a) (join $sup76318x27x0x0x0 (0 1 2 3) 2 a b i j) (join lst_append_ans (0 1) 1 __t5oTD102 r) (join ol_fromlst (1 0) 1 a __t5TS9103) (join ol_fromlst_ans (0 1) 1 __t5TS9103 ca)) (head (mkstruct ol_append (1 2 0) __5fbv387 ca cb)) seq_oracle.slog:28 #f)
  class ReadTask39 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lst_appendindex29;  slog::Index** $sup76318x27x0x0x0index30;  slog::Index** ol_fromlst_ansindex31;  slog::Index** lst_appendindex32;  slog::Index** lst_append_ansindex33;  slog::Index** ol_fromlstindex34;  slog::Index** $sup76318x27x0x0x0index35;  slog::Index** lst_append_ansindex36;  slog::Index** ol_fromlstindex37;  slog::Index** ol_fromlst_ansindex38;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ol_append");
      outer_rel = db->getRelation("ol_fromlst");
      std::vector<u16> ord40({2, 0, 1});
      slog::Relation* readrel41 = db->getRelation("lst_append");
      lst_appendindex29 = readrel41->getIndex(ord40, false);
      std::vector<u16> ord42({1, 0, 2, 3});
      slog::Relation* readrel43 = db->getRelation("$sup76318x27x0x0x0");
      $sup76318x27x0x0x0index30 = readrel43->getIndex(ord42, false);
      std::vector<u16> ord44({0, 1});
      slog::Relation* readrel45 = db->getRelation("ol_fromlst_ans");
      ol_fromlst_ansindex31 = readrel45->getIndex(ord44, false);
      std::vector<u16> ord46({2, 0, 1});
      slog::Relation* readrel47 = db->getRelation("lst_append");
      lst_appendindex32 = readrel47->getIndex(ord46, false);
      std::vector<u16> ord48({0, 1});
      slog::Relation* readrel49 = db->getRelation("lst_append_ans");
      lst_append_ansindex33 = readrel49->getIndex(ord48, false);
      std::vector<u16> ord50({1, 0});
      slog::Relation* readrel51 = db->getRelation("ol_fromlst");
      ol_fromlstindex34 = readrel51->getIndex(ord50, false);
      std::vector<u16> ord52({0, 1, 2, 3});
      slog::Relation* readrel53 = db->getRelation("$sup76318x27x0x0x0");
      $sup76318x27x0x0x0index35 = readrel53->getIndex(ord52, false);
      std::vector<u16> ord54({0, 1});
      slog::Relation* readrel55 = db->getRelation("lst_append_ans");
      lst_append_ansindex36 = readrel55->getIndex(ord54, false);
      std::vector<u16> ord56({1, 0});
      slog::Relation* readrel57 = db->getRelation("ol_fromlst");
      ol_fromlstindex37 = readrel57->getIndex(ord56, false);
      std::vector<u16> ord58({0, 1});
      slog::Relation* readrel59 = db->getRelation("ol_fromlst_ans");
      ol_fromlst_ansindex38 = readrel59->getIndex(ord58, false);
  
    }
    ReadTask39(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c17 = _t[1];
        if (!slog::exists_probe<3,1>(lst_appendindex29, std::array<u64,3>{v_c17, 0, 0})) return;
        if (!slog::exists_probe<4,1>($sup76318x27x0x0x0index30, std::array<u64,4>{v_c17, 0, 0, 0})) return;
        slog::join_probe<2,1>(ol_fromlst_ansindex31, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m60) {
          u64 v_c18 = m60[1];
          slog::join_probe<3,1>(lst_appendindex32, std::array<u64,3>{v_c17, 0, 0}, [&](const std::array<u64,3>& m61) {
            u64 v_c19 = m61[1]; u64 v_c20 = m61[2];
            if (!slog::exists_probe<2,1>(lst_append_ansindex33, std::array<u64,2>{v_c19, 0})) return;
            if (!slog::exists_probe<2,1>(ol_fromlstindex34, std::array<u64,2>{v_c20, 0})) return;
            slog::join_probe<4,2>($sup76318x27x0x0x0index35, std::array<u64,4>{v_c20, v_c17, 0, 0}, [&](const std::array<u64,4>& m62) {
              u64 v_c21 = m62[2]; u64 v_c22 = m62[3];
              slog::join_probe<2,1>(lst_append_ansindex36, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m63) {
                u64 v_c23 = m63[1];
                slog::join_probe<2,1>(ol_fromlstindex37, std::array<u64,2>{v_c20, 0}, [&](const std::array<u64,2>& m64) {
                  u64 v_c24 = m64[1];
                  slog::join_probe<2,1>(ol_fromlst_ansindex38, std::array<u64,2>{v_c24, 0}, [&](const std::array<u64,2>& m65) {
                    u64 v_c25 = m65[1];
                    ++_fires;
                    slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c25, v_c18}, std::array<u16,3>{1, 2, 0});
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
        ReadTask39* _cont = new ReadTask39(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask39(db,b), false);
  // (crule (pre) (scan temp2mRb790 __t1IJu45 __v0 x) (body (join ccons (2 1 0) 2 __v0 x __t0pq643)) (head (emit ol_take_ans (0 1) __t1IJu45 __t0pq643)) list-cons.slog:44 #f)
  class ReadTask67 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** cconsindex66;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ol_take_ans");
      std::vector<u16> ord68({0, 1});
      slog::Relation* readrel69 = db->getRelation("ol_take_ans");
      head_index[0] = readrel69->getIndex(ord68, false);
      outer_rel = db->getRelation("temp2mRb790");
      std::vector<u16> ord70({2, 1, 0});
      slog::Relation* readrel71 = db->getRelation("ccons");
      cconsindex66 = readrel71->getIndex(ord70, false);
  
    }
    ReadTask67(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c14 = _t[1];
        u64 v_c5 = _t[2];
        slog::join_probe<3,2>(cconsindex66, std::array<u64,3>{v_c14, v_c5, 0}, [&](const std::array<u64,3>& m72) {
          u64 v_c27 = m72[2];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c26, v_c27}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("list-cons.slog:44", "delta:temp2mRb790", _fires);
  
      if (!_done)
      {
        ReadTask67* _cont = new ReadTask67(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask67(db,b), false);
  // (crule (pre) (scan ol_fromlst_ans __t5TS9103 ca) (body (join-old ol_fromlst (0 1) 1 (0 1) __t5TS9103 a) (exists $sup76318x27x0x0x0 (0 1 2 3) 1 a) (join lst_append (1 2 0) 1 a b __t5oTD102) (exists lst_append_ans (0 1) 1 __t5oTD102) (exists ol_fromlst (1 0) 1 b) (join $sup76318x27x0x0x0 (0 1 2 3) 2 a b i j) (join lst_append_ans (0 1) 1 __t5oTD102 r) (join-old ol_fromlst (1 0) 1 (1 0) b __t1qQi104) (join-old ol_fromlst_ans (0 1) 1 (0 1) __t1qQi104 cb)) (head (mkstruct ol_append (1 2 0) __5fbv387 ca cb)) seq_oracle.slog:28 #f)
  class ReadTask85 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ol_fromlstindex73;  slog::Index** $sup76318x27x0x0x0index74;  slog::Index** lst_appendindex75;  slog::Index** lst_append_ansindex76;  slog::Index** ol_fromlstindex77;  slog::Index** $sup76318x27x0x0x0index78;  slog::Index** lst_append_ansindex79;  slog::Index** ol_fromlstindex80;  slog::Index** ol_fromlst_ansindex81;  slog::Index** ol_fromlstdelta82;  slog::Index** ol_fromlstdelta83;  slog::Index** ol_fromlst_ansdelta84;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ol_append");
      outer_rel = db->getRelation("ol_fromlst_ans");
      std::vector<u16> ord86({0, 1});
      slog::Relation* readrel87 = db->getRelation("ol_fromlst");
      ol_fromlstindex73 = readrel87->getIndex(ord86, false);
      std::vector<u16> ord88({0, 1});
      slog::Relation* readrel89 = db->getRelation("ol_fromlst");
      ol_fromlstdelta82 = readrel89->getIndex(ord88, true);
      std::vector<u16> ord90({0, 1, 2, 3});
      slog::Relation* readrel91 = db->getRelation("$sup76318x27x0x0x0");
      $sup76318x27x0x0x0index74 = readrel91->getIndex(ord90, false);
      std::vector<u16> ord92({1, 2, 0});
      slog::Relation* readrel93 = db->getRelation("lst_append");
      lst_appendindex75 = readrel93->getIndex(ord92, false);
      std::vector<u16> ord94({0, 1});
      slog::Relation* readrel95 = db->getRelation("lst_append_ans");
      lst_append_ansindex76 = readrel95->getIndex(ord94, false);
      std::vector<u16> ord96({1, 0});
      slog::Relation* readrel97 = db->getRelation("ol_fromlst");
      ol_fromlstindex77 = readrel97->getIndex(ord96, false);
      std::vector<u16> ord98({0, 1, 2, 3});
      slog::Relation* readrel99 = db->getRelation("$sup76318x27x0x0x0");
      $sup76318x27x0x0x0index78 = readrel99->getIndex(ord98, false);
      std::vector<u16> ord100({0, 1});
      slog::Relation* readrel101 = db->getRelation("lst_append_ans");
      lst_append_ansindex79 = readrel101->getIndex(ord100, false);
      std::vector<u16> ord102({1, 0});
      slog::Relation* readrel103 = db->getRelation("ol_fromlst");
      ol_fromlstindex80 = readrel103->getIndex(ord102, false);
      std::vector<u16> ord104({1, 0});
      slog::Relation* readrel105 = db->getRelation("ol_fromlst");
      ol_fromlstdelta83 = readrel105->getIndex(ord104, true);
      std::vector<u16> ord106({0, 1});
      slog::Relation* readrel107 = db->getRelation("ol_fromlst_ans");
      ol_fromlst_ansindex81 = readrel107->getIndex(ord106, false);
      std::vector<u16> ord108({0, 1});
      slog::Relation* readrel109 = db->getRelation("ol_fromlst_ans");
      ol_fromlst_ansdelta84 = readrel109->getIndex(ord108, true);
  
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
        u64 v_c24 = _t[0];
        u64 v_c25 = _t[1];
        slog::join_probe_old<2,1>(ol_fromlstindex73, ol_fromlstdelta82, std::array<u64,2>{v_c24, 0}, [&](const std::array<u64,2>& m110) {
          u64 v_c20 = m110[1];
          if (!slog::exists_probe<4,1>($sup76318x27x0x0x0index74, std::array<u64,4>{v_c20, 0, 0, 0})) return;
          slog::join_probe<3,1>(lst_appendindex75, std::array<u64,3>{v_c20, 0, 0}, [&](const std::array<u64,3>& m111) {
            u64 v_c17 = m111[1]; u64 v_c19 = m111[2];
            if (!slog::exists_probe<2,1>(lst_append_ansindex76, std::array<u64,2>{v_c19, 0})) return;
            if (!slog::exists_probe<2,1>(ol_fromlstindex77, std::array<u64,2>{v_c17, 0})) return;
            slog::join_probe<4,2>($sup76318x27x0x0x0index78, std::array<u64,4>{v_c20, v_c17, 0, 0}, [&](const std::array<u64,4>& m112) {
              u64 v_c21 = m112[2]; u64 v_c22 = m112[3];
              slog::join_probe<2,1>(lst_append_ansindex79, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m113) {
                u64 v_c23 = m113[1];
                slog::join_probe_old<2,1>(ol_fromlstindex80, ol_fromlstdelta83, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m114) {
                  u64 v_c16 = m114[1];
                  slog::join_probe_old<2,1>(ol_fromlst_ansindex81, ol_fromlst_ansdelta84, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m115) {
                    u64 v_c18 = m115[1];
                    ++_fires;
                    slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c25, v_c18}, std::array<u16,3>{1, 2, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:28", "delta:ol_fromlst_ans", _fires);
  
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
  // (crule (pre) (scan div_by_zero __erre4p06748 __errf54rZ749 __errf9uVj750) (body) (head (emit error (0) __erre4p06748)) <internal>:1 #f)
  class ReadTask116 : public slog::Task
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
      std::vector<u16> ord117({0});
      slog::Relation* readrel118 = db->getRelation("error");
      head_index[0] = readrel118->getIndex(ord117, false);
      outer_rel = db->getRelation("div_by_zero");
  
    }
    ReadTask116(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c30 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c28}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:div_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask116* _cont = new ReadTask116(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask116(db,b), false);
  // (crule (pre) (scan ccons __t1KbX25 x xs) (body (join-old ol_rev_acc (1 2 0) 1 (1 2 0) __t1KbX25 acc __t1DOS26)) (head (emit-temp temp5iul788 acc x xs) (mkstruct ccons (2 1 0) __t2R1C24 acc x)) list-cons.slog:54 #f)
  class ReadTask121 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ol_rev_accindex119;  slog::Index** ol_rev_accdelta120;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5iul788");
      head_rel[1] = db->getRelation("ccons");
      outer_rel = db->getRelation("ccons");
      std::vector<u16> ord122({1, 2, 0});
      slog::Relation* readrel123 = db->getRelation("ol_rev_acc");
      ol_rev_accindex119 = readrel123->getIndex(ord122, false);
      std::vector<u16> ord124({1, 2, 0});
      slog::Relation* readrel125 = db->getRelation("ol_rev_acc");
      ol_rev_accdelta120 = readrel125->getIndex(ord124, true);
  
    }
    ReadTask121(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c31 = _t[0];
        u64 v_c5 = _t[1];
        u64 v_c11 = _t[2];
        slog::join_probe_old<3,1>(ol_rev_accindex119, ol_rev_accdelta120, std::array<u64,3>{v_c31, 0, 0}, [&](const std::array<u64,3>& m126) {
          u64 v_c32 = m126[1]; u64 v_c33 = m126[2];
          ++_fires;
          slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c32, v_c5, v_c11});
          slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c32, v_c5}, std::array<u16,3>{2, 1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("list-cons.slog:54", "delta:ccons", _fires);
  
      if (!_done)
      {
        ReadTask121* _cont = new ReadTask121(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask121(db,b), false);
  // (crule (pre (let __tconst5CoZ46 const5feceb66ffc86f38d952786c) (let __tconst91dC47 const6b86b273ff34fce19d6b804e)) (scan ccons __t30ob44 x xs) (body (exists ol_take (1 2 0) 1 __t30ob44) (exists ol_take (1 2 0) 1 xs) (join $sup59985x43x0x0x0 (3 2 0 1) 2 xs x __t1IJu45 n) (cmp lt __tconst5CoZ46 n) (join-old ol_take (0 2 1) 3 (0 2 1) __t1IJu45 n __t30ob44) (let __t2oh148 (_0002d n __tconst91dC47)) (join-old ol_take (1 2 0) 2 (1 2 0) xs __t2oh148 __t8pjA49) (join ol_take_ans (0 1) 1 __t8pjA49 __v0)) (head (emit-temp temp2mRb790 __t1IJu45 __v0 x) (mkstruct ccons (2 1 0) __t0pq643 __v0 x)) list-cons.slog:44 #f)
  class ReadTask135 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ol_takeindex127;  slog::Index** ol_takeindex128;  slog::Index** $sup59985x43x0x0x0index129;  slog::Index** ol_takeindex130;  slog::Index** ol_takeindex131;  slog::Index** ol_take_ansindex132;  slog::Index** ol_takedelta133;  slog::Index** ol_takedelta134;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2mRb790");
      head_rel[1] = db->getRelation("ccons");
      outer_rel = db->getRelation("ccons");
      std::vector<u16> ord136({1, 2, 0});
      slog::Relation* readrel137 = db->getRelation("ol_take");
      ol_takeindex127 = readrel137->getIndex(ord136, false);
      std::vector<u16> ord138({1, 2, 0});
      slog::Relation* readrel139 = db->getRelation("ol_take");
      ol_takeindex128 = readrel139->getIndex(ord138, false);
      std::vector<u16> ord140({3, 2, 0, 1});
      slog::Relation* readrel141 = db->getRelation("$sup59985x43x0x0x0");
      $sup59985x43x0x0x0index129 = readrel141->getIndex(ord140, false);
      std::vector<u16> ord142({0, 2, 1});
      slog::Relation* readrel143 = db->getRelation("ol_take");
      ol_takeindex130 = readrel143->getIndex(ord142, false);
      std::vector<u16> ord144({0, 2, 1});
      slog::Relation* readrel145 = db->getRelation("ol_take");
      ol_takedelta133 = readrel145->getIndex(ord144, true);
      std::vector<u16> ord146({1, 2, 0});
      slog::Relation* readrel147 = db->getRelation("ol_take");
      ol_takeindex131 = readrel147->getIndex(ord146, false);
      std::vector<u16> ord148({1, 2, 0});
      slog::Relation* readrel149 = db->getRelation("ol_take");
      ol_takedelta134 = readrel149->getIndex(ord148, true);
      std::vector<u16> ord150({0, 1});
      slog::Relation* readrel151 = db->getRelation("ol_take_ans");
      ol_take_ansindex132 = readrel151->getIndex(ord150, false);
  
    }
    ReadTask135(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c34 = v_const5feceb66ffc86f38d952786c;
      u64 v_c35 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c36 = _t[0];
        u64 v_c5 = _t[1];
        u64 v_c11 = _t[2];
        if (!slog::exists_probe<3,1>(ol_takeindex127, std::array<u64,3>{v_c36, 0, 0})) return;
        if (!slog::exists_probe<3,1>(ol_takeindex128, std::array<u64,3>{v_c11, 0, 0})) return;
        slog::join_probe<4,2>($sup59985x43x0x0x0index129, std::array<u64,4>{v_c11, v_c5, 0, 0}, [&](const std::array<u64,4>& m152) {
          u64 v_c26 = m152[2]; u64 v_c37 = m152[3];
          u64 v_c38 = _prim_lt(db, v_c34, v_c37);
          if (v_c38 == slog_error) { slog::emit_pending_error(db, "list-cons.slog:44"); return; }
          if (!v_c38) return;
          slog::join_probe_old<3,3>(ol_takeindex130, ol_takedelta133, std::array<u64,3>{v_c26, v_c37, v_c36}, [&](const std::array<u64,3>& m154) {
            u64 v_c39 = _prim__0002d(db, v_c37, v_c35);
            if (v_c39 == slog_error) { slog::emit_pending_error(db, "list-cons.slog:44"); return; }
            slog::join_probe_old<3,2>(ol_takeindex131, ol_takedelta134, std::array<u64,3>{v_c11, v_c39, 0}, [&](const std::array<u64,3>& m155) {
              u64 v_c40 = m155[2];
              slog::join_probe<2,1>(ol_take_ansindex132, std::array<u64,2>{v_c40, 0}, [&](const std::array<u64,2>& m156) {
                u64 v_c14 = m156[1];
                ++_fires;
                slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c26, v_c14, v_c5});
                slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c14, v_c5}, std::array<u16,3>{2, 1, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("list-cons.slog:44", "delta:ccons", _fires);
  
      if (!_done)
      {
        ReadTask135* _cont = new ReadTask135(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask135(db,b), false);
  // (crule (pre) (scan ol_fromlst_ans __t1qQi104 cb) (body (join-old ol_fromlst (0 1) 1 (0 1) __t1qQi104 b) (exists $sup76318x27x0x0x0 (1 0 2 3) 1 b) (join lst_append (2 0 1) 1 b __t5oTD102 a) (exists lst_append_ans (0 1) 1 __t5oTD102) (exists ol_fromlst (1 0) 1 a) (join $sup76318x27x0x0x0 (0 1 2 3) 2 a b i j) (join lst_append_ans (0 1) 1 __t5oTD102 r) (join-old ol_fromlst (1 0) 1 (1 0) a __t5TS9103) (join ol_fromlst_ans (0 1) 1 __t5TS9103 ca)) (head (mkstruct ol_append (1 2 0) __5fbv387 ca cb)) seq_oracle.slog:28 #f)
  class ReadTask168 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ol_fromlstindex157;  slog::Index** $sup76318x27x0x0x0index158;  slog::Index** lst_appendindex159;  slog::Index** lst_append_ansindex160;  slog::Index** ol_fromlstindex161;  slog::Index** $sup76318x27x0x0x0index162;  slog::Index** lst_append_ansindex163;  slog::Index** ol_fromlstindex164;  slog::Index** ol_fromlst_ansindex165;  slog::Index** ol_fromlstdelta166;  slog::Index** ol_fromlstdelta167;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ol_append");
      outer_rel = db->getRelation("ol_fromlst_ans");
      std::vector<u16> ord169({0, 1});
      slog::Relation* readrel170 = db->getRelation("ol_fromlst");
      ol_fromlstindex157 = readrel170->getIndex(ord169, false);
      std::vector<u16> ord171({0, 1});
      slog::Relation* readrel172 = db->getRelation("ol_fromlst");
      ol_fromlstdelta166 = readrel172->getIndex(ord171, true);
      std::vector<u16> ord173({1, 0, 2, 3});
      slog::Relation* readrel174 = db->getRelation("$sup76318x27x0x0x0");
      $sup76318x27x0x0x0index158 = readrel174->getIndex(ord173, false);
      std::vector<u16> ord175({2, 0, 1});
      slog::Relation* readrel176 = db->getRelation("lst_append");
      lst_appendindex159 = readrel176->getIndex(ord175, false);
      std::vector<u16> ord177({0, 1});
      slog::Relation* readrel178 = db->getRelation("lst_append_ans");
      lst_append_ansindex160 = readrel178->getIndex(ord177, false);
      std::vector<u16> ord179({1, 0});
      slog::Relation* readrel180 = db->getRelation("ol_fromlst");
      ol_fromlstindex161 = readrel180->getIndex(ord179, false);
      std::vector<u16> ord181({0, 1, 2, 3});
      slog::Relation* readrel182 = db->getRelation("$sup76318x27x0x0x0");
      $sup76318x27x0x0x0index162 = readrel182->getIndex(ord181, false);
      std::vector<u16> ord183({0, 1});
      slog::Relation* readrel184 = db->getRelation("lst_append_ans");
      lst_append_ansindex163 = readrel184->getIndex(ord183, false);
      std::vector<u16> ord185({1, 0});
      slog::Relation* readrel186 = db->getRelation("ol_fromlst");
      ol_fromlstindex164 = readrel186->getIndex(ord185, false);
      std::vector<u16> ord187({1, 0});
      slog::Relation* readrel188 = db->getRelation("ol_fromlst");
      ol_fromlstdelta167 = readrel188->getIndex(ord187, true);
      std::vector<u16> ord189({0, 1});
      slog::Relation* readrel190 = db->getRelation("ol_fromlst_ans");
      ol_fromlst_ansindex165 = readrel190->getIndex(ord189, false);
  
    }
    ReadTask168(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe_old<2,1>(ol_fromlstindex157, ol_fromlstdelta166, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m191) {
          u64 v_c17 = m191[1];
          if (!slog::exists_probe<4,1>($sup76318x27x0x0x0index158, std::array<u64,4>{v_c17, 0, 0, 0})) return;
          slog::join_probe<3,1>(lst_appendindex159, std::array<u64,3>{v_c17, 0, 0}, [&](const std::array<u64,3>& m192) {
            u64 v_c19 = m192[1]; u64 v_c20 = m192[2];
            if (!slog::exists_probe<2,1>(lst_append_ansindex160, std::array<u64,2>{v_c19, 0})) return;
            if (!slog::exists_probe<2,1>(ol_fromlstindex161, std::array<u64,2>{v_c20, 0})) return;
            slog::join_probe<4,2>($sup76318x27x0x0x0index162, std::array<u64,4>{v_c20, v_c17, 0, 0}, [&](const std::array<u64,4>& m193) {
              u64 v_c21 = m193[2]; u64 v_c22 = m193[3];
              slog::join_probe<2,1>(lst_append_ansindex163, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m194) {
                u64 v_c23 = m194[1];
                slog::join_probe_old<2,1>(ol_fromlstindex164, ol_fromlstdelta167, std::array<u64,2>{v_c20, 0}, [&](const std::array<u64,2>& m195) {
                  u64 v_c24 = m195[1];
                  slog::join_probe<2,1>(ol_fromlst_ansindex165, std::array<u64,2>{v_c24, 0}, [&](const std::array<u64,2>& m196) {
                    u64 v_c25 = m196[1];
                    ++_fires;
                    slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c25, v_c18}, std::array<u16,3>{1, 2, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:28", "delta:ol_fromlst_ans", _fires);
  
      if (!_done)
      {
        ReadTask168* _cont = new ReadTask168(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask168(db,b), false);
  // (crule (pre (let __tconst5CoZ46 const5feceb66ffc86f38d952786c) (let __tconst91dC47 const6b86b273ff34fce19d6b804e)) (scan ol_take __t1IJu45 __t30ob44 n) (body (cmp lt __tconst5CoZ46 n) (join $sup59985x43x0x0x0 (0 1 2 3) 2 __t1IJu45 n x xs) (join ccons (2 1 0) 3 xs x __t30ob44) (let __t2oh148 (_0002d n __tconst91dC47)) (join-old ol_take (1 2 0) 2 (1 2 0) xs __t2oh148 __t8pjA49) (join ol_take_ans (0 1) 1 __t8pjA49 __v0)) (head (emit-temp temp2mRb790 __t1IJu45 __v0 x) (mkstruct ccons (2 1 0) __t0pq643 __v0 x)) list-cons.slog:44 #f)
  class ReadTask202 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup59985x43x0x0x0index197;  slog::Index** cconsindex198;  slog::Index** ol_takeindex199;  slog::Index** ol_take_ansindex200;  slog::Index** ol_takedelta201;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2mRb790");
      head_rel[1] = db->getRelation("ccons");
      outer_rel = db->getRelation("ol_take");
      std::vector<u16> ord203({0, 1, 2, 3});
      slog::Relation* readrel204 = db->getRelation("$sup59985x43x0x0x0");
      $sup59985x43x0x0x0index197 = readrel204->getIndex(ord203, false);
      std::vector<u16> ord205({2, 1, 0});
      slog::Relation* readrel206 = db->getRelation("ccons");
      cconsindex198 = readrel206->getIndex(ord205, false);
      std::vector<u16> ord207({1, 2, 0});
      slog::Relation* readrel208 = db->getRelation("ol_take");
      ol_takeindex199 = readrel208->getIndex(ord207, false);
      std::vector<u16> ord209({1, 2, 0});
      slog::Relation* readrel210 = db->getRelation("ol_take");
      ol_takedelta201 = readrel210->getIndex(ord209, true);
      std::vector<u16> ord211({0, 1});
      slog::Relation* readrel212 = db->getRelation("ol_take_ans");
      ol_take_ansindex200 = readrel212->getIndex(ord211, false);
  
    }
    ReadTask202(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c34 = v_const5feceb66ffc86f38d952786c;
      u64 v_c35 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c26 = _t[0];
        u64 v_c36 = _t[1];
        u64 v_c37 = _t[2];
        u64 v_c41 = _prim_lt(db, v_c34, v_c37);
        if (v_c41 == slog_error) { slog::emit_pending_error(db, "list-cons.slog:44"); return; }
        if (!v_c41) return;
        slog::join_probe<4,2>($sup59985x43x0x0x0index197, std::array<u64,4>{v_c26, v_c37, 0, 0}, [&](const std::array<u64,4>& m214) {
          u64 v_c5 = m214[2]; u64 v_c11 = m214[3];
          slog::join_probe<3,3>(cconsindex198, std::array<u64,3>{v_c11, v_c5, v_c36}, [&](const std::array<u64,3>& m215) {
            u64 v_c39 = _prim__0002d(db, v_c37, v_c35);
            if (v_c39 == slog_error) { slog::emit_pending_error(db, "list-cons.slog:44"); return; }
            slog::join_probe_old<3,2>(ol_takeindex199, ol_takedelta201, std::array<u64,3>{v_c11, v_c39, 0}, [&](const std::array<u64,3>& m216) {
              u64 v_c40 = m216[2];
              slog::join_probe<2,1>(ol_take_ansindex200, std::array<u64,2>{v_c40, 0}, [&](const std::array<u64,2>& m217) {
                u64 v_c14 = m217[1];
                ++_fires;
                slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c26, v_c14, v_c5});
                slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c14, v_c5}, std::array<u16,3>{2, 1, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("list-cons.slog:44", "delta:ol_take", _fires);
  
      if (!_done)
      {
        ReadTask202* _cont = new ReadTask202(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask202(db,b), false);
  // (crule (pre (let _00024sqc043G284 const6b86b273ff34fce19d6b804e) (let _00024sqc0Ftc285 const5feceb66ffc86f38d952786c) (let _00024sqc4Arr286 const6b86b273ff34fce19d6b804e) (let _00024sqc1a9l287 const5feceb66ffc86f38d952786c) (let _00024sqo2g9r292 const5feceb66ffc86f38d952786c)) (scan ol_fromlst_ans __t9Mc169 __v0) (body (exists $seq_at (1 0 2) 1 _00024sqo2g9r292) (join-old ol_fromlst (0 1) 1 (0 1) __t9Mc169 xs) (exists $sup59985x12x0x0x0 (3 0 2 1) 1 xs) (join-old $seq_at (1 0 2) 1 (1 0 2) _00024sqo2g9r292 x _00024seq0) (exists ol_fromlst (1 0) 1 _00024seq0) (join-old $sup59985x12x0x0x0 (3 0 2 1) 3 (3 0 2 1) xs _00024seq0 x __t0Thi68) (join-old ol_fromlst (0 1) 2 (0 1) __t0Thi68 _00024seq0) (letp _00024sql34b9282 (aslst _00024seq0)) (let _00024sqn2tQo283 (llen _00024sql34b9282)) (cmp ge _00024sqn2tQo283 _00024sqc043G284) (letp chk2ZLu779 (lref _00024sql34b9282 _00024sqc0Ftc285)) (eq x chk2ZLu779) (let _00024sqp8Anj288 (_0002d _00024sqn2tQo283 _00024sqc1a9l287)) (let chk6q91780 (lslice _00024sql34b9282 _00024sqc4Arr286 _00024sqp8Anj288)) (eq xs chk6q91780)) (head (emit-temp temp3vIA778 __t0Thi68 __v0 x) (mkstruct ccons (2 1 0) __t3yQa67 __v0 x)) list-cons.slog:13 #f)
  class ReadTask229 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $seq_atindex218;  slog::Index** ol_fromlstindex219;  slog::Index** $sup59985x12x0x0x0index220;  slog::Index** $seq_atindex221;  slog::Index** ol_fromlstindex222;  slog::Index** $sup59985x12x0x0x0index223;  slog::Index** ol_fromlstindex224;  slog::Index** ol_fromlstdelta225;  slog::Index** $seq_atdelta226;  slog::Index** $sup59985x12x0x0x0delta227;  slog::Index** ol_fromlstdelta228;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3vIA778");
      head_rel[1] = db->getRelation("ccons");
      outer_rel = db->getRelation("ol_fromlst_ans");
      std::vector<u16> ord230({1, 0, 2});
      slog::Relation* readrel231 = db->getRelation("$seq_at");
      $seq_atindex218 = readrel231->getIndex(ord230, false);
      std::vector<u16> ord232({0, 1});
      slog::Relation* readrel233 = db->getRelation("ol_fromlst");
      ol_fromlstindex219 = readrel233->getIndex(ord232, false);
      std::vector<u16> ord234({0, 1});
      slog::Relation* readrel235 = db->getRelation("ol_fromlst");
      ol_fromlstdelta225 = readrel235->getIndex(ord234, true);
      std::vector<u16> ord236({3, 0, 2, 1});
      slog::Relation* readrel237 = db->getRelation("$sup59985x12x0x0x0");
      $sup59985x12x0x0x0index220 = readrel237->getIndex(ord236, false);
      std::vector<u16> ord238({1, 0, 2});
      slog::Relation* readrel239 = db->getRelation("$seq_at");
      $seq_atindex221 = readrel239->getIndex(ord238, false);
      std::vector<u16> ord240({1, 0, 2});
      slog::Relation* readrel241 = db->getRelation("$seq_at");
      $seq_atdelta226 = readrel241->getIndex(ord240, true);
      std::vector<u16> ord242({1, 0});
      slog::Relation* readrel243 = db->getRelation("ol_fromlst");
      ol_fromlstindex222 = readrel243->getIndex(ord242, false);
      std::vector<u16> ord244({3, 0, 2, 1});
      slog::Relation* readrel245 = db->getRelation("$sup59985x12x0x0x0");
      $sup59985x12x0x0x0index223 = readrel245->getIndex(ord244, false);
      std::vector<u16> ord246({3, 0, 2, 1});
      slog::Relation* readrel247 = db->getRelation("$sup59985x12x0x0x0");
      $sup59985x12x0x0x0delta227 = readrel247->getIndex(ord246, true);
      std::vector<u16> ord248({0, 1});
      slog::Relation* readrel249 = db->getRelation("ol_fromlst");
      ol_fromlstindex224 = readrel249->getIndex(ord248, false);
      std::vector<u16> ord250({0, 1});
      slog::Relation* readrel251 = db->getRelation("ol_fromlst");
      ol_fromlstdelta228 = readrel251->getIndex(ord250, true);
  
    }
    ReadTask229(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c1 = v_const5feceb66ffc86f38d952786c;
      u64 v_c2 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c3 = v_const5feceb66ffc86f38d952786c;
      u64 v_c4 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c13 = _t[0];
        u64 v_c14 = _t[1];
        if (!slog::exists_probe<3,1>($seq_atindex218, std::array<u64,3>{v_c4, 0, 0})) return;
        slog::join_probe_old<2,1>(ol_fromlstindex219, ol_fromlstdelta225, std::array<u64,2>{v_c13, 0}, [&](const std::array<u64,2>& m252) {
          u64 v_c11 = m252[1];
          if (!slog::exists_probe<4,1>($sup59985x12x0x0x0index220, std::array<u64,4>{v_c11, 0, 0, 0})) return;
          slog::join_probe_old<3,1>($seq_atindex221, $seq_atdelta226, std::array<u64,3>{v_c4, 0, 0}, [&](const std::array<u64,3>& m253) {
            u64 v_c5 = m253[1]; u64 v_c6 = m253[2];
            if (!slog::exists_probe<2,1>(ol_fromlstindex222, std::array<u64,2>{v_c6, 0})) return;
            slog::join_probe_old<4,3>($sup59985x12x0x0x0index223, $sup59985x12x0x0x0delta227, std::array<u64,4>{v_c11, v_c6, v_c5, 0}, [&](const std::array<u64,4>& m254) {
              u64 v_c12 = m254[3];
              slog::join_probe_old<2,2>(ol_fromlstindex224, ol_fromlstdelta228, std::array<u64,2>{v_c12, v_c6}, [&](const std::array<u64,2>& m255) {
                bool ok256 = true;
                u64 v_c7 = _prim_aslst(db, v_c6, &ok256);
                if (!ok256) return;
                u64 v_c8 = _prim_llen(db, v_c7);
                if (v_c8 == slog_error) { slog::emit_pending_error(db, "list-cons.slog:13"); return; }
                u64 v_c42 = _prim_ge(db, v_c8, v_c0);
                if (v_c42 == slog_error) { slog::emit_pending_error(db, "list-cons.slog:13"); return; }
                if (!v_c42) return;
                bool ok258 = true;
                u64 v_c43 = _prim_lref(db, v_c7, v_c1, &ok258);
                if (!ok258) return;
                if (v_c5 != v_c43) return;
                u64 v_c10 = _prim__0002d(db, v_c8, v_c3);
                if (v_c10 == slog_error) { slog::emit_pending_error(db, "list-cons.slog:13"); return; }
                u64 v_c44 = _prim_lslice(db, v_c7, v_c2, v_c10);
                if (v_c44 == slog_error) { slog::emit_pending_error(db, "list-cons.slog:13"); return; }
                if (v_c11 != v_c44) return;
                ++_fires;
                slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c12, v_c14, v_c5});
                slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c14, v_c5}, std::array<u16,3>{2, 1, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("list-cons.slog:13", "delta:ol_fromlst_ans", _fires);
  
      if (!_done)
      {
        ReadTask229* _cont = new ReadTask229(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask229(db,b), false);
  // (crule (pre) (scan $sup59985x22x0x0x0 __t3t1M97 r x xs) (body (exists ol_append (0 2 1) 2 __t3t1M97 r) (exists ol_append (1 2 0) 2 xs r) (join-old ccons (2 1 0) 2 (2 1 0) xs x __t6cAF96) (join-old ol_append (0 2 1) 3 (0 2 1) __t3t1M97 r __t6cAF96) (join-old ol_append (1 2 0) 2 (1 2 0) xs r __t4evy98) (join ol_append_ans (0 1) 1 __t4evy98 z)) (head (emit-temp temp9VKb789 __t3t1M97 x z) (mkstruct ccons (2 1 0) __t7O1j95 z x)) list-cons.slog:23 #f)
  class ReadTask268 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ol_appendindex259;  slog::Index** ol_appendindex260;  slog::Index** cconsindex261;  slog::Index** ol_appendindex262;  slog::Index** ol_appendindex263;  slog::Index** ol_append_ansindex264;  slog::Index** cconsdelta265;  slog::Index** ol_appenddelta266;  slog::Index** ol_appenddelta267;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9VKb789");
      head_rel[1] = db->getRelation("ccons");
      outer_rel = db->getRelation("$sup59985x22x0x0x0");
      std::vector<u16> ord269({0, 2, 1});
      slog::Relation* readrel270 = db->getRelation("ol_append");
      ol_appendindex259 = readrel270->getIndex(ord269, false);
      std::vector<u16> ord271({1, 2, 0});
      slog::Relation* readrel272 = db->getRelation("ol_append");
      ol_appendindex260 = readrel272->getIndex(ord271, false);
      std::vector<u16> ord273({2, 1, 0});
      slog::Relation* readrel274 = db->getRelation("ccons");
      cconsindex261 = readrel274->getIndex(ord273, false);
      std::vector<u16> ord275({2, 1, 0});
      slog::Relation* readrel276 = db->getRelation("ccons");
      cconsdelta265 = readrel276->getIndex(ord275, true);
      std::vector<u16> ord277({0, 2, 1});
      slog::Relation* readrel278 = db->getRelation("ol_append");
      ol_appendindex262 = readrel278->getIndex(ord277, false);
      std::vector<u16> ord279({0, 2, 1});
      slog::Relation* readrel280 = db->getRelation("ol_append");
      ol_appenddelta266 = readrel280->getIndex(ord279, true);
      std::vector<u16> ord281({1, 2, 0});
      slog::Relation* readrel282 = db->getRelation("ol_append");
      ol_appendindex263 = readrel282->getIndex(ord281, false);
      std::vector<u16> ord283({1, 2, 0});
      slog::Relation* readrel284 = db->getRelation("ol_append");
      ol_appenddelta267 = readrel284->getIndex(ord283, true);
      std::vector<u16> ord285({0, 1});
      slog::Relation* readrel286 = db->getRelation("ol_append_ans");
      ol_append_ansindex264 = readrel286->getIndex(ord285, false);
  
    }
    ReadTask268(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c23 = _t[1];
        u64 v_c5 = _t[2];
        u64 v_c11 = _t[3];
        if (!slog::exists_probe<3,2>(ol_appendindex259, std::array<u64,3>{v_c45, v_c23, 0})) return;
        if (!slog::exists_probe<3,2>(ol_appendindex260, std::array<u64,3>{v_c11, v_c23, 0})) return;
        slog::join_probe_old<3,2>(cconsindex261, cconsdelta265, std::array<u64,3>{v_c11, v_c5, 0}, [&](const std::array<u64,3>& m287) {
          u64 v_c46 = m287[2];
          slog::join_probe_old<3,3>(ol_appendindex262, ol_appenddelta266, std::array<u64,3>{v_c45, v_c23, v_c46}, [&](const std::array<u64,3>& m288) {
            slog::join_probe_old<3,2>(ol_appendindex263, ol_appenddelta267, std::array<u64,3>{v_c11, v_c23, 0}, [&](const std::array<u64,3>& m289) {
              u64 v_c47 = m289[2];
              slog::join_probe<2,1>(ol_append_ansindex264, std::array<u64,2>{v_c47, 0}, [&](const std::array<u64,2>& m290) {
                u64 v_c48 = m290[1];
                ++_fires;
                slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c45, v_c5, v_c48});
                slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c48, v_c5}, std::array<u16,3>{2, 1, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("list-cons.slog:23", "delta:$sup59985x22x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask268* _cont = new ReadTask268(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask268(db,b), false);
  // (crule (pre) (scan ccons __t6cAF96 x xs) (body (exists ol_append (1 2 0) 1 __t6cAF96) (exists ol_append (1 2 0) 1 xs) (join $sup59985x22x0x0x0 (2 3 0 1) 2 x xs __t3t1M97 r) (join-old ol_append (0 2 1) 3 (0 2 1) __t3t1M97 r __t6cAF96) (join-old ol_append (1 2 0) 2 (1 2 0) xs r __t4evy98) (join ol_append_ans (0 1) 1 __t4evy98 z)) (head (emit-temp temp9VKb789 __t3t1M97 x z) (mkstruct ccons (2 1 0) __t7O1j95 z x)) list-cons.slog:23 #f)
  class ReadTask299 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ol_appendindex291;  slog::Index** ol_appendindex292;  slog::Index** $sup59985x22x0x0x0index293;  slog::Index** ol_appendindex294;  slog::Index** ol_appendindex295;  slog::Index** ol_append_ansindex296;  slog::Index** ol_appenddelta297;  slog::Index** ol_appenddelta298;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9VKb789");
      head_rel[1] = db->getRelation("ccons");
      outer_rel = db->getRelation("ccons");
      std::vector<u16> ord300({1, 2, 0});
      slog::Relation* readrel301 = db->getRelation("ol_append");
      ol_appendindex291 = readrel301->getIndex(ord300, false);
      std::vector<u16> ord302({1, 2, 0});
      slog::Relation* readrel303 = db->getRelation("ol_append");
      ol_appendindex292 = readrel303->getIndex(ord302, false);
      std::vector<u16> ord304({2, 3, 0, 1});
      slog::Relation* readrel305 = db->getRelation("$sup59985x22x0x0x0");
      $sup59985x22x0x0x0index293 = readrel305->getIndex(ord304, false);
      std::vector<u16> ord306({0, 2, 1});
      slog::Relation* readrel307 = db->getRelation("ol_append");
      ol_appendindex294 = readrel307->getIndex(ord306, false);
      std::vector<u16> ord308({0, 2, 1});
      slog::Relation* readrel309 = db->getRelation("ol_append");
      ol_appenddelta297 = readrel309->getIndex(ord308, true);
      std::vector<u16> ord310({1, 2, 0});
      slog::Relation* readrel311 = db->getRelation("ol_append");
      ol_appendindex295 = readrel311->getIndex(ord310, false);
      std::vector<u16> ord312({1, 2, 0});
      slog::Relation* readrel313 = db->getRelation("ol_append");
      ol_appenddelta298 = readrel313->getIndex(ord312, true);
      std::vector<u16> ord314({0, 1});
      slog::Relation* readrel315 = db->getRelation("ol_append_ans");
      ol_append_ansindex296 = readrel315->getIndex(ord314, false);
  
    }
    ReadTask299(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c5 = _t[1];
        u64 v_c11 = _t[2];
        if (!slog::exists_probe<3,1>(ol_appendindex291, std::array<u64,3>{v_c46, 0, 0})) return;
        if (!slog::exists_probe<3,1>(ol_appendindex292, std::array<u64,3>{v_c11, 0, 0})) return;
        slog::join_probe<4,2>($sup59985x22x0x0x0index293, std::array<u64,4>{v_c5, v_c11, 0, 0}, [&](const std::array<u64,4>& m316) {
          u64 v_c45 = m316[2]; u64 v_c23 = m316[3];
          slog::join_probe_old<3,3>(ol_appendindex294, ol_appenddelta297, std::array<u64,3>{v_c45, v_c23, v_c46}, [&](const std::array<u64,3>& m317) {
            slog::join_probe_old<3,2>(ol_appendindex295, ol_appenddelta298, std::array<u64,3>{v_c11, v_c23, 0}, [&](const std::array<u64,3>& m318) {
              u64 v_c47 = m318[2];
              slog::join_probe<2,1>(ol_append_ansindex296, std::array<u64,2>{v_c47, 0}, [&](const std::array<u64,2>& m319) {
                u64 v_c48 = m319[1];
                ++_fires;
                slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c45, v_c5, v_c48});
                slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c48, v_c5}, std::array<u16,3>{2, 1, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("list-cons.slog:23", "delta:ccons", _fires);
  
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
  // (crule (pre (let __tconst6hdJ420 const9ac63e4426dab2edcc97bcf7)) (scan ol_rev __t4fr4263 l) (body (join _enum (1 0) 1 __tconst6hdJ420 __t8fx9262)) (head (mkstruct ol_rev_acc (1 2 0) __3EKr419 l __t8fx9262)) list-cons.slog:56 #f)
  class ReadTask321 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex320;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ol_rev_acc");
      outer_rel = db->getRelation("ol_rev");
      std::vector<u16> ord322({1, 0});
      slog::Relation* readrel323 = db->getRelation("_enum");
      _enumindex320 = readrel323->getIndex(ord322, false);
  
    }
    ReadTask321(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c49 = v_const9ac63e4426dab2edcc97bcf7;
  
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
        slog::join_probe<2,1>(_enumindex320, std::array<u64,2>{v_c49, 0}, [&](const std::array<u64,2>& m324) {
          u64 v_c52 = m324[1];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c51, v_c52}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("list-cons.slog:56", "delta:ol_rev", _fires);
  
      if (!_done)
      {
        ReadTask321* _cont = new ReadTask321(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask321(db,b), false);
  // (crule (pre) (scan ol_fromlst_ans __t4wzo101 cb) (body (join-old ol_fromlst (0 1) 1 (0 1) __t4wzo101 b) (exists $sup76318x27x0x0x0 (1 0 2 3) 1 b) (join lst_append (2 0 1) 1 b __t2Gaw99 a) (exists lst_append_ans (0 1) 1 __t2Gaw99) (exists ol_fromlst (1 0) 1 a) (join $sup76318x27x0x0x0 (0 1 2 3) 2 a b i j) (join lst_append_ans (0 1) 1 __t2Gaw99 r) (join-old ol_fromlst (1 0) 1 (1 0) a __t1dzp100) (join ol_fromlst_ans (0 1) 1 __t1dzp100 ca)) (head (mkstruct ol_fromlst (1 0) __3XFq393 r)) seq_oracle.slog:28 #f)
  class ReadTask336 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ol_fromlstindex325;  slog::Index** $sup76318x27x0x0x0index326;  slog::Index** lst_appendindex327;  slog::Index** lst_append_ansindex328;  slog::Index** ol_fromlstindex329;  slog::Index** $sup76318x27x0x0x0index330;  slog::Index** lst_append_ansindex331;  slog::Index** ol_fromlstindex332;  slog::Index** ol_fromlst_ansindex333;  slog::Index** ol_fromlstdelta334;  slog::Index** ol_fromlstdelta335;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ol_fromlst");
      outer_rel = db->getRelation("ol_fromlst_ans");
      std::vector<u16> ord337({0, 1});
      slog::Relation* readrel338 = db->getRelation("ol_fromlst");
      ol_fromlstindex325 = readrel338->getIndex(ord337, false);
      std::vector<u16> ord339({0, 1});
      slog::Relation* readrel340 = db->getRelation("ol_fromlst");
      ol_fromlstdelta334 = readrel340->getIndex(ord339, true);
      std::vector<u16> ord341({1, 0, 2, 3});
      slog::Relation* readrel342 = db->getRelation("$sup76318x27x0x0x0");
      $sup76318x27x0x0x0index326 = readrel342->getIndex(ord341, false);
      std::vector<u16> ord343({2, 0, 1});
      slog::Relation* readrel344 = db->getRelation("lst_append");
      lst_appendindex327 = readrel344->getIndex(ord343, false);
      std::vector<u16> ord345({0, 1});
      slog::Relation* readrel346 = db->getRelation("lst_append_ans");
      lst_append_ansindex328 = readrel346->getIndex(ord345, false);
      std::vector<u16> ord347({1, 0});
      slog::Relation* readrel348 = db->getRelation("ol_fromlst");
      ol_fromlstindex329 = readrel348->getIndex(ord347, false);
      std::vector<u16> ord349({0, 1, 2, 3});
      slog::Relation* readrel350 = db->getRelation("$sup76318x27x0x0x0");
      $sup76318x27x0x0x0index330 = readrel350->getIndex(ord349, false);
      std::vector<u16> ord351({0, 1});
      slog::Relation* readrel352 = db->getRelation("lst_append_ans");
      lst_append_ansindex331 = readrel352->getIndex(ord351, false);
      std::vector<u16> ord353({1, 0});
      slog::Relation* readrel354 = db->getRelation("ol_fromlst");
      ol_fromlstindex332 = readrel354->getIndex(ord353, false);
      std::vector<u16> ord355({1, 0});
      slog::Relation* readrel356 = db->getRelation("ol_fromlst");
      ol_fromlstdelta335 = readrel356->getIndex(ord355, true);
      std::vector<u16> ord357({0, 1});
      slog::Relation* readrel358 = db->getRelation("ol_fromlst_ans");
      ol_fromlst_ansindex333 = readrel358->getIndex(ord357, false);
  
    }
    ReadTask336(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c18 = _t[1];
        slog::join_probe_old<2,1>(ol_fromlstindex325, ol_fromlstdelta334, std::array<u64,2>{v_c53, 0}, [&](const std::array<u64,2>& m359) {
          u64 v_c17 = m359[1];
          if (!slog::exists_probe<4,1>($sup76318x27x0x0x0index326, std::array<u64,4>{v_c17, 0, 0, 0})) return;
          slog::join_probe<3,1>(lst_appendindex327, std::array<u64,3>{v_c17, 0, 0}, [&](const std::array<u64,3>& m360) {
            u64 v_c54 = m360[1]; u64 v_c20 = m360[2];
            if (!slog::exists_probe<2,1>(lst_append_ansindex328, std::array<u64,2>{v_c54, 0})) return;
            if (!slog::exists_probe<2,1>(ol_fromlstindex329, std::array<u64,2>{v_c20, 0})) return;
            slog::join_probe<4,2>($sup76318x27x0x0x0index330, std::array<u64,4>{v_c20, v_c17, 0, 0}, [&](const std::array<u64,4>& m361) {
              u64 v_c21 = m361[2]; u64 v_c22 = m361[3];
              slog::join_probe<2,1>(lst_append_ansindex331, std::array<u64,2>{v_c54, 0}, [&](const std::array<u64,2>& m362) {
                u64 v_c23 = m362[1];
                slog::join_probe_old<2,1>(ol_fromlstindex332, ol_fromlstdelta335, std::array<u64,2>{v_c20, 0}, [&](const std::array<u64,2>& m363) {
                  u64 v_c55 = m363[1];
                  slog::join_probe<2,1>(ol_fromlst_ansindex333, std::array<u64,2>{v_c55, 0}, [&](const std::array<u64,2>& m364) {
                    u64 v_c25 = m364[1];
                    ++_fires;
                    slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c23}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:28", "delta:ol_fromlst_ans", _fires);
  
      if (!_done)
      {
        ReadTask336* _cont = new ReadTask336(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask336(db,b), false);
  // (crule (pre) (scan ol_fromlst_ans __t1dzp100 ca) (body (join-old ol_fromlst (0 1) 1 (0 1) __t1dzp100 a) (exists $sup76318x27x0x0x0 (0 1 2 3) 1 a) (join lst_append (1 2 0) 1 a b __t2Gaw99) (exists lst_append_ans (0 1) 1 __t2Gaw99) (exists ol_fromlst (1 0) 1 b) (join $sup76318x27x0x0x0 (0 1 2 3) 2 a b i j) (join lst_append_ans (0 1) 1 __t2Gaw99 r) (join-old ol_fromlst (1 0) 1 (1 0) b __t4wzo101) (join-old ol_fromlst_ans (0 1) 1 (0 1) __t4wzo101 cb)) (head (mkstruct ol_fromlst (1 0) __3XFq393 r)) seq_oracle.slog:28 #f)
  class ReadTask377 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ol_fromlstindex365;  slog::Index** $sup76318x27x0x0x0index366;  slog::Index** lst_appendindex367;  slog::Index** lst_append_ansindex368;  slog::Index** ol_fromlstindex369;  slog::Index** $sup76318x27x0x0x0index370;  slog::Index** lst_append_ansindex371;  slog::Index** ol_fromlstindex372;  slog::Index** ol_fromlst_ansindex373;  slog::Index** ol_fromlstdelta374;  slog::Index** ol_fromlstdelta375;  slog::Index** ol_fromlst_ansdelta376;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ol_fromlst");
      outer_rel = db->getRelation("ol_fromlst_ans");
      std::vector<u16> ord378({0, 1});
      slog::Relation* readrel379 = db->getRelation("ol_fromlst");
      ol_fromlstindex365 = readrel379->getIndex(ord378, false);
      std::vector<u16> ord380({0, 1});
      slog::Relation* readrel381 = db->getRelation("ol_fromlst");
      ol_fromlstdelta374 = readrel381->getIndex(ord380, true);
      std::vector<u16> ord382({0, 1, 2, 3});
      slog::Relation* readrel383 = db->getRelation("$sup76318x27x0x0x0");
      $sup76318x27x0x0x0index366 = readrel383->getIndex(ord382, false);
      std::vector<u16> ord384({1, 2, 0});
      slog::Relation* readrel385 = db->getRelation("lst_append");
      lst_appendindex367 = readrel385->getIndex(ord384, false);
      std::vector<u16> ord386({0, 1});
      slog::Relation* readrel387 = db->getRelation("lst_append_ans");
      lst_append_ansindex368 = readrel387->getIndex(ord386, false);
      std::vector<u16> ord388({1, 0});
      slog::Relation* readrel389 = db->getRelation("ol_fromlst");
      ol_fromlstindex369 = readrel389->getIndex(ord388, false);
      std::vector<u16> ord390({0, 1, 2, 3});
      slog::Relation* readrel391 = db->getRelation("$sup76318x27x0x0x0");
      $sup76318x27x0x0x0index370 = readrel391->getIndex(ord390, false);
      std::vector<u16> ord392({0, 1});
      slog::Relation* readrel393 = db->getRelation("lst_append_ans");
      lst_append_ansindex371 = readrel393->getIndex(ord392, false);
      std::vector<u16> ord394({1, 0});
      slog::Relation* readrel395 = db->getRelation("ol_fromlst");
      ol_fromlstindex372 = readrel395->getIndex(ord394, false);
      std::vector<u16> ord396({1, 0});
      slog::Relation* readrel397 = db->getRelation("ol_fromlst");
      ol_fromlstdelta375 = readrel397->getIndex(ord396, true);
      std::vector<u16> ord398({0, 1});
      slog::Relation* readrel399 = db->getRelation("ol_fromlst_ans");
      ol_fromlst_ansindex373 = readrel399->getIndex(ord398, false);
      std::vector<u16> ord400({0, 1});
      slog::Relation* readrel401 = db->getRelation("ol_fromlst_ans");
      ol_fromlst_ansdelta376 = readrel401->getIndex(ord400, true);
  
    }
    ReadTask377(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c25 = _t[1];
        slog::join_probe_old<2,1>(ol_fromlstindex365, ol_fromlstdelta374, std::array<u64,2>{v_c55, 0}, [&](const std::array<u64,2>& m402) {
          u64 v_c20 = m402[1];
          if (!slog::exists_probe<4,1>($sup76318x27x0x0x0index366, std::array<u64,4>{v_c20, 0, 0, 0})) return;
          slog::join_probe<3,1>(lst_appendindex367, std::array<u64,3>{v_c20, 0, 0}, [&](const std::array<u64,3>& m403) {
            u64 v_c17 = m403[1]; u64 v_c54 = m403[2];
            if (!slog::exists_probe<2,1>(lst_append_ansindex368, std::array<u64,2>{v_c54, 0})) return;
            if (!slog::exists_probe<2,1>(ol_fromlstindex369, std::array<u64,2>{v_c17, 0})) return;
            slog::join_probe<4,2>($sup76318x27x0x0x0index370, std::array<u64,4>{v_c20, v_c17, 0, 0}, [&](const std::array<u64,4>& m404) {
              u64 v_c21 = m404[2]; u64 v_c22 = m404[3];
              slog::join_probe<2,1>(lst_append_ansindex371, std::array<u64,2>{v_c54, 0}, [&](const std::array<u64,2>& m405) {
                u64 v_c23 = m405[1];
                slog::join_probe_old<2,1>(ol_fromlstindex372, ol_fromlstdelta375, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m406) {
                  u64 v_c53 = m406[1];
                  slog::join_probe_old<2,1>(ol_fromlst_ansindex373, ol_fromlst_ansdelta376, std::array<u64,2>{v_c53, 0}, [&](const std::array<u64,2>& m407) {
                    u64 v_c18 = m407[1];
                    ++_fires;
                    slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c23}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:28", "delta:ol_fromlst_ans", _fires);
  
      if (!_done)
      {
        ReadTask377* _cont = new ReadTask377(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask377(db,b), false);
  // (crule (pre) (scan ol_fromlst_ans __t6ptU21 c) (body (join-old ol_fromlst (0 1) 1 (0 1) __t6ptU21 l) (exists lst_take (1 2 0) 1 l) (join $sup76318x53x0x0x0 (2 0 1) 1 l i k) (join lst_take (1 2 0) 2 l k __t9s8U20) (join lst_take_ans (0 1) 1 __t9s8U20 r)) (head (mkstruct ol_take (1 2 0) __0P0b311 c k)) seq_oracle.slog:54 #f)
  class ReadTask414 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ol_fromlstindex408;  slog::Index** lst_takeindex409;  slog::Index** $sup76318x53x0x0x0index410;  slog::Index** lst_takeindex411;  slog::Index** lst_take_ansindex412;  slog::Index** ol_fromlstdelta413;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ol_take");
      outer_rel = db->getRelation("ol_fromlst_ans");
      std::vector<u16> ord415({0, 1});
      slog::Relation* readrel416 = db->getRelation("ol_fromlst");
      ol_fromlstindex408 = readrel416->getIndex(ord415, false);
      std::vector<u16> ord417({0, 1});
      slog::Relation* readrel418 = db->getRelation("ol_fromlst");
      ol_fromlstdelta413 = readrel418->getIndex(ord417, true);
      std::vector<u16> ord419({1, 2, 0});
      slog::Relation* readrel420 = db->getRelation("lst_take");
      lst_takeindex409 = readrel420->getIndex(ord419, false);
      std::vector<u16> ord421({2, 0, 1});
      slog::Relation* readrel422 = db->getRelation("$sup76318x53x0x0x0");
      $sup76318x53x0x0x0index410 = readrel422->getIndex(ord421, false);
      std::vector<u16> ord423({1, 2, 0});
      slog::Relation* readrel424 = db->getRelation("lst_take");
      lst_takeindex411 = readrel424->getIndex(ord423, false);
      std::vector<u16> ord425({0, 1});
      slog::Relation* readrel426 = db->getRelation("lst_take_ans");
      lst_take_ansindex412 = readrel426->getIndex(ord425, false);
  
    }
    ReadTask414(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c57 = _t[1];
        slog::join_probe_old<2,1>(ol_fromlstindex408, ol_fromlstdelta413, std::array<u64,2>{v_c56, 0}, [&](const std::array<u64,2>& m427) {
          u64 v_c51 = m427[1];
          if (!slog::exists_probe<3,1>(lst_takeindex409, std::array<u64,3>{v_c51, 0, 0})) return;
          slog::join_probe<3,1>($sup76318x53x0x0x0index410, std::array<u64,3>{v_c51, 0, 0}, [&](const std::array<u64,3>& m428) {
            u64 v_c21 = m428[1]; u64 v_c58 = m428[2];
            slog::join_probe<3,2>(lst_takeindex411, std::array<u64,3>{v_c51, v_c58, 0}, [&](const std::array<u64,3>& m429) {
              u64 v_c59 = m429[2];
              slog::join_probe<2,1>(lst_take_ansindex412, std::array<u64,2>{v_c59, 0}, [&](const std::array<u64,2>& m430) {
                u64 v_c23 = m430[1];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c57, v_c58}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:54", "delta:ol_fromlst_ans", _fires);
  
      if (!_done)
      {
        ReadTask414* _cont = new ReadTask414(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask414(db,b), false);
  // (crule (pre (let __trid1e1N340 constcff65e3a987ac3b552474055) (let __trel4N6n341 constde3f85f3da4637dccad01619) (let __tcol5YC8342 const5feceb66ffc86f38d952786c)) (scan $sup76318x43x0x0x0 i l y) (body) (head (tycheck l (accept seq) __trid1e1N340 __trel4N6n341 __tcol5YC8342 (1 2 3 4 0)) (mkstruct ol_fromlst (1 0) __28ew339 l)) seq_oracle.slog:44 #f)
  class ReadTask431 : public slog::Task
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
      outer_rel = db->getRelation("$sup76318x43x0x0x0");
  
    }
    ReadTask431(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c60 = v_constcff65e3a987ac3b552474055;
      u64 v_c61 = v_constde3f85f3da4637dccad01619;
      u64 v_c62 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c21 = _t[0];
        u64 v_c51 = _t[1];
        u64 v_c63 = _t[2];
        ++_fires;
        if (!(is_seq(v_c51)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c60, v_c61, v_c62, v_c51}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c51}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:44", "all:$sup76318x43x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask431* _cont = new ReadTask431(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask431(db,b), true);
  // (crule (pre) (scan ol_append __t4evy98 xs r) (body (exists ccons (2 1 0) 1 xs) (exists ol_append (2 0 1) 1 r) (exists ol_append_ans (0 1) 1 __t4evy98) (join $sup59985x22x0x0x0 (1 3 0 2) 2 r xs __t3t1M97 x) (exists ol_append (0 2 1) 2 __t3t1M97 r) (join ccons (2 1 0) 2 xs x __t6cAF96) (join ol_append (0 2 1) 3 __t3t1M97 r __t6cAF96) (join ol_append_ans (0 1) 1 __t4evy98 z)) (head (emit-temp temp9VKb789 __t3t1M97 x z) (mkstruct ccons (2 1 0) __t7O1j95 z x)) list-cons.slog:23 #f)
  class ReadTask440 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** cconsindex432;  slog::Index** ol_appendindex433;  slog::Index** ol_append_ansindex434;  slog::Index** $sup59985x22x0x0x0index435;  slog::Index** ol_appendindex436;  slog::Index** cconsindex437;  slog::Index** ol_appendindex438;  slog::Index** ol_append_ansindex439;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9VKb789");
      head_rel[1] = db->getRelation("ccons");
      outer_rel = db->getRelation("ol_append");
      std::vector<u16> ord441({2, 1, 0});
      slog::Relation* readrel442 = db->getRelation("ccons");
      cconsindex432 = readrel442->getIndex(ord441, false);
      std::vector<u16> ord443({2, 0, 1});
      slog::Relation* readrel444 = db->getRelation("ol_append");
      ol_appendindex433 = readrel444->getIndex(ord443, false);
      std::vector<u16> ord445({0, 1});
      slog::Relation* readrel446 = db->getRelation("ol_append_ans");
      ol_append_ansindex434 = readrel446->getIndex(ord445, false);
      std::vector<u16> ord447({1, 3, 0, 2});
      slog::Relation* readrel448 = db->getRelation("$sup59985x22x0x0x0");
      $sup59985x22x0x0x0index435 = readrel448->getIndex(ord447, false);
      std::vector<u16> ord449({0, 2, 1});
      slog::Relation* readrel450 = db->getRelation("ol_append");
      ol_appendindex436 = readrel450->getIndex(ord449, false);
      std::vector<u16> ord451({2, 1, 0});
      slog::Relation* readrel452 = db->getRelation("ccons");
      cconsindex437 = readrel452->getIndex(ord451, false);
      std::vector<u16> ord453({0, 2, 1});
      slog::Relation* readrel454 = db->getRelation("ol_append");
      ol_appendindex438 = readrel454->getIndex(ord453, false);
      std::vector<u16> ord455({0, 1});
      slog::Relation* readrel456 = db->getRelation("ol_append_ans");
      ol_append_ansindex439 = readrel456->getIndex(ord455, false);
  
    }
    ReadTask440(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c47 = _t[0];
        u64 v_c11 = _t[1];
        u64 v_c23 = _t[2];
        if (!slog::exists_probe<3,1>(cconsindex432, std::array<u64,3>{v_c11, 0, 0})) return;
        if (!slog::exists_probe<3,1>(ol_appendindex433, std::array<u64,3>{v_c23, 0, 0})) return;
        if (!slog::exists_probe<2,1>(ol_append_ansindex434, std::array<u64,2>{v_c47, 0})) return;
        slog::join_probe<4,2>($sup59985x22x0x0x0index435, std::array<u64,4>{v_c23, v_c11, 0, 0}, [&](const std::array<u64,4>& m457) {
          u64 v_c45 = m457[2]; u64 v_c5 = m457[3];
          if (!slog::exists_probe<3,2>(ol_appendindex436, std::array<u64,3>{v_c45, v_c23, 0})) return;
          slog::join_probe<3,2>(cconsindex437, std::array<u64,3>{v_c11, v_c5, 0}, [&](const std::array<u64,3>& m458) {
            u64 v_c46 = m458[2];
            slog::join_probe<3,3>(ol_appendindex438, std::array<u64,3>{v_c45, v_c23, v_c46}, [&](const std::array<u64,3>& m459) {
              slog::join_probe<2,1>(ol_append_ansindex439, std::array<u64,2>{v_c47, 0}, [&](const std::array<u64,2>& m460) {
                u64 v_c48 = m460[1];
                ++_fires;
                slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c45, v_c5, v_c48});
                slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c48, v_c5}, std::array<u16,3>{2, 1, 0});
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
        ReadTask440* _cont = new ReadTask440(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask440(db,b), false);
  // (crule (pre) (scan mpz_table_overflow __erre8pOA775 __errf9WYB776 __errf9Lr7777) (body) (head (emit error (0) __erre8pOA775)) <internal>:1 #f)
  class ReadTask461 : public slog::Task
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
      std::vector<u16> ord462({0});
      slog::Relation* readrel463 = db->getRelation("error");
      head_index[0] = readrel463->getIndex(ord462, false);
      outer_rel = db->getRelation("mpz_table_overflow");
  
    }
    ReadTask461(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c66 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c64}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_table_overflow", _fires);
  
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
  // (crule (pre) (scan ol_fromlst __t1dzp100 a) (body (exists lst_append (1 2 0) 1 a) (exists $sup76318x27x0x0x0 (0 1 2 3) 1 a) (join ol_fromlst_ans (0 1) 1 __t1dzp100 ca) (join lst_append (1 2 0) 1 a b __t2Gaw99) (exists lst_append_ans (0 1) 1 __t2Gaw99) (exists ol_fromlst (1 0) 1 b) (join $sup76318x27x0x0x0 (0 1 2 3) 2 a b i j) (join lst_append_ans (0 1) 1 __t2Gaw99 r) (join-old ol_fromlst (1 0) 1 (1 0) b __t4wzo101) (join ol_fromlst_ans (0 1) 1 __t4wzo101 cb)) (head (mkstruct ol_fromlst (1 0) __3XFq393 r)) seq_oracle.slog:28 #f)
  class ReadTask475 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lst_appendindex464;  slog::Index** $sup76318x27x0x0x0index465;  slog::Index** ol_fromlst_ansindex466;  slog::Index** lst_appendindex467;  slog::Index** lst_append_ansindex468;  slog::Index** ol_fromlstindex469;  slog::Index** $sup76318x27x0x0x0index470;  slog::Index** lst_append_ansindex471;  slog::Index** ol_fromlstindex472;  slog::Index** ol_fromlst_ansindex473;  slog::Index** ol_fromlstdelta474;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ol_fromlst");
      outer_rel = db->getRelation("ol_fromlst");
      std::vector<u16> ord476({1, 2, 0});
      slog::Relation* readrel477 = db->getRelation("lst_append");
      lst_appendindex464 = readrel477->getIndex(ord476, false);
      std::vector<u16> ord478({0, 1, 2, 3});
      slog::Relation* readrel479 = db->getRelation("$sup76318x27x0x0x0");
      $sup76318x27x0x0x0index465 = readrel479->getIndex(ord478, false);
      std::vector<u16> ord480({0, 1});
      slog::Relation* readrel481 = db->getRelation("ol_fromlst_ans");
      ol_fromlst_ansindex466 = readrel481->getIndex(ord480, false);
      std::vector<u16> ord482({1, 2, 0});
      slog::Relation* readrel483 = db->getRelation("lst_append");
      lst_appendindex467 = readrel483->getIndex(ord482, false);
      std::vector<u16> ord484({0, 1});
      slog::Relation* readrel485 = db->getRelation("lst_append_ans");
      lst_append_ansindex468 = readrel485->getIndex(ord484, false);
      std::vector<u16> ord486({1, 0});
      slog::Relation* readrel487 = db->getRelation("ol_fromlst");
      ol_fromlstindex469 = readrel487->getIndex(ord486, false);
      std::vector<u16> ord488({0, 1, 2, 3});
      slog::Relation* readrel489 = db->getRelation("$sup76318x27x0x0x0");
      $sup76318x27x0x0x0index470 = readrel489->getIndex(ord488, false);
      std::vector<u16> ord490({0, 1});
      slog::Relation* readrel491 = db->getRelation("lst_append_ans");
      lst_append_ansindex471 = readrel491->getIndex(ord490, false);
      std::vector<u16> ord492({1, 0});
      slog::Relation* readrel493 = db->getRelation("ol_fromlst");
      ol_fromlstindex472 = readrel493->getIndex(ord492, false);
      std::vector<u16> ord494({1, 0});
      slog::Relation* readrel495 = db->getRelation("ol_fromlst");
      ol_fromlstdelta474 = readrel495->getIndex(ord494, true);
      std::vector<u16> ord496({0, 1});
      slog::Relation* readrel497 = db->getRelation("ol_fromlst_ans");
      ol_fromlst_ansindex473 = readrel497->getIndex(ord496, false);
  
    }
    ReadTask475(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c20 = _t[1];
        if (!slog::exists_probe<3,1>(lst_appendindex464, std::array<u64,3>{v_c20, 0, 0})) return;
        if (!slog::exists_probe<4,1>($sup76318x27x0x0x0index465, std::array<u64,4>{v_c20, 0, 0, 0})) return;
        slog::join_probe<2,1>(ol_fromlst_ansindex466, std::array<u64,2>{v_c55, 0}, [&](const std::array<u64,2>& m498) {
          u64 v_c25 = m498[1];
          slog::join_probe<3,1>(lst_appendindex467, std::array<u64,3>{v_c20, 0, 0}, [&](const std::array<u64,3>& m499) {
            u64 v_c17 = m499[1]; u64 v_c54 = m499[2];
            if (!slog::exists_probe<2,1>(lst_append_ansindex468, std::array<u64,2>{v_c54, 0})) return;
            if (!slog::exists_probe<2,1>(ol_fromlstindex469, std::array<u64,2>{v_c17, 0})) return;
            slog::join_probe<4,2>($sup76318x27x0x0x0index470, std::array<u64,4>{v_c20, v_c17, 0, 0}, [&](const std::array<u64,4>& m500) {
              u64 v_c21 = m500[2]; u64 v_c22 = m500[3];
              slog::join_probe<2,1>(lst_append_ansindex471, std::array<u64,2>{v_c54, 0}, [&](const std::array<u64,2>& m501) {
                u64 v_c23 = m501[1];
                slog::join_probe_old<2,1>(ol_fromlstindex472, ol_fromlstdelta474, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m502) {
                  u64 v_c53 = m502[1];
                  slog::join_probe<2,1>(ol_fromlst_ansindex473, std::array<u64,2>{v_c53, 0}, [&](const std::array<u64,2>& m503) {
                    u64 v_c18 = m503[1];
                    ++_fires;
                    slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c23}, std::array<u16,2>{1, 0});
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
        ReadTask475* _cont = new ReadTask475(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask475(db,b), false);
  // (crule (pre) (scan ol_fromlst __t7O3Z118 l) (body (exists $sup76318x53x0x0x0 (2 0 1) 1 l) (exists lst_take (1 2 0) 1 l) (join ol_fromlst_ans (0 1) 1 __t7O3Z118 c) (join $sup76318x53x0x0x0 (2 0 1) 1 l i k) (join lst_take (1 2 0) 2 l k __t1gGD117) (join lst_take_ans (0 1) 1 __t1gGD117 r)) (head (mkstruct ol_fromlst (1 0) __1QCl400 r)) seq_oracle.slog:54 #f)
  class ReadTask510 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup76318x53x0x0x0index504;  slog::Index** lst_takeindex505;  slog::Index** ol_fromlst_ansindex506;  slog::Index** $sup76318x53x0x0x0index507;  slog::Index** lst_takeindex508;  slog::Index** lst_take_ansindex509;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ol_fromlst");
      outer_rel = db->getRelation("ol_fromlst");
      std::vector<u16> ord511({2, 0, 1});
      slog::Relation* readrel512 = db->getRelation("$sup76318x53x0x0x0");
      $sup76318x53x0x0x0index504 = readrel512->getIndex(ord511, false);
      std::vector<u16> ord513({1, 2, 0});
      slog::Relation* readrel514 = db->getRelation("lst_take");
      lst_takeindex505 = readrel514->getIndex(ord513, false);
      std::vector<u16> ord515({0, 1});
      slog::Relation* readrel516 = db->getRelation("ol_fromlst_ans");
      ol_fromlst_ansindex506 = readrel516->getIndex(ord515, false);
      std::vector<u16> ord517({2, 0, 1});
      slog::Relation* readrel518 = db->getRelation("$sup76318x53x0x0x0");
      $sup76318x53x0x0x0index507 = readrel518->getIndex(ord517, false);
      std::vector<u16> ord519({1, 2, 0});
      slog::Relation* readrel520 = db->getRelation("lst_take");
      lst_takeindex508 = readrel520->getIndex(ord519, false);
      std::vector<u16> ord521({0, 1});
      slog::Relation* readrel522 = db->getRelation("lst_take_ans");
      lst_take_ansindex509 = readrel522->getIndex(ord521, false);
  
    }
    ReadTask510(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c51 = _t[1];
        if (!slog::exists_probe<3,1>($sup76318x53x0x0x0index504, std::array<u64,3>{v_c51, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lst_takeindex505, std::array<u64,3>{v_c51, 0, 0})) return;
        slog::join_probe<2,1>(ol_fromlst_ansindex506, std::array<u64,2>{v_c67, 0}, [&](const std::array<u64,2>& m523) {
          u64 v_c57 = m523[1];
          slog::join_probe<3,1>($sup76318x53x0x0x0index507, std::array<u64,3>{v_c51, 0, 0}, [&](const std::array<u64,3>& m524) {
            u64 v_c21 = m524[1]; u64 v_c58 = m524[2];
            slog::join_probe<3,2>(lst_takeindex508, std::array<u64,3>{v_c51, v_c58, 0}, [&](const std::array<u64,3>& m525) {
              u64 v_c68 = m525[2];
              slog::join_probe<2,1>(lst_take_ansindex509, std::array<u64,2>{v_c68, 0}, [&](const std::array<u64,2>& m526) {
                u64 v_c23 = m526[1];
                ++_fires;
                slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c23}, std::array<u16,2>{1, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:54", "delta:ol_fromlst", _fires);
  
      if (!_done)
      {
        ReadTask510* _cont = new ReadTask510(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask510(db,b), false);
  // (crule (pre (let _00024sqc043G284 const6b86b273ff34fce19d6b804e) (let _00024sqc0Ftc285 const5feceb66ffc86f38d952786c) (let _00024sqc4Arr286 const6b86b273ff34fce19d6b804e) (let _00024sqc1a9l287 const5feceb66ffc86f38d952786c) (let _00024sqo2g9r292 const5feceb66ffc86f38d952786c)) (scan $sup59985x12x0x0x0 _00024seq0 __t0Thi68 x xs) (body (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo2g9r292 x _00024seq0) (join-old ol_fromlst (0 1) 2 (0 1) __t0Thi68 _00024seq0) (join-old ol_fromlst (1 0) 1 (1 0) xs __t9Mc169) (join ol_fromlst_ans (0 1) 1 __t9Mc169 __v0) (letp _00024sql34b9282 (aslst _00024seq0)) (let _00024sqn2tQo283 (llen _00024sql34b9282)) (cmp ge _00024sqn2tQo283 _00024sqc043G284) (letp chk8ELO781 (lref _00024sql34b9282 _00024sqc0Ftc285)) (eq x chk8ELO781) (let _00024sqp8Anj288 (_0002d _00024sqn2tQo283 _00024sqc1a9l287)) (let chk838Q782 (lslice _00024sql34b9282 _00024sqc4Arr286 _00024sqp8Anj288)) (eq xs chk838Q782)) (head (emit-temp temp3vIA778 __t0Thi68 __v0 x) (mkstruct ccons (2 1 0) __t3yQa67 __v0 x)) list-cons.slog:13 #f)
  class ReadTask534 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $seq_atindex527;  slog::Index** ol_fromlstindex528;  slog::Index** ol_fromlstindex529;  slog::Index** ol_fromlst_ansindex530;  slog::Index** $seq_atdelta531;  slog::Index** ol_fromlstdelta532;  slog::Index** ol_fromlstdelta533;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3vIA778");
      head_rel[1] = db->getRelation("ccons");
      outer_rel = db->getRelation("$sup59985x12x0x0x0");
      std::vector<u16> ord535({1, 0, 2});
      slog::Relation* readrel536 = db->getRelation("$seq_at");
      $seq_atindex527 = readrel536->getIndex(ord535, false);
      std::vector<u16> ord537({1, 0, 2});
      slog::Relation* readrel538 = db->getRelation("$seq_at");
      $seq_atdelta531 = readrel538->getIndex(ord537, true);
      std::vector<u16> ord539({0, 1});
      slog::Relation* readrel540 = db->getRelation("ol_fromlst");
      ol_fromlstindex528 = readrel540->getIndex(ord539, false);
      std::vector<u16> ord541({0, 1});
      slog::Relation* readrel542 = db->getRelation("ol_fromlst");
      ol_fromlstdelta532 = readrel542->getIndex(ord541, true);
      std::vector<u16> ord543({1, 0});
      slog::Relation* readrel544 = db->getRelation("ol_fromlst");
      ol_fromlstindex529 = readrel544->getIndex(ord543, false);
      std::vector<u16> ord545({1, 0});
      slog::Relation* readrel546 = db->getRelation("ol_fromlst");
      ol_fromlstdelta533 = readrel546->getIndex(ord545, true);
      std::vector<u16> ord547({0, 1});
      slog::Relation* readrel548 = db->getRelation("ol_fromlst_ans");
      ol_fromlst_ansindex530 = readrel548->getIndex(ord547, false);
  
    }
    ReadTask534(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c1 = v_const5feceb66ffc86f38d952786c;
      u64 v_c2 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c3 = v_const5feceb66ffc86f38d952786c;
      u64 v_c4 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c6 = _t[0];
        u64 v_c12 = _t[1];
        u64 v_c5 = _t[2];
        u64 v_c11 = _t[3];
        slog::join_probe_old<3,3>($seq_atindex527, $seq_atdelta531, std::array<u64,3>{v_c4, v_c5, v_c6}, [&](const std::array<u64,3>& m549) {
          slog::join_probe_old<2,2>(ol_fromlstindex528, ol_fromlstdelta532, std::array<u64,2>{v_c12, v_c6}, [&](const std::array<u64,2>& m550) {
            slog::join_probe_old<2,1>(ol_fromlstindex529, ol_fromlstdelta533, std::array<u64,2>{v_c11, 0}, [&](const std::array<u64,2>& m551) {
              u64 v_c13 = m551[1];
              slog::join_probe<2,1>(ol_fromlst_ansindex530, std::array<u64,2>{v_c13, 0}, [&](const std::array<u64,2>& m552) {
                u64 v_c14 = m552[1];
                bool ok553 = true;
                u64 v_c7 = _prim_aslst(db, v_c6, &ok553);
                if (!ok553) return;
                u64 v_c8 = _prim_llen(db, v_c7);
                if (v_c8 == slog_error) { slog::emit_pending_error(db, "list-cons.slog:13"); return; }
                u64 v_c69 = _prim_ge(db, v_c8, v_c0);
                if (v_c69 == slog_error) { slog::emit_pending_error(db, "list-cons.slog:13"); return; }
                if (!v_c69) return;
                bool ok555 = true;
                u64 v_c70 = _prim_lref(db, v_c7, v_c1, &ok555);
                if (!ok555) return;
                if (v_c5 != v_c70) return;
                u64 v_c10 = _prim__0002d(db, v_c8, v_c3);
                if (v_c10 == slog_error) { slog::emit_pending_error(db, "list-cons.slog:13"); return; }
                u64 v_c71 = _prim_lslice(db, v_c7, v_c2, v_c10);
                if (v_c71 == slog_error) { slog::emit_pending_error(db, "list-cons.slog:13"); return; }
                if (v_c11 != v_c71) return;
                ++_fires;
                slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c12, v_c14, v_c5});
                slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c14, v_c5}, std::array<u16,3>{2, 1, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("list-cons.slog:13", "delta:$sup59985x12x0x0x0", _fires);
  
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
  // (crule (pre) (scan seed i l) (body) (head (mkstruct ol_fromlst (1 0) __9MEv320 l)) seq_oracle.slog:59 #f)
  class ReadTask556 : public slog::Task
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
    ReadTask556(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c51 = _t[1];
        ++_fires;
        slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c51}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:59", "all:seed", _fires);
  
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
      s->addTask(phase_read, new ReadTask556(db,b), true);
  // (crule (pre (let __tconst1kxe388 const9ac63e4426dab2edcc97bcf7)) (scan ol_take __t2Vv6250 __t9XCT249 n) (body (join _enum (0 1) 2 __t9XCT249 __tconst1kxe388)) (head (emit ol_take_ans (0 1) __t2Vv6250 __t9XCT249)) list-cons.slog:43 #f)
  class ReadTask558 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex557;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ol_take_ans");
      std::vector<u16> ord559({0, 1});
      slog::Relation* readrel560 = db->getRelation("ol_take_ans");
      head_index[0] = readrel560->getIndex(ord559, false);
      outer_rel = db->getRelation("ol_take");
      std::vector<u16> ord561({0, 1});
      slog::Relation* readrel562 = db->getRelation("_enum");
      _enumindex557 = readrel562->getIndex(ord561, false);
  
    }
    ReadTask558(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c72 = v_const9ac63e4426dab2edcc97bcf7;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c73 = _t[0];
        u64 v_c74 = _t[1];
        u64 v_c37 = _t[2];
        slog::join_probe<2,2>(_enumindex557, std::array<u64,2>{v_c74, v_c72}, [&](const std::array<u64,2>& m563) {
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c73, v_c74}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("list-cons.slog:43", "delta:ol_take", _fires);
  
      if (!_done)
      {
        ReadTask558* _cont = new ReadTask558(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask558(db,b), false);
  // (crule (pre) (scan ol_fromlst_ans __t56aw4 c) (body (join-old ol_fromlst (0 1) 1 (0 1) __t56aw4 l) (exists lst_rev (1 0) 1 l) (join seed (1 0) 1 l i) (join lst_rev (1 0) 1 l __t5hLI3) (join lst_rev_ans (0 1) 1 __t5hLI3 r)) (head (mkstruct ol_rev (1 0) __9mwF303 c)) seq_oracle.slog:59 #f)
  class ReadTask570 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ol_fromlstindex564;  slog::Index** lst_revindex565;  slog::Index** seedindex566;  slog::Index** lst_revindex567;  slog::Index** lst_rev_ansindex568;  slog::Index** ol_fromlstdelta569;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ol_rev");
      outer_rel = db->getRelation("ol_fromlst_ans");
      std::vector<u16> ord571({0, 1});
      slog::Relation* readrel572 = db->getRelation("ol_fromlst");
      ol_fromlstindex564 = readrel572->getIndex(ord571, false);
      std::vector<u16> ord573({0, 1});
      slog::Relation* readrel574 = db->getRelation("ol_fromlst");
      ol_fromlstdelta569 = readrel574->getIndex(ord573, true);
      std::vector<u16> ord575({1, 0});
      slog::Relation* readrel576 = db->getRelation("lst_rev");
      lst_revindex565 = readrel576->getIndex(ord575, false);
      std::vector<u16> ord577({1, 0});
      slog::Relation* readrel578 = db->getRelation("seed");
      seedindex566 = readrel578->getIndex(ord577, false);
      std::vector<u16> ord579({1, 0});
      slog::Relation* readrel580 = db->getRelation("lst_rev");
      lst_revindex567 = readrel580->getIndex(ord579, false);
      std::vector<u16> ord581({0, 1});
      slog::Relation* readrel582 = db->getRelation("lst_rev_ans");
      lst_rev_ansindex568 = readrel582->getIndex(ord581, false);
  
    }
    ReadTask570(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c57 = _t[1];
        slog::join_probe_old<2,1>(ol_fromlstindex564, ol_fromlstdelta569, std::array<u64,2>{v_c75, 0}, [&](const std::array<u64,2>& m583) {
          u64 v_c51 = m583[1];
          if (!slog::exists_probe<2,1>(lst_revindex565, std::array<u64,2>{v_c51, 0})) return;
          slog::join_probe<2,1>(seedindex566, std::array<u64,2>{v_c51, 0}, [&](const std::array<u64,2>& m584) {
            u64 v_c21 = m584[1];
            slog::join_probe<2,1>(lst_revindex567, std::array<u64,2>{v_c51, 0}, [&](const std::array<u64,2>& m585) {
              u64 v_c76 = m585[1];
              slog::join_probe<2,1>(lst_rev_ansindex568, std::array<u64,2>{v_c76, 0}, [&](const std::array<u64,2>& m586) {
                u64 v_c23 = m586[1];
                ++_fires;
                slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c57}, std::array<u16,2>{1, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:59", "delta:ol_fromlst_ans", _fires);
  
      if (!_done)
      {
        ReadTask570* _cont = new ReadTask570(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask570(db,b), false);
  // (crule (pre (let __tconst5CoZ46 const5feceb66ffc86f38d952786c) (let __tconst91dC47 const6b86b273ff34fce19d6b804e)) (scan ol_take __t8pjA49 xs __t2oh148) (body (exists ccons (2 1 0) 1 xs) (exists $sup59985x43x0x0x0 (3 2 0 1) 1 xs) (join ol_take_ans (0 1) 1 __t8pjA49 __v0) (join ccons (2 1 0) 1 xs x __t30ob44) (exists ol_take (1 2 0) 1 __t30ob44) (join $sup59985x43x0x0x0 (3 2 0 1) 2 xs x __t1IJu45 n) (cmp lt __tconst5CoZ46 n) (join ol_take (0 2 1) 3 __t1IJu45 n __t30ob44) (let chk8AZv792 (_0002d n __tconst91dC47)) (eq __t2oh148 chk8AZv792)) (head (emit-temp temp2mRb790 __t1IJu45 __v0 x) (mkstruct ccons (2 1 0) __t0pq643 __v0 x)) list-cons.slog:44 #f)
  class ReadTask594 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** cconsindex587;  slog::Index** $sup59985x43x0x0x0index588;  slog::Index** ol_take_ansindex589;  slog::Index** cconsindex590;  slog::Index** ol_takeindex591;  slog::Index** $sup59985x43x0x0x0index592;  slog::Index** ol_takeindex593;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2mRb790");
      head_rel[1] = db->getRelation("ccons");
      outer_rel = db->getRelation("ol_take");
      std::vector<u16> ord595({2, 1, 0});
      slog::Relation* readrel596 = db->getRelation("ccons");
      cconsindex587 = readrel596->getIndex(ord595, false);
      std::vector<u16> ord597({3, 2, 0, 1});
      slog::Relation* readrel598 = db->getRelation("$sup59985x43x0x0x0");
      $sup59985x43x0x0x0index588 = readrel598->getIndex(ord597, false);
      std::vector<u16> ord599({0, 1});
      slog::Relation* readrel600 = db->getRelation("ol_take_ans");
      ol_take_ansindex589 = readrel600->getIndex(ord599, false);
      std::vector<u16> ord601({2, 1, 0});
      slog::Relation* readrel602 = db->getRelation("ccons");
      cconsindex590 = readrel602->getIndex(ord601, false);
      std::vector<u16> ord603({1, 2, 0});
      slog::Relation* readrel604 = db->getRelation("ol_take");
      ol_takeindex591 = readrel604->getIndex(ord603, false);
      std::vector<u16> ord605({3, 2, 0, 1});
      slog::Relation* readrel606 = db->getRelation("$sup59985x43x0x0x0");
      $sup59985x43x0x0x0index592 = readrel606->getIndex(ord605, false);
      std::vector<u16> ord607({0, 2, 1});
      slog::Relation* readrel608 = db->getRelation("ol_take");
      ol_takeindex593 = readrel608->getIndex(ord607, false);
  
    }
    ReadTask594(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c34 = v_const5feceb66ffc86f38d952786c;
      u64 v_c35 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c11 = _t[1];
        u64 v_c39 = _t[2];
        if (!slog::exists_probe<3,1>(cconsindex587, std::array<u64,3>{v_c11, 0, 0})) return;
        if (!slog::exists_probe<4,1>($sup59985x43x0x0x0index588, std::array<u64,4>{v_c11, 0, 0, 0})) return;
        slog::join_probe<2,1>(ol_take_ansindex589, std::array<u64,2>{v_c40, 0}, [&](const std::array<u64,2>& m609) {
          u64 v_c14 = m609[1];
          slog::join_probe<3,1>(cconsindex590, std::array<u64,3>{v_c11, 0, 0}, [&](const std::array<u64,3>& m610) {
            u64 v_c5 = m610[1]; u64 v_c36 = m610[2];
            if (!slog::exists_probe<3,1>(ol_takeindex591, std::array<u64,3>{v_c36, 0, 0})) return;
            slog::join_probe<4,2>($sup59985x43x0x0x0index592, std::array<u64,4>{v_c11, v_c5, 0, 0}, [&](const std::array<u64,4>& m611) {
              u64 v_c26 = m611[2]; u64 v_c37 = m611[3];
              u64 v_c77 = _prim_lt(db, v_c34, v_c37);
              if (v_c77 == slog_error) { slog::emit_pending_error(db, "list-cons.slog:44"); return; }
              if (!v_c77) return;
              slog::join_probe<3,3>(ol_takeindex593, std::array<u64,3>{v_c26, v_c37, v_c36}, [&](const std::array<u64,3>& m613) {
                u64 v_c78 = _prim__0002d(db, v_c37, v_c35);
                if (v_c78 == slog_error) { slog::emit_pending_error(db, "list-cons.slog:44"); return; }
                if (v_c39 != v_c78) return;
                ++_fires;
                slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c26, v_c14, v_c5});
                slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c14, v_c5}, std::array<u16,3>{2, 1, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("list-cons.slog:44", "delta:ol_take", _fires);
  
      if (!_done)
      {
        ReadTask594* _cont = new ReadTask594(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask594(db,b), false);
  // (crule (pre) (scan type_mismatch __erre64OQ765 __errf2MiU766 __errf5kyi767 __errf8cUJ768 __errf1NoS769) (body) (head (emit error (0) __erre64OQ765)) <internal>:1 #f)
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
      outer_rel = db->getRelation("type_mismatch");
  
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
        u64 v_c79 = _t[0];
        u64 v_c80 = _t[1];
        u64 v_c81 = _t[2];
        u64 v_c82 = _t[3];
        u64 v_c83 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c79}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:type_mismatch", _fires);
  
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
  // (crule (pre) (scan ol_fromlst __t5TS9103 a) (body (exists lst_append (1 2 0) 1 a) (exists $sup76318x27x0x0x0 (0 1 2 3) 1 a) (join ol_fromlst_ans (0 1) 1 __t5TS9103 ca) (join lst_append (1 2 0) 1 a b __t5oTD102) (exists lst_append_ans (0 1) 1 __t5oTD102) (exists ol_fromlst (1 0) 1 b) (join $sup76318x27x0x0x0 (0 1 2 3) 2 a b i j) (join lst_append_ans (0 1) 1 __t5oTD102 r) (join-old ol_fromlst (1 0) 1 (1 0) b __t1qQi104) (join ol_fromlst_ans (0 1) 1 __t1qQi104 cb)) (head (mkstruct ol_append (1 2 0) __5fbv387 ca cb)) seq_oracle.slog:28 #f)
  class ReadTask628 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lst_appendindex617;  slog::Index** $sup76318x27x0x0x0index618;  slog::Index** ol_fromlst_ansindex619;  slog::Index** lst_appendindex620;  slog::Index** lst_append_ansindex621;  slog::Index** ol_fromlstindex622;  slog::Index** $sup76318x27x0x0x0index623;  slog::Index** lst_append_ansindex624;  slog::Index** ol_fromlstindex625;  slog::Index** ol_fromlst_ansindex626;  slog::Index** ol_fromlstdelta627;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ol_append");
      outer_rel = db->getRelation("ol_fromlst");
      std::vector<u16> ord629({1, 2, 0});
      slog::Relation* readrel630 = db->getRelation("lst_append");
      lst_appendindex617 = readrel630->getIndex(ord629, false);
      std::vector<u16> ord631({0, 1, 2, 3});
      slog::Relation* readrel632 = db->getRelation("$sup76318x27x0x0x0");
      $sup76318x27x0x0x0index618 = readrel632->getIndex(ord631, false);
      std::vector<u16> ord633({0, 1});
      slog::Relation* readrel634 = db->getRelation("ol_fromlst_ans");
      ol_fromlst_ansindex619 = readrel634->getIndex(ord633, false);
      std::vector<u16> ord635({1, 2, 0});
      slog::Relation* readrel636 = db->getRelation("lst_append");
      lst_appendindex620 = readrel636->getIndex(ord635, false);
      std::vector<u16> ord637({0, 1});
      slog::Relation* readrel638 = db->getRelation("lst_append_ans");
      lst_append_ansindex621 = readrel638->getIndex(ord637, false);
      std::vector<u16> ord639({1, 0});
      slog::Relation* readrel640 = db->getRelation("ol_fromlst");
      ol_fromlstindex622 = readrel640->getIndex(ord639, false);
      std::vector<u16> ord641({0, 1, 2, 3});
      slog::Relation* readrel642 = db->getRelation("$sup76318x27x0x0x0");
      $sup76318x27x0x0x0index623 = readrel642->getIndex(ord641, false);
      std::vector<u16> ord643({0, 1});
      slog::Relation* readrel644 = db->getRelation("lst_append_ans");
      lst_append_ansindex624 = readrel644->getIndex(ord643, false);
      std::vector<u16> ord645({1, 0});
      slog::Relation* readrel646 = db->getRelation("ol_fromlst");
      ol_fromlstindex625 = readrel646->getIndex(ord645, false);
      std::vector<u16> ord647({1, 0});
      slog::Relation* readrel648 = db->getRelation("ol_fromlst");
      ol_fromlstdelta627 = readrel648->getIndex(ord647, true);
      std::vector<u16> ord649({0, 1});
      slog::Relation* readrel650 = db->getRelation("ol_fromlst_ans");
      ol_fromlst_ansindex626 = readrel650->getIndex(ord649, false);
  
    }
    ReadTask628(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c20 = _t[1];
        if (!slog::exists_probe<3,1>(lst_appendindex617, std::array<u64,3>{v_c20, 0, 0})) return;
        if (!slog::exists_probe<4,1>($sup76318x27x0x0x0index618, std::array<u64,4>{v_c20, 0, 0, 0})) return;
        slog::join_probe<2,1>(ol_fromlst_ansindex619, std::array<u64,2>{v_c24, 0}, [&](const std::array<u64,2>& m651) {
          u64 v_c25 = m651[1];
          slog::join_probe<3,1>(lst_appendindex620, std::array<u64,3>{v_c20, 0, 0}, [&](const std::array<u64,3>& m652) {
            u64 v_c17 = m652[1]; u64 v_c19 = m652[2];
            if (!slog::exists_probe<2,1>(lst_append_ansindex621, std::array<u64,2>{v_c19, 0})) return;
            if (!slog::exists_probe<2,1>(ol_fromlstindex622, std::array<u64,2>{v_c17, 0})) return;
            slog::join_probe<4,2>($sup76318x27x0x0x0index623, std::array<u64,4>{v_c20, v_c17, 0, 0}, [&](const std::array<u64,4>& m653) {
              u64 v_c21 = m653[2]; u64 v_c22 = m653[3];
              slog::join_probe<2,1>(lst_append_ansindex624, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m654) {
                u64 v_c23 = m654[1];
                slog::join_probe_old<2,1>(ol_fromlstindex625, ol_fromlstdelta627, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m655) {
                  u64 v_c16 = m655[1];
                  slog::join_probe<2,1>(ol_fromlst_ansindex626, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m656) {
                    u64 v_c18 = m656[1];
                    ++_fires;
                    slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c25, v_c18}, std::array<u16,3>{1, 2, 0});
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
        ReadTask628* _cont = new ReadTask628(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask628(db,b), false);
  // (crule (pre) (scan ol_fromlst_ans __t7O3Z118 c) (body (join-old ol_fromlst (0 1) 1 (0 1) __t7O3Z118 l) (exists lst_take (1 2 0) 1 l) (join $sup76318x53x0x0x0 (2 0 1) 1 l i k) (join lst_take (1 2 0) 2 l k __t1gGD117) (join lst_take_ans (0 1) 1 __t1gGD117 r)) (head (mkstruct ol_fromlst (1 0) __1QCl400 r)) seq_oracle.slog:54 #f)
  class ReadTask663 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ol_fromlstindex657;  slog::Index** lst_takeindex658;  slog::Index** $sup76318x53x0x0x0index659;  slog::Index** lst_takeindex660;  slog::Index** lst_take_ansindex661;  slog::Index** ol_fromlstdelta662;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ol_fromlst");
      outer_rel = db->getRelation("ol_fromlst_ans");
      std::vector<u16> ord664({0, 1});
      slog::Relation* readrel665 = db->getRelation("ol_fromlst");
      ol_fromlstindex657 = readrel665->getIndex(ord664, false);
      std::vector<u16> ord666({0, 1});
      slog::Relation* readrel667 = db->getRelation("ol_fromlst");
      ol_fromlstdelta662 = readrel667->getIndex(ord666, true);
      std::vector<u16> ord668({1, 2, 0});
      slog::Relation* readrel669 = db->getRelation("lst_take");
      lst_takeindex658 = readrel669->getIndex(ord668, false);
      std::vector<u16> ord670({2, 0, 1});
      slog::Relation* readrel671 = db->getRelation("$sup76318x53x0x0x0");
      $sup76318x53x0x0x0index659 = readrel671->getIndex(ord670, false);
      std::vector<u16> ord672({1, 2, 0});
      slog::Relation* readrel673 = db->getRelation("lst_take");
      lst_takeindex660 = readrel673->getIndex(ord672, false);
      std::vector<u16> ord674({0, 1});
      slog::Relation* readrel675 = db->getRelation("lst_take_ans");
      lst_take_ansindex661 = readrel675->getIndex(ord674, false);
  
    }
    ReadTask663(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c57 = _t[1];
        slog::join_probe_old<2,1>(ol_fromlstindex657, ol_fromlstdelta662, std::array<u64,2>{v_c67, 0}, [&](const std::array<u64,2>& m676) {
          u64 v_c51 = m676[1];
          if (!slog::exists_probe<3,1>(lst_takeindex658, std::array<u64,3>{v_c51, 0, 0})) return;
          slog::join_probe<3,1>($sup76318x53x0x0x0index659, std::array<u64,3>{v_c51, 0, 0}, [&](const std::array<u64,3>& m677) {
            u64 v_c21 = m677[1]; u64 v_c58 = m677[2];
            slog::join_probe<3,2>(lst_takeindex660, std::array<u64,3>{v_c51, v_c58, 0}, [&](const std::array<u64,3>& m678) {
              u64 v_c68 = m678[2];
              slog::join_probe<2,1>(lst_take_ansindex661, std::array<u64,2>{v_c68, 0}, [&](const std::array<u64,2>& m679) {
                u64 v_c23 = m679[1];
                ++_fires;
                slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c23}, std::array<u16,2>{1, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:54", "delta:ol_fromlst_ans", _fires);
  
      if (!_done)
      {
        ReadTask663* _cont = new ReadTask663(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask663(db,b), false);
  // (crule (pre) (scan ol_fromlst __t3SE22 l) (body (exists ol_fromlst_ans (0 1) 1 __t3SE22) (exists lst_rev (1 0) 1 l) (join seed (1 0) 1 l i) (join ol_fromlst_ans (0 1) 1 __t3SE22 c) (join lst_rev (1 0) 1 l __t3V4l1) (join lst_rev_ans (0 1) 1 __t3V4l1 r)) (head (mkstruct ol_fromlst (1 0) __2yQv333 r)) seq_oracle.slog:59 #f)
  class ReadTask686 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** ol_fromlst_ansindex680;  slog::Index** lst_revindex681;  slog::Index** seedindex682;  slog::Index** ol_fromlst_ansindex683;  slog::Index** lst_revindex684;  slog::Index** lst_rev_ansindex685;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ol_fromlst");
      outer_rel = db->getRelation("ol_fromlst");
      std::vector<u16> ord687({0, 1});
      slog::Relation* readrel688 = db->getRelation("ol_fromlst_ans");
      ol_fromlst_ansindex680 = readrel688->getIndex(ord687, false);
      std::vector<u16> ord689({1, 0});
      slog::Relation* readrel690 = db->getRelation("lst_rev");
      lst_revindex681 = readrel690->getIndex(ord689, false);
      std::vector<u16> ord691({1, 0});
      slog::Relation* readrel692 = db->getRelation("seed");
      seedindex682 = readrel692->getIndex(ord691, false);
      std::vector<u16> ord693({0, 1});
      slog::Relation* readrel694 = db->getRelation("ol_fromlst_ans");
      ol_fromlst_ansindex683 = readrel694->getIndex(ord693, false);
      std::vector<u16> ord695({1, 0});
      slog::Relation* readrel696 = db->getRelation("lst_rev");
      lst_revindex684 = readrel696->getIndex(ord695, false);
      std::vector<u16> ord697({0, 1});
      slog::Relation* readrel698 = db->getRelation("lst_rev_ans");
      lst_rev_ansindex685 = readrel698->getIndex(ord697, false);
  
    }
    ReadTask686(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c84 = _t[0];
        u64 v_c51 = _t[1];
        if (!slog::exists_probe<2,1>(ol_fromlst_ansindex680, std::array<u64,2>{v_c84, 0})) return;
        if (!slog::exists_probe<2,1>(lst_revindex681, std::array<u64,2>{v_c51, 0})) return;
        slog::join_probe<2,1>(seedindex682, std::array<u64,2>{v_c51, 0}, [&](const std::array<u64,2>& m699) {
          u64 v_c21 = m699[1];
          slog::join_probe<2,1>(ol_fromlst_ansindex683, std::array<u64,2>{v_c84, 0}, [&](const std::array<u64,2>& m700) {
            u64 v_c57 = m700[1];
            slog::join_probe<2,1>(lst_revindex684, std::array<u64,2>{v_c51, 0}, [&](const std::array<u64,2>& m701) {
              u64 v_c85 = m701[1];
              slog::join_probe<2,1>(lst_rev_ansindex685, std::array<u64,2>{v_c85, 0}, [&](const std::array<u64,2>& m702) {
                u64 v_c23 = m702[1];
                ++_fires;
                slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c23}, std::array<u16,2>{1, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:59", "delta:ol_fromlst", _fires);
  
      if (!_done)
      {
        ReadTask686* _cont = new ReadTask686(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask686(db,b), false);
  // (crule (pre (let __trid7qON360 constc0b63bd612a3529319444133) (let __trel0wj9361 constde3f85f3da4637dccad01619) (let __tcol5mex362 const5feceb66ffc86f38d952786c)) (scan $sup76318x33x0x0x0 i k l) (body) (head (tycheck l (accept seq) __trid7qON360 __trel0wj9361 __tcol5mex362 (1 2 3 4 0)) (mkstruct ol_fromlst (1 0) __9nNZ359 l)) seq_oracle.slog:34 #f)
  class ReadTask703 : public slog::Task
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
      outer_rel = db->getRelation("$sup76318x33x0x0x0");
  
    }
    ReadTask703(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c86 = v_constc0b63bd612a3529319444133;
      u64 v_c87 = v_constde3f85f3da4637dccad01619;
      u64 v_c88 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c21 = _t[0];
        u64 v_c58 = _t[1];
        u64 v_c51 = _t[2];
        ++_fires;
        if (!(is_seq(v_c51)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c86, v_c87, v_c88, v_c51}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c51}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:34", "all:$sup76318x33x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask703* _cont = new ReadTask703(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask703(db,b), true);
  // (crule (pre (let __trid5lmT297 const154aa17dce57824acb89891d) (let __trel52B8298 constde3f85f3da4637dccad01619) (let __tcol1rN4299 const5feceb66ffc86f38d952786c)) (scan $sup76318x53x0x0x0 i k l) (body) (head (tycheck l (accept seq) __trid5lmT297 __trel52B8298 __tcol1rN4299 (1 2 3 4 0)) (mkstruct ol_fromlst (1 0) __7k0h296 l)) seq_oracle.slog:54 #f)
  class ReadTask704 : public slog::Task
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
      outer_rel = db->getRelation("$sup76318x53x0x0x0");
  
    }
    ReadTask704(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c89 = v_const154aa17dce57824acb89891d;
      u64 v_c90 = v_constde3f85f3da4637dccad01619;
      u64 v_c91 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c21 = _t[0];
        u64 v_c58 = _t[1];
        u64 v_c51 = _t[2];
        ++_fires;
        if (!(is_seq(v_c51)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c89, v_c90, v_c91, v_c51}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c51}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("seq_oracle.slog:54", "all:$sup76318x53x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask704* _cont = new ReadTask704(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask704(db,b), true);
  // (crule (pre) (scan temp9VKb789 __t3t1M97 x z) (body (join ccons (2 1 0) 2 z x __t7O1j95)) (head (emit ol_append_ans (0 1) __t3t1M97 __t7O1j95)) list-cons.slog:23 #f)
  class ReadTask706 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** cconsindex705;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ol_append_ans");
      std::vector<u16> ord707({0, 1});
      slog::Relation* readrel708 = db->getRelation("ol_append_ans");
      head_index[0] = readrel708->getIndex(ord707, false);
      outer_rel = db->getRelation("temp9VKb789");
      std::vector<u16> ord709({2, 1, 0});
      slog::Relation* readrel710 = db->getRelation("ccons");
      cconsindex705 = readrel710->getIndex(ord709, false);
  
    }
    ReadTask706(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c5 = _t[1];
        u64 v_c48 = _t[2];
        slog::join_probe<3,2>(cconsindex705, std::array<u64,3>{v_c48, v_c5, 0}, [&](const std::array<u64,3>& m711) {
          u64 v_c92 = m711[2];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c45, v_c92}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("list-cons.slog:23", "delta:temp9VKb789", _fires);
  
      if (!_done)
      {
        ReadTask706* _cont = new ReadTask706(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask706(db,b), false);
  // (crule (pre) (scan toint_range __erre3HJ1762 __errf97eo763 __errf14JT764) (body) (head (emit error (0) __erre3HJ1762)) <internal>:1 #f)
  class ReadTask712 : public slog::Task
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
      std::vector<u16> ord713({0});
      slog::Relation* readrel714 = db->getRelation("error");
      head_index[0] = readrel714->getIndex(ord713, false);
      outer_rel = db->getRelation("toint_range");
  
    }
    ReadTask712(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c93 = _t[0];
        u64 v_c94 = _t[1];
        u64 v_c95 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c93}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:toint_range", _fires);
  
      if (!_done)
      {
        ReadTask712* _cont = new ReadTask712(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask712(db,b), false);
}

