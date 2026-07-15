
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const26c89ee8ccc4ea998fd1a912;
extern u64 v_const2c624232cdd221771294dfbb;
extern u64 v_const4b227777d4dd1fc61c6f884f;
extern u64 v_const4e07408562bedb8b60ce05c1;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const66633592860a63ea6408b433;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const76a4fedc25549f0939d52fb7;
extern u64 v_const81906d9241165d9f6a541e47;
extern u64 v_const94d9c4e2675ef4bd8443d499;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_conste3776bfed7f405de8017ecfa;
extern u64 v_constef2d127de37b942baad06145;
extern u64 v_constf95dfec4ee2675891829b965;


void slog_rules_cc67696b823a1d9b9(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre (let __tconst19LZ687 conste3776bfed7f405de8017ecfa) (let __tconst6nio451 constef2d127de37b942baad06145) (let __tconst5Crw454 constd4735e3a265e16eee03f5971) (let __tconst7cMm457 const2c624232cdd221771294dfbb) (let __tconst776G459 const6b86b273ff34fce19d6b804e)) (probe st_ins (2 0 1) 1 __tconst776G459 __t7DB2460 __v1) (body (exists st_ins (2 0 1) 1 __tconst6nio451) (exists st_ins (2 0 1) 1 __tconst5Crw454) (exists st_ins_ans (1 0) 1 __v1) (exists st_ins (2 0 1) 1 __tconst7cMm457) (exists st_ins_ans (0 1) 1 __t7DB2460) (join _enum (1 0) 1 __tconst19LZ687 __t82EP455) (exists st_ins (1 2 0) 2 __t82EP455 __tconst5Crw454) (join st_ins (1 2 0) 2 __t82EP455 __tconst6nio451 __t6TRN453) (exists st_ins_ans (0 1) 1 __t6TRN453) (join st_ins (1 2 0) 2 __t82EP455 __tconst5Crw454 __t7k0a456) (join st_ins_ans (0 1) 2 __t7k0a456 __v1) (join st_ins_ans (0 1) 1 __t6TRN453 __v0) (join st_ins (1 2 0) 2 __v0 __tconst7cMm457 __t6eAo458) (join st_ins_ans (0 1) 1 __t6eAo458 a) (join st_ins_ans (0 1) 1 __t7DB2460 b)) (head (mkstruct st_union (1 2 0) __6Awq688 a b)) st_basic.slog:18 #f)
  class ReadTask15 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** st_insindex0;  slog::Index** st_insindex1;  slog::Index** st_ins_ansindex2;  slog::Index** st_insindex3;  slog::Index** st_ins_ansindex4;  slog::Index** _enumindex5;  slog::Index** st_insindex6;  slog::Index** st_insindex7;  slog::Index** st_ins_ansindex8;  slog::Index** st_insindex9;  slog::Index** st_ins_ansindex10;  slog::Index** st_ins_ansindex11;  slog::Index** st_insindex12;  slog::Index** st_ins_ansindex13;  slog::Index** st_ins_ansindex14;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_union");
      std::vector<u16> ord16({2, 0, 1});
      slog::Relation* readrel17 = db->getRelation("st_ins");
      driver_index = readrel17->getIndex(ord16, true);
      std::vector<u16> ord18({2, 0, 1});
      slog::Relation* readrel19 = db->getRelation("st_ins");
      st_insindex0 = readrel19->getIndex(ord18, false);
      std::vector<u16> ord20({2, 0, 1});
      slog::Relation* readrel21 = db->getRelation("st_ins");
      st_insindex1 = readrel21->getIndex(ord20, false);
      std::vector<u16> ord22({1, 0});
      slog::Relation* readrel23 = db->getRelation("st_ins_ans");
      st_ins_ansindex2 = readrel23->getIndex(ord22, false);
      std::vector<u16> ord24({2, 0, 1});
      slog::Relation* readrel25 = db->getRelation("st_ins");
      st_insindex3 = readrel25->getIndex(ord24, false);
      std::vector<u16> ord26({0, 1});
      slog::Relation* readrel27 = db->getRelation("st_ins_ans");
      st_ins_ansindex4 = readrel27->getIndex(ord26, false);
      std::vector<u16> ord28({1, 0});
      slog::Relation* readrel29 = db->getRelation("_enum");
      _enumindex5 = readrel29->getIndex(ord28, false);
      std::vector<u16> ord30({1, 2, 0});
      slog::Relation* readrel31 = db->getRelation("st_ins");
      st_insindex6 = readrel31->getIndex(ord30, false);
      std::vector<u16> ord32({1, 2, 0});
      slog::Relation* readrel33 = db->getRelation("st_ins");
      st_insindex7 = readrel33->getIndex(ord32, false);
      std::vector<u16> ord34({0, 1});
      slog::Relation* readrel35 = db->getRelation("st_ins_ans");
      st_ins_ansindex8 = readrel35->getIndex(ord34, false);
      std::vector<u16> ord36({1, 2, 0});
      slog::Relation* readrel37 = db->getRelation("st_ins");
      st_insindex9 = readrel37->getIndex(ord36, false);
      std::vector<u16> ord38({0, 1});
      slog::Relation* readrel39 = db->getRelation("st_ins_ans");
      st_ins_ansindex10 = readrel39->getIndex(ord38, false);
      std::vector<u16> ord40({0, 1});
      slog::Relation* readrel41 = db->getRelation("st_ins_ans");
      st_ins_ansindex11 = readrel41->getIndex(ord40, false);
      std::vector<u16> ord42({1, 2, 0});
      slog::Relation* readrel43 = db->getRelation("st_ins");
      st_insindex12 = readrel43->getIndex(ord42, false);
      std::vector<u16> ord44({0, 1});
      slog::Relation* readrel45 = db->getRelation("st_ins_ans");
      st_ins_ansindex13 = readrel45->getIndex(ord44, false);
      std::vector<u16> ord46({0, 1});
      slog::Relation* readrel47 = db->getRelation("st_ins_ans");
      st_ins_ansindex14 = readrel47->getIndex(ord46, false);
  
    }
    ReadTask15(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c1 = v_constef2d127de37b942baad06145;
      u64 v_c2 = v_constd4735e3a265e16eee03f5971;
      u64 v_c3 = v_const2c624232cdd221771294dfbb;
      u64 v_c4 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c4, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m48) {
        u64 v_c5 = m48[1];
        u64 v_c6 = m48[2];
        if (buckethash(v_c5) != bucket) return;
        if (!slog::exists_probe<3,1>(st_insindex0, std::array<u64,3>{v_c1, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex1, std::array<u64,3>{v_c2, 0, 0})) return;
        if (!slog::exists_probe<2,1>(st_ins_ansindex2, std::array<u64,2>{v_c6, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex3, std::array<u64,3>{v_c3, 0, 0})) return;
        if (!slog::exists_probe<2,1>(st_ins_ansindex4, std::array<u64,2>{v_c5, 0})) return;
        slog::join_probe<2,1>(_enumindex5, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m49) {
          u64 v_c7 = m49[1];
          if (!slog::exists_probe<3,2>(st_insindex6, std::array<u64,3>{v_c7, v_c2, 0})) return;
          slog::join_probe<3,2>(st_insindex7, std::array<u64,3>{v_c7, v_c1, 0}, [&](const std::array<u64,3>& m50) {
            u64 v_c8 = m50[2];
            if (!slog::exists_probe<2,1>(st_ins_ansindex8, std::array<u64,2>{v_c8, 0})) return;
            slog::join_probe<3,2>(st_insindex9, std::array<u64,3>{v_c7, v_c2, 0}, [&](const std::array<u64,3>& m51) {
              u64 v_c9 = m51[2];
              slog::join_probe<2,2>(st_ins_ansindex10, std::array<u64,2>{v_c9, v_c6}, [&](const std::array<u64,2>& m52) {
                slog::join_probe<2,1>(st_ins_ansindex11, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m53) {
                  u64 v_c10 = m53[1];
                  slog::join_probe<3,2>(st_insindex12, std::array<u64,3>{v_c10, v_c3, 0}, [&](const std::array<u64,3>& m54) {
                    u64 v_c11 = m54[2];
                    slog::join_probe<2,1>(st_ins_ansindex13, std::array<u64,2>{v_c11, 0}, [&](const std::array<u64,2>& m55) {
                      u64 v_c12 = m55[1];
                      slog::join_probe<2,1>(st_ins_ansindex14, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m56) {
                        u64 v_c13 = m56[1];
                        ++_fires;
                        slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c12, v_c13}, std::array<u16,3>{1, 2, 0});
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
  
      if (_fires) db->bumpFires("st_basic.slog:18", "delta:st_ins", _fires);
  
      if (!_done)
      {
        ReadTask15* _cont = new ReadTask15(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask15(db,b), false);
  // (crule (pre (let __tconst4Rwd255 const5feceb66ffc86f38d952786c)) (scan pbranch __t3lRY253 p m l r) (body (join-old st_union (1 2 0) 1 (1 2 0) __t3lRY253 __t4MB5252 __t57tc254) (join pbranch (0 1 2 3 4) 1 __t4MB5252 q n u v) (cmp lt m n) (let __t7ozQ256 (band p n)) (cmp gt __t7ozQ256 __tconst4Rwd255)) (head (emit $sup9688x117x0x0x0 (0 8 1 2 3 4 5 6 7) __t57tc254 v l m n p q r u)) set.slog:118 #f)
  class ReadTask60 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_unionindex57;  slog::Index** pbranchindex58;  slog::Index** st_uniondelta59;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x117x0x0x0");
      std::vector<u16> ord61({0, 8, 1, 2, 3, 4, 5, 6, 7});
      slog::Relation* readrel62 = db->getRelation("$sup9688x117x0x0x0");
      head_index[0] = readrel62->getIndex(ord61, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord63({1, 2, 0});
      slog::Relation* readrel64 = db->getRelation("st_union");
      st_unionindex57 = readrel64->getIndex(ord63, false);
      std::vector<u16> ord65({1, 2, 0});
      slog::Relation* readrel66 = db->getRelation("st_union");
      st_uniondelta59 = readrel66->getIndex(ord65, true);
      std::vector<u16> ord67({0, 1, 2, 3, 4});
      slog::Relation* readrel68 = db->getRelation("pbranch");
      pbranchindex58 = readrel68->getIndex(ord67, false);
  
    }
    ReadTask60(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c14 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c15 = _t[0];
        u64 v_c16 = _t[1];
        u64 v_c17 = _t[2];
        u64 v_c18 = _t[3];
        u64 v_c19 = _t[4];
        slog::join_probe_old<3,1>(st_unionindex57, st_uniondelta59, std::array<u64,3>{v_c15, 0, 0}, [&](const std::array<u64,3>& m69) {
          u64 v_c20 = m69[1]; u64 v_c21 = m69[2];
          slog::join_probe<5,1>(pbranchindex58, std::array<u64,5>{v_c20, 0, 0, 0, 0}, [&](const std::array<u64,5>& m70) {
            u64 v_c22 = m70[1]; u64 v_c23 = m70[2]; u64 v_c24 = m70[3]; u64 v_c25 = m70[4];
            u64 v_c26 = _prim_lt(db, v_c17, v_c23);
            if (v_c26 == slog_error) { slog::emit_pending_error(db, "set.slog:118"); return; }
            if (!v_c26) return;
            u64 v_c27 = _prim_band(db, v_c16, v_c23);
            if (v_c27 == slog_error) { slog::emit_pending_error(db, "set.slog:118"); return; }
            u64 v_c28 = _prim_gt(db, v_c27, v_c14);
            if (v_c28 == slog_error) { slog::emit_pending_error(db, "set.slog:118"); return; }
            if (!v_c28) return;
            ++_fires;
            slog::emit<9>(head_rel[0], head_index[0], newbatch[0], std::array<u64,9>{v_c21, v_c25, v_c18, v_c17, v_c23, v_c16, v_c22, v_c19, v_c24}, std::array<u16,9>{0, 8, 1, 2, 3, 4, 5, 6, 7});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:118", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask60* _cont = new ReadTask60(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask60(db,b), false);
  // (crule (pre (let __trid7ZXP741 constf95dfec4ee2675891829b965) (let __trel10Ao742 const94d9c4e2675ef4bd8443d499) (let __tcol76dL743 const6b86b273ff34fce19d6b804e) (let __trel4Ohi744 const66633592860a63ea6408b433) (let __tcol4wuu745 const5feceb66ffc86f38d952786c) (let __trel36Us746 const66633592860a63ea6408b433) (let __tcol9fN6747 const6b86b273ff34fce19d6b804e) (let __trel53tw748 const66633592860a63ea6408b433) (let __tcol6UpH749 constd4735e3a265e16eee03f5971) (let __trel087A750 const66633592860a63ea6408b433) (let __tcol40vf751 const4e07408562bedb8b60ce05c1)) (scan $sup9688x114x0x0x1 __d0 __d1 l m n p q r u v) (body) (head (tycheck u (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid7ZXP741 __trel10Ao742 __tcol76dL743 (1 2 3 4 0)) (tycheck p (accept int) __trid7ZXP741 __trel4Ohi744 __tcol4wuu745 (1 2 3 4 0)) (tycheck m (accept int) __trid7ZXP741 __trel36Us746 __tcol9fN6747 (1 2 3 4 0)) (tycheck l (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid7ZXP741 __trel53tw748 __tcol6UpH749 (1 2 3 4 0)) (tycheck r (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid7ZXP741 __trel087A750 __tcol40vf751 (1 2 3 4 0)) (emit-temp temp20p21276 l m p r u) (mkstruct pbranch (1 2 3 4 0) __t6qba207 p m l r)) set.slog:115 #f)
  class ReadTask76 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[7];
    slog::Index** head_index[7];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid74;  u32 sid73;  u32 sid75;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("malformed_deduction");
      head_rel[3] = db->getRelation("malformed_deduction");
      head_rel[4] = db->getRelation("malformed_deduction");
      head_rel[5] = db->getRelation("temp20p21276");
      head_rel[6] = db->getRelation("pbranch");
      outer_rel = db->getRelation("$sup9688x114x0x0x1");
      sid74 = db->getRelation("_enum")->getStructId();
      sid73 = db->getRelation("pbranch")->getStructId();
      sid75 = db->getRelation("pleaf")->getStructId();
  
    }
    ReadTask76(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c29 = v_constf95dfec4ee2675891829b965;
      u64 v_c30 = v_const94d9c4e2675ef4bd8443d499;
      u64 v_c31 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c32 = v_const66633592860a63ea6408b433;
      u64 v_c33 = v_const5feceb66ffc86f38d952786c;
      u64 v_c34 = v_const66633592860a63ea6408b433;
      u64 v_c35 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c36 = v_const66633592860a63ea6408b433;
      u64 v_c37 = v_constd4735e3a265e16eee03f5971;
      u64 v_c38 = v_const66633592860a63ea6408b433;
      u64 v_c39 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[7];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
      newbatch[4] = new slog::InsertBatch();
      newbatch[5] = new slog::InsertBatch();
      newbatch[6] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c40 = _t[0];
        u64 v_c41 = _t[1];
        u64 v_c18 = _t[2];
        u64 v_c17 = _t[3];
        u64 v_c23 = _t[4];
        u64 v_c16 = _t[5];
        u64 v_c22 = _t[6];
        u64 v_c19 = _t[7];
        u64 v_c24 = _t[8];
        u64 v_c25 = _t[9];
        ++_fires;
        if (!((is_struct(v_c24) && (decode_struct_id(v_c24) == sid73 || decode_struct_id(v_c24) == sid74 || decode_struct_id(v_c24) == sid75))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c29, v_c30, v_c31, v_c24}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c16)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c29, v_c32, v_c33, v_c16}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c17)))
        {
          slog::emit_struct<5>(head_rel[2], newbatch[2], std::array<u64,4>{v_c29, v_c34, v_c35, v_c17}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c18) && (decode_struct_id(v_c18) == sid73 || decode_struct_id(v_c18) == sid74 || decode_struct_id(v_c18) == sid75))))
        {
          slog::emit_struct<5>(head_rel[3], newbatch[3], std::array<u64,4>{v_c29, v_c36, v_c37, v_c18}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c19) && (decode_struct_id(v_c19) == sid73 || decode_struct_id(v_c19) == sid74 || decode_struct_id(v_c19) == sid75))))
        {
          slog::emit_struct<5>(head_rel[4], newbatch[4], std::array<u64,4>{v_c29, v_c38, v_c39, v_c19}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_temp<5>(head_rel[5], newbatch[5], std::array<u64,5>{v_c18, v_c17, v_c16, v_c19, v_c24});
        slog::emit_struct<5>(head_rel[6], newbatch[6], std::array<u64,4>{v_c16, v_c17, v_c18, v_c19}, std::array<u16,5>{1, 2, 3, 4, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
        head_rel[5]->sendBatch(newbatch[5]);
        head_rel[6]->sendBatch(newbatch[6]);
  
      if (_fires) db->bumpFires("set.slog:115", "delta:$sup9688x114x0x0x1", _fires);
  
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
  // (crule (pre (let __tconst9YUA1125 conste3776bfed7f405de8017ecfa) (let __tconst7TTg43 constef2d127de37b942baad06145) (let __tconst35F246 const2c624232cdd221771294dfbb) (let __tconst0QyJ48 constd4735e3a265e16eee03f5971) (let __tconst6ZQr51 const6b86b273ff34fce19d6b804e)) (scan st_ins_ans __t3nMl50 __v1) (body (exists _enum (1 0) 1 __tconst9YUA1125) (exists st_ins (2 0 1) 1 __tconst7TTg43) (exists st_ins (1 2 0) 2 __v1 __tconst6ZQr51) (exists st_ins (2 0 1) 1 __tconst35F246) (join-old st_ins (0 2 1) 2 (0 2 1) __t3nMl50 __tconst0QyJ48 __t7Lp349) (join _enum (0 1) 2 __t7Lp349 __tconst9YUA1125) (join-old st_ins (1 2 0) 2 (1 2 0) __t7Lp349 __tconst7TTg43 __t8j8m45) (exists st_ins_ans (0 1) 1 __t8j8m45) (join-old st_ins (1 2 0) 2 (1 2 0) __v1 __tconst6ZQr51 __t7CuH52) (exists st_ins_ans (0 1) 1 __t7CuH52) (join st_ins_ans (0 1) 1 __t8j8m45 __v0) (join-old st_ins (1 2 0) 2 (1 2 0) __v0 __tconst35F246 __t4CDi47) (join st_ins_ans (0 1) 1 __t4CDi47 a) (exists st_union (1 2 0) 1 a) (join-old st_ins_ans (0 1) 1 (0 1) __t7CuH52 b) (join-old st_union (1 2 0) 2 (1 2 0) a b __t8gtb53) (join-old st_union_ans (0 1) 1 (0 1) __t8gtb53 r)) (head (emit canon (0) r)) st_basic.slog:18 #f)
  class ReadTask101 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex77;  slog::Index** st_insindex78;  slog::Index** st_insindex79;  slog::Index** st_insindex80;  slog::Index** st_insindex81;  slog::Index** _enumindex82;  slog::Index** st_insindex83;  slog::Index** st_ins_ansindex84;  slog::Index** st_insindex85;  slog::Index** st_ins_ansindex86;  slog::Index** st_ins_ansindex87;  slog::Index** st_insindex88;  slog::Index** st_ins_ansindex89;  slog::Index** st_unionindex90;  slog::Index** st_ins_ansindex91;  slog::Index** st_unionindex92;  slog::Index** st_union_ansindex93;  slog::Index** st_insdelta94;  slog::Index** st_insdelta95;  slog::Index** st_insdelta96;  slog::Index** st_insdelta97;  slog::Index** st_ins_ansdelta98;  slog::Index** st_uniondelta99;  slog::Index** st_union_ansdelta100;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("canon");
      std::vector<u16> ord102({0});
      slog::Relation* readrel103 = db->getRelation("canon");
      head_index[0] = readrel103->getIndex(ord102, false);
      outer_rel = db->getRelation("st_ins_ans");
      std::vector<u16> ord104({1, 0});
      slog::Relation* readrel105 = db->getRelation("_enum");
      _enumindex77 = readrel105->getIndex(ord104, false);
      std::vector<u16> ord106({2, 0, 1});
      slog::Relation* readrel107 = db->getRelation("st_ins");
      st_insindex78 = readrel107->getIndex(ord106, false);
      std::vector<u16> ord108({1, 2, 0});
      slog::Relation* readrel109 = db->getRelation("st_ins");
      st_insindex79 = readrel109->getIndex(ord108, false);
      std::vector<u16> ord110({2, 0, 1});
      slog::Relation* readrel111 = db->getRelation("st_ins");
      st_insindex80 = readrel111->getIndex(ord110, false);
      std::vector<u16> ord112({0, 2, 1});
      slog::Relation* readrel113 = db->getRelation("st_ins");
      st_insindex81 = readrel113->getIndex(ord112, false);
      std::vector<u16> ord114({0, 2, 1});
      slog::Relation* readrel115 = db->getRelation("st_ins");
      st_insdelta94 = readrel115->getIndex(ord114, true);
      std::vector<u16> ord116({0, 1});
      slog::Relation* readrel117 = db->getRelation("_enum");
      _enumindex82 = readrel117->getIndex(ord116, false);
      std::vector<u16> ord118({1, 2, 0});
      slog::Relation* readrel119 = db->getRelation("st_ins");
      st_insindex83 = readrel119->getIndex(ord118, false);
      std::vector<u16> ord120({1, 2, 0});
      slog::Relation* readrel121 = db->getRelation("st_ins");
      st_insdelta95 = readrel121->getIndex(ord120, true);
      std::vector<u16> ord122({0, 1});
      slog::Relation* readrel123 = db->getRelation("st_ins_ans");
      st_ins_ansindex84 = readrel123->getIndex(ord122, false);
      std::vector<u16> ord124({1, 2, 0});
      slog::Relation* readrel125 = db->getRelation("st_ins");
      st_insindex85 = readrel125->getIndex(ord124, false);
      std::vector<u16> ord126({1, 2, 0});
      slog::Relation* readrel127 = db->getRelation("st_ins");
      st_insdelta96 = readrel127->getIndex(ord126, true);
      std::vector<u16> ord128({0, 1});
      slog::Relation* readrel129 = db->getRelation("st_ins_ans");
      st_ins_ansindex86 = readrel129->getIndex(ord128, false);
      std::vector<u16> ord130({0, 1});
      slog::Relation* readrel131 = db->getRelation("st_ins_ans");
      st_ins_ansindex87 = readrel131->getIndex(ord130, false);
      std::vector<u16> ord132({1, 2, 0});
      slog::Relation* readrel133 = db->getRelation("st_ins");
      st_insindex88 = readrel133->getIndex(ord132, false);
      std::vector<u16> ord134({1, 2, 0});
      slog::Relation* readrel135 = db->getRelation("st_ins");
      st_insdelta97 = readrel135->getIndex(ord134, true);
      std::vector<u16> ord136({0, 1});
      slog::Relation* readrel137 = db->getRelation("st_ins_ans");
      st_ins_ansindex89 = readrel137->getIndex(ord136, false);
      std::vector<u16> ord138({1, 2, 0});
      slog::Relation* readrel139 = db->getRelation("st_union");
      st_unionindex90 = readrel139->getIndex(ord138, false);
      std::vector<u16> ord140({0, 1});
      slog::Relation* readrel141 = db->getRelation("st_ins_ans");
      st_ins_ansindex91 = readrel141->getIndex(ord140, false);
      std::vector<u16> ord142({0, 1});
      slog::Relation* readrel143 = db->getRelation("st_ins_ans");
      st_ins_ansdelta98 = readrel143->getIndex(ord142, true);
      std::vector<u16> ord144({1, 2, 0});
      slog::Relation* readrel145 = db->getRelation("st_union");
      st_unionindex92 = readrel145->getIndex(ord144, false);
      std::vector<u16> ord146({1, 2, 0});
      slog::Relation* readrel147 = db->getRelation("st_union");
      st_uniondelta99 = readrel147->getIndex(ord146, true);
      std::vector<u16> ord148({0, 1});
      slog::Relation* readrel149 = db->getRelation("st_union_ans");
      st_union_ansindex93 = readrel149->getIndex(ord148, false);
      std::vector<u16> ord150({0, 1});
      slog::Relation* readrel151 = db->getRelation("st_union_ans");
      st_union_ansdelta100 = readrel151->getIndex(ord150, true);
  
    }
    ReadTask101(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c42 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c43 = v_constef2d127de37b942baad06145;
      u64 v_c44 = v_const2c624232cdd221771294dfbb;
      u64 v_c45 = v_constd4735e3a265e16eee03f5971;
      u64 v_c46 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c47 = _t[0];
        u64 v_c6 = _t[1];
        if (!slog::exists_probe<2,1>(_enumindex77, std::array<u64,2>{v_c42, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex78, std::array<u64,3>{v_c43, 0, 0})) return;
        if (!slog::exists_probe<3,2>(st_insindex79, std::array<u64,3>{v_c6, v_c46, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex80, std::array<u64,3>{v_c44, 0, 0})) return;
        slog::join_probe_old<3,2>(st_insindex81, st_insdelta94, std::array<u64,3>{v_c47, v_c45, 0}, [&](const std::array<u64,3>& m152) {
          u64 v_c48 = m152[2];
          slog::join_probe<2,2>(_enumindex82, std::array<u64,2>{v_c48, v_c42}, [&](const std::array<u64,2>& m153) {
            slog::join_probe_old<3,2>(st_insindex83, st_insdelta95, std::array<u64,3>{v_c48, v_c43, 0}, [&](const std::array<u64,3>& m154) {
              u64 v_c49 = m154[2];
              if (!slog::exists_probe<2,1>(st_ins_ansindex84, std::array<u64,2>{v_c49, 0})) return;
              slog::join_probe_old<3,2>(st_insindex85, st_insdelta96, std::array<u64,3>{v_c6, v_c46, 0}, [&](const std::array<u64,3>& m155) {
                u64 v_c50 = m155[2];
                if (!slog::exists_probe<2,1>(st_ins_ansindex86, std::array<u64,2>{v_c50, 0})) return;
                slog::join_probe<2,1>(st_ins_ansindex87, std::array<u64,2>{v_c49, 0}, [&](const std::array<u64,2>& m156) {
                  u64 v_c10 = m156[1];
                  slog::join_probe_old<3,2>(st_insindex88, st_insdelta97, std::array<u64,3>{v_c10, v_c44, 0}, [&](const std::array<u64,3>& m157) {
                    u64 v_c51 = m157[2];
                    slog::join_probe<2,1>(st_ins_ansindex89, std::array<u64,2>{v_c51, 0}, [&](const std::array<u64,2>& m158) {
                      u64 v_c12 = m158[1];
                      if (!slog::exists_probe<3,1>(st_unionindex90, std::array<u64,3>{v_c12, 0, 0})) return;
                      slog::join_probe_old<2,1>(st_ins_ansindex91, st_ins_ansdelta98, std::array<u64,2>{v_c50, 0}, [&](const std::array<u64,2>& m159) {
                        u64 v_c13 = m159[1];
                        slog::join_probe_old<3,2>(st_unionindex92, st_uniondelta99, std::array<u64,3>{v_c12, v_c13, 0}, [&](const std::array<u64,3>& m160) {
                          u64 v_c52 = m160[2];
                          slog::join_probe_old<2,1>(st_union_ansindex93, st_union_ansdelta100, std::array<u64,2>{v_c52, 0}, [&](const std::array<u64,2>& m161) {
                            u64 v_c19 = m161[1];
                            ++_fires;
                            slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c19}, std::array<u16,1>{0});
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
  
      if (_fires) db->bumpFires("st_basic.slog:18", "delta:st_ins_ans", _fires);
  
      if (!_done)
      {
        ReadTask101* _cont = new ReadTask101(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask101(db,b), false);
  // (crule (pre (let __tconst63YF62 const6b86b273ff34fce19d6b804e)) (scan st_union __t2j0W61 __t5Obr65 __t2ifW59) (body (exists $sup9688x114x0x0x0 (0 7 1 2 3 4 5 6 8) 1 __t2j0W61) (exists $sup9688x114x0x0x1 (0 8 1 2 3 4 5 6 7 9) 1 __t2j0W61) (join-old st_union (1 2 0) 1 (1 2 0) __t5Obr65 u __t6dzp66) (exists $sup9688x114x0x0x0 (0 7 1 2 3 4 5 6 8) 2 __t2j0W61 u) (exists $sup9688x114x0x0x1 (0 8 1 2 3 4 5 6 7 9) 2 __t2j0W61 u) (exists st_union_ans (0 1) 1 __t6dzp66) (join pbranch (3 0 1 2 4) 2 u __t2ifW59 q n v) (exists $sup9688x114x0x0x1 (8 4 6 9 0 2 3 5 7 1) 5 u n q v __t2j0W61) (exists st_msk (2 0 1) 1 n) (exists st_msk_ans (1 0) 1 q) (join $sup9688x114x0x0x0 (5 3 7 8 0 1 2 4 6) 5 q n u v __t2j0W61 l m p r) (cmp lt m n) (exists pbranch (1 2 3 4 0) 5 p m l r __t5Obr65) (exists st_msk (1 2 0) 2 p n) (join $sup9688x114x0x0x1 (8 4 6 9 0 2 3 5 7 1) 9 u n q v __t2j0W61 l m p r __t1Zy964) (join-old pbranch (1 2 3 4 0) 5 (1 2 3 4 0) p m l r __t5Obr65) (join-old st_msk (1 2 0) 3 (1 2 0) p n __t1Zy964) (join st_msk_ans (0 1) 2 __t1Zy964 q) (join st_union_ans (0 1) 1 __t6dzp66 __v0) (let __t3h5j63 (band p n)) (cmp lt __t3h5j63 __tconst63YF62)) (head (emit-temp temp1Dk71281 __t2j0W61 __v0 n q v) (mkstruct pbranch (1 2 3 4 0) __t0srE58 q n __v0 v)) set.slog:115 #f)
  class ReadTask183 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x114x0x0x0index162;  slog::Index** $sup9688x114x0x0x1index163;  slog::Index** st_unionindex164;  slog::Index** $sup9688x114x0x0x0index165;  slog::Index** $sup9688x114x0x0x1index166;  slog::Index** st_union_ansindex167;  slog::Index** pbranchindex168;  slog::Index** $sup9688x114x0x0x1index169;  slog::Index** st_mskindex170;  slog::Index** st_msk_ansindex171;  slog::Index** $sup9688x114x0x0x0index172;  slog::Index** pbranchindex173;  slog::Index** st_mskindex174;  slog::Index** $sup9688x114x0x0x1index175;  slog::Index** pbranchindex176;  slog::Index** st_mskindex177;  slog::Index** st_msk_ansindex178;  slog::Index** st_union_ansindex179;  slog::Index** st_uniondelta180;  slog::Index** pbranchdelta181;  slog::Index** st_mskdelta182;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp1Dk71281");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("st_union");
      std::vector<u16> ord184({0, 7, 1, 2, 3, 4, 5, 6, 8});
      slog::Relation* readrel185 = db->getRelation("$sup9688x114x0x0x0");
      $sup9688x114x0x0x0index162 = readrel185->getIndex(ord184, false);
      std::vector<u16> ord186({0, 8, 1, 2, 3, 4, 5, 6, 7, 9});
      slog::Relation* readrel187 = db->getRelation("$sup9688x114x0x0x1");
      $sup9688x114x0x0x1index163 = readrel187->getIndex(ord186, false);
      std::vector<u16> ord188({1, 2, 0});
      slog::Relation* readrel189 = db->getRelation("st_union");
      st_unionindex164 = readrel189->getIndex(ord188, false);
      std::vector<u16> ord190({1, 2, 0});
      slog::Relation* readrel191 = db->getRelation("st_union");
      st_uniondelta180 = readrel191->getIndex(ord190, true);
      std::vector<u16> ord192({0, 7, 1, 2, 3, 4, 5, 6, 8});
      slog::Relation* readrel193 = db->getRelation("$sup9688x114x0x0x0");
      $sup9688x114x0x0x0index165 = readrel193->getIndex(ord192, false);
      std::vector<u16> ord194({0, 8, 1, 2, 3, 4, 5, 6, 7, 9});
      slog::Relation* readrel195 = db->getRelation("$sup9688x114x0x0x1");
      $sup9688x114x0x0x1index166 = readrel195->getIndex(ord194, false);
      std::vector<u16> ord196({0, 1});
      slog::Relation* readrel197 = db->getRelation("st_union_ans");
      st_union_ansindex167 = readrel197->getIndex(ord196, false);
      std::vector<u16> ord198({3, 0, 1, 2, 4});
      slog::Relation* readrel199 = db->getRelation("pbranch");
      pbranchindex168 = readrel199->getIndex(ord198, false);
      std::vector<u16> ord200({8, 4, 6, 9, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel201 = db->getRelation("$sup9688x114x0x0x1");
      $sup9688x114x0x0x1index169 = readrel201->getIndex(ord200, false);
      std::vector<u16> ord202({2, 0, 1});
      slog::Relation* readrel203 = db->getRelation("st_msk");
      st_mskindex170 = readrel203->getIndex(ord202, false);
      std::vector<u16> ord204({1, 0});
      slog::Relation* readrel205 = db->getRelation("st_msk_ans");
      st_msk_ansindex171 = readrel205->getIndex(ord204, false);
      std::vector<u16> ord206({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel207 = db->getRelation("$sup9688x114x0x0x0");
      $sup9688x114x0x0x0index172 = readrel207->getIndex(ord206, false);
      std::vector<u16> ord208({1, 2, 3, 4, 0});
      slog::Relation* readrel209 = db->getRelation("pbranch");
      pbranchindex173 = readrel209->getIndex(ord208, false);
      std::vector<u16> ord210({1, 2, 0});
      slog::Relation* readrel211 = db->getRelation("st_msk");
      st_mskindex174 = readrel211->getIndex(ord210, false);
      std::vector<u16> ord212({8, 4, 6, 9, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel213 = db->getRelation("$sup9688x114x0x0x1");
      $sup9688x114x0x0x1index175 = readrel213->getIndex(ord212, false);
      std::vector<u16> ord214({1, 2, 3, 4, 0});
      slog::Relation* readrel215 = db->getRelation("pbranch");
      pbranchindex176 = readrel215->getIndex(ord214, false);
      std::vector<u16> ord216({1, 2, 3, 4, 0});
      slog::Relation* readrel217 = db->getRelation("pbranch");
      pbranchdelta181 = readrel217->getIndex(ord216, true);
      std::vector<u16> ord218({1, 2, 0});
      slog::Relation* readrel219 = db->getRelation("st_msk");
      st_mskindex177 = readrel219->getIndex(ord218, false);
      std::vector<u16> ord220({1, 2, 0});
      slog::Relation* readrel221 = db->getRelation("st_msk");
      st_mskdelta182 = readrel221->getIndex(ord220, true);
      std::vector<u16> ord222({0, 1});
      slog::Relation* readrel223 = db->getRelation("st_msk_ans");
      st_msk_ansindex178 = readrel223->getIndex(ord222, false);
      std::vector<u16> ord224({0, 1});
      slog::Relation* readrel225 = db->getRelation("st_union_ans");
      st_union_ansindex179 = readrel225->getIndex(ord224, false);
  
    }
    ReadTask183(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c53 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c54 = _t[0];
        u64 v_c55 = _t[1];
        u64 v_c56 = _t[2];
        if (!slog::exists_probe<9,1>($sup9688x114x0x0x0index162, std::array<u64,9>{v_c54, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<10,1>($sup9688x114x0x0x1index163, std::array<u64,10>{v_c54, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(st_unionindex164, st_uniondelta180, std::array<u64,3>{v_c55, 0, 0}, [&](const std::array<u64,3>& m226) {
          u64 v_c24 = m226[1]; u64 v_c57 = m226[2];
          if (!slog::exists_probe<9,2>($sup9688x114x0x0x0index165, std::array<u64,9>{v_c54, v_c24, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<10,2>($sup9688x114x0x0x1index166, std::array<u64,10>{v_c54, v_c24, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<2,1>(st_union_ansindex167, std::array<u64,2>{v_c57, 0})) return;
          slog::join_probe<5,2>(pbranchindex168, std::array<u64,5>{v_c24, v_c56, 0, 0, 0}, [&](const std::array<u64,5>& m227) {
            u64 v_c22 = m227[2]; u64 v_c23 = m227[3]; u64 v_c25 = m227[4];
            if (!slog::exists_probe<10,5>($sup9688x114x0x0x1index169, std::array<u64,10>{v_c24, v_c23, v_c22, v_c25, v_c54, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<3,1>(st_mskindex170, std::array<u64,3>{v_c23, 0, 0})) return;
            if (!slog::exists_probe<2,1>(st_msk_ansindex171, std::array<u64,2>{v_c22, 0})) return;
            slog::join_probe<9,5>($sup9688x114x0x0x0index172, std::array<u64,9>{v_c22, v_c23, v_c24, v_c25, v_c54, 0, 0, 0, 0}, [&](const std::array<u64,9>& m228) {
              u64 v_c18 = m228[5]; u64 v_c17 = m228[6]; u64 v_c16 = m228[7]; u64 v_c19 = m228[8];
              u64 v_c58 = _prim_lt(db, v_c17, v_c23);
              if (v_c58 == slog_error) { slog::emit_pending_error(db, "set.slog:115"); return; }
              if (!v_c58) return;
              if (!slog::exists_probe<5,5>(pbranchindex173, std::array<u64,5>{v_c16, v_c17, v_c18, v_c19, v_c55})) return;
              if (!slog::exists_probe<3,2>(st_mskindex174, std::array<u64,3>{v_c16, v_c23, 0})) return;
              slog::join_probe<10,9>($sup9688x114x0x0x1index175, std::array<u64,10>{v_c24, v_c23, v_c22, v_c25, v_c54, v_c18, v_c17, v_c16, v_c19, 0}, [&](const std::array<u64,10>& m230) {
                u64 v_c59 = m230[9];
                slog::join_probe_old<5,5>(pbranchindex176, pbranchdelta181, std::array<u64,5>{v_c16, v_c17, v_c18, v_c19, v_c55}, [&](const std::array<u64,5>& m231) {
                  slog::join_probe_old<3,3>(st_mskindex177, st_mskdelta182, std::array<u64,3>{v_c16, v_c23, v_c59}, [&](const std::array<u64,3>& m232) {
                    slog::join_probe<2,2>(st_msk_ansindex178, std::array<u64,2>{v_c59, v_c22}, [&](const std::array<u64,2>& m233) {
                      slog::join_probe<2,1>(st_union_ansindex179, std::array<u64,2>{v_c57, 0}, [&](const std::array<u64,2>& m234) {
                        u64 v_c10 = m234[1];
                        u64 v_c60 = _prim_band(db, v_c16, v_c23);
                        if (v_c60 == slog_error) { slog::emit_pending_error(db, "set.slog:115"); return; }
                        u64 v_c61 = _prim_lt(db, v_c60, v_c53);
                        if (v_c61 == slog_error) { slog::emit_pending_error(db, "set.slog:115"); return; }
                        if (!v_c61) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c54, v_c10, v_c23, v_c22, v_c25});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c22, v_c23, v_c10, v_c25}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:115", "delta:st_union", _fires);
  
      if (!_done)
      {
        ReadTask183* _cont = new ReadTask183(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask183(db,b), false);
  // (crule (pre (let __trid4bDq789 const76a4fedc25549f0939d52fb7) (let __trel1o0k790 const26c89ee8ccc4ea998fd1a912) (let __tcol6PPW791 const4e07408562bedb8b60ce05c1)) (scan $sup9688x88x0x0x0 __d0 k l m p r) (body (exists st_msk_ans (1 0) 1 p) (exists st_del (1 2 0) 2 l k) (join-old st_msk (1 2 0) 2 (1 2 0) k m __t5gdG368) (join-old st_msk_ans (0 1) 2 (0 1) __t5gdG368 p) (join-old st_del (1 2 0) 2 (1 2 0) l k __t8asA369) (join-old st_del_ans (0 1) 1 (0 1) __t8asA369 __v0)) (head (tycheck r (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid4bDq789 __trel1o0k790 __tcol6PPW791 (1 2 3 4 0)) (mkstruct st_bld (1 2 3 4 0) __3BTR788 p m __v0 r)) set.slog:89 #f)
  class ReadTask249 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_msk_ansindex236;  slog::Index** st_delindex237;  slog::Index** st_mskindex238;  slog::Index** st_msk_ansindex239;  slog::Index** st_delindex240;  slog::Index** st_del_ansindex241;  slog::Index** st_mskdelta242;  slog::Index** st_msk_ansdelta243;  slog::Index** st_deldelta244;  slog::Index** st_del_ansdelta245;
    u32 sid247;  u32 sid246;  u32 sid248;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("st_bld");
      outer_rel = db->getRelation("$sup9688x88x0x0x0");
      std::vector<u16> ord250({1, 0});
      slog::Relation* readrel251 = db->getRelation("st_msk_ans");
      st_msk_ansindex236 = readrel251->getIndex(ord250, false);
      std::vector<u16> ord252({1, 2, 0});
      slog::Relation* readrel253 = db->getRelation("st_del");
      st_delindex237 = readrel253->getIndex(ord252, false);
      std::vector<u16> ord254({1, 2, 0});
      slog::Relation* readrel255 = db->getRelation("st_msk");
      st_mskindex238 = readrel255->getIndex(ord254, false);
      std::vector<u16> ord256({1, 2, 0});
      slog::Relation* readrel257 = db->getRelation("st_msk");
      st_mskdelta242 = readrel257->getIndex(ord256, true);
      std::vector<u16> ord258({0, 1});
      slog::Relation* readrel259 = db->getRelation("st_msk_ans");
      st_msk_ansindex239 = readrel259->getIndex(ord258, false);
      std::vector<u16> ord260({0, 1});
      slog::Relation* readrel261 = db->getRelation("st_msk_ans");
      st_msk_ansdelta243 = readrel261->getIndex(ord260, true);
      std::vector<u16> ord262({1, 2, 0});
      slog::Relation* readrel263 = db->getRelation("st_del");
      st_delindex240 = readrel263->getIndex(ord262, false);
      std::vector<u16> ord264({1, 2, 0});
      slog::Relation* readrel265 = db->getRelation("st_del");
      st_deldelta244 = readrel265->getIndex(ord264, true);
      std::vector<u16> ord266({0, 1});
      slog::Relation* readrel267 = db->getRelation("st_del_ans");
      st_del_ansindex241 = readrel267->getIndex(ord266, false);
      std::vector<u16> ord268({0, 1});
      slog::Relation* readrel269 = db->getRelation("st_del_ans");
      st_del_ansdelta245 = readrel269->getIndex(ord268, true);
      sid247 = db->getRelation("_enum")->getStructId();
      sid246 = db->getRelation("pbranch")->getStructId();
      sid248 = db->getRelation("pleaf")->getStructId();
  
    }
    ReadTask249(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c62 = v_const76a4fedc25549f0939d52fb7;
      u64 v_c63 = v_const26c89ee8ccc4ea998fd1a912;
      u64 v_c64 = v_const4e07408562bedb8b60ce05c1;
  
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
        u64 v_c65 = _t[1];
        u64 v_c18 = _t[2];
        u64 v_c17 = _t[3];
        u64 v_c16 = _t[4];
        u64 v_c19 = _t[5];
        if (!slog::exists_probe<2,1>(st_msk_ansindex236, std::array<u64,2>{v_c16, 0})) return;
        if (!slog::exists_probe<3,2>(st_delindex237, std::array<u64,3>{v_c18, v_c65, 0})) return;
        slog::join_probe_old<3,2>(st_mskindex238, st_mskdelta242, std::array<u64,3>{v_c65, v_c17, 0}, [&](const std::array<u64,3>& m270) {
          u64 v_c66 = m270[2];
          slog::join_probe_old<2,2>(st_msk_ansindex239, st_msk_ansdelta243, std::array<u64,2>{v_c66, v_c16}, [&](const std::array<u64,2>& m271) {
            slog::join_probe_old<3,2>(st_delindex240, st_deldelta244, std::array<u64,3>{v_c18, v_c65, 0}, [&](const std::array<u64,3>& m272) {
              u64 v_c67 = m272[2];
              slog::join_probe_old<2,1>(st_del_ansindex241, st_del_ansdelta245, std::array<u64,2>{v_c67, 0}, [&](const std::array<u64,2>& m273) {
                u64 v_c10 = m273[1];
                ++_fires;
                if (!((is_struct(v_c19) && (decode_struct_id(v_c19) == sid246 || decode_struct_id(v_c19) == sid247 || decode_struct_id(v_c19) == sid248))))
                {
                  slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c62, v_c63, v_c64, v_c19}, std::array<u16,5>{1, 2, 3, 4, 0});
                  return;
                }
                slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c16, v_c17, v_c10, v_c19}, std::array<u16,5>{1, 2, 3, 4, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("set.slog:89", "delta:$sup9688x88x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask249* _cont = new ReadTask249(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask249(db,b), false);
  // (crule (pre (let __tconst0v7T491 const5feceb66ffc86f38d952786c)) (scan st_del_ans __t9BRr495 __v0) (body (exists st_bld (4 0 1 2 3) 1 __v0) (join-old st_del (0 2 1) 1 (0 2 1) __t9BRr495 k r) (exists pbranch (4 0 1 2 3) 1 r) (exists st_del (2 0 1) 1 k) (exists st_msk (1 2 0) 1 k) (join-old $sup9688x90x0x0x0 (1 5 0 2 3 4) 2 (1 5 0 2 3 4) k r __t3j4h490 l m p) (exists st_bld (1 2 3 4 0) 4 p m l __v0) (exists st_del (0 2 1) 2 __t3j4h490 k) (exists st_msk (1 2 0) 2 k m) (exists st_msk_ans (1 0) 1 p) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t4hkT489) (exists st_del (0 2 1) 3 __t3j4h490 k __t4hkT489) (join-old st_bld (1 2 3 4 0) 4 (1 2 3 4 0) p m l __v0 __t8CKV493) (join-old st_del (0 2 1) 3 (0 2 1) __t3j4h490 k __t4hkT489) (exists st_bld_ans (0 1) 1 __t8CKV493) (join-old st_msk (1 2 0) 2 (1 2 0) k m __t44Py494) (join st_msk_ans (0 1) 2 __t44Py494 p) (join st_bld_ans (0 1) 1 __t8CKV493 res) (let __t3zgo492 (band k m)) (cmp gt __t3zgo492 __tconst0v7T491)) (head (emit st_del_ans (0 1) __t3j4h490 res)) set.slog:91 #f)
  class ReadTask298 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_bldindex274;  slog::Index** st_delindex275;  slog::Index** pbranchindex276;  slog::Index** st_delindex277;  slog::Index** st_mskindex278;  slog::Index** $sup9688x90x0x0x0index279;  slog::Index** st_bldindex280;  slog::Index** st_delindex281;  slog::Index** st_mskindex282;  slog::Index** st_msk_ansindex283;  slog::Index** pbranchindex284;  slog::Index** st_delindex285;  slog::Index** st_bldindex286;  slog::Index** st_delindex287;  slog::Index** st_bld_ansindex288;  slog::Index** st_mskindex289;  slog::Index** st_msk_ansindex290;  slog::Index** st_bld_ansindex291;  slog::Index** st_deldelta292;  slog::Index** $sup9688x90x0x0x0delta293;  slog::Index** pbranchdelta294;  slog::Index** st_blddelta295;  slog::Index** st_deldelta296;  slog::Index** st_mskdelta297;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_del_ans");
      std::vector<u16> ord299({0, 1});
      slog::Relation* readrel300 = db->getRelation("st_del_ans");
      head_index[0] = readrel300->getIndex(ord299, false);
      outer_rel = db->getRelation("st_del_ans");
      std::vector<u16> ord301({4, 0, 1, 2, 3});
      slog::Relation* readrel302 = db->getRelation("st_bld");
      st_bldindex274 = readrel302->getIndex(ord301, false);
      std::vector<u16> ord303({0, 2, 1});
      slog::Relation* readrel304 = db->getRelation("st_del");
      st_delindex275 = readrel304->getIndex(ord303, false);
      std::vector<u16> ord305({0, 2, 1});
      slog::Relation* readrel306 = db->getRelation("st_del");
      st_deldelta292 = readrel306->getIndex(ord305, true);
      std::vector<u16> ord307({4, 0, 1, 2, 3});
      slog::Relation* readrel308 = db->getRelation("pbranch");
      pbranchindex276 = readrel308->getIndex(ord307, false);
      std::vector<u16> ord309({2, 0, 1});
      slog::Relation* readrel310 = db->getRelation("st_del");
      st_delindex277 = readrel310->getIndex(ord309, false);
      std::vector<u16> ord311({1, 2, 0});
      slog::Relation* readrel312 = db->getRelation("st_msk");
      st_mskindex278 = readrel312->getIndex(ord311, false);
      std::vector<u16> ord313({1, 5, 0, 2, 3, 4});
      slog::Relation* readrel314 = db->getRelation("$sup9688x90x0x0x0");
      $sup9688x90x0x0x0index279 = readrel314->getIndex(ord313, false);
      std::vector<u16> ord315({1, 5, 0, 2, 3, 4});
      slog::Relation* readrel316 = db->getRelation("$sup9688x90x0x0x0");
      $sup9688x90x0x0x0delta293 = readrel316->getIndex(ord315, true);
      std::vector<u16> ord317({1, 2, 3, 4, 0});
      slog::Relation* readrel318 = db->getRelation("st_bld");
      st_bldindex280 = readrel318->getIndex(ord317, false);
      std::vector<u16> ord319({0, 2, 1});
      slog::Relation* readrel320 = db->getRelation("st_del");
      st_delindex281 = readrel320->getIndex(ord319, false);
      std::vector<u16> ord321({1, 2, 0});
      slog::Relation* readrel322 = db->getRelation("st_msk");
      st_mskindex282 = readrel322->getIndex(ord321, false);
      std::vector<u16> ord323({1, 0});
      slog::Relation* readrel324 = db->getRelation("st_msk_ans");
      st_msk_ansindex283 = readrel324->getIndex(ord323, false);
      std::vector<u16> ord325({1, 2, 3, 4, 0});
      slog::Relation* readrel326 = db->getRelation("pbranch");
      pbranchindex284 = readrel326->getIndex(ord325, false);
      std::vector<u16> ord327({1, 2, 3, 4, 0});
      slog::Relation* readrel328 = db->getRelation("pbranch");
      pbranchdelta294 = readrel328->getIndex(ord327, true);
      std::vector<u16> ord329({0, 2, 1});
      slog::Relation* readrel330 = db->getRelation("st_del");
      st_delindex285 = readrel330->getIndex(ord329, false);
      std::vector<u16> ord331({1, 2, 3, 4, 0});
      slog::Relation* readrel332 = db->getRelation("st_bld");
      st_bldindex286 = readrel332->getIndex(ord331, false);
      std::vector<u16> ord333({1, 2, 3, 4, 0});
      slog::Relation* readrel334 = db->getRelation("st_bld");
      st_blddelta295 = readrel334->getIndex(ord333, true);
      std::vector<u16> ord335({0, 2, 1});
      slog::Relation* readrel336 = db->getRelation("st_del");
      st_delindex287 = readrel336->getIndex(ord335, false);
      std::vector<u16> ord337({0, 2, 1});
      slog::Relation* readrel338 = db->getRelation("st_del");
      st_deldelta296 = readrel338->getIndex(ord337, true);
      std::vector<u16> ord339({0, 1});
      slog::Relation* readrel340 = db->getRelation("st_bld_ans");
      st_bld_ansindex288 = readrel340->getIndex(ord339, false);
      std::vector<u16> ord341({1, 2, 0});
      slog::Relation* readrel342 = db->getRelation("st_msk");
      st_mskindex289 = readrel342->getIndex(ord341, false);
      std::vector<u16> ord343({1, 2, 0});
      slog::Relation* readrel344 = db->getRelation("st_msk");
      st_mskdelta297 = readrel344->getIndex(ord343, true);
      std::vector<u16> ord345({0, 1});
      slog::Relation* readrel346 = db->getRelation("st_msk_ans");
      st_msk_ansindex290 = readrel346->getIndex(ord345, false);
      std::vector<u16> ord347({0, 1});
      slog::Relation* readrel348 = db->getRelation("st_bld_ans");
      st_bld_ansindex291 = readrel348->getIndex(ord347, false);
  
    }
    ReadTask298(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c68 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c69 = _t[0];
        u64 v_c10 = _t[1];
        if (!slog::exists_probe<5,1>(st_bldindex274, std::array<u64,5>{v_c10, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(st_delindex275, st_deldelta292, std::array<u64,3>{v_c69, 0, 0}, [&](const std::array<u64,3>& m349) {
          u64 v_c65 = m349[1]; u64 v_c19 = m349[2];
          if (!slog::exists_probe<5,1>(pbranchindex276, std::array<u64,5>{v_c19, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(st_delindex277, std::array<u64,3>{v_c65, 0, 0})) return;
          if (!slog::exists_probe<3,1>(st_mskindex278, std::array<u64,3>{v_c65, 0, 0})) return;
          slog::join_probe_old<6,2>($sup9688x90x0x0x0index279, $sup9688x90x0x0x0delta293, std::array<u64,6>{v_c65, v_c19, 0, 0, 0, 0}, [&](const std::array<u64,6>& m350) {
            u64 v_c70 = m350[2]; u64 v_c18 = m350[3]; u64 v_c17 = m350[4]; u64 v_c16 = m350[5];
            if (!slog::exists_probe<5,4>(st_bldindex280, std::array<u64,5>{v_c16, v_c17, v_c18, v_c10, 0})) return;
            if (!slog::exists_probe<3,2>(st_delindex281, std::array<u64,3>{v_c70, v_c65, 0})) return;
            if (!slog::exists_probe<3,2>(st_mskindex282, std::array<u64,3>{v_c65, v_c17, 0})) return;
            if (!slog::exists_probe<2,1>(st_msk_ansindex283, std::array<u64,2>{v_c16, 0})) return;
            slog::join_probe_old<5,4>(pbranchindex284, pbranchdelta294, std::array<u64,5>{v_c16, v_c17, v_c18, v_c19, 0}, [&](const std::array<u64,5>& m351) {
              u64 v_c71 = m351[4];
              if (!slog::exists_probe<3,3>(st_delindex285, std::array<u64,3>{v_c70, v_c65, v_c71})) return;
              slog::join_probe_old<5,4>(st_bldindex286, st_blddelta295, std::array<u64,5>{v_c16, v_c17, v_c18, v_c10, 0}, [&](const std::array<u64,5>& m352) {
                u64 v_c72 = m352[4];
                slog::join_probe_old<3,3>(st_delindex287, st_deldelta296, std::array<u64,3>{v_c70, v_c65, v_c71}, [&](const std::array<u64,3>& m353) {
                  if (!slog::exists_probe<2,1>(st_bld_ansindex288, std::array<u64,2>{v_c72, 0})) return;
                  slog::join_probe_old<3,2>(st_mskindex289, st_mskdelta297, std::array<u64,3>{v_c65, v_c17, 0}, [&](const std::array<u64,3>& m354) {
                    u64 v_c73 = m354[2];
                    slog::join_probe<2,2>(st_msk_ansindex290, std::array<u64,2>{v_c73, v_c16}, [&](const std::array<u64,2>& m355) {
                      slog::join_probe<2,1>(st_bld_ansindex291, std::array<u64,2>{v_c72, 0}, [&](const std::array<u64,2>& m356) {
                        u64 v_c74 = m356[1];
                        u64 v_c75 = _prim_band(db, v_c65, v_c17);
                        if (v_c75 == slog_error) { slog::emit_pending_error(db, "set.slog:91"); return; }
                        u64 v_c76 = _prim_gt(db, v_c75, v_c68);
                        if (v_c76 == slog_error) { slog::emit_pending_error(db, "set.slog:91"); return; }
                        if (!v_c76) return;
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c70, v_c74}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("set.slog:91", "delta:st_del_ans", _fires);
  
      if (!_done)
      {
        ReadTask298* _cont = new ReadTask298(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask298(db,b), false);
  // (crule (pre (let __tconst7OE6425 const5feceb66ffc86f38d952786c)) (probe st_mem0_ans (1 0) 1 __tconst7OE6425 __t32gs424) (body (join-old st_mem0 (0 1 2) 1 (0 1 2) __t32gs424 t k) (exists st_diff (2 0 1) 1 t) (join-old pleaf (1 0) 1 (1 0) k __t2KDy422) (join-old st_diff (1 2 0) 2 (1 2 0) __t2KDy422 t __t2CPR423)) (head (emit st_diff_ans (0 1) __t2CPR423 __t2KDy422)) set.slog:134 #f)
  class ReadTask365 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** st_mem0index358;  slog::Index** st_diffindex359;  slog::Index** pleafindex360;  slog::Index** st_diffindex361;  slog::Index** st_mem0delta362;  slog::Index** pleafdelta363;  slog::Index** st_diffdelta364;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord366({0, 1});
      slog::Relation* readrel367 = db->getRelation("st_diff_ans");
      head_index[0] = readrel367->getIndex(ord366, false);
      std::vector<u16> ord368({1, 0});
      slog::Relation* readrel369 = db->getRelation("st_mem0_ans");
      driver_index = readrel369->getIndex(ord368, true);
      std::vector<u16> ord370({0, 1, 2});
      slog::Relation* readrel371 = db->getRelation("st_mem0");
      st_mem0index358 = readrel371->getIndex(ord370, false);
      std::vector<u16> ord372({0, 1, 2});
      slog::Relation* readrel373 = db->getRelation("st_mem0");
      st_mem0delta362 = readrel373->getIndex(ord372, true);
      std::vector<u16> ord374({2, 0, 1});
      slog::Relation* readrel375 = db->getRelation("st_diff");
      st_diffindex359 = readrel375->getIndex(ord374, false);
      std::vector<u16> ord376({1, 0});
      slog::Relation* readrel377 = db->getRelation("pleaf");
      pleafindex360 = readrel377->getIndex(ord376, false);
      std::vector<u16> ord378({1, 0});
      slog::Relation* readrel379 = db->getRelation("pleaf");
      pleafdelta363 = readrel379->getIndex(ord378, true);
      std::vector<u16> ord380({1, 2, 0});
      slog::Relation* readrel381 = db->getRelation("st_diff");
      st_diffindex361 = readrel381->getIndex(ord380, false);
      std::vector<u16> ord382({1, 2, 0});
      slog::Relation* readrel383 = db->getRelation("st_diff");
      st_diffdelta364 = readrel383->getIndex(ord382, true);
  
    }
    ReadTask365(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c77 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c77, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m384) {
        u64 v_c78 = m384[1];
        if (buckethash(v_c78) != bucket) return;
        slog::join_probe_old<3,1>(st_mem0index358, st_mem0delta362, std::array<u64,3>{v_c78, 0, 0}, [&](const std::array<u64,3>& m385) {
          u64 v_c79 = m385[1]; u64 v_c65 = m385[2];
          if (!slog::exists_probe<3,1>(st_diffindex359, std::array<u64,3>{v_c79, 0, 0})) return;
          slog::join_probe_old<2,1>(pleafindex360, pleafdelta363, std::array<u64,2>{v_c65, 0}, [&](const std::array<u64,2>& m386) {
            u64 v_c80 = m386[1];
            slog::join_probe_old<3,2>(st_diffindex361, st_diffdelta364, std::array<u64,3>{v_c80, v_c79, 0}, [&](const std::array<u64,3>& m387) {
              u64 v_c81 = m387[2];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c81, v_c80}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:134", "delta:st_mem0_ans", _fires);
  
      if (!_done)
      {
        ReadTask365* _cont = new ReadTask365(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask365(db,b), false);
  // (crule (pre (let __tconst03UB810 conste3776bfed7f405de8017ecfa) (let __tconst71XF295 const6b86b273ff34fce19d6b804e)) (probe st_mem0_ans (1 0) 1 __tconst71XF295 __t38OP294) (body (join _enum (1 0) 1 __tconst03UB810 __t26at291) (join-old st_mem0 (0 1 2) 1 (0 1 2) __t38OP294 t k) (exists st_diff (2 0 1) 1 t) (join-old pleaf (1 0) 1 (1 0) k __t1D2a292) (join-old st_diff (1 2 0) 2 (1 2 0) __t1D2a292 t __t8FIc293)) (head (emit st_diff_ans (0 1) __t8FIc293 __t26at291)) set.slog:135 #f)
  class ReadTask396 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** _enumindex388;  slog::Index** st_mem0index389;  slog::Index** st_diffindex390;  slog::Index** pleafindex391;  slog::Index** st_diffindex392;  slog::Index** st_mem0delta393;  slog::Index** pleafdelta394;  slog::Index** st_diffdelta395;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord397({0, 1});
      slog::Relation* readrel398 = db->getRelation("st_diff_ans");
      head_index[0] = readrel398->getIndex(ord397, false);
      std::vector<u16> ord399({1, 0});
      slog::Relation* readrel400 = db->getRelation("st_mem0_ans");
      driver_index = readrel400->getIndex(ord399, true);
      std::vector<u16> ord401({1, 0});
      slog::Relation* readrel402 = db->getRelation("_enum");
      _enumindex388 = readrel402->getIndex(ord401, false);
      std::vector<u16> ord403({0, 1, 2});
      slog::Relation* readrel404 = db->getRelation("st_mem0");
      st_mem0index389 = readrel404->getIndex(ord403, false);
      std::vector<u16> ord405({0, 1, 2});
      slog::Relation* readrel406 = db->getRelation("st_mem0");
      st_mem0delta393 = readrel406->getIndex(ord405, true);
      std::vector<u16> ord407({2, 0, 1});
      slog::Relation* readrel408 = db->getRelation("st_diff");
      st_diffindex390 = readrel408->getIndex(ord407, false);
      std::vector<u16> ord409({1, 0});
      slog::Relation* readrel410 = db->getRelation("pleaf");
      pleafindex391 = readrel410->getIndex(ord409, false);
      std::vector<u16> ord411({1, 0});
      slog::Relation* readrel412 = db->getRelation("pleaf");
      pleafdelta394 = readrel412->getIndex(ord411, true);
      std::vector<u16> ord413({1, 2, 0});
      slog::Relation* readrel414 = db->getRelation("st_diff");
      st_diffindex392 = readrel414->getIndex(ord413, false);
      std::vector<u16> ord415({1, 2, 0});
      slog::Relation* readrel416 = db->getRelation("st_diff");
      st_diffdelta395 = readrel416->getIndex(ord415, true);
  
    }
    ReadTask396(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c82 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c83 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c83, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m417) {
        u64 v_c84 = m417[1];
        if (buckethash(v_c84) != bucket) return;
        slog::join_probe<2,1>(_enumindex388, std::array<u64,2>{v_c82, 0}, [&](const std::array<u64,2>& m418) {
          u64 v_c85 = m418[1];
          slog::join_probe_old<3,1>(st_mem0index389, st_mem0delta393, std::array<u64,3>{v_c84, 0, 0}, [&](const std::array<u64,3>& m419) {
            u64 v_c79 = m419[1]; u64 v_c65 = m419[2];
            if (!slog::exists_probe<3,1>(st_diffindex390, std::array<u64,3>{v_c79, 0, 0})) return;
            slog::join_probe_old<2,1>(pleafindex391, pleafdelta394, std::array<u64,2>{v_c65, 0}, [&](const std::array<u64,2>& m420) {
              u64 v_c86 = m420[1];
              slog::join_probe_old<3,2>(st_diffindex392, st_diffdelta395, std::array<u64,3>{v_c86, v_c79, 0}, [&](const std::array<u64,3>& m421) {
                u64 v_c87 = m421[2];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c87, v_c85}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:135", "delta:st_mem0_ans", _fires);
  
      if (!_done)
      {
        ReadTask396* _cont = new ReadTask396(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask396(db,b), false);
  // (crule (pre (let __tconst9YUA1125 conste3776bfed7f405de8017ecfa) (let __tconst7TTg43 constef2d127de37b942baad06145) (let __tconst35F246 const2c624232cdd221771294dfbb) (let __tconst0QyJ48 constd4735e3a265e16eee03f5971) (let __tconst6ZQr51 const6b86b273ff34fce19d6b804e)) (scan st_ins_ans __t8j8m45 __v0) (body (exists _enum (1 0) 1 __tconst9YUA1125) (exists st_ins (1 2 0) 2 __v0 __tconst35F246) (exists st_ins (2 0 1) 1 __tconst0QyJ48) (exists st_ins (2 0 1) 1 __tconst6ZQr51) (join-old st_ins (0 2 1) 2 (0 2 1) __t8j8m45 __tconst7TTg43 __t7Lp349) (join _enum (0 1) 2 __t7Lp349 __tconst9YUA1125) (exists st_ins (1 2 0) 2 __t7Lp349 __tconst0QyJ48) (join-old st_ins (1 2 0) 2 (1 2 0) __v0 __tconst35F246 __t4CDi47) (exists st_ins_ans (0 1) 1 __t4CDi47) (join-old st_ins (1 2 0) 2 (1 2 0) __t7Lp349 __tconst0QyJ48 __t3nMl50) (exists st_ins_ans (0 1) 1 __t3nMl50) (join-old st_ins_ans (0 1) 1 (0 1) __t4CDi47 a) (exists st_union (1 2 0) 1 a) (join-old st_ins_ans (0 1) 1 (0 1) __t3nMl50 __v1) (join-old st_ins (1 2 0) 2 (1 2 0) __v1 __tconst6ZQr51 __t7CuH52) (join-old st_ins_ans (0 1) 1 (0 1) __t7CuH52 b) (join-old st_union (1 2 0) 2 (1 2 0) a b __t8gtb53) (join-old st_union_ans (0 1) 1 (0 1) __t8gtb53 r)) (head (emit canon (0) r)) st_basic.slog:18 #f)
  class ReadTask449 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex422;  slog::Index** st_insindex423;  slog::Index** st_insindex424;  slog::Index** st_insindex425;  slog::Index** st_insindex426;  slog::Index** _enumindex427;  slog::Index** st_insindex428;  slog::Index** st_insindex429;  slog::Index** st_ins_ansindex430;  slog::Index** st_insindex431;  slog::Index** st_ins_ansindex432;  slog::Index** st_ins_ansindex433;  slog::Index** st_unionindex434;  slog::Index** st_ins_ansindex435;  slog::Index** st_insindex436;  slog::Index** st_ins_ansindex437;  slog::Index** st_unionindex438;  slog::Index** st_union_ansindex439;  slog::Index** st_insdelta440;  slog::Index** st_insdelta441;  slog::Index** st_insdelta442;  slog::Index** st_ins_ansdelta443;  slog::Index** st_ins_ansdelta444;  slog::Index** st_insdelta445;  slog::Index** st_ins_ansdelta446;  slog::Index** st_uniondelta447;  slog::Index** st_union_ansdelta448;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("canon");
      std::vector<u16> ord450({0});
      slog::Relation* readrel451 = db->getRelation("canon");
      head_index[0] = readrel451->getIndex(ord450, false);
      outer_rel = db->getRelation("st_ins_ans");
      std::vector<u16> ord452({1, 0});
      slog::Relation* readrel453 = db->getRelation("_enum");
      _enumindex422 = readrel453->getIndex(ord452, false);
      std::vector<u16> ord454({1, 2, 0});
      slog::Relation* readrel455 = db->getRelation("st_ins");
      st_insindex423 = readrel455->getIndex(ord454, false);
      std::vector<u16> ord456({2, 0, 1});
      slog::Relation* readrel457 = db->getRelation("st_ins");
      st_insindex424 = readrel457->getIndex(ord456, false);
      std::vector<u16> ord458({2, 0, 1});
      slog::Relation* readrel459 = db->getRelation("st_ins");
      st_insindex425 = readrel459->getIndex(ord458, false);
      std::vector<u16> ord460({0, 2, 1});
      slog::Relation* readrel461 = db->getRelation("st_ins");
      st_insindex426 = readrel461->getIndex(ord460, false);
      std::vector<u16> ord462({0, 2, 1});
      slog::Relation* readrel463 = db->getRelation("st_ins");
      st_insdelta440 = readrel463->getIndex(ord462, true);
      std::vector<u16> ord464({0, 1});
      slog::Relation* readrel465 = db->getRelation("_enum");
      _enumindex427 = readrel465->getIndex(ord464, false);
      std::vector<u16> ord466({1, 2, 0});
      slog::Relation* readrel467 = db->getRelation("st_ins");
      st_insindex428 = readrel467->getIndex(ord466, false);
      std::vector<u16> ord468({1, 2, 0});
      slog::Relation* readrel469 = db->getRelation("st_ins");
      st_insindex429 = readrel469->getIndex(ord468, false);
      std::vector<u16> ord470({1, 2, 0});
      slog::Relation* readrel471 = db->getRelation("st_ins");
      st_insdelta441 = readrel471->getIndex(ord470, true);
      std::vector<u16> ord472({0, 1});
      slog::Relation* readrel473 = db->getRelation("st_ins_ans");
      st_ins_ansindex430 = readrel473->getIndex(ord472, false);
      std::vector<u16> ord474({1, 2, 0});
      slog::Relation* readrel475 = db->getRelation("st_ins");
      st_insindex431 = readrel475->getIndex(ord474, false);
      std::vector<u16> ord476({1, 2, 0});
      slog::Relation* readrel477 = db->getRelation("st_ins");
      st_insdelta442 = readrel477->getIndex(ord476, true);
      std::vector<u16> ord478({0, 1});
      slog::Relation* readrel479 = db->getRelation("st_ins_ans");
      st_ins_ansindex432 = readrel479->getIndex(ord478, false);
      std::vector<u16> ord480({0, 1});
      slog::Relation* readrel481 = db->getRelation("st_ins_ans");
      st_ins_ansindex433 = readrel481->getIndex(ord480, false);
      std::vector<u16> ord482({0, 1});
      slog::Relation* readrel483 = db->getRelation("st_ins_ans");
      st_ins_ansdelta443 = readrel483->getIndex(ord482, true);
      std::vector<u16> ord484({1, 2, 0});
      slog::Relation* readrel485 = db->getRelation("st_union");
      st_unionindex434 = readrel485->getIndex(ord484, false);
      std::vector<u16> ord486({0, 1});
      slog::Relation* readrel487 = db->getRelation("st_ins_ans");
      st_ins_ansindex435 = readrel487->getIndex(ord486, false);
      std::vector<u16> ord488({0, 1});
      slog::Relation* readrel489 = db->getRelation("st_ins_ans");
      st_ins_ansdelta444 = readrel489->getIndex(ord488, true);
      std::vector<u16> ord490({1, 2, 0});
      slog::Relation* readrel491 = db->getRelation("st_ins");
      st_insindex436 = readrel491->getIndex(ord490, false);
      std::vector<u16> ord492({1, 2, 0});
      slog::Relation* readrel493 = db->getRelation("st_ins");
      st_insdelta445 = readrel493->getIndex(ord492, true);
      std::vector<u16> ord494({0, 1});
      slog::Relation* readrel495 = db->getRelation("st_ins_ans");
      st_ins_ansindex437 = readrel495->getIndex(ord494, false);
      std::vector<u16> ord496({0, 1});
      slog::Relation* readrel497 = db->getRelation("st_ins_ans");
      st_ins_ansdelta446 = readrel497->getIndex(ord496, true);
      std::vector<u16> ord498({1, 2, 0});
      slog::Relation* readrel499 = db->getRelation("st_union");
      st_unionindex438 = readrel499->getIndex(ord498, false);
      std::vector<u16> ord500({1, 2, 0});
      slog::Relation* readrel501 = db->getRelation("st_union");
      st_uniondelta447 = readrel501->getIndex(ord500, true);
      std::vector<u16> ord502({0, 1});
      slog::Relation* readrel503 = db->getRelation("st_union_ans");
      st_union_ansindex439 = readrel503->getIndex(ord502, false);
      std::vector<u16> ord504({0, 1});
      slog::Relation* readrel505 = db->getRelation("st_union_ans");
      st_union_ansdelta448 = readrel505->getIndex(ord504, true);
  
    }
    ReadTask449(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c42 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c43 = v_constef2d127de37b942baad06145;
      u64 v_c44 = v_const2c624232cdd221771294dfbb;
      u64 v_c45 = v_constd4735e3a265e16eee03f5971;
      u64 v_c46 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c49 = _t[0];
        u64 v_c10 = _t[1];
        if (!slog::exists_probe<2,1>(_enumindex422, std::array<u64,2>{v_c42, 0})) return;
        if (!slog::exists_probe<3,2>(st_insindex423, std::array<u64,3>{v_c10, v_c44, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex424, std::array<u64,3>{v_c45, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex425, std::array<u64,3>{v_c46, 0, 0})) return;
        slog::join_probe_old<3,2>(st_insindex426, st_insdelta440, std::array<u64,3>{v_c49, v_c43, 0}, [&](const std::array<u64,3>& m506) {
          u64 v_c48 = m506[2];
          slog::join_probe<2,2>(_enumindex427, std::array<u64,2>{v_c48, v_c42}, [&](const std::array<u64,2>& m507) {
            if (!slog::exists_probe<3,2>(st_insindex428, std::array<u64,3>{v_c48, v_c45, 0})) return;
            slog::join_probe_old<3,2>(st_insindex429, st_insdelta441, std::array<u64,3>{v_c10, v_c44, 0}, [&](const std::array<u64,3>& m508) {
              u64 v_c51 = m508[2];
              if (!slog::exists_probe<2,1>(st_ins_ansindex430, std::array<u64,2>{v_c51, 0})) return;
              slog::join_probe_old<3,2>(st_insindex431, st_insdelta442, std::array<u64,3>{v_c48, v_c45, 0}, [&](const std::array<u64,3>& m509) {
                u64 v_c47 = m509[2];
                if (!slog::exists_probe<2,1>(st_ins_ansindex432, std::array<u64,2>{v_c47, 0})) return;
                slog::join_probe_old<2,1>(st_ins_ansindex433, st_ins_ansdelta443, std::array<u64,2>{v_c51, 0}, [&](const std::array<u64,2>& m510) {
                  u64 v_c12 = m510[1];
                  if (!slog::exists_probe<3,1>(st_unionindex434, std::array<u64,3>{v_c12, 0, 0})) return;
                  slog::join_probe_old<2,1>(st_ins_ansindex435, st_ins_ansdelta444, std::array<u64,2>{v_c47, 0}, [&](const std::array<u64,2>& m511) {
                    u64 v_c6 = m511[1];
                    slog::join_probe_old<3,2>(st_insindex436, st_insdelta445, std::array<u64,3>{v_c6, v_c46, 0}, [&](const std::array<u64,3>& m512) {
                      u64 v_c50 = m512[2];
                      slog::join_probe_old<2,1>(st_ins_ansindex437, st_ins_ansdelta446, std::array<u64,2>{v_c50, 0}, [&](const std::array<u64,2>& m513) {
                        u64 v_c13 = m513[1];
                        slog::join_probe_old<3,2>(st_unionindex438, st_uniondelta447, std::array<u64,3>{v_c12, v_c13, 0}, [&](const std::array<u64,3>& m514) {
                          u64 v_c52 = m514[2];
                          slog::join_probe_old<2,1>(st_union_ansindex439, st_union_ansdelta448, std::array<u64,2>{v_c52, 0}, [&](const std::array<u64,2>& m515) {
                            u64 v_c19 = m515[1];
                            ++_fires;
                            slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c19}, std::array<u16,1>{0});
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
  
      if (_fires) db->bumpFires("st_basic.slog:18", "delta:st_ins_ans", _fires);
  
      if (!_done)
      {
        ReadTask449* _cont = new ReadTask449(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask449(db,b), false);
  // (crule (pre (let __tconst3inB738 conste3776bfed7f405de8017ecfa) (let __tconst4Wut540 const6b86b273ff34fce19d6b804e) (let __tconst5bud543 const2c624232cdd221771294dfbb) (let __tconst4ddf539 constd4735e3a265e16eee03f5971)) (scan st_ins_ans __t19Ry544 __v1) (body (exists _enum (1 0) 1 __tconst3inB738) (exists st_ins (2 0 1) 1 __tconst4Wut540) (join-old st_ins (0 2 1) 2 (0 2 1) __t19Ry544 __tconst5bud543 __v0) (exists st_ins_ans (1 0) 1 __v0) (join _enum (1 0) 1 __tconst3inB738 __t86kg541) (join-old st_ins (1 2 0) 2 (1 2 0) __t86kg541 __tconst4Wut540 __t7kvj542) (join st_ins_ans (0 1) 2 __t7kvj542 __v0)) (head (mkstruct st_ins (1 2 0) __8Yai739 __v1 __tconst4ddf539)) st_basic.slog:15 #f)
  class ReadTask525 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex516;  slog::Index** st_insindex517;  slog::Index** st_insindex518;  slog::Index** st_ins_ansindex519;  slog::Index** _enumindex520;  slog::Index** st_insindex521;  slog::Index** st_ins_ansindex522;  slog::Index** st_insdelta523;  slog::Index** st_insdelta524;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_ins");
      outer_rel = db->getRelation("st_ins_ans");
      std::vector<u16> ord526({1, 0});
      slog::Relation* readrel527 = db->getRelation("_enum");
      _enumindex516 = readrel527->getIndex(ord526, false);
      std::vector<u16> ord528({2, 0, 1});
      slog::Relation* readrel529 = db->getRelation("st_ins");
      st_insindex517 = readrel529->getIndex(ord528, false);
      std::vector<u16> ord530({0, 2, 1});
      slog::Relation* readrel531 = db->getRelation("st_ins");
      st_insindex518 = readrel531->getIndex(ord530, false);
      std::vector<u16> ord532({0, 2, 1});
      slog::Relation* readrel533 = db->getRelation("st_ins");
      st_insdelta523 = readrel533->getIndex(ord532, true);
      std::vector<u16> ord534({1, 0});
      slog::Relation* readrel535 = db->getRelation("st_ins_ans");
      st_ins_ansindex519 = readrel535->getIndex(ord534, false);
      std::vector<u16> ord536({1, 0});
      slog::Relation* readrel537 = db->getRelation("_enum");
      _enumindex520 = readrel537->getIndex(ord536, false);
      std::vector<u16> ord538({1, 2, 0});
      slog::Relation* readrel539 = db->getRelation("st_ins");
      st_insindex521 = readrel539->getIndex(ord538, false);
      std::vector<u16> ord540({1, 2, 0});
      slog::Relation* readrel541 = db->getRelation("st_ins");
      st_insdelta524 = readrel541->getIndex(ord540, true);
      std::vector<u16> ord542({0, 1});
      slog::Relation* readrel543 = db->getRelation("st_ins_ans");
      st_ins_ansindex522 = readrel543->getIndex(ord542, false);
  
    }
    ReadTask525(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c88 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c89 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c90 = v_const2c624232cdd221771294dfbb;
      u64 v_c91 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c92 = _t[0];
        u64 v_c6 = _t[1];
        if (!slog::exists_probe<2,1>(_enumindex516, std::array<u64,2>{v_c88, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex517, std::array<u64,3>{v_c89, 0, 0})) return;
        slog::join_probe_old<3,2>(st_insindex518, st_insdelta523, std::array<u64,3>{v_c92, v_c90, 0}, [&](const std::array<u64,3>& m544) {
          u64 v_c10 = m544[2];
          if (!slog::exists_probe<2,1>(st_ins_ansindex519, std::array<u64,2>{v_c10, 0})) return;
          slog::join_probe<2,1>(_enumindex520, std::array<u64,2>{v_c88, 0}, [&](const std::array<u64,2>& m545) {
            u64 v_c93 = m545[1];
            slog::join_probe_old<3,2>(st_insindex521, st_insdelta524, std::array<u64,3>{v_c93, v_c89, 0}, [&](const std::array<u64,3>& m546) {
              u64 v_c94 = m546[2];
              slog::join_probe<2,2>(st_ins_ansindex522, std::array<u64,2>{v_c94, v_c10}, [&](const std::array<u64,2>& m547) {
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c6, v_c91}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("st_basic.slog:15", "delta:st_ins_ans", _fires);
  
      if (!_done)
      {
        ReadTask525* _cont = new ReadTask525(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask525(db,b), false);
  // (crule (pre (let __tconst80a51002 conste3776bfed7f405de8017ecfa) (let __tconst87Bp297 const6b86b273ff34fce19d6b804e) (let __tconst9HiA300 const2c624232cdd221771294dfbb) (let __tconst4xiW302 constd4735e3a265e16eee03f5971) (let __tconst3GLg296 constef2d127de37b942baad06145)) (probe st_ins (2 0 1) 1 __tconst4xiW302 __t43hI303 __v1) (body (exists st_ins (2 0 1) 1 __tconst87Bp297) (exists st_ins (2 0 1) 1 __tconst9HiA300) (exists st_ins_ans (1 0) 1 __v1) (exists st_ins_ans (0 1) 1 __t43hI303) (join _enum (1 0) 1 __tconst80a51002 __t1S8l298) (join st_ins (1 2 0) 2 __t1S8l298 __tconst87Bp297 __t3icK299) (join st_ins_ans (0 1) 1 __t3icK299 __v0) (join st_ins (1 2 0) 2 __v0 __tconst9HiA300 __t8YZs301) (join st_ins_ans (0 1) 2 __t8YZs301 __v1) (join st_ins_ans (0 1) 1 __t43hI303 __v2)) (head (mkstruct st_ins (1 2 0) __6IJz1003 __v2 __tconst3GLg296)) st_basic.slog:15 #f)
  class ReadTask558 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** st_insindex548;  slog::Index** st_insindex549;  slog::Index** st_ins_ansindex550;  slog::Index** st_ins_ansindex551;  slog::Index** _enumindex552;  slog::Index** st_insindex553;  slog::Index** st_ins_ansindex554;  slog::Index** st_insindex555;  slog::Index** st_ins_ansindex556;  slog::Index** st_ins_ansindex557;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_ins");
      std::vector<u16> ord559({2, 0, 1});
      slog::Relation* readrel560 = db->getRelation("st_ins");
      driver_index = readrel560->getIndex(ord559, true);
      std::vector<u16> ord561({2, 0, 1});
      slog::Relation* readrel562 = db->getRelation("st_ins");
      st_insindex548 = readrel562->getIndex(ord561, false);
      std::vector<u16> ord563({2, 0, 1});
      slog::Relation* readrel564 = db->getRelation("st_ins");
      st_insindex549 = readrel564->getIndex(ord563, false);
      std::vector<u16> ord565({1, 0});
      slog::Relation* readrel566 = db->getRelation("st_ins_ans");
      st_ins_ansindex550 = readrel566->getIndex(ord565, false);
      std::vector<u16> ord567({0, 1});
      slog::Relation* readrel568 = db->getRelation("st_ins_ans");
      st_ins_ansindex551 = readrel568->getIndex(ord567, false);
      std::vector<u16> ord569({1, 0});
      slog::Relation* readrel570 = db->getRelation("_enum");
      _enumindex552 = readrel570->getIndex(ord569, false);
      std::vector<u16> ord571({1, 2, 0});
      slog::Relation* readrel572 = db->getRelation("st_ins");
      st_insindex553 = readrel572->getIndex(ord571, false);
      std::vector<u16> ord573({0, 1});
      slog::Relation* readrel574 = db->getRelation("st_ins_ans");
      st_ins_ansindex554 = readrel574->getIndex(ord573, false);
      std::vector<u16> ord575({1, 2, 0});
      slog::Relation* readrel576 = db->getRelation("st_ins");
      st_insindex555 = readrel576->getIndex(ord575, false);
      std::vector<u16> ord577({0, 1});
      slog::Relation* readrel578 = db->getRelation("st_ins_ans");
      st_ins_ansindex556 = readrel578->getIndex(ord577, false);
      std::vector<u16> ord579({0, 1});
      slog::Relation* readrel580 = db->getRelation("st_ins_ans");
      st_ins_ansindex557 = readrel580->getIndex(ord579, false);
  
    }
    ReadTask558(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c95 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c96 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c97 = v_const2c624232cdd221771294dfbb;
      u64 v_c98 = v_constd4735e3a265e16eee03f5971;
      u64 v_c99 = v_constef2d127de37b942baad06145;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c98, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m581) {
        u64 v_c100 = m581[1];
        u64 v_c6 = m581[2];
        if (buckethash(v_c100) != bucket) return;
        if (!slog::exists_probe<3,1>(st_insindex548, std::array<u64,3>{v_c96, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex549, std::array<u64,3>{v_c97, 0, 0})) return;
        if (!slog::exists_probe<2,1>(st_ins_ansindex550, std::array<u64,2>{v_c6, 0})) return;
        if (!slog::exists_probe<2,1>(st_ins_ansindex551, std::array<u64,2>{v_c100, 0})) return;
        slog::join_probe<2,1>(_enumindex552, std::array<u64,2>{v_c95, 0}, [&](const std::array<u64,2>& m582) {
          u64 v_c101 = m582[1];
          slog::join_probe<3,2>(st_insindex553, std::array<u64,3>{v_c101, v_c96, 0}, [&](const std::array<u64,3>& m583) {
            u64 v_c102 = m583[2];
            slog::join_probe<2,1>(st_ins_ansindex554, std::array<u64,2>{v_c102, 0}, [&](const std::array<u64,2>& m584) {
              u64 v_c10 = m584[1];
              slog::join_probe<3,2>(st_insindex555, std::array<u64,3>{v_c10, v_c97, 0}, [&](const std::array<u64,3>& m585) {
                u64 v_c103 = m585[2];
                slog::join_probe<2,2>(st_ins_ansindex556, std::array<u64,2>{v_c103, v_c6}, [&](const std::array<u64,2>& m586) {
                  slog::join_probe<2,1>(st_ins_ansindex557, std::array<u64,2>{v_c100, 0}, [&](const std::array<u64,2>& m587) {
                    u64 v_c104 = m587[1];
                    ++_fires;
                    slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c104, v_c99}, std::array<u16,3>{1, 2, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("st_basic.slog:15", "delta:st_ins", _fires);
  
      if (!_done)
      {
        ReadTask558* _cont = new ReadTask558(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask558(db,b), false);
  // (crule (pre (let _00024sqc6FSA620 const4b227777d4dd1fc61c6f884f) (let _00024sqc3Ub8621 const5feceb66ffc86f38d952786c) (let _00024sqc1TCF622 const6b86b273ff34fce19d6b804e) (let _00024sqc3FMQ623 const6b86b273ff34fce19d6b804e) (let _00024sqc41K7624 const2c624232cdd221771294dfbb) (let _00024sqc6uPA625 constd4735e3a265e16eee03f5971) (let _00024sqc9VIm626 constd4735e3a265e16eee03f5971) (let _00024sqc7Q1B627 const4e07408562bedb8b60ce05c1) (let _00024sqc4nIn628 constef2d127de37b942baad06145) (let _00024sqo09Ee630 const6b86b273ff34fce19d6b804e) (let _00024sqo5YJw629 const5feceb66ffc86f38d952786c) (let _00024sqo1RnK632 const2c624232cdd221771294dfbb) (let _00024sqo5bHs631 const6b86b273ff34fce19d6b804e) (let _00024sqo2z3g634 constd4735e3a265e16eee03f5971) (let _00024sqo0Hmn633 constd4735e3a265e16eee03f5971) (let _00024sqo7Xdh636 constef2d127de37b942baad06145) (let _00024sqo5nmm635 const4e07408562bedb8b60ce05c1) (let _00024sqo4nJm638 const6b86b273ff34fce19d6b804e) (let _00024sqo7qJs637 const4e07408562bedb8b60ce05c1) (let _00024sqo4dTI640 const2c624232cdd221771294dfbb) (let _00024sqo4MMk639 constd4735e3a265e16eee03f5971) (let _00024sqo3whL642 constd4735e3a265e16eee03f5971) (let _00024sqo9zLj641 const6b86b273ff34fce19d6b804e) (let _00024sqo1Fkt644 constef2d127de37b942baad06145) (let _00024sqo2E1m643 const5feceb66ffc86f38d952786c)) (scan st_fromlist_ans __t2iar332 r) (body (exists $seq_at (1 0 2) 2 _00024sqo5bHs631 _00024sqo1RnK632) (exists $seq_at (1 0 2) 2 _00024sqo0Hmn633 _00024sqo2z3g634) (exists $seq_at (1 0 2) 2 _00024sqo5nmm635 _00024sqo7Xdh636) (exists $seq_atr (0 1 2) 2 _00024sqo4nJm638 _00024sqo7qJs637) (exists $seq_atr (0 1 2) 2 _00024sqo4dTI640 _00024sqo4MMk639) (exists $seq_atr (0 1 2) 2 _00024sqo3whL642 _00024sqo9zLj641) (exists $seq_atr (0 1 2) 2 _00024sqo1Fkt644 _00024sqo2E1m643) (join-old $seq_at (1 0 2) 2 (1 0 2) _00024sqo5YJw629 _00024sqo09Ee630 _00024seq0) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo5bHs631 _00024sqo1RnK632 _00024seq0) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo0Hmn633 _00024sqo2z3g634 _00024seq0) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo5nmm635 _00024sqo7Xdh636 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo4nJm638 _00024sqo7qJs637 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo4dTI640 _00024sqo4MMk639 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo3whL642 _00024sqo9zLj641 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo1Fkt644 _00024sqo2E1m643 _00024seq0) (join st_fromlist (0 1) 2 __t2iar332 _00024seq0) (letp _00024sql7znl618 (aslst _00024seq0)) (let chk13pu1354 (llen _00024sql7znl618)) (eq _00024sqc6FSA620 chk13pu1354) (letp chk5PRD1355 (lref _00024sql7znl618 _00024sqc3Ub8621)) (eq _00024sqc1TCF622 chk5PRD1355) (letp chk59Bg1356 (lref _00024sql7znl618 _00024sqc3FMQ623)) (eq _00024sqc41K7624 chk59Bg1356) (letp chk9CNO1357 (lref _00024sql7znl618 _00024sqc6uPA625)) (eq _00024sqc9VIm626 chk9CNO1357) (letp chk9cCy1358 (lref _00024sql7znl618 _00024sqc7Q1B627)) (eq _00024sqc4nIn628 chk9cCy1358)) (head (emit canon (0) r)) st_basic.slog:17 #f)
  class ReadTask612 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $seq_atindex588;  slog::Index** $seq_atindex589;  slog::Index** $seq_atindex590;  slog::Index** $seq_atrindex591;  slog::Index** $seq_atrindex592;  slog::Index** $seq_atrindex593;  slog::Index** $seq_atrindex594;  slog::Index** $seq_atindex595;  slog::Index** $seq_atindex596;  slog::Index** $seq_atindex597;  slog::Index** $seq_atindex598;  slog::Index** $seq_atrindex599;  slog::Index** $seq_atrindex600;  slog::Index** $seq_atrindex601;  slog::Index** $seq_atrindex602;  slog::Index** st_fromlistindex603;  slog::Index** $seq_atdelta604;  slog::Index** $seq_atdelta605;  slog::Index** $seq_atdelta606;  slog::Index** $seq_atdelta607;  slog::Index** $seq_atrdelta608;  slog::Index** $seq_atrdelta609;  slog::Index** $seq_atrdelta610;  slog::Index** $seq_atrdelta611;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("canon");
      std::vector<u16> ord613({0});
      slog::Relation* readrel614 = db->getRelation("canon");
      head_index[0] = readrel614->getIndex(ord613, false);
      outer_rel = db->getRelation("st_fromlist_ans");
      std::vector<u16> ord615({1, 0, 2});
      slog::Relation* readrel616 = db->getRelation("$seq_at");
      $seq_atindex588 = readrel616->getIndex(ord615, false);
      std::vector<u16> ord617({1, 0, 2});
      slog::Relation* readrel618 = db->getRelation("$seq_at");
      $seq_atindex589 = readrel618->getIndex(ord617, false);
      std::vector<u16> ord619({1, 0, 2});
      slog::Relation* readrel620 = db->getRelation("$seq_at");
      $seq_atindex590 = readrel620->getIndex(ord619, false);
      std::vector<u16> ord621({0, 1, 2});
      slog::Relation* readrel622 = db->getRelation("$seq_atr");
      $seq_atrindex591 = readrel622->getIndex(ord621, false);
      std::vector<u16> ord623({0, 1, 2});
      slog::Relation* readrel624 = db->getRelation("$seq_atr");
      $seq_atrindex592 = readrel624->getIndex(ord623, false);
      std::vector<u16> ord625({0, 1, 2});
      slog::Relation* readrel626 = db->getRelation("$seq_atr");
      $seq_atrindex593 = readrel626->getIndex(ord625, false);
      std::vector<u16> ord627({0, 1, 2});
      slog::Relation* readrel628 = db->getRelation("$seq_atr");
      $seq_atrindex594 = readrel628->getIndex(ord627, false);
      std::vector<u16> ord629({1, 0, 2});
      slog::Relation* readrel630 = db->getRelation("$seq_at");
      $seq_atindex595 = readrel630->getIndex(ord629, false);
      std::vector<u16> ord631({1, 0, 2});
      slog::Relation* readrel632 = db->getRelation("$seq_at");
      $seq_atdelta604 = readrel632->getIndex(ord631, true);
      std::vector<u16> ord633({1, 0, 2});
      slog::Relation* readrel634 = db->getRelation("$seq_at");
      $seq_atindex596 = readrel634->getIndex(ord633, false);
      std::vector<u16> ord635({1, 0, 2});
      slog::Relation* readrel636 = db->getRelation("$seq_at");
      $seq_atdelta605 = readrel636->getIndex(ord635, true);
      std::vector<u16> ord637({1, 0, 2});
      slog::Relation* readrel638 = db->getRelation("$seq_at");
      $seq_atindex597 = readrel638->getIndex(ord637, false);
      std::vector<u16> ord639({1, 0, 2});
      slog::Relation* readrel640 = db->getRelation("$seq_at");
      $seq_atdelta606 = readrel640->getIndex(ord639, true);
      std::vector<u16> ord641({1, 0, 2});
      slog::Relation* readrel642 = db->getRelation("$seq_at");
      $seq_atindex598 = readrel642->getIndex(ord641, false);
      std::vector<u16> ord643({1, 0, 2});
      slog::Relation* readrel644 = db->getRelation("$seq_at");
      $seq_atdelta607 = readrel644->getIndex(ord643, true);
      std::vector<u16> ord645({0, 1, 2});
      slog::Relation* readrel646 = db->getRelation("$seq_atr");
      $seq_atrindex599 = readrel646->getIndex(ord645, false);
      std::vector<u16> ord647({0, 1, 2});
      slog::Relation* readrel648 = db->getRelation("$seq_atr");
      $seq_atrdelta608 = readrel648->getIndex(ord647, true);
      std::vector<u16> ord649({0, 1, 2});
      slog::Relation* readrel650 = db->getRelation("$seq_atr");
      $seq_atrindex600 = readrel650->getIndex(ord649, false);
      std::vector<u16> ord651({0, 1, 2});
      slog::Relation* readrel652 = db->getRelation("$seq_atr");
      $seq_atrdelta609 = readrel652->getIndex(ord651, true);
      std::vector<u16> ord653({0, 1, 2});
      slog::Relation* readrel654 = db->getRelation("$seq_atr");
      $seq_atrindex601 = readrel654->getIndex(ord653, false);
      std::vector<u16> ord655({0, 1, 2});
      slog::Relation* readrel656 = db->getRelation("$seq_atr");
      $seq_atrdelta610 = readrel656->getIndex(ord655, true);
      std::vector<u16> ord657({0, 1, 2});
      slog::Relation* readrel658 = db->getRelation("$seq_atr");
      $seq_atrindex602 = readrel658->getIndex(ord657, false);
      std::vector<u16> ord659({0, 1, 2});
      slog::Relation* readrel660 = db->getRelation("$seq_atr");
      $seq_atrdelta611 = readrel660->getIndex(ord659, true);
      std::vector<u16> ord661({0, 1});
      slog::Relation* readrel662 = db->getRelation("st_fromlist");
      st_fromlistindex603 = readrel662->getIndex(ord661, false);
  
    }
    ReadTask612(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c105 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c106 = v_const5feceb66ffc86f38d952786c;
      u64 v_c107 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c108 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c109 = v_const2c624232cdd221771294dfbb;
      u64 v_c110 = v_constd4735e3a265e16eee03f5971;
      u64 v_c111 = v_constd4735e3a265e16eee03f5971;
      u64 v_c112 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c113 = v_constef2d127de37b942baad06145;
      u64 v_c114 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c115 = v_const5feceb66ffc86f38d952786c;
      u64 v_c116 = v_const2c624232cdd221771294dfbb;
      u64 v_c117 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c118 = v_constd4735e3a265e16eee03f5971;
      u64 v_c119 = v_constd4735e3a265e16eee03f5971;
      u64 v_c120 = v_constef2d127de37b942baad06145;
      u64 v_c121 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c122 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c123 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c124 = v_const2c624232cdd221771294dfbb;
      u64 v_c125 = v_constd4735e3a265e16eee03f5971;
      u64 v_c126 = v_constd4735e3a265e16eee03f5971;
      u64 v_c127 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c128 = v_constef2d127de37b942baad06145;
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
        u64 v_c19 = _t[1];
        if (!slog::exists_probe<3,2>($seq_atindex588, std::array<u64,3>{v_c117, v_c116, 0})) return;
        if (!slog::exists_probe<3,2>($seq_atindex589, std::array<u64,3>{v_c119, v_c118, 0})) return;
        if (!slog::exists_probe<3,2>($seq_atindex590, std::array<u64,3>{v_c121, v_c120, 0})) return;
        if (!slog::exists_probe<3,2>($seq_atrindex591, std::array<u64,3>{v_c122, v_c123, 0})) return;
        if (!slog::exists_probe<3,2>($seq_atrindex592, std::array<u64,3>{v_c124, v_c125, 0})) return;
        if (!slog::exists_probe<3,2>($seq_atrindex593, std::array<u64,3>{v_c126, v_c127, 0})) return;
        if (!slog::exists_probe<3,2>($seq_atrindex594, std::array<u64,3>{v_c128, v_c129, 0})) return;
        slog::join_probe_old<3,2>($seq_atindex595, $seq_atdelta604, std::array<u64,3>{v_c115, v_c114, 0}, [&](const std::array<u64,3>& m663) {
          u64 v_c131 = m663[2];
          slog::join_probe_old<3,3>($seq_atindex596, $seq_atdelta605, std::array<u64,3>{v_c117, v_c116, v_c131}, [&](const std::array<u64,3>& m664) {
            slog::join_probe_old<3,3>($seq_atindex597, $seq_atdelta606, std::array<u64,3>{v_c119, v_c118, v_c131}, [&](const std::array<u64,3>& m665) {
              slog::join_probe_old<3,3>($seq_atindex598, $seq_atdelta607, std::array<u64,3>{v_c121, v_c120, v_c131}, [&](const std::array<u64,3>& m666) {
                slog::join_probe_old<3,3>($seq_atrindex599, $seq_atrdelta608, std::array<u64,3>{v_c122, v_c123, v_c131}, [&](const std::array<u64,3>& m667) {
                  slog::join_probe_old<3,3>($seq_atrindex600, $seq_atrdelta609, std::array<u64,3>{v_c124, v_c125, v_c131}, [&](const std::array<u64,3>& m668) {
                    slog::join_probe_old<3,3>($seq_atrindex601, $seq_atrdelta610, std::array<u64,3>{v_c126, v_c127, v_c131}, [&](const std::array<u64,3>& m669) {
                      slog::join_probe_old<3,3>($seq_atrindex602, $seq_atrdelta611, std::array<u64,3>{v_c128, v_c129, v_c131}, [&](const std::array<u64,3>& m670) {
                        slog::join_probe<2,2>(st_fromlistindex603, std::array<u64,2>{v_c130, v_c131}, [&](const std::array<u64,2>& m671) {
                          bool ok672 = true;
                          u64 v_c132 = _prim_aslst(db, v_c131, &ok672);
                          if (!ok672) return;
                          u64 v_c133 = _prim_llen(db, v_c132);
                          if (v_c133 == slog_error) { slog::emit_pending_error(db, "st_basic.slog:17"); return; }
                          if (v_c105 != v_c133) return;
                          bool ok673 = true;
                          u64 v_c134 = _prim_lref(db, v_c132, v_c106, &ok673);
                          if (!ok673) return;
                          if (v_c107 != v_c134) return;
                          bool ok674 = true;
                          u64 v_c135 = _prim_lref(db, v_c132, v_c108, &ok674);
                          if (!ok674) return;
                          if (v_c109 != v_c135) return;
                          bool ok675 = true;
                          u64 v_c136 = _prim_lref(db, v_c132, v_c110, &ok675);
                          if (!ok675) return;
                          if (v_c111 != v_c136) return;
                          bool ok676 = true;
                          u64 v_c137 = _prim_lref(db, v_c132, v_c112, &ok676);
                          if (!ok676) return;
                          if (v_c113 != v_c137) return;
                          ++_fires;
                          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c19}, std::array<u16,1>{0});
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
  
      if (_fires) db->bumpFires("st_basic.slog:17", "delta:st_fromlist_ans", _fires);
  
      if (!_done)
      {
        ReadTask612* _cont = new ReadTask612(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask612(db,b), false);
  // (crule (pre (let __tconst0x19246 const6b86b273ff34fce19d6b804e)) (scan st_union_ans __t4eoh250 __v0) (body (join-old st_union (0 1 2) 1 (0 1 2) __t4eoh250 l __t8HsZ249) (exists pbranch (3 0 1 2 4) 1 l) (exists $sup9688x103x0x0x0 (1 2 4 6 0 3 5 7 8) 1 l) (exists $sup9688x103x0x0x1 (2 3 5 7 0 4 6 8 9 1) 1 l) (join-old st_union (2 0 1) 1 (2 0 1) __t8HsZ249 __t3N33245 __t2RvE244) (exists $sup9688x103x0x0x0 (0 1 2 3 4 5 6 7 8) 2 __t3N33245 l) (exists $sup9688x103x0x0x1 (0 2 1 3 4 5 6 7 8 9) 2 __t3N33245 l) (join-old pbranch (3 0 1 2 4) 2 (3 0 1 2 4) l __t2RvE244 p m r) (exists $sup9688x103x0x0x1 (2 3 5 7 0 4 6 8 9 1) 5 l m p r __t3N33245) (exists st_msk (2 0 1) 1 m) (exists st_msk_ans (1 0) 1 p) (join-old $sup9688x103x0x0x0 (1 2 4 6 0 3 5 7 8) 5 (1 2 4 6 0 3 5 7 8) l m p r __t3N33245 n q u v) (cmp lt n m) (exists pbranch (1 2 3 4 0) 5 q n u v __t8HsZ249) (exists st_msk (1 2 0) 2 q m) (join-old $sup9688x103x0x0x1 (2 3 5 7 0 4 6 8 9 1) 9 (2 3 5 7 0 4 6 8 9 1) l m p r __t3N33245 n q u v __t3q0j248) (join-old pbranch (1 2 3 4 0) 5 (1 2 3 4 0) q n u v __t8HsZ249) (join-old st_msk (1 2 0) 3 (1 2 0) q m __t3q0j248) (join st_msk_ans (0 1) 2 __t3q0j248 p) (let __t1j57247 (band q m)) (cmp lt __t1j57247 __tconst0x19246)) (head (emit-temp temp9eaB1343 __t3N33245 __v0 m p r) (mkstruct pbranch (1 2 3 4 0) __t2omG242 p m __v0 r)) set.slog:104 #f)
  class ReadTask702 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_unionindex677;  slog::Index** pbranchindex678;  slog::Index** $sup9688x103x0x0x0index679;  slog::Index** $sup9688x103x0x0x1index680;  slog::Index** st_unionindex681;  slog::Index** $sup9688x103x0x0x0index682;  slog::Index** $sup9688x103x0x0x1index683;  slog::Index** pbranchindex684;  slog::Index** $sup9688x103x0x0x1index685;  slog::Index** st_mskindex686;  slog::Index** st_msk_ansindex687;  slog::Index** $sup9688x103x0x0x0index688;  slog::Index** pbranchindex689;  slog::Index** st_mskindex690;  slog::Index** $sup9688x103x0x0x1index691;  slog::Index** pbranchindex692;  slog::Index** st_mskindex693;  slog::Index** st_msk_ansindex694;  slog::Index** st_uniondelta695;  slog::Index** st_uniondelta696;  slog::Index** pbranchdelta697;  slog::Index** $sup9688x103x0x0x0delta698;  slog::Index** $sup9688x103x0x0x1delta699;  slog::Index** pbranchdelta700;  slog::Index** st_mskdelta701;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9eaB1343");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("st_union_ans");
      std::vector<u16> ord703({0, 1, 2});
      slog::Relation* readrel704 = db->getRelation("st_union");
      st_unionindex677 = readrel704->getIndex(ord703, false);
      std::vector<u16> ord705({0, 1, 2});
      slog::Relation* readrel706 = db->getRelation("st_union");
      st_uniondelta695 = readrel706->getIndex(ord705, true);
      std::vector<u16> ord707({3, 0, 1, 2, 4});
      slog::Relation* readrel708 = db->getRelation("pbranch");
      pbranchindex678 = readrel708->getIndex(ord707, false);
      std::vector<u16> ord709({1, 2, 4, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel710 = db->getRelation("$sup9688x103x0x0x0");
      $sup9688x103x0x0x0index679 = readrel710->getIndex(ord709, false);
      std::vector<u16> ord711({2, 3, 5, 7, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel712 = db->getRelation("$sup9688x103x0x0x1");
      $sup9688x103x0x0x1index680 = readrel712->getIndex(ord711, false);
      std::vector<u16> ord713({2, 0, 1});
      slog::Relation* readrel714 = db->getRelation("st_union");
      st_unionindex681 = readrel714->getIndex(ord713, false);
      std::vector<u16> ord715({2, 0, 1});
      slog::Relation* readrel716 = db->getRelation("st_union");
      st_uniondelta696 = readrel716->getIndex(ord715, true);
      std::vector<u16> ord717({0, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel718 = db->getRelation("$sup9688x103x0x0x0");
      $sup9688x103x0x0x0index682 = readrel718->getIndex(ord717, false);
      std::vector<u16> ord719({0, 2, 1, 3, 4, 5, 6, 7, 8, 9});
      slog::Relation* readrel720 = db->getRelation("$sup9688x103x0x0x1");
      $sup9688x103x0x0x1index683 = readrel720->getIndex(ord719, false);
      std::vector<u16> ord721({3, 0, 1, 2, 4});
      slog::Relation* readrel722 = db->getRelation("pbranch");
      pbranchindex684 = readrel722->getIndex(ord721, false);
      std::vector<u16> ord723({3, 0, 1, 2, 4});
      slog::Relation* readrel724 = db->getRelation("pbranch");
      pbranchdelta697 = readrel724->getIndex(ord723, true);
      std::vector<u16> ord725({2, 3, 5, 7, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel726 = db->getRelation("$sup9688x103x0x0x1");
      $sup9688x103x0x0x1index685 = readrel726->getIndex(ord725, false);
      std::vector<u16> ord727({2, 0, 1});
      slog::Relation* readrel728 = db->getRelation("st_msk");
      st_mskindex686 = readrel728->getIndex(ord727, false);
      std::vector<u16> ord729({1, 0});
      slog::Relation* readrel730 = db->getRelation("st_msk_ans");
      st_msk_ansindex687 = readrel730->getIndex(ord729, false);
      std::vector<u16> ord731({1, 2, 4, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel732 = db->getRelation("$sup9688x103x0x0x0");
      $sup9688x103x0x0x0index688 = readrel732->getIndex(ord731, false);
      std::vector<u16> ord733({1, 2, 4, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel734 = db->getRelation("$sup9688x103x0x0x0");
      $sup9688x103x0x0x0delta698 = readrel734->getIndex(ord733, true);
      std::vector<u16> ord735({1, 2, 3, 4, 0});
      slog::Relation* readrel736 = db->getRelation("pbranch");
      pbranchindex689 = readrel736->getIndex(ord735, false);
      std::vector<u16> ord737({1, 2, 0});
      slog::Relation* readrel738 = db->getRelation("st_msk");
      st_mskindex690 = readrel738->getIndex(ord737, false);
      std::vector<u16> ord739({2, 3, 5, 7, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel740 = db->getRelation("$sup9688x103x0x0x1");
      $sup9688x103x0x0x1index691 = readrel740->getIndex(ord739, false);
      std::vector<u16> ord741({2, 3, 5, 7, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel742 = db->getRelation("$sup9688x103x0x0x1");
      $sup9688x103x0x0x1delta699 = readrel742->getIndex(ord741, true);
      std::vector<u16> ord743({1, 2, 3, 4, 0});
      slog::Relation* readrel744 = db->getRelation("pbranch");
      pbranchindex692 = readrel744->getIndex(ord743, false);
      std::vector<u16> ord745({1, 2, 3, 4, 0});
      slog::Relation* readrel746 = db->getRelation("pbranch");
      pbranchdelta700 = readrel746->getIndex(ord745, true);
      std::vector<u16> ord747({1, 2, 0});
      slog::Relation* readrel748 = db->getRelation("st_msk");
      st_mskindex693 = readrel748->getIndex(ord747, false);
      std::vector<u16> ord749({1, 2, 0});
      slog::Relation* readrel750 = db->getRelation("st_msk");
      st_mskdelta701 = readrel750->getIndex(ord749, true);
      std::vector<u16> ord751({0, 1});
      slog::Relation* readrel752 = db->getRelation("st_msk_ans");
      st_msk_ansindex694 = readrel752->getIndex(ord751, false);
  
    }
    ReadTask702(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c138 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c139 = _t[0];
        u64 v_c10 = _t[1];
        slog::join_probe_old<3,1>(st_unionindex677, st_uniondelta695, std::array<u64,3>{v_c139, 0, 0}, [&](const std::array<u64,3>& m753) {
          u64 v_c18 = m753[1]; u64 v_c140 = m753[2];
          if (!slog::exists_probe<5,1>(pbranchindex678, std::array<u64,5>{v_c18, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<9,1>($sup9688x103x0x0x0index679, std::array<u64,9>{v_c18, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<10,1>($sup9688x103x0x0x1index680, std::array<u64,10>{v_c18, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          slog::join_probe_old<3,1>(st_unionindex681, st_uniondelta696, std::array<u64,3>{v_c140, 0, 0}, [&](const std::array<u64,3>& m754) {
            u64 v_c141 = m754[1]; u64 v_c142 = m754[2];
            if (!slog::exists_probe<9,2>($sup9688x103x0x0x0index682, std::array<u64,9>{v_c141, v_c18, 0, 0, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<10,2>($sup9688x103x0x0x1index683, std::array<u64,10>{v_c141, v_c18, 0, 0, 0, 0, 0, 0, 0, 0})) return;
            slog::join_probe_old<5,2>(pbranchindex684, pbranchdelta697, std::array<u64,5>{v_c18, v_c142, 0, 0, 0}, [&](const std::array<u64,5>& m755) {
              u64 v_c16 = m755[2]; u64 v_c17 = m755[3]; u64 v_c19 = m755[4];
              if (!slog::exists_probe<10,5>($sup9688x103x0x0x1index685, std::array<u64,10>{v_c18, v_c17, v_c16, v_c19, v_c141, 0, 0, 0, 0, 0})) return;
              if (!slog::exists_probe<3,1>(st_mskindex686, std::array<u64,3>{v_c17, 0, 0})) return;
              if (!slog::exists_probe<2,1>(st_msk_ansindex687, std::array<u64,2>{v_c16, 0})) return;
              slog::join_probe_old<9,5>($sup9688x103x0x0x0index688, $sup9688x103x0x0x0delta698, std::array<u64,9>{v_c18, v_c17, v_c16, v_c19, v_c141, 0, 0, 0, 0}, [&](const std::array<u64,9>& m756) {
                u64 v_c23 = m756[5]; u64 v_c22 = m756[6]; u64 v_c24 = m756[7]; u64 v_c25 = m756[8];
                u64 v_c143 = _prim_lt(db, v_c23, v_c17);
                if (v_c143 == slog_error) { slog::emit_pending_error(db, "set.slog:104"); return; }
                if (!v_c143) return;
                if (!slog::exists_probe<5,5>(pbranchindex689, std::array<u64,5>{v_c22, v_c23, v_c24, v_c25, v_c140})) return;
                if (!slog::exists_probe<3,2>(st_mskindex690, std::array<u64,3>{v_c22, v_c17, 0})) return;
                slog::join_probe_old<10,9>($sup9688x103x0x0x1index691, $sup9688x103x0x0x1delta699, std::array<u64,10>{v_c18, v_c17, v_c16, v_c19, v_c141, v_c23, v_c22, v_c24, v_c25, 0}, [&](const std::array<u64,10>& m758) {
                  u64 v_c144 = m758[9];
                  slog::join_probe_old<5,5>(pbranchindex692, pbranchdelta700, std::array<u64,5>{v_c22, v_c23, v_c24, v_c25, v_c140}, [&](const std::array<u64,5>& m759) {
                    slog::join_probe_old<3,3>(st_mskindex693, st_mskdelta701, std::array<u64,3>{v_c22, v_c17, v_c144}, [&](const std::array<u64,3>& m760) {
                      slog::join_probe<2,2>(st_msk_ansindex694, std::array<u64,2>{v_c144, v_c16}, [&](const std::array<u64,2>& m761) {
                        u64 v_c145 = _prim_band(db, v_c22, v_c17);
                        if (v_c145 == slog_error) { slog::emit_pending_error(db, "set.slog:104"); return; }
                        u64 v_c146 = _prim_lt(db, v_c145, v_c138);
                        if (v_c146 == slog_error) { slog::emit_pending_error(db, "set.slog:104"); return; }
                        if (!v_c146) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c141, v_c10, v_c17, v_c16, v_c19});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c16, v_c17, v_c10, v_c19}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:104", "delta:st_union_ans", _fires);
  
      if (!_done)
      {
        ReadTask702* _cont = new ReadTask702(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask702(db,b), false);
  // (crule (pre (let __tconst9YUA1125 conste3776bfed7f405de8017ecfa) (let __tconst7TTg43 constef2d127de37b942baad06145) (let __tconst35F246 const2c624232cdd221771294dfbb) (let __tconst0QyJ48 constd4735e3a265e16eee03f5971) (let __tconst6ZQr51 const6b86b273ff34fce19d6b804e)) (scan st_union __t8gtb53 a b) (body (exists st_ins (2 0 1) 1 __tconst7TTg43) (exists st_ins (2 0 1) 1 __tconst0QyJ48) (exists st_ins (2 0 1) 1 __tconst35F246) (exists st_ins_ans (1 0) 1 a) (exists st_ins (2 0 1) 1 __tconst6ZQr51) (exists st_ins_ans (1 0) 1 b) (exists st_union_ans (0 1) 1 __t8gtb53) (join _enum (1 0) 1 __tconst9YUA1125 __t7Lp349) (exists st_ins (1 2 0) 2 __t7Lp349 __tconst0QyJ48) (join st_ins (1 2 0) 2 __t7Lp349 __tconst7TTg43 __t8j8m45) (exists st_ins_ans (0 1) 1 __t8j8m45) (join st_ins (1 2 0) 2 __t7Lp349 __tconst0QyJ48 __t3nMl50) (exists st_ins_ans (0 1) 1 __t3nMl50) (join st_ins_ans (0 1) 1 __t8j8m45 __v0) (join st_ins (1 2 0) 2 __v0 __tconst35F246 __t4CDi47) (join st_ins_ans (0 1) 2 __t4CDi47 a) (join st_ins_ans (0 1) 1 __t3nMl50 __v1) (join st_ins (1 2 0) 2 __v1 __tconst6ZQr51 __t7CuH52) (join st_ins_ans (0 1) 2 __t7CuH52 b) (join st_union_ans (0 1) 1 __t8gtb53 r)) (head (emit canon (0) r)) st_basic.slog:18 #f)
  class ReadTask783 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_insindex763;  slog::Index** st_insindex764;  slog::Index** st_insindex765;  slog::Index** st_ins_ansindex766;  slog::Index** st_insindex767;  slog::Index** st_ins_ansindex768;  slog::Index** st_union_ansindex769;  slog::Index** _enumindex770;  slog::Index** st_insindex771;  slog::Index** st_insindex772;  slog::Index** st_ins_ansindex773;  slog::Index** st_insindex774;  slog::Index** st_ins_ansindex775;  slog::Index** st_ins_ansindex776;  slog::Index** st_insindex777;  slog::Index** st_ins_ansindex778;  slog::Index** st_ins_ansindex779;  slog::Index** st_insindex780;  slog::Index** st_ins_ansindex781;  slog::Index** st_union_ansindex782;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("canon");
      std::vector<u16> ord784({0});
      slog::Relation* readrel785 = db->getRelation("canon");
      head_index[0] = readrel785->getIndex(ord784, false);
      outer_rel = db->getRelation("st_union");
      std::vector<u16> ord786({2, 0, 1});
      slog::Relation* readrel787 = db->getRelation("st_ins");
      st_insindex763 = readrel787->getIndex(ord786, false);
      std::vector<u16> ord788({2, 0, 1});
      slog::Relation* readrel789 = db->getRelation("st_ins");
      st_insindex764 = readrel789->getIndex(ord788, false);
      std::vector<u16> ord790({2, 0, 1});
      slog::Relation* readrel791 = db->getRelation("st_ins");
      st_insindex765 = readrel791->getIndex(ord790, false);
      std::vector<u16> ord792({1, 0});
      slog::Relation* readrel793 = db->getRelation("st_ins_ans");
      st_ins_ansindex766 = readrel793->getIndex(ord792, false);
      std::vector<u16> ord794({2, 0, 1});
      slog::Relation* readrel795 = db->getRelation("st_ins");
      st_insindex767 = readrel795->getIndex(ord794, false);
      std::vector<u16> ord796({1, 0});
      slog::Relation* readrel797 = db->getRelation("st_ins_ans");
      st_ins_ansindex768 = readrel797->getIndex(ord796, false);
      std::vector<u16> ord798({0, 1});
      slog::Relation* readrel799 = db->getRelation("st_union_ans");
      st_union_ansindex769 = readrel799->getIndex(ord798, false);
      std::vector<u16> ord800({1, 0});
      slog::Relation* readrel801 = db->getRelation("_enum");
      _enumindex770 = readrel801->getIndex(ord800, false);
      std::vector<u16> ord802({1, 2, 0});
      slog::Relation* readrel803 = db->getRelation("st_ins");
      st_insindex771 = readrel803->getIndex(ord802, false);
      std::vector<u16> ord804({1, 2, 0});
      slog::Relation* readrel805 = db->getRelation("st_ins");
      st_insindex772 = readrel805->getIndex(ord804, false);
      std::vector<u16> ord806({0, 1});
      slog::Relation* readrel807 = db->getRelation("st_ins_ans");
      st_ins_ansindex773 = readrel807->getIndex(ord806, false);
      std::vector<u16> ord808({1, 2, 0});
      slog::Relation* readrel809 = db->getRelation("st_ins");
      st_insindex774 = readrel809->getIndex(ord808, false);
      std::vector<u16> ord810({0, 1});
      slog::Relation* readrel811 = db->getRelation("st_ins_ans");
      st_ins_ansindex775 = readrel811->getIndex(ord810, false);
      std::vector<u16> ord812({0, 1});
      slog::Relation* readrel813 = db->getRelation("st_ins_ans");
      st_ins_ansindex776 = readrel813->getIndex(ord812, false);
      std::vector<u16> ord814({1, 2, 0});
      slog::Relation* readrel815 = db->getRelation("st_ins");
      st_insindex777 = readrel815->getIndex(ord814, false);
      std::vector<u16> ord816({0, 1});
      slog::Relation* readrel817 = db->getRelation("st_ins_ans");
      st_ins_ansindex778 = readrel817->getIndex(ord816, false);
      std::vector<u16> ord818({0, 1});
      slog::Relation* readrel819 = db->getRelation("st_ins_ans");
      st_ins_ansindex779 = readrel819->getIndex(ord818, false);
      std::vector<u16> ord820({1, 2, 0});
      slog::Relation* readrel821 = db->getRelation("st_ins");
      st_insindex780 = readrel821->getIndex(ord820, false);
      std::vector<u16> ord822({0, 1});
      slog::Relation* readrel823 = db->getRelation("st_ins_ans");
      st_ins_ansindex781 = readrel823->getIndex(ord822, false);
      std::vector<u16> ord824({0, 1});
      slog::Relation* readrel825 = db->getRelation("st_union_ans");
      st_union_ansindex782 = readrel825->getIndex(ord824, false);
  
    }
    ReadTask783(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c42 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c43 = v_constef2d127de37b942baad06145;
      u64 v_c44 = v_const2c624232cdd221771294dfbb;
      u64 v_c45 = v_constd4735e3a265e16eee03f5971;
      u64 v_c46 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c52 = _t[0];
        u64 v_c12 = _t[1];
        u64 v_c13 = _t[2];
        if (!slog::exists_probe<3,1>(st_insindex763, std::array<u64,3>{v_c43, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex764, std::array<u64,3>{v_c45, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex765, std::array<u64,3>{v_c44, 0, 0})) return;
        if (!slog::exists_probe<2,1>(st_ins_ansindex766, std::array<u64,2>{v_c12, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex767, std::array<u64,3>{v_c46, 0, 0})) return;
        if (!slog::exists_probe<2,1>(st_ins_ansindex768, std::array<u64,2>{v_c13, 0})) return;
        if (!slog::exists_probe<2,1>(st_union_ansindex769, std::array<u64,2>{v_c52, 0})) return;
        slog::join_probe<2,1>(_enumindex770, std::array<u64,2>{v_c42, 0}, [&](const std::array<u64,2>& m826) {
          u64 v_c48 = m826[1];
          if (!slog::exists_probe<3,2>(st_insindex771, std::array<u64,3>{v_c48, v_c45, 0})) return;
          slog::join_probe<3,2>(st_insindex772, std::array<u64,3>{v_c48, v_c43, 0}, [&](const std::array<u64,3>& m827) {
            u64 v_c49 = m827[2];
            if (!slog::exists_probe<2,1>(st_ins_ansindex773, std::array<u64,2>{v_c49, 0})) return;
            slog::join_probe<3,2>(st_insindex774, std::array<u64,3>{v_c48, v_c45, 0}, [&](const std::array<u64,3>& m828) {
              u64 v_c47 = m828[2];
              if (!slog::exists_probe<2,1>(st_ins_ansindex775, std::array<u64,2>{v_c47, 0})) return;
              slog::join_probe<2,1>(st_ins_ansindex776, std::array<u64,2>{v_c49, 0}, [&](const std::array<u64,2>& m829) {
                u64 v_c10 = m829[1];
                slog::join_probe<3,2>(st_insindex777, std::array<u64,3>{v_c10, v_c44, 0}, [&](const std::array<u64,3>& m830) {
                  u64 v_c51 = m830[2];
                  slog::join_probe<2,2>(st_ins_ansindex778, std::array<u64,2>{v_c51, v_c12}, [&](const std::array<u64,2>& m831) {
                    slog::join_probe<2,1>(st_ins_ansindex779, std::array<u64,2>{v_c47, 0}, [&](const std::array<u64,2>& m832) {
                      u64 v_c6 = m832[1];
                      slog::join_probe<3,2>(st_insindex780, std::array<u64,3>{v_c6, v_c46, 0}, [&](const std::array<u64,3>& m833) {
                        u64 v_c50 = m833[2];
                        slog::join_probe<2,2>(st_ins_ansindex781, std::array<u64,2>{v_c50, v_c13}, [&](const std::array<u64,2>& m834) {
                          slog::join_probe<2,1>(st_union_ansindex782, std::array<u64,2>{v_c52, 0}, [&](const std::array<u64,2>& m835) {
                            u64 v_c19 = m835[1];
                            ++_fires;
                            slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c19}, std::array<u16,1>{0});
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
  
      if (_fires) db->bumpFires("st_basic.slog:18", "delta:st_union", _fires);
  
      if (!_done)
      {
        ReadTask783* _cont = new ReadTask783(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask783(db,b), false);
  // (crule (pre (let _00024sqc6FSA620 const4b227777d4dd1fc61c6f884f) (let _00024sqc3Ub8621 const5feceb66ffc86f38d952786c) (let _00024sqc1TCF622 const6b86b273ff34fce19d6b804e) (let _00024sqc3FMQ623 const6b86b273ff34fce19d6b804e) (let _00024sqc41K7624 const2c624232cdd221771294dfbb) (let _00024sqc6uPA625 constd4735e3a265e16eee03f5971) (let _00024sqc9VIm626 constd4735e3a265e16eee03f5971) (let _00024sqc7Q1B627 const4e07408562bedb8b60ce05c1) (let _00024sqc4nIn628 constef2d127de37b942baad06145) (let _00024sqo09Ee630 const6b86b273ff34fce19d6b804e) (let _00024sqo5YJw629 const5feceb66ffc86f38d952786c) (let _00024sqo1RnK632 const2c624232cdd221771294dfbb) (let _00024sqo5bHs631 const6b86b273ff34fce19d6b804e) (let _00024sqo2z3g634 constd4735e3a265e16eee03f5971) (let _00024sqo0Hmn633 constd4735e3a265e16eee03f5971) (let _00024sqo7Xdh636 constef2d127de37b942baad06145) (let _00024sqo5nmm635 const4e07408562bedb8b60ce05c1) (let _00024sqo4nJm638 const6b86b273ff34fce19d6b804e) (let _00024sqo7qJs637 const4e07408562bedb8b60ce05c1) (let _00024sqo4dTI640 const2c624232cdd221771294dfbb) (let _00024sqo4MMk639 constd4735e3a265e16eee03f5971) (let _00024sqo3whL642 constd4735e3a265e16eee03f5971) (let _00024sqo9zLj641 const6b86b273ff34fce19d6b804e) (let _00024sqo1Fkt644 constef2d127de37b942baad06145) (let _00024sqo2E1m643 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 2 _00024sqo5nmm635 _00024sqo7Xdh636 _00024seq0) (body (join $seq_at (1 0 2) 3 _00024sqo5YJw629 _00024sqo09Ee630 _00024seq0) (join $seq_at (1 0 2) 3 _00024sqo5bHs631 _00024sqo1RnK632 _00024seq0) (join $seq_at (1 0 2) 3 _00024sqo0Hmn633 _00024sqo2z3g634 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo4nJm638 _00024sqo7qJs637 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo4dTI640 _00024sqo4MMk639 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo3whL642 _00024sqo9zLj641 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo1Fkt644 _00024sqo2E1m643 _00024seq0) (join st_fromlist (1 0) 1 _00024seq0 __t2iar332) (join st_fromlist_ans (0 1) 1 __t2iar332 r) (letp _00024sql7znl618 (aslst _00024seq0)) (let chk8cWB1374 (llen _00024sql7znl618)) (eq _00024sqc6FSA620 chk8cWB1374) (letp chk1WLE1375 (lref _00024sql7znl618 _00024sqc3Ub8621)) (eq _00024sqc1TCF622 chk1WLE1375) (letp chk9y0F1376 (lref _00024sql7znl618 _00024sqc3FMQ623)) (eq _00024sqc41K7624 chk9y0F1376) (letp chk5KjB1377 (lref _00024sql7znl618 _00024sqc6uPA625)) (eq _00024sqc9VIm626 chk5KjB1377) (letp chk9l5k1378 (lref _00024sql7znl618 _00024sqc7Q1B627)) (eq _00024sqc4nIn628 chk9l5k1378)) (head (emit canon (0) r)) st_basic.slog:17 #f)
  class ReadTask849 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex836;  slog::Index** $seq_atindex837;  slog::Index** $seq_atindex838;  slog::Index** $seq_atrindex839;  slog::Index** $seq_atrindex840;  slog::Index** $seq_atrindex841;  slog::Index** $seq_atrindex842;  slog::Index** st_fromlistindex843;  slog::Index** st_fromlist_ansindex844;  slog::Index** $seq_atrdelta845;  slog::Index** $seq_atrdelta846;  slog::Index** $seq_atrdelta847;  slog::Index** $seq_atrdelta848;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("canon");
      std::vector<u16> ord850({0});
      slog::Relation* readrel851 = db->getRelation("canon");
      head_index[0] = readrel851->getIndex(ord850, false);
      std::vector<u16> ord852({1, 0, 2});
      slog::Relation* readrel853 = db->getRelation("$seq_at");
      driver_index = readrel853->getIndex(ord852, true);
      std::vector<u16> ord854({1, 0, 2});
      slog::Relation* readrel855 = db->getRelation("$seq_at");
      $seq_atindex836 = readrel855->getIndex(ord854, false);
      std::vector<u16> ord856({1, 0, 2});
      slog::Relation* readrel857 = db->getRelation("$seq_at");
      $seq_atindex837 = readrel857->getIndex(ord856, false);
      std::vector<u16> ord858({1, 0, 2});
      slog::Relation* readrel859 = db->getRelation("$seq_at");
      $seq_atindex838 = readrel859->getIndex(ord858, false);
      std::vector<u16> ord860({0, 1, 2});
      slog::Relation* readrel861 = db->getRelation("$seq_atr");
      $seq_atrindex839 = readrel861->getIndex(ord860, false);
      std::vector<u16> ord862({0, 1, 2});
      slog::Relation* readrel863 = db->getRelation("$seq_atr");
      $seq_atrdelta845 = readrel863->getIndex(ord862, true);
      std::vector<u16> ord864({0, 1, 2});
      slog::Relation* readrel865 = db->getRelation("$seq_atr");
      $seq_atrindex840 = readrel865->getIndex(ord864, false);
      std::vector<u16> ord866({0, 1, 2});
      slog::Relation* readrel867 = db->getRelation("$seq_atr");
      $seq_atrdelta846 = readrel867->getIndex(ord866, true);
      std::vector<u16> ord868({0, 1, 2});
      slog::Relation* readrel869 = db->getRelation("$seq_atr");
      $seq_atrindex841 = readrel869->getIndex(ord868, false);
      std::vector<u16> ord870({0, 1, 2});
      slog::Relation* readrel871 = db->getRelation("$seq_atr");
      $seq_atrdelta847 = readrel871->getIndex(ord870, true);
      std::vector<u16> ord872({0, 1, 2});
      slog::Relation* readrel873 = db->getRelation("$seq_atr");
      $seq_atrindex842 = readrel873->getIndex(ord872, false);
      std::vector<u16> ord874({0, 1, 2});
      slog::Relation* readrel875 = db->getRelation("$seq_atr");
      $seq_atrdelta848 = readrel875->getIndex(ord874, true);
      std::vector<u16> ord876({1, 0});
      slog::Relation* readrel877 = db->getRelation("st_fromlist");
      st_fromlistindex843 = readrel877->getIndex(ord876, false);
      std::vector<u16> ord878({0, 1});
      slog::Relation* readrel879 = db->getRelation("st_fromlist_ans");
      st_fromlist_ansindex844 = readrel879->getIndex(ord878, false);
  
    }
    ReadTask849(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c105 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c106 = v_const5feceb66ffc86f38d952786c;
      u64 v_c107 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c108 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c109 = v_const2c624232cdd221771294dfbb;
      u64 v_c110 = v_constd4735e3a265e16eee03f5971;
      u64 v_c111 = v_constd4735e3a265e16eee03f5971;
      u64 v_c112 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c113 = v_constef2d127de37b942baad06145;
      u64 v_c114 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c115 = v_const5feceb66ffc86f38d952786c;
      u64 v_c116 = v_const2c624232cdd221771294dfbb;
      u64 v_c117 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c118 = v_constd4735e3a265e16eee03f5971;
      u64 v_c119 = v_constd4735e3a265e16eee03f5971;
      u64 v_c120 = v_constef2d127de37b942baad06145;
      u64 v_c121 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c122 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c123 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c124 = v_const2c624232cdd221771294dfbb;
      u64 v_c125 = v_constd4735e3a265e16eee03f5971;
      u64 v_c126 = v_constd4735e3a265e16eee03f5971;
      u64 v_c127 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c128 = v_constef2d127de37b942baad06145;
      u64 v_c129 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c121, v_c120, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m880) {
        u64 v_c131 = m880[2];
        if (buckethash(v_c131) != bucket) return;
        slog::join_probe<3,3>($seq_atindex836, std::array<u64,3>{v_c115, v_c114, v_c131}, [&](const std::array<u64,3>& m881) {
          slog::join_probe<3,3>($seq_atindex837, std::array<u64,3>{v_c117, v_c116, v_c131}, [&](const std::array<u64,3>& m882) {
            slog::join_probe<3,3>($seq_atindex838, std::array<u64,3>{v_c119, v_c118, v_c131}, [&](const std::array<u64,3>& m883) {
              slog::join_probe_old<3,3>($seq_atrindex839, $seq_atrdelta845, std::array<u64,3>{v_c122, v_c123, v_c131}, [&](const std::array<u64,3>& m884) {
                slog::join_probe_old<3,3>($seq_atrindex840, $seq_atrdelta846, std::array<u64,3>{v_c124, v_c125, v_c131}, [&](const std::array<u64,3>& m885) {
                  slog::join_probe_old<3,3>($seq_atrindex841, $seq_atrdelta847, std::array<u64,3>{v_c126, v_c127, v_c131}, [&](const std::array<u64,3>& m886) {
                    slog::join_probe_old<3,3>($seq_atrindex842, $seq_atrdelta848, std::array<u64,3>{v_c128, v_c129, v_c131}, [&](const std::array<u64,3>& m887) {
                      slog::join_probe<2,1>(st_fromlistindex843, std::array<u64,2>{v_c131, 0}, [&](const std::array<u64,2>& m888) {
                        u64 v_c130 = m888[1];
                        slog::join_probe<2,1>(st_fromlist_ansindex844, std::array<u64,2>{v_c130, 0}, [&](const std::array<u64,2>& m889) {
                          u64 v_c19 = m889[1];
                          bool ok890 = true;
                          u64 v_c132 = _prim_aslst(db, v_c131, &ok890);
                          if (!ok890) return;
                          u64 v_c147 = _prim_llen(db, v_c132);
                          if (v_c147 == slog_error) { slog::emit_pending_error(db, "st_basic.slog:17"); return; }
                          if (v_c105 != v_c147) return;
                          bool ok891 = true;
                          u64 v_c148 = _prim_lref(db, v_c132, v_c106, &ok891);
                          if (!ok891) return;
                          if (v_c107 != v_c148) return;
                          bool ok892 = true;
                          u64 v_c149 = _prim_lref(db, v_c132, v_c108, &ok892);
                          if (!ok892) return;
                          if (v_c109 != v_c149) return;
                          bool ok893 = true;
                          u64 v_c150 = _prim_lref(db, v_c132, v_c110, &ok893);
                          if (!ok893) return;
                          if (v_c111 != v_c150) return;
                          bool ok894 = true;
                          u64 v_c151 = _prim_lref(db, v_c132, v_c112, &ok894);
                          if (!ok894) return;
                          if (v_c113 != v_c151) return;
                          ++_fires;
                          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c19}, std::array<u16,1>{0});
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
  
      if (_fires) db->bumpFires("st_basic.slog:17", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask849* _cont = new ReadTask849(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask849(db,b), false);
  // (crule (pre (let __tconst6z9n537 const5feceb66ffc86f38d952786c)) (scan pbranch __t3erE535 p m l r) (body (join-old st_diff (1 2 0) 1 (1 2 0) __t3erE535 __t1Xgc534 __t7CyZ536) (join pbranch (0 1 2 3 4) 1 __t1Xgc534 q n u v) (cmp lt m n) (let __t0JvE538 (band p n)) (cmp gt __t0JvE538 __tconst6z9n537)) (head (emit $sup9688x151x0x0x0 (0 8 1 2 3 4 5 6 7) __t7CyZ536 v l m n p q r u)) set.slog:152 #f)
  class ReadTask898 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_diffindex895;  slog::Index** pbranchindex896;  slog::Index** st_diffdelta897;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x151x0x0x0");
      std::vector<u16> ord899({0, 8, 1, 2, 3, 4, 5, 6, 7});
      slog::Relation* readrel900 = db->getRelation("$sup9688x151x0x0x0");
      head_index[0] = readrel900->getIndex(ord899, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord901({1, 2, 0});
      slog::Relation* readrel902 = db->getRelation("st_diff");
      st_diffindex895 = readrel902->getIndex(ord901, false);
      std::vector<u16> ord903({1, 2, 0});
      slog::Relation* readrel904 = db->getRelation("st_diff");
      st_diffdelta897 = readrel904->getIndex(ord903, true);
      std::vector<u16> ord905({0, 1, 2, 3, 4});
      slog::Relation* readrel906 = db->getRelation("pbranch");
      pbranchindex896 = readrel906->getIndex(ord905, false);
  
    }
    ReadTask898(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c152 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c153 = _t[0];
        u64 v_c16 = _t[1];
        u64 v_c17 = _t[2];
        u64 v_c18 = _t[3];
        u64 v_c19 = _t[4];
        slog::join_probe_old<3,1>(st_diffindex895, st_diffdelta897, std::array<u64,3>{v_c153, 0, 0}, [&](const std::array<u64,3>& m907) {
          u64 v_c154 = m907[1]; u64 v_c155 = m907[2];
          slog::join_probe<5,1>(pbranchindex896, std::array<u64,5>{v_c154, 0, 0, 0, 0}, [&](const std::array<u64,5>& m908) {
            u64 v_c22 = m908[1]; u64 v_c23 = m908[2]; u64 v_c24 = m908[3]; u64 v_c25 = m908[4];
            u64 v_c156 = _prim_lt(db, v_c17, v_c23);
            if (v_c156 == slog_error) { slog::emit_pending_error(db, "set.slog:152"); return; }
            if (!v_c156) return;
            u64 v_c157 = _prim_band(db, v_c16, v_c23);
            if (v_c157 == slog_error) { slog::emit_pending_error(db, "set.slog:152"); return; }
            u64 v_c158 = _prim_gt(db, v_c157, v_c152);
            if (v_c158 == slog_error) { slog::emit_pending_error(db, "set.slog:152"); return; }
            if (!v_c158) return;
            ++_fires;
            slog::emit<9>(head_rel[0], head_index[0], newbatch[0], std::array<u64,9>{v_c155, v_c25, v_c18, v_c17, v_c23, v_c16, v_c22, v_c19, v_c24}, std::array<u16,9>{0, 8, 1, 2, 3, 4, 5, 6, 7});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:152", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask898* _cont = new ReadTask898(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask898(db,b), false);
  // (crule (pre) (scan $sup9688x106x0x0x0 __d0 l m n p q r u v) (body (exists st_msk_ans (1 0) 1 p) (join-old st_msk (1 2 0) 2 (1 2 0) q m __t6jwI501) (join-old st_msk_ans (0 1) 2 (0 1) __t6jwI501 p)) (head (emit $sup9688x106x0x0x1 (0 7 1 2 3 4 5 6 8 9) __d0 r __t6jwI501 l m n p q u v)) set.slog:107 #f)
  class ReadTask916 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_msk_ansindex911;  slog::Index** st_mskindex912;  slog::Index** st_msk_ansindex913;  slog::Index** st_mskdelta914;  slog::Index** st_msk_ansdelta915;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x106x0x0x1");
      std::vector<u16> ord917({0, 7, 1, 2, 3, 4, 5, 6, 8, 9});
      slog::Relation* readrel918 = db->getRelation("$sup9688x106x0x0x1");
      head_index[0] = readrel918->getIndex(ord917, false);
      outer_rel = db->getRelation("$sup9688x106x0x0x0");
      std::vector<u16> ord919({1, 0});
      slog::Relation* readrel920 = db->getRelation("st_msk_ans");
      st_msk_ansindex911 = readrel920->getIndex(ord919, false);
      std::vector<u16> ord921({1, 2, 0});
      slog::Relation* readrel922 = db->getRelation("st_msk");
      st_mskindex912 = readrel922->getIndex(ord921, false);
      std::vector<u16> ord923({1, 2, 0});
      slog::Relation* readrel924 = db->getRelation("st_msk");
      st_mskdelta914 = readrel924->getIndex(ord923, true);
      std::vector<u16> ord925({0, 1});
      slog::Relation* readrel926 = db->getRelation("st_msk_ans");
      st_msk_ansindex913 = readrel926->getIndex(ord925, false);
      std::vector<u16> ord927({0, 1});
      slog::Relation* readrel928 = db->getRelation("st_msk_ans");
      st_msk_ansdelta915 = readrel928->getIndex(ord927, true);
  
    }
    ReadTask916(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c18 = _t[1];
        u64 v_c17 = _t[2];
        u64 v_c23 = _t[3];
        u64 v_c16 = _t[4];
        u64 v_c22 = _t[5];
        u64 v_c19 = _t[6];
        u64 v_c24 = _t[7];
        u64 v_c25 = _t[8];
        if (!slog::exists_probe<2,1>(st_msk_ansindex911, std::array<u64,2>{v_c16, 0})) return;
        slog::join_probe_old<3,2>(st_mskindex912, st_mskdelta914, std::array<u64,3>{v_c22, v_c17, 0}, [&](const std::array<u64,3>& m929) {
          u64 v_c159 = m929[2];
          slog::join_probe_old<2,2>(st_msk_ansindex913, st_msk_ansdelta915, std::array<u64,2>{v_c159, v_c16}, [&](const std::array<u64,2>& m930) {
            ++_fires;
            slog::emit<10>(head_rel[0], head_index[0], newbatch[0], std::array<u64,10>{v_c40, v_c19, v_c159, v_c18, v_c17, v_c23, v_c16, v_c22, v_c24, v_c25}, std::array<u16,10>{0, 7, 1, 2, 3, 4, 5, 6, 8, 9});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:107", "delta:$sup9688x106x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask916* _cont = new ReadTask916(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask916(db,b), false);
  // (crule (pre (let __tconst5jgZ160 const6b86b273ff34fce19d6b804e)) (scan st_diff_ans __t0YPK165 __v0) (body (exists st_bld (3 0 1 2 4) 1 __v0) (join-old st_diff (0 1 2) 1 (0 1 2) __t0YPK165 l __t6ACr164) (exists pbranch (3 0 1 2 4) 1 l) (exists $sup9688x139x0x0x0 (1 0 2 3 4 5 6 7 8) 1 l) (join-old st_diff (2 0 1) 1 (2 0 1) __t6ACr164 __t3X8M159 __t66RN158) (exists $sup9688x139x0x0x0 (0 1 2 3 4 5 6 7 8) 2 __t3X8M159 l) (join-old pbranch (3 0 1 2 4) 2 (3 0 1 2 4) l __t66RN158 p m r) (exists st_bld (1 2 3 4 0) 4 p m __v0 r) (exists st_msk (2 0 1) 1 m) (exists st_msk_ans (1 0) 1 p) (join-old $sup9688x139x0x0x0 (4 2 6 1 0 3 5 7 8) 5 (4 2 6 1 0 3 5 7 8) p m r l __t3X8M159 n q u v) (cmp lt n m) (join-old pbranch (1 2 3 4 0) 5 (1 2 3 4 0) q n u v __t6ACr164) (exists st_msk (1 2 0) 2 q m) (join-old st_bld (1 2 3 4 0) 4 (1 2 3 4 0) p m __v0 r __t1RXD162) (exists st_bld_ans (0 1) 1 __t1RXD162) (join-old st_msk (1 2 0) 2 (1 2 0) q m __t8DQ7163) (join st_msk_ans (0 1) 2 __t8DQ7163 p) (join st_bld_ans (0 1) 1 __t1RXD162 res) (let __t2cGU161 (band q m)) (cmp lt __t2cGU161 __tconst5jgZ160)) (head (emit st_diff_ans (0 1) __t3X8M159 res)) set.slog:140 #f)
  class ReadTask956 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_bldindex931;  slog::Index** st_diffindex932;  slog::Index** pbranchindex933;  slog::Index** $sup9688x139x0x0x0index934;  slog::Index** st_diffindex935;  slog::Index** $sup9688x139x0x0x0index936;  slog::Index** pbranchindex937;  slog::Index** st_bldindex938;  slog::Index** st_mskindex939;  slog::Index** st_msk_ansindex940;  slog::Index** $sup9688x139x0x0x0index941;  slog::Index** pbranchindex942;  slog::Index** st_mskindex943;  slog::Index** st_bldindex944;  slog::Index** st_bld_ansindex945;  slog::Index** st_mskindex946;  slog::Index** st_msk_ansindex947;  slog::Index** st_bld_ansindex948;  slog::Index** st_diffdelta949;  slog::Index** st_diffdelta950;  slog::Index** pbranchdelta951;  slog::Index** $sup9688x139x0x0x0delta952;  slog::Index** pbranchdelta953;  slog::Index** st_blddelta954;  slog::Index** st_mskdelta955;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord957({0, 1});
      slog::Relation* readrel958 = db->getRelation("st_diff_ans");
      head_index[0] = readrel958->getIndex(ord957, false);
      outer_rel = db->getRelation("st_diff_ans");
      std::vector<u16> ord959({3, 0, 1, 2, 4});
      slog::Relation* readrel960 = db->getRelation("st_bld");
      st_bldindex931 = readrel960->getIndex(ord959, false);
      std::vector<u16> ord961({0, 1, 2});
      slog::Relation* readrel962 = db->getRelation("st_diff");
      st_diffindex932 = readrel962->getIndex(ord961, false);
      std::vector<u16> ord963({0, 1, 2});
      slog::Relation* readrel964 = db->getRelation("st_diff");
      st_diffdelta949 = readrel964->getIndex(ord963, true);
      std::vector<u16> ord965({3, 0, 1, 2, 4});
      slog::Relation* readrel966 = db->getRelation("pbranch");
      pbranchindex933 = readrel966->getIndex(ord965, false);
      std::vector<u16> ord967({1, 0, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel968 = db->getRelation("$sup9688x139x0x0x0");
      $sup9688x139x0x0x0index934 = readrel968->getIndex(ord967, false);
      std::vector<u16> ord969({2, 0, 1});
      slog::Relation* readrel970 = db->getRelation("st_diff");
      st_diffindex935 = readrel970->getIndex(ord969, false);
      std::vector<u16> ord971({2, 0, 1});
      slog::Relation* readrel972 = db->getRelation("st_diff");
      st_diffdelta950 = readrel972->getIndex(ord971, true);
      std::vector<u16> ord973({0, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel974 = db->getRelation("$sup9688x139x0x0x0");
      $sup9688x139x0x0x0index936 = readrel974->getIndex(ord973, false);
      std::vector<u16> ord975({3, 0, 1, 2, 4});
      slog::Relation* readrel976 = db->getRelation("pbranch");
      pbranchindex937 = readrel976->getIndex(ord975, false);
      std::vector<u16> ord977({3, 0, 1, 2, 4});
      slog::Relation* readrel978 = db->getRelation("pbranch");
      pbranchdelta951 = readrel978->getIndex(ord977, true);
      std::vector<u16> ord979({1, 2, 3, 4, 0});
      slog::Relation* readrel980 = db->getRelation("st_bld");
      st_bldindex938 = readrel980->getIndex(ord979, false);
      std::vector<u16> ord981({2, 0, 1});
      slog::Relation* readrel982 = db->getRelation("st_msk");
      st_mskindex939 = readrel982->getIndex(ord981, false);
      std::vector<u16> ord983({1, 0});
      slog::Relation* readrel984 = db->getRelation("st_msk_ans");
      st_msk_ansindex940 = readrel984->getIndex(ord983, false);
      std::vector<u16> ord985({4, 2, 6, 1, 0, 3, 5, 7, 8});
      slog::Relation* readrel986 = db->getRelation("$sup9688x139x0x0x0");
      $sup9688x139x0x0x0index941 = readrel986->getIndex(ord985, false);
      std::vector<u16> ord987({4, 2, 6, 1, 0, 3, 5, 7, 8});
      slog::Relation* readrel988 = db->getRelation("$sup9688x139x0x0x0");
      $sup9688x139x0x0x0delta952 = readrel988->getIndex(ord987, true);
      std::vector<u16> ord989({1, 2, 3, 4, 0});
      slog::Relation* readrel990 = db->getRelation("pbranch");
      pbranchindex942 = readrel990->getIndex(ord989, false);
      std::vector<u16> ord991({1, 2, 3, 4, 0});
      slog::Relation* readrel992 = db->getRelation("pbranch");
      pbranchdelta953 = readrel992->getIndex(ord991, true);
      std::vector<u16> ord993({1, 2, 0});
      slog::Relation* readrel994 = db->getRelation("st_msk");
      st_mskindex943 = readrel994->getIndex(ord993, false);
      std::vector<u16> ord995({1, 2, 3, 4, 0});
      slog::Relation* readrel996 = db->getRelation("st_bld");
      st_bldindex944 = readrel996->getIndex(ord995, false);
      std::vector<u16> ord997({1, 2, 3, 4, 0});
      slog::Relation* readrel998 = db->getRelation("st_bld");
      st_blddelta954 = readrel998->getIndex(ord997, true);
      std::vector<u16> ord999({0, 1});
      slog::Relation* readrel1000 = db->getRelation("st_bld_ans");
      st_bld_ansindex945 = readrel1000->getIndex(ord999, false);
      std::vector<u16> ord1001({1, 2, 0});
      slog::Relation* readrel1002 = db->getRelation("st_msk");
      st_mskindex946 = readrel1002->getIndex(ord1001, false);
      std::vector<u16> ord1003({1, 2, 0});
      slog::Relation* readrel1004 = db->getRelation("st_msk");
      st_mskdelta955 = readrel1004->getIndex(ord1003, true);
      std::vector<u16> ord1005({0, 1});
      slog::Relation* readrel1006 = db->getRelation("st_msk_ans");
      st_msk_ansindex947 = readrel1006->getIndex(ord1005, false);
      std::vector<u16> ord1007({0, 1});
      slog::Relation* readrel1008 = db->getRelation("st_bld_ans");
      st_bld_ansindex948 = readrel1008->getIndex(ord1007, false);
  
    }
    ReadTask956(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c160 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c161 = _t[0];
        u64 v_c10 = _t[1];
        if (!slog::exists_probe<5,1>(st_bldindex931, std::array<u64,5>{v_c10, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(st_diffindex932, st_diffdelta949, std::array<u64,3>{v_c161, 0, 0}, [&](const std::array<u64,3>& m1009) {
          u64 v_c18 = m1009[1]; u64 v_c162 = m1009[2];
          if (!slog::exists_probe<5,1>(pbranchindex933, std::array<u64,5>{v_c18, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<9,1>($sup9688x139x0x0x0index934, std::array<u64,9>{v_c18, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          slog::join_probe_old<3,1>(st_diffindex935, st_diffdelta950, std::array<u64,3>{v_c162, 0, 0}, [&](const std::array<u64,3>& m1010) {
            u64 v_c163 = m1010[1]; u64 v_c164 = m1010[2];
            if (!slog::exists_probe<9,2>($sup9688x139x0x0x0index936, std::array<u64,9>{v_c163, v_c18, 0, 0, 0, 0, 0, 0, 0})) return;
            slog::join_probe_old<5,2>(pbranchindex937, pbranchdelta951, std::array<u64,5>{v_c18, v_c164, 0, 0, 0}, [&](const std::array<u64,5>& m1011) {
              u64 v_c16 = m1011[2]; u64 v_c17 = m1011[3]; u64 v_c19 = m1011[4];
              if (!slog::exists_probe<5,4>(st_bldindex938, std::array<u64,5>{v_c16, v_c17, v_c10, v_c19, 0})) return;
              if (!slog::exists_probe<3,1>(st_mskindex939, std::array<u64,3>{v_c17, 0, 0})) return;
              if (!slog::exists_probe<2,1>(st_msk_ansindex940, std::array<u64,2>{v_c16, 0})) return;
              slog::join_probe_old<9,5>($sup9688x139x0x0x0index941, $sup9688x139x0x0x0delta952, std::array<u64,9>{v_c16, v_c17, v_c19, v_c18, v_c163, 0, 0, 0, 0}, [&](const std::array<u64,9>& m1012) {
                u64 v_c23 = m1012[5]; u64 v_c22 = m1012[6]; u64 v_c24 = m1012[7]; u64 v_c25 = m1012[8];
                u64 v_c165 = _prim_lt(db, v_c23, v_c17);
                if (v_c165 == slog_error) { slog::emit_pending_error(db, "set.slog:140"); return; }
                if (!v_c165) return;
                slog::join_probe_old<5,5>(pbranchindex942, pbranchdelta953, std::array<u64,5>{v_c22, v_c23, v_c24, v_c25, v_c162}, [&](const std::array<u64,5>& m1014) {
                  if (!slog::exists_probe<3,2>(st_mskindex943, std::array<u64,3>{v_c22, v_c17, 0})) return;
                  slog::join_probe_old<5,4>(st_bldindex944, st_blddelta954, std::array<u64,5>{v_c16, v_c17, v_c10, v_c19, 0}, [&](const std::array<u64,5>& m1015) {
                    u64 v_c166 = m1015[4];
                    if (!slog::exists_probe<2,1>(st_bld_ansindex945, std::array<u64,2>{v_c166, 0})) return;
                    slog::join_probe_old<3,2>(st_mskindex946, st_mskdelta955, std::array<u64,3>{v_c22, v_c17, 0}, [&](const std::array<u64,3>& m1016) {
                      u64 v_c167 = m1016[2];
                      slog::join_probe<2,2>(st_msk_ansindex947, std::array<u64,2>{v_c167, v_c16}, [&](const std::array<u64,2>& m1017) {
                        slog::join_probe<2,1>(st_bld_ansindex948, std::array<u64,2>{v_c166, 0}, [&](const std::array<u64,2>& m1018) {
                          u64 v_c74 = m1018[1];
                          u64 v_c168 = _prim_band(db, v_c22, v_c17);
                          if (v_c168 == slog_error) { slog::emit_pending_error(db, "set.slog:140"); return; }
                          u64 v_c169 = _prim_lt(db, v_c168, v_c160);
                          if (v_c169 == slog_error) { slog::emit_pending_error(db, "set.slog:140"); return; }
                          if (!v_c169) return;
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c163, v_c74}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("set.slog:140", "delta:st_diff_ans", _fires);
  
      if (!_done)
      {
        ReadTask956* _cont = new ReadTask956(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask956(db,b), false);
  // (crule (pre (let _00024sqc6FSA620 const4b227777d4dd1fc61c6f884f) (let _00024sqc3Ub8621 const5feceb66ffc86f38d952786c) (let _00024sqc1TCF622 const6b86b273ff34fce19d6b804e) (let _00024sqc3FMQ623 const6b86b273ff34fce19d6b804e) (let _00024sqc41K7624 const2c624232cdd221771294dfbb) (let _00024sqc6uPA625 constd4735e3a265e16eee03f5971) (let _00024sqc9VIm626 constd4735e3a265e16eee03f5971) (let _00024sqc7Q1B627 const4e07408562bedb8b60ce05c1) (let _00024sqc4nIn628 constef2d127de37b942baad06145) (let _00024sqo09Ee630 const6b86b273ff34fce19d6b804e) (let _00024sqo5YJw629 const5feceb66ffc86f38d952786c) (let _00024sqo1RnK632 const2c624232cdd221771294dfbb) (let _00024sqo5bHs631 const6b86b273ff34fce19d6b804e) (let _00024sqo2z3g634 constd4735e3a265e16eee03f5971) (let _00024sqo0Hmn633 constd4735e3a265e16eee03f5971) (let _00024sqo7Xdh636 constef2d127de37b942baad06145) (let _00024sqo5nmm635 const4e07408562bedb8b60ce05c1) (let _00024sqo4nJm638 const6b86b273ff34fce19d6b804e) (let _00024sqo7qJs637 const4e07408562bedb8b60ce05c1) (let _00024sqo4dTI640 const2c624232cdd221771294dfbb) (let _00024sqo4MMk639 constd4735e3a265e16eee03f5971) (let _00024sqo3whL642 constd4735e3a265e16eee03f5971) (let _00024sqo9zLj641 const6b86b273ff34fce19d6b804e) (let _00024sqo1Fkt644 constef2d127de37b942baad06145) (let _00024sqo2E1m643 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 2 _00024sqo5YJw629 _00024sqo09Ee630 _00024seq0) (body (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo5bHs631 _00024sqo1RnK632 _00024seq0) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo0Hmn633 _00024sqo2z3g634 _00024seq0) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo5nmm635 _00024sqo7Xdh636 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo4nJm638 _00024sqo7qJs637 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo4dTI640 _00024sqo4MMk639 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo3whL642 _00024sqo9zLj641 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo1Fkt644 _00024sqo2E1m643 _00024seq0) (join st_fromlist (1 0) 1 _00024seq0 __t2iar332) (join st_fromlist_ans (0 1) 1 __t2iar332 r) (letp _00024sql7znl618 (aslst _00024seq0)) (let chk38xC1359 (llen _00024sql7znl618)) (eq _00024sqc6FSA620 chk38xC1359) (letp chk1red1360 (lref _00024sql7znl618 _00024sqc3Ub8621)) (eq _00024sqc1TCF622 chk1red1360) (letp chk6fg71361 (lref _00024sql7znl618 _00024sqc3FMQ623)) (eq _00024sqc41K7624 chk6fg71361) (letp chk2fTp1362 (lref _00024sql7znl618 _00024sqc6uPA625)) (eq _00024sqc9VIm626 chk2fTp1362) (letp chk0YTs1363 (lref _00024sql7znl618 _00024sqc7Q1B627)) (eq _00024sqc4nIn628 chk0YTs1363)) (head (emit canon (0) r)) st_basic.slog:17 #f)
  class ReadTask1036 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex1020;  slog::Index** $seq_atindex1021;  slog::Index** $seq_atindex1022;  slog::Index** $seq_atrindex1023;  slog::Index** $seq_atrindex1024;  slog::Index** $seq_atrindex1025;  slog::Index** $seq_atrindex1026;  slog::Index** st_fromlistindex1027;  slog::Index** st_fromlist_ansindex1028;  slog::Index** $seq_atdelta1029;  slog::Index** $seq_atdelta1030;  slog::Index** $seq_atdelta1031;  slog::Index** $seq_atrdelta1032;  slog::Index** $seq_atrdelta1033;  slog::Index** $seq_atrdelta1034;  slog::Index** $seq_atrdelta1035;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("canon");
      std::vector<u16> ord1037({0});
      slog::Relation* readrel1038 = db->getRelation("canon");
      head_index[0] = readrel1038->getIndex(ord1037, false);
      std::vector<u16> ord1039({1, 0, 2});
      slog::Relation* readrel1040 = db->getRelation("$seq_at");
      driver_index = readrel1040->getIndex(ord1039, true);
      std::vector<u16> ord1041({1, 0, 2});
      slog::Relation* readrel1042 = db->getRelation("$seq_at");
      $seq_atindex1020 = readrel1042->getIndex(ord1041, false);
      std::vector<u16> ord1043({1, 0, 2});
      slog::Relation* readrel1044 = db->getRelation("$seq_at");
      $seq_atdelta1029 = readrel1044->getIndex(ord1043, true);
      std::vector<u16> ord1045({1, 0, 2});
      slog::Relation* readrel1046 = db->getRelation("$seq_at");
      $seq_atindex1021 = readrel1046->getIndex(ord1045, false);
      std::vector<u16> ord1047({1, 0, 2});
      slog::Relation* readrel1048 = db->getRelation("$seq_at");
      $seq_atdelta1030 = readrel1048->getIndex(ord1047, true);
      std::vector<u16> ord1049({1, 0, 2});
      slog::Relation* readrel1050 = db->getRelation("$seq_at");
      $seq_atindex1022 = readrel1050->getIndex(ord1049, false);
      std::vector<u16> ord1051({1, 0, 2});
      slog::Relation* readrel1052 = db->getRelation("$seq_at");
      $seq_atdelta1031 = readrel1052->getIndex(ord1051, true);
      std::vector<u16> ord1053({0, 1, 2});
      slog::Relation* readrel1054 = db->getRelation("$seq_atr");
      $seq_atrindex1023 = readrel1054->getIndex(ord1053, false);
      std::vector<u16> ord1055({0, 1, 2});
      slog::Relation* readrel1056 = db->getRelation("$seq_atr");
      $seq_atrdelta1032 = readrel1056->getIndex(ord1055, true);
      std::vector<u16> ord1057({0, 1, 2});
      slog::Relation* readrel1058 = db->getRelation("$seq_atr");
      $seq_atrindex1024 = readrel1058->getIndex(ord1057, false);
      std::vector<u16> ord1059({0, 1, 2});
      slog::Relation* readrel1060 = db->getRelation("$seq_atr");
      $seq_atrdelta1033 = readrel1060->getIndex(ord1059, true);
      std::vector<u16> ord1061({0, 1, 2});
      slog::Relation* readrel1062 = db->getRelation("$seq_atr");
      $seq_atrindex1025 = readrel1062->getIndex(ord1061, false);
      std::vector<u16> ord1063({0, 1, 2});
      slog::Relation* readrel1064 = db->getRelation("$seq_atr");
      $seq_atrdelta1034 = readrel1064->getIndex(ord1063, true);
      std::vector<u16> ord1065({0, 1, 2});
      slog::Relation* readrel1066 = db->getRelation("$seq_atr");
      $seq_atrindex1026 = readrel1066->getIndex(ord1065, false);
      std::vector<u16> ord1067({0, 1, 2});
      slog::Relation* readrel1068 = db->getRelation("$seq_atr");
      $seq_atrdelta1035 = readrel1068->getIndex(ord1067, true);
      std::vector<u16> ord1069({1, 0});
      slog::Relation* readrel1070 = db->getRelation("st_fromlist");
      st_fromlistindex1027 = readrel1070->getIndex(ord1069, false);
      std::vector<u16> ord1071({0, 1});
      slog::Relation* readrel1072 = db->getRelation("st_fromlist_ans");
      st_fromlist_ansindex1028 = readrel1072->getIndex(ord1071, false);
  
    }
    ReadTask1036(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c105 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c106 = v_const5feceb66ffc86f38d952786c;
      u64 v_c107 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c108 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c109 = v_const2c624232cdd221771294dfbb;
      u64 v_c110 = v_constd4735e3a265e16eee03f5971;
      u64 v_c111 = v_constd4735e3a265e16eee03f5971;
      u64 v_c112 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c113 = v_constef2d127de37b942baad06145;
      u64 v_c114 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c115 = v_const5feceb66ffc86f38d952786c;
      u64 v_c116 = v_const2c624232cdd221771294dfbb;
      u64 v_c117 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c118 = v_constd4735e3a265e16eee03f5971;
      u64 v_c119 = v_constd4735e3a265e16eee03f5971;
      u64 v_c120 = v_constef2d127de37b942baad06145;
      u64 v_c121 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c122 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c123 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c124 = v_const2c624232cdd221771294dfbb;
      u64 v_c125 = v_constd4735e3a265e16eee03f5971;
      u64 v_c126 = v_constd4735e3a265e16eee03f5971;
      u64 v_c127 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c128 = v_constef2d127de37b942baad06145;
      u64 v_c129 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c115, v_c114, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1073) {
        u64 v_c131 = m1073[2];
        if (buckethash(v_c131) != bucket) return;
        slog::join_probe_old<3,3>($seq_atindex1020, $seq_atdelta1029, std::array<u64,3>{v_c117, v_c116, v_c131}, [&](const std::array<u64,3>& m1074) {
          slog::join_probe_old<3,3>($seq_atindex1021, $seq_atdelta1030, std::array<u64,3>{v_c119, v_c118, v_c131}, [&](const std::array<u64,3>& m1075) {
            slog::join_probe_old<3,3>($seq_atindex1022, $seq_atdelta1031, std::array<u64,3>{v_c121, v_c120, v_c131}, [&](const std::array<u64,3>& m1076) {
              slog::join_probe_old<3,3>($seq_atrindex1023, $seq_atrdelta1032, std::array<u64,3>{v_c122, v_c123, v_c131}, [&](const std::array<u64,3>& m1077) {
                slog::join_probe_old<3,3>($seq_atrindex1024, $seq_atrdelta1033, std::array<u64,3>{v_c124, v_c125, v_c131}, [&](const std::array<u64,3>& m1078) {
                  slog::join_probe_old<3,3>($seq_atrindex1025, $seq_atrdelta1034, std::array<u64,3>{v_c126, v_c127, v_c131}, [&](const std::array<u64,3>& m1079) {
                    slog::join_probe_old<3,3>($seq_atrindex1026, $seq_atrdelta1035, std::array<u64,3>{v_c128, v_c129, v_c131}, [&](const std::array<u64,3>& m1080) {
                      slog::join_probe<2,1>(st_fromlistindex1027, std::array<u64,2>{v_c131, 0}, [&](const std::array<u64,2>& m1081) {
                        u64 v_c130 = m1081[1];
                        slog::join_probe<2,1>(st_fromlist_ansindex1028, std::array<u64,2>{v_c130, 0}, [&](const std::array<u64,2>& m1082) {
                          u64 v_c19 = m1082[1];
                          bool ok1083 = true;
                          u64 v_c132 = _prim_aslst(db, v_c131, &ok1083);
                          if (!ok1083) return;
                          u64 v_c170 = _prim_llen(db, v_c132);
                          if (v_c170 == slog_error) { slog::emit_pending_error(db, "st_basic.slog:17"); return; }
                          if (v_c105 != v_c170) return;
                          bool ok1084 = true;
                          u64 v_c171 = _prim_lref(db, v_c132, v_c106, &ok1084);
                          if (!ok1084) return;
                          if (v_c107 != v_c171) return;
                          bool ok1085 = true;
                          u64 v_c172 = _prim_lref(db, v_c132, v_c108, &ok1085);
                          if (!ok1085) return;
                          if (v_c109 != v_c172) return;
                          bool ok1086 = true;
                          u64 v_c173 = _prim_lref(db, v_c132, v_c110, &ok1086);
                          if (!ok1086) return;
                          if (v_c111 != v_c173) return;
                          bool ok1087 = true;
                          u64 v_c174 = _prim_lref(db, v_c132, v_c112, &ok1087);
                          if (!ok1087) return;
                          if (v_c113 != v_c174) return;
                          ++_fires;
                          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c19}, std::array<u16,1>{0});
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
  
      if (_fires) db->bumpFires("st_basic.slog:17", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask1036* _cont = new ReadTask1036(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1036(db,b), false);
  // (crule (pre) (scan $sup9688x36x0x0x1 __d0 __d1 __v0 p0 p1 t0 t1) (body (join st_hsb_ans (0 1) 0 __t5IW626 __v3) (join st_hsb_ans (0 1) 1 __t5IW626 __v1) (let __t8vKi27 (bxor p0 p1)) (join-old st_hsb (0 1) 2 (0 1) __t5IW626 __t8vKi27)) (head (emit $sup9688x36x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) __d1 __v0 __v3 __v1 __d0 __t5IW626 __t5IW626 p0 p1 t0 t1)) set.slog:37 #f)
  class ReadTask1092 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_hsb_ansindex1088;  slog::Index** st_hsb_ansindex1089;  slog::Index** st_hsbindex1090;  slog::Index** st_hsbdelta1091;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x36x0x0x2");
      std::vector<u16> ord1093({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel1094 = db->getRelation("$sup9688x36x0x0x2");
      head_index[0] = readrel1094->getIndex(ord1093, false);
      outer_rel = db->getRelation("$sup9688x36x0x0x1");
      std::vector<u16> ord1095({0, 1});
      slog::Relation* readrel1096 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex1088 = readrel1096->getIndex(ord1095, false);
      std::vector<u16> ord1097({0, 1});
      slog::Relation* readrel1098 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex1089 = readrel1098->getIndex(ord1097, false);
      std::vector<u16> ord1099({0, 1});
      slog::Relation* readrel1100 = db->getRelation("st_hsb");
      st_hsbindex1090 = readrel1100->getIndex(ord1099, false);
      std::vector<u16> ord1101({0, 1});
      slog::Relation* readrel1102 = db->getRelation("st_hsb");
      st_hsbdelta1091 = readrel1102->getIndex(ord1101, true);
  
    }
    ReadTask1092(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c41 = _t[1];
        u64 v_c10 = _t[2];
        u64 v_c175 = _t[3];
        u64 v_c176 = _t[4];
        u64 v_c177 = _t[5];
        u64 v_c178 = _t[6];
        slog::join_all<2>(st_hsb_ansindex1088, [&](const std::array<u64,2>& m1103) {
          u64 v_c179 = m1103[0]; u64 v_c180 = m1103[1];
          slog::join_probe<2,1>(st_hsb_ansindex1089, std::array<u64,2>{v_c179, 0}, [&](const std::array<u64,2>& m1104) {
            u64 v_c6 = m1104[1];
            u64 v_c181 = _prim_bxor(db, v_c175, v_c176);
            if (v_c181 == slog_error) { slog::emit_pending_error(db, "set.slog:37"); return; }
            slog::join_probe_old<2,2>(st_hsbindex1090, st_hsbdelta1091, std::array<u64,2>{v_c179, v_c181}, [&](const std::array<u64,2>& m1105) {
              ++_fires;
              slog::emit<11>(head_rel[0], head_index[0], newbatch[0], std::array<u64,11>{v_c41, v_c10, v_c180, v_c6, v_c40, v_c179, v_c179, v_c175, v_c176, v_c177, v_c178}, std::array<u16,11>{1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:37", "delta:$sup9688x36x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask1092* _cont = new ReadTask1092(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1092(db,b), false);
  // (crule (pre (let _00024sqc5Ylt593 const4b227777d4dd1fc61c6f884f) (let _00024sqc75sY594 const5feceb66ffc86f38d952786c) (let _00024sqc7SC7595 constef2d127de37b942baad06145) (let _00024sqc9xIA596 const6b86b273ff34fce19d6b804e) (let _00024sqc1Dz5597 constd4735e3a265e16eee03f5971) (let _00024sqc3IO1598 constd4735e3a265e16eee03f5971) (let _00024sqc8gB7599 const2c624232cdd221771294dfbb) (let _00024sqc5ClH600 const4e07408562bedb8b60ce05c1) (let _00024sqc3osW601 const6b86b273ff34fce19d6b804e) (let _00024sqo1fme603 constef2d127de37b942baad06145) (let _00024sqo8SDr602 const5feceb66ffc86f38d952786c) (let _00024sqo8V65605 constd4735e3a265e16eee03f5971) (let _00024sqo8H0j604 const6b86b273ff34fce19d6b804e) (let _00024sqo58Kv607 const2c624232cdd221771294dfbb) (let _00024sqo9fPL606 constd4735e3a265e16eee03f5971) (let _00024sqo8Byv609 const6b86b273ff34fce19d6b804e) (let _00024sqo6mXs608 const4e07408562bedb8b60ce05c1) (let _00024sqo1LyP611 constef2d127de37b942baad06145) (let _00024sqo7das610 const4e07408562bedb8b60ce05c1) (let _00024sqo8vL7613 constd4735e3a265e16eee03f5971) (let _00024sqo5GBE612 constd4735e3a265e16eee03f5971) (let _00024sqo1K4x615 const2c624232cdd221771294dfbb) (let _00024sqo0Oce614 const6b86b273ff34fce19d6b804e) (let _00024sqo9RJN617 const6b86b273ff34fce19d6b804e) (let _00024sqo9a1a616 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 2 _00024sqo6mXs608 _00024sqo8Byv609 _00024seq0) (body (join $seq_at (1 0 2) 3 _00024sqo8SDr602 _00024sqo1fme603 _00024seq0) (join $seq_at (1 0 2) 3 _00024sqo8H0j604 _00024sqo8V65605 _00024seq0) (join $seq_at (1 0 2) 3 _00024sqo9fPL606 _00024sqo58Kv607 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo1LyP611 _00024sqo7das610 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo8vL7613 _00024sqo5GBE612 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo1K4x615 _00024sqo0Oce614 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo9RJN617 _00024sqo9a1a616 _00024seq0) (join st_fromlist (1 0) 1 _00024seq0 __t14PV427) (join st_fromlist_ans (0 1) 1 __t14PV427 r) (letp _00024sql0i4I591 (aslst _00024seq0)) (let chk3SEo1307 (llen _00024sql0i4I591)) (eq _00024sqc5Ylt593 chk3SEo1307) (letp chk9qvU1308 (lref _00024sql0i4I591 _00024sqc75sY594)) (eq _00024sqc7SC7595 chk9qvU1308) (letp chk98EE1309 (lref _00024sql0i4I591 _00024sqc9xIA596)) (eq _00024sqc1Dz5597 chk98EE1309) (letp chk7K9b1310 (lref _00024sql0i4I591 _00024sqc3IO1598)) (eq _00024sqc8gB7599 chk7K9b1310) (letp chk4L601311 (lref _00024sql0i4I591 _00024sqc5ClH600)) (eq _00024sqc3osW601 chk4L601311)) (head (emit canon (0) r)) st_basic.slog:16 #f)
  class ReadTask1119 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex1106;  slog::Index** $seq_atindex1107;  slog::Index** $seq_atindex1108;  slog::Index** $seq_atrindex1109;  slog::Index** $seq_atrindex1110;  slog::Index** $seq_atrindex1111;  slog::Index** $seq_atrindex1112;  slog::Index** st_fromlistindex1113;  slog::Index** st_fromlist_ansindex1114;  slog::Index** $seq_atrdelta1115;  slog::Index** $seq_atrdelta1116;  slog::Index** $seq_atrdelta1117;  slog::Index** $seq_atrdelta1118;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("canon");
      std::vector<u16> ord1120({0});
      slog::Relation* readrel1121 = db->getRelation("canon");
      head_index[0] = readrel1121->getIndex(ord1120, false);
      std::vector<u16> ord1122({1, 0, 2});
      slog::Relation* readrel1123 = db->getRelation("$seq_at");
      driver_index = readrel1123->getIndex(ord1122, true);
      std::vector<u16> ord1124({1, 0, 2});
      slog::Relation* readrel1125 = db->getRelation("$seq_at");
      $seq_atindex1106 = readrel1125->getIndex(ord1124, false);
      std::vector<u16> ord1126({1, 0, 2});
      slog::Relation* readrel1127 = db->getRelation("$seq_at");
      $seq_atindex1107 = readrel1127->getIndex(ord1126, false);
      std::vector<u16> ord1128({1, 0, 2});
      slog::Relation* readrel1129 = db->getRelation("$seq_at");
      $seq_atindex1108 = readrel1129->getIndex(ord1128, false);
      std::vector<u16> ord1130({0, 1, 2});
      slog::Relation* readrel1131 = db->getRelation("$seq_atr");
      $seq_atrindex1109 = readrel1131->getIndex(ord1130, false);
      std::vector<u16> ord1132({0, 1, 2});
      slog::Relation* readrel1133 = db->getRelation("$seq_atr");
      $seq_atrdelta1115 = readrel1133->getIndex(ord1132, true);
      std::vector<u16> ord1134({0, 1, 2});
      slog::Relation* readrel1135 = db->getRelation("$seq_atr");
      $seq_atrindex1110 = readrel1135->getIndex(ord1134, false);
      std::vector<u16> ord1136({0, 1, 2});
      slog::Relation* readrel1137 = db->getRelation("$seq_atr");
      $seq_atrdelta1116 = readrel1137->getIndex(ord1136, true);
      std::vector<u16> ord1138({0, 1, 2});
      slog::Relation* readrel1139 = db->getRelation("$seq_atr");
      $seq_atrindex1111 = readrel1139->getIndex(ord1138, false);
      std::vector<u16> ord1140({0, 1, 2});
      slog::Relation* readrel1141 = db->getRelation("$seq_atr");
      $seq_atrdelta1117 = readrel1141->getIndex(ord1140, true);
      std::vector<u16> ord1142({0, 1, 2});
      slog::Relation* readrel1143 = db->getRelation("$seq_atr");
      $seq_atrindex1112 = readrel1143->getIndex(ord1142, false);
      std::vector<u16> ord1144({0, 1, 2});
      slog::Relation* readrel1145 = db->getRelation("$seq_atr");
      $seq_atrdelta1118 = readrel1145->getIndex(ord1144, true);
      std::vector<u16> ord1146({1, 0});
      slog::Relation* readrel1147 = db->getRelation("st_fromlist");
      st_fromlistindex1113 = readrel1147->getIndex(ord1146, false);
      std::vector<u16> ord1148({0, 1});
      slog::Relation* readrel1149 = db->getRelation("st_fromlist_ans");
      st_fromlist_ansindex1114 = readrel1149->getIndex(ord1148, false);
  
    }
    ReadTask1119(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c182 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c183 = v_const5feceb66ffc86f38d952786c;
      u64 v_c184 = v_constef2d127de37b942baad06145;
      u64 v_c185 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c186 = v_constd4735e3a265e16eee03f5971;
      u64 v_c187 = v_constd4735e3a265e16eee03f5971;
      u64 v_c188 = v_const2c624232cdd221771294dfbb;
      u64 v_c189 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c190 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c191 = v_constef2d127de37b942baad06145;
      u64 v_c192 = v_const5feceb66ffc86f38d952786c;
      u64 v_c193 = v_constd4735e3a265e16eee03f5971;
      u64 v_c194 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c195 = v_const2c624232cdd221771294dfbb;
      u64 v_c196 = v_constd4735e3a265e16eee03f5971;
      u64 v_c197 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c198 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c199 = v_constef2d127de37b942baad06145;
      u64 v_c200 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c201 = v_constd4735e3a265e16eee03f5971;
      u64 v_c202 = v_constd4735e3a265e16eee03f5971;
      u64 v_c203 = v_const2c624232cdd221771294dfbb;
      u64 v_c204 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c205 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c206 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c198, v_c197, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1150) {
        u64 v_c131 = m1150[2];
        if (buckethash(v_c131) != bucket) return;
        slog::join_probe<3,3>($seq_atindex1106, std::array<u64,3>{v_c192, v_c191, v_c131}, [&](const std::array<u64,3>& m1151) {
          slog::join_probe<3,3>($seq_atindex1107, std::array<u64,3>{v_c194, v_c193, v_c131}, [&](const std::array<u64,3>& m1152) {
            slog::join_probe<3,3>($seq_atindex1108, std::array<u64,3>{v_c196, v_c195, v_c131}, [&](const std::array<u64,3>& m1153) {
              slog::join_probe_old<3,3>($seq_atrindex1109, $seq_atrdelta1115, std::array<u64,3>{v_c199, v_c200, v_c131}, [&](const std::array<u64,3>& m1154) {
                slog::join_probe_old<3,3>($seq_atrindex1110, $seq_atrdelta1116, std::array<u64,3>{v_c201, v_c202, v_c131}, [&](const std::array<u64,3>& m1155) {
                  slog::join_probe_old<3,3>($seq_atrindex1111, $seq_atrdelta1117, std::array<u64,3>{v_c203, v_c204, v_c131}, [&](const std::array<u64,3>& m1156) {
                    slog::join_probe_old<3,3>($seq_atrindex1112, $seq_atrdelta1118, std::array<u64,3>{v_c205, v_c206, v_c131}, [&](const std::array<u64,3>& m1157) {
                      slog::join_probe<2,1>(st_fromlistindex1113, std::array<u64,2>{v_c131, 0}, [&](const std::array<u64,2>& m1158) {
                        u64 v_c207 = m1158[1];
                        slog::join_probe<2,1>(st_fromlist_ansindex1114, std::array<u64,2>{v_c207, 0}, [&](const std::array<u64,2>& m1159) {
                          u64 v_c19 = m1159[1];
                          bool ok1160 = true;
                          u64 v_c208 = _prim_aslst(db, v_c131, &ok1160);
                          if (!ok1160) return;
                          u64 v_c209 = _prim_llen(db, v_c208);
                          if (v_c209 == slog_error) { slog::emit_pending_error(db, "st_basic.slog:16"); return; }
                          if (v_c182 != v_c209) return;
                          bool ok1161 = true;
                          u64 v_c210 = _prim_lref(db, v_c208, v_c183, &ok1161);
                          if (!ok1161) return;
                          if (v_c184 != v_c210) return;
                          bool ok1162 = true;
                          u64 v_c211 = _prim_lref(db, v_c208, v_c185, &ok1162);
                          if (!ok1162) return;
                          if (v_c186 != v_c211) return;
                          bool ok1163 = true;
                          u64 v_c212 = _prim_lref(db, v_c208, v_c187, &ok1163);
                          if (!ok1163) return;
                          if (v_c188 != v_c212) return;
                          bool ok1164 = true;
                          u64 v_c213 = _prim_lref(db, v_c208, v_c189, &ok1164);
                          if (!ok1164) return;
                          if (v_c190 != v_c213) return;
                          ++_fires;
                          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c19}, std::array<u16,1>{0});
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
  
      if (_fires) db->bumpFires("st_basic.slog:16", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask1119* _cont = new ReadTask1119(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1119(db,b), false);
  // (crule (pre (let __trid5BEA1071 const81906d9241165d9f6a541e47) (let __trel7nV51072 const26c89ee8ccc4ea998fd1a912) (let __tcol7NRn1073 constd4735e3a265e16eee03f5971)) (scan st_diff __t7sr4550 r __t3eTQ549) (body (exists $sup9688x142x0x0x0 (6 0 1 2 3 4 5 7 8) 1 r) (join st_diff_ans (0 1) 1 __t7sr4550 __v0) (join pbranch (0 1 2 3 4) 1 __t3eTQ549 q n u v) (exists st_msk (1 2 0) 1 q) (join $sup9688x142x0x0x0 (3 5 7 8 6 0 1 2 4) 5 n q u v r __d0 l m p) (exists st_msk_ans (1 0) 1 p) (join st_msk (1 2 0) 2 q m __t3ZZb548) (join st_msk_ans (0 1) 2 __t3ZZb548 p)) (head (tycheck l (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid5BEA1071 __trel7nV51072 __tcol7NRn1073 (1 2 3 4 0)) (mkstruct st_bld (1 2 3 4 0) __2Xjw1070 p m l __v0)) set.slog:143 #f)
  class ReadTask1176 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x142x0x0x0index1165;  slog::Index** st_diff_ansindex1166;  slog::Index** pbranchindex1167;  slog::Index** st_mskindex1168;  slog::Index** $sup9688x142x0x0x0index1169;  slog::Index** st_msk_ansindex1170;  slog::Index** st_mskindex1171;  slog::Index** st_msk_ansindex1172;
    u32 sid1174;  u32 sid1173;  u32 sid1175;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("st_bld");
      outer_rel = db->getRelation("st_diff");
      std::vector<u16> ord1177({6, 0, 1, 2, 3, 4, 5, 7, 8});
      slog::Relation* readrel1178 = db->getRelation("$sup9688x142x0x0x0");
      $sup9688x142x0x0x0index1165 = readrel1178->getIndex(ord1177, false);
      std::vector<u16> ord1179({0, 1});
      slog::Relation* readrel1180 = db->getRelation("st_diff_ans");
      st_diff_ansindex1166 = readrel1180->getIndex(ord1179, false);
      std::vector<u16> ord1181({0, 1, 2, 3, 4});
      slog::Relation* readrel1182 = db->getRelation("pbranch");
      pbranchindex1167 = readrel1182->getIndex(ord1181, false);
      std::vector<u16> ord1183({1, 2, 0});
      slog::Relation* readrel1184 = db->getRelation("st_msk");
      st_mskindex1168 = readrel1184->getIndex(ord1183, false);
      std::vector<u16> ord1185({3, 5, 7, 8, 6, 0, 1, 2, 4});
      slog::Relation* readrel1186 = db->getRelation("$sup9688x142x0x0x0");
      $sup9688x142x0x0x0index1169 = readrel1186->getIndex(ord1185, false);
      std::vector<u16> ord1187({1, 0});
      slog::Relation* readrel1188 = db->getRelation("st_msk_ans");
      st_msk_ansindex1170 = readrel1188->getIndex(ord1187, false);
      std::vector<u16> ord1189({1, 2, 0});
      slog::Relation* readrel1190 = db->getRelation("st_msk");
      st_mskindex1171 = readrel1190->getIndex(ord1189, false);
      std::vector<u16> ord1191({0, 1});
      slog::Relation* readrel1192 = db->getRelation("st_msk_ans");
      st_msk_ansindex1172 = readrel1192->getIndex(ord1191, false);
      sid1174 = db->getRelation("_enum")->getStructId();
      sid1173 = db->getRelation("pbranch")->getStructId();
      sid1175 = db->getRelation("pleaf")->getStructId();
  
    }
    ReadTask1176(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c214 = v_const81906d9241165d9f6a541e47;
      u64 v_c215 = v_const26c89ee8ccc4ea998fd1a912;
      u64 v_c216 = v_constd4735e3a265e16eee03f5971;
  
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
        u64 v_c19 = _t[1];
        u64 v_c218 = _t[2];
        if (!slog::exists_probe<9,1>($sup9688x142x0x0x0index1165, std::array<u64,9>{v_c19, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(st_diff_ansindex1166, std::array<u64,2>{v_c217, 0}, [&](const std::array<u64,2>& m1193) {
          u64 v_c10 = m1193[1];
          slog::join_probe<5,1>(pbranchindex1167, std::array<u64,5>{v_c218, 0, 0, 0, 0}, [&](const std::array<u64,5>& m1194) {
            u64 v_c22 = m1194[1]; u64 v_c23 = m1194[2]; u64 v_c24 = m1194[3]; u64 v_c25 = m1194[4];
            if (!slog::exists_probe<3,1>(st_mskindex1168, std::array<u64,3>{v_c22, 0, 0})) return;
            slog::join_probe<9,5>($sup9688x142x0x0x0index1169, std::array<u64,9>{v_c23, v_c22, v_c24, v_c25, v_c19, 0, 0, 0, 0}, [&](const std::array<u64,9>& m1195) {
              u64 v_c40 = m1195[5]; u64 v_c18 = m1195[6]; u64 v_c17 = m1195[7]; u64 v_c16 = m1195[8];
              if (!slog::exists_probe<2,1>(st_msk_ansindex1170, std::array<u64,2>{v_c16, 0})) return;
              slog::join_probe<3,2>(st_mskindex1171, std::array<u64,3>{v_c22, v_c17, 0}, [&](const std::array<u64,3>& m1196) {
                u64 v_c219 = m1196[2];
                slog::join_probe<2,2>(st_msk_ansindex1172, std::array<u64,2>{v_c219, v_c16}, [&](const std::array<u64,2>& m1197) {
                  ++_fires;
                  if (!((is_struct(v_c18) && (decode_struct_id(v_c18) == sid1173 || decode_struct_id(v_c18) == sid1174 || decode_struct_id(v_c18) == sid1175))))
                  {
                    slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c214, v_c215, v_c216, v_c18}, std::array<u16,5>{1, 2, 3, 4, 0});
                    return;
                  }
                  slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c16, v_c17, v_c18, v_c10}, std::array<u16,5>{1, 2, 3, 4, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("set.slog:143", "delta:st_diff", _fires);
  
      if (!_done)
      {
        ReadTask1176* _cont = new ReadTask1176(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1176(db,b), false);
  // (crule (pre (let _00024sqc5Ylt593 const4b227777d4dd1fc61c6f884f) (let _00024sqc75sY594 const5feceb66ffc86f38d952786c) (let _00024sqc7SC7595 constef2d127de37b942baad06145) (let _00024sqc9xIA596 const6b86b273ff34fce19d6b804e) (let _00024sqc1Dz5597 constd4735e3a265e16eee03f5971) (let _00024sqc3IO1598 constd4735e3a265e16eee03f5971) (let _00024sqc8gB7599 const2c624232cdd221771294dfbb) (let _00024sqc5ClH600 const4e07408562bedb8b60ce05c1) (let _00024sqc3osW601 const6b86b273ff34fce19d6b804e) (let _00024sqo1fme603 constef2d127de37b942baad06145) (let _00024sqo8SDr602 const5feceb66ffc86f38d952786c) (let _00024sqo8V65605 constd4735e3a265e16eee03f5971) (let _00024sqo8H0j604 const6b86b273ff34fce19d6b804e) (let _00024sqo58Kv607 const2c624232cdd221771294dfbb) (let _00024sqo9fPL606 constd4735e3a265e16eee03f5971) (let _00024sqo8Byv609 const6b86b273ff34fce19d6b804e) (let _00024sqo6mXs608 const4e07408562bedb8b60ce05c1) (let _00024sqo1LyP611 constef2d127de37b942baad06145) (let _00024sqo7das610 const4e07408562bedb8b60ce05c1) (let _00024sqo8vL7613 constd4735e3a265e16eee03f5971) (let _00024sqo5GBE612 constd4735e3a265e16eee03f5971) (let _00024sqo1K4x615 const2c624232cdd221771294dfbb) (let _00024sqo0Oce614 const6b86b273ff34fce19d6b804e) (let _00024sqo9RJN617 const6b86b273ff34fce19d6b804e) (let _00024sqo9a1a616 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 2 _00024sqo8H0j604 _00024sqo8V65605 _00024seq0) (body (join $seq_at (1 0 2) 3 _00024sqo8SDr602 _00024sqo1fme603 _00024seq0) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo9fPL606 _00024sqo58Kv607 _00024seq0) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo6mXs608 _00024sqo8Byv609 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo1LyP611 _00024sqo7das610 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo8vL7613 _00024sqo5GBE612 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo1K4x615 _00024sqo0Oce614 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo9RJN617 _00024sqo9a1a616 _00024seq0) (join st_fromlist (1 0) 1 _00024seq0 __t14PV427) (join st_fromlist_ans (0 1) 1 __t14PV427 r) (letp _00024sql0i4I591 (aslst _00024seq0)) (let chk1RXn1297 (llen _00024sql0i4I591)) (eq _00024sqc5Ylt593 chk1RXn1297) (letp chk7L3r1298 (lref _00024sql0i4I591 _00024sqc75sY594)) (eq _00024sqc7SC7595 chk7L3r1298) (letp chk9GK91299 (lref _00024sql0i4I591 _00024sqc9xIA596)) (eq _00024sqc1Dz5597 chk9GK91299) (letp chk5UJE1300 (lref _00024sql0i4I591 _00024sqc3IO1598)) (eq _00024sqc8gB7599 chk5UJE1300) (letp chk8rPG1301 (lref _00024sql0i4I591 _00024sqc5ClH600)) (eq _00024sqc3osW601 chk8rPG1301)) (head (emit canon (0) r)) st_basic.slog:16 #f)
  class ReadTask1213 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex1198;  slog::Index** $seq_atindex1199;  slog::Index** $seq_atindex1200;  slog::Index** $seq_atrindex1201;  slog::Index** $seq_atrindex1202;  slog::Index** $seq_atrindex1203;  slog::Index** $seq_atrindex1204;  slog::Index** st_fromlistindex1205;  slog::Index** st_fromlist_ansindex1206;  slog::Index** $seq_atdelta1207;  slog::Index** $seq_atdelta1208;  slog::Index** $seq_atrdelta1209;  slog::Index** $seq_atrdelta1210;  slog::Index** $seq_atrdelta1211;  slog::Index** $seq_atrdelta1212;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("canon");
      std::vector<u16> ord1214({0});
      slog::Relation* readrel1215 = db->getRelation("canon");
      head_index[0] = readrel1215->getIndex(ord1214, false);
      std::vector<u16> ord1216({1, 0, 2});
      slog::Relation* readrel1217 = db->getRelation("$seq_at");
      driver_index = readrel1217->getIndex(ord1216, true);
      std::vector<u16> ord1218({1, 0, 2});
      slog::Relation* readrel1219 = db->getRelation("$seq_at");
      $seq_atindex1198 = readrel1219->getIndex(ord1218, false);
      std::vector<u16> ord1220({1, 0, 2});
      slog::Relation* readrel1221 = db->getRelation("$seq_at");
      $seq_atindex1199 = readrel1221->getIndex(ord1220, false);
      std::vector<u16> ord1222({1, 0, 2});
      slog::Relation* readrel1223 = db->getRelation("$seq_at");
      $seq_atdelta1207 = readrel1223->getIndex(ord1222, true);
      std::vector<u16> ord1224({1, 0, 2});
      slog::Relation* readrel1225 = db->getRelation("$seq_at");
      $seq_atindex1200 = readrel1225->getIndex(ord1224, false);
      std::vector<u16> ord1226({1, 0, 2});
      slog::Relation* readrel1227 = db->getRelation("$seq_at");
      $seq_atdelta1208 = readrel1227->getIndex(ord1226, true);
      std::vector<u16> ord1228({0, 1, 2});
      slog::Relation* readrel1229 = db->getRelation("$seq_atr");
      $seq_atrindex1201 = readrel1229->getIndex(ord1228, false);
      std::vector<u16> ord1230({0, 1, 2});
      slog::Relation* readrel1231 = db->getRelation("$seq_atr");
      $seq_atrdelta1209 = readrel1231->getIndex(ord1230, true);
      std::vector<u16> ord1232({0, 1, 2});
      slog::Relation* readrel1233 = db->getRelation("$seq_atr");
      $seq_atrindex1202 = readrel1233->getIndex(ord1232, false);
      std::vector<u16> ord1234({0, 1, 2});
      slog::Relation* readrel1235 = db->getRelation("$seq_atr");
      $seq_atrdelta1210 = readrel1235->getIndex(ord1234, true);
      std::vector<u16> ord1236({0, 1, 2});
      slog::Relation* readrel1237 = db->getRelation("$seq_atr");
      $seq_atrindex1203 = readrel1237->getIndex(ord1236, false);
      std::vector<u16> ord1238({0, 1, 2});
      slog::Relation* readrel1239 = db->getRelation("$seq_atr");
      $seq_atrdelta1211 = readrel1239->getIndex(ord1238, true);
      std::vector<u16> ord1240({0, 1, 2});
      slog::Relation* readrel1241 = db->getRelation("$seq_atr");
      $seq_atrindex1204 = readrel1241->getIndex(ord1240, false);
      std::vector<u16> ord1242({0, 1, 2});
      slog::Relation* readrel1243 = db->getRelation("$seq_atr");
      $seq_atrdelta1212 = readrel1243->getIndex(ord1242, true);
      std::vector<u16> ord1244({1, 0});
      slog::Relation* readrel1245 = db->getRelation("st_fromlist");
      st_fromlistindex1205 = readrel1245->getIndex(ord1244, false);
      std::vector<u16> ord1246({0, 1});
      slog::Relation* readrel1247 = db->getRelation("st_fromlist_ans");
      st_fromlist_ansindex1206 = readrel1247->getIndex(ord1246, false);
  
    }
    ReadTask1213(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c182 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c183 = v_const5feceb66ffc86f38d952786c;
      u64 v_c184 = v_constef2d127de37b942baad06145;
      u64 v_c185 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c186 = v_constd4735e3a265e16eee03f5971;
      u64 v_c187 = v_constd4735e3a265e16eee03f5971;
      u64 v_c188 = v_const2c624232cdd221771294dfbb;
      u64 v_c189 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c190 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c191 = v_constef2d127de37b942baad06145;
      u64 v_c192 = v_const5feceb66ffc86f38d952786c;
      u64 v_c193 = v_constd4735e3a265e16eee03f5971;
      u64 v_c194 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c195 = v_const2c624232cdd221771294dfbb;
      u64 v_c196 = v_constd4735e3a265e16eee03f5971;
      u64 v_c197 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c198 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c199 = v_constef2d127de37b942baad06145;
      u64 v_c200 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c201 = v_constd4735e3a265e16eee03f5971;
      u64 v_c202 = v_constd4735e3a265e16eee03f5971;
      u64 v_c203 = v_const2c624232cdd221771294dfbb;
      u64 v_c204 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c205 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c206 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c194, v_c193, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1248) {
        u64 v_c131 = m1248[2];
        if (buckethash(v_c131) != bucket) return;
        slog::join_probe<3,3>($seq_atindex1198, std::array<u64,3>{v_c192, v_c191, v_c131}, [&](const std::array<u64,3>& m1249) {
          slog::join_probe_old<3,3>($seq_atindex1199, $seq_atdelta1207, std::array<u64,3>{v_c196, v_c195, v_c131}, [&](const std::array<u64,3>& m1250) {
            slog::join_probe_old<3,3>($seq_atindex1200, $seq_atdelta1208, std::array<u64,3>{v_c198, v_c197, v_c131}, [&](const std::array<u64,3>& m1251) {
              slog::join_probe_old<3,3>($seq_atrindex1201, $seq_atrdelta1209, std::array<u64,3>{v_c199, v_c200, v_c131}, [&](const std::array<u64,3>& m1252) {
                slog::join_probe_old<3,3>($seq_atrindex1202, $seq_atrdelta1210, std::array<u64,3>{v_c201, v_c202, v_c131}, [&](const std::array<u64,3>& m1253) {
                  slog::join_probe_old<3,3>($seq_atrindex1203, $seq_atrdelta1211, std::array<u64,3>{v_c203, v_c204, v_c131}, [&](const std::array<u64,3>& m1254) {
                    slog::join_probe_old<3,3>($seq_atrindex1204, $seq_atrdelta1212, std::array<u64,3>{v_c205, v_c206, v_c131}, [&](const std::array<u64,3>& m1255) {
                      slog::join_probe<2,1>(st_fromlistindex1205, std::array<u64,2>{v_c131, 0}, [&](const std::array<u64,2>& m1256) {
                        u64 v_c207 = m1256[1];
                        slog::join_probe<2,1>(st_fromlist_ansindex1206, std::array<u64,2>{v_c207, 0}, [&](const std::array<u64,2>& m1257) {
                          u64 v_c19 = m1257[1];
                          bool ok1258 = true;
                          u64 v_c208 = _prim_aslst(db, v_c131, &ok1258);
                          if (!ok1258) return;
                          u64 v_c220 = _prim_llen(db, v_c208);
                          if (v_c220 == slog_error) { slog::emit_pending_error(db, "st_basic.slog:16"); return; }
                          if (v_c182 != v_c220) return;
                          bool ok1259 = true;
                          u64 v_c221 = _prim_lref(db, v_c208, v_c183, &ok1259);
                          if (!ok1259) return;
                          if (v_c184 != v_c221) return;
                          bool ok1260 = true;
                          u64 v_c222 = _prim_lref(db, v_c208, v_c185, &ok1260);
                          if (!ok1260) return;
                          if (v_c186 != v_c222) return;
                          bool ok1261 = true;
                          u64 v_c223 = _prim_lref(db, v_c208, v_c187, &ok1261);
                          if (!ok1261) return;
                          if (v_c188 != v_c223) return;
                          bool ok1262 = true;
                          u64 v_c224 = _prim_lref(db, v_c208, v_c189, &ok1262);
                          if (!ok1262) return;
                          if (v_c190 != v_c224) return;
                          ++_fires;
                          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c19}, std::array<u16,1>{0});
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
  
      if (_fires) db->bumpFires("st_basic.slog:16", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask1213* _cont = new ReadTask1213(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1213(db,b), false);
  // (crule (pre) (scan pleaf __t43Dv181 j) (body (join-old st_del (1 2 0) 1 (1 2 0) __t43Dv181 k __t5Avq182) (neq j k)) (head (emit st_del_ans (0 1) __t5Avq182 __t43Dv181)) set.slog:87 #f)
  class ReadTask1265 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_delindex1263;  slog::Index** st_deldelta1264;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_del_ans");
      std::vector<u16> ord1266({0, 1});
      slog::Relation* readrel1267 = db->getRelation("st_del_ans");
      head_index[0] = readrel1267->getIndex(ord1266, false);
      outer_rel = db->getRelation("pleaf");
      std::vector<u16> ord1268({1, 2, 0});
      slog::Relation* readrel1269 = db->getRelation("st_del");
      st_delindex1263 = readrel1269->getIndex(ord1268, false);
      std::vector<u16> ord1270({1, 2, 0});
      slog::Relation* readrel1271 = db->getRelation("st_del");
      st_deldelta1264 = readrel1271->getIndex(ord1270, true);
  
    }
    ReadTask1265(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c225 = _t[0];
        u64 v_c226 = _t[1];
        slog::join_probe_old<3,1>(st_delindex1263, st_deldelta1264, std::array<u64,3>{v_c225, 0, 0}, [&](const std::array<u64,3>& m1272) {
          u64 v_c65 = m1272[1]; u64 v_c227 = m1272[2];
          if (v_c226 == v_c65) return;
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c227, v_c225}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:87", "delta:pleaf", _fires);
  
      if (!_done)
      {
        ReadTask1265* _cont = new ReadTask1265(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1265(db,b), false);
  // (crule (pre (let __tconst8Ksp764 conste3776bfed7f405de8017ecfa) (let __tconst6tkr379 const6b86b273ff34fce19d6b804e) (let __tconst7Eph382 const2c624232cdd221771294dfbb) (let __tconst4emd384 constd4735e3a265e16eee03f5971) (let __tconst2ksI386 constef2d127de37b942baad06145)) (probe st_ins (2 0 1) 1 __tconst6tkr379 __t2Q6o381 __t6fdj380) (body (join _enum (0 1) 2 __t6fdj380 __tconst8Ksp764) (exists st_ins (2 0 1) 1 __tconst7Eph382) (exists st_ins (2 0 1) 1 __tconst4emd384) (exists st_ins (2 0 1) 1 __tconst2ksI386) (join st_ins_ans (0 1) 1 __t2Q6o381 __v0) (join-old st_ins (1 2 0) 2 (1 2 0) __v0 __tconst7Eph382 __t0FtX383) (join st_ins_ans (0 1) 1 __t0FtX383 __v1) (join-old st_ins (1 2 0) 2 (1 2 0) __v1 __tconst4emd384 __t88YX385) (join st_ins_ans (0 1) 1 __t88YX385 __v2) (join-old st_ins (1 2 0) 2 (1 2 0) __v2 __tconst2ksI386 __t7LWC387) (join st_ins_ans (0 1) 1 __t7LWC387 r)) (head (emit canon (0) r)) st_basic.slog:15 #f)
  class ReadTask1287 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** _enumindex1273;  slog::Index** st_insindex1274;  slog::Index** st_insindex1275;  slog::Index** st_insindex1276;  slog::Index** st_ins_ansindex1277;  slog::Index** st_insindex1278;  slog::Index** st_ins_ansindex1279;  slog::Index** st_insindex1280;  slog::Index** st_ins_ansindex1281;  slog::Index** st_insindex1282;  slog::Index** st_ins_ansindex1283;  slog::Index** st_insdelta1284;  slog::Index** st_insdelta1285;  slog::Index** st_insdelta1286;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("canon");
      std::vector<u16> ord1288({0});
      slog::Relation* readrel1289 = db->getRelation("canon");
      head_index[0] = readrel1289->getIndex(ord1288, false);
      std::vector<u16> ord1290({2, 0, 1});
      slog::Relation* readrel1291 = db->getRelation("st_ins");
      driver_index = readrel1291->getIndex(ord1290, true);
      std::vector<u16> ord1292({0, 1});
      slog::Relation* readrel1293 = db->getRelation("_enum");
      _enumindex1273 = readrel1293->getIndex(ord1292, false);
      std::vector<u16> ord1294({2, 0, 1});
      slog::Relation* readrel1295 = db->getRelation("st_ins");
      st_insindex1274 = readrel1295->getIndex(ord1294, false);
      std::vector<u16> ord1296({2, 0, 1});
      slog::Relation* readrel1297 = db->getRelation("st_ins");
      st_insindex1275 = readrel1297->getIndex(ord1296, false);
      std::vector<u16> ord1298({2, 0, 1});
      slog::Relation* readrel1299 = db->getRelation("st_ins");
      st_insindex1276 = readrel1299->getIndex(ord1298, false);
      std::vector<u16> ord1300({0, 1});
      slog::Relation* readrel1301 = db->getRelation("st_ins_ans");
      st_ins_ansindex1277 = readrel1301->getIndex(ord1300, false);
      std::vector<u16> ord1302({1, 2, 0});
      slog::Relation* readrel1303 = db->getRelation("st_ins");
      st_insindex1278 = readrel1303->getIndex(ord1302, false);
      std::vector<u16> ord1304({1, 2, 0});
      slog::Relation* readrel1305 = db->getRelation("st_ins");
      st_insdelta1284 = readrel1305->getIndex(ord1304, true);
      std::vector<u16> ord1306({0, 1});
      slog::Relation* readrel1307 = db->getRelation("st_ins_ans");
      st_ins_ansindex1279 = readrel1307->getIndex(ord1306, false);
      std::vector<u16> ord1308({1, 2, 0});
      slog::Relation* readrel1309 = db->getRelation("st_ins");
      st_insindex1280 = readrel1309->getIndex(ord1308, false);
      std::vector<u16> ord1310({1, 2, 0});
      slog::Relation* readrel1311 = db->getRelation("st_ins");
      st_insdelta1285 = readrel1311->getIndex(ord1310, true);
      std::vector<u16> ord1312({0, 1});
      slog::Relation* readrel1313 = db->getRelation("st_ins_ans");
      st_ins_ansindex1281 = readrel1313->getIndex(ord1312, false);
      std::vector<u16> ord1314({1, 2, 0});
      slog::Relation* readrel1315 = db->getRelation("st_ins");
      st_insindex1282 = readrel1315->getIndex(ord1314, false);
      std::vector<u16> ord1316({1, 2, 0});
      slog::Relation* readrel1317 = db->getRelation("st_ins");
      st_insdelta1286 = readrel1317->getIndex(ord1316, true);
      std::vector<u16> ord1318({0, 1});
      slog::Relation* readrel1319 = db->getRelation("st_ins_ans");
      st_ins_ansindex1283 = readrel1319->getIndex(ord1318, false);
  
    }
    ReadTask1287(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c228 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c229 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c230 = v_const2c624232cdd221771294dfbb;
      u64 v_c231 = v_constd4735e3a265e16eee03f5971;
      u64 v_c232 = v_constef2d127de37b942baad06145;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c229, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1320) {
        u64 v_c233 = m1320[1];
        u64 v_c234 = m1320[2];
        if (buckethash(v_c233) != bucket) return;
        slog::join_probe<2,2>(_enumindex1273, std::array<u64,2>{v_c234, v_c228}, [&](const std::array<u64,2>& m1321) {
          if (!slog::exists_probe<3,1>(st_insindex1274, std::array<u64,3>{v_c230, 0, 0})) return;
          if (!slog::exists_probe<3,1>(st_insindex1275, std::array<u64,3>{v_c231, 0, 0})) return;
          if (!slog::exists_probe<3,1>(st_insindex1276, std::array<u64,3>{v_c232, 0, 0})) return;
          slog::join_probe<2,1>(st_ins_ansindex1277, std::array<u64,2>{v_c233, 0}, [&](const std::array<u64,2>& m1322) {
            u64 v_c10 = m1322[1];
            slog::join_probe_old<3,2>(st_insindex1278, st_insdelta1284, std::array<u64,3>{v_c10, v_c230, 0}, [&](const std::array<u64,3>& m1323) {
              u64 v_c235 = m1323[2];
              slog::join_probe<2,1>(st_ins_ansindex1279, std::array<u64,2>{v_c235, 0}, [&](const std::array<u64,2>& m1324) {
                u64 v_c6 = m1324[1];
                slog::join_probe_old<3,2>(st_insindex1280, st_insdelta1285, std::array<u64,3>{v_c6, v_c231, 0}, [&](const std::array<u64,3>& m1325) {
                  u64 v_c236 = m1325[2];
                  slog::join_probe<2,1>(st_ins_ansindex1281, std::array<u64,2>{v_c236, 0}, [&](const std::array<u64,2>& m1326) {
                    u64 v_c104 = m1326[1];
                    slog::join_probe_old<3,2>(st_insindex1282, st_insdelta1286, std::array<u64,3>{v_c104, v_c232, 0}, [&](const std::array<u64,3>& m1327) {
                      u64 v_c237 = m1327[2];
                      slog::join_probe<2,1>(st_ins_ansindex1283, std::array<u64,2>{v_c237, 0}, [&](const std::array<u64,2>& m1328) {
                        u64 v_c19 = m1328[1];
                        ++_fires;
                        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c19}, std::array<u16,1>{0});
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
  
      if (_fires) db->bumpFires("st_basic.slog:15", "delta:st_ins", _fires);
  
      if (!_done)
      {
        ReadTask1287* _cont = new ReadTask1287(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1287(db,b), false);
  // (crule (pre (let __tconst4ng4400 const5feceb66ffc86f38d952786c)) (scan st_msk_ans __t7rLj403 __v0) (body (join-old st_msk (0 1 2) 1 (0 1 2) __t7rLj403 k m) (exists pbranch (2 0 1 3 4) 1 m) (exists st_mem0 (2 0 1) 1 k) (join-old $sup9688x69x0x0x0 (1 3 0 2 4 5) 2 (1 3 0 2 4 5) k m __t26uy402 l p r) (neq p __v0) (exists st_mem0 (2 0 1) 2 k __t26uy402) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t4Y7m401) (join-old st_mem0 (0 1 2) 3 (0 1 2) __t26uy402 __t4Y7m401 k)) (head (emit st_mem0_ans (0 1) __t26uy402 __tconst4ng4400)) set.slog:70 #f)
  class ReadTask1340 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_mskindex1329;  slog::Index** pbranchindex1330;  slog::Index** st_mem0index1331;  slog::Index** $sup9688x69x0x0x0index1332;  slog::Index** st_mem0index1333;  slog::Index** pbranchindex1334;  slog::Index** st_mem0index1335;  slog::Index** st_mskdelta1336;  slog::Index** $sup9688x69x0x0x0delta1337;  slog::Index** pbranchdelta1338;  slog::Index** st_mem0delta1339;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_mem0_ans");
      std::vector<u16> ord1341({0, 1});
      slog::Relation* readrel1342 = db->getRelation("st_mem0_ans");
      head_index[0] = readrel1342->getIndex(ord1341, false);
      outer_rel = db->getRelation("st_msk_ans");
      std::vector<u16> ord1343({0, 1, 2});
      slog::Relation* readrel1344 = db->getRelation("st_msk");
      st_mskindex1329 = readrel1344->getIndex(ord1343, false);
      std::vector<u16> ord1345({0, 1, 2});
      slog::Relation* readrel1346 = db->getRelation("st_msk");
      st_mskdelta1336 = readrel1346->getIndex(ord1345, true);
      std::vector<u16> ord1347({2, 0, 1, 3, 4});
      slog::Relation* readrel1348 = db->getRelation("pbranch");
      pbranchindex1330 = readrel1348->getIndex(ord1347, false);
      std::vector<u16> ord1349({2, 0, 1});
      slog::Relation* readrel1350 = db->getRelation("st_mem0");
      st_mem0index1331 = readrel1350->getIndex(ord1349, false);
      std::vector<u16> ord1351({1, 3, 0, 2, 4, 5});
      slog::Relation* readrel1352 = db->getRelation("$sup9688x69x0x0x0");
      $sup9688x69x0x0x0index1332 = readrel1352->getIndex(ord1351, false);
      std::vector<u16> ord1353({1, 3, 0, 2, 4, 5});
      slog::Relation* readrel1354 = db->getRelation("$sup9688x69x0x0x0");
      $sup9688x69x0x0x0delta1337 = readrel1354->getIndex(ord1353, true);
      std::vector<u16> ord1355({2, 0, 1});
      slog::Relation* readrel1356 = db->getRelation("st_mem0");
      st_mem0index1333 = readrel1356->getIndex(ord1355, false);
      std::vector<u16> ord1357({1, 2, 3, 4, 0});
      slog::Relation* readrel1358 = db->getRelation("pbranch");
      pbranchindex1334 = readrel1358->getIndex(ord1357, false);
      std::vector<u16> ord1359({1, 2, 3, 4, 0});
      slog::Relation* readrel1360 = db->getRelation("pbranch");
      pbranchdelta1338 = readrel1360->getIndex(ord1359, true);
      std::vector<u16> ord1361({0, 1, 2});
      slog::Relation* readrel1362 = db->getRelation("st_mem0");
      st_mem0index1335 = readrel1362->getIndex(ord1361, false);
      std::vector<u16> ord1363({0, 1, 2});
      slog::Relation* readrel1364 = db->getRelation("st_mem0");
      st_mem0delta1339 = readrel1364->getIndex(ord1363, true);
  
    }
    ReadTask1340(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c238 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c239 = _t[0];
        u64 v_c10 = _t[1];
        slog::join_probe_old<3,1>(st_mskindex1329, st_mskdelta1336, std::array<u64,3>{v_c239, 0, 0}, [&](const std::array<u64,3>& m1365) {
          u64 v_c65 = m1365[1]; u64 v_c17 = m1365[2];
          if (!slog::exists_probe<5,1>(pbranchindex1330, std::array<u64,5>{v_c17, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(st_mem0index1331, std::array<u64,3>{v_c65, 0, 0})) return;
          slog::join_probe_old<6,2>($sup9688x69x0x0x0index1332, $sup9688x69x0x0x0delta1337, std::array<u64,6>{v_c65, v_c17, 0, 0, 0, 0}, [&](const std::array<u64,6>& m1366) {
            u64 v_c240 = m1366[2]; u64 v_c18 = m1366[3]; u64 v_c16 = m1366[4]; u64 v_c19 = m1366[5];
            if (v_c16 == v_c10) return;
            if (!slog::exists_probe<3,2>(st_mem0index1333, std::array<u64,3>{v_c65, v_c240, 0})) return;
            slog::join_probe_old<5,4>(pbranchindex1334, pbranchdelta1338, std::array<u64,5>{v_c16, v_c17, v_c18, v_c19, 0}, [&](const std::array<u64,5>& m1367) {
              u64 v_c241 = m1367[4];
              slog::join_probe_old<3,3>(st_mem0index1335, st_mem0delta1339, std::array<u64,3>{v_c240, v_c241, v_c65}, [&](const std::array<u64,3>& m1368) {
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c240, v_c238}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:70", "delta:st_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask1340* _cont = new ReadTask1340(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1340(db,b), false);
  // (crule (pre (let __tconst4gCF88 const6b86b273ff34fce19d6b804e)) (probe st_hsb (1 0) 1 __tconst4gCF88 __t16AT89) (body) (head (emit st_hsb_ans (0 1) __t16AT89 __tconst4gCF88)) set.slog:28 #f)
  class ReadTask1369 : public slog::Task
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
      head_rel[0] = db->getRelation("st_hsb_ans");
      std::vector<u16> ord1370({0, 1});
      slog::Relation* readrel1371 = db->getRelation("st_hsb_ans");
      head_index[0] = readrel1371->getIndex(ord1370, false);
      std::vector<u16> ord1372({1, 0});
      slog::Relation* readrel1373 = db->getRelation("st_hsb");
      driver_index = readrel1373->getIndex(ord1372, true);
  
    }
    ReadTask1369(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c242 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c242, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m1374) {
        u64 v_c243 = m1374[1];
        if (buckethash(v_c243) != bucket) return;
        ++_fires;
        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c243, v_c242}, std::array<u16,2>{0, 1});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:28", "delta:st_hsb", _fires);
  
      if (!_done)
      {
        ReadTask1369* _cont = new ReadTask1369(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1369(db,b), false);
  // (crule (pre (let __tconst7O7w336 const5feceb66ffc86f38d952786c)) (scan st_diff_ans __t95th341 __v0) (body (exists st_bld (4 0 1 2 3) 1 __v0) (join-old st_diff (0 1 2) 1 (0 1 2) __t95th341 r __t69OA340) (exists pbranch (4 0 1 2 3) 1 r) (exists $sup9688x142x0x0x0 (6 0 1 2 3 4 5 7 8) 1 r) (join-old st_diff (2 0 1) 1 (2 0 1) __t69OA340 __t8Fy1335 __t88zt334) (exists $sup9688x142x0x0x0 (0 6 1 2 3 4 5 7 8) 2 __t8Fy1335 r) (join-old pbranch (4 0 1 2 3) 2 (4 0 1 2 3) r __t88zt334 p m l) (exists st_bld (1 2 3 4 0) 4 p m l __v0) (exists st_msk (2 0 1) 1 m) (exists st_msk_ans (1 0) 1 p) (join-old $sup9688x142x0x0x0 (4 1 2 6 0 3 5 7 8) 5 (4 1 2 6 0 3 5 7 8) p l m r __t8Fy1335 n q u v) (cmp lt n m) (join-old pbranch (1 2 3 4 0) 5 (1 2 3 4 0) q n u v __t69OA340) (exists st_msk (1 2 0) 2 q m) (join-old st_bld (1 2 3 4 0) 4 (1 2 3 4 0) p m l __v0 __t7XLn338) (exists st_bld_ans (0 1) 1 __t7XLn338) (join-old st_msk (1 2 0) 2 (1 2 0) q m __t19Mr339) (join st_msk_ans (0 1) 2 __t19Mr339 p) (join st_bld_ans (0 1) 1 __t7XLn338 res) (let __t4rbw337 (band q m)) (cmp gt __t4rbw337 __tconst7O7w336)) (head (emit st_diff_ans (0 1) __t8Fy1335 res)) set.slog:143 #f)
  class ReadTask1400 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_bldindex1375;  slog::Index** st_diffindex1376;  slog::Index** pbranchindex1377;  slog::Index** $sup9688x142x0x0x0index1378;  slog::Index** st_diffindex1379;  slog::Index** $sup9688x142x0x0x0index1380;  slog::Index** pbranchindex1381;  slog::Index** st_bldindex1382;  slog::Index** st_mskindex1383;  slog::Index** st_msk_ansindex1384;  slog::Index** $sup9688x142x0x0x0index1385;  slog::Index** pbranchindex1386;  slog::Index** st_mskindex1387;  slog::Index** st_bldindex1388;  slog::Index** st_bld_ansindex1389;  slog::Index** st_mskindex1390;  slog::Index** st_msk_ansindex1391;  slog::Index** st_bld_ansindex1392;  slog::Index** st_diffdelta1393;  slog::Index** st_diffdelta1394;  slog::Index** pbranchdelta1395;  slog::Index** $sup9688x142x0x0x0delta1396;  slog::Index** pbranchdelta1397;  slog::Index** st_blddelta1398;  slog::Index** st_mskdelta1399;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord1401({0, 1});
      slog::Relation* readrel1402 = db->getRelation("st_diff_ans");
      head_index[0] = readrel1402->getIndex(ord1401, false);
      outer_rel = db->getRelation("st_diff_ans");
      std::vector<u16> ord1403({4, 0, 1, 2, 3});
      slog::Relation* readrel1404 = db->getRelation("st_bld");
      st_bldindex1375 = readrel1404->getIndex(ord1403, false);
      std::vector<u16> ord1405({0, 1, 2});
      slog::Relation* readrel1406 = db->getRelation("st_diff");
      st_diffindex1376 = readrel1406->getIndex(ord1405, false);
      std::vector<u16> ord1407({0, 1, 2});
      slog::Relation* readrel1408 = db->getRelation("st_diff");
      st_diffdelta1393 = readrel1408->getIndex(ord1407, true);
      std::vector<u16> ord1409({4, 0, 1, 2, 3});
      slog::Relation* readrel1410 = db->getRelation("pbranch");
      pbranchindex1377 = readrel1410->getIndex(ord1409, false);
      std::vector<u16> ord1411({6, 0, 1, 2, 3, 4, 5, 7, 8});
      slog::Relation* readrel1412 = db->getRelation("$sup9688x142x0x0x0");
      $sup9688x142x0x0x0index1378 = readrel1412->getIndex(ord1411, false);
      std::vector<u16> ord1413({2, 0, 1});
      slog::Relation* readrel1414 = db->getRelation("st_diff");
      st_diffindex1379 = readrel1414->getIndex(ord1413, false);
      std::vector<u16> ord1415({2, 0, 1});
      slog::Relation* readrel1416 = db->getRelation("st_diff");
      st_diffdelta1394 = readrel1416->getIndex(ord1415, true);
      std::vector<u16> ord1417({0, 6, 1, 2, 3, 4, 5, 7, 8});
      slog::Relation* readrel1418 = db->getRelation("$sup9688x142x0x0x0");
      $sup9688x142x0x0x0index1380 = readrel1418->getIndex(ord1417, false);
      std::vector<u16> ord1419({4, 0, 1, 2, 3});
      slog::Relation* readrel1420 = db->getRelation("pbranch");
      pbranchindex1381 = readrel1420->getIndex(ord1419, false);
      std::vector<u16> ord1421({4, 0, 1, 2, 3});
      slog::Relation* readrel1422 = db->getRelation("pbranch");
      pbranchdelta1395 = readrel1422->getIndex(ord1421, true);
      std::vector<u16> ord1423({1, 2, 3, 4, 0});
      slog::Relation* readrel1424 = db->getRelation("st_bld");
      st_bldindex1382 = readrel1424->getIndex(ord1423, false);
      std::vector<u16> ord1425({2, 0, 1});
      slog::Relation* readrel1426 = db->getRelation("st_msk");
      st_mskindex1383 = readrel1426->getIndex(ord1425, false);
      std::vector<u16> ord1427({1, 0});
      slog::Relation* readrel1428 = db->getRelation("st_msk_ans");
      st_msk_ansindex1384 = readrel1428->getIndex(ord1427, false);
      std::vector<u16> ord1429({4, 1, 2, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel1430 = db->getRelation("$sup9688x142x0x0x0");
      $sup9688x142x0x0x0index1385 = readrel1430->getIndex(ord1429, false);
      std::vector<u16> ord1431({4, 1, 2, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel1432 = db->getRelation("$sup9688x142x0x0x0");
      $sup9688x142x0x0x0delta1396 = readrel1432->getIndex(ord1431, true);
      std::vector<u16> ord1433({1, 2, 3, 4, 0});
      slog::Relation* readrel1434 = db->getRelation("pbranch");
      pbranchindex1386 = readrel1434->getIndex(ord1433, false);
      std::vector<u16> ord1435({1, 2, 3, 4, 0});
      slog::Relation* readrel1436 = db->getRelation("pbranch");
      pbranchdelta1397 = readrel1436->getIndex(ord1435, true);
      std::vector<u16> ord1437({1, 2, 0});
      slog::Relation* readrel1438 = db->getRelation("st_msk");
      st_mskindex1387 = readrel1438->getIndex(ord1437, false);
      std::vector<u16> ord1439({1, 2, 3, 4, 0});
      slog::Relation* readrel1440 = db->getRelation("st_bld");
      st_bldindex1388 = readrel1440->getIndex(ord1439, false);
      std::vector<u16> ord1441({1, 2, 3, 4, 0});
      slog::Relation* readrel1442 = db->getRelation("st_bld");
      st_blddelta1398 = readrel1442->getIndex(ord1441, true);
      std::vector<u16> ord1443({0, 1});
      slog::Relation* readrel1444 = db->getRelation("st_bld_ans");
      st_bld_ansindex1389 = readrel1444->getIndex(ord1443, false);
      std::vector<u16> ord1445({1, 2, 0});
      slog::Relation* readrel1446 = db->getRelation("st_msk");
      st_mskindex1390 = readrel1446->getIndex(ord1445, false);
      std::vector<u16> ord1447({1, 2, 0});
      slog::Relation* readrel1448 = db->getRelation("st_msk");
      st_mskdelta1399 = readrel1448->getIndex(ord1447, true);
      std::vector<u16> ord1449({0, 1});
      slog::Relation* readrel1450 = db->getRelation("st_msk_ans");
      st_msk_ansindex1391 = readrel1450->getIndex(ord1449, false);
      std::vector<u16> ord1451({0, 1});
      slog::Relation* readrel1452 = db->getRelation("st_bld_ans");
      st_bld_ansindex1392 = readrel1452->getIndex(ord1451, false);
  
    }
    ReadTask1400(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c244 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c245 = _t[0];
        u64 v_c10 = _t[1];
        if (!slog::exists_probe<5,1>(st_bldindex1375, std::array<u64,5>{v_c10, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(st_diffindex1376, st_diffdelta1393, std::array<u64,3>{v_c245, 0, 0}, [&](const std::array<u64,3>& m1453) {
          u64 v_c19 = m1453[1]; u64 v_c246 = m1453[2];
          if (!slog::exists_probe<5,1>(pbranchindex1377, std::array<u64,5>{v_c19, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<9,1>($sup9688x142x0x0x0index1378, std::array<u64,9>{v_c19, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          slog::join_probe_old<3,1>(st_diffindex1379, st_diffdelta1394, std::array<u64,3>{v_c246, 0, 0}, [&](const std::array<u64,3>& m1454) {
            u64 v_c247 = m1454[1]; u64 v_c248 = m1454[2];
            if (!slog::exists_probe<9,2>($sup9688x142x0x0x0index1380, std::array<u64,9>{v_c247, v_c19, 0, 0, 0, 0, 0, 0, 0})) return;
            slog::join_probe_old<5,2>(pbranchindex1381, pbranchdelta1395, std::array<u64,5>{v_c19, v_c248, 0, 0, 0}, [&](const std::array<u64,5>& m1455) {
              u64 v_c16 = m1455[2]; u64 v_c17 = m1455[3]; u64 v_c18 = m1455[4];
              if (!slog::exists_probe<5,4>(st_bldindex1382, std::array<u64,5>{v_c16, v_c17, v_c18, v_c10, 0})) return;
              if (!slog::exists_probe<3,1>(st_mskindex1383, std::array<u64,3>{v_c17, 0, 0})) return;
              if (!slog::exists_probe<2,1>(st_msk_ansindex1384, std::array<u64,2>{v_c16, 0})) return;
              slog::join_probe_old<9,5>($sup9688x142x0x0x0index1385, $sup9688x142x0x0x0delta1396, std::array<u64,9>{v_c16, v_c18, v_c17, v_c19, v_c247, 0, 0, 0, 0}, [&](const std::array<u64,9>& m1456) {
                u64 v_c23 = m1456[5]; u64 v_c22 = m1456[6]; u64 v_c24 = m1456[7]; u64 v_c25 = m1456[8];
                u64 v_c249 = _prim_lt(db, v_c23, v_c17);
                if (v_c249 == slog_error) { slog::emit_pending_error(db, "set.slog:143"); return; }
                if (!v_c249) return;
                slog::join_probe_old<5,5>(pbranchindex1386, pbranchdelta1397, std::array<u64,5>{v_c22, v_c23, v_c24, v_c25, v_c246}, [&](const std::array<u64,5>& m1458) {
                  if (!slog::exists_probe<3,2>(st_mskindex1387, std::array<u64,3>{v_c22, v_c17, 0})) return;
                  slog::join_probe_old<5,4>(st_bldindex1388, st_blddelta1398, std::array<u64,5>{v_c16, v_c17, v_c18, v_c10, 0}, [&](const std::array<u64,5>& m1459) {
                    u64 v_c250 = m1459[4];
                    if (!slog::exists_probe<2,1>(st_bld_ansindex1389, std::array<u64,2>{v_c250, 0})) return;
                    slog::join_probe_old<3,2>(st_mskindex1390, st_mskdelta1399, std::array<u64,3>{v_c22, v_c17, 0}, [&](const std::array<u64,3>& m1460) {
                      u64 v_c251 = m1460[2];
                      slog::join_probe<2,2>(st_msk_ansindex1391, std::array<u64,2>{v_c251, v_c16}, [&](const std::array<u64,2>& m1461) {
                        slog::join_probe<2,1>(st_bld_ansindex1392, std::array<u64,2>{v_c250, 0}, [&](const std::array<u64,2>& m1462) {
                          u64 v_c74 = m1462[1];
                          u64 v_c252 = _prim_band(db, v_c22, v_c17);
                          if (v_c252 == slog_error) { slog::emit_pending_error(db, "set.slog:143"); return; }
                          u64 v_c253 = _prim_gt(db, v_c252, v_c244);
                          if (v_c253 == slog_error) { slog::emit_pending_error(db, "set.slog:143"); return; }
                          if (!v_c253) return;
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c247, v_c74}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("set.slog:143", "delta:st_diff_ans", _fires);
  
      if (!_done)
      {
        ReadTask1400* _cont = new ReadTask1400(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1400(db,b), false);
  // (crule (pre) (scan st_ins __t7MBh414 __t44oW413 k) (body (join pleaf (0 1) 2 __t44oW413 k)) (head (emit st_ins_ans (0 1) __t7MBh414 __t44oW413)) set.slog:49 #f)
  class ReadTask1465 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pleafindex1464;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_ins_ans");
      std::vector<u16> ord1466({0, 1});
      slog::Relation* readrel1467 = db->getRelation("st_ins_ans");
      head_index[0] = readrel1467->getIndex(ord1466, false);
      outer_rel = db->getRelation("st_ins");
      std::vector<u16> ord1468({0, 1});
      slog::Relation* readrel1469 = db->getRelation("pleaf");
      pleafindex1464 = readrel1469->getIndex(ord1468, false);
  
    }
    ReadTask1465(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c254 = _t[0];
        u64 v_c255 = _t[1];
        u64 v_c65 = _t[2];
        slog::join_probe<2,2>(pleafindex1464, std::array<u64,2>{v_c255, v_c65}, [&](const std::array<u64,2>& m1470) {
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c254, v_c255}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:49", "delta:st_ins", _fires);
  
      if (!_done)
      {
        ReadTask1465* _cont = new ReadTask1465(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1465(db,b), false);
  // (crule (pre (let __trid5BEA1071 const81906d9241165d9f6a541e47) (let __trel7nV51072 const26c89ee8ccc4ea998fd1a912) (let __tcol7NRn1073 constd4735e3a265e16eee03f5971)) (scan st_msk_ans __t3ZZb548 p) (body (exists $sup9688x142x0x0x0 (4 1 2 6 0 3 5 7 8) 1 p) (join-old st_msk (0 1 2) 1 (0 1 2) __t3ZZb548 q m) (exists pbranch (1 2 3 4 0) 1 q) (join $sup9688x142x0x0x0 (2 5 4 0 1 3 6 7 8) 3 m q p __d0 l n r u v) (exists st_diff (1 2 0) 1 r) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t3eTQ549) (join-old st_diff (1 2 0) 2 (1 2 0) r __t3eTQ549 __t7sr4550) (join-old st_diff_ans (0 1) 1 (0 1) __t7sr4550 __v0)) (head (tycheck l (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid5BEA1071 __trel7nV51072 __tcol7NRn1073 (1 2 3 4 0)) (mkstruct st_bld (1 2 3 4 0) __2Xjw1070 p m l __v0)) set.slog:143 #f)
  class ReadTask1486 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x142x0x0x0index1471;  slog::Index** st_mskindex1472;  slog::Index** pbranchindex1473;  slog::Index** $sup9688x142x0x0x0index1474;  slog::Index** st_diffindex1475;  slog::Index** pbranchindex1476;  slog::Index** st_diffindex1477;  slog::Index** st_diff_ansindex1478;  slog::Index** st_mskdelta1479;  slog::Index** pbranchdelta1480;  slog::Index** st_diffdelta1481;  slog::Index** st_diff_ansdelta1482;
    u32 sid1484;  u32 sid1483;  u32 sid1485;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("st_bld");
      outer_rel = db->getRelation("st_msk_ans");
      std::vector<u16> ord1487({4, 1, 2, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel1488 = db->getRelation("$sup9688x142x0x0x0");
      $sup9688x142x0x0x0index1471 = readrel1488->getIndex(ord1487, false);
      std::vector<u16> ord1489({0, 1, 2});
      slog::Relation* readrel1490 = db->getRelation("st_msk");
      st_mskindex1472 = readrel1490->getIndex(ord1489, false);
      std::vector<u16> ord1491({0, 1, 2});
      slog::Relation* readrel1492 = db->getRelation("st_msk");
      st_mskdelta1479 = readrel1492->getIndex(ord1491, true);
      std::vector<u16> ord1493({1, 2, 3, 4, 0});
      slog::Relation* readrel1494 = db->getRelation("pbranch");
      pbranchindex1473 = readrel1494->getIndex(ord1493, false);
      std::vector<u16> ord1495({2, 5, 4, 0, 1, 3, 6, 7, 8});
      slog::Relation* readrel1496 = db->getRelation("$sup9688x142x0x0x0");
      $sup9688x142x0x0x0index1474 = readrel1496->getIndex(ord1495, false);
      std::vector<u16> ord1497({1, 2, 0});
      slog::Relation* readrel1498 = db->getRelation("st_diff");
      st_diffindex1475 = readrel1498->getIndex(ord1497, false);
      std::vector<u16> ord1499({1, 2, 3, 4, 0});
      slog::Relation* readrel1500 = db->getRelation("pbranch");
      pbranchindex1476 = readrel1500->getIndex(ord1499, false);
      std::vector<u16> ord1501({1, 2, 3, 4, 0});
      slog::Relation* readrel1502 = db->getRelation("pbranch");
      pbranchdelta1480 = readrel1502->getIndex(ord1501, true);
      std::vector<u16> ord1503({1, 2, 0});
      slog::Relation* readrel1504 = db->getRelation("st_diff");
      st_diffindex1477 = readrel1504->getIndex(ord1503, false);
      std::vector<u16> ord1505({1, 2, 0});
      slog::Relation* readrel1506 = db->getRelation("st_diff");
      st_diffdelta1481 = readrel1506->getIndex(ord1505, true);
      std::vector<u16> ord1507({0, 1});
      slog::Relation* readrel1508 = db->getRelation("st_diff_ans");
      st_diff_ansindex1478 = readrel1508->getIndex(ord1507, false);
      std::vector<u16> ord1509({0, 1});
      slog::Relation* readrel1510 = db->getRelation("st_diff_ans");
      st_diff_ansdelta1482 = readrel1510->getIndex(ord1509, true);
      sid1484 = db->getRelation("_enum")->getStructId();
      sid1483 = db->getRelation("pbranch")->getStructId();
      sid1485 = db->getRelation("pleaf")->getStructId();
  
    }
    ReadTask1486(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c214 = v_const81906d9241165d9f6a541e47;
      u64 v_c215 = v_const26c89ee8ccc4ea998fd1a912;
      u64 v_c216 = v_constd4735e3a265e16eee03f5971;
  
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
        u64 v_c16 = _t[1];
        if (!slog::exists_probe<9,1>($sup9688x142x0x0x0index1471, std::array<u64,9>{v_c16, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(st_mskindex1472, st_mskdelta1479, std::array<u64,3>{v_c219, 0, 0}, [&](const std::array<u64,3>& m1511) {
          u64 v_c22 = m1511[1]; u64 v_c17 = m1511[2];
          if (!slog::exists_probe<5,1>(pbranchindex1473, std::array<u64,5>{v_c22, 0, 0, 0, 0})) return;
          slog::join_probe<9,3>($sup9688x142x0x0x0index1474, std::array<u64,9>{v_c17, v_c22, v_c16, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m1512) {
            u64 v_c40 = m1512[3]; u64 v_c18 = m1512[4]; u64 v_c23 = m1512[5]; u64 v_c19 = m1512[6]; u64 v_c24 = m1512[7]; u64 v_c25 = m1512[8];
            if (!slog::exists_probe<3,1>(st_diffindex1475, std::array<u64,3>{v_c19, 0, 0})) return;
            slog::join_probe_old<5,4>(pbranchindex1476, pbranchdelta1480, std::array<u64,5>{v_c22, v_c23, v_c24, v_c25, 0}, [&](const std::array<u64,5>& m1513) {
              u64 v_c218 = m1513[4];
              slog::join_probe_old<3,2>(st_diffindex1477, st_diffdelta1481, std::array<u64,3>{v_c19, v_c218, 0}, [&](const std::array<u64,3>& m1514) {
                u64 v_c217 = m1514[2];
                slog::join_probe_old<2,1>(st_diff_ansindex1478, st_diff_ansdelta1482, std::array<u64,2>{v_c217, 0}, [&](const std::array<u64,2>& m1515) {
                  u64 v_c10 = m1515[1];
                  ++_fires;
                  if (!((is_struct(v_c18) && (decode_struct_id(v_c18) == sid1483 || decode_struct_id(v_c18) == sid1484 || decode_struct_id(v_c18) == sid1485))))
                  {
                    slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c214, v_c215, v_c216, v_c18}, std::array<u16,5>{1, 2, 3, 4, 0});
                    return;
                  }
                  slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c16, v_c17, v_c18, v_c10}, std::array<u16,5>{1, 2, 3, 4, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("set.slog:143", "delta:st_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask1486* _cont = new ReadTask1486(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1486(db,b), false);
}

