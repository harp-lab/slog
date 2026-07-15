
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const1d9eff40314d54862fee3942;
extern u64 v_const1e44311dd5d36c3a7dc21dfa;
extern u64 v_const26c89ee8ccc4ea998fd1a912;
extern u64 v_const2c624232cdd221771294dfbb;
extern u64 v_const2d2149bb550ad5e39952d8f4;
extern u64 v_const4e07408562bedb8b60ce05c1;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const66633592860a63ea6408b433;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const76a4fedc25549f0939d52fb7;
extern u64 v_const81906d9241165d9f6a541e47;
extern u64 v_const8719959a9b35fbf66b391c9f;
extern u64 v_const987d6cf2e5032ff135cc0c65;
extern u64 v_const99e1cbf3d792d4a87847a801;
extern u64 v_consta10f76b4ec574de5d7b6908e;
extern u64 v_constb0e9a61bdf716031c5ca8c29;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_conste3776bfed7f405de8017ecfa;
extern u64 v_constef2d127de37b942baad06145;
extern u64 v_constf95dfec4ee2675891829b965;


void slog_rules_c1a7954baa8c7a132(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre) (scan pleaf __t4JtR13 k) (body (exists st_ins (2 0 1) 1 k) (exists $sup9688x54x0x0x0 (1 3 0 2 4 5 6) 1 k) (exists st_msk (1 2 0) 1 k) (join-old st_join (1 2 3 4 0) 2 (1 2 3 4 0) k __t4JtR13 p __t4iIu12 __t4hUr14) (exists $sup9688x54x0x0x0 (1 4 6 3 0 2 5) 3 k p __t4iIu12) (exists pbranch (0 1 2 3 4) 2 __t4iIu12 p) (exists st_join_ans (0 1) 1 __t4hUr14) (join st_ins (1 2 0) 2 __t4iIu12 k __t2YgE11) (join $sup9688x54x0x0x0 (0 1 6 4 2 3 5) 4 __t2YgE11 k __t4iIu12 p l m r) (join pbranch (1 2 3 4 0) 5 p m l r __t4iIu12) (join-old st_msk (1 2 0) 2 (1 2 0) k m __t9Q9j15) (join st_msk_ans (0 1) 1 __t9Q9j15 __v0) (neq p __v0) (join st_join_ans (0 1) 1 __t4hUr14 res)) (head (emit st_ins_ans (0 1) __t2YgE11 res)) set.slog:55 #f)
  class ReadTask15 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_insindex0;  slog::Index** $sup9688x54x0x0x0index1;  slog::Index** st_mskindex2;  slog::Index** st_joinindex3;  slog::Index** $sup9688x54x0x0x0index4;  slog::Index** pbranchindex5;  slog::Index** st_join_ansindex6;  slog::Index** st_insindex7;  slog::Index** $sup9688x54x0x0x0index8;  slog::Index** pbranchindex9;  slog::Index** st_mskindex10;  slog::Index** st_msk_ansindex11;  slog::Index** st_join_ansindex12;  slog::Index** st_joindelta13;  slog::Index** st_mskdelta14;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_ins_ans");
      std::vector<u16> ord16({0, 1});
      slog::Relation* readrel17 = db->getRelation("st_ins_ans");
      head_index[0] = readrel17->getIndex(ord16, false);
      outer_rel = db->getRelation("pleaf");
      std::vector<u16> ord18({2, 0, 1});
      slog::Relation* readrel19 = db->getRelation("st_ins");
      st_insindex0 = readrel19->getIndex(ord18, false);
      std::vector<u16> ord20({1, 3, 0, 2, 4, 5, 6});
      slog::Relation* readrel21 = db->getRelation("$sup9688x54x0x0x0");
      $sup9688x54x0x0x0index1 = readrel21->getIndex(ord20, false);
      std::vector<u16> ord22({1, 2, 0});
      slog::Relation* readrel23 = db->getRelation("st_msk");
      st_mskindex2 = readrel23->getIndex(ord22, false);
      std::vector<u16> ord24({1, 2, 3, 4, 0});
      slog::Relation* readrel25 = db->getRelation("st_join");
      st_joinindex3 = readrel25->getIndex(ord24, false);
      std::vector<u16> ord26({1, 2, 3, 4, 0});
      slog::Relation* readrel27 = db->getRelation("st_join");
      st_joindelta13 = readrel27->getIndex(ord26, true);
      std::vector<u16> ord28({1, 4, 6, 3, 0, 2, 5});
      slog::Relation* readrel29 = db->getRelation("$sup9688x54x0x0x0");
      $sup9688x54x0x0x0index4 = readrel29->getIndex(ord28, false);
      std::vector<u16> ord30({0, 1, 2, 3, 4});
      slog::Relation* readrel31 = db->getRelation("pbranch");
      pbranchindex5 = readrel31->getIndex(ord30, false);
      std::vector<u16> ord32({0, 1});
      slog::Relation* readrel33 = db->getRelation("st_join_ans");
      st_join_ansindex6 = readrel33->getIndex(ord32, false);
      std::vector<u16> ord34({1, 2, 0});
      slog::Relation* readrel35 = db->getRelation("st_ins");
      st_insindex7 = readrel35->getIndex(ord34, false);
      std::vector<u16> ord36({0, 1, 6, 4, 2, 3, 5});
      slog::Relation* readrel37 = db->getRelation("$sup9688x54x0x0x0");
      $sup9688x54x0x0x0index8 = readrel37->getIndex(ord36, false);
      std::vector<u16> ord38({1, 2, 3, 4, 0});
      slog::Relation* readrel39 = db->getRelation("pbranch");
      pbranchindex9 = readrel39->getIndex(ord38, false);
      std::vector<u16> ord40({1, 2, 0});
      slog::Relation* readrel41 = db->getRelation("st_msk");
      st_mskindex10 = readrel41->getIndex(ord40, false);
      std::vector<u16> ord42({1, 2, 0});
      slog::Relation* readrel43 = db->getRelation("st_msk");
      st_mskdelta14 = readrel43->getIndex(ord42, true);
      std::vector<u16> ord44({0, 1});
      slog::Relation* readrel45 = db->getRelation("st_msk_ans");
      st_msk_ansindex11 = readrel45->getIndex(ord44, false);
      std::vector<u16> ord46({0, 1});
      slog::Relation* readrel47 = db->getRelation("st_join_ans");
      st_join_ansindex12 = readrel47->getIndex(ord46, false);
  
    }
    ReadTask15(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        if (!slog::exists_probe<3,1>(st_insindex0, std::array<u64,3>{v_c1, 0, 0})) return;
        if (!slog::exists_probe<7,1>($sup9688x54x0x0x0index1, std::array<u64,7>{v_c1, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mskindex2, std::array<u64,3>{v_c1, 0, 0})) return;
        slog::join_probe_old<5,2>(st_joinindex3, st_joindelta13, std::array<u64,5>{v_c1, v_c0, 0, 0, 0}, [&](const std::array<u64,5>& m48) {
          u64 v_c2 = m48[2]; u64 v_c3 = m48[3]; u64 v_c4 = m48[4];
          if (!slog::exists_probe<7,3>($sup9688x54x0x0x0index4, std::array<u64,7>{v_c1, v_c2, v_c3, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,2>(pbranchindex5, std::array<u64,5>{v_c3, v_c2, 0, 0, 0})) return;
          if (!slog::exists_probe<2,1>(st_join_ansindex6, std::array<u64,2>{v_c4, 0})) return;
          slog::join_probe<3,2>(st_insindex7, std::array<u64,3>{v_c3, v_c1, 0}, [&](const std::array<u64,3>& m49) {
            u64 v_c5 = m49[2];
            slog::join_probe<7,4>($sup9688x54x0x0x0index8, std::array<u64,7>{v_c5, v_c1, v_c3, v_c2, 0, 0, 0}, [&](const std::array<u64,7>& m50) {
              u64 v_c6 = m50[4]; u64 v_c7 = m50[5]; u64 v_c8 = m50[6];
              slog::join_probe<5,5>(pbranchindex9, std::array<u64,5>{v_c2, v_c7, v_c6, v_c8, v_c3}, [&](const std::array<u64,5>& m51) {
                slog::join_probe_old<3,2>(st_mskindex10, st_mskdelta14, std::array<u64,3>{v_c1, v_c7, 0}, [&](const std::array<u64,3>& m52) {
                  u64 v_c9 = m52[2];
                  slog::join_probe<2,1>(st_msk_ansindex11, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m53) {
                    u64 v_c10 = m53[1];
                    if (v_c2 == v_c10) return;
                    slog::join_probe<2,1>(st_join_ansindex12, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m54) {
                      u64 v_c11 = m54[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c5, v_c11}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:55", "delta:pleaf", _fires);
  
      if (!_done)
      {
        ReadTask15* _cont = new ReadTask15(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask15(db,b), false);
  // (crule (pre (let __tconst1v9F125 const5feceb66ffc86f38d952786c)) (scan pbranch __t32HA128 p m l r) (body (exists $sup9688x117x0x0x1 (2 3 5 7 0 1 4 6 8 9) 4 l m p r) (exists st_union (1 2 0) 1 __t32HA128) (exists st_msk (1 2 0) 1 p) (join $sup9688x117x0x0x0 (1 2 4 6 0 3 5 7 8) 4 l m p r __t0ttd124 n q u v) (cmp lt m n) (exists pbranch (1 2 3 4 0) 4 q n u v) (exists st_union (0 1 2) 2 __t0ttd124 __t32HA128) (exists st_msk (1 2 0) 2 p n) (exists st_msk_ans (1 0) 1 q) (exists st_union (1 2 0) 2 __t32HA128 v) (join $sup9688x117x0x0x1 (9 4 6 8 0 2 3 5 7 1) 9 v n q u __t0ttd124 l m p r __t3TTE127) (exists st_msk (1 2 0) 3 p n __t3TTE127) (exists st_msk_ans (0 1) 2 __t3TTE127 q) (join pbranch (1 2 3 4 0) 4 q n u v __t43ng122) (join st_union (0 1 2) 3 __t0ttd124 __t32HA128 __t43ng122) (join st_msk (1 2 0) 3 p n __t3TTE127) (join st_msk_ans (0 1) 2 __t3TTE127 q) (join-old st_union (1 2 0) 2 (1 2 0) __t32HA128 v __t4LMh129) (join st_union_ans (0 1) 1 __t4LMh129 __v0) (let __t3tQC126 (band p n)) (cmp gt __t3tQC126 __tconst1v9F125)) (head (emit-temp temp4p811353 __t0ttd124 __v0 n q u) (mkstruct pbranch (1 2 3 4 0) __t6NgR121 q n u __v0)) set.slog:118 #f)
  class ReadTask74 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x117x0x0x1index55;  slog::Index** st_unionindex56;  slog::Index** st_mskindex57;  slog::Index** $sup9688x117x0x0x0index58;  slog::Index** pbranchindex59;  slog::Index** st_unionindex60;  slog::Index** st_mskindex61;  slog::Index** st_msk_ansindex62;  slog::Index** st_unionindex63;  slog::Index** $sup9688x117x0x0x1index64;  slog::Index** st_mskindex65;  slog::Index** st_msk_ansindex66;  slog::Index** pbranchindex67;  slog::Index** st_unionindex68;  slog::Index** st_mskindex69;  slog::Index** st_msk_ansindex70;  slog::Index** st_unionindex71;  slog::Index** st_union_ansindex72;  slog::Index** st_uniondelta73;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4p811353");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord75({2, 3, 5, 7, 0, 1, 4, 6, 8, 9});
      slog::Relation* readrel76 = db->getRelation("$sup9688x117x0x0x1");
      $sup9688x117x0x0x1index55 = readrel76->getIndex(ord75, false);
      std::vector<u16> ord77({1, 2, 0});
      slog::Relation* readrel78 = db->getRelation("st_union");
      st_unionindex56 = readrel78->getIndex(ord77, false);
      std::vector<u16> ord79({1, 2, 0});
      slog::Relation* readrel80 = db->getRelation("st_msk");
      st_mskindex57 = readrel80->getIndex(ord79, false);
      std::vector<u16> ord81({1, 2, 4, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel82 = db->getRelation("$sup9688x117x0x0x0");
      $sup9688x117x0x0x0index58 = readrel82->getIndex(ord81, false);
      std::vector<u16> ord83({1, 2, 3, 4, 0});
      slog::Relation* readrel84 = db->getRelation("pbranch");
      pbranchindex59 = readrel84->getIndex(ord83, false);
      std::vector<u16> ord85({0, 1, 2});
      slog::Relation* readrel86 = db->getRelation("st_union");
      st_unionindex60 = readrel86->getIndex(ord85, false);
      std::vector<u16> ord87({1, 2, 0});
      slog::Relation* readrel88 = db->getRelation("st_msk");
      st_mskindex61 = readrel88->getIndex(ord87, false);
      std::vector<u16> ord89({1, 0});
      slog::Relation* readrel90 = db->getRelation("st_msk_ans");
      st_msk_ansindex62 = readrel90->getIndex(ord89, false);
      std::vector<u16> ord91({1, 2, 0});
      slog::Relation* readrel92 = db->getRelation("st_union");
      st_unionindex63 = readrel92->getIndex(ord91, false);
      std::vector<u16> ord93({9, 4, 6, 8, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel94 = db->getRelation("$sup9688x117x0x0x1");
      $sup9688x117x0x0x1index64 = readrel94->getIndex(ord93, false);
      std::vector<u16> ord95({1, 2, 0});
      slog::Relation* readrel96 = db->getRelation("st_msk");
      st_mskindex65 = readrel96->getIndex(ord95, false);
      std::vector<u16> ord97({0, 1});
      slog::Relation* readrel98 = db->getRelation("st_msk_ans");
      st_msk_ansindex66 = readrel98->getIndex(ord97, false);
      std::vector<u16> ord99({1, 2, 3, 4, 0});
      slog::Relation* readrel100 = db->getRelation("pbranch");
      pbranchindex67 = readrel100->getIndex(ord99, false);
      std::vector<u16> ord101({0, 1, 2});
      slog::Relation* readrel102 = db->getRelation("st_union");
      st_unionindex68 = readrel102->getIndex(ord101, false);
      std::vector<u16> ord103({1, 2, 0});
      slog::Relation* readrel104 = db->getRelation("st_msk");
      st_mskindex69 = readrel104->getIndex(ord103, false);
      std::vector<u16> ord105({0, 1});
      slog::Relation* readrel106 = db->getRelation("st_msk_ans");
      st_msk_ansindex70 = readrel106->getIndex(ord105, false);
      std::vector<u16> ord107({1, 2, 0});
      slog::Relation* readrel108 = db->getRelation("st_union");
      st_unionindex71 = readrel108->getIndex(ord107, false);
      std::vector<u16> ord109({1, 2, 0});
      slog::Relation* readrel110 = db->getRelation("st_union");
      st_uniondelta73 = readrel110->getIndex(ord109, true);
      std::vector<u16> ord111({0, 1});
      slog::Relation* readrel112 = db->getRelation("st_union_ans");
      st_union_ansindex72 = readrel112->getIndex(ord111, false);
  
    }
    ReadTask74(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c12 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c2 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c6 = _t[3];
        u64 v_c8 = _t[4];
        if (!slog::exists_probe<10,4>($sup9688x117x0x0x1index55, std::array<u64,10>{v_c6, v_c7, v_c2, v_c8, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_unionindex56, std::array<u64,3>{v_c13, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mskindex57, std::array<u64,3>{v_c2, 0, 0})) return;
        slog::join_probe<9,4>($sup9688x117x0x0x0index58, std::array<u64,9>{v_c6, v_c7, v_c2, v_c8, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m113) {
          u64 v_c14 = m113[4]; u64 v_c15 = m113[5]; u64 v_c16 = m113[6]; u64 v_c17 = m113[7]; u64 v_c18 = m113[8];
          u64 v_c19 = _prim_lt(db, v_c7, v_c15);
          if (v_c19 == slog_error) { slog::emit_pending_error(db, "set.slog:118"); return; }
          if (!v_c19) return;
          if (!slog::exists_probe<5,4>(pbranchindex59, std::array<u64,5>{v_c16, v_c15, v_c17, v_c18, 0})) return;
          if (!slog::exists_probe<3,2>(st_unionindex60, std::array<u64,3>{v_c14, v_c13, 0})) return;
          if (!slog::exists_probe<3,2>(st_mskindex61, std::array<u64,3>{v_c2, v_c15, 0})) return;
          if (!slog::exists_probe<2,1>(st_msk_ansindex62, std::array<u64,2>{v_c16, 0})) return;
          if (!slog::exists_probe<3,2>(st_unionindex63, std::array<u64,3>{v_c13, v_c18, 0})) return;
          slog::join_probe<10,9>($sup9688x117x0x0x1index64, std::array<u64,10>{v_c18, v_c15, v_c16, v_c17, v_c14, v_c6, v_c7, v_c2, v_c8, 0}, [&](const std::array<u64,10>& m115) {
            u64 v_c20 = m115[9];
            if (!slog::exists_probe<3,3>(st_mskindex65, std::array<u64,3>{v_c2, v_c15, v_c20})) return;
            if (!slog::exists_probe<2,2>(st_msk_ansindex66, std::array<u64,2>{v_c20, v_c16})) return;
            slog::join_probe<5,4>(pbranchindex67, std::array<u64,5>{v_c16, v_c15, v_c17, v_c18, 0}, [&](const std::array<u64,5>& m116) {
              u64 v_c21 = m116[4];
              slog::join_probe<3,3>(st_unionindex68, std::array<u64,3>{v_c14, v_c13, v_c21}, [&](const std::array<u64,3>& m117) {
                slog::join_probe<3,3>(st_mskindex69, std::array<u64,3>{v_c2, v_c15, v_c20}, [&](const std::array<u64,3>& m118) {
                  slog::join_probe<2,2>(st_msk_ansindex70, std::array<u64,2>{v_c20, v_c16}, [&](const std::array<u64,2>& m119) {
                    slog::join_probe_old<3,2>(st_unionindex71, st_uniondelta73, std::array<u64,3>{v_c13, v_c18, 0}, [&](const std::array<u64,3>& m120) {
                      u64 v_c22 = m120[2];
                      slog::join_probe<2,1>(st_union_ansindex72, std::array<u64,2>{v_c22, 0}, [&](const std::array<u64,2>& m121) {
                        u64 v_c10 = m121[1];
                        u64 v_c23 = _prim_band(db, v_c2, v_c15);
                        if (v_c23 == slog_error) { slog::emit_pending_error(db, "set.slog:118"); return; }
                        u64 v_c24 = _prim_gt(db, v_c23, v_c12);
                        if (v_c24 == slog_error) { slog::emit_pending_error(db, "set.slog:118"); return; }
                        if (!v_c24) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c14, v_c10, v_c15, v_c16, v_c17});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c16, v_c15, v_c17, v_c10}, std::array<u16,5>{1, 2, 3, 4, 0});
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
        ReadTask74* _cont = new ReadTask74(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask74(db,b), false);
  // (crule (pre (let __tconst8Ksp764 conste3776bfed7f405de8017ecfa) (let __tconst6tkr379 const6b86b273ff34fce19d6b804e) (let __tconst7Eph382 const2c624232cdd221771294dfbb) (let __tconst4emd384 constd4735e3a265e16eee03f5971) (let __tconst2ksI386 constef2d127de37b942baad06145)) (scan st_ins_ans __t2Q6o381 __v0) (body (exists _enum (1 0) 1 __tconst8Ksp764) (exists st_ins (1 2 0) 2 __v0 __tconst7Eph382) (exists st_ins (2 0 1) 1 __tconst4emd384) (exists st_ins (2 0 1) 1 __tconst2ksI386) (join-old st_ins (0 2 1) 2 (0 2 1) __t2Q6o381 __tconst6tkr379 __t6fdj380) (join _enum (0 1) 2 __t6fdj380 __tconst8Ksp764) (join-old st_ins (1 2 0) 2 (1 2 0) __v0 __tconst7Eph382 __t0FtX383) (join-old st_ins_ans (0 1) 1 (0 1) __t0FtX383 __v1) (join-old st_ins (1 2 0) 2 (1 2 0) __v1 __tconst4emd384 __t88YX385) (join-old st_ins_ans (0 1) 1 (0 1) __t88YX385 __v2) (join-old st_ins (1 2 0) 2 (1 2 0) __v2 __tconst2ksI386 __t7LWC387) (join-old st_ins_ans (0 1) 1 (0 1) __t7LWC387 r)) (head (emit canon (0) r)) st_basic.slog:15 #f)
  class ReadTask142 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex123;  slog::Index** st_insindex124;  slog::Index** st_insindex125;  slog::Index** st_insindex126;  slog::Index** st_insindex127;  slog::Index** _enumindex128;  slog::Index** st_insindex129;  slog::Index** st_ins_ansindex130;  slog::Index** st_insindex131;  slog::Index** st_ins_ansindex132;  slog::Index** st_insindex133;  slog::Index** st_ins_ansindex134;  slog::Index** st_insdelta135;  slog::Index** st_insdelta136;  slog::Index** st_ins_ansdelta137;  slog::Index** st_insdelta138;  slog::Index** st_ins_ansdelta139;  slog::Index** st_insdelta140;  slog::Index** st_ins_ansdelta141;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("canon");
      std::vector<u16> ord143({0});
      slog::Relation* readrel144 = db->getRelation("canon");
      head_index[0] = readrel144->getIndex(ord143, false);
      outer_rel = db->getRelation("st_ins_ans");
      std::vector<u16> ord145({1, 0});
      slog::Relation* readrel146 = db->getRelation("_enum");
      _enumindex123 = readrel146->getIndex(ord145, false);
      std::vector<u16> ord147({1, 2, 0});
      slog::Relation* readrel148 = db->getRelation("st_ins");
      st_insindex124 = readrel148->getIndex(ord147, false);
      std::vector<u16> ord149({2, 0, 1});
      slog::Relation* readrel150 = db->getRelation("st_ins");
      st_insindex125 = readrel150->getIndex(ord149, false);
      std::vector<u16> ord151({2, 0, 1});
      slog::Relation* readrel152 = db->getRelation("st_ins");
      st_insindex126 = readrel152->getIndex(ord151, false);
      std::vector<u16> ord153({0, 2, 1});
      slog::Relation* readrel154 = db->getRelation("st_ins");
      st_insindex127 = readrel154->getIndex(ord153, false);
      std::vector<u16> ord155({0, 2, 1});
      slog::Relation* readrel156 = db->getRelation("st_ins");
      st_insdelta135 = readrel156->getIndex(ord155, true);
      std::vector<u16> ord157({0, 1});
      slog::Relation* readrel158 = db->getRelation("_enum");
      _enumindex128 = readrel158->getIndex(ord157, false);
      std::vector<u16> ord159({1, 2, 0});
      slog::Relation* readrel160 = db->getRelation("st_ins");
      st_insindex129 = readrel160->getIndex(ord159, false);
      std::vector<u16> ord161({1, 2, 0});
      slog::Relation* readrel162 = db->getRelation("st_ins");
      st_insdelta136 = readrel162->getIndex(ord161, true);
      std::vector<u16> ord163({0, 1});
      slog::Relation* readrel164 = db->getRelation("st_ins_ans");
      st_ins_ansindex130 = readrel164->getIndex(ord163, false);
      std::vector<u16> ord165({0, 1});
      slog::Relation* readrel166 = db->getRelation("st_ins_ans");
      st_ins_ansdelta137 = readrel166->getIndex(ord165, true);
      std::vector<u16> ord167({1, 2, 0});
      slog::Relation* readrel168 = db->getRelation("st_ins");
      st_insindex131 = readrel168->getIndex(ord167, false);
      std::vector<u16> ord169({1, 2, 0});
      slog::Relation* readrel170 = db->getRelation("st_ins");
      st_insdelta138 = readrel170->getIndex(ord169, true);
      std::vector<u16> ord171({0, 1});
      slog::Relation* readrel172 = db->getRelation("st_ins_ans");
      st_ins_ansindex132 = readrel172->getIndex(ord171, false);
      std::vector<u16> ord173({0, 1});
      slog::Relation* readrel174 = db->getRelation("st_ins_ans");
      st_ins_ansdelta139 = readrel174->getIndex(ord173, true);
      std::vector<u16> ord175({1, 2, 0});
      slog::Relation* readrel176 = db->getRelation("st_ins");
      st_insindex133 = readrel176->getIndex(ord175, false);
      std::vector<u16> ord177({1, 2, 0});
      slog::Relation* readrel178 = db->getRelation("st_ins");
      st_insdelta140 = readrel178->getIndex(ord177, true);
      std::vector<u16> ord179({0, 1});
      slog::Relation* readrel180 = db->getRelation("st_ins_ans");
      st_ins_ansindex134 = readrel180->getIndex(ord179, false);
      std::vector<u16> ord181({0, 1});
      slog::Relation* readrel182 = db->getRelation("st_ins_ans");
      st_ins_ansdelta141 = readrel182->getIndex(ord181, true);
  
    }
    ReadTask142(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c25 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c26 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c27 = v_const2c624232cdd221771294dfbb;
      u64 v_c28 = v_constd4735e3a265e16eee03f5971;
      u64 v_c29 = v_constef2d127de37b942baad06145;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c30 = _t[0];
        u64 v_c10 = _t[1];
        if (!slog::exists_probe<2,1>(_enumindex123, std::array<u64,2>{v_c25, 0})) return;
        if (!slog::exists_probe<3,2>(st_insindex124, std::array<u64,3>{v_c10, v_c27, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex125, std::array<u64,3>{v_c28, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex126, std::array<u64,3>{v_c29, 0, 0})) return;
        slog::join_probe_old<3,2>(st_insindex127, st_insdelta135, std::array<u64,3>{v_c30, v_c26, 0}, [&](const std::array<u64,3>& m183) {
          u64 v_c31 = m183[2];
          slog::join_probe<2,2>(_enumindex128, std::array<u64,2>{v_c31, v_c25}, [&](const std::array<u64,2>& m184) {
            slog::join_probe_old<3,2>(st_insindex129, st_insdelta136, std::array<u64,3>{v_c10, v_c27, 0}, [&](const std::array<u64,3>& m185) {
              u64 v_c32 = m185[2];
              slog::join_probe_old<2,1>(st_ins_ansindex130, st_ins_ansdelta137, std::array<u64,2>{v_c32, 0}, [&](const std::array<u64,2>& m186) {
                u64 v_c33 = m186[1];
                slog::join_probe_old<3,2>(st_insindex131, st_insdelta138, std::array<u64,3>{v_c33, v_c28, 0}, [&](const std::array<u64,3>& m187) {
                  u64 v_c34 = m187[2];
                  slog::join_probe_old<2,1>(st_ins_ansindex132, st_ins_ansdelta139, std::array<u64,2>{v_c34, 0}, [&](const std::array<u64,2>& m188) {
                    u64 v_c35 = m188[1];
                    slog::join_probe_old<3,2>(st_insindex133, st_insdelta140, std::array<u64,3>{v_c35, v_c29, 0}, [&](const std::array<u64,3>& m189) {
                      u64 v_c36 = m189[2];
                      slog::join_probe_old<2,1>(st_ins_ansindex134, st_ins_ansdelta141, std::array<u64,2>{v_c36, 0}, [&](const std::array<u64,2>& m190) {
                        u64 v_c8 = m190[1];
                        ++_fires;
                        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c8}, std::array<u16,1>{0});
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
        ReadTask142* _cont = new ReadTask142(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask142(db,b), false);
  // (crule (pre) (scan pbranch __t2KHS511 q n u v) (body (join-old st_diff (2 0 1) 1 (2 0 1) __t2KHS511 __t5hAF513 __t1YwN512) (join-old pbranch (0 1 2 3 4) 1 (0 1 2 3 4) __t1YwN512 p m l r) (cmp lt n m)) (head (emit $sup9688x145x0x0x0 (0 1 2 3 4 5 6 7 8) __t5hAF513 l m n p q r u v)) set.slog:146 #f)
  class ReadTask195 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_diffindex191;  slog::Index** pbranchindex192;  slog::Index** st_diffdelta193;  slog::Index** pbranchdelta194;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x145x0x0x0");
      std::vector<u16> ord196({0, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel197 = db->getRelation("$sup9688x145x0x0x0");
      head_index[0] = readrel197->getIndex(ord196, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord198({2, 0, 1});
      slog::Relation* readrel199 = db->getRelation("st_diff");
      st_diffindex191 = readrel199->getIndex(ord198, false);
      std::vector<u16> ord200({2, 0, 1});
      slog::Relation* readrel201 = db->getRelation("st_diff");
      st_diffdelta193 = readrel201->getIndex(ord200, true);
      std::vector<u16> ord202({0, 1, 2, 3, 4});
      slog::Relation* readrel203 = db->getRelation("pbranch");
      pbranchindex192 = readrel203->getIndex(ord202, false);
      std::vector<u16> ord204({0, 1, 2, 3, 4});
      slog::Relation* readrel205 = db->getRelation("pbranch");
      pbranchdelta194 = readrel205->getIndex(ord204, true);
  
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
        u64 v_c37 = _t[0];
        u64 v_c16 = _t[1];
        u64 v_c15 = _t[2];
        u64 v_c17 = _t[3];
        u64 v_c18 = _t[4];
        slog::join_probe_old<3,1>(st_diffindex191, st_diffdelta193, std::array<u64,3>{v_c37, 0, 0}, [&](const std::array<u64,3>& m206) {
          u64 v_c38 = m206[1]; u64 v_c39 = m206[2];
          slog::join_probe_old<5,1>(pbranchindex192, pbranchdelta194, std::array<u64,5>{v_c39, 0, 0, 0, 0}, [&](const std::array<u64,5>& m207) {
            u64 v_c2 = m207[1]; u64 v_c7 = m207[2]; u64 v_c6 = m207[3]; u64 v_c8 = m207[4];
            u64 v_c40 = _prim_lt(db, v_c15, v_c7);
            if (v_c40 == slog_error) { slog::emit_pending_error(db, "set.slog:146"); return; }
            if (!v_c40) return;
            ++_fires;
            slog::emit<9>(head_rel[0], head_index[0], newbatch[0], std::array<u64,9>{v_c38, v_c6, v_c7, v_c15, v_c2, v_c16, v_c8, v_c17, v_c18}, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:146", "delta:pbranch", _fires);
  
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
  // (crule (pre (let __tconst2KXZ105 const6b86b273ff34fce19d6b804e)) (scan st_msk_ans __t3oZy109 q) (body (exists $sup9688x148x0x0x0 (5 3 7 8 0 1 2 4 6) 1 q) (exists pbranch (1 2 3 4 0) 1 q) (join-old st_msk (0 1 2) 1 (0 1 2) __t3oZy109 p n) (exists pbranch (1 2 3 4 0) 2 q n) (exists pbranch (1 2 3 4 0) 1 p) (join-old $sup9688x148x0x0x0 (3 4 5 0 1 2 6 7 8) 3 (3 4 5 0 1 2 6 7 8) n p q __t5Ek2104 l m r u v) (cmp lt m n) (exists pbranch (1 2 3 4 0) 4 p m l r) (exists st_diff (2 0 1) 1 u) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t6SZQ102) (exists st_diff (2 0 1) 2 __t6SZQ102 __t5Ek2104) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t6qKy107) (join-old st_diff (0 1 2) 3 (0 1 2) __t5Ek2104 __t6qKy107 __t6SZQ102) (join-old st_diff (1 2 0) 2 (1 2 0) __t6qKy107 u __t4u9h108) (join st_diff_ans (0 1) 1 __t4u9h108 res) (let __t7tsw106 (band p n)) (cmp lt __t7tsw106 __tconst2KXZ105)) (head (emit st_diff_ans (0 1) __t5Ek2104 res)) set.slog:149 #f)
  class ReadTask229 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x148x0x0x0index209;  slog::Index** pbranchindex210;  slog::Index** st_mskindex211;  slog::Index** pbranchindex212;  slog::Index** pbranchindex213;  slog::Index** $sup9688x148x0x0x0index214;  slog::Index** pbranchindex215;  slog::Index** st_diffindex216;  slog::Index** pbranchindex217;  slog::Index** st_diffindex218;  slog::Index** pbranchindex219;  slog::Index** st_diffindex220;  slog::Index** st_diffindex221;  slog::Index** st_diff_ansindex222;  slog::Index** st_mskdelta223;  slog::Index** $sup9688x148x0x0x0delta224;  slog::Index** pbranchdelta225;  slog::Index** pbranchdelta226;  slog::Index** st_diffdelta227;  slog::Index** st_diffdelta228;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord230({0, 1});
      slog::Relation* readrel231 = db->getRelation("st_diff_ans");
      head_index[0] = readrel231->getIndex(ord230, false);
      outer_rel = db->getRelation("st_msk_ans");
      std::vector<u16> ord232({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel233 = db->getRelation("$sup9688x148x0x0x0");
      $sup9688x148x0x0x0index209 = readrel233->getIndex(ord232, false);
      std::vector<u16> ord234({1, 2, 3, 4, 0});
      slog::Relation* readrel235 = db->getRelation("pbranch");
      pbranchindex210 = readrel235->getIndex(ord234, false);
      std::vector<u16> ord236({0, 1, 2});
      slog::Relation* readrel237 = db->getRelation("st_msk");
      st_mskindex211 = readrel237->getIndex(ord236, false);
      std::vector<u16> ord238({0, 1, 2});
      slog::Relation* readrel239 = db->getRelation("st_msk");
      st_mskdelta223 = readrel239->getIndex(ord238, true);
      std::vector<u16> ord240({1, 2, 3, 4, 0});
      slog::Relation* readrel241 = db->getRelation("pbranch");
      pbranchindex212 = readrel241->getIndex(ord240, false);
      std::vector<u16> ord242({1, 2, 3, 4, 0});
      slog::Relation* readrel243 = db->getRelation("pbranch");
      pbranchindex213 = readrel243->getIndex(ord242, false);
      std::vector<u16> ord244({3, 4, 5, 0, 1, 2, 6, 7, 8});
      slog::Relation* readrel245 = db->getRelation("$sup9688x148x0x0x0");
      $sup9688x148x0x0x0index214 = readrel245->getIndex(ord244, false);
      std::vector<u16> ord246({3, 4, 5, 0, 1, 2, 6, 7, 8});
      slog::Relation* readrel247 = db->getRelation("$sup9688x148x0x0x0");
      $sup9688x148x0x0x0delta224 = readrel247->getIndex(ord246, true);
      std::vector<u16> ord248({1, 2, 3, 4, 0});
      slog::Relation* readrel249 = db->getRelation("pbranch");
      pbranchindex215 = readrel249->getIndex(ord248, false);
      std::vector<u16> ord250({2, 0, 1});
      slog::Relation* readrel251 = db->getRelation("st_diff");
      st_diffindex216 = readrel251->getIndex(ord250, false);
      std::vector<u16> ord252({1, 2, 3, 4, 0});
      slog::Relation* readrel253 = db->getRelation("pbranch");
      pbranchindex217 = readrel253->getIndex(ord252, false);
      std::vector<u16> ord254({1, 2, 3, 4, 0});
      slog::Relation* readrel255 = db->getRelation("pbranch");
      pbranchdelta225 = readrel255->getIndex(ord254, true);
      std::vector<u16> ord256({2, 0, 1});
      slog::Relation* readrel257 = db->getRelation("st_diff");
      st_diffindex218 = readrel257->getIndex(ord256, false);
      std::vector<u16> ord258({1, 2, 3, 4, 0});
      slog::Relation* readrel259 = db->getRelation("pbranch");
      pbranchindex219 = readrel259->getIndex(ord258, false);
      std::vector<u16> ord260({1, 2, 3, 4, 0});
      slog::Relation* readrel261 = db->getRelation("pbranch");
      pbranchdelta226 = readrel261->getIndex(ord260, true);
      std::vector<u16> ord262({0, 1, 2});
      slog::Relation* readrel263 = db->getRelation("st_diff");
      st_diffindex220 = readrel263->getIndex(ord262, false);
      std::vector<u16> ord264({0, 1, 2});
      slog::Relation* readrel265 = db->getRelation("st_diff");
      st_diffdelta227 = readrel265->getIndex(ord264, true);
      std::vector<u16> ord266({1, 2, 0});
      slog::Relation* readrel267 = db->getRelation("st_diff");
      st_diffindex221 = readrel267->getIndex(ord266, false);
      std::vector<u16> ord268({1, 2, 0});
      slog::Relation* readrel269 = db->getRelation("st_diff");
      st_diffdelta228 = readrel269->getIndex(ord268, true);
      std::vector<u16> ord270({0, 1});
      slog::Relation* readrel271 = db->getRelation("st_diff_ans");
      st_diff_ansindex222 = readrel271->getIndex(ord270, false);
  
    }
    ReadTask229(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c41 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c42 = _t[0];
        u64 v_c16 = _t[1];
        if (!slog::exists_probe<9,1>($sup9688x148x0x0x0index209, std::array<u64,9>{v_c16, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex210, std::array<u64,5>{v_c16, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(st_mskindex211, st_mskdelta223, std::array<u64,3>{v_c42, 0, 0}, [&](const std::array<u64,3>& m272) {
          u64 v_c2 = m272[1]; u64 v_c15 = m272[2];
          if (!slog::exists_probe<5,2>(pbranchindex212, std::array<u64,5>{v_c16, v_c15, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>(pbranchindex213, std::array<u64,5>{v_c2, 0, 0, 0, 0})) return;
          slog::join_probe_old<9,3>($sup9688x148x0x0x0index214, $sup9688x148x0x0x0delta224, std::array<u64,9>{v_c15, v_c2, v_c16, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m273) {
            u64 v_c43 = m273[3]; u64 v_c6 = m273[4]; u64 v_c7 = m273[5]; u64 v_c8 = m273[6]; u64 v_c17 = m273[7]; u64 v_c18 = m273[8];
            u64 v_c44 = _prim_lt(db, v_c7, v_c15);
            if (v_c44 == slog_error) { slog::emit_pending_error(db, "set.slog:149"); return; }
            if (!v_c44) return;
            if (!slog::exists_probe<5,4>(pbranchindex215, std::array<u64,5>{v_c2, v_c7, v_c6, v_c8, 0})) return;
            if (!slog::exists_probe<3,1>(st_diffindex216, std::array<u64,3>{v_c17, 0, 0})) return;
            slog::join_probe_old<5,4>(pbranchindex217, pbranchdelta225, std::array<u64,5>{v_c16, v_c15, v_c17, v_c18, 0}, [&](const std::array<u64,5>& m275) {
              u64 v_c45 = m275[4];
              if (!slog::exists_probe<3,2>(st_diffindex218, std::array<u64,3>{v_c45, v_c43, 0})) return;
              slog::join_probe_old<5,4>(pbranchindex219, pbranchdelta226, std::array<u64,5>{v_c2, v_c7, v_c6, v_c8, 0}, [&](const std::array<u64,5>& m276) {
                u64 v_c46 = m276[4];
                slog::join_probe_old<3,3>(st_diffindex220, st_diffdelta227, std::array<u64,3>{v_c43, v_c46, v_c45}, [&](const std::array<u64,3>& m277) {
                  slog::join_probe_old<3,2>(st_diffindex221, st_diffdelta228, std::array<u64,3>{v_c46, v_c17, 0}, [&](const std::array<u64,3>& m278) {
                    u64 v_c47 = m278[2];
                    slog::join_probe<2,1>(st_diff_ansindex222, std::array<u64,2>{v_c47, 0}, [&](const std::array<u64,2>& m279) {
                      u64 v_c11 = m279[1];
                      u64 v_c48 = _prim_band(db, v_c2, v_c15);
                      if (v_c48 == slog_error) { slog::emit_pending_error(db, "set.slog:149"); return; }
                      u64 v_c49 = _prim_lt(db, v_c48, v_c41);
                      if (v_c49 == slog_error) { slog::emit_pending_error(db, "set.slog:149"); return; }
                      if (!v_c49) return;
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c43, v_c11}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:149", "delta:st_msk_ans", _fires);
  
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
  // (crule (pre) (scan st_bld __t9obY409 p m __v0 __v1) (body (exists $sup9688x136x0x0x0 (2 3 1 4 0 5 6) 2 m p) (exists pbranch (1 2 3 4 0) 2 p m) (exists st_diff_ans (1 0) 1 __v0) (exists st_diff_ans (1 0) 1 __v1) (exists st_bld_ans (0 1) 1 __t9obY409) (join pbranch (1 2 3 4 0) 2 p m u v __t9ous406) (exists st_diff (2 0 1) 1 __t9ous406) (exists st_diff (2 0 1) 1 u) (exists st_diff (2 0 1) 1 v) (join $sup9688x136x0x0x0 (2 3 5 6 0 1 4) 4 m p u v __t5pD6408 l r) (exists st_diff (2 0 1) 2 __t9ous406 __t5pD6408) (exists st_diff (1 2 0) 2 l u) (exists st_diff (1 2 0) 2 r v) (join pbranch (1 2 3 4 0) 4 p m l r __t3cJ7407) (join st_diff (0 1 2) 3 __t5pD6408 __t3cJ7407 __t9ous406) (join-old st_diff (1 2 0) 2 (1 2 0) l u __t6cu0410) (join st_diff_ans (0 1) 2 __t6cu0410 __v0) (join-old st_diff (1 2 0) 2 (1 2 0) r v __t8u30411) (join st_diff_ans (0 1) 2 __t8u30411 __v1) (join st_bld_ans (0 1) 1 __t9obY409 res)) (head (emit st_diff_ans (0 1) __t5pD6408 res)) set.slog:137 #f)
  class ReadTask303 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x136x0x0x0index281;  slog::Index** pbranchindex282;  slog::Index** st_diff_ansindex283;  slog::Index** st_diff_ansindex284;  slog::Index** st_bld_ansindex285;  slog::Index** pbranchindex286;  slog::Index** st_diffindex287;  slog::Index** st_diffindex288;  slog::Index** st_diffindex289;  slog::Index** $sup9688x136x0x0x0index290;  slog::Index** st_diffindex291;  slog::Index** st_diffindex292;  slog::Index** st_diffindex293;  slog::Index** pbranchindex294;  slog::Index** st_diffindex295;  slog::Index** st_diffindex296;  slog::Index** st_diff_ansindex297;  slog::Index** st_diffindex298;  slog::Index** st_diff_ansindex299;  slog::Index** st_bld_ansindex300;  slog::Index** st_diffdelta301;  slog::Index** st_diffdelta302;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord304({0, 1});
      slog::Relation* readrel305 = db->getRelation("st_diff_ans");
      head_index[0] = readrel305->getIndex(ord304, false);
      outer_rel = db->getRelation("st_bld");
      std::vector<u16> ord306({2, 3, 1, 4, 0, 5, 6});
      slog::Relation* readrel307 = db->getRelation("$sup9688x136x0x0x0");
      $sup9688x136x0x0x0index281 = readrel307->getIndex(ord306, false);
      std::vector<u16> ord308({1, 2, 3, 4, 0});
      slog::Relation* readrel309 = db->getRelation("pbranch");
      pbranchindex282 = readrel309->getIndex(ord308, false);
      std::vector<u16> ord310({1, 0});
      slog::Relation* readrel311 = db->getRelation("st_diff_ans");
      st_diff_ansindex283 = readrel311->getIndex(ord310, false);
      std::vector<u16> ord312({1, 0});
      slog::Relation* readrel313 = db->getRelation("st_diff_ans");
      st_diff_ansindex284 = readrel313->getIndex(ord312, false);
      std::vector<u16> ord314({0, 1});
      slog::Relation* readrel315 = db->getRelation("st_bld_ans");
      st_bld_ansindex285 = readrel315->getIndex(ord314, false);
      std::vector<u16> ord316({1, 2, 3, 4, 0});
      slog::Relation* readrel317 = db->getRelation("pbranch");
      pbranchindex286 = readrel317->getIndex(ord316, false);
      std::vector<u16> ord318({2, 0, 1});
      slog::Relation* readrel319 = db->getRelation("st_diff");
      st_diffindex287 = readrel319->getIndex(ord318, false);
      std::vector<u16> ord320({2, 0, 1});
      slog::Relation* readrel321 = db->getRelation("st_diff");
      st_diffindex288 = readrel321->getIndex(ord320, false);
      std::vector<u16> ord322({2, 0, 1});
      slog::Relation* readrel323 = db->getRelation("st_diff");
      st_diffindex289 = readrel323->getIndex(ord322, false);
      std::vector<u16> ord324({2, 3, 5, 6, 0, 1, 4});
      slog::Relation* readrel325 = db->getRelation("$sup9688x136x0x0x0");
      $sup9688x136x0x0x0index290 = readrel325->getIndex(ord324, false);
      std::vector<u16> ord326({2, 0, 1});
      slog::Relation* readrel327 = db->getRelation("st_diff");
      st_diffindex291 = readrel327->getIndex(ord326, false);
      std::vector<u16> ord328({1, 2, 0});
      slog::Relation* readrel329 = db->getRelation("st_diff");
      st_diffindex292 = readrel329->getIndex(ord328, false);
      std::vector<u16> ord330({1, 2, 0});
      slog::Relation* readrel331 = db->getRelation("st_diff");
      st_diffindex293 = readrel331->getIndex(ord330, false);
      std::vector<u16> ord332({1, 2, 3, 4, 0});
      slog::Relation* readrel333 = db->getRelation("pbranch");
      pbranchindex294 = readrel333->getIndex(ord332, false);
      std::vector<u16> ord334({0, 1, 2});
      slog::Relation* readrel335 = db->getRelation("st_diff");
      st_diffindex295 = readrel335->getIndex(ord334, false);
      std::vector<u16> ord336({1, 2, 0});
      slog::Relation* readrel337 = db->getRelation("st_diff");
      st_diffindex296 = readrel337->getIndex(ord336, false);
      std::vector<u16> ord338({1, 2, 0});
      slog::Relation* readrel339 = db->getRelation("st_diff");
      st_diffdelta301 = readrel339->getIndex(ord338, true);
      std::vector<u16> ord340({0, 1});
      slog::Relation* readrel341 = db->getRelation("st_diff_ans");
      st_diff_ansindex297 = readrel341->getIndex(ord340, false);
      std::vector<u16> ord342({1, 2, 0});
      slog::Relation* readrel343 = db->getRelation("st_diff");
      st_diffindex298 = readrel343->getIndex(ord342, false);
      std::vector<u16> ord344({1, 2, 0});
      slog::Relation* readrel345 = db->getRelation("st_diff");
      st_diffdelta302 = readrel345->getIndex(ord344, true);
      std::vector<u16> ord346({0, 1});
      slog::Relation* readrel347 = db->getRelation("st_diff_ans");
      st_diff_ansindex299 = readrel347->getIndex(ord346, false);
      std::vector<u16> ord348({0, 1});
      slog::Relation* readrel349 = db->getRelation("st_bld_ans");
      st_bld_ansindex300 = readrel349->getIndex(ord348, false);
  
    }
    ReadTask303(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c2 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c10 = _t[3];
        u64 v_c33 = _t[4];
        if (!slog::exists_probe<7,2>($sup9688x136x0x0x0index281, std::array<u64,7>{v_c7, v_c2, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,2>(pbranchindex282, std::array<u64,5>{v_c2, v_c7, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(st_diff_ansindex283, std::array<u64,2>{v_c10, 0})) return;
        if (!slog::exists_probe<2,1>(st_diff_ansindex284, std::array<u64,2>{v_c33, 0})) return;
        if (!slog::exists_probe<2,1>(st_bld_ansindex285, std::array<u64,2>{v_c50, 0})) return;
        slog::join_probe<5,2>(pbranchindex286, std::array<u64,5>{v_c2, v_c7, 0, 0, 0}, [&](const std::array<u64,5>& m350) {
          u64 v_c17 = m350[2]; u64 v_c18 = m350[3]; u64 v_c51 = m350[4];
          if (!slog::exists_probe<3,1>(st_diffindex287, std::array<u64,3>{v_c51, 0, 0})) return;
          if (!slog::exists_probe<3,1>(st_diffindex288, std::array<u64,3>{v_c17, 0, 0})) return;
          if (!slog::exists_probe<3,1>(st_diffindex289, std::array<u64,3>{v_c18, 0, 0})) return;
          slog::join_probe<7,4>($sup9688x136x0x0x0index290, std::array<u64,7>{v_c7, v_c2, v_c17, v_c18, 0, 0, 0}, [&](const std::array<u64,7>& m351) {
            u64 v_c52 = m351[4]; u64 v_c6 = m351[5]; u64 v_c8 = m351[6];
            if (!slog::exists_probe<3,2>(st_diffindex291, std::array<u64,3>{v_c51, v_c52, 0})) return;
            if (!slog::exists_probe<3,2>(st_diffindex292, std::array<u64,3>{v_c6, v_c17, 0})) return;
            if (!slog::exists_probe<3,2>(st_diffindex293, std::array<u64,3>{v_c8, v_c18, 0})) return;
            slog::join_probe<5,4>(pbranchindex294, std::array<u64,5>{v_c2, v_c7, v_c6, v_c8, 0}, [&](const std::array<u64,5>& m352) {
              u64 v_c53 = m352[4];
              slog::join_probe<3,3>(st_diffindex295, std::array<u64,3>{v_c52, v_c53, v_c51}, [&](const std::array<u64,3>& m353) {
                slog::join_probe_old<3,2>(st_diffindex296, st_diffdelta301, std::array<u64,3>{v_c6, v_c17, 0}, [&](const std::array<u64,3>& m354) {
                  u64 v_c54 = m354[2];
                  slog::join_probe<2,2>(st_diff_ansindex297, std::array<u64,2>{v_c54, v_c10}, [&](const std::array<u64,2>& m355) {
                    slog::join_probe_old<3,2>(st_diffindex298, st_diffdelta302, std::array<u64,3>{v_c8, v_c18, 0}, [&](const std::array<u64,3>& m356) {
                      u64 v_c55 = m356[2];
                      slog::join_probe<2,2>(st_diff_ansindex299, std::array<u64,2>{v_c55, v_c33}, [&](const std::array<u64,2>& m357) {
                        slog::join_probe<2,1>(st_bld_ansindex300, std::array<u64,2>{v_c50, 0}, [&](const std::array<u64,2>& m358) {
                          u64 v_c11 = m358[1];
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c52, v_c11}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("set.slog:137", "delta:st_bld", _fires);
  
      if (!_done)
      {
        ReadTask303* _cont = new ReadTask303(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask303(db,b), false);
  // (crule (pre (let __trid8tci711 const81906d9241165d9f6a541e47) (let __trel8bT4712 consta10f76b4ec574de5d7b6908e) (let __tcol6BPh713 const5feceb66ffc86f38d952786c) (let __trel180X714 consta10f76b4ec574de5d7b6908e) (let __tcol8kWm715 const6b86b273ff34fce19d6b804e)) (scan $sup9688x142x0x0x0 __d0 l m n p q r u v) (body) (head (tycheck q (accept int) __trid8tci711 __trel8bT4712 __tcol6BPh713 (1 2 3 4 0)) (tycheck m (accept int) __trid8tci711 __trel180X714 __tcol8kWm715 (1 2 3 4 0)) (mkstruct st_msk (1 2 0) __5UZs710 q m)) set.slog:143 #f)
  class ReadTask359 : public slog::Task
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
      outer_rel = db->getRelation("$sup9688x142x0x0x0");
  
    }
    ReadTask359(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c56 = v_const81906d9241165d9f6a541e47;
      u64 v_c57 = v_consta10f76b4ec574de5d7b6908e;
      u64 v_c58 = v_const5feceb66ffc86f38d952786c;
      u64 v_c59 = v_consta10f76b4ec574de5d7b6908e;
      u64 v_c60 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c61 = _t[0];
        u64 v_c6 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c15 = _t[3];
        u64 v_c2 = _t[4];
        u64 v_c16 = _t[5];
        u64 v_c8 = _t[6];
        u64 v_c17 = _t[7];
        u64 v_c18 = _t[8];
        ++_fires;
        if (!(is_int(v_c16)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c56, v_c57, v_c58, v_c16}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c7)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c56, v_c59, v_c60, v_c7}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c16, v_c7}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("set.slog:143", "delta:$sup9688x142x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask359* _cont = new ReadTask359(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask359(db,b), false);
  // (crule (pre (let __tconst2in2504 const5feceb66ffc86f38d952786c)) (scan st_mem0 __t9V8P506 r k) (body (exists $sup9688x72x0x0x0 (1 5 0 2 3 4) 2 k r) (exists pbranch (4 0 1 2 3) 1 r) (exists st_mem0 (2 0 1) 1 k) (exists st_msk (1 2 0) 1 k) (join st_mem0_ans (0 1) 1 __t9V8P506 a) (join $sup9688x72x0x0x0 (1 5 0 2 3 4) 2 k r __t6Rw6503 l m p) (exists st_mem0 (2 0 1) 2 k __t6Rw6503) (exists st_msk (1 2 0) 2 k m) (exists st_msk_ans (1 0) 1 p) (join pbranch (1 2 3 4 0) 4 p m l r __t1XtO502) (join st_mem0 (0 1 2) 3 __t6Rw6503 __t1XtO502 k) (join-old st_msk (1 2 0) 2 (1 2 0) k m __t4A7W507) (join st_msk_ans (0 1) 2 __t4A7W507 p) (let __t9tLi505 (band k m)) (cmp gt __t9tLi505 __tconst2in2504)) (head (emit st_mem0_ans (0 1) __t6Rw6503 a)) set.slog:73 #f)
  class ReadTask374 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x72x0x0x0index360;  slog::Index** pbranchindex361;  slog::Index** st_mem0index362;  slog::Index** st_mskindex363;  slog::Index** st_mem0_ansindex364;  slog::Index** $sup9688x72x0x0x0index365;  slog::Index** st_mem0index366;  slog::Index** st_mskindex367;  slog::Index** st_msk_ansindex368;  slog::Index** pbranchindex369;  slog::Index** st_mem0index370;  slog::Index** st_mskindex371;  slog::Index** st_msk_ansindex372;  slog::Index** st_mskdelta373;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_mem0_ans");
      std::vector<u16> ord375({0, 1});
      slog::Relation* readrel376 = db->getRelation("st_mem0_ans");
      head_index[0] = readrel376->getIndex(ord375, false);
      outer_rel = db->getRelation("st_mem0");
      std::vector<u16> ord377({1, 5, 0, 2, 3, 4});
      slog::Relation* readrel378 = db->getRelation("$sup9688x72x0x0x0");
      $sup9688x72x0x0x0index360 = readrel378->getIndex(ord377, false);
      std::vector<u16> ord379({4, 0, 1, 2, 3});
      slog::Relation* readrel380 = db->getRelation("pbranch");
      pbranchindex361 = readrel380->getIndex(ord379, false);
      std::vector<u16> ord381({2, 0, 1});
      slog::Relation* readrel382 = db->getRelation("st_mem0");
      st_mem0index362 = readrel382->getIndex(ord381, false);
      std::vector<u16> ord383({1, 2, 0});
      slog::Relation* readrel384 = db->getRelation("st_msk");
      st_mskindex363 = readrel384->getIndex(ord383, false);
      std::vector<u16> ord385({0, 1});
      slog::Relation* readrel386 = db->getRelation("st_mem0_ans");
      st_mem0_ansindex364 = readrel386->getIndex(ord385, false);
      std::vector<u16> ord387({1, 5, 0, 2, 3, 4});
      slog::Relation* readrel388 = db->getRelation("$sup9688x72x0x0x0");
      $sup9688x72x0x0x0index365 = readrel388->getIndex(ord387, false);
      std::vector<u16> ord389({2, 0, 1});
      slog::Relation* readrel390 = db->getRelation("st_mem0");
      st_mem0index366 = readrel390->getIndex(ord389, false);
      std::vector<u16> ord391({1, 2, 0});
      slog::Relation* readrel392 = db->getRelation("st_msk");
      st_mskindex367 = readrel392->getIndex(ord391, false);
      std::vector<u16> ord393({1, 0});
      slog::Relation* readrel394 = db->getRelation("st_msk_ans");
      st_msk_ansindex368 = readrel394->getIndex(ord393, false);
      std::vector<u16> ord395({1, 2, 3, 4, 0});
      slog::Relation* readrel396 = db->getRelation("pbranch");
      pbranchindex369 = readrel396->getIndex(ord395, false);
      std::vector<u16> ord397({0, 1, 2});
      slog::Relation* readrel398 = db->getRelation("st_mem0");
      st_mem0index370 = readrel398->getIndex(ord397, false);
      std::vector<u16> ord399({1, 2, 0});
      slog::Relation* readrel400 = db->getRelation("st_msk");
      st_mskindex371 = readrel400->getIndex(ord399, false);
      std::vector<u16> ord401({1, 2, 0});
      slog::Relation* readrel402 = db->getRelation("st_msk");
      st_mskdelta373 = readrel402->getIndex(ord401, true);
      std::vector<u16> ord403({0, 1});
      slog::Relation* readrel404 = db->getRelation("st_msk_ans");
      st_msk_ansindex372 = readrel404->getIndex(ord403, false);
  
    }
    ReadTask374(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c62 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c63 = _t[0];
        u64 v_c8 = _t[1];
        u64 v_c1 = _t[2];
        if (!slog::exists_probe<6,2>($sup9688x72x0x0x0index360, std::array<u64,6>{v_c1, v_c8, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex361, std::array<u64,5>{v_c8, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mem0index362, std::array<u64,3>{v_c1, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mskindex363, std::array<u64,3>{v_c1, 0, 0})) return;
        slog::join_probe<2,1>(st_mem0_ansindex364, std::array<u64,2>{v_c63, 0}, [&](const std::array<u64,2>& m405) {
          u64 v_c64 = m405[1];
          slog::join_probe<6,2>($sup9688x72x0x0x0index365, std::array<u64,6>{v_c1, v_c8, 0, 0, 0, 0}, [&](const std::array<u64,6>& m406) {
            u64 v_c65 = m406[2]; u64 v_c6 = m406[3]; u64 v_c7 = m406[4]; u64 v_c2 = m406[5];
            if (!slog::exists_probe<3,2>(st_mem0index366, std::array<u64,3>{v_c1, v_c65, 0})) return;
            if (!slog::exists_probe<3,2>(st_mskindex367, std::array<u64,3>{v_c1, v_c7, 0})) return;
            if (!slog::exists_probe<2,1>(st_msk_ansindex368, std::array<u64,2>{v_c2, 0})) return;
            slog::join_probe<5,4>(pbranchindex369, std::array<u64,5>{v_c2, v_c7, v_c6, v_c8, 0}, [&](const std::array<u64,5>& m407) {
              u64 v_c66 = m407[4];
              slog::join_probe<3,3>(st_mem0index370, std::array<u64,3>{v_c65, v_c66, v_c1}, [&](const std::array<u64,3>& m408) {
                slog::join_probe_old<3,2>(st_mskindex371, st_mskdelta373, std::array<u64,3>{v_c1, v_c7, 0}, [&](const std::array<u64,3>& m409) {
                  u64 v_c67 = m409[2];
                  slog::join_probe<2,2>(st_msk_ansindex372, std::array<u64,2>{v_c67, v_c2}, [&](const std::array<u64,2>& m410) {
                    u64 v_c68 = _prim_band(db, v_c1, v_c7);
                    if (v_c68 == slog_error) { slog::emit_pending_error(db, "set.slog:73"); return; }
                    u64 v_c69 = _prim_gt(db, v_c68, v_c62);
                    if (v_c69 == slog_error) { slog::emit_pending_error(db, "set.slog:73"); return; }
                    if (!v_c69) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c65, v_c64}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:73", "delta:st_mem0", _fires);
  
      if (!_done)
      {
        ReadTask374* _cont = new ReadTask374(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask374(db,b), false);
  // (crule (pre (let __tconst2in2504 const5feceb66ffc86f38d952786c)) (scan pbranch __t1XtO502 p m l r) (body (exists st_mem0 (1 2 0) 1 __t1XtO502) (exists st_mem0 (1 2 0) 1 r) (exists st_msk (2 0 1) 1 m) (exists st_msk_ans (1 0) 1 p) (join $sup9688x72x0x0x0 (4 2 3 5 0 1) 4 p l m r __t6Rw6503 k) (join-old st_mem0 (0 1 2) 3 (0 1 2) __t6Rw6503 __t1XtO502 k) (exists st_msk (1 2 0) 2 k m) (join-old st_mem0 (1 2 0) 2 (1 2 0) r k __t9V8P506) (exists st_mem0_ans (0 1) 1 __t9V8P506) (join-old st_msk (1 2 0) 2 (1 2 0) k m __t4A7W507) (join st_msk_ans (0 1) 2 __t4A7W507 p) (join st_mem0_ans (0 1) 1 __t9V8P506 a) (let __t9tLi505 (band k m)) (cmp gt __t9tLi505 __tconst2in2504)) (head (emit st_mem0_ans (0 1) __t6Rw6503 a)) set.slog:73 #f)
  class ReadTask427 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_mem0index412;  slog::Index** st_mem0index413;  slog::Index** st_mskindex414;  slog::Index** st_msk_ansindex415;  slog::Index** $sup9688x72x0x0x0index416;  slog::Index** st_mem0index417;  slog::Index** st_mskindex418;  slog::Index** st_mem0index419;  slog::Index** st_mem0_ansindex420;  slog::Index** st_mskindex421;  slog::Index** st_msk_ansindex422;  slog::Index** st_mem0_ansindex423;  slog::Index** st_mem0delta424;  slog::Index** st_mem0delta425;  slog::Index** st_mskdelta426;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_mem0_ans");
      std::vector<u16> ord428({0, 1});
      slog::Relation* readrel429 = db->getRelation("st_mem0_ans");
      head_index[0] = readrel429->getIndex(ord428, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord430({1, 2, 0});
      slog::Relation* readrel431 = db->getRelation("st_mem0");
      st_mem0index412 = readrel431->getIndex(ord430, false);
      std::vector<u16> ord432({1, 2, 0});
      slog::Relation* readrel433 = db->getRelation("st_mem0");
      st_mem0index413 = readrel433->getIndex(ord432, false);
      std::vector<u16> ord434({2, 0, 1});
      slog::Relation* readrel435 = db->getRelation("st_msk");
      st_mskindex414 = readrel435->getIndex(ord434, false);
      std::vector<u16> ord436({1, 0});
      slog::Relation* readrel437 = db->getRelation("st_msk_ans");
      st_msk_ansindex415 = readrel437->getIndex(ord436, false);
      std::vector<u16> ord438({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel439 = db->getRelation("$sup9688x72x0x0x0");
      $sup9688x72x0x0x0index416 = readrel439->getIndex(ord438, false);
      std::vector<u16> ord440({0, 1, 2});
      slog::Relation* readrel441 = db->getRelation("st_mem0");
      st_mem0index417 = readrel441->getIndex(ord440, false);
      std::vector<u16> ord442({0, 1, 2});
      slog::Relation* readrel443 = db->getRelation("st_mem0");
      st_mem0delta424 = readrel443->getIndex(ord442, true);
      std::vector<u16> ord444({1, 2, 0});
      slog::Relation* readrel445 = db->getRelation("st_msk");
      st_mskindex418 = readrel445->getIndex(ord444, false);
      std::vector<u16> ord446({1, 2, 0});
      slog::Relation* readrel447 = db->getRelation("st_mem0");
      st_mem0index419 = readrel447->getIndex(ord446, false);
      std::vector<u16> ord448({1, 2, 0});
      slog::Relation* readrel449 = db->getRelation("st_mem0");
      st_mem0delta425 = readrel449->getIndex(ord448, true);
      std::vector<u16> ord450({0, 1});
      slog::Relation* readrel451 = db->getRelation("st_mem0_ans");
      st_mem0_ansindex420 = readrel451->getIndex(ord450, false);
      std::vector<u16> ord452({1, 2, 0});
      slog::Relation* readrel453 = db->getRelation("st_msk");
      st_mskindex421 = readrel453->getIndex(ord452, false);
      std::vector<u16> ord454({1, 2, 0});
      slog::Relation* readrel455 = db->getRelation("st_msk");
      st_mskdelta426 = readrel455->getIndex(ord454, true);
      std::vector<u16> ord456({0, 1});
      slog::Relation* readrel457 = db->getRelation("st_msk_ans");
      st_msk_ansindex422 = readrel457->getIndex(ord456, false);
      std::vector<u16> ord458({0, 1});
      slog::Relation* readrel459 = db->getRelation("st_mem0_ans");
      st_mem0_ansindex423 = readrel459->getIndex(ord458, false);
  
    }
    ReadTask427(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c62 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c66 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c6 = _t[3];
        u64 v_c8 = _t[4];
        if (!slog::exists_probe<3,1>(st_mem0index412, std::array<u64,3>{v_c66, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mem0index413, std::array<u64,3>{v_c8, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mskindex414, std::array<u64,3>{v_c7, 0, 0})) return;
        if (!slog::exists_probe<2,1>(st_msk_ansindex415, std::array<u64,2>{v_c2, 0})) return;
        slog::join_probe<6,4>($sup9688x72x0x0x0index416, std::array<u64,6>{v_c2, v_c6, v_c7, v_c8, 0, 0}, [&](const std::array<u64,6>& m460) {
          u64 v_c65 = m460[4]; u64 v_c1 = m460[5];
          slog::join_probe_old<3,3>(st_mem0index417, st_mem0delta424, std::array<u64,3>{v_c65, v_c66, v_c1}, [&](const std::array<u64,3>& m461) {
            if (!slog::exists_probe<3,2>(st_mskindex418, std::array<u64,3>{v_c1, v_c7, 0})) return;
            slog::join_probe_old<3,2>(st_mem0index419, st_mem0delta425, std::array<u64,3>{v_c8, v_c1, 0}, [&](const std::array<u64,3>& m462) {
              u64 v_c63 = m462[2];
              if (!slog::exists_probe<2,1>(st_mem0_ansindex420, std::array<u64,2>{v_c63, 0})) return;
              slog::join_probe_old<3,2>(st_mskindex421, st_mskdelta426, std::array<u64,3>{v_c1, v_c7, 0}, [&](const std::array<u64,3>& m463) {
                u64 v_c67 = m463[2];
                slog::join_probe<2,2>(st_msk_ansindex422, std::array<u64,2>{v_c67, v_c2}, [&](const std::array<u64,2>& m464) {
                  slog::join_probe<2,1>(st_mem0_ansindex423, std::array<u64,2>{v_c63, 0}, [&](const std::array<u64,2>& m465) {
                    u64 v_c64 = m465[1];
                    u64 v_c68 = _prim_band(db, v_c1, v_c7);
                    if (v_c68 == slog_error) { slog::emit_pending_error(db, "set.slog:73"); return; }
                    u64 v_c70 = _prim_gt(db, v_c68, v_c62);
                    if (v_c70 == slog_error) { slog::emit_pending_error(db, "set.slog:73"); return; }
                    if (!v_c70) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c65, v_c64}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:73", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask427* _cont = new ReadTask427(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask427(db,b), false);
  // (crule (pre) (scan pbranch __t0y5a8 p m l r) (body (join-old st_diff (1 2 0) 1 (1 2 0) __t0y5a8 __t9yhk7 __t2Ttf9) (join pbranch (0 1 2 3 4) 1 __t9yhk7 q n u v) (cmp lt m n)) (head (emit $sup9688x154x0x0x0 (0 1 2 3 4 5 6 7 8) __t2Ttf9 l m n p q r u v)) set.slog:155 #f)
  class ReadTask470 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_diffindex467;  slog::Index** pbranchindex468;  slog::Index** st_diffdelta469;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x154x0x0x0");
      std::vector<u16> ord471({0, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel472 = db->getRelation("$sup9688x154x0x0x0");
      head_index[0] = readrel472->getIndex(ord471, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord473({1, 2, 0});
      slog::Relation* readrel474 = db->getRelation("st_diff");
      st_diffindex467 = readrel474->getIndex(ord473, false);
      std::vector<u16> ord475({1, 2, 0});
      slog::Relation* readrel476 = db->getRelation("st_diff");
      st_diffdelta469 = readrel476->getIndex(ord475, true);
      std::vector<u16> ord477({0, 1, 2, 3, 4});
      slog::Relation* readrel478 = db->getRelation("pbranch");
      pbranchindex468 = readrel478->getIndex(ord477, false);
  
    }
    ReadTask470(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c71 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c6 = _t[3];
        u64 v_c8 = _t[4];
        slog::join_probe_old<3,1>(st_diffindex467, st_diffdelta469, std::array<u64,3>{v_c71, 0, 0}, [&](const std::array<u64,3>& m479) {
          u64 v_c72 = m479[1]; u64 v_c73 = m479[2];
          slog::join_probe<5,1>(pbranchindex468, std::array<u64,5>{v_c72, 0, 0, 0, 0}, [&](const std::array<u64,5>& m480) {
            u64 v_c16 = m480[1]; u64 v_c15 = m480[2]; u64 v_c17 = m480[3]; u64 v_c18 = m480[4];
            u64 v_c74 = _prim_lt(db, v_c7, v_c15);
            if (v_c74 == slog_error) { slog::emit_pending_error(db, "set.slog:155"); return; }
            if (!v_c74) return;
            ++_fires;
            slog::emit<9>(head_rel[0], head_index[0], newbatch[0], std::array<u64,9>{v_c73, v_c6, v_c7, v_c15, v_c2, v_c16, v_c8, v_c17, v_c18}, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:155", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask470* _cont = new ReadTask470(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask470(db,b), false);
  // (crule (pre (let __trid1xrb1094 constf95dfec4ee2675891829b965) (let __trel8PqH1095 consta10f76b4ec574de5d7b6908e) (let __tcol56T31096 const5feceb66ffc86f38d952786c) (let __trel3jxi1097 consta10f76b4ec574de5d7b6908e) (let __tcol6Mha1098 const6b86b273ff34fce19d6b804e)) (scan $sup9688x114x0x0x0 __d0 l m n p q r u v) (body) (head (tycheck p (accept int) __trid1xrb1094 __trel8PqH1095 __tcol56T31096 (1 2 3 4 0)) (tycheck n (accept int) __trid1xrb1094 __trel3jxi1097 __tcol6Mha1098 (1 2 3 4 0)) (mkstruct st_msk (1 2 0) __5O281093 p n)) set.slog:115 #f)
  class ReadTask482 : public slog::Task
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
      outer_rel = db->getRelation("$sup9688x114x0x0x0");
  
    }
    ReadTask482(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c75 = v_constf95dfec4ee2675891829b965;
      u64 v_c76 = v_consta10f76b4ec574de5d7b6908e;
      u64 v_c77 = v_const5feceb66ffc86f38d952786c;
      u64 v_c78 = v_consta10f76b4ec574de5d7b6908e;
      u64 v_c79 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c61 = _t[0];
        u64 v_c6 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c15 = _t[3];
        u64 v_c2 = _t[4];
        u64 v_c16 = _t[5];
        u64 v_c8 = _t[6];
        u64 v_c17 = _t[7];
        u64 v_c18 = _t[8];
        ++_fires;
        if (!(is_int(v_c2)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c75, v_c76, v_c77, v_c2}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c15)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c75, v_c78, v_c79, v_c15}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c2, v_c15}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("set.slog:115", "delta:$sup9688x114x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask482* _cont = new ReadTask482(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask482(db,b), false);
  // (crule (pre (let __tconst3u0P481 const6b86b273ff34fce19d6b804e)) (scan pbranch __t64JH479 p m l r) (body (join-old st_del (1 2 0) 1 (1 2 0) __t64JH479 k __t1Omm480) (let __t5Pxk482 (band k m)) (cmp lt __t5Pxk482 __tconst3u0P481)) (head (emit $sup9688x88x0x0x0 (4 3 5 2 0 1) p m r l __t1Omm480 k)) set.slog:89 #f)
  class ReadTask485 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_delindex483;  slog::Index** st_deldelta484;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x88x0x0x0");
      std::vector<u16> ord486({4, 3, 5, 2, 0, 1});
      slog::Relation* readrel487 = db->getRelation("$sup9688x88x0x0x0");
      head_index[0] = readrel487->getIndex(ord486, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord488({1, 2, 0});
      slog::Relation* readrel489 = db->getRelation("st_del");
      st_delindex483 = readrel489->getIndex(ord488, false);
      std::vector<u16> ord490({1, 2, 0});
      slog::Relation* readrel491 = db->getRelation("st_del");
      st_deldelta484 = readrel491->getIndex(ord490, true);
  
    }
    ReadTask485(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c80 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c81 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c6 = _t[3];
        u64 v_c8 = _t[4];
        slog::join_probe_old<3,1>(st_delindex483, st_deldelta484, std::array<u64,3>{v_c81, 0, 0}, [&](const std::array<u64,3>& m492) {
          u64 v_c1 = m492[1]; u64 v_c82 = m492[2];
          u64 v_c83 = _prim_band(db, v_c1, v_c7);
          if (v_c83 == slog_error) { slog::emit_pending_error(db, "set.slog:89"); return; }
          u64 v_c84 = _prim_lt(db, v_c83, v_c80);
          if (v_c84 == slog_error) { slog::emit_pending_error(db, "set.slog:89"); return; }
          if (!v_c84) return;
          ++_fires;
          slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c2, v_c7, v_c8, v_c6, v_c82, v_c1}, std::array<u16,6>{4, 3, 5, 2, 0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:89", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask485* _cont = new ReadTask485(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask485(db,b), false);
  // (crule (pre (let __tconst0v7T491 const5feceb66ffc86f38d952786c)) (scan st_bld __t8CKV493 p m l __v0) (body (exists $sup9688x90x0x0x0 (4 2 3 5 0 1) 3 p l m) (exists st_msk (2 0 1) 1 m) (exists st_msk_ans (1 0) 1 p) (exists st_del_ans (1 0) 1 __v0) (exists st_bld_ans (0 1) 1 __t8CKV493) (join pbranch (1 2 3 4 0) 3 p m l r __t4hkT489) (exists st_del (1 2 0) 1 __t4hkT489) (exists st_del (1 2 0) 1 r) (join $sup9688x90x0x0x0 (4 2 3 5 0 1) 4 p l m r __t3j4h490 k) (join st_del (0 2 1) 3 __t3j4h490 k __t4hkT489) (exists st_del (1 2 0) 2 r k) (join-old st_msk (1 2 0) 2 (1 2 0) k m __t44Py494) (join st_msk_ans (0 1) 2 __t44Py494 p) (join-old st_del (1 2 0) 2 (1 2 0) r k __t9BRr495) (join st_del_ans (0 1) 2 __t9BRr495 __v0) (join st_bld_ans (0 1) 1 __t8CKV493 res) (let __t3zgo492 (band k m)) (cmp gt __t3zgo492 __tconst0v7T491)) (head (emit st_del_ans (0 1) __t3j4h490 res)) set.slog:91 #f)
  class ReadTask512 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x90x0x0x0index494;  slog::Index** st_mskindex495;  slog::Index** st_msk_ansindex496;  slog::Index** st_del_ansindex497;  slog::Index** st_bld_ansindex498;  slog::Index** pbranchindex499;  slog::Index** st_delindex500;  slog::Index** st_delindex501;  slog::Index** $sup9688x90x0x0x0index502;  slog::Index** st_delindex503;  slog::Index** st_delindex504;  slog::Index** st_mskindex505;  slog::Index** st_msk_ansindex506;  slog::Index** st_delindex507;  slog::Index** st_del_ansindex508;  slog::Index** st_bld_ansindex509;  slog::Index** st_mskdelta510;  slog::Index** st_deldelta511;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_del_ans");
      std::vector<u16> ord513({0, 1});
      slog::Relation* readrel514 = db->getRelation("st_del_ans");
      head_index[0] = readrel514->getIndex(ord513, false);
      outer_rel = db->getRelation("st_bld");
      std::vector<u16> ord515({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel516 = db->getRelation("$sup9688x90x0x0x0");
      $sup9688x90x0x0x0index494 = readrel516->getIndex(ord515, false);
      std::vector<u16> ord517({2, 0, 1});
      slog::Relation* readrel518 = db->getRelation("st_msk");
      st_mskindex495 = readrel518->getIndex(ord517, false);
      std::vector<u16> ord519({1, 0});
      slog::Relation* readrel520 = db->getRelation("st_msk_ans");
      st_msk_ansindex496 = readrel520->getIndex(ord519, false);
      std::vector<u16> ord521({1, 0});
      slog::Relation* readrel522 = db->getRelation("st_del_ans");
      st_del_ansindex497 = readrel522->getIndex(ord521, false);
      std::vector<u16> ord523({0, 1});
      slog::Relation* readrel524 = db->getRelation("st_bld_ans");
      st_bld_ansindex498 = readrel524->getIndex(ord523, false);
      std::vector<u16> ord525({1, 2, 3, 4, 0});
      slog::Relation* readrel526 = db->getRelation("pbranch");
      pbranchindex499 = readrel526->getIndex(ord525, false);
      std::vector<u16> ord527({1, 2, 0});
      slog::Relation* readrel528 = db->getRelation("st_del");
      st_delindex500 = readrel528->getIndex(ord527, false);
      std::vector<u16> ord529({1, 2, 0});
      slog::Relation* readrel530 = db->getRelation("st_del");
      st_delindex501 = readrel530->getIndex(ord529, false);
      std::vector<u16> ord531({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel532 = db->getRelation("$sup9688x90x0x0x0");
      $sup9688x90x0x0x0index502 = readrel532->getIndex(ord531, false);
      std::vector<u16> ord533({0, 2, 1});
      slog::Relation* readrel534 = db->getRelation("st_del");
      st_delindex503 = readrel534->getIndex(ord533, false);
      std::vector<u16> ord535({1, 2, 0});
      slog::Relation* readrel536 = db->getRelation("st_del");
      st_delindex504 = readrel536->getIndex(ord535, false);
      std::vector<u16> ord537({1, 2, 0});
      slog::Relation* readrel538 = db->getRelation("st_msk");
      st_mskindex505 = readrel538->getIndex(ord537, false);
      std::vector<u16> ord539({1, 2, 0});
      slog::Relation* readrel540 = db->getRelation("st_msk");
      st_mskdelta510 = readrel540->getIndex(ord539, true);
      std::vector<u16> ord541({0, 1});
      slog::Relation* readrel542 = db->getRelation("st_msk_ans");
      st_msk_ansindex506 = readrel542->getIndex(ord541, false);
      std::vector<u16> ord543({1, 2, 0});
      slog::Relation* readrel544 = db->getRelation("st_del");
      st_delindex507 = readrel544->getIndex(ord543, false);
      std::vector<u16> ord545({1, 2, 0});
      slog::Relation* readrel546 = db->getRelation("st_del");
      st_deldelta511 = readrel546->getIndex(ord545, true);
      std::vector<u16> ord547({0, 1});
      slog::Relation* readrel548 = db->getRelation("st_del_ans");
      st_del_ansindex508 = readrel548->getIndex(ord547, false);
      std::vector<u16> ord549({0, 1});
      slog::Relation* readrel550 = db->getRelation("st_bld_ans");
      st_bld_ansindex509 = readrel550->getIndex(ord549, false);
  
    }
    ReadTask512(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c85 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c86 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c6 = _t[3];
        u64 v_c10 = _t[4];
        if (!slog::exists_probe<6,3>($sup9688x90x0x0x0index494, std::array<u64,6>{v_c2, v_c6, v_c7, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mskindex495, std::array<u64,3>{v_c7, 0, 0})) return;
        if (!slog::exists_probe<2,1>(st_msk_ansindex496, std::array<u64,2>{v_c2, 0})) return;
        if (!slog::exists_probe<2,1>(st_del_ansindex497, std::array<u64,2>{v_c10, 0})) return;
        if (!slog::exists_probe<2,1>(st_bld_ansindex498, std::array<u64,2>{v_c86, 0})) return;
        slog::join_probe<5,3>(pbranchindex499, std::array<u64,5>{v_c2, v_c7, v_c6, 0, 0}, [&](const std::array<u64,5>& m551) {
          u64 v_c8 = m551[3]; u64 v_c87 = m551[4];
          if (!slog::exists_probe<3,1>(st_delindex500, std::array<u64,3>{v_c87, 0, 0})) return;
          if (!slog::exists_probe<3,1>(st_delindex501, std::array<u64,3>{v_c8, 0, 0})) return;
          slog::join_probe<6,4>($sup9688x90x0x0x0index502, std::array<u64,6>{v_c2, v_c6, v_c7, v_c8, 0, 0}, [&](const std::array<u64,6>& m552) {
            u64 v_c88 = m552[4]; u64 v_c1 = m552[5];
            slog::join_probe<3,3>(st_delindex503, std::array<u64,3>{v_c88, v_c1, v_c87}, [&](const std::array<u64,3>& m553) {
              if (!slog::exists_probe<3,2>(st_delindex504, std::array<u64,3>{v_c8, v_c1, 0})) return;
              slog::join_probe_old<3,2>(st_mskindex505, st_mskdelta510, std::array<u64,3>{v_c1, v_c7, 0}, [&](const std::array<u64,3>& m554) {
                u64 v_c89 = m554[2];
                slog::join_probe<2,2>(st_msk_ansindex506, std::array<u64,2>{v_c89, v_c2}, [&](const std::array<u64,2>& m555) {
                  slog::join_probe_old<3,2>(st_delindex507, st_deldelta511, std::array<u64,3>{v_c8, v_c1, 0}, [&](const std::array<u64,3>& m556) {
                    u64 v_c90 = m556[2];
                    slog::join_probe<2,2>(st_del_ansindex508, std::array<u64,2>{v_c90, v_c10}, [&](const std::array<u64,2>& m557) {
                      slog::join_probe<2,1>(st_bld_ansindex509, std::array<u64,2>{v_c86, 0}, [&](const std::array<u64,2>& m558) {
                        u64 v_c11 = m558[1];
                        u64 v_c91 = _prim_band(db, v_c1, v_c7);
                        if (v_c91 == slog_error) { slog::emit_pending_error(db, "set.slog:91"); return; }
                        u64 v_c92 = _prim_gt(db, v_c91, v_c85);
                        if (v_c92 == slog_error) { slog::emit_pending_error(db, "set.slog:91"); return; }
                        if (!v_c92) return;
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c88, v_c11}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("set.slog:91", "delta:st_bld", _fires);
  
      if (!_done)
      {
        ReadTask512* _cont = new ReadTask512(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask512(db,b), false);
  // (crule (pre (let __trid6n3v1100 const2d2149bb550ad5e39952d8f4) (let __trel74k31101 consta10f76b4ec574de5d7b6908e) (let __tcol5UMS1102 const5feceb66ffc86f38d952786c) (let __trel0ODM1103 consta10f76b4ec574de5d7b6908e) (let __tcol8mcy1104 const6b86b273ff34fce19d6b804e)) (scan $sup9688x117x0x0x0 __d0 l m n p q r u v) (body) (head (tycheck p (accept int) __trid6n3v1100 __trel74k31101 __tcol5UMS1102 (1 2 3 4 0)) (tycheck n (accept int) __trid6n3v1100 __trel0ODM1103 __tcol8mcy1104 (1 2 3 4 0)) (mkstruct st_msk (1 2 0) __21ah1099 p n)) set.slog:118 #f)
  class ReadTask560 : public slog::Task
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
      outer_rel = db->getRelation("$sup9688x117x0x0x0");
  
    }
    ReadTask560(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c93 = v_const2d2149bb550ad5e39952d8f4;
      u64 v_c94 = v_consta10f76b4ec574de5d7b6908e;
      u64 v_c95 = v_const5feceb66ffc86f38d952786c;
      u64 v_c96 = v_consta10f76b4ec574de5d7b6908e;
      u64 v_c97 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c61 = _t[0];
        u64 v_c6 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c15 = _t[3];
        u64 v_c2 = _t[4];
        u64 v_c16 = _t[5];
        u64 v_c8 = _t[6];
        u64 v_c17 = _t[7];
        u64 v_c18 = _t[8];
        ++_fires;
        if (!(is_int(v_c2)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c93, v_c94, v_c95, v_c2}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c15)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c93, v_c96, v_c97, v_c15}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c2, v_c15}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("set.slog:118", "delta:$sup9688x117x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask560* _cont = new ReadTask560(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask560(db,b), false);
  // (crule (pre (let __tconst03UB810 conste3776bfed7f405de8017ecfa) (let __tconst71XF295 const6b86b273ff34fce19d6b804e)) (scan pleaf __t1D2a292 k) (body (exists st_mem0_ans (1 0) 1 __tconst71XF295) (exists st_mem0 (2 0 1) 1 k) (exists st_diff (1 2 0) 1 __t1D2a292) (join _enum (1 0) 1 __tconst03UB810 __t26at291) (join st_mem0_ans (1 0) 1 __tconst71XF295 __t38OP294) (join-old st_mem0 (2 0 1) 2 (2 0 1) k __t38OP294 t) (join-old st_diff (1 2 0) 2 (1 2 0) __t1D2a292 t __t8FIc293)) (head (emit st_diff_ans (0 1) __t8FIc293 __t26at291)) set.slog:135 #f)
  class ReadTask570 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_mem0_ansindex561;  slog::Index** st_mem0index562;  slog::Index** st_diffindex563;  slog::Index** _enumindex564;  slog::Index** st_mem0_ansindex565;  slog::Index** st_mem0index566;  slog::Index** st_diffindex567;  slog::Index** st_mem0delta568;  slog::Index** st_diffdelta569;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord571({0, 1});
      slog::Relation* readrel572 = db->getRelation("st_diff_ans");
      head_index[0] = readrel572->getIndex(ord571, false);
      outer_rel = db->getRelation("pleaf");
      std::vector<u16> ord573({1, 0});
      slog::Relation* readrel574 = db->getRelation("st_mem0_ans");
      st_mem0_ansindex561 = readrel574->getIndex(ord573, false);
      std::vector<u16> ord575({2, 0, 1});
      slog::Relation* readrel576 = db->getRelation("st_mem0");
      st_mem0index562 = readrel576->getIndex(ord575, false);
      std::vector<u16> ord577({1, 2, 0});
      slog::Relation* readrel578 = db->getRelation("st_diff");
      st_diffindex563 = readrel578->getIndex(ord577, false);
      std::vector<u16> ord579({1, 0});
      slog::Relation* readrel580 = db->getRelation("_enum");
      _enumindex564 = readrel580->getIndex(ord579, false);
      std::vector<u16> ord581({1, 0});
      slog::Relation* readrel582 = db->getRelation("st_mem0_ans");
      st_mem0_ansindex565 = readrel582->getIndex(ord581, false);
      std::vector<u16> ord583({2, 0, 1});
      slog::Relation* readrel584 = db->getRelation("st_mem0");
      st_mem0index566 = readrel584->getIndex(ord583, false);
      std::vector<u16> ord585({2, 0, 1});
      slog::Relation* readrel586 = db->getRelation("st_mem0");
      st_mem0delta568 = readrel586->getIndex(ord585, true);
      std::vector<u16> ord587({1, 2, 0});
      slog::Relation* readrel588 = db->getRelation("st_diff");
      st_diffindex567 = readrel588->getIndex(ord587, false);
      std::vector<u16> ord589({1, 2, 0});
      slog::Relation* readrel590 = db->getRelation("st_diff");
      st_diffdelta569 = readrel590->getIndex(ord589, true);
  
    }
    ReadTask570(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c98 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c99 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c100 = _t[0];
        u64 v_c1 = _t[1];
        if (!slog::exists_probe<2,1>(st_mem0_ansindex561, std::array<u64,2>{v_c99, 0})) return;
        if (!slog::exists_probe<3,1>(st_mem0index562, std::array<u64,3>{v_c1, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_diffindex563, std::array<u64,3>{v_c100, 0, 0})) return;
        slog::join_probe<2,1>(_enumindex564, std::array<u64,2>{v_c98, 0}, [&](const std::array<u64,2>& m591) {
          u64 v_c101 = m591[1];
          slog::join_probe<2,1>(st_mem0_ansindex565, std::array<u64,2>{v_c99, 0}, [&](const std::array<u64,2>& m592) {
            u64 v_c102 = m592[1];
            slog::join_probe_old<3,2>(st_mem0index566, st_mem0delta568, std::array<u64,3>{v_c1, v_c102, 0}, [&](const std::array<u64,3>& m593) {
              u64 v_c103 = m593[2];
              slog::join_probe_old<3,2>(st_diffindex567, st_diffdelta569, std::array<u64,3>{v_c100, v_c103, 0}, [&](const std::array<u64,3>& m594) {
                u64 v_c104 = m594[2];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c104, v_c101}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:135", "delta:pleaf", _fires);
  
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
  // (crule (pre (let __tconst8lGk118 const6b86b273ff34fce19d6b804e)) (scan pbranch __t8tCR116 p m l r) (body (join-old st_mem0 (1 2 0) 1 (1 2 0) __t8tCR116 k __t5R5p117) (let __t7KqF119 (band k m)) (cmp lt __t7KqF119 __tconst8lGk118)) (head (emit $sup9688x70x0x0x0 (4 2 3 5 0 1) p l m r __t5R5p117 k)) set.slog:71 #f)
  class ReadTask597 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_mem0index595;  slog::Index** st_mem0delta596;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x70x0x0x0");
      std::vector<u16> ord598({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel599 = db->getRelation("$sup9688x70x0x0x0");
      head_index[0] = readrel599->getIndex(ord598, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord600({1, 2, 0});
      slog::Relation* readrel601 = db->getRelation("st_mem0");
      st_mem0index595 = readrel601->getIndex(ord600, false);
      std::vector<u16> ord602({1, 2, 0});
      slog::Relation* readrel603 = db->getRelation("st_mem0");
      st_mem0delta596 = readrel603->getIndex(ord602, true);
  
    }
    ReadTask597(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c105 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c106 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c6 = _t[3];
        u64 v_c8 = _t[4];
        slog::join_probe_old<3,1>(st_mem0index595, st_mem0delta596, std::array<u64,3>{v_c106, 0, 0}, [&](const std::array<u64,3>& m604) {
          u64 v_c1 = m604[1]; u64 v_c107 = m604[2];
          u64 v_c108 = _prim_band(db, v_c1, v_c7);
          if (v_c108 == slog_error) { slog::emit_pending_error(db, "set.slog:71"); return; }
          u64 v_c109 = _prim_lt(db, v_c108, v_c105);
          if (v_c109 == slog_error) { slog::emit_pending_error(db, "set.slog:71"); return; }
          if (!v_c109) return;
          ++_fires;
          slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c2, v_c6, v_c7, v_c8, v_c107, v_c1}, std::array<u16,6>{4, 2, 3, 5, 0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:71", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask597* _cont = new ReadTask597(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask597(db,b), false);
  // (crule (pre (let __trid6dB61075 const81906d9241165d9f6a541e47) (let __trel9A581076 const1d9eff40314d54862fee3942) (let __tcol5CMk1077 const5feceb66ffc86f38d952786c) (let __trel3pms1078 const66633592860a63ea6408b433) (let __tcol8lFk1079 const5feceb66ffc86f38d952786c) (let __trel1Y1b1080 const66633592860a63ea6408b433) (let __tcol6op81081 const6b86b273ff34fce19d6b804e) (let __trel1Ra51082 const66633592860a63ea6408b433) (let __tcol4LRb1083 constd4735e3a265e16eee03f5971) (let __trel03mI1084 const66633592860a63ea6408b433) (let __tcol3kOv1085 const4e07408562bedb8b60ce05c1)) (scan $sup9688x142x0x0x0 __d0 l m n p q r u v) (body) (head (tycheck r (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid6dB61075 __trel9A581076 __tcol5CMk1077 (1 2 3 4 0)) (tycheck q (accept int) __trid6dB61075 __trel3pms1078 __tcol8lFk1079 (1 2 3 4 0)) (tycheck n (accept int) __trid6dB61075 __trel1Y1b1080 __tcol6op81081 (1 2 3 4 0)) (tycheck u (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid6dB61075 __trel1Ra51082 __tcol4LRb1083 (1 2 3 4 0)) (tycheck v (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid6dB61075 __trel03mI1084 __tcol3kOv1085 (1 2 3 4 0)) (emit-temp temp4PCZ1408 n q r u v) (mkstruct pbranch (1 2 3 4 0) __t3E7r174 q n u v)) set.slog:143 #f)
  class ReadTask609 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[7];
    slog::Index** head_index[7];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid607;  u32 sid606;  u32 sid608;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("malformed_deduction");
      head_rel[3] = db->getRelation("malformed_deduction");
      head_rel[4] = db->getRelation("malformed_deduction");
      head_rel[5] = db->getRelation("temp4PCZ1408");
      head_rel[6] = db->getRelation("pbranch");
      outer_rel = db->getRelation("$sup9688x142x0x0x0");
      sid607 = db->getRelation("_enum")->getStructId();
      sid606 = db->getRelation("pbranch")->getStructId();
      sid608 = db->getRelation("pleaf")->getStructId();
  
    }
    ReadTask609(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c110 = v_const81906d9241165d9f6a541e47;
      u64 v_c111 = v_const1d9eff40314d54862fee3942;
      u64 v_c112 = v_const5feceb66ffc86f38d952786c;
      u64 v_c113 = v_const66633592860a63ea6408b433;
      u64 v_c114 = v_const5feceb66ffc86f38d952786c;
      u64 v_c115 = v_const66633592860a63ea6408b433;
      u64 v_c116 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c117 = v_const66633592860a63ea6408b433;
      u64 v_c118 = v_constd4735e3a265e16eee03f5971;
      u64 v_c119 = v_const66633592860a63ea6408b433;
      u64 v_c120 = v_const4e07408562bedb8b60ce05c1;
  
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
        u64 v_c61 = _t[0];
        u64 v_c6 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c15 = _t[3];
        u64 v_c2 = _t[4];
        u64 v_c16 = _t[5];
        u64 v_c8 = _t[6];
        u64 v_c17 = _t[7];
        u64 v_c18 = _t[8];
        ++_fires;
        if (!((is_struct(v_c8) && (decode_struct_id(v_c8) == sid606 || decode_struct_id(v_c8) == sid607 || decode_struct_id(v_c8) == sid608))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c110, v_c111, v_c112, v_c8}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c16)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c110, v_c113, v_c114, v_c16}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c15)))
        {
          slog::emit_struct<5>(head_rel[2], newbatch[2], std::array<u64,4>{v_c110, v_c115, v_c116, v_c15}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c17) && (decode_struct_id(v_c17) == sid606 || decode_struct_id(v_c17) == sid607 || decode_struct_id(v_c17) == sid608))))
        {
          slog::emit_struct<5>(head_rel[3], newbatch[3], std::array<u64,4>{v_c110, v_c117, v_c118, v_c17}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c18) && (decode_struct_id(v_c18) == sid606 || decode_struct_id(v_c18) == sid607 || decode_struct_id(v_c18) == sid608))))
        {
          slog::emit_struct<5>(head_rel[4], newbatch[4], std::array<u64,4>{v_c110, v_c119, v_c120, v_c18}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_temp<5>(head_rel[5], newbatch[5], std::array<u64,5>{v_c15, v_c16, v_c8, v_c17, v_c18});
        slog::emit_struct<5>(head_rel[6], newbatch[6], std::array<u64,4>{v_c16, v_c15, v_c17, v_c18}, std::array<u16,5>{1, 2, 3, 4, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
        head_rel[5]->sendBatch(newbatch[5]);
        head_rel[6]->sendBatch(newbatch[6]);
  
      if (_fires) db->bumpFires("set.slog:143", "delta:$sup9688x142x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask609* _cont = new ReadTask609(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask609(db,b), false);
  // (crule (pre (let __tconst19LZ687 conste3776bfed7f405de8017ecfa) (let __tconst6nio451 constef2d127de37b942baad06145) (let __tconst5Crw454 constd4735e3a265e16eee03f5971) (let __tconst7cMm457 const2c624232cdd221771294dfbb) (let __tconst776G459 const6b86b273ff34fce19d6b804e)) (probe st_ins (2 0 1) 1 __tconst6nio451 __t6TRN453 __t82EP455) (body (join _enum (0 1) 2 __t82EP455 __tconst19LZ687) (exists st_ins_ans (0 1) 1 __t6TRN453) (exists st_ins (2 0 1) 1 __tconst7cMm457) (exists st_ins (2 0 1) 1 __tconst776G459) (join-old st_ins (1 2 0) 2 (1 2 0) __t82EP455 __tconst5Crw454 __t7k0a456) (exists st_ins_ans (0 1) 1 __t7k0a456) (join st_ins_ans (0 1) 1 __t6TRN453 __v0) (join-old st_ins (1 2 0) 2 (1 2 0) __v0 __tconst7cMm457 __t6eAo458) (exists st_ins_ans (0 1) 1 __t6eAo458) (join st_ins_ans (0 1) 1 __t7k0a456 __v1) (join-old st_ins (1 2 0) 2 (1 2 0) __v1 __tconst776G459 __t7DB2460) (exists st_ins_ans (0 1) 1 __t7DB2460) (join st_ins_ans (0 1) 1 __t6eAo458 a) (join st_ins_ans (0 1) 1 __t7DB2460 b)) (head (mkstruct st_union (1 2 0) __6Awq688 a b)) st_basic.slog:18 #f)
  class ReadTask627 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** _enumindex610;  slog::Index** st_ins_ansindex611;  slog::Index** st_insindex612;  slog::Index** st_insindex613;  slog::Index** st_insindex614;  slog::Index** st_ins_ansindex615;  slog::Index** st_ins_ansindex616;  slog::Index** st_insindex617;  slog::Index** st_ins_ansindex618;  slog::Index** st_ins_ansindex619;  slog::Index** st_insindex620;  slog::Index** st_ins_ansindex621;  slog::Index** st_ins_ansindex622;  slog::Index** st_ins_ansindex623;  slog::Index** st_insdelta624;  slog::Index** st_insdelta625;  slog::Index** st_insdelta626;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_union");
      std::vector<u16> ord628({2, 0, 1});
      slog::Relation* readrel629 = db->getRelation("st_ins");
      driver_index = readrel629->getIndex(ord628, true);
      std::vector<u16> ord630({0, 1});
      slog::Relation* readrel631 = db->getRelation("_enum");
      _enumindex610 = readrel631->getIndex(ord630, false);
      std::vector<u16> ord632({0, 1});
      slog::Relation* readrel633 = db->getRelation("st_ins_ans");
      st_ins_ansindex611 = readrel633->getIndex(ord632, false);
      std::vector<u16> ord634({2, 0, 1});
      slog::Relation* readrel635 = db->getRelation("st_ins");
      st_insindex612 = readrel635->getIndex(ord634, false);
      std::vector<u16> ord636({2, 0, 1});
      slog::Relation* readrel637 = db->getRelation("st_ins");
      st_insindex613 = readrel637->getIndex(ord636, false);
      std::vector<u16> ord638({1, 2, 0});
      slog::Relation* readrel639 = db->getRelation("st_ins");
      st_insindex614 = readrel639->getIndex(ord638, false);
      std::vector<u16> ord640({1, 2, 0});
      slog::Relation* readrel641 = db->getRelation("st_ins");
      st_insdelta624 = readrel641->getIndex(ord640, true);
      std::vector<u16> ord642({0, 1});
      slog::Relation* readrel643 = db->getRelation("st_ins_ans");
      st_ins_ansindex615 = readrel643->getIndex(ord642, false);
      std::vector<u16> ord644({0, 1});
      slog::Relation* readrel645 = db->getRelation("st_ins_ans");
      st_ins_ansindex616 = readrel645->getIndex(ord644, false);
      std::vector<u16> ord646({1, 2, 0});
      slog::Relation* readrel647 = db->getRelation("st_ins");
      st_insindex617 = readrel647->getIndex(ord646, false);
      std::vector<u16> ord648({1, 2, 0});
      slog::Relation* readrel649 = db->getRelation("st_ins");
      st_insdelta625 = readrel649->getIndex(ord648, true);
      std::vector<u16> ord650({0, 1});
      slog::Relation* readrel651 = db->getRelation("st_ins_ans");
      st_ins_ansindex618 = readrel651->getIndex(ord650, false);
      std::vector<u16> ord652({0, 1});
      slog::Relation* readrel653 = db->getRelation("st_ins_ans");
      st_ins_ansindex619 = readrel653->getIndex(ord652, false);
      std::vector<u16> ord654({1, 2, 0});
      slog::Relation* readrel655 = db->getRelation("st_ins");
      st_insindex620 = readrel655->getIndex(ord654, false);
      std::vector<u16> ord656({1, 2, 0});
      slog::Relation* readrel657 = db->getRelation("st_ins");
      st_insdelta626 = readrel657->getIndex(ord656, true);
      std::vector<u16> ord658({0, 1});
      slog::Relation* readrel659 = db->getRelation("st_ins_ans");
      st_ins_ansindex621 = readrel659->getIndex(ord658, false);
      std::vector<u16> ord660({0, 1});
      slog::Relation* readrel661 = db->getRelation("st_ins_ans");
      st_ins_ansindex622 = readrel661->getIndex(ord660, false);
      std::vector<u16> ord662({0, 1});
      slog::Relation* readrel663 = db->getRelation("st_ins_ans");
      st_ins_ansindex623 = readrel663->getIndex(ord662, false);
  
    }
    ReadTask627(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c121 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c122 = v_constef2d127de37b942baad06145;
      u64 v_c123 = v_constd4735e3a265e16eee03f5971;
      u64 v_c124 = v_const2c624232cdd221771294dfbb;
      u64 v_c125 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c122, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m664) {
        u64 v_c126 = m664[1];
        u64 v_c127 = m664[2];
        if (buckethash(v_c126) != bucket) return;
        slog::join_probe<2,2>(_enumindex610, std::array<u64,2>{v_c127, v_c121}, [&](const std::array<u64,2>& m665) {
          if (!slog::exists_probe<2,1>(st_ins_ansindex611, std::array<u64,2>{v_c126, 0})) return;
          if (!slog::exists_probe<3,1>(st_insindex612, std::array<u64,3>{v_c124, 0, 0})) return;
          if (!slog::exists_probe<3,1>(st_insindex613, std::array<u64,3>{v_c125, 0, 0})) return;
          slog::join_probe_old<3,2>(st_insindex614, st_insdelta624, std::array<u64,3>{v_c127, v_c123, 0}, [&](const std::array<u64,3>& m666) {
            u64 v_c128 = m666[2];
            if (!slog::exists_probe<2,1>(st_ins_ansindex615, std::array<u64,2>{v_c128, 0})) return;
            slog::join_probe<2,1>(st_ins_ansindex616, std::array<u64,2>{v_c126, 0}, [&](const std::array<u64,2>& m667) {
              u64 v_c10 = m667[1];
              slog::join_probe_old<3,2>(st_insindex617, st_insdelta625, std::array<u64,3>{v_c10, v_c124, 0}, [&](const std::array<u64,3>& m668) {
                u64 v_c129 = m668[2];
                if (!slog::exists_probe<2,1>(st_ins_ansindex618, std::array<u64,2>{v_c129, 0})) return;
                slog::join_probe<2,1>(st_ins_ansindex619, std::array<u64,2>{v_c128, 0}, [&](const std::array<u64,2>& m669) {
                  u64 v_c33 = m669[1];
                  slog::join_probe_old<3,2>(st_insindex620, st_insdelta626, std::array<u64,3>{v_c33, v_c125, 0}, [&](const std::array<u64,3>& m670) {
                    u64 v_c130 = m670[2];
                    if (!slog::exists_probe<2,1>(st_ins_ansindex621, std::array<u64,2>{v_c130, 0})) return;
                    slog::join_probe<2,1>(st_ins_ansindex622, std::array<u64,2>{v_c129, 0}, [&](const std::array<u64,2>& m671) {
                      u64 v_c64 = m671[1];
                      slog::join_probe<2,1>(st_ins_ansindex623, std::array<u64,2>{v_c130, 0}, [&](const std::array<u64,2>& m672) {
                        u64 v_c131 = m672[1];
                        ++_fires;
                        slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c64, v_c131}, std::array<u16,3>{1, 2, 0});
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
        ReadTask627* _cont = new ReadTask627(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask627(db,b), false);
  // (crule (pre) (scan st_join __t1ZYa238 p __t7ZZP236 q __t8STz237) (body (exists pbranch (0 1 2 3 4) 2 __t7ZZP236 p) (exists pbranch (0 1 2 3 4) 2 __t8STz237 q) (exists st_union (1 2 0) 2 __t7ZZP236 __t8STz237) (exists st_msk (1 2 0) 1 p) (exists st_join_ans (0 1) 1 __t1ZYa238) (join $sup9688x120x0x0x0 (4 5 7 8 0 1 2 3 6 9 10) 4 p q __t7ZZP236 __t8STz237 __t3tZ8235 l m n r u v) (cmp lt m n) (join pbranch (1 2 3 4 0) 5 p m l r __t7ZZP236) (join pbranch (1 2 3 4 0) 5 q n u v __t8STz237) (join st_union (0 1 2) 3 __t3tZ8235 __t7ZZP236 __t8STz237) (join-old st_msk (1 2 0) 2 (1 2 0) p n __t3Qtm239) (join st_msk_ans (0 1) 1 __t3Qtm239 __v0) (neq q __v0) (join st_join_ans (0 1) 1 __t1ZYa238 res)) (head (emit st_union_ans (0 1) __t3tZ8235 res)) set.slog:121 #f)
  class ReadTask686 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex673;  slog::Index** pbranchindex674;  slog::Index** st_unionindex675;  slog::Index** st_mskindex676;  slog::Index** st_join_ansindex677;  slog::Index** $sup9688x120x0x0x0index678;  slog::Index** pbranchindex679;  slog::Index** pbranchindex680;  slog::Index** st_unionindex681;  slog::Index** st_mskindex682;  slog::Index** st_msk_ansindex683;  slog::Index** st_join_ansindex684;  slog::Index** st_mskdelta685;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_union_ans");
      std::vector<u16> ord687({0, 1});
      slog::Relation* readrel688 = db->getRelation("st_union_ans");
      head_index[0] = readrel688->getIndex(ord687, false);
      outer_rel = db->getRelation("st_join");
      std::vector<u16> ord689({0, 1, 2, 3, 4});
      slog::Relation* readrel690 = db->getRelation("pbranch");
      pbranchindex673 = readrel690->getIndex(ord689, false);
      std::vector<u16> ord691({0, 1, 2, 3, 4});
      slog::Relation* readrel692 = db->getRelation("pbranch");
      pbranchindex674 = readrel692->getIndex(ord691, false);
      std::vector<u16> ord693({1, 2, 0});
      slog::Relation* readrel694 = db->getRelation("st_union");
      st_unionindex675 = readrel694->getIndex(ord693, false);
      std::vector<u16> ord695({1, 2, 0});
      slog::Relation* readrel696 = db->getRelation("st_msk");
      st_mskindex676 = readrel696->getIndex(ord695, false);
      std::vector<u16> ord697({0, 1});
      slog::Relation* readrel698 = db->getRelation("st_join_ans");
      st_join_ansindex677 = readrel698->getIndex(ord697, false);
      std::vector<u16> ord699({4, 5, 7, 8, 0, 1, 2, 3, 6, 9, 10});
      slog::Relation* readrel700 = db->getRelation("$sup9688x120x0x0x0");
      $sup9688x120x0x0x0index678 = readrel700->getIndex(ord699, false);
      std::vector<u16> ord701({1, 2, 3, 4, 0});
      slog::Relation* readrel702 = db->getRelation("pbranch");
      pbranchindex679 = readrel702->getIndex(ord701, false);
      std::vector<u16> ord703({1, 2, 3, 4, 0});
      slog::Relation* readrel704 = db->getRelation("pbranch");
      pbranchindex680 = readrel704->getIndex(ord703, false);
      std::vector<u16> ord705({0, 1, 2});
      slog::Relation* readrel706 = db->getRelation("st_union");
      st_unionindex681 = readrel706->getIndex(ord705, false);
      std::vector<u16> ord707({1, 2, 0});
      slog::Relation* readrel708 = db->getRelation("st_msk");
      st_mskindex682 = readrel708->getIndex(ord707, false);
      std::vector<u16> ord709({1, 2, 0});
      slog::Relation* readrel710 = db->getRelation("st_msk");
      st_mskdelta685 = readrel710->getIndex(ord709, true);
      std::vector<u16> ord711({0, 1});
      slog::Relation* readrel712 = db->getRelation("st_msk_ans");
      st_msk_ansindex683 = readrel712->getIndex(ord711, false);
      std::vector<u16> ord713({0, 1});
      slog::Relation* readrel714 = db->getRelation("st_join_ans");
      st_join_ansindex684 = readrel714->getIndex(ord713, false);
  
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
        u64 v_c132 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c133 = _t[2];
        u64 v_c16 = _t[3];
        u64 v_c134 = _t[4];
        if (!slog::exists_probe<5,2>(pbranchindex673, std::array<u64,5>{v_c133, v_c2, 0, 0, 0})) return;
        if (!slog::exists_probe<5,2>(pbranchindex674, std::array<u64,5>{v_c134, v_c16, 0, 0, 0})) return;
        if (!slog::exists_probe<3,2>(st_unionindex675, std::array<u64,3>{v_c133, v_c134, 0})) return;
        if (!slog::exists_probe<3,1>(st_mskindex676, std::array<u64,3>{v_c2, 0, 0})) return;
        if (!slog::exists_probe<2,1>(st_join_ansindex677, std::array<u64,2>{v_c132, 0})) return;
        slog::join_probe<11,4>($sup9688x120x0x0x0index678, std::array<u64,11>{v_c2, v_c16, v_c133, v_c134, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m715) {
          u64 v_c135 = m715[4]; u64 v_c6 = m715[5]; u64 v_c7 = m715[6]; u64 v_c15 = m715[7]; u64 v_c8 = m715[8]; u64 v_c17 = m715[9]; u64 v_c18 = m715[10];
          u64 v_c136 = _prim_lt(db, v_c7, v_c15);
          if (v_c136 == slog_error) { slog::emit_pending_error(db, "set.slog:121"); return; }
          if (!v_c136) return;
          slog::join_probe<5,5>(pbranchindex679, std::array<u64,5>{v_c2, v_c7, v_c6, v_c8, v_c133}, [&](const std::array<u64,5>& m717) {
            slog::join_probe<5,5>(pbranchindex680, std::array<u64,5>{v_c16, v_c15, v_c17, v_c18, v_c134}, [&](const std::array<u64,5>& m718) {
              slog::join_probe<3,3>(st_unionindex681, std::array<u64,3>{v_c135, v_c133, v_c134}, [&](const std::array<u64,3>& m719) {
                slog::join_probe_old<3,2>(st_mskindex682, st_mskdelta685, std::array<u64,3>{v_c2, v_c15, 0}, [&](const std::array<u64,3>& m720) {
                  u64 v_c137 = m720[2];
                  slog::join_probe<2,1>(st_msk_ansindex683, std::array<u64,2>{v_c137, 0}, [&](const std::array<u64,2>& m721) {
                    u64 v_c10 = m721[1];
                    if (v_c16 == v_c10) return;
                    slog::join_probe<2,1>(st_join_ansindex684, std::array<u64,2>{v_c132, 0}, [&](const std::array<u64,2>& m722) {
                      u64 v_c11 = m722[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c135, v_c11}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:121", "delta:st_join", _fires);
  
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
  // (crule (pre) (scan st_msk_ans __t7gQz149 __v0) (body (join-old st_msk (0 1 2) 1 (0 1 2) __t7gQz149 q m) (exists pbranch (1 2 3 4 0) 1 q) (exists pbranch (2 0 1 3 4) 1 m) (join-old $sup9688x145x0x0x0 (2 5 0 1 3 4 6 7 8) 2 (2 5 0 1 3 4 6 7 8) m q __t3Vft148 l n p r u v) (cmp lt n m) (neq p __v0) (exists pbranch (1 2 3 4 0) 4 p m l r) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t0w8p146) (exists st_diff (2 0 1) 2 __t0w8p146 __t3Vft148) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t8pVe147) (join-old st_diff (0 1 2) 3 (0 1 2) __t3Vft148 __t8pVe147 __t0w8p146)) (head (emit st_diff_ans (0 1) __t3Vft148 __t8pVe147)) set.slog:146 #f)
  class ReadTask737 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_mskindex723;  slog::Index** pbranchindex724;  slog::Index** pbranchindex725;  slog::Index** $sup9688x145x0x0x0index726;  slog::Index** pbranchindex727;  slog::Index** pbranchindex728;  slog::Index** st_diffindex729;  slog::Index** pbranchindex730;  slog::Index** st_diffindex731;  slog::Index** st_mskdelta732;  slog::Index** $sup9688x145x0x0x0delta733;  slog::Index** pbranchdelta734;  slog::Index** pbranchdelta735;  slog::Index** st_diffdelta736;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord738({0, 1});
      slog::Relation* readrel739 = db->getRelation("st_diff_ans");
      head_index[0] = readrel739->getIndex(ord738, false);
      outer_rel = db->getRelation("st_msk_ans");
      std::vector<u16> ord740({0, 1, 2});
      slog::Relation* readrel741 = db->getRelation("st_msk");
      st_mskindex723 = readrel741->getIndex(ord740, false);
      std::vector<u16> ord742({0, 1, 2});
      slog::Relation* readrel743 = db->getRelation("st_msk");
      st_mskdelta732 = readrel743->getIndex(ord742, true);
      std::vector<u16> ord744({1, 2, 3, 4, 0});
      slog::Relation* readrel745 = db->getRelation("pbranch");
      pbranchindex724 = readrel745->getIndex(ord744, false);
      std::vector<u16> ord746({2, 0, 1, 3, 4});
      slog::Relation* readrel747 = db->getRelation("pbranch");
      pbranchindex725 = readrel747->getIndex(ord746, false);
      std::vector<u16> ord748({2, 5, 0, 1, 3, 4, 6, 7, 8});
      slog::Relation* readrel749 = db->getRelation("$sup9688x145x0x0x0");
      $sup9688x145x0x0x0index726 = readrel749->getIndex(ord748, false);
      std::vector<u16> ord750({2, 5, 0, 1, 3, 4, 6, 7, 8});
      slog::Relation* readrel751 = db->getRelation("$sup9688x145x0x0x0");
      $sup9688x145x0x0x0delta733 = readrel751->getIndex(ord750, true);
      std::vector<u16> ord752({1, 2, 3, 4, 0});
      slog::Relation* readrel753 = db->getRelation("pbranch");
      pbranchindex727 = readrel753->getIndex(ord752, false);
      std::vector<u16> ord754({1, 2, 3, 4, 0});
      slog::Relation* readrel755 = db->getRelation("pbranch");
      pbranchindex728 = readrel755->getIndex(ord754, false);
      std::vector<u16> ord756({1, 2, 3, 4, 0});
      slog::Relation* readrel757 = db->getRelation("pbranch");
      pbranchdelta734 = readrel757->getIndex(ord756, true);
      std::vector<u16> ord758({2, 0, 1});
      slog::Relation* readrel759 = db->getRelation("st_diff");
      st_diffindex729 = readrel759->getIndex(ord758, false);
      std::vector<u16> ord760({1, 2, 3, 4, 0});
      slog::Relation* readrel761 = db->getRelation("pbranch");
      pbranchindex730 = readrel761->getIndex(ord760, false);
      std::vector<u16> ord762({1, 2, 3, 4, 0});
      slog::Relation* readrel763 = db->getRelation("pbranch");
      pbranchdelta735 = readrel763->getIndex(ord762, true);
      std::vector<u16> ord764({0, 1, 2});
      slog::Relation* readrel765 = db->getRelation("st_diff");
      st_diffindex731 = readrel765->getIndex(ord764, false);
      std::vector<u16> ord766({0, 1, 2});
      slog::Relation* readrel767 = db->getRelation("st_diff");
      st_diffdelta736 = readrel767->getIndex(ord766, true);
  
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
        u64 v_c138 = _t[0];
        u64 v_c10 = _t[1];
        slog::join_probe_old<3,1>(st_mskindex723, st_mskdelta732, std::array<u64,3>{v_c138, 0, 0}, [&](const std::array<u64,3>& m768) {
          u64 v_c16 = m768[1]; u64 v_c7 = m768[2];
          if (!slog::exists_probe<5,1>(pbranchindex724, std::array<u64,5>{v_c16, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>(pbranchindex725, std::array<u64,5>{v_c7, 0, 0, 0, 0})) return;
          slog::join_probe_old<9,2>($sup9688x145x0x0x0index726, $sup9688x145x0x0x0delta733, std::array<u64,9>{v_c7, v_c16, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m769) {
            u64 v_c139 = m769[2]; u64 v_c6 = m769[3]; u64 v_c15 = m769[4]; u64 v_c2 = m769[5]; u64 v_c8 = m769[6]; u64 v_c17 = m769[7]; u64 v_c18 = m769[8];
            u64 v_c140 = _prim_lt(db, v_c15, v_c7);
            if (v_c140 == slog_error) { slog::emit_pending_error(db, "set.slog:146"); return; }
            if (!v_c140) return;
            if (v_c2 == v_c10) return;
            if (!slog::exists_probe<5,4>(pbranchindex727, std::array<u64,5>{v_c2, v_c7, v_c6, v_c8, 0})) return;
            slog::join_probe_old<5,4>(pbranchindex728, pbranchdelta734, std::array<u64,5>{v_c16, v_c15, v_c17, v_c18, 0}, [&](const std::array<u64,5>& m771) {
              u64 v_c141 = m771[4];
              if (!slog::exists_probe<3,2>(st_diffindex729, std::array<u64,3>{v_c141, v_c139, 0})) return;
              slog::join_probe_old<5,4>(pbranchindex730, pbranchdelta735, std::array<u64,5>{v_c2, v_c7, v_c6, v_c8, 0}, [&](const std::array<u64,5>& m772) {
                u64 v_c142 = m772[4];
                slog::join_probe_old<3,3>(st_diffindex731, st_diffdelta736, std::array<u64,3>{v_c139, v_c142, v_c141}, [&](const std::array<u64,3>& m773) {
                  ++_fires;
                  slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c139, v_c142}, std::array<u16,2>{0, 1});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:146", "delta:st_msk_ans", _fires);
  
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
  // (crule (pre) (scan st_union_ans __t8LsM290 __v1) (body (join-old st_union (0 1 2) 1 (0 1 2) __t8LsM290 r v) (exists pbranch (4 0 1 2 3) 1 v) (exists pbranch (4 0 1 2 3) 1 r) (join-old $sup9688x100x0x0x0 (4 6 0 1 2 3 5) 2 (4 6 0 1 2 3 5) r v __t2Q3U288 l m p u) (exists pbranch (1 2 3 4 0) 4 p m l r) (exists st_union (1 2 0) 2 l u) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m u v __t22FG286) (exists st_union (2 0 1) 2 __t22FG286 __t2Q3U288) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t1pUK287) (join-old st_union (0 1 2) 3 (0 1 2) __t2Q3U288 __t1pUK287 __t22FG286) (join-old st_union (1 2 0) 2 (1 2 0) l u __t1gnX289) (join st_union_ans (0 1) 1 __t1gnX289 __v0)) (head (emit-temp temp6bMv1274 __t2Q3U288 __v0 __v1 m p) (mkstruct pbranch (1 2 3 4 0) __t6nPF285 p m __v0 __v1)) set.slog:101 #f)
  class ReadTask792 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_unionindex774;  slog::Index** pbranchindex775;  slog::Index** pbranchindex776;  slog::Index** $sup9688x100x0x0x0index777;  slog::Index** pbranchindex778;  slog::Index** st_unionindex779;  slog::Index** pbranchindex780;  slog::Index** st_unionindex781;  slog::Index** pbranchindex782;  slog::Index** st_unionindex783;  slog::Index** st_unionindex784;  slog::Index** st_union_ansindex785;  slog::Index** st_uniondelta786;  slog::Index** $sup9688x100x0x0x0delta787;  slog::Index** pbranchdelta788;  slog::Index** pbranchdelta789;  slog::Index** st_uniondelta790;  slog::Index** st_uniondelta791;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp6bMv1274");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("st_union_ans");
      std::vector<u16> ord793({0, 1, 2});
      slog::Relation* readrel794 = db->getRelation("st_union");
      st_unionindex774 = readrel794->getIndex(ord793, false);
      std::vector<u16> ord795({0, 1, 2});
      slog::Relation* readrel796 = db->getRelation("st_union");
      st_uniondelta786 = readrel796->getIndex(ord795, true);
      std::vector<u16> ord797({4, 0, 1, 2, 3});
      slog::Relation* readrel798 = db->getRelation("pbranch");
      pbranchindex775 = readrel798->getIndex(ord797, false);
      std::vector<u16> ord799({4, 0, 1, 2, 3});
      slog::Relation* readrel800 = db->getRelation("pbranch");
      pbranchindex776 = readrel800->getIndex(ord799, false);
      std::vector<u16> ord801({4, 6, 0, 1, 2, 3, 5});
      slog::Relation* readrel802 = db->getRelation("$sup9688x100x0x0x0");
      $sup9688x100x0x0x0index777 = readrel802->getIndex(ord801, false);
      std::vector<u16> ord803({4, 6, 0, 1, 2, 3, 5});
      slog::Relation* readrel804 = db->getRelation("$sup9688x100x0x0x0");
      $sup9688x100x0x0x0delta787 = readrel804->getIndex(ord803, true);
      std::vector<u16> ord805({1, 2, 3, 4, 0});
      slog::Relation* readrel806 = db->getRelation("pbranch");
      pbranchindex778 = readrel806->getIndex(ord805, false);
      std::vector<u16> ord807({1, 2, 0});
      slog::Relation* readrel808 = db->getRelation("st_union");
      st_unionindex779 = readrel808->getIndex(ord807, false);
      std::vector<u16> ord809({1, 2, 3, 4, 0});
      slog::Relation* readrel810 = db->getRelation("pbranch");
      pbranchindex780 = readrel810->getIndex(ord809, false);
      std::vector<u16> ord811({1, 2, 3, 4, 0});
      slog::Relation* readrel812 = db->getRelation("pbranch");
      pbranchdelta788 = readrel812->getIndex(ord811, true);
      std::vector<u16> ord813({2, 0, 1});
      slog::Relation* readrel814 = db->getRelation("st_union");
      st_unionindex781 = readrel814->getIndex(ord813, false);
      std::vector<u16> ord815({1, 2, 3, 4, 0});
      slog::Relation* readrel816 = db->getRelation("pbranch");
      pbranchindex782 = readrel816->getIndex(ord815, false);
      std::vector<u16> ord817({1, 2, 3, 4, 0});
      slog::Relation* readrel818 = db->getRelation("pbranch");
      pbranchdelta789 = readrel818->getIndex(ord817, true);
      std::vector<u16> ord819({0, 1, 2});
      slog::Relation* readrel820 = db->getRelation("st_union");
      st_unionindex783 = readrel820->getIndex(ord819, false);
      std::vector<u16> ord821({0, 1, 2});
      slog::Relation* readrel822 = db->getRelation("st_union");
      st_uniondelta790 = readrel822->getIndex(ord821, true);
      std::vector<u16> ord823({1, 2, 0});
      slog::Relation* readrel824 = db->getRelation("st_union");
      st_unionindex784 = readrel824->getIndex(ord823, false);
      std::vector<u16> ord825({1, 2, 0});
      slog::Relation* readrel826 = db->getRelation("st_union");
      st_uniondelta791 = readrel826->getIndex(ord825, true);
      std::vector<u16> ord827({0, 1});
      slog::Relation* readrel828 = db->getRelation("st_union_ans");
      st_union_ansindex785 = readrel828->getIndex(ord827, false);
  
    }
    ReadTask792(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c143 = _t[0];
        u64 v_c33 = _t[1];
        slog::join_probe_old<3,1>(st_unionindex774, st_uniondelta786, std::array<u64,3>{v_c143, 0, 0}, [&](const std::array<u64,3>& m829) {
          u64 v_c8 = m829[1]; u64 v_c18 = m829[2];
          if (!slog::exists_probe<5,1>(pbranchindex775, std::array<u64,5>{v_c18, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>(pbranchindex776, std::array<u64,5>{v_c8, 0, 0, 0, 0})) return;
          slog::join_probe_old<7,2>($sup9688x100x0x0x0index777, $sup9688x100x0x0x0delta787, std::array<u64,7>{v_c8, v_c18, 0, 0, 0, 0, 0}, [&](const std::array<u64,7>& m830) {
            u64 v_c144 = m830[2]; u64 v_c6 = m830[3]; u64 v_c7 = m830[4]; u64 v_c2 = m830[5]; u64 v_c17 = m830[6];
            if (!slog::exists_probe<5,4>(pbranchindex778, std::array<u64,5>{v_c2, v_c7, v_c6, v_c8, 0})) return;
            if (!slog::exists_probe<3,2>(st_unionindex779, std::array<u64,3>{v_c6, v_c17, 0})) return;
            slog::join_probe_old<5,4>(pbranchindex780, pbranchdelta788, std::array<u64,5>{v_c2, v_c7, v_c17, v_c18, 0}, [&](const std::array<u64,5>& m831) {
              u64 v_c145 = m831[4];
              if (!slog::exists_probe<3,2>(st_unionindex781, std::array<u64,3>{v_c145, v_c144, 0})) return;
              slog::join_probe_old<5,4>(pbranchindex782, pbranchdelta789, std::array<u64,5>{v_c2, v_c7, v_c6, v_c8, 0}, [&](const std::array<u64,5>& m832) {
                u64 v_c146 = m832[4];
                slog::join_probe_old<3,3>(st_unionindex783, st_uniondelta790, std::array<u64,3>{v_c144, v_c146, v_c145}, [&](const std::array<u64,3>& m833) {
                  slog::join_probe_old<3,2>(st_unionindex784, st_uniondelta791, std::array<u64,3>{v_c6, v_c17, 0}, [&](const std::array<u64,3>& m834) {
                    u64 v_c147 = m834[2];
                    slog::join_probe<2,1>(st_union_ansindex785, std::array<u64,2>{v_c147, 0}, [&](const std::array<u64,2>& m835) {
                      u64 v_c10 = m835[1];
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c144, v_c10, v_c33, v_c7, v_c2});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c2, v_c7, v_c10, v_c33}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:101", "delta:st_union_ans", _fires);
  
      if (!_done)
      {
        ReadTask792* _cont = new ReadTask792(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask792(db,b), false);
  // (crule (pre) (scan pleaf __t29mi113 j) (body (exists st_ins (1 2 0) 1 __t29mi113) (join-old st_join (3 4 0 1 2) 2 (3 4 0 1 2) j __t29mi113 __t6WK8115 k __t3mOh114) (neq j k) (join-old pleaf (0 1) 2 (0 1) __t3mOh114 k) (exists st_join_ans (0 1) 1 __t6WK8115) (join st_ins (1 2 0) 2 __t29mi113 k __t1Tua112) (join st_join_ans (0 1) 1 __t6WK8115 r)) (head (emit st_ins_ans (0 1) __t1Tua112 r)) set.slog:50 #f)
  class ReadTask844 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_insindex836;  slog::Index** st_joinindex837;  slog::Index** pleafindex838;  slog::Index** st_join_ansindex839;  slog::Index** st_insindex840;  slog::Index** st_join_ansindex841;  slog::Index** st_joindelta842;  slog::Index** pleafdelta843;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_ins_ans");
      std::vector<u16> ord845({0, 1});
      slog::Relation* readrel846 = db->getRelation("st_ins_ans");
      head_index[0] = readrel846->getIndex(ord845, false);
      outer_rel = db->getRelation("pleaf");
      std::vector<u16> ord847({1, 2, 0});
      slog::Relation* readrel848 = db->getRelation("st_ins");
      st_insindex836 = readrel848->getIndex(ord847, false);
      std::vector<u16> ord849({3, 4, 0, 1, 2});
      slog::Relation* readrel850 = db->getRelation("st_join");
      st_joinindex837 = readrel850->getIndex(ord849, false);
      std::vector<u16> ord851({3, 4, 0, 1, 2});
      slog::Relation* readrel852 = db->getRelation("st_join");
      st_joindelta842 = readrel852->getIndex(ord851, true);
      std::vector<u16> ord853({0, 1});
      slog::Relation* readrel854 = db->getRelation("pleaf");
      pleafindex838 = readrel854->getIndex(ord853, false);
      std::vector<u16> ord855({0, 1});
      slog::Relation* readrel856 = db->getRelation("pleaf");
      pleafdelta843 = readrel856->getIndex(ord855, true);
      std::vector<u16> ord857({0, 1});
      slog::Relation* readrel858 = db->getRelation("st_join_ans");
      st_join_ansindex839 = readrel858->getIndex(ord857, false);
      std::vector<u16> ord859({1, 2, 0});
      slog::Relation* readrel860 = db->getRelation("st_ins");
      st_insindex840 = readrel860->getIndex(ord859, false);
      std::vector<u16> ord861({0, 1});
      slog::Relation* readrel862 = db->getRelation("st_join_ans");
      st_join_ansindex841 = readrel862->getIndex(ord861, false);
  
    }
    ReadTask844(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c148 = _t[0];
        u64 v_c149 = _t[1];
        if (!slog::exists_probe<3,1>(st_insindex836, std::array<u64,3>{v_c148, 0, 0})) return;
        slog::join_probe_old<5,2>(st_joinindex837, st_joindelta842, std::array<u64,5>{v_c149, v_c148, 0, 0, 0}, [&](const std::array<u64,5>& m863) {
          u64 v_c150 = m863[2]; u64 v_c1 = m863[3]; u64 v_c151 = m863[4];
          if (v_c149 == v_c1) return;
          slog::join_probe_old<2,2>(pleafindex838, pleafdelta843, std::array<u64,2>{v_c151, v_c1}, [&](const std::array<u64,2>& m864) {
            if (!slog::exists_probe<2,1>(st_join_ansindex839, std::array<u64,2>{v_c150, 0})) return;
            slog::join_probe<3,2>(st_insindex840, std::array<u64,3>{v_c148, v_c1, 0}, [&](const std::array<u64,3>& m865) {
              u64 v_c152 = m865[2];
              slog::join_probe<2,1>(st_join_ansindex841, std::array<u64,2>{v_c150, 0}, [&](const std::array<u64,2>& m866) {
                u64 v_c8 = m866[1];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c152, v_c8}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:50", "delta:pleaf", _fires);
  
      if (!_done)
      {
        ReadTask844* _cont = new ReadTask844(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask844(db,b), false);
  // (crule (pre (let __tconst4ix7260 const5feceb66ffc86f38d952786c)) (scan pbranch __t0vi9258 p m l r) (body (exists $sup9688x52x0x0x1 (3 4 5 6 0 2 1) 4 l m p r) (exists st_ins (1 2 0) 1 __t0vi9258) (exists st_msk (2 0 1) 1 m) (exists st_msk_ans (1 0) 1 p) (exists st_ins (1 2 0) 1 r) (join $sup9688x52x0x0x0 (4 2 3 5 0 1) 4 p l m r __t7CbB259 k) (exists st_ins (0 2 1) 3 __t7CbB259 k __t0vi9258) (exists st_msk (1 2 0) 2 k m) (exists st_ins (1 2 0) 2 r k) (join $sup9688x52x0x0x1 (3 4 5 6 0 2 1) 6 l m p r __t7CbB259 k __t57zq262) (join-old st_ins (0 2 1) 3 (0 2 1) __t7CbB259 k __t0vi9258) (join-old st_msk (1 2 0) 3 (1 2 0) k m __t57zq262) (join st_msk_ans (0 1) 2 __t57zq262 p) (join-old st_ins (1 2 0) 2 (1 2 0) r k __t2KGA263) (join st_ins_ans (0 1) 1 __t2KGA263 __v0) (let __t7Gsa261 (band k m)) (cmp gt __t7Gsa261 __tconst4ix7260)) (head (emit-temp temp8v341350 __t7CbB259 __v0 l m p) (mkstruct pbranch (1 2 3 4 0) __t4EZL257 p m l __v0)) set.slog:53 #f)
  class ReadTask885 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x52x0x0x1index867;  slog::Index** st_insindex868;  slog::Index** st_mskindex869;  slog::Index** st_msk_ansindex870;  slog::Index** st_insindex871;  slog::Index** $sup9688x52x0x0x0index872;  slog::Index** st_insindex873;  slog::Index** st_mskindex874;  slog::Index** st_insindex875;  slog::Index** $sup9688x52x0x0x1index876;  slog::Index** st_insindex877;  slog::Index** st_mskindex878;  slog::Index** st_msk_ansindex879;  slog::Index** st_insindex880;  slog::Index** st_ins_ansindex881;  slog::Index** st_insdelta882;  slog::Index** st_mskdelta883;  slog::Index** st_insdelta884;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8v341350");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord886({3, 4, 5, 6, 0, 2, 1});
      slog::Relation* readrel887 = db->getRelation("$sup9688x52x0x0x1");
      $sup9688x52x0x0x1index867 = readrel887->getIndex(ord886, false);
      std::vector<u16> ord888({1, 2, 0});
      slog::Relation* readrel889 = db->getRelation("st_ins");
      st_insindex868 = readrel889->getIndex(ord888, false);
      std::vector<u16> ord890({2, 0, 1});
      slog::Relation* readrel891 = db->getRelation("st_msk");
      st_mskindex869 = readrel891->getIndex(ord890, false);
      std::vector<u16> ord892({1, 0});
      slog::Relation* readrel893 = db->getRelation("st_msk_ans");
      st_msk_ansindex870 = readrel893->getIndex(ord892, false);
      std::vector<u16> ord894({1, 2, 0});
      slog::Relation* readrel895 = db->getRelation("st_ins");
      st_insindex871 = readrel895->getIndex(ord894, false);
      std::vector<u16> ord896({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel897 = db->getRelation("$sup9688x52x0x0x0");
      $sup9688x52x0x0x0index872 = readrel897->getIndex(ord896, false);
      std::vector<u16> ord898({0, 2, 1});
      slog::Relation* readrel899 = db->getRelation("st_ins");
      st_insindex873 = readrel899->getIndex(ord898, false);
      std::vector<u16> ord900({1, 2, 0});
      slog::Relation* readrel901 = db->getRelation("st_msk");
      st_mskindex874 = readrel901->getIndex(ord900, false);
      std::vector<u16> ord902({1, 2, 0});
      slog::Relation* readrel903 = db->getRelation("st_ins");
      st_insindex875 = readrel903->getIndex(ord902, false);
      std::vector<u16> ord904({3, 4, 5, 6, 0, 2, 1});
      slog::Relation* readrel905 = db->getRelation("$sup9688x52x0x0x1");
      $sup9688x52x0x0x1index876 = readrel905->getIndex(ord904, false);
      std::vector<u16> ord906({0, 2, 1});
      slog::Relation* readrel907 = db->getRelation("st_ins");
      st_insindex877 = readrel907->getIndex(ord906, false);
      std::vector<u16> ord908({0, 2, 1});
      slog::Relation* readrel909 = db->getRelation("st_ins");
      st_insdelta882 = readrel909->getIndex(ord908, true);
      std::vector<u16> ord910({1, 2, 0});
      slog::Relation* readrel911 = db->getRelation("st_msk");
      st_mskindex878 = readrel911->getIndex(ord910, false);
      std::vector<u16> ord912({1, 2, 0});
      slog::Relation* readrel913 = db->getRelation("st_msk");
      st_mskdelta883 = readrel913->getIndex(ord912, true);
      std::vector<u16> ord914({0, 1});
      slog::Relation* readrel915 = db->getRelation("st_msk_ans");
      st_msk_ansindex879 = readrel915->getIndex(ord914, false);
      std::vector<u16> ord916({1, 2, 0});
      slog::Relation* readrel917 = db->getRelation("st_ins");
      st_insindex880 = readrel917->getIndex(ord916, false);
      std::vector<u16> ord918({1, 2, 0});
      slog::Relation* readrel919 = db->getRelation("st_ins");
      st_insdelta884 = readrel919->getIndex(ord918, true);
      std::vector<u16> ord920({0, 1});
      slog::Relation* readrel921 = db->getRelation("st_ins_ans");
      st_ins_ansindex881 = readrel921->getIndex(ord920, false);
  
    }
    ReadTask885(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c153 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c154 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c6 = _t[3];
        u64 v_c8 = _t[4];
        if (!slog::exists_probe<7,4>($sup9688x52x0x0x1index867, std::array<u64,7>{v_c6, v_c7, v_c2, v_c8, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex868, std::array<u64,3>{v_c154, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mskindex869, std::array<u64,3>{v_c7, 0, 0})) return;
        if (!slog::exists_probe<2,1>(st_msk_ansindex870, std::array<u64,2>{v_c2, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex871, std::array<u64,3>{v_c8, 0, 0})) return;
        slog::join_probe<6,4>($sup9688x52x0x0x0index872, std::array<u64,6>{v_c2, v_c6, v_c7, v_c8, 0, 0}, [&](const std::array<u64,6>& m922) {
          u64 v_c155 = m922[4]; u64 v_c1 = m922[5];
          if (!slog::exists_probe<3,3>(st_insindex873, std::array<u64,3>{v_c155, v_c1, v_c154})) return;
          if (!slog::exists_probe<3,2>(st_mskindex874, std::array<u64,3>{v_c1, v_c7, 0})) return;
          if (!slog::exists_probe<3,2>(st_insindex875, std::array<u64,3>{v_c8, v_c1, 0})) return;
          slog::join_probe<7,6>($sup9688x52x0x0x1index876, std::array<u64,7>{v_c6, v_c7, v_c2, v_c8, v_c155, v_c1, 0}, [&](const std::array<u64,7>& m923) {
            u64 v_c156 = m923[6];
            slog::join_probe_old<3,3>(st_insindex877, st_insdelta882, std::array<u64,3>{v_c155, v_c1, v_c154}, [&](const std::array<u64,3>& m924) {
              slog::join_probe_old<3,3>(st_mskindex878, st_mskdelta883, std::array<u64,3>{v_c1, v_c7, v_c156}, [&](const std::array<u64,3>& m925) {
                slog::join_probe<2,2>(st_msk_ansindex879, std::array<u64,2>{v_c156, v_c2}, [&](const std::array<u64,2>& m926) {
                  slog::join_probe_old<3,2>(st_insindex880, st_insdelta884, std::array<u64,3>{v_c8, v_c1, 0}, [&](const std::array<u64,3>& m927) {
                    u64 v_c157 = m927[2];
                    slog::join_probe<2,1>(st_ins_ansindex881, std::array<u64,2>{v_c157, 0}, [&](const std::array<u64,2>& m928) {
                      u64 v_c10 = m928[1];
                      u64 v_c158 = _prim_band(db, v_c1, v_c7);
                      if (v_c158 == slog_error) { slog::emit_pending_error(db, "set.slog:53"); return; }
                      u64 v_c159 = _prim_gt(db, v_c158, v_c153);
                      if (v_c159 == slog_error) { slog::emit_pending_error(db, "set.slog:53"); return; }
                      if (!v_c159) return;
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c155, v_c10, v_c6, v_c7, v_c2});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c2, v_c7, v_c6, v_c10}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:53", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask885* _cont = new ReadTask885(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask885(db,b), false);
  // (crule (pre) (scan int_overflow __erre1Zz41244 __errf19FQ1245 __errf6RN41246 __errf3dSG1247) (body) (head (emit error (0) __erre1Zz41244)) <internal>:1 #f)
  class ReadTask930 : public slog::Task
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
      std::vector<u16> ord931({0});
      slog::Relation* readrel932 = db->getRelation("error");
      head_index[0] = readrel932->getIndex(ord931, false);
      outer_rel = db->getRelation("int_overflow");
  
    }
    ReadTask930(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c160}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:int_overflow", _fires);
  
      if (!_done)
      {
        ReadTask930* _cont = new ReadTask930(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask930(db,b), false);
  // (crule (pre) (scan temp9eaB1343 __t3N33245 __v0 m p r) (body (join pbranch (1 2 3 4 0) 4 p m __v0 r __t2omG242)) (head (emit st_union_ans (0 1) __t3N33245 __t2omG242)) set.slog:104 #f)
  class ReadTask934 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex933;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_union_ans");
      std::vector<u16> ord935({0, 1});
      slog::Relation* readrel936 = db->getRelation("st_union_ans");
      head_index[0] = readrel936->getIndex(ord935, false);
      outer_rel = db->getRelation("temp9eaB1343");
      std::vector<u16> ord937({1, 2, 3, 4, 0});
      slog::Relation* readrel938 = db->getRelation("pbranch");
      pbranchindex933 = readrel938->getIndex(ord937, false);
  
    }
    ReadTask934(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c10 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c2 = _t[3];
        u64 v_c8 = _t[4];
        slog::join_probe<5,4>(pbranchindex933, std::array<u64,5>{v_c2, v_c7, v_c10, v_c8, 0}, [&](const std::array<u64,5>& m939) {
          u64 v_c165 = m939[4];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c164, v_c165}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:104", "delta:temp9eaB1343", _fires);
  
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
  // (crule (pre) (scan st_mem0 __t0per475 __t1mni474 k) (body (join pbranch (0 1 2 3 4) 1 __t1mni474 p m l r)) (head (emit $sup9688x69x0x0x0 (0 1 2 3 4 5) __t0per475 k l m p r)) set.slog:70 #f)
  class ReadTask941 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex940;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x69x0x0x0");
      std::vector<u16> ord942({0, 1, 2, 3, 4, 5});
      slog::Relation* readrel943 = db->getRelation("$sup9688x69x0x0x0");
      head_index[0] = readrel943->getIndex(ord942, false);
      outer_rel = db->getRelation("st_mem0");
      std::vector<u16> ord944({0, 1, 2, 3, 4});
      slog::Relation* readrel945 = db->getRelation("pbranch");
      pbranchindex940 = readrel945->getIndex(ord944, false);
  
    }
    ReadTask941(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c166 = _t[0];
        u64 v_c167 = _t[1];
        u64 v_c1 = _t[2];
        slog::join_probe<5,1>(pbranchindex940, std::array<u64,5>{v_c167, 0, 0, 0, 0}, [&](const std::array<u64,5>& m946) {
          u64 v_c2 = m946[1]; u64 v_c7 = m946[2]; u64 v_c6 = m946[3]; u64 v_c8 = m946[4];
          ++_fires;
          slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c166, v_c1, v_c6, v_c7, v_c2, v_c8}, std::array<u16,6>{0, 1, 2, 3, 4, 5});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:70", "delta:st_mem0", _fires);
  
      if (!_done)
      {
        ReadTask941* _cont = new ReadTask941(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask941(db,b), false);
  // (crule (pre) (scan st_ins __t2YgE11 __t4iIu12 k) (body (exists st_join (1 4 3 0 2) 2 k __t4iIu12) (exists pleaf (1 0) 1 k) (exists st_msk (1 2 0) 1 k) (join $sup9688x54x0x0x0 (0 1 6 4 2 3 5) 3 __t2YgE11 k __t4iIu12 p l m r) (join-old pbranch (1 2 3 4 0) 5 (1 2 3 4 0) p m l r __t4iIu12) (exists st_msk (1 2 0) 2 k m) (join-old st_join (1 4 3 0 2) 3 (1 4 3 0 2) k __t4iIu12 p __t4hUr14 __t4JtR13) (join-old pleaf (0 1) 2 (0 1) __t4JtR13 k) (exists st_join_ans (0 1) 1 __t4hUr14) (join-old st_msk (1 2 0) 2 (1 2 0) k m __t9Q9j15) (join st_msk_ans (0 1) 1 __t9Q9j15 __v0) (neq p __v0) (join st_join_ans (0 1) 1 __t4hUr14 res)) (head (emit st_ins_ans (0 1) __t2YgE11 res)) set.slog:55 #f)
  class ReadTask963 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_joinindex947;  slog::Index** pleafindex948;  slog::Index** st_mskindex949;  slog::Index** $sup9688x54x0x0x0index950;  slog::Index** pbranchindex951;  slog::Index** st_mskindex952;  slog::Index** st_joinindex953;  slog::Index** pleafindex954;  slog::Index** st_join_ansindex955;  slog::Index** st_mskindex956;  slog::Index** st_msk_ansindex957;  slog::Index** st_join_ansindex958;  slog::Index** pbranchdelta959;  slog::Index** st_joindelta960;  slog::Index** pleafdelta961;  slog::Index** st_mskdelta962;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_ins_ans");
      std::vector<u16> ord964({0, 1});
      slog::Relation* readrel965 = db->getRelation("st_ins_ans");
      head_index[0] = readrel965->getIndex(ord964, false);
      outer_rel = db->getRelation("st_ins");
      std::vector<u16> ord966({1, 4, 3, 0, 2});
      slog::Relation* readrel967 = db->getRelation("st_join");
      st_joinindex947 = readrel967->getIndex(ord966, false);
      std::vector<u16> ord968({1, 0});
      slog::Relation* readrel969 = db->getRelation("pleaf");
      pleafindex948 = readrel969->getIndex(ord968, false);
      std::vector<u16> ord970({1, 2, 0});
      slog::Relation* readrel971 = db->getRelation("st_msk");
      st_mskindex949 = readrel971->getIndex(ord970, false);
      std::vector<u16> ord972({0, 1, 6, 4, 2, 3, 5});
      slog::Relation* readrel973 = db->getRelation("$sup9688x54x0x0x0");
      $sup9688x54x0x0x0index950 = readrel973->getIndex(ord972, false);
      std::vector<u16> ord974({1, 2, 3, 4, 0});
      slog::Relation* readrel975 = db->getRelation("pbranch");
      pbranchindex951 = readrel975->getIndex(ord974, false);
      std::vector<u16> ord976({1, 2, 3, 4, 0});
      slog::Relation* readrel977 = db->getRelation("pbranch");
      pbranchdelta959 = readrel977->getIndex(ord976, true);
      std::vector<u16> ord978({1, 2, 0});
      slog::Relation* readrel979 = db->getRelation("st_msk");
      st_mskindex952 = readrel979->getIndex(ord978, false);
      std::vector<u16> ord980({1, 4, 3, 0, 2});
      slog::Relation* readrel981 = db->getRelation("st_join");
      st_joinindex953 = readrel981->getIndex(ord980, false);
      std::vector<u16> ord982({1, 4, 3, 0, 2});
      slog::Relation* readrel983 = db->getRelation("st_join");
      st_joindelta960 = readrel983->getIndex(ord982, true);
      std::vector<u16> ord984({0, 1});
      slog::Relation* readrel985 = db->getRelation("pleaf");
      pleafindex954 = readrel985->getIndex(ord984, false);
      std::vector<u16> ord986({0, 1});
      slog::Relation* readrel987 = db->getRelation("pleaf");
      pleafdelta961 = readrel987->getIndex(ord986, true);
      std::vector<u16> ord988({0, 1});
      slog::Relation* readrel989 = db->getRelation("st_join_ans");
      st_join_ansindex955 = readrel989->getIndex(ord988, false);
      std::vector<u16> ord990({1, 2, 0});
      slog::Relation* readrel991 = db->getRelation("st_msk");
      st_mskindex956 = readrel991->getIndex(ord990, false);
      std::vector<u16> ord992({1, 2, 0});
      slog::Relation* readrel993 = db->getRelation("st_msk");
      st_mskdelta962 = readrel993->getIndex(ord992, true);
      std::vector<u16> ord994({0, 1});
      slog::Relation* readrel995 = db->getRelation("st_msk_ans");
      st_msk_ansindex957 = readrel995->getIndex(ord994, false);
      std::vector<u16> ord996({0, 1});
      slog::Relation* readrel997 = db->getRelation("st_join_ans");
      st_join_ansindex958 = readrel997->getIndex(ord996, false);
  
    }
    ReadTask963(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c5 = _t[0];
        u64 v_c3 = _t[1];
        u64 v_c1 = _t[2];
        if (!slog::exists_probe<5,2>(st_joinindex947, std::array<u64,5>{v_c1, v_c3, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(pleafindex948, std::array<u64,2>{v_c1, 0})) return;
        if (!slog::exists_probe<3,1>(st_mskindex949, std::array<u64,3>{v_c1, 0, 0})) return;
        slog::join_probe<7,3>($sup9688x54x0x0x0index950, std::array<u64,7>{v_c5, v_c1, v_c3, 0, 0, 0, 0}, [&](const std::array<u64,7>& m998) {
          u64 v_c2 = m998[3]; u64 v_c6 = m998[4]; u64 v_c7 = m998[5]; u64 v_c8 = m998[6];
          slog::join_probe_old<5,5>(pbranchindex951, pbranchdelta959, std::array<u64,5>{v_c2, v_c7, v_c6, v_c8, v_c3}, [&](const std::array<u64,5>& m999) {
            if (!slog::exists_probe<3,2>(st_mskindex952, std::array<u64,3>{v_c1, v_c7, 0})) return;
            slog::join_probe_old<5,3>(st_joinindex953, st_joindelta960, std::array<u64,5>{v_c1, v_c3, v_c2, 0, 0}, [&](const std::array<u64,5>& m1000) {
              u64 v_c4 = m1000[3]; u64 v_c0 = m1000[4];
              slog::join_probe_old<2,2>(pleafindex954, pleafdelta961, std::array<u64,2>{v_c0, v_c1}, [&](const std::array<u64,2>& m1001) {
                if (!slog::exists_probe<2,1>(st_join_ansindex955, std::array<u64,2>{v_c4, 0})) return;
                slog::join_probe_old<3,2>(st_mskindex956, st_mskdelta962, std::array<u64,3>{v_c1, v_c7, 0}, [&](const std::array<u64,3>& m1002) {
                  u64 v_c9 = m1002[2];
                  slog::join_probe<2,1>(st_msk_ansindex957, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m1003) {
                    u64 v_c10 = m1003[1];
                    if (v_c2 == v_c10) return;
                    slog::join_probe<2,1>(st_join_ansindex958, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m1004) {
                      u64 v_c11 = m1004[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c5, v_c11}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:55", "delta:st_ins", _fires);
  
      if (!_done)
      {
        ReadTask963* _cont = new ReadTask963(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask963(db,b), false);
  // (crule (pre (let __tconst9B7m280 const6b86b273ff34fce19d6b804e)) (scan st_del_ans __t62j9284 __v0) (body (exists st_bld (3 0 1 2 4) 1 __v0) (join-old st_del (0 2 1) 1 (0 2 1) __t62j9284 k l) (exists pbranch (3 0 1 2 4) 1 l) (exists st_del (2 0 1) 1 k) (exists st_msk (1 2 0) 1 k) (join-old $sup9688x88x0x0x0 (1 2 0 3 4 5) 2 (1 2 0 3 4 5) k l __t3OU0279 m p r) (exists st_bld (1 2 3 4 0) 4 p m __v0 r) (exists st_del (0 2 1) 2 __t3OU0279 k) (exists st_msk (1 2 0) 2 k m) (exists st_msk_ans (1 0) 1 p) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t2u9k278) (exists st_del (0 2 1) 3 __t3OU0279 k __t2u9k278) (join-old st_bld (1 2 3 4 0) 4 (1 2 3 4 0) p m __v0 r __t6UON282) (join-old st_del (0 2 1) 3 (0 2 1) __t3OU0279 k __t2u9k278) (exists st_bld_ans (0 1) 1 __t6UON282) (join-old st_msk (1 2 0) 2 (1 2 0) k m __t5pdy283) (join st_msk_ans (0 1) 2 __t5pdy283 p) (join st_bld_ans (0 1) 1 __t6UON282 res) (let __t4Xlx281 (band k m)) (cmp lt __t4Xlx281 __tconst9B7m280)) (head (emit st_del_ans (0 1) __t3OU0279 res)) set.slog:89 #f)
  class ReadTask1029 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_bldindex1005;  slog::Index** st_delindex1006;  slog::Index** pbranchindex1007;  slog::Index** st_delindex1008;  slog::Index** st_mskindex1009;  slog::Index** $sup9688x88x0x0x0index1010;  slog::Index** st_bldindex1011;  slog::Index** st_delindex1012;  slog::Index** st_mskindex1013;  slog::Index** st_msk_ansindex1014;  slog::Index** pbranchindex1015;  slog::Index** st_delindex1016;  slog::Index** st_bldindex1017;  slog::Index** st_delindex1018;  slog::Index** st_bld_ansindex1019;  slog::Index** st_mskindex1020;  slog::Index** st_msk_ansindex1021;  slog::Index** st_bld_ansindex1022;  slog::Index** st_deldelta1023;  slog::Index** $sup9688x88x0x0x0delta1024;  slog::Index** pbranchdelta1025;  slog::Index** st_blddelta1026;  slog::Index** st_deldelta1027;  slog::Index** st_mskdelta1028;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_del_ans");
      std::vector<u16> ord1030({0, 1});
      slog::Relation* readrel1031 = db->getRelation("st_del_ans");
      head_index[0] = readrel1031->getIndex(ord1030, false);
      outer_rel = db->getRelation("st_del_ans");
      std::vector<u16> ord1032({3, 0, 1, 2, 4});
      slog::Relation* readrel1033 = db->getRelation("st_bld");
      st_bldindex1005 = readrel1033->getIndex(ord1032, false);
      std::vector<u16> ord1034({0, 2, 1});
      slog::Relation* readrel1035 = db->getRelation("st_del");
      st_delindex1006 = readrel1035->getIndex(ord1034, false);
      std::vector<u16> ord1036({0, 2, 1});
      slog::Relation* readrel1037 = db->getRelation("st_del");
      st_deldelta1023 = readrel1037->getIndex(ord1036, true);
      std::vector<u16> ord1038({3, 0, 1, 2, 4});
      slog::Relation* readrel1039 = db->getRelation("pbranch");
      pbranchindex1007 = readrel1039->getIndex(ord1038, false);
      std::vector<u16> ord1040({2, 0, 1});
      slog::Relation* readrel1041 = db->getRelation("st_del");
      st_delindex1008 = readrel1041->getIndex(ord1040, false);
      std::vector<u16> ord1042({1, 2, 0});
      slog::Relation* readrel1043 = db->getRelation("st_msk");
      st_mskindex1009 = readrel1043->getIndex(ord1042, false);
      std::vector<u16> ord1044({1, 2, 0, 3, 4, 5});
      slog::Relation* readrel1045 = db->getRelation("$sup9688x88x0x0x0");
      $sup9688x88x0x0x0index1010 = readrel1045->getIndex(ord1044, false);
      std::vector<u16> ord1046({1, 2, 0, 3, 4, 5});
      slog::Relation* readrel1047 = db->getRelation("$sup9688x88x0x0x0");
      $sup9688x88x0x0x0delta1024 = readrel1047->getIndex(ord1046, true);
      std::vector<u16> ord1048({1, 2, 3, 4, 0});
      slog::Relation* readrel1049 = db->getRelation("st_bld");
      st_bldindex1011 = readrel1049->getIndex(ord1048, false);
      std::vector<u16> ord1050({0, 2, 1});
      slog::Relation* readrel1051 = db->getRelation("st_del");
      st_delindex1012 = readrel1051->getIndex(ord1050, false);
      std::vector<u16> ord1052({1, 2, 0});
      slog::Relation* readrel1053 = db->getRelation("st_msk");
      st_mskindex1013 = readrel1053->getIndex(ord1052, false);
      std::vector<u16> ord1054({1, 0});
      slog::Relation* readrel1055 = db->getRelation("st_msk_ans");
      st_msk_ansindex1014 = readrel1055->getIndex(ord1054, false);
      std::vector<u16> ord1056({1, 2, 3, 4, 0});
      slog::Relation* readrel1057 = db->getRelation("pbranch");
      pbranchindex1015 = readrel1057->getIndex(ord1056, false);
      std::vector<u16> ord1058({1, 2, 3, 4, 0});
      slog::Relation* readrel1059 = db->getRelation("pbranch");
      pbranchdelta1025 = readrel1059->getIndex(ord1058, true);
      std::vector<u16> ord1060({0, 2, 1});
      slog::Relation* readrel1061 = db->getRelation("st_del");
      st_delindex1016 = readrel1061->getIndex(ord1060, false);
      std::vector<u16> ord1062({1, 2, 3, 4, 0});
      slog::Relation* readrel1063 = db->getRelation("st_bld");
      st_bldindex1017 = readrel1063->getIndex(ord1062, false);
      std::vector<u16> ord1064({1, 2, 3, 4, 0});
      slog::Relation* readrel1065 = db->getRelation("st_bld");
      st_blddelta1026 = readrel1065->getIndex(ord1064, true);
      std::vector<u16> ord1066({0, 2, 1});
      slog::Relation* readrel1067 = db->getRelation("st_del");
      st_delindex1018 = readrel1067->getIndex(ord1066, false);
      std::vector<u16> ord1068({0, 2, 1});
      slog::Relation* readrel1069 = db->getRelation("st_del");
      st_deldelta1027 = readrel1069->getIndex(ord1068, true);
      std::vector<u16> ord1070({0, 1});
      slog::Relation* readrel1071 = db->getRelation("st_bld_ans");
      st_bld_ansindex1019 = readrel1071->getIndex(ord1070, false);
      std::vector<u16> ord1072({1, 2, 0});
      slog::Relation* readrel1073 = db->getRelation("st_msk");
      st_mskindex1020 = readrel1073->getIndex(ord1072, false);
      std::vector<u16> ord1074({1, 2, 0});
      slog::Relation* readrel1075 = db->getRelation("st_msk");
      st_mskdelta1028 = readrel1075->getIndex(ord1074, true);
      std::vector<u16> ord1076({0, 1});
      slog::Relation* readrel1077 = db->getRelation("st_msk_ans");
      st_msk_ansindex1021 = readrel1077->getIndex(ord1076, false);
      std::vector<u16> ord1078({0, 1});
      slog::Relation* readrel1079 = db->getRelation("st_bld_ans");
      st_bld_ansindex1022 = readrel1079->getIndex(ord1078, false);
  
    }
    ReadTask1029(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c168 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c169 = _t[0];
        u64 v_c10 = _t[1];
        if (!slog::exists_probe<5,1>(st_bldindex1005, std::array<u64,5>{v_c10, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(st_delindex1006, st_deldelta1023, std::array<u64,3>{v_c169, 0, 0}, [&](const std::array<u64,3>& m1080) {
          u64 v_c1 = m1080[1]; u64 v_c6 = m1080[2];
          if (!slog::exists_probe<5,1>(pbranchindex1007, std::array<u64,5>{v_c6, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(st_delindex1008, std::array<u64,3>{v_c1, 0, 0})) return;
          if (!slog::exists_probe<3,1>(st_mskindex1009, std::array<u64,3>{v_c1, 0, 0})) return;
          slog::join_probe_old<6,2>($sup9688x88x0x0x0index1010, $sup9688x88x0x0x0delta1024, std::array<u64,6>{v_c1, v_c6, 0, 0, 0, 0}, [&](const std::array<u64,6>& m1081) {
            u64 v_c170 = m1081[2]; u64 v_c7 = m1081[3]; u64 v_c2 = m1081[4]; u64 v_c8 = m1081[5];
            if (!slog::exists_probe<5,4>(st_bldindex1011, std::array<u64,5>{v_c2, v_c7, v_c10, v_c8, 0})) return;
            if (!slog::exists_probe<3,2>(st_delindex1012, std::array<u64,3>{v_c170, v_c1, 0})) return;
            if (!slog::exists_probe<3,2>(st_mskindex1013, std::array<u64,3>{v_c1, v_c7, 0})) return;
            if (!slog::exists_probe<2,1>(st_msk_ansindex1014, std::array<u64,2>{v_c2, 0})) return;
            slog::join_probe_old<5,4>(pbranchindex1015, pbranchdelta1025, std::array<u64,5>{v_c2, v_c7, v_c6, v_c8, 0}, [&](const std::array<u64,5>& m1082) {
              u64 v_c171 = m1082[4];
              if (!slog::exists_probe<3,3>(st_delindex1016, std::array<u64,3>{v_c170, v_c1, v_c171})) return;
              slog::join_probe_old<5,4>(st_bldindex1017, st_blddelta1026, std::array<u64,5>{v_c2, v_c7, v_c10, v_c8, 0}, [&](const std::array<u64,5>& m1083) {
                u64 v_c172 = m1083[4];
                slog::join_probe_old<3,3>(st_delindex1018, st_deldelta1027, std::array<u64,3>{v_c170, v_c1, v_c171}, [&](const std::array<u64,3>& m1084) {
                  if (!slog::exists_probe<2,1>(st_bld_ansindex1019, std::array<u64,2>{v_c172, 0})) return;
                  slog::join_probe_old<3,2>(st_mskindex1020, st_mskdelta1028, std::array<u64,3>{v_c1, v_c7, 0}, [&](const std::array<u64,3>& m1085) {
                    u64 v_c173 = m1085[2];
                    slog::join_probe<2,2>(st_msk_ansindex1021, std::array<u64,2>{v_c173, v_c2}, [&](const std::array<u64,2>& m1086) {
                      slog::join_probe<2,1>(st_bld_ansindex1022, std::array<u64,2>{v_c172, 0}, [&](const std::array<u64,2>& m1087) {
                        u64 v_c11 = m1087[1];
                        u64 v_c174 = _prim_band(db, v_c1, v_c7);
                        if (v_c174 == slog_error) { slog::emit_pending_error(db, "set.slog:89"); return; }
                        u64 v_c175 = _prim_lt(db, v_c174, v_c168);
                        if (v_c175 == slog_error) { slog::emit_pending_error(db, "set.slog:89"); return; }
                        if (!v_c175) return;
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c170, v_c11}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("set.slog:89", "delta:st_del_ans", _fires);
  
      if (!_done)
      {
        ReadTask1029* _cont = new ReadTask1029(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1029(db,b), false);
  // (crule (pre (let __trid4bDq789 const76a4fedc25549f0939d52fb7) (let __trel1o0k790 const26c89ee8ccc4ea998fd1a912) (let __tcol6PPW791 const4e07408562bedb8b60ce05c1)) (scan st_del __t8asA369 l k) (body (exists $sup9688x88x0x0x0 (1 2 0 3 4 5) 2 k l) (exists st_msk (1 2 0) 1 k) (join st_del_ans (0 1) 1 __t8asA369 __v0) (join $sup9688x88x0x0x0 (1 2 0 3 4 5) 2 k l __d0 m p r) (exists st_msk_ans (1 0) 1 p) (join st_msk (1 2 0) 2 k m __t5gdG368) (join st_msk_ans (0 1) 2 __t5gdG368 p)) (head (tycheck r (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid4bDq789 __trel1o0k790 __tcol6PPW791 (1 2 3 4 0)) (mkstruct st_bld (1 2 3 4 0) __3BTR788 p m __v0 r)) set.slog:89 #f)
  class ReadTask1099 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x88x0x0x0index1089;  slog::Index** st_mskindex1090;  slog::Index** st_del_ansindex1091;  slog::Index** $sup9688x88x0x0x0index1092;  slog::Index** st_msk_ansindex1093;  slog::Index** st_mskindex1094;  slog::Index** st_msk_ansindex1095;
    u32 sid1097;  u32 sid1096;  u32 sid1098;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("st_bld");
      outer_rel = db->getRelation("st_del");
      std::vector<u16> ord1100({1, 2, 0, 3, 4, 5});
      slog::Relation* readrel1101 = db->getRelation("$sup9688x88x0x0x0");
      $sup9688x88x0x0x0index1089 = readrel1101->getIndex(ord1100, false);
      std::vector<u16> ord1102({1, 2, 0});
      slog::Relation* readrel1103 = db->getRelation("st_msk");
      st_mskindex1090 = readrel1103->getIndex(ord1102, false);
      std::vector<u16> ord1104({0, 1});
      slog::Relation* readrel1105 = db->getRelation("st_del_ans");
      st_del_ansindex1091 = readrel1105->getIndex(ord1104, false);
      std::vector<u16> ord1106({1, 2, 0, 3, 4, 5});
      slog::Relation* readrel1107 = db->getRelation("$sup9688x88x0x0x0");
      $sup9688x88x0x0x0index1092 = readrel1107->getIndex(ord1106, false);
      std::vector<u16> ord1108({1, 0});
      slog::Relation* readrel1109 = db->getRelation("st_msk_ans");
      st_msk_ansindex1093 = readrel1109->getIndex(ord1108, false);
      std::vector<u16> ord1110({1, 2, 0});
      slog::Relation* readrel1111 = db->getRelation("st_msk");
      st_mskindex1094 = readrel1111->getIndex(ord1110, false);
      std::vector<u16> ord1112({0, 1});
      slog::Relation* readrel1113 = db->getRelation("st_msk_ans");
      st_msk_ansindex1095 = readrel1113->getIndex(ord1112, false);
      sid1097 = db->getRelation("_enum")->getStructId();
      sid1096 = db->getRelation("pbranch")->getStructId();
      sid1098 = db->getRelation("pleaf")->getStructId();
  
    }
    ReadTask1099(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c176 = v_const76a4fedc25549f0939d52fb7;
      u64 v_c177 = v_const26c89ee8ccc4ea998fd1a912;
      u64 v_c178 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c179 = _t[0];
        u64 v_c6 = _t[1];
        u64 v_c1 = _t[2];
        if (!slog::exists_probe<6,2>($sup9688x88x0x0x0index1089, std::array<u64,6>{v_c1, v_c6, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mskindex1090, std::array<u64,3>{v_c1, 0, 0})) return;
        slog::join_probe<2,1>(st_del_ansindex1091, std::array<u64,2>{v_c179, 0}, [&](const std::array<u64,2>& m1114) {
          u64 v_c10 = m1114[1];
          slog::join_probe<6,2>($sup9688x88x0x0x0index1092, std::array<u64,6>{v_c1, v_c6, 0, 0, 0, 0}, [&](const std::array<u64,6>& m1115) {
            u64 v_c61 = m1115[2]; u64 v_c7 = m1115[3]; u64 v_c2 = m1115[4]; u64 v_c8 = m1115[5];
            if (!slog::exists_probe<2,1>(st_msk_ansindex1093, std::array<u64,2>{v_c2, 0})) return;
            slog::join_probe<3,2>(st_mskindex1094, std::array<u64,3>{v_c1, v_c7, 0}, [&](const std::array<u64,3>& m1116) {
              u64 v_c180 = m1116[2];
              slog::join_probe<2,2>(st_msk_ansindex1095, std::array<u64,2>{v_c180, v_c2}, [&](const std::array<u64,2>& m1117) {
                ++_fires;
                if (!((is_struct(v_c8) && (decode_struct_id(v_c8) == sid1096 || decode_struct_id(v_c8) == sid1097 || decode_struct_id(v_c8) == sid1098))))
                {
                  slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c176, v_c177, v_c178, v_c8}, std::array<u16,5>{1, 2, 3, 4, 0});
                  return;
                }
                slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c2, v_c7, v_c10, v_c8}, std::array<u16,5>{1, 2, 3, 4, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("set.slog:89", "delta:st_del", _fires);
  
      if (!_done)
      {
        ReadTask1099* _cont = new ReadTask1099(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1099(db,b), false);
  // (crule (pre (let __trid7Sws818 const987d6cf2e5032ff135cc0c65) (let __trel4XPm819 const26c89ee8ccc4ea998fd1a912) (let __tcol9qQF820 const4e07408562bedb8b60ce05c1)) (scan st_msk __t9Eou545 q m) (body (exists $sup9688x139x0x0x0 (2 5 4 0 1 3 6 7 8) 2 m q) (exists pbranch (1 2 3 4 0) 1 q) (join st_msk_ans (0 1) 1 __t9Eou545 p) (join $sup9688x139x0x0x0 (2 5 4 0 1 3 6 7 8) 3 m q p __d0 l n r u v) (exists st_diff (1 2 0) 1 l) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t3QFk546) (join-old st_diff (1 2 0) 2 (1 2 0) l __t3QFk546 __t9ide547) (join st_diff_ans (0 1) 1 __t9ide547 __v0)) (head (tycheck r (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid7Sws818 __trel4XPm819 __tcol9qQF820 (1 2 3 4 0)) (mkstruct st_bld (1 2 3 4 0) __1n2S817 p m __v0 r)) set.slog:140 #f)
  class ReadTask1131 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x139x0x0x0index1118;  slog::Index** pbranchindex1119;  slog::Index** st_msk_ansindex1120;  slog::Index** $sup9688x139x0x0x0index1121;  slog::Index** st_diffindex1122;  slog::Index** pbranchindex1123;  slog::Index** st_diffindex1124;  slog::Index** st_diff_ansindex1125;  slog::Index** pbranchdelta1126;  slog::Index** st_diffdelta1127;
    u32 sid1129;  u32 sid1128;  u32 sid1130;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("st_bld");
      outer_rel = db->getRelation("st_msk");
      std::vector<u16> ord1132({2, 5, 4, 0, 1, 3, 6, 7, 8});
      slog::Relation* readrel1133 = db->getRelation("$sup9688x139x0x0x0");
      $sup9688x139x0x0x0index1118 = readrel1133->getIndex(ord1132, false);
      std::vector<u16> ord1134({1, 2, 3, 4, 0});
      slog::Relation* readrel1135 = db->getRelation("pbranch");
      pbranchindex1119 = readrel1135->getIndex(ord1134, false);
      std::vector<u16> ord1136({0, 1});
      slog::Relation* readrel1137 = db->getRelation("st_msk_ans");
      st_msk_ansindex1120 = readrel1137->getIndex(ord1136, false);
      std::vector<u16> ord1138({2, 5, 4, 0, 1, 3, 6, 7, 8});
      slog::Relation* readrel1139 = db->getRelation("$sup9688x139x0x0x0");
      $sup9688x139x0x0x0index1121 = readrel1139->getIndex(ord1138, false);
      std::vector<u16> ord1140({1, 2, 0});
      slog::Relation* readrel1141 = db->getRelation("st_diff");
      st_diffindex1122 = readrel1141->getIndex(ord1140, false);
      std::vector<u16> ord1142({1, 2, 3, 4, 0});
      slog::Relation* readrel1143 = db->getRelation("pbranch");
      pbranchindex1123 = readrel1143->getIndex(ord1142, false);
      std::vector<u16> ord1144({1, 2, 3, 4, 0});
      slog::Relation* readrel1145 = db->getRelation("pbranch");
      pbranchdelta1126 = readrel1145->getIndex(ord1144, true);
      std::vector<u16> ord1146({1, 2, 0});
      slog::Relation* readrel1147 = db->getRelation("st_diff");
      st_diffindex1124 = readrel1147->getIndex(ord1146, false);
      std::vector<u16> ord1148({1, 2, 0});
      slog::Relation* readrel1149 = db->getRelation("st_diff");
      st_diffdelta1127 = readrel1149->getIndex(ord1148, true);
      std::vector<u16> ord1150({0, 1});
      slog::Relation* readrel1151 = db->getRelation("st_diff_ans");
      st_diff_ansindex1125 = readrel1151->getIndex(ord1150, false);
      sid1129 = db->getRelation("_enum")->getStructId();
      sid1128 = db->getRelation("pbranch")->getStructId();
      sid1130 = db->getRelation("pleaf")->getStructId();
  
    }
    ReadTask1131(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c181 = v_const987d6cf2e5032ff135cc0c65;
      u64 v_c182 = v_const26c89ee8ccc4ea998fd1a912;
      u64 v_c183 = v_const4e07408562bedb8b60ce05c1;
  
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
        u64 v_c16 = _t[1];
        u64 v_c7 = _t[2];
        if (!slog::exists_probe<9,2>($sup9688x139x0x0x0index1118, std::array<u64,9>{v_c7, v_c16, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex1119, std::array<u64,5>{v_c16, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(st_msk_ansindex1120, std::array<u64,2>{v_c184, 0}, [&](const std::array<u64,2>& m1152) {
          u64 v_c2 = m1152[1];
          slog::join_probe<9,3>($sup9688x139x0x0x0index1121, std::array<u64,9>{v_c7, v_c16, v_c2, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m1153) {
            u64 v_c61 = m1153[3]; u64 v_c6 = m1153[4]; u64 v_c15 = m1153[5]; u64 v_c8 = m1153[6]; u64 v_c17 = m1153[7]; u64 v_c18 = m1153[8];
            if (!slog::exists_probe<3,1>(st_diffindex1122, std::array<u64,3>{v_c6, 0, 0})) return;
            slog::join_probe_old<5,4>(pbranchindex1123, pbranchdelta1126, std::array<u64,5>{v_c16, v_c15, v_c17, v_c18, 0}, [&](const std::array<u64,5>& m1154) {
              u64 v_c185 = m1154[4];
              slog::join_probe_old<3,2>(st_diffindex1124, st_diffdelta1127, std::array<u64,3>{v_c6, v_c185, 0}, [&](const std::array<u64,3>& m1155) {
                u64 v_c186 = m1155[2];
                slog::join_probe<2,1>(st_diff_ansindex1125, std::array<u64,2>{v_c186, 0}, [&](const std::array<u64,2>& m1156) {
                  u64 v_c10 = m1156[1];
                  ++_fires;
                  if (!((is_struct(v_c8) && (decode_struct_id(v_c8) == sid1128 || decode_struct_id(v_c8) == sid1129 || decode_struct_id(v_c8) == sid1130))))
                  {
                    slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c181, v_c182, v_c183, v_c8}, std::array<u16,5>{1, 2, 3, 4, 0});
                    return;
                  }
                  slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c2, v_c7, v_c10, v_c8}, std::array<u16,5>{1, 2, 3, 4, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("set.slog:140", "delta:st_msk", _fires);
  
      if (!_done)
      {
        ReadTask1131* _cont = new ReadTask1131(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1131(db,b), false);
  // (crule (pre (let __trid0O8l910 const1e44311dd5d36c3a7dc21dfa) (let __trel2X7j911 const26c89ee8ccc4ea998fd1a912) (let __tcol3tdZ912 constd4735e3a265e16eee03f5971)) (scan st_del __t56Eo399 r k) (body (exists $sup9688x90x0x0x0 (1 5 0 2 3 4) 2 k r) (exists st_msk (1 2 0) 1 k) (join st_del_ans (0 1) 1 __t56Eo399 __v0) (join $sup9688x90x0x0x0 (1 5 0 2 3 4) 2 k r __d0 l m p) (exists st_msk_ans (1 0) 1 p) (join st_msk (1 2 0) 2 k m __t8Ytg398) (join st_msk_ans (0 1) 2 __t8Ytg398 p)) (head (tycheck l (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid0O8l910 __trel2X7j911 __tcol3tdZ912 (1 2 3 4 0)) (mkstruct st_bld (1 2 3 4 0) __6yFQ909 p m l __v0)) set.slog:91 #f)
  class ReadTask1167 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x90x0x0x0index1157;  slog::Index** st_mskindex1158;  slog::Index** st_del_ansindex1159;  slog::Index** $sup9688x90x0x0x0index1160;  slog::Index** st_msk_ansindex1161;  slog::Index** st_mskindex1162;  slog::Index** st_msk_ansindex1163;
    u32 sid1165;  u32 sid1164;  u32 sid1166;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("st_bld");
      outer_rel = db->getRelation("st_del");
      std::vector<u16> ord1168({1, 5, 0, 2, 3, 4});
      slog::Relation* readrel1169 = db->getRelation("$sup9688x90x0x0x0");
      $sup9688x90x0x0x0index1157 = readrel1169->getIndex(ord1168, false);
      std::vector<u16> ord1170({1, 2, 0});
      slog::Relation* readrel1171 = db->getRelation("st_msk");
      st_mskindex1158 = readrel1171->getIndex(ord1170, false);
      std::vector<u16> ord1172({0, 1});
      slog::Relation* readrel1173 = db->getRelation("st_del_ans");
      st_del_ansindex1159 = readrel1173->getIndex(ord1172, false);
      std::vector<u16> ord1174({1, 5, 0, 2, 3, 4});
      slog::Relation* readrel1175 = db->getRelation("$sup9688x90x0x0x0");
      $sup9688x90x0x0x0index1160 = readrel1175->getIndex(ord1174, false);
      std::vector<u16> ord1176({1, 0});
      slog::Relation* readrel1177 = db->getRelation("st_msk_ans");
      st_msk_ansindex1161 = readrel1177->getIndex(ord1176, false);
      std::vector<u16> ord1178({1, 2, 0});
      slog::Relation* readrel1179 = db->getRelation("st_msk");
      st_mskindex1162 = readrel1179->getIndex(ord1178, false);
      std::vector<u16> ord1180({0, 1});
      slog::Relation* readrel1181 = db->getRelation("st_msk_ans");
      st_msk_ansindex1163 = readrel1181->getIndex(ord1180, false);
      sid1165 = db->getRelation("_enum")->getStructId();
      sid1164 = db->getRelation("pbranch")->getStructId();
      sid1166 = db->getRelation("pleaf")->getStructId();
  
    }
    ReadTask1167(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c187 = v_const1e44311dd5d36c3a7dc21dfa;
      u64 v_c188 = v_const26c89ee8ccc4ea998fd1a912;
      u64 v_c189 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c190 = _t[0];
        u64 v_c8 = _t[1];
        u64 v_c1 = _t[2];
        if (!slog::exists_probe<6,2>($sup9688x90x0x0x0index1157, std::array<u64,6>{v_c1, v_c8, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mskindex1158, std::array<u64,3>{v_c1, 0, 0})) return;
        slog::join_probe<2,1>(st_del_ansindex1159, std::array<u64,2>{v_c190, 0}, [&](const std::array<u64,2>& m1182) {
          u64 v_c10 = m1182[1];
          slog::join_probe<6,2>($sup9688x90x0x0x0index1160, std::array<u64,6>{v_c1, v_c8, 0, 0, 0, 0}, [&](const std::array<u64,6>& m1183) {
            u64 v_c61 = m1183[2]; u64 v_c6 = m1183[3]; u64 v_c7 = m1183[4]; u64 v_c2 = m1183[5];
            if (!slog::exists_probe<2,1>(st_msk_ansindex1161, std::array<u64,2>{v_c2, 0})) return;
            slog::join_probe<3,2>(st_mskindex1162, std::array<u64,3>{v_c1, v_c7, 0}, [&](const std::array<u64,3>& m1184) {
              u64 v_c191 = m1184[2];
              slog::join_probe<2,2>(st_msk_ansindex1163, std::array<u64,2>{v_c191, v_c2}, [&](const std::array<u64,2>& m1185) {
                ++_fires;
                if (!((is_struct(v_c6) && (decode_struct_id(v_c6) == sid1164 || decode_struct_id(v_c6) == sid1165 || decode_struct_id(v_c6) == sid1166))))
                {
                  slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c187, v_c188, v_c189, v_c6}, std::array<u16,5>{1, 2, 3, 4, 0});
                  return;
                }
                slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c2, v_c7, v_c6, v_c10}, std::array<u16,5>{1, 2, 3, 4, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("set.slog:91", "delta:st_del", _fires);
  
      if (!_done)
      {
        ReadTask1167* _cont = new ReadTask1167(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1167(db,b), false);
  // (crule (pre (let __tconst8cca353 const6b86b273ff34fce19d6b804e)) (scan st_hsb_ans __t75bg356 __v3) (body (exists st_hsb_ans (0 1) 1 __t75bg356) (exists $sup9688x36x0x0x2 (1 6 0 2 3 4 5 7 8 9 10) 2 __t75bg356 __v3) (exists $sup9688x36x0x0x1 (1 2 0 3 4 5 6) 1 __t75bg356) (join-old st_hsb_ans (0 1) 1 (0 1) __t75bg356 __v1) (exists $sup9688x36x0x0x2 (1 5 6 7 0 2 3 4 8 9 10) 3 __t75bg356 __v1 __v3) (exists st_msk (2 0 1) 1 __v1) (join-old st_hsb_ans (0 1) 1 (0 1) __t75bg356 __v0) (exists $sup9688x36x0x0x1 (1 2 0 3 4 5 6) 2 __t75bg356 __v0) (join $sup9688x36x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) 4 __t75bg356 __v0 __v3 __v1 __t0kmv352 dup66Lo1333 dup68E21334 p0 p1 t0 t1) (eq __t75bg356 dup68E21334) (eq __t75bg356 dup66Lo1333) (join $sup9688x36x0x0x1 (0 3 4 5 6 1 2) 7 __t0kmv352 p0 p1 t0 t1 __t75bg356 __v0) (join $sup9688x36x0x0x0 (1 0 2 3 4) 5 p0 __t0kmv352 p1 t0 t1) (join-old st_join (1 2 3 4 0) 5 (1 2 3 4 0) p0 t0 p1 t1 __t0kmv352) (join-old st_msk (1 2 0) 2 (1 2 0) p0 __v1 __t9xbE359) (join-old st_msk_ans (0 1) 1 (0 1) __t9xbE359 __v2) (let __t5oQR360 (bxor p0 p1)) (join-old st_hsb (0 1) 2 (0 1) __t75bg356 __t5oQR360) (let __t3ChK354 (band p0 __v0)) (cmp lt __t3ChK354 __tconst8cca353)) (head (emit-temp temp3xVH1332 __t0kmv352 __v2 __v3 t0 t1) (mkstruct pbranch (1 2 3 4 0) __t4fDE351 __v2 __v3 t0 t1)) set.slog:37 #f)
  class ReadTask1207 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_hsb_ansindex1186;  slog::Index** $sup9688x36x0x0x2index1187;  slog::Index** $sup9688x36x0x0x1index1188;  slog::Index** st_hsb_ansindex1189;  slog::Index** $sup9688x36x0x0x2index1190;  slog::Index** st_mskindex1191;  slog::Index** st_hsb_ansindex1192;  slog::Index** $sup9688x36x0x0x1index1193;  slog::Index** $sup9688x36x0x0x2index1194;  slog::Index** $sup9688x36x0x0x1index1195;  slog::Index** $sup9688x36x0x0x0index1196;  slog::Index** st_joinindex1197;  slog::Index** st_mskindex1198;  slog::Index** st_msk_ansindex1199;  slog::Index** st_hsbindex1200;  slog::Index** st_hsb_ansdelta1201;  slog::Index** st_hsb_ansdelta1202;  slog::Index** st_joindelta1203;  slog::Index** st_mskdelta1204;  slog::Index** st_msk_ansdelta1205;  slog::Index** st_hsbdelta1206;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3xVH1332");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("st_hsb_ans");
      std::vector<u16> ord1208({0, 1});
      slog::Relation* readrel1209 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex1186 = readrel1209->getIndex(ord1208, false);
      std::vector<u16> ord1210({1, 6, 0, 2, 3, 4, 5, 7, 8, 9, 10});
      slog::Relation* readrel1211 = db->getRelation("$sup9688x36x0x0x2");
      $sup9688x36x0x0x2index1187 = readrel1211->getIndex(ord1210, false);
      std::vector<u16> ord1212({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel1213 = db->getRelation("$sup9688x36x0x0x1");
      $sup9688x36x0x0x1index1188 = readrel1213->getIndex(ord1212, false);
      std::vector<u16> ord1214({0, 1});
      slog::Relation* readrel1215 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex1189 = readrel1215->getIndex(ord1214, false);
      std::vector<u16> ord1216({0, 1});
      slog::Relation* readrel1217 = db->getRelation("st_hsb_ans");
      st_hsb_ansdelta1201 = readrel1217->getIndex(ord1216, true);
      std::vector<u16> ord1218({1, 5, 6, 7, 0, 2, 3, 4, 8, 9, 10});
      slog::Relation* readrel1219 = db->getRelation("$sup9688x36x0x0x2");
      $sup9688x36x0x0x2index1190 = readrel1219->getIndex(ord1218, false);
      std::vector<u16> ord1220({2, 0, 1});
      slog::Relation* readrel1221 = db->getRelation("st_msk");
      st_mskindex1191 = readrel1221->getIndex(ord1220, false);
      std::vector<u16> ord1222({0, 1});
      slog::Relation* readrel1223 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex1192 = readrel1223->getIndex(ord1222, false);
      std::vector<u16> ord1224({0, 1});
      slog::Relation* readrel1225 = db->getRelation("st_hsb_ans");
      st_hsb_ansdelta1202 = readrel1225->getIndex(ord1224, true);
      std::vector<u16> ord1226({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel1227 = db->getRelation("$sup9688x36x0x0x1");
      $sup9688x36x0x0x1index1193 = readrel1227->getIndex(ord1226, false);
      std::vector<u16> ord1228({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel1229 = db->getRelation("$sup9688x36x0x0x2");
      $sup9688x36x0x0x2index1194 = readrel1229->getIndex(ord1228, false);
      std::vector<u16> ord1230({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel1231 = db->getRelation("$sup9688x36x0x0x1");
      $sup9688x36x0x0x1index1195 = readrel1231->getIndex(ord1230, false);
      std::vector<u16> ord1232({1, 0, 2, 3, 4});
      slog::Relation* readrel1233 = db->getRelation("$sup9688x36x0x0x0");
      $sup9688x36x0x0x0index1196 = readrel1233->getIndex(ord1232, false);
      std::vector<u16> ord1234({1, 2, 3, 4, 0});
      slog::Relation* readrel1235 = db->getRelation("st_join");
      st_joinindex1197 = readrel1235->getIndex(ord1234, false);
      std::vector<u16> ord1236({1, 2, 3, 4, 0});
      slog::Relation* readrel1237 = db->getRelation("st_join");
      st_joindelta1203 = readrel1237->getIndex(ord1236, true);
      std::vector<u16> ord1238({1, 2, 0});
      slog::Relation* readrel1239 = db->getRelation("st_msk");
      st_mskindex1198 = readrel1239->getIndex(ord1238, false);
      std::vector<u16> ord1240({1, 2, 0});
      slog::Relation* readrel1241 = db->getRelation("st_msk");
      st_mskdelta1204 = readrel1241->getIndex(ord1240, true);
      std::vector<u16> ord1242({0, 1});
      slog::Relation* readrel1243 = db->getRelation("st_msk_ans");
      st_msk_ansindex1199 = readrel1243->getIndex(ord1242, false);
      std::vector<u16> ord1244({0, 1});
      slog::Relation* readrel1245 = db->getRelation("st_msk_ans");
      st_msk_ansdelta1205 = readrel1245->getIndex(ord1244, true);
      std::vector<u16> ord1246({0, 1});
      slog::Relation* readrel1247 = db->getRelation("st_hsb");
      st_hsbindex1200 = readrel1247->getIndex(ord1246, false);
      std::vector<u16> ord1248({0, 1});
      slog::Relation* readrel1249 = db->getRelation("st_hsb");
      st_hsbdelta1206 = readrel1249->getIndex(ord1248, true);
  
    }
    ReadTask1207(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c192 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c193 = _t[0];
        u64 v_c194 = _t[1];
        if (!slog::exists_probe<2,1>(st_hsb_ansindex1186, std::array<u64,2>{v_c193, 0})) return;
        if (!slog::exists_probe<11,2>($sup9688x36x0x0x2index1187, std::array<u64,11>{v_c193, v_c194, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<7,1>($sup9688x36x0x0x1index1188, std::array<u64,7>{v_c193, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<2,1>(st_hsb_ansindex1189, st_hsb_ansdelta1201, std::array<u64,2>{v_c193, 0}, [&](const std::array<u64,2>& m1250) {
          u64 v_c33 = m1250[1];
          if (!slog::exists_probe<11,3>($sup9688x36x0x0x2index1190, std::array<u64,11>{v_c193, v_c33, v_c194, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(st_mskindex1191, std::array<u64,3>{v_c33, 0, 0})) return;
          slog::join_probe_old<2,1>(st_hsb_ansindex1192, st_hsb_ansdelta1202, std::array<u64,2>{v_c193, 0}, [&](const std::array<u64,2>& m1251) {
            u64 v_c10 = m1251[1];
            if (!slog::exists_probe<7,2>($sup9688x36x0x0x1index1193, std::array<u64,7>{v_c193, v_c10, 0, 0, 0, 0, 0})) return;
            slog::join_probe<11,4>($sup9688x36x0x0x2index1194, std::array<u64,11>{v_c193, v_c10, v_c194, v_c33, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m1252) {
              u64 v_c195 = m1252[4]; u64 v_c196 = m1252[5]; u64 v_c197 = m1252[6]; u64 v_c198 = m1252[7]; u64 v_c199 = m1252[8]; u64 v_c200 = m1252[9]; u64 v_c201 = m1252[10];
              if (v_c193 != v_c197) return;
              if (v_c193 != v_c196) return;
              slog::join_probe<7,7>($sup9688x36x0x0x1index1195, std::array<u64,7>{v_c195, v_c198, v_c199, v_c200, v_c201, v_c193, v_c10}, [&](const std::array<u64,7>& m1253) {
                slog::join_probe<5,5>($sup9688x36x0x0x0index1196, std::array<u64,5>{v_c198, v_c195, v_c199, v_c200, v_c201}, [&](const std::array<u64,5>& m1254) {
                  slog::join_probe_old<5,5>(st_joinindex1197, st_joindelta1203, std::array<u64,5>{v_c198, v_c200, v_c199, v_c201, v_c195}, [&](const std::array<u64,5>& m1255) {
                    slog::join_probe_old<3,2>(st_mskindex1198, st_mskdelta1204, std::array<u64,3>{v_c198, v_c33, 0}, [&](const std::array<u64,3>& m1256) {
                      u64 v_c202 = m1256[2];
                      slog::join_probe_old<2,1>(st_msk_ansindex1199, st_msk_ansdelta1205, std::array<u64,2>{v_c202, 0}, [&](const std::array<u64,2>& m1257) {
                        u64 v_c35 = m1257[1];
                        u64 v_c203 = _prim_bxor(db, v_c198, v_c199);
                        if (v_c203 == slog_error) { slog::emit_pending_error(db, "set.slog:37"); return; }
                        slog::join_probe_old<2,2>(st_hsbindex1200, st_hsbdelta1206, std::array<u64,2>{v_c193, v_c203}, [&](const std::array<u64,2>& m1258) {
                          u64 v_c204 = _prim_band(db, v_c198, v_c10);
                          if (v_c204 == slog_error) { slog::emit_pending_error(db, "set.slog:37"); return; }
                          u64 v_c205 = _prim_lt(db, v_c204, v_c192);
                          if (v_c205 == slog_error) { slog::emit_pending_error(db, "set.slog:37"); return; }
                          if (!v_c205) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c195, v_c35, v_c194, v_c200, v_c201});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c35, v_c194, v_c200, v_c201}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:37", "delta:st_hsb_ans", _fires);
  
      if (!_done)
      {
        ReadTask1207* _cont = new ReadTask1207(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1207(db,b), false);
  // (crule (pre (let __trid6BRy1044 constb0e9a61bdf716031c5ca8c29) (let __trel1qQv1045 const99e1cbf3d792d4a87847a801) (let __tcol7IDH1046 const5feceb66ffc86f38d952786c) (let __trel6cc81047 const99e1cbf3d792d4a87847a801) (let __tcol07o51048 const6b86b273ff34fce19d6b804e)) (scan $sup9688x52x0x0x1 __d0 __d1 k l m p r) (body) (head (tycheck r (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid6BRy1044 __trel1qQv1045 __tcol7IDH1046 (1 2 3 4 0)) (tycheck k (accept int) __trid6BRy1044 __trel6cc81047 __tcol07o51048 (1 2 3 4 0)) (mkstruct st_ins (1 2 0) __2Uzn1043 r k)) set.slog:53 #f)
  class ReadTask1263 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid1261;  u32 sid1260;  u32 sid1262;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("st_ins");
      outer_rel = db->getRelation("$sup9688x52x0x0x1");
      sid1261 = db->getRelation("_enum")->getStructId();
      sid1260 = db->getRelation("pbranch")->getStructId();
      sid1262 = db->getRelation("pleaf")->getStructId();
  
    }
    ReadTask1263(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c206 = v_constb0e9a61bdf716031c5ca8c29;
      u64 v_c207 = v_const99e1cbf3d792d4a87847a801;
      u64 v_c208 = v_const5feceb66ffc86f38d952786c;
      u64 v_c209 = v_const99e1cbf3d792d4a87847a801;
      u64 v_c210 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c61 = _t[0];
        u64 v_c211 = _t[1];
        u64 v_c1 = _t[2];
        u64 v_c6 = _t[3];
        u64 v_c7 = _t[4];
        u64 v_c2 = _t[5];
        u64 v_c8 = _t[6];
        ++_fires;
        if (!((is_struct(v_c8) && (decode_struct_id(v_c8) == sid1260 || decode_struct_id(v_c8) == sid1261 || decode_struct_id(v_c8) == sid1262))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c206, v_c207, v_c208, v_c8}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c1)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c206, v_c209, v_c210, v_c1}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c8, v_c1}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("set.slog:53", "delta:$sup9688x52x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask1263* _cont = new ReadTask1263(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1263(db,b), false);
  // (crule (pre (let __trid5BEA1071 const81906d9241165d9f6a541e47) (let __trel7nV51072 const26c89ee8ccc4ea998fd1a912) (let __tcol7NRn1073 constd4735e3a265e16eee03f5971)) (scan st_msk __t3ZZb548 q m) (body (exists $sup9688x142x0x0x0 (2 5 4 0 1 3 6 7 8) 2 m q) (exists pbranch (1 2 3 4 0) 1 q) (join st_msk_ans (0 1) 1 __t3ZZb548 p) (join $sup9688x142x0x0x0 (2 5 4 0 1 3 6 7 8) 3 m q p __d0 l n r u v) (exists st_diff (1 2 0) 1 r) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t3eTQ549) (join-old st_diff (1 2 0) 2 (1 2 0) r __t3eTQ549 __t7sr4550) (join st_diff_ans (0 1) 1 __t7sr4550 __v0)) (head (tycheck l (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid5BEA1071 __trel7nV51072 __tcol7NRn1073 (1 2 3 4 0)) (mkstruct st_bld (1 2 3 4 0) __2Xjw1070 p m l __v0)) set.slog:143 #f)
  class ReadTask1277 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x142x0x0x0index1264;  slog::Index** pbranchindex1265;  slog::Index** st_msk_ansindex1266;  slog::Index** $sup9688x142x0x0x0index1267;  slog::Index** st_diffindex1268;  slog::Index** pbranchindex1269;  slog::Index** st_diffindex1270;  slog::Index** st_diff_ansindex1271;  slog::Index** pbranchdelta1272;  slog::Index** st_diffdelta1273;
    u32 sid1275;  u32 sid1274;  u32 sid1276;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("st_bld");
      outer_rel = db->getRelation("st_msk");
      std::vector<u16> ord1278({2, 5, 4, 0, 1, 3, 6, 7, 8});
      slog::Relation* readrel1279 = db->getRelation("$sup9688x142x0x0x0");
      $sup9688x142x0x0x0index1264 = readrel1279->getIndex(ord1278, false);
      std::vector<u16> ord1280({1, 2, 3, 4, 0});
      slog::Relation* readrel1281 = db->getRelation("pbranch");
      pbranchindex1265 = readrel1281->getIndex(ord1280, false);
      std::vector<u16> ord1282({0, 1});
      slog::Relation* readrel1283 = db->getRelation("st_msk_ans");
      st_msk_ansindex1266 = readrel1283->getIndex(ord1282, false);
      std::vector<u16> ord1284({2, 5, 4, 0, 1, 3, 6, 7, 8});
      slog::Relation* readrel1285 = db->getRelation("$sup9688x142x0x0x0");
      $sup9688x142x0x0x0index1267 = readrel1285->getIndex(ord1284, false);
      std::vector<u16> ord1286({1, 2, 0});
      slog::Relation* readrel1287 = db->getRelation("st_diff");
      st_diffindex1268 = readrel1287->getIndex(ord1286, false);
      std::vector<u16> ord1288({1, 2, 3, 4, 0});
      slog::Relation* readrel1289 = db->getRelation("pbranch");
      pbranchindex1269 = readrel1289->getIndex(ord1288, false);
      std::vector<u16> ord1290({1, 2, 3, 4, 0});
      slog::Relation* readrel1291 = db->getRelation("pbranch");
      pbranchdelta1272 = readrel1291->getIndex(ord1290, true);
      std::vector<u16> ord1292({1, 2, 0});
      slog::Relation* readrel1293 = db->getRelation("st_diff");
      st_diffindex1270 = readrel1293->getIndex(ord1292, false);
      std::vector<u16> ord1294({1, 2, 0});
      slog::Relation* readrel1295 = db->getRelation("st_diff");
      st_diffdelta1273 = readrel1295->getIndex(ord1294, true);
      std::vector<u16> ord1296({0, 1});
      slog::Relation* readrel1297 = db->getRelation("st_diff_ans");
      st_diff_ansindex1271 = readrel1297->getIndex(ord1296, false);
      sid1275 = db->getRelation("_enum")->getStructId();
      sid1274 = db->getRelation("pbranch")->getStructId();
      sid1276 = db->getRelation("pleaf")->getStructId();
  
    }
    ReadTask1277(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c212 = v_const81906d9241165d9f6a541e47;
      u64 v_c213 = v_const26c89ee8ccc4ea998fd1a912;
      u64 v_c214 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c215 = _t[0];
        u64 v_c16 = _t[1];
        u64 v_c7 = _t[2];
        if (!slog::exists_probe<9,2>($sup9688x142x0x0x0index1264, std::array<u64,9>{v_c7, v_c16, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex1265, std::array<u64,5>{v_c16, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(st_msk_ansindex1266, std::array<u64,2>{v_c215, 0}, [&](const std::array<u64,2>& m1298) {
          u64 v_c2 = m1298[1];
          slog::join_probe<9,3>($sup9688x142x0x0x0index1267, std::array<u64,9>{v_c7, v_c16, v_c2, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m1299) {
            u64 v_c61 = m1299[3]; u64 v_c6 = m1299[4]; u64 v_c15 = m1299[5]; u64 v_c8 = m1299[6]; u64 v_c17 = m1299[7]; u64 v_c18 = m1299[8];
            if (!slog::exists_probe<3,1>(st_diffindex1268, std::array<u64,3>{v_c8, 0, 0})) return;
            slog::join_probe_old<5,4>(pbranchindex1269, pbranchdelta1272, std::array<u64,5>{v_c16, v_c15, v_c17, v_c18, 0}, [&](const std::array<u64,5>& m1300) {
              u64 v_c216 = m1300[4];
              slog::join_probe_old<3,2>(st_diffindex1270, st_diffdelta1273, std::array<u64,3>{v_c8, v_c216, 0}, [&](const std::array<u64,3>& m1301) {
                u64 v_c217 = m1301[2];
                slog::join_probe<2,1>(st_diff_ansindex1271, std::array<u64,2>{v_c217, 0}, [&](const std::array<u64,2>& m1302) {
                  u64 v_c10 = m1302[1];
                  ++_fires;
                  if (!((is_struct(v_c6) && (decode_struct_id(v_c6) == sid1274 || decode_struct_id(v_c6) == sid1275 || decode_struct_id(v_c6) == sid1276))))
                  {
                    slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c212, v_c213, v_c214, v_c6}, std::array<u16,5>{1, 2, 3, 4, 0});
                    return;
                  }
                  slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c2, v_c7, v_c6, v_c10}, std::array<u16,5>{1, 2, 3, 4, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("set.slog:143", "delta:st_msk", _fires);
  
      if (!_done)
      {
        ReadTask1277* _cont = new ReadTask1277(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1277(db,b), false);
  // (crule (pre (let __tconst3qtG324 const6b86b273ff34fce19d6b804e)) (scan st_mem0 __t14DN326 l k) (body (exists $sup9688x70x0x0x0 (1 2 0 3 4 5) 2 k l) (exists pbranch (3 0 1 2 4) 1 l) (exists st_mem0 (2 0 1) 1 k) (exists st_msk (1 2 0) 1 k) (join st_mem0_ans (0 1) 1 __t14DN326 a) (join $sup9688x70x0x0x0 (1 2 0 3 4 5) 2 k l __t6uqp323 m p r) (exists st_mem0 (2 0 1) 2 k __t6uqp323) (exists st_msk (1 2 0) 2 k m) (exists st_msk_ans (1 0) 1 p) (join pbranch (1 2 3 4 0) 4 p m l r __t7Uqa322) (join st_mem0 (0 1 2) 3 __t6uqp323 __t7Uqa322 k) (join-old st_msk (1 2 0) 2 (1 2 0) k m __t3nJI327) (join st_msk_ans (0 1) 2 __t3nJI327 p) (let __t1YAQ325 (band k m)) (cmp lt __t1YAQ325 __tconst3qtG324)) (head (emit st_mem0_ans (0 1) __t6uqp323 a)) set.slog:71 #f)
  class ReadTask1317 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x70x0x0x0index1303;  slog::Index** pbranchindex1304;  slog::Index** st_mem0index1305;  slog::Index** st_mskindex1306;  slog::Index** st_mem0_ansindex1307;  slog::Index** $sup9688x70x0x0x0index1308;  slog::Index** st_mem0index1309;  slog::Index** st_mskindex1310;  slog::Index** st_msk_ansindex1311;  slog::Index** pbranchindex1312;  slog::Index** st_mem0index1313;  slog::Index** st_mskindex1314;  slog::Index** st_msk_ansindex1315;  slog::Index** st_mskdelta1316;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_mem0_ans");
      std::vector<u16> ord1318({0, 1});
      slog::Relation* readrel1319 = db->getRelation("st_mem0_ans");
      head_index[0] = readrel1319->getIndex(ord1318, false);
      outer_rel = db->getRelation("st_mem0");
      std::vector<u16> ord1320({1, 2, 0, 3, 4, 5});
      slog::Relation* readrel1321 = db->getRelation("$sup9688x70x0x0x0");
      $sup9688x70x0x0x0index1303 = readrel1321->getIndex(ord1320, false);
      std::vector<u16> ord1322({3, 0, 1, 2, 4});
      slog::Relation* readrel1323 = db->getRelation("pbranch");
      pbranchindex1304 = readrel1323->getIndex(ord1322, false);
      std::vector<u16> ord1324({2, 0, 1});
      slog::Relation* readrel1325 = db->getRelation("st_mem0");
      st_mem0index1305 = readrel1325->getIndex(ord1324, false);
      std::vector<u16> ord1326({1, 2, 0});
      slog::Relation* readrel1327 = db->getRelation("st_msk");
      st_mskindex1306 = readrel1327->getIndex(ord1326, false);
      std::vector<u16> ord1328({0, 1});
      slog::Relation* readrel1329 = db->getRelation("st_mem0_ans");
      st_mem0_ansindex1307 = readrel1329->getIndex(ord1328, false);
      std::vector<u16> ord1330({1, 2, 0, 3, 4, 5});
      slog::Relation* readrel1331 = db->getRelation("$sup9688x70x0x0x0");
      $sup9688x70x0x0x0index1308 = readrel1331->getIndex(ord1330, false);
      std::vector<u16> ord1332({2, 0, 1});
      slog::Relation* readrel1333 = db->getRelation("st_mem0");
      st_mem0index1309 = readrel1333->getIndex(ord1332, false);
      std::vector<u16> ord1334({1, 2, 0});
      slog::Relation* readrel1335 = db->getRelation("st_msk");
      st_mskindex1310 = readrel1335->getIndex(ord1334, false);
      std::vector<u16> ord1336({1, 0});
      slog::Relation* readrel1337 = db->getRelation("st_msk_ans");
      st_msk_ansindex1311 = readrel1337->getIndex(ord1336, false);
      std::vector<u16> ord1338({1, 2, 3, 4, 0});
      slog::Relation* readrel1339 = db->getRelation("pbranch");
      pbranchindex1312 = readrel1339->getIndex(ord1338, false);
      std::vector<u16> ord1340({0, 1, 2});
      slog::Relation* readrel1341 = db->getRelation("st_mem0");
      st_mem0index1313 = readrel1341->getIndex(ord1340, false);
      std::vector<u16> ord1342({1, 2, 0});
      slog::Relation* readrel1343 = db->getRelation("st_msk");
      st_mskindex1314 = readrel1343->getIndex(ord1342, false);
      std::vector<u16> ord1344({1, 2, 0});
      slog::Relation* readrel1345 = db->getRelation("st_msk");
      st_mskdelta1316 = readrel1345->getIndex(ord1344, true);
      std::vector<u16> ord1346({0, 1});
      slog::Relation* readrel1347 = db->getRelation("st_msk_ans");
      st_msk_ansindex1315 = readrel1347->getIndex(ord1346, false);
  
    }
    ReadTask1317(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c218 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c219 = _t[0];
        u64 v_c6 = _t[1];
        u64 v_c1 = _t[2];
        if (!slog::exists_probe<6,2>($sup9688x70x0x0x0index1303, std::array<u64,6>{v_c1, v_c6, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex1304, std::array<u64,5>{v_c6, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mem0index1305, std::array<u64,3>{v_c1, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mskindex1306, std::array<u64,3>{v_c1, 0, 0})) return;
        slog::join_probe<2,1>(st_mem0_ansindex1307, std::array<u64,2>{v_c219, 0}, [&](const std::array<u64,2>& m1348) {
          u64 v_c64 = m1348[1];
          slog::join_probe<6,2>($sup9688x70x0x0x0index1308, std::array<u64,6>{v_c1, v_c6, 0, 0, 0, 0}, [&](const std::array<u64,6>& m1349) {
            u64 v_c220 = m1349[2]; u64 v_c7 = m1349[3]; u64 v_c2 = m1349[4]; u64 v_c8 = m1349[5];
            if (!slog::exists_probe<3,2>(st_mem0index1309, std::array<u64,3>{v_c1, v_c220, 0})) return;
            if (!slog::exists_probe<3,2>(st_mskindex1310, std::array<u64,3>{v_c1, v_c7, 0})) return;
            if (!slog::exists_probe<2,1>(st_msk_ansindex1311, std::array<u64,2>{v_c2, 0})) return;
            slog::join_probe<5,4>(pbranchindex1312, std::array<u64,5>{v_c2, v_c7, v_c6, v_c8, 0}, [&](const std::array<u64,5>& m1350) {
              u64 v_c221 = m1350[4];
              slog::join_probe<3,3>(st_mem0index1313, std::array<u64,3>{v_c220, v_c221, v_c1}, [&](const std::array<u64,3>& m1351) {
                slog::join_probe_old<3,2>(st_mskindex1314, st_mskdelta1316, std::array<u64,3>{v_c1, v_c7, 0}, [&](const std::array<u64,3>& m1352) {
                  u64 v_c222 = m1352[2];
                  slog::join_probe<2,2>(st_msk_ansindex1315, std::array<u64,2>{v_c222, v_c2}, [&](const std::array<u64,2>& m1353) {
                    u64 v_c223 = _prim_band(db, v_c1, v_c7);
                    if (v_c223 == slog_error) { slog::emit_pending_error(db, "set.slog:71"); return; }
                    u64 v_c224 = _prim_lt(db, v_c223, v_c218);
                    if (v_c224 == slog_error) { slog::emit_pending_error(db, "set.slog:71"); return; }
                    if (!v_c224) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c220, v_c64}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:71", "delta:st_mem0", _fires);
  
      if (!_done)
      {
        ReadTask1317* _cont = new ReadTask1317(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1317(db,b), false);
  // (crule (pre (let __trid6cNB1008 const8719959a9b35fbf66b391c9f) (let __trel4wz31009 consta10f76b4ec574de5d7b6908e) (let __tcol5CoB1010 const5feceb66ffc86f38d952786c) (let __trel6H8T1011 consta10f76b4ec574de5d7b6908e) (let __tcol7lqS1012 const6b86b273ff34fce19d6b804e)) (scan $sup9688x87x0x0x0 __d0 k l m p r) (body) (head (tycheck k (accept int) __trid6cNB1008 __trel4wz31009 __tcol5CoB1010 (1 2 3 4 0)) (tycheck m (accept int) __trid6cNB1008 __trel6H8T1011 __tcol7lqS1012 (1 2 3 4 0)) (mkstruct st_msk (1 2 0) __27tF1007 k m)) set.slog:88 #f)
  class ReadTask1355 : public slog::Task
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
      outer_rel = db->getRelation("$sup9688x87x0x0x0");
  
    }
    ReadTask1355(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c225 = v_const8719959a9b35fbf66b391c9f;
      u64 v_c226 = v_consta10f76b4ec574de5d7b6908e;
      u64 v_c227 = v_const5feceb66ffc86f38d952786c;
      u64 v_c228 = v_consta10f76b4ec574de5d7b6908e;
      u64 v_c229 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c61 = _t[0];
        u64 v_c1 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c7 = _t[3];
        u64 v_c2 = _t[4];
        u64 v_c8 = _t[5];
        ++_fires;
        if (!(is_int(v_c1)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c225, v_c226, v_c227, v_c1}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c7)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c225, v_c228, v_c229, v_c7}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c1, v_c7}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("set.slog:88", "delta:$sup9688x87x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1355* _cont = new ReadTask1355(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1355(db,b), false);
  // (crule (pre) (scan temp1gVy1270 __t4kHg92 __t5SLx91) (body) (head (emit st_hsb_ans (0 1) __t4kHg92 __t5SLx91)) set.slog:29 #f)
  class ReadTask1356 : public slog::Task
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
      head_rel[0] = db->getRelation("st_hsb_ans");
      std::vector<u16> ord1357({0, 1});
      slog::Relation* readrel1358 = db->getRelation("st_hsb_ans");
      head_index[0] = readrel1358->getIndex(ord1357, false);
      outer_rel = db->getRelation("temp1gVy1270");
  
    }
    ReadTask1356(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c230 = _t[0];
        u64 v_c231 = _t[1];
        ++_fires;
        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c230, v_c231}, std::array<u16,2>{0, 1});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:29", "delta:temp1gVy1270", _fires);
  
      if (!_done)
      {
        ReadTask1356* _cont = new ReadTask1356(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1356(db,b), false);
  // (crule (pre (let __tconst5ja6317 const6b86b273ff34fce19d6b804e)) (scan st_ins_ans __t1WXl320 __v0) (body (join-old st_ins (0 2 1) 1 (0 2 1) __t1WXl320 k l) (exists $sup9688x50x0x0x1 (2 3 0 1 4 5 6) 2 k l) (exists pbranch (3 0 1 2 4) 1 l) (exists st_ins (2 0 1) 1 k) (exists st_msk (1 2 0) 1 k) (join-old $sup9688x50x0x0x0 (1 2 0 3 4 5) 2 (1 2 0 3 4 5) k l __t6bST316 m p r) (exists pbranch (1 2 3 4 0) 4 p m l r) (exists st_ins (0 2 1) 2 __t6bST316 k) (exists st_msk (1 2 0) 2 k m) (exists st_msk_ans (1 0) 1 p) (join-old $sup9688x50x0x0x1 (3 4 5 6 0 2 1) 6 (3 4 5 6 0 2 1) l m p r __t6bST316 k __t5Q4t319) (exists st_msk (1 2 0) 3 k m __t5Q4t319) (exists st_msk_ans (0 1) 2 __t5Q4t319 p) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t8dDI315) (join-old st_ins (0 2 1) 3 (0 2 1) __t6bST316 k __t8dDI315) (join-old st_msk (1 2 0) 3 (1 2 0) k m __t5Q4t319) (join st_msk_ans (0 1) 2 __t5Q4t319 p) (let __t06Cj318 (band k m)) (cmp lt __t06Cj318 __tconst5ja6317)) (head (emit-temp temp8kS01399 __t6bST316 __v0 m p r) (mkstruct pbranch (1 2 3 4 0) __t4IGt314 p m __v0 r)) set.slog:51 #f)
  class ReadTask1382 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_insindex1359;  slog::Index** $sup9688x50x0x0x1index1360;  slog::Index** pbranchindex1361;  slog::Index** st_insindex1362;  slog::Index** st_mskindex1363;  slog::Index** $sup9688x50x0x0x0index1364;  slog::Index** pbranchindex1365;  slog::Index** st_insindex1366;  slog::Index** st_mskindex1367;  slog::Index** st_msk_ansindex1368;  slog::Index** $sup9688x50x0x0x1index1369;  slog::Index** st_mskindex1370;  slog::Index** st_msk_ansindex1371;  slog::Index** pbranchindex1372;  slog::Index** st_insindex1373;  slog::Index** st_mskindex1374;  slog::Index** st_msk_ansindex1375;  slog::Index** st_insdelta1376;  slog::Index** $sup9688x50x0x0x0delta1377;  slog::Index** $sup9688x50x0x0x1delta1378;  slog::Index** pbranchdelta1379;  slog::Index** st_insdelta1380;  slog::Index** st_mskdelta1381;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp8kS01399");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("st_ins_ans");
      std::vector<u16> ord1383({0, 2, 1});
      slog::Relation* readrel1384 = db->getRelation("st_ins");
      st_insindex1359 = readrel1384->getIndex(ord1383, false);
      std::vector<u16> ord1385({0, 2, 1});
      slog::Relation* readrel1386 = db->getRelation("st_ins");
      st_insdelta1376 = readrel1386->getIndex(ord1385, true);
      std::vector<u16> ord1387({2, 3, 0, 1, 4, 5, 6});
      slog::Relation* readrel1388 = db->getRelation("$sup9688x50x0x0x1");
      $sup9688x50x0x0x1index1360 = readrel1388->getIndex(ord1387, false);
      std::vector<u16> ord1389({3, 0, 1, 2, 4});
      slog::Relation* readrel1390 = db->getRelation("pbranch");
      pbranchindex1361 = readrel1390->getIndex(ord1389, false);
      std::vector<u16> ord1391({2, 0, 1});
      slog::Relation* readrel1392 = db->getRelation("st_ins");
      st_insindex1362 = readrel1392->getIndex(ord1391, false);
      std::vector<u16> ord1393({1, 2, 0});
      slog::Relation* readrel1394 = db->getRelation("st_msk");
      st_mskindex1363 = readrel1394->getIndex(ord1393, false);
      std::vector<u16> ord1395({1, 2, 0, 3, 4, 5});
      slog::Relation* readrel1396 = db->getRelation("$sup9688x50x0x0x0");
      $sup9688x50x0x0x0index1364 = readrel1396->getIndex(ord1395, false);
      std::vector<u16> ord1397({1, 2, 0, 3, 4, 5});
      slog::Relation* readrel1398 = db->getRelation("$sup9688x50x0x0x0");
      $sup9688x50x0x0x0delta1377 = readrel1398->getIndex(ord1397, true);
      std::vector<u16> ord1399({1, 2, 3, 4, 0});
      slog::Relation* readrel1400 = db->getRelation("pbranch");
      pbranchindex1365 = readrel1400->getIndex(ord1399, false);
      std::vector<u16> ord1401({0, 2, 1});
      slog::Relation* readrel1402 = db->getRelation("st_ins");
      st_insindex1366 = readrel1402->getIndex(ord1401, false);
      std::vector<u16> ord1403({1, 2, 0});
      slog::Relation* readrel1404 = db->getRelation("st_msk");
      st_mskindex1367 = readrel1404->getIndex(ord1403, false);
      std::vector<u16> ord1405({1, 0});
      slog::Relation* readrel1406 = db->getRelation("st_msk_ans");
      st_msk_ansindex1368 = readrel1406->getIndex(ord1405, false);
      std::vector<u16> ord1407({3, 4, 5, 6, 0, 2, 1});
      slog::Relation* readrel1408 = db->getRelation("$sup9688x50x0x0x1");
      $sup9688x50x0x0x1index1369 = readrel1408->getIndex(ord1407, false);
      std::vector<u16> ord1409({3, 4, 5, 6, 0, 2, 1});
      slog::Relation* readrel1410 = db->getRelation("$sup9688x50x0x0x1");
      $sup9688x50x0x0x1delta1378 = readrel1410->getIndex(ord1409, true);
      std::vector<u16> ord1411({1, 2, 0});
      slog::Relation* readrel1412 = db->getRelation("st_msk");
      st_mskindex1370 = readrel1412->getIndex(ord1411, false);
      std::vector<u16> ord1413({0, 1});
      slog::Relation* readrel1414 = db->getRelation("st_msk_ans");
      st_msk_ansindex1371 = readrel1414->getIndex(ord1413, false);
      std::vector<u16> ord1415({1, 2, 3, 4, 0});
      slog::Relation* readrel1416 = db->getRelation("pbranch");
      pbranchindex1372 = readrel1416->getIndex(ord1415, false);
      std::vector<u16> ord1417({1, 2, 3, 4, 0});
      slog::Relation* readrel1418 = db->getRelation("pbranch");
      pbranchdelta1379 = readrel1418->getIndex(ord1417, true);
      std::vector<u16> ord1419({0, 2, 1});
      slog::Relation* readrel1420 = db->getRelation("st_ins");
      st_insindex1373 = readrel1420->getIndex(ord1419, false);
      std::vector<u16> ord1421({0, 2, 1});
      slog::Relation* readrel1422 = db->getRelation("st_ins");
      st_insdelta1380 = readrel1422->getIndex(ord1421, true);
      std::vector<u16> ord1423({1, 2, 0});
      slog::Relation* readrel1424 = db->getRelation("st_msk");
      st_mskindex1374 = readrel1424->getIndex(ord1423, false);
      std::vector<u16> ord1425({1, 2, 0});
      slog::Relation* readrel1426 = db->getRelation("st_msk");
      st_mskdelta1381 = readrel1426->getIndex(ord1425, true);
      std::vector<u16> ord1427({0, 1});
      slog::Relation* readrel1428 = db->getRelation("st_msk_ans");
      st_msk_ansindex1375 = readrel1428->getIndex(ord1427, false);
  
    }
    ReadTask1382(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c232 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c233 = _t[0];
        u64 v_c10 = _t[1];
        slog::join_probe_old<3,1>(st_insindex1359, st_insdelta1376, std::array<u64,3>{v_c233, 0, 0}, [&](const std::array<u64,3>& m1429) {
          u64 v_c1 = m1429[1]; u64 v_c6 = m1429[2];
          if (!slog::exists_probe<7,2>($sup9688x50x0x0x1index1360, std::array<u64,7>{v_c1, v_c6, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>(pbranchindex1361, std::array<u64,5>{v_c6, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(st_insindex1362, std::array<u64,3>{v_c1, 0, 0})) return;
          if (!slog::exists_probe<3,1>(st_mskindex1363, std::array<u64,3>{v_c1, 0, 0})) return;
          slog::join_probe_old<6,2>($sup9688x50x0x0x0index1364, $sup9688x50x0x0x0delta1377, std::array<u64,6>{v_c1, v_c6, 0, 0, 0, 0}, [&](const std::array<u64,6>& m1430) {
            u64 v_c234 = m1430[2]; u64 v_c7 = m1430[3]; u64 v_c2 = m1430[4]; u64 v_c8 = m1430[5];
            if (!slog::exists_probe<5,4>(pbranchindex1365, std::array<u64,5>{v_c2, v_c7, v_c6, v_c8, 0})) return;
            if (!slog::exists_probe<3,2>(st_insindex1366, std::array<u64,3>{v_c234, v_c1, 0})) return;
            if (!slog::exists_probe<3,2>(st_mskindex1367, std::array<u64,3>{v_c1, v_c7, 0})) return;
            if (!slog::exists_probe<2,1>(st_msk_ansindex1368, std::array<u64,2>{v_c2, 0})) return;
            slog::join_probe_old<7,6>($sup9688x50x0x0x1index1369, $sup9688x50x0x0x1delta1378, std::array<u64,7>{v_c6, v_c7, v_c2, v_c8, v_c234, v_c1, 0}, [&](const std::array<u64,7>& m1431) {
              u64 v_c235 = m1431[6];
              if (!slog::exists_probe<3,3>(st_mskindex1370, std::array<u64,3>{v_c1, v_c7, v_c235})) return;
              if (!slog::exists_probe<2,2>(st_msk_ansindex1371, std::array<u64,2>{v_c235, v_c2})) return;
              slog::join_probe_old<5,4>(pbranchindex1372, pbranchdelta1379, std::array<u64,5>{v_c2, v_c7, v_c6, v_c8, 0}, [&](const std::array<u64,5>& m1432) {
                u64 v_c236 = m1432[4];
                slog::join_probe_old<3,3>(st_insindex1373, st_insdelta1380, std::array<u64,3>{v_c234, v_c1, v_c236}, [&](const std::array<u64,3>& m1433) {
                  slog::join_probe_old<3,3>(st_mskindex1374, st_mskdelta1381, std::array<u64,3>{v_c1, v_c7, v_c235}, [&](const std::array<u64,3>& m1434) {
                    slog::join_probe<2,2>(st_msk_ansindex1375, std::array<u64,2>{v_c235, v_c2}, [&](const std::array<u64,2>& m1435) {
                      u64 v_c237 = _prim_band(db, v_c1, v_c7);
                      if (v_c237 == slog_error) { slog::emit_pending_error(db, "set.slog:51"); return; }
                      u64 v_c238 = _prim_lt(db, v_c237, v_c232);
                      if (v_c238 == slog_error) { slog::emit_pending_error(db, "set.slog:51"); return; }
                      if (!v_c238) return;
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c234, v_c10, v_c7, v_c2, v_c8});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c2, v_c7, v_c10, v_c8}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:51", "delta:st_ins_ans", _fires);
  
      if (!_done)
      {
        ReadTask1382* _cont = new ReadTask1382(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1382(db,b), false);
}

