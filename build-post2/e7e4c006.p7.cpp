
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const1e44311dd5d36c3a7dc21dfa;
extern u64 v_const26c89ee8ccc4ea998fd1a912;
extern u64 v_const2c624232cdd221771294dfbb;
extern u64 v_const4b227777d4dd1fc61c6f884f;
extern u64 v_const4e07408562bedb8b60ce05c1;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const6235871e739625dd33ac2813;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const76a4fedc25549f0939d52fb7;
extern u64 v_const99e1cbf3d792d4a87847a801;
extern u64 v_consta10f76b4ec574de5d7b6908e;
extern u64 v_constc49bf1a249fe0ece92ed8fd8;
extern u64 v_constd2ed9ad006724fa952709457;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_conste3776bfed7f405de8017ecfa;
extern u64 v_consteea677b485376be09c1a9cc9;
extern u64 v_constef2d127de37b942baad06145;
extern u64 v_constf2664e0abda1016213c9fa90;


void slog_rules_cb8ebc47edbdc47eb(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre) (scan pbranch __t9ous406 p m u v) (body (exists pbranch (1 2 3 4 0) 2 p m) (exists st_diff (2 0 1) 1 __t9ous406) (exists st_diff (2 0 1) 1 u) (exists st_diff (2 0 1) 1 v) (exists st_bld (1 2 3 4 0) 2 p m) (join $sup9688x136x0x0x0 (2 3 5 6 0 1 4) 4 m p u v __t5pD6408 l r) (exists st_diff (2 0 1) 2 __t9ous406 __t5pD6408) (exists st_diff (1 2 0) 2 l u) (exists st_diff (1 2 0) 2 r v) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t3cJ7407) (join-old st_diff (0 1 2) 3 (0 1 2) __t5pD6408 __t3cJ7407 __t9ous406) (join-old st_diff (1 2 0) 2 (1 2 0) l u __t6cu0410) (exists st_diff_ans (0 1) 1 __t6cu0410) (join-old st_diff (1 2 0) 2 (1 2 0) r v __t8u30411) (exists st_diff_ans (0 1) 1 __t8u30411) (join-old st_bld (1 2 3 4 0) 2 (1 2 3 4 0) p m __v0 __v1 __t9obY409) (join st_diff_ans (0 1) 2 __t6cu0410 __v0) (join st_diff_ans (0 1) 2 __t8u30411 __v1) (join st_bld_ans (0 1) 1 __t9obY409 res)) (head (emit st_diff_ans (0 1) __t5pD6408 res)) set.slog:137 #f)
  class ReadTask24 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex0;  slog::Index** st_diffindex1;  slog::Index** st_diffindex2;  slog::Index** st_diffindex3;  slog::Index** st_bldindex4;  slog::Index** $sup9688x136x0x0x0index5;  slog::Index** st_diffindex6;  slog::Index** st_diffindex7;  slog::Index** st_diffindex8;  slog::Index** pbranchindex9;  slog::Index** st_diffindex10;  slog::Index** st_diffindex11;  slog::Index** st_diff_ansindex12;  slog::Index** st_diffindex13;  slog::Index** st_diff_ansindex14;  slog::Index** st_bldindex15;  slog::Index** st_diff_ansindex16;  slog::Index** st_diff_ansindex17;  slog::Index** st_bld_ansindex18;  slog::Index** pbranchdelta19;  slog::Index** st_diffdelta20;  slog::Index** st_diffdelta21;  slog::Index** st_diffdelta22;  slog::Index** st_blddelta23;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord25({0, 1});
      slog::Relation* readrel26 = db->getRelation("st_diff_ans");
      head_index[0] = readrel26->getIndex(ord25, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord27({1, 2, 3, 4, 0});
      slog::Relation* readrel28 = db->getRelation("pbranch");
      pbranchindex0 = readrel28->getIndex(ord27, false);
      std::vector<u16> ord29({2, 0, 1});
      slog::Relation* readrel30 = db->getRelation("st_diff");
      st_diffindex1 = readrel30->getIndex(ord29, false);
      std::vector<u16> ord31({2, 0, 1});
      slog::Relation* readrel32 = db->getRelation("st_diff");
      st_diffindex2 = readrel32->getIndex(ord31, false);
      std::vector<u16> ord33({2, 0, 1});
      slog::Relation* readrel34 = db->getRelation("st_diff");
      st_diffindex3 = readrel34->getIndex(ord33, false);
      std::vector<u16> ord35({1, 2, 3, 4, 0});
      slog::Relation* readrel36 = db->getRelation("st_bld");
      st_bldindex4 = readrel36->getIndex(ord35, false);
      std::vector<u16> ord37({2, 3, 5, 6, 0, 1, 4});
      slog::Relation* readrel38 = db->getRelation("$sup9688x136x0x0x0");
      $sup9688x136x0x0x0index5 = readrel38->getIndex(ord37, false);
      std::vector<u16> ord39({2, 0, 1});
      slog::Relation* readrel40 = db->getRelation("st_diff");
      st_diffindex6 = readrel40->getIndex(ord39, false);
      std::vector<u16> ord41({1, 2, 0});
      slog::Relation* readrel42 = db->getRelation("st_diff");
      st_diffindex7 = readrel42->getIndex(ord41, false);
      std::vector<u16> ord43({1, 2, 0});
      slog::Relation* readrel44 = db->getRelation("st_diff");
      st_diffindex8 = readrel44->getIndex(ord43, false);
      std::vector<u16> ord45({1, 2, 3, 4, 0});
      slog::Relation* readrel46 = db->getRelation("pbranch");
      pbranchindex9 = readrel46->getIndex(ord45, false);
      std::vector<u16> ord47({1, 2, 3, 4, 0});
      slog::Relation* readrel48 = db->getRelation("pbranch");
      pbranchdelta19 = readrel48->getIndex(ord47, true);
      std::vector<u16> ord49({0, 1, 2});
      slog::Relation* readrel50 = db->getRelation("st_diff");
      st_diffindex10 = readrel50->getIndex(ord49, false);
      std::vector<u16> ord51({0, 1, 2});
      slog::Relation* readrel52 = db->getRelation("st_diff");
      st_diffdelta20 = readrel52->getIndex(ord51, true);
      std::vector<u16> ord53({1, 2, 0});
      slog::Relation* readrel54 = db->getRelation("st_diff");
      st_diffindex11 = readrel54->getIndex(ord53, false);
      std::vector<u16> ord55({1, 2, 0});
      slog::Relation* readrel56 = db->getRelation("st_diff");
      st_diffdelta21 = readrel56->getIndex(ord55, true);
      std::vector<u16> ord57({0, 1});
      slog::Relation* readrel58 = db->getRelation("st_diff_ans");
      st_diff_ansindex12 = readrel58->getIndex(ord57, false);
      std::vector<u16> ord59({1, 2, 0});
      slog::Relation* readrel60 = db->getRelation("st_diff");
      st_diffindex13 = readrel60->getIndex(ord59, false);
      std::vector<u16> ord61({1, 2, 0});
      slog::Relation* readrel62 = db->getRelation("st_diff");
      st_diffdelta22 = readrel62->getIndex(ord61, true);
      std::vector<u16> ord63({0, 1});
      slog::Relation* readrel64 = db->getRelation("st_diff_ans");
      st_diff_ansindex14 = readrel64->getIndex(ord63, false);
      std::vector<u16> ord65({1, 2, 3, 4, 0});
      slog::Relation* readrel66 = db->getRelation("st_bld");
      st_bldindex15 = readrel66->getIndex(ord65, false);
      std::vector<u16> ord67({1, 2, 3, 4, 0});
      slog::Relation* readrel68 = db->getRelation("st_bld");
      st_blddelta23 = readrel68->getIndex(ord67, true);
      std::vector<u16> ord69({0, 1});
      slog::Relation* readrel70 = db->getRelation("st_diff_ans");
      st_diff_ansindex16 = readrel70->getIndex(ord69, false);
      std::vector<u16> ord71({0, 1});
      slog::Relation* readrel72 = db->getRelation("st_diff_ans");
      st_diff_ansindex17 = readrel72->getIndex(ord71, false);
      std::vector<u16> ord73({0, 1});
      slog::Relation* readrel74 = db->getRelation("st_bld_ans");
      st_bld_ansindex18 = readrel74->getIndex(ord73, false);
  
    }
    ReadTask24(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c2 = _t[2];
        u64 v_c3 = _t[3];
        u64 v_c4 = _t[4];
        if (!slog::exists_probe<5,2>(pbranchindex0, std::array<u64,5>{v_c1, v_c2, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_diffindex1, std::array<u64,3>{v_c0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_diffindex2, std::array<u64,3>{v_c3, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_diffindex3, std::array<u64,3>{v_c4, 0, 0})) return;
        if (!slog::exists_probe<5,2>(st_bldindex4, std::array<u64,5>{v_c1, v_c2, 0, 0, 0})) return;
        slog::join_probe<7,4>($sup9688x136x0x0x0index5, std::array<u64,7>{v_c2, v_c1, v_c3, v_c4, 0, 0, 0}, [&](const std::array<u64,7>& m75) {
          u64 v_c5 = m75[4]; u64 v_c6 = m75[5]; u64 v_c7 = m75[6];
          if (!slog::exists_probe<3,2>(st_diffindex6, std::array<u64,3>{v_c0, v_c5, 0})) return;
          if (!slog::exists_probe<3,2>(st_diffindex7, std::array<u64,3>{v_c6, v_c3, 0})) return;
          if (!slog::exists_probe<3,2>(st_diffindex8, std::array<u64,3>{v_c7, v_c4, 0})) return;
          slog::join_probe_old<5,4>(pbranchindex9, pbranchdelta19, std::array<u64,5>{v_c1, v_c2, v_c6, v_c7, 0}, [&](const std::array<u64,5>& m76) {
            u64 v_c8 = m76[4];
            slog::join_probe_old<3,3>(st_diffindex10, st_diffdelta20, std::array<u64,3>{v_c5, v_c8, v_c0}, [&](const std::array<u64,3>& m77) {
              slog::join_probe_old<3,2>(st_diffindex11, st_diffdelta21, std::array<u64,3>{v_c6, v_c3, 0}, [&](const std::array<u64,3>& m78) {
                u64 v_c9 = m78[2];
                if (!slog::exists_probe<2,1>(st_diff_ansindex12, std::array<u64,2>{v_c9, 0})) return;
                slog::join_probe_old<3,2>(st_diffindex13, st_diffdelta22, std::array<u64,3>{v_c7, v_c4, 0}, [&](const std::array<u64,3>& m79) {
                  u64 v_c10 = m79[2];
                  if (!slog::exists_probe<2,1>(st_diff_ansindex14, std::array<u64,2>{v_c10, 0})) return;
                  slog::join_probe_old<5,2>(st_bldindex15, st_blddelta23, std::array<u64,5>{v_c1, v_c2, 0, 0, 0}, [&](const std::array<u64,5>& m80) {
                    u64 v_c11 = m80[2]; u64 v_c12 = m80[3]; u64 v_c13 = m80[4];
                    slog::join_probe<2,2>(st_diff_ansindex16, std::array<u64,2>{v_c9, v_c11}, [&](const std::array<u64,2>& m81) {
                      slog::join_probe<2,2>(st_diff_ansindex17, std::array<u64,2>{v_c10, v_c12}, [&](const std::array<u64,2>& m82) {
                        slog::join_probe<2,1>(st_bld_ansindex18, std::array<u64,2>{v_c13, 0}, [&](const std::array<u64,2>& m83) {
                          u64 v_c14 = m83[1];
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c5, v_c14}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("set.slog:137", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask24* _cont = new ReadTask24(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask24(db,b), false);
  // (crule (pre (let __tconst03UB810 conste3776bfed7f405de8017ecfa) (let __tconst71XF295 const6b86b273ff34fce19d6b804e)) (scan st_mem0 __t38OP294 t k) (body (join st_mem0_ans (0 1) 2 __t38OP294 __tconst71XF295) (exists pleaf (1 0) 1 k) (exists st_diff (2 0 1) 1 t) (join _enum (1 0) 1 __tconst03UB810 __t26at291) (join pleaf (1 0) 1 k __t1D2a292) (join st_diff (1 2 0) 2 __t1D2a292 t __t8FIc293)) (head (emit st_diff_ans (0 1) __t8FIc293 __t26at291)) set.slog:135 #f)
  class ReadTask90 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_mem0_ansindex84;  slog::Index** pleafindex85;  slog::Index** st_diffindex86;  slog::Index** _enumindex87;  slog::Index** pleafindex88;  slog::Index** st_diffindex89;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord91({0, 1});
      slog::Relation* readrel92 = db->getRelation("st_diff_ans");
      head_index[0] = readrel92->getIndex(ord91, false);
      outer_rel = db->getRelation("st_mem0");
      std::vector<u16> ord93({0, 1});
      slog::Relation* readrel94 = db->getRelation("st_mem0_ans");
      st_mem0_ansindex84 = readrel94->getIndex(ord93, false);
      std::vector<u16> ord95({1, 0});
      slog::Relation* readrel96 = db->getRelation("pleaf");
      pleafindex85 = readrel96->getIndex(ord95, false);
      std::vector<u16> ord97({2, 0, 1});
      slog::Relation* readrel98 = db->getRelation("st_diff");
      st_diffindex86 = readrel98->getIndex(ord97, false);
      std::vector<u16> ord99({1, 0});
      slog::Relation* readrel100 = db->getRelation("_enum");
      _enumindex87 = readrel100->getIndex(ord99, false);
      std::vector<u16> ord101({1, 0});
      slog::Relation* readrel102 = db->getRelation("pleaf");
      pleafindex88 = readrel102->getIndex(ord101, false);
      std::vector<u16> ord103({1, 2, 0});
      slog::Relation* readrel104 = db->getRelation("st_diff");
      st_diffindex89 = readrel104->getIndex(ord103, false);
  
    }
    ReadTask90(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c15 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c16 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c17 = _t[0];
        u64 v_c18 = _t[1];
        u64 v_c19 = _t[2];
        slog::join_probe<2,2>(st_mem0_ansindex84, std::array<u64,2>{v_c17, v_c16}, [&](const std::array<u64,2>& m105) {
          if (!slog::exists_probe<2,1>(pleafindex85, std::array<u64,2>{v_c19, 0})) return;
          if (!slog::exists_probe<3,1>(st_diffindex86, std::array<u64,3>{v_c18, 0, 0})) return;
          slog::join_probe<2,1>(_enumindex87, std::array<u64,2>{v_c15, 0}, [&](const std::array<u64,2>& m106) {
            u64 v_c20 = m106[1];
            slog::join_probe<2,1>(pleafindex88, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m107) {
              u64 v_c21 = m107[1];
              slog::join_probe<3,2>(st_diffindex89, std::array<u64,3>{v_c21, v_c18, 0}, [&](const std::array<u64,3>& m108) {
                u64 v_c22 = m108[2];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c22, v_c20}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:135", "delta:st_mem0", _fires);
  
      if (!_done)
      {
        ReadTask90* _cont = new ReadTask90(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask90(db,b), false);
  // (crule (pre (let __trid8g2r1050 const1e44311dd5d36c3a7dc21dfa) (let __trel89t41051 consta10f76b4ec574de5d7b6908e) (let __tcol1JzC1052 const5feceb66ffc86f38d952786c) (let __trel01u71053 consta10f76b4ec574de5d7b6908e) (let __tcol7ubM1054 const6b86b273ff34fce19d6b804e)) (scan $sup9688x90x0x0x0 __d0 k l m p r) (body) (head (tycheck k (accept int) __trid8g2r1050 __trel89t41051 __tcol1JzC1052 (1 2 3 4 0)) (tycheck m (accept int) __trid8g2r1050 __trel01u71053 __tcol7ubM1054 (1 2 3 4 0)) (mkstruct st_msk (1 2 0) __7afH1049 k m)) set.slog:91 #f)
  class ReadTask109 : public slog::Task
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
      outer_rel = db->getRelation("$sup9688x90x0x0x0");
  
    }
    ReadTask109(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c23 = v_const1e44311dd5d36c3a7dc21dfa;
      u64 v_c24 = v_consta10f76b4ec574de5d7b6908e;
      u64 v_c25 = v_const5feceb66ffc86f38d952786c;
      u64 v_c26 = v_consta10f76b4ec574de5d7b6908e;
      u64 v_c27 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c28 = _t[0];
        u64 v_c19 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c2 = _t[3];
        u64 v_c1 = _t[4];
        u64 v_c7 = _t[5];
        ++_fires;
        if (!(is_int(v_c19)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c23, v_c24, v_c25, v_c19}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c2)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c23, v_c26, v_c27, v_c2}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c19, v_c2}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("set.slog:91", "delta:$sup9688x90x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask109* _cont = new ReadTask109(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask109(db,b), false);
  // (crule (pre) (scan pbranch __t1mni474 p m l r) (body (join-old st_mem0 (1 2 0) 1 (1 2 0) __t1mni474 k __t0per475)) (head (emit $sup9688x69x0x0x0 (0 1 2 3 4 5) __t0per475 k l m p r)) set.slog:70 #f)
  class ReadTask112 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_mem0index110;  slog::Index** st_mem0delta111;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x69x0x0x0");
      std::vector<u16> ord113({0, 1, 2, 3, 4, 5});
      slog::Relation* readrel114 = db->getRelation("$sup9688x69x0x0x0");
      head_index[0] = readrel114->getIndex(ord113, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord115({1, 2, 0});
      slog::Relation* readrel116 = db->getRelation("st_mem0");
      st_mem0index110 = readrel116->getIndex(ord115, false);
      std::vector<u16> ord117({1, 2, 0});
      slog::Relation* readrel118 = db->getRelation("st_mem0");
      st_mem0delta111 = readrel118->getIndex(ord117, true);
  
    }
    ReadTask112(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c29 = _t[0];
        u64 v_c1 = _t[1];
        u64 v_c2 = _t[2];
        u64 v_c6 = _t[3];
        u64 v_c7 = _t[4];
        slog::join_probe_old<3,1>(st_mem0index110, st_mem0delta111, std::array<u64,3>{v_c29, 0, 0}, [&](const std::array<u64,3>& m119) {
          u64 v_c19 = m119[1]; u64 v_c30 = m119[2];
          ++_fires;
          slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c30, v_c19, v_c6, v_c2, v_c1, v_c7}, std::array<u16,6>{0, 1, 2, 3, 4, 5});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:70", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask112* _cont = new ReadTask112(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask112(db,b), false);
  // (crule (pre (let __tconst0eJ4499 const6b86b273ff34fce19d6b804e)) (scan st_diff __t557L498 __t5Gbs497 __t3WTc496) (body (join pbranch (0 1 2 3 4) 1 __t3WTc496 q n u v) (join pbranch (0 1 2 3 4) 1 __t5Gbs497 p m l r) (cmp lt m n) (let __t85kh500 (band p n)) (cmp lt __t85kh500 __tconst0eJ4499)) (head (emit $sup9688x148x0x0x0 (0 7 1 2 3 4 5 6 8) __t557L498 u l m n p q r v)) set.slog:149 #f)
  class ReadTask122 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex120;  slog::Index** pbranchindex121;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x148x0x0x0");
      std::vector<u16> ord123({0, 7, 1, 2, 3, 4, 5, 6, 8});
      slog::Relation* readrel124 = db->getRelation("$sup9688x148x0x0x0");
      head_index[0] = readrel124->getIndex(ord123, false);
      outer_rel = db->getRelation("st_diff");
      std::vector<u16> ord125({0, 1, 2, 3, 4});
      slog::Relation* readrel126 = db->getRelation("pbranch");
      pbranchindex120 = readrel126->getIndex(ord125, false);
      std::vector<u16> ord127({0, 1, 2, 3, 4});
      slog::Relation* readrel128 = db->getRelation("pbranch");
      pbranchindex121 = readrel128->getIndex(ord127, false);
  
    }
    ReadTask122(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c31 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c34 = _t[2];
        slog::join_probe<5,1>(pbranchindex120, std::array<u64,5>{v_c34, 0, 0, 0, 0}, [&](const std::array<u64,5>& m129) {
          u64 v_c35 = m129[1]; u64 v_c36 = m129[2]; u64 v_c3 = m129[3]; u64 v_c4 = m129[4];
          slog::join_probe<5,1>(pbranchindex121, std::array<u64,5>{v_c33, 0, 0, 0, 0}, [&](const std::array<u64,5>& m130) {
            u64 v_c1 = m130[1]; u64 v_c2 = m130[2]; u64 v_c6 = m130[3]; u64 v_c7 = m130[4];
            u64 v_c37 = _prim_lt(db, v_c2, v_c36);
            if (v_c37 == slog_error) { slog::emit_pending_error(db, "set.slog:149"); return; }
            if (!v_c37) return;
            u64 v_c38 = _prim_band(db, v_c1, v_c36);
            if (v_c38 == slog_error) { slog::emit_pending_error(db, "set.slog:149"); return; }
            u64 v_c39 = _prim_lt(db, v_c38, v_c31);
            if (v_c39 == slog_error) { slog::emit_pending_error(db, "set.slog:149"); return; }
            if (!v_c39) return;
            ++_fires;
            slog::emit<9>(head_rel[0], head_index[0], newbatch[0], std::array<u64,9>{v_c32, v_c3, v_c6, v_c2, v_c36, v_c1, v_c35, v_c7, v_c4}, std::array<u16,9>{0, 7, 1, 2, 3, 4, 5, 6, 8});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:149", "delta:st_diff", _fires);
  
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
  // (crule (pre (let __tconst63YF62 const6b86b273ff34fce19d6b804e)) (scan pbranch __t5Obr65 p m l r) (body (exists $sup9688x114x0x0x1 (2 3 5 7 0 1 4 6 8 9) 4 l m p r) (exists st_union (1 2 0) 1 __t5Obr65) (exists st_msk (1 2 0) 1 p) (join $sup9688x114x0x0x0 (1 2 4 6 0 3 5 7 8) 4 l m p r __t2j0W61 n q u v) (cmp lt m n) (exists pbranch (1 2 3 4 0) 4 q n u v) (exists st_union (0 1 2) 2 __t2j0W61 __t5Obr65) (exists st_msk (1 2 0) 2 p n) (exists st_msk_ans (1 0) 1 q) (exists st_union (1 2 0) 2 __t5Obr65 u) (join $sup9688x114x0x0x1 (8 4 6 9 0 2 3 5 7 1) 9 u n q v __t2j0W61 l m p r __t1Zy964) (exists st_msk (1 2 0) 3 p n __t1Zy964) (exists st_msk_ans (0 1) 2 __t1Zy964 q) (join pbranch (1 2 3 4 0) 4 q n u v __t2ifW59) (join st_union (0 1 2) 3 __t2j0W61 __t5Obr65 __t2ifW59) (join st_msk (1 2 0) 3 p n __t1Zy964) (join st_msk_ans (0 1) 2 __t1Zy964 q) (join-old st_union (1 2 0) 2 (1 2 0) __t5Obr65 u __t6dzp66) (join st_union_ans (0 1) 1 __t6dzp66 __v0) (let __t3h5j63 (band p n)) (cmp lt __t3h5j63 __tconst63YF62)) (head (emit-temp temp1Dk71281 __t2j0W61 __v0 n q v) (mkstruct pbranch (1 2 3 4 0) __t0srE58 q n __v0 v)) set.slog:115 #f)
  class ReadTask152 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x114x0x0x1index133;  slog::Index** st_unionindex134;  slog::Index** st_mskindex135;  slog::Index** $sup9688x114x0x0x0index136;  slog::Index** pbranchindex137;  slog::Index** st_unionindex138;  slog::Index** st_mskindex139;  slog::Index** st_msk_ansindex140;  slog::Index** st_unionindex141;  slog::Index** $sup9688x114x0x0x1index142;  slog::Index** st_mskindex143;  slog::Index** st_msk_ansindex144;  slog::Index** pbranchindex145;  slog::Index** st_unionindex146;  slog::Index** st_mskindex147;  slog::Index** st_msk_ansindex148;  slog::Index** st_unionindex149;  slog::Index** st_union_ansindex150;  slog::Index** st_uniondelta151;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp1Dk71281");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord153({2, 3, 5, 7, 0, 1, 4, 6, 8, 9});
      slog::Relation* readrel154 = db->getRelation("$sup9688x114x0x0x1");
      $sup9688x114x0x0x1index133 = readrel154->getIndex(ord153, false);
      std::vector<u16> ord155({1, 2, 0});
      slog::Relation* readrel156 = db->getRelation("st_union");
      st_unionindex134 = readrel156->getIndex(ord155, false);
      std::vector<u16> ord157({1, 2, 0});
      slog::Relation* readrel158 = db->getRelation("st_msk");
      st_mskindex135 = readrel158->getIndex(ord157, false);
      std::vector<u16> ord159({1, 2, 4, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel160 = db->getRelation("$sup9688x114x0x0x0");
      $sup9688x114x0x0x0index136 = readrel160->getIndex(ord159, false);
      std::vector<u16> ord161({1, 2, 3, 4, 0});
      slog::Relation* readrel162 = db->getRelation("pbranch");
      pbranchindex137 = readrel162->getIndex(ord161, false);
      std::vector<u16> ord163({0, 1, 2});
      slog::Relation* readrel164 = db->getRelation("st_union");
      st_unionindex138 = readrel164->getIndex(ord163, false);
      std::vector<u16> ord165({1, 2, 0});
      slog::Relation* readrel166 = db->getRelation("st_msk");
      st_mskindex139 = readrel166->getIndex(ord165, false);
      std::vector<u16> ord167({1, 0});
      slog::Relation* readrel168 = db->getRelation("st_msk_ans");
      st_msk_ansindex140 = readrel168->getIndex(ord167, false);
      std::vector<u16> ord169({1, 2, 0});
      slog::Relation* readrel170 = db->getRelation("st_union");
      st_unionindex141 = readrel170->getIndex(ord169, false);
      std::vector<u16> ord171({8, 4, 6, 9, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel172 = db->getRelation("$sup9688x114x0x0x1");
      $sup9688x114x0x0x1index142 = readrel172->getIndex(ord171, false);
      std::vector<u16> ord173({1, 2, 0});
      slog::Relation* readrel174 = db->getRelation("st_msk");
      st_mskindex143 = readrel174->getIndex(ord173, false);
      std::vector<u16> ord175({0, 1});
      slog::Relation* readrel176 = db->getRelation("st_msk_ans");
      st_msk_ansindex144 = readrel176->getIndex(ord175, false);
      std::vector<u16> ord177({1, 2, 3, 4, 0});
      slog::Relation* readrel178 = db->getRelation("pbranch");
      pbranchindex145 = readrel178->getIndex(ord177, false);
      std::vector<u16> ord179({0, 1, 2});
      slog::Relation* readrel180 = db->getRelation("st_union");
      st_unionindex146 = readrel180->getIndex(ord179, false);
      std::vector<u16> ord181({1, 2, 0});
      slog::Relation* readrel182 = db->getRelation("st_msk");
      st_mskindex147 = readrel182->getIndex(ord181, false);
      std::vector<u16> ord183({0, 1});
      slog::Relation* readrel184 = db->getRelation("st_msk_ans");
      st_msk_ansindex148 = readrel184->getIndex(ord183, false);
      std::vector<u16> ord185({1, 2, 0});
      slog::Relation* readrel186 = db->getRelation("st_union");
      st_unionindex149 = readrel186->getIndex(ord185, false);
      std::vector<u16> ord187({1, 2, 0});
      slog::Relation* readrel188 = db->getRelation("st_union");
      st_uniondelta151 = readrel188->getIndex(ord187, true);
      std::vector<u16> ord189({0, 1});
      slog::Relation* readrel190 = db->getRelation("st_union_ans");
      st_union_ansindex150 = readrel190->getIndex(ord189, false);
  
    }
    ReadTask152(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c40 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c1 = _t[1];
        u64 v_c2 = _t[2];
        u64 v_c6 = _t[3];
        u64 v_c7 = _t[4];
        if (!slog::exists_probe<10,4>($sup9688x114x0x0x1index133, std::array<u64,10>{v_c6, v_c2, v_c1, v_c7, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_unionindex134, std::array<u64,3>{v_c41, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mskindex135, std::array<u64,3>{v_c1, 0, 0})) return;
        slog::join_probe<9,4>($sup9688x114x0x0x0index136, std::array<u64,9>{v_c6, v_c2, v_c1, v_c7, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m191) {
          u64 v_c42 = m191[4]; u64 v_c36 = m191[5]; u64 v_c35 = m191[6]; u64 v_c3 = m191[7]; u64 v_c4 = m191[8];
          u64 v_c43 = _prim_lt(db, v_c2, v_c36);
          if (v_c43 == slog_error) { slog::emit_pending_error(db, "set.slog:115"); return; }
          if (!v_c43) return;
          if (!slog::exists_probe<5,4>(pbranchindex137, std::array<u64,5>{v_c35, v_c36, v_c3, v_c4, 0})) return;
          if (!slog::exists_probe<3,2>(st_unionindex138, std::array<u64,3>{v_c42, v_c41, 0})) return;
          if (!slog::exists_probe<3,2>(st_mskindex139, std::array<u64,3>{v_c1, v_c36, 0})) return;
          if (!slog::exists_probe<2,1>(st_msk_ansindex140, std::array<u64,2>{v_c35, 0})) return;
          if (!slog::exists_probe<3,2>(st_unionindex141, std::array<u64,3>{v_c41, v_c3, 0})) return;
          slog::join_probe<10,9>($sup9688x114x0x0x1index142, std::array<u64,10>{v_c3, v_c36, v_c35, v_c4, v_c42, v_c6, v_c2, v_c1, v_c7, 0}, [&](const std::array<u64,10>& m193) {
            u64 v_c44 = m193[9];
            if (!slog::exists_probe<3,3>(st_mskindex143, std::array<u64,3>{v_c1, v_c36, v_c44})) return;
            if (!slog::exists_probe<2,2>(st_msk_ansindex144, std::array<u64,2>{v_c44, v_c35})) return;
            slog::join_probe<5,4>(pbranchindex145, std::array<u64,5>{v_c35, v_c36, v_c3, v_c4, 0}, [&](const std::array<u64,5>& m194) {
              u64 v_c45 = m194[4];
              slog::join_probe<3,3>(st_unionindex146, std::array<u64,3>{v_c42, v_c41, v_c45}, [&](const std::array<u64,3>& m195) {
                slog::join_probe<3,3>(st_mskindex147, std::array<u64,3>{v_c1, v_c36, v_c44}, [&](const std::array<u64,3>& m196) {
                  slog::join_probe<2,2>(st_msk_ansindex148, std::array<u64,2>{v_c44, v_c35}, [&](const std::array<u64,2>& m197) {
                    slog::join_probe_old<3,2>(st_unionindex149, st_uniondelta151, std::array<u64,3>{v_c41, v_c3, 0}, [&](const std::array<u64,3>& m198) {
                      u64 v_c46 = m198[2];
                      slog::join_probe<2,1>(st_union_ansindex150, std::array<u64,2>{v_c46, 0}, [&](const std::array<u64,2>& m199) {
                        u64 v_c11 = m199[1];
                        u64 v_c47 = _prim_band(db, v_c1, v_c36);
                        if (v_c47 == slog_error) { slog::emit_pending_error(db, "set.slog:115"); return; }
                        u64 v_c48 = _prim_lt(db, v_c47, v_c40);
                        if (v_c48 == slog_error) { slog::emit_pending_error(db, "set.slog:115"); return; }
                        if (!v_c48) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c42, v_c11, v_c36, v_c35, v_c4});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c35, v_c36, v_c11, v_c4}, std::array<u16,5>{1, 2, 3, 4, 0});
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
        ReadTask152* _cont = new ReadTask152(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask152(db,b), false);
  // (crule (pre (let _00024sqc3E2A583 const6b86b273ff34fce19d6b804e) (let _00024sqc4KkP584 const5feceb66ffc86f38d952786c) (let _00024sqc0Eej585 const6b86b273ff34fce19d6b804e) (let _00024sqc1Y6T586 const5feceb66ffc86f38d952786c) (let __trid8HrV778 const6235871e739625dd33ac2813) (let __trel9Eaq779 const99e1cbf3d792d4a87847a801) (let __tcol9IWV780 const6b86b273ff34fce19d6b804e)) (scan st_fromlist_ans __t3Nxu152 __v0) (body (join st_fromlist (0 1) 1 __t3Nxu152 xs) (join $sup9688x168x0x0x0 (3 0 1 2) 1 xs _00024seq0 __d0 x) (letp _00024sql4Qqe581 (aslst _00024seq0)) (let _00024sqn3ACa582 (llen _00024sql4Qqe581)) (cmp ge _00024sqn3ACa582 _00024sqc3E2A583) (letp chk5VAP1400 (lref _00024sql4Qqe581 _00024sqc4KkP584)) (eq x chk5VAP1400) (let _00024sqp4Sey587 (_0002d _00024sqn3ACa582 _00024sqc1Y6T586)) (let chk6dai1401 (lslice _00024sql4Qqe581 _00024sqc0Eej585 _00024sqp4Sey587)) (eq xs chk6dai1401)) (head (tycheck x (accept int) __trid8HrV778 __trel9Eaq779 __tcol9IWV780 (1 2 3 4 0)) (mkstruct st_ins (1 2 0) __9ltz777 __v0 x)) set.slog:169 #f)
  class ReadTask203 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_fromlistindex201;  slog::Index** $sup9688x168x0x0x0index202;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("st_ins");
      outer_rel = db->getRelation("st_fromlist_ans");
      std::vector<u16> ord204({0, 1});
      slog::Relation* readrel205 = db->getRelation("st_fromlist");
      st_fromlistindex201 = readrel205->getIndex(ord204, false);
      std::vector<u16> ord206({3, 0, 1, 2});
      slog::Relation* readrel207 = db->getRelation("$sup9688x168x0x0x0");
      $sup9688x168x0x0x0index202 = readrel207->getIndex(ord206, false);
  
    }
    ReadTask203(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c49 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c50 = v_const5feceb66ffc86f38d952786c;
      u64 v_c51 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c52 = v_const5feceb66ffc86f38d952786c;
      u64 v_c53 = v_const6235871e739625dd33ac2813;
      u64 v_c54 = v_const99e1cbf3d792d4a87847a801;
      u64 v_c55 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c56 = _t[0];
        u64 v_c11 = _t[1];
        slog::join_probe<2,1>(st_fromlistindex201, std::array<u64,2>{v_c56, 0}, [&](const std::array<u64,2>& m208) {
          u64 v_c57 = m208[1];
          slog::join_probe<4,1>($sup9688x168x0x0x0index202, std::array<u64,4>{v_c57, 0, 0, 0}, [&](const std::array<u64,4>& m209) {
            u64 v_c58 = m209[1]; u64 v_c28 = m209[2]; u64 v_c59 = m209[3];
            bool ok210 = true;
            u64 v_c60 = _prim_aslst(db, v_c58, &ok210);
            if (!ok210) return;
            u64 v_c61 = _prim_llen(db, v_c60);
            if (v_c61 == slog_error) { slog::emit_pending_error(db, "set.slog:169"); return; }
            u64 v_c62 = _prim_ge(db, v_c61, v_c49);
            if (v_c62 == slog_error) { slog::emit_pending_error(db, "set.slog:169"); return; }
            if (!v_c62) return;
            bool ok212 = true;
            u64 v_c63 = _prim_lref(db, v_c60, v_c50, &ok212);
            if (!ok212) return;
            if (v_c59 != v_c63) return;
            u64 v_c64 = _prim__0002d(db, v_c61, v_c52);
            if (v_c64 == slog_error) { slog::emit_pending_error(db, "set.slog:169"); return; }
            u64 v_c65 = _prim_lslice(db, v_c60, v_c51, v_c64);
            if (v_c65 == slog_error) { slog::emit_pending_error(db, "set.slog:169"); return; }
            if (v_c57 != v_c65) return;
            ++_fires;
            if (!(is_int(v_c59)))
            {
              slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c53, v_c54, v_c55, v_c59}, std::array<u16,5>{1, 2, 3, 4, 0});
              return;
            }
            slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c11, v_c59}, std::array<u16,3>{1, 2, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("set.slog:169", "delta:st_fromlist_ans", _fires);
  
      if (!_done)
      {
        ReadTask203* _cont = new ReadTask203(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask203(db,b), false);
  // (crule (pre (let __trid0O8l910 const1e44311dd5d36c3a7dc21dfa) (let __trel2X7j911 const26c89ee8ccc4ea998fd1a912) (let __tcol3tdZ912 constd4735e3a265e16eee03f5971)) (scan st_msk_ans __t8Ytg398 p) (body (exists $sup9688x90x0x0x0 (4 2 3 5 0 1) 1 p) (join-old st_msk (0 1 2) 1 (0 1 2) __t8Ytg398 k m) (exists st_del (2 0 1) 1 k) (join $sup9688x90x0x0x0 (1 3 4 0 2 5) 3 k m p __d0 l r) (join-old st_del (1 2 0) 2 (1 2 0) r k __t56Eo399) (join-old st_del_ans (0 1) 1 (0 1) __t56Eo399 __v0)) (head (tycheck l (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid0O8l910 __trel2X7j911 __tcol3tdZ912 (1 2 3 4 0)) (mkstruct st_bld (1 2 3 4 0) __6yFQ909 p m l __v0)) set.slog:91 #f)
  class ReadTask225 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x90x0x0x0index213;  slog::Index** st_mskindex214;  slog::Index** st_delindex215;  slog::Index** $sup9688x90x0x0x0index216;  slog::Index** st_delindex217;  slog::Index** st_del_ansindex218;  slog::Index** st_mskdelta219;  slog::Index** st_deldelta220;  slog::Index** st_del_ansdelta221;
    u32 sid223;  u32 sid222;  u32 sid224;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("st_bld");
      outer_rel = db->getRelation("st_msk_ans");
      std::vector<u16> ord226({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel227 = db->getRelation("$sup9688x90x0x0x0");
      $sup9688x90x0x0x0index213 = readrel227->getIndex(ord226, false);
      std::vector<u16> ord228({0, 1, 2});
      slog::Relation* readrel229 = db->getRelation("st_msk");
      st_mskindex214 = readrel229->getIndex(ord228, false);
      std::vector<u16> ord230({0, 1, 2});
      slog::Relation* readrel231 = db->getRelation("st_msk");
      st_mskdelta219 = readrel231->getIndex(ord230, true);
      std::vector<u16> ord232({2, 0, 1});
      slog::Relation* readrel233 = db->getRelation("st_del");
      st_delindex215 = readrel233->getIndex(ord232, false);
      std::vector<u16> ord234({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel235 = db->getRelation("$sup9688x90x0x0x0");
      $sup9688x90x0x0x0index216 = readrel235->getIndex(ord234, false);
      std::vector<u16> ord236({1, 2, 0});
      slog::Relation* readrel237 = db->getRelation("st_del");
      st_delindex217 = readrel237->getIndex(ord236, false);
      std::vector<u16> ord238({1, 2, 0});
      slog::Relation* readrel239 = db->getRelation("st_del");
      st_deldelta220 = readrel239->getIndex(ord238, true);
      std::vector<u16> ord240({0, 1});
      slog::Relation* readrel241 = db->getRelation("st_del_ans");
      st_del_ansindex218 = readrel241->getIndex(ord240, false);
      std::vector<u16> ord242({0, 1});
      slog::Relation* readrel243 = db->getRelation("st_del_ans");
      st_del_ansdelta221 = readrel243->getIndex(ord242, true);
      sid223 = db->getRelation("_enum")->getStructId();
      sid222 = db->getRelation("pbranch")->getStructId();
      sid224 = db->getRelation("pleaf")->getStructId();
  
    }
    ReadTask225(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c66 = v_const1e44311dd5d36c3a7dc21dfa;
      u64 v_c67 = v_const26c89ee8ccc4ea998fd1a912;
      u64 v_c68 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c69 = _t[0];
        u64 v_c1 = _t[1];
        if (!slog::exists_probe<6,1>($sup9688x90x0x0x0index213, std::array<u64,6>{v_c1, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(st_mskindex214, st_mskdelta219, std::array<u64,3>{v_c69, 0, 0}, [&](const std::array<u64,3>& m244) {
          u64 v_c19 = m244[1]; u64 v_c2 = m244[2];
          if (!slog::exists_probe<3,1>(st_delindex215, std::array<u64,3>{v_c19, 0, 0})) return;
          slog::join_probe<6,3>($sup9688x90x0x0x0index216, std::array<u64,6>{v_c19, v_c2, v_c1, 0, 0, 0}, [&](const std::array<u64,6>& m245) {
            u64 v_c28 = m245[3]; u64 v_c6 = m245[4]; u64 v_c7 = m245[5];
            slog::join_probe_old<3,2>(st_delindex217, st_deldelta220, std::array<u64,3>{v_c7, v_c19, 0}, [&](const std::array<u64,3>& m246) {
              u64 v_c70 = m246[2];
              slog::join_probe_old<2,1>(st_del_ansindex218, st_del_ansdelta221, std::array<u64,2>{v_c70, 0}, [&](const std::array<u64,2>& m247) {
                u64 v_c11 = m247[1];
                ++_fires;
                if (!((is_struct(v_c6) && (decode_struct_id(v_c6) == sid222 || decode_struct_id(v_c6) == sid223 || decode_struct_id(v_c6) == sid224))))
                {
                  slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c66, v_c67, v_c68, v_c6}, std::array<u16,5>{1, 2, 3, 4, 0});
                  return;
                }
                slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c1, v_c2, v_c6, v_c11}, std::array<u16,5>{1, 2, 3, 4, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("set.slog:91", "delta:st_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask225* _cont = new ReadTask225(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask225(db,b), false);
  // (crule (pre (let _00024sqc6FSA620 const4b227777d4dd1fc61c6f884f) (let _00024sqc3Ub8621 const5feceb66ffc86f38d952786c) (let _00024sqc1TCF622 const6b86b273ff34fce19d6b804e) (let _00024sqc3FMQ623 const6b86b273ff34fce19d6b804e) (let _00024sqc41K7624 const2c624232cdd221771294dfbb) (let _00024sqc6uPA625 constd4735e3a265e16eee03f5971) (let _00024sqc9VIm626 constd4735e3a265e16eee03f5971) (let _00024sqc7Q1B627 const4e07408562bedb8b60ce05c1) (let _00024sqc4nIn628 constef2d127de37b942baad06145) (let _00024sqo09Ee630 const6b86b273ff34fce19d6b804e) (let _00024sqo5YJw629 const5feceb66ffc86f38d952786c) (let _00024sqo1RnK632 const2c624232cdd221771294dfbb) (let _00024sqo5bHs631 const6b86b273ff34fce19d6b804e) (let _00024sqo2z3g634 constd4735e3a265e16eee03f5971) (let _00024sqo0Hmn633 constd4735e3a265e16eee03f5971) (let _00024sqo7Xdh636 constef2d127de37b942baad06145) (let _00024sqo5nmm635 const4e07408562bedb8b60ce05c1) (let _00024sqo4nJm638 const6b86b273ff34fce19d6b804e) (let _00024sqo7qJs637 const4e07408562bedb8b60ce05c1) (let _00024sqo4dTI640 const2c624232cdd221771294dfbb) (let _00024sqo4MMk639 constd4735e3a265e16eee03f5971) (let _00024sqo3whL642 constd4735e3a265e16eee03f5971) (let _00024sqo9zLj641 const6b86b273ff34fce19d6b804e) (let _00024sqo1Fkt644 constef2d127de37b942baad06145) (let _00024sqo2E1m643 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 2 _00024sqo0Hmn633 _00024sqo2z3g634 _00024seq0) (body (join $seq_at (1 0 2) 3 _00024sqo5YJw629 _00024sqo09Ee630 _00024seq0) (join $seq_at (1 0 2) 3 _00024sqo5bHs631 _00024sqo1RnK632 _00024seq0) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo5nmm635 _00024sqo7Xdh636 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo4nJm638 _00024sqo7qJs637 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo4dTI640 _00024sqo4MMk639 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo3whL642 _00024sqo9zLj641 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo1Fkt644 _00024sqo2E1m643 _00024seq0) (join st_fromlist (1 0) 1 _00024seq0 __t2iar332) (join st_fromlist_ans (0 1) 1 __t2iar332 r) (letp _00024sql7znl618 (aslst _00024seq0)) (let chk8ClI1369 (llen _00024sql7znl618)) (eq _00024sqc6FSA620 chk8ClI1369) (letp chk9AGc1370 (lref _00024sql7znl618 _00024sqc3Ub8621)) (eq _00024sqc1TCF622 chk9AGc1370) (letp chk7gCa1371 (lref _00024sql7znl618 _00024sqc3FMQ623)) (eq _00024sqc41K7624 chk7gCa1371) (letp chk5zJi1372 (lref _00024sql7znl618 _00024sqc6uPA625)) (eq _00024sqc9VIm626 chk5zJi1372) (letp chk2p311373 (lref _00024sql7znl618 _00024sqc7Q1B627)) (eq _00024sqc4nIn628 chk2p311373)) (head (emit canon (0) r)) st_basic.slog:17 #f)
  class ReadTask262 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex248;  slog::Index** $seq_atindex249;  slog::Index** $seq_atindex250;  slog::Index** $seq_atrindex251;  slog::Index** $seq_atrindex252;  slog::Index** $seq_atrindex253;  slog::Index** $seq_atrindex254;  slog::Index** st_fromlistindex255;  slog::Index** st_fromlist_ansindex256;  slog::Index** $seq_atdelta257;  slog::Index** $seq_atrdelta258;  slog::Index** $seq_atrdelta259;  slog::Index** $seq_atrdelta260;  slog::Index** $seq_atrdelta261;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("canon");
      std::vector<u16> ord263({0});
      slog::Relation* readrel264 = db->getRelation("canon");
      head_index[0] = readrel264->getIndex(ord263, false);
      std::vector<u16> ord265({1, 0, 2});
      slog::Relation* readrel266 = db->getRelation("$seq_at");
      driver_index = readrel266->getIndex(ord265, true);
      std::vector<u16> ord267({1, 0, 2});
      slog::Relation* readrel268 = db->getRelation("$seq_at");
      $seq_atindex248 = readrel268->getIndex(ord267, false);
      std::vector<u16> ord269({1, 0, 2});
      slog::Relation* readrel270 = db->getRelation("$seq_at");
      $seq_atindex249 = readrel270->getIndex(ord269, false);
      std::vector<u16> ord271({1, 0, 2});
      slog::Relation* readrel272 = db->getRelation("$seq_at");
      $seq_atindex250 = readrel272->getIndex(ord271, false);
      std::vector<u16> ord273({1, 0, 2});
      slog::Relation* readrel274 = db->getRelation("$seq_at");
      $seq_atdelta257 = readrel274->getIndex(ord273, true);
      std::vector<u16> ord275({0, 1, 2});
      slog::Relation* readrel276 = db->getRelation("$seq_atr");
      $seq_atrindex251 = readrel276->getIndex(ord275, false);
      std::vector<u16> ord277({0, 1, 2});
      slog::Relation* readrel278 = db->getRelation("$seq_atr");
      $seq_atrdelta258 = readrel278->getIndex(ord277, true);
      std::vector<u16> ord279({0, 1, 2});
      slog::Relation* readrel280 = db->getRelation("$seq_atr");
      $seq_atrindex252 = readrel280->getIndex(ord279, false);
      std::vector<u16> ord281({0, 1, 2});
      slog::Relation* readrel282 = db->getRelation("$seq_atr");
      $seq_atrdelta259 = readrel282->getIndex(ord281, true);
      std::vector<u16> ord283({0, 1, 2});
      slog::Relation* readrel284 = db->getRelation("$seq_atr");
      $seq_atrindex253 = readrel284->getIndex(ord283, false);
      std::vector<u16> ord285({0, 1, 2});
      slog::Relation* readrel286 = db->getRelation("$seq_atr");
      $seq_atrdelta260 = readrel286->getIndex(ord285, true);
      std::vector<u16> ord287({0, 1, 2});
      slog::Relation* readrel288 = db->getRelation("$seq_atr");
      $seq_atrindex254 = readrel288->getIndex(ord287, false);
      std::vector<u16> ord289({0, 1, 2});
      slog::Relation* readrel290 = db->getRelation("$seq_atr");
      $seq_atrdelta261 = readrel290->getIndex(ord289, true);
      std::vector<u16> ord291({1, 0});
      slog::Relation* readrel292 = db->getRelation("st_fromlist");
      st_fromlistindex255 = readrel292->getIndex(ord291, false);
      std::vector<u16> ord293({0, 1});
      slog::Relation* readrel294 = db->getRelation("st_fromlist_ans");
      st_fromlist_ansindex256 = readrel294->getIndex(ord293, false);
  
    }
    ReadTask262(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c71 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c72 = v_const5feceb66ffc86f38d952786c;
      u64 v_c73 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c74 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c75 = v_const2c624232cdd221771294dfbb;
      u64 v_c76 = v_constd4735e3a265e16eee03f5971;
      u64 v_c77 = v_constd4735e3a265e16eee03f5971;
      u64 v_c78 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c79 = v_constef2d127de37b942baad06145;
      u64 v_c80 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c81 = v_const5feceb66ffc86f38d952786c;
      u64 v_c82 = v_const2c624232cdd221771294dfbb;
      u64 v_c83 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c84 = v_constd4735e3a265e16eee03f5971;
      u64 v_c85 = v_constd4735e3a265e16eee03f5971;
      u64 v_c86 = v_constef2d127de37b942baad06145;
      u64 v_c87 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c88 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c89 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c90 = v_const2c624232cdd221771294dfbb;
      u64 v_c91 = v_constd4735e3a265e16eee03f5971;
      u64 v_c92 = v_constd4735e3a265e16eee03f5971;
      u64 v_c93 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c94 = v_constef2d127de37b942baad06145;
      u64 v_c95 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c85, v_c84, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m295) {
        u64 v_c58 = m295[2];
        if (buckethash(v_c58) != bucket) return;
        slog::join_probe<3,3>($seq_atindex248, std::array<u64,3>{v_c81, v_c80, v_c58}, [&](const std::array<u64,3>& m296) {
          slog::join_probe<3,3>($seq_atindex249, std::array<u64,3>{v_c83, v_c82, v_c58}, [&](const std::array<u64,3>& m297) {
            slog::join_probe_old<3,3>($seq_atindex250, $seq_atdelta257, std::array<u64,3>{v_c87, v_c86, v_c58}, [&](const std::array<u64,3>& m298) {
              slog::join_probe_old<3,3>($seq_atrindex251, $seq_atrdelta258, std::array<u64,3>{v_c88, v_c89, v_c58}, [&](const std::array<u64,3>& m299) {
                slog::join_probe_old<3,3>($seq_atrindex252, $seq_atrdelta259, std::array<u64,3>{v_c90, v_c91, v_c58}, [&](const std::array<u64,3>& m300) {
                  slog::join_probe_old<3,3>($seq_atrindex253, $seq_atrdelta260, std::array<u64,3>{v_c92, v_c93, v_c58}, [&](const std::array<u64,3>& m301) {
                    slog::join_probe_old<3,3>($seq_atrindex254, $seq_atrdelta261, std::array<u64,3>{v_c94, v_c95, v_c58}, [&](const std::array<u64,3>& m302) {
                      slog::join_probe<2,1>(st_fromlistindex255, std::array<u64,2>{v_c58, 0}, [&](const std::array<u64,2>& m303) {
                        u64 v_c96 = m303[1];
                        slog::join_probe<2,1>(st_fromlist_ansindex256, std::array<u64,2>{v_c96, 0}, [&](const std::array<u64,2>& m304) {
                          u64 v_c7 = m304[1];
                          bool ok305 = true;
                          u64 v_c97 = _prim_aslst(db, v_c58, &ok305);
                          if (!ok305) return;
                          u64 v_c98 = _prim_llen(db, v_c97);
                          if (v_c98 == slog_error) { slog::emit_pending_error(db, "st_basic.slog:17"); return; }
                          if (v_c71 != v_c98) return;
                          bool ok306 = true;
                          u64 v_c99 = _prim_lref(db, v_c97, v_c72, &ok306);
                          if (!ok306) return;
                          if (v_c73 != v_c99) return;
                          bool ok307 = true;
                          u64 v_c100 = _prim_lref(db, v_c97, v_c74, &ok307);
                          if (!ok307) return;
                          if (v_c75 != v_c100) return;
                          bool ok308 = true;
                          u64 v_c101 = _prim_lref(db, v_c97, v_c76, &ok308);
                          if (!ok308) return;
                          if (v_c77 != v_c101) return;
                          bool ok309 = true;
                          u64 v_c102 = _prim_lref(db, v_c97, v_c78, &ok309);
                          if (!ok309) return;
                          if (v_c79 != v_c102) return;
                          ++_fires;
                          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c7}, std::array<u16,1>{0});
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
        ReadTask262* _cont = new ReadTask262(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask262(db,b), false);
  // (crule (pre (let __trid9MGf873 constd2ed9ad006724fa952709457) (let __trel0REP874 consta10f76b4ec574de5d7b6908e) (let __tcol8Yrb875 const5feceb66ffc86f38d952786c) (let __trel1khO876 consta10f76b4ec574de5d7b6908e) (let __tcol3oWa877 const6b86b273ff34fce19d6b804e)) (scan $sup9688x69x0x0x0 __d0 k l m p r) (body) (head (tycheck k (accept int) __trid9MGf873 __trel0REP874 __tcol8Yrb875 (1 2 3 4 0)) (tycheck m (accept int) __trid9MGf873 __trel1khO876 __tcol3oWa877 (1 2 3 4 0)) (mkstruct st_msk (1 2 0) __8MI9872 k m)) set.slog:70 #f)
  class ReadTask310 : public slog::Task
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
      outer_rel = db->getRelation("$sup9688x69x0x0x0");
  
    }
    ReadTask310(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c103 = v_constd2ed9ad006724fa952709457;
      u64 v_c104 = v_consta10f76b4ec574de5d7b6908e;
      u64 v_c105 = v_const5feceb66ffc86f38d952786c;
      u64 v_c106 = v_consta10f76b4ec574de5d7b6908e;
      u64 v_c107 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c28 = _t[0];
        u64 v_c19 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c2 = _t[3];
        u64 v_c1 = _t[4];
        u64 v_c7 = _t[5];
        ++_fires;
        if (!(is_int(v_c19)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c103, v_c104, v_c105, v_c19}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c2)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c103, v_c106, v_c107, v_c2}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c19, v_c2}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("set.slog:70", "delta:$sup9688x69x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask310* _cont = new ReadTask310(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask310(db,b), false);
  // (crule (pre (let __tconst8weT1062 conste3776bfed7f405de8017ecfa)) (scan st_diff __t6ijb559 __t9s61558 t) (body (join _enum (0 1) 2 __t9s61558 __tconst8weT1062)) (head (emit st_diff_ans (0 1) __t6ijb559 __t9s61558)) set.slog:132 #f)
  class ReadTask312 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex311;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord313({0, 1});
      slog::Relation* readrel314 = db->getRelation("st_diff_ans");
      head_index[0] = readrel314->getIndex(ord313, false);
      outer_rel = db->getRelation("st_diff");
      std::vector<u16> ord315({0, 1});
      slog::Relation* readrel316 = db->getRelation("_enum");
      _enumindex311 = readrel316->getIndex(ord315, false);
  
    }
    ReadTask312(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c108 = v_conste3776bfed7f405de8017ecfa;
  
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
        u64 v_c18 = _t[2];
        slog::join_probe<2,2>(_enumindex311, std::array<u64,2>{v_c110, v_c108}, [&](const std::array<u64,2>& m317) {
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c109, v_c110}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:132", "delta:st_diff", _fires);
  
      if (!_done)
      {
        ReadTask312* _cont = new ReadTask312(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask312(db,b), false);
  // (crule (pre) (scan pbranch __t22FG286 p m u v) (body (exists pbranch (1 2 3 4 0) 2 p m) (exists st_union (2 0 1) 1 __t22FG286) (exists st_union (2 0 1) 1 u) (exists st_union (2 0 1) 1 v) (join $sup9688x100x0x0x0 (2 3 5 6 0 1 4) 4 m p u v __t2Q3U288 l r) (exists st_union (2 0 1) 2 __t22FG286 __t2Q3U288) (exists st_union (1 2 0) 2 l u) (exists st_union (1 2 0) 2 r v) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t1pUK287) (join-old st_union (0 1 2) 3 (0 1 2) __t2Q3U288 __t1pUK287 __t22FG286) (join-old st_union (1 2 0) 2 (1 2 0) l u __t1gnX289) (exists st_union_ans (0 1) 1 __t1gnX289) (join-old st_union (1 2 0) 2 (1 2 0) r v __t8LsM290) (exists st_union_ans (0 1) 1 __t8LsM290) (join st_union_ans (0 1) 1 __t1gnX289 __v0) (join st_union_ans (0 1) 1 __t8LsM290 __v1)) (head (emit-temp temp6bMv1274 __t2Q3U288 __v0 __v1 m p) (mkstruct pbranch (1 2 3 4 0) __t6nPF285 p m __v0 __v1)) set.slog:101 #f)
  class ReadTask338 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex318;  slog::Index** st_unionindex319;  slog::Index** st_unionindex320;  slog::Index** st_unionindex321;  slog::Index** $sup9688x100x0x0x0index322;  slog::Index** st_unionindex323;  slog::Index** st_unionindex324;  slog::Index** st_unionindex325;  slog::Index** pbranchindex326;  slog::Index** st_unionindex327;  slog::Index** st_unionindex328;  slog::Index** st_union_ansindex329;  slog::Index** st_unionindex330;  slog::Index** st_union_ansindex331;  slog::Index** st_union_ansindex332;  slog::Index** st_union_ansindex333;  slog::Index** pbranchdelta334;  slog::Index** st_uniondelta335;  slog::Index** st_uniondelta336;  slog::Index** st_uniondelta337;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp6bMv1274");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord339({1, 2, 3, 4, 0});
      slog::Relation* readrel340 = db->getRelation("pbranch");
      pbranchindex318 = readrel340->getIndex(ord339, false);
      std::vector<u16> ord341({2, 0, 1});
      slog::Relation* readrel342 = db->getRelation("st_union");
      st_unionindex319 = readrel342->getIndex(ord341, false);
      std::vector<u16> ord343({2, 0, 1});
      slog::Relation* readrel344 = db->getRelation("st_union");
      st_unionindex320 = readrel344->getIndex(ord343, false);
      std::vector<u16> ord345({2, 0, 1});
      slog::Relation* readrel346 = db->getRelation("st_union");
      st_unionindex321 = readrel346->getIndex(ord345, false);
      std::vector<u16> ord347({2, 3, 5, 6, 0, 1, 4});
      slog::Relation* readrel348 = db->getRelation("$sup9688x100x0x0x0");
      $sup9688x100x0x0x0index322 = readrel348->getIndex(ord347, false);
      std::vector<u16> ord349({2, 0, 1});
      slog::Relation* readrel350 = db->getRelation("st_union");
      st_unionindex323 = readrel350->getIndex(ord349, false);
      std::vector<u16> ord351({1, 2, 0});
      slog::Relation* readrel352 = db->getRelation("st_union");
      st_unionindex324 = readrel352->getIndex(ord351, false);
      std::vector<u16> ord353({1, 2, 0});
      slog::Relation* readrel354 = db->getRelation("st_union");
      st_unionindex325 = readrel354->getIndex(ord353, false);
      std::vector<u16> ord355({1, 2, 3, 4, 0});
      slog::Relation* readrel356 = db->getRelation("pbranch");
      pbranchindex326 = readrel356->getIndex(ord355, false);
      std::vector<u16> ord357({1, 2, 3, 4, 0});
      slog::Relation* readrel358 = db->getRelation("pbranch");
      pbranchdelta334 = readrel358->getIndex(ord357, true);
      std::vector<u16> ord359({0, 1, 2});
      slog::Relation* readrel360 = db->getRelation("st_union");
      st_unionindex327 = readrel360->getIndex(ord359, false);
      std::vector<u16> ord361({0, 1, 2});
      slog::Relation* readrel362 = db->getRelation("st_union");
      st_uniondelta335 = readrel362->getIndex(ord361, true);
      std::vector<u16> ord363({1, 2, 0});
      slog::Relation* readrel364 = db->getRelation("st_union");
      st_unionindex328 = readrel364->getIndex(ord363, false);
      std::vector<u16> ord365({1, 2, 0});
      slog::Relation* readrel366 = db->getRelation("st_union");
      st_uniondelta336 = readrel366->getIndex(ord365, true);
      std::vector<u16> ord367({0, 1});
      slog::Relation* readrel368 = db->getRelation("st_union_ans");
      st_union_ansindex329 = readrel368->getIndex(ord367, false);
      std::vector<u16> ord369({1, 2, 0});
      slog::Relation* readrel370 = db->getRelation("st_union");
      st_unionindex330 = readrel370->getIndex(ord369, false);
      std::vector<u16> ord371({1, 2, 0});
      slog::Relation* readrel372 = db->getRelation("st_union");
      st_uniondelta337 = readrel372->getIndex(ord371, true);
      std::vector<u16> ord373({0, 1});
      slog::Relation* readrel374 = db->getRelation("st_union_ans");
      st_union_ansindex331 = readrel374->getIndex(ord373, false);
      std::vector<u16> ord375({0, 1});
      slog::Relation* readrel376 = db->getRelation("st_union_ans");
      st_union_ansindex332 = readrel376->getIndex(ord375, false);
      std::vector<u16> ord377({0, 1});
      slog::Relation* readrel378 = db->getRelation("st_union_ans");
      st_union_ansindex333 = readrel378->getIndex(ord377, false);
  
    }
    ReadTask338(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c111 = _t[0];
        u64 v_c1 = _t[1];
        u64 v_c2 = _t[2];
        u64 v_c3 = _t[3];
        u64 v_c4 = _t[4];
        if (!slog::exists_probe<5,2>(pbranchindex318, std::array<u64,5>{v_c1, v_c2, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_unionindex319, std::array<u64,3>{v_c111, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_unionindex320, std::array<u64,3>{v_c3, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_unionindex321, std::array<u64,3>{v_c4, 0, 0})) return;
        slog::join_probe<7,4>($sup9688x100x0x0x0index322, std::array<u64,7>{v_c2, v_c1, v_c3, v_c4, 0, 0, 0}, [&](const std::array<u64,7>& m379) {
          u64 v_c112 = m379[4]; u64 v_c6 = m379[5]; u64 v_c7 = m379[6];
          if (!slog::exists_probe<3,2>(st_unionindex323, std::array<u64,3>{v_c111, v_c112, 0})) return;
          if (!slog::exists_probe<3,2>(st_unionindex324, std::array<u64,3>{v_c6, v_c3, 0})) return;
          if (!slog::exists_probe<3,2>(st_unionindex325, std::array<u64,3>{v_c7, v_c4, 0})) return;
          slog::join_probe_old<5,4>(pbranchindex326, pbranchdelta334, std::array<u64,5>{v_c1, v_c2, v_c6, v_c7, 0}, [&](const std::array<u64,5>& m380) {
            u64 v_c113 = m380[4];
            slog::join_probe_old<3,3>(st_unionindex327, st_uniondelta335, std::array<u64,3>{v_c112, v_c113, v_c111}, [&](const std::array<u64,3>& m381) {
              slog::join_probe_old<3,2>(st_unionindex328, st_uniondelta336, std::array<u64,3>{v_c6, v_c3, 0}, [&](const std::array<u64,3>& m382) {
                u64 v_c114 = m382[2];
                if (!slog::exists_probe<2,1>(st_union_ansindex329, std::array<u64,2>{v_c114, 0})) return;
                slog::join_probe_old<3,2>(st_unionindex330, st_uniondelta337, std::array<u64,3>{v_c7, v_c4, 0}, [&](const std::array<u64,3>& m383) {
                  u64 v_c115 = m383[2];
                  if (!slog::exists_probe<2,1>(st_union_ansindex331, std::array<u64,2>{v_c115, 0})) return;
                  slog::join_probe<2,1>(st_union_ansindex332, std::array<u64,2>{v_c114, 0}, [&](const std::array<u64,2>& m384) {
                    u64 v_c11 = m384[1];
                    slog::join_probe<2,1>(st_union_ansindex333, std::array<u64,2>{v_c115, 0}, [&](const std::array<u64,2>& m385) {
                      u64 v_c12 = m385[1];
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c112, v_c11, v_c12, v_c2, v_c1});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c1, v_c2, v_c11, v_c12}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:101", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask338* _cont = new ReadTask338(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask338(db,b), false);
  // (crule (pre (let __tconst2IZo78 const5feceb66ffc86f38d952786c)) (scan st_diff_ans __t8Vvm81 res) (body (join-old st_diff (0 1 2) 1 (0 1 2) __t8Vvm81 __t0L1D80 v) (exists pbranch (4 0 1 2 3) 1 v) (exists $sup9688x151x0x0x0 (8 0 1 2 3 4 5 6 7) 1 v) (join-old st_diff (1 2 0) 1 (1 2 0) __t0L1D80 __t3eDW75 __t0F4S77) (exists $sup9688x151x0x0x0 (0 8 1 2 3 4 5 6 7) 2 __t0F4S77 v) (join-old pbranch (4 0 1 2 3) 2 (4 0 1 2 3) v __t3eDW75 q n u) (exists st_msk (2 0 1) 1 n) (exists st_msk_ans (1 0) 1 q) (join-old $sup9688x151x0x0x0 (5 3 7 8 0 1 2 4 6) 5 (5 3 7 8 0 1 2 4 6) q n u v __t0F4S77 l m p r) (cmp lt m n) (join-old pbranch (1 2 3 4 0) 5 (1 2 3 4 0) p m l r __t0L1D80) (join-old st_msk (1 2 0) 2 (1 2 0) p n __t1x4A82) (join-old st_msk_ans (0 1) 2 (0 1) __t1x4A82 q) (let __t2OsQ79 (band p n)) (cmp gt __t2OsQ79 __tconst2IZo78)) (head (emit st_diff_ans (0 1) __t0F4S77 res)) set.slog:152 #f)
  class ReadTask405 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_diffindex386;  slog::Index** pbranchindex387;  slog::Index** $sup9688x151x0x0x0index388;  slog::Index** st_diffindex389;  slog::Index** $sup9688x151x0x0x0index390;  slog::Index** pbranchindex391;  slog::Index** st_mskindex392;  slog::Index** st_msk_ansindex393;  slog::Index** $sup9688x151x0x0x0index394;  slog::Index** pbranchindex395;  slog::Index** st_mskindex396;  slog::Index** st_msk_ansindex397;  slog::Index** st_diffdelta398;  slog::Index** st_diffdelta399;  slog::Index** pbranchdelta400;  slog::Index** $sup9688x151x0x0x0delta401;  slog::Index** pbranchdelta402;  slog::Index** st_mskdelta403;  slog::Index** st_msk_ansdelta404;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord406({0, 1});
      slog::Relation* readrel407 = db->getRelation("st_diff_ans");
      head_index[0] = readrel407->getIndex(ord406, false);
      outer_rel = db->getRelation("st_diff_ans");
      std::vector<u16> ord408({0, 1, 2});
      slog::Relation* readrel409 = db->getRelation("st_diff");
      st_diffindex386 = readrel409->getIndex(ord408, false);
      std::vector<u16> ord410({0, 1, 2});
      slog::Relation* readrel411 = db->getRelation("st_diff");
      st_diffdelta398 = readrel411->getIndex(ord410, true);
      std::vector<u16> ord412({4, 0, 1, 2, 3});
      slog::Relation* readrel413 = db->getRelation("pbranch");
      pbranchindex387 = readrel413->getIndex(ord412, false);
      std::vector<u16> ord414({8, 0, 1, 2, 3, 4, 5, 6, 7});
      slog::Relation* readrel415 = db->getRelation("$sup9688x151x0x0x0");
      $sup9688x151x0x0x0index388 = readrel415->getIndex(ord414, false);
      std::vector<u16> ord416({1, 2, 0});
      slog::Relation* readrel417 = db->getRelation("st_diff");
      st_diffindex389 = readrel417->getIndex(ord416, false);
      std::vector<u16> ord418({1, 2, 0});
      slog::Relation* readrel419 = db->getRelation("st_diff");
      st_diffdelta399 = readrel419->getIndex(ord418, true);
      std::vector<u16> ord420({0, 8, 1, 2, 3, 4, 5, 6, 7});
      slog::Relation* readrel421 = db->getRelation("$sup9688x151x0x0x0");
      $sup9688x151x0x0x0index390 = readrel421->getIndex(ord420, false);
      std::vector<u16> ord422({4, 0, 1, 2, 3});
      slog::Relation* readrel423 = db->getRelation("pbranch");
      pbranchindex391 = readrel423->getIndex(ord422, false);
      std::vector<u16> ord424({4, 0, 1, 2, 3});
      slog::Relation* readrel425 = db->getRelation("pbranch");
      pbranchdelta400 = readrel425->getIndex(ord424, true);
      std::vector<u16> ord426({2, 0, 1});
      slog::Relation* readrel427 = db->getRelation("st_msk");
      st_mskindex392 = readrel427->getIndex(ord426, false);
      std::vector<u16> ord428({1, 0});
      slog::Relation* readrel429 = db->getRelation("st_msk_ans");
      st_msk_ansindex393 = readrel429->getIndex(ord428, false);
      std::vector<u16> ord430({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel431 = db->getRelation("$sup9688x151x0x0x0");
      $sup9688x151x0x0x0index394 = readrel431->getIndex(ord430, false);
      std::vector<u16> ord432({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel433 = db->getRelation("$sup9688x151x0x0x0");
      $sup9688x151x0x0x0delta401 = readrel433->getIndex(ord432, true);
      std::vector<u16> ord434({1, 2, 3, 4, 0});
      slog::Relation* readrel435 = db->getRelation("pbranch");
      pbranchindex395 = readrel435->getIndex(ord434, false);
      std::vector<u16> ord436({1, 2, 3, 4, 0});
      slog::Relation* readrel437 = db->getRelation("pbranch");
      pbranchdelta402 = readrel437->getIndex(ord436, true);
      std::vector<u16> ord438({1, 2, 0});
      slog::Relation* readrel439 = db->getRelation("st_msk");
      st_mskindex396 = readrel439->getIndex(ord438, false);
      std::vector<u16> ord440({1, 2, 0});
      slog::Relation* readrel441 = db->getRelation("st_msk");
      st_mskdelta403 = readrel441->getIndex(ord440, true);
      std::vector<u16> ord442({0, 1});
      slog::Relation* readrel443 = db->getRelation("st_msk_ans");
      st_msk_ansindex397 = readrel443->getIndex(ord442, false);
      std::vector<u16> ord444({0, 1});
      slog::Relation* readrel445 = db->getRelation("st_msk_ans");
      st_msk_ansdelta404 = readrel445->getIndex(ord444, true);
  
    }
    ReadTask405(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c116 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c117 = _t[0];
        u64 v_c14 = _t[1];
        slog::join_probe_old<3,1>(st_diffindex386, st_diffdelta398, std::array<u64,3>{v_c117, 0, 0}, [&](const std::array<u64,3>& m446) {
          u64 v_c118 = m446[1]; u64 v_c4 = m446[2];
          if (!slog::exists_probe<5,1>(pbranchindex387, std::array<u64,5>{v_c4, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<9,1>($sup9688x151x0x0x0index388, std::array<u64,9>{v_c4, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          slog::join_probe_old<3,1>(st_diffindex389, st_diffdelta399, std::array<u64,3>{v_c118, 0, 0}, [&](const std::array<u64,3>& m447) {
            u64 v_c119 = m447[1]; u64 v_c120 = m447[2];
            if (!slog::exists_probe<9,2>($sup9688x151x0x0x0index390, std::array<u64,9>{v_c120, v_c4, 0, 0, 0, 0, 0, 0, 0})) return;
            slog::join_probe_old<5,2>(pbranchindex391, pbranchdelta400, std::array<u64,5>{v_c4, v_c119, 0, 0, 0}, [&](const std::array<u64,5>& m448) {
              u64 v_c35 = m448[2]; u64 v_c36 = m448[3]; u64 v_c3 = m448[4];
              if (!slog::exists_probe<3,1>(st_mskindex392, std::array<u64,3>{v_c36, 0, 0})) return;
              if (!slog::exists_probe<2,1>(st_msk_ansindex393, std::array<u64,2>{v_c35, 0})) return;
              slog::join_probe_old<9,5>($sup9688x151x0x0x0index394, $sup9688x151x0x0x0delta401, std::array<u64,9>{v_c35, v_c36, v_c3, v_c4, v_c120, 0, 0, 0, 0}, [&](const std::array<u64,9>& m449) {
                u64 v_c6 = m449[5]; u64 v_c2 = m449[6]; u64 v_c1 = m449[7]; u64 v_c7 = m449[8];
                u64 v_c121 = _prim_lt(db, v_c2, v_c36);
                if (v_c121 == slog_error) { slog::emit_pending_error(db, "set.slog:152"); return; }
                if (!v_c121) return;
                slog::join_probe_old<5,5>(pbranchindex395, pbranchdelta402, std::array<u64,5>{v_c1, v_c2, v_c6, v_c7, v_c118}, [&](const std::array<u64,5>& m451) {
                  slog::join_probe_old<3,2>(st_mskindex396, st_mskdelta403, std::array<u64,3>{v_c1, v_c36, 0}, [&](const std::array<u64,3>& m452) {
                    u64 v_c122 = m452[2];
                    slog::join_probe_old<2,2>(st_msk_ansindex397, st_msk_ansdelta404, std::array<u64,2>{v_c122, v_c35}, [&](const std::array<u64,2>& m453) {
                      u64 v_c123 = _prim_band(db, v_c1, v_c36);
                      if (v_c123 == slog_error) { slog::emit_pending_error(db, "set.slog:152"); return; }
                      u64 v_c124 = _prim_gt(db, v_c123, v_c116);
                      if (v_c124 == slog_error) { slog::emit_pending_error(db, "set.slog:152"); return; }
                      if (!v_c124) return;
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c120, v_c14}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:152", "delta:st_diff_ans", _fires);
  
      if (!_done)
      {
        ReadTask405* _cont = new ReadTask405(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask405(db,b), false);
  // (crule (pre) (scan st_diff __t8u30411 r v) (body (exists $sup9688x136x0x0x0 (4 6 0 1 2 3 5) 2 r v) (exists pbranch (4 0 1 2 3) 1 v) (exists pbranch (4 0 1 2 3) 1 r) (join st_diff_ans (0 1) 1 __t8u30411 __v1) (exists st_bld (4 0 1 2 3) 1 __v1) (join $sup9688x136x0x0x0 (4 6 0 1 2 3 5) 2 r v __t5pD6408 l m p u) (exists pbranch (1 2 3 4 0) 4 p m l r) (exists st_bld (2 1 4 0 3) 3 m p __v1) (exists st_diff (1 2 0) 2 l u) (join pbranch (1 2 3 4 0) 4 p m u v __t9ous406) (exists st_diff (2 0 1) 2 __t9ous406 __t5pD6408) (join pbranch (1 2 3 4 0) 4 p m l r __t3cJ7407) (join st_diff (0 1 2) 3 __t5pD6408 __t3cJ7407 __t9ous406) (join st_bld (2 1 4 0 3) 3 m p __v1 __t9obY409 __v0) (exists st_diff_ans (1 0) 1 __v0) (exists st_bld_ans (0 1) 1 __t9obY409) (join st_diff (1 2 0) 2 l u __t6cu0410) (join st_diff_ans (0 1) 2 __t6cu0410 __v0) (join st_bld_ans (0 1) 1 __t9obY409 res)) (head (emit st_diff_ans (0 1) __t5pD6408 res)) set.slog:137 #f)
  class ReadTask474 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x136x0x0x0index455;  slog::Index** pbranchindex456;  slog::Index** pbranchindex457;  slog::Index** st_diff_ansindex458;  slog::Index** st_bldindex459;  slog::Index** $sup9688x136x0x0x0index460;  slog::Index** pbranchindex461;  slog::Index** st_bldindex462;  slog::Index** st_diffindex463;  slog::Index** pbranchindex464;  slog::Index** st_diffindex465;  slog::Index** pbranchindex466;  slog::Index** st_diffindex467;  slog::Index** st_bldindex468;  slog::Index** st_diff_ansindex469;  slog::Index** st_bld_ansindex470;  slog::Index** st_diffindex471;  slog::Index** st_diff_ansindex472;  slog::Index** st_bld_ansindex473;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord475({0, 1});
      slog::Relation* readrel476 = db->getRelation("st_diff_ans");
      head_index[0] = readrel476->getIndex(ord475, false);
      outer_rel = db->getRelation("st_diff");
      std::vector<u16> ord477({4, 6, 0, 1, 2, 3, 5});
      slog::Relation* readrel478 = db->getRelation("$sup9688x136x0x0x0");
      $sup9688x136x0x0x0index455 = readrel478->getIndex(ord477, false);
      std::vector<u16> ord479({4, 0, 1, 2, 3});
      slog::Relation* readrel480 = db->getRelation("pbranch");
      pbranchindex456 = readrel480->getIndex(ord479, false);
      std::vector<u16> ord481({4, 0, 1, 2, 3});
      slog::Relation* readrel482 = db->getRelation("pbranch");
      pbranchindex457 = readrel482->getIndex(ord481, false);
      std::vector<u16> ord483({0, 1});
      slog::Relation* readrel484 = db->getRelation("st_diff_ans");
      st_diff_ansindex458 = readrel484->getIndex(ord483, false);
      std::vector<u16> ord485({4, 0, 1, 2, 3});
      slog::Relation* readrel486 = db->getRelation("st_bld");
      st_bldindex459 = readrel486->getIndex(ord485, false);
      std::vector<u16> ord487({4, 6, 0, 1, 2, 3, 5});
      slog::Relation* readrel488 = db->getRelation("$sup9688x136x0x0x0");
      $sup9688x136x0x0x0index460 = readrel488->getIndex(ord487, false);
      std::vector<u16> ord489({1, 2, 3, 4, 0});
      slog::Relation* readrel490 = db->getRelation("pbranch");
      pbranchindex461 = readrel490->getIndex(ord489, false);
      std::vector<u16> ord491({2, 1, 4, 0, 3});
      slog::Relation* readrel492 = db->getRelation("st_bld");
      st_bldindex462 = readrel492->getIndex(ord491, false);
      std::vector<u16> ord493({1, 2, 0});
      slog::Relation* readrel494 = db->getRelation("st_diff");
      st_diffindex463 = readrel494->getIndex(ord493, false);
      std::vector<u16> ord495({1, 2, 3, 4, 0});
      slog::Relation* readrel496 = db->getRelation("pbranch");
      pbranchindex464 = readrel496->getIndex(ord495, false);
      std::vector<u16> ord497({2, 0, 1});
      slog::Relation* readrel498 = db->getRelation("st_diff");
      st_diffindex465 = readrel498->getIndex(ord497, false);
      std::vector<u16> ord499({1, 2, 3, 4, 0});
      slog::Relation* readrel500 = db->getRelation("pbranch");
      pbranchindex466 = readrel500->getIndex(ord499, false);
      std::vector<u16> ord501({0, 1, 2});
      slog::Relation* readrel502 = db->getRelation("st_diff");
      st_diffindex467 = readrel502->getIndex(ord501, false);
      std::vector<u16> ord503({2, 1, 4, 0, 3});
      slog::Relation* readrel504 = db->getRelation("st_bld");
      st_bldindex468 = readrel504->getIndex(ord503, false);
      std::vector<u16> ord505({1, 0});
      slog::Relation* readrel506 = db->getRelation("st_diff_ans");
      st_diff_ansindex469 = readrel506->getIndex(ord505, false);
      std::vector<u16> ord507({0, 1});
      slog::Relation* readrel508 = db->getRelation("st_bld_ans");
      st_bld_ansindex470 = readrel508->getIndex(ord507, false);
      std::vector<u16> ord509({1, 2, 0});
      slog::Relation* readrel510 = db->getRelation("st_diff");
      st_diffindex471 = readrel510->getIndex(ord509, false);
      std::vector<u16> ord511({0, 1});
      slog::Relation* readrel512 = db->getRelation("st_diff_ans");
      st_diff_ansindex472 = readrel512->getIndex(ord511, false);
      std::vector<u16> ord513({0, 1});
      slog::Relation* readrel514 = db->getRelation("st_bld_ans");
      st_bld_ansindex473 = readrel514->getIndex(ord513, false);
  
    }
    ReadTask474(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c10 = _t[0];
        u64 v_c7 = _t[1];
        u64 v_c4 = _t[2];
        if (!slog::exists_probe<7,2>($sup9688x136x0x0x0index455, std::array<u64,7>{v_c7, v_c4, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex456, std::array<u64,5>{v_c4, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex457, std::array<u64,5>{v_c7, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(st_diff_ansindex458, std::array<u64,2>{v_c10, 0}, [&](const std::array<u64,2>& m515) {
          u64 v_c12 = m515[1];
          if (!slog::exists_probe<5,1>(st_bldindex459, std::array<u64,5>{v_c12, 0, 0, 0, 0})) return;
          slog::join_probe<7,2>($sup9688x136x0x0x0index460, std::array<u64,7>{v_c7, v_c4, 0, 0, 0, 0, 0}, [&](const std::array<u64,7>& m516) {
            u64 v_c5 = m516[2]; u64 v_c6 = m516[3]; u64 v_c2 = m516[4]; u64 v_c1 = m516[5]; u64 v_c3 = m516[6];
            if (!slog::exists_probe<5,4>(pbranchindex461, std::array<u64,5>{v_c1, v_c2, v_c6, v_c7, 0})) return;
            if (!slog::exists_probe<5,3>(st_bldindex462, std::array<u64,5>{v_c2, v_c1, v_c12, 0, 0})) return;
            if (!slog::exists_probe<3,2>(st_diffindex463, std::array<u64,3>{v_c6, v_c3, 0})) return;
            slog::join_probe<5,4>(pbranchindex464, std::array<u64,5>{v_c1, v_c2, v_c3, v_c4, 0}, [&](const std::array<u64,5>& m517) {
              u64 v_c0 = m517[4];
              if (!slog::exists_probe<3,2>(st_diffindex465, std::array<u64,3>{v_c0, v_c5, 0})) return;
              slog::join_probe<5,4>(pbranchindex466, std::array<u64,5>{v_c1, v_c2, v_c6, v_c7, 0}, [&](const std::array<u64,5>& m518) {
                u64 v_c8 = m518[4];
                slog::join_probe<3,3>(st_diffindex467, std::array<u64,3>{v_c5, v_c8, v_c0}, [&](const std::array<u64,3>& m519) {
                  slog::join_probe<5,3>(st_bldindex468, std::array<u64,5>{v_c2, v_c1, v_c12, 0, 0}, [&](const std::array<u64,5>& m520) {
                    u64 v_c13 = m520[3]; u64 v_c11 = m520[4];
                    if (!slog::exists_probe<2,1>(st_diff_ansindex469, std::array<u64,2>{v_c11, 0})) return;
                    if (!slog::exists_probe<2,1>(st_bld_ansindex470, std::array<u64,2>{v_c13, 0})) return;
                    slog::join_probe<3,2>(st_diffindex471, std::array<u64,3>{v_c6, v_c3, 0}, [&](const std::array<u64,3>& m521) {
                      u64 v_c9 = m521[2];
                      slog::join_probe<2,2>(st_diff_ansindex472, std::array<u64,2>{v_c9, v_c11}, [&](const std::array<u64,2>& m522) {
                        slog::join_probe<2,1>(st_bld_ansindex473, std::array<u64,2>{v_c13, 0}, [&](const std::array<u64,2>& m523) {
                          u64 v_c14 = m523[1];
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c5, v_c14}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("set.slog:137", "delta:st_diff", _fires);
  
      if (!_done)
      {
        ReadTask474* _cont = new ReadTask474(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask474(db,b), false);
  // (crule (pre (let __trid1BiT950 constc49bf1a249fe0ece92ed8fd8) (let __trel6q0k951 consta10f76b4ec574de5d7b6908e) (let __tcol8Cfv952 const5feceb66ffc86f38d952786c) (let __trel2MUP953 consta10f76b4ec574de5d7b6908e) (let __tcol26q3954 const6b86b273ff34fce19d6b804e)) (scan $sup9688x110x0x0x0 __d0 l m n p q r s t u v) (body) (head (tycheck q (accept int) __trid1BiT950 __trel6q0k951 __tcol8Cfv952 (1 2 3 4 0)) (tycheck m (accept int) __trid1BiT950 __trel2MUP953 __tcol26q3954 (1 2 3 4 0)) (mkstruct st_msk (1 2 0) __2lc2949 q m)) set.slog:111 #f)
  class ReadTask524 : public slog::Task
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
      outer_rel = db->getRelation("$sup9688x110x0x0x0");
  
    }
    ReadTask524(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c125 = v_constc49bf1a249fe0ece92ed8fd8;
      u64 v_c126 = v_consta10f76b4ec574de5d7b6908e;
      u64 v_c127 = v_const5feceb66ffc86f38d952786c;
      u64 v_c128 = v_consta10f76b4ec574de5d7b6908e;
      u64 v_c129 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c28 = _t[0];
        u64 v_c6 = _t[1];
        u64 v_c2 = _t[2];
        u64 v_c36 = _t[3];
        u64 v_c1 = _t[4];
        u64 v_c35 = _t[5];
        u64 v_c7 = _t[6];
        u64 v_c130 = _t[7];
        u64 v_c18 = _t[8];
        u64 v_c3 = _t[9];
        u64 v_c4 = _t[10];
        ++_fires;
        if (!(is_int(v_c35)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c125, v_c126, v_c127, v_c35}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c2)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c125, v_c128, v_c129, v_c2}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c35, v_c2}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("set.slog:111", "delta:$sup9688x110x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask524* _cont = new ReadTask524(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask524(db,b), false);
  // (crule (pre (let __tconst5qiO758 conste3776bfed7f405de8017ecfa) (let __tconst5MZ7439 constef2d127de37b942baad06145) (let __tconst7dws442 constd4735e3a265e16eee03f5971) (let __tconst4Zv7438 const2c624232cdd221771294dfbb)) (probe st_ins (2 0 1) 1 __tconst7dws442 __t1qxx444 __t8JV0443) (body (join _enum (0 1) 2 __t8JV0443 __tconst5qiO758) (exists st_ins_ans (0 1) 1 __t1qxx444) (join st_ins (1 2 0) 2 __t8JV0443 __tconst5MZ7439 __t1gci441) (join st_ins_ans (0 1) 1 __t1gci441 __v0) (join st_ins_ans (0 1) 1 __t1qxx444 __v1)) (head (mkstruct st_ins (1 2 0) __0kE5759 __v0 __tconst4Zv7438)) st_basic.slog:18 #f)
  class ReadTask530 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** _enumindex525;  slog::Index** st_ins_ansindex526;  slog::Index** st_insindex527;  slog::Index** st_ins_ansindex528;  slog::Index** st_ins_ansindex529;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_ins");
      std::vector<u16> ord531({2, 0, 1});
      slog::Relation* readrel532 = db->getRelation("st_ins");
      driver_index = readrel532->getIndex(ord531, true);
      std::vector<u16> ord533({0, 1});
      slog::Relation* readrel534 = db->getRelation("_enum");
      _enumindex525 = readrel534->getIndex(ord533, false);
      std::vector<u16> ord535({0, 1});
      slog::Relation* readrel536 = db->getRelation("st_ins_ans");
      st_ins_ansindex526 = readrel536->getIndex(ord535, false);
      std::vector<u16> ord537({1, 2, 0});
      slog::Relation* readrel538 = db->getRelation("st_ins");
      st_insindex527 = readrel538->getIndex(ord537, false);
      std::vector<u16> ord539({0, 1});
      slog::Relation* readrel540 = db->getRelation("st_ins_ans");
      st_ins_ansindex528 = readrel540->getIndex(ord539, false);
      std::vector<u16> ord541({0, 1});
      slog::Relation* readrel542 = db->getRelation("st_ins_ans");
      st_ins_ansindex529 = readrel542->getIndex(ord541, false);
  
    }
    ReadTask530(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c131 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c132 = v_constef2d127de37b942baad06145;
      u64 v_c133 = v_constd4735e3a265e16eee03f5971;
      u64 v_c134 = v_const2c624232cdd221771294dfbb;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c133, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m543) {
        u64 v_c135 = m543[1];
        u64 v_c136 = m543[2];
        if (buckethash(v_c135) != bucket) return;
        slog::join_probe<2,2>(_enumindex525, std::array<u64,2>{v_c136, v_c131}, [&](const std::array<u64,2>& m544) {
          if (!slog::exists_probe<2,1>(st_ins_ansindex526, std::array<u64,2>{v_c135, 0})) return;
          slog::join_probe<3,2>(st_insindex527, std::array<u64,3>{v_c136, v_c132, 0}, [&](const std::array<u64,3>& m545) {
            u64 v_c137 = m545[2];
            slog::join_probe<2,1>(st_ins_ansindex528, std::array<u64,2>{v_c137, 0}, [&](const std::array<u64,2>& m546) {
              u64 v_c11 = m546[1];
              slog::join_probe<2,1>(st_ins_ansindex529, std::array<u64,2>{v_c135, 0}, [&](const std::array<u64,2>& m547) {
                u64 v_c12 = m547[1];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c11, v_c134}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("st_basic.slog:18", "delta:st_ins", _fires);
  
      if (!_done)
      {
        ReadTask530* _cont = new ReadTask530(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask530(db,b), false);
  // (crule (pre (let __tconst9B7m280 const6b86b273ff34fce19d6b804e)) (scan st_del __t3OU0279 __t2u9k278 k) (body (exists st_msk (1 2 0) 1 k) (exists st_del (2 0 1) 1 k) (join $sup9688x88x0x0x0 (0 1 2 3 4 5) 2 __t3OU0279 k l m p r) (join pbranch (1 2 3 4 0) 5 p m l r __t2u9k278) (exists st_msk (1 2 0) 2 k m) (exists st_msk_ans (1 0) 1 p) (exists st_del (1 2 0) 2 l k) (join-old st_bld (2 1 4 0 3) 3 (2 1 4 0 3) m p r __t6UON282 __v0) (exists st_del_ans (1 0) 1 __v0) (exists st_bld_ans (0 1) 1 __t6UON282) (join-old st_msk (1 2 0) 2 (1 2 0) k m __t5pdy283) (join st_msk_ans (0 1) 2 __t5pdy283 p) (join-old st_del (1 2 0) 2 (1 2 0) l k __t62j9284) (join st_del_ans (0 1) 2 __t62j9284 __v0) (join st_bld_ans (0 1) 1 __t6UON282 res) (let __t4Xlx281 (band k m)) (cmp lt __t4Xlx281 __tconst9B7m280)) (head (emit st_del_ans (0 1) __t3OU0279 res)) set.slog:89 #f)
  class ReadTask566 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_mskindex548;  slog::Index** st_delindex549;  slog::Index** $sup9688x88x0x0x0index550;  slog::Index** pbranchindex551;  slog::Index** st_mskindex552;  slog::Index** st_msk_ansindex553;  slog::Index** st_delindex554;  slog::Index** st_bldindex555;  slog::Index** st_del_ansindex556;  slog::Index** st_bld_ansindex557;  slog::Index** st_mskindex558;  slog::Index** st_msk_ansindex559;  slog::Index** st_delindex560;  slog::Index** st_del_ansindex561;  slog::Index** st_bld_ansindex562;  slog::Index** st_blddelta563;  slog::Index** st_mskdelta564;  slog::Index** st_deldelta565;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_del_ans");
      std::vector<u16> ord567({0, 1});
      slog::Relation* readrel568 = db->getRelation("st_del_ans");
      head_index[0] = readrel568->getIndex(ord567, false);
      outer_rel = db->getRelation("st_del");
      std::vector<u16> ord569({1, 2, 0});
      slog::Relation* readrel570 = db->getRelation("st_msk");
      st_mskindex548 = readrel570->getIndex(ord569, false);
      std::vector<u16> ord571({2, 0, 1});
      slog::Relation* readrel572 = db->getRelation("st_del");
      st_delindex549 = readrel572->getIndex(ord571, false);
      std::vector<u16> ord573({0, 1, 2, 3, 4, 5});
      slog::Relation* readrel574 = db->getRelation("$sup9688x88x0x0x0");
      $sup9688x88x0x0x0index550 = readrel574->getIndex(ord573, false);
      std::vector<u16> ord575({1, 2, 3, 4, 0});
      slog::Relation* readrel576 = db->getRelation("pbranch");
      pbranchindex551 = readrel576->getIndex(ord575, false);
      std::vector<u16> ord577({1, 2, 0});
      slog::Relation* readrel578 = db->getRelation("st_msk");
      st_mskindex552 = readrel578->getIndex(ord577, false);
      std::vector<u16> ord579({1, 0});
      slog::Relation* readrel580 = db->getRelation("st_msk_ans");
      st_msk_ansindex553 = readrel580->getIndex(ord579, false);
      std::vector<u16> ord581({1, 2, 0});
      slog::Relation* readrel582 = db->getRelation("st_del");
      st_delindex554 = readrel582->getIndex(ord581, false);
      std::vector<u16> ord583({2, 1, 4, 0, 3});
      slog::Relation* readrel584 = db->getRelation("st_bld");
      st_bldindex555 = readrel584->getIndex(ord583, false);
      std::vector<u16> ord585({2, 1, 4, 0, 3});
      slog::Relation* readrel586 = db->getRelation("st_bld");
      st_blddelta563 = readrel586->getIndex(ord585, true);
      std::vector<u16> ord587({1, 0});
      slog::Relation* readrel588 = db->getRelation("st_del_ans");
      st_del_ansindex556 = readrel588->getIndex(ord587, false);
      std::vector<u16> ord589({0, 1});
      slog::Relation* readrel590 = db->getRelation("st_bld_ans");
      st_bld_ansindex557 = readrel590->getIndex(ord589, false);
      std::vector<u16> ord591({1, 2, 0});
      slog::Relation* readrel592 = db->getRelation("st_msk");
      st_mskindex558 = readrel592->getIndex(ord591, false);
      std::vector<u16> ord593({1, 2, 0});
      slog::Relation* readrel594 = db->getRelation("st_msk");
      st_mskdelta564 = readrel594->getIndex(ord593, true);
      std::vector<u16> ord595({0, 1});
      slog::Relation* readrel596 = db->getRelation("st_msk_ans");
      st_msk_ansindex559 = readrel596->getIndex(ord595, false);
      std::vector<u16> ord597({1, 2, 0});
      slog::Relation* readrel598 = db->getRelation("st_del");
      st_delindex560 = readrel598->getIndex(ord597, false);
      std::vector<u16> ord599({1, 2, 0});
      slog::Relation* readrel600 = db->getRelation("st_del");
      st_deldelta565 = readrel600->getIndex(ord599, true);
      std::vector<u16> ord601({0, 1});
      slog::Relation* readrel602 = db->getRelation("st_del_ans");
      st_del_ansindex561 = readrel602->getIndex(ord601, false);
      std::vector<u16> ord603({0, 1});
      slog::Relation* readrel604 = db->getRelation("st_bld_ans");
      st_bld_ansindex562 = readrel604->getIndex(ord603, false);
  
    }
    ReadTask566(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c138 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c19 = _t[2];
        if (!slog::exists_probe<3,1>(st_mskindex548, std::array<u64,3>{v_c19, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_delindex549, std::array<u64,3>{v_c19, 0, 0})) return;
        slog::join_probe<6,2>($sup9688x88x0x0x0index550, std::array<u64,6>{v_c139, v_c19, 0, 0, 0, 0}, [&](const std::array<u64,6>& m605) {
          u64 v_c6 = m605[2]; u64 v_c2 = m605[3]; u64 v_c1 = m605[4]; u64 v_c7 = m605[5];
          slog::join_probe<5,5>(pbranchindex551, std::array<u64,5>{v_c1, v_c2, v_c6, v_c7, v_c140}, [&](const std::array<u64,5>& m606) {
            if (!slog::exists_probe<3,2>(st_mskindex552, std::array<u64,3>{v_c19, v_c2, 0})) return;
            if (!slog::exists_probe<2,1>(st_msk_ansindex553, std::array<u64,2>{v_c1, 0})) return;
            if (!slog::exists_probe<3,2>(st_delindex554, std::array<u64,3>{v_c6, v_c19, 0})) return;
            slog::join_probe_old<5,3>(st_bldindex555, st_blddelta563, std::array<u64,5>{v_c2, v_c1, v_c7, 0, 0}, [&](const std::array<u64,5>& m607) {
              u64 v_c141 = m607[3]; u64 v_c11 = m607[4];
              if (!slog::exists_probe<2,1>(st_del_ansindex556, std::array<u64,2>{v_c11, 0})) return;
              if (!slog::exists_probe<2,1>(st_bld_ansindex557, std::array<u64,2>{v_c141, 0})) return;
              slog::join_probe_old<3,2>(st_mskindex558, st_mskdelta564, std::array<u64,3>{v_c19, v_c2, 0}, [&](const std::array<u64,3>& m608) {
                u64 v_c142 = m608[2];
                slog::join_probe<2,2>(st_msk_ansindex559, std::array<u64,2>{v_c142, v_c1}, [&](const std::array<u64,2>& m609) {
                  slog::join_probe_old<3,2>(st_delindex560, st_deldelta565, std::array<u64,3>{v_c6, v_c19, 0}, [&](const std::array<u64,3>& m610) {
                    u64 v_c143 = m610[2];
                    slog::join_probe<2,2>(st_del_ansindex561, std::array<u64,2>{v_c143, v_c11}, [&](const std::array<u64,2>& m611) {
                      slog::join_probe<2,1>(st_bld_ansindex562, std::array<u64,2>{v_c141, 0}, [&](const std::array<u64,2>& m612) {
                        u64 v_c14 = m612[1];
                        u64 v_c144 = _prim_band(db, v_c19, v_c2);
                        if (v_c144 == slog_error) { slog::emit_pending_error(db, "set.slog:89"); return; }
                        u64 v_c145 = _prim_lt(db, v_c144, v_c138);
                        if (v_c145 == slog_error) { slog::emit_pending_error(db, "set.slog:89"); return; }
                        if (!v_c145) return;
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c139, v_c14}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("set.slog:89", "delta:st_del", _fires);
  
      if (!_done)
      {
        ReadTask566* _cont = new ReadTask566(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask566(db,b), false);
  // (crule (pre (let __tconst9YUA1125 conste3776bfed7f405de8017ecfa) (let __tconst7TTg43 constef2d127de37b942baad06145) (let __tconst35F246 const2c624232cdd221771294dfbb) (let __tconst0QyJ48 constd4735e3a265e16eee03f5971) (let __tconst6ZQr51 const6b86b273ff34fce19d6b804e)) (scan st_union_ans __t8gtb53 r) (body (exists st_ins (2 0 1) 1 __tconst7TTg43) (exists st_ins (2 0 1) 1 __tconst0QyJ48) (exists st_ins (2 0 1) 1 __tconst35F246) (exists st_ins (2 0 1) 1 __tconst6ZQr51) (join _enum (1 0) 1 __tconst9YUA1125 __t7Lp349) (exists st_ins (1 2 0) 2 __t7Lp349 __tconst0QyJ48) (join-old st_ins (1 2 0) 2 (1 2 0) __t7Lp349 __tconst7TTg43 __t8j8m45) (exists st_ins_ans (0 1) 1 __t8j8m45) (join-old st_ins (1 2 0) 2 (1 2 0) __t7Lp349 __tconst0QyJ48 __t3nMl50) (exists st_ins_ans (0 1) 1 __t3nMl50) (join st_ins_ans (0 1) 1 __t8j8m45 __v0) (join-old st_ins (1 2 0) 2 (1 2 0) __v0 __tconst35F246 __t4CDi47) (join st_ins_ans (0 1) 1 __t4CDi47 a) (join-old st_union (0 1 2) 2 (0 1 2) __t8gtb53 a b) (exists st_ins_ans (1 0) 1 b) (join st_ins_ans (0 1) 1 __t3nMl50 __v1) (join-old st_ins (1 2 0) 2 (1 2 0) __v1 __tconst6ZQr51 __t7CuH52) (join st_ins_ans (0 1) 2 __t7CuH52 b)) (head (emit canon (0) r)) st_basic.slog:18 #f)
  class ReadTask637 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_insindex614;  slog::Index** st_insindex615;  slog::Index** st_insindex616;  slog::Index** st_insindex617;  slog::Index** _enumindex618;  slog::Index** st_insindex619;  slog::Index** st_insindex620;  slog::Index** st_ins_ansindex621;  slog::Index** st_insindex622;  slog::Index** st_ins_ansindex623;  slog::Index** st_ins_ansindex624;  slog::Index** st_insindex625;  slog::Index** st_ins_ansindex626;  slog::Index** st_unionindex627;  slog::Index** st_ins_ansindex628;  slog::Index** st_ins_ansindex629;  slog::Index** st_insindex630;  slog::Index** st_ins_ansindex631;  slog::Index** st_insdelta632;  slog::Index** st_insdelta633;  slog::Index** st_insdelta634;  slog::Index** st_uniondelta635;  slog::Index** st_insdelta636;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("canon");
      std::vector<u16> ord638({0});
      slog::Relation* readrel639 = db->getRelation("canon");
      head_index[0] = readrel639->getIndex(ord638, false);
      outer_rel = db->getRelation("st_union_ans");
      std::vector<u16> ord640({2, 0, 1});
      slog::Relation* readrel641 = db->getRelation("st_ins");
      st_insindex614 = readrel641->getIndex(ord640, false);
      std::vector<u16> ord642({2, 0, 1});
      slog::Relation* readrel643 = db->getRelation("st_ins");
      st_insindex615 = readrel643->getIndex(ord642, false);
      std::vector<u16> ord644({2, 0, 1});
      slog::Relation* readrel645 = db->getRelation("st_ins");
      st_insindex616 = readrel645->getIndex(ord644, false);
      std::vector<u16> ord646({2, 0, 1});
      slog::Relation* readrel647 = db->getRelation("st_ins");
      st_insindex617 = readrel647->getIndex(ord646, false);
      std::vector<u16> ord648({1, 0});
      slog::Relation* readrel649 = db->getRelation("_enum");
      _enumindex618 = readrel649->getIndex(ord648, false);
      std::vector<u16> ord650({1, 2, 0});
      slog::Relation* readrel651 = db->getRelation("st_ins");
      st_insindex619 = readrel651->getIndex(ord650, false);
      std::vector<u16> ord652({1, 2, 0});
      slog::Relation* readrel653 = db->getRelation("st_ins");
      st_insindex620 = readrel653->getIndex(ord652, false);
      std::vector<u16> ord654({1, 2, 0});
      slog::Relation* readrel655 = db->getRelation("st_ins");
      st_insdelta632 = readrel655->getIndex(ord654, true);
      std::vector<u16> ord656({0, 1});
      slog::Relation* readrel657 = db->getRelation("st_ins_ans");
      st_ins_ansindex621 = readrel657->getIndex(ord656, false);
      std::vector<u16> ord658({1, 2, 0});
      slog::Relation* readrel659 = db->getRelation("st_ins");
      st_insindex622 = readrel659->getIndex(ord658, false);
      std::vector<u16> ord660({1, 2, 0});
      slog::Relation* readrel661 = db->getRelation("st_ins");
      st_insdelta633 = readrel661->getIndex(ord660, true);
      std::vector<u16> ord662({0, 1});
      slog::Relation* readrel663 = db->getRelation("st_ins_ans");
      st_ins_ansindex623 = readrel663->getIndex(ord662, false);
      std::vector<u16> ord664({0, 1});
      slog::Relation* readrel665 = db->getRelation("st_ins_ans");
      st_ins_ansindex624 = readrel665->getIndex(ord664, false);
      std::vector<u16> ord666({1, 2, 0});
      slog::Relation* readrel667 = db->getRelation("st_ins");
      st_insindex625 = readrel667->getIndex(ord666, false);
      std::vector<u16> ord668({1, 2, 0});
      slog::Relation* readrel669 = db->getRelation("st_ins");
      st_insdelta634 = readrel669->getIndex(ord668, true);
      std::vector<u16> ord670({0, 1});
      slog::Relation* readrel671 = db->getRelation("st_ins_ans");
      st_ins_ansindex626 = readrel671->getIndex(ord670, false);
      std::vector<u16> ord672({0, 1, 2});
      slog::Relation* readrel673 = db->getRelation("st_union");
      st_unionindex627 = readrel673->getIndex(ord672, false);
      std::vector<u16> ord674({0, 1, 2});
      slog::Relation* readrel675 = db->getRelation("st_union");
      st_uniondelta635 = readrel675->getIndex(ord674, true);
      std::vector<u16> ord676({1, 0});
      slog::Relation* readrel677 = db->getRelation("st_ins_ans");
      st_ins_ansindex628 = readrel677->getIndex(ord676, false);
      std::vector<u16> ord678({0, 1});
      slog::Relation* readrel679 = db->getRelation("st_ins_ans");
      st_ins_ansindex629 = readrel679->getIndex(ord678, false);
      std::vector<u16> ord680({1, 2, 0});
      slog::Relation* readrel681 = db->getRelation("st_ins");
      st_insindex630 = readrel681->getIndex(ord680, false);
      std::vector<u16> ord682({1, 2, 0});
      slog::Relation* readrel683 = db->getRelation("st_ins");
      st_insdelta636 = readrel683->getIndex(ord682, true);
      std::vector<u16> ord684({0, 1});
      slog::Relation* readrel685 = db->getRelation("st_ins_ans");
      st_ins_ansindex631 = readrel685->getIndex(ord684, false);
  
    }
    ReadTask637(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c146 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c147 = v_constef2d127de37b942baad06145;
      u64 v_c148 = v_const2c624232cdd221771294dfbb;
      u64 v_c149 = v_constd4735e3a265e16eee03f5971;
      u64 v_c150 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c151 = _t[0];
        u64 v_c7 = _t[1];
        if (!slog::exists_probe<3,1>(st_insindex614, std::array<u64,3>{v_c147, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex615, std::array<u64,3>{v_c149, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex616, std::array<u64,3>{v_c148, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex617, std::array<u64,3>{v_c150, 0, 0})) return;
        slog::join_probe<2,1>(_enumindex618, std::array<u64,2>{v_c146, 0}, [&](const std::array<u64,2>& m686) {
          u64 v_c152 = m686[1];
          if (!slog::exists_probe<3,2>(st_insindex619, std::array<u64,3>{v_c152, v_c149, 0})) return;
          slog::join_probe_old<3,2>(st_insindex620, st_insdelta632, std::array<u64,3>{v_c152, v_c147, 0}, [&](const std::array<u64,3>& m687) {
            u64 v_c153 = m687[2];
            if (!slog::exists_probe<2,1>(st_ins_ansindex621, std::array<u64,2>{v_c153, 0})) return;
            slog::join_probe_old<3,2>(st_insindex622, st_insdelta633, std::array<u64,3>{v_c152, v_c149, 0}, [&](const std::array<u64,3>& m688) {
              u64 v_c154 = m688[2];
              if (!slog::exists_probe<2,1>(st_ins_ansindex623, std::array<u64,2>{v_c154, 0})) return;
              slog::join_probe<2,1>(st_ins_ansindex624, std::array<u64,2>{v_c153, 0}, [&](const std::array<u64,2>& m689) {
                u64 v_c11 = m689[1];
                slog::join_probe_old<3,2>(st_insindex625, st_insdelta634, std::array<u64,3>{v_c11, v_c148, 0}, [&](const std::array<u64,3>& m690) {
                  u64 v_c155 = m690[2];
                  slog::join_probe<2,1>(st_ins_ansindex626, std::array<u64,2>{v_c155, 0}, [&](const std::array<u64,2>& m691) {
                    u64 v_c156 = m691[1];
                    slog::join_probe_old<3,2>(st_unionindex627, st_uniondelta635, std::array<u64,3>{v_c151, v_c156, 0}, [&](const std::array<u64,3>& m692) {
                      u64 v_c157 = m692[2];
                      if (!slog::exists_probe<2,1>(st_ins_ansindex628, std::array<u64,2>{v_c157, 0})) return;
                      slog::join_probe<2,1>(st_ins_ansindex629, std::array<u64,2>{v_c154, 0}, [&](const std::array<u64,2>& m693) {
                        u64 v_c12 = m693[1];
                        slog::join_probe_old<3,2>(st_insindex630, st_insdelta636, std::array<u64,3>{v_c12, v_c150, 0}, [&](const std::array<u64,3>& m694) {
                          u64 v_c158 = m694[2];
                          slog::join_probe<2,2>(st_ins_ansindex631, std::array<u64,2>{v_c158, v_c157}, [&](const std::array<u64,2>& m695) {
                            ++_fires;
                            slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c7}, std::array<u16,1>{0});
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
  
      if (_fires) db->bumpFires("st_basic.slog:18", "delta:st_union_ans", _fires);
  
      if (!_done)
      {
        ReadTask637* _cont = new ReadTask637(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask637(db,b), false);
  // (crule (pre (let _00024sqc6FSA620 const4b227777d4dd1fc61c6f884f) (let _00024sqc3Ub8621 const5feceb66ffc86f38d952786c) (let _00024sqc1TCF622 const6b86b273ff34fce19d6b804e) (let _00024sqc3FMQ623 const6b86b273ff34fce19d6b804e) (let _00024sqc41K7624 const2c624232cdd221771294dfbb) (let _00024sqc6uPA625 constd4735e3a265e16eee03f5971) (let _00024sqc9VIm626 constd4735e3a265e16eee03f5971) (let _00024sqc7Q1B627 const4e07408562bedb8b60ce05c1) (let _00024sqc4nIn628 constef2d127de37b942baad06145) (let _00024sqo09Ee630 const6b86b273ff34fce19d6b804e) (let _00024sqo5YJw629 const5feceb66ffc86f38d952786c) (let _00024sqo1RnK632 const2c624232cdd221771294dfbb) (let _00024sqo5bHs631 const6b86b273ff34fce19d6b804e) (let _00024sqo2z3g634 constd4735e3a265e16eee03f5971) (let _00024sqo0Hmn633 constd4735e3a265e16eee03f5971) (let _00024sqo7Xdh636 constef2d127de37b942baad06145) (let _00024sqo5nmm635 const4e07408562bedb8b60ce05c1) (let _00024sqo4nJm638 const6b86b273ff34fce19d6b804e) (let _00024sqo7qJs637 const4e07408562bedb8b60ce05c1) (let _00024sqo4dTI640 const2c624232cdd221771294dfbb) (let _00024sqo4MMk639 constd4735e3a265e16eee03f5971) (let _00024sqo3whL642 constd4735e3a265e16eee03f5971) (let _00024sqo9zLj641 const6b86b273ff34fce19d6b804e) (let _00024sqo1Fkt644 constef2d127de37b942baad06145) (let _00024sqo2E1m643 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 2 _00024sqo5bHs631 _00024sqo1RnK632 _00024seq0) (body (join $seq_at (1 0 2) 3 _00024sqo5YJw629 _00024sqo09Ee630 _00024seq0) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo0Hmn633 _00024sqo2z3g634 _00024seq0) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo5nmm635 _00024sqo7Xdh636 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo4nJm638 _00024sqo7qJs637 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo4dTI640 _00024sqo4MMk639 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo3whL642 _00024sqo9zLj641 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo1Fkt644 _00024sqo2E1m643 _00024seq0) (join st_fromlist (1 0) 1 _00024seq0 __t2iar332) (join st_fromlist_ans (0 1) 1 __t2iar332 r) (letp _00024sql7znl618 (aslst _00024seq0)) (let chk6DC11364 (llen _00024sql7znl618)) (eq _00024sqc6FSA620 chk6DC11364) (letp chk9pGM1365 (lref _00024sql7znl618 _00024sqc3Ub8621)) (eq _00024sqc1TCF622 chk9pGM1365) (letp chk5aFV1366 (lref _00024sql7znl618 _00024sqc3FMQ623)) (eq _00024sqc41K7624 chk5aFV1366) (letp chk3PVe1367 (lref _00024sql7znl618 _00024sqc6uPA625)) (eq _00024sqc9VIm626 chk3PVe1367) (letp chk4Gl71368 (lref _00024sql7znl618 _00024sqc7Q1B627)) (eq _00024sqc4nIn628 chk4Gl71368)) (head (emit canon (0) r)) st_basic.slog:17 #f)
  class ReadTask711 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex696;  slog::Index** $seq_atindex697;  slog::Index** $seq_atindex698;  slog::Index** $seq_atrindex699;  slog::Index** $seq_atrindex700;  slog::Index** $seq_atrindex701;  slog::Index** $seq_atrindex702;  slog::Index** st_fromlistindex703;  slog::Index** st_fromlist_ansindex704;  slog::Index** $seq_atdelta705;  slog::Index** $seq_atdelta706;  slog::Index** $seq_atrdelta707;  slog::Index** $seq_atrdelta708;  slog::Index** $seq_atrdelta709;  slog::Index** $seq_atrdelta710;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("canon");
      std::vector<u16> ord712({0});
      slog::Relation* readrel713 = db->getRelation("canon");
      head_index[0] = readrel713->getIndex(ord712, false);
      std::vector<u16> ord714({1, 0, 2});
      slog::Relation* readrel715 = db->getRelation("$seq_at");
      driver_index = readrel715->getIndex(ord714, true);
      std::vector<u16> ord716({1, 0, 2});
      slog::Relation* readrel717 = db->getRelation("$seq_at");
      $seq_atindex696 = readrel717->getIndex(ord716, false);
      std::vector<u16> ord718({1, 0, 2});
      slog::Relation* readrel719 = db->getRelation("$seq_at");
      $seq_atindex697 = readrel719->getIndex(ord718, false);
      std::vector<u16> ord720({1, 0, 2});
      slog::Relation* readrel721 = db->getRelation("$seq_at");
      $seq_atdelta705 = readrel721->getIndex(ord720, true);
      std::vector<u16> ord722({1, 0, 2});
      slog::Relation* readrel723 = db->getRelation("$seq_at");
      $seq_atindex698 = readrel723->getIndex(ord722, false);
      std::vector<u16> ord724({1, 0, 2});
      slog::Relation* readrel725 = db->getRelation("$seq_at");
      $seq_atdelta706 = readrel725->getIndex(ord724, true);
      std::vector<u16> ord726({0, 1, 2});
      slog::Relation* readrel727 = db->getRelation("$seq_atr");
      $seq_atrindex699 = readrel727->getIndex(ord726, false);
      std::vector<u16> ord728({0, 1, 2});
      slog::Relation* readrel729 = db->getRelation("$seq_atr");
      $seq_atrdelta707 = readrel729->getIndex(ord728, true);
      std::vector<u16> ord730({0, 1, 2});
      slog::Relation* readrel731 = db->getRelation("$seq_atr");
      $seq_atrindex700 = readrel731->getIndex(ord730, false);
      std::vector<u16> ord732({0, 1, 2});
      slog::Relation* readrel733 = db->getRelation("$seq_atr");
      $seq_atrdelta708 = readrel733->getIndex(ord732, true);
      std::vector<u16> ord734({0, 1, 2});
      slog::Relation* readrel735 = db->getRelation("$seq_atr");
      $seq_atrindex701 = readrel735->getIndex(ord734, false);
      std::vector<u16> ord736({0, 1, 2});
      slog::Relation* readrel737 = db->getRelation("$seq_atr");
      $seq_atrdelta709 = readrel737->getIndex(ord736, true);
      std::vector<u16> ord738({0, 1, 2});
      slog::Relation* readrel739 = db->getRelation("$seq_atr");
      $seq_atrindex702 = readrel739->getIndex(ord738, false);
      std::vector<u16> ord740({0, 1, 2});
      slog::Relation* readrel741 = db->getRelation("$seq_atr");
      $seq_atrdelta710 = readrel741->getIndex(ord740, true);
      std::vector<u16> ord742({1, 0});
      slog::Relation* readrel743 = db->getRelation("st_fromlist");
      st_fromlistindex703 = readrel743->getIndex(ord742, false);
      std::vector<u16> ord744({0, 1});
      slog::Relation* readrel745 = db->getRelation("st_fromlist_ans");
      st_fromlist_ansindex704 = readrel745->getIndex(ord744, false);
  
    }
    ReadTask711(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c71 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c72 = v_const5feceb66ffc86f38d952786c;
      u64 v_c73 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c74 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c75 = v_const2c624232cdd221771294dfbb;
      u64 v_c76 = v_constd4735e3a265e16eee03f5971;
      u64 v_c77 = v_constd4735e3a265e16eee03f5971;
      u64 v_c78 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c79 = v_constef2d127de37b942baad06145;
      u64 v_c80 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c81 = v_const5feceb66ffc86f38d952786c;
      u64 v_c82 = v_const2c624232cdd221771294dfbb;
      u64 v_c83 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c84 = v_constd4735e3a265e16eee03f5971;
      u64 v_c85 = v_constd4735e3a265e16eee03f5971;
      u64 v_c86 = v_constef2d127de37b942baad06145;
      u64 v_c87 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c88 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c89 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c90 = v_const2c624232cdd221771294dfbb;
      u64 v_c91 = v_constd4735e3a265e16eee03f5971;
      u64 v_c92 = v_constd4735e3a265e16eee03f5971;
      u64 v_c93 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c94 = v_constef2d127de37b942baad06145;
      u64 v_c95 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c83, v_c82, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m746) {
        u64 v_c58 = m746[2];
        if (buckethash(v_c58) != bucket) return;
        slog::join_probe<3,3>($seq_atindex696, std::array<u64,3>{v_c81, v_c80, v_c58}, [&](const std::array<u64,3>& m747) {
          slog::join_probe_old<3,3>($seq_atindex697, $seq_atdelta705, std::array<u64,3>{v_c85, v_c84, v_c58}, [&](const std::array<u64,3>& m748) {
            slog::join_probe_old<3,3>($seq_atindex698, $seq_atdelta706, std::array<u64,3>{v_c87, v_c86, v_c58}, [&](const std::array<u64,3>& m749) {
              slog::join_probe_old<3,3>($seq_atrindex699, $seq_atrdelta707, std::array<u64,3>{v_c88, v_c89, v_c58}, [&](const std::array<u64,3>& m750) {
                slog::join_probe_old<3,3>($seq_atrindex700, $seq_atrdelta708, std::array<u64,3>{v_c90, v_c91, v_c58}, [&](const std::array<u64,3>& m751) {
                  slog::join_probe_old<3,3>($seq_atrindex701, $seq_atrdelta709, std::array<u64,3>{v_c92, v_c93, v_c58}, [&](const std::array<u64,3>& m752) {
                    slog::join_probe_old<3,3>($seq_atrindex702, $seq_atrdelta710, std::array<u64,3>{v_c94, v_c95, v_c58}, [&](const std::array<u64,3>& m753) {
                      slog::join_probe<2,1>(st_fromlistindex703, std::array<u64,2>{v_c58, 0}, [&](const std::array<u64,2>& m754) {
                        u64 v_c96 = m754[1];
                        slog::join_probe<2,1>(st_fromlist_ansindex704, std::array<u64,2>{v_c96, 0}, [&](const std::array<u64,2>& m755) {
                          u64 v_c7 = m755[1];
                          bool ok756 = true;
                          u64 v_c97 = _prim_aslst(db, v_c58, &ok756);
                          if (!ok756) return;
                          u64 v_c159 = _prim_llen(db, v_c97);
                          if (v_c159 == slog_error) { slog::emit_pending_error(db, "st_basic.slog:17"); return; }
                          if (v_c71 != v_c159) return;
                          bool ok757 = true;
                          u64 v_c160 = _prim_lref(db, v_c97, v_c72, &ok757);
                          if (!ok757) return;
                          if (v_c73 != v_c160) return;
                          bool ok758 = true;
                          u64 v_c161 = _prim_lref(db, v_c97, v_c74, &ok758);
                          if (!ok758) return;
                          if (v_c75 != v_c161) return;
                          bool ok759 = true;
                          u64 v_c162 = _prim_lref(db, v_c97, v_c76, &ok759);
                          if (!ok759) return;
                          if (v_c77 != v_c162) return;
                          bool ok760 = true;
                          u64 v_c163 = _prim_lref(db, v_c97, v_c78, &ok760);
                          if (!ok760) return;
                          if (v_c79 != v_c163) return;
                          ++_fires;
                          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c7}, std::array<u16,1>{0});
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
        ReadTask711* _cont = new ReadTask711(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask711(db,b), false);
  // (crule (pre) (scan st_msk_ans __t0CrA568 __v0) (body (join-old st_msk (0 1 2) 1 (0 1 2) __t0CrA568 k m) (exists pbranch (2 0 1 3 4) 1 m) (exists st_del (2 0 1) 1 k) (join-old $sup9688x87x0x0x0 (1 3 0 2 4 5) 2 (1 3 0 2 4 5) k m __t3SFe567 l p r) (neq p __v0) (exists st_del (0 2 1) 2 __t3SFe567 k) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t5rDd566) (join-old st_del (0 2 1) 3 (0 2 1) __t3SFe567 k __t5rDd566)) (head (emit st_del_ans (0 1) __t3SFe567 __t5rDd566)) set.slog:88 #f)
  class ReadTask772 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_mskindex761;  slog::Index** pbranchindex762;  slog::Index** st_delindex763;  slog::Index** $sup9688x87x0x0x0index764;  slog::Index** st_delindex765;  slog::Index** pbranchindex766;  slog::Index** st_delindex767;  slog::Index** st_mskdelta768;  slog::Index** $sup9688x87x0x0x0delta769;  slog::Index** pbranchdelta770;  slog::Index** st_deldelta771;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_del_ans");
      std::vector<u16> ord773({0, 1});
      slog::Relation* readrel774 = db->getRelation("st_del_ans");
      head_index[0] = readrel774->getIndex(ord773, false);
      outer_rel = db->getRelation("st_msk_ans");
      std::vector<u16> ord775({0, 1, 2});
      slog::Relation* readrel776 = db->getRelation("st_msk");
      st_mskindex761 = readrel776->getIndex(ord775, false);
      std::vector<u16> ord777({0, 1, 2});
      slog::Relation* readrel778 = db->getRelation("st_msk");
      st_mskdelta768 = readrel778->getIndex(ord777, true);
      std::vector<u16> ord779({2, 0, 1, 3, 4});
      slog::Relation* readrel780 = db->getRelation("pbranch");
      pbranchindex762 = readrel780->getIndex(ord779, false);
      std::vector<u16> ord781({2, 0, 1});
      slog::Relation* readrel782 = db->getRelation("st_del");
      st_delindex763 = readrel782->getIndex(ord781, false);
      std::vector<u16> ord783({1, 3, 0, 2, 4, 5});
      slog::Relation* readrel784 = db->getRelation("$sup9688x87x0x0x0");
      $sup9688x87x0x0x0index764 = readrel784->getIndex(ord783, false);
      std::vector<u16> ord785({1, 3, 0, 2, 4, 5});
      slog::Relation* readrel786 = db->getRelation("$sup9688x87x0x0x0");
      $sup9688x87x0x0x0delta769 = readrel786->getIndex(ord785, true);
      std::vector<u16> ord787({0, 2, 1});
      slog::Relation* readrel788 = db->getRelation("st_del");
      st_delindex765 = readrel788->getIndex(ord787, false);
      std::vector<u16> ord789({1, 2, 3, 4, 0});
      slog::Relation* readrel790 = db->getRelation("pbranch");
      pbranchindex766 = readrel790->getIndex(ord789, false);
      std::vector<u16> ord791({1, 2, 3, 4, 0});
      slog::Relation* readrel792 = db->getRelation("pbranch");
      pbranchdelta770 = readrel792->getIndex(ord791, true);
      std::vector<u16> ord793({0, 2, 1});
      slog::Relation* readrel794 = db->getRelation("st_del");
      st_delindex767 = readrel794->getIndex(ord793, false);
      std::vector<u16> ord795({0, 2, 1});
      slog::Relation* readrel796 = db->getRelation("st_del");
      st_deldelta771 = readrel796->getIndex(ord795, true);
  
    }
    ReadTask772(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c164 = _t[0];
        u64 v_c11 = _t[1];
        slog::join_probe_old<3,1>(st_mskindex761, st_mskdelta768, std::array<u64,3>{v_c164, 0, 0}, [&](const std::array<u64,3>& m797) {
          u64 v_c19 = m797[1]; u64 v_c2 = m797[2];
          if (!slog::exists_probe<5,1>(pbranchindex762, std::array<u64,5>{v_c2, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(st_delindex763, std::array<u64,3>{v_c19, 0, 0})) return;
          slog::join_probe_old<6,2>($sup9688x87x0x0x0index764, $sup9688x87x0x0x0delta769, std::array<u64,6>{v_c19, v_c2, 0, 0, 0, 0}, [&](const std::array<u64,6>& m798) {
            u64 v_c165 = m798[2]; u64 v_c6 = m798[3]; u64 v_c1 = m798[4]; u64 v_c7 = m798[5];
            if (v_c1 == v_c11) return;
            if (!slog::exists_probe<3,2>(st_delindex765, std::array<u64,3>{v_c165, v_c19, 0})) return;
            slog::join_probe_old<5,4>(pbranchindex766, pbranchdelta770, std::array<u64,5>{v_c1, v_c2, v_c6, v_c7, 0}, [&](const std::array<u64,5>& m799) {
              u64 v_c166 = m799[4];
              slog::join_probe_old<3,3>(st_delindex767, st_deldelta771, std::array<u64,3>{v_c165, v_c19, v_c166}, [&](const std::array<u64,3>& m800) {
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c165, v_c166}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:88", "delta:st_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask772* _cont = new ReadTask772(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask772(db,b), false);
  // (crule (pre (let __tconst1v9F125 const5feceb66ffc86f38d952786c)) (scan st_msk_ans __t3TTE127 q) (body (exists $sup9688x117x0x0x1 (1 6 0 2 3 4 5 7 8 9) 2 __t3TTE127 q) (exists $sup9688x117x0x0x0 (5 3 7 8 0 1 2 4 6) 1 q) (exists pbranch (1 2 3 4 0) 1 q) (join-old st_msk (0 1 2) 1 (0 1 2) __t3TTE127 p n) (exists $sup9688x117x0x0x0 (3 4 5 0 1 2 6 7 8) 3 n p q) (exists pbranch (1 2 3 4 0) 2 q n) (exists pbranch (1 2 3 4 0) 1 p) (join-old $sup9688x117x0x0x1 (1 4 5 6 0 2 3 7 8 9) 4 (1 4 5 6 0 2 3 7 8 9) __t3TTE127 n p q __t0ttd124 l m r u v) (cmp lt m n) (join-old $sup9688x117x0x0x0 (5 3 7 8 0 1 2 4 6) 9 (5 3 7 8 0 1 2 4 6) q n u v __t0ttd124 l m p r) (exists pbranch (1 2 3 4 0) 4 p m l r) (exists st_union (2 0 1) 1 v) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t43ng122) (exists st_union (2 0 1) 2 __t43ng122 __t0ttd124) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t32HA128) (join-old st_union (0 1 2) 3 (0 1 2) __t0ttd124 __t32HA128 __t43ng122) (join-old st_union (1 2 0) 2 (1 2 0) __t32HA128 v __t4LMh129) (join-old st_union_ans (0 1) 1 (0 1) __t4LMh129 __v0) (let __t3tQC126 (band p n)) (cmp gt __t3tQC126 __tconst1v9F125)) (head (emit-temp temp4p811353 __t0ttd124 __v0 n q u) (mkstruct pbranch (1 2 3 4 0) __t6NgR121 q n u __v0)) set.slog:118 #f)
  class ReadTask826 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x117x0x0x1index801;  slog::Index** $sup9688x117x0x0x0index802;  slog::Index** pbranchindex803;  slog::Index** st_mskindex804;  slog::Index** $sup9688x117x0x0x0index805;  slog::Index** pbranchindex806;  slog::Index** pbranchindex807;  slog::Index** $sup9688x117x0x0x1index808;  slog::Index** $sup9688x117x0x0x0index809;  slog::Index** pbranchindex810;  slog::Index** st_unionindex811;  slog::Index** pbranchindex812;  slog::Index** st_unionindex813;  slog::Index** pbranchindex814;  slog::Index** st_unionindex815;  slog::Index** st_unionindex816;  slog::Index** st_union_ansindex817;  slog::Index** st_mskdelta818;  slog::Index** $sup9688x117x0x0x1delta819;  slog::Index** $sup9688x117x0x0x0delta820;  slog::Index** pbranchdelta821;  slog::Index** pbranchdelta822;  slog::Index** st_uniondelta823;  slog::Index** st_uniondelta824;  slog::Index** st_union_ansdelta825;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4p811353");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("st_msk_ans");
      std::vector<u16> ord827({1, 6, 0, 2, 3, 4, 5, 7, 8, 9});
      slog::Relation* readrel828 = db->getRelation("$sup9688x117x0x0x1");
      $sup9688x117x0x0x1index801 = readrel828->getIndex(ord827, false);
      std::vector<u16> ord829({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel830 = db->getRelation("$sup9688x117x0x0x0");
      $sup9688x117x0x0x0index802 = readrel830->getIndex(ord829, false);
      std::vector<u16> ord831({1, 2, 3, 4, 0});
      slog::Relation* readrel832 = db->getRelation("pbranch");
      pbranchindex803 = readrel832->getIndex(ord831, false);
      std::vector<u16> ord833({0, 1, 2});
      slog::Relation* readrel834 = db->getRelation("st_msk");
      st_mskindex804 = readrel834->getIndex(ord833, false);
      std::vector<u16> ord835({0, 1, 2});
      slog::Relation* readrel836 = db->getRelation("st_msk");
      st_mskdelta818 = readrel836->getIndex(ord835, true);
      std::vector<u16> ord837({3, 4, 5, 0, 1, 2, 6, 7, 8});
      slog::Relation* readrel838 = db->getRelation("$sup9688x117x0x0x0");
      $sup9688x117x0x0x0index805 = readrel838->getIndex(ord837, false);
      std::vector<u16> ord839({1, 2, 3, 4, 0});
      slog::Relation* readrel840 = db->getRelation("pbranch");
      pbranchindex806 = readrel840->getIndex(ord839, false);
      std::vector<u16> ord841({1, 2, 3, 4, 0});
      slog::Relation* readrel842 = db->getRelation("pbranch");
      pbranchindex807 = readrel842->getIndex(ord841, false);
      std::vector<u16> ord843({1, 4, 5, 6, 0, 2, 3, 7, 8, 9});
      slog::Relation* readrel844 = db->getRelation("$sup9688x117x0x0x1");
      $sup9688x117x0x0x1index808 = readrel844->getIndex(ord843, false);
      std::vector<u16> ord845({1, 4, 5, 6, 0, 2, 3, 7, 8, 9});
      slog::Relation* readrel846 = db->getRelation("$sup9688x117x0x0x1");
      $sup9688x117x0x0x1delta819 = readrel846->getIndex(ord845, true);
      std::vector<u16> ord847({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel848 = db->getRelation("$sup9688x117x0x0x0");
      $sup9688x117x0x0x0index809 = readrel848->getIndex(ord847, false);
      std::vector<u16> ord849({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel850 = db->getRelation("$sup9688x117x0x0x0");
      $sup9688x117x0x0x0delta820 = readrel850->getIndex(ord849, true);
      std::vector<u16> ord851({1, 2, 3, 4, 0});
      slog::Relation* readrel852 = db->getRelation("pbranch");
      pbranchindex810 = readrel852->getIndex(ord851, false);
      std::vector<u16> ord853({2, 0, 1});
      slog::Relation* readrel854 = db->getRelation("st_union");
      st_unionindex811 = readrel854->getIndex(ord853, false);
      std::vector<u16> ord855({1, 2, 3, 4, 0});
      slog::Relation* readrel856 = db->getRelation("pbranch");
      pbranchindex812 = readrel856->getIndex(ord855, false);
      std::vector<u16> ord857({1, 2, 3, 4, 0});
      slog::Relation* readrel858 = db->getRelation("pbranch");
      pbranchdelta821 = readrel858->getIndex(ord857, true);
      std::vector<u16> ord859({2, 0, 1});
      slog::Relation* readrel860 = db->getRelation("st_union");
      st_unionindex813 = readrel860->getIndex(ord859, false);
      std::vector<u16> ord861({1, 2, 3, 4, 0});
      slog::Relation* readrel862 = db->getRelation("pbranch");
      pbranchindex814 = readrel862->getIndex(ord861, false);
      std::vector<u16> ord863({1, 2, 3, 4, 0});
      slog::Relation* readrel864 = db->getRelation("pbranch");
      pbranchdelta822 = readrel864->getIndex(ord863, true);
      std::vector<u16> ord865({0, 1, 2});
      slog::Relation* readrel866 = db->getRelation("st_union");
      st_unionindex815 = readrel866->getIndex(ord865, false);
      std::vector<u16> ord867({0, 1, 2});
      slog::Relation* readrel868 = db->getRelation("st_union");
      st_uniondelta823 = readrel868->getIndex(ord867, true);
      std::vector<u16> ord869({1, 2, 0});
      slog::Relation* readrel870 = db->getRelation("st_union");
      st_unionindex816 = readrel870->getIndex(ord869, false);
      std::vector<u16> ord871({1, 2, 0});
      slog::Relation* readrel872 = db->getRelation("st_union");
      st_uniondelta824 = readrel872->getIndex(ord871, true);
      std::vector<u16> ord873({0, 1});
      slog::Relation* readrel874 = db->getRelation("st_union_ans");
      st_union_ansindex817 = readrel874->getIndex(ord873, false);
      std::vector<u16> ord875({0, 1});
      slog::Relation* readrel876 = db->getRelation("st_union_ans");
      st_union_ansdelta825 = readrel876->getIndex(ord875, true);
  
    }
    ReadTask826(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c167 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c168 = _t[0];
        u64 v_c35 = _t[1];
        if (!slog::exists_probe<10,2>($sup9688x117x0x0x1index801, std::array<u64,10>{v_c168, v_c35, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<9,1>($sup9688x117x0x0x0index802, std::array<u64,9>{v_c35, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex803, std::array<u64,5>{v_c35, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(st_mskindex804, st_mskdelta818, std::array<u64,3>{v_c168, 0, 0}, [&](const std::array<u64,3>& m877) {
          u64 v_c1 = m877[1]; u64 v_c36 = m877[2];
          if (!slog::exists_probe<9,3>($sup9688x117x0x0x0index805, std::array<u64,9>{v_c36, v_c1, v_c35, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,2>(pbranchindex806, std::array<u64,5>{v_c35, v_c36, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>(pbranchindex807, std::array<u64,5>{v_c1, 0, 0, 0, 0})) return;
          slog::join_probe_old<10,4>($sup9688x117x0x0x1index808, $sup9688x117x0x0x1delta819, std::array<u64,10>{v_c168, v_c36, v_c1, v_c35, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,10>& m878) {
            u64 v_c169 = m878[4]; u64 v_c6 = m878[5]; u64 v_c2 = m878[6]; u64 v_c7 = m878[7]; u64 v_c3 = m878[8]; u64 v_c4 = m878[9];
            u64 v_c170 = _prim_lt(db, v_c2, v_c36);
            if (v_c170 == slog_error) { slog::emit_pending_error(db, "set.slog:118"); return; }
            if (!v_c170) return;
            slog::join_probe_old<9,9>($sup9688x117x0x0x0index809, $sup9688x117x0x0x0delta820, std::array<u64,9>{v_c35, v_c36, v_c3, v_c4, v_c169, v_c6, v_c2, v_c1, v_c7}, [&](const std::array<u64,9>& m880) {
              if (!slog::exists_probe<5,4>(pbranchindex810, std::array<u64,5>{v_c1, v_c2, v_c6, v_c7, 0})) return;
              if (!slog::exists_probe<3,1>(st_unionindex811, std::array<u64,3>{v_c4, 0, 0})) return;
              slog::join_probe_old<5,4>(pbranchindex812, pbranchdelta821, std::array<u64,5>{v_c35, v_c36, v_c3, v_c4, 0}, [&](const std::array<u64,5>& m881) {
                u64 v_c171 = m881[4];
                if (!slog::exists_probe<3,2>(st_unionindex813, std::array<u64,3>{v_c171, v_c169, 0})) return;
                slog::join_probe_old<5,4>(pbranchindex814, pbranchdelta822, std::array<u64,5>{v_c1, v_c2, v_c6, v_c7, 0}, [&](const std::array<u64,5>& m882) {
                  u64 v_c172 = m882[4];
                  slog::join_probe_old<3,3>(st_unionindex815, st_uniondelta823, std::array<u64,3>{v_c169, v_c172, v_c171}, [&](const std::array<u64,3>& m883) {
                    slog::join_probe_old<3,2>(st_unionindex816, st_uniondelta824, std::array<u64,3>{v_c172, v_c4, 0}, [&](const std::array<u64,3>& m884) {
                      u64 v_c173 = m884[2];
                      slog::join_probe_old<2,1>(st_union_ansindex817, st_union_ansdelta825, std::array<u64,2>{v_c173, 0}, [&](const std::array<u64,2>& m885) {
                        u64 v_c11 = m885[1];
                        u64 v_c174 = _prim_band(db, v_c1, v_c36);
                        if (v_c174 == slog_error) { slog::emit_pending_error(db, "set.slog:118"); return; }
                        u64 v_c175 = _prim_gt(db, v_c174, v_c167);
                        if (v_c175 == slog_error) { slog::emit_pending_error(db, "set.slog:118"); return; }
                        if (!v_c175) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c169, v_c11, v_c36, v_c35, v_c3});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c35, v_c36, v_c3, v_c11}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:118", "delta:st_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask826* _cont = new ReadTask826(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask826(db,b), false);
  // (crule (pre (let __tconst1v9F125 const5feceb66ffc86f38d952786c)) (scan st_union_ans __t4LMh129 __v0) (body (join-old st_union (0 1 2) 1 (0 1 2) __t4LMh129 __t32HA128 v) (exists pbranch (4 0 1 2 3) 1 v) (exists $sup9688x117x0x0x0 (8 0 1 2 3 4 5 6 7) 1 v) (exists $sup9688x117x0x0x1 (9 4 6 8 0 2 3 5 7 1) 1 v) (join-old st_union (1 2 0) 1 (1 2 0) __t32HA128 __t43ng122 __t0ttd124) (exists $sup9688x117x0x0x0 (0 8 1 2 3 4 5 6 7) 2 __t0ttd124 v) (exists $sup9688x117x0x0x1 (0 9 1 2 3 4 5 6 7 8) 2 __t0ttd124 v) (join-old pbranch (4 0 1 2 3) 2 (4 0 1 2 3) v __t43ng122 q n u) (exists $sup9688x117x0x0x1 (9 4 6 8 0 2 3 5 7 1) 5 v n q u __t0ttd124) (exists st_msk (2 0 1) 1 n) (exists st_msk_ans (1 0) 1 q) (join-old $sup9688x117x0x0x0 (5 3 7 8 0 1 2 4 6) 5 (5 3 7 8 0 1 2 4 6) q n u v __t0ttd124 l m p r) (cmp lt m n) (exists pbranch (1 2 3 4 0) 5 p m l r __t32HA128) (exists st_msk (1 2 0) 2 p n) (join-old $sup9688x117x0x0x1 (9 4 6 8 0 2 3 5 7 1) 9 (9 4 6 8 0 2 3 5 7 1) v n q u __t0ttd124 l m p r __t3TTE127) (join-old pbranch (1 2 3 4 0) 5 (1 2 3 4 0) p m l r __t32HA128) (join-old st_msk (1 2 0) 3 (1 2 0) p n __t3TTE127) (join st_msk_ans (0 1) 2 __t3TTE127 q) (let __t3tQC126 (band p n)) (cmp gt __t3tQC126 __tconst1v9F125)) (head (emit-temp temp4p811353 __t0ttd124 __v0 n q u) (mkstruct pbranch (1 2 3 4 0) __t6NgR121 q n u __v0)) set.slog:118 #f)
  class ReadTask912 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_unionindex887;  slog::Index** pbranchindex888;  slog::Index** $sup9688x117x0x0x0index889;  slog::Index** $sup9688x117x0x0x1index890;  slog::Index** st_unionindex891;  slog::Index** $sup9688x117x0x0x0index892;  slog::Index** $sup9688x117x0x0x1index893;  slog::Index** pbranchindex894;  slog::Index** $sup9688x117x0x0x1index895;  slog::Index** st_mskindex896;  slog::Index** st_msk_ansindex897;  slog::Index** $sup9688x117x0x0x0index898;  slog::Index** pbranchindex899;  slog::Index** st_mskindex900;  slog::Index** $sup9688x117x0x0x1index901;  slog::Index** pbranchindex902;  slog::Index** st_mskindex903;  slog::Index** st_msk_ansindex904;  slog::Index** st_uniondelta905;  slog::Index** st_uniondelta906;  slog::Index** pbranchdelta907;  slog::Index** $sup9688x117x0x0x0delta908;  slog::Index** $sup9688x117x0x0x1delta909;  slog::Index** pbranchdelta910;  slog::Index** st_mskdelta911;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4p811353");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("st_union_ans");
      std::vector<u16> ord913({0, 1, 2});
      slog::Relation* readrel914 = db->getRelation("st_union");
      st_unionindex887 = readrel914->getIndex(ord913, false);
      std::vector<u16> ord915({0, 1, 2});
      slog::Relation* readrel916 = db->getRelation("st_union");
      st_uniondelta905 = readrel916->getIndex(ord915, true);
      std::vector<u16> ord917({4, 0, 1, 2, 3});
      slog::Relation* readrel918 = db->getRelation("pbranch");
      pbranchindex888 = readrel918->getIndex(ord917, false);
      std::vector<u16> ord919({8, 0, 1, 2, 3, 4, 5, 6, 7});
      slog::Relation* readrel920 = db->getRelation("$sup9688x117x0x0x0");
      $sup9688x117x0x0x0index889 = readrel920->getIndex(ord919, false);
      std::vector<u16> ord921({9, 4, 6, 8, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel922 = db->getRelation("$sup9688x117x0x0x1");
      $sup9688x117x0x0x1index890 = readrel922->getIndex(ord921, false);
      std::vector<u16> ord923({1, 2, 0});
      slog::Relation* readrel924 = db->getRelation("st_union");
      st_unionindex891 = readrel924->getIndex(ord923, false);
      std::vector<u16> ord925({1, 2, 0});
      slog::Relation* readrel926 = db->getRelation("st_union");
      st_uniondelta906 = readrel926->getIndex(ord925, true);
      std::vector<u16> ord927({0, 8, 1, 2, 3, 4, 5, 6, 7});
      slog::Relation* readrel928 = db->getRelation("$sup9688x117x0x0x0");
      $sup9688x117x0x0x0index892 = readrel928->getIndex(ord927, false);
      std::vector<u16> ord929({0, 9, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel930 = db->getRelation("$sup9688x117x0x0x1");
      $sup9688x117x0x0x1index893 = readrel930->getIndex(ord929, false);
      std::vector<u16> ord931({4, 0, 1, 2, 3});
      slog::Relation* readrel932 = db->getRelation("pbranch");
      pbranchindex894 = readrel932->getIndex(ord931, false);
      std::vector<u16> ord933({4, 0, 1, 2, 3});
      slog::Relation* readrel934 = db->getRelation("pbranch");
      pbranchdelta907 = readrel934->getIndex(ord933, true);
      std::vector<u16> ord935({9, 4, 6, 8, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel936 = db->getRelation("$sup9688x117x0x0x1");
      $sup9688x117x0x0x1index895 = readrel936->getIndex(ord935, false);
      std::vector<u16> ord937({2, 0, 1});
      slog::Relation* readrel938 = db->getRelation("st_msk");
      st_mskindex896 = readrel938->getIndex(ord937, false);
      std::vector<u16> ord939({1, 0});
      slog::Relation* readrel940 = db->getRelation("st_msk_ans");
      st_msk_ansindex897 = readrel940->getIndex(ord939, false);
      std::vector<u16> ord941({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel942 = db->getRelation("$sup9688x117x0x0x0");
      $sup9688x117x0x0x0index898 = readrel942->getIndex(ord941, false);
      std::vector<u16> ord943({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel944 = db->getRelation("$sup9688x117x0x0x0");
      $sup9688x117x0x0x0delta908 = readrel944->getIndex(ord943, true);
      std::vector<u16> ord945({1, 2, 3, 4, 0});
      slog::Relation* readrel946 = db->getRelation("pbranch");
      pbranchindex899 = readrel946->getIndex(ord945, false);
      std::vector<u16> ord947({1, 2, 0});
      slog::Relation* readrel948 = db->getRelation("st_msk");
      st_mskindex900 = readrel948->getIndex(ord947, false);
      std::vector<u16> ord949({9, 4, 6, 8, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel950 = db->getRelation("$sup9688x117x0x0x1");
      $sup9688x117x0x0x1index901 = readrel950->getIndex(ord949, false);
      std::vector<u16> ord951({9, 4, 6, 8, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel952 = db->getRelation("$sup9688x117x0x0x1");
      $sup9688x117x0x0x1delta909 = readrel952->getIndex(ord951, true);
      std::vector<u16> ord953({1, 2, 3, 4, 0});
      slog::Relation* readrel954 = db->getRelation("pbranch");
      pbranchindex902 = readrel954->getIndex(ord953, false);
      std::vector<u16> ord955({1, 2, 3, 4, 0});
      slog::Relation* readrel956 = db->getRelation("pbranch");
      pbranchdelta910 = readrel956->getIndex(ord955, true);
      std::vector<u16> ord957({1, 2, 0});
      slog::Relation* readrel958 = db->getRelation("st_msk");
      st_mskindex903 = readrel958->getIndex(ord957, false);
      std::vector<u16> ord959({1, 2, 0});
      slog::Relation* readrel960 = db->getRelation("st_msk");
      st_mskdelta911 = readrel960->getIndex(ord959, true);
      std::vector<u16> ord961({0, 1});
      slog::Relation* readrel962 = db->getRelation("st_msk_ans");
      st_msk_ansindex904 = readrel962->getIndex(ord961, false);
  
    }
    ReadTask912(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c167 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c173 = _t[0];
        u64 v_c11 = _t[1];
        slog::join_probe_old<3,1>(st_unionindex887, st_uniondelta905, std::array<u64,3>{v_c173, 0, 0}, [&](const std::array<u64,3>& m963) {
          u64 v_c172 = m963[1]; u64 v_c4 = m963[2];
          if (!slog::exists_probe<5,1>(pbranchindex888, std::array<u64,5>{v_c4, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<9,1>($sup9688x117x0x0x0index889, std::array<u64,9>{v_c4, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<10,1>($sup9688x117x0x0x1index890, std::array<u64,10>{v_c4, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          slog::join_probe_old<3,1>(st_unionindex891, st_uniondelta906, std::array<u64,3>{v_c172, 0, 0}, [&](const std::array<u64,3>& m964) {
            u64 v_c171 = m964[1]; u64 v_c169 = m964[2];
            if (!slog::exists_probe<9,2>($sup9688x117x0x0x0index892, std::array<u64,9>{v_c169, v_c4, 0, 0, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<10,2>($sup9688x117x0x0x1index893, std::array<u64,10>{v_c169, v_c4, 0, 0, 0, 0, 0, 0, 0, 0})) return;
            slog::join_probe_old<5,2>(pbranchindex894, pbranchdelta907, std::array<u64,5>{v_c4, v_c171, 0, 0, 0}, [&](const std::array<u64,5>& m965) {
              u64 v_c35 = m965[2]; u64 v_c36 = m965[3]; u64 v_c3 = m965[4];
              if (!slog::exists_probe<10,5>($sup9688x117x0x0x1index895, std::array<u64,10>{v_c4, v_c36, v_c35, v_c3, v_c169, 0, 0, 0, 0, 0})) return;
              if (!slog::exists_probe<3,1>(st_mskindex896, std::array<u64,3>{v_c36, 0, 0})) return;
              if (!slog::exists_probe<2,1>(st_msk_ansindex897, std::array<u64,2>{v_c35, 0})) return;
              slog::join_probe_old<9,5>($sup9688x117x0x0x0index898, $sup9688x117x0x0x0delta908, std::array<u64,9>{v_c35, v_c36, v_c3, v_c4, v_c169, 0, 0, 0, 0}, [&](const std::array<u64,9>& m966) {
                u64 v_c6 = m966[5]; u64 v_c2 = m966[6]; u64 v_c1 = m966[7]; u64 v_c7 = m966[8];
                u64 v_c176 = _prim_lt(db, v_c2, v_c36);
                if (v_c176 == slog_error) { slog::emit_pending_error(db, "set.slog:118"); return; }
                if (!v_c176) return;
                if (!slog::exists_probe<5,5>(pbranchindex899, std::array<u64,5>{v_c1, v_c2, v_c6, v_c7, v_c172})) return;
                if (!slog::exists_probe<3,2>(st_mskindex900, std::array<u64,3>{v_c1, v_c36, 0})) return;
                slog::join_probe_old<10,9>($sup9688x117x0x0x1index901, $sup9688x117x0x0x1delta909, std::array<u64,10>{v_c4, v_c36, v_c35, v_c3, v_c169, v_c6, v_c2, v_c1, v_c7, 0}, [&](const std::array<u64,10>& m968) {
                  u64 v_c168 = m968[9];
                  slog::join_probe_old<5,5>(pbranchindex902, pbranchdelta910, std::array<u64,5>{v_c1, v_c2, v_c6, v_c7, v_c172}, [&](const std::array<u64,5>& m969) {
                    slog::join_probe_old<3,3>(st_mskindex903, st_mskdelta911, std::array<u64,3>{v_c1, v_c36, v_c168}, [&](const std::array<u64,3>& m970) {
                      slog::join_probe<2,2>(st_msk_ansindex904, std::array<u64,2>{v_c168, v_c35}, [&](const std::array<u64,2>& m971) {
                        u64 v_c174 = _prim_band(db, v_c1, v_c36);
                        if (v_c174 == slog_error) { slog::emit_pending_error(db, "set.slog:118"); return; }
                        u64 v_c177 = _prim_gt(db, v_c174, v_c167);
                        if (v_c177 == slog_error) { slog::emit_pending_error(db, "set.slog:118"); return; }
                        if (!v_c177) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c169, v_c11, v_c36, v_c35, v_c3});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c35, v_c36, v_c3, v_c11}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:118", "delta:st_union_ans", _fires);
  
      if (!_done)
      {
        ReadTask912* _cont = new ReadTask912(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask912(db,b), false);
  // (crule (pre (let __trid3pvH1038 const76a4fedc25549f0939d52fb7) (let __trel2E691039 consteea677b485376be09c1a9cc9) (let __tcol5t1r1040 const5feceb66ffc86f38d952786c) (let __trel4TAR1041 consteea677b485376be09c1a9cc9) (let __tcol8vx71042 const6b86b273ff34fce19d6b804e)) (scan $sup9688x88x0x0x0 __d0 k l m p r) (body) (head (tycheck l (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid3pvH1038 __trel2E691039 __tcol5t1r1040 (1 2 3 4 0)) (tycheck k (accept int) __trid3pvH1038 __trel4TAR1041 __tcol8vx71042 (1 2 3 4 0)) (mkstruct st_del (1 2 0) __5t9p1037 l k)) set.slog:89 #f)
  class ReadTask976 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid974;  u32 sid973;  u32 sid975;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("st_del");
      outer_rel = db->getRelation("$sup9688x88x0x0x0");
      sid974 = db->getRelation("_enum")->getStructId();
      sid973 = db->getRelation("pbranch")->getStructId();
      sid975 = db->getRelation("pleaf")->getStructId();
  
    }
    ReadTask976(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c178 = v_const76a4fedc25549f0939d52fb7;
      u64 v_c179 = v_consteea677b485376be09c1a9cc9;
      u64 v_c180 = v_const5feceb66ffc86f38d952786c;
      u64 v_c181 = v_consteea677b485376be09c1a9cc9;
      u64 v_c182 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c28 = _t[0];
        u64 v_c19 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c2 = _t[3];
        u64 v_c1 = _t[4];
        u64 v_c7 = _t[5];
        ++_fires;
        if (!((is_struct(v_c6) && (decode_struct_id(v_c6) == sid973 || decode_struct_id(v_c6) == sid974 || decode_struct_id(v_c6) == sid975))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c178, v_c179, v_c180, v_c6}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c19)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c178, v_c181, v_c182, v_c19}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c6, v_c19}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("set.slog:89", "delta:$sup9688x88x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask976* _cont = new ReadTask976(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask976(db,b), false);
  // (crule (pre (let __tconst5ja6317 const6b86b273ff34fce19d6b804e)) (scan st_msk_ans __t5Q4t319 p) (body (exists $sup9688x50x0x0x1 (1 5 0 2 3 4 6) 2 __t5Q4t319 p) (exists $sup9688x50x0x0x0 (4 2 3 5 0 1) 1 p) (exists pbranch (1 2 3 4 0) 1 p) (join-old st_msk (0 1 2) 1 (0 1 2) __t5Q4t319 k m) (exists $sup9688x50x0x0x0 (1 3 4 0 2 5) 3 k m p) (exists pbranch (1 2 3 4 0) 2 p m) (exists st_ins (2 0 1) 1 k) (join-old $sup9688x50x0x0x1 (1 2 4 5 0 3 6) 4 (1 2 4 5 0 3 6) __t5Q4t319 k m p __t6bST316 l r) (join-old $sup9688x50x0x0x0 (4 2 3 5 0 1) 6 (4 2 3 5 0 1) p l m r __t6bST316 k) (exists st_ins (0 2 1) 2 __t6bST316 k) (exists st_ins (1 2 0) 2 l k) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t8dDI315) (join-old st_ins (0 2 1) 3 (0 2 1) __t6bST316 k __t8dDI315) (join-old st_ins (1 2 0) 2 (1 2 0) l k __t1WXl320) (join-old st_ins_ans (0 1) 1 (0 1) __t1WXl320 __v0) (let __t06Cj318 (band k m)) (cmp lt __t06Cj318 __tconst5ja6317)) (head (emit-temp temp8kS01399 __t6bST316 __v0 m p r) (mkstruct pbranch (1 2 3 4 0) __t4IGt314 p m __v0 r)) set.slog:51 #f)
  class ReadTask999 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x50x0x0x1index977;  slog::Index** $sup9688x50x0x0x0index978;  slog::Index** pbranchindex979;  slog::Index** st_mskindex980;  slog::Index** $sup9688x50x0x0x0index981;  slog::Index** pbranchindex982;  slog::Index** st_insindex983;  slog::Index** $sup9688x50x0x0x1index984;  slog::Index** $sup9688x50x0x0x0index985;  slog::Index** st_insindex986;  slog::Index** st_insindex987;  slog::Index** pbranchindex988;  slog::Index** st_insindex989;  slog::Index** st_insindex990;  slog::Index** st_ins_ansindex991;  slog::Index** st_mskdelta992;  slog::Index** $sup9688x50x0x0x1delta993;  slog::Index** $sup9688x50x0x0x0delta994;  slog::Index** pbranchdelta995;  slog::Index** st_insdelta996;  slog::Index** st_insdelta997;  slog::Index** st_ins_ansdelta998;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8kS01399");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("st_msk_ans");
      std::vector<u16> ord1000({1, 5, 0, 2, 3, 4, 6});
      slog::Relation* readrel1001 = db->getRelation("$sup9688x50x0x0x1");
      $sup9688x50x0x0x1index977 = readrel1001->getIndex(ord1000, false);
      std::vector<u16> ord1002({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel1003 = db->getRelation("$sup9688x50x0x0x0");
      $sup9688x50x0x0x0index978 = readrel1003->getIndex(ord1002, false);
      std::vector<u16> ord1004({1, 2, 3, 4, 0});
      slog::Relation* readrel1005 = db->getRelation("pbranch");
      pbranchindex979 = readrel1005->getIndex(ord1004, false);
      std::vector<u16> ord1006({0, 1, 2});
      slog::Relation* readrel1007 = db->getRelation("st_msk");
      st_mskindex980 = readrel1007->getIndex(ord1006, false);
      std::vector<u16> ord1008({0, 1, 2});
      slog::Relation* readrel1009 = db->getRelation("st_msk");
      st_mskdelta992 = readrel1009->getIndex(ord1008, true);
      std::vector<u16> ord1010({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel1011 = db->getRelation("$sup9688x50x0x0x0");
      $sup9688x50x0x0x0index981 = readrel1011->getIndex(ord1010, false);
      std::vector<u16> ord1012({1, 2, 3, 4, 0});
      slog::Relation* readrel1013 = db->getRelation("pbranch");
      pbranchindex982 = readrel1013->getIndex(ord1012, false);
      std::vector<u16> ord1014({2, 0, 1});
      slog::Relation* readrel1015 = db->getRelation("st_ins");
      st_insindex983 = readrel1015->getIndex(ord1014, false);
      std::vector<u16> ord1016({1, 2, 4, 5, 0, 3, 6});
      slog::Relation* readrel1017 = db->getRelation("$sup9688x50x0x0x1");
      $sup9688x50x0x0x1index984 = readrel1017->getIndex(ord1016, false);
      std::vector<u16> ord1018({1, 2, 4, 5, 0, 3, 6});
      slog::Relation* readrel1019 = db->getRelation("$sup9688x50x0x0x1");
      $sup9688x50x0x0x1delta993 = readrel1019->getIndex(ord1018, true);
      std::vector<u16> ord1020({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel1021 = db->getRelation("$sup9688x50x0x0x0");
      $sup9688x50x0x0x0index985 = readrel1021->getIndex(ord1020, false);
      std::vector<u16> ord1022({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel1023 = db->getRelation("$sup9688x50x0x0x0");
      $sup9688x50x0x0x0delta994 = readrel1023->getIndex(ord1022, true);
      std::vector<u16> ord1024({0, 2, 1});
      slog::Relation* readrel1025 = db->getRelation("st_ins");
      st_insindex986 = readrel1025->getIndex(ord1024, false);
      std::vector<u16> ord1026({1, 2, 0});
      slog::Relation* readrel1027 = db->getRelation("st_ins");
      st_insindex987 = readrel1027->getIndex(ord1026, false);
      std::vector<u16> ord1028({1, 2, 3, 4, 0});
      slog::Relation* readrel1029 = db->getRelation("pbranch");
      pbranchindex988 = readrel1029->getIndex(ord1028, false);
      std::vector<u16> ord1030({1, 2, 3, 4, 0});
      slog::Relation* readrel1031 = db->getRelation("pbranch");
      pbranchdelta995 = readrel1031->getIndex(ord1030, true);
      std::vector<u16> ord1032({0, 2, 1});
      slog::Relation* readrel1033 = db->getRelation("st_ins");
      st_insindex989 = readrel1033->getIndex(ord1032, false);
      std::vector<u16> ord1034({0, 2, 1});
      slog::Relation* readrel1035 = db->getRelation("st_ins");
      st_insdelta996 = readrel1035->getIndex(ord1034, true);
      std::vector<u16> ord1036({1, 2, 0});
      slog::Relation* readrel1037 = db->getRelation("st_ins");
      st_insindex990 = readrel1037->getIndex(ord1036, false);
      std::vector<u16> ord1038({1, 2, 0});
      slog::Relation* readrel1039 = db->getRelation("st_ins");
      st_insdelta997 = readrel1039->getIndex(ord1038, true);
      std::vector<u16> ord1040({0, 1});
      slog::Relation* readrel1041 = db->getRelation("st_ins_ans");
      st_ins_ansindex991 = readrel1041->getIndex(ord1040, false);
      std::vector<u16> ord1042({0, 1});
      slog::Relation* readrel1043 = db->getRelation("st_ins_ans");
      st_ins_ansdelta998 = readrel1043->getIndex(ord1042, true);
  
    }
    ReadTask999(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c183 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c184 = _t[0];
        u64 v_c1 = _t[1];
        if (!slog::exists_probe<7,2>($sup9688x50x0x0x1index977, std::array<u64,7>{v_c184, v_c1, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<6,1>($sup9688x50x0x0x0index978, std::array<u64,6>{v_c1, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex979, std::array<u64,5>{v_c1, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(st_mskindex980, st_mskdelta992, std::array<u64,3>{v_c184, 0, 0}, [&](const std::array<u64,3>& m1044) {
          u64 v_c19 = m1044[1]; u64 v_c2 = m1044[2];
          if (!slog::exists_probe<6,3>($sup9688x50x0x0x0index981, std::array<u64,6>{v_c19, v_c2, v_c1, 0, 0, 0})) return;
          if (!slog::exists_probe<5,2>(pbranchindex982, std::array<u64,5>{v_c1, v_c2, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(st_insindex983, std::array<u64,3>{v_c19, 0, 0})) return;
          slog::join_probe_old<7,4>($sup9688x50x0x0x1index984, $sup9688x50x0x0x1delta993, std::array<u64,7>{v_c184, v_c19, v_c2, v_c1, 0, 0, 0}, [&](const std::array<u64,7>& m1045) {
            u64 v_c185 = m1045[4]; u64 v_c6 = m1045[5]; u64 v_c7 = m1045[6];
            slog::join_probe_old<6,6>($sup9688x50x0x0x0index985, $sup9688x50x0x0x0delta994, std::array<u64,6>{v_c1, v_c6, v_c2, v_c7, v_c185, v_c19}, [&](const std::array<u64,6>& m1046) {
              if (!slog::exists_probe<3,2>(st_insindex986, std::array<u64,3>{v_c185, v_c19, 0})) return;
              if (!slog::exists_probe<3,2>(st_insindex987, std::array<u64,3>{v_c6, v_c19, 0})) return;
              slog::join_probe_old<5,4>(pbranchindex988, pbranchdelta995, std::array<u64,5>{v_c1, v_c2, v_c6, v_c7, 0}, [&](const std::array<u64,5>& m1047) {
                u64 v_c186 = m1047[4];
                slog::join_probe_old<3,3>(st_insindex989, st_insdelta996, std::array<u64,3>{v_c185, v_c19, v_c186}, [&](const std::array<u64,3>& m1048) {
                  slog::join_probe_old<3,2>(st_insindex990, st_insdelta997, std::array<u64,3>{v_c6, v_c19, 0}, [&](const std::array<u64,3>& m1049) {
                    u64 v_c187 = m1049[2];
                    slog::join_probe_old<2,1>(st_ins_ansindex991, st_ins_ansdelta998, std::array<u64,2>{v_c187, 0}, [&](const std::array<u64,2>& m1050) {
                      u64 v_c11 = m1050[1];
                      u64 v_c188 = _prim_band(db, v_c19, v_c2);
                      if (v_c188 == slog_error) { slog::emit_pending_error(db, "set.slog:51"); return; }
                      u64 v_c189 = _prim_lt(db, v_c188, v_c183);
                      if (v_c189 == slog_error) { slog::emit_pending_error(db, "set.slog:51"); return; }
                      if (!v_c189) return;
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c185, v_c11, v_c2, v_c1, v_c7});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c1, v_c2, v_c11, v_c7}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:51", "delta:st_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask999* _cont = new ReadTask999(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask999(db,b), false);
  // (crule (pre) (scan st_hsb __t81zv171 __t7IWy172) (body (exists st_hsb_ans (0 1) 1 __t81zv171) (join st_hsb_ans (0 1) 1 __t81zv171 __v3) (join st_hsb_ans (0 1) 1 __t81zv171 __v1) (join $sup9688x40x0x0x1 (1 2 0 3 4 5 6) 0 __d1 __v0 __d0 p0 p1 t0 t1) (let chk9lts1342 (bxor p0 p1)) (eq __t7IWy172 chk9lts1342)) (head (emit $sup9688x40x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) __d1 __v0 __v3 __v1 __d0 __t81zv171 __t81zv171 p0 p1 t0 t1)) set.slog:41 #f)
  class ReadTask1056 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_hsb_ansindex1052;  slog::Index** st_hsb_ansindex1053;  slog::Index** st_hsb_ansindex1054;  slog::Index** $sup9688x40x0x0x1index1055;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x40x0x0x2");
      std::vector<u16> ord1057({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel1058 = db->getRelation("$sup9688x40x0x0x2");
      head_index[0] = readrel1058->getIndex(ord1057, false);
      outer_rel = db->getRelation("st_hsb");
      std::vector<u16> ord1059({0, 1});
      slog::Relation* readrel1060 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex1052 = readrel1060->getIndex(ord1059, false);
      std::vector<u16> ord1061({0, 1});
      slog::Relation* readrel1062 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex1053 = readrel1062->getIndex(ord1061, false);
      std::vector<u16> ord1063({0, 1});
      slog::Relation* readrel1064 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex1054 = readrel1064->getIndex(ord1063, false);
      std::vector<u16> ord1065({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel1066 = db->getRelation("$sup9688x40x0x0x1");
      $sup9688x40x0x0x1index1055 = readrel1066->getIndex(ord1065, false);
  
    }
    ReadTask1056(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c190 = _t[0];
        u64 v_c191 = _t[1];
        if (!slog::exists_probe<2,1>(st_hsb_ansindex1052, std::array<u64,2>{v_c190, 0})) return;
        slog::join_probe<2,1>(st_hsb_ansindex1053, std::array<u64,2>{v_c190, 0}, [&](const std::array<u64,2>& m1067) {
          u64 v_c192 = m1067[1];
          slog::join_probe<2,1>(st_hsb_ansindex1054, std::array<u64,2>{v_c190, 0}, [&](const std::array<u64,2>& m1068) {
            u64 v_c12 = m1068[1];
            slog::join_all<7>($sup9688x40x0x0x1index1055, [&](const std::array<u64,7>& m1069) {
              u64 v_c193 = m1069[0]; u64 v_c11 = m1069[1]; u64 v_c28 = m1069[2]; u64 v_c194 = m1069[3]; u64 v_c195 = m1069[4]; u64 v_c196 = m1069[5]; u64 v_c197 = m1069[6];
              u64 v_c198 = _prim_bxor(db, v_c194, v_c195);
              if (v_c198 == slog_error) { slog::emit_pending_error(db, "set.slog:41"); return; }
              if (v_c191 != v_c198) return;
              ++_fires;
              slog::emit<11>(head_rel[0], head_index[0], newbatch[0], std::array<u64,11>{v_c193, v_c11, v_c192, v_c12, v_c28, v_c190, v_c190, v_c194, v_c195, v_c196, v_c197}, std::array<u16,11>{1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:41", "delta:st_hsb", _fires);
  
      if (!_done)
      {
        ReadTask1056* _cont = new ReadTask1056(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1056(db,b), false);
  // (crule (pre (let __tconst0x19246 const6b86b273ff34fce19d6b804e)) (scan st_msk_ans __t3q0j248 p) (body (exists $sup9688x103x0x0x1 (1 5 0 2 3 4 6 7 8 9) 2 __t3q0j248 p) (exists $sup9688x103x0x0x0 (4 0 1 2 3 5 6 7 8) 1 p) (exists pbranch (1 2 3 4 0) 1 p) (join-old st_msk (0 1 2) 1 (0 1 2) __t3q0j248 q m) (exists $sup9688x103x0x0x0 (2 5 4 0 1 3 6 7 8) 3 m q p) (exists pbranch (1 2 3 4 0) 2 p m) (exists pbranch (1 2 3 4 0) 1 q) (join-old $sup9688x103x0x0x1 (1 3 6 5 0 2 4 7 8 9) 4 (1 3 6 5 0 2 4 7 8 9) __t3q0j248 m q p __t3N33245 l n r u v) (cmp lt n m) (join-old $sup9688x103x0x0x0 (1 2 4 6 0 3 5 7 8) 9 (1 2 4 6 0 3 5 7 8) l m p r __t3N33245 n q u v) (exists pbranch (1 2 3 4 0) 4 q n u v) (exists st_union (1 2 0) 1 l) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t2RvE244) (exists st_union (0 1 2) 2 __t3N33245 __t2RvE244) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t8HsZ249) (join-old st_union (0 1 2) 3 (0 1 2) __t3N33245 __t2RvE244 __t8HsZ249) (join-old st_union (1 2 0) 2 (1 2 0) l __t8HsZ249 __t4eoh250) (join-old st_union_ans (0 1) 1 (0 1) __t4eoh250 __v0) (let __t1j57247 (band q m)) (cmp lt __t1j57247 __tconst0x19246)) (head (emit-temp temp9eaB1343 __t3N33245 __v0 m p r) (mkstruct pbranch (1 2 3 4 0) __t2omG242 p m __v0 r)) set.slog:104 #f)
  class ReadTask1095 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x103x0x0x1index1070;  slog::Index** $sup9688x103x0x0x0index1071;  slog::Index** pbranchindex1072;  slog::Index** st_mskindex1073;  slog::Index** $sup9688x103x0x0x0index1074;  slog::Index** pbranchindex1075;  slog::Index** pbranchindex1076;  slog::Index** $sup9688x103x0x0x1index1077;  slog::Index** $sup9688x103x0x0x0index1078;  slog::Index** pbranchindex1079;  slog::Index** st_unionindex1080;  slog::Index** pbranchindex1081;  slog::Index** st_unionindex1082;  slog::Index** pbranchindex1083;  slog::Index** st_unionindex1084;  slog::Index** st_unionindex1085;  slog::Index** st_union_ansindex1086;  slog::Index** st_mskdelta1087;  slog::Index** $sup9688x103x0x0x1delta1088;  slog::Index** $sup9688x103x0x0x0delta1089;  slog::Index** pbranchdelta1090;  slog::Index** pbranchdelta1091;  slog::Index** st_uniondelta1092;  slog::Index** st_uniondelta1093;  slog::Index** st_union_ansdelta1094;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9eaB1343");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("st_msk_ans");
      std::vector<u16> ord1096({1, 5, 0, 2, 3, 4, 6, 7, 8, 9});
      slog::Relation* readrel1097 = db->getRelation("$sup9688x103x0x0x1");
      $sup9688x103x0x0x1index1070 = readrel1097->getIndex(ord1096, false);
      std::vector<u16> ord1098({4, 0, 1, 2, 3, 5, 6, 7, 8});
      slog::Relation* readrel1099 = db->getRelation("$sup9688x103x0x0x0");
      $sup9688x103x0x0x0index1071 = readrel1099->getIndex(ord1098, false);
      std::vector<u16> ord1100({1, 2, 3, 4, 0});
      slog::Relation* readrel1101 = db->getRelation("pbranch");
      pbranchindex1072 = readrel1101->getIndex(ord1100, false);
      std::vector<u16> ord1102({0, 1, 2});
      slog::Relation* readrel1103 = db->getRelation("st_msk");
      st_mskindex1073 = readrel1103->getIndex(ord1102, false);
      std::vector<u16> ord1104({0, 1, 2});
      slog::Relation* readrel1105 = db->getRelation("st_msk");
      st_mskdelta1087 = readrel1105->getIndex(ord1104, true);
      std::vector<u16> ord1106({2, 5, 4, 0, 1, 3, 6, 7, 8});
      slog::Relation* readrel1107 = db->getRelation("$sup9688x103x0x0x0");
      $sup9688x103x0x0x0index1074 = readrel1107->getIndex(ord1106, false);
      std::vector<u16> ord1108({1, 2, 3, 4, 0});
      slog::Relation* readrel1109 = db->getRelation("pbranch");
      pbranchindex1075 = readrel1109->getIndex(ord1108, false);
      std::vector<u16> ord1110({1, 2, 3, 4, 0});
      slog::Relation* readrel1111 = db->getRelation("pbranch");
      pbranchindex1076 = readrel1111->getIndex(ord1110, false);
      std::vector<u16> ord1112({1, 3, 6, 5, 0, 2, 4, 7, 8, 9});
      slog::Relation* readrel1113 = db->getRelation("$sup9688x103x0x0x1");
      $sup9688x103x0x0x1index1077 = readrel1113->getIndex(ord1112, false);
      std::vector<u16> ord1114({1, 3, 6, 5, 0, 2, 4, 7, 8, 9});
      slog::Relation* readrel1115 = db->getRelation("$sup9688x103x0x0x1");
      $sup9688x103x0x0x1delta1088 = readrel1115->getIndex(ord1114, true);
      std::vector<u16> ord1116({1, 2, 4, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel1117 = db->getRelation("$sup9688x103x0x0x0");
      $sup9688x103x0x0x0index1078 = readrel1117->getIndex(ord1116, false);
      std::vector<u16> ord1118({1, 2, 4, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel1119 = db->getRelation("$sup9688x103x0x0x0");
      $sup9688x103x0x0x0delta1089 = readrel1119->getIndex(ord1118, true);
      std::vector<u16> ord1120({1, 2, 3, 4, 0});
      slog::Relation* readrel1121 = db->getRelation("pbranch");
      pbranchindex1079 = readrel1121->getIndex(ord1120, false);
      std::vector<u16> ord1122({1, 2, 0});
      slog::Relation* readrel1123 = db->getRelation("st_union");
      st_unionindex1080 = readrel1123->getIndex(ord1122, false);
      std::vector<u16> ord1124({1, 2, 3, 4, 0});
      slog::Relation* readrel1125 = db->getRelation("pbranch");
      pbranchindex1081 = readrel1125->getIndex(ord1124, false);
      std::vector<u16> ord1126({1, 2, 3, 4, 0});
      slog::Relation* readrel1127 = db->getRelation("pbranch");
      pbranchdelta1090 = readrel1127->getIndex(ord1126, true);
      std::vector<u16> ord1128({0, 1, 2});
      slog::Relation* readrel1129 = db->getRelation("st_union");
      st_unionindex1082 = readrel1129->getIndex(ord1128, false);
      std::vector<u16> ord1130({1, 2, 3, 4, 0});
      slog::Relation* readrel1131 = db->getRelation("pbranch");
      pbranchindex1083 = readrel1131->getIndex(ord1130, false);
      std::vector<u16> ord1132({1, 2, 3, 4, 0});
      slog::Relation* readrel1133 = db->getRelation("pbranch");
      pbranchdelta1091 = readrel1133->getIndex(ord1132, true);
      std::vector<u16> ord1134({0, 1, 2});
      slog::Relation* readrel1135 = db->getRelation("st_union");
      st_unionindex1084 = readrel1135->getIndex(ord1134, false);
      std::vector<u16> ord1136({0, 1, 2});
      slog::Relation* readrel1137 = db->getRelation("st_union");
      st_uniondelta1092 = readrel1137->getIndex(ord1136, true);
      std::vector<u16> ord1138({1, 2, 0});
      slog::Relation* readrel1139 = db->getRelation("st_union");
      st_unionindex1085 = readrel1139->getIndex(ord1138, false);
      std::vector<u16> ord1140({1, 2, 0});
      slog::Relation* readrel1141 = db->getRelation("st_union");
      st_uniondelta1093 = readrel1141->getIndex(ord1140, true);
      std::vector<u16> ord1142({0, 1});
      slog::Relation* readrel1143 = db->getRelation("st_union_ans");
      st_union_ansindex1086 = readrel1143->getIndex(ord1142, false);
      std::vector<u16> ord1144({0, 1});
      slog::Relation* readrel1145 = db->getRelation("st_union_ans");
      st_union_ansdelta1094 = readrel1145->getIndex(ord1144, true);
  
    }
    ReadTask1095(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c199 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c200 = _t[0];
        u64 v_c1 = _t[1];
        if (!slog::exists_probe<10,2>($sup9688x103x0x0x1index1070, std::array<u64,10>{v_c200, v_c1, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<9,1>($sup9688x103x0x0x0index1071, std::array<u64,9>{v_c1, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex1072, std::array<u64,5>{v_c1, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(st_mskindex1073, st_mskdelta1087, std::array<u64,3>{v_c200, 0, 0}, [&](const std::array<u64,3>& m1146) {
          u64 v_c35 = m1146[1]; u64 v_c2 = m1146[2];
          if (!slog::exists_probe<9,3>($sup9688x103x0x0x0index1074, std::array<u64,9>{v_c2, v_c35, v_c1, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,2>(pbranchindex1075, std::array<u64,5>{v_c1, v_c2, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>(pbranchindex1076, std::array<u64,5>{v_c35, 0, 0, 0, 0})) return;
          slog::join_probe_old<10,4>($sup9688x103x0x0x1index1077, $sup9688x103x0x0x1delta1088, std::array<u64,10>{v_c200, v_c2, v_c35, v_c1, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,10>& m1147) {
            u64 v_c201 = m1147[4]; u64 v_c6 = m1147[5]; u64 v_c36 = m1147[6]; u64 v_c7 = m1147[7]; u64 v_c3 = m1147[8]; u64 v_c4 = m1147[9];
            u64 v_c202 = _prim_lt(db, v_c36, v_c2);
            if (v_c202 == slog_error) { slog::emit_pending_error(db, "set.slog:104"); return; }
            if (!v_c202) return;
            slog::join_probe_old<9,9>($sup9688x103x0x0x0index1078, $sup9688x103x0x0x0delta1089, std::array<u64,9>{v_c6, v_c2, v_c1, v_c7, v_c201, v_c36, v_c35, v_c3, v_c4}, [&](const std::array<u64,9>& m1149) {
              if (!slog::exists_probe<5,4>(pbranchindex1079, std::array<u64,5>{v_c35, v_c36, v_c3, v_c4, 0})) return;
              if (!slog::exists_probe<3,1>(st_unionindex1080, std::array<u64,3>{v_c6, 0, 0})) return;
              slog::join_probe_old<5,4>(pbranchindex1081, pbranchdelta1090, std::array<u64,5>{v_c1, v_c2, v_c6, v_c7, 0}, [&](const std::array<u64,5>& m1150) {
                u64 v_c203 = m1150[4];
                if (!slog::exists_probe<3,2>(st_unionindex1082, std::array<u64,3>{v_c201, v_c203, 0})) return;
                slog::join_probe_old<5,4>(pbranchindex1083, pbranchdelta1091, std::array<u64,5>{v_c35, v_c36, v_c3, v_c4, 0}, [&](const std::array<u64,5>& m1151) {
                  u64 v_c204 = m1151[4];
                  slog::join_probe_old<3,3>(st_unionindex1084, st_uniondelta1092, std::array<u64,3>{v_c201, v_c203, v_c204}, [&](const std::array<u64,3>& m1152) {
                    slog::join_probe_old<3,2>(st_unionindex1085, st_uniondelta1093, std::array<u64,3>{v_c6, v_c204, 0}, [&](const std::array<u64,3>& m1153) {
                      u64 v_c205 = m1153[2];
                      slog::join_probe_old<2,1>(st_union_ansindex1086, st_union_ansdelta1094, std::array<u64,2>{v_c205, 0}, [&](const std::array<u64,2>& m1154) {
                        u64 v_c11 = m1154[1];
                        u64 v_c206 = _prim_band(db, v_c35, v_c2);
                        if (v_c206 == slog_error) { slog::emit_pending_error(db, "set.slog:104"); return; }
                        u64 v_c207 = _prim_lt(db, v_c206, v_c199);
                        if (v_c207 == slog_error) { slog::emit_pending_error(db, "set.slog:104"); return; }
                        if (!v_c207) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c201, v_c11, v_c2, v_c1, v_c7});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c1, v_c2, v_c11, v_c7}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:104", "delta:st_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask1095* _cont = new ReadTask1095(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1095(db,b), false);
  // (crule (pre (let __tconst9VVd93 const6b86b273ff34fce19d6b804e) (let __tconst8Blx94 constd4735e3a265e16eee03f5971)) (scan st_hsb_ans __t8W3F96 __v0) (body (join-old st_hsb (0 1) 1 (0 1) __t8W3F96 __t1MAp95) (join-old st_hsb (0 1) 0 (0 1) __t4kHg92 x) (cmp lt __tconst9VVd93 x) (let chk2LjO1271 (_0002f x __tconst8Blx94)) (eq __t1MAp95 chk2LjO1271) (let __t5SLx91 (_0002a __tconst8Blx94 __v0))) (head (emit-temp temp1gVy1270 __t4kHg92 __t5SLx91)) set.slog:29 #f)
  class ReadTask1160 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_hsbindex1156;  slog::Index** st_hsbindex1157;  slog::Index** st_hsbdelta1158;  slog::Index** st_hsbdelta1159;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp1gVy1270");
      outer_rel = db->getRelation("st_hsb_ans");
      std::vector<u16> ord1161({0, 1});
      slog::Relation* readrel1162 = db->getRelation("st_hsb");
      st_hsbindex1156 = readrel1162->getIndex(ord1161, false);
      std::vector<u16> ord1163({0, 1});
      slog::Relation* readrel1164 = db->getRelation("st_hsb");
      st_hsbdelta1158 = readrel1164->getIndex(ord1163, true);
      std::vector<u16> ord1165({0, 1});
      slog::Relation* readrel1166 = db->getRelation("st_hsb");
      st_hsbindex1157 = readrel1166->getIndex(ord1165, false);
      std::vector<u16> ord1167({0, 1});
      slog::Relation* readrel1168 = db->getRelation("st_hsb");
      st_hsbdelta1159 = readrel1168->getIndex(ord1167, true);
  
    }
    ReadTask1160(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c208 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c209 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c210 = _t[0];
        u64 v_c11 = _t[1];
        slog::join_probe_old<2,1>(st_hsbindex1156, st_hsbdelta1158, std::array<u64,2>{v_c210, 0}, [&](const std::array<u64,2>& m1169) {
          u64 v_c211 = m1169[1];
          slog::join_all_old<2>(st_hsbindex1157, st_hsbdelta1159, [&](const std::array<u64,2>& m1170) {
            u64 v_c212 = m1170[0]; u64 v_c59 = m1170[1];
            u64 v_c213 = _prim_lt(db, v_c208, v_c59);
            if (v_c213 == slog_error) { slog::emit_pending_error(db, "set.slog:29"); return; }
            if (!v_c213) return;
            u64 v_c214 = _prim__0002f(db, v_c59, v_c209);
            if (v_c214 == slog_error) { slog::emit_pending_error(db, "set.slog:29"); return; }
            if (v_c211 != v_c214) return;
            u64 v_c215 = _prim__0002a(db, v_c209, v_c11);
            if (v_c215 == slog_error) { slog::emit_pending_error(db, "set.slog:29"); return; }
            ++_fires;
            slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c212, v_c215});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:29", "delta:st_hsb_ans", _fires);
  
      if (!_done)
      {
        ReadTask1160* _cont = new ReadTask1160(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1160(db,b), false);
  // (crule (pre (let __tconst3q0e391 const5feceb66ffc86f38d952786c)) (scan st_diff __t3g0Z390 __t91mZ389 __t4x1d388) (body (join pbranch (0 1 2 3 4) 1 __t4x1d388 q n u v) (join pbranch (0 1 2 3 4) 1 __t91mZ389 p m l r) (cmp lt n m) (let __t2V1B392 (band q m)) (cmp gt __t2V1B392 __tconst3q0e391)) (head (emit $sup9688x142x0x0x0 (0 6 1 2 3 4 5 7 8) __t3g0Z390 r l m n p q u v)) set.slog:143 #f)
  class ReadTask1174 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex1172;  slog::Index** pbranchindex1173;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x142x0x0x0");
      std::vector<u16> ord1175({0, 6, 1, 2, 3, 4, 5, 7, 8});
      slog::Relation* readrel1176 = db->getRelation("$sup9688x142x0x0x0");
      head_index[0] = readrel1176->getIndex(ord1175, false);
      outer_rel = db->getRelation("st_diff");
      std::vector<u16> ord1177({0, 1, 2, 3, 4});
      slog::Relation* readrel1178 = db->getRelation("pbranch");
      pbranchindex1172 = readrel1178->getIndex(ord1177, false);
      std::vector<u16> ord1179({0, 1, 2, 3, 4});
      slog::Relation* readrel1180 = db->getRelation("pbranch");
      pbranchindex1173 = readrel1180->getIndex(ord1179, false);
  
    }
    ReadTask1174(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c216 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c217 = _t[0];
        u64 v_c218 = _t[1];
        u64 v_c219 = _t[2];
        slog::join_probe<5,1>(pbranchindex1172, std::array<u64,5>{v_c219, 0, 0, 0, 0}, [&](const std::array<u64,5>& m1181) {
          u64 v_c35 = m1181[1]; u64 v_c36 = m1181[2]; u64 v_c3 = m1181[3]; u64 v_c4 = m1181[4];
          slog::join_probe<5,1>(pbranchindex1173, std::array<u64,5>{v_c218, 0, 0, 0, 0}, [&](const std::array<u64,5>& m1182) {
            u64 v_c1 = m1182[1]; u64 v_c2 = m1182[2]; u64 v_c6 = m1182[3]; u64 v_c7 = m1182[4];
            u64 v_c220 = _prim_lt(db, v_c36, v_c2);
            if (v_c220 == slog_error) { slog::emit_pending_error(db, "set.slog:143"); return; }
            if (!v_c220) return;
            u64 v_c221 = _prim_band(db, v_c35, v_c2);
            if (v_c221 == slog_error) { slog::emit_pending_error(db, "set.slog:143"); return; }
            u64 v_c222 = _prim_gt(db, v_c221, v_c216);
            if (v_c222 == slog_error) { slog::emit_pending_error(db, "set.slog:143"); return; }
            if (!v_c222) return;
            ++_fires;
            slog::emit<9>(head_rel[0], head_index[0], newbatch[0], std::array<u64,9>{v_c217, v_c7, v_c6, v_c2, v_c36, v_c1, v_c35, v_c3, v_c4}, std::array<u16,9>{0, 6, 1, 2, 3, 4, 5, 7, 8});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:143", "delta:st_diff", _fires);
  
      if (!_done)
      {
        ReadTask1174* _cont = new ReadTask1174(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1174(db,b), false);
  // (crule (pre) (scan st_join __t4hUr14 k __t4JtR13 p __t4iIu12) (body (join pleaf (0 1) 2 __t4JtR13 k) (exists $sup9688x54x0x0x0 (1 4 6 3 0 2 5) 3 k p __t4iIu12) (exists pbranch (0 1 2 3 4) 2 __t4iIu12 p) (exists st_msk (1 2 0) 1 k) (exists st_join_ans (0 1) 1 __t4hUr14) (join st_ins (1 2 0) 2 __t4iIu12 k __t2YgE11) (join $sup9688x54x0x0x0 (0 1 6 4 2 3 5) 4 __t2YgE11 k __t4iIu12 p l m r) (join pbranch (1 2 3 4 0) 5 p m l r __t4iIu12) (join-old st_msk (1 2 0) 2 (1 2 0) k m __t9Q9j15) (join st_msk_ans (0 1) 1 __t9Q9j15 __v0) (neq p __v0) (join st_join_ans (0 1) 1 __t4hUr14 res)) (head (emit st_ins_ans (0 1) __t2YgE11 res)) set.slog:55 #f)
  class ReadTask1197 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pleafindex1185;  slog::Index** $sup9688x54x0x0x0index1186;  slog::Index** pbranchindex1187;  slog::Index** st_mskindex1188;  slog::Index** st_join_ansindex1189;  slog::Index** st_insindex1190;  slog::Index** $sup9688x54x0x0x0index1191;  slog::Index** pbranchindex1192;  slog::Index** st_mskindex1193;  slog::Index** st_msk_ansindex1194;  slog::Index** st_join_ansindex1195;  slog::Index** st_mskdelta1196;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_ins_ans");
      std::vector<u16> ord1198({0, 1});
      slog::Relation* readrel1199 = db->getRelation("st_ins_ans");
      head_index[0] = readrel1199->getIndex(ord1198, false);
      outer_rel = db->getRelation("st_join");
      std::vector<u16> ord1200({0, 1});
      slog::Relation* readrel1201 = db->getRelation("pleaf");
      pleafindex1185 = readrel1201->getIndex(ord1200, false);
      std::vector<u16> ord1202({1, 4, 6, 3, 0, 2, 5});
      slog::Relation* readrel1203 = db->getRelation("$sup9688x54x0x0x0");
      $sup9688x54x0x0x0index1186 = readrel1203->getIndex(ord1202, false);
      std::vector<u16> ord1204({0, 1, 2, 3, 4});
      slog::Relation* readrel1205 = db->getRelation("pbranch");
      pbranchindex1187 = readrel1205->getIndex(ord1204, false);
      std::vector<u16> ord1206({1, 2, 0});
      slog::Relation* readrel1207 = db->getRelation("st_msk");
      st_mskindex1188 = readrel1207->getIndex(ord1206, false);
      std::vector<u16> ord1208({0, 1});
      slog::Relation* readrel1209 = db->getRelation("st_join_ans");
      st_join_ansindex1189 = readrel1209->getIndex(ord1208, false);
      std::vector<u16> ord1210({1, 2, 0});
      slog::Relation* readrel1211 = db->getRelation("st_ins");
      st_insindex1190 = readrel1211->getIndex(ord1210, false);
      std::vector<u16> ord1212({0, 1, 6, 4, 2, 3, 5});
      slog::Relation* readrel1213 = db->getRelation("$sup9688x54x0x0x0");
      $sup9688x54x0x0x0index1191 = readrel1213->getIndex(ord1212, false);
      std::vector<u16> ord1214({1, 2, 3, 4, 0});
      slog::Relation* readrel1215 = db->getRelation("pbranch");
      pbranchindex1192 = readrel1215->getIndex(ord1214, false);
      std::vector<u16> ord1216({1, 2, 0});
      slog::Relation* readrel1217 = db->getRelation("st_msk");
      st_mskindex1193 = readrel1217->getIndex(ord1216, false);
      std::vector<u16> ord1218({1, 2, 0});
      slog::Relation* readrel1219 = db->getRelation("st_msk");
      st_mskdelta1196 = readrel1219->getIndex(ord1218, true);
      std::vector<u16> ord1220({0, 1});
      slog::Relation* readrel1221 = db->getRelation("st_msk_ans");
      st_msk_ansindex1194 = readrel1221->getIndex(ord1220, false);
      std::vector<u16> ord1222({0, 1});
      slog::Relation* readrel1223 = db->getRelation("st_join_ans");
      st_join_ansindex1195 = readrel1223->getIndex(ord1222, false);
  
    }
    ReadTask1197(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c19 = _t[1];
        u64 v_c224 = _t[2];
        u64 v_c1 = _t[3];
        u64 v_c225 = _t[4];
        slog::join_probe<2,2>(pleafindex1185, std::array<u64,2>{v_c224, v_c19}, [&](const std::array<u64,2>& m1224) {
          if (!slog::exists_probe<7,3>($sup9688x54x0x0x0index1186, std::array<u64,7>{v_c19, v_c1, v_c225, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,2>(pbranchindex1187, std::array<u64,5>{v_c225, v_c1, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(st_mskindex1188, std::array<u64,3>{v_c19, 0, 0})) return;
          if (!slog::exists_probe<2,1>(st_join_ansindex1189, std::array<u64,2>{v_c223, 0})) return;
          slog::join_probe<3,2>(st_insindex1190, std::array<u64,3>{v_c225, v_c19, 0}, [&](const std::array<u64,3>& m1225) {
            u64 v_c226 = m1225[2];
            slog::join_probe<7,4>($sup9688x54x0x0x0index1191, std::array<u64,7>{v_c226, v_c19, v_c225, v_c1, 0, 0, 0}, [&](const std::array<u64,7>& m1226) {
              u64 v_c6 = m1226[4]; u64 v_c2 = m1226[5]; u64 v_c7 = m1226[6];
              slog::join_probe<5,5>(pbranchindex1192, std::array<u64,5>{v_c1, v_c2, v_c6, v_c7, v_c225}, [&](const std::array<u64,5>& m1227) {
                slog::join_probe_old<3,2>(st_mskindex1193, st_mskdelta1196, std::array<u64,3>{v_c19, v_c2, 0}, [&](const std::array<u64,3>& m1228) {
                  u64 v_c227 = m1228[2];
                  slog::join_probe<2,1>(st_msk_ansindex1194, std::array<u64,2>{v_c227, 0}, [&](const std::array<u64,2>& m1229) {
                    u64 v_c11 = m1229[1];
                    if (v_c1 == v_c11) return;
                    slog::join_probe<2,1>(st_join_ansindex1195, std::array<u64,2>{v_c223, 0}, [&](const std::array<u64,2>& m1230) {
                      u64 v_c14 = m1230[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c226, v_c14}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:55", "delta:st_join", _fires);
  
      if (!_done)
      {
        ReadTask1197* _cont = new ReadTask1197(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1197(db,b), false);
  // (crule (pre (let __tconst3PZl1055 conste3776bfed7f405de8017ecfa) (let _00024sqc23Xd647 const5feceb66ffc86f38d952786c)) (probe _enum (1 0) 1 __tconst3PZl1055 __t3G7q555) (body (join st_fromlist (0 1) 0 __t8Ndl556 _00024seq0) (letp _00024sql3kOn645 (aslst _00024seq0)) (let chk0LU61351 (llen _00024sql3kOn645)) (eq _00024sqc23Xd647 chk0LU61351)) (head (emit st_fromlist_ans (0 1) __t8Ndl556 __t3G7q555)) set.slog:168 #f)
  class ReadTask1232 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** st_fromlistindex1231;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_fromlist_ans");
      std::vector<u16> ord1233({0, 1});
      slog::Relation* readrel1234 = db->getRelation("st_fromlist_ans");
      head_index[0] = readrel1234->getIndex(ord1233, false);
      std::vector<u16> ord1235({1, 0});
      slog::Relation* readrel1236 = db->getRelation("_enum");
      driver_index = readrel1236->getIndex(ord1235, true);
      std::vector<u16> ord1237({0, 1});
      slog::Relation* readrel1238 = db->getRelation("st_fromlist");
      st_fromlistindex1231 = readrel1238->getIndex(ord1237, false);
  
    }
    ReadTask1232(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c228 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c229 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c228, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m1239) {
        u64 v_c230 = m1239[1];
        if (buckethash(v_c230) != bucket) return;
        slog::join_all<2>(st_fromlistindex1231, [&](const std::array<u64,2>& m1240) {
          u64 v_c231 = m1240[0]; u64 v_c58 = m1240[1];
          bool ok1241 = true;
          u64 v_c232 = _prim_aslst(db, v_c58, &ok1241);
          if (!ok1241) return;
          u64 v_c233 = _prim_llen(db, v_c232);
          if (v_c233 == slog_error) { slog::emit_pending_error(db, "set.slog:168"); return; }
          if (v_c229 != v_c233) return;
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c231, v_c230}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:168", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask1232* _cont = new ReadTask1232(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1232(db,b), true);
  // (crule (pre (let __tconst3UXC251 constef2d127de37b942baad06145)) (scan canon s) (body) (head (mkstruct st_mem0 (1 2 0) __003Y727 s __tconst3UXC251)) st_basic.slog:20 #f)
  class ReadTask1242 : public slog::Task
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
      head_rel[0] = db->getRelation("st_mem0");
      outer_rel = db->getRelation("canon");
  
    }
    ReadTask1242(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c234 = v_constef2d127de37b942baad06145;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c130 = _t[0];
        ++_fires;
        slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c130, v_c234}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("st_basic.slog:20", "delta:canon", _fires);
  
      if (!_done)
      {
        ReadTask1242* _cont = new ReadTask1242(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1242(db,b), false);
  // (crule (pre (let __tconst4buc465 const5feceb66ffc86f38d952786c)) (scan st_join __t4PzE464 p0 t0 p1 t1) (body (join $sup9688x40x0x0x0 (1 0 2 3 4) 5 p0 __t4PzE464 p1 t0 t1) (exists $sup9688x40x0x0x2 (0 7 8 9 10 1 4 2 3 5 6) 5 __t4PzE464 p0 p1 t0 t1) (exists st_msk (1 2 0) 1 p0) (join $sup9688x40x0x0x1 (0 3 4 5 6 1 2) 5 __t4PzE464 p0 p1 t0 t1 __t2flT468 __v0) (exists st_hsb_ans (0 1) 1 __t2flT468) (exists st_hsb_ans (0 1) 2 __t2flT468 __v0) (join $sup9688x40x0x0x2 (0 7 8 9 10 1 4 2 3 5 6) 7 __t4PzE464 p0 p1 t0 t1 __t2flT468 __v0 dup2gd61405 dup5ZAM1406 __v1 __v3) (eq __t2flT468 dup5ZAM1406) (eq __t2flT468 dup2gd61405) (join st_hsb_ans (0 1) 2 __t2flT468 __v3) (join st_hsb_ans (0 1) 2 __t2flT468 __v1) (join st_hsb_ans (0 1) 2 __t2flT468 __v0) (join st_msk (1 2 0) 2 p0 __v1 __t0rt9471) (join st_msk_ans (0 1) 1 __t0rt9471 __v2) (let __t2awV472 (bxor p0 p1)) (join st_hsb (0 1) 2 __t2flT468 __t2awV472) (let __t7pIU466 (band p0 __v0)) (cmp gt __t7pIU466 __tconst4buc465)) (head (emit-temp temp5blj1404 __t4PzE464 __v2 __v3 t0 t1) (mkstruct pbranch (1 2 3 4 0) __t1bKH463 __v2 __v3 t1 t0)) set.slog:41 #f)
  class ReadTask1256 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x40x0x0x0index1243;  slog::Index** $sup9688x40x0x0x2index1244;  slog::Index** st_mskindex1245;  slog::Index** $sup9688x40x0x0x1index1246;  slog::Index** st_hsb_ansindex1247;  slog::Index** st_hsb_ansindex1248;  slog::Index** $sup9688x40x0x0x2index1249;  slog::Index** st_hsb_ansindex1250;  slog::Index** st_hsb_ansindex1251;  slog::Index** st_hsb_ansindex1252;  slog::Index** st_mskindex1253;  slog::Index** st_msk_ansindex1254;  slog::Index** st_hsbindex1255;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5blj1404");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("st_join");
      std::vector<u16> ord1257({1, 0, 2, 3, 4});
      slog::Relation* readrel1258 = db->getRelation("$sup9688x40x0x0x0");
      $sup9688x40x0x0x0index1243 = readrel1258->getIndex(ord1257, false);
      std::vector<u16> ord1259({0, 7, 8, 9, 10, 1, 4, 2, 3, 5, 6});
      slog::Relation* readrel1260 = db->getRelation("$sup9688x40x0x0x2");
      $sup9688x40x0x0x2index1244 = readrel1260->getIndex(ord1259, false);
      std::vector<u16> ord1261({1, 2, 0});
      slog::Relation* readrel1262 = db->getRelation("st_msk");
      st_mskindex1245 = readrel1262->getIndex(ord1261, false);
      std::vector<u16> ord1263({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel1264 = db->getRelation("$sup9688x40x0x0x1");
      $sup9688x40x0x0x1index1246 = readrel1264->getIndex(ord1263, false);
      std::vector<u16> ord1265({0, 1});
      slog::Relation* readrel1266 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex1247 = readrel1266->getIndex(ord1265, false);
      std::vector<u16> ord1267({0, 1});
      slog::Relation* readrel1268 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex1248 = readrel1268->getIndex(ord1267, false);
      std::vector<u16> ord1269({0, 7, 8, 9, 10, 1, 4, 2, 3, 5, 6});
      slog::Relation* readrel1270 = db->getRelation("$sup9688x40x0x0x2");
      $sup9688x40x0x0x2index1249 = readrel1270->getIndex(ord1269, false);
      std::vector<u16> ord1271({0, 1});
      slog::Relation* readrel1272 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex1250 = readrel1272->getIndex(ord1271, false);
      std::vector<u16> ord1273({0, 1});
      slog::Relation* readrel1274 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex1251 = readrel1274->getIndex(ord1273, false);
      std::vector<u16> ord1275({0, 1});
      slog::Relation* readrel1276 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex1252 = readrel1276->getIndex(ord1275, false);
      std::vector<u16> ord1277({1, 2, 0});
      slog::Relation* readrel1278 = db->getRelation("st_msk");
      st_mskindex1253 = readrel1278->getIndex(ord1277, false);
      std::vector<u16> ord1279({0, 1});
      slog::Relation* readrel1280 = db->getRelation("st_msk_ans");
      st_msk_ansindex1254 = readrel1280->getIndex(ord1279, false);
      std::vector<u16> ord1281({0, 1});
      slog::Relation* readrel1282 = db->getRelation("st_hsb");
      st_hsbindex1255 = readrel1282->getIndex(ord1281, false);
  
    }
    ReadTask1256(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c235 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c236 = _t[0];
        u64 v_c194 = _t[1];
        u64 v_c196 = _t[2];
        u64 v_c195 = _t[3];
        u64 v_c197 = _t[4];
        slog::join_probe<5,5>($sup9688x40x0x0x0index1243, std::array<u64,5>{v_c194, v_c236, v_c195, v_c196, v_c197}, [&](const std::array<u64,5>& m1283) {
          if (!slog::exists_probe<11,5>($sup9688x40x0x0x2index1244, std::array<u64,11>{v_c236, v_c194, v_c195, v_c196, v_c197, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(st_mskindex1245, std::array<u64,3>{v_c194, 0, 0})) return;
          slog::join_probe<7,5>($sup9688x40x0x0x1index1246, std::array<u64,7>{v_c236, v_c194, v_c195, v_c196, v_c197, 0, 0}, [&](const std::array<u64,7>& m1284) {
            u64 v_c237 = m1284[5]; u64 v_c11 = m1284[6];
            if (!slog::exists_probe<2,1>(st_hsb_ansindex1247, std::array<u64,2>{v_c237, 0})) return;
            if (!slog::exists_probe<2,2>(st_hsb_ansindex1248, std::array<u64,2>{v_c237, v_c11})) return;
            slog::join_probe<11,7>($sup9688x40x0x0x2index1249, std::array<u64,11>{v_c236, v_c194, v_c195, v_c196, v_c197, v_c237, v_c11, 0, 0, 0, 0}, [&](const std::array<u64,11>& m1285) {
              u64 v_c238 = m1285[7]; u64 v_c239 = m1285[8]; u64 v_c12 = m1285[9]; u64 v_c192 = m1285[10];
              if (v_c237 != v_c239) return;
              if (v_c237 != v_c238) return;
              slog::join_probe<2,2>(st_hsb_ansindex1250, std::array<u64,2>{v_c237, v_c192}, [&](const std::array<u64,2>& m1286) {
                slog::join_probe<2,2>(st_hsb_ansindex1251, std::array<u64,2>{v_c237, v_c12}, [&](const std::array<u64,2>& m1287) {
                  slog::join_probe<2,2>(st_hsb_ansindex1252, std::array<u64,2>{v_c237, v_c11}, [&](const std::array<u64,2>& m1288) {
                    slog::join_probe<3,2>(st_mskindex1253, std::array<u64,3>{v_c194, v_c12, 0}, [&](const std::array<u64,3>& m1289) {
                      u64 v_c240 = m1289[2];
                      slog::join_probe<2,1>(st_msk_ansindex1254, std::array<u64,2>{v_c240, 0}, [&](const std::array<u64,2>& m1290) {
                        u64 v_c241 = m1290[1];
                        u64 v_c242 = _prim_bxor(db, v_c194, v_c195);
                        if (v_c242 == slog_error) { slog::emit_pending_error(db, "set.slog:41"); return; }
                        slog::join_probe<2,2>(st_hsbindex1255, std::array<u64,2>{v_c237, v_c242}, [&](const std::array<u64,2>& m1291) {
                          u64 v_c243 = _prim_band(db, v_c194, v_c11);
                          if (v_c243 == slog_error) { slog::emit_pending_error(db, "set.slog:41"); return; }
                          u64 v_c244 = _prim_gt(db, v_c243, v_c235);
                          if (v_c244 == slog_error) { slog::emit_pending_error(db, "set.slog:41"); return; }
                          if (!v_c244) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c236, v_c241, v_c192, v_c196, v_c197});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c241, v_c192, v_c197, v_c196}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:41", "delta:st_join", _fires);
  
      if (!_done)
      {
        ReadTask1256* _cont = new ReadTask1256(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1256(db,b), false);
  // (crule (pre (let __trid7AMG943 constf2664e0abda1016213c9fa90) (let __trel1lLE944 const26c89ee8ccc4ea998fd1a912) (let __tcol6Qdi945 const5feceb66ffc86f38d952786c) (let __trel7lgp946 const26c89ee8ccc4ea998fd1a912) (let __tcol7D5S947 const6b86b273ff34fce19d6b804e)) (scan $sup9688x136x0x0x0 __d0 l m p r u v) (body (exists st_diff (1 2 0) 2 r v) (join-old st_diff (1 2 0) 2 (1 2 0) l u __t3HZn560) (exists st_diff_ans (0 1) 1 __t3HZn560) (join-old st_diff (1 2 0) 2 (1 2 0) r v __t6exy561) (exists st_diff_ans (0 1) 1 __t6exy561) (join-old st_diff_ans (0 1) 1 (0 1) __t3HZn560 __v0) (join-old st_diff_ans (0 1) 1 (0 1) __t6exy561 __v1)) (head (tycheck p (accept int) __trid7AMG943 __trel1lLE944 __tcol6Qdi945 (1 2 3 4 0)) (tycheck m (accept int) __trid7AMG943 __trel7lgp946 __tcol7D5S947 (1 2 3 4 0)) (mkstruct st_bld (1 2 3 4 0) __7CRS942 p m __v0 __v1)) set.slog:137 #f)
  class ReadTask1304 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_diffindex1293;  slog::Index** st_diffindex1294;  slog::Index** st_diff_ansindex1295;  slog::Index** st_diffindex1296;  slog::Index** st_diff_ansindex1297;  slog::Index** st_diff_ansindex1298;  slog::Index** st_diff_ansindex1299;  slog::Index** st_diffdelta1300;  slog::Index** st_diffdelta1301;  slog::Index** st_diff_ansdelta1302;  slog::Index** st_diff_ansdelta1303;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("st_bld");
      outer_rel = db->getRelation("$sup9688x136x0x0x0");
      std::vector<u16> ord1305({1, 2, 0});
      slog::Relation* readrel1306 = db->getRelation("st_diff");
      st_diffindex1293 = readrel1306->getIndex(ord1305, false);
      std::vector<u16> ord1307({1, 2, 0});
      slog::Relation* readrel1308 = db->getRelation("st_diff");
      st_diffindex1294 = readrel1308->getIndex(ord1307, false);
      std::vector<u16> ord1309({1, 2, 0});
      slog::Relation* readrel1310 = db->getRelation("st_diff");
      st_diffdelta1300 = readrel1310->getIndex(ord1309, true);
      std::vector<u16> ord1311({0, 1});
      slog::Relation* readrel1312 = db->getRelation("st_diff_ans");
      st_diff_ansindex1295 = readrel1312->getIndex(ord1311, false);
      std::vector<u16> ord1313({1, 2, 0});
      slog::Relation* readrel1314 = db->getRelation("st_diff");
      st_diffindex1296 = readrel1314->getIndex(ord1313, false);
      std::vector<u16> ord1315({1, 2, 0});
      slog::Relation* readrel1316 = db->getRelation("st_diff");
      st_diffdelta1301 = readrel1316->getIndex(ord1315, true);
      std::vector<u16> ord1317({0, 1});
      slog::Relation* readrel1318 = db->getRelation("st_diff_ans");
      st_diff_ansindex1297 = readrel1318->getIndex(ord1317, false);
      std::vector<u16> ord1319({0, 1});
      slog::Relation* readrel1320 = db->getRelation("st_diff_ans");
      st_diff_ansindex1298 = readrel1320->getIndex(ord1319, false);
      std::vector<u16> ord1321({0, 1});
      slog::Relation* readrel1322 = db->getRelation("st_diff_ans");
      st_diff_ansdelta1302 = readrel1322->getIndex(ord1321, true);
      std::vector<u16> ord1323({0, 1});
      slog::Relation* readrel1324 = db->getRelation("st_diff_ans");
      st_diff_ansindex1299 = readrel1324->getIndex(ord1323, false);
      std::vector<u16> ord1325({0, 1});
      slog::Relation* readrel1326 = db->getRelation("st_diff_ans");
      st_diff_ansdelta1303 = readrel1326->getIndex(ord1325, true);
  
    }
    ReadTask1304(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c245 = v_constf2664e0abda1016213c9fa90;
      u64 v_c246 = v_const26c89ee8ccc4ea998fd1a912;
      u64 v_c247 = v_const5feceb66ffc86f38d952786c;
      u64 v_c248 = v_const26c89ee8ccc4ea998fd1a912;
      u64 v_c249 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c28 = _t[0];
        u64 v_c6 = _t[1];
        u64 v_c2 = _t[2];
        u64 v_c1 = _t[3];
        u64 v_c7 = _t[4];
        u64 v_c3 = _t[5];
        u64 v_c4 = _t[6];
        if (!slog::exists_probe<3,2>(st_diffindex1293, std::array<u64,3>{v_c7, v_c4, 0})) return;
        slog::join_probe_old<3,2>(st_diffindex1294, st_diffdelta1300, std::array<u64,3>{v_c6, v_c3, 0}, [&](const std::array<u64,3>& m1327) {
          u64 v_c250 = m1327[2];
          if (!slog::exists_probe<2,1>(st_diff_ansindex1295, std::array<u64,2>{v_c250, 0})) return;
          slog::join_probe_old<3,2>(st_diffindex1296, st_diffdelta1301, std::array<u64,3>{v_c7, v_c4, 0}, [&](const std::array<u64,3>& m1328) {
            u64 v_c251 = m1328[2];
            if (!slog::exists_probe<2,1>(st_diff_ansindex1297, std::array<u64,2>{v_c251, 0})) return;
            slog::join_probe_old<2,1>(st_diff_ansindex1298, st_diff_ansdelta1302, std::array<u64,2>{v_c250, 0}, [&](const std::array<u64,2>& m1329) {
              u64 v_c11 = m1329[1];
              slog::join_probe_old<2,1>(st_diff_ansindex1299, st_diff_ansdelta1303, std::array<u64,2>{v_c251, 0}, [&](const std::array<u64,2>& m1330) {
                u64 v_c12 = m1330[1];
                ++_fires;
                if (!(is_int(v_c1)))
                {
                  slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c245, v_c246, v_c247, v_c1}, std::array<u16,5>{1, 2, 3, 4, 0});
                  return;
                }
                if (!(is_int(v_c2)))
                {
                  slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c245, v_c248, v_c249, v_c2}, std::array<u16,5>{1, 2, 3, 4, 0});
                  return;
                }
                slog::emit_struct<5>(head_rel[2], newbatch[2], std::array<u64,4>{v_c1, v_c2, v_c11, v_c12}, std::array<u16,5>{1, 2, 3, 4, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("set.slog:137", "delta:$sup9688x136x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1304* _cont = new ReadTask1304(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1304(db,b), false);
  // (crule (pre (let __tconst9B7m280 const6b86b273ff34fce19d6b804e)) (scan pbranch __t2u9k278 p m l r) (body (exists st_del (1 2 0) 1 __t2u9k278) (exists st_bld (2 1 4 0 3) 3 m p r) (exists st_msk (2 0 1) 1 m) (exists st_msk_ans (1 0) 1 p) (exists st_del (1 2 0) 1 l) (join $sup9688x88x0x0x0 (4 3 5 2 0 1) 4 p m r l __t3OU0279 k) (join-old st_del (0 2 1) 3 (0 2 1) __t3OU0279 k __t2u9k278) (exists st_msk (1 2 0) 2 k m) (exists st_del (1 2 0) 2 l k) (join-old st_bld (2 1 4 0 3) 3 (2 1 4 0 3) m p r __t6UON282 __v0) (exists st_del_ans (1 0) 1 __v0) (exists st_bld_ans (0 1) 1 __t6UON282) (join-old st_msk (1 2 0) 2 (1 2 0) k m __t5pdy283) (join st_msk_ans (0 1) 2 __t5pdy283 p) (join-old st_del (1 2 0) 2 (1 2 0) l k __t62j9284) (join st_del_ans (0 1) 2 __t62j9284 __v0) (join st_bld_ans (0 1) 1 __t6UON282 res) (let __t4Xlx281 (band k m)) (cmp lt __t4Xlx281 __tconst9B7m280)) (head (emit st_del_ans (0 1) __t3OU0279 res)) set.slog:89 #f)
  class ReadTask1352 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_delindex1331;  slog::Index** st_bldindex1332;  slog::Index** st_mskindex1333;  slog::Index** st_msk_ansindex1334;  slog::Index** st_delindex1335;  slog::Index** $sup9688x88x0x0x0index1336;  slog::Index** st_delindex1337;  slog::Index** st_mskindex1338;  slog::Index** st_delindex1339;  slog::Index** st_bldindex1340;  slog::Index** st_del_ansindex1341;  slog::Index** st_bld_ansindex1342;  slog::Index** st_mskindex1343;  slog::Index** st_msk_ansindex1344;  slog::Index** st_delindex1345;  slog::Index** st_del_ansindex1346;  slog::Index** st_bld_ansindex1347;  slog::Index** st_deldelta1348;  slog::Index** st_blddelta1349;  slog::Index** st_mskdelta1350;  slog::Index** st_deldelta1351;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_del_ans");
      std::vector<u16> ord1353({0, 1});
      slog::Relation* readrel1354 = db->getRelation("st_del_ans");
      head_index[0] = readrel1354->getIndex(ord1353, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord1355({1, 2, 0});
      slog::Relation* readrel1356 = db->getRelation("st_del");
      st_delindex1331 = readrel1356->getIndex(ord1355, false);
      std::vector<u16> ord1357({2, 1, 4, 0, 3});
      slog::Relation* readrel1358 = db->getRelation("st_bld");
      st_bldindex1332 = readrel1358->getIndex(ord1357, false);
      std::vector<u16> ord1359({2, 0, 1});
      slog::Relation* readrel1360 = db->getRelation("st_msk");
      st_mskindex1333 = readrel1360->getIndex(ord1359, false);
      std::vector<u16> ord1361({1, 0});
      slog::Relation* readrel1362 = db->getRelation("st_msk_ans");
      st_msk_ansindex1334 = readrel1362->getIndex(ord1361, false);
      std::vector<u16> ord1363({1, 2, 0});
      slog::Relation* readrel1364 = db->getRelation("st_del");
      st_delindex1335 = readrel1364->getIndex(ord1363, false);
      std::vector<u16> ord1365({4, 3, 5, 2, 0, 1});
      slog::Relation* readrel1366 = db->getRelation("$sup9688x88x0x0x0");
      $sup9688x88x0x0x0index1336 = readrel1366->getIndex(ord1365, false);
      std::vector<u16> ord1367({0, 2, 1});
      slog::Relation* readrel1368 = db->getRelation("st_del");
      st_delindex1337 = readrel1368->getIndex(ord1367, false);
      std::vector<u16> ord1369({0, 2, 1});
      slog::Relation* readrel1370 = db->getRelation("st_del");
      st_deldelta1348 = readrel1370->getIndex(ord1369, true);
      std::vector<u16> ord1371({1, 2, 0});
      slog::Relation* readrel1372 = db->getRelation("st_msk");
      st_mskindex1338 = readrel1372->getIndex(ord1371, false);
      std::vector<u16> ord1373({1, 2, 0});
      slog::Relation* readrel1374 = db->getRelation("st_del");
      st_delindex1339 = readrel1374->getIndex(ord1373, false);
      std::vector<u16> ord1375({2, 1, 4, 0, 3});
      slog::Relation* readrel1376 = db->getRelation("st_bld");
      st_bldindex1340 = readrel1376->getIndex(ord1375, false);
      std::vector<u16> ord1377({2, 1, 4, 0, 3});
      slog::Relation* readrel1378 = db->getRelation("st_bld");
      st_blddelta1349 = readrel1378->getIndex(ord1377, true);
      std::vector<u16> ord1379({1, 0});
      slog::Relation* readrel1380 = db->getRelation("st_del_ans");
      st_del_ansindex1341 = readrel1380->getIndex(ord1379, false);
      std::vector<u16> ord1381({0, 1});
      slog::Relation* readrel1382 = db->getRelation("st_bld_ans");
      st_bld_ansindex1342 = readrel1382->getIndex(ord1381, false);
      std::vector<u16> ord1383({1, 2, 0});
      slog::Relation* readrel1384 = db->getRelation("st_msk");
      st_mskindex1343 = readrel1384->getIndex(ord1383, false);
      std::vector<u16> ord1385({1, 2, 0});
      slog::Relation* readrel1386 = db->getRelation("st_msk");
      st_mskdelta1350 = readrel1386->getIndex(ord1385, true);
      std::vector<u16> ord1387({0, 1});
      slog::Relation* readrel1388 = db->getRelation("st_msk_ans");
      st_msk_ansindex1344 = readrel1388->getIndex(ord1387, false);
      std::vector<u16> ord1389({1, 2, 0});
      slog::Relation* readrel1390 = db->getRelation("st_del");
      st_delindex1345 = readrel1390->getIndex(ord1389, false);
      std::vector<u16> ord1391({1, 2, 0});
      slog::Relation* readrel1392 = db->getRelation("st_del");
      st_deldelta1351 = readrel1392->getIndex(ord1391, true);
      std::vector<u16> ord1393({0, 1});
      slog::Relation* readrel1394 = db->getRelation("st_del_ans");
      st_del_ansindex1346 = readrel1394->getIndex(ord1393, false);
      std::vector<u16> ord1395({0, 1});
      slog::Relation* readrel1396 = db->getRelation("st_bld_ans");
      st_bld_ansindex1347 = readrel1396->getIndex(ord1395, false);
  
    }
    ReadTask1352(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c138 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c140 = _t[0];
        u64 v_c1 = _t[1];
        u64 v_c2 = _t[2];
        u64 v_c6 = _t[3];
        u64 v_c7 = _t[4];
        if (!slog::exists_probe<3,1>(st_delindex1331, std::array<u64,3>{v_c140, 0, 0})) return;
        if (!slog::exists_probe<5,3>(st_bldindex1332, std::array<u64,5>{v_c2, v_c1, v_c7, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mskindex1333, std::array<u64,3>{v_c2, 0, 0})) return;
        if (!slog::exists_probe<2,1>(st_msk_ansindex1334, std::array<u64,2>{v_c1, 0})) return;
        if (!slog::exists_probe<3,1>(st_delindex1335, std::array<u64,3>{v_c6, 0, 0})) return;
        slog::join_probe<6,4>($sup9688x88x0x0x0index1336, std::array<u64,6>{v_c1, v_c2, v_c7, v_c6, 0, 0}, [&](const std::array<u64,6>& m1397) {
          u64 v_c139 = m1397[4]; u64 v_c19 = m1397[5];
          slog::join_probe_old<3,3>(st_delindex1337, st_deldelta1348, std::array<u64,3>{v_c139, v_c19, v_c140}, [&](const std::array<u64,3>& m1398) {
            if (!slog::exists_probe<3,2>(st_mskindex1338, std::array<u64,3>{v_c19, v_c2, 0})) return;
            if (!slog::exists_probe<3,2>(st_delindex1339, std::array<u64,3>{v_c6, v_c19, 0})) return;
            slog::join_probe_old<5,3>(st_bldindex1340, st_blddelta1349, std::array<u64,5>{v_c2, v_c1, v_c7, 0, 0}, [&](const std::array<u64,5>& m1399) {
              u64 v_c141 = m1399[3]; u64 v_c11 = m1399[4];
              if (!slog::exists_probe<2,1>(st_del_ansindex1341, std::array<u64,2>{v_c11, 0})) return;
              if (!slog::exists_probe<2,1>(st_bld_ansindex1342, std::array<u64,2>{v_c141, 0})) return;
              slog::join_probe_old<3,2>(st_mskindex1343, st_mskdelta1350, std::array<u64,3>{v_c19, v_c2, 0}, [&](const std::array<u64,3>& m1400) {
                u64 v_c142 = m1400[2];
                slog::join_probe<2,2>(st_msk_ansindex1344, std::array<u64,2>{v_c142, v_c1}, [&](const std::array<u64,2>& m1401) {
                  slog::join_probe_old<3,2>(st_delindex1345, st_deldelta1351, std::array<u64,3>{v_c6, v_c19, 0}, [&](const std::array<u64,3>& m1402) {
                    u64 v_c143 = m1402[2];
                    slog::join_probe<2,2>(st_del_ansindex1346, std::array<u64,2>{v_c143, v_c11}, [&](const std::array<u64,2>& m1403) {
                      slog::join_probe<2,1>(st_bld_ansindex1347, std::array<u64,2>{v_c141, 0}, [&](const std::array<u64,2>& m1404) {
                        u64 v_c14 = m1404[1];
                        u64 v_c144 = _prim_band(db, v_c19, v_c2);
                        if (v_c144 == slog_error) { slog::emit_pending_error(db, "set.slog:89"); return; }
                        u64 v_c252 = _prim_lt(db, v_c144, v_c138);
                        if (v_c252 == slog_error) { slog::emit_pending_error(db, "set.slog:89"); return; }
                        if (!v_c252) return;
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c139, v_c14}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("set.slog:89", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask1352* _cont = new ReadTask1352(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1352(db,b), false);
  // (crule (pre (let __tconst9k1p217 const6b86b273ff34fce19d6b804e)) (scan st_diff __t0V4b216 __t3Raq215 __t1kmq214) (body (join pbranch (0 1 2 3 4) 1 __t1kmq214 q n u v) (join pbranch (0 1 2 3 4) 1 __t3Raq215 p m l r) (cmp lt n m) (let __t76JX218 (band q m)) (cmp lt __t76JX218 __tconst9k1p217)) (head (emit $sup9688x139x0x0x0 (0 1 2 3 4 5 6 7 8) __t0V4b216 l m n p q r u v)) set.slog:140 #f)
  class ReadTask1408 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex1406;  slog::Index** pbranchindex1407;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x139x0x0x0");
      std::vector<u16> ord1409({0, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel1410 = db->getRelation("$sup9688x139x0x0x0");
      head_index[0] = readrel1410->getIndex(ord1409, false);
      outer_rel = db->getRelation("st_diff");
      std::vector<u16> ord1411({0, 1, 2, 3, 4});
      slog::Relation* readrel1412 = db->getRelation("pbranch");
      pbranchindex1406 = readrel1412->getIndex(ord1411, false);
      std::vector<u16> ord1413({0, 1, 2, 3, 4});
      slog::Relation* readrel1414 = db->getRelation("pbranch");
      pbranchindex1407 = readrel1414->getIndex(ord1413, false);
  
    }
    ReadTask1408(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c253 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c256 = _t[2];
        slog::join_probe<5,1>(pbranchindex1406, std::array<u64,5>{v_c256, 0, 0, 0, 0}, [&](const std::array<u64,5>& m1415) {
          u64 v_c35 = m1415[1]; u64 v_c36 = m1415[2]; u64 v_c3 = m1415[3]; u64 v_c4 = m1415[4];
          slog::join_probe<5,1>(pbranchindex1407, std::array<u64,5>{v_c255, 0, 0, 0, 0}, [&](const std::array<u64,5>& m1416) {
            u64 v_c1 = m1416[1]; u64 v_c2 = m1416[2]; u64 v_c6 = m1416[3]; u64 v_c7 = m1416[4];
            u64 v_c257 = _prim_lt(db, v_c36, v_c2);
            if (v_c257 == slog_error) { slog::emit_pending_error(db, "set.slog:140"); return; }
            if (!v_c257) return;
            u64 v_c258 = _prim_band(db, v_c35, v_c2);
            if (v_c258 == slog_error) { slog::emit_pending_error(db, "set.slog:140"); return; }
            u64 v_c259 = _prim_lt(db, v_c258, v_c253);
            if (v_c259 == slog_error) { slog::emit_pending_error(db, "set.slog:140"); return; }
            if (!v_c259) return;
            ++_fires;
            slog::emit<9>(head_rel[0], head_index[0], newbatch[0], std::array<u64,9>{v_c254, v_c6, v_c2, v_c36, v_c1, v_c35, v_c7, v_c3, v_c4}, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:140", "delta:st_diff", _fires);
  
      if (!_done)
      {
        ReadTask1408* _cont = new ReadTask1408(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1408(db,b), false);
  // (crule (pre (let __tconst19LZ687 conste3776bfed7f405de8017ecfa) (let __tconst6nio451 constef2d127de37b942baad06145) (let __tconst5Crw454 constd4735e3a265e16eee03f5971) (let __tconst7cMm457 const2c624232cdd221771294dfbb) (let __tconst776G459 const6b86b273ff34fce19d6b804e)) (scan st_ins_ans __t7DB2460 b) (body (exists _enum (1 0) 1 __tconst19LZ687) (exists st_ins (2 0 1) 1 __tconst6nio451) (exists st_ins (2 0 1) 1 __tconst5Crw454) (exists st_ins (2 0 1) 1 __tconst7cMm457) (join-old st_ins (0 2 1) 2 (0 2 1) __t7DB2460 __tconst776G459 __v1) (exists st_ins_ans (1 0) 1 __v1) (join _enum (1 0) 1 __tconst19LZ687 __t82EP455) (exists st_ins (1 2 0) 2 __t82EP455 __tconst5Crw454) (join-old st_ins (1 2 0) 2 (1 2 0) __t82EP455 __tconst6nio451 __t6TRN453) (exists st_ins_ans (0 1) 1 __t6TRN453) (join-old st_ins (1 2 0) 2 (1 2 0) __t82EP455 __tconst5Crw454 __t7k0a456) (join st_ins_ans (0 1) 2 __t7k0a456 __v1) (join st_ins_ans (0 1) 1 __t6TRN453 __v0) (join-old st_ins (1 2 0) 2 (1 2 0) __v0 __tconst7cMm457 __t6eAo458) (join st_ins_ans (0 1) 1 __t6eAo458 a)) (head (mkstruct st_union (1 2 0) __6Awq688 a b)) st_basic.slog:18 #f)
  class ReadTask1438 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex1419;  slog::Index** st_insindex1420;  slog::Index** st_insindex1421;  slog::Index** st_insindex1422;  slog::Index** st_insindex1423;  slog::Index** st_ins_ansindex1424;  slog::Index** _enumindex1425;  slog::Index** st_insindex1426;  slog::Index** st_insindex1427;  slog::Index** st_ins_ansindex1428;  slog::Index** st_insindex1429;  slog::Index** st_ins_ansindex1430;  slog::Index** st_ins_ansindex1431;  slog::Index** st_insindex1432;  slog::Index** st_ins_ansindex1433;  slog::Index** st_insdelta1434;  slog::Index** st_insdelta1435;  slog::Index** st_insdelta1436;  slog::Index** st_insdelta1437;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_union");
      outer_rel = db->getRelation("st_ins_ans");
      std::vector<u16> ord1439({1, 0});
      slog::Relation* readrel1440 = db->getRelation("_enum");
      _enumindex1419 = readrel1440->getIndex(ord1439, false);
      std::vector<u16> ord1441({2, 0, 1});
      slog::Relation* readrel1442 = db->getRelation("st_ins");
      st_insindex1420 = readrel1442->getIndex(ord1441, false);
      std::vector<u16> ord1443({2, 0, 1});
      slog::Relation* readrel1444 = db->getRelation("st_ins");
      st_insindex1421 = readrel1444->getIndex(ord1443, false);
      std::vector<u16> ord1445({2, 0, 1});
      slog::Relation* readrel1446 = db->getRelation("st_ins");
      st_insindex1422 = readrel1446->getIndex(ord1445, false);
      std::vector<u16> ord1447({0, 2, 1});
      slog::Relation* readrel1448 = db->getRelation("st_ins");
      st_insindex1423 = readrel1448->getIndex(ord1447, false);
      std::vector<u16> ord1449({0, 2, 1});
      slog::Relation* readrel1450 = db->getRelation("st_ins");
      st_insdelta1434 = readrel1450->getIndex(ord1449, true);
      std::vector<u16> ord1451({1, 0});
      slog::Relation* readrel1452 = db->getRelation("st_ins_ans");
      st_ins_ansindex1424 = readrel1452->getIndex(ord1451, false);
      std::vector<u16> ord1453({1, 0});
      slog::Relation* readrel1454 = db->getRelation("_enum");
      _enumindex1425 = readrel1454->getIndex(ord1453, false);
      std::vector<u16> ord1455({1, 2, 0});
      slog::Relation* readrel1456 = db->getRelation("st_ins");
      st_insindex1426 = readrel1456->getIndex(ord1455, false);
      std::vector<u16> ord1457({1, 2, 0});
      slog::Relation* readrel1458 = db->getRelation("st_ins");
      st_insindex1427 = readrel1458->getIndex(ord1457, false);
      std::vector<u16> ord1459({1, 2, 0});
      slog::Relation* readrel1460 = db->getRelation("st_ins");
      st_insdelta1435 = readrel1460->getIndex(ord1459, true);
      std::vector<u16> ord1461({0, 1});
      slog::Relation* readrel1462 = db->getRelation("st_ins_ans");
      st_ins_ansindex1428 = readrel1462->getIndex(ord1461, false);
      std::vector<u16> ord1463({1, 2, 0});
      slog::Relation* readrel1464 = db->getRelation("st_ins");
      st_insindex1429 = readrel1464->getIndex(ord1463, false);
      std::vector<u16> ord1465({1, 2, 0});
      slog::Relation* readrel1466 = db->getRelation("st_ins");
      st_insdelta1436 = readrel1466->getIndex(ord1465, true);
      std::vector<u16> ord1467({0, 1});
      slog::Relation* readrel1468 = db->getRelation("st_ins_ans");
      st_ins_ansindex1430 = readrel1468->getIndex(ord1467, false);
      std::vector<u16> ord1469({0, 1});
      slog::Relation* readrel1470 = db->getRelation("st_ins_ans");
      st_ins_ansindex1431 = readrel1470->getIndex(ord1469, false);
      std::vector<u16> ord1471({1, 2, 0});
      slog::Relation* readrel1472 = db->getRelation("st_ins");
      st_insindex1432 = readrel1472->getIndex(ord1471, false);
      std::vector<u16> ord1473({1, 2, 0});
      slog::Relation* readrel1474 = db->getRelation("st_ins");
      st_insdelta1437 = readrel1474->getIndex(ord1473, true);
      std::vector<u16> ord1475({0, 1});
      slog::Relation* readrel1476 = db->getRelation("st_ins_ans");
      st_ins_ansindex1433 = readrel1476->getIndex(ord1475, false);
  
    }
    ReadTask1438(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c260 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c261 = v_constef2d127de37b942baad06145;
      u64 v_c262 = v_constd4735e3a265e16eee03f5971;
      u64 v_c263 = v_const2c624232cdd221771294dfbb;
      u64 v_c264 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c265 = _t[0];
        u64 v_c157 = _t[1];
        if (!slog::exists_probe<2,1>(_enumindex1419, std::array<u64,2>{v_c260, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex1420, std::array<u64,3>{v_c261, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex1421, std::array<u64,3>{v_c262, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex1422, std::array<u64,3>{v_c263, 0, 0})) return;
        slog::join_probe_old<3,2>(st_insindex1423, st_insdelta1434, std::array<u64,3>{v_c265, v_c264, 0}, [&](const std::array<u64,3>& m1477) {
          u64 v_c12 = m1477[2];
          if (!slog::exists_probe<2,1>(st_ins_ansindex1424, std::array<u64,2>{v_c12, 0})) return;
          slog::join_probe<2,1>(_enumindex1425, std::array<u64,2>{v_c260, 0}, [&](const std::array<u64,2>& m1478) {
            u64 v_c266 = m1478[1];
            if (!slog::exists_probe<3,2>(st_insindex1426, std::array<u64,3>{v_c266, v_c262, 0})) return;
            slog::join_probe_old<3,2>(st_insindex1427, st_insdelta1435, std::array<u64,3>{v_c266, v_c261, 0}, [&](const std::array<u64,3>& m1479) {
              u64 v_c267 = m1479[2];
              if (!slog::exists_probe<2,1>(st_ins_ansindex1428, std::array<u64,2>{v_c267, 0})) return;
              slog::join_probe_old<3,2>(st_insindex1429, st_insdelta1436, std::array<u64,3>{v_c266, v_c262, 0}, [&](const std::array<u64,3>& m1480) {
                u64 v_c268 = m1480[2];
                slog::join_probe<2,2>(st_ins_ansindex1430, std::array<u64,2>{v_c268, v_c12}, [&](const std::array<u64,2>& m1481) {
                  slog::join_probe<2,1>(st_ins_ansindex1431, std::array<u64,2>{v_c267, 0}, [&](const std::array<u64,2>& m1482) {
                    u64 v_c11 = m1482[1];
                    slog::join_probe_old<3,2>(st_insindex1432, st_insdelta1437, std::array<u64,3>{v_c11, v_c263, 0}, [&](const std::array<u64,3>& m1483) {
                      u64 v_c269 = m1483[2];
                      slog::join_probe<2,1>(st_ins_ansindex1433, std::array<u64,2>{v_c269, 0}, [&](const std::array<u64,2>& m1484) {
                        u64 v_c156 = m1484[1];
                        ++_fires;
                        slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c156, v_c157}, std::array<u16,3>{1, 2, 0});
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
        ReadTask1438* _cont = new ReadTask1438(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1438(db,b), false);
  // (crule (pre (let __tconst7Gyt29 const6b86b273ff34fce19d6b804e)) (scan st_mem0 __t7Db431 __t53uv30 k) (body (join pleaf (0 1) 2 __t53uv30 k)) (head (emit st_mem0_ans (0 1) __t7Db431 __tconst7Gyt29)) set.slog:68 #f)
  class ReadTask1486 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pleafindex1485;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_mem0_ans");
      std::vector<u16> ord1487({0, 1});
      slog::Relation* readrel1488 = db->getRelation("st_mem0_ans");
      head_index[0] = readrel1488->getIndex(ord1487, false);
      outer_rel = db->getRelation("st_mem0");
      std::vector<u16> ord1489({0, 1});
      slog::Relation* readrel1490 = db->getRelation("pleaf");
      pleafindex1485 = readrel1490->getIndex(ord1489, false);
  
    }
    ReadTask1486(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c270 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c271 = _t[0];
        u64 v_c272 = _t[1];
        u64 v_c19 = _t[2];
        slog::join_probe<2,2>(pleafindex1485, std::array<u64,2>{v_c272, v_c19}, [&](const std::array<u64,2>& m1491) {
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c271, v_c270}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:68", "delta:st_mem0", _fires);
  
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
  // (crule (pre (let __tconst9YUA1125 conste3776bfed7f405de8017ecfa) (let __tconst7TTg43 constef2d127de37b942baad06145) (let __tconst35F246 const2c624232cdd221771294dfbb) (let __tconst0QyJ48 constd4735e3a265e16eee03f5971) (let __tconst6ZQr51 const6b86b273ff34fce19d6b804e)) (scan st_ins_ans __t7CuH52 b) (body (exists _enum (1 0) 1 __tconst9YUA1125) (exists st_ins (2 0 1) 1 __tconst7TTg43) (exists st_ins (2 0 1) 1 __tconst0QyJ48) (exists st_ins (2 0 1) 1 __tconst35F246) (exists st_union (2 0 1) 1 b) (join-old st_ins (0 2 1) 2 (0 2 1) __t7CuH52 __tconst6ZQr51 __v1) (exists st_ins_ans (1 0) 1 __v1) (join _enum (1 0) 1 __tconst9YUA1125 __t7Lp349) (exists st_ins (1 2 0) 2 __t7Lp349 __tconst0QyJ48) (join-old st_ins (1 2 0) 2 (1 2 0) __t7Lp349 __tconst7TTg43 __t8j8m45) (exists st_ins_ans (0 1) 1 __t8j8m45) (join-old st_ins (1 2 0) 2 (1 2 0) __t7Lp349 __tconst0QyJ48 __t3nMl50) (join st_ins_ans (0 1) 2 __t3nMl50 __v1) (join st_ins_ans (0 1) 1 __t8j8m45 __v0) (join-old st_ins (1 2 0) 2 (1 2 0) __v0 __tconst35F246 __t4CDi47) (join st_ins_ans (0 1) 1 __t4CDi47 a) (join-old st_union (1 2 0) 2 (1 2 0) a b __t8gtb53) (join-old st_union_ans (0 1) 1 (0 1) __t8gtb53 r)) (head (emit canon (0) r)) st_basic.slog:18 #f)
  class ReadTask1516 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex1492;  slog::Index** st_insindex1493;  slog::Index** st_insindex1494;  slog::Index** st_insindex1495;  slog::Index** st_unionindex1496;  slog::Index** st_insindex1497;  slog::Index** st_ins_ansindex1498;  slog::Index** _enumindex1499;  slog::Index** st_insindex1500;  slog::Index** st_insindex1501;  slog::Index** st_ins_ansindex1502;  slog::Index** st_insindex1503;  slog::Index** st_ins_ansindex1504;  slog::Index** st_ins_ansindex1505;  slog::Index** st_insindex1506;  slog::Index** st_ins_ansindex1507;  slog::Index** st_unionindex1508;  slog::Index** st_union_ansindex1509;  slog::Index** st_insdelta1510;  slog::Index** st_insdelta1511;  slog::Index** st_insdelta1512;  slog::Index** st_insdelta1513;  slog::Index** st_uniondelta1514;  slog::Index** st_union_ansdelta1515;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("canon");
      std::vector<u16> ord1517({0});
      slog::Relation* readrel1518 = db->getRelation("canon");
      head_index[0] = readrel1518->getIndex(ord1517, false);
      outer_rel = db->getRelation("st_ins_ans");
      std::vector<u16> ord1519({1, 0});
      slog::Relation* readrel1520 = db->getRelation("_enum");
      _enumindex1492 = readrel1520->getIndex(ord1519, false);
      std::vector<u16> ord1521({2, 0, 1});
      slog::Relation* readrel1522 = db->getRelation("st_ins");
      st_insindex1493 = readrel1522->getIndex(ord1521, false);
      std::vector<u16> ord1523({2, 0, 1});
      slog::Relation* readrel1524 = db->getRelation("st_ins");
      st_insindex1494 = readrel1524->getIndex(ord1523, false);
      std::vector<u16> ord1525({2, 0, 1});
      slog::Relation* readrel1526 = db->getRelation("st_ins");
      st_insindex1495 = readrel1526->getIndex(ord1525, false);
      std::vector<u16> ord1527({2, 0, 1});
      slog::Relation* readrel1528 = db->getRelation("st_union");
      st_unionindex1496 = readrel1528->getIndex(ord1527, false);
      std::vector<u16> ord1529({0, 2, 1});
      slog::Relation* readrel1530 = db->getRelation("st_ins");
      st_insindex1497 = readrel1530->getIndex(ord1529, false);
      std::vector<u16> ord1531({0, 2, 1});
      slog::Relation* readrel1532 = db->getRelation("st_ins");
      st_insdelta1510 = readrel1532->getIndex(ord1531, true);
      std::vector<u16> ord1533({1, 0});
      slog::Relation* readrel1534 = db->getRelation("st_ins_ans");
      st_ins_ansindex1498 = readrel1534->getIndex(ord1533, false);
      std::vector<u16> ord1535({1, 0});
      slog::Relation* readrel1536 = db->getRelation("_enum");
      _enumindex1499 = readrel1536->getIndex(ord1535, false);
      std::vector<u16> ord1537({1, 2, 0});
      slog::Relation* readrel1538 = db->getRelation("st_ins");
      st_insindex1500 = readrel1538->getIndex(ord1537, false);
      std::vector<u16> ord1539({1, 2, 0});
      slog::Relation* readrel1540 = db->getRelation("st_ins");
      st_insindex1501 = readrel1540->getIndex(ord1539, false);
      std::vector<u16> ord1541({1, 2, 0});
      slog::Relation* readrel1542 = db->getRelation("st_ins");
      st_insdelta1511 = readrel1542->getIndex(ord1541, true);
      std::vector<u16> ord1543({0, 1});
      slog::Relation* readrel1544 = db->getRelation("st_ins_ans");
      st_ins_ansindex1502 = readrel1544->getIndex(ord1543, false);
      std::vector<u16> ord1545({1, 2, 0});
      slog::Relation* readrel1546 = db->getRelation("st_ins");
      st_insindex1503 = readrel1546->getIndex(ord1545, false);
      std::vector<u16> ord1547({1, 2, 0});
      slog::Relation* readrel1548 = db->getRelation("st_ins");
      st_insdelta1512 = readrel1548->getIndex(ord1547, true);
      std::vector<u16> ord1549({0, 1});
      slog::Relation* readrel1550 = db->getRelation("st_ins_ans");
      st_ins_ansindex1504 = readrel1550->getIndex(ord1549, false);
      std::vector<u16> ord1551({0, 1});
      slog::Relation* readrel1552 = db->getRelation("st_ins_ans");
      st_ins_ansindex1505 = readrel1552->getIndex(ord1551, false);
      std::vector<u16> ord1553({1, 2, 0});
      slog::Relation* readrel1554 = db->getRelation("st_ins");
      st_insindex1506 = readrel1554->getIndex(ord1553, false);
      std::vector<u16> ord1555({1, 2, 0});
      slog::Relation* readrel1556 = db->getRelation("st_ins");
      st_insdelta1513 = readrel1556->getIndex(ord1555, true);
      std::vector<u16> ord1557({0, 1});
      slog::Relation* readrel1558 = db->getRelation("st_ins_ans");
      st_ins_ansindex1507 = readrel1558->getIndex(ord1557, false);
      std::vector<u16> ord1559({1, 2, 0});
      slog::Relation* readrel1560 = db->getRelation("st_union");
      st_unionindex1508 = readrel1560->getIndex(ord1559, false);
      std::vector<u16> ord1561({1, 2, 0});
      slog::Relation* readrel1562 = db->getRelation("st_union");
      st_uniondelta1514 = readrel1562->getIndex(ord1561, true);
      std::vector<u16> ord1563({0, 1});
      slog::Relation* readrel1564 = db->getRelation("st_union_ans");
      st_union_ansindex1509 = readrel1564->getIndex(ord1563, false);
      std::vector<u16> ord1565({0, 1});
      slog::Relation* readrel1566 = db->getRelation("st_union_ans");
      st_union_ansdelta1515 = readrel1566->getIndex(ord1565, true);
  
    }
    ReadTask1516(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c146 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c147 = v_constef2d127de37b942baad06145;
      u64 v_c148 = v_const2c624232cdd221771294dfbb;
      u64 v_c149 = v_constd4735e3a265e16eee03f5971;
      u64 v_c150 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c158 = _t[0];
        u64 v_c157 = _t[1];
        if (!slog::exists_probe<2,1>(_enumindex1492, std::array<u64,2>{v_c146, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex1493, std::array<u64,3>{v_c147, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex1494, std::array<u64,3>{v_c149, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex1495, std::array<u64,3>{v_c148, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_unionindex1496, std::array<u64,3>{v_c157, 0, 0})) return;
        slog::join_probe_old<3,2>(st_insindex1497, st_insdelta1510, std::array<u64,3>{v_c158, v_c150, 0}, [&](const std::array<u64,3>& m1567) {
          u64 v_c12 = m1567[2];
          if (!slog::exists_probe<2,1>(st_ins_ansindex1498, std::array<u64,2>{v_c12, 0})) return;
          slog::join_probe<2,1>(_enumindex1499, std::array<u64,2>{v_c146, 0}, [&](const std::array<u64,2>& m1568) {
            u64 v_c152 = m1568[1];
            if (!slog::exists_probe<3,2>(st_insindex1500, std::array<u64,3>{v_c152, v_c149, 0})) return;
            slog::join_probe_old<3,2>(st_insindex1501, st_insdelta1511, std::array<u64,3>{v_c152, v_c147, 0}, [&](const std::array<u64,3>& m1569) {
              u64 v_c153 = m1569[2];
              if (!slog::exists_probe<2,1>(st_ins_ansindex1502, std::array<u64,2>{v_c153, 0})) return;
              slog::join_probe_old<3,2>(st_insindex1503, st_insdelta1512, std::array<u64,3>{v_c152, v_c149, 0}, [&](const std::array<u64,3>& m1570) {
                u64 v_c154 = m1570[2];
                slog::join_probe<2,2>(st_ins_ansindex1504, std::array<u64,2>{v_c154, v_c12}, [&](const std::array<u64,2>& m1571) {
                  slog::join_probe<2,1>(st_ins_ansindex1505, std::array<u64,2>{v_c153, 0}, [&](const std::array<u64,2>& m1572) {
                    u64 v_c11 = m1572[1];
                    slog::join_probe_old<3,2>(st_insindex1506, st_insdelta1513, std::array<u64,3>{v_c11, v_c148, 0}, [&](const std::array<u64,3>& m1573) {
                      u64 v_c155 = m1573[2];
                      slog::join_probe<2,1>(st_ins_ansindex1507, std::array<u64,2>{v_c155, 0}, [&](const std::array<u64,2>& m1574) {
                        u64 v_c156 = m1574[1];
                        slog::join_probe_old<3,2>(st_unionindex1508, st_uniondelta1514, std::array<u64,3>{v_c156, v_c157, 0}, [&](const std::array<u64,3>& m1575) {
                          u64 v_c151 = m1575[2];
                          slog::join_probe_old<2,1>(st_union_ansindex1509, st_union_ansdelta1515, std::array<u64,2>{v_c151, 0}, [&](const std::array<u64,2>& m1576) {
                            u64 v_c7 = m1576[1];
                            ++_fires;
                            slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c7}, std::array<u16,1>{0});
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
        ReadTask1516* _cont = new ReadTask1516(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1516(db,b), false);
  // (crule (pre) (scan pbranch __t1YwN512 p m l r) (body (join-old st_diff (1 2 0) 1 (1 2 0) __t1YwN512 __t2KHS511 __t5hAF513) (join pbranch (0 1 2 3 4) 1 __t2KHS511 q n u v) (cmp lt n m)) (head (emit $sup9688x145x0x0x0 (0 1 2 3 4 5 6 7 8) __t5hAF513 l m n p q r u v)) set.slog:146 #f)
  class ReadTask1580 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_diffindex1577;  slog::Index** pbranchindex1578;  slog::Index** st_diffdelta1579;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x145x0x0x0");
      std::vector<u16> ord1581({0, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel1582 = db->getRelation("$sup9688x145x0x0x0");
      head_index[0] = readrel1582->getIndex(ord1581, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord1583({1, 2, 0});
      slog::Relation* readrel1584 = db->getRelation("st_diff");
      st_diffindex1577 = readrel1584->getIndex(ord1583, false);
      std::vector<u16> ord1585({1, 2, 0});
      slog::Relation* readrel1586 = db->getRelation("st_diff");
      st_diffdelta1579 = readrel1586->getIndex(ord1585, true);
      std::vector<u16> ord1587({0, 1, 2, 3, 4});
      slog::Relation* readrel1588 = db->getRelation("pbranch");
      pbranchindex1578 = readrel1588->getIndex(ord1587, false);
  
    }
    ReadTask1580(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c273 = _t[0];
        u64 v_c1 = _t[1];
        u64 v_c2 = _t[2];
        u64 v_c6 = _t[3];
        u64 v_c7 = _t[4];
        slog::join_probe_old<3,1>(st_diffindex1577, st_diffdelta1579, std::array<u64,3>{v_c273, 0, 0}, [&](const std::array<u64,3>& m1589) {
          u64 v_c274 = m1589[1]; u64 v_c275 = m1589[2];
          slog::join_probe<5,1>(pbranchindex1578, std::array<u64,5>{v_c274, 0, 0, 0, 0}, [&](const std::array<u64,5>& m1590) {
            u64 v_c35 = m1590[1]; u64 v_c36 = m1590[2]; u64 v_c3 = m1590[3]; u64 v_c4 = m1590[4];
            u64 v_c276 = _prim_lt(db, v_c36, v_c2);
            if (v_c276 == slog_error) { slog::emit_pending_error(db, "set.slog:146"); return; }
            if (!v_c276) return;
            ++_fires;
            slog::emit<9>(head_rel[0], head_index[0], newbatch[0], std::array<u64,9>{v_c275, v_c6, v_c2, v_c36, v_c1, v_c35, v_c7, v_c3, v_c4}, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:146", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask1580* _cont = new ReadTask1580(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1580(db,b), false);
  // (crule (pre) (scan temp18xQ1344 n q r u v) (body (join pbranch (1 2 3 4 0) 4 q n u v __t1FMB110)) (head (mkstruct st_union (1 2 0) __1kxy921 r __t1FMB110)) set.slog:107 #f)
  class ReadTask1593 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex1592;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_union");
      outer_rel = db->getRelation("temp18xQ1344");
      std::vector<u16> ord1594({1, 2, 3, 4, 0});
      slog::Relation* readrel1595 = db->getRelation("pbranch");
      pbranchindex1592 = readrel1595->getIndex(ord1594, false);
  
    }
    ReadTask1593(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c36 = _t[0];
        u64 v_c35 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c3 = _t[3];
        u64 v_c4 = _t[4];
        slog::join_probe<5,4>(pbranchindex1592, std::array<u64,5>{v_c35, v_c36, v_c3, v_c4, 0}, [&](const std::array<u64,5>& m1596) {
          u64 v_c277 = m1596[4];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c7, v_c277}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:107", "delta:temp18xQ1344", _fires);
  
      if (!_done)
      {
        ReadTask1593* _cont = new ReadTask1593(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1593(db,b), false);
  // (crule (pre) (scan pleaf __t2ibk186 k) (body (join-old st_union (1 2 0) 1 (1 2 0) __t2ibk186 t __t4ltC187)) (head (mkstruct st_ins (1 2 0) __9JL71004 t k)) set.slog:98 #f)
  class ReadTask1599 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_unionindex1597;  slog::Index** st_uniondelta1598;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_ins");
      outer_rel = db->getRelation("pleaf");
      std::vector<u16> ord1600({1, 2, 0});
      slog::Relation* readrel1601 = db->getRelation("st_union");
      st_unionindex1597 = readrel1601->getIndex(ord1600, false);
      std::vector<u16> ord1602({1, 2, 0});
      slog::Relation* readrel1603 = db->getRelation("st_union");
      st_uniondelta1598 = readrel1603->getIndex(ord1602, true);
  
    }
    ReadTask1599(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c19 = _t[1];
        slog::join_probe_old<3,1>(st_unionindex1597, st_uniondelta1598, std::array<u64,3>{v_c278, 0, 0}, [&](const std::array<u64,3>& m1604) {
          u64 v_c18 = m1604[1]; u64 v_c279 = m1604[2];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c18, v_c19}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:98", "delta:pleaf", _fires);
  
      if (!_done)
      {
        ReadTask1599* _cont = new ReadTask1599(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1599(db,b), false);
  // (crule (pre (let __tconst9YUA1125 conste3776bfed7f405de8017ecfa) (let __tconst7TTg43 constef2d127de37b942baad06145) (let __tconst35F246 const2c624232cdd221771294dfbb) (let __tconst0QyJ48 constd4735e3a265e16eee03f5971) (let __tconst6ZQr51 const6b86b273ff34fce19d6b804e)) (probe st_ins (2 0 1) 1 __tconst0QyJ48 __t3nMl50 __t7Lp349) (body (join _enum (0 1) 2 __t7Lp349 __tconst9YUA1125) (exists st_ins (2 0 1) 1 __tconst35F246) (exists st_ins_ans (0 1) 1 __t3nMl50) (exists st_ins (2 0 1) 1 __tconst6ZQr51) (join st_ins (1 2 0) 2 __t7Lp349 __tconst7TTg43 __t8j8m45) (join st_ins_ans (0 1) 1 __t8j8m45 __v0) (join st_ins (1 2 0) 2 __v0 __tconst35F246 __t4CDi47) (join st_ins_ans (0 1) 1 __t4CDi47 a) (exists st_union (1 2 0) 1 a) (join st_ins_ans (0 1) 1 __t3nMl50 __v1) (join-old st_ins (1 2 0) 2 (1 2 0) __v1 __tconst6ZQr51 __t7CuH52) (join st_ins_ans (0 1) 1 __t7CuH52 b) (join-old st_union (1 2 0) 2 (1 2 0) a b __t8gtb53) (join st_union_ans (0 1) 1 __t8gtb53 r)) (head (emit canon (0) r)) st_basic.slog:18 #f)
  class ReadTask1621 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** _enumindex1605;  slog::Index** st_insindex1606;  slog::Index** st_ins_ansindex1607;  slog::Index** st_insindex1608;  slog::Index** st_insindex1609;  slog::Index** st_ins_ansindex1610;  slog::Index** st_insindex1611;  slog::Index** st_ins_ansindex1612;  slog::Index** st_unionindex1613;  slog::Index** st_ins_ansindex1614;  slog::Index** st_insindex1615;  slog::Index** st_ins_ansindex1616;  slog::Index** st_unionindex1617;  slog::Index** st_union_ansindex1618;  slog::Index** st_insdelta1619;  slog::Index** st_uniondelta1620;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("canon");
      std::vector<u16> ord1622({0});
      slog::Relation* readrel1623 = db->getRelation("canon");
      head_index[0] = readrel1623->getIndex(ord1622, false);
      std::vector<u16> ord1624({2, 0, 1});
      slog::Relation* readrel1625 = db->getRelation("st_ins");
      driver_index = readrel1625->getIndex(ord1624, true);
      std::vector<u16> ord1626({0, 1});
      slog::Relation* readrel1627 = db->getRelation("_enum");
      _enumindex1605 = readrel1627->getIndex(ord1626, false);
      std::vector<u16> ord1628({2, 0, 1});
      slog::Relation* readrel1629 = db->getRelation("st_ins");
      st_insindex1606 = readrel1629->getIndex(ord1628, false);
      std::vector<u16> ord1630({0, 1});
      slog::Relation* readrel1631 = db->getRelation("st_ins_ans");
      st_ins_ansindex1607 = readrel1631->getIndex(ord1630, false);
      std::vector<u16> ord1632({2, 0, 1});
      slog::Relation* readrel1633 = db->getRelation("st_ins");
      st_insindex1608 = readrel1633->getIndex(ord1632, false);
      std::vector<u16> ord1634({1, 2, 0});
      slog::Relation* readrel1635 = db->getRelation("st_ins");
      st_insindex1609 = readrel1635->getIndex(ord1634, false);
      std::vector<u16> ord1636({0, 1});
      slog::Relation* readrel1637 = db->getRelation("st_ins_ans");
      st_ins_ansindex1610 = readrel1637->getIndex(ord1636, false);
      std::vector<u16> ord1638({1, 2, 0});
      slog::Relation* readrel1639 = db->getRelation("st_ins");
      st_insindex1611 = readrel1639->getIndex(ord1638, false);
      std::vector<u16> ord1640({0, 1});
      slog::Relation* readrel1641 = db->getRelation("st_ins_ans");
      st_ins_ansindex1612 = readrel1641->getIndex(ord1640, false);
      std::vector<u16> ord1642({1, 2, 0});
      slog::Relation* readrel1643 = db->getRelation("st_union");
      st_unionindex1613 = readrel1643->getIndex(ord1642, false);
      std::vector<u16> ord1644({0, 1});
      slog::Relation* readrel1645 = db->getRelation("st_ins_ans");
      st_ins_ansindex1614 = readrel1645->getIndex(ord1644, false);
      std::vector<u16> ord1646({1, 2, 0});
      slog::Relation* readrel1647 = db->getRelation("st_ins");
      st_insindex1615 = readrel1647->getIndex(ord1646, false);
      std::vector<u16> ord1648({1, 2, 0});
      slog::Relation* readrel1649 = db->getRelation("st_ins");
      st_insdelta1619 = readrel1649->getIndex(ord1648, true);
      std::vector<u16> ord1650({0, 1});
      slog::Relation* readrel1651 = db->getRelation("st_ins_ans");
      st_ins_ansindex1616 = readrel1651->getIndex(ord1650, false);
      std::vector<u16> ord1652({1, 2, 0});
      slog::Relation* readrel1653 = db->getRelation("st_union");
      st_unionindex1617 = readrel1653->getIndex(ord1652, false);
      std::vector<u16> ord1654({1, 2, 0});
      slog::Relation* readrel1655 = db->getRelation("st_union");
      st_uniondelta1620 = readrel1655->getIndex(ord1654, true);
      std::vector<u16> ord1656({0, 1});
      slog::Relation* readrel1657 = db->getRelation("st_union_ans");
      st_union_ansindex1618 = readrel1657->getIndex(ord1656, false);
  
    }
    ReadTask1621(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c146 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c147 = v_constef2d127de37b942baad06145;
      u64 v_c148 = v_const2c624232cdd221771294dfbb;
      u64 v_c149 = v_constd4735e3a265e16eee03f5971;
      u64 v_c150 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c149, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1658) {
        u64 v_c154 = m1658[1];
        u64 v_c152 = m1658[2];
        if (buckethash(v_c154) != bucket) return;
        slog::join_probe<2,2>(_enumindex1605, std::array<u64,2>{v_c152, v_c146}, [&](const std::array<u64,2>& m1659) {
          if (!slog::exists_probe<3,1>(st_insindex1606, std::array<u64,3>{v_c148, 0, 0})) return;
          if (!slog::exists_probe<2,1>(st_ins_ansindex1607, std::array<u64,2>{v_c154, 0})) return;
          if (!slog::exists_probe<3,1>(st_insindex1608, std::array<u64,3>{v_c150, 0, 0})) return;
          slog::join_probe<3,2>(st_insindex1609, std::array<u64,3>{v_c152, v_c147, 0}, [&](const std::array<u64,3>& m1660) {
            u64 v_c153 = m1660[2];
            slog::join_probe<2,1>(st_ins_ansindex1610, std::array<u64,2>{v_c153, 0}, [&](const std::array<u64,2>& m1661) {
              u64 v_c11 = m1661[1];
              slog::join_probe<3,2>(st_insindex1611, std::array<u64,3>{v_c11, v_c148, 0}, [&](const std::array<u64,3>& m1662) {
                u64 v_c155 = m1662[2];
                slog::join_probe<2,1>(st_ins_ansindex1612, std::array<u64,2>{v_c155, 0}, [&](const std::array<u64,2>& m1663) {
                  u64 v_c156 = m1663[1];
                  if (!slog::exists_probe<3,1>(st_unionindex1613, std::array<u64,3>{v_c156, 0, 0})) return;
                  slog::join_probe<2,1>(st_ins_ansindex1614, std::array<u64,2>{v_c154, 0}, [&](const std::array<u64,2>& m1664) {
                    u64 v_c12 = m1664[1];
                    slog::join_probe_old<3,2>(st_insindex1615, st_insdelta1619, std::array<u64,3>{v_c12, v_c150, 0}, [&](const std::array<u64,3>& m1665) {
                      u64 v_c158 = m1665[2];
                      slog::join_probe<2,1>(st_ins_ansindex1616, std::array<u64,2>{v_c158, 0}, [&](const std::array<u64,2>& m1666) {
                        u64 v_c157 = m1666[1];
                        slog::join_probe_old<3,2>(st_unionindex1617, st_uniondelta1620, std::array<u64,3>{v_c156, v_c157, 0}, [&](const std::array<u64,3>& m1667) {
                          u64 v_c151 = m1667[2];
                          slog::join_probe<2,1>(st_union_ansindex1618, std::array<u64,2>{v_c151, 0}, [&](const std::array<u64,2>& m1668) {
                            u64 v_c7 = m1668[1];
                            ++_fires;
                            slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c7}, std::array<u16,1>{0});
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
        ReadTask1621* _cont = new ReadTask1621(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1621(db,b), false);
  // (crule (pre) (scan temp4p811353 __t0ttd124 __v0 n q u) (body (join pbranch (1 2 3 4 0) 4 q n u __v0 __t6NgR121)) (head (emit st_union_ans (0 1) __t0ttd124 __t6NgR121)) set.slog:118 #f)
  class ReadTask1670 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex1669;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_union_ans");
      std::vector<u16> ord1671({0, 1});
      slog::Relation* readrel1672 = db->getRelation("st_union_ans");
      head_index[0] = readrel1672->getIndex(ord1671, false);
      outer_rel = db->getRelation("temp4p811353");
      std::vector<u16> ord1673({1, 2, 3, 4, 0});
      slog::Relation* readrel1674 = db->getRelation("pbranch");
      pbranchindex1669 = readrel1674->getIndex(ord1673, false);
  
    }
    ReadTask1670(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c169 = _t[0];
        u64 v_c11 = _t[1];
        u64 v_c36 = _t[2];
        u64 v_c35 = _t[3];
        u64 v_c3 = _t[4];
        slog::join_probe<5,4>(pbranchindex1669, std::array<u64,5>{v_c35, v_c36, v_c3, v_c11, 0}, [&](const std::array<u64,5>& m1675) {
          u64 v_c280 = m1675[4];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c169, v_c280}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:118", "delta:temp4p811353", _fires);
  
      if (!_done)
      {
        ReadTask1670* _cont = new ReadTask1670(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1670(db,b), false);
}

