
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const2c624232cdd221771294dfbb;
extern u64 v_const5df67abc0c9885765912ad3d;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_consta10f76b4ec574de5d7b6908e;
extern u64 v_constbeaae0387ae49b5204a99e32;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_constd9f85eba98ed33f6c0ac9bf6;
extern u64 v_conste3776bfed7f405de8017ecfa;
extern u64 v_constef2d127de37b942baad06145;


void slog_rules_c8c9720fd6e0bc4f9(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre (let __tconst19LZ687 conste3776bfed7f405de8017ecfa) (let __tconst6nio451 constef2d127de37b942baad06145) (let __tconst5Crw454 constd4735e3a265e16eee03f5971) (let __tconst7cMm457 const2c624232cdd221771294dfbb) (let __tconst776G459 const6b86b273ff34fce19d6b804e)) (probe st_ins (2 0 1) 1 __tconst7cMm457 __t6eAo458 __v0) (body (exists st_ins (2 0 1) 1 __tconst6nio451) (exists st_ins_ans (1 0) 1 __v0) (exists st_ins (2 0 1) 1 __tconst5Crw454) (exists st_ins (2 0 1) 1 __tconst776G459) (exists st_ins_ans (0 1) 1 __t6eAo458) (join _enum (1 0) 1 __tconst19LZ687 __t82EP455) (exists st_ins (1 2 0) 2 __t82EP455 __tconst5Crw454) (join st_ins (1 2 0) 2 __t82EP455 __tconst6nio451 __t6TRN453) (join st_ins_ans (0 1) 2 __t6TRN453 __v0) (join st_ins (1 2 0) 2 __t82EP455 __tconst5Crw454 __t7k0a456) (join st_ins_ans (0 1) 1 __t7k0a456 __v1) (join-old st_ins (1 2 0) 2 (1 2 0) __v1 __tconst776G459 __t7DB2460) (exists st_ins_ans (0 1) 1 __t7DB2460) (join st_ins_ans (0 1) 1 __t6eAo458 a) (join st_ins_ans (0 1) 1 __t7DB2460 b)) (head (mkstruct st_union (1 2 0) __6Awq688 a b)) st_basic.slog:18 #f)
  class ReadTask16 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** st_insindex0;  slog::Index** st_ins_ansindex1;  slog::Index** st_insindex2;  slog::Index** st_insindex3;  slog::Index** st_ins_ansindex4;  slog::Index** _enumindex5;  slog::Index** st_insindex6;  slog::Index** st_insindex7;  slog::Index** st_ins_ansindex8;  slog::Index** st_insindex9;  slog::Index** st_ins_ansindex10;  slog::Index** st_insindex11;  slog::Index** st_ins_ansindex12;  slog::Index** st_ins_ansindex13;  slog::Index** st_ins_ansindex14;  slog::Index** st_insdelta15;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_union");
      std::vector<u16> ord17({2, 0, 1});
      slog::Relation* readrel18 = db->getRelation("st_ins");
      driver_index = readrel18->getIndex(ord17, true);
      std::vector<u16> ord19({2, 0, 1});
      slog::Relation* readrel20 = db->getRelation("st_ins");
      st_insindex0 = readrel20->getIndex(ord19, false);
      std::vector<u16> ord21({1, 0});
      slog::Relation* readrel22 = db->getRelation("st_ins_ans");
      st_ins_ansindex1 = readrel22->getIndex(ord21, false);
      std::vector<u16> ord23({2, 0, 1});
      slog::Relation* readrel24 = db->getRelation("st_ins");
      st_insindex2 = readrel24->getIndex(ord23, false);
      std::vector<u16> ord25({2, 0, 1});
      slog::Relation* readrel26 = db->getRelation("st_ins");
      st_insindex3 = readrel26->getIndex(ord25, false);
      std::vector<u16> ord27({0, 1});
      slog::Relation* readrel28 = db->getRelation("st_ins_ans");
      st_ins_ansindex4 = readrel28->getIndex(ord27, false);
      std::vector<u16> ord29({1, 0});
      slog::Relation* readrel30 = db->getRelation("_enum");
      _enumindex5 = readrel30->getIndex(ord29, false);
      std::vector<u16> ord31({1, 2, 0});
      slog::Relation* readrel32 = db->getRelation("st_ins");
      st_insindex6 = readrel32->getIndex(ord31, false);
      std::vector<u16> ord33({1, 2, 0});
      slog::Relation* readrel34 = db->getRelation("st_ins");
      st_insindex7 = readrel34->getIndex(ord33, false);
      std::vector<u16> ord35({0, 1});
      slog::Relation* readrel36 = db->getRelation("st_ins_ans");
      st_ins_ansindex8 = readrel36->getIndex(ord35, false);
      std::vector<u16> ord37({1, 2, 0});
      slog::Relation* readrel38 = db->getRelation("st_ins");
      st_insindex9 = readrel38->getIndex(ord37, false);
      std::vector<u16> ord39({0, 1});
      slog::Relation* readrel40 = db->getRelation("st_ins_ans");
      st_ins_ansindex10 = readrel40->getIndex(ord39, false);
      std::vector<u16> ord41({1, 2, 0});
      slog::Relation* readrel42 = db->getRelation("st_ins");
      st_insindex11 = readrel42->getIndex(ord41, false);
      std::vector<u16> ord43({1, 2, 0});
      slog::Relation* readrel44 = db->getRelation("st_ins");
      st_insdelta15 = readrel44->getIndex(ord43, true);
      std::vector<u16> ord45({0, 1});
      slog::Relation* readrel46 = db->getRelation("st_ins_ans");
      st_ins_ansindex12 = readrel46->getIndex(ord45, false);
      std::vector<u16> ord47({0, 1});
      slog::Relation* readrel48 = db->getRelation("st_ins_ans");
      st_ins_ansindex13 = readrel48->getIndex(ord47, false);
      std::vector<u16> ord49({0, 1});
      slog::Relation* readrel50 = db->getRelation("st_ins_ans");
      st_ins_ansindex14 = readrel50->getIndex(ord49, false);
  
    }
    ReadTask16(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c3, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m51) {
        u64 v_c5 = m51[1];
        u64 v_c6 = m51[2];
        if (buckethash(v_c5) != bucket) return;
        if (!slog::exists_probe<3,1>(st_insindex0, std::array<u64,3>{v_c1, 0, 0})) return;
        if (!slog::exists_probe<2,1>(st_ins_ansindex1, std::array<u64,2>{v_c6, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex2, std::array<u64,3>{v_c2, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex3, std::array<u64,3>{v_c4, 0, 0})) return;
        if (!slog::exists_probe<2,1>(st_ins_ansindex4, std::array<u64,2>{v_c5, 0})) return;
        slog::join_probe<2,1>(_enumindex5, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m52) {
          u64 v_c7 = m52[1];
          if (!slog::exists_probe<3,2>(st_insindex6, std::array<u64,3>{v_c7, v_c2, 0})) return;
          slog::join_probe<3,2>(st_insindex7, std::array<u64,3>{v_c7, v_c1, 0}, [&](const std::array<u64,3>& m53) {
            u64 v_c8 = m53[2];
            slog::join_probe<2,2>(st_ins_ansindex8, std::array<u64,2>{v_c8, v_c6}, [&](const std::array<u64,2>& m54) {
              slog::join_probe<3,2>(st_insindex9, std::array<u64,3>{v_c7, v_c2, 0}, [&](const std::array<u64,3>& m55) {
                u64 v_c9 = m55[2];
                slog::join_probe<2,1>(st_ins_ansindex10, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m56) {
                  u64 v_c10 = m56[1];
                  slog::join_probe_old<3,2>(st_insindex11, st_insdelta15, std::array<u64,3>{v_c10, v_c4, 0}, [&](const std::array<u64,3>& m57) {
                    u64 v_c11 = m57[2];
                    if (!slog::exists_probe<2,1>(st_ins_ansindex12, std::array<u64,2>{v_c11, 0})) return;
                    slog::join_probe<2,1>(st_ins_ansindex13, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m58) {
                      u64 v_c12 = m58[1];
                      slog::join_probe<2,1>(st_ins_ansindex14, std::array<u64,2>{v_c11, 0}, [&](const std::array<u64,2>& m59) {
                        u64 v_c13 = m59[1];
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
        ReadTask16* _cont = new ReadTask16(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask16(db,b), false);
  // (crule (pre (let __tconst0XIw307 const5feceb66ffc86f38d952786c)) (scan pbranch __t4jxi305 p m l r) (body (join-old st_union (1 2 0) 1 (1 2 0) __t4jxi305 __t3Mhw304 __t8fFv306) (join pbranch (0 1 2 3 4) 1 __t3Mhw304 q n u v) (cmp lt n m) (let __t3ur5308 (band q m)) (cmp gt __t3ur5308 __tconst0XIw307)) (head (emit $sup9688x106x0x0x0 (0 6 1 2 3 4 5 7 8) __t8fFv306 r l m n p q u v)) set.slog:107 #f)
  class ReadTask63 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_unionindex60;  slog::Index** pbranchindex61;  slog::Index** st_uniondelta62;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x106x0x0x0");
      std::vector<u16> ord64({0, 6, 1, 2, 3, 4, 5, 7, 8});
      slog::Relation* readrel65 = db->getRelation("$sup9688x106x0x0x0");
      head_index[0] = readrel65->getIndex(ord64, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord66({1, 2, 0});
      slog::Relation* readrel67 = db->getRelation("st_union");
      st_unionindex60 = readrel67->getIndex(ord66, false);
      std::vector<u16> ord68({1, 2, 0});
      slog::Relation* readrel69 = db->getRelation("st_union");
      st_uniondelta62 = readrel69->getIndex(ord68, true);
      std::vector<u16> ord70({0, 1, 2, 3, 4});
      slog::Relation* readrel71 = db->getRelation("pbranch");
      pbranchindex61 = readrel71->getIndex(ord70, false);
  
    }
    ReadTask63(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe_old<3,1>(st_unionindex60, st_uniondelta62, std::array<u64,3>{v_c15, 0, 0}, [&](const std::array<u64,3>& m72) {
          u64 v_c20 = m72[1]; u64 v_c21 = m72[2];
          slog::join_probe<5,1>(pbranchindex61, std::array<u64,5>{v_c20, 0, 0, 0, 0}, [&](const std::array<u64,5>& m73) {
            u64 v_c22 = m73[1]; u64 v_c23 = m73[2]; u64 v_c24 = m73[3]; u64 v_c25 = m73[4];
            u64 v_c26 = _prim_lt(db, v_c23, v_c17);
            if (v_c26 == slog_error) { slog::emit_pending_error(db, "set.slog:107"); return; }
            if (!v_c26) return;
            u64 v_c27 = _prim_band(db, v_c22, v_c17);
            if (v_c27 == slog_error) { slog::emit_pending_error(db, "set.slog:107"); return; }
            u64 v_c28 = _prim_gt(db, v_c27, v_c14);
            if (v_c28 == slog_error) { slog::emit_pending_error(db, "set.slog:107"); return; }
            if (!v_c28) return;
            ++_fires;
            slog::emit<9>(head_rel[0], head_index[0], newbatch[0], std::array<u64,9>{v_c21, v_c19, v_c18, v_c17, v_c23, v_c16, v_c22, v_c24, v_c25}, std::array<u16,9>{0, 6, 1, 2, 3, 4, 5, 7, 8});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:107", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask63* _cont = new ReadTask63(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask63(db,b), false);
  // (crule (pre (let __trid9jhA753 const5df67abc0c9885765912ad3d) (let __trel2i7G754 consta10f76b4ec574de5d7b6908e) (let __tcol7F5z755 const5feceb66ffc86f38d952786c) (let __trel6gFQ756 consta10f76b4ec574de5d7b6908e) (let __tcol42vV757 const6b86b273ff34fce19d6b804e)) (scan $sup9688x36x0x0x2 __d0 __d1 __d2 __d4 __v0 __v1 __v3 p0 p1 t0 t1) (body) (head (tycheck p0 (accept int) __trid9jhA753 __trel2i7G754 __tcol7F5z755 (1 2 3 4 0)) (tycheck __v1 (accept int) __trid9jhA753 __trel6gFQ756 __tcol42vV757 (1 2 3 4 0)) (mkstruct st_msk (1 2 0) __2VRr752 p0 __v1)) set.slog:37 #f)
  class ReadTask76 : public slog::Task
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
      head_rel[2] = db->getRelation("st_msk");
      outer_rel = db->getRelation("$sup9688x36x0x0x2");
  
    }
    ReadTask76(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c29 = v_const5df67abc0c9885765912ad3d;
      u64 v_c30 = v_consta10f76b4ec574de5d7b6908e;
      u64 v_c31 = v_const5feceb66ffc86f38d952786c;
      u64 v_c32 = v_consta10f76b4ec574de5d7b6908e;
      u64 v_c33 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c34 = _t[0];
        u64 v_c35 = _t[1];
        u64 v_c36 = _t[2];
        u64 v_c37 = _t[3];
        u64 v_c6 = _t[4];
        u64 v_c10 = _t[5];
        u64 v_c38 = _t[6];
        u64 v_c39 = _t[7];
        u64 v_c40 = _t[8];
        u64 v_c41 = _t[9];
        u64 v_c42 = _t[10];
        ++_fires;
        if (!(is_int(v_c39)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c29, v_c30, v_c31, v_c39}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c10)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c29, v_c32, v_c33, v_c10}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c39, v_c10}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("set.slog:37", "delta:$sup9688x36x0x0x2", _fires);
  
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
  // (crule (pre (let __tconst0UIr907 conste3776bfed7f405de8017ecfa) (let __tconst67v2432 constef2d127de37b942baad06145) (let __tconst3Prp435 constd4735e3a265e16eee03f5971) (let __tconst4LVH431 const6b86b273ff34fce19d6b804e)) (scan st_ins_ans __t1RFt437 __v1) (body (exists _enum (1 0) 1 __tconst0UIr907) (exists st_ins (2 0 1) 1 __tconst67v2432) (join-old st_ins (0 2 1) 2 (0 2 1) __t1RFt437 __tconst3Prp435 __t5QG4436) (join _enum (0 1) 2 __t5QG4436 __tconst0UIr907) (join-old st_ins (1 2 0) 2 (1 2 0) __t5QG4436 __tconst67v2432 __t2Qai434) (join st_ins_ans (0 1) 1 __t2Qai434 __v0)) (head (mkstruct st_ins (1 2 0) __12BV908 __v1 __tconst4LVH431)) st_basic.slog:18 #f)
  class ReadTask85 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex77;  slog::Index** st_insindex78;  slog::Index** st_insindex79;  slog::Index** _enumindex80;  slog::Index** st_insindex81;  slog::Index** st_ins_ansindex82;  slog::Index** st_insdelta83;  slog::Index** st_insdelta84;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_ins");
      outer_rel = db->getRelation("st_ins_ans");
      std::vector<u16> ord86({1, 0});
      slog::Relation* readrel87 = db->getRelation("_enum");
      _enumindex77 = readrel87->getIndex(ord86, false);
      std::vector<u16> ord88({2, 0, 1});
      slog::Relation* readrel89 = db->getRelation("st_ins");
      st_insindex78 = readrel89->getIndex(ord88, false);
      std::vector<u16> ord90({0, 2, 1});
      slog::Relation* readrel91 = db->getRelation("st_ins");
      st_insindex79 = readrel91->getIndex(ord90, false);
      std::vector<u16> ord92({0, 2, 1});
      slog::Relation* readrel93 = db->getRelation("st_ins");
      st_insdelta83 = readrel93->getIndex(ord92, true);
      std::vector<u16> ord94({0, 1});
      slog::Relation* readrel95 = db->getRelation("_enum");
      _enumindex80 = readrel95->getIndex(ord94, false);
      std::vector<u16> ord96({1, 2, 0});
      slog::Relation* readrel97 = db->getRelation("st_ins");
      st_insindex81 = readrel97->getIndex(ord96, false);
      std::vector<u16> ord98({1, 2, 0});
      slog::Relation* readrel99 = db->getRelation("st_ins");
      st_insdelta84 = readrel99->getIndex(ord98, true);
      std::vector<u16> ord100({0, 1});
      slog::Relation* readrel101 = db->getRelation("st_ins_ans");
      st_ins_ansindex82 = readrel101->getIndex(ord100, false);
  
    }
    ReadTask85(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c43 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c44 = v_constef2d127de37b942baad06145;
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
        u64 v_c10 = _t[1];
        if (!slog::exists_probe<2,1>(_enumindex77, std::array<u64,2>{v_c43, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex78, std::array<u64,3>{v_c44, 0, 0})) return;
        slog::join_probe_old<3,2>(st_insindex79, st_insdelta83, std::array<u64,3>{v_c47, v_c45, 0}, [&](const std::array<u64,3>& m102) {
          u64 v_c48 = m102[2];
          slog::join_probe<2,2>(_enumindex80, std::array<u64,2>{v_c48, v_c43}, [&](const std::array<u64,2>& m103) {
            slog::join_probe_old<3,2>(st_insindex81, st_insdelta84, std::array<u64,3>{v_c48, v_c44, 0}, [&](const std::array<u64,3>& m104) {
              u64 v_c49 = m104[2];
              slog::join_probe<2,1>(st_ins_ansindex82, std::array<u64,2>{v_c49, 0}, [&](const std::array<u64,2>& m105) {
                u64 v_c6 = m105[1];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c10, v_c46}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("st_basic.slog:18", "delta:st_ins_ans", _fires);
  
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
  // (crule (pre (let __trid9vzr1014 constd9f85eba98ed33f6c0ac9bf6) (let __trel83YH1015 consta10f76b4ec574de5d7b6908e) (let __tcol3Q6u1016 const5feceb66ffc86f38d952786c) (let __trel5gws1017 consta10f76b4ec574de5d7b6908e) (let __tcol5HCS1018 const6b86b273ff34fce19d6b804e)) (scan $sup9688x54x0x0x0 __d0 k l m p r t) (body) (head (tycheck k (accept int) __trid9vzr1014 __trel83YH1015 __tcol3Q6u1016 (1 2 3 4 0)) (tycheck m (accept int) __trid9vzr1014 __trel5gws1017 __tcol5HCS1018 (1 2 3 4 0)) (mkstruct st_msk (1 2 0) __6c9y1013 k m)) set.slog:55 #f)
  class ReadTask106 : public slog::Task
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
      head_rel[2] = db->getRelation("st_msk");
      outer_rel = db->getRelation("$sup9688x54x0x0x0");
  
    }
    ReadTask106(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c50 = v_constd9f85eba98ed33f6c0ac9bf6;
      u64 v_c51 = v_consta10f76b4ec574de5d7b6908e;
      u64 v_c52 = v_const5feceb66ffc86f38d952786c;
      u64 v_c53 = v_consta10f76b4ec574de5d7b6908e;
      u64 v_c54 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c34 = _t[0];
        u64 v_c55 = _t[1];
        u64 v_c18 = _t[2];
        u64 v_c17 = _t[3];
        u64 v_c16 = _t[4];
        u64 v_c19 = _t[5];
        u64 v_c56 = _t[6];
        ++_fires;
        if (!(is_int(v_c55)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c50, v_c51, v_c52, v_c55}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c17)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c50, v_c53, v_c54, v_c17}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c55, v_c17}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("set.slog:55", "delta:$sup9688x54x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask106* _cont = new ReadTask106(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask106(db,b), false);
  // (crule (pre (let __tconst19LZ687 conste3776bfed7f405de8017ecfa) (let __tconst6nio451 constef2d127de37b942baad06145) (let __tconst5Crw454 constd4735e3a265e16eee03f5971) (let __tconst7cMm457 const2c624232cdd221771294dfbb) (let __tconst776G459 const6b86b273ff34fce19d6b804e)) (scan st_ins_ans __t7k0a456 __v1) (body (exists _enum (1 0) 1 __tconst19LZ687) (exists st_ins (2 0 1) 1 __tconst6nio451) (exists st_ins (1 2 0) 2 __v1 __tconst776G459) (exists st_ins (2 0 1) 1 __tconst7cMm457) (join-old st_ins (0 2 1) 2 (0 2 1) __t7k0a456 __tconst5Crw454 __t82EP455) (join _enum (0 1) 2 __t82EP455 __tconst19LZ687) (join-old st_ins (1 2 0) 2 (1 2 0) __t82EP455 __tconst6nio451 __t6TRN453) (exists st_ins_ans (0 1) 1 __t6TRN453) (join-old st_ins (1 2 0) 2 (1 2 0) __v1 __tconst776G459 __t7DB2460) (exists st_ins_ans (0 1) 1 __t7DB2460) (join st_ins_ans (0 1) 1 __t6TRN453 __v0) (join-old st_ins (1 2 0) 2 (1 2 0) __v0 __tconst7cMm457 __t6eAo458) (join-old st_ins_ans (0 1) 1 (0 1) __t6eAo458 a) (join-old st_ins_ans (0 1) 1 (0 1) __t7DB2460 b)) (head (mkstruct st_union (1 2 0) __6Awq688 a b)) st_basic.slog:18 #f)
  class ReadTask127 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex107;  slog::Index** st_insindex108;  slog::Index** st_insindex109;  slog::Index** st_insindex110;  slog::Index** st_insindex111;  slog::Index** _enumindex112;  slog::Index** st_insindex113;  slog::Index** st_ins_ansindex114;  slog::Index** st_insindex115;  slog::Index** st_ins_ansindex116;  slog::Index** st_ins_ansindex117;  slog::Index** st_insindex118;  slog::Index** st_ins_ansindex119;  slog::Index** st_ins_ansindex120;  slog::Index** st_insdelta121;  slog::Index** st_insdelta122;  slog::Index** st_insdelta123;  slog::Index** st_insdelta124;  slog::Index** st_ins_ansdelta125;  slog::Index** st_ins_ansdelta126;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_union");
      outer_rel = db->getRelation("st_ins_ans");
      std::vector<u16> ord128({1, 0});
      slog::Relation* readrel129 = db->getRelation("_enum");
      _enumindex107 = readrel129->getIndex(ord128, false);
      std::vector<u16> ord130({2, 0, 1});
      slog::Relation* readrel131 = db->getRelation("st_ins");
      st_insindex108 = readrel131->getIndex(ord130, false);
      std::vector<u16> ord132({1, 2, 0});
      slog::Relation* readrel133 = db->getRelation("st_ins");
      st_insindex109 = readrel133->getIndex(ord132, false);
      std::vector<u16> ord134({2, 0, 1});
      slog::Relation* readrel135 = db->getRelation("st_ins");
      st_insindex110 = readrel135->getIndex(ord134, false);
      std::vector<u16> ord136({0, 2, 1});
      slog::Relation* readrel137 = db->getRelation("st_ins");
      st_insindex111 = readrel137->getIndex(ord136, false);
      std::vector<u16> ord138({0, 2, 1});
      slog::Relation* readrel139 = db->getRelation("st_ins");
      st_insdelta121 = readrel139->getIndex(ord138, true);
      std::vector<u16> ord140({0, 1});
      slog::Relation* readrel141 = db->getRelation("_enum");
      _enumindex112 = readrel141->getIndex(ord140, false);
      std::vector<u16> ord142({1, 2, 0});
      slog::Relation* readrel143 = db->getRelation("st_ins");
      st_insindex113 = readrel143->getIndex(ord142, false);
      std::vector<u16> ord144({1, 2, 0});
      slog::Relation* readrel145 = db->getRelation("st_ins");
      st_insdelta122 = readrel145->getIndex(ord144, true);
      std::vector<u16> ord146({0, 1});
      slog::Relation* readrel147 = db->getRelation("st_ins_ans");
      st_ins_ansindex114 = readrel147->getIndex(ord146, false);
      std::vector<u16> ord148({1, 2, 0});
      slog::Relation* readrel149 = db->getRelation("st_ins");
      st_insindex115 = readrel149->getIndex(ord148, false);
      std::vector<u16> ord150({1, 2, 0});
      slog::Relation* readrel151 = db->getRelation("st_ins");
      st_insdelta123 = readrel151->getIndex(ord150, true);
      std::vector<u16> ord152({0, 1});
      slog::Relation* readrel153 = db->getRelation("st_ins_ans");
      st_ins_ansindex116 = readrel153->getIndex(ord152, false);
      std::vector<u16> ord154({0, 1});
      slog::Relation* readrel155 = db->getRelation("st_ins_ans");
      st_ins_ansindex117 = readrel155->getIndex(ord154, false);
      std::vector<u16> ord156({1, 2, 0});
      slog::Relation* readrel157 = db->getRelation("st_ins");
      st_insindex118 = readrel157->getIndex(ord156, false);
      std::vector<u16> ord158({1, 2, 0});
      slog::Relation* readrel159 = db->getRelation("st_ins");
      st_insdelta124 = readrel159->getIndex(ord158, true);
      std::vector<u16> ord160({0, 1});
      slog::Relation* readrel161 = db->getRelation("st_ins_ans");
      st_ins_ansindex119 = readrel161->getIndex(ord160, false);
      std::vector<u16> ord162({0, 1});
      slog::Relation* readrel163 = db->getRelation("st_ins_ans");
      st_ins_ansdelta125 = readrel163->getIndex(ord162, true);
      std::vector<u16> ord164({0, 1});
      slog::Relation* readrel165 = db->getRelation("st_ins_ans");
      st_ins_ansindex120 = readrel165->getIndex(ord164, false);
      std::vector<u16> ord166({0, 1});
      slog::Relation* readrel167 = db->getRelation("st_ins_ans");
      st_ins_ansdelta126 = readrel167->getIndex(ord166, true);
  
    }
    ReadTask127(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c9 = _t[0];
        u64 v_c10 = _t[1];
        if (!slog::exists_probe<2,1>(_enumindex107, std::array<u64,2>{v_c0, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex108, std::array<u64,3>{v_c1, 0, 0})) return;
        if (!slog::exists_probe<3,2>(st_insindex109, std::array<u64,3>{v_c10, v_c4, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex110, std::array<u64,3>{v_c3, 0, 0})) return;
        slog::join_probe_old<3,2>(st_insindex111, st_insdelta121, std::array<u64,3>{v_c9, v_c2, 0}, [&](const std::array<u64,3>& m168) {
          u64 v_c7 = m168[2];
          slog::join_probe<2,2>(_enumindex112, std::array<u64,2>{v_c7, v_c0}, [&](const std::array<u64,2>& m169) {
            slog::join_probe_old<3,2>(st_insindex113, st_insdelta122, std::array<u64,3>{v_c7, v_c1, 0}, [&](const std::array<u64,3>& m170) {
              u64 v_c8 = m170[2];
              if (!slog::exists_probe<2,1>(st_ins_ansindex114, std::array<u64,2>{v_c8, 0})) return;
              slog::join_probe_old<3,2>(st_insindex115, st_insdelta123, std::array<u64,3>{v_c10, v_c4, 0}, [&](const std::array<u64,3>& m171) {
                u64 v_c11 = m171[2];
                if (!slog::exists_probe<2,1>(st_ins_ansindex116, std::array<u64,2>{v_c11, 0})) return;
                slog::join_probe<2,1>(st_ins_ansindex117, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m172) {
                  u64 v_c6 = m172[1];
                  slog::join_probe_old<3,2>(st_insindex118, st_insdelta124, std::array<u64,3>{v_c6, v_c3, 0}, [&](const std::array<u64,3>& m173) {
                    u64 v_c5 = m173[2];
                    slog::join_probe_old<2,1>(st_ins_ansindex119, st_ins_ansdelta125, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m174) {
                      u64 v_c12 = m174[1];
                      slog::join_probe_old<2,1>(st_ins_ansindex120, st_ins_ansdelta126, std::array<u64,2>{v_c11, 0}, [&](const std::array<u64,2>& m175) {
                        u64 v_c13 = m175[1];
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
  
      if (_fires) db->bumpFires("st_basic.slog:18", "delta:st_ins_ans", _fires);
  
      if (!_done)
      {
        ReadTask127* _cont = new ReadTask127(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask127(db,b), false);
  // (crule (pre (let __tconst0v7T491 const5feceb66ffc86f38d952786c)) (scan st_msk __t44Py494 k m) (body (exists $sup9688x90x0x0x0 (1 3 4 0 2 5) 2 k m) (exists pbranch (2 0 1 3 4) 1 m) (exists st_del (2 0 1) 1 k) (exists st_bld (2 1 4 0 3) 1 m) (join st_msk_ans (0 1) 1 __t44Py494 p) (exists pbranch (1 2 3 4 0) 2 p m) (exists st_bld (1 2 3 4 0) 2 p m) (join $sup9688x90x0x0x0 (1 3 4 0 2 5) 3 k m p __t3j4h490 l r) (exists st_del (0 2 1) 2 __t3j4h490 k) (exists st_bld (1 2 3 4 0) 3 p m l) (exists st_del (1 2 0) 2 r k) (join pbranch (1 2 3 4 0) 4 p m l r __t4hkT489) (join st_del (0 2 1) 3 __t3j4h490 k __t4hkT489) (join st_bld (1 2 3 4 0) 3 p m l __v0 __t8CKV493) (exists st_del_ans (1 0) 1 __v0) (exists st_bld_ans (0 1) 1 __t8CKV493) (join-old st_del (1 2 0) 2 (1 2 0) r k __t9BRr495) (join st_del_ans (0 1) 2 __t9BRr495 __v0) (join st_bld_ans (0 1) 1 __t8CKV493 res) (let __t3zgo492 (band k m)) (cmp gt __t3zgo492 __tconst0v7T491)) (head (emit st_del_ans (0 1) __t3j4h490 res)) set.slog:91 #f)
  class ReadTask196 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x90x0x0x0index176;  slog::Index** pbranchindex177;  slog::Index** st_delindex178;  slog::Index** st_bldindex179;  slog::Index** st_msk_ansindex180;  slog::Index** pbranchindex181;  slog::Index** st_bldindex182;  slog::Index** $sup9688x90x0x0x0index183;  slog::Index** st_delindex184;  slog::Index** st_bldindex185;  slog::Index** st_delindex186;  slog::Index** pbranchindex187;  slog::Index** st_delindex188;  slog::Index** st_bldindex189;  slog::Index** st_del_ansindex190;  slog::Index** st_bld_ansindex191;  slog::Index** st_delindex192;  slog::Index** st_del_ansindex193;  slog::Index** st_bld_ansindex194;  slog::Index** st_deldelta195;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_del_ans");
      std::vector<u16> ord197({0, 1});
      slog::Relation* readrel198 = db->getRelation("st_del_ans");
      head_index[0] = readrel198->getIndex(ord197, false);
      outer_rel = db->getRelation("st_msk");
      std::vector<u16> ord199({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel200 = db->getRelation("$sup9688x90x0x0x0");
      $sup9688x90x0x0x0index176 = readrel200->getIndex(ord199, false);
      std::vector<u16> ord201({2, 0, 1, 3, 4});
      slog::Relation* readrel202 = db->getRelation("pbranch");
      pbranchindex177 = readrel202->getIndex(ord201, false);
      std::vector<u16> ord203({2, 0, 1});
      slog::Relation* readrel204 = db->getRelation("st_del");
      st_delindex178 = readrel204->getIndex(ord203, false);
      std::vector<u16> ord205({2, 1, 4, 0, 3});
      slog::Relation* readrel206 = db->getRelation("st_bld");
      st_bldindex179 = readrel206->getIndex(ord205, false);
      std::vector<u16> ord207({0, 1});
      slog::Relation* readrel208 = db->getRelation("st_msk_ans");
      st_msk_ansindex180 = readrel208->getIndex(ord207, false);
      std::vector<u16> ord209({1, 2, 3, 4, 0});
      slog::Relation* readrel210 = db->getRelation("pbranch");
      pbranchindex181 = readrel210->getIndex(ord209, false);
      std::vector<u16> ord211({1, 2, 3, 4, 0});
      slog::Relation* readrel212 = db->getRelation("st_bld");
      st_bldindex182 = readrel212->getIndex(ord211, false);
      std::vector<u16> ord213({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel214 = db->getRelation("$sup9688x90x0x0x0");
      $sup9688x90x0x0x0index183 = readrel214->getIndex(ord213, false);
      std::vector<u16> ord215({0, 2, 1});
      slog::Relation* readrel216 = db->getRelation("st_del");
      st_delindex184 = readrel216->getIndex(ord215, false);
      std::vector<u16> ord217({1, 2, 3, 4, 0});
      slog::Relation* readrel218 = db->getRelation("st_bld");
      st_bldindex185 = readrel218->getIndex(ord217, false);
      std::vector<u16> ord219({1, 2, 0});
      slog::Relation* readrel220 = db->getRelation("st_del");
      st_delindex186 = readrel220->getIndex(ord219, false);
      std::vector<u16> ord221({1, 2, 3, 4, 0});
      slog::Relation* readrel222 = db->getRelation("pbranch");
      pbranchindex187 = readrel222->getIndex(ord221, false);
      std::vector<u16> ord223({0, 2, 1});
      slog::Relation* readrel224 = db->getRelation("st_del");
      st_delindex188 = readrel224->getIndex(ord223, false);
      std::vector<u16> ord225({1, 2, 3, 4, 0});
      slog::Relation* readrel226 = db->getRelation("st_bld");
      st_bldindex189 = readrel226->getIndex(ord225, false);
      std::vector<u16> ord227({1, 0});
      slog::Relation* readrel228 = db->getRelation("st_del_ans");
      st_del_ansindex190 = readrel228->getIndex(ord227, false);
      std::vector<u16> ord229({0, 1});
      slog::Relation* readrel230 = db->getRelation("st_bld_ans");
      st_bld_ansindex191 = readrel230->getIndex(ord229, false);
      std::vector<u16> ord231({1, 2, 0});
      slog::Relation* readrel232 = db->getRelation("st_del");
      st_delindex192 = readrel232->getIndex(ord231, false);
      std::vector<u16> ord233({1, 2, 0});
      slog::Relation* readrel234 = db->getRelation("st_del");
      st_deldelta195 = readrel234->getIndex(ord233, true);
      std::vector<u16> ord235({0, 1});
      slog::Relation* readrel236 = db->getRelation("st_del_ans");
      st_del_ansindex193 = readrel236->getIndex(ord235, false);
      std::vector<u16> ord237({0, 1});
      slog::Relation* readrel238 = db->getRelation("st_bld_ans");
      st_bld_ansindex194 = readrel238->getIndex(ord237, false);
  
    }
    ReadTask196(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c57 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c58 = _t[0];
        u64 v_c55 = _t[1];
        u64 v_c17 = _t[2];
        if (!slog::exists_probe<6,2>($sup9688x90x0x0x0index176, std::array<u64,6>{v_c55, v_c17, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex177, std::array<u64,5>{v_c17, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_delindex178, std::array<u64,3>{v_c55, 0, 0})) return;
        if (!slog::exists_probe<5,1>(st_bldindex179, std::array<u64,5>{v_c17, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(st_msk_ansindex180, std::array<u64,2>{v_c58, 0}, [&](const std::array<u64,2>& m239) {
          u64 v_c16 = m239[1];
          if (!slog::exists_probe<5,2>(pbranchindex181, std::array<u64,5>{v_c16, v_c17, 0, 0, 0})) return;
          if (!slog::exists_probe<5,2>(st_bldindex182, std::array<u64,5>{v_c16, v_c17, 0, 0, 0})) return;
          slog::join_probe<6,3>($sup9688x90x0x0x0index183, std::array<u64,6>{v_c55, v_c17, v_c16, 0, 0, 0}, [&](const std::array<u64,6>& m240) {
            u64 v_c59 = m240[3]; u64 v_c18 = m240[4]; u64 v_c19 = m240[5];
            if (!slog::exists_probe<3,2>(st_delindex184, std::array<u64,3>{v_c59, v_c55, 0})) return;
            if (!slog::exists_probe<5,3>(st_bldindex185, std::array<u64,5>{v_c16, v_c17, v_c18, 0, 0})) return;
            if (!slog::exists_probe<3,2>(st_delindex186, std::array<u64,3>{v_c19, v_c55, 0})) return;
            slog::join_probe<5,4>(pbranchindex187, std::array<u64,5>{v_c16, v_c17, v_c18, v_c19, 0}, [&](const std::array<u64,5>& m241) {
              u64 v_c60 = m241[4];
              slog::join_probe<3,3>(st_delindex188, std::array<u64,3>{v_c59, v_c55, v_c60}, [&](const std::array<u64,3>& m242) {
                slog::join_probe<5,3>(st_bldindex189, std::array<u64,5>{v_c16, v_c17, v_c18, 0, 0}, [&](const std::array<u64,5>& m243) {
                  u64 v_c6 = m243[3]; u64 v_c61 = m243[4];
                  if (!slog::exists_probe<2,1>(st_del_ansindex190, std::array<u64,2>{v_c6, 0})) return;
                  if (!slog::exists_probe<2,1>(st_bld_ansindex191, std::array<u64,2>{v_c61, 0})) return;
                  slog::join_probe_old<3,2>(st_delindex192, st_deldelta195, std::array<u64,3>{v_c19, v_c55, 0}, [&](const std::array<u64,3>& m244) {
                    u64 v_c62 = m244[2];
                    slog::join_probe<2,2>(st_del_ansindex193, std::array<u64,2>{v_c62, v_c6}, [&](const std::array<u64,2>& m245) {
                      slog::join_probe<2,1>(st_bld_ansindex194, std::array<u64,2>{v_c61, 0}, [&](const std::array<u64,2>& m246) {
                        u64 v_c63 = m246[1];
                        u64 v_c64 = _prim_band(db, v_c55, v_c17);
                        if (v_c64 == slog_error) { slog::emit_pending_error(db, "set.slog:91"); return; }
                        u64 v_c65 = _prim_gt(db, v_c64, v_c57);
                        if (v_c65 == slog_error) { slog::emit_pending_error(db, "set.slog:91"); return; }
                        if (!v_c65) return;
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c59, v_c63}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("set.slog:91", "delta:st_msk", _fires);
  
      if (!_done)
      {
        ReadTask196* _cont = new ReadTask196(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask196(db,b), false);
  // (crule (pre) (scan temp44eI1413 __t1yUC575 __t6hEH570 k) (body (let __t7Tml573 (_0002f k __t6hEH570))) (head (emit-temp temp8c8A1414 __t1yUC575 __t6hEH570 __t7Tml573)) set.slog:33 #f)
  class ReadTask248 : public slog::Task
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
      head_rel[0] = db->getRelation("temp8c8A1414");
      outer_rel = db->getRelation("temp44eI1413");
  
    }
    ReadTask248(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c67 = _t[1];
        u64 v_c55 = _t[2];
        u64 v_c68 = _prim__0002f(db, v_c55, v_c67);
        if (v_c68 == slog_error) { slog::emit_pending_error(db, "set.slog:33"); return; }
        ++_fires;
        slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c66, v_c67, v_c68});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:33", "delta:temp44eI1413", _fires);
  
      if (!_done)
      {
        ReadTask248* _cont = new ReadTask248(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask248(db,b), false);
  // (crule (pre) (scan st_union __t4ltC187 __t2ibk186 t) (body (join pleaf (0 1) 1 __t2ibk186 k)) (head (mkstruct st_ins (1 2 0) __9JL71004 t k)) set.slog:98 #f)
  class ReadTask250 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pleafindex249;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_ins");
      outer_rel = db->getRelation("st_union");
      std::vector<u16> ord251({0, 1});
      slog::Relation* readrel252 = db->getRelation("pleaf");
      pleafindex249 = readrel252->getIndex(ord251, false);
  
    }
    ReadTask250(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c69 = _t[0];
        u64 v_c70 = _t[1];
        u64 v_c56 = _t[2];
        slog::join_probe<2,1>(pleafindex249, std::array<u64,2>{v_c70, 0}, [&](const std::array<u64,2>& m253) {
          u64 v_c55 = m253[1];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c56, v_c55}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:98", "delta:st_union", _fires);
  
      if (!_done)
      {
        ReadTask250* _cont = new ReadTask250(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask250(db,b), false);
  // (crule (pre (let __tconst2in2504 const5feceb66ffc86f38d952786c)) (scan st_msk_ans __t4A7W507 p) (body (exists $sup9688x72x0x0x0 (4 2 3 5 0 1) 1 p) (exists pbranch (1 2 3 4 0) 1 p) (join-old st_msk (0 1 2) 1 (0 1 2) __t4A7W507 k m) (exists pbranch (1 2 3 4 0) 2 p m) (exists st_mem0 (2 0 1) 1 k) (join-old $sup9688x72x0x0x0 (1 3 4 0 2 5) 3 (1 3 4 0 2 5) k m p __t6Rw6503 l r) (exists st_mem0 (2 0 1) 2 k __t6Rw6503) (exists st_mem0 (1 2 0) 2 r k) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t1XtO502) (join-old st_mem0 (0 1 2) 3 (0 1 2) __t6Rw6503 __t1XtO502 k) (join-old st_mem0 (1 2 0) 2 (1 2 0) r k __t9V8P506) (join st_mem0_ans (0 1) 1 __t9V8P506 a) (let __t9tLi505 (band k m)) (cmp gt __t9tLi505 __tconst2in2504)) (head (emit st_mem0_ans (0 1) __t6Rw6503 a)) set.slog:73 #f)
  class ReadTask271 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x72x0x0x0index254;  slog::Index** pbranchindex255;  slog::Index** st_mskindex256;  slog::Index** pbranchindex257;  slog::Index** st_mem0index258;  slog::Index** $sup9688x72x0x0x0index259;  slog::Index** st_mem0index260;  slog::Index** st_mem0index261;  slog::Index** pbranchindex262;  slog::Index** st_mem0index263;  slog::Index** st_mem0index264;  slog::Index** st_mem0_ansindex265;  slog::Index** st_mskdelta266;  slog::Index** $sup9688x72x0x0x0delta267;  slog::Index** pbranchdelta268;  slog::Index** st_mem0delta269;  slog::Index** st_mem0delta270;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_mem0_ans");
      std::vector<u16> ord272({0, 1});
      slog::Relation* readrel273 = db->getRelation("st_mem0_ans");
      head_index[0] = readrel273->getIndex(ord272, false);
      outer_rel = db->getRelation("st_msk_ans");
      std::vector<u16> ord274({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel275 = db->getRelation("$sup9688x72x0x0x0");
      $sup9688x72x0x0x0index254 = readrel275->getIndex(ord274, false);
      std::vector<u16> ord276({1, 2, 3, 4, 0});
      slog::Relation* readrel277 = db->getRelation("pbranch");
      pbranchindex255 = readrel277->getIndex(ord276, false);
      std::vector<u16> ord278({0, 1, 2});
      slog::Relation* readrel279 = db->getRelation("st_msk");
      st_mskindex256 = readrel279->getIndex(ord278, false);
      std::vector<u16> ord280({0, 1, 2});
      slog::Relation* readrel281 = db->getRelation("st_msk");
      st_mskdelta266 = readrel281->getIndex(ord280, true);
      std::vector<u16> ord282({1, 2, 3, 4, 0});
      slog::Relation* readrel283 = db->getRelation("pbranch");
      pbranchindex257 = readrel283->getIndex(ord282, false);
      std::vector<u16> ord284({2, 0, 1});
      slog::Relation* readrel285 = db->getRelation("st_mem0");
      st_mem0index258 = readrel285->getIndex(ord284, false);
      std::vector<u16> ord286({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel287 = db->getRelation("$sup9688x72x0x0x0");
      $sup9688x72x0x0x0index259 = readrel287->getIndex(ord286, false);
      std::vector<u16> ord288({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel289 = db->getRelation("$sup9688x72x0x0x0");
      $sup9688x72x0x0x0delta267 = readrel289->getIndex(ord288, true);
      std::vector<u16> ord290({2, 0, 1});
      slog::Relation* readrel291 = db->getRelation("st_mem0");
      st_mem0index260 = readrel291->getIndex(ord290, false);
      std::vector<u16> ord292({1, 2, 0});
      slog::Relation* readrel293 = db->getRelation("st_mem0");
      st_mem0index261 = readrel293->getIndex(ord292, false);
      std::vector<u16> ord294({1, 2, 3, 4, 0});
      slog::Relation* readrel295 = db->getRelation("pbranch");
      pbranchindex262 = readrel295->getIndex(ord294, false);
      std::vector<u16> ord296({1, 2, 3, 4, 0});
      slog::Relation* readrel297 = db->getRelation("pbranch");
      pbranchdelta268 = readrel297->getIndex(ord296, true);
      std::vector<u16> ord298({0, 1, 2});
      slog::Relation* readrel299 = db->getRelation("st_mem0");
      st_mem0index263 = readrel299->getIndex(ord298, false);
      std::vector<u16> ord300({0, 1, 2});
      slog::Relation* readrel301 = db->getRelation("st_mem0");
      st_mem0delta269 = readrel301->getIndex(ord300, true);
      std::vector<u16> ord302({1, 2, 0});
      slog::Relation* readrel303 = db->getRelation("st_mem0");
      st_mem0index264 = readrel303->getIndex(ord302, false);
      std::vector<u16> ord304({1, 2, 0});
      slog::Relation* readrel305 = db->getRelation("st_mem0");
      st_mem0delta270 = readrel305->getIndex(ord304, true);
      std::vector<u16> ord306({0, 1});
      slog::Relation* readrel307 = db->getRelation("st_mem0_ans");
      st_mem0_ansindex265 = readrel307->getIndex(ord306, false);
  
    }
    ReadTask271(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c71 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c72 = _t[0];
        u64 v_c16 = _t[1];
        if (!slog::exists_probe<6,1>($sup9688x72x0x0x0index254, std::array<u64,6>{v_c16, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex255, std::array<u64,5>{v_c16, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(st_mskindex256, st_mskdelta266, std::array<u64,3>{v_c72, 0, 0}, [&](const std::array<u64,3>& m308) {
          u64 v_c55 = m308[1]; u64 v_c17 = m308[2];
          if (!slog::exists_probe<5,2>(pbranchindex257, std::array<u64,5>{v_c16, v_c17, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(st_mem0index258, std::array<u64,3>{v_c55, 0, 0})) return;
          slog::join_probe_old<6,3>($sup9688x72x0x0x0index259, $sup9688x72x0x0x0delta267, std::array<u64,6>{v_c55, v_c17, v_c16, 0, 0, 0}, [&](const std::array<u64,6>& m309) {
            u64 v_c73 = m309[3]; u64 v_c18 = m309[4]; u64 v_c19 = m309[5];
            if (!slog::exists_probe<3,2>(st_mem0index260, std::array<u64,3>{v_c55, v_c73, 0})) return;
            if (!slog::exists_probe<3,2>(st_mem0index261, std::array<u64,3>{v_c19, v_c55, 0})) return;
            slog::join_probe_old<5,4>(pbranchindex262, pbranchdelta268, std::array<u64,5>{v_c16, v_c17, v_c18, v_c19, 0}, [&](const std::array<u64,5>& m310) {
              u64 v_c74 = m310[4];
              slog::join_probe_old<3,3>(st_mem0index263, st_mem0delta269, std::array<u64,3>{v_c73, v_c74, v_c55}, [&](const std::array<u64,3>& m311) {
                slog::join_probe_old<3,2>(st_mem0index264, st_mem0delta270, std::array<u64,3>{v_c19, v_c55, 0}, [&](const std::array<u64,3>& m312) {
                  u64 v_c75 = m312[2];
                  slog::join_probe<2,1>(st_mem0_ansindex265, std::array<u64,2>{v_c75, 0}, [&](const std::array<u64,2>& m313) {
                    u64 v_c12 = m313[1];
                    u64 v_c76 = _prim_band(db, v_c55, v_c17);
                    if (v_c76 == slog_error) { slog::emit_pending_error(db, "set.slog:73"); return; }
                    u64 v_c77 = _prim_gt(db, v_c76, v_c71);
                    if (v_c77 == slog_error) { slog::emit_pending_error(db, "set.slog:73"); return; }
                    if (!v_c77) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c73, v_c12}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:73", "delta:st_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask271* _cont = new ReadTask271(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask271(db,b), false);
  // (crule (pre) (scan mpz_overflow __erre3d0w1260 __errf8PDP1261 __errf9SEI1262 __errf0xHr1263 __errf6fVQ1264) (body) (head (emit error (0) __erre3d0w1260)) <internal>:1 #f)
  class ReadTask315 : public slog::Task
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
      std::vector<u16> ord316({0});
      slog::Relation* readrel317 = db->getRelation("error");
      head_index[0] = readrel317->getIndex(ord316, false);
      outer_rel = db->getRelation("mpz_overflow");
  
    }
    ReadTask315(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c79 = _t[1];
        u64 v_c80 = _t[2];
        u64 v_c81 = _t[3];
        u64 v_c82 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c78}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_overflow", _fires);
  
      if (!_done)
      {
        ReadTask315* _cont = new ReadTask315(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask315(db,b), false);
  // (crule (pre (let __trid2qai782 constbeaae0387ae49b5204a99e32) (let __trel8qEy783 consta10f76b4ec574de5d7b6908e) (let __tcol0eHk784 const5feceb66ffc86f38d952786c) (let __trel3LXx785 consta10f76b4ec574de5d7b6908e) (let __tcol10XB786 const6b86b273ff34fce19d6b804e)) (scan $sup9688x145x0x0x0 __d0 l m n p q r u v) (body) (head (tycheck q (accept int) __trid2qai782 __trel8qEy783 __tcol0eHk784 (1 2 3 4 0)) (tycheck m (accept int) __trid2qai782 __trel3LXx785 __tcol10XB786 (1 2 3 4 0)) (mkstruct st_msk (1 2 0) __1CxB781 q m)) set.slog:146 #f)
  class ReadTask318 : public slog::Task
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
      head_rel[2] = db->getRelation("st_msk");
      outer_rel = db->getRelation("$sup9688x145x0x0x0");
  
    }
    ReadTask318(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c83 = v_constbeaae0387ae49b5204a99e32;
      u64 v_c84 = v_consta10f76b4ec574de5d7b6908e;
      u64 v_c85 = v_const5feceb66ffc86f38d952786c;
      u64 v_c86 = v_consta10f76b4ec574de5d7b6908e;
      u64 v_c87 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c34 = _t[0];
        u64 v_c18 = _t[1];
        u64 v_c17 = _t[2];
        u64 v_c23 = _t[3];
        u64 v_c16 = _t[4];
        u64 v_c22 = _t[5];
        u64 v_c19 = _t[6];
        u64 v_c24 = _t[7];
        u64 v_c25 = _t[8];
        ++_fires;
        if (!(is_int(v_c22)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c83, v_c84, v_c85, v_c22}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c17)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c83, v_c86, v_c87, v_c17}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c22, v_c17}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("set.slog:146", "delta:$sup9688x145x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask318* _cont = new ReadTask318(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask318(db,b), false);
  // (crule (pre (let __tconst7ZkP346 const5feceb66ffc86f38d952786c)) (scan pbranch __t4ii6344 p m l r) (body (exists $sup9688x106x0x0x1 (7 2 3 5 0 4 6 8 9 1) 4 r l m p) (exists st_union (1 2 0) 1 __t4ii6344) (exists st_msk (2 0 1) 1 m) (exists st_msk_ans (1 0) 1 p) (exists st_union (1 2 0) 1 r) (join $sup9688x106x0x0x0 (4 1 2 6 0 3 5 7 8) 4 p l m r __t7KDg345 n q u v) (cmp lt n m) (exists pbranch (1 2 3 4 0) 4 q n u v) (exists st_union (0 1 2) 2 __t7KDg345 __t4ii6344) (exists st_msk (1 2 0) 2 q m) (join $sup9688x106x0x0x1 (7 2 3 5 0 4 6 8 9 1) 9 r l m p __t7KDg345 n q u v __t0gfm348) (exists st_msk (1 2 0) 3 q m __t0gfm348) (exists st_msk_ans (0 1) 2 __t0gfm348 p) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t0LeB349) (join-old st_union (0 1 2) 3 (0 1 2) __t7KDg345 __t4ii6344 __t0LeB349) (join-old st_msk (1 2 0) 3 (1 2 0) q m __t0gfm348) (join st_msk_ans (0 1) 2 __t0gfm348 p) (join-old st_union (1 2 0) 2 (1 2 0) r __t0LeB349 __t4u97350) (join st_union_ans (0 1) 1 __t4u97350 __v0) (let __t9euC347 (band q m)) (cmp gt __t9euC347 __tconst7ZkP346)) (head (emit-temp temp3Stv1345 __t7KDg345 __v0 l m p) (mkstruct pbranch (1 2 3 4 0) __t0u8a342 p m l __v0)) set.slog:107 #f)
  class ReadTask341 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x106x0x0x1index319;  slog::Index** st_unionindex320;  slog::Index** st_mskindex321;  slog::Index** st_msk_ansindex322;  slog::Index** st_unionindex323;  slog::Index** $sup9688x106x0x0x0index324;  slog::Index** pbranchindex325;  slog::Index** st_unionindex326;  slog::Index** st_mskindex327;  slog::Index** $sup9688x106x0x0x1index328;  slog::Index** st_mskindex329;  slog::Index** st_msk_ansindex330;  slog::Index** pbranchindex331;  slog::Index** st_unionindex332;  slog::Index** st_mskindex333;  slog::Index** st_msk_ansindex334;  slog::Index** st_unionindex335;  slog::Index** st_union_ansindex336;  slog::Index** pbranchdelta337;  slog::Index** st_uniondelta338;  slog::Index** st_mskdelta339;  slog::Index** st_uniondelta340;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3Stv1345");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord342({7, 2, 3, 5, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel343 = db->getRelation("$sup9688x106x0x0x1");
      $sup9688x106x0x0x1index319 = readrel343->getIndex(ord342, false);
      std::vector<u16> ord344({1, 2, 0});
      slog::Relation* readrel345 = db->getRelation("st_union");
      st_unionindex320 = readrel345->getIndex(ord344, false);
      std::vector<u16> ord346({2, 0, 1});
      slog::Relation* readrel347 = db->getRelation("st_msk");
      st_mskindex321 = readrel347->getIndex(ord346, false);
      std::vector<u16> ord348({1, 0});
      slog::Relation* readrel349 = db->getRelation("st_msk_ans");
      st_msk_ansindex322 = readrel349->getIndex(ord348, false);
      std::vector<u16> ord350({1, 2, 0});
      slog::Relation* readrel351 = db->getRelation("st_union");
      st_unionindex323 = readrel351->getIndex(ord350, false);
      std::vector<u16> ord352({4, 1, 2, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel353 = db->getRelation("$sup9688x106x0x0x0");
      $sup9688x106x0x0x0index324 = readrel353->getIndex(ord352, false);
      std::vector<u16> ord354({1, 2, 3, 4, 0});
      slog::Relation* readrel355 = db->getRelation("pbranch");
      pbranchindex325 = readrel355->getIndex(ord354, false);
      std::vector<u16> ord356({0, 1, 2});
      slog::Relation* readrel357 = db->getRelation("st_union");
      st_unionindex326 = readrel357->getIndex(ord356, false);
      std::vector<u16> ord358({1, 2, 0});
      slog::Relation* readrel359 = db->getRelation("st_msk");
      st_mskindex327 = readrel359->getIndex(ord358, false);
      std::vector<u16> ord360({7, 2, 3, 5, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel361 = db->getRelation("$sup9688x106x0x0x1");
      $sup9688x106x0x0x1index328 = readrel361->getIndex(ord360, false);
      std::vector<u16> ord362({1, 2, 0});
      slog::Relation* readrel363 = db->getRelation("st_msk");
      st_mskindex329 = readrel363->getIndex(ord362, false);
      std::vector<u16> ord364({0, 1});
      slog::Relation* readrel365 = db->getRelation("st_msk_ans");
      st_msk_ansindex330 = readrel365->getIndex(ord364, false);
      std::vector<u16> ord366({1, 2, 3, 4, 0});
      slog::Relation* readrel367 = db->getRelation("pbranch");
      pbranchindex331 = readrel367->getIndex(ord366, false);
      std::vector<u16> ord368({1, 2, 3, 4, 0});
      slog::Relation* readrel369 = db->getRelation("pbranch");
      pbranchdelta337 = readrel369->getIndex(ord368, true);
      std::vector<u16> ord370({0, 1, 2});
      slog::Relation* readrel371 = db->getRelation("st_union");
      st_unionindex332 = readrel371->getIndex(ord370, false);
      std::vector<u16> ord372({0, 1, 2});
      slog::Relation* readrel373 = db->getRelation("st_union");
      st_uniondelta338 = readrel373->getIndex(ord372, true);
      std::vector<u16> ord374({1, 2, 0});
      slog::Relation* readrel375 = db->getRelation("st_msk");
      st_mskindex333 = readrel375->getIndex(ord374, false);
      std::vector<u16> ord376({1, 2, 0});
      slog::Relation* readrel377 = db->getRelation("st_msk");
      st_mskdelta339 = readrel377->getIndex(ord376, true);
      std::vector<u16> ord378({0, 1});
      slog::Relation* readrel379 = db->getRelation("st_msk_ans");
      st_msk_ansindex334 = readrel379->getIndex(ord378, false);
      std::vector<u16> ord380({1, 2, 0});
      slog::Relation* readrel381 = db->getRelation("st_union");
      st_unionindex335 = readrel381->getIndex(ord380, false);
      std::vector<u16> ord382({1, 2, 0});
      slog::Relation* readrel383 = db->getRelation("st_union");
      st_uniondelta340 = readrel383->getIndex(ord382, true);
      std::vector<u16> ord384({0, 1});
      slog::Relation* readrel385 = db->getRelation("st_union_ans");
      st_union_ansindex336 = readrel385->getIndex(ord384, false);
  
    }
    ReadTask341(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
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
        u64 v_c89 = _t[0];
        u64 v_c16 = _t[1];
        u64 v_c17 = _t[2];
        u64 v_c18 = _t[3];
        u64 v_c19 = _t[4];
        if (!slog::exists_probe<10,4>($sup9688x106x0x0x1index319, std::array<u64,10>{v_c19, v_c18, v_c17, v_c16, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_unionindex320, std::array<u64,3>{v_c89, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mskindex321, std::array<u64,3>{v_c17, 0, 0})) return;
        if (!slog::exists_probe<2,1>(st_msk_ansindex322, std::array<u64,2>{v_c16, 0})) return;
        if (!slog::exists_probe<3,1>(st_unionindex323, std::array<u64,3>{v_c19, 0, 0})) return;
        slog::join_probe<9,4>($sup9688x106x0x0x0index324, std::array<u64,9>{v_c16, v_c18, v_c17, v_c19, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m386) {
          u64 v_c90 = m386[4]; u64 v_c23 = m386[5]; u64 v_c22 = m386[6]; u64 v_c24 = m386[7]; u64 v_c25 = m386[8];
          u64 v_c91 = _prim_lt(db, v_c23, v_c17);
          if (v_c91 == slog_error) { slog::emit_pending_error(db, "set.slog:107"); return; }
          if (!v_c91) return;
          if (!slog::exists_probe<5,4>(pbranchindex325, std::array<u64,5>{v_c22, v_c23, v_c24, v_c25, 0})) return;
          if (!slog::exists_probe<3,2>(st_unionindex326, std::array<u64,3>{v_c90, v_c89, 0})) return;
          if (!slog::exists_probe<3,2>(st_mskindex327, std::array<u64,3>{v_c22, v_c17, 0})) return;
          slog::join_probe<10,9>($sup9688x106x0x0x1index328, std::array<u64,10>{v_c19, v_c18, v_c17, v_c16, v_c90, v_c23, v_c22, v_c24, v_c25, 0}, [&](const std::array<u64,10>& m388) {
            u64 v_c92 = m388[9];
            if (!slog::exists_probe<3,3>(st_mskindex329, std::array<u64,3>{v_c22, v_c17, v_c92})) return;
            if (!slog::exists_probe<2,2>(st_msk_ansindex330, std::array<u64,2>{v_c92, v_c16})) return;
            slog::join_probe_old<5,4>(pbranchindex331, pbranchdelta337, std::array<u64,5>{v_c22, v_c23, v_c24, v_c25, 0}, [&](const std::array<u64,5>& m389) {
              u64 v_c93 = m389[4];
              slog::join_probe_old<3,3>(st_unionindex332, st_uniondelta338, std::array<u64,3>{v_c90, v_c89, v_c93}, [&](const std::array<u64,3>& m390) {
                slog::join_probe_old<3,3>(st_mskindex333, st_mskdelta339, std::array<u64,3>{v_c22, v_c17, v_c92}, [&](const std::array<u64,3>& m391) {
                  slog::join_probe<2,2>(st_msk_ansindex334, std::array<u64,2>{v_c92, v_c16}, [&](const std::array<u64,2>& m392) {
                    slog::join_probe_old<3,2>(st_unionindex335, st_uniondelta340, std::array<u64,3>{v_c19, v_c93, 0}, [&](const std::array<u64,3>& m393) {
                      u64 v_c94 = m393[2];
                      slog::join_probe<2,1>(st_union_ansindex336, std::array<u64,2>{v_c94, 0}, [&](const std::array<u64,2>& m394) {
                        u64 v_c6 = m394[1];
                        u64 v_c95 = _prim_band(db, v_c22, v_c17);
                        if (v_c95 == slog_error) { slog::emit_pending_error(db, "set.slog:107"); return; }
                        u64 v_c96 = _prim_gt(db, v_c95, v_c88);
                        if (v_c96 == slog_error) { slog::emit_pending_error(db, "set.slog:107"); return; }
                        if (!v_c96) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c90, v_c6, v_c18, v_c17, v_c16});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c16, v_c17, v_c18, v_c6}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:107", "delta:pbranch", _fires);
  
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
  // (crule (pre) (scan st_union __t3tZ8235 __t7ZZP236 __t8STz237) (body (exists $sup9688x120x0x0x0 (0 7 8 1 2 3 4 5 6 9 10) 3 __t3tZ8235 __t7ZZP236 __t8STz237) (join-old st_join (2 4 0 1 3) 2 (2 4 0 1 3) __t7ZZP236 __t8STz237 __t1ZYa238 p q) (exists pbranch (0 1 2 3 4) 2 __t7ZZP236 p) (exists pbranch (0 1 2 3 4) 2 __t8STz237 q) (exists st_msk (1 2 0) 1 p) (exists st_join_ans (0 1) 1 __t1ZYa238) (join $sup9688x120x0x0x0 (4 5 7 8 0 1 2 3 6 9 10) 5 p q __t7ZZP236 __t8STz237 __t3tZ8235 l m n r u v) (cmp lt m n) (join-old pbranch (1 2 3 4 0) 5 (1 2 3 4 0) p m l r __t7ZZP236) (join-old pbranch (1 2 3 4 0) 5 (1 2 3 4 0) q n u v __t8STz237) (join-old st_msk (1 2 0) 2 (1 2 0) p n __t3Qtm239) (join st_msk_ans (0 1) 1 __t3Qtm239 __v0) (neq q __v0) (join st_join_ans (0 1) 1 __t1ZYa238 res)) (head (emit st_union_ans (0 1) __t3tZ8235 res)) set.slog:121 #f)
  class ReadTask412 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x120x0x0x0index396;  slog::Index** st_joinindex397;  slog::Index** pbranchindex398;  slog::Index** pbranchindex399;  slog::Index** st_mskindex400;  slog::Index** st_join_ansindex401;  slog::Index** $sup9688x120x0x0x0index402;  slog::Index** pbranchindex403;  slog::Index** pbranchindex404;  slog::Index** st_mskindex405;  slog::Index** st_msk_ansindex406;  slog::Index** st_join_ansindex407;  slog::Index** st_joindelta408;  slog::Index** pbranchdelta409;  slog::Index** pbranchdelta410;  slog::Index** st_mskdelta411;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_union_ans");
      std::vector<u16> ord413({0, 1});
      slog::Relation* readrel414 = db->getRelation("st_union_ans");
      head_index[0] = readrel414->getIndex(ord413, false);
      outer_rel = db->getRelation("st_union");
      std::vector<u16> ord415({0, 7, 8, 1, 2, 3, 4, 5, 6, 9, 10});
      slog::Relation* readrel416 = db->getRelation("$sup9688x120x0x0x0");
      $sup9688x120x0x0x0index396 = readrel416->getIndex(ord415, false);
      std::vector<u16> ord417({2, 4, 0, 1, 3});
      slog::Relation* readrel418 = db->getRelation("st_join");
      st_joinindex397 = readrel418->getIndex(ord417, false);
      std::vector<u16> ord419({2, 4, 0, 1, 3});
      slog::Relation* readrel420 = db->getRelation("st_join");
      st_joindelta408 = readrel420->getIndex(ord419, true);
      std::vector<u16> ord421({0, 1, 2, 3, 4});
      slog::Relation* readrel422 = db->getRelation("pbranch");
      pbranchindex398 = readrel422->getIndex(ord421, false);
      std::vector<u16> ord423({0, 1, 2, 3, 4});
      slog::Relation* readrel424 = db->getRelation("pbranch");
      pbranchindex399 = readrel424->getIndex(ord423, false);
      std::vector<u16> ord425({1, 2, 0});
      slog::Relation* readrel426 = db->getRelation("st_msk");
      st_mskindex400 = readrel426->getIndex(ord425, false);
      std::vector<u16> ord427({0, 1});
      slog::Relation* readrel428 = db->getRelation("st_join_ans");
      st_join_ansindex401 = readrel428->getIndex(ord427, false);
      std::vector<u16> ord429({4, 5, 7, 8, 0, 1, 2, 3, 6, 9, 10});
      slog::Relation* readrel430 = db->getRelation("$sup9688x120x0x0x0");
      $sup9688x120x0x0x0index402 = readrel430->getIndex(ord429, false);
      std::vector<u16> ord431({1, 2, 3, 4, 0});
      slog::Relation* readrel432 = db->getRelation("pbranch");
      pbranchindex403 = readrel432->getIndex(ord431, false);
      std::vector<u16> ord433({1, 2, 3, 4, 0});
      slog::Relation* readrel434 = db->getRelation("pbranch");
      pbranchdelta409 = readrel434->getIndex(ord433, true);
      std::vector<u16> ord435({1, 2, 3, 4, 0});
      slog::Relation* readrel436 = db->getRelation("pbranch");
      pbranchindex404 = readrel436->getIndex(ord435, false);
      std::vector<u16> ord437({1, 2, 3, 4, 0});
      slog::Relation* readrel438 = db->getRelation("pbranch");
      pbranchdelta410 = readrel438->getIndex(ord437, true);
      std::vector<u16> ord439({1, 2, 0});
      slog::Relation* readrel440 = db->getRelation("st_msk");
      st_mskindex405 = readrel440->getIndex(ord439, false);
      std::vector<u16> ord441({1, 2, 0});
      slog::Relation* readrel442 = db->getRelation("st_msk");
      st_mskdelta411 = readrel442->getIndex(ord441, true);
      std::vector<u16> ord443({0, 1});
      slog::Relation* readrel444 = db->getRelation("st_msk_ans");
      st_msk_ansindex406 = readrel444->getIndex(ord443, false);
      std::vector<u16> ord445({0, 1});
      slog::Relation* readrel446 = db->getRelation("st_join_ans");
      st_join_ansindex407 = readrel446->getIndex(ord445, false);
  
    }
    ReadTask412(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c99 = _t[2];
        if (!slog::exists_probe<11,3>($sup9688x120x0x0x0index396, std::array<u64,11>{v_c97, v_c98, v_c99, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<5,2>(st_joinindex397, st_joindelta408, std::array<u64,5>{v_c98, v_c99, 0, 0, 0}, [&](const std::array<u64,5>& m447) {
          u64 v_c100 = m447[2]; u64 v_c16 = m447[3]; u64 v_c22 = m447[4];
          if (!slog::exists_probe<5,2>(pbranchindex398, std::array<u64,5>{v_c98, v_c16, 0, 0, 0})) return;
          if (!slog::exists_probe<5,2>(pbranchindex399, std::array<u64,5>{v_c99, v_c22, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(st_mskindex400, std::array<u64,3>{v_c16, 0, 0})) return;
          if (!slog::exists_probe<2,1>(st_join_ansindex401, std::array<u64,2>{v_c100, 0})) return;
          slog::join_probe<11,5>($sup9688x120x0x0x0index402, std::array<u64,11>{v_c16, v_c22, v_c98, v_c99, v_c97, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m448) {
            u64 v_c18 = m448[5]; u64 v_c17 = m448[6]; u64 v_c23 = m448[7]; u64 v_c19 = m448[8]; u64 v_c24 = m448[9]; u64 v_c25 = m448[10];
            u64 v_c101 = _prim_lt(db, v_c17, v_c23);
            if (v_c101 == slog_error) { slog::emit_pending_error(db, "set.slog:121"); return; }
            if (!v_c101) return;
            slog::join_probe_old<5,5>(pbranchindex403, pbranchdelta409, std::array<u64,5>{v_c16, v_c17, v_c18, v_c19, v_c98}, [&](const std::array<u64,5>& m450) {
              slog::join_probe_old<5,5>(pbranchindex404, pbranchdelta410, std::array<u64,5>{v_c22, v_c23, v_c24, v_c25, v_c99}, [&](const std::array<u64,5>& m451) {
                slog::join_probe_old<3,2>(st_mskindex405, st_mskdelta411, std::array<u64,3>{v_c16, v_c23, 0}, [&](const std::array<u64,3>& m452) {
                  u64 v_c102 = m452[2];
                  slog::join_probe<2,1>(st_msk_ansindex406, std::array<u64,2>{v_c102, 0}, [&](const std::array<u64,2>& m453) {
                    u64 v_c6 = m453[1];
                    if (v_c22 == v_c6) return;
                    slog::join_probe<2,1>(st_join_ansindex407, std::array<u64,2>{v_c100, 0}, [&](const std::array<u64,2>& m454) {
                      u64 v_c63 = m454[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c97, v_c63}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:121", "delta:st_union", _fires);
  
      if (!_done)
      {
        ReadTask412* _cont = new ReadTask412(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask412(db,b), false);
  // (crule (pre) (scan st_diff __t6ID7275 s __t5fUY274) (body (exists st_del (1 2 0) 1 s) (join pleaf (0 1) 1 __t5fUY274 k) (join-old st_del (1 2 0) 2 (1 2 0) s k __t8BXn276) (join st_del_ans (0 1) 1 __t8BXn276 r)) (head (emit st_diff_ans (0 1) __t6ID7275 r)) set.slog:133 #f)
  class ReadTask460 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_delindex455;  slog::Index** pleafindex456;  slog::Index** st_delindex457;  slog::Index** st_del_ansindex458;  slog::Index** st_deldelta459;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord461({0, 1});
      slog::Relation* readrel462 = db->getRelation("st_diff_ans");
      head_index[0] = readrel462->getIndex(ord461, false);
      outer_rel = db->getRelation("st_diff");
      std::vector<u16> ord463({1, 2, 0});
      slog::Relation* readrel464 = db->getRelation("st_del");
      st_delindex455 = readrel464->getIndex(ord463, false);
      std::vector<u16> ord465({0, 1});
      slog::Relation* readrel466 = db->getRelation("pleaf");
      pleafindex456 = readrel466->getIndex(ord465, false);
      std::vector<u16> ord467({1, 2, 0});
      slog::Relation* readrel468 = db->getRelation("st_del");
      st_delindex457 = readrel468->getIndex(ord467, false);
      std::vector<u16> ord469({1, 2, 0});
      slog::Relation* readrel470 = db->getRelation("st_del");
      st_deldelta459 = readrel470->getIndex(ord469, true);
      std::vector<u16> ord471({0, 1});
      slog::Relation* readrel472 = db->getRelation("st_del_ans");
      st_del_ansindex458 = readrel472->getIndex(ord471, false);
  
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
        u64 v_c103 = _t[0];
        u64 v_c104 = _t[1];
        u64 v_c105 = _t[2];
        if (!slog::exists_probe<3,1>(st_delindex455, std::array<u64,3>{v_c104, 0, 0})) return;
        slog::join_probe<2,1>(pleafindex456, std::array<u64,2>{v_c105, 0}, [&](const std::array<u64,2>& m473) {
          u64 v_c55 = m473[1];
          slog::join_probe_old<3,2>(st_delindex457, st_deldelta459, std::array<u64,3>{v_c104, v_c55, 0}, [&](const std::array<u64,3>& m474) {
            u64 v_c106 = m474[2];
            slog::join_probe<2,1>(st_del_ansindex458, std::array<u64,2>{v_c106, 0}, [&](const std::array<u64,2>& m475) {
              u64 v_c19 = m475[1];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c103, v_c19}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:133", "delta:st_diff", _fires);
  
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
  // (crule (pre (let __tconst7ZkP346 const5feceb66ffc86f38d952786c)) (scan pbranch __t0LeB349 q n u v) (body (exists $sup9688x106x0x0x1 (4 6 8 9 0 1 2 3 5 7) 4 n q u v) (exists st_union (2 0 1) 1 __t0LeB349) (exists st_msk (1 2 0) 1 q) (join $sup9688x106x0x0x0 (3 5 7 8 0 1 2 4 6) 4 n q u v __t7KDg345 l m p r) (cmp lt n m) (exists pbranch (1 2 3 4 0) 4 p m l r) (exists st_union (2 0 1) 2 __t0LeB349 __t7KDg345) (exists st_msk (1 2 0) 2 q m) (exists st_msk_ans (1 0) 1 p) (exists st_union (1 2 0) 2 r __t0LeB349) (join $sup9688x106x0x0x1 (7 2 3 5 0 4 6 8 9 1) 9 r l m p __t7KDg345 n q u v __t0gfm348) (exists st_msk (1 2 0) 3 q m __t0gfm348) (exists st_msk_ans (0 1) 2 __t0gfm348 p) (join pbranch (1 2 3 4 0) 4 p m l r __t4ii6344) (join st_union (0 1 2) 3 __t7KDg345 __t4ii6344 __t0LeB349) (join st_msk (1 2 0) 3 q m __t0gfm348) (join st_msk_ans (0 1) 2 __t0gfm348 p) (join-old st_union (1 2 0) 2 (1 2 0) r __t0LeB349 __t4u97350) (join st_union_ans (0 1) 1 __t4u97350 __v0) (let __t9euC347 (band q m)) (cmp gt __t9euC347 __tconst7ZkP346)) (head (emit-temp temp3Stv1345 __t7KDg345 __v0 l m p) (mkstruct pbranch (1 2 3 4 0) __t0u8a342 p m l __v0)) set.slog:107 #f)
  class ReadTask495 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x106x0x0x1index476;  slog::Index** st_unionindex477;  slog::Index** st_mskindex478;  slog::Index** $sup9688x106x0x0x0index479;  slog::Index** pbranchindex480;  slog::Index** st_unionindex481;  slog::Index** st_mskindex482;  slog::Index** st_msk_ansindex483;  slog::Index** st_unionindex484;  slog::Index** $sup9688x106x0x0x1index485;  slog::Index** st_mskindex486;  slog::Index** st_msk_ansindex487;  slog::Index** pbranchindex488;  slog::Index** st_unionindex489;  slog::Index** st_mskindex490;  slog::Index** st_msk_ansindex491;  slog::Index** st_unionindex492;  slog::Index** st_union_ansindex493;  slog::Index** st_uniondelta494;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3Stv1345");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord496({4, 6, 8, 9, 0, 1, 2, 3, 5, 7});
      slog::Relation* readrel497 = db->getRelation("$sup9688x106x0x0x1");
      $sup9688x106x0x0x1index476 = readrel497->getIndex(ord496, false);
      std::vector<u16> ord498({2, 0, 1});
      slog::Relation* readrel499 = db->getRelation("st_union");
      st_unionindex477 = readrel499->getIndex(ord498, false);
      std::vector<u16> ord500({1, 2, 0});
      slog::Relation* readrel501 = db->getRelation("st_msk");
      st_mskindex478 = readrel501->getIndex(ord500, false);
      std::vector<u16> ord502({3, 5, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel503 = db->getRelation("$sup9688x106x0x0x0");
      $sup9688x106x0x0x0index479 = readrel503->getIndex(ord502, false);
      std::vector<u16> ord504({1, 2, 3, 4, 0});
      slog::Relation* readrel505 = db->getRelation("pbranch");
      pbranchindex480 = readrel505->getIndex(ord504, false);
      std::vector<u16> ord506({2, 0, 1});
      slog::Relation* readrel507 = db->getRelation("st_union");
      st_unionindex481 = readrel507->getIndex(ord506, false);
      std::vector<u16> ord508({1, 2, 0});
      slog::Relation* readrel509 = db->getRelation("st_msk");
      st_mskindex482 = readrel509->getIndex(ord508, false);
      std::vector<u16> ord510({1, 0});
      slog::Relation* readrel511 = db->getRelation("st_msk_ans");
      st_msk_ansindex483 = readrel511->getIndex(ord510, false);
      std::vector<u16> ord512({1, 2, 0});
      slog::Relation* readrel513 = db->getRelation("st_union");
      st_unionindex484 = readrel513->getIndex(ord512, false);
      std::vector<u16> ord514({7, 2, 3, 5, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel515 = db->getRelation("$sup9688x106x0x0x1");
      $sup9688x106x0x0x1index485 = readrel515->getIndex(ord514, false);
      std::vector<u16> ord516({1, 2, 0});
      slog::Relation* readrel517 = db->getRelation("st_msk");
      st_mskindex486 = readrel517->getIndex(ord516, false);
      std::vector<u16> ord518({0, 1});
      slog::Relation* readrel519 = db->getRelation("st_msk_ans");
      st_msk_ansindex487 = readrel519->getIndex(ord518, false);
      std::vector<u16> ord520({1, 2, 3, 4, 0});
      slog::Relation* readrel521 = db->getRelation("pbranch");
      pbranchindex488 = readrel521->getIndex(ord520, false);
      std::vector<u16> ord522({0, 1, 2});
      slog::Relation* readrel523 = db->getRelation("st_union");
      st_unionindex489 = readrel523->getIndex(ord522, false);
      std::vector<u16> ord524({1, 2, 0});
      slog::Relation* readrel525 = db->getRelation("st_msk");
      st_mskindex490 = readrel525->getIndex(ord524, false);
      std::vector<u16> ord526({0, 1});
      slog::Relation* readrel527 = db->getRelation("st_msk_ans");
      st_msk_ansindex491 = readrel527->getIndex(ord526, false);
      std::vector<u16> ord528({1, 2, 0});
      slog::Relation* readrel529 = db->getRelation("st_union");
      st_unionindex492 = readrel529->getIndex(ord528, false);
      std::vector<u16> ord530({1, 2, 0});
      slog::Relation* readrel531 = db->getRelation("st_union");
      st_uniondelta494 = readrel531->getIndex(ord530, true);
      std::vector<u16> ord532({0, 1});
      slog::Relation* readrel533 = db->getRelation("st_union_ans");
      st_union_ansindex493 = readrel533->getIndex(ord532, false);
  
    }
    ReadTask495(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
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
        u64 v_c93 = _t[0];
        u64 v_c22 = _t[1];
        u64 v_c23 = _t[2];
        u64 v_c24 = _t[3];
        u64 v_c25 = _t[4];
        if (!slog::exists_probe<10,4>($sup9688x106x0x0x1index476, std::array<u64,10>{v_c23, v_c22, v_c24, v_c25, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_unionindex477, std::array<u64,3>{v_c93, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mskindex478, std::array<u64,3>{v_c22, 0, 0})) return;
        slog::join_probe<9,4>($sup9688x106x0x0x0index479, std::array<u64,9>{v_c23, v_c22, v_c24, v_c25, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m534) {
          u64 v_c90 = m534[4]; u64 v_c18 = m534[5]; u64 v_c17 = m534[6]; u64 v_c16 = m534[7]; u64 v_c19 = m534[8];
          u64 v_c107 = _prim_lt(db, v_c23, v_c17);
          if (v_c107 == slog_error) { slog::emit_pending_error(db, "set.slog:107"); return; }
          if (!v_c107) return;
          if (!slog::exists_probe<5,4>(pbranchindex480, std::array<u64,5>{v_c16, v_c17, v_c18, v_c19, 0})) return;
          if (!slog::exists_probe<3,2>(st_unionindex481, std::array<u64,3>{v_c93, v_c90, 0})) return;
          if (!slog::exists_probe<3,2>(st_mskindex482, std::array<u64,3>{v_c22, v_c17, 0})) return;
          if (!slog::exists_probe<2,1>(st_msk_ansindex483, std::array<u64,2>{v_c16, 0})) return;
          if (!slog::exists_probe<3,2>(st_unionindex484, std::array<u64,3>{v_c19, v_c93, 0})) return;
          slog::join_probe<10,9>($sup9688x106x0x0x1index485, std::array<u64,10>{v_c19, v_c18, v_c17, v_c16, v_c90, v_c23, v_c22, v_c24, v_c25, 0}, [&](const std::array<u64,10>& m536) {
            u64 v_c92 = m536[9];
            if (!slog::exists_probe<3,3>(st_mskindex486, std::array<u64,3>{v_c22, v_c17, v_c92})) return;
            if (!slog::exists_probe<2,2>(st_msk_ansindex487, std::array<u64,2>{v_c92, v_c16})) return;
            slog::join_probe<5,4>(pbranchindex488, std::array<u64,5>{v_c16, v_c17, v_c18, v_c19, 0}, [&](const std::array<u64,5>& m537) {
              u64 v_c89 = m537[4];
              slog::join_probe<3,3>(st_unionindex489, std::array<u64,3>{v_c90, v_c89, v_c93}, [&](const std::array<u64,3>& m538) {
                slog::join_probe<3,3>(st_mskindex490, std::array<u64,3>{v_c22, v_c17, v_c92}, [&](const std::array<u64,3>& m539) {
                  slog::join_probe<2,2>(st_msk_ansindex491, std::array<u64,2>{v_c92, v_c16}, [&](const std::array<u64,2>& m540) {
                    slog::join_probe_old<3,2>(st_unionindex492, st_uniondelta494, std::array<u64,3>{v_c19, v_c93, 0}, [&](const std::array<u64,3>& m541) {
                      u64 v_c94 = m541[2];
                      slog::join_probe<2,1>(st_union_ansindex493, std::array<u64,2>{v_c94, 0}, [&](const std::array<u64,2>& m542) {
                        u64 v_c6 = m542[1];
                        u64 v_c95 = _prim_band(db, v_c22, v_c17);
                        if (v_c95 == slog_error) { slog::emit_pending_error(db, "set.slog:107"); return; }
                        u64 v_c108 = _prim_gt(db, v_c95, v_c88);
                        if (v_c108 == slog_error) { slog::emit_pending_error(db, "set.slog:107"); return; }
                        if (!v_c108) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c90, v_c6, v_c18, v_c17, v_c16});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c16, v_c17, v_c18, v_c6}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:107", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask495* _cont = new ReadTask495(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask495(db,b), false);
  // (crule (pre) (scan temp3xVH1332 __t0kmv352 __v2 __v3 t0 t1) (body (join pbranch (1 2 3 4 0) 4 __v2 __v3 t0 t1 __t4fDE351)) (head (emit st_join_ans (0 1) __t0kmv352 __t4fDE351)) set.slog:37 #f)
  class ReadTask545 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex544;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_join_ans");
      std::vector<u16> ord546({0, 1});
      slog::Relation* readrel547 = db->getRelation("st_join_ans");
      head_index[0] = readrel547->getIndex(ord546, false);
      outer_rel = db->getRelation("temp3xVH1332");
      std::vector<u16> ord548({1, 2, 3, 4, 0});
      slog::Relation* readrel549 = db->getRelation("pbranch");
      pbranchindex544 = readrel549->getIndex(ord548, false);
  
    }
    ReadTask545(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c38 = _t[2];
        u64 v_c41 = _t[3];
        u64 v_c42 = _t[4];
        slog::join_probe<5,4>(pbranchindex544, std::array<u64,5>{v_c110, v_c38, v_c41, v_c42, 0}, [&](const std::array<u64,5>& m550) {
          u64 v_c111 = m550[4];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c109, v_c111}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:37", "delta:temp3xVH1332", _fires);
  
      if (!_done)
      {
        ReadTask545* _cont = new ReadTask545(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask545(db,b), false);
  // (crule (pre) (scan pbranch __t6Gju1 p m u v) (body (exists st_union (2 0 1) 1 __t6Gju1) (join-old pbranch (1 2 3 4 0) 2 (1 2 3 4 0) p m l r __t66nq2) (join-old st_union (1 2 0) 2 (1 2 0) __t66nq2 __t6Gju1 __t0Mc03)) (head (emit $sup9688x100x0x0x0 (0 1 2 3 4 5 6) __t0Mc03 l m p r u v)) set.slog:101 #f)
  class ReadTask556 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_unionindex551;  slog::Index** pbranchindex552;  slog::Index** st_unionindex553;  slog::Index** pbranchdelta554;  slog::Index** st_uniondelta555;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x100x0x0x0");
      std::vector<u16> ord557({0, 1, 2, 3, 4, 5, 6});
      slog::Relation* readrel558 = db->getRelation("$sup9688x100x0x0x0");
      head_index[0] = readrel558->getIndex(ord557, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord559({2, 0, 1});
      slog::Relation* readrel560 = db->getRelation("st_union");
      st_unionindex551 = readrel560->getIndex(ord559, false);
      std::vector<u16> ord561({1, 2, 3, 4, 0});
      slog::Relation* readrel562 = db->getRelation("pbranch");
      pbranchindex552 = readrel562->getIndex(ord561, false);
      std::vector<u16> ord563({1, 2, 3, 4, 0});
      slog::Relation* readrel564 = db->getRelation("pbranch");
      pbranchdelta554 = readrel564->getIndex(ord563, true);
      std::vector<u16> ord565({1, 2, 0});
      slog::Relation* readrel566 = db->getRelation("st_union");
      st_unionindex553 = readrel566->getIndex(ord565, false);
      std::vector<u16> ord567({1, 2, 0});
      slog::Relation* readrel568 = db->getRelation("st_union");
      st_uniondelta555 = readrel568->getIndex(ord567, true);
  
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
        u64 v_c112 = _t[0];
        u64 v_c16 = _t[1];
        u64 v_c17 = _t[2];
        u64 v_c24 = _t[3];
        u64 v_c25 = _t[4];
        if (!slog::exists_probe<3,1>(st_unionindex551, std::array<u64,3>{v_c112, 0, 0})) return;
        slog::join_probe_old<5,2>(pbranchindex552, pbranchdelta554, std::array<u64,5>{v_c16, v_c17, 0, 0, 0}, [&](const std::array<u64,5>& m569) {
          u64 v_c18 = m569[2]; u64 v_c19 = m569[3]; u64 v_c113 = m569[4];
          slog::join_probe_old<3,2>(st_unionindex553, st_uniondelta555, std::array<u64,3>{v_c113, v_c112, 0}, [&](const std::array<u64,3>& m570) {
            u64 v_c114 = m570[2];
            ++_fires;
            slog::emit<7>(head_rel[0], head_index[0], newbatch[0], std::array<u64,7>{v_c114, v_c18, v_c17, v_c16, v_c19, v_c24, v_c25}, std::array<u16,7>{0, 1, 2, 3, 4, 5, 6});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:101", "delta:pbranch", _fires);
  
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
  // (crule (pre (let __tconst7O7w336 const5feceb66ffc86f38d952786c)) (scan st_bld_ans __t7XLn338 res) (body (join-old st_bld (0 1 2 3 4) 1 (0 1 2 3 4) __t7XLn338 p m l __v0) (exists $sup9688x142x0x0x0 (4 1 2 6 0 3 5 7 8) 3 p l m) (exists st_msk (2 0 1) 1 m) (exists st_msk_ans (1 0) 1 p) (exists st_diff_ans (1 0) 1 __v0) (join-old pbranch (1 2 3 4 0) 3 (1 2 3 4 0) p m l r __t88zt334) (exists st_diff (1 2 0) 1 __t88zt334) (exists st_diff (1 2 0) 1 r) (join-old $sup9688x142x0x0x0 (4 1 2 6 0 3 5 7 8) 4 (4 1 2 6 0 3 5 7 8) p l m r __t8Fy1335 n q u v) (cmp lt n m) (exists st_diff (0 1 2) 2 __t8Fy1335 __t88zt334) (exists st_msk (1 2 0) 2 q m) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t69OA340) (join-old st_diff (0 1 2) 3 (0 1 2) __t8Fy1335 __t88zt334 __t69OA340) (exists st_diff (1 2 0) 2 r __t69OA340) (join-old st_msk (1 2 0) 2 (1 2 0) q m __t19Mr339) (join-old st_msk_ans (0 1) 2 (0 1) __t19Mr339 p) (join-old st_diff (1 2 0) 2 (1 2 0) r __t69OA340 __t95th341) (join-old st_diff_ans (0 1) 2 (0 1) __t95th341 __v0) (let __t4rbw337 (band q m)) (cmp gt __t4rbw337 __tconst7O7w336)) (head (emit st_diff_ans (0 1) __t8Fy1335 res)) set.slog:143 #f)
  class ReadTask598 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_bldindex571;  slog::Index** $sup9688x142x0x0x0index572;  slog::Index** st_mskindex573;  slog::Index** st_msk_ansindex574;  slog::Index** st_diff_ansindex575;  slog::Index** pbranchindex576;  slog::Index** st_diffindex577;  slog::Index** st_diffindex578;  slog::Index** $sup9688x142x0x0x0index579;  slog::Index** st_diffindex580;  slog::Index** st_mskindex581;  slog::Index** pbranchindex582;  slog::Index** st_diffindex583;  slog::Index** st_diffindex584;  slog::Index** st_mskindex585;  slog::Index** st_msk_ansindex586;  slog::Index** st_diffindex587;  slog::Index** st_diff_ansindex588;  slog::Index** st_blddelta589;  slog::Index** pbranchdelta590;  slog::Index** $sup9688x142x0x0x0delta591;  slog::Index** pbranchdelta592;  slog::Index** st_diffdelta593;  slog::Index** st_mskdelta594;  slog::Index** st_msk_ansdelta595;  slog::Index** st_diffdelta596;  slog::Index** st_diff_ansdelta597;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord599({0, 1});
      slog::Relation* readrel600 = db->getRelation("st_diff_ans");
      head_index[0] = readrel600->getIndex(ord599, false);
      outer_rel = db->getRelation("st_bld_ans");
      std::vector<u16> ord601({0, 1, 2, 3, 4});
      slog::Relation* readrel602 = db->getRelation("st_bld");
      st_bldindex571 = readrel602->getIndex(ord601, false);
      std::vector<u16> ord603({0, 1, 2, 3, 4});
      slog::Relation* readrel604 = db->getRelation("st_bld");
      st_blddelta589 = readrel604->getIndex(ord603, true);
      std::vector<u16> ord605({4, 1, 2, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel606 = db->getRelation("$sup9688x142x0x0x0");
      $sup9688x142x0x0x0index572 = readrel606->getIndex(ord605, false);
      std::vector<u16> ord607({2, 0, 1});
      slog::Relation* readrel608 = db->getRelation("st_msk");
      st_mskindex573 = readrel608->getIndex(ord607, false);
      std::vector<u16> ord609({1, 0});
      slog::Relation* readrel610 = db->getRelation("st_msk_ans");
      st_msk_ansindex574 = readrel610->getIndex(ord609, false);
      std::vector<u16> ord611({1, 0});
      slog::Relation* readrel612 = db->getRelation("st_diff_ans");
      st_diff_ansindex575 = readrel612->getIndex(ord611, false);
      std::vector<u16> ord613({1, 2, 3, 4, 0});
      slog::Relation* readrel614 = db->getRelation("pbranch");
      pbranchindex576 = readrel614->getIndex(ord613, false);
      std::vector<u16> ord615({1, 2, 3, 4, 0});
      slog::Relation* readrel616 = db->getRelation("pbranch");
      pbranchdelta590 = readrel616->getIndex(ord615, true);
      std::vector<u16> ord617({1, 2, 0});
      slog::Relation* readrel618 = db->getRelation("st_diff");
      st_diffindex577 = readrel618->getIndex(ord617, false);
      std::vector<u16> ord619({1, 2, 0});
      slog::Relation* readrel620 = db->getRelation("st_diff");
      st_diffindex578 = readrel620->getIndex(ord619, false);
      std::vector<u16> ord621({4, 1, 2, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel622 = db->getRelation("$sup9688x142x0x0x0");
      $sup9688x142x0x0x0index579 = readrel622->getIndex(ord621, false);
      std::vector<u16> ord623({4, 1, 2, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel624 = db->getRelation("$sup9688x142x0x0x0");
      $sup9688x142x0x0x0delta591 = readrel624->getIndex(ord623, true);
      std::vector<u16> ord625({0, 1, 2});
      slog::Relation* readrel626 = db->getRelation("st_diff");
      st_diffindex580 = readrel626->getIndex(ord625, false);
      std::vector<u16> ord627({1, 2, 0});
      slog::Relation* readrel628 = db->getRelation("st_msk");
      st_mskindex581 = readrel628->getIndex(ord627, false);
      std::vector<u16> ord629({1, 2, 3, 4, 0});
      slog::Relation* readrel630 = db->getRelation("pbranch");
      pbranchindex582 = readrel630->getIndex(ord629, false);
      std::vector<u16> ord631({1, 2, 3, 4, 0});
      slog::Relation* readrel632 = db->getRelation("pbranch");
      pbranchdelta592 = readrel632->getIndex(ord631, true);
      std::vector<u16> ord633({0, 1, 2});
      slog::Relation* readrel634 = db->getRelation("st_diff");
      st_diffindex583 = readrel634->getIndex(ord633, false);
      std::vector<u16> ord635({0, 1, 2});
      slog::Relation* readrel636 = db->getRelation("st_diff");
      st_diffdelta593 = readrel636->getIndex(ord635, true);
      std::vector<u16> ord637({1, 2, 0});
      slog::Relation* readrel638 = db->getRelation("st_diff");
      st_diffindex584 = readrel638->getIndex(ord637, false);
      std::vector<u16> ord639({1, 2, 0});
      slog::Relation* readrel640 = db->getRelation("st_msk");
      st_mskindex585 = readrel640->getIndex(ord639, false);
      std::vector<u16> ord641({1, 2, 0});
      slog::Relation* readrel642 = db->getRelation("st_msk");
      st_mskdelta594 = readrel642->getIndex(ord641, true);
      std::vector<u16> ord643({0, 1});
      slog::Relation* readrel644 = db->getRelation("st_msk_ans");
      st_msk_ansindex586 = readrel644->getIndex(ord643, false);
      std::vector<u16> ord645({0, 1});
      slog::Relation* readrel646 = db->getRelation("st_msk_ans");
      st_msk_ansdelta595 = readrel646->getIndex(ord645, true);
      std::vector<u16> ord647({1, 2, 0});
      slog::Relation* readrel648 = db->getRelation("st_diff");
      st_diffindex587 = readrel648->getIndex(ord647, false);
      std::vector<u16> ord649({1, 2, 0});
      slog::Relation* readrel650 = db->getRelation("st_diff");
      st_diffdelta596 = readrel650->getIndex(ord649, true);
      std::vector<u16> ord651({0, 1});
      slog::Relation* readrel652 = db->getRelation("st_diff_ans");
      st_diff_ansindex588 = readrel652->getIndex(ord651, false);
      std::vector<u16> ord653({0, 1});
      slog::Relation* readrel654 = db->getRelation("st_diff_ans");
      st_diff_ansdelta597 = readrel654->getIndex(ord653, true);
  
    }
    ReadTask598(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c115 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c116 = _t[0];
        u64 v_c63 = _t[1];
        slog::join_probe_old<5,1>(st_bldindex571, st_blddelta589, std::array<u64,5>{v_c116, 0, 0, 0, 0}, [&](const std::array<u64,5>& m655) {
          u64 v_c16 = m655[1]; u64 v_c17 = m655[2]; u64 v_c18 = m655[3]; u64 v_c6 = m655[4];
          if (!slog::exists_probe<9,3>($sup9688x142x0x0x0index572, std::array<u64,9>{v_c16, v_c18, v_c17, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(st_mskindex573, std::array<u64,3>{v_c17, 0, 0})) return;
          if (!slog::exists_probe<2,1>(st_msk_ansindex574, std::array<u64,2>{v_c16, 0})) return;
          if (!slog::exists_probe<2,1>(st_diff_ansindex575, std::array<u64,2>{v_c6, 0})) return;
          slog::join_probe_old<5,3>(pbranchindex576, pbranchdelta590, std::array<u64,5>{v_c16, v_c17, v_c18, 0, 0}, [&](const std::array<u64,5>& m656) {
            u64 v_c19 = m656[3]; u64 v_c117 = m656[4];
            if (!slog::exists_probe<3,1>(st_diffindex577, std::array<u64,3>{v_c117, 0, 0})) return;
            if (!slog::exists_probe<3,1>(st_diffindex578, std::array<u64,3>{v_c19, 0, 0})) return;
            slog::join_probe_old<9,4>($sup9688x142x0x0x0index579, $sup9688x142x0x0x0delta591, std::array<u64,9>{v_c16, v_c18, v_c17, v_c19, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m657) {
              u64 v_c118 = m657[4]; u64 v_c23 = m657[5]; u64 v_c22 = m657[6]; u64 v_c24 = m657[7]; u64 v_c25 = m657[8];
              u64 v_c119 = _prim_lt(db, v_c23, v_c17);
              if (v_c119 == slog_error) { slog::emit_pending_error(db, "set.slog:143"); return; }
              if (!v_c119) return;
              if (!slog::exists_probe<3,2>(st_diffindex580, std::array<u64,3>{v_c118, v_c117, 0})) return;
              if (!slog::exists_probe<3,2>(st_mskindex581, std::array<u64,3>{v_c22, v_c17, 0})) return;
              slog::join_probe_old<5,4>(pbranchindex582, pbranchdelta592, std::array<u64,5>{v_c22, v_c23, v_c24, v_c25, 0}, [&](const std::array<u64,5>& m659) {
                u64 v_c120 = m659[4];
                slog::join_probe_old<3,3>(st_diffindex583, st_diffdelta593, std::array<u64,3>{v_c118, v_c117, v_c120}, [&](const std::array<u64,3>& m660) {
                  if (!slog::exists_probe<3,2>(st_diffindex584, std::array<u64,3>{v_c19, v_c120, 0})) return;
                  slog::join_probe_old<3,2>(st_mskindex585, st_mskdelta594, std::array<u64,3>{v_c22, v_c17, 0}, [&](const std::array<u64,3>& m661) {
                    u64 v_c121 = m661[2];
                    slog::join_probe_old<2,2>(st_msk_ansindex586, st_msk_ansdelta595, std::array<u64,2>{v_c121, v_c16}, [&](const std::array<u64,2>& m662) {
                      slog::join_probe_old<3,2>(st_diffindex587, st_diffdelta596, std::array<u64,3>{v_c19, v_c120, 0}, [&](const std::array<u64,3>& m663) {
                        u64 v_c122 = m663[2];
                        slog::join_probe_old<2,2>(st_diff_ansindex588, st_diff_ansdelta597, std::array<u64,2>{v_c122, v_c6}, [&](const std::array<u64,2>& m664) {
                          u64 v_c123 = _prim_band(db, v_c22, v_c17);
                          if (v_c123 == slog_error) { slog::emit_pending_error(db, "set.slog:143"); return; }
                          u64 v_c124 = _prim_gt(db, v_c123, v_c115);
                          if (v_c124 == slog_error) { slog::emit_pending_error(db, "set.slog:143"); return; }
                          if (!v_c124) return;
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c118, v_c63}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("set.slog:143", "delta:st_bld_ans", _fires);
  
      if (!_done)
      {
        ReadTask598* _cont = new ReadTask598(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask598(db,b), false);
  // (crule (pre) (scan pbranch __t9DTf133 p m l r) (body (exists st_join (1 2 3 4 0) 2 p __t9DTf133) (exists st_union (1 2 0) 1 __t9DTf133) (exists st_msk (2 0 1) 1 m) (join $sup9688x110x0x0x0 (1 2 4 6 7 5 0 3 8 9 10) 5 l m p r __t9DTf133 q __t1PdV132 n __t972J134 u v) (cmp lt n m) (join-old pbranch (1 2 3 4 0) 5 (1 2 3 4 0) q n u v __t972J134) (exists st_union (0 1 2) 3 __t1PdV132 __t9DTf133 __t972J134) (exists st_msk (1 2 0) 2 q m) (join-old st_join (1 2 3 4 0) 4 (1 2 3 4 0) p __t9DTf133 q __t972J134 __t744h135) (join st_union (0 1 2) 3 __t1PdV132 __t9DTf133 __t972J134) (exists st_join_ans (0 1) 1 __t744h135) (join-old st_msk (1 2 0) 2 (1 2 0) q m __t4C16136) (join st_msk_ans (0 1) 1 __t4C16136 __v0) (neq p __v0) (join st_join_ans (0 1) 1 __t744h135 res)) (head (emit st_union_ans (0 1) __t1PdV132 res)) set.slog:111 #f)
  class ReadTask682 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_joinindex666;  slog::Index** st_unionindex667;  slog::Index** st_mskindex668;  slog::Index** $sup9688x110x0x0x0index669;  slog::Index** pbranchindex670;  slog::Index** st_unionindex671;  slog::Index** st_mskindex672;  slog::Index** st_joinindex673;  slog::Index** st_unionindex674;  slog::Index** st_join_ansindex675;  slog::Index** st_mskindex676;  slog::Index** st_msk_ansindex677;  slog::Index** st_join_ansindex678;  slog::Index** pbranchdelta679;  slog::Index** st_joindelta680;  slog::Index** st_mskdelta681;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_union_ans");
      std::vector<u16> ord683({0, 1});
      slog::Relation* readrel684 = db->getRelation("st_union_ans");
      head_index[0] = readrel684->getIndex(ord683, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord685({1, 2, 3, 4, 0});
      slog::Relation* readrel686 = db->getRelation("st_join");
      st_joinindex666 = readrel686->getIndex(ord685, false);
      std::vector<u16> ord687({1, 2, 0});
      slog::Relation* readrel688 = db->getRelation("st_union");
      st_unionindex667 = readrel688->getIndex(ord687, false);
      std::vector<u16> ord689({2, 0, 1});
      slog::Relation* readrel690 = db->getRelation("st_msk");
      st_mskindex668 = readrel690->getIndex(ord689, false);
      std::vector<u16> ord691({1, 2, 4, 6, 7, 5, 0, 3, 8, 9, 10});
      slog::Relation* readrel692 = db->getRelation("$sup9688x110x0x0x0");
      $sup9688x110x0x0x0index669 = readrel692->getIndex(ord691, false);
      std::vector<u16> ord693({1, 2, 3, 4, 0});
      slog::Relation* readrel694 = db->getRelation("pbranch");
      pbranchindex670 = readrel694->getIndex(ord693, false);
      std::vector<u16> ord695({1, 2, 3, 4, 0});
      slog::Relation* readrel696 = db->getRelation("pbranch");
      pbranchdelta679 = readrel696->getIndex(ord695, true);
      std::vector<u16> ord697({0, 1, 2});
      slog::Relation* readrel698 = db->getRelation("st_union");
      st_unionindex671 = readrel698->getIndex(ord697, false);
      std::vector<u16> ord699({1, 2, 0});
      slog::Relation* readrel700 = db->getRelation("st_msk");
      st_mskindex672 = readrel700->getIndex(ord699, false);
      std::vector<u16> ord701({1, 2, 3, 4, 0});
      slog::Relation* readrel702 = db->getRelation("st_join");
      st_joinindex673 = readrel702->getIndex(ord701, false);
      std::vector<u16> ord703({1, 2, 3, 4, 0});
      slog::Relation* readrel704 = db->getRelation("st_join");
      st_joindelta680 = readrel704->getIndex(ord703, true);
      std::vector<u16> ord705({0, 1, 2});
      slog::Relation* readrel706 = db->getRelation("st_union");
      st_unionindex674 = readrel706->getIndex(ord705, false);
      std::vector<u16> ord707({0, 1});
      slog::Relation* readrel708 = db->getRelation("st_join_ans");
      st_join_ansindex675 = readrel708->getIndex(ord707, false);
      std::vector<u16> ord709({1, 2, 0});
      slog::Relation* readrel710 = db->getRelation("st_msk");
      st_mskindex676 = readrel710->getIndex(ord709, false);
      std::vector<u16> ord711({1, 2, 0});
      slog::Relation* readrel712 = db->getRelation("st_msk");
      st_mskdelta681 = readrel712->getIndex(ord711, true);
      std::vector<u16> ord713({0, 1});
      slog::Relation* readrel714 = db->getRelation("st_msk_ans");
      st_msk_ansindex677 = readrel714->getIndex(ord713, false);
      std::vector<u16> ord715({0, 1});
      slog::Relation* readrel716 = db->getRelation("st_join_ans");
      st_join_ansindex678 = readrel716->getIndex(ord715, false);
  
    }
    ReadTask682(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c125 = _t[0];
        u64 v_c16 = _t[1];
        u64 v_c17 = _t[2];
        u64 v_c18 = _t[3];
        u64 v_c19 = _t[4];
        if (!slog::exists_probe<5,2>(st_joinindex666, std::array<u64,5>{v_c16, v_c125, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_unionindex667, std::array<u64,3>{v_c125, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mskindex668, std::array<u64,3>{v_c17, 0, 0})) return;
        slog::join_probe<11,5>($sup9688x110x0x0x0index669, std::array<u64,11>{v_c18, v_c17, v_c16, v_c19, v_c125, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m717) {
          u64 v_c22 = m717[5]; u64 v_c126 = m717[6]; u64 v_c23 = m717[7]; u64 v_c127 = m717[8]; u64 v_c24 = m717[9]; u64 v_c25 = m717[10];
          u64 v_c128 = _prim_lt(db, v_c23, v_c17);
          if (v_c128 == slog_error) { slog::emit_pending_error(db, "set.slog:111"); return; }
          if (!v_c128) return;
          slog::join_probe_old<5,5>(pbranchindex670, pbranchdelta679, std::array<u64,5>{v_c22, v_c23, v_c24, v_c25, v_c127}, [&](const std::array<u64,5>& m719) {
            if (!slog::exists_probe<3,3>(st_unionindex671, std::array<u64,3>{v_c126, v_c125, v_c127})) return;
            if (!slog::exists_probe<3,2>(st_mskindex672, std::array<u64,3>{v_c22, v_c17, 0})) return;
            slog::join_probe_old<5,4>(st_joinindex673, st_joindelta680, std::array<u64,5>{v_c16, v_c125, v_c22, v_c127, 0}, [&](const std::array<u64,5>& m720) {
              u64 v_c129 = m720[4];
              slog::join_probe<3,3>(st_unionindex674, std::array<u64,3>{v_c126, v_c125, v_c127}, [&](const std::array<u64,3>& m721) {
                if (!slog::exists_probe<2,1>(st_join_ansindex675, std::array<u64,2>{v_c129, 0})) return;
                slog::join_probe_old<3,2>(st_mskindex676, st_mskdelta681, std::array<u64,3>{v_c22, v_c17, 0}, [&](const std::array<u64,3>& m722) {
                  u64 v_c130 = m722[2];
                  slog::join_probe<2,1>(st_msk_ansindex677, std::array<u64,2>{v_c130, 0}, [&](const std::array<u64,2>& m723) {
                    u64 v_c6 = m723[1];
                    if (v_c16 == v_c6) return;
                    slog::join_probe<2,1>(st_join_ansindex678, std::array<u64,2>{v_c129, 0}, [&](const std::array<u64,2>& m724) {
                      u64 v_c63 = m724[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c126, v_c63}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:111", "delta:pbranch", _fires);
  
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
  // (crule (pre) (scan $sup9688x145x0x0x0 __t3Vft148 l m n p q r u v) (body (cmp lt n m) (exists pbranch (1 2 3 4 0) 4 p m l r) (exists st_msk (1 2 0) 2 q m) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t0w8p146) (exists st_diff (2 0 1) 2 __t0w8p146 __t3Vft148) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t8pVe147) (join-old st_diff (0 1 2) 3 (0 1 2) __t3Vft148 __t8pVe147 __t0w8p146) (join-old st_msk (1 2 0) 2 (1 2 0) q m __t7gQz149) (join st_msk_ans (0 1) 1 __t7gQz149 __v0) (neq p __v0)) (head (emit st_diff_ans (0 1) __t3Vft148 __t8pVe147)) set.slog:146 #f)
  class ReadTask737 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex725;  slog::Index** st_mskindex726;  slog::Index** pbranchindex727;  slog::Index** st_diffindex728;  slog::Index** pbranchindex729;  slog::Index** st_diffindex730;  slog::Index** st_mskindex731;  slog::Index** st_msk_ansindex732;  slog::Index** pbranchdelta733;  slog::Index** pbranchdelta734;  slog::Index** st_diffdelta735;  slog::Index** st_mskdelta736;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord738({0, 1});
      slog::Relation* readrel739 = db->getRelation("st_diff_ans");
      head_index[0] = readrel739->getIndex(ord738, false);
      outer_rel = db->getRelation("$sup9688x145x0x0x0");
      std::vector<u16> ord740({1, 2, 3, 4, 0});
      slog::Relation* readrel741 = db->getRelation("pbranch");
      pbranchindex725 = readrel741->getIndex(ord740, false);
      std::vector<u16> ord742({1, 2, 0});
      slog::Relation* readrel743 = db->getRelation("st_msk");
      st_mskindex726 = readrel743->getIndex(ord742, false);
      std::vector<u16> ord744({1, 2, 3, 4, 0});
      slog::Relation* readrel745 = db->getRelation("pbranch");
      pbranchindex727 = readrel745->getIndex(ord744, false);
      std::vector<u16> ord746({1, 2, 3, 4, 0});
      slog::Relation* readrel747 = db->getRelation("pbranch");
      pbranchdelta733 = readrel747->getIndex(ord746, true);
      std::vector<u16> ord748({2, 0, 1});
      slog::Relation* readrel749 = db->getRelation("st_diff");
      st_diffindex728 = readrel749->getIndex(ord748, false);
      std::vector<u16> ord750({1, 2, 3, 4, 0});
      slog::Relation* readrel751 = db->getRelation("pbranch");
      pbranchindex729 = readrel751->getIndex(ord750, false);
      std::vector<u16> ord752({1, 2, 3, 4, 0});
      slog::Relation* readrel753 = db->getRelation("pbranch");
      pbranchdelta734 = readrel753->getIndex(ord752, true);
      std::vector<u16> ord754({0, 1, 2});
      slog::Relation* readrel755 = db->getRelation("st_diff");
      st_diffindex730 = readrel755->getIndex(ord754, false);
      std::vector<u16> ord756({0, 1, 2});
      slog::Relation* readrel757 = db->getRelation("st_diff");
      st_diffdelta735 = readrel757->getIndex(ord756, true);
      std::vector<u16> ord758({1, 2, 0});
      slog::Relation* readrel759 = db->getRelation("st_msk");
      st_mskindex731 = readrel759->getIndex(ord758, false);
      std::vector<u16> ord760({1, 2, 0});
      slog::Relation* readrel761 = db->getRelation("st_msk");
      st_mskdelta736 = readrel761->getIndex(ord760, true);
      std::vector<u16> ord762({0, 1});
      slog::Relation* readrel763 = db->getRelation("st_msk_ans");
      st_msk_ansindex732 = readrel763->getIndex(ord762, false);
  
    }
    ReadTask737(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c131 = _t[0];
        u64 v_c18 = _t[1];
        u64 v_c17 = _t[2];
        u64 v_c23 = _t[3];
        u64 v_c16 = _t[4];
        u64 v_c22 = _t[5];
        u64 v_c19 = _t[6];
        u64 v_c24 = _t[7];
        u64 v_c25 = _t[8];
        u64 v_c132 = _prim_lt(db, v_c23, v_c17);
        if (v_c132 == slog_error) { slog::emit_pending_error(db, "set.slog:146"); return; }
        if (!v_c132) return;
        if (!slog::exists_probe<5,4>(pbranchindex725, std::array<u64,5>{v_c16, v_c17, v_c18, v_c19, 0})) return;
        if (!slog::exists_probe<3,2>(st_mskindex726, std::array<u64,3>{v_c22, v_c17, 0})) return;
        slog::join_probe_old<5,4>(pbranchindex727, pbranchdelta733, std::array<u64,5>{v_c22, v_c23, v_c24, v_c25, 0}, [&](const std::array<u64,5>& m765) {
          u64 v_c133 = m765[4];
          if (!slog::exists_probe<3,2>(st_diffindex728, std::array<u64,3>{v_c133, v_c131, 0})) return;
          slog::join_probe_old<5,4>(pbranchindex729, pbranchdelta734, std::array<u64,5>{v_c16, v_c17, v_c18, v_c19, 0}, [&](const std::array<u64,5>& m766) {
            u64 v_c134 = m766[4];
            slog::join_probe_old<3,3>(st_diffindex730, st_diffdelta735, std::array<u64,3>{v_c131, v_c134, v_c133}, [&](const std::array<u64,3>& m767) {
              slog::join_probe_old<3,2>(st_mskindex731, st_mskdelta736, std::array<u64,3>{v_c22, v_c17, 0}, [&](const std::array<u64,3>& m768) {
                u64 v_c135 = m768[2];
                slog::join_probe<2,1>(st_msk_ansindex732, std::array<u64,2>{v_c135, 0}, [&](const std::array<u64,2>& m769) {
                  u64 v_c6 = m769[1];
                  if (v_c16 == v_c6) return;
                  ++_fires;
                  slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c131, v_c134}, std::array<u16,2>{0, 1});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:146", "delta:$sup9688x145x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask737* _cont = new ReadTask737(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask737(db,b), false);
  // (crule (pre (let __tconst8Ksp764 conste3776bfed7f405de8017ecfa) (let __tconst6tkr379 const6b86b273ff34fce19d6b804e) (let __tconst7Eph382 const2c624232cdd221771294dfbb) (let __tconst4emd384 constd4735e3a265e16eee03f5971) (let __tconst2ksI386 constef2d127de37b942baad06145)) (scan st_ins_ans __t0FtX383 __v1) (body (exists st_ins (1 2 0) 2 __v1 __tconst4emd384) (exists _enum (1 0) 1 __tconst8Ksp764) (exists st_ins (2 0 1) 1 __tconst6tkr379) (exists st_ins (2 0 1) 1 __tconst2ksI386) (join-old st_ins (0 2 1) 2 (0 2 1) __t0FtX383 __tconst7Eph382 __v0) (exists st_ins_ans (1 0) 1 __v0) (join-old st_ins (1 2 0) 2 (1 2 0) __v1 __tconst4emd384 __t88YX385) (exists st_ins_ans (0 1) 1 __t88YX385) (join _enum (1 0) 1 __tconst8Ksp764 __t6fdj380) (join-old st_ins (1 2 0) 2 (1 2 0) __t6fdj380 __tconst6tkr379 __t2Q6o381) (join st_ins_ans (0 1) 2 __t2Q6o381 __v0) (join-old st_ins_ans (0 1) 1 (0 1) __t88YX385 __v2) (join-old st_ins (1 2 0) 2 (1 2 0) __v2 __tconst2ksI386 __t7LWC387) (join-old st_ins_ans (0 1) 1 (0 1) __t7LWC387 r)) (head (emit canon (0) r)) st_basic.slog:15 #f)
  class ReadTask790 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_insindex770;  slog::Index** _enumindex771;  slog::Index** st_insindex772;  slog::Index** st_insindex773;  slog::Index** st_insindex774;  slog::Index** st_ins_ansindex775;  slog::Index** st_insindex776;  slog::Index** st_ins_ansindex777;  slog::Index** _enumindex778;  slog::Index** st_insindex779;  slog::Index** st_ins_ansindex780;  slog::Index** st_ins_ansindex781;  slog::Index** st_insindex782;  slog::Index** st_ins_ansindex783;  slog::Index** st_insdelta784;  slog::Index** st_insdelta785;  slog::Index** st_insdelta786;  slog::Index** st_ins_ansdelta787;  slog::Index** st_insdelta788;  slog::Index** st_ins_ansdelta789;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("canon");
      std::vector<u16> ord791({0});
      slog::Relation* readrel792 = db->getRelation("canon");
      head_index[0] = readrel792->getIndex(ord791, false);
      outer_rel = db->getRelation("st_ins_ans");
      std::vector<u16> ord793({1, 2, 0});
      slog::Relation* readrel794 = db->getRelation("st_ins");
      st_insindex770 = readrel794->getIndex(ord793, false);
      std::vector<u16> ord795({1, 0});
      slog::Relation* readrel796 = db->getRelation("_enum");
      _enumindex771 = readrel796->getIndex(ord795, false);
      std::vector<u16> ord797({2, 0, 1});
      slog::Relation* readrel798 = db->getRelation("st_ins");
      st_insindex772 = readrel798->getIndex(ord797, false);
      std::vector<u16> ord799({2, 0, 1});
      slog::Relation* readrel800 = db->getRelation("st_ins");
      st_insindex773 = readrel800->getIndex(ord799, false);
      std::vector<u16> ord801({0, 2, 1});
      slog::Relation* readrel802 = db->getRelation("st_ins");
      st_insindex774 = readrel802->getIndex(ord801, false);
      std::vector<u16> ord803({0, 2, 1});
      slog::Relation* readrel804 = db->getRelation("st_ins");
      st_insdelta784 = readrel804->getIndex(ord803, true);
      std::vector<u16> ord805({1, 0});
      slog::Relation* readrel806 = db->getRelation("st_ins_ans");
      st_ins_ansindex775 = readrel806->getIndex(ord805, false);
      std::vector<u16> ord807({1, 2, 0});
      slog::Relation* readrel808 = db->getRelation("st_ins");
      st_insindex776 = readrel808->getIndex(ord807, false);
      std::vector<u16> ord809({1, 2, 0});
      slog::Relation* readrel810 = db->getRelation("st_ins");
      st_insdelta785 = readrel810->getIndex(ord809, true);
      std::vector<u16> ord811({0, 1});
      slog::Relation* readrel812 = db->getRelation("st_ins_ans");
      st_ins_ansindex777 = readrel812->getIndex(ord811, false);
      std::vector<u16> ord813({1, 0});
      slog::Relation* readrel814 = db->getRelation("_enum");
      _enumindex778 = readrel814->getIndex(ord813, false);
      std::vector<u16> ord815({1, 2, 0});
      slog::Relation* readrel816 = db->getRelation("st_ins");
      st_insindex779 = readrel816->getIndex(ord815, false);
      std::vector<u16> ord817({1, 2, 0});
      slog::Relation* readrel818 = db->getRelation("st_ins");
      st_insdelta786 = readrel818->getIndex(ord817, true);
      std::vector<u16> ord819({0, 1});
      slog::Relation* readrel820 = db->getRelation("st_ins_ans");
      st_ins_ansindex780 = readrel820->getIndex(ord819, false);
      std::vector<u16> ord821({0, 1});
      slog::Relation* readrel822 = db->getRelation("st_ins_ans");
      st_ins_ansindex781 = readrel822->getIndex(ord821, false);
      std::vector<u16> ord823({0, 1});
      slog::Relation* readrel824 = db->getRelation("st_ins_ans");
      st_ins_ansdelta787 = readrel824->getIndex(ord823, true);
      std::vector<u16> ord825({1, 2, 0});
      slog::Relation* readrel826 = db->getRelation("st_ins");
      st_insindex782 = readrel826->getIndex(ord825, false);
      std::vector<u16> ord827({1, 2, 0});
      slog::Relation* readrel828 = db->getRelation("st_ins");
      st_insdelta788 = readrel828->getIndex(ord827, true);
      std::vector<u16> ord829({0, 1});
      slog::Relation* readrel830 = db->getRelation("st_ins_ans");
      st_ins_ansindex783 = readrel830->getIndex(ord829, false);
      std::vector<u16> ord831({0, 1});
      slog::Relation* readrel832 = db->getRelation("st_ins_ans");
      st_ins_ansdelta789 = readrel832->getIndex(ord831, true);
  
    }
    ReadTask790(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c136 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c137 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c138 = v_const2c624232cdd221771294dfbb;
      u64 v_c139 = v_constd4735e3a265e16eee03f5971;
      u64 v_c140 = v_constef2d127de37b942baad06145;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c141 = _t[0];
        u64 v_c10 = _t[1];
        if (!slog::exists_probe<3,2>(st_insindex770, std::array<u64,3>{v_c10, v_c139, 0})) return;
        if (!slog::exists_probe<2,1>(_enumindex771, std::array<u64,2>{v_c136, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex772, std::array<u64,3>{v_c137, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex773, std::array<u64,3>{v_c140, 0, 0})) return;
        slog::join_probe_old<3,2>(st_insindex774, st_insdelta784, std::array<u64,3>{v_c141, v_c138, 0}, [&](const std::array<u64,3>& m833) {
          u64 v_c6 = m833[2];
          if (!slog::exists_probe<2,1>(st_ins_ansindex775, std::array<u64,2>{v_c6, 0})) return;
          slog::join_probe_old<3,2>(st_insindex776, st_insdelta785, std::array<u64,3>{v_c10, v_c139, 0}, [&](const std::array<u64,3>& m834) {
            u64 v_c142 = m834[2];
            if (!slog::exists_probe<2,1>(st_ins_ansindex777, std::array<u64,2>{v_c142, 0})) return;
            slog::join_probe<2,1>(_enumindex778, std::array<u64,2>{v_c136, 0}, [&](const std::array<u64,2>& m835) {
              u64 v_c143 = m835[1];
              slog::join_probe_old<3,2>(st_insindex779, st_insdelta786, std::array<u64,3>{v_c143, v_c137, 0}, [&](const std::array<u64,3>& m836) {
                u64 v_c144 = m836[2];
                slog::join_probe<2,2>(st_ins_ansindex780, std::array<u64,2>{v_c144, v_c6}, [&](const std::array<u64,2>& m837) {
                  slog::join_probe_old<2,1>(st_ins_ansindex781, st_ins_ansdelta787, std::array<u64,2>{v_c142, 0}, [&](const std::array<u64,2>& m838) {
                    u64 v_c110 = m838[1];
                    slog::join_probe_old<3,2>(st_insindex782, st_insdelta788, std::array<u64,3>{v_c110, v_c140, 0}, [&](const std::array<u64,3>& m839) {
                      u64 v_c145 = m839[2];
                      slog::join_probe_old<2,1>(st_ins_ansindex783, st_ins_ansdelta789, std::array<u64,2>{v_c145, 0}, [&](const std::array<u64,2>& m840) {
                        u64 v_c19 = m840[1];
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
  
      if (_fires) db->bumpFires("st_basic.slog:15", "delta:st_ins_ans", _fires);
  
      if (!_done)
      {
        ReadTask790* _cont = new ReadTask790(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask790(db,b), false);
  // (crule (pre (let __tconst4ng4400 const5feceb66ffc86f38d952786c)) (scan st_msk __t7rLj403 k m) (body (exists $sup9688x69x0x0x0 (1 3 0 2 4 5) 2 k m) (exists pbranch (2 0 1 3 4) 1 m) (exists st_mem0 (2 0 1) 1 k) (join st_msk_ans (0 1) 1 __t7rLj403 __v0) (join $sup9688x69x0x0x0 (1 3 0 2 4 5) 2 k m __t26uy402 l p r) (neq p __v0) (exists st_mem0 (2 0 1) 2 k __t26uy402) (join pbranch (1 2 3 4 0) 4 p m l r __t4Y7m401) (join st_mem0 (0 1 2) 3 __t26uy402 __t4Y7m401 k)) (head (emit st_mem0_ans (0 1) __t26uy402 __tconst4ng4400)) set.slog:70 #f)
  class ReadTask849 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x69x0x0x0index841;  slog::Index** pbranchindex842;  slog::Index** st_mem0index843;  slog::Index** st_msk_ansindex844;  slog::Index** $sup9688x69x0x0x0index845;  slog::Index** st_mem0index846;  slog::Index** pbranchindex847;  slog::Index** st_mem0index848;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_mem0_ans");
      std::vector<u16> ord850({0, 1});
      slog::Relation* readrel851 = db->getRelation("st_mem0_ans");
      head_index[0] = readrel851->getIndex(ord850, false);
      outer_rel = db->getRelation("st_msk");
      std::vector<u16> ord852({1, 3, 0, 2, 4, 5});
      slog::Relation* readrel853 = db->getRelation("$sup9688x69x0x0x0");
      $sup9688x69x0x0x0index841 = readrel853->getIndex(ord852, false);
      std::vector<u16> ord854({2, 0, 1, 3, 4});
      slog::Relation* readrel855 = db->getRelation("pbranch");
      pbranchindex842 = readrel855->getIndex(ord854, false);
      std::vector<u16> ord856({2, 0, 1});
      slog::Relation* readrel857 = db->getRelation("st_mem0");
      st_mem0index843 = readrel857->getIndex(ord856, false);
      std::vector<u16> ord858({0, 1});
      slog::Relation* readrel859 = db->getRelation("st_msk_ans");
      st_msk_ansindex844 = readrel859->getIndex(ord858, false);
      std::vector<u16> ord860({1, 3, 0, 2, 4, 5});
      slog::Relation* readrel861 = db->getRelation("$sup9688x69x0x0x0");
      $sup9688x69x0x0x0index845 = readrel861->getIndex(ord860, false);
      std::vector<u16> ord862({2, 0, 1});
      slog::Relation* readrel863 = db->getRelation("st_mem0");
      st_mem0index846 = readrel863->getIndex(ord862, false);
      std::vector<u16> ord864({1, 2, 3, 4, 0});
      slog::Relation* readrel865 = db->getRelation("pbranch");
      pbranchindex847 = readrel865->getIndex(ord864, false);
      std::vector<u16> ord866({0, 1, 2});
      slog::Relation* readrel867 = db->getRelation("st_mem0");
      st_mem0index848 = readrel867->getIndex(ord866, false);
  
    }
    ReadTask849(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c146 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c147 = _t[0];
        u64 v_c55 = _t[1];
        u64 v_c17 = _t[2];
        if (!slog::exists_probe<6,2>($sup9688x69x0x0x0index841, std::array<u64,6>{v_c55, v_c17, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex842, std::array<u64,5>{v_c17, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mem0index843, std::array<u64,3>{v_c55, 0, 0})) return;
        slog::join_probe<2,1>(st_msk_ansindex844, std::array<u64,2>{v_c147, 0}, [&](const std::array<u64,2>& m868) {
          u64 v_c6 = m868[1];
          slog::join_probe<6,2>($sup9688x69x0x0x0index845, std::array<u64,6>{v_c55, v_c17, 0, 0, 0, 0}, [&](const std::array<u64,6>& m869) {
            u64 v_c148 = m869[2]; u64 v_c18 = m869[3]; u64 v_c16 = m869[4]; u64 v_c19 = m869[5];
            if (v_c16 == v_c6) return;
            if (!slog::exists_probe<3,2>(st_mem0index846, std::array<u64,3>{v_c55, v_c148, 0})) return;
            slog::join_probe<5,4>(pbranchindex847, std::array<u64,5>{v_c16, v_c17, v_c18, v_c19, 0}, [&](const std::array<u64,5>& m870) {
              u64 v_c149 = m870[4];
              slog::join_probe<3,3>(st_mem0index848, std::array<u64,3>{v_c148, v_c149, v_c55}, [&](const std::array<u64,3>& m871) {
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c148, v_c146}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:70", "delta:st_msk", _fires);
  
      if (!_done)
      {
        ReadTask849* _cont = new ReadTask849(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask849(db,b), false);
  // (crule (pre (let __tconst1v9F125 const5feceb66ffc86f38d952786c)) (scan st_union __t4LMh129 __t32HA128 v) (body (exists st_union (1 2 0) 1 __t32HA128) (exists pbranch (4 0 1 2 3) 1 v) (exists $sup9688x117x0x0x0 (8 0 1 2 3 4 5 6 7) 1 v) (exists $sup9688x117x0x0x1 (9 4 6 8 0 2 3 5 7 1) 1 v) (join st_union_ans (0 1) 1 __t4LMh129 __v0) (join st_union (1 2 0) 1 __t32HA128 __t43ng122 __t0ttd124) (exists $sup9688x117x0x0x0 (0 8 1 2 3 4 5 6 7) 2 __t0ttd124 v) (exists $sup9688x117x0x0x1 (0 9 1 2 3 4 5 6 7 8) 2 __t0ttd124 v) (join pbranch (4 0 1 2 3) 2 v __t43ng122 q n u) (exists $sup9688x117x0x0x1 (9 4 6 8 0 2 3 5 7 1) 5 v n q u __t0ttd124) (exists st_msk (2 0 1) 1 n) (exists st_msk_ans (1 0) 1 q) (join $sup9688x117x0x0x0 (5 3 7 8 0 1 2 4 6) 5 q n u v __t0ttd124 l m p r) (cmp lt m n) (exists pbranch (1 2 3 4 0) 5 p m l r __t32HA128) (exists st_msk (1 2 0) 2 p n) (join $sup9688x117x0x0x1 (9 4 6 8 0 2 3 5 7 1) 9 v n q u __t0ttd124 l m p r __t3TTE127) (join pbranch (1 2 3 4 0) 5 p m l r __t32HA128) (join st_msk (1 2 0) 3 p n __t3TTE127) (join st_msk_ans (0 1) 2 __t3TTE127 q) (let __t3tQC126 (band p n)) (cmp gt __t3tQC126 __tconst1v9F125)) (head (emit-temp temp4p811353 __t0ttd124 __v0 n q u) (mkstruct pbranch (1 2 3 4 0) __t6NgR121 q n u __v0)) set.slog:118 #f)
  class ReadTask891 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_unionindex872;  slog::Index** pbranchindex873;  slog::Index** $sup9688x117x0x0x0index874;  slog::Index** $sup9688x117x0x0x1index875;  slog::Index** st_union_ansindex876;  slog::Index** st_unionindex877;  slog::Index** $sup9688x117x0x0x0index878;  slog::Index** $sup9688x117x0x0x1index879;  slog::Index** pbranchindex880;  slog::Index** $sup9688x117x0x0x1index881;  slog::Index** st_mskindex882;  slog::Index** st_msk_ansindex883;  slog::Index** $sup9688x117x0x0x0index884;  slog::Index** pbranchindex885;  slog::Index** st_mskindex886;  slog::Index** $sup9688x117x0x0x1index887;  slog::Index** pbranchindex888;  slog::Index** st_mskindex889;  slog::Index** st_msk_ansindex890;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4p811353");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("st_union");
      std::vector<u16> ord892({1, 2, 0});
      slog::Relation* readrel893 = db->getRelation("st_union");
      st_unionindex872 = readrel893->getIndex(ord892, false);
      std::vector<u16> ord894({4, 0, 1, 2, 3});
      slog::Relation* readrel895 = db->getRelation("pbranch");
      pbranchindex873 = readrel895->getIndex(ord894, false);
      std::vector<u16> ord896({8, 0, 1, 2, 3, 4, 5, 6, 7});
      slog::Relation* readrel897 = db->getRelation("$sup9688x117x0x0x0");
      $sup9688x117x0x0x0index874 = readrel897->getIndex(ord896, false);
      std::vector<u16> ord898({9, 4, 6, 8, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel899 = db->getRelation("$sup9688x117x0x0x1");
      $sup9688x117x0x0x1index875 = readrel899->getIndex(ord898, false);
      std::vector<u16> ord900({0, 1});
      slog::Relation* readrel901 = db->getRelation("st_union_ans");
      st_union_ansindex876 = readrel901->getIndex(ord900, false);
      std::vector<u16> ord902({1, 2, 0});
      slog::Relation* readrel903 = db->getRelation("st_union");
      st_unionindex877 = readrel903->getIndex(ord902, false);
      std::vector<u16> ord904({0, 8, 1, 2, 3, 4, 5, 6, 7});
      slog::Relation* readrel905 = db->getRelation("$sup9688x117x0x0x0");
      $sup9688x117x0x0x0index878 = readrel905->getIndex(ord904, false);
      std::vector<u16> ord906({0, 9, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel907 = db->getRelation("$sup9688x117x0x0x1");
      $sup9688x117x0x0x1index879 = readrel907->getIndex(ord906, false);
      std::vector<u16> ord908({4, 0, 1, 2, 3});
      slog::Relation* readrel909 = db->getRelation("pbranch");
      pbranchindex880 = readrel909->getIndex(ord908, false);
      std::vector<u16> ord910({9, 4, 6, 8, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel911 = db->getRelation("$sup9688x117x0x0x1");
      $sup9688x117x0x0x1index881 = readrel911->getIndex(ord910, false);
      std::vector<u16> ord912({2, 0, 1});
      slog::Relation* readrel913 = db->getRelation("st_msk");
      st_mskindex882 = readrel913->getIndex(ord912, false);
      std::vector<u16> ord914({1, 0});
      slog::Relation* readrel915 = db->getRelation("st_msk_ans");
      st_msk_ansindex883 = readrel915->getIndex(ord914, false);
      std::vector<u16> ord916({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel917 = db->getRelation("$sup9688x117x0x0x0");
      $sup9688x117x0x0x0index884 = readrel917->getIndex(ord916, false);
      std::vector<u16> ord918({1, 2, 3, 4, 0});
      slog::Relation* readrel919 = db->getRelation("pbranch");
      pbranchindex885 = readrel919->getIndex(ord918, false);
      std::vector<u16> ord920({1, 2, 0});
      slog::Relation* readrel921 = db->getRelation("st_msk");
      st_mskindex886 = readrel921->getIndex(ord920, false);
      std::vector<u16> ord922({9, 4, 6, 8, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel923 = db->getRelation("$sup9688x117x0x0x1");
      $sup9688x117x0x0x1index887 = readrel923->getIndex(ord922, false);
      std::vector<u16> ord924({1, 2, 3, 4, 0});
      slog::Relation* readrel925 = db->getRelation("pbranch");
      pbranchindex888 = readrel925->getIndex(ord924, false);
      std::vector<u16> ord926({1, 2, 0});
      slog::Relation* readrel927 = db->getRelation("st_msk");
      st_mskindex889 = readrel927->getIndex(ord926, false);
      std::vector<u16> ord928({0, 1});
      slog::Relation* readrel929 = db->getRelation("st_msk_ans");
      st_msk_ansindex890 = readrel929->getIndex(ord928, false);
  
    }
    ReadTask891(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c150 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c151 = _t[0];
        u64 v_c152 = _t[1];
        u64 v_c25 = _t[2];
        if (!slog::exists_probe<3,1>(st_unionindex872, std::array<u64,3>{v_c152, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex873, std::array<u64,5>{v_c25, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<9,1>($sup9688x117x0x0x0index874, std::array<u64,9>{v_c25, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<10,1>($sup9688x117x0x0x1index875, std::array<u64,10>{v_c25, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(st_union_ansindex876, std::array<u64,2>{v_c151, 0}, [&](const std::array<u64,2>& m930) {
          u64 v_c6 = m930[1];
          slog::join_probe<3,1>(st_unionindex877, std::array<u64,3>{v_c152, 0, 0}, [&](const std::array<u64,3>& m931) {
            u64 v_c153 = m931[1]; u64 v_c154 = m931[2];
            if (!slog::exists_probe<9,2>($sup9688x117x0x0x0index878, std::array<u64,9>{v_c154, v_c25, 0, 0, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<10,2>($sup9688x117x0x0x1index879, std::array<u64,10>{v_c154, v_c25, 0, 0, 0, 0, 0, 0, 0, 0})) return;
            slog::join_probe<5,2>(pbranchindex880, std::array<u64,5>{v_c25, v_c153, 0, 0, 0}, [&](const std::array<u64,5>& m932) {
              u64 v_c22 = m932[2]; u64 v_c23 = m932[3]; u64 v_c24 = m932[4];
              if (!slog::exists_probe<10,5>($sup9688x117x0x0x1index881, std::array<u64,10>{v_c25, v_c23, v_c22, v_c24, v_c154, 0, 0, 0, 0, 0})) return;
              if (!slog::exists_probe<3,1>(st_mskindex882, std::array<u64,3>{v_c23, 0, 0})) return;
              if (!slog::exists_probe<2,1>(st_msk_ansindex883, std::array<u64,2>{v_c22, 0})) return;
              slog::join_probe<9,5>($sup9688x117x0x0x0index884, std::array<u64,9>{v_c22, v_c23, v_c24, v_c25, v_c154, 0, 0, 0, 0}, [&](const std::array<u64,9>& m933) {
                u64 v_c18 = m933[5]; u64 v_c17 = m933[6]; u64 v_c16 = m933[7]; u64 v_c19 = m933[8];
                u64 v_c155 = _prim_lt(db, v_c17, v_c23);
                if (v_c155 == slog_error) { slog::emit_pending_error(db, "set.slog:118"); return; }
                if (!v_c155) return;
                if (!slog::exists_probe<5,5>(pbranchindex885, std::array<u64,5>{v_c16, v_c17, v_c18, v_c19, v_c152})) return;
                if (!slog::exists_probe<3,2>(st_mskindex886, std::array<u64,3>{v_c16, v_c23, 0})) return;
                slog::join_probe<10,9>($sup9688x117x0x0x1index887, std::array<u64,10>{v_c25, v_c23, v_c22, v_c24, v_c154, v_c18, v_c17, v_c16, v_c19, 0}, [&](const std::array<u64,10>& m935) {
                  u64 v_c156 = m935[9];
                  slog::join_probe<5,5>(pbranchindex888, std::array<u64,5>{v_c16, v_c17, v_c18, v_c19, v_c152}, [&](const std::array<u64,5>& m936) {
                    slog::join_probe<3,3>(st_mskindex889, std::array<u64,3>{v_c16, v_c23, v_c156}, [&](const std::array<u64,3>& m937) {
                      slog::join_probe<2,2>(st_msk_ansindex890, std::array<u64,2>{v_c156, v_c22}, [&](const std::array<u64,2>& m938) {
                        u64 v_c157 = _prim_band(db, v_c16, v_c23);
                        if (v_c157 == slog_error) { slog::emit_pending_error(db, "set.slog:118"); return; }
                        u64 v_c158 = _prim_gt(db, v_c157, v_c150);
                        if (v_c158 == slog_error) { slog::emit_pending_error(db, "set.slog:118"); return; }
                        if (!v_c158) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c154, v_c6, v_c23, v_c22, v_c24});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c22, v_c23, v_c24, v_c6}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:118", "delta:st_union", _fires);
  
      if (!_done)
      {
        ReadTask891* _cont = new ReadTask891(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask891(db,b), false);
  // (crule (pre) (scan pbranch __t1VuF518 q m u v) (body (exists pbranch (2 0 1 3 4) 1 m) (exists st_union (2 0 1) 1 __t1VuF518) (join-old st_join (3 4 0 1 2) 2 (3 4 0 1 2) q __t1VuF518 __t3WPW519 p __t52IG517) (neq p q) (exists st_union (1 2 0) 2 __t52IG517 __t1VuF518) (exists st_join_ans (0 1) 1 __t3WPW519) (join pbranch (0 1 2 3 4) 3 __t52IG517 p m l r) (join st_union (1 2 0) 2 __t52IG517 __t1VuF518 __t5oQM516) (join st_join_ans (0 1) 1 __t3WPW519 res)) (head (emit st_union_ans (0 1) __t5oQM516 res)) set.slog:125 #f)
  class ReadTask949 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex940;  slog::Index** st_unionindex941;  slog::Index** st_joinindex942;  slog::Index** st_unionindex943;  slog::Index** st_join_ansindex944;  slog::Index** pbranchindex945;  slog::Index** st_unionindex946;  slog::Index** st_join_ansindex947;  slog::Index** st_joindelta948;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_union_ans");
      std::vector<u16> ord950({0, 1});
      slog::Relation* readrel951 = db->getRelation("st_union_ans");
      head_index[0] = readrel951->getIndex(ord950, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord952({2, 0, 1, 3, 4});
      slog::Relation* readrel953 = db->getRelation("pbranch");
      pbranchindex940 = readrel953->getIndex(ord952, false);
      std::vector<u16> ord954({2, 0, 1});
      slog::Relation* readrel955 = db->getRelation("st_union");
      st_unionindex941 = readrel955->getIndex(ord954, false);
      std::vector<u16> ord956({3, 4, 0, 1, 2});
      slog::Relation* readrel957 = db->getRelation("st_join");
      st_joinindex942 = readrel957->getIndex(ord956, false);
      std::vector<u16> ord958({3, 4, 0, 1, 2});
      slog::Relation* readrel959 = db->getRelation("st_join");
      st_joindelta948 = readrel959->getIndex(ord958, true);
      std::vector<u16> ord960({1, 2, 0});
      slog::Relation* readrel961 = db->getRelation("st_union");
      st_unionindex943 = readrel961->getIndex(ord960, false);
      std::vector<u16> ord962({0, 1});
      slog::Relation* readrel963 = db->getRelation("st_join_ans");
      st_join_ansindex944 = readrel963->getIndex(ord962, false);
      std::vector<u16> ord964({0, 1, 2, 3, 4});
      slog::Relation* readrel965 = db->getRelation("pbranch");
      pbranchindex945 = readrel965->getIndex(ord964, false);
      std::vector<u16> ord966({1, 2, 0});
      slog::Relation* readrel967 = db->getRelation("st_union");
      st_unionindex946 = readrel967->getIndex(ord966, false);
      std::vector<u16> ord968({0, 1});
      slog::Relation* readrel969 = db->getRelation("st_join_ans");
      st_join_ansindex947 = readrel969->getIndex(ord968, false);
  
    }
    ReadTask949(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c159 = _t[0];
        u64 v_c22 = _t[1];
        u64 v_c17 = _t[2];
        u64 v_c24 = _t[3];
        u64 v_c25 = _t[4];
        if (!slog::exists_probe<5,1>(pbranchindex940, std::array<u64,5>{v_c17, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_unionindex941, std::array<u64,3>{v_c159, 0, 0})) return;
        slog::join_probe_old<5,2>(st_joinindex942, st_joindelta948, std::array<u64,5>{v_c22, v_c159, 0, 0, 0}, [&](const std::array<u64,5>& m970) {
          u64 v_c160 = m970[2]; u64 v_c16 = m970[3]; u64 v_c161 = m970[4];
          if (v_c16 == v_c22) return;
          if (!slog::exists_probe<3,2>(st_unionindex943, std::array<u64,3>{v_c161, v_c159, 0})) return;
          if (!slog::exists_probe<2,1>(st_join_ansindex944, std::array<u64,2>{v_c160, 0})) return;
          slog::join_probe<5,3>(pbranchindex945, std::array<u64,5>{v_c161, v_c16, v_c17, 0, 0}, [&](const std::array<u64,5>& m971) {
            u64 v_c18 = m971[3]; u64 v_c19 = m971[4];
            slog::join_probe<3,2>(st_unionindex946, std::array<u64,3>{v_c161, v_c159, 0}, [&](const std::array<u64,3>& m972) {
              u64 v_c162 = m972[2];
              slog::join_probe<2,1>(st_join_ansindex947, std::array<u64,2>{v_c160, 0}, [&](const std::array<u64,2>& m973) {
                u64 v_c63 = m973[1];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c162, v_c63}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:125", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask949* _cont = new ReadTask949(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask949(db,b), false);
  // (crule (pre) (scan nan_result __erre4oBC1248 __errf3wc21249 __errf16O11250 __errf6Nlz1251) (body) (head (emit error (0) __erre4oBC1248)) <internal>:1 #f)
  class ReadTask974 : public slog::Task
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
      std::vector<u16> ord975({0});
      slog::Relation* readrel976 = db->getRelation("error");
      head_index[0] = readrel976->getIndex(ord975, false);
      outer_rel = db->getRelation("nan_result");
  
    }
    ReadTask974(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c163 = _t[0];
        u64 v_c164 = _t[1];
        u64 v_c165 = _t[2];
        u64 v_c166 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c163}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:nan_result", _fires);
  
      if (!_done)
      {
        ReadTask974* _cont = new ReadTask974(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask974(db,b), false);
  // (crule (pre) (scan st_ins __t7Z9l430 s k) (body (exists pleaf (1 0) 1 k) (exists st_union (1 2 0) 1 s) (join st_ins_ans (0 1) 1 __t7Z9l430 r) (join pleaf (1 0) 1 k __t65ux428) (join st_union (1 2 0) 2 s __t65ux428 __t8LrU429)) (head (emit st_union_ans (0 1) __t8LrU429 r)) set.slog:99 #f)
  class ReadTask982 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pleafindex977;  slog::Index** st_unionindex978;  slog::Index** st_ins_ansindex979;  slog::Index** pleafindex980;  slog::Index** st_unionindex981;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_union_ans");
      std::vector<u16> ord983({0, 1});
      slog::Relation* readrel984 = db->getRelation("st_union_ans");
      head_index[0] = readrel984->getIndex(ord983, false);
      outer_rel = db->getRelation("st_ins");
      std::vector<u16> ord985({1, 0});
      slog::Relation* readrel986 = db->getRelation("pleaf");
      pleafindex977 = readrel986->getIndex(ord985, false);
      std::vector<u16> ord987({1, 2, 0});
      slog::Relation* readrel988 = db->getRelation("st_union");
      st_unionindex978 = readrel988->getIndex(ord987, false);
      std::vector<u16> ord989({0, 1});
      slog::Relation* readrel990 = db->getRelation("st_ins_ans");
      st_ins_ansindex979 = readrel990->getIndex(ord989, false);
      std::vector<u16> ord991({1, 0});
      slog::Relation* readrel992 = db->getRelation("pleaf");
      pleafindex980 = readrel992->getIndex(ord991, false);
      std::vector<u16> ord993({1, 2, 0});
      slog::Relation* readrel994 = db->getRelation("st_union");
      st_unionindex981 = readrel994->getIndex(ord993, false);
  
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
        u64 v_c167 = _t[0];
        u64 v_c104 = _t[1];
        u64 v_c55 = _t[2];
        if (!slog::exists_probe<2,1>(pleafindex977, std::array<u64,2>{v_c55, 0})) return;
        if (!slog::exists_probe<3,1>(st_unionindex978, std::array<u64,3>{v_c104, 0, 0})) return;
        slog::join_probe<2,1>(st_ins_ansindex979, std::array<u64,2>{v_c167, 0}, [&](const std::array<u64,2>& m995) {
          u64 v_c19 = m995[1];
          slog::join_probe<2,1>(pleafindex980, std::array<u64,2>{v_c55, 0}, [&](const std::array<u64,2>& m996) {
            u64 v_c168 = m996[1];
            slog::join_probe<3,2>(st_unionindex981, std::array<u64,3>{v_c104, v_c168, 0}, [&](const std::array<u64,3>& m997) {
              u64 v_c169 = m997[2];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c169, v_c19}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:99", "delta:st_ins", _fires);
  
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
}

