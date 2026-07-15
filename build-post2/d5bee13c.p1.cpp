
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const06abaa100ecef791ce028c56;
extern u64 v_const0bbd2fbd1dc4200473343503;
extern u64 v_const11445e6556bc59ce1e80cdf7;
extern u64 v_const1ca60a80dbae6414bef23d65;
extern u64 v_const20347926ddb307a8e2bdb71b;
extern u64 v_const4a59dbb9cb3129dfcc75170b;
extern u64 v_const4e07408562bedb8b60ce05c1;
extern u64 v_const5d6ab4fefffae2e4c15033db;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const6c3d8aa344844f80a370de02;
extern u64 v_const8c6798fa821ed573f6b89759;
extern u64 v_consta24220c5193376967f1fa95e;
extern u64 v_consta9707d158296ad63d61ac4f7;
extern u64 v_constaa218622af4adb846b2d6244;
extern u64 v_constcd2a69ce5ca278db1d6da969;
extern u64 v_constd01925b37634a1a9d24159d8;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_constdd7bbf31ce5f578b9805e840;
extern u64 v_constdede4476644eb06b5a48b866;
extern u64 v_constf6cdc3db4b71e0cdeda6912e;
extern u64 v_constfdb0a95399e17c48d6f65653;
extern u64 v_constfee494ff4827aeb0635bb714;


void slog_rules_c1f75f668b44d76de(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre (let __trid9n3x1549 const5d6ab4fefffae2e4c15033db) (let __trel5eWq1550 const4a59dbb9cb3129dfcc75170b) (let __tcol6eZ31551 constd4735e3a265e16eee03f5971)) (scan mp_put_ans __t9Rkj767 rho2) (body (join-old mp_put (0 2 1 3) 1 (0 2 1 3) __t9Rkj767 x rho t) (exists letrec (1 2 3 0) 1 x) (join eval (2 3 0 1) 2 rho t __9QsM1547 __t7vAU766) (join-old letrec (0 1 2 3) 2 (0 1 2 3) __t7vAU766 x er eb)) (head (tycheck t (accept seq) __trid9n3x1549 __trel5eWq1550 __tcol6eZ31551 (1 2 3 4 0)) (mkstruct eval (1 2 3 0) __6xaV1548 er rho2 t)) interp.slog:98 #f)
  class ReadTask6 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_putindex0;  slog::Index** letrecindex1;  slog::Index** evalindex2;  slog::Index** letrecindex3;  slog::Index** mp_putdelta4;  slog::Index** letrecdelta5;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("eval");
      outer_rel = db->getRelation("mp_put_ans");
      std::vector<u16> ord7({0, 2, 1, 3});
      slog::Relation* readrel8 = db->getRelation("mp_put");
      mp_putindex0 = readrel8->getIndex(ord7, false);
      std::vector<u16> ord9({0, 2, 1, 3});
      slog::Relation* readrel10 = db->getRelation("mp_put");
      mp_putdelta4 = readrel10->getIndex(ord9, true);
      std::vector<u16> ord11({1, 2, 3, 0});
      slog::Relation* readrel12 = db->getRelation("letrec");
      letrecindex1 = readrel12->getIndex(ord11, false);
      std::vector<u16> ord13({2, 3, 0, 1});
      slog::Relation* readrel14 = db->getRelation("eval");
      evalindex2 = readrel14->getIndex(ord13, false);
      std::vector<u16> ord15({0, 1, 2, 3});
      slog::Relation* readrel16 = db->getRelation("letrec");
      letrecindex3 = readrel16->getIndex(ord15, false);
      std::vector<u16> ord17({0, 1, 2, 3});
      slog::Relation* readrel18 = db->getRelation("letrec");
      letrecdelta5 = readrel18->getIndex(ord17, true);
  
    }
    ReadTask6(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const5d6ab4fefffae2e4c15033db;
      u64 v_c1 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c2 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c3 = _t[0];
        u64 v_c4 = _t[1];
        slog::join_probe_old<4,1>(mp_putindex0, mp_putdelta4, std::array<u64,4>{v_c3, 0, 0, 0}, [&](const std::array<u64,4>& m19) {
          u64 v_c5 = m19[1]; u64 v_c6 = m19[2]; u64 v_c7 = m19[3];
          if (!slog::exists_probe<4,1>(letrecindex1, std::array<u64,4>{v_c5, 0, 0, 0})) return;
          slog::join_probe<4,2>(evalindex2, std::array<u64,4>{v_c6, v_c7, 0, 0}, [&](const std::array<u64,4>& m20) {
            u64 v_c8 = m20[2]; u64 v_c9 = m20[3];
            slog::join_probe_old<4,2>(letrecindex3, letrecdelta5, std::array<u64,4>{v_c9, v_c5, 0, 0}, [&](const std::array<u64,4>& m21) {
              u64 v_c10 = m21[2]; u64 v_c11 = m21[3];
              ++_fires;
              if (!(is_seq(v_c7)))
              {
                slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c0, v_c1, v_c2, v_c7}, std::array<u16,5>{1, 2, 3, 4, 0});
                return;
              }
              slog::emit_struct<4>(head_rel[1], newbatch[1], std::array<u64,3>{v_c10, v_c4, v_c7}, std::array<u16,4>{1, 2, 3, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:98", "delta:mp_put_ans", _fires);
  
      if (!_done)
      {
        ReadTask6* _cont = new ReadTask6(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask6(db,b), false);
  // (crule (pre) (scan $sup70016x51x0x0x1 __t2z6s532 __t5qy8533 __t2srV536 __t0CD9539 eb ef es rho rhoc t t2 vs xs) (body (join $sup70016x51x0x0x0 (4 0 3 1 2) 5 t __t2z6s532 rho ef es) (join-old eval (2 3 0 1) 4 (2 3 0 1) rho t __t5qy8533 ef) (join-old eval_args (3 2 0 1) 4 (3 2 0 1) t rho __t2srV536 es) (exists app (1 2 0) 2 ef es) (exists tick (0 2 1) 2 __t0CD9539 t) (exists extend_env (1 2 3 0) 3 rhoc xs t2) (exists eval_args_ans (0 1) 2 __t2srV536 vs) (exists tick_ans (0 1) 2 __t0CD9539 t2) (exists lambda (1 2 0) 2 xs eb) (exists closure (2 0 1) 1 rhoc) (exists eval_ans (0 1) 1 __t5qy8533) (exists eval (3 1 0 2) 2 t2 eb) (join-old eval (2 3 0 1) 3 (2 3 0 1) rho t __t2z6s532 __t5a7h538) (join-old app (0 1 2) 3 (0 1 2) __t5a7h538 ef es) (join-old tick (0 2 1) 3 (0 2 1) __t0CD9539 t __t5a7h538) (join-old extend_env (1 2 3 0) 3 (1 2 3 0) rhoc xs t2 __t5fzh540) (join eval_args_ans (0 1) 2 __t2srV536 vs) (join tick_ans (0 1) 2 __t0CD9539 t2) (exists extend_env_ans (0 1) 1 __t5fzh540) (join-old lambda (1 2 0) 2 (1 2 0) xs eb __t6iPm534) (join-old closure (1 2 0) 2 (1 2 0) __t6iPm534 rhoc __t9dfl535) (join eval_ans (0 1) 2 __t5qy8533 __t9dfl535) (join-old eval (3 1 0 2) 2 (3 1 0 2) t2 eb __t7TaT537 __v0) (join extend_env_ans (0 1) 2 __t5fzh540 __v0) (join eval_ans (0 1) 1 __t7TaT537 v)) (head (emit eval_ans (0 1) __t2z6s532 v)) interp.slog:52 #f)
  class ReadTask56 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup70016x51x0x0x0index22;  slog::Index** evalindex23;  slog::Index** eval_argsindex24;  slog::Index** appindex25;  slog::Index** tickindex26;  slog::Index** extend_envindex27;  slog::Index** eval_args_ansindex28;  slog::Index** tick_ansindex29;  slog::Index** lambdaindex30;  slog::Index** closureindex31;  slog::Index** eval_ansindex32;  slog::Index** evalindex33;  slog::Index** evalindex34;  slog::Index** appindex35;  slog::Index** tickindex36;  slog::Index** extend_envindex37;  slog::Index** eval_args_ansindex38;  slog::Index** tick_ansindex39;  slog::Index** extend_env_ansindex40;  slog::Index** lambdaindex41;  slog::Index** closureindex42;  slog::Index** eval_ansindex43;  slog::Index** evalindex44;  slog::Index** extend_env_ansindex45;  slog::Index** eval_ansindex46;  slog::Index** evaldelta47;  slog::Index** eval_argsdelta48;  slog::Index** evaldelta49;  slog::Index** appdelta50;  slog::Index** tickdelta51;  slog::Index** extend_envdelta52;  slog::Index** lambdadelta53;  slog::Index** closuredelta54;  slog::Index** evaldelta55;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord57({0, 1});
      slog::Relation* readrel58 = db->getRelation("eval_ans");
      head_index[0] = readrel58->getIndex(ord57, false);
      outer_rel = db->getRelation("$sup70016x51x0x0x1");
      std::vector<u16> ord59({4, 0, 3, 1, 2});
      slog::Relation* readrel60 = db->getRelation("$sup70016x51x0x0x0");
      $sup70016x51x0x0x0index22 = readrel60->getIndex(ord59, false);
      std::vector<u16> ord61({2, 3, 0, 1});
      slog::Relation* readrel62 = db->getRelation("eval");
      evalindex23 = readrel62->getIndex(ord61, false);
      std::vector<u16> ord63({2, 3, 0, 1});
      slog::Relation* readrel64 = db->getRelation("eval");
      evaldelta47 = readrel64->getIndex(ord63, true);
      std::vector<u16> ord65({3, 2, 0, 1});
      slog::Relation* readrel66 = db->getRelation("eval_args");
      eval_argsindex24 = readrel66->getIndex(ord65, false);
      std::vector<u16> ord67({3, 2, 0, 1});
      slog::Relation* readrel68 = db->getRelation("eval_args");
      eval_argsdelta48 = readrel68->getIndex(ord67, true);
      std::vector<u16> ord69({1, 2, 0});
      slog::Relation* readrel70 = db->getRelation("app");
      appindex25 = readrel70->getIndex(ord69, false);
      std::vector<u16> ord71({0, 2, 1});
      slog::Relation* readrel72 = db->getRelation("tick");
      tickindex26 = readrel72->getIndex(ord71, false);
      std::vector<u16> ord73({1, 2, 3, 0});
      slog::Relation* readrel74 = db->getRelation("extend_env");
      extend_envindex27 = readrel74->getIndex(ord73, false);
      std::vector<u16> ord75({0, 1});
      slog::Relation* readrel76 = db->getRelation("eval_args_ans");
      eval_args_ansindex28 = readrel76->getIndex(ord75, false);
      std::vector<u16> ord77({0, 1});
      slog::Relation* readrel78 = db->getRelation("tick_ans");
      tick_ansindex29 = readrel78->getIndex(ord77, false);
      std::vector<u16> ord79({1, 2, 0});
      slog::Relation* readrel80 = db->getRelation("lambda");
      lambdaindex30 = readrel80->getIndex(ord79, false);
      std::vector<u16> ord81({2, 0, 1});
      slog::Relation* readrel82 = db->getRelation("closure");
      closureindex31 = readrel82->getIndex(ord81, false);
      std::vector<u16> ord83({0, 1});
      slog::Relation* readrel84 = db->getRelation("eval_ans");
      eval_ansindex32 = readrel84->getIndex(ord83, false);
      std::vector<u16> ord85({3, 1, 0, 2});
      slog::Relation* readrel86 = db->getRelation("eval");
      evalindex33 = readrel86->getIndex(ord85, false);
      std::vector<u16> ord87({2, 3, 0, 1});
      slog::Relation* readrel88 = db->getRelation("eval");
      evalindex34 = readrel88->getIndex(ord87, false);
      std::vector<u16> ord89({2, 3, 0, 1});
      slog::Relation* readrel90 = db->getRelation("eval");
      evaldelta49 = readrel90->getIndex(ord89, true);
      std::vector<u16> ord91({0, 1, 2});
      slog::Relation* readrel92 = db->getRelation("app");
      appindex35 = readrel92->getIndex(ord91, false);
      std::vector<u16> ord93({0, 1, 2});
      slog::Relation* readrel94 = db->getRelation("app");
      appdelta50 = readrel94->getIndex(ord93, true);
      std::vector<u16> ord95({0, 2, 1});
      slog::Relation* readrel96 = db->getRelation("tick");
      tickindex36 = readrel96->getIndex(ord95, false);
      std::vector<u16> ord97({0, 2, 1});
      slog::Relation* readrel98 = db->getRelation("tick");
      tickdelta51 = readrel98->getIndex(ord97, true);
      std::vector<u16> ord99({1, 2, 3, 0});
      slog::Relation* readrel100 = db->getRelation("extend_env");
      extend_envindex37 = readrel100->getIndex(ord99, false);
      std::vector<u16> ord101({1, 2, 3, 0});
      slog::Relation* readrel102 = db->getRelation("extend_env");
      extend_envdelta52 = readrel102->getIndex(ord101, true);
      std::vector<u16> ord103({0, 1});
      slog::Relation* readrel104 = db->getRelation("eval_args_ans");
      eval_args_ansindex38 = readrel104->getIndex(ord103, false);
      std::vector<u16> ord105({0, 1});
      slog::Relation* readrel106 = db->getRelation("tick_ans");
      tick_ansindex39 = readrel106->getIndex(ord105, false);
      std::vector<u16> ord107({0, 1});
      slog::Relation* readrel108 = db->getRelation("extend_env_ans");
      extend_env_ansindex40 = readrel108->getIndex(ord107, false);
      std::vector<u16> ord109({1, 2, 0});
      slog::Relation* readrel110 = db->getRelation("lambda");
      lambdaindex41 = readrel110->getIndex(ord109, false);
      std::vector<u16> ord111({1, 2, 0});
      slog::Relation* readrel112 = db->getRelation("lambda");
      lambdadelta53 = readrel112->getIndex(ord111, true);
      std::vector<u16> ord113({1, 2, 0});
      slog::Relation* readrel114 = db->getRelation("closure");
      closureindex42 = readrel114->getIndex(ord113, false);
      std::vector<u16> ord115({1, 2, 0});
      slog::Relation* readrel116 = db->getRelation("closure");
      closuredelta54 = readrel116->getIndex(ord115, true);
      std::vector<u16> ord117({0, 1});
      slog::Relation* readrel118 = db->getRelation("eval_ans");
      eval_ansindex43 = readrel118->getIndex(ord117, false);
      std::vector<u16> ord119({3, 1, 0, 2});
      slog::Relation* readrel120 = db->getRelation("eval");
      evalindex44 = readrel120->getIndex(ord119, false);
      std::vector<u16> ord121({3, 1, 0, 2});
      slog::Relation* readrel122 = db->getRelation("eval");
      evaldelta55 = readrel122->getIndex(ord121, true);
      std::vector<u16> ord123({0, 1});
      slog::Relation* readrel124 = db->getRelation("extend_env_ans");
      extend_env_ansindex45 = readrel124->getIndex(ord123, false);
      std::vector<u16> ord125({0, 1});
      slog::Relation* readrel126 = db->getRelation("eval_ans");
      eval_ansindex46 = readrel126->getIndex(ord125, false);
  
    }
    ReadTask56(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c14 = _t[2];
        u64 v_c15 = _t[3];
        u64 v_c11 = _t[4];
        u64 v_c16 = _t[5];
        u64 v_c17 = _t[6];
        u64 v_c6 = _t[7];
        u64 v_c18 = _t[8];
        u64 v_c7 = _t[9];
        u64 v_c19 = _t[10];
        u64 v_c20 = _t[11];
        u64 v_c21 = _t[12];
        slog::join_probe<5,5>($sup70016x51x0x0x0index22, std::array<u64,5>{v_c7, v_c12, v_c6, v_c16, v_c17}, [&](const std::array<u64,5>& m127) {
          slog::join_probe_old<4,4>(evalindex23, evaldelta47, std::array<u64,4>{v_c6, v_c7, v_c13, v_c16}, [&](const std::array<u64,4>& m128) {
            slog::join_probe_old<4,4>(eval_argsindex24, eval_argsdelta48, std::array<u64,4>{v_c7, v_c6, v_c14, v_c17}, [&](const std::array<u64,4>& m129) {
              if (!slog::exists_probe<3,2>(appindex25, std::array<u64,3>{v_c16, v_c17, 0})) return;
              if (!slog::exists_probe<3,2>(tickindex26, std::array<u64,3>{v_c15, v_c7, 0})) return;
              if (!slog::exists_probe<4,3>(extend_envindex27, std::array<u64,4>{v_c18, v_c21, v_c19, 0})) return;
              if (!slog::exists_probe<2,2>(eval_args_ansindex28, std::array<u64,2>{v_c14, v_c20})) return;
              if (!slog::exists_probe<2,2>(tick_ansindex29, std::array<u64,2>{v_c15, v_c19})) return;
              if (!slog::exists_probe<3,2>(lambdaindex30, std::array<u64,3>{v_c21, v_c11, 0})) return;
              if (!slog::exists_probe<3,1>(closureindex31, std::array<u64,3>{v_c18, 0, 0})) return;
              if (!slog::exists_probe<2,1>(eval_ansindex32, std::array<u64,2>{v_c13, 0})) return;
              if (!slog::exists_probe<4,2>(evalindex33, std::array<u64,4>{v_c19, v_c11, 0, 0})) return;
              slog::join_probe_old<4,3>(evalindex34, evaldelta49, std::array<u64,4>{v_c6, v_c7, v_c12, 0}, [&](const std::array<u64,4>& m130) {
                u64 v_c22 = m130[3];
                slog::join_probe_old<3,3>(appindex35, appdelta50, std::array<u64,3>{v_c22, v_c16, v_c17}, [&](const std::array<u64,3>& m131) {
                  slog::join_probe_old<3,3>(tickindex36, tickdelta51, std::array<u64,3>{v_c15, v_c7, v_c22}, [&](const std::array<u64,3>& m132) {
                    slog::join_probe_old<4,3>(extend_envindex37, extend_envdelta52, std::array<u64,4>{v_c18, v_c21, v_c19, 0}, [&](const std::array<u64,4>& m133) {
                      u64 v_c23 = m133[3];
                      slog::join_probe<2,2>(eval_args_ansindex38, std::array<u64,2>{v_c14, v_c20}, [&](const std::array<u64,2>& m134) {
                        slog::join_probe<2,2>(tick_ansindex39, std::array<u64,2>{v_c15, v_c19}, [&](const std::array<u64,2>& m135) {
                          if (!slog::exists_probe<2,1>(extend_env_ansindex40, std::array<u64,2>{v_c23, 0})) return;
                          slog::join_probe_old<3,2>(lambdaindex41, lambdadelta53, std::array<u64,3>{v_c21, v_c11, 0}, [&](const std::array<u64,3>& m136) {
                            u64 v_c24 = m136[2];
                            slog::join_probe_old<3,2>(closureindex42, closuredelta54, std::array<u64,3>{v_c24, v_c18, 0}, [&](const std::array<u64,3>& m137) {
                              u64 v_c25 = m137[2];
                              slog::join_probe<2,2>(eval_ansindex43, std::array<u64,2>{v_c13, v_c25}, [&](const std::array<u64,2>& m138) {
                                slog::join_probe_old<4,2>(evalindex44, evaldelta55, std::array<u64,4>{v_c19, v_c11, 0, 0}, [&](const std::array<u64,4>& m139) {
                                  u64 v_c26 = m139[2]; u64 v_c27 = m139[3];
                                  slog::join_probe<2,2>(extend_env_ansindex45, std::array<u64,2>{v_c23, v_c27}, [&](const std::array<u64,2>& m140) {
                                    slog::join_probe<2,1>(eval_ansindex46, std::array<u64,2>{v_c26, 0}, [&](const std::array<u64,2>& m141) {
                                      u64 v_c28 = m141[1];
                                      ++_fires;
                                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c12, v_c28}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:52", "delta:$sup70016x51x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask56* _cont = new ReadTask56(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask56(db,b), false);
  // (crule (pre) (scan mbranch __t8lCA285 p m l r) (body (join-old mp_del (1 2 0) 1 (1 2 0) __t8lCA285 k __t4dB9286)) (head (emit $sup5638x81x0x0x0 (0 1 2 3 4 5) __t4dB9286 k l m p r)) map.slog:82 #f)
  class ReadTask144 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_delindex142;  slog::Index** mp_deldelta143;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x81x0x0x0");
      std::vector<u16> ord145({0, 1, 2, 3, 4, 5});
      slog::Relation* readrel146 = db->getRelation("$sup5638x81x0x0x0");
      head_index[0] = readrel146->getIndex(ord145, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord147({1, 2, 0});
      slog::Relation* readrel148 = db->getRelation("mp_del");
      mp_delindex142 = readrel148->getIndex(ord147, false);
      std::vector<u16> ord149({1, 2, 0});
      slog::Relation* readrel150 = db->getRelation("mp_del");
      mp_deldelta143 = readrel150->getIndex(ord149, true);
  
    }
    ReadTask144(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c30 = _t[1];
        u64 v_c31 = _t[2];
        u64 v_c32 = _t[3];
        u64 v_c33 = _t[4];
        slog::join_probe_old<3,1>(mp_delindex142, mp_deldelta143, std::array<u64,3>{v_c29, 0, 0}, [&](const std::array<u64,3>& m151) {
          u64 v_c34 = m151[1]; u64 v_c35 = m151[2];
          ++_fires;
          slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c35, v_c34, v_c32, v_c31, v_c30, v_c33}, std::array<u16,6>{0, 1, 2, 3, 4, 5});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:82", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask144* _cont = new ReadTask144(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask144(db,b), false);
  // (crule (pre (let __tconst7pEc129 const6b86b273ff34fce19d6b804e)) (scan mp_hsb __t0Ayb132 __t867d136) (body (exists mp_hsb_ans (0 1) 1 __t0Ayb132) (exists $sup5638x25x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) 1 __t0Ayb132) (exists $sup5638x25x0x0x1 (1 2 0 3 4 5 6) 1 __t0Ayb132) (join mp_hsb_ans (0 1) 1 __t0Ayb132 __v3) (exists $sup5638x25x0x0x2 (1 6 0 2 3 4 5 7 8 9 10) 2 __t0Ayb132 __v3) (join mp_hsb_ans (0 1) 1 __t0Ayb132 __v1) (exists $sup5638x25x0x0x2 (1 5 6 7 0 2 3 4 8 9 10) 3 __t0Ayb132 __v1 __v3) (exists mp_msk (2 0 1) 1 __v1) (join mp_hsb_ans (0 1) 1 __t0Ayb132 __v0) (exists $sup5638x25x0x0x1 (1 2 0 3 4 5 6) 2 __t0Ayb132 __v0) (join $sup5638x25x0x0x2 (1 4 6 5 0 2 3 7 8 9 10) 4 __t0Ayb132 __v0 __v3 __v1 __t8CpS128 dup4t6F1978 dup2J5X1979 p0 p1 t0 t1) (eq __t0Ayb132 dup2J5X1979) (eq __t0Ayb132 dup4t6F1978) (join $sup5638x25x0x0x1 (0 3 4 5 6 1 2) 7 __t8CpS128 p0 p1 t0 t1 __t0Ayb132 __v0) (join $sup5638x25x0x0x0 (1 0 2 3 4) 5 p0 __t8CpS128 p1 t0 t1) (join-old mp_join (1 2 3 4 0) 5 (1 2 3 4 0) p0 t0 p1 t1 __t8CpS128) (join mp_msk (1 2 0) 2 p0 __v1 __t40jf135) (join mp_msk_ans (0 1) 1 __t40jf135 __v2) (let __t8HR0130 (band p0 __v0)) (cmp lt __t8HR0130 __tconst7pEc129) (let chk1Cuk1980 (bxor p0 p1)) (eq __t867d136 chk1Cuk1980)) (head (emit-temp temp0yve1977 __t8CpS128 __v2 __v3 t0 t1) (mkstruct mbranch (1 2 3 4 0) __t3nlL127 __v2 __v3 t0 t1)) map.slog:26 #f)
  class ReadTask169 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_hsb_ansindex152;  slog::Index** $sup5638x25x0x0x2index153;  slog::Index** $sup5638x25x0x0x1index154;  slog::Index** mp_hsb_ansindex155;  slog::Index** $sup5638x25x0x0x2index156;  slog::Index** mp_hsb_ansindex157;  slog::Index** $sup5638x25x0x0x2index158;  slog::Index** mp_mskindex159;  slog::Index** mp_hsb_ansindex160;  slog::Index** $sup5638x25x0x0x1index161;  slog::Index** $sup5638x25x0x0x2index162;  slog::Index** $sup5638x25x0x0x1index163;  slog::Index** $sup5638x25x0x0x0index164;  slog::Index** mp_joinindex165;  slog::Index** mp_mskindex166;  slog::Index** mp_msk_ansindex167;  slog::Index** mp_joindelta168;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0yve1977");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_hsb");
      std::vector<u16> ord170({0, 1});
      slog::Relation* readrel171 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex152 = readrel171->getIndex(ord170, false);
      std::vector<u16> ord172({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel173 = db->getRelation("$sup5638x25x0x0x2");
      $sup5638x25x0x0x2index153 = readrel173->getIndex(ord172, false);
      std::vector<u16> ord174({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel175 = db->getRelation("$sup5638x25x0x0x1");
      $sup5638x25x0x0x1index154 = readrel175->getIndex(ord174, false);
      std::vector<u16> ord176({0, 1});
      slog::Relation* readrel177 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex155 = readrel177->getIndex(ord176, false);
      std::vector<u16> ord178({1, 6, 0, 2, 3, 4, 5, 7, 8, 9, 10});
      slog::Relation* readrel179 = db->getRelation("$sup5638x25x0x0x2");
      $sup5638x25x0x0x2index156 = readrel179->getIndex(ord178, false);
      std::vector<u16> ord180({0, 1});
      slog::Relation* readrel181 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex157 = readrel181->getIndex(ord180, false);
      std::vector<u16> ord182({1, 5, 6, 7, 0, 2, 3, 4, 8, 9, 10});
      slog::Relation* readrel183 = db->getRelation("$sup5638x25x0x0x2");
      $sup5638x25x0x0x2index158 = readrel183->getIndex(ord182, false);
      std::vector<u16> ord184({2, 0, 1});
      slog::Relation* readrel185 = db->getRelation("mp_msk");
      mp_mskindex159 = readrel185->getIndex(ord184, false);
      std::vector<u16> ord186({0, 1});
      slog::Relation* readrel187 = db->getRelation("mp_hsb_ans");
      mp_hsb_ansindex160 = readrel187->getIndex(ord186, false);
      std::vector<u16> ord188({1, 2, 0, 3, 4, 5, 6});
      slog::Relation* readrel189 = db->getRelation("$sup5638x25x0x0x1");
      $sup5638x25x0x0x1index161 = readrel189->getIndex(ord188, false);
      std::vector<u16> ord190({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
      slog::Relation* readrel191 = db->getRelation("$sup5638x25x0x0x2");
      $sup5638x25x0x0x2index162 = readrel191->getIndex(ord190, false);
      std::vector<u16> ord192({0, 3, 4, 5, 6, 1, 2});
      slog::Relation* readrel193 = db->getRelation("$sup5638x25x0x0x1");
      $sup5638x25x0x0x1index163 = readrel193->getIndex(ord192, false);
      std::vector<u16> ord194({1, 0, 2, 3, 4});
      slog::Relation* readrel195 = db->getRelation("$sup5638x25x0x0x0");
      $sup5638x25x0x0x0index164 = readrel195->getIndex(ord194, false);
      std::vector<u16> ord196({1, 2, 3, 4, 0});
      slog::Relation* readrel197 = db->getRelation("mp_join");
      mp_joinindex165 = readrel197->getIndex(ord196, false);
      std::vector<u16> ord198({1, 2, 3, 4, 0});
      slog::Relation* readrel199 = db->getRelation("mp_join");
      mp_joindelta168 = readrel199->getIndex(ord198, true);
      std::vector<u16> ord200({1, 2, 0});
      slog::Relation* readrel201 = db->getRelation("mp_msk");
      mp_mskindex166 = readrel201->getIndex(ord200, false);
      std::vector<u16> ord202({0, 1});
      slog::Relation* readrel203 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex167 = readrel203->getIndex(ord202, false);
  
    }
    ReadTask169(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c36 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c37 = _t[0];
        u64 v_c38 = _t[1];
        if (!slog::exists_probe<2,1>(mp_hsb_ansindex152, std::array<u64,2>{v_c37, 0})) return;
        if (!slog::exists_probe<11,1>($sup5638x25x0x0x2index153, std::array<u64,11>{v_c37, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<7,1>($sup5638x25x0x0x1index154, std::array<u64,7>{v_c37, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(mp_hsb_ansindex155, std::array<u64,2>{v_c37, 0}, [&](const std::array<u64,2>& m204) {
          u64 v_c39 = m204[1];
          if (!slog::exists_probe<11,2>($sup5638x25x0x0x2index156, std::array<u64,11>{v_c37, v_c39, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          slog::join_probe<2,1>(mp_hsb_ansindex157, std::array<u64,2>{v_c37, 0}, [&](const std::array<u64,2>& m205) {
            u64 v_c40 = m205[1];
            if (!slog::exists_probe<11,3>($sup5638x25x0x0x2index158, std::array<u64,11>{v_c37, v_c40, v_c39, 0, 0, 0, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<3,1>(mp_mskindex159, std::array<u64,3>{v_c40, 0, 0})) return;
            slog::join_probe<2,1>(mp_hsb_ansindex160, std::array<u64,2>{v_c37, 0}, [&](const std::array<u64,2>& m206) {
              u64 v_c27 = m206[1];
              if (!slog::exists_probe<7,2>($sup5638x25x0x0x1index161, std::array<u64,7>{v_c37, v_c27, 0, 0, 0, 0, 0})) return;
              slog::join_probe<11,4>($sup5638x25x0x0x2index162, std::array<u64,11>{v_c37, v_c27, v_c39, v_c40, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,11>& m207) {
                u64 v_c41 = m207[4]; u64 v_c42 = m207[5]; u64 v_c43 = m207[6]; u64 v_c44 = m207[7]; u64 v_c45 = m207[8]; u64 v_c46 = m207[9]; u64 v_c47 = m207[10];
                if (v_c37 != v_c43) return;
                if (v_c37 != v_c42) return;
                slog::join_probe<7,7>($sup5638x25x0x0x1index163, std::array<u64,7>{v_c41, v_c44, v_c45, v_c46, v_c47, v_c37, v_c27}, [&](const std::array<u64,7>& m208) {
                  slog::join_probe<5,5>($sup5638x25x0x0x0index164, std::array<u64,5>{v_c44, v_c41, v_c45, v_c46, v_c47}, [&](const std::array<u64,5>& m209) {
                    slog::join_probe_old<5,5>(mp_joinindex165, mp_joindelta168, std::array<u64,5>{v_c44, v_c46, v_c45, v_c47, v_c41}, [&](const std::array<u64,5>& m210) {
                      slog::join_probe<3,2>(mp_mskindex166, std::array<u64,3>{v_c44, v_c40, 0}, [&](const std::array<u64,3>& m211) {
                        u64 v_c48 = m211[2];
                        slog::join_probe<2,1>(mp_msk_ansindex167, std::array<u64,2>{v_c48, 0}, [&](const std::array<u64,2>& m212) {
                          u64 v_c49 = m212[1];
                          u64 v_c50 = _prim_band(db, v_c44, v_c27);
                          if (v_c50 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                          u64 v_c51 = _prim_lt(db, v_c50, v_c36);
                          if (v_c51 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                          if (!v_c51) return;
                          u64 v_c52 = _prim_bxor(db, v_c44, v_c45);
                          if (v_c52 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
                          if (v_c38 != v_c52) return;
                          ++_fires;
                          slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c41, v_c49, v_c39, v_c46, v_c47});
                          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c49, v_c39, v_c46, v_c47}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:26", "delta:mp_hsb", _fires);
  
      if (!_done)
      {
        ReadTask169* _cont = new ReadTask169(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask169(db,b), false);
  // (crule (pre (let __tconst2Vg0546 const06abaa100ecef791ce028c56) (let _00024sqc2T6l964 constd4735e3a265e16eee03f5971) (let _00024sqc2Wzv965 const5feceb66ffc86f38d952786c) (let _00024sqc80On966 const6b86b273ff34fce19d6b804e) (let _00024sqo5uVM967 const5feceb66ffc86f38d952786c) (let _00024sqo11r2968 const6b86b273ff34fce19d6b804e) (let _00024sqo89F1969 const6b86b273ff34fce19d6b804e) (let _00024sqo57Hb970 const5feceb66ffc86f38d952786c)) (probe $seq_atr (1 0 2) 1 _00024sqo89F1969 __t40a6549 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo5uVM967 __t40a6549 _00024seq2) (join $seq_at (1 0 2) 3 _00024sqo11r2968 __t40a6549 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo57Hb970 __t40a6549 _00024seq2) (join delta (1 2 0) 2 __tconst2Vg0546 _00024seq2 __t6qCW547) (join closure (0 1 2) 1 __t40a6549 lm rc) (join any_bool (0) 0 b) (letp _00024sql3t08962 (aslst _00024seq2)) (let chk8oK41850 (llen _00024sql3t08962)) (eq _00024sqc2T6l964 chk8oK41850) (letp chk4RN51851 (lref _00024sql3t08962 _00024sqc2Wzv965)) (eq __t40a6549 chk4RN51851) (letp chk6Qn61852 (lref _00024sql3t08962 _00024sqc80On966)) (eq __t40a6549 chk6Qn61852)) (head (emit-temp temp7z5q1838 __t6qCW547 b) (mkstruct boolval (1 0) __t1Eis545 b)) interp.slog:126 #f)
  class ReadTask221 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex214;  slog::Index** $seq_atindex215;  slog::Index** $seq_atrindex216;  slog::Index** deltaindex217;  slog::Index** closureindex218;  slog::Index** any_boolindex219;  slog::Index** $seq_atrdelta220;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7z5q1838");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord222({1, 0, 2});
      slog::Relation* readrel223 = db->getRelation("$seq_atr");
      driver_index = readrel223->getIndex(ord222, true);
      std::vector<u16> ord224({1, 0, 2});
      slog::Relation* readrel225 = db->getRelation("$seq_at");
      $seq_atindex214 = readrel225->getIndex(ord224, false);
      std::vector<u16> ord226({1, 0, 2});
      slog::Relation* readrel227 = db->getRelation("$seq_at");
      $seq_atindex215 = readrel227->getIndex(ord226, false);
      std::vector<u16> ord228({1, 0, 2});
      slog::Relation* readrel229 = db->getRelation("$seq_atr");
      $seq_atrindex216 = readrel229->getIndex(ord228, false);
      std::vector<u16> ord230({1, 0, 2});
      slog::Relation* readrel231 = db->getRelation("$seq_atr");
      $seq_atrdelta220 = readrel231->getIndex(ord230, true);
      std::vector<u16> ord232({1, 2, 0});
      slog::Relation* readrel233 = db->getRelation("delta");
      deltaindex217 = readrel233->getIndex(ord232, false);
      std::vector<u16> ord234({0, 1, 2});
      slog::Relation* readrel235 = db->getRelation("closure");
      closureindex218 = readrel235->getIndex(ord234, false);
      std::vector<u16> ord236({0});
      slog::Relation* readrel237 = db->getRelation("any_bool");
      any_boolindex219 = readrel237->getIndex(ord236, false);
  
    }
    ReadTask221(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c53 = v_const06abaa100ecef791ce028c56;
      u64 v_c54 = v_constd4735e3a265e16eee03f5971;
      u64 v_c55 = v_const5feceb66ffc86f38d952786c;
      u64 v_c56 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c57 = v_const5feceb66ffc86f38d952786c;
      u64 v_c58 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c59 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c60 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c59, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m238) {
        u64 v_c61 = m238[1];
        u64 v_c62 = m238[2];
        if (buckethash(v_c61) != bucket) return;
        slog::join_probe<3,3>($seq_atindex214, std::array<u64,3>{v_c57, v_c61, v_c62}, [&](const std::array<u64,3>& m239) {
          slog::join_probe<3,3>($seq_atindex215, std::array<u64,3>{v_c58, v_c61, v_c62}, [&](const std::array<u64,3>& m240) {
            slog::join_probe_old<3,3>($seq_atrindex216, $seq_atrdelta220, std::array<u64,3>{v_c60, v_c61, v_c62}, [&](const std::array<u64,3>& m241) {
              slog::join_probe<3,2>(deltaindex217, std::array<u64,3>{v_c53, v_c62, 0}, [&](const std::array<u64,3>& m242) {
                u64 v_c63 = m242[2];
                slog::join_probe<3,1>(closureindex218, std::array<u64,3>{v_c61, 0, 0}, [&](const std::array<u64,3>& m243) {
                  u64 v_c64 = m243[1]; u64 v_c65 = m243[2];
                  slog::join_all<1>(any_boolindex219, [&](const std::array<u64,1>& m244) {
                    u64 v_c66 = m244[0];
                    bool ok245 = true;
                    u64 v_c67 = _prim_aslst(db, v_c62, &ok245);
                    if (!ok245) return;
                    u64 v_c68 = _prim_llen(db, v_c67);
                    if (v_c68 == slog_error) { slog::emit_pending_error(db, "interp.slog:126"); return; }
                    if (v_c54 != v_c68) return;
                    bool ok246 = true;
                    u64 v_c69 = _prim_lref(db, v_c67, v_c55, &ok246);
                    if (!ok246) return;
                    if (v_c61 != v_c69) return;
                    bool ok247 = true;
                    u64 v_c70 = _prim_lref(db, v_c67, v_c56, &ok247);
                    if (!ok247) return;
                    if (v_c61 != v_c70) return;
                    ++_fires;
                    slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c63, v_c66});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c66}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:126", "delta:$seq_atr", _fires);
  
      if (!_done)
      {
        ReadTask221* _cont = new ReadTask221(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask221(db,b), false);
  // (crule (pre) (scan mp_msk __t99il580 p n) (body (exists $sup5638x107x0x0x0 (3 4 5 0 1 2 6 7 8) 2 n p) (join mp_msk_ans (0 1) 1 __t99il580 q) (join $sup5638x107x0x0x0 (3 4 5 0 1 2 6 7 8) 3 n p q __d0 l m r u v)) (head (emit $sup5638x107x0x0x1 (0 9 1 2 3 4 5 6 7 8) __d0 v __t99il580 l m n p q r u)) map.slog:108 #f)
  class ReadTask251 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x107x0x0x0index248;  slog::Index** mp_msk_ansindex249;  slog::Index** $sup5638x107x0x0x0index250;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x107x0x0x1");
      std::vector<u16> ord252({0, 9, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel253 = db->getRelation("$sup5638x107x0x0x1");
      head_index[0] = readrel253->getIndex(ord252, false);
      outer_rel = db->getRelation("mp_msk");
      std::vector<u16> ord254({3, 4, 5, 0, 1, 2, 6, 7, 8});
      slog::Relation* readrel255 = db->getRelation("$sup5638x107x0x0x0");
      $sup5638x107x0x0x0index248 = readrel255->getIndex(ord254, false);
      std::vector<u16> ord256({0, 1});
      slog::Relation* readrel257 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex249 = readrel257->getIndex(ord256, false);
      std::vector<u16> ord258({3, 4, 5, 0, 1, 2, 6, 7, 8});
      slog::Relation* readrel259 = db->getRelation("$sup5638x107x0x0x0");
      $sup5638x107x0x0x0index250 = readrel259->getIndex(ord258, false);
  
    }
    ReadTask251(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c30 = _t[1];
        u64 v_c72 = _t[2];
        if (!slog::exists_probe<9,2>($sup5638x107x0x0x0index248, std::array<u64,9>{v_c72, v_c30, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(mp_msk_ansindex249, std::array<u64,2>{v_c71, 0}, [&](const std::array<u64,2>& m260) {
          u64 v_c73 = m260[1];
          slog::join_probe<9,3>($sup5638x107x0x0x0index250, std::array<u64,9>{v_c72, v_c30, v_c73, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m261) {
            u64 v_c74 = m261[3]; u64 v_c32 = m261[4]; u64 v_c31 = m261[5]; u64 v_c33 = m261[6]; u64 v_c75 = m261[7]; u64 v_c28 = m261[8];
            ++_fires;
            slog::emit<10>(head_rel[0], head_index[0], newbatch[0], std::array<u64,10>{v_c74, v_c28, v_c71, v_c32, v_c31, v_c72, v_c30, v_c73, v_c33, v_c75}, std::array<u16,10>{0, 9, 1, 2, 3, 4, 5, 6, 7, 8});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:108", "delta:mp_msk", _fires);
  
      if (!_done)
      {
        ReadTask251* _cont = new ReadTask251(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask251(db,b), false);
  // (crule (pre (let __trid28jP1212 const6c3d8aa344844f80a370de02) (let __trel2nq61213 constdd7bbf31ce5f578b9805e840) (let __tcol68CZ1214 const5feceb66ffc86f38d952786c) (let __trel4zCi1215 constdd7bbf31ce5f578b9805e840) (let __tcol91UP1216 const6b86b273ff34fce19d6b804e)) (scan $sup5638x101x0x0x0 __d0 l m n p q r s t u v) (body) (head (tycheck q (accept int) __trid28jP1212 __trel2nq61213 __tcol68CZ1214 (1 2 3 4 0)) (tycheck m (accept int) __trid28jP1212 __trel4zCi1215 __tcol91UP1216 (1 2 3 4 0)) (mkstruct mp_msk (1 2 0) __7O1d1211 q m)) map.slog:102 #f)
  class ReadTask262 : public slog::Task
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
      outer_rel = db->getRelation("$sup5638x101x0x0x0");
  
    }
    ReadTask262(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c76 = v_const6c3d8aa344844f80a370de02;
      u64 v_c77 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c78 = v_const5feceb66ffc86f38d952786c;
      u64 v_c79 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c80 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c74 = _t[0];
        u64 v_c32 = _t[1];
        u64 v_c31 = _t[2];
        u64 v_c72 = _t[3];
        u64 v_c30 = _t[4];
        u64 v_c73 = _t[5];
        u64 v_c33 = _t[6];
        u64 v_c81 = _t[7];
        u64 v_c7 = _t[8];
        u64 v_c75 = _t[9];
        u64 v_c28 = _t[10];
        ++_fires;
        if (!(is_int(v_c73)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c76, v_c77, v_c78, v_c73}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c31)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c76, v_c79, v_c80, v_c31}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c73, v_c31}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:102", "delta:$sup5638x101x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask262* _cont = new ReadTask262(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask262(db,b), false);
  // (crule (pre (let __tconst3VAm410 const5feceb66ffc86f38d952786c)) (scan mbranch __t7ecR407 q n u v) (body (join-old mp_union (2 0 1) 1 (2 0 1) __t7ecR407 __t6JnF409 __t7895408) (join-old mbranch (0 1 2 3 4) 1 (0 1 2 3 4) __t7895408 p m l r) (cmp lt n m) (let __t8deh411 (band q m)) (cmp gt __t8deh411 __tconst3VAm410)) (head (emit $sup5638x98x0x0x0 (0 6 1 2 3 4 5 7 8) __t6JnF409 r l m n p q u v)) map.slog:99 #f)
  class ReadTask267 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex263;  slog::Index** mbranchindex264;  slog::Index** mp_uniondelta265;  slog::Index** mbranchdelta266;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x98x0x0x0");
      std::vector<u16> ord268({0, 6, 1, 2, 3, 4, 5, 7, 8});
      slog::Relation* readrel269 = db->getRelation("$sup5638x98x0x0x0");
      head_index[0] = readrel269->getIndex(ord268, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord270({2, 0, 1});
      slog::Relation* readrel271 = db->getRelation("mp_union");
      mp_unionindex263 = readrel271->getIndex(ord270, false);
      std::vector<u16> ord272({2, 0, 1});
      slog::Relation* readrel273 = db->getRelation("mp_union");
      mp_uniondelta265 = readrel273->getIndex(ord272, true);
      std::vector<u16> ord274({0, 1, 2, 3, 4});
      slog::Relation* readrel275 = db->getRelation("mbranch");
      mbranchindex264 = readrel275->getIndex(ord274, false);
      std::vector<u16> ord276({0, 1, 2, 3, 4});
      slog::Relation* readrel277 = db->getRelation("mbranch");
      mbranchdelta266 = readrel277->getIndex(ord276, true);
  
    }
    ReadTask267(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c82 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c83 = _t[0];
        u64 v_c73 = _t[1];
        u64 v_c72 = _t[2];
        u64 v_c75 = _t[3];
        u64 v_c28 = _t[4];
        slog::join_probe_old<3,1>(mp_unionindex263, mp_uniondelta265, std::array<u64,3>{v_c83, 0, 0}, [&](const std::array<u64,3>& m278) {
          u64 v_c84 = m278[1]; u64 v_c85 = m278[2];
          slog::join_probe_old<5,1>(mbranchindex264, mbranchdelta266, std::array<u64,5>{v_c85, 0, 0, 0, 0}, [&](const std::array<u64,5>& m279) {
            u64 v_c30 = m279[1]; u64 v_c31 = m279[2]; u64 v_c32 = m279[3]; u64 v_c33 = m279[4];
            u64 v_c86 = _prim_lt(db, v_c72, v_c31);
            if (v_c86 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
            if (!v_c86) return;
            u64 v_c87 = _prim_band(db, v_c73, v_c31);
            if (v_c87 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
            u64 v_c88 = _prim_gt(db, v_c87, v_c82);
            if (v_c88 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
            if (!v_c88) return;
            ++_fires;
            slog::emit<9>(head_rel[0], head_index[0], newbatch[0], std::array<u64,9>{v_c84, v_c33, v_c32, v_c31, v_c72, v_c30, v_c73, v_c75, v_c28}, std::array<u16,9>{0, 6, 1, 2, 3, 4, 5, 7, 8});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:99", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask267* _cont = new ReadTask267(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask267(db,b), false);
  // (crule (pre) (scan mp_union __t7CA0447 __t8p1x448 __t8IRS449) (body (join-old mbranch (0 1 2 3 4) 1 (0 1 2 3 4) __t8p1x448 p m l r) (join-old mbranch (2 0 1 3 4) 2 (2 0 1 3 4) m __t8IRS449 q u v) (neq p q)) (head (mkstruct mp_join (1 2 3 4 0) __86XP1466 p __t8p1x448 q __t8IRS449)) map.slog:114 #f)
  class ReadTask286 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex282;  slog::Index** mbranchindex283;  slog::Index** mbranchdelta284;  slog::Index** mbranchdelta285;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_join");
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord287({0, 1, 2, 3, 4});
      slog::Relation* readrel288 = db->getRelation("mbranch");
      mbranchindex282 = readrel288->getIndex(ord287, false);
      std::vector<u16> ord289({0, 1, 2, 3, 4});
      slog::Relation* readrel290 = db->getRelation("mbranch");
      mbranchdelta284 = readrel290->getIndex(ord289, true);
      std::vector<u16> ord291({2, 0, 1, 3, 4});
      slog::Relation* readrel292 = db->getRelation("mbranch");
      mbranchindex283 = readrel292->getIndex(ord291, false);
      std::vector<u16> ord293({2, 0, 1, 3, 4});
      slog::Relation* readrel294 = db->getRelation("mbranch");
      mbranchdelta285 = readrel294->getIndex(ord293, true);
  
    }
    ReadTask286(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c89 = _t[0];
        u64 v_c90 = _t[1];
        u64 v_c91 = _t[2];
        slog::join_probe_old<5,1>(mbranchindex282, mbranchdelta284, std::array<u64,5>{v_c90, 0, 0, 0, 0}, [&](const std::array<u64,5>& m295) {
          u64 v_c30 = m295[1]; u64 v_c31 = m295[2]; u64 v_c32 = m295[3]; u64 v_c33 = m295[4];
          slog::join_probe_old<5,2>(mbranchindex283, mbranchdelta285, std::array<u64,5>{v_c31, v_c91, 0, 0, 0}, [&](const std::array<u64,5>& m296) {
            u64 v_c73 = m296[2]; u64 v_c75 = m296[3]; u64 v_c28 = m296[4];
            if (v_c30 == v_c73) return;
            ++_fires;
            slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c30, v_c90, v_c73, v_c91}, std::array<u16,5>{1, 2, 3, 4, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:114", "delta:mp_union", _fires);
  
      if (!_done)
      {
        ReadTask286* _cont = new ReadTask286(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask286(db,b), false);
  // (crule (pre (let __tconst25r1527 const5feceb66ffc86f38d952786c)) (scan mp_put_ans __t7U64528 r) (body (join mp_has0_ans (1 0) 1 __tconst25r1527 __t5miQ526) (join-old mp_has0 (0 2 1) 1 (0 2 1) __t5miQ526 k t) (exists $sup5638x68x0x0x0 (1 2 3 0) 2 k t) (exists mp_put_soft (1 2 3 0) 2 t k) (join-old mp_put (0 2 1 3) 3 (0 2 1 3) __t7U64528 k t v) (exists mp_put_soft (1 2 3 0) 3 t k v) (join-old $sup5638x68x0x0x0 (1 2 3 0) 3 (1 2 3 0) k t v __t94M4525) (join-old mp_put_soft (1 2 3 0) 4 (1 2 3 0) t k v __t94M4525)) (head (emit mp_put_soft_ans (0 1) __t94M4525 r)) map.slog:69 #f)
  class ReadTask309 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_has0_ansindex297;  slog::Index** mp_has0index298;  slog::Index** $sup5638x68x0x0x0index299;  slog::Index** mp_put_softindex300;  slog::Index** mp_putindex301;  slog::Index** mp_put_softindex302;  slog::Index** $sup5638x68x0x0x0index303;  slog::Index** mp_put_softindex304;  slog::Index** mp_has0delta305;  slog::Index** mp_putdelta306;  slog::Index** $sup5638x68x0x0x0delta307;  slog::Index** mp_put_softdelta308;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_soft_ans");
      std::vector<u16> ord310({0, 1});
      slog::Relation* readrel311 = db->getRelation("mp_put_soft_ans");
      head_index[0] = readrel311->getIndex(ord310, false);
      outer_rel = db->getRelation("mp_put_ans");
      std::vector<u16> ord312({1, 0});
      slog::Relation* readrel313 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex297 = readrel313->getIndex(ord312, false);
      std::vector<u16> ord314({0, 2, 1});
      slog::Relation* readrel315 = db->getRelation("mp_has0");
      mp_has0index298 = readrel315->getIndex(ord314, false);
      std::vector<u16> ord316({0, 2, 1});
      slog::Relation* readrel317 = db->getRelation("mp_has0");
      mp_has0delta305 = readrel317->getIndex(ord316, true);
      std::vector<u16> ord318({1, 2, 3, 0});
      slog::Relation* readrel319 = db->getRelation("$sup5638x68x0x0x0");
      $sup5638x68x0x0x0index299 = readrel319->getIndex(ord318, false);
      std::vector<u16> ord320({1, 2, 3, 0});
      slog::Relation* readrel321 = db->getRelation("mp_put_soft");
      mp_put_softindex300 = readrel321->getIndex(ord320, false);
      std::vector<u16> ord322({0, 2, 1, 3});
      slog::Relation* readrel323 = db->getRelation("mp_put");
      mp_putindex301 = readrel323->getIndex(ord322, false);
      std::vector<u16> ord324({0, 2, 1, 3});
      slog::Relation* readrel325 = db->getRelation("mp_put");
      mp_putdelta306 = readrel325->getIndex(ord324, true);
      std::vector<u16> ord326({1, 2, 3, 0});
      slog::Relation* readrel327 = db->getRelation("mp_put_soft");
      mp_put_softindex302 = readrel327->getIndex(ord326, false);
      std::vector<u16> ord328({1, 2, 3, 0});
      slog::Relation* readrel329 = db->getRelation("$sup5638x68x0x0x0");
      $sup5638x68x0x0x0index303 = readrel329->getIndex(ord328, false);
      std::vector<u16> ord330({1, 2, 3, 0});
      slog::Relation* readrel331 = db->getRelation("$sup5638x68x0x0x0");
      $sup5638x68x0x0x0delta307 = readrel331->getIndex(ord330, true);
      std::vector<u16> ord332({1, 2, 3, 0});
      slog::Relation* readrel333 = db->getRelation("mp_put_soft");
      mp_put_softindex304 = readrel333->getIndex(ord332, false);
      std::vector<u16> ord334({1, 2, 3, 0});
      slog::Relation* readrel335 = db->getRelation("mp_put_soft");
      mp_put_softdelta308 = readrel335->getIndex(ord334, true);
  
    }
    ReadTask309(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c92 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c93 = _t[0];
        u64 v_c33 = _t[1];
        slog::join_probe<2,1>(mp_has0_ansindex297, std::array<u64,2>{v_c92, 0}, [&](const std::array<u64,2>& m336) {
          u64 v_c94 = m336[1];
          slog::join_probe_old<3,1>(mp_has0index298, mp_has0delta305, std::array<u64,3>{v_c94, 0, 0}, [&](const std::array<u64,3>& m337) {
            u64 v_c34 = m337[1]; u64 v_c7 = m337[2];
            if (!slog::exists_probe<4,2>($sup5638x68x0x0x0index299, std::array<u64,4>{v_c34, v_c7, 0, 0})) return;
            if (!slog::exists_probe<4,2>(mp_put_softindex300, std::array<u64,4>{v_c7, v_c34, 0, 0})) return;
            slog::join_probe_old<4,3>(mp_putindex301, mp_putdelta306, std::array<u64,4>{v_c93, v_c34, v_c7, 0}, [&](const std::array<u64,4>& m338) {
              u64 v_c28 = m338[3];
              if (!slog::exists_probe<4,3>(mp_put_softindex302, std::array<u64,4>{v_c7, v_c34, v_c28, 0})) return;
              slog::join_probe_old<4,3>($sup5638x68x0x0x0index303, $sup5638x68x0x0x0delta307, std::array<u64,4>{v_c34, v_c7, v_c28, 0}, [&](const std::array<u64,4>& m339) {
                u64 v_c95 = m339[3];
                slog::join_probe_old<4,4>(mp_put_softindex304, mp_put_softdelta308, std::array<u64,4>{v_c7, v_c34, v_c28, v_c95}, [&](const std::array<u64,4>& m340) {
                  ++_fires;
                  slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c95, v_c33}, std::array<u16,2>{0, 1});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:69", "delta:mp_put_ans", _fires);
  
      if (!_done)
      {
        ReadTask309* _cont = new ReadTask309(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask309(db,b), false);
  // (crule (pre) (scan eval __t5ODU807 __t3yPA806 rho t) (body (join app (0 1 2) 1 __t3yPA806 ef es)) (head (emit $sup70016x75x0x0x0 (1 2 0 3 4) ef es __t5ODU807 rho t)) interp.slog:76 #f)
  class ReadTask342 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex341;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup70016x75x0x0x0");
      std::vector<u16> ord343({1, 2, 0, 3, 4});
      slog::Relation* readrel344 = db->getRelation("$sup70016x75x0x0x0");
      head_index[0] = readrel344->getIndex(ord343, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord345({0, 1, 2});
      slog::Relation* readrel346 = db->getRelation("app");
      appindex341 = readrel346->getIndex(ord345, false);
  
    }
    ReadTask342(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c6 = _t[2];
        u64 v_c7 = _t[3];
        slog::join_probe<3,1>(appindex341, std::array<u64,3>{v_c97, 0, 0}, [&](const std::array<u64,3>& m347) {
          u64 v_c16 = m347[1]; u64 v_c17 = m347[2];
          ++_fires;
          slog::emit<5>(head_rel[0], head_index[0], newbatch[0], std::array<u64,5>{v_c16, v_c17, v_c96, v_c6, v_c7}, std::array<u16,5>{1, 2, 0, 3, 4});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:76", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask342* _cont = new ReadTask342(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask342(db,b), false);
  // (crule (pre (let __tconst3ZiI681 const5feceb66ffc86f38d952786c)) (scan mp_union __t6NDF685 __t0Aux684 v) (body (exists mp_union (1 2 0) 1 __t0Aux684) (exists mbranch (4 0 1 2 3) 1 v) (exists $sup5638x107x0x0x0 (8 0 1 2 3 4 5 6 7) 1 v) (exists $sup5638x107x0x0x1 (9 4 6 8 0 2 3 5 7 1) 1 v) (join mp_union_ans (0 1) 1 __t6NDF685 __v0) (join mp_union (1 2 0) 1 __t0Aux684 __t105R678 __t5Sgr680) (exists $sup5638x107x0x0x0 (0 8 1 2 3 4 5 6 7) 2 __t5Sgr680 v) (exists $sup5638x107x0x0x1 (0 9 1 2 3 4 5 6 7 8) 2 __t5Sgr680 v) (join mbranch (4 0 1 2 3) 2 v __t105R678 q n u) (exists $sup5638x107x0x0x1 (9 4 6 8 0 2 3 5 7 1) 5 v n q u __t5Sgr680) (exists mp_msk (2 0 1) 1 n) (exists mp_msk_ans (1 0) 1 q) (join $sup5638x107x0x0x0 (5 3 7 8 0 1 2 4 6) 5 q n u v __t5Sgr680 l m p r) (cmp lt m n) (exists mbranch (1 2 3 4 0) 5 p m l r __t0Aux684) (exists mp_msk (1 2 0) 2 p n) (join $sup5638x107x0x0x1 (9 4 6 8 0 2 3 5 7 1) 9 v n q u __t5Sgr680 l m p r __t78qG683) (join mbranch (1 2 3 4 0) 5 p m l r __t0Aux684) (join mp_msk (1 2 0) 3 p n __t78qG683) (join mp_msk_ans (0 1) 2 __t78qG683 q) (let __t90AV682 (band p n)) (cmp gt __t90AV682 __tconst3ZiI681)) (head (emit-temp temp9jSj1946 __t5Sgr680 __v0 n q u) (mkstruct mbranch (1 2 3 4 0) __t287h677 q n u __v0)) map.slog:108 #f)
  class ReadTask367 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex348;  slog::Index** mbranchindex349;  slog::Index** $sup5638x107x0x0x0index350;  slog::Index** $sup5638x107x0x0x1index351;  slog::Index** mp_union_ansindex352;  slog::Index** mp_unionindex353;  slog::Index** $sup5638x107x0x0x0index354;  slog::Index** $sup5638x107x0x0x1index355;  slog::Index** mbranchindex356;  slog::Index** $sup5638x107x0x0x1index357;  slog::Index** mp_mskindex358;  slog::Index** mp_msk_ansindex359;  slog::Index** $sup5638x107x0x0x0index360;  slog::Index** mbranchindex361;  slog::Index** mp_mskindex362;  slog::Index** $sup5638x107x0x0x1index363;  slog::Index** mbranchindex364;  slog::Index** mp_mskindex365;  slog::Index** mp_msk_ansindex366;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9jSj1946");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord368({1, 2, 0});
      slog::Relation* readrel369 = db->getRelation("mp_union");
      mp_unionindex348 = readrel369->getIndex(ord368, false);
      std::vector<u16> ord370({4, 0, 1, 2, 3});
      slog::Relation* readrel371 = db->getRelation("mbranch");
      mbranchindex349 = readrel371->getIndex(ord370, false);
      std::vector<u16> ord372({8, 0, 1, 2, 3, 4, 5, 6, 7});
      slog::Relation* readrel373 = db->getRelation("$sup5638x107x0x0x0");
      $sup5638x107x0x0x0index350 = readrel373->getIndex(ord372, false);
      std::vector<u16> ord374({9, 4, 6, 8, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel375 = db->getRelation("$sup5638x107x0x0x1");
      $sup5638x107x0x0x1index351 = readrel375->getIndex(ord374, false);
      std::vector<u16> ord376({0, 1});
      slog::Relation* readrel377 = db->getRelation("mp_union_ans");
      mp_union_ansindex352 = readrel377->getIndex(ord376, false);
      std::vector<u16> ord378({1, 2, 0});
      slog::Relation* readrel379 = db->getRelation("mp_union");
      mp_unionindex353 = readrel379->getIndex(ord378, false);
      std::vector<u16> ord380({0, 8, 1, 2, 3, 4, 5, 6, 7});
      slog::Relation* readrel381 = db->getRelation("$sup5638x107x0x0x0");
      $sup5638x107x0x0x0index354 = readrel381->getIndex(ord380, false);
      std::vector<u16> ord382({0, 9, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel383 = db->getRelation("$sup5638x107x0x0x1");
      $sup5638x107x0x0x1index355 = readrel383->getIndex(ord382, false);
      std::vector<u16> ord384({4, 0, 1, 2, 3});
      slog::Relation* readrel385 = db->getRelation("mbranch");
      mbranchindex356 = readrel385->getIndex(ord384, false);
      std::vector<u16> ord386({9, 4, 6, 8, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel387 = db->getRelation("$sup5638x107x0x0x1");
      $sup5638x107x0x0x1index357 = readrel387->getIndex(ord386, false);
      std::vector<u16> ord388({2, 0, 1});
      slog::Relation* readrel389 = db->getRelation("mp_msk");
      mp_mskindex358 = readrel389->getIndex(ord388, false);
      std::vector<u16> ord390({1, 0});
      slog::Relation* readrel391 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex359 = readrel391->getIndex(ord390, false);
      std::vector<u16> ord392({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel393 = db->getRelation("$sup5638x107x0x0x0");
      $sup5638x107x0x0x0index360 = readrel393->getIndex(ord392, false);
      std::vector<u16> ord394({1, 2, 3, 4, 0});
      slog::Relation* readrel395 = db->getRelation("mbranch");
      mbranchindex361 = readrel395->getIndex(ord394, false);
      std::vector<u16> ord396({1, 2, 0});
      slog::Relation* readrel397 = db->getRelation("mp_msk");
      mp_mskindex362 = readrel397->getIndex(ord396, false);
      std::vector<u16> ord398({9, 4, 6, 8, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel399 = db->getRelation("$sup5638x107x0x0x1");
      $sup5638x107x0x0x1index363 = readrel399->getIndex(ord398, false);
      std::vector<u16> ord400({1, 2, 3, 4, 0});
      slog::Relation* readrel401 = db->getRelation("mbranch");
      mbranchindex364 = readrel401->getIndex(ord400, false);
      std::vector<u16> ord402({1, 2, 0});
      slog::Relation* readrel403 = db->getRelation("mp_msk");
      mp_mskindex365 = readrel403->getIndex(ord402, false);
      std::vector<u16> ord404({0, 1});
      slog::Relation* readrel405 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex366 = readrel405->getIndex(ord404, false);
  
    }
    ReadTask367(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c98 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c28 = _t[2];
        if (!slog::exists_probe<3,1>(mp_unionindex348, std::array<u64,3>{v_c100, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex349, std::array<u64,5>{v_c28, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<9,1>($sup5638x107x0x0x0index350, std::array<u64,9>{v_c28, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<10,1>($sup5638x107x0x0x1index351, std::array<u64,10>{v_c28, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(mp_union_ansindex352, std::array<u64,2>{v_c99, 0}, [&](const std::array<u64,2>& m406) {
          u64 v_c27 = m406[1];
          slog::join_probe<3,1>(mp_unionindex353, std::array<u64,3>{v_c100, 0, 0}, [&](const std::array<u64,3>& m407) {
            u64 v_c101 = m407[1]; u64 v_c102 = m407[2];
            if (!slog::exists_probe<9,2>($sup5638x107x0x0x0index354, std::array<u64,9>{v_c102, v_c28, 0, 0, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<10,2>($sup5638x107x0x0x1index355, std::array<u64,10>{v_c102, v_c28, 0, 0, 0, 0, 0, 0, 0, 0})) return;
            slog::join_probe<5,2>(mbranchindex356, std::array<u64,5>{v_c28, v_c101, 0, 0, 0}, [&](const std::array<u64,5>& m408) {
              u64 v_c73 = m408[2]; u64 v_c72 = m408[3]; u64 v_c75 = m408[4];
              if (!slog::exists_probe<10,5>($sup5638x107x0x0x1index357, std::array<u64,10>{v_c28, v_c72, v_c73, v_c75, v_c102, 0, 0, 0, 0, 0})) return;
              if (!slog::exists_probe<3,1>(mp_mskindex358, std::array<u64,3>{v_c72, 0, 0})) return;
              if (!slog::exists_probe<2,1>(mp_msk_ansindex359, std::array<u64,2>{v_c73, 0})) return;
              slog::join_probe<9,5>($sup5638x107x0x0x0index360, std::array<u64,9>{v_c73, v_c72, v_c75, v_c28, v_c102, 0, 0, 0, 0}, [&](const std::array<u64,9>& m409) {
                u64 v_c32 = m409[5]; u64 v_c31 = m409[6]; u64 v_c30 = m409[7]; u64 v_c33 = m409[8];
                u64 v_c103 = _prim_lt(db, v_c31, v_c72);
                if (v_c103 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
                if (!v_c103) return;
                if (!slog::exists_probe<5,5>(mbranchindex361, std::array<u64,5>{v_c30, v_c31, v_c32, v_c33, v_c100})) return;
                if (!slog::exists_probe<3,2>(mp_mskindex362, std::array<u64,3>{v_c30, v_c72, 0})) return;
                slog::join_probe<10,9>($sup5638x107x0x0x1index363, std::array<u64,10>{v_c28, v_c72, v_c73, v_c75, v_c102, v_c32, v_c31, v_c30, v_c33, 0}, [&](const std::array<u64,10>& m411) {
                  u64 v_c104 = m411[9];
                  slog::join_probe<5,5>(mbranchindex364, std::array<u64,5>{v_c30, v_c31, v_c32, v_c33, v_c100}, [&](const std::array<u64,5>& m412) {
                    slog::join_probe<3,3>(mp_mskindex365, std::array<u64,3>{v_c30, v_c72, v_c104}, [&](const std::array<u64,3>& m413) {
                      slog::join_probe<2,2>(mp_msk_ansindex366, std::array<u64,2>{v_c104, v_c73}, [&](const std::array<u64,2>& m414) {
                        u64 v_c105 = _prim_band(db, v_c30, v_c72);
                        if (v_c105 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
                        u64 v_c106 = _prim_gt(db, v_c105, v_c98);
                        if (v_c106 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
                        if (!v_c106) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c102, v_c27, v_c72, v_c73, v_c75});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c73, v_c72, v_c75, v_c27}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:108", "delta:mp_union", _fires);
  
      if (!_done)
      {
        ReadTask367* _cont = new ReadTask367(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask367(db,b), false);
  // (crule (pre (let __tconst6x3F256 const5feceb66ffc86f38d952786c)) (scan mbranch __t1mbS254 p m l r) (body (join-old mp_del (1 2 0) 1 (1 2 0) __t1mbS254 k __t90gb255) (let __t5ss7257 (band k m)) (cmp gt __t5ss7257 __tconst6x3F256)) (head (emit $sup5638x84x0x0x0 (4 2 3 5 0 1) p l m r __t90gb255 k)) map.slog:85 #f)
  class ReadTask418 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_delindex416;  slog::Index** mp_deldelta417;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x84x0x0x0");
      std::vector<u16> ord419({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel420 = db->getRelation("$sup5638x84x0x0x0");
      head_index[0] = readrel420->getIndex(ord419, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord421({1, 2, 0});
      slog::Relation* readrel422 = db->getRelation("mp_del");
      mp_delindex416 = readrel422->getIndex(ord421, false);
      std::vector<u16> ord423({1, 2, 0});
      slog::Relation* readrel424 = db->getRelation("mp_del");
      mp_deldelta417 = readrel424->getIndex(ord423, true);
  
    }
    ReadTask418(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c107 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c108 = _t[0];
        u64 v_c30 = _t[1];
        u64 v_c31 = _t[2];
        u64 v_c32 = _t[3];
        u64 v_c33 = _t[4];
        slog::join_probe_old<3,1>(mp_delindex416, mp_deldelta417, std::array<u64,3>{v_c108, 0, 0}, [&](const std::array<u64,3>& m425) {
          u64 v_c34 = m425[1]; u64 v_c109 = m425[2];
          u64 v_c110 = _prim_band(db, v_c34, v_c31);
          if (v_c110 == slog_error) { slog::emit_pending_error(db, "map.slog:85"); return; }
          u64 v_c111 = _prim_gt(db, v_c110, v_c107);
          if (v_c111 == slog_error) { slog::emit_pending_error(db, "map.slog:85"); return; }
          if (!v_c111) return;
          ++_fires;
          slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c30, v_c32, v_c31, v_c33, v_c109, v_c34}, std::array<u16,6>{4, 2, 3, 5, 0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:85", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask418* _cont = new ReadTask418(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask418(db,b), false);
  // (crule (pre) (scan temp3Msk1947 __t7f1J316 j k v) (body (join mleaf (1 2 0) 2 k v __t7bYO315)) (head (mkstruct mp_join (1 2 3 4 0) __4P0H1417 k __t7bYO315 j __t7f1J316)) map.slog:39 #f)
  class ReadTask428 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mleafindex427;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_join");
      outer_rel = db->getRelation("temp3Msk1947");
      std::vector<u16> ord429({1, 2, 0});
      slog::Relation* readrel430 = db->getRelation("mleaf");
      mleafindex427 = readrel430->getIndex(ord429, false);
  
    }
    ReadTask428(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c113 = _t[1];
        u64 v_c34 = _t[2];
        u64 v_c28 = _t[3];
        slog::join_probe<3,2>(mleafindex427, std::array<u64,3>{v_c34, v_c28, 0}, [&](const std::array<u64,3>& m431) {
          u64 v_c114 = m431[2];
          ++_fires;
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c34, v_c114, v_c113, v_c112}, std::array<u16,5>{1, 2, 3, 4, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:39", "delta:temp3Msk1947", _fires);
  
      if (!_done)
      {
        ReadTask428* _cont = new ReadTask428(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask428(db,b), false);
  // (crule (pre) (scan mp_msk __t51z5346 q m) (body (exists $sup5638x98x0x0x0 (2 5 4 0 1 3 6 7 8) 2 m q) (join mp_msk_ans (0 1) 1 __t51z5346 p) (join $sup5638x98x0x0x0 (2 5 4 0 1 3 6 7 8) 3 m q p __d0 l n r u v)) (head (emit $sup5638x98x0x0x1 (0 7 1 2 3 4 5 6 8 9) __d0 r __t51z5346 l m n p q u v)) map.slog:99 #f)
  class ReadTask435 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x98x0x0x0index432;  slog::Index** mp_msk_ansindex433;  slog::Index** $sup5638x98x0x0x0index434;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x98x0x0x1");
      std::vector<u16> ord436({0, 7, 1, 2, 3, 4, 5, 6, 8, 9});
      slog::Relation* readrel437 = db->getRelation("$sup5638x98x0x0x1");
      head_index[0] = readrel437->getIndex(ord436, false);
      outer_rel = db->getRelation("mp_msk");
      std::vector<u16> ord438({2, 5, 4, 0, 1, 3, 6, 7, 8});
      slog::Relation* readrel439 = db->getRelation("$sup5638x98x0x0x0");
      $sup5638x98x0x0x0index432 = readrel439->getIndex(ord438, false);
      std::vector<u16> ord440({0, 1});
      slog::Relation* readrel441 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex433 = readrel441->getIndex(ord440, false);
      std::vector<u16> ord442({2, 5, 4, 0, 1, 3, 6, 7, 8});
      slog::Relation* readrel443 = db->getRelation("$sup5638x98x0x0x0");
      $sup5638x98x0x0x0index434 = readrel443->getIndex(ord442, false);
  
    }
    ReadTask435(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c115 = _t[0];
        u64 v_c73 = _t[1];
        u64 v_c31 = _t[2];
        if (!slog::exists_probe<9,2>($sup5638x98x0x0x0index432, std::array<u64,9>{v_c31, v_c73, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(mp_msk_ansindex433, std::array<u64,2>{v_c115, 0}, [&](const std::array<u64,2>& m444) {
          u64 v_c30 = m444[1];
          slog::join_probe<9,3>($sup5638x98x0x0x0index434, std::array<u64,9>{v_c31, v_c73, v_c30, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m445) {
            u64 v_c74 = m445[3]; u64 v_c32 = m445[4]; u64 v_c72 = m445[5]; u64 v_c33 = m445[6]; u64 v_c75 = m445[7]; u64 v_c28 = m445[8];
            ++_fires;
            slog::emit<10>(head_rel[0], head_index[0], newbatch[0], std::array<u64,10>{v_c74, v_c33, v_c115, v_c32, v_c31, v_c72, v_c30, v_c73, v_c75, v_c28}, std::array<u16,10>{0, 7, 1, 2, 3, 4, 5, 6, 8, 9});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:99", "delta:mp_msk", _fires);
  
      if (!_done)
      {
        ReadTask435* _cont = new ReadTask435(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask435(db,b), false);
  // (crule (pre (let __tconst6uLy1418 constcd2a69ce5ca278db1d6da969) (let _00024sqc5ZED979 constd4735e3a265e16eee03f5971) (let _00024sqc8Ktf980 const5feceb66ffc86f38d952786c) (let _00024sqc1r6Y981 const6b86b273ff34fce19d6b804e) (let _00024sqo4ml8982 const5feceb66ffc86f38d952786c) (let _00024sqo9GuQ983 const6b86b273ff34fce19d6b804e) (let _00024sqo9DrV984 const6b86b273ff34fce19d6b804e) (let _00024sqo0wvc985 const5feceb66ffc86f38d952786c) (let __trid2ZoU1419 constfdb0a95399e17c48d6f65653) (let __trel2kf41420 constdede4476644eb06b5a48b866) (let __tcol0QrU1421 const6b86b273ff34fce19d6b804e)) (probe $seq_at (1 0 2) 1 _00024sqo9GuQ983 __t0ebd433 _00024seq2) (body (join $seq_at (1 0 2) 3 _00024sqo4ml8982 __t0ebd433 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo9DrV984 __t0ebd433 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo0wvc985 __t0ebd433 _00024seq2) (join _enum (0 1) 2 __t0ebd433 __tconst6uLy1418) (join delta (2 0 1) 1 _00024seq2 __t9b4a431 op) (join arithmetic_op (0) 1 op) (letp _00024sql4NVe977 (aslst _00024seq2)) (let chk5xm11862 (llen _00024sql4NVe977)) (eq _00024sqc5ZED979 chk5xm11862) (letp chk7H4y1863 (lref _00024sql4NVe977 _00024sqc8Ktf980)) (eq __t0ebd433 chk7H4y1863) (letp chk1VlX1864 (lref _00024sql4NVe977 _00024sqc1r6Y981)) (eq __t0ebd433 chk1VlX1864)) (head (tycheck __t0ebd433 (accept (struct boolval) (struct closure) (struct _enum) (struct prim) (struct symval)) __trid2ZoU1419 __trel2kf41420 __tcol0QrU1421 (1 2 3 4 0)) (emit delta_ans (0 1) __t9b4a431 __t0ebd433)) interp.slog:116 #f)
  class ReadTask459 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex446;  slog::Index** $seq_atrindex447;  slog::Index** $seq_atrindex448;  slog::Index** _enumindex449;  slog::Index** deltaindex450;  slog::Index** arithmetic_opindex451;  slog::Index** $seq_atrdelta452;  slog::Index** $seq_atrdelta453;
    u32 sid456;  u32 sid454;  u32 sid455;  u32 sid457;  u32 sid458;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("delta_ans");
      std::vector<u16> ord460({0, 1});
      slog::Relation* readrel461 = db->getRelation("delta_ans");
      head_index[1] = readrel461->getIndex(ord460, false);
      std::vector<u16> ord462({1, 0, 2});
      slog::Relation* readrel463 = db->getRelation("$seq_at");
      driver_index = readrel463->getIndex(ord462, true);
      std::vector<u16> ord464({1, 0, 2});
      slog::Relation* readrel465 = db->getRelation("$seq_at");
      $seq_atindex446 = readrel465->getIndex(ord464, false);
      std::vector<u16> ord466({1, 0, 2});
      slog::Relation* readrel467 = db->getRelation("$seq_atr");
      $seq_atrindex447 = readrel467->getIndex(ord466, false);
      std::vector<u16> ord468({1, 0, 2});
      slog::Relation* readrel469 = db->getRelation("$seq_atr");
      $seq_atrdelta452 = readrel469->getIndex(ord468, true);
      std::vector<u16> ord470({1, 0, 2});
      slog::Relation* readrel471 = db->getRelation("$seq_atr");
      $seq_atrindex448 = readrel471->getIndex(ord470, false);
      std::vector<u16> ord472({1, 0, 2});
      slog::Relation* readrel473 = db->getRelation("$seq_atr");
      $seq_atrdelta453 = readrel473->getIndex(ord472, true);
      std::vector<u16> ord474({0, 1});
      slog::Relation* readrel475 = db->getRelation("_enum");
      _enumindex449 = readrel475->getIndex(ord474, false);
      std::vector<u16> ord476({2, 0, 1});
      slog::Relation* readrel477 = db->getRelation("delta");
      deltaindex450 = readrel477->getIndex(ord476, false);
      std::vector<u16> ord478({0});
      slog::Relation* readrel479 = db->getRelation("arithmetic_op");
      arithmetic_opindex451 = readrel479->getIndex(ord478, false);
      sid456 = db->getRelation("_enum")->getStructId();
      sid454 = db->getRelation("boolval")->getStructId();
      sid455 = db->getRelation("closure")->getStructId();
      sid457 = db->getRelation("prim")->getStructId();
      sid458 = db->getRelation("symval")->getStructId();
  
    }
    ReadTask459(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c116 = v_constcd2a69ce5ca278db1d6da969;
      u64 v_c117 = v_constd4735e3a265e16eee03f5971;
      u64 v_c118 = v_const5feceb66ffc86f38d952786c;
      u64 v_c119 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c120 = v_const5feceb66ffc86f38d952786c;
      u64 v_c121 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c122 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c123 = v_const5feceb66ffc86f38d952786c;
      u64 v_c124 = v_constfdb0a95399e17c48d6f65653;
      u64 v_c125 = v_constdede4476644eb06b5a48b866;
      u64 v_c126 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c121, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m480) {
        u64 v_c127 = m480[1];
        u64 v_c62 = m480[2];
        if (buckethash(v_c127) != bucket) return;
        slog::join_probe<3,3>($seq_atindex446, std::array<u64,3>{v_c120, v_c127, v_c62}, [&](const std::array<u64,3>& m481) {
          slog::join_probe_old<3,3>($seq_atrindex447, $seq_atrdelta452, std::array<u64,3>{v_c122, v_c127, v_c62}, [&](const std::array<u64,3>& m482) {
            slog::join_probe_old<3,3>($seq_atrindex448, $seq_atrdelta453, std::array<u64,3>{v_c123, v_c127, v_c62}, [&](const std::array<u64,3>& m483) {
              slog::join_probe<2,2>(_enumindex449, std::array<u64,2>{v_c127, v_c116}, [&](const std::array<u64,2>& m484) {
                slog::join_probe<3,1>(deltaindex450, std::array<u64,3>{v_c62, 0, 0}, [&](const std::array<u64,3>& m485) {
                  u64 v_c128 = m485[1]; u64 v_c129 = m485[2];
                  slog::join_probe<1,1>(arithmetic_opindex451, std::array<u64,1>{v_c129}, [&](const std::array<u64,1>& m486) {
                    bool ok487 = true;
                    u64 v_c130 = _prim_aslst(db, v_c62, &ok487);
                    if (!ok487) return;
                    u64 v_c131 = _prim_llen(db, v_c130);
                    if (v_c131 == slog_error) { slog::emit_pending_error(db, "interp.slog:116"); return; }
                    if (v_c117 != v_c131) return;
                    bool ok488 = true;
                    u64 v_c132 = _prim_lref(db, v_c130, v_c118, &ok488);
                    if (!ok488) return;
                    if (v_c127 != v_c132) return;
                    bool ok489 = true;
                    u64 v_c133 = _prim_lref(db, v_c130, v_c119, &ok489);
                    if (!ok489) return;
                    if (v_c127 != v_c133) return;
                    ++_fires;
                    if (!((is_struct(v_c127) && (decode_struct_id(v_c127) == sid454 || decode_struct_id(v_c127) == sid455 || decode_struct_id(v_c127) == sid456 || decode_struct_id(v_c127) == sid457 || decode_struct_id(v_c127) == sid458))))
                    {
                      slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c124, v_c125, v_c126, v_c127}, std::array<u16,5>{1, 2, 3, 4, 0});
                      return;
                    }
                    slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c128, v_c127}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:116", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask459* _cont = new ReadTask459(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask459(db,b), false);
  // (crule (pre (let __tconst0g0f1135 constd01925b37634a1a9d24159d8)) (scan mp_del __t69Uy426 __t8pgc425 k) (body (exists _enum (1 0) 1 __tconst0g0f1135) (join mleaf (0 1 2) 2 __t8pgc425 k v) (join _enum (1 0) 1 __tconst0g0f1135 __t3QLG424)) (head (emit mp_del_ans (0 1) __t69Uy426 __t3QLG424)) map.slog:80 #f)
  class ReadTask493 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex490;  slog::Index** mleafindex491;  slog::Index** _enumindex492;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_del_ans");
      std::vector<u16> ord494({0, 1});
      slog::Relation* readrel495 = db->getRelation("mp_del_ans");
      head_index[0] = readrel495->getIndex(ord494, false);
      outer_rel = db->getRelation("mp_del");
      std::vector<u16> ord496({1, 0});
      slog::Relation* readrel497 = db->getRelation("_enum");
      _enumindex490 = readrel497->getIndex(ord496, false);
      std::vector<u16> ord498({0, 1, 2});
      slog::Relation* readrel499 = db->getRelation("mleaf");
      mleafindex491 = readrel499->getIndex(ord498, false);
      std::vector<u16> ord500({1, 0});
      slog::Relation* readrel501 = db->getRelation("_enum");
      _enumindex492 = readrel501->getIndex(ord500, false);
  
    }
    ReadTask493(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c134 = v_constd01925b37634a1a9d24159d8;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c135 = _t[0];
        u64 v_c136 = _t[1];
        u64 v_c34 = _t[2];
        if (!slog::exists_probe<2,1>(_enumindex490, std::array<u64,2>{v_c134, 0})) return;
        slog::join_probe<3,2>(mleafindex491, std::array<u64,3>{v_c136, v_c34, 0}, [&](const std::array<u64,3>& m502) {
          u64 v_c28 = m502[2];
          slog::join_probe<2,1>(_enumindex492, std::array<u64,2>{v_c134, 0}, [&](const std::array<u64,2>& m503) {
            u64 v_c137 = m503[1];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c135, v_c137}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:80", "delta:mp_del", _fires);
  
      if (!_done)
      {
        ReadTask493* _cont = new ReadTask493(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask493(db,b), false);
  // (crule (pre) (scan mp_union __t7E2l604 s __t5Ivz603) (body (exists mp_put_soft (1 2 3 0) 1 s) (join mleaf (0 1 2) 1 __t5Ivz603 k v) (join-old mp_put_soft (1 2 3 0) 3 (1 2 3 0) s k v __t5GLK605) (join mp_put_soft_ans (0 1) 1 __t5GLK605 r)) (head (emit mp_union_ans (0 1) __t7E2l604 r)) map.slog:93 #f)
  class ReadTask509 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_put_softindex504;  slog::Index** mleafindex505;  slog::Index** mp_put_softindex506;  slog::Index** mp_put_soft_ansindex507;  slog::Index** mp_put_softdelta508;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord510({0, 1});
      slog::Relation* readrel511 = db->getRelation("mp_union_ans");
      head_index[0] = readrel511->getIndex(ord510, false);
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord512({1, 2, 3, 0});
      slog::Relation* readrel513 = db->getRelation("mp_put_soft");
      mp_put_softindex504 = readrel513->getIndex(ord512, false);
      std::vector<u16> ord514({0, 1, 2});
      slog::Relation* readrel515 = db->getRelation("mleaf");
      mleafindex505 = readrel515->getIndex(ord514, false);
      std::vector<u16> ord516({1, 2, 3, 0});
      slog::Relation* readrel517 = db->getRelation("mp_put_soft");
      mp_put_softindex506 = readrel517->getIndex(ord516, false);
      std::vector<u16> ord518({1, 2, 3, 0});
      slog::Relation* readrel519 = db->getRelation("mp_put_soft");
      mp_put_softdelta508 = readrel519->getIndex(ord518, true);
      std::vector<u16> ord520({0, 1});
      slog::Relation* readrel521 = db->getRelation("mp_put_soft_ans");
      mp_put_soft_ansindex507 = readrel521->getIndex(ord520, false);
  
    }
    ReadTask509(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c81 = _t[1];
        u64 v_c139 = _t[2];
        if (!slog::exists_probe<4,1>(mp_put_softindex504, std::array<u64,4>{v_c81, 0, 0, 0})) return;
        slog::join_probe<3,1>(mleafindex505, std::array<u64,3>{v_c139, 0, 0}, [&](const std::array<u64,3>& m522) {
          u64 v_c34 = m522[1]; u64 v_c28 = m522[2];
          slog::join_probe_old<4,3>(mp_put_softindex506, mp_put_softdelta508, std::array<u64,4>{v_c81, v_c34, v_c28, 0}, [&](const std::array<u64,4>& m523) {
            u64 v_c140 = m523[3];
            slog::join_probe<2,1>(mp_put_soft_ansindex507, std::array<u64,2>{v_c140, 0}, [&](const std::array<u64,2>& m524) {
              u64 v_c33 = m524[1];
              ++_fires;
              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c138, v_c33}, std::array<u16,2>{0, 1});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:93", "delta:mp_union", _fires);
  
      if (!_done)
      {
        ReadTask509* _cont = new ReadTask509(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask509(db,b), false);
  // (crule (pre (let __tconst3ZiI681 const5feceb66ffc86f38d952786c)) (scan mp_union __t5Sgr680 __t0Aux684 __t105R678) (body (exists $sup5638x107x0x0x0 (0 8 1 2 3 4 5 6 7) 1 __t5Sgr680) (exists $sup5638x107x0x0x1 (0 9 1 2 3 4 5 6 7 8) 1 __t5Sgr680) (join-old mp_union (1 2 0) 1 (1 2 0) __t0Aux684 v __t6NDF685) (exists $sup5638x107x0x0x0 (0 8 1 2 3 4 5 6 7) 2 __t5Sgr680 v) (exists $sup5638x107x0x0x1 (0 9 1 2 3 4 5 6 7 8) 2 __t5Sgr680 v) (exists mp_union_ans (0 1) 1 __t6NDF685) (join mbranch (4 0 1 2 3) 2 v __t105R678 q n u) (exists $sup5638x107x0x0x1 (9 4 6 8 0 2 3 5 7 1) 5 v n q u __t5Sgr680) (exists mp_msk (2 0 1) 1 n) (exists mp_msk_ans (1 0) 1 q) (join $sup5638x107x0x0x0 (5 3 7 8 0 1 2 4 6) 5 q n u v __t5Sgr680 l m p r) (cmp lt m n) (exists mbranch (1 2 3 4 0) 5 p m l r __t0Aux684) (exists mp_msk (1 2 0) 2 p n) (join $sup5638x107x0x0x1 (9 4 6 8 0 2 3 5 7 1) 9 v n q u __t5Sgr680 l m p r __t78qG683) (join-old mbranch (1 2 3 4 0) 5 (1 2 3 4 0) p m l r __t0Aux684) (join-old mp_msk (1 2 0) 3 (1 2 0) p n __t78qG683) (join mp_msk_ans (0 1) 2 __t78qG683 q) (join mp_union_ans (0 1) 1 __t6NDF685 __v0) (let __t90AV682 (band p n)) (cmp gt __t90AV682 __tconst3ZiI681)) (head (emit-temp temp9jSj1946 __t5Sgr680 __v0 n q u) (mkstruct mbranch (1 2 3 4 0) __t287h677 q n u __v0)) map.slog:108 #f)
  class ReadTask546 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x107x0x0x0index525;  slog::Index** $sup5638x107x0x0x1index526;  slog::Index** mp_unionindex527;  slog::Index** $sup5638x107x0x0x0index528;  slog::Index** $sup5638x107x0x0x1index529;  slog::Index** mp_union_ansindex530;  slog::Index** mbranchindex531;  slog::Index** $sup5638x107x0x0x1index532;  slog::Index** mp_mskindex533;  slog::Index** mp_msk_ansindex534;  slog::Index** $sup5638x107x0x0x0index535;  slog::Index** mbranchindex536;  slog::Index** mp_mskindex537;  slog::Index** $sup5638x107x0x0x1index538;  slog::Index** mbranchindex539;  slog::Index** mp_mskindex540;  slog::Index** mp_msk_ansindex541;  slog::Index** mp_union_ansindex542;  slog::Index** mp_uniondelta543;  slog::Index** mbranchdelta544;  slog::Index** mp_mskdelta545;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9jSj1946");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord547({0, 8, 1, 2, 3, 4, 5, 6, 7});
      slog::Relation* readrel548 = db->getRelation("$sup5638x107x0x0x0");
      $sup5638x107x0x0x0index525 = readrel548->getIndex(ord547, false);
      std::vector<u16> ord549({0, 9, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel550 = db->getRelation("$sup5638x107x0x0x1");
      $sup5638x107x0x0x1index526 = readrel550->getIndex(ord549, false);
      std::vector<u16> ord551({1, 2, 0});
      slog::Relation* readrel552 = db->getRelation("mp_union");
      mp_unionindex527 = readrel552->getIndex(ord551, false);
      std::vector<u16> ord553({1, 2, 0});
      slog::Relation* readrel554 = db->getRelation("mp_union");
      mp_uniondelta543 = readrel554->getIndex(ord553, true);
      std::vector<u16> ord555({0, 8, 1, 2, 3, 4, 5, 6, 7});
      slog::Relation* readrel556 = db->getRelation("$sup5638x107x0x0x0");
      $sup5638x107x0x0x0index528 = readrel556->getIndex(ord555, false);
      std::vector<u16> ord557({0, 9, 1, 2, 3, 4, 5, 6, 7, 8});
      slog::Relation* readrel558 = db->getRelation("$sup5638x107x0x0x1");
      $sup5638x107x0x0x1index529 = readrel558->getIndex(ord557, false);
      std::vector<u16> ord559({0, 1});
      slog::Relation* readrel560 = db->getRelation("mp_union_ans");
      mp_union_ansindex530 = readrel560->getIndex(ord559, false);
      std::vector<u16> ord561({4, 0, 1, 2, 3});
      slog::Relation* readrel562 = db->getRelation("mbranch");
      mbranchindex531 = readrel562->getIndex(ord561, false);
      std::vector<u16> ord563({9, 4, 6, 8, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel564 = db->getRelation("$sup5638x107x0x0x1");
      $sup5638x107x0x0x1index532 = readrel564->getIndex(ord563, false);
      std::vector<u16> ord565({2, 0, 1});
      slog::Relation* readrel566 = db->getRelation("mp_msk");
      mp_mskindex533 = readrel566->getIndex(ord565, false);
      std::vector<u16> ord567({1, 0});
      slog::Relation* readrel568 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex534 = readrel568->getIndex(ord567, false);
      std::vector<u16> ord569({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel570 = db->getRelation("$sup5638x107x0x0x0");
      $sup5638x107x0x0x0index535 = readrel570->getIndex(ord569, false);
      std::vector<u16> ord571({1, 2, 3, 4, 0});
      slog::Relation* readrel572 = db->getRelation("mbranch");
      mbranchindex536 = readrel572->getIndex(ord571, false);
      std::vector<u16> ord573({1, 2, 0});
      slog::Relation* readrel574 = db->getRelation("mp_msk");
      mp_mskindex537 = readrel574->getIndex(ord573, false);
      std::vector<u16> ord575({9, 4, 6, 8, 0, 2, 3, 5, 7, 1});
      slog::Relation* readrel576 = db->getRelation("$sup5638x107x0x0x1");
      $sup5638x107x0x0x1index538 = readrel576->getIndex(ord575, false);
      std::vector<u16> ord577({1, 2, 3, 4, 0});
      slog::Relation* readrel578 = db->getRelation("mbranch");
      mbranchindex539 = readrel578->getIndex(ord577, false);
      std::vector<u16> ord579({1, 2, 3, 4, 0});
      slog::Relation* readrel580 = db->getRelation("mbranch");
      mbranchdelta544 = readrel580->getIndex(ord579, true);
      std::vector<u16> ord581({1, 2, 0});
      slog::Relation* readrel582 = db->getRelation("mp_msk");
      mp_mskindex540 = readrel582->getIndex(ord581, false);
      std::vector<u16> ord583({1, 2, 0});
      slog::Relation* readrel584 = db->getRelation("mp_msk");
      mp_mskdelta545 = readrel584->getIndex(ord583, true);
      std::vector<u16> ord585({0, 1});
      slog::Relation* readrel586 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex541 = readrel586->getIndex(ord585, false);
      std::vector<u16> ord587({0, 1});
      slog::Relation* readrel588 = db->getRelation("mp_union_ans");
      mp_union_ansindex542 = readrel588->getIndex(ord587, false);
  
    }
    ReadTask546(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c98 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c102 = _t[0];
        u64 v_c100 = _t[1];
        u64 v_c101 = _t[2];
        if (!slog::exists_probe<9,1>($sup5638x107x0x0x0index525, std::array<u64,9>{v_c102, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<10,1>($sup5638x107x0x0x1index526, std::array<u64,10>{v_c102, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(mp_unionindex527, mp_uniondelta543, std::array<u64,3>{v_c100, 0, 0}, [&](const std::array<u64,3>& m589) {
          u64 v_c28 = m589[1]; u64 v_c99 = m589[2];
          if (!slog::exists_probe<9,2>($sup5638x107x0x0x0index528, std::array<u64,9>{v_c102, v_c28, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<10,2>($sup5638x107x0x0x1index529, std::array<u64,10>{v_c102, v_c28, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<2,1>(mp_union_ansindex530, std::array<u64,2>{v_c99, 0})) return;
          slog::join_probe<5,2>(mbranchindex531, std::array<u64,5>{v_c28, v_c101, 0, 0, 0}, [&](const std::array<u64,5>& m590) {
            u64 v_c73 = m590[2]; u64 v_c72 = m590[3]; u64 v_c75 = m590[4];
            if (!slog::exists_probe<10,5>($sup5638x107x0x0x1index532, std::array<u64,10>{v_c28, v_c72, v_c73, v_c75, v_c102, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<3,1>(mp_mskindex533, std::array<u64,3>{v_c72, 0, 0})) return;
            if (!slog::exists_probe<2,1>(mp_msk_ansindex534, std::array<u64,2>{v_c73, 0})) return;
            slog::join_probe<9,5>($sup5638x107x0x0x0index535, std::array<u64,9>{v_c73, v_c72, v_c75, v_c28, v_c102, 0, 0, 0, 0}, [&](const std::array<u64,9>& m591) {
              u64 v_c32 = m591[5]; u64 v_c31 = m591[6]; u64 v_c30 = m591[7]; u64 v_c33 = m591[8];
              u64 v_c141 = _prim_lt(db, v_c31, v_c72);
              if (v_c141 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
              if (!v_c141) return;
              if (!slog::exists_probe<5,5>(mbranchindex536, std::array<u64,5>{v_c30, v_c31, v_c32, v_c33, v_c100})) return;
              if (!slog::exists_probe<3,2>(mp_mskindex537, std::array<u64,3>{v_c30, v_c72, 0})) return;
              slog::join_probe<10,9>($sup5638x107x0x0x1index538, std::array<u64,10>{v_c28, v_c72, v_c73, v_c75, v_c102, v_c32, v_c31, v_c30, v_c33, 0}, [&](const std::array<u64,10>& m593) {
                u64 v_c104 = m593[9];
                slog::join_probe_old<5,5>(mbranchindex539, mbranchdelta544, std::array<u64,5>{v_c30, v_c31, v_c32, v_c33, v_c100}, [&](const std::array<u64,5>& m594) {
                  slog::join_probe_old<3,3>(mp_mskindex540, mp_mskdelta545, std::array<u64,3>{v_c30, v_c72, v_c104}, [&](const std::array<u64,3>& m595) {
                    slog::join_probe<2,2>(mp_msk_ansindex541, std::array<u64,2>{v_c104, v_c73}, [&](const std::array<u64,2>& m596) {
                      slog::join_probe<2,1>(mp_union_ansindex542, std::array<u64,2>{v_c99, 0}, [&](const std::array<u64,2>& m597) {
                        u64 v_c27 = m597[1];
                        u64 v_c105 = _prim_band(db, v_c30, v_c72);
                        if (v_c105 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
                        u64 v_c142 = _prim_gt(db, v_c105, v_c98);
                        if (v_c142 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
                        if (!v_c142) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c102, v_c27, v_c72, v_c73, v_c75});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c73, v_c72, v_c75, v_c27}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:108", "delta:mp_union", _fires);
  
      if (!_done)
      {
        ReadTask546* _cont = new ReadTask546(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask546(db,b), false);
  // (crule (pre) (scan mp_put __t4a7n626 __t8ls4627 k v) (body (exists mp_join (1 4 2 0 3) 2 k __t8ls4627) (join-old mleaf (1 2 0) 2 (1 2 0) k v __t6AYq628) (join-old mp_join (1 4 2 0 3) 3 (1 4 2 0 3) k __t8ls4627 __t6AYq628 __t5fYY629 j) (neq j k) (exists mp_join_ans (0 1) 1 __t5fYY629) (join-old mleaf (0 1 2) 2 (0 1 2) __t8ls4627 j w) (join mp_join_ans (0 1) 1 __t5fYY629 r)) (head (emit mp_put_ans (0 1) __t4a7n626 r)) map.slog:39 #f)
  class ReadTask608 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_joinindex599;  slog::Index** mleafindex600;  slog::Index** mp_joinindex601;  slog::Index** mp_join_ansindex602;  slog::Index** mleafindex603;  slog::Index** mp_join_ansindex604;  slog::Index** mleafdelta605;  slog::Index** mp_joindelta606;  slog::Index** mleafdelta607;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_ans");
      std::vector<u16> ord609({0, 1});
      slog::Relation* readrel610 = db->getRelation("mp_put_ans");
      head_index[0] = readrel610->getIndex(ord609, false);
      outer_rel = db->getRelation("mp_put");
      std::vector<u16> ord611({1, 4, 2, 0, 3});
      slog::Relation* readrel612 = db->getRelation("mp_join");
      mp_joinindex599 = readrel612->getIndex(ord611, false);
      std::vector<u16> ord613({1, 2, 0});
      slog::Relation* readrel614 = db->getRelation("mleaf");
      mleafindex600 = readrel614->getIndex(ord613, false);
      std::vector<u16> ord615({1, 2, 0});
      slog::Relation* readrel616 = db->getRelation("mleaf");
      mleafdelta605 = readrel616->getIndex(ord615, true);
      std::vector<u16> ord617({1, 4, 2, 0, 3});
      slog::Relation* readrel618 = db->getRelation("mp_join");
      mp_joinindex601 = readrel618->getIndex(ord617, false);
      std::vector<u16> ord619({1, 4, 2, 0, 3});
      slog::Relation* readrel620 = db->getRelation("mp_join");
      mp_joindelta606 = readrel620->getIndex(ord619, true);
      std::vector<u16> ord621({0, 1});
      slog::Relation* readrel622 = db->getRelation("mp_join_ans");
      mp_join_ansindex602 = readrel622->getIndex(ord621, false);
      std::vector<u16> ord623({0, 1, 2});
      slog::Relation* readrel624 = db->getRelation("mleaf");
      mleafindex603 = readrel624->getIndex(ord623, false);
      std::vector<u16> ord625({0, 1, 2});
      slog::Relation* readrel626 = db->getRelation("mleaf");
      mleafdelta607 = readrel626->getIndex(ord625, true);
      std::vector<u16> ord627({0, 1});
      slog::Relation* readrel628 = db->getRelation("mp_join_ans");
      mp_join_ansindex604 = readrel628->getIndex(ord627, false);
  
    }
    ReadTask608(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c143 = _t[0];
        u64 v_c144 = _t[1];
        u64 v_c34 = _t[2];
        u64 v_c28 = _t[3];
        if (!slog::exists_probe<5,2>(mp_joinindex599, std::array<u64,5>{v_c34, v_c144, 0, 0, 0})) return;
        slog::join_probe_old<3,2>(mleafindex600, mleafdelta605, std::array<u64,3>{v_c34, v_c28, 0}, [&](const std::array<u64,3>& m629) {
          u64 v_c145 = m629[2];
          slog::join_probe_old<5,3>(mp_joinindex601, mp_joindelta606, std::array<u64,5>{v_c34, v_c144, v_c145, 0, 0}, [&](const std::array<u64,5>& m630) {
            u64 v_c146 = m630[3]; u64 v_c113 = m630[4];
            if (v_c113 == v_c34) return;
            if (!slog::exists_probe<2,1>(mp_join_ansindex602, std::array<u64,2>{v_c146, 0})) return;
            slog::join_probe_old<3,2>(mleafindex603, mleafdelta607, std::array<u64,3>{v_c144, v_c113, 0}, [&](const std::array<u64,3>& m631) {
              u64 v_c147 = m631[2];
              slog::join_probe<2,1>(mp_join_ansindex604, std::array<u64,2>{v_c146, 0}, [&](const std::array<u64,2>& m632) {
                u64 v_c33 = m632[1];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c143, v_c33}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:39", "delta:mp_put", _fires);
  
      if (!_done)
      {
        ReadTask608* _cont = new ReadTask608(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask608(db,b), false);
  // (crule (pre) (scan $sup5638x42x0x0x0 __d0 k l m p r v) (body (exists mp_msk_ans (1 0) 1 p) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t95lh295) (join-old mp_msk_ans (0 1) 2 (0 1) __t95lh295 p)) (head (emit $sup5638x42x0x0x1 (1 5 0 2 3 4 6 7) __t95lh295 p __d0 k l m r v)) map.slog:43 #f)
  class ReadTask638 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_msk_ansindex633;  slog::Index** mp_mskindex634;  slog::Index** mp_msk_ansindex635;  slog::Index** mp_mskdelta636;  slog::Index** mp_msk_ansdelta637;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x42x0x0x1");
      std::vector<u16> ord639({1, 5, 0, 2, 3, 4, 6, 7});
      slog::Relation* readrel640 = db->getRelation("$sup5638x42x0x0x1");
      head_index[0] = readrel640->getIndex(ord639, false);
      outer_rel = db->getRelation("$sup5638x42x0x0x0");
      std::vector<u16> ord641({1, 0});
      slog::Relation* readrel642 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex633 = readrel642->getIndex(ord641, false);
      std::vector<u16> ord643({1, 2, 0});
      slog::Relation* readrel644 = db->getRelation("mp_msk");
      mp_mskindex634 = readrel644->getIndex(ord643, false);
      std::vector<u16> ord645({1, 2, 0});
      slog::Relation* readrel646 = db->getRelation("mp_msk");
      mp_mskdelta636 = readrel646->getIndex(ord645, true);
      std::vector<u16> ord647({0, 1});
      slog::Relation* readrel648 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex635 = readrel648->getIndex(ord647, false);
      std::vector<u16> ord649({0, 1});
      slog::Relation* readrel650 = db->getRelation("mp_msk_ans");
      mp_msk_ansdelta637 = readrel650->getIndex(ord649, true);
  
    }
    ReadTask638(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c74 = _t[0];
        u64 v_c34 = _t[1];
        u64 v_c32 = _t[2];
        u64 v_c31 = _t[3];
        u64 v_c30 = _t[4];
        u64 v_c33 = _t[5];
        u64 v_c28 = _t[6];
        if (!slog::exists_probe<2,1>(mp_msk_ansindex633, std::array<u64,2>{v_c30, 0})) return;
        slog::join_probe_old<3,2>(mp_mskindex634, mp_mskdelta636, std::array<u64,3>{v_c34, v_c31, 0}, [&](const std::array<u64,3>& m651) {
          u64 v_c148 = m651[2];
          slog::join_probe_old<2,2>(mp_msk_ansindex635, mp_msk_ansdelta637, std::array<u64,2>{v_c148, v_c30}, [&](const std::array<u64,2>& m652) {
            ++_fires;
            slog::emit<8>(head_rel[0], head_index[0], newbatch[0], std::array<u64,8>{v_c148, v_c30, v_c74, v_c34, v_c32, v_c31, v_c33, v_c28}, std::array<u16,8>{1, 5, 0, 2, 3, 4, 6, 7});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:43", "delta:$sup5638x42x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask638* _cont = new ReadTask638(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask638(db,b), false);
  // (crule (pre) (scan mp_union_ans __t4atM456 __v1) (body (join-old mp_union (0 1 2) 1 (0 1 2) __t4atM456 r v) (exists mbranch (4 0 1 2 3) 1 v) (exists mbranch (4 0 1 2 3) 1 r) (join-old $sup5638x93x0x0x0 (4 6 0 1 2 3 5) 2 (4 6 0 1 2 3 5) r v __t70BJ454 l m p u) (exists mbranch (1 2 3 4 0) 4 p m l r) (exists mp_union (1 2 0) 2 l u) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m u v __t1p4P452) (exists mp_union (2 0 1) 2 __t1p4P452 __t70BJ454) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t4xjy453) (join-old mp_union (0 1 2) 3 (0 1 2) __t70BJ454 __t4xjy453 __t1p4P452) (join-old mp_union (1 2 0) 2 (1 2 0) l u __t1OdF455) (join mp_union_ans (0 1) 1 __t1OdF455 __v0)) (head (emit-temp temp9Yrn2045 __t70BJ454 __v0 __v1 m p) (mkstruct mbranch (1 2 3 4 0) __t8Q9x451 p m __v0 __v1)) map.slog:94 #f)
  class ReadTask671 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_unionindex653;  slog::Index** mbranchindex654;  slog::Index** mbranchindex655;  slog::Index** $sup5638x93x0x0x0index656;  slog::Index** mbranchindex657;  slog::Index** mp_unionindex658;  slog::Index** mbranchindex659;  slog::Index** mp_unionindex660;  slog::Index** mbranchindex661;  slog::Index** mp_unionindex662;  slog::Index** mp_unionindex663;  slog::Index** mp_union_ansindex664;  slog::Index** mp_uniondelta665;  slog::Index** $sup5638x93x0x0x0delta666;  slog::Index** mbranchdelta667;  slog::Index** mbranchdelta668;  slog::Index** mp_uniondelta669;  slog::Index** mp_uniondelta670;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9Yrn2045");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_union_ans");
      std::vector<u16> ord672({0, 1, 2});
      slog::Relation* readrel673 = db->getRelation("mp_union");
      mp_unionindex653 = readrel673->getIndex(ord672, false);
      std::vector<u16> ord674({0, 1, 2});
      slog::Relation* readrel675 = db->getRelation("mp_union");
      mp_uniondelta665 = readrel675->getIndex(ord674, true);
      std::vector<u16> ord676({4, 0, 1, 2, 3});
      slog::Relation* readrel677 = db->getRelation("mbranch");
      mbranchindex654 = readrel677->getIndex(ord676, false);
      std::vector<u16> ord678({4, 0, 1, 2, 3});
      slog::Relation* readrel679 = db->getRelation("mbranch");
      mbranchindex655 = readrel679->getIndex(ord678, false);
      std::vector<u16> ord680({4, 6, 0, 1, 2, 3, 5});
      slog::Relation* readrel681 = db->getRelation("$sup5638x93x0x0x0");
      $sup5638x93x0x0x0index656 = readrel681->getIndex(ord680, false);
      std::vector<u16> ord682({4, 6, 0, 1, 2, 3, 5});
      slog::Relation* readrel683 = db->getRelation("$sup5638x93x0x0x0");
      $sup5638x93x0x0x0delta666 = readrel683->getIndex(ord682, true);
      std::vector<u16> ord684({1, 2, 3, 4, 0});
      slog::Relation* readrel685 = db->getRelation("mbranch");
      mbranchindex657 = readrel685->getIndex(ord684, false);
      std::vector<u16> ord686({1, 2, 0});
      slog::Relation* readrel687 = db->getRelation("mp_union");
      mp_unionindex658 = readrel687->getIndex(ord686, false);
      std::vector<u16> ord688({1, 2, 3, 4, 0});
      slog::Relation* readrel689 = db->getRelation("mbranch");
      mbranchindex659 = readrel689->getIndex(ord688, false);
      std::vector<u16> ord690({1, 2, 3, 4, 0});
      slog::Relation* readrel691 = db->getRelation("mbranch");
      mbranchdelta667 = readrel691->getIndex(ord690, true);
      std::vector<u16> ord692({2, 0, 1});
      slog::Relation* readrel693 = db->getRelation("mp_union");
      mp_unionindex660 = readrel693->getIndex(ord692, false);
      std::vector<u16> ord694({1, 2, 3, 4, 0});
      slog::Relation* readrel695 = db->getRelation("mbranch");
      mbranchindex661 = readrel695->getIndex(ord694, false);
      std::vector<u16> ord696({1, 2, 3, 4, 0});
      slog::Relation* readrel697 = db->getRelation("mbranch");
      mbranchdelta668 = readrel697->getIndex(ord696, true);
      std::vector<u16> ord698({0, 1, 2});
      slog::Relation* readrel699 = db->getRelation("mp_union");
      mp_unionindex662 = readrel699->getIndex(ord698, false);
      std::vector<u16> ord700({0, 1, 2});
      slog::Relation* readrel701 = db->getRelation("mp_union");
      mp_uniondelta669 = readrel701->getIndex(ord700, true);
      std::vector<u16> ord702({1, 2, 0});
      slog::Relation* readrel703 = db->getRelation("mp_union");
      mp_unionindex663 = readrel703->getIndex(ord702, false);
      std::vector<u16> ord704({1, 2, 0});
      slog::Relation* readrel705 = db->getRelation("mp_union");
      mp_uniondelta670 = readrel705->getIndex(ord704, true);
      std::vector<u16> ord706({0, 1});
      slog::Relation* readrel707 = db->getRelation("mp_union_ans");
      mp_union_ansindex664 = readrel707->getIndex(ord706, false);
  
    }
    ReadTask671(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c149 = _t[0];
        u64 v_c40 = _t[1];
        slog::join_probe_old<3,1>(mp_unionindex653, mp_uniondelta665, std::array<u64,3>{v_c149, 0, 0}, [&](const std::array<u64,3>& m708) {
          u64 v_c33 = m708[1]; u64 v_c28 = m708[2];
          if (!slog::exists_probe<5,1>(mbranchindex654, std::array<u64,5>{v_c28, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>(mbranchindex655, std::array<u64,5>{v_c33, 0, 0, 0, 0})) return;
          slog::join_probe_old<7,2>($sup5638x93x0x0x0index656, $sup5638x93x0x0x0delta666, std::array<u64,7>{v_c33, v_c28, 0, 0, 0, 0, 0}, [&](const std::array<u64,7>& m709) {
            u64 v_c150 = m709[2]; u64 v_c32 = m709[3]; u64 v_c31 = m709[4]; u64 v_c30 = m709[5]; u64 v_c75 = m709[6];
            if (!slog::exists_probe<5,4>(mbranchindex657, std::array<u64,5>{v_c30, v_c31, v_c32, v_c33, 0})) return;
            if (!slog::exists_probe<3,2>(mp_unionindex658, std::array<u64,3>{v_c32, v_c75, 0})) return;
            slog::join_probe_old<5,4>(mbranchindex659, mbranchdelta667, std::array<u64,5>{v_c30, v_c31, v_c75, v_c28, 0}, [&](const std::array<u64,5>& m710) {
              u64 v_c151 = m710[4];
              if (!slog::exists_probe<3,2>(mp_unionindex660, std::array<u64,3>{v_c151, v_c150, 0})) return;
              slog::join_probe_old<5,4>(mbranchindex661, mbranchdelta668, std::array<u64,5>{v_c30, v_c31, v_c32, v_c33, 0}, [&](const std::array<u64,5>& m711) {
                u64 v_c152 = m711[4];
                slog::join_probe_old<3,3>(mp_unionindex662, mp_uniondelta669, std::array<u64,3>{v_c150, v_c152, v_c151}, [&](const std::array<u64,3>& m712) {
                  slog::join_probe_old<3,2>(mp_unionindex663, mp_uniondelta670, std::array<u64,3>{v_c32, v_c75, 0}, [&](const std::array<u64,3>& m713) {
                    u64 v_c153 = m713[2];
                    slog::join_probe<2,1>(mp_union_ansindex664, std::array<u64,2>{v_c153, 0}, [&](const std::array<u64,2>& m714) {
                      u64 v_c27 = m714[1];
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c150, v_c27, v_c40, v_c31, v_c30});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c30, v_c31, v_c27, v_c40}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:94", "delta:mp_union_ans", _fires);
  
      if (!_done)
      {
        ReadTask671* _cont = new ReadTask671(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask671(db,b), false);
  // (crule (pre) (scan scheme_false fv) (body (join-old select_branch (0 1 2 3) 0 (0 1 2 3) __t7CcU1 tv e2 e3) (neq tv fv)) (head (emit select_branch_ans (0 1) __t7CcU1 e2)) interp.slog:86 #f)
  class ReadTask717 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** select_branchindex715;  slog::Index** select_branchdelta716;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("select_branch_ans");
      std::vector<u16> ord718({0, 1});
      slog::Relation* readrel719 = db->getRelation("select_branch_ans");
      head_index[0] = readrel719->getIndex(ord718, false);
      outer_rel = db->getRelation("scheme_false");
      std::vector<u16> ord720({0, 1, 2, 3});
      slog::Relation* readrel721 = db->getRelation("select_branch");
      select_branchindex715 = readrel721->getIndex(ord720, false);
      std::vector<u16> ord722({0, 1, 2, 3});
      slog::Relation* readrel723 = db->getRelation("select_branch");
      select_branchdelta716 = readrel723->getIndex(ord722, true);
  
    }
    ReadTask717(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c154 = _t[0];
        slog::join_all_old<4>(select_branchindex715, select_branchdelta716, [&](const std::array<u64,4>& m724) {
          u64 v_c155 = m724[0]; u64 v_c156 = m724[1]; u64 v_c157 = m724[2]; u64 v_c158 = m724[3];
          if (v_c156 == v_c154) return;
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c155, v_c157}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:86", "delta:scheme_false", _fires);
  
      if (!_done)
      {
        ReadTask717* _cont = new ReadTask717(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask717(db,b), false);
  // (crule (pre) (scan eval __t6VzV444 er rho t) (body (exists let (2 0 1 3) 1 er) (exists eval_ans (0 1) 1 __t6VzV444) (join eval (2 3 0 1) 2 rho t __4PdZ1446 __t3kGW443) (join let (0 2 1 3) 2 __t3kGW443 er x eb) (join eval_ans (0 1) 1 __t6VzV444 vr)) (head (emit store (0 1 2) x t vr) (emit binding_event (0 1 2) x t t)) interp.slog:94 #f)
  class ReadTask730 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letindex725;  slog::Index** eval_ansindex726;  slog::Index** evalindex727;  slog::Index** letindex728;  slog::Index** eval_ansindex729;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("store");
      std::vector<u16> ord731({0, 1, 2});
      slog::Relation* readrel732 = db->getRelation("store");
      head_index[0] = readrel732->getIndex(ord731, false);
      head_rel[1] = db->getRelation("binding_event");
      std::vector<u16> ord733({0, 1, 2});
      slog::Relation* readrel734 = db->getRelation("binding_event");
      head_index[1] = readrel734->getIndex(ord733, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord735({2, 0, 1, 3});
      slog::Relation* readrel736 = db->getRelation("let");
      letindex725 = readrel736->getIndex(ord735, false);
      std::vector<u16> ord737({0, 1});
      slog::Relation* readrel738 = db->getRelation("eval_ans");
      eval_ansindex726 = readrel738->getIndex(ord737, false);
      std::vector<u16> ord739({2, 3, 0, 1});
      slog::Relation* readrel740 = db->getRelation("eval");
      evalindex727 = readrel740->getIndex(ord739, false);
      std::vector<u16> ord741({0, 2, 1, 3});
      slog::Relation* readrel742 = db->getRelation("let");
      letindex728 = readrel742->getIndex(ord741, false);
      std::vector<u16> ord743({0, 1});
      slog::Relation* readrel744 = db->getRelation("eval_ans");
      eval_ansindex729 = readrel744->getIndex(ord743, false);
  
    }
    ReadTask730(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c10 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c7 = _t[3];
        if (!slog::exists_probe<4,1>(letindex725, std::array<u64,4>{v_c10, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(eval_ansindex726, std::array<u64,2>{v_c159, 0})) return;
        slog::join_probe<4,2>(evalindex727, std::array<u64,4>{v_c6, v_c7, 0, 0}, [&](const std::array<u64,4>& m745) {
          u64 v_c160 = m745[2]; u64 v_c161 = m745[3];
          slog::join_probe<4,2>(letindex728, std::array<u64,4>{v_c161, v_c10, 0, 0}, [&](const std::array<u64,4>& m746) {
            u64 v_c5 = m746[2]; u64 v_c11 = m746[3];
            slog::join_probe<2,1>(eval_ansindex729, std::array<u64,2>{v_c159, 0}, [&](const std::array<u64,2>& m747) {
              u64 v_c162 = m747[1];
              ++_fires;
              slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c5, v_c7, v_c162}, std::array<u16,3>{0, 1, 2});
              slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c5, v_c7, v_c7}, std::array<u16,3>{0, 1, 2});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:94", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask730* _cont = new ReadTask730(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask730(db,b), false);
  // (crule (pre) (scan lambda __t3Nsh264 xs eb) (body (join-old closure (1 2 0) 1 (1 2 0) __t3Nsh264 rhoc __t5Yru265) (join eval_ans (1 0) 1 __t5Yru265 __t1jZw263) (join eval (0 1 2 3) 1 __t1jZw263 ef rho t) (exists eval_args (3 2 0 1) 2 t rho) (exists app (1 2 0) 1 ef) (exists tick (2 0 1) 1 t) (join $sup70016x51x0x0x0 (1 3 4 0 2) 3 ef rho t __d0 es) (exists app (1 2 0) 2 ef es) (join-old eval_args (1 3 2 0) 3 (1 3 2 0) es t rho __t2ycT266) (exists eval_args_ans (0 1) 1 __t2ycT266) (join-old app (1 2 0) 2 (1 2 0) ef es __t4H6p267) (join-old tick (1 2 0) 2 (1 2 0) __t4H6p267 t __t8A6X268) (exists tick_ans (0 1) 1 __t8A6X268) (join eval_args_ans (0 1) 1 __t2ycT266 vs) (join tick_ans (0 1) 1 __t8A6X268 t2)) (head (emit $sup70016x51x0x0x1 (1 8 0 2 3 4 5 6 7 9 10 11 12) __t1jZw263 rhoc __d0 __t2ycT266 __t8A6X268 eb ef es rho t t2 vs xs)) interp.slog:52 #f)
  class ReadTask767 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** closureindex748;  slog::Index** eval_ansindex749;  slog::Index** evalindex750;  slog::Index** eval_argsindex751;  slog::Index** appindex752;  slog::Index** tickindex753;  slog::Index** $sup70016x51x0x0x0index754;  slog::Index** appindex755;  slog::Index** eval_argsindex756;  slog::Index** eval_args_ansindex757;  slog::Index** appindex758;  slog::Index** tickindex759;  slog::Index** tick_ansindex760;  slog::Index** eval_args_ansindex761;  slog::Index** tick_ansindex762;  slog::Index** closuredelta763;  slog::Index** eval_argsdelta764;  slog::Index** appdelta765;  slog::Index** tickdelta766;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup70016x51x0x0x1");
      std::vector<u16> ord768({1, 8, 0, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12});
      slog::Relation* readrel769 = db->getRelation("$sup70016x51x0x0x1");
      head_index[0] = readrel769->getIndex(ord768, false);
      outer_rel = db->getRelation("lambda");
      std::vector<u16> ord770({1, 2, 0});
      slog::Relation* readrel771 = db->getRelation("closure");
      closureindex748 = readrel771->getIndex(ord770, false);
      std::vector<u16> ord772({1, 2, 0});
      slog::Relation* readrel773 = db->getRelation("closure");
      closuredelta763 = readrel773->getIndex(ord772, true);
      std::vector<u16> ord774({1, 0});
      slog::Relation* readrel775 = db->getRelation("eval_ans");
      eval_ansindex749 = readrel775->getIndex(ord774, false);
      std::vector<u16> ord776({0, 1, 2, 3});
      slog::Relation* readrel777 = db->getRelation("eval");
      evalindex750 = readrel777->getIndex(ord776, false);
      std::vector<u16> ord778({3, 2, 0, 1});
      slog::Relation* readrel779 = db->getRelation("eval_args");
      eval_argsindex751 = readrel779->getIndex(ord778, false);
      std::vector<u16> ord780({1, 2, 0});
      slog::Relation* readrel781 = db->getRelation("app");
      appindex752 = readrel781->getIndex(ord780, false);
      std::vector<u16> ord782({2, 0, 1});
      slog::Relation* readrel783 = db->getRelation("tick");
      tickindex753 = readrel783->getIndex(ord782, false);
      std::vector<u16> ord784({1, 3, 4, 0, 2});
      slog::Relation* readrel785 = db->getRelation("$sup70016x51x0x0x0");
      $sup70016x51x0x0x0index754 = readrel785->getIndex(ord784, false);
      std::vector<u16> ord786({1, 2, 0});
      slog::Relation* readrel787 = db->getRelation("app");
      appindex755 = readrel787->getIndex(ord786, false);
      std::vector<u16> ord788({1, 3, 2, 0});
      slog::Relation* readrel789 = db->getRelation("eval_args");
      eval_argsindex756 = readrel789->getIndex(ord788, false);
      std::vector<u16> ord790({1, 3, 2, 0});
      slog::Relation* readrel791 = db->getRelation("eval_args");
      eval_argsdelta764 = readrel791->getIndex(ord790, true);
      std::vector<u16> ord792({0, 1});
      slog::Relation* readrel793 = db->getRelation("eval_args_ans");
      eval_args_ansindex757 = readrel793->getIndex(ord792, false);
      std::vector<u16> ord794({1, 2, 0});
      slog::Relation* readrel795 = db->getRelation("app");
      appindex758 = readrel795->getIndex(ord794, false);
      std::vector<u16> ord796({1, 2, 0});
      slog::Relation* readrel797 = db->getRelation("app");
      appdelta765 = readrel797->getIndex(ord796, true);
      std::vector<u16> ord798({1, 2, 0});
      slog::Relation* readrel799 = db->getRelation("tick");
      tickindex759 = readrel799->getIndex(ord798, false);
      std::vector<u16> ord800({1, 2, 0});
      slog::Relation* readrel801 = db->getRelation("tick");
      tickdelta766 = readrel801->getIndex(ord800, true);
      std::vector<u16> ord802({0, 1});
      slog::Relation* readrel803 = db->getRelation("tick_ans");
      tick_ansindex760 = readrel803->getIndex(ord802, false);
      std::vector<u16> ord804({0, 1});
      slog::Relation* readrel805 = db->getRelation("eval_args_ans");
      eval_args_ansindex761 = readrel805->getIndex(ord804, false);
      std::vector<u16> ord806({0, 1});
      slog::Relation* readrel807 = db->getRelation("tick_ans");
      tick_ansindex762 = readrel807->getIndex(ord806, false);
  
    }
    ReadTask767(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c21 = _t[1];
        u64 v_c11 = _t[2];
        slog::join_probe_old<3,1>(closureindex748, closuredelta763, std::array<u64,3>{v_c163, 0, 0}, [&](const std::array<u64,3>& m808) {
          u64 v_c18 = m808[1]; u64 v_c164 = m808[2];
          slog::join_probe<2,1>(eval_ansindex749, std::array<u64,2>{v_c164, 0}, [&](const std::array<u64,2>& m809) {
            u64 v_c165 = m809[1];
            slog::join_probe<4,1>(evalindex750, std::array<u64,4>{v_c165, 0, 0, 0}, [&](const std::array<u64,4>& m810) {
              u64 v_c16 = m810[1]; u64 v_c6 = m810[2]; u64 v_c7 = m810[3];
              if (!slog::exists_probe<4,2>(eval_argsindex751, std::array<u64,4>{v_c7, v_c6, 0, 0})) return;
              if (!slog::exists_probe<3,1>(appindex752, std::array<u64,3>{v_c16, 0, 0})) return;
              if (!slog::exists_probe<3,1>(tickindex753, std::array<u64,3>{v_c7, 0, 0})) return;
              slog::join_probe<5,3>($sup70016x51x0x0x0index754, std::array<u64,5>{v_c16, v_c6, v_c7, 0, 0}, [&](const std::array<u64,5>& m811) {
                u64 v_c74 = m811[3]; u64 v_c17 = m811[4];
                if (!slog::exists_probe<3,2>(appindex755, std::array<u64,3>{v_c16, v_c17, 0})) return;
                slog::join_probe_old<4,3>(eval_argsindex756, eval_argsdelta764, std::array<u64,4>{v_c17, v_c7, v_c6, 0}, [&](const std::array<u64,4>& m812) {
                  u64 v_c166 = m812[3];
                  if (!slog::exists_probe<2,1>(eval_args_ansindex757, std::array<u64,2>{v_c166, 0})) return;
                  slog::join_probe_old<3,2>(appindex758, appdelta765, std::array<u64,3>{v_c16, v_c17, 0}, [&](const std::array<u64,3>& m813) {
                    u64 v_c167 = m813[2];
                    slog::join_probe_old<3,2>(tickindex759, tickdelta766, std::array<u64,3>{v_c167, v_c7, 0}, [&](const std::array<u64,3>& m814) {
                      u64 v_c168 = m814[2];
                      if (!slog::exists_probe<2,1>(tick_ansindex760, std::array<u64,2>{v_c168, 0})) return;
                      slog::join_probe<2,1>(eval_args_ansindex761, std::array<u64,2>{v_c166, 0}, [&](const std::array<u64,2>& m815) {
                        u64 v_c20 = m815[1];
                        slog::join_probe<2,1>(tick_ansindex762, std::array<u64,2>{v_c168, 0}, [&](const std::array<u64,2>& m816) {
                          u64 v_c19 = m816[1];
                          ++_fires;
                          slog::emit<13>(head_rel[0], head_index[0], newbatch[0], std::array<u64,13>{v_c165, v_c18, v_c74, v_c166, v_c168, v_c11, v_c16, v_c17, v_c6, v_c7, v_c19, v_c20, v_c21}, std::array<u16,13>{1, 8, 0, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12});
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
  
      if (_fires) db->bumpFires("interp.slog:52", "delta:lambda", _fires);
  
      if (!_done)
      {
        ReadTask767* _cont = new ReadTask767(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask767(db,b), false);
  // (crule (pre) (scan temp0VqC1776 l m p r u) (body (join mbranch (1 2 3 4 0) 4 p m l r __t17aB636)) (head (mkstruct mp_union (1 2 0) __9tIl1507 __t17aB636 u)) map.slog:105 #f)
  class ReadTask818 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex817;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union");
      outer_rel = db->getRelation("temp0VqC1776");
      std::vector<u16> ord819({1, 2, 3, 4, 0});
      slog::Relation* readrel820 = db->getRelation("mbranch");
      mbranchindex817 = readrel820->getIndex(ord819, false);
  
    }
    ReadTask818(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c32 = _t[0];
        u64 v_c31 = _t[1];
        u64 v_c30 = _t[2];
        u64 v_c33 = _t[3];
        u64 v_c75 = _t[4];
        slog::join_probe<5,4>(mbranchindex817, std::array<u64,5>{v_c30, v_c31, v_c32, v_c33, 0}, [&](const std::array<u64,5>& m821) {
          u64 v_c169 = m821[4];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c169, v_c75}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:105", "delta:temp0VqC1776", _fires);
  
      if (!_done)
      {
        ReadTask818* _cont = new ReadTask818(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask818(db,b), false);
  // (crule (pre (let __tconst3ZiI681 const5feceb66ffc86f38d952786c)) (scan $sup5638x107x0x0x1 __t5Sgr680 __t78qG683 l m n p q r u v) (body (cmp lt m n) (join $sup5638x107x0x0x0 (5 3 7 8 0 1 2 4 6) 9 q n u v __t5Sgr680 l m p r) (exists mbranch (1 2 3 4 0) 4 p m l r) (exists mp_msk (1 2 0) 3 p n __t78qG683) (exists mp_msk_ans (0 1) 2 __t78qG683 q) (exists mp_union (2 0 1) 1 v) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t105R678) (exists mp_union (2 0 1) 2 __t105R678 __t5Sgr680) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t0Aux684) (join-old mp_union (0 1 2) 3 (0 1 2) __t5Sgr680 __t0Aux684 __t105R678) (join-old mp_msk (1 2 0) 3 (1 2 0) p n __t78qG683) (join mp_msk_ans (0 1) 2 __t78qG683 q) (join-old mp_union (1 2 0) 2 (1 2 0) __t0Aux684 v __t6NDF685) (join mp_union_ans (0 1) 1 __t6NDF685 __v0) (let __t90AV682 (band p n)) (cmp gt __t90AV682 __tconst3ZiI681)) (head (emit-temp temp9jSj1946 __t5Sgr680 __v0 n q u) (mkstruct mbranch (1 2 3 4 0) __t287h677 q n u __v0)) map.slog:108 #f)
  class ReadTask840 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x107x0x0x0index822;  slog::Index** mbranchindex823;  slog::Index** mp_mskindex824;  slog::Index** mp_msk_ansindex825;  slog::Index** mp_unionindex826;  slog::Index** mbranchindex827;  slog::Index** mp_unionindex828;  slog::Index** mbranchindex829;  slog::Index** mp_unionindex830;  slog::Index** mp_mskindex831;  slog::Index** mp_msk_ansindex832;  slog::Index** mp_unionindex833;  slog::Index** mp_union_ansindex834;  slog::Index** mbranchdelta835;  slog::Index** mbranchdelta836;  slog::Index** mp_uniondelta837;  slog::Index** mp_mskdelta838;  slog::Index** mp_uniondelta839;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9jSj1946");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("$sup5638x107x0x0x1");
      std::vector<u16> ord841({5, 3, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel842 = db->getRelation("$sup5638x107x0x0x0");
      $sup5638x107x0x0x0index822 = readrel842->getIndex(ord841, false);
      std::vector<u16> ord843({1, 2, 3, 4, 0});
      slog::Relation* readrel844 = db->getRelation("mbranch");
      mbranchindex823 = readrel844->getIndex(ord843, false);
      std::vector<u16> ord845({1, 2, 0});
      slog::Relation* readrel846 = db->getRelation("mp_msk");
      mp_mskindex824 = readrel846->getIndex(ord845, false);
      std::vector<u16> ord847({0, 1});
      slog::Relation* readrel848 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex825 = readrel848->getIndex(ord847, false);
      std::vector<u16> ord849({2, 0, 1});
      slog::Relation* readrel850 = db->getRelation("mp_union");
      mp_unionindex826 = readrel850->getIndex(ord849, false);
      std::vector<u16> ord851({1, 2, 3, 4, 0});
      slog::Relation* readrel852 = db->getRelation("mbranch");
      mbranchindex827 = readrel852->getIndex(ord851, false);
      std::vector<u16> ord853({1, 2, 3, 4, 0});
      slog::Relation* readrel854 = db->getRelation("mbranch");
      mbranchdelta835 = readrel854->getIndex(ord853, true);
      std::vector<u16> ord855({2, 0, 1});
      slog::Relation* readrel856 = db->getRelation("mp_union");
      mp_unionindex828 = readrel856->getIndex(ord855, false);
      std::vector<u16> ord857({1, 2, 3, 4, 0});
      slog::Relation* readrel858 = db->getRelation("mbranch");
      mbranchindex829 = readrel858->getIndex(ord857, false);
      std::vector<u16> ord859({1, 2, 3, 4, 0});
      slog::Relation* readrel860 = db->getRelation("mbranch");
      mbranchdelta836 = readrel860->getIndex(ord859, true);
      std::vector<u16> ord861({0, 1, 2});
      slog::Relation* readrel862 = db->getRelation("mp_union");
      mp_unionindex830 = readrel862->getIndex(ord861, false);
      std::vector<u16> ord863({0, 1, 2});
      slog::Relation* readrel864 = db->getRelation("mp_union");
      mp_uniondelta837 = readrel864->getIndex(ord863, true);
      std::vector<u16> ord865({1, 2, 0});
      slog::Relation* readrel866 = db->getRelation("mp_msk");
      mp_mskindex831 = readrel866->getIndex(ord865, false);
      std::vector<u16> ord867({1, 2, 0});
      slog::Relation* readrel868 = db->getRelation("mp_msk");
      mp_mskdelta838 = readrel868->getIndex(ord867, true);
      std::vector<u16> ord869({0, 1});
      slog::Relation* readrel870 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex832 = readrel870->getIndex(ord869, false);
      std::vector<u16> ord871({1, 2, 0});
      slog::Relation* readrel872 = db->getRelation("mp_union");
      mp_unionindex833 = readrel872->getIndex(ord871, false);
      std::vector<u16> ord873({1, 2, 0});
      slog::Relation* readrel874 = db->getRelation("mp_union");
      mp_uniondelta839 = readrel874->getIndex(ord873, true);
      std::vector<u16> ord875({0, 1});
      slog::Relation* readrel876 = db->getRelation("mp_union_ans");
      mp_union_ansindex834 = readrel876->getIndex(ord875, false);
  
    }
    ReadTask840(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c98 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c102 = _t[0];
        u64 v_c104 = _t[1];
        u64 v_c32 = _t[2];
        u64 v_c31 = _t[3];
        u64 v_c72 = _t[4];
        u64 v_c30 = _t[5];
        u64 v_c73 = _t[6];
        u64 v_c33 = _t[7];
        u64 v_c75 = _t[8];
        u64 v_c28 = _t[9];
        u64 v_c170 = _prim_lt(db, v_c31, v_c72);
        if (v_c170 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
        if (!v_c170) return;
        slog::join_probe<9,9>($sup5638x107x0x0x0index822, std::array<u64,9>{v_c73, v_c72, v_c75, v_c28, v_c102, v_c32, v_c31, v_c30, v_c33}, [&](const std::array<u64,9>& m878) {
          if (!slog::exists_probe<5,4>(mbranchindex823, std::array<u64,5>{v_c30, v_c31, v_c32, v_c33, 0})) return;
          if (!slog::exists_probe<3,3>(mp_mskindex824, std::array<u64,3>{v_c30, v_c72, v_c104})) return;
          if (!slog::exists_probe<2,2>(mp_msk_ansindex825, std::array<u64,2>{v_c104, v_c73})) return;
          if (!slog::exists_probe<3,1>(mp_unionindex826, std::array<u64,3>{v_c28, 0, 0})) return;
          slog::join_probe_old<5,4>(mbranchindex827, mbranchdelta835, std::array<u64,5>{v_c73, v_c72, v_c75, v_c28, 0}, [&](const std::array<u64,5>& m879) {
            u64 v_c101 = m879[4];
            if (!slog::exists_probe<3,2>(mp_unionindex828, std::array<u64,3>{v_c101, v_c102, 0})) return;
            slog::join_probe_old<5,4>(mbranchindex829, mbranchdelta836, std::array<u64,5>{v_c30, v_c31, v_c32, v_c33, 0}, [&](const std::array<u64,5>& m880) {
              u64 v_c100 = m880[4];
              slog::join_probe_old<3,3>(mp_unionindex830, mp_uniondelta837, std::array<u64,3>{v_c102, v_c100, v_c101}, [&](const std::array<u64,3>& m881) {
                slog::join_probe_old<3,3>(mp_mskindex831, mp_mskdelta838, std::array<u64,3>{v_c30, v_c72, v_c104}, [&](const std::array<u64,3>& m882) {
                  slog::join_probe<2,2>(mp_msk_ansindex832, std::array<u64,2>{v_c104, v_c73}, [&](const std::array<u64,2>& m883) {
                    slog::join_probe_old<3,2>(mp_unionindex833, mp_uniondelta839, std::array<u64,3>{v_c100, v_c28, 0}, [&](const std::array<u64,3>& m884) {
                      u64 v_c99 = m884[2];
                      slog::join_probe<2,1>(mp_union_ansindex834, std::array<u64,2>{v_c99, 0}, [&](const std::array<u64,2>& m885) {
                        u64 v_c27 = m885[1];
                        u64 v_c105 = _prim_band(db, v_c30, v_c72);
                        if (v_c105 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
                        u64 v_c171 = _prim_gt(db, v_c105, v_c98);
                        if (v_c171 == slog_error) { slog::emit_pending_error(db, "map.slog:108"); return; }
                        if (!v_c171) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c102, v_c27, v_c72, v_c73, v_c75});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c73, v_c72, v_c75, v_c27}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:108", "delta:$sup5638x107x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask840* _cont = new ReadTask840(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask840(db,b), false);
  // (crule (pre) (scan eval __t5mTH630 e1 rho t) (body (exists eval_ans (0 1) 1 __t5mTH630) (join $sup70016x87x0x0x0 (1 4 5 0 2 3) 3 e1 rho t __d0 e2 e3) (join-old select_branch (2 3 1 0) 2 (2 3 1 0) e2 e3 __v0 __t4JBz631) (join eval_ans (0 1) 2 __t5mTH630 __v0) (join select_branch_ans (0 1) 1 __t4JBz631 __v1)) (head (mkstruct eval (1 2 3 0) __226z1519 __v1 rho t)) interp.slog:88 #f)
  class ReadTask893 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eval_ansindex887;  slog::Index** $sup70016x87x0x0x0index888;  slog::Index** select_branchindex889;  slog::Index** eval_ansindex890;  slog::Index** select_branch_ansindex891;  slog::Index** select_branchdelta892;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord894({0, 1});
      slog::Relation* readrel895 = db->getRelation("eval_ans");
      eval_ansindex887 = readrel895->getIndex(ord894, false);
      std::vector<u16> ord896({1, 4, 5, 0, 2, 3});
      slog::Relation* readrel897 = db->getRelation("$sup70016x87x0x0x0");
      $sup70016x87x0x0x0index888 = readrel897->getIndex(ord896, false);
      std::vector<u16> ord898({2, 3, 1, 0});
      slog::Relation* readrel899 = db->getRelation("select_branch");
      select_branchindex889 = readrel899->getIndex(ord898, false);
      std::vector<u16> ord900({2, 3, 1, 0});
      slog::Relation* readrel901 = db->getRelation("select_branch");
      select_branchdelta892 = readrel901->getIndex(ord900, true);
      std::vector<u16> ord902({0, 1});
      slog::Relation* readrel903 = db->getRelation("eval_ans");
      eval_ansindex890 = readrel903->getIndex(ord902, false);
      std::vector<u16> ord904({0, 1});
      slog::Relation* readrel905 = db->getRelation("select_branch_ans");
      select_branch_ansindex891 = readrel905->getIndex(ord904, false);
  
    }
    ReadTask893(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c172 = _t[0];
        u64 v_c173 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c7 = _t[3];
        if (!slog::exists_probe<2,1>(eval_ansindex887, std::array<u64,2>{v_c172, 0})) return;
        slog::join_probe<6,3>($sup70016x87x0x0x0index888, std::array<u64,6>{v_c173, v_c6, v_c7, 0, 0, 0}, [&](const std::array<u64,6>& m906) {
          u64 v_c74 = m906[3]; u64 v_c157 = m906[4]; u64 v_c158 = m906[5];
          slog::join_probe_old<4,2>(select_branchindex889, select_branchdelta892, std::array<u64,4>{v_c157, v_c158, 0, 0}, [&](const std::array<u64,4>& m907) {
            u64 v_c27 = m907[2]; u64 v_c174 = m907[3];
            slog::join_probe<2,2>(eval_ansindex890, std::array<u64,2>{v_c172, v_c27}, [&](const std::array<u64,2>& m908) {
              slog::join_probe<2,1>(select_branch_ansindex891, std::array<u64,2>{v_c174, 0}, [&](const std::array<u64,2>& m909) {
                u64 v_c40 = m909[1];
                ++_fires;
                slog::emit_struct<4>(head_rel[0], newbatch[0], std::array<u64,3>{v_c40, v_c6, v_c7}, std::array<u16,4>{1, 2, 3, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:88", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask893* _cont = new ReadTask893(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask893(db,b), false);
  // (crule (pre (let __trid2h491263 const11445e6556bc59ce1e80cdf7) (let __trel4i351264 consta24220c5193376967f1fa95e) (let __tcol4H291265 const5feceb66ffc86f38d952786c) (let __trel3cI61266 consta24220c5193376967f1fa95e) (let __tcol2hY51267 const6b86b273ff34fce19d6b804e) (let __trel87kD1268 consta24220c5193376967f1fa95e) (let __tcol6cQM1269 constd4735e3a265e16eee03f5971) (let __trel7CVY1270 consta24220c5193376967f1fa95e) (let __tcol1Rva1271 const4e07408562bedb8b60ce05c1)) (scan $sup5638x110x0x0x0 __d0 l m n p q r s t u v) (body) (head (tycheck p (accept int) __trid2h491263 __trel4i351264 __tcol4H291265 (1 2 3 4 0)) (tycheck s (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid2h491263 __trel3cI61266 __tcol2hY51267 (1 2 3 4 0)) (tycheck q (accept int) __trid2h491263 __trel87kD1268 __tcol6cQM1269 (1 2 3 4 0)) (tycheck t (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid2h491263 __trel7CVY1270 __tcol1Rva1271 (1 2 3 4 0)) (mkstruct mp_join (1 2 3 4 0) __2pZD1262 p s q t)) map.slog:111 #f)
  class ReadTask913 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[5];
    slog::Index** head_index[5];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid911;  u32 sid910;  u32 sid912;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("malformed_deduction");
      head_rel[3] = db->getRelation("malformed_deduction");
      head_rel[4] = db->getRelation("mp_join");
      outer_rel = db->getRelation("$sup5638x110x0x0x0");
      sid911 = db->getRelation("_enum")->getStructId();
      sid910 = db->getRelation("mbranch")->getStructId();
      sid912 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask913(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c175 = v_const11445e6556bc59ce1e80cdf7;
      u64 v_c176 = v_consta24220c5193376967f1fa95e;
      u64 v_c177 = v_const5feceb66ffc86f38d952786c;
      u64 v_c178 = v_consta24220c5193376967f1fa95e;
      u64 v_c179 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c180 = v_consta24220c5193376967f1fa95e;
      u64 v_c181 = v_constd4735e3a265e16eee03f5971;
      u64 v_c182 = v_consta24220c5193376967f1fa95e;
      u64 v_c183 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[5];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
      newbatch[4] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c74 = _t[0];
        u64 v_c32 = _t[1];
        u64 v_c31 = _t[2];
        u64 v_c72 = _t[3];
        u64 v_c30 = _t[4];
        u64 v_c73 = _t[5];
        u64 v_c33 = _t[6];
        u64 v_c81 = _t[7];
        u64 v_c7 = _t[8];
        u64 v_c75 = _t[9];
        u64 v_c28 = _t[10];
        ++_fires;
        if (!(is_int(v_c30)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c175, v_c176, v_c177, v_c30}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c81) && (decode_struct_id(v_c81) == sid910 || decode_struct_id(v_c81) == sid911 || decode_struct_id(v_c81) == sid912))))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c175, v_c178, v_c179, v_c81}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c73)))
        {
          slog::emit_struct<5>(head_rel[2], newbatch[2], std::array<u64,4>{v_c175, v_c180, v_c181, v_c73}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c7) && (decode_struct_id(v_c7) == sid910 || decode_struct_id(v_c7) == sid911 || decode_struct_id(v_c7) == sid912))))
        {
          slog::emit_struct<5>(head_rel[3], newbatch[3], std::array<u64,4>{v_c175, v_c182, v_c183, v_c7}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<5>(head_rel[4], newbatch[4], std::array<u64,4>{v_c30, v_c81, v_c73, v_c7}, std::array<u16,5>{1, 2, 3, 4, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
  
      if (_fires) db->bumpFires("map.slog:111", "delta:$sup5638x110x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask913* _cont = new ReadTask913(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask913(db,b), false);
  // (crule (pre (let __trid1aRe1173 constaa218622af4adb846b2d6244) (let __trel90Y91174 constf6cdc3db4b71e0cdeda6912e) (let __tcol2p1T1175 const6b86b273ff34fce19d6b804e) (let __trel6kaB1176 constf6cdc3db4b71e0cdeda6912e) (let __tcol9YXV1177 constd4735e3a265e16eee03f5971)) (scan eval_ans __t77Vk298 __v0) (body (join-old eval (0 1 2 3) 1 (0 1 2 3) __t77Vk298 e1 rho t) (join $sup70016x87x0x0x0 (1 4 5 0 2 3) 3 e1 rho t __d0 e2 e3)) (head (tycheck e2 (accept (struct app) (struct boolean) (struct if) (struct lambda) (struct let) (struct letrec) (struct num) (struct primref) (struct ref) (struct sym)) __trid1aRe1173 __trel90Y91174 __tcol2p1T1175 (1 2 3 4 0)) (tycheck e3 (accept (struct app) (struct boolean) (struct if) (struct lambda) (struct let) (struct letrec) (struct num) (struct primref) (struct ref) (struct sym)) __trid1aRe1173 __trel6kaB1176 __tcol9YXV1177 (1 2 3 4 0)) (mkstruct select_branch (2 3 1 0) __7Jff1172 e2 e3 __v0)) interp.slog:88 #f)
  class ReadTask927 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex914;  slog::Index** $sup70016x87x0x0x0index915;  slog::Index** evaldelta916;
    u32 sid917;  u32 sid918;  u32 sid919;  u32 sid920;  u32 sid921;  u32 sid922;  u32 sid923;  u32 sid924;  u32 sid925;  u32 sid926;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("select_branch");
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord928({0, 1, 2, 3});
      slog::Relation* readrel929 = db->getRelation("eval");
      evalindex914 = readrel929->getIndex(ord928, false);
      std::vector<u16> ord930({0, 1, 2, 3});
      slog::Relation* readrel931 = db->getRelation("eval");
      evaldelta916 = readrel931->getIndex(ord930, true);
      std::vector<u16> ord932({1, 4, 5, 0, 2, 3});
      slog::Relation* readrel933 = db->getRelation("$sup70016x87x0x0x0");
      $sup70016x87x0x0x0index915 = readrel933->getIndex(ord932, false);
      sid917 = db->getRelation("app")->getStructId();
      sid918 = db->getRelation("boolean")->getStructId();
      sid919 = db->getRelation("if")->getStructId();
      sid920 = db->getRelation("lambda")->getStructId();
      sid921 = db->getRelation("let")->getStructId();
      sid922 = db->getRelation("letrec")->getStructId();
      sid923 = db->getRelation("num")->getStructId();
      sid924 = db->getRelation("primref")->getStructId();
      sid925 = db->getRelation("ref")->getStructId();
      sid926 = db->getRelation("sym")->getStructId();
  
    }
    ReadTask927(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c184 = v_constaa218622af4adb846b2d6244;
      u64 v_c185 = v_constf6cdc3db4b71e0cdeda6912e;
      u64 v_c186 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c187 = v_constf6cdc3db4b71e0cdeda6912e;
      u64 v_c188 = v_constd4735e3a265e16eee03f5971;
  
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
        u64 v_c189 = _t[0];
        u64 v_c27 = _t[1];
        slog::join_probe_old<4,1>(evalindex914, evaldelta916, std::array<u64,4>{v_c189, 0, 0, 0}, [&](const std::array<u64,4>& m934) {
          u64 v_c173 = m934[1]; u64 v_c6 = m934[2]; u64 v_c7 = m934[3];
          slog::join_probe<6,3>($sup70016x87x0x0x0index915, std::array<u64,6>{v_c173, v_c6, v_c7, 0, 0, 0}, [&](const std::array<u64,6>& m935) {
            u64 v_c74 = m935[3]; u64 v_c157 = m935[4]; u64 v_c158 = m935[5];
            ++_fires;
            if (!((is_struct(v_c157) && (decode_struct_id(v_c157) == sid917 || decode_struct_id(v_c157) == sid918 || decode_struct_id(v_c157) == sid919 || decode_struct_id(v_c157) == sid920 || decode_struct_id(v_c157) == sid921 || decode_struct_id(v_c157) == sid922 || decode_struct_id(v_c157) == sid923 || decode_struct_id(v_c157) == sid924 || decode_struct_id(v_c157) == sid925 || decode_struct_id(v_c157) == sid926))))
            {
              slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c184, v_c185, v_c186, v_c157}, std::array<u16,5>{1, 2, 3, 4, 0});
              return;
            }
            if (!((is_struct(v_c158) && (decode_struct_id(v_c158) == sid917 || decode_struct_id(v_c158) == sid918 || decode_struct_id(v_c158) == sid919 || decode_struct_id(v_c158) == sid920 || decode_struct_id(v_c158) == sid921 || decode_struct_id(v_c158) == sid922 || decode_struct_id(v_c158) == sid923 || decode_struct_id(v_c158) == sid924 || decode_struct_id(v_c158) == sid925 || decode_struct_id(v_c158) == sid926))))
            {
              slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c184, v_c187, v_c188, v_c158}, std::array<u16,5>{1, 2, 3, 4, 0});
              return;
            }
            slog::emit_struct<4>(head_rel[2], newbatch[2], std::array<u64,3>{v_c157, v_c158, v_c27}, std::array<u16,4>{2, 3, 1, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("interp.slog:88", "delta:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask927* _cont = new ReadTask927(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask927(db,b), false);
  // (crule (pre) (scan eval_ans __t8KmI338 __t1N6L339) (body (join-old prim (0 1) 1 (0 1) __t1N6L339 op) (join-old delta (1 2 0) 1 (1 2 0) op vs __t9Mk1341) (exists delta_ans (0 1) 1 __t9Mk1341) (join-old eval_args_ans (1 0) 1 (1 0) vs __t24hv340) (join-old delta_ans (0 1) 1 (0 1) __t9Mk1341 v) (join-old eval (0 1 2 3) 1 (0 1 2 3) __t8KmI338 ef rho t) (exists $sup70016x75x0x0x0 (1 3 4 2 0) 3 ef rho t) (exists eval (2 3 0 1) 2 rho t) (exists app (1 2 0) 1 ef) (join-old eval_args (3 2 0 1) 3 (3 2 0 1) t rho __t24hv340 es) (exists app (1 2 0) 2 ef es) (join-old $sup70016x75x0x0x0 (1 3 4 2 0) 4 (1 3 4 2 0) ef rho t es __t8Dhb337) (join-old eval (2 3 0 1) 3 (2 3 0 1) rho t __t8Dhb337 __t87KU336) (join-old app (0 1 2) 3 (0 1 2) __t87KU336 ef es)) (head (emit eval_ans (0 1) __t8Dhb337 v)) interp.slog:76 #f)
  class ReadTask959 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** primindex936;  slog::Index** deltaindex937;  slog::Index** delta_ansindex938;  slog::Index** eval_args_ansindex939;  slog::Index** delta_ansindex940;  slog::Index** evalindex941;  slog::Index** $sup70016x75x0x0x0index942;  slog::Index** evalindex943;  slog::Index** appindex944;  slog::Index** eval_argsindex945;  slog::Index** appindex946;  slog::Index** $sup70016x75x0x0x0index947;  slog::Index** evalindex948;  slog::Index** appindex949;  slog::Index** primdelta950;  slog::Index** deltadelta951;  slog::Index** eval_args_ansdelta952;  slog::Index** delta_ansdelta953;  slog::Index** evaldelta954;  slog::Index** eval_argsdelta955;  slog::Index** $sup70016x75x0x0x0delta956;  slog::Index** evaldelta957;  slog::Index** appdelta958;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord960({0, 1});
      slog::Relation* readrel961 = db->getRelation("eval_ans");
      head_index[0] = readrel961->getIndex(ord960, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord962({0, 1});
      slog::Relation* readrel963 = db->getRelation("prim");
      primindex936 = readrel963->getIndex(ord962, false);
      std::vector<u16> ord964({0, 1});
      slog::Relation* readrel965 = db->getRelation("prim");
      primdelta950 = readrel965->getIndex(ord964, true);
      std::vector<u16> ord966({1, 2, 0});
      slog::Relation* readrel967 = db->getRelation("delta");
      deltaindex937 = readrel967->getIndex(ord966, false);
      std::vector<u16> ord968({1, 2, 0});
      slog::Relation* readrel969 = db->getRelation("delta");
      deltadelta951 = readrel969->getIndex(ord968, true);
      std::vector<u16> ord970({0, 1});
      slog::Relation* readrel971 = db->getRelation("delta_ans");
      delta_ansindex938 = readrel971->getIndex(ord970, false);
      std::vector<u16> ord972({1, 0});
      slog::Relation* readrel973 = db->getRelation("eval_args_ans");
      eval_args_ansindex939 = readrel973->getIndex(ord972, false);
      std::vector<u16> ord974({1, 0});
      slog::Relation* readrel975 = db->getRelation("eval_args_ans");
      eval_args_ansdelta952 = readrel975->getIndex(ord974, true);
      std::vector<u16> ord976({0, 1});
      slog::Relation* readrel977 = db->getRelation("delta_ans");
      delta_ansindex940 = readrel977->getIndex(ord976, false);
      std::vector<u16> ord978({0, 1});
      slog::Relation* readrel979 = db->getRelation("delta_ans");
      delta_ansdelta953 = readrel979->getIndex(ord978, true);
      std::vector<u16> ord980({0, 1, 2, 3});
      slog::Relation* readrel981 = db->getRelation("eval");
      evalindex941 = readrel981->getIndex(ord980, false);
      std::vector<u16> ord982({0, 1, 2, 3});
      slog::Relation* readrel983 = db->getRelation("eval");
      evaldelta954 = readrel983->getIndex(ord982, true);
      std::vector<u16> ord984({1, 3, 4, 2, 0});
      slog::Relation* readrel985 = db->getRelation("$sup70016x75x0x0x0");
      $sup70016x75x0x0x0index942 = readrel985->getIndex(ord984, false);
      std::vector<u16> ord986({2, 3, 0, 1});
      slog::Relation* readrel987 = db->getRelation("eval");
      evalindex943 = readrel987->getIndex(ord986, false);
      std::vector<u16> ord988({1, 2, 0});
      slog::Relation* readrel989 = db->getRelation("app");
      appindex944 = readrel989->getIndex(ord988, false);
      std::vector<u16> ord990({3, 2, 0, 1});
      slog::Relation* readrel991 = db->getRelation("eval_args");
      eval_argsindex945 = readrel991->getIndex(ord990, false);
      std::vector<u16> ord992({3, 2, 0, 1});
      slog::Relation* readrel993 = db->getRelation("eval_args");
      eval_argsdelta955 = readrel993->getIndex(ord992, true);
      std::vector<u16> ord994({1, 2, 0});
      slog::Relation* readrel995 = db->getRelation("app");
      appindex946 = readrel995->getIndex(ord994, false);
      std::vector<u16> ord996({1, 3, 4, 2, 0});
      slog::Relation* readrel997 = db->getRelation("$sup70016x75x0x0x0");
      $sup70016x75x0x0x0index947 = readrel997->getIndex(ord996, false);
      std::vector<u16> ord998({1, 3, 4, 2, 0});
      slog::Relation* readrel999 = db->getRelation("$sup70016x75x0x0x0");
      $sup70016x75x0x0x0delta956 = readrel999->getIndex(ord998, true);
      std::vector<u16> ord1000({2, 3, 0, 1});
      slog::Relation* readrel1001 = db->getRelation("eval");
      evalindex948 = readrel1001->getIndex(ord1000, false);
      std::vector<u16> ord1002({2, 3, 0, 1});
      slog::Relation* readrel1003 = db->getRelation("eval");
      evaldelta957 = readrel1003->getIndex(ord1002, true);
      std::vector<u16> ord1004({0, 1, 2});
      slog::Relation* readrel1005 = db->getRelation("app");
      appindex949 = readrel1005->getIndex(ord1004, false);
      std::vector<u16> ord1006({0, 1, 2});
      slog::Relation* readrel1007 = db->getRelation("app");
      appdelta958 = readrel1007->getIndex(ord1006, true);
  
    }
    ReadTask959(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe_old<2,1>(primindex936, primdelta950, std::array<u64,2>{v_c191, 0}, [&](const std::array<u64,2>& m1008) {
          u64 v_c129 = m1008[1];
          slog::join_probe_old<3,1>(deltaindex937, deltadelta951, std::array<u64,3>{v_c129, 0, 0}, [&](const std::array<u64,3>& m1009) {
            u64 v_c20 = m1009[1]; u64 v_c192 = m1009[2];
            if (!slog::exists_probe<2,1>(delta_ansindex938, std::array<u64,2>{v_c192, 0})) return;
            slog::join_probe_old<2,1>(eval_args_ansindex939, eval_args_ansdelta952, std::array<u64,2>{v_c20, 0}, [&](const std::array<u64,2>& m1010) {
              u64 v_c193 = m1010[1];
              slog::join_probe_old<2,1>(delta_ansindex940, delta_ansdelta953, std::array<u64,2>{v_c192, 0}, [&](const std::array<u64,2>& m1011) {
                u64 v_c28 = m1011[1];
                slog::join_probe_old<4,1>(evalindex941, evaldelta954, std::array<u64,4>{v_c190, 0, 0, 0}, [&](const std::array<u64,4>& m1012) {
                  u64 v_c16 = m1012[1]; u64 v_c6 = m1012[2]; u64 v_c7 = m1012[3];
                  if (!slog::exists_probe<5,3>($sup70016x75x0x0x0index942, std::array<u64,5>{v_c16, v_c6, v_c7, 0, 0})) return;
                  if (!slog::exists_probe<4,2>(evalindex943, std::array<u64,4>{v_c6, v_c7, 0, 0})) return;
                  if (!slog::exists_probe<3,1>(appindex944, std::array<u64,3>{v_c16, 0, 0})) return;
                  slog::join_probe_old<4,3>(eval_argsindex945, eval_argsdelta955, std::array<u64,4>{v_c7, v_c6, v_c193, 0}, [&](const std::array<u64,4>& m1013) {
                    u64 v_c17 = m1013[3];
                    if (!slog::exists_probe<3,2>(appindex946, std::array<u64,3>{v_c16, v_c17, 0})) return;
                    slog::join_probe_old<5,4>($sup70016x75x0x0x0index947, $sup70016x75x0x0x0delta956, std::array<u64,5>{v_c16, v_c6, v_c7, v_c17, 0}, [&](const std::array<u64,5>& m1014) {
                      u64 v_c194 = m1014[4];
                      slog::join_probe_old<4,3>(evalindex948, evaldelta957, std::array<u64,4>{v_c6, v_c7, v_c194, 0}, [&](const std::array<u64,4>& m1015) {
                        u64 v_c195 = m1015[3];
                        slog::join_probe_old<3,3>(appindex949, appdelta958, std::array<u64,3>{v_c195, v_c16, v_c17}, [&](const std::array<u64,3>& m1016) {
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c194, v_c28}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:76", "delta:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask959* _cont = new ReadTask959(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask959(db,b), false);
  // (crule (pre (let _00024sqc7DnB839 const6b86b273ff34fce19d6b804e) (let _00024sqc4H0B840 const5feceb66ffc86f38d952786c) (let _00024sqc58w2841 const6b86b273ff34fce19d6b804e) (let _00024sqc7wgB842 const5feceb66ffc86f38d952786c) (let _00024sqo31L8847 const5feceb66ffc86f38d952786c)) (scan extend_env __t8zl419 __v0 xs t) (body (exists mp_put (3 0 2 1) 1 t) (exists $sup70016x47x0x0x0 (3 5 0 1 2 4) 2 t xs) (exists extend_env (3 0 1 2) 1 t) (exists $seq_at (1 0 2) 1 _00024sqo31L8847) (exists extend_env_ans (0 1) 1 __t8zl419) (join mp_put_ans (1 0) 1 __v0 __t42Fa18) (join mp_put (3 0 2 1) 2 t __t42Fa18 x rho) (exists extend_env (1 3 0 2) 2 rho t) (exists $seq_at (1 0 2) 2 _00024sqo31L8847 x) (join $sup70016x47x0x0x0 (2 3 4 5 0 1) 4 rho t x xs _00024seq0 __t2ugT17) (join extend_env (0 2 3 1) 4 __t2ugT17 _00024seq0 t rho) (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo31L8847 x _00024seq0) (join extend_env_ans (0 1) 1 __t8zl419 __v1) (letp _00024sql00Zd837 (aslst _00024seq0)) (let _00024sqn2cl5838 (llen _00024sql00Zd837)) (cmp ge _00024sqn2cl5838 _00024sqc7DnB839) (letp chk3bDq1829 (lref _00024sql00Zd837 _00024sqc4H0B840)) (eq x chk3bDq1829) (let _00024sqp8r44843 (_0002d _00024sqn2cl5838 _00024sqc7wgB842)) (let chk4p8K1830 (lslice _00024sql00Zd837 _00024sqc58w2841 _00024sqp8r44843)) (eq xs chk4p8K1830)) (head (emit extend_env_ans (0 1) __t2ugT17 __v1)) interp.slog:48 #f)
  class ReadTask1031 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_putindex1017;  slog::Index** $sup70016x47x0x0x0index1018;  slog::Index** extend_envindex1019;  slog::Index** $seq_atindex1020;  slog::Index** extend_env_ansindex1021;  slog::Index** mp_put_ansindex1022;  slog::Index** mp_putindex1023;  slog::Index** extend_envindex1024;  slog::Index** $seq_atindex1025;  slog::Index** $sup70016x47x0x0x0index1026;  slog::Index** extend_envindex1027;  slog::Index** $seq_atindex1028;  slog::Index** extend_env_ansindex1029;  slog::Index** $seq_atdelta1030;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("extend_env_ans");
      std::vector<u16> ord1032({0, 1});
      slog::Relation* readrel1033 = db->getRelation("extend_env_ans");
      head_index[0] = readrel1033->getIndex(ord1032, false);
      outer_rel = db->getRelation("extend_env");
      std::vector<u16> ord1034({3, 0, 2, 1});
      slog::Relation* readrel1035 = db->getRelation("mp_put");
      mp_putindex1017 = readrel1035->getIndex(ord1034, false);
      std::vector<u16> ord1036({3, 5, 0, 1, 2, 4});
      slog::Relation* readrel1037 = db->getRelation("$sup70016x47x0x0x0");
      $sup70016x47x0x0x0index1018 = readrel1037->getIndex(ord1036, false);
      std::vector<u16> ord1038({3, 0, 1, 2});
      slog::Relation* readrel1039 = db->getRelation("extend_env");
      extend_envindex1019 = readrel1039->getIndex(ord1038, false);
      std::vector<u16> ord1040({1, 0, 2});
      slog::Relation* readrel1041 = db->getRelation("$seq_at");
      $seq_atindex1020 = readrel1041->getIndex(ord1040, false);
      std::vector<u16> ord1042({0, 1});
      slog::Relation* readrel1043 = db->getRelation("extend_env_ans");
      extend_env_ansindex1021 = readrel1043->getIndex(ord1042, false);
      std::vector<u16> ord1044({1, 0});
      slog::Relation* readrel1045 = db->getRelation("mp_put_ans");
      mp_put_ansindex1022 = readrel1045->getIndex(ord1044, false);
      std::vector<u16> ord1046({3, 0, 2, 1});
      slog::Relation* readrel1047 = db->getRelation("mp_put");
      mp_putindex1023 = readrel1047->getIndex(ord1046, false);
      std::vector<u16> ord1048({1, 3, 0, 2});
      slog::Relation* readrel1049 = db->getRelation("extend_env");
      extend_envindex1024 = readrel1049->getIndex(ord1048, false);
      std::vector<u16> ord1050({1, 0, 2});
      slog::Relation* readrel1051 = db->getRelation("$seq_at");
      $seq_atindex1025 = readrel1051->getIndex(ord1050, false);
      std::vector<u16> ord1052({2, 3, 4, 5, 0, 1});
      slog::Relation* readrel1053 = db->getRelation("$sup70016x47x0x0x0");
      $sup70016x47x0x0x0index1026 = readrel1053->getIndex(ord1052, false);
      std::vector<u16> ord1054({0, 2, 3, 1});
      slog::Relation* readrel1055 = db->getRelation("extend_env");
      extend_envindex1027 = readrel1055->getIndex(ord1054, false);
      std::vector<u16> ord1056({1, 0, 2});
      slog::Relation* readrel1057 = db->getRelation("$seq_at");
      $seq_atindex1028 = readrel1057->getIndex(ord1056, false);
      std::vector<u16> ord1058({1, 0, 2});
      slog::Relation* readrel1059 = db->getRelation("$seq_at");
      $seq_atdelta1030 = readrel1059->getIndex(ord1058, true);
      std::vector<u16> ord1060({0, 1});
      slog::Relation* readrel1061 = db->getRelation("extend_env_ans");
      extend_env_ansindex1029 = readrel1061->getIndex(ord1060, false);
  
    }
    ReadTask1031(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c196 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c197 = v_const5feceb66ffc86f38d952786c;
      u64 v_c198 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c199 = v_const5feceb66ffc86f38d952786c;
      u64 v_c200 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c201 = _t[0];
        u64 v_c27 = _t[1];
        u64 v_c21 = _t[2];
        u64 v_c7 = _t[3];
        if (!slog::exists_probe<4,1>(mp_putindex1017, std::array<u64,4>{v_c7, 0, 0, 0})) return;
        if (!slog::exists_probe<6,2>($sup70016x47x0x0x0index1018, std::array<u64,6>{v_c7, v_c21, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(extend_envindex1019, std::array<u64,4>{v_c7, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>($seq_atindex1020, std::array<u64,3>{v_c200, 0, 0})) return;
        if (!slog::exists_probe<2,1>(extend_env_ansindex1021, std::array<u64,2>{v_c201, 0})) return;
        slog::join_probe<2,1>(mp_put_ansindex1022, std::array<u64,2>{v_c27, 0}, [&](const std::array<u64,2>& m1062) {
          u64 v_c202 = m1062[1];
          slog::join_probe<4,2>(mp_putindex1023, std::array<u64,4>{v_c7, v_c202, 0, 0}, [&](const std::array<u64,4>& m1063) {
            u64 v_c5 = m1063[2]; u64 v_c6 = m1063[3];
            if (!slog::exists_probe<4,2>(extend_envindex1024, std::array<u64,4>{v_c6, v_c7, 0, 0})) return;
            if (!slog::exists_probe<3,2>($seq_atindex1025, std::array<u64,3>{v_c200, v_c5, 0})) return;
            slog::join_probe<6,4>($sup70016x47x0x0x0index1026, std::array<u64,6>{v_c6, v_c7, v_c5, v_c21, 0, 0}, [&](const std::array<u64,6>& m1064) {
              u64 v_c203 = m1064[4]; u64 v_c204 = m1064[5];
              slog::join_probe<4,4>(extend_envindex1027, std::array<u64,4>{v_c204, v_c203, v_c7, v_c6}, [&](const std::array<u64,4>& m1065) {
                slog::join_probe_old<3,3>($seq_atindex1028, $seq_atdelta1030, std::array<u64,3>{v_c200, v_c5, v_c203}, [&](const std::array<u64,3>& m1066) {
                  slog::join_probe<2,1>(extend_env_ansindex1029, std::array<u64,2>{v_c201, 0}, [&](const std::array<u64,2>& m1067) {
                    u64 v_c40 = m1067[1];
                    bool ok1068 = true;
                    u64 v_c205 = _prim_aslst(db, v_c203, &ok1068);
                    if (!ok1068) return;
                    u64 v_c206 = _prim_llen(db, v_c205);
                    if (v_c206 == slog_error) { slog::emit_pending_error(db, "interp.slog:48"); return; }
                    u64 v_c207 = _prim_ge(db, v_c206, v_c196);
                    if (v_c207 == slog_error) { slog::emit_pending_error(db, "interp.slog:48"); return; }
                    if (!v_c207) return;
                    bool ok1070 = true;
                    u64 v_c208 = _prim_lref(db, v_c205, v_c197, &ok1070);
                    if (!ok1070) return;
                    if (v_c5 != v_c208) return;
                    u64 v_c209 = _prim__0002d(db, v_c206, v_c199);
                    if (v_c209 == slog_error) { slog::emit_pending_error(db, "interp.slog:48"); return; }
                    u64 v_c210 = _prim_lslice(db, v_c205, v_c198, v_c209);
                    if (v_c210 == slog_error) { slog::emit_pending_error(db, "interp.slog:48"); return; }
                    if (v_c21 != v_c210) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c204, v_c40}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:48", "delta:extend_env", _fires);
  
      if (!_done)
      {
        ReadTask1031* _cont = new ReadTask1031(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1031(db,b), false);
  // (crule (pre) (scan eval __t7Mwu413 __t1NSj412 rho t) (body (join app (0 1 2) 1 __t1NSj412 ef es)) (head (emit $sup70016x51x0x0x0 (4 0 3 1 2) t __t7Mwu413 rho ef es)) interp.slog:52 #f)
  class ReadTask1072 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex1071;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup70016x51x0x0x0");
      std::vector<u16> ord1073({4, 0, 3, 1, 2});
      slog::Relation* readrel1074 = db->getRelation("$sup70016x51x0x0x0");
      head_index[0] = readrel1074->getIndex(ord1073, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord1075({0, 1, 2});
      slog::Relation* readrel1076 = db->getRelation("app");
      appindex1071 = readrel1076->getIndex(ord1075, false);
  
    }
    ReadTask1072(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c212 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c7 = _t[3];
        slog::join_probe<3,1>(appindex1071, std::array<u64,3>{v_c212, 0, 0}, [&](const std::array<u64,3>& m1077) {
          u64 v_c16 = m1077[1]; u64 v_c17 = m1077[2];
          ++_fires;
          slog::emit<5>(head_rel[0], head_index[0], newbatch[0], std::array<u64,5>{v_c7, v_c211, v_c6, v_c16, v_c17}, std::array<u16,5>{4, 0, 3, 1, 2});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:52", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask1072* _cont = new ReadTask1072(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1072(db,b), false);
  // (crule (pre (let __tconst2Fuh376 const6b86b273ff34fce19d6b804e) (let __tconst0hsx377 constd4735e3a265e16eee03f5971)) (scan mp_hsb_ans __t1Fw3379 __v0) (body (join-old mp_hsb (0 1) 1 (0 1) __t1Fw3379 __t0AZp378) (join-old mp_hsb (0 1) 0 (0 1) __t9DAM375 x) (cmp lt __tconst2Fuh376 x) (let chk7BZc1873 (_0002f x __tconst0hsx377)) (eq __t0AZp378 chk7BZc1873) (let __t9OPt374 (_0002a __tconst0hsx377 __v0))) (head (emit-temp temp9Aeo1872 __t9DAM375 __t9OPt374)) map.slog:19 #f)
  class ReadTask1082 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_hsbindex1078;  slog::Index** mp_hsbindex1079;  slog::Index** mp_hsbdelta1080;  slog::Index** mp_hsbdelta1081;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9Aeo1872");
      outer_rel = db->getRelation("mp_hsb_ans");
      std::vector<u16> ord1083({0, 1});
      slog::Relation* readrel1084 = db->getRelation("mp_hsb");
      mp_hsbindex1078 = readrel1084->getIndex(ord1083, false);
      std::vector<u16> ord1085({0, 1});
      slog::Relation* readrel1086 = db->getRelation("mp_hsb");
      mp_hsbdelta1080 = readrel1086->getIndex(ord1085, true);
      std::vector<u16> ord1087({0, 1});
      slog::Relation* readrel1088 = db->getRelation("mp_hsb");
      mp_hsbindex1079 = readrel1088->getIndex(ord1087, false);
      std::vector<u16> ord1089({0, 1});
      slog::Relation* readrel1090 = db->getRelation("mp_hsb");
      mp_hsbdelta1081 = readrel1090->getIndex(ord1089, true);
  
    }
    ReadTask1082(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c213 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c214 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c215 = _t[0];
        u64 v_c27 = _t[1];
        slog::join_probe_old<2,1>(mp_hsbindex1078, mp_hsbdelta1080, std::array<u64,2>{v_c215, 0}, [&](const std::array<u64,2>& m1091) {
          u64 v_c216 = m1091[1];
          slog::join_all_old<2>(mp_hsbindex1079, mp_hsbdelta1081, [&](const std::array<u64,2>& m1092) {
            u64 v_c217 = m1092[0]; u64 v_c5 = m1092[1];
            u64 v_c218 = _prim_lt(db, v_c213, v_c5);
            if (v_c218 == slog_error) { slog::emit_pending_error(db, "map.slog:19"); return; }
            if (!v_c218) return;
            u64 v_c219 = _prim__0002f(db, v_c5, v_c214);
            if (v_c219 == slog_error) { slog::emit_pending_error(db, "map.slog:19"); return; }
            if (v_c216 != v_c219) return;
            u64 v_c220 = _prim__0002a(db, v_c214, v_c27);
            if (v_c220 == slog_error) { slog::emit_pending_error(db, "map.slog:19"); return; }
            ++_fires;
            slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c217, v_c220});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:19", "delta:mp_hsb_ans", _fires);
  
      if (!_done)
      {
        ReadTask1082* _cont = new ReadTask1082(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1082(db,b), false);
  // (crule (pre (let __trid3mSJ1494 const1ca60a80dbae6414bef23d65) (let __trel4ohT1495 constdd7bbf31ce5f578b9805e840) (let __tcol0z4c1496 const5feceb66ffc86f38d952786c) (let __trel4Oiw1497 constdd7bbf31ce5f578b9805e840) (let __tcol19O91498 const6b86b273ff34fce19d6b804e)) (scan $sup5638x44x0x0x0 __d0 k l m p r t v) (body) (head (tycheck k (accept int) __trid3mSJ1494 __trel4ohT1495 __tcol0z4c1496 (1 2 3 4 0)) (tycheck m (accept int) __trid3mSJ1494 __trel4Oiw1497 __tcol19O91498 (1 2 3 4 0)) (mkstruct mp_msk (1 2 0) __3Qaz1493 k m)) map.slog:45 #f)
  class ReadTask1094 : public slog::Task
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
      outer_rel = db->getRelation("$sup5638x44x0x0x0");
  
    }
    ReadTask1094(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c221 = v_const1ca60a80dbae6414bef23d65;
      u64 v_c222 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c223 = v_const5feceb66ffc86f38d952786c;
      u64 v_c224 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c225 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c74 = _t[0];
        u64 v_c34 = _t[1];
        u64 v_c32 = _t[2];
        u64 v_c31 = _t[3];
        u64 v_c30 = _t[4];
        u64 v_c33 = _t[5];
        u64 v_c7 = _t[6];
        u64 v_c28 = _t[7];
        ++_fires;
        if (!(is_int(v_c34)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c221, v_c222, v_c223, v_c34}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c31)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c221, v_c224, v_c225, v_c31}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c34, v_c31}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:45", "delta:$sup5638x44x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask1094* _cont = new ReadTask1094(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1094(db,b), false);
  // (crule (pre (let __tconst2b6r460 const5feceb66ffc86f38d952786c)) (scan mp_put_ans __t9vSj463 __v0) (body (join-old mp_put (0 2 1 3) 1 (0 2 1 3) __t9vSj463 k r v) (exists $sup5638x42x0x0x1 (2 6 7 0 1 3 4 5) 3 k r v) (exists mbranch (4 0 1 2 3) 1 r) (exists mp_put (2 3 0 1) 2 k v) (exists mp_msk (1 2 0) 1 k) (join-old $sup5638x42x0x0x0 (1 5 6 0 2 3 4) 3 (1 5 6 0 2 3 4) k r v __t6Bbs459 l m p) (exists mbranch (1 2 3 4 0) 4 p m l r) (exists mp_put (3 0 2 1) 3 v __t6Bbs459 k) (exists mp_msk (1 2 0) 2 k m) (exists mp_msk_ans (1 0) 1 p) (join-old $sup5638x42x0x0x1 (3 4 5 6 0 2 7 1) 7 (3 4 5 6 0 2 7 1) l m p r __t6Bbs459 k v __t5aM3462) (exists mp_msk (1 2 0) 3 k m __t5aM3462) (exists mp_msk_ans (0 1) 2 __t5aM3462 p) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t9ixF458) (join-old mp_put (0 2 1 3) 4 (0 2 1 3) __t6Bbs459 k __t9ixF458 v) (join-old mp_msk (1 2 0) 3 (1 2 0) k m __t5aM3462) (join mp_msk_ans (0 1) 2 __t5aM3462 p) (let __t1jZ6461 (band k m)) (cmp gt __t1jZ6461 __tconst2b6r460)) (head (emit-temp temp7Xjy1975 __t6Bbs459 __v0 l m p) (mkstruct mbranch (1 2 3 4 0) __t8oL5457 p m l __v0)) map.slog:43 #f)
  class ReadTask1118 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_putindex1095;  slog::Index** $sup5638x42x0x0x1index1096;  slog::Index** mbranchindex1097;  slog::Index** mp_putindex1098;  slog::Index** mp_mskindex1099;  slog::Index** $sup5638x42x0x0x0index1100;  slog::Index** mbranchindex1101;  slog::Index** mp_putindex1102;  slog::Index** mp_mskindex1103;  slog::Index** mp_msk_ansindex1104;  slog::Index** $sup5638x42x0x0x1index1105;  slog::Index** mp_mskindex1106;  slog::Index** mp_msk_ansindex1107;  slog::Index** mbranchindex1108;  slog::Index** mp_putindex1109;  slog::Index** mp_mskindex1110;  slog::Index** mp_msk_ansindex1111;  slog::Index** mp_putdelta1112;  slog::Index** $sup5638x42x0x0x0delta1113;  slog::Index** $sup5638x42x0x0x1delta1114;  slog::Index** mbranchdelta1115;  slog::Index** mp_putdelta1116;  slog::Index** mp_mskdelta1117;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7Xjy1975");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_put_ans");
      std::vector<u16> ord1119({0, 2, 1, 3});
      slog::Relation* readrel1120 = db->getRelation("mp_put");
      mp_putindex1095 = readrel1120->getIndex(ord1119, false);
      std::vector<u16> ord1121({0, 2, 1, 3});
      slog::Relation* readrel1122 = db->getRelation("mp_put");
      mp_putdelta1112 = readrel1122->getIndex(ord1121, true);
      std::vector<u16> ord1123({2, 6, 7, 0, 1, 3, 4, 5});
      slog::Relation* readrel1124 = db->getRelation("$sup5638x42x0x0x1");
      $sup5638x42x0x0x1index1096 = readrel1124->getIndex(ord1123, false);
      std::vector<u16> ord1125({4, 0, 1, 2, 3});
      slog::Relation* readrel1126 = db->getRelation("mbranch");
      mbranchindex1097 = readrel1126->getIndex(ord1125, false);
      std::vector<u16> ord1127({2, 3, 0, 1});
      slog::Relation* readrel1128 = db->getRelation("mp_put");
      mp_putindex1098 = readrel1128->getIndex(ord1127, false);
      std::vector<u16> ord1129({1, 2, 0});
      slog::Relation* readrel1130 = db->getRelation("mp_msk");
      mp_mskindex1099 = readrel1130->getIndex(ord1129, false);
      std::vector<u16> ord1131({1, 5, 6, 0, 2, 3, 4});
      slog::Relation* readrel1132 = db->getRelation("$sup5638x42x0x0x0");
      $sup5638x42x0x0x0index1100 = readrel1132->getIndex(ord1131, false);
      std::vector<u16> ord1133({1, 5, 6, 0, 2, 3, 4});
      slog::Relation* readrel1134 = db->getRelation("$sup5638x42x0x0x0");
      $sup5638x42x0x0x0delta1113 = readrel1134->getIndex(ord1133, true);
      std::vector<u16> ord1135({1, 2, 3, 4, 0});
      slog::Relation* readrel1136 = db->getRelation("mbranch");
      mbranchindex1101 = readrel1136->getIndex(ord1135, false);
      std::vector<u16> ord1137({3, 0, 2, 1});
      slog::Relation* readrel1138 = db->getRelation("mp_put");
      mp_putindex1102 = readrel1138->getIndex(ord1137, false);
      std::vector<u16> ord1139({1, 2, 0});
      slog::Relation* readrel1140 = db->getRelation("mp_msk");
      mp_mskindex1103 = readrel1140->getIndex(ord1139, false);
      std::vector<u16> ord1141({1, 0});
      slog::Relation* readrel1142 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1104 = readrel1142->getIndex(ord1141, false);
      std::vector<u16> ord1143({3, 4, 5, 6, 0, 2, 7, 1});
      slog::Relation* readrel1144 = db->getRelation("$sup5638x42x0x0x1");
      $sup5638x42x0x0x1index1105 = readrel1144->getIndex(ord1143, false);
      std::vector<u16> ord1145({3, 4, 5, 6, 0, 2, 7, 1});
      slog::Relation* readrel1146 = db->getRelation("$sup5638x42x0x0x1");
      $sup5638x42x0x0x1delta1114 = readrel1146->getIndex(ord1145, true);
      std::vector<u16> ord1147({1, 2, 0});
      slog::Relation* readrel1148 = db->getRelation("mp_msk");
      mp_mskindex1106 = readrel1148->getIndex(ord1147, false);
      std::vector<u16> ord1149({0, 1});
      slog::Relation* readrel1150 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1107 = readrel1150->getIndex(ord1149, false);
      std::vector<u16> ord1151({1, 2, 3, 4, 0});
      slog::Relation* readrel1152 = db->getRelation("mbranch");
      mbranchindex1108 = readrel1152->getIndex(ord1151, false);
      std::vector<u16> ord1153({1, 2, 3, 4, 0});
      slog::Relation* readrel1154 = db->getRelation("mbranch");
      mbranchdelta1115 = readrel1154->getIndex(ord1153, true);
      std::vector<u16> ord1155({0, 2, 1, 3});
      slog::Relation* readrel1156 = db->getRelation("mp_put");
      mp_putindex1109 = readrel1156->getIndex(ord1155, false);
      std::vector<u16> ord1157({0, 2, 1, 3});
      slog::Relation* readrel1158 = db->getRelation("mp_put");
      mp_putdelta1116 = readrel1158->getIndex(ord1157, true);
      std::vector<u16> ord1159({1, 2, 0});
      slog::Relation* readrel1160 = db->getRelation("mp_msk");
      mp_mskindex1110 = readrel1160->getIndex(ord1159, false);
      std::vector<u16> ord1161({1, 2, 0});
      slog::Relation* readrel1162 = db->getRelation("mp_msk");
      mp_mskdelta1117 = readrel1162->getIndex(ord1161, true);
      std::vector<u16> ord1163({0, 1});
      slog::Relation* readrel1164 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1111 = readrel1164->getIndex(ord1163, false);
  
    }
    ReadTask1118(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c226 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c227 = _t[0];
        u64 v_c27 = _t[1];
        slog::join_probe_old<4,1>(mp_putindex1095, mp_putdelta1112, std::array<u64,4>{v_c227, 0, 0, 0}, [&](const std::array<u64,4>& m1165) {
          u64 v_c34 = m1165[1]; u64 v_c33 = m1165[2]; u64 v_c28 = m1165[3];
          if (!slog::exists_probe<8,3>($sup5638x42x0x0x1index1096, std::array<u64,8>{v_c34, v_c33, v_c28, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<5,1>(mbranchindex1097, std::array<u64,5>{v_c33, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<4,2>(mp_putindex1098, std::array<u64,4>{v_c34, v_c28, 0, 0})) return;
          if (!slog::exists_probe<3,1>(mp_mskindex1099, std::array<u64,3>{v_c34, 0, 0})) return;
          slog::join_probe_old<7,3>($sup5638x42x0x0x0index1100, $sup5638x42x0x0x0delta1113, std::array<u64,7>{v_c34, v_c33, v_c28, 0, 0, 0, 0}, [&](const std::array<u64,7>& m1166) {
            u64 v_c228 = m1166[3]; u64 v_c32 = m1166[4]; u64 v_c31 = m1166[5]; u64 v_c30 = m1166[6];
            if (!slog::exists_probe<5,4>(mbranchindex1101, std::array<u64,5>{v_c30, v_c31, v_c32, v_c33, 0})) return;
            if (!slog::exists_probe<4,3>(mp_putindex1102, std::array<u64,4>{v_c28, v_c228, v_c34, 0})) return;
            if (!slog::exists_probe<3,2>(mp_mskindex1103, std::array<u64,3>{v_c34, v_c31, 0})) return;
            if (!slog::exists_probe<2,1>(mp_msk_ansindex1104, std::array<u64,2>{v_c30, 0})) return;
            slog::join_probe_old<8,7>($sup5638x42x0x0x1index1105, $sup5638x42x0x0x1delta1114, std::array<u64,8>{v_c32, v_c31, v_c30, v_c33, v_c228, v_c34, v_c28, 0}, [&](const std::array<u64,8>& m1167) {
              u64 v_c229 = m1167[7];
              if (!slog::exists_probe<3,3>(mp_mskindex1106, std::array<u64,3>{v_c34, v_c31, v_c229})) return;
              if (!slog::exists_probe<2,2>(mp_msk_ansindex1107, std::array<u64,2>{v_c229, v_c30})) return;
              slog::join_probe_old<5,4>(mbranchindex1108, mbranchdelta1115, std::array<u64,5>{v_c30, v_c31, v_c32, v_c33, 0}, [&](const std::array<u64,5>& m1168) {
                u64 v_c230 = m1168[4];
                slog::join_probe_old<4,4>(mp_putindex1109, mp_putdelta1116, std::array<u64,4>{v_c228, v_c34, v_c230, v_c28}, [&](const std::array<u64,4>& m1169) {
                  slog::join_probe_old<3,3>(mp_mskindex1110, mp_mskdelta1117, std::array<u64,3>{v_c34, v_c31, v_c229}, [&](const std::array<u64,3>& m1170) {
                    slog::join_probe<2,2>(mp_msk_ansindex1111, std::array<u64,2>{v_c229, v_c30}, [&](const std::array<u64,2>& m1171) {
                      u64 v_c231 = _prim_band(db, v_c34, v_c31);
                      if (v_c231 == slog_error) { slog::emit_pending_error(db, "map.slog:43"); return; }
                      u64 v_c232 = _prim_gt(db, v_c231, v_c226);
                      if (v_c232 == slog_error) { slog::emit_pending_error(db, "map.slog:43"); return; }
                      if (!v_c232) return;
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c228, v_c27, v_c32, v_c31, v_c30});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c30, v_c31, v_c32, v_c27}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:43", "delta:mp_put_ans", _fires);
  
      if (!_done)
      {
        ReadTask1118* _cont = new ReadTask1118(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1118(db,b), false);
  // (crule (pre (let __tconst3WIu273 const5feceb66ffc86f38d952786c)) (scan lst_take __t96hl275 l n) (body (let __t5BnU274 (lslice l __tconst3WIu273 n))) (head (emit-temp temp3fv92049 __t5BnU274 __t96hl275)) list.slog:29 #f)
  class ReadTask1173 : public slog::Task
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
      head_rel[0] = db->getRelation("temp3fv92049");
      outer_rel = db->getRelation("lst_take");
  
    }
    ReadTask1173(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c233 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c234 = _t[0];
        u64 v_c32 = _t[1];
        u64 v_c72 = _t[2];
        u64 v_c235 = _prim_lslice(db, v_c32, v_c233, v_c72);
        if (v_c235 == slog_error) { slog::emit_pending_error(db, "list.slog:29"); return; }
        ++_fires;
        slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c235, v_c234});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("list.slog:29", "delta:lst_take", _fires);
  
      if (!_done)
      {
        ReadTask1173* _cont = new ReadTask1173(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1173(db,b), false);
  // (crule (pre (let __tconst0xOc223 const5feceb66ffc86f38d952786c)) (scan mbranch __t5FeR226 q n u v) (body (exists $sup5638x98x0x0x1 (4 6 8 9 0 1 2 3 5 7) 4 n q u v) (exists mp_union (2 0 1) 1 __t5FeR226) (exists mp_msk (1 2 0) 1 q) (join $sup5638x98x0x0x0 (3 5 7 8 0 1 2 4 6) 4 n q u v __t14N0222 l m p r) (cmp lt n m) (exists mbranch (1 2 3 4 0) 4 p m l r) (exists mp_union (2 0 1) 2 __t5FeR226 __t14N0222) (exists mp_msk (1 2 0) 2 q m) (exists mp_msk_ans (1 0) 1 p) (exists mp_union (1 2 0) 2 r __t5FeR226) (join $sup5638x98x0x0x1 (7 2 3 5 0 4 6 8 9 1) 9 r l m p __t14N0222 n q u v __t4NVE225) (exists mp_msk (1 2 0) 3 q m __t4NVE225) (exists mp_msk_ans (0 1) 2 __t4NVE225 p) (join mbranch (1 2 3 4 0) 4 p m l r __t006N221) (join mp_union (0 1 2) 3 __t14N0222 __t006N221 __t5FeR226) (join mp_msk (1 2 0) 3 q m __t4NVE225) (join mp_msk_ans (0 1) 2 __t4NVE225 p) (join-old mp_union (1 2 0) 2 (1 2 0) r __t5FeR226 __t6Lp3227) (join mp_union_ans (0 1) 1 __t6Lp3227 __v0) (let __t91c5224 (band q m)) (cmp gt __t91c5224 __tconst0xOc223)) (head (emit-temp temp0Tjz1856 __t14N0222 __v0 l m p) (mkstruct mbranch (1 2 3 4 0) __t1O3D219 p m l __v0)) map.slog:99 #f)
  class ReadTask1193 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x98x0x0x1index1174;  slog::Index** mp_unionindex1175;  slog::Index** mp_mskindex1176;  slog::Index** $sup5638x98x0x0x0index1177;  slog::Index** mbranchindex1178;  slog::Index** mp_unionindex1179;  slog::Index** mp_mskindex1180;  slog::Index** mp_msk_ansindex1181;  slog::Index** mp_unionindex1182;  slog::Index** $sup5638x98x0x0x1index1183;  slog::Index** mp_mskindex1184;  slog::Index** mp_msk_ansindex1185;  slog::Index** mbranchindex1186;  slog::Index** mp_unionindex1187;  slog::Index** mp_mskindex1188;  slog::Index** mp_msk_ansindex1189;  slog::Index** mp_unionindex1190;  slog::Index** mp_union_ansindex1191;  slog::Index** mp_uniondelta1192;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0Tjz1856");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord1194({4, 6, 8, 9, 0, 1, 2, 3, 5, 7});
      slog::Relation* readrel1195 = db->getRelation("$sup5638x98x0x0x1");
      $sup5638x98x0x0x1index1174 = readrel1195->getIndex(ord1194, false);
      std::vector<u16> ord1196({2, 0, 1});
      slog::Relation* readrel1197 = db->getRelation("mp_union");
      mp_unionindex1175 = readrel1197->getIndex(ord1196, false);
      std::vector<u16> ord1198({1, 2, 0});
      slog::Relation* readrel1199 = db->getRelation("mp_msk");
      mp_mskindex1176 = readrel1199->getIndex(ord1198, false);
      std::vector<u16> ord1200({3, 5, 7, 8, 0, 1, 2, 4, 6});
      slog::Relation* readrel1201 = db->getRelation("$sup5638x98x0x0x0");
      $sup5638x98x0x0x0index1177 = readrel1201->getIndex(ord1200, false);
      std::vector<u16> ord1202({1, 2, 3, 4, 0});
      slog::Relation* readrel1203 = db->getRelation("mbranch");
      mbranchindex1178 = readrel1203->getIndex(ord1202, false);
      std::vector<u16> ord1204({2, 0, 1});
      slog::Relation* readrel1205 = db->getRelation("mp_union");
      mp_unionindex1179 = readrel1205->getIndex(ord1204, false);
      std::vector<u16> ord1206({1, 2, 0});
      slog::Relation* readrel1207 = db->getRelation("mp_msk");
      mp_mskindex1180 = readrel1207->getIndex(ord1206, false);
      std::vector<u16> ord1208({1, 0});
      slog::Relation* readrel1209 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1181 = readrel1209->getIndex(ord1208, false);
      std::vector<u16> ord1210({1, 2, 0});
      slog::Relation* readrel1211 = db->getRelation("mp_union");
      mp_unionindex1182 = readrel1211->getIndex(ord1210, false);
      std::vector<u16> ord1212({7, 2, 3, 5, 0, 4, 6, 8, 9, 1});
      slog::Relation* readrel1213 = db->getRelation("$sup5638x98x0x0x1");
      $sup5638x98x0x0x1index1183 = readrel1213->getIndex(ord1212, false);
      std::vector<u16> ord1214({1, 2, 0});
      slog::Relation* readrel1215 = db->getRelation("mp_msk");
      mp_mskindex1184 = readrel1215->getIndex(ord1214, false);
      std::vector<u16> ord1216({0, 1});
      slog::Relation* readrel1217 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1185 = readrel1217->getIndex(ord1216, false);
      std::vector<u16> ord1218({1, 2, 3, 4, 0});
      slog::Relation* readrel1219 = db->getRelation("mbranch");
      mbranchindex1186 = readrel1219->getIndex(ord1218, false);
      std::vector<u16> ord1220({0, 1, 2});
      slog::Relation* readrel1221 = db->getRelation("mp_union");
      mp_unionindex1187 = readrel1221->getIndex(ord1220, false);
      std::vector<u16> ord1222({1, 2, 0});
      slog::Relation* readrel1223 = db->getRelation("mp_msk");
      mp_mskindex1188 = readrel1223->getIndex(ord1222, false);
      std::vector<u16> ord1224({0, 1});
      slog::Relation* readrel1225 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1189 = readrel1225->getIndex(ord1224, false);
      std::vector<u16> ord1226({1, 2, 0});
      slog::Relation* readrel1227 = db->getRelation("mp_union");
      mp_unionindex1190 = readrel1227->getIndex(ord1226, false);
      std::vector<u16> ord1228({1, 2, 0});
      slog::Relation* readrel1229 = db->getRelation("mp_union");
      mp_uniondelta1192 = readrel1229->getIndex(ord1228, true);
      std::vector<u16> ord1230({0, 1});
      slog::Relation* readrel1231 = db->getRelation("mp_union_ans");
      mp_union_ansindex1191 = readrel1231->getIndex(ord1230, false);
  
    }
    ReadTask1193(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c236 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c237 = _t[0];
        u64 v_c73 = _t[1];
        u64 v_c72 = _t[2];
        u64 v_c75 = _t[3];
        u64 v_c28 = _t[4];
        if (!slog::exists_probe<10,4>($sup5638x98x0x0x1index1174, std::array<u64,10>{v_c72, v_c73, v_c75, v_c28, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_unionindex1175, std::array<u64,3>{v_c237, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex1176, std::array<u64,3>{v_c73, 0, 0})) return;
        slog::join_probe<9,4>($sup5638x98x0x0x0index1177, std::array<u64,9>{v_c72, v_c73, v_c75, v_c28, 0, 0, 0, 0, 0}, [&](const std::array<u64,9>& m1232) {
          u64 v_c238 = m1232[4]; u64 v_c32 = m1232[5]; u64 v_c31 = m1232[6]; u64 v_c30 = m1232[7]; u64 v_c33 = m1232[8];
          u64 v_c239 = _prim_lt(db, v_c72, v_c31);
          if (v_c239 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
          if (!v_c239) return;
          if (!slog::exists_probe<5,4>(mbranchindex1178, std::array<u64,5>{v_c30, v_c31, v_c32, v_c33, 0})) return;
          if (!slog::exists_probe<3,2>(mp_unionindex1179, std::array<u64,3>{v_c237, v_c238, 0})) return;
          if (!slog::exists_probe<3,2>(mp_mskindex1180, std::array<u64,3>{v_c73, v_c31, 0})) return;
          if (!slog::exists_probe<2,1>(mp_msk_ansindex1181, std::array<u64,2>{v_c30, 0})) return;
          if (!slog::exists_probe<3,2>(mp_unionindex1182, std::array<u64,3>{v_c33, v_c237, 0})) return;
          slog::join_probe<10,9>($sup5638x98x0x0x1index1183, std::array<u64,10>{v_c33, v_c32, v_c31, v_c30, v_c238, v_c72, v_c73, v_c75, v_c28, 0}, [&](const std::array<u64,10>& m1234) {
            u64 v_c240 = m1234[9];
            if (!slog::exists_probe<3,3>(mp_mskindex1184, std::array<u64,3>{v_c73, v_c31, v_c240})) return;
            if (!slog::exists_probe<2,2>(mp_msk_ansindex1185, std::array<u64,2>{v_c240, v_c30})) return;
            slog::join_probe<5,4>(mbranchindex1186, std::array<u64,5>{v_c30, v_c31, v_c32, v_c33, 0}, [&](const std::array<u64,5>& m1235) {
              u64 v_c241 = m1235[4];
              slog::join_probe<3,3>(mp_unionindex1187, std::array<u64,3>{v_c238, v_c241, v_c237}, [&](const std::array<u64,3>& m1236) {
                slog::join_probe<3,3>(mp_mskindex1188, std::array<u64,3>{v_c73, v_c31, v_c240}, [&](const std::array<u64,3>& m1237) {
                  slog::join_probe<2,2>(mp_msk_ansindex1189, std::array<u64,2>{v_c240, v_c30}, [&](const std::array<u64,2>& m1238) {
                    slog::join_probe_old<3,2>(mp_unionindex1190, mp_uniondelta1192, std::array<u64,3>{v_c33, v_c237, 0}, [&](const std::array<u64,3>& m1239) {
                      u64 v_c242 = m1239[2];
                      slog::join_probe<2,1>(mp_union_ansindex1191, std::array<u64,2>{v_c242, 0}, [&](const std::array<u64,2>& m1240) {
                        u64 v_c27 = m1240[1];
                        u64 v_c243 = _prim_band(db, v_c73, v_c31);
                        if (v_c243 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
                        u64 v_c244 = _prim_gt(db, v_c243, v_c236);
                        if (v_c244 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
                        if (!v_c244) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c238, v_c27, v_c32, v_c31, v_c30});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c30, v_c31, v_c32, v_c27}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:99", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask1193* _cont = new ReadTask1193(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1193(db,b), false);
  // (crule (pre (let __trid8LqO1205 constfee494ff4827aeb0635bb714) (let __trel2H7m1206 const20347926ddb307a8e2bdb71b) (let __tcol2B611207 constd4735e3a265e16eee03f5971)) (scan mp_msk_ans __t0gIW440 p) (body (exists $sup5638x84x0x0x0 (4 2 3 5 0 1) 1 p) (join-old mp_msk (0 1 2) 1 (0 1 2) __t0gIW440 k m) (exists mp_del (2 0 1) 1 k) (join $sup5638x84x0x0x0 (1 3 4 0 2 5) 3 k m p __d0 l r) (join-old mp_del (1 2 0) 2 (1 2 0) r k __t33MJ441) (join-old mp_del_ans (0 1) 1 (0 1) __t33MJ441 __v0)) (head (tycheck l (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid8LqO1205 __trel2H7m1206 __tcol2B611207 (1 2 3 4 0)) (mkstruct mp_bld (1 2 3 4 0) __0kM11204 p m l __v0)) map.slog:85 #f)
  class ReadTask1254 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x84x0x0x0index1242;  slog::Index** mp_mskindex1243;  slog::Index** mp_delindex1244;  slog::Index** $sup5638x84x0x0x0index1245;  slog::Index** mp_delindex1246;  slog::Index** mp_del_ansindex1247;  slog::Index** mp_mskdelta1248;  slog::Index** mp_deldelta1249;  slog::Index** mp_del_ansdelta1250;
    u32 sid1252;  u32 sid1251;  u32 sid1253;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("mp_bld");
      outer_rel = db->getRelation("mp_msk_ans");
      std::vector<u16> ord1255({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel1256 = db->getRelation("$sup5638x84x0x0x0");
      $sup5638x84x0x0x0index1242 = readrel1256->getIndex(ord1255, false);
      std::vector<u16> ord1257({0, 1, 2});
      slog::Relation* readrel1258 = db->getRelation("mp_msk");
      mp_mskindex1243 = readrel1258->getIndex(ord1257, false);
      std::vector<u16> ord1259({0, 1, 2});
      slog::Relation* readrel1260 = db->getRelation("mp_msk");
      mp_mskdelta1248 = readrel1260->getIndex(ord1259, true);
      std::vector<u16> ord1261({2, 0, 1});
      slog::Relation* readrel1262 = db->getRelation("mp_del");
      mp_delindex1244 = readrel1262->getIndex(ord1261, false);
      std::vector<u16> ord1263({1, 3, 4, 0, 2, 5});
      slog::Relation* readrel1264 = db->getRelation("$sup5638x84x0x0x0");
      $sup5638x84x0x0x0index1245 = readrel1264->getIndex(ord1263, false);
      std::vector<u16> ord1265({1, 2, 0});
      slog::Relation* readrel1266 = db->getRelation("mp_del");
      mp_delindex1246 = readrel1266->getIndex(ord1265, false);
      std::vector<u16> ord1267({1, 2, 0});
      slog::Relation* readrel1268 = db->getRelation("mp_del");
      mp_deldelta1249 = readrel1268->getIndex(ord1267, true);
      std::vector<u16> ord1269({0, 1});
      slog::Relation* readrel1270 = db->getRelation("mp_del_ans");
      mp_del_ansindex1247 = readrel1270->getIndex(ord1269, false);
      std::vector<u16> ord1271({0, 1});
      slog::Relation* readrel1272 = db->getRelation("mp_del_ans");
      mp_del_ansdelta1250 = readrel1272->getIndex(ord1271, true);
      sid1252 = db->getRelation("_enum")->getStructId();
      sid1251 = db->getRelation("mbranch")->getStructId();
      sid1253 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask1254(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c245 = v_constfee494ff4827aeb0635bb714;
      u64 v_c246 = v_const20347926ddb307a8e2bdb71b;
      u64 v_c247 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c248 = _t[0];
        u64 v_c30 = _t[1];
        if (!slog::exists_probe<6,1>($sup5638x84x0x0x0index1242, std::array<u64,6>{v_c30, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(mp_mskindex1243, mp_mskdelta1248, std::array<u64,3>{v_c248, 0, 0}, [&](const std::array<u64,3>& m1273) {
          u64 v_c34 = m1273[1]; u64 v_c31 = m1273[2];
          if (!slog::exists_probe<3,1>(mp_delindex1244, std::array<u64,3>{v_c34, 0, 0})) return;
          slog::join_probe<6,3>($sup5638x84x0x0x0index1245, std::array<u64,6>{v_c34, v_c31, v_c30, 0, 0, 0}, [&](const std::array<u64,6>& m1274) {
            u64 v_c74 = m1274[3]; u64 v_c32 = m1274[4]; u64 v_c33 = m1274[5];
            slog::join_probe_old<3,2>(mp_delindex1246, mp_deldelta1249, std::array<u64,3>{v_c33, v_c34, 0}, [&](const std::array<u64,3>& m1275) {
              u64 v_c249 = m1275[2];
              slog::join_probe_old<2,1>(mp_del_ansindex1247, mp_del_ansdelta1250, std::array<u64,2>{v_c249, 0}, [&](const std::array<u64,2>& m1276) {
                u64 v_c27 = m1276[1];
                ++_fires;
                if (!((is_struct(v_c32) && (decode_struct_id(v_c32) == sid1251 || decode_struct_id(v_c32) == sid1252 || decode_struct_id(v_c32) == sid1253))))
                {
                  slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c245, v_c246, v_c247, v_c32}, std::array<u16,5>{1, 2, 3, 4, 0});
                  return;
                }
                slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c30, v_c31, v_c32, v_c27}, std::array<u16,5>{1, 2, 3, 4, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("map.slog:85", "delta:mp_msk_ans", _fires);
  
      if (!_done)
      {
        ReadTask1254* _cont = new ReadTask1254(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1254(db,b), false);
  // (crule (pre (let __tconst4OFx251 const6b86b273ff34fce19d6b804e)) (scan mp_del __t18R6250 __t18bm249 k) (body (join mbranch (0 1 2 3 4) 1 __t18bm249 p m l r) (let __t0Aej252 (band k m)) (cmp lt __t0Aej252 __tconst4OFx251)) (head (emit $sup5638x82x0x0x0 (4 3 5 2 0 1) p m r l __t18R6250 k)) map.slog:83 #f)
  class ReadTask1278 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex1277;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x82x0x0x0");
      std::vector<u16> ord1279({4, 3, 5, 2, 0, 1});
      slog::Relation* readrel1280 = db->getRelation("$sup5638x82x0x0x0");
      head_index[0] = readrel1280->getIndex(ord1279, false);
      outer_rel = db->getRelation("mp_del");
      std::vector<u16> ord1281({0, 1, 2, 3, 4});
      slog::Relation* readrel1282 = db->getRelation("mbranch");
      mbranchindex1277 = readrel1282->getIndex(ord1281, false);
  
    }
    ReadTask1278(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c250 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c251 = _t[0];
        u64 v_c252 = _t[1];
        u64 v_c34 = _t[2];
        slog::join_probe<5,1>(mbranchindex1277, std::array<u64,5>{v_c252, 0, 0, 0, 0}, [&](const std::array<u64,5>& m1283) {
          u64 v_c30 = m1283[1]; u64 v_c31 = m1283[2]; u64 v_c32 = m1283[3]; u64 v_c33 = m1283[4];
          u64 v_c253 = _prim_band(db, v_c34, v_c31);
          if (v_c253 == slog_error) { slog::emit_pending_error(db, "map.slog:83"); return; }
          u64 v_c254 = _prim_lt(db, v_c253, v_c250);
          if (v_c254 == slog_error) { slog::emit_pending_error(db, "map.slog:83"); return; }
          if (!v_c254) return;
          ++_fires;
          slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c30, v_c31, v_c33, v_c32, v_c251, v_c34}, std::array<u16,6>{4, 3, 5, 2, 0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:83", "delta:mp_del", _fires);
  
      if (!_done)
      {
        ReadTask1278* _cont = new ReadTask1278(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1278(db,b), false);
  // (crule (pre (let __trid4qD31544 consta9707d158296ad63d61ac4f7) (let __trel07sS1545 const0bbd2fbd1dc4200473343503) (let __tcol16oz1546 const5feceb66ffc86f38d952786c)) (scan eval __t1OhY558 __t4vLM557 rho t) (body (join lambda (0 1 2) 1 __t4vLM557 xs eb)) (head (tycheck __t4vLM557 (accept (struct lambda)) __trid4qD31544 __trel07sS1545 __tcol16oz1546 (1 2 3 4 0)) (emit-temp temp7xOk1832 __t1OhY558 __t4vLM557 rho) (mkstruct closure (1 2 0) __t7c6K556 __t4vLM557 rho)) interp.slog:33 #f)
  class ReadTask1287 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lambdaindex1285;
    u32 sid1286;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("temp7xOk1832");
      head_rel[2] = db->getRelation("closure");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord1288({0, 1, 2});
      slog::Relation* readrel1289 = db->getRelation("lambda");
      lambdaindex1285 = readrel1289->getIndex(ord1288, false);
      sid1286 = db->getRelation("lambda")->getStructId();
  
    }
    ReadTask1287(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c255 = v_consta9707d158296ad63d61ac4f7;
      u64 v_c256 = v_const0bbd2fbd1dc4200473343503;
      u64 v_c257 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c258 = _t[0];
        u64 v_c259 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c7 = _t[3];
        slog::join_probe<3,1>(lambdaindex1285, std::array<u64,3>{v_c259, 0, 0}, [&](const std::array<u64,3>& m1290) {
          u64 v_c21 = m1290[1]; u64 v_c11 = m1290[2];
          ++_fires;
          if (!((is_struct(v_c259) && (decode_struct_id(v_c259) == sid1286))))
          {
            slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c255, v_c256, v_c257, v_c259}, std::array<u16,5>{1, 2, 3, 4, 0});
            return;
          }
          slog::emit_temp<3>(head_rel[1], newbatch[1], std::array<u64,3>{v_c258, v_c259, v_c6});
          slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c259, v_c6}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("interp.slog:33", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask1287* _cont = new ReadTask1287(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1287(db,b), false);
  // (crule (pre) (scan eval __t5qy8533 ef rho t) (body (exists $sup70016x51x0x0x1 (1 5 7 9 0 2 3 4 6 8 10 11 12) 4 __t5qy8533 ef rho t) (exists eval_args (3 2 0 1) 2 t rho) (exists eval (2 3 0 1) 2 rho t) (exists app (1 2 0) 1 ef) (exists tick (2 0 1) 1 t) (exists eval_ans (0 1) 1 __t5qy8533) (join $sup70016x51x0x0x0 (1 3 4 0 2) 3 ef rho t __t2z6s532 es) (exists eval_args (1 3 2 0) 3 es t rho) (exists eval (2 3 0 1) 3 rho t __t2z6s532) (exists app (1 2 0) 2 ef es) (join $sup70016x51x0x0x1 (5 6 0 7 9 1 2 3 4 8 10 11 12) 6 ef es __t2z6s532 rho t __t5qy8533 __t2srV536 __t0CD9539 eb rhoc t2 vs xs) (join-old eval_args (3 2 0 1) 4 (3 2 0 1) t rho __t2srV536 es) (exists tick (0 2 1) 2 __t0CD9539 t) (exists extend_env (1 2 3 0) 3 rhoc xs t2) (exists eval_args_ans (0 1) 2 __t2srV536 vs) (exists tick_ans (0 1) 2 __t0CD9539 t2) (exists lambda (1 2 0) 2 xs eb) (exists closure (2 0 1) 1 rhoc) (exists eval (3 1 0 2) 2 t2 eb) (join eval (2 3 0 1) 3 rho t __t2z6s532 __t5a7h538) (join-old app (0 1 2) 3 (0 1 2) __t5a7h538 ef es) (join-old tick (0 2 1) 3 (0 2 1) __t0CD9539 t __t5a7h538) (join-old extend_env (1 2 3 0) 3 (1 2 3 0) rhoc xs t2 __t5fzh540) (join eval_args_ans (0 1) 2 __t2srV536 vs) (join tick_ans (0 1) 2 __t0CD9539 t2) (exists extend_env_ans (0 1) 1 __t5fzh540) (join-old lambda (1 2 0) 2 (1 2 0) xs eb __t6iPm534) (join-old closure (1 2 0) 2 (1 2 0) __t6iPm534 rhoc __t9dfl535) (join eval_ans (0 1) 2 __t5qy8533 __t9dfl535) (join-old eval (3 1 0 2) 2 (3 1 0 2) t2 eb __t7TaT537 __v0) (join extend_env_ans (0 1) 2 __t5fzh540 __v0) (join eval_ans (0 1) 1 __t7TaT537 v)) (head (emit eval_ans (0 1) __t2z6s532 v)) interp.slog:52 #f)
  class ReadTask1330 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup70016x51x0x0x1index1291;  slog::Index** eval_argsindex1292;  slog::Index** evalindex1293;  slog::Index** appindex1294;  slog::Index** tickindex1295;  slog::Index** eval_ansindex1296;  slog::Index** $sup70016x51x0x0x0index1297;  slog::Index** eval_argsindex1298;  slog::Index** evalindex1299;  slog::Index** appindex1300;  slog::Index** $sup70016x51x0x0x1index1301;  slog::Index** eval_argsindex1302;  slog::Index** tickindex1303;  slog::Index** extend_envindex1304;  slog::Index** eval_args_ansindex1305;  slog::Index** tick_ansindex1306;  slog::Index** lambdaindex1307;  slog::Index** closureindex1308;  slog::Index** evalindex1309;  slog::Index** evalindex1310;  slog::Index** appindex1311;  slog::Index** tickindex1312;  slog::Index** extend_envindex1313;  slog::Index** eval_args_ansindex1314;  slog::Index** tick_ansindex1315;  slog::Index** extend_env_ansindex1316;  slog::Index** lambdaindex1317;  slog::Index** closureindex1318;  slog::Index** eval_ansindex1319;  slog::Index** evalindex1320;  slog::Index** extend_env_ansindex1321;  slog::Index** eval_ansindex1322;  slog::Index** eval_argsdelta1323;  slog::Index** appdelta1324;  slog::Index** tickdelta1325;  slog::Index** extend_envdelta1326;  slog::Index** lambdadelta1327;  slog::Index** closuredelta1328;  slog::Index** evaldelta1329;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1331({0, 1});
      slog::Relation* readrel1332 = db->getRelation("eval_ans");
      head_index[0] = readrel1332->getIndex(ord1331, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord1333({1, 5, 7, 9, 0, 2, 3, 4, 6, 8, 10, 11, 12});
      slog::Relation* readrel1334 = db->getRelation("$sup70016x51x0x0x1");
      $sup70016x51x0x0x1index1291 = readrel1334->getIndex(ord1333, false);
      std::vector<u16> ord1335({3, 2, 0, 1});
      slog::Relation* readrel1336 = db->getRelation("eval_args");
      eval_argsindex1292 = readrel1336->getIndex(ord1335, false);
      std::vector<u16> ord1337({2, 3, 0, 1});
      slog::Relation* readrel1338 = db->getRelation("eval");
      evalindex1293 = readrel1338->getIndex(ord1337, false);
      std::vector<u16> ord1339({1, 2, 0});
      slog::Relation* readrel1340 = db->getRelation("app");
      appindex1294 = readrel1340->getIndex(ord1339, false);
      std::vector<u16> ord1341({2, 0, 1});
      slog::Relation* readrel1342 = db->getRelation("tick");
      tickindex1295 = readrel1342->getIndex(ord1341, false);
      std::vector<u16> ord1343({0, 1});
      slog::Relation* readrel1344 = db->getRelation("eval_ans");
      eval_ansindex1296 = readrel1344->getIndex(ord1343, false);
      std::vector<u16> ord1345({1, 3, 4, 0, 2});
      slog::Relation* readrel1346 = db->getRelation("$sup70016x51x0x0x0");
      $sup70016x51x0x0x0index1297 = readrel1346->getIndex(ord1345, false);
      std::vector<u16> ord1347({1, 3, 2, 0});
      slog::Relation* readrel1348 = db->getRelation("eval_args");
      eval_argsindex1298 = readrel1348->getIndex(ord1347, false);
      std::vector<u16> ord1349({2, 3, 0, 1});
      slog::Relation* readrel1350 = db->getRelation("eval");
      evalindex1299 = readrel1350->getIndex(ord1349, false);
      std::vector<u16> ord1351({1, 2, 0});
      slog::Relation* readrel1352 = db->getRelation("app");
      appindex1300 = readrel1352->getIndex(ord1351, false);
      std::vector<u16> ord1353({5, 6, 0, 7, 9, 1, 2, 3, 4, 8, 10, 11, 12});
      slog::Relation* readrel1354 = db->getRelation("$sup70016x51x0x0x1");
      $sup70016x51x0x0x1index1301 = readrel1354->getIndex(ord1353, false);
      std::vector<u16> ord1355({3, 2, 0, 1});
      slog::Relation* readrel1356 = db->getRelation("eval_args");
      eval_argsindex1302 = readrel1356->getIndex(ord1355, false);
      std::vector<u16> ord1357({3, 2, 0, 1});
      slog::Relation* readrel1358 = db->getRelation("eval_args");
      eval_argsdelta1323 = readrel1358->getIndex(ord1357, true);
      std::vector<u16> ord1359({0, 2, 1});
      slog::Relation* readrel1360 = db->getRelation("tick");
      tickindex1303 = readrel1360->getIndex(ord1359, false);
      std::vector<u16> ord1361({1, 2, 3, 0});
      slog::Relation* readrel1362 = db->getRelation("extend_env");
      extend_envindex1304 = readrel1362->getIndex(ord1361, false);
      std::vector<u16> ord1363({0, 1});
      slog::Relation* readrel1364 = db->getRelation("eval_args_ans");
      eval_args_ansindex1305 = readrel1364->getIndex(ord1363, false);
      std::vector<u16> ord1365({0, 1});
      slog::Relation* readrel1366 = db->getRelation("tick_ans");
      tick_ansindex1306 = readrel1366->getIndex(ord1365, false);
      std::vector<u16> ord1367({1, 2, 0});
      slog::Relation* readrel1368 = db->getRelation("lambda");
      lambdaindex1307 = readrel1368->getIndex(ord1367, false);
      std::vector<u16> ord1369({2, 0, 1});
      slog::Relation* readrel1370 = db->getRelation("closure");
      closureindex1308 = readrel1370->getIndex(ord1369, false);
      std::vector<u16> ord1371({3, 1, 0, 2});
      slog::Relation* readrel1372 = db->getRelation("eval");
      evalindex1309 = readrel1372->getIndex(ord1371, false);
      std::vector<u16> ord1373({2, 3, 0, 1});
      slog::Relation* readrel1374 = db->getRelation("eval");
      evalindex1310 = readrel1374->getIndex(ord1373, false);
      std::vector<u16> ord1375({0, 1, 2});
      slog::Relation* readrel1376 = db->getRelation("app");
      appindex1311 = readrel1376->getIndex(ord1375, false);
      std::vector<u16> ord1377({0, 1, 2});
      slog::Relation* readrel1378 = db->getRelation("app");
      appdelta1324 = readrel1378->getIndex(ord1377, true);
      std::vector<u16> ord1379({0, 2, 1});
      slog::Relation* readrel1380 = db->getRelation("tick");
      tickindex1312 = readrel1380->getIndex(ord1379, false);
      std::vector<u16> ord1381({0, 2, 1});
      slog::Relation* readrel1382 = db->getRelation("tick");
      tickdelta1325 = readrel1382->getIndex(ord1381, true);
      std::vector<u16> ord1383({1, 2, 3, 0});
      slog::Relation* readrel1384 = db->getRelation("extend_env");
      extend_envindex1313 = readrel1384->getIndex(ord1383, false);
      std::vector<u16> ord1385({1, 2, 3, 0});
      slog::Relation* readrel1386 = db->getRelation("extend_env");
      extend_envdelta1326 = readrel1386->getIndex(ord1385, true);
      std::vector<u16> ord1387({0, 1});
      slog::Relation* readrel1388 = db->getRelation("eval_args_ans");
      eval_args_ansindex1314 = readrel1388->getIndex(ord1387, false);
      std::vector<u16> ord1389({0, 1});
      slog::Relation* readrel1390 = db->getRelation("tick_ans");
      tick_ansindex1315 = readrel1390->getIndex(ord1389, false);
      std::vector<u16> ord1391({0, 1});
      slog::Relation* readrel1392 = db->getRelation("extend_env_ans");
      extend_env_ansindex1316 = readrel1392->getIndex(ord1391, false);
      std::vector<u16> ord1393({1, 2, 0});
      slog::Relation* readrel1394 = db->getRelation("lambda");
      lambdaindex1317 = readrel1394->getIndex(ord1393, false);
      std::vector<u16> ord1395({1, 2, 0});
      slog::Relation* readrel1396 = db->getRelation("lambda");
      lambdadelta1327 = readrel1396->getIndex(ord1395, true);
      std::vector<u16> ord1397({1, 2, 0});
      slog::Relation* readrel1398 = db->getRelation("closure");
      closureindex1318 = readrel1398->getIndex(ord1397, false);
      std::vector<u16> ord1399({1, 2, 0});
      slog::Relation* readrel1400 = db->getRelation("closure");
      closuredelta1328 = readrel1400->getIndex(ord1399, true);
      std::vector<u16> ord1401({0, 1});
      slog::Relation* readrel1402 = db->getRelation("eval_ans");
      eval_ansindex1319 = readrel1402->getIndex(ord1401, false);
      std::vector<u16> ord1403({3, 1, 0, 2});
      slog::Relation* readrel1404 = db->getRelation("eval");
      evalindex1320 = readrel1404->getIndex(ord1403, false);
      std::vector<u16> ord1405({3, 1, 0, 2});
      slog::Relation* readrel1406 = db->getRelation("eval");
      evaldelta1329 = readrel1406->getIndex(ord1405, true);
      std::vector<u16> ord1407({0, 1});
      slog::Relation* readrel1408 = db->getRelation("extend_env_ans");
      extend_env_ansindex1321 = readrel1408->getIndex(ord1407, false);
      std::vector<u16> ord1409({0, 1});
      slog::Relation* readrel1410 = db->getRelation("eval_ans");
      eval_ansindex1322 = readrel1410->getIndex(ord1409, false);
  
    }
    ReadTask1330(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c13 = _t[0];
        u64 v_c16 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c7 = _t[3];
        if (!slog::exists_probe<13,4>($sup70016x51x0x0x1index1291, std::array<u64,13>{v_c13, v_c16, v_c6, v_c7, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<4,2>(eval_argsindex1292, std::array<u64,4>{v_c7, v_c6, 0, 0})) return;
        if (!slog::exists_probe<4,2>(evalindex1293, std::array<u64,4>{v_c6, v_c7, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex1294, std::array<u64,3>{v_c16, 0, 0})) return;
        if (!slog::exists_probe<3,1>(tickindex1295, std::array<u64,3>{v_c7, 0, 0})) return;
        if (!slog::exists_probe<2,1>(eval_ansindex1296, std::array<u64,2>{v_c13, 0})) return;
        slog::join_probe<5,3>($sup70016x51x0x0x0index1297, std::array<u64,5>{v_c16, v_c6, v_c7, 0, 0}, [&](const std::array<u64,5>& m1411) {
          u64 v_c12 = m1411[3]; u64 v_c17 = m1411[4];
          if (!slog::exists_probe<4,3>(eval_argsindex1298, std::array<u64,4>{v_c17, v_c7, v_c6, 0})) return;
          if (!slog::exists_probe<4,3>(evalindex1299, std::array<u64,4>{v_c6, v_c7, v_c12, 0})) return;
          if (!slog::exists_probe<3,2>(appindex1300, std::array<u64,3>{v_c16, v_c17, 0})) return;
          slog::join_probe<13,6>($sup70016x51x0x0x1index1301, std::array<u64,13>{v_c16, v_c17, v_c12, v_c6, v_c7, v_c13, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,13>& m1412) {
            u64 v_c14 = m1412[6]; u64 v_c15 = m1412[7]; u64 v_c11 = m1412[8]; u64 v_c18 = m1412[9]; u64 v_c19 = m1412[10]; u64 v_c20 = m1412[11]; u64 v_c21 = m1412[12];
            slog::join_probe_old<4,4>(eval_argsindex1302, eval_argsdelta1323, std::array<u64,4>{v_c7, v_c6, v_c14, v_c17}, [&](const std::array<u64,4>& m1413) {
              if (!slog::exists_probe<3,2>(tickindex1303, std::array<u64,3>{v_c15, v_c7, 0})) return;
              if (!slog::exists_probe<4,3>(extend_envindex1304, std::array<u64,4>{v_c18, v_c21, v_c19, 0})) return;
              if (!slog::exists_probe<2,2>(eval_args_ansindex1305, std::array<u64,2>{v_c14, v_c20})) return;
              if (!slog::exists_probe<2,2>(tick_ansindex1306, std::array<u64,2>{v_c15, v_c19})) return;
              if (!slog::exists_probe<3,2>(lambdaindex1307, std::array<u64,3>{v_c21, v_c11, 0})) return;
              if (!slog::exists_probe<3,1>(closureindex1308, std::array<u64,3>{v_c18, 0, 0})) return;
              if (!slog::exists_probe<4,2>(evalindex1309, std::array<u64,4>{v_c19, v_c11, 0, 0})) return;
              slog::join_probe<4,3>(evalindex1310, std::array<u64,4>{v_c6, v_c7, v_c12, 0}, [&](const std::array<u64,4>& m1414) {
                u64 v_c22 = m1414[3];
                slog::join_probe_old<3,3>(appindex1311, appdelta1324, std::array<u64,3>{v_c22, v_c16, v_c17}, [&](const std::array<u64,3>& m1415) {
                  slog::join_probe_old<3,3>(tickindex1312, tickdelta1325, std::array<u64,3>{v_c15, v_c7, v_c22}, [&](const std::array<u64,3>& m1416) {
                    slog::join_probe_old<4,3>(extend_envindex1313, extend_envdelta1326, std::array<u64,4>{v_c18, v_c21, v_c19, 0}, [&](const std::array<u64,4>& m1417) {
                      u64 v_c23 = m1417[3];
                      slog::join_probe<2,2>(eval_args_ansindex1314, std::array<u64,2>{v_c14, v_c20}, [&](const std::array<u64,2>& m1418) {
                        slog::join_probe<2,2>(tick_ansindex1315, std::array<u64,2>{v_c15, v_c19}, [&](const std::array<u64,2>& m1419) {
                          if (!slog::exists_probe<2,1>(extend_env_ansindex1316, std::array<u64,2>{v_c23, 0})) return;
                          slog::join_probe_old<3,2>(lambdaindex1317, lambdadelta1327, std::array<u64,3>{v_c21, v_c11, 0}, [&](const std::array<u64,3>& m1420) {
                            u64 v_c24 = m1420[2];
                            slog::join_probe_old<3,2>(closureindex1318, closuredelta1328, std::array<u64,3>{v_c24, v_c18, 0}, [&](const std::array<u64,3>& m1421) {
                              u64 v_c25 = m1421[2];
                              slog::join_probe<2,2>(eval_ansindex1319, std::array<u64,2>{v_c13, v_c25}, [&](const std::array<u64,2>& m1422) {
                                slog::join_probe_old<4,2>(evalindex1320, evaldelta1329, std::array<u64,4>{v_c19, v_c11, 0, 0}, [&](const std::array<u64,4>& m1423) {
                                  u64 v_c26 = m1423[2]; u64 v_c27 = m1423[3];
                                  slog::join_probe<2,2>(extend_env_ansindex1321, std::array<u64,2>{v_c23, v_c27}, [&](const std::array<u64,2>& m1424) {
                                    slog::join_probe<2,1>(eval_ansindex1322, std::array<u64,2>{v_c26, 0}, [&](const std::array<u64,2>& m1425) {
                                      u64 v_c28 = m1425[1];
                                      ++_fires;
                                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c12, v_c28}, std::array<u16,2>{0, 1});
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
        ReadTask1330* _cont = new ReadTask1330(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1330(db,b), false);
  // (crule (pre (let __trid6DUz1244 const8c6798fa821ed573f6b89759) (let __trel85wC1245 const4a59dbb9cb3129dfcc75170b) (let __tcol5KOf1246 const5feceb66ffc86f38d952786c)) (scan extend_env_ans __t753P32 __v0) (body (join-old extend_env (0 2 3 1) 1 (0 2 3 1) __t753P32 xs t2 rhoc) (join $sup70016x51x0x0x1 (8 10 12 3 4 0 1 2 5 6 7 9 11) 3 rhoc t2 xs __d4 eb __d0 __d1 __d2 ef es rho t vs)) (head (tycheck eb (accept (struct app) (struct boolean) (struct if) (struct lambda) (struct let) (struct letrec) (struct num) (struct primref) (struct ref) (struct sym)) __trid6DUz1244 __trel85wC1245 __tcol5KOf1246 (1 2 3 4 0)) (mkstruct eval (1 2 3 0) __3Qtr1243 eb __v0 t2)) interp.slog:52 #f)
  class ReadTask1439 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** extend_envindex1426;  slog::Index** $sup70016x51x0x0x1index1427;  slog::Index** extend_envdelta1428;
    u32 sid1429;  u32 sid1430;  u32 sid1431;  u32 sid1432;  u32 sid1433;  u32 sid1434;  u32 sid1435;  u32 sid1436;  u32 sid1437;  u32 sid1438;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("eval");
      outer_rel = db->getRelation("extend_env_ans");
      std::vector<u16> ord1440({0, 2, 3, 1});
      slog::Relation* readrel1441 = db->getRelation("extend_env");
      extend_envindex1426 = readrel1441->getIndex(ord1440, false);
      std::vector<u16> ord1442({0, 2, 3, 1});
      slog::Relation* readrel1443 = db->getRelation("extend_env");
      extend_envdelta1428 = readrel1443->getIndex(ord1442, true);
      std::vector<u16> ord1444({8, 10, 12, 3, 4, 0, 1, 2, 5, 6, 7, 9, 11});
      slog::Relation* readrel1445 = db->getRelation("$sup70016x51x0x0x1");
      $sup70016x51x0x0x1index1427 = readrel1445->getIndex(ord1444, false);
      sid1429 = db->getRelation("app")->getStructId();
      sid1430 = db->getRelation("boolean")->getStructId();
      sid1431 = db->getRelation("if")->getStructId();
      sid1432 = db->getRelation("lambda")->getStructId();
      sid1433 = db->getRelation("let")->getStructId();
      sid1434 = db->getRelation("letrec")->getStructId();
      sid1435 = db->getRelation("num")->getStructId();
      sid1436 = db->getRelation("primref")->getStructId();
      sid1437 = db->getRelation("ref")->getStructId();
      sid1438 = db->getRelation("sym")->getStructId();
  
    }
    ReadTask1439(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c260 = v_const8c6798fa821ed573f6b89759;
      u64 v_c261 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c262 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c263 = _t[0];
        u64 v_c27 = _t[1];
        slog::join_probe_old<4,1>(extend_envindex1426, extend_envdelta1428, std::array<u64,4>{v_c263, 0, 0, 0}, [&](const std::array<u64,4>& m1446) {
          u64 v_c21 = m1446[1]; u64 v_c19 = m1446[2]; u64 v_c18 = m1446[3];
          slog::join_probe<13,3>($sup70016x51x0x0x1index1427, std::array<u64,13>{v_c18, v_c19, v_c21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,13>& m1447) {
            u64 v_c264 = m1447[3]; u64 v_c11 = m1447[4]; u64 v_c74 = m1447[5]; u64 v_c265 = m1447[6]; u64 v_c266 = m1447[7]; u64 v_c16 = m1447[8]; u64 v_c17 = m1447[9]; u64 v_c6 = m1447[10]; u64 v_c7 = m1447[11]; u64 v_c20 = m1447[12];
            ++_fires;
            if (!((is_struct(v_c11) && (decode_struct_id(v_c11) == sid1429 || decode_struct_id(v_c11) == sid1430 || decode_struct_id(v_c11) == sid1431 || decode_struct_id(v_c11) == sid1432 || decode_struct_id(v_c11) == sid1433 || decode_struct_id(v_c11) == sid1434 || decode_struct_id(v_c11) == sid1435 || decode_struct_id(v_c11) == sid1436 || decode_struct_id(v_c11) == sid1437 || decode_struct_id(v_c11) == sid1438))))
            {
              slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c260, v_c261, v_c262, v_c11}, std::array<u16,5>{1, 2, 3, 4, 0});
              return;
            }
            slog::emit_struct<4>(head_rel[1], newbatch[1], std::array<u64,3>{v_c11, v_c27, v_c19}, std::array<u16,4>{1, 2, 3, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:52", "delta:extend_env_ans", _fires);
  
      if (!_done)
      {
        ReadTask1439* _cont = new ReadTask1439(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1439(db,b), false);
  // (crule (pre (let __trid8LqO1205 constfee494ff4827aeb0635bb714) (let __trel2H7m1206 const20347926ddb307a8e2bdb71b) (let __tcol2B611207 constd4735e3a265e16eee03f5971)) (scan mp_del __t33MJ441 r k) (body (exists $sup5638x84x0x0x0 (1 5 0 2 3 4) 2 k r) (exists mp_msk (1 2 0) 1 k) (join mp_del_ans (0 1) 1 __t33MJ441 __v0) (join $sup5638x84x0x0x0 (1 5 0 2 3 4) 2 k r __d0 l m p) (exists mp_msk_ans (1 0) 1 p) (join mp_msk (1 2 0) 2 k m __t0gIW440) (join mp_msk_ans (0 1) 2 __t0gIW440 p)) (head (tycheck l (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid8LqO1205 __trel2H7m1206 __tcol2B611207 (1 2 3 4 0)) (mkstruct mp_bld (1 2 3 4 0) __0kM11204 p m l __v0)) map.slog:85 #f)
  class ReadTask1458 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x84x0x0x0index1448;  slog::Index** mp_mskindex1449;  slog::Index** mp_del_ansindex1450;  slog::Index** $sup5638x84x0x0x0index1451;  slog::Index** mp_msk_ansindex1452;  slog::Index** mp_mskindex1453;  slog::Index** mp_msk_ansindex1454;
    u32 sid1456;  u32 sid1455;  u32 sid1457;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("mp_bld");
      outer_rel = db->getRelation("mp_del");
      std::vector<u16> ord1459({1, 5, 0, 2, 3, 4});
      slog::Relation* readrel1460 = db->getRelation("$sup5638x84x0x0x0");
      $sup5638x84x0x0x0index1448 = readrel1460->getIndex(ord1459, false);
      std::vector<u16> ord1461({1, 2, 0});
      slog::Relation* readrel1462 = db->getRelation("mp_msk");
      mp_mskindex1449 = readrel1462->getIndex(ord1461, false);
      std::vector<u16> ord1463({0, 1});
      slog::Relation* readrel1464 = db->getRelation("mp_del_ans");
      mp_del_ansindex1450 = readrel1464->getIndex(ord1463, false);
      std::vector<u16> ord1465({1, 5, 0, 2, 3, 4});
      slog::Relation* readrel1466 = db->getRelation("$sup5638x84x0x0x0");
      $sup5638x84x0x0x0index1451 = readrel1466->getIndex(ord1465, false);
      std::vector<u16> ord1467({1, 0});
      slog::Relation* readrel1468 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1452 = readrel1468->getIndex(ord1467, false);
      std::vector<u16> ord1469({1, 2, 0});
      slog::Relation* readrel1470 = db->getRelation("mp_msk");
      mp_mskindex1453 = readrel1470->getIndex(ord1469, false);
      std::vector<u16> ord1471({0, 1});
      slog::Relation* readrel1472 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1454 = readrel1472->getIndex(ord1471, false);
      sid1456 = db->getRelation("_enum")->getStructId();
      sid1455 = db->getRelation("mbranch")->getStructId();
      sid1457 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask1458(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c245 = v_constfee494ff4827aeb0635bb714;
      u64 v_c246 = v_const20347926ddb307a8e2bdb71b;
      u64 v_c247 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c249 = _t[0];
        u64 v_c33 = _t[1];
        u64 v_c34 = _t[2];
        if (!slog::exists_probe<6,2>($sup5638x84x0x0x0index1448, std::array<u64,6>{v_c34, v_c33, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex1449, std::array<u64,3>{v_c34, 0, 0})) return;
        slog::join_probe<2,1>(mp_del_ansindex1450, std::array<u64,2>{v_c249, 0}, [&](const std::array<u64,2>& m1473) {
          u64 v_c27 = m1473[1];
          slog::join_probe<6,2>($sup5638x84x0x0x0index1451, std::array<u64,6>{v_c34, v_c33, 0, 0, 0, 0}, [&](const std::array<u64,6>& m1474) {
            u64 v_c74 = m1474[2]; u64 v_c32 = m1474[3]; u64 v_c31 = m1474[4]; u64 v_c30 = m1474[5];
            if (!slog::exists_probe<2,1>(mp_msk_ansindex1452, std::array<u64,2>{v_c30, 0})) return;
            slog::join_probe<3,2>(mp_mskindex1453, std::array<u64,3>{v_c34, v_c31, 0}, [&](const std::array<u64,3>& m1475) {
              u64 v_c248 = m1475[2];
              slog::join_probe<2,2>(mp_msk_ansindex1454, std::array<u64,2>{v_c248, v_c30}, [&](const std::array<u64,2>& m1476) {
                ++_fires;
                if (!((is_struct(v_c32) && (decode_struct_id(v_c32) == sid1455 || decode_struct_id(v_c32) == sid1456 || decode_struct_id(v_c32) == sid1457))))
                {
                  slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c245, v_c246, v_c247, v_c32}, std::array<u16,5>{1, 2, 3, 4, 0});
                  return;
                }
                slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c30, v_c31, v_c32, v_c27}, std::array<u16,5>{1, 2, 3, 4, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("map.slog:85", "delta:mp_del", _fires);
  
      if (!_done)
      {
        ReadTask1458* _cont = new ReadTask1458(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1458(db,b), false);
  // (crule (pre) (scan eval_args __t24hv340 es rho t) (body (exists eval (2 3 0 1) 2 rho t) (exists app (2 0 1) 1 es) (exists eval_args_ans (0 1) 1 __t24hv340) (join $sup70016x75x0x0x0 (2 3 4 0 1) 3 es rho t __t8Dhb337 ef) (exists app (1 2 0) 2 ef es) (exists eval (1 2 3 0) 3 ef rho t) (join eval (2 3 0 1) 3 rho t __t8Dhb337 __t87KU336) (join app (0 1 2) 3 __t87KU336 ef es) (join eval (1 2 3 0) 3 ef rho t __t8KmI338) (join eval_ans (0 1) 1 __t8KmI338 __t1N6L339) (join eval_args_ans (0 1) 1 __t24hv340 vs) (exists delta (2 0 1) 1 vs) (join prim (0 1) 1 __t1N6L339 op) (join-old delta (1 2 0) 2 (1 2 0) op vs __t9Mk1341) (join delta_ans (0 1) 1 __t9Mk1341 v)) (head (emit eval_ans (0 1) __t8Dhb337 v)) interp.slog:76 #f)
  class ReadTask1493 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1477;  slog::Index** appindex1478;  slog::Index** eval_args_ansindex1479;  slog::Index** $sup70016x75x0x0x0index1480;  slog::Index** appindex1481;  slog::Index** evalindex1482;  slog::Index** evalindex1483;  slog::Index** appindex1484;  slog::Index** evalindex1485;  slog::Index** eval_ansindex1486;  slog::Index** eval_args_ansindex1487;  slog::Index** deltaindex1488;  slog::Index** primindex1489;  slog::Index** deltaindex1490;  slog::Index** delta_ansindex1491;  slog::Index** deltadelta1492;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1494({0, 1});
      slog::Relation* readrel1495 = db->getRelation("eval_ans");
      head_index[0] = readrel1495->getIndex(ord1494, false);
      outer_rel = db->getRelation("eval_args");
      std::vector<u16> ord1496({2, 3, 0, 1});
      slog::Relation* readrel1497 = db->getRelation("eval");
      evalindex1477 = readrel1497->getIndex(ord1496, false);
      std::vector<u16> ord1498({2, 0, 1});
      slog::Relation* readrel1499 = db->getRelation("app");
      appindex1478 = readrel1499->getIndex(ord1498, false);
      std::vector<u16> ord1500({0, 1});
      slog::Relation* readrel1501 = db->getRelation("eval_args_ans");
      eval_args_ansindex1479 = readrel1501->getIndex(ord1500, false);
      std::vector<u16> ord1502({2, 3, 4, 0, 1});
      slog::Relation* readrel1503 = db->getRelation("$sup70016x75x0x0x0");
      $sup70016x75x0x0x0index1480 = readrel1503->getIndex(ord1502, false);
      std::vector<u16> ord1504({1, 2, 0});
      slog::Relation* readrel1505 = db->getRelation("app");
      appindex1481 = readrel1505->getIndex(ord1504, false);
      std::vector<u16> ord1506({1, 2, 3, 0});
      slog::Relation* readrel1507 = db->getRelation("eval");
      evalindex1482 = readrel1507->getIndex(ord1506, false);
      std::vector<u16> ord1508({2, 3, 0, 1});
      slog::Relation* readrel1509 = db->getRelation("eval");
      evalindex1483 = readrel1509->getIndex(ord1508, false);
      std::vector<u16> ord1510({0, 1, 2});
      slog::Relation* readrel1511 = db->getRelation("app");
      appindex1484 = readrel1511->getIndex(ord1510, false);
      std::vector<u16> ord1512({1, 2, 3, 0});
      slog::Relation* readrel1513 = db->getRelation("eval");
      evalindex1485 = readrel1513->getIndex(ord1512, false);
      std::vector<u16> ord1514({0, 1});
      slog::Relation* readrel1515 = db->getRelation("eval_ans");
      eval_ansindex1486 = readrel1515->getIndex(ord1514, false);
      std::vector<u16> ord1516({0, 1});
      slog::Relation* readrel1517 = db->getRelation("eval_args_ans");
      eval_args_ansindex1487 = readrel1517->getIndex(ord1516, false);
      std::vector<u16> ord1518({2, 0, 1});
      slog::Relation* readrel1519 = db->getRelation("delta");
      deltaindex1488 = readrel1519->getIndex(ord1518, false);
      std::vector<u16> ord1520({0, 1});
      slog::Relation* readrel1521 = db->getRelation("prim");
      primindex1489 = readrel1521->getIndex(ord1520, false);
      std::vector<u16> ord1522({1, 2, 0});
      slog::Relation* readrel1523 = db->getRelation("delta");
      deltaindex1490 = readrel1523->getIndex(ord1522, false);
      std::vector<u16> ord1524({1, 2, 0});
      slog::Relation* readrel1525 = db->getRelation("delta");
      deltadelta1492 = readrel1525->getIndex(ord1524, true);
      std::vector<u16> ord1526({0, 1});
      slog::Relation* readrel1527 = db->getRelation("delta_ans");
      delta_ansindex1491 = readrel1527->getIndex(ord1526, false);
  
    }
    ReadTask1493(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c193 = _t[0];
        u64 v_c17 = _t[1];
        u64 v_c6 = _t[2];
        u64 v_c7 = _t[3];
        if (!slog::exists_probe<4,2>(evalindex1477, std::array<u64,4>{v_c6, v_c7, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex1478, std::array<u64,3>{v_c17, 0, 0})) return;
        if (!slog::exists_probe<2,1>(eval_args_ansindex1479, std::array<u64,2>{v_c193, 0})) return;
        slog::join_probe<5,3>($sup70016x75x0x0x0index1480, std::array<u64,5>{v_c17, v_c6, v_c7, 0, 0}, [&](const std::array<u64,5>& m1528) {
          u64 v_c194 = m1528[3]; u64 v_c16 = m1528[4];
          if (!slog::exists_probe<3,2>(appindex1481, std::array<u64,3>{v_c16, v_c17, 0})) return;
          if (!slog::exists_probe<4,3>(evalindex1482, std::array<u64,4>{v_c16, v_c6, v_c7, 0})) return;
          slog::join_probe<4,3>(evalindex1483, std::array<u64,4>{v_c6, v_c7, v_c194, 0}, [&](const std::array<u64,4>& m1529) {
            u64 v_c195 = m1529[3];
            slog::join_probe<3,3>(appindex1484, std::array<u64,3>{v_c195, v_c16, v_c17}, [&](const std::array<u64,3>& m1530) {
              slog::join_probe<4,3>(evalindex1485, std::array<u64,4>{v_c16, v_c6, v_c7, 0}, [&](const std::array<u64,4>& m1531) {
                u64 v_c190 = m1531[3];
                slog::join_probe<2,1>(eval_ansindex1486, std::array<u64,2>{v_c190, 0}, [&](const std::array<u64,2>& m1532) {
                  u64 v_c191 = m1532[1];
                  slog::join_probe<2,1>(eval_args_ansindex1487, std::array<u64,2>{v_c193, 0}, [&](const std::array<u64,2>& m1533) {
                    u64 v_c20 = m1533[1];
                    if (!slog::exists_probe<3,1>(deltaindex1488, std::array<u64,3>{v_c20, 0, 0})) return;
                    slog::join_probe<2,1>(primindex1489, std::array<u64,2>{v_c191, 0}, [&](const std::array<u64,2>& m1534) {
                      u64 v_c129 = m1534[1];
                      slog::join_probe_old<3,2>(deltaindex1490, deltadelta1492, std::array<u64,3>{v_c129, v_c20, 0}, [&](const std::array<u64,3>& m1535) {
                        u64 v_c192 = m1535[2];
                        slog::join_probe<2,1>(delta_ansindex1491, std::array<u64,2>{v_c192, 0}, [&](const std::array<u64,2>& m1536) {
                          u64 v_c28 = m1536[1];
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c194, v_c28}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:76", "delta:eval_args", _fires);
  
      if (!_done)
      {
        ReadTask1493* _cont = new ReadTask1493(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1493(db,b), false);
  // (crule (pre) (scan temp3yhj1777 k p t v) (body (join mleaf (1 2 0) 2 k v __t8Woy284)) (head (mkstruct mp_join (1 2 3 4 0) __7qsn1350 k __t8Woy284 p t)) map.slog:45 #f)
  class ReadTask1538 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mleafindex1537;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_join");
      outer_rel = db->getRelation("temp3yhj1777");
      std::vector<u16> ord1539({1, 2, 0});
      slog::Relation* readrel1540 = db->getRelation("mleaf");
      mleafindex1537 = readrel1540->getIndex(ord1539, false);
  
    }
    ReadTask1538(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c34 = _t[0];
        u64 v_c30 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c28 = _t[3];
        slog::join_probe<3,2>(mleafindex1537, std::array<u64,3>{v_c34, v_c28, 0}, [&](const std::array<u64,3>& m1541) {
          u64 v_c267 = m1541[2];
          ++_fires;
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c34, v_c267, v_c30, v_c7}, std::array<u16,5>{1, 2, 3, 4, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:45", "delta:temp3yhj1777", _fires);
  
      if (!_done)
      {
        ReadTask1538* _cont = new ReadTask1538(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1538(db,b), false);
  // (crule (pre) (scan tick_ans __t2n7W617 t2) (body (join-old tick (0 2 1) 1 (0 2 1) __t2n7W617 t __t3MQm616) (exists eval (3 1 0 2) 1 t) (exists eval_args (3 2 0 1) 1 t) (join eval (3 1 0 2) 2 t __t3MQm616 __3JBR1203 rho) (exists eval_args (3 2 0 1) 2 t rho) (join-old eval (2 3 0 1) 2 (2 3 0 1) rho t __t7lOb612 ef) (exists eval_ans (0 1) 1 __t7lOb612) (join-old app (0 1 2) 2 (0 1 2) __t3MQm616 ef es) (join-old eval_args (1 3 2 0) 3 (1 3 2 0) es t rho __t192L615) (exists eval_args_ans (0 1) 1 __t192L615) (join eval_ans (0 1) 1 __t7lOb612 __t6tRF614) (join eval_args_ans (0 1) 1 __t192L615 vs) (join-old closure (0 1 2) 1 (0 1 2) __t6tRF614 __t20Nd613 rhoc) (join-old lambda (0 1 2) 1 (0 1 2) __t20Nd613 xs eb)) (head (emit bind_store (0 1 2 3) xs vs t2 t) (emit call_event (0 1) t2 t)) interp.slog:59 #f)
  class ReadTask1562 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** tickindex1542;  slog::Index** evalindex1543;  slog::Index** eval_argsindex1544;  slog::Index** evalindex1545;  slog::Index** eval_argsindex1546;  slog::Index** evalindex1547;  slog::Index** eval_ansindex1548;  slog::Index** appindex1549;  slog::Index** eval_argsindex1550;  slog::Index** eval_args_ansindex1551;  slog::Index** eval_ansindex1552;  slog::Index** eval_args_ansindex1553;  slog::Index** closureindex1554;  slog::Index** lambdaindex1555;  slog::Index** tickdelta1556;  slog::Index** evaldelta1557;  slog::Index** appdelta1558;  slog::Index** eval_argsdelta1559;  slog::Index** closuredelta1560;  slog::Index** lambdadelta1561;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("bind_store");
      std::vector<u16> ord1563({0, 1, 2, 3});
      slog::Relation* readrel1564 = db->getRelation("bind_store");
      head_index[0] = readrel1564->getIndex(ord1563, false);
      head_rel[1] = db->getRelation("call_event");
      std::vector<u16> ord1565({0, 1});
      slog::Relation* readrel1566 = db->getRelation("call_event");
      head_index[1] = readrel1566->getIndex(ord1565, false);
      outer_rel = db->getRelation("tick_ans");
      std::vector<u16> ord1567({0, 2, 1});
      slog::Relation* readrel1568 = db->getRelation("tick");
      tickindex1542 = readrel1568->getIndex(ord1567, false);
      std::vector<u16> ord1569({0, 2, 1});
      slog::Relation* readrel1570 = db->getRelation("tick");
      tickdelta1556 = readrel1570->getIndex(ord1569, true);
      std::vector<u16> ord1571({3, 1, 0, 2});
      slog::Relation* readrel1572 = db->getRelation("eval");
      evalindex1543 = readrel1572->getIndex(ord1571, false);
      std::vector<u16> ord1573({3, 2, 0, 1});
      slog::Relation* readrel1574 = db->getRelation("eval_args");
      eval_argsindex1544 = readrel1574->getIndex(ord1573, false);
      std::vector<u16> ord1575({3, 1, 0, 2});
      slog::Relation* readrel1576 = db->getRelation("eval");
      evalindex1545 = readrel1576->getIndex(ord1575, false);
      std::vector<u16> ord1577({3, 2, 0, 1});
      slog::Relation* readrel1578 = db->getRelation("eval_args");
      eval_argsindex1546 = readrel1578->getIndex(ord1577, false);
      std::vector<u16> ord1579({2, 3, 0, 1});
      slog::Relation* readrel1580 = db->getRelation("eval");
      evalindex1547 = readrel1580->getIndex(ord1579, false);
      std::vector<u16> ord1581({2, 3, 0, 1});
      slog::Relation* readrel1582 = db->getRelation("eval");
      evaldelta1557 = readrel1582->getIndex(ord1581, true);
      std::vector<u16> ord1583({0, 1});
      slog::Relation* readrel1584 = db->getRelation("eval_ans");
      eval_ansindex1548 = readrel1584->getIndex(ord1583, false);
      std::vector<u16> ord1585({0, 1, 2});
      slog::Relation* readrel1586 = db->getRelation("app");
      appindex1549 = readrel1586->getIndex(ord1585, false);
      std::vector<u16> ord1587({0, 1, 2});
      slog::Relation* readrel1588 = db->getRelation("app");
      appdelta1558 = readrel1588->getIndex(ord1587, true);
      std::vector<u16> ord1589({1, 3, 2, 0});
      slog::Relation* readrel1590 = db->getRelation("eval_args");
      eval_argsindex1550 = readrel1590->getIndex(ord1589, false);
      std::vector<u16> ord1591({1, 3, 2, 0});
      slog::Relation* readrel1592 = db->getRelation("eval_args");
      eval_argsdelta1559 = readrel1592->getIndex(ord1591, true);
      std::vector<u16> ord1593({0, 1});
      slog::Relation* readrel1594 = db->getRelation("eval_args_ans");
      eval_args_ansindex1551 = readrel1594->getIndex(ord1593, false);
      std::vector<u16> ord1595({0, 1});
      slog::Relation* readrel1596 = db->getRelation("eval_ans");
      eval_ansindex1552 = readrel1596->getIndex(ord1595, false);
      std::vector<u16> ord1597({0, 1});
      slog::Relation* readrel1598 = db->getRelation("eval_args_ans");
      eval_args_ansindex1553 = readrel1598->getIndex(ord1597, false);
      std::vector<u16> ord1599({0, 1, 2});
      slog::Relation* readrel1600 = db->getRelation("closure");
      closureindex1554 = readrel1600->getIndex(ord1599, false);
      std::vector<u16> ord1601({0, 1, 2});
      slog::Relation* readrel1602 = db->getRelation("closure");
      closuredelta1560 = readrel1602->getIndex(ord1601, true);
      std::vector<u16> ord1603({0, 1, 2});
      slog::Relation* readrel1604 = db->getRelation("lambda");
      lambdaindex1555 = readrel1604->getIndex(ord1603, false);
      std::vector<u16> ord1605({0, 1, 2});
      slog::Relation* readrel1606 = db->getRelation("lambda");
      lambdadelta1561 = readrel1606->getIndex(ord1605, true);
  
    }
    ReadTask1562(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c268 = _t[0];
        u64 v_c19 = _t[1];
        slog::join_probe_old<3,1>(tickindex1542, tickdelta1556, std::array<u64,3>{v_c268, 0, 0}, [&](const std::array<u64,3>& m1607) {
          u64 v_c7 = m1607[1]; u64 v_c269 = m1607[2];
          if (!slog::exists_probe<4,1>(evalindex1543, std::array<u64,4>{v_c7, 0, 0, 0})) return;
          if (!slog::exists_probe<4,1>(eval_argsindex1544, std::array<u64,4>{v_c7, 0, 0, 0})) return;
          slog::join_probe<4,2>(evalindex1545, std::array<u64,4>{v_c7, v_c269, 0, 0}, [&](const std::array<u64,4>& m1608) {
            u64 v_c270 = m1608[2]; u64 v_c6 = m1608[3];
            if (!slog::exists_probe<4,2>(eval_argsindex1546, std::array<u64,4>{v_c7, v_c6, 0, 0})) return;
            slog::join_probe_old<4,2>(evalindex1547, evaldelta1557, std::array<u64,4>{v_c6, v_c7, 0, 0}, [&](const std::array<u64,4>& m1609) {
              u64 v_c271 = m1609[2]; u64 v_c16 = m1609[3];
              if (!slog::exists_probe<2,1>(eval_ansindex1548, std::array<u64,2>{v_c271, 0})) return;
              slog::join_probe_old<3,2>(appindex1549, appdelta1558, std::array<u64,3>{v_c269, v_c16, 0}, [&](const std::array<u64,3>& m1610) {
                u64 v_c17 = m1610[2];
                slog::join_probe_old<4,3>(eval_argsindex1550, eval_argsdelta1559, std::array<u64,4>{v_c17, v_c7, v_c6, 0}, [&](const std::array<u64,4>& m1611) {
                  u64 v_c272 = m1611[3];
                  if (!slog::exists_probe<2,1>(eval_args_ansindex1551, std::array<u64,2>{v_c272, 0})) return;
                  slog::join_probe<2,1>(eval_ansindex1552, std::array<u64,2>{v_c271, 0}, [&](const std::array<u64,2>& m1612) {
                    u64 v_c273 = m1612[1];
                    slog::join_probe<2,1>(eval_args_ansindex1553, std::array<u64,2>{v_c272, 0}, [&](const std::array<u64,2>& m1613) {
                      u64 v_c20 = m1613[1];
                      slog::join_probe_old<3,1>(closureindex1554, closuredelta1560, std::array<u64,3>{v_c273, 0, 0}, [&](const std::array<u64,3>& m1614) {
                        u64 v_c274 = m1614[1]; u64 v_c18 = m1614[2];
                        slog::join_probe_old<3,1>(lambdaindex1555, lambdadelta1561, std::array<u64,3>{v_c274, 0, 0}, [&](const std::array<u64,3>& m1615) {
                          u64 v_c21 = m1615[1]; u64 v_c11 = m1615[2];
                          ++_fires;
                          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c21, v_c20, v_c19, v_c7}, std::array<u16,4>{0, 1, 2, 3});
                          slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c19, v_c7}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:59", "delta:tick_ans", _fires);
  
      if (!_done)
      {
        ReadTask1562* _cont = new ReadTask1562(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1562(db,b), false);
  // (crule (pre (let __tconst8WAL326 const6b86b273ff34fce19d6b804e)) (scan mbranch __t0WBy324 p m l r) (body (exists mp_has0 (1 2 0) 1 __t0WBy324) (exists mp_has0 (1 2 0) 1 l) (exists mp_msk (2 0 1) 1 m) (exists mp_msk_ans (1 0) 1 p) (join $sup5638x60x0x0x0 (4 2 3 5 0 1) 4 p l m r __t6Aa9325 k) (join-old mp_has0 (0 2 1) 3 (0 2 1) __t6Aa9325 k __t0WBy324) (exists mp_msk (1 2 0) 2 k m) (join-old mp_has0 (1 2 0) 2 (1 2 0) l k __t81Rn328) (exists mp_has0_ans (0 1) 1 __t81Rn328) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t2ONI329) (join mp_msk_ans (0 1) 2 __t2ONI329 p) (join mp_has0_ans (0 1) 1 __t81Rn328 a) (let __t5v2X327 (band k m)) (cmp lt __t5v2X327 __tconst8WAL326)) (head (emit mp_has0_ans (0 1) __t6Aa9325 a)) map.slog:61 #f)
  class ReadTask1631 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_has0index1616;  slog::Index** mp_has0index1617;  slog::Index** mp_mskindex1618;  slog::Index** mp_msk_ansindex1619;  slog::Index** $sup5638x60x0x0x0index1620;  slog::Index** mp_has0index1621;  slog::Index** mp_mskindex1622;  slog::Index** mp_has0index1623;  slog::Index** mp_has0_ansindex1624;  slog::Index** mp_mskindex1625;  slog::Index** mp_msk_ansindex1626;  slog::Index** mp_has0_ansindex1627;  slog::Index** mp_has0delta1628;  slog::Index** mp_has0delta1629;  slog::Index** mp_mskdelta1630;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_has0_ans");
      std::vector<u16> ord1632({0, 1});
      slog::Relation* readrel1633 = db->getRelation("mp_has0_ans");
      head_index[0] = readrel1633->getIndex(ord1632, false);
      outer_rel = db->getRelation("mbranch");
      std::vector<u16> ord1634({1, 2, 0});
      slog::Relation* readrel1635 = db->getRelation("mp_has0");
      mp_has0index1616 = readrel1635->getIndex(ord1634, false);
      std::vector<u16> ord1636({1, 2, 0});
      slog::Relation* readrel1637 = db->getRelation("mp_has0");
      mp_has0index1617 = readrel1637->getIndex(ord1636, false);
      std::vector<u16> ord1638({2, 0, 1});
      slog::Relation* readrel1639 = db->getRelation("mp_msk");
      mp_mskindex1618 = readrel1639->getIndex(ord1638, false);
      std::vector<u16> ord1640({1, 0});
      slog::Relation* readrel1641 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1619 = readrel1641->getIndex(ord1640, false);
      std::vector<u16> ord1642({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel1643 = db->getRelation("$sup5638x60x0x0x0");
      $sup5638x60x0x0x0index1620 = readrel1643->getIndex(ord1642, false);
      std::vector<u16> ord1644({0, 2, 1});
      slog::Relation* readrel1645 = db->getRelation("mp_has0");
      mp_has0index1621 = readrel1645->getIndex(ord1644, false);
      std::vector<u16> ord1646({0, 2, 1});
      slog::Relation* readrel1647 = db->getRelation("mp_has0");
      mp_has0delta1628 = readrel1647->getIndex(ord1646, true);
      std::vector<u16> ord1648({1, 2, 0});
      slog::Relation* readrel1649 = db->getRelation("mp_msk");
      mp_mskindex1622 = readrel1649->getIndex(ord1648, false);
      std::vector<u16> ord1650({1, 2, 0});
      slog::Relation* readrel1651 = db->getRelation("mp_has0");
      mp_has0index1623 = readrel1651->getIndex(ord1650, false);
      std::vector<u16> ord1652({1, 2, 0});
      slog::Relation* readrel1653 = db->getRelation("mp_has0");
      mp_has0delta1629 = readrel1653->getIndex(ord1652, true);
      std::vector<u16> ord1654({0, 1});
      slog::Relation* readrel1655 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex1624 = readrel1655->getIndex(ord1654, false);
      std::vector<u16> ord1656({1, 2, 0});
      slog::Relation* readrel1657 = db->getRelation("mp_msk");
      mp_mskindex1625 = readrel1657->getIndex(ord1656, false);
      std::vector<u16> ord1658({1, 2, 0});
      slog::Relation* readrel1659 = db->getRelation("mp_msk");
      mp_mskdelta1630 = readrel1659->getIndex(ord1658, true);
      std::vector<u16> ord1660({0, 1});
      slog::Relation* readrel1661 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex1626 = readrel1661->getIndex(ord1660, false);
      std::vector<u16> ord1662({0, 1});
      slog::Relation* readrel1663 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex1627 = readrel1663->getIndex(ord1662, false);
  
    }
    ReadTask1631(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c275 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c276 = _t[0];
        u64 v_c30 = _t[1];
        u64 v_c31 = _t[2];
        u64 v_c32 = _t[3];
        u64 v_c33 = _t[4];
        if (!slog::exists_probe<3,1>(mp_has0index1616, std::array<u64,3>{v_c276, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_has0index1617, std::array<u64,3>{v_c32, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex1618, std::array<u64,3>{v_c31, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex1619, std::array<u64,2>{v_c30, 0})) return;
        slog::join_probe<6,4>($sup5638x60x0x0x0index1620, std::array<u64,6>{v_c30, v_c32, v_c31, v_c33, 0, 0}, [&](const std::array<u64,6>& m1664) {
          u64 v_c277 = m1664[4]; u64 v_c34 = m1664[5];
          slog::join_probe_old<3,3>(mp_has0index1621, mp_has0delta1628, std::array<u64,3>{v_c277, v_c34, v_c276}, [&](const std::array<u64,3>& m1665) {
            if (!slog::exists_probe<3,2>(mp_mskindex1622, std::array<u64,3>{v_c34, v_c31, 0})) return;
            slog::join_probe_old<3,2>(mp_has0index1623, mp_has0delta1629, std::array<u64,3>{v_c32, v_c34, 0}, [&](const std::array<u64,3>& m1666) {
              u64 v_c278 = m1666[2];
              if (!slog::exists_probe<2,1>(mp_has0_ansindex1624, std::array<u64,2>{v_c278, 0})) return;
              slog::join_probe_old<3,2>(mp_mskindex1625, mp_mskdelta1630, std::array<u64,3>{v_c34, v_c31, 0}, [&](const std::array<u64,3>& m1667) {
                u64 v_c279 = m1667[2];
                slog::join_probe<2,2>(mp_msk_ansindex1626, std::array<u64,2>{v_c279, v_c30}, [&](const std::array<u64,2>& m1668) {
                  slog::join_probe<2,1>(mp_has0_ansindex1627, std::array<u64,2>{v_c278, 0}, [&](const std::array<u64,2>& m1669) {
                    u64 v_c280 = m1669[1];
                    u64 v_c281 = _prim_band(db, v_c34, v_c31);
                    if (v_c281 == slog_error) { slog::emit_pending_error(db, "map.slog:61"); return; }
                    u64 v_c282 = _prim_lt(db, v_c281, v_c275);
                    if (v_c282 == slog_error) { slog::emit_pending_error(db, "map.slog:61"); return; }
                    if (!v_c282) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c277, v_c280}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:61", "delta:mbranch", _fires);
  
      if (!_done)
      {
        ReadTask1631* _cont = new ReadTask1631(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1631(db,b), false);
}

