
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const0122baa3ac55f1b433944eb1;
extern u64 v_const1b2483991f3f37e4463261cd;
extern u64 v_const521b2193c302e05f0bbf60da;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const7f254967624b26d820569bd6;
extern u64 v_const9cfb09b7c00913be7566a50e;
extern u64 v_constb642bb32c0b8fd35118770e8;
extern u64 v_constb9e118781cea1f9fa01462e0;
extern u64 v_constcd2a69ce5ca278db1d6da969;
extern u64 v_constd01925b37634a1a9d24159d8;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_constd9f3167b950244706dc6dbb2;
extern u64 v_constdd7bbf31ce5f578b9805e840;
extern u64 v_constde34af73616246ffdc2cc593;
extern u64 v_constdede4476644eb06b5a48b866;
extern u64 v_conste90c92f3e6c3b47a7bc93e42;
extern u64 v_constfdb0a95399e17c48d6f65653;


void slog_rules_cfc6e8e503efb06d7(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre (let __tconst4KHb101 const5feceb66ffc86f38d952786c)) (scan mleaf __t9soq102 j v) (body (join-old mp_has0 (1 2 0) 1 (1 2 0) __t9soq102 k __t58FV103) (neq j k)) (head (emit mp_has0_ans (0 1) __t58FV103 __tconst4KHb101)) map.slog:59 #f)
  class ReadTask2 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_has0index0;  slog::Index** mp_has0delta1;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_has0_ans");
      std::vector<u16> ord3({0, 1});
      slog::Relation* readrel4 = db->getRelation("mp_has0_ans");
      head_index[0] = readrel4->getIndex(ord3, false);
      outer_rel = db->getRelation("mleaf");
      std::vector<u16> ord5({1, 2, 0});
      slog::Relation* readrel6 = db->getRelation("mp_has0");
      mp_has0index0 = readrel6->getIndex(ord5, false);
      std::vector<u16> ord7({1, 2, 0});
      slog::Relation* readrel8 = db->getRelation("mp_has0");
      mp_has0delta1 = readrel8->getIndex(ord7, true);
  
    }
    ReadTask2(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const5feceb66ffc86f38d952786c;
  
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
        slog::join_probe_old<3,1>(mp_has0index0, mp_has0delta1, std::array<u64,3>{v_c1, 0, 0}, [&](const std::array<u64,3>& m9) {
          u64 v_c4 = m9[1]; u64 v_c5 = m9[2];
          if (v_c2 == v_c4) return;
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c5, v_c0}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:59", "delta:mleaf", _fires);
  
      if (!_done)
      {
        ReadTask2* _cont = new ReadTask2(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask2(db,b), false);
  // (crule (pre) (scan closure __t5Yru265 __t3Nsh264 rhoc) (body (join eval_ans (1 0) 1 __t5Yru265 __t1jZw263) (join lambda (0 1 2) 1 __t3Nsh264 xs eb) (join eval (0 1 2 3) 1 __t1jZw263 ef rho t) (exists eval_args (3 2 0 1) 2 t rho) (exists app (1 2 0) 1 ef) (exists tick (2 0 1) 1 t) (join $sup70016x51x0x0x0 (1 3 4 0 2) 3 ef rho t __d0 es) (exists app (1 2 0) 2 ef es) (join-old eval_args (1 3 2 0) 3 (1 3 2 0) es t rho __t2ycT266) (exists eval_args_ans (0 1) 1 __t2ycT266) (join-old app (1 2 0) 2 (1 2 0) ef es __t4H6p267) (join-old tick (1 2 0) 2 (1 2 0) __t4H6p267 t __t8A6X268) (exists tick_ans (0 1) 1 __t8A6X268) (join eval_args_ans (0 1) 1 __t2ycT266 vs) (join tick_ans (0 1) 1 __t8A6X268 t2)) (head (emit $sup70016x51x0x0x1 (1 8 0 2 3 4 5 6 7 9 10 11 12) __t1jZw263 rhoc __d0 __t2ycT266 __t8A6X268 eb ef es rho t t2 vs xs)) interp.slog:52 #f)
  class ReadTask28 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eval_ansindex10;  slog::Index** lambdaindex11;  slog::Index** evalindex12;  slog::Index** eval_argsindex13;  slog::Index** appindex14;  slog::Index** tickindex15;  slog::Index** $sup70016x51x0x0x0index16;  slog::Index** appindex17;  slog::Index** eval_argsindex18;  slog::Index** eval_args_ansindex19;  slog::Index** appindex20;  slog::Index** tickindex21;  slog::Index** tick_ansindex22;  slog::Index** eval_args_ansindex23;  slog::Index** tick_ansindex24;  slog::Index** eval_argsdelta25;  slog::Index** appdelta26;  slog::Index** tickdelta27;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup70016x51x0x0x1");
      std::vector<u16> ord29({1, 8, 0, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12});
      slog::Relation* readrel30 = db->getRelation("$sup70016x51x0x0x1");
      head_index[0] = readrel30->getIndex(ord29, false);
      outer_rel = db->getRelation("closure");
      std::vector<u16> ord31({1, 0});
      slog::Relation* readrel32 = db->getRelation("eval_ans");
      eval_ansindex10 = readrel32->getIndex(ord31, false);
      std::vector<u16> ord33({0, 1, 2});
      slog::Relation* readrel34 = db->getRelation("lambda");
      lambdaindex11 = readrel34->getIndex(ord33, false);
      std::vector<u16> ord35({0, 1, 2, 3});
      slog::Relation* readrel36 = db->getRelation("eval");
      evalindex12 = readrel36->getIndex(ord35, false);
      std::vector<u16> ord37({3, 2, 0, 1});
      slog::Relation* readrel38 = db->getRelation("eval_args");
      eval_argsindex13 = readrel38->getIndex(ord37, false);
      std::vector<u16> ord39({1, 2, 0});
      slog::Relation* readrel40 = db->getRelation("app");
      appindex14 = readrel40->getIndex(ord39, false);
      std::vector<u16> ord41({2, 0, 1});
      slog::Relation* readrel42 = db->getRelation("tick");
      tickindex15 = readrel42->getIndex(ord41, false);
      std::vector<u16> ord43({1, 3, 4, 0, 2});
      slog::Relation* readrel44 = db->getRelation("$sup70016x51x0x0x0");
      $sup70016x51x0x0x0index16 = readrel44->getIndex(ord43, false);
      std::vector<u16> ord45({1, 2, 0});
      slog::Relation* readrel46 = db->getRelation("app");
      appindex17 = readrel46->getIndex(ord45, false);
      std::vector<u16> ord47({1, 3, 2, 0});
      slog::Relation* readrel48 = db->getRelation("eval_args");
      eval_argsindex18 = readrel48->getIndex(ord47, false);
      std::vector<u16> ord49({1, 3, 2, 0});
      slog::Relation* readrel50 = db->getRelation("eval_args");
      eval_argsdelta25 = readrel50->getIndex(ord49, true);
      std::vector<u16> ord51({0, 1});
      slog::Relation* readrel52 = db->getRelation("eval_args_ans");
      eval_args_ansindex19 = readrel52->getIndex(ord51, false);
      std::vector<u16> ord53({1, 2, 0});
      slog::Relation* readrel54 = db->getRelation("app");
      appindex20 = readrel54->getIndex(ord53, false);
      std::vector<u16> ord55({1, 2, 0});
      slog::Relation* readrel56 = db->getRelation("app");
      appdelta26 = readrel56->getIndex(ord55, true);
      std::vector<u16> ord57({1, 2, 0});
      slog::Relation* readrel58 = db->getRelation("tick");
      tickindex21 = readrel58->getIndex(ord57, false);
      std::vector<u16> ord59({1, 2, 0});
      slog::Relation* readrel60 = db->getRelation("tick");
      tickdelta27 = readrel60->getIndex(ord59, true);
      std::vector<u16> ord61({0, 1});
      slog::Relation* readrel62 = db->getRelation("tick_ans");
      tick_ansindex22 = readrel62->getIndex(ord61, false);
      std::vector<u16> ord63({0, 1});
      slog::Relation* readrel64 = db->getRelation("eval_args_ans");
      eval_args_ansindex23 = readrel64->getIndex(ord63, false);
      std::vector<u16> ord65({0, 1});
      slog::Relation* readrel66 = db->getRelation("tick_ans");
      tick_ansindex24 = readrel66->getIndex(ord65, false);
  
    }
    ReadTask28(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c6 = _t[0];
        u64 v_c7 = _t[1];
        u64 v_c8 = _t[2];
        slog::join_probe<2,1>(eval_ansindex10, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m67) {
          u64 v_c9 = m67[1];
          slog::join_probe<3,1>(lambdaindex11, std::array<u64,3>{v_c7, 0, 0}, [&](const std::array<u64,3>& m68) {
            u64 v_c10 = m68[1]; u64 v_c11 = m68[2];
            slog::join_probe<4,1>(evalindex12, std::array<u64,4>{v_c9, 0, 0, 0}, [&](const std::array<u64,4>& m69) {
              u64 v_c12 = m69[1]; u64 v_c13 = m69[2]; u64 v_c14 = m69[3];
              if (!slog::exists_probe<4,2>(eval_argsindex13, std::array<u64,4>{v_c14, v_c13, 0, 0})) return;
              if (!slog::exists_probe<3,1>(appindex14, std::array<u64,3>{v_c12, 0, 0})) return;
              if (!slog::exists_probe<3,1>(tickindex15, std::array<u64,3>{v_c14, 0, 0})) return;
              slog::join_probe<5,3>($sup70016x51x0x0x0index16, std::array<u64,5>{v_c12, v_c13, v_c14, 0, 0}, [&](const std::array<u64,5>& m70) {
                u64 v_c15 = m70[3]; u64 v_c16 = m70[4];
                if (!slog::exists_probe<3,2>(appindex17, std::array<u64,3>{v_c12, v_c16, 0})) return;
                slog::join_probe_old<4,3>(eval_argsindex18, eval_argsdelta25, std::array<u64,4>{v_c16, v_c14, v_c13, 0}, [&](const std::array<u64,4>& m71) {
                  u64 v_c17 = m71[3];
                  if (!slog::exists_probe<2,1>(eval_args_ansindex19, std::array<u64,2>{v_c17, 0})) return;
                  slog::join_probe_old<3,2>(appindex20, appdelta26, std::array<u64,3>{v_c12, v_c16, 0}, [&](const std::array<u64,3>& m72) {
                    u64 v_c18 = m72[2];
                    slog::join_probe_old<3,2>(tickindex21, tickdelta27, std::array<u64,3>{v_c18, v_c14, 0}, [&](const std::array<u64,3>& m73) {
                      u64 v_c19 = m73[2];
                      if (!slog::exists_probe<2,1>(tick_ansindex22, std::array<u64,2>{v_c19, 0})) return;
                      slog::join_probe<2,1>(eval_args_ansindex23, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m74) {
                        u64 v_c20 = m74[1];
                        slog::join_probe<2,1>(tick_ansindex24, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m75) {
                          u64 v_c21 = m75[1];
                          ++_fires;
                          slog::emit<13>(head_rel[0], head_index[0], newbatch[0], std::array<u64,13>{v_c9, v_c8, v_c15, v_c17, v_c19, v_c11, v_c12, v_c16, v_c13, v_c14, v_c21, v_c20, v_c10}, std::array<u16,13>{1, 8, 0, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12});
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
  
      if (_fires) db->bumpFires("interp.slog:52", "delta:closure", _fires);
  
      if (!_done)
      {
        ReadTask28* _cont = new ReadTask28(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask28(db,b), false);
  // (crule (pre (let __tconst4UBH116 const6b86b273ff34fce19d6b804e)) (scan $sup5638x95x0x0x0 __t2hbE115 l m n p q r u v) (body (cmp lt n m) (exists mbranch (1 2 3 4 0) 4 p m l r) (exists mbranch (1 2 3 4 0) 4 q n u v) (exists mp_msk (1 2 0) 2 q m) (exists mp_msk_ans (1 0) 1 p) (exists mp_union (1 2 0) 1 l) (join-old $sup5638x95x0x0x1 (2 3 5 7 0 4 6 8 9 1) 9 (2 3 5 7 0 4 6 8 9 1) l m p r __t2hbE115 n q u v __t27ag118) (exists mp_msk (1 2 0) 3 q m __t27ag118) (exists mp_msk_ans (0 1) 2 __t27ag118 p) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t5EdF114) (exists mp_union (0 1 2) 2 __t2hbE115 __t5EdF114) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t8CES119) (join-old mp_union (0 1 2) 3 (0 1 2) __t2hbE115 __t5EdF114 __t8CES119) (join-old mp_msk (1 2 0) 3 (1 2 0) q m __t27ag118) (join mp_msk_ans (0 1) 2 __t27ag118 p) (join-old mp_union (1 2 0) 2 (1 2 0) l __t8CES119 __t7k4o120) (join mp_union_ans (0 1) 1 __t7k4o120 __v0) (let __t1JZU117 (band q m)) (cmp lt __t1JZU117 __tconst4UBH116)) (head (emit-temp temp3MZb2062 __t2hbE115 __v0 m p r) (mkstruct mbranch (1 2 3 4 0) __t9UHh112 p m __v0 r)) map.slog:96 #f)
  class ReadTask98 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex76;  slog::Index** mbranchindex77;  slog::Index** mp_mskindex78;  slog::Index** mp_msk_ansindex79;  slog::Index** mp_unionindex80;  slog::Index** $sup5638x95x0x0x1index81;  slog::Index** mp_mskindex82;  slog::Index** mp_msk_ansindex83;  slog::Index** mbranchindex84;  slog::Index** mp_unionindex85;  slog::Index** mbranchindex86;  slog::Index** mp_unionindex87;  slog::Index** mp_mskindex88;  slog::Index** mp_msk_ansindex89;  slog::Index** mp_unionindex90;  slog::Index** mp_union_ansindex91;  slog::Index** $sup5638x95x0x0x1delta92;  slog::Index** mbranchdelta93;  slog::Index** mbranchdelta94;  slog::Index** mp_uniondelta95;  slog::Index** mp_mskdelta96;  slog::Index** mp_uniondelta97;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3MZb2062");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("$sup5638x95x0x0x0");
      std::vector<u16> ord99({1, 2, 3, 4, 0});
      slog::Relation* readrel100 = db->getRelation("mbranch");
      mbranchindex76 = readrel100->getIndex(ord99, false);
      std::vector<u16> ord101({1, 2, 3, 4, 0});
      slog::Relation* readrel102 = db->getRelation("mbranch");
      mbranchindex77 = readrel102->getIndex(ord101, false);
      std::vector<u16> ord103({1, 2, 0});
      slog::Relation* readrel104 = db->getRelation("mp_msk");
      mp_mskindex78 = readrel104->getIndex(ord103, false);
      std::vector<u16> ord105({1, 0});
      slog::Relation* readrel106 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex79 = readrel106->getIndex(ord105, false);
      std::vector<u16> ord107({1, 2, 0});
      slog::Relation* readrel108 = db->getRelation("mp_union");
      mp_unionindex80 = readrel108->getIndex(ord107, false);
      std::vector<u16> ord109({2, 3, 5, 7, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel110 = db->getRelation("$sup5638x95x0x0x1");
      $sup5638x95x0x0x1index81 = readrel110->getIndex(ord109, false);
      std::vector<u16> ord111({2, 3, 5, 7, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel112 = db->getRelation("$sup5638x95x0x0x1");
      $sup5638x95x0x0x1delta92 = readrel112->getIndex(ord111, true);
      std::vector<u16> ord113({1, 2, 0});
      slog::Relation* readrel114 = db->getRelation("mp_msk");
      mp_mskindex82 = readrel114->getIndex(ord113, false);
      std::vector<u16> ord115({0, 1});
      slog::Relation* readrel116 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex83 = readrel116->getIndex(ord115, false);
      std::vector<u16> ord117({1, 2, 3, 4, 0});
      slog::Relation* readrel118 = db->getRelation("mbranch");
      mbranchindex84 = readrel118->getIndex(ord117, false);
      std::vector<u16> ord119({1, 2, 3, 4, 0});
      slog::Relation* readrel120 = db->getRelation("mbranch");
      mbranchdelta93 = readrel120->getIndex(ord119, true);
      std::vector<u16> ord121({0, 1, 2});
      slog::Relation* readrel122 = db->getRelation("mp_union");
      mp_unionindex85 = readrel122->getIndex(ord121, false);
      std::vector<u16> ord123({1, 2, 3, 4, 0});
      slog::Relation* readrel124 = db->getRelation("mbranch");
      mbranchindex86 = readrel124->getIndex(ord123, false);
      std::vector<u16> ord125({1, 2, 3, 4, 0});
      slog::Relation* readrel126 = db->getRelation("mbranch");
      mbranchdelta94 = readrel126->getIndex(ord125, true);
      std::vector<u16> ord127({0, 1, 2});
      slog::Relation* readrel128 = db->getRelation("mp_union");
      mp_unionindex87 = readrel128->getIndex(ord127, false);
      std::vector<u16> ord129({0, 1, 2});
      slog::Relation* readrel130 = db->getRelation("mp_union");
      mp_uniondelta95 = readrel130->getIndex(ord129, true);
      std::vector<u16> ord131({1, 2, 0});
      slog::Relation* readrel132 = db->getRelation("mp_msk");
      mp_mskindex88 = readrel132->getIndex(ord131, false);
      std::vector<u16> ord133({1, 2, 0});
      slog::Relation* readrel134 = db->getRelation("mp_msk");
      mp_mskdelta96 = readrel134->getIndex(ord133, true);
      std::vector<u16> ord135({0, 1});
      slog::Relation* readrel136 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex89 = readrel136->getIndex(ord135, false);
      std::vector<u16> ord137({1, 2, 0});
      slog::Relation* readrel138 = db->getRelation("mp_union");
      mp_unionindex90 = readrel138->getIndex(ord137, false);
      std::vector<u16> ord139({1, 2, 0});
      slog::Relation* readrel140 = db->getRelation("mp_union");
      mp_uniondelta97 = readrel140->getIndex(ord139, true);
      std::vector<u16> ord141({0, 1});
      slog::Relation* readrel142 = db->getRelation("mp_union_ans");
      mp_union_ansindex91 = readrel142->getIndex(ord141, false);
  
    }
    ReadTask98(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c22 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
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
        u64 v_c3 = _t[8];
        u64 v_c31 = _prim_lt(db, v_c26, v_c25);
        if (v_c31 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
        if (!v_c31) return;
        if (!slog::exists_probe<5,4>(mbranchindex76, std::array<u64,5>{v_c27, v_c25, v_c24, v_c29, 0})) return;
        if (!slog::exists_probe<5,4>(mbranchindex77, std::array<u64,5>{v_c28, v_c26, v_c30, v_c3, 0})) return;
        if (!slog::exists_probe<3,2>(mp_mskindex78, std::array<u64,3>{v_c28, v_c25, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex79, std::array<u64,2>{v_c27, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex80, std::array<u64,3>{v_c24, 0, 0})) return;
        slog::join_probe_old<10,9>($sup5638x95x0x0x1index81, $sup5638x95x0x0x1delta92, std::array<u64,10>{v_c24, v_c25, v_c27, v_c29, v_c23, v_c26, v_c28, v_c30, v_c3, 0}, [&](const std::array<u64,10>& m144) {
          u64 v_c32 = m144[9];
          if (!slog::exists_probe<3,3>(mp_mskindex82, std::array<u64,3>{v_c28, v_c25, v_c32})) return;
          if (!slog::exists_probe<2,2>(mp_msk_ansindex83, std::array<u64,2>{v_c32, v_c27})) return;
          slog::join_probe_old<5,4>(mbranchindex84, mbranchdelta93, std::array<u64,5>{v_c27, v_c25, v_c24, v_c29, 0}, [&](const std::array<u64,5>& m145) {
            u64 v_c33 = m145[4];
            if (!slog::exists_probe<3,2>(mp_unionindex85, std::array<u64,3>{v_c23, v_c33, 0})) return;
            slog::join_probe_old<5,4>(mbranchindex86, mbranchdelta94, std::array<u64,5>{v_c28, v_c26, v_c30, v_c3, 0}, [&](const std::array<u64,5>& m146) {
              u64 v_c34 = m146[4];
              slog::join_probe_old<3,3>(mp_unionindex87, mp_uniondelta95, std::array<u64,3>{v_c23, v_c33, v_c34}, [&](const std::array<u64,3>& m147) {
                slog::join_probe_old<3,3>(mp_mskindex88, mp_mskdelta96, std::array<u64,3>{v_c28, v_c25, v_c32}, [&](const std::array<u64,3>& m148) {
                  slog::join_probe<2,2>(mp_msk_ansindex89, std::array<u64,2>{v_c32, v_c27}, [&](const std::array<u64,2>& m149) {
                    slog::join_probe_old<3,2>(mp_unionindex90, mp_uniondelta97, std::array<u64,3>{v_c24, v_c34, 0}, [&](const std::array<u64,3>& m150) {
                      u64 v_c35 = m150[2];
                      slog::join_probe<2,1>(mp_union_ansindex91, std::array<u64,2>{v_c35, 0}, [&](const std::array<u64,2>& m151) {
                        u64 v_c36 = m151[1];
                        u64 v_c37 = _prim_band(db, v_c28, v_c25);
                        if (v_c37 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
                        u64 v_c38 = _prim_lt(db, v_c37, v_c22);
                        if (v_c38 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
                        if (!v_c38) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c23, v_c36, v_c25, v_c27, v_c29});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c27, v_c25, v_c36, v_c29}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:96", "delta:$sup5638x95x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask98* _cont = new ReadTask98(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask98(db,b), false);
  // (crule (pre (let __tconst8wBL581 const5feceb66ffc86f38d952786c)) (scan mp_msk_ans __t7zc5584 __v0) (body (join-old mp_msk (0 1 2) 1 (0 1 2) __t7zc5584 k m) (exists mbranch (2 0 1 3 4) 1 m) (exists mp_has0 (2 0 1) 1 k) (join-old $sup5638x59x0x0x0 (1 3 0 2 4 5) 2 (1 3 0 2 4 5) k m __t8lWf583 l p r) (neq p __v0) (exists mp_has0 (0 2 1) 2 __t8lWf583 k) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t0T68582) (join-old mp_has0 (0 2 1) 3 (0 2 1) __t8lWf583 k __t0T68582)) (head (emit mp_has0_ans (0 1) __t8lWf583 __tconst8wBL581)) map.slog:60 #f)
  class ReadTask164 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_mskindex153;  slog::Index** mbranchindex154;  slog::Index** mp_has0index155;  slog::Index** $sup5638x59x0x0x0index156;  slog::Index** mp_has0index157;  slog::Index** mbranchindex158;  slog::Index** mp_has0index159;  slog::Index** mp_mskdelta160;  slog::Index** $sup5638x59x0x0x0delta161;  slog::Index** mbranchdelta162;  slog::Index** mp_has0delta163;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_has0_ans");
      std::vector<u16> ord165({0, 1});
      slog::Relation* readrel166 = db->getRelation("mp_has0_ans");
      head_index[0] = readrel166->getIndex(ord165, false);
      outer_rel = db->getRelation("mp_msk_ans");
      std::vector<u16> ord167({0, 1, 2});
      slog::Relation* readrel168 = db->getRelation("mp_msk");
      mp_mskindex153 = readrel168->getIndex(ord167, false);
      std::vector<u16> ord169({0, 1, 2});
      slog::Relation* readrel170 = db->getRelation("mp_msk");
      mp_mskdelta160 = readrel170->getIndex(ord169, true);
      std::vector<u16> ord171({2, 0, 1, 3, 4});
      slog::Relation* readrel172 = db->getRelation("mbranch");
      mbranchindex154 = readrel172->getIndex(ord171, false);
      std::vector<u16> ord173({2, 0, 1});
      slog::Relation* readrel174 = db->getRelation("mp_has0");
      mp_has0index155 = readrel174->getIndex(ord173, false);
      std::vector<u16> ord175({1, 3, 0, 2, 4, 5});
      slog::Relation* readrel176 = db->getRelation("$sup5638x59x0x0x0");
      $sup5638x59x0x0x0index156 = readrel176->getIndex(ord175, false);
      std::vector<u16> ord177({1, 3, 0, 2, 4, 5});
      slog::Relation* readrel178 = db->getRelation("$sup5638x59x0x0x0");
      $sup5638x59x0x0x0delta161 = readrel178->getIndex(ord177, true);
      std::vector<u16> ord179({0, 2, 1});
      slog::Relation* readrel180 = db->getRelation("mp_has0");
      mp_has0index157 = readrel180->getIndex(ord179, false);
      std::vector<u16> ord181({1, 2, 3, 4, 0});
      slog::Relation* readrel182 = db->getRelation("mbranch");
      mbranchindex158 = readrel182->getIndex(ord181, false);
      std::vector<u16> ord183({1, 2, 3, 4, 0});
      slog::Relation* readrel184 = db->getRelation("mbranch");
      mbranchdelta162 = readrel184->getIndex(ord183, true);
      std::vector<u16> ord185({0, 2, 1});
      slog::Relation* readrel186 = db->getRelation("mp_has0");
      mp_has0index159 = readrel186->getIndex(ord185, false);
      std::vector<u16> ord187({0, 2, 1});
      slog::Relation* readrel188 = db->getRelation("mp_has0");
      mp_has0delta163 = readrel188->getIndex(ord187, true);
  
    }
    ReadTask164(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c39 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c40 = _t[0];
        u64 v_c36 = _t[1];
        slog::join_probe_old<3,1>(mp_mskindex153, mp_mskdelta160, std::array<u64,3>{v_c40, 0, 0}, [&](const std::array<u64,3>& m189) {
          u64 v_c4 = m189[1]; u64 v_c25 = m189[2];
          if (!slog::exists_probe<5,1>(mbranchindex154, std::array<u64,5>{v_c25, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_has0index155, std::array<u64,3>{v_c4, 0, 0})) return;
          slog::join_probe_old<6,2>($sup5638x59x0x0x0index156, $sup5638x59x0x0x0delta161, std::array<u64,6>{v_c4, v_c25, 0, 0, 0, 0}, [&](const std::array<u64,6>& m190) {
            u64 v_c41 = m190[2]; u64 v_c24 = m190[3]; u64 v_c27 = m190[4]; u64 v_c29 = m190[5];
            if (v_c27 == v_c36) return;
            if (!slog::exists_probe<3,2>(mp_has0index157, std::array<u64,3>{v_c41, v_c4, 0})) return;
            slog::join_probe_old<5,4>(mbranchindex158, mbranchdelta162, std::array<u64,5>{v_c27, v_c25, v_c24, v_c29, 0}, [&](const std::array<u64,5>& m191) {
              u64 v_c42 = m191[4];
              slog::join_probe_old<3,3>(mp_has0index159, mp_has0delta163, std::array<u64,3>{v_c41, v_c4, v_c42}, [&](const std::array<u64,3>& m192) {
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c41, v_c39}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:60", "delta:mp_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask164* _cont = new ReadTask164(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask164(db,b), false);
  // (crule (pre) (scan temp9jSj1946 __t5Sgr680 __v0 n q u) (body (join mbranch (1 2 3 4 0) 4 q n u __v0 __t287h677)) (head (emit mp_union_ans (0 1) __t5Sgr680 __t287h677)) map.slog:108 #f)
  class ReadTask194 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex193;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord195({0, 1});
      slog::Relation* readrel196 = db->getRelation("mp_union_ans");
      head_index[0] = readrel196->getIndex(ord195, false);
      outer_rel = db->getRelation("temp9jSj1946");
      std::vector<u16> ord197({1, 2, 3, 4, 0});
      slog::Relation* readrel198 = db->getRelation("mbranch");
      mbranchindex193 = readrel198->getIndex(ord197, false);
  
    }
    ReadTask194(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c43 = _t[0];
        u64 v_c36 = _t[1];
        u64 v_c26 = _t[2];
        u64 v_c28 = _t[3];
        u64 v_c30 = _t[4];
        slog::join_probe<5,4>(mbranchindex193, std::array<u64,5>{v_c28, v_c26, v_c30, v_c36, 0}, [&](const std::array<u64,5>& m199) {
          u64 v_c44 = m199[4];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c43, v_c44}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:108", "delta:temp9jSj1946", _fires);
  
      if (!_done)
      {
        ReadTask194* _cont = new ReadTask194(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask194(db,b), false);
  // (crule (pre (let __tconst7pEc129 const6b86b273ff34fce19d6b804e)) (scan mp_msk __t40jf135 p0 __v1) (body (exists mp_hsb_ans (1 0) 1 __v1) (exists $sup5638x25x0x0x2 (5 7 1 0 2 3 4 6 8 9 10) 2 __v1 p0) (exists $sup5638x25x0x0x1 (3 1 0 2 4 5 6) 1 p0) (exists $sup5638x25x0x0x0 (1 0 2 3 4) 1 p0) (exists mp_join (1 2 3 4 0) 1 p0) (join mp_msk_ans (0 1) 1 __t40jf135 __v2) (join mp_hsb_ans (1 0) 1 __v1 __t0Ayb132) (exists $sup5638x25x0x0x2 (5 7 1 0 2 3 4 6 8 9 10) 3 __v1 p0 __t0Ayb132) (exists $sup5638x25x0x0x1 (3 1 0 2 4 5 6) 2 p0 __t0Ayb132) (exists mp_hsb_ans (0 1) 1 __t0Ayb132) (join mp_hsb_ans (0 1) 1 __t0Ayb132 __v3) (join $sup5638x25x0x0x2 (1 5 6 7 0 2 3 4 8 9 10) 4 __t0Ayb132 __v1 __v3 p0 __t8CpS128 dup4t6F1978 dup2J5X1979 __v0 p1 t0 t1) (eq __t0Ayb132 dup2J5X1979) (eq __t0Ayb132 dup4t6F1978) (join $sup5638x25x0x0x1 (0 3 4 5 6 1 2) 7 __t8CpS128 p0 p1 t0 t1 __t0Ayb132 __v0) (join $sup5638x25x0x0x0 (1 0 2 3 4) 5 p0 __t8CpS128 p1 t0 t1) (join-old mp_join (1 2 3 4 0) 5 (1 2 3 4 0) p0 t0 p1 t1 __t8CpS128) (join mp_hsb_ans (0 1) 2 __t0Ayb132 __v0) (let __t867d136 (bxor p0 p1)) (join-old mp_hsb (0 1) 2 (0 1) __t0Ayb132 __t867d136) (let __t8HR0130 (band p0 __v0)) (cmp lt __t8HR0130 __tconst7pEc129)) (head (emit-temp temp0yve1977 __t8CpS128 __v2 __v3 t0 t1) (mkstruct mbranch (1 2 3 4 0) __t3nlL127 __v2 __v3 t0 t1)) map.slog:26 #f)
  class ReadTask219 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_hsb_ansindex200;  slog::Index** $sup5638x25x0x0x2index201;  slog::Index** $sup5638x25x0x0x1index202;  slog::Index** $sup5638x25x0x0x0index203;  slog::Index** mp_joinindex204;  slog::Index** mp_msk_ansindex205;  slog::Index** mp_hsb_ansindex206;  slog::Index** $sup5638x25x0x0x2index207;  slog::Index** $sup5638x25x0x0x1index208;  slog::Index** mp_hsb_ansindex209;  slog::Index** mp_hsb_ansindex210;  slog::Index** $sup5638x25x0x0x2index211;  slog::Index** $sup5638x25x0x0x1index212;  slog::Index** $sup5638x25x0x0x0index213;  slog::Index** mp_joinindex214;  slog::Index** mp_hsb_ansindex215;  slog::Index** mp_hsbindex216;  slog::Index** mp_joindelta217;  slog::Index** mp_hsbdelta218;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0yve1977");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_msk");
      std::vector<u16> ord220({1, 0});
      slog::Relation* readrel221 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex200 = readrel221->getIndex(ord220, false);
      std::vector<u16> ord222({5, 7, 1, 0, 2, 3, 4, 6, 8, 9, 10});
      slog::Relation* readrel223 = db->getRelation("$sup5638x25x0x0x2");
      $sup5638x25x0x0x2index201 = readrel223->getIndex(ord222, false);
      std::vector<u16> ord224({3, 1, 0, 2, 4, 5, 6});
      slog::Relation* readrel225 = db->getRelation("$sup5638x25x0x0x1");
      $sup5638x25x0x0x1index202 = readrel225->getIndex(ord224, false);
      std::vector<u16> ord226({1, 0, 2, 3, 4});
      slog::Relation* readrel227 = db->getRelation("$sup5638x25x0x0x0");
      $sup5638x25x0x0x0index203 = readrel227->getIndex(ord226, false);
      std::vector<u16> ord228({1, 2, 3, 4, 0});
      slog::Relation* readrel229 = db->getRelation("mp_join");
      mp_joinindex204 = readrel229->getIndex(ord228, false);
      std::vector<u16> ord230({0, 1});
      slog::Relation* readrel231 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex205 = readrel231->getIndex(ord230, false);
      std::vector<u16> ord232({1, 0});
      slog::Relation* readrel233 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex206 = readrel233->getIndex(ord232, false);
      std::vector<u16> ord234({5, 7, 1, 0, 2, 3, 4, 6, 8, 9, 10});
      slog::Relation* readrel235 = db->getRelation("$sup5638x25x0x0x2");
      $sup5638x25x0x0x2index207 = readrel235->getIndex(ord234, false);
      std::vector<u16> ord236({3, 1, 0, 2, 4, 5, 6});
      slog::Relation* readrel237 = db->getRelation("$sup5638x25x0x0x1");
      $sup5638x25x0x0x1index208 = readrel237->getIndex(ord236, false);
      std::vector<u16> ord238({0, 1});
      slog::Relation* readrel239 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex209 = readrel239->getIndex(ord238, false);
      std::vector<u16> ord240({0, 1});
      slog::Relation* readrel241 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex210 = readrel241->getIndex(ord240, false);
      std::vector<u16> ord242({1, 5, 6, 7, 0, 2, 3, 4, 8, 9, 10});
      slog::Relation* readrel243 = db->getRelation("$sup5638x25x0x0x2");
      $sup5638x25x0x0x2index211 = readrel243->getIndex(ord242, false);
      std::vector<u16> ord244({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel245 = db->getRelation("$sup5638x25x0x0x1");
      $sup5638x25x0x0x1index212 = readrel245->getIndex(ord244, false);
      std::vector<u16> ord246({1, 0, 2, 3, 4});
      slog::Relation* readrel247 = db->getRelation("$sup5638x25x0x0x0");
      $sup5638x25x0x0x0index213 = readrel247->getIndex(ord246, false);
      std::vector<u16> ord248({1, 2, 3, 4, 0});
      slog::Relation* readrel249 = db->getRelation("mp_join");
      mp_joinindex214 = readrel249->getIndex(ord248, false);
      std::vector<u16> ord250({1, 2, 3, 4, 0});
      slog::Relation* readrel251 = db->getRelation("mp_join");
      mp_joindelta217 = readrel251->getIndex(ord250, true);
      std::vector<u16> ord252({0, 1});
      slog::Relation* readrel253 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex215 = readrel253->getIndex(ord252, false);
      std::vector<u16> ord254({0, 1});
      slog::Relation* readrel255 = db->getRelation("mp_hsb");
      mp_hsbindex216 = readrel255->getIndex(ord254, false);
      std::vector<u16> ord256({0, 1});
      slog::Relation* readrel257 = db->getRelation("mp_hsb");
      mp_hsbdelta218 = readrel257->getIndex(ord256, true);
  
    }
    ReadTask219(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c45 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c47 = _t[1];
        u64 v_c48 = _t[2];
        if (!slog::exists_probe<2,1>(mp_hsb_ansindex200, std::array<u64,2>{v_c48, 0})) return;
        if (!slog::exists_probe<11,2>($sup5638x25x0x0x2index201, std::array<u64,11>{v_c48, v_c47, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<7,1>($sup5638x25x0x0x1index202, std::array<u64,7>{v_c47, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>($sup5638x25x0x0x0index203, std::array<u64,5>{v_c47, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mp_joinindex204, std::array<u64,5>{v_c47, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(mp_msk_ansindex205, std::array<u64,2>{v_c46, 0}, [&](const std::array<u64,2>& m258) {
          u64 v_c49 = m258[1];
          slog::join_probe<2,1>(mp_hsb_ansindex206, std::array<u64,2>{v_c48, 0}, [&](const std::array<u64,2>& m259) {
            u64 v_c50 = m259[1];
            if (!slog::exists_probe<11,3>($sup5638x25x0x0x2index207, std::array<u64,11>{v_c48, v_c47, v_c50, 0, 0, 0, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<7,2>($sup5638x25x0x0x1index208, std::array<u64,7>{v_c47, v_c50, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<2,1>(mp_hsb_ansindex209, std::array<u64,2>{v_c50, 0})) return;
            slog::join_probe<2,1>(mp_hsb_ansindex210, std::array<u64,2>{v_c50, 0}, [&](const std::array<u64,2>& m260) {
              u64 v_c51 = m260[1];
              slog::join_probe<11,4>($sup5638x25x0x0x2index211, std::array<u64,11>{v_c50, v_c48, v_c51, v_c47, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m261) {
                u64 v_c52 = m261[4]; u64 v_c53 = m261[5]; u64 v_c54 = m261[6]; u64 v_c36 = m261[7]; u64 v_c55 = m261[8]; u64 v_c56 = m261[9]; u64 v_c57 = m261[10];
                if (v_c50 != v_c54) return;
                if (v_c50 != v_c53) return;
                slog::join_probe<7,7>($sup5638x25x0x0x1index212, std::array<u64,7>{v_c52, v_c47, v_c55, v_c56, v_c57, v_c50, v_c36}, [&](const std::array<u64,7>& m262) {
                  slog::join_probe<5,5>($sup5638x25x0x0x0index213, std::array<u64,5>{v_c47, v_c52, v_c55, v_c56, v_c57}, [&](const std::array<u64,5>& m263) {
                    slog::join_probe_old<5,5>(mp_joinindex214, mp_joindelta217, std::array<u64,5>{v_c47, v_c56, v_c55, v_c57, v_c52}, [&](const std::array<u64,5>& m264) {
                      slog::join_probe<2,2>(mp_hsb_ansindex215, std::array<u64,2>{v_c50, v_c36}, [&](const std::array<u64,2>& m265) {
                        u64 v_c58 = _prim_bxor(db, v_c47, v_c55);
                        if (v_c58 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                        slog::join_probe_old<2,2>(mp_hsbindex216, mp_hsbdelta218, std::array<u64,2>{v_c50, v_c58}, [&](const std::array<u64,2>& m266) {
                          u64 v_c59 = _prim_band(db, v_c47, v_c36);
                          if (v_c59 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                          u64 v_c60 = _prim_lt(db, v_c59, v_c45);
                          if (v_c60 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                          if (!v_c60) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c52, v_c49, v_c51, v_c56, v_c57});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c49, v_c51, v_c56, v_c57}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:26", "delta:mp_msk", _fires);
  
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
  // (crule (pre (let __trid9sn11341 const521b2193c302e05f0bbf60da) (let __trel5bLw1342 constb642bb32c0b8fd35118770e8) (let __tcol7oJ51343 const5feceb66ffc86f38d952786c) (let __trel6zpS1344 constb642bb32c0b8fd35118770e8) (let __tcol4MTz1345 const6b86b273ff34fce19d6b804e)) (scan $sup5638x51x0x0x0 __d0 k l m p r) (body) (head (tycheck l (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid9sn11341 __trel5bLw1342 __tcol7oJ51343 (1 2 3 4 0)) (tycheck k (accept int) __trid9sn11341 __trel6zpS1344 __tcol4MTz1345 (1 2 3 4 0)) (mkstruct mp_get (1 2 0) __2GpZ1340 l k)) map.slog:52 #f)
  class ReadTask271 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid269;  u32 sid268;  u32 sid270;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("mp_get");
      outer_rel = db->getRelation("$sup5638x51x0x0x0");
      sid269 = db->getRelation("_enum")->getStructId();
      sid268 = db->getRelation("mbranch")->getStructId();
      sid270 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask271(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c61 = v_const521b2193c302e05f0bbf60da;
      u64 v_c62 = v_constb642bb32c0b8fd35118770e8;
      u64 v_c63 = v_const5feceb66ffc86f38d952786c;
      u64 v_c64 = v_constb642bb32c0b8fd35118770e8;
      u64 v_c65 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c15 = _t[0];
        u64 v_c4 = _t[1];
        u64 v_c24 = _t[2];
        u64 v_c25 = _t[3];
        u64 v_c27 = _t[4];
        u64 v_c29 = _t[5];
        ++_fires;
        if (!((is_struct(v_c24) && (decode_struct_id(v_c24) == sid268 || decode_struct_id(v_c24) == sid269 || decode_struct_id(v_c24) == sid270))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c61, v_c62, v_c63, v_c24}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c4)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c61, v_c64, v_c65, v_c4}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c24, v_c4}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:52", "delta:$sup5638x51x0x0x0", _fires);
  
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
  // (crule (pre) (scan prim __t21iW553 op) (body (join eval_ans (1 0) 1 __t21iW553 __t6oYx552) (join eval (0 1 2 3) 1 __t6oYx552 ef rho t) (exists eval_args (3 2 0 1) 2 t rho) (join $sup70016x75x0x0x0 (1 3 4 2 0) 3 ef rho t es __d0) (join-old eval_args (1 3 2 0) 3 (1 3 2 0) es t rho __t11mn554) (join eval_args_ans (0 1) 1 __t11mn554 vs)) (head (mkstruct delta (1 2 0) __5Kx31559 op vs)) interp.slog:76 #f)
  class ReadTask279 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eval_ansindex272;  slog::Index** evalindex273;  slog::Index** eval_argsindex274;  slog::Index** $sup70016x75x0x0x0index275;  slog::Index** eval_argsindex276;  slog::Index** eval_args_ansindex277;  slog::Index** eval_argsdelta278;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("delta");
      outer_rel = db->getRelation("prim");
      std::vector<u16> ord280({1, 0});
      slog::Relation* readrel281 = db->getRelation("eval_ans");
      eval_ansindex272 = readrel281->getIndex(ord280, false);
      std::vector<u16> ord282({0, 1, 2, 3});
      slog::Relation* readrel283 = db->getRelation("eval");
      evalindex273 = readrel283->getIndex(ord282, false);
      std::vector<u16> ord284({3, 2, 0, 1});
      slog::Relation* readrel285 = db->getRelation("eval_args");
      eval_argsindex274 = readrel285->getIndex(ord284, false);
      std::vector<u16> ord286({1, 3, 4, 2, 0});
      slog::Relation* readrel287 = db->getRelation("$sup70016x75x0x0x0");
      $sup70016x75x0x0x0index275 = readrel287->getIndex(ord286, false);
      std::vector<u16> ord288({1, 3, 2, 0});
      slog::Relation* readrel289 = db->getRelation("eval_args");
      eval_argsindex276 = readrel289->getIndex(ord288, false);
      std::vector<u16> ord290({1, 3, 2, 0});
      slog::Relation* readrel291 = db->getRelation("eval_args");
      eval_argsdelta278 = readrel291->getIndex(ord290, true);
      std::vector<u16> ord292({0, 1});
      slog::Relation* readrel293 = db->getRelation("eval_args_ans");
      eval_args_ansindex277 = readrel293->getIndex(ord292, false);
  
    }
    ReadTask279(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe<2,1>(eval_ansindex272, std::array<u64,2>{v_c66, 0}, [&](const std::array<u64,2>& m294) {
          u64 v_c68 = m294[1];
          slog::join_probe<4,1>(evalindex273, std::array<u64,4>{v_c68, 0, 0, 0}, [&](const std::array<u64,4>& m295) {
            u64 v_c12 = m295[1]; u64 v_c13 = m295[2]; u64 v_c14 = m295[3];
            if (!slog::exists_probe<4,2>(eval_argsindex274, std::array<u64,4>{v_c14, v_c13, 0, 0})) return;
            slog::join_probe<5,3>($sup70016x75x0x0x0index275, std::array<u64,5>{v_c12, v_c13, v_c14, 0, 0}, [&](const std::array<u64,5>& m296) {
              u64 v_c16 = m296[3]; u64 v_c15 = m296[4];
              slog::join_probe_old<4,3>(eval_argsindex276, eval_argsdelta278, std::array<u64,4>{v_c16, v_c14, v_c13, 0}, [&](const std::array<u64,4>& m297) {
                u64 v_c69 = m297[3];
                slog::join_probe<2,1>(eval_args_ansindex277, std::array<u64,2>{v_c69, 0}, [&](const std::array<u64,2>& m298) {
                  u64 v_c20 = m298[1];
                  ++_fires;
                  slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c67, v_c20}, std::array<u16,3>{1, 2, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:76", "delta:prim", _fires);
  
      if (!_done)
      {
        ReadTask279* _cont = new ReadTask279(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask279(db,b), false);
  // (crule (pre) (scan eval __t5IFg653 __t4xHt652 rho t) (body (join sym (0 1) 1 __t4xHt652 s)) (head (emit-temp temp9x9w1897 __t5IFg653 s) (mkstruct symval (1 0) __t2tjI651 s)) interp.slog:32 #f)
  class ReadTask300 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** symindex299;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9x9w1897");
      head_rel[1] = db->getRelation("symval");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord301({0, 1});
      slog::Relation* readrel302 = db->getRelation("sym");
      symindex299 = readrel302->getIndex(ord301, false);
  
    }
    ReadTask300(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c70 = _t[0];
        u64 v_c71 = _t[1];
        u64 v_c13 = _t[2];
        u64 v_c14 = _t[3];
        slog::join_probe<2,1>(symindex299, std::array<u64,2>{v_c71, 0}, [&](const std::array<u64,2>& m303) {
          u64 v_c72 = m303[1];
          ++_fires;
          slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c70, v_c72});
          slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c72}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:32", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask300* _cont = new ReadTask300(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask300(db,b), false);
  // (crule (pre) (scan mbranch __t04LR600 p m l r) (body (exists mp_union (1 2 0) 1 __t04LR600) (join mbranch (1 2 3 4 0) 2 p m u v __t7y6C599) (join-old mp_union (1 2 0) 2 (1 2 0) __t04LR600 __t7y6C599 __t2zhu601)) (head (emit $sup5638x93x0x0x0 (0 1 2 3 4 5 6) __t2zhu601 l m p r u v)) map.slog:94 #f)
  class ReadTask308 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex304;  slog::Index** mbranchindex305;  slog::Index** mp_unionindex306;  slog::Index** mp_uniondelta307;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x93x0x0x0");
      std::vector<u16> ord309({0, 1, 2, 3, 4, 5, 6});
      slog::Relation* readrel310 = db->getRelation("$sup5638x93x0x0x0");
      head_index[0] = readrel310->getIndex(ord309, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord311({1, 2, 0});
      slog::Relation* readrel312 = db->getRelation("mp_union");
      mp_unionindex304 = readrel312->getIndex(ord311, false);
      std::vector<u16> ord313({1, 2, 3, 4, 0});
      slog::Relation* readrel314 = db->getRelation("mbranch");
      mbranchindex305 = readrel314->getIndex(ord313, false);
      std::vector<u16> ord315({1, 2, 0});
      slog::Relation* readrel316 = db->getRelation("mp_union");
      mp_unionindex306 = readrel316->getIndex(ord315, false);
      std::vector<u16> ord317({1, 2, 0});
      slog::Relation* readrel318 = db->getRelation("mp_union");
      mp_uniondelta307 = readrel318->getIndex(ord317, true);
  
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
        u64 v_c73 = _t[0];
        u64 v_c27 = _t[1];
        u64 v_c25 = _t[2];
        u64 v_c24 = _t[3];
        u64 v_c29 = _t[4];
        if (!slog::exists_probe<3,1>(mp_unionindex304, std::array<u64,3>{v_c73, 0, 0})) return;
        slog::join_probe<5,2>(mbranchindex305, std::array<u64,5>{v_c27, v_c25, 0, 0, 0}, [&](const std::array<u64,5>& m319) {
          u64 v_c30 = m319[2]; u64 v_c3 = m319[3]; u64 v_c74 = m319[4];
          slog::join_probe_old<3,2>(mp_unionindex306, mp_uniondelta307, std::array<u64,3>{v_c73, v_c74, 0}, [&](const std::array<u64,3>& m320) {
            u64 v_c75 = m320[2];
            ++_fires;
            slog::emit<7>(head_rel[0], head_index[0], newbatch[0], std::array<u64,7>{v_c75, v_c24, v_c25, v_c27, v_c29, v_c30, v_c3}, std::array<u16,7>{0, 1, 2, 3, 4, 5, 6});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:94", "delta:mbranch", _fires);
  
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
  // (crule (pre) (scan mp_join __t6UVn392 p __t6AX6390 q __t46nL391) (body (exists mbranch (0 1 2 3 4) 2 __t6AX6390 p) (exists mbranch (0 1 2 3 4) 2 __t46nL391 q) (exists mp_union (1 2 0) 2 __t6AX6390 __t46nL391) (exists mp_msk (1 2 0) 1 p) (exists mp_join_ans (0 1) 1 __t6UVn392) (join $sup5638x110x0x0x0 (4 5 7 8 0 1 2 3 6 9 10) 4 p q __t6AX6390 __t46nL391 __t5Qtl389 l m n r u v) (cmp lt m n) (join mbranch (1 2 3 4 0) 5 p m l r __t6AX6390) (join mbranch (1 2 3 4 0) 5 q n u v __t46nL391) (join mp_union (0 1 2) 3 __t5Qtl389 __t6AX6390 __t46nL391) (join-old mp_msk (1 2 0) 2 (1 2 0) p n __t827P393) (join mp_msk_ans (0 1) 1 __t827P393 __v0) (neq q __v0) (join mp_join_ans (0 1) 1 __t6UVn392 res)) (head (emit mp_union_ans (0 1) __t5Qtl389 res)) map.slog:111 #f)
  class ReadTask334 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex321;  slog::Index** mbranchindex322;  slog::Index** mp_unionindex323;  slog::Index** mp_mskindex324;  slog::Index** mp_join_ansindex325;  slog::Index** $sup5638x110x0x0x0index326;  slog::Index** mbranchindex327;  slog::Index** mbranchindex328;  slog::Index** mp_unionindex329;  slog::Index** mp_mskindex330;  slog::Index** mp_msk_ansindex331;  slog::Index** mp_join_ansindex332;  slog::Index** mp_mskdelta333;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord335({0, 1});
      slog::Relation* readrel336 = db->getRelation("mp_union_ans");
      head_index[0] = readrel336->getIndex(ord335, false);
      outer_rel = db->getRelation("mp_join");
      std::vector<u16> ord337({0, 1, 2, 3, 4});
      slog::Relation* readrel338 = db->getRelation("mbranch");
      mbranchindex321 = readrel338->getIndex(ord337, false);
      std::vector<u16> ord339({0, 1, 2, 3, 4});
      slog::Relation* readrel340 = db->getRelation("mbranch");
      mbranchindex322 = readrel340->getIndex(ord339, false);
      std::vector<u16> ord341({1, 2, 0});
      slog::Relation* readrel342 = db->getRelation("mp_union");
      mp_unionindex323 = readrel342->getIndex(ord341, false);
      std::vector<u16> ord343({1, 2, 0});
      slog::Relation* readrel344 = db->getRelation("mp_msk");
      mp_mskindex324 = readrel344->getIndex(ord343, false);
      std::vector<u16> ord345({0, 1});
      slog::Relation* readrel346 = db->getRelation("mp_join_ans");
      mp_join_ansindex325 = readrel346->getIndex(ord345, false);
      std::vector<u16> ord347({4, 5, 7, 8, 0, 1, 2, 3, 6, 9, 10});
      slog::Relation* readrel348 = db->getRelation("$sup5638x110x0x0x0");
      $sup5638x110x0x0x0index326 = readrel348->getIndex(ord347, false);
      std::vector<u16> ord349({1, 2, 3, 4, 0});
      slog::Relation* readrel350 = db->getRelation("mbranch");
      mbranchindex327 = readrel350->getIndex(ord349, false);
      std::vector<u16> ord351({1, 2, 3, 4, 0});
      slog::Relation* readrel352 = db->getRelation("mbranch");
      mbranchindex328 = readrel352->getIndex(ord351, false);
      std::vector<u16> ord353({0, 1, 2});
      slog::Relation* readrel354 = db->getRelation("mp_union");
      mp_unionindex329 = readrel354->getIndex(ord353, false);
      std::vector<u16> ord355({1, 2, 0});
      slog::Relation* readrel356 = db->getRelation("mp_msk");
      mp_mskindex330 = readrel356->getIndex(ord355, false);
      std::vector<u16> ord357({1, 2, 0});
      slog::Relation* readrel358 = db->getRelation("mp_msk");
      mp_mskdelta333 = readrel358->getIndex(ord357, true);
      std::vector<u16> ord359({0, 1});
      slog::Relation* readrel360 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex331 = readrel360->getIndex(ord359, false);
      std::vector<u16> ord361({0, 1});
      slog::Relation* readrel362 = db->getRelation("mp_join_ans");
      mp_join_ansindex332 = readrel362->getIndex(ord361, false);
  
    }
    ReadTask334(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c76 = _t[0];
        u64 v_c27 = _t[1];
        u64 v_c77 = _t[2];
        u64 v_c28 = _t[3];
        u64 v_c78 = _t[4];
        if (!slog::exists_probe<5,2>(mbranchindex321, std::array<u64,5>{v_c77, v_c27, 0, 0, 0})) return;
        if (!slog::exists_probe<5,2>(mbranchindex322, std::array<u64,5>{v_c78, v_c28, 0, 0, 0})) return;
        if (!slog::exists_probe<3,2>(mp_unionindex323, std::array<u64,3>{v_c77, v_c78, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex324, std::array<u64,3>{v_c27, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_join_ansindex325, std::array<u64,2>{v_c76, 0})) return;
        slog::join_probe<11,4>($sup5638x110x0x0x0index326, std::array<u64,11>{v_c27, v_c28, v_c77, v_c78, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m363) {
          u64 v_c79 = m363[4]; u64 v_c24 = m363[5]; u64 v_c25 = m363[6]; u64 v_c26 = m363[7]; u64 v_c29 = m363[8]; u64 v_c30 = m363[9]; u64 v_c3 = m363[10];
          u64 v_c80 = _prim_lt(db, v_c25, v_c26);
          if (v_c80 == slog_error) { slog::emit_pending_error(db, "map.slog:111"); return; }
          if (!v_c80) return;
          slog::join_probe<5,5>(mbranchindex327, std::array<u64,5>{v_c27, v_c25, v_c24, v_c29, v_c77}, [&](const std::array<u64,5>& m365) {
            slog::join_probe<5,5>(mbranchindex328, std::array<u64,5>{v_c28, v_c26, v_c30, v_c3, v_c78}, [&](const std::array<u64,5>& m366) {
              slog::join_probe<3,3>(mp_unionindex329, std::array<u64,3>{v_c79, v_c77, v_c78}, [&](const std::array<u64,3>& m367) {
                slog::join_probe_old<3,2>(mp_mskindex330, mp_mskdelta333, std::array<u64,3>{v_c27, v_c26, 0}, [&](const std::array<u64,3>& m368) {
                  u64 v_c81 = m368[2];
                  slog::join_probe<2,1>(mp_msk_ansindex331, std::array<u64,2>{v_c81, 0}, [&](const std::array<u64,2>& m369) {
                    u64 v_c36 = m369[1];
                    if (v_c28 == v_c36) return;
                    slog::join_probe<2,1>(mp_join_ansindex332, std::array<u64,2>{v_c76, 0}, [&](const std::array<u64,2>& m370) {
                      u64 v_c82 = m370[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c79, v_c82}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:111", "delta:mp_join", _fires);
  
      if (!_done)
      {
        ReadTask334* _cont = new ReadTask334(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask334(db,b), false);
  // (crule (pre) (scan $sup5638x101x0x0x0 __t5awj693 l m n p q r __t1ouF694 __t1a8C695 u v) (body (cmp lt n m) (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) p m l r __t1ouF694) (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) q n u v __t1a8C695) (exists mp_union (0 1 2) 3 __t5awj693 __t1ouF694 __t1a8C695) (exists mp_msk (1 2 0) 2 q m) (join-old mp_join (1 2 3 4 0) 4 (1 2 3 4 0) p __t1ouF694 q __t1a8C695 __t8BsD696) (join-old mp_union (0 1 2) 3 (0 1 2) __t5awj693 __t1ouF694 __t1a8C695) (exists mp_join_ans (0 1) 1 __t8BsD696) (join-old mp_msk (1 2 0) 2 (1 2 0) q m __t84wf697) (join mp_msk_ans (0 1) 1 __t84wf697 __v0) (neq p __v0) (join mp_join_ans (0 1) 1 __t8BsD696 res)) (head (emit mp_union_ans (0 1) __t5awj693 res)) map.slog:102 #f)
  class ReadTask386 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex371;  slog::Index** mbranchindex372;  slog::Index** mp_unionindex373;  slog::Index** mp_mskindex374;  slog::Index** mp_joinindex375;  slog::Index** mp_unionindex376;  slog::Index** mp_join_ansindex377;  slog::Index** mp_mskindex378;  slog::Index** mp_msk_ansindex379;  slog::Index** mp_join_ansindex380;  slog::Index** mbranchdelta381;  slog::Index** mbranchdelta382;  slog::Index** mp_joindelta383;  slog::Index** mp_uniondelta384;  slog::Index** mp_mskdelta385;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord387({0, 1});
      slog::Relation* readrel388 = db->getRelation("mp_union_ans");
      head_index[0] = readrel388->getIndex(ord387, false);
      outer_rel = db->getRelation("$sup5638x101x0x0x0");
      std::vector<u16> ord389({1, 2, 3, 4, 0});
      slog::Relation* readrel390 = db->getRelation("mbranch");
      mbranchindex371 = readrel390->getIndex(ord389, false);
      std::vector<u16> ord391({1, 2, 3, 4, 0});
      slog::Relation* readrel392 = db->getRelation("mbranch");
      mbranchdelta381 = readrel392->getIndex(ord391, true);
      std::vector<u16> ord393({1, 2, 3, 4, 0});
      slog::Relation* readrel394 = db->getRelation("mbranch");
      mbranchindex372 = readrel394->getIndex(ord393, false);
      std::vector<u16> ord395({1, 2, 3, 4, 0});
      slog::Relation* readrel396 = db->getRelation("mbranch");
      mbranchdelta382 = readrel396->getIndex(ord395, true);
      std::vector<u16> ord397({0, 1, 2});
      slog::Relation* readrel398 = db->getRelation("mp_union");
      mp_unionindex373 = readrel398->getIndex(ord397, false);
      std::vector<u16> ord399({1, 2, 0});
      slog::Relation* readrel400 = db->getRelation("mp_msk");
      mp_mskindex374 = readrel400->getIndex(ord399, false);
      std::vector<u16> ord401({1, 2, 3, 4, 0});
      slog::Relation* readrel402 = db->getRelation("mp_join");
      mp_joinindex375 = readrel402->getIndex(ord401, false);
      std::vector<u16> ord403({1, 2, 3, 4, 0});
      slog::Relation* readrel404 = db->getRelation("mp_join");
      mp_joindelta383 = readrel404->getIndex(ord403, true);
      std::vector<u16> ord405({0, 1, 2});
      slog::Relation* readrel406 = db->getRelation("mp_union");
      mp_unionindex376 = readrel406->getIndex(ord405, false);
      std::vector<u16> ord407({0, 1, 2});
      slog::Relation* readrel408 = db->getRelation("mp_union");
      mp_uniondelta384 = readrel408->getIndex(ord407, true);
      std::vector<u16> ord409({0, 1});
      slog::Relation* readrel410 = db->getRelation("mp_join_ans");
      mp_join_ansindex377 = readrel410->getIndex(ord409, false);
      std::vector<u16> ord411({1, 2, 0});
      slog::Relation* readrel412 = db->getRelation("mp_msk");
      mp_mskindex378 = readrel412->getIndex(ord411, false);
      std::vector<u16> ord413({1, 2, 0});
      slog::Relation* readrel414 = db->getRelation("mp_msk");
      mp_mskdelta385 = readrel414->getIndex(ord413, true);
      std::vector<u16> ord415({0, 1});
      slog::Relation* readrel416 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex379 = readrel416->getIndex(ord415, false);
      std::vector<u16> ord417({0, 1});
      slog::Relation* readrel418 = db->getRelation("mp_join_ans");
      mp_join_ansindex380 = readrel418->getIndex(ord417, false);
  
    }
    ReadTask386(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c83 = _t[0];
        u64 v_c24 = _t[1];
        u64 v_c25 = _t[2];
        u64 v_c26 = _t[3];
        u64 v_c27 = _t[4];
        u64 v_c28 = _t[5];
        u64 v_c29 = _t[6];
        u64 v_c84 = _t[7];
        u64 v_c85 = _t[8];
        u64 v_c30 = _t[9];
        u64 v_c3 = _t[10];
        u64 v_c86 = _prim_lt(db, v_c26, v_c25);
        if (v_c86 == slog_error) { slog::emit_pending_error(db, "map.slog:102"); return; }
        if (!v_c86) return;
        slog::join_probe_old<5,5>(mbranchindex371, mbranchdelta381, std::array<u64,5>{v_c27, v_c25, v_c24, v_c29, v_c84}, [&](const std::array<u64,5>& m420) {
          slog::join_probe_old<5,5>(mbranchindex372, mbranchdelta382, std::array<u64,5>{v_c28, v_c26, v_c30, v_c3, v_c85}, [&](const std::array<u64,5>& m421) {
            if (!slog::exists_probe<3,3>(mp_unionindex373, std::array<u64,3>{v_c83, v_c84, v_c85})) return;
            if (!slog::exists_probe<3,2>(mp_mskindex374, std::array<u64,3>{v_c28, v_c25, 0})) return;
            slog::join_probe_old<5,4>(mp_joinindex375, mp_joindelta383, std::array<u64,5>{v_c27, v_c84, v_c28, v_c85, 0}, [&](const std::array<u64,5>& m422) {
              u64 v_c87 = m422[4];
              slog::join_probe_old<3,3>(mp_unionindex376, mp_uniondelta384, std::array<u64,3>{v_c83, v_c84, v_c85}, [&](const std::array<u64,3>& m423) {
                if (!slog::exists_probe<2,1>(mp_join_ansindex377, std::array<u64,2>{v_c87, 0})) return;
                slog::join_probe_old<3,2>(mp_mskindex378, mp_mskdelta385, std::array<u64,3>{v_c28, v_c25, 0}, [&](const std::array<u64,3>& m424) {
                  u64 v_c88 = m424[2];
                  slog::join_probe<2,1>(mp_msk_ansindex379, std::array<u64,2>{v_c88, 0}, [&](const std::array<u64,2>& m425) {
                    u64 v_c36 = m425[1];
                    if (v_c27 == v_c36) return;
                    slog::join_probe<2,1>(mp_join_ansindex380, std::array<u64,2>{v_c87, 0}, [&](const std::array<u64,2>& m426) {
                      u64 v_c82 = m426[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c83, v_c82}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:102", "delta:$sup5638x101x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask386* _cont = new ReadTask386(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask386(db,b), false);
  // (crule (pre (let __trid3fDE1468 constde34af73616246ffdc2cc593) (let __trel6J4k1469 conste90c92f3e6c3b47a7bc93e42) (let __tcol8unt1470 const5feceb66ffc86f38d952786c) (let __trel0jNW1471 conste90c92f3e6c3b47a7bc93e42) (let __tcol8rhY1472 const6b86b273ff34fce19d6b804e) (let __trel9AUZ1473 conste90c92f3e6c3b47a7bc93e42) (let __tcol7Vgw1474 constd4735e3a265e16eee03f5971)) (scan $sup70016x43x0x0x0 _00024seq0 __d0 e es rho t) (body) (head (tycheck es (accept seq) __trid3fDE1468 __trel6J4k1469 __tcol8unt1470 (1 2 3 4 0)) (tycheck rho (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid3fDE1468 __trel0jNW1471 __tcol8rhY1472 (1 2 3 4 0)) (tycheck t (accept seq) __trid3fDE1468 __trel9AUZ1473 __tcol7Vgw1474 (1 2 3 4 0)) (mkstruct eval_args (1 3 2 0) __5XhH1467 es t rho)) interp.slog:44 #f)
  class ReadTask430 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[4];
    slog::Index** head_index[4];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid428;  u32 sid427;  u32 sid429;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("malformed_deduction");
      head_rel[3] = db->getRelation("eval_args");
      outer_rel = db->getRelation("$sup70016x43x0x0x0");
      sid428 = db->getRelation("_enum")->getStructId();
      sid427 = db->getRelation("mbranch")->getStructId();
      sid429 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask430(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c89 = v_constde34af73616246ffdc2cc593;
      u64 v_c90 = v_conste90c92f3e6c3b47a7bc93e42;
      u64 v_c91 = v_const5feceb66ffc86f38d952786c;
      u64 v_c92 = v_conste90c92f3e6c3b47a7bc93e42;
      u64 v_c93 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c94 = v_conste90c92f3e6c3b47a7bc93e42;
      u64 v_c95 = v_constd4735e3a265e16eee03f5971;
  
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
        u64 v_c96 = _t[0];
        u64 v_c15 = _t[1];
        u64 v_c97 = _t[2];
        u64 v_c16 = _t[3];
        u64 v_c13 = _t[4];
        u64 v_c14 = _t[5];
        ++_fires;
        if (!(is_seq(v_c16)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c89, v_c90, v_c91, v_c16}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c13) && (decode_struct_id(v_c13) == sid427 || decode_struct_id(v_c13) == sid428 || decode_struct_id(v_c13) == sid429))))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c89, v_c92, v_c93, v_c13}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_seq(v_c14)))
        {
          slog::emit_struct<5>(head_rel[2], newbatch[2], std::array<u64,4>{v_c89, v_c94, v_c95, v_c14}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<4>(head_rel[3], newbatch[3], std::array<u64,3>{v_c16, v_c14, v_c13}, std::array<u16,4>{1, 3, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
  
      if (_fires) db->bumpFires("interp.slog:44", "delta:$sup70016x43x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask430* _cont = new ReadTask430(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask430(db,b), false);
  // (crule (pre (let __tconst5rYq1261 constd01925b37634a1a9d24159d8)) (scan mp_union __t9IWG270 s __t1UKh269) (body (join _enum (0 1) 2 __t1UKh269 __tconst5rYq1261)) (head (emit mp_union_ans (0 1) __t9IWG270 s)) map.slog:91 #f)
  class ReadTask432 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex431;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord433({0, 1});
      slog::Relation* readrel434 = db->getRelation("mp_union_ans");
      head_index[0] = readrel434->getIndex(ord433, false);
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord435({0, 1});
      slog::Relation* readrel436 = db->getRelation("_enum");
      _enumindex431 = readrel436->getIndex(ord435, false);
  
    }
    ReadTask432(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c98 = v_constd01925b37634a1a9d24159d8;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c99 = _t[0];
        u64 v_c72 = _t[1];
        u64 v_c100 = _t[2];
        slog::join_probe<2,2>(_enumindex431, std::array<u64,2>{v_c100, v_c98}, [&](const std::array<u64,2>& m437) {
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c99, v_c72}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:91", "delta:mp_union", _fires);
  
      if (!_done)
      {
        ReadTask432* _cont = new ReadTask432(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask432(db,b), false);
  // (crule (pre) (scan mp_del __t4dB9286 __t8lCA285 k) (body (join mbranch (0 1 2 3 4) 1 __t8lCA285 p m l r)) (head (emit $sup5638x81x0x0x0 (0 1 2 3 4 5) __t4dB9286 k l m p r)) map.slog:82 #f)
  class ReadTask439 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex438;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x81x0x0x0");
      std::vector<u16> ord440({0, 1, 2, 3, 4, 5});
      slog::Relation* readrel441 = db->getRelation("$sup5638x81x0x0x0");
      head_index[0] = readrel441->getIndex(ord440, false);
      outer_rel = db->getRelation("mp_del");
      std::vector<u16> ord442({0, 1, 2, 3, 4});
      slog::Relation* readrel443 = db->getRelation("mbranch");
      mbranchindex438 = readrel443->getIndex(ord442, false);
  
    }
    ReadTask439(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c101 = _t[0];
        u64 v_c102 = _t[1];
        u64 v_c4 = _t[2];
        slog::join_probe<5,1>(mbranchindex438, std::array<u64,5>{v_c102, 0, 0, 0, 0}, [&](const std::array<u64,5>& m444) {
          u64 v_c27 = m444[1]; u64 v_c25 = m444[2]; u64 v_c24 = m444[3]; u64 v_c29 = m444[4];
          ++_fires;
          slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c101, v_c4, v_c24, v_c25, v_c27, v_c29}, std::array<u16,6>{0, 1, 2, 3, 4, 5});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:82", "delta:mp_del", _fires);
  
      if (!_done)
      {
        ReadTask439* _cont = new ReadTask439(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask439(db,b), false);
  // (crule (pre (let _00024sqc250U943 const6b86b273ff34fce19d6b804e) (let _00024sqc6BYS944 const5feceb66ffc86f38d952786c) (let _00024sqc0VjW945 const6b86b273ff34fce19d6b804e) (let _00024sqc8uew946 const5feceb66ffc86f38d952786c) (let _00024sqo2y2x951 const5feceb66ffc86f38d952786c) (let __t6qtm791 (lempty))) (scan eval_ans __t7vCW795 __v0) (body (join-old $seq_at (1 0 2) 1 (1 0 2) _00024sqo2y2x951 e _00024seq0) (exists $sup70016x43x0x0x0 (0 2 3 4 5 1) 2 _00024seq0 e) (exists eval_args (1 3 2 0) 1 _00024seq0) (join-old eval (0 1 2 3) 2 (0 1 2 3) __t7vCW795 e rho t) (letp _00024sql7raK941 (aslst _00024seq0)) (let _00024sqn1wbQ942 (llen _00024sql7raK941)) (cmp ge _00024sqn1wbQ942 _00024sqc250U943) (let _00024sqp9fgp947 (_0002d _00024sqn1wbQ942 _00024sqc8uew946)) (let es (lslice _00024sql7raK941 _00024sqc0VjW945 _00024sqp9fgp947)) (exists eval_args (1 3 2 0) 3 _00024seq0 t rho) (exists eval_args (1 3 2 0) 3 es t rho) (join-old $sup70016x43x0x0x0 (0 2 3 4 5 1) 5 (0 2 3 4 5 1) _00024seq0 e es rho t __t7ZV0794) (join-old eval_args (3 2 0 1) 4 (3 2 0 1) t rho __t7ZV0794 _00024seq0) (join-old eval_args (1 3 2 0) 3 (1 3 2 0) es t rho __t9m2L796) (join-old eval_args_ans (0 1) 1 (0 1) __t9m2L796 __v1) (letp chk4vLf2036 (lref _00024sql7raK941 _00024sqc6BYS944)) (eq e chk4vLf2036)) (head (emit-temp temp2swd2033 __t6qtm791 __t7ZV0794 __v0 __v1)) interp.slog:44 #f)
  class ReadTask461 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $seq_atindex445;  slog::Index** $sup70016x43x0x0x0index446;  slog::Index** eval_argsindex447;  slog::Index** evalindex448;  slog::Index** eval_argsindex449;  slog::Index** eval_argsindex450;  slog::Index** $sup70016x43x0x0x0index451;  slog::Index** eval_argsindex452;  slog::Index** eval_argsindex453;  slog::Index** eval_args_ansindex454;  slog::Index** $seq_atdelta455;  slog::Index** evaldelta456;  slog::Index** $sup70016x43x0x0x0delta457;  slog::Index** eval_argsdelta458;  slog::Index** eval_argsdelta459;  slog::Index** eval_args_ansdelta460;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2swd2033");
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord462({1, 0, 2});
      slog::Relation* readrel463 = db->getRelation("$seq_at");
      $seq_atindex445 = readrel463->getIndex(ord462, false);
      std::vector<u16> ord464({1, 0, 2});
      slog::Relation* readrel465 = db->getRelation("$seq_at");
      $seq_atdelta455 = readrel465->getIndex(ord464, true);
      std::vector<u16> ord466({0, 2, 3, 4, 5, 1});
      slog::Relation* readrel467 = db->getRelation("$sup70016x43x0x0x0");
      $sup70016x43x0x0x0index446 = readrel467->getIndex(ord466, false);
      std::vector<u16> ord468({1, 3, 2, 0});
      slog::Relation* readrel469 = db->getRelation("eval_args");
      eval_argsindex447 = readrel469->getIndex(ord468, false);
      std::vector<u16> ord470({0, 1, 2, 3});
      slog::Relation* readrel471 = db->getRelation("eval");
      evalindex448 = readrel471->getIndex(ord470, false);
      std::vector<u16> ord472({0, 1, 2, 3});
      slog::Relation* readrel473 = db->getRelation("eval");
      evaldelta456 = readrel473->getIndex(ord472, true);
      std::vector<u16> ord474({1, 3, 2, 0});
      slog::Relation* readrel475 = db->getRelation("eval_args");
      eval_argsindex449 = readrel475->getIndex(ord474, false);
      std::vector<u16> ord476({1, 3, 2, 0});
      slog::Relation* readrel477 = db->getRelation("eval_args");
      eval_argsindex450 = readrel477->getIndex(ord476, false);
      std::vector<u16> ord478({0, 2, 3, 4, 5, 1});
      slog::Relation* readrel479 = db->getRelation("$sup70016x43x0x0x0");
      $sup70016x43x0x0x0index451 = readrel479->getIndex(ord478, false);
      std::vector<u16> ord480({0, 2, 3, 4, 5, 1});
      slog::Relation* readrel481 = db->getRelation("$sup70016x43x0x0x0");
      $sup70016x43x0x0x0delta457 = readrel481->getIndex(ord480, true);
      std::vector<u16> ord482({3, 2, 0, 1});
      slog::Relation* readrel483 = db->getRelation("eval_args");
      eval_argsindex452 = readrel483->getIndex(ord482, false);
      std::vector<u16> ord484({3, 2, 0, 1});
      slog::Relation* readrel485 = db->getRelation("eval_args");
      eval_argsdelta458 = readrel485->getIndex(ord484, true);
      std::vector<u16> ord486({1, 3, 2, 0});
      slog::Relation* readrel487 = db->getRelation("eval_args");
      eval_argsindex453 = readrel487->getIndex(ord486, false);
      std::vector<u16> ord488({1, 3, 2, 0});
      slog::Relation* readrel489 = db->getRelation("eval_args");
      eval_argsdelta459 = readrel489->getIndex(ord488, true);
      std::vector<u16> ord490({0, 1});
      slog::Relation* readrel491 = db->getRelation("eval_args_ans");
      eval_args_ansindex454 = readrel491->getIndex(ord490, false);
      std::vector<u16> ord492({0, 1});
      slog::Relation* readrel493 = db->getRelation("eval_args_ans");
      eval_args_ansdelta460 = readrel493->getIndex(ord492, true);
  
    }
    ReadTask461(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c103 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c104 = v_const5feceb66ffc86f38d952786c;
      u64 v_c105 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c106 = v_const5feceb66ffc86f38d952786c;
      u64 v_c107 = v_const5feceb66ffc86f38d952786c;
      u64 v_c108 = _prim_lempty(db);
      if (v_c108 == slog_error) { slog::emit_pending_error(db, "interp.slog:44"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c109 = _t[0];
        u64 v_c36 = _t[1];
        slog::join_probe_old<3,1>($seq_atindex445, $seq_atdelta455, std::array<u64,3>{v_c107, 0, 0}, [&](const std::array<u64,3>& m494) {
          u64 v_c97 = m494[1]; u64 v_c96 = m494[2];
          if (!slog::exists_probe<6,2>($sup70016x43x0x0x0index446, std::array<u64,6>{v_c96, v_c97, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<4,1>(eval_argsindex447, std::array<u64,4>{v_c96, 0, 0, 0})) return;
          slog::join_probe_old<4,2>(evalindex448, evaldelta456, std::array<u64,4>{v_c109, v_c97, 0, 0}, [&](const std::array<u64,4>& m495) {
            u64 v_c13 = m495[2]; u64 v_c14 = m495[3];
            bool ok496 = true;
            u64 v_c110 = _prim_aslst(db, v_c96, &ok496);
            if (!ok496) return;
            u64 v_c111 = _prim_llen(db, v_c110);
            if (v_c111 == slog_error) { slog::emit_pending_error(db, "interp.slog:44"); return; }
            u64 v_c112 = _prim_ge(db, v_c111, v_c103);
            if (v_c112 == slog_error) { slog::emit_pending_error(db, "interp.slog:44"); return; }
            if (!v_c112) return;
            u64 v_c113 = _prim__0002d(db, v_c111, v_c106);
            if (v_c113 == slog_error) { slog::emit_pending_error(db, "interp.slog:44"); return; }
            u64 v_c16 = _prim_lslice(db, v_c110, v_c105, v_c113);
            if (v_c16 == slog_error) { slog::emit_pending_error(db, "interp.slog:44"); return; }
            if (!slog::exists_probe<4,3>(eval_argsindex449, std::array<u64,4>{v_c96, v_c14, v_c13, 0})) return;
            if (!slog::exists_probe<4,3>(eval_argsindex450, std::array<u64,4>{v_c16, v_c14, v_c13, 0})) return;
            slog::join_probe_old<6,5>($sup70016x43x0x0x0index451, $sup70016x43x0x0x0delta457, std::array<u64,6>{v_c96, v_c97, v_c16, v_c13, v_c14, 0}, [&](const std::array<u64,6>& m498) {
              u64 v_c114 = m498[5];
              slog::join_probe_old<4,4>(eval_argsindex452, eval_argsdelta458, std::array<u64,4>{v_c14, v_c13, v_c114, v_c96}, [&](const std::array<u64,4>& m499) {
                slog::join_probe_old<4,3>(eval_argsindex453, eval_argsdelta459, std::array<u64,4>{v_c16, v_c14, v_c13, 0}, [&](const std::array<u64,4>& m500) {
                  u64 v_c115 = m500[3];
                  slog::join_probe_old<2,1>(eval_args_ansindex454, eval_args_ansdelta460, std::array<u64,2>{v_c115, 0}, [&](const std::array<u64,2>& m501) {
                    u64 v_c48 = m501[1];
                    bool ok502 = true;
                    u64 v_c116 = _prim_lref(db, v_c110, v_c104, &ok502);
                    if (!ok502) return;
                    if (v_c97 != v_c116) return;
                    ++_fires;
                    slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c108, v_c114, v_c36, v_c48});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:44", "delta:eval_ans", _fires);
  
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
  // (crule (pre (let __tconst7oJb145 const6b86b273ff34fce19d6b804e)) (scan mp_union_ans __t221b149 __v0) (body (join-old mp_union (0 1 2) 1 (0 1 2) __t221b149 __t5mfE148 u) (exists mbranch (3 0 1 2 4) 1 u) (exists $sup5638x104x0x0x0 (7 0 1 2 3 4 5 6 8) 1 u) (exists $sup5638x104x0x0x1 (8 4 6 9 0 2 3 5 7 1) 1 u) (join-old mp_union (1 2 0) 1 (1 2 0) __t5mfE148 __t2NO6142 __t0kfV144) (exists $sup5638x104x0x0x0 (0 7 1 2 3 4 5 6 8) 2 __t0kfV144 u) (exists $sup5638x104x0x0x1 (0 8 1 2 3 4 5 6 7 9) 2 __t0kfV144 u) (join-old mbranch (3 0 1 2 4) 2 (3 0 1 2 4) u __t2NO6142 q n v) (exists $sup5638x104x0x0x1 (8 4 6 9 0 2 3 5 7 1) 5 u n q v __t0kfV144) (exists mp_msk (2 0 1) 1 n) (exists mp_msk_ans (1 0) 1 q) (join-old $sup5638x104x0x0x0 (5 3 7 8 0 1 2 4 6) 5 (5 3 7 8 0 1 2 4 6) q n u v __t0kfV144 l m p r) (cmp lt m n) (exists mbranch (1 2 3 4 0) 5 p m l r __t5mfE148) (exists mp_msk (1 2 0) 2 p n) (join-old $sup5638x104x0x0x1 (8 4 6 9 0 2 3 5 7 1) 9 (8 4 6 9 0 2 3 5 7 1) u n q v __t0kfV144 l m p r __t7PVf147) (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) p m l r __t5mfE148) (join-old mp_msk (1 2 0) 3 (1 2 0) p n __t7PVf147) (join mp_msk_ans (0 1) 2 __t7PVf147 q) (let __t5ygO146 (band p n)) (cmp lt __t5ygO146 __tconst7oJb145)) (head (emit-temp temp9IEi1871 __t0kfV144 __v0 n q v) (mkstruct mbranch (1 2 3 4 0) __t4DAr141 q n __v0 v)) map.slog:105 #f)
  class ReadTask528 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex503;  slog::Index** mbranchindex504;  slog::Index** $sup5638x104x0x0x0index505;  slog::Index** $sup5638x104x0x0x1index506;  slog::Index** mp_unionindex507;  slog::Index** $sup5638x104x0x0x0index508;  slog::Index** $sup5638x104x0x0x1index509;  slog::Index** mbranchindex510;  slog::Index** $sup5638x104x0x0x1index511;  slog::Index** mp_mskindex512;  slog::Index** mp_msk_ansindex513;  slog::Index** $sup5638x104x0x0x0index514;  slog::Index** mbranchindex515;  slog::Index** mp_mskindex516;  slog::Index** $sup5638x104x0x0x1index517;  slog::Index** mbranchindex518;  slog::Index** mp_mskindex519;  slog::Index** mp_msk_ansindex520;  slog::Index** mp_uniondelta521;  slog::Index** mp_uniondelta522;  slog::Index** mbranchdelta523;  slog::Index** $sup5638x104x0x0x0delta524;  slog::Index** $sup5638x104x0x0x1delta525;  slog::Index** mbranchdelta526;  slog::Index** mp_mskdelta527;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9IEi1871");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_union_ans");
      std::vector<u16> ord529({0, 1, 2});
      slog::Relation* readrel530 = db->getRelation("mp_union");
      mp_unionindex503 = readrel530->getIndex(ord529, false);
      std::vector<u16> ord531({0, 1, 2});
      slog::Relation* readrel532 = db->getRelation("mp_union");
      mp_uniondelta521 = readrel532->getIndex(ord531, true);
      std::vector<u16> ord533({3, 0, 1, 2, 4});
      slog::Relation* readrel534 = db->getRelation("mbranch");
      mbranchindex504 = readrel534->getIndex(ord533, false);
      std::vector<u16> ord535({7, 0, 1, 2, 3, 4, 5, 6, 8});
      slog::Relation* readrel536 = db->getRelation("$sup5638x104x0x0x0");
      $sup5638x104x0x0x0index505 = readrel536->getIndex(ord535, false);
      std::vector<u16> ord537({8, 4, 6, 9, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel538 = db->getRelation("$sup5638x104x0x0x1");
      $sup5638x104x0x0x1index506 = readrel538->getIndex(ord537, false);
      std::vector<u16> ord539({1, 2, 0});
      slog::Relation* readrel540 = db->getRelation("mp_union");
      mp_unionindex507 = readrel540->getIndex(ord539, false);
      std::vector<u16> ord541({1, 2, 0});
      slog::Relation* readrel542 = db->getRelation("mp_union");
      mp_uniondelta522 = readrel542->getIndex(ord541, true);
      std::vector<u16> ord543({0, 7, 1, 2, 3, 4, 5, 6, 8});
      slog::Relation* readrel544 = db->getRelation("$sup5638x104x0x0x0");
      $sup5638x104x0x0x0index508 = readrel544->getIndex(ord543, false);
      std::vector<u16> ord545({0, 8, 1, 2, 3, 4, 5, 6, 7, 9});
      slog::Relation* readrel546 = db->getRelation("$sup5638x104x0x0x1");
      $sup5638x104x0x0x1index509 = readrel546->getIndex(ord545, false);
      std::vector<u16> ord547({3, 0, 1, 2, 4});
      slog::Relation* readrel548 = db->getRelation("mbranch");
      mbranchindex510 = readrel548->getIndex(ord547, false);
      std::vector<u16> ord549({3, 0, 1, 2, 4});
      slog::Relation* readrel550 = db->getRelation("mbranch");
      mbranchdelta523 = readrel550->getIndex(ord549, true);
      std::vector<u16> ord551({8, 4, 6, 9, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel552 = db->getRelation("$sup5638x104x0x0x1");
      $sup5638x104x0x0x1index511 = readrel552->getIndex(ord551, false);
      std::vector<u16> ord553({2, 0, 1});
      slog::Relation* readrel554 = db->getRelation("mp_msk");
      mp_mskindex512 = readrel554->getIndex(ord553, false);
      std::vector<u16> ord555({1, 0});
      slog::Relation* readrel556 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex513 = readrel556->getIndex(ord555, false);
      std::vector<u16> ord557({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel558 = db->getRelation("$sup5638x104x0x0x0");
      $sup5638x104x0x0x0index514 = readrel558->getIndex(ord557, false);
      std::vector<u16> ord559({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel560 = db->getRelation("$sup5638x104x0x0x0");
      $sup5638x104x0x0x0delta524 = readrel560->getIndex(ord559, true);
      std::vector<u16> ord561({1, 2, 3, 4, 0});
      slog::Relation* readrel562 = db->getRelation("mbranch");
      mbranchindex515 = readrel562->getIndex(ord561, false);
      std::vector<u16> ord563({1, 2, 0});
      slog::Relation* readrel564 = db->getRelation("mp_msk");
      mp_mskindex516 = readrel564->getIndex(ord563, false);
      std::vector<u16> ord565({8, 4, 6, 9, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel566 = db->getRelation("$sup5638x104x0x0x1");
      $sup5638x104x0x0x1index517 = readrel566->getIndex(ord565, false);
      std::vector<u16> ord567({8, 4, 6, 9, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel568 = db->getRelation("$sup5638x104x0x0x1");
      $sup5638x104x0x0x1delta525 = readrel568->getIndex(ord567, true);
      std::vector<u16> ord569({1, 2, 3, 4, 0});
      slog::Relation* readrel570 = db->getRelation("mbranch");
      mbranchindex518 = readrel570->getIndex(ord569, false);
      std::vector<u16> ord571({1, 2, 3, 4, 0});
      slog::Relation* readrel572 = db->getRelation("mbranch");
      mbranchdelta526 = readrel572->getIndex(ord571, true);
      std::vector<u16> ord573({1, 2, 0});
      slog::Relation* readrel574 = db->getRelation("mp_msk");
      mp_mskindex519 = readrel574->getIndex(ord573, false);
      std::vector<u16> ord575({1, 2, 0});
      slog::Relation* readrel576 = db->getRelation("mp_msk");
      mp_mskdelta527 = readrel576->getIndex(ord575, true);
      std::vector<u16> ord577({0, 1});
      slog::Relation* readrel578 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex520 = readrel578->getIndex(ord577, false);
  
    }
    ReadTask528(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c117 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c118 = _t[0];
        u64 v_c36 = _t[1];
        slog::join_probe_old<3,1>(mp_unionindex503, mp_uniondelta521, std::array<u64,3>{v_c118, 0, 0}, [&](const std::array<u64,3>& m579) {
          u64 v_c119 = m579[1]; u64 v_c30 = m579[2];
          if (!slog::exists_probe<5,1>(mbranchindex504, std::array<u64,5>{v_c30, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<9,1>($sup5638x104x0x0x0index505, std::array<u64,9>{v_c30, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<10,1>($sup5638x104x0x0x1index506, std::array<u64,10>{v_c30, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          slog::join_probe_old<3,1>(mp_unionindex507, mp_uniondelta522, std::array<u64,3>{v_c119, 0, 0}, [&](const std::array<u64,3>& m580) {
            u64 v_c120 = m580[1]; u64 v_c121 = m580[2];
            if (!slog::exists_probe<9,2>($sup5638x104x0x0x0index508, std::array<u64,9>{v_c121, v_c30, 0, 0, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<10,2>($sup5638x104x0x0x1index509, std::array<u64,10>{v_c121, v_c30, 0, 0, 0, 0, 0, 0, 0, 0})) return;
            slog::join_probe_old<5,2>(mbranchindex510, mbranchdelta523, std::array<u64,5>{v_c30, v_c120, 0, 0, 0}, [&](const std::array<u64,5>& m581) {
              u64 v_c28 = m581[2]; u64 v_c26 = m581[3]; u64 v_c3 = m581[4];
              if (!slog::exists_probe<10,5>($sup5638x104x0x0x1index511, std::array<u64,10>{v_c30, v_c26, v_c28, v_c3, v_c121, 0, 0, 0, 0, 0})) return;
              if (!slog::exists_probe<3,1>(mp_mskindex512, std::array<u64,3>{v_c26, 0, 0})) return;
              if (!slog::exists_probe<2,1>(mp_msk_ansindex513, std::array<u64,2>{v_c28, 0})) return;
              slog::join_probe_old<9,5>($sup5638x104x0x0x0index514, $sup5638x104x0x0x0delta524, std::array<u64,9>{v_c28, v_c26, v_c30, v_c3, v_c121, 0, 0, 0, 0}, [&](const std::array<u64,9>& m582) {
                u64 v_c24 = m582[5]; u64 v_c25 = m582[6]; u64 v_c27 = m582[7]; u64 v_c29 = m582[8];
                u64 v_c122 = _prim_lt(db, v_c25, v_c26);
                if (v_c122 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
                if (!v_c122) return;
                if (!slog::exists_probe<5,5>(mbranchindex515, std::array<u64,5>{v_c27, v_c25, v_c24, v_c29, v_c119})) return;
                if (!slog::exists_probe<3,2>(mp_mskindex516, std::array<u64,3>{v_c27, v_c26, 0})) return;
                slog::join_probe_old<10,9>($sup5638x104x0x0x1index517, $sup5638x104x0x0x1delta525, std::array<u64,10>{v_c30, v_c26, v_c28, v_c3, v_c121, v_c24, v_c25, v_c27, v_c29, 0}, [&](const std::array<u64,10>& m584) {
                  u64 v_c123 = m584[9];
                  slog::join_probe_old<5,5>(mbranchindex518, mbranchdelta526, std::array<u64,5>{v_c27, v_c25, v_c24, v_c29, v_c119}, [&](const std::array<u64,5>& m585) {
                    slog::join_probe_old<3,3>(mp_mskindex519, mp_mskdelta527, std::array<u64,3>{v_c27, v_c26, v_c123}, [&](const std::array<u64,3>& m586) {
                      slog::join_probe<2,2>(mp_msk_ansindex520, std::array<u64,2>{v_c123, v_c28}, [&](const std::array<u64,2>& m587) {
                        u64 v_c124 = _prim_band(db, v_c27, v_c26);
                        if (v_c124 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
                        u64 v_c125 = _prim_lt(db, v_c124, v_c117);
                        if (v_c125 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
                        if (!v_c125) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c121, v_c36, v_c26, v_c28, v_c3});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c28, v_c26, v_c36, v_c3}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:105", "delta:mp_union_ans", _fires);
  
      if (!_done)
      {
        ReadTask528* _cont = new ReadTask528(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask528(db,b), false);
  // (crule (pre (let __tconst6BXE233 const5feceb66ffc86f38d952786c)) (scan mp_has0 __t2sXu235 r k) (body (exists $sup5638x62x0x0x0 (1 5 0 2 3 4) 2 k r) (exists mbranch (4 0 1 2 3) 1 r) (exists mp_has0 (2 0 1) 1 k) (exists mp_msk (1 2 0) 1 k) (join mp_has0_ans (0 1) 1 __t2sXu235 a) (join $sup5638x62x0x0x0 (1 5 0 2 3 4) 2 k r __t7cml232 l m p) (exists mp_has0 (0 2 1) 2 __t7cml232 k) (exists mp_msk (1 2 0) 2 k m) (exists mp_msk_ans (1 0) 1 p) (join mbranch (1 2 3 4 0) 4 p m l r __t5gI3231) (join mp_has0 (0 2 1) 3 __t7cml232 k __t5gI3231) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t9BfR236) (join mp_msk_ans (0 1) 2 __t9BfR236 p) (let __t2LqG234 (band k m)) (cmp gt __t2LqG234 __tconst6BXE233)) (head (emit mp_has0_ans (0 1) __t7cml232 a)) map.slog:63 #f)
  class ReadTask603 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x62x0x0x0index589;  slog::Index** mbranchindex590;  slog::Index** mp_has0index591;  slog::Index** mp_mskindex592;  slog::Index** mp_has0_ansindex593;  slog::Index** $sup5638x62x0x0x0index594;  slog::Index** mp_has0index595;  slog::Index** mp_mskindex596;  slog::Index** mp_msk_ansindex597;  slog::Index** mbranchindex598;  slog::Index** mp_has0index599;  slog::Index** mp_mskindex600;  slog::Index** mp_msk_ansindex601;  slog::Index** mp_mskdelta602;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_has0_ans");
      std::vector<u16> ord604({0, 1});
      slog::Relation* readrel605 = db->getRelation("mp_has0_ans");
      head_index[0] = readrel605->getIndex(ord604, false);
      outer_rel = db->getRelation("mp_has0");
      std::vector<u16> ord606({1, 5, 0, 2, 3, 4});
      slog::Relation* readrel607 = db->getRelation("$sup5638x62x0x0x0");
      $sup5638x62x0x0x0index589 = readrel607->getIndex(ord606, false);
      std::vector<u16> ord608({4, 0, 1, 2, 3});
      slog::Relation* readrel609 = db->getRelation("mbranch");
      mbranchindex590 = readrel609->getIndex(ord608, false);
      std::vector<u16> ord610({2, 0, 1});
      slog::Relation* readrel611 = db->getRelation("mp_has0");
      mp_has0index591 = readrel611->getIndex(ord610, false);
      std::vector<u16> ord612({1, 2, 0});
      slog::Relation* readrel613 = db->getRelation("mp_msk");
      mp_mskindex592 = readrel613->getIndex(ord612, false);
      std::vector<u16> ord614({0, 1});
      slog::Relation* readrel615 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex593 = readrel615->getIndex(ord614, false);
      std::vector<u16> ord616({1, 5, 0, 2, 3, 4});
      slog::Relation* readrel617 = db->getRelation("$sup5638x62x0x0x0");
      $sup5638x62x0x0x0index594 = readrel617->getIndex(ord616, false);
      std::vector<u16> ord618({0, 2, 1});
      slog::Relation* readrel619 = db->getRelation("mp_has0");
      mp_has0index595 = readrel619->getIndex(ord618, false);
      std::vector<u16> ord620({1, 2, 0});
      slog::Relation* readrel621 = db->getRelation("mp_msk");
      mp_mskindex596 = readrel621->getIndex(ord620, false);
      std::vector<u16> ord622({1, 0});
      slog::Relation* readrel623 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex597 = readrel623->getIndex(ord622, false);
      std::vector<u16> ord624({1, 2, 3, 4, 0});
      slog::Relation* readrel625 = db->getRelation("mbranch");
      mbranchindex598 = readrel625->getIndex(ord624, false);
      std::vector<u16> ord626({0, 2, 1});
      slog::Relation* readrel627 = db->getRelation("mp_has0");
      mp_has0index599 = readrel627->getIndex(ord626, false);
      std::vector<u16> ord628({1, 2, 0});
      slog::Relation* readrel629 = db->getRelation("mp_msk");
      mp_mskindex600 = readrel629->getIndex(ord628, false);
      std::vector<u16> ord630({1, 2, 0});
      slog::Relation* readrel631 = db->getRelation("mp_msk");
      mp_mskdelta602 = readrel631->getIndex(ord630, true);
      std::vector<u16> ord632({0, 1});
      slog::Relation* readrel633 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex601 = readrel633->getIndex(ord632, false);
  
    }
    ReadTask603(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c126 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c127 = _t[0];
        u64 v_c29 = _t[1];
        u64 v_c4 = _t[2];
        if (!slog::exists_probe<6,2>($sup5638x62x0x0x0index589, std::array<u64,6>{v_c4, v_c29, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex590, std::array<u64,5>{v_c29, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_has0index591, std::array<u64,3>{v_c4, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex592, std::array<u64,3>{v_c4, 0, 0})) return;
        slog::join_probe<2,1>(mp_has0_ansindex593, std::array<u64,2>{v_c127, 0}, [&](const std::array<u64,2>& m634) {
          u64 v_c128 = m634[1];
          slog::join_probe<6,2>($sup5638x62x0x0x0index594, std::array<u64,6>{v_c4, v_c29, 0, 0, 0, 0}, [&](const std::array<u64,6>& m635) {
            u64 v_c129 = m635[2]; u64 v_c24 = m635[3]; u64 v_c25 = m635[4]; u64 v_c27 = m635[5];
            if (!slog::exists_probe<3,2>(mp_has0index595, std::array<u64,3>{v_c129, v_c4, 0})) return;
            if (!slog::exists_probe<3,2>(mp_mskindex596, std::array<u64,3>{v_c4, v_c25, 0})) return;
            if (!slog::exists_probe<2,1>(mp_msk_ansindex597, std::array<u64,2>{v_c27, 0})) return;
            slog::join_probe<5,4>(mbranchindex598, std::array<u64,5>{v_c27, v_c25, v_c24, v_c29, 0}, [&](const std::array<u64,5>& m636) {
              u64 v_c130 = m636[4];
              slog::join_probe<3,3>(mp_has0index599, std::array<u64,3>{v_c129, v_c4, v_c130}, [&](const std::array<u64,3>& m637) {
                slog::join_probe_old<3,2>(mp_mskindex600, mp_mskdelta602, std::array<u64,3>{v_c4, v_c25, 0}, [&](const std::array<u64,3>& m638) {
                  u64 v_c131 = m638[2];
                  slog::join_probe<2,2>(mp_msk_ansindex601, std::array<u64,2>{v_c131, v_c27}, [&](const std::array<u64,2>& m639) {
                    u64 v_c132 = _prim_band(db, v_c4, v_c25);
                    if (v_c132 == slog_error) { slog::emit_pending_error(db, "map.slog:63"); return; }
                    u64 v_c133 = _prim_gt(db, v_c132, v_c126);
                    if (v_c133 == slog_error) { slog::emit_pending_error(db, "map.slog:63"); return; }
                    if (!v_c133) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c129, v_c128}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:63", "delta:mp_has0", _fires);
  
      if (!_done)
      {
        ReadTask603* _cont = new ReadTask603(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask603(db,b), false);
  // (crule (pre (let __trid8V8J1314 const1b2483991f3f37e4463261cd) (let __trel0z7a1315 constdd7bbf31ce5f578b9805e840) (let __tcol0Oy21316 const5feceb66ffc86f38d952786c) (let __trel1J4a1317 constdd7bbf31ce5f578b9805e840) (let __tcol7DcT1318 const6b86b273ff34fce19d6b804e)) (scan $sup5638x40x0x0x0 __d0 k l m p r v) (body) (head (tycheck k (accept int) __trid8V8J1314 __trel0z7a1315 __tcol0Oy21316 (1 2 3 4 0)) (tycheck m (accept int) __trid8V8J1314 __trel1J4a1317 __tcol7DcT1318 (1 2 3 4 0)) (mkstruct mp_msk (1 2 0) __4tRY1313 k m)) map.slog:41 #f)
  class ReadTask641 : public slog::Task
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
      outer_rel = db->getRelation("$sup5638x40x0x0x0");
  
    }
    ReadTask641(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c134 = v_const1b2483991f3f37e4463261cd;
      u64 v_c135 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c136 = v_const5feceb66ffc86f38d952786c;
      u64 v_c137 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c138 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c15 = _t[0];
        u64 v_c4 = _t[1];
        u64 v_c24 = _t[2];
        u64 v_c25 = _t[3];
        u64 v_c27 = _t[4];
        u64 v_c29 = _t[5];
        u64 v_c3 = _t[6];
        ++_fires;
        if (!(is_int(v_c4)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c134, v_c135, v_c136, v_c4}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c25)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c134, v_c137, v_c138, v_c25}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c4, v_c25}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:41", "delta:$sup5638x40x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask641* _cont = new ReadTask641(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask641(db,b), false);
  // (crule (pre) (scan mp_msk __t6N42442 q m) (body (exists $sup5638x95x0x0x0 (2 5 4 0 1 3 6 7 8) 2 m q) (join mp_msk_ans (0 1) 1 __t6N42442 p) (join $sup5638x95x0x0x0 (2 5 4 0 1 3 6 7 8) 3 m q p __d0 l n r u v)) (head (emit $sup5638x95x0x0x1 (0 2 1 3 4 5 6 7 8 9) __d0 l __t6N42442 m n p q r u v)) map.slog:96 #f)
  class ReadTask645 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x95x0x0x0index642;  slog::Index** mp_msk_ansindex643;  slog::Index** $sup5638x95x0x0x0index644;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x95x0x0x1");
      std::vector<u16> ord646({0, 2, 1, 3, 4, 5, 6, 7, 8, 9});
      slog::Relation* readrel647 = db->getRelation("$sup5638x95x0x0x1");
      head_index[0] = readrel647->getIndex(ord646, false);
      outer_rel = db->getRelation("mp_msk");
      std::vector<u16> ord648({2, 5, 4, 0, 1, 3, 6, 7, 8});
      slog::Relation* readrel649 = db->getRelation("$sup5638x95x0x0x0");
      $sup5638x95x0x0x0index642 = readrel649->getIndex(ord648, false);
      std::vector<u16> ord650({0, 1});
      slog::Relation* readrel651 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex643 = readrel651->getIndex(ord650, false);
      std::vector<u16> ord652({2, 5, 4, 0, 1, 3, 6, 7, 8});
      slog::Relation* readrel653 = db->getRelation("$sup5638x95x0x0x0");
      $sup5638x95x0x0x0index644 = readrel653->getIndex(ord652, false);
  
    }
    ReadTask645(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c28 = _t[1];
        u64 v_c25 = _t[2];
        if (!slog::exists_probe<9,2>($sup5638x95x0x0x0index642, std::array<u64,9>{v_c25, v_c28, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(mp_msk_ansindex643, std::array<u64,2>{v_c139, 0}, [&](const std::array<u64,2>& m654) {
          u64 v_c27 = m654[1];
          slog::join_probe<9,3>($sup5638x95x0x0x0index644, std::array<u64,9>{v_c25, v_c28, v_c27, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m655) {
            u64 v_c15 = m655[3]; u64 v_c24 = m655[4]; u64 v_c26 = m655[5]; u64 v_c29 = m655[6]; u64 v_c30 = m655[7]; u64 v_c3 = m655[8];
            ++_fires;
            slog::emit<10>(head_rel[0], head_index[0], newbatch[0], std::array<u64,10>{v_c15, v_c24, v_c139, v_c25, v_c26, v_c27, v_c28, v_c29, v_c30, v_c3}, std::array<u16,10>{0, 2, 1, 3, 4, 5, 6, 7, 8, 9});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:96", "delta:mp_msk", _fires);
  
      if (!_done)
      {
        ReadTask645* _cont = new ReadTask645(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask645(db,b), false);
  // (crule (pre) (scan eval_ans __t7lOb612 __t6tRF614) (body (join-old closure (0 1 2) 1 (0 1 2) __t6tRF614 __t20Nd613 rhoc) (join-old lambda (0 1 2) 1 (0 1 2) __t20Nd613 xs eb) (join-old eval (0 1 2 3) 1 (0 1 2 3) __t7lOb612 ef rho t) (exists app (1 2 0) 1 ef) (exists eval_args (3 2 0 1) 2 t rho) (exists tick (2 0 1) 1 t) (join eval (2 3 0 1) 2 rho t __3JBR1203 __t3MQm616) (exists tick (1 2 0) 2 __t3MQm616 t) (join-old app (0 1 2) 2 (0 1 2) __t3MQm616 ef es) (join-old eval_args (1 3 2 0) 3 (1 3 2 0) es t rho __t192L615) (exists eval_args_ans (0 1) 1 __t192L615) (join-old tick (1 2 0) 2 (1 2 0) __t3MQm616 t __t2n7W617) (exists tick_ans (0 1) 1 __t2n7W617) (join-old eval_args_ans (0 1) 1 (0 1) __t192L615 vs) (join-old tick_ans (0 1) 1 (0 1) __t2n7W617 t2)) (head (emit bind_store (0 1 2 3) xs vs t2 t) (emit call_event (0 1) t2 t)) interp.slog:59 #f)
  class ReadTask679 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** closureindex656;  slog::Index** lambdaindex657;  slog::Index** evalindex658;  slog::Index** appindex659;  slog::Index** eval_argsindex660;  slog::Index** tickindex661;  slog::Index** evalindex662;  slog::Index** tickindex663;  slog::Index** appindex664;  slog::Index** eval_argsindex665;  slog::Index** eval_args_ansindex666;  slog::Index** tickindex667;  slog::Index** tick_ansindex668;  slog::Index** eval_args_ansindex669;  slog::Index** tick_ansindex670;  slog::Index** closuredelta671;  slog::Index** lambdadelta672;  slog::Index** evaldelta673;  slog::Index** appdelta674;  slog::Index** eval_argsdelta675;  slog::Index** tickdelta676;  slog::Index** eval_args_ansdelta677;  slog::Index** tick_ansdelta678;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("bind_store");
      std::vector<u16> ord680({0, 1, 2, 3});
      slog::Relation* readrel681 = db->getRelation("bind_store");
      head_index[0] = readrel681->getIndex(ord680, false);
      head_rel[1] = db->getRelation("call_event");
      std::vector<u16> ord682({0, 1});
      slog::Relation* readrel683 = db->getRelation("call_event");
      head_index[1] = readrel683->getIndex(ord682, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord684({0, 1, 2});
      slog::Relation* readrel685 = db->getRelation("closure");
      closureindex656 = readrel685->getIndex(ord684, false);
      std::vector<u16> ord686({0, 1, 2});
      slog::Relation* readrel687 = db->getRelation("closure");
      closuredelta671 = readrel687->getIndex(ord686, true);
      std::vector<u16> ord688({0, 1, 2});
      slog::Relation* readrel689 = db->getRelation("lambda");
      lambdaindex657 = readrel689->getIndex(ord688, false);
      std::vector<u16> ord690({0, 1, 2});
      slog::Relation* readrel691 = db->getRelation("lambda");
      lambdadelta672 = readrel691->getIndex(ord690, true);
      std::vector<u16> ord692({0, 1, 2, 3});
      slog::Relation* readrel693 = db->getRelation("eval");
      evalindex658 = readrel693->getIndex(ord692, false);
      std::vector<u16> ord694({0, 1, 2, 3});
      slog::Relation* readrel695 = db->getRelation("eval");
      evaldelta673 = readrel695->getIndex(ord694, true);
      std::vector<u16> ord696({1, 2, 0});
      slog::Relation* readrel697 = db->getRelation("app");
      appindex659 = readrel697->getIndex(ord696, false);
      std::vector<u16> ord698({3, 2, 0, 1});
      slog::Relation* readrel699 = db->getRelation("eval_args");
      eval_argsindex660 = readrel699->getIndex(ord698, false);
      std::vector<u16> ord700({2, 0, 1});
      slog::Relation* readrel701 = db->getRelation("tick");
      tickindex661 = readrel701->getIndex(ord700, false);
      std::vector<u16> ord702({2, 3, 0, 1});
      slog::Relation* readrel703 = db->getRelation("eval");
      evalindex662 = readrel703->getIndex(ord702, false);
      std::vector<u16> ord704({1, 2, 0});
      slog::Relation* readrel705 = db->getRelation("tick");
      tickindex663 = readrel705->getIndex(ord704, false);
      std::vector<u16> ord706({0, 1, 2});
      slog::Relation* readrel707 = db->getRelation("app");
      appindex664 = readrel707->getIndex(ord706, false);
      std::vector<u16> ord708({0, 1, 2});
      slog::Relation* readrel709 = db->getRelation("app");
      appdelta674 = readrel709->getIndex(ord708, true);
      std::vector<u16> ord710({1, 3, 2, 0});
      slog::Relation* readrel711 = db->getRelation("eval_args");
      eval_argsindex665 = readrel711->getIndex(ord710, false);
      std::vector<u16> ord712({1, 3, 2, 0});
      slog::Relation* readrel713 = db->getRelation("eval_args");
      eval_argsdelta675 = readrel713->getIndex(ord712, true);
      std::vector<u16> ord714({0, 1});
      slog::Relation* readrel715 = db->getRelation("eval_args_ans");
      eval_args_ansindex666 = readrel715->getIndex(ord714, false);
      std::vector<u16> ord716({1, 2, 0});
      slog::Relation* readrel717 = db->getRelation("tick");
      tickindex667 = readrel717->getIndex(ord716, false);
      std::vector<u16> ord718({1, 2, 0});
      slog::Relation* readrel719 = db->getRelation("tick");
      tickdelta676 = readrel719->getIndex(ord718, true);
      std::vector<u16> ord720({0, 1});
      slog::Relation* readrel721 = db->getRelation("tick_ans");
      tick_ansindex668 = readrel721->getIndex(ord720, false);
      std::vector<u16> ord722({0, 1});
      slog::Relation* readrel723 = db->getRelation("eval_args_ans");
      eval_args_ansindex669 = readrel723->getIndex(ord722, false);
      std::vector<u16> ord724({0, 1});
      slog::Relation* readrel725 = db->getRelation("eval_args_ans");
      eval_args_ansdelta677 = readrel725->getIndex(ord724, true);
      std::vector<u16> ord726({0, 1});
      slog::Relation* readrel727 = db->getRelation("tick_ans");
      tick_ansindex670 = readrel727->getIndex(ord726, false);
      std::vector<u16> ord728({0, 1});
      slog::Relation* readrel729 = db->getRelation("tick_ans");
      tick_ansdelta678 = readrel729->getIndex(ord728, true);
  
    }
    ReadTask679(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c140 = _t[0];
        u64 v_c141 = _t[1];
        slog::join_probe_old<3,1>(closureindex656, closuredelta671, std::array<u64,3>{v_c141, 0, 0}, [&](const std::array<u64,3>& m730) {
          u64 v_c142 = m730[1]; u64 v_c8 = m730[2];
          slog::join_probe_old<3,1>(lambdaindex657, lambdadelta672, std::array<u64,3>{v_c142, 0, 0}, [&](const std::array<u64,3>& m731) {
            u64 v_c10 = m731[1]; u64 v_c11 = m731[2];
            slog::join_probe_old<4,1>(evalindex658, evaldelta673, std::array<u64,4>{v_c140, 0, 0, 0}, [&](const std::array<u64,4>& m732) {
              u64 v_c12 = m732[1]; u64 v_c13 = m732[2]; u64 v_c14 = m732[3];
              if (!slog::exists_probe<3,1>(appindex659, std::array<u64,3>{v_c12, 0, 0})) return;
              if (!slog::exists_probe<4,2>(eval_argsindex660, std::array<u64,4>{v_c14, v_c13, 0, 0})) return;
              if (!slog::exists_probe<3,1>(tickindex661, std::array<u64,3>{v_c14, 0, 0})) return;
              slog::join_probe<4,2>(evalindex662, std::array<u64,4>{v_c13, v_c14, 0, 0}, [&](const std::array<u64,4>& m733) {
                u64 v_c143 = m733[2]; u64 v_c144 = m733[3];
                if (!slog::exists_probe<3,2>(tickindex663, std::array<u64,3>{v_c144, v_c14, 0})) return;
                slog::join_probe_old<3,2>(appindex664, appdelta674, std::array<u64,3>{v_c144, v_c12, 0}, [&](const std::array<u64,3>& m734) {
                  u64 v_c16 = m734[2];
                  slog::join_probe_old<4,3>(eval_argsindex665, eval_argsdelta675, std::array<u64,4>{v_c16, v_c14, v_c13, 0}, [&](const std::array<u64,4>& m735) {
                    u64 v_c145 = m735[3];
                    if (!slog::exists_probe<2,1>(eval_args_ansindex666, std::array<u64,2>{v_c145, 0})) return;
                    slog::join_probe_old<3,2>(tickindex667, tickdelta676, std::array<u64,3>{v_c144, v_c14, 0}, [&](const std::array<u64,3>& m736) {
                      u64 v_c146 = m736[2];
                      if (!slog::exists_probe<2,1>(tick_ansindex668, std::array<u64,2>{v_c146, 0})) return;
                      slog::join_probe_old<2,1>(eval_args_ansindex669, eval_args_ansdelta677, std::array<u64,2>{v_c145, 0}, [&](const std::array<u64,2>& m737) {
                        u64 v_c20 = m737[1];
                        slog::join_probe_old<2,1>(tick_ansindex670, tick_ansdelta678, std::array<u64,2>{v_c146, 0}, [&](const std::array<u64,2>& m738) {
                          u64 v_c21 = m738[1];
                          ++_fires;
                          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c10, v_c20, v_c21, v_c14}, std::array<u16,4>{0, 1, 2, 3});
                          slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c21, v_c14}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:59", "delta:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask679* _cont = new ReadTask679(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask679(db,b), false);
  // (crule (pre (let __tconst8HHZ1552 constb9e118781cea1f9fa01462e0)) (probe _enum (1 0) 1 __tconst8HHZ1552 __t7uDW271) (body) (head (mkstruct boolval (1 0) __t48JJ272 __t7uDW271)) interp.slog:82 #f)
  class ReadTask739 : public slog::Task
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
      head_rel[0] = db->getRelation("boolval");
      std::vector<u16> ord740({1, 0});
      slog::Relation* readrel741 = db->getRelation("_enum");
      driver_index = readrel741->getIndex(ord740, true);
  
    }
    ReadTask739(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c147 = v_constb9e118781cea1f9fa01462e0;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c147, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m742) {
        u64 v_c148 = m742[1];
        if (buckethash(v_c148) != bucket) return;
        ++_fires;
        slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c148}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:82", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask739* _cont = new ReadTask739(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask739(db,b), true);
  // (crule (pre) (scan mp_join __t5j84218 p0 t0 p1 t1) (body) (head (emit $sup5638x29x0x0x0 (1 0 2 3 4) p0 __t5j84218 p1 t0 t1)) map.slog:30 #f)
  class ReadTask743 : public slog::Task
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
      head_rel[0] = db->getRelation("$sup5638x29x0x0x0");
      std::vector<u16> ord744({1, 0, 2, 3, 4});
      slog::Relation* readrel745 = db->getRelation("$sup5638x29x0x0x0");
      head_index[0] = readrel745->getIndex(ord744, false);
      outer_rel = db->getRelation("mp_join");
  
    }
    ReadTask743(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c149 = _t[0];
        u64 v_c47 = _t[1];
        u64 v_c56 = _t[2];
        u64 v_c55 = _t[3];
        u64 v_c57 = _t[4];
        ++_fires;
        slog::emit<5>(head_rel[0], head_index[0], newbatch[0], std::array<u64,5>{v_c47, v_c149, v_c55, v_c56, v_c57}, std::array<u16,5>{1, 0, 2, 3, 4});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:30", "delta:mp_join", _fires);
  
      if (!_done)
      {
        ReadTask743* _cont = new ReadTask743(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask743(db,b), false);
  // (crule (pre) (scan mp_put __t6Fc5832 __t6oBk833 k v) (body (exists mp_join (1 4 2 0 3) 2 k __t6oBk833) (exists mleaf (1 2 0) 2 k v) (exists mp_msk (1 2 0) 1 k) (join $sup5638x44x0x0x0 (1 7 0 6 4 2 3 5) 4 k v __t6Fc5832 __t6oBk833 p l m r) (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) p m l r __t6oBk833) (exists mp_msk (1 2 0) 2 k m) (join-old mp_join (3 4 1 0 2) 3 (3 4 1 0 2) p __t6oBk833 k __t6jFY835 __t5lKq834) (join-old mleaf (0 1 2) 3 (0 1 2) __t5lKq834 k v) (exists mp_join_ans (0 1) 1 __t6jFY835) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t2nZc836) (join mp_msk_ans (0 1) 1 __t2nZc836 __v0) (neq p __v0) (join mp_join_ans (0 1) 1 __t6jFY835 res)) (head (emit mp_put_ans (0 1) __t6Fc5832 res)) map.slog:45 #f)
  class ReadTask762 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_joinindex746;  slog::Index** mleafindex747;  slog::Index** mp_mskindex748;  slog::Index** $sup5638x44x0x0x0index749;  slog::Index** mbranchindex750;  slog::Index** mp_mskindex751;  slog::Index** mp_joinindex752;  slog::Index** mleafindex753;  slog::Index** mp_join_ansindex754;  slog::Index** mp_mskindex755;  slog::Index** mp_msk_ansindex756;  slog::Index** mp_join_ansindex757;  slog::Index** mbranchdelta758;  slog::Index** mp_joindelta759;  slog::Index** mleafdelta760;  slog::Index** mp_mskdelta761;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_ans");
      std::vector<u16> ord763({0, 1});
      slog::Relation* readrel764 = db->getRelation("mp_put_ans");
      head_index[0] = readrel764->getIndex(ord763, false);
      outer_rel = db->getRelation("mp_put");
      std::vector<u16> ord765({1, 4, 2, 0, 3});
      slog::Relation* readrel766 = db->getRelation("mp_join");
      mp_joinindex746 = readrel766->getIndex(ord765, false);
      std::vector<u16> ord767({1, 2, 0});
      slog::Relation* readrel768 = db->getRelation("mleaf");
      mleafindex747 = readrel768->getIndex(ord767, false);
      std::vector<u16> ord769({1, 2, 0});
      slog::Relation* readrel770 = db->getRelation("mp_msk");
      mp_mskindex748 = readrel770->getIndex(ord769, false);
      std::vector<u16> ord771({1, 7, 0, 6, 4, 2, 3, 5});
      slog::Relation* readrel772 = db->getRelation("$sup5638x44x0x0x0");
      $sup5638x44x0x0x0index749 = readrel772->getIndex(ord771, false);
      std::vector<u16> ord773({1, 2, 3, 4, 0});
      slog::Relation* readrel774 = db->getRelation("mbranch");
      mbranchindex750 = readrel774->getIndex(ord773, false);
      std::vector<u16> ord775({1, 2, 3, 4, 0});
      slog::Relation* readrel776 = db->getRelation("mbranch");
      mbranchdelta758 = readrel776->getIndex(ord775, true);
      std::vector<u16> ord777({1, 2, 0});
      slog::Relation* readrel778 = db->getRelation("mp_msk");
      mp_mskindex751 = readrel778->getIndex(ord777, false);
      std::vector<u16> ord779({3, 4, 1, 0, 2});
      slog::Relation* readrel780 = db->getRelation("mp_join");
      mp_joinindex752 = readrel780->getIndex(ord779, false);
      std::vector<u16> ord781({3, 4, 1, 0, 2});
      slog::Relation* readrel782 = db->getRelation("mp_join");
      mp_joindelta759 = readrel782->getIndex(ord781, true);
      std::vector<u16> ord783({0, 1, 2});
      slog::Relation* readrel784 = db->getRelation("mleaf");
      mleafindex753 = readrel784->getIndex(ord783, false);
      std::vector<u16> ord785({0, 1, 2});
      slog::Relation* readrel786 = db->getRelation("mleaf");
      mleafdelta760 = readrel786->getIndex(ord785, true);
      std::vector<u16> ord787({0, 1});
      slog::Relation* readrel788 = db->getRelation("mp_join_ans");
      mp_join_ansindex754 = readrel788->getIndex(ord787, false);
      std::vector<u16> ord789({1, 2, 0});
      slog::Relation* readrel790 = db->getRelation("mp_msk");
      mp_mskindex755 = readrel790->getIndex(ord789, false);
      std::vector<u16> ord791({1, 2, 0});
      slog::Relation* readrel792 = db->getRelation("mp_msk");
      mp_mskdelta761 = readrel792->getIndex(ord791, true);
      std::vector<u16> ord793({0, 1});
      slog::Relation* readrel794 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex756 = readrel794->getIndex(ord793, false);
      std::vector<u16> ord795({0, 1});
      slog::Relation* readrel796 = db->getRelation("mp_join_ans");
      mp_join_ansindex757 = readrel796->getIndex(ord795, false);
  
    }
    ReadTask762(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c150 = _t[0];
        u64 v_c151 = _t[1];
        u64 v_c4 = _t[2];
        u64 v_c3 = _t[3];
        if (!slog::exists_probe<5,2>(mp_joinindex746, std::array<u64,5>{v_c4, v_c151, 0, 0, 0})) return;
        if (!slog::exists_probe<3,2>(mleafindex747, std::array<u64,3>{v_c4, v_c3, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex748, std::array<u64,3>{v_c4, 0, 0})) return;
        slog::join_probe<8,4>($sup5638x44x0x0x0index749, std::array<u64,8>{v_c4, v_c3, v_c150, v_c151, 0, 0, 0, 0}, [&](const std::array<u64,8>& m797) {
          u64 v_c27 = m797[4]; u64 v_c24 = m797[5]; u64 v_c25 = m797[6]; u64 v_c29 = m797[7];
          slog::join_probe_old<5,5>(mbranchindex750, mbranchdelta758, std::array<u64,5>{v_c27, v_c25, v_c24, v_c29, v_c151}, [&](const std::array<u64,5>& m798) {
            if (!slog::exists_probe<3,2>(mp_mskindex751, std::array<u64,3>{v_c4, v_c25, 0})) return;
            slog::join_probe_old<5,3>(mp_joinindex752, mp_joindelta759, std::array<u64,5>{v_c27, v_c151, v_c4, 0, 0}, [&](const std::array<u64,5>& m799) {
              u64 v_c152 = m799[3]; u64 v_c153 = m799[4];
              slog::join_probe_old<3,3>(mleafindex753, mleafdelta760, std::array<u64,3>{v_c153, v_c4, v_c3}, [&](const std::array<u64,3>& m800) {
                if (!slog::exists_probe<2,1>(mp_join_ansindex754, std::array<u64,2>{v_c152, 0})) return;
                slog::join_probe_old<3,2>(mp_mskindex755, mp_mskdelta761, std::array<u64,3>{v_c4, v_c25, 0}, [&](const std::array<u64,3>& m801) {
                  u64 v_c154 = m801[2];
                  slog::join_probe<2,1>(mp_msk_ansindex756, std::array<u64,2>{v_c154, 0}, [&](const std::array<u64,2>& m802) {
                    u64 v_c36 = m802[1];
                    if (v_c27 == v_c36) return;
                    slog::join_probe<2,1>(mp_join_ansindex757, std::array<u64,2>{v_c152, 0}, [&](const std::array<u64,2>& m803) {
                      u64 v_c82 = m803[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c150, v_c82}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:45", "delta:mp_put", _fires);
  
      if (!_done)
      {
        ReadTask762* _cont = new ReadTask762(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask762(db,b), false);
  // (crule (pre) (scan mp_put_soft __t6kaY573 t k v) (body) (head (emit $sup5638x68x0x0x0 (1 2 3 0) k t v __t6kaY573)) map.slog:69 #f)
  class ReadTask804 : public slog::Task
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
      head_rel[0] = db->getRelation("$sup5638x68x0x0x0");
      std::vector<u16> ord805({1, 2, 3, 0});
      slog::Relation* readrel806 = db->getRelation("$sup5638x68x0x0x0");
      head_index[0] = readrel806->getIndex(ord805, false);
      outer_rel = db->getRelation("mp_put_soft");
  
    }
    ReadTask804(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c14 = _t[1];
        u64 v_c4 = _t[2];
        u64 v_c3 = _t[3];
        ++_fires;
        slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c4, v_c14, v_c3, v_c155}, std::array<u16,4>{1, 2, 3, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:69", "delta:mp_put_soft", _fires);
  
      if (!_done)
      {
        ReadTask804* _cont = new ReadTask804(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask804(db,b), false);
  // (crule (pre) (scan mpz_table_overflow __erre5MoD1773 __errf4uWo1774 __errf2M8m1775) (body) (head (emit error (0) __erre5MoD1773)) <internal>:1 #f)
  class ReadTask807 : public slog::Task
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
      std::vector<u16> ord808({0});
      slog::Relation* readrel809 = db->getRelation("error");
      head_index[0] = readrel809->getIndex(ord808, false);
      outer_rel = db->getRelation("mpz_table_overflow");
  
    }
    ReadTask807(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c157 = _t[1];
        u64 v_c158 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c156}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_table_overflow", _fires);
  
      if (!_done)
      {
        ReadTask807* _cont = new ReadTask807(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask807(db,b), false);
  // (crule (pre) (scan mleaf __t7f1J316 j w) (body (join-old mp_put (1 2 3 0) 1 (1 2 3 0) __t7f1J316 k v __t18bR317) (neq j k)) (head (emit-temp temp3Msk1947 __t7f1J316 j k v) (mkstruct mleaf (1 2 0) __t7bYO315 k v)) map.slog:39 #f)
  class ReadTask812 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_putindex810;  slog::Index** mp_putdelta811;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3Msk1947");
      head_rel[1] = db->getRelation("mleaf");
      outer_rel = db->getRelation("mleaf");
      std::vector<u16> ord813({1, 2, 3, 0});
      slog::Relation* readrel814 = db->getRelation("mp_put");
      mp_putindex810 = readrel814->getIndex(ord813, false);
      std::vector<u16> ord815({1, 2, 3, 0});
      slog::Relation* readrel816 = db->getRelation("mp_put");
      mp_putdelta811 = readrel816->getIndex(ord815, true);
  
    }
    ReadTask812(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c159 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c160 = _t[2];
        slog::join_probe_old<4,1>(mp_putindex810, mp_putdelta811, std::array<u64,4>{v_c159, 0, 0, 0}, [&](const std::array<u64,4>& m817) {
          u64 v_c4 = m817[1]; u64 v_c3 = m817[2]; u64 v_c161 = m817[3];
          if (v_c2 == v_c4) return;
          ++_fires;
          slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c159, v_c2, v_c4, v_c3});
          slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c4, v_c3}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("map.slog:39", "delta:mleaf", _fires);
  
      if (!_done)
      {
        ReadTask812* _cont = new ReadTask812(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask812(db,b), false);
  // (crule (pre (let __trid2O7O1484 const9cfb09b7c00913be7566a50e) (let __trel65Vd1485 const7f254967624b26d820569bd6) (let __tcol93kE1486 const5feceb66ffc86f38d952786c) (let __trel2E3y1487 const7f254967624b26d820569bd6) (let __tcol8XSW1488 const6b86b273ff34fce19d6b804e)) (scan $sup5638x93x0x0x0 __d0 l m p r u v) (body) (head (tycheck r (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid2O7O1484 __trel65Vd1485 __tcol93kE1486 (1 2 3 4 0)) (tycheck v (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid2O7O1484 __trel2E3y1487 __tcol8XSW1488 (1 2 3 4 0)) (mkstruct mp_union (1 2 0) __3Si01483 r v)) map.slog:94 #f)
  class ReadTask821 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid819;  u32 sid818;  u32 sid820;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("mp_union");
      outer_rel = db->getRelation("$sup5638x93x0x0x0");
      sid819 = db->getRelation("_enum")->getStructId();
      sid818 = db->getRelation("mbranch")->getStructId();
      sid820 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask821(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c162 = v_const9cfb09b7c00913be7566a50e;
      u64 v_c163 = v_const7f254967624b26d820569bd6;
      u64 v_c164 = v_const5feceb66ffc86f38d952786c;
      u64 v_c165 = v_const7f254967624b26d820569bd6;
      u64 v_c166 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c15 = _t[0];
        u64 v_c24 = _t[1];
        u64 v_c25 = _t[2];
        u64 v_c27 = _t[3];
        u64 v_c29 = _t[4];
        u64 v_c30 = _t[5];
        u64 v_c3 = _t[6];
        ++_fires;
        if (!((is_struct(v_c29) && (decode_struct_id(v_c29) == sid818 || decode_struct_id(v_c29) == sid819 || decode_struct_id(v_c29) == sid820))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c162, v_c163, v_c164, v_c29}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c3) && (decode_struct_id(v_c3) == sid818 || decode_struct_id(v_c3) == sid819 || decode_struct_id(v_c3) == sid820))))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c162, v_c165, v_c166, v_c3}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c29, v_c3}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:94", "delta:$sup5638x93x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask821* _cont = new ReadTask821(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask821(db,b), false);
  // (crule (pre (let __tconst9a82241 const6b86b273ff34fce19d6b804e)) (scan mp_msk_ans __t0CZp243 p) (body (exists $sup5638x40x0x0x1 (1 5 0 2 3 4 6 7) 2 __t0CZp243 p) (exists $sup5638x40x0x0x0 (4 2 3 5 0 1 6) 1 p) (exists mbranch (1 2 3 4 0) 1 p) (join-old mp_msk (0 1 2) 1 (0 1 2) __t0CZp243 k m) (exists $sup5638x40x0x0x0 (1 3 4 0 2 5 6) 3 k m p) (exists mbranch (1 2 3 4 0) 2 p m) (exists mp_put (2 3 0 1) 1 k) (join-old $sup5638x40x0x0x1 (1 2 4 5 0 3 6 7) 4 (1 2 4 5 0 3 6 7) __t0CZp243 k m p __t8K90240 l r v) (join-old $sup5638x40x0x0x0 (4 2 3 5 0 1 6) 7 (4 2 3 5 0 1 6) p l m r __t8K90240 k v) (exists mp_put (3 0 2 1) 3 v __t8K90240 k) (exists mp_put (1 2 3 0) 3 l k v) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t3kyC239) (join-old mp_put (0 2 1 3) 4 (0 2 1 3) __t8K90240 k __t3kyC239 v) (join-old mp_put (1 2 3 0) 3 (1 2 3 0) l k v __t630X244) (join-old mp_put_ans (0 1) 1 (0 1) __t630X244 __v0) (let __t9Ap1242 (band k m)) (cmp lt __t9Ap1242 __tconst9a82241)) (head (emit-temp temp636D1974 __t8K90240 __v0 m p r) (mkstruct mbranch (1 2 3 4 0) __t2hPi238 p m __v0 r)) map.slog:41 #f)
  class ReadTask844 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x40x0x0x1index822;  slog::Index** $sup5638x40x0x0x0index823;  slog::Index** mbranchindex824;  slog::Index** mp_mskindex825;  slog::Index** $sup5638x40x0x0x0index826;  slog::Index** mbranchindex827;  slog::Index** mp_putindex828;  slog::Index** $sup5638x40x0x0x1index829;  slog::Index** $sup5638x40x0x0x0index830;  slog::Index** mp_putindex831;  slog::Index** mp_putindex832;  slog::Index** mbranchindex833;  slog::Index** mp_putindex834;  slog::Index** mp_putindex835;  slog::Index** mp_put_ansindex836;  slog::Index** mp_mskdelta837;  slog::Index** $sup5638x40x0x0x1delta838;  slog::Index** $sup5638x40x0x0x0delta839;  slog::Index** mbranchdelta840;  slog::Index** mp_putdelta841;  slog::Index** mp_putdelta842;  slog::Index** mp_put_ansdelta843;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp636D1974");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_msk_ans");
      std::vector<u16> ord845({1, 5, 0, 2, 3, 4, 6, 7});
      slog::Relation* readrel846 = db->getRelation("$sup5638x40x0x0x1");
      $sup5638x40x0x0x1index822 = readrel846->getIndex(ord845, false);
      std::vector<u16> ord847({4, 2, 3, 5, 0, 1, 6});
      slog::Relation* readrel848 = db->getRelation("$sup5638x40x0x0x0");
      $sup5638x40x0x0x0index823 = readrel848->getIndex(ord847, false);
      std::vector<u16> ord849({1, 2, 3, 4, 0});
      slog::Relation* readrel850 = db->getRelation("mbranch");
      mbranchindex824 = readrel850->getIndex(ord849, false);
      std::vector<u16> ord851({0, 1, 2});
      slog::Relation* readrel852 = db->getRelation("mp_msk");
      mp_mskindex825 = readrel852->getIndex(ord851, false);
      std::vector<u16> ord853({0, 1, 2});
      slog::Relation* readrel854 = db->getRelation("mp_msk");
      mp_mskdelta837 = readrel854->getIndex(ord853, true);
      std::vector<u16> ord855({1, 3, 4, 0, 2, 5, 6});
      slog::Relation* readrel856 = db->getRelation("$sup5638x40x0x0x0");
      $sup5638x40x0x0x0index826 = readrel856->getIndex(ord855, false);
      std::vector<u16> ord857({1, 2, 3, 4, 0});
      slog::Relation* readrel858 = db->getRelation("mbranch");
      mbranchindex827 = readrel858->getIndex(ord857, false);
      std::vector<u16> ord859({2, 3, 0, 1});
      slog::Relation* readrel860 = db->getRelation("mp_put");
      mp_putindex828 = readrel860->getIndex(ord859, false);
      std::vector<u16> ord861({1, 2, 4, 5, 0, 3, 6, 7});
      slog::Relation* readrel862 = db->getRelation("$sup5638x40x0x0x1");
      $sup5638x40x0x0x1index829 = readrel862->getIndex(ord861, false);
      std::vector<u16> ord863({1, 2, 4, 5, 0, 3, 6, 7});
      slog::Relation* readrel864 = db->getRelation("$sup5638x40x0x0x1");
      $sup5638x40x0x0x1delta838 = readrel864->getIndex(ord863, true);
      std::vector<u16> ord865({4, 2, 3, 5, 0, 1, 6});
      slog::Relation* readrel866 = db->getRelation("$sup5638x40x0x0x0");
      $sup5638x40x0x0x0index830 = readrel866->getIndex(ord865, false);
      std::vector<u16> ord867({4, 2, 3, 5, 0, 1, 6});
      slog::Relation* readrel868 = db->getRelation("$sup5638x40x0x0x0");
      $sup5638x40x0x0x0delta839 = readrel868->getIndex(ord867, true);
      std::vector<u16> ord869({3, 0, 2, 1});
      slog::Relation* readrel870 = db->getRelation("mp_put");
      mp_putindex831 = readrel870->getIndex(ord869, false);
      std::vector<u16> ord871({1, 2, 3, 0});
      slog::Relation* readrel872 = db->getRelation("mp_put");
      mp_putindex832 = readrel872->getIndex(ord871, false);
      std::vector<u16> ord873({1, 2, 3, 4, 0});
      slog::Relation* readrel874 = db->getRelation("mbranch");
      mbranchindex833 = readrel874->getIndex(ord873, false);
      std::vector<u16> ord875({1, 2, 3, 4, 0});
      slog::Relation* readrel876 = db->getRelation("mbranch");
      mbranchdelta840 = readrel876->getIndex(ord875, true);
      std::vector<u16> ord877({0, 2, 1, 3});
      slog::Relation* readrel878 = db->getRelation("mp_put");
      mp_putindex834 = readrel878->getIndex(ord877, false);
      std::vector<u16> ord879({0, 2, 1, 3});
      slog::Relation* readrel880 = db->getRelation("mp_put");
      mp_putdelta841 = readrel880->getIndex(ord879, true);
      std::vector<u16> ord881({1, 2, 3, 0});
      slog::Relation* readrel882 = db->getRelation("mp_put");
      mp_putindex835 = readrel882->getIndex(ord881, false);
      std::vector<u16> ord883({1, 2, 3, 0});
      slog::Relation* readrel884 = db->getRelation("mp_put");
      mp_putdelta842 = readrel884->getIndex(ord883, true);
      std::vector<u16> ord885({0, 1});
      slog::Relation* readrel886 = db->getRelation("mp_put_ans");
      mp_put_ansindex836 = readrel886->getIndex(ord885, false);
      std::vector<u16> ord887({0, 1});
      slog::Relation* readrel888 = db->getRelation("mp_put_ans");
      mp_put_ansdelta843 = readrel888->getIndex(ord887, true);
  
    }
    ReadTask844(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c167 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c27 = _t[1];
        if (!slog::exists_probe<8,2>($sup5638x40x0x0x1index822, std::array<u64,8>{v_c168, v_c27, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<7,1>($sup5638x40x0x0x0index823, std::array<u64,7>{v_c27, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex824, std::array<u64,5>{v_c27, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(mp_mskindex825, mp_mskdelta837, std::array<u64,3>{v_c168, 0, 0}, [&](const std::array<u64,3>& m889) {
          u64 v_c4 = m889[1]; u64 v_c25 = m889[2];
          if (!slog::exists_probe<7,3>($sup5638x40x0x0x0index826, std::array<u64,7>{v_c4, v_c25, v_c27, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,2>(mbranchindex827, std::array<u64,5>{v_c27, v_c25, 0, 0, 0})) return;
          if (!slog::exists_probe<4,1>(mp_putindex828, std::array<u64,4>{v_c4, 0, 0, 0})) return;
          slog::join_probe_old<8,4>($sup5638x40x0x0x1index829, $sup5638x40x0x0x1delta838, std::array<u64,8>{v_c168, v_c4, v_c25, v_c27, 0, 0, 0, 0}, [&](const std::array<u64,8>& m890) {
            u64 v_c169 = m890[4]; u64 v_c24 = m890[5]; u64 v_c29 = m890[6]; u64 v_c3 = m890[7];
            slog::join_probe_old<7,7>($sup5638x40x0x0x0index830, $sup5638x40x0x0x0delta839, std::array<u64,7>{v_c27, v_c24, v_c25, v_c29, v_c169, v_c4, v_c3}, [&](const std::array<u64,7>& m891) {
              if (!slog::exists_probe<4,3>(mp_putindex831, std::array<u64,4>{v_c3, v_c169, v_c4, 0})) return;
              if (!slog::exists_probe<4,3>(mp_putindex832, std::array<u64,4>{v_c24, v_c4, v_c3, 0})) return;
              slog::join_probe_old<5,4>(mbranchindex833, mbranchdelta840, std::array<u64,5>{v_c27, v_c25, v_c24, v_c29, 0}, [&](const std::array<u64,5>& m892) {
                u64 v_c170 = m892[4];
                slog::join_probe_old<4,4>(mp_putindex834, mp_putdelta841, std::array<u64,4>{v_c169, v_c4, v_c170, v_c3}, [&](const std::array<u64,4>& m893) {
                  slog::join_probe_old<4,3>(mp_putindex835, mp_putdelta842, std::array<u64,4>{v_c24, v_c4, v_c3, 0}, [&](const std::array<u64,4>& m894) {
                    u64 v_c171 = m894[3];
                    slog::join_probe_old<2,1>(mp_put_ansindex836, mp_put_ansdelta843, std::array<u64,2>{v_c171, 0}, [&](const std::array<u64,2>& m895) {
                      u64 v_c36 = m895[1];
                      u64 v_c172 = _prim_band(db, v_c4, v_c25);
                      if (v_c172 == slog_error) { slog::emit_pending_error(db, "map.slog:41"); return; }
                      u64 v_c173 = _prim_lt(db, v_c172, v_c167);
                      if (v_c173 == slog_error) { slog::emit_pending_error(db, "map.slog:41"); return; }
                      if (!v_c173) return;
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c169, v_c36, v_c25, v_c27, v_c29});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c27, v_c25, v_c36, v_c29}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:41", "delta:mp_msk_ans", _fires);
  
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
  // (crule (pre (let __trid9hLR1438 constd9f3167b950244706dc6dbb2) (let __trel1gN71439 constdd7bbf31ce5f578b9805e840) (let __tcol9yB21440 const5feceb66ffc86f38d952786c) (let __trel0HpK1441 constdd7bbf31ce5f578b9805e840) (let __tcol5sk61442 const6b86b273ff34fce19d6b804e)) (scan $sup5638x107x0x0x0 __d0 l m n p q r u v) (body) (head (tycheck p (accept int) __trid9hLR1438 __trel1gN71439 __tcol9yB21440 (1 2 3 4 0)) (tycheck n (accept int) __trid9hLR1438 __trel0HpK1441 __tcol5sk61442 (1 2 3 4 0)) (mkstruct mp_msk (1 2 0) __2Gbw1437 p n)) map.slog:108 #f)
  class ReadTask897 : public slog::Task
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
      outer_rel = db->getRelation("$sup5638x107x0x0x0");
  
    }
    ReadTask897(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c174 = v_constd9f3167b950244706dc6dbb2;
      u64 v_c175 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c176 = v_const5feceb66ffc86f38d952786c;
      u64 v_c177 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c178 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c15 = _t[0];
        u64 v_c24 = _t[1];
        u64 v_c25 = _t[2];
        u64 v_c26 = _t[3];
        u64 v_c27 = _t[4];
        u64 v_c28 = _t[5];
        u64 v_c29 = _t[6];
        u64 v_c30 = _t[7];
        u64 v_c3 = _t[8];
        ++_fires;
        if (!(is_int(v_c27)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c174, v_c175, v_c176, v_c27}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c26)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c174, v_c177, v_c178, v_c26}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c27, v_c26}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:108", "delta:$sup5638x107x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask897* _cont = new ReadTask897(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask897(db,b), false);
  // (crule (pre (let __tconst6yBc1412 const0122baa3ac55f1b433944eb1)) (scan temp16EG1919 __t9sv95) (body (join _enum (1 0) 1 __tconst6yBc1412 __t55Md2) (join boolval (1 0) 1 __t55Md2 __t5Yya3)) (head (emit delta_ans (0 1) __t9sv95 __t5Yya3)) interp.slog:123 #f)
  class ReadTask900 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex898;  slog::Index** boolvalindex899;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("delta_ans");
      std::vector<u16> ord901({0, 1});
      slog::Relation* readrel902 = db->getRelation("delta_ans");
      head_index[0] = readrel902->getIndex(ord901, false);
      outer_rel = db->getRelation("temp16EG1919");
      std::vector<u16> ord903({1, 0});
      slog::Relation* readrel904 = db->getRelation("_enum");
      _enumindex898 = readrel904->getIndex(ord903, false);
      std::vector<u16> ord905({1, 0});
      slog::Relation* readrel906 = db->getRelation("boolval");
      boolvalindex899 = readrel906->getIndex(ord905, false);
  
    }
    ReadTask900(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c179 = v_const0122baa3ac55f1b433944eb1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c180 = _t[0];
        slog::join_probe<2,1>(_enumindex898, std::array<u64,2>{v_c179, 0}, [&](const std::array<u64,2>& m907) {
          u64 v_c181 = m907[1];
          slog::join_probe<2,1>(boolvalindex899, std::array<u64,2>{v_c181, 0}, [&](const std::array<u64,2>& m908) {
            u64 v_c182 = m908[1];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c180, v_c182}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:123", "delta:temp16EG1919", _fires);
  
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
  // (crule (pre (let __tconst6uLy1418 constcd2a69ce5ca278db1d6da969) (let _00024sqc5ZED979 constd4735e3a265e16eee03f5971) (let _00024sqc8Ktf980 const5feceb66ffc86f38d952786c) (let _00024sqc1r6Y981 const6b86b273ff34fce19d6b804e) (let _00024sqo4ml8982 const5feceb66ffc86f38d952786c) (let _00024sqo9GuQ983 const6b86b273ff34fce19d6b804e) (let _00024sqo9DrV984 const6b86b273ff34fce19d6b804e) (let _00024sqo0wvc985 const5feceb66ffc86f38d952786c) (let __trid2ZoU1419 constfdb0a95399e17c48d6f65653) (let __trel2kf41420 constdede4476644eb06b5a48b866) (let __tcol0QrU1421 const6b86b273ff34fce19d6b804e)) (probe $seq_atr (1 0 2) 1 _00024sqo9DrV984 __t0ebd433 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo4ml8982 __t0ebd433 _00024seq2) (join $seq_at (1 0 2) 3 _00024sqo9GuQ983 __t0ebd433 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo0wvc985 __t0ebd433 _00024seq2) (join _enum (0 1) 2 __t0ebd433 __tconst6uLy1418) (join delta (2 0 1) 1 _00024seq2 __t9b4a431 op) (join arithmetic_op (0) 1 op) (letp _00024sql4NVe977 (aslst _00024seq2)) (let chk8y1l1865 (llen _00024sql4NVe977)) (eq _00024sqc5ZED979 chk8y1l1865) (letp chk4Y7d1866 (lref _00024sql4NVe977 _00024sqc8Ktf980)) (eq __t0ebd433 chk4Y7d1866) (letp chk0plO1867 (lref _00024sql4NVe977 _00024sqc1r6Y981)) (eq __t0ebd433 chk0plO1867)) (head (tycheck __t0ebd433 (accept (struct boolval) (struct closure) (struct _enum) (struct prim) (struct symval)) __trid2ZoU1419 __trel2kf41420 __tcol0QrU1421 (1 2 3 4 0)) (emit delta_ans (0 1) __t9b4a431 __t0ebd433)) interp.slog:116 #f)
  class ReadTask921 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex909;  slog::Index** $seq_atindex910;  slog::Index** $seq_atrindex911;  slog::Index** _enumindex912;  slog::Index** deltaindex913;  slog::Index** arithmetic_opindex914;  slog::Index** $seq_atrdelta915;
    u32 sid918;  u32 sid916;  u32 sid917;  u32 sid919;  u32 sid920;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("delta_ans");
      std::vector<u16> ord922({0, 1});
      slog::Relation* readrel923 = db->getRelation("delta_ans");
      head_index[1] = readrel923->getIndex(ord922, false);
      std::vector<u16> ord924({1, 0, 2});
      slog::Relation* readrel925 = db->getRelation("$seq_atr");
      driver_index = readrel925->getIndex(ord924, true);
      std::vector<u16> ord926({1, 0, 2});
      slog::Relation* readrel927 = db->getRelation("$seq_at");
      $seq_atindex909 = readrel927->getIndex(ord926, false);
      std::vector<u16> ord928({1, 0, 2});
      slog::Relation* readrel929 = db->getRelation("$seq_at");
      $seq_atindex910 = readrel929->getIndex(ord928, false);
      std::vector<u16> ord930({1, 0, 2});
      slog::Relation* readrel931 = db->getRelation("$seq_atr");
      $seq_atrindex911 = readrel931->getIndex(ord930, false);
      std::vector<u16> ord932({1, 0, 2});
      slog::Relation* readrel933 = db->getRelation("$seq_atr");
      $seq_atrdelta915 = readrel933->getIndex(ord932, true);
      std::vector<u16> ord934({0, 1});
      slog::Relation* readrel935 = db->getRelation("_enum");
      _enumindex912 = readrel935->getIndex(ord934, false);
      std::vector<u16> ord936({2, 0, 1});
      slog::Relation* readrel937 = db->getRelation("delta");
      deltaindex913 = readrel937->getIndex(ord936, false);
      std::vector<u16> ord938({0});
      slog::Relation* readrel939 = db->getRelation("arithmetic_op");
      arithmetic_opindex914 = readrel939->getIndex(ord938, false);
      sid918 = db->getRelation("_enum")->getStructId();
      sid916 = db->getRelation("boolval")->getStructId();
      sid917 = db->getRelation("closure")->getStructId();
      sid919 = db->getRelation("prim")->getStructId();
      sid920 = db->getRelation("symval")->getStructId();
  
    }
    ReadTask921(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c183 = v_constcd2a69ce5ca278db1d6da969;
      u64 v_c184 = v_constd4735e3a265e16eee03f5971;
      u64 v_c185 = v_const5feceb66ffc86f38d952786c;
      u64 v_c186 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c187 = v_const5feceb66ffc86f38d952786c;
      u64 v_c188 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c189 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c190 = v_const5feceb66ffc86f38d952786c;
      u64 v_c191 = v_constfdb0a95399e17c48d6f65653;
      u64 v_c192 = v_constdede4476644eb06b5a48b866;
      u64 v_c193 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c189, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m940) {
        u64 v_c194 = m940[1];
        u64 v_c195 = m940[2];
        if (buckethash(v_c194) != bucket) return;
        slog::join_probe<3,3>($seq_atindex909, std::array<u64,3>{v_c187, v_c194, v_c195}, [&](const std::array<u64,3>& m941) {
          slog::join_probe<3,3>($seq_atindex910, std::array<u64,3>{v_c188, v_c194, v_c195}, [&](const std::array<u64,3>& m942) {
            slog::join_probe_old<3,3>($seq_atrindex911, $seq_atrdelta915, std::array<u64,3>{v_c190, v_c194, v_c195}, [&](const std::array<u64,3>& m943) {
              slog::join_probe<2,2>(_enumindex912, std::array<u64,2>{v_c194, v_c183}, [&](const std::array<u64,2>& m944) {
                slog::join_probe<3,1>(deltaindex913, std::array<u64,3>{v_c195, 0, 0}, [&](const std::array<u64,3>& m945) {
                  u64 v_c196 = m945[1]; u64 v_c67 = m945[2];
                  slog::join_probe<1,1>(arithmetic_opindex914, std::array<u64,1>{v_c67}, [&](const std::array<u64,1>& m946) {
                    bool ok947 = true;
                    u64 v_c197 = _prim_aslst(db, v_c195, &ok947);
                    if (!ok947) return;
                    u64 v_c198 = _prim_llen(db, v_c197);
                    if (v_c198 == slog_error) { slog::emit_pending_error(db, "interp.slog:116"); return; }
                    if (v_c184 != v_c198) return;
                    bool ok948 = true;
                    u64 v_c199 = _prim_lref(db, v_c197, v_c185, &ok948);
                    if (!ok948) return;
                    if (v_c194 != v_c199) return;
                    bool ok949 = true;
                    u64 v_c200 = _prim_lref(db, v_c197, v_c186, &ok949);
                    if (!ok949) return;
                    if (v_c194 != v_c200) return;
                    ++_fires;
                    if (!((is_struct(v_c194) && (decode_struct_id(v_c194) == sid916 || decode_struct_id(v_c194) == sid917 || decode_struct_id(v_c194) == sid918 || decode_struct_id(v_c194) == sid919 || decode_struct_id(v_c194) == sid920))))
                    {
                      slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c191, v_c192, v_c193, v_c194}, std::array<u16,5>{1, 2, 3, 4, 0});
                      return;
                    }
                    slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c196, v_c194}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:116", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask921* _cont = new ReadTask921(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask921(db,b), false);
  // (crule (pre) (scan $sup5638x29x0x0x1 __d0 __d1 __v0 p0 p1 t0 t1) (body (let __t7knf810 (bxor p0 p1))) (head (emit-temp temp8lYe1877 __t7knf810)) map.slog:30 #f)
  class ReadTask950 : public slog::Task
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
      head_rel[0] = db->getRelation("temp8lYe1877");
      outer_rel = db->getRelation("$sup5638x29x0x0x1");
  
    }
    ReadTask950(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c15 = _t[0];
        u64 v_c201 = _t[1];
        u64 v_c36 = _t[2];
        u64 v_c47 = _t[3];
        u64 v_c55 = _t[4];
        u64 v_c56 = _t[5];
        u64 v_c57 = _t[6];
        u64 v_c202 = _prim_bxor(db, v_c47, v_c55);
        if (v_c202 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c202});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:30", "delta:$sup5638x29x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask950* _cont = new ReadTask950(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask950(db,b), false);
  // (crule (pre) (scan eval_args_ans __t11mn554 vs) (body (join-old eval_args (0 1 2 3) 1 (0 1 2 3) __t11mn554 es rho t) (exists eval (2 3 0 1) 2 rho t) (join $sup70016x75x0x0x0 (2 3 4 0 1) 3 es rho t __d0 ef) (join-old eval (1 2 3 0) 3 (1 2 3 0) ef rho t __t6oYx552) (join eval_ans (0 1) 1 __t6oYx552 __t21iW553) (join-old prim (0 1) 1 (0 1) __t21iW553 op)) (head (mkstruct delta (1 2 0) __5Kx31559 op vs)) interp.slog:76 #f)
  class ReadTask960 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eval_argsindex951;  slog::Index** evalindex952;  slog::Index** $sup70016x75x0x0x0index953;  slog::Index** evalindex954;  slog::Index** eval_ansindex955;  slog::Index** primindex956;  slog::Index** eval_argsdelta957;  slog::Index** evaldelta958;  slog::Index** primdelta959;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("delta");
      outer_rel = db->getRelation("eval_args_ans");
      std::vector<u16> ord961({0, 1, 2, 3});
      slog::Relation* readrel962 = db->getRelation("eval_args");
      eval_argsindex951 = readrel962->getIndex(ord961, false);
      std::vector<u16> ord963({0, 1, 2, 3});
      slog::Relation* readrel964 = db->getRelation("eval_args");
      eval_argsdelta957 = readrel964->getIndex(ord963, true);
      std::vector<u16> ord965({2, 3, 0, 1});
      slog::Relation* readrel966 = db->getRelation("eval");
      evalindex952 = readrel966->getIndex(ord965, false);
      std::vector<u16> ord967({2, 3, 4, 0, 1});
      slog::Relation* readrel968 = db->getRelation("$sup70016x75x0x0x0");
      $sup70016x75x0x0x0index953 = readrel968->getIndex(ord967, false);
      std::vector<u16> ord969({1, 2, 3, 0});
      slog::Relation* readrel970 = db->getRelation("eval");
      evalindex954 = readrel970->getIndex(ord969, false);
      std::vector<u16> ord971({1, 2, 3, 0});
      slog::Relation* readrel972 = db->getRelation("eval");
      evaldelta958 = readrel972->getIndex(ord971, true);
      std::vector<u16> ord973({0, 1});
      slog::Relation* readrel974 = db->getRelation("eval_ans");
      eval_ansindex955 = readrel974->getIndex(ord973, false);
      std::vector<u16> ord975({0, 1});
      slog::Relation* readrel976 = db->getRelation("prim");
      primindex956 = readrel976->getIndex(ord975, false);
      std::vector<u16> ord977({0, 1});
      slog::Relation* readrel978 = db->getRelation("prim");
      primdelta959 = readrel978->getIndex(ord977, true);
  
    }
    ReadTask960(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c20 = _t[1];
        slog::join_probe_old<4,1>(eval_argsindex951, eval_argsdelta957, std::array<u64,4>{v_c69, 0, 0, 0}, [&](const std::array<u64,4>& m979) {
          u64 v_c16 = m979[1]; u64 v_c13 = m979[2]; u64 v_c14 = m979[3];
          if (!slog::exists_probe<4,2>(evalindex952, std::array<u64,4>{v_c13, v_c14, 0, 0})) return;
          slog::join_probe<5,3>($sup70016x75x0x0x0index953, std::array<u64,5>{v_c16, v_c13, v_c14, 0, 0}, [&](const std::array<u64,5>& m980) {
            u64 v_c15 = m980[3]; u64 v_c12 = m980[4];
            slog::join_probe_old<4,3>(evalindex954, evaldelta958, std::array<u64,4>{v_c12, v_c13, v_c14, 0}, [&](const std::array<u64,4>& m981) {
              u64 v_c68 = m981[3];
              slog::join_probe<2,1>(eval_ansindex955, std::array<u64,2>{v_c68, 0}, [&](const std::array<u64,2>& m982) {
                u64 v_c66 = m982[1];
                slog::join_probe_old<2,1>(primindex956, primdelta959, std::array<u64,2>{v_c66, 0}, [&](const std::array<u64,2>& m983) {
                  u64 v_c67 = m983[1];
                  ++_fires;
                  slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c67, v_c20}, std::array<u16,3>{1, 2, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:76", "delta:eval_args_ans", _fires);
  
      if (!_done)
      {
        ReadTask960* _cont = new ReadTask960(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask960(db,b), false);
  // (crule (pre (let __t0SOq399 (lempty))) (scan lst_take __t4nP5402 __t3PGq401 k) (body (join klimit (0) 1 k) (join lst_take_ans (0 1) 1 __t4nP5402 __v0) (join tick (0 2 1) 0 __t7qQQ398 t site) (let __t7jWC400 (lpush __t0SOq399 site)) (let chk43sx1918 (lcat __t7jWC400 t)) (eq __t3PGq401 chk43sx1918)) (head (emit tick_ans (0 1) __t7qQQ398 __v0)) context.slog:11 #f)
  class ReadTask987 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** klimitindex984;  slog::Index** lst_take_ansindex985;  slog::Index** tickindex986;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("tick_ans");
      std::vector<u16> ord988({0, 1});
      slog::Relation* readrel989 = db->getRelation("tick_ans");
      head_index[0] = readrel989->getIndex(ord988, false);
      outer_rel = db->getRelation("lst_take");
      std::vector<u16> ord990({0});
      slog::Relation* readrel991 = db->getRelation("klimit");
      klimitindex984 = readrel991->getIndex(ord990, false);
      std::vector<u16> ord992({0, 1});
      slog::Relation* readrel993 = db->getRelation("lst_take_ans");
      lst_take_ansindex985 = readrel993->getIndex(ord992, false);
      std::vector<u16> ord994({0, 2, 1});
      slog::Relation* readrel995 = db->getRelation("tick");
      tickindex986 = readrel995->getIndex(ord994, false);
  
    }
    ReadTask987(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c203 = _prim_lempty(db);
      if (v_c203 == slog_error) { slog::emit_pending_error(db, "context.slog:11"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c204 = _t[0];
        u64 v_c205 = _t[1];
        u64 v_c4 = _t[2];
        slog::join_probe<1,1>(klimitindex984, std::array<u64,1>{v_c4}, [&](const std::array<u64,1>& m996) {
          slog::join_probe<2,1>(lst_take_ansindex985, std::array<u64,2>{v_c204, 0}, [&](const std::array<u64,2>& m997) {
            u64 v_c36 = m997[1];
            slog::join_all<3>(tickindex986, [&](const std::array<u64,3>& m998) {
              u64 v_c206 = m998[0]; u64 v_c14 = m998[1]; u64 v_c207 = m998[2];
              u64 v_c208 = _prim_lpush(db, v_c203, v_c207);
              if (v_c208 == slog_error) { slog::emit_pending_error(db, "context.slog:11"); return; }
              u64 v_c209 = _prim_lcat(db, v_c208, v_c14);
              if (v_c209 == slog_error) { slog::emit_pending_error(db, "context.slog:11"); return; }
              if (v_c205 != v_c209) return;
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c206, v_c36}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("context.slog:11", "delta:lst_take", _fires);
  
      if (!_done)
      {
        ReadTask987* _cont = new ReadTask987(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask987(db,b), false);
  // (crule (pre) (scan temp60fT1907 __t7b5L282) (body) (head (mkstruct mp_hsb (1 0) __8YVU1436 __t7b5L282)) map.slog:30 #f)
  class ReadTask999 : public slog::Task
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
      outer_rel = db->getRelation("temp60fT1907");
  
    }
    ReadTask999(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c210 = _t[0];
        ++_fires;
        slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c210}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:30", "delta:temp60fT1907", _fires);
  
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
  // (crule (pre) (scan eval __t7TaT537 eb __v0 t2) (body (exists tick_ans (1 0) 1 t2) (exists extend_env_ans (1 0) 1 __v0) (exists extend_env (3 0 1 2) 1 t2) (exists $sup70016x51x0x0x1 (4 10 8 12 0 1 2 3 5 6 7 9 11) 2 eb t2) (exists lambda (2 0 1) 1 eb) (join eval_ans (0 1) 1 __t7TaT537 v) (join tick_ans (1 0) 1 t2 __t0CD9539) (exists $sup70016x51x0x0x1 (3 10 4 0 1 2 5 6 7 8 9 11 12) 3 __t0CD9539 t2 eb) (join extend_env_ans (1 0) 1 __v0 __t5fzh540) (join-old extend_env (3 0 1 2) 2 (3 0 1 2) t2 __t5fzh540 rhoc xs) (exists lambda (1 2 0) 2 xs eb) (exists closure (2 0 1) 1 rhoc) (join $sup70016x51x0x0x1 (8 10 12 3 4 0 1 2 5 6 7 9 11) 5 rhoc t2 xs __t0CD9539 eb __t2z6s532 __t5qy8533 __t2srV536 ef es rho t vs) (join $sup70016x51x0x0x0 (4 0 3 1 2) 5 t __t2z6s532 rho ef es) (join eval (2 3 0 1) 4 rho t __t5qy8533 ef) (join eval_args (3 2 0 1) 4 t rho __t2srV536 es) (exists app (1 2 0) 2 ef es) (exists tick (0 2 1) 2 __t0CD9539 t) (exists eval_args_ans (0 1) 2 __t2srV536 vs) (exists eval_ans (0 1) 1 __t5qy8533) (join eval (2 3 0 1) 3 rho t __t2z6s532 __t5a7h538) (join-old app (0 1 2) 3 (0 1 2) __t5a7h538 ef es) (join-old tick (0 2 1) 3 (0 2 1) __t0CD9539 t __t5a7h538) (join eval_args_ans (0 1) 2 __t2srV536 vs) (join lambda (1 2 0) 2 xs eb __t6iPm534) (join closure (1 2 0) 2 __t6iPm534 rhoc __t9dfl535) (join eval_ans (0 1) 2 __t5qy8533 __t9dfl535)) (head (emit eval_ans (0 1) __t2z6s532 v)) interp.slog:52 #f)
  class ReadTask1030 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** tick_ansindex1000;  slog::Index** extend_env_ansindex1001;  slog::Index** extend_envindex1002;  slog::Index** $sup70016x51x0x0x1index1003;  slog::Index** lambdaindex1004;  slog::Index** eval_ansindex1005;  slog::Index** tick_ansindex1006;  slog::Index** $sup70016x51x0x0x1index1007;  slog::Index** extend_env_ansindex1008;  slog::Index** extend_envindex1009;  slog::Index** lambdaindex1010;  slog::Index** closureindex1011;  slog::Index** $sup70016x51x0x0x1index1012;  slog::Index** $sup70016x51x0x0x0index1013;  slog::Index** evalindex1014;  slog::Index** eval_argsindex1015;  slog::Index** appindex1016;  slog::Index** tickindex1017;  slog::Index** eval_args_ansindex1018;  slog::Index** eval_ansindex1019;  slog::Index** evalindex1020;  slog::Index** appindex1021;  slog::Index** tickindex1022;  slog::Index** eval_args_ansindex1023;  slog::Index** lambdaindex1024;  slog::Index** closureindex1025;  slog::Index** eval_ansindex1026;  slog::Index** extend_envdelta1027;  slog::Index** appdelta1028;  slog::Index** tickdelta1029;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1031({0, 1});
      slog::Relation* readrel1032 = db->getRelation("eval_ans");
      head_index[0] = readrel1032->getIndex(ord1031, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord1033({1, 0});
      slog::Relation* readrel1034 = db->getRelation("tick_ans");
      tick_ansindex1000 = readrel1034->getIndex(ord1033, false);
      std::vector<u16> ord1035({1, 0});
      slog::Relation* readrel1036 = db->getRelation("extend_env_ans");
      extend_env_ansindex1001 = readrel1036->getIndex(ord1035, false);
      std::vector<u16> ord1037({3, 0, 1, 2});
      slog::Relation* readrel1038 = db->getRelation("extend_env");
      extend_envindex1002 = readrel1038->getIndex(ord1037, false);
      std::vector<u16> ord1039({4, 10, 8, 12, 0, 1, 2, 3, 5, 6, 7, 9, 11});
      slog::Relation* readrel1040 = db->getRelation("$sup70016x51x0x0x1");
      $sup70016x51x0x0x1index1003 = readrel1040->getIndex(ord1039, false);
      std::vector<u16> ord1041({2, 0, 1});
      slog::Relation* readrel1042 = db->getRelation("lambda");
      lambdaindex1004 = readrel1042->getIndex(ord1041, false);
      std::vector<u16> ord1043({0, 1});
      slog::Relation* readrel1044 = db->getRelation("eval_ans");
      eval_ansindex1005 = readrel1044->getIndex(ord1043, false);
      std::vector<u16> ord1045({1, 0});
      slog::Relation* readrel1046 = db->getRelation("tick_ans");
      tick_ansindex1006 = readrel1046->getIndex(ord1045, false);
      std::vector<u16> ord1047({3, 10, 4, 0, 1, 2, 5, 6, 7, 8, 9, 11, 12});
      slog::Relation* readrel1048 = db->getRelation("$sup70016x51x0x0x1");
      $sup70016x51x0x0x1index1007 = readrel1048->getIndex(ord1047, false);
      std::vector<u16> ord1049({1, 0});
      slog::Relation* readrel1050 = db->getRelation("extend_env_ans");
      extend_env_ansindex1008 = readrel1050->getIndex(ord1049, false);
      std::vector<u16> ord1051({3, 0, 1, 2});
      slog::Relation* readrel1052 = db->getRelation("extend_env");
      extend_envindex1009 = readrel1052->getIndex(ord1051, false);
      std::vector<u16> ord1053({3, 0, 1, 2});
      slog::Relation* readrel1054 = db->getRelation("extend_env");
      extend_envdelta1027 = readrel1054->getIndex(ord1053, true);
      std::vector<u16> ord1055({1, 2, 0});
      slog::Relation* readrel1056 = db->getRelation("lambda");
      lambdaindex1010 = readrel1056->getIndex(ord1055, false);
      std::vector<u16> ord1057({2, 0, 1});
      slog::Relation* readrel1058 = db->getRelation("closure");
      closureindex1011 = readrel1058->getIndex(ord1057, false);
      std::vector<u16> ord1059({8, 10, 12, 3, 4, 0, 1, 2, 5, 6, 7, 9, 11});
      slog::Relation* readrel1060 = db->getRelation("$sup70016x51x0x0x1");
      $sup70016x51x0x0x1index1012 = readrel1060->getIndex(ord1059, false);
      std::vector<u16> ord1061({4, 0, 3, 1, 2});
      slog::Relation* readrel1062 = db->getRelation("$sup70016x51x0x0x0");
      $sup70016x51x0x0x0index1013 = readrel1062->getIndex(ord1061, false);
      std::vector<u16> ord1063({2, 3, 0, 1});
      slog::Relation* readrel1064 = db->getRelation("eval");
      evalindex1014 = readrel1064->getIndex(ord1063, false);
      std::vector<u16> ord1065({3, 2, 0, 1});
      slog::Relation* readrel1066 = db->getRelation("eval_args");
      eval_argsindex1015 = readrel1066->getIndex(ord1065, false);
      std::vector<u16> ord1067({1, 2, 0});
      slog::Relation* readrel1068 = db->getRelation("app");
      appindex1016 = readrel1068->getIndex(ord1067, false);
      std::vector<u16> ord1069({0, 2, 1});
      slog::Relation* readrel1070 = db->getRelation("tick");
      tickindex1017 = readrel1070->getIndex(ord1069, false);
      std::vector<u16> ord1071({0, 1});
      slog::Relation* readrel1072 = db->getRelation("eval_args_ans");
      eval_args_ansindex1018 = readrel1072->getIndex(ord1071, false);
      std::vector<u16> ord1073({0, 1});
      slog::Relation* readrel1074 = db->getRelation("eval_ans");
      eval_ansindex1019 = readrel1074->getIndex(ord1073, false);
      std::vector<u16> ord1075({2, 3, 0, 1});
      slog::Relation* readrel1076 = db->getRelation("eval");
      evalindex1020 = readrel1076->getIndex(ord1075, false);
      std::vector<u16> ord1077({0, 1, 2});
      slog::Relation* readrel1078 = db->getRelation("app");
      appindex1021 = readrel1078->getIndex(ord1077, false);
      std::vector<u16> ord1079({0, 1, 2});
      slog::Relation* readrel1080 = db->getRelation("app");
      appdelta1028 = readrel1080->getIndex(ord1079, true);
      std::vector<u16> ord1081({0, 2, 1});
      slog::Relation* readrel1082 = db->getRelation("tick");
      tickindex1022 = readrel1082->getIndex(ord1081, false);
      std::vector<u16> ord1083({0, 2, 1});
      slog::Relation* readrel1084 = db->getRelation("tick");
      tickdelta1029 = readrel1084->getIndex(ord1083, true);
      std::vector<u16> ord1085({0, 1});
      slog::Relation* readrel1086 = db->getRelation("eval_args_ans");
      eval_args_ansindex1023 = readrel1086->getIndex(ord1085, false);
      std::vector<u16> ord1087({1, 2, 0});
      slog::Relation* readrel1088 = db->getRelation("lambda");
      lambdaindex1024 = readrel1088->getIndex(ord1087, false);
      std::vector<u16> ord1089({1, 2, 0});
      slog::Relation* readrel1090 = db->getRelation("closure");
      closureindex1025 = readrel1090->getIndex(ord1089, false);
      std::vector<u16> ord1091({0, 1});
      slog::Relation* readrel1092 = db->getRelation("eval_ans");
      eval_ansindex1026 = readrel1092->getIndex(ord1091, false);
  
    }
    ReadTask1030(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c211 = _t[0];
        u64 v_c11 = _t[1];
        u64 v_c36 = _t[2];
        u64 v_c21 = _t[3];
        if (!slog::exists_probe<2,1>(tick_ansindex1000, std::array<u64,2>{v_c21, 0})) return;
        if (!slog::exists_probe<2,1>(extend_env_ansindex1001, std::array<u64,2>{v_c36, 0})) return;
        if (!slog::exists_probe<4,1>(extend_envindex1002, std::array<u64,4>{v_c21, 0, 0, 0})) return;
        if (!slog::exists_probe<13,2>($sup70016x51x0x0x1index1003, std::array<u64,13>{v_c11, v_c21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1004, std::array<u64,3>{v_c11, 0, 0})) return;
        slog::join_probe<2,1>(eval_ansindex1005, std::array<u64,2>{v_c211, 0}, [&](const std::array<u64,2>& m1093) {
          u64 v_c3 = m1093[1];
          slog::join_probe<2,1>(tick_ansindex1006, std::array<u64,2>{v_c21, 0}, [&](const std::array<u64,2>& m1094) {
            u64 v_c212 = m1094[1];
            if (!slog::exists_probe<13,3>($sup70016x51x0x0x1index1007, std::array<u64,13>{v_c212, v_c21, v_c11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
            slog::join_probe<2,1>(extend_env_ansindex1008, std::array<u64,2>{v_c36, 0}, [&](const std::array<u64,2>& m1095) {
              u64 v_c213 = m1095[1];
              slog::join_probe_old<4,2>(extend_envindex1009, extend_envdelta1027, std::array<u64,4>{v_c21, v_c213, 0, 0}, [&](const std::array<u64,4>& m1096) {
                u64 v_c8 = m1096[2]; u64 v_c10 = m1096[3];
                if (!slog::exists_probe<3,2>(lambdaindex1010, std::array<u64,3>{v_c10, v_c11, 0})) return;
                if (!slog::exists_probe<3,1>(closureindex1011, std::array<u64,3>{v_c8, 0, 0})) return;
                slog::join_probe<13,5>($sup70016x51x0x0x1index1012, std::array<u64,13>{v_c8, v_c21, v_c10, v_c212, v_c11, 0, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,13>& m1097) {
                  u64 v_c214 = m1097[5]; u64 v_c215 = m1097[6]; u64 v_c216 = m1097[7]; u64 v_c12 = m1097[8]; u64 v_c16 = m1097[9]; u64 v_c13 = m1097[10]; u64 v_c14 = m1097[11]; u64 v_c20 = m1097[12];
                  slog::join_probe<5,5>($sup70016x51x0x0x0index1013, std::array<u64,5>{v_c14, v_c214, v_c13, v_c12, v_c16}, [&](const std::array<u64,5>& m1098) {
                    slog::join_probe<4,4>(evalindex1014, std::array<u64,4>{v_c13, v_c14, v_c215, v_c12}, [&](const std::array<u64,4>& m1099) {
                      slog::join_probe<4,4>(eval_argsindex1015, std::array<u64,4>{v_c14, v_c13, v_c216, v_c16}, [&](const std::array<u64,4>& m1100) {
                        if (!slog::exists_probe<3,2>(appindex1016, std::array<u64,3>{v_c12, v_c16, 0})) return;
                        if (!slog::exists_probe<3,2>(tickindex1017, std::array<u64,3>{v_c212, v_c14, 0})) return;
                        if (!slog::exists_probe<2,2>(eval_args_ansindex1018, std::array<u64,2>{v_c216, v_c20})) return;
                        if (!slog::exists_probe<2,1>(eval_ansindex1019, std::array<u64,2>{v_c215, 0})) return;
                        slog::join_probe<4,3>(evalindex1020, std::array<u64,4>{v_c13, v_c14, v_c214, 0}, [&](const std::array<u64,4>& m1101) {
                          u64 v_c217 = m1101[3];
                          slog::join_probe_old<3,3>(appindex1021, appdelta1028, std::array<u64,3>{v_c217, v_c12, v_c16}, [&](const std::array<u64,3>& m1102) {
                            slog::join_probe_old<3,3>(tickindex1022, tickdelta1029, std::array<u64,3>{v_c212, v_c14, v_c217}, [&](const std::array<u64,3>& m1103) {
                              slog::join_probe<2,2>(eval_args_ansindex1023, std::array<u64,2>{v_c216, v_c20}, [&](const std::array<u64,2>& m1104) {
                                slog::join_probe<3,2>(lambdaindex1024, std::array<u64,3>{v_c10, v_c11, 0}, [&](const std::array<u64,3>& m1105) {
                                  u64 v_c218 = m1105[2];
                                  slog::join_probe<3,2>(closureindex1025, std::array<u64,3>{v_c218, v_c8, 0}, [&](const std::array<u64,3>& m1106) {
                                    u64 v_c219 = m1106[2];
                                    slog::join_probe<2,2>(eval_ansindex1026, std::array<u64,2>{v_c215, v_c219}, [&](const std::array<u64,2>& m1107) {
                                      ++_fires;
                                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c214, v_c3}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:52", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask1030* _cont = new ReadTask1030(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1030(db,b), false);
  // (crule (pre) (scan eval_ans __t5mTH630 __v0) (body (exists select_branch (1 0 2 3) 1 __v0) (join-old eval (0 1 2 3) 1 (0 1 2 3) __t5mTH630 e1 rho t) (join $sup70016x87x0x0x0 (1 4 5 0 2 3) 3 e1 rho t __d0 e2 e3) (join-old select_branch (2 3 1 0) 3 (2 3 1 0) e2 e3 __v0 __t4JBz631) (join-old select_branch_ans (0 1) 1 (0 1) __t4JBz631 __v1)) (head (mkstruct eval (1 2 3 0) __226z1519 __v1 rho t)) interp.slog:88 #f)
  class ReadTask1116 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** select_branchindex1108;  slog::Index** evalindex1109;  slog::Index** $sup70016x87x0x0x0index1110;  slog::Index** select_branchindex1111;  slog::Index** select_branch_ansindex1112;  slog::Index** evaldelta1113;  slog::Index** select_branchdelta1114;  slog::Index** select_branch_ansdelta1115;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord1117({1, 0, 2, 3});
      slog::Relation* readrel1118 = db->getRelation("select_branch");
      select_branchindex1108 = readrel1118->getIndex(ord1117, false);
      std::vector<u16> ord1119({0, 1, 2, 3});
      slog::Relation* readrel1120 = db->getRelation("eval");
      evalindex1109 = readrel1120->getIndex(ord1119, false);
      std::vector<u16> ord1121({0, 1, 2, 3});
      slog::Relation* readrel1122 = db->getRelation("eval");
      evaldelta1113 = readrel1122->getIndex(ord1121, true);
      std::vector<u16> ord1123({1, 4, 5, 0, 2, 3});
      slog::Relation* readrel1124 = db->getRelation("$sup70016x87x0x0x0");
      $sup70016x87x0x0x0index1110 = readrel1124->getIndex(ord1123, false);
      std::vector<u16> ord1125({2, 3, 1, 0});
      slog::Relation* readrel1126 = db->getRelation("select_branch");
      select_branchindex1111 = readrel1126->getIndex(ord1125, false);
      std::vector<u16> ord1127({2, 3, 1, 0});
      slog::Relation* readrel1128 = db->getRelation("select_branch");
      select_branchdelta1114 = readrel1128->getIndex(ord1127, true);
      std::vector<u16> ord1129({0, 1});
      slog::Relation* readrel1130 = db->getRelation("select_branch_ans");
      select_branch_ansindex1112 = readrel1130->getIndex(ord1129, false);
      std::vector<u16> ord1131({0, 1});
      slog::Relation* readrel1132 = db->getRelation("select_branch_ans");
      select_branch_ansdelta1115 = readrel1132->getIndex(ord1131, true);
  
    }
    ReadTask1116(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c220 = _t[0];
        u64 v_c36 = _t[1];
        if (!slog::exists_probe<4,1>(select_branchindex1108, std::array<u64,4>{v_c36, 0, 0, 0})) return;
        slog::join_probe_old<4,1>(evalindex1109, evaldelta1113, std::array<u64,4>{v_c220, 0, 0, 0}, [&](const std::array<u64,4>& m1133) {
          u64 v_c221 = m1133[1]; u64 v_c13 = m1133[2]; u64 v_c14 = m1133[3];
          slog::join_probe<6,3>($sup70016x87x0x0x0index1110, std::array<u64,6>{v_c221, v_c13, v_c14, 0, 0, 0}, [&](const std::array<u64,6>& m1134) {
            u64 v_c15 = m1134[3]; u64 v_c222 = m1134[4]; u64 v_c223 = m1134[5];
            slog::join_probe_old<4,3>(select_branchindex1111, select_branchdelta1114, std::array<u64,4>{v_c222, v_c223, v_c36, 0}, [&](const std::array<u64,4>& m1135) {
              u64 v_c224 = m1135[3];
              slog::join_probe_old<2,1>(select_branch_ansindex1112, select_branch_ansdelta1115, std::array<u64,2>{v_c224, 0}, [&](const std::array<u64,2>& m1136) {
                u64 v_c48 = m1136[1];
                ++_fires;
                slog::emit_struct<4>(head_rel[0], newbatch[0], std::array<u64,3>{v_c48, v_c13, v_c14}, std::array<u16,4>{1, 2, 3, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:88", "delta:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask1116* _cont = new ReadTask1116(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1116(db,b), false);
  // (crule (pre) (scan tick __t0CD9539 __t5a7h538 t) (body (exists $sup70016x51x0x0x0 (4 0 3 1 2) 1 t) (exists $sup70016x51x0x0x1 (3 9 10 0 1 2 4 5 6 7 8 11 12) 2 __t0CD9539 t) (exists eval (3 1 0 2) 1 t) (exists eval_args (3 2 0 1) 1 t) (exists tick_ans (0 1) 1 __t0CD9539) (join eval (3 1 0 2) 2 t __t5a7h538 __t2z6s532 rho) (exists $sup70016x51x0x0x1 (0 7 9 3 10 1 2 4 5 6 8 11 12) 4 __t2z6s532 rho t __t0CD9539) (exists eval (2 3 0 1) 2 rho t) (exists eval_args (3 2 0 1) 2 t rho) (join $sup70016x51x0x0x0 (4 0 3 1 2) 3 t __t2z6s532 rho ef es) (exists eval (1 2 3 0) 3 ef rho t) (exists eval_args (1 3 2 0) 3 es t rho) (exists app (0 1 2) 3 __t5a7h538 ef es) (join $sup70016x51x0x0x1 (0 3 5 6 7 9 10 1 2 4 8 11 12) 6 __t2z6s532 __t0CD9539 ef es rho t t2 __t5qy8533 __t2srV536 eb rhoc vs xs) (join eval (2 3 0 1) 4 rho t __t5qy8533 ef) (join eval_args (3 2 0 1) 4 t rho __t2srV536 es) (join app (0 1 2) 3 __t5a7h538 ef es) (exists eval_args_ans (0 1) 2 __t2srV536 vs) (exists tick_ans (0 1) 2 __t0CD9539 t2) (exists lambda (1 2 0) 2 xs eb) (exists closure (2 0 1) 1 rhoc) (exists eval_ans (0 1) 1 __t5qy8533) (exists eval (3 1 0 2) 2 t2 eb) (join-old extend_env (1 2 3 0) 3 (1 2 3 0) rhoc xs t2 __t5fzh540) (join eval_args_ans (0 1) 2 __t2srV536 vs) (join tick_ans (0 1) 2 __t0CD9539 t2) (exists extend_env_ans (0 1) 1 __t5fzh540) (join lambda (1 2 0) 2 xs eb __t6iPm534) (join closure (1 2 0) 2 __t6iPm534 rhoc __t9dfl535) (join eval_ans (0 1) 2 __t5qy8533 __t9dfl535) (join eval (3 1 0 2) 2 t2 eb __t7TaT537 __v0) (join extend_env_ans (0 1) 2 __t5fzh540 __v0) (join eval_ans (0 1) 1 __t7TaT537 v)) (head (emit eval_ans (0 1) __t2z6s532 v)) interp.slog:52 #f)
  class ReadTask1171 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup70016x51x0x0x0index1137;  slog::Index** $sup70016x51x0x0x1index1138;  slog::Index** evalindex1139;  slog::Index** eval_argsindex1140;  slog::Index** tick_ansindex1141;  slog::Index** evalindex1142;  slog::Index** $sup70016x51x0x0x1index1143;  slog::Index** evalindex1144;  slog::Index** eval_argsindex1145;  slog::Index** $sup70016x51x0x0x0index1146;  slog::Index** evalindex1147;  slog::Index** eval_argsindex1148;  slog::Index** appindex1149;  slog::Index** $sup70016x51x0x0x1index1150;  slog::Index** evalindex1151;  slog::Index** eval_argsindex1152;  slog::Index** appindex1153;  slog::Index** eval_args_ansindex1154;  slog::Index** tick_ansindex1155;  slog::Index** lambdaindex1156;  slog::Index** closureindex1157;  slog::Index** eval_ansindex1158;  slog::Index** evalindex1159;  slog::Index** extend_envindex1160;  slog::Index** eval_args_ansindex1161;  slog::Index** tick_ansindex1162;  slog::Index** extend_env_ansindex1163;  slog::Index** lambdaindex1164;  slog::Index** closureindex1165;  slog::Index** eval_ansindex1166;  slog::Index** evalindex1167;  slog::Index** extend_env_ansindex1168;  slog::Index** eval_ansindex1169;  slog::Index** extend_envdelta1170;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1172({0, 1});
      slog::Relation* readrel1173 = db->getRelation("eval_ans");
      head_index[0] = readrel1173->getIndex(ord1172, false);
      outer_rel = db->getRelation("tick");
      std::vector<u16> ord1174({4, 0, 3, 1, 2});
      slog::Relation* readrel1175 = db->getRelation("$sup70016x51x0x0x0");
      $sup70016x51x0x0x0index1137 = readrel1175->getIndex(ord1174, false);
      std::vector<u16> ord1176({3, 9, 10, 0, 1, 2, 4, 5, 6, 7, 8, 11, 12});
      slog::Relation* readrel1177 = db->getRelation("$sup70016x51x0x0x1");
      $sup70016x51x0x0x1index1138 = readrel1177->getIndex(ord1176, false);
      std::vector<u16> ord1178({3, 1, 0, 2});
      slog::Relation* readrel1179 = db->getRelation("eval");
      evalindex1139 = readrel1179->getIndex(ord1178, false);
      std::vector<u16> ord1180({3, 2, 0, 1});
      slog::Relation* readrel1181 = db->getRelation("eval_args");
      eval_argsindex1140 = readrel1181->getIndex(ord1180, false);
      std::vector<u16> ord1182({0, 1});
      slog::Relation* readrel1183 = db->getRelation("tick_ans");
      tick_ansindex1141 = readrel1183->getIndex(ord1182, false);
      std::vector<u16> ord1184({3, 1, 0, 2});
      slog::Relation* readrel1185 = db->getRelation("eval");
      evalindex1142 = readrel1185->getIndex(ord1184, false);
      std::vector<u16> ord1186({0, 7, 9, 3, 10, 1, 2, 4, 5, 6, 8, 11, 12});
      slog::Relation* readrel1187 = db->getRelation("$sup70016x51x0x0x1");
      $sup70016x51x0x0x1index1143 = readrel1187->getIndex(ord1186, false);
      std::vector<u16> ord1188({2, 3, 0, 1});
      slog::Relation* readrel1189 = db->getRelation("eval");
      evalindex1144 = readrel1189->getIndex(ord1188, false);
      std::vector<u16> ord1190({3, 2, 0, 1});
      slog::Relation* readrel1191 = db->getRelation("eval_args");
      eval_argsindex1145 = readrel1191->getIndex(ord1190, false);
      std::vector<u16> ord1192({4, 0, 3, 1, 2});
      slog::Relation* readrel1193 = db->getRelation("$sup70016x51x0x0x0");
      $sup70016x51x0x0x0index1146 = readrel1193->getIndex(ord1192, false);
      std::vector<u16> ord1194({1, 2, 3, 0});
      slog::Relation* readrel1195 = db->getRelation("eval");
      evalindex1147 = readrel1195->getIndex(ord1194, false);
      std::vector<u16> ord1196({1, 3, 2, 0});
      slog::Relation* readrel1197 = db->getRelation("eval_args");
      eval_argsindex1148 = readrel1197->getIndex(ord1196, false);
      std::vector<u16> ord1198({0, 1, 2});
      slog::Relation* readrel1199 = db->getRelation("app");
      appindex1149 = readrel1199->getIndex(ord1198, false);
      std::vector<u16> ord1200({0, 3, 5, 6, 7, 9, 10, 1, 2, 4, 8, 11, 12});
      slog::Relation* readrel1201 = db->getRelation("$sup70016x51x0x0x1");
      $sup70016x51x0x0x1index1150 = readrel1201->getIndex(ord1200, false);
      std::vector<u16> ord1202({2, 3, 0, 1});
      slog::Relation* readrel1203 = db->getRelation("eval");
      evalindex1151 = readrel1203->getIndex(ord1202, false);
      std::vector<u16> ord1204({3, 2, 0, 1});
      slog::Relation* readrel1205 = db->getRelation("eval_args");
      eval_argsindex1152 = readrel1205->getIndex(ord1204, false);
      std::vector<u16> ord1206({0, 1, 2});
      slog::Relation* readrel1207 = db->getRelation("app");
      appindex1153 = readrel1207->getIndex(ord1206, false);
      std::vector<u16> ord1208({0, 1});
      slog::Relation* readrel1209 = db->getRelation("eval_args_ans");
      eval_args_ansindex1154 = readrel1209->getIndex(ord1208, false);
      std::vector<u16> ord1210({0, 1});
      slog::Relation* readrel1211 = db->getRelation("tick_ans");
      tick_ansindex1155 = readrel1211->getIndex(ord1210, false);
      std::vector<u16> ord1212({1, 2, 0});
      slog::Relation* readrel1213 = db->getRelation("lambda");
      lambdaindex1156 = readrel1213->getIndex(ord1212, false);
      std::vector<u16> ord1214({2, 0, 1});
      slog::Relation* readrel1215 = db->getRelation("closure");
      closureindex1157 = readrel1215->getIndex(ord1214, false);
      std::vector<u16> ord1216({0, 1});
      slog::Relation* readrel1217 = db->getRelation("eval_ans");
      eval_ansindex1158 = readrel1217->getIndex(ord1216, false);
      std::vector<u16> ord1218({3, 1, 0, 2});
      slog::Relation* readrel1219 = db->getRelation("eval");
      evalindex1159 = readrel1219->getIndex(ord1218, false);
      std::vector<u16> ord1220({1, 2, 3, 0});
      slog::Relation* readrel1221 = db->getRelation("extend_env");
      extend_envindex1160 = readrel1221->getIndex(ord1220, false);
      std::vector<u16> ord1222({1, 2, 3, 0});
      slog::Relation* readrel1223 = db->getRelation("extend_env");
      extend_envdelta1170 = readrel1223->getIndex(ord1222, true);
      std::vector<u16> ord1224({0, 1});
      slog::Relation* readrel1225 = db->getRelation("eval_args_ans");
      eval_args_ansindex1161 = readrel1225->getIndex(ord1224, false);
      std::vector<u16> ord1226({0, 1});
      slog::Relation* readrel1227 = db->getRelation("tick_ans");
      tick_ansindex1162 = readrel1227->getIndex(ord1226, false);
      std::vector<u16> ord1228({0, 1});
      slog::Relation* readrel1229 = db->getRelation("extend_env_ans");
      extend_env_ansindex1163 = readrel1229->getIndex(ord1228, false);
      std::vector<u16> ord1230({1, 2, 0});
      slog::Relation* readrel1231 = db->getRelation("lambda");
      lambdaindex1164 = readrel1231->getIndex(ord1230, false);
      std::vector<u16> ord1232({1, 2, 0});
      slog::Relation* readrel1233 = db->getRelation("closure");
      closureindex1165 = readrel1233->getIndex(ord1232, false);
      std::vector<u16> ord1234({0, 1});
      slog::Relation* readrel1235 = db->getRelation("eval_ans");
      eval_ansindex1166 = readrel1235->getIndex(ord1234, false);
      std::vector<u16> ord1236({3, 1, 0, 2});
      slog::Relation* readrel1237 = db->getRelation("eval");
      evalindex1167 = readrel1237->getIndex(ord1236, false);
      std::vector<u16> ord1238({0, 1});
      slog::Relation* readrel1239 = db->getRelation("extend_env_ans");
      extend_env_ansindex1168 = readrel1239->getIndex(ord1238, false);
      std::vector<u16> ord1240({0, 1});
      slog::Relation* readrel1241 = db->getRelation("eval_ans");
      eval_ansindex1169 = readrel1241->getIndex(ord1240, false);
  
    }
    ReadTask1171(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c217 = _t[1];
        u64 v_c14 = _t[2];
        if (!slog::exists_probe<5,1>($sup70016x51x0x0x0index1137, std::array<u64,5>{v_c14, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<13,2>($sup70016x51x0x0x1index1138, std::array<u64,13>{v_c212, v_c14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(evalindex1139, std::array<u64,4>{v_c14, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(eval_argsindex1140, std::array<u64,4>{v_c14, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(tick_ansindex1141, std::array<u64,2>{v_c212, 0})) return;
        slog::join_probe<4,2>(evalindex1142, std::array<u64,4>{v_c14, v_c217, 0, 0}, [&](const std::array<u64,4>& m1242) {
          u64 v_c214 = m1242[2]; u64 v_c13 = m1242[3];
          if (!slog::exists_probe<13,4>($sup70016x51x0x0x1index1143, std::array<u64,13>{v_c214, v_c13, v_c14, v_c212, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<4,2>(evalindex1144, std::array<u64,4>{v_c13, v_c14, 0, 0})) return;
          if (!slog::exists_probe<4,2>(eval_argsindex1145, std::array<u64,4>{v_c14, v_c13, 0, 0})) return;
          slog::join_probe<5,3>($sup70016x51x0x0x0index1146, std::array<u64,5>{v_c14, v_c214, v_c13, 0, 0}, [&](const std::array<u64,5>& m1243) {
            u64 v_c12 = m1243[3]; u64 v_c16 = m1243[4];
            if (!slog::exists_probe<4,3>(evalindex1147, std::array<u64,4>{v_c12, v_c13, v_c14, 0})) return;
            if (!slog::exists_probe<4,3>(eval_argsindex1148, std::array<u64,4>{v_c16, v_c14, v_c13, 0})) return;
            if (!slog::exists_probe<3,3>(appindex1149, std::array<u64,3>{v_c217, v_c12, v_c16})) return;
            slog::join_probe<13,6>($sup70016x51x0x0x1index1150, std::array<u64,13>{v_c214, v_c212, v_c12, v_c16, v_c13, v_c14, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,13>& m1244) {
              u64 v_c21 = m1244[6]; u64 v_c215 = m1244[7]; u64 v_c216 = m1244[8]; u64 v_c11 = m1244[9]; u64 v_c8 = m1244[10]; u64 v_c20 = m1244[11]; u64 v_c10 = m1244[12];
              slog::join_probe<4,4>(evalindex1151, std::array<u64,4>{v_c13, v_c14, v_c215, v_c12}, [&](const std::array<u64,4>& m1245) {
                slog::join_probe<4,4>(eval_argsindex1152, std::array<u64,4>{v_c14, v_c13, v_c216, v_c16}, [&](const std::array<u64,4>& m1246) {
                  slog::join_probe<3,3>(appindex1153, std::array<u64,3>{v_c217, v_c12, v_c16}, [&](const std::array<u64,3>& m1247) {
                    if (!slog::exists_probe<2,2>(eval_args_ansindex1154, std::array<u64,2>{v_c216, v_c20})) return;
                    if (!slog::exists_probe<2,2>(tick_ansindex1155, std::array<u64,2>{v_c212, v_c21})) return;
                    if (!slog::exists_probe<3,2>(lambdaindex1156, std::array<u64,3>{v_c10, v_c11, 0})) return;
                    if (!slog::exists_probe<3,1>(closureindex1157, std::array<u64,3>{v_c8, 0, 0})) return;
                    if (!slog::exists_probe<2,1>(eval_ansindex1158, std::array<u64,2>{v_c215, 0})) return;
                    if (!slog::exists_probe<4,2>(evalindex1159, std::array<u64,4>{v_c21, v_c11, 0, 0})) return;
                    slog::join_probe_old<4,3>(extend_envindex1160, extend_envdelta1170, std::array<u64,4>{v_c8, v_c10, v_c21, 0}, [&](const std::array<u64,4>& m1248) {
                      u64 v_c213 = m1248[3];
                      slog::join_probe<2,2>(eval_args_ansindex1161, std::array<u64,2>{v_c216, v_c20}, [&](const std::array<u64,2>& m1249) {
                        slog::join_probe<2,2>(tick_ansindex1162, std::array<u64,2>{v_c212, v_c21}, [&](const std::array<u64,2>& m1250) {
                          if (!slog::exists_probe<2,1>(extend_env_ansindex1163, std::array<u64,2>{v_c213, 0})) return;
                          slog::join_probe<3,2>(lambdaindex1164, std::array<u64,3>{v_c10, v_c11, 0}, [&](const std::array<u64,3>& m1251) {
                            u64 v_c218 = m1251[2];
                            slog::join_probe<3,2>(closureindex1165, std::array<u64,3>{v_c218, v_c8, 0}, [&](const std::array<u64,3>& m1252) {
                              u64 v_c219 = m1252[2];
                              slog::join_probe<2,2>(eval_ansindex1166, std::array<u64,2>{v_c215, v_c219}, [&](const std::array<u64,2>& m1253) {
                                slog::join_probe<4,2>(evalindex1167, std::array<u64,4>{v_c21, v_c11, 0, 0}, [&](const std::array<u64,4>& m1254) {
                                  u64 v_c211 = m1254[2]; u64 v_c36 = m1254[3];
                                  slog::join_probe<2,2>(extend_env_ansindex1168, std::array<u64,2>{v_c213, v_c36}, [&](const std::array<u64,2>& m1255) {
                                    slog::join_probe<2,1>(eval_ansindex1169, std::array<u64,2>{v_c211, 0}, [&](const std::array<u64,2>& m1256) {
                                      u64 v_c3 = m1256[1];
                                      ++_fires;
                                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c214, v_c3}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:52", "delta:tick", _fires);
  
      if (!_done)
      {
        ReadTask1171* _cont = new ReadTask1171(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1171(db,b), false);
  // (crule (pre) (scan mbranch __t46nL391 q n u v) (body (exists mp_join (3 4 1 0 2) 2 q __t46nL391) (exists mp_union (2 0 1) 1 __t46nL391) (exists mp_msk (2 0 1) 1 n) (join $sup5638x110x0x0x0 (3 5 8 9 10 0 1 2 4 6 7) 5 n q __t46nL391 u v __t5Qtl389 l m p r __t6AX6390) (cmp lt m n) (join mbranch (1 2 3 4 0) 5 p m l r __t6AX6390) (exists mp_union (0 1 2) 3 __t5Qtl389 __t6AX6390 __t46nL391) (exists mp_msk (1 2 0) 2 p n) (join-old mp_join (1 2 3 4 0) 4 (1 2 3 4 0) p __t6AX6390 q __t46nL391 __t6UVn392) (join mp_union (0 1 2) 3 __t5Qtl389 __t6AX6390 __t46nL391) (exists mp_join_ans (0 1) 1 __t6UVn392) (join-old mp_msk (1 2 0) 2 (1 2 0) p n __t827P393) (join mp_msk_ans (0 1) 1 __t827P393 __v0) (neq q __v0) (join mp_join_ans (0 1) 1 __t6UVn392 res)) (head (emit mp_union_ans (0 1) __t5Qtl389 res)) map.slog:111 #f)
  class ReadTask1272 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_joinindex1257;  slog::Index** mp_unionindex1258;  slog::Index** mp_mskindex1259;  slog::Index** $sup5638x110x0x0x0index1260;  slog::Index** mbranchindex1261;  slog::Index** mp_unionindex1262;  slog::Index** mp_mskindex1263;  slog::Index** mp_joinindex1264;  slog::Index** mp_unionindex1265;  slog::Index** mp_join_ansindex1266;  slog::Index** mp_mskindex1267;  slog::Index** mp_msk_ansindex1268;  slog::Index** mp_join_ansindex1269;  slog::Index** mp_joindelta1270;  slog::Index** mp_mskdelta1271;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord1273({0, 1});
      slog::Relation* readrel1274 = db->getRelation("mp_union_ans");
      head_index[0] = readrel1274->getIndex(ord1273, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord1275({3, 4, 1, 0, 2});
      slog::Relation* readrel1276 = db->getRelation("mp_join");
      mp_joinindex1257 = readrel1276->getIndex(ord1275, false);
      std::vector<u16> ord1277({2, 0, 1});
      slog::Relation* readrel1278 = db->getRelation("mp_union");
      mp_unionindex1258 = readrel1278->getIndex(ord1277, false);
      std::vector<u16> ord1279({2, 0, 1});
      slog::Relation* readrel1280 = db->getRelation("mp_msk");
      mp_mskindex1259 = readrel1280->getIndex(ord1279, false);
      std::vector<u16> ord1281({3, 5, 8, 9, 10, 0, 1, 2, 4, 6, 7});
      slog::Relation* readrel1282 = db->getRelation("$sup5638x110x0x0x0");
      $sup5638x110x0x0x0index1260 = readrel1282->getIndex(ord1281, false);
      std::vector<u16> ord1283({1, 2, 3, 4, 0});
      slog::Relation* readrel1284 = db->getRelation("mbranch");
      mbranchindex1261 = readrel1284->getIndex(ord1283, false);
      std::vector<u16> ord1285({0, 1, 2});
      slog::Relation* readrel1286 = db->getRelation("mp_union");
      mp_unionindex1262 = readrel1286->getIndex(ord1285, false);
      std::vector<u16> ord1287({1, 2, 0});
      slog::Relation* readrel1288 = db->getRelation("mp_msk");
      mp_mskindex1263 = readrel1288->getIndex(ord1287, false);
      std::vector<u16> ord1289({1, 2, 3, 4, 0});
      slog::Relation* readrel1290 = db->getRelation("mp_join");
      mp_joinindex1264 = readrel1290->getIndex(ord1289, false);
      std::vector<u16> ord1291({1, 2, 3, 4, 0});
      slog::Relation* readrel1292 = db->getRelation("mp_join");
      mp_joindelta1270 = readrel1292->getIndex(ord1291, true);
      std::vector<u16> ord1293({0, 1, 2});
      slog::Relation* readrel1294 = db->getRelation("mp_union");
      mp_unionindex1265 = readrel1294->getIndex(ord1293, false);
      std::vector<u16> ord1295({0, 1});
      slog::Relation* readrel1296 = db->getRelation("mp_join_ans");
      mp_join_ansindex1266 = readrel1296->getIndex(ord1295, false);
      std::vector<u16> ord1297({1, 2, 0});
      slog::Relation* readrel1298 = db->getRelation("mp_msk");
      mp_mskindex1267 = readrel1298->getIndex(ord1297, false);
      std::vector<u16> ord1299({1, 2, 0});
      slog::Relation* readrel1300 = db->getRelation("mp_msk");
      mp_mskdelta1271 = readrel1300->getIndex(ord1299, true);
      std::vector<u16> ord1301({0, 1});
      slog::Relation* readrel1302 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1268 = readrel1302->getIndex(ord1301, false);
      std::vector<u16> ord1303({0, 1});
      slog::Relation* readrel1304 = db->getRelation("mp_join_ans");
      mp_join_ansindex1269 = readrel1304->getIndex(ord1303, false);
  
    }
    ReadTask1272(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c28 = _t[1];
        u64 v_c26 = _t[2];
        u64 v_c30 = _t[3];
        u64 v_c3 = _t[4];
        if (!slog::exists_probe<5,2>(mp_joinindex1257, std::array<u64,5>{v_c28, v_c78, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex1258, std::array<u64,3>{v_c78, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex1259, std::array<u64,3>{v_c26, 0, 0})) return;
        slog::join_probe<11,5>($sup5638x110x0x0x0index1260, std::array<u64,11>{v_c26, v_c28, v_c78, v_c30, v_c3, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m1305) {
          u64 v_c79 = m1305[5]; u64 v_c24 = m1305[6]; u64 v_c25 = m1305[7]; u64 v_c27 = m1305[8]; u64 v_c29 = m1305[9]; u64 v_c77 = m1305[10];
          u64 v_c225 = _prim_lt(db, v_c25, v_c26);
          if (v_c225 == slog_error) { slog::emit_pending_error(db, "map.slog:111"); return; }
          if (!v_c225) return;
          slog::join_probe<5,5>(mbranchindex1261, std::array<u64,5>{v_c27, v_c25, v_c24, v_c29, v_c77}, [&](const std::array<u64,5>& m1307) {
            if (!slog::exists_probe<3,3>(mp_unionindex1262, std::array<u64,3>{v_c79, v_c77, v_c78})) return;
            if (!slog::exists_probe<3,2>(mp_mskindex1263, std::array<u64,3>{v_c27, v_c26, 0})) return;
            slog::join_probe_old<5,4>(mp_joinindex1264, mp_joindelta1270, std::array<u64,5>{v_c27, v_c77, v_c28, v_c78, 0}, [&](const std::array<u64,5>& m1308) {
              u64 v_c76 = m1308[4];
              slog::join_probe<3,3>(mp_unionindex1265, std::array<u64,3>{v_c79, v_c77, v_c78}, [&](const std::array<u64,3>& m1309) {
                if (!slog::exists_probe<2,1>(mp_join_ansindex1266, std::array<u64,2>{v_c76, 0})) return;
                slog::join_probe_old<3,2>(mp_mskindex1267, mp_mskdelta1271, std::array<u64,3>{v_c27, v_c26, 0}, [&](const std::array<u64,3>& m1310) {
                  u64 v_c81 = m1310[2];
                  slog::join_probe<2,1>(mp_msk_ansindex1268, std::array<u64,2>{v_c81, 0}, [&](const std::array<u64,2>& m1311) {
                    u64 v_c36 = m1311[1];
                    if (v_c28 == v_c36) return;
                    slog::join_probe<2,1>(mp_join_ansindex1269, std::array<u64,2>{v_c76, 0}, [&](const std::array<u64,2>& m1312) {
                      u64 v_c82 = m1312[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c79, v_c82}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:111", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask1272* _cont = new ReadTask1272(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1272(db,b), false);
  // (crule (pre (let __tconst85Gw1131 constb9e118781cea1f9fa01462e0)) (scan temp2zCq2052 __t44yZ306) (body (join _enum (1 0) 1 __tconst85Gw1131 __t4QRG303) (join boolval (1 0) 1 __t4QRG303 __t6gLd304)) (head (emit delta_ans (0 1) __t44yZ306 __t6gLd304)) interp.slog:124 #f)
  class ReadTask1315 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex1313;  slog::Index** boolvalindex1314;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("delta_ans");
      std::vector<u16> ord1316({0, 1});
      slog::Relation* readrel1317 = db->getRelation("delta_ans");
      head_index[0] = readrel1317->getIndex(ord1316, false);
      outer_rel = db->getRelation("temp2zCq2052");
      std::vector<u16> ord1318({1, 0});
      slog::Relation* readrel1319 = db->getRelation("_enum");
      _enumindex1313 = readrel1319->getIndex(ord1318, false);
      std::vector<u16> ord1320({1, 0});
      slog::Relation* readrel1321 = db->getRelation("boolval");
      boolvalindex1314 = readrel1321->getIndex(ord1320, false);
  
    }
    ReadTask1315(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c226 = v_constb9e118781cea1f9fa01462e0;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c227 = _t[0];
        slog::join_probe<2,1>(_enumindex1313, std::array<u64,2>{v_c226, 0}, [&](const std::array<u64,2>& m1322) {
          u64 v_c228 = m1322[1];
          slog::join_probe<2,1>(boolvalindex1314, std::array<u64,2>{v_c228, 0}, [&](const std::array<u64,2>& m1323) {
            u64 v_c229 = m1323[1];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c227, v_c229}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:124", "delta:temp2zCq2052", _fires);
  
      if (!_done)
      {
        ReadTask1315* _cont = new ReadTask1315(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1315(db,b), false);
  // (crule (pre) (scan mbranch __t9kHM367 p m l r) (body (join mp_union (1 2 0) 1 __t9kHM367 __t6hR1368 __t2qeD366) (join-old mbranch (0 1 2 3 4) 1 (0 1 2 3 4) __t6hR1368 q n u v) (cmp lt n m)) (head (emit $sup5638x101x0x0x0 (2 5 0 1 3 4 6 7 8 9 10) m q __t2qeD366 l n p r __t9kHM367 __t6hR1368 u v)) map.slog:102 #f)
  class ReadTask1327 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex1324;  slog::Index** mbranchindex1325;  slog::Index** mbranchdelta1326;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x101x0x0x0");
      std::vector<u16> ord1328({2, 5, 0, 1, 3, 4, 6, 7, 8, 9, 10});
      slog::Relation* readrel1329 = db->getRelation("$sup5638x101x0x0x0");
      head_index[0] = readrel1329->getIndex(ord1328, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord1330({1, 2, 0});
      slog::Relation* readrel1331 = db->getRelation("mp_union");
      mp_unionindex1324 = readrel1331->getIndex(ord1330, false);
      std::vector<u16> ord1332({0, 1, 2, 3, 4});
      slog::Relation* readrel1333 = db->getRelation("mbranch");
      mbranchindex1325 = readrel1333->getIndex(ord1332, false);
      std::vector<u16> ord1334({0, 1, 2, 3, 4});
      slog::Relation* readrel1335 = db->getRelation("mbranch");
      mbranchdelta1326 = readrel1335->getIndex(ord1334, true);
  
    }
    ReadTask1327(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c27 = _t[1];
        u64 v_c25 = _t[2];
        u64 v_c24 = _t[3];
        u64 v_c29 = _t[4];
        slog::join_probe<3,1>(mp_unionindex1324, std::array<u64,3>{v_c230, 0, 0}, [&](const std::array<u64,3>& m1336) {
          u64 v_c231 = m1336[1]; u64 v_c232 = m1336[2];
          slog::join_probe_old<5,1>(mbranchindex1325, mbranchdelta1326, std::array<u64,5>{v_c231, 0, 0, 0, 0}, [&](const std::array<u64,5>& m1337) {
            u64 v_c28 = m1337[1]; u64 v_c26 = m1337[2]; u64 v_c30 = m1337[3]; u64 v_c3 = m1337[4];
            u64 v_c233 = _prim_lt(db, v_c26, v_c25);
            if (v_c233 == slog_error) { slog::emit_pending_error(db, "map.slog:102"); return; }
            if (!v_c233) return;
            ++_fires;
            slog::emit<11>(head_rel[0], head_index[0], newbatch[0], std::array<u64,11>{v_c25, v_c28, v_c232, v_c24, v_c26, v_c27, v_c29, v_c230, v_c231, v_c30, v_c3}, std::array<u16,11>{2, 5, 0, 1, 3, 4, 6, 7, 8, 9, 10});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:102", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask1327* _cont = new ReadTask1327(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1327(db,b), false);
}

