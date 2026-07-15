
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const0122baa3ac55f1b433944eb1;
extern u64 v_const06abaa100ecef791ce028c56;
extern u64 v_const0933fb667296882d8c45abca;
extern u64 v_const1064263932db82f2cf6d4ac2;
extern u64 v_const38c0e144c051f35df0684885;
extern u64 v_const3b05f339a47cf251e643e4dd;
extern u64 v_const3d914f9348c9cc0ff8a79716;
extern u64 v_const4e07408562bedb8b60ce05c1;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const73475cb40a568e8da8a045ce;
extern u64 v_const8c6798fa821ed573f6b89759;
extern u64 v_const90fb9068eda6f2d68bb61c33;
extern u64 v_consta22c7bfa7abc2d7d387fd7df;
extern u64 v_constb177cd86b4c517da8099d6e4;
extern u64 v_constb9a8f892254647859feb7453;
extern u64 v_constc742e02805b99df617265a41;
extern u64 v_constc8dd3fe14ad7db61de7362fc;
extern u64 v_constcd2a69ce5ca278db1d6da969;
extern u64 v_constd01925b37634a1a9d24159d8;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_constd59eced1ded07f84c145592f;
extern u64 v_constdd7bbf31ce5f578b9805e840;
extern u64 v_conste90c92f3e6c3b47a7bc93e42;


void slog_rules_c7de3d01b7ffc9384(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre (let __trid7Nk11323 const8c6798fa821ed573f6b89759) (let __trel6M6l1324 conste90c92f3e6c3b47a7bc93e42) (let __tcol75u91325 const5feceb66ffc86f38d952786c) (let __trel9bV61326 conste90c92f3e6c3b47a7bc93e42) (let __tcol2iTZ1327 const6b86b273ff34fce19d6b804e) (let __trel2B9d1328 conste90c92f3e6c3b47a7bc93e42) (let __tcol6AUg1329 constd4735e3a265e16eee03f5971)) (scan $sup70016x51x0x0x0 __d0 ef es rho t) (body) (head (tycheck es (accept seq) __trid7Nk11323 __trel6M6l1324 __tcol75u91325 (1 2 3 4 0)) (tycheck rho (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid7Nk11323 __trel9bV61326 __tcol2iTZ1327 (1 2 3 4 0)) (tycheck t (accept seq) __trid7Nk11323 __trel2B9d1328 __tcol6AUg1329 (1 2 3 4 0)) (mkstruct eval_args (1 3 2 0) __0Cbw1322 es t rho)) interp.slog:52 #f)
  class ReadTask3 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[4];
    slog::Index** head_index[4];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid1;  u32 sid0;  u32 sid2;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("malformed_deduction");
      head_rel[3] = db->getRelation("eval_args");
      outer_rel = db->getRelation("$sup70016x51x0x0x0");
      sid1 = db->getRelation("_enum")->getStructId();
      sid0 = db->getRelation("mbranch")->getStructId();
      sid2 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask3(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const8c6798fa821ed573f6b89759;
      u64 v_c1 = v_conste90c92f3e6c3b47a7bc93e42;
      u64 v_c2 = v_const5feceb66ffc86f38d952786c;
      u64 v_c3 = v_conste90c92f3e6c3b47a7bc93e42;
      u64 v_c4 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c5 = v_conste90c92f3e6c3b47a7bc93e42;
      u64 v_c6 = v_constd4735e3a265e16eee03f5971;
  
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
        u64 v_c7 = _t[0];
        u64 v_c8 = _t[1];
        u64 v_c9 = _t[2];
        u64 v_c10 = _t[3];
        u64 v_c11 = _t[4];
        ++_fires;
        if (!(is_seq(v_c9)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c0, v_c1, v_c2, v_c9}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c10) && (decode_struct_id(v_c10) == sid0 || decode_struct_id(v_c10) == sid1 || decode_struct_id(v_c10) == sid2))))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c0, v_c3, v_c4, v_c10}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_seq(v_c11)))
        {
          slog::emit_struct<5>(head_rel[2], newbatch[2], std::array<u64,4>{v_c0, v_c5, v_c6, v_c11}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<4>(head_rel[3], newbatch[3], std::array<u64,3>{v_c9, v_c11, v_c10}, std::array<u16,4>{1, 3, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
  
      if (_fires) db->bumpFires("interp.slog:52", "delta:$sup70016x51x0x0x0", _fires);
  
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
  // (crule (pre) (scan eval __t7DhJ358 __t0Sks357 rho t) (body (exists $sup70016x95x0x0x1 (0 4 6 2 3 7 1 5) 3 __t7DhJ358 rho t) (exists mp_put (1 3 0 2) 2 rho t) (exists eval (3 1 0 2) 1 t) (join $sup70016x95x0x0x0 (0 3 4 1 2 5) 3 __t7DhJ358 rho t eb er x) (exists letrec (0 1 2 3) 4 __t0Sks357 x er eb) (exists mp_put (1 2 3 0) 3 rho x t) (exists eval (3 1 0 2) 2 t er) (exists eval (3 1 0 2) 2 t eb) (join $sup70016x95x0x0x1 (0 4 6 2 3 7 1 5) 6 __t7DhJ358 rho t eb er x __t0Rig361 rho2) (join letrec (0 1 2 3) 4 __t0Sks357 x er eb) (join-old mp_put (0 2 1 3) 4 (0 2 1 3) __t0Rig361 x rho t) (exists eval (1 2 3 0) 3 eb rho2 t) (exists mp_put_ans (0 1) 2 __t0Rig361 rho2) (join-old eval (1 2 3 0) 3 (1 2 3 0) er rho2 t __t6HuT359) (exists eval_ans (0 1) 1 __t6HuT359) (join-old eval (1 2 3 0) 3 (1 2 3 0) eb rho2 t __t63JF360) (join mp_put_ans (0 1) 2 __t0Rig361 rho2) (exists eval_ans (0 1) 1 __t63JF360) (join eval_ans (0 1) 1 __t6HuT359 vr) (join eval_ans (0 1) 1 __t63JF360 v)) (head (emit eval_ans (0 1) __t7DhJ358 v)) interp.slog:96 #f)
  class ReadTask27 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup70016x95x0x0x1index4;  slog::Index** mp_putindex5;  slog::Index** evalindex6;  slog::Index** $sup70016x95x0x0x0index7;  slog::Index** letrecindex8;  slog::Index** mp_putindex9;  slog::Index** evalindex10;  slog::Index** evalindex11;  slog::Index** $sup70016x95x0x0x1index12;  slog::Index** letrecindex13;  slog::Index** mp_putindex14;  slog::Index** evalindex15;  slog::Index** mp_put_ansindex16;  slog::Index** evalindex17;  slog::Index** eval_ansindex18;  slog::Index** evalindex19;  slog::Index** mp_put_ansindex20;  slog::Index** eval_ansindex21;  slog::Index** eval_ansindex22;  slog::Index** eval_ansindex23;  slog::Index** mp_putdelta24;  slog::Index** evaldelta25;  slog::Index** evaldelta26;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord28({0, 1});
      slog::Relation* readrel29 = db->getRelation("eval_ans");
      head_index[0] = readrel29->getIndex(ord28, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord30({0, 4, 6, 2, 3, 7, 1, 5});
      slog::Relation* readrel31 = db->getRelation("$sup70016x95x0x0x1");
      $sup70016x95x0x0x1index4 = readrel31->getIndex(ord30, false);
      std::vector<u16> ord32({1, 3, 0, 2});
      slog::Relation* readrel33 = db->getRelation("mp_put");
      mp_putindex5 = readrel33->getIndex(ord32, false);
      std::vector<u16> ord34({3, 1, 0, 2});
      slog::Relation* readrel35 = db->getRelation("eval");
      evalindex6 = readrel35->getIndex(ord34, false);
      std::vector<u16> ord36({0, 3, 4, 1, 2, 5});
      slog::Relation* readrel37 = db->getRelation("$sup70016x95x0x0x0");
      $sup70016x95x0x0x0index7 = readrel37->getIndex(ord36, false);
      std::vector<u16> ord38({0, 1, 2, 3});
      slog::Relation* readrel39 = db->getRelation("letrec");
      letrecindex8 = readrel39->getIndex(ord38, false);
      std::vector<u16> ord40({1, 2, 3, 0});
      slog::Relation* readrel41 = db->getRelation("mp_put");
      mp_putindex9 = readrel41->getIndex(ord40, false);
      std::vector<u16> ord42({3, 1, 0, 2});
      slog::Relation* readrel43 = db->getRelation("eval");
      evalindex10 = readrel43->getIndex(ord42, false);
      std::vector<u16> ord44({3, 1, 0, 2});
      slog::Relation* readrel45 = db->getRelation("eval");
      evalindex11 = readrel45->getIndex(ord44, false);
      std::vector<u16> ord46({0, 4, 6, 2, 3, 7, 1, 5});
      slog::Relation* readrel47 = db->getRelation("$sup70016x95x0x0x1");
      $sup70016x95x0x0x1index12 = readrel47->getIndex(ord46, false);
      std::vector<u16> ord48({0, 1, 2, 3});
      slog::Relation* readrel49 = db->getRelation("letrec");
      letrecindex13 = readrel49->getIndex(ord48, false);
      std::vector<u16> ord50({0, 2, 1, 3});
      slog::Relation* readrel51 = db->getRelation("mp_put");
      mp_putindex14 = readrel51->getIndex(ord50, false);
      std::vector<u16> ord52({0, 2, 1, 3});
      slog::Relation* readrel53 = db->getRelation("mp_put");
      mp_putdelta24 = readrel53->getIndex(ord52, true);
      std::vector<u16> ord54({1, 2, 3, 0});
      slog::Relation* readrel55 = db->getRelation("eval");
      evalindex15 = readrel55->getIndex(ord54, false);
      std::vector<u16> ord56({0, 1});
      slog::Relation* readrel57 = db->getRelation("mp_put_ans");
      mp_put_ansindex16 = readrel57->getIndex(ord56, false);
      std::vector<u16> ord58({1, 2, 3, 0});
      slog::Relation* readrel59 = db->getRelation("eval");
      evalindex17 = readrel59->getIndex(ord58, false);
      std::vector<u16> ord60({1, 2, 3, 0});
      slog::Relation* readrel61 = db->getRelation("eval");
      evaldelta25 = readrel61->getIndex(ord60, true);
      std::vector<u16> ord62({0, 1});
      slog::Relation* readrel63 = db->getRelation("eval_ans");
      eval_ansindex18 = readrel63->getIndex(ord62, false);
      std::vector<u16> ord64({1, 2, 3, 0});
      slog::Relation* readrel65 = db->getRelation("eval");
      evalindex19 = readrel65->getIndex(ord64, false);
      std::vector<u16> ord66({1, 2, 3, 0});
      slog::Relation* readrel67 = db->getRelation("eval");
      evaldelta26 = readrel67->getIndex(ord66, true);
      std::vector<u16> ord68({0, 1});
      slog::Relation* readrel69 = db->getRelation("mp_put_ans");
      mp_put_ansindex20 = readrel69->getIndex(ord68, false);
      std::vector<u16> ord70({0, 1});
      slog::Relation* readrel71 = db->getRelation("eval_ans");
      eval_ansindex21 = readrel71->getIndex(ord70, false);
      std::vector<u16> ord72({0, 1});
      slog::Relation* readrel73 = db->getRelation("eval_ans");
      eval_ansindex22 = readrel73->getIndex(ord72, false);
      std::vector<u16> ord74({0, 1});
      slog::Relation* readrel75 = db->getRelation("eval_ans");
      eval_ansindex23 = readrel75->getIndex(ord74, false);
  
    }
    ReadTask27(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c12 = _t[0];
        u64 v_c13 = _t[1];
        u64 v_c10 = _t[2];
        u64 v_c11 = _t[3];
        if (!slog::exists_probe<8,3>($sup70016x95x0x0x1index4, std::array<u64,8>{v_c12, v_c10, v_c11, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<4,2>(mp_putindex5, std::array<u64,4>{v_c10, v_c11, 0, 0})) return;
        if (!slog::exists_probe<4,1>(evalindex6, std::array<u64,4>{v_c11, 0, 0, 0})) return;
        slog::join_probe<6,3>($sup70016x95x0x0x0index7, std::array<u64,6>{v_c12, v_c10, v_c11, 0, 0, 0}, [&](const std::array<u64,6>& m76) {
          u64 v_c14 = m76[3]; u64 v_c15 = m76[4]; u64 v_c16 = m76[5];
          if (!slog::exists_probe<4,4>(letrecindex8, std::array<u64,4>{v_c13, v_c16, v_c15, v_c14})) return;
          if (!slog::exists_probe<4,3>(mp_putindex9, std::array<u64,4>{v_c10, v_c16, v_c11, 0})) return;
          if (!slog::exists_probe<4,2>(evalindex10, std::array<u64,4>{v_c11, v_c15, 0, 0})) return;
          if (!slog::exists_probe<4,2>(evalindex11, std::array<u64,4>{v_c11, v_c14, 0, 0})) return;
          slog::join_probe<8,6>($sup70016x95x0x0x1index12, std::array<u64,8>{v_c12, v_c10, v_c11, v_c14, v_c15, v_c16, 0, 0}, [&](const std::array<u64,8>& m77) {
            u64 v_c17 = m77[6]; u64 v_c18 = m77[7];
            slog::join_probe<4,4>(letrecindex13, std::array<u64,4>{v_c13, v_c16, v_c15, v_c14}, [&](const std::array<u64,4>& m78) {
              slog::join_probe_old<4,4>(mp_putindex14, mp_putdelta24, std::array<u64,4>{v_c17, v_c16, v_c10, v_c11}, [&](const std::array<u64,4>& m79) {
                if (!slog::exists_probe<4,3>(evalindex15, std::array<u64,4>{v_c14, v_c18, v_c11, 0})) return;
                if (!slog::exists_probe<2,2>(mp_put_ansindex16, std::array<u64,2>{v_c17, v_c18})) return;
                slog::join_probe_old<4,3>(evalindex17, evaldelta25, std::array<u64,4>{v_c15, v_c18, v_c11, 0}, [&](const std::array<u64,4>& m80) {
                  u64 v_c19 = m80[3];
                  if (!slog::exists_probe<2,1>(eval_ansindex18, std::array<u64,2>{v_c19, 0})) return;
                  slog::join_probe_old<4,3>(evalindex19, evaldelta26, std::array<u64,4>{v_c14, v_c18, v_c11, 0}, [&](const std::array<u64,4>& m81) {
                    u64 v_c20 = m81[3];
                    slog::join_probe<2,2>(mp_put_ansindex20, std::array<u64,2>{v_c17, v_c18}, [&](const std::array<u64,2>& m82) {
                      if (!slog::exists_probe<2,1>(eval_ansindex21, std::array<u64,2>{v_c20, 0})) return;
                      slog::join_probe<2,1>(eval_ansindex22, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m83) {
                        u64 v_c21 = m83[1];
                        slog::join_probe<2,1>(eval_ansindex23, std::array<u64,2>{v_c20, 0}, [&](const std::array<u64,2>& m84) {
                          u64 v_c22 = m84[1];
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c12, v_c22}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:96", "delta:eval", _fires);
  
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
  // (crule (pre) (scan mp_join_ans __t5fYY629 r) (body (join-old mp_join (0 1 2 3 4) 1 (0 1 2 3 4) __t5fYY629 k __t6AYq628 j __t8ls4627) (neq j k) (exists mleaf (0 1 2) 2 __t6AYq628 k) (exists mp_put (1 2 3 0) 2 __t8ls4627 k) (join-old mleaf (0 1 2) 2 (0 1 2) __t8ls4627 j w) (join-old mleaf (0 1 2) 2 (0 1 2) __t6AYq628 k v) (join-old mp_put (1 2 3 0) 3 (1 2 3 0) __t8ls4627 k v __t4a7n626)) (head (emit mp_put_ans (0 1) __t4a7n626 r)) map.slog:39 #f)
  class ReadTask95 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_joinindex85;  slog::Index** mleafindex86;  slog::Index** mp_putindex87;  slog::Index** mleafindex88;  slog::Index** mleafindex89;  slog::Index** mp_putindex90;  slog::Index** mp_joindelta91;  slog::Index** mleafdelta92;  slog::Index** mleafdelta93;  slog::Index** mp_putdelta94;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_ans");
      std::vector<u16> ord96({0, 1});
      slog::Relation* readrel97 = db->getRelation("mp_put_ans");
      head_index[0] = readrel97->getIndex(ord96, false);
      outer_rel = db->getRelation("mp_join_ans");
      std::vector<u16> ord98({0, 1, 2, 3, 4});
      slog::Relation* readrel99 = db->getRelation("mp_join");
      mp_joinindex85 = readrel99->getIndex(ord98, false);
      std::vector<u16> ord100({0, 1, 2, 3, 4});
      slog::Relation* readrel101 = db->getRelation("mp_join");
      mp_joindelta91 = readrel101->getIndex(ord100, true);
      std::vector<u16> ord102({0, 1, 2});
      slog::Relation* readrel103 = db->getRelation("mleaf");
      mleafindex86 = readrel103->getIndex(ord102, false);
      std::vector<u16> ord104({1, 2, 3, 0});
      slog::Relation* readrel105 = db->getRelation("mp_put");
      mp_putindex87 = readrel105->getIndex(ord104, false);
      std::vector<u16> ord106({0, 1, 2});
      slog::Relation* readrel107 = db->getRelation("mleaf");
      mleafindex88 = readrel107->getIndex(ord106, false);
      std::vector<u16> ord108({0, 1, 2});
      slog::Relation* readrel109 = db->getRelation("mleaf");
      mleafdelta92 = readrel109->getIndex(ord108, true);
      std::vector<u16> ord110({0, 1, 2});
      slog::Relation* readrel111 = db->getRelation("mleaf");
      mleafindex89 = readrel111->getIndex(ord110, false);
      std::vector<u16> ord112({0, 1, 2});
      slog::Relation* readrel113 = db->getRelation("mleaf");
      mleafdelta93 = readrel113->getIndex(ord112, true);
      std::vector<u16> ord114({1, 2, 3, 0});
      slog::Relation* readrel115 = db->getRelation("mp_put");
      mp_putindex90 = readrel115->getIndex(ord114, false);
      std::vector<u16> ord116({1, 2, 3, 0});
      slog::Relation* readrel117 = db->getRelation("mp_put");
      mp_putdelta94 = readrel117->getIndex(ord116, true);
  
    }
    ReadTask95(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c23 = _t[0];
        u64 v_c24 = _t[1];
        slog::join_probe_old<5,1>(mp_joinindex85, mp_joindelta91, std::array<u64,5>{v_c23, 0, 0, 0, 0}, [&](const std::array<u64,5>& m118) {
          u64 v_c25 = m118[1]; u64 v_c26 = m118[2]; u64 v_c27 = m118[3]; u64 v_c28 = m118[4];
          if (v_c27 == v_c25) return;
          if (!slog::exists_probe<3,2>(mleafindex86, std::array<u64,3>{v_c26, v_c25, 0})) return;
          if (!slog::exists_probe<4,2>(mp_putindex87, std::array<u64,4>{v_c28, v_c25, 0, 0})) return;
          slog::join_probe_old<3,2>(mleafindex88, mleafdelta92, std::array<u64,3>{v_c28, v_c27, 0}, [&](const std::array<u64,3>& m119) {
            u64 v_c29 = m119[2];
            slog::join_probe_old<3,2>(mleafindex89, mleafdelta93, std::array<u64,3>{v_c26, v_c25, 0}, [&](const std::array<u64,3>& m120) {
              u64 v_c22 = m120[2];
              slog::join_probe_old<4,3>(mp_putindex90, mp_putdelta94, std::array<u64,4>{v_c28, v_c25, v_c22, 0}, [&](const std::array<u64,4>& m121) {
                u64 v_c30 = m121[3];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c30, v_c24}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:39", "delta:mp_join_ans", _fires);
  
      if (!_done)
      {
        ReadTask95* _cont = new ReadTask95(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask95(db,b), false);
  // (crule (pre (let __tconst2Vg0546 const06abaa100ecef791ce028c56) (let _00024sqc2T6l964 constd4735e3a265e16eee03f5971) (let _00024sqc2Wzv965 const5feceb66ffc86f38d952786c) (let _00024sqc80On966 const6b86b273ff34fce19d6b804e) (let _00024sqo5uVM967 const5feceb66ffc86f38d952786c) (let _00024sqo11r2968 const6b86b273ff34fce19d6b804e) (let _00024sqo89F1969 const6b86b273ff34fce19d6b804e) (let _00024sqo57Hb970 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo5uVM967 __t40a6549 _00024seq2) (body (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo11r2968 __t40a6549 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo89F1969 __t40a6549 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo57Hb970 __t40a6549 _00024seq2) (join delta (1 2 0) 2 __tconst2Vg0546 _00024seq2 __t6qCW547) (join closure (0 1 2) 1 __t40a6549 lm rc) (join any_bool (0) 0 b) (letp _00024sql3t08962 (aslst _00024seq2)) (let chk9qqo1844 (llen _00024sql3t08962)) (eq _00024sqc2T6l964 chk9qqo1844) (letp chk3dUJ1845 (lref _00024sql3t08962 _00024sqc2Wzv965)) (eq __t40a6549 chk3dUJ1845) (letp chk086w1846 (lref _00024sql3t08962 _00024sqc80On966)) (eq __t40a6549 chk086w1846)) (head (emit-temp temp7z5q1838 __t6qCW547 b) (mkstruct boolval (1 0) __t1Eis545 b)) interp.slog:126 #f)
  class ReadTask131 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex122;  slog::Index** $seq_atrindex123;  slog::Index** $seq_atrindex124;  slog::Index** deltaindex125;  slog::Index** closureindex126;  slog::Index** any_boolindex127;  slog::Index** $seq_atdelta128;  slog::Index** $seq_atrdelta129;  slog::Index** $seq_atrdelta130;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7z5q1838");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord132({1, 0, 2});
      slog::Relation* readrel133 = db->getRelation("$seq_at");
      driver_index = readrel133->getIndex(ord132, true);
      std::vector<u16> ord134({1, 0, 2});
      slog::Relation* readrel135 = db->getRelation("$seq_at");
      $seq_atindex122 = readrel135->getIndex(ord134, false);
      std::vector<u16> ord136({1, 0, 2});
      slog::Relation* readrel137 = db->getRelation("$seq_at");
      $seq_atdelta128 = readrel137->getIndex(ord136, true);
      std::vector<u16> ord138({1, 0, 2});
      slog::Relation* readrel139 = db->getRelation("$seq_atr");
      $seq_atrindex123 = readrel139->getIndex(ord138, false);
      std::vector<u16> ord140({1, 0, 2});
      slog::Relation* readrel141 = db->getRelation("$seq_atr");
      $seq_atrdelta129 = readrel141->getIndex(ord140, true);
      std::vector<u16> ord142({1, 0, 2});
      slog::Relation* readrel143 = db->getRelation("$seq_atr");
      $seq_atrindex124 = readrel143->getIndex(ord142, false);
      std::vector<u16> ord144({1, 0, 2});
      slog::Relation* readrel145 = db->getRelation("$seq_atr");
      $seq_atrdelta130 = readrel145->getIndex(ord144, true);
      std::vector<u16> ord146({1, 2, 0});
      slog::Relation* readrel147 = db->getRelation("delta");
      deltaindex125 = readrel147->getIndex(ord146, false);
      std::vector<u16> ord148({0, 1, 2});
      slog::Relation* readrel149 = db->getRelation("closure");
      closureindex126 = readrel149->getIndex(ord148, false);
      std::vector<u16> ord150({0});
      slog::Relation* readrel151 = db->getRelation("any_bool");
      any_boolindex127 = readrel151->getIndex(ord150, false);
  
    }
    ReadTask131(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c31 = v_const06abaa100ecef791ce028c56;
      u64 v_c32 = v_constd4735e3a265e16eee03f5971;
      u64 v_c33 = v_const5feceb66ffc86f38d952786c;
      u64 v_c34 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c35 = v_const5feceb66ffc86f38d952786c;
      u64 v_c36 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c37 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c38 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c35, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m152) {
        u64 v_c39 = m152[1];
        u64 v_c40 = m152[2];
        if (buckethash(v_c39) != bucket) return;
        slog::join_probe_old<3,3>($seq_atindex122, $seq_atdelta128, std::array<u64,3>{v_c36, v_c39, v_c40}, [&](const std::array<u64,3>& m153) {
          slog::join_probe_old<3,3>($seq_atrindex123, $seq_atrdelta129, std::array<u64,3>{v_c37, v_c39, v_c40}, [&](const std::array<u64,3>& m154) {
            slog::join_probe_old<3,3>($seq_atrindex124, $seq_atrdelta130, std::array<u64,3>{v_c38, v_c39, v_c40}, [&](const std::array<u64,3>& m155) {
              slog::join_probe<3,2>(deltaindex125, std::array<u64,3>{v_c31, v_c40, 0}, [&](const std::array<u64,3>& m156) {
                u64 v_c41 = m156[2];
                slog::join_probe<3,1>(closureindex126, std::array<u64,3>{v_c39, 0, 0}, [&](const std::array<u64,3>& m157) {
                  u64 v_c42 = m157[1]; u64 v_c43 = m157[2];
                  slog::join_all<1>(any_boolindex127, [&](const std::array<u64,1>& m158) {
                    u64 v_c44 = m158[0];
                    bool ok159 = true;
                    u64 v_c45 = _prim_aslst(db, v_c40, &ok159);
                    if (!ok159) return;
                    u64 v_c46 = _prim_llen(db, v_c45);
                    if (v_c46 == slog_error) { slog::emit_pending_error(db, "interp.slog:126"); return; }
                    if (v_c32 != v_c46) return;
                    bool ok160 = true;
                    u64 v_c47 = _prim_lref(db, v_c45, v_c33, &ok160);
                    if (!ok160) return;
                    if (v_c39 != v_c47) return;
                    bool ok161 = true;
                    u64 v_c48 = _prim_lref(db, v_c45, v_c34, &ok161);
                    if (!ok161) return;
                    if (v_c39 != v_c48) return;
                    ++_fires;
                    slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c41, v_c44});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c44}, std::array<u16,2>{1, 0});
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
        ReadTask131* _cont = new ReadTask131(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask131(db,b), false);
  // (crule (pre) (scan mp_put __t3Rle816 rho x t) (body (exists eval (2 3 0 1) 2 rho t) (exists mp_put_ans (0 1) 1 __t3Rle816) (join $sup70016x92x0x0x0 (3 4 5 0 1 2) 3 rho t x __d0 eb er) (join eval (1 2 3 0) 3 er rho t __t7uXV815) (join eval_ans (0 1) 1 __t7uXV815 vr) (join mp_put_ans (0 1) 1 __t3Rle816 __v0)) (head (emit $sup70016x92x0x0x1 (1 8 0 2 3 4 5 6 7 9) __t7uXV815 vr __d0 __t3Rle816 __v0 eb er rho t x)) interp.slog:93 #f)
  class ReadTask168 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex162;  slog::Index** mp_put_ansindex163;  slog::Index** $sup70016x92x0x0x0index164;  slog::Index** evalindex165;  slog::Index** eval_ansindex166;  slog::Index** mp_put_ansindex167;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup70016x92x0x0x1");
      std::vector<u16> ord169({1, 8, 0, 2, 3, 4, 5, 6, 7, 9});
      slog::Relation* readrel170 = db->getRelation("$sup70016x92x0x0x1");
      head_index[0] = readrel170->getIndex(ord169, false);
      outer_rel = db->getRelation("mp_put");
      std::vector<u16> ord171({2, 3, 0, 1});
      slog::Relation* readrel172 = db->getRelation("eval");
      evalindex162 = readrel172->getIndex(ord171, false);
      std::vector<u16> ord173({0, 1});
      slog::Relation* readrel174 = db->getRelation("mp_put_ans");
      mp_put_ansindex163 = readrel174->getIndex(ord173, false);
      std::vector<u16> ord175({3, 4, 5, 0, 1, 2});
      slog::Relation* readrel176 = db->getRelation("$sup70016x92x0x0x0");
      $sup70016x92x0x0x0index164 = readrel176->getIndex(ord175, false);
      std::vector<u16> ord177({1, 2, 3, 0});
      slog::Relation* readrel178 = db->getRelation("eval");
      evalindex165 = readrel178->getIndex(ord177, false);
      std::vector<u16> ord179({0, 1});
      slog::Relation* readrel180 = db->getRelation("eval_ans");
      eval_ansindex166 = readrel180->getIndex(ord179, false);
      std::vector<u16> ord181({0, 1});
      slog::Relation* readrel182 = db->getRelation("mp_put_ans");
      mp_put_ansindex167 = readrel182->getIndex(ord181, false);
  
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
        u64 v_c49 = _t[0];
        u64 v_c10 = _t[1];
        u64 v_c16 = _t[2];
        u64 v_c11 = _t[3];
        if (!slog::exists_probe<4,2>(evalindex162, std::array<u64,4>{v_c10, v_c11, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_put_ansindex163, std::array<u64,2>{v_c49, 0})) return;
        slog::join_probe<6,3>($sup70016x92x0x0x0index164, std::array<u64,6>{v_c10, v_c11, v_c16, 0, 0, 0}, [&](const std::array<u64,6>& m183) {
          u64 v_c7 = m183[3]; u64 v_c14 = m183[4]; u64 v_c15 = m183[5];
          slog::join_probe<4,3>(evalindex165, std::array<u64,4>{v_c15, v_c10, v_c11, 0}, [&](const std::array<u64,4>& m184) {
            u64 v_c50 = m184[3];
            slog::join_probe<2,1>(eval_ansindex166, std::array<u64,2>{v_c50, 0}, [&](const std::array<u64,2>& m185) {
              u64 v_c21 = m185[1];
              slog::join_probe<2,1>(mp_put_ansindex167, std::array<u64,2>{v_c49, 0}, [&](const std::array<u64,2>& m186) {
                u64 v_c51 = m186[1];
                ++_fires;
                slog::emit<10>(head_rel[0], head_index[0], newbatch[0], std::array<u64,10>{v_c50, v_c21, v_c7, v_c49, v_c51, v_c14, v_c15, v_c10, v_c11, v_c16}, std::array<u16,10>{1, 8, 0, 2, 3, 4, 5, 6, 7, 9});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:93", "delta:mp_put", _fires);
  
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
  // (crule (pre) (scan temp3q8l1778 __t6erK660 b) (body (join boolval (1 0) 1 b __t5eIx658)) (head (emit delta_ans (0 1) __t6erK660 __t5eIx658)) interp.slog:125 #f)
  class ReadTask188 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** boolvalindex187;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("delta_ans");
      std::vector<u16> ord189({0, 1});
      slog::Relation* readrel190 = db->getRelation("delta_ans");
      head_index[0] = readrel190->getIndex(ord189, false);
      outer_rel = db->getRelation("temp3q8l1778");
      std::vector<u16> ord191({1, 0});
      slog::Relation* readrel192 = db->getRelation("boolval");
      boolvalindex187 = readrel192->getIndex(ord191, false);
  
    }
    ReadTask188(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c52 = _t[0];
        u64 v_c44 = _t[1];
        slog::join_probe<2,1>(boolvalindex187, std::array<u64,2>{v_c44, 0}, [&](const std::array<u64,2>& m193) {
          u64 v_c53 = m193[1];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c52, v_c53}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:125", "delta:temp3q8l1778", _fires);
  
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
  // (crule (pre) (scan mp_msk_ans __t7tLj279 q) (body (exists $sup5638x104x0x0x0 (5 3 7 8 0 1 2 4 6) 1 q) (join-old mp_msk (0 1 2) 1 (0 1 2) __t7tLj279 p n) (join $sup5638x104x0x0x0 (3 4 5 0 1 2 6 7 8) 3 n p q __d0 l m r u v)) (head (emit $sup5638x104x0x0x1 (0 8 1 2 3 4 5 6 7 9) __d0 u __t7tLj279 l m n p q r v)) map.slog:105 #f)
  class ReadTask198 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x104x0x0x0index194;  slog::Index** mp_mskindex195;  slog::Index** $sup5638x104x0x0x0index196;  slog::Index** mp_mskdelta197;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x104x0x0x1");
      std::vector<u16> ord199({0, 8, 1, 2, 3, 4, 5, 6, 7, 9});
      slog::Relation* readrel200 = db->getRelation("$sup5638x104x0x0x1");
      head_index[0] = readrel200->getIndex(ord199, false);
      outer_rel = db->getRelation("mp_msk_ans");
      std::vector<u16> ord201({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel202 = db->getRelation("$sup5638x104x0x0x0");
      $sup5638x104x0x0x0index194 = readrel202->getIndex(ord201, false);
      std::vector<u16> ord203({0, 1, 2});
      slog::Relation* readrel204 = db->getRelation("mp_msk");
      mp_mskindex195 = readrel204->getIndex(ord203, false);
      std::vector<u16> ord205({0, 1, 2});
      slog::Relation* readrel206 = db->getRelation("mp_msk");
      mp_mskdelta197 = readrel206->getIndex(ord205, true);
      std::vector<u16> ord207({3, 4, 5, 0, 1, 2, 6, 7, 8});
      slog::Relation* readrel208 = db->getRelation("$sup5638x104x0x0x0");
      $sup5638x104x0x0x0index196 = readrel208->getIndex(ord207, false);
  
    }
    ReadTask198(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c54 = _t[0];
        u64 v_c55 = _t[1];
        if (!slog::exists_probe<9,1>($sup5638x104x0x0x0index194, std::array<u64,9>{v_c55, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(mp_mskindex195, mp_mskdelta197, std::array<u64,3>{v_c54, 0, 0}, [&](const std::array<u64,3>& m209) {
          u64 v_c56 = m209[1]; u64 v_c57 = m209[2];
          slog::join_probe<9,3>($sup5638x104x0x0x0index196, std::array<u64,9>{v_c57, v_c56, v_c55, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m210) {
            u64 v_c7 = m210[3]; u64 v_c58 = m210[4]; u64 v_c59 = m210[5]; u64 v_c24 = m210[6]; u64 v_c60 = m210[7]; u64 v_c22 = m210[8];
            ++_fires;
            slog::emit<10>(head_rel[0], head_index[0], newbatch[0], std::array<u64,10>{v_c7, v_c60, v_c54, v_c58, v_c59, v_c57, v_c56, v_c55, v_c24, v_c22}, std::array<u16,10>{0, 8, 1, 2, 3, 4, 5, 6, 7, 9});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:105", "delta:mp_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask198* _cont = new ReadTask198(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask198(db,b), false);
  // (crule (pre) (scan mleaf __t6AYq628 k v) (body (exists mp_join (1 2 3 4 0) 2 k __t6AYq628) (join mp_put (2 3 0 1) 2 k v __t4a7n626 __t8ls4627) (join-old mp_join (1 4 2 0 3) 3 (1 4 2 0 3) k __t8ls4627 __t6AYq628 __t5fYY629 j) (neq j k) (exists mp_join_ans (0 1) 1 __t5fYY629) (join mleaf (0 1 2) 2 __t8ls4627 j w) (join mp_join_ans (0 1) 1 __t5fYY629 r)) (head (emit mp_put_ans (0 1) __t4a7n626 r)) map.slog:39 #f)
  class ReadTask218 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_joinindex211;  slog::Index** mp_putindex212;  slog::Index** mp_joinindex213;  slog::Index** mp_join_ansindex214;  slog::Index** mleafindex215;  slog::Index** mp_join_ansindex216;  slog::Index** mp_joindelta217;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_ans");
      std::vector<u16> ord219({0, 1});
      slog::Relation* readrel220 = db->getRelation("mp_put_ans");
      head_index[0] = readrel220->getIndex(ord219, false);
      outer_rel = db->getRelation("mleaf");
      std::vector<u16> ord221({1, 2, 3, 4, 0});
      slog::Relation* readrel222 = db->getRelation("mp_join");
      mp_joinindex211 = readrel222->getIndex(ord221, false);
      std::vector<u16> ord223({2, 3, 0, 1});
      slog::Relation* readrel224 = db->getRelation("mp_put");
      mp_putindex212 = readrel224->getIndex(ord223, false);
      std::vector<u16> ord225({1, 4, 2, 0, 3});
      slog::Relation* readrel226 = db->getRelation("mp_join");
      mp_joinindex213 = readrel226->getIndex(ord225, false);
      std::vector<u16> ord227({1, 4, 2, 0, 3});
      slog::Relation* readrel228 = db->getRelation("mp_join");
      mp_joindelta217 = readrel228->getIndex(ord227, true);
      std::vector<u16> ord229({0, 1});
      slog::Relation* readrel230 = db->getRelation("mp_join_ans");
      mp_join_ansindex214 = readrel230->getIndex(ord229, false);
      std::vector<u16> ord231({0, 1, 2});
      slog::Relation* readrel232 = db->getRelation("mleaf");
      mleafindex215 = readrel232->getIndex(ord231, false);
      std::vector<u16> ord233({0, 1});
      slog::Relation* readrel234 = db->getRelation("mp_join_ans");
      mp_join_ansindex216 = readrel234->getIndex(ord233, false);
  
    }
    ReadTask218(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c25 = _t[1];
        u64 v_c22 = _t[2];
        if (!slog::exists_probe<5,2>(mp_joinindex211, std::array<u64,5>{v_c25, v_c26, 0, 0, 0})) return;
        slog::join_probe<4,2>(mp_putindex212, std::array<u64,4>{v_c25, v_c22, 0, 0}, [&](const std::array<u64,4>& m235) {
          u64 v_c30 = m235[2]; u64 v_c28 = m235[3];
          slog::join_probe_old<5,3>(mp_joinindex213, mp_joindelta217, std::array<u64,5>{v_c25, v_c28, v_c26, 0, 0}, [&](const std::array<u64,5>& m236) {
            u64 v_c23 = m236[3]; u64 v_c27 = m236[4];
            if (v_c27 == v_c25) return;
            if (!slog::exists_probe<2,1>(mp_join_ansindex214, std::array<u64,2>{v_c23, 0})) return;
            slog::join_probe<3,2>(mleafindex215, std::array<u64,3>{v_c28, v_c27, 0}, [&](const std::array<u64,3>& m237) {
              u64 v_c29 = m237[2];
              slog::join_probe<2,1>(mp_join_ansindex216, std::array<u64,2>{v_c23, 0}, [&](const std::array<u64,2>& m238) {
                u64 v_c24 = m238[1];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c30, v_c24}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:39", "delta:mleaf", _fires);
  
      if (!_done)
      {
        ReadTask218* _cont = new ReadTask218(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask218(db,b), false);
  // (crule (pre (let __tconst49eD1184 constcd2a69ce5ca278db1d6da969) (let __tconst7GbT659 const06abaa100ecef791ce028c56) (let _00024sqc0jJd1013 constd4735e3a265e16eee03f5971) (let _00024sqc54us1014 const5feceb66ffc86f38d952786c) (let _00024sqc6uOX1015 const6b86b273ff34fce19d6b804e) (let _00024sqo8ZRa1016 const5feceb66ffc86f38d952786c) (let _00024sqo9lkw1017 const6b86b273ff34fce19d6b804e) (let _00024sqo8so11018 const6b86b273ff34fce19d6b804e) (let _00024sqo0qa11019 const5feceb66ffc86f38d952786c)) (probe $seq_atr (1 0 2) 1 _00024sqo8so11018 __t013P662 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo8ZRa1016 __t013P662 _00024seq2) (join $seq_at (1 0 2) 3 _00024sqo9lkw1017 __t013P662 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo0qa11019 __t013P662 _00024seq2) (join _enum (0 1) 2 __t013P662 __tconst49eD1184) (join delta (1 2 0) 2 __tconst7GbT659 _00024seq2 __t6erK660) (join any_bool (0) 0 b) (letp _00024sql99Ol1011 (aslst _00024seq2)) (let chk4VoV1787 (llen _00024sql99Ol1011)) (eq _00024sqc0jJd1013 chk4VoV1787) (letp chk7EHt1788 (lref _00024sql99Ol1011 _00024sqc54us1014)) (eq __t013P662 chk7EHt1788) (letp chk9yf91789 (lref _00024sql99Ol1011 _00024sqc6uOX1015)) (eq __t013P662 chk9yf91789)) (head (emit-temp temp3q8l1778 __t6erK660 b) (mkstruct boolval (1 0) __t5eIx658 b)) interp.slog:125 #f)
  class ReadTask246 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex239;  slog::Index** $seq_atindex240;  slog::Index** $seq_atrindex241;  slog::Index** _enumindex242;  slog::Index** deltaindex243;  slog::Index** any_boolindex244;  slog::Index** $seq_atrdelta245;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3q8l1778");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord247({1, 0, 2});
      slog::Relation* readrel248 = db->getRelation("$seq_atr");
      driver_index = readrel248->getIndex(ord247, true);
      std::vector<u16> ord249({1, 0, 2});
      slog::Relation* readrel250 = db->getRelation("$seq_at");
      $seq_atindex239 = readrel250->getIndex(ord249, false);
      std::vector<u16> ord251({1, 0, 2});
      slog::Relation* readrel252 = db->getRelation("$seq_at");
      $seq_atindex240 = readrel252->getIndex(ord251, false);
      std::vector<u16> ord253({1, 0, 2});
      slog::Relation* readrel254 = db->getRelation("$seq_atr");
      $seq_atrindex241 = readrel254->getIndex(ord253, false);
      std::vector<u16> ord255({1, 0, 2});
      slog::Relation* readrel256 = db->getRelation("$seq_atr");
      $seq_atrdelta245 = readrel256->getIndex(ord255, true);
      std::vector<u16> ord257({0, 1});
      slog::Relation* readrel258 = db->getRelation("_enum");
      _enumindex242 = readrel258->getIndex(ord257, false);
      std::vector<u16> ord259({1, 2, 0});
      slog::Relation* readrel260 = db->getRelation("delta");
      deltaindex243 = readrel260->getIndex(ord259, false);
      std::vector<u16> ord261({0});
      slog::Relation* readrel262 = db->getRelation("any_bool");
      any_boolindex244 = readrel262->getIndex(ord261, false);
  
    }
    ReadTask246(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c61 = v_constcd2a69ce5ca278db1d6da969;
      u64 v_c62 = v_const06abaa100ecef791ce028c56;
      u64 v_c63 = v_constd4735e3a265e16eee03f5971;
      u64 v_c64 = v_const5feceb66ffc86f38d952786c;
      u64 v_c65 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c66 = v_const5feceb66ffc86f38d952786c;
      u64 v_c67 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c68 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c69 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c68, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m263) {
        u64 v_c70 = m263[1];
        u64 v_c40 = m263[2];
        if (buckethash(v_c70) != bucket) return;
        slog::join_probe<3,3>($seq_atindex239, std::array<u64,3>{v_c66, v_c70, v_c40}, [&](const std::array<u64,3>& m264) {
          slog::join_probe<3,3>($seq_atindex240, std::array<u64,3>{v_c67, v_c70, v_c40}, [&](const std::array<u64,3>& m265) {
            slog::join_probe_old<3,3>($seq_atrindex241, $seq_atrdelta245, std::array<u64,3>{v_c69, v_c70, v_c40}, [&](const std::array<u64,3>& m266) {
              slog::join_probe<2,2>(_enumindex242, std::array<u64,2>{v_c70, v_c61}, [&](const std::array<u64,2>& m267) {
                slog::join_probe<3,2>(deltaindex243, std::array<u64,3>{v_c62, v_c40, 0}, [&](const std::array<u64,3>& m268) {
                  u64 v_c52 = m268[2];
                  slog::join_all<1>(any_boolindex244, [&](const std::array<u64,1>& m269) {
                    u64 v_c44 = m269[0];
                    bool ok270 = true;
                    u64 v_c71 = _prim_aslst(db, v_c40, &ok270);
                    if (!ok270) return;
                    u64 v_c72 = _prim_llen(db, v_c71);
                    if (v_c72 == slog_error) { slog::emit_pending_error(db, "interp.slog:125"); return; }
                    if (v_c63 != v_c72) return;
                    bool ok271 = true;
                    u64 v_c73 = _prim_lref(db, v_c71, v_c64, &ok271);
                    if (!ok271) return;
                    if (v_c70 != v_c73) return;
                    bool ok272 = true;
                    u64 v_c74 = _prim_lref(db, v_c71, v_c65, &ok272);
                    if (!ok272) return;
                    if (v_c70 != v_c74) return;
                    ++_fires;
                    slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c52, v_c44});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c44}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:125", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask246* _cont = new ReadTask246(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask246(db,b), false);
  // (crule (pre (let __tconst6pU7782 const5feceb66ffc86f38d952786c)) (scan $sup5638x29x0x0x1 __t7O3e781 __t8x7Q785 __v0 p0 p1 t0 t1) (body (exists $sup5638x29x0x0x0 (1 0 2 3 4) 5 p0 __t7O3e781 p1 t0 t1) (exists mp_join (1 2 3 4 0) 5 p0 t0 p1 t1 __t7O3e781) (exists mp_hsb_ans (0 1) 1 __t8x7Q785) (exists mp_hsb_ans (0 1) 2 __t8x7Q785 __v0) (exists mp_msk (1 2 0) 1 p0) (join $sup5638x29x0x0x2 (0 7 8 9 10 1 4 2 3 5 6) 7 __t7O3e781 p0 p1 t0 t1 __t8x7Q785 __v0 dup6QI21998 dup4FCe1999 __v1 __v3) (eq __t8x7Q785 dup4FCe1999) (eq __t8x7Q785 dup6QI21998) (join-old $sup5638x29x0x0x0 (1 0 2 3 4) 5 (1 0 2 3 4) p0 __t7O3e781 p1 t0 t1) (join-old mp_join (1 2 3 4 0) 5 (1 2 3 4 0) p0 t0 p1 t1 __t7O3e781) (join-old mp_hsb_ans (0 1) 2 (0 1) __t8x7Q785 __v3) (join-old mp_hsb_ans (0 1) 2 (0 1) __t8x7Q785 __v1) (join-old mp_hsb_ans (0 1) 2 (0 1) __t8x7Q785 __v0) (join-old mp_msk (1 2 0) 2 (1 2 0) p0 __v1 __t4ZDq788) (join-old mp_msk_ans (0 1) 1 (0 1) __t4ZDq788 __v2) (let __t1znr789 (bxor p0 p1)) (join-old mp_hsb (0 1) 2 (0 1) __t8x7Q785 __t1znr789) (let __t8SIw783 (band p0 __v0)) (cmp gt __t8SIw783 __tconst6pU7782)) (head (emit-temp temp4rXE1997 __t7O3e781 __v2 __v3 t0 t1) (mkstruct mbranch (1 2 3 4 0) __t6B7E780 __v2 __v3 t1 t0)) map.slog:30 #f)
  class ReadTask295 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x29x0x0x0index273;  slog::Index** mp_joinindex274;  slog::Index** mp_hsb_ansindex275;  slog::Index** mp_hsb_ansindex276;  slog::Index** mp_mskindex277;  slog::Index** $sup5638x29x0x0x2index278;  slog::Index** $sup5638x29x0x0x0index279;  slog::Index** mp_joinindex280;  slog::Index** mp_hsb_ansindex281;  slog::Index** mp_hsb_ansindex282;  slog::Index** mp_hsb_ansindex283;  slog::Index** mp_mskindex284;  slog::Index** mp_msk_ansindex285;  slog::Index** mp_hsbindex286;  slog::Index** $sup5638x29x0x0x0delta287;  slog::Index** mp_joindelta288;  slog::Index** mp_hsb_ansdelta289;  slog::Index** mp_hsb_ansdelta290;  slog::Index** mp_hsb_ansdelta291;  slog::Index** mp_mskdelta292;  slog::Index** mp_msk_ansdelta293;  slog::Index** mp_hsbdelta294;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4rXE1997");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("$sup5638x29x0x0x1");
      std::vector<u16> ord296({1, 0, 2, 3, 4});
      slog::Relation* readrel297 = db->getRelation("$sup5638x29x0x0x0");
      $sup5638x29x0x0x0index273 = readrel297->getIndex(ord296, false);
      std::vector<u16> ord298({1, 2, 3, 4, 0});
      slog::Relation* readrel299 = db->getRelation("mp_join");
      mp_joinindex274 = readrel299->getIndex(ord298, false);
      std::vector<u16> ord300({0, 1});
      slog::Relation* readrel301 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex275 = readrel301->getIndex(ord300, false);
      std::vector<u16> ord302({0, 1});
      slog::Relation* readrel303 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex276 = readrel303->getIndex(ord302, false);
      std::vector<u16> ord304({1, 2, 0});
      slog::Relation* readrel305 = db->getRelation("mp_msk");
      mp_mskindex277 = readrel305->getIndex(ord304, false);
      std::vector<u16> ord306({0, 7, 8, 9, 10, 1, 4, 2, 3, 5, 6});
      slog::Relation* readrel307 = db->getRelation("$sup5638x29x0x0x2");
      $sup5638x29x0x0x2index278 = readrel307->getIndex(ord306, false);
      std::vector<u16> ord308({1, 0, 2, 3, 4});
      slog::Relation* readrel309 = db->getRelation("$sup5638x29x0x0x0");
      $sup5638x29x0x0x0index279 = readrel309->getIndex(ord308, false);
      std::vector<u16> ord310({1, 0, 2, 3, 4});
      slog::Relation* readrel311 = db->getRelation("$sup5638x29x0x0x0");
      $sup5638x29x0x0x0delta287 = readrel311->getIndex(ord310, true);
      std::vector<u16> ord312({1, 2, 3, 4, 0});
      slog::Relation* readrel313 = db->getRelation("mp_join");
      mp_joinindex280 = readrel313->getIndex(ord312, false);
      std::vector<u16> ord314({1, 2, 3, 4, 0});
      slog::Relation* readrel315 = db->getRelation("mp_join");
      mp_joindelta288 = readrel315->getIndex(ord314, true);
      std::vector<u16> ord316({0, 1});
      slog::Relation* readrel317 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex281 = readrel317->getIndex(ord316, false);
      std::vector<u16> ord318({0, 1});
      slog::Relation* readrel319 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta289 = readrel319->getIndex(ord318, true);
      std::vector<u16> ord320({0, 1});
      slog::Relation* readrel321 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex282 = readrel321->getIndex(ord320, false);
      std::vector<u16> ord322({0, 1});
      slog::Relation* readrel323 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta290 = readrel323->getIndex(ord322, true);
      std::vector<u16> ord324({0, 1});
      slog::Relation* readrel325 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex283 = readrel325->getIndex(ord324, false);
      std::vector<u16> ord326({0, 1});
      slog::Relation* readrel327 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansdelta291 = readrel327->getIndex(ord326, true);
      std::vector<u16> ord328({1, 2, 0});
      slog::Relation* readrel329 = db->getRelation("mp_msk");
      mp_mskindex284 = readrel329->getIndex(ord328, false);
      std::vector<u16> ord330({1, 2, 0});
      slog::Relation* readrel331 = db->getRelation("mp_msk");
      mp_mskdelta292 = readrel331->getIndex(ord330, true);
      std::vector<u16> ord332({0, 1});
      slog::Relation* readrel333 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex285 = readrel333->getIndex(ord332, false);
      std::vector<u16> ord334({0, 1});
      slog::Relation* readrel335 = db->getRelation("mp_msk_ans");
      mp_msk_ansdelta293 = readrel335->getIndex(ord334, true);
      std::vector<u16> ord336({0, 1});
      slog::Relation* readrel337 = db->getRelation("mp_hsb");
      mp_hsbindex286 = readrel337->getIndex(ord336, false);
      std::vector<u16> ord338({0, 1});
      slog::Relation* readrel339 = db->getRelation("mp_hsb");
      mp_hsbdelta294 = readrel339->getIndex(ord338, true);
  
    }
    ReadTask295(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c75 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c76 = _t[0];
        u64 v_c77 = _t[1];
        u64 v_c51 = _t[2];
        u64 v_c78 = _t[3];
        u64 v_c79 = _t[4];
        u64 v_c80 = _t[5];
        u64 v_c81 = _t[6];
        if (!slog::exists_probe<5,5>($sup5638x29x0x0x0index273, std::array<u64,5>{v_c78, v_c76, v_c79, v_c80, v_c81})) return;
        if (!slog::exists_probe<5,5>(mp_joinindex274, std::array<u64,5>{v_c78, v_c80, v_c79, v_c81, v_c76})) return;
        if (!slog::exists_probe<2,1>(mp_hsb_ansindex275, std::array<u64,2>{v_c77, 0})) return;
        if (!slog::exists_probe<2,2>(mp_hsb_ansindex276, std::array<u64,2>{v_c77, v_c51})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex277, std::array<u64,3>{v_c78, 0, 0})) return;
        slog::join_probe<11,7>($sup5638x29x0x0x2index278, std::array<u64,11>{v_c76, v_c78, v_c79, v_c80, v_c81, v_c77, v_c51, 0, 0, 0, 0}, [&](const std::array<u64,11>& m340) {
          u64 v_c82 = m340[7]; u64 v_c83 = m340[8]; u64 v_c84 = m340[9]; u64 v_c85 = m340[10];
          if (v_c77 != v_c83) return;
          if (v_c77 != v_c82) return;
          slog::join_probe_old<5,5>($sup5638x29x0x0x0index279, $sup5638x29x0x0x0delta287, std::array<u64,5>{v_c78, v_c76, v_c79, v_c80, v_c81}, [&](const std::array<u64,5>& m341) {
            slog::join_probe_old<5,5>(mp_joinindex280, mp_joindelta288, std::array<u64,5>{v_c78, v_c80, v_c79, v_c81, v_c76}, [&](const std::array<u64,5>& m342) {
              slog::join_probe_old<2,2>(mp_hsb_ansindex281, mp_hsb_ansdelta289, std::array<u64,2>{v_c77, v_c85}, [&](const std::array<u64,2>& m343) {
                slog::join_probe_old<2,2>(mp_hsb_ansindex282, mp_hsb_ansdelta290, std::array<u64,2>{v_c77, v_c84}, [&](const std::array<u64,2>& m344) {
                  slog::join_probe_old<2,2>(mp_hsb_ansindex283, mp_hsb_ansdelta291, std::array<u64,2>{v_c77, v_c51}, [&](const std::array<u64,2>& m345) {
                    slog::join_probe_old<3,2>(mp_mskindex284, mp_mskdelta292, std::array<u64,3>{v_c78, v_c84, 0}, [&](const std::array<u64,3>& m346) {
                      u64 v_c86 = m346[2];
                      slog::join_probe_old<2,1>(mp_msk_ansindex285, mp_msk_ansdelta293, std::array<u64,2>{v_c86, 0}, [&](const std::array<u64,2>& m347) {
                        u64 v_c87 = m347[1];
                        u64 v_c88 = _prim_bxor(db, v_c78, v_c79);
                        if (v_c88 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                        slog::join_probe_old<2,2>(mp_hsbindex286, mp_hsbdelta294, std::array<u64,2>{v_c77, v_c88}, [&](const std::array<u64,2>& m348) {
                          u64 v_c89 = _prim_band(db, v_c78, v_c51);
                          if (v_c89 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                          u64 v_c90 = _prim_gt(db, v_c89, v_c75);
                          if (v_c90 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
                          if (!v_c90) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c76, v_c87, v_c85, v_c80, v_c81});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c87, v_c85, v_c81, v_c80}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:30", "delta:$sup5638x29x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask295* _cont = new ReadTask295(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask295(db,b), false);
  // (crule (pre) (scan mp_put __t1yia422 t k v) (body (exists mp_union (2 0 1) 1 t) (exists mp_put_ans (0 1) 1 __t1yia422) (join mleaf (1 2 0) 2 k v __t4XKi420) (join mp_union (1 2 0) 2 __t4XKi420 t __t5GHT421) (join mp_put_ans (0 1) 1 __t1yia422 r)) (head (emit mp_union_ans (0 1) __t5GHT421 r)) map.slog:92 #f)
  class ReadTask355 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex350;  slog::Index** mp_put_ansindex351;  slog::Index** mleafindex352;  slog::Index** mp_unionindex353;  slog::Index** mp_put_ansindex354;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord356({0, 1});
      slog::Relation* readrel357 = db->getRelation("mp_union_ans");
      head_index[0] = readrel357->getIndex(ord356, false);
      outer_rel = db->getRelation("mp_put");
      std::vector<u16> ord358({2, 0, 1});
      slog::Relation* readrel359 = db->getRelation("mp_union");
      mp_unionindex350 = readrel359->getIndex(ord358, false);
      std::vector<u16> ord360({0, 1});
      slog::Relation* readrel361 = db->getRelation("mp_put_ans");
      mp_put_ansindex351 = readrel361->getIndex(ord360, false);
      std::vector<u16> ord362({1, 2, 0});
      slog::Relation* readrel363 = db->getRelation("mleaf");
      mleafindex352 = readrel363->getIndex(ord362, false);
      std::vector<u16> ord364({1, 2, 0});
      slog::Relation* readrel365 = db->getRelation("mp_union");
      mp_unionindex353 = readrel365->getIndex(ord364, false);
      std::vector<u16> ord366({0, 1});
      slog::Relation* readrel367 = db->getRelation("mp_put_ans");
      mp_put_ansindex354 = readrel367->getIndex(ord366, false);
  
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
        u64 v_c91 = _t[0];
        u64 v_c11 = _t[1];
        u64 v_c25 = _t[2];
        u64 v_c22 = _t[3];
        if (!slog::exists_probe<3,1>(mp_unionindex350, std::array<u64,3>{v_c11, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_put_ansindex351, std::array<u64,2>{v_c91, 0})) return;
        slog::join_probe<3,2>(mleafindex352, std::array<u64,3>{v_c25, v_c22, 0}, [&](const std::array<u64,3>& m368) {
          u64 v_c92 = m368[2];
          slog::join_probe<3,2>(mp_unionindex353, std::array<u64,3>{v_c92, v_c11, 0}, [&](const std::array<u64,3>& m369) {
            u64 v_c93 = m369[2];
            slog::join_probe<2,1>(mp_put_ansindex354, std::array<u64,2>{v_c91, 0}, [&](const std::array<u64,2>& m370) {
              u64 v_c24 = m370[1];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c93, v_c24}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:92", "delta:mp_put", _fires);
  
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
  // (crule (pre) (scan eval __t5iY7814 __t5LFI813 rho t) (body (join let (0 2 1 3) 1 __t5LFI813 er x eb)) (head (emit $sup70016x92x0x0x0 (1 4 0 2 3 5) eb t __t5iY7814 er rho x)) interp.slog:93 #f)
  class ReadTask372 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letindex371;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup70016x92x0x0x0");
      std::vector<u16> ord373({1, 4, 0, 2, 3, 5});
      slog::Relation* readrel374 = db->getRelation("$sup70016x92x0x0x0");
      head_index[0] = readrel374->getIndex(ord373, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord375({0, 2, 1, 3});
      slog::Relation* readrel376 = db->getRelation("let");
      letindex371 = readrel376->getIndex(ord375, false);
  
    }
    ReadTask372(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c95 = _t[1];
        u64 v_c10 = _t[2];
        u64 v_c11 = _t[3];
        slog::join_probe<4,1>(letindex371, std::array<u64,4>{v_c95, 0, 0, 0}, [&](const std::array<u64,4>& m377) {
          u64 v_c15 = m377[1]; u64 v_c16 = m377[2]; u64 v_c14 = m377[3];
          ++_fires;
          slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c14, v_c11, v_c94, v_c15, v_c10, v_c16}, std::array<u16,6>{1, 4, 0, 2, 3, 5});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:93", "delta:eval", _fires);
  
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
  // (crule (pre) (scan temp9x9w1897 __t5IFg653 s) (body (join symval (1 0) 1 s __t2tjI651)) (head (emit eval_ans (0 1) __t5IFg653 __t2tjI651)) interp.slog:32 #f)
  class ReadTask379 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** symvalindex378;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord380({0, 1});
      slog::Relation* readrel381 = db->getRelation("eval_ans");
      head_index[0] = readrel381->getIndex(ord380, false);
      outer_rel = db->getRelation("temp9x9w1897");
      std::vector<u16> ord382({1, 0});
      slog::Relation* readrel383 = db->getRelation("symval");
      symvalindex378 = readrel383->getIndex(ord382, false);
  
    }
    ReadTask379(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c96 = _t[0];
        u64 v_c97 = _t[1];
        slog::join_probe<2,1>(symvalindex378, std::array<u64,2>{v_c97, 0}, [&](const std::array<u64,2>& m384) {
          u64 v_c98 = m384[1];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c96, v_c98}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:32", "delta:temp9x9w1897", _fires);
  
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
  // (crule (pre) (scan mp_put __t7WtB688 __t3q5a687 k v) (body (join mleaf (0 1 2) 2 __t3q5a687 k w)) (head (emit-temp temp5lsY1878 __t7WtB688 k v) (mkstruct mleaf (1 2 0) __t9pzZ686 k v)) map.slog:38 #f)
  class ReadTask386 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mleafindex385;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp5lsY1878");
      head_rel[1] = db->getRelation("mleaf");
      outer_rel = db->getRelation("mp_put");
      std::vector<u16> ord387({0, 1, 2});
      slog::Relation* readrel388 = db->getRelation("mleaf");
      mleafindex385 = readrel388->getIndex(ord387, false);
  
    }
    ReadTask386(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c99 = _t[0];
        u64 v_c100 = _t[1];
        u64 v_c25 = _t[2];
        u64 v_c22 = _t[3];
        slog::join_probe<3,2>(mleafindex385, std::array<u64,3>{v_c100, v_c25, 0}, [&](const std::array<u64,3>& m389) {
          u64 v_c29 = m389[2];
          ++_fires;
          slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c99, v_c25, v_c22});
          slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c25, v_c22}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("map.slog:38", "delta:mp_put", _fires);
  
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
  // (crule (pre) (scan eval __4PdZ1446 __t3kGW443 rho t) (body (join-old eval (2 3 0 1) 2 (2 3 0 1) rho t __t6VzV444 er) (exists eval_ans (0 1) 1 __t6VzV444) (join-old let (0 2 1 3) 2 (0 2 1 3) __t3kGW443 er x eb) (join-old eval_ans (0 1) 1 (0 1) __t6VzV444 vr)) (head (emit store (0 1 2) x t vr) (emit binding_event (0 1 2) x t t)) interp.slog:94 #f)
  class ReadTask397 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex390;  slog::Index** eval_ansindex391;  slog::Index** letindex392;  slog::Index** eval_ansindex393;  slog::Index** evaldelta394;  slog::Index** letdelta395;  slog::Index** eval_ansdelta396;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("store");
      std::vector<u16> ord398({0, 1, 2});
      slog::Relation* readrel399 = db->getRelation("store");
      head_index[0] = readrel399->getIndex(ord398, false);
      head_rel[1] = db->getRelation("binding_event");
      std::vector<u16> ord400({0, 1, 2});
      slog::Relation* readrel401 = db->getRelation("binding_event");
      head_index[1] = readrel401->getIndex(ord400, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord402({2, 3, 0, 1});
      slog::Relation* readrel403 = db->getRelation("eval");
      evalindex390 = readrel403->getIndex(ord402, false);
      std::vector<u16> ord404({2, 3, 0, 1});
      slog::Relation* readrel405 = db->getRelation("eval");
      evaldelta394 = readrel405->getIndex(ord404, true);
      std::vector<u16> ord406({0, 1});
      slog::Relation* readrel407 = db->getRelation("eval_ans");
      eval_ansindex391 = readrel407->getIndex(ord406, false);
      std::vector<u16> ord408({0, 2, 1, 3});
      slog::Relation* readrel409 = db->getRelation("let");
      letindex392 = readrel409->getIndex(ord408, false);
      std::vector<u16> ord410({0, 2, 1, 3});
      slog::Relation* readrel411 = db->getRelation("let");
      letdelta395 = readrel411->getIndex(ord410, true);
      std::vector<u16> ord412({0, 1});
      slog::Relation* readrel413 = db->getRelation("eval_ans");
      eval_ansindex393 = readrel413->getIndex(ord412, false);
      std::vector<u16> ord414({0, 1});
      slog::Relation* readrel415 = db->getRelation("eval_ans");
      eval_ansdelta396 = readrel415->getIndex(ord414, true);
  
    }
    ReadTask397(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c101 = _t[0];
        u64 v_c102 = _t[1];
        u64 v_c10 = _t[2];
        u64 v_c11 = _t[3];
        slog::join_probe_old<4,2>(evalindex390, evaldelta394, std::array<u64,4>{v_c10, v_c11, 0, 0}, [&](const std::array<u64,4>& m416) {
          u64 v_c103 = m416[2]; u64 v_c15 = m416[3];
          if (!slog::exists_probe<2,1>(eval_ansindex391, std::array<u64,2>{v_c103, 0})) return;
          slog::join_probe_old<4,2>(letindex392, letdelta395, std::array<u64,4>{v_c102, v_c15, 0, 0}, [&](const std::array<u64,4>& m417) {
            u64 v_c16 = m417[2]; u64 v_c14 = m417[3];
            slog::join_probe_old<2,1>(eval_ansindex393, eval_ansdelta396, std::array<u64,2>{v_c103, 0}, [&](const std::array<u64,2>& m418) {
              u64 v_c21 = m418[1];
              ++_fires;
              slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c16, v_c11, v_c21}, std::array<u16,3>{0, 1, 2});
              slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c16, v_c11, v_c11}, std::array<u16,3>{0, 1, 2});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:94", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask397* _cont = new ReadTask397(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask397(db,b), false);
  // (crule (pre (let __tconst8WcI1085 const0122baa3ac55f1b433944eb1) (let __tconst9cNI595 const06abaa100ecef791ce028c56) (let _00024sqc696g1041 constd4735e3a265e16eee03f5971) (let _00024sqc3XnD1042 const5feceb66ffc86f38d952786c) (let _00024sqc4UkF1043 const6b86b273ff34fce19d6b804e) (let _00024sqo05pe1044 const5feceb66ffc86f38d952786c) (let _00024sqo5XjX1045 const6b86b273ff34fce19d6b804e) (let _00024sqo0BYf1046 const6b86b273ff34fce19d6b804e) (let _00024sqo9pUp1047 const5feceb66ffc86f38d952786c)) (scan symval __t7ye2598 s) (body (exists $seq_at (1 0 2) 2 _00024sqo5XjX1045 __t7ye2598) (exists $seq_atr (1 0 2) 2 _00024sqo0BYf1046 __t7ye2598) (exists $seq_atr (1 0 2) 2 _00024sqo9pUp1047 __t7ye2598) (exists delta (1 2 0) 1 __tconst9cNI595) (exists _enum (1 0) 1 __tconst8WcI1085) (join-old $seq_at (1 0 2) 2 (1 0 2) _00024sqo05pe1044 __t7ye2598 _00024seq2) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo5XjX1045 __t7ye2598 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo0BYf1046 __t7ye2598 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo9pUp1047 __t7ye2598 _00024seq2) (join delta (1 2 0) 2 __tconst9cNI595 _00024seq2 __t0WVv596) (join _enum (1 0) 1 __tconst8WcI1085 __t8vy6593) (letp _00024sql2mO51039 (aslst _00024seq2)) (let chk9B0U2015 (llen _00024sql2mO51039)) (eq _00024sqc696g1041 chk9B0U2015) (letp chk4zqg2016 (lref _00024sql2mO51039 _00024sqc3XnD1042)) (eq __t7ye2598 chk4zqg2016) (letp chk1ePc2017 (lref _00024sql2mO51039 _00024sqc4UkF1043)) (eq __t7ye2598 chk1ePc2017)) (head (emit-temp temp7W0m2012 __t0WVv596) (mkstruct boolval (1 0) __t17ui594 __t8vy6593)) interp.slog:121 #f)
  class ReadTask434 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $seq_atindex419;  slog::Index** $seq_atrindex420;  slog::Index** $seq_atrindex421;  slog::Index** deltaindex422;  slog::Index** _enumindex423;  slog::Index** $seq_atindex424;  slog::Index** $seq_atindex425;  slog::Index** $seq_atrindex426;  slog::Index** $seq_atrindex427;  slog::Index** deltaindex428;  slog::Index** _enumindex429;  slog::Index** $seq_atdelta430;  slog::Index** $seq_atdelta431;  slog::Index** $seq_atrdelta432;  slog::Index** $seq_atrdelta433;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7W0m2012");
      head_rel[1] = db->getRelation("boolval");
      outer_rel = db->getRelation("symval");
      std::vector<u16> ord435({1, 0, 2});
      slog::Relation* readrel436 = db->getRelation("$seq_at");
      $seq_atindex419 = readrel436->getIndex(ord435, false);
      std::vector<u16> ord437({1, 0, 2});
      slog::Relation* readrel438 = db->getRelation("$seq_atr");
      $seq_atrindex420 = readrel438->getIndex(ord437, false);
      std::vector<u16> ord439({1, 0, 2});
      slog::Relation* readrel440 = db->getRelation("$seq_atr");
      $seq_atrindex421 = readrel440->getIndex(ord439, false);
      std::vector<u16> ord441({1, 2, 0});
      slog::Relation* readrel442 = db->getRelation("delta");
      deltaindex422 = readrel442->getIndex(ord441, false);
      std::vector<u16> ord443({1, 0});
      slog::Relation* readrel444 = db->getRelation("_enum");
      _enumindex423 = readrel444->getIndex(ord443, false);
      std::vector<u16> ord445({1, 0, 2});
      slog::Relation* readrel446 = db->getRelation("$seq_at");
      $seq_atindex424 = readrel446->getIndex(ord445, false);
      std::vector<u16> ord447({1, 0, 2});
      slog::Relation* readrel448 = db->getRelation("$seq_at");
      $seq_atdelta430 = readrel448->getIndex(ord447, true);
      std::vector<u16> ord449({1, 0, 2});
      slog::Relation* readrel450 = db->getRelation("$seq_at");
      $seq_atindex425 = readrel450->getIndex(ord449, false);
      std::vector<u16> ord451({1, 0, 2});
      slog::Relation* readrel452 = db->getRelation("$seq_at");
      $seq_atdelta431 = readrel452->getIndex(ord451, true);
      std::vector<u16> ord453({1, 0, 2});
      slog::Relation* readrel454 = db->getRelation("$seq_atr");
      $seq_atrindex426 = readrel454->getIndex(ord453, false);
      std::vector<u16> ord455({1, 0, 2});
      slog::Relation* readrel456 = db->getRelation("$seq_atr");
      $seq_atrdelta432 = readrel456->getIndex(ord455, true);
      std::vector<u16> ord457({1, 0, 2});
      slog::Relation* readrel458 = db->getRelation("$seq_atr");
      $seq_atrindex427 = readrel458->getIndex(ord457, false);
      std::vector<u16> ord459({1, 0, 2});
      slog::Relation* readrel460 = db->getRelation("$seq_atr");
      $seq_atrdelta433 = readrel460->getIndex(ord459, true);
      std::vector<u16> ord461({1, 2, 0});
      slog::Relation* readrel462 = db->getRelation("delta");
      deltaindex428 = readrel462->getIndex(ord461, false);
      std::vector<u16> ord463({1, 0});
      slog::Relation* readrel464 = db->getRelation("_enum");
      _enumindex429 = readrel464->getIndex(ord463, false);
  
    }
    ReadTask434(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c104 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c105 = v_const06abaa100ecef791ce028c56;
      u64 v_c106 = v_constd4735e3a265e16eee03f5971;
      u64 v_c107 = v_const5feceb66ffc86f38d952786c;
      u64 v_c108 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c109 = v_const5feceb66ffc86f38d952786c;
      u64 v_c110 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c111 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c112 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c113 = _t[0];
        u64 v_c97 = _t[1];
        if (!slog::exists_probe<3,2>($seq_atindex419, std::array<u64,3>{v_c110, v_c113, 0})) return;
        if (!slog::exists_probe<3,2>($seq_atrindex420, std::array<u64,3>{v_c111, v_c113, 0})) return;
        if (!slog::exists_probe<3,2>($seq_atrindex421, std::array<u64,3>{v_c112, v_c113, 0})) return;
        if (!slog::exists_probe<3,1>(deltaindex422, std::array<u64,3>{v_c105, 0, 0})) return;
        if (!slog::exists_probe<2,1>(_enumindex423, std::array<u64,2>{v_c104, 0})) return;
        slog::join_probe_old<3,2>($seq_atindex424, $seq_atdelta430, std::array<u64,3>{v_c109, v_c113, 0}, [&](const std::array<u64,3>& m465) {
          u64 v_c40 = m465[2];
          slog::join_probe_old<3,3>($seq_atindex425, $seq_atdelta431, std::array<u64,3>{v_c110, v_c113, v_c40}, [&](const std::array<u64,3>& m466) {
            slog::join_probe_old<3,3>($seq_atrindex426, $seq_atrdelta432, std::array<u64,3>{v_c111, v_c113, v_c40}, [&](const std::array<u64,3>& m467) {
              slog::join_probe_old<3,3>($seq_atrindex427, $seq_atrdelta433, std::array<u64,3>{v_c112, v_c113, v_c40}, [&](const std::array<u64,3>& m468) {
                slog::join_probe<3,2>(deltaindex428, std::array<u64,3>{v_c105, v_c40, 0}, [&](const std::array<u64,3>& m469) {
                  u64 v_c114 = m469[2];
                  slog::join_probe<2,1>(_enumindex429, std::array<u64,2>{v_c104, 0}, [&](const std::array<u64,2>& m470) {
                    u64 v_c115 = m470[1];
                    bool ok471 = true;
                    u64 v_c116 = _prim_aslst(db, v_c40, &ok471);
                    if (!ok471) return;
                    u64 v_c117 = _prim_llen(db, v_c116);
                    if (v_c117 == slog_error) { slog::emit_pending_error(db, "interp.slog:121"); return; }
                    if (v_c106 != v_c117) return;
                    bool ok472 = true;
                    u64 v_c118 = _prim_lref(db, v_c116, v_c107, &ok472);
                    if (!ok472) return;
                    if (v_c113 != v_c118) return;
                    bool ok473 = true;
                    u64 v_c119 = _prim_lref(db, v_c116, v_c108, &ok473);
                    if (!ok473) return;
                    if (v_c113 != v_c119) return;
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c114});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c115}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:121", "delta:symval", _fires);
  
      if (!_done)
      {
        ReadTask434* _cont = new ReadTask434(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask434(db,b), false);
  // (crule (pre (let __tconst1XIR1130 constd01925b37634a1a9d24159d8)) (scan mp_bld __t4AuA805 p m __t8d7K804 r) (body (join _enum (0 1) 2 __t8d7K804 __tconst1XIR1130)) (head (emit mp_bld_ans (0 1) __t4AuA805 r)) map.slog:73 #f)
  class ReadTask475 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex474;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_bld_ans");
      std::vector<u16> ord476({0, 1});
      slog::Relation* readrel477 = db->getRelation("mp_bld_ans");
      head_index[0] = readrel477->getIndex(ord476, false);
      outer_rel = db->getRelation("mp_bld");
      std::vector<u16> ord478({0, 1});
      slog::Relation* readrel479 = db->getRelation("_enum");
      _enumindex474 = readrel479->getIndex(ord478, false);
  
    }
    ReadTask475(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c120 = v_constd01925b37634a1a9d24159d8;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c121 = _t[0];
        u64 v_c56 = _t[1];
        u64 v_c59 = _t[2];
        u64 v_c122 = _t[3];
        u64 v_c24 = _t[4];
        slog::join_probe<2,2>(_enumindex474, std::array<u64,2>{v_c122, v_c120}, [&](const std::array<u64,2>& m480) {
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c121, v_c24}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:73", "delta:mp_bld", _fires);
  
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
  // (crule (pre (let __tconst35Xg1071 const0122baa3ac55f1b433944eb1) (let __tconst3u5R106 const06abaa100ecef791ce028c56) (let _00024sqc9bdu903 constd4735e3a265e16eee03f5971) (let _00024sqc9U0q904 const5feceb66ffc86f38d952786c) (let _00024sqc3xmn905 const6b86b273ff34fce19d6b804e) (let _00024sqo7aO7906 const5feceb66ffc86f38d952786c) (let _00024sqo8pFe907 const6b86b273ff34fce19d6b804e) (let _00024sqo3hRp908 const6b86b273ff34fce19d6b804e) (let _00024sqo4hee909 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo7aO7906 __t5IbK109 _00024seq2) (body (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo8pFe907 __t5IbK109 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo3hRp908 __t5IbK109 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo4hee909 __t5IbK109 _00024seq2) (exists _enum (1 0) 1 __tconst35Xg1071) (join delta (1 2 0) 2 __tconst3u5R106 _00024seq2 __t8l3B107) (join _enum (1 0) 1 __tconst35Xg1071 __t6gQ5104) (join boolval (0 1) 1 __t5IbK109 b) (letp _00024sql6c1M901 (aslst _00024seq2)) (let chk4EP21961 (llen _00024sql6c1M901)) (eq _00024sqc9bdu903 chk4EP21961) (letp chk0Oc01962 (lref _00024sql6c1M901 _00024sqc9U0q904)) (eq __t5IbK109 chk0Oc01962) (letp chk9k3L1963 (lref _00024sql6c1M901 _00024sqc3xmn905)) (eq __t5IbK109 chk9k3L1963)) (head (emit-temp temp1yql1955 __t8l3B107) (mkstruct boolval (1 0) __t274c105 __t6gQ5104)) interp.slog:122 #f)
  class ReadTask491 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex481;  slog::Index** $seq_atrindex482;  slog::Index** $seq_atrindex483;  slog::Index** _enumindex484;  slog::Index** deltaindex485;  slog::Index** _enumindex486;  slog::Index** boolvalindex487;  slog::Index** $seq_atdelta488;  slog::Index** $seq_atrdelta489;  slog::Index** $seq_atrdelta490;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp1yql1955");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord492({1, 0, 2});
      slog::Relation* readrel493 = db->getRelation("$seq_at");
      driver_index = readrel493->getIndex(ord492, true);
      std::vector<u16> ord494({1, 0, 2});
      slog::Relation* readrel495 = db->getRelation("$seq_at");
      $seq_atindex481 = readrel495->getIndex(ord494, false);
      std::vector<u16> ord496({1, 0, 2});
      slog::Relation* readrel497 = db->getRelation("$seq_at");
      $seq_atdelta488 = readrel497->getIndex(ord496, true);
      std::vector<u16> ord498({1, 0, 2});
      slog::Relation* readrel499 = db->getRelation("$seq_atr");
      $seq_atrindex482 = readrel499->getIndex(ord498, false);
      std::vector<u16> ord500({1, 0, 2});
      slog::Relation* readrel501 = db->getRelation("$seq_atr");
      $seq_atrdelta489 = readrel501->getIndex(ord500, true);
      std::vector<u16> ord502({1, 0, 2});
      slog::Relation* readrel503 = db->getRelation("$seq_atr");
      $seq_atrindex483 = readrel503->getIndex(ord502, false);
      std::vector<u16> ord504({1, 0, 2});
      slog::Relation* readrel505 = db->getRelation("$seq_atr");
      $seq_atrdelta490 = readrel505->getIndex(ord504, true);
      std::vector<u16> ord506({1, 0});
      slog::Relation* readrel507 = db->getRelation("_enum");
      _enumindex484 = readrel507->getIndex(ord506, false);
      std::vector<u16> ord508({1, 2, 0});
      slog::Relation* readrel509 = db->getRelation("delta");
      deltaindex485 = readrel509->getIndex(ord508, false);
      std::vector<u16> ord510({1, 0});
      slog::Relation* readrel511 = db->getRelation("_enum");
      _enumindex486 = readrel511->getIndex(ord510, false);
      std::vector<u16> ord512({0, 1});
      slog::Relation* readrel513 = db->getRelation("boolval");
      boolvalindex487 = readrel513->getIndex(ord512, false);
  
    }
    ReadTask491(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c123 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c124 = v_const06abaa100ecef791ce028c56;
      u64 v_c125 = v_constd4735e3a265e16eee03f5971;
      u64 v_c126 = v_const5feceb66ffc86f38d952786c;
      u64 v_c127 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c128 = v_const5feceb66ffc86f38d952786c;
      u64 v_c129 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c130 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c131 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c128, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m514) {
        u64 v_c132 = m514[1];
        u64 v_c40 = m514[2];
        if (buckethash(v_c132) != bucket) return;
        slog::join_probe_old<3,3>($seq_atindex481, $seq_atdelta488, std::array<u64,3>{v_c129, v_c132, v_c40}, [&](const std::array<u64,3>& m515) {
          slog::join_probe_old<3,3>($seq_atrindex482, $seq_atrdelta489, std::array<u64,3>{v_c130, v_c132, v_c40}, [&](const std::array<u64,3>& m516) {
            slog::join_probe_old<3,3>($seq_atrindex483, $seq_atrdelta490, std::array<u64,3>{v_c131, v_c132, v_c40}, [&](const std::array<u64,3>& m517) {
              if (!slog::exists_probe<2,1>(_enumindex484, std::array<u64,2>{v_c123, 0})) return;
              slog::join_probe<3,2>(deltaindex485, std::array<u64,3>{v_c124, v_c40, 0}, [&](const std::array<u64,3>& m518) {
                u64 v_c133 = m518[2];
                slog::join_probe<2,1>(_enumindex486, std::array<u64,2>{v_c123, 0}, [&](const std::array<u64,2>& m519) {
                  u64 v_c134 = m519[1];
                  slog::join_probe<2,1>(boolvalindex487, std::array<u64,2>{v_c132, 0}, [&](const std::array<u64,2>& m520) {
                    u64 v_c44 = m520[1];
                    bool ok521 = true;
                    u64 v_c135 = _prim_aslst(db, v_c40, &ok521);
                    if (!ok521) return;
                    u64 v_c136 = _prim_llen(db, v_c135);
                    if (v_c136 == slog_error) { slog::emit_pending_error(db, "interp.slog:122"); return; }
                    if (v_c125 != v_c136) return;
                    bool ok522 = true;
                    u64 v_c137 = _prim_lref(db, v_c135, v_c126, &ok522);
                    if (!ok522) return;
                    if (v_c132 != v_c137) return;
                    bool ok523 = true;
                    u64 v_c138 = _prim_lref(db, v_c135, v_c127, &ok523);
                    if (!ok523) return;
                    if (v_c132 != v_c138) return;
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c133});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c134}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:122", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask491* _cont = new ReadTask491(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask491(db,b), false);
  // (crule (pre (let __tconst8WcI1085 const0122baa3ac55f1b433944eb1) (let __tconst9cNI595 const06abaa100ecef791ce028c56) (let _00024sqc696g1041 constd4735e3a265e16eee03f5971) (let _00024sqc3XnD1042 const5feceb66ffc86f38d952786c) (let _00024sqc4UkF1043 const6b86b273ff34fce19d6b804e) (let _00024sqo05pe1044 const5feceb66ffc86f38d952786c) (let _00024sqo5XjX1045 const6b86b273ff34fce19d6b804e) (let _00024sqo0BYf1046 const6b86b273ff34fce19d6b804e) (let _00024sqo9pUp1047 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo05pe1044 __t7ye2598 _00024seq2) (body (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo5XjX1045 __t7ye2598 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo0BYf1046 __t7ye2598 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo9pUp1047 __t7ye2598 _00024seq2) (exists _enum (1 0) 1 __tconst8WcI1085) (join delta (1 2 0) 2 __tconst9cNI595 _00024seq2 __t0WVv596) (join _enum (1 0) 1 __tconst8WcI1085 __t8vy6593) (join symval (0 1) 1 __t7ye2598 s) (letp _00024sql2mO51039 (aslst _00024seq2)) (let chk4vIa2018 (llen _00024sql2mO51039)) (eq _00024sqc696g1041 chk4vIa2018) (letp chk3uve2019 (lref _00024sql2mO51039 _00024sqc3XnD1042)) (eq __t7ye2598 chk3uve2019) (letp chk40EG2020 (lref _00024sql2mO51039 _00024sqc4UkF1043)) (eq __t7ye2598 chk40EG2020)) (head (emit-temp temp7W0m2012 __t0WVv596) (mkstruct boolval (1 0) __t17ui594 __t8vy6593)) interp.slog:121 #f)
  class ReadTask534 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex524;  slog::Index** $seq_atrindex525;  slog::Index** $seq_atrindex526;  slog::Index** _enumindex527;  slog::Index** deltaindex528;  slog::Index** _enumindex529;  slog::Index** symvalindex530;  slog::Index** $seq_atdelta531;  slog::Index** $seq_atrdelta532;  slog::Index** $seq_atrdelta533;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7W0m2012");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord535({1, 0, 2});
      slog::Relation* readrel536 = db->getRelation("$seq_at");
      driver_index = readrel536->getIndex(ord535, true);
      std::vector<u16> ord537({1, 0, 2});
      slog::Relation* readrel538 = db->getRelation("$seq_at");
      $seq_atindex524 = readrel538->getIndex(ord537, false);
      std::vector<u16> ord539({1, 0, 2});
      slog::Relation* readrel540 = db->getRelation("$seq_at");
      $seq_atdelta531 = readrel540->getIndex(ord539, true);
      std::vector<u16> ord541({1, 0, 2});
      slog::Relation* readrel542 = db->getRelation("$seq_atr");
      $seq_atrindex525 = readrel542->getIndex(ord541, false);
      std::vector<u16> ord543({1, 0, 2});
      slog::Relation* readrel544 = db->getRelation("$seq_atr");
      $seq_atrdelta532 = readrel544->getIndex(ord543, true);
      std::vector<u16> ord545({1, 0, 2});
      slog::Relation* readrel546 = db->getRelation("$seq_atr");
      $seq_atrindex526 = readrel546->getIndex(ord545, false);
      std::vector<u16> ord547({1, 0, 2});
      slog::Relation* readrel548 = db->getRelation("$seq_atr");
      $seq_atrdelta533 = readrel548->getIndex(ord547, true);
      std::vector<u16> ord549({1, 0});
      slog::Relation* readrel550 = db->getRelation("_enum");
      _enumindex527 = readrel550->getIndex(ord549, false);
      std::vector<u16> ord551({1, 2, 0});
      slog::Relation* readrel552 = db->getRelation("delta");
      deltaindex528 = readrel552->getIndex(ord551, false);
      std::vector<u16> ord553({1, 0});
      slog::Relation* readrel554 = db->getRelation("_enum");
      _enumindex529 = readrel554->getIndex(ord553, false);
      std::vector<u16> ord555({0, 1});
      slog::Relation* readrel556 = db->getRelation("symval");
      symvalindex530 = readrel556->getIndex(ord555, false);
  
    }
    ReadTask534(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c104 = v_const0122baa3ac55f1b433944eb1;
      u64 v_c105 = v_const06abaa100ecef791ce028c56;
      u64 v_c106 = v_constd4735e3a265e16eee03f5971;
      u64 v_c107 = v_const5feceb66ffc86f38d952786c;
      u64 v_c108 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c109 = v_const5feceb66ffc86f38d952786c;
      u64 v_c110 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c111 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c112 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c109, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m557) {
        u64 v_c113 = m557[1];
        u64 v_c40 = m557[2];
        if (buckethash(v_c113) != bucket) return;
        slog::join_probe_old<3,3>($seq_atindex524, $seq_atdelta531, std::array<u64,3>{v_c110, v_c113, v_c40}, [&](const std::array<u64,3>& m558) {
          slog::join_probe_old<3,3>($seq_atrindex525, $seq_atrdelta532, std::array<u64,3>{v_c111, v_c113, v_c40}, [&](const std::array<u64,3>& m559) {
            slog::join_probe_old<3,3>($seq_atrindex526, $seq_atrdelta533, std::array<u64,3>{v_c112, v_c113, v_c40}, [&](const std::array<u64,3>& m560) {
              if (!slog::exists_probe<2,1>(_enumindex527, std::array<u64,2>{v_c104, 0})) return;
              slog::join_probe<3,2>(deltaindex528, std::array<u64,3>{v_c105, v_c40, 0}, [&](const std::array<u64,3>& m561) {
                u64 v_c114 = m561[2];
                slog::join_probe<2,1>(_enumindex529, std::array<u64,2>{v_c104, 0}, [&](const std::array<u64,2>& m562) {
                  u64 v_c115 = m562[1];
                  slog::join_probe<2,1>(symvalindex530, std::array<u64,2>{v_c113, 0}, [&](const std::array<u64,2>& m563) {
                    u64 v_c97 = m563[1];
                    bool ok564 = true;
                    u64 v_c116 = _prim_aslst(db, v_c40, &ok564);
                    if (!ok564) return;
                    u64 v_c139 = _prim_llen(db, v_c116);
                    if (v_c139 == slog_error) { slog::emit_pending_error(db, "interp.slog:121"); return; }
                    if (v_c106 != v_c139) return;
                    bool ok565 = true;
                    u64 v_c140 = _prim_lref(db, v_c116, v_c107, &ok565);
                    if (!ok565) return;
                    if (v_c113 != v_c140) return;
                    bool ok566 = true;
                    u64 v_c141 = _prim_lref(db, v_c116, v_c108, &ok566);
                    if (!ok566) return;
                    if (v_c113 != v_c141) return;
                    ++_fires;
                    slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c114});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c115}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:121", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask534* _cont = new ReadTask534(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask534(db,b), false);
  // (crule (pre (let __trid46f71539 consta22c7bfa7abc2d7d387fd7df) (let __trel4X8o1540 const1064263932db82f2cf6d4ac2) (let __tcol7P7i1541 const5feceb66ffc86f38d952786c) (let __trel0ujM1542 const1064263932db82f2cf6d4ac2) (let __tcol0vjf1543 const6b86b273ff34fce19d6b804e)) (scan $sup5638x42x0x0x1 __d0 __d1 k l m p r v) (body) (head (tycheck r (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid46f71539 __trel4X8o1540 __tcol7P7i1541 (1 2 3 4 0)) (tycheck k (accept int) __trid46f71539 __trel0ujM1542 __tcol0vjf1543 (1 2 3 4 0)) (mkstruct mp_put (1 2 3 0) __0Kwz1538 r k v)) map.slog:43 #f)
  class ReadTask570 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid568;  u32 sid567;  u32 sid569;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("mp_put");
      outer_rel = db->getRelation("$sup5638x42x0x0x1");
      sid568 = db->getRelation("_enum")->getStructId();
      sid567 = db->getRelation("mbranch")->getStructId();
      sid569 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask570(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c142 = v_consta22c7bfa7abc2d7d387fd7df;
      u64 v_c143 = v_const1064263932db82f2cf6d4ac2;
      u64 v_c144 = v_const5feceb66ffc86f38d952786c;
      u64 v_c145 = v_const1064263932db82f2cf6d4ac2;
      u64 v_c146 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c7 = _t[0];
        u64 v_c147 = _t[1];
        u64 v_c25 = _t[2];
        u64 v_c58 = _t[3];
        u64 v_c59 = _t[4];
        u64 v_c56 = _t[5];
        u64 v_c24 = _t[6];
        u64 v_c22 = _t[7];
        ++_fires;
        if (!((is_struct(v_c24) && (decode_struct_id(v_c24) == sid567 || decode_struct_id(v_c24) == sid568 || decode_struct_id(v_c24) == sid569))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c142, v_c143, v_c144, v_c24}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c25)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c142, v_c145, v_c146, v_c25}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<4>(head_rel[2], newbatch[2], std::array<u64,3>{v_c24, v_c25, v_c22}, std::array<u16,4>{1, 2, 3, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:43", "delta:$sup5638x42x0x0x1", _fires);
  
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
  // (crule (pre (let _00024sqc250U943 const6b86b273ff34fce19d6b804e) (let _00024sqc6BYS944 const5feceb66ffc86f38d952786c) (let _00024sqc0VjW945 const6b86b273ff34fce19d6b804e) (let _00024sqc8uew946 const5feceb66ffc86f38d952786c) (let _00024sqo2y2x951 const5feceb66ffc86f38d952786c) (let __t6qtm791 (lempty))) (scan eval_args_ans __t9m2L796 __v1) (body (join-old $seq_at (1 0 2) 1 (1 0 2) _00024sqo2y2x951 e _00024seq0) (letp _00024sql7raK941 (aslst _00024seq0)) (let _00024sqn1wbQ942 (llen _00024sql7raK941)) (cmp ge _00024sqn1wbQ942 _00024sqc250U943) (let _00024sqp9fgp947 (_0002d _00024sqn1wbQ942 _00024sqc8uew946)) (let es (lslice _00024sql7raK941 _00024sqc0VjW945 _00024sqp9fgp947)) (exists eval_args (1 3 2 0) 1 _00024seq0) (exists eval_args (0 1 2 3) 2 __t9m2L796 es) (exists eval (1 2 3 0) 1 e) (join-old $sup70016x43x0x0x0 (0 2 3 4 5 1) 3 (0 2 3 4 5 1) _00024seq0 e es rho t __t7ZV0794) (join-old eval_args (3 2 0 1) 4 (3 2 0 1) t rho __t7ZV0794 _00024seq0) (join-old eval_args (3 2 0 1) 4 (3 2 0 1) t rho __t9m2L796 es) (join-old eval (1 2 3 0) 3 (1 2 3 0) e rho t __t7vCW795) (join eval_ans (0 1) 1 __t7vCW795 __v0) (letp chk9Pp32037 (lref _00024sql7raK941 _00024sqc6BYS944)) (eq e chk9Pp32037)) (head (emit-temp temp2swd2033 __t6qtm791 __t7ZV0794 __v0 __v1)) interp.slog:44 #f)
  class ReadTask585 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $seq_atindex571;  slog::Index** eval_argsindex572;  slog::Index** eval_argsindex573;  slog::Index** evalindex574;  slog::Index** $sup70016x43x0x0x0index575;  slog::Index** eval_argsindex576;  slog::Index** eval_argsindex577;  slog::Index** evalindex578;  slog::Index** eval_ansindex579;  slog::Index** $seq_atdelta580;  slog::Index** $sup70016x43x0x0x0delta581;  slog::Index** eval_argsdelta582;  slog::Index** eval_argsdelta583;  slog::Index** evaldelta584;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp2swd2033");
      outer_rel = db->getRelation("eval_args_ans");
      std::vector<u16> ord586({1, 0, 2});
      slog::Relation* readrel587 = db->getRelation("$seq_at");
      $seq_atindex571 = readrel587->getIndex(ord586, false);
      std::vector<u16> ord588({1, 0, 2});
      slog::Relation* readrel589 = db->getRelation("$seq_at");
      $seq_atdelta580 = readrel589->getIndex(ord588, true);
      std::vector<u16> ord590({1, 3, 2, 0});
      slog::Relation* readrel591 = db->getRelation("eval_args");
      eval_argsindex572 = readrel591->getIndex(ord590, false);
      std::vector<u16> ord592({0, 1, 2, 3});
      slog::Relation* readrel593 = db->getRelation("eval_args");
      eval_argsindex573 = readrel593->getIndex(ord592, false);
      std::vector<u16> ord594({1, 2, 3, 0});
      slog::Relation* readrel595 = db->getRelation("eval");
      evalindex574 = readrel595->getIndex(ord594, false);
      std::vector<u16> ord596({0, 2, 3, 4, 5, 1});
      slog::Relation* readrel597 = db->getRelation("$sup70016x43x0x0x0");
      $sup70016x43x0x0x0index575 = readrel597->getIndex(ord596, false);
      std::vector<u16> ord598({0, 2, 3, 4, 5, 1});
      slog::Relation* readrel599 = db->getRelation("$sup70016x43x0x0x0");
      $sup70016x43x0x0x0delta581 = readrel599->getIndex(ord598, true);
      std::vector<u16> ord600({3, 2, 0, 1});
      slog::Relation* readrel601 = db->getRelation("eval_args");
      eval_argsindex576 = readrel601->getIndex(ord600, false);
      std::vector<u16> ord602({3, 2, 0, 1});
      slog::Relation* readrel603 = db->getRelation("eval_args");
      eval_argsdelta582 = readrel603->getIndex(ord602, true);
      std::vector<u16> ord604({3, 2, 0, 1});
      slog::Relation* readrel605 = db->getRelation("eval_args");
      eval_argsindex577 = readrel605->getIndex(ord604, false);
      std::vector<u16> ord606({3, 2, 0, 1});
      slog::Relation* readrel607 = db->getRelation("eval_args");
      eval_argsdelta583 = readrel607->getIndex(ord606, true);
      std::vector<u16> ord608({1, 2, 3, 0});
      slog::Relation* readrel609 = db->getRelation("eval");
      evalindex578 = readrel609->getIndex(ord608, false);
      std::vector<u16> ord610({1, 2, 3, 0});
      slog::Relation* readrel611 = db->getRelation("eval");
      evaldelta584 = readrel611->getIndex(ord610, true);
      std::vector<u16> ord612({0, 1});
      slog::Relation* readrel613 = db->getRelation("eval_ans");
      eval_ansindex579 = readrel613->getIndex(ord612, false);
  
    }
    ReadTask585(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c148 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c149 = v_const5feceb66ffc86f38d952786c;
      u64 v_c150 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c151 = v_const5feceb66ffc86f38d952786c;
      u64 v_c152 = v_const5feceb66ffc86f38d952786c;
      u64 v_c153 = _prim_lempty(db);
      if (v_c153 == slog_error) { slog::emit_pending_error(db, "interp.slog:44"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c154 = _t[0];
        u64 v_c84 = _t[1];
        slog::join_probe_old<3,1>($seq_atindex571, $seq_atdelta580, std::array<u64,3>{v_c152, 0, 0}, [&](const std::array<u64,3>& m614) {
          u64 v_c155 = m614[1]; u64 v_c156 = m614[2];
          bool ok615 = true;
          u64 v_c157 = _prim_aslst(db, v_c156, &ok615);
          if (!ok615) return;
          u64 v_c158 = _prim_llen(db, v_c157);
          if (v_c158 == slog_error) { slog::emit_pending_error(db, "interp.slog:44"); return; }
          u64 v_c159 = _prim_ge(db, v_c158, v_c148);
          if (v_c159 == slog_error) { slog::emit_pending_error(db, "interp.slog:44"); return; }
          if (!v_c159) return;
          u64 v_c160 = _prim__0002d(db, v_c158, v_c151);
          if (v_c160 == slog_error) { slog::emit_pending_error(db, "interp.slog:44"); return; }
          u64 v_c9 = _prim_lslice(db, v_c157, v_c150, v_c160);
          if (v_c9 == slog_error) { slog::emit_pending_error(db, "interp.slog:44"); return; }
          if (!slog::exists_probe<4,1>(eval_argsindex572, std::array<u64,4>{v_c156, 0, 0, 0})) return;
          if (!slog::exists_probe<4,2>(eval_argsindex573, std::array<u64,4>{v_c154, v_c9, 0, 0})) return;
          if (!slog::exists_probe<4,1>(evalindex574, std::array<u64,4>{v_c155, 0, 0, 0})) return;
          slog::join_probe_old<6,3>($sup70016x43x0x0x0index575, $sup70016x43x0x0x0delta581, std::array<u64,6>{v_c156, v_c155, v_c9, 0, 0, 0}, [&](const std::array<u64,6>& m617) {
            u64 v_c10 = m617[3]; u64 v_c11 = m617[4]; u64 v_c161 = m617[5];
            slog::join_probe_old<4,4>(eval_argsindex576, eval_argsdelta582, std::array<u64,4>{v_c11, v_c10, v_c161, v_c156}, [&](const std::array<u64,4>& m618) {
              slog::join_probe_old<4,4>(eval_argsindex577, eval_argsdelta583, std::array<u64,4>{v_c11, v_c10, v_c154, v_c9}, [&](const std::array<u64,4>& m619) {
                slog::join_probe_old<4,3>(evalindex578, evaldelta584, std::array<u64,4>{v_c155, v_c10, v_c11, 0}, [&](const std::array<u64,4>& m620) {
                  u64 v_c162 = m620[3];
                  slog::join_probe<2,1>(eval_ansindex579, std::array<u64,2>{v_c162, 0}, [&](const std::array<u64,2>& m621) {
                    u64 v_c51 = m621[1];
                    bool ok622 = true;
                    u64 v_c163 = _prim_lref(db, v_c157, v_c149, &ok622);
                    if (!ok622) return;
                    if (v_c155 != v_c163) return;
                    ++_fires;
                    slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c153, v_c161, v_c51, v_c84});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:44", "delta:eval_args_ans", _fires);
  
      if (!_done)
      {
        ReadTask585* _cont = new ReadTask585(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask585(db,b), false);
  // (crule (pre) (scan mp_put_soft __t4JSX768 t k v) (body) (head (emit $sup5638x67x0x0x0 (1 2 0 3) k t __t4JSX768 v)) map.slog:68 #f)
  class ReadTask623 : public slog::Task
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
      head_rel[0] = db->getRelation("$sup5638x67x0x0x0");
      std::vector<u16> ord624({1, 2, 0, 3});
      slog::Relation* readrel625 = db->getRelation("$sup5638x67x0x0x0");
      head_index[0] = readrel625->getIndex(ord624, false);
      outer_rel = db->getRelation("mp_put_soft");
  
    }
    ReadTask623(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c25 = _t[2];
        u64 v_c22 = _t[3];
        ++_fires;
        slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c25, v_c11, v_c164, v_c22}, std::array<u16,4>{1, 2, 0, 3});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:68", "delta:mp_put_soft", _fires);
  
      if (!_done)
      {
        ReadTask623* _cont = new ReadTask623(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask623(db,b), false);
  // (crule (pre) (scan temp636D1974 __t8K90240 __v0 m p r) (body (join mbranch (1 2 3 4 0) 4 p m __v0 r __t2hPi238)) (head (emit mp_put_ans (0 1) __t8K90240 __t2hPi238)) map.slog:41 #f)
  class ReadTask627 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex626;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_ans");
      std::vector<u16> ord628({0, 1});
      slog::Relation* readrel629 = db->getRelation("mp_put_ans");
      head_index[0] = readrel629->getIndex(ord628, false);
      outer_rel = db->getRelation("temp636D1974");
      std::vector<u16> ord630({1, 2, 3, 4, 0});
      slog::Relation* readrel631 = db->getRelation("mbranch");
      mbranchindex626 = readrel631->getIndex(ord630, false);
  
    }
    ReadTask627(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c165 = _t[0];
        u64 v_c51 = _t[1];
        u64 v_c59 = _t[2];
        u64 v_c56 = _t[3];
        u64 v_c24 = _t[4];
        slog::join_probe<5,4>(mbranchindex626, std::array<u64,5>{v_c56, v_c59, v_c51, v_c24, 0}, [&](const std::array<u64,5>& m632) {
          u64 v_c166 = m632[4];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c165, v_c166}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:41", "delta:temp636D1974", _fires);
  
      if (!_done)
      {
        ReadTask627* _cont = new ReadTask627(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask627(db,b), false);
  // (crule (pre (let __tconst7oJb145 const6b86b273ff34fce19d6b804e)) (scan mp_msk __t7PVf147 p n) (body (exists $sup5638x104x0x0x0 (3 4 5 0 1 2 6 7 8) 2 n p) (exists mbranch (2 0 1 3 4) 1 n) (exists mbranch (1 2 3 4 0) 1 p) (exists mp_msk_ans (0 1) 1 __t7PVf147) (join $sup5638x104x0x0x1 (1 4 5 6 0 2 3 7 8 9) 3 __t7PVf147 n p q __t0kfV144 l m r u v) (cmp lt m n) (join $sup5638x104x0x0x0 (5 3 7 8 0 1 2 4 6) 9 q n u v __t0kfV144 l m p r) (exists mbranch (1 2 3 4 0) 4 p m l r) (exists mp_msk_ans (0 1) 2 __t7PVf147 q) (exists mp_union (2 0 1) 1 u) (join mbranch (1 2 3 4 0) 4 q n u v __t2NO6142) (exists mp_union (2 0 1) 2 __t2NO6142 __t0kfV144) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t5mfE148) (join mp_union (0 1 2) 3 __t0kfV144 __t5mfE148 __t2NO6142) (join mp_msk_ans (0 1) 2 __t7PVf147 q) (join-old mp_union (1 2 0) 2 (1 2 0) __t5mfE148 u __t221b149) (join mp_union_ans (0 1) 1 __t221b149 __v0) (let __t5ygO146 (band p n)) (cmp lt __t5ygO146 __tconst7oJb145)) (head (emit-temp temp9IEi1871 __t0kfV144 __v0 n q v) (mkstruct mbranch (1 2 3 4 0) __t4DAr141 q n __v0 v)) map.slog:105 #f)
  class ReadTask651 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x104x0x0x0index633;  slog::Index** mbranchindex634;  slog::Index** mbranchindex635;  slog::Index** mp_msk_ansindex636;  slog::Index** $sup5638x104x0x0x1index637;  slog::Index** $sup5638x104x0x0x0index638;  slog::Index** mbranchindex639;  slog::Index** mp_msk_ansindex640;  slog::Index** mp_unionindex641;  slog::Index** mbranchindex642;  slog::Index** mp_unionindex643;  slog::Index** mbranchindex644;  slog::Index** mp_unionindex645;  slog::Index** mp_msk_ansindex646;  slog::Index** mp_unionindex647;  slog::Index** mp_union_ansindex648;  slog::Index** mbranchdelta649;  slog::Index** mp_uniondelta650;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9IEi1871");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_msk");
      std::vector<u16> ord652({3, 4, 5, 0, 1, 2, 6, 7, 8});
      slog::Relation* readrel653 = db->getRelation("$sup5638x104x0x0x0");
      $sup5638x104x0x0x0index633 = readrel653->getIndex(ord652, false);
      std::vector<u16> ord654({2, 0, 1, 3, 4});
      slog::Relation* readrel655 = db->getRelation("mbranch");
      mbranchindex634 = readrel655->getIndex(ord654, false);
      std::vector<u16> ord656({1, 2, 3, 4, 0});
      slog::Relation* readrel657 = db->getRelation("mbranch");
      mbranchindex635 = readrel657->getIndex(ord656, false);
      std::vector<u16> ord658({0, 1});
      slog::Relation* readrel659 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex636 = readrel659->getIndex(ord658, false);
      std::vector<u16> ord660({1, 4, 5, 6, 0, 2, 3, 7, 8, 9});
      slog::Relation* readrel661 = db->getRelation("$sup5638x104x0x0x1");
      $sup5638x104x0x0x1index637 = readrel661->getIndex(ord660, false);
      std::vector<u16> ord662({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel663 = db->getRelation("$sup5638x104x0x0x0");
      $sup5638x104x0x0x0index638 = readrel663->getIndex(ord662, false);
      std::vector<u16> ord664({1, 2, 3, 4, 0});
      slog::Relation* readrel665 = db->getRelation("mbranch");
      mbranchindex639 = readrel665->getIndex(ord664, false);
      std::vector<u16> ord666({0, 1});
      slog::Relation* readrel667 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex640 = readrel667->getIndex(ord666, false);
      std::vector<u16> ord668({2, 0, 1});
      slog::Relation* readrel669 = db->getRelation("mp_union");
      mp_unionindex641 = readrel669->getIndex(ord668, false);
      std::vector<u16> ord670({1, 2, 3, 4, 0});
      slog::Relation* readrel671 = db->getRelation("mbranch");
      mbranchindex642 = readrel671->getIndex(ord670, false);
      std::vector<u16> ord672({2, 0, 1});
      slog::Relation* readrel673 = db->getRelation("mp_union");
      mp_unionindex643 = readrel673->getIndex(ord672, false);
      std::vector<u16> ord674({1, 2, 3, 4, 0});
      slog::Relation* readrel675 = db->getRelation("mbranch");
      mbranchindex644 = readrel675->getIndex(ord674, false);
      std::vector<u16> ord676({1, 2, 3, 4, 0});
      slog::Relation* readrel677 = db->getRelation("mbranch");
      mbranchdelta649 = readrel677->getIndex(ord676, true);
      std::vector<u16> ord678({0, 1, 2});
      slog::Relation* readrel679 = db->getRelation("mp_union");
      mp_unionindex645 = readrel679->getIndex(ord678, false);
      std::vector<u16> ord680({0, 1});
      slog::Relation* readrel681 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex646 = readrel681->getIndex(ord680, false);
      std::vector<u16> ord682({1, 2, 0});
      slog::Relation* readrel683 = db->getRelation("mp_union");
      mp_unionindex647 = readrel683->getIndex(ord682, false);
      std::vector<u16> ord684({1, 2, 0});
      slog::Relation* readrel685 = db->getRelation("mp_union");
      mp_uniondelta650 = readrel685->getIndex(ord684, true);
      std::vector<u16> ord686({0, 1});
      slog::Relation* readrel687 = db->getRelation("mp_union_ans");
      mp_union_ansindex648 = readrel687->getIndex(ord686, false);
  
    }
    ReadTask651(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c56 = _t[1];
        u64 v_c57 = _t[2];
        if (!slog::exists_probe<9,2>($sup5638x104x0x0x0index633, std::array<u64,9>{v_c57, v_c56, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex634, std::array<u64,5>{v_c57, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex635, std::array<u64,5>{v_c56, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex636, std::array<u64,2>{v_c168, 0})) return;
        slog::join_probe<10,3>($sup5638x104x0x0x1index637, std::array<u64,10>{v_c168, v_c57, v_c56, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,10>& m688) {
          u64 v_c55 = m688[3]; u64 v_c169 = m688[4]; u64 v_c58 = m688[5]; u64 v_c59 = m688[6]; u64 v_c24 = m688[7]; u64 v_c60 = m688[8]; u64 v_c22 = m688[9];
          u64 v_c170 = _prim_lt(db, v_c59, v_c57);
          if (v_c170 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
          if (!v_c170) return;
          slog::join_probe<9,9>($sup5638x104x0x0x0index638, std::array<u64,9>{v_c55, v_c57, v_c60, v_c22, v_c169, v_c58, v_c59, v_c56, v_c24}, [&](const std::array<u64,9>& m690) {
            if (!slog::exists_probe<5,4>(mbranchindex639, std::array<u64,5>{v_c56, v_c59, v_c58, v_c24, 0})) return;
            if (!slog::exists_probe<2,2>(mp_msk_ansindex640, std::array<u64,2>{v_c168, v_c55})) return;
            if (!slog::exists_probe<3,1>(mp_unionindex641, std::array<u64,3>{v_c60, 0, 0})) return;
            slog::join_probe<5,4>(mbranchindex642, std::array<u64,5>{v_c55, v_c57, v_c60, v_c22, 0}, [&](const std::array<u64,5>& m691) {
              u64 v_c171 = m691[4];
              if (!slog::exists_probe<3,2>(mp_unionindex643, std::array<u64,3>{v_c171, v_c169, 0})) return;
              slog::join_probe_old<5,4>(mbranchindex644, mbranchdelta649, std::array<u64,5>{v_c56, v_c59, v_c58, v_c24, 0}, [&](const std::array<u64,5>& m692) {
                u64 v_c172 = m692[4];
                slog::join_probe<3,3>(mp_unionindex645, std::array<u64,3>{v_c169, v_c172, v_c171}, [&](const std::array<u64,3>& m693) {
                  slog::join_probe<2,2>(mp_msk_ansindex646, std::array<u64,2>{v_c168, v_c55}, [&](const std::array<u64,2>& m694) {
                    slog::join_probe_old<3,2>(mp_unionindex647, mp_uniondelta650, std::array<u64,3>{v_c172, v_c60, 0}, [&](const std::array<u64,3>& m695) {
                      u64 v_c173 = m695[2];
                      slog::join_probe<2,1>(mp_union_ansindex648, std::array<u64,2>{v_c173, 0}, [&](const std::array<u64,2>& m696) {
                        u64 v_c51 = m696[1];
                        u64 v_c174 = _prim_band(db, v_c56, v_c57);
                        if (v_c174 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
                        u64 v_c175 = _prim_lt(db, v_c174, v_c167);
                        if (v_c175 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
                        if (!v_c175) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c169, v_c51, v_c57, v_c55, v_c22});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c55, v_c57, v_c51, v_c22}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:105", "delta:mp_msk", _fires);
  
      if (!_done)
      {
        ReadTask651* _cont = new ReadTask651(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask651(db,b), false);
  // (crule (pre (let __trid8mAw1224 constb9a8f892254647859feb7453) (let __trel9Znd1225 const38c0e144c051f35df0684885) (let __tcol4PNo1226 const5feceb66ffc86f38d952786c) (let __trel2Z7a1227 const38c0e144c051f35df0684885) (let __tcol1oj71228 const6b86b273ff34fce19d6b804e)) (scan $sup70016x33x0x0x0 __d0 rho t x) (body) (head (tycheck x (accept int) __trid8mAw1224 __trel9Znd1225 __tcol4PNo1226 (1 2 3 4 0)) (tycheck rho (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid8mAw1224 __trel2Z7a1227 __tcol1oj71228 (1 2 3 4 0)) (mkstruct lookup (1 2 0) __06xI1223 x rho)) interp.slog:34 #f)
  class ReadTask701 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid699;  u32 sid698;  u32 sid700;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("lookup");
      outer_rel = db->getRelation("$sup70016x33x0x0x0");
      sid699 = db->getRelation("_enum")->getStructId();
      sid698 = db->getRelation("mbranch")->getStructId();
      sid700 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask701(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c176 = v_constb9a8f892254647859feb7453;
      u64 v_c177 = v_const38c0e144c051f35df0684885;
      u64 v_c178 = v_const5feceb66ffc86f38d952786c;
      u64 v_c179 = v_const38c0e144c051f35df0684885;
      u64 v_c180 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c7 = _t[0];
        u64 v_c10 = _t[1];
        u64 v_c11 = _t[2];
        u64 v_c16 = _t[3];
        ++_fires;
        if (!(is_int(v_c16)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c176, v_c177, v_c178, v_c16}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c10) && (decode_struct_id(v_c10) == sid698 || decode_struct_id(v_c10) == sid699 || decode_struct_id(v_c10) == sid700))))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c176, v_c179, v_c180, v_c10}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c16, v_c10}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("interp.slog:34", "delta:$sup70016x33x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask701* _cont = new ReadTask701(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask701(db,b), false);
  // (crule (pre (let __tconst0BLx640 constd4735e3a265e16eee03f5971)) (scan mp_msk __t8cgD644 k m) (body (let __t2Q40639 (_0002a __tconst0BLx640 m))) (head (emit-temp temp2Uly1937 __t2Q40639 __t8cgD644 k)) map.slog:22 #f)
  class ReadTask702 : public slog::Task
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
      head_rel[0] = db->getRelation("temp2Uly1937");
      outer_rel = db->getRelation("mp_msk");
  
    }
    ReadTask702(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c181 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c182 = _t[0];
        u64 v_c25 = _t[1];
        u64 v_c59 = _t[2];
        u64 v_c183 = _prim__0002a(db, v_c181, v_c59);
        if (v_c183 == slog_error) { slog::emit_pending_error(db, "map.slog:22"); return; }
        ++_fires;
        slog::emit_temp<3>(head_rel[0], newbatch[0], std::array<u64,3>{v_c183, v_c182, v_c25});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:22", "delta:mp_msk", _fires);
  
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
  // (crule (pre (let __tconst43q5382 const5feceb66ffc86f38d952786c)) (scan mp_get __t9K8V381 __t5bK8380 k) (body (exists mp_get (2 0 1) 1 k) (join $sup5638x52x0x0x0 (0 1 2 3 4 5) 2 __t9K8V381 k l m p r) (join mbranch (1 2 3 4 0) 5 p m l r __t5bK8380) (join-old mp_get (1 2 0) 2 (1 2 0) r k __t1KiE384) (join mp_get_ans (0 1) 1 __t1KiE384 v) (let __t0f7P383 (band k m)) (cmp gt __t0f7P383 __tconst43q5382)) (head (emit mp_get_ans (0 1) __t9K8V381 v)) map.slog:53 #f)
  class ReadTask709 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_getindex703;  slog::Index** $sup5638x52x0x0x0index704;  slog::Index** mbranchindex705;  slog::Index** mp_getindex706;  slog::Index** mp_get_ansindex707;  slog::Index** mp_getdelta708;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_get_ans");
      std::vector<u16> ord710({0, 1});
      slog::Relation* readrel711 = db->getRelation("mp_get_ans");
      head_index[0] = readrel711->getIndex(ord710, false);
      outer_rel = db->getRelation("mp_get");
      std::vector<u16> ord712({2, 0, 1});
      slog::Relation* readrel713 = db->getRelation("mp_get");
      mp_getindex703 = readrel713->getIndex(ord712, false);
      std::vector<u16> ord714({0, 1, 2, 3, 4, 5});
      slog::Relation* readrel715 = db->getRelation("$sup5638x52x0x0x0");
      $sup5638x52x0x0x0index704 = readrel715->getIndex(ord714, false);
      std::vector<u16> ord716({1, 2, 3, 4, 0});
      slog::Relation* readrel717 = db->getRelation("mbranch");
      mbranchindex705 = readrel717->getIndex(ord716, false);
      std::vector<u16> ord718({1, 2, 0});
      slog::Relation* readrel719 = db->getRelation("mp_get");
      mp_getindex706 = readrel719->getIndex(ord718, false);
      std::vector<u16> ord720({1, 2, 0});
      slog::Relation* readrel721 = db->getRelation("mp_get");
      mp_getdelta708 = readrel721->getIndex(ord720, true);
      std::vector<u16> ord722({0, 1});
      slog::Relation* readrel723 = db->getRelation("mp_get_ans");
      mp_get_ansindex707 = readrel723->getIndex(ord722, false);
  
    }
    ReadTask709(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c184 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c185 = _t[0];
        u64 v_c186 = _t[1];
        u64 v_c25 = _t[2];
        if (!slog::exists_probe<3,1>(mp_getindex703, std::array<u64,3>{v_c25, 0, 0})) return;
        slog::join_probe<6,2>($sup5638x52x0x0x0index704, std::array<u64,6>{v_c185, v_c25, 0, 0, 0, 0}, [&](const std::array<u64,6>& m724) {
          u64 v_c58 = m724[2]; u64 v_c59 = m724[3]; u64 v_c56 = m724[4]; u64 v_c24 = m724[5];
          slog::join_probe<5,5>(mbranchindex705, std::array<u64,5>{v_c56, v_c59, v_c58, v_c24, v_c186}, [&](const std::array<u64,5>& m725) {
            slog::join_probe_old<3,2>(mp_getindex706, mp_getdelta708, std::array<u64,3>{v_c24, v_c25, 0}, [&](const std::array<u64,3>& m726) {
              u64 v_c187 = m726[2];
              slog::join_probe<2,1>(mp_get_ansindex707, std::array<u64,2>{v_c187, 0}, [&](const std::array<u64,2>& m727) {
                u64 v_c22 = m727[1];
                u64 v_c188 = _prim_band(db, v_c25, v_c59);
                if (v_c188 == slog_error) { slog::emit_pending_error(db, "map.slog:53"); return; }
                u64 v_c189 = _prim_gt(db, v_c188, v_c184);
                if (v_c189 == slog_error) { slog::emit_pending_error(db, "map.slog:53"); return; }
                if (!v_c189) return;
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c185, v_c22}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:53", "delta:mp_get", _fires);
  
      if (!_done)
      {
        ReadTask709* _cont = new ReadTask709(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask709(db,b), false);
  // (crule (pre (let __tconst70WV799 const5feceb66ffc86f38d952786c)) (scan mbranch __t29Nf797 p m l r) (body (exists mp_del (1 2 0) 1 __t29Nf797) (exists mp_bld (1 2 3 4 0) 3 p m l) (exists mp_msk (2 0 1) 1 m) (exists mp_msk_ans (1 0) 1 p) (exists mp_del (1 2 0) 1 r) (join $sup5638x84x0x0x0 (4 2 3 5 0 1) 4 p l m r __t2paO798 k) (join-old mp_del (0 2 1) 3 (0 2 1) __t2paO798 k __t29Nf797) (exists mp_msk (1 2 0) 2 k m) (exists mp_del (1 2 0) 2 r k) (join-old mp_bld (1 2 3 4 0) 3 (1 2 3 4 0) p m l __v0 __t2Csk801) (exists mp_del_ans (1 0) 1 __v0) (exists mp_bld_ans (0 1) 1 __t2Csk801) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t4hJg802) (join mp_msk_ans (0 1) 2 __t4hJg802 p) (join-old mp_del (1 2 0) 2 (1 2 0) r k __t1FSo803) (join mp_del_ans (0 1) 2 __t1FSo803 __v0) (join mp_bld_ans (0 1) 1 __t2Csk801 res) (let __t1QoP800 (band k m)) (cmp gt __t1QoP800 __tconst70WV799)) (head (emit mp_del_ans (0 1) __t2paO798 res)) map.slog:85 #f)
  class ReadTask750 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_delindex729;  slog::Index** mp_bldindex730;  slog::Index** mp_mskindex731;  slog::Index** mp_msk_ansindex732;  slog::Index** mp_delindex733;  slog::Index** $sup5638x84x0x0x0index734;  slog::Index** mp_delindex735;  slog::Index** mp_mskindex736;  slog::Index** mp_delindex737;  slog::Index** mp_bldindex738;  slog::Index** mp_del_ansindex739;  slog::Index** mp_bld_ansindex740;  slog::Index** mp_mskindex741;  slog::Index** mp_msk_ansindex742;  slog::Index** mp_delindex743;  slog::Index** mp_del_ansindex744;  slog::Index** mp_bld_ansindex745;  slog::Index** mp_deldelta746;  slog::Index** mp_blddelta747;  slog::Index** mp_mskdelta748;  slog::Index** mp_deldelta749;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord751({0, 1});
      slog::Relation* readrel752 = db->getRelation("mp_del_ans");
      head_index[0] = readrel752->getIndex(ord751, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord753({1, 2, 0});
      slog::Relation* readrel754 = db->getRelation("mp_del");
      mp_delindex729 = readrel754->getIndex(ord753, false);
      std::vector<u16> ord755({1, 2, 3, 4, 0});
      slog::Relation* readrel756 = db->getRelation("mp_bld");
      mp_bldindex730 = readrel756->getIndex(ord755, false);
      std::vector<u16> ord757({2, 0, 1});
      slog::Relation* readrel758 = db->getRelation("mp_msk");
      mp_mskindex731 = readrel758->getIndex(ord757, false);
      std::vector<u16> ord759({1, 0});
      slog::Relation* readrel760 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex732 = readrel760->getIndex(ord759, false);
      std::vector<u16> ord761({1, 2, 0});
      slog::Relation* readrel762 = db->getRelation("mp_del");
      mp_delindex733 = readrel762->getIndex(ord761, false);
      std::vector<u16> ord763({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel764 = db->getRelation("$sup5638x84x0x0x0");
      $sup5638x84x0x0x0index734 = readrel764->getIndex(ord763, false);
      std::vector<u16> ord765({0, 2, 1});
      slog::Relation* readrel766 = db->getRelation("mp_del");
      mp_delindex735 = readrel766->getIndex(ord765, false);
      std::vector<u16> ord767({0, 2, 1});
      slog::Relation* readrel768 = db->getRelation("mp_del");
      mp_deldelta746 = readrel768->getIndex(ord767, true);
      std::vector<u16> ord769({1, 2, 0});
      slog::Relation* readrel770 = db->getRelation("mp_msk");
      mp_mskindex736 = readrel770->getIndex(ord769, false);
      std::vector<u16> ord771({1, 2, 0});
      slog::Relation* readrel772 = db->getRelation("mp_del");
      mp_delindex737 = readrel772->getIndex(ord771, false);
      std::vector<u16> ord773({1, 2, 3, 4, 0});
      slog::Relation* readrel774 = db->getRelation("mp_bld");
      mp_bldindex738 = readrel774->getIndex(ord773, false);
      std::vector<u16> ord775({1, 2, 3, 4, 0});
      slog::Relation* readrel776 = db->getRelation("mp_bld");
      mp_blddelta747 = readrel776->getIndex(ord775, true);
      std::vector<u16> ord777({1, 0});
      slog::Relation* readrel778 = db->getRelation("mp_del_ans");
      mp_del_ansindex739 = readrel778->getIndex(ord777, false);
      std::vector<u16> ord779({0, 1});
      slog::Relation* readrel780 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex740 = readrel780->getIndex(ord779, false);
      std::vector<u16> ord781({1, 2, 0});
      slog::Relation* readrel782 = db->getRelation("mp_msk");
      mp_mskindex741 = readrel782->getIndex(ord781, false);
      std::vector<u16> ord783({1, 2, 0});
      slog::Relation* readrel784 = db->getRelation("mp_msk");
      mp_mskdelta748 = readrel784->getIndex(ord783, true);
      std::vector<u16> ord785({0, 1});
      slog::Relation* readrel786 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex742 = readrel786->getIndex(ord785, false);
      std::vector<u16> ord787({1, 2, 0});
      slog::Relation* readrel788 = db->getRelation("mp_del");
      mp_delindex743 = readrel788->getIndex(ord787, false);
      std::vector<u16> ord789({1, 2, 0});
      slog::Relation* readrel790 = db->getRelation("mp_del");
      mp_deldelta749 = readrel790->getIndex(ord789, true);
      std::vector<u16> ord791({0, 1});
      slog::Relation* readrel792 = db->getRelation("mp_del_ans");
      mp_del_ansindex744 = readrel792->getIndex(ord791, false);
      std::vector<u16> ord793({0, 1});
      slog::Relation* readrel794 = db->getRelation("mp_bld_ans");
      mp_bld_ansindex745 = readrel794->getIndex(ord793, false);
  
    }
    ReadTask750(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c190 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c191 = _t[0];
        u64 v_c56 = _t[1];
        u64 v_c59 = _t[2];
        u64 v_c58 = _t[3];
        u64 v_c24 = _t[4];
        if (!slog::exists_probe<3,1>(mp_delindex729, std::array<u64,3>{v_c191, 0, 0})) return;
        if (!slog::exists_probe<5,3>(mp_bldindex730, std::array<u64,5>{v_c56, v_c59, v_c58, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex731, std::array<u64,3>{v_c59, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex732, std::array<u64,2>{v_c56, 0})) return;
        if (!slog::exists_probe<3,1>(mp_delindex733, std::array<u64,3>{v_c24, 0, 0})) return;
        slog::join_probe<6,4>($sup5638x84x0x0x0index734, std::array<u64,6>{v_c56, v_c58, v_c59, v_c24, 0, 0}, [&](const std::array<u64,6>& m795) {
          u64 v_c192 = m795[4]; u64 v_c25 = m795[5];
          slog::join_probe_old<3,3>(mp_delindex735, mp_deldelta746, std::array<u64,3>{v_c192, v_c25, v_c191}, [&](const std::array<u64,3>& m796) {
            if (!slog::exists_probe<3,2>(mp_mskindex736, std::array<u64,3>{v_c25, v_c59, 0})) return;
            if (!slog::exists_probe<3,2>(mp_delindex737, std::array<u64,3>{v_c24, v_c25, 0})) return;
            slog::join_probe_old<5,3>(mp_bldindex738, mp_blddelta747, std::array<u64,5>{v_c56, v_c59, v_c58, 0, 0}, [&](const std::array<u64,5>& m797) {
              u64 v_c51 = m797[3]; u64 v_c193 = m797[4];
              if (!slog::exists_probe<2,1>(mp_del_ansindex739, std::array<u64,2>{v_c51, 0})) return;
              if (!slog::exists_probe<2,1>(mp_bld_ansindex740, std::array<u64,2>{v_c193, 0})) return;
              slog::join_probe_old<3,2>(mp_mskindex741, mp_mskdelta748, std::array<u64,3>{v_c25, v_c59, 0}, [&](const std::array<u64,3>& m798) {
                u64 v_c194 = m798[2];
                slog::join_probe<2,2>(mp_msk_ansindex742, std::array<u64,2>{v_c194, v_c56}, [&](const std::array<u64,2>& m799) {
                  slog::join_probe_old<3,2>(mp_delindex743, mp_deldelta749, std::array<u64,3>{v_c24, v_c25, 0}, [&](const std::array<u64,3>& m800) {
                    u64 v_c195 = m800[2];
                    slog::join_probe<2,2>(mp_del_ansindex744, std::array<u64,2>{v_c195, v_c51}, [&](const std::array<u64,2>& m801) {
                      slog::join_probe<2,1>(mp_bld_ansindex745, std::array<u64,2>{v_c193, 0}, [&](const std::array<u64,2>& m802) {
                        u64 v_c196 = m802[1];
                        u64 v_c197 = _prim_band(db, v_c25, v_c59);
                        if (v_c197 == slog_error) { slog::emit_pending_error(db, "map.slog:85"); return; }
                        u64 v_c198 = _prim_gt(db, v_c197, v_c190);
                        if (v_c198 == slog_error) { slog::emit_pending_error(db, "map.slog:85"); return; }
                        if (!v_c198) return;
                        ++_fires;
                        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c192, v_c196}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("map.slog:85", "delta:mbranch", _fires);
  
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
  // (crule (pre) (scan closure __t6tRF614 __t20Nd613 rhoc) (body (join eval_ans (1 0) 1 __t6tRF614 __t7lOb612) (join lambda (0 1 2) 1 __t20Nd613 xs eb) (join eval (0 1 2 3) 1 __t7lOb612 ef rho t) (exists app (1 2 0) 1 ef) (exists eval_args (3 2 0 1) 2 t rho) (exists tick (2 0 1) 1 t) (join eval (2 3 0 1) 2 rho t __3JBR1203 __t3MQm616) (exists tick (1 2 0) 2 __t3MQm616 t) (join-old app (0 1 2) 2 (0 1 2) __t3MQm616 ef es) (join-old eval_args (1 3 2 0) 3 (1 3 2 0) es t rho __t192L615) (exists eval_args_ans (0 1) 1 __t192L615) (join-old tick (1 2 0) 2 (1 2 0) __t3MQm616 t __t2n7W617) (exists tick_ans (0 1) 1 __t2n7W617) (join eval_args_ans (0 1) 1 __t192L615 vs) (join tick_ans (0 1) 1 __t2n7W617 t2)) (head (emit bind_store (0 1 2 3) xs vs t2 t) (emit call_event (0 1) t2 t)) interp.slog:59 #f)
  class ReadTask822 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eval_ansindex804;  slog::Index** lambdaindex805;  slog::Index** evalindex806;  slog::Index** appindex807;  slog::Index** eval_argsindex808;  slog::Index** tickindex809;  slog::Index** evalindex810;  slog::Index** tickindex811;  slog::Index** appindex812;  slog::Index** eval_argsindex813;  slog::Index** eval_args_ansindex814;  slog::Index** tickindex815;  slog::Index** tick_ansindex816;  slog::Index** eval_args_ansindex817;  slog::Index** tick_ansindex818;  slog::Index** appdelta819;  slog::Index** eval_argsdelta820;  slog::Index** tickdelta821;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("bind_store");
      std::vector<u16> ord823({0, 1, 2, 3});
      slog::Relation* readrel824 = db->getRelation("bind_store");
      head_index[0] = readrel824->getIndex(ord823, false);
      head_rel[1] = db->getRelation("call_event");
      std::vector<u16> ord825({0, 1});
      slog::Relation* readrel826 = db->getRelation("call_event");
      head_index[1] = readrel826->getIndex(ord825, false);
      outer_rel = db->getRelation("closure");
      std::vector<u16> ord827({1, 0});
      slog::Relation* readrel828 = db->getRelation("eval_ans");
      eval_ansindex804 = readrel828->getIndex(ord827, false);
      std::vector<u16> ord829({0, 1, 2});
      slog::Relation* readrel830 = db->getRelation("lambda");
      lambdaindex805 = readrel830->getIndex(ord829, false);
      std::vector<u16> ord831({0, 1, 2, 3});
      slog::Relation* readrel832 = db->getRelation("eval");
      evalindex806 = readrel832->getIndex(ord831, false);
      std::vector<u16> ord833({1, 2, 0});
      slog::Relation* readrel834 = db->getRelation("app");
      appindex807 = readrel834->getIndex(ord833, false);
      std::vector<u16> ord835({3, 2, 0, 1});
      slog::Relation* readrel836 = db->getRelation("eval_args");
      eval_argsindex808 = readrel836->getIndex(ord835, false);
      std::vector<u16> ord837({2, 0, 1});
      slog::Relation* readrel838 = db->getRelation("tick");
      tickindex809 = readrel838->getIndex(ord837, false);
      std::vector<u16> ord839({2, 3, 0, 1});
      slog::Relation* readrel840 = db->getRelation("eval");
      evalindex810 = readrel840->getIndex(ord839, false);
      std::vector<u16> ord841({1, 2, 0});
      slog::Relation* readrel842 = db->getRelation("tick");
      tickindex811 = readrel842->getIndex(ord841, false);
      std::vector<u16> ord843({0, 1, 2});
      slog::Relation* readrel844 = db->getRelation("app");
      appindex812 = readrel844->getIndex(ord843, false);
      std::vector<u16> ord845({0, 1, 2});
      slog::Relation* readrel846 = db->getRelation("app");
      appdelta819 = readrel846->getIndex(ord845, true);
      std::vector<u16> ord847({1, 3, 2, 0});
      slog::Relation* readrel848 = db->getRelation("eval_args");
      eval_argsindex813 = readrel848->getIndex(ord847, false);
      std::vector<u16> ord849({1, 3, 2, 0});
      slog::Relation* readrel850 = db->getRelation("eval_args");
      eval_argsdelta820 = readrel850->getIndex(ord849, true);
      std::vector<u16> ord851({0, 1});
      slog::Relation* readrel852 = db->getRelation("eval_args_ans");
      eval_args_ansindex814 = readrel852->getIndex(ord851, false);
      std::vector<u16> ord853({1, 2, 0});
      slog::Relation* readrel854 = db->getRelation("tick");
      tickindex815 = readrel854->getIndex(ord853, false);
      std::vector<u16> ord855({1, 2, 0});
      slog::Relation* readrel856 = db->getRelation("tick");
      tickdelta821 = readrel856->getIndex(ord855, true);
      std::vector<u16> ord857({0, 1});
      slog::Relation* readrel858 = db->getRelation("tick_ans");
      tick_ansindex816 = readrel858->getIndex(ord857, false);
      std::vector<u16> ord859({0, 1});
      slog::Relation* readrel860 = db->getRelation("eval_args_ans");
      eval_args_ansindex817 = readrel860->getIndex(ord859, false);
      std::vector<u16> ord861({0, 1});
      slog::Relation* readrel862 = db->getRelation("tick_ans");
      tick_ansindex818 = readrel862->getIndex(ord861, false);
  
    }
    ReadTask822(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c199 = _t[0];
        u64 v_c200 = _t[1];
        u64 v_c201 = _t[2];
        slog::join_probe<2,1>(eval_ansindex804, std::array<u64,2>{v_c199, 0}, [&](const std::array<u64,2>& m863) {
          u64 v_c202 = m863[1];
          slog::join_probe<3,1>(lambdaindex805, std::array<u64,3>{v_c200, 0, 0}, [&](const std::array<u64,3>& m864) {
            u64 v_c203 = m864[1]; u64 v_c14 = m864[2];
            slog::join_probe<4,1>(evalindex806, std::array<u64,4>{v_c202, 0, 0, 0}, [&](const std::array<u64,4>& m865) {
              u64 v_c8 = m865[1]; u64 v_c10 = m865[2]; u64 v_c11 = m865[3];
              if (!slog::exists_probe<3,1>(appindex807, std::array<u64,3>{v_c8, 0, 0})) return;
              if (!slog::exists_probe<4,2>(eval_argsindex808, std::array<u64,4>{v_c11, v_c10, 0, 0})) return;
              if (!slog::exists_probe<3,1>(tickindex809, std::array<u64,3>{v_c11, 0, 0})) return;
              slog::join_probe<4,2>(evalindex810, std::array<u64,4>{v_c10, v_c11, 0, 0}, [&](const std::array<u64,4>& m866) {
                u64 v_c204 = m866[2]; u64 v_c205 = m866[3];
                if (!slog::exists_probe<3,2>(tickindex811, std::array<u64,3>{v_c205, v_c11, 0})) return;
                slog::join_probe_old<3,2>(appindex812, appdelta819, std::array<u64,3>{v_c205, v_c8, 0}, [&](const std::array<u64,3>& m867) {
                  u64 v_c9 = m867[2];
                  slog::join_probe_old<4,3>(eval_argsindex813, eval_argsdelta820, std::array<u64,4>{v_c9, v_c11, v_c10, 0}, [&](const std::array<u64,4>& m868) {
                    u64 v_c206 = m868[3];
                    if (!slog::exists_probe<2,1>(eval_args_ansindex814, std::array<u64,2>{v_c206, 0})) return;
                    slog::join_probe_old<3,2>(tickindex815, tickdelta821, std::array<u64,3>{v_c205, v_c11, 0}, [&](const std::array<u64,3>& m869) {
                      u64 v_c207 = m869[2];
                      if (!slog::exists_probe<2,1>(tick_ansindex816, std::array<u64,2>{v_c207, 0})) return;
                      slog::join_probe<2,1>(eval_args_ansindex817, std::array<u64,2>{v_c206, 0}, [&](const std::array<u64,2>& m870) {
                        u64 v_c208 = m870[1];
                        slog::join_probe<2,1>(tick_ansindex818, std::array<u64,2>{v_c207, 0}, [&](const std::array<u64,2>& m871) {
                          u64 v_c209 = m871[1];
                          ++_fires;
                          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c203, v_c208, v_c209, v_c11}, std::array<u16,4>{0, 1, 2, 3});
                          slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c209, v_c11}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:59", "delta:closure", _fires);
  
      if (!_done)
      {
        ReadTask822* _cont = new ReadTask822(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask822(db,b), false);
  // (crule (pre) (scan mp_hsb __t16An260 __t7Dpg261) (body (exists mp_hsb_ans (0 1) 1 __t16An260) (join mp_hsb_ans (0 1) 1 __t16An260 __v3) (join mp_hsb_ans (0 1) 1 __t16An260 __v1) (join $sup5638x29x0x0x1 (1 2 0 3 4 5 6) 0 __d1 __v0 __d0 p0 p1 t0 t1) (let chk7iN51837 (bxor p0 p1)) (eq __t7Dpg261 chk7iN51837)) (head (emit $sup5638x29x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) __d1 __v0 __v3 __v1 __d0 __t16An260 __t16An260 p0 p1 t0 t1)) map.slog:30 #f)
  class ReadTask876 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_hsb_ansindex872;  slog::Index** mp_hsb_ansindex873;  slog::Index** mp_hsb_ansindex874;  slog::Index** $sup5638x29x0x0x1index875;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x29x0x0x2");
      std::vector<u16> ord877({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel878 = db->getRelation("$sup5638x29x0x0x2");
      head_index[0] = readrel878->getIndex(ord877, false);
      outer_rel = db->getRelation("mp_hsb");
      std::vector<u16> ord879({0, 1});
      slog::Relation* readrel880 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex872 = readrel880->getIndex(ord879, false);
      std::vector<u16> ord881({0, 1});
      slog::Relation* readrel882 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex873 = readrel882->getIndex(ord881, false);
      std::vector<u16> ord883({0, 1});
      slog::Relation* readrel884 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex874 = readrel884->getIndex(ord883, false);
      std::vector<u16> ord885({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel886 = db->getRelation("$sup5638x29x0x0x1");
      $sup5638x29x0x0x1index875 = readrel886->getIndex(ord885, false);
  
    }
    ReadTask876(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c211 = _t[1];
        if (!slog::exists_probe<2,1>(mp_hsb_ansindex872, std::array<u64,2>{v_c210, 0})) return;
        slog::join_probe<2,1>(mp_hsb_ansindex873, std::array<u64,2>{v_c210, 0}, [&](const std::array<u64,2>& m887) {
          u64 v_c85 = m887[1];
          slog::join_probe<2,1>(mp_hsb_ansindex874, std::array<u64,2>{v_c210, 0}, [&](const std::array<u64,2>& m888) {
            u64 v_c84 = m888[1];
            slog::join_all<7>($sup5638x29x0x0x1index875, [&](const std::array<u64,7>& m889) {
              u64 v_c147 = m889[0]; u64 v_c51 = m889[1]; u64 v_c7 = m889[2]; u64 v_c78 = m889[3]; u64 v_c79 = m889[4]; u64 v_c80 = m889[5]; u64 v_c81 = m889[6];
              u64 v_c212 = _prim_bxor(db, v_c78, v_c79);
              if (v_c212 == slog_error) { slog::emit_pending_error(db, "map.slog:30"); return; }
              if (v_c211 != v_c212) return;
              ++_fires;
              slog::emit<11>(head_rel[0], head_index[0], newbatch[0], std::array<u64,11>{v_c147, v_c51, v_c85, v_c84, v_c7, v_c210, v_c210, v_c78, v_c79, v_c80, v_c81}, std::array<u16,11>{1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:30", "delta:mp_hsb", _fires);
  
      if (!_done)
      {
        ReadTask876* _cont = new ReadTask876(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask876(db,b), false);
  // (crule (pre (let _00024sqc7DnB839 const6b86b273ff34fce19d6b804e) (let _00024sqc4H0B840 const5feceb66ffc86f38d952786c) (let _00024sqc58w2841 const6b86b273ff34fce19d6b804e) (let _00024sqc7wgB842 const5feceb66ffc86f38d952786c) (let _00024sqo31L8847 const5feceb66ffc86f38d952786c)) (scan extend_env_ans __t8zl419 __v1) (body (join-old $seq_at (1 0 2) 1 (1 0 2) _00024sqo31L8847 x _00024seq0) (letp _00024sql00Zd837 (aslst _00024seq0)) (let _00024sqn2cl5838 (llen _00024sql00Zd837)) (cmp ge _00024sqn2cl5838 _00024sqc7DnB839) (let _00024sqp8r44843 (_0002d _00024sqn2cl5838 _00024sqc7wgB842)) (let xs (lslice _00024sql00Zd837 _00024sqc58w2841 _00024sqp8r44843)) (exists extend_env (2 3 0 1) 1 _00024seq0) (exists mp_put (2 3 0 1) 1 x) (exists extend_env (0 2 3 1) 2 __t8zl419 xs) (join-old $sup70016x47x0x0x0 (0 4 5 1 2 3) 3 (0 4 5 1 2 3) _00024seq0 x xs __t2ugT17 rho t) (join-old extend_env (0 2 3 1) 4 (0 2 3 1) __t2ugT17 _00024seq0 t rho) (exists extend_env (0 2 3 1) 3 __t8zl419 xs t) (join-old mp_put (1 2 3 0) 3 (1 2 3 0) rho x t __t42Fa18) (exists mp_put_ans (0 1) 1 __t42Fa18) (join-old extend_env (0 2 3 1) 3 (0 2 3 1) __t8zl419 xs t __v0) (join mp_put_ans (0 1) 2 __t42Fa18 __v0) (letp chk9Wb01824 (lref _00024sql00Zd837 _00024sqc4H0B840)) (eq x chk9Wb01824)) (head (emit extend_env_ans (0 1) __t2ugT17 __v1)) interp.slog:48 #f)
  class ReadTask906 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $seq_atindex890;  slog::Index** extend_envindex891;  slog::Index** mp_putindex892;  slog::Index** extend_envindex893;  slog::Index** $sup70016x47x0x0x0index894;  slog::Index** extend_envindex895;  slog::Index** extend_envindex896;  slog::Index** mp_putindex897;  slog::Index** mp_put_ansindex898;  slog::Index** extend_envindex899;  slog::Index** mp_put_ansindex900;  slog::Index** $seq_atdelta901;  slog::Index** $sup70016x47x0x0x0delta902;  slog::Index** extend_envdelta903;  slog::Index** mp_putdelta904;  slog::Index** extend_envdelta905;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("extend_env_ans");
      std::vector<u16> ord907({0, 1});
      slog::Relation* readrel908 = db->getRelation("extend_env_ans");
      head_index[0] = readrel908->getIndex(ord907, false);
      outer_rel = db->getRelation("extend_env_ans");
      std::vector<u16> ord909({1, 0, 2});
      slog::Relation* readrel910 = db->getRelation("$seq_at");
      $seq_atindex890 = readrel910->getIndex(ord909, false);
      std::vector<u16> ord911({1, 0, 2});
      slog::Relation* readrel912 = db->getRelation("$seq_at");
      $seq_atdelta901 = readrel912->getIndex(ord911, true);
      std::vector<u16> ord913({2, 3, 0, 1});
      slog::Relation* readrel914 = db->getRelation("extend_env");
      extend_envindex891 = readrel914->getIndex(ord913, false);
      std::vector<u16> ord915({2, 3, 0, 1});
      slog::Relation* readrel916 = db->getRelation("mp_put");
      mp_putindex892 = readrel916->getIndex(ord915, false);
      std::vector<u16> ord917({0, 2, 3, 1});
      slog::Relation* readrel918 = db->getRelation("extend_env");
      extend_envindex893 = readrel918->getIndex(ord917, false);
      std::vector<u16> ord919({0, 4, 5, 1, 2, 3});
      slog::Relation* readrel920 = db->getRelation("$sup70016x47x0x0x0");
      $sup70016x47x0x0x0index894 = readrel920->getIndex(ord919, false);
      std::vector<u16> ord921({0, 4, 5, 1, 2, 3});
      slog::Relation* readrel922 = db->getRelation("$sup70016x47x0x0x0");
      $sup70016x47x0x0x0delta902 = readrel922->getIndex(ord921, true);
      std::vector<u16> ord923({0, 2, 3, 1});
      slog::Relation* readrel924 = db->getRelation("extend_env");
      extend_envindex895 = readrel924->getIndex(ord923, false);
      std::vector<u16> ord925({0, 2, 3, 1});
      slog::Relation* readrel926 = db->getRelation("extend_env");
      extend_envdelta903 = readrel926->getIndex(ord925, true);
      std::vector<u16> ord927({0, 2, 3, 1});
      slog::Relation* readrel928 = db->getRelation("extend_env");
      extend_envindex896 = readrel928->getIndex(ord927, false);
      std::vector<u16> ord929({1, 2, 3, 0});
      slog::Relation* readrel930 = db->getRelation("mp_put");
      mp_putindex897 = readrel930->getIndex(ord929, false);
      std::vector<u16> ord931({1, 2, 3, 0});
      slog::Relation* readrel932 = db->getRelation("mp_put");
      mp_putdelta904 = readrel932->getIndex(ord931, true);
      std::vector<u16> ord933({0, 1});
      slog::Relation* readrel934 = db->getRelation("mp_put_ans");
      mp_put_ansindex898 = readrel934->getIndex(ord933, false);
      std::vector<u16> ord935({0, 2, 3, 1});
      slog::Relation* readrel936 = db->getRelation("extend_env");
      extend_envindex899 = readrel936->getIndex(ord935, false);
      std::vector<u16> ord937({0, 2, 3, 1});
      slog::Relation* readrel938 = db->getRelation("extend_env");
      extend_envdelta905 = readrel938->getIndex(ord937, true);
      std::vector<u16> ord939({0, 1});
      slog::Relation* readrel940 = db->getRelation("mp_put_ans");
      mp_put_ansindex900 = readrel940->getIndex(ord939, false);
  
    }
    ReadTask906(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c213 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c214 = v_const5feceb66ffc86f38d952786c;
      u64 v_c215 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c216 = v_const5feceb66ffc86f38d952786c;
      u64 v_c217 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c218 = _t[0];
        u64 v_c84 = _t[1];
        slog::join_probe_old<3,1>($seq_atindex890, $seq_atdelta901, std::array<u64,3>{v_c217, 0, 0}, [&](const std::array<u64,3>& m941) {
          u64 v_c16 = m941[1]; u64 v_c156 = m941[2];
          bool ok942 = true;
          u64 v_c219 = _prim_aslst(db, v_c156, &ok942);
          if (!ok942) return;
          u64 v_c220 = _prim_llen(db, v_c219);
          if (v_c220 == slog_error) { slog::emit_pending_error(db, "interp.slog:48"); return; }
          u64 v_c221 = _prim_ge(db, v_c220, v_c213);
          if (v_c221 == slog_error) { slog::emit_pending_error(db, "interp.slog:48"); return; }
          if (!v_c221) return;
          u64 v_c222 = _prim__0002d(db, v_c220, v_c216);
          if (v_c222 == slog_error) { slog::emit_pending_error(db, "interp.slog:48"); return; }
          u64 v_c203 = _prim_lslice(db, v_c219, v_c215, v_c222);
          if (v_c203 == slog_error) { slog::emit_pending_error(db, "interp.slog:48"); return; }
          if (!slog::exists_probe<4,1>(extend_envindex891, std::array<u64,4>{v_c156, 0, 0, 0})) return;
          if (!slog::exists_probe<4,1>(mp_putindex892, std::array<u64,4>{v_c16, 0, 0, 0})) return;
          if (!slog::exists_probe<4,2>(extend_envindex893, std::array<u64,4>{v_c218, v_c203, 0, 0})) return;
          slog::join_probe_old<6,3>($sup70016x47x0x0x0index894, $sup70016x47x0x0x0delta902, std::array<u64,6>{v_c156, v_c16, v_c203, 0, 0, 0}, [&](const std::array<u64,6>& m944) {
            u64 v_c223 = m944[3]; u64 v_c10 = m944[4]; u64 v_c11 = m944[5];
            slog::join_probe_old<4,4>(extend_envindex895, extend_envdelta903, std::array<u64,4>{v_c223, v_c156, v_c11, v_c10}, [&](const std::array<u64,4>& m945) {
              if (!slog::exists_probe<4,3>(extend_envindex896, std::array<u64,4>{v_c218, v_c203, v_c11, 0})) return;
              slog::join_probe_old<4,3>(mp_putindex897, mp_putdelta904, std::array<u64,4>{v_c10, v_c16, v_c11, 0}, [&](const std::array<u64,4>& m946) {
                u64 v_c224 = m946[3];
                if (!slog::exists_probe<2,1>(mp_put_ansindex898, std::array<u64,2>{v_c224, 0})) return;
                slog::join_probe_old<4,3>(extend_envindex899, extend_envdelta905, std::array<u64,4>{v_c218, v_c203, v_c11, 0}, [&](const std::array<u64,4>& m947) {
                  u64 v_c51 = m947[3];
                  slog::join_probe<2,2>(mp_put_ansindex900, std::array<u64,2>{v_c224, v_c51}, [&](const std::array<u64,2>& m948) {
                    bool ok949 = true;
                    u64 v_c225 = _prim_lref(db, v_c219, v_c214, &ok949);
                    if (!ok949) return;
                    if (v_c16 != v_c225) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c223, v_c84}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:48", "delta:extend_env_ans", _fires);
  
      if (!_done)
      {
        ReadTask906* _cont = new ReadTask906(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask906(db,b), false);
  // (crule (pre) (scan mp_join_ans __t8BsD696 res) (body (join-old mp_join (0 1 2 3 4) 1 (0 1 2 3 4) __t8BsD696 p __t1ouF694 q __t1a8C695) (exists mbranch (0 1 2 3 4) 2 __t1ouF694 p) (exists mbranch (0 1 2 3 4) 2 __t1a8C695 q) (exists mp_union (1 2 0) 2 __t1ouF694 __t1a8C695) (exists mp_msk (1 2 0) 1 q) (join-old $sup5638x101x0x0x0 (4 5 7 8 0 1 2 3 6 9 10) 4 (4 5 7 8 0 1 2 3 6 9 10) p q __t1ouF694 __t1a8C695 __t5awj693 l m n r u v) (cmp lt n m) (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) p m l r __t1ouF694) (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) q n u v __t1a8C695) (join-old mp_union (0 1 2) 3 (0 1 2) __t5awj693 __t1ouF694 __t1a8C695) (join-old mp_msk (1 2 0) 2 (1 2 0) q m __t84wf697) (join-old mp_msk_ans (0 1) 1 (0 1) __t84wf697 __v0) (neq p __v0)) (head (emit mp_union_ans (0 1) __t5awj693 res)) map.slog:102 #f)
  class ReadTask968 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_joinindex950;  slog::Index** mbranchindex951;  slog::Index** mbranchindex952;  slog::Index** mp_unionindex953;  slog::Index** mp_mskindex954;  slog::Index** $sup5638x101x0x0x0index955;  slog::Index** mbranchindex956;  slog::Index** mbranchindex957;  slog::Index** mp_unionindex958;  slog::Index** mp_mskindex959;  slog::Index** mp_msk_ansindex960;  slog::Index** mp_joindelta961;  slog::Index** $sup5638x101x0x0x0delta962;  slog::Index** mbranchdelta963;  slog::Index** mbranchdelta964;  slog::Index** mp_uniondelta965;  slog::Index** mp_mskdelta966;  slog::Index** mp_msk_ansdelta967;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord969({0, 1});
      slog::Relation* readrel970 = db->getRelation("mp_union_ans");
      head_index[0] = readrel970->getIndex(ord969, false);
      outer_rel = db->getRelation("mp_join_ans");
      std::vector<u16> ord971({0, 1, 2, 3, 4});
      slog::Relation* readrel972 = db->getRelation("mp_join");
      mp_joinindex950 = readrel972->getIndex(ord971, false);
      std::vector<u16> ord973({0, 1, 2, 3, 4});
      slog::Relation* readrel974 = db->getRelation("mp_join");
      mp_joindelta961 = readrel974->getIndex(ord973, true);
      std::vector<u16> ord975({0, 1, 2, 3, 4});
      slog::Relation* readrel976 = db->getRelation("mbranch");
      mbranchindex951 = readrel976->getIndex(ord975, false);
      std::vector<u16> ord977({0, 1, 2, 3, 4});
      slog::Relation* readrel978 = db->getRelation("mbranch");
      mbranchindex952 = readrel978->getIndex(ord977, false);
      std::vector<u16> ord979({1, 2, 0});
      slog::Relation* readrel980 = db->getRelation("mp_union");
      mp_unionindex953 = readrel980->getIndex(ord979, false);
      std::vector<u16> ord981({1, 2, 0});
      slog::Relation* readrel982 = db->getRelation("mp_msk");
      mp_mskindex954 = readrel982->getIndex(ord981, false);
      std::vector<u16> ord983({4, 5, 7, 8, 0, 1, 2, 3, 6, 9, 10});
      slog::Relation* readrel984 = db->getRelation("$sup5638x101x0x0x0");
      $sup5638x101x0x0x0index955 = readrel984->getIndex(ord983, false);
      std::vector<u16> ord985({4, 5, 7, 8, 0, 1, 2, 3, 6, 9, 10});
      slog::Relation* readrel986 = db->getRelation("$sup5638x101x0x0x0");
      $sup5638x101x0x0x0delta962 = readrel986->getIndex(ord985, true);
      std::vector<u16> ord987({1, 2, 3, 4, 0});
      slog::Relation* readrel988 = db->getRelation("mbranch");
      mbranchindex956 = readrel988->getIndex(ord987, false);
      std::vector<u16> ord989({1, 2, 3, 4, 0});
      slog::Relation* readrel990 = db->getRelation("mbranch");
      mbranchdelta963 = readrel990->getIndex(ord989, true);
      std::vector<u16> ord991({1, 2, 3, 4, 0});
      slog::Relation* readrel992 = db->getRelation("mbranch");
      mbranchindex957 = readrel992->getIndex(ord991, false);
      std::vector<u16> ord993({1, 2, 3, 4, 0});
      slog::Relation* readrel994 = db->getRelation("mbranch");
      mbranchdelta964 = readrel994->getIndex(ord993, true);
      std::vector<u16> ord995({0, 1, 2});
      slog::Relation* readrel996 = db->getRelation("mp_union");
      mp_unionindex958 = readrel996->getIndex(ord995, false);
      std::vector<u16> ord997({0, 1, 2});
      slog::Relation* readrel998 = db->getRelation("mp_union");
      mp_uniondelta965 = readrel998->getIndex(ord997, true);
      std::vector<u16> ord999({1, 2, 0});
      slog::Relation* readrel1000 = db->getRelation("mp_msk");
      mp_mskindex959 = readrel1000->getIndex(ord999, false);
      std::vector<u16> ord1001({1, 2, 0});
      slog::Relation* readrel1002 = db->getRelation("mp_msk");
      mp_mskdelta966 = readrel1002->getIndex(ord1001, true);
      std::vector<u16> ord1003({0, 1});
      slog::Relation* readrel1004 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex960 = readrel1004->getIndex(ord1003, false);
      std::vector<u16> ord1005({0, 1});
      slog::Relation* readrel1006 = db->getRelation("mp_msk_ans");
      mp_msk_ansdelta967 = readrel1006->getIndex(ord1005, true);
  
    }
    ReadTask968(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c226 = _t[0];
        u64 v_c196 = _t[1];
        slog::join_probe_old<5,1>(mp_joinindex950, mp_joindelta961, std::array<u64,5>{v_c226, 0, 0, 0, 0}, [&](const std::array<u64,5>& m1007) {
          u64 v_c56 = m1007[1]; u64 v_c227 = m1007[2]; u64 v_c55 = m1007[3]; u64 v_c228 = m1007[4];
          if (!slog::exists_probe<5,2>(mbranchindex951, std::array<u64,5>{v_c227, v_c56, 0, 0, 0})) return;
          if (!slog::exists_probe<5,2>(mbranchindex952, std::array<u64,5>{v_c228, v_c55, 0, 0, 0})) return;
          if (!slog::exists_probe<3,2>(mp_unionindex953, std::array<u64,3>{v_c227, v_c228, 0})) return;
          if (!slog::exists_probe<3,1>(mp_mskindex954, std::array<u64,3>{v_c55, 0, 0})) return;
          slog::join_probe_old<11,4>($sup5638x101x0x0x0index955, $sup5638x101x0x0x0delta962, std::array<u64,11>{v_c56, v_c55, v_c227, v_c228, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m1008) {
            u64 v_c229 = m1008[4]; u64 v_c58 = m1008[5]; u64 v_c59 = m1008[6]; u64 v_c57 = m1008[7]; u64 v_c24 = m1008[8]; u64 v_c60 = m1008[9]; u64 v_c22 = m1008[10];
            u64 v_c230 = _prim_lt(db, v_c57, v_c59);
            if (v_c230 == slog_error) { slog::emit_pending_error(db, "map.slog:102"); return; }
            if (!v_c230) return;
            slog::join_probe_old<5,5>(mbranchindex956, mbranchdelta963, std::array<u64,5>{v_c56, v_c59, v_c58, v_c24, v_c227}, [&](const std::array<u64,5>& m1010) {
              slog::join_probe_old<5,5>(mbranchindex957, mbranchdelta964, std::array<u64,5>{v_c55, v_c57, v_c60, v_c22, v_c228}, [&](const std::array<u64,5>& m1011) {
                slog::join_probe_old<3,3>(mp_unionindex958, mp_uniondelta965, std::array<u64,3>{v_c229, v_c227, v_c228}, [&](const std::array<u64,3>& m1012) {
                  slog::join_probe_old<3,2>(mp_mskindex959, mp_mskdelta966, std::array<u64,3>{v_c55, v_c59, 0}, [&](const std::array<u64,3>& m1013) {
                    u64 v_c231 = m1013[2];
                    slog::join_probe_old<2,1>(mp_msk_ansindex960, mp_msk_ansdelta967, std::array<u64,2>{v_c231, 0}, [&](const std::array<u64,2>& m1014) {
                      u64 v_c51 = m1014[1];
                      if (v_c56 == v_c51) return;
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c229, v_c196}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:102", "delta:mp_join_ans", _fires);
  
      if (!_done)
      {
        ReadTask968* _cont = new ReadTask968(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask968(db,b), false);
  // (crule (pre (let _00024sqc4Fzm988 constd4735e3a265e16eee03f5971) (let _00024sqc6SKj989 const5feceb66ffc86f38d952786c) (let _00024sqc8JKk990 const6b86b273ff34fce19d6b804e) (let _00024sqc2Wqs993 const6b86b273ff34fce19d6b804e) (let _00024sqc3gqm994 const5feceb66ffc86f38d952786c) (let _00024sqc5u0R995 const6b86b273ff34fce19d6b804e) (let _00024sqc2qd4996 const5feceb66ffc86f38d952786c) (let _00024sqo0rW61001 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo0rW61001 _00024seq0 _00024seq1) (body (exists $sup5638x127x0x0x0 (0 1 2 3 4 5) 2 _00024seq0 _00024seq1) (join mp_fromlist (1 0) 1 _00024seq1 __t1Wom763) (letp _00024sql7g5s986 (aslst _00024seq0)) (letp k (lref _00024sql7g5s986 _00024sqc6SKj989)) (letp v (lref _00024sql7g5s986 _00024sqc8JKk990)) (letp _00024sql4o7j991 (aslst _00024seq1)) (let _00024sqn095f992 (llen _00024sql4o7j991)) (cmp ge _00024sqn095f992 _00024sqc2Wqs993) (let _00024sqp3avN997 (_0002d _00024sqn095f992 _00024sqc2qd4996)) (let xs (lslice _00024sql4o7j991 _00024sqc5u0R995 _00024sqp3avN997)) (join $sup5638x127x0x0x0 (3 4 5 0 1 2) 6 k v xs _00024seq0 _00024seq1 __t1Wom763) (exists mp_fromlist (1 0) 1 xs) (join mp_put (2 3 0 1) 2 k v __t5IsX765 __v0) (exists mp_put_ans (0 1) 1 __t5IsX765) (join mp_fromlist_ans (1 0) 1 __v0 __t3r8n764) (join mp_fromlist (0 1) 2 __t3r8n764 xs) (join mp_put_ans (0 1) 1 __t5IsX765 __v1) (let chk0a1V1889 (llen _00024sql7g5s986)) (eq _00024sqc4Fzm988 chk0a1V1889) (letp chk1oEj1890 (lref _00024sql4o7j991 _00024sqc3gqm994)) (eq _00024seq0 chk1oEj1890)) (head (emit mp_fromlist_ans (1 0) __v1 __t1Wom763)) map.slog:128 #f)
  class ReadTask1024 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $sup5638x127x0x0x0index1015;  slog::Index** mp_fromlistindex1016;  slog::Index** $sup5638x127x0x0x0index1017;  slog::Index** mp_fromlistindex1018;  slog::Index** mp_putindex1019;  slog::Index** mp_put_ansindex1020;  slog::Index** mp_fromlist_ansindex1021;  slog::Index** mp_fromlistindex1022;  slog::Index** mp_put_ansindex1023;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_fromlist_ans");
      std::vector<u16> ord1025({1, 0});
      slog::Relation* readrel1026 = db->getRelation("mp_fromlist_ans");
      head_index[0] = readrel1026->getIndex(ord1025, false);
      std::vector<u16> ord1027({1, 0, 2});
      slog::Relation* readrel1028 = db->getRelation("$seq_at");
      driver_index = readrel1028->getIndex(ord1027, true);
      std::vector<u16> ord1029({0, 1, 2, 3, 4, 5});
      slog::Relation* readrel1030 = db->getRelation("$sup5638x127x0x0x0");
      $sup5638x127x0x0x0index1015 = readrel1030->getIndex(ord1029, false);
      std::vector<u16> ord1031({1, 0});
      slog::Relation* readrel1032 = db->getRelation("mp_fromlist");
      mp_fromlistindex1016 = readrel1032->getIndex(ord1031, false);
      std::vector<u16> ord1033({3, 4, 5, 0, 1, 2});
      slog::Relation* readrel1034 = db->getRelation("$sup5638x127x0x0x0");
      $sup5638x127x0x0x0index1017 = readrel1034->getIndex(ord1033, false);
      std::vector<u16> ord1035({1, 0});
      slog::Relation* readrel1036 = db->getRelation("mp_fromlist");
      mp_fromlistindex1018 = readrel1036->getIndex(ord1035, false);
      std::vector<u16> ord1037({2, 3, 0, 1});
      slog::Relation* readrel1038 = db->getRelation("mp_put");
      mp_putindex1019 = readrel1038->getIndex(ord1037, false);
      std::vector<u16> ord1039({0, 1});
      slog::Relation* readrel1040 = db->getRelation("mp_put_ans");
      mp_put_ansindex1020 = readrel1040->getIndex(ord1039, false);
      std::vector<u16> ord1041({1, 0});
      slog::Relation* readrel1042 = db->getRelation("mp_fromlist_ans");
      mp_fromlist_ansindex1021 = readrel1042->getIndex(ord1041, false);
      std::vector<u16> ord1043({0, 1});
      slog::Relation* readrel1044 = db->getRelation("mp_fromlist");
      mp_fromlistindex1022 = readrel1044->getIndex(ord1043, false);
      std::vector<u16> ord1045({0, 1});
      slog::Relation* readrel1046 = db->getRelation("mp_put_ans");
      mp_put_ansindex1023 = readrel1046->getIndex(ord1045, false);
  
    }
    ReadTask1024(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c232 = v_constd4735e3a265e16eee03f5971;
      u64 v_c233 = v_const5feceb66ffc86f38d952786c;
      u64 v_c234 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c235 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c236 = v_const5feceb66ffc86f38d952786c;
      u64 v_c237 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c238 = v_const5feceb66ffc86f38d952786c;
      u64 v_c239 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c239, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1047) {
        u64 v_c156 = m1047[1];
        u64 v_c240 = m1047[2];
        if (buckethash(v_c156) != bucket) return;
        if (!slog::exists_probe<6,2>($sup5638x127x0x0x0index1015, std::array<u64,6>{v_c156, v_c240, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(mp_fromlistindex1016, std::array<u64,2>{v_c240, 0}, [&](const std::array<u64,2>& m1048) {
          u64 v_c241 = m1048[1];
          bool ok1049 = true;
          u64 v_c242 = _prim_aslst(db, v_c156, &ok1049);
          if (!ok1049) return;
          bool ok1050 = true;
          u64 v_c25 = _prim_lref(db, v_c242, v_c233, &ok1050);
          if (!ok1050) return;
          bool ok1051 = true;
          u64 v_c22 = _prim_lref(db, v_c242, v_c234, &ok1051);
          if (!ok1051) return;
          bool ok1052 = true;
          u64 v_c243 = _prim_aslst(db, v_c240, &ok1052);
          if (!ok1052) return;
          u64 v_c244 = _prim_llen(db, v_c243);
          if (v_c244 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
          u64 v_c245 = _prim_ge(db, v_c244, v_c235);
          if (v_c245 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
          if (!v_c245) return;
          u64 v_c246 = _prim__0002d(db, v_c244, v_c238);
          if (v_c246 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
          u64 v_c203 = _prim_lslice(db, v_c243, v_c237, v_c246);
          if (v_c203 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
          slog::join_probe<6,6>($sup5638x127x0x0x0index1017, std::array<u64,6>{v_c25, v_c22, v_c203, v_c156, v_c240, v_c241}, [&](const std::array<u64,6>& m1054) {
            if (!slog::exists_probe<2,1>(mp_fromlistindex1018, std::array<u64,2>{v_c203, 0})) return;
            slog::join_probe<4,2>(mp_putindex1019, std::array<u64,4>{v_c25, v_c22, 0, 0}, [&](const std::array<u64,4>& m1055) {
              u64 v_c247 = m1055[2]; u64 v_c51 = m1055[3];
              if (!slog::exists_probe<2,1>(mp_put_ansindex1020, std::array<u64,2>{v_c247, 0})) return;
              slog::join_probe<2,1>(mp_fromlist_ansindex1021, std::array<u64,2>{v_c51, 0}, [&](const std::array<u64,2>& m1056) {
                u64 v_c248 = m1056[1];
                slog::join_probe<2,2>(mp_fromlistindex1022, std::array<u64,2>{v_c248, v_c203}, [&](const std::array<u64,2>& m1057) {
                  slog::join_probe<2,1>(mp_put_ansindex1023, std::array<u64,2>{v_c247, 0}, [&](const std::array<u64,2>& m1058) {
                    u64 v_c84 = m1058[1];
                    u64 v_c249 = _prim_llen(db, v_c242);
                    if (v_c249 == slog_error) { slog::emit_pending_error(db, "map.slog:128"); return; }
                    if (v_c232 != v_c249) return;
                    bool ok1059 = true;
                    u64 v_c250 = _prim_lref(db, v_c243, v_c236, &ok1059);
                    if (!ok1059) return;
                    if (v_c156 != v_c250) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c84, v_c241}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:128", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask1024* _cont = new ReadTask1024(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1024(db,b), false);
  // (crule (pre (let __tconst19gx36 const6b86b273ff34fce19d6b804e)) (scan mbranch __t4rR634 p m l r) (body (join-old mp_union (1 2 0) 1 (1 2 0) __t4rR634 __t9QG833 __t4pAf35) (join mbranch (0 1 2 3 4) 1 __t9QG833 q n u v) (cmp lt n m) (let __t204137 (band q m)) (cmp lt __t204137 __tconst19gx36)) (head (emit $sup5638x95x0x0x0 (0 1 2 3 4 5 6 7 8) __t4pAf35 l m n p q r u v)) map.slog:96 #f)
  class ReadTask1063 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex1060;  slog::Index** mbranchindex1061;  slog::Index** mp_uniondelta1062;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x95x0x0x0");
      std::vector<u16> ord1064({0, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel1065 = db->getRelation("$sup5638x95x0x0x0");
      head_index[0] = readrel1065->getIndex(ord1064, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord1066({1, 2, 0});
      slog::Relation* readrel1067 = db->getRelation("mp_union");
      mp_unionindex1060 = readrel1067->getIndex(ord1066, false);
      std::vector<u16> ord1068({1, 2, 0});
      slog::Relation* readrel1069 = db->getRelation("mp_union");
      mp_uniondelta1062 = readrel1069->getIndex(ord1068, true);
      std::vector<u16> ord1070({0, 1, 2, 3, 4});
      slog::Relation* readrel1071 = db->getRelation("mbranch");
      mbranchindex1061 = readrel1071->getIndex(ord1070, false);
  
    }
    ReadTask1063(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c251 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c252 = _t[0];
        u64 v_c56 = _t[1];
        u64 v_c59 = _t[2];
        u64 v_c58 = _t[3];
        u64 v_c24 = _t[4];
        slog::join_probe_old<3,1>(mp_unionindex1060, mp_uniondelta1062, std::array<u64,3>{v_c252, 0, 0}, [&](const std::array<u64,3>& m1072) {
          u64 v_c253 = m1072[1]; u64 v_c254 = m1072[2];
          slog::join_probe<5,1>(mbranchindex1061, std::array<u64,5>{v_c253, 0, 0, 0, 0}, [&](const std::array<u64,5>& m1073) {
            u64 v_c55 = m1073[1]; u64 v_c57 = m1073[2]; u64 v_c60 = m1073[3]; u64 v_c22 = m1073[4];
            u64 v_c255 = _prim_lt(db, v_c57, v_c59);
            if (v_c255 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
            if (!v_c255) return;
            u64 v_c256 = _prim_band(db, v_c55, v_c59);
            if (v_c256 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
            u64 v_c257 = _prim_lt(db, v_c256, v_c251);
            if (v_c257 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
            if (!v_c257) return;
            ++_fires;
            slog::emit<9>(head_rel[0], head_index[0], newbatch[0], std::array<u64,9>{v_c254, v_c58, v_c59, v_c57, v_c56, v_c55, v_c24, v_c60, v_c22}, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:96", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask1063* _cont = new ReadTask1063(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1063(db,b), false);
  // (crule (pre (let __trid5i9W1073 constb177cd86b4c517da8099d6e4) (let __trel0uAT1074 const1064263932db82f2cf6d4ac2) (let __tcol476G1075 const5feceb66ffc86f38d952786c) (let __trel64Fx1076 const1064263932db82f2cf6d4ac2) (let __tcol6RKf1077 const6b86b273ff34fce19d6b804e)) (scan $sup70016x92x0x0x0 __d0 eb er rho t x) (body) (head (tycheck rho (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid5i9W1073 __trel0uAT1074 __tcol476G1075 (1 2 3 4 0)) (tycheck x (accept int) __trid5i9W1073 __trel64Fx1076 __tcol6RKf1077 (1 2 3 4 0)) (mkstruct mp_put (1 2 3 0) __2r491072 rho x t)) interp.slog:93 #f)
  class ReadTask1079 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid1077;  u32 sid1076;  u32 sid1078;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("mp_put");
      outer_rel = db->getRelation("$sup70016x92x0x0x0");
      sid1077 = db->getRelation("_enum")->getStructId();
      sid1076 = db->getRelation("mbranch")->getStructId();
      sid1078 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask1079(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c258 = v_constb177cd86b4c517da8099d6e4;
      u64 v_c259 = v_const1064263932db82f2cf6d4ac2;
      u64 v_c260 = v_const5feceb66ffc86f38d952786c;
      u64 v_c261 = v_const1064263932db82f2cf6d4ac2;
      u64 v_c262 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c7 = _t[0];
        u64 v_c14 = _t[1];
        u64 v_c15 = _t[2];
        u64 v_c10 = _t[3];
        u64 v_c11 = _t[4];
        u64 v_c16 = _t[5];
        ++_fires;
        if (!((is_struct(v_c10) && (decode_struct_id(v_c10) == sid1076 || decode_struct_id(v_c10) == sid1077 || decode_struct_id(v_c10) == sid1078))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c258, v_c259, v_c260, v_c10}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c16)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c258, v_c261, v_c262, v_c16}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<4>(head_rel[2], newbatch[2], std::array<u64,3>{v_c10, v_c16, v_c11}, std::array<u16,4>{1, 2, 3, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("interp.slog:93", "delta:$sup70016x92x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1079* _cont = new ReadTask1079(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1079(db,b), false);
  // (crule (pre) (scan mp_msk_ans __t95lh295 p) (body (exists $sup5638x42x0x0x0 (4 2 3 5 0 1 6) 1 p) (join-old mp_msk (0 1 2) 1 (0 1 2) __t95lh295 k m) (join $sup5638x42x0x0x0 (1 3 4 0 2 5 6) 3 k m p __d0 l r v)) (head (emit $sup5638x42x0x0x1 (1 5 0 2 3 4 6 7) __t95lh295 p __d0 k l m r v)) map.slog:43 #f)
  class ReadTask1084 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x42x0x0x0index1080;  slog::Index** mp_mskindex1081;  slog::Index** $sup5638x42x0x0x0index1082;  slog::Index** mp_mskdelta1083;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x42x0x0x1");
      std::vector<u16> ord1085({1, 5, 0, 2, 3, 4, 6, 7});
      slog::Relation* readrel1086 = db->getRelation("$sup5638x42x0x0x1");
      head_index[0] = readrel1086->getIndex(ord1085, false);
      outer_rel = db->getRelation("mp_msk_ans");
      std::vector<u16> ord1087({4, 2, 3, 5, 0, 1, 6});
      slog::Relation* readrel1088 = db->getRelation("$sup5638x42x0x0x0");
      $sup5638x42x0x0x0index1080 = readrel1088->getIndex(ord1087, false);
      std::vector<u16> ord1089({0, 1, 2});
      slog::Relation* readrel1090 = db->getRelation("mp_msk");
      mp_mskindex1081 = readrel1090->getIndex(ord1089, false);
      std::vector<u16> ord1091({0, 1, 2});
      slog::Relation* readrel1092 = db->getRelation("mp_msk");
      mp_mskdelta1083 = readrel1092->getIndex(ord1091, true);
      std::vector<u16> ord1093({1, 3, 4, 0, 2, 5, 6});
      slog::Relation* readrel1094 = db->getRelation("$sup5638x42x0x0x0");
      $sup5638x42x0x0x0index1082 = readrel1094->getIndex(ord1093, false);
  
    }
    ReadTask1084(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c56 = _t[1];
        if (!slog::exists_probe<7,1>($sup5638x42x0x0x0index1080, std::array<u64,7>{v_c56, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(mp_mskindex1081, mp_mskdelta1083, std::array<u64,3>{v_c263, 0, 0}, [&](const std::array<u64,3>& m1095) {
          u64 v_c25 = m1095[1]; u64 v_c59 = m1095[2];
          slog::join_probe<7,3>($sup5638x42x0x0x0index1082, std::array<u64,7>{v_c25, v_c59, v_c56, 0, 0, 0, 0}, [&](const std::array<u64,7>& m1096) {
            u64 v_c7 = m1096[3]; u64 v_c58 = m1096[4]; u64 v_c24 = m1096[5]; u64 v_c22 = m1096[6];
            ++_fires;
            slog::emit<8>(head_rel[0], head_index[0], newbatch[0], std::array<u64,8>{v_c263, v_c56, v_c7, v_c25, v_c58, v_c59, v_c24, v_c22}, std::array<u16,8>{1, 5, 0, 2, 3, 4, 6, 7});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:43", "delta:mp_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask1084* _cont = new ReadTask1084(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1084(db,b), false);
  // (crule (pre (let _00024sqc4eJq915 const6b86b273ff34fce19d6b804e) (let _00024sqc7353916 const5feceb66ffc86f38d952786c) (let _00024sqc4F46917 const6b86b273ff34fce19d6b804e) (let _00024sqc6X6r918 const5feceb66ffc86f38d952786c) (let __trid8NVw1490 const3b05f339a47cf251e643e4dd) (let __trel54xq1491 constc8dd3fe14ad7db61de7362fc) (let __tcol3esC1492 constd4735e3a265e16eee03f5971)) (scan mp_put __t8uts322 rho x t) (body (exists mp_put_ans (0 1) 1 __t8uts322) (join $sup70016x47x0x0x0 (2 3 4 5 0 1) 3 rho t x xs _00024seq0 __d0) (join mp_put_ans (0 1) 1 __t8uts322 __v0) (letp _00024sql9Vv7913 (aslst _00024seq0)) (let _00024sqn4An9914 (llen _00024sql9Vv7913)) (cmp ge _00024sqn4An9914 _00024sqc4eJq915) (letp chk1Ya41914 (lref _00024sql9Vv7913 _00024sqc7353916)) (eq x chk1Ya41914) (let _00024sqp6qIB919 (_0002d _00024sqn4An9914 _00024sqc6X6r918)) (let chk5j8N1915 (lslice _00024sql9Vv7913 _00024sqc4F46917 _00024sqp6qIB919)) (eq xs chk5j8N1915)) (head (tycheck t (accept seq) __trid8NVw1490 __trel54xq1491 __tcol3esC1492 (1 2 3 4 0)) (mkstruct extend_env (1 2 3 0) __3tRX1489 __v0 xs t)) interp.slog:48 #f)
  class ReadTask1100 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_put_ansindex1097;  slog::Index** $sup70016x47x0x0x0index1098;  slog::Index** mp_put_ansindex1099;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("extend_env");
      outer_rel = db->getRelation("mp_put");
      std::vector<u16> ord1101({0, 1});
      slog::Relation* readrel1102 = db->getRelation("mp_put_ans");
      mp_put_ansindex1097 = readrel1102->getIndex(ord1101, false);
      std::vector<u16> ord1103({2, 3, 4, 5, 0, 1});
      slog::Relation* readrel1104 = db->getRelation("$sup70016x47x0x0x0");
      $sup70016x47x0x0x0index1098 = readrel1104->getIndex(ord1103, false);
      std::vector<u16> ord1105({0, 1});
      slog::Relation* readrel1106 = db->getRelation("mp_put_ans");
      mp_put_ansindex1099 = readrel1106->getIndex(ord1105, false);
  
    }
    ReadTask1100(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c264 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c265 = v_const5feceb66ffc86f38d952786c;
      u64 v_c266 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c267 = v_const5feceb66ffc86f38d952786c;
      u64 v_c268 = v_const3b05f339a47cf251e643e4dd;
      u64 v_c269 = v_constc8dd3fe14ad7db61de7362fc;
      u64 v_c270 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c271 = _t[0];
        u64 v_c10 = _t[1];
        u64 v_c16 = _t[2];
        u64 v_c11 = _t[3];
        if (!slog::exists_probe<2,1>(mp_put_ansindex1097, std::array<u64,2>{v_c271, 0})) return;
        slog::join_probe<6,3>($sup70016x47x0x0x0index1098, std::array<u64,6>{v_c10, v_c11, v_c16, 0, 0, 0}, [&](const std::array<u64,6>& m1107) {
          u64 v_c203 = m1107[3]; u64 v_c156 = m1107[4]; u64 v_c7 = m1107[5];
          slog::join_probe<2,1>(mp_put_ansindex1099, std::array<u64,2>{v_c271, 0}, [&](const std::array<u64,2>& m1108) {
            u64 v_c51 = m1108[1];
            bool ok1109 = true;
            u64 v_c272 = _prim_aslst(db, v_c156, &ok1109);
            if (!ok1109) return;
            u64 v_c273 = _prim_llen(db, v_c272);
            if (v_c273 == slog_error) { slog::emit_pending_error(db, "interp.slog:48"); return; }
            u64 v_c274 = _prim_ge(db, v_c273, v_c264);
            if (v_c274 == slog_error) { slog::emit_pending_error(db, "interp.slog:48"); return; }
            if (!v_c274) return;
            bool ok1111 = true;
            u64 v_c275 = _prim_lref(db, v_c272, v_c265, &ok1111);
            if (!ok1111) return;
            if (v_c16 != v_c275) return;
            u64 v_c276 = _prim__0002d(db, v_c273, v_c267);
            if (v_c276 == slog_error) { slog::emit_pending_error(db, "interp.slog:48"); return; }
            u64 v_c277 = _prim_lslice(db, v_c272, v_c266, v_c276);
            if (v_c277 == slog_error) { slog::emit_pending_error(db, "interp.slog:48"); return; }
            if (v_c203 != v_c277) return;
            ++_fires;
            if (!(is_seq(v_c11)))
            {
              slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c268, v_c269, v_c270, v_c11}, std::array<u16,5>{1, 2, 3, 4, 0});
              return;
            }
            slog::emit_struct<4>(head_rel[1], newbatch[1], std::array<u64,3>{v_c51, v_c203, v_c11}, std::array<u16,4>{1, 2, 3, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:48", "delta:mp_put", _fires);
  
      if (!_done)
      {
        ReadTask1100* _cont = new ReadTask1100(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1100(db,b), false);
  // (crule (pre (let __tconst58wu717 const4e07408562bedb8b60ce05c1) (let __tconst0hQe724 const6b86b273ff34fce19d6b804e) (let __tconst7lpr731 const0933fb667296882d8c45abca) (let __tconst9wm7741 const73475cb40a568e8da8a045ce) (let __tconst4vHk745 const5feceb66ffc86f38d952786c) (let __tconst1Nf0752 const90fb9068eda6f2d68bb61c33) (let __tconst5hIJ756 const3d914f9348c9cc0ff8a79716) (let __tconst6I9K760 constd59eced1ded07f84c145592f)) (scan temp58Bx1898 __t75NQ757) (body (exists num (1 0) 1 __tconst4vHk745) (exists ref (1 0) 1 __tconst9wm7741) (exists primref (1 0) 1 __tconst7lpr731) (exists ref (1 0) 1 __tconst5hIJ756) (exists num (1 0) 1 __tconst0hQe724) (exists ref (1 0) 1 __tconst6I9K760) (exists num (1 0) 1 __tconst58wu717) (join primref (1 0) 1 __tconst1Nf0752 __t6Asn753) (join num (1 0) 1 __tconst4vHk745 __t8vxv746) (join ref (1 0) 1 __tconst9wm7741 __t6TM2740) (join primref (1 0) 1 __tconst7lpr731 __t1nv4732) (join ref (1 0) 1 __tconst5hIJ756 __t64lX727) (join num (1 0) 1 __tconst0hQe724 __t8m96725) (join ref (1 0) 1 __tconst6I9K760 __t9NO9722) (join num (1 0) 1 __tconst58wu717 __t4oVz718) (let __t9E2t720 (lpush __t75NQ757 __t4oVz718)) (let __t81pk743 (lpush __t75NQ757 __tconst9wm7741)) (let __t8oLu750 (lpush __t75NQ757 __t64lX727)) (let __t8k6P758 (lpush __t75NQ757 __tconst5hIJ756))) (head (emit-temp temp775z1899 __t75NQ757 __t81pk743 __t8k6P758 __t8oLu750 __t9E2t720)) kcfa.slog:70 #f)
  class ReadTask1127 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** numindex1112;  slog::Index** refindex1113;  slog::Index** primrefindex1114;  slog::Index** refindex1115;  slog::Index** numindex1116;  slog::Index** refindex1117;  slog::Index** numindex1118;  slog::Index** primrefindex1119;  slog::Index** numindex1120;  slog::Index** refindex1121;  slog::Index** primrefindex1122;  slog::Index** refindex1123;  slog::Index** numindex1124;  slog::Index** refindex1125;  slog::Index** numindex1126;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp775z1899");
      outer_rel = db->getRelation("temp58Bx1898");
      std::vector<u16> ord1128({1, 0});
      slog::Relation* readrel1129 = db->getRelation("num");
      numindex1112 = readrel1129->getIndex(ord1128, false);
      std::vector<u16> ord1130({1, 0});
      slog::Relation* readrel1131 = db->getRelation("ref");
      refindex1113 = readrel1131->getIndex(ord1130, false);
      std::vector<u16> ord1132({1, 0});
      slog::Relation* readrel1133 = db->getRelation("primref");
      primrefindex1114 = readrel1133->getIndex(ord1132, false);
      std::vector<u16> ord1134({1, 0});
      slog::Relation* readrel1135 = db->getRelation("ref");
      refindex1115 = readrel1135->getIndex(ord1134, false);
      std::vector<u16> ord1136({1, 0});
      slog::Relation* readrel1137 = db->getRelation("num");
      numindex1116 = readrel1137->getIndex(ord1136, false);
      std::vector<u16> ord1138({1, 0});
      slog::Relation* readrel1139 = db->getRelation("ref");
      refindex1117 = readrel1139->getIndex(ord1138, false);
      std::vector<u16> ord1140({1, 0});
      slog::Relation* readrel1141 = db->getRelation("num");
      numindex1118 = readrel1141->getIndex(ord1140, false);
      std::vector<u16> ord1142({1, 0});
      slog::Relation* readrel1143 = db->getRelation("primref");
      primrefindex1119 = readrel1143->getIndex(ord1142, false);
      std::vector<u16> ord1144({1, 0});
      slog::Relation* readrel1145 = db->getRelation("num");
      numindex1120 = readrel1145->getIndex(ord1144, false);
      std::vector<u16> ord1146({1, 0});
      slog::Relation* readrel1147 = db->getRelation("ref");
      refindex1121 = readrel1147->getIndex(ord1146, false);
      std::vector<u16> ord1148({1, 0});
      slog::Relation* readrel1149 = db->getRelation("primref");
      primrefindex1122 = readrel1149->getIndex(ord1148, false);
      std::vector<u16> ord1150({1, 0});
      slog::Relation* readrel1151 = db->getRelation("ref");
      refindex1123 = readrel1151->getIndex(ord1150, false);
      std::vector<u16> ord1152({1, 0});
      slog::Relation* readrel1153 = db->getRelation("num");
      numindex1124 = readrel1153->getIndex(ord1152, false);
      std::vector<u16> ord1154({1, 0});
      slog::Relation* readrel1155 = db->getRelation("ref");
      refindex1125 = readrel1155->getIndex(ord1154, false);
      std::vector<u16> ord1156({1, 0});
      slog::Relation* readrel1157 = db->getRelation("num");
      numindex1126 = readrel1157->getIndex(ord1156, false);
  
    }
    ReadTask1127(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c278 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c279 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c280 = v_const0933fb667296882d8c45abca;
      u64 v_c281 = v_const73475cb40a568e8da8a045ce;
      u64 v_c282 = v_const5feceb66ffc86f38d952786c;
      u64 v_c283 = v_const90fb9068eda6f2d68bb61c33;
      u64 v_c284 = v_const3d914f9348c9cc0ff8a79716;
      u64 v_c285 = v_constd59eced1ded07f84c145592f;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c286 = _t[0];
        if (!slog::exists_probe<2,1>(numindex1112, std::array<u64,2>{v_c282, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1113, std::array<u64,2>{v_c281, 0})) return;
        if (!slog::exists_probe<2,1>(primrefindex1114, std::array<u64,2>{v_c280, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1115, std::array<u64,2>{v_c284, 0})) return;
        if (!slog::exists_probe<2,1>(numindex1116, std::array<u64,2>{v_c279, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1117, std::array<u64,2>{v_c285, 0})) return;
        if (!slog::exists_probe<2,1>(numindex1118, std::array<u64,2>{v_c278, 0})) return;
        slog::join_probe<2,1>(primrefindex1119, std::array<u64,2>{v_c283, 0}, [&](const std::array<u64,2>& m1158) {
          u64 v_c287 = m1158[1];
          slog::join_probe<2,1>(numindex1120, std::array<u64,2>{v_c282, 0}, [&](const std::array<u64,2>& m1159) {
            u64 v_c288 = m1159[1];
            slog::join_probe<2,1>(refindex1121, std::array<u64,2>{v_c281, 0}, [&](const std::array<u64,2>& m1160) {
              u64 v_c289 = m1160[1];
              slog::join_probe<2,1>(primrefindex1122, std::array<u64,2>{v_c280, 0}, [&](const std::array<u64,2>& m1161) {
                u64 v_c290 = m1161[1];
                slog::join_probe<2,1>(refindex1123, std::array<u64,2>{v_c284, 0}, [&](const std::array<u64,2>& m1162) {
                  u64 v_c291 = m1162[1];
                  slog::join_probe<2,1>(numindex1124, std::array<u64,2>{v_c279, 0}, [&](const std::array<u64,2>& m1163) {
                    u64 v_c292 = m1163[1];
                    slog::join_probe<2,1>(refindex1125, std::array<u64,2>{v_c285, 0}, [&](const std::array<u64,2>& m1164) {
                      u64 v_c293 = m1164[1];
                      slog::join_probe<2,1>(numindex1126, std::array<u64,2>{v_c278, 0}, [&](const std::array<u64,2>& m1165) {
                        u64 v_c294 = m1165[1];
                        u64 v_c295 = _prim_lpush(db, v_c286, v_c294);
                        if (v_c295 == slog_error) { slog::emit_pending_error(db, "kcfa.slog:70"); return; }
                        u64 v_c296 = _prim_lpush(db, v_c286, v_c281);
                        if (v_c296 == slog_error) { slog::emit_pending_error(db, "kcfa.slog:70"); return; }
                        u64 v_c297 = _prim_lpush(db, v_c286, v_c291);
                        if (v_c297 == slog_error) { slog::emit_pending_error(db, "kcfa.slog:70"); return; }
                        u64 v_c298 = _prim_lpush(db, v_c286, v_c284);
                        if (v_c298 == slog_error) { slog::emit_pending_error(db, "kcfa.slog:70"); return; }
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c286, v_c296, v_c298, v_c297, v_c295});
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
  
      if (_fires) db->bumpFires("kcfa.slog:70", "delta:temp58Bx1898", _fires);
  
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
  // (crule (pre) (scan eval __t6oYx552 ef rho t) (body (exists eval_args (3 2 0 1) 2 t rho) (exists eval_ans (0 1) 1 __t6oYx552) (join $sup70016x75x0x0x0 (1 3 4 2 0) 3 ef rho t es __d0) (join-old eval_args (1 3 2 0) 3 (1 3 2 0) es t rho __t11mn554) (exists eval_args_ans (0 1) 1 __t11mn554) (join eval_ans (0 1) 1 __t6oYx552 __t21iW553) (join eval_args_ans (0 1) 1 __t11mn554 vs) (join-old prim (0 1) 1 (0 1) __t21iW553 op)) (head (mkstruct delta (1 2 0) __5Kx31559 op vs)) interp.slog:76 #f)
  class ReadTask1176 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eval_argsindex1166;  slog::Index** eval_ansindex1167;  slog::Index** $sup70016x75x0x0x0index1168;  slog::Index** eval_argsindex1169;  slog::Index** eval_args_ansindex1170;  slog::Index** eval_ansindex1171;  slog::Index** eval_args_ansindex1172;  slog::Index** primindex1173;  slog::Index** eval_argsdelta1174;  slog::Index** primdelta1175;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("delta");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord1177({3, 2, 0, 1});
      slog::Relation* readrel1178 = db->getRelation("eval_args");
      eval_argsindex1166 = readrel1178->getIndex(ord1177, false);
      std::vector<u16> ord1179({0, 1});
      slog::Relation* readrel1180 = db->getRelation("eval_ans");
      eval_ansindex1167 = readrel1180->getIndex(ord1179, false);
      std::vector<u16> ord1181({1, 3, 4, 2, 0});
      slog::Relation* readrel1182 = db->getRelation("$sup70016x75x0x0x0");
      $sup70016x75x0x0x0index1168 = readrel1182->getIndex(ord1181, false);
      std::vector<u16> ord1183({1, 3, 2, 0});
      slog::Relation* readrel1184 = db->getRelation("eval_args");
      eval_argsindex1169 = readrel1184->getIndex(ord1183, false);
      std::vector<u16> ord1185({1, 3, 2, 0});
      slog::Relation* readrel1186 = db->getRelation("eval_args");
      eval_argsdelta1174 = readrel1186->getIndex(ord1185, true);
      std::vector<u16> ord1187({0, 1});
      slog::Relation* readrel1188 = db->getRelation("eval_args_ans");
      eval_args_ansindex1170 = readrel1188->getIndex(ord1187, false);
      std::vector<u16> ord1189({0, 1});
      slog::Relation* readrel1190 = db->getRelation("eval_ans");
      eval_ansindex1171 = readrel1190->getIndex(ord1189, false);
      std::vector<u16> ord1191({0, 1});
      slog::Relation* readrel1192 = db->getRelation("eval_args_ans");
      eval_args_ansindex1172 = readrel1192->getIndex(ord1191, false);
      std::vector<u16> ord1193({0, 1});
      slog::Relation* readrel1194 = db->getRelation("prim");
      primindex1173 = readrel1194->getIndex(ord1193, false);
      std::vector<u16> ord1195({0, 1});
      slog::Relation* readrel1196 = db->getRelation("prim");
      primdelta1175 = readrel1196->getIndex(ord1195, true);
  
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
        u64 v_c299 = _t[0];
        u64 v_c8 = _t[1];
        u64 v_c10 = _t[2];
        u64 v_c11 = _t[3];
        if (!slog::exists_probe<4,2>(eval_argsindex1166, std::array<u64,4>{v_c11, v_c10, 0, 0})) return;
        if (!slog::exists_probe<2,1>(eval_ansindex1167, std::array<u64,2>{v_c299, 0})) return;
        slog::join_probe<5,3>($sup70016x75x0x0x0index1168, std::array<u64,5>{v_c8, v_c10, v_c11, 0, 0}, [&](const std::array<u64,5>& m1197) {
          u64 v_c9 = m1197[3]; u64 v_c7 = m1197[4];
          slog::join_probe_old<4,3>(eval_argsindex1169, eval_argsdelta1174, std::array<u64,4>{v_c9, v_c11, v_c10, 0}, [&](const std::array<u64,4>& m1198) {
            u64 v_c300 = m1198[3];
            if (!slog::exists_probe<2,1>(eval_args_ansindex1170, std::array<u64,2>{v_c300, 0})) return;
            slog::join_probe<2,1>(eval_ansindex1171, std::array<u64,2>{v_c299, 0}, [&](const std::array<u64,2>& m1199) {
              u64 v_c301 = m1199[1];
              slog::join_probe<2,1>(eval_args_ansindex1172, std::array<u64,2>{v_c300, 0}, [&](const std::array<u64,2>& m1200) {
                u64 v_c208 = m1200[1];
                slog::join_probe_old<2,1>(primindex1173, primdelta1175, std::array<u64,2>{v_c301, 0}, [&](const std::array<u64,2>& m1201) {
                  u64 v_c302 = m1201[1];
                  ++_fires;
                  slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c302, v_c208}, std::array<u16,3>{1, 2, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:76", "delta:eval", _fires);
  
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
  // (crule (pre (let _00024sqc7DnB839 const6b86b273ff34fce19d6b804e) (let _00024sqc4H0B840 const5feceb66ffc86f38d952786c) (let _00024sqc58w2841 const6b86b273ff34fce19d6b804e) (let _00024sqc7wgB842 const5feceb66ffc86f38d952786c) (let _00024sqo31L8847 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo31L8847 x _00024seq0) (body (letp _00024sql00Zd837 (aslst _00024seq0)) (let _00024sqn2cl5838 (llen _00024sql00Zd837)) (cmp ge _00024sqn2cl5838 _00024sqc7DnB839) (let _00024sqp8r44843 (_0002d _00024sqn2cl5838 _00024sqc7wgB842)) (let xs (lslice _00024sql00Zd837 _00024sqc58w2841 _00024sqp8r44843)) (exists extend_env (2 3 0 1) 1 _00024seq0) (exists mp_put (2 3 0 1) 1 x) (exists extend_env (2 3 0 1) 1 xs) (join $sup70016x47x0x0x0 (0 4 5 1 2 3) 3 _00024seq0 x xs __t2ugT17 rho t) (join extend_env (0 2 3 1) 4 __t2ugT17 _00024seq0 t rho) (exists extend_env (2 3 0 1) 2 xs t) (join mp_put (1 2 3 0) 3 rho x t __t42Fa18) (exists mp_put_ans (0 1) 1 __t42Fa18) (join extend_env (2 3 0 1) 2 xs t __t8zl419 __v0) (join mp_put_ans (0 1) 2 __t42Fa18 __v0) (join extend_env_ans (0 1) 1 __t8zl419 __v1) (letp chk7q3Q1831 (lref _00024sql00Zd837 _00024sqc4H0B840)) (eq x chk7q3Q1831)) (head (emit extend_env_ans (0 1) __t2ugT17 __v1)) interp.slog:48 #f)
  class ReadTask1213 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** extend_envindex1202;  slog::Index** mp_putindex1203;  slog::Index** extend_envindex1204;  slog::Index** $sup70016x47x0x0x0index1205;  slog::Index** extend_envindex1206;  slog::Index** extend_envindex1207;  slog::Index** mp_putindex1208;  slog::Index** mp_put_ansindex1209;  slog::Index** extend_envindex1210;  slog::Index** mp_put_ansindex1211;  slog::Index** extend_env_ansindex1212;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("extend_env_ans");
      std::vector<u16> ord1214({0, 1});
      slog::Relation* readrel1215 = db->getRelation("extend_env_ans");
      head_index[0] = readrel1215->getIndex(ord1214, false);
      std::vector<u16> ord1216({1, 0, 2});
      slog::Relation* readrel1217 = db->getRelation("$seq_at");
      driver_index = readrel1217->getIndex(ord1216, true);
      std::vector<u16> ord1218({2, 3, 0, 1});
      slog::Relation* readrel1219 = db->getRelation("extend_env");
      extend_envindex1202 = readrel1219->getIndex(ord1218, false);
      std::vector<u16> ord1220({2, 3, 0, 1});
      slog::Relation* readrel1221 = db->getRelation("mp_put");
      mp_putindex1203 = readrel1221->getIndex(ord1220, false);
      std::vector<u16> ord1222({2, 3, 0, 1});
      slog::Relation* readrel1223 = db->getRelation("extend_env");
      extend_envindex1204 = readrel1223->getIndex(ord1222, false);
      std::vector<u16> ord1224({0, 4, 5, 1, 2, 3});
      slog::Relation* readrel1225 = db->getRelation("$sup70016x47x0x0x0");
      $sup70016x47x0x0x0index1205 = readrel1225->getIndex(ord1224, false);
      std::vector<u16> ord1226({0, 2, 3, 1});
      slog::Relation* readrel1227 = db->getRelation("extend_env");
      extend_envindex1206 = readrel1227->getIndex(ord1226, false);
      std::vector<u16> ord1228({2, 3, 0, 1});
      slog::Relation* readrel1229 = db->getRelation("extend_env");
      extend_envindex1207 = readrel1229->getIndex(ord1228, false);
      std::vector<u16> ord1230({1, 2, 3, 0});
      slog::Relation* readrel1231 = db->getRelation("mp_put");
      mp_putindex1208 = readrel1231->getIndex(ord1230, false);
      std::vector<u16> ord1232({0, 1});
      slog::Relation* readrel1233 = db->getRelation("mp_put_ans");
      mp_put_ansindex1209 = readrel1233->getIndex(ord1232, false);
      std::vector<u16> ord1234({2, 3, 0, 1});
      slog::Relation* readrel1235 = db->getRelation("extend_env");
      extend_envindex1210 = readrel1235->getIndex(ord1234, false);
      std::vector<u16> ord1236({0, 1});
      slog::Relation* readrel1237 = db->getRelation("mp_put_ans");
      mp_put_ansindex1211 = readrel1237->getIndex(ord1236, false);
      std::vector<u16> ord1238({0, 1});
      slog::Relation* readrel1239 = db->getRelation("extend_env_ans");
      extend_env_ansindex1212 = readrel1239->getIndex(ord1238, false);
  
    }
    ReadTask1213(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c213 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c214 = v_const5feceb66ffc86f38d952786c;
      u64 v_c215 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c216 = v_const5feceb66ffc86f38d952786c;
      u64 v_c217 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c217, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1240) {
        u64 v_c16 = m1240[1];
        u64 v_c156 = m1240[2];
        if (buckethash(v_c16) != bucket) return;
        bool ok1241 = true;
        u64 v_c219 = _prim_aslst(db, v_c156, &ok1241);
        if (!ok1241) return;
        u64 v_c220 = _prim_llen(db, v_c219);
        if (v_c220 == slog_error) { slog::emit_pending_error(db, "interp.slog:48"); return; }
        u64 v_c303 = _prim_ge(db, v_c220, v_c213);
        if (v_c303 == slog_error) { slog::emit_pending_error(db, "interp.slog:48"); return; }
        if (!v_c303) return;
        u64 v_c222 = _prim__0002d(db, v_c220, v_c216);
        if (v_c222 == slog_error) { slog::emit_pending_error(db, "interp.slog:48"); return; }
        u64 v_c203 = _prim_lslice(db, v_c219, v_c215, v_c222);
        if (v_c203 == slog_error) { slog::emit_pending_error(db, "interp.slog:48"); return; }
        if (!slog::exists_probe<4,1>(extend_envindex1202, std::array<u64,4>{v_c156, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(mp_putindex1203, std::array<u64,4>{v_c16, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(extend_envindex1204, std::array<u64,4>{v_c203, 0, 0, 0})) return;
        slog::join_probe<6,3>($sup70016x47x0x0x0index1205, std::array<u64,6>{v_c156, v_c16, v_c203, 0, 0, 0}, [&](const std::array<u64,6>& m1243) {
          u64 v_c223 = m1243[3]; u64 v_c10 = m1243[4]; u64 v_c11 = m1243[5];
          slog::join_probe<4,4>(extend_envindex1206, std::array<u64,4>{v_c223, v_c156, v_c11, v_c10}, [&](const std::array<u64,4>& m1244) {
            if (!slog::exists_probe<4,2>(extend_envindex1207, std::array<u64,4>{v_c203, v_c11, 0, 0})) return;
            slog::join_probe<4,3>(mp_putindex1208, std::array<u64,4>{v_c10, v_c16, v_c11, 0}, [&](const std::array<u64,4>& m1245) {
              u64 v_c224 = m1245[3];
              if (!slog::exists_probe<2,1>(mp_put_ansindex1209, std::array<u64,2>{v_c224, 0})) return;
              slog::join_probe<4,2>(extend_envindex1210, std::array<u64,4>{v_c203, v_c11, 0, 0}, [&](const std::array<u64,4>& m1246) {
                u64 v_c218 = m1246[2]; u64 v_c51 = m1246[3];
                slog::join_probe<2,2>(mp_put_ansindex1211, std::array<u64,2>{v_c224, v_c51}, [&](const std::array<u64,2>& m1247) {
                  slog::join_probe<2,1>(extend_env_ansindex1212, std::array<u64,2>{v_c218, 0}, [&](const std::array<u64,2>& m1248) {
                    u64 v_c84 = m1248[1];
                    bool ok1249 = true;
                    u64 v_c304 = _prim_lref(db, v_c219, v_c214, &ok1249);
                    if (!ok1249) return;
                    if (v_c16 != v_c304) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c223, v_c84}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:48", "delta:$seq_at", _fires);
  
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
  // (crule (pre) (scan eval __t7GLg670 er rho t) (body (exists $sup70016x92x0x0x1 (1 5 6 7 8 0 2 3 4 9) 4 __t7GLg670 er rho t) (exists mp_put (1 3 0 2) 2 rho t) (exists let (2 0 1 3) 1 er) (exists eval (2 3 0 1) 2 rho t) (exists eval (3 1 0 2) 1 t) (exists eval_ans (0 1) 1 __t7GLg670) (join $sup70016x92x0x0x0 (2 3 4 0 1 5) 3 er rho t __t5vg0669 eb x) (exists mp_put (1 2 3 0) 3 rho x t) (exists let (1 2 3 0) 3 x er eb) (exists eval (2 3 0 1) 3 rho t __t5vg0669) (exists eval (3 1 0 2) 2 t eb) (join $sup70016x92x0x0x1 (0 6 7 4 5 9 1 2 3 8) 7 __t5vg0669 rho t eb er x __t7GLg670 __t0mp6672 __v0 vr) (join-old mp_put (0 2 1 3) 4 (0 2 1 3) __t0mp6672 x rho t) (exists eval (1 2 3 0) 3 eb __v0 t) (exists eval_ans (0 1) 2 __t7GLg670 vr) (exists mp_put_ans (0 1) 2 __t0mp6672 __v0) (join let (1 2 3 0) 3 x er eb __t2w2P668) (join eval (2 3 0 1) 4 rho t __t5vg0669 __t2w2P668) (join-old eval (1 2 3 0) 3 (1 2 3 0) eb __v0 t __t3BcP671) (join eval_ans (0 1) 2 __t7GLg670 vr) (join mp_put_ans (0 1) 2 __t0mp6672 __v0) (join eval_ans (0 1) 1 __t3BcP671 v)) (head (emit eval_ans (0 1) __t5vg0669 v)) interp.slog:93 #f)
  class ReadTask1274 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup70016x92x0x0x1index1250;  slog::Index** mp_putindex1251;  slog::Index** letindex1252;  slog::Index** evalindex1253;  slog::Index** evalindex1254;  slog::Index** eval_ansindex1255;  slog::Index** $sup70016x92x0x0x0index1256;  slog::Index** mp_putindex1257;  slog::Index** letindex1258;  slog::Index** evalindex1259;  slog::Index** evalindex1260;  slog::Index** $sup70016x92x0x0x1index1261;  slog::Index** mp_putindex1262;  slog::Index** evalindex1263;  slog::Index** eval_ansindex1264;  slog::Index** mp_put_ansindex1265;  slog::Index** letindex1266;  slog::Index** evalindex1267;  slog::Index** evalindex1268;  slog::Index** eval_ansindex1269;  slog::Index** mp_put_ansindex1270;  slog::Index** eval_ansindex1271;  slog::Index** mp_putdelta1272;  slog::Index** evaldelta1273;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1275({0, 1});
      slog::Relation* readrel1276 = db->getRelation("eval_ans");
      head_index[0] = readrel1276->getIndex(ord1275, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord1277({1, 5, 6, 7, 8, 0, 2, 3, 4, 9});
      slog::Relation* readrel1278 = db->getRelation("$sup70016x92x0x0x1");
      $sup70016x92x0x0x1index1250 = readrel1278->getIndex(ord1277, false);
      std::vector<u16> ord1279({1, 3, 0, 2});
      slog::Relation* readrel1280 = db->getRelation("mp_put");
      mp_putindex1251 = readrel1280->getIndex(ord1279, false);
      std::vector<u16> ord1281({2, 0, 1, 3});
      slog::Relation* readrel1282 = db->getRelation("let");
      letindex1252 = readrel1282->getIndex(ord1281, false);
      std::vector<u16> ord1283({2, 3, 0, 1});
      slog::Relation* readrel1284 = db->getRelation("eval");
      evalindex1253 = readrel1284->getIndex(ord1283, false);
      std::vector<u16> ord1285({3, 1, 0, 2});
      slog::Relation* readrel1286 = db->getRelation("eval");
      evalindex1254 = readrel1286->getIndex(ord1285, false);
      std::vector<u16> ord1287({0, 1});
      slog::Relation* readrel1288 = db->getRelation("eval_ans");
      eval_ansindex1255 = readrel1288->getIndex(ord1287, false);
      std::vector<u16> ord1289({2, 3, 4, 0, 1, 5});
      slog::Relation* readrel1290 = db->getRelation("$sup70016x92x0x0x0");
      $sup70016x92x0x0x0index1256 = readrel1290->getIndex(ord1289, false);
      std::vector<u16> ord1291({1, 2, 3, 0});
      slog::Relation* readrel1292 = db->getRelation("mp_put");
      mp_putindex1257 = readrel1292->getIndex(ord1291, false);
      std::vector<u16> ord1293({1, 2, 3, 0});
      slog::Relation* readrel1294 = db->getRelation("let");
      letindex1258 = readrel1294->getIndex(ord1293, false);
      std::vector<u16> ord1295({2, 3, 0, 1});
      slog::Relation* readrel1296 = db->getRelation("eval");
      evalindex1259 = readrel1296->getIndex(ord1295, false);
      std::vector<u16> ord1297({3, 1, 0, 2});
      slog::Relation* readrel1298 = db->getRelation("eval");
      evalindex1260 = readrel1298->getIndex(ord1297, false);
      std::vector<u16> ord1299({0, 6, 7, 4, 5, 9, 1, 2, 3, 8});
      slog::Relation* readrel1300 = db->getRelation("$sup70016x92x0x0x1");
      $sup70016x92x0x0x1index1261 = readrel1300->getIndex(ord1299, false);
      std::vector<u16> ord1301({0, 2, 1, 3});
      slog::Relation* readrel1302 = db->getRelation("mp_put");
      mp_putindex1262 = readrel1302->getIndex(ord1301, false);
      std::vector<u16> ord1303({0, 2, 1, 3});
      slog::Relation* readrel1304 = db->getRelation("mp_put");
      mp_putdelta1272 = readrel1304->getIndex(ord1303, true);
      std::vector<u16> ord1305({1, 2, 3, 0});
      slog::Relation* readrel1306 = db->getRelation("eval");
      evalindex1263 = readrel1306->getIndex(ord1305, false);
      std::vector<u16> ord1307({0, 1});
      slog::Relation* readrel1308 = db->getRelation("eval_ans");
      eval_ansindex1264 = readrel1308->getIndex(ord1307, false);
      std::vector<u16> ord1309({0, 1});
      slog::Relation* readrel1310 = db->getRelation("mp_put_ans");
      mp_put_ansindex1265 = readrel1310->getIndex(ord1309, false);
      std::vector<u16> ord1311({1, 2, 3, 0});
      slog::Relation* readrel1312 = db->getRelation("let");
      letindex1266 = readrel1312->getIndex(ord1311, false);
      std::vector<u16> ord1313({2, 3, 0, 1});
      slog::Relation* readrel1314 = db->getRelation("eval");
      evalindex1267 = readrel1314->getIndex(ord1313, false);
      std::vector<u16> ord1315({1, 2, 3, 0});
      slog::Relation* readrel1316 = db->getRelation("eval");
      evalindex1268 = readrel1316->getIndex(ord1315, false);
      std::vector<u16> ord1317({1, 2, 3, 0});
      slog::Relation* readrel1318 = db->getRelation("eval");
      evaldelta1273 = readrel1318->getIndex(ord1317, true);
      std::vector<u16> ord1319({0, 1});
      slog::Relation* readrel1320 = db->getRelation("eval_ans");
      eval_ansindex1269 = readrel1320->getIndex(ord1319, false);
      std::vector<u16> ord1321({0, 1});
      slog::Relation* readrel1322 = db->getRelation("mp_put_ans");
      mp_put_ansindex1270 = readrel1322->getIndex(ord1321, false);
      std::vector<u16> ord1323({0, 1});
      slog::Relation* readrel1324 = db->getRelation("eval_ans");
      eval_ansindex1271 = readrel1324->getIndex(ord1323, false);
  
    }
    ReadTask1274(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c305 = _t[0];
        u64 v_c15 = _t[1];
        u64 v_c10 = _t[2];
        u64 v_c11 = _t[3];
        if (!slog::exists_probe<10,4>($sup70016x92x0x0x1index1250, std::array<u64,10>{v_c305, v_c15, v_c10, v_c11, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<4,2>(mp_putindex1251, std::array<u64,4>{v_c10, v_c11, 0, 0})) return;
        if (!slog::exists_probe<4,1>(letindex1252, std::array<u64,4>{v_c15, 0, 0, 0})) return;
        if (!slog::exists_probe<4,2>(evalindex1253, std::array<u64,4>{v_c10, v_c11, 0, 0})) return;
        if (!slog::exists_probe<4,1>(evalindex1254, std::array<u64,4>{v_c11, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(eval_ansindex1255, std::array<u64,2>{v_c305, 0})) return;
        slog::join_probe<6,3>($sup70016x92x0x0x0index1256, std::array<u64,6>{v_c15, v_c10, v_c11, 0, 0, 0}, [&](const std::array<u64,6>& m1325) {
          u64 v_c306 = m1325[3]; u64 v_c14 = m1325[4]; u64 v_c16 = m1325[5];
          if (!slog::exists_probe<4,3>(mp_putindex1257, std::array<u64,4>{v_c10, v_c16, v_c11, 0})) return;
          if (!slog::exists_probe<4,3>(letindex1258, std::array<u64,4>{v_c16, v_c15, v_c14, 0})) return;
          if (!slog::exists_probe<4,3>(evalindex1259, std::array<u64,4>{v_c10, v_c11, v_c306, 0})) return;
          if (!slog::exists_probe<4,2>(evalindex1260, std::array<u64,4>{v_c11, v_c14, 0, 0})) return;
          slog::join_probe<10,7>($sup70016x92x0x0x1index1261, std::array<u64,10>{v_c306, v_c10, v_c11, v_c14, v_c15, v_c16, v_c305, 0, 0, 0}, [&](const std::array<u64,10>& m1326) {
            u64 v_c307 = m1326[7]; u64 v_c51 = m1326[8]; u64 v_c21 = m1326[9];
            slog::join_probe_old<4,4>(mp_putindex1262, mp_putdelta1272, std::array<u64,4>{v_c307, v_c16, v_c10, v_c11}, [&](const std::array<u64,4>& m1327) {
              if (!slog::exists_probe<4,3>(evalindex1263, std::array<u64,4>{v_c14, v_c51, v_c11, 0})) return;
              if (!slog::exists_probe<2,2>(eval_ansindex1264, std::array<u64,2>{v_c305, v_c21})) return;
              if (!slog::exists_probe<2,2>(mp_put_ansindex1265, std::array<u64,2>{v_c307, v_c51})) return;
              slog::join_probe<4,3>(letindex1266, std::array<u64,4>{v_c16, v_c15, v_c14, 0}, [&](const std::array<u64,4>& m1328) {
                u64 v_c308 = m1328[3];
                slog::join_probe<4,4>(evalindex1267, std::array<u64,4>{v_c10, v_c11, v_c306, v_c308}, [&](const std::array<u64,4>& m1329) {
                  slog::join_probe_old<4,3>(evalindex1268, evaldelta1273, std::array<u64,4>{v_c14, v_c51, v_c11, 0}, [&](const std::array<u64,4>& m1330) {
                    u64 v_c309 = m1330[3];
                    slog::join_probe<2,2>(eval_ansindex1269, std::array<u64,2>{v_c305, v_c21}, [&](const std::array<u64,2>& m1331) {
                      slog::join_probe<2,2>(mp_put_ansindex1270, std::array<u64,2>{v_c307, v_c51}, [&](const std::array<u64,2>& m1332) {
                        slog::join_probe<2,1>(eval_ansindex1271, std::array<u64,2>{v_c309, 0}, [&](const std::array<u64,2>& m1333) {
                          u64 v_c22 = m1333[1];
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c306, v_c22}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:93", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask1274* _cont = new ReadTask1274(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1274(db,b), false);
  // (crule (pre) (scan temp7z5q1838 __t6qCW547 b) (body (join boolval (1 0) 1 b __t1Eis545)) (head (emit delta_ans (0 1) __t6qCW547 __t1Eis545)) interp.slog:126 #f)
  class ReadTask1335 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** boolvalindex1334;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("delta_ans");
      std::vector<u16> ord1336({0, 1});
      slog::Relation* readrel1337 = db->getRelation("delta_ans");
      head_index[0] = readrel1337->getIndex(ord1336, false);
      outer_rel = db->getRelation("temp7z5q1838");
      std::vector<u16> ord1338({1, 0});
      slog::Relation* readrel1339 = db->getRelation("boolval");
      boolvalindex1334 = readrel1339->getIndex(ord1338, false);
  
    }
    ReadTask1335(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c41 = _t[0];
        u64 v_c44 = _t[1];
        slog::join_probe<2,1>(boolvalindex1334, std::array<u64,2>{v_c44, 0}, [&](const std::array<u64,2>& m1340) {
          u64 v_c310 = m1340[1];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c41, v_c310}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:126", "delta:temp7z5q1838", _fires);
  
      if (!_done)
      {
        ReadTask1335* _cont = new ReadTask1335(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1335(db,b), false);
  // (crule (pre) (scan $sup70016x51x0x0x0 __d0 ef es rho t) (body (exists eval_args (1 3 2 0) 3 es t rho) (exists app (1 2 0) 2 ef es) (exists tick (2 0 1) 1 t) (join-old eval (1 2 3 0) 3 (1 2 3 0) ef rho t __t1jZw263) (exists eval_ans (0 1) 1 __t1jZw263) (join-old eval_args (1 3 2 0) 3 (1 3 2 0) es t rho __t2ycT266) (exists eval_args_ans (0 1) 1 __t2ycT266) (join-old app (1 2 0) 2 (1 2 0) ef es __t4H6p267) (join-old tick (1 2 0) 2 (1 2 0) __t4H6p267 t __t8A6X268) (exists tick_ans (0 1) 1 __t8A6X268) (join-old eval_ans (0 1) 1 (0 1) __t1jZw263 __t5Yru265) (join-old eval_args_ans (0 1) 1 (0 1) __t2ycT266 vs) (join-old tick_ans (0 1) 1 (0 1) __t8A6X268 t2) (join-old closure (0 1 2) 1 (0 1 2) __t5Yru265 __t3Nsh264 rhoc) (join-old lambda (0 1 2) 1 (0 1 2) __t3Nsh264 xs eb)) (head (emit $sup70016x51x0x0x1 (1 8 0 2 3 4 5 6 7 9 10 11 12) __t1jZw263 rhoc __d0 __t2ycT266 __t8A6X268 eb ef es rho t t2 vs xs)) interp.slog:52 #f)
  class ReadTask1365 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eval_argsindex1341;  slog::Index** appindex1342;  slog::Index** tickindex1343;  slog::Index** evalindex1344;  slog::Index** eval_ansindex1345;  slog::Index** eval_argsindex1346;  slog::Index** eval_args_ansindex1347;  slog::Index** appindex1348;  slog::Index** tickindex1349;  slog::Index** tick_ansindex1350;  slog::Index** eval_ansindex1351;  slog::Index** eval_args_ansindex1352;  slog::Index** tick_ansindex1353;  slog::Index** closureindex1354;  slog::Index** lambdaindex1355;  slog::Index** evaldelta1356;  slog::Index** eval_argsdelta1357;  slog::Index** appdelta1358;  slog::Index** tickdelta1359;  slog::Index** eval_ansdelta1360;  slog::Index** eval_args_ansdelta1361;  slog::Index** tick_ansdelta1362;  slog::Index** closuredelta1363;  slog::Index** lambdadelta1364;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup70016x51x0x0x1");
      std::vector<u16> ord1366({1, 8, 0, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12});
      slog::Relation* readrel1367 = db->getRelation("$sup70016x51x0x0x1");
      head_index[0] = readrel1367->getIndex(ord1366, false);
      outer_rel = db->getRelation("$sup70016x51x0x0x0");
      std::vector<u16> ord1368({1, 3, 2, 0});
      slog::Relation* readrel1369 = db->getRelation("eval_args");
      eval_argsindex1341 = readrel1369->getIndex(ord1368, false);
      std::vector<u16> ord1370({1, 2, 0});
      slog::Relation* readrel1371 = db->getRelation("app");
      appindex1342 = readrel1371->getIndex(ord1370, false);
      std::vector<u16> ord1372({2, 0, 1});
      slog::Relation* readrel1373 = db->getRelation("tick");
      tickindex1343 = readrel1373->getIndex(ord1372, false);
      std::vector<u16> ord1374({1, 2, 3, 0});
      slog::Relation* readrel1375 = db->getRelation("eval");
      evalindex1344 = readrel1375->getIndex(ord1374, false);
      std::vector<u16> ord1376({1, 2, 3, 0});
      slog::Relation* readrel1377 = db->getRelation("eval");
      evaldelta1356 = readrel1377->getIndex(ord1376, true);
      std::vector<u16> ord1378({0, 1});
      slog::Relation* readrel1379 = db->getRelation("eval_ans");
      eval_ansindex1345 = readrel1379->getIndex(ord1378, false);
      std::vector<u16> ord1380({1, 3, 2, 0});
      slog::Relation* readrel1381 = db->getRelation("eval_args");
      eval_argsindex1346 = readrel1381->getIndex(ord1380, false);
      std::vector<u16> ord1382({1, 3, 2, 0});
      slog::Relation* readrel1383 = db->getRelation("eval_args");
      eval_argsdelta1357 = readrel1383->getIndex(ord1382, true);
      std::vector<u16> ord1384({0, 1});
      slog::Relation* readrel1385 = db->getRelation("eval_args_ans");
      eval_args_ansindex1347 = readrel1385->getIndex(ord1384, false);
      std::vector<u16> ord1386({1, 2, 0});
      slog::Relation* readrel1387 = db->getRelation("app");
      appindex1348 = readrel1387->getIndex(ord1386, false);
      std::vector<u16> ord1388({1, 2, 0});
      slog::Relation* readrel1389 = db->getRelation("app");
      appdelta1358 = readrel1389->getIndex(ord1388, true);
      std::vector<u16> ord1390({1, 2, 0});
      slog::Relation* readrel1391 = db->getRelation("tick");
      tickindex1349 = readrel1391->getIndex(ord1390, false);
      std::vector<u16> ord1392({1, 2, 0});
      slog::Relation* readrel1393 = db->getRelation("tick");
      tickdelta1359 = readrel1393->getIndex(ord1392, true);
      std::vector<u16> ord1394({0, 1});
      slog::Relation* readrel1395 = db->getRelation("tick_ans");
      tick_ansindex1350 = readrel1395->getIndex(ord1394, false);
      std::vector<u16> ord1396({0, 1});
      slog::Relation* readrel1397 = db->getRelation("eval_ans");
      eval_ansindex1351 = readrel1397->getIndex(ord1396, false);
      std::vector<u16> ord1398({0, 1});
      slog::Relation* readrel1399 = db->getRelation("eval_ans");
      eval_ansdelta1360 = readrel1399->getIndex(ord1398, true);
      std::vector<u16> ord1400({0, 1});
      slog::Relation* readrel1401 = db->getRelation("eval_args_ans");
      eval_args_ansindex1352 = readrel1401->getIndex(ord1400, false);
      std::vector<u16> ord1402({0, 1});
      slog::Relation* readrel1403 = db->getRelation("eval_args_ans");
      eval_args_ansdelta1361 = readrel1403->getIndex(ord1402, true);
      std::vector<u16> ord1404({0, 1});
      slog::Relation* readrel1405 = db->getRelation("tick_ans");
      tick_ansindex1353 = readrel1405->getIndex(ord1404, false);
      std::vector<u16> ord1406({0, 1});
      slog::Relation* readrel1407 = db->getRelation("tick_ans");
      tick_ansdelta1362 = readrel1407->getIndex(ord1406, true);
      std::vector<u16> ord1408({0, 1, 2});
      slog::Relation* readrel1409 = db->getRelation("closure");
      closureindex1354 = readrel1409->getIndex(ord1408, false);
      std::vector<u16> ord1410({0, 1, 2});
      slog::Relation* readrel1411 = db->getRelation("closure");
      closuredelta1363 = readrel1411->getIndex(ord1410, true);
      std::vector<u16> ord1412({0, 1, 2});
      slog::Relation* readrel1413 = db->getRelation("lambda");
      lambdaindex1355 = readrel1413->getIndex(ord1412, false);
      std::vector<u16> ord1414({0, 1, 2});
      slog::Relation* readrel1415 = db->getRelation("lambda");
      lambdadelta1364 = readrel1415->getIndex(ord1414, true);
  
    }
    ReadTask1365(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c7 = _t[0];
        u64 v_c8 = _t[1];
        u64 v_c9 = _t[2];
        u64 v_c10 = _t[3];
        u64 v_c11 = _t[4];
        if (!slog::exists_probe<4,3>(eval_argsindex1341, std::array<u64,4>{v_c9, v_c11, v_c10, 0})) return;
        if (!slog::exists_probe<3,2>(appindex1342, std::array<u64,3>{v_c8, v_c9, 0})) return;
        if (!slog::exists_probe<3,1>(tickindex1343, std::array<u64,3>{v_c11, 0, 0})) return;
        slog::join_probe_old<4,3>(evalindex1344, evaldelta1356, std::array<u64,4>{v_c8, v_c10, v_c11, 0}, [&](const std::array<u64,4>& m1416) {
          u64 v_c311 = m1416[3];
          if (!slog::exists_probe<2,1>(eval_ansindex1345, std::array<u64,2>{v_c311, 0})) return;
          slog::join_probe_old<4,3>(eval_argsindex1346, eval_argsdelta1357, std::array<u64,4>{v_c9, v_c11, v_c10, 0}, [&](const std::array<u64,4>& m1417) {
            u64 v_c312 = m1417[3];
            if (!slog::exists_probe<2,1>(eval_args_ansindex1347, std::array<u64,2>{v_c312, 0})) return;
            slog::join_probe_old<3,2>(appindex1348, appdelta1358, std::array<u64,3>{v_c8, v_c9, 0}, [&](const std::array<u64,3>& m1418) {
              u64 v_c313 = m1418[2];
              slog::join_probe_old<3,2>(tickindex1349, tickdelta1359, std::array<u64,3>{v_c313, v_c11, 0}, [&](const std::array<u64,3>& m1419) {
                u64 v_c314 = m1419[2];
                if (!slog::exists_probe<2,1>(tick_ansindex1350, std::array<u64,2>{v_c314, 0})) return;
                slog::join_probe_old<2,1>(eval_ansindex1351, eval_ansdelta1360, std::array<u64,2>{v_c311, 0}, [&](const std::array<u64,2>& m1420) {
                  u64 v_c315 = m1420[1];
                  slog::join_probe_old<2,1>(eval_args_ansindex1352, eval_args_ansdelta1361, std::array<u64,2>{v_c312, 0}, [&](const std::array<u64,2>& m1421) {
                    u64 v_c208 = m1421[1];
                    slog::join_probe_old<2,1>(tick_ansindex1353, tick_ansdelta1362, std::array<u64,2>{v_c314, 0}, [&](const std::array<u64,2>& m1422) {
                      u64 v_c209 = m1422[1];
                      slog::join_probe_old<3,1>(closureindex1354, closuredelta1363, std::array<u64,3>{v_c315, 0, 0}, [&](const std::array<u64,3>& m1423) {
                        u64 v_c316 = m1423[1]; u64 v_c201 = m1423[2];
                        slog::join_probe_old<3,1>(lambdaindex1355, lambdadelta1364, std::array<u64,3>{v_c316, 0, 0}, [&](const std::array<u64,3>& m1424) {
                          u64 v_c203 = m1424[1]; u64 v_c14 = m1424[2];
                          ++_fires;
                          slog::emit<13>(head_rel[0], head_index[0], newbatch[0], std::array<u64,13>{v_c311, v_c201, v_c7, v_c312, v_c314, v_c14, v_c8, v_c9, v_c10, v_c11, v_c209, v_c208, v_c203}, std::array<u16,13>{1, 8, 0, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12});
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
  
      if (_fires) db->bumpFires("interp.slog:52", "delta:$sup70016x51x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1365* _cont = new ReadTask1365(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1365(db,b), false);
  // (crule (pre) (scan $sup5638x98x0x0x0 __d0 l m n p q r u v) (body (exists mp_msk_ans (1 0) 1 p) (join-old mp_msk (1 2 0) 2 (1 2 0) q m __t51z5346) (join-old mp_msk_ans (0 1) 2 (0 1) __t51z5346 p)) (head (emit $sup5638x98x0x0x1 (0 7 1 2 3 4 5 6 8 9) __d0 r __t51z5346 l m n p q u v)) map.slog:99 #f)
  class ReadTask1430 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_msk_ansindex1425;  slog::Index** mp_mskindex1426;  slog::Index** mp_msk_ansindex1427;  slog::Index** mp_mskdelta1428;  slog::Index** mp_msk_ansdelta1429;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x98x0x0x1");
      std::vector<u16> ord1431({0, 7, 1, 2, 3, 4, 5, 6, 8, 9});
      slog::Relation* readrel1432 = db->getRelation("$sup5638x98x0x0x1");
      head_index[0] = readrel1432->getIndex(ord1431, false);
      outer_rel = db->getRelation("$sup5638x98x0x0x0");
      std::vector<u16> ord1433({1, 0});
      slog::Relation* readrel1434 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1425 = readrel1434->getIndex(ord1433, false);
      std::vector<u16> ord1435({1, 2, 0});
      slog::Relation* readrel1436 = db->getRelation("mp_msk");
      mp_mskindex1426 = readrel1436->getIndex(ord1435, false);
      std::vector<u16> ord1437({1, 2, 0});
      slog::Relation* readrel1438 = db->getRelation("mp_msk");
      mp_mskdelta1428 = readrel1438->getIndex(ord1437, true);
      std::vector<u16> ord1439({0, 1});
      slog::Relation* readrel1440 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1427 = readrel1440->getIndex(ord1439, false);
      std::vector<u16> ord1441({0, 1});
      slog::Relation* readrel1442 = db->getRelation("mp_msk_ans");
      mp_msk_ansdelta1429 = readrel1442->getIndex(ord1441, true);
  
    }
    ReadTask1430(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c7 = _t[0];
        u64 v_c58 = _t[1];
        u64 v_c59 = _t[2];
        u64 v_c57 = _t[3];
        u64 v_c56 = _t[4];
        u64 v_c55 = _t[5];
        u64 v_c24 = _t[6];
        u64 v_c60 = _t[7];
        u64 v_c22 = _t[8];
        if (!slog::exists_probe<2,1>(mp_msk_ansindex1425, std::array<u64,2>{v_c56, 0})) return;
        slog::join_probe_old<3,2>(mp_mskindex1426, mp_mskdelta1428, std::array<u64,3>{v_c55, v_c59, 0}, [&](const std::array<u64,3>& m1443) {
          u64 v_c317 = m1443[2];
          slog::join_probe_old<2,2>(mp_msk_ansindex1427, mp_msk_ansdelta1429, std::array<u64,2>{v_c317, v_c56}, [&](const std::array<u64,2>& m1444) {
            ++_fires;
            slog::emit<10>(head_rel[0], head_index[0], newbatch[0], std::array<u64,10>{v_c7, v_c24, v_c317, v_c58, v_c59, v_c57, v_c56, v_c55, v_c60, v_c22}, std::array<u16,10>{0, 7, 1, 2, 3, 4, 5, 6, 8, 9});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:99", "delta:$sup5638x98x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1430* _cont = new ReadTask1430(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1430(db,b), false);
  // (crule (pre (let __tconst8VYR1133 constd01925b37634a1a9d24159d8)) (scan mp_union __t2icL823 __t17tk822 t) (body (join _enum (0 1) 2 __t17tk822 __tconst8VYR1133)) (head (emit mp_union_ans (0 1) __t2icL823 t)) map.slog:90 #f)
  class ReadTask1446 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex1445;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord1447({0, 1});
      slog::Relation* readrel1448 = db->getRelation("mp_union_ans");
      head_index[0] = readrel1448->getIndex(ord1447, false);
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord1449({0, 1});
      slog::Relation* readrel1450 = db->getRelation("_enum");
      _enumindex1445 = readrel1450->getIndex(ord1449, false);
  
    }
    ReadTask1446(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c318 = v_constd01925b37634a1a9d24159d8;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c319 = _t[0];
        u64 v_c320 = _t[1];
        u64 v_c11 = _t[2];
        slog::join_probe<2,2>(_enumindex1445, std::array<u64,2>{v_c320, v_c318}, [&](const std::array<u64,2>& m1451) {
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c319, v_c11}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:90", "delta:mp_union", _fires);
  
      if (!_done)
      {
        ReadTask1446* _cont = new ReadTask1446(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1446(db,b), false);
  // (crule (pre (let __trid7W6n1448 constc742e02805b99df617265a41) (let __trel3FLX1449 constdd7bbf31ce5f578b9805e840) (let __tcol0rmE1450 const5feceb66ffc86f38d952786c) (let __trel0fxR1451 constdd7bbf31ce5f578b9805e840) (let __tcol9wbA1452 const6b86b273ff34fce19d6b804e)) (scan $sup5638x95x0x0x0 __d0 l m n p q r u v) (body) (head (tycheck q (accept int) __trid7W6n1448 __trel3FLX1449 __tcol0rmE1450 (1 2 3 4 0)) (tycheck m (accept int) __trid7W6n1448 __trel0fxR1451 __tcol9wbA1452 (1 2 3 4 0)) (mkstruct mp_msk (1 2 0) __0YJG1447 q m)) map.slog:96 #f)
  class ReadTask1452 : public slog::Task
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
      outer_rel = db->getRelation("$sup5638x95x0x0x0");
  
    }
    ReadTask1452(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c321 = v_constc742e02805b99df617265a41;
      u64 v_c322 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c323 = v_const5feceb66ffc86f38d952786c;
      u64 v_c324 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c325 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c7 = _t[0];
        u64 v_c58 = _t[1];
        u64 v_c59 = _t[2];
        u64 v_c57 = _t[3];
        u64 v_c56 = _t[4];
        u64 v_c55 = _t[5];
        u64 v_c24 = _t[6];
        u64 v_c60 = _t[7];
        u64 v_c22 = _t[8];
        ++_fires;
        if (!(is_int(v_c55)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c321, v_c322, v_c323, v_c55}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c59)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c321, v_c324, v_c325, v_c59}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c55, v_c59}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:96", "delta:$sup5638x95x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1452* _cont = new ReadTask1452(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1452(db,b), false);
  // (crule (pre) (scan mp_join_ans __t6UVn392 res) (body (join-old mp_join (0 1 2 3 4) 1 (0 1 2 3 4) __t6UVn392 p __t6AX6390 q __t46nL391) (exists mbranch (0 1 2 3 4) 2 __t6AX6390 p) (exists mbranch (0 1 2 3 4) 2 __t46nL391 q) (exists mp_union (1 2 0) 2 __t6AX6390 __t46nL391) (exists mp_msk (1 2 0) 1 p) (join-old $sup5638x110x0x0x0 (4 5 7 8 0 1 2 3 6 9 10) 4 (4 5 7 8 0 1 2 3 6 9 10) p q __t6AX6390 __t46nL391 __t5Qtl389 l m n r u v) (cmp lt m n) (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) p m l r __t6AX6390) (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) q n u v __t46nL391) (join-old mp_union (0 1 2) 3 (0 1 2) __t5Qtl389 __t6AX6390 __t46nL391) (join-old mp_msk (1 2 0) 2 (1 2 0) p n __t827P393) (join-old mp_msk_ans (0 1) 1 (0 1) __t827P393 __v0) (neq q __v0)) (head (emit mp_union_ans (0 1) __t5Qtl389 res)) map.slog:111 #f)
  class ReadTask1471 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_joinindex1453;  slog::Index** mbranchindex1454;  slog::Index** mbranchindex1455;  slog::Index** mp_unionindex1456;  slog::Index** mp_mskindex1457;  slog::Index** $sup5638x110x0x0x0index1458;  slog::Index** mbranchindex1459;  slog::Index** mbranchindex1460;  slog::Index** mp_unionindex1461;  slog::Index** mp_mskindex1462;  slog::Index** mp_msk_ansindex1463;  slog::Index** mp_joindelta1464;  slog::Index** $sup5638x110x0x0x0delta1465;  slog::Index** mbranchdelta1466;  slog::Index** mbranchdelta1467;  slog::Index** mp_uniondelta1468;  slog::Index** mp_mskdelta1469;  slog::Index** mp_msk_ansdelta1470;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord1472({0, 1});
      slog::Relation* readrel1473 = db->getRelation("mp_union_ans");
      head_index[0] = readrel1473->getIndex(ord1472, false);
      outer_rel = db->getRelation("mp_join_ans");
      std::vector<u16> ord1474({0, 1, 2, 3, 4});
      slog::Relation* readrel1475 = db->getRelation("mp_join");
      mp_joinindex1453 = readrel1475->getIndex(ord1474, false);
      std::vector<u16> ord1476({0, 1, 2, 3, 4});
      slog::Relation* readrel1477 = db->getRelation("mp_join");
      mp_joindelta1464 = readrel1477->getIndex(ord1476, true);
      std::vector<u16> ord1478({0, 1, 2, 3, 4});
      slog::Relation* readrel1479 = db->getRelation("mbranch");
      mbranchindex1454 = readrel1479->getIndex(ord1478, false);
      std::vector<u16> ord1480({0, 1, 2, 3, 4});
      slog::Relation* readrel1481 = db->getRelation("mbranch");
      mbranchindex1455 = readrel1481->getIndex(ord1480, false);
      std::vector<u16> ord1482({1, 2, 0});
      slog::Relation* readrel1483 = db->getRelation("mp_union");
      mp_unionindex1456 = readrel1483->getIndex(ord1482, false);
      std::vector<u16> ord1484({1, 2, 0});
      slog::Relation* readrel1485 = db->getRelation("mp_msk");
      mp_mskindex1457 = readrel1485->getIndex(ord1484, false);
      std::vector<u16> ord1486({4, 5, 7, 8, 0, 1, 2, 3, 6, 9, 10});
      slog::Relation* readrel1487 = db->getRelation("$sup5638x110x0x0x0");
      $sup5638x110x0x0x0index1458 = readrel1487->getIndex(ord1486, false);
      std::vector<u16> ord1488({4, 5, 7, 8, 0, 1, 2, 3, 6, 9, 10});
      slog::Relation* readrel1489 = db->getRelation("$sup5638x110x0x0x0");
      $sup5638x110x0x0x0delta1465 = readrel1489->getIndex(ord1488, true);
      std::vector<u16> ord1490({1, 2, 3, 4, 0});
      slog::Relation* readrel1491 = db->getRelation("mbranch");
      mbranchindex1459 = readrel1491->getIndex(ord1490, false);
      std::vector<u16> ord1492({1, 2, 3, 4, 0});
      slog::Relation* readrel1493 = db->getRelation("mbranch");
      mbranchdelta1466 = readrel1493->getIndex(ord1492, true);
      std::vector<u16> ord1494({1, 2, 3, 4, 0});
      slog::Relation* readrel1495 = db->getRelation("mbranch");
      mbranchindex1460 = readrel1495->getIndex(ord1494, false);
      std::vector<u16> ord1496({1, 2, 3, 4, 0});
      slog::Relation* readrel1497 = db->getRelation("mbranch");
      mbranchdelta1467 = readrel1497->getIndex(ord1496, true);
      std::vector<u16> ord1498({0, 1, 2});
      slog::Relation* readrel1499 = db->getRelation("mp_union");
      mp_unionindex1461 = readrel1499->getIndex(ord1498, false);
      std::vector<u16> ord1500({0, 1, 2});
      slog::Relation* readrel1501 = db->getRelation("mp_union");
      mp_uniondelta1468 = readrel1501->getIndex(ord1500, true);
      std::vector<u16> ord1502({1, 2, 0});
      slog::Relation* readrel1503 = db->getRelation("mp_msk");
      mp_mskindex1462 = readrel1503->getIndex(ord1502, false);
      std::vector<u16> ord1504({1, 2, 0});
      slog::Relation* readrel1505 = db->getRelation("mp_msk");
      mp_mskdelta1469 = readrel1505->getIndex(ord1504, true);
      std::vector<u16> ord1506({0, 1});
      slog::Relation* readrel1507 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1463 = readrel1507->getIndex(ord1506, false);
      std::vector<u16> ord1508({0, 1});
      slog::Relation* readrel1509 = db->getRelation("mp_msk_ans");
      mp_msk_ansdelta1470 = readrel1509->getIndex(ord1508, true);
  
    }
    ReadTask1471(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c326 = _t[0];
        u64 v_c196 = _t[1];
        slog::join_probe_old<5,1>(mp_joinindex1453, mp_joindelta1464, std::array<u64,5>{v_c326, 0, 0, 0, 0}, [&](const std::array<u64,5>& m1510) {
          u64 v_c56 = m1510[1]; u64 v_c327 = m1510[2]; u64 v_c55 = m1510[3]; u64 v_c328 = m1510[4];
          if (!slog::exists_probe<5,2>(mbranchindex1454, std::array<u64,5>{v_c327, v_c56, 0, 0, 0})) return;
          if (!slog::exists_probe<5,2>(mbranchindex1455, std::array<u64,5>{v_c328, v_c55, 0, 0, 0})) return;
          if (!slog::exists_probe<3,2>(mp_unionindex1456, std::array<u64,3>{v_c327, v_c328, 0})) return;
          if (!slog::exists_probe<3,1>(mp_mskindex1457, std::array<u64,3>{v_c56, 0, 0})) return;
          slog::join_probe_old<11,4>($sup5638x110x0x0x0index1458, $sup5638x110x0x0x0delta1465, std::array<u64,11>{v_c56, v_c55, v_c327, v_c328, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m1511) {
            u64 v_c329 = m1511[4]; u64 v_c58 = m1511[5]; u64 v_c59 = m1511[6]; u64 v_c57 = m1511[7]; u64 v_c24 = m1511[8]; u64 v_c60 = m1511[9]; u64 v_c22 = m1511[10];
            u64 v_c330 = _prim_lt(db, v_c59, v_c57);
            if (v_c330 == slog_error) { slog::emit_pending_error(db, "map.slog:111"); return; }
            if (!v_c330) return;
            slog::join_probe_old<5,5>(mbranchindex1459, mbranchdelta1466, std::array<u64,5>{v_c56, v_c59, v_c58, v_c24, v_c327}, [&](const std::array<u64,5>& m1513) {
              slog::join_probe_old<5,5>(mbranchindex1460, mbranchdelta1467, std::array<u64,5>{v_c55, v_c57, v_c60, v_c22, v_c328}, [&](const std::array<u64,5>& m1514) {
                slog::join_probe_old<3,3>(mp_unionindex1461, mp_uniondelta1468, std::array<u64,3>{v_c329, v_c327, v_c328}, [&](const std::array<u64,3>& m1515) {
                  slog::join_probe_old<3,2>(mp_mskindex1462, mp_mskdelta1469, std::array<u64,3>{v_c56, v_c57, 0}, [&](const std::array<u64,3>& m1516) {
                    u64 v_c331 = m1516[2];
                    slog::join_probe_old<2,1>(mp_msk_ansindex1463, mp_msk_ansdelta1470, std::array<u64,2>{v_c331, 0}, [&](const std::array<u64,2>& m1517) {
                      u64 v_c51 = m1517[1];
                      if (v_c55 == v_c51) return;
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c329, v_c196}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:111", "delta:mp_join_ans", _fires);
  
      if (!_done)
      {
        ReadTask1471* _cont = new ReadTask1471(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1471(db,b), false);
  // (crule (pre) (scan mp_msk_ans __t2nZc836 __v0) (body (join-old mp_msk (0 1 2) 1 (0 1 2) __t2nZc836 k m) (exists $sup5638x44x0x0x0 (1 3 7 0 2 4 5 6) 2 k m) (exists mbranch (2 0 1 3 4) 1 m) (exists mp_put (2 3 0 1) 1 k) (exists mp_join (1 2 3 4 0) 1 k) (join-old mleaf (1 2 0) 1 (1 2 0) k v __t5lKq834) (exists mp_put (2 3 0 1) 2 k v) (exists mp_join (1 2 3 4 0) 2 k __t5lKq834) (join-old $sup5638x44x0x0x0 (1 3 7 0 2 4 5 6) 3 (1 3 7 0 2 4 5 6) k m v __t6Fc5832 l p r __t6oBk833) (neq p __v0) (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) p m l r __t6oBk833) (join-old mp_put (0 2 1 3) 4 (0 2 1 3) __t6Fc5832 k __t6oBk833 v) (join-old mp_join (1 2 3 4 0) 4 (1 2 3 4 0) k __t5lKq834 p __t6oBk833 __t6jFY835) (join mp_join_ans (0 1) 1 __t6jFY835 res)) (head (emit mp_put_ans (0 1) __t6Fc5832 res)) map.slog:45 #f)
  class ReadTask1537 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_mskindex1518;  slog::Index** $sup5638x44x0x0x0index1519;  slog::Index** mbranchindex1520;  slog::Index** mp_putindex1521;  slog::Index** mp_joinindex1522;  slog::Index** mleafindex1523;  slog::Index** mp_putindex1524;  slog::Index** mp_joinindex1525;  slog::Index** $sup5638x44x0x0x0index1526;  slog::Index** mbranchindex1527;  slog::Index** mp_putindex1528;  slog::Index** mp_joinindex1529;  slog::Index** mp_join_ansindex1530;  slog::Index** mp_mskdelta1531;  slog::Index** mleafdelta1532;  slog::Index** $sup5638x44x0x0x0delta1533;  slog::Index** mbranchdelta1534;  slog::Index** mp_putdelta1535;  slog::Index** mp_joindelta1536;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_ans");
      std::vector<u16> ord1538({0, 1});
      slog::Relation* readrel1539 = db->getRelation("mp_put_ans");
      head_index[0] = readrel1539->getIndex(ord1538, false);
      outer_rel = db->getRelation("mp_msk_ans");
      std::vector<u16> ord1540({0, 1, 2});
      slog::Relation* readrel1541 = db->getRelation("mp_msk");
      mp_mskindex1518 = readrel1541->getIndex(ord1540, false);
      std::vector<u16> ord1542({0, 1, 2});
      slog::Relation* readrel1543 = db->getRelation("mp_msk");
      mp_mskdelta1531 = readrel1543->getIndex(ord1542, true);
      std::vector<u16> ord1544({1, 3, 7, 0, 2, 4, 5, 6});
      slog::Relation* readrel1545 = db->getRelation("$sup5638x44x0x0x0");
      $sup5638x44x0x0x0index1519 = readrel1545->getIndex(ord1544, false);
      std::vector<u16> ord1546({2, 0, 1, 3, 4});
      slog::Relation* readrel1547 = db->getRelation("mbranch");
      mbranchindex1520 = readrel1547->getIndex(ord1546, false);
      std::vector<u16> ord1548({2, 3, 0, 1});
      slog::Relation* readrel1549 = db->getRelation("mp_put");
      mp_putindex1521 = readrel1549->getIndex(ord1548, false);
      std::vector<u16> ord1550({1, 2, 3, 4, 0});
      slog::Relation* readrel1551 = db->getRelation("mp_join");
      mp_joinindex1522 = readrel1551->getIndex(ord1550, false);
      std::vector<u16> ord1552({1, 2, 0});
      slog::Relation* readrel1553 = db->getRelation("mleaf");
      mleafindex1523 = readrel1553->getIndex(ord1552, false);
      std::vector<u16> ord1554({1, 2, 0});
      slog::Relation* readrel1555 = db->getRelation("mleaf");
      mleafdelta1532 = readrel1555->getIndex(ord1554, true);
      std::vector<u16> ord1556({2, 3, 0, 1});
      slog::Relation* readrel1557 = db->getRelation("mp_put");
      mp_putindex1524 = readrel1557->getIndex(ord1556, false);
      std::vector<u16> ord1558({1, 2, 3, 4, 0});
      slog::Relation* readrel1559 = db->getRelation("mp_join");
      mp_joinindex1525 = readrel1559->getIndex(ord1558, false);
      std::vector<u16> ord1560({1, 3, 7, 0, 2, 4, 5, 6});
      slog::Relation* readrel1561 = db->getRelation("$sup5638x44x0x0x0");
      $sup5638x44x0x0x0index1526 = readrel1561->getIndex(ord1560, false);
      std::vector<u16> ord1562({1, 3, 7, 0, 2, 4, 5, 6});
      slog::Relation* readrel1563 = db->getRelation("$sup5638x44x0x0x0");
      $sup5638x44x0x0x0delta1533 = readrel1563->getIndex(ord1562, true);
      std::vector<u16> ord1564({1, 2, 3, 4, 0});
      slog::Relation* readrel1565 = db->getRelation("mbranch");
      mbranchindex1527 = readrel1565->getIndex(ord1564, false);
      std::vector<u16> ord1566({1, 2, 3, 4, 0});
      slog::Relation* readrel1567 = db->getRelation("mbranch");
      mbranchdelta1534 = readrel1567->getIndex(ord1566, true);
      std::vector<u16> ord1568({0, 2, 1, 3});
      slog::Relation* readrel1569 = db->getRelation("mp_put");
      mp_putindex1528 = readrel1569->getIndex(ord1568, false);
      std::vector<u16> ord1570({0, 2, 1, 3});
      slog::Relation* readrel1571 = db->getRelation("mp_put");
      mp_putdelta1535 = readrel1571->getIndex(ord1570, true);
      std::vector<u16> ord1572({1, 2, 3, 4, 0});
      slog::Relation* readrel1573 = db->getRelation("mp_join");
      mp_joinindex1529 = readrel1573->getIndex(ord1572, false);
      std::vector<u16> ord1574({1, 2, 3, 4, 0});
      slog::Relation* readrel1575 = db->getRelation("mp_join");
      mp_joindelta1536 = readrel1575->getIndex(ord1574, true);
      std::vector<u16> ord1576({0, 1});
      slog::Relation* readrel1577 = db->getRelation("mp_join_ans");
      mp_join_ansindex1530 = readrel1577->getIndex(ord1576, false);
  
    }
    ReadTask1537(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c332 = _t[0];
        u64 v_c51 = _t[1];
        slog::join_probe_old<3,1>(mp_mskindex1518, mp_mskdelta1531, std::array<u64,3>{v_c332, 0, 0}, [&](const std::array<u64,3>& m1578) {
          u64 v_c25 = m1578[1]; u64 v_c59 = m1578[2];
          if (!slog::exists_probe<8,2>($sup5638x44x0x0x0index1519, std::array<u64,8>{v_c25, v_c59, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>(mbranchindex1520, std::array<u64,5>{v_c59, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<4,1>(mp_putindex1521, std::array<u64,4>{v_c25, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>(mp_joinindex1522, std::array<u64,5>{v_c25, 0, 0, 0, 0})) return;
          slog::join_probe_old<3,1>(mleafindex1523, mleafdelta1532, std::array<u64,3>{v_c25, 0, 0}, [&](const std::array<u64,3>& m1579) {
            u64 v_c22 = m1579[1]; u64 v_c333 = m1579[2];
            if (!slog::exists_probe<4,2>(mp_putindex1524, std::array<u64,4>{v_c25, v_c22, 0, 0})) return;
            if (!slog::exists_probe<5,2>(mp_joinindex1525, std::array<u64,5>{v_c25, v_c333, 0, 0, 0})) return;
            slog::join_probe_old<8,3>($sup5638x44x0x0x0index1526, $sup5638x44x0x0x0delta1533, std::array<u64,8>{v_c25, v_c59, v_c22, 0, 0, 0, 0, 0}, [&](const std::array<u64,8>& m1580) {
              u64 v_c334 = m1580[3]; u64 v_c58 = m1580[4]; u64 v_c56 = m1580[5]; u64 v_c24 = m1580[6]; u64 v_c335 = m1580[7];
              if (v_c56 == v_c51) return;
              slog::join_probe_old<5,5>(mbranchindex1527, mbranchdelta1534, std::array<u64,5>{v_c56, v_c59, v_c58, v_c24, v_c335}, [&](const std::array<u64,5>& m1581) {
                slog::join_probe_old<4,4>(mp_putindex1528, mp_putdelta1535, std::array<u64,4>{v_c334, v_c25, v_c335, v_c22}, [&](const std::array<u64,4>& m1582) {
                  slog::join_probe_old<5,4>(mp_joinindex1529, mp_joindelta1536, std::array<u64,5>{v_c25, v_c333, v_c56, v_c335, 0}, [&](const std::array<u64,5>& m1583) {
                    u64 v_c336 = m1583[4];
                    slog::join_probe<2,1>(mp_join_ansindex1530, std::array<u64,2>{v_c336, 0}, [&](const std::array<u64,2>& m1584) {
                      u64 v_c196 = m1584[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c334, v_c196}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:45", "delta:mp_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask1537* _cont = new ReadTask1537(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1537(db,b), false);
}

