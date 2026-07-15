
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const1d9eff40314d54862fee3942;
extern u64 v_const22475024b8f1c7d620b83a7c;
extern u64 v_const2c624232cdd221771294dfbb;
extern u64 v_const4b227777d4dd1fc61c6f884f;
extern u64 v_const4e07408562bedb8b60ce05c1;
extern u64 v_const5d058eae1c2c75768f73b199;
extern u64 v_const5e6127cdd5ea2629462053c9;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const66633592860a63ea6408b433;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const9899bd1a9f17c17561973172;
extern u64 v_consta10f76b4ec574de5d7b6908e;
extern u64 v_constcbf5a4e983555adcacc7f2e9;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_constd9f85eba98ed33f6c0ac9bf6;
extern u64 v_conste3776bfed7f405de8017ecfa;
extern u64 v_constef2d127de37b942baad06145;
extern u64 v_constf2664e0abda1016213c9fa90;


void slog_rules_c66c32b0817855ec9(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre (let __tconst9B7m280 const6b86b273ff34fce19d6b804e)) (scan st_del __t62j9284 l k) (body (exists $sup9688x88x0x0x0 (1 2 0 3 4 5) 2 k l) (exists pbranch (3 0 1 2 4) 1 l) (exists st_del (2 0 1) 1 k) (exists st_msk (1 2 0) 1 k) (join st_del_ans (0 1) 1 __t62j9284 __v0) (exists st_bld (3 0 1 2 4) 1 __v0) (join $sup9688x88x0x0x0 (1 2 0 3 4 5) 2 k l __t3OU0279 m p r) (exists st_bld (1 2 3 4 0) 4 p m __v0 r) (exists st_del (0 2 1) 2 __t3OU0279 k) (exists st_msk (1 2 0) 2 k m) (exists st_msk_ans (1 0) 1 p) (join pbranch (1 2 3 4 0) 4 p m l r __t2u9k278) (exists st_del (0 2 1) 3 __t3OU0279 k __t2u9k278) (join st_bld (1 2 3 4 0) 4 p m __v0 r __t6UON282) (join st_del (0 2 1) 3 __t3OU0279 k __t2u9k278) (exists st_bld_ans (0 1) 1 __t6UON282) (join st_msk (1 2 0) 2 k m __t5pdy283) (join st_msk_ans (0 1) 2 __t5pdy283 p) (join st_bld_ans (0 1) 1 __t6UON282 res) (let __t4Xlx281 (band k m)) (cmp lt __t4Xlx281 __tconst9B7m280)) (head (emit st_del_ans (0 1) __t3OU0279 res)) set.slog:89 #f)
  class ReadTask19 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x88x0x0x0index0;  slog::Index** pbranchindex1;  slog::Index** st_delindex2;  slog::Index** st_mskindex3;  slog::Index** st_del_ansindex4;  slog::Index** st_bldindex5;  slog::Index** $sup9688x88x0x0x0index6;  slog::Index** st_bldindex7;  slog::Index** st_delindex8;  slog::Index** st_mskindex9;  slog::Index** st_msk_ansindex10;  slog::Index** pbranchindex11;  slog::Index** st_delindex12;  slog::Index** st_bldindex13;  slog::Index** st_delindex14;  slog::Index** st_bld_ansindex15;  slog::Index** st_mskindex16;  slog::Index** st_msk_ansindex17;  slog::Index** st_bld_ansindex18;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_del_ans");
      std::vector<u16> ord20({0, 1});
      slog::Relation* readrel21 = db->getRelation("st_del_ans");
      head_index[0] = readrel21->getIndex(ord20, false);
      outer_rel = db->getRelation("st_del");
      std::vector<u16> ord22({1, 2, 0, 3, 4, 5});
      slog::Relation* readrel23 = db->getRelation("$sup9688x88x0x0x0");
      $sup9688x88x0x0x0index0 = readrel23->getIndex(ord22, false);
      std::vector<u16> ord24({3, 0, 1, 2, 4});
      slog::Relation* readrel25 = db->getRelation("pbranch");
      pbranchindex1 = readrel25->getIndex(ord24, false);
      std::vector<u16> ord26({2, 0, 1});
      slog::Relation* readrel27 = db->getRelation("st_del");
      st_delindex2 = readrel27->getIndex(ord26, false);
      std::vector<u16> ord28({1, 2, 0});
      slog::Relation* readrel29 = db->getRelation("st_msk");
      st_mskindex3 = readrel29->getIndex(ord28, false);
      std::vector<u16> ord30({0, 1});
      slog::Relation* readrel31 = db->getRelation("st_del_ans");
      st_del_ansindex4 = readrel31->getIndex(ord30, false);
      std::vector<u16> ord32({3, 0, 1, 2, 4});
      slog::Relation* readrel33 = db->getRelation("st_bld");
      st_bldindex5 = readrel33->getIndex(ord32, false);
      std::vector<u16> ord34({1, 2, 0, 3, 4, 5});
      slog::Relation* readrel35 = db->getRelation("$sup9688x88x0x0x0");
      $sup9688x88x0x0x0index6 = readrel35->getIndex(ord34, false);
      std::vector<u16> ord36({1, 2, 3, 4, 0});
      slog::Relation* readrel37 = db->getRelation("st_bld");
      st_bldindex7 = readrel37->getIndex(ord36, false);
      std::vector<u16> ord38({0, 2, 1});
      slog::Relation* readrel39 = db->getRelation("st_del");
      st_delindex8 = readrel39->getIndex(ord38, false);
      std::vector<u16> ord40({1, 2, 0});
      slog::Relation* readrel41 = db->getRelation("st_msk");
      st_mskindex9 = readrel41->getIndex(ord40, false);
      std::vector<u16> ord42({1, 0});
      slog::Relation* readrel43 = db->getRelation("st_msk_ans");
      st_msk_ansindex10 = readrel43->getIndex(ord42, false);
      std::vector<u16> ord44({1, 2, 3, 4, 0});
      slog::Relation* readrel45 = db->getRelation("pbranch");
      pbranchindex11 = readrel45->getIndex(ord44, false);
      std::vector<u16> ord46({0, 2, 1});
      slog::Relation* readrel47 = db->getRelation("st_del");
      st_delindex12 = readrel47->getIndex(ord46, false);
      std::vector<u16> ord48({1, 2, 3, 4, 0});
      slog::Relation* readrel49 = db->getRelation("st_bld");
      st_bldindex13 = readrel49->getIndex(ord48, false);
      std::vector<u16> ord50({0, 2, 1});
      slog::Relation* readrel51 = db->getRelation("st_del");
      st_delindex14 = readrel51->getIndex(ord50, false);
      std::vector<u16> ord52({0, 1});
      slog::Relation* readrel53 = db->getRelation("st_bld_ans");
      st_bld_ansindex15 = readrel53->getIndex(ord52, false);
      std::vector<u16> ord54({1, 2, 0});
      slog::Relation* readrel55 = db->getRelation("st_msk");
      st_mskindex16 = readrel55->getIndex(ord54, false);
      std::vector<u16> ord56({0, 1});
      slog::Relation* readrel57 = db->getRelation("st_msk_ans");
      st_msk_ansindex17 = readrel57->getIndex(ord56, false);
      std::vector<u16> ord58({0, 1});
      slog::Relation* readrel59 = db->getRelation("st_bld_ans");
      st_bld_ansindex18 = readrel59->getIndex(ord58, false);
  
    }
    ReadTask19(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c1 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c3 = _t[2];
        if (!slog::exists_probe<6,2>($sup9688x88x0x0x0index0, std::array<u64,6>{v_c3, v_c2, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex1, std::array<u64,5>{v_c2, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_delindex2, std::array<u64,3>{v_c3, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mskindex3, std::array<u64,3>{v_c3, 0, 0})) return;
        slog::join_probe<2,1>(st_del_ansindex4, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m60) {
          u64 v_c4 = m60[1];
          if (!slog::exists_probe<5,1>(st_bldindex5, std::array<u64,5>{v_c4, 0, 0, 0, 0})) return;
          slog::join_probe<6,2>($sup9688x88x0x0x0index6, std::array<u64,6>{v_c3, v_c2, 0, 0, 0, 0}, [&](const std::array<u64,6>& m61) {
            u64 v_c5 = m61[2]; u64 v_c6 = m61[3]; u64 v_c7 = m61[4]; u64 v_c8 = m61[5];
            if (!slog::exists_probe<5,4>(st_bldindex7, std::array<u64,5>{v_c7, v_c6, v_c4, v_c8, 0})) return;
            if (!slog::exists_probe<3,2>(st_delindex8, std::array<u64,3>{v_c5, v_c3, 0})) return;
            if (!slog::exists_probe<3,2>(st_mskindex9, std::array<u64,3>{v_c3, v_c6, 0})) return;
            if (!slog::exists_probe<2,1>(st_msk_ansindex10, std::array<u64,2>{v_c7, 0})) return;
            slog::join_probe<5,4>(pbranchindex11, std::array<u64,5>{v_c7, v_c6, v_c2, v_c8, 0}, [&](const std::array<u64,5>& m62) {
              u64 v_c9 = m62[4];
              if (!slog::exists_probe<3,3>(st_delindex12, std::array<u64,3>{v_c5, v_c3, v_c9})) return;
              slog::join_probe<5,4>(st_bldindex13, std::array<u64,5>{v_c7, v_c6, v_c4, v_c8, 0}, [&](const std::array<u64,5>& m63) {
                u64 v_c10 = m63[4];
                slog::join_probe<3,3>(st_delindex14, std::array<u64,3>{v_c5, v_c3, v_c9}, [&](const std::array<u64,3>& m64) {
                  if (!slog::exists_probe<2,1>(st_bld_ansindex15, std::array<u64,2>{v_c10, 0})) return;
                  slog::join_probe<3,2>(st_mskindex16, std::array<u64,3>{v_c3, v_c6, 0}, [&](const std::array<u64,3>& m65) {
                    u64 v_c11 = m65[2];
                    slog::join_probe<2,2>(st_msk_ansindex17, std::array<u64,2>{v_c11, v_c7}, [&](const std::array<u64,2>& m66) {
                      slog::join_probe<2,1>(st_bld_ansindex18, std::array<u64,2>{v_c10, 0}, [&](const std::array<u64,2>& m67) {
                        u64 v_c12 = m67[1];
                        u64 v_c13 = _prim_band(db, v_c3, v_c6);
                        if (v_c13 == slog_error) { slog::emit_pending_error(db, "set.slog:89"); return; }
                        u64 v_c14 = _prim_lt(db, v_c13, v_c0);
                        if (v_c14 == slog_error) { slog::emit_pending_error(db, "set.slog:89"); return; }
                        if (!v_c14) return;
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c5, v_c12}, std::array<u16,2>{0, 1});
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
        ReadTask19* _cont = new ReadTask19(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask19(db,b), false);
  // (crule (pre (let __tconst8Ksp764 conste3776bfed7f405de8017ecfa) (let __tconst6tkr379 const6b86b273ff34fce19d6b804e) (let __tconst7Eph382 const2c624232cdd221771294dfbb) (let __tconst4emd384 constd4735e3a265e16eee03f5971) (let __tconst2ksI386 constef2d127de37b942baad06145)) (scan st_ins_ans __t88YX385 __v2) (body (exists st_ins (1 2 0) 2 __v2 __tconst2ksI386) (exists _enum (1 0) 1 __tconst8Ksp764) (exists st_ins (2 0 1) 1 __tconst6tkr379) (exists st_ins (2 0 1) 1 __tconst7Eph382) (join-old st_ins (0 2 1) 2 (0 2 1) __t88YX385 __tconst4emd384 __v1) (exists st_ins_ans (1 0) 1 __v1) (join-old st_ins (1 2 0) 2 (1 2 0) __v2 __tconst2ksI386 __t7LWC387) (exists st_ins_ans (0 1) 1 __t7LWC387) (join _enum (1 0) 1 __tconst8Ksp764 __t6fdj380) (join-old st_ins (1 2 0) 2 (1 2 0) __t6fdj380 __tconst6tkr379 __t2Q6o381) (join st_ins_ans (0 1) 1 __t2Q6o381 __v0) (join-old st_ins (1 2 0) 2 (1 2 0) __v0 __tconst7Eph382 __t0FtX383) (join st_ins_ans (0 1) 2 __t0FtX383 __v1) (join-old st_ins_ans (0 1) 1 (0 1) __t7LWC387 r)) (head (emit canon (0) r)) st_basic.slog:15 #f)
  class ReadTask88 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_insindex69;  slog::Index** _enumindex70;  slog::Index** st_insindex71;  slog::Index** st_insindex72;  slog::Index** st_insindex73;  slog::Index** st_ins_ansindex74;  slog::Index** st_insindex75;  slog::Index** st_ins_ansindex76;  slog::Index** _enumindex77;  slog::Index** st_insindex78;  slog::Index** st_ins_ansindex79;  slog::Index** st_insindex80;  slog::Index** st_ins_ansindex81;  slog::Index** st_ins_ansindex82;  slog::Index** st_insdelta83;  slog::Index** st_insdelta84;  slog::Index** st_insdelta85;  slog::Index** st_insdelta86;  slog::Index** st_ins_ansdelta87;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("canon");
      std::vector<u16> ord89({0});
      slog::Relation* readrel90 = db->getRelation("canon");
      head_index[0] = readrel90->getIndex(ord89, false);
      outer_rel = db->getRelation("st_ins_ans");
      std::vector<u16> ord91({1, 2, 0});
      slog::Relation* readrel92 = db->getRelation("st_ins");
      st_insindex69 = readrel92->getIndex(ord91, false);
      std::vector<u16> ord93({1, 0});
      slog::Relation* readrel94 = db->getRelation("_enum");
      _enumindex70 = readrel94->getIndex(ord93, false);
      std::vector<u16> ord95({2, 0, 1});
      slog::Relation* readrel96 = db->getRelation("st_ins");
      st_insindex71 = readrel96->getIndex(ord95, false);
      std::vector<u16> ord97({2, 0, 1});
      slog::Relation* readrel98 = db->getRelation("st_ins");
      st_insindex72 = readrel98->getIndex(ord97, false);
      std::vector<u16> ord99({0, 2, 1});
      slog::Relation* readrel100 = db->getRelation("st_ins");
      st_insindex73 = readrel100->getIndex(ord99, false);
      std::vector<u16> ord101({0, 2, 1});
      slog::Relation* readrel102 = db->getRelation("st_ins");
      st_insdelta83 = readrel102->getIndex(ord101, true);
      std::vector<u16> ord103({1, 0});
      slog::Relation* readrel104 = db->getRelation("st_ins_ans");
      st_ins_ansindex74 = readrel104->getIndex(ord103, false);
      std::vector<u16> ord105({1, 2, 0});
      slog::Relation* readrel106 = db->getRelation("st_ins");
      st_insindex75 = readrel106->getIndex(ord105, false);
      std::vector<u16> ord107({1, 2, 0});
      slog::Relation* readrel108 = db->getRelation("st_ins");
      st_insdelta84 = readrel108->getIndex(ord107, true);
      std::vector<u16> ord109({0, 1});
      slog::Relation* readrel110 = db->getRelation("st_ins_ans");
      st_ins_ansindex76 = readrel110->getIndex(ord109, false);
      std::vector<u16> ord111({1, 0});
      slog::Relation* readrel112 = db->getRelation("_enum");
      _enumindex77 = readrel112->getIndex(ord111, false);
      std::vector<u16> ord113({1, 2, 0});
      slog::Relation* readrel114 = db->getRelation("st_ins");
      st_insindex78 = readrel114->getIndex(ord113, false);
      std::vector<u16> ord115({1, 2, 0});
      slog::Relation* readrel116 = db->getRelation("st_ins");
      st_insdelta85 = readrel116->getIndex(ord115, true);
      std::vector<u16> ord117({0, 1});
      slog::Relation* readrel118 = db->getRelation("st_ins_ans");
      st_ins_ansindex79 = readrel118->getIndex(ord117, false);
      std::vector<u16> ord119({1, 2, 0});
      slog::Relation* readrel120 = db->getRelation("st_ins");
      st_insindex80 = readrel120->getIndex(ord119, false);
      std::vector<u16> ord121({1, 2, 0});
      slog::Relation* readrel122 = db->getRelation("st_ins");
      st_insdelta86 = readrel122->getIndex(ord121, true);
      std::vector<u16> ord123({0, 1});
      slog::Relation* readrel124 = db->getRelation("st_ins_ans");
      st_ins_ansindex81 = readrel124->getIndex(ord123, false);
      std::vector<u16> ord125({0, 1});
      slog::Relation* readrel126 = db->getRelation("st_ins_ans");
      st_ins_ansindex82 = readrel126->getIndex(ord125, false);
      std::vector<u16> ord127({0, 1});
      slog::Relation* readrel128 = db->getRelation("st_ins_ans");
      st_ins_ansdelta87 = readrel128->getIndex(ord127, true);
  
    }
    ReadTask88(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c15 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c16 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c17 = v_const2c624232cdd221771294dfbb;
      u64 v_c18 = v_constd4735e3a265e16eee03f5971;
      u64 v_c19 = v_constef2d127de37b942baad06145;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c20 = _t[0];
        u64 v_c21 = _t[1];
        if (!slog::exists_probe<3,2>(st_insindex69, std::array<u64,3>{v_c21, v_c19, 0})) return;
        if (!slog::exists_probe<2,1>(_enumindex70, std::array<u64,2>{v_c15, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex71, std::array<u64,3>{v_c16, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex72, std::array<u64,3>{v_c17, 0, 0})) return;
        slog::join_probe_old<3,2>(st_insindex73, st_insdelta83, std::array<u64,3>{v_c20, v_c18, 0}, [&](const std::array<u64,3>& m129) {
          u64 v_c22 = m129[2];
          if (!slog::exists_probe<2,1>(st_ins_ansindex74, std::array<u64,2>{v_c22, 0})) return;
          slog::join_probe_old<3,2>(st_insindex75, st_insdelta84, std::array<u64,3>{v_c21, v_c19, 0}, [&](const std::array<u64,3>& m130) {
            u64 v_c23 = m130[2];
            if (!slog::exists_probe<2,1>(st_ins_ansindex76, std::array<u64,2>{v_c23, 0})) return;
            slog::join_probe<2,1>(_enumindex77, std::array<u64,2>{v_c15, 0}, [&](const std::array<u64,2>& m131) {
              u64 v_c24 = m131[1];
              slog::join_probe_old<3,2>(st_insindex78, st_insdelta85, std::array<u64,3>{v_c24, v_c16, 0}, [&](const std::array<u64,3>& m132) {
                u64 v_c25 = m132[2];
                slog::join_probe<2,1>(st_ins_ansindex79, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m133) {
                  u64 v_c4 = m133[1];
                  slog::join_probe_old<3,2>(st_insindex80, st_insdelta86, std::array<u64,3>{v_c4, v_c17, 0}, [&](const std::array<u64,3>& m134) {
                    u64 v_c26 = m134[2];
                    slog::join_probe<2,2>(st_ins_ansindex81, std::array<u64,2>{v_c26, v_c22}, [&](const std::array<u64,2>& m135) {
                      slog::join_probe_old<2,1>(st_ins_ansindex82, st_ins_ansdelta87, std::array<u64,2>{v_c23, 0}, [&](const std::array<u64,2>& m136) {
                        u64 v_c8 = m136[1];
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
  // (crule (pre) (scan temp3V0b1338 __t638T579) (body) (head (mkstruct st_hsb (1 0) __8RUL685 __t638T579)) set.slog:41 #f)
  class ReadTask137 : public slog::Task
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
      outer_rel = db->getRelation("temp3V0b1338");
  
    }
    ReadTask137(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c27 = _t[0];
        ++_fires;
        slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c27}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:41", "delta:temp3V0b1338", _fires);
  
      if (!_done)
      {
        ReadTask137* _cont = new ReadTask137(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask137(db,b), false);
  // (crule (pre) (scan st_union __t2rFM184 __t7Mu9183 t) (body (exists st_ins (1 2 0) 1 t) (join pleaf (0 1) 1 __t7Mu9183 k) (join-old st_ins (1 2 0) 2 (1 2 0) t k __t5aIA185) (join st_ins_ans (0 1) 1 __t5aIA185 r)) (head (emit st_union_ans (0 1) __t2rFM184 r)) set.slog:98 #f)
  class ReadTask143 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_insindex138;  slog::Index** pleafindex139;  slog::Index** st_insindex140;  slog::Index** st_ins_ansindex141;  slog::Index** st_insdelta142;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_union_ans");
      std::vector<u16> ord144({0, 1});
      slog::Relation* readrel145 = db->getRelation("st_union_ans");
      head_index[0] = readrel145->getIndex(ord144, false);
      outer_rel = db->getRelation("st_union");
      std::vector<u16> ord146({1, 2, 0});
      slog::Relation* readrel147 = db->getRelation("st_ins");
      st_insindex138 = readrel147->getIndex(ord146, false);
      std::vector<u16> ord148({0, 1});
      slog::Relation* readrel149 = db->getRelation("pleaf");
      pleafindex139 = readrel149->getIndex(ord148, false);
      std::vector<u16> ord150({1, 2, 0});
      slog::Relation* readrel151 = db->getRelation("st_ins");
      st_insindex140 = readrel151->getIndex(ord150, false);
      std::vector<u16> ord152({1, 2, 0});
      slog::Relation* readrel153 = db->getRelation("st_ins");
      st_insdelta142 = readrel153->getIndex(ord152, true);
      std::vector<u16> ord154({0, 1});
      slog::Relation* readrel155 = db->getRelation("st_ins_ans");
      st_ins_ansindex141 = readrel155->getIndex(ord154, false);
  
    }
    ReadTask143(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        if (!slog::exists_probe<3,1>(st_insindex138, std::array<u64,3>{v_c30, 0, 0})) return;
        slog::join_probe<2,1>(pleafindex139, std::array<u64,2>{v_c29, 0}, [&](const std::array<u64,2>& m156) {
          u64 v_c3 = m156[1];
          slog::join_probe_old<3,2>(st_insindex140, st_insdelta142, std::array<u64,3>{v_c30, v_c3, 0}, [&](const std::array<u64,3>& m157) {
            u64 v_c31 = m157[2];
            slog::join_probe<2,1>(st_ins_ansindex141, std::array<u64,2>{v_c31, 0}, [&](const std::array<u64,2>& m158) {
              u64 v_c8 = m158[1];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c28, v_c8}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:98", "delta:st_union", _fires);
  
      if (!_done)
      {
        ReadTask143* _cont = new ReadTask143(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask143(db,b), false);
  // (crule (pre (let __tconst0UIr907 conste3776bfed7f405de8017ecfa) (let __tconst67v2432 constef2d127de37b942baad06145) (let __tconst3Prp435 constd4735e3a265e16eee03f5971) (let __tconst4LVH431 const6b86b273ff34fce19d6b804e)) (probe st_ins (2 0 1) 1 __tconst67v2432 __t2Qai434 __t5QG4436) (body (join _enum (0 1) 2 __t5QG4436 __tconst0UIr907) (exists st_ins_ans (0 1) 1 __t2Qai434) (join-old st_ins (1 2 0) 2 (1 2 0) __t5QG4436 __tconst3Prp435 __t1RFt437) (exists st_ins_ans (0 1) 1 __t1RFt437) (join st_ins_ans (0 1) 1 __t2Qai434 __v0) (join st_ins_ans (0 1) 1 __t1RFt437 __v1)) (head (mkstruct st_ins (1 2 0) __12BV908 __v1 __tconst4LVH431)) st_basic.slog:18 #f)
  class ReadTask166 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** _enumindex159;  slog::Index** st_ins_ansindex160;  slog::Index** st_insindex161;  slog::Index** st_ins_ansindex162;  slog::Index** st_ins_ansindex163;  slog::Index** st_ins_ansindex164;  slog::Index** st_insdelta165;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_ins");
      std::vector<u16> ord167({2, 0, 1});
      slog::Relation* readrel168 = db->getRelation("st_ins");
      driver_index = readrel168->getIndex(ord167, true);
      std::vector<u16> ord169({0, 1});
      slog::Relation* readrel170 = db->getRelation("_enum");
      _enumindex159 = readrel170->getIndex(ord169, false);
      std::vector<u16> ord171({0, 1});
      slog::Relation* readrel172 = db->getRelation("st_ins_ans");
      st_ins_ansindex160 = readrel172->getIndex(ord171, false);
      std::vector<u16> ord173({1, 2, 0});
      slog::Relation* readrel174 = db->getRelation("st_ins");
      st_insindex161 = readrel174->getIndex(ord173, false);
      std::vector<u16> ord175({1, 2, 0});
      slog::Relation* readrel176 = db->getRelation("st_ins");
      st_insdelta165 = readrel176->getIndex(ord175, true);
      std::vector<u16> ord177({0, 1});
      slog::Relation* readrel178 = db->getRelation("st_ins_ans");
      st_ins_ansindex162 = readrel178->getIndex(ord177, false);
      std::vector<u16> ord179({0, 1});
      slog::Relation* readrel180 = db->getRelation("st_ins_ans");
      st_ins_ansindex163 = readrel180->getIndex(ord179, false);
      std::vector<u16> ord181({0, 1});
      slog::Relation* readrel182 = db->getRelation("st_ins_ans");
      st_ins_ansindex164 = readrel182->getIndex(ord181, false);
  
    }
    ReadTask166(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c32 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c33 = v_constef2d127de37b942baad06145;
      u64 v_c34 = v_constd4735e3a265e16eee03f5971;
      u64 v_c35 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c33, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m183) {
        u64 v_c36 = m183[1];
        u64 v_c37 = m183[2];
        if (buckethash(v_c36) != bucket) return;
        slog::join_probe<2,2>(_enumindex159, std::array<u64,2>{v_c37, v_c32}, [&](const std::array<u64,2>& m184) {
          if (!slog::exists_probe<2,1>(st_ins_ansindex160, std::array<u64,2>{v_c36, 0})) return;
          slog::join_probe_old<3,2>(st_insindex161, st_insdelta165, std::array<u64,3>{v_c37, v_c34, 0}, [&](const std::array<u64,3>& m185) {
            u64 v_c38 = m185[2];
            if (!slog::exists_probe<2,1>(st_ins_ansindex162, std::array<u64,2>{v_c38, 0})) return;
            slog::join_probe<2,1>(st_ins_ansindex163, std::array<u64,2>{v_c36, 0}, [&](const std::array<u64,2>& m186) {
              u64 v_c4 = m186[1];
              slog::join_probe<2,1>(st_ins_ansindex164, std::array<u64,2>{v_c38, 0}, [&](const std::array<u64,2>& m187) {
                u64 v_c22 = m187[1];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c22, v_c35}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("st_basic.slog:18", "delta:st_ins", _fires);
  
      if (!_done)
      {
        ReadTask166* _cont = new ReadTask166(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask166(db,b), false);
  // (crule (pre (let __trid7g40866 const22475024b8f1c7d620b83a7c) (let __trel4hWy867 consta10f76b4ec574de5d7b6908e) (let __tcol6Cjg868 const5feceb66ffc86f38d952786c) (let __trel05Yn869 consta10f76b4ec574de5d7b6908e) (let __tcol2FBj870 const6b86b273ff34fce19d6b804e)) (scan $sup9688x106x0x0x0 __d0 l m n p q r u v) (body) (head (tycheck q (accept int) __trid7g40866 __trel4hWy867 __tcol6Cjg868 (1 2 3 4 0)) (tycheck m (accept int) __trid7g40866 __trel05Yn869 __tcol2FBj870 (1 2 3 4 0)) (mkstruct st_msk (1 2 0) __8mif865 q m)) set.slog:107 #f)
  class ReadTask188 : public slog::Task
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
      outer_rel = db->getRelation("$sup9688x106x0x0x0");
  
    }
    ReadTask188(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c39 = v_const22475024b8f1c7d620b83a7c;
      u64 v_c40 = v_consta10f76b4ec574de5d7b6908e;
      u64 v_c41 = v_const5feceb66ffc86f38d952786c;
      u64 v_c42 = v_consta10f76b4ec574de5d7b6908e;
      u64 v_c43 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c44 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c45 = _t[3];
        u64 v_c7 = _t[4];
        u64 v_c46 = _t[5];
        u64 v_c8 = _t[6];
        u64 v_c47 = _t[7];
        u64 v_c48 = _t[8];
        ++_fires;
        if (!(is_int(v_c46)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c39, v_c40, v_c41, v_c46}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c6)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c39, v_c42, v_c43, v_c6}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c46, v_c6}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("set.slog:107", "delta:$sup9688x106x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask188* _cont = new ReadTask188(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask188(db,b), false);
  // (crule (pre (let _00024sqc6FSA620 const4b227777d4dd1fc61c6f884f) (let _00024sqc3Ub8621 const5feceb66ffc86f38d952786c) (let _00024sqc1TCF622 const6b86b273ff34fce19d6b804e) (let _00024sqc3FMQ623 const6b86b273ff34fce19d6b804e) (let _00024sqc41K7624 const2c624232cdd221771294dfbb) (let _00024sqc6uPA625 constd4735e3a265e16eee03f5971) (let _00024sqc9VIm626 constd4735e3a265e16eee03f5971) (let _00024sqc7Q1B627 const4e07408562bedb8b60ce05c1) (let _00024sqc4nIn628 constef2d127de37b942baad06145) (let _00024sqo09Ee630 const6b86b273ff34fce19d6b804e) (let _00024sqo5YJw629 const5feceb66ffc86f38d952786c) (let _00024sqo1RnK632 const2c624232cdd221771294dfbb) (let _00024sqo5bHs631 const6b86b273ff34fce19d6b804e) (let _00024sqo2z3g634 constd4735e3a265e16eee03f5971) (let _00024sqo0Hmn633 constd4735e3a265e16eee03f5971) (let _00024sqo7Xdh636 constef2d127de37b942baad06145) (let _00024sqo5nmm635 const4e07408562bedb8b60ce05c1) (let _00024sqo4nJm638 const6b86b273ff34fce19d6b804e) (let _00024sqo7qJs637 const4e07408562bedb8b60ce05c1) (let _00024sqo4dTI640 const2c624232cdd221771294dfbb) (let _00024sqo4MMk639 constd4735e3a265e16eee03f5971) (let _00024sqo3whL642 constd4735e3a265e16eee03f5971) (let _00024sqo9zLj641 const6b86b273ff34fce19d6b804e) (let _00024sqo1Fkt644 constef2d127de37b942baad06145) (let _00024sqo2E1m643 const5feceb66ffc86f38d952786c)) (probe $seq_atr (0 1 2) 2 _00024sqo3whL642 _00024sqo9zLj641 _00024seq0) (body (join $seq_at (1 0 2) 3 _00024sqo5YJw629 _00024sqo09Ee630 _00024seq0) (join $seq_at (1 0 2) 3 _00024sqo5bHs631 _00024sqo1RnK632 _00024seq0) (join $seq_at (1 0 2) 3 _00024sqo0Hmn633 _00024sqo2z3g634 _00024seq0) (join $seq_at (1 0 2) 3 _00024sqo5nmm635 _00024sqo7Xdh636 _00024seq0) (join $seq_atr (0 1 2) 3 _00024sqo4nJm638 _00024sqo7qJs637 _00024seq0) (join $seq_atr (0 1 2) 3 _00024sqo4dTI640 _00024sqo4MMk639 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo1Fkt644 _00024sqo2E1m643 _00024seq0) (join st_fromlist (1 0) 1 _00024seq0 __t2iar332) (join st_fromlist_ans (0 1) 1 __t2iar332 r) (letp _00024sql7znl618 (aslst _00024seq0)) (let chk9Nlj1389 (llen _00024sql7znl618)) (eq _00024sqc6FSA620 chk9Nlj1389) (letp chk43Tj1390 (lref _00024sql7znl618 _00024sqc3Ub8621)) (eq _00024sqc1TCF622 chk43Tj1390) (letp chk7vXj1391 (lref _00024sql7znl618 _00024sqc3FMQ623)) (eq _00024sqc41K7624 chk7vXj1391) (letp chk44uG1392 (lref _00024sql7znl618 _00024sqc6uPA625)) (eq _00024sqc9VIm626 chk44uG1392) (letp chk49RA1393 (lref _00024sql7znl618 _00024sqc7Q1B627)) (eq _00024sqc4nIn628 chk49RA1393)) (head (emit canon (0) r)) st_basic.slog:17 #f)
  class ReadTask199 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex189;  slog::Index** $seq_atindex190;  slog::Index** $seq_atindex191;  slog::Index** $seq_atindex192;  slog::Index** $seq_atrindex193;  slog::Index** $seq_atrindex194;  slog::Index** $seq_atrindex195;  slog::Index** st_fromlistindex196;  slog::Index** st_fromlist_ansindex197;  slog::Index** $seq_atrdelta198;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("canon");
      std::vector<u16> ord200({0});
      slog::Relation* readrel201 = db->getRelation("canon");
      head_index[0] = readrel201->getIndex(ord200, false);
      std::vector<u16> ord202({0, 1, 2});
      slog::Relation* readrel203 = db->getRelation("$seq_atr");
      driver_index = readrel203->getIndex(ord202, true);
      std::vector<u16> ord204({1, 0, 2});
      slog::Relation* readrel205 = db->getRelation("$seq_at");
      $seq_atindex189 = readrel205->getIndex(ord204, false);
      std::vector<u16> ord206({1, 0, 2});
      slog::Relation* readrel207 = db->getRelation("$seq_at");
      $seq_atindex190 = readrel207->getIndex(ord206, false);
      std::vector<u16> ord208({1, 0, 2});
      slog::Relation* readrel209 = db->getRelation("$seq_at");
      $seq_atindex191 = readrel209->getIndex(ord208, false);
      std::vector<u16> ord210({1, 0, 2});
      slog::Relation* readrel211 = db->getRelation("$seq_at");
      $seq_atindex192 = readrel211->getIndex(ord210, false);
      std::vector<u16> ord212({0, 1, 2});
      slog::Relation* readrel213 = db->getRelation("$seq_atr");
      $seq_atrindex193 = readrel213->getIndex(ord212, false);
      std::vector<u16> ord214({0, 1, 2});
      slog::Relation* readrel215 = db->getRelation("$seq_atr");
      $seq_atrindex194 = readrel215->getIndex(ord214, false);
      std::vector<u16> ord216({0, 1, 2});
      slog::Relation* readrel217 = db->getRelation("$seq_atr");
      $seq_atrindex195 = readrel217->getIndex(ord216, false);
      std::vector<u16> ord218({0, 1, 2});
      slog::Relation* readrel219 = db->getRelation("$seq_atr");
      $seq_atrdelta198 = readrel219->getIndex(ord218, true);
      std::vector<u16> ord220({1, 0});
      slog::Relation* readrel221 = db->getRelation("st_fromlist");
      st_fromlistindex196 = readrel221->getIndex(ord220, false);
      std::vector<u16> ord222({0, 1});
      slog::Relation* readrel223 = db->getRelation("st_fromlist_ans");
      st_fromlist_ansindex197 = readrel223->getIndex(ord222, false);
  
    }
    ReadTask199(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c49 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c50 = v_const5feceb66ffc86f38d952786c;
      u64 v_c51 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c52 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c53 = v_const2c624232cdd221771294dfbb;
      u64 v_c54 = v_constd4735e3a265e16eee03f5971;
      u64 v_c55 = v_constd4735e3a265e16eee03f5971;
      u64 v_c56 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c57 = v_constef2d127de37b942baad06145;
      u64 v_c58 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c59 = v_const5feceb66ffc86f38d952786c;
      u64 v_c60 = v_const2c624232cdd221771294dfbb;
      u64 v_c61 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c62 = v_constd4735e3a265e16eee03f5971;
      u64 v_c63 = v_constd4735e3a265e16eee03f5971;
      u64 v_c64 = v_constef2d127de37b942baad06145;
      u64 v_c65 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c66 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c67 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c68 = v_const2c624232cdd221771294dfbb;
      u64 v_c69 = v_constd4735e3a265e16eee03f5971;
      u64 v_c70 = v_constd4735e3a265e16eee03f5971;
      u64 v_c71 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c72 = v_constef2d127de37b942baad06145;
      u64 v_c73 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c70, v_c71, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m224) {
        u64 v_c74 = m224[2];
        if (buckethash(v_c74) != bucket) return;
        slog::join_probe<3,3>($seq_atindex189, std::array<u64,3>{v_c59, v_c58, v_c74}, [&](const std::array<u64,3>& m225) {
          slog::join_probe<3,3>($seq_atindex190, std::array<u64,3>{v_c61, v_c60, v_c74}, [&](const std::array<u64,3>& m226) {
            slog::join_probe<3,3>($seq_atindex191, std::array<u64,3>{v_c63, v_c62, v_c74}, [&](const std::array<u64,3>& m227) {
              slog::join_probe<3,3>($seq_atindex192, std::array<u64,3>{v_c65, v_c64, v_c74}, [&](const std::array<u64,3>& m228) {
                slog::join_probe<3,3>($seq_atrindex193, std::array<u64,3>{v_c66, v_c67, v_c74}, [&](const std::array<u64,3>& m229) {
                  slog::join_probe<3,3>($seq_atrindex194, std::array<u64,3>{v_c68, v_c69, v_c74}, [&](const std::array<u64,3>& m230) {
                    slog::join_probe_old<3,3>($seq_atrindex195, $seq_atrdelta198, std::array<u64,3>{v_c72, v_c73, v_c74}, [&](const std::array<u64,3>& m231) {
                      slog::join_probe<2,1>(st_fromlistindex196, std::array<u64,2>{v_c74, 0}, [&](const std::array<u64,2>& m232) {
                        u64 v_c75 = m232[1];
                        slog::join_probe<2,1>(st_fromlist_ansindex197, std::array<u64,2>{v_c75, 0}, [&](const std::array<u64,2>& m233) {
                          u64 v_c8 = m233[1];
                          bool ok234 = true;
                          u64 v_c76 = _prim_aslst(db, v_c74, &ok234);
                          if (!ok234) return;
                          u64 v_c77 = _prim_llen(db, v_c76);
                          if (v_c77 == slog_error) { slog::emit_pending_error(db, "st_basic.slog:17"); return; }
                          if (v_c49 != v_c77) return;
                          bool ok235 = true;
                          u64 v_c78 = _prim_lref(db, v_c76, v_c50, &ok235);
                          if (!ok235) return;
                          if (v_c51 != v_c78) return;
                          bool ok236 = true;
                          u64 v_c79 = _prim_lref(db, v_c76, v_c52, &ok236);
                          if (!ok236) return;
                          if (v_c53 != v_c79) return;
                          bool ok237 = true;
                          u64 v_c80 = _prim_lref(db, v_c76, v_c54, &ok237);
                          if (!ok237) return;
                          if (v_c55 != v_c80) return;
                          bool ok238 = true;
                          u64 v_c81 = _prim_lref(db, v_c76, v_c56, &ok238);
                          if (!ok238) return;
                          if (v_c57 != v_c81) return;
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
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("st_basic.slog:17", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask199* _cont = new ReadTask199(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask199(db,b), false);
  // (crule (pre) (scan $sup9688x136x0x0x0 __t5pD6408 l m p r u v) (body (exists pbranch (1 2 3 4 0) 4 p m l r) (exists st_diff (1 2 0) 2 l u) (exists st_diff (1 2 0) 2 r v) (exists st_bld (1 2 3 4 0) 2 p m) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m u v __t9ous406) (exists st_diff (2 0 1) 2 __t9ous406 __t5pD6408) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t3cJ7407) (join-old st_diff (0 1 2) 3 (0 1 2) __t5pD6408 __t3cJ7407 __t9ous406) (join-old st_diff (1 2 0) 2 (1 2 0) l u __t6cu0410) (exists st_diff_ans (0 1) 1 __t6cu0410) (join-old st_diff (1 2 0) 2 (1 2 0) r v __t8u30411) (exists st_diff_ans (0 1) 1 __t8u30411) (join-old st_bld (1 2 3 4 0) 2 (1 2 3 4 0) p m __v0 __v1 __t9obY409) (join st_diff_ans (0 1) 2 __t6cu0410 __v0) (join st_diff_ans (0 1) 2 __t8u30411 __v1) (join st_bld_ans (0 1) 1 __t9obY409 res)) (head (emit st_diff_ans (0 1) __t5pD6408 res)) set.slog:137 #f)
  class ReadTask261 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex239;  slog::Index** st_diffindex240;  slog::Index** st_diffindex241;  slog::Index** st_bldindex242;  slog::Index** pbranchindex243;  slog::Index** st_diffindex244;  slog::Index** pbranchindex245;  slog::Index** st_diffindex246;  slog::Index** st_diffindex247;  slog::Index** st_diff_ansindex248;  slog::Index** st_diffindex249;  slog::Index** st_diff_ansindex250;  slog::Index** st_bldindex251;  slog::Index** st_diff_ansindex252;  slog::Index** st_diff_ansindex253;  slog::Index** st_bld_ansindex254;  slog::Index** pbranchdelta255;  slog::Index** pbranchdelta256;  slog::Index** st_diffdelta257;  slog::Index** st_diffdelta258;  slog::Index** st_diffdelta259;  slog::Index** st_blddelta260;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord262({0, 1});
      slog::Relation* readrel263 = db->getRelation("st_diff_ans");
      head_index[0] = readrel263->getIndex(ord262, false);
      outer_rel = db->getRelation("$sup9688x136x0x0x0");
      std::vector<u16> ord264({1, 2, 3, 4, 0});
      slog::Relation* readrel265 = db->getRelation("pbranch");
      pbranchindex239 = readrel265->getIndex(ord264, false);
      std::vector<u16> ord266({1, 2, 0});
      slog::Relation* readrel267 = db->getRelation("st_diff");
      st_diffindex240 = readrel267->getIndex(ord266, false);
      std::vector<u16> ord268({1, 2, 0});
      slog::Relation* readrel269 = db->getRelation("st_diff");
      st_diffindex241 = readrel269->getIndex(ord268, false);
      std::vector<u16> ord270({1, 2, 3, 4, 0});
      slog::Relation* readrel271 = db->getRelation("st_bld");
      st_bldindex242 = readrel271->getIndex(ord270, false);
      std::vector<u16> ord272({1, 2, 3, 4, 0});
      slog::Relation* readrel273 = db->getRelation("pbranch");
      pbranchindex243 = readrel273->getIndex(ord272, false);
      std::vector<u16> ord274({1, 2, 3, 4, 0});
      slog::Relation* readrel275 = db->getRelation("pbranch");
      pbranchdelta255 = readrel275->getIndex(ord274, true);
      std::vector<u16> ord276({2, 0, 1});
      slog::Relation* readrel277 = db->getRelation("st_diff");
      st_diffindex244 = readrel277->getIndex(ord276, false);
      std::vector<u16> ord278({1, 2, 3, 4, 0});
      slog::Relation* readrel279 = db->getRelation("pbranch");
      pbranchindex245 = readrel279->getIndex(ord278, false);
      std::vector<u16> ord280({1, 2, 3, 4, 0});
      slog::Relation* readrel281 = db->getRelation("pbranch");
      pbranchdelta256 = readrel281->getIndex(ord280, true);
      std::vector<u16> ord282({0, 1, 2});
      slog::Relation* readrel283 = db->getRelation("st_diff");
      st_diffindex246 = readrel283->getIndex(ord282, false);
      std::vector<u16> ord284({0, 1, 2});
      slog::Relation* readrel285 = db->getRelation("st_diff");
      st_diffdelta257 = readrel285->getIndex(ord284, true);
      std::vector<u16> ord286({1, 2, 0});
      slog::Relation* readrel287 = db->getRelation("st_diff");
      st_diffindex247 = readrel287->getIndex(ord286, false);
      std::vector<u16> ord288({1, 2, 0});
      slog::Relation* readrel289 = db->getRelation("st_diff");
      st_diffdelta258 = readrel289->getIndex(ord288, true);
      std::vector<u16> ord290({0, 1});
      slog::Relation* readrel291 = db->getRelation("st_diff_ans");
      st_diff_ansindex248 = readrel291->getIndex(ord290, false);
      std::vector<u16> ord292({1, 2, 0});
      slog::Relation* readrel293 = db->getRelation("st_diff");
      st_diffindex249 = readrel293->getIndex(ord292, false);
      std::vector<u16> ord294({1, 2, 0});
      slog::Relation* readrel295 = db->getRelation("st_diff");
      st_diffdelta259 = readrel295->getIndex(ord294, true);
      std::vector<u16> ord296({0, 1});
      slog::Relation* readrel297 = db->getRelation("st_diff_ans");
      st_diff_ansindex250 = readrel297->getIndex(ord296, false);
      std::vector<u16> ord298({1, 2, 3, 4, 0});
      slog::Relation* readrel299 = db->getRelation("st_bld");
      st_bldindex251 = readrel299->getIndex(ord298, false);
      std::vector<u16> ord300({1, 2, 3, 4, 0});
      slog::Relation* readrel301 = db->getRelation("st_bld");
      st_blddelta260 = readrel301->getIndex(ord300, true);
      std::vector<u16> ord302({0, 1});
      slog::Relation* readrel303 = db->getRelation("st_diff_ans");
      st_diff_ansindex252 = readrel303->getIndex(ord302, false);
      std::vector<u16> ord304({0, 1});
      slog::Relation* readrel305 = db->getRelation("st_diff_ans");
      st_diff_ansindex253 = readrel305->getIndex(ord304, false);
      std::vector<u16> ord306({0, 1});
      slog::Relation* readrel307 = db->getRelation("st_bld_ans");
      st_bld_ansindex254 = readrel307->getIndex(ord306, false);
  
    }
    ReadTask261(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c82 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c7 = _t[3];
        u64 v_c8 = _t[4];
        u64 v_c47 = _t[5];
        u64 v_c48 = _t[6];
        if (!slog::exists_probe<5,4>(pbranchindex239, std::array<u64,5>{v_c7, v_c6, v_c2, v_c8, 0})) return;
        if (!slog::exists_probe<3,2>(st_diffindex240, std::array<u64,3>{v_c2, v_c47, 0})) return;
        if (!slog::exists_probe<3,2>(st_diffindex241, std::array<u64,3>{v_c8, v_c48, 0})) return;
        if (!slog::exists_probe<5,2>(st_bldindex242, std::array<u64,5>{v_c7, v_c6, 0, 0, 0})) return;
        slog::join_probe_old<5,4>(pbranchindex243, pbranchdelta255, std::array<u64,5>{v_c7, v_c6, v_c47, v_c48, 0}, [&](const std::array<u64,5>& m308) {
          u64 v_c83 = m308[4];
          if (!slog::exists_probe<3,2>(st_diffindex244, std::array<u64,3>{v_c83, v_c82, 0})) return;
          slog::join_probe_old<5,4>(pbranchindex245, pbranchdelta256, std::array<u64,5>{v_c7, v_c6, v_c2, v_c8, 0}, [&](const std::array<u64,5>& m309) {
            u64 v_c84 = m309[4];
            slog::join_probe_old<3,3>(st_diffindex246, st_diffdelta257, std::array<u64,3>{v_c82, v_c84, v_c83}, [&](const std::array<u64,3>& m310) {
              slog::join_probe_old<3,2>(st_diffindex247, st_diffdelta258, std::array<u64,3>{v_c2, v_c47, 0}, [&](const std::array<u64,3>& m311) {
                u64 v_c85 = m311[2];
                if (!slog::exists_probe<2,1>(st_diff_ansindex248, std::array<u64,2>{v_c85, 0})) return;
                slog::join_probe_old<3,2>(st_diffindex249, st_diffdelta259, std::array<u64,3>{v_c8, v_c48, 0}, [&](const std::array<u64,3>& m312) {
                  u64 v_c86 = m312[2];
                  if (!slog::exists_probe<2,1>(st_diff_ansindex250, std::array<u64,2>{v_c86, 0})) return;
                  slog::join_probe_old<5,2>(st_bldindex251, st_blddelta260, std::array<u64,5>{v_c7, v_c6, 0, 0, 0}, [&](const std::array<u64,5>& m313) {
                    u64 v_c4 = m313[2]; u64 v_c22 = m313[3]; u64 v_c87 = m313[4];
                    slog::join_probe<2,2>(st_diff_ansindex252, std::array<u64,2>{v_c85, v_c4}, [&](const std::array<u64,2>& m314) {
                      slog::join_probe<2,2>(st_diff_ansindex253, std::array<u64,2>{v_c86, v_c22}, [&](const std::array<u64,2>& m315) {
                        slog::join_probe<2,1>(st_bld_ansindex254, std::array<u64,2>{v_c87, 0}, [&](const std::array<u64,2>& m316) {
                          u64 v_c12 = m316[1];
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c82, v_c12}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("set.slog:137", "delta:$sup9688x136x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask261* _cont = new ReadTask261(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask261(db,b), false);
  // (crule (pre) (scan $sup9688x40x0x0x0 __d0 p0 p1 t0 t1) (body (let __t8J2j229 (bxor p0 p1))) (head (emit-temp temp1foc1411 __t8J2j229)) set.slog:41 #f)
  class ReadTask317 : public slog::Task
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
      head_rel[0] = db->getRelation("temp1foc1411");
      outer_rel = db->getRelation("$sup9688x40x0x0x0");
  
    }
    ReadTask317(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c44 = _t[0];
        u64 v_c88 = _t[1];
        u64 v_c89 = _t[2];
        u64 v_c90 = _t[3];
        u64 v_c91 = _t[4];
        u64 v_c92 = _prim_bxor(db, v_c88, v_c89);
        if (v_c92 == slog_error) { slog::emit_pending_error(db, "set.slog:41"); return; }
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c92});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:41", "delta:$sup9688x40x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask317* _cont = new ReadTask317(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask317(db,b), false);
  // (crule (pre) (scan st_bld_ans __t9obY409 res) (body (join-old st_bld (0 1 2 3 4) 1 (0 1 2 3 4) __t9obY409 p m __v0 __v1) (exists $sup9688x136x0x0x0 (2 3 1 4 0 5 6) 2 m p) (exists pbranch (1 2 3 4 0) 2 p m) (exists st_diff_ans (1 0) 1 __v0) (exists st_diff_ans (1 0) 1 __v1) (join-old pbranch (1 2 3 4 0) 2 (1 2 3 4 0) p m u v __t9ous406) (exists st_diff (2 0 1) 1 __t9ous406) (exists st_diff (2 0 1) 1 u) (exists st_diff (2 0 1) 1 v) (join-old $sup9688x136x0x0x0 (2 3 5 6 0 1 4) 4 (2 3 5 6 0 1 4) m p u v __t5pD6408 l r) (exists st_diff (2 0 1) 2 __t9ous406 __t5pD6408) (exists st_diff (1 2 0) 2 l u) (exists st_diff (1 2 0) 2 r v) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t3cJ7407) (join-old st_diff (0 1 2) 3 (0 1 2) __t5pD6408 __t3cJ7407 __t9ous406) (join-old st_diff (1 2 0) 2 (1 2 0) l u __t6cu0410) (join-old st_diff_ans (0 1) 2 (0 1) __t6cu0410 __v0) (join-old st_diff (1 2 0) 2 (1 2 0) r v __t8u30411) (join-old st_diff_ans (0 1) 2 (0 1) __t8u30411 __v1)) (head (emit st_diff_ans (0 1) __t5pD6408 res)) set.slog:137 #f)
  class ReadTask346 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_bldindex318;  slog::Index** $sup9688x136x0x0x0index319;  slog::Index** pbranchindex320;  slog::Index** st_diff_ansindex321;  slog::Index** st_diff_ansindex322;  slog::Index** pbranchindex323;  slog::Index** st_diffindex324;  slog::Index** st_diffindex325;  slog::Index** st_diffindex326;  slog::Index** $sup9688x136x0x0x0index327;  slog::Index** st_diffindex328;  slog::Index** st_diffindex329;  slog::Index** st_diffindex330;  slog::Index** pbranchindex331;  slog::Index** st_diffindex332;  slog::Index** st_diffindex333;  slog::Index** st_diff_ansindex334;  slog::Index** st_diffindex335;  slog::Index** st_diff_ansindex336;  slog::Index** st_blddelta337;  slog::Index** pbranchdelta338;  slog::Index** $sup9688x136x0x0x0delta339;  slog::Index** pbranchdelta340;  slog::Index** st_diffdelta341;  slog::Index** st_diffdelta342;  slog::Index** st_diff_ansdelta343;  slog::Index** st_diffdelta344;  slog::Index** st_diff_ansdelta345;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord347({0, 1});
      slog::Relation* readrel348 = db->getRelation("st_diff_ans");
      head_index[0] = readrel348->getIndex(ord347, false);
      outer_rel = db->getRelation("st_bld_ans");
      std::vector<u16> ord349({0, 1, 2, 3, 4});
      slog::Relation* readrel350 = db->getRelation("st_bld");
      st_bldindex318 = readrel350->getIndex(ord349, false);
      std::vector<u16> ord351({0, 1, 2, 3, 4});
      slog::Relation* readrel352 = db->getRelation("st_bld");
      st_blddelta337 = readrel352->getIndex(ord351, true);
      std::vector<u16> ord353({2, 3, 1, 4, 0, 5, 6});
      slog::Relation* readrel354 = db->getRelation("$sup9688x136x0x0x0");
      $sup9688x136x0x0x0index319 = readrel354->getIndex(ord353, false);
      std::vector<u16> ord355({1, 2, 3, 4, 0});
      slog::Relation* readrel356 = db->getRelation("pbranch");
      pbranchindex320 = readrel356->getIndex(ord355, false);
      std::vector<u16> ord357({1, 0});
      slog::Relation* readrel358 = db->getRelation("st_diff_ans");
      st_diff_ansindex321 = readrel358->getIndex(ord357, false);
      std::vector<u16> ord359({1, 0});
      slog::Relation* readrel360 = db->getRelation("st_diff_ans");
      st_diff_ansindex322 = readrel360->getIndex(ord359, false);
      std::vector<u16> ord361({1, 2, 3, 4, 0});
      slog::Relation* readrel362 = db->getRelation("pbranch");
      pbranchindex323 = readrel362->getIndex(ord361, false);
      std::vector<u16> ord363({1, 2, 3, 4, 0});
      slog::Relation* readrel364 = db->getRelation("pbranch");
      pbranchdelta338 = readrel364->getIndex(ord363, true);
      std::vector<u16> ord365({2, 0, 1});
      slog::Relation* readrel366 = db->getRelation("st_diff");
      st_diffindex324 = readrel366->getIndex(ord365, false);
      std::vector<u16> ord367({2, 0, 1});
      slog::Relation* readrel368 = db->getRelation("st_diff");
      st_diffindex325 = readrel368->getIndex(ord367, false);
      std::vector<u16> ord369({2, 0, 1});
      slog::Relation* readrel370 = db->getRelation("st_diff");
      st_diffindex326 = readrel370->getIndex(ord369, false);
      std::vector<u16> ord371({2, 3, 5, 6, 0, 1, 4});
      slog::Relation* readrel372 = db->getRelation("$sup9688x136x0x0x0");
      $sup9688x136x0x0x0index327 = readrel372->getIndex(ord371, false);
      std::vector<u16> ord373({2, 3, 5, 6, 0, 1, 4});
      slog::Relation* readrel374 = db->getRelation("$sup9688x136x0x0x0");
      $sup9688x136x0x0x0delta339 = readrel374->getIndex(ord373, true);
      std::vector<u16> ord375({2, 0, 1});
      slog::Relation* readrel376 = db->getRelation("st_diff");
      st_diffindex328 = readrel376->getIndex(ord375, false);
      std::vector<u16> ord377({1, 2, 0});
      slog::Relation* readrel378 = db->getRelation("st_diff");
      st_diffindex329 = readrel378->getIndex(ord377, false);
      std::vector<u16> ord379({1, 2, 0});
      slog::Relation* readrel380 = db->getRelation("st_diff");
      st_diffindex330 = readrel380->getIndex(ord379, false);
      std::vector<u16> ord381({1, 2, 3, 4, 0});
      slog::Relation* readrel382 = db->getRelation("pbranch");
      pbranchindex331 = readrel382->getIndex(ord381, false);
      std::vector<u16> ord383({1, 2, 3, 4, 0});
      slog::Relation* readrel384 = db->getRelation("pbranch");
      pbranchdelta340 = readrel384->getIndex(ord383, true);
      std::vector<u16> ord385({0, 1, 2});
      slog::Relation* readrel386 = db->getRelation("st_diff");
      st_diffindex332 = readrel386->getIndex(ord385, false);
      std::vector<u16> ord387({0, 1, 2});
      slog::Relation* readrel388 = db->getRelation("st_diff");
      st_diffdelta341 = readrel388->getIndex(ord387, true);
      std::vector<u16> ord389({1, 2, 0});
      slog::Relation* readrel390 = db->getRelation("st_diff");
      st_diffindex333 = readrel390->getIndex(ord389, false);
      std::vector<u16> ord391({1, 2, 0});
      slog::Relation* readrel392 = db->getRelation("st_diff");
      st_diffdelta342 = readrel392->getIndex(ord391, true);
      std::vector<u16> ord393({0, 1});
      slog::Relation* readrel394 = db->getRelation("st_diff_ans");
      st_diff_ansindex334 = readrel394->getIndex(ord393, false);
      std::vector<u16> ord395({0, 1});
      slog::Relation* readrel396 = db->getRelation("st_diff_ans");
      st_diff_ansdelta343 = readrel396->getIndex(ord395, true);
      std::vector<u16> ord397({1, 2, 0});
      slog::Relation* readrel398 = db->getRelation("st_diff");
      st_diffindex335 = readrel398->getIndex(ord397, false);
      std::vector<u16> ord399({1, 2, 0});
      slog::Relation* readrel400 = db->getRelation("st_diff");
      st_diffdelta344 = readrel400->getIndex(ord399, true);
      std::vector<u16> ord401({0, 1});
      slog::Relation* readrel402 = db->getRelation("st_diff_ans");
      st_diff_ansindex336 = readrel402->getIndex(ord401, false);
      std::vector<u16> ord403({0, 1});
      slog::Relation* readrel404 = db->getRelation("st_diff_ans");
      st_diff_ansdelta345 = readrel404->getIndex(ord403, true);
  
    }
    ReadTask346(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c12 = _t[1];
        slog::join_probe_old<5,1>(st_bldindex318, st_blddelta337, std::array<u64,5>{v_c87, 0, 0, 0, 0}, [&](const std::array<u64,5>& m405) {
          u64 v_c7 = m405[1]; u64 v_c6 = m405[2]; u64 v_c4 = m405[3]; u64 v_c22 = m405[4];
          if (!slog::exists_probe<7,2>($sup9688x136x0x0x0index319, std::array<u64,7>{v_c6, v_c7, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,2>(pbranchindex320, std::array<u64,5>{v_c7, v_c6, 0, 0, 0})) return;
          if (!slog::exists_probe<2,1>(st_diff_ansindex321, std::array<u64,2>{v_c4, 0})) return;
          if (!slog::exists_probe<2,1>(st_diff_ansindex322, std::array<u64,2>{v_c22, 0})) return;
          slog::join_probe_old<5,2>(pbranchindex323, pbranchdelta338, std::array<u64,5>{v_c7, v_c6, 0, 0, 0}, [&](const std::array<u64,5>& m406) {
            u64 v_c47 = m406[2]; u64 v_c48 = m406[3]; u64 v_c83 = m406[4];
            if (!slog::exists_probe<3,1>(st_diffindex324, std::array<u64,3>{v_c83, 0, 0})) return;
            if (!slog::exists_probe<3,1>(st_diffindex325, std::array<u64,3>{v_c47, 0, 0})) return;
            if (!slog::exists_probe<3,1>(st_diffindex326, std::array<u64,3>{v_c48, 0, 0})) return;
            slog::join_probe_old<7,4>($sup9688x136x0x0x0index327, $sup9688x136x0x0x0delta339, std::array<u64,7>{v_c6, v_c7, v_c47, v_c48, 0, 0, 0}, [&](const std::array<u64,7>& m407) {
              u64 v_c82 = m407[4]; u64 v_c2 = m407[5]; u64 v_c8 = m407[6];
              if (!slog::exists_probe<3,2>(st_diffindex328, std::array<u64,3>{v_c83, v_c82, 0})) return;
              if (!slog::exists_probe<3,2>(st_diffindex329, std::array<u64,3>{v_c2, v_c47, 0})) return;
              if (!slog::exists_probe<3,2>(st_diffindex330, std::array<u64,3>{v_c8, v_c48, 0})) return;
              slog::join_probe_old<5,4>(pbranchindex331, pbranchdelta340, std::array<u64,5>{v_c7, v_c6, v_c2, v_c8, 0}, [&](const std::array<u64,5>& m408) {
                u64 v_c84 = m408[4];
                slog::join_probe_old<3,3>(st_diffindex332, st_diffdelta341, std::array<u64,3>{v_c82, v_c84, v_c83}, [&](const std::array<u64,3>& m409) {
                  slog::join_probe_old<3,2>(st_diffindex333, st_diffdelta342, std::array<u64,3>{v_c2, v_c47, 0}, [&](const std::array<u64,3>& m410) {
                    u64 v_c85 = m410[2];
                    slog::join_probe_old<2,2>(st_diff_ansindex334, st_diff_ansdelta343, std::array<u64,2>{v_c85, v_c4}, [&](const std::array<u64,2>& m411) {
                      slog::join_probe_old<3,2>(st_diffindex335, st_diffdelta344, std::array<u64,3>{v_c8, v_c48, 0}, [&](const std::array<u64,3>& m412) {
                        u64 v_c86 = m412[2];
                        slog::join_probe_old<2,2>(st_diff_ansindex336, st_diff_ansdelta345, std::array<u64,2>{v_c86, v_c22}, [&](const std::array<u64,2>& m413) {
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c82, v_c12}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("set.slog:137", "delta:st_bld_ans", _fires);
  
      if (!_done)
      {
        ReadTask346* _cont = new ReadTask346(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask346(db,b), false);
  // (crule (pre (let _00024sqc374s650 const6b86b273ff34fce19d6b804e) (let _00024sqc70tB651 const5feceb66ffc86f38d952786c) (let _00024sqc9HvG652 const6b86b273ff34fce19d6b804e) (let _00024sqc2OSe653 const5feceb66ffc86f38d952786c) (let _00024sqo65nP658 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo65nP658 x _00024seq0) (body (letp _00024sql5p7m648 (aslst _00024seq0)) (let _00024sqn1lS2649 (llen _00024sql5p7m648)) (cmp ge _00024sqn1lS2649 _00024sqc374s650) (let _00024sqp836n654 (_0002d _00024sqn1lS2649 _00024sqc2OSe653)) (let xs (lslice _00024sql5p7m648 _00024sqc9HvG652 _00024sqp836n654)) (exists st_fromlist (1 0) 1 _00024seq0) (exists st_fromlist (1 0) 1 xs) (exists st_ins (2 0 1) 1 x) (join $sup9688x168x0x0x0 (2 3 0 1) 3 x xs _00024seq0 __t9UzC72) (join st_fromlist (0 1) 2 __t9UzC72 _00024seq0) (join st_fromlist (1 0) 1 xs __t6xe073) (join st_fromlist_ans (0 1) 1 __t6xe073 __v0) (join st_ins (1 2 0) 2 __v0 x __t8MgF74) (join st_ins_ans (0 1) 1 __t8MgF74 __v1) (letp chk2EVZ1286 (lref _00024sql5p7m648 _00024sqc70tB651)) (eq x chk2EVZ1286)) (head (emit st_fromlist_ans (0 1) __t9UzC72 __v1)) set.slog:169 #f)
  class ReadTask423 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** st_fromlistindex414;  slog::Index** st_fromlistindex415;  slog::Index** st_insindex416;  slog::Index** $sup9688x168x0x0x0index417;  slog::Index** st_fromlistindex418;  slog::Index** st_fromlistindex419;  slog::Index** st_fromlist_ansindex420;  slog::Index** st_insindex421;  slog::Index** st_ins_ansindex422;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_fromlist_ans");
      std::vector<u16> ord424({0, 1});
      slog::Relation* readrel425 = db->getRelation("st_fromlist_ans");
      head_index[0] = readrel425->getIndex(ord424, false);
      std::vector<u16> ord426({1, 0, 2});
      slog::Relation* readrel427 = db->getRelation("$seq_at");
      driver_index = readrel427->getIndex(ord426, true);
      std::vector<u16> ord428({1, 0});
      slog::Relation* readrel429 = db->getRelation("st_fromlist");
      st_fromlistindex414 = readrel429->getIndex(ord428, false);
      std::vector<u16> ord430({1, 0});
      slog::Relation* readrel431 = db->getRelation("st_fromlist");
      st_fromlistindex415 = readrel431->getIndex(ord430, false);
      std::vector<u16> ord432({2, 0, 1});
      slog::Relation* readrel433 = db->getRelation("st_ins");
      st_insindex416 = readrel433->getIndex(ord432, false);
      std::vector<u16> ord434({2, 3, 0, 1});
      slog::Relation* readrel435 = db->getRelation("$sup9688x168x0x0x0");
      $sup9688x168x0x0x0index417 = readrel435->getIndex(ord434, false);
      std::vector<u16> ord436({0, 1});
      slog::Relation* readrel437 = db->getRelation("st_fromlist");
      st_fromlistindex418 = readrel437->getIndex(ord436, false);
      std::vector<u16> ord438({1, 0});
      slog::Relation* readrel439 = db->getRelation("st_fromlist");
      st_fromlistindex419 = readrel439->getIndex(ord438, false);
      std::vector<u16> ord440({0, 1});
      slog::Relation* readrel441 = db->getRelation("st_fromlist_ans");
      st_fromlist_ansindex420 = readrel441->getIndex(ord440, false);
      std::vector<u16> ord442({1, 2, 0});
      slog::Relation* readrel443 = db->getRelation("st_ins");
      st_insindex421 = readrel443->getIndex(ord442, false);
      std::vector<u16> ord444({0, 1});
      slog::Relation* readrel445 = db->getRelation("st_ins_ans");
      st_ins_ansindex422 = readrel445->getIndex(ord444, false);
  
    }
    ReadTask423(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c93 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c94 = v_const5feceb66ffc86f38d952786c;
      u64 v_c95 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c96 = v_const5feceb66ffc86f38d952786c;
      u64 v_c97 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c97, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m446) {
        u64 v_c98 = m446[1];
        u64 v_c74 = m446[2];
        if (buckethash(v_c98) != bucket) return;
        bool ok447 = true;
        u64 v_c99 = _prim_aslst(db, v_c74, &ok447);
        if (!ok447) return;
        u64 v_c100 = _prim_llen(db, v_c99);
        if (v_c100 == slog_error) { slog::emit_pending_error(db, "set.slog:169"); return; }
        u64 v_c101 = _prim_ge(db, v_c100, v_c93);
        if (v_c101 == slog_error) { slog::emit_pending_error(db, "set.slog:169"); return; }
        if (!v_c101) return;
        u64 v_c102 = _prim__0002d(db, v_c100, v_c96);
        if (v_c102 == slog_error) { slog::emit_pending_error(db, "set.slog:169"); return; }
        u64 v_c103 = _prim_lslice(db, v_c99, v_c95, v_c102);
        if (v_c103 == slog_error) { slog::emit_pending_error(db, "set.slog:169"); return; }
        if (!slog::exists_probe<2,1>(st_fromlistindex414, std::array<u64,2>{v_c74, 0})) return;
        if (!slog::exists_probe<2,1>(st_fromlistindex415, std::array<u64,2>{v_c103, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex416, std::array<u64,3>{v_c98, 0, 0})) return;
        slog::join_probe<4,3>($sup9688x168x0x0x0index417, std::array<u64,4>{v_c98, v_c103, v_c74, 0}, [&](const std::array<u64,4>& m449) {
          u64 v_c104 = m449[3];
          slog::join_probe<2,2>(st_fromlistindex418, std::array<u64,2>{v_c104, v_c74}, [&](const std::array<u64,2>& m450) {
            slog::join_probe<2,1>(st_fromlistindex419, std::array<u64,2>{v_c103, 0}, [&](const std::array<u64,2>& m451) {
              u64 v_c105 = m451[1];
              slog::join_probe<2,1>(st_fromlist_ansindex420, std::array<u64,2>{v_c105, 0}, [&](const std::array<u64,2>& m452) {
                u64 v_c4 = m452[1];
                slog::join_probe<3,2>(st_insindex421, std::array<u64,3>{v_c4, v_c98, 0}, [&](const std::array<u64,3>& m453) {
                  u64 v_c106 = m453[2];
                  slog::join_probe<2,1>(st_ins_ansindex422, std::array<u64,2>{v_c106, 0}, [&](const std::array<u64,2>& m454) {
                    u64 v_c22 = m454[1];
                    bool ok455 = true;
                    u64 v_c107 = _prim_lref(db, v_c99, v_c94, &ok455);
                    if (!ok455) return;
                    if (v_c98 != v_c107) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c104, v_c22}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:169", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask423* _cont = new ReadTask423(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask423(db,b), false);
  // (crule (pre (let __tconst9B7m280 const6b86b273ff34fce19d6b804e)) (scan $sup9688x88x0x0x0 __t3OU0279 k l m p r) (body (exists st_del (0 2 1) 2 __t3OU0279 k) (exists st_bld (2 1 4 0 3) 3 m p r) (exists st_msk (1 2 0) 2 k m) (exists st_msk_ans (1 0) 1 p) (exists st_del (1 2 0) 2 l k) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t2u9k278) (join-old st_del (0 2 1) 3 (0 2 1) __t3OU0279 k __t2u9k278) (join-old st_bld (2 1 4 0 3) 3 (2 1 4 0 3) m p r __t6UON282 __v0) (exists st_del_ans (1 0) 1 __v0) (exists st_bld_ans (0 1) 1 __t6UON282) (join-old st_msk (1 2 0) 2 (1 2 0) k m __t5pdy283) (join st_msk_ans (0 1) 2 __t5pdy283 p) (join-old st_del (1 2 0) 2 (1 2 0) l k __t62j9284) (join st_del_ans (0 1) 2 __t62j9284 __v0) (join st_bld_ans (0 1) 1 __t6UON282 res) (let __t4Xlx281 (band k m)) (cmp lt __t4Xlx281 __tconst9B7m280)) (head (emit st_del_ans (0 1) __t3OU0279 res)) set.slog:89 #f)
  class ReadTask476 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_delindex456;  slog::Index** st_bldindex457;  slog::Index** st_mskindex458;  slog::Index** st_msk_ansindex459;  slog::Index** st_delindex460;  slog::Index** pbranchindex461;  slog::Index** st_delindex462;  slog::Index** st_bldindex463;  slog::Index** st_del_ansindex464;  slog::Index** st_bld_ansindex465;  slog::Index** st_mskindex466;  slog::Index** st_msk_ansindex467;  slog::Index** st_delindex468;  slog::Index** st_del_ansindex469;  slog::Index** st_bld_ansindex470;  slog::Index** pbranchdelta471;  slog::Index** st_deldelta472;  slog::Index** st_blddelta473;  slog::Index** st_mskdelta474;  slog::Index** st_deldelta475;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_del_ans");
      std::vector<u16> ord477({0, 1});
      slog::Relation* readrel478 = db->getRelation("st_del_ans");
      head_index[0] = readrel478->getIndex(ord477, false);
      outer_rel = db->getRelation("$sup9688x88x0x0x0");
      std::vector<u16> ord479({0, 2, 1});
      slog::Relation* readrel480 = db->getRelation("st_del");
      st_delindex456 = readrel480->getIndex(ord479, false);
      std::vector<u16> ord481({2, 1, 4, 0, 3});
      slog::Relation* readrel482 = db->getRelation("st_bld");
      st_bldindex457 = readrel482->getIndex(ord481, false);
      std::vector<u16> ord483({1, 2, 0});
      slog::Relation* readrel484 = db->getRelation("st_msk");
      st_mskindex458 = readrel484->getIndex(ord483, false);
      std::vector<u16> ord485({1, 0});
      slog::Relation* readrel486 = db->getRelation("st_msk_ans");
      st_msk_ansindex459 = readrel486->getIndex(ord485, false);
      std::vector<u16> ord487({1, 2, 0});
      slog::Relation* readrel488 = db->getRelation("st_del");
      st_delindex460 = readrel488->getIndex(ord487, false);
      std::vector<u16> ord489({1, 2, 3, 4, 0});
      slog::Relation* readrel490 = db->getRelation("pbranch");
      pbranchindex461 = readrel490->getIndex(ord489, false);
      std::vector<u16> ord491({1, 2, 3, 4, 0});
      slog::Relation* readrel492 = db->getRelation("pbranch");
      pbranchdelta471 = readrel492->getIndex(ord491, true);
      std::vector<u16> ord493({0, 2, 1});
      slog::Relation* readrel494 = db->getRelation("st_del");
      st_delindex462 = readrel494->getIndex(ord493, false);
      std::vector<u16> ord495({0, 2, 1});
      slog::Relation* readrel496 = db->getRelation("st_del");
      st_deldelta472 = readrel496->getIndex(ord495, true);
      std::vector<u16> ord497({2, 1, 4, 0, 3});
      slog::Relation* readrel498 = db->getRelation("st_bld");
      st_bldindex463 = readrel498->getIndex(ord497, false);
      std::vector<u16> ord499({2, 1, 4, 0, 3});
      slog::Relation* readrel500 = db->getRelation("st_bld");
      st_blddelta473 = readrel500->getIndex(ord499, true);
      std::vector<u16> ord501({1, 0});
      slog::Relation* readrel502 = db->getRelation("st_del_ans");
      st_del_ansindex464 = readrel502->getIndex(ord501, false);
      std::vector<u16> ord503({0, 1});
      slog::Relation* readrel504 = db->getRelation("st_bld_ans");
      st_bld_ansindex465 = readrel504->getIndex(ord503, false);
      std::vector<u16> ord505({1, 2, 0});
      slog::Relation* readrel506 = db->getRelation("st_msk");
      st_mskindex466 = readrel506->getIndex(ord505, false);
      std::vector<u16> ord507({1, 2, 0});
      slog::Relation* readrel508 = db->getRelation("st_msk");
      st_mskdelta474 = readrel508->getIndex(ord507, true);
      std::vector<u16> ord509({0, 1});
      slog::Relation* readrel510 = db->getRelation("st_msk_ans");
      st_msk_ansindex467 = readrel510->getIndex(ord509, false);
      std::vector<u16> ord511({1, 2, 0});
      slog::Relation* readrel512 = db->getRelation("st_del");
      st_delindex468 = readrel512->getIndex(ord511, false);
      std::vector<u16> ord513({1, 2, 0});
      slog::Relation* readrel514 = db->getRelation("st_del");
      st_deldelta475 = readrel514->getIndex(ord513, true);
      std::vector<u16> ord515({0, 1});
      slog::Relation* readrel516 = db->getRelation("st_del_ans");
      st_del_ansindex469 = readrel516->getIndex(ord515, false);
      std::vector<u16> ord517({0, 1});
      slog::Relation* readrel518 = db->getRelation("st_bld_ans");
      st_bld_ansindex470 = readrel518->getIndex(ord517, false);
  
    }
    ReadTask476(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c2 = _t[2];
        u64 v_c6 = _t[3];
        u64 v_c7 = _t[4];
        u64 v_c8 = _t[5];
        if (!slog::exists_probe<3,2>(st_delindex456, std::array<u64,3>{v_c5, v_c3, 0})) return;
        if (!slog::exists_probe<5,3>(st_bldindex457, std::array<u64,5>{v_c6, v_c7, v_c8, 0, 0})) return;
        if (!slog::exists_probe<3,2>(st_mskindex458, std::array<u64,3>{v_c3, v_c6, 0})) return;
        if (!slog::exists_probe<2,1>(st_msk_ansindex459, std::array<u64,2>{v_c7, 0})) return;
        if (!slog::exists_probe<3,2>(st_delindex460, std::array<u64,3>{v_c2, v_c3, 0})) return;
        slog::join_probe_old<5,4>(pbranchindex461, pbranchdelta471, std::array<u64,5>{v_c7, v_c6, v_c2, v_c8, 0}, [&](const std::array<u64,5>& m519) {
          u64 v_c9 = m519[4];
          slog::join_probe_old<3,3>(st_delindex462, st_deldelta472, std::array<u64,3>{v_c5, v_c3, v_c9}, [&](const std::array<u64,3>& m520) {
            slog::join_probe_old<5,3>(st_bldindex463, st_blddelta473, std::array<u64,5>{v_c6, v_c7, v_c8, 0, 0}, [&](const std::array<u64,5>& m521) {
              u64 v_c10 = m521[3]; u64 v_c4 = m521[4];
              if (!slog::exists_probe<2,1>(st_del_ansindex464, std::array<u64,2>{v_c4, 0})) return;
              if (!slog::exists_probe<2,1>(st_bld_ansindex465, std::array<u64,2>{v_c10, 0})) return;
              slog::join_probe_old<3,2>(st_mskindex466, st_mskdelta474, std::array<u64,3>{v_c3, v_c6, 0}, [&](const std::array<u64,3>& m522) {
                u64 v_c11 = m522[2];
                slog::join_probe<2,2>(st_msk_ansindex467, std::array<u64,2>{v_c11, v_c7}, [&](const std::array<u64,2>& m523) {
                  slog::join_probe_old<3,2>(st_delindex468, st_deldelta475, std::array<u64,3>{v_c2, v_c3, 0}, [&](const std::array<u64,3>& m524) {
                    u64 v_c1 = m524[2];
                    slog::join_probe<2,2>(st_del_ansindex469, std::array<u64,2>{v_c1, v_c4}, [&](const std::array<u64,2>& m525) {
                      slog::join_probe<2,1>(st_bld_ansindex470, std::array<u64,2>{v_c10, 0}, [&](const std::array<u64,2>& m526) {
                        u64 v_c12 = m526[1];
                        u64 v_c13 = _prim_band(db, v_c3, v_c6);
                        if (v_c13 == slog_error) { slog::emit_pending_error(db, "set.slog:89"); return; }
                        u64 v_c108 = _prim_lt(db, v_c13, v_c0);
                        if (v_c108 == slog_error) { slog::emit_pending_error(db, "set.slog:89"); return; }
                        if (!v_c108) return;
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c5, v_c12}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("set.slog:89", "delta:$sup9688x88x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask476* _cont = new ReadTask476(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask476(db,b), false);
  // (crule (pre) (scan pbranch __t0w8p146 q n u v) (body (exists st_diff (2 0 1) 1 __t0w8p146) (exists st_msk (1 2 0) 1 q) (join $sup9688x145x0x0x0 (3 5 7 8 0 1 2 4 6) 4 n q u v __t3Vft148 l m p r) (cmp lt n m) (exists st_diff (2 0 1) 2 __t0w8p146 __t3Vft148) (exists st_msk (1 2 0) 2 q m) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t8pVe147) (join-old st_diff (0 1 2) 3 (0 1 2) __t3Vft148 __t8pVe147 __t0w8p146) (join-old st_msk (1 2 0) 2 (1 2 0) q m __t7gQz149) (join st_msk_ans (0 1) 1 __t7gQz149 __v0) (neq p __v0)) (head (emit st_diff_ans (0 1) __t3Vft148 __t8pVe147)) set.slog:146 #f)
  class ReadTask540 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_diffindex528;  slog::Index** st_mskindex529;  slog::Index** $sup9688x145x0x0x0index530;  slog::Index** st_diffindex531;  slog::Index** st_mskindex532;  slog::Index** pbranchindex533;  slog::Index** st_diffindex534;  slog::Index** st_mskindex535;  slog::Index** st_msk_ansindex536;  slog::Index** pbranchdelta537;  slog::Index** st_diffdelta538;  slog::Index** st_mskdelta539;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord541({0, 1});
      slog::Relation* readrel542 = db->getRelation("st_diff_ans");
      head_index[0] = readrel542->getIndex(ord541, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord543({2, 0, 1});
      slog::Relation* readrel544 = db->getRelation("st_diff");
      st_diffindex528 = readrel544->getIndex(ord543, false);
      std::vector<u16> ord545({1, 2, 0});
      slog::Relation* readrel546 = db->getRelation("st_msk");
      st_mskindex529 = readrel546->getIndex(ord545, false);
      std::vector<u16> ord547({3, 5, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel548 = db->getRelation("$sup9688x145x0x0x0");
      $sup9688x145x0x0x0index530 = readrel548->getIndex(ord547, false);
      std::vector<u16> ord549({2, 0, 1});
      slog::Relation* readrel550 = db->getRelation("st_diff");
      st_diffindex531 = readrel550->getIndex(ord549, false);
      std::vector<u16> ord551({1, 2, 0});
      slog::Relation* readrel552 = db->getRelation("st_msk");
      st_mskindex532 = readrel552->getIndex(ord551, false);
      std::vector<u16> ord553({1, 2, 3, 4, 0});
      slog::Relation* readrel554 = db->getRelation("pbranch");
      pbranchindex533 = readrel554->getIndex(ord553, false);
      std::vector<u16> ord555({1, 2, 3, 4, 0});
      slog::Relation* readrel556 = db->getRelation("pbranch");
      pbranchdelta537 = readrel556->getIndex(ord555, true);
      std::vector<u16> ord557({0, 1, 2});
      slog::Relation* readrel558 = db->getRelation("st_diff");
      st_diffindex534 = readrel558->getIndex(ord557, false);
      std::vector<u16> ord559({0, 1, 2});
      slog::Relation* readrel560 = db->getRelation("st_diff");
      st_diffdelta538 = readrel560->getIndex(ord559, true);
      std::vector<u16> ord561({1, 2, 0});
      slog::Relation* readrel562 = db->getRelation("st_msk");
      st_mskindex535 = readrel562->getIndex(ord561, false);
      std::vector<u16> ord563({1, 2, 0});
      slog::Relation* readrel564 = db->getRelation("st_msk");
      st_mskdelta539 = readrel564->getIndex(ord563, true);
      std::vector<u16> ord565({0, 1});
      slog::Relation* readrel566 = db->getRelation("st_msk_ans");
      st_msk_ansindex536 = readrel566->getIndex(ord565, false);
  
    }
    ReadTask540(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c46 = _t[1];
        u64 v_c45 = _t[2];
        u64 v_c47 = _t[3];
        u64 v_c48 = _t[4];
        if (!slog::exists_probe<3,1>(st_diffindex528, std::array<u64,3>{v_c109, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mskindex529, std::array<u64,3>{v_c46, 0, 0})) return;
        slog::join_probe<9,4>($sup9688x145x0x0x0index530, std::array<u64,9>{v_c45, v_c46, v_c47, v_c48, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m567) {
          u64 v_c110 = m567[4]; u64 v_c2 = m567[5]; u64 v_c6 = m567[6]; u64 v_c7 = m567[7]; u64 v_c8 = m567[8];
          u64 v_c111 = _prim_lt(db, v_c45, v_c6);
          if (v_c111 == slog_error) { slog::emit_pending_error(db, "set.slog:146"); return; }
          if (!v_c111) return;
          if (!slog::exists_probe<3,2>(st_diffindex531, std::array<u64,3>{v_c109, v_c110, 0})) return;
          if (!slog::exists_probe<3,2>(st_mskindex532, std::array<u64,3>{v_c46, v_c6, 0})) return;
          slog::join_probe_old<5,4>(pbranchindex533, pbranchdelta537, std::array<u64,5>{v_c7, v_c6, v_c2, v_c8, 0}, [&](const std::array<u64,5>& m569) {
            u64 v_c112 = m569[4];
            slog::join_probe_old<3,3>(st_diffindex534, st_diffdelta538, std::array<u64,3>{v_c110, v_c112, v_c109}, [&](const std::array<u64,3>& m570) {
              slog::join_probe_old<3,2>(st_mskindex535, st_mskdelta539, std::array<u64,3>{v_c46, v_c6, 0}, [&](const std::array<u64,3>& m571) {
                u64 v_c113 = m571[2];
                slog::join_probe<2,1>(st_msk_ansindex536, std::array<u64,2>{v_c113, 0}, [&](const std::array<u64,2>& m572) {
                  u64 v_c4 = m572[1];
                  if (v_c7 == v_c4) return;
                  ++_fires;
                  slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c110, v_c112}, std::array<u16,2>{0, 1});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:146", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask540* _cont = new ReadTask540(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask540(db,b), false);
  // (crule (pre (let _00024sqc5Ylt593 const4b227777d4dd1fc61c6f884f) (let _00024sqc75sY594 const5feceb66ffc86f38d952786c) (let _00024sqc7SC7595 constef2d127de37b942baad06145) (let _00024sqc9xIA596 const6b86b273ff34fce19d6b804e) (let _00024sqc1Dz5597 constd4735e3a265e16eee03f5971) (let _00024sqc3IO1598 constd4735e3a265e16eee03f5971) (let _00024sqc8gB7599 const2c624232cdd221771294dfbb) (let _00024sqc5ClH600 const4e07408562bedb8b60ce05c1) (let _00024sqc3osW601 const6b86b273ff34fce19d6b804e) (let _00024sqo1fme603 constef2d127de37b942baad06145) (let _00024sqo8SDr602 const5feceb66ffc86f38d952786c) (let _00024sqo8V65605 constd4735e3a265e16eee03f5971) (let _00024sqo8H0j604 const6b86b273ff34fce19d6b804e) (let _00024sqo58Kv607 const2c624232cdd221771294dfbb) (let _00024sqo9fPL606 constd4735e3a265e16eee03f5971) (let _00024sqo8Byv609 const6b86b273ff34fce19d6b804e) (let _00024sqo6mXs608 const4e07408562bedb8b60ce05c1) (let _00024sqo1LyP611 constef2d127de37b942baad06145) (let _00024sqo7das610 const4e07408562bedb8b60ce05c1) (let _00024sqo8vL7613 constd4735e3a265e16eee03f5971) (let _00024sqo5GBE612 constd4735e3a265e16eee03f5971) (let _00024sqo1K4x615 const2c624232cdd221771294dfbb) (let _00024sqo0Oce614 const6b86b273ff34fce19d6b804e) (let _00024sqo9RJN617 const6b86b273ff34fce19d6b804e) (let _00024sqo9a1a616 const5feceb66ffc86f38d952786c)) (probe $seq_atr (0 1 2) 2 _00024sqo8vL7613 _00024sqo5GBE612 _00024seq0) (body (join $seq_at (1 0 2) 3 _00024sqo8SDr602 _00024sqo1fme603 _00024seq0) (join $seq_at (1 0 2) 3 _00024sqo8H0j604 _00024sqo8V65605 _00024seq0) (join $seq_at (1 0 2) 3 _00024sqo9fPL606 _00024sqo58Kv607 _00024seq0) (join $seq_at (1 0 2) 3 _00024sqo6mXs608 _00024sqo8Byv609 _00024seq0) (join $seq_atr (0 1 2) 3 _00024sqo1LyP611 _00024sqo7das610 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo1K4x615 _00024sqo0Oce614 _00024seq0) (join-old $seq_atr (0 1 2) 3 (0 1 2) _00024sqo9RJN617 _00024sqo9a1a616 _00024seq0) (join st_fromlist (1 0) 1 _00024seq0 __t14PV427) (join st_fromlist_ans (0 1) 1 __t14PV427 r) (letp _00024sql0i4I591 (aslst _00024seq0)) (let chk2X1S1317 (llen _00024sql0i4I591)) (eq _00024sqc5Ylt593 chk2X1S1317) (letp chk5tmf1318 (lref _00024sql0i4I591 _00024sqc75sY594)) (eq _00024sqc7SC7595 chk5tmf1318) (letp chk1Ffx1319 (lref _00024sql0i4I591 _00024sqc9xIA596)) (eq _00024sqc1Dz5597 chk1Ffx1319) (letp chk5agX1320 (lref _00024sql0i4I591 _00024sqc3IO1598)) (eq _00024sqc8gB7599 chk5agX1320) (letp chk4NKk1321 (lref _00024sql0i4I591 _00024sqc5ClH600)) (eq _00024sqc3osW601 chk4NKk1321)) (head (emit canon (0) r)) st_basic.slog:16 #f)
  class ReadTask584 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex573;  slog::Index** $seq_atindex574;  slog::Index** $seq_atindex575;  slog::Index** $seq_atindex576;  slog::Index** $seq_atrindex577;  slog::Index** $seq_atrindex578;  slog::Index** $seq_atrindex579;  slog::Index** st_fromlistindex580;  slog::Index** st_fromlist_ansindex581;  slog::Index** $seq_atrdelta582;  slog::Index** $seq_atrdelta583;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("canon");
      std::vector<u16> ord585({0});
      slog::Relation* readrel586 = db->getRelation("canon");
      head_index[0] = readrel586->getIndex(ord585, false);
      std::vector<u16> ord587({0, 1, 2});
      slog::Relation* readrel588 = db->getRelation("$seq_atr");
      driver_index = readrel588->getIndex(ord587, true);
      std::vector<u16> ord589({1, 0, 2});
      slog::Relation* readrel590 = db->getRelation("$seq_at");
      $seq_atindex573 = readrel590->getIndex(ord589, false);
      std::vector<u16> ord591({1, 0, 2});
      slog::Relation* readrel592 = db->getRelation("$seq_at");
      $seq_atindex574 = readrel592->getIndex(ord591, false);
      std::vector<u16> ord593({1, 0, 2});
      slog::Relation* readrel594 = db->getRelation("$seq_at");
      $seq_atindex575 = readrel594->getIndex(ord593, false);
      std::vector<u16> ord595({1, 0, 2});
      slog::Relation* readrel596 = db->getRelation("$seq_at");
      $seq_atindex576 = readrel596->getIndex(ord595, false);
      std::vector<u16> ord597({0, 1, 2});
      slog::Relation* readrel598 = db->getRelation("$seq_atr");
      $seq_atrindex577 = readrel598->getIndex(ord597, false);
      std::vector<u16> ord599({0, 1, 2});
      slog::Relation* readrel600 = db->getRelation("$seq_atr");
      $seq_atrindex578 = readrel600->getIndex(ord599, false);
      std::vector<u16> ord601({0, 1, 2});
      slog::Relation* readrel602 = db->getRelation("$seq_atr");
      $seq_atrdelta582 = readrel602->getIndex(ord601, true);
      std::vector<u16> ord603({0, 1, 2});
      slog::Relation* readrel604 = db->getRelation("$seq_atr");
      $seq_atrindex579 = readrel604->getIndex(ord603, false);
      std::vector<u16> ord605({0, 1, 2});
      slog::Relation* readrel606 = db->getRelation("$seq_atr");
      $seq_atrdelta583 = readrel606->getIndex(ord605, true);
      std::vector<u16> ord607({1, 0});
      slog::Relation* readrel608 = db->getRelation("st_fromlist");
      st_fromlistindex580 = readrel608->getIndex(ord607, false);
      std::vector<u16> ord609({0, 1});
      slog::Relation* readrel610 = db->getRelation("st_fromlist_ans");
      st_fromlist_ansindex581 = readrel610->getIndex(ord609, false);
  
    }
    ReadTask584(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c114 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c115 = v_const5feceb66ffc86f38d952786c;
      u64 v_c116 = v_constef2d127de37b942baad06145;
      u64 v_c117 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c118 = v_constd4735e3a265e16eee03f5971;
      u64 v_c119 = v_constd4735e3a265e16eee03f5971;
      u64 v_c120 = v_const2c624232cdd221771294dfbb;
      u64 v_c121 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c122 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c123 = v_constef2d127de37b942baad06145;
      u64 v_c124 = v_const5feceb66ffc86f38d952786c;
      u64 v_c125 = v_constd4735e3a265e16eee03f5971;
      u64 v_c126 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c127 = v_const2c624232cdd221771294dfbb;
      u64 v_c128 = v_constd4735e3a265e16eee03f5971;
      u64 v_c129 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c130 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c131 = v_constef2d127de37b942baad06145;
      u64 v_c132 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c133 = v_constd4735e3a265e16eee03f5971;
      u64 v_c134 = v_constd4735e3a265e16eee03f5971;
      u64 v_c135 = v_const2c624232cdd221771294dfbb;
      u64 v_c136 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c137 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c138 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c133, v_c134, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m611) {
        u64 v_c74 = m611[2];
        if (buckethash(v_c74) != bucket) return;
        slog::join_probe<3,3>($seq_atindex573, std::array<u64,3>{v_c124, v_c123, v_c74}, [&](const std::array<u64,3>& m612) {
          slog::join_probe<3,3>($seq_atindex574, std::array<u64,3>{v_c126, v_c125, v_c74}, [&](const std::array<u64,3>& m613) {
            slog::join_probe<3,3>($seq_atindex575, std::array<u64,3>{v_c128, v_c127, v_c74}, [&](const std::array<u64,3>& m614) {
              slog::join_probe<3,3>($seq_atindex576, std::array<u64,3>{v_c130, v_c129, v_c74}, [&](const std::array<u64,3>& m615) {
                slog::join_probe<3,3>($seq_atrindex577, std::array<u64,3>{v_c131, v_c132, v_c74}, [&](const std::array<u64,3>& m616) {
                  slog::join_probe_old<3,3>($seq_atrindex578, $seq_atrdelta582, std::array<u64,3>{v_c135, v_c136, v_c74}, [&](const std::array<u64,3>& m617) {
                    slog::join_probe_old<3,3>($seq_atrindex579, $seq_atrdelta583, std::array<u64,3>{v_c137, v_c138, v_c74}, [&](const std::array<u64,3>& m618) {
                      slog::join_probe<2,1>(st_fromlistindex580, std::array<u64,2>{v_c74, 0}, [&](const std::array<u64,2>& m619) {
                        u64 v_c139 = m619[1];
                        slog::join_probe<2,1>(st_fromlist_ansindex581, std::array<u64,2>{v_c139, 0}, [&](const std::array<u64,2>& m620) {
                          u64 v_c8 = m620[1];
                          bool ok621 = true;
                          u64 v_c140 = _prim_aslst(db, v_c74, &ok621);
                          if (!ok621) return;
                          u64 v_c141 = _prim_llen(db, v_c140);
                          if (v_c141 == slog_error) { slog::emit_pending_error(db, "st_basic.slog:16"); return; }
                          if (v_c114 != v_c141) return;
                          bool ok622 = true;
                          u64 v_c142 = _prim_lref(db, v_c140, v_c115, &ok622);
                          if (!ok622) return;
                          if (v_c116 != v_c142) return;
                          bool ok623 = true;
                          u64 v_c143 = _prim_lref(db, v_c140, v_c117, &ok623);
                          if (!ok623) return;
                          if (v_c118 != v_c143) return;
                          bool ok624 = true;
                          u64 v_c144 = _prim_lref(db, v_c140, v_c119, &ok624);
                          if (!ok624) return;
                          if (v_c120 != v_c144) return;
                          bool ok625 = true;
                          u64 v_c145 = _prim_lref(db, v_c140, v_c121, &ok625);
                          if (!ok625) return;
                          if (v_c122 != v_c145) return;
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
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("st_basic.slog:16", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask584* _cont = new ReadTask584(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask584(db,b), false);
  // (crule (pre (let __trid5e7d916 constf2664e0abda1016213c9fa90) (let __trel5vWf917 const1d9eff40314d54862fee3942) (let __tcol5reU918 const5feceb66ffc86f38d952786c) (let __trel8Aed919 const1d9eff40314d54862fee3942) (let __tcol7zoD920 const6b86b273ff34fce19d6b804e)) (scan $sup9688x136x0x0x0 __d0 l m p r u v) (body) (head (tycheck r (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid5e7d916 __trel5vWf917 __tcol5reU918 (1 2 3 4 0)) (tycheck v (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid5e7d916 __trel8Aed919 __tcol7zoD920 (1 2 3 4 0)) (mkstruct st_diff (1 2 0) __2JPl915 r v)) set.slog:137 #f)
  class ReadTask629 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid627;  u32 sid626;  u32 sid628;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("st_diff");
      outer_rel = db->getRelation("$sup9688x136x0x0x0");
      sid627 = db->getRelation("_enum")->getStructId();
      sid626 = db->getRelation("pbranch")->getStructId();
      sid628 = db->getRelation("pleaf")->getStructId();
  
    }
    ReadTask629(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c146 = v_constf2664e0abda1016213c9fa90;
      u64 v_c147 = v_const1d9eff40314d54862fee3942;
      u64 v_c148 = v_const5feceb66ffc86f38d952786c;
      u64 v_c149 = v_const1d9eff40314d54862fee3942;
      u64 v_c150 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c44 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c7 = _t[3];
        u64 v_c8 = _t[4];
        u64 v_c47 = _t[5];
        u64 v_c48 = _t[6];
        ++_fires;
        if (!((is_struct(v_c8) && (decode_struct_id(v_c8) == sid626 || decode_struct_id(v_c8) == sid627 || decode_struct_id(v_c8) == sid628))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c146, v_c147, v_c148, v_c8}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c48) && (decode_struct_id(v_c48) == sid626 || decode_struct_id(v_c48) == sid627 || decode_struct_id(v_c48) == sid628))))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c146, v_c149, v_c150, v_c48}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c8, v_c48}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("set.slog:137", "delta:$sup9688x136x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask629* _cont = new ReadTask629(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask629(db,b), false);
  // (crule (pre) (scan temp7aSv1347 __t9i2T156) (body) (head (mkstruct st_hsb (1 0) __6Jtv718 __t9i2T156)) set.slog:37 #f)
  class ReadTask630 : public slog::Task
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
      outer_rel = db->getRelation("temp7aSv1347");
  
    }
    ReadTask630(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c151 = _t[0];
        ++_fires;
        slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c151}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:37", "delta:temp7aSv1347", _fires);
  
      if (!_done)
      {
        ReadTask630* _cont = new ReadTask630(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask630(db,b), false);
  // (crule (pre (let __tconst4buc465 const5feceb66ffc86f38d952786c)) (scan st_msk __t0rt9471 p0 __v1) (body (exists st_hsb_ans (1 0) 1 __v1) (exists $sup9688x40x0x0x2 (5 7 1 0 2 3 4 6 8 9 10) 2 __v1 p0) (exists $sup9688x40x0x0x1 (3 1 0 2 4 5 6) 1 p0) (exists $sup9688x40x0x0x0 (1 0 2 3 4) 1 p0) (exists st_join (1 2 3 4 0) 1 p0) (join st_msk_ans (0 1) 1 __t0rt9471 __v2) (join st_hsb_ans (1 0) 1 __v1 __t2flT468) (exists $sup9688x40x0x0x2 (5 7 1 0 2 3 4 6 8 9 10) 3 __v1 p0 __t2flT468) (exists $sup9688x40x0x0x1 (3 1 0 2 4 5 6) 2 p0 __t2flT468) (exists st_hsb_ans (0 1) 1 __t2flT468) (join st_hsb_ans (0 1) 1 __t2flT468 __v3) (join $sup9688x40x0x0x2 (1 5 6 7 0 2 3 4 8 9 10) 4 __t2flT468 __v1 __v3 p0 __t4PzE464 dup2gd61405 dup5ZAM1406 __v0 p1 t0 t1) (eq __t2flT468 dup5ZAM1406) (eq __t2flT468 dup2gd61405) (join $sup9688x40x0x0x1 (0 3 4 5 6 1 2) 7 __t4PzE464 p0 p1 t0 t1 __t2flT468 __v0) (join $sup9688x40x0x0x0 (1 0 2 3 4) 5 p0 __t4PzE464 p1 t0 t1) (join-old st_join (1 2 3 4 0) 5 (1 2 3 4 0) p0 t0 p1 t1 __t4PzE464) (join st_hsb_ans (0 1) 2 __t2flT468 __v0) (let __t2awV472 (bxor p0 p1)) (join-old st_hsb (0 1) 2 (0 1) __t2flT468 __t2awV472) (let __t7pIU466 (band p0 __v0)) (cmp gt __t7pIU466 __tconst4buc465)) (head (emit-temp temp5blj1404 __t4PzE464 __v2 __v3 t0 t1) (mkstruct pbranch (1 2 3 4 0) __t1bKH463 __v2 __v3 t1 t0)) set.slog:41 #f)
  class ReadTask650 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_hsb_ansindex631;  slog::Index** $sup9688x40x0x0x2index632;  slog::Index** $sup9688x40x0x0x1index633;  slog::Index** $sup9688x40x0x0x0index634;  slog::Index** st_joinindex635;  slog::Index** st_msk_ansindex636;  slog::Index** st_hsb_ansindex637;  slog::Index** $sup9688x40x0x0x2index638;  slog::Index** $sup9688x40x0x0x1index639;  slog::Index** st_hsb_ansindex640;  slog::Index** st_hsb_ansindex641;  slog::Index** $sup9688x40x0x0x2index642;  slog::Index** $sup9688x40x0x0x1index643;  slog::Index** $sup9688x40x0x0x0index644;  slog::Index** st_joinindex645;  slog::Index** st_hsb_ansindex646;  slog::Index** st_hsbindex647;  slog::Index** st_joindelta648;  slog::Index** st_hsbdelta649;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5blj1404");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("st_msk");
      std::vector<u16> ord651({1, 0});
      slog::Relation* readrel652 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex631 = readrel652->getIndex(ord651, false);
      std::vector<u16> ord653({5, 7, 1, 0, 2, 3, 4, 6, 8, 9, 10});
      slog::Relation* readrel654 = db->getRelation("$sup9688x40x0x0x2");
      $sup9688x40x0x0x2index632 = readrel654->getIndex(ord653, false);
      std::vector<u16> ord655({3, 1, 0, 2, 4, 5, 6});
      slog::Relation* readrel656 = db->getRelation("$sup9688x40x0x0x1");
      $sup9688x40x0x0x1index633 = readrel656->getIndex(ord655, false);
      std::vector<u16> ord657({1, 0, 2, 3, 4});
      slog::Relation* readrel658 = db->getRelation("$sup9688x40x0x0x0");
      $sup9688x40x0x0x0index634 = readrel658->getIndex(ord657, false);
      std::vector<u16> ord659({1, 2, 3, 4, 0});
      slog::Relation* readrel660 = db->getRelation("st_join");
      st_joinindex635 = readrel660->getIndex(ord659, false);
      std::vector<u16> ord661({0, 1});
      slog::Relation* readrel662 = db->getRelation("st_msk_ans");
      st_msk_ansindex636 = readrel662->getIndex(ord661, false);
      std::vector<u16> ord663({1, 0});
      slog::Relation* readrel664 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex637 = readrel664->getIndex(ord663, false);
      std::vector<u16> ord665({5, 7, 1, 0, 2, 3, 4, 6, 8, 9, 10});
      slog::Relation* readrel666 = db->getRelation("$sup9688x40x0x0x2");
      $sup9688x40x0x0x2index638 = readrel666->getIndex(ord665, false);
      std::vector<u16> ord667({3, 1, 0, 2, 4, 5, 6});
      slog::Relation* readrel668 = db->getRelation("$sup9688x40x0x0x1");
      $sup9688x40x0x0x1index639 = readrel668->getIndex(ord667, false);
      std::vector<u16> ord669({0, 1});
      slog::Relation* readrel670 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex640 = readrel670->getIndex(ord669, false);
      std::vector<u16> ord671({0, 1});
      slog::Relation* readrel672 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex641 = readrel672->getIndex(ord671, false);
      std::vector<u16> ord673({1, 5, 6, 7, 0, 2, 3, 4, 8, 9, 10});
      slog::Relation* readrel674 = db->getRelation("$sup9688x40x0x0x2");
      $sup9688x40x0x0x2index642 = readrel674->getIndex(ord673, false);
      std::vector<u16> ord675({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel676 = db->getRelation("$sup9688x40x0x0x1");
      $sup9688x40x0x0x1index643 = readrel676->getIndex(ord675, false);
      std::vector<u16> ord677({1, 0, 2, 3, 4});
      slog::Relation* readrel678 = db->getRelation("$sup9688x40x0x0x0");
      $sup9688x40x0x0x0index644 = readrel678->getIndex(ord677, false);
      std::vector<u16> ord679({1, 2, 3, 4, 0});
      slog::Relation* readrel680 = db->getRelation("st_join");
      st_joinindex645 = readrel680->getIndex(ord679, false);
      std::vector<u16> ord681({1, 2, 3, 4, 0});
      slog::Relation* readrel682 = db->getRelation("st_join");
      st_joindelta648 = readrel682->getIndex(ord681, true);
      std::vector<u16> ord683({0, 1});
      slog::Relation* readrel684 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex646 = readrel684->getIndex(ord683, false);
      std::vector<u16> ord685({0, 1});
      slog::Relation* readrel686 = db->getRelation("st_hsb");
      st_hsbindex647 = readrel686->getIndex(ord685, false);
      std::vector<u16> ord687({0, 1});
      slog::Relation* readrel688 = db->getRelation("st_hsb");
      st_hsbdelta649 = readrel688->getIndex(ord687, true);
  
    }
    ReadTask650(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c152 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c153 = _t[0];
        u64 v_c88 = _t[1];
        u64 v_c22 = _t[2];
        if (!slog::exists_probe<2,1>(st_hsb_ansindex631, std::array<u64,2>{v_c22, 0})) return;
        if (!slog::exists_probe<11,2>($sup9688x40x0x0x2index632, std::array<u64,11>{v_c22, v_c88, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<7,1>($sup9688x40x0x0x1index633, std::array<u64,7>{v_c88, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>($sup9688x40x0x0x0index634, std::array<u64,5>{v_c88, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(st_joinindex635, std::array<u64,5>{v_c88, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(st_msk_ansindex636, std::array<u64,2>{v_c153, 0}, [&](const std::array<u64,2>& m689) {
          u64 v_c21 = m689[1];
          slog::join_probe<2,1>(st_hsb_ansindex637, std::array<u64,2>{v_c22, 0}, [&](const std::array<u64,2>& m690) {
            u64 v_c154 = m690[1];
            if (!slog::exists_probe<11,3>($sup9688x40x0x0x2index638, std::array<u64,11>{v_c22, v_c88, v_c154, 0, 0, 0, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<7,2>($sup9688x40x0x0x1index639, std::array<u64,7>{v_c88, v_c154, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<2,1>(st_hsb_ansindex640, std::array<u64,2>{v_c154, 0})) return;
            slog::join_probe<2,1>(st_hsb_ansindex641, std::array<u64,2>{v_c154, 0}, [&](const std::array<u64,2>& m691) {
              u64 v_c155 = m691[1];
              slog::join_probe<11,4>($sup9688x40x0x0x2index642, std::array<u64,11>{v_c154, v_c22, v_c155, v_c88, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m692) {
                u64 v_c156 = m692[4]; u64 v_c157 = m692[5]; u64 v_c158 = m692[6]; u64 v_c4 = m692[7]; u64 v_c89 = m692[8]; u64 v_c90 = m692[9]; u64 v_c91 = m692[10];
                if (v_c154 != v_c158) return;
                if (v_c154 != v_c157) return;
                slog::join_probe<7,7>($sup9688x40x0x0x1index643, std::array<u64,7>{v_c156, v_c88, v_c89, v_c90, v_c91, v_c154, v_c4}, [&](const std::array<u64,7>& m693) {
                  slog::join_probe<5,5>($sup9688x40x0x0x0index644, std::array<u64,5>{v_c88, v_c156, v_c89, v_c90, v_c91}, [&](const std::array<u64,5>& m694) {
                    slog::join_probe_old<5,5>(st_joinindex645, st_joindelta648, std::array<u64,5>{v_c88, v_c90, v_c89, v_c91, v_c156}, [&](const std::array<u64,5>& m695) {
                      slog::join_probe<2,2>(st_hsb_ansindex646, std::array<u64,2>{v_c154, v_c4}, [&](const std::array<u64,2>& m696) {
                        u64 v_c159 = _prim_bxor(db, v_c88, v_c89);
                        if (v_c159 == slog_error) { slog::emit_pending_error(db, "set.slog:41"); return; }
                        slog::join_probe_old<2,2>(st_hsbindex647, st_hsbdelta649, std::array<u64,2>{v_c154, v_c159}, [&](const std::array<u64,2>& m697) {
                          u64 v_c160 = _prim_band(db, v_c88, v_c4);
                          if (v_c160 == slog_error) { slog::emit_pending_error(db, "set.slog:41"); return; }
                          u64 v_c161 = _prim_gt(db, v_c160, v_c152);
                          if (v_c161 == slog_error) { slog::emit_pending_error(db, "set.slog:41"); return; }
                          if (!v_c161) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c156, v_c21, v_c155, v_c90, v_c91});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c21, v_c155, v_c91, v_c90}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:41", "delta:st_msk", _fires);
  
      if (!_done)
      {
        ReadTask650* _cont = new ReadTask650(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask650(db,b), false);
  // (crule (pre (let __tconst2in2504 const5feceb66ffc86f38d952786c)) (scan st_mem0 __t6Rw6503 __t1XtO502 k) (body (exists st_mem0 (2 0 1) 1 k) (exists st_msk (1 2 0) 1 k) (join $sup9688x72x0x0x0 (0 1 2 3 4 5) 2 __t6Rw6503 k l m p r) (join pbranch (1 2 3 4 0) 5 p m l r __t1XtO502) (exists st_msk (1 2 0) 2 k m) (exists st_msk_ans (1 0) 1 p) (join-old st_mem0 (1 2 0) 2 (1 2 0) r k __t9V8P506) (exists st_mem0_ans (0 1) 1 __t9V8P506) (join-old st_msk (1 2 0) 2 (1 2 0) k m __t4A7W507) (join st_msk_ans (0 1) 2 __t4A7W507 p) (join st_mem0_ans (0 1) 1 __t9V8P506 a) (let __t9tLi505 (band k m)) (cmp gt __t9tLi505 __tconst2in2504)) (head (emit st_mem0_ans (0 1) __t6Rw6503 a)) set.slog:73 #f)
  class ReadTask712 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_mem0index699;  slog::Index** st_mskindex700;  slog::Index** $sup9688x72x0x0x0index701;  slog::Index** pbranchindex702;  slog::Index** st_mskindex703;  slog::Index** st_msk_ansindex704;  slog::Index** st_mem0index705;  slog::Index** st_mem0_ansindex706;  slog::Index** st_mskindex707;  slog::Index** st_msk_ansindex708;  slog::Index** st_mem0_ansindex709;  slog::Index** st_mem0delta710;  slog::Index** st_mskdelta711;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_mem0_ans");
      std::vector<u16> ord713({0, 1});
      slog::Relation* readrel714 = db->getRelation("st_mem0_ans");
      head_index[0] = readrel714->getIndex(ord713, false);
      outer_rel = db->getRelation("st_mem0");
      std::vector<u16> ord715({2, 0, 1});
      slog::Relation* readrel716 = db->getRelation("st_mem0");
      st_mem0index699 = readrel716->getIndex(ord715, false);
      std::vector<u16> ord717({1, 2, 0});
      slog::Relation* readrel718 = db->getRelation("st_msk");
      st_mskindex700 = readrel718->getIndex(ord717, false);
      std::vector<u16> ord719({0, 1, 2, 3, 4, 5});
      slog::Relation* readrel720 = db->getRelation("$sup9688x72x0x0x0");
      $sup9688x72x0x0x0index701 = readrel720->getIndex(ord719, false);
      std::vector<u16> ord721({1, 2, 3, 4, 0});
      slog::Relation* readrel722 = db->getRelation("pbranch");
      pbranchindex702 = readrel722->getIndex(ord721, false);
      std::vector<u16> ord723({1, 2, 0});
      slog::Relation* readrel724 = db->getRelation("st_msk");
      st_mskindex703 = readrel724->getIndex(ord723, false);
      std::vector<u16> ord725({1, 0});
      slog::Relation* readrel726 = db->getRelation("st_msk_ans");
      st_msk_ansindex704 = readrel726->getIndex(ord725, false);
      std::vector<u16> ord727({1, 2, 0});
      slog::Relation* readrel728 = db->getRelation("st_mem0");
      st_mem0index705 = readrel728->getIndex(ord727, false);
      std::vector<u16> ord729({1, 2, 0});
      slog::Relation* readrel730 = db->getRelation("st_mem0");
      st_mem0delta710 = readrel730->getIndex(ord729, true);
      std::vector<u16> ord731({0, 1});
      slog::Relation* readrel732 = db->getRelation("st_mem0_ans");
      st_mem0_ansindex706 = readrel732->getIndex(ord731, false);
      std::vector<u16> ord733({1, 2, 0});
      slog::Relation* readrel734 = db->getRelation("st_msk");
      st_mskindex707 = readrel734->getIndex(ord733, false);
      std::vector<u16> ord735({1, 2, 0});
      slog::Relation* readrel736 = db->getRelation("st_msk");
      st_mskdelta711 = readrel736->getIndex(ord735, true);
      std::vector<u16> ord737({0, 1});
      slog::Relation* readrel738 = db->getRelation("st_msk_ans");
      st_msk_ansindex708 = readrel738->getIndex(ord737, false);
      std::vector<u16> ord739({0, 1});
      slog::Relation* readrel740 = db->getRelation("st_mem0_ans");
      st_mem0_ansindex709 = readrel740->getIndex(ord739, false);
  
    }
    ReadTask712(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c162 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c3 = _t[2];
        if (!slog::exists_probe<3,1>(st_mem0index699, std::array<u64,3>{v_c3, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mskindex700, std::array<u64,3>{v_c3, 0, 0})) return;
        slog::join_probe<6,2>($sup9688x72x0x0x0index701, std::array<u64,6>{v_c163, v_c3, 0, 0, 0, 0}, [&](const std::array<u64,6>& m741) {
          u64 v_c2 = m741[2]; u64 v_c6 = m741[3]; u64 v_c7 = m741[4]; u64 v_c8 = m741[5];
          slog::join_probe<5,5>(pbranchindex702, std::array<u64,5>{v_c7, v_c6, v_c2, v_c8, v_c164}, [&](const std::array<u64,5>& m742) {
            if (!slog::exists_probe<3,2>(st_mskindex703, std::array<u64,3>{v_c3, v_c6, 0})) return;
            if (!slog::exists_probe<2,1>(st_msk_ansindex704, std::array<u64,2>{v_c7, 0})) return;
            slog::join_probe_old<3,2>(st_mem0index705, st_mem0delta710, std::array<u64,3>{v_c8, v_c3, 0}, [&](const std::array<u64,3>& m743) {
              u64 v_c165 = m743[2];
              if (!slog::exists_probe<2,1>(st_mem0_ansindex706, std::array<u64,2>{v_c165, 0})) return;
              slog::join_probe_old<3,2>(st_mskindex707, st_mskdelta711, std::array<u64,3>{v_c3, v_c6, 0}, [&](const std::array<u64,3>& m744) {
                u64 v_c166 = m744[2];
                slog::join_probe<2,2>(st_msk_ansindex708, std::array<u64,2>{v_c166, v_c7}, [&](const std::array<u64,2>& m745) {
                  slog::join_probe<2,1>(st_mem0_ansindex709, std::array<u64,2>{v_c165, 0}, [&](const std::array<u64,2>& m746) {
                    u64 v_c167 = m746[1];
                    u64 v_c168 = _prim_band(db, v_c3, v_c6);
                    if (v_c168 == slog_error) { slog::emit_pending_error(db, "set.slog:73"); return; }
                    u64 v_c169 = _prim_gt(db, v_c168, v_c162);
                    if (v_c169 == slog_error) { slog::emit_pending_error(db, "set.slog:73"); return; }
                    if (!v_c169) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c163, v_c167}, std::array<u16,2>{0, 1});
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
  // (crule (pre (let __tconst6u6w168 constd4735e3a265e16eee03f5971) (let __trid3Iw3761 const5e6127cdd5ea2629462053c9) (let __trel3BQx762 const1d9eff40314d54862fee3942) (let __tcol9eoL763 const5feceb66ffc86f38d952786c)) (scan st_ins_ans __t70EZ169 o) (body (join-old st_ins (0 2 1) 2 (0 2 1) __t70EZ169 __tconst6u6w168 __v0) (join $sup97714x23x0x0x1 (1 0 2) 1 __v0 __d0 s)) (head (tycheck s (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid3Iw3761 __trel3BQx762 __tcol9eoL763 (1 2 3 4 0)) (mkstruct st_diff (1 2 0) __1G6J760 s o)) st_basic.slog:24 #f)
  class ReadTask754 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_insindex748;  slog::Index** $sup97714x23x0x0x1index749;  slog::Index** st_insdelta750;
    u32 sid752;  u32 sid751;  u32 sid753;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("st_diff");
      outer_rel = db->getRelation("st_ins_ans");
      std::vector<u16> ord755({0, 2, 1});
      slog::Relation* readrel756 = db->getRelation("st_ins");
      st_insindex748 = readrel756->getIndex(ord755, false);
      std::vector<u16> ord757({0, 2, 1});
      slog::Relation* readrel758 = db->getRelation("st_ins");
      st_insdelta750 = readrel758->getIndex(ord757, true);
      std::vector<u16> ord759({1, 0, 2});
      slog::Relation* readrel760 = db->getRelation("$sup97714x23x0x0x1");
      $sup97714x23x0x0x1index749 = readrel760->getIndex(ord759, false);
      sid752 = db->getRelation("_enum")->getStructId();
      sid751 = db->getRelation("pbranch")->getStructId();
      sid753 = db->getRelation("pleaf")->getStructId();
  
    }
    ReadTask754(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c170 = v_constd4735e3a265e16eee03f5971;
      u64 v_c171 = v_const5e6127cdd5ea2629462053c9;
      u64 v_c172 = v_const1d9eff40314d54862fee3942;
      u64 v_c173 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c174 = _t[0];
        u64 v_c175 = _t[1];
        slog::join_probe_old<3,2>(st_insindex748, st_insdelta750, std::array<u64,3>{v_c174, v_c170, 0}, [&](const std::array<u64,3>& m761) {
          u64 v_c4 = m761[2];
          slog::join_probe<3,1>($sup97714x23x0x0x1index749, std::array<u64,3>{v_c4, 0, 0}, [&](const std::array<u64,3>& m762) {
            u64 v_c44 = m762[1]; u64 v_c176 = m762[2];
            ++_fires;
            if (!((is_struct(v_c176) && (decode_struct_id(v_c176) == sid751 || decode_struct_id(v_c176) == sid752 || decode_struct_id(v_c176) == sid753))))
            {
              slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c171, v_c172, v_c173, v_c176}, std::array<u16,5>{1, 2, 3, 4, 0});
              return;
            }
            slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c176, v_c175}, std::array<u16,3>{1, 2, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("st_basic.slog:24", "delta:st_ins_ans", _fires);
  
      if (!_done)
      {
        ReadTask754* _cont = new ReadTask754(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask754(db,b), false);
  // (crule (pre (let __tconst0v7T491 const5feceb66ffc86f38d952786c)) (scan st_del __t9BRr495 r k) (body (exists $sup9688x90x0x0x0 (1 5 0 2 3 4) 2 k r) (exists pbranch (4 0 1 2 3) 1 r) (exists st_del (2 0 1) 1 k) (exists st_msk (1 2 0) 1 k) (join st_del_ans (0 1) 1 __t9BRr495 __v0) (exists st_bld (4 0 1 2 3) 1 __v0) (join $sup9688x90x0x0x0 (1 5 0 2 3 4) 2 k r __t3j4h490 l m p) (exists st_bld (1 2 3 4 0) 4 p m l __v0) (exists st_del (0 2 1) 2 __t3j4h490 k) (exists st_msk (1 2 0) 2 k m) (exists st_msk_ans (1 0) 1 p) (join pbranch (1 2 3 4 0) 4 p m l r __t4hkT489) (exists st_del (0 2 1) 3 __t3j4h490 k __t4hkT489) (join st_bld (1 2 3 4 0) 4 p m l __v0 __t8CKV493) (join st_del (0 2 1) 3 __t3j4h490 k __t4hkT489) (exists st_bld_ans (0 1) 1 __t8CKV493) (join st_msk (1 2 0) 2 k m __t44Py494) (join st_msk_ans (0 1) 2 __t44Py494 p) (join st_bld_ans (0 1) 1 __t8CKV493 res) (let __t3zgo492 (band k m)) (cmp gt __t3zgo492 __tconst0v7T491)) (head (emit st_del_ans (0 1) __t3j4h490 res)) set.slog:91 #f)
  class ReadTask782 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x90x0x0x0index763;  slog::Index** pbranchindex764;  slog::Index** st_delindex765;  slog::Index** st_mskindex766;  slog::Index** st_del_ansindex767;  slog::Index** st_bldindex768;  slog::Index** $sup9688x90x0x0x0index769;  slog::Index** st_bldindex770;  slog::Index** st_delindex771;  slog::Index** st_mskindex772;  slog::Index** st_msk_ansindex773;  slog::Index** pbranchindex774;  slog::Index** st_delindex775;  slog::Index** st_bldindex776;  slog::Index** st_delindex777;  slog::Index** st_bld_ansindex778;  slog::Index** st_mskindex779;  slog::Index** st_msk_ansindex780;  slog::Index** st_bld_ansindex781;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_del_ans");
      std::vector<u16> ord783({0, 1});
      slog::Relation* readrel784 = db->getRelation("st_del_ans");
      head_index[0] = readrel784->getIndex(ord783, false);
      outer_rel = db->getRelation("st_del");
      std::vector<u16> ord785({1, 5, 0, 2, 3, 4});
      slog::Relation* readrel786 = db->getRelation("$sup9688x90x0x0x0");
      $sup9688x90x0x0x0index763 = readrel786->getIndex(ord785, false);
      std::vector<u16> ord787({4, 0, 1, 2, 3});
      slog::Relation* readrel788 = db->getRelation("pbranch");
      pbranchindex764 = readrel788->getIndex(ord787, false);
      std::vector<u16> ord789({2, 0, 1});
      slog::Relation* readrel790 = db->getRelation("st_del");
      st_delindex765 = readrel790->getIndex(ord789, false);
      std::vector<u16> ord791({1, 2, 0});
      slog::Relation* readrel792 = db->getRelation("st_msk");
      st_mskindex766 = readrel792->getIndex(ord791, false);
      std::vector<u16> ord793({0, 1});
      slog::Relation* readrel794 = db->getRelation("st_del_ans");
      st_del_ansindex767 = readrel794->getIndex(ord793, false);
      std::vector<u16> ord795({4, 0, 1, 2, 3});
      slog::Relation* readrel796 = db->getRelation("st_bld");
      st_bldindex768 = readrel796->getIndex(ord795, false);
      std::vector<u16> ord797({1, 5, 0, 2, 3, 4});
      slog::Relation* readrel798 = db->getRelation("$sup9688x90x0x0x0");
      $sup9688x90x0x0x0index769 = readrel798->getIndex(ord797, false);
      std::vector<u16> ord799({1, 2, 3, 4, 0});
      slog::Relation* readrel800 = db->getRelation("st_bld");
      st_bldindex770 = readrel800->getIndex(ord799, false);
      std::vector<u16> ord801({0, 2, 1});
      slog::Relation* readrel802 = db->getRelation("st_del");
      st_delindex771 = readrel802->getIndex(ord801, false);
      std::vector<u16> ord803({1, 2, 0});
      slog::Relation* readrel804 = db->getRelation("st_msk");
      st_mskindex772 = readrel804->getIndex(ord803, false);
      std::vector<u16> ord805({1, 0});
      slog::Relation* readrel806 = db->getRelation("st_msk_ans");
      st_msk_ansindex773 = readrel806->getIndex(ord805, false);
      std::vector<u16> ord807({1, 2, 3, 4, 0});
      slog::Relation* readrel808 = db->getRelation("pbranch");
      pbranchindex774 = readrel808->getIndex(ord807, false);
      std::vector<u16> ord809({0, 2, 1});
      slog::Relation* readrel810 = db->getRelation("st_del");
      st_delindex775 = readrel810->getIndex(ord809, false);
      std::vector<u16> ord811({1, 2, 3, 4, 0});
      slog::Relation* readrel812 = db->getRelation("st_bld");
      st_bldindex776 = readrel812->getIndex(ord811, false);
      std::vector<u16> ord813({0, 2, 1});
      slog::Relation* readrel814 = db->getRelation("st_del");
      st_delindex777 = readrel814->getIndex(ord813, false);
      std::vector<u16> ord815({0, 1});
      slog::Relation* readrel816 = db->getRelation("st_bld_ans");
      st_bld_ansindex778 = readrel816->getIndex(ord815, false);
      std::vector<u16> ord817({1, 2, 0});
      slog::Relation* readrel818 = db->getRelation("st_msk");
      st_mskindex779 = readrel818->getIndex(ord817, false);
      std::vector<u16> ord819({0, 1});
      slog::Relation* readrel820 = db->getRelation("st_msk_ans");
      st_msk_ansindex780 = readrel820->getIndex(ord819, false);
      std::vector<u16> ord821({0, 1});
      slog::Relation* readrel822 = db->getRelation("st_bld_ans");
      st_bld_ansindex781 = readrel822->getIndex(ord821, false);
  
    }
    ReadTask782(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c177 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c178 = _t[0];
        u64 v_c8 = _t[1];
        u64 v_c3 = _t[2];
        if (!slog::exists_probe<6,2>($sup9688x90x0x0x0index763, std::array<u64,6>{v_c3, v_c8, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex764, std::array<u64,5>{v_c8, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_delindex765, std::array<u64,3>{v_c3, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mskindex766, std::array<u64,3>{v_c3, 0, 0})) return;
        slog::join_probe<2,1>(st_del_ansindex767, std::array<u64,2>{v_c178, 0}, [&](const std::array<u64,2>& m823) {
          u64 v_c4 = m823[1];
          if (!slog::exists_probe<5,1>(st_bldindex768, std::array<u64,5>{v_c4, 0, 0, 0, 0})) return;
          slog::join_probe<6,2>($sup9688x90x0x0x0index769, std::array<u64,6>{v_c3, v_c8, 0, 0, 0, 0}, [&](const std::array<u64,6>& m824) {
            u64 v_c179 = m824[2]; u64 v_c2 = m824[3]; u64 v_c6 = m824[4]; u64 v_c7 = m824[5];
            if (!slog::exists_probe<5,4>(st_bldindex770, std::array<u64,5>{v_c7, v_c6, v_c2, v_c4, 0})) return;
            if (!slog::exists_probe<3,2>(st_delindex771, std::array<u64,3>{v_c179, v_c3, 0})) return;
            if (!slog::exists_probe<3,2>(st_mskindex772, std::array<u64,3>{v_c3, v_c6, 0})) return;
            if (!slog::exists_probe<2,1>(st_msk_ansindex773, std::array<u64,2>{v_c7, 0})) return;
            slog::join_probe<5,4>(pbranchindex774, std::array<u64,5>{v_c7, v_c6, v_c2, v_c8, 0}, [&](const std::array<u64,5>& m825) {
              u64 v_c180 = m825[4];
              if (!slog::exists_probe<3,3>(st_delindex775, std::array<u64,3>{v_c179, v_c3, v_c180})) return;
              slog::join_probe<5,4>(st_bldindex776, std::array<u64,5>{v_c7, v_c6, v_c2, v_c4, 0}, [&](const std::array<u64,5>& m826) {
                u64 v_c181 = m826[4];
                slog::join_probe<3,3>(st_delindex777, std::array<u64,3>{v_c179, v_c3, v_c180}, [&](const std::array<u64,3>& m827) {
                  if (!slog::exists_probe<2,1>(st_bld_ansindex778, std::array<u64,2>{v_c181, 0})) return;
                  slog::join_probe<3,2>(st_mskindex779, std::array<u64,3>{v_c3, v_c6, 0}, [&](const std::array<u64,3>& m828) {
                    u64 v_c182 = m828[2];
                    slog::join_probe<2,2>(st_msk_ansindex780, std::array<u64,2>{v_c182, v_c7}, [&](const std::array<u64,2>& m829) {
                      slog::join_probe<2,1>(st_bld_ansindex781, std::array<u64,2>{v_c181, 0}, [&](const std::array<u64,2>& m830) {
                        u64 v_c12 = m830[1];
                        u64 v_c183 = _prim_band(db, v_c3, v_c6);
                        if (v_c183 == slog_error) { slog::emit_pending_error(db, "set.slog:91"); return; }
                        u64 v_c184 = _prim_gt(db, v_c183, v_c177);
                        if (v_c184 == slog_error) { slog::emit_pending_error(db, "set.slog:91"); return; }
                        if (!v_c184) return;
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c179, v_c12}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("set.slog:91", "delta:st_del", _fires);
  
      if (!_done)
      {
        ReadTask782* _cont = new ReadTask782(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask782(db,b), false);
  // (crule (pre) (scan temp5blj1404 __t4PzE464 __v2 __v3 t0 t1) (body (join pbranch (1 2 3 4 0) 4 __v2 __v3 t1 t0 __t1bKH463)) (head (emit st_join_ans (0 1) __t4PzE464 __t1bKH463)) set.slog:41 #f)
  class ReadTask833 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex832;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_join_ans");
      std::vector<u16> ord834({0, 1});
      slog::Relation* readrel835 = db->getRelation("st_join_ans");
      head_index[0] = readrel835->getIndex(ord834, false);
      outer_rel = db->getRelation("temp5blj1404");
      std::vector<u16> ord836({1, 2, 3, 4, 0});
      slog::Relation* readrel837 = db->getRelation("pbranch");
      pbranchindex832 = readrel837->getIndex(ord836, false);
  
    }
    ReadTask833(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c156 = _t[0];
        u64 v_c21 = _t[1];
        u64 v_c155 = _t[2];
        u64 v_c90 = _t[3];
        u64 v_c91 = _t[4];
        slog::join_probe<5,4>(pbranchindex832, std::array<u64,5>{v_c21, v_c155, v_c91, v_c90, 0}, [&](const std::array<u64,5>& m838) {
          u64 v_c185 = m838[4];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c156, v_c185}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:41", "delta:temp5blj1404", _fires);
  
      if (!_done)
      {
        ReadTask833* _cont = new ReadTask833(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask833(db,b), false);
  // (crule (pre (let __tconst80a51002 conste3776bfed7f405de8017ecfa) (let __tconst87Bp297 const6b86b273ff34fce19d6b804e) (let __tconst9HiA300 const2c624232cdd221771294dfbb) (let __tconst4xiW302 constd4735e3a265e16eee03f5971) (let __tconst3GLg296 constef2d127de37b942baad06145)) (scan st_ins_ans __t43hI303 __v2) (body (exists _enum (1 0) 1 __tconst80a51002) (exists st_ins (2 0 1) 1 __tconst87Bp297) (exists st_ins (2 0 1) 1 __tconst9HiA300) (join-old st_ins (0 2 1) 2 (0 2 1) __t43hI303 __tconst4xiW302 __v1) (exists st_ins_ans (1 0) 1 __v1) (join _enum (1 0) 1 __tconst80a51002 __t1S8l298) (join-old st_ins (1 2 0) 2 (1 2 0) __t1S8l298 __tconst87Bp297 __t3icK299) (join st_ins_ans (0 1) 1 __t3icK299 __v0) (join-old st_ins (1 2 0) 2 (1 2 0) __v0 __tconst9HiA300 __t8YZs301) (join st_ins_ans (0 1) 2 __t8YZs301 __v1)) (head (mkstruct st_ins (1 2 0) __6IJz1003 __v2 __tconst3GLg296)) st_basic.slog:15 #f)
  class ReadTask852 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex839;  slog::Index** st_insindex840;  slog::Index** st_insindex841;  slog::Index** st_insindex842;  slog::Index** st_ins_ansindex843;  slog::Index** _enumindex844;  slog::Index** st_insindex845;  slog::Index** st_ins_ansindex846;  slog::Index** st_insindex847;  slog::Index** st_ins_ansindex848;  slog::Index** st_insdelta849;  slog::Index** st_insdelta850;  slog::Index** st_insdelta851;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_ins");
      outer_rel = db->getRelation("st_ins_ans");
      std::vector<u16> ord853({1, 0});
      slog::Relation* readrel854 = db->getRelation("_enum");
      _enumindex839 = readrel854->getIndex(ord853, false);
      std::vector<u16> ord855({2, 0, 1});
      slog::Relation* readrel856 = db->getRelation("st_ins");
      st_insindex840 = readrel856->getIndex(ord855, false);
      std::vector<u16> ord857({2, 0, 1});
      slog::Relation* readrel858 = db->getRelation("st_ins");
      st_insindex841 = readrel858->getIndex(ord857, false);
      std::vector<u16> ord859({0, 2, 1});
      slog::Relation* readrel860 = db->getRelation("st_ins");
      st_insindex842 = readrel860->getIndex(ord859, false);
      std::vector<u16> ord861({0, 2, 1});
      slog::Relation* readrel862 = db->getRelation("st_ins");
      st_insdelta849 = readrel862->getIndex(ord861, true);
      std::vector<u16> ord863({1, 0});
      slog::Relation* readrel864 = db->getRelation("st_ins_ans");
      st_ins_ansindex843 = readrel864->getIndex(ord863, false);
      std::vector<u16> ord865({1, 0});
      slog::Relation* readrel866 = db->getRelation("_enum");
      _enumindex844 = readrel866->getIndex(ord865, false);
      std::vector<u16> ord867({1, 2, 0});
      slog::Relation* readrel868 = db->getRelation("st_ins");
      st_insindex845 = readrel868->getIndex(ord867, false);
      std::vector<u16> ord869({1, 2, 0});
      slog::Relation* readrel870 = db->getRelation("st_ins");
      st_insdelta850 = readrel870->getIndex(ord869, true);
      std::vector<u16> ord871({0, 1});
      slog::Relation* readrel872 = db->getRelation("st_ins_ans");
      st_ins_ansindex846 = readrel872->getIndex(ord871, false);
      std::vector<u16> ord873({1, 2, 0});
      slog::Relation* readrel874 = db->getRelation("st_ins");
      st_insindex847 = readrel874->getIndex(ord873, false);
      std::vector<u16> ord875({1, 2, 0});
      slog::Relation* readrel876 = db->getRelation("st_ins");
      st_insdelta851 = readrel876->getIndex(ord875, true);
      std::vector<u16> ord877({0, 1});
      slog::Relation* readrel878 = db->getRelation("st_ins_ans");
      st_ins_ansindex848 = readrel878->getIndex(ord877, false);
  
    }
    ReadTask852(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c186 = v_conste3776bfed7f405de8017ecfa;
      u64 v_c187 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c188 = v_const2c624232cdd221771294dfbb;
      u64 v_c189 = v_constd4735e3a265e16eee03f5971;
      u64 v_c190 = v_constef2d127de37b942baad06145;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c191 = _t[0];
        u64 v_c21 = _t[1];
        if (!slog::exists_probe<2,1>(_enumindex839, std::array<u64,2>{v_c186, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex840, std::array<u64,3>{v_c187, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_insindex841, std::array<u64,3>{v_c188, 0, 0})) return;
        slog::join_probe_old<3,2>(st_insindex842, st_insdelta849, std::array<u64,3>{v_c191, v_c189, 0}, [&](const std::array<u64,3>& m879) {
          u64 v_c22 = m879[2];
          if (!slog::exists_probe<2,1>(st_ins_ansindex843, std::array<u64,2>{v_c22, 0})) return;
          slog::join_probe<2,1>(_enumindex844, std::array<u64,2>{v_c186, 0}, [&](const std::array<u64,2>& m880) {
            u64 v_c192 = m880[1];
            slog::join_probe_old<3,2>(st_insindex845, st_insdelta850, std::array<u64,3>{v_c192, v_c187, 0}, [&](const std::array<u64,3>& m881) {
              u64 v_c193 = m881[2];
              slog::join_probe<2,1>(st_ins_ansindex846, std::array<u64,2>{v_c193, 0}, [&](const std::array<u64,2>& m882) {
                u64 v_c4 = m882[1];
                slog::join_probe_old<3,2>(st_insindex847, st_insdelta851, std::array<u64,3>{v_c4, v_c188, 0}, [&](const std::array<u64,3>& m883) {
                  u64 v_c194 = m883[2];
                  slog::join_probe<2,2>(st_ins_ansindex848, std::array<u64,2>{v_c194, v_c22}, [&](const std::array<u64,2>& m884) {
                    ++_fires;
                    slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c21, v_c190}, std::array<u16,3>{1, 2, 0});
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
        ReadTask852* _cont = new ReadTask852(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask852(db,b), false);
  // (crule (pre) (scan st_join __t4gXi86 p0 t0 p1 t1) (body) (head (emit $sup9688x36x0x0x0 (1 0 2 3 4) p0 __t4gXi86 p1 t0 t1)) set.slog:37 #f)
  class ReadTask885 : public slog::Task
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
      head_rel[0] = db->getRelation("$sup9688x36x0x0x0");
      std::vector<u16> ord886({1, 0, 2, 3, 4});
      slog::Relation* readrel887 = db->getRelation("$sup9688x36x0x0x0");
      head_index[0] = readrel887->getIndex(ord886, false);
      outer_rel = db->getRelation("st_join");
  
    }
    ReadTask885(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c195 = _t[0];
        u64 v_c88 = _t[1];
        u64 v_c90 = _t[2];
        u64 v_c89 = _t[3];
        u64 v_c91 = _t[4];
        ++_fires;
        slog::emit<5>(head_rel[0], head_index[0], newbatch[0], std::array<u64,5>{v_c88, v_c195, v_c89, v_c90, v_c91}, std::array<u16,5>{1, 0, 2, 3, 4});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:37", "delta:st_join", _fires);
  
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
  // (crule (pre (let __tconst4buc465 const5feceb66ffc86f38d952786c)) (scan st_hsb __t2flT468 __t2awV472) (body (exists st_hsb_ans (0 1) 1 __t2flT468) (exists $sup9688x40x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) 1 __t2flT468) (exists $sup9688x40x0x0x1 (1 2 0 3 4 5 6) 1 __t2flT468) (join st_hsb_ans (0 1) 1 __t2flT468 __v3) (exists $sup9688x40x0x0x2 (1 6 0 2 3 4 5 7 8 9 10) 2 __t2flT468 __v3) (join st_hsb_ans (0 1) 1 __t2flT468 __v1) (exists $sup9688x40x0x0x2 (1 5 6 7 0 2 3 4 8 9 10) 3 __t2flT468 __v1 __v3) (exists st_msk (2 0 1) 1 __v1) (join st_hsb_ans (0 1) 1 __t2flT468 __v0) (exists $sup9688x40x0x0x1 (1 2 0 3 4 5 6) 2 __t2flT468 __v0) (join $sup9688x40x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) 4 __t2flT468 __v0 __v3 __v1 __t4PzE464 dup2gd61405 dup5ZAM1406 p0 p1 t0 t1) (eq __t2flT468 dup5ZAM1406) (eq __t2flT468 dup2gd61405) (join $sup9688x40x0x0x1 (0 3 4 5 6 1 2) 7 __t4PzE464 p0 p1 t0 t1 __t2flT468 __v0) (join $sup9688x40x0x0x0 (1 0 2 3 4) 5 p0 __t4PzE464 p1 t0 t1) (join-old st_join (1 2 3 4 0) 5 (1 2 3 4 0) p0 t0 p1 t1 __t4PzE464) (join st_msk (1 2 0) 2 p0 __v1 __t0rt9471) (join st_msk_ans (0 1) 1 __t0rt9471 __v2) (let __t7pIU466 (band p0 __v0)) (cmp gt __t7pIU466 __tconst4buc465) (let chk0Mpi1407 (bxor p0 p1)) (eq __t2awV472 chk0Mpi1407)) (head (emit-temp temp5blj1404 __t4PzE464 __v2 __v3 t0 t1) (mkstruct pbranch (1 2 3 4 0) __t1bKH463 __v2 __v3 t1 t0)) set.slog:41 #f)
  class ReadTask905 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_hsb_ansindex888;  slog::Index** $sup9688x40x0x0x2index889;  slog::Index** $sup9688x40x0x0x1index890;  slog::Index** st_hsb_ansindex891;  slog::Index** $sup9688x40x0x0x2index892;  slog::Index** st_hsb_ansindex893;  slog::Index** $sup9688x40x0x0x2index894;  slog::Index** st_mskindex895;  slog::Index** st_hsb_ansindex896;  slog::Index** $sup9688x40x0x0x1index897;  slog::Index** $sup9688x40x0x0x2index898;  slog::Index** $sup9688x40x0x0x1index899;  slog::Index** $sup9688x40x0x0x0index900;  slog::Index** st_joinindex901;  slog::Index** st_mskindex902;  slog::Index** st_msk_ansindex903;  slog::Index** st_joindelta904;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5blj1404");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("st_hsb");
      std::vector<u16> ord906({0, 1});
      slog::Relation* readrel907 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex888 = readrel907->getIndex(ord906, false);
      std::vector<u16> ord908({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel909 = db->getRelation("$sup9688x40x0x0x2");
      $sup9688x40x0x0x2index889 = readrel909->getIndex(ord908, false);
      std::vector<u16> ord910({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel911 = db->getRelation("$sup9688x40x0x0x1");
      $sup9688x40x0x0x1index890 = readrel911->getIndex(ord910, false);
      std::vector<u16> ord912({0, 1});
      slog::Relation* readrel913 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex891 = readrel913->getIndex(ord912, false);
      std::vector<u16> ord914({1, 6, 0, 2, 3, 4, 5, 7, 8, 9, 10});
      slog::Relation* readrel915 = db->getRelation("$sup9688x40x0x0x2");
      $sup9688x40x0x0x2index892 = readrel915->getIndex(ord914, false);
      std::vector<u16> ord916({0, 1});
      slog::Relation* readrel917 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex893 = readrel917->getIndex(ord916, false);
      std::vector<u16> ord918({1, 5, 6, 7, 0, 2, 3, 4, 8, 9, 10});
      slog::Relation* readrel919 = db->getRelation("$sup9688x40x0x0x2");
      $sup9688x40x0x0x2index894 = readrel919->getIndex(ord918, false);
      std::vector<u16> ord920({2, 0, 1});
      slog::Relation* readrel921 = db->getRelation("st_msk");
      st_mskindex895 = readrel921->getIndex(ord920, false);
      std::vector<u16> ord922({0, 1});
      slog::Relation* readrel923 = db->getRelation("st_hsb_ans");
      st_hsb_ansindex896 = readrel923->getIndex(ord922, false);
      std::vector<u16> ord924({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel925 = db->getRelation("$sup9688x40x0x0x1");
      $sup9688x40x0x0x1index897 = readrel925->getIndex(ord924, false);
      std::vector<u16> ord926({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel927 = db->getRelation("$sup9688x40x0x0x2");
      $sup9688x40x0x0x2index898 = readrel927->getIndex(ord926, false);
      std::vector<u16> ord928({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel929 = db->getRelation("$sup9688x40x0x0x1");
      $sup9688x40x0x0x1index899 = readrel929->getIndex(ord928, false);
      std::vector<u16> ord930({1, 0, 2, 3, 4});
      slog::Relation* readrel931 = db->getRelation("$sup9688x40x0x0x0");
      $sup9688x40x0x0x0index900 = readrel931->getIndex(ord930, false);
      std::vector<u16> ord932({1, 2, 3, 4, 0});
      slog::Relation* readrel933 = db->getRelation("st_join");
      st_joinindex901 = readrel933->getIndex(ord932, false);
      std::vector<u16> ord934({1, 2, 3, 4, 0});
      slog::Relation* readrel935 = db->getRelation("st_join");
      st_joindelta904 = readrel935->getIndex(ord934, true);
      std::vector<u16> ord936({1, 2, 0});
      slog::Relation* readrel937 = db->getRelation("st_msk");
      st_mskindex902 = readrel937->getIndex(ord936, false);
      std::vector<u16> ord938({0, 1});
      slog::Relation* readrel939 = db->getRelation("st_msk_ans");
      st_msk_ansindex903 = readrel939->getIndex(ord938, false);
  
    }
    ReadTask905(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c152 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c159 = _t[1];
        if (!slog::exists_probe<2,1>(st_hsb_ansindex888, std::array<u64,2>{v_c154, 0})) return;
        if (!slog::exists_probe<11,1>($sup9688x40x0x0x2index889, std::array<u64,11>{v_c154, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<7,1>($sup9688x40x0x0x1index890, std::array<u64,7>{v_c154, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(st_hsb_ansindex891, std::array<u64,2>{v_c154, 0}, [&](const std::array<u64,2>& m940) {
          u64 v_c155 = m940[1];
          if (!slog::exists_probe<11,2>($sup9688x40x0x0x2index892, std::array<u64,11>{v_c154, v_c155, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          slog::join_probe<2,1>(st_hsb_ansindex893, std::array<u64,2>{v_c154, 0}, [&](const std::array<u64,2>& m941) {
            u64 v_c22 = m941[1];
            if (!slog::exists_probe<11,3>($sup9688x40x0x0x2index894, std::array<u64,11>{v_c154, v_c22, v_c155, 0, 0, 0, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<3,1>(st_mskindex895, std::array<u64,3>{v_c22, 0, 0})) return;
            slog::join_probe<2,1>(st_hsb_ansindex896, std::array<u64,2>{v_c154, 0}, [&](const std::array<u64,2>& m942) {
              u64 v_c4 = m942[1];
              if (!slog::exists_probe<7,2>($sup9688x40x0x0x1index897, std::array<u64,7>{v_c154, v_c4, 0, 0, 0, 0, 0})) return;
              slog::join_probe<11,4>($sup9688x40x0x0x2index898, std::array<u64,11>{v_c154, v_c4, v_c155, v_c22, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m943) {
                u64 v_c156 = m943[4]; u64 v_c157 = m943[5]; u64 v_c158 = m943[6]; u64 v_c88 = m943[7]; u64 v_c89 = m943[8]; u64 v_c90 = m943[9]; u64 v_c91 = m943[10];
                if (v_c154 != v_c158) return;
                if (v_c154 != v_c157) return;
                slog::join_probe<7,7>($sup9688x40x0x0x1index899, std::array<u64,7>{v_c156, v_c88, v_c89, v_c90, v_c91, v_c154, v_c4}, [&](const std::array<u64,7>& m944) {
                  slog::join_probe<5,5>($sup9688x40x0x0x0index900, std::array<u64,5>{v_c88, v_c156, v_c89, v_c90, v_c91}, [&](const std::array<u64,5>& m945) {
                    slog::join_probe_old<5,5>(st_joinindex901, st_joindelta904, std::array<u64,5>{v_c88, v_c90, v_c89, v_c91, v_c156}, [&](const std::array<u64,5>& m946) {
                      slog::join_probe<3,2>(st_mskindex902, std::array<u64,3>{v_c88, v_c22, 0}, [&](const std::array<u64,3>& m947) {
                        u64 v_c153 = m947[2];
                        slog::join_probe<2,1>(st_msk_ansindex903, std::array<u64,2>{v_c153, 0}, [&](const std::array<u64,2>& m948) {
                          u64 v_c21 = m948[1];
                          u64 v_c160 = _prim_band(db, v_c88, v_c4);
                          if (v_c160 == slog_error) { slog::emit_pending_error(db, "set.slog:41"); return; }
                          u64 v_c196 = _prim_gt(db, v_c160, v_c152);
                          if (v_c196 == slog_error) { slog::emit_pending_error(db, "set.slog:41"); return; }
                          if (!v_c196) return;
                          u64 v_c197 = _prim_bxor(db, v_c88, v_c89);
                          if (v_c197 == slog_error) { slog::emit_pending_error(db, "set.slog:41"); return; }
                          if (v_c159 != v_c197) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c156, v_c21, v_c155, v_c90, v_c91});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c21, v_c155, v_c91, v_c90}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:41", "delta:st_hsb", _fires);
  
      if (!_done)
      {
        ReadTask905* _cont = new ReadTask905(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask905(db,b), false);
  // (crule (pre) (scan st_ins __t1Tua112 __t29mi113 k) (body (exists pleaf (1 0) 1 k) (join-old st_join (1 4 3 0 2) 2 (1 4 3 0 2) k __t29mi113 j __t6WK8115 __t3mOh114) (neq j k) (join-old pleaf (0 1) 2 (0 1) __t29mi113 j) (join-old pleaf (0 1) 2 (0 1) __t3mOh114 k) (join st_join_ans (0 1) 1 __t6WK8115 r)) (head (emit st_ins_ans (0 1) __t1Tua112 r)) set.slog:50 #f)
  class ReadTask958 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pleafindex950;  slog::Index** st_joinindex951;  slog::Index** pleafindex952;  slog::Index** pleafindex953;  slog::Index** st_join_ansindex954;  slog::Index** st_joindelta955;  slog::Index** pleafdelta956;  slog::Index** pleafdelta957;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_ins_ans");
      std::vector<u16> ord959({0, 1});
      slog::Relation* readrel960 = db->getRelation("st_ins_ans");
      head_index[0] = readrel960->getIndex(ord959, false);
      outer_rel = db->getRelation("st_ins");
      std::vector<u16> ord961({1, 0});
      slog::Relation* readrel962 = db->getRelation("pleaf");
      pleafindex950 = readrel962->getIndex(ord961, false);
      std::vector<u16> ord963({1, 4, 3, 0, 2});
      slog::Relation* readrel964 = db->getRelation("st_join");
      st_joinindex951 = readrel964->getIndex(ord963, false);
      std::vector<u16> ord965({1, 4, 3, 0, 2});
      slog::Relation* readrel966 = db->getRelation("st_join");
      st_joindelta955 = readrel966->getIndex(ord965, true);
      std::vector<u16> ord967({0, 1});
      slog::Relation* readrel968 = db->getRelation("pleaf");
      pleafindex952 = readrel968->getIndex(ord967, false);
      std::vector<u16> ord969({0, 1});
      slog::Relation* readrel970 = db->getRelation("pleaf");
      pleafdelta956 = readrel970->getIndex(ord969, true);
      std::vector<u16> ord971({0, 1});
      slog::Relation* readrel972 = db->getRelation("pleaf");
      pleafindex953 = readrel972->getIndex(ord971, false);
      std::vector<u16> ord973({0, 1});
      slog::Relation* readrel974 = db->getRelation("pleaf");
      pleafdelta957 = readrel974->getIndex(ord973, true);
      std::vector<u16> ord975({0, 1});
      slog::Relation* readrel976 = db->getRelation("st_join_ans");
      st_join_ansindex954 = readrel976->getIndex(ord975, false);
  
    }
    ReadTask958(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c198 = _t[0];
        u64 v_c199 = _t[1];
        u64 v_c3 = _t[2];
        if (!slog::exists_probe<2,1>(pleafindex950, std::array<u64,2>{v_c3, 0})) return;
        slog::join_probe_old<5,2>(st_joinindex951, st_joindelta955, std::array<u64,5>{v_c3, v_c199, 0, 0, 0}, [&](const std::array<u64,5>& m977) {
          u64 v_c200 = m977[2]; u64 v_c201 = m977[3]; u64 v_c202 = m977[4];
          if (v_c200 == v_c3) return;
          slog::join_probe_old<2,2>(pleafindex952, pleafdelta956, std::array<u64,2>{v_c199, v_c200}, [&](const std::array<u64,2>& m978) {
            slog::join_probe_old<2,2>(pleafindex953, pleafdelta957, std::array<u64,2>{v_c202, v_c3}, [&](const std::array<u64,2>& m979) {
              slog::join_probe<2,1>(st_join_ansindex954, std::array<u64,2>{v_c201, 0}, [&](const std::array<u64,2>& m980) {
                u64 v_c8 = m980[1];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c198, v_c8}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:50", "delta:st_ins", _fires);
  
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
  // (crule (pre (let __trid24kc889 constcbf5a4e983555adcacc7f2e9) (let __trel12Y1890 const1d9eff40314d54862fee3942) (let __tcol88JW891 const6b86b273ff34fce19d6b804e) (let __trel85R5892 const66633592860a63ea6408b433) (let __tcol02BJ893 const5feceb66ffc86f38d952786c) (let __trel8hVh894 const66633592860a63ea6408b433) (let __tcol6Fxg895 const6b86b273ff34fce19d6b804e) (let __trel79gp896 const66633592860a63ea6408b433) (let __tcol0Tyz897 constd4735e3a265e16eee03f5971) (let __trel7fGf898 const66633592860a63ea6408b433) (let __tcol1GdA899 const4e07408562bedb8b60ce05c1)) (scan $sup9688x151x0x0x0 __d0 l m n p q r u v) (body) (head (tycheck v (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid24kc889 __trel12Y1890 __tcol88JW891 (1 2 3 4 0)) (tycheck p (accept int) __trid24kc889 __trel85R5892 __tcol02BJ893 (1 2 3 4 0)) (tycheck m (accept int) __trid24kc889 __trel8hVh894 __tcol6Fxg895 (1 2 3 4 0)) (tycheck l (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid24kc889 __trel79gp896 __tcol0Tyz897 (1 2 3 4 0)) (tycheck r (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid24kc889 __trel7fGf898 __tcol1GdA899 (1 2 3 4 0)) (emit-temp temp4rmF1269 l m p r v) (mkstruct pbranch (1 2 3 4 0) __t1NYA370 p m l r)) set.slog:152 #f)
  class ReadTask984 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[7];
    slog::Index** head_index[7];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid982;  u32 sid981;  u32 sid983;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("malformed_deduction");
      head_rel[3] = db->getRelation("malformed_deduction");
      head_rel[4] = db->getRelation("malformed_deduction");
      head_rel[5] = db->getRelation("temp4rmF1269");
      head_rel[6] = db->getRelation("pbranch");
      outer_rel = db->getRelation("$sup9688x151x0x0x0");
      sid982 = db->getRelation("_enum")->getStructId();
      sid981 = db->getRelation("pbranch")->getStructId();
      sid983 = db->getRelation("pleaf")->getStructId();
  
    }
    ReadTask984(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c203 = v_constcbf5a4e983555adcacc7f2e9;
      u64 v_c204 = v_const1d9eff40314d54862fee3942;
      u64 v_c205 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c206 = v_const66633592860a63ea6408b433;
      u64 v_c207 = v_const5feceb66ffc86f38d952786c;
      u64 v_c208 = v_const66633592860a63ea6408b433;
      u64 v_c209 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c210 = v_const66633592860a63ea6408b433;
      u64 v_c211 = v_constd4735e3a265e16eee03f5971;
      u64 v_c212 = v_const66633592860a63ea6408b433;
      u64 v_c213 = v_const4e07408562bedb8b60ce05c1;
  
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
        u64 v_c44 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c45 = _t[3];
        u64 v_c7 = _t[4];
        u64 v_c46 = _t[5];
        u64 v_c8 = _t[6];
        u64 v_c47 = _t[7];
        u64 v_c48 = _t[8];
        ++_fires;
        if (!((is_struct(v_c48) && (decode_struct_id(v_c48) == sid981 || decode_struct_id(v_c48) == sid982 || decode_struct_id(v_c48) == sid983))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c203, v_c204, v_c205, v_c48}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c7)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c203, v_c206, v_c207, v_c7}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c6)))
        {
          slog::emit_struct<5>(head_rel[2], newbatch[2], std::array<u64,4>{v_c203, v_c208, v_c209, v_c6}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c2) && (decode_struct_id(v_c2) == sid981 || decode_struct_id(v_c2) == sid982 || decode_struct_id(v_c2) == sid983))))
        {
          slog::emit_struct<5>(head_rel[3], newbatch[3], std::array<u64,4>{v_c203, v_c210, v_c211, v_c2}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c8) && (decode_struct_id(v_c8) == sid981 || decode_struct_id(v_c8) == sid982 || decode_struct_id(v_c8) == sid983))))
        {
          slog::emit_struct<5>(head_rel[4], newbatch[4], std::array<u64,4>{v_c203, v_c212, v_c213, v_c8}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_temp<5>(head_rel[5], newbatch[5], std::array<u64,5>{v_c2, v_c6, v_c7, v_c8, v_c48});
        slog::emit_struct<5>(head_rel[6], newbatch[6], std::array<u64,4>{v_c7, v_c6, v_c2, v_c8}, std::array<u16,5>{1, 2, 3, 4, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
        head_rel[5]->sendBatch(newbatch[5]);
        head_rel[6]->sendBatch(newbatch[6]);
  
      if (_fires) db->bumpFires("set.slog:152", "delta:$sup9688x151x0x0x0", _fires);
  
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
  // (crule (pre (let __tconst8MXc56 const6b86b273ff34fce19d6b804e)) (scan st_ins __t8YRN55 __t8Tgk54 k) (body (join pbranch (0 1 2 3 4) 1 __t8Tgk54 p m l r) (let __t3NtX57 (band k m)) (cmp lt __t3NtX57 __tconst8MXc56)) (head (emit $sup9688x50x0x0x0 (4 2 3 5 0 1) p l m r __t8YRN55 k)) set.slog:51 #f)
  class ReadTask986 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex985;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x50x0x0x0");
      std::vector<u16> ord987({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel988 = db->getRelation("$sup9688x50x0x0x0");
      head_index[0] = readrel988->getIndex(ord987, false);
      outer_rel = db->getRelation("st_ins");
      std::vector<u16> ord989({0, 1, 2, 3, 4});
      slog::Relation* readrel990 = db->getRelation("pbranch");
      pbranchindex985 = readrel990->getIndex(ord989, false);
  
    }
    ReadTask986(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c214 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c215 = _t[0];
        u64 v_c216 = _t[1];
        u64 v_c3 = _t[2];
        slog::join_probe<5,1>(pbranchindex985, std::array<u64,5>{v_c216, 0, 0, 0, 0}, [&](const std::array<u64,5>& m991) {
          u64 v_c7 = m991[1]; u64 v_c6 = m991[2]; u64 v_c2 = m991[3]; u64 v_c8 = m991[4];
          u64 v_c217 = _prim_band(db, v_c3, v_c6);
          if (v_c217 == slog_error) { slog::emit_pending_error(db, "set.slog:51"); return; }
          u64 v_c218 = _prim_lt(db, v_c217, v_c214);
          if (v_c218 == slog_error) { slog::emit_pending_error(db, "set.slog:51"); return; }
          if (!v_c218) return;
          ++_fires;
          slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c7, v_c2, v_c6, v_c8, v_c215, v_c3}, std::array<u16,6>{4, 2, 3, 5, 0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:51", "delta:st_ins", _fires);
  
      if (!_done)
      {
        ReadTask986* _cont = new ReadTask986(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask986(db,b), false);
  // (crule (pre (let __tconst2IZo78 const5feceb66ffc86f38d952786c)) (scan st_diff __t8Vvm81 __t0L1D80 v) (body (exists st_diff (1 2 0) 1 __t0L1D80) (exists pbranch (4 0 1 2 3) 1 v) (exists $sup9688x151x0x0x0 (8 0 1 2 3 4 5 6 7) 1 v) (join st_diff_ans (0 1) 1 __t8Vvm81 res) (join st_diff (1 2 0) 1 __t0L1D80 __t3eDW75 __t0F4S77) (exists $sup9688x151x0x0x0 (0 8 1 2 3 4 5 6 7) 2 __t0F4S77 v) (join pbranch (4 0 1 2 3) 2 v __t3eDW75 q n u) (exists st_msk (2 0 1) 1 n) (exists st_msk_ans (1 0) 1 q) (join $sup9688x151x0x0x0 (5 3 7 8 0 1 2 4 6) 5 q n u v __t0F4S77 l m p r) (cmp lt m n) (join pbranch (1 2 3 4 0) 5 p m l r __t0L1D80) (join-old st_msk (1 2 0) 2 (1 2 0) p n __t1x4A82) (join st_msk_ans (0 1) 2 __t1x4A82 q) (let __t2OsQ79 (band p n)) (cmp gt __t2OsQ79 __tconst2IZo78)) (head (emit st_diff_ans (0 1) __t0F4S77 res)) set.slog:152 #f)
  class ReadTask1007 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_diffindex993;  slog::Index** pbranchindex994;  slog::Index** $sup9688x151x0x0x0index995;  slog::Index** st_diff_ansindex996;  slog::Index** st_diffindex997;  slog::Index** $sup9688x151x0x0x0index998;  slog::Index** pbranchindex999;  slog::Index** st_mskindex1000;  slog::Index** st_msk_ansindex1001;  slog::Index** $sup9688x151x0x0x0index1002;  slog::Index** pbranchindex1003;  slog::Index** st_mskindex1004;  slog::Index** st_msk_ansindex1005;  slog::Index** st_mskdelta1006;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_diff_ans");
      std::vector<u16> ord1008({0, 1});
      slog::Relation* readrel1009 = db->getRelation("st_diff_ans");
      head_index[0] = readrel1009->getIndex(ord1008, false);
      outer_rel = db->getRelation("st_diff");
      std::vector<u16> ord1010({1, 2, 0});
      slog::Relation* readrel1011 = db->getRelation("st_diff");
      st_diffindex993 = readrel1011->getIndex(ord1010, false);
      std::vector<u16> ord1012({4, 0, 1, 2, 3});
      slog::Relation* readrel1013 = db->getRelation("pbranch");
      pbranchindex994 = readrel1013->getIndex(ord1012, false);
      std::vector<u16> ord1014({8, 0, 1, 2, 3, 4, 5, 6, 7});
      slog::Relation* readrel1015 = db->getRelation("$sup9688x151x0x0x0");
      $sup9688x151x0x0x0index995 = readrel1015->getIndex(ord1014, false);
      std::vector<u16> ord1016({0, 1});
      slog::Relation* readrel1017 = db->getRelation("st_diff_ans");
      st_diff_ansindex996 = readrel1017->getIndex(ord1016, false);
      std::vector<u16> ord1018({1, 2, 0});
      slog::Relation* readrel1019 = db->getRelation("st_diff");
      st_diffindex997 = readrel1019->getIndex(ord1018, false);
      std::vector<u16> ord1020({0, 8, 1, 2, 3, 4, 5, 6, 7});
      slog::Relation* readrel1021 = db->getRelation("$sup9688x151x0x0x0");
      $sup9688x151x0x0x0index998 = readrel1021->getIndex(ord1020, false);
      std::vector<u16> ord1022({4, 0, 1, 2, 3});
      slog::Relation* readrel1023 = db->getRelation("pbranch");
      pbranchindex999 = readrel1023->getIndex(ord1022, false);
      std::vector<u16> ord1024({2, 0, 1});
      slog::Relation* readrel1025 = db->getRelation("st_msk");
      st_mskindex1000 = readrel1025->getIndex(ord1024, false);
      std::vector<u16> ord1026({1, 0});
      slog::Relation* readrel1027 = db->getRelation("st_msk_ans");
      st_msk_ansindex1001 = readrel1027->getIndex(ord1026, false);
      std::vector<u16> ord1028({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel1029 = db->getRelation("$sup9688x151x0x0x0");
      $sup9688x151x0x0x0index1002 = readrel1029->getIndex(ord1028, false);
      std::vector<u16> ord1030({1, 2, 3, 4, 0});
      slog::Relation* readrel1031 = db->getRelation("pbranch");
      pbranchindex1003 = readrel1031->getIndex(ord1030, false);
      std::vector<u16> ord1032({1, 2, 0});
      slog::Relation* readrel1033 = db->getRelation("st_msk");
      st_mskindex1004 = readrel1033->getIndex(ord1032, false);
      std::vector<u16> ord1034({1, 2, 0});
      slog::Relation* readrel1035 = db->getRelation("st_msk");
      st_mskdelta1006 = readrel1035->getIndex(ord1034, true);
      std::vector<u16> ord1036({0, 1});
      slog::Relation* readrel1037 = db->getRelation("st_msk_ans");
      st_msk_ansindex1005 = readrel1037->getIndex(ord1036, false);
  
    }
    ReadTask1007(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c219 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c220 = _t[0];
        u64 v_c221 = _t[1];
        u64 v_c48 = _t[2];
        if (!slog::exists_probe<3,1>(st_diffindex993, std::array<u64,3>{v_c221, 0, 0})) return;
        if (!slog::exists_probe<5,1>(pbranchindex994, std::array<u64,5>{v_c48, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<9,1>($sup9688x151x0x0x0index995, std::array<u64,9>{v_c48, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(st_diff_ansindex996, std::array<u64,2>{v_c220, 0}, [&](const std::array<u64,2>& m1038) {
          u64 v_c12 = m1038[1];
          slog::join_probe<3,1>(st_diffindex997, std::array<u64,3>{v_c221, 0, 0}, [&](const std::array<u64,3>& m1039) {
            u64 v_c222 = m1039[1]; u64 v_c223 = m1039[2];
            if (!slog::exists_probe<9,2>($sup9688x151x0x0x0index998, std::array<u64,9>{v_c223, v_c48, 0, 0, 0, 0, 0, 0, 0})) return;
            slog::join_probe<5,2>(pbranchindex999, std::array<u64,5>{v_c48, v_c222, 0, 0, 0}, [&](const std::array<u64,5>& m1040) {
              u64 v_c46 = m1040[2]; u64 v_c45 = m1040[3]; u64 v_c47 = m1040[4];
              if (!slog::exists_probe<3,1>(st_mskindex1000, std::array<u64,3>{v_c45, 0, 0})) return;
              if (!slog::exists_probe<2,1>(st_msk_ansindex1001, std::array<u64,2>{v_c46, 0})) return;
              slog::join_probe<9,5>($sup9688x151x0x0x0index1002, std::array<u64,9>{v_c46, v_c45, v_c47, v_c48, v_c223, 0, 0, 0, 0}, [&](const std::array<u64,9>& m1041) {
                u64 v_c2 = m1041[5]; u64 v_c6 = m1041[6]; u64 v_c7 = m1041[7]; u64 v_c8 = m1041[8];
                u64 v_c224 = _prim_lt(db, v_c6, v_c45);
                if (v_c224 == slog_error) { slog::emit_pending_error(db, "set.slog:152"); return; }
                if (!v_c224) return;
                slog::join_probe<5,5>(pbranchindex1003, std::array<u64,5>{v_c7, v_c6, v_c2, v_c8, v_c221}, [&](const std::array<u64,5>& m1043) {
                  slog::join_probe_old<3,2>(st_mskindex1004, st_mskdelta1006, std::array<u64,3>{v_c7, v_c45, 0}, [&](const std::array<u64,3>& m1044) {
                    u64 v_c225 = m1044[2];
                    slog::join_probe<2,2>(st_msk_ansindex1005, std::array<u64,2>{v_c225, v_c46}, [&](const std::array<u64,2>& m1045) {
                      u64 v_c226 = _prim_band(db, v_c7, v_c45);
                      if (v_c226 == slog_error) { slog::emit_pending_error(db, "set.slog:152"); return; }
                      u64 v_c227 = _prim_gt(db, v_c226, v_c219);
                      if (v_c227 == slog_error) { slog::emit_pending_error(db, "set.slog:152"); return; }
                      if (!v_c227) return;
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c223, v_c12}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:152", "delta:st_diff", _fires);
  
      if (!_done)
      {
        ReadTask1007* _cont = new ReadTask1007(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1007(db,b), false);
  // (crule (pre) (scan pbranch __t0A4U311 p m l r) (body (join st_ins (1 2 0) 1 __t0A4U311 k __t37YR310)) (head (emit $sup9688x54x0x0x0 (1 3 0 2 4 5 6) k m __t37YR310 l p r __t0A4U311)) set.slog:55 #f)
  class ReadTask1048 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_insindex1047;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup9688x54x0x0x0");
      std::vector<u16> ord1049({1, 3, 0, 2, 4, 5, 6});
      slog::Relation* readrel1050 = db->getRelation("$sup9688x54x0x0x0");
      head_index[0] = readrel1050->getIndex(ord1049, false);
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord1051({1, 2, 0});
      slog::Relation* readrel1052 = db->getRelation("st_ins");
      st_insindex1047 = readrel1052->getIndex(ord1051, false);
  
    }
    ReadTask1048(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c228 = _t[0];
        u64 v_c7 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c2 = _t[3];
        u64 v_c8 = _t[4];
        slog::join_probe<3,1>(st_insindex1047, std::array<u64,3>{v_c228, 0, 0}, [&](const std::array<u64,3>& m1053) {
          u64 v_c3 = m1053[1]; u64 v_c229 = m1053[2];
          ++_fires;
          slog::emit<7>(head_rel[0], head_index[0], newbatch[0], std::array<u64,7>{v_c3, v_c6, v_c229, v_c2, v_c7, v_c8, v_c228}, std::array<u16,7>{1, 3, 0, 2, 4, 5, 6});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:55", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask1048* _cont = new ReadTask1048(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1048(db,b), false);
  // (crule (pre (let __trid9YsA798 constd9f85eba98ed33f6c0ac9bf6) (let __trel8cki799 const9899bd1a9f17c17561973172) (let __tcol9n2h800 const5feceb66ffc86f38d952786c) (let __trel7Kee801 const9899bd1a9f17c17561973172) (let __tcol8dgx802 constd4735e3a265e16eee03f5971) (let __trel3RoV803 const9899bd1a9f17c17561973172) (let __tcol6lMb804 const4e07408562bedb8b60ce05c1) (let __trel8gXZ805 const5d058eae1c2c75768f73b199) (let __tcol5PJt806 const5feceb66ffc86f38d952786c)) (scan $sup9688x54x0x0x0 __d0 k l m p r t) (body) (head (tycheck k (accept int) __trid9YsA798 __trel8cki799 __tcol9n2h800 (1 2 3 4 0)) (tycheck p (accept int) __trid9YsA798 __trel7Kee801 __tcol8dgx802 (1 2 3 4 0)) (tycheck t (accept (struct pbranch) (struct _enum) (struct pleaf)) __trid9YsA798 __trel3RoV803 __tcol6lMb804 (1 2 3 4 0)) (tycheck k (accept int) __trid9YsA798 __trel8gXZ805 __tcol5PJt806 (1 2 3 4 0)) (emit-temp temp4FcU1416 k p t) (mkstruct pleaf (1 0) __t9ved580 k)) set.slog:55 #f)
  class ReadTask1057 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[6];
    slog::Index** head_index[6];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid1055;  u32 sid1054;  u32 sid1056;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("malformed_deduction");
      head_rel[3] = db->getRelation("malformed_deduction");
      head_rel[4] = db->getRelation("temp4FcU1416");
      head_rel[5] = db->getRelation("pleaf");
      outer_rel = db->getRelation("$sup9688x54x0x0x0");
      sid1055 = db->getRelation("_enum")->getStructId();
      sid1054 = db->getRelation("pbranch")->getStructId();
      sid1056 = db->getRelation("pleaf")->getStructId();
  
    }
    ReadTask1057(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c230 = v_constd9f85eba98ed33f6c0ac9bf6;
      u64 v_c231 = v_const9899bd1a9f17c17561973172;
      u64 v_c232 = v_const5feceb66ffc86f38d952786c;
      u64 v_c233 = v_const9899bd1a9f17c17561973172;
      u64 v_c234 = v_constd4735e3a265e16eee03f5971;
      u64 v_c235 = v_const9899bd1a9f17c17561973172;
      u64 v_c236 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c237 = v_const5d058eae1c2c75768f73b199;
      u64 v_c238 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c44 = _t[0];
        u64 v_c3 = _t[1];
        u64 v_c2 = _t[2];
        u64 v_c6 = _t[3];
        u64 v_c7 = _t[4];
        u64 v_c8 = _t[5];
        u64 v_c30 = _t[6];
        ++_fires;
        if (!(is_int(v_c3)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c230, v_c231, v_c232, v_c3}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c7)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c230, v_c233, v_c234, v_c7}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c30) && (decode_struct_id(v_c30) == sid1054 || decode_struct_id(v_c30) == sid1055 || decode_struct_id(v_c30) == sid1056))))
        {
          slog::emit_struct<5>(head_rel[2], newbatch[2], std::array<u64,4>{v_c230, v_c235, v_c236, v_c30}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c3)))
        {
          slog::emit_struct<5>(head_rel[3], newbatch[3], std::array<u64,4>{v_c230, v_c237, v_c238, v_c3}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_temp<3>(head_rel[4], newbatch[4], std::array<u64,3>{v_c3, v_c7, v_c30});
        slog::emit_struct<2>(head_rel[5], newbatch[5], std::array<u64,1>{v_c3}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
        head_rel[5]->sendBatch(newbatch[5]);
  
      if (_fires) db->bumpFires("set.slog:55", "delta:$sup9688x54x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1057* _cont = new ReadTask1057(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1057(db,b), false);
  // (crule (pre (let _00024sqc6FSA620 const4b227777d4dd1fc61c6f884f) (let _00024sqc3Ub8621 const5feceb66ffc86f38d952786c) (let _00024sqc1TCF622 const6b86b273ff34fce19d6b804e) (let _00024sqc3FMQ623 const6b86b273ff34fce19d6b804e) (let _00024sqc41K7624 const2c624232cdd221771294dfbb) (let _00024sqc6uPA625 constd4735e3a265e16eee03f5971) (let _00024sqc9VIm626 constd4735e3a265e16eee03f5971) (let _00024sqc7Q1B627 const4e07408562bedb8b60ce05c1) (let _00024sqc4nIn628 constef2d127de37b942baad06145) (let _00024sqo09Ee630 const6b86b273ff34fce19d6b804e) (let _00024sqo5YJw629 const5feceb66ffc86f38d952786c) (let _00024sqo1RnK632 const2c624232cdd221771294dfbb) (let _00024sqo5bHs631 const6b86b273ff34fce19d6b804e) (let _00024sqo2z3g634 constd4735e3a265e16eee03f5971) (let _00024sqo0Hmn633 constd4735e3a265e16eee03f5971) (let _00024sqo7Xdh636 constef2d127de37b942baad06145) (let _00024sqo5nmm635 const4e07408562bedb8b60ce05c1) (let _00024sqo4nJm638 const6b86b273ff34fce19d6b804e) (let _00024sqo7qJs637 const4e07408562bedb8b60ce05c1) (let _00024sqo4dTI640 const2c624232cdd221771294dfbb) (let _00024sqo4MMk639 constd4735e3a265e16eee03f5971) (let _00024sqo3whL642 constd4735e3a265e16eee03f5971) (let _00024sqo9zLj641 const6b86b273ff34fce19d6b804e) (let _00024sqo1Fkt644 constef2d127de37b942baad06145) (let _00024sqo2E1m643 const5feceb66ffc86f38d952786c)) (probe $seq_atr (0 1 2) 2 _00024sqo1Fkt644 _00024sqo2E1m643 _00024seq0) (body (join $seq_at (1 0 2) 3 _00024sqo5YJw629 _00024sqo09Ee630 _00024seq0) (join $seq_at (1 0 2) 3 _00024sqo5bHs631 _00024sqo1RnK632 _00024seq0) (join $seq_at (1 0 2) 3 _00024sqo0Hmn633 _00024sqo2z3g634 _00024seq0) (join $seq_at (1 0 2) 3 _00024sqo5nmm635 _00024sqo7Xdh636 _00024seq0) (join $seq_atr (0 1 2) 3 _00024sqo4nJm638 _00024sqo7qJs637 _00024seq0) (join $seq_atr (0 1 2) 3 _00024sqo4dTI640 _00024sqo4MMk639 _00024seq0) (join $seq_atr (0 1 2) 3 _00024sqo3whL642 _00024sqo9zLj641 _00024seq0) (join st_fromlist (1 0) 1 _00024seq0 __t2iar332) (join st_fromlist_ans (0 1) 1 __t2iar332 r) (letp _00024sql7znl618 (aslst _00024seq0)) (let chk3Q411394 (llen _00024sql7znl618)) (eq _00024sqc6FSA620 chk3Q411394) (letp chk2p3y1395 (lref _00024sql7znl618 _00024sqc3Ub8621)) (eq _00024sqc1TCF622 chk2p3y1395) (letp chk145z1396 (lref _00024sql7znl618 _00024sqc3FMQ623)) (eq _00024sqc41K7624 chk145z1396) (letp chk5m9o1397 (lref _00024sql7znl618 _00024sqc6uPA625)) (eq _00024sqc9VIm626 chk5m9o1397) (letp chk5Ebk1398 (lref _00024sql7znl618 _00024sqc7Q1B627)) (eq _00024sqc4nIn628 chk5Ebk1398)) (head (emit canon (0) r)) st_basic.slog:17 #f)
  class ReadTask1067 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex1058;  slog::Index** $seq_atindex1059;  slog::Index** $seq_atindex1060;  slog::Index** $seq_atindex1061;  slog::Index** $seq_atrindex1062;  slog::Index** $seq_atrindex1063;  slog::Index** $seq_atrindex1064;  slog::Index** st_fromlistindex1065;  slog::Index** st_fromlist_ansindex1066;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("canon");
      std::vector<u16> ord1068({0});
      slog::Relation* readrel1069 = db->getRelation("canon");
      head_index[0] = readrel1069->getIndex(ord1068, false);
      std::vector<u16> ord1070({0, 1, 2});
      slog::Relation* readrel1071 = db->getRelation("$seq_atr");
      driver_index = readrel1071->getIndex(ord1070, true);
      std::vector<u16> ord1072({1, 0, 2});
      slog::Relation* readrel1073 = db->getRelation("$seq_at");
      $seq_atindex1058 = readrel1073->getIndex(ord1072, false);
      std::vector<u16> ord1074({1, 0, 2});
      slog::Relation* readrel1075 = db->getRelation("$seq_at");
      $seq_atindex1059 = readrel1075->getIndex(ord1074, false);
      std::vector<u16> ord1076({1, 0, 2});
      slog::Relation* readrel1077 = db->getRelation("$seq_at");
      $seq_atindex1060 = readrel1077->getIndex(ord1076, false);
      std::vector<u16> ord1078({1, 0, 2});
      slog::Relation* readrel1079 = db->getRelation("$seq_at");
      $seq_atindex1061 = readrel1079->getIndex(ord1078, false);
      std::vector<u16> ord1080({0, 1, 2});
      slog::Relation* readrel1081 = db->getRelation("$seq_atr");
      $seq_atrindex1062 = readrel1081->getIndex(ord1080, false);
      std::vector<u16> ord1082({0, 1, 2});
      slog::Relation* readrel1083 = db->getRelation("$seq_atr");
      $seq_atrindex1063 = readrel1083->getIndex(ord1082, false);
      std::vector<u16> ord1084({0, 1, 2});
      slog::Relation* readrel1085 = db->getRelation("$seq_atr");
      $seq_atrindex1064 = readrel1085->getIndex(ord1084, false);
      std::vector<u16> ord1086({1, 0});
      slog::Relation* readrel1087 = db->getRelation("st_fromlist");
      st_fromlistindex1065 = readrel1087->getIndex(ord1086, false);
      std::vector<u16> ord1088({0, 1});
      slog::Relation* readrel1089 = db->getRelation("st_fromlist_ans");
      st_fromlist_ansindex1066 = readrel1089->getIndex(ord1088, false);
  
    }
    ReadTask1067(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c49 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c50 = v_const5feceb66ffc86f38d952786c;
      u64 v_c51 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c52 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c53 = v_const2c624232cdd221771294dfbb;
      u64 v_c54 = v_constd4735e3a265e16eee03f5971;
      u64 v_c55 = v_constd4735e3a265e16eee03f5971;
      u64 v_c56 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c57 = v_constef2d127de37b942baad06145;
      u64 v_c58 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c59 = v_const5feceb66ffc86f38d952786c;
      u64 v_c60 = v_const2c624232cdd221771294dfbb;
      u64 v_c61 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c62 = v_constd4735e3a265e16eee03f5971;
      u64 v_c63 = v_constd4735e3a265e16eee03f5971;
      u64 v_c64 = v_constef2d127de37b942baad06145;
      u64 v_c65 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c66 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c67 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c68 = v_const2c624232cdd221771294dfbb;
      u64 v_c69 = v_constd4735e3a265e16eee03f5971;
      u64 v_c70 = v_constd4735e3a265e16eee03f5971;
      u64 v_c71 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c72 = v_constef2d127de37b942baad06145;
      u64 v_c73 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,2>(driver_index, std::array<u64,3>{v_c72, v_c73, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1090) {
        u64 v_c74 = m1090[2];
        if (buckethash(v_c74) != bucket) return;
        slog::join_probe<3,3>($seq_atindex1058, std::array<u64,3>{v_c59, v_c58, v_c74}, [&](const std::array<u64,3>& m1091) {
          slog::join_probe<3,3>($seq_atindex1059, std::array<u64,3>{v_c61, v_c60, v_c74}, [&](const std::array<u64,3>& m1092) {
            slog::join_probe<3,3>($seq_atindex1060, std::array<u64,3>{v_c63, v_c62, v_c74}, [&](const std::array<u64,3>& m1093) {
              slog::join_probe<3,3>($seq_atindex1061, std::array<u64,3>{v_c65, v_c64, v_c74}, [&](const std::array<u64,3>& m1094) {
                slog::join_probe<3,3>($seq_atrindex1062, std::array<u64,3>{v_c66, v_c67, v_c74}, [&](const std::array<u64,3>& m1095) {
                  slog::join_probe<3,3>($seq_atrindex1063, std::array<u64,3>{v_c68, v_c69, v_c74}, [&](const std::array<u64,3>& m1096) {
                    slog::join_probe<3,3>($seq_atrindex1064, std::array<u64,3>{v_c70, v_c71, v_c74}, [&](const std::array<u64,3>& m1097) {
                      slog::join_probe<2,1>(st_fromlistindex1065, std::array<u64,2>{v_c74, 0}, [&](const std::array<u64,2>& m1098) {
                        u64 v_c75 = m1098[1];
                        slog::join_probe<2,1>(st_fromlist_ansindex1066, std::array<u64,2>{v_c75, 0}, [&](const std::array<u64,2>& m1099) {
                          u64 v_c8 = m1099[1];
                          bool ok1100 = true;
                          u64 v_c76 = _prim_aslst(db, v_c74, &ok1100);
                          if (!ok1100) return;
                          u64 v_c239 = _prim_llen(db, v_c76);
                          if (v_c239 == slog_error) { slog::emit_pending_error(db, "st_basic.slog:17"); return; }
                          if (v_c49 != v_c239) return;
                          bool ok1101 = true;
                          u64 v_c240 = _prim_lref(db, v_c76, v_c50, &ok1101);
                          if (!ok1101) return;
                          if (v_c51 != v_c240) return;
                          bool ok1102 = true;
                          u64 v_c241 = _prim_lref(db, v_c76, v_c52, &ok1102);
                          if (!ok1102) return;
                          if (v_c53 != v_c241) return;
                          bool ok1103 = true;
                          u64 v_c242 = _prim_lref(db, v_c76, v_c54, &ok1103);
                          if (!ok1103) return;
                          if (v_c55 != v_c242) return;
                          bool ok1104 = true;
                          u64 v_c243 = _prim_lref(db, v_c76, v_c56, &ok1104);
                          if (!ok1104) return;
                          if (v_c57 != v_c243) return;
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
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("st_basic.slog:17", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask1067* _cont = new ReadTask1067(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1067(db,b), false);
  // (crule (pre) (scan st_del __t5Avq182 __t43Dv181 k) (body (join pleaf (0 1) 1 __t43Dv181 j) (neq j k)) (head (emit st_del_ans (0 1) __t5Avq182 __t43Dv181)) set.slog:87 #f)
  class ReadTask1106 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pleafindex1105;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_del_ans");
      std::vector<u16> ord1107({0, 1});
      slog::Relation* readrel1108 = db->getRelation("st_del_ans");
      head_index[0] = readrel1108->getIndex(ord1107, false);
      outer_rel = db->getRelation("st_del");
      std::vector<u16> ord1109({0, 1});
      slog::Relation* readrel1110 = db->getRelation("pleaf");
      pleafindex1105 = readrel1110->getIndex(ord1109, false);
  
    }
    ReadTask1106(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c244 = _t[0];
        u64 v_c245 = _t[1];
        u64 v_c3 = _t[2];
        slog::join_probe<2,1>(pleafindex1105, std::array<u64,2>{v_c245, 0}, [&](const std::array<u64,2>& m1111) {
          u64 v_c200 = m1111[1];
          if (v_c200 == v_c3) return;
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c244, v_c245}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:87", "delta:st_del", _fires);
  
      if (!_done)
      {
        ReadTask1106* _cont = new ReadTask1106(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1106(db,b), false);
  // (crule (pre) (scan $sup9688x54x0x0x0 __t2YgE11 k l m p r __t4iIu12) (body (join-old pbranch (1 2 3 4 0) 5 (1 2 3 4 0) p m l r __t4iIu12) (join-old st_ins (0 2 1) 3 (0 2 1) __t2YgE11 k __t4iIu12) (exists pleaf (1 0) 1 k) (exists st_msk (1 2 0) 2 k m) (join-old st_join (1 4 3 0 2) 3 (1 4 3 0 2) k __t4iIu12 p __t4hUr14 __t4JtR13) (join-old pleaf (0 1) 2 (0 1) __t4JtR13 k) (exists st_join_ans (0 1) 1 __t4hUr14) (join-old st_msk (1 2 0) 2 (1 2 0) k m __t9Q9j15) (join st_msk_ans (0 1) 1 __t9Q9j15 __v0) (neq p __v0) (join st_join_ans (0 1) 1 __t4hUr14 res)) (head (emit st_ins_ans (0 1) __t2YgE11 res)) set.slog:55 #f)
  class ReadTask1127 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex1112;  slog::Index** st_insindex1113;  slog::Index** pleafindex1114;  slog::Index** st_mskindex1115;  slog::Index** st_joinindex1116;  slog::Index** pleafindex1117;  slog::Index** st_join_ansindex1118;  slog::Index** st_mskindex1119;  slog::Index** st_msk_ansindex1120;  slog::Index** st_join_ansindex1121;  slog::Index** pbranchdelta1122;  slog::Index** st_insdelta1123;  slog::Index** st_joindelta1124;  slog::Index** pleafdelta1125;  slog::Index** st_mskdelta1126;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_ins_ans");
      std::vector<u16> ord1128({0, 1});
      slog::Relation* readrel1129 = db->getRelation("st_ins_ans");
      head_index[0] = readrel1129->getIndex(ord1128, false);
      outer_rel = db->getRelation("$sup9688x54x0x0x0");
      std::vector<u16> ord1130({1, 2, 3, 4, 0});
      slog::Relation* readrel1131 = db->getRelation("pbranch");
      pbranchindex1112 = readrel1131->getIndex(ord1130, false);
      std::vector<u16> ord1132({1, 2, 3, 4, 0});
      slog::Relation* readrel1133 = db->getRelation("pbranch");
      pbranchdelta1122 = readrel1133->getIndex(ord1132, true);
      std::vector<u16> ord1134({0, 2, 1});
      slog::Relation* readrel1135 = db->getRelation("st_ins");
      st_insindex1113 = readrel1135->getIndex(ord1134, false);
      std::vector<u16> ord1136({0, 2, 1});
      slog::Relation* readrel1137 = db->getRelation("st_ins");
      st_insdelta1123 = readrel1137->getIndex(ord1136, true);
      std::vector<u16> ord1138({1, 0});
      slog::Relation* readrel1139 = db->getRelation("pleaf");
      pleafindex1114 = readrel1139->getIndex(ord1138, false);
      std::vector<u16> ord1140({1, 2, 0});
      slog::Relation* readrel1141 = db->getRelation("st_msk");
      st_mskindex1115 = readrel1141->getIndex(ord1140, false);
      std::vector<u16> ord1142({1, 4, 3, 0, 2});
      slog::Relation* readrel1143 = db->getRelation("st_join");
      st_joinindex1116 = readrel1143->getIndex(ord1142, false);
      std::vector<u16> ord1144({1, 4, 3, 0, 2});
      slog::Relation* readrel1145 = db->getRelation("st_join");
      st_joindelta1124 = readrel1145->getIndex(ord1144, true);
      std::vector<u16> ord1146({0, 1});
      slog::Relation* readrel1147 = db->getRelation("pleaf");
      pleafindex1117 = readrel1147->getIndex(ord1146, false);
      std::vector<u16> ord1148({0, 1});
      slog::Relation* readrel1149 = db->getRelation("pleaf");
      pleafdelta1125 = readrel1149->getIndex(ord1148, true);
      std::vector<u16> ord1150({0, 1});
      slog::Relation* readrel1151 = db->getRelation("st_join_ans");
      st_join_ansindex1118 = readrel1151->getIndex(ord1150, false);
      std::vector<u16> ord1152({1, 2, 0});
      slog::Relation* readrel1153 = db->getRelation("st_msk");
      st_mskindex1119 = readrel1153->getIndex(ord1152, false);
      std::vector<u16> ord1154({1, 2, 0});
      slog::Relation* readrel1155 = db->getRelation("st_msk");
      st_mskdelta1126 = readrel1155->getIndex(ord1154, true);
      std::vector<u16> ord1156({0, 1});
      slog::Relation* readrel1157 = db->getRelation("st_msk_ans");
      st_msk_ansindex1120 = readrel1157->getIndex(ord1156, false);
      std::vector<u16> ord1158({0, 1});
      slog::Relation* readrel1159 = db->getRelation("st_join_ans");
      st_join_ansindex1121 = readrel1159->getIndex(ord1158, false);
  
    }
    ReadTask1127(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c246 = _t[0];
        u64 v_c3 = _t[1];
        u64 v_c2 = _t[2];
        u64 v_c6 = _t[3];
        u64 v_c7 = _t[4];
        u64 v_c8 = _t[5];
        u64 v_c247 = _t[6];
        slog::join_probe_old<5,5>(pbranchindex1112, pbranchdelta1122, std::array<u64,5>{v_c7, v_c6, v_c2, v_c8, v_c247}, [&](const std::array<u64,5>& m1160) {
          slog::join_probe_old<3,3>(st_insindex1113, st_insdelta1123, std::array<u64,3>{v_c246, v_c3, v_c247}, [&](const std::array<u64,3>& m1161) {
            if (!slog::exists_probe<2,1>(pleafindex1114, std::array<u64,2>{v_c3, 0})) return;
            if (!slog::exists_probe<3,2>(st_mskindex1115, std::array<u64,3>{v_c3, v_c6, 0})) return;
            slog::join_probe_old<5,3>(st_joinindex1116, st_joindelta1124, std::array<u64,5>{v_c3, v_c247, v_c7, 0, 0}, [&](const std::array<u64,5>& m1162) {
              u64 v_c248 = m1162[3]; u64 v_c249 = m1162[4];
              slog::join_probe_old<2,2>(pleafindex1117, pleafdelta1125, std::array<u64,2>{v_c249, v_c3}, [&](const std::array<u64,2>& m1163) {
                if (!slog::exists_probe<2,1>(st_join_ansindex1118, std::array<u64,2>{v_c248, 0})) return;
                slog::join_probe_old<3,2>(st_mskindex1119, st_mskdelta1126, std::array<u64,3>{v_c3, v_c6, 0}, [&](const std::array<u64,3>& m1164) {
                  u64 v_c250 = m1164[2];
                  slog::join_probe<2,1>(st_msk_ansindex1120, std::array<u64,2>{v_c250, 0}, [&](const std::array<u64,2>& m1165) {
                    u64 v_c4 = m1165[1];
                    if (v_c7 == v_c4) return;
                    slog::join_probe<2,1>(st_join_ansindex1121, std::array<u64,2>{v_c248, 0}, [&](const std::array<u64,2>& m1166) {
                      u64 v_c12 = m1166[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c246, v_c12}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:55", "delta:$sup9688x54x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1127* _cont = new ReadTask1127(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1127(db,b), false);
  // (crule (pre) (scan $sup9688x87x0x0x0 __t3SFe567 k l m p r) (body (exists st_del (0 2 1) 2 __t3SFe567 k) (exists st_msk (1 2 0) 2 k m) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t5rDd566) (join-old st_del (0 2 1) 3 (0 2 1) __t3SFe567 k __t5rDd566) (join-old st_msk (1 2 0) 2 (1 2 0) k m __t0CrA568) (join st_msk_ans (0 1) 1 __t0CrA568 __v0) (neq p __v0)) (head (emit st_del_ans (0 1) __t3SFe567 __t5rDd566)) set.slog:88 #f)
  class ReadTask1176 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** st_delindex1167;  slog::Index** st_mskindex1168;  slog::Index** pbranchindex1169;  slog::Index** st_delindex1170;  slog::Index** st_mskindex1171;  slog::Index** st_msk_ansindex1172;  slog::Index** pbranchdelta1173;  slog::Index** st_deldelta1174;  slog::Index** st_mskdelta1175;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_del_ans");
      std::vector<u16> ord1177({0, 1});
      slog::Relation* readrel1178 = db->getRelation("st_del_ans");
      head_index[0] = readrel1178->getIndex(ord1177, false);
      outer_rel = db->getRelation("$sup9688x87x0x0x0");
      std::vector<u16> ord1179({0, 2, 1});
      slog::Relation* readrel1180 = db->getRelation("st_del");
      st_delindex1167 = readrel1180->getIndex(ord1179, false);
      std::vector<u16> ord1181({1, 2, 0});
      slog::Relation* readrel1182 = db->getRelation("st_msk");
      st_mskindex1168 = readrel1182->getIndex(ord1181, false);
      std::vector<u16> ord1183({1, 2, 3, 4, 0});
      slog::Relation* readrel1184 = db->getRelation("pbranch");
      pbranchindex1169 = readrel1184->getIndex(ord1183, false);
      std::vector<u16> ord1185({1, 2, 3, 4, 0});
      slog::Relation* readrel1186 = db->getRelation("pbranch");
      pbranchdelta1173 = readrel1186->getIndex(ord1185, true);
      std::vector<u16> ord1187({0, 2, 1});
      slog::Relation* readrel1188 = db->getRelation("st_del");
      st_delindex1170 = readrel1188->getIndex(ord1187, false);
      std::vector<u16> ord1189({0, 2, 1});
      slog::Relation* readrel1190 = db->getRelation("st_del");
      st_deldelta1174 = readrel1190->getIndex(ord1189, true);
      std::vector<u16> ord1191({1, 2, 0});
      slog::Relation* readrel1192 = db->getRelation("st_msk");
      st_mskindex1171 = readrel1192->getIndex(ord1191, false);
      std::vector<u16> ord1193({1, 2, 0});
      slog::Relation* readrel1194 = db->getRelation("st_msk");
      st_mskdelta1175 = readrel1194->getIndex(ord1193, true);
      std::vector<u16> ord1195({0, 1});
      slog::Relation* readrel1196 = db->getRelation("st_msk_ans");
      st_msk_ansindex1172 = readrel1196->getIndex(ord1195, false);
  
    }
    ReadTask1176(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c251 = _t[0];
        u64 v_c3 = _t[1];
        u64 v_c2 = _t[2];
        u64 v_c6 = _t[3];
        u64 v_c7 = _t[4];
        u64 v_c8 = _t[5];
        if (!slog::exists_probe<3,2>(st_delindex1167, std::array<u64,3>{v_c251, v_c3, 0})) return;
        if (!slog::exists_probe<3,2>(st_mskindex1168, std::array<u64,3>{v_c3, v_c6, 0})) return;
        slog::join_probe_old<5,4>(pbranchindex1169, pbranchdelta1173, std::array<u64,5>{v_c7, v_c6, v_c2, v_c8, 0}, [&](const std::array<u64,5>& m1197) {
          u64 v_c252 = m1197[4];
          slog::join_probe_old<3,3>(st_delindex1170, st_deldelta1174, std::array<u64,3>{v_c251, v_c3, v_c252}, [&](const std::array<u64,3>& m1198) {
            slog::join_probe_old<3,2>(st_mskindex1171, st_mskdelta1175, std::array<u64,3>{v_c3, v_c6, 0}, [&](const std::array<u64,3>& m1199) {
              u64 v_c253 = m1199[2];
              slog::join_probe<2,1>(st_msk_ansindex1172, std::array<u64,2>{v_c253, 0}, [&](const std::array<u64,2>& m1200) {
                u64 v_c4 = m1200[1];
                if (v_c7 == v_c4) return;
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c251, v_c252}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:88", "delta:$sup9688x87x0x0x0", _fires);
  
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
  // (crule (pre (let __tconst0x19246 const6b86b273ff34fce19d6b804e)) (scan pbranch __t2RvE244 p m l r) (body (exists $sup9688x103x0x0x1 (2 3 5 7 0 4 6 8 9 1) 4 l m p r) (exists st_union (1 2 0) 1 __t2RvE244) (exists st_msk (2 0 1) 1 m) (exists st_msk_ans (1 0) 1 p) (exists st_union (1 2 0) 1 l) (join $sup9688x103x0x0x0 (1 2 4 6 0 3 5 7 8) 4 l m p r __t3N33245 n q u v) (cmp lt n m) (exists pbranch (1 2 3 4 0) 4 q n u v) (exists st_union (0 1 2) 2 __t3N33245 __t2RvE244) (exists st_msk (1 2 0) 2 q m) (join $sup9688x103x0x0x1 (2 3 5 7 0 4 6 8 9 1) 9 l m p r __t3N33245 n q u v __t3q0j248) (exists st_msk (1 2 0) 3 q m __t3q0j248) (exists st_msk_ans (0 1) 2 __t3q0j248 p) (join-old pbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t8HsZ249) (join-old st_union (0 1 2) 3 (0 1 2) __t3N33245 __t2RvE244 __t8HsZ249) (join-old st_msk (1 2 0) 3 (1 2 0) q m __t3q0j248) (join st_msk_ans (0 1) 2 __t3q0j248 p) (join-old st_union (1 2 0) 2 (1 2 0) l __t8HsZ249 __t4eoh250) (join st_union_ans (0 1) 1 __t4eoh250 __v0) (let __t1j57247 (band q m)) (cmp lt __t1j57247 __tconst0x19246)) (head (emit-temp temp9eaB1343 __t3N33245 __v0 m p r) (mkstruct pbranch (1 2 3 4 0) __t2omG242 p m __v0 r)) set.slog:104 #f)
  class ReadTask1223 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup9688x103x0x0x1index1201;  slog::Index** st_unionindex1202;  slog::Index** st_mskindex1203;  slog::Index** st_msk_ansindex1204;  slog::Index** st_unionindex1205;  slog::Index** $sup9688x103x0x0x0index1206;  slog::Index** pbranchindex1207;  slog::Index** st_unionindex1208;  slog::Index** st_mskindex1209;  slog::Index** $sup9688x103x0x0x1index1210;  slog::Index** st_mskindex1211;  slog::Index** st_msk_ansindex1212;  slog::Index** pbranchindex1213;  slog::Index** st_unionindex1214;  slog::Index** st_mskindex1215;  slog::Index** st_msk_ansindex1216;  slog::Index** st_unionindex1217;  slog::Index** st_union_ansindex1218;  slog::Index** pbranchdelta1219;  slog::Index** st_uniondelta1220;  slog::Index** st_mskdelta1221;  slog::Index** st_uniondelta1222;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9eaB1343");
      head_rel[1] = db->getRelation("pbranch");
      outer_rel = db->getRelation("pbranch");
      std::vector<u16> ord1224({2, 3, 5, 7, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel1225 = db->getRelation("$sup9688x103x0x0x1");
      $sup9688x103x0x0x1index1201 = readrel1225->getIndex(ord1224, false);
      std::vector<u16> ord1226({1, 2, 0});
      slog::Relation* readrel1227 = db->getRelation("st_union");
      st_unionindex1202 = readrel1227->getIndex(ord1226, false);
      std::vector<u16> ord1228({2, 0, 1});
      slog::Relation* readrel1229 = db->getRelation("st_msk");
      st_mskindex1203 = readrel1229->getIndex(ord1228, false);
      std::vector<u16> ord1230({1, 0});
      slog::Relation* readrel1231 = db->getRelation("st_msk_ans");
      st_msk_ansindex1204 = readrel1231->getIndex(ord1230, false);
      std::vector<u16> ord1232({1, 2, 0});
      slog::Relation* readrel1233 = db->getRelation("st_union");
      st_unionindex1205 = readrel1233->getIndex(ord1232, false);
      std::vector<u16> ord1234({1, 2, 4, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel1235 = db->getRelation("$sup9688x103x0x0x0");
      $sup9688x103x0x0x0index1206 = readrel1235->getIndex(ord1234, false);
      std::vector<u16> ord1236({1, 2, 3, 4, 0});
      slog::Relation* readrel1237 = db->getRelation("pbranch");
      pbranchindex1207 = readrel1237->getIndex(ord1236, false);
      std::vector<u16> ord1238({0, 1, 2});
      slog::Relation* readrel1239 = db->getRelation("st_union");
      st_unionindex1208 = readrel1239->getIndex(ord1238, false);
      std::vector<u16> ord1240({1, 2, 0});
      slog::Relation* readrel1241 = db->getRelation("st_msk");
      st_mskindex1209 = readrel1241->getIndex(ord1240, false);
      std::vector<u16> ord1242({2, 3, 5, 7, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel1243 = db->getRelation("$sup9688x103x0x0x1");
      $sup9688x103x0x0x1index1210 = readrel1243->getIndex(ord1242, false);
      std::vector<u16> ord1244({1, 2, 0});
      slog::Relation* readrel1245 = db->getRelation("st_msk");
      st_mskindex1211 = readrel1245->getIndex(ord1244, false);
      std::vector<u16> ord1246({0, 1});
      slog::Relation* readrel1247 = db->getRelation("st_msk_ans");
      st_msk_ansindex1212 = readrel1247->getIndex(ord1246, false);
      std::vector<u16> ord1248({1, 2, 3, 4, 0});
      slog::Relation* readrel1249 = db->getRelation("pbranch");
      pbranchindex1213 = readrel1249->getIndex(ord1248, false);
      std::vector<u16> ord1250({1, 2, 3, 4, 0});
      slog::Relation* readrel1251 = db->getRelation("pbranch");
      pbranchdelta1219 = readrel1251->getIndex(ord1250, true);
      std::vector<u16> ord1252({0, 1, 2});
      slog::Relation* readrel1253 = db->getRelation("st_union");
      st_unionindex1214 = readrel1253->getIndex(ord1252, false);
      std::vector<u16> ord1254({0, 1, 2});
      slog::Relation* readrel1255 = db->getRelation("st_union");
      st_uniondelta1220 = readrel1255->getIndex(ord1254, true);
      std::vector<u16> ord1256({1, 2, 0});
      slog::Relation* readrel1257 = db->getRelation("st_msk");
      st_mskindex1215 = readrel1257->getIndex(ord1256, false);
      std::vector<u16> ord1258({1, 2, 0});
      slog::Relation* readrel1259 = db->getRelation("st_msk");
      st_mskdelta1221 = readrel1259->getIndex(ord1258, true);
      std::vector<u16> ord1260({0, 1});
      slog::Relation* readrel1261 = db->getRelation("st_msk_ans");
      st_msk_ansindex1216 = readrel1261->getIndex(ord1260, false);
      std::vector<u16> ord1262({1, 2, 0});
      slog::Relation* readrel1263 = db->getRelation("st_union");
      st_unionindex1217 = readrel1263->getIndex(ord1262, false);
      std::vector<u16> ord1264({1, 2, 0});
      slog::Relation* readrel1265 = db->getRelation("st_union");
      st_uniondelta1222 = readrel1265->getIndex(ord1264, true);
      std::vector<u16> ord1266({0, 1});
      slog::Relation* readrel1267 = db->getRelation("st_union_ans");
      st_union_ansindex1218 = readrel1267->getIndex(ord1266, false);
  
    }
    ReadTask1223(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c254 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c255 = _t[0];
        u64 v_c7 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c2 = _t[3];
        u64 v_c8 = _t[4];
        if (!slog::exists_probe<10,4>($sup9688x103x0x0x1index1201, std::array<u64,10>{v_c2, v_c6, v_c7, v_c8, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_unionindex1202, std::array<u64,3>{v_c255, 0, 0})) return;
        if (!slog::exists_probe<3,1>(st_mskindex1203, std::array<u64,3>{v_c6, 0, 0})) return;
        if (!slog::exists_probe<2,1>(st_msk_ansindex1204, std::array<u64,2>{v_c7, 0})) return;
        if (!slog::exists_probe<3,1>(st_unionindex1205, std::array<u64,3>{v_c2, 0, 0})) return;
        slog::join_probe<9,4>($sup9688x103x0x0x0index1206, std::array<u64,9>{v_c2, v_c6, v_c7, v_c8, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m1268) {
          u64 v_c256 = m1268[4]; u64 v_c45 = m1268[5]; u64 v_c46 = m1268[6]; u64 v_c47 = m1268[7]; u64 v_c48 = m1268[8];
          u64 v_c257 = _prim_lt(db, v_c45, v_c6);
          if (v_c257 == slog_error) { slog::emit_pending_error(db, "set.slog:104"); return; }
          if (!v_c257) return;
          if (!slog::exists_probe<5,4>(pbranchindex1207, std::array<u64,5>{v_c46, v_c45, v_c47, v_c48, 0})) return;
          if (!slog::exists_probe<3,2>(st_unionindex1208, std::array<u64,3>{v_c256, v_c255, 0})) return;
          if (!slog::exists_probe<3,2>(st_mskindex1209, std::array<u64,3>{v_c46, v_c6, 0})) return;
          slog::join_probe<10,9>($sup9688x103x0x0x1index1210, std::array<u64,10>{v_c2, v_c6, v_c7, v_c8, v_c256, v_c45, v_c46, v_c47, v_c48, 0}, [&](const std::array<u64,10>& m1270) {
            u64 v_c258 = m1270[9];
            if (!slog::exists_probe<3,3>(st_mskindex1211, std::array<u64,3>{v_c46, v_c6, v_c258})) return;
            if (!slog::exists_probe<2,2>(st_msk_ansindex1212, std::array<u64,2>{v_c258, v_c7})) return;
            slog::join_probe_old<5,4>(pbranchindex1213, pbranchdelta1219, std::array<u64,5>{v_c46, v_c45, v_c47, v_c48, 0}, [&](const std::array<u64,5>& m1271) {
              u64 v_c259 = m1271[4];
              slog::join_probe_old<3,3>(st_unionindex1214, st_uniondelta1220, std::array<u64,3>{v_c256, v_c255, v_c259}, [&](const std::array<u64,3>& m1272) {
                slog::join_probe_old<3,3>(st_mskindex1215, st_mskdelta1221, std::array<u64,3>{v_c46, v_c6, v_c258}, [&](const std::array<u64,3>& m1273) {
                  slog::join_probe<2,2>(st_msk_ansindex1216, std::array<u64,2>{v_c258, v_c7}, [&](const std::array<u64,2>& m1274) {
                    slog::join_probe_old<3,2>(st_unionindex1217, st_uniondelta1222, std::array<u64,3>{v_c2, v_c259, 0}, [&](const std::array<u64,3>& m1275) {
                      u64 v_c260 = m1275[2];
                      slog::join_probe<2,1>(st_union_ansindex1218, std::array<u64,2>{v_c260, 0}, [&](const std::array<u64,2>& m1276) {
                        u64 v_c4 = m1276[1];
                        u64 v_c261 = _prim_band(db, v_c46, v_c6);
                        if (v_c261 == slog_error) { slog::emit_pending_error(db, "set.slog:104"); return; }
                        u64 v_c262 = _prim_lt(db, v_c261, v_c254);
                        if (v_c262 == slog_error) { slog::emit_pending_error(db, "set.slog:104"); return; }
                        if (!v_c262) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c256, v_c4, v_c6, v_c7, v_c8});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c7, v_c6, v_c4, v_c8}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("set.slog:104", "delta:pbranch", _fires);
  
      if (!_done)
      {
        ReadTask1223* _cont = new ReadTask1223(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1223(db,b), false);
  // (crule (pre) (scan st_join __t744h135 p __t9DTf133 q __t972J134) (body (exists pbranch (0 1 2 3 4) 2 __t9DTf133 p) (exists pbranch (0 1 2 3 4) 2 __t972J134 q) (exists st_union (1 2 0) 2 __t9DTf133 __t972J134) (exists st_msk (1 2 0) 1 q) (exists st_join_ans (0 1) 1 __t744h135) (join $sup9688x110x0x0x0 (4 5 7 8 0 1 2 3 6 9 10) 4 p q __t9DTf133 __t972J134 __t1PdV132 l m n r u v) (cmp lt n m) (join pbranch (1 2 3 4 0) 5 p m l r __t9DTf133) (join pbranch (1 2 3 4 0) 5 q n u v __t972J134) (join st_union (0 1 2) 3 __t1PdV132 __t9DTf133 __t972J134) (join-old st_msk (1 2 0) 2 (1 2 0) q m __t4C16136) (join st_msk_ans (0 1) 1 __t4C16136 __v0) (neq p __v0) (join st_join_ans (0 1) 1 __t744h135 res)) (head (emit st_union_ans (0 1) __t1PdV132 res)) set.slog:111 #f)
  class ReadTask1291 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** pbranchindex1278;  slog::Index** pbranchindex1279;  slog::Index** st_unionindex1280;  slog::Index** st_mskindex1281;  slog::Index** st_join_ansindex1282;  slog::Index** $sup9688x110x0x0x0index1283;  slog::Index** pbranchindex1284;  slog::Index** pbranchindex1285;  slog::Index** st_unionindex1286;  slog::Index** st_mskindex1287;  slog::Index** st_msk_ansindex1288;  slog::Index** st_join_ansindex1289;  slog::Index** st_mskdelta1290;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("st_union_ans");
      std::vector<u16> ord1292({0, 1});
      slog::Relation* readrel1293 = db->getRelation("st_union_ans");
      head_index[0] = readrel1293->getIndex(ord1292, false);
      outer_rel = db->getRelation("st_join");
      std::vector<u16> ord1294({0, 1, 2, 3, 4});
      slog::Relation* readrel1295 = db->getRelation("pbranch");
      pbranchindex1278 = readrel1295->getIndex(ord1294, false);
      std::vector<u16> ord1296({0, 1, 2, 3, 4});
      slog::Relation* readrel1297 = db->getRelation("pbranch");
      pbranchindex1279 = readrel1297->getIndex(ord1296, false);
      std::vector<u16> ord1298({1, 2, 0});
      slog::Relation* readrel1299 = db->getRelation("st_union");
      st_unionindex1280 = readrel1299->getIndex(ord1298, false);
      std::vector<u16> ord1300({1, 2, 0});
      slog::Relation* readrel1301 = db->getRelation("st_msk");
      st_mskindex1281 = readrel1301->getIndex(ord1300, false);
      std::vector<u16> ord1302({0, 1});
      slog::Relation* readrel1303 = db->getRelation("st_join_ans");
      st_join_ansindex1282 = readrel1303->getIndex(ord1302, false);
      std::vector<u16> ord1304({4, 5, 7, 8, 0, 1, 2, 3, 6, 9, 10});
      slog::Relation* readrel1305 = db->getRelation("$sup9688x110x0x0x0");
      $sup9688x110x0x0x0index1283 = readrel1305->getIndex(ord1304, false);
      std::vector<u16> ord1306({1, 2, 3, 4, 0});
      slog::Relation* readrel1307 = db->getRelation("pbranch");
      pbranchindex1284 = readrel1307->getIndex(ord1306, false);
      std::vector<u16> ord1308({1, 2, 3, 4, 0});
      slog::Relation* readrel1309 = db->getRelation("pbranch");
      pbranchindex1285 = readrel1309->getIndex(ord1308, false);
      std::vector<u16> ord1310({0, 1, 2});
      slog::Relation* readrel1311 = db->getRelation("st_union");
      st_unionindex1286 = readrel1311->getIndex(ord1310, false);
      std::vector<u16> ord1312({1, 2, 0});
      slog::Relation* readrel1313 = db->getRelation("st_msk");
      st_mskindex1287 = readrel1313->getIndex(ord1312, false);
      std::vector<u16> ord1314({1, 2, 0});
      slog::Relation* readrel1315 = db->getRelation("st_msk");
      st_mskdelta1290 = readrel1315->getIndex(ord1314, true);
      std::vector<u16> ord1316({0, 1});
      slog::Relation* readrel1317 = db->getRelation("st_msk_ans");
      st_msk_ansindex1288 = readrel1317->getIndex(ord1316, false);
      std::vector<u16> ord1318({0, 1});
      slog::Relation* readrel1319 = db->getRelation("st_join_ans");
      st_join_ansindex1289 = readrel1319->getIndex(ord1318, false);
  
    }
    ReadTask1291(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c263 = _t[0];
        u64 v_c7 = _t[1];
        u64 v_c264 = _t[2];
        u64 v_c46 = _t[3];
        u64 v_c265 = _t[4];
        if (!slog::exists_probe<5,2>(pbranchindex1278, std::array<u64,5>{v_c264, v_c7, 0, 0, 0})) return;
        if (!slog::exists_probe<5,2>(pbranchindex1279, std::array<u64,5>{v_c265, v_c46, 0, 0, 0})) return;
        if (!slog::exists_probe<3,2>(st_unionindex1280, std::array<u64,3>{v_c264, v_c265, 0})) return;
        if (!slog::exists_probe<3,1>(st_mskindex1281, std::array<u64,3>{v_c46, 0, 0})) return;
        if (!slog::exists_probe<2,1>(st_join_ansindex1282, std::array<u64,2>{v_c263, 0})) return;
        slog::join_probe<11,4>($sup9688x110x0x0x0index1283, std::array<u64,11>{v_c7, v_c46, v_c264, v_c265, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m1320) {
          u64 v_c266 = m1320[4]; u64 v_c2 = m1320[5]; u64 v_c6 = m1320[6]; u64 v_c45 = m1320[7]; u64 v_c8 = m1320[8]; u64 v_c47 = m1320[9]; u64 v_c48 = m1320[10];
          u64 v_c267 = _prim_lt(db, v_c45, v_c6);
          if (v_c267 == slog_error) { slog::emit_pending_error(db, "set.slog:111"); return; }
          if (!v_c267) return;
          slog::join_probe<5,5>(pbranchindex1284, std::array<u64,5>{v_c7, v_c6, v_c2, v_c8, v_c264}, [&](const std::array<u64,5>& m1322) {
            slog::join_probe<5,5>(pbranchindex1285, std::array<u64,5>{v_c46, v_c45, v_c47, v_c48, v_c265}, [&](const std::array<u64,5>& m1323) {
              slog::join_probe<3,3>(st_unionindex1286, std::array<u64,3>{v_c266, v_c264, v_c265}, [&](const std::array<u64,3>& m1324) {
                slog::join_probe_old<3,2>(st_mskindex1287, st_mskdelta1290, std::array<u64,3>{v_c46, v_c6, 0}, [&](const std::array<u64,3>& m1325) {
                  u64 v_c268 = m1325[2];
                  slog::join_probe<2,1>(st_msk_ansindex1288, std::array<u64,2>{v_c268, 0}, [&](const std::array<u64,2>& m1326) {
                    u64 v_c4 = m1326[1];
                    if (v_c7 == v_c4) return;
                    slog::join_probe<2,1>(st_join_ansindex1289, std::array<u64,2>{v_c263, 0}, [&](const std::array<u64,2>& m1327) {
                      u64 v_c12 = m1327[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c266, v_c12}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("set.slog:111", "delta:st_join", _fires);
  
      if (!_done)
      {
        ReadTask1291* _cont = new ReadTask1291(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1291(db,b), false);
}

