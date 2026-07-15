
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const2c624232cdd221771294dfbb;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_conste3776bfed7f405de8017ecfa;
extern u64 v_constef2d127de37b942baad06145;


void slog_rules_c6481f25fa5c8b850(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre) (scan temp9CLY1403 __t6JPy526) (body) (head (mkstruct st_hsb (1 0) __8XvC716 __t6JPy526)) set.slog:41 #f)
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
      head_rel[0] = db->getRelation("st_hsb");
      outer_rel = db->getRelation("temp9CLY1403");
  
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
        ++_fires;
        slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c0}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:41", "delta:temp9CLY1403", _fires);
  
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
      s->addTask(phase_read, new ReadTask0(db,b), false);
  // (crule (pre (let __tconst4buc465 const5feceb66ffc86f38d952786c)) (scan st_msk_ans __t0rt9471 __v2) (body (join-old st_msk (0 1 2) 1 (0 1 2) __t0rt9471 p0 __v1) (exists $sup9688x40x0x0x2 (5 7 1 0 2 3 4 6 8 9 10) 2 __v1 p0) (exists $sup9688x40x0x0x1 (3 1 0 2 4 5 6) 1 p0) (exists $sup9688x40x0x0x0 (1 0 2 3 4) 1 p0) (exists st_join (1 2 3 4 0) 1 p0) (join-old st_hsb_ans (1 0) 1 (1 0) __v1 __t2flT468) (exists $sup9688x40x0x0x2 (5 7 1 0 2 3 4 6 8 9 10) 3 __v1 p0 __t2flT468) (exists $sup9688x40x0x0x1 (3 1 0 2 4 5 6) 2 p0 __t2flT468) (exists st_hsb_ans (0 1) 1 __t2flT468) (join st_hsb_ans (0 1) 1 __t2flT468 __v3) (join $sup9688x40x0x0x2 (1 5 6 7 0 2 3 4 8 9 10) 4 __t2flT468 __v1 __v3 p0 __t4PzE464 dup2gd61405 dup5ZAM1406 __v0 p1 t0 t1) (eq __t2flT468 dup5ZAM1406) (eq __t2flT468 dup2gd61405) (join $sup9688x40x0x0x1 (0 3 4 5 6 1 2) 7 __t4PzE464 p0 p1 t0 t1 __t2flT468 __v0) (join $sup9688x40x0x0x0 (1 0 2 3 4) 5 p0 __t4PzE464 p1 t0 t1) (join-old st_join (1 2 3 4 0) 5 (1 2 3 4 0) p0 t0 p1 t1 __t4PzE464) (join-old st_hsb_ans (0 1) 2 (0 1) __t2flT468 __v0) (let __t2awV472 (bxor p0 p1)) (join-old st_hsb (0 1) 2 (0 1) __t2flT468 __t2awV472) (let __t7pIU466 (band p0 __v0)) (cmp gt __t7pIU466 __tconst4buc465)) (head (emit-temp temp5blj1404 __t4PzE464 __v2 __v3 t0 t1) (mkstruct pbranch (1 2 3 4 0) __t1bKH463 __v2 __v3 t1 t0)) set.slog:41 #f)
  class ReadTask22 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_mskindex1;  slog::Index** $sup9688x40x0x0x2index2;  slog::Index** $sup9688x40x0x0x1index3;  slog::Index** $sup9688x40x0x0x0index4;  slog::Index** st_joinindex5;  slog::Index** st_hsb_ansindex6;  slog::Index** $sup9688x40x0x0x2index7;  slog::Index** $sup9688x40x0x0x1index8;  slog::Index** st_hsb_ansindex9;  slog::Index** st_hsb_ansindex10;  slog::Index** $sup9688x40x0x0x2index11;  slog::Index** $sup9688x40x0x0x1index12;  slog::Index** $sup9688x40x0x0x0index13;  slog::Index** st_joinindex14;  slog::Index** st_hsb_ansindex15;  slog::Index** st_hsbindex16;  slog::Index** st_mskdelta17;  slog::Index** st_hsb_ansdelta18;  slog::Index** st_joindelta19;  slog::Index** st_hsb_ansdelta20;  slog::Index** st_hsbdelta21;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5blj1404");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("st_msk_ans");
      std::vector<u16> ord23({0, 1, 2});
      slog::Relation* readrel24 = db->getRelation("st_msk");
      st_mskindex1 = readrel24->getIndex(ord23, false);
      std::vector<u16> ord25({0, 1, 2});
      slog::Relation* readrel26 = db->getRelation("st_msk");
      st_mskdelta17 = readrel26->getIndex(ord25, true);
      std::vector<u16> ord27({5, 7, 1, 0, 2, 3, 4, 6, 8, 9, 10});
      slog::Relation* readrel28 = db->getRelation("$sup9688x40x0x0x2");
      $sup9688x40x0x0x2index2 = readrel28->getIndex(ord27, false);
      std::vector<u16> ord29({3, 1, 0, 2, 4, 5, 6});
      slog::Relation* readrel30 = db->getRelation("$sup9688x40x0x0x1");
      $sup9688x40x0x0x1index3 = readrel30->getIndex(ord29, false);
      std::vector<u16> ord31({1, 0, 2, 3, 4});
      slog::Relation* readrel32 = db->getRelation("$sup9688x40x0x0x0");
      $sup9688x40x0x0x0index4 = readrel32->getIndex(ord31, false);
      std::vector<u16> ord33({1, 2, 3, 4, 0});
      slog::Relation* readrel34 = db->getRelation("st_join");
      st_joinindex5 = readrel34->getIndex(ord33, false);
      std::vector<u16> ord35({1, 0});
      slog::Relation* readrel36 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex6 = readrel36->getIndex(ord35, false);
      std::vector<u16> ord37({1, 0});
      slog::Relation* readrel38 = db->getRelation("st_hsb_ans");
      st_hsb_ansdelta18 = readrel38->getIndex(ord37, true);
      std::vector<u16> ord39({5, 7, 1, 0, 2, 3, 4, 6, 8, 9, 10});
      slog::Relation* readrel40 = db->getRelation("$sup9688x40x0x0x2");
      $sup9688x40x0x0x2index7 = readrel40->getIndex(ord39, false);
      std::vector<u16> ord41({3, 1, 0, 2, 4, 5, 6});
      slog::Relation* readrel42 = db->getRelation("$sup9688x40x0x0x1");
      $sup9688x40x0x0x1index8 = readrel42->getIndex(ord41, false);
      std::vector<u16> ord43({0, 1});
      slog::Relation* readrel44 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex9 = readrel44->getIndex(ord43, false);
      std::vector<u16> ord45({0, 1});
      slog::Relation* readrel46 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex10 = readrel46->getIndex(ord45, false);
      std::vector<u16> ord47({1, 5, 6, 7, 0, 2, 3, 4, 8, 9, 10});
      slog::Relation* readrel48 = db->getRelation("$sup9688x40x0x0x2");
      $sup9688x40x0x0x2index11 = readrel48->getIndex(ord47, false);
      std::vector<u16> ord49({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel50 = db->getRelation("$sup9688x40x0x0x1");
      $sup9688x40x0x0x1index12 = readrel50->getIndex(ord49, false);
      std::vector<u16> ord51({1, 0, 2, 3, 4});
      slog::Relation* readrel52 = db->getRelation("$sup9688x40x0x0x0");
      $sup9688x40x0x0x0index13 = readrel52->getIndex(ord51, false);
      std::vector<u16> ord53({1, 2, 3, 4, 0});
      slog::Relation* readrel54 = db->getRelation("st_join");
      st_joinindex14 = readrel54->getIndex(ord53, false);
      std::vector<u16> ord55({1, 2, 3, 4, 0});
      slog::Relation* readrel56 = db->getRelation("st_join");
      st_joindelta19 = readrel56->getIndex(ord55, true);
      std::vector<u16> ord57({0, 1});
      slog::Relation* readrel58 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex15 = readrel58->getIndex(ord57, false);
      std::vector<u16> ord59({0, 1});
      slog::Relation* readrel60 = db->getRelation("st_hsb_ans");
      st_hsb_ansdelta20 = readrel60->getIndex(ord59, true);
      std::vector<u16> ord61({0, 1});
      slog::Relation* readrel62 = db->getRelation("st_hsb");
      st_hsbindex16 = readrel62->getIndex(ord61, false);
      std::vector<u16> ord63({0, 1});
      slog::Relation* readrel64 = db->getRelation("st_hsb");
      st_hsbdelta21 = readrel64->getIndex(ord63, true);
  
    }
    ReadTask22(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c1 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c3 = _t[1];
        slog::join_probe_old<3,1>(st_mskindex1, st_mskdelta17, std::array<u64,3>{v_c2, 0, 0}, [&](const std::array<u64,3>& m65) {
          u64 v_c4 = m65[1]; u64 v_c5 = m65[2];
          if (!slog::exists_probe<11,2>($sup9688x40x0x0x2index2, std::array<u64,11>{v_c5, v_c4, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<7,1>($sup9688x40x0x0x1index3, std::array<u64,7>{v_c4, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>($sup9688x40x0x0x0index4, std::array<u64,5>{v_c4, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>(st_joinindex5, std::array<u64,5>{v_c4, 0, 0, 0, 0})) return;
          slog::join_probe_old<2,1>(st_hsb_ansindex6, st_hsb_ansdelta18, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m66) {
            u64 v_c6 = m66[1];
            if (!slog::exists_probe<11,3>($sup9688x40x0x0x2index7, std::array<u64,11>{v_c5, v_c4, v_c6, 0, 0, 0, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<7,2>($sup9688x40x0x0x1index8, std::array<u64,7>{v_c4, v_c6, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<2,1>(st_hsb_ansindex9, std::array<u64,2>{v_c6, 0})) return;
            slog::join_probe<2,1>(st_hsb_ansindex10, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m67) {
              u64 v_c7 = m67[1];
              slog::join_probe<11,4>($sup9688x40x0x0x2index11, std::array<u64,11>{v_c6, v_c5, v_c7, v_c4, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m68) {
                u64 v_c8 = m68[4]; u64 v_c9 = m68[5]; u64 v_c10 = m68[6]; u64 v_c11 = m68[7]; u64 v_c12 = m68[8]; u64 v_c13 = m68[9]; u64 v_c14 = m68[10];
                if (v_c6 != v_c10) return;
                if (v_c6 != v_c9) return;
                slog::join_probe<7,7>($sup9688x40x0x0x1index12, std::array<u64,7>{v_c8, v_c4, v_c12, v_c13, v_c14, v_c6, v_c11}, [&](const std::array<u64,7>& m69) {
                  slog::join_probe<5,5>($sup9688x40x0x0x0index13, std::array<u64,5>{v_c4, v_c8, v_c12, v_c13, v_c14}, [&](const std::array<u64,5>& m70) {
                    slog::join_probe_old<5,5>(st_joinindex14, st_joindelta19, std::array<u64,5>{v_c4, v_c13, v_c12, v_c14, v_c8}, [&](const std::array<u64,5>& m71) {
                      slog::join_probe_old<2,2>(st_hsb_ansindex15, st_hsb_ansdelta20, std::array<u64,2>{v_c6, v_c11}, [&](const std::array<u64,2>& m72) {
                        u64 v_c15 = _prim_bxor(db, v_c4, v_c12);
                        if (v_c15 == slog_error) { slog::emit_pending_error(db, "set.slog:41"); return; }
                        slog::join_probe_old<2,2>(st_hsbindex16, st_hsbdelta21, std::array<u64,2>{v_c6, v_c15}, [&](const std::array<u64,2>& m73) {
                          u64 v_c16 = _prim_band(db, v_c4, v_c11);
                          if (v_c16 == slog_error) { slog::emit_pending_error(db, "set.slog:41"); return; }
                          u64 v_c17 = _prim_gt(db, v_c16, v_c1);
                          if (v_c17 == slog_error) { slog::emit_pending_error(db, "set.slog:41"); return; }
                          if (!v_c17) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c8, v_c3, v_c7, v_c13, v_c14});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c3, v_c7, v_c14, v_c13}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:41", "delta:st_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask22* _cont = new ReadTask22(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask22(db,b), false);
  // (crule (pre (let _00024sqc374s650 const6b86b273ff34fce19d6b804e) (let _00024sqc70tB651 const5feceb66ffc86f38d952786c) (let _00024sqc9HvG652 const6b86b273ff34fce19d6b804e) (let _00024sqc2OSe653 const5feceb66ffc86f38d952786c) (let _00024sqo65nP658 const5feceb66ffc86f38d952786c)) (scan st_ins_ans __t8MgF74 __v1) (body (exists $seq_at (1 0 2) 1 _00024sqo65nP658) (join-old st_ins (0 2 1) 1 (0 2 1) __t8MgF74 x __v0) (exists $sup9688x168x0x0x0 (2 3 0 1) 1 x) (exists st_fromlist_ans (1 0) 1 __v0) (join-old $seq_at (1 0 2) 2 (1 0 2) _00024sqo65nP658 x _00024seq0) (letp _00024sql5p7m648 (aslst _00024seq0)) (let _00024sqn1lS2649 (llen _00024sql5p7m648)) (cmp ge _00024sqn1lS2649 _00024sqc374s650) (let _00024sqp836n654 (_0002d _00024sqn1lS2649 _00024sqc2OSe653)) (let xs (lslice _00024sql5p7m648 _00024sqc9HvG652 _00024sqp836n654)) (exists st_fromlist (1 0) 1 _00024seq0) (exists st_fromlist (1 0) 1 xs) (join $sup9688x168x0x0x0 (2 3 0 1) 3 x xs _00024seq0 __t9UzC72) (join st_fromlist (0 1) 2 __t9UzC72 _00024seq0) (join st_fromlist_ans (1 0) 1 __v0 __t6xe073) (join st_fromlist (0 1) 2 __t6xe073 xs) (letp chk5CLX1284 (lref _00024sql5p7m648 _00024sqc70tB651)) (eq x chk5CLX1284)) (head (emit st_fromlist_ans (0 1) __t9UzC72 __v1)) set.slog:169 #f)
  class ReadTask88 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $seq_atindex75;  slog::Index** st_insindex76;  slog::Index** $sup9688x168x0x0x0index77;  slog::Index** st_fromlist_ansindex78;  slog::Index** $seq_atindex79;  slog::Index** st_fromlistindex80;  slog::Index** st_fromlistindex81;  slog::Index** $sup9688x168x0x0x0index82;  slog::Index** st_fromlistindex83;  slog::Index** st_fromlist_ansindex84;  slog::Index** st_fromlistindex85;  slog::Index** st_insdelta86;  slog::Index** $seq_atdelta87;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_fromlist_ans");
      std::vector<u16> ord89({0, 1});
      slog::Relation* readrel90 = db->getRelation("st_fromlist_ans");
      head_index[0] = readrel90->getIndex(ord89, false);
      outer_rel = db->getRelation("st_ins_ans");
      std::vector<u16> ord91({1, 0, 2});
      slog::Relation* readrel92 = db->getRelation("$seq_at");
      $seq_atindex75 = readrel92->getIndex(ord91, false);
      std::vector<u16> ord93({0, 2, 1});
      slog::Relation* readrel94 = db->getRelation("st_ins");
      st_insindex76 = readrel94->getIndex(ord93, false);
      std::vector<u16> ord95({0, 2, 1});
      slog::Relation* readrel96 = db->getRelation("st_ins");
      st_insdelta86 = readrel96->getIndex(ord95, true);
      std::vector<u16> ord97({2, 3, 0, 1});
      slog::Relation* readrel98 = db->getRelation("$sup9688x168x0x0x0");
      $sup9688x168x0x0x0index77 = readrel98->getIndex(ord97, false);
      std::vector<u16> ord99({1, 0});
      slog::Relation* readrel100 = db->getRelation("st_fromlist_ans");
      st_fromlist_ansindex78 = readrel100->getIndex(ord99, false);
      std::vector<u16> ord101({1, 0, 2});
      slog::Relation* readrel102 = db->getRelation("$seq_at");
      $seq_atindex79 = readrel102->getIndex(ord101, false);
      std::vector<u16> ord103({1, 0, 2});
      slog::Relation* readrel104 = db->getRelation("$seq_at");
      $seq_atdelta87 = readrel104->getIndex(ord103, true);
      std::vector<u16> ord105({1, 0});
      slog::Relation* readrel106 = db->getRelation("st_fromlist");
      st_fromlistindex80 = readrel106->getIndex(ord105, false);
      std::vector<u16> ord107({1, 0});
      slog::Relation* readrel108 = db->getRelation("st_fromlist");
      st_fromlistindex81 = readrel108->getIndex(ord107, false);
      std::vector<u16> ord109({2, 3, 0, 1});
      slog::Relation* readrel110 = db->getRelation("$sup9688x168x0x0x0");
      $sup9688x168x0x0x0index82 = readrel110->getIndex(ord109, false);
      std::vector<u16> ord111({0, 1});
      slog::Relation* readrel112 = db->getRelation("st_fromlist");
      st_fromlistindex83 = readrel112->getIndex(ord111, false);
      std::vector<u16> ord113({1, 0});
      slog::Relation* readrel114 = db->getRelation("st_fromlist_ans");
      st_fromlist_ansindex84 = readrel114->getIndex(ord113, false);
      std::vector<u16> ord115({0, 1});
      slog::Relation* readrel116 = db->getRelation("st_fromlist");
      st_fromlistindex85 = readrel116->getIndex(ord115, false);
  
    }
    ReadTask88(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c18 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c19 = v_const5feceb66ffc86f38d952786c;
      u64 v_c20 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c21 = v_const5feceb66ffc86f38d952786c;
      u64 v_c22 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c23 = _t[0];
        u64 v_c5 = _t[1];
        if (!slog::exists_probe<3,1>($seq_atindex75, std::array<u64,3>{v_c22, 0, 0})) return;
        slog::join_probe_old<3,1>(st_insindex76, st_insdelta86, std::array<u64,3>{v_c23, 0, 0}, [&](const std::array<u64,3>& m117) {
          u64 v_c24 = m117[1]; u64 v_c11 = m117[2];
          if (!slog::exists_probe<4,1>($sup9688x168x0x0x0index77, std::array<u64,4>{v_c24, 0, 0, 0})) return;
          if (!slog::exists_probe<2,1>(st_fromlist_ansindex78, std::array<u64,2>{v_c11, 0})) return;
          slog::join_probe_old<3,2>($seq_atindex79, $seq_atdelta87, std::array<u64,3>{v_c22, v_c24, 0}, [&](const std::array<u64,3>& m118) {
            u64 v_c25 = m118[2];
            bool ok119 = true;
            u64 v_c26 = _prim_aslst(db, v_c25, &ok119);
            if (!ok119) return;
            u64 v_c27 = _prim_llen(db, v_c26);
            if (v_c27 == slog_error) { slog::emit_pending_error(db, "set.slog:169"); return; }
            u64 v_c28 = _prim_ge(db, v_c27, v_c18);
            if (v_c28 == slog_error) { slog::emit_pending_error(db, "set.slog:169"); return; }
            if (!v_c28) return;
            u64 v_c29 = _prim__0002d(db, v_c27, v_c21);
            if (v_c29 == slog_error) { slog::emit_pending_error(db, "set.slog:169"); return; }
            u64 v_c30 = _prim_lslice(db, v_c26, v_c20, v_c29);
            if (v_c30 == slog_error) { slog::emit_pending_error(db, "set.slog:169"); return; }
            if (!slog::exists_probe<2,1>(st_fromlistindex80, std::array<u64,2>{v_c25, 0})) return;
            if (!slog::exists_probe<2,1>(st_fromlistindex81, std::array<u64,2>{v_c30, 0})) return;
            slog::join_probe<4,3>($sup9688x168x0x0x0index82, std::array<u64,4>{v_c24, v_c30, v_c25, 0}, [&](const std::array<u64,4>& m121) {
              u64 v_c31 = m121[3];
              slog::join_probe<2,2>(st_fromlistindex83, std::array<u64,2>{v_c31, v_c25}, [&](const std::array<u64,2>& m122) {
                slog::join_probe<2,1>(st_fromlist_ansindex84, std::array<u64,2>{v_c11, 0}, [&](const std::array<u64,2>& m123) {
                  u64 v_c32 = m123[1];
                  slog::join_probe<2,2>(st_fromlistindex85, std::array<u64,2>{v_c32, v_c30}, [&](const std::array<u64,2>& m124) {
                    bool ok125 = true;
                    u64 v_c33 = _prim_lref(db, v_c26, v_c19, &ok125);
                    if (!ok125) return;
                    if (v_c24 != v_c33) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c31, v_c5}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:169", "delta:st_ins_ans", _fires);
  
      if (!_done)
      {
        ReadTask88* _cont = new ReadTask88(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask88(db,b), false);
  // (crule (pre (let __tconst9YUA1125 conste3776bfed7f405de8017ecfa) (let __tconst7TTg43 constef2d127de37b942baad06145) (let __tconst35F246 const2c624232cdd221771294dfbb) (let __tconst0QyJ48 constd4735e3a265e16eee03f5971) (let __tconst6ZQr51 const6b86b273ff34fce19d6b804e)) (probe st_ins (2 0 1) 1 __tconst35F246 __t4CDi47 __v0) (body (exists st_ins (2 0 1) 1 __tconst7TTg43) (exists st_ins_ans (1 0) 1 __v0) (exists st_ins (2 0 1) 1 __tconst0QyJ48) (exists st_ins_ans (0 1) 1 __t4CDi47) (exists st_ins (2 0 1) 1 __tconst6ZQr51) (join _enum (1 0) 1 __tconst9YUA1125 __t7Lp349) (exists st_ins (1 2 0) 2 __t7Lp349 __tconst0QyJ48) (join st_ins (1 2 0) 2 __t7Lp349 __tconst7TTg43 __t8j8m45) (join st_ins_ans (0 1) 2 __t8j8m45 __v0) (join-old st_ins (1 2 0) 2 (1 2 0) __t7Lp349 __tconst0QyJ48 __t3nMl50) (exists st_ins_ans (0 1) 1 __t3nMl50) (join st_ins_ans (0 1) 1 __t4CDi47 a) (exists st_union (1 2 0) 1 a) (join st_ins_ans (0 1) 1 __t3nMl50 __v1) (join-old st_ins (1 2 0) 2 (1 2 0) __v1 __tconst6ZQr51 __t7CuH52) (join st_ins_ans (0 1) 1 __t7CuH52 b) (join-old st_union (1 2 0) 2 (1 2 0) a b __t8gtb53) (join st_union_ans (0 1) 1 __t8gtb53 r)) (head (emit canon (0) r)) st_basic.slog:18 #f)
  class ReadTask147 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** st_insindex126;  slog::Index** st_ins_ansindex127;  slog::Index** st_insindex128;  slog::Index** st_ins_ansindex129;  slog::Index** st_insindex130;  slog::Index** _enumindex131;  slog::Index** st_insindex132;  slog::Index** st_insindex133;  slog::Index** st_ins_ansindex134;  slog::Index** st_insindex135;  slog::Index** st_ins_ansindex136;  slog::Index** st_ins_ansindex137;  slog::Index** st_unionindex138;  slog::Index** st_ins_ansindex139;  slog::Index** st_insindex140;  slog::Index** st_ins_ansindex141;  slog::Index** st_unionindex142;  slog::Index** st_union_ansindex143;  slog::Index** st_insdelta144;  slog::Index** st_insdelta145;  slog::Index** st_uniondelta146;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("canon");
      std::vector<u16> ord148({0});
      slog::Relation* readrel149 = db->getRelation("canon");
      head_index[0] = readrel149->getIndex(ord148, false);
      std::vector<u16> ord150({2, 0, 1});
      slog::Relation* readrel151 = db->getRelation("st_ins");
      driver_index = readrel151->getIndex(ord150, true);
      std::vector<u16> ord152({2, 0, 1});
      slog::Relation* readrel153 = db->getRelation("st_ins");
      st_insindex126 = readrel153->getIndex(ord152, false);
      std::vector<u16> ord154({1, 0});
      slog::Relation* readrel155 = db->getRelation("st_ins_ans");
      st_ins_ansindex127 = readrel155->getIndex(ord154, false);
      std::vector<u16> ord156({2, 0, 1});
      slog::Relation* readrel157 = db->getRelation("st_ins");
      st_insindex128 = readrel157->getIndex(ord156, false);
      std::vector<u16> ord158({0, 1});
      slog::Relation* readrel159 = db->getRelation("st_ins_ans");
      st_ins_ansindex129 = readrel159->getIndex(ord158, false);
      std::vector<u16> ord160({2, 0, 1});
      slog::Relation* readrel161 = db->getRelation("st_ins");
      st_insindex130 = readrel161->getIndex(ord160, false);
      std::vector<u16> ord162({1, 0});
      slog::Relation* readrel163 = db->getRelation("_enum");
      _enumindex131 = readrel163->getIndex(ord162, false);
      std::vector<u16> ord164({1, 2, 0});
      slog::Relation* readrel165 = db->getRelation("st_ins");
      st_insindex132 = readrel165->getIndex(ord164, false);
      std::vector<u16> ord166({1, 2, 0});
      slog::Relation* readrel167 = db->getRelation("st_ins");
      st_insindex133 = readrel167->getIndex(ord166, false);
      std::vector<u16> ord168({0, 1});
      slog::Relation* readrel169 = db->getRelation("st_ins_ans");
      st_ins_ansindex134 = readrel169->getIndex(ord168, false);
      std::vector<u16> ord170({1, 2, 0});
      slog::Relation* readrel171 = db->getRelation("st_ins");
      st_insindex135 = readrel171->getIndex(ord170, false);
      std::vector<u16> ord172({1, 2, 0});
      slog::Relation* readrel173 = db->getRelation("st_ins");
      st_insdelta144 = readrel173->getIndex(ord172, true);
      std::vector<u16> ord174({0, 1});
      slog::Relation* readrel175 = db->getRelation("st_ins_ans");
      st_ins_ansindex136 = readrel175->getIndex(ord174, false);
      std::vector<u16> ord176({0, 1});
      slog::Relation* readrel177 = db->getRelation("st_ins_ans");
      st_ins_ansindex137 = readrel177->getIndex(ord176, false);
      std::vector<u16> ord178({1, 2, 0});
      slog::Relation* readrel179 = db->getRelation("st_union");
      st_unionindex138 = readrel179->getIndex(ord178, false);
      std::vector<u16> ord180({0, 1});
      slog::Relation* readrel181 = db->getRelation("st_ins_ans");
      st_ins_ansindex139 = readrel181->getIndex(ord180, false);
      std::vector<u16> ord182({1, 2, 0});
      slog::Relation* readrel183 = db->getRelation("st_ins");
      st_insindex140 = readrel183->getIndex(ord182, false);
      std::vector<u16> ord184({1, 2, 0});
      slog::Relation* readrel185 = db->getRelation("st_ins");
      st_insdelta145 = readrel185->getIndex(ord184, true);
      std::vector<u16> ord186({0, 1});
      slog::Relation* readrel187 = db->getRelation("st_ins_ans");
      st_ins_ansindex141 = readrel187->getIndex(ord186, false);
      std::vector<u16> ord188({1, 2, 0});
      slog::Relation* readrel189 = db->getRelation("st_union");
      st_unionindex142 = readrel189->getIndex(ord188, false);
      std::vector<u16> ord190({1, 2, 0});
      slog::Relation* readrel191 = db->getRelation("st_union");
      st_uniondelta146 = readrel191->getIndex(ord190, true);
      std::vector<u16> ord192({0, 1});
      slog::Relation* readrel193 = db->getRelation("st_union_ans");
      st_union_ansindex143 = readrel193->getIndex(ord192, false);
  
    }
    ReadTask147(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c34 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c35 = v_constef2d127de37b942baad06145;
      u64 v_c36 = v_const2c624232cdd221771294dfbb;
      u64 v_c37 = v_constd4735e3a265e16eee03f5971;
      u64 v_c38 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c36, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m194) {
        u64 v_c39 = m194[1];
        u64 v_c11 = m194[2];
        if (buckethash(v_c39) != bucket) return;
        if (!slog::exists_probe<3,1>(st_insindex126, std::array<u64,3>{v_c35, 0, 0})) return;
        if (!slog::exists_probe<2,1>(st_ins_ansindex127, std::array<u64,2>{v_c11, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex128, std::array<u64,3>{v_c37, 0, 0})) return;
        if (!slog::exists_probe<2,1>(st_ins_ansindex129, std::array<u64,2>{v_c39, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex130, std::array<u64,3>{v_c38, 0, 0})) return;
        slog::join_probe<2,1>(_enumindex131, std::array<u64,2>{v_c34, 0}, [&](const std::array<u64,2>& m195) {
          u64 v_c40 = m195[1];
          if (!slog::exists_probe<3,2>(st_insindex132, std::array<u64,3>{v_c40, v_c37, 0})) return;
          slog::join_probe<3,2>(st_insindex133, std::array<u64,3>{v_c40, v_c35, 0}, [&](const std::array<u64,3>& m196) {
            u64 v_c41 = m196[2];
            slog::join_probe<2,2>(st_ins_ansindex134, std::array<u64,2>{v_c41, v_c11}, [&](const std::array<u64,2>& m197) {
              slog::join_probe_old<3,2>(st_insindex135, st_insdelta144, std::array<u64,3>{v_c40, v_c37, 0}, [&](const std::array<u64,3>& m198) {
                u64 v_c42 = m198[2];
                if (!slog::exists_probe<2,1>(st_ins_ansindex136, std::array<u64,2>{v_c42, 0})) return;
                slog::join_probe<2,1>(st_ins_ansindex137, std::array<u64,2>{v_c39, 0}, [&](const std::array<u64,2>& m199) {
                  u64 v_c43 = m199[1];
                  if (!slog::exists_probe<3,1>(st_unionindex138, std::array<u64,3>{v_c43, 0, 0})) return;
                  slog::join_probe<2,1>(st_ins_ansindex139, std::array<u64,2>{v_c42, 0}, [&](const std::array<u64,2>& m200) {
                    u64 v_c5 = m200[1];
                    slog::join_probe_old<3,2>(st_insindex140, st_insdelta145, std::array<u64,3>{v_c5, v_c38, 0}, [&](const std::array<u64,3>& m201) {
                      u64 v_c44 = m201[2];
                      slog::join_probe<2,1>(st_ins_ansindex141, std::array<u64,2>{v_c44, 0}, [&](const std::array<u64,2>& m202) {
                        u64 v_c45 = m202[1];
                        slog::join_probe_old<3,2>(st_unionindex142, st_uniondelta146, std::array<u64,3>{v_c43, v_c45, 0}, [&](const std::array<u64,3>& m203) {
                          u64 v_c46 = m203[2];
                          slog::join_probe<2,1>(st_union_ansindex143, std::array<u64,2>{v_c46, 0}, [&](const std::array<u64,2>& m204) {
                            u64 v_c47 = m204[1];
                            ++_fires;
                            slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c47}, std::array<u16,1>{0});
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
  
      if (_fires) db->bumpFires("st_basic.slog:18", "delta:st_ins", _fires);
  
      if (!_done)
      {
        ReadTask147* _cont = new ReadTask147(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask147(db,b), false);
  // (crule (pre (let __tconst63YF62 const6b86b273ff34fce19d6b804e)) (scan pbranch __t2ifW59 q n u v) (body (exists $sup9688x114x0x0x1 (8 4 6 9 0 2 3 5 7 1) 4 u n q v) (exists st_union (2 0 1) 1 __t2ifW59) (exists st_msk (2 0 1) 1 n) (exists st_msk_ans (1 0) 1 q) (exists st_union (2 0 1) 1 u) (join $sup9688x114x0x0x0 (5 3 7 8 0 1 2 4 6) 4 q n u v __t2j0W61 l m p r) (cmp lt m n) (exists pbranch (1 2 3 4 0) 4 p m l r) (exists st_union (2 0 1) 2 __t2ifW59 __t2j0W61) (exists st_msk (1 2 0) 2 p n) (join $sup9688x114x0x0x1 (8 4 6 9 0 2 3 5 7 1) 9 u n q v __t2j0W61 l m p r __t1Zy964) (exists st_msk (1 2 0) 3 p n __t1Zy964) (exists st_msk_ans (0 1) 2 __t1Zy964 q) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t5Obr65) (join-old st_union (0 1 2) 3 (0 1 2) __t2j0W61 __t5Obr65 __t2ifW59) (join-old st_msk (1 2 0) 3 (1 2 0) p n __t1Zy964) (join st_msk_ans (0 1) 2 __t1Zy964 q) (join-old st_union (1 2 0) 2 (1 2 0) __t5Obr65 u __t6dzp66) (join st_union_ans (0 1) 1 __t6dzp66 __v0) (let __t3h5j63 (band p n)) (cmp lt __t3h5j63 __tconst63YF62)) (head (emit-temp temp1Dk71281 __t2j0W61 __v0 n q v) (mkstruct pbranch (1 2 3 4 0) __t0srE58 q n __v0 v)) set.slog:115 #f)
  class ReadTask227 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x114x0x0x1index205;  slog::Index** st_unionindex206;  slog::Index** st_mskindex207;  slog::Index** st_msk_ansindex208;  slog::Index** st_unionindex209;  slog::Index** $sup9688x114x0x0x0index210;  slog::Index** pbranchindex211;  slog::Index** st_unionindex212;  slog::Index** st_mskindex213;  slog::Index** $sup9688x114x0x0x1index214;  slog::Index** st_mskindex215;  slog::Index** st_msk_ansindex216;  slog::Index** pbranchindex217;  slog::Index** st_unionindex218;  slog::Index** st_mskindex219;  slog::Index** st_msk_ansindex220;  slog::Index** st_unionindex221;  slog::Index** st_union_ansindex222;  slog::Index** pbranchdelta223;  slog::Index** st_uniondelta224;  slog::Index** st_mskdelta225;  slog::Index** st_uniondelta226;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp1Dk71281");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord228({8, 4, 6, 9, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel229 = db->getRelation("$sup9688x114x0x0x1");
      $sup9688x114x0x0x1index205 = readrel229->getIndex(ord228, false);
      std::vector<u16> ord230({2, 0, 1});
      slog::Relation* readrel231 = db->getRelation("st_union");
      st_unionindex206 = readrel231->getIndex(ord230, false);
      std::vector<u16> ord232({2, 0, 1});
      slog::Relation* readrel233 = db->getRelation("st_msk");
      st_mskindex207 = readrel233->getIndex(ord232, false);
      std::vector<u16> ord234({1, 0});
      slog::Relation* readrel235 = db->getRelation("st_msk_ans");
      st_msk_ansindex208 = readrel235->getIndex(ord234, false);
      std::vector<u16> ord236({2, 0, 1});
      slog::Relation* readrel237 = db->getRelation("st_union");
      st_unionindex209 = readrel237->getIndex(ord236, false);
      std::vector<u16> ord238({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel239 = db->getRelation("$sup9688x114x0x0x0");
      $sup9688x114x0x0x0index210 = readrel239->getIndex(ord238, false);
      std::vector<u16> ord240({1, 2, 3, 4, 0});
      slog::Relation* readrel241 = db->getRelation("pbranch");
      pbranchindex211 = readrel241->getIndex(ord240, false);
      std::vector<u16> ord242({2, 0, 1});
      slog::Relation* readrel243 = db->getRelation("st_union");
      st_unionindex212 = readrel243->getIndex(ord242, false);
      std::vector<u16> ord244({1, 2, 0});
      slog::Relation* readrel245 = db->getRelation("st_msk");
      st_mskindex213 = readrel245->getIndex(ord244, false);
      std::vector<u16> ord246({8, 4, 6, 9, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel247 = db->getRelation("$sup9688x114x0x0x1");
      $sup9688x114x0x0x1index214 = readrel247->getIndex(ord246, false);
      std::vector<u16> ord248({1, 2, 0});
      slog::Relation* readrel249 = db->getRelation("st_msk");
      st_mskindex215 = readrel249->getIndex(ord248, false);
      std::vector<u16> ord250({0, 1});
      slog::Relation* readrel251 = db->getRelation("st_msk_ans");
      st_msk_ansindex216 = readrel251->getIndex(ord250, false);
      std::vector<u16> ord252({1, 2, 3, 4, 0});
      slog::Relation* readrel253 = db->getRelation("pbranch");
      pbranchindex217 = readrel253->getIndex(ord252, false);
      std::vector<u16> ord254({1, 2, 3, 4, 0});
      slog::Relation* readrel255 = db->getRelation("pbranch");
      pbranchdelta223 = readrel255->getIndex(ord254, true);
      std::vector<u16> ord256({0, 1, 2});
      slog::Relation* readrel257 = db->getRelation("st_union");
      st_unionindex218 = readrel257->getIndex(ord256, false);
      std::vector<u16> ord258({0, 1, 2});
      slog::Relation* readrel259 = db->getRelation("st_union");
      st_uniondelta224 = readrel259->getIndex(ord258, true);
      std::vector<u16> ord260({1, 2, 0});
      slog::Relation* readrel261 = db->getRelation("st_msk");
      st_mskindex219 = readrel261->getIndex(ord260, false);
      std::vector<u16> ord262({1, 2, 0});
      slog::Relation* readrel263 = db->getRelation("st_msk");
      st_mskdelta225 = readrel263->getIndex(ord262, true);
      std::vector<u16> ord264({0, 1});
      slog::Relation* readrel265 = db->getRelation("st_msk_ans");
      st_msk_ansindex220 = readrel265->getIndex(ord264, false);
      std::vector<u16> ord266({1, 2, 0});
      slog::Relation* readrel267 = db->getRelation("st_union");
      st_unionindex221 = readrel267->getIndex(ord266, false);
      std::vector<u16> ord268({1, 2, 0});
      slog::Relation* readrel269 = db->getRelation("st_union");
      st_uniondelta226 = readrel269->getIndex(ord268, true);
      std::vector<u16> ord270({0, 1});
      slog::Relation* readrel271 = db->getRelation("st_union_ans");
      st_union_ansindex222 = readrel271->getIndex(ord270, false);
  
    }
    ReadTask227(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c48 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c49 = _t[0];
        u64 v_c50 = _t[1];
        u64 v_c51 = _t[2];
        u64 v_c52 = _t[3];
        u64 v_c53 = _t[4];
        if (!slog::exists_probe<10,4>($sup9688x114x0x0x1index205, std::array<u64,10>{v_c52, v_c51, v_c50, v_c53, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_unionindex206, std::array<u64,3>{v_c49, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mskindex207, std::array<u64,3>{v_c51, 0, 0})) return;
        if (!slog::exists_probe<2,1>(st_msk_ansindex208, std::array<u64,2>{v_c50, 0})) return;
        if (!slog::exists_probe<3,1>(st_unionindex209, std::array<u64,3>{v_c52, 0, 0})) return;
        slog::join_probe<9,4>($sup9688x114x0x0x0index210, std::array<u64,9>{v_c50, v_c51, v_c52, v_c53, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m272) {
          u64 v_c54 = m272[4]; u64 v_c55 = m272[5]; u64 v_c56 = m272[6]; u64 v_c57 = m272[7]; u64 v_c47 = m272[8];
          u64 v_c58 = _prim_lt(db, v_c56, v_c51);
          if (v_c58 == slog_error) { slog::emit_pending_error(db, "set.slog:115"); return; }
          if (!v_c58) return;
          if (!slog::exists_probe<5,4>(pbranchindex211, std::array<u64,5>{v_c57, v_c56, v_c55, v_c47, 0})) return;
          if (!slog::exists_probe<3,2>(st_unionindex212, std::array<u64,3>{v_c49, v_c54, 0})) return;
          if (!slog::exists_probe<3,2>(st_mskindex213, std::array<u64,3>{v_c57, v_c51, 0})) return;
          slog::join_probe<10,9>($sup9688x114x0x0x1index214, std::array<u64,10>{v_c52, v_c51, v_c50, v_c53, v_c54, v_c55, v_c56, v_c57, v_c47, 0}, [&](const std::array<u64,10>& m274) {
            u64 v_c59 = m274[9];
            if (!slog::exists_probe<3,3>(st_mskindex215, std::array<u64,3>{v_c57, v_c51, v_c59})) return;
            if (!slog::exists_probe<2,2>(st_msk_ansindex216, std::array<u64,2>{v_c59, v_c50})) return;
            slog::join_probe_old<5,4>(pbranchindex217, pbranchdelta223, std::array<u64,5>{v_c57, v_c56, v_c55, v_c47, 0}, [&](const std::array<u64,5>& m275) {
              u64 v_c60 = m275[4];
              slog::join_probe_old<3,3>(st_unionindex218, st_uniondelta224, std::array<u64,3>{v_c54, v_c60, v_c49}, [&](const std::array<u64,3>& m276) {
                slog::join_probe_old<3,3>(st_mskindex219, st_mskdelta225, std::array<u64,3>{v_c57, v_c51, v_c59}, [&](const std::array<u64,3>& m277) {
                  slog::join_probe<2,2>(st_msk_ansindex220, std::array<u64,2>{v_c59, v_c50}, [&](const std::array<u64,2>& m278) {
                    slog::join_probe_old<3,2>(st_unionindex221, st_uniondelta226, std::array<u64,3>{v_c60, v_c52, 0}, [&](const std::array<u64,3>& m279) {
                      u64 v_c61 = m279[2];
                      slog::join_probe<2,1>(st_union_ansindex222, std::array<u64,2>{v_c61, 0}, [&](const std::array<u64,2>& m280) {
                        u64 v_c11 = m280[1];
                        u64 v_c62 = _prim_band(db, v_c57, v_c51);
                        if (v_c62 == slog_error) { slog::emit_pending_error(db, "set.slog:115"); return; }
                        u64 v_c63 = _prim_lt(db, v_c62, v_c48);
                        if (v_c63 == slog_error) { slog::emit_pending_error(db, "set.slog:115"); return; }
                        if (!v_c63) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c54, v_c11, v_c51, v_c50, v_c53});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c50, v_c51, v_c11, v_c53}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:115", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask227* _cont = new ReadTask227(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask227(db,b), false);
  // (crule (pre) (scan $sup9688x40x0x0x1 __d0 __d1 __v0 p0 p1 t0 t1) (body (let __t638T579 (bxor p0 p1))) (head (emit-temp temp3V0b1338 __t638T579)) set.slog:41 #f)
  class ReadTask282 : public slog::Task
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
      head_rel[0] = db->getRelation("temp3V0b1338");
      outer_rel = db->getRelation("$sup9688x40x0x0x1");
  
    }
    ReadTask282(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c11 = _t[2];
        u64 v_c4 = _t[3];
        u64 v_c12 = _t[4];
        u64 v_c13 = _t[5];
        u64 v_c14 = _t[6];
        u64 v_c66 = _prim_bxor(db, v_c4, v_c12);
        if (v_c66 == slog_error) { slog::emit_pending_error(db, "set.slog:41"); return; }
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c66});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:41", "delta:$sup9688x40x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask282* _cont = new ReadTask282(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask282(db,b), false);
  // (crule (pre) (scan temp00v81415 __t1yUC575 __t5cKm574) (body) (head (emit st_msk_ans (0 1) __t1yUC575 __t5cKm574)) set.slog:33 #f)
  class ReadTask283 : public slog::Task
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
      head_rel[0] = db->getRelation("st_msk_ans");
      std::vector<u16> ord284({0, 1});
      slog::Relation* readrel285 = db->getRelation("st_msk_ans");
      head_index[0] = readrel285->getIndex(ord284, false);
      outer_rel = db->getRelation("temp00v81415");
  
    }
    ReadTask283(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        ++_fires;
        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c67, v_c68}, std::array<u16,2>{0, 1});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:33", "delta:temp00v81415", _fires);
  
      if (!_done)
      {
        ReadTask283* _cont = new ReadTask283(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask283(db,b), false);
  // (crule (pre (let __tconst8cca353 const6b86b273ff34fce19d6b804e)) (scan st_msk __t9xbE359 p0 __v1) (body (exists st_hsb_ans (1 0) 1 __v1) (exists $sup9688x36x0x0x2 (5 7 1 0 2 3 4 6 8 9 10) 2 __v1 p0) (exists $sup9688x36x0x0x1 (3 1 0 2 4 5 6) 1 p0) (exists $sup9688x36x0x0x0 (1 0 2 3 4) 1 p0) (exists st_join (1 2 3 4 0) 1 p0) (join st_msk_ans (0 1) 1 __t9xbE359 __v2) (join st_hsb_ans (1 0) 1 __v1 __t75bg356) (exists $sup9688x36x0x0x2 (5 7 1 0 2 3 4 6 8 9 10) 3 __v1 p0 __t75bg356) (exists $sup9688x36x0x0x1 (3 1 0 2 4 5 6) 2 p0 __t75bg356) (exists st_hsb_ans (0 1) 1 __t75bg356) (join st_hsb_ans (0 1) 1 __t75bg356 __v3) (join $sup9688x36x0x0x2 (1 5 6 7 0 2 3 4 8 9 10) 4 __t75bg356 __v1 __v3 p0 __t0kmv352 dup66Lo1333 dup68E21334 __v0 p1 t0 t1) (eq __t75bg356 dup68E21334) (eq __t75bg356 dup66Lo1333) (join $sup9688x36x0x0x1 (0 3 4 5 6 1 2) 7 __t0kmv352 p0 p1 t0 t1 __t75bg356 __v0) (join $sup9688x36x0x0x0 (1 0 2 3 4) 5 p0 __t0kmv352 p1 t0 t1) (join-old st_join (1 2 3 4 0) 5 (1 2 3 4 0) p0 t0 p1 t1 __t0kmv352) (join st_hsb_ans (0 1) 2 __t75bg356 __v0) (let __t5oQR360 (bxor p0 p1)) (join-old st_hsb (0 1) 2 (0 1) __t75bg356 __t5oQR360) (let __t3ChK354 (band p0 __v0)) (cmp lt __t3ChK354 __tconst8cca353)) (head (emit-temp temp3xVH1332 __t0kmv352 __v2 __v3 t0 t1) (mkstruct pbranch (1 2 3 4 0) __t4fDE351 __v2 __v3 t0 t1)) set.slog:37 #f)
  class ReadTask305 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_hsb_ansindex286;  slog::Index** $sup9688x36x0x0x2index287;  slog::Index** $sup9688x36x0x0x1index288;  slog::Index** $sup9688x36x0x0x0index289;  slog::Index** st_joinindex290;  slog::Index** st_msk_ansindex291;  slog::Index** st_hsb_ansindex292;  slog::Index** $sup9688x36x0x0x2index293;  slog::Index** $sup9688x36x0x0x1index294;  slog::Index** st_hsb_ansindex295;  slog::Index** st_hsb_ansindex296;  slog::Index** $sup9688x36x0x0x2index297;  slog::Index** $sup9688x36x0x0x1index298;  slog::Index** $sup9688x36x0x0x0index299;  slog::Index** st_joinindex300;  slog::Index** st_hsb_ansindex301;  slog::Index** st_hsbindex302;  slog::Index** st_joindelta303;  slog::Index** st_hsbdelta304;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3xVH1332");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("st_msk");
      std::vector<u16> ord306({1, 0});
      slog::Relation* readrel307 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex286 = readrel307->getIndex(ord306, false);
      std::vector<u16> ord308({5, 7, 1, 0, 2, 3, 4, 6, 8, 9, 10});
      slog::Relation* readrel309 = db->getRelation("$sup9688x36x0x0x2");
      $sup9688x36x0x0x2index287 = readrel309->getIndex(ord308, false);
      std::vector<u16> ord310({3, 1, 0, 2, 4, 5, 6});
      slog::Relation* readrel311 = db->getRelation("$sup9688x36x0x0x1");
      $sup9688x36x0x0x1index288 = readrel311->getIndex(ord310, false);
      std::vector<u16> ord312({1, 0, 2, 3, 4});
      slog::Relation* readrel313 = db->getRelation("$sup9688x36x0x0x0");
      $sup9688x36x0x0x0index289 = readrel313->getIndex(ord312, false);
      std::vector<u16> ord314({1, 2, 3, 4, 0});
      slog::Relation* readrel315 = db->getRelation("st_join");
      st_joinindex290 = readrel315->getIndex(ord314, false);
      std::vector<u16> ord316({0, 1});
      slog::Relation* readrel317 = db->getRelation("st_msk_ans");
      st_msk_ansindex291 = readrel317->getIndex(ord316, false);
      std::vector<u16> ord318({1, 0});
      slog::Relation* readrel319 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex292 = readrel319->getIndex(ord318, false);
      std::vector<u16> ord320({5, 7, 1, 0, 2, 3, 4, 6, 8, 9, 10});
      slog::Relation* readrel321 = db->getRelation("$sup9688x36x0x0x2");
      $sup9688x36x0x0x2index293 = readrel321->getIndex(ord320, false);
      std::vector<u16> ord322({3, 1, 0, 2, 4, 5, 6});
      slog::Relation* readrel323 = db->getRelation("$sup9688x36x0x0x1");
      $sup9688x36x0x0x1index294 = readrel323->getIndex(ord322, false);
      std::vector<u16> ord324({0, 1});
      slog::Relation* readrel325 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex295 = readrel325->getIndex(ord324, false);
      std::vector<u16> ord326({0, 1});
      slog::Relation* readrel327 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex296 = readrel327->getIndex(ord326, false);
      std::vector<u16> ord328({1, 5, 6, 7, 0, 2, 3, 4, 8, 9, 10});
      slog::Relation* readrel329 = db->getRelation("$sup9688x36x0x0x2");
      $sup9688x36x0x0x2index297 = readrel329->getIndex(ord328, false);
      std::vector<u16> ord330({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel331 = db->getRelation("$sup9688x36x0x0x1");
      $sup9688x36x0x0x1index298 = readrel331->getIndex(ord330, false);
      std::vector<u16> ord332({1, 0, 2, 3, 4});
      slog::Relation* readrel333 = db->getRelation("$sup9688x36x0x0x0");
      $sup9688x36x0x0x0index299 = readrel333->getIndex(ord332, false);
      std::vector<u16> ord334({1, 2, 3, 4, 0});
      slog::Relation* readrel335 = db->getRelation("st_join");
      st_joinindex300 = readrel335->getIndex(ord334, false);
      std::vector<u16> ord336({1, 2, 3, 4, 0});
      slog::Relation* readrel337 = db->getRelation("st_join");
      st_joindelta303 = readrel337->getIndex(ord336, true);
      std::vector<u16> ord338({0, 1});
      slog::Relation* readrel339 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex301 = readrel339->getIndex(ord338, false);
      std::vector<u16> ord340({0, 1});
      slog::Relation* readrel341 = db->getRelation("st_hsb");
      st_hsbindex302 = readrel341->getIndex(ord340, false);
      std::vector<u16> ord342({0, 1});
      slog::Relation* readrel343 = db->getRelation("st_hsb");
      st_hsbdelta304 = readrel343->getIndex(ord342, true);
  
    }
    ReadTask305(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c69 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c4 = _t[1];
        u64 v_c5 = _t[2];
        if (!slog::exists_probe<2,1>(st_hsb_ansindex286, std::array<u64,2>{v_c5, 0})) return;
        if (!slog::exists_probe<11,2>($sup9688x36x0x0x2index287, std::array<u64,11>{v_c5, v_c4, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<7,1>($sup9688x36x0x0x1index288, std::array<u64,7>{v_c4, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>($sup9688x36x0x0x0index289, std::array<u64,5>{v_c4, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(st_joinindex290, std::array<u64,5>{v_c4, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(st_msk_ansindex291, std::array<u64,2>{v_c70, 0}, [&](const std::array<u64,2>& m344) {
          u64 v_c3 = m344[1];
          slog::join_probe<2,1>(st_hsb_ansindex292, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m345) {
            u64 v_c71 = m345[1];
            if (!slog::exists_probe<11,3>($sup9688x36x0x0x2index293, std::array<u64,11>{v_c5, v_c4, v_c71, 0, 0, 0, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<7,2>($sup9688x36x0x0x1index294, std::array<u64,7>{v_c4, v_c71, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<2,1>(st_hsb_ansindex295, std::array<u64,2>{v_c71, 0})) return;
            slog::join_probe<2,1>(st_hsb_ansindex296, std::array<u64,2>{v_c71, 0}, [&](const std::array<u64,2>& m346) {
              u64 v_c7 = m346[1];
              slog::join_probe<11,4>($sup9688x36x0x0x2index297, std::array<u64,11>{v_c71, v_c5, v_c7, v_c4, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m347) {
                u64 v_c72 = m347[4]; u64 v_c73 = m347[5]; u64 v_c74 = m347[6]; u64 v_c11 = m347[7]; u64 v_c12 = m347[8]; u64 v_c13 = m347[9]; u64 v_c14 = m347[10];
                if (v_c71 != v_c74) return;
                if (v_c71 != v_c73) return;
                slog::join_probe<7,7>($sup9688x36x0x0x1index298, std::array<u64,7>{v_c72, v_c4, v_c12, v_c13, v_c14, v_c71, v_c11}, [&](const std::array<u64,7>& m348) {
                  slog::join_probe<5,5>($sup9688x36x0x0x0index299, std::array<u64,5>{v_c4, v_c72, v_c12, v_c13, v_c14}, [&](const std::array<u64,5>& m349) {
                    slog::join_probe_old<5,5>(st_joinindex300, st_joindelta303, std::array<u64,5>{v_c4, v_c13, v_c12, v_c14, v_c72}, [&](const std::array<u64,5>& m350) {
                      slog::join_probe<2,2>(st_hsb_ansindex301, std::array<u64,2>{v_c71, v_c11}, [&](const std::array<u64,2>& m351) {
                        u64 v_c75 = _prim_bxor(db, v_c4, v_c12);
                        if (v_c75 == slog_error) { slog::emit_pending_error(db, "set.slog:37"); return; }
                        slog::join_probe_old<2,2>(st_hsbindex302, st_hsbdelta304, std::array<u64,2>{v_c71, v_c75}, [&](const std::array<u64,2>& m352) {
                          u64 v_c76 = _prim_band(db, v_c4, v_c11);
                          if (v_c76 == slog_error) { slog::emit_pending_error(db, "set.slog:37"); return; }
                          u64 v_c77 = _prim_lt(db, v_c76, v_c69);
                          if (v_c77 == slog_error) { slog::emit_pending_error(db, "set.slog:37"); return; }
                          if (!v_c77) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c72, v_c3, v_c7, v_c13, v_c14});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c3, v_c7, v_c13, v_c14}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:37", "delta:st_msk", _fires);
  
      if (!_done)
      {
        ReadTask305* _cont = new ReadTask305(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask305(db,b), false);
  // (crule (pre (let __tconst9B7m280 const6b86b273ff34fce19d6b804e)) (scan st_bld __t6UON282 p m __v0 r) (body (exists $sup9688x88x0x0x0 (4 3 5 2 0 1) 3 p m r) (exists st_msk (2 0 1) 1 m) (exists st_msk_ans (1 0) 1 p) (exists st_del_ans (1 0) 1 __v0) (exists st_bld_ans (0 1) 1 __t6UON282) (join pbranch (1 2 4 0 3) 3 p m r __t2u9k278 l) (exists st_del (1 2 0) 1 __t2u9k278) (exists st_del (1 2 0) 1 l) (join $sup9688x88x0x0x0 (4 3 5 2 0 1) 4 p m r l __t3OU0279 k) (join st_del (0 2 1) 3 __t3OU0279 k __t2u9k278) (exists st_del (1 2 0) 2 l k) (join-old st_msk (1 2 0) 2 (1 2 0) k m __t5pdy283) (join st_msk_ans (0 1) 2 __t5pdy283 p) (join-old st_del (1 2 0) 2 (1 2 0) l k __t62j9284) (join st_del_ans (0 1) 2 __t62j9284 __v0) (join st_bld_ans (0 1) 1 __t6UON282 res) (let __t4Xlx281 (band k m)) (cmp lt __t4Xlx281 __tconst9B7m280)) (head (emit st_del_ans (0 1) __t3OU0279 res)) set.slog:89 #f)
  class ReadTask372 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x88x0x0x0index354;  slog::Index** st_mskindex355;  slog::Index** st_msk_ansindex356;  slog::Index** st_del_ansindex357;  slog::Index** st_bld_ansindex358;  slog::Index** pbranchindex359;  slog::Index** st_delindex360;  slog::Index** st_delindex361;  slog::Index** $sup9688x88x0x0x0index362;  slog::Index** st_delindex363;  slog::Index** st_delindex364;  slog::Index** st_mskindex365;  slog::Index** st_msk_ansindex366;  slog::Index** st_delindex367;  slog::Index** st_del_ansindex368;  slog::Index** st_bld_ansindex369;  slog::Index** st_mskdelta370;  slog::Index** st_deldelta371;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_del_ans");
      std::vector<u16> ord373({0, 1});
      slog::Relation* readrel374 = db->getRelation("st_del_ans");
      head_index[0] = readrel374->getIndex(ord373, false);
      outer_rel = db->getRelation("st_bld");
      std::vector<u16> ord375({4, 3, 5, 2, 0, 1});
      slog::Relation* readrel376 = db->getRelation("$sup9688x88x0x0x0");
      $sup9688x88x0x0x0index354 = readrel376->getIndex(ord375, false);
      std::vector<u16> ord377({2, 0, 1});
      slog::Relation* readrel378 = db->getRelation("st_msk");
      st_mskindex355 = readrel378->getIndex(ord377, false);
      std::vector<u16> ord379({1, 0});
      slog::Relation* readrel380 = db->getRelation("st_msk_ans");
      st_msk_ansindex356 = readrel380->getIndex(ord379, false);
      std::vector<u16> ord381({1, 0});
      slog::Relation* readrel382 = db->getRelation("st_del_ans");
      st_del_ansindex357 = readrel382->getIndex(ord381, false);
      std::vector<u16> ord383({0, 1});
      slog::Relation* readrel384 = db->getRelation("st_bld_ans");
      st_bld_ansindex358 = readrel384->getIndex(ord383, false);
      std::vector<u16> ord385({1, 2, 4, 0, 3});
      slog::Relation* readrel386 = db->getRelation("pbranch");
      pbranchindex359 = readrel386->getIndex(ord385, false);
      std::vector<u16> ord387({1, 2, 0});
      slog::Relation* readrel388 = db->getRelation("st_del");
      st_delindex360 = readrel388->getIndex(ord387, false);
      std::vector<u16> ord389({1, 2, 0});
      slog::Relation* readrel390 = db->getRelation("st_del");
      st_delindex361 = readrel390->getIndex(ord389, false);
      std::vector<u16> ord391({4, 3, 5, 2, 0, 1});
      slog::Relation* readrel392 = db->getRelation("$sup9688x88x0x0x0");
      $sup9688x88x0x0x0index362 = readrel392->getIndex(ord391, false);
      std::vector<u16> ord393({0, 2, 1});
      slog::Relation* readrel394 = db->getRelation("st_del");
      st_delindex363 = readrel394->getIndex(ord393, false);
      std::vector<u16> ord395({1, 2, 0});
      slog::Relation* readrel396 = db->getRelation("st_del");
      st_delindex364 = readrel396->getIndex(ord395, false);
      std::vector<u16> ord397({1, 2, 0});
      slog::Relation* readrel398 = db->getRelation("st_msk");
      st_mskindex365 = readrel398->getIndex(ord397, false);
      std::vector<u16> ord399({1, 2, 0});
      slog::Relation* readrel400 = db->getRelation("st_msk");
      st_mskdelta370 = readrel400->getIndex(ord399, true);
      std::vector<u16> ord401({0, 1});
      slog::Relation* readrel402 = db->getRelation("st_msk_ans");
      st_msk_ansindex366 = readrel402->getIndex(ord401, false);
      std::vector<u16> ord403({1, 2, 0});
      slog::Relation* readrel404 = db->getRelation("st_del");
      st_delindex367 = readrel404->getIndex(ord403, false);
      std::vector<u16> ord405({1, 2, 0});
      slog::Relation* readrel406 = db->getRelation("st_del");
      st_deldelta371 = readrel406->getIndex(ord405, true);
      std::vector<u16> ord407({0, 1});
      slog::Relation* readrel408 = db->getRelation("st_del_ans");
      st_del_ansindex368 = readrel408->getIndex(ord407, false);
      std::vector<u16> ord409({0, 1});
      slog::Relation* readrel410 = db->getRelation("st_bld_ans");
      st_bld_ansindex369 = readrel410->getIndex(ord409, false);
  
    }
    ReadTask372(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c78 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c79 = _t[0];
        u64 v_c57 = _t[1];
        u64 v_c56 = _t[2];
        u64 v_c11 = _t[3];
        u64 v_c47 = _t[4];
        if (!slog::exists_probe<6,3>($sup9688x88x0x0x0index354, std::array<u64,6>{v_c57, v_c56, v_c47, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mskindex355, std::array<u64,3>{v_c56, 0, 0})) return;
        if (!slog::exists_probe<2,1>(st_msk_ansindex356, std::array<u64,2>{v_c57, 0})) return;
        if (!slog::exists_probe<2,1>(st_del_ansindex357, std::array<u64,2>{v_c11, 0})) return;
        if (!slog::exists_probe<2,1>(st_bld_ansindex358, std::array<u64,2>{v_c79, 0})) return;
        slog::join_probe<5,3>(pbranchindex359, std::array<u64,5>{v_c57, v_c56, v_c47, 0, 0}, [&](const std::array<u64,5>& m411) {
          u64 v_c80 = m411[3]; u64 v_c55 = m411[4];
          if (!slog::exists_probe<3,1>(st_delindex360, std::array<u64,3>{v_c80, 0, 0})) return;
          if (!slog::exists_probe<3,1>(st_delindex361, std::array<u64,3>{v_c55, 0, 0})) return;
          slog::join_probe<6,4>($sup9688x88x0x0x0index362, std::array<u64,6>{v_c57, v_c56, v_c47, v_c55, 0, 0}, [&](const std::array<u64,6>& m412) {
            u64 v_c81 = m412[4]; u64 v_c82 = m412[5];
            slog::join_probe<3,3>(st_delindex363, std::array<u64,3>{v_c81, v_c82, v_c80}, [&](const std::array<u64,3>& m413) {
              if (!slog::exists_probe<3,2>(st_delindex364, std::array<u64,3>{v_c55, v_c82, 0})) return;
              slog::join_probe_old<3,2>(st_mskindex365, st_mskdelta370, std::array<u64,3>{v_c82, v_c56, 0}, [&](const std::array<u64,3>& m414) {
                u64 v_c83 = m414[2];
                slog::join_probe<2,2>(st_msk_ansindex366, std::array<u64,2>{v_c83, v_c57}, [&](const std::array<u64,2>& m415) {
                  slog::join_probe_old<3,2>(st_delindex367, st_deldelta371, std::array<u64,3>{v_c55, v_c82, 0}, [&](const std::array<u64,3>& m416) {
                    u64 v_c84 = m416[2];
                    slog::join_probe<2,2>(st_del_ansindex368, std::array<u64,2>{v_c84, v_c11}, [&](const std::array<u64,2>& m417) {
                      slog::join_probe<2,1>(st_bld_ansindex369, std::array<u64,2>{v_c79, 0}, [&](const std::array<u64,2>& m418) {
                        u64 v_c85 = m418[1];
                        u64 v_c86 = _prim_band(db, v_c82, v_c56);
                        if (v_c86 == slog_error) { slog::emit_pending_error(db, "set.slog:89"); return; }
                        u64 v_c87 = _prim_lt(db, v_c86, v_c78);
                        if (v_c87 == slog_error) { slog::emit_pending_error(db, "set.slog:89"); return; }
                        if (!v_c87) return;
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c81, v_c85}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("set.slog:89", "delta:st_bld", _fires);
  
      if (!_done)
      {
        ReadTask372* _cont = new ReadTask372(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask372(db,b), false);
  // (crule (pre (let __tconst3lre272 const5feceb66ffc86f38d952786c)) (scan $sup9688x40x0x0x0 __d0 p0 p1 t0 t1) (body (join-old st_hsb_ans (0 1) 0 (0 1) __t9G4L271 __v0) (let __t26Ir270 (bxor p0 p1)) (join-old st_hsb (0 1) 2 (0 1) __t9G4L271 __t26Ir270) (let __t5swO273 (band p0 __v0)) (cmp gt __t5swO273 __tconst3lre272)) (head (emit $sup9688x40x0x0x1 (1 2 0 3 4 5 6) __t9G4L271 __v0 __d0 p0 p1 t0 t1)) set.slog:41 #f)
  class ReadTask424 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_hsb_ansindex420;  slog::Index** st_hsbindex421;  slog::Index** st_hsb_ansdelta422;  slog::Index** st_hsbdelta423;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x40x0x0x1");
      std::vector<u16> ord425({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel426 = db->getRelation("$sup9688x40x0x0x1");
      head_index[0] = readrel426->getIndex(ord425, false);
      outer_rel = db->getRelation("$sup9688x40x0x0x0");
      std::vector<u16> ord427({0, 1});
      slog::Relation* readrel428 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex420 = readrel428->getIndex(ord427, false);
      std::vector<u16> ord429({0, 1});
      slog::Relation* readrel430 = db->getRelation("st_hsb_ans");
      st_hsb_ansdelta422 = readrel430->getIndex(ord429, true);
      std::vector<u16> ord431({0, 1});
      slog::Relation* readrel432 = db->getRelation("st_hsb");
      st_hsbindex421 = readrel432->getIndex(ord431, false);
      std::vector<u16> ord433({0, 1});
      slog::Relation* readrel434 = db->getRelation("st_hsb");
      st_hsbdelta423 = readrel434->getIndex(ord433, true);
  
    }
    ReadTask424(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c88 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c64 = _t[0];
        u64 v_c4 = _t[1];
        u64 v_c12 = _t[2];
        u64 v_c13 = _t[3];
        u64 v_c14 = _t[4];
        slog::join_all_old<2>(st_hsb_ansindex420, st_hsb_ansdelta422, [&](const std::array<u64,2>& m435) {
          u64 v_c89 = m435[0]; u64 v_c11 = m435[1];
          u64 v_c90 = _prim_bxor(db, v_c4, v_c12);
          if (v_c90 == slog_error) { slog::emit_pending_error(db, "set.slog:41"); return; }
          slog::join_probe_old<2,2>(st_hsbindex421, st_hsbdelta423, std::array<u64,2>{v_c89, v_c90}, [&](const std::array<u64,2>& m436) {
            u64 v_c91 = _prim_band(db, v_c4, v_c11);
            if (v_c91 == slog_error) { slog::emit_pending_error(db, "set.slog:41"); return; }
            u64 v_c92 = _prim_gt(db, v_c91, v_c88);
            if (v_c92 == slog_error) { slog::emit_pending_error(db, "set.slog:41"); return; }
            if (!v_c92) return;
            ++_fires;
            slog::emit<7>(head_rel[0], head_index[0], newbatch[0], std::array<u64,7>{v_c89, v_c11, v_c64, v_c4, v_c12, v_c13, v_c14}, std::array<u16,7>{1, 2, 0, 3, 4, 5, 6});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:41", "delta:$sup9688x40x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask424* _cont = new ReadTask424(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask424(db,b), false);
  // (crule (pre (let __tconst63YF62 const6b86b273ff34fce19d6b804e)) (scan st_union_ans __t6dzp66 __v0) (body (join-old st_union (0 1 2) 1 (0 1 2) __t6dzp66 __t5Obr65 u) (exists pbranch (3 0 1 2 4) 1 u) (exists $sup9688x114x0x0x0 (7 0 1 2 3 4 5 6 8) 1 u) (exists $sup9688x114x0x0x1 (8 4 6 9 0 2 3 5 7 1) 1 u) (join-old st_union (1 2 0) 1 (1 2 0) __t5Obr65 __t2ifW59 __t2j0W61) (exists $sup9688x114x0x0x0 (0 7 1 2 3 4 5 6 8) 2 __t2j0W61 u) (exists $sup9688x114x0x0x1 (0 8 1 2 3 4 5 6 7 9) 2 __t2j0W61 u) (join-old pbranch (3 0 1 2 4) 2 (3 0 1 2 4) u __t2ifW59 q n v) (exists $sup9688x114x0x0x1 (8 4 6 9 0 2 3 5 7 1) 5 u n q v __t2j0W61) (exists st_msk (2 0 1) 1 n) (exists st_msk_ans (1 0) 1 q) (join-old $sup9688x114x0x0x0 (5 3 7 8 0 1 2 4 6) 5 (5 3 7 8 0 1 2 4 6) q n u v __t2j0W61 l m p r) (cmp lt m n) (exists pbranch (1 2 3 4 0) 5 p m l r __t5Obr65) (exists st_msk (1 2 0) 2 p n) (join-old $sup9688x114x0x0x1 (8 4 6 9 0 2 3 5 7 1) 9 (8 4 6 9 0 2 3 5 7 1) u n q v __t2j0W61 l m p r __t1Zy964) (join-old pbranch (1 2 3 4 0) 5 (1 2 3 4 0) p m l r __t5Obr65) (join-old st_msk (1 2 0) 3 (1 2 0) p n __t1Zy964) (join st_msk_ans (0 1) 2 __t1Zy964 q) (let __t3h5j63 (band p n)) (cmp lt __t3h5j63 __tconst63YF62)) (head (emit-temp temp1Dk71281 __t2j0W61 __v0 n q v) (mkstruct pbranch (1 2 3 4 0) __t0srE58 q n __v0 v)) set.slog:115 #f)
  class ReadTask463 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_unionindex438;  slog::Index** pbranchindex439;  slog::Index** $sup9688x114x0x0x0index440;  slog::Index** $sup9688x114x0x0x1index441;  slog::Index** st_unionindex442;  slog::Index** $sup9688x114x0x0x0index443;  slog::Index** $sup9688x114x0x0x1index444;  slog::Index** pbranchindex445;  slog::Index** $sup9688x114x0x0x1index446;  slog::Index** st_mskindex447;  slog::Index** st_msk_ansindex448;  slog::Index** $sup9688x114x0x0x0index449;  slog::Index** pbranchindex450;  slog::Index** st_mskindex451;  slog::Index** $sup9688x114x0x0x1index452;  slog::Index** pbranchindex453;  slog::Index** st_mskindex454;  slog::Index** st_msk_ansindex455;  slog::Index** st_uniondelta456;  slog::Index** st_uniondelta457;  slog::Index** pbranchdelta458;  slog::Index** $sup9688x114x0x0x0delta459;  slog::Index** $sup9688x114x0x0x1delta460;  slog::Index** pbranchdelta461;  slog::Index** st_mskdelta462;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp1Dk71281");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("st_union_ans");
      std::vector<u16> ord464({0, 1, 2});
      slog::Relation* readrel465 = db->getRelation("st_union");
      st_unionindex438 = readrel465->getIndex(ord464, false);
      std::vector<u16> ord466({0, 1, 2});
      slog::Relation* readrel467 = db->getRelation("st_union");
      st_uniondelta456 = readrel467->getIndex(ord466, true);
      std::vector<u16> ord468({3, 0, 1, 2, 4});
      slog::Relation* readrel469 = db->getRelation("pbranch");
      pbranchindex439 = readrel469->getIndex(ord468, false);
      std::vector<u16> ord470({7, 0, 1, 2, 3, 4, 5, 6, 8});
      slog::Relation* readrel471 = db->getRelation("$sup9688x114x0x0x0");
      $sup9688x114x0x0x0index440 = readrel471->getIndex(ord470, false);
      std::vector<u16> ord472({8, 4, 6, 9, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel473 = db->getRelation("$sup9688x114x0x0x1");
      $sup9688x114x0x0x1index441 = readrel473->getIndex(ord472, false);
      std::vector<u16> ord474({1, 2, 0});
      slog::Relation* readrel475 = db->getRelation("st_union");
      st_unionindex442 = readrel475->getIndex(ord474, false);
      std::vector<u16> ord476({1, 2, 0});
      slog::Relation* readrel477 = db->getRelation("st_union");
      st_uniondelta457 = readrel477->getIndex(ord476, true);
      std::vector<u16> ord478({0, 7, 1, 2, 3, 4, 5, 6, 8});
      slog::Relation* readrel479 = db->getRelation("$sup9688x114x0x0x0");
      $sup9688x114x0x0x0index443 = readrel479->getIndex(ord478, false);
      std::vector<u16> ord480({0, 8, 1, 2, 3, 4, 5, 6, 7, 9});
      slog::Relation* readrel481 = db->getRelation("$sup9688x114x0x0x1");
      $sup9688x114x0x0x1index444 = readrel481->getIndex(ord480, false);
      std::vector<u16> ord482({3, 0, 1, 2, 4});
      slog::Relation* readrel483 = db->getRelation("pbranch");
      pbranchindex445 = readrel483->getIndex(ord482, false);
      std::vector<u16> ord484({3, 0, 1, 2, 4});
      slog::Relation* readrel485 = db->getRelation("pbranch");
      pbranchdelta458 = readrel485->getIndex(ord484, true);
      std::vector<u16> ord486({8, 4, 6, 9, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel487 = db->getRelation("$sup9688x114x0x0x1");
      $sup9688x114x0x0x1index446 = readrel487->getIndex(ord486, false);
      std::vector<u16> ord488({2, 0, 1});
      slog::Relation* readrel489 = db->getRelation("st_msk");
      st_mskindex447 = readrel489->getIndex(ord488, false);
      std::vector<u16> ord490({1, 0});
      slog::Relation* readrel491 = db->getRelation("st_msk_ans");
      st_msk_ansindex448 = readrel491->getIndex(ord490, false);
      std::vector<u16> ord492({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel493 = db->getRelation("$sup9688x114x0x0x0");
      $sup9688x114x0x0x0index449 = readrel493->getIndex(ord492, false);
      std::vector<u16> ord494({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel495 = db->getRelation("$sup9688x114x0x0x0");
      $sup9688x114x0x0x0delta459 = readrel495->getIndex(ord494, true);
      std::vector<u16> ord496({1, 2, 3, 4, 0});
      slog::Relation* readrel497 = db->getRelation("pbranch");
      pbranchindex450 = readrel497->getIndex(ord496, false);
      std::vector<u16> ord498({1, 2, 0});
      slog::Relation* readrel499 = db->getRelation("st_msk");
      st_mskindex451 = readrel499->getIndex(ord498, false);
      std::vector<u16> ord500({8, 4, 6, 9, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel501 = db->getRelation("$sup9688x114x0x0x1");
      $sup9688x114x0x0x1index452 = readrel501->getIndex(ord500, false);
      std::vector<u16> ord502({8, 4, 6, 9, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel503 = db->getRelation("$sup9688x114x0x0x1");
      $sup9688x114x0x0x1delta460 = readrel503->getIndex(ord502, true);
      std::vector<u16> ord504({1, 2, 3, 4, 0});
      slog::Relation* readrel505 = db->getRelation("pbranch");
      pbranchindex453 = readrel505->getIndex(ord504, false);
      std::vector<u16> ord506({1, 2, 3, 4, 0});
      slog::Relation* readrel507 = db->getRelation("pbranch");
      pbranchdelta461 = readrel507->getIndex(ord506, true);
      std::vector<u16> ord508({1, 2, 0});
      slog::Relation* readrel509 = db->getRelation("st_msk");
      st_mskindex454 = readrel509->getIndex(ord508, false);
      std::vector<u16> ord510({1, 2, 0});
      slog::Relation* readrel511 = db->getRelation("st_msk");
      st_mskdelta462 = readrel511->getIndex(ord510, true);
      std::vector<u16> ord512({0, 1});
      slog::Relation* readrel513 = db->getRelation("st_msk_ans");
      st_msk_ansindex455 = readrel513->getIndex(ord512, false);
  
    }
    ReadTask463(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c48 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c11 = _t[1];
        slog::join_probe_old<3,1>(st_unionindex438, st_uniondelta456, std::array<u64,3>{v_c61, 0, 0}, [&](const std::array<u64,3>& m514) {
          u64 v_c60 = m514[1]; u64 v_c52 = m514[2];
          if (!slog::exists_probe<5,1>(pbranchindex439, std::array<u64,5>{v_c52, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<9,1>($sup9688x114x0x0x0index440, std::array<u64,9>{v_c52, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<10,1>($sup9688x114x0x0x1index441, std::array<u64,10>{v_c52, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          slog::join_probe_old<3,1>(st_unionindex442, st_uniondelta457, std::array<u64,3>{v_c60, 0, 0}, [&](const std::array<u64,3>& m515) {
            u64 v_c49 = m515[1]; u64 v_c54 = m515[2];
            if (!slog::exists_probe<9,2>($sup9688x114x0x0x0index443, std::array<u64,9>{v_c54, v_c52, 0, 0, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<10,2>($sup9688x114x0x0x1index444, std::array<u64,10>{v_c54, v_c52, 0, 0, 0, 0, 0, 0, 0, 0})) return;
            slog::join_probe_old<5,2>(pbranchindex445, pbranchdelta458, std::array<u64,5>{v_c52, v_c49, 0, 0, 0}, [&](const std::array<u64,5>& m516) {
              u64 v_c50 = m516[2]; u64 v_c51 = m516[3]; u64 v_c53 = m516[4];
              if (!slog::exists_probe<10,5>($sup9688x114x0x0x1index446, std::array<u64,10>{v_c52, v_c51, v_c50, v_c53, v_c54, 0, 0, 0, 0, 0})) return;
              if (!slog::exists_probe<3,1>(st_mskindex447, std::array<u64,3>{v_c51, 0, 0})) return;
              if (!slog::exists_probe<2,1>(st_msk_ansindex448, std::array<u64,2>{v_c50, 0})) return;
              slog::join_probe_old<9,5>($sup9688x114x0x0x0index449, $sup9688x114x0x0x0delta459, std::array<u64,9>{v_c50, v_c51, v_c52, v_c53, v_c54, 0, 0, 0, 0}, [&](const std::array<u64,9>& m517) {
                u64 v_c55 = m517[5]; u64 v_c56 = m517[6]; u64 v_c57 = m517[7]; u64 v_c47 = m517[8];
                u64 v_c93 = _prim_lt(db, v_c56, v_c51);
                if (v_c93 == slog_error) { slog::emit_pending_error(db, "set.slog:115"); return; }
                if (!v_c93) return;
                if (!slog::exists_probe<5,5>(pbranchindex450, std::array<u64,5>{v_c57, v_c56, v_c55, v_c47, v_c60})) return;
                if (!slog::exists_probe<3,2>(st_mskindex451, std::array<u64,3>{v_c57, v_c51, 0})) return;
                slog::join_probe_old<10,9>($sup9688x114x0x0x1index452, $sup9688x114x0x0x1delta460, std::array<u64,10>{v_c52, v_c51, v_c50, v_c53, v_c54, v_c55, v_c56, v_c57, v_c47, 0}, [&](const std::array<u64,10>& m519) {
                  u64 v_c59 = m519[9];
                  slog::join_probe_old<5,5>(pbranchindex453, pbranchdelta461, std::array<u64,5>{v_c57, v_c56, v_c55, v_c47, v_c60}, [&](const std::array<u64,5>& m520) {
                    slog::join_probe_old<3,3>(st_mskindex454, st_mskdelta462, std::array<u64,3>{v_c57, v_c51, v_c59}, [&](const std::array<u64,3>& m521) {
                      slog::join_probe<2,2>(st_msk_ansindex455, std::array<u64,2>{v_c59, v_c50}, [&](const std::array<u64,2>& m522) {
                        u64 v_c62 = _prim_band(db, v_c57, v_c51);
                        if (v_c62 == slog_error) { slog::emit_pending_error(db, "set.slog:115"); return; }
                        u64 v_c94 = _prim_lt(db, v_c62, v_c48);
                        if (v_c94 == slog_error) { slog::emit_pending_error(db, "set.slog:115"); return; }
                        if (!v_c94) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c54, v_c11, v_c51, v_c50, v_c53});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c50, v_c51, v_c11, v_c53}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:115", "delta:st_union_ans", _fires);
  
      if (!_done)
      {
        ReadTask463* _cont = new ReadTask463(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask463(db,b), false);
  // (crule (pre (let __tconst1v9F125 const5feceb66ffc86f38d952786c)) (scan st_msk __t3TTE127 p n) (body (exists $sup9688x117x0x0x0 (3 4 5 0 1 2 6 7 8) 2 n p) (exists pbranch (2 0 1 3 4) 1 n) (exists pbranch (1 2 3 4 0) 1 p) (exists st_msk_ans (0 1) 1 __t3TTE127) (join $sup9688x117x0x0x1 (1 4 5 6 0 2 3 7 8 9) 3 __t3TTE127 n p q __t0ttd124 l m r u v) (cmp lt m n) (join $sup9688x117x0x0x0 (5 3 7 8 0 1 2 4 6) 9 q n u v __t0ttd124 l m p r) (exists pbranch (1 2 3 4 0) 4 p m l r) (exists st_msk_ans (0 1) 2 __t3TTE127 q) (exists st_union (2 0 1) 1 v) (join pbranch (1 2 3 4 0) 4 q n u v __t43ng122) (exists st_union (2 0 1) 2 __t43ng122 __t0ttd124) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t32HA128) (join st_union (0 1 2) 3 __t0ttd124 __t32HA128 __t43ng122) (join st_msk_ans (0 1) 2 __t3TTE127 q) (join-old st_union (1 2 0) 2 (1 2 0) __t32HA128 v __t4LMh129) (join st_union_ans (0 1) 1 __t4LMh129 __v0) (let __t3tQC126 (band p n)) (cmp gt __t3tQC126 __tconst1v9F125)) (head (emit-temp temp4p811353 __t0ttd124 __v0 n q u) (mkstruct pbranch (1 2 3 4 0) __t6NgR121 q n u __v0)) set.slog:118 #f)
  class ReadTask542 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x117x0x0x0index524;  slog::Index** pbranchindex525;  slog::Index** pbranchindex526;  slog::Index** st_msk_ansindex527;  slog::Index** $sup9688x117x0x0x1index528;  slog::Index** $sup9688x117x0x0x0index529;  slog::Index** pbranchindex530;  slog::Index** st_msk_ansindex531;  slog::Index** st_unionindex532;  slog::Index** pbranchindex533;  slog::Index** st_unionindex534;  slog::Index** pbranchindex535;  slog::Index** st_unionindex536;  slog::Index** st_msk_ansindex537;  slog::Index** st_unionindex538;  slog::Index** st_union_ansindex539;  slog::Index** pbranchdelta540;  slog::Index** st_uniondelta541;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4p811353");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("st_msk");
      std::vector<u16> ord543({3, 4, 5, 0, 1, 2, 6, 7, 8});
      slog::Relation* readrel544 = db->getRelation("$sup9688x117x0x0x0");
      $sup9688x117x0x0x0index524 = readrel544->getIndex(ord543, false);
      std::vector<u16> ord545({2, 0, 1, 3, 4});
      slog::Relation* readrel546 = db->getRelation("pbranch");
      pbranchindex525 = readrel546->getIndex(ord545, false);
      std::vector<u16> ord547({1, 2, 3, 4, 0});
      slog::Relation* readrel548 = db->getRelation("pbranch");
      pbranchindex526 = readrel548->getIndex(ord547, false);
      std::vector<u16> ord549({0, 1});
      slog::Relation* readrel550 = db->getRelation("st_msk_ans");
      st_msk_ansindex527 = readrel550->getIndex(ord549, false);
      std::vector<u16> ord551({1, 4, 5, 6, 0, 2, 3, 7, 8, 9});
      slog::Relation* readrel552 = db->getRelation("$sup9688x117x0x0x1");
      $sup9688x117x0x0x1index528 = readrel552->getIndex(ord551, false);
      std::vector<u16> ord553({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel554 = db->getRelation("$sup9688x117x0x0x0");
      $sup9688x117x0x0x0index529 = readrel554->getIndex(ord553, false);
      std::vector<u16> ord555({1, 2, 3, 4, 0});
      slog::Relation* readrel556 = db->getRelation("pbranch");
      pbranchindex530 = readrel556->getIndex(ord555, false);
      std::vector<u16> ord557({0, 1});
      slog::Relation* readrel558 = db->getRelation("st_msk_ans");
      st_msk_ansindex531 = readrel558->getIndex(ord557, false);
      std::vector<u16> ord559({2, 0, 1});
      slog::Relation* readrel560 = db->getRelation("st_union");
      st_unionindex532 = readrel560->getIndex(ord559, false);
      std::vector<u16> ord561({1, 2, 3, 4, 0});
      slog::Relation* readrel562 = db->getRelation("pbranch");
      pbranchindex533 = readrel562->getIndex(ord561, false);
      std::vector<u16> ord563({2, 0, 1});
      slog::Relation* readrel564 = db->getRelation("st_union");
      st_unionindex534 = readrel564->getIndex(ord563, false);
      std::vector<u16> ord565({1, 2, 3, 4, 0});
      slog::Relation* readrel566 = db->getRelation("pbranch");
      pbranchindex535 = readrel566->getIndex(ord565, false);
      std::vector<u16> ord567({1, 2, 3, 4, 0});
      slog::Relation* readrel568 = db->getRelation("pbranch");
      pbranchdelta540 = readrel568->getIndex(ord567, true);
      std::vector<u16> ord569({0, 1, 2});
      slog::Relation* readrel570 = db->getRelation("st_union");
      st_unionindex536 = readrel570->getIndex(ord569, false);
      std::vector<u16> ord571({0, 1});
      slog::Relation* readrel572 = db->getRelation("st_msk_ans");
      st_msk_ansindex537 = readrel572->getIndex(ord571, false);
      std::vector<u16> ord573({1, 2, 0});
      slog::Relation* readrel574 = db->getRelation("st_union");
      st_unionindex538 = readrel574->getIndex(ord573, false);
      std::vector<u16> ord575({1, 2, 0});
      slog::Relation* readrel576 = db->getRelation("st_union");
      st_uniondelta541 = readrel576->getIndex(ord575, true);
      std::vector<u16> ord577({0, 1});
      slog::Relation* readrel578 = db->getRelation("st_union_ans");
      st_union_ansindex539 = readrel578->getIndex(ord577, false);
  
    }
    ReadTask542(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c95 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c96 = _t[0];
        u64 v_c57 = _t[1];
        u64 v_c51 = _t[2];
        if (!slog::exists_probe<9,2>($sup9688x117x0x0x0index524, std::array<u64,9>{v_c51, v_c57, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex525, std::array<u64,5>{v_c51, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex526, std::array<u64,5>{v_c57, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(st_msk_ansindex527, std::array<u64,2>{v_c96, 0})) return;
        slog::join_probe<10,3>($sup9688x117x0x0x1index528, std::array<u64,10>{v_c96, v_c51, v_c57, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,10>& m579) {
          u64 v_c50 = m579[3]; u64 v_c97 = m579[4]; u64 v_c55 = m579[5]; u64 v_c56 = m579[6]; u64 v_c47 = m579[7]; u64 v_c52 = m579[8]; u64 v_c53 = m579[9];
          u64 v_c98 = _prim_lt(db, v_c56, v_c51);
          if (v_c98 == slog_error) { slog::emit_pending_error(db, "set.slog:118"); return; }
          if (!v_c98) return;
          slog::join_probe<9,9>($sup9688x117x0x0x0index529, std::array<u64,9>{v_c50, v_c51, v_c52, v_c53, v_c97, v_c55, v_c56, v_c57, v_c47}, [&](const std::array<u64,9>& m581) {
            if (!slog::exists_probe<5,4>(pbranchindex530, std::array<u64,5>{v_c57, v_c56, v_c55, v_c47, 0})) return;
            if (!slog::exists_probe<2,2>(st_msk_ansindex531, std::array<u64,2>{v_c96, v_c50})) return;
            if (!slog::exists_probe<3,1>(st_unionindex532, std::array<u64,3>{v_c53, 0, 0})) return;
            slog::join_probe<5,4>(pbranchindex533, std::array<u64,5>{v_c50, v_c51, v_c52, v_c53, 0}, [&](const std::array<u64,5>& m582) {
              u64 v_c99 = m582[4];
              if (!slog::exists_probe<3,2>(st_unionindex534, std::array<u64,3>{v_c99, v_c97, 0})) return;
              slog::join_probe_old<5,4>(pbranchindex535, pbranchdelta540, std::array<u64,5>{v_c57, v_c56, v_c55, v_c47, 0}, [&](const std::array<u64,5>& m583) {
                u64 v_c100 = m583[4];
                slog::join_probe<3,3>(st_unionindex536, std::array<u64,3>{v_c97, v_c100, v_c99}, [&](const std::array<u64,3>& m584) {
                  slog::join_probe<2,2>(st_msk_ansindex537, std::array<u64,2>{v_c96, v_c50}, [&](const std::array<u64,2>& m585) {
                    slog::join_probe_old<3,2>(st_unionindex538, st_uniondelta541, std::array<u64,3>{v_c100, v_c53, 0}, [&](const std::array<u64,3>& m586) {
                      u64 v_c101 = m586[2];
                      slog::join_probe<2,1>(st_union_ansindex539, std::array<u64,2>{v_c101, 0}, [&](const std::array<u64,2>& m587) {
                        u64 v_c11 = m587[1];
                        u64 v_c102 = _prim_band(db, v_c57, v_c51);
                        if (v_c102 == slog_error) { slog::emit_pending_error(db, "set.slog:118"); return; }
                        u64 v_c103 = _prim_gt(db, v_c102, v_c95);
                        if (v_c103 == slog_error) { slog::emit_pending_error(db, "set.slog:118"); return; }
                        if (!v_c103) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c97, v_c11, v_c51, v_c50, v_c52});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c50, v_c51, v_c52, v_c11}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:118", "delta:st_msk", _fires);
  
      if (!_done)
      {
        ReadTask542* _cont = new ReadTask542(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask542(db,b), false);
  // (crule (pre (let __tconst19LZ687 conste3776bfed7f405de8017ecfa) (let __tconst6nio451 constef2d127de37b942baad06145) (let __tconst5Crw454 constd4735e3a265e16eee03f5971) (let __tconst7cMm457 const2c624232cdd221771294dfbb) (let __tconst776G459 const6b86b273ff34fce19d6b804e)) (probe st_ins (2 0 1) 1 __tconst5Crw454 __t7k0a456 __t82EP455) (body (join _enum (0 1) 2 __t82EP455 __tconst19LZ687) (exists st_ins (2 0 1) 1 __tconst7cMm457) (exists st_ins_ans (0 1) 1 __t7k0a456) (exists st_ins (2 0 1) 1 __tconst776G459) (join st_ins (1 2 0) 2 __t82EP455 __tconst6nio451 __t6TRN453) (join st_ins_ans (0 1) 1 __t6TRN453 __v0) (join-old st_ins (1 2 0) 2 (1 2 0) __v0 __tconst7cMm457 __t6eAo458) (exists st_ins_ans (0 1) 1 __t6eAo458) (join st_ins_ans (0 1) 1 __t7k0a456 __v1) (join-old st_ins (1 2 0) 2 (1 2 0) __v1 __tconst776G459 __t7DB2460) (exists st_ins_ans (0 1) 1 __t7DB2460) (join st_ins_ans (0 1) 1 __t6eAo458 a) (join st_ins_ans (0 1) 1 __t7DB2460 b)) (head (mkstruct st_union (1 2 0) __6Awq688 a b)) st_basic.slog:18 #f)
  class ReadTask604 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** _enumindex589;  slog::Index** st_insindex590;  slog::Index** st_ins_ansindex591;  slog::Index** st_insindex592;  slog::Index** st_insindex593;  slog::Index** st_ins_ansindex594;  slog::Index** st_insindex595;  slog::Index** st_ins_ansindex596;  slog::Index** st_ins_ansindex597;  slog::Index** st_insindex598;  slog::Index** st_ins_ansindex599;  slog::Index** st_ins_ansindex600;  slog::Index** st_ins_ansindex601;  slog::Index** st_insdelta602;  slog::Index** st_insdelta603;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_union");
      std::vector<u16> ord605({2, 0, 1});
      slog::Relation* readrel606 = db->getRelation("st_ins");
      driver_index = readrel606->getIndex(ord605, true);
      std::vector<u16> ord607({0, 1});
      slog::Relation* readrel608 = db->getRelation("_enum");
      _enumindex589 = readrel608->getIndex(ord607, false);
      std::vector<u16> ord609({2, 0, 1});
      slog::Relation* readrel610 = db->getRelation("st_ins");
      st_insindex590 = readrel610->getIndex(ord609, false);
      std::vector<u16> ord611({0, 1});
      slog::Relation* readrel612 = db->getRelation("st_ins_ans");
      st_ins_ansindex591 = readrel612->getIndex(ord611, false);
      std::vector<u16> ord613({2, 0, 1});
      slog::Relation* readrel614 = db->getRelation("st_ins");
      st_insindex592 = readrel614->getIndex(ord613, false);
      std::vector<u16> ord615({1, 2, 0});
      slog::Relation* readrel616 = db->getRelation("st_ins");
      st_insindex593 = readrel616->getIndex(ord615, false);
      std::vector<u16> ord617({0, 1});
      slog::Relation* readrel618 = db->getRelation("st_ins_ans");
      st_ins_ansindex594 = readrel618->getIndex(ord617, false);
      std::vector<u16> ord619({1, 2, 0});
      slog::Relation* readrel620 = db->getRelation("st_ins");
      st_insindex595 = readrel620->getIndex(ord619, false);
      std::vector<u16> ord621({1, 2, 0});
      slog::Relation* readrel622 = db->getRelation("st_ins");
      st_insdelta602 = readrel622->getIndex(ord621, true);
      std::vector<u16> ord623({0, 1});
      slog::Relation* readrel624 = db->getRelation("st_ins_ans");
      st_ins_ansindex596 = readrel624->getIndex(ord623, false);
      std::vector<u16> ord625({0, 1});
      slog::Relation* readrel626 = db->getRelation("st_ins_ans");
      st_ins_ansindex597 = readrel626->getIndex(ord625, false);
      std::vector<u16> ord627({1, 2, 0});
      slog::Relation* readrel628 = db->getRelation("st_ins");
      st_insindex598 = readrel628->getIndex(ord627, false);
      std::vector<u16> ord629({1, 2, 0});
      slog::Relation* readrel630 = db->getRelation("st_ins");
      st_insdelta603 = readrel630->getIndex(ord629, true);
      std::vector<u16> ord631({0, 1});
      slog::Relation* readrel632 = db->getRelation("st_ins_ans");
      st_ins_ansindex599 = readrel632->getIndex(ord631, false);
      std::vector<u16> ord633({0, 1});
      slog::Relation* readrel634 = db->getRelation("st_ins_ans");
      st_ins_ansindex600 = readrel634->getIndex(ord633, false);
      std::vector<u16> ord635({0, 1});
      slog::Relation* readrel636 = db->getRelation("st_ins_ans");
      st_ins_ansindex601 = readrel636->getIndex(ord635, false);
  
    }
    ReadTask604(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c104 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c105 = v_constef2d127de37b942baad06145;
      u64 v_c106 = v_constd4735e3a265e16eee03f5971;
      u64 v_c107 = v_const2c624232cdd221771294dfbb;
      u64 v_c108 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c106, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m637) {
        u64 v_c109 = m637[1];
        u64 v_c110 = m637[2];
        if (buckethash(v_c109) != bucket) return;
        slog::join_probe<2,2>(_enumindex589, std::array<u64,2>{v_c110, v_c104}, [&](const std::array<u64,2>& m638) {
          if (!slog::exists_probe<3,1>(st_insindex590, std::array<u64,3>{v_c107, 0, 0})) return;
          if (!slog::exists_probe<2,1>(st_ins_ansindex591, std::array<u64,2>{v_c109, 0})) return;
          if (!slog::exists_probe<3,1>(st_insindex592, std::array<u64,3>{v_c108, 0, 0})) return;
          slog::join_probe<3,2>(st_insindex593, std::array<u64,3>{v_c110, v_c105, 0}, [&](const std::array<u64,3>& m639) {
            u64 v_c111 = m639[2];
            slog::join_probe<2,1>(st_ins_ansindex594, std::array<u64,2>{v_c111, 0}, [&](const std::array<u64,2>& m640) {
              u64 v_c11 = m640[1];
              slog::join_probe_old<3,2>(st_insindex595, st_insdelta602, std::array<u64,3>{v_c11, v_c107, 0}, [&](const std::array<u64,3>& m641) {
                u64 v_c112 = m641[2];
                if (!slog::exists_probe<2,1>(st_ins_ansindex596, std::array<u64,2>{v_c112, 0})) return;
                slog::join_probe<2,1>(st_ins_ansindex597, std::array<u64,2>{v_c109, 0}, [&](const std::array<u64,2>& m642) {
                  u64 v_c5 = m642[1];
                  slog::join_probe_old<3,2>(st_insindex598, st_insdelta603, std::array<u64,3>{v_c5, v_c108, 0}, [&](const std::array<u64,3>& m643) {
                    u64 v_c113 = m643[2];
                    if (!slog::exists_probe<2,1>(st_ins_ansindex599, std::array<u64,2>{v_c113, 0})) return;
                    slog::join_probe<2,1>(st_ins_ansindex600, std::array<u64,2>{v_c112, 0}, [&](const std::array<u64,2>& m644) {
                      u64 v_c43 = m644[1];
                      slog::join_probe<2,1>(st_ins_ansindex601, std::array<u64,2>{v_c113, 0}, [&](const std::array<u64,2>& m645) {
                        u64 v_c45 = m645[1];
                        ++_fires;
                        slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c43, v_c45}, std::array<u16,3>{1, 2, 0});
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
        ReadTask604* _cont = new ReadTask604(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask604(db,b), false);
  // (crule (pre (let __tconst6xBD941 conste3776bfed7f405de8017ecfa) (let __tconst6e9n32 const5feceb66ffc86f38d952786c)) (scan st_mem0 __t17fB34 __t6lrD33 k) (body (join _enum (0 1) 2 __t6lrD33 __tconst6xBD941)) (head (emit st_mem0_ans (0 1) __t17fB34 __tconst6e9n32)) set.slog:67 #f)
  class ReadTask647 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex646;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_mem0_ans");
      std::vector<u16> ord648({0, 1});
      slog::Relation* readrel649 = db->getRelation("st_mem0_ans");
      head_index[0] = readrel649->getIndex(ord648, false);
      outer_rel = db->getRelation("st_mem0");
      std::vector<u16> ord650({0, 1});
      slog::Relation* readrel651 = db->getRelation("_enum");
      _enumindex646 = readrel651->getIndex(ord650, false);
  
    }
    ReadTask647(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c114 = v_conste3776bfed7f405de8017ecfa;
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
        u64 v_c117 = _t[1];
        u64 v_c82 = _t[2];
        slog::join_probe<2,2>(_enumindex646, std::array<u64,2>{v_c117, v_c114}, [&](const std::array<u64,2>& m652) {
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c116, v_c115}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:67", "delta:st_mem0", _fires);
  
      if (!_done)
      {
        ReadTask647* _cont = new ReadTask647(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask647(db,b), false);
  // (crule (pre (let __tconst1v9F125 const5feceb66ffc86f38d952786c)) (scan pbranch __t43ng122 q n u v) (body (exists $sup9688x117x0x0x1 (9 4 6 8 0 2 3 5 7 1) 4 v n q u) (exists st_union (2 0 1) 1 __t43ng122) (exists st_msk (2 0 1) 1 n) (exists st_msk_ans (1 0) 1 q) (exists st_union (2 0 1) 1 v) (join $sup9688x117x0x0x0 (5 3 7 8 0 1 2 4 6) 4 q n u v __t0ttd124 l m p r) (cmp lt m n) (exists pbranch (1 2 3 4 0) 4 p m l r) (exists st_union (2 0 1) 2 __t43ng122 __t0ttd124) (exists st_msk (1 2 0) 2 p n) (join $sup9688x117x0x0x1 (9 4 6 8 0 2 3 5 7 1) 9 v n q u __t0ttd124 l m p r __t3TTE127) (exists st_msk (1 2 0) 3 p n __t3TTE127) (exists st_msk_ans (0 1) 2 __t3TTE127 q) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t32HA128) (join-old st_union (0 1 2) 3 (0 1 2) __t0ttd124 __t32HA128 __t43ng122) (join-old st_msk (1 2 0) 3 (1 2 0) p n __t3TTE127) (join st_msk_ans (0 1) 2 __t3TTE127 q) (join-old st_union (1 2 0) 2 (1 2 0) __t32HA128 v __t4LMh129) (join st_union_ans (0 1) 1 __t4LMh129 __v0) (let __t3tQC126 (band p n)) (cmp gt __t3tQC126 __tconst1v9F125)) (head (emit-temp temp4p811353 __t0ttd124 __v0 n q u) (mkstruct pbranch (1 2 3 4 0) __t6NgR121 q n u __v0)) set.slog:118 #f)
  class ReadTask675 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x117x0x0x1index653;  slog::Index** st_unionindex654;  slog::Index** st_mskindex655;  slog::Index** st_msk_ansindex656;  slog::Index** st_unionindex657;  slog::Index** $sup9688x117x0x0x0index658;  slog::Index** pbranchindex659;  slog::Index** st_unionindex660;  slog::Index** st_mskindex661;  slog::Index** $sup9688x117x0x0x1index662;  slog::Index** st_mskindex663;  slog::Index** st_msk_ansindex664;  slog::Index** pbranchindex665;  slog::Index** st_unionindex666;  slog::Index** st_mskindex667;  slog::Index** st_msk_ansindex668;  slog::Index** st_unionindex669;  slog::Index** st_union_ansindex670;  slog::Index** pbranchdelta671;  slog::Index** st_uniondelta672;  slog::Index** st_mskdelta673;  slog::Index** st_uniondelta674;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4p811353");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord676({9, 4, 6, 8, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel677 = db->getRelation("$sup9688x117x0x0x1");
      $sup9688x117x0x0x1index653 = readrel677->getIndex(ord676, false);
      std::vector<u16> ord678({2, 0, 1});
      slog::Relation* readrel679 = db->getRelation("st_union");
      st_unionindex654 = readrel679->getIndex(ord678, false);
      std::vector<u16> ord680({2, 0, 1});
      slog::Relation* readrel681 = db->getRelation("st_msk");
      st_mskindex655 = readrel681->getIndex(ord680, false);
      std::vector<u16> ord682({1, 0});
      slog::Relation* readrel683 = db->getRelation("st_msk_ans");
      st_msk_ansindex656 = readrel683->getIndex(ord682, false);
      std::vector<u16> ord684({2, 0, 1});
      slog::Relation* readrel685 = db->getRelation("st_union");
      st_unionindex657 = readrel685->getIndex(ord684, false);
      std::vector<u16> ord686({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel687 = db->getRelation("$sup9688x117x0x0x0");
      $sup9688x117x0x0x0index658 = readrel687->getIndex(ord686, false);
      std::vector<u16> ord688({1, 2, 3, 4, 0});
      slog::Relation* readrel689 = db->getRelation("pbranch");
      pbranchindex659 = readrel689->getIndex(ord688, false);
      std::vector<u16> ord690({2, 0, 1});
      slog::Relation* readrel691 = db->getRelation("st_union");
      st_unionindex660 = readrel691->getIndex(ord690, false);
      std::vector<u16> ord692({1, 2, 0});
      slog::Relation* readrel693 = db->getRelation("st_msk");
      st_mskindex661 = readrel693->getIndex(ord692, false);
      std::vector<u16> ord694({9, 4, 6, 8, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel695 = db->getRelation("$sup9688x117x0x0x1");
      $sup9688x117x0x0x1index662 = readrel695->getIndex(ord694, false);
      std::vector<u16> ord696({1, 2, 0});
      slog::Relation* readrel697 = db->getRelation("st_msk");
      st_mskindex663 = readrel697->getIndex(ord696, false);
      std::vector<u16> ord698({0, 1});
      slog::Relation* readrel699 = db->getRelation("st_msk_ans");
      st_msk_ansindex664 = readrel699->getIndex(ord698, false);
      std::vector<u16> ord700({1, 2, 3, 4, 0});
      slog::Relation* readrel701 = db->getRelation("pbranch");
      pbranchindex665 = readrel701->getIndex(ord700, false);
      std::vector<u16> ord702({1, 2, 3, 4, 0});
      slog::Relation* readrel703 = db->getRelation("pbranch");
      pbranchdelta671 = readrel703->getIndex(ord702, true);
      std::vector<u16> ord704({0, 1, 2});
      slog::Relation* readrel705 = db->getRelation("st_union");
      st_unionindex666 = readrel705->getIndex(ord704, false);
      std::vector<u16> ord706({0, 1, 2});
      slog::Relation* readrel707 = db->getRelation("st_union");
      st_uniondelta672 = readrel707->getIndex(ord706, true);
      std::vector<u16> ord708({1, 2, 0});
      slog::Relation* readrel709 = db->getRelation("st_msk");
      st_mskindex667 = readrel709->getIndex(ord708, false);
      std::vector<u16> ord710({1, 2, 0});
      slog::Relation* readrel711 = db->getRelation("st_msk");
      st_mskdelta673 = readrel711->getIndex(ord710, true);
      std::vector<u16> ord712({0, 1});
      slog::Relation* readrel713 = db->getRelation("st_msk_ans");
      st_msk_ansindex668 = readrel713->getIndex(ord712, false);
      std::vector<u16> ord714({1, 2, 0});
      slog::Relation* readrel715 = db->getRelation("st_union");
      st_unionindex669 = readrel715->getIndex(ord714, false);
      std::vector<u16> ord716({1, 2, 0});
      slog::Relation* readrel717 = db->getRelation("st_union");
      st_uniondelta674 = readrel717->getIndex(ord716, true);
      std::vector<u16> ord718({0, 1});
      slog::Relation* readrel719 = db->getRelation("st_union_ans");
      st_union_ansindex670 = readrel719->getIndex(ord718, false);
  
    }
    ReadTask675(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c95 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c50 = _t[1];
        u64 v_c51 = _t[2];
        u64 v_c52 = _t[3];
        u64 v_c53 = _t[4];
        if (!slog::exists_probe<10,4>($sup9688x117x0x0x1index653, std::array<u64,10>{v_c53, v_c51, v_c50, v_c52, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_unionindex654, std::array<u64,3>{v_c99, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mskindex655, std::array<u64,3>{v_c51, 0, 0})) return;
        if (!slog::exists_probe<2,1>(st_msk_ansindex656, std::array<u64,2>{v_c50, 0})) return;
        if (!slog::exists_probe<3,1>(st_unionindex657, std::array<u64,3>{v_c53, 0, 0})) return;
        slog::join_probe<9,4>($sup9688x117x0x0x0index658, std::array<u64,9>{v_c50, v_c51, v_c52, v_c53, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m720) {
          u64 v_c97 = m720[4]; u64 v_c55 = m720[5]; u64 v_c56 = m720[6]; u64 v_c57 = m720[7]; u64 v_c47 = m720[8];
          u64 v_c118 = _prim_lt(db, v_c56, v_c51);
          if (v_c118 == slog_error) { slog::emit_pending_error(db, "set.slog:118"); return; }
          if (!v_c118) return;
          if (!slog::exists_probe<5,4>(pbranchindex659, std::array<u64,5>{v_c57, v_c56, v_c55, v_c47, 0})) return;
          if (!slog::exists_probe<3,2>(st_unionindex660, std::array<u64,3>{v_c99, v_c97, 0})) return;
          if (!slog::exists_probe<3,2>(st_mskindex661, std::array<u64,3>{v_c57, v_c51, 0})) return;
          slog::join_probe<10,9>($sup9688x117x0x0x1index662, std::array<u64,10>{v_c53, v_c51, v_c50, v_c52, v_c97, v_c55, v_c56, v_c57, v_c47, 0}, [&](const std::array<u64,10>& m722) {
            u64 v_c96 = m722[9];
            if (!slog::exists_probe<3,3>(st_mskindex663, std::array<u64,3>{v_c57, v_c51, v_c96})) return;
            if (!slog::exists_probe<2,2>(st_msk_ansindex664, std::array<u64,2>{v_c96, v_c50})) return;
            slog::join_probe_old<5,4>(pbranchindex665, pbranchdelta671, std::array<u64,5>{v_c57, v_c56, v_c55, v_c47, 0}, [&](const std::array<u64,5>& m723) {
              u64 v_c100 = m723[4];
              slog::join_probe_old<3,3>(st_unionindex666, st_uniondelta672, std::array<u64,3>{v_c97, v_c100, v_c99}, [&](const std::array<u64,3>& m724) {
                slog::join_probe_old<3,3>(st_mskindex667, st_mskdelta673, std::array<u64,3>{v_c57, v_c51, v_c96}, [&](const std::array<u64,3>& m725) {
                  slog::join_probe<2,2>(st_msk_ansindex668, std::array<u64,2>{v_c96, v_c50}, [&](const std::array<u64,2>& m726) {
                    slog::join_probe_old<3,2>(st_unionindex669, st_uniondelta674, std::array<u64,3>{v_c100, v_c53, 0}, [&](const std::array<u64,3>& m727) {
                      u64 v_c101 = m727[2];
                      slog::join_probe<2,1>(st_union_ansindex670, std::array<u64,2>{v_c101, 0}, [&](const std::array<u64,2>& m728) {
                        u64 v_c11 = m728[1];
                        u64 v_c102 = _prim_band(db, v_c57, v_c51);
                        if (v_c102 == slog_error) { slog::emit_pending_error(db, "set.slog:118"); return; }
                        u64 v_c119 = _prim_gt(db, v_c102, v_c95);
                        if (v_c119 == slog_error) { slog::emit_pending_error(db, "set.slog:118"); return; }
                        if (!v_c119) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c97, v_c11, v_c51, v_c50, v_c52});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c50, v_c51, v_c52, v_c11}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:118", "delta:pbranch", _fires);
  
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
  // (crule (pre (let __tconst37os885 conste3776bfed7f405de8017ecfa) (let __tconst7vMT166 constef2d127de37b942baad06145)) (probe _enum (1 0) 1 __tconst37os885 __t9vbF167) (body) (head (mkstruct st_ins (1 2 0) __4Ju8884 __t9vbF167 __tconst7vMT166)) st_basic.slog:18 #f)
  class ReadTask730 : public slog::Task
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
      head_rel[0] = db->getRelation("st_ins");
      std::vector<u16> ord731({1, 0});
      slog::Relation* readrel732 = db->getRelation("_enum");
      driver_index = readrel732->getIndex(ord731, true);
  
    }
    ReadTask730(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c120 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c121 = v_constef2d127de37b942baad06145;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c120, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m733) {
        u64 v_c122 = m733[1];
        if (buckethash(v_c122) != bucket) return;
        ++_fires;
        slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c122, v_c121}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("st_basic.slog:18", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask730* _cont = new ReadTask730(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask730(db,b), true);
  // (crule (pre) (scan st_union __t2Q3U288 __t1pUK287 __t22FG286) (body (exists $sup9688x100x0x0x0 (0 1 2 3 4 5 6) 1 __t2Q3U288) (join pbranch (0 1 2 3 4) 1 __t22FG286 p m u v) (exists pbranch (0 1 2 3 4) 3 __t1pUK287 p m) (exists st_union (2 0 1) 1 u) (exists st_union (2 0 1) 1 v) (join $sup9688x100x0x0x0 (2 3 5 6 0 1 4) 5 m p u v __t2Q3U288 l r) (join pbranch (1 2 3 4 0) 5 p m l r __t1pUK287) (exists st_union (1 2 0) 2 r v) (join-old st_union (1 2 0) 2 (1 2 0) l u __t1gnX289) (exists st_union_ans (0 1) 1 __t1gnX289) (join-old st_union (1 2 0) 2 (1 2 0) r v __t8LsM290) (exists st_union_ans (0 1) 1 __t8LsM290) (join st_union_ans (0 1) 1 __t1gnX289 __v0) (join st_union_ans (0 1) 1 __t8LsM290 __v1)) (head (emit-temp temp6bMv1274 __t2Q3U288 __v0 __v1 m p) (mkstruct pbranch (1 2 3 4 0) __t6nPF285 p m __v0 __v1)) set.slog:101 #f)
  class ReadTask750 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x100x0x0x0index734;  slog::Index** pbranchindex735;  slog::Index** pbranchindex736;  slog::Index** st_unionindex737;  slog::Index** st_unionindex738;  slog::Index** $sup9688x100x0x0x0index739;  slog::Index** pbranchindex740;  slog::Index** st_unionindex741;  slog::Index** st_unionindex742;  slog::Index** st_union_ansindex743;  slog::Index** st_unionindex744;  slog::Index** st_union_ansindex745;  slog::Index** st_union_ansindex746;  slog::Index** st_union_ansindex747;  slog::Index** st_uniondelta748;  slog::Index** st_uniondelta749;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp6bMv1274");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("st_union");
      std::vector<u16> ord751({0, 1, 2, 3, 4, 5, 6});
      slog::Relation* readrel752 = db->getRelation("$sup9688x100x0x0x0");
      $sup9688x100x0x0x0index734 = readrel752->getIndex(ord751, false);
      std::vector<u16> ord753({0, 1, 2, 3, 4});
      slog::Relation* readrel754 = db->getRelation("pbranch");
      pbranchindex735 = readrel754->getIndex(ord753, false);
      std::vector<u16> ord755({0, 1, 2, 3, 4});
      slog::Relation* readrel756 = db->getRelation("pbranch");
      pbranchindex736 = readrel756->getIndex(ord755, false);
      std::vector<u16> ord757({2, 0, 1});
      slog::Relation* readrel758 = db->getRelation("st_union");
      st_unionindex737 = readrel758->getIndex(ord757, false);
      std::vector<u16> ord759({2, 0, 1});
      slog::Relation* readrel760 = db->getRelation("st_union");
      st_unionindex738 = readrel760->getIndex(ord759, false);
      std::vector<u16> ord761({2, 3, 5, 6, 0, 1, 4});
      slog::Relation* readrel762 = db->getRelation("$sup9688x100x0x0x0");
      $sup9688x100x0x0x0index739 = readrel762->getIndex(ord761, false);
      std::vector<u16> ord763({1, 2, 3, 4, 0});
      slog::Relation* readrel764 = db->getRelation("pbranch");
      pbranchindex740 = readrel764->getIndex(ord763, false);
      std::vector<u16> ord765({1, 2, 0});
      slog::Relation* readrel766 = db->getRelation("st_union");
      st_unionindex741 = readrel766->getIndex(ord765, false);
      std::vector<u16> ord767({1, 2, 0});
      slog::Relation* readrel768 = db->getRelation("st_union");
      st_unionindex742 = readrel768->getIndex(ord767, false);
      std::vector<u16> ord769({1, 2, 0});
      slog::Relation* readrel770 = db->getRelation("st_union");
      st_uniondelta748 = readrel770->getIndex(ord769, true);
      std::vector<u16> ord771({0, 1});
      slog::Relation* readrel772 = db->getRelation("st_union_ans");
      st_union_ansindex743 = readrel772->getIndex(ord771, false);
      std::vector<u16> ord773({1, 2, 0});
      slog::Relation* readrel774 = db->getRelation("st_union");
      st_unionindex744 = readrel774->getIndex(ord773, false);
      std::vector<u16> ord775({1, 2, 0});
      slog::Relation* readrel776 = db->getRelation("st_union");
      st_uniondelta749 = readrel776->getIndex(ord775, true);
      std::vector<u16> ord777({0, 1});
      slog::Relation* readrel778 = db->getRelation("st_union_ans");
      st_union_ansindex745 = readrel778->getIndex(ord777, false);
      std::vector<u16> ord779({0, 1});
      slog::Relation* readrel780 = db->getRelation("st_union_ans");
      st_union_ansindex746 = readrel780->getIndex(ord779, false);
      std::vector<u16> ord781({0, 1});
      slog::Relation* readrel782 = db->getRelation("st_union_ans");
      st_union_ansindex747 = readrel782->getIndex(ord781, false);
  
    }
    ReadTask750(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c123 = _t[0];
        u64 v_c124 = _t[1];
        u64 v_c125 = _t[2];
        if (!slog::exists_probe<7,1>($sup9688x100x0x0x0index734, std::array<u64,7>{v_c123, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe<5,1>(pbranchindex735, std::array<u64,5>{v_c125, 0, 0, 0, 0}, [&](const std::array<u64,5>& m783) {
          u64 v_c57 = m783[1]; u64 v_c56 = m783[2]; u64 v_c52 = m783[3]; u64 v_c53 = m783[4];
          if (!slog::exists_probe<5,3>(pbranchindex736, std::array<u64,5>{v_c124, v_c57, v_c56, 0, 0})) return;
          if (!slog::exists_probe<3,1>(st_unionindex737, std::array<u64,3>{v_c52, 0, 0})) return;
          if (!slog::exists_probe<3,1>(st_unionindex738, std::array<u64,3>{v_c53, 0, 0})) return;
          slog::join_probe<7,5>($sup9688x100x0x0x0index739, std::array<u64,7>{v_c56, v_c57, v_c52, v_c53, v_c123, 0, 0}, [&](const std::array<u64,7>& m784) {
            u64 v_c55 = m784[5]; u64 v_c47 = m784[6];
            slog::join_probe<5,5>(pbranchindex740, std::array<u64,5>{v_c57, v_c56, v_c55, v_c47, v_c124}, [&](const std::array<u64,5>& m785) {
              if (!slog::exists_probe<3,2>(st_unionindex741, std::array<u64,3>{v_c47, v_c53, 0})) return;
              slog::join_probe_old<3,2>(st_unionindex742, st_uniondelta748, std::array<u64,3>{v_c55, v_c52, 0}, [&](const std::array<u64,3>& m786) {
                u64 v_c126 = m786[2];
                if (!slog::exists_probe<2,1>(st_union_ansindex743, std::array<u64,2>{v_c126, 0})) return;
                slog::join_probe_old<3,2>(st_unionindex744, st_uniondelta749, std::array<u64,3>{v_c47, v_c53, 0}, [&](const std::array<u64,3>& m787) {
                  u64 v_c127 = m787[2];
                  if (!slog::exists_probe<2,1>(st_union_ansindex745, std::array<u64,2>{v_c127, 0})) return;
                  slog::join_probe<2,1>(st_union_ansindex746, std::array<u64,2>{v_c126, 0}, [&](const std::array<u64,2>& m788) {
                    u64 v_c11 = m788[1];
                    slog::join_probe<2,1>(st_union_ansindex747, std::array<u64,2>{v_c127, 0}, [&](const std::array<u64,2>& m789) {
                      u64 v_c5 = m789[1];
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c123, v_c11, v_c5, v_c56, v_c57});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c57, v_c56, v_c11, v_c5}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:101", "delta:st_union", _fires);
  
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
  // (crule (pre) (scan st_del __t8BXn276 s k) (body (exists pleaf (1 0) 1 k) (exists st_diff (1 2 0) 1 s) (join st_del_ans (0 1) 1 __t8BXn276 r) (join pleaf (1 0) 1 k __t5fUY274) (join st_diff (1 2 0) 2 s __t5fUY274 __t6ID7275)) (head (emit st_diff_ans (0 1) __t6ID7275 r)) set.slog:133 #f)
  class ReadTask795 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pleafindex790;  slog::Index** st_diffindex791;  slog::Index** st_del_ansindex792;  slog::Index** pleafindex793;  slog::Index** st_diffindex794;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord796({0, 1});
      slog::Relation* readrel797 = db->getRelation("st_diff_ans");
      head_index[0] = readrel797->getIndex(ord796, false);
      outer_rel = db->getRelation("st_del");
      std::vector<u16> ord798({1, 0});
      slog::Relation* readrel799 = db->getRelation("pleaf");
      pleafindex790 = readrel799->getIndex(ord798, false);
      std::vector<u16> ord800({1, 2, 0});
      slog::Relation* readrel801 = db->getRelation("st_diff");
      st_diffindex791 = readrel801->getIndex(ord800, false);
      std::vector<u16> ord802({0, 1});
      slog::Relation* readrel803 = db->getRelation("st_del_ans");
      st_del_ansindex792 = readrel803->getIndex(ord802, false);
      std::vector<u16> ord804({1, 0});
      slog::Relation* readrel805 = db->getRelation("pleaf");
      pleafindex793 = readrel805->getIndex(ord804, false);
      std::vector<u16> ord806({1, 2, 0});
      slog::Relation* readrel807 = db->getRelation("st_diff");
      st_diffindex794 = readrel807->getIndex(ord806, false);
  
    }
    ReadTask795(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c82 = _t[2];
        if (!slog::exists_probe<2,1>(pleafindex790, std::array<u64,2>{v_c82, 0})) return;
        if (!slog::exists_probe<3,1>(st_diffindex791, std::array<u64,3>{v_c129, 0, 0})) return;
        slog::join_probe<2,1>(st_del_ansindex792, std::array<u64,2>{v_c128, 0}, [&](const std::array<u64,2>& m808) {
          u64 v_c47 = m808[1];
          slog::join_probe<2,1>(pleafindex793, std::array<u64,2>{v_c82, 0}, [&](const std::array<u64,2>& m809) {
            u64 v_c130 = m809[1];
            slog::join_probe<3,2>(st_diffindex794, std::array<u64,3>{v_c129, v_c130, 0}, [&](const std::array<u64,3>& m810) {
              u64 v_c131 = m810[2];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c131, v_c47}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:133", "delta:st_del", _fires);
  
      if (!_done)
      {
        ReadTask795* _cont = new ReadTask795(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask795(db,b), false);
  // (crule (pre (let __tconst1v9F125 const5feceb66ffc86f38d952786c)) (scan $sup9688x117x0x0x1 __t0ttd124 __t3TTE127 l m n p q r u v) (body (cmp lt m n) (join $sup9688x117x0x0x0 (5 3 7 8 0 1 2 4 6) 9 q n u v __t0ttd124 l m p r) (exists pbranch (1 2 3 4 0) 4 p m l r) (exists st_msk (1 2 0) 3 p n __t3TTE127) (exists st_msk_ans (0 1) 2 __t3TTE127 q) (exists st_union (2 0 1) 1 v) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t43ng122) (exists st_union (2 0 1) 2 __t43ng122 __t0ttd124) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t32HA128) (join-old st_union (0 1 2) 3 (0 1 2) __t0ttd124 __t32HA128 __t43ng122) (join-old st_msk (1 2 0) 3 (1 2 0) p n __t3TTE127) (join st_msk_ans (0 1) 2 __t3TTE127 q) (join-old st_union (1 2 0) 2 (1 2 0) __t32HA128 v __t4LMh129) (join st_union_ans (0 1) 1 __t4LMh129 __v0) (let __t3tQC126 (band p n)) (cmp gt __t3tQC126 __tconst1v9F125)) (head (emit-temp temp4p811353 __t0ttd124 __v0 n q u) (mkstruct pbranch (1 2 3 4 0) __t6NgR121 q n u __v0)) set.slog:118 #f)
  class ReadTask829 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x117x0x0x0index811;  slog::Index** pbranchindex812;  slog::Index** st_mskindex813;  slog::Index** st_msk_ansindex814;  slog::Index** st_unionindex815;  slog::Index** pbranchindex816;  slog::Index** st_unionindex817;  slog::Index** pbranchindex818;  slog::Index** st_unionindex819;  slog::Index** st_mskindex820;  slog::Index** st_msk_ansindex821;  slog::Index** st_unionindex822;  slog::Index** st_union_ansindex823;  slog::Index** pbranchdelta824;  slog::Index** pbranchdelta825;  slog::Index** st_uniondelta826;  slog::Index** st_mskdelta827;  slog::Index** st_uniondelta828;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4p811353");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("$sup9688x117x0x0x1");
      std::vector<u16> ord830({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel831 = db->getRelation("$sup9688x117x0x0x0");
      $sup9688x117x0x0x0index811 = readrel831->getIndex(ord830, false);
      std::vector<u16> ord832({1, 2, 3, 4, 0});
      slog::Relation* readrel833 = db->getRelation("pbranch");
      pbranchindex812 = readrel833->getIndex(ord832, false);
      std::vector<u16> ord834({1, 2, 0});
      slog::Relation* readrel835 = db->getRelation("st_msk");
      st_mskindex813 = readrel835->getIndex(ord834, false);
      std::vector<u16> ord836({0, 1});
      slog::Relation* readrel837 = db->getRelation("st_msk_ans");
      st_msk_ansindex814 = readrel837->getIndex(ord836, false);
      std::vector<u16> ord838({2, 0, 1});
      slog::Relation* readrel839 = db->getRelation("st_union");
      st_unionindex815 = readrel839->getIndex(ord838, false);
      std::vector<u16> ord840({1, 2, 3, 4, 0});
      slog::Relation* readrel841 = db->getRelation("pbranch");
      pbranchindex816 = readrel841->getIndex(ord840, false);
      std::vector<u16> ord842({1, 2, 3, 4, 0});
      slog::Relation* readrel843 = db->getRelation("pbranch");
      pbranchdelta824 = readrel843->getIndex(ord842, true);
      std::vector<u16> ord844({2, 0, 1});
      slog::Relation* readrel845 = db->getRelation("st_union");
      st_unionindex817 = readrel845->getIndex(ord844, false);
      std::vector<u16> ord846({1, 2, 3, 4, 0});
      slog::Relation* readrel847 = db->getRelation("pbranch");
      pbranchindex818 = readrel847->getIndex(ord846, false);
      std::vector<u16> ord848({1, 2, 3, 4, 0});
      slog::Relation* readrel849 = db->getRelation("pbranch");
      pbranchdelta825 = readrel849->getIndex(ord848, true);
      std::vector<u16> ord850({0, 1, 2});
      slog::Relation* readrel851 = db->getRelation("st_union");
      st_unionindex819 = readrel851->getIndex(ord850, false);
      std::vector<u16> ord852({0, 1, 2});
      slog::Relation* readrel853 = db->getRelation("st_union");
      st_uniondelta826 = readrel853->getIndex(ord852, true);
      std::vector<u16> ord854({1, 2, 0});
      slog::Relation* readrel855 = db->getRelation("st_msk");
      st_mskindex820 = readrel855->getIndex(ord854, false);
      std::vector<u16> ord856({1, 2, 0});
      slog::Relation* readrel857 = db->getRelation("st_msk");
      st_mskdelta827 = readrel857->getIndex(ord856, true);
      std::vector<u16> ord858({0, 1});
      slog::Relation* readrel859 = db->getRelation("st_msk_ans");
      st_msk_ansindex821 = readrel859->getIndex(ord858, false);
      std::vector<u16> ord860({1, 2, 0});
      slog::Relation* readrel861 = db->getRelation("st_union");
      st_unionindex822 = readrel861->getIndex(ord860, false);
      std::vector<u16> ord862({1, 2, 0});
      slog::Relation* readrel863 = db->getRelation("st_union");
      st_uniondelta828 = readrel863->getIndex(ord862, true);
      std::vector<u16> ord864({0, 1});
      slog::Relation* readrel865 = db->getRelation("st_union_ans");
      st_union_ansindex823 = readrel865->getIndex(ord864, false);
  
    }
    ReadTask829(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c95 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c97 = _t[0];
        u64 v_c96 = _t[1];
        u64 v_c55 = _t[2];
        u64 v_c56 = _t[3];
        u64 v_c51 = _t[4];
        u64 v_c57 = _t[5];
        u64 v_c50 = _t[6];
        u64 v_c47 = _t[7];
        u64 v_c52 = _t[8];
        u64 v_c53 = _t[9];
        u64 v_c132 = _prim_lt(db, v_c56, v_c51);
        if (v_c132 == slog_error) { slog::emit_pending_error(db, "set.slog:118"); return; }
        if (!v_c132) return;
        slog::join_probe<9,9>($sup9688x117x0x0x0index811, std::array<u64,9>{v_c50, v_c51, v_c52, v_c53, v_c97, v_c55, v_c56, v_c57, v_c47}, [&](const std::array<u64,9>& m867) {
          if (!slog::exists_probe<5,4>(pbranchindex812, std::array<u64,5>{v_c57, v_c56, v_c55, v_c47, 0})) return;
          if (!slog::exists_probe<3,3>(st_mskindex813, std::array<u64,3>{v_c57, v_c51, v_c96})) return;
          if (!slog::exists_probe<2,2>(st_msk_ansindex814, std::array<u64,2>{v_c96, v_c50})) return;
          if (!slog::exists_probe<3,1>(st_unionindex815, std::array<u64,3>{v_c53, 0, 0})) return;
          slog::join_probe_old<5,4>(pbranchindex816, pbranchdelta824, std::array<u64,5>{v_c50, v_c51, v_c52, v_c53, 0}, [&](const std::array<u64,5>& m868) {
            u64 v_c99 = m868[4];
            if (!slog::exists_probe<3,2>(st_unionindex817, std::array<u64,3>{v_c99, v_c97, 0})) return;
            slog::join_probe_old<5,4>(pbranchindex818, pbranchdelta825, std::array<u64,5>{v_c57, v_c56, v_c55, v_c47, 0}, [&](const std::array<u64,5>& m869) {
              u64 v_c100 = m869[4];
              slog::join_probe_old<3,3>(st_unionindex819, st_uniondelta826, std::array<u64,3>{v_c97, v_c100, v_c99}, [&](const std::array<u64,3>& m870) {
                slog::join_probe_old<3,3>(st_mskindex820, st_mskdelta827, std::array<u64,3>{v_c57, v_c51, v_c96}, [&](const std::array<u64,3>& m871) {
                  slog::join_probe<2,2>(st_msk_ansindex821, std::array<u64,2>{v_c96, v_c50}, [&](const std::array<u64,2>& m872) {
                    slog::join_probe_old<3,2>(st_unionindex822, st_uniondelta828, std::array<u64,3>{v_c100, v_c53, 0}, [&](const std::array<u64,3>& m873) {
                      u64 v_c101 = m873[2];
                      slog::join_probe<2,1>(st_union_ansindex823, std::array<u64,2>{v_c101, 0}, [&](const std::array<u64,2>& m874) {
                        u64 v_c11 = m874[1];
                        u64 v_c102 = _prim_band(db, v_c57, v_c51);
                        if (v_c102 == slog_error) { slog::emit_pending_error(db, "set.slog:118"); return; }
                        u64 v_c133 = _prim_gt(db, v_c102, v_c95);
                        if (v_c133 == slog_error) { slog::emit_pending_error(db, "set.slog:118"); return; }
                        if (!v_c133) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c97, v_c11, v_c51, v_c50, v_c52});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c50, v_c51, v_c52, v_c11}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:118", "delta:$sup9688x117x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask829* _cont = new ReadTask829(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask829(db,b), false);
  // (crule (pre) (scan temp3LID1346 l m p r u) (body (join pbranch (1 2 3 4 0) 4 p m l r __t16OH277)) (head (mkstruct st_diff (1 2 0) __3NDk955 __t16OH277 u)) set.slog:149 #f)
  class ReadTask877 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex876;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff");
      outer_rel = db->getRelation("temp3LID1346");
      std::vector<u16> ord878({1, 2, 3, 4, 0});
      slog::Relation* readrel879 = db->getRelation("pbranch");
      pbranchindex876 = readrel879->getIndex(ord878, false);
  
    }
    ReadTask877(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c56 = _t[1];
        u64 v_c57 = _t[2];
        u64 v_c47 = _t[3];
        u64 v_c52 = _t[4];
        slog::join_probe<5,4>(pbranchindex876, std::array<u64,5>{v_c57, v_c56, v_c55, v_c47, 0}, [&](const std::array<u64,5>& m880) {
          u64 v_c134 = m880[4];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c134, v_c52}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:149", "delta:temp3LID1346", _fires);
  
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
  // (crule (pre (let __tconst7ZkP346 const5feceb66ffc86f38d952786c)) (scan st_union __t4u97350 r __t0LeB349) (body (exists st_union (2 0 1) 1 __t0LeB349) (exists pbranch (4 0 1 2 3) 1 r) (exists $sup9688x106x0x0x0 (6 0 1 2 3 4 5 7 8) 1 r) (exists $sup9688x106x0x0x1 (7 2 3 5 0 4 6 8 9 1) 1 r) (join st_union_ans (0 1) 1 __t4u97350 __v0) (join st_union (2 0 1) 1 __t0LeB349 __t7KDg345 __t4ii6344) (exists $sup9688x106x0x0x0 (0 6 1 2 3 4 5 7 8) 2 __t7KDg345 r) (exists $sup9688x106x0x0x1 (0 7 1 2 3 4 5 6 8 9) 2 __t7KDg345 r) (join pbranch (4 0 1 2 3) 2 r __t4ii6344 p m l) (exists $sup9688x106x0x0x1 (7 2 3 5 0 4 6 8 9 1) 5 r l m p __t7KDg345) (exists st_msk (2 0 1) 1 m) (exists st_msk_ans (1 0) 1 p) (join $sup9688x106x0x0x0 (4 1 2 6 0 3 5 7 8) 5 p l m r __t7KDg345 n q u v) (cmp lt n m) (exists pbranch (1 2 3 4 0) 5 q n u v __t0LeB349) (exists st_msk (1 2 0) 2 q m) (join $sup9688x106x0x0x1 (7 2 3 5 0 4 6 8 9 1) 9 r l m p __t7KDg345 n q u v __t0gfm348) (join pbranch (1 2 3 4 0) 5 q n u v __t0LeB349) (join st_msk (1 2 0) 3 q m __t0gfm348) (join st_msk_ans (0 1) 2 __t0gfm348 p) (let __t9euC347 (band q m)) (cmp gt __t9euC347 __tconst7ZkP346)) (head (emit-temp temp3Stv1345 __t7KDg345 __v0 l m p) (mkstruct pbranch (1 2 3 4 0) __t0u8a342 p m l __v0)) set.slog:107 #f)
  class ReadTask900 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_unionindex881;  slog::Index** pbranchindex882;  slog::Index** $sup9688x106x0x0x0index883;  slog::Index** $sup9688x106x0x0x1index884;  slog::Index** st_union_ansindex885;  slog::Index** st_unionindex886;  slog::Index** $sup9688x106x0x0x0index887;  slog::Index** $sup9688x106x0x0x1index888;  slog::Index** pbranchindex889;  slog::Index** $sup9688x106x0x0x1index890;  slog::Index** st_mskindex891;  slog::Index** st_msk_ansindex892;  slog::Index** $sup9688x106x0x0x0index893;  slog::Index** pbranchindex894;  slog::Index** st_mskindex895;  slog::Index** $sup9688x106x0x0x1index896;  slog::Index** pbranchindex897;  slog::Index** st_mskindex898;  slog::Index** st_msk_ansindex899;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3Stv1345");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("st_union");
      std::vector<u16> ord901({2, 0, 1});
      slog::Relation* readrel902 = db->getRelation("st_union");
      st_unionindex881 = readrel902->getIndex(ord901, false);
      std::vector<u16> ord903({4, 0, 1, 2, 3});
      slog::Relation* readrel904 = db->getRelation("pbranch");
      pbranchindex882 = readrel904->getIndex(ord903, false);
      std::vector<u16> ord905({6, 0, 1, 2, 3, 4, 5, 7, 8});
      slog::Relation* readrel906 = db->getRelation("$sup9688x106x0x0x0");
      $sup9688x106x0x0x0index883 = readrel906->getIndex(ord905, false);
      std::vector<u16> ord907({7, 2, 3, 5, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel908 = db->getRelation("$sup9688x106x0x0x1");
      $sup9688x106x0x0x1index884 = readrel908->getIndex(ord907, false);
      std::vector<u16> ord909({0, 1});
      slog::Relation* readrel910 = db->getRelation("st_union_ans");
      st_union_ansindex885 = readrel910->getIndex(ord909, false);
      std::vector<u16> ord911({2, 0, 1});
      slog::Relation* readrel912 = db->getRelation("st_union");
      st_unionindex886 = readrel912->getIndex(ord911, false);
      std::vector<u16> ord913({0, 6, 1, 2, 3, 4, 5, 7, 8});
      slog::Relation* readrel914 = db->getRelation("$sup9688x106x0x0x0");
      $sup9688x106x0x0x0index887 = readrel914->getIndex(ord913, false);
      std::vector<u16> ord915({0, 7, 1, 2, 3, 4, 5, 6, 8, 9});
      slog::Relation* readrel916 = db->getRelation("$sup9688x106x0x0x1");
      $sup9688x106x0x0x1index888 = readrel916->getIndex(ord915, false);
      std::vector<u16> ord917({4, 0, 1, 2, 3});
      slog::Relation* readrel918 = db->getRelation("pbranch");
      pbranchindex889 = readrel918->getIndex(ord917, false);
      std::vector<u16> ord919({7, 2, 3, 5, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel920 = db->getRelation("$sup9688x106x0x0x1");
      $sup9688x106x0x0x1index890 = readrel920->getIndex(ord919, false);
      std::vector<u16> ord921({2, 0, 1});
      slog::Relation* readrel922 = db->getRelation("st_msk");
      st_mskindex891 = readrel922->getIndex(ord921, false);
      std::vector<u16> ord923({1, 0});
      slog::Relation* readrel924 = db->getRelation("st_msk_ans");
      st_msk_ansindex892 = readrel924->getIndex(ord923, false);
      std::vector<u16> ord925({4, 1, 2, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel926 = db->getRelation("$sup9688x106x0x0x0");
      $sup9688x106x0x0x0index893 = readrel926->getIndex(ord925, false);
      std::vector<u16> ord927({1, 2, 3, 4, 0});
      slog::Relation* readrel928 = db->getRelation("pbranch");
      pbranchindex894 = readrel928->getIndex(ord927, false);
      std::vector<u16> ord929({1, 2, 0});
      slog::Relation* readrel930 = db->getRelation("st_msk");
      st_mskindex895 = readrel930->getIndex(ord929, false);
      std::vector<u16> ord931({7, 2, 3, 5, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel932 = db->getRelation("$sup9688x106x0x0x1");
      $sup9688x106x0x0x1index896 = readrel932->getIndex(ord931, false);
      std::vector<u16> ord933({1, 2, 3, 4, 0});
      slog::Relation* readrel934 = db->getRelation("pbranch");
      pbranchindex897 = readrel934->getIndex(ord933, false);
      std::vector<u16> ord935({1, 2, 0});
      slog::Relation* readrel936 = db->getRelation("st_msk");
      st_mskindex898 = readrel936->getIndex(ord935, false);
      std::vector<u16> ord937({0, 1});
      slog::Relation* readrel938 = db->getRelation("st_msk_ans");
      st_msk_ansindex899 = readrel938->getIndex(ord937, false);
  
    }
    ReadTask900(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c135 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c136 = _t[0];
        u64 v_c47 = _t[1];
        u64 v_c137 = _t[2];
        if (!slog::exists_probe<3,1>(st_unionindex881, std::array<u64,3>{v_c137, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex882, std::array<u64,5>{v_c47, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<9,1>($sup9688x106x0x0x0index883, std::array<u64,9>{v_c47, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<10,1>($sup9688x106x0x0x1index884, std::array<u64,10>{v_c47, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(st_union_ansindex885, std::array<u64,2>{v_c136, 0}, [&](const std::array<u64,2>& m939) {
          u64 v_c11 = m939[1];
          slog::join_probe<3,1>(st_unionindex886, std::array<u64,3>{v_c137, 0, 0}, [&](const std::array<u64,3>& m940) {
            u64 v_c138 = m940[1]; u64 v_c139 = m940[2];
            if (!slog::exists_probe<9,2>($sup9688x106x0x0x0index887, std::array<u64,9>{v_c138, v_c47, 0, 0, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<10,2>($sup9688x106x0x0x1index888, std::array<u64,10>{v_c138, v_c47, 0, 0, 0, 0, 0, 0, 0, 0})) return;
            slog::join_probe<5,2>(pbranchindex889, std::array<u64,5>{v_c47, v_c139, 0, 0, 0}, [&](const std::array<u64,5>& m941) {
              u64 v_c57 = m941[2]; u64 v_c56 = m941[3]; u64 v_c55 = m941[4];
              if (!slog::exists_probe<10,5>($sup9688x106x0x0x1index890, std::array<u64,10>{v_c47, v_c55, v_c56, v_c57, v_c138, 0, 0, 0, 0, 0})) return;
              if (!slog::exists_probe<3,1>(st_mskindex891, std::array<u64,3>{v_c56, 0, 0})) return;
              if (!slog::exists_probe<2,1>(st_msk_ansindex892, std::array<u64,2>{v_c57, 0})) return;
              slog::join_probe<9,5>($sup9688x106x0x0x0index893, std::array<u64,9>{v_c57, v_c55, v_c56, v_c47, v_c138, 0, 0, 0, 0}, [&](const std::array<u64,9>& m942) {
                u64 v_c51 = m942[5]; u64 v_c50 = m942[6]; u64 v_c52 = m942[7]; u64 v_c53 = m942[8];
                u64 v_c140 = _prim_lt(db, v_c51, v_c56);
                if (v_c140 == slog_error) { slog::emit_pending_error(db, "set.slog:107"); return; }
                if (!v_c140) return;
                if (!slog::exists_probe<5,5>(pbranchindex894, std::array<u64,5>{v_c50, v_c51, v_c52, v_c53, v_c137})) return;
                if (!slog::exists_probe<3,2>(st_mskindex895, std::array<u64,3>{v_c50, v_c56, 0})) return;
                slog::join_probe<10,9>($sup9688x106x0x0x1index896, std::array<u64,10>{v_c47, v_c55, v_c56, v_c57, v_c138, v_c51, v_c50, v_c52, v_c53, 0}, [&](const std::array<u64,10>& m944) {
                  u64 v_c141 = m944[9];
                  slog::join_probe<5,5>(pbranchindex897, std::array<u64,5>{v_c50, v_c51, v_c52, v_c53, v_c137}, [&](const std::array<u64,5>& m945) {
                    slog::join_probe<3,3>(st_mskindex898, std::array<u64,3>{v_c50, v_c56, v_c141}, [&](const std::array<u64,3>& m946) {
                      slog::join_probe<2,2>(st_msk_ansindex899, std::array<u64,2>{v_c141, v_c57}, [&](const std::array<u64,2>& m947) {
                        u64 v_c142 = _prim_band(db, v_c50, v_c56);
                        if (v_c142 == slog_error) { slog::emit_pending_error(db, "set.slog:107"); return; }
                        u64 v_c143 = _prim_gt(db, v_c142, v_c135);
                        if (v_c143 == slog_error) { slog::emit_pending_error(db, "set.slog:107"); return; }
                        if (!v_c143) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c138, v_c11, v_c55, v_c56, v_c57});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c57, v_c56, v_c55, v_c11}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:107", "delta:st_union", _fires);
  
      if (!_done)
      {
        ReadTask900* _cont = new ReadTask900(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask900(db,b), false);
  // (crule (pre (let __tconst5qiO758 conste3776bfed7f405de8017ecfa) (let __tconst5MZ7439 constef2d127de37b942baad06145) (let __tconst7dws442 constd4735e3a265e16eee03f5971) (let __tconst4Zv7438 const2c624232cdd221771294dfbb)) (scan st_ins_ans __t1gci441 __v0) (body (exists _enum (1 0) 1 __tconst5qiO758) (exists st_ins (2 0 1) 1 __tconst7dws442) (join-old st_ins (0 2 1) 2 (0 2 1) __t1gci441 __tconst5MZ7439 __t8JV0443) (join _enum (0 1) 2 __t8JV0443 __tconst5qiO758) (join-old st_ins (1 2 0) 2 (1 2 0) __t8JV0443 __tconst7dws442 __t1qxx444) (join-old st_ins_ans (0 1) 1 (0 1) __t1qxx444 __v1)) (head (mkstruct st_ins (1 2 0) __0kE5759 __v0 __tconst4Zv7438)) st_basic.slog:18 #f)
  class ReadTask958 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex949;  slog::Index** st_insindex950;  slog::Index** st_insindex951;  slog::Index** _enumindex952;  slog::Index** st_insindex953;  slog::Index** st_ins_ansindex954;  slog::Index** st_insdelta955;  slog::Index** st_insdelta956;  slog::Index** st_ins_ansdelta957;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_ins");
      outer_rel = db->getRelation("st_ins_ans");
      std::vector<u16> ord959({1, 0});
      slog::Relation* readrel960 = db->getRelation("_enum");
      _enumindex949 = readrel960->getIndex(ord959, false);
      std::vector<u16> ord961({2, 0, 1});
      slog::Relation* readrel962 = db->getRelation("st_ins");
      st_insindex950 = readrel962->getIndex(ord961, false);
      std::vector<u16> ord963({0, 2, 1});
      slog::Relation* readrel964 = db->getRelation("st_ins");
      st_insindex951 = readrel964->getIndex(ord963, false);
      std::vector<u16> ord965({0, 2, 1});
      slog::Relation* readrel966 = db->getRelation("st_ins");
      st_insdelta955 = readrel966->getIndex(ord965, true);
      std::vector<u16> ord967({0, 1});
      slog::Relation* readrel968 = db->getRelation("_enum");
      _enumindex952 = readrel968->getIndex(ord967, false);
      std::vector<u16> ord969({1, 2, 0});
      slog::Relation* readrel970 = db->getRelation("st_ins");
      st_insindex953 = readrel970->getIndex(ord969, false);
      std::vector<u16> ord971({1, 2, 0});
      slog::Relation* readrel972 = db->getRelation("st_ins");
      st_insdelta956 = readrel972->getIndex(ord971, true);
      std::vector<u16> ord973({0, 1});
      slog::Relation* readrel974 = db->getRelation("st_ins_ans");
      st_ins_ansindex954 = readrel974->getIndex(ord973, false);
      std::vector<u16> ord975({0, 1});
      slog::Relation* readrel976 = db->getRelation("st_ins_ans");
      st_ins_ansdelta957 = readrel976->getIndex(ord975, true);
  
    }
    ReadTask958(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c144 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c145 = v_constef2d127de37b942baad06145;
      u64 v_c146 = v_constd4735e3a265e16eee03f5971;
      u64 v_c147 = v_const2c624232cdd221771294dfbb;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c148 = _t[0];
        u64 v_c11 = _t[1];
        if (!slog::exists_probe<2,1>(_enumindex949, std::array<u64,2>{v_c144, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex950, std::array<u64,3>{v_c146, 0, 0})) return;
        slog::join_probe_old<3,2>(st_insindex951, st_insdelta955, std::array<u64,3>{v_c148, v_c145, 0}, [&](const std::array<u64,3>& m977) {
          u64 v_c149 = m977[2];
          slog::join_probe<2,2>(_enumindex952, std::array<u64,2>{v_c149, v_c144}, [&](const std::array<u64,2>& m978) {
            slog::join_probe_old<3,2>(st_insindex953, st_insdelta956, std::array<u64,3>{v_c149, v_c146, 0}, [&](const std::array<u64,3>& m979) {
              u64 v_c150 = m979[2];
              slog::join_probe_old<2,1>(st_ins_ansindex954, st_ins_ansdelta957, std::array<u64,2>{v_c150, 0}, [&](const std::array<u64,2>& m980) {
                u64 v_c5 = m980[1];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c11, v_c147}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("st_basic.slog:18", "delta:st_ins_ans", _fires);
  
      if (!_done)
      {
        ReadTask958* _cont = new ReadTask958(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask958(db,b), false);
  // (crule (pre (let __tconst3lre272 const5feceb66ffc86f38d952786c)) (scan st_hsb_ans __t9G4L271 __v0) (body (join-old st_hsb (0 1) 1 (0 1) __t9G4L271 __t26Ir270) (join $sup9688x40x0x0x0 (1 0 2 3 4) 0 p0 __d0 p1 t0 t1) (let __t5swO273 (band p0 __v0)) (cmp gt __t5swO273 __tconst3lre272) (let chk0z301348 (bxor p0 p1)) (eq __t26Ir270 chk0z301348)) (head (emit $sup9688x40x0x0x1 (1 2 0 3 4 5 6) __t9G4L271 __v0 __d0 p0 p1 t0 t1)) set.slog:41 #f)
  class ReadTask984 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_hsbindex981;  slog::Index** $sup9688x40x0x0x0index982;  slog::Index** st_hsbdelta983;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x40x0x0x1");
      std::vector<u16> ord985({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel986 = db->getRelation("$sup9688x40x0x0x1");
      head_index[0] = readrel986->getIndex(ord985, false);
      outer_rel = db->getRelation("st_hsb_ans");
      std::vector<u16> ord987({0, 1});
      slog::Relation* readrel988 = db->getRelation("st_hsb");
      st_hsbindex981 = readrel988->getIndex(ord987, false);
      std::vector<u16> ord989({0, 1});
      slog::Relation* readrel990 = db->getRelation("st_hsb");
      st_hsbdelta983 = readrel990->getIndex(ord989, true);
      std::vector<u16> ord991({1, 0, 2, 3, 4});
      slog::Relation* readrel992 = db->getRelation("$sup9688x40x0x0x0");
      $sup9688x40x0x0x0index982 = readrel992->getIndex(ord991, false);
  
    }
    ReadTask984(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c88 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c89 = _t[0];
        u64 v_c11 = _t[1];
        slog::join_probe_old<2,1>(st_hsbindex981, st_hsbdelta983, std::array<u64,2>{v_c89, 0}, [&](const std::array<u64,2>& m993) {
          u64 v_c90 = m993[1];
          slog::join_all<5>($sup9688x40x0x0x0index982, [&](const std::array<u64,5>& m994) {
            u64 v_c4 = m994[0]; u64 v_c64 = m994[1]; u64 v_c12 = m994[2]; u64 v_c13 = m994[3]; u64 v_c14 = m994[4];
            u64 v_c91 = _prim_band(db, v_c4, v_c11);
            if (v_c91 == slog_error) { slog::emit_pending_error(db, "set.slog:41"); return; }
            u64 v_c151 = _prim_gt(db, v_c91, v_c88);
            if (v_c151 == slog_error) { slog::emit_pending_error(db, "set.slog:41"); return; }
            if (!v_c151) return;
            u64 v_c152 = _prim_bxor(db, v_c4, v_c12);
            if (v_c152 == slog_error) { slog::emit_pending_error(db, "set.slog:41"); return; }
            if (v_c90 != v_c152) return;
            ++_fires;
            slog::emit<7>(head_rel[0], head_index[0], newbatch[0], std::array<u64,7>{v_c89, v_c11, v_c64, v_c4, v_c12, v_c13, v_c14}, std::array<u16,7>{1, 2, 0, 3, 4, 5, 6});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:41", "delta:st_hsb_ans", _fires);
  
      if (!_done)
      {
        ReadTask984* _cont = new ReadTask984(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask984(db,b), false);
  // (crule (pre) (scan st_msk __t3Qtm239 p n) (body (exists pbranch (1 2 3 4 0) 1 p) (exists $sup9688x120x0x0x0 (3 4 0 1 2 5 6 7 8 9 10) 2 n p) (exists pbranch (2 0 1 3 4) 1 n) (exists st_join (1 2 3 4 0) 1 p) (join st_msk_ans (0 1) 1 __t3Qtm239 __v0) (join pbranch (1 2 3 4 0) 1 p m l r __t7ZZP236) (cmp lt m n) (exists st_join (1 2 3 4 0) 2 p __t7ZZP236) (exists st_union (1 2 0) 1 __t7ZZP236) (join $sup9688x120x0x0x0 (1 2 4 6 7 3 0 5 8 9 10) 6 l m p r __t7ZZP236 n __t3tZ8235 q __t8STz237 u v) (neq q __v0) (join pbranch (1 2 3 4 0) 5 q n u v __t8STz237) (exists st_union (0 1 2) 3 __t3tZ8235 __t7ZZP236 __t8STz237) (join st_join (1 2 3 4 0) 4 p __t7ZZP236 q __t8STz237 __t1ZYa238) (join st_union (0 1 2) 3 __t3tZ8235 __t7ZZP236 __t8STz237) (join st_join_ans (0 1) 1 __t1ZYa238 res)) (head (emit st_union_ans (0 1) __t3tZ8235 res)) set.slog:121 #f)
  class ReadTask1010 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex996;  slog::Index** $sup9688x120x0x0x0index997;  slog::Index** pbranchindex998;  slog::Index** st_joinindex999;  slog::Index** st_msk_ansindex1000;  slog::Index** pbranchindex1001;  slog::Index** st_joinindex1002;  slog::Index** st_unionindex1003;  slog::Index** $sup9688x120x0x0x0index1004;  slog::Index** pbranchindex1005;  slog::Index** st_unionindex1006;  slog::Index** st_joinindex1007;  slog::Index** st_unionindex1008;  slog::Index** st_join_ansindex1009;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_union_ans");
      std::vector<u16> ord1011({0, 1});
      slog::Relation* readrel1012 = db->getRelation("st_union_ans");
      head_index[0] = readrel1012->getIndex(ord1011, false);
      outer_rel = db->getRelation("st_msk");
      std::vector<u16> ord1013({1, 2, 3, 4, 0});
      slog::Relation* readrel1014 = db->getRelation("pbranch");
      pbranchindex996 = readrel1014->getIndex(ord1013, false);
      std::vector<u16> ord1015({3, 4, 0, 1, 2, 5, 6, 7, 8, 9, 10});
      slog::Relation* readrel1016 = db->getRelation("$sup9688x120x0x0x0");
      $sup9688x120x0x0x0index997 = readrel1016->getIndex(ord1015, false);
      std::vector<u16> ord1017({2, 0, 1, 3, 4});
      slog::Relation* readrel1018 = db->getRelation("pbranch");
      pbranchindex998 = readrel1018->getIndex(ord1017, false);
      std::vector<u16> ord1019({1, 2, 3, 4, 0});
      slog::Relation* readrel1020 = db->getRelation("st_join");
      st_joinindex999 = readrel1020->getIndex(ord1019, false);
      std::vector<u16> ord1021({0, 1});
      slog::Relation* readrel1022 = db->getRelation("st_msk_ans");
      st_msk_ansindex1000 = readrel1022->getIndex(ord1021, false);
      std::vector<u16> ord1023({1, 2, 3, 4, 0});
      slog::Relation* readrel1024 = db->getRelation("pbranch");
      pbranchindex1001 = readrel1024->getIndex(ord1023, false);
      std::vector<u16> ord1025({1, 2, 3, 4, 0});
      slog::Relation* readrel1026 = db->getRelation("st_join");
      st_joinindex1002 = readrel1026->getIndex(ord1025, false);
      std::vector<u16> ord1027({1, 2, 0});
      slog::Relation* readrel1028 = db->getRelation("st_union");
      st_unionindex1003 = readrel1028->getIndex(ord1027, false);
      std::vector<u16> ord1029({1, 2, 4, 6, 7, 3, 0, 5, 8, 9, 10});
      slog::Relation* readrel1030 = db->getRelation("$sup9688x120x0x0x0");
      $sup9688x120x0x0x0index1004 = readrel1030->getIndex(ord1029, false);
      std::vector<u16> ord1031({1, 2, 3, 4, 0});
      slog::Relation* readrel1032 = db->getRelation("pbranch");
      pbranchindex1005 = readrel1032->getIndex(ord1031, false);
      std::vector<u16> ord1033({0, 1, 2});
      slog::Relation* readrel1034 = db->getRelation("st_union");
      st_unionindex1006 = readrel1034->getIndex(ord1033, false);
      std::vector<u16> ord1035({1, 2, 3, 4, 0});
      slog::Relation* readrel1036 = db->getRelation("st_join");
      st_joinindex1007 = readrel1036->getIndex(ord1035, false);
      std::vector<u16> ord1037({0, 1, 2});
      slog::Relation* readrel1038 = db->getRelation("st_union");
      st_unionindex1008 = readrel1038->getIndex(ord1037, false);
      std::vector<u16> ord1039({0, 1});
      slog::Relation* readrel1040 = db->getRelation("st_join_ans");
      st_join_ansindex1009 = readrel1040->getIndex(ord1039, false);
  
    }
    ReadTask1010(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c153 = _t[0];
        u64 v_c57 = _t[1];
        u64 v_c51 = _t[2];
        if (!slog::exists_probe<5,1>(pbranchindex996, std::array<u64,5>{v_c57, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<11,2>($sup9688x120x0x0x0index997, std::array<u64,11>{v_c51, v_c57, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex998, std::array<u64,5>{v_c51, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(st_joinindex999, std::array<u64,5>{v_c57, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(st_msk_ansindex1000, std::array<u64,2>{v_c153, 0}, [&](const std::array<u64,2>& m1041) {
          u64 v_c11 = m1041[1];
          slog::join_probe<5,1>(pbranchindex1001, std::array<u64,5>{v_c57, 0, 0, 0, 0}, [&](const std::array<u64,5>& m1042) {
            u64 v_c56 = m1042[1]; u64 v_c55 = m1042[2]; u64 v_c47 = m1042[3]; u64 v_c154 = m1042[4];
            u64 v_c155 = _prim_lt(db, v_c56, v_c51);
            if (v_c155 == slog_error) { slog::emit_pending_error(db, "set.slog:121"); return; }
            if (!v_c155) return;
            if (!slog::exists_probe<5,2>(st_joinindex1002, std::array<u64,5>{v_c57, v_c154, 0, 0, 0})) return;
            if (!slog::exists_probe<3,1>(st_unionindex1003, std::array<u64,3>{v_c154, 0, 0})) return;
            slog::join_probe<11,6>($sup9688x120x0x0x0index1004, std::array<u64,11>{v_c55, v_c56, v_c57, v_c47, v_c154, v_c51, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m1044) {
              u64 v_c156 = m1044[6]; u64 v_c50 = m1044[7]; u64 v_c157 = m1044[8]; u64 v_c52 = m1044[9]; u64 v_c53 = m1044[10];
              if (v_c50 == v_c11) return;
              slog::join_probe<5,5>(pbranchindex1005, std::array<u64,5>{v_c50, v_c51, v_c52, v_c53, v_c157}, [&](const std::array<u64,5>& m1045) {
                if (!slog::exists_probe<3,3>(st_unionindex1006, std::array<u64,3>{v_c156, v_c154, v_c157})) return;
                slog::join_probe<5,4>(st_joinindex1007, std::array<u64,5>{v_c57, v_c154, v_c50, v_c157, 0}, [&](const std::array<u64,5>& m1046) {
                  u64 v_c158 = m1046[4];
                  slog::join_probe<3,3>(st_unionindex1008, std::array<u64,3>{v_c156, v_c154, v_c157}, [&](const std::array<u64,3>& m1047) {
                    slog::join_probe<2,1>(st_join_ansindex1009, std::array<u64,2>{v_c158, 0}, [&](const std::array<u64,2>& m1048) {
                      u64 v_c85 = m1048[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c156, v_c85}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:121", "delta:st_msk", _fires);
  
      if (!_done)
      {
        ReadTask1010* _cont = new ReadTask1010(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1010(db,b), false);
  // (crule (pre (let __tconst0v7T491 const5feceb66ffc86f38d952786c)) (scan pbranch __t4hkT489 p m l r) (body (exists st_del (1 2 0) 1 __t4hkT489) (exists st_bld (1 2 3 4 0) 3 p m l) (exists st_msk (2 0 1) 1 m) (exists st_msk_ans (1 0) 1 p) (exists st_del (1 2 0) 1 r) (join $sup9688x90x0x0x0 (4 2 3 5 0 1) 4 p l m r __t3j4h490 k) (join-old st_del (0 2 1) 3 (0 2 1) __t3j4h490 k __t4hkT489) (exists st_msk (1 2 0) 2 k m) (exists st_del (1 2 0) 2 r k) (join-old st_bld (1 2 3 4 0) 3 (1 2 3 4 0) p m l __v0 __t8CKV493) (exists st_del_ans (1 0) 1 __v0) (exists st_bld_ans (0 1) 1 __t8CKV493) (join-old st_msk (1 2 0) 2 (1 2 0) k m __t44Py494) (join st_msk_ans (0 1) 2 __t44Py494 p) (join-old st_del (1 2 0) 2 (1 2 0) r k __t9BRr495) (join st_del_ans (0 1) 2 __t9BRr495 __v0) (join st_bld_ans (0 1) 1 __t8CKV493 res) (let __t3zgo492 (band k m)) (cmp gt __t3zgo492 __tconst0v7T491)) (head (emit st_del_ans (0 1) __t3j4h490 res)) set.slog:91 #f)
  class ReadTask1070 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_delindex1049;  slog::Index** st_bldindex1050;  slog::Index** st_mskindex1051;  slog::Index** st_msk_ansindex1052;  slog::Index** st_delindex1053;  slog::Index** $sup9688x90x0x0x0index1054;  slog::Index** st_delindex1055;  slog::Index** st_mskindex1056;  slog::Index** st_delindex1057;  slog::Index** st_bldindex1058;  slog::Index** st_del_ansindex1059;  slog::Index** st_bld_ansindex1060;  slog::Index** st_mskindex1061;  slog::Index** st_msk_ansindex1062;  slog::Index** st_delindex1063;  slog::Index** st_del_ansindex1064;  slog::Index** st_bld_ansindex1065;  slog::Index** st_deldelta1066;  slog::Index** st_blddelta1067;  slog::Index** st_mskdelta1068;  slog::Index** st_deldelta1069;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_del_ans");
      std::vector<u16> ord1071({0, 1});
      slog::Relation* readrel1072 = db->getRelation("st_del_ans");
      head_index[0] = readrel1072->getIndex(ord1071, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord1073({1, 2, 0});
      slog::Relation* readrel1074 = db->getRelation("st_del");
      st_delindex1049 = readrel1074->getIndex(ord1073, false);
      std::vector<u16> ord1075({1, 2, 3, 4, 0});
      slog::Relation* readrel1076 = db->getRelation("st_bld");
      st_bldindex1050 = readrel1076->getIndex(ord1075, false);
      std::vector<u16> ord1077({2, 0, 1});
      slog::Relation* readrel1078 = db->getRelation("st_msk");
      st_mskindex1051 = readrel1078->getIndex(ord1077, false);
      std::vector<u16> ord1079({1, 0});
      slog::Relation* readrel1080 = db->getRelation("st_msk_ans");
      st_msk_ansindex1052 = readrel1080->getIndex(ord1079, false);
      std::vector<u16> ord1081({1, 2, 0});
      slog::Relation* readrel1082 = db->getRelation("st_del");
      st_delindex1053 = readrel1082->getIndex(ord1081, false);
      std::vector<u16> ord1083({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel1084 = db->getRelation("$sup9688x90x0x0x0");
      $sup9688x90x0x0x0index1054 = readrel1084->getIndex(ord1083, false);
      std::vector<u16> ord1085({0, 2, 1});
      slog::Relation* readrel1086 = db->getRelation("st_del");
      st_delindex1055 = readrel1086->getIndex(ord1085, false);
      std::vector<u16> ord1087({0, 2, 1});
      slog::Relation* readrel1088 = db->getRelation("st_del");
      st_deldelta1066 = readrel1088->getIndex(ord1087, true);
      std::vector<u16> ord1089({1, 2, 0});
      slog::Relation* readrel1090 = db->getRelation("st_msk");
      st_mskindex1056 = readrel1090->getIndex(ord1089, false);
      std::vector<u16> ord1091({1, 2, 0});
      slog::Relation* readrel1092 = db->getRelation("st_del");
      st_delindex1057 = readrel1092->getIndex(ord1091, false);
      std::vector<u16> ord1093({1, 2, 3, 4, 0});
      slog::Relation* readrel1094 = db->getRelation("st_bld");
      st_bldindex1058 = readrel1094->getIndex(ord1093, false);
      std::vector<u16> ord1095({1, 2, 3, 4, 0});
      slog::Relation* readrel1096 = db->getRelation("st_bld");
      st_blddelta1067 = readrel1096->getIndex(ord1095, true);
      std::vector<u16> ord1097({1, 0});
      slog::Relation* readrel1098 = db->getRelation("st_del_ans");
      st_del_ansindex1059 = readrel1098->getIndex(ord1097, false);
      std::vector<u16> ord1099({0, 1});
      slog::Relation* readrel1100 = db->getRelation("st_bld_ans");
      st_bld_ansindex1060 = readrel1100->getIndex(ord1099, false);
      std::vector<u16> ord1101({1, 2, 0});
      slog::Relation* readrel1102 = db->getRelation("st_msk");
      st_mskindex1061 = readrel1102->getIndex(ord1101, false);
      std::vector<u16> ord1103({1, 2, 0});
      slog::Relation* readrel1104 = db->getRelation("st_msk");
      st_mskdelta1068 = readrel1104->getIndex(ord1103, true);
      std::vector<u16> ord1105({0, 1});
      slog::Relation* readrel1106 = db->getRelation("st_msk_ans");
      st_msk_ansindex1062 = readrel1106->getIndex(ord1105, false);
      std::vector<u16> ord1107({1, 2, 0});
      slog::Relation* readrel1108 = db->getRelation("st_del");
      st_delindex1063 = readrel1108->getIndex(ord1107, false);
      std::vector<u16> ord1109({1, 2, 0});
      slog::Relation* readrel1110 = db->getRelation("st_del");
      st_deldelta1069 = readrel1110->getIndex(ord1109, true);
      std::vector<u16> ord1111({0, 1});
      slog::Relation* readrel1112 = db->getRelation("st_del_ans");
      st_del_ansindex1064 = readrel1112->getIndex(ord1111, false);
      std::vector<u16> ord1113({0, 1});
      slog::Relation* readrel1114 = db->getRelation("st_bld_ans");
      st_bld_ansindex1065 = readrel1114->getIndex(ord1113, false);
  
    }
    ReadTask1070(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c159 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c160 = _t[0];
        u64 v_c57 = _t[1];
        u64 v_c56 = _t[2];
        u64 v_c55 = _t[3];
        u64 v_c47 = _t[4];
        if (!slog::exists_probe<3,1>(st_delindex1049, std::array<u64,3>{v_c160, 0, 0})) return;
        if (!slog::exists_probe<5,3>(st_bldindex1050, std::array<u64,5>{v_c57, v_c56, v_c55, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mskindex1051, std::array<u64,3>{v_c56, 0, 0})) return;
        if (!slog::exists_probe<2,1>(st_msk_ansindex1052, std::array<u64,2>{v_c57, 0})) return;
        if (!slog::exists_probe<3,1>(st_delindex1053, std::array<u64,3>{v_c47, 0, 0})) return;
        slog::join_probe<6,4>($sup9688x90x0x0x0index1054, std::array<u64,6>{v_c57, v_c55, v_c56, v_c47, 0, 0}, [&](const std::array<u64,6>& m1115) {
          u64 v_c161 = m1115[4]; u64 v_c82 = m1115[5];
          slog::join_probe_old<3,3>(st_delindex1055, st_deldelta1066, std::array<u64,3>{v_c161, v_c82, v_c160}, [&](const std::array<u64,3>& m1116) {
            if (!slog::exists_probe<3,2>(st_mskindex1056, std::array<u64,3>{v_c82, v_c56, 0})) return;
            if (!slog::exists_probe<3,2>(st_delindex1057, std::array<u64,3>{v_c47, v_c82, 0})) return;
            slog::join_probe_old<5,3>(st_bldindex1058, st_blddelta1067, std::array<u64,5>{v_c57, v_c56, v_c55, 0, 0}, [&](const std::array<u64,5>& m1117) {
              u64 v_c11 = m1117[3]; u64 v_c162 = m1117[4];
              if (!slog::exists_probe<2,1>(st_del_ansindex1059, std::array<u64,2>{v_c11, 0})) return;
              if (!slog::exists_probe<2,1>(st_bld_ansindex1060, std::array<u64,2>{v_c162, 0})) return;
              slog::join_probe_old<3,2>(st_mskindex1061, st_mskdelta1068, std::array<u64,3>{v_c82, v_c56, 0}, [&](const std::array<u64,3>& m1118) {
                u64 v_c163 = m1118[2];
                slog::join_probe<2,2>(st_msk_ansindex1062, std::array<u64,2>{v_c163, v_c57}, [&](const std::array<u64,2>& m1119) {
                  slog::join_probe_old<3,2>(st_delindex1063, st_deldelta1069, std::array<u64,3>{v_c47, v_c82, 0}, [&](const std::array<u64,3>& m1120) {
                    u64 v_c164 = m1120[2];
                    slog::join_probe<2,2>(st_del_ansindex1064, std::array<u64,2>{v_c164, v_c11}, [&](const std::array<u64,2>& m1121) {
                      slog::join_probe<2,1>(st_bld_ansindex1065, std::array<u64,2>{v_c162, 0}, [&](const std::array<u64,2>& m1122) {
                        u64 v_c85 = m1122[1];
                        u64 v_c165 = _prim_band(db, v_c82, v_c56);
                        if (v_c165 == slog_error) { slog::emit_pending_error(db, "set.slog:91"); return; }
                        u64 v_c166 = _prim_gt(db, v_c165, v_c159);
                        if (v_c166 == slog_error) { slog::emit_pending_error(db, "set.slog:91"); return; }
                        if (!v_c166) return;
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c161, v_c85}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("set.slog:91", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask1070* _cont = new ReadTask1070(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1070(db,b), false);
  // (crule (pre (let __tconst3qtG324 const6b86b273ff34fce19d6b804e)) (scan st_mem0_ans __t14DN326 a) (body (join-old st_mem0 (0 1 2) 1 (0 1 2) __t14DN326 l k) (exists pbranch (3 0 1 2 4) 1 l) (exists st_mem0 (2 0 1) 1 k) (exists st_msk (1 2 0) 1 k) (join-old $sup9688x70x0x0x0 (1 2 0 3 4 5) 2 (1 2 0 3 4 5) k l __t6uqp323 m p r) (exists st_mem0 (2 0 1) 2 k __t6uqp323) (exists st_msk (1 2 0) 2 k m) (exists st_msk_ans (1 0) 1 p) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t7Uqa322) (join-old st_mem0 (0 1 2) 3 (0 1 2) __t6uqp323 __t7Uqa322 k) (join-old st_msk (1 2 0) 2 (1 2 0) k m __t3nJI327) (join-old st_msk_ans (0 1) 2 (0 1) __t3nJI327 p) (let __t1YAQ325 (band k m)) (cmp lt __t1YAQ325 __tconst3qtG324)) (head (emit st_mem0_ans (0 1) __t6uqp323 a)) set.slog:71 #f)
  class ReadTask1142 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_mem0index1124;  slog::Index** pbranchindex1125;  slog::Index** st_mem0index1126;  slog::Index** st_mskindex1127;  slog::Index** $sup9688x70x0x0x0index1128;  slog::Index** st_mem0index1129;  slog::Index** st_mskindex1130;  slog::Index** st_msk_ansindex1131;  slog::Index** pbranchindex1132;  slog::Index** st_mem0index1133;  slog::Index** st_mskindex1134;  slog::Index** st_msk_ansindex1135;  slog::Index** st_mem0delta1136;  slog::Index** $sup9688x70x0x0x0delta1137;  slog::Index** pbranchdelta1138;  slog::Index** st_mem0delta1139;  slog::Index** st_mskdelta1140;  slog::Index** st_msk_ansdelta1141;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_mem0_ans");
      std::vector<u16> ord1143({0, 1});
      slog::Relation* readrel1144 = db->getRelation("st_mem0_ans");
      head_index[0] = readrel1144->getIndex(ord1143, false);
      outer_rel = db->getRelation("st_mem0_ans");
      std::vector<u16> ord1145({0, 1, 2});
      slog::Relation* readrel1146 = db->getRelation("st_mem0");
      st_mem0index1124 = readrel1146->getIndex(ord1145, false);
      std::vector<u16> ord1147({0, 1, 2});
      slog::Relation* readrel1148 = db->getRelation("st_mem0");
      st_mem0delta1136 = readrel1148->getIndex(ord1147, true);
      std::vector<u16> ord1149({3, 0, 1, 2, 4});
      slog::Relation* readrel1150 = db->getRelation("pbranch");
      pbranchindex1125 = readrel1150->getIndex(ord1149, false);
      std::vector<u16> ord1151({2, 0, 1});
      slog::Relation* readrel1152 = db->getRelation("st_mem0");
      st_mem0index1126 = readrel1152->getIndex(ord1151, false);
      std::vector<u16> ord1153({1, 2, 0});
      slog::Relation* readrel1154 = db->getRelation("st_msk");
      st_mskindex1127 = readrel1154->getIndex(ord1153, false);
      std::vector<u16> ord1155({1, 2, 0, 3, 4, 5});
      slog::Relation* readrel1156 = db->getRelation("$sup9688x70x0x0x0");
      $sup9688x70x0x0x0index1128 = readrel1156->getIndex(ord1155, false);
      std::vector<u16> ord1157({1, 2, 0, 3, 4, 5});
      slog::Relation* readrel1158 = db->getRelation("$sup9688x70x0x0x0");
      $sup9688x70x0x0x0delta1137 = readrel1158->getIndex(ord1157, true);
      std::vector<u16> ord1159({2, 0, 1});
      slog::Relation* readrel1160 = db->getRelation("st_mem0");
      st_mem0index1129 = readrel1160->getIndex(ord1159, false);
      std::vector<u16> ord1161({1, 2, 0});
      slog::Relation* readrel1162 = db->getRelation("st_msk");
      st_mskindex1130 = readrel1162->getIndex(ord1161, false);
      std::vector<u16> ord1163({1, 0});
      slog::Relation* readrel1164 = db->getRelation("st_msk_ans");
      st_msk_ansindex1131 = readrel1164->getIndex(ord1163, false);
      std::vector<u16> ord1165({1, 2, 3, 4, 0});
      slog::Relation* readrel1166 = db->getRelation("pbranch");
      pbranchindex1132 = readrel1166->getIndex(ord1165, false);
      std::vector<u16> ord1167({1, 2, 3, 4, 0});
      slog::Relation* readrel1168 = db->getRelation("pbranch");
      pbranchdelta1138 = readrel1168->getIndex(ord1167, true);
      std::vector<u16> ord1169({0, 1, 2});
      slog::Relation* readrel1170 = db->getRelation("st_mem0");
      st_mem0index1133 = readrel1170->getIndex(ord1169, false);
      std::vector<u16> ord1171({0, 1, 2});
      slog::Relation* readrel1172 = db->getRelation("st_mem0");
      st_mem0delta1139 = readrel1172->getIndex(ord1171, true);
      std::vector<u16> ord1173({1, 2, 0});
      slog::Relation* readrel1174 = db->getRelation("st_msk");
      st_mskindex1134 = readrel1174->getIndex(ord1173, false);
      std::vector<u16> ord1175({1, 2, 0});
      slog::Relation* readrel1176 = db->getRelation("st_msk");
      st_mskdelta1140 = readrel1176->getIndex(ord1175, true);
      std::vector<u16> ord1177({0, 1});
      slog::Relation* readrel1178 = db->getRelation("st_msk_ans");
      st_msk_ansindex1135 = readrel1178->getIndex(ord1177, false);
      std::vector<u16> ord1179({0, 1});
      slog::Relation* readrel1180 = db->getRelation("st_msk_ans");
      st_msk_ansdelta1141 = readrel1180->getIndex(ord1179, true);
  
    }
    ReadTask1142(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c167 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c168 = _t[0];
        u64 v_c43 = _t[1];
        slog::join_probe_old<3,1>(st_mem0index1124, st_mem0delta1136, std::array<u64,3>{v_c168, 0, 0}, [&](const std::array<u64,3>& m1181) {
          u64 v_c55 = m1181[1]; u64 v_c82 = m1181[2];
          if (!slog::exists_probe<5,1>(pbranchindex1125, std::array<u64,5>{v_c55, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(st_mem0index1126, std::array<u64,3>{v_c82, 0, 0})) return;
          if (!slog::exists_probe<3,1>(st_mskindex1127, std::array<u64,3>{v_c82, 0, 0})) return;
          slog::join_probe_old<6,2>($sup9688x70x0x0x0index1128, $sup9688x70x0x0x0delta1137, std::array<u64,6>{v_c82, v_c55, 0, 0, 0, 0}, [&](const std::array<u64,6>& m1182) {
            u64 v_c169 = m1182[2]; u64 v_c56 = m1182[3]; u64 v_c57 = m1182[4]; u64 v_c47 = m1182[5];
            if (!slog::exists_probe<3,2>(st_mem0index1129, std::array<u64,3>{v_c82, v_c169, 0})) return;
            if (!slog::exists_probe<3,2>(st_mskindex1130, std::array<u64,3>{v_c82, v_c56, 0})) return;
            if (!slog::exists_probe<2,1>(st_msk_ansindex1131, std::array<u64,2>{v_c57, 0})) return;
            slog::join_probe_old<5,4>(pbranchindex1132, pbranchdelta1138, std::array<u64,5>{v_c57, v_c56, v_c55, v_c47, 0}, [&](const std::array<u64,5>& m1183) {
              u64 v_c170 = m1183[4];
              slog::join_probe_old<3,3>(st_mem0index1133, st_mem0delta1139, std::array<u64,3>{v_c169, v_c170, v_c82}, [&](const std::array<u64,3>& m1184) {
                slog::join_probe_old<3,2>(st_mskindex1134, st_mskdelta1140, std::array<u64,3>{v_c82, v_c56, 0}, [&](const std::array<u64,3>& m1185) {
                  u64 v_c171 = m1185[2];
                  slog::join_probe_old<2,2>(st_msk_ansindex1135, st_msk_ansdelta1141, std::array<u64,2>{v_c171, v_c57}, [&](const std::array<u64,2>& m1186) {
                    u64 v_c172 = _prim_band(db, v_c82, v_c56);
                    if (v_c172 == slog_error) { slog::emit_pending_error(db, "set.slog:71"); return; }
                    u64 v_c173 = _prim_lt(db, v_c172, v_c167);
                    if (v_c173 == slog_error) { slog::emit_pending_error(db, "set.slog:71"); return; }
                    if (!v_c173) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c169, v_c43}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:71", "delta:st_mem0_ans", _fires);
  
      if (!_done)
      {
        ReadTask1142* _cont = new ReadTask1142(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1142(db,b), false);
  // (crule (pre) (scan st_ins_ans __t5aIA185 r) (body (join-old st_ins (0 2 1) 1 (0 2 1) __t5aIA185 k t) (exists st_union (2 0 1) 1 t) (join-old pleaf (1 0) 1 (1 0) k __t7Mu9183) (join-old st_union (1 2 0) 2 (1 2 0) __t7Mu9183 t __t2rFM184)) (head (emit st_union_ans (0 1) __t2rFM184 r)) set.slog:98 #f)
  class ReadTask1195 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_insindex1188;  slog::Index** st_unionindex1189;  slog::Index** pleafindex1190;  slog::Index** st_unionindex1191;  slog::Index** st_insdelta1192;  slog::Index** pleafdelta1193;  slog::Index** st_uniondelta1194;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_union_ans");
      std::vector<u16> ord1196({0, 1});
      slog::Relation* readrel1197 = db->getRelation("st_union_ans");
      head_index[0] = readrel1197->getIndex(ord1196, false);
      outer_rel = db->getRelation("st_ins_ans");
      std::vector<u16> ord1198({0, 2, 1});
      slog::Relation* readrel1199 = db->getRelation("st_ins");
      st_insindex1188 = readrel1199->getIndex(ord1198, false);
      std::vector<u16> ord1200({0, 2, 1});
      slog::Relation* readrel1201 = db->getRelation("st_ins");
      st_insdelta1192 = readrel1201->getIndex(ord1200, true);
      std::vector<u16> ord1202({2, 0, 1});
      slog::Relation* readrel1203 = db->getRelation("st_union");
      st_unionindex1189 = readrel1203->getIndex(ord1202, false);
      std::vector<u16> ord1204({1, 0});
      slog::Relation* readrel1205 = db->getRelation("pleaf");
      pleafindex1190 = readrel1205->getIndex(ord1204, false);
      std::vector<u16> ord1206({1, 0});
      slog::Relation* readrel1207 = db->getRelation("pleaf");
      pleafdelta1193 = readrel1207->getIndex(ord1206, true);
      std::vector<u16> ord1208({1, 2, 0});
      slog::Relation* readrel1209 = db->getRelation("st_union");
      st_unionindex1191 = readrel1209->getIndex(ord1208, false);
      std::vector<u16> ord1210({1, 2, 0});
      slog::Relation* readrel1211 = db->getRelation("st_union");
      st_uniondelta1194 = readrel1211->getIndex(ord1210, true);
  
    }
    ReadTask1195(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c174 = _t[0];
        u64 v_c47 = _t[1];
        slog::join_probe_old<3,1>(st_insindex1188, st_insdelta1192, std::array<u64,3>{v_c174, 0, 0}, [&](const std::array<u64,3>& m1212) {
          u64 v_c82 = m1212[1]; u64 v_c175 = m1212[2];
          if (!slog::exists_probe<3,1>(st_unionindex1189, std::array<u64,3>{v_c175, 0, 0})) return;
          slog::join_probe_old<2,1>(pleafindex1190, pleafdelta1193, std::array<u64,2>{v_c82, 0}, [&](const std::array<u64,2>& m1213) {
            u64 v_c176 = m1213[1];
            slog::join_probe_old<3,2>(st_unionindex1191, st_uniondelta1194, std::array<u64,3>{v_c176, v_c175, 0}, [&](const std::array<u64,3>& m1214) {
              u64 v_c177 = m1214[2];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c177, v_c47}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:98", "delta:st_ins_ans", _fires);
  
      if (!_done)
      {
        ReadTask1195* _cont = new ReadTask1195(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1195(db,b), false);
  // (crule (pre (let __tconst8cca353 const6b86b273ff34fce19d6b804e)) (scan $sup9688x36x0x0x2 __t0kmv352 __t75bg356 dup66Lo1333 dup68E21334 __v0 __v1 __v3 p0 p1 t0 t1) (body (eq __t75bg356 dup68E21334) (eq __t75bg356 dup66Lo1333) (join-old $sup9688x36x0x0x1 (0 3 4 5 6 1 2) 7 (0 3 4 5 6 1 2) __t0kmv352 p0 p1 t0 t1 __t75bg356 __v0) (join-old $sup9688x36x0x0x0 (1 0 2 3 4) 5 (1 0 2 3 4) p0 __t0kmv352 p1 t0 t1) (join-old st_join (1 2 3 4 0) 5 (1 2 3 4 0) p0 t0 p1 t1 __t0kmv352) (join-old st_hsb_ans (0 1) 2 (0 1) __t75bg356 __v3) (join-old st_hsb_ans (0 1) 2 (0 1) __t75bg356 __v1) (join-old st_hsb_ans (0 1) 2 (0 1) __t75bg356 __v0) (join-old st_msk (1 2 0) 2 (1 2 0) p0 __v1 __t9xbE359) (join-old st_msk_ans (0 1) 1 (0 1) __t9xbE359 __v2) (let __t5oQR360 (bxor p0 p1)) (join-old st_hsb (0 1) 2 (0 1) __t75bg356 __t5oQR360) (let __t3ChK354 (band p0 __v0)) (cmp lt __t3ChK354 __tconst8cca353)) (head (emit-temp temp3xVH1332 __t0kmv352 __v2 __v3 t0 t1) (mkstruct pbranch (1 2 3 4 0) __t4fDE351 __v2 __v3 t0 t1)) set.slog:37 #f)
  class ReadTask1233 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x36x0x0x1index1215;  slog::Index** $sup9688x36x0x0x0index1216;  slog::Index** st_joinindex1217;  slog::Index** st_hsb_ansindex1218;  slog::Index** st_hsb_ansindex1219;  slog::Index** st_hsb_ansindex1220;  slog::Index** st_mskindex1221;  slog::Index** st_msk_ansindex1222;  slog::Index** st_hsbindex1223;  slog::Index** $sup9688x36x0x0x1delta1224;  slog::Index** $sup9688x36x0x0x0delta1225;  slog::Index** st_joindelta1226;  slog::Index** st_hsb_ansdelta1227;  slog::Index** st_hsb_ansdelta1228;  slog::Index** st_hsb_ansdelta1229;  slog::Index** st_mskdelta1230;  slog::Index** st_msk_ansdelta1231;  slog::Index** st_hsbdelta1232;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3xVH1332");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("$sup9688x36x0x0x2");
      std::vector<u16> ord1234({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel1235 = db->getRelation("$sup9688x36x0x0x1");
      $sup9688x36x0x0x1index1215 = readrel1235->getIndex(ord1234, false);
      std::vector<u16> ord1236({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel1237 = db->getRelation("$sup9688x36x0x0x1");
      $sup9688x36x0x0x1delta1224 = readrel1237->getIndex(ord1236, true);
      std::vector<u16> ord1238({1, 0, 2, 3, 4});
      slog::Relation* readrel1239 = db->getRelation("$sup9688x36x0x0x0");
      $sup9688x36x0x0x0index1216 = readrel1239->getIndex(ord1238, false);
      std::vector<u16> ord1240({1, 0, 2, 3, 4});
      slog::Relation* readrel1241 = db->getRelation("$sup9688x36x0x0x0");
      $sup9688x36x0x0x0delta1225 = readrel1241->getIndex(ord1240, true);
      std::vector<u16> ord1242({1, 2, 3, 4, 0});
      slog::Relation* readrel1243 = db->getRelation("st_join");
      st_joinindex1217 = readrel1243->getIndex(ord1242, false);
      std::vector<u16> ord1244({1, 2, 3, 4, 0});
      slog::Relation* readrel1245 = db->getRelation("st_join");
      st_joindelta1226 = readrel1245->getIndex(ord1244, true);
      std::vector<u16> ord1246({0, 1});
      slog::Relation* readrel1247 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex1218 = readrel1247->getIndex(ord1246, false);
      std::vector<u16> ord1248({0, 1});
      slog::Relation* readrel1249 = db->getRelation("st_hsb_ans");
      st_hsb_ansdelta1227 = readrel1249->getIndex(ord1248, true);
      std::vector<u16> ord1250({0, 1});
      slog::Relation* readrel1251 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex1219 = readrel1251->getIndex(ord1250, false);
      std::vector<u16> ord1252({0, 1});
      slog::Relation* readrel1253 = db->getRelation("st_hsb_ans");
      st_hsb_ansdelta1228 = readrel1253->getIndex(ord1252, true);
      std::vector<u16> ord1254({0, 1});
      slog::Relation* readrel1255 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex1220 = readrel1255->getIndex(ord1254, false);
      std::vector<u16> ord1256({0, 1});
      slog::Relation* readrel1257 = db->getRelation("st_hsb_ans");
      st_hsb_ansdelta1229 = readrel1257->getIndex(ord1256, true);
      std::vector<u16> ord1258({1, 2, 0});
      slog::Relation* readrel1259 = db->getRelation("st_msk");
      st_mskindex1221 = readrel1259->getIndex(ord1258, false);
      std::vector<u16> ord1260({1, 2, 0});
      slog::Relation* readrel1261 = db->getRelation("st_msk");
      st_mskdelta1230 = readrel1261->getIndex(ord1260, true);
      std::vector<u16> ord1262({0, 1});
      slog::Relation* readrel1263 = db->getRelation("st_msk_ans");
      st_msk_ansindex1222 = readrel1263->getIndex(ord1262, false);
      std::vector<u16> ord1264({0, 1});
      slog::Relation* readrel1265 = db->getRelation("st_msk_ans");
      st_msk_ansdelta1231 = readrel1265->getIndex(ord1264, true);
      std::vector<u16> ord1266({0, 1});
      slog::Relation* readrel1267 = db->getRelation("st_hsb");
      st_hsbindex1223 = readrel1267->getIndex(ord1266, false);
      std::vector<u16> ord1268({0, 1});
      slog::Relation* readrel1269 = db->getRelation("st_hsb");
      st_hsbdelta1232 = readrel1269->getIndex(ord1268, true);
  
    }
    ReadTask1233(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c69 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c72 = _t[0];
        u64 v_c71 = _t[1];
        u64 v_c73 = _t[2];
        u64 v_c74 = _t[3];
        u64 v_c11 = _t[4];
        u64 v_c5 = _t[5];
        u64 v_c7 = _t[6];
        u64 v_c4 = _t[7];
        u64 v_c12 = _t[8];
        u64 v_c13 = _t[9];
        u64 v_c14 = _t[10];
        if (v_c71 != v_c74) return;
        if (v_c71 != v_c73) return;
        slog::join_probe_old<7,7>($sup9688x36x0x0x1index1215, $sup9688x36x0x0x1delta1224, std::array<u64,7>{v_c72, v_c4, v_c12, v_c13, v_c14, v_c71, v_c11}, [&](const std::array<u64,7>& m1270) {
          slog::join_probe_old<5,5>($sup9688x36x0x0x0index1216, $sup9688x36x0x0x0delta1225, std::array<u64,5>{v_c4, v_c72, v_c12, v_c13, v_c14}, [&](const std::array<u64,5>& m1271) {
            slog::join_probe_old<5,5>(st_joinindex1217, st_joindelta1226, std::array<u64,5>{v_c4, v_c13, v_c12, v_c14, v_c72}, [&](const std::array<u64,5>& m1272) {
              slog::join_probe_old<2,2>(st_hsb_ansindex1218, st_hsb_ansdelta1227, std::array<u64,2>{v_c71, v_c7}, [&](const std::array<u64,2>& m1273) {
                slog::join_probe_old<2,2>(st_hsb_ansindex1219, st_hsb_ansdelta1228, std::array<u64,2>{v_c71, v_c5}, [&](const std::array<u64,2>& m1274) {
                  slog::join_probe_old<2,2>(st_hsb_ansindex1220, st_hsb_ansdelta1229, std::array<u64,2>{v_c71, v_c11}, [&](const std::array<u64,2>& m1275) {
                    slog::join_probe_old<3,2>(st_mskindex1221, st_mskdelta1230, std::array<u64,3>{v_c4, v_c5, 0}, [&](const std::array<u64,3>& m1276) {
                      u64 v_c70 = m1276[2];
                      slog::join_probe_old<2,1>(st_msk_ansindex1222, st_msk_ansdelta1231, std::array<u64,2>{v_c70, 0}, [&](const std::array<u64,2>& m1277) {
                        u64 v_c3 = m1277[1];
                        u64 v_c75 = _prim_bxor(db, v_c4, v_c12);
                        if (v_c75 == slog_error) { slog::emit_pending_error(db, "set.slog:37"); return; }
                        slog::join_probe_old<2,2>(st_hsbindex1223, st_hsbdelta1232, std::array<u64,2>{v_c71, v_c75}, [&](const std::array<u64,2>& m1278) {
                          u64 v_c76 = _prim_band(db, v_c4, v_c11);
                          if (v_c76 == slog_error) { slog::emit_pending_error(db, "set.slog:37"); return; }
                          u64 v_c178 = _prim_lt(db, v_c76, v_c69);
                          if (v_c178 == slog_error) { slog::emit_pending_error(db, "set.slog:37"); return; }
                          if (!v_c178) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c72, v_c3, v_c7, v_c13, v_c14});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c3, v_c7, v_c13, v_c14}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:37", "delta:$sup9688x36x0x0x2", _fires);
  
      if (!_done)
      {
        ReadTask1233* _cont = new ReadTask1233(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1233(db,b), false);
  // (crule (pre (let __tconst3xtE191 const6b86b273ff34fce19d6b804e)) (scan pbranch __t1xmG188 q n u v) (body (join-old st_union (2 0 1) 1 (2 0 1) __t1xmG188 __t1CMK190 __t8Eum189) (join-old pbranch (0 1 2 3 4) 1 (0 1 2 3 4) __t8Eum189 p m l r) (cmp lt n m) (let __t1Yb7192 (band q m)) (cmp lt __t1Yb7192 __tconst3xtE191)) (head (emit $sup9688x103x0x0x0 (0 1 2 3 4 5 6 7 8) __t1CMK190 l m n p q r u v)) set.slog:104 #f)
  class ReadTask1284 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_unionindex1280;  slog::Index** pbranchindex1281;  slog::Index** st_uniondelta1282;  slog::Index** pbranchdelta1283;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x103x0x0x0");
      std::vector<u16> ord1285({0, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel1286 = db->getRelation("$sup9688x103x0x0x0");
      head_index[0] = readrel1286->getIndex(ord1285, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord1287({2, 0, 1});
      slog::Relation* readrel1288 = db->getRelation("st_union");
      st_unionindex1280 = readrel1288->getIndex(ord1287, false);
      std::vector<u16> ord1289({2, 0, 1});
      slog::Relation* readrel1290 = db->getRelation("st_union");
      st_uniondelta1282 = readrel1290->getIndex(ord1289, true);
      std::vector<u16> ord1291({0, 1, 2, 3, 4});
      slog::Relation* readrel1292 = db->getRelation("pbranch");
      pbranchindex1281 = readrel1292->getIndex(ord1291, false);
      std::vector<u16> ord1293({0, 1, 2, 3, 4});
      slog::Relation* readrel1294 = db->getRelation("pbranch");
      pbranchdelta1283 = readrel1294->getIndex(ord1293, true);
  
    }
    ReadTask1284(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c179 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c180 = _t[0];
        u64 v_c50 = _t[1];
        u64 v_c51 = _t[2];
        u64 v_c52 = _t[3];
        u64 v_c53 = _t[4];
        slog::join_probe_old<3,1>(st_unionindex1280, st_uniondelta1282, std::array<u64,3>{v_c180, 0, 0}, [&](const std::array<u64,3>& m1295) {
          u64 v_c181 = m1295[1]; u64 v_c182 = m1295[2];
          slog::join_probe_old<5,1>(pbranchindex1281, pbranchdelta1283, std::array<u64,5>{v_c182, 0, 0, 0, 0}, [&](const std::array<u64,5>& m1296) {
            u64 v_c57 = m1296[1]; u64 v_c56 = m1296[2]; u64 v_c55 = m1296[3]; u64 v_c47 = m1296[4];
            u64 v_c183 = _prim_lt(db, v_c51, v_c56);
            if (v_c183 == slog_error) { slog::emit_pending_error(db, "set.slog:104"); return; }
            if (!v_c183) return;
            u64 v_c184 = _prim_band(db, v_c50, v_c56);
            if (v_c184 == slog_error) { slog::emit_pending_error(db, "set.slog:104"); return; }
            u64 v_c185 = _prim_lt(db, v_c184, v_c179);
            if (v_c185 == slog_error) { slog::emit_pending_error(db, "set.slog:104"); return; }
            if (!v_c185) return;
            ++_fires;
            slog::emit<9>(head_rel[0], head_index[0], newbatch[0], std::array<u64,9>{v_c181, v_c55, v_c56, v_c51, v_c57, v_c50, v_c47, v_c52, v_c53}, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:104", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask1284* _cont = new ReadTask1284(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1284(db,b), false);
  // (crule (pre (let __tconst0UIr907 conste3776bfed7f405de8017ecfa) (let __tconst67v2432 constef2d127de37b942baad06145) (let __tconst3Prp435 constd4735e3a265e16eee03f5971) (let __tconst4LVH431 const6b86b273ff34fce19d6b804e)) (probe st_ins (2 0 1) 1 __tconst3Prp435 __t1RFt437 __t5QG4436) (body (join _enum (0 1) 2 __t5QG4436 __tconst0UIr907) (exists st_ins_ans (0 1) 1 __t1RFt437) (join st_ins (1 2 0) 2 __t5QG4436 __tconst67v2432 __t2Qai434) (join st_ins_ans (0 1) 1 __t2Qai434 __v0) (join st_ins_ans (0 1) 1 __t1RFt437 __v1)) (head (mkstruct st_ins (1 2 0) __12BV908 __v1 __tconst4LVH431)) st_basic.slog:18 #f)
  class ReadTask1304 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** _enumindex1299;  slog::Index** st_ins_ansindex1300;  slog::Index** st_insindex1301;  slog::Index** st_ins_ansindex1302;  slog::Index** st_ins_ansindex1303;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_ins");
      std::vector<u16> ord1305({2, 0, 1});
      slog::Relation* readrel1306 = db->getRelation("st_ins");
      driver_index = readrel1306->getIndex(ord1305, true);
      std::vector<u16> ord1307({0, 1});
      slog::Relation* readrel1308 = db->getRelation("_enum");
      _enumindex1299 = readrel1308->getIndex(ord1307, false);
      std::vector<u16> ord1309({0, 1});
      slog::Relation* readrel1310 = db->getRelation("st_ins_ans");
      st_ins_ansindex1300 = readrel1310->getIndex(ord1309, false);
      std::vector<u16> ord1311({1, 2, 0});
      slog::Relation* readrel1312 = db->getRelation("st_ins");
      st_insindex1301 = readrel1312->getIndex(ord1311, false);
      std::vector<u16> ord1313({0, 1});
      slog::Relation* readrel1314 = db->getRelation("st_ins_ans");
      st_ins_ansindex1302 = readrel1314->getIndex(ord1313, false);
      std::vector<u16> ord1315({0, 1});
      slog::Relation* readrel1316 = db->getRelation("st_ins_ans");
      st_ins_ansindex1303 = readrel1316->getIndex(ord1315, false);
  
    }
    ReadTask1304(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c186 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c187 = v_constef2d127de37b942baad06145;
      u64 v_c188 = v_constd4735e3a265e16eee03f5971;
      u64 v_c189 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c188, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1317) {
        u64 v_c190 = m1317[1];
        u64 v_c191 = m1317[2];
        if (buckethash(v_c190) != bucket) return;
        slog::join_probe<2,2>(_enumindex1299, std::array<u64,2>{v_c191, v_c186}, [&](const std::array<u64,2>& m1318) {
          if (!slog::exists_probe<2,1>(st_ins_ansindex1300, std::array<u64,2>{v_c190, 0})) return;
          slog::join_probe<3,2>(st_insindex1301, std::array<u64,3>{v_c191, v_c187, 0}, [&](const std::array<u64,3>& m1319) {
            u64 v_c192 = m1319[2];
            slog::join_probe<2,1>(st_ins_ansindex1302, std::array<u64,2>{v_c192, 0}, [&](const std::array<u64,2>& m1320) {
              u64 v_c11 = m1320[1];
              slog::join_probe<2,1>(st_ins_ansindex1303, std::array<u64,2>{v_c190, 0}, [&](const std::array<u64,2>& m1321) {
                u64 v_c5 = m1321[1];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c5, v_c189}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("st_basic.slog:18", "delta:st_ins", _fires);
  
      if (!_done)
      {
        ReadTask1304* _cont = new ReadTask1304(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1304(db,b), false);
}

