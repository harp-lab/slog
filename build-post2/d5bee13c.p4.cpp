
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const0122baa3ac55f1b433944eb1;
extern u64 v_const06abaa100ecef791ce028c56;
extern u64 v_const0933fb667296882d8c45abca;
extern u64 v_const3b5b774db59f55c2fdaef73a;
extern u64 v_const3cd26ab9ce3085a816a74a29;
extern u64 v_const3fdba35f04dc8c462986c992;
extern u64 v_const4a44dc15364204a80fe80e90;
extern u64 v_const4b227777d4dd1fc61c6f884f;
extern u64 v_const4e07408562bedb8b60ce05c1;
extern u64 v_const4fc82b26aecb47d2868c4efb;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const624b60c58c9d8bfb6ff1886c;
extern u64 v_const6b51d431df5d7f141cbececc;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const7297d2085ea0adffc396d546;
extern u64 v_const798640599597df7a8daa32b1;
extern u64 v_const7f254967624b26d820569bd6;
extern u64 v_const90fb9068eda6f2d68bb61c33;
extern u64 v_const955cca1ceba45052d85984d3;
extern u64 v_const9cfb09b7c00913be7566a50e;
extern u64 v_constb9e118781cea1f9fa01462e0;
extern u64 v_constcd2a69ce5ca278db1d6da969;
extern u64 v_constd01925b37634a1a9d24159d8;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_constda53dc5001ef1e872bd575bd;
extern u64 v_constdd7bbf31ce5f578b9805e840;
extern u64 v_conste25572d3e5a4cc456a779178;
extern u64 v_conste29c9c180c6279b0b02abd6a;
extern u64 v_conste7f6c011776e8db7cd330b54;
extern u64 v_consteb1e33e8a81b697b75855af6;
extern u64 v_consted725292f5f32d61535958c1;
extern u64 v_constef2d127de37b942baad06145;
extern u64 v_constf5ca38f748a1d6eaf726b8a4;
extern u64 v_constfee494ff4827aeb0635bb714;


void slog_rules_c8e7cc03eec61bc4f(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre) (scan mp_msk __t95lh295 k m) (body (exists $sup5638x42x0x0x0 (1 3 4 0 2 5 6) 2 k m) (join mp_msk_ans (0 1) 1 __t95lh295 p) (join $sup5638x42x0x0x0 (1 3 4 0 2 5 6) 3 k m p __d0 l r v)) (head (emit $sup5638x42x0x0x1 (1 5 0 2 3 4 6 7) __t95lh295 p __d0 k l m r v)) map.slog:43 #f)
  class ReadTask3 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x42x0x0x0index0;  slog::Index** mp_msk_ansindex1;  slog::Index** $sup5638x42x0x0x0index2;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x42x0x0x1");
      std::vector<u16> ord4({1, 5, 0, 2, 3, 4, 6, 7});
      slog::Relation* readrel5 = db->getRelation("$sup5638x42x0x0x1");
      head_index[0] = readrel5->getIndex(ord4, false);
      outer_rel = db->getRelation("mp_msk");
      std::vector<u16> ord6({1, 3, 4, 0, 2, 5, 6});
      slog::Relation* readrel7 = db->getRelation("$sup5638x42x0x0x0");
      $sup5638x42x0x0x0index0 = readrel7->getIndex(ord6, false);
      std::vector<u16> ord8({0, 1});
      slog::Relation* readrel9 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1 = readrel9->getIndex(ord8, false);
      std::vector<u16> ord10({1, 3, 4, 0, 2, 5, 6});
      slog::Relation* readrel11 = db->getRelation("$sup5638x42x0x0x0");
      $sup5638x42x0x0x0index2 = readrel11->getIndex(ord10, false);
  
    }
    ReadTask3(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        if (!slog::exists_probe<7,2>($sup5638x42x0x0x0index0, std::array<u64,7>{v_c1, v_c2, 0, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(mp_msk_ansindex1, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m12) {
          u64 v_c3 = m12[1];
          slog::join_probe<7,3>($sup5638x42x0x0x0index2, std::array<u64,7>{v_c1, v_c2, v_c3, 0, 0, 0, 0}, [&](const std::array<u64,7>& m13) {
            u64 v_c4 = m13[3]; u64 v_c5 = m13[4]; u64 v_c6 = m13[5]; u64 v_c7 = m13[6];
            ++_fires;
            slog::emit<8>(head_rel[0], head_index[0], newbatch[0], std::array<u64,8>{v_c0, v_c3, v_c4, v_c1, v_c5, v_c2, v_c6, v_c7}, std::array<u16,8>{1, 5, 0, 2, 3, 4, 6, 7});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:43", "delta:mp_msk", _fires);
  
      if (!_done)
      {
        ReadTask3* _cont = new ReadTask3(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask3(db,b), false);
  // (crule (pre (let __tconst5vD0184 const4a44dc15364204a80fe80e90) (let __tconst2wxb180 const4fc82b26aecb47d2868c4efb) (let __tconst5BWV176 const6b51d431df5d7f141cbececc) (let __tconst2n7e169 conste25572d3e5a4cc456a779178) (let __tconst1XI2167 const3fdba35f04dc8c462986c992) (let __tconst8wlK160 constda53dc5001ef1e872bd575bd) (let __tconst5TvD157 const06abaa100ecef791ce028c56)) (scan temp6MYu1990 __t89SV181) (body (exists ref (1 0) 1 __tconst5BWV176) (exists primref (1 0) 1 __tconst5TvD157) (exists sym (1 0) 1 __tconst8wlK160) (exists ref (1 0) 1 __tconst5vD0184) (exists sym (1 0) 1 __tconst2n7e169) (exists ref (1 0) 1 __tconst2wxb180) (join ref (1 0) 1 __tconst1XI2167 __t8RaS151) (join ref (1 0) 1 __tconst5BWV176 __t2CIh153) (join primref (1 0) 1 __tconst5TvD157 __t2ZGf158) (join sym (1 0) 1 __tconst8wlK160 __t3Wf9161) (join ref (1 0) 1 __tconst5vD0184 __t1od9165) (join sym (1 0) 1 __tconst2n7e169 __t93en170) (join ref (1 0) 1 __tconst2wxb180 __t1BW9179) (let __t1jRc182 (lpush __t89SV181 __tconst2wxb180)) (let __t39Ee172 (lpush __t89SV181 __t93en170)) (let __t9exo163 (lpush __t89SV181 __t3Wf9161)) (let __t6qCj155 (lpush __t89SV181 __t2CIh153))) (head (emit-temp temp9mV91991 __t1jRc182 __t39Ee172 __t6qCj155 __t9exo163)) kcfa.slog:29 #f)
  class ReadTask27 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex14;  slog::Index** primrefindex15;  slog::Index** symindex16;  slog::Index** refindex17;  slog::Index** symindex18;  slog::Index** refindex19;  slog::Index** refindex20;  slog::Index** refindex21;  slog::Index** primrefindex22;  slog::Index** symindex23;  slog::Index** refindex24;  slog::Index** symindex25;  slog::Index** refindex26;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9mV91991");
      outer_rel = db->getRelation("temp6MYu1990");
      std::vector<u16> ord28({1, 0});
      slog::Relation* readrel29 = db->getRelation("ref");
      refindex14 = readrel29->getIndex(ord28, false);
      std::vector<u16> ord30({1, 0});
      slog::Relation* readrel31 = db->getRelation("primref");
      primrefindex15 = readrel31->getIndex(ord30, false);
      std::vector<u16> ord32({1, 0});
      slog::Relation* readrel33 = db->getRelation("sym");
      symindex16 = readrel33->getIndex(ord32, false);
      std::vector<u16> ord34({1, 0});
      slog::Relation* readrel35 = db->getRelation("ref");
      refindex17 = readrel35->getIndex(ord34, false);
      std::vector<u16> ord36({1, 0});
      slog::Relation* readrel37 = db->getRelation("sym");
      symindex18 = readrel37->getIndex(ord36, false);
      std::vector<u16> ord38({1, 0});
      slog::Relation* readrel39 = db->getRelation("ref");
      refindex19 = readrel39->getIndex(ord38, false);
      std::vector<u16> ord40({1, 0});
      slog::Relation* readrel41 = db->getRelation("ref");
      refindex20 = readrel41->getIndex(ord40, false);
      std::vector<u16> ord42({1, 0});
      slog::Relation* readrel43 = db->getRelation("ref");
      refindex21 = readrel43->getIndex(ord42, false);
      std::vector<u16> ord44({1, 0});
      slog::Relation* readrel45 = db->getRelation("primref");
      primrefindex22 = readrel45->getIndex(ord44, false);
      std::vector<u16> ord46({1, 0});
      slog::Relation* readrel47 = db->getRelation("sym");
      symindex23 = readrel47->getIndex(ord46, false);
      std::vector<u16> ord48({1, 0});
      slog::Relation* readrel49 = db->getRelation("ref");
      refindex24 = readrel49->getIndex(ord48, false);
      std::vector<u16> ord50({1, 0});
      slog::Relation* readrel51 = db->getRelation("sym");
      symindex25 = readrel51->getIndex(ord50, false);
      std::vector<u16> ord52({1, 0});
      slog::Relation* readrel53 = db->getRelation("ref");
      refindex26 = readrel53->getIndex(ord52, false);
  
    }
    ReadTask27(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c8 = v_const4a44dc15364204a80fe80e90;
      u64 v_c9 = v_const4fc82b26aecb47d2868c4efb;
      u64 v_c10 = v_const6b51d431df5d7f141cbececc;
      u64 v_c11 = v_conste25572d3e5a4cc456a779178;
      u64 v_c12 = v_const3fdba35f04dc8c462986c992;
      u64 v_c13 = v_constda53dc5001ef1e872bd575bd;
      u64 v_c14 = v_const06abaa100ecef791ce028c56;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c15 = _t[0];
        if (!slog::exists_probe<2,1>(refindex14, std::array<u64,2>{v_c10, 0})) return;
        if (!slog::exists_probe<2,1>(primrefindex15, std::array<u64,2>{v_c14, 0})) return;
        if (!slog::exists_probe<2,1>(symindex16, std::array<u64,2>{v_c13, 0})) return;
        if (!slog::exists_probe<2,1>(refindex17, std::array<u64,2>{v_c8, 0})) return;
        if (!slog::exists_probe<2,1>(symindex18, std::array<u64,2>{v_c11, 0})) return;
        if (!slog::exists_probe<2,1>(refindex19, std::array<u64,2>{v_c9, 0})) return;
        slog::join_probe<2,1>(refindex20, std::array<u64,2>{v_c12, 0}, [&](const std::array<u64,2>& m54) {
          u64 v_c16 = m54[1];
          slog::join_probe<2,1>(refindex21, std::array<u64,2>{v_c10, 0}, [&](const std::array<u64,2>& m55) {
            u64 v_c17 = m55[1];
            slog::join_probe<2,1>(primrefindex22, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m56) {
              u64 v_c18 = m56[1];
              slog::join_probe<2,1>(symindex23, std::array<u64,2>{v_c13, 0}, [&](const std::array<u64,2>& m57) {
                u64 v_c19 = m57[1];
                slog::join_probe<2,1>(refindex24, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m58) {
                  u64 v_c20 = m58[1];
                  slog::join_probe<2,1>(symindex25, std::array<u64,2>{v_c11, 0}, [&](const std::array<u64,2>& m59) {
                    u64 v_c21 = m59[1];
                    slog::join_probe<2,1>(refindex26, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m60) {
                      u64 v_c22 = m60[1];
                      u64 v_c23 = _prim_lpush(db, v_c15, v_c9);
                      if (v_c23 == slog_error) { slog::emit_pending_error(db, "kcfa.slog:29"); return; }
                      u64 v_c24 = _prim_lpush(db, v_c15, v_c21);
                      if (v_c24 == slog_error) { slog::emit_pending_error(db, "kcfa.slog:29"); return; }
                      u64 v_c25 = _prim_lpush(db, v_c15, v_c19);
                      if (v_c25 == slog_error) { slog::emit_pending_error(db, "kcfa.slog:29"); return; }
                      u64 v_c26 = _prim_lpush(db, v_c15, v_c17);
                      if (v_c26 == slog_error) { slog::emit_pending_error(db, "kcfa.slog:29"); return; }
                      ++_fires;
                      slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c23, v_c24, v_c26, v_c25});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("kcfa.slog:29", "delta:temp6MYu1990", _fires);
  
      if (!_done)
      {
        ReadTask27* _cont = new ReadTask27(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask27(db,b), false);
  // (crule (pre (let __tconst8WAL326 const6b86b273ff34fce19d6b804e)) (scan mp_msk_ans __t2ONI329 p) (body (exists $sup5638x60x0x0x0 (4 2 3 5 0 1) 1 p) (exists mbranch (1 2 3 4 0) 1 p) (join-old mp_msk (0 1 2) 1 (0 1 2) __t2ONI329 k m) (exists mbranch (1 2 3 4 0) 2 p m) (exists mp_has0 (2 0 1) 1 k) (join-old $sup5638x60x0x0x0 (1 3 4 0 2 5) 3 (1 3 4 0 2 5) k m p __t6Aa9325 l r) (exists mp_has0 (0 2 1) 2 __t6Aa9325 k) (exists mp_has0 (1 2 0) 2 l k) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t0WBy324) (join-old mp_has0 (0 2 1) 3 (0 2 1) __t6Aa9325 k __t0WBy324) (join-old mp_has0 (1 2 0) 2 (1 2 0) l k __t81Rn328) (join mp_has0_ans (0 1) 1 __t81Rn328 a) (let __t5v2X327 (band k m)) (cmp lt __t5v2X327 __tconst8WAL326)) (head (emit mp_has0_ans (0 1) __t6Aa9325 a)) map.slog:61 #f)
  class ReadTask78 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x60x0x0x0index61;  slog::Index** mbranchindex62;  slog::Index** mp_mskindex63;  slog::Index** mbranchindex64;  slog::Index** mp_has0index65;  slog::Index** $sup5638x60x0x0x0index66;  slog::Index** mp_has0index67;  slog::Index** mp_has0index68;  slog::Index** mbranchindex69;  slog::Index** mp_has0index70;  slog::Index** mp_has0index71;  slog::Index** mp_has0_ansindex72;  slog::Index** mp_mskdelta73;  slog::Index** $sup5638x60x0x0x0delta74;  slog::Index** mbranchdelta75;  slog::Index** mp_has0delta76;  slog::Index** mp_has0delta77;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_has0_ans");
      std::vector<u16> ord79({0, 1});
      slog::Relation* readrel80 = db->getRelation("mp_has0_ans");
      head_index[0] = readrel80->getIndex(ord79, false);
      outer_rel = db->getRelation("mp_msk_ans");
      std::vector<u16> ord81({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel82 = db->getRelation("$sup5638x60x0x0x0");
      $sup5638x60x0x0x0index61 = readrel82->getIndex(ord81, false);
      std::vector<u16> ord83({1, 2, 3, 4, 0});
      slog::Relation* readrel84 = db->getRelation("mbranch");
      mbranchindex62 = readrel84->getIndex(ord83, false);
      std::vector<u16> ord85({0, 1, 2});
      slog::Relation* readrel86 = db->getRelation("mp_msk");
      mp_mskindex63 = readrel86->getIndex(ord85, false);
      std::vector<u16> ord87({0, 1, 2});
      slog::Relation* readrel88 = db->getRelation("mp_msk");
      mp_mskdelta73 = readrel88->getIndex(ord87, true);
      std::vector<u16> ord89({1, 2, 3, 4, 0});
      slog::Relation* readrel90 = db->getRelation("mbranch");
      mbranchindex64 = readrel90->getIndex(ord89, false);
      std::vector<u16> ord91({2, 0, 1});
      slog::Relation* readrel92 = db->getRelation("mp_has0");
      mp_has0index65 = readrel92->getIndex(ord91, false);
      std::vector<u16> ord93({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel94 = db->getRelation("$sup5638x60x0x0x0");
      $sup5638x60x0x0x0index66 = readrel94->getIndex(ord93, false);
      std::vector<u16> ord95({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel96 = db->getRelation("$sup5638x60x0x0x0");
      $sup5638x60x0x0x0delta74 = readrel96->getIndex(ord95, true);
      std::vector<u16> ord97({0, 2, 1});
      slog::Relation* readrel98 = db->getRelation("mp_has0");
      mp_has0index67 = readrel98->getIndex(ord97, false);
      std::vector<u16> ord99({1, 2, 0});
      slog::Relation* readrel100 = db->getRelation("mp_has0");
      mp_has0index68 = readrel100->getIndex(ord99, false);
      std::vector<u16> ord101({1, 2, 3, 4, 0});
      slog::Relation* readrel102 = db->getRelation("mbranch");
      mbranchindex69 = readrel102->getIndex(ord101, false);
      std::vector<u16> ord103({1, 2, 3, 4, 0});
      slog::Relation* readrel104 = db->getRelation("mbranch");
      mbranchdelta75 = readrel104->getIndex(ord103, true);
      std::vector<u16> ord105({0, 2, 1});
      slog::Relation* readrel106 = db->getRelation("mp_has0");
      mp_has0index70 = readrel106->getIndex(ord105, false);
      std::vector<u16> ord107({0, 2, 1});
      slog::Relation* readrel108 = db->getRelation("mp_has0");
      mp_has0delta76 = readrel108->getIndex(ord107, true);
      std::vector<u16> ord109({1, 2, 0});
      slog::Relation* readrel110 = db->getRelation("mp_has0");
      mp_has0index71 = readrel110->getIndex(ord109, false);
      std::vector<u16> ord111({1, 2, 0});
      slog::Relation* readrel112 = db->getRelation("mp_has0");
      mp_has0delta77 = readrel112->getIndex(ord111, true);
      std::vector<u16> ord113({0, 1});
      slog::Relation* readrel114 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex72 = readrel114->getIndex(ord113, false);
  
    }
    ReadTask78(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c27 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c28 = _t[0];
        u64 v_c3 = _t[1];
        if (!slog::exists_probe<6,1>($sup5638x60x0x0x0index61, std::array<u64,6>{v_c3, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex62, std::array<u64,5>{v_c3, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(mp_mskindex63, mp_mskdelta73, std::array<u64,3>{v_c28, 0, 0}, [&](const std::array<u64,3>& m115) {
          u64 v_c1 = m115[1]; u64 v_c2 = m115[2];
          if (!slog::exists_probe<5,2>(mbranchindex64, std::array<u64,5>{v_c3, v_c2, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_has0index65, std::array<u64,3>{v_c1, 0, 0})) return;
          slog::join_probe_old<6,3>($sup5638x60x0x0x0index66, $sup5638x60x0x0x0delta74, std::array<u64,6>{v_c1, v_c2, v_c3, 0, 0, 0}, [&](const std::array<u64,6>& m116) {
            u64 v_c29 = m116[3]; u64 v_c5 = m116[4]; u64 v_c6 = m116[5];
            if (!slog::exists_probe<3,2>(mp_has0index67, std::array<u64,3>{v_c29, v_c1, 0})) return;
            if (!slog::exists_probe<3,2>(mp_has0index68, std::array<u64,3>{v_c5, v_c1, 0})) return;
            slog::join_probe_old<5,4>(mbranchindex69, mbranchdelta75, std::array<u64,5>{v_c3, v_c2, v_c5, v_c6, 0}, [&](const std::array<u64,5>& m117) {
              u64 v_c30 = m117[4];
              slog::join_probe_old<3,3>(mp_has0index70, mp_has0delta76, std::array<u64,3>{v_c29, v_c1, v_c30}, [&](const std::array<u64,3>& m118) {
                slog::join_probe_old<3,2>(mp_has0index71, mp_has0delta77, std::array<u64,3>{v_c5, v_c1, 0}, [&](const std::array<u64,3>& m119) {
                  u64 v_c31 = m119[2];
                  slog::join_probe<2,1>(mp_has0_ansindex72, std::array<u64,2>{v_c31, 0}, [&](const std::array<u64,2>& m120) {
                    u64 v_c32 = m120[1];
                    u64 v_c33 = _prim_band(db, v_c1, v_c2);
                    if (v_c33 == slog_error) { slog::emit_pending_error(db, "map.slog:61"); return; }
                    u64 v_c34 = _prim_lt(db, v_c33, v_c27);
                    if (v_c34 == slog_error) { slog::emit_pending_error(db, "map.slog:61"); return; }
                    if (!v_c34) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c29, v_c32}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:61", "delta:mp_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask78* _cont = new ReadTask78(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask78(db,b), false);
  // (crule (pre) (scan mp_put __t18bR317 __t7f1J316 k v) (body (join mleaf (0 1 2) 1 __t7f1J316 j w) (neq j k)) (head (emit-temp temp3Msk1947 __t7f1J316 j k v) (mkstruct mleaf (1 2 0) __t7bYO315 k v)) map.slog:39 #f)
  class ReadTask123 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mleafindex122;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3Msk1947");
      head_rel[1] = db->getRelation("mleaf");
      outer_rel = db->getRelation("mp_put");
      std::vector<u16> ord124({0, 1, 2});
      slog::Relation* readrel125 = db->getRelation("mleaf");
      mleafindex122 = readrel125->getIndex(ord124, false);
  
    }
    ReadTask123(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c35 = _t[0];
        u64 v_c36 = _t[1];
        u64 v_c1 = _t[2];
        u64 v_c7 = _t[3];
        slog::join_probe<3,1>(mleafindex122, std::array<u64,3>{v_c36, 0, 0}, [&](const std::array<u64,3>& m126) {
          u64 v_c37 = m126[1]; u64 v_c38 = m126[2];
          if (v_c37 == v_c1) return;
          ++_fires;
          slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c36, v_c37, v_c1, v_c7});
          slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c1, v_c7}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("map.slog:39", "delta:mp_put", _fires);
  
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
  // (crule (pre (let __tconst8hOq309 const6b86b273ff34fce19d6b804e)) (scan mp_del_ans __t1hIi313 __v0) (body (exists mp_bld (3 0 1 2 4) 1 __v0) (join-old mp_del (0 2 1) 1 (0 2 1) __t1hIi313 k l) (exists mbranch (3 0 1 2 4) 1 l) (exists mp_del (2 0 1) 1 k) (exists mp_msk (1 2 0) 1 k) (join-old $sup5638x82x0x0x0 (1 2 0 3 4 5) 2 (1 2 0 3 4 5) k l __t0iNt308 m p r) (exists mp_bld (1 2 3 4 0) 4 p m __v0 r) (exists mp_del (0 2 1) 2 __t0iNt308 k) (exists mp_msk (1 2 0) 2 k m) (exists mp_msk_ans (1 0) 1 p) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t62gM307) (exists mp_del (0 2 1) 3 __t0iNt308 k __t62gM307) (join-old mp_bld (1 2 3 4 0) 4 (1 2 3 4 0) p m __v0 r __t8pI6311) (join-old mp_del (0 2 1) 3 (0 2 1) __t0iNt308 k __t62gM307) (exists mp_bld_ans (0 1) 1 __t8pI6311) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t8vNz312) (join mp_msk_ans (0 1) 2 __t8vNz312 p) (join mp_bld_ans (0 1) 1 __t8pI6311 res) (let __t3mg0310 (band k m)) (cmp lt __t3mg0310 __tconst8hOq309)) (head (emit mp_del_ans (0 1) __t0iNt308 res)) map.slog:83 #f)
  class ReadTask151 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_bldindex127;  slog::Index** mp_delindex128;  slog::Index** mbranchindex129;  slog::Index** mp_delindex130;  slog::Index** mp_mskindex131;  slog::Index** $sup5638x82x0x0x0index132;  slog::Index** mp_bldindex133;  slog::Index** mp_delindex134;  slog::Index** mp_mskindex135;  slog::Index** mp_msk_ansindex136;  slog::Index** mbranchindex137;  slog::Index** mp_delindex138;  slog::Index** mp_bldindex139;  slog::Index** mp_delindex140;  slog::Index** mp_bld_ansindex141;  slog::Index** mp_mskindex142;  slog::Index** mp_msk_ansindex143;  slog::Index** mp_bld_ansindex144;  slog::Index** mp_deldelta145;  slog::Index** $sup5638x82x0x0x0delta146;  slog::Index** mbranchdelta147;  slog::Index** mp_blddelta148;  slog::Index** mp_deldelta149;  slog::Index** mp_mskdelta150;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord152({0, 1});
      slog::Relation* readrel153 = db->getRelation("mp_del_ans");
      head_index[0] = readrel153->getIndex(ord152, false);
      outer_rel = db->getRelation("mp_del_ans");
      std::vector<u16> ord154({3, 0, 1, 2, 4});
      slog::Relation* readrel155 = db->getRelation("mp_bld");
      mp_bldindex127 = readrel155->getIndex(ord154, false);
      std::vector<u16> ord156({0, 2, 1});
      slog::Relation* readrel157 = db->getRelation("mp_del");
      mp_delindex128 = readrel157->getIndex(ord156, false);
      std::vector<u16> ord158({0, 2, 1});
      slog::Relation* readrel159 = db->getRelation("mp_del");
      mp_deldelta145 = readrel159->getIndex(ord158, true);
      std::vector<u16> ord160({3, 0, 1, 2, 4});
      slog::Relation* readrel161 = db->getRelation("mbranch");
      mbranchindex129 = readrel161->getIndex(ord160, false);
      std::vector<u16> ord162({2, 0, 1});
      slog::Relation* readrel163 = db->getRelation("mp_del");
      mp_delindex130 = readrel163->getIndex(ord162, false);
      std::vector<u16> ord164({1, 2, 0});
      slog::Relation* readrel165 = db->getRelation("mp_msk");
      mp_mskindex131 = readrel165->getIndex(ord164, false);
      std::vector<u16> ord166({1, 2, 0, 3, 4, 5});
      slog::Relation* readrel167 = db->getRelation("$sup5638x82x0x0x0");
      $sup5638x82x0x0x0index132 = readrel167->getIndex(ord166, false);
      std::vector<u16> ord168({1, 2, 0, 3, 4, 5});
      slog::Relation* readrel169 = db->getRelation("$sup5638x82x0x0x0");
      $sup5638x82x0x0x0delta146 = readrel169->getIndex(ord168, true);
      std::vector<u16> ord170({1, 2, 3, 4, 0});
      slog::Relation* readrel171 = db->getRelation("mp_bld");
      mp_bldindex133 = readrel171->getIndex(ord170, false);
      std::vector<u16> ord172({0, 2, 1});
      slog::Relation* readrel173 = db->getRelation("mp_del");
      mp_delindex134 = readrel173->getIndex(ord172, false);
      std::vector<u16> ord174({1, 2, 0});
      slog::Relation* readrel175 = db->getRelation("mp_msk");
      mp_mskindex135 = readrel175->getIndex(ord174, false);
      std::vector<u16> ord176({1, 0});
      slog::Relation* readrel177 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex136 = readrel177->getIndex(ord176, false);
      std::vector<u16> ord178({1, 2, 3, 4, 0});
      slog::Relation* readrel179 = db->getRelation("mbranch");
      mbranchindex137 = readrel179->getIndex(ord178, false);
      std::vector<u16> ord180({1, 2, 3, 4, 0});
      slog::Relation* readrel181 = db->getRelation("mbranch");
      mbranchdelta147 = readrel181->getIndex(ord180, true);
      std::vector<u16> ord182({0, 2, 1});
      slog::Relation* readrel183 = db->getRelation("mp_del");
      mp_delindex138 = readrel183->getIndex(ord182, false);
      std::vector<u16> ord184({1, 2, 3, 4, 0});
      slog::Relation* readrel185 = db->getRelation("mp_bld");
      mp_bldindex139 = readrel185->getIndex(ord184, false);
      std::vector<u16> ord186({1, 2, 3, 4, 0});
      slog::Relation* readrel187 = db->getRelation("mp_bld");
      mp_blddelta148 = readrel187->getIndex(ord186, true);
      std::vector<u16> ord188({0, 2, 1});
      slog::Relation* readrel189 = db->getRelation("mp_del");
      mp_delindex140 = readrel189->getIndex(ord188, false);
      std::vector<u16> ord190({0, 2, 1});
      slog::Relation* readrel191 = db->getRelation("mp_del");
      mp_deldelta149 = readrel191->getIndex(ord190, true);
      std::vector<u16> ord192({0, 1});
      slog::Relation* readrel193 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex141 = readrel193->getIndex(ord192, false);
      std::vector<u16> ord194({1, 2, 0});
      slog::Relation* readrel195 = db->getRelation("mp_msk");
      mp_mskindex142 = readrel195->getIndex(ord194, false);
      std::vector<u16> ord196({1, 2, 0});
      slog::Relation* readrel197 = db->getRelation("mp_msk");
      mp_mskdelta150 = readrel197->getIndex(ord196, true);
      std::vector<u16> ord198({0, 1});
      slog::Relation* readrel199 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex143 = readrel199->getIndex(ord198, false);
      std::vector<u16> ord200({0, 1});
      slog::Relation* readrel201 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex144 = readrel201->getIndex(ord200, false);
  
    }
    ReadTask151(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c39 = v_const6b86b273ff34fce19d6b804e;
  
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
        if (!slog::exists_probe<5,1>(mp_bldindex127, std::array<u64,5>{v_c41, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(mp_delindex128, mp_deldelta145, std::array<u64,3>{v_c40, 0, 0}, [&](const std::array<u64,3>& m202) {
          u64 v_c1 = m202[1]; u64 v_c5 = m202[2];
          if (!slog::exists_probe<5,1>(mbranchindex129, std::array<u64,5>{v_c5, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_delindex130, std::array<u64,3>{v_c1, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_mskindex131, std::array<u64,3>{v_c1, 0, 0})) return;
          slog::join_probe_old<6,2>($sup5638x82x0x0x0index132, $sup5638x82x0x0x0delta146, std::array<u64,6>{v_c1, v_c5, 0, 0, 0, 0}, [&](const std::array<u64,6>& m203) {
            u64 v_c42 = m203[2]; u64 v_c2 = m203[3]; u64 v_c3 = m203[4]; u64 v_c6 = m203[5];
            if (!slog::exists_probe<5,4>(mp_bldindex133, std::array<u64,5>{v_c3, v_c2, v_c41, v_c6, 0})) return;
            if (!slog::exists_probe<3,2>(mp_delindex134, std::array<u64,3>{v_c42, v_c1, 0})) return;
            if (!slog::exists_probe<3,2>(mp_mskindex135, std::array<u64,3>{v_c1, v_c2, 0})) return;
            if (!slog::exists_probe<2,1>(mp_msk_ansindex136, std::array<u64,2>{v_c3, 0})) return;
            slog::join_probe_old<5,4>(mbranchindex137, mbranchdelta147, std::array<u64,5>{v_c3, v_c2, v_c5, v_c6, 0}, [&](const std::array<u64,5>& m204) {
              u64 v_c43 = m204[4];
              if (!slog::exists_probe<3,3>(mp_delindex138, std::array<u64,3>{v_c42, v_c1, v_c43})) return;
              slog::join_probe_old<5,4>(mp_bldindex139, mp_blddelta148, std::array<u64,5>{v_c3, v_c2, v_c41, v_c6, 0}, [&](const std::array<u64,5>& m205) {
                u64 v_c44 = m205[4];
                slog::join_probe_old<3,3>(mp_delindex140, mp_deldelta149, std::array<u64,3>{v_c42, v_c1, v_c43}, [&](const std::array<u64,3>& m206) {
                  if (!slog::exists_probe<2,1>(mp_bld_ansindex141, std::array<u64,2>{v_c44, 0})) return;
                  slog::join_probe_old<3,2>(mp_mskindex142, mp_mskdelta150, std::array<u64,3>{v_c1, v_c2, 0}, [&](const std::array<u64,3>& m207) {
                    u64 v_c45 = m207[2];
                    slog::join_probe<2,2>(mp_msk_ansindex143, std::array<u64,2>{v_c45, v_c3}, [&](const std::array<u64,2>& m208) {
                      slog::join_probe<2,1>(mp_bld_ansindex144, std::array<u64,2>{v_c44, 0}, [&](const std::array<u64,2>& m209) {
                        u64 v_c46 = m209[1];
                        u64 v_c47 = _prim_band(db, v_c1, v_c2);
                        if (v_c47 == slog_error) { slog::emit_pending_error(db, "map.slog:83"); return; }
                        u64 v_c48 = _prim_lt(db, v_c47, v_c39);
                        if (v_c48 == slog_error) { slog::emit_pending_error(db, "map.slog:83"); return; }
                        if (!v_c48) return;
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c42, v_c46}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("map.slog:83", "delta:mp_del_ans", _fires);
  
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
  // (crule (pre (let __tconst8wKO1349 constb9e118781cea1f9fa01462e0)) (scan select_branch __t6mHg429 __t3WHU428 e2 e3) (body (join _enum (1 0) 1 __tconst8wKO1349 __t1Q0o427) (join boolval (0 1) 2 __t3WHU428 __t1Q0o427)) (head (emit select_branch_ans (0 1) __t6mHg429 e3)) interp.slog:85 #f)
  class ReadTask213 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex211;  slog::Index** boolvalindex212;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("select_branch_ans");
      std::vector<u16> ord214({0, 1});
      slog::Relation* readrel215 = db->getRelation("select_branch_ans");
      head_index[0] = readrel215->getIndex(ord214, false);
      outer_rel = db->getRelation("select_branch");
      std::vector<u16> ord216({1, 0});
      slog::Relation* readrel217 = db->getRelation("_enum");
      _enumindex211 = readrel217->getIndex(ord216, false);
      std::vector<u16> ord218({0, 1});
      slog::Relation* readrel219 = db->getRelation("boolval");
      boolvalindex212 = readrel219->getIndex(ord218, false);
  
    }
    ReadTask213(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c49 = v_constb9e118781cea1f9fa01462e0;
  
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
        u64 v_c52 = _t[2];
        u64 v_c53 = _t[3];
        slog::join_probe<2,1>(_enumindex211, std::array<u64,2>{v_c49, 0}, [&](const std::array<u64,2>& m220) {
          u64 v_c54 = m220[1];
          slog::join_probe<2,2>(boolvalindex212, std::array<u64,2>{v_c51, v_c54}, [&](const std::array<u64,2>& m221) {
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c50, v_c53}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:85", "delta:select_branch", _fires);
  
      if (!_done)
      {
        ReadTask213* _cont = new ReadTask213(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask213(db,b), false);
  // (crule (pre (let __trid25em1405 const9cfb09b7c00913be7566a50e) (let __trel2b0C1406 const7f254967624b26d820569bd6) (let __tcol3P9B1407 const5feceb66ffc86f38d952786c) (let __trel7gk61408 const7f254967624b26d820569bd6) (let __tcol6pJq1409 const6b86b273ff34fce19d6b804e)) (scan $sup5638x93x0x0x0 __d0 l m p r u v) (body) (head (tycheck l (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid25em1405 __trel2b0C1406 __tcol3P9B1407 (1 2 3 4 0)) (tycheck u (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid25em1405 __trel7gk61408 __tcol6pJq1409 (1 2 3 4 0)) (mkstruct mp_union (1 2 0) __4Xaw1404 l u)) map.slog:94 #f)
  class ReadTask225 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid223;  u32 sid222;  u32 sid224;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("mp_union");
      outer_rel = db->getRelation("$sup5638x93x0x0x0");
      sid223 = db->getRelation("_enum")->getStructId();
      sid222 = db->getRelation("mbranch")->getStructId();
      sid224 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask225(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c55 = v_const9cfb09b7c00913be7566a50e;
      u64 v_c56 = v_const7f254967624b26d820569bd6;
      u64 v_c57 = v_const5feceb66ffc86f38d952786c;
      u64 v_c58 = v_const7f254967624b26d820569bd6;
      u64 v_c59 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c4 = _t[0];
        u64 v_c5 = _t[1];
        u64 v_c2 = _t[2];
        u64 v_c3 = _t[3];
        u64 v_c6 = _t[4];
        u64 v_c60 = _t[5];
        u64 v_c7 = _t[6];
        ++_fires;
        if (!((is_struct(v_c5) && (decode_struct_id(v_c5) == sid222 || decode_struct_id(v_c5) == sid223 || decode_struct_id(v_c5) == sid224))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c55, v_c56, v_c57, v_c5}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c60) && (decode_struct_id(v_c60) == sid222 || decode_struct_id(v_c60) == sid223 || decode_struct_id(v_c60) == sid224))))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c55, v_c58, v_c59, v_c60}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c5, v_c60}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:94", "delta:$sup5638x93x0x0x0", _fires);
  
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
  // (crule (pre) (scan mp_msk_ans __t99il580 q) (body (exists $sup5638x107x0x0x0 (5 3 7 8 0 1 2 4 6) 1 q) (join-old mp_msk (0 1 2) 1 (0 1 2) __t99il580 p n) (join $sup5638x107x0x0x0 (3 4 5 0 1 2 6 7 8) 3 n p q __d0 l m r u v)) (head (emit $sup5638x107x0x0x1 (0 9 1 2 3 4 5 6 7 8) __d0 v __t99il580 l m n p q r u)) map.slog:108 #f)
  class ReadTask230 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x107x0x0x0index226;  slog::Index** mp_mskindex227;  slog::Index** $sup5638x107x0x0x0index228;  slog::Index** mp_mskdelta229;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x107x0x0x1");
      std::vector<u16> ord231({0, 9, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel232 = db->getRelation("$sup5638x107x0x0x1");
      head_index[0] = readrel232->getIndex(ord231, false);
      outer_rel = db->getRelation("mp_msk_ans");
      std::vector<u16> ord233({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel234 = db->getRelation("$sup5638x107x0x0x0");
      $sup5638x107x0x0x0index226 = readrel234->getIndex(ord233, false);
      std::vector<u16> ord235({0, 1, 2});
      slog::Relation* readrel236 = db->getRelation("mp_msk");
      mp_mskindex227 = readrel236->getIndex(ord235, false);
      std::vector<u16> ord237({0, 1, 2});
      slog::Relation* readrel238 = db->getRelation("mp_msk");
      mp_mskdelta229 = readrel238->getIndex(ord237, true);
      std::vector<u16> ord239({3, 4, 5, 0, 1, 2, 6, 7, 8});
      slog::Relation* readrel240 = db->getRelation("$sup5638x107x0x0x0");
      $sup5638x107x0x0x0index228 = readrel240->getIndex(ord239, false);
  
    }
    ReadTask230(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c62 = _t[1];
        if (!slog::exists_probe<9,1>($sup5638x107x0x0x0index226, std::array<u64,9>{v_c62, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(mp_mskindex227, mp_mskdelta229, std::array<u64,3>{v_c61, 0, 0}, [&](const std::array<u64,3>& m241) {
          u64 v_c3 = m241[1]; u64 v_c63 = m241[2];
          slog::join_probe<9,3>($sup5638x107x0x0x0index228, std::array<u64,9>{v_c63, v_c3, v_c62, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m242) {
            u64 v_c4 = m242[3]; u64 v_c5 = m242[4]; u64 v_c2 = m242[5]; u64 v_c6 = m242[6]; u64 v_c60 = m242[7]; u64 v_c7 = m242[8];
            ++_fires;
            slog::emit<10>(head_rel[0], head_index[0], newbatch[0], std::array<u64,10>{v_c4, v_c7, v_c61, v_c5, v_c2, v_c63, v_c3, v_c62, v_c6, v_c60}, std::array<u16,10>{0, 9, 1, 2, 3, 4, 5, 6, 7, 8});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:108", "delta:mp_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask230* _cont = new ReadTask230(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask230(db,b), false);
  // (crule (pre (let __tconst2Vg0546 const06abaa100ecef791ce028c56) (let _00024sqc2T6l964 constd4735e3a265e16eee03f5971) (let _00024sqc2Wzv965 const5feceb66ffc86f38d952786c) (let _00024sqc80On966 const6b86b273ff34fce19d6b804e) (let _00024sqo5uVM967 const5feceb66ffc86f38d952786c) (let _00024sqo11r2968 const6b86b273ff34fce19d6b804e) (let _00024sqo89F1969 const6b86b273ff34fce19d6b804e) (let _00024sqo57Hb970 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo11r2968 __t40a6549 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo5uVM967 __t40a6549 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo89F1969 __t40a6549 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo57Hb970 __t40a6549 _00024seq2) (join delta (1 2 0) 2 __tconst2Vg0546 _00024seq2 __t6qCW547) (join closure (0 1 2) 1 __t40a6549 lm rc) (join any_bool (0) 0 b) (letp _00024sql3t08962 (aslst _00024seq2)) (let chk9VOX1847 (llen _00024sql3t08962)) (eq _00024sqc2T6l964 chk9VOX1847) (letp chk7cNe1848 (lref _00024sql3t08962 _00024sqc2Wzv965)) (eq __t40a6549 chk7cNe1848) (letp chk1qW01849 (lref _00024sql3t08962 _00024sqc80On966)) (eq __t40a6549 chk1qW01849)) (head (emit-temp temp7z5q1838 __t6qCW547 b) (mkstruct boolval (1 0) __t1Eis545 b)) interp.slog:126 #f)
  class ReadTask251 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex243;  slog::Index** $seq_atrindex244;  slog::Index** $seq_atrindex245;  slog::Index** deltaindex246;  slog::Index** closureindex247;  slog::Index** any_boolindex248;  slog::Index** $seq_atrdelta249;  slog::Index** $seq_atrdelta250;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7z5q1838");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord252({1, 0, 2});
      slog::Relation* readrel253 = db->getRelation("$seq_at");
      driver_index = readrel253->getIndex(ord252, true);
      std::vector<u16> ord254({1, 0, 2});
      slog::Relation* readrel255 = db->getRelation("$seq_at");
      $seq_atindex243 = readrel255->getIndex(ord254, false);
      std::vector<u16> ord256({1, 0, 2});
      slog::Relation* readrel257 = db->getRelation("$seq_atr");
      $seq_atrindex244 = readrel257->getIndex(ord256, false);
      std::vector<u16> ord258({1, 0, 2});
      slog::Relation* readrel259 = db->getRelation("$seq_atr");
      $seq_atrdelta249 = readrel259->getIndex(ord258, true);
      std::vector<u16> ord260({1, 0, 2});
      slog::Relation* readrel261 = db->getRelation("$seq_atr");
      $seq_atrindex245 = readrel261->getIndex(ord260, false);
      std::vector<u16> ord262({1, 0, 2});
      slog::Relation* readrel263 = db->getRelation("$seq_atr");
      $seq_atrdelta250 = readrel263->getIndex(ord262, true);
      std::vector<u16> ord264({1, 2, 0});
      slog::Relation* readrel265 = db->getRelation("delta");
      deltaindex246 = readrel265->getIndex(ord264, false);
      std::vector<u16> ord266({0, 1, 2});
      slog::Relation* readrel267 = db->getRelation("closure");
      closureindex247 = readrel267->getIndex(ord266, false);
      std::vector<u16> ord268({0});
      slog::Relation* readrel269 = db->getRelation("any_bool");
      any_boolindex248 = readrel269->getIndex(ord268, false);
  
    }
    ReadTask251(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c64 = v_const06abaa100ecef791ce028c56;
      u64 v_c65 = v_constd4735e3a265e16eee03f5971;
      u64 v_c66 = v_const5feceb66ffc86f38d952786c;
      u64 v_c67 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c68 = v_const5feceb66ffc86f38d952786c;
      u64 v_c69 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c70 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c71 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c69, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m270) {
        u64 v_c72 = m270[1];
        u64 v_c73 = m270[2];
        if (buckethash(v_c72) != bucket) return;
        slog::join_probe<3,3>($seq_atindex243, std::array<u64,3>{v_c68, v_c72, v_c73}, [&](const std::array<u64,3>& m271) {
          slog::join_probe_old<3,3>($seq_atrindex244, $seq_atrdelta249, std::array<u64,3>{v_c70, v_c72, v_c73}, [&](const std::array<u64,3>& m272) {
            slog::join_probe_old<3,3>($seq_atrindex245, $seq_atrdelta250, std::array<u64,3>{v_c71, v_c72, v_c73}, [&](const std::array<u64,3>& m273) {
              slog::join_probe<3,2>(deltaindex246, std::array<u64,3>{v_c64, v_c73, 0}, [&](const std::array<u64,3>& m274) {
                u64 v_c74 = m274[2];
                slog::join_probe<3,1>(closureindex247, std::array<u64,3>{v_c72, 0, 0}, [&](const std::array<u64,3>& m275) {
                  u64 v_c75 = m275[1]; u64 v_c76 = m275[2];
                  slog::join_all<1>(any_boolindex248, [&](const std::array<u64,1>& m276) {
                    u64 v_c77 = m276[0];
                    bool ok277 = true;
                    u64 v_c78 = _prim_aslst(db, v_c73, &ok277);
                    if (!ok277) return;
                    u64 v_c79 = _prim_llen(db, v_c78);
                    if (v_c79 == slog_error) { slog::emit_pending_error(db, "interp.slog:126"); return; }
                    if (v_c65 != v_c79) return;
                    bool ok278 = true;
                    u64 v_c80 = _prim_lref(db, v_c78, v_c66, &ok278);
                    if (!ok278) return;
                    if (v_c72 != v_c80) return;
                    bool ok279 = true;
                    u64 v_c81 = _prim_lref(db, v_c78, v_c67, &ok279);
                    if (!ok279) return;
                    if (v_c72 != v_c81) return;
                    ++_fires;
                    slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c74, v_c77});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c77}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:126", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask251* _cont = new ReadTask251(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask251(db,b), false);
  // (crule (pre (let __tconst7FS91443 constcd2a69ce5ca278db1d6da969)) (scan eval __t7Kqt248 __t1Nbh247 rho t) (body (join _enum (1 0) 1 __tconst7FS91443 __t49OJ246) (join num (0 1) 1 __t1Nbh247 n)) (head (emit eval_ans (0 1) __t7Kqt248 __t49OJ246)) interp.slog:30 #f)
  class ReadTask282 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex280;  slog::Index** numindex281;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord283({0, 1});
      slog::Relation* readrel284 = db->getRelation("eval_ans");
      head_index[0] = readrel284->getIndex(ord283, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord285({1, 0});
      slog::Relation* readrel286 = db->getRelation("_enum");
      _enumindex280 = readrel286->getIndex(ord285, false);
      std::vector<u16> ord287({0, 1});
      slog::Relation* readrel288 = db->getRelation("num");
      numindex281 = readrel288->getIndex(ord287, false);
  
    }
    ReadTask282(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c82 = v_constcd2a69ce5ca278db1d6da969;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c83 = _t[0];
        u64 v_c84 = _t[1];
        u64 v_c85 = _t[2];
        u64 v_c86 = _t[3];
        slog::join_probe<2,1>(_enumindex280, std::array<u64,2>{v_c82, 0}, [&](const std::array<u64,2>& m289) {
          u64 v_c87 = m289[1];
          slog::join_probe<2,1>(numindex281, std::array<u64,2>{v_c84, 0}, [&](const std::array<u64,2>& m290) {
            u64 v_c63 = m290[1];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c83, v_c87}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:30", "delta:eval", _fires);
  
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
  // (crule (pre) (scan temp89ti1945 __t5ttu125 k) (body) (head (mkstruct lst_take (1 2 0) __65RG1332 __t5ttu125 k)) context.slog:11 #f)
  class ReadTask291 : public slog::Task
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
      head_rel[0] = db->getRelation("lst_take");
      outer_rel = db->getRelation("temp89ti1945");
  
    }
    ReadTask291(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c88 = _t[0];
        u64 v_c1 = _t[1];
        ++_fires;
        slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c88, v_c1}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("context.slog:11", "delta:temp89ti1945", _fires);
  
      if (!_done)
      {
        ReadTask291* _cont = new ReadTask291(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask291(db,b), false);
  // (crule (pre (let __tconst2mJz511 constf5ca38f748a1d6eaf726b8a4)) (scan temp32cQ2010 __t0cTh509 __t2zNy470 __t6hPZ506) (body (join lambda (1 2 0) 2 __t0cTh509 __t6hPZ506 __t6gSw510)) (head (emit-temp temp9iKU2011 __t2zNy470 __t6gSw510) (mkstruct letrec (1 2 3 0) __t9LO7512 __tconst2mJz511 __t6gSw510 __t2zNy470)) kcfa.slog:40 #f)
  class ReadTask293 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lambdaindex292;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9iKU2011");
      head_rel[1] = db->getRelation("letrec");
      outer_rel = db->getRelation("temp32cQ2010");
      std::vector<u16> ord294({1, 2, 0});
      slog::Relation* readrel295 = db->getRelation("lambda");
      lambdaindex292 = readrel295->getIndex(ord294, false);
  
    }
    ReadTask293(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c89 = v_constf5ca38f748a1d6eaf726b8a4;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c90 = _t[0];
        u64 v_c91 = _t[1];
        u64 v_c92 = _t[2];
        slog::join_probe<3,2>(lambdaindex292, std::array<u64,3>{v_c90, v_c92, 0}, [&](const std::array<u64,3>& m296) {
          u64 v_c93 = m296[2];
          ++_fires;
          slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c91, v_c93});
          slog::emit_struct<4>(head_rel[1], newbatch[1], std::array<u64,3>{v_c89, v_c93, v_c91}, std::array<u16,4>{1, 2, 3, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("kcfa.slog:40", "delta:temp32cQ2010", _fires);
  
      if (!_done)
      {
        ReadTask293* _cont = new ReadTask293(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask293(db,b), false);
  // (crule (pre) (scan temp3nE61896 __t3e5V215) (body) (head (mkstruct mp_hsb (1 0) __2tuC1229 __t3e5V215)) map.slog:19 #f)
  class ReadTask297 : public slog::Task
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
      outer_rel = db->getRelation("temp3nE61896");
  
    }
    ReadTask297(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c94 = _t[0];
        ++_fires;
        slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c94}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:19", "delta:temp3nE61896", _fires);
  
      if (!_done)
      {
        ReadTask297* _cont = new ReadTask297(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask297(db,b), false);
  // (crule (pre) (scan tick_ans __t8A6X268 t2) (body (join-old tick (0 2 1) 1 (0 2 1) __t8A6X268 t __t4H6p267) (exists $sup70016x51x0x0x0 (4 0 3 1 2) 1 t) (exists eval (3 1 0 2) 1 t) (exists eval_args (3 2 0 1) 1 t) (join-old app (0 1 2) 1 (0 1 2) __t4H6p267 ef es) (exists eval (3 1 0 2) 2 t ef) (exists eval_args (1 3 2 0) 2 es t) (join $sup70016x51x0x0x0 (1 2 4 0 3) 3 ef es t __d0 rho) (exists eval_args (1 3 2 0) 3 es t rho) (join-old eval (1 2 3 0) 3 (1 2 3 0) ef rho t __t1jZw263) (exists eval_ans (0 1) 1 __t1jZw263) (join-old eval_args (1 3 2 0) 3 (1 3 2 0) es t rho __t2ycT266) (exists eval_args_ans (0 1) 1 __t2ycT266) (join eval_ans (0 1) 1 __t1jZw263 __t5Yru265) (join eval_args_ans (0 1) 1 __t2ycT266 vs) (join-old closure (0 1 2) 1 (0 1 2) __t5Yru265 __t3Nsh264 rhoc) (join-old lambda (0 1 2) 1 (0 1 2) __t3Nsh264 xs eb)) (head (emit $sup70016x51x0x0x1 (1 8 0 2 3 4 5 6 7 9 10 11 12) __t1jZw263 rhoc __d0 __t2ycT266 __t8A6X268 eb ef es rho t t2 vs xs)) interp.slog:52 #f)
  class ReadTask321 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** tickindex298;  slog::Index** $sup70016x51x0x0x0index299;  slog::Index** evalindex300;  slog::Index** eval_argsindex301;  slog::Index** appindex302;  slog::Index** evalindex303;  slog::Index** eval_argsindex304;  slog::Index** $sup70016x51x0x0x0index305;  slog::Index** eval_argsindex306;  slog::Index** evalindex307;  slog::Index** eval_ansindex308;  slog::Index** eval_argsindex309;  slog::Index** eval_args_ansindex310;  slog::Index** eval_ansindex311;  slog::Index** eval_args_ansindex312;  slog::Index** closureindex313;  slog::Index** lambdaindex314;  slog::Index** tickdelta315;  slog::Index** appdelta316;  slog::Index** evaldelta317;  slog::Index** eval_argsdelta318;  slog::Index** closuredelta319;  slog::Index** lambdadelta320;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup70016x51x0x0x1");
      std::vector<u16> ord322({1, 8, 0, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12});
      slog::Relation* readrel323 = db->getRelation("$sup70016x51x0x0x1");
      head_index[0] = readrel323->getIndex(ord322, false);
      outer_rel = db->getRelation("tick_ans");
      std::vector<u16> ord324({0, 2, 1});
      slog::Relation* readrel325 = db->getRelation("tick");
      tickindex298 = readrel325->getIndex(ord324, false);
      std::vector<u16> ord326({0, 2, 1});
      slog::Relation* readrel327 = db->getRelation("tick");
      tickdelta315 = readrel327->getIndex(ord326, true);
      std::vector<u16> ord328({4, 0, 3, 1, 2});
      slog::Relation* readrel329 = db->getRelation("$sup70016x51x0x0x0");
      $sup70016x51x0x0x0index299 = readrel329->getIndex(ord328, false);
      std::vector<u16> ord330({3, 1, 0, 2});
      slog::Relation* readrel331 = db->getRelation("eval");
      evalindex300 = readrel331->getIndex(ord330, false);
      std::vector<u16> ord332({3, 2, 0, 1});
      slog::Relation* readrel333 = db->getRelation("eval_args");
      eval_argsindex301 = readrel333->getIndex(ord332, false);
      std::vector<u16> ord334({0, 1, 2});
      slog::Relation* readrel335 = db->getRelation("app");
      appindex302 = readrel335->getIndex(ord334, false);
      std::vector<u16> ord336({0, 1, 2});
      slog::Relation* readrel337 = db->getRelation("app");
      appdelta316 = readrel337->getIndex(ord336, true);
      std::vector<u16> ord338({3, 1, 0, 2});
      slog::Relation* readrel339 = db->getRelation("eval");
      evalindex303 = readrel339->getIndex(ord338, false);
      std::vector<u16> ord340({1, 3, 2, 0});
      slog::Relation* readrel341 = db->getRelation("eval_args");
      eval_argsindex304 = readrel341->getIndex(ord340, false);
      std::vector<u16> ord342({1, 2, 4, 0, 3});
      slog::Relation* readrel343 = db->getRelation("$sup70016x51x0x0x0");
      $sup70016x51x0x0x0index305 = readrel343->getIndex(ord342, false);
      std::vector<u16> ord344({1, 3, 2, 0});
      slog::Relation* readrel345 = db->getRelation("eval_args");
      eval_argsindex306 = readrel345->getIndex(ord344, false);
      std::vector<u16> ord346({1, 2, 3, 0});
      slog::Relation* readrel347 = db->getRelation("eval");
      evalindex307 = readrel347->getIndex(ord346, false);
      std::vector<u16> ord348({1, 2, 3, 0});
      slog::Relation* readrel349 = db->getRelation("eval");
      evaldelta317 = readrel349->getIndex(ord348, true);
      std::vector<u16> ord350({0, 1});
      slog::Relation* readrel351 = db->getRelation("eval_ans");
      eval_ansindex308 = readrel351->getIndex(ord350, false);
      std::vector<u16> ord352({1, 3, 2, 0});
      slog::Relation* readrel353 = db->getRelation("eval_args");
      eval_argsindex309 = readrel353->getIndex(ord352, false);
      std::vector<u16> ord354({1, 3, 2, 0});
      slog::Relation* readrel355 = db->getRelation("eval_args");
      eval_argsdelta318 = readrel355->getIndex(ord354, true);
      std::vector<u16> ord356({0, 1});
      slog::Relation* readrel357 = db->getRelation("eval_args_ans");
      eval_args_ansindex310 = readrel357->getIndex(ord356, false);
      std::vector<u16> ord358({0, 1});
      slog::Relation* readrel359 = db->getRelation("eval_ans");
      eval_ansindex311 = readrel359->getIndex(ord358, false);
      std::vector<u16> ord360({0, 1});
      slog::Relation* readrel361 = db->getRelation("eval_args_ans");
      eval_args_ansindex312 = readrel361->getIndex(ord360, false);
      std::vector<u16> ord362({0, 1, 2});
      slog::Relation* readrel363 = db->getRelation("closure");
      closureindex313 = readrel363->getIndex(ord362, false);
      std::vector<u16> ord364({0, 1, 2});
      slog::Relation* readrel365 = db->getRelation("closure");
      closuredelta319 = readrel365->getIndex(ord364, true);
      std::vector<u16> ord366({0, 1, 2});
      slog::Relation* readrel367 = db->getRelation("lambda");
      lambdaindex314 = readrel367->getIndex(ord366, false);
      std::vector<u16> ord368({0, 1, 2});
      slog::Relation* readrel369 = db->getRelation("lambda");
      lambdadelta320 = readrel369->getIndex(ord368, true);
  
    }
    ReadTask321(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c95 = _t[0];
        u64 v_c96 = _t[1];
        slog::join_probe_old<3,1>(tickindex298, tickdelta315, std::array<u64,3>{v_c95, 0, 0}, [&](const std::array<u64,3>& m370) {
          u64 v_c86 = m370[1]; u64 v_c97 = m370[2];
          if (!slog::exists_probe<5,1>($sup70016x51x0x0x0index299, std::array<u64,5>{v_c86, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<4,1>(evalindex300, std::array<u64,4>{v_c86, 0, 0, 0})) return;
          if (!slog::exists_probe<4,1>(eval_argsindex301, std::array<u64,4>{v_c86, 0, 0, 0})) return;
          slog::join_probe_old<3,1>(appindex302, appdelta316, std::array<u64,3>{v_c97, 0, 0}, [&](const std::array<u64,3>& m371) {
            u64 v_c98 = m371[1]; u64 v_c99 = m371[2];
            if (!slog::exists_probe<4,2>(evalindex303, std::array<u64,4>{v_c86, v_c98, 0, 0})) return;
            if (!slog::exists_probe<4,2>(eval_argsindex304, std::array<u64,4>{v_c99, v_c86, 0, 0})) return;
            slog::join_probe<5,3>($sup70016x51x0x0x0index305, std::array<u64,5>{v_c98, v_c99, v_c86, 0, 0}, [&](const std::array<u64,5>& m372) {
              u64 v_c4 = m372[3]; u64 v_c85 = m372[4];
              if (!slog::exists_probe<4,3>(eval_argsindex306, std::array<u64,4>{v_c99, v_c86, v_c85, 0})) return;
              slog::join_probe_old<4,3>(evalindex307, evaldelta317, std::array<u64,4>{v_c98, v_c85, v_c86, 0}, [&](const std::array<u64,4>& m373) {
                u64 v_c100 = m373[3];
                if (!slog::exists_probe<2,1>(eval_ansindex308, std::array<u64,2>{v_c100, 0})) return;
                slog::join_probe_old<4,3>(eval_argsindex309, eval_argsdelta318, std::array<u64,4>{v_c99, v_c86, v_c85, 0}, [&](const std::array<u64,4>& m374) {
                  u64 v_c101 = m374[3];
                  if (!slog::exists_probe<2,1>(eval_args_ansindex310, std::array<u64,2>{v_c101, 0})) return;
                  slog::join_probe<2,1>(eval_ansindex311, std::array<u64,2>{v_c100, 0}, [&](const std::array<u64,2>& m375) {
                    u64 v_c102 = m375[1];
                    slog::join_probe<2,1>(eval_args_ansindex312, std::array<u64,2>{v_c101, 0}, [&](const std::array<u64,2>& m376) {
                      u64 v_c103 = m376[1];
                      slog::join_probe_old<3,1>(closureindex313, closuredelta319, std::array<u64,3>{v_c102, 0, 0}, [&](const std::array<u64,3>& m377) {
                        u64 v_c104 = m377[1]; u64 v_c105 = m377[2];
                        slog::join_probe_old<3,1>(lambdaindex314, lambdadelta320, std::array<u64,3>{v_c104, 0, 0}, [&](const std::array<u64,3>& m378) {
                          u64 v_c106 = m378[1]; u64 v_c107 = m378[2];
                          ++_fires;
                          slog::emit<13>(head_rel[0], head_index[0], newbatch[0], std::array<u64,13>{v_c100, v_c105, v_c4, v_c101, v_c95, v_c107, v_c98, v_c99, v_c85, v_c86, v_c96, v_c103, v_c106}, std::array<u16,13>{1, 8, 0, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12});
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
  
      if (_fires) db->bumpFires("interp.slog:52", "delta:tick_ans", _fires);
  
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
  // (crule (pre (let _00024sqc8FiT940 const5feceb66ffc86f38d952786c)) (scan extend_env __t2JLh258 rho _00024seq0 t) (body (letp _00024sql0rkO938 (aslst _00024seq0)) (let chk6mpK1908 (llen _00024sql0rkO938)) (eq _00024sqc8FiT940 chk6mpK1908)) (head (emit extend_env_ans (0 1) __t2JLh258 rho)) interp.slog:47 #f)
  class ReadTask379 : public slog::Task
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
      head_rel[0] = db->getRelation("extend_env_ans");
      std::vector<u16> ord380({0, 1});
      slog::Relation* readrel381 = db->getRelation("extend_env_ans");
      head_index[0] = readrel381->getIndex(ord380, false);
      outer_rel = db->getRelation("extend_env");
  
    }
    ReadTask379(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c108 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c109 = _t[0];
        u64 v_c85 = _t[1];
        u64 v_c110 = _t[2];
        u64 v_c86 = _t[3];
        bool ok382 = true;
        u64 v_c111 = _prim_aslst(db, v_c110, &ok382);
        if (!ok382) return;
        u64 v_c112 = _prim_llen(db, v_c111);
        if (v_c112 == slog_error) { slog::emit_pending_error(db, "interp.slog:47"); return; }
        if (v_c108 != v_c112) return;
        ++_fires;
        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c109, v_c85}, std::array<u16,2>{0, 1});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:47", "delta:extend_env", _fires);
  
      if (!_done)
      {
        ReadTask379* _cont = new ReadTask379(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask379(db,b), false);
  // (crule (pre) (scan mpz_overflow __erre9y4j1768 __errf5sNn1769 __errf2LbF1770 __errf3lq71771 __errf9DpL1772) (body) (head (emit error (0) __erre9y4j1768)) <internal>:1 #f)
  class ReadTask383 : public slog::Task
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
      std::vector<u16> ord384({0});
      slog::Relation* readrel385 = db->getRelation("error");
      head_index[0] = readrel385->getIndex(ord384, false);
      outer_rel = db->getRelation("mpz_overflow");
  
    }
    ReadTask383(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c113 = _t[0];
        u64 v_c114 = _t[1];
        u64 v_c115 = _t[2];
        u64 v_c116 = _t[3];
        u64 v_c117 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c113}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_overflow", _fires);
  
      if (!_done)
      {
        ReadTask383* _cont = new ReadTask383(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask383(db,b), false);
  // (crule (pre (let __tconst85Gw1131 constb9e118781cea1f9fa01462e0) (let __tconst3nKQ305 const06abaa100ecef791ce028c56) (let _00024sqc19MG1022 constd4735e3a265e16eee03f5971) (let _00024sqc5y4j1023 const5feceb66ffc86f38d952786c) (let _00024sqc09of1024 const6b86b273ff34fce19d6b804e) (let _00024sqo41XW1025 const5feceb66ffc86f38d952786c) (let _00024sqo2TL91026 const6b86b273ff34fce19d6b804e) (let _00024sqo4lhI1027 const6b86b273ff34fce19d6b804e) (let _00024sqo7qxI1028 const5feceb66ffc86f38d952786c)) (probe $seq_atr (1 0 2) 1 _00024sqo4lhI1027 v1 _00024seq0) (body (join $seq_at (1 0 2) 3 _00024sqo41XW1025 v1 _00024seq0) (letp _00024sql8r1X1020 (aslst _00024seq0)) (letp v2 (lref _00024sql8r1X1020 _00024sqc09of1024)) (neq v1 v2) (join $seq_at (1 0 2) 3 _00024sqo2TL91026 v2 _00024seq0) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo7qxI1028 v2 _00024seq0) (exists _enum (1 0) 1 __tconst85Gw1131) (join delta (1 2 0) 2 __tconst3nKQ305 _00024seq0 __t44yZ306) (join _enum (1 0) 1 __tconst85Gw1131 __t4QRG303) (let chk9OfU2058 (llen _00024sql8r1X1020)) (eq _00024sqc19MG1022 chk9OfU2058) (letp chk0Dt92059 (lref _00024sql8r1X1020 _00024sqc5y4j1023)) (eq v1 chk0Dt92059)) (head (emit-temp temp2zCq2052 __t44yZ306) (mkstruct boolval (1 0) __t6gLd304 __t4QRG303)) interp.slog:124 #f)
  class ReadTask393 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex386;  slog::Index** $seq_atindex387;  slog::Index** $seq_atrindex388;  slog::Index** _enumindex389;  slog::Index** deltaindex390;  slog::Index** _enumindex391;  slog::Index** $seq_atrdelta392;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2zCq2052");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord394({1, 0, 2});
      slog::Relation* readrel395 = db->getRelation("$seq_atr");
      driver_index = readrel395->getIndex(ord394, true);
      std::vector<u16> ord396({1, 0, 2});
      slog::Relation* readrel397 = db->getRelation("$seq_at");
      $seq_atindex386 = readrel397->getIndex(ord396, false);
      std::vector<u16> ord398({1, 0, 2});
      slog::Relation* readrel399 = db->getRelation("$seq_at");
      $seq_atindex387 = readrel399->getIndex(ord398, false);
      std::vector<u16> ord400({1, 0, 2});
      slog::Relation* readrel401 = db->getRelation("$seq_atr");
      $seq_atrindex388 = readrel401->getIndex(ord400, false);
      std::vector<u16> ord402({1, 0, 2});
      slog::Relation* readrel403 = db->getRelation("$seq_atr");
      $seq_atrdelta392 = readrel403->getIndex(ord402, true);
      std::vector<u16> ord404({1, 0});
      slog::Relation* readrel405 = db->getRelation("_enum");
      _enumindex389 = readrel405->getIndex(ord404, false);
      std::vector<u16> ord406({1, 2, 0});
      slog::Relation* readrel407 = db->getRelation("delta");
      deltaindex390 = readrel407->getIndex(ord406, false);
      std::vector<u16> ord408({1, 0});
      slog::Relation* readrel409 = db->getRelation("_enum");
      _enumindex391 = readrel409->getIndex(ord408, false);
  
    }
    ReadTask393(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c118 = v_constb9e118781cea1f9fa01462e0;
      u64 v_c119 = v_const06abaa100ecef791ce028c56;
      u64 v_c120 = v_constd4735e3a265e16eee03f5971;
      u64 v_c121 = v_const5feceb66ffc86f38d952786c;
      u64 v_c122 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c123 = v_const5feceb66ffc86f38d952786c;
      u64 v_c124 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c125 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c126 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c125, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m410) {
        u64 v_c127 = m410[1];
        u64 v_c110 = m410[2];
        if (buckethash(v_c127) != bucket) return;
        slog::join_probe<3,3>($seq_atindex386, std::array<u64,3>{v_c123, v_c127, v_c110}, [&](const std::array<u64,3>& m411) {
          bool ok412 = true;
          u64 v_c128 = _prim_aslst(db, v_c110, &ok412);
          if (!ok412) return;
          bool ok413 = true;
          u64 v_c129 = _prim_lref(db, v_c128, v_c122, &ok413);
          if (!ok413) return;
          if (v_c127 == v_c129) return;
          slog::join_probe<3,3>($seq_atindex387, std::array<u64,3>{v_c124, v_c129, v_c110}, [&](const std::array<u64,3>& m414) {
            slog::join_probe_old<3,3>($seq_atrindex388, $seq_atrdelta392, std::array<u64,3>{v_c126, v_c129, v_c110}, [&](const std::array<u64,3>& m415) {
              if (!slog::exists_probe<2,1>(_enumindex389, std::array<u64,2>{v_c118, 0})) return;
              slog::join_probe<3,2>(deltaindex390, std::array<u64,3>{v_c119, v_c110, 0}, [&](const std::array<u64,3>& m416) {
                u64 v_c130 = m416[2];
                slog::join_probe<2,1>(_enumindex391, std::array<u64,2>{v_c118, 0}, [&](const std::array<u64,2>& m417) {
                  u64 v_c131 = m417[1];
                  u64 v_c132 = _prim_llen(db, v_c128);
                  if (v_c132 == slog_error) { slog::emit_pending_error(db, "interp.slog:124"); return; }
                  if (v_c120 != v_c132) return;
                  bool ok418 = true;
                  u64 v_c133 = _prim_lref(db, v_c128, v_c121, &ok418);
                  if (!ok418) return;
                  if (v_c127 != v_c133) return;
                  ++_fires;
                  slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c130});
                  slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c131}, std::array<u16,2>{1, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:124", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask393* _cont = new ReadTask393(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask393(db,b), false);
  // (crule (pre) (scan temp5qo21875 __t3rqG10 k v) (body (join mleaf (1 2 0) 2 k v __t1xsL8)) (head (emit mp_put_ans (0 1) __t3rqG10 __t1xsL8)) map.slog:37 #f)
  class ReadTask420 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mleafindex419;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_ans");
      std::vector<u16> ord421({0, 1});
      slog::Relation* readrel422 = db->getRelation("mp_put_ans");
      head_index[0] = readrel422->getIndex(ord421, false);
      outer_rel = db->getRelation("temp5qo21875");
      std::vector<u16> ord423({1, 2, 0});
      slog::Relation* readrel424 = db->getRelation("mleaf");
      mleafindex419 = readrel424->getIndex(ord423, false);
  
    }
    ReadTask420(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c134 = _t[0];
        u64 v_c1 = _t[1];
        u64 v_c7 = _t[2];
        slog::join_probe<3,2>(mleafindex419, std::array<u64,3>{v_c1, v_c7, 0}, [&](const std::array<u64,3>& m425) {
          u64 v_c135 = m425[2];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c134, v_c135}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:37", "delta:temp5qo21875", _fires);
  
      if (!_done)
      {
        ReadTask420* _cont = new ReadTask420(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask420(db,b), false);
  // (crule (pre (let __tconst9Msd523 const6b86b273ff34fce19d6b804e)) (scan mbranch __t8ZnZ521 p m l r) (body (join-old mp_union (1 2 0) 1 (1 2 0) __t8ZnZ521 __t333H520 __t0OqE522) (join mbranch (0 1 2 3 4) 1 __t333H520 q n u v) (cmp lt m n) (let __t9LcB524 (band p n)) (cmp lt __t9LcB524 __tconst9Msd523)) (head (emit $sup5638x104x0x0x0 (0 7 1 2 3 4 5 6 8) __t0OqE522 u l m n p q r v)) map.slog:105 #f)
  class ReadTask429 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex426;  slog::Index** mbranchindex427;  slog::Index** mp_uniondelta428;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x104x0x0x0");
      std::vector<u16> ord430({0, 7, 1, 2, 3, 4, 5, 6, 8});
      slog::Relation* readrel431 = db->getRelation("$sup5638x104x0x0x0");
      head_index[0] = readrel431->getIndex(ord430, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord432({1, 2, 0});
      slog::Relation* readrel433 = db->getRelation("mp_union");
      mp_unionindex426 = readrel433->getIndex(ord432, false);
      std::vector<u16> ord434({1, 2, 0});
      slog::Relation* readrel435 = db->getRelation("mp_union");
      mp_uniondelta428 = readrel435->getIndex(ord434, true);
      std::vector<u16> ord436({0, 1, 2, 3, 4});
      slog::Relation* readrel437 = db->getRelation("mbranch");
      mbranchindex427 = readrel437->getIndex(ord436, false);
  
    }
    ReadTask429(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c136 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c137 = _t[0];
        u64 v_c3 = _t[1];
        u64 v_c2 = _t[2];
        u64 v_c5 = _t[3];
        u64 v_c6 = _t[4];
        slog::join_probe_old<3,1>(mp_unionindex426, mp_uniondelta428, std::array<u64,3>{v_c137, 0, 0}, [&](const std::array<u64,3>& m438) {
          u64 v_c138 = m438[1]; u64 v_c139 = m438[2];
          slog::join_probe<5,1>(mbranchindex427, std::array<u64,5>{v_c138, 0, 0, 0, 0}, [&](const std::array<u64,5>& m439) {
            u64 v_c62 = m439[1]; u64 v_c63 = m439[2]; u64 v_c60 = m439[3]; u64 v_c7 = m439[4];
            u64 v_c140 = _prim_lt(db, v_c2, v_c63);
            if (v_c140 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
            if (!v_c140) return;
            u64 v_c141 = _prim_band(db, v_c3, v_c63);
            if (v_c141 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
            u64 v_c142 = _prim_lt(db, v_c141, v_c136);
            if (v_c142 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
            if (!v_c142) return;
            ++_fires;
            slog::emit<9>(head_rel[0], head_index[0], newbatch[0], std::array<u64,9>{v_c139, v_c60, v_c5, v_c2, v_c63, v_c3, v_c62, v_c6, v_c7}, std::array<u16,9>{0, 7, 1, 2, 3, 4, 5, 6, 8});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:105", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask429* _cont = new ReadTask429(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask429(db,b), false);
  // (crule (pre (let __trid1Y0W1052 constfee494ff4827aeb0635bb714) (let __trel2sU51053 const3cd26ab9ce3085a816a74a29) (let __tcol5SQY1054 const5feceb66ffc86f38d952786c) (let __trel3j6c1055 const3cd26ab9ce3085a816a74a29) (let __tcol7MIh1056 const6b86b273ff34fce19d6b804e)) (scan $sup5638x84x0x0x0 __d0 k l m p r) (body) (head (tycheck r (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid1Y0W1052 __trel2sU51053 __tcol5SQY1054 (1 2 3 4 0)) (tycheck k (accept int) __trid1Y0W1052 __trel3j6c1055 __tcol7MIh1056 (1 2 3 4 0)) (mkstruct mp_del (1 2 0) __63RD1051 r k)) map.slog:85 #f)
  class ReadTask445 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid443;  u32 sid442;  u32 sid444;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("mp_del");
      outer_rel = db->getRelation("$sup5638x84x0x0x0");
      sid443 = db->getRelation("_enum")->getStructId();
      sid442 = db->getRelation("mbranch")->getStructId();
      sid444 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask445(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c143 = v_constfee494ff4827aeb0635bb714;
      u64 v_c144 = v_const3cd26ab9ce3085a816a74a29;
      u64 v_c145 = v_const5feceb66ffc86f38d952786c;
      u64 v_c146 = v_const3cd26ab9ce3085a816a74a29;
      u64 v_c147 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c4 = _t[0];
        u64 v_c1 = _t[1];
        u64 v_c5 = _t[2];
        u64 v_c2 = _t[3];
        u64 v_c3 = _t[4];
        u64 v_c6 = _t[5];
        ++_fires;
        if (!((is_struct(v_c6) && (decode_struct_id(v_c6) == sid442 || decode_struct_id(v_c6) == sid443 || decode_struct_id(v_c6) == sid444))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c143, v_c144, v_c145, v_c6}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c1)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c143, v_c146, v_c147, v_c1}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c6, v_c1}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:85", "delta:$sup5638x84x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask445* _cont = new ReadTask445(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask445(db,b), false);
  // (crule (pre (let __tconst2mJz511 constf5ca38f748a1d6eaf726b8a4) (let __tconst3zaK478 const0933fb667296882d8c45abca) (let __tconst6GsZ491 consted725292f5f32d61535958c1) (let __tconst0Ob1494 const6b86b273ff34fce19d6b804e) (let __tconst8C9X496 const5feceb66ffc86f38d952786c) (let __tconst91JR503 const90fb9068eda6f2d68bb61c33)) (scan temp7cao2002 __t0cTh509 __t3yjA501 __t4qrC508 __t8A1z467) (body (exists num (1 0) 1 __tconst8C9X496) (exists primref (1 0) 1 __tconst6GsZ491) (exists primref (1 0) 1 __tconst3zaK478) (exists num (1 0) 1 __tconst0Ob1494) (exists ref (1 0) 1 __tconst2mJz511) (join primref (1 0) 1 __tconst91JR503 __t8Gth504) (join num (1 0) 1 __tconst8C9X496 __t8p4J497) (join primref (1 0) 1 __tconst6GsZ491 __t3x0f492) (join primref (1 0) 1 __tconst3zaK478 __t2abh479) (join num (1 0) 1 __tconst0Ob1494 __t1oVV472) (join ref (1 0) 1 __tconst2mJz511 __t1y5d469) (let __t7hSc477 (lpush __t3yjA501 __t1oVV472)) (let __t18Fx502 (lpush __t3yjA501 __t8p4J497))) (head (emit-temp temp29qZ2003 __t0cTh509 __t18Fx502 __t3yjA501 __t4qrC508 __t7hSc477 __t8A1z467) (mkstruct app (1 2 0) __t2zNy470 __t1y5d469 __t8A1z467)) kcfa.slog:40 #f)
  class ReadTask457 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** numindex446;  slog::Index** primrefindex447;  slog::Index** primrefindex448;  slog::Index** numindex449;  slog::Index** refindex450;  slog::Index** primrefindex451;  slog::Index** numindex452;  slog::Index** primrefindex453;  slog::Index** primrefindex454;  slog::Index** numindex455;  slog::Index** refindex456;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp29qZ2003");
      head_rel[1] = db->getRelation("app");
      outer_rel = db->getRelation("temp7cao2002");
      std::vector<u16> ord458({1, 0});
      slog::Relation* readrel459 = db->getRelation("num");
      numindex446 = readrel459->getIndex(ord458, false);
      std::vector<u16> ord460({1, 0});
      slog::Relation* readrel461 = db->getRelation("primref");
      primrefindex447 = readrel461->getIndex(ord460, false);
      std::vector<u16> ord462({1, 0});
      slog::Relation* readrel463 = db->getRelation("primref");
      primrefindex448 = readrel463->getIndex(ord462, false);
      std::vector<u16> ord464({1, 0});
      slog::Relation* readrel465 = db->getRelation("num");
      numindex449 = readrel465->getIndex(ord464, false);
      std::vector<u16> ord466({1, 0});
      slog::Relation* readrel467 = db->getRelation("ref");
      refindex450 = readrel467->getIndex(ord466, false);
      std::vector<u16> ord468({1, 0});
      slog::Relation* readrel469 = db->getRelation("primref");
      primrefindex451 = readrel469->getIndex(ord468, false);
      std::vector<u16> ord470({1, 0});
      slog::Relation* readrel471 = db->getRelation("num");
      numindex452 = readrel471->getIndex(ord470, false);
      std::vector<u16> ord472({1, 0});
      slog::Relation* readrel473 = db->getRelation("primref");
      primrefindex453 = readrel473->getIndex(ord472, false);
      std::vector<u16> ord474({1, 0});
      slog::Relation* readrel475 = db->getRelation("primref");
      primrefindex454 = readrel475->getIndex(ord474, false);
      std::vector<u16> ord476({1, 0});
      slog::Relation* readrel477 = db->getRelation("num");
      numindex455 = readrel477->getIndex(ord476, false);
      std::vector<u16> ord478({1, 0});
      slog::Relation* readrel479 = db->getRelation("ref");
      refindex456 = readrel479->getIndex(ord478, false);
  
    }
    ReadTask457(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c89 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c148 = v_const0933fb667296882d8c45abca;
      u64 v_c149 = v_consted725292f5f32d61535958c1;
      u64 v_c150 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c151 = v_const5feceb66ffc86f38d952786c;
      u64 v_c152 = v_const90fb9068eda6f2d68bb61c33;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c90 = _t[0];
        u64 v_c153 = _t[1];
        u64 v_c154 = _t[2];
        u64 v_c155 = _t[3];
        if (!slog::exists_probe<2,1>(numindex446, std::array<u64,2>{v_c151, 0})) return;
        if (!slog::exists_probe<2,1>(primrefindex447, std::array<u64,2>{v_c149, 0})) return;
        if (!slog::exists_probe<2,1>(primrefindex448, std::array<u64,2>{v_c148, 0})) return;
        if (!slog::exists_probe<2,1>(numindex449, std::array<u64,2>{v_c150, 0})) return;
        if (!slog::exists_probe<2,1>(refindex450, std::array<u64,2>{v_c89, 0})) return;
        slog::join_probe<2,1>(primrefindex451, std::array<u64,2>{v_c152, 0}, [&](const std::array<u64,2>& m480) {
          u64 v_c156 = m480[1];
          slog::join_probe<2,1>(numindex452, std::array<u64,2>{v_c151, 0}, [&](const std::array<u64,2>& m481) {
            u64 v_c157 = m481[1];
            slog::join_probe<2,1>(primrefindex453, std::array<u64,2>{v_c149, 0}, [&](const std::array<u64,2>& m482) {
              u64 v_c158 = m482[1];
              slog::join_probe<2,1>(primrefindex454, std::array<u64,2>{v_c148, 0}, [&](const std::array<u64,2>& m483) {
                u64 v_c159 = m483[1];
                slog::join_probe<2,1>(numindex455, std::array<u64,2>{v_c150, 0}, [&](const std::array<u64,2>& m484) {
                  u64 v_c160 = m484[1];
                  slog::join_probe<2,1>(refindex456, std::array<u64,2>{v_c89, 0}, [&](const std::array<u64,2>& m485) {
                    u64 v_c161 = m485[1];
                    u64 v_c162 = _prim_lpush(db, v_c153, v_c160);
                    if (v_c162 == slog_error) { slog::emit_pending_error(db, "kcfa.slog:40"); return; }
                    u64 v_c163 = _prim_lpush(db, v_c153, v_c157);
                    if (v_c163 == slog_error) { slog::emit_pending_error(db, "kcfa.slog:40"); return; }
                    ++_fires;
                    slog::emit_temp<6>(head_rel[0], newbatch[0], std::array<u64,6>{v_c90, v_c163, v_c153, v_c154, v_c162, v_c155});
                    slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c161, v_c155}, std::array<u16,3>{1, 2, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("kcfa.slog:40", "delta:temp7cao2002", _fires);
  
      if (!_done)
      {
        ReadTask457* _cont = new ReadTask457(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask457(db,b), false);
  // (crule (pre (let __tconst4UBH116 const6b86b273ff34fce19d6b804e)) (scan mp_union_ans __t7k4o120 __v0) (body (join-old mp_union (0 1 2) 1 (0 1 2) __t7k4o120 l __t8CES119) (exists mbranch (3 0 1 2 4) 1 l) (exists $sup5638x95x0x0x0 (1 2 4 6 0 3 5 7 8) 1 l) (exists $sup5638x95x0x0x1 (2 3 5 7 0 4 6 8 9 1) 1 l) (join-old mp_union (2 0 1) 1 (2 0 1) __t8CES119 __t2hbE115 __t5EdF114) (exists $sup5638x95x0x0x0 (0 1 2 3 4 5 6 7 8) 2 __t2hbE115 l) (exists $sup5638x95x0x0x1 (0 2 1 3 4 5 6 7 8 9) 2 __t2hbE115 l) (join-old mbranch (3 0 1 2 4) 2 (3 0 1 2 4) l __t5EdF114 p m r) (exists $sup5638x95x0x0x1 (2 3 5 7 0 4 6 8 9 1) 5 l m p r __t2hbE115) (exists mp_msk (2 0 1) 1 m) (exists mp_msk_ans (1 0) 1 p) (join-old $sup5638x95x0x0x0 (1 2 4 6 0 3 5 7 8) 5 (1 2 4 6 0 3 5 7 8) l m p r __t2hbE115 n q u v) (cmp lt n m) (exists mbranch (1 2 3 4 0) 5 q n u v __t8CES119) (exists mp_msk (1 2 0) 2 q m) (join-old $sup5638x95x0x0x1 (2 3 5 7 0 4 6 8 9 1) 9 (2 3 5 7 0 4 6 8 9 1) l m p r __t2hbE115 n q u v __t27ag118) (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) q n u v __t8CES119) (join-old mp_msk (1 2 0) 3 (1 2 0) q m __t27ag118) (join mp_msk_ans (0 1) 2 __t27ag118 p) (let __t1JZU117 (band q m)) (cmp lt __t1JZU117 __tconst4UBH116)) (head (emit-temp temp3MZb2062 __t2hbE115 __v0 m p r) (mkstruct mbranch (1 2 3 4 0) __t9UHh112 p m __v0 r)) map.slog:96 #f)
  class ReadTask511 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex486;  slog::Index** mbranchindex487;  slog::Index** $sup5638x95x0x0x0index488;  slog::Index** $sup5638x95x0x0x1index489;  slog::Index** mp_unionindex490;  slog::Index** $sup5638x95x0x0x0index491;  slog::Index** $sup5638x95x0x0x1index492;  slog::Index** mbranchindex493;  slog::Index** $sup5638x95x0x0x1index494;  slog::Index** mp_mskindex495;  slog::Index** mp_msk_ansindex496;  slog::Index** $sup5638x95x0x0x0index497;  slog::Index** mbranchindex498;  slog::Index** mp_mskindex499;  slog::Index** $sup5638x95x0x0x1index500;  slog::Index** mbranchindex501;  slog::Index** mp_mskindex502;  slog::Index** mp_msk_ansindex503;  slog::Index** mp_uniondelta504;  slog::Index** mp_uniondelta505;  slog::Index** mbranchdelta506;  slog::Index** $sup5638x95x0x0x0delta507;  slog::Index** $sup5638x95x0x0x1delta508;  slog::Index** mbranchdelta509;  slog::Index** mp_mskdelta510;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3MZb2062");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_union_ans");
      std::vector<u16> ord512({0, 1, 2});
      slog::Relation* readrel513 = db->getRelation("mp_union");
      mp_unionindex486 = readrel513->getIndex(ord512, false);
      std::vector<u16> ord514({0, 1, 2});
      slog::Relation* readrel515 = db->getRelation("mp_union");
      mp_uniondelta504 = readrel515->getIndex(ord514, true);
      std::vector<u16> ord516({3, 0, 1, 2, 4});
      slog::Relation* readrel517 = db->getRelation("mbranch");
      mbranchindex487 = readrel517->getIndex(ord516, false);
      std::vector<u16> ord518({1, 2, 4, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel519 = db->getRelation("$sup5638x95x0x0x0");
      $sup5638x95x0x0x0index488 = readrel519->getIndex(ord518, false);
      std::vector<u16> ord520({2, 3, 5, 7, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel521 = db->getRelation("$sup5638x95x0x0x1");
      $sup5638x95x0x0x1index489 = readrel521->getIndex(ord520, false);
      std::vector<u16> ord522({2, 0, 1});
      slog::Relation* readrel523 = db->getRelation("mp_union");
      mp_unionindex490 = readrel523->getIndex(ord522, false);
      std::vector<u16> ord524({2, 0, 1});
      slog::Relation* readrel525 = db->getRelation("mp_union");
      mp_uniondelta505 = readrel525->getIndex(ord524, true);
      std::vector<u16> ord526({0, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel527 = db->getRelation("$sup5638x95x0x0x0");
      $sup5638x95x0x0x0index491 = readrel527->getIndex(ord526, false);
      std::vector<u16> ord528({0, 2, 1, 3, 4, 5, 6, 7, 8, 9});
      slog::Relation* readrel529 = db->getRelation("$sup5638x95x0x0x1");
      $sup5638x95x0x0x1index492 = readrel529->getIndex(ord528, false);
      std::vector<u16> ord530({3, 0, 1, 2, 4});
      slog::Relation* readrel531 = db->getRelation("mbranch");
      mbranchindex493 = readrel531->getIndex(ord530, false);
      std::vector<u16> ord532({3, 0, 1, 2, 4});
      slog::Relation* readrel533 = db->getRelation("mbranch");
      mbranchdelta506 = readrel533->getIndex(ord532, true);
      std::vector<u16> ord534({2, 3, 5, 7, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel535 = db->getRelation("$sup5638x95x0x0x1");
      $sup5638x95x0x0x1index494 = readrel535->getIndex(ord534, false);
      std::vector<u16> ord536({2, 0, 1});
      slog::Relation* readrel537 = db->getRelation("mp_msk");
      mp_mskindex495 = readrel537->getIndex(ord536, false);
      std::vector<u16> ord538({1, 0});
      slog::Relation* readrel539 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex496 = readrel539->getIndex(ord538, false);
      std::vector<u16> ord540({1, 2, 4, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel541 = db->getRelation("$sup5638x95x0x0x0");
      $sup5638x95x0x0x0index497 = readrel541->getIndex(ord540, false);
      std::vector<u16> ord542({1, 2, 4, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel543 = db->getRelation("$sup5638x95x0x0x0");
      $sup5638x95x0x0x0delta507 = readrel543->getIndex(ord542, true);
      std::vector<u16> ord544({1, 2, 3, 4, 0});
      slog::Relation* readrel545 = db->getRelation("mbranch");
      mbranchindex498 = readrel545->getIndex(ord544, false);
      std::vector<u16> ord546({1, 2, 0});
      slog::Relation* readrel547 = db->getRelation("mp_msk");
      mp_mskindex499 = readrel547->getIndex(ord546, false);
      std::vector<u16> ord548({2, 3, 5, 7, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel549 = db->getRelation("$sup5638x95x0x0x1");
      $sup5638x95x0x0x1index500 = readrel549->getIndex(ord548, false);
      std::vector<u16> ord550({2, 3, 5, 7, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel551 = db->getRelation("$sup5638x95x0x0x1");
      $sup5638x95x0x0x1delta508 = readrel551->getIndex(ord550, true);
      std::vector<u16> ord552({1, 2, 3, 4, 0});
      slog::Relation* readrel553 = db->getRelation("mbranch");
      mbranchindex501 = readrel553->getIndex(ord552, false);
      std::vector<u16> ord554({1, 2, 3, 4, 0});
      slog::Relation* readrel555 = db->getRelation("mbranch");
      mbranchdelta509 = readrel555->getIndex(ord554, true);
      std::vector<u16> ord556({1, 2, 0});
      slog::Relation* readrel557 = db->getRelation("mp_msk");
      mp_mskindex502 = readrel557->getIndex(ord556, false);
      std::vector<u16> ord558({1, 2, 0});
      slog::Relation* readrel559 = db->getRelation("mp_msk");
      mp_mskdelta510 = readrel559->getIndex(ord558, true);
      std::vector<u16> ord560({0, 1});
      slog::Relation* readrel561 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex503 = readrel561->getIndex(ord560, false);
  
    }
    ReadTask511(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c164 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c165 = _t[0];
        u64 v_c41 = _t[1];
        slog::join_probe_old<3,1>(mp_unionindex486, mp_uniondelta504, std::array<u64,3>{v_c165, 0, 0}, [&](const std::array<u64,3>& m562) {
          u64 v_c5 = m562[1]; u64 v_c166 = m562[2];
          if (!slog::exists_probe<5,1>(mbranchindex487, std::array<u64,5>{v_c5, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<9,1>($sup5638x95x0x0x0index488, std::array<u64,9>{v_c5, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<10,1>($sup5638x95x0x0x1index489, std::array<u64,10>{v_c5, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          slog::join_probe_old<3,1>(mp_unionindex490, mp_uniondelta505, std::array<u64,3>{v_c166, 0, 0}, [&](const std::array<u64,3>& m563) {
            u64 v_c167 = m563[1]; u64 v_c168 = m563[2];
            if (!slog::exists_probe<9,2>($sup5638x95x0x0x0index491, std::array<u64,9>{v_c167, v_c5, 0, 0, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<10,2>($sup5638x95x0x0x1index492, std::array<u64,10>{v_c167, v_c5, 0, 0, 0, 0, 0, 0, 0, 0})) return;
            slog::join_probe_old<5,2>(mbranchindex493, mbranchdelta506, std::array<u64,5>{v_c5, v_c168, 0, 0, 0}, [&](const std::array<u64,5>& m564) {
              u64 v_c3 = m564[2]; u64 v_c2 = m564[3]; u64 v_c6 = m564[4];
              if (!slog::exists_probe<10,5>($sup5638x95x0x0x1index494, std::array<u64,10>{v_c5, v_c2, v_c3, v_c6, v_c167, 0, 0, 0, 0, 0})) return;
              if (!slog::exists_probe<3,1>(mp_mskindex495, std::array<u64,3>{v_c2, 0, 0})) return;
              if (!slog::exists_probe<2,1>(mp_msk_ansindex496, std::array<u64,2>{v_c3, 0})) return;
              slog::join_probe_old<9,5>($sup5638x95x0x0x0index497, $sup5638x95x0x0x0delta507, std::array<u64,9>{v_c5, v_c2, v_c3, v_c6, v_c167, 0, 0, 0, 0}, [&](const std::array<u64,9>& m565) {
                u64 v_c63 = m565[5]; u64 v_c62 = m565[6]; u64 v_c60 = m565[7]; u64 v_c7 = m565[8];
                u64 v_c169 = _prim_lt(db, v_c63, v_c2);
                if (v_c169 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
                if (!v_c169) return;
                if (!slog::exists_probe<5,5>(mbranchindex498, std::array<u64,5>{v_c62, v_c63, v_c60, v_c7, v_c166})) return;
                if (!slog::exists_probe<3,2>(mp_mskindex499, std::array<u64,3>{v_c62, v_c2, 0})) return;
                slog::join_probe_old<10,9>($sup5638x95x0x0x1index500, $sup5638x95x0x0x1delta508, std::array<u64,10>{v_c5, v_c2, v_c3, v_c6, v_c167, v_c63, v_c62, v_c60, v_c7, 0}, [&](const std::array<u64,10>& m567) {
                  u64 v_c170 = m567[9];
                  slog::join_probe_old<5,5>(mbranchindex501, mbranchdelta509, std::array<u64,5>{v_c62, v_c63, v_c60, v_c7, v_c166}, [&](const std::array<u64,5>& m568) {
                    slog::join_probe_old<3,3>(mp_mskindex502, mp_mskdelta510, std::array<u64,3>{v_c62, v_c2, v_c170}, [&](const std::array<u64,3>& m569) {
                      slog::join_probe<2,2>(mp_msk_ansindex503, std::array<u64,2>{v_c170, v_c3}, [&](const std::array<u64,2>& m570) {
                        u64 v_c171 = _prim_band(db, v_c62, v_c2);
                        if (v_c171 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
                        u64 v_c172 = _prim_lt(db, v_c171, v_c164);
                        if (v_c172 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
                        if (!v_c172) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c167, v_c41, v_c2, v_c3, v_c6});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c3, v_c2, v_c41, v_c6}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:96", "delta:mp_union_ans", _fires);
  
      if (!_done)
      {
        ReadTask511* _cont = new ReadTask511(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask511(db,b), false);
  // (crule (pre) (scan mbranch __t6oBk833 p m l r) (body (exists mp_put (1 2 3 0) 1 __t6oBk833) (exists mp_join (3 4 1 0 2) 2 p __t6oBk833) (exists mp_msk (2 0 1) 1 m) (join $sup5638x44x0x0x0 (2 3 4 5 6 0 1 7) 5 l m p r __t6oBk833 __t6Fc5832 k v) (join mp_put (0 2 1 3) 4 __t6Fc5832 k __t6oBk833 v) (exists mleaf (1 2 0) 2 k v) (exists mp_msk (1 2 0) 2 k m) (join-old mp_join (3 4 1 0 2) 3 (3 4 1 0 2) p __t6oBk833 k __t6jFY835 __t5lKq834) (join-old mleaf (0 1 2) 3 (0 1 2) __t5lKq834 k v) (exists mp_join_ans (0 1) 1 __t6jFY835) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t2nZc836) (join mp_msk_ans (0 1) 1 __t2nZc836 __v0) (neq p __v0) (join mp_join_ans (0 1) 1 __t6jFY835 res)) (head (emit mp_put_ans (0 1) __t6Fc5832 res)) map.slog:45 #f)
  class ReadTask588 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_putindex572;  slog::Index** mp_joinindex573;  slog::Index** mp_mskindex574;  slog::Index** $sup5638x44x0x0x0index575;  slog::Index** mp_putindex576;  slog::Index** mleafindex577;  slog::Index** mp_mskindex578;  slog::Index** mp_joinindex579;  slog::Index** mleafindex580;  slog::Index** mp_join_ansindex581;  slog::Index** mp_mskindex582;  slog::Index** mp_msk_ansindex583;  slog::Index** mp_join_ansindex584;  slog::Index** mp_joindelta585;  slog::Index** mleafdelta586;  slog::Index** mp_mskdelta587;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_ans");
      std::vector<u16> ord589({0, 1});
      slog::Relation* readrel590 = db->getRelation("mp_put_ans");
      head_index[0] = readrel590->getIndex(ord589, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord591({1, 2, 3, 0});
      slog::Relation* readrel592 = db->getRelation("mp_put");
      mp_putindex572 = readrel592->getIndex(ord591, false);
      std::vector<u16> ord593({3, 4, 1, 0, 2});
      slog::Relation* readrel594 = db->getRelation("mp_join");
      mp_joinindex573 = readrel594->getIndex(ord593, false);
      std::vector<u16> ord595({2, 0, 1});
      slog::Relation* readrel596 = db->getRelation("mp_msk");
      mp_mskindex574 = readrel596->getIndex(ord595, false);
      std::vector<u16> ord597({2, 3, 4, 5, 6, 0, 1, 7});
      slog::Relation* readrel598 = db->getRelation("$sup5638x44x0x0x0");
      $sup5638x44x0x0x0index575 = readrel598->getIndex(ord597, false);
      std::vector<u16> ord599({0, 2, 1, 3});
      slog::Relation* readrel600 = db->getRelation("mp_put");
      mp_putindex576 = readrel600->getIndex(ord599, false);
      std::vector<u16> ord601({1, 2, 0});
      slog::Relation* readrel602 = db->getRelation("mleaf");
      mleafindex577 = readrel602->getIndex(ord601, false);
      std::vector<u16> ord603({1, 2, 0});
      slog::Relation* readrel604 = db->getRelation("mp_msk");
      mp_mskindex578 = readrel604->getIndex(ord603, false);
      std::vector<u16> ord605({3, 4, 1, 0, 2});
      slog::Relation* readrel606 = db->getRelation("mp_join");
      mp_joinindex579 = readrel606->getIndex(ord605, false);
      std::vector<u16> ord607({3, 4, 1, 0, 2});
      slog::Relation* readrel608 = db->getRelation("mp_join");
      mp_joindelta585 = readrel608->getIndex(ord607, true);
      std::vector<u16> ord609({0, 1, 2});
      slog::Relation* readrel610 = db->getRelation("mleaf");
      mleafindex580 = readrel610->getIndex(ord609, false);
      std::vector<u16> ord611({0, 1, 2});
      slog::Relation* readrel612 = db->getRelation("mleaf");
      mleafdelta586 = readrel612->getIndex(ord611, true);
      std::vector<u16> ord613({0, 1});
      slog::Relation* readrel614 = db->getRelation("mp_join_ans");
      mp_join_ansindex581 = readrel614->getIndex(ord613, false);
      std::vector<u16> ord615({1, 2, 0});
      slog::Relation* readrel616 = db->getRelation("mp_msk");
      mp_mskindex582 = readrel616->getIndex(ord615, false);
      std::vector<u16> ord617({1, 2, 0});
      slog::Relation* readrel618 = db->getRelation("mp_msk");
      mp_mskdelta587 = readrel618->getIndex(ord617, true);
      std::vector<u16> ord619({0, 1});
      slog::Relation* readrel620 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex583 = readrel620->getIndex(ord619, false);
      std::vector<u16> ord621({0, 1});
      slog::Relation* readrel622 = db->getRelation("mp_join_ans");
      mp_join_ansindex584 = readrel622->getIndex(ord621, false);
  
    }
    ReadTask588(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c173 = _t[0];
        u64 v_c3 = _t[1];
        u64 v_c2 = _t[2];
        u64 v_c5 = _t[3];
        u64 v_c6 = _t[4];
        if (!slog::exists_probe<4,1>(mp_putindex572, std::array<u64,4>{v_c173, 0, 0, 0})) return;
        if (!slog::exists_probe<5,2>(mp_joinindex573, std::array<u64,5>{v_c3, v_c173, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex574, std::array<u64,3>{v_c2, 0, 0})) return;
        slog::join_probe<8,5>($sup5638x44x0x0x0index575, std::array<u64,8>{v_c5, v_c2, v_c3, v_c6, v_c173, 0, 0, 0}, [&](const std::array<u64,8>& m623) {
          u64 v_c174 = m623[5]; u64 v_c1 = m623[6]; u64 v_c7 = m623[7];
          slog::join_probe<4,4>(mp_putindex576, std::array<u64,4>{v_c174, v_c1, v_c173, v_c7}, [&](const std::array<u64,4>& m624) {
            if (!slog::exists_probe<3,2>(mleafindex577, std::array<u64,3>{v_c1, v_c7, 0})) return;
            if (!slog::exists_probe<3,2>(mp_mskindex578, std::array<u64,3>{v_c1, v_c2, 0})) return;
            slog::join_probe_old<5,3>(mp_joinindex579, mp_joindelta585, std::array<u64,5>{v_c3, v_c173, v_c1, 0, 0}, [&](const std::array<u64,5>& m625) {
              u64 v_c175 = m625[3]; u64 v_c176 = m625[4];
              slog::join_probe_old<3,3>(mleafindex580, mleafdelta586, std::array<u64,3>{v_c176, v_c1, v_c7}, [&](const std::array<u64,3>& m626) {
                if (!slog::exists_probe<2,1>(mp_join_ansindex581, std::array<u64,2>{v_c175, 0})) return;
                slog::join_probe_old<3,2>(mp_mskindex582, mp_mskdelta587, std::array<u64,3>{v_c1, v_c2, 0}, [&](const std::array<u64,3>& m627) {
                  u64 v_c177 = m627[2];
                  slog::join_probe<2,1>(mp_msk_ansindex583, std::array<u64,2>{v_c177, 0}, [&](const std::array<u64,2>& m628) {
                    u64 v_c41 = m628[1];
                    if (v_c3 == v_c41) return;
                    slog::join_probe<2,1>(mp_join_ansindex584, std::array<u64,2>{v_c175, 0}, [&](const std::array<u64,2>& m629) {
                      u64 v_c46 = m629[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c174, v_c46}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:45", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask588* _cont = new ReadTask588(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask588(db,b), false);
  // (crule (pre) (scan mp_union __t70BJ454 __t4xjy453 __t1p4P452) (body (exists $sup5638x93x0x0x0 (0 1 2 3 4 5 6) 1 __t70BJ454) (join mbranch (0 1 2 3 4) 1 __t1p4P452 p m u v) (exists mbranch (0 1 2 3 4) 3 __t4xjy453 p m) (exists mp_union (2 0 1) 1 u) (exists mp_union (2 0 1) 1 v) (join $sup5638x93x0x0x0 (2 3 5 6 0 1 4) 5 m p u v __t70BJ454 l r) (join mbranch (1 2 3 4 0) 5 p m l r __t4xjy453) (exists mp_union (1 2 0) 2 r v) (join-old mp_union (1 2 0) 2 (1 2 0) l u __t1OdF455) (exists mp_union_ans (0 1) 1 __t1OdF455) (join-old mp_union (1 2 0) 2 (1 2 0) r v __t4atM456) (exists mp_union_ans (0 1) 1 __t4atM456) (join mp_union_ans (0 1) 1 __t1OdF455 __v0) (join mp_union_ans (0 1) 1 __t4atM456 __v1)) (head (emit-temp temp9Yrn2045 __t70BJ454 __v0 __v1 m p) (mkstruct mbranch (1 2 3 4 0) __t8Q9x451 p m __v0 __v1)) map.slog:94 #f)
  class ReadTask646 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x93x0x0x0index630;  slog::Index** mbranchindex631;  slog::Index** mbranchindex632;  slog::Index** mp_unionindex633;  slog::Index** mp_unionindex634;  slog::Index** $sup5638x93x0x0x0index635;  slog::Index** mbranchindex636;  slog::Index** mp_unionindex637;  slog::Index** mp_unionindex638;  slog::Index** mp_union_ansindex639;  slog::Index** mp_unionindex640;  slog::Index** mp_union_ansindex641;  slog::Index** mp_union_ansindex642;  slog::Index** mp_union_ansindex643;  slog::Index** mp_uniondelta644;  slog::Index** mp_uniondelta645;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9Yrn2045");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord647({0, 1, 2, 3, 4, 5, 6});
      slog::Relation* readrel648 = db->getRelation("$sup5638x93x0x0x0");
      $sup5638x93x0x0x0index630 = readrel648->getIndex(ord647, false);
      std::vector<u16> ord649({0, 1, 2, 3, 4});
      slog::Relation* readrel650 = db->getRelation("mbranch");
      mbranchindex631 = readrel650->getIndex(ord649, false);
      std::vector<u16> ord651({0, 1, 2, 3, 4});
      slog::Relation* readrel652 = db->getRelation("mbranch");
      mbranchindex632 = readrel652->getIndex(ord651, false);
      std::vector<u16> ord653({2, 0, 1});
      slog::Relation* readrel654 = db->getRelation("mp_union");
      mp_unionindex633 = readrel654->getIndex(ord653, false);
      std::vector<u16> ord655({2, 0, 1});
      slog::Relation* readrel656 = db->getRelation("mp_union");
      mp_unionindex634 = readrel656->getIndex(ord655, false);
      std::vector<u16> ord657({2, 3, 5, 6, 0, 1, 4});
      slog::Relation* readrel658 = db->getRelation("$sup5638x93x0x0x0");
      $sup5638x93x0x0x0index635 = readrel658->getIndex(ord657, false);
      std::vector<u16> ord659({1, 2, 3, 4, 0});
      slog::Relation* readrel660 = db->getRelation("mbranch");
      mbranchindex636 = readrel660->getIndex(ord659, false);
      std::vector<u16> ord661({1, 2, 0});
      slog::Relation* readrel662 = db->getRelation("mp_union");
      mp_unionindex637 = readrel662->getIndex(ord661, false);
      std::vector<u16> ord663({1, 2, 0});
      slog::Relation* readrel664 = db->getRelation("mp_union");
      mp_unionindex638 = readrel664->getIndex(ord663, false);
      std::vector<u16> ord665({1, 2, 0});
      slog::Relation* readrel666 = db->getRelation("mp_union");
      mp_uniondelta644 = readrel666->getIndex(ord665, true);
      std::vector<u16> ord667({0, 1});
      slog::Relation* readrel668 = db->getRelation("mp_union_ans");
      mp_union_ansindex639 = readrel668->getIndex(ord667, false);
      std::vector<u16> ord669({1, 2, 0});
      slog::Relation* readrel670 = db->getRelation("mp_union");
      mp_unionindex640 = readrel670->getIndex(ord669, false);
      std::vector<u16> ord671({1, 2, 0});
      slog::Relation* readrel672 = db->getRelation("mp_union");
      mp_uniondelta645 = readrel672->getIndex(ord671, true);
      std::vector<u16> ord673({0, 1});
      slog::Relation* readrel674 = db->getRelation("mp_union_ans");
      mp_union_ansindex641 = readrel674->getIndex(ord673, false);
      std::vector<u16> ord675({0, 1});
      slog::Relation* readrel676 = db->getRelation("mp_union_ans");
      mp_union_ansindex642 = readrel676->getIndex(ord675, false);
      std::vector<u16> ord677({0, 1});
      slog::Relation* readrel678 = db->getRelation("mp_union_ans");
      mp_union_ansindex643 = readrel678->getIndex(ord677, false);
  
    }
    ReadTask646(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c178 = _t[0];
        u64 v_c179 = _t[1];
        u64 v_c180 = _t[2];
        if (!slog::exists_probe<7,1>($sup5638x93x0x0x0index630, std::array<u64,7>{v_c178, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe<5,1>(mbranchindex631, std::array<u64,5>{v_c180, 0, 0, 0, 0}, [&](const std::array<u64,5>& m679) {
          u64 v_c3 = m679[1]; u64 v_c2 = m679[2]; u64 v_c60 = m679[3]; u64 v_c7 = m679[4];
          if (!slog::exists_probe<5,3>(mbranchindex632, std::array<u64,5>{v_c179, v_c3, v_c2, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_unionindex633, std::array<u64,3>{v_c60, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_unionindex634, std::array<u64,3>{v_c7, 0, 0})) return;
          slog::join_probe<7,5>($sup5638x93x0x0x0index635, std::array<u64,7>{v_c2, v_c3, v_c60, v_c7, v_c178, 0, 0}, [&](const std::array<u64,7>& m680) {
            u64 v_c5 = m680[5]; u64 v_c6 = m680[6];
            slog::join_probe<5,5>(mbranchindex636, std::array<u64,5>{v_c3, v_c2, v_c5, v_c6, v_c179}, [&](const std::array<u64,5>& m681) {
              if (!slog::exists_probe<3,2>(mp_unionindex637, std::array<u64,3>{v_c6, v_c7, 0})) return;
              slog::join_probe_old<3,2>(mp_unionindex638, mp_uniondelta644, std::array<u64,3>{v_c5, v_c60, 0}, [&](const std::array<u64,3>& m682) {
                u64 v_c181 = m682[2];
                if (!slog::exists_probe<2,1>(mp_union_ansindex639, std::array<u64,2>{v_c181, 0})) return;
                slog::join_probe_old<3,2>(mp_unionindex640, mp_uniondelta645, std::array<u64,3>{v_c6, v_c7, 0}, [&](const std::array<u64,3>& m683) {
                  u64 v_c182 = m683[2];
                  if (!slog::exists_probe<2,1>(mp_union_ansindex641, std::array<u64,2>{v_c182, 0})) return;
                  slog::join_probe<2,1>(mp_union_ansindex642, std::array<u64,2>{v_c181, 0}, [&](const std::array<u64,2>& m684) {
                    u64 v_c41 = m684[1];
                    slog::join_probe<2,1>(mp_union_ansindex643, std::array<u64,2>{v_c182, 0}, [&](const std::array<u64,2>& m685) {
                      u64 v_c183 = m685[1];
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c178, v_c41, v_c183, v_c2, v_c3});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c3, v_c2, v_c41, v_c183}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:94", "delta:mp_union", _fires);
  
      if (!_done)
      {
        ReadTask646* _cont = new ReadTask646(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask646(db,b), false);
  // (crule (pre (let __tconst2mJz511 constf5ca38f748a1d6eaf726b8a4) (let __tconst3zaK478 const0933fb667296882d8c45abca) (let __tconst6GsZ491 consted725292f5f32d61535958c1) (let __tconst0Ob1494 const6b86b273ff34fce19d6b804e) (let __tconst91JR503 const90fb9068eda6f2d68bb61c33)) (scan temp29qZ2003 __t0cTh509 __t18Fx502 __t3yjA501 __t4qrC508 __t7hSc477 __t8A1z467) (body (exists primref (1 0) 1 __tconst6GsZ491) (exists primref (1 0) 1 __tconst3zaK478) (exists num (1 0) 1 __tconst0Ob1494) (exists ref (1 0) 1 __tconst2mJz511) (exists app (2 0 1) 1 __t8A1z467) (join primref (1 0) 1 __tconst91JR503 __t8Gth504) (join primref (1 0) 1 __tconst6GsZ491 __t3x0f492) (join primref (1 0) 1 __tconst3zaK478 __t2abh479) (join num (1 0) 1 __tconst0Ob1494 __t1oVV472) (join ref (1 0) 1 __tconst2mJz511 __t1y5d469) (join app (1 2 0) 2 __t1y5d469 __t8A1z467 __t2zNy470)) (head (emit-temp temp7ZBA2004 __t0cTh509 __t18Fx502 __t2zNy470 __t3yjA501 __t4qrC508 __t7hSc477) (mkstruct app (1 2 0) __t9p5V480 __t2abh479 __t7hSc477) (mkstruct app (1 2 0) __t0Vtj505 __t8Gth504 __t18Fx502)) kcfa.slog:40 #f)
  class ReadTask697 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** primrefindex686;  slog::Index** primrefindex687;  slog::Index** numindex688;  slog::Index** refindex689;  slog::Index** appindex690;  slog::Index** primrefindex691;  slog::Index** primrefindex692;  slog::Index** primrefindex693;  slog::Index** numindex694;  slog::Index** refindex695;  slog::Index** appindex696;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7ZBA2004");
      head_rel[1] = db->getRelation("app");
      head_rel[2] = db->getRelation("app");
      outer_rel = db->getRelation("temp29qZ2003");
      std::vector<u16> ord698({1, 0});
      slog::Relation* readrel699 = db->getRelation("primref");
      primrefindex686 = readrel699->getIndex(ord698, false);
      std::vector<u16> ord700({1, 0});
      slog::Relation* readrel701 = db->getRelation("primref");
      primrefindex687 = readrel701->getIndex(ord700, false);
      std::vector<u16> ord702({1, 0});
      slog::Relation* readrel703 = db->getRelation("num");
      numindex688 = readrel703->getIndex(ord702, false);
      std::vector<u16> ord704({1, 0});
      slog::Relation* readrel705 = db->getRelation("ref");
      refindex689 = readrel705->getIndex(ord704, false);
      std::vector<u16> ord706({2, 0, 1});
      slog::Relation* readrel707 = db->getRelation("app");
      appindex690 = readrel707->getIndex(ord706, false);
      std::vector<u16> ord708({1, 0});
      slog::Relation* readrel709 = db->getRelation("primref");
      primrefindex691 = readrel709->getIndex(ord708, false);
      std::vector<u16> ord710({1, 0});
      slog::Relation* readrel711 = db->getRelation("primref");
      primrefindex692 = readrel711->getIndex(ord710, false);
      std::vector<u16> ord712({1, 0});
      slog::Relation* readrel713 = db->getRelation("primref");
      primrefindex693 = readrel713->getIndex(ord712, false);
      std::vector<u16> ord714({1, 0});
      slog::Relation* readrel715 = db->getRelation("num");
      numindex694 = readrel715->getIndex(ord714, false);
      std::vector<u16> ord716({1, 0});
      slog::Relation* readrel717 = db->getRelation("ref");
      refindex695 = readrel717->getIndex(ord716, false);
      std::vector<u16> ord718({1, 2, 0});
      slog::Relation* readrel719 = db->getRelation("app");
      appindex696 = readrel719->getIndex(ord718, false);
  
    }
    ReadTask697(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c89 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c148 = v_const0933fb667296882d8c45abca;
      u64 v_c149 = v_consted725292f5f32d61535958c1;
      u64 v_c150 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c152 = v_const90fb9068eda6f2d68bb61c33;
  
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
        u64 v_c90 = _t[0];
        u64 v_c163 = _t[1];
        u64 v_c153 = _t[2];
        u64 v_c154 = _t[3];
        u64 v_c162 = _t[4];
        u64 v_c155 = _t[5];
        if (!slog::exists_probe<2,1>(primrefindex686, std::array<u64,2>{v_c149, 0})) return;
        if (!slog::exists_probe<2,1>(primrefindex687, std::array<u64,2>{v_c148, 0})) return;
        if (!slog::exists_probe<2,1>(numindex688, std::array<u64,2>{v_c150, 0})) return;
        if (!slog::exists_probe<2,1>(refindex689, std::array<u64,2>{v_c89, 0})) return;
        if (!slog::exists_probe<3,1>(appindex690, std::array<u64,3>{v_c155, 0, 0})) return;
        slog::join_probe<2,1>(primrefindex691, std::array<u64,2>{v_c152, 0}, [&](const std::array<u64,2>& m720) {
          u64 v_c156 = m720[1];
          slog::join_probe<2,1>(primrefindex692, std::array<u64,2>{v_c149, 0}, [&](const std::array<u64,2>& m721) {
            u64 v_c158 = m721[1];
            slog::join_probe<2,1>(primrefindex693, std::array<u64,2>{v_c148, 0}, [&](const std::array<u64,2>& m722) {
              u64 v_c159 = m722[1];
              slog::join_probe<2,1>(numindex694, std::array<u64,2>{v_c150, 0}, [&](const std::array<u64,2>& m723) {
                u64 v_c160 = m723[1];
                slog::join_probe<2,1>(refindex695, std::array<u64,2>{v_c89, 0}, [&](const std::array<u64,2>& m724) {
                  u64 v_c161 = m724[1];
                  slog::join_probe<3,2>(appindex696, std::array<u64,3>{v_c161, v_c155, 0}, [&](const std::array<u64,3>& m725) {
                    u64 v_c91 = m725[2];
                    ++_fires;
                    slog::emit_temp<6>(head_rel[0], newbatch[0], std::array<u64,6>{v_c90, v_c163, v_c91, v_c153, v_c154, v_c162});
                    slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c159, v_c162}, std::array<u16,3>{1, 2, 0});
                    slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c156, v_c163}, std::array<u16,3>{1, 2, 0});
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
  
      if (_fires) db->bumpFires("kcfa.slog:40", "delta:temp29qZ2003", _fires);
  
      if (!_done)
      {
        ReadTask697* _cont = new ReadTask697(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask697(db,b), false);
  // (crule (pre) (scan temp4Zu91795 __t7695542 b) (body (join boolval (1 0) 1 b __t4iE5541)) (head (emit delta_ans (0 1) __t7695542 __t4iE5541)) interp.slog:117 #f)
  class ReadTask727 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** boolvalindex726;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("delta_ans");
      std::vector<u16> ord728({0, 1});
      slog::Relation* readrel729 = db->getRelation("delta_ans");
      head_index[0] = readrel729->getIndex(ord728, false);
      outer_rel = db->getRelation("temp4Zu91795");
      std::vector<u16> ord730({1, 0});
      slog::Relation* readrel731 = db->getRelation("boolval");
      boolvalindex726 = readrel731->getIndex(ord730, false);
  
    }
    ReadTask727(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c184 = _t[0];
        u64 v_c77 = _t[1];
        slog::join_probe<2,1>(boolvalindex726, std::array<u64,2>{v_c77, 0}, [&](const std::array<u64,2>& m732) {
          u64 v_c185 = m732[1];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c184, v_c185}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:117", "delta:temp4Zu91795", _fires);
  
      if (!_done)
      {
        ReadTask727* _cont = new ReadTask727(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask727(db,b), false);
  // (crule (pre (let __tconst6yBc1412 const0122baa3ac55f1b433944eb1) (let __tconst2fTo4 const06abaa100ecef791ce028c56) (let _00024sqc0dj4865 constd4735e3a265e16eee03f5971) (let _00024sqc32Jr866 const5feceb66ffc86f38d952786c) (let _00024sqc79IH867 const6b86b273ff34fce19d6b804e) (let _00024sqo5fwv868 const5feceb66ffc86f38d952786c) (let _00024sqo41sW869 const6b86b273ff34fce19d6b804e) (let _00024sqo1lCq870 const6b86b273ff34fce19d6b804e) (let _00024sqo4Tlp871 const5feceb66ffc86f38d952786c)) (scan prim __t4CTM7 op) (body (exists $seq_at (1 0 2) 2 _00024sqo41sW869 __t4CTM7) (exists $seq_atr (1 0 2) 2 _00024sqo1lCq870 __t4CTM7) (exists $seq_atr (1 0 2) 2 _00024sqo4Tlp871 __t4CTM7) (exists delta (1 2 0) 1 __tconst2fTo4) (exists _enum (1 0) 1 __tconst6yBc1412) (join-old $seq_at (1 0 2) 2 (1 0 2) _00024sqo5fwv868 __t4CTM7 _00024seq2) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo41sW869 __t4CTM7 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo1lCq870 __t4CTM7 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo4Tlp871 __t4CTM7 _00024seq2) (join delta (1 2 0) 2 __tconst2fTo4 _00024seq2 __t9sv95) (join _enum (1 0) 1 __tconst6yBc1412 __t55Md2) (letp _00024sql5qXm863 (aslst _00024seq2)) (let chk6cQ31922 (llen _00024sql5qXm863)) (eq _00024sqc0dj4865 chk6cQ31922) (letp chk2Vaq1923 (lref _00024sql5qXm863 _00024sqc32Jr866)) (eq __t4CTM7 chk2Vaq1923) (letp chk5j651924 (lref _00024sql5qXm863 _00024sqc79IH867)) (eq __t4CTM7 chk5j651924)) (head (emit-temp temp16EG1919 __t9sv95) (mkstruct boolval (1 0) __t5Yya3 __t55Md2)) interp.slog:123 #f)
  class ReadTask748 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $seq_atindex733;  slog::Index** $seq_atrindex734;  slog::Index** $seq_atrindex735;  slog::Index** deltaindex736;  slog::Index** _enumindex737;  slog::Index** $seq_atindex738;  slog::Index** $seq_atindex739;  slog::Index** $seq_atrindex740;  slog::Index** $seq_atrindex741;  slog::Index** deltaindex742;  slog::Index** _enumindex743;  slog::Index** $seq_atdelta744;  slog::Index** $seq_atdelta745;  slog::Index** $seq_atrdelta746;  slog::Index** $seq_atrdelta747;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp16EG1919");
      head_rel[1] = db->getRelation("boolval");
      outer_rel = db->getRelation("prim");
      std::vector<u16> ord749({1, 0, 2});
      slog::Relation* readrel750 = db->getRelation("$seq_at");
      $seq_atindex733 = readrel750->getIndex(ord749, false);
      std::vector<u16> ord751({1, 0, 2});
      slog::Relation* readrel752 = db->getRelation("$seq_atr");
      $seq_atrindex734 = readrel752->getIndex(ord751, false);
      std::vector<u16> ord753({1, 0, 2});
      slog::Relation* readrel754 = db->getRelation("$seq_atr");
      $seq_atrindex735 = readrel754->getIndex(ord753, false);
      std::vector<u16> ord755({1, 2, 0});
      slog::Relation* readrel756 = db->getRelation("delta");
      deltaindex736 = readrel756->getIndex(ord755, false);
      std::vector<u16> ord757({1, 0});
      slog::Relation* readrel758 = db->getRelation("_enum");
      _enumindex737 = readrel758->getIndex(ord757, false);
      std::vector<u16> ord759({1, 0, 2});
      slog::Relation* readrel760 = db->getRelation("$seq_at");
      $seq_atindex738 = readrel760->getIndex(ord759, false);
      std::vector<u16> ord761({1, 0, 2});
      slog::Relation* readrel762 = db->getRelation("$seq_at");
      $seq_atdelta744 = readrel762->getIndex(ord761, true);
      std::vector<u16> ord763({1, 0, 2});
      slog::Relation* readrel764 = db->getRelation("$seq_at");
      $seq_atindex739 = readrel764->getIndex(ord763, false);
      std::vector<u16> ord765({1, 0, 2});
      slog::Relation* readrel766 = db->getRelation("$seq_at");
      $seq_atdelta745 = readrel766->getIndex(ord765, true);
      std::vector<u16> ord767({1, 0, 2});
      slog::Relation* readrel768 = db->getRelation("$seq_atr");
      $seq_atrindex740 = readrel768->getIndex(ord767, false);
      std::vector<u16> ord769({1, 0, 2});
      slog::Relation* readrel770 = db->getRelation("$seq_atr");
      $seq_atrdelta746 = readrel770->getIndex(ord769, true);
      std::vector<u16> ord771({1, 0, 2});
      slog::Relation* readrel772 = db->getRelation("$seq_atr");
      $seq_atrindex741 = readrel772->getIndex(ord771, false);
      std::vector<u16> ord773({1, 0, 2});
      slog::Relation* readrel774 = db->getRelation("$seq_atr");
      $seq_atrdelta747 = readrel774->getIndex(ord773, true);
      std::vector<u16> ord775({1, 2, 0});
      slog::Relation* readrel776 = db->getRelation("delta");
      deltaindex742 = readrel776->getIndex(ord775, false);
      std::vector<u16> ord777({1, 0});
      slog::Relation* readrel778 = db->getRelation("_enum");
      _enumindex743 = readrel778->getIndex(ord777, false);
  
    }
    ReadTask748(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c186 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c187 = v_const06abaa100ecef791ce028c56;
      u64 v_c188 = v_constd4735e3a265e16eee03f5971;
      u64 v_c189 = v_const5feceb66ffc86f38d952786c;
      u64 v_c190 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c191 = v_const5feceb66ffc86f38d952786c;
      u64 v_c192 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c193 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c194 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c195 = _t[0];
        u64 v_c196 = _t[1];
        if (!slog::exists_probe<3,2>($seq_atindex733, std::array<u64,3>{v_c192, v_c195, 0})) return;
        if (!slog::exists_probe<3,2>($seq_atrindex734, std::array<u64,3>{v_c193, v_c195, 0})) return;
        if (!slog::exists_probe<3,2>($seq_atrindex735, std::array<u64,3>{v_c194, v_c195, 0})) return;
        if (!slog::exists_probe<3,1>(deltaindex736, std::array<u64,3>{v_c187, 0, 0})) return;
        if (!slog::exists_probe<2,1>(_enumindex737, std::array<u64,2>{v_c186, 0})) return;
        slog::join_probe_old<3,2>($seq_atindex738, $seq_atdelta744, std::array<u64,3>{v_c191, v_c195, 0}, [&](const std::array<u64,3>& m779) {
          u64 v_c73 = m779[2];
          slog::join_probe_old<3,3>($seq_atindex739, $seq_atdelta745, std::array<u64,3>{v_c192, v_c195, v_c73}, [&](const std::array<u64,3>& m780) {
            slog::join_probe_old<3,3>($seq_atrindex740, $seq_atrdelta746, std::array<u64,3>{v_c193, v_c195, v_c73}, [&](const std::array<u64,3>& m781) {
              slog::join_probe_old<3,3>($seq_atrindex741, $seq_atrdelta747, std::array<u64,3>{v_c194, v_c195, v_c73}, [&](const std::array<u64,3>& m782) {
                slog::join_probe<3,2>(deltaindex742, std::array<u64,3>{v_c187, v_c73, 0}, [&](const std::array<u64,3>& m783) {
                  u64 v_c197 = m783[2];
                  slog::join_probe<2,1>(_enumindex743, std::array<u64,2>{v_c186, 0}, [&](const std::array<u64,2>& m784) {
                    u64 v_c198 = m784[1];
                    bool ok785 = true;
                    u64 v_c199 = _prim_aslst(db, v_c73, &ok785);
                    if (!ok785) return;
                    u64 v_c200 = _prim_llen(db, v_c199);
                    if (v_c200 == slog_error) { slog::emit_pending_error(db, "interp.slog:123"); return; }
                    if (v_c188 != v_c200) return;
                    bool ok786 = true;
                    u64 v_c201 = _prim_lref(db, v_c199, v_c189, &ok786);
                    if (!ok786) return;
                    if (v_c195 != v_c201) return;
                    bool ok787 = true;
                    u64 v_c202 = _prim_lref(db, v_c199, v_c190, &ok787);
                    if (!ok787) return;
                    if (v_c195 != v_c202) return;
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c197});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c198}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:123", "delta:prim", _fires);
  
      if (!_done)
      {
        ReadTask748* _cont = new ReadTask748(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask748(db,b), false);
  // (crule (pre) (scan $sup70016x95x0x0x0 __t7DhJ358 eb er rho t x) (body (exists mp_put (1 2 3 0) 3 rho x t) (exists letrec (1 2 3 0) 3 x er eb) (exists eval (2 3 0 1) 3 rho t __t7DhJ358) (exists eval (3 1 0 2) 2 t er) (exists eval (3 1 0 2) 2 t eb) (join-old $sup70016x95x0x0x1 (0 4 6 2 3 7 1 5) 6 (0 4 6 2 3 7 1 5) __t7DhJ358 rho t eb er x __t0Rig361 rho2) (join-old mp_put (0 2 1 3) 4 (0 2 1 3) __t0Rig361 x rho t) (exists eval (1 2 3 0) 3 er rho2 t) (exists eval (1 2 3 0) 3 eb rho2 t) (exists mp_put_ans (0 1) 2 __t0Rig361 rho2) (join-old letrec (1 2 3 0) 3 (1 2 3 0) x er eb __t0Sks357) (join-old eval (2 3 0 1) 4 (2 3 0 1) rho t __t7DhJ358 __t0Sks357) (join-old eval (1 2 3 0) 3 (1 2 3 0) er rho2 t __t6HuT359) (exists eval_ans (0 1) 1 __t6HuT359) (join-old eval (1 2 3 0) 3 (1 2 3 0) eb rho2 t __t63JF360) (join mp_put_ans (0 1) 2 __t0Rig361 rho2) (exists eval_ans (0 1) 1 __t63JF360) (join eval_ans (0 1) 1 __t6HuT359 vr) (join eval_ans (0 1) 1 __t63JF360 v)) (head (emit eval_ans (0 1) __t7DhJ358 v)) interp.slog:96 #f)
  class ReadTask813 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_putindex788;  slog::Index** letrecindex789;  slog::Index** evalindex790;  slog::Index** evalindex791;  slog::Index** evalindex792;  slog::Index** $sup70016x95x0x0x1index793;  slog::Index** mp_putindex794;  slog::Index** evalindex795;  slog::Index** evalindex796;  slog::Index** mp_put_ansindex797;  slog::Index** letrecindex798;  slog::Index** evalindex799;  slog::Index** evalindex800;  slog::Index** eval_ansindex801;  slog::Index** evalindex802;  slog::Index** mp_put_ansindex803;  slog::Index** eval_ansindex804;  slog::Index** eval_ansindex805;  slog::Index** eval_ansindex806;  slog::Index** $sup70016x95x0x0x1delta807;  slog::Index** mp_putdelta808;  slog::Index** letrecdelta809;  slog::Index** evaldelta810;  slog::Index** evaldelta811;  slog::Index** evaldelta812;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord814({0, 1});
      slog::Relation* readrel815 = db->getRelation("eval_ans");
      head_index[0] = readrel815->getIndex(ord814, false);
      outer_rel = db->getRelation("$sup70016x95x0x0x0");
      std::vector<u16> ord816({1, 2, 3, 0});
      slog::Relation* readrel817 = db->getRelation("mp_put");
      mp_putindex788 = readrel817->getIndex(ord816, false);
      std::vector<u16> ord818({1, 2, 3, 0});
      slog::Relation* readrel819 = db->getRelation("letrec");
      letrecindex789 = readrel819->getIndex(ord818, false);
      std::vector<u16> ord820({2, 3, 0, 1});
      slog::Relation* readrel821 = db->getRelation("eval");
      evalindex790 = readrel821->getIndex(ord820, false);
      std::vector<u16> ord822({3, 1, 0, 2});
      slog::Relation* readrel823 = db->getRelation("eval");
      evalindex791 = readrel823->getIndex(ord822, false);
      std::vector<u16> ord824({3, 1, 0, 2});
      slog::Relation* readrel825 = db->getRelation("eval");
      evalindex792 = readrel825->getIndex(ord824, false);
      std::vector<u16> ord826({0, 4, 6, 2, 3, 7, 1, 5});
      slog::Relation* readrel827 = db->getRelation("$sup70016x95x0x0x1");
      $sup70016x95x0x0x1index793 = readrel827->getIndex(ord826, false);
      std::vector<u16> ord828({0, 4, 6, 2, 3, 7, 1, 5});
      slog::Relation* readrel829 = db->getRelation("$sup70016x95x0x0x1");
      $sup70016x95x0x0x1delta807 = readrel829->getIndex(ord828, true);
      std::vector<u16> ord830({0, 2, 1, 3});
      slog::Relation* readrel831 = db->getRelation("mp_put");
      mp_putindex794 = readrel831->getIndex(ord830, false);
      std::vector<u16> ord832({0, 2, 1, 3});
      slog::Relation* readrel833 = db->getRelation("mp_put");
      mp_putdelta808 = readrel833->getIndex(ord832, true);
      std::vector<u16> ord834({1, 2, 3, 0});
      slog::Relation* readrel835 = db->getRelation("eval");
      evalindex795 = readrel835->getIndex(ord834, false);
      std::vector<u16> ord836({1, 2, 3, 0});
      slog::Relation* readrel837 = db->getRelation("eval");
      evalindex796 = readrel837->getIndex(ord836, false);
      std::vector<u16> ord838({0, 1});
      slog::Relation* readrel839 = db->getRelation("mp_put_ans");
      mp_put_ansindex797 = readrel839->getIndex(ord838, false);
      std::vector<u16> ord840({1, 2, 3, 0});
      slog::Relation* readrel841 = db->getRelation("letrec");
      letrecindex798 = readrel841->getIndex(ord840, false);
      std::vector<u16> ord842({1, 2, 3, 0});
      slog::Relation* readrel843 = db->getRelation("letrec");
      letrecdelta809 = readrel843->getIndex(ord842, true);
      std::vector<u16> ord844({2, 3, 0, 1});
      slog::Relation* readrel845 = db->getRelation("eval");
      evalindex799 = readrel845->getIndex(ord844, false);
      std::vector<u16> ord846({2, 3, 0, 1});
      slog::Relation* readrel847 = db->getRelation("eval");
      evaldelta810 = readrel847->getIndex(ord846, true);
      std::vector<u16> ord848({1, 2, 3, 0});
      slog::Relation* readrel849 = db->getRelation("eval");
      evalindex800 = readrel849->getIndex(ord848, false);
      std::vector<u16> ord850({1, 2, 3, 0});
      slog::Relation* readrel851 = db->getRelation("eval");
      evaldelta811 = readrel851->getIndex(ord850, true);
      std::vector<u16> ord852({0, 1});
      slog::Relation* readrel853 = db->getRelation("eval_ans");
      eval_ansindex801 = readrel853->getIndex(ord852, false);
      std::vector<u16> ord854({1, 2, 3, 0});
      slog::Relation* readrel855 = db->getRelation("eval");
      evalindex802 = readrel855->getIndex(ord854, false);
      std::vector<u16> ord856({1, 2, 3, 0});
      slog::Relation* readrel857 = db->getRelation("eval");
      evaldelta812 = readrel857->getIndex(ord856, true);
      std::vector<u16> ord858({0, 1});
      slog::Relation* readrel859 = db->getRelation("mp_put_ans");
      mp_put_ansindex803 = readrel859->getIndex(ord858, false);
      std::vector<u16> ord860({0, 1});
      slog::Relation* readrel861 = db->getRelation("eval_ans");
      eval_ansindex804 = readrel861->getIndex(ord860, false);
      std::vector<u16> ord862({0, 1});
      slog::Relation* readrel863 = db->getRelation("eval_ans");
      eval_ansindex805 = readrel863->getIndex(ord862, false);
      std::vector<u16> ord864({0, 1});
      slog::Relation* readrel865 = db->getRelation("eval_ans");
      eval_ansindex806 = readrel865->getIndex(ord864, false);
  
    }
    ReadTask813(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c203 = _t[0];
        u64 v_c107 = _t[1];
        u64 v_c204 = _t[2];
        u64 v_c85 = _t[3];
        u64 v_c86 = _t[4];
        u64 v_c205 = _t[5];
        if (!slog::exists_probe<4,3>(mp_putindex788, std::array<u64,4>{v_c85, v_c205, v_c86, 0})) return;
        if (!slog::exists_probe<4,3>(letrecindex789, std::array<u64,4>{v_c205, v_c204, v_c107, 0})) return;
        if (!slog::exists_probe<4,3>(evalindex790, std::array<u64,4>{v_c85, v_c86, v_c203, 0})) return;
        if (!slog::exists_probe<4,2>(evalindex791, std::array<u64,4>{v_c86, v_c204, 0, 0})) return;
        if (!slog::exists_probe<4,2>(evalindex792, std::array<u64,4>{v_c86, v_c107, 0, 0})) return;
        slog::join_probe_old<8,6>($sup70016x95x0x0x1index793, $sup70016x95x0x0x1delta807, std::array<u64,8>{v_c203, v_c85, v_c86, v_c107, v_c204, v_c205, 0, 0}, [&](const std::array<u64,8>& m866) {
          u64 v_c206 = m866[6]; u64 v_c207 = m866[7];
          slog::join_probe_old<4,4>(mp_putindex794, mp_putdelta808, std::array<u64,4>{v_c206, v_c205, v_c85, v_c86}, [&](const std::array<u64,4>& m867) {
            if (!slog::exists_probe<4,3>(evalindex795, std::array<u64,4>{v_c204, v_c207, v_c86, 0})) return;
            if (!slog::exists_probe<4,3>(evalindex796, std::array<u64,4>{v_c107, v_c207, v_c86, 0})) return;
            if (!slog::exists_probe<2,2>(mp_put_ansindex797, std::array<u64,2>{v_c206, v_c207})) return;
            slog::join_probe_old<4,3>(letrecindex798, letrecdelta809, std::array<u64,4>{v_c205, v_c204, v_c107, 0}, [&](const std::array<u64,4>& m868) {
              u64 v_c208 = m868[3];
              slog::join_probe_old<4,4>(evalindex799, evaldelta810, std::array<u64,4>{v_c85, v_c86, v_c203, v_c208}, [&](const std::array<u64,4>& m869) {
                slog::join_probe_old<4,3>(evalindex800, evaldelta811, std::array<u64,4>{v_c204, v_c207, v_c86, 0}, [&](const std::array<u64,4>& m870) {
                  u64 v_c209 = m870[3];
                  if (!slog::exists_probe<2,1>(eval_ansindex801, std::array<u64,2>{v_c209, 0})) return;
                  slog::join_probe_old<4,3>(evalindex802, evaldelta812, std::array<u64,4>{v_c107, v_c207, v_c86, 0}, [&](const std::array<u64,4>& m871) {
                    u64 v_c210 = m871[3];
                    slog::join_probe<2,2>(mp_put_ansindex803, std::array<u64,2>{v_c206, v_c207}, [&](const std::array<u64,2>& m872) {
                      if (!slog::exists_probe<2,1>(eval_ansindex804, std::array<u64,2>{v_c210, 0})) return;
                      slog::join_probe<2,1>(eval_ansindex805, std::array<u64,2>{v_c209, 0}, [&](const std::array<u64,2>& m873) {
                        u64 v_c211 = m873[1];
                        slog::join_probe<2,1>(eval_ansindex806, std::array<u64,2>{v_c210, 0}, [&](const std::array<u64,2>& m874) {
                          u64 v_c7 = m874[1];
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c203, v_c7}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:96", "delta:$sup70016x95x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask813* _cont = new ReadTask813(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask813(db,b), false);
  // (crule (pre) (scan mp_union __t1OdF455 l u) (body (exists $sup5638x93x0x0x0 (1 5 0 2 3 4 6) 2 l u) (exists mbranch (3 0 1 2 4) 1 u) (exists mbranch (3 0 1 2 4) 1 l) (join mp_union_ans (0 1) 1 __t1OdF455 __v0) (join $sup5638x93x0x0x0 (1 5 0 2 3 4 6) 2 l u __t70BJ454 m p r v) (exists mbranch (1 2 3 4 0) 4 p m l r) (exists mp_union (1 2 0) 2 r v) (join mbranch (1 2 3 4 0) 4 p m u v __t1p4P452) (exists mp_union (2 0 1) 2 __t1p4P452 __t70BJ454) (join mbranch (1 2 3 4 0) 4 p m l r __t4xjy453) (join mp_union (0 1 2) 3 __t70BJ454 __t4xjy453 __t1p4P452) (join-old mp_union (1 2 0) 2 (1 2 0) r v __t4atM456) (join mp_union_ans (0 1) 1 __t4atM456 __v1)) (head (emit-temp temp9Yrn2045 __t70BJ454 __v0 __v1 m p) (mkstruct mbranch (1 2 3 4 0) __t8Q9x451 p m __v0 __v1)) map.slog:94 #f)
  class ReadTask889 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x93x0x0x0index875;  slog::Index** mbranchindex876;  slog::Index** mbranchindex877;  slog::Index** mp_union_ansindex878;  slog::Index** $sup5638x93x0x0x0index879;  slog::Index** mbranchindex880;  slog::Index** mp_unionindex881;  slog::Index** mbranchindex882;  slog::Index** mp_unionindex883;  slog::Index** mbranchindex884;  slog::Index** mp_unionindex885;  slog::Index** mp_unionindex886;  slog::Index** mp_union_ansindex887;  slog::Index** mp_uniondelta888;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9Yrn2045");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord890({1, 5, 0, 2, 3, 4, 6});
      slog::Relation* readrel891 = db->getRelation("$sup5638x93x0x0x0");
      $sup5638x93x0x0x0index875 = readrel891->getIndex(ord890, false);
      std::vector<u16> ord892({3, 0, 1, 2, 4});
      slog::Relation* readrel893 = db->getRelation("mbranch");
      mbranchindex876 = readrel893->getIndex(ord892, false);
      std::vector<u16> ord894({3, 0, 1, 2, 4});
      slog::Relation* readrel895 = db->getRelation("mbranch");
      mbranchindex877 = readrel895->getIndex(ord894, false);
      std::vector<u16> ord896({0, 1});
      slog::Relation* readrel897 = db->getRelation("mp_union_ans");
      mp_union_ansindex878 = readrel897->getIndex(ord896, false);
      std::vector<u16> ord898({1, 5, 0, 2, 3, 4, 6});
      slog::Relation* readrel899 = db->getRelation("$sup5638x93x0x0x0");
      $sup5638x93x0x0x0index879 = readrel899->getIndex(ord898, false);
      std::vector<u16> ord900({1, 2, 3, 4, 0});
      slog::Relation* readrel901 = db->getRelation("mbranch");
      mbranchindex880 = readrel901->getIndex(ord900, false);
      std::vector<u16> ord902({1, 2, 0});
      slog::Relation* readrel903 = db->getRelation("mp_union");
      mp_unionindex881 = readrel903->getIndex(ord902, false);
      std::vector<u16> ord904({1, 2, 3, 4, 0});
      slog::Relation* readrel905 = db->getRelation("mbranch");
      mbranchindex882 = readrel905->getIndex(ord904, false);
      std::vector<u16> ord906({2, 0, 1});
      slog::Relation* readrel907 = db->getRelation("mp_union");
      mp_unionindex883 = readrel907->getIndex(ord906, false);
      std::vector<u16> ord908({1, 2, 3, 4, 0});
      slog::Relation* readrel909 = db->getRelation("mbranch");
      mbranchindex884 = readrel909->getIndex(ord908, false);
      std::vector<u16> ord910({0, 1, 2});
      slog::Relation* readrel911 = db->getRelation("mp_union");
      mp_unionindex885 = readrel911->getIndex(ord910, false);
      std::vector<u16> ord912({1, 2, 0});
      slog::Relation* readrel913 = db->getRelation("mp_union");
      mp_unionindex886 = readrel913->getIndex(ord912, false);
      std::vector<u16> ord914({1, 2, 0});
      slog::Relation* readrel915 = db->getRelation("mp_union");
      mp_uniondelta888 = readrel915->getIndex(ord914, true);
      std::vector<u16> ord916({0, 1});
      slog::Relation* readrel917 = db->getRelation("mp_union_ans");
      mp_union_ansindex887 = readrel917->getIndex(ord916, false);
  
    }
    ReadTask889(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c181 = _t[0];
        u64 v_c5 = _t[1];
        u64 v_c60 = _t[2];
        if (!slog::exists_probe<7,2>($sup5638x93x0x0x0index875, std::array<u64,7>{v_c5, v_c60, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex876, std::array<u64,5>{v_c60, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex877, std::array<u64,5>{v_c5, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(mp_union_ansindex878, std::array<u64,2>{v_c181, 0}, [&](const std::array<u64,2>& m918) {
          u64 v_c41 = m918[1];
          slog::join_probe<7,2>($sup5638x93x0x0x0index879, std::array<u64,7>{v_c5, v_c60, 0, 0, 0, 0, 0}, [&](const std::array<u64,7>& m919) {
            u64 v_c178 = m919[2]; u64 v_c2 = m919[3]; u64 v_c3 = m919[4]; u64 v_c6 = m919[5]; u64 v_c7 = m919[6];
            if (!slog::exists_probe<5,4>(mbranchindex880, std::array<u64,5>{v_c3, v_c2, v_c5, v_c6, 0})) return;
            if (!slog::exists_probe<3,2>(mp_unionindex881, std::array<u64,3>{v_c6, v_c7, 0})) return;
            slog::join_probe<5,4>(mbranchindex882, std::array<u64,5>{v_c3, v_c2, v_c60, v_c7, 0}, [&](const std::array<u64,5>& m920) {
              u64 v_c180 = m920[4];
              if (!slog::exists_probe<3,2>(mp_unionindex883, std::array<u64,3>{v_c180, v_c178, 0})) return;
              slog::join_probe<5,4>(mbranchindex884, std::array<u64,5>{v_c3, v_c2, v_c5, v_c6, 0}, [&](const std::array<u64,5>& m921) {
                u64 v_c179 = m921[4];
                slog::join_probe<3,3>(mp_unionindex885, std::array<u64,3>{v_c178, v_c179, v_c180}, [&](const std::array<u64,3>& m922) {
                  slog::join_probe_old<3,2>(mp_unionindex886, mp_uniondelta888, std::array<u64,3>{v_c6, v_c7, 0}, [&](const std::array<u64,3>& m923) {
                    u64 v_c182 = m923[2];
                    slog::join_probe<2,1>(mp_union_ansindex887, std::array<u64,2>{v_c182, 0}, [&](const std::array<u64,2>& m924) {
                      u64 v_c183 = m924[1];
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c178, v_c41, v_c183, v_c2, v_c3});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c3, v_c2, v_c41, v_c183}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:94", "delta:mp_union", _fires);
  
      if (!_done)
      {
        ReadTask889* _cont = new ReadTask889(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask889(db,b), false);
  // (crule (pre) (scan eval_ans __t2MYH648 __v0) (body (exists select_branch (1 0 2 3) 1 __v0) (join-old eval (0 1 2 3) 1 (0 1 2 3) __t2MYH648 e1 rho t) (exists if (1 3 2 0) 1 e1) (exists eval (2 3 0 1) 2 rho t) (join-old $sup70016x87x0x0x0 (1 4 5 0 2 3) 3 (1 4 5 0 2 3) e1 rho t __t7kdB647 e2 e3) (exists eval (2 3 0 1) 3 rho t __t7kdB647) (exists select_branch (2 3 1 0) 3 e2 e3 __v0) (join-old if (1 3 2 0) 3 (1 3 2 0) e1 e3 e2 __t71xd646) (join-old eval (2 3 0 1) 4 (2 3 0 1) rho t __t7kdB647 __t71xd646) (join-old select_branch (2 3 1 0) 3 (2 3 1 0) e2 e3 __v0 __t1Vli649) (exists select_branch_ans (0 1) 1 __t1Vli649) (join-old eval (2 3 0 1) 2 (2 3 0 1) rho t __t4Rxn650 __v1) (join-old select_branch_ans (0 1) 2 (0 1) __t1Vli649 __v1) (join-old eval_ans (0 1) 1 (0 1) __t4Rxn650 __v2)) (head (emit eval_ans (0 1) __t7kdB647 __v2)) interp.slog:88 #f)
  class ReadTask947 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** select_branchindex925;  slog::Index** evalindex926;  slog::Index** ifindex927;  slog::Index** evalindex928;  slog::Index** $sup70016x87x0x0x0index929;  slog::Index** evalindex930;  slog::Index** select_branchindex931;  slog::Index** ifindex932;  slog::Index** evalindex933;  slog::Index** select_branchindex934;  slog::Index** select_branch_ansindex935;  slog::Index** evalindex936;  slog::Index** select_branch_ansindex937;  slog::Index** eval_ansindex938;  slog::Index** evaldelta939;  slog::Index** $sup70016x87x0x0x0delta940;  slog::Index** ifdelta941;  slog::Index** evaldelta942;  slog::Index** select_branchdelta943;  slog::Index** evaldelta944;  slog::Index** select_branch_ansdelta945;  slog::Index** eval_ansdelta946;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord948({0, 1});
      slog::Relation* readrel949 = db->getRelation("eval_ans");
      head_index[0] = readrel949->getIndex(ord948, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord950({1, 0, 2, 3});
      slog::Relation* readrel951 = db->getRelation("select_branch");
      select_branchindex925 = readrel951->getIndex(ord950, false);
      std::vector<u16> ord952({0, 1, 2, 3});
      slog::Relation* readrel953 = db->getRelation("eval");
      evalindex926 = readrel953->getIndex(ord952, false);
      std::vector<u16> ord954({0, 1, 2, 3});
      slog::Relation* readrel955 = db->getRelation("eval");
      evaldelta939 = readrel955->getIndex(ord954, true);
      std::vector<u16> ord956({1, 3, 2, 0});
      slog::Relation* readrel957 = db->getRelation("if");
      ifindex927 = readrel957->getIndex(ord956, false);
      std::vector<u16> ord958({2, 3, 0, 1});
      slog::Relation* readrel959 = db->getRelation("eval");
      evalindex928 = readrel959->getIndex(ord958, false);
      std::vector<u16> ord960({1, 4, 5, 0, 2, 3});
      slog::Relation* readrel961 = db->getRelation("$sup70016x87x0x0x0");
      $sup70016x87x0x0x0index929 = readrel961->getIndex(ord960, false);
      std::vector<u16> ord962({1, 4, 5, 0, 2, 3});
      slog::Relation* readrel963 = db->getRelation("$sup70016x87x0x0x0");
      $sup70016x87x0x0x0delta940 = readrel963->getIndex(ord962, true);
      std::vector<u16> ord964({2, 3, 0, 1});
      slog::Relation* readrel965 = db->getRelation("eval");
      evalindex930 = readrel965->getIndex(ord964, false);
      std::vector<u16> ord966({2, 3, 1, 0});
      slog::Relation* readrel967 = db->getRelation("select_branch");
      select_branchindex931 = readrel967->getIndex(ord966, false);
      std::vector<u16> ord968({1, 3, 2, 0});
      slog::Relation* readrel969 = db->getRelation("if");
      ifindex932 = readrel969->getIndex(ord968, false);
      std::vector<u16> ord970({1, 3, 2, 0});
      slog::Relation* readrel971 = db->getRelation("if");
      ifdelta941 = readrel971->getIndex(ord970, true);
      std::vector<u16> ord972({2, 3, 0, 1});
      slog::Relation* readrel973 = db->getRelation("eval");
      evalindex933 = readrel973->getIndex(ord972, false);
      std::vector<u16> ord974({2, 3, 0, 1});
      slog::Relation* readrel975 = db->getRelation("eval");
      evaldelta942 = readrel975->getIndex(ord974, true);
      std::vector<u16> ord976({2, 3, 1, 0});
      slog::Relation* readrel977 = db->getRelation("select_branch");
      select_branchindex934 = readrel977->getIndex(ord976, false);
      std::vector<u16> ord978({2, 3, 1, 0});
      slog::Relation* readrel979 = db->getRelation("select_branch");
      select_branchdelta943 = readrel979->getIndex(ord978, true);
      std::vector<u16> ord980({0, 1});
      slog::Relation* readrel981 = db->getRelation("select_branch_ans");
      select_branch_ansindex935 = readrel981->getIndex(ord980, false);
      std::vector<u16> ord982({2, 3, 0, 1});
      slog::Relation* readrel983 = db->getRelation("eval");
      evalindex936 = readrel983->getIndex(ord982, false);
      std::vector<u16> ord984({2, 3, 0, 1});
      slog::Relation* readrel985 = db->getRelation("eval");
      evaldelta944 = readrel985->getIndex(ord984, true);
      std::vector<u16> ord986({0, 1});
      slog::Relation* readrel987 = db->getRelation("select_branch_ans");
      select_branch_ansindex937 = readrel987->getIndex(ord986, false);
      std::vector<u16> ord988({0, 1});
      slog::Relation* readrel989 = db->getRelation("select_branch_ans");
      select_branch_ansdelta945 = readrel989->getIndex(ord988, true);
      std::vector<u16> ord990({0, 1});
      slog::Relation* readrel991 = db->getRelation("eval_ans");
      eval_ansindex938 = readrel991->getIndex(ord990, false);
      std::vector<u16> ord992({0, 1});
      slog::Relation* readrel993 = db->getRelation("eval_ans");
      eval_ansdelta946 = readrel993->getIndex(ord992, true);
  
    }
    ReadTask947(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c212 = _t[0];
        u64 v_c41 = _t[1];
        if (!slog::exists_probe<4,1>(select_branchindex925, std::array<u64,4>{v_c41, 0, 0, 0})) return;
        slog::join_probe_old<4,1>(evalindex926, evaldelta939, std::array<u64,4>{v_c212, 0, 0, 0}, [&](const std::array<u64,4>& m994) {
          u64 v_c213 = m994[1]; u64 v_c85 = m994[2]; u64 v_c86 = m994[3];
          if (!slog::exists_probe<4,1>(ifindex927, std::array<u64,4>{v_c213, 0, 0, 0})) return;
          if (!slog::exists_probe<4,2>(evalindex928, std::array<u64,4>{v_c85, v_c86, 0, 0})) return;
          slog::join_probe_old<6,3>($sup70016x87x0x0x0index929, $sup70016x87x0x0x0delta940, std::array<u64,6>{v_c213, v_c85, v_c86, 0, 0, 0}, [&](const std::array<u64,6>& m995) {
            u64 v_c214 = m995[3]; u64 v_c52 = m995[4]; u64 v_c53 = m995[5];
            if (!slog::exists_probe<4,3>(evalindex930, std::array<u64,4>{v_c85, v_c86, v_c214, 0})) return;
            if (!slog::exists_probe<4,3>(select_branchindex931, std::array<u64,4>{v_c52, v_c53, v_c41, 0})) return;
            slog::join_probe_old<4,3>(ifindex932, ifdelta941, std::array<u64,4>{v_c213, v_c53, v_c52, 0}, [&](const std::array<u64,4>& m996) {
              u64 v_c215 = m996[3];
              slog::join_probe_old<4,4>(evalindex933, evaldelta942, std::array<u64,4>{v_c85, v_c86, v_c214, v_c215}, [&](const std::array<u64,4>& m997) {
                slog::join_probe_old<4,3>(select_branchindex934, select_branchdelta943, std::array<u64,4>{v_c52, v_c53, v_c41, 0}, [&](const std::array<u64,4>& m998) {
                  u64 v_c216 = m998[3];
                  if (!slog::exists_probe<2,1>(select_branch_ansindex935, std::array<u64,2>{v_c216, 0})) return;
                  slog::join_probe_old<4,2>(evalindex936, evaldelta944, std::array<u64,4>{v_c85, v_c86, 0, 0}, [&](const std::array<u64,4>& m999) {
                    u64 v_c217 = m999[2]; u64 v_c183 = m999[3];
                    slog::join_probe_old<2,2>(select_branch_ansindex937, select_branch_ansdelta945, std::array<u64,2>{v_c216, v_c183}, [&](const std::array<u64,2>& m1000) {
                      slog::join_probe_old<2,1>(eval_ansindex938, eval_ansdelta946, std::array<u64,2>{v_c217, 0}, [&](const std::array<u64,2>& m1001) {
                        u64 v_c218 = m1001[1];
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c214, v_c218}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:88", "delta:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask947* _cont = new ReadTask947(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask947(db,b), false);
  // (crule (pre) (scan temp5onR1943 __t4XRi123 k site t) (body (let __t56KF124 (lpush __t4XRi123 site))) (head (emit-temp temp0HD91944 __t56KF124 k t)) context.slog:11 #f)
  class ReadTask1002 : public slog::Task
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
      head_rel[0] = db->getRelation("temp0HD91944");
      outer_rel = db->getRelation("temp5onR1943");
  
    }
    ReadTask1002(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c219 = _t[0];
        u64 v_c1 = _t[1];
        u64 v_c220 = _t[2];
        u64 v_c86 = _t[3];
        u64 v_c221 = _prim_lpush(db, v_c219, v_c220);
        if (v_c221 == slog_error) { slog::emit_pending_error(db, "context.slog:11"); return; }
        ++_fires;
        slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c221, v_c1, v_c86});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("context.slog:11", "delta:temp5onR1943", _fires);
  
      if (!_done)
      {
        ReadTask1002* _cont = new ReadTask1002(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1002(db,b), false);
  // (crule (pre (let __tconst4CIq418 const5feceb66ffc86f38d952786c)) (scan mp_union __t6aCH417 __t2QpY416 __t9vor415) (body (join mbranch (0 1 2 3 4) 1 __t9vor415 q n u v) (join mbranch (0 1 2 3 4) 1 __t2QpY416 p m l r) (cmp lt m n) (let __t1cei419 (band p n)) (cmp gt __t1cei419 __tconst4CIq418)) (head (emit $sup5638x107x0x0x0 (0 8 1 2 3 4 5 6 7) __t6aCH417 v l m n p q r u)) map.slog:108 #f)
  class ReadTask1005 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex1003;  slog::Index** mbranchindex1004;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x107x0x0x0");
      std::vector<u16> ord1006({0, 8, 1, 2, 3, 4, 5, 6, 7});
      slog::Relation* readrel1007 = db->getRelation("$sup5638x107x0x0x0");
      head_index[0] = readrel1007->getIndex(ord1006, false);
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord1008({0, 1, 2, 3, 4});
      slog::Relation* readrel1009 = db->getRelation("mbranch");
      mbranchindex1003 = readrel1009->getIndex(ord1008, false);
      std::vector<u16> ord1010({0, 1, 2, 3, 4});
      slog::Relation* readrel1011 = db->getRelation("mbranch");
      mbranchindex1004 = readrel1011->getIndex(ord1010, false);
  
    }
    ReadTask1005(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c222 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c225 = _t[2];
        slog::join_probe<5,1>(mbranchindex1003, std::array<u64,5>{v_c225, 0, 0, 0, 0}, [&](const std::array<u64,5>& m1012) {
          u64 v_c62 = m1012[1]; u64 v_c63 = m1012[2]; u64 v_c60 = m1012[3]; u64 v_c7 = m1012[4];
          slog::join_probe<5,1>(mbranchindex1004, std::array<u64,5>{v_c224, 0, 0, 0, 0}, [&](const std::array<u64,5>& m1013) {
            u64 v_c3 = m1013[1]; u64 v_c2 = m1013[2]; u64 v_c5 = m1013[3]; u64 v_c6 = m1013[4];
            u64 v_c226 = _prim_lt(db, v_c2, v_c63);
            if (v_c226 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
            if (!v_c226) return;
            u64 v_c227 = _prim_band(db, v_c3, v_c63);
            if (v_c227 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
            u64 v_c228 = _prim_gt(db, v_c227, v_c222);
            if (v_c228 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
            if (!v_c228) return;
            ++_fires;
            slog::emit<9>(head_rel[0], head_index[0], newbatch[0], std::array<u64,9>{v_c223, v_c7, v_c5, v_c2, v_c63, v_c3, v_c62, v_c6, v_c60}, std::array<u16,9>{0, 8, 1, 2, 3, 4, 5, 6, 7});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:108", "delta:mp_union", _fires);
  
      if (!_done)
      {
        ReadTask1005* _cont = new ReadTask1005(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1005(db,b), false);
  // (crule (pre) (scan app __t1NSj412 ef es) (body (join-old eval (1 2 3 0) 1 (1 2 3 0) __t1NSj412 rho t __t7Mwu413)) (head (emit $sup70016x51x0x0x0 (4 0 3 1 2) t __t7Mwu413 rho ef es)) interp.slog:52 #f)
  class ReadTask1018 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1016;  slog::Index** evaldelta1017;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup70016x51x0x0x0");
      std::vector<u16> ord1019({4, 0, 3, 1, 2});
      slog::Relation* readrel1020 = db->getRelation("$sup70016x51x0x0x0");
      head_index[0] = readrel1020->getIndex(ord1019, false);
      outer_rel = db->getRelation("app");
      std::vector<u16> ord1021({1, 2, 3, 0});
      slog::Relation* readrel1022 = db->getRelation("eval");
      evalindex1016 = readrel1022->getIndex(ord1021, false);
      std::vector<u16> ord1023({1, 2, 3, 0});
      slog::Relation* readrel1024 = db->getRelation("eval");
      evaldelta1017 = readrel1024->getIndex(ord1023, true);
  
    }
    ReadTask1018(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c98 = _t[1];
        u64 v_c99 = _t[2];
        slog::join_probe_old<4,1>(evalindex1016, evaldelta1017, std::array<u64,4>{v_c229, 0, 0, 0}, [&](const std::array<u64,4>& m1025) {
          u64 v_c85 = m1025[1]; u64 v_c86 = m1025[2]; u64 v_c230 = m1025[3];
          ++_fires;
          slog::emit<5>(head_rel[0], head_index[0], newbatch[0], std::array<u64,5>{v_c86, v_c230, v_c85, v_c98, v_c99}, std::array<u16,5>{4, 0, 3, 1, 2});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:52", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask1018* _cont = new ReadTask1018(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1018(db,b), false);
  // (crule (pre) (scan mp_put __t0mp6672 rho x t) (body (exists $sup70016x92x0x0x1 (2 6 7 9 0 4 5 1 3 8) 4 __t0mp6672 rho t x) (exists eval (2 3 0 1) 2 rho t) (exists let (1 2 3 0) 1 x) (exists eval (3 1 0 2) 1 t) (exists mp_put_ans (0 1) 1 __t0mp6672) (join $sup70016x92x0x0x0 (3 4 5 0 1 2) 3 rho t x __t5vg0669 eb er) (exists eval (1 2 3 0) 3 er rho t) (exists let (1 2 3 0) 3 x er eb) (exists eval (2 3 0 1) 3 rho t __t5vg0669) (exists eval (3 1 0 2) 2 t eb) (join $sup70016x92x0x0x1 (2 6 7 9 0 4 5 1 3 8) 7 __t0mp6672 rho t x __t5vg0669 eb er __t7GLg670 __v0 vr) (join eval (2 3 0 1) 4 rho t __t7GLg670 er) (exists eval (1 2 3 0) 3 eb __v0 t) (exists eval_ans (0 1) 2 __t7GLg670 vr) (exists mp_put_ans (0 1) 2 __t0mp6672 __v0) (join let (1 2 3 0) 3 x er eb __t2w2P668) (join eval (2 3 0 1) 4 rho t __t5vg0669 __t2w2P668) (join eval (1 2 3 0) 3 eb __v0 t __t3BcP671) (join eval_ans (0 1) 2 __t7GLg670 vr) (join mp_put_ans (0 1) 2 __t0mp6672 __v0) (join eval_ans (0 1) 1 __t3BcP671 v)) (head (emit eval_ans (0 1) __t5vg0669 v)) interp.slog:93 #f)
  class ReadTask1047 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup70016x92x0x0x1index1026;  slog::Index** evalindex1027;  slog::Index** letindex1028;  slog::Index** evalindex1029;  slog::Index** mp_put_ansindex1030;  slog::Index** $sup70016x92x0x0x0index1031;  slog::Index** evalindex1032;  slog::Index** letindex1033;  slog::Index** evalindex1034;  slog::Index** evalindex1035;  slog::Index** $sup70016x92x0x0x1index1036;  slog::Index** evalindex1037;  slog::Index** evalindex1038;  slog::Index** eval_ansindex1039;  slog::Index** mp_put_ansindex1040;  slog::Index** letindex1041;  slog::Index** evalindex1042;  slog::Index** evalindex1043;  slog::Index** eval_ansindex1044;  slog::Index** mp_put_ansindex1045;  slog::Index** eval_ansindex1046;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1048({0, 1});
      slog::Relation* readrel1049 = db->getRelation("eval_ans");
      head_index[0] = readrel1049->getIndex(ord1048, false);
      outer_rel = db->getRelation("mp_put");
      std::vector<u16> ord1050({2, 6, 7, 9, 0, 4, 5, 1, 3, 8});
      slog::Relation* readrel1051 = db->getRelation("$sup70016x92x0x0x1");
      $sup70016x92x0x0x1index1026 = readrel1051->getIndex(ord1050, false);
      std::vector<u16> ord1052({2, 3, 0, 1});
      slog::Relation* readrel1053 = db->getRelation("eval");
      evalindex1027 = readrel1053->getIndex(ord1052, false);
      std::vector<u16> ord1054({1, 2, 3, 0});
      slog::Relation* readrel1055 = db->getRelation("let");
      letindex1028 = readrel1055->getIndex(ord1054, false);
      std::vector<u16> ord1056({3, 1, 0, 2});
      slog::Relation* readrel1057 = db->getRelation("eval");
      evalindex1029 = readrel1057->getIndex(ord1056, false);
      std::vector<u16> ord1058({0, 1});
      slog::Relation* readrel1059 = db->getRelation("mp_put_ans");
      mp_put_ansindex1030 = readrel1059->getIndex(ord1058, false);
      std::vector<u16> ord1060({3, 4, 5, 0, 1, 2});
      slog::Relation* readrel1061 = db->getRelation("$sup70016x92x0x0x0");
      $sup70016x92x0x0x0index1031 = readrel1061->getIndex(ord1060, false);
      std::vector<u16> ord1062({1, 2, 3, 0});
      slog::Relation* readrel1063 = db->getRelation("eval");
      evalindex1032 = readrel1063->getIndex(ord1062, false);
      std::vector<u16> ord1064({1, 2, 3, 0});
      slog::Relation* readrel1065 = db->getRelation("let");
      letindex1033 = readrel1065->getIndex(ord1064, false);
      std::vector<u16> ord1066({2, 3, 0, 1});
      slog::Relation* readrel1067 = db->getRelation("eval");
      evalindex1034 = readrel1067->getIndex(ord1066, false);
      std::vector<u16> ord1068({3, 1, 0, 2});
      slog::Relation* readrel1069 = db->getRelation("eval");
      evalindex1035 = readrel1069->getIndex(ord1068, false);
      std::vector<u16> ord1070({2, 6, 7, 9, 0, 4, 5, 1, 3, 8});
      slog::Relation* readrel1071 = db->getRelation("$sup70016x92x0x0x1");
      $sup70016x92x0x0x1index1036 = readrel1071->getIndex(ord1070, false);
      std::vector<u16> ord1072({2, 3, 0, 1});
      slog::Relation* readrel1073 = db->getRelation("eval");
      evalindex1037 = readrel1073->getIndex(ord1072, false);
      std::vector<u16> ord1074({1, 2, 3, 0});
      slog::Relation* readrel1075 = db->getRelation("eval");
      evalindex1038 = readrel1075->getIndex(ord1074, false);
      std::vector<u16> ord1076({0, 1});
      slog::Relation* readrel1077 = db->getRelation("eval_ans");
      eval_ansindex1039 = readrel1077->getIndex(ord1076, false);
      std::vector<u16> ord1078({0, 1});
      slog::Relation* readrel1079 = db->getRelation("mp_put_ans");
      mp_put_ansindex1040 = readrel1079->getIndex(ord1078, false);
      std::vector<u16> ord1080({1, 2, 3, 0});
      slog::Relation* readrel1081 = db->getRelation("let");
      letindex1041 = readrel1081->getIndex(ord1080, false);
      std::vector<u16> ord1082({2, 3, 0, 1});
      slog::Relation* readrel1083 = db->getRelation("eval");
      evalindex1042 = readrel1083->getIndex(ord1082, false);
      std::vector<u16> ord1084({1, 2, 3, 0});
      slog::Relation* readrel1085 = db->getRelation("eval");
      evalindex1043 = readrel1085->getIndex(ord1084, false);
      std::vector<u16> ord1086({0, 1});
      slog::Relation* readrel1087 = db->getRelation("eval_ans");
      eval_ansindex1044 = readrel1087->getIndex(ord1086, false);
      std::vector<u16> ord1088({0, 1});
      slog::Relation* readrel1089 = db->getRelation("mp_put_ans");
      mp_put_ansindex1045 = readrel1089->getIndex(ord1088, false);
      std::vector<u16> ord1090({0, 1});
      slog::Relation* readrel1091 = db->getRelation("eval_ans");
      eval_ansindex1046 = readrel1091->getIndex(ord1090, false);
  
    }
    ReadTask1047(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c231 = _t[0];
        u64 v_c85 = _t[1];
        u64 v_c205 = _t[2];
        u64 v_c86 = _t[3];
        if (!slog::exists_probe<10,4>($sup70016x92x0x0x1index1026, std::array<u64,10>{v_c231, v_c85, v_c86, v_c205, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<4,2>(evalindex1027, std::array<u64,4>{v_c85, v_c86, 0, 0})) return;
        if (!slog::exists_probe<4,1>(letindex1028, std::array<u64,4>{v_c205, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(evalindex1029, std::array<u64,4>{v_c86, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_put_ansindex1030, std::array<u64,2>{v_c231, 0})) return;
        slog::join_probe<6,3>($sup70016x92x0x0x0index1031, std::array<u64,6>{v_c85, v_c86, v_c205, 0, 0, 0}, [&](const std::array<u64,6>& m1092) {
          u64 v_c232 = m1092[3]; u64 v_c107 = m1092[4]; u64 v_c204 = m1092[5];
          if (!slog::exists_probe<4,3>(evalindex1032, std::array<u64,4>{v_c204, v_c85, v_c86, 0})) return;
          if (!slog::exists_probe<4,3>(letindex1033, std::array<u64,4>{v_c205, v_c204, v_c107, 0})) return;
          if (!slog::exists_probe<4,3>(evalindex1034, std::array<u64,4>{v_c85, v_c86, v_c232, 0})) return;
          if (!slog::exists_probe<4,2>(evalindex1035, std::array<u64,4>{v_c86, v_c107, 0, 0})) return;
          slog::join_probe<10,7>($sup70016x92x0x0x1index1036, std::array<u64,10>{v_c231, v_c85, v_c86, v_c205, v_c232, v_c107, v_c204, 0, 0, 0}, [&](const std::array<u64,10>& m1093) {
            u64 v_c233 = m1093[7]; u64 v_c41 = m1093[8]; u64 v_c211 = m1093[9];
            slog::join_probe<4,4>(evalindex1037, std::array<u64,4>{v_c85, v_c86, v_c233, v_c204}, [&](const std::array<u64,4>& m1094) {
              if (!slog::exists_probe<4,3>(evalindex1038, std::array<u64,4>{v_c107, v_c41, v_c86, 0})) return;
              if (!slog::exists_probe<2,2>(eval_ansindex1039, std::array<u64,2>{v_c233, v_c211})) return;
              if (!slog::exists_probe<2,2>(mp_put_ansindex1040, std::array<u64,2>{v_c231, v_c41})) return;
              slog::join_probe<4,3>(letindex1041, std::array<u64,4>{v_c205, v_c204, v_c107, 0}, [&](const std::array<u64,4>& m1095) {
                u64 v_c234 = m1095[3];
                slog::join_probe<4,4>(evalindex1042, std::array<u64,4>{v_c85, v_c86, v_c232, v_c234}, [&](const std::array<u64,4>& m1096) {
                  slog::join_probe<4,3>(evalindex1043, std::array<u64,4>{v_c107, v_c41, v_c86, 0}, [&](const std::array<u64,4>& m1097) {
                    u64 v_c235 = m1097[3];
                    slog::join_probe<2,2>(eval_ansindex1044, std::array<u64,2>{v_c233, v_c211}, [&](const std::array<u64,2>& m1098) {
                      slog::join_probe<2,2>(mp_put_ansindex1045, std::array<u64,2>{v_c231, v_c41}, [&](const std::array<u64,2>& m1099) {
                        slog::join_probe<2,1>(eval_ansindex1046, std::array<u64,2>{v_c235, 0}, [&](const std::array<u64,2>& m1100) {
                          u64 v_c7 = m1100[1];
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c232, v_c7}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:93", "delta:mp_put", _fires);
  
      if (!_done)
      {
        ReadTask1047* _cont = new ReadTask1047(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1047(db,b), false);
  // (crule (pre (let __tconst5cJe186 const4b227777d4dd1fc61c6f884f) (let __tconst0B8U188 const4e07408562bedb8b60ce05c1) (let __tconst1O2C203 const7297d2085ea0adffc396d546) (let __tconst0bgi206 conste29c9c180c6279b0b02abd6a) (let __tconst5diV207 consteb1e33e8a81b697b75855af6) (let __tconst2PAJ212 const624b60c58c9d8bfb6ff1886c) (let __t9JAh208 (lempty))) (once) (body) (head (emit-temp temp2NPt1949 __t9JAh208) (mkstruct num (1 0) __t5VhZ187 __tconst5cJe186) (mkstruct num (1 0) __t5xXk189 __tconst0B8U188) (mkstruct ref (1 0) __t4x55194 __tconst2PAJ212) (mkstruct ref (1 0) __t7M5t197 __tconst0bgi206) (mkstruct ref (1 0) __t4QtG199 __tconst5diV207) (mkstruct primref (1 0) __t0nMB204 __tconst1O2C203)) kcfa.slog:59 #f)
  class ReadTask1101 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[7];
    slog::Index** head_index[7];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2NPt1949");
      head_rel[1] = db->getRelation("num");
      head_rel[2] = db->getRelation("num");
      head_rel[3] = db->getRelation("ref");
      head_rel[4] = db->getRelation("ref");
      head_rel[5] = db->getRelation("ref");
      head_rel[6] = db->getRelation("primref");
  
    }
    ReadTask1101(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c236 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c237 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c238 = v_const7297d2085ea0adffc396d546;
      u64 v_c239 = v_conste29c9c180c6279b0b02abd6a;
      u64 v_c240 = v_consteb1e33e8a81b697b75855af6;
      u64 v_c241 = v_const624b60c58c9d8bfb6ff1886c;
      u64 v_c242 = _prim_lempty(db);
      if (v_c242 == slog_error) { slog::emit_pending_error(db, "kcfa.slog:59"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[7];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
      newbatch[4] = new slog::InsertBatch();
      newbatch[5] = new slog::InsertBatch();
      newbatch[6] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c242});
      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c236}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[2], newbatch[2], std::array<u64,1>{v_c237}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[3], newbatch[3], std::array<u64,1>{v_c241}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[4], newbatch[4], std::array<u64,1>{v_c239}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[5], newbatch[5], std::array<u64,1>{v_c240}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[6], newbatch[6], std::array<u64,1>{v_c238}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
        head_rel[5]->sendBatch(newbatch[5]);
        head_rel[6]->sendBatch(newbatch[6]);
  
      if (_fires) db->bumpFires("kcfa.slog:59", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask1101(db,b), true);
  // (crule (pre (let __tconst27gk1319 constd01925b37634a1a9d24159d8)) (scan mp_del __t8Vuy635 __t1MJL634 k) (body (join _enum (0 1) 2 __t1MJL634 __tconst27gk1319)) (head (emit mp_del_ans (0 1) __t8Vuy635 __t1MJL634)) map.slog:79 #f)
  class ReadTask1103 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex1102;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord1104({0, 1});
      slog::Relation* readrel1105 = db->getRelation("mp_del_ans");
      head_index[0] = readrel1105->getIndex(ord1104, false);
      outer_rel = db->getRelation("mp_del");
      std::vector<u16> ord1106({0, 1});
      slog::Relation* readrel1107 = db->getRelation("_enum");
      _enumindex1102 = readrel1107->getIndex(ord1106, false);
  
    }
    ReadTask1103(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c243 = v_constd01925b37634a1a9d24159d8;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c244 = _t[0];
        u64 v_c245 = _t[1];
        u64 v_c1 = _t[2];
        slog::join_probe<2,2>(_enumindex1102, std::array<u64,2>{v_c245, v_c243}, [&](const std::array<u64,2>& m1108) {
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c244, v_c245}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:79", "delta:mp_del", _fires);
  
      if (!_done)
      {
        ReadTask1103* _cont = new ReadTask1103(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1103(db,b), false);
  // (crule (pre (let __tconst6yBc1412 const0122baa3ac55f1b433944eb1) (let __tconst2fTo4 const06abaa100ecef791ce028c56) (let _00024sqc0dj4865 constd4735e3a265e16eee03f5971) (let _00024sqc32Jr866 const5feceb66ffc86f38d952786c) (let _00024sqc79IH867 const6b86b273ff34fce19d6b804e) (let _00024sqo5fwv868 const5feceb66ffc86f38d952786c) (let _00024sqo41sW869 const6b86b273ff34fce19d6b804e) (let _00024sqo1lCq870 const6b86b273ff34fce19d6b804e) (let _00024sqo4Tlp871 const5feceb66ffc86f38d952786c)) (probe $seq_atr (1 0 2) 1 _00024sqo4Tlp871 __t4CTM7 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo5fwv868 __t4CTM7 _00024seq2) (join $seq_at (1 0 2) 3 _00024sqo41sW869 __t4CTM7 _00024seq2) (join $seq_atr (1 0 2) 3 _00024sqo1lCq870 __t4CTM7 _00024seq2) (exists _enum (1 0) 1 __tconst6yBc1412) (join delta (1 2 0) 2 __tconst2fTo4 _00024seq2 __t9sv95) (join _enum (1 0) 1 __tconst6yBc1412 __t55Md2) (join prim (0 1) 1 __t4CTM7 op) (letp _00024sql5qXm863 (aslst _00024seq2)) (let chk8Ayp1934 (llen _00024sql5qXm863)) (eq _00024sqc0dj4865 chk8Ayp1934) (letp chk1jUY1935 (lref _00024sql5qXm863 _00024sqc32Jr866)) (eq __t4CTM7 chk1jUY1935) (letp chk26Qq1936 (lref _00024sql5qXm863 _00024sqc79IH867)) (eq __t4CTM7 chk26Qq1936)) (head (emit-temp temp16EG1919 __t9sv95) (mkstruct boolval (1 0) __t5Yya3 __t55Md2)) interp.slog:123 #f)
  class ReadTask1116 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex1109;  slog::Index** $seq_atindex1110;  slog::Index** $seq_atrindex1111;  slog::Index** _enumindex1112;  slog::Index** deltaindex1113;  slog::Index** _enumindex1114;  slog::Index** primindex1115;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp16EG1919");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord1117({1, 0, 2});
      slog::Relation* readrel1118 = db->getRelation("$seq_atr");
      driver_index = readrel1118->getIndex(ord1117, true);
      std::vector<u16> ord1119({1, 0, 2});
      slog::Relation* readrel1120 = db->getRelation("$seq_at");
      $seq_atindex1109 = readrel1120->getIndex(ord1119, false);
      std::vector<u16> ord1121({1, 0, 2});
      slog::Relation* readrel1122 = db->getRelation("$seq_at");
      $seq_atindex1110 = readrel1122->getIndex(ord1121, false);
      std::vector<u16> ord1123({1, 0, 2});
      slog::Relation* readrel1124 = db->getRelation("$seq_atr");
      $seq_atrindex1111 = readrel1124->getIndex(ord1123, false);
      std::vector<u16> ord1125({1, 0});
      slog::Relation* readrel1126 = db->getRelation("_enum");
      _enumindex1112 = readrel1126->getIndex(ord1125, false);
      std::vector<u16> ord1127({1, 2, 0});
      slog::Relation* readrel1128 = db->getRelation("delta");
      deltaindex1113 = readrel1128->getIndex(ord1127, false);
      std::vector<u16> ord1129({1, 0});
      slog::Relation* readrel1130 = db->getRelation("_enum");
      _enumindex1114 = readrel1130->getIndex(ord1129, false);
      std::vector<u16> ord1131({0, 1});
      slog::Relation* readrel1132 = db->getRelation("prim");
      primindex1115 = readrel1132->getIndex(ord1131, false);
  
    }
    ReadTask1116(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c186 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c187 = v_const06abaa100ecef791ce028c56;
      u64 v_c188 = v_constd4735e3a265e16eee03f5971;
      u64 v_c189 = v_const5feceb66ffc86f38d952786c;
      u64 v_c190 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c191 = v_const5feceb66ffc86f38d952786c;
      u64 v_c192 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c193 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c194 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c194, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1133) {
        u64 v_c195 = m1133[1];
        u64 v_c73 = m1133[2];
        if (buckethash(v_c195) != bucket) return;
        slog::join_probe<3,3>($seq_atindex1109, std::array<u64,3>{v_c191, v_c195, v_c73}, [&](const std::array<u64,3>& m1134) {
          slog::join_probe<3,3>($seq_atindex1110, std::array<u64,3>{v_c192, v_c195, v_c73}, [&](const std::array<u64,3>& m1135) {
            slog::join_probe<3,3>($seq_atrindex1111, std::array<u64,3>{v_c193, v_c195, v_c73}, [&](const std::array<u64,3>& m1136) {
              if (!slog::exists_probe<2,1>(_enumindex1112, std::array<u64,2>{v_c186, 0})) return;
              slog::join_probe<3,2>(deltaindex1113, std::array<u64,3>{v_c187, v_c73, 0}, [&](const std::array<u64,3>& m1137) {
                u64 v_c197 = m1137[2];
                slog::join_probe<2,1>(_enumindex1114, std::array<u64,2>{v_c186, 0}, [&](const std::array<u64,2>& m1138) {
                  u64 v_c198 = m1138[1];
                  slog::join_probe<2,1>(primindex1115, std::array<u64,2>{v_c195, 0}, [&](const std::array<u64,2>& m1139) {
                    u64 v_c196 = m1139[1];
                    bool ok1140 = true;
                    u64 v_c199 = _prim_aslst(db, v_c73, &ok1140);
                    if (!ok1140) return;
                    u64 v_c246 = _prim_llen(db, v_c199);
                    if (v_c246 == slog_error) { slog::emit_pending_error(db, "interp.slog:123"); return; }
                    if (v_c188 != v_c246) return;
                    bool ok1141 = true;
                    u64 v_c247 = _prim_lref(db, v_c199, v_c189, &ok1141);
                    if (!ok1141) return;
                    if (v_c195 != v_c247) return;
                    bool ok1142 = true;
                    u64 v_c248 = _prim_lref(db, v_c199, v_c190, &ok1142);
                    if (!ok1142) return;
                    if (v_c195 != v_c248) return;
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c197});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c198}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:123", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask1116* _cont = new ReadTask1116(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1116(db,b), false);
  // (crule (pre) (scan mbranch __t1ouF694 p m l r) (body (exists mp_join (1 2 3 4 0) 2 p __t1ouF694) (exists mp_union (1 2 0) 1 __t1ouF694) (exists mp_msk (2 0 1) 1 m) (join $sup5638x101x0x0x0 (1 2 4 6 7 5 0 3 8 9 10) 5 l m p r __t1ouF694 q __t5awj693 n __t1a8C695 u v) (cmp lt n m) (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) q n u v __t1a8C695) (exists mp_union (0 1 2) 3 __t5awj693 __t1ouF694 __t1a8C695) (exists mp_msk (1 2 0) 2 q m) (join-old mp_join (1 2 3 4 0) 4 (1 2 3 4 0) p __t1ouF694 q __t1a8C695 __t8BsD696) (join mp_union (0 1 2) 3 __t5awj693 __t1ouF694 __t1a8C695) (exists mp_join_ans (0 1) 1 __t8BsD696) (join-old mp_msk (1 2 0) 2 (1 2 0) q m __t84wf697) (join mp_msk_ans (0 1) 1 __t84wf697 __v0) (neq p __v0) (join mp_join_ans (0 1) 1 __t8BsD696 res)) (head (emit mp_union_ans (0 1) __t5awj693 res)) map.slog:102 #f)
  class ReadTask1159 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_joinindex1143;  slog::Index** mp_unionindex1144;  slog::Index** mp_mskindex1145;  slog::Index** $sup5638x101x0x0x0index1146;  slog::Index** mbranchindex1147;  slog::Index** mp_unionindex1148;  slog::Index** mp_mskindex1149;  slog::Index** mp_joinindex1150;  slog::Index** mp_unionindex1151;  slog::Index** mp_join_ansindex1152;  slog::Index** mp_mskindex1153;  slog::Index** mp_msk_ansindex1154;  slog::Index** mp_join_ansindex1155;  slog::Index** mbranchdelta1156;  slog::Index** mp_joindelta1157;  slog::Index** mp_mskdelta1158;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord1160({0, 1});
      slog::Relation* readrel1161 = db->getRelation("mp_union_ans");
      head_index[0] = readrel1161->getIndex(ord1160, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord1162({1, 2, 3, 4, 0});
      slog::Relation* readrel1163 = db->getRelation("mp_join");
      mp_joinindex1143 = readrel1163->getIndex(ord1162, false);
      std::vector<u16> ord1164({1, 2, 0});
      slog::Relation* readrel1165 = db->getRelation("mp_union");
      mp_unionindex1144 = readrel1165->getIndex(ord1164, false);
      std::vector<u16> ord1166({2, 0, 1});
      slog::Relation* readrel1167 = db->getRelation("mp_msk");
      mp_mskindex1145 = readrel1167->getIndex(ord1166, false);
      std::vector<u16> ord1168({1, 2, 4, 6, 7, 5, 0, 3, 8, 9, 10});
      slog::Relation* readrel1169 = db->getRelation("$sup5638x101x0x0x0");
      $sup5638x101x0x0x0index1146 = readrel1169->getIndex(ord1168, false);
      std::vector<u16> ord1170({1, 2, 3, 4, 0});
      slog::Relation* readrel1171 = db->getRelation("mbranch");
      mbranchindex1147 = readrel1171->getIndex(ord1170, false);
      std::vector<u16> ord1172({1, 2, 3, 4, 0});
      slog::Relation* readrel1173 = db->getRelation("mbranch");
      mbranchdelta1156 = readrel1173->getIndex(ord1172, true);
      std::vector<u16> ord1174({0, 1, 2});
      slog::Relation* readrel1175 = db->getRelation("mp_union");
      mp_unionindex1148 = readrel1175->getIndex(ord1174, false);
      std::vector<u16> ord1176({1, 2, 0});
      slog::Relation* readrel1177 = db->getRelation("mp_msk");
      mp_mskindex1149 = readrel1177->getIndex(ord1176, false);
      std::vector<u16> ord1178({1, 2, 3, 4, 0});
      slog::Relation* readrel1179 = db->getRelation("mp_join");
      mp_joinindex1150 = readrel1179->getIndex(ord1178, false);
      std::vector<u16> ord1180({1, 2, 3, 4, 0});
      slog::Relation* readrel1181 = db->getRelation("mp_join");
      mp_joindelta1157 = readrel1181->getIndex(ord1180, true);
      std::vector<u16> ord1182({0, 1, 2});
      slog::Relation* readrel1183 = db->getRelation("mp_union");
      mp_unionindex1151 = readrel1183->getIndex(ord1182, false);
      std::vector<u16> ord1184({0, 1});
      slog::Relation* readrel1185 = db->getRelation("mp_join_ans");
      mp_join_ansindex1152 = readrel1185->getIndex(ord1184, false);
      std::vector<u16> ord1186({1, 2, 0});
      slog::Relation* readrel1187 = db->getRelation("mp_msk");
      mp_mskindex1153 = readrel1187->getIndex(ord1186, false);
      std::vector<u16> ord1188({1, 2, 0});
      slog::Relation* readrel1189 = db->getRelation("mp_msk");
      mp_mskdelta1158 = readrel1189->getIndex(ord1188, true);
      std::vector<u16> ord1190({0, 1});
      slog::Relation* readrel1191 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1154 = readrel1191->getIndex(ord1190, false);
      std::vector<u16> ord1192({0, 1});
      slog::Relation* readrel1193 = db->getRelation("mp_join_ans");
      mp_join_ansindex1155 = readrel1193->getIndex(ord1192, false);
  
    }
    ReadTask1159(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c249 = _t[0];
        u64 v_c3 = _t[1];
        u64 v_c2 = _t[2];
        u64 v_c5 = _t[3];
        u64 v_c6 = _t[4];
        if (!slog::exists_probe<5,2>(mp_joinindex1143, std::array<u64,5>{v_c3, v_c249, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex1144, std::array<u64,3>{v_c249, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex1145, std::array<u64,3>{v_c2, 0, 0})) return;
        slog::join_probe<11,5>($sup5638x101x0x0x0index1146, std::array<u64,11>{v_c5, v_c2, v_c3, v_c6, v_c249, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m1194) {
          u64 v_c62 = m1194[5]; u64 v_c250 = m1194[6]; u64 v_c63 = m1194[7]; u64 v_c251 = m1194[8]; u64 v_c60 = m1194[9]; u64 v_c7 = m1194[10];
          u64 v_c252 = _prim_lt(db, v_c63, v_c2);
          if (v_c252 == slog_error) { slog::emit_pending_error(db, "map.slog:102"); return; }
          if (!v_c252) return;
          slog::join_probe_old<5,5>(mbranchindex1147, mbranchdelta1156, std::array<u64,5>{v_c62, v_c63, v_c60, v_c7, v_c251}, [&](const std::array<u64,5>& m1196) {
            if (!slog::exists_probe<3,3>(mp_unionindex1148, std::array<u64,3>{v_c250, v_c249, v_c251})) return;
            if (!slog::exists_probe<3,2>(mp_mskindex1149, std::array<u64,3>{v_c62, v_c2, 0})) return;
            slog::join_probe_old<5,4>(mp_joinindex1150, mp_joindelta1157, std::array<u64,5>{v_c3, v_c249, v_c62, v_c251, 0}, [&](const std::array<u64,5>& m1197) {
              u64 v_c253 = m1197[4];
              slog::join_probe<3,3>(mp_unionindex1151, std::array<u64,3>{v_c250, v_c249, v_c251}, [&](const std::array<u64,3>& m1198) {
                if (!slog::exists_probe<2,1>(mp_join_ansindex1152, std::array<u64,2>{v_c253, 0})) return;
                slog::join_probe_old<3,2>(mp_mskindex1153, mp_mskdelta1158, std::array<u64,3>{v_c62, v_c2, 0}, [&](const std::array<u64,3>& m1199) {
                  u64 v_c254 = m1199[2];
                  slog::join_probe<2,1>(mp_msk_ansindex1154, std::array<u64,2>{v_c254, 0}, [&](const std::array<u64,2>& m1200) {
                    u64 v_c41 = m1200[1];
                    if (v_c3 == v_c41) return;
                    slog::join_probe<2,1>(mp_join_ansindex1155, std::array<u64,2>{v_c253, 0}, [&](const std::array<u64,2>& m1201) {
                      u64 v_c46 = m1201[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c250, v_c46}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:102", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask1159* _cont = new ReadTask1159(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1159(db,b), false);
  // (crule (pre) (scan $sup5638x25x0x0x0 __d0 p0 p1 t0 t1) (body (let __t252g323 (bxor p0 p1))) (head (emit-temp temp6Noe1976 __t252g323)) map.slog:26 #f)
  class ReadTask1202 : public slog::Task
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
      head_rel[0] = db->getRelation("temp6Noe1976");
      outer_rel = db->getRelation("$sup5638x25x0x0x0");
  
    }
    ReadTask1202(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c4 = _t[0];
        u64 v_c255 = _t[1];
        u64 v_c256 = _t[2];
        u64 v_c257 = _t[3];
        u64 v_c258 = _t[4];
        u64 v_c259 = _prim_bxor(db, v_c255, v_c256);
        if (v_c259 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c259});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:26", "delta:$sup5638x25x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1202* _cont = new ReadTask1202(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1202(db,b), false);
  // (crule (pre) (scan nan_result __erre3RD51756 __errf7vRk1757 __errf2xVu1758 __errf0LXs1759) (body) (head (emit error (0) __erre3RD51756)) <internal>:1 #f)
  class ReadTask1203 : public slog::Task
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
      std::vector<u16> ord1204({0});
      slog::Relation* readrel1205 = db->getRelation("error");
      head_index[0] = readrel1205->getIndex(ord1204, false);
      outer_rel = db->getRelation("nan_result");
  
    }
    ReadTask1203(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c260 = _t[0];
        u64 v_c261 = _t[1];
        u64 v_c262 = _t[2];
        u64 v_c263 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c260}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:nan_result", _fires);
  
      if (!_done)
      {
        ReadTask1203* _cont = new ReadTask1203(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1203(db,b), false);
  // (crule (pre) (scan eval_args_ans __t2srV536 vs) (body (exists $sup70016x51x0x0x1 (2 11 0 1 3 4 5 6 7 8 9 10 12) 2 __t2srV536 vs) (join-old eval_args (0 1 2 3) 1 (0 1 2 3) __t2srV536 es rho t) (exists $sup70016x51x0x0x1 (2 6 7 9 11 0 1 3 4 5 8 10 12) 5 __t2srV536 es rho t vs) (exists eval (2 3 0 1) 2 rho t) (exists app (2 0 1) 1 es) (exists tick (2 0 1) 1 t) (join-old $sup70016x51x0x0x0 (2 3 4 0 1) 3 (2 3 4 0 1) es rho t __t2z6s532 ef) (exists eval (1 2 3 0) 3 ef rho t) (exists eval (2 3 0 1) 3 rho t __t2z6s532) (exists app (1 2 0) 2 ef es) (join-old $sup70016x51x0x0x1 (0 2 5 6 7 9 11 1 3 4 8 10 12) 7 (0 2 5 6 7 9 11 1 3 4 8 10 12) __t2z6s532 __t2srV536 ef es rho t vs __t5qy8533 __t0CD9539 eb rhoc t2 xs) (join-old eval (2 3 0 1) 4 (2 3 0 1) rho t __t5qy8533 ef) (exists tick (0 2 1) 2 __t0CD9539 t) (exists extend_env (1 2 3 0) 3 rhoc xs t2) (exists tick_ans (0 1) 2 __t0CD9539 t2) (exists lambda (1 2 0) 2 xs eb) (exists closure (2 0 1) 1 rhoc) (exists eval_ans (0 1) 1 __t5qy8533) (exists eval (3 1 0 2) 2 t2 eb) (join-old eval (2 3 0 1) 3 (2 3 0 1) rho t __t2z6s532 __t5a7h538) (join-old app (0 1 2) 3 (0 1 2) __t5a7h538 ef es) (join-old tick (0 2 1) 3 (0 2 1) __t0CD9539 t __t5a7h538) (join-old extend_env (1 2 3 0) 3 (1 2 3 0) rhoc xs t2 __t5fzh540) (join-old tick_ans (0 1) 2 (0 1) __t0CD9539 t2) (exists extend_env_ans (0 1) 1 __t5fzh540) (join-old lambda (1 2 0) 2 (1 2 0) xs eb __t6iPm534) (join-old closure (1 2 0) 2 (1 2 0) __t6iPm534 rhoc __t9dfl535) (join eval_ans (0 1) 2 __t5qy8533 __t9dfl535) (join-old eval (3 1 0 2) 2 (3 1 0 2) t2 eb __t7TaT537 __v0) (join-old extend_env_ans (0 1) 2 (0 1) __t5fzh540 __v0) (join-old eval_ans (0 1) 1 (0 1) __t7TaT537 v)) (head (emit eval_ans (0 1) __t2z6s532 v)) interp.slog:52 #f)
  class ReadTask1251 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup70016x51x0x0x1index1206;  slog::Index** eval_argsindex1207;  slog::Index** $sup70016x51x0x0x1index1208;  slog::Index** evalindex1209;  slog::Index** appindex1210;  slog::Index** tickindex1211;  slog::Index** $sup70016x51x0x0x0index1212;  slog::Index** evalindex1213;  slog::Index** evalindex1214;  slog::Index** appindex1215;  slog::Index** $sup70016x51x0x0x1index1216;  slog::Index** evalindex1217;  slog::Index** tickindex1218;  slog::Index** extend_envindex1219;  slog::Index** tick_ansindex1220;  slog::Index** lambdaindex1221;  slog::Index** closureindex1222;  slog::Index** eval_ansindex1223;  slog::Index** evalindex1224;  slog::Index** evalindex1225;  slog::Index** appindex1226;  slog::Index** tickindex1227;  slog::Index** extend_envindex1228;  slog::Index** tick_ansindex1229;  slog::Index** extend_env_ansindex1230;  slog::Index** lambdaindex1231;  slog::Index** closureindex1232;  slog::Index** eval_ansindex1233;  slog::Index** evalindex1234;  slog::Index** extend_env_ansindex1235;  slog::Index** eval_ansindex1236;  slog::Index** eval_argsdelta1237;  slog::Index** $sup70016x51x0x0x0delta1238;  slog::Index** $sup70016x51x0x0x1delta1239;  slog::Index** evaldelta1240;  slog::Index** evaldelta1241;  slog::Index** appdelta1242;  slog::Index** tickdelta1243;  slog::Index** extend_envdelta1244;  slog::Index** tick_ansdelta1245;  slog::Index** lambdadelta1246;  slog::Index** closuredelta1247;  slog::Index** evaldelta1248;  slog::Index** extend_env_ansdelta1249;  slog::Index** eval_ansdelta1250;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1252({0, 1});
      slog::Relation* readrel1253 = db->getRelation("eval_ans");
      head_index[0] = readrel1253->getIndex(ord1252, false);
      outer_rel = db->getRelation("eval_args_ans");
      std::vector<u16> ord1254({2, 11, 0, 1, 3, 4, 5, 6, 7, 8, 9, 10, 12});
      slog::Relation* readrel1255 = db->getRelation("$sup70016x51x0x0x1");
      $sup70016x51x0x0x1index1206 = readrel1255->getIndex(ord1254, false);
      std::vector<u16> ord1256({0, 1, 2, 3});
      slog::Relation* readrel1257 = db->getRelation("eval_args");
      eval_argsindex1207 = readrel1257->getIndex(ord1256, false);
      std::vector<u16> ord1258({0, 1, 2, 3});
      slog::Relation* readrel1259 = db->getRelation("eval_args");
      eval_argsdelta1237 = readrel1259->getIndex(ord1258, true);
      std::vector<u16> ord1260({2, 6, 7, 9, 11, 0, 1, 3, 4, 5, 8, 10, 12});
      slog::Relation* readrel1261 = db->getRelation("$sup70016x51x0x0x1");
      $sup70016x51x0x0x1index1208 = readrel1261->getIndex(ord1260, false);
      std::vector<u16> ord1262({2, 3, 0, 1});
      slog::Relation* readrel1263 = db->getRelation("eval");
      evalindex1209 = readrel1263->getIndex(ord1262, false);
      std::vector<u16> ord1264({2, 0, 1});
      slog::Relation* readrel1265 = db->getRelation("app");
      appindex1210 = readrel1265->getIndex(ord1264, false);
      std::vector<u16> ord1266({2, 0, 1});
      slog::Relation* readrel1267 = db->getRelation("tick");
      tickindex1211 = readrel1267->getIndex(ord1266, false);
      std::vector<u16> ord1268({2, 3, 4, 0, 1});
      slog::Relation* readrel1269 = db->getRelation("$sup70016x51x0x0x0");
      $sup70016x51x0x0x0index1212 = readrel1269->getIndex(ord1268, false);
      std::vector<u16> ord1270({2, 3, 4, 0, 1});
      slog::Relation* readrel1271 = db->getRelation("$sup70016x51x0x0x0");
      $sup70016x51x0x0x0delta1238 = readrel1271->getIndex(ord1270, true);
      std::vector<u16> ord1272({1, 2, 3, 0});
      slog::Relation* readrel1273 = db->getRelation("eval");
      evalindex1213 = readrel1273->getIndex(ord1272, false);
      std::vector<u16> ord1274({2, 3, 0, 1});
      slog::Relation* readrel1275 = db->getRelation("eval");
      evalindex1214 = readrel1275->getIndex(ord1274, false);
      std::vector<u16> ord1276({1, 2, 0});
      slog::Relation* readrel1277 = db->getRelation("app");
      appindex1215 = readrel1277->getIndex(ord1276, false);
      std::vector<u16> ord1278({0, 2, 5, 6, 7, 9, 11, 1, 3, 4, 8, 10, 12});
      slog::Relation* readrel1279 = db->getRelation("$sup70016x51x0x0x1");
      $sup70016x51x0x0x1index1216 = readrel1279->getIndex(ord1278, false);
      std::vector<u16> ord1280({0, 2, 5, 6, 7, 9, 11, 1, 3, 4, 8, 10, 12});
      slog::Relation* readrel1281 = db->getRelation("$sup70016x51x0x0x1");
      $sup70016x51x0x0x1delta1239 = readrel1281->getIndex(ord1280, true);
      std::vector<u16> ord1282({2, 3, 0, 1});
      slog::Relation* readrel1283 = db->getRelation("eval");
      evalindex1217 = readrel1283->getIndex(ord1282, false);
      std::vector<u16> ord1284({2, 3, 0, 1});
      slog::Relation* readrel1285 = db->getRelation("eval");
      evaldelta1240 = readrel1285->getIndex(ord1284, true);
      std::vector<u16> ord1286({0, 2, 1});
      slog::Relation* readrel1287 = db->getRelation("tick");
      tickindex1218 = readrel1287->getIndex(ord1286, false);
      std::vector<u16> ord1288({1, 2, 3, 0});
      slog::Relation* readrel1289 = db->getRelation("extend_env");
      extend_envindex1219 = readrel1289->getIndex(ord1288, false);
      std::vector<u16> ord1290({0, 1});
      slog::Relation* readrel1291 = db->getRelation("tick_ans");
      tick_ansindex1220 = readrel1291->getIndex(ord1290, false);
      std::vector<u16> ord1292({1, 2, 0});
      slog::Relation* readrel1293 = db->getRelation("lambda");
      lambdaindex1221 = readrel1293->getIndex(ord1292, false);
      std::vector<u16> ord1294({2, 0, 1});
      slog::Relation* readrel1295 = db->getRelation("closure");
      closureindex1222 = readrel1295->getIndex(ord1294, false);
      std::vector<u16> ord1296({0, 1});
      slog::Relation* readrel1297 = db->getRelation("eval_ans");
      eval_ansindex1223 = readrel1297->getIndex(ord1296, false);
      std::vector<u16> ord1298({3, 1, 0, 2});
      slog::Relation* readrel1299 = db->getRelation("eval");
      evalindex1224 = readrel1299->getIndex(ord1298, false);
      std::vector<u16> ord1300({2, 3, 0, 1});
      slog::Relation* readrel1301 = db->getRelation("eval");
      evalindex1225 = readrel1301->getIndex(ord1300, false);
      std::vector<u16> ord1302({2, 3, 0, 1});
      slog::Relation* readrel1303 = db->getRelation("eval");
      evaldelta1241 = readrel1303->getIndex(ord1302, true);
      std::vector<u16> ord1304({0, 1, 2});
      slog::Relation* readrel1305 = db->getRelation("app");
      appindex1226 = readrel1305->getIndex(ord1304, false);
      std::vector<u16> ord1306({0, 1, 2});
      slog::Relation* readrel1307 = db->getRelation("app");
      appdelta1242 = readrel1307->getIndex(ord1306, true);
      std::vector<u16> ord1308({0, 2, 1});
      slog::Relation* readrel1309 = db->getRelation("tick");
      tickindex1227 = readrel1309->getIndex(ord1308, false);
      std::vector<u16> ord1310({0, 2, 1});
      slog::Relation* readrel1311 = db->getRelation("tick");
      tickdelta1243 = readrel1311->getIndex(ord1310, true);
      std::vector<u16> ord1312({1, 2, 3, 0});
      slog::Relation* readrel1313 = db->getRelation("extend_env");
      extend_envindex1228 = readrel1313->getIndex(ord1312, false);
      std::vector<u16> ord1314({1, 2, 3, 0});
      slog::Relation* readrel1315 = db->getRelation("extend_env");
      extend_envdelta1244 = readrel1315->getIndex(ord1314, true);
      std::vector<u16> ord1316({0, 1});
      slog::Relation* readrel1317 = db->getRelation("tick_ans");
      tick_ansindex1229 = readrel1317->getIndex(ord1316, false);
      std::vector<u16> ord1318({0, 1});
      slog::Relation* readrel1319 = db->getRelation("tick_ans");
      tick_ansdelta1245 = readrel1319->getIndex(ord1318, true);
      std::vector<u16> ord1320({0, 1});
      slog::Relation* readrel1321 = db->getRelation("extend_env_ans");
      extend_env_ansindex1230 = readrel1321->getIndex(ord1320, false);
      std::vector<u16> ord1322({1, 2, 0});
      slog::Relation* readrel1323 = db->getRelation("lambda");
      lambdaindex1231 = readrel1323->getIndex(ord1322, false);
      std::vector<u16> ord1324({1, 2, 0});
      slog::Relation* readrel1325 = db->getRelation("lambda");
      lambdadelta1246 = readrel1325->getIndex(ord1324, true);
      std::vector<u16> ord1326({1, 2, 0});
      slog::Relation* readrel1327 = db->getRelation("closure");
      closureindex1232 = readrel1327->getIndex(ord1326, false);
      std::vector<u16> ord1328({1, 2, 0});
      slog::Relation* readrel1329 = db->getRelation("closure");
      closuredelta1247 = readrel1329->getIndex(ord1328, true);
      std::vector<u16> ord1330({0, 1});
      slog::Relation* readrel1331 = db->getRelation("eval_ans");
      eval_ansindex1233 = readrel1331->getIndex(ord1330, false);
      std::vector<u16> ord1332({3, 1, 0, 2});
      slog::Relation* readrel1333 = db->getRelation("eval");
      evalindex1234 = readrel1333->getIndex(ord1332, false);
      std::vector<u16> ord1334({3, 1, 0, 2});
      slog::Relation* readrel1335 = db->getRelation("eval");
      evaldelta1248 = readrel1335->getIndex(ord1334, true);
      std::vector<u16> ord1336({0, 1});
      slog::Relation* readrel1337 = db->getRelation("extend_env_ans");
      extend_env_ansindex1235 = readrel1337->getIndex(ord1336, false);
      std::vector<u16> ord1338({0, 1});
      slog::Relation* readrel1339 = db->getRelation("extend_env_ans");
      extend_env_ansdelta1249 = readrel1339->getIndex(ord1338, true);
      std::vector<u16> ord1340({0, 1});
      slog::Relation* readrel1341 = db->getRelation("eval_ans");
      eval_ansindex1236 = readrel1341->getIndex(ord1340, false);
      std::vector<u16> ord1342({0, 1});
      slog::Relation* readrel1343 = db->getRelation("eval_ans");
      eval_ansdelta1250 = readrel1343->getIndex(ord1342, true);
  
    }
    ReadTask1251(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c264 = _t[0];
        u64 v_c103 = _t[1];
        if (!slog::exists_probe<13,2>($sup70016x51x0x0x1index1206, std::array<u64,13>{v_c264, v_c103, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<4,1>(eval_argsindex1207, eval_argsdelta1237, std::array<u64,4>{v_c264, 0, 0, 0}, [&](const std::array<u64,4>& m1344) {
          u64 v_c99 = m1344[1]; u64 v_c85 = m1344[2]; u64 v_c86 = m1344[3];
          if (!slog::exists_probe<13,5>($sup70016x51x0x0x1index1208, std::array<u64,13>{v_c264, v_c99, v_c85, v_c86, v_c103, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<4,2>(evalindex1209, std::array<u64,4>{v_c85, v_c86, 0, 0})) return;
          if (!slog::exists_probe<3,1>(appindex1210, std::array<u64,3>{v_c99, 0, 0})) return;
          if (!slog::exists_probe<3,1>(tickindex1211, std::array<u64,3>{v_c86, 0, 0})) return;
          slog::join_probe_old<5,3>($sup70016x51x0x0x0index1212, $sup70016x51x0x0x0delta1238, std::array<u64,5>{v_c99, v_c85, v_c86, 0, 0}, [&](const std::array<u64,5>& m1345) {
            u64 v_c265 = m1345[3]; u64 v_c98 = m1345[4];
            if (!slog::exists_probe<4,3>(evalindex1213, std::array<u64,4>{v_c98, v_c85, v_c86, 0})) return;
            if (!slog::exists_probe<4,3>(evalindex1214, std::array<u64,4>{v_c85, v_c86, v_c265, 0})) return;
            if (!slog::exists_probe<3,2>(appindex1215, std::array<u64,3>{v_c98, v_c99, 0})) return;
            slog::join_probe_old<13,7>($sup70016x51x0x0x1index1216, $sup70016x51x0x0x1delta1239, std::array<u64,13>{v_c265, v_c264, v_c98, v_c99, v_c85, v_c86, v_c103, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,13>& m1346) {
              u64 v_c266 = m1346[7]; u64 v_c267 = m1346[8]; u64 v_c107 = m1346[9]; u64 v_c105 = m1346[10]; u64 v_c96 = m1346[11]; u64 v_c106 = m1346[12];
              slog::join_probe_old<4,4>(evalindex1217, evaldelta1240, std::array<u64,4>{v_c85, v_c86, v_c266, v_c98}, [&](const std::array<u64,4>& m1347) {
                if (!slog::exists_probe<3,2>(tickindex1218, std::array<u64,3>{v_c267, v_c86, 0})) return;
                if (!slog::exists_probe<4,3>(extend_envindex1219, std::array<u64,4>{v_c105, v_c106, v_c96, 0})) return;
                if (!slog::exists_probe<2,2>(tick_ansindex1220, std::array<u64,2>{v_c267, v_c96})) return;
                if (!slog::exists_probe<3,2>(lambdaindex1221, std::array<u64,3>{v_c106, v_c107, 0})) return;
                if (!slog::exists_probe<3,1>(closureindex1222, std::array<u64,3>{v_c105, 0, 0})) return;
                if (!slog::exists_probe<2,1>(eval_ansindex1223, std::array<u64,2>{v_c266, 0})) return;
                if (!slog::exists_probe<4,2>(evalindex1224, std::array<u64,4>{v_c96, v_c107, 0, 0})) return;
                slog::join_probe_old<4,3>(evalindex1225, evaldelta1241, std::array<u64,4>{v_c85, v_c86, v_c265, 0}, [&](const std::array<u64,4>& m1348) {
                  u64 v_c268 = m1348[3];
                  slog::join_probe_old<3,3>(appindex1226, appdelta1242, std::array<u64,3>{v_c268, v_c98, v_c99}, [&](const std::array<u64,3>& m1349) {
                    slog::join_probe_old<3,3>(tickindex1227, tickdelta1243, std::array<u64,3>{v_c267, v_c86, v_c268}, [&](const std::array<u64,3>& m1350) {
                      slog::join_probe_old<4,3>(extend_envindex1228, extend_envdelta1244, std::array<u64,4>{v_c105, v_c106, v_c96, 0}, [&](const std::array<u64,4>& m1351) {
                        u64 v_c269 = m1351[3];
                        slog::join_probe_old<2,2>(tick_ansindex1229, tick_ansdelta1245, std::array<u64,2>{v_c267, v_c96}, [&](const std::array<u64,2>& m1352) {
                          if (!slog::exists_probe<2,1>(extend_env_ansindex1230, std::array<u64,2>{v_c269, 0})) return;
                          slog::join_probe_old<3,2>(lambdaindex1231, lambdadelta1246, std::array<u64,3>{v_c106, v_c107, 0}, [&](const std::array<u64,3>& m1353) {
                            u64 v_c270 = m1353[2];
                            slog::join_probe_old<3,2>(closureindex1232, closuredelta1247, std::array<u64,3>{v_c270, v_c105, 0}, [&](const std::array<u64,3>& m1354) {
                              u64 v_c271 = m1354[2];
                              slog::join_probe<2,2>(eval_ansindex1233, std::array<u64,2>{v_c266, v_c271}, [&](const std::array<u64,2>& m1355) {
                                slog::join_probe_old<4,2>(evalindex1234, evaldelta1248, std::array<u64,4>{v_c96, v_c107, 0, 0}, [&](const std::array<u64,4>& m1356) {
                                  u64 v_c272 = m1356[2]; u64 v_c41 = m1356[3];
                                  slog::join_probe_old<2,2>(extend_env_ansindex1235, extend_env_ansdelta1249, std::array<u64,2>{v_c269, v_c41}, [&](const std::array<u64,2>& m1357) {
                                    slog::join_probe_old<2,1>(eval_ansindex1236, eval_ansdelta1250, std::array<u64,2>{v_c272, 0}, [&](const std::array<u64,2>& m1358) {
                                      u64 v_c7 = m1358[1];
                                      ++_fires;
                                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c265, v_c7}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:52", "delta:eval_args_ans", _fires);
  
      if (!_done)
      {
        ReadTask1251* _cont = new ReadTask1251(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1251(db,b), false);
  // (crule (pre (let __trid0c5B1149 const3b5b774db59f55c2fdaef73a) (let __trel7L961150 constdd7bbf31ce5f578b9805e840) (let __tcol6ewS1151 const5feceb66ffc86f38d952786c) (let __trel3SYq1152 constdd7bbf31ce5f578b9805e840) (let __tcol5yOd1153 const6b86b273ff34fce19d6b804e)) (scan $sup5638x62x0x0x0 __d0 k l m p r) (body) (head (tycheck k (accept int) __trid0c5B1149 __trel7L961150 __tcol6ewS1151 (1 2 3 4 0)) (tycheck m (accept int) __trid0c5B1149 __trel3SYq1152 __tcol5yOd1153 (1 2 3 4 0)) (mkstruct mp_msk (1 2 0) __49SU1148 k m)) map.slog:63 #f)
  class ReadTask1359 : public slog::Task
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
      outer_rel = db->getRelation("$sup5638x62x0x0x0");
  
    }
    ReadTask1359(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c273 = v_const3b5b774db59f55c2fdaef73a;
      u64 v_c274 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c275 = v_const5feceb66ffc86f38d952786c;
      u64 v_c276 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c277 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c4 = _t[0];
        u64 v_c1 = _t[1];
        u64 v_c5 = _t[2];
        u64 v_c2 = _t[3];
        u64 v_c3 = _t[4];
        u64 v_c6 = _t[5];
        ++_fires;
        if (!(is_int(v_c1)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c273, v_c274, v_c275, v_c1}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c2)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c273, v_c276, v_c277, v_c2}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c1, v_c2}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:63", "delta:$sup5638x62x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1359* _cont = new ReadTask1359(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1359(db,b), false);
  // (crule (pre (let __tconst0SLc45 const06abaa100ecef791ce028c56) (let __tconst2JmK55 conste7f6c011776e8db7cd330b54) (let __tconst7dEi64 constef2d127de37b942baad06145) (let __tconst9TOB66 const955cca1ceba45052d85984d3) (let __tconst6c7T73 const4b227777d4dd1fc61c6f884f) (let __tconst2wMu75 const798640599597df7a8daa32b1) (let __tconst56qw82 const4e07408562bedb8b60ce05c1) (let __tconst4buE86 constd4735e3a265e16eee03f5971) (let __tconst2aC790 const6b86b273ff34fce19d6b804e) (let __tconst5MNq94 const5feceb66ffc86f38d952786c) (let __t9eMP91 (lempty))) (once) (body) (head (emit-temp temp5W9V1981 __t9eMP91) (mkstruct ref (1 0) __t4U6j39 __tconst2JmK55) (mkstruct ref (1 0) __t5HCy41 __tconst7dEi64) (mkstruct primref (1 0) __t0d6446 __tconst0SLc45) (mkstruct num (1 0) __t7V3849 __tconst5MNq94) (mkstruct ref (1 0) __t5Ugf53 __tconst6c7T73) (mkstruct ref (1 0) __t7Sy862 __tconst56qw82) (mkstruct sym (1 0) __t8BGj67 __tconst9TOB66) (mkstruct ref (1 0) __t0g1Q71 __tconst5MNq94) (mkstruct sym (1 0) __t5BQT76 __tconst2wMu75) (mkstruct ref (1 0) __t6rYz85 __tconst2aC790)) kcfa.slog:16 #f)
  class ReadTask1360 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[11];
    slog::Index** head_index[11];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5W9V1981");
      head_rel[1] = db->getRelation("ref");
      head_rel[2] = db->getRelation("ref");
      head_rel[3] = db->getRelation("primref");
      head_rel[4] = db->getRelation("num");
      head_rel[5] = db->getRelation("ref");
      head_rel[6] = db->getRelation("ref");
      head_rel[7] = db->getRelation("sym");
      head_rel[8] = db->getRelation("ref");
      head_rel[9] = db->getRelation("sym");
      head_rel[10] = db->getRelation("ref");
  
    }
    ReadTask1360(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c278 = v_const06abaa100ecef791ce028c56;
      u64 v_c279 = v_conste7f6c011776e8db7cd330b54;
      u64 v_c280 = v_constef2d127de37b942baad06145;
      u64 v_c281 = v_const955cca1ceba45052d85984d3;
      u64 v_c282 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c283 = v_const798640599597df7a8daa32b1;
      u64 v_c284 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c285 = v_constd4735e3a265e16eee03f5971;
      u64 v_c286 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c287 = v_const5feceb66ffc86f38d952786c;
      u64 v_c288 = _prim_lempty(db);
      if (v_c288 == slog_error) { slog::emit_pending_error(db, "kcfa.slog:16"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[11];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
      newbatch[4] = new slog::InsertBatch();
      newbatch[5] = new slog::InsertBatch();
      newbatch[6] = new slog::InsertBatch();
      newbatch[7] = new slog::InsertBatch();
      newbatch[8] = new slog::InsertBatch();
      newbatch[9] = new slog::InsertBatch();
      newbatch[10] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c288});
      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c279}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[2], newbatch[2], std::array<u64,1>{v_c280}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[3], newbatch[3], std::array<u64,1>{v_c278}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[4], newbatch[4], std::array<u64,1>{v_c287}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[5], newbatch[5], std::array<u64,1>{v_c282}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[6], newbatch[6], std::array<u64,1>{v_c284}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[7], newbatch[7], std::array<u64,1>{v_c281}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[8], newbatch[8], std::array<u64,1>{v_c287}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[9], newbatch[9], std::array<u64,1>{v_c283}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[10], newbatch[10], std::array<u64,1>{v_c286}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
        head_rel[5]->sendBatch(newbatch[5]);
        head_rel[6]->sendBatch(newbatch[6]);
        head_rel[7]->sendBatch(newbatch[7]);
        head_rel[8]->sendBatch(newbatch[8]);
        head_rel[9]->sendBatch(newbatch[9]);
        head_rel[10]->sendBatch(newbatch[10]);
  
      if (_fires) db->bumpFires("kcfa.slog:16", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask1360(db,b), true);
  // (crule (pre) (scan temp8M8t2030 ef es t) (body (join app (1 2 0) 2 ef es __t2e2U253)) (head (mkstruct tick (1 2 0) __5Isa1305 __t2e2U253 t)) interp.slog:52 #f)
  class ReadTask1362 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex1361;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("tick");
      outer_rel = db->getRelation("temp8M8t2030");
      std::vector<u16> ord1363({1, 2, 0});
      slog::Relation* readrel1364 = db->getRelation("app");
      appindex1361 = readrel1364->getIndex(ord1363, false);
  
    }
    ReadTask1362(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c98 = _t[0];
        u64 v_c99 = _t[1];
        u64 v_c86 = _t[2];
        slog::join_probe<3,2>(appindex1361, std::array<u64,3>{v_c98, v_c99, 0}, [&](const std::array<u64,3>& m1365) {
          u64 v_c289 = m1365[2];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c289, v_c86}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:52", "delta:temp8M8t2030", _fires);
  
      if (!_done)
      {
        ReadTask1362* _cont = new ReadTask1362(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1362(db,b), false);
}

