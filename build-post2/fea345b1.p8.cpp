
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const0f8748be649f8ee4066bb1d7;
extern u64 v_const229c0b7aa8a7eb4055f5a3d0;
extern u64 v_const361d5df359e0d7681220d09d;
extern u64 v_const3a82152bd1402931076fe2d7;
extern u64 v_const4492fd5fa4baacfebd29f5e5;
extern u64 v_const4a8acfc71441e0695ffcf5b3;
extern u64 v_const4d5ce1398140fbe27561181f;
extern u64 v_const4e3b5454cf93e32fad90650d;
extern u64 v_const4f84f41d89b6b717419b4eaa;
extern u64 v_const50a95ec20b9767e468d04917;
extern u64 v_const576506f61f53440f1edd95d2;
extern u64 v_const615ad01b1c532bb6634df115;
extern u64 v_const66518c0c1b3a5a0b09ae2ef1;
extern u64 v_const6bc0ba365ada70df115e1785;
extern u64 v_const6cf13cc59dcbe759113f68a4;
extern u64 v_const7b8fd91ee9ff10cfbb8066bf;
extern u64 v_const7c7d2cfc66f4d976987d2d20;
extern u64 v_const81cb39a72a584ab4f703b7f7;
extern u64 v_const85f09fa1913b9daf65957cf7;
extern u64 v_const8ca682693a0738a0641c6956;
extern u64 v_const969c6e56242ce8d0a4346602;
extern u64 v_const970c20ea81b833e5b5a7accf;
extern u64 v_const990b444cbd47632035b2fa1a;
extern u64 v_const9a67f28c6b77e842f439a84a;
extern u64 v_consta32d5a443def48e6d64c6f4b;
extern u64 v_consta8180db1c2f300980314f910;
extern u64 v_constaaaad65142343c54348db5d0;
extern u64 v_constb49bea2fcccd8f4301a347ed;
extern u64 v_constc40f204dda7ba4054abb9e74;
extern u64 v_constc85eae03730a4f4cf1d66a0c;
extern u64 v_constcaa3ee5a2828a31924f6b39d;
extern u64 v_constd5f017533ea574d5f9b3400c;
extern u64 v_constd7a1925d249b4768c8a9f2d8;
extern u64 v_constdbf1bdba02122b2adce28528;
extern u64 v_constdc1bb6655fb38bdb032e3754;
extern u64 v_conste58dec6bca6f63ef79c3b755;
extern u64 v_consteb793a6f75d6cfe49d3c2c90;
extern u64 v_constf0a25c0401304c51b5ee9c5e;


void slog_rules_c7ee83098c94661e0(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre (let __tconst7JVW192 const6cf13cc59dcbe759113f68a4) (let __tconst7B9N190 constcaa3ee5a2828a31924f6b39d) (let __tconst5wC2180 const970c20ea81b833e5b5a7accf) (let __tconst2ady176 constc40f204dda7ba4054abb9e74)) (seeded) (body (join ref (1 0) 1 __tconst7JVW192 __t6fOY185) (exists lambda (1 2 0) 1 __tconst2ady176) (exists ref (1 0) 1 __tconst5wC2180) (exists lambda (1 2 0) 1 __tconst5wC2180) (exists ref (1 0) 1 __tconst7B9N190) (exists app (1 2 0) 1 __t6fOY185) (join ref (1 0) 1 __tconst2ady176 __t3ZY4175) (join lambda (1 2 0) 2 __tconst2ady176 __t3ZY4175 __t1Ls4177) (join ref (1 0) 1 __tconst5wC2180 __t52sB179) (join lambda (1 2 0) 2 __tconst5wC2180 __t52sB179 __t6CST181) (join ref (1 0) 1 __tconst7B9N190 __t8oRJ183) (join app (1 2 0) 2 __t6fOY185 __t8oRJ183 __t2CTd186) (join app (1 2 0) 2 __t6fOY185 __t2CTd186 __t9pbS189)) (head (mkstruct lambda (1 2 0) __t6W4v191 __tconst7B9N190 __t9pbS189)) mcfa-counting.slog:301 #f)
  class ReadTask13 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex0;  slog::Index** lambdaindex1;  slog::Index** refindex2;  slog::Index** lambdaindex3;  slog::Index** refindex4;  slog::Index** appindex5;  slog::Index** refindex6;  slog::Index** lambdaindex7;  slog::Index** refindex8;  slog::Index** lambdaindex9;  slog::Index** refindex10;  slog::Index** appindex11;  slog::Index** appindex12;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      std::vector<u16> ord14({1, 2, 0});
      slog::Relation* readrel15 = db->getRelation("lambda");
      head_index[0] = readrel15->getIndex(ord14, false);
      std::vector<u16> ord16({1, 0});
      slog::Relation* readrel17 = db->getRelation("ref");
      refindex0 = readrel17->getIndex(ord16, false);
      std::vector<u16> ord18({1, 2, 0});
      slog::Relation* readrel19 = db->getRelation("lambda");
      lambdaindex1 = readrel19->getIndex(ord18, false);
      std::vector<u16> ord20({1, 0});
      slog::Relation* readrel21 = db->getRelation("ref");
      refindex2 = readrel21->getIndex(ord20, false);
      std::vector<u16> ord22({1, 2, 0});
      slog::Relation* readrel23 = db->getRelation("lambda");
      lambdaindex3 = readrel23->getIndex(ord22, false);
      std::vector<u16> ord24({1, 0});
      slog::Relation* readrel25 = db->getRelation("ref");
      refindex4 = readrel25->getIndex(ord24, false);
      std::vector<u16> ord26({1, 2, 0});
      slog::Relation* readrel27 = db->getRelation("app");
      appindex5 = readrel27->getIndex(ord26, false);
      std::vector<u16> ord28({1, 0});
      slog::Relation* readrel29 = db->getRelation("ref");
      refindex6 = readrel29->getIndex(ord28, false);
      std::vector<u16> ord30({1, 2, 0});
      slog::Relation* readrel31 = db->getRelation("lambda");
      lambdaindex7 = readrel31->getIndex(ord30, false);
      std::vector<u16> ord32({1, 0});
      slog::Relation* readrel33 = db->getRelation("ref");
      refindex8 = readrel33->getIndex(ord32, false);
      std::vector<u16> ord34({1, 2, 0});
      slog::Relation* readrel35 = db->getRelation("lambda");
      lambdaindex9 = readrel35->getIndex(ord34, false);
      std::vector<u16> ord36({1, 0});
      slog::Relation* readrel37 = db->getRelation("ref");
      refindex10 = readrel37->getIndex(ord36, false);
      std::vector<u16> ord38({1, 2, 0});
      slog::Relation* readrel39 = db->getRelation("app");
      appindex11 = readrel39->getIndex(ord38, false);
      std::vector<u16> ord40({1, 2, 0});
      slog::Relation* readrel41 = db->getRelation("app");
      appindex12 = readrel41->getIndex(ord40, false);
  
    }
    ReadTask13(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const6cf13cc59dcbe759113f68a4;
      u64 v_c1 = v_constcaa3ee5a2828a31924f6b39d;
      u64 v_c2 = v_const970c20ea81b833e5b5a7accf;
      u64 v_c3 = v_constc40f204dda7ba4054abb9e74;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex0, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m42) {
        u64 v_c4 = m42[1];
        if (!slog::exists_probe<3,1>(lambdaindex1, std::array<u64,3>{v_c3, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex2, std::array<u64,2>{v_c2, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex3, std::array<u64,3>{v_c2, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex4, std::array<u64,2>{v_c1, 0})) return;
        if (!slog::exists_probe<3,1>(appindex5, std::array<u64,3>{v_c4, 0, 0})) return;
        slog::join_probe<2,1>(refindex6, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m43) {
          u64 v_c5 = m43[1];
          slog::join_probe<3,2>(lambdaindex7, std::array<u64,3>{v_c3, v_c5, 0}, [&](const std::array<u64,3>& m44) {
            u64 v_c6 = m44[2];
            slog::join_probe<2,1>(refindex8, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m45) {
              u64 v_c7 = m45[1];
              slog::join_probe<3,2>(lambdaindex9, std::array<u64,3>{v_c2, v_c7, 0}, [&](const std::array<u64,3>& m46) {
                u64 v_c8 = m46[2];
                slog::join_probe<2,1>(refindex10, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m47) {
                  u64 v_c9 = m47[1];
                  slog::join_probe<3,2>(appindex11, std::array<u64,3>{v_c4, v_c9, 0}, [&](const std::array<u64,3>& m48) {
                    u64 v_c10 = m48[2];
                    slog::join_probe<3,2>(appindex12, std::array<u64,3>{v_c4, v_c10, 0}, [&](const std::array<u64,3>& m49) {
                      u64 v_c11 = m49[2];
                      ++_fires;
                      slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c1, v_c11}, std::array<u16,3>{1, 2, 0});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:301", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask13(db,b));
  // (crule (pre) (scan $sup27994x83x0x0x0 __t5GoB317 c ea ef) (body (exists eval (1 2 0) 2 ef c) (exists eval (1 2 0) 2 ea c) (exists eval (0 2 1) 2 __t5GoB317 c) (exists app (1 2 0) 2 ef ea) (join-old $sup27994x83x0x0x1 (5 7 0 3 1 2 4 6 8 9) 4 (5 7 0 3 1 2 4 6 8 9) ea ef __t5GoB317 c __t1FV8318 __t8XTs321 cb eb va x) (join-old eval (0 2 1) 3 (0 2 1) __t1FV8318 c ef) (join-old eval (0 2 1) 3 (0 2 1) __t8XTs321 c ea) (join eval_ans (0 1) 2 __t8XTs321 va) (exists lambda (1 2 0) 2 x eb) (exists clo (2 0 1) 1 cb) (exists eval_ans (0 1) 1 __t1FV8318) (exists eval (1 2 0) 1 eb) (join-old eval (0 2 1) 2 (0 2 1) __t5GoB317 c __t3MbO322) (join-old app (0 1 2) 3 (0 1 2) __t3MbO322 ef ea) (exists eval (1 2 0) 2 eb __t3MbO322) (join-old lambda (1 2 0) 2 (1 2 0) x eb __t6vap319) (join-old clo (1 2 0) 2 (1 2 0) __t6vap319 cb __t1oxE320) (join eval_ans (0 1) 2 __t1FV8318 __t1oxE320) (join-old eval (1 2 0) 2 (1 2 0) eb __t3MbO322 __t3H1A323) (join eval_ans (0 1) 1 __t3H1A323 v)) (head (emit eval_ans (0 1) __t5GoB317 v)) mcfa-counting.slog:84 #f)
  class ReadTask78 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex50;  slog::Index** evalindex51;  slog::Index** evalindex52;  slog::Index** appindex53;  slog::Index** $sup27994x83x0x0x1index54;  slog::Index** evalindex55;  slog::Index** evalindex56;  slog::Index** eval_ansindex57;  slog::Index** lambdaindex58;  slog::Index** cloindex59;  slog::Index** eval_ansindex60;  slog::Index** evalindex61;  slog::Index** evalindex62;  slog::Index** appindex63;  slog::Index** evalindex64;  slog::Index** lambdaindex65;  slog::Index** cloindex66;  slog::Index** eval_ansindex67;  slog::Index** evalindex68;  slog::Index** eval_ansindex69;  slog::Index** $sup27994x83x0x0x1delta70;  slog::Index** evaldelta71;  slog::Index** evaldelta72;  slog::Index** evaldelta73;  slog::Index** appdelta74;  slog::Index** lambdadelta75;  slog::Index** clodelta76;  slog::Index** evaldelta77;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord79({0, 1});
      slog::Relation* readrel80 = db->getRelation("eval_ans");
      head_index[0] = readrel80->getIndex(ord79, false);
      outer_rel = db->getRelation("$sup27994x83x0x0x0");
      std::vector<u16> ord81({1, 2, 0});
      slog::Relation* readrel82 = db->getRelation("eval");
      evalindex50 = readrel82->getIndex(ord81, false);
      std::vector<u16> ord83({1, 2, 0});
      slog::Relation* readrel84 = db->getRelation("eval");
      evalindex51 = readrel84->getIndex(ord83, false);
      std::vector<u16> ord85({0, 2, 1});
      slog::Relation* readrel86 = db->getRelation("eval");
      evalindex52 = readrel86->getIndex(ord85, false);
      std::vector<u16> ord87({1, 2, 0});
      slog::Relation* readrel88 = db->getRelation("app");
      appindex53 = readrel88->getIndex(ord87, false);
      std::vector<u16> ord89({5, 7, 0, 3, 1, 2, 4, 6, 8, 9});
      slog::Relation* readrel90 = db->getRelation("$sup27994x83x0x0x1");
      $sup27994x83x0x0x1index54 = readrel90->getIndex(ord89, false);
      std::vector<u16> ord91({5, 7, 0, 3, 1, 2, 4, 6, 8, 9});
      slog::Relation* readrel92 = db->getRelation("$sup27994x83x0x0x1");
      $sup27994x83x0x0x1delta70 = readrel92->getIndex(ord91, true);
      std::vector<u16> ord93({0, 2, 1});
      slog::Relation* readrel94 = db->getRelation("eval");
      evalindex55 = readrel94->getIndex(ord93, false);
      std::vector<u16> ord95({0, 2, 1});
      slog::Relation* readrel96 = db->getRelation("eval");
      evaldelta71 = readrel96->getIndex(ord95, true);
      std::vector<u16> ord97({0, 2, 1});
      slog::Relation* readrel98 = db->getRelation("eval");
      evalindex56 = readrel98->getIndex(ord97, false);
      std::vector<u16> ord99({0, 2, 1});
      slog::Relation* readrel100 = db->getRelation("eval");
      evaldelta72 = readrel100->getIndex(ord99, true);
      std::vector<u16> ord101({0, 1});
      slog::Relation* readrel102 = db->getRelation("eval_ans");
      eval_ansindex57 = readrel102->getIndex(ord101, false);
      std::vector<u16> ord103({1, 2, 0});
      slog::Relation* readrel104 = db->getRelation("lambda");
      lambdaindex58 = readrel104->getIndex(ord103, false);
      std::vector<u16> ord105({2, 0, 1});
      slog::Relation* readrel106 = db->getRelation("clo");
      cloindex59 = readrel106->getIndex(ord105, false);
      std::vector<u16> ord107({0, 1});
      slog::Relation* readrel108 = db->getRelation("eval_ans");
      eval_ansindex60 = readrel108->getIndex(ord107, false);
      std::vector<u16> ord109({1, 2, 0});
      slog::Relation* readrel110 = db->getRelation("eval");
      evalindex61 = readrel110->getIndex(ord109, false);
      std::vector<u16> ord111({0, 2, 1});
      slog::Relation* readrel112 = db->getRelation("eval");
      evalindex62 = readrel112->getIndex(ord111, false);
      std::vector<u16> ord113({0, 2, 1});
      slog::Relation* readrel114 = db->getRelation("eval");
      evaldelta73 = readrel114->getIndex(ord113, true);
      std::vector<u16> ord115({0, 1, 2});
      slog::Relation* readrel116 = db->getRelation("app");
      appindex63 = readrel116->getIndex(ord115, false);
      std::vector<u16> ord117({0, 1, 2});
      slog::Relation* readrel118 = db->getRelation("app");
      appdelta74 = readrel118->getIndex(ord117, true);
      std::vector<u16> ord119({1, 2, 0});
      slog::Relation* readrel120 = db->getRelation("eval");
      evalindex64 = readrel120->getIndex(ord119, false);
      std::vector<u16> ord121({1, 2, 0});
      slog::Relation* readrel122 = db->getRelation("lambda");
      lambdaindex65 = readrel122->getIndex(ord121, false);
      std::vector<u16> ord123({1, 2, 0});
      slog::Relation* readrel124 = db->getRelation("lambda");
      lambdadelta75 = readrel124->getIndex(ord123, true);
      std::vector<u16> ord125({1, 2, 0});
      slog::Relation* readrel126 = db->getRelation("clo");
      cloindex66 = readrel126->getIndex(ord125, false);
      std::vector<u16> ord127({1, 2, 0});
      slog::Relation* readrel128 = db->getRelation("clo");
      clodelta76 = readrel128->getIndex(ord127, true);
      std::vector<u16> ord129({0, 1});
      slog::Relation* readrel130 = db->getRelation("eval_ans");
      eval_ansindex67 = readrel130->getIndex(ord129, false);
      std::vector<u16> ord131({1, 2, 0});
      slog::Relation* readrel132 = db->getRelation("eval");
      evalindex68 = readrel132->getIndex(ord131, false);
      std::vector<u16> ord133({1, 2, 0});
      slog::Relation* readrel134 = db->getRelation("eval");
      evaldelta77 = readrel134->getIndex(ord133, true);
      std::vector<u16> ord135({0, 1});
      slog::Relation* readrel136 = db->getRelation("eval_ans");
      eval_ansindex69 = readrel136->getIndex(ord135, false);
  
    }
    ReadTask78(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        if (!slog::exists_probe<3,2>(evalindex50, std::array<u64,3>{v_c15, v_c13, 0})) return;
        if (!slog::exists_probe<3,2>(evalindex51, std::array<u64,3>{v_c14, v_c13, 0})) return;
        if (!slog::exists_probe<3,2>(evalindex52, std::array<u64,3>{v_c12, v_c13, 0})) return;
        if (!slog::exists_probe<3,2>(appindex53, std::array<u64,3>{v_c15, v_c14, 0})) return;
        slog::join_probe_old<10,4>($sup27994x83x0x0x1index54, $sup27994x83x0x0x1delta70, std::array<u64,10>{v_c14, v_c15, v_c12, v_c13, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,10>& m137) {
          u64 v_c16 = m137[4]; u64 v_c17 = m137[5]; u64 v_c18 = m137[6]; u64 v_c19 = m137[7]; u64 v_c20 = m137[8]; u64 v_c21 = m137[9];
          slog::join_probe_old<3,3>(evalindex55, evaldelta71, std::array<u64,3>{v_c16, v_c13, v_c15}, [&](const std::array<u64,3>& m138) {
            slog::join_probe_old<3,3>(evalindex56, evaldelta72, std::array<u64,3>{v_c17, v_c13, v_c14}, [&](const std::array<u64,3>& m139) {
              slog::join_probe<2,2>(eval_ansindex57, std::array<u64,2>{v_c17, v_c20}, [&](const std::array<u64,2>& m140) {
                if (!slog::exists_probe<3,2>(lambdaindex58, std::array<u64,3>{v_c21, v_c19, 0})) return;
                if (!slog::exists_probe<3,1>(cloindex59, std::array<u64,3>{v_c18, 0, 0})) return;
                if (!slog::exists_probe<2,1>(eval_ansindex60, std::array<u64,2>{v_c16, 0})) return;
                if (!slog::exists_probe<3,1>(evalindex61, std::array<u64,3>{v_c19, 0, 0})) return;
                slog::join_probe_old<3,2>(evalindex62, evaldelta73, std::array<u64,3>{v_c12, v_c13, 0}, [&](const std::array<u64,3>& m141) {
                  u64 v_c22 = m141[2];
                  slog::join_probe_old<3,3>(appindex63, appdelta74, std::array<u64,3>{v_c22, v_c15, v_c14}, [&](const std::array<u64,3>& m142) {
                    if (!slog::exists_probe<3,2>(evalindex64, std::array<u64,3>{v_c19, v_c22, 0})) return;
                    slog::join_probe_old<3,2>(lambdaindex65, lambdadelta75, std::array<u64,3>{v_c21, v_c19, 0}, [&](const std::array<u64,3>& m143) {
                      u64 v_c23 = m143[2];
                      slog::join_probe_old<3,2>(cloindex66, clodelta76, std::array<u64,3>{v_c23, v_c18, 0}, [&](const std::array<u64,3>& m144) {
                        u64 v_c24 = m144[2];
                        slog::join_probe<2,2>(eval_ansindex67, std::array<u64,2>{v_c16, v_c24}, [&](const std::array<u64,2>& m145) {
                          slog::join_probe_old<3,2>(evalindex68, evaldelta77, std::array<u64,3>{v_c19, v_c22, 0}, [&](const std::array<u64,3>& m146) {
                            u64 v_c25 = m146[2];
                            slog::join_probe<2,1>(eval_ansindex69, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m147) {
                              u64 v_c26 = m147[1];
                              ++_fires;
                              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c12, v_c26}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("mcfa-counting.slog:84", "delta:$sup27994x83x0x0x0", _fires);
  
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
  // (crule (pre (let __tconst4Xaz41 const81cb39a72a584ab4f703b7f7) (let __tconst4xzG22 constdbf1bdba02122b2adce28528) (let __tconst1aIN38 const4d5ce1398140fbe27561181f) (let __tconst1HMF17 constd7a1925d249b4768c8a9f2d8) (let __tconst37GM26 const85f09fa1913b9daf65957cf7) (let __tconst1ha033 const969c6e56242ce8d0a4346602)) (scan app __t9tGa43 __t79we42 __t8Ovw23) (body (exists lambda (0 1 2) 2 __t79we42 __tconst4Xaz41) (exists ref (1 0) 1 __tconst4xzG22) (exists lambda (1 2 0) 1 __tconst1HMF17) (exists ref (1 0) 1 __tconst1HMF17) (exists ref (1 0) 1 __tconst4Xaz41) (exists ref (1 0) 1 __tconst37GM26) (exists lambda (1 2 0) 1 __tconst37GM26) (exists lambda (1 2 0) 1 __tconst1aIN38) (exists lambda (1 2 0) 1 __tconst1ha033) (exists ref (1 0) 1 __tconst1ha033) (join lambda (0 1 2) 2 __t8Ovw23 __tconst4xzG22 __t3b2k21) (join lambda (0 1 2) 2 __t79we42 __tconst4Xaz41 __t7P7240) (join ref (1 0) 1 __tconst4xzG22 __t2DOE20) (join app (0 1 2) 2 __t3b2k21 __t2DOE20 __t2wNc18) (join lambda (0 1 2) 2 __t2wNc18 __tconst1HMF17 __t7H1u16) (join ref (0 1) 2 __t7H1u16 __tconst1HMF17) (join ref (1 0) 1 __tconst4Xaz41 __t75SZ29) (exists app (1 2 0) 1 __t75SZ29) (join ref (1 0) 1 __tconst37GM26 __t7U1m25) (join lambda (1 2 0) 2 __tconst37GM26 __t7U1m25 __t5myE27) (join app (1 2 0) 2 __t75SZ29 __t5myE27 __t2Vg230) (join app (2 0 1) 2 __t2Vg230 __t7P7240 __t3aRV39) (join lambda (0 1 2) 2 __t3aRV39 __tconst1aIN38 __t3pMW37) (join app (0 1 2) 2 __t3pMW37 __t75SZ29 __t065j34) (join lambda (0 1 2) 2 __t065j34 __tconst1ha033 __t7N9A32) (join ref (0 1) 2 __t7N9A32 __tconst1ha033)) (head (emit program (0) __t9tGa43)) mcfa-counting.slog:260 #f)
  class ReadTask174 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lambdaindex148;  slog::Index** refindex149;  slog::Index** lambdaindex150;  slog::Index** refindex151;  slog::Index** refindex152;  slog::Index** refindex153;  slog::Index** lambdaindex154;  slog::Index** lambdaindex155;  slog::Index** lambdaindex156;  slog::Index** refindex157;  slog::Index** lambdaindex158;  slog::Index** lambdaindex159;  slog::Index** refindex160;  slog::Index** appindex161;  slog::Index** lambdaindex162;  slog::Index** refindex163;  slog::Index** refindex164;  slog::Index** appindex165;  slog::Index** refindex166;  slog::Index** lambdaindex167;  slog::Index** appindex168;  slog::Index** appindex169;  slog::Index** lambdaindex170;  slog::Index** appindex171;  slog::Index** lambdaindex172;  slog::Index** refindex173;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("program");
      std::vector<u16> ord175({0});
      slog::Relation* readrel176 = db->getRelation("program");
      head_index[0] = readrel176->getIndex(ord175, false);
      outer_rel = db->getRelation("app");
      std::vector<u16> ord177({0, 1, 2});
      slog::Relation* readrel178 = db->getRelation("lambda");
      lambdaindex148 = readrel178->getIndex(ord177, false);
      std::vector<u16> ord179({1, 0});
      slog::Relation* readrel180 = db->getRelation("ref");
      refindex149 = readrel180->getIndex(ord179, false);
      std::vector<u16> ord181({1, 2, 0});
      slog::Relation* readrel182 = db->getRelation("lambda");
      lambdaindex150 = readrel182->getIndex(ord181, false);
      std::vector<u16> ord183({1, 0});
      slog::Relation* readrel184 = db->getRelation("ref");
      refindex151 = readrel184->getIndex(ord183, false);
      std::vector<u16> ord185({1, 0});
      slog::Relation* readrel186 = db->getRelation("ref");
      refindex152 = readrel186->getIndex(ord185, false);
      std::vector<u16> ord187({1, 0});
      slog::Relation* readrel188 = db->getRelation("ref");
      refindex153 = readrel188->getIndex(ord187, false);
      std::vector<u16> ord189({1, 2, 0});
      slog::Relation* readrel190 = db->getRelation("lambda");
      lambdaindex154 = readrel190->getIndex(ord189, false);
      std::vector<u16> ord191({1, 2, 0});
      slog::Relation* readrel192 = db->getRelation("lambda");
      lambdaindex155 = readrel192->getIndex(ord191, false);
      std::vector<u16> ord193({1, 2, 0});
      slog::Relation* readrel194 = db->getRelation("lambda");
      lambdaindex156 = readrel194->getIndex(ord193, false);
      std::vector<u16> ord195({1, 0});
      slog::Relation* readrel196 = db->getRelation("ref");
      refindex157 = readrel196->getIndex(ord195, false);
      std::vector<u16> ord197({0, 1, 2});
      slog::Relation* readrel198 = db->getRelation("lambda");
      lambdaindex158 = readrel198->getIndex(ord197, false);
      std::vector<u16> ord199({0, 1, 2});
      slog::Relation* readrel200 = db->getRelation("lambda");
      lambdaindex159 = readrel200->getIndex(ord199, false);
      std::vector<u16> ord201({1, 0});
      slog::Relation* readrel202 = db->getRelation("ref");
      refindex160 = readrel202->getIndex(ord201, false);
      std::vector<u16> ord203({0, 1, 2});
      slog::Relation* readrel204 = db->getRelation("app");
      appindex161 = readrel204->getIndex(ord203, false);
      std::vector<u16> ord205({0, 1, 2});
      slog::Relation* readrel206 = db->getRelation("lambda");
      lambdaindex162 = readrel206->getIndex(ord205, false);
      std::vector<u16> ord207({0, 1});
      slog::Relation* readrel208 = db->getRelation("ref");
      refindex163 = readrel208->getIndex(ord207, false);
      std::vector<u16> ord209({1, 0});
      slog::Relation* readrel210 = db->getRelation("ref");
      refindex164 = readrel210->getIndex(ord209, false);
      std::vector<u16> ord211({1, 2, 0});
      slog::Relation* readrel212 = db->getRelation("app");
      appindex165 = readrel212->getIndex(ord211, false);
      std::vector<u16> ord213({1, 0});
      slog::Relation* readrel214 = db->getRelation("ref");
      refindex166 = readrel214->getIndex(ord213, false);
      std::vector<u16> ord215({1, 2, 0});
      slog::Relation* readrel216 = db->getRelation("lambda");
      lambdaindex167 = readrel216->getIndex(ord215, false);
      std::vector<u16> ord217({1, 2, 0});
      slog::Relation* readrel218 = db->getRelation("app");
      appindex168 = readrel218->getIndex(ord217, false);
      std::vector<u16> ord219({2, 0, 1});
      slog::Relation* readrel220 = db->getRelation("app");
      appindex169 = readrel220->getIndex(ord219, false);
      std::vector<u16> ord221({0, 1, 2});
      slog::Relation* readrel222 = db->getRelation("lambda");
      lambdaindex170 = readrel222->getIndex(ord221, false);
      std::vector<u16> ord223({0, 1, 2});
      slog::Relation* readrel224 = db->getRelation("app");
      appindex171 = readrel224->getIndex(ord223, false);
      std::vector<u16> ord225({0, 1, 2});
      slog::Relation* readrel226 = db->getRelation("lambda");
      lambdaindex172 = readrel226->getIndex(ord225, false);
      std::vector<u16> ord227({0, 1});
      slog::Relation* readrel228 = db->getRelation("ref");
      refindex173 = readrel228->getIndex(ord227, false);
  
    }
    ReadTask174(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c27 = v_const81cb39a72a584ab4f703b7f7;
      u64 v_c28 = v_constdbf1bdba02122b2adce28528;
      u64 v_c29 = v_const4d5ce1398140fbe27561181f;
      u64 v_c30 = v_constd7a1925d249b4768c8a9f2d8;
      u64 v_c31 = v_const85f09fa1913b9daf65957cf7;
      u64 v_c32 = v_const969c6e56242ce8d0a4346602;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c33 = _t[0];
        u64 v_c34 = _t[1];
        u64 v_c35 = _t[2];
        if (!slog::exists_probe<3,2>(lambdaindex148, std::array<u64,3>{v_c34, v_c27, 0})) return;
        if (!slog::exists_probe<2,1>(refindex149, std::array<u64,2>{v_c28, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex150, std::array<u64,3>{v_c30, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex151, std::array<u64,2>{v_c30, 0})) return;
        if (!slog::exists_probe<2,1>(refindex152, std::array<u64,2>{v_c27, 0})) return;
        if (!slog::exists_probe<2,1>(refindex153, std::array<u64,2>{v_c31, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex154, std::array<u64,3>{v_c31, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex155, std::array<u64,3>{v_c29, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex156, std::array<u64,3>{v_c32, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex157, std::array<u64,2>{v_c32, 0})) return;
        slog::join_probe<3,2>(lambdaindex158, std::array<u64,3>{v_c35, v_c28, 0}, [&](const std::array<u64,3>& m229) {
          u64 v_c36 = m229[2];
          slog::join_probe<3,2>(lambdaindex159, std::array<u64,3>{v_c34, v_c27, 0}, [&](const std::array<u64,3>& m230) {
            u64 v_c37 = m230[2];
            slog::join_probe<2,1>(refindex160, std::array<u64,2>{v_c28, 0}, [&](const std::array<u64,2>& m231) {
              u64 v_c38 = m231[1];
              slog::join_probe<3,2>(appindex161, std::array<u64,3>{v_c36, v_c38, 0}, [&](const std::array<u64,3>& m232) {
                u64 v_c39 = m232[2];
                slog::join_probe<3,2>(lambdaindex162, std::array<u64,3>{v_c39, v_c30, 0}, [&](const std::array<u64,3>& m233) {
                  u64 v_c40 = m233[2];
                  slog::join_probe<2,2>(refindex163, std::array<u64,2>{v_c40, v_c30}, [&](const std::array<u64,2>& m234) {
                    slog::join_probe<2,1>(refindex164, std::array<u64,2>{v_c27, 0}, [&](const std::array<u64,2>& m235) {
                      u64 v_c41 = m235[1];
                      if (!slog::exists_probe<3,1>(appindex165, std::array<u64,3>{v_c41, 0, 0})) return;
                      slog::join_probe<2,1>(refindex166, std::array<u64,2>{v_c31, 0}, [&](const std::array<u64,2>& m236) {
                        u64 v_c42 = m236[1];
                        slog::join_probe<3,2>(lambdaindex167, std::array<u64,3>{v_c31, v_c42, 0}, [&](const std::array<u64,3>& m237) {
                          u64 v_c43 = m237[2];
                          slog::join_probe<3,2>(appindex168, std::array<u64,3>{v_c41, v_c43, 0}, [&](const std::array<u64,3>& m238) {
                            u64 v_c44 = m238[2];
                            slog::join_probe<3,2>(appindex169, std::array<u64,3>{v_c44, v_c37, 0}, [&](const std::array<u64,3>& m239) {
                              u64 v_c45 = m239[2];
                              slog::join_probe<3,2>(lambdaindex170, std::array<u64,3>{v_c45, v_c29, 0}, [&](const std::array<u64,3>& m240) {
                                u64 v_c46 = m240[2];
                                slog::join_probe<3,2>(appindex171, std::array<u64,3>{v_c46, v_c41, 0}, [&](const std::array<u64,3>& m241) {
                                  u64 v_c47 = m241[2];
                                  slog::join_probe<3,2>(lambdaindex172, std::array<u64,3>{v_c47, v_c32, 0}, [&](const std::array<u64,3>& m242) {
                                    u64 v_c48 = m242[2];
                                    slog::join_probe<2,2>(refindex173, std::array<u64,2>{v_c48, v_c32}, [&](const std::array<u64,2>& m243) {
                                      ++_fires;
                                      slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c33}, std::array<u16,1>{0});
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
  
      if (_fires) db->bumpFires("mcfa-counting.slog:260", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask174* _cont = new ReadTask174(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask174(db,b), false);
  // (crule (pre (let __tconst9zoW125 const7c7d2cfc66f4d976987d2d20) (let __tconst4V4L122 const6bc0ba365ada70df115e1785) (let __tconst82U8119 consta8180db1c2f300980314f910) (let __tconst3wDH116 constd5f017533ea574d5f9b3400c) (let __tconst4Zcr91 const9a67f28c6b77e842f439a84a) (let __tconst0vRf84 conste58dec6bca6f63ef79c3b755) (let __tconst4BKz104 const0f8748be649f8ee4066bb1d7) (let __tconst3ktF111 const990b444cbd47632035b2fa1a) (let __tconst5nWJ102 const4f84f41d89b6b717419b4eaa)) (seeded) (body (join ref (1 0) 1 __tconst4V4L122 __t7aew98) (exists lambda (1 2 0) 1 __tconst0vRf84) (exists ref (1 0) 1 __tconst3wDH116) (exists ref (1 0) 1 __tconst4Zcr91) (exists ref (1 0) 1 __tconst9zoW125) (exists lambda (1 2 0) 1 __tconst4Zcr91) (exists ref (1 0) 1 __tconst4BKz104) (exists lambda (1 2 0) 1 __tconst4BKz104) (exists app (1 2 0) 1 __t7aew98) (exists ref (1 0) 1 __tconst5nWJ102) (exists lambda (1 2 0) 1 __tconst5nWJ102) (exists ref (1 0) 1 __tconst3ktF111) (exists lambda (1 2 0) 1 __tconst3ktF111) (exists lambda (1 2 0) 1 __tconst3wDH116) (join ref (1 0) 1 __tconst0vRf84 __t2duR83) (join lambda (1 2 0) 2 __tconst0vRf84 __t2duR83 __t87vL85) (join ref (1 0) 1 __tconst3wDH116 __t3wir114) (exists app (1 2 0) 1 __t3wir114) (join ref (1 0) 1 __tconst4Zcr91 __t0C9F87) (exists app (2 0 1) 1 __t0C9F87) (join ref (1 0) 1 __tconst9zoW125 __t3Q2G89) (join app (1 2 0) 2 __t3Q2G89 __t0C9F87 __t2Eqd90) (join lambda (1 2 0) 2 __tconst4Zcr91 __t2Eqd90 __t3pgm92) (join ref (1 0) 1 __tconst4BKz104 __t8C0a94) (join lambda (1 2 0) 2 __tconst4BKz104 __t8C0a94 __t4fDK96) (join app (1 2 0) 2 __t7aew98 __t4fDK96 __t7TEO99) (join ref (1 0) 1 __tconst5nWJ102 __t5MaG101) (join lambda (1 2 0) 2 __tconst5nWJ102 __t5MaG101 __t35jA103) (join lambda (1 2 0) 2 __tconst4BKz104 __t35jA103 __t6RuY105) (join app (1 2 0) 2 __t7aew98 __t6RuY105 __t2Z7m108) (exists app (2 0 1) 1 __t2Z7m108) (join ref (1 0) 1 __tconst3ktF111 __t7ohz110) (join lambda (1 2 0) 2 __tconst3ktF111 __t7ohz110 __t8GWA112) (join app (1 2 0) 2 __t3wir114 __t8GWA112 __t44OM115) (join lambda (1 2 0) 2 __tconst3wDH116 __t44OM115 __t7CwH117) (join app (1 2 0) 2 __t7CwH117 __t2Z7m108 __t50Kk118)) (head (mkstruct lambda (1 2 0) __t3SEs120 __tconst82U8119 __t50Kk118)) mcfa-counting.slog:241 #f)
  class ReadTask280 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex244;  slog::Index** lambdaindex245;  slog::Index** refindex246;  slog::Index** refindex247;  slog::Index** refindex248;  slog::Index** lambdaindex249;  slog::Index** refindex250;  slog::Index** lambdaindex251;  slog::Index** appindex252;  slog::Index** refindex253;  slog::Index** lambdaindex254;  slog::Index** refindex255;  slog::Index** lambdaindex256;  slog::Index** lambdaindex257;  slog::Index** refindex258;  slog::Index** lambdaindex259;  slog::Index** refindex260;  slog::Index** appindex261;  slog::Index** refindex262;  slog::Index** appindex263;  slog::Index** refindex264;  slog::Index** appindex265;  slog::Index** lambdaindex266;  slog::Index** refindex267;  slog::Index** lambdaindex268;  slog::Index** appindex269;  slog::Index** refindex270;  slog::Index** lambdaindex271;  slog::Index** lambdaindex272;  slog::Index** appindex273;  slog::Index** appindex274;  slog::Index** refindex275;  slog::Index** lambdaindex276;  slog::Index** appindex277;  slog::Index** lambdaindex278;  slog::Index** appindex279;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      std::vector<u16> ord281({1, 2, 0});
      slog::Relation* readrel282 = db->getRelation("lambda");
      head_index[0] = readrel282->getIndex(ord281, false);
      std::vector<u16> ord283({1, 0});
      slog::Relation* readrel284 = db->getRelation("ref");
      refindex244 = readrel284->getIndex(ord283, false);
      std::vector<u16> ord285({1, 2, 0});
      slog::Relation* readrel286 = db->getRelation("lambda");
      lambdaindex245 = readrel286->getIndex(ord285, false);
      std::vector<u16> ord287({1, 0});
      slog::Relation* readrel288 = db->getRelation("ref");
      refindex246 = readrel288->getIndex(ord287, false);
      std::vector<u16> ord289({1, 0});
      slog::Relation* readrel290 = db->getRelation("ref");
      refindex247 = readrel290->getIndex(ord289, false);
      std::vector<u16> ord291({1, 0});
      slog::Relation* readrel292 = db->getRelation("ref");
      refindex248 = readrel292->getIndex(ord291, false);
      std::vector<u16> ord293({1, 2, 0});
      slog::Relation* readrel294 = db->getRelation("lambda");
      lambdaindex249 = readrel294->getIndex(ord293, false);
      std::vector<u16> ord295({1, 0});
      slog::Relation* readrel296 = db->getRelation("ref");
      refindex250 = readrel296->getIndex(ord295, false);
      std::vector<u16> ord297({1, 2, 0});
      slog::Relation* readrel298 = db->getRelation("lambda");
      lambdaindex251 = readrel298->getIndex(ord297, false);
      std::vector<u16> ord299({1, 2, 0});
      slog::Relation* readrel300 = db->getRelation("app");
      appindex252 = readrel300->getIndex(ord299, false);
      std::vector<u16> ord301({1, 0});
      slog::Relation* readrel302 = db->getRelation("ref");
      refindex253 = readrel302->getIndex(ord301, false);
      std::vector<u16> ord303({1, 2, 0});
      slog::Relation* readrel304 = db->getRelation("lambda");
      lambdaindex254 = readrel304->getIndex(ord303, false);
      std::vector<u16> ord305({1, 0});
      slog::Relation* readrel306 = db->getRelation("ref");
      refindex255 = readrel306->getIndex(ord305, false);
      std::vector<u16> ord307({1, 2, 0});
      slog::Relation* readrel308 = db->getRelation("lambda");
      lambdaindex256 = readrel308->getIndex(ord307, false);
      std::vector<u16> ord309({1, 2, 0});
      slog::Relation* readrel310 = db->getRelation("lambda");
      lambdaindex257 = readrel310->getIndex(ord309, false);
      std::vector<u16> ord311({1, 0});
      slog::Relation* readrel312 = db->getRelation("ref");
      refindex258 = readrel312->getIndex(ord311, false);
      std::vector<u16> ord313({1, 2, 0});
      slog::Relation* readrel314 = db->getRelation("lambda");
      lambdaindex259 = readrel314->getIndex(ord313, false);
      std::vector<u16> ord315({1, 0});
      slog::Relation* readrel316 = db->getRelation("ref");
      refindex260 = readrel316->getIndex(ord315, false);
      std::vector<u16> ord317({1, 2, 0});
      slog::Relation* readrel318 = db->getRelation("app");
      appindex261 = readrel318->getIndex(ord317, false);
      std::vector<u16> ord319({1, 0});
      slog::Relation* readrel320 = db->getRelation("ref");
      refindex262 = readrel320->getIndex(ord319, false);
      std::vector<u16> ord321({2, 0, 1});
      slog::Relation* readrel322 = db->getRelation("app");
      appindex263 = readrel322->getIndex(ord321, false);
      std::vector<u16> ord323({1, 0});
      slog::Relation* readrel324 = db->getRelation("ref");
      refindex264 = readrel324->getIndex(ord323, false);
      std::vector<u16> ord325({1, 2, 0});
      slog::Relation* readrel326 = db->getRelation("app");
      appindex265 = readrel326->getIndex(ord325, false);
      std::vector<u16> ord327({1, 2, 0});
      slog::Relation* readrel328 = db->getRelation("lambda");
      lambdaindex266 = readrel328->getIndex(ord327, false);
      std::vector<u16> ord329({1, 0});
      slog::Relation* readrel330 = db->getRelation("ref");
      refindex267 = readrel330->getIndex(ord329, false);
      std::vector<u16> ord331({1, 2, 0});
      slog::Relation* readrel332 = db->getRelation("lambda");
      lambdaindex268 = readrel332->getIndex(ord331, false);
      std::vector<u16> ord333({1, 2, 0});
      slog::Relation* readrel334 = db->getRelation("app");
      appindex269 = readrel334->getIndex(ord333, false);
      std::vector<u16> ord335({1, 0});
      slog::Relation* readrel336 = db->getRelation("ref");
      refindex270 = readrel336->getIndex(ord335, false);
      std::vector<u16> ord337({1, 2, 0});
      slog::Relation* readrel338 = db->getRelation("lambda");
      lambdaindex271 = readrel338->getIndex(ord337, false);
      std::vector<u16> ord339({1, 2, 0});
      slog::Relation* readrel340 = db->getRelation("lambda");
      lambdaindex272 = readrel340->getIndex(ord339, false);
      std::vector<u16> ord341({1, 2, 0});
      slog::Relation* readrel342 = db->getRelation("app");
      appindex273 = readrel342->getIndex(ord341, false);
      std::vector<u16> ord343({2, 0, 1});
      slog::Relation* readrel344 = db->getRelation("app");
      appindex274 = readrel344->getIndex(ord343, false);
      std::vector<u16> ord345({1, 0});
      slog::Relation* readrel346 = db->getRelation("ref");
      refindex275 = readrel346->getIndex(ord345, false);
      std::vector<u16> ord347({1, 2, 0});
      slog::Relation* readrel348 = db->getRelation("lambda");
      lambdaindex276 = readrel348->getIndex(ord347, false);
      std::vector<u16> ord349({1, 2, 0});
      slog::Relation* readrel350 = db->getRelation("app");
      appindex277 = readrel350->getIndex(ord349, false);
      std::vector<u16> ord351({1, 2, 0});
      slog::Relation* readrel352 = db->getRelation("lambda");
      lambdaindex278 = readrel352->getIndex(ord351, false);
      std::vector<u16> ord353({1, 2, 0});
      slog::Relation* readrel354 = db->getRelation("app");
      appindex279 = readrel354->getIndex(ord353, false);
  
    }
    ReadTask280(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c49 = v_const7c7d2cfc66f4d976987d2d20;
      u64 v_c50 = v_const6bc0ba365ada70df115e1785;
      u64 v_c51 = v_consta8180db1c2f300980314f910;
      u64 v_c52 = v_constd5f017533ea574d5f9b3400c;
      u64 v_c53 = v_const9a67f28c6b77e842f439a84a;
      u64 v_c54 = v_conste58dec6bca6f63ef79c3b755;
      u64 v_c55 = v_const0f8748be649f8ee4066bb1d7;
      u64 v_c56 = v_const990b444cbd47632035b2fa1a;
      u64 v_c57 = v_const4f84f41d89b6b717419b4eaa;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex244, std::array<u64,2>{v_c50, 0}, [&](const std::array<u64,2>& m355) {
        u64 v_c58 = m355[1];
        if (!slog::exists_probe<3,1>(lambdaindex245, std::array<u64,3>{v_c54, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex246, std::array<u64,2>{v_c52, 0})) return;
        if (!slog::exists_probe<2,1>(refindex247, std::array<u64,2>{v_c53, 0})) return;
        if (!slog::exists_probe<2,1>(refindex248, std::array<u64,2>{v_c49, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex249, std::array<u64,3>{v_c53, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex250, std::array<u64,2>{v_c55, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex251, std::array<u64,3>{v_c55, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex252, std::array<u64,3>{v_c58, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex253, std::array<u64,2>{v_c57, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex254, std::array<u64,3>{v_c57, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex255, std::array<u64,2>{v_c56, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex256, std::array<u64,3>{v_c56, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex257, std::array<u64,3>{v_c52, 0, 0})) return;
        slog::join_probe<2,1>(refindex258, std::array<u64,2>{v_c54, 0}, [&](const std::array<u64,2>& m356) {
          u64 v_c59 = m356[1];
          slog::join_probe<3,2>(lambdaindex259, std::array<u64,3>{v_c54, v_c59, 0}, [&](const std::array<u64,3>& m357) {
            u64 v_c60 = m357[2];
            slog::join_probe<2,1>(refindex260, std::array<u64,2>{v_c52, 0}, [&](const std::array<u64,2>& m358) {
              u64 v_c61 = m358[1];
              if (!slog::exists_probe<3,1>(appindex261, std::array<u64,3>{v_c61, 0, 0})) return;
              slog::join_probe<2,1>(refindex262, std::array<u64,2>{v_c53, 0}, [&](const std::array<u64,2>& m359) {
                u64 v_c62 = m359[1];
                if (!slog::exists_probe<3,1>(appindex263, std::array<u64,3>{v_c62, 0, 0})) return;
                slog::join_probe<2,1>(refindex264, std::array<u64,2>{v_c49, 0}, [&](const std::array<u64,2>& m360) {
                  u64 v_c63 = m360[1];
                  slog::join_probe<3,2>(appindex265, std::array<u64,3>{v_c63, v_c62, 0}, [&](const std::array<u64,3>& m361) {
                    u64 v_c64 = m361[2];
                    slog::join_probe<3,2>(lambdaindex266, std::array<u64,3>{v_c53, v_c64, 0}, [&](const std::array<u64,3>& m362) {
                      u64 v_c65 = m362[2];
                      slog::join_probe<2,1>(refindex267, std::array<u64,2>{v_c55, 0}, [&](const std::array<u64,2>& m363) {
                        u64 v_c66 = m363[1];
                        slog::join_probe<3,2>(lambdaindex268, std::array<u64,3>{v_c55, v_c66, 0}, [&](const std::array<u64,3>& m364) {
                          u64 v_c67 = m364[2];
                          slog::join_probe<3,2>(appindex269, std::array<u64,3>{v_c58, v_c67, 0}, [&](const std::array<u64,3>& m365) {
                            u64 v_c68 = m365[2];
                            slog::join_probe<2,1>(refindex270, std::array<u64,2>{v_c57, 0}, [&](const std::array<u64,2>& m366) {
                              u64 v_c69 = m366[1];
                              slog::join_probe<3,2>(lambdaindex271, std::array<u64,3>{v_c57, v_c69, 0}, [&](const std::array<u64,3>& m367) {
                                u64 v_c70 = m367[2];
                                slog::join_probe<3,2>(lambdaindex272, std::array<u64,3>{v_c55, v_c70, 0}, [&](const std::array<u64,3>& m368) {
                                  u64 v_c71 = m368[2];
                                  slog::join_probe<3,2>(appindex273, std::array<u64,3>{v_c58, v_c71, 0}, [&](const std::array<u64,3>& m369) {
                                    u64 v_c72 = m369[2];
                                    if (!slog::exists_probe<3,1>(appindex274, std::array<u64,3>{v_c72, 0, 0})) return;
                                    slog::join_probe<2,1>(refindex275, std::array<u64,2>{v_c56, 0}, [&](const std::array<u64,2>& m370) {
                                      u64 v_c73 = m370[1];
                                      slog::join_probe<3,2>(lambdaindex276, std::array<u64,3>{v_c56, v_c73, 0}, [&](const std::array<u64,3>& m371) {
                                        u64 v_c74 = m371[2];
                                        slog::join_probe<3,2>(appindex277, std::array<u64,3>{v_c61, v_c74, 0}, [&](const std::array<u64,3>& m372) {
                                          u64 v_c75 = m372[2];
                                          slog::join_probe<3,2>(lambdaindex278, std::array<u64,3>{v_c52, v_c75, 0}, [&](const std::array<u64,3>& m373) {
                                            u64 v_c76 = m373[2];
                                            slog::join_probe<3,2>(appindex279, std::array<u64,3>{v_c76, v_c72, 0}, [&](const std::array<u64,3>& m374) {
                                              u64 v_c77 = m374[2];
                                              ++_fires;
                                              slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c51, v_c77}, std::array<u16,3>{1, 2, 0});
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
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:241", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask280(db,b));
  // (crule (pre (let __tconst9zoW125 const7c7d2cfc66f4d976987d2d20) (let __tconst4V4L122 const6bc0ba365ada70df115e1785) (let __tconst82U8119 consta8180db1c2f300980314f910) (let __tconst3wDH116 constd5f017533ea574d5f9b3400c) (let __tconst4Zcr91 const9a67f28c6b77e842f439a84a) (let __tconst0vRf84 conste58dec6bca6f63ef79c3b755) (let __tconst4BKz104 const0f8748be649f8ee4066bb1d7) (let __tconst3ktF111 const990b444cbd47632035b2fa1a) (let __tconst5nWJ102 const4f84f41d89b6b717419b4eaa)) (scan app __t50Kk118 __t7CwH117 __t2Z7m108) (body (exists ref (1 0) 1 __tconst4V4L122) (exists lambda (1 2 0) 1 __tconst4BKz104) (exists lambda (1 2 0) 1 __tconst5nWJ102) (exists ref (1 0) 1 __tconst5nWJ102) (exists ref (1 0) 1 __tconst0vRf84) (exists lambda (1 2 0) 1 __tconst0vRf84) (exists ref (1 0) 1 __tconst3wDH116) (exists lambda (1 2 0) 1 __tconst3ktF111) (exists ref (1 0) 1 __tconst3ktF111) (exists ref (1 0) 1 __tconst4Zcr91) (exists ref (1 0) 1 __tconst9zoW125) (exists lambda (1 2 0) 1 __tconst4Zcr91) (exists ref (1 0) 1 __tconst4BKz104) (join lambda (0 1 2) 2 __t7CwH117 __tconst3wDH116 __t44OM115) (join ref (1 0) 1 __tconst4V4L122 __t7aew98) (exists app (1 2 0) 1 __t7aew98) (join app (0 1 2) 2 __t2Z7m108 __t7aew98 __t6RuY105) (join lambda (0 1 2) 2 __t6RuY105 __tconst4BKz104 __t35jA103) (join lambda (0 1 2) 2 __t35jA103 __tconst5nWJ102 __t5MaG101) (join ref (0 1) 2 __t5MaG101 __tconst5nWJ102) (join ref (1 0) 1 __tconst0vRf84 __t2duR83) (join lambda (1 2 0) 2 __tconst0vRf84 __t2duR83 __t87vL85) (join ref (1 0) 1 __tconst3wDH116 __t3wir114) (join app (0 1 2) 2 __t44OM115 __t3wir114 __t8GWA112) (join lambda (0 1 2) 2 __t8GWA112 __tconst3ktF111 __t7ohz110) (join ref (0 1) 2 __t7ohz110 __tconst3ktF111) (join ref (1 0) 1 __tconst4Zcr91 __t0C9F87) (exists app (2 0 1) 1 __t0C9F87) (join ref (1 0) 1 __tconst9zoW125 __t3Q2G89) (join app (1 2 0) 2 __t3Q2G89 __t0C9F87 __t2Eqd90) (join lambda (1 2 0) 2 __tconst4Zcr91 __t2Eqd90 __t3pgm92) (join ref (1 0) 1 __tconst4BKz104 __t8C0a94) (join lambda (1 2 0) 2 __tconst4BKz104 __t8C0a94 __t4fDK96) (join app (1 2 0) 2 __t7aew98 __t4fDK96 __t7TEO99)) (head (mkstruct lambda (1 2 0) __t3SEs120 __tconst82U8119 __t50Kk118)) mcfa-counting.slog:241 #f)
  class ReadTask409 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex375;  slog::Index** lambdaindex376;  slog::Index** lambdaindex377;  slog::Index** refindex378;  slog::Index** refindex379;  slog::Index** lambdaindex380;  slog::Index** refindex381;  slog::Index** lambdaindex382;  slog::Index** refindex383;  slog::Index** refindex384;  slog::Index** refindex385;  slog::Index** lambdaindex386;  slog::Index** refindex387;  slog::Index** lambdaindex388;  slog::Index** refindex389;  slog::Index** appindex390;  slog::Index** appindex391;  slog::Index** lambdaindex392;  slog::Index** lambdaindex393;  slog::Index** refindex394;  slog::Index** refindex395;  slog::Index** lambdaindex396;  slog::Index** refindex397;  slog::Index** appindex398;  slog::Index** lambdaindex399;  slog::Index** refindex400;  slog::Index** refindex401;  slog::Index** appindex402;  slog::Index** refindex403;  slog::Index** appindex404;  slog::Index** lambdaindex405;  slog::Index** refindex406;  slog::Index** lambdaindex407;  slog::Index** appindex408;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      outer_rel = db->getRelation("app");
      std::vector<u16> ord410({1, 0});
      slog::Relation* readrel411 = db->getRelation("ref");
      refindex375 = readrel411->getIndex(ord410, false);
      std::vector<u16> ord412({1, 2, 0});
      slog::Relation* readrel413 = db->getRelation("lambda");
      lambdaindex376 = readrel413->getIndex(ord412, false);
      std::vector<u16> ord414({1, 2, 0});
      slog::Relation* readrel415 = db->getRelation("lambda");
      lambdaindex377 = readrel415->getIndex(ord414, false);
      std::vector<u16> ord416({1, 0});
      slog::Relation* readrel417 = db->getRelation("ref");
      refindex378 = readrel417->getIndex(ord416, false);
      std::vector<u16> ord418({1, 0});
      slog::Relation* readrel419 = db->getRelation("ref");
      refindex379 = readrel419->getIndex(ord418, false);
      std::vector<u16> ord420({1, 2, 0});
      slog::Relation* readrel421 = db->getRelation("lambda");
      lambdaindex380 = readrel421->getIndex(ord420, false);
      std::vector<u16> ord422({1, 0});
      slog::Relation* readrel423 = db->getRelation("ref");
      refindex381 = readrel423->getIndex(ord422, false);
      std::vector<u16> ord424({1, 2, 0});
      slog::Relation* readrel425 = db->getRelation("lambda");
      lambdaindex382 = readrel425->getIndex(ord424, false);
      std::vector<u16> ord426({1, 0});
      slog::Relation* readrel427 = db->getRelation("ref");
      refindex383 = readrel427->getIndex(ord426, false);
      std::vector<u16> ord428({1, 0});
      slog::Relation* readrel429 = db->getRelation("ref");
      refindex384 = readrel429->getIndex(ord428, false);
      std::vector<u16> ord430({1, 0});
      slog::Relation* readrel431 = db->getRelation("ref");
      refindex385 = readrel431->getIndex(ord430, false);
      std::vector<u16> ord432({1, 2, 0});
      slog::Relation* readrel433 = db->getRelation("lambda");
      lambdaindex386 = readrel433->getIndex(ord432, false);
      std::vector<u16> ord434({1, 0});
      slog::Relation* readrel435 = db->getRelation("ref");
      refindex387 = readrel435->getIndex(ord434, false);
      std::vector<u16> ord436({0, 1, 2});
      slog::Relation* readrel437 = db->getRelation("lambda");
      lambdaindex388 = readrel437->getIndex(ord436, false);
      std::vector<u16> ord438({1, 0});
      slog::Relation* readrel439 = db->getRelation("ref");
      refindex389 = readrel439->getIndex(ord438, false);
      std::vector<u16> ord440({1, 2, 0});
      slog::Relation* readrel441 = db->getRelation("app");
      appindex390 = readrel441->getIndex(ord440, false);
      std::vector<u16> ord442({0, 1, 2});
      slog::Relation* readrel443 = db->getRelation("app");
      appindex391 = readrel443->getIndex(ord442, false);
      std::vector<u16> ord444({0, 1, 2});
      slog::Relation* readrel445 = db->getRelation("lambda");
      lambdaindex392 = readrel445->getIndex(ord444, false);
      std::vector<u16> ord446({0, 1, 2});
      slog::Relation* readrel447 = db->getRelation("lambda");
      lambdaindex393 = readrel447->getIndex(ord446, false);
      std::vector<u16> ord448({0, 1});
      slog::Relation* readrel449 = db->getRelation("ref");
      refindex394 = readrel449->getIndex(ord448, false);
      std::vector<u16> ord450({1, 0});
      slog::Relation* readrel451 = db->getRelation("ref");
      refindex395 = readrel451->getIndex(ord450, false);
      std::vector<u16> ord452({1, 2, 0});
      slog::Relation* readrel453 = db->getRelation("lambda");
      lambdaindex396 = readrel453->getIndex(ord452, false);
      std::vector<u16> ord454({1, 0});
      slog::Relation* readrel455 = db->getRelation("ref");
      refindex397 = readrel455->getIndex(ord454, false);
      std::vector<u16> ord456({0, 1, 2});
      slog::Relation* readrel457 = db->getRelation("app");
      appindex398 = readrel457->getIndex(ord456, false);
      std::vector<u16> ord458({0, 1, 2});
      slog::Relation* readrel459 = db->getRelation("lambda");
      lambdaindex399 = readrel459->getIndex(ord458, false);
      std::vector<u16> ord460({0, 1});
      slog::Relation* readrel461 = db->getRelation("ref");
      refindex400 = readrel461->getIndex(ord460, false);
      std::vector<u16> ord462({1, 0});
      slog::Relation* readrel463 = db->getRelation("ref");
      refindex401 = readrel463->getIndex(ord462, false);
      std::vector<u16> ord464({2, 0, 1});
      slog::Relation* readrel465 = db->getRelation("app");
      appindex402 = readrel465->getIndex(ord464, false);
      std::vector<u16> ord466({1, 0});
      slog::Relation* readrel467 = db->getRelation("ref");
      refindex403 = readrel467->getIndex(ord466, false);
      std::vector<u16> ord468({1, 2, 0});
      slog::Relation* readrel469 = db->getRelation("app");
      appindex404 = readrel469->getIndex(ord468, false);
      std::vector<u16> ord470({1, 2, 0});
      slog::Relation* readrel471 = db->getRelation("lambda");
      lambdaindex405 = readrel471->getIndex(ord470, false);
      std::vector<u16> ord472({1, 0});
      slog::Relation* readrel473 = db->getRelation("ref");
      refindex406 = readrel473->getIndex(ord472, false);
      std::vector<u16> ord474({1, 2, 0});
      slog::Relation* readrel475 = db->getRelation("lambda");
      lambdaindex407 = readrel475->getIndex(ord474, false);
      std::vector<u16> ord476({1, 2, 0});
      slog::Relation* readrel477 = db->getRelation("app");
      appindex408 = readrel477->getIndex(ord476, false);
  
    }
    ReadTask409(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c49 = v_const7c7d2cfc66f4d976987d2d20;
      u64 v_c50 = v_const6bc0ba365ada70df115e1785;
      u64 v_c51 = v_consta8180db1c2f300980314f910;
      u64 v_c52 = v_constd5f017533ea574d5f9b3400c;
      u64 v_c53 = v_const9a67f28c6b77e842f439a84a;
      u64 v_c54 = v_conste58dec6bca6f63ef79c3b755;
      u64 v_c55 = v_const0f8748be649f8ee4066bb1d7;
      u64 v_c56 = v_const990b444cbd47632035b2fa1a;
      u64 v_c57 = v_const4f84f41d89b6b717419b4eaa;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c77 = _t[0];
        u64 v_c76 = _t[1];
        u64 v_c72 = _t[2];
        if (!slog::exists_probe<2,1>(refindex375, std::array<u64,2>{v_c50, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex376, std::array<u64,3>{v_c55, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex377, std::array<u64,3>{v_c57, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex378, std::array<u64,2>{v_c57, 0})) return;
        if (!slog::exists_probe<2,1>(refindex379, std::array<u64,2>{v_c54, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex380, std::array<u64,3>{v_c54, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex381, std::array<u64,2>{v_c52, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex382, std::array<u64,3>{v_c56, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex383, std::array<u64,2>{v_c56, 0})) return;
        if (!slog::exists_probe<2,1>(refindex384, std::array<u64,2>{v_c53, 0})) return;
        if (!slog::exists_probe<2,1>(refindex385, std::array<u64,2>{v_c49, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex386, std::array<u64,3>{v_c53, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex387, std::array<u64,2>{v_c55, 0})) return;
        slog::join_probe<3,2>(lambdaindex388, std::array<u64,3>{v_c76, v_c52, 0}, [&](const std::array<u64,3>& m478) {
          u64 v_c75 = m478[2];
          slog::join_probe<2,1>(refindex389, std::array<u64,2>{v_c50, 0}, [&](const std::array<u64,2>& m479) {
            u64 v_c58 = m479[1];
            if (!slog::exists_probe<3,1>(appindex390, std::array<u64,3>{v_c58, 0, 0})) return;
            slog::join_probe<3,2>(appindex391, std::array<u64,3>{v_c72, v_c58, 0}, [&](const std::array<u64,3>& m480) {
              u64 v_c71 = m480[2];
              slog::join_probe<3,2>(lambdaindex392, std::array<u64,3>{v_c71, v_c55, 0}, [&](const std::array<u64,3>& m481) {
                u64 v_c70 = m481[2];
                slog::join_probe<3,2>(lambdaindex393, std::array<u64,3>{v_c70, v_c57, 0}, [&](const std::array<u64,3>& m482) {
                  u64 v_c69 = m482[2];
                  slog::join_probe<2,2>(refindex394, std::array<u64,2>{v_c69, v_c57}, [&](const std::array<u64,2>& m483) {
                    slog::join_probe<2,1>(refindex395, std::array<u64,2>{v_c54, 0}, [&](const std::array<u64,2>& m484) {
                      u64 v_c59 = m484[1];
                      slog::join_probe<3,2>(lambdaindex396, std::array<u64,3>{v_c54, v_c59, 0}, [&](const std::array<u64,3>& m485) {
                        u64 v_c60 = m485[2];
                        slog::join_probe<2,1>(refindex397, std::array<u64,2>{v_c52, 0}, [&](const std::array<u64,2>& m486) {
                          u64 v_c61 = m486[1];
                          slog::join_probe<3,2>(appindex398, std::array<u64,3>{v_c75, v_c61, 0}, [&](const std::array<u64,3>& m487) {
                            u64 v_c74 = m487[2];
                            slog::join_probe<3,2>(lambdaindex399, std::array<u64,3>{v_c74, v_c56, 0}, [&](const std::array<u64,3>& m488) {
                              u64 v_c73 = m488[2];
                              slog::join_probe<2,2>(refindex400, std::array<u64,2>{v_c73, v_c56}, [&](const std::array<u64,2>& m489) {
                                slog::join_probe<2,1>(refindex401, std::array<u64,2>{v_c53, 0}, [&](const std::array<u64,2>& m490) {
                                  u64 v_c62 = m490[1];
                                  if (!slog::exists_probe<3,1>(appindex402, std::array<u64,3>{v_c62, 0, 0})) return;
                                  slog::join_probe<2,1>(refindex403, std::array<u64,2>{v_c49, 0}, [&](const std::array<u64,2>& m491) {
                                    u64 v_c63 = m491[1];
                                    slog::join_probe<3,2>(appindex404, std::array<u64,3>{v_c63, v_c62, 0}, [&](const std::array<u64,3>& m492) {
                                      u64 v_c64 = m492[2];
                                      slog::join_probe<3,2>(lambdaindex405, std::array<u64,3>{v_c53, v_c64, 0}, [&](const std::array<u64,3>& m493) {
                                        u64 v_c65 = m493[2];
                                        slog::join_probe<2,1>(refindex406, std::array<u64,2>{v_c55, 0}, [&](const std::array<u64,2>& m494) {
                                          u64 v_c66 = m494[1];
                                          slog::join_probe<3,2>(lambdaindex407, std::array<u64,3>{v_c55, v_c66, 0}, [&](const std::array<u64,3>& m495) {
                                            u64 v_c67 = m495[2];
                                            slog::join_probe<3,2>(appindex408, std::array<u64,3>{v_c58, v_c67, 0}, [&](const std::array<u64,3>& m496) {
                                              u64 v_c68 = m496[2];
                                              ++_fires;
                                              slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c51, v_c77}, std::array<u16,3>{1, 2, 0});
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
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:241", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask409* _cont = new ReadTask409(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask409(db,b), false);
  // (crule (pre (let __tconst7JVW192 const6cf13cc59dcbe759113f68a4) (let __tconst7B9N190 constcaa3ee5a2828a31924f6b39d) (let __tconst5wC2180 const970c20ea81b833e5b5a7accf) (let __tconst2ady176 constc40f204dda7ba4054abb9e74)) (seeded) (body (join ref (1 0) 1 __tconst2ady176 __t3ZY4175) (exists ref (1 0) 1 __tconst7B9N190) (exists ref (1 0) 1 __tconst7JVW192) (join ref (1 0) 1 __tconst5wC2180 __t52sB179) (join ref (1 0) 1 __tconst7B9N190 __t8oRJ183) (join ref (1 0) 1 __tconst7JVW192 __t6fOY185)) (head (mkstruct app (1 2 0) __t2CTd186 __t6fOY185 __t8oRJ183) (mkstruct lambda (1 2 0) __t6CST181 __tconst5wC2180 __t52sB179) (mkstruct lambda (1 2 0) __t1Ls4177 __tconst2ady176 __t3ZY4175)) mcfa-counting.slog:301 #f)
  class ReadTask503 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
  
  
  
  
  
  
    slog::Index** refindex497;  slog::Index** refindex498;  slog::Index** refindex499;  slog::Index** refindex500;  slog::Index** refindex501;  slog::Index** refindex502;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord504({1, 2, 0});
      slog::Relation* readrel505 = db->getRelation("app");
      head_index[0] = readrel505->getIndex(ord504, false);
      head_rel[1] = db->getRelation("lambda");
      std::vector<u16> ord506({1, 2, 0});
      slog::Relation* readrel507 = db->getRelation("lambda");
      head_index[1] = readrel507->getIndex(ord506, false);
      head_rel[2] = db->getRelation("lambda");
      std::vector<u16> ord508({1, 2, 0});
      slog::Relation* readrel509 = db->getRelation("lambda");
      head_index[2] = readrel509->getIndex(ord508, false);
      std::vector<u16> ord510({1, 0});
      slog::Relation* readrel511 = db->getRelation("ref");
      refindex497 = readrel511->getIndex(ord510, false);
      std::vector<u16> ord512({1, 0});
      slog::Relation* readrel513 = db->getRelation("ref");
      refindex498 = readrel513->getIndex(ord512, false);
      std::vector<u16> ord514({1, 0});
      slog::Relation* readrel515 = db->getRelation("ref");
      refindex499 = readrel515->getIndex(ord514, false);
      std::vector<u16> ord516({1, 0});
      slog::Relation* readrel517 = db->getRelation("ref");
      refindex500 = readrel517->getIndex(ord516, false);
      std::vector<u16> ord518({1, 0});
      slog::Relation* readrel519 = db->getRelation("ref");
      refindex501 = readrel519->getIndex(ord518, false);
      std::vector<u16> ord520({1, 0});
      slog::Relation* readrel521 = db->getRelation("ref");
      refindex502 = readrel521->getIndex(ord520, false);
  
    }
    ReadTask503(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const6cf13cc59dcbe759113f68a4;
      u64 v_c1 = v_constcaa3ee5a2828a31924f6b39d;
      u64 v_c2 = v_const970c20ea81b833e5b5a7accf;
      u64 v_c3 = v_constc40f204dda7ba4054abb9e74;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex497, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m522) {
        u64 v_c5 = m522[1];
        if (!slog::exists_probe<2,1>(refindex498, std::array<u64,2>{v_c1, 0})) return;
        if (!slog::exists_probe<2,1>(refindex499, std::array<u64,2>{v_c0, 0})) return;
        slog::join_probe<2,1>(refindex500, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m523) {
          u64 v_c7 = m523[1];
          slog::join_probe<2,1>(refindex501, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m524) {
            u64 v_c9 = m524[1];
            slog::join_probe<2,1>(refindex502, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m525) {
              u64 v_c4 = m525[1];
              ++_fires;
              slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c4, v_c9}, std::array<u16,3>{1, 2, 0});
              slog::emit_struct_checked<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c2, v_c7}, std::array<u16,3>{1, 2, 0});
              slog::emit_struct_checked<3>(head_rel[2], head_index[2], newbatch[2], std::array<u64,2>{v_c3, v_c5}, std::array<u16,3>{1, 2, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:301", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask503(db,b));
  // (crule (pre (let __tconst4Xaz41 const81cb39a72a584ab4f703b7f7) (let __tconst1aIN38 const4d5ce1398140fbe27561181f) (let __tconst1ha033 const969c6e56242ce8d0a4346602) (let __tconst37GM26 const85f09fa1913b9daf65957cf7) (let __tconst4xzG22 constdbf1bdba02122b2adce28528) (let __tconst1HMF17 constd7a1925d249b4768c8a9f2d8)) (probe ref (1 0) 1 __tconst1HMF17 __t7H1u16) (body (exists ref (1 0) 1 __tconst37GM26) (exists ref (1 0) 1 __tconst4Xaz41) (exists ref (1 0) 1 __tconst1ha033) (join ref (1 0) 1 __tconst4xzG22 __t2DOE20) (join ref (1 0) 1 __tconst37GM26 __t7U1m25) (join ref (1 0) 1 __tconst4Xaz41 __t75SZ29) (join ref (1 0) 1 __tconst1ha033 __t7N9A32)) (head (mkstruct lambda (1 2 0) __t065j34 __tconst1ha033 __t7N9A32) (mkstruct lambda (1 2 0) __t5myE27 __tconst37GM26 __t7U1m25) (mkstruct lambda (1 2 0) __t2wNc18 __tconst1HMF17 __t7H1u16)) mcfa-counting.slog:260 #f)
  class ReadTask533 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** refindex526;  slog::Index** refindex527;  slog::Index** refindex528;  slog::Index** refindex529;  slog::Index** refindex530;  slog::Index** refindex531;  slog::Index** refindex532;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      head_rel[1] = db->getRelation("lambda");
      head_rel[2] = db->getRelation("lambda");
      std::vector<u16> ord534({1, 0});
      slog::Relation* readrel535 = db->getRelation("ref");
      driver_index = readrel535->getIndex(ord534, true);
      std::vector<u16> ord536({1, 0});
      slog::Relation* readrel537 = db->getRelation("ref");
      refindex526 = readrel537->getIndex(ord536, false);
      std::vector<u16> ord538({1, 0});
      slog::Relation* readrel539 = db->getRelation("ref");
      refindex527 = readrel539->getIndex(ord538, false);
      std::vector<u16> ord540({1, 0});
      slog::Relation* readrel541 = db->getRelation("ref");
      refindex528 = readrel541->getIndex(ord540, false);
      std::vector<u16> ord542({1, 0});
      slog::Relation* readrel543 = db->getRelation("ref");
      refindex529 = readrel543->getIndex(ord542, false);
      std::vector<u16> ord544({1, 0});
      slog::Relation* readrel545 = db->getRelation("ref");
      refindex530 = readrel545->getIndex(ord544, false);
      std::vector<u16> ord546({1, 0});
      slog::Relation* readrel547 = db->getRelation("ref");
      refindex531 = readrel547->getIndex(ord546, false);
      std::vector<u16> ord548({1, 0});
      slog::Relation* readrel549 = db->getRelation("ref");
      refindex532 = readrel549->getIndex(ord548, false);
  
    }
    ReadTask533(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c27 = v_const81cb39a72a584ab4f703b7f7;
      u64 v_c29 = v_const4d5ce1398140fbe27561181f;
      u64 v_c32 = v_const969c6e56242ce8d0a4346602;
      u64 v_c31 = v_const85f09fa1913b9daf65957cf7;
      u64 v_c28 = v_constdbf1bdba02122b2adce28528;
      u64 v_c30 = v_constd7a1925d249b4768c8a9f2d8;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c30, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m550) {
        u64 v_c40 = m550[1];
        if (buckethash(v_c40) != bucket) return;
        if (!slog::exists_probe<2,1>(refindex526, std::array<u64,2>{v_c31, 0})) return;
        if (!slog::exists_probe<2,1>(refindex527, std::array<u64,2>{v_c27, 0})) return;
        if (!slog::exists_probe<2,1>(refindex528, std::array<u64,2>{v_c32, 0})) return;
        slog::join_probe<2,1>(refindex529, std::array<u64,2>{v_c28, 0}, [&](const std::array<u64,2>& m551) {
          u64 v_c38 = m551[1];
          slog::join_probe<2,1>(refindex530, std::array<u64,2>{v_c31, 0}, [&](const std::array<u64,2>& m552) {
            u64 v_c42 = m552[1];
            slog::join_probe<2,1>(refindex531, std::array<u64,2>{v_c27, 0}, [&](const std::array<u64,2>& m553) {
              u64 v_c41 = m553[1];
              slog::join_probe<2,1>(refindex532, std::array<u64,2>{v_c32, 0}, [&](const std::array<u64,2>& m554) {
                u64 v_c48 = m554[1];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c32, v_c48}, std::array<u16,3>{1, 2, 0});
                slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c31, v_c42}, std::array<u16,3>{1, 2, 0});
                slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c30, v_c40}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:260", "delta:ref", _fires);
  
      if (!_done)
      {
        ReadTask533* _cont = new ReadTask533(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask533(db,b), false);
  // (crule (pre (let __tconst4she277 const50a95ec20b9767e468d04917) (let __tconst0ZLv270 constf0a25c0401304c51b5ee9c5e)) (seeded) (body (join ref (1 0) 1 __tconst0ZLv270 __t9L3S266) (exists app (1 2 0) 1 __t9L3S266) (exists lambda (1 2 0) 1 __tconst0ZLv270) (exists lambda (1 2 0) 1 __tconst4she277) (join ref (1 0) 1 __tconst4she277 __t28CO273) (exists app (1 2 0) 1 __t28CO273) (join app (1 2 0) 1 __t9L3S266 dup0ug7447 __t8kx2269) (eq __t9L3S266 dup0ug7447) (join lambda (1 2 0) 2 __tconst0ZLv270 __t8kx2269 __t3oIn271) (exists app (2 0 1) 1 __t3oIn271) (join app (1 2 0) 1 __t28CO273 dup8OjW448 __t6FnS276) (eq __t28CO273 dup8OjW448) (join lambda (1 2 0) 2 __tconst4she277 __t6FnS276 __t6zNR278) (join app (1 2 0) 2 __t6zNR278 __t3oIn271 __t4C0a279)) (head (emit program (0) __t4C0a279)) mcfa-counting.slog:183 #f)
  class ReadTask567 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex555;  slog::Index** appindex556;  slog::Index** lambdaindex557;  slog::Index** lambdaindex558;  slog::Index** refindex559;  slog::Index** appindex560;  slog::Index** appindex561;  slog::Index** lambdaindex562;  slog::Index** appindex563;  slog::Index** appindex564;  slog::Index** lambdaindex565;  slog::Index** appindex566;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("program");
      std::vector<u16> ord568({0});
      slog::Relation* readrel569 = db->getRelation("program");
      head_index[0] = readrel569->getIndex(ord568, false);
      std::vector<u16> ord570({1, 0});
      slog::Relation* readrel571 = db->getRelation("ref");
      refindex555 = readrel571->getIndex(ord570, false);
      std::vector<u16> ord572({1, 2, 0});
      slog::Relation* readrel573 = db->getRelation("app");
      appindex556 = readrel573->getIndex(ord572, false);
      std::vector<u16> ord574({1, 2, 0});
      slog::Relation* readrel575 = db->getRelation("lambda");
      lambdaindex557 = readrel575->getIndex(ord574, false);
      std::vector<u16> ord576({1, 2, 0});
      slog::Relation* readrel577 = db->getRelation("lambda");
      lambdaindex558 = readrel577->getIndex(ord576, false);
      std::vector<u16> ord578({1, 0});
      slog::Relation* readrel579 = db->getRelation("ref");
      refindex559 = readrel579->getIndex(ord578, false);
      std::vector<u16> ord580({1, 2, 0});
      slog::Relation* readrel581 = db->getRelation("app");
      appindex560 = readrel581->getIndex(ord580, false);
      std::vector<u16> ord582({1, 2, 0});
      slog::Relation* readrel583 = db->getRelation("app");
      appindex561 = readrel583->getIndex(ord582, false);
      std::vector<u16> ord584({1, 2, 0});
      slog::Relation* readrel585 = db->getRelation("lambda");
      lambdaindex562 = readrel585->getIndex(ord584, false);
      std::vector<u16> ord586({2, 0, 1});
      slog::Relation* readrel587 = db->getRelation("app");
      appindex563 = readrel587->getIndex(ord586, false);
      std::vector<u16> ord588({1, 2, 0});
      slog::Relation* readrel589 = db->getRelation("app");
      appindex564 = readrel589->getIndex(ord588, false);
      std::vector<u16> ord590({1, 2, 0});
      slog::Relation* readrel591 = db->getRelation("lambda");
      lambdaindex565 = readrel591->getIndex(ord590, false);
      std::vector<u16> ord592({1, 2, 0});
      slog::Relation* readrel593 = db->getRelation("app");
      appindex566 = readrel593->getIndex(ord592, false);
  
    }
    ReadTask567(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c78 = v_const50a95ec20b9767e468d04917;
      u64 v_c79 = v_constf0a25c0401304c51b5ee9c5e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex555, std::array<u64,2>{v_c79, 0}, [&](const std::array<u64,2>& m594) {
        u64 v_c80 = m594[1];
        if (!slog::exists_probe<3,1>(appindex556, std::array<u64,3>{v_c80, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex557, std::array<u64,3>{v_c79, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex558, std::array<u64,3>{v_c78, 0, 0})) return;
        slog::join_probe<2,1>(refindex559, std::array<u64,2>{v_c78, 0}, [&](const std::array<u64,2>& m595) {
          u64 v_c81 = m595[1];
          if (!slog::exists_probe<3,1>(appindex560, std::array<u64,3>{v_c81, 0, 0})) return;
          slog::join_probe<3,1>(appindex561, std::array<u64,3>{v_c80, 0, 0}, [&](const std::array<u64,3>& m596) {
            u64 v_c82 = m596[1]; u64 v_c83 = m596[2];
            if (v_c80 != v_c82) return;
            slog::join_probe<3,2>(lambdaindex562, std::array<u64,3>{v_c79, v_c83, 0}, [&](const std::array<u64,3>& m597) {
              u64 v_c84 = m597[2];
              if (!slog::exists_probe<3,1>(appindex563, std::array<u64,3>{v_c84, 0, 0})) return;
              slog::join_probe<3,1>(appindex564, std::array<u64,3>{v_c81, 0, 0}, [&](const std::array<u64,3>& m598) {
                u64 v_c85 = m598[1]; u64 v_c86 = m598[2];
                if (v_c81 != v_c85) return;
                slog::join_probe<3,2>(lambdaindex565, std::array<u64,3>{v_c78, v_c86, 0}, [&](const std::array<u64,3>& m599) {
                  u64 v_c87 = m599[2];
                  slog::join_probe<3,2>(appindex566, std::array<u64,3>{v_c87, v_c84, 0}, [&](const std::array<u64,3>& m600) {
                    u64 v_c88 = m600[2];
                    ++_fires;
                    slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c88}, std::array<u16,1>{0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:183", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask567(db,b));
  // (crule (pre (let __tconst1pJW313 constb49bea2fcccd8f4301a347ed) (let __tconst2Yzp284 const8ca682693a0738a0641c6956) (let __tconst7LWP310 const66518c0c1b3a5a0b09ae2ef1) (let __tconst5PoN291 constc85eae03730a4f4cf1d66a0c) (let __tconst0sqO307 const4a8acfc71441e0695ffcf5b3) (let __tconst9rZO295 const576506f61f53440f1edd95d2) (let __tconst2CSv302 const229c0b7aa8a7eb4055f5a3d0)) (seeded) (body (join ref (1 0) 1 __tconst2Yzp284 __t248W283) (exists ref (1 0) 1 __tconst1pJW313) (exists ref (1 0) 1 __tconst7LWP310) (exists ref (1 0) 1 __tconst9rZO295) (exists lambda (1 2 0) 1 __tconst9rZO295) (exists ref (1 0) 1 __tconst2CSv302) (exists lambda (1 2 0) 1 __tconst2CSv302) (exists lambda (1 2 0) 1 __tconst0sqO307) (exists lambda (1 2 0) 1 __tconst7LWP310) (exists lambda (1 2 0) 1 __tconst5PoN291) (exists lambda (1 2 0) 1 __tconst1pJW313) (join lambda (1 2 0) 2 __tconst2Yzp284 __t248W283 __t0oFu285) (exists app (2 0 1) 1 __t0oFu285) (join ref (1 0) 1 __tconst1pJW313 __t165O287) (exists app (1 2 0) 1 __t165O287) (join ref (1 0) 1 __tconst7LWP310 __t91H2298) (exists app (1 2 0) 1 __t91H2298) (join ref (1 0) 1 __tconst9rZO295 __t71w7294) (join lambda (1 2 0) 2 __tconst9rZO295 __t71w7294 __t3dkk296) (join app (1 2 0) 2 __t91H2298 __t3dkk296 __t4LtH299) (exists app (2 0 1) 1 __t4LtH299) (join ref (1 0) 1 __tconst2CSv302 __t6lXa301) (join lambda (1 2 0) 2 __tconst2CSv302 __t6lXa301 __t7EW2303) (join app (1 2 0) 2 __t91H2298 __t7EW2303 __t4HUX306) (join lambda (1 2 0) 2 __tconst0sqO307 __t4HUX306 __t0vn1308) (join app (1 2 0) 2 __t0vn1308 __t4LtH299 __t6t9L309) (join lambda (1 2 0) 2 __tconst7LWP310 __t6t9L309 __t5T0g311) (exists app (1 2 0) 1 __t5T0g311) (join app (1 2 0) 1 __t165O287 dup8U5A390 __t30Ec290) (eq __t165O287 dup8U5A390) (join lambda (1 2 0) 2 __tconst5PoN291 __t30Ec290 __t7aCZ292) (join app (1 2 0) 2 __t5T0g311 __t7aCZ292 __t3Izn312) (join lambda (1 2 0) 2 __tconst1pJW313 __t3Izn312 __t7Qbz314) (join app (1 2 0) 2 __t7Qbz314 __t0oFu285 __t1Lkt315)) (head (emit program (0) __t1Lkt315)) mcfa-counting.slog:194 #f)
  class ReadTask634 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex601;  slog::Index** refindex602;  slog::Index** refindex603;  slog::Index** refindex604;  slog::Index** lambdaindex605;  slog::Index** refindex606;  slog::Index** lambdaindex607;  slog::Index** lambdaindex608;  slog::Index** lambdaindex609;  slog::Index** lambdaindex610;  slog::Index** lambdaindex611;  slog::Index** lambdaindex612;  slog::Index** appindex613;  slog::Index** refindex614;  slog::Index** appindex615;  slog::Index** refindex616;  slog::Index** appindex617;  slog::Index** refindex618;  slog::Index** lambdaindex619;  slog::Index** appindex620;  slog::Index** appindex621;  slog::Index** refindex622;  slog::Index** lambdaindex623;  slog::Index** appindex624;  slog::Index** lambdaindex625;  slog::Index** appindex626;  slog::Index** lambdaindex627;  slog::Index** appindex628;  slog::Index** appindex629;  slog::Index** lambdaindex630;  slog::Index** appindex631;  slog::Index** lambdaindex632;  slog::Index** appindex633;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("program");
      std::vector<u16> ord635({0});
      slog::Relation* readrel636 = db->getRelation("program");
      head_index[0] = readrel636->getIndex(ord635, false);
      std::vector<u16> ord637({1, 0});
      slog::Relation* readrel638 = db->getRelation("ref");
      refindex601 = readrel638->getIndex(ord637, false);
      std::vector<u16> ord639({1, 0});
      slog::Relation* readrel640 = db->getRelation("ref");
      refindex602 = readrel640->getIndex(ord639, false);
      std::vector<u16> ord641({1, 0});
      slog::Relation* readrel642 = db->getRelation("ref");
      refindex603 = readrel642->getIndex(ord641, false);
      std::vector<u16> ord643({1, 0});
      slog::Relation* readrel644 = db->getRelation("ref");
      refindex604 = readrel644->getIndex(ord643, false);
      std::vector<u16> ord645({1, 2, 0});
      slog::Relation* readrel646 = db->getRelation("lambda");
      lambdaindex605 = readrel646->getIndex(ord645, false);
      std::vector<u16> ord647({1, 0});
      slog::Relation* readrel648 = db->getRelation("ref");
      refindex606 = readrel648->getIndex(ord647, false);
      std::vector<u16> ord649({1, 2, 0});
      slog::Relation* readrel650 = db->getRelation("lambda");
      lambdaindex607 = readrel650->getIndex(ord649, false);
      std::vector<u16> ord651({1, 2, 0});
      slog::Relation* readrel652 = db->getRelation("lambda");
      lambdaindex608 = readrel652->getIndex(ord651, false);
      std::vector<u16> ord653({1, 2, 0});
      slog::Relation* readrel654 = db->getRelation("lambda");
      lambdaindex609 = readrel654->getIndex(ord653, false);
      std::vector<u16> ord655({1, 2, 0});
      slog::Relation* readrel656 = db->getRelation("lambda");
      lambdaindex610 = readrel656->getIndex(ord655, false);
      std::vector<u16> ord657({1, 2, 0});
      slog::Relation* readrel658 = db->getRelation("lambda");
      lambdaindex611 = readrel658->getIndex(ord657, false);
      std::vector<u16> ord659({1, 2, 0});
      slog::Relation* readrel660 = db->getRelation("lambda");
      lambdaindex612 = readrel660->getIndex(ord659, false);
      std::vector<u16> ord661({2, 0, 1});
      slog::Relation* readrel662 = db->getRelation("app");
      appindex613 = readrel662->getIndex(ord661, false);
      std::vector<u16> ord663({1, 0});
      slog::Relation* readrel664 = db->getRelation("ref");
      refindex614 = readrel664->getIndex(ord663, false);
      std::vector<u16> ord665({1, 2, 0});
      slog::Relation* readrel666 = db->getRelation("app");
      appindex615 = readrel666->getIndex(ord665, false);
      std::vector<u16> ord667({1, 0});
      slog::Relation* readrel668 = db->getRelation("ref");
      refindex616 = readrel668->getIndex(ord667, false);
      std::vector<u16> ord669({1, 2, 0});
      slog::Relation* readrel670 = db->getRelation("app");
      appindex617 = readrel670->getIndex(ord669, false);
      std::vector<u16> ord671({1, 0});
      slog::Relation* readrel672 = db->getRelation("ref");
      refindex618 = readrel672->getIndex(ord671, false);
      std::vector<u16> ord673({1, 2, 0});
      slog::Relation* readrel674 = db->getRelation("lambda");
      lambdaindex619 = readrel674->getIndex(ord673, false);
      std::vector<u16> ord675({1, 2, 0});
      slog::Relation* readrel676 = db->getRelation("app");
      appindex620 = readrel676->getIndex(ord675, false);
      std::vector<u16> ord677({2, 0, 1});
      slog::Relation* readrel678 = db->getRelation("app");
      appindex621 = readrel678->getIndex(ord677, false);
      std::vector<u16> ord679({1, 0});
      slog::Relation* readrel680 = db->getRelation("ref");
      refindex622 = readrel680->getIndex(ord679, false);
      std::vector<u16> ord681({1, 2, 0});
      slog::Relation* readrel682 = db->getRelation("lambda");
      lambdaindex623 = readrel682->getIndex(ord681, false);
      std::vector<u16> ord683({1, 2, 0});
      slog::Relation* readrel684 = db->getRelation("app");
      appindex624 = readrel684->getIndex(ord683, false);
      std::vector<u16> ord685({1, 2, 0});
      slog::Relation* readrel686 = db->getRelation("lambda");
      lambdaindex625 = readrel686->getIndex(ord685, false);
      std::vector<u16> ord687({1, 2, 0});
      slog::Relation* readrel688 = db->getRelation("app");
      appindex626 = readrel688->getIndex(ord687, false);
      std::vector<u16> ord689({1, 2, 0});
      slog::Relation* readrel690 = db->getRelation("lambda");
      lambdaindex627 = readrel690->getIndex(ord689, false);
      std::vector<u16> ord691({1, 2, 0});
      slog::Relation* readrel692 = db->getRelation("app");
      appindex628 = readrel692->getIndex(ord691, false);
      std::vector<u16> ord693({1, 2, 0});
      slog::Relation* readrel694 = db->getRelation("app");
      appindex629 = readrel694->getIndex(ord693, false);
      std::vector<u16> ord695({1, 2, 0});
      slog::Relation* readrel696 = db->getRelation("lambda");
      lambdaindex630 = readrel696->getIndex(ord695, false);
      std::vector<u16> ord697({1, 2, 0});
      slog::Relation* readrel698 = db->getRelation("app");
      appindex631 = readrel698->getIndex(ord697, false);
      std::vector<u16> ord699({1, 2, 0});
      slog::Relation* readrel700 = db->getRelation("lambda");
      lambdaindex632 = readrel700->getIndex(ord699, false);
      std::vector<u16> ord701({1, 2, 0});
      slog::Relation* readrel702 = db->getRelation("app");
      appindex633 = readrel702->getIndex(ord701, false);
  
    }
    ReadTask634(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c89 = v_constb49bea2fcccd8f4301a347ed;
      u64 v_c90 = v_const8ca682693a0738a0641c6956;
      u64 v_c91 = v_const66518c0c1b3a5a0b09ae2ef1;
      u64 v_c92 = v_constc85eae03730a4f4cf1d66a0c;
      u64 v_c93 = v_const4a8acfc71441e0695ffcf5b3;
      u64 v_c94 = v_const576506f61f53440f1edd95d2;
      u64 v_c95 = v_const229c0b7aa8a7eb4055f5a3d0;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex601, std::array<u64,2>{v_c90, 0}, [&](const std::array<u64,2>& m703) {
        u64 v_c96 = m703[1];
        if (!slog::exists_probe<2,1>(refindex602, std::array<u64,2>{v_c89, 0})) return;
        if (!slog::exists_probe<2,1>(refindex603, std::array<u64,2>{v_c91, 0})) return;
        if (!slog::exists_probe<2,1>(refindex604, std::array<u64,2>{v_c94, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex605, std::array<u64,3>{v_c94, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex606, std::array<u64,2>{v_c95, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex607, std::array<u64,3>{v_c95, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex608, std::array<u64,3>{v_c93, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex609, std::array<u64,3>{v_c91, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex610, std::array<u64,3>{v_c92, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex611, std::array<u64,3>{v_c89, 0, 0})) return;
        slog::join_probe<3,2>(lambdaindex612, std::array<u64,3>{v_c90, v_c96, 0}, [&](const std::array<u64,3>& m704) {
          u64 v_c97 = m704[2];
          if (!slog::exists_probe<3,1>(appindex613, std::array<u64,3>{v_c97, 0, 0})) return;
          slog::join_probe<2,1>(refindex614, std::array<u64,2>{v_c89, 0}, [&](const std::array<u64,2>& m705) {
            u64 v_c98 = m705[1];
            if (!slog::exists_probe<3,1>(appindex615, std::array<u64,3>{v_c98, 0, 0})) return;
            slog::join_probe<2,1>(refindex616, std::array<u64,2>{v_c91, 0}, [&](const std::array<u64,2>& m706) {
              u64 v_c99 = m706[1];
              if (!slog::exists_probe<3,1>(appindex617, std::array<u64,3>{v_c99, 0, 0})) return;
              slog::join_probe<2,1>(refindex618, std::array<u64,2>{v_c94, 0}, [&](const std::array<u64,2>& m707) {
                u64 v_c100 = m707[1];
                slog::join_probe<3,2>(lambdaindex619, std::array<u64,3>{v_c94, v_c100, 0}, [&](const std::array<u64,3>& m708) {
                  u64 v_c101 = m708[2];
                  slog::join_probe<3,2>(appindex620, std::array<u64,3>{v_c99, v_c101, 0}, [&](const std::array<u64,3>& m709) {
                    u64 v_c102 = m709[2];
                    if (!slog::exists_probe<3,1>(appindex621, std::array<u64,3>{v_c102, 0, 0})) return;
                    slog::join_probe<2,1>(refindex622, std::array<u64,2>{v_c95, 0}, [&](const std::array<u64,2>& m710) {
                      u64 v_c103 = m710[1];
                      slog::join_probe<3,2>(lambdaindex623, std::array<u64,3>{v_c95, v_c103, 0}, [&](const std::array<u64,3>& m711) {
                        u64 v_c104 = m711[2];
                        slog::join_probe<3,2>(appindex624, std::array<u64,3>{v_c99, v_c104, 0}, [&](const std::array<u64,3>& m712) {
                          u64 v_c105 = m712[2];
                          slog::join_probe<3,2>(lambdaindex625, std::array<u64,3>{v_c93, v_c105, 0}, [&](const std::array<u64,3>& m713) {
                            u64 v_c106 = m713[2];
                            slog::join_probe<3,2>(appindex626, std::array<u64,3>{v_c106, v_c102, 0}, [&](const std::array<u64,3>& m714) {
                              u64 v_c107 = m714[2];
                              slog::join_probe<3,2>(lambdaindex627, std::array<u64,3>{v_c91, v_c107, 0}, [&](const std::array<u64,3>& m715) {
                                u64 v_c108 = m715[2];
                                if (!slog::exists_probe<3,1>(appindex628, std::array<u64,3>{v_c108, 0, 0})) return;
                                slog::join_probe<3,1>(appindex629, std::array<u64,3>{v_c98, 0, 0}, [&](const std::array<u64,3>& m716) {
                                  u64 v_c109 = m716[1]; u64 v_c110 = m716[2];
                                  if (v_c98 != v_c109) return;
                                  slog::join_probe<3,2>(lambdaindex630, std::array<u64,3>{v_c92, v_c110, 0}, [&](const std::array<u64,3>& m717) {
                                    u64 v_c111 = m717[2];
                                    slog::join_probe<3,2>(appindex631, std::array<u64,3>{v_c108, v_c111, 0}, [&](const std::array<u64,3>& m718) {
                                      u64 v_c112 = m718[2];
                                      slog::join_probe<3,2>(lambdaindex632, std::array<u64,3>{v_c89, v_c112, 0}, [&](const std::array<u64,3>& m719) {
                                        u64 v_c113 = m719[2];
                                        slog::join_probe<3,2>(appindex633, std::array<u64,3>{v_c113, v_c97, 0}, [&](const std::array<u64,3>& m720) {
                                          u64 v_c114 = m720[2];
                                          ++_fires;
                                          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c114}, std::array<u16,1>{0});
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
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:194", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask634(db,b));
  // (crule (pre (let __tconst0zC2144 const4e3b5454cf93e32fad90650d) (let __tconst8xRt151 const3a82152bd1402931076fe2d7) (let __tconst8eg8132 const361d5df359e0d7681220d09d) (let __tconst3Taj142 constdc1bb6655fb38bdb032e3754)) (scan app __t6Ups153 __t2nYy152 __t6t5O145) (body (exists lambda (0 1 2) 2 __t6t5O145 __tconst0zC2144) (exists lambda (1 2 0) 1 __tconst3Taj142) (exists ref (1 0) 1 __tconst8eg8132) (exists lambda (1 2 0) 1 __tconst8eg8132) (exists ref (1 0) 1 __tconst8xRt151) (exists ref (1 0) 1 __tconst3Taj142) (exists ref (1 0) 1 __tconst0zC2144) (join lambda (0 1 2) 2 __t2nYy152 __tconst8xRt151 __t9UZN150) (join lambda (0 1 2) 2 __t6t5O145 __tconst0zC2144 __t2Ce3143) (join lambda (0 1 2) 2 __t2Ce3143 __tconst3Taj142 __t25NQ141) (join ref (1 0) 1 __tconst8eg8132 __t19JM131) (join lambda (1 2 0) 2 __tconst8eg8132 __t19JM131 __t4DXA133) (join ref (1 0) 1 __tconst8xRt151 __t1g2P147) (join app (0 1 2) 2 __t9UZN150 __t1g2P147 dup2cTw407) (eq __t1g2P147 dup2cTw407) (join ref (1 0) 1 __tconst3Taj142 __t93Xi135) (join app (2 0 1) 2 __t93Xi135 __t25NQ141 __t8dYW140) (join ref (1 0) 1 __tconst0zC2144 __t7VSc137) (join app (0 1 2) 2 __t8dYW140 __t7VSc137 dup5xYd408) (eq __t7VSc137 dup5xYd408)) (head (mkstruct app (1 2 0) __t6KrY154 __t6Ups153 __t4DXA133)) mcfa-counting.slog:224 #f)
  class ReadTask739 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lambdaindex721;  slog::Index** lambdaindex722;  slog::Index** refindex723;  slog::Index** lambdaindex724;  slog::Index** refindex725;  slog::Index** refindex726;  slog::Index** refindex727;  slog::Index** lambdaindex728;  slog::Index** lambdaindex729;  slog::Index** lambdaindex730;  slog::Index** refindex731;  slog::Index** lambdaindex732;  slog::Index** refindex733;  slog::Index** appindex734;  slog::Index** refindex735;  slog::Index** appindex736;  slog::Index** refindex737;  slog::Index** appindex738;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      outer_rel = db->getRelation("app");
      std::vector<u16> ord740({0, 1, 2});
      slog::Relation* readrel741 = db->getRelation("lambda");
      lambdaindex721 = readrel741->getIndex(ord740, false);
      std::vector<u16> ord742({1, 2, 0});
      slog::Relation* readrel743 = db->getRelation("lambda");
      lambdaindex722 = readrel743->getIndex(ord742, false);
      std::vector<u16> ord744({1, 0});
      slog::Relation* readrel745 = db->getRelation("ref");
      refindex723 = readrel745->getIndex(ord744, false);
      std::vector<u16> ord746({1, 2, 0});
      slog::Relation* readrel747 = db->getRelation("lambda");
      lambdaindex724 = readrel747->getIndex(ord746, false);
      std::vector<u16> ord748({1, 0});
      slog::Relation* readrel749 = db->getRelation("ref");
      refindex725 = readrel749->getIndex(ord748, false);
      std::vector<u16> ord750({1, 0});
      slog::Relation* readrel751 = db->getRelation("ref");
      refindex726 = readrel751->getIndex(ord750, false);
      std::vector<u16> ord752({1, 0});
      slog::Relation* readrel753 = db->getRelation("ref");
      refindex727 = readrel753->getIndex(ord752, false);
      std::vector<u16> ord754({0, 1, 2});
      slog::Relation* readrel755 = db->getRelation("lambda");
      lambdaindex728 = readrel755->getIndex(ord754, false);
      std::vector<u16> ord756({0, 1, 2});
      slog::Relation* readrel757 = db->getRelation("lambda");
      lambdaindex729 = readrel757->getIndex(ord756, false);
      std::vector<u16> ord758({0, 1, 2});
      slog::Relation* readrel759 = db->getRelation("lambda");
      lambdaindex730 = readrel759->getIndex(ord758, false);
      std::vector<u16> ord760({1, 0});
      slog::Relation* readrel761 = db->getRelation("ref");
      refindex731 = readrel761->getIndex(ord760, false);
      std::vector<u16> ord762({1, 2, 0});
      slog::Relation* readrel763 = db->getRelation("lambda");
      lambdaindex732 = readrel763->getIndex(ord762, false);
      std::vector<u16> ord764({1, 0});
      slog::Relation* readrel765 = db->getRelation("ref");
      refindex733 = readrel765->getIndex(ord764, false);
      std::vector<u16> ord766({0, 1, 2});
      slog::Relation* readrel767 = db->getRelation("app");
      appindex734 = readrel767->getIndex(ord766, false);
      std::vector<u16> ord768({1, 0});
      slog::Relation* readrel769 = db->getRelation("ref");
      refindex735 = readrel769->getIndex(ord768, false);
      std::vector<u16> ord770({2, 0, 1});
      slog::Relation* readrel771 = db->getRelation("app");
      appindex736 = readrel771->getIndex(ord770, false);
      std::vector<u16> ord772({1, 0});
      slog::Relation* readrel773 = db->getRelation("ref");
      refindex737 = readrel773->getIndex(ord772, false);
      std::vector<u16> ord774({0, 1, 2});
      slog::Relation* readrel775 = db->getRelation("app");
      appindex738 = readrel775->getIndex(ord774, false);
  
    }
    ReadTask739(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c115 = v_const4e3b5454cf93e32fad90650d;
      u64 v_c116 = v_const3a82152bd1402931076fe2d7;
      u64 v_c117 = v_const361d5df359e0d7681220d09d;
      u64 v_c118 = v_constdc1bb6655fb38bdb032e3754;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c119 = _t[0];
        u64 v_c120 = _t[1];
        u64 v_c121 = _t[2];
        if (!slog::exists_probe<3,2>(lambdaindex721, std::array<u64,3>{v_c121, v_c115, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex722, std::array<u64,3>{v_c118, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex723, std::array<u64,2>{v_c117, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex724, std::array<u64,3>{v_c117, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex725, std::array<u64,2>{v_c116, 0})) return;
        if (!slog::exists_probe<2,1>(refindex726, std::array<u64,2>{v_c118, 0})) return;
        if (!slog::exists_probe<2,1>(refindex727, std::array<u64,2>{v_c115, 0})) return;
        slog::join_probe<3,2>(lambdaindex728, std::array<u64,3>{v_c120, v_c116, 0}, [&](const std::array<u64,3>& m776) {
          u64 v_c122 = m776[2];
          slog::join_probe<3,2>(lambdaindex729, std::array<u64,3>{v_c121, v_c115, 0}, [&](const std::array<u64,3>& m777) {
            u64 v_c123 = m777[2];
            slog::join_probe<3,2>(lambdaindex730, std::array<u64,3>{v_c123, v_c118, 0}, [&](const std::array<u64,3>& m778) {
              u64 v_c124 = m778[2];
              slog::join_probe<2,1>(refindex731, std::array<u64,2>{v_c117, 0}, [&](const std::array<u64,2>& m779) {
                u64 v_c125 = m779[1];
                slog::join_probe<3,2>(lambdaindex732, std::array<u64,3>{v_c117, v_c125, 0}, [&](const std::array<u64,3>& m780) {
                  u64 v_c126 = m780[2];
                  slog::join_probe<2,1>(refindex733, std::array<u64,2>{v_c116, 0}, [&](const std::array<u64,2>& m781) {
                    u64 v_c127 = m781[1];
                    slog::join_probe<3,2>(appindex734, std::array<u64,3>{v_c122, v_c127, 0}, [&](const std::array<u64,3>& m782) {
                      u64 v_c128 = m782[2];
                      if (v_c127 != v_c128) return;
                      slog::join_probe<2,1>(refindex735, std::array<u64,2>{v_c118, 0}, [&](const std::array<u64,2>& m783) {
                        u64 v_c129 = m783[1];
                        slog::join_probe<3,2>(appindex736, std::array<u64,3>{v_c129, v_c124, 0}, [&](const std::array<u64,3>& m784) {
                          u64 v_c130 = m784[2];
                          slog::join_probe<2,1>(refindex737, std::array<u64,2>{v_c115, 0}, [&](const std::array<u64,2>& m785) {
                            u64 v_c131 = m785[1];
                            slog::join_probe<3,2>(appindex738, std::array<u64,3>{v_c130, v_c131, 0}, [&](const std::array<u64,3>& m786) {
                              u64 v_c132 = m786[2];
                              if (v_c131 != v_c132) return;
                              ++_fires;
                              slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c119, v_c126}, std::array<u16,3>{1, 2, 0});
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
  
      if (_fires) db->bumpFires("mcfa-counting.slog:224", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask739* _cont = new ReadTask739(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask739(db,b), false);
  // (crule (pre) (scan freevar y __t4JNf263) (body (exists clo (1 2 0) 1 __t4JNf263) (join-old store (0 1 2) 1 (0 1 2) y cb vy) (join-old clo (1 2 0) 2 (1 2 0) __t4JNf263 cb __t0zen261) (join eval_ans (1 0) 1 __t0zen261 __t7ceq259) (join-old eval (0 2 1) 1 (0 2 1) __t7ceq259 c ef) (exists app (1 2 0) 1 ef) (exists eval (2 0 1) 1 c) (join eval (2 0 1) 1 c __5DEq344 __t6ooL258) (join-old app (0 1 2) 2 (0 1 2) __t6ooL258 ef ea) (join-old eval (1 2 0) 2 (1 2 0) ea c __t2S0s262) (join eval_ans (0 1) 1 __t2S0s262 va) (join-old lambda (0 1 2) 1 (0 1 2) __t4JNf263 x eb)) (head (emit store (0 1 2) y __t6ooL258 vy) (emit bindev (0 1 2) y __t6ooL258 c)) mcfa-counting.slog:102 #f)
  class ReadTask805 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** cloindex787;  slog::Index** storeindex788;  slog::Index** cloindex789;  slog::Index** eval_ansindex790;  slog::Index** evalindex791;  slog::Index** appindex792;  slog::Index** evalindex793;  slog::Index** evalindex794;  slog::Index** appindex795;  slog::Index** evalindex796;  slog::Index** eval_ansindex797;  slog::Index** lambdaindex798;  slog::Index** storedelta799;  slog::Index** clodelta800;  slog::Index** evaldelta801;  slog::Index** appdelta802;  slog::Index** evaldelta803;  slog::Index** lambdadelta804;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("store");
      std::vector<u16> ord806({0, 1, 2});
      slog::Relation* readrel807 = db->getRelation("store");
      head_index[0] = readrel807->getIndex(ord806, false);
      head_rel[1] = db->getRelation("bindev");
      std::vector<u16> ord808({0, 1, 2});
      slog::Relation* readrel809 = db->getRelation("bindev");
      head_index[1] = readrel809->getIndex(ord808, false);
      outer_rel = db->getRelation("freevar");
      std::vector<u16> ord810({1, 2, 0});
      slog::Relation* readrel811 = db->getRelation("clo");
      cloindex787 = readrel811->getIndex(ord810, false);
      std::vector<u16> ord812({0, 1, 2});
      slog::Relation* readrel813 = db->getRelation("store");
      storeindex788 = readrel813->getIndex(ord812, false);
      std::vector<u16> ord814({0, 1, 2});
      slog::Relation* readrel815 = db->getRelation("store");
      storedelta799 = readrel815->getIndex(ord814, true);
      std::vector<u16> ord816({1, 2, 0});
      slog::Relation* readrel817 = db->getRelation("clo");
      cloindex789 = readrel817->getIndex(ord816, false);
      std::vector<u16> ord818({1, 2, 0});
      slog::Relation* readrel819 = db->getRelation("clo");
      clodelta800 = readrel819->getIndex(ord818, true);
      std::vector<u16> ord820({1, 0});
      slog::Relation* readrel821 = db->getRelation("eval_ans");
      eval_ansindex790 = readrel821->getIndex(ord820, false);
      std::vector<u16> ord822({0, 2, 1});
      slog::Relation* readrel823 = db->getRelation("eval");
      evalindex791 = readrel823->getIndex(ord822, false);
      std::vector<u16> ord824({0, 2, 1});
      slog::Relation* readrel825 = db->getRelation("eval");
      evaldelta801 = readrel825->getIndex(ord824, true);
      std::vector<u16> ord826({1, 2, 0});
      slog::Relation* readrel827 = db->getRelation("app");
      appindex792 = readrel827->getIndex(ord826, false);
      std::vector<u16> ord828({2, 0, 1});
      slog::Relation* readrel829 = db->getRelation("eval");
      evalindex793 = readrel829->getIndex(ord828, false);
      std::vector<u16> ord830({2, 0, 1});
      slog::Relation* readrel831 = db->getRelation("eval");
      evalindex794 = readrel831->getIndex(ord830, false);
      std::vector<u16> ord832({0, 1, 2});
      slog::Relation* readrel833 = db->getRelation("app");
      appindex795 = readrel833->getIndex(ord832, false);
      std::vector<u16> ord834({0, 1, 2});
      slog::Relation* readrel835 = db->getRelation("app");
      appdelta802 = readrel835->getIndex(ord834, true);
      std::vector<u16> ord836({1, 2, 0});
      slog::Relation* readrel837 = db->getRelation("eval");
      evalindex796 = readrel837->getIndex(ord836, false);
      std::vector<u16> ord838({1, 2, 0});
      slog::Relation* readrel839 = db->getRelation("eval");
      evaldelta803 = readrel839->getIndex(ord838, true);
      std::vector<u16> ord840({0, 1});
      slog::Relation* readrel841 = db->getRelation("eval_ans");
      eval_ansindex797 = readrel841->getIndex(ord840, false);
      std::vector<u16> ord842({0, 1, 2});
      slog::Relation* readrel843 = db->getRelation("lambda");
      lambdaindex798 = readrel843->getIndex(ord842, false);
      std::vector<u16> ord844({0, 1, 2});
      slog::Relation* readrel845 = db->getRelation("lambda");
      lambdadelta804 = readrel845->getIndex(ord844, true);
  
    }
    ReadTask805(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c133 = _t[0];
        u64 v_c134 = _t[1];
        if (!slog::exists_probe<3,1>(cloindex787, std::array<u64,3>{v_c134, 0, 0})) return;
        slog::join_probe_old<3,1>(storeindex788, storedelta799, std::array<u64,3>{v_c133, 0, 0}, [&](const std::array<u64,3>& m846) {
          u64 v_c18 = m846[1]; u64 v_c135 = m846[2];
          slog::join_probe_old<3,2>(cloindex789, clodelta800, std::array<u64,3>{v_c134, v_c18, 0}, [&](const std::array<u64,3>& m847) {
            u64 v_c136 = m847[2];
            slog::join_probe<2,1>(eval_ansindex790, std::array<u64,2>{v_c136, 0}, [&](const std::array<u64,2>& m848) {
              u64 v_c137 = m848[1];
              slog::join_probe_old<3,1>(evalindex791, evaldelta801, std::array<u64,3>{v_c137, 0, 0}, [&](const std::array<u64,3>& m849) {
                u64 v_c13 = m849[1]; u64 v_c15 = m849[2];
                if (!slog::exists_probe<3,1>(appindex792, std::array<u64,3>{v_c15, 0, 0})) return;
                if (!slog::exists_probe<3,1>(evalindex793, std::array<u64,3>{v_c13, 0, 0})) return;
                slog::join_probe<3,1>(evalindex794, std::array<u64,3>{v_c13, 0, 0}, [&](const std::array<u64,3>& m850) {
                  u64 v_c138 = m850[1]; u64 v_c139 = m850[2];
                  slog::join_probe_old<3,2>(appindex795, appdelta802, std::array<u64,3>{v_c139, v_c15, 0}, [&](const std::array<u64,3>& m851) {
                    u64 v_c14 = m851[2];
                    slog::join_probe_old<3,2>(evalindex796, evaldelta803, std::array<u64,3>{v_c14, v_c13, 0}, [&](const std::array<u64,3>& m852) {
                      u64 v_c140 = m852[2];
                      slog::join_probe<2,1>(eval_ansindex797, std::array<u64,2>{v_c140, 0}, [&](const std::array<u64,2>& m853) {
                        u64 v_c20 = m853[1];
                        slog::join_probe_old<3,1>(lambdaindex798, lambdadelta804, std::array<u64,3>{v_c134, 0, 0}, [&](const std::array<u64,3>& m854) {
                          u64 v_c21 = m854[1]; u64 v_c19 = m854[2];
                          ++_fires;
                          slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c133, v_c139, v_c135}, std::array<u16,3>{0, 1, 2});
                          slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c133, v_c139, v_c13}, std::array<u16,3>{0, 1, 2});
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
  
      if (_fires) db->bumpFires("mcfa-counting.slog:102", "delta:freevar", _fires);
  
      if (!_done)
      {
        ReadTask805* _cont = new ReadTask805(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask805(db,b), false);
  // (crule (pre (let __tconst1pJW313 constb49bea2fcccd8f4301a347ed) (let __tconst7LWP310 const66518c0c1b3a5a0b09ae2ef1) (let __tconst0sqO307 const4a8acfc71441e0695ffcf5b3) (let __tconst5PoN291 constc85eae03730a4f4cf1d66a0c) (let __tconst2Yzp284 const8ca682693a0738a0641c6956) (let __tconst9rZO295 const576506f61f53440f1edd95d2) (let __tconst2CSv302 const229c0b7aa8a7eb4055f5a3d0)) (scan app __t6t9L309 __t0vn1308 __t4LtH299) (body (exists ref (1 0) 1 __tconst7LWP310) (exists lambda (1 2 0) 1 __tconst9rZO295) (exists ref (1 0) 1 __tconst9rZO295) (exists lambda (1 2 0) 1 __tconst2CSv302) (exists ref (1 0) 1 __tconst2CSv302) (exists ref (1 0) 1 __tconst2Yzp284) (exists lambda (1 2 0) 1 __tconst2Yzp284) (exists ref (1 0) 1 __tconst1pJW313) (exists lambda (1 2 0) 1 __tconst5PoN291) (join lambda (0 1 2) 2 __t0vn1308 __tconst0sqO307 __t4HUX306) (join ref (1 0) 1 __tconst7LWP310 __t91H2298) (exists app (0 1 2) 2 __t4HUX306 __t91H2298) (join app (0 1 2) 2 __t4LtH299 __t91H2298 __t3dkk296) (join lambda (0 1 2) 2 __t3dkk296 __tconst9rZO295 __t71w7294) (join ref (0 1) 2 __t71w7294 __tconst9rZO295) (join app (0 1 2) 2 __t4HUX306 __t91H2298 __t7EW2303) (join lambda (0 1 2) 2 __t7EW2303 __tconst2CSv302 __t6lXa301) (join ref (0 1) 2 __t6lXa301 __tconst2CSv302) (join ref (1 0) 1 __tconst2Yzp284 __t248W283) (join lambda (1 2 0) 2 __tconst2Yzp284 __t248W283 __t0oFu285) (join ref (1 0) 1 __tconst1pJW313 __t165O287) (join app (1 2 0) 1 __t165O287 dup9ui7381 __t30Ec290) (eq __t165O287 dup9ui7381) (join lambda (1 2 0) 2 __tconst5PoN291 __t30Ec290 __t7aCZ292)) (head (mkstruct lambda (1 2 0) __t5T0g311 __tconst7LWP310 __t6t9L309)) mcfa-counting.slog:194 #f)
  class ReadTask878 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex855;  slog::Index** lambdaindex856;  slog::Index** refindex857;  slog::Index** lambdaindex858;  slog::Index** refindex859;  slog::Index** refindex860;  slog::Index** lambdaindex861;  slog::Index** refindex862;  slog::Index** lambdaindex863;  slog::Index** lambdaindex864;  slog::Index** refindex865;  slog::Index** appindex866;  slog::Index** appindex867;  slog::Index** lambdaindex868;  slog::Index** refindex869;  slog::Index** appindex870;  slog::Index** lambdaindex871;  slog::Index** refindex872;  slog::Index** refindex873;  slog::Index** lambdaindex874;  slog::Index** refindex875;  slog::Index** appindex876;  slog::Index** lambdaindex877;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      outer_rel = db->getRelation("app");
      std::vector<u16> ord879({1, 0});
      slog::Relation* readrel880 = db->getRelation("ref");
      refindex855 = readrel880->getIndex(ord879, false);
      std::vector<u16> ord881({1, 2, 0});
      slog::Relation* readrel882 = db->getRelation("lambda");
      lambdaindex856 = readrel882->getIndex(ord881, false);
      std::vector<u16> ord883({1, 0});
      slog::Relation* readrel884 = db->getRelation("ref");
      refindex857 = readrel884->getIndex(ord883, false);
      std::vector<u16> ord885({1, 2, 0});
      slog::Relation* readrel886 = db->getRelation("lambda");
      lambdaindex858 = readrel886->getIndex(ord885, false);
      std::vector<u16> ord887({1, 0});
      slog::Relation* readrel888 = db->getRelation("ref");
      refindex859 = readrel888->getIndex(ord887, false);
      std::vector<u16> ord889({1, 0});
      slog::Relation* readrel890 = db->getRelation("ref");
      refindex860 = readrel890->getIndex(ord889, false);
      std::vector<u16> ord891({1, 2, 0});
      slog::Relation* readrel892 = db->getRelation("lambda");
      lambdaindex861 = readrel892->getIndex(ord891, false);
      std::vector<u16> ord893({1, 0});
      slog::Relation* readrel894 = db->getRelation("ref");
      refindex862 = readrel894->getIndex(ord893, false);
      std::vector<u16> ord895({1, 2, 0});
      slog::Relation* readrel896 = db->getRelation("lambda");
      lambdaindex863 = readrel896->getIndex(ord895, false);
      std::vector<u16> ord897({0, 1, 2});
      slog::Relation* readrel898 = db->getRelation("lambda");
      lambdaindex864 = readrel898->getIndex(ord897, false);
      std::vector<u16> ord899({1, 0});
      slog::Relation* readrel900 = db->getRelation("ref");
      refindex865 = readrel900->getIndex(ord899, false);
      std::vector<u16> ord901({0, 1, 2});
      slog::Relation* readrel902 = db->getRelation("app");
      appindex866 = readrel902->getIndex(ord901, false);
      std::vector<u16> ord903({0, 1, 2});
      slog::Relation* readrel904 = db->getRelation("app");
      appindex867 = readrel904->getIndex(ord903, false);
      std::vector<u16> ord905({0, 1, 2});
      slog::Relation* readrel906 = db->getRelation("lambda");
      lambdaindex868 = readrel906->getIndex(ord905, false);
      std::vector<u16> ord907({0, 1});
      slog::Relation* readrel908 = db->getRelation("ref");
      refindex869 = readrel908->getIndex(ord907, false);
      std::vector<u16> ord909({0, 1, 2});
      slog::Relation* readrel910 = db->getRelation("app");
      appindex870 = readrel910->getIndex(ord909, false);
      std::vector<u16> ord911({0, 1, 2});
      slog::Relation* readrel912 = db->getRelation("lambda");
      lambdaindex871 = readrel912->getIndex(ord911, false);
      std::vector<u16> ord913({0, 1});
      slog::Relation* readrel914 = db->getRelation("ref");
      refindex872 = readrel914->getIndex(ord913, false);
      std::vector<u16> ord915({1, 0});
      slog::Relation* readrel916 = db->getRelation("ref");
      refindex873 = readrel916->getIndex(ord915, false);
      std::vector<u16> ord917({1, 2, 0});
      slog::Relation* readrel918 = db->getRelation("lambda");
      lambdaindex874 = readrel918->getIndex(ord917, false);
      std::vector<u16> ord919({1, 0});
      slog::Relation* readrel920 = db->getRelation("ref");
      refindex875 = readrel920->getIndex(ord919, false);
      std::vector<u16> ord921({1, 2, 0});
      slog::Relation* readrel922 = db->getRelation("app");
      appindex876 = readrel922->getIndex(ord921, false);
      std::vector<u16> ord923({1, 2, 0});
      slog::Relation* readrel924 = db->getRelation("lambda");
      lambdaindex877 = readrel924->getIndex(ord923, false);
  
    }
    ReadTask878(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c89 = v_constb49bea2fcccd8f4301a347ed;
      u64 v_c91 = v_const66518c0c1b3a5a0b09ae2ef1;
      u64 v_c93 = v_const4a8acfc71441e0695ffcf5b3;
      u64 v_c92 = v_constc85eae03730a4f4cf1d66a0c;
      u64 v_c90 = v_const8ca682693a0738a0641c6956;
      u64 v_c94 = v_const576506f61f53440f1edd95d2;
      u64 v_c95 = v_const229c0b7aa8a7eb4055f5a3d0;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c107 = _t[0];
        u64 v_c106 = _t[1];
        u64 v_c102 = _t[2];
        if (!slog::exists_probe<2,1>(refindex855, std::array<u64,2>{v_c91, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex856, std::array<u64,3>{v_c94, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex857, std::array<u64,2>{v_c94, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex858, std::array<u64,3>{v_c95, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex859, std::array<u64,2>{v_c95, 0})) return;
        if (!slog::exists_probe<2,1>(refindex860, std::array<u64,2>{v_c90, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex861, std::array<u64,3>{v_c90, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex862, std::array<u64,2>{v_c89, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex863, std::array<u64,3>{v_c92, 0, 0})) return;
        slog::join_probe<3,2>(lambdaindex864, std::array<u64,3>{v_c106, v_c93, 0}, [&](const std::array<u64,3>& m925) {
          u64 v_c105 = m925[2];
          slog::join_probe<2,1>(refindex865, std::array<u64,2>{v_c91, 0}, [&](const std::array<u64,2>& m926) {
            u64 v_c99 = m926[1];
            if (!slog::exists_probe<3,2>(appindex866, std::array<u64,3>{v_c105, v_c99, 0})) return;
            slog::join_probe<3,2>(appindex867, std::array<u64,3>{v_c102, v_c99, 0}, [&](const std::array<u64,3>& m927) {
              u64 v_c101 = m927[2];
              slog::join_probe<3,2>(lambdaindex868, std::array<u64,3>{v_c101, v_c94, 0}, [&](const std::array<u64,3>& m928) {
                u64 v_c100 = m928[2];
                slog::join_probe<2,2>(refindex869, std::array<u64,2>{v_c100, v_c94}, [&](const std::array<u64,2>& m929) {
                  slog::join_probe<3,2>(appindex870, std::array<u64,3>{v_c105, v_c99, 0}, [&](const std::array<u64,3>& m930) {
                    u64 v_c104 = m930[2];
                    slog::join_probe<3,2>(lambdaindex871, std::array<u64,3>{v_c104, v_c95, 0}, [&](const std::array<u64,3>& m931) {
                      u64 v_c103 = m931[2];
                      slog::join_probe<2,2>(refindex872, std::array<u64,2>{v_c103, v_c95}, [&](const std::array<u64,2>& m932) {
                        slog::join_probe<2,1>(refindex873, std::array<u64,2>{v_c90, 0}, [&](const std::array<u64,2>& m933) {
                          u64 v_c96 = m933[1];
                          slog::join_probe<3,2>(lambdaindex874, std::array<u64,3>{v_c90, v_c96, 0}, [&](const std::array<u64,3>& m934) {
                            u64 v_c97 = m934[2];
                            slog::join_probe<2,1>(refindex875, std::array<u64,2>{v_c89, 0}, [&](const std::array<u64,2>& m935) {
                              u64 v_c98 = m935[1];
                              slog::join_probe<3,1>(appindex876, std::array<u64,3>{v_c98, 0, 0}, [&](const std::array<u64,3>& m936) {
                                u64 v_c141 = m936[1]; u64 v_c110 = m936[2];
                                if (v_c98 != v_c141) return;
                                slog::join_probe<3,2>(lambdaindex877, std::array<u64,3>{v_c92, v_c110, 0}, [&](const std::array<u64,3>& m937) {
                                  u64 v_c111 = m937[2];
                                  ++_fires;
                                  slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c91, v_c107}, std::array<u16,3>{1, 2, 0});
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
  
      if (_fires) db->bumpFires("mcfa-counting.slog:194", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask878* _cont = new ReadTask878(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask878(db,b), false);
  // (crule (pre (let __tconst4Xaz41 const81cb39a72a584ab4f703b7f7) (let __tconst4xzG22 constdbf1bdba02122b2adce28528) (let __tconst1aIN38 const4d5ce1398140fbe27561181f) (let __tconst1HMF17 constd7a1925d249b4768c8a9f2d8) (let __tconst37GM26 const85f09fa1913b9daf65957cf7) (let __tconst1ha033 const969c6e56242ce8d0a4346602)) (seeded) (body (join ref (1 0) 1 __tconst4xzG22 __t2DOE20) (exists ref (1 0) 1 __tconst1HMF17) (exists lambda (1 2 0) 1 __tconst1HMF17) (exists app (1 2 0) 1 __t2DOE20) (exists lambda (1 2 0) 1 __tconst4xzG22) (exists ref (1 0) 1 __tconst37GM26) (exists lambda (1 2 0) 1 __tconst37GM26) (exists ref (1 0) 1 __tconst1ha033) (exists lambda (1 2 0) 1 __tconst1ha033) (exists lambda (1 2 0) 1 __tconst1aIN38) (exists lambda (1 2 0) 1 __tconst4Xaz41) (join ref (1 0) 1 __tconst4Xaz41 __t75SZ29) (exists app (1 2 0) 1 __t75SZ29) (join ref (1 0) 1 __tconst1HMF17 __t7H1u16) (join lambda (1 2 0) 2 __tconst1HMF17 __t7H1u16 __t2wNc18) (join app (1 2 0) 2 __t2DOE20 __t2wNc18 __t3b2k21) (join lambda (1 2 0) 2 __tconst4xzG22 __t3b2k21 __t8Ovw23) (exists app (2 0 1) 1 __t8Ovw23) (join ref (1 0) 1 __tconst37GM26 __t7U1m25) (join lambda (1 2 0) 2 __tconst37GM26 __t7U1m25 __t5myE27) (join app (1 2 0) 2 __t75SZ29 __t5myE27 __t2Vg230) (exists app (2 0 1) 1 __t2Vg230) (join ref (1 0) 1 __tconst1ha033 __t7N9A32) (join lambda (1 2 0) 2 __tconst1ha033 __t7N9A32 __t065j34) (join app (1 2 0) 2 __t75SZ29 __t065j34 __t3pMW37) (join lambda (1 2 0) 2 __tconst1aIN38 __t3pMW37 __t3aRV39) (join app (1 2 0) 2 __t3aRV39 __t2Vg230 __t7P7240) (join lambda (1 2 0) 2 __tconst4Xaz41 __t7P7240 __t79we42) (join app (1 2 0) 2 __t79we42 __t8Ovw23 __t9tGa43)) (head (emit program (0) __t9tGa43)) mcfa-counting.slog:260 #f)
  class ReadTask967 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex938;  slog::Index** refindex939;  slog::Index** lambdaindex940;  slog::Index** appindex941;  slog::Index** lambdaindex942;  slog::Index** refindex943;  slog::Index** lambdaindex944;  slog::Index** refindex945;  slog::Index** lambdaindex946;  slog::Index** lambdaindex947;  slog::Index** lambdaindex948;  slog::Index** refindex949;  slog::Index** appindex950;  slog::Index** refindex951;  slog::Index** lambdaindex952;  slog::Index** appindex953;  slog::Index** lambdaindex954;  slog::Index** appindex955;  slog::Index** refindex956;  slog::Index** lambdaindex957;  slog::Index** appindex958;  slog::Index** appindex959;  slog::Index** refindex960;  slog::Index** lambdaindex961;  slog::Index** appindex962;  slog::Index** lambdaindex963;  slog::Index** appindex964;  slog::Index** lambdaindex965;  slog::Index** appindex966;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("program");
      std::vector<u16> ord968({0});
      slog::Relation* readrel969 = db->getRelation("program");
      head_index[0] = readrel969->getIndex(ord968, false);
      std::vector<u16> ord970({1, 0});
      slog::Relation* readrel971 = db->getRelation("ref");
      refindex938 = readrel971->getIndex(ord970, false);
      std::vector<u16> ord972({1, 0});
      slog::Relation* readrel973 = db->getRelation("ref");
      refindex939 = readrel973->getIndex(ord972, false);
      std::vector<u16> ord974({1, 2, 0});
      slog::Relation* readrel975 = db->getRelation("lambda");
      lambdaindex940 = readrel975->getIndex(ord974, false);
      std::vector<u16> ord976({1, 2, 0});
      slog::Relation* readrel977 = db->getRelation("app");
      appindex941 = readrel977->getIndex(ord976, false);
      std::vector<u16> ord978({1, 2, 0});
      slog::Relation* readrel979 = db->getRelation("lambda");
      lambdaindex942 = readrel979->getIndex(ord978, false);
      std::vector<u16> ord980({1, 0});
      slog::Relation* readrel981 = db->getRelation("ref");
      refindex943 = readrel981->getIndex(ord980, false);
      std::vector<u16> ord982({1, 2, 0});
      slog::Relation* readrel983 = db->getRelation("lambda");
      lambdaindex944 = readrel983->getIndex(ord982, false);
      std::vector<u16> ord984({1, 0});
      slog::Relation* readrel985 = db->getRelation("ref");
      refindex945 = readrel985->getIndex(ord984, false);
      std::vector<u16> ord986({1, 2, 0});
      slog::Relation* readrel987 = db->getRelation("lambda");
      lambdaindex946 = readrel987->getIndex(ord986, false);
      std::vector<u16> ord988({1, 2, 0});
      slog::Relation* readrel989 = db->getRelation("lambda");
      lambdaindex947 = readrel989->getIndex(ord988, false);
      std::vector<u16> ord990({1, 2, 0});
      slog::Relation* readrel991 = db->getRelation("lambda");
      lambdaindex948 = readrel991->getIndex(ord990, false);
      std::vector<u16> ord992({1, 0});
      slog::Relation* readrel993 = db->getRelation("ref");
      refindex949 = readrel993->getIndex(ord992, false);
      std::vector<u16> ord994({1, 2, 0});
      slog::Relation* readrel995 = db->getRelation("app");
      appindex950 = readrel995->getIndex(ord994, false);
      std::vector<u16> ord996({1, 0});
      slog::Relation* readrel997 = db->getRelation("ref");
      refindex951 = readrel997->getIndex(ord996, false);
      std::vector<u16> ord998({1, 2, 0});
      slog::Relation* readrel999 = db->getRelation("lambda");
      lambdaindex952 = readrel999->getIndex(ord998, false);
      std::vector<u16> ord1000({1, 2, 0});
      slog::Relation* readrel1001 = db->getRelation("app");
      appindex953 = readrel1001->getIndex(ord1000, false);
      std::vector<u16> ord1002({1, 2, 0});
      slog::Relation* readrel1003 = db->getRelation("lambda");
      lambdaindex954 = readrel1003->getIndex(ord1002, false);
      std::vector<u16> ord1004({2, 0, 1});
      slog::Relation* readrel1005 = db->getRelation("app");
      appindex955 = readrel1005->getIndex(ord1004, false);
      std::vector<u16> ord1006({1, 0});
      slog::Relation* readrel1007 = db->getRelation("ref");
      refindex956 = readrel1007->getIndex(ord1006, false);
      std::vector<u16> ord1008({1, 2, 0});
      slog::Relation* readrel1009 = db->getRelation("lambda");
      lambdaindex957 = readrel1009->getIndex(ord1008, false);
      std::vector<u16> ord1010({1, 2, 0});
      slog::Relation* readrel1011 = db->getRelation("app");
      appindex958 = readrel1011->getIndex(ord1010, false);
      std::vector<u16> ord1012({2, 0, 1});
      slog::Relation* readrel1013 = db->getRelation("app");
      appindex959 = readrel1013->getIndex(ord1012, false);
      std::vector<u16> ord1014({1, 0});
      slog::Relation* readrel1015 = db->getRelation("ref");
      refindex960 = readrel1015->getIndex(ord1014, false);
      std::vector<u16> ord1016({1, 2, 0});
      slog::Relation* readrel1017 = db->getRelation("lambda");
      lambdaindex961 = readrel1017->getIndex(ord1016, false);
      std::vector<u16> ord1018({1, 2, 0});
      slog::Relation* readrel1019 = db->getRelation("app");
      appindex962 = readrel1019->getIndex(ord1018, false);
      std::vector<u16> ord1020({1, 2, 0});
      slog::Relation* readrel1021 = db->getRelation("lambda");
      lambdaindex963 = readrel1021->getIndex(ord1020, false);
      std::vector<u16> ord1022({1, 2, 0});
      slog::Relation* readrel1023 = db->getRelation("app");
      appindex964 = readrel1023->getIndex(ord1022, false);
      std::vector<u16> ord1024({1, 2, 0});
      slog::Relation* readrel1025 = db->getRelation("lambda");
      lambdaindex965 = readrel1025->getIndex(ord1024, false);
      std::vector<u16> ord1026({1, 2, 0});
      slog::Relation* readrel1027 = db->getRelation("app");
      appindex966 = readrel1027->getIndex(ord1026, false);
  
    }
    ReadTask967(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c27 = v_const81cb39a72a584ab4f703b7f7;
      u64 v_c28 = v_constdbf1bdba02122b2adce28528;
      u64 v_c29 = v_const4d5ce1398140fbe27561181f;
      u64 v_c30 = v_constd7a1925d249b4768c8a9f2d8;
      u64 v_c31 = v_const85f09fa1913b9daf65957cf7;
      u64 v_c32 = v_const969c6e56242ce8d0a4346602;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex938, std::array<u64,2>{v_c28, 0}, [&](const std::array<u64,2>& m1028) {
        u64 v_c38 = m1028[1];
        if (!slog::exists_probe<2,1>(refindex939, std::array<u64,2>{v_c30, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex940, std::array<u64,3>{v_c30, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex941, std::array<u64,3>{v_c38, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex942, std::array<u64,3>{v_c28, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex943, std::array<u64,2>{v_c31, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex944, std::array<u64,3>{v_c31, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex945, std::array<u64,2>{v_c32, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex946, std::array<u64,3>{v_c32, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex947, std::array<u64,3>{v_c29, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex948, std::array<u64,3>{v_c27, 0, 0})) return;
        slog::join_probe<2,1>(refindex949, std::array<u64,2>{v_c27, 0}, [&](const std::array<u64,2>& m1029) {
          u64 v_c41 = m1029[1];
          if (!slog::exists_probe<3,1>(appindex950, std::array<u64,3>{v_c41, 0, 0})) return;
          slog::join_probe<2,1>(refindex951, std::array<u64,2>{v_c30, 0}, [&](const std::array<u64,2>& m1030) {
            u64 v_c40 = m1030[1];
            slog::join_probe<3,2>(lambdaindex952, std::array<u64,3>{v_c30, v_c40, 0}, [&](const std::array<u64,3>& m1031) {
              u64 v_c39 = m1031[2];
              slog::join_probe<3,2>(appindex953, std::array<u64,3>{v_c38, v_c39, 0}, [&](const std::array<u64,3>& m1032) {
                u64 v_c36 = m1032[2];
                slog::join_probe<3,2>(lambdaindex954, std::array<u64,3>{v_c28, v_c36, 0}, [&](const std::array<u64,3>& m1033) {
                  u64 v_c35 = m1033[2];
                  if (!slog::exists_probe<3,1>(appindex955, std::array<u64,3>{v_c35, 0, 0})) return;
                  slog::join_probe<2,1>(refindex956, std::array<u64,2>{v_c31, 0}, [&](const std::array<u64,2>& m1034) {
                    u64 v_c42 = m1034[1];
                    slog::join_probe<3,2>(lambdaindex957, std::array<u64,3>{v_c31, v_c42, 0}, [&](const std::array<u64,3>& m1035) {
                      u64 v_c43 = m1035[2];
                      slog::join_probe<3,2>(appindex958, std::array<u64,3>{v_c41, v_c43, 0}, [&](const std::array<u64,3>& m1036) {
                        u64 v_c44 = m1036[2];
                        if (!slog::exists_probe<3,1>(appindex959, std::array<u64,3>{v_c44, 0, 0})) return;
                        slog::join_probe<2,1>(refindex960, std::array<u64,2>{v_c32, 0}, [&](const std::array<u64,2>& m1037) {
                          u64 v_c48 = m1037[1];
                          slog::join_probe<3,2>(lambdaindex961, std::array<u64,3>{v_c32, v_c48, 0}, [&](const std::array<u64,3>& m1038) {
                            u64 v_c47 = m1038[2];
                            slog::join_probe<3,2>(appindex962, std::array<u64,3>{v_c41, v_c47, 0}, [&](const std::array<u64,3>& m1039) {
                              u64 v_c46 = m1039[2];
                              slog::join_probe<3,2>(lambdaindex963, std::array<u64,3>{v_c29, v_c46, 0}, [&](const std::array<u64,3>& m1040) {
                                u64 v_c45 = m1040[2];
                                slog::join_probe<3,2>(appindex964, std::array<u64,3>{v_c45, v_c44, 0}, [&](const std::array<u64,3>& m1041) {
                                  u64 v_c37 = m1041[2];
                                  slog::join_probe<3,2>(lambdaindex965, std::array<u64,3>{v_c27, v_c37, 0}, [&](const std::array<u64,3>& m1042) {
                                    u64 v_c34 = m1042[2];
                                    slog::join_probe<3,2>(appindex966, std::array<u64,3>{v_c34, v_c35, 0}, [&](const std::array<u64,3>& m1043) {
                                      u64 v_c33 = m1043[2];
                                      ++_fires;
                                      slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c33}, std::array<u16,1>{0});
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
  
      if (_fires) db->bumpFires("mcfa-counting.slog:260", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask967(db,b));
  // (crule (pre (let __tconst9zoW125 const7c7d2cfc66f4d976987d2d20) (let __tconst4V4L122 const6bc0ba365ada70df115e1785) (let __tconst82U8119 consta8180db1c2f300980314f910) (let __tconst3wDH116 constd5f017533ea574d5f9b3400c) (let __tconst4BKz104 const0f8748be649f8ee4066bb1d7) (let __tconst4Zcr91 const9a67f28c6b77e842f439a84a) (let __tconst3ktF111 const990b444cbd47632035b2fa1a) (let __tconst5nWJ102 const4f84f41d89b6b717419b4eaa) (let __tconst0vRf84 conste58dec6bca6f63ef79c3b755)) (seeded) (body (join ref (1 0) 1 __tconst4V4L122 __t7aew98) (exists ref (1 0) 1 __tconst0vRf84) (exists lambda (1 2 0) 1 __tconst0vRf84) (exists ref (1 0) 1 __tconst4Zcr91) (exists ref (1 0) 1 __tconst9zoW125) (exists lambda (1 2 0) 1 __tconst4Zcr91) (exists ref (1 0) 1 __tconst4BKz104) (exists lambda (1 2 0) 1 __tconst4BKz104) (exists app (1 2 0) 1 __t7aew98) (exists ref (1 0) 1 __tconst5nWJ102) (exists lambda (1 2 0) 1 __tconst5nWJ102) (exists ref (1 0) 1 __tconst3ktF111) (exists lambda (1 2 0) 1 __tconst3ktF111) (join ref (1 0) 1 __tconst3wDH116 __t3wir114) (exists app (1 2 0) 1 __t3wir114) (join ref (1 0) 1 __tconst0vRf84 __t2duR83) (join lambda (1 2 0) 2 __tconst0vRf84 __t2duR83 __t87vL85) (join ref (1 0) 1 __tconst4Zcr91 __t0C9F87) (exists app (2 0 1) 1 __t0C9F87) (join ref (1 0) 1 __tconst9zoW125 __t3Q2G89) (join app (1 2 0) 2 __t3Q2G89 __t0C9F87 __t2Eqd90) (join lambda (1 2 0) 2 __tconst4Zcr91 __t2Eqd90 __t3pgm92) (join ref (1 0) 1 __tconst4BKz104 __t8C0a94) (join lambda (1 2 0) 2 __tconst4BKz104 __t8C0a94 __t4fDK96) (join app (1 2 0) 2 __t7aew98 __t4fDK96 __t7TEO99) (join ref (1 0) 1 __tconst5nWJ102 __t5MaG101) (join lambda (1 2 0) 2 __tconst5nWJ102 __t5MaG101 __t35jA103) (join lambda (1 2 0) 2 __tconst4BKz104 __t35jA103 __t6RuY105) (join ref (1 0) 1 __tconst3ktF111 __t7ohz110) (join lambda (1 2 0) 2 __tconst3ktF111 __t7ohz110 __t8GWA112) (join app (1 2 0) 2 __t3wir114 __t8GWA112 __t44OM115)) (head (mkstruct lambda (1 2 0) __t7CwH117 __tconst3wDH116 __t44OM115) (mkstruct app (1 2 0) __t2Z7m108 __t7aew98 __t6RuY105)) mcfa-counting.slog:241 #f)
  class ReadTask1075 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
  
  
  
  
  
    slog::Index** refindex1044;  slog::Index** refindex1045;  slog::Index** lambdaindex1046;  slog::Index** refindex1047;  slog::Index** refindex1048;  slog::Index** lambdaindex1049;  slog::Index** refindex1050;  slog::Index** lambdaindex1051;  slog::Index** appindex1052;  slog::Index** refindex1053;  slog::Index** lambdaindex1054;  slog::Index** refindex1055;  slog::Index** lambdaindex1056;  slog::Index** refindex1057;  slog::Index** appindex1058;  slog::Index** refindex1059;  slog::Index** lambdaindex1060;  slog::Index** refindex1061;  slog::Index** appindex1062;  slog::Index** refindex1063;  slog::Index** appindex1064;  slog::Index** lambdaindex1065;  slog::Index** refindex1066;  slog::Index** lambdaindex1067;  slog::Index** appindex1068;  slog::Index** refindex1069;  slog::Index** lambdaindex1070;  slog::Index** lambdaindex1071;  slog::Index** refindex1072;  slog::Index** lambdaindex1073;  slog::Index** appindex1074;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      std::vector<u16> ord1076({1, 2, 0});
      slog::Relation* readrel1077 = db->getRelation("lambda");
      head_index[0] = readrel1077->getIndex(ord1076, false);
      head_rel[1] = db->getRelation("app");
      std::vector<u16> ord1078({1, 2, 0});
      slog::Relation* readrel1079 = db->getRelation("app");
      head_index[1] = readrel1079->getIndex(ord1078, false);
      std::vector<u16> ord1080({1, 0});
      slog::Relation* readrel1081 = db->getRelation("ref");
      refindex1044 = readrel1081->getIndex(ord1080, false);
      std::vector<u16> ord1082({1, 0});
      slog::Relation* readrel1083 = db->getRelation("ref");
      refindex1045 = readrel1083->getIndex(ord1082, false);
      std::vector<u16> ord1084({1, 2, 0});
      slog::Relation* readrel1085 = db->getRelation("lambda");
      lambdaindex1046 = readrel1085->getIndex(ord1084, false);
      std::vector<u16> ord1086({1, 0});
      slog::Relation* readrel1087 = db->getRelation("ref");
      refindex1047 = readrel1087->getIndex(ord1086, false);
      std::vector<u16> ord1088({1, 0});
      slog::Relation* readrel1089 = db->getRelation("ref");
      refindex1048 = readrel1089->getIndex(ord1088, false);
      std::vector<u16> ord1090({1, 2, 0});
      slog::Relation* readrel1091 = db->getRelation("lambda");
      lambdaindex1049 = readrel1091->getIndex(ord1090, false);
      std::vector<u16> ord1092({1, 0});
      slog::Relation* readrel1093 = db->getRelation("ref");
      refindex1050 = readrel1093->getIndex(ord1092, false);
      std::vector<u16> ord1094({1, 2, 0});
      slog::Relation* readrel1095 = db->getRelation("lambda");
      lambdaindex1051 = readrel1095->getIndex(ord1094, false);
      std::vector<u16> ord1096({1, 2, 0});
      slog::Relation* readrel1097 = db->getRelation("app");
      appindex1052 = readrel1097->getIndex(ord1096, false);
      std::vector<u16> ord1098({1, 0});
      slog::Relation* readrel1099 = db->getRelation("ref");
      refindex1053 = readrel1099->getIndex(ord1098, false);
      std::vector<u16> ord1100({1, 2, 0});
      slog::Relation* readrel1101 = db->getRelation("lambda");
      lambdaindex1054 = readrel1101->getIndex(ord1100, false);
      std::vector<u16> ord1102({1, 0});
      slog::Relation* readrel1103 = db->getRelation("ref");
      refindex1055 = readrel1103->getIndex(ord1102, false);
      std::vector<u16> ord1104({1, 2, 0});
      slog::Relation* readrel1105 = db->getRelation("lambda");
      lambdaindex1056 = readrel1105->getIndex(ord1104, false);
      std::vector<u16> ord1106({1, 0});
      slog::Relation* readrel1107 = db->getRelation("ref");
      refindex1057 = readrel1107->getIndex(ord1106, false);
      std::vector<u16> ord1108({1, 2, 0});
      slog::Relation* readrel1109 = db->getRelation("app");
      appindex1058 = readrel1109->getIndex(ord1108, false);
      std::vector<u16> ord1110({1, 0});
      slog::Relation* readrel1111 = db->getRelation("ref");
      refindex1059 = readrel1111->getIndex(ord1110, false);
      std::vector<u16> ord1112({1, 2, 0});
      slog::Relation* readrel1113 = db->getRelation("lambda");
      lambdaindex1060 = readrel1113->getIndex(ord1112, false);
      std::vector<u16> ord1114({1, 0});
      slog::Relation* readrel1115 = db->getRelation("ref");
      refindex1061 = readrel1115->getIndex(ord1114, false);
      std::vector<u16> ord1116({2, 0, 1});
      slog::Relation* readrel1117 = db->getRelation("app");
      appindex1062 = readrel1117->getIndex(ord1116, false);
      std::vector<u16> ord1118({1, 0});
      slog::Relation* readrel1119 = db->getRelation("ref");
      refindex1063 = readrel1119->getIndex(ord1118, false);
      std::vector<u16> ord1120({1, 2, 0});
      slog::Relation* readrel1121 = db->getRelation("app");
      appindex1064 = readrel1121->getIndex(ord1120, false);
      std::vector<u16> ord1122({1, 2, 0});
      slog::Relation* readrel1123 = db->getRelation("lambda");
      lambdaindex1065 = readrel1123->getIndex(ord1122, false);
      std::vector<u16> ord1124({1, 0});
      slog::Relation* readrel1125 = db->getRelation("ref");
      refindex1066 = readrel1125->getIndex(ord1124, false);
      std::vector<u16> ord1126({1, 2, 0});
      slog::Relation* readrel1127 = db->getRelation("lambda");
      lambdaindex1067 = readrel1127->getIndex(ord1126, false);
      std::vector<u16> ord1128({1, 2, 0});
      slog::Relation* readrel1129 = db->getRelation("app");
      appindex1068 = readrel1129->getIndex(ord1128, false);
      std::vector<u16> ord1130({1, 0});
      slog::Relation* readrel1131 = db->getRelation("ref");
      refindex1069 = readrel1131->getIndex(ord1130, false);
      std::vector<u16> ord1132({1, 2, 0});
      slog::Relation* readrel1133 = db->getRelation("lambda");
      lambdaindex1070 = readrel1133->getIndex(ord1132, false);
      std::vector<u16> ord1134({1, 2, 0});
      slog::Relation* readrel1135 = db->getRelation("lambda");
      lambdaindex1071 = readrel1135->getIndex(ord1134, false);
      std::vector<u16> ord1136({1, 0});
      slog::Relation* readrel1137 = db->getRelation("ref");
      refindex1072 = readrel1137->getIndex(ord1136, false);
      std::vector<u16> ord1138({1, 2, 0});
      slog::Relation* readrel1139 = db->getRelation("lambda");
      lambdaindex1073 = readrel1139->getIndex(ord1138, false);
      std::vector<u16> ord1140({1, 2, 0});
      slog::Relation* readrel1141 = db->getRelation("app");
      appindex1074 = readrel1141->getIndex(ord1140, false);
  
    }
    ReadTask1075(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c49 = v_const7c7d2cfc66f4d976987d2d20;
      u64 v_c50 = v_const6bc0ba365ada70df115e1785;
      u64 v_c51 = v_consta8180db1c2f300980314f910;
      u64 v_c52 = v_constd5f017533ea574d5f9b3400c;
      u64 v_c55 = v_const0f8748be649f8ee4066bb1d7;
      u64 v_c53 = v_const9a67f28c6b77e842f439a84a;
      u64 v_c56 = v_const990b444cbd47632035b2fa1a;
      u64 v_c57 = v_const4f84f41d89b6b717419b4eaa;
      u64 v_c54 = v_conste58dec6bca6f63ef79c3b755;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex1044, std::array<u64,2>{v_c50, 0}, [&](const std::array<u64,2>& m1142) {
        u64 v_c58 = m1142[1];
        if (!slog::exists_probe<2,1>(refindex1045, std::array<u64,2>{v_c54, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1046, std::array<u64,3>{v_c54, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1047, std::array<u64,2>{v_c53, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1048, std::array<u64,2>{v_c49, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1049, std::array<u64,3>{v_c53, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1050, std::array<u64,2>{v_c55, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1051, std::array<u64,3>{v_c55, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex1052, std::array<u64,3>{v_c58, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1053, std::array<u64,2>{v_c57, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1054, std::array<u64,3>{v_c57, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1055, std::array<u64,2>{v_c56, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1056, std::array<u64,3>{v_c56, 0, 0})) return;
        slog::join_probe<2,1>(refindex1057, std::array<u64,2>{v_c52, 0}, [&](const std::array<u64,2>& m1143) {
          u64 v_c61 = m1143[1];
          if (!slog::exists_probe<3,1>(appindex1058, std::array<u64,3>{v_c61, 0, 0})) return;
          slog::join_probe<2,1>(refindex1059, std::array<u64,2>{v_c54, 0}, [&](const std::array<u64,2>& m1144) {
            u64 v_c59 = m1144[1];
            slog::join_probe<3,2>(lambdaindex1060, std::array<u64,3>{v_c54, v_c59, 0}, [&](const std::array<u64,3>& m1145) {
              u64 v_c60 = m1145[2];
              slog::join_probe<2,1>(refindex1061, std::array<u64,2>{v_c53, 0}, [&](const std::array<u64,2>& m1146) {
                u64 v_c62 = m1146[1];
                if (!slog::exists_probe<3,1>(appindex1062, std::array<u64,3>{v_c62, 0, 0})) return;
                slog::join_probe<2,1>(refindex1063, std::array<u64,2>{v_c49, 0}, [&](const std::array<u64,2>& m1147) {
                  u64 v_c63 = m1147[1];
                  slog::join_probe<3,2>(appindex1064, std::array<u64,3>{v_c63, v_c62, 0}, [&](const std::array<u64,3>& m1148) {
                    u64 v_c64 = m1148[2];
                    slog::join_probe<3,2>(lambdaindex1065, std::array<u64,3>{v_c53, v_c64, 0}, [&](const std::array<u64,3>& m1149) {
                      u64 v_c65 = m1149[2];
                      slog::join_probe<2,1>(refindex1066, std::array<u64,2>{v_c55, 0}, [&](const std::array<u64,2>& m1150) {
                        u64 v_c66 = m1150[1];
                        slog::join_probe<3,2>(lambdaindex1067, std::array<u64,3>{v_c55, v_c66, 0}, [&](const std::array<u64,3>& m1151) {
                          u64 v_c67 = m1151[2];
                          slog::join_probe<3,2>(appindex1068, std::array<u64,3>{v_c58, v_c67, 0}, [&](const std::array<u64,3>& m1152) {
                            u64 v_c68 = m1152[2];
                            slog::join_probe<2,1>(refindex1069, std::array<u64,2>{v_c57, 0}, [&](const std::array<u64,2>& m1153) {
                              u64 v_c69 = m1153[1];
                              slog::join_probe<3,2>(lambdaindex1070, std::array<u64,3>{v_c57, v_c69, 0}, [&](const std::array<u64,3>& m1154) {
                                u64 v_c70 = m1154[2];
                                slog::join_probe<3,2>(lambdaindex1071, std::array<u64,3>{v_c55, v_c70, 0}, [&](const std::array<u64,3>& m1155) {
                                  u64 v_c71 = m1155[2];
                                  slog::join_probe<2,1>(refindex1072, std::array<u64,2>{v_c56, 0}, [&](const std::array<u64,2>& m1156) {
                                    u64 v_c73 = m1156[1];
                                    slog::join_probe<3,2>(lambdaindex1073, std::array<u64,3>{v_c56, v_c73, 0}, [&](const std::array<u64,3>& m1157) {
                                      u64 v_c74 = m1157[2];
                                      slog::join_probe<3,2>(appindex1074, std::array<u64,3>{v_c61, v_c74, 0}, [&](const std::array<u64,3>& m1158) {
                                        u64 v_c75 = m1158[2];
                                        ++_fires;
                                        slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c52, v_c75}, std::array<u16,3>{1, 2, 0});
                                        slog::emit_struct_checked<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c58, v_c71}, std::array<u16,3>{1, 2, 0});
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
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:241", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask1075(db,b));
  // (crule (pre (let __tconst7sqz226 const7b8fd91ee9ff10cfbb8066bf) (let __tconst1EUj230 const615ad01b1c532bb6634df115) (let __tconst4N2q248 constaaaad65142343c54348db5d0) (let __tconst2VuQ234 const4492fd5fa4baacfebd29f5e5) (let __tconst4Sko246 consteb793a6f75d6cfe49d3c2c90) (let __tconst2x2f244 consta32d5a443def48e6d64c6f4b)) (scan app __t9bBp251 __t5pZU250 __t5ryk231) (body (exists ref (1 0) 1 __tconst1EUj230) (exists ref (1 0) 1 __tconst7sqz226) (exists lambda (1 2 0) 1 __tconst7sqz226) (exists ref (1 0) 1 __tconst2VuQ234) (exists lambda (1 2 0) 1 __tconst2VuQ234) (exists lambda (1 2 0) 1 __tconst4N2q248) (exists lambda (1 2 0) 1 __tconst4Sko246) (exists lambda (1 2 0) 1 __tconst2x2f244) (exists ref (1 0) 1 __tconst2x2f244) (exists ref (1 0) 1 __tconst4N2q248) (exists ref (1 0) 1 __tconst4Sko246) (join lambda (0 1 2) 2 __t5ryk231 __tconst1EUj230 __t3WVP229) (join ref (0 1) 2 __t3WVP229 __tconst1EUj230) (join ref (1 0) 1 __tconst7sqz226 __t5APF225) (join lambda (1 2 0) 2 __tconst7sqz226 __t5APF225 __t2BAX227) (join ref (1 0) 1 __tconst2VuQ234 __t2PLq233) (join lambda (1 2 0) 2 __tconst2VuQ234 __t2PLq233 __t45rU235) (join app (2 0 1) 2 __t45rU235 __t5pZU250 __t5uyC249) (join lambda (0 1 2) 2 __t5uyC249 __tconst4N2q248 __t7yz1247) (join lambda (0 1 2) 2 __t7yz1247 __tconst4Sko246 __t3laZ245) (join lambda (0 1 2) 2 __t3laZ245 __tconst2x2f244 __t5h6K243) (join ref (1 0) 1 __tconst2x2f244 __t3pbc237) (join app (2 0 1) 2 __t3pbc237 __t5h6K243 __t4wvK242) (join ref (1 0) 1 __tconst4N2q248 __t6KL4241) (join app (0 1 2) 2 __t4wvK242 __t6KL4241 __t16jv239) (join ref (0 1) 2 __t16jv239 __tconst4Sko246)) (head (mkstruct app (1 2 0) __t7iVu252 __t9bBp251 __t2BAX227)) mcfa-counting.slog:272 #f)
  class ReadTask1185 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex1159;  slog::Index** refindex1160;  slog::Index** lambdaindex1161;  slog::Index** refindex1162;  slog::Index** lambdaindex1163;  slog::Index** lambdaindex1164;  slog::Index** lambdaindex1165;  slog::Index** lambdaindex1166;  slog::Index** refindex1167;  slog::Index** refindex1168;  slog::Index** refindex1169;  slog::Index** lambdaindex1170;  slog::Index** refindex1171;  slog::Index** refindex1172;  slog::Index** lambdaindex1173;  slog::Index** refindex1174;  slog::Index** lambdaindex1175;  slog::Index** appindex1176;  slog::Index** lambdaindex1177;  slog::Index** lambdaindex1178;  slog::Index** lambdaindex1179;  slog::Index** refindex1180;  slog::Index** appindex1181;  slog::Index** refindex1182;  slog::Index** appindex1183;  slog::Index** refindex1184;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      outer_rel = db->getRelation("app");
      std::vector<u16> ord1186({1, 0});
      slog::Relation* readrel1187 = db->getRelation("ref");
      refindex1159 = readrel1187->getIndex(ord1186, false);
      std::vector<u16> ord1188({1, 0});
      slog::Relation* readrel1189 = db->getRelation("ref");
      refindex1160 = readrel1189->getIndex(ord1188, false);
      std::vector<u16> ord1190({1, 2, 0});
      slog::Relation* readrel1191 = db->getRelation("lambda");
      lambdaindex1161 = readrel1191->getIndex(ord1190, false);
      std::vector<u16> ord1192({1, 0});
      slog::Relation* readrel1193 = db->getRelation("ref");
      refindex1162 = readrel1193->getIndex(ord1192, false);
      std::vector<u16> ord1194({1, 2, 0});
      slog::Relation* readrel1195 = db->getRelation("lambda");
      lambdaindex1163 = readrel1195->getIndex(ord1194, false);
      std::vector<u16> ord1196({1, 2, 0});
      slog::Relation* readrel1197 = db->getRelation("lambda");
      lambdaindex1164 = readrel1197->getIndex(ord1196, false);
      std::vector<u16> ord1198({1, 2, 0});
      slog::Relation* readrel1199 = db->getRelation("lambda");
      lambdaindex1165 = readrel1199->getIndex(ord1198, false);
      std::vector<u16> ord1200({1, 2, 0});
      slog::Relation* readrel1201 = db->getRelation("lambda");
      lambdaindex1166 = readrel1201->getIndex(ord1200, false);
      std::vector<u16> ord1202({1, 0});
      slog::Relation* readrel1203 = db->getRelation("ref");
      refindex1167 = readrel1203->getIndex(ord1202, false);
      std::vector<u16> ord1204({1, 0});
      slog::Relation* readrel1205 = db->getRelation("ref");
      refindex1168 = readrel1205->getIndex(ord1204, false);
      std::vector<u16> ord1206({1, 0});
      slog::Relation* readrel1207 = db->getRelation("ref");
      refindex1169 = readrel1207->getIndex(ord1206, false);
      std::vector<u16> ord1208({0, 1, 2});
      slog::Relation* readrel1209 = db->getRelation("lambda");
      lambdaindex1170 = readrel1209->getIndex(ord1208, false);
      std::vector<u16> ord1210({0, 1});
      slog::Relation* readrel1211 = db->getRelation("ref");
      refindex1171 = readrel1211->getIndex(ord1210, false);
      std::vector<u16> ord1212({1, 0});
      slog::Relation* readrel1213 = db->getRelation("ref");
      refindex1172 = readrel1213->getIndex(ord1212, false);
      std::vector<u16> ord1214({1, 2, 0});
      slog::Relation* readrel1215 = db->getRelation("lambda");
      lambdaindex1173 = readrel1215->getIndex(ord1214, false);
      std::vector<u16> ord1216({1, 0});
      slog::Relation* readrel1217 = db->getRelation("ref");
      refindex1174 = readrel1217->getIndex(ord1216, false);
      std::vector<u16> ord1218({1, 2, 0});
      slog::Relation* readrel1219 = db->getRelation("lambda");
      lambdaindex1175 = readrel1219->getIndex(ord1218, false);
      std::vector<u16> ord1220({2, 0, 1});
      slog::Relation* readrel1221 = db->getRelation("app");
      appindex1176 = readrel1221->getIndex(ord1220, false);
      std::vector<u16> ord1222({0, 1, 2});
      slog::Relation* readrel1223 = db->getRelation("lambda");
      lambdaindex1177 = readrel1223->getIndex(ord1222, false);
      std::vector<u16> ord1224({0, 1, 2});
      slog::Relation* readrel1225 = db->getRelation("lambda");
      lambdaindex1178 = readrel1225->getIndex(ord1224, false);
      std::vector<u16> ord1226({0, 1, 2});
      slog::Relation* readrel1227 = db->getRelation("lambda");
      lambdaindex1179 = readrel1227->getIndex(ord1226, false);
      std::vector<u16> ord1228({1, 0});
      slog::Relation* readrel1229 = db->getRelation("ref");
      refindex1180 = readrel1229->getIndex(ord1228, false);
      std::vector<u16> ord1230({2, 0, 1});
      slog::Relation* readrel1231 = db->getRelation("app");
      appindex1181 = readrel1231->getIndex(ord1230, false);
      std::vector<u16> ord1232({1, 0});
      slog::Relation* readrel1233 = db->getRelation("ref");
      refindex1182 = readrel1233->getIndex(ord1232, false);
      std::vector<u16> ord1234({0, 1, 2});
      slog::Relation* readrel1235 = db->getRelation("app");
      appindex1183 = readrel1235->getIndex(ord1234, false);
      std::vector<u16> ord1236({0, 1});
      slog::Relation* readrel1237 = db->getRelation("ref");
      refindex1184 = readrel1237->getIndex(ord1236, false);
  
    }
    ReadTask1185(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c142 = v_const7b8fd91ee9ff10cfbb8066bf;
      u64 v_c143 = v_const615ad01b1c532bb6634df115;
      u64 v_c144 = v_constaaaad65142343c54348db5d0;
      u64 v_c145 = v_const4492fd5fa4baacfebd29f5e5;
      u64 v_c146 = v_consteb793a6f75d6cfe49d3c2c90;
      u64 v_c147 = v_consta32d5a443def48e6d64c6f4b;
  
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
        u64 v_c150 = _t[2];
        if (!slog::exists_probe<2,1>(refindex1159, std::array<u64,2>{v_c143, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1160, std::array<u64,2>{v_c142, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1161, std::array<u64,3>{v_c142, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1162, std::array<u64,2>{v_c145, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1163, std::array<u64,3>{v_c145, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1164, std::array<u64,3>{v_c144, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1165, std::array<u64,3>{v_c146, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1166, std::array<u64,3>{v_c147, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1167, std::array<u64,2>{v_c147, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1168, std::array<u64,2>{v_c144, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1169, std::array<u64,2>{v_c146, 0})) return;
        slog::join_probe<3,2>(lambdaindex1170, std::array<u64,3>{v_c150, v_c143, 0}, [&](const std::array<u64,3>& m1238) {
          u64 v_c151 = m1238[2];
          slog::join_probe<2,2>(refindex1171, std::array<u64,2>{v_c151, v_c143}, [&](const std::array<u64,2>& m1239) {
            slog::join_probe<2,1>(refindex1172, std::array<u64,2>{v_c142, 0}, [&](const std::array<u64,2>& m1240) {
              u64 v_c152 = m1240[1];
              slog::join_probe<3,2>(lambdaindex1173, std::array<u64,3>{v_c142, v_c152, 0}, [&](const std::array<u64,3>& m1241) {
                u64 v_c153 = m1241[2];
                slog::join_probe<2,1>(refindex1174, std::array<u64,2>{v_c145, 0}, [&](const std::array<u64,2>& m1242) {
                  u64 v_c154 = m1242[1];
                  slog::join_probe<3,2>(lambdaindex1175, std::array<u64,3>{v_c145, v_c154, 0}, [&](const std::array<u64,3>& m1243) {
                    u64 v_c155 = m1243[2];
                    slog::join_probe<3,2>(appindex1176, std::array<u64,3>{v_c155, v_c149, 0}, [&](const std::array<u64,3>& m1244) {
                      u64 v_c156 = m1244[2];
                      slog::join_probe<3,2>(lambdaindex1177, std::array<u64,3>{v_c156, v_c144, 0}, [&](const std::array<u64,3>& m1245) {
                        u64 v_c157 = m1245[2];
                        slog::join_probe<3,2>(lambdaindex1178, std::array<u64,3>{v_c157, v_c146, 0}, [&](const std::array<u64,3>& m1246) {
                          u64 v_c158 = m1246[2];
                          slog::join_probe<3,2>(lambdaindex1179, std::array<u64,3>{v_c158, v_c147, 0}, [&](const std::array<u64,3>& m1247) {
                            u64 v_c159 = m1247[2];
                            slog::join_probe<2,1>(refindex1180, std::array<u64,2>{v_c147, 0}, [&](const std::array<u64,2>& m1248) {
                              u64 v_c160 = m1248[1];
                              slog::join_probe<3,2>(appindex1181, std::array<u64,3>{v_c160, v_c159, 0}, [&](const std::array<u64,3>& m1249) {
                                u64 v_c161 = m1249[2];
                                slog::join_probe<2,1>(refindex1182, std::array<u64,2>{v_c144, 0}, [&](const std::array<u64,2>& m1250) {
                                  u64 v_c162 = m1250[1];
                                  slog::join_probe<3,2>(appindex1183, std::array<u64,3>{v_c161, v_c162, 0}, [&](const std::array<u64,3>& m1251) {
                                    u64 v_c163 = m1251[2];
                                    slog::join_probe<2,2>(refindex1184, std::array<u64,2>{v_c163, v_c146}, [&](const std::array<u64,2>& m1252) {
                                      ++_fires;
                                      slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c148, v_c153}, std::array<u16,3>{1, 2, 0});
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
  
      if (_fires) db->bumpFires("mcfa-counting.slog:272", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask1185* _cont = new ReadTask1185(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1185(db,b), false);
  // (crule (pre (let __tconst7JVW192 const6cf13cc59dcbe759113f68a4) (let __tconst7B9N190 constcaa3ee5a2828a31924f6b39d) (let __tconst5wC2180 const970c20ea81b833e5b5a7accf) (let __tconst2ady176 constc40f204dda7ba4054abb9e74)) (probe ref (1 0) 1 __tconst2ady176 __t3ZY4175) (body (exists ref (1 0) 1 __tconst7B9N190) (exists ref (1 0) 1 __tconst7JVW192) (join ref (1 0) 1 __tconst5wC2180 __t52sB179) (join ref (1 0) 1 __tconst7B9N190 __t8oRJ183) (join ref (1 0) 1 __tconst7JVW192 __t6fOY185)) (head (mkstruct app (1 2 0) __t2CTd186 __t6fOY185 __t8oRJ183) (mkstruct lambda (1 2 0) __t6CST181 __tconst5wC2180 __t52sB179) (mkstruct lambda (1 2 0) __t1Ls4177 __tconst2ady176 __t3ZY4175)) mcfa-counting.slog:301 #f)
  class ReadTask1258 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** refindex1253;  slog::Index** refindex1254;  slog::Index** refindex1255;  slog::Index** refindex1256;  slog::Index** refindex1257;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      head_rel[1] = db->getRelation("lambda");
      head_rel[2] = db->getRelation("lambda");
      std::vector<u16> ord1259({1, 0});
      slog::Relation* readrel1260 = db->getRelation("ref");
      driver_index = readrel1260->getIndex(ord1259, true);
      std::vector<u16> ord1261({1, 0});
      slog::Relation* readrel1262 = db->getRelation("ref");
      refindex1253 = readrel1262->getIndex(ord1261, false);
      std::vector<u16> ord1263({1, 0});
      slog::Relation* readrel1264 = db->getRelation("ref");
      refindex1254 = readrel1264->getIndex(ord1263, false);
      std::vector<u16> ord1265({1, 0});
      slog::Relation* readrel1266 = db->getRelation("ref");
      refindex1255 = readrel1266->getIndex(ord1265, false);
      std::vector<u16> ord1267({1, 0});
      slog::Relation* readrel1268 = db->getRelation("ref");
      refindex1256 = readrel1268->getIndex(ord1267, false);
      std::vector<u16> ord1269({1, 0});
      slog::Relation* readrel1270 = db->getRelation("ref");
      refindex1257 = readrel1270->getIndex(ord1269, false);
  
    }
    ReadTask1258(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const6cf13cc59dcbe759113f68a4;
      u64 v_c1 = v_constcaa3ee5a2828a31924f6b39d;
      u64 v_c2 = v_const970c20ea81b833e5b5a7accf;
      u64 v_c3 = v_constc40f204dda7ba4054abb9e74;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c3, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m1271) {
        u64 v_c5 = m1271[1];
        if (buckethash(v_c5) != bucket) return;
        if (!slog::exists_probe<2,1>(refindex1253, std::array<u64,2>{v_c1, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1254, std::array<u64,2>{v_c0, 0})) return;
        slog::join_probe<2,1>(refindex1255, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m1272) {
          u64 v_c7 = m1272[1];
          slog::join_probe<2,1>(refindex1256, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m1273) {
            u64 v_c9 = m1273[1];
            slog::join_probe<2,1>(refindex1257, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m1274) {
              u64 v_c4 = m1274[1];
              ++_fires;
              slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c4, v_c9}, std::array<u16,3>{1, 2, 0});
              slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c2, v_c7}, std::array<u16,3>{1, 2, 0});
              slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c3, v_c5}, std::array<u16,3>{1, 2, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:301", "delta:ref", _fires);
  
      if (!_done)
      {
        ReadTask1258* _cont = new ReadTask1258(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1258(db,b), false);
  // (crule (pre (let __tconst9zoW125 const7c7d2cfc66f4d976987d2d20) (let __tconst4V4L122 const6bc0ba365ada70df115e1785) (let __tconst4Zcr91 const9a67f28c6b77e842f439a84a) (let __tconst0vRf84 conste58dec6bca6f63ef79c3b755) (let __tconst82U8119 consta8180db1c2f300980314f910) (let __tconst4BKz104 const0f8748be649f8ee4066bb1d7) (let __tconst3wDH116 constd5f017533ea574d5f9b3400c) (let __tconst3ktF111 const990b444cbd47632035b2fa1a) (let __tconst5nWJ102 const4f84f41d89b6b717419b4eaa)) (seeded) (body (join ref (1 0) 1 __tconst0vRf84 __t2duR83) (exists ref (1 0) 1 __tconst4V4L122) (exists ref (1 0) 1 __tconst4Zcr91) (exists ref (1 0) 1 __tconst9zoW125) (exists lambda (1 2 0) 1 __tconst4Zcr91) (exists ref (1 0) 1 __tconst4BKz104) (exists lambda (1 2 0) 1 __tconst4BKz104) (exists ref (1 0) 1 __tconst3wDH116) (exists ref (1 0) 1 __tconst5nWJ102) (exists lambda (1 2 0) 1 __tconst5nWJ102) (exists ref (1 0) 1 __tconst3ktF111) (exists lambda (1 2 0) 1 __tconst3ktF111) (exists lambda (1 2 0) 1 __tconst3wDH116) (exists lambda (1 2 0) 1 __tconst82U8119) (exists lambda (1 2 0) 1 __tconst4V4L122) (join lambda (1 2 0) 2 __tconst0vRf84 __t2duR83 __t87vL85) (join ref (1 0) 1 __tconst4V4L122 __t7aew98) (exists app (1 2 0) 1 __t7aew98) (join ref (1 0) 1 __tconst4Zcr91 __t0C9F87) (exists app (2 0 1) 1 __t0C9F87) (join ref (1 0) 1 __tconst9zoW125 __t3Q2G89) (join app (1 2 0) 2 __t3Q2G89 __t0C9F87 __t2Eqd90) (join lambda (1 2 0) 2 __tconst4Zcr91 __t2Eqd90 __t3pgm92) (join ref (1 0) 1 __tconst4BKz104 __t8C0a94) (join lambda (1 2 0) 2 __tconst4BKz104 __t8C0a94 __t4fDK96) (join app (1 2 0) 2 __t7aew98 __t4fDK96 __t7TEO99) (exists app (2 0 1) 1 __t7TEO99) (join ref (1 0) 1 __tconst3wDH116 __t3wir114) (exists app (1 2 0) 1 __t3wir114) (join ref (1 0) 1 __tconst5nWJ102 __t5MaG101) (join lambda (1 2 0) 2 __tconst5nWJ102 __t5MaG101 __t35jA103) (join lambda (1 2 0) 2 __tconst4BKz104 __t35jA103 __t6RuY105) (join app (1 2 0) 2 __t7aew98 __t6RuY105 __t2Z7m108) (exists app (2 0 1) 1 __t2Z7m108) (join ref (1 0) 1 __tconst3ktF111 __t7ohz110) (join lambda (1 2 0) 2 __tconst3ktF111 __t7ohz110 __t8GWA112) (join app (1 2 0) 2 __t3wir114 __t8GWA112 __t44OM115) (join lambda (1 2 0) 2 __tconst3wDH116 __t44OM115 __t7CwH117) (join app (1 2 0) 2 __t7CwH117 __t2Z7m108 __t50Kk118) (join lambda (1 2 0) 2 __tconst82U8119 __t50Kk118 __t3SEs120) (join app (1 2 0) 2 __t3SEs120 __t7TEO99 __t1GdP121) (join lambda (1 2 0) 2 __tconst4V4L122 __t1GdP121 __t5iMg123)) (head (mkstruct app (1 2 0) __t3cyj124 __t5iMg123 __t3pgm92)) mcfa-counting.slog:241 #f)
  class ReadTask1317 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex1275;  slog::Index** refindex1276;  slog::Index** refindex1277;  slog::Index** refindex1278;  slog::Index** lambdaindex1279;  slog::Index** refindex1280;  slog::Index** lambdaindex1281;  slog::Index** refindex1282;  slog::Index** refindex1283;  slog::Index** lambdaindex1284;  slog::Index** refindex1285;  slog::Index** lambdaindex1286;  slog::Index** lambdaindex1287;  slog::Index** lambdaindex1288;  slog::Index** lambdaindex1289;  slog::Index** lambdaindex1290;  slog::Index** refindex1291;  slog::Index** appindex1292;  slog::Index** refindex1293;  slog::Index** appindex1294;  slog::Index** refindex1295;  slog::Index** appindex1296;  slog::Index** lambdaindex1297;  slog::Index** refindex1298;  slog::Index** lambdaindex1299;  slog::Index** appindex1300;  slog::Index** appindex1301;  slog::Index** refindex1302;  slog::Index** appindex1303;  slog::Index** refindex1304;  slog::Index** lambdaindex1305;  slog::Index** lambdaindex1306;  slog::Index** appindex1307;  slog::Index** appindex1308;  slog::Index** refindex1309;  slog::Index** lambdaindex1310;  slog::Index** appindex1311;  slog::Index** lambdaindex1312;  slog::Index** appindex1313;  slog::Index** lambdaindex1314;  slog::Index** appindex1315;  slog::Index** lambdaindex1316;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord1318({1, 2, 0});
      slog::Relation* readrel1319 = db->getRelation("app");
      head_index[0] = readrel1319->getIndex(ord1318, false);
      std::vector<u16> ord1320({1, 0});
      slog::Relation* readrel1321 = db->getRelation("ref");
      refindex1275 = readrel1321->getIndex(ord1320, false);
      std::vector<u16> ord1322({1, 0});
      slog::Relation* readrel1323 = db->getRelation("ref");
      refindex1276 = readrel1323->getIndex(ord1322, false);
      std::vector<u16> ord1324({1, 0});
      slog::Relation* readrel1325 = db->getRelation("ref");
      refindex1277 = readrel1325->getIndex(ord1324, false);
      std::vector<u16> ord1326({1, 0});
      slog::Relation* readrel1327 = db->getRelation("ref");
      refindex1278 = readrel1327->getIndex(ord1326, false);
      std::vector<u16> ord1328({1, 2, 0});
      slog::Relation* readrel1329 = db->getRelation("lambda");
      lambdaindex1279 = readrel1329->getIndex(ord1328, false);
      std::vector<u16> ord1330({1, 0});
      slog::Relation* readrel1331 = db->getRelation("ref");
      refindex1280 = readrel1331->getIndex(ord1330, false);
      std::vector<u16> ord1332({1, 2, 0});
      slog::Relation* readrel1333 = db->getRelation("lambda");
      lambdaindex1281 = readrel1333->getIndex(ord1332, false);
      std::vector<u16> ord1334({1, 0});
      slog::Relation* readrel1335 = db->getRelation("ref");
      refindex1282 = readrel1335->getIndex(ord1334, false);
      std::vector<u16> ord1336({1, 0});
      slog::Relation* readrel1337 = db->getRelation("ref");
      refindex1283 = readrel1337->getIndex(ord1336, false);
      std::vector<u16> ord1338({1, 2, 0});
      slog::Relation* readrel1339 = db->getRelation("lambda");
      lambdaindex1284 = readrel1339->getIndex(ord1338, false);
      std::vector<u16> ord1340({1, 0});
      slog::Relation* readrel1341 = db->getRelation("ref");
      refindex1285 = readrel1341->getIndex(ord1340, false);
      std::vector<u16> ord1342({1, 2, 0});
      slog::Relation* readrel1343 = db->getRelation("lambda");
      lambdaindex1286 = readrel1343->getIndex(ord1342, false);
      std::vector<u16> ord1344({1, 2, 0});
      slog::Relation* readrel1345 = db->getRelation("lambda");
      lambdaindex1287 = readrel1345->getIndex(ord1344, false);
      std::vector<u16> ord1346({1, 2, 0});
      slog::Relation* readrel1347 = db->getRelation("lambda");
      lambdaindex1288 = readrel1347->getIndex(ord1346, false);
      std::vector<u16> ord1348({1, 2, 0});
      slog::Relation* readrel1349 = db->getRelation("lambda");
      lambdaindex1289 = readrel1349->getIndex(ord1348, false);
      std::vector<u16> ord1350({1, 2, 0});
      slog::Relation* readrel1351 = db->getRelation("lambda");
      lambdaindex1290 = readrel1351->getIndex(ord1350, false);
      std::vector<u16> ord1352({1, 0});
      slog::Relation* readrel1353 = db->getRelation("ref");
      refindex1291 = readrel1353->getIndex(ord1352, false);
      std::vector<u16> ord1354({1, 2, 0});
      slog::Relation* readrel1355 = db->getRelation("app");
      appindex1292 = readrel1355->getIndex(ord1354, false);
      std::vector<u16> ord1356({1, 0});
      slog::Relation* readrel1357 = db->getRelation("ref");
      refindex1293 = readrel1357->getIndex(ord1356, false);
      std::vector<u16> ord1358({2, 0, 1});
      slog::Relation* readrel1359 = db->getRelation("app");
      appindex1294 = readrel1359->getIndex(ord1358, false);
      std::vector<u16> ord1360({1, 0});
      slog::Relation* readrel1361 = db->getRelation("ref");
      refindex1295 = readrel1361->getIndex(ord1360, false);
      std::vector<u16> ord1362({1, 2, 0});
      slog::Relation* readrel1363 = db->getRelation("app");
      appindex1296 = readrel1363->getIndex(ord1362, false);
      std::vector<u16> ord1364({1, 2, 0});
      slog::Relation* readrel1365 = db->getRelation("lambda");
      lambdaindex1297 = readrel1365->getIndex(ord1364, false);
      std::vector<u16> ord1366({1, 0});
      slog::Relation* readrel1367 = db->getRelation("ref");
      refindex1298 = readrel1367->getIndex(ord1366, false);
      std::vector<u16> ord1368({1, 2, 0});
      slog::Relation* readrel1369 = db->getRelation("lambda");
      lambdaindex1299 = readrel1369->getIndex(ord1368, false);
      std::vector<u16> ord1370({1, 2, 0});
      slog::Relation* readrel1371 = db->getRelation("app");
      appindex1300 = readrel1371->getIndex(ord1370, false);
      std::vector<u16> ord1372({2, 0, 1});
      slog::Relation* readrel1373 = db->getRelation("app");
      appindex1301 = readrel1373->getIndex(ord1372, false);
      std::vector<u16> ord1374({1, 0});
      slog::Relation* readrel1375 = db->getRelation("ref");
      refindex1302 = readrel1375->getIndex(ord1374, false);
      std::vector<u16> ord1376({1, 2, 0});
      slog::Relation* readrel1377 = db->getRelation("app");
      appindex1303 = readrel1377->getIndex(ord1376, false);
      std::vector<u16> ord1378({1, 0});
      slog::Relation* readrel1379 = db->getRelation("ref");
      refindex1304 = readrel1379->getIndex(ord1378, false);
      std::vector<u16> ord1380({1, 2, 0});
      slog::Relation* readrel1381 = db->getRelation("lambda");
      lambdaindex1305 = readrel1381->getIndex(ord1380, false);
      std::vector<u16> ord1382({1, 2, 0});
      slog::Relation* readrel1383 = db->getRelation("lambda");
      lambdaindex1306 = readrel1383->getIndex(ord1382, false);
      std::vector<u16> ord1384({1, 2, 0});
      slog::Relation* readrel1385 = db->getRelation("app");
      appindex1307 = readrel1385->getIndex(ord1384, false);
      std::vector<u16> ord1386({2, 0, 1});
      slog::Relation* readrel1387 = db->getRelation("app");
      appindex1308 = readrel1387->getIndex(ord1386, false);
      std::vector<u16> ord1388({1, 0});
      slog::Relation* readrel1389 = db->getRelation("ref");
      refindex1309 = readrel1389->getIndex(ord1388, false);
      std::vector<u16> ord1390({1, 2, 0});
      slog::Relation* readrel1391 = db->getRelation("lambda");
      lambdaindex1310 = readrel1391->getIndex(ord1390, false);
      std::vector<u16> ord1392({1, 2, 0});
      slog::Relation* readrel1393 = db->getRelation("app");
      appindex1311 = readrel1393->getIndex(ord1392, false);
      std::vector<u16> ord1394({1, 2, 0});
      slog::Relation* readrel1395 = db->getRelation("lambda");
      lambdaindex1312 = readrel1395->getIndex(ord1394, false);
      std::vector<u16> ord1396({1, 2, 0});
      slog::Relation* readrel1397 = db->getRelation("app");
      appindex1313 = readrel1397->getIndex(ord1396, false);
      std::vector<u16> ord1398({1, 2, 0});
      slog::Relation* readrel1399 = db->getRelation("lambda");
      lambdaindex1314 = readrel1399->getIndex(ord1398, false);
      std::vector<u16> ord1400({1, 2, 0});
      slog::Relation* readrel1401 = db->getRelation("app");
      appindex1315 = readrel1401->getIndex(ord1400, false);
      std::vector<u16> ord1402({1, 2, 0});
      slog::Relation* readrel1403 = db->getRelation("lambda");
      lambdaindex1316 = readrel1403->getIndex(ord1402, false);
  
    }
    ReadTask1317(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c49 = v_const7c7d2cfc66f4d976987d2d20;
      u64 v_c50 = v_const6bc0ba365ada70df115e1785;
      u64 v_c53 = v_const9a67f28c6b77e842f439a84a;
      u64 v_c54 = v_conste58dec6bca6f63ef79c3b755;
      u64 v_c51 = v_consta8180db1c2f300980314f910;
      u64 v_c55 = v_const0f8748be649f8ee4066bb1d7;
      u64 v_c52 = v_constd5f017533ea574d5f9b3400c;
      u64 v_c56 = v_const990b444cbd47632035b2fa1a;
      u64 v_c57 = v_const4f84f41d89b6b717419b4eaa;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex1275, std::array<u64,2>{v_c54, 0}, [&](const std::array<u64,2>& m1404) {
        u64 v_c59 = m1404[1];
        if (!slog::exists_probe<2,1>(refindex1276, std::array<u64,2>{v_c50, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1277, std::array<u64,2>{v_c53, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1278, std::array<u64,2>{v_c49, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1279, std::array<u64,3>{v_c53, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1280, std::array<u64,2>{v_c55, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1281, std::array<u64,3>{v_c55, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1282, std::array<u64,2>{v_c52, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1283, std::array<u64,2>{v_c57, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1284, std::array<u64,3>{v_c57, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1285, std::array<u64,2>{v_c56, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1286, std::array<u64,3>{v_c56, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1287, std::array<u64,3>{v_c52, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1288, std::array<u64,3>{v_c51, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1289, std::array<u64,3>{v_c50, 0, 0})) return;
        slog::join_probe<3,2>(lambdaindex1290, std::array<u64,3>{v_c54, v_c59, 0}, [&](const std::array<u64,3>& m1405) {
          u64 v_c60 = m1405[2];
          slog::join_probe<2,1>(refindex1291, std::array<u64,2>{v_c50, 0}, [&](const std::array<u64,2>& m1406) {
            u64 v_c58 = m1406[1];
            if (!slog::exists_probe<3,1>(appindex1292, std::array<u64,3>{v_c58, 0, 0})) return;
            slog::join_probe<2,1>(refindex1293, std::array<u64,2>{v_c53, 0}, [&](const std::array<u64,2>& m1407) {
              u64 v_c62 = m1407[1];
              if (!slog::exists_probe<3,1>(appindex1294, std::array<u64,3>{v_c62, 0, 0})) return;
              slog::join_probe<2,1>(refindex1295, std::array<u64,2>{v_c49, 0}, [&](const std::array<u64,2>& m1408) {
                u64 v_c63 = m1408[1];
                slog::join_probe<3,2>(appindex1296, std::array<u64,3>{v_c63, v_c62, 0}, [&](const std::array<u64,3>& m1409) {
                  u64 v_c64 = m1409[2];
                  slog::join_probe<3,2>(lambdaindex1297, std::array<u64,3>{v_c53, v_c64, 0}, [&](const std::array<u64,3>& m1410) {
                    u64 v_c65 = m1410[2];
                    slog::join_probe<2,1>(refindex1298, std::array<u64,2>{v_c55, 0}, [&](const std::array<u64,2>& m1411) {
                      u64 v_c66 = m1411[1];
                      slog::join_probe<3,2>(lambdaindex1299, std::array<u64,3>{v_c55, v_c66, 0}, [&](const std::array<u64,3>& m1412) {
                        u64 v_c67 = m1412[2];
                        slog::join_probe<3,2>(appindex1300, std::array<u64,3>{v_c58, v_c67, 0}, [&](const std::array<u64,3>& m1413) {
                          u64 v_c68 = m1413[2];
                          if (!slog::exists_probe<3,1>(appindex1301, std::array<u64,3>{v_c68, 0, 0})) return;
                          slog::join_probe<2,1>(refindex1302, std::array<u64,2>{v_c52, 0}, [&](const std::array<u64,2>& m1414) {
                            u64 v_c61 = m1414[1];
                            if (!slog::exists_probe<3,1>(appindex1303, std::array<u64,3>{v_c61, 0, 0})) return;
                            slog::join_probe<2,1>(refindex1304, std::array<u64,2>{v_c57, 0}, [&](const std::array<u64,2>& m1415) {
                              u64 v_c69 = m1415[1];
                              slog::join_probe<3,2>(lambdaindex1305, std::array<u64,3>{v_c57, v_c69, 0}, [&](const std::array<u64,3>& m1416) {
                                u64 v_c70 = m1416[2];
                                slog::join_probe<3,2>(lambdaindex1306, std::array<u64,3>{v_c55, v_c70, 0}, [&](const std::array<u64,3>& m1417) {
                                  u64 v_c71 = m1417[2];
                                  slog::join_probe<3,2>(appindex1307, std::array<u64,3>{v_c58, v_c71, 0}, [&](const std::array<u64,3>& m1418) {
                                    u64 v_c72 = m1418[2];
                                    if (!slog::exists_probe<3,1>(appindex1308, std::array<u64,3>{v_c72, 0, 0})) return;
                                    slog::join_probe<2,1>(refindex1309, std::array<u64,2>{v_c56, 0}, [&](const std::array<u64,2>& m1419) {
                                      u64 v_c73 = m1419[1];
                                      slog::join_probe<3,2>(lambdaindex1310, std::array<u64,3>{v_c56, v_c73, 0}, [&](const std::array<u64,3>& m1420) {
                                        u64 v_c74 = m1420[2];
                                        slog::join_probe<3,2>(appindex1311, std::array<u64,3>{v_c61, v_c74, 0}, [&](const std::array<u64,3>& m1421) {
                                          u64 v_c75 = m1421[2];
                                          slog::join_probe<3,2>(lambdaindex1312, std::array<u64,3>{v_c52, v_c75, 0}, [&](const std::array<u64,3>& m1422) {
                                            u64 v_c76 = m1422[2];
                                            slog::join_probe<3,2>(appindex1313, std::array<u64,3>{v_c76, v_c72, 0}, [&](const std::array<u64,3>& m1423) {
                                              u64 v_c77 = m1423[2];
                                              slog::join_probe<3,2>(lambdaindex1314, std::array<u64,3>{v_c51, v_c77, 0}, [&](const std::array<u64,3>& m1424) {
                                                u64 v_c164 = m1424[2];
                                                slog::join_probe<3,2>(appindex1315, std::array<u64,3>{v_c164, v_c68, 0}, [&](const std::array<u64,3>& m1425) {
                                                  u64 v_c165 = m1425[2];
                                                  slog::join_probe<3,2>(lambdaindex1316, std::array<u64,3>{v_c50, v_c165, 0}, [&](const std::array<u64,3>& m1426) {
                                                    u64 v_c166 = m1426[2];
                                                    ++_fires;
                                                    slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c166, v_c65}, std::array<u16,3>{1, 2, 0});
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
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:241", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask1317(db,b));
  // (crule (pre) (scan lambda __t3DWB162 x eb) (body (join freevar (1 0) 1 __t3DWB162 y) (join store (0 1 2) 1 y cb vy) (join-old eval (0 2 1) 0 (0 2 1) __9gNV361 c __t0neE161) (join-old app (0 1 2) 1 (0 1 2) __t0neE161 ef ea)) (head (mkstruct eval (1 2 0) __1Zia362 ef c)) mcfa-counting.slog:102 #f)
  class ReadTask1433 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** freevarindex1427;  slog::Index** storeindex1428;  slog::Index** evalindex1429;  slog::Index** appindex1430;  slog::Index** evaldelta1431;  slog::Index** appdelta1432;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("lambda");
      std::vector<u16> ord1434({1, 0});
      slog::Relation* readrel1435 = db->getRelation("freevar");
      freevarindex1427 = readrel1435->getIndex(ord1434, false);
      std::vector<u16> ord1436({0, 1, 2});
      slog::Relation* readrel1437 = db->getRelation("store");
      storeindex1428 = readrel1437->getIndex(ord1436, false);
      std::vector<u16> ord1438({0, 2, 1});
      slog::Relation* readrel1439 = db->getRelation("eval");
      evalindex1429 = readrel1439->getIndex(ord1438, false);
      std::vector<u16> ord1440({0, 2, 1});
      slog::Relation* readrel1441 = db->getRelation("eval");
      evaldelta1431 = readrel1441->getIndex(ord1440, true);
      std::vector<u16> ord1442({0, 1, 2});
      slog::Relation* readrel1443 = db->getRelation("app");
      appindex1430 = readrel1443->getIndex(ord1442, false);
      std::vector<u16> ord1444({0, 1, 2});
      slog::Relation* readrel1445 = db->getRelation("app");
      appdelta1432 = readrel1445->getIndex(ord1444, true);
  
    }
    ReadTask1433(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c21 = _t[1];
        u64 v_c19 = _t[2];
        slog::join_probe<2,1>(freevarindex1427, std::array<u64,2>{v_c167, 0}, [&](const std::array<u64,2>& m1446) {
          u64 v_c133 = m1446[1];
          slog::join_probe<3,1>(storeindex1428, std::array<u64,3>{v_c133, 0, 0}, [&](const std::array<u64,3>& m1447) {
            u64 v_c18 = m1447[1]; u64 v_c135 = m1447[2];
            slog::join_all_old<3>(evalindex1429, evaldelta1431, [&](const std::array<u64,3>& m1448) {
              u64 v_c168 = m1448[0]; u64 v_c13 = m1448[1]; u64 v_c169 = m1448[2];
              slog::join_probe_old<3,1>(appindex1430, appdelta1432, std::array<u64,3>{v_c169, 0, 0}, [&](const std::array<u64,3>& m1449) {
                u64 v_c15 = m1449[1]; u64 v_c14 = m1449[2];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c15, v_c13}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:102", "delta:lambda", _fires);
  
      if (!_done)
      {
        ReadTask1433* _cont = new ReadTask1433(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1433(db,b), false);
  // (crule (pre (let __tconst8xRt151 const3a82152bd1402931076fe2d7) (let __tconst0zC2144 const4e3b5454cf93e32fad90650d) (let __tconst3Taj142 constdc1bb6655fb38bdb032e3754) (let __tconst8eg8132 const361d5df359e0d7681220d09d)) (probe ref (1 0) 1 __tconst8eg8132 __t19JM131) (body (exists ref (1 0) 1 __tconst0zC2144) (exists ref (1 0) 1 __tconst8xRt151) (join ref (1 0) 1 __tconst3Taj142 __t93Xi135) (join ref (1 0) 1 __tconst0zC2144 __t7VSc137) (join ref (1 0) 1 __tconst8xRt151 __t1g2P147)) (head (mkstruct app (1 2 0) __t9UZN150 __t1g2P147 __t1g2P147) (mkstruct app (1 2 0) __t8dYW140 __t7VSc137 __t7VSc137) (mkstruct lambda (1 2 0) __t4DXA133 __tconst8eg8132 __t19JM131)) mcfa-counting.slog:224 #f)
  class ReadTask1455 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** refindex1450;  slog::Index** refindex1451;  slog::Index** refindex1452;  slog::Index** refindex1453;  slog::Index** refindex1454;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      head_rel[1] = db->getRelation("app");
      head_rel[2] = db->getRelation("lambda");
      std::vector<u16> ord1456({1, 0});
      slog::Relation* readrel1457 = db->getRelation("ref");
      driver_index = readrel1457->getIndex(ord1456, true);
      std::vector<u16> ord1458({1, 0});
      slog::Relation* readrel1459 = db->getRelation("ref");
      refindex1450 = readrel1459->getIndex(ord1458, false);
      std::vector<u16> ord1460({1, 0});
      slog::Relation* readrel1461 = db->getRelation("ref");
      refindex1451 = readrel1461->getIndex(ord1460, false);
      std::vector<u16> ord1462({1, 0});
      slog::Relation* readrel1463 = db->getRelation("ref");
      refindex1452 = readrel1463->getIndex(ord1462, false);
      std::vector<u16> ord1464({1, 0});
      slog::Relation* readrel1465 = db->getRelation("ref");
      refindex1453 = readrel1465->getIndex(ord1464, false);
      std::vector<u16> ord1466({1, 0});
      slog::Relation* readrel1467 = db->getRelation("ref");
      refindex1454 = readrel1467->getIndex(ord1466, false);
  
    }
    ReadTask1455(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c116 = v_const3a82152bd1402931076fe2d7;
      u64 v_c115 = v_const4e3b5454cf93e32fad90650d;
      u64 v_c118 = v_constdc1bb6655fb38bdb032e3754;
      u64 v_c117 = v_const361d5df359e0d7681220d09d;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c117, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m1468) {
        u64 v_c125 = m1468[1];
        if (buckethash(v_c125) != bucket) return;
        if (!slog::exists_probe<2,1>(refindex1450, std::array<u64,2>{v_c115, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1451, std::array<u64,2>{v_c116, 0})) return;
        slog::join_probe<2,1>(refindex1452, std::array<u64,2>{v_c118, 0}, [&](const std::array<u64,2>& m1469) {
          u64 v_c129 = m1469[1];
          slog::join_probe<2,1>(refindex1453, std::array<u64,2>{v_c115, 0}, [&](const std::array<u64,2>& m1470) {
            u64 v_c131 = m1470[1];
            slog::join_probe<2,1>(refindex1454, std::array<u64,2>{v_c116, 0}, [&](const std::array<u64,2>& m1471) {
              u64 v_c127 = m1471[1];
              ++_fires;
              slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c127, v_c127}, std::array<u16,3>{1, 2, 0});
              slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c131, v_c131}, std::array<u16,3>{1, 2, 0});
              slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c117, v_c125}, std::array<u16,3>{1, 2, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:224", "delta:ref", _fires);
  
      if (!_done)
      {
        ReadTask1455* _cont = new ReadTask1455(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1455(db,b), false);
  // (crule (pre) (scan freevar x ef) (body (join-old app (1 2 0) 1 (1 2 0) ef ea __t2veU155)) (head (emit freevar (0 1) x __t2veU155)) freevars.slog:13 #f)
  class ReadTask1474 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex1472;  slog::Index** appdelta1473;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("freevar");
      std::vector<u16> ord1475({0, 1});
      slog::Relation* readrel1476 = db->getRelation("freevar");
      head_index[0] = readrel1476->getIndex(ord1475, false);
      outer_rel = db->getRelation("freevar");
      std::vector<u16> ord1477({1, 2, 0});
      slog::Relation* readrel1478 = db->getRelation("app");
      appindex1472 = readrel1478->getIndex(ord1477, false);
      std::vector<u16> ord1479({1, 2, 0});
      slog::Relation* readrel1480 = db->getRelation("app");
      appdelta1473 = readrel1480->getIndex(ord1479, true);
  
    }
    ReadTask1474(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c21 = _t[0];
        u64 v_c15 = _t[1];
        slog::join_probe_old<3,1>(appindex1472, appdelta1473, std::array<u64,3>{v_c15, 0, 0}, [&](const std::array<u64,3>& m1481) {
          u64 v_c14 = m1481[1]; u64 v_c170 = m1481[2];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c21, v_c170}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:13", "delta:freevar", _fires);
  
      if (!_done)
      {
        ReadTask1474* _cont = new ReadTask1474(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1474(db,b), false);
  // (crule (pre (let __tconst1pJW313 constb49bea2fcccd8f4301a347ed) (let __tconst7LWP310 const66518c0c1b3a5a0b09ae2ef1) (let __tconst0sqO307 const4a8acfc71441e0695ffcf5b3) (let __tconst2CSv302 const229c0b7aa8a7eb4055f5a3d0) (let __tconst9rZO295 const576506f61f53440f1edd95d2) (let __tconst5PoN291 constc85eae03730a4f4cf1d66a0c) (let __tconst2Yzp284 const8ca682693a0738a0641c6956)) (once) (body) (head (mkstruct ref (1 0) __t6lXa301 __tconst2CSv302) (mkstruct ref (1 0) __t91H2298 __tconst7LWP310) (mkstruct ref (1 0) __t71w7294 __tconst9rZO295) (mkstruct ref (1 0) __t165O287 __tconst1pJW313) (mkstruct ref (1 0) __t248W283 __tconst2Yzp284)) mcfa-counting.slog:194 #f)
  class ReadTask1482 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[5];
    slog::Index** head_index[5];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ref");
      head_rel[1] = db->getRelation("ref");
      head_rel[2] = db->getRelation("ref");
      head_rel[3] = db->getRelation("ref");
      head_rel[4] = db->getRelation("ref");
  
    }
    ReadTask1482(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c89 = v_constb49bea2fcccd8f4301a347ed;
      u64 v_c91 = v_const66518c0c1b3a5a0b09ae2ef1;
      u64 v_c93 = v_const4a8acfc71441e0695ffcf5b3;
      u64 v_c95 = v_const229c0b7aa8a7eb4055f5a3d0;
      u64 v_c94 = v_const576506f61f53440f1edd95d2;
      u64 v_c92 = v_constc85eae03730a4f4cf1d66a0c;
      u64 v_c90 = v_const8ca682693a0738a0641c6956;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[5];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
      newbatch[4] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c95}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c91}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[2], newbatch[2], std::array<u64,1>{v_c94}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[3], newbatch[3], std::array<u64,1>{v_c89}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[4], newbatch[4], std::array<u64,1>{v_c90}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:194", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask1482(db,b), true);
  // (crule (pre (let __tconst4N2q248 constaaaad65142343c54348db5d0) (let __tconst4Sko246 consteb793a6f75d6cfe49d3c2c90) (let __tconst7sqz226 const7b8fd91ee9ff10cfbb8066bf) (let __tconst1EUj230 const615ad01b1c532bb6634df115) (let __tconst2VuQ234 const4492fd5fa4baacfebd29f5e5) (let __tconst2x2f244 consta32d5a443def48e6d64c6f4b)) (seeded) (body (join ref (1 0) 1 __tconst2VuQ234 __t2PLq233) (exists ref (1 0) 1 __tconst1EUj230) (exists lambda (1 2 0) 1 __tconst1EUj230) (exists ref (1 0) 1 __tconst7sqz226) (exists lambda (1 2 0) 1 __tconst7sqz226) (exists ref (1 0) 1 __tconst2x2f244) (exists ref (1 0) 1 __tconst4N2q248) (exists ref (1 0) 1 __tconst4Sko246) (exists lambda (1 2 0) 1 __tconst2x2f244) (exists lambda (1 2 0) 1 __tconst4Sko246) (exists lambda (1 2 0) 1 __tconst4N2q248) (join lambda (1 2 0) 2 __tconst2VuQ234 __t2PLq233 __t45rU235) (join ref (1 0) 1 __tconst1EUj230 __t3WVP229) (join lambda (1 2 0) 2 __tconst1EUj230 __t3WVP229 __t5ryk231) (join ref (1 0) 1 __tconst7sqz226 __t5APF225) (join lambda (1 2 0) 2 __tconst7sqz226 __t5APF225 __t2BAX227) (join ref (1 0) 1 __tconst2x2f244 __t3pbc237) (exists app (2 0 1) 1 __t3pbc237) (join ref (1 0) 1 __tconst4N2q248 __t6KL4241) (exists app (1 2 0) 1 __t6KL4241) (join ref (1 0) 1 __tconst4Sko246 __t16jv239) (join app (1 2 0) 2 __t6KL4241 __t16jv239 __t4wvK242) (join app (1 2 0) 2 __t4wvK242 __t3pbc237 __t5h6K243) (join lambda (1 2 0) 2 __tconst2x2f244 __t5h6K243 __t3laZ245) (join lambda (1 2 0) 2 __tconst4Sko246 __t3laZ245 __t7yz1247) (join lambda (1 2 0) 2 __tconst4N2q248 __t7yz1247 __t5uyC249)) (head (mkstruct app (1 2 0) __t5pZU250 __t5uyC249 __t45rU235)) mcfa-counting.slog:272 #f)
  class ReadTask1509 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex1483;  slog::Index** refindex1484;  slog::Index** lambdaindex1485;  slog::Index** refindex1486;  slog::Index** lambdaindex1487;  slog::Index** refindex1488;  slog::Index** refindex1489;  slog::Index** refindex1490;  slog::Index** lambdaindex1491;  slog::Index** lambdaindex1492;  slog::Index** lambdaindex1493;  slog::Index** lambdaindex1494;  slog::Index** refindex1495;  slog::Index** lambdaindex1496;  slog::Index** refindex1497;  slog::Index** lambdaindex1498;  slog::Index** refindex1499;  slog::Index** appindex1500;  slog::Index** refindex1501;  slog::Index** appindex1502;  slog::Index** refindex1503;  slog::Index** appindex1504;  slog::Index** appindex1505;  slog::Index** lambdaindex1506;  slog::Index** lambdaindex1507;  slog::Index** lambdaindex1508;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord1510({1, 2, 0});
      slog::Relation* readrel1511 = db->getRelation("app");
      head_index[0] = readrel1511->getIndex(ord1510, false);
      std::vector<u16> ord1512({1, 0});
      slog::Relation* readrel1513 = db->getRelation("ref");
      refindex1483 = readrel1513->getIndex(ord1512, false);
      std::vector<u16> ord1514({1, 0});
      slog::Relation* readrel1515 = db->getRelation("ref");
      refindex1484 = readrel1515->getIndex(ord1514, false);
      std::vector<u16> ord1516({1, 2, 0});
      slog::Relation* readrel1517 = db->getRelation("lambda");
      lambdaindex1485 = readrel1517->getIndex(ord1516, false);
      std::vector<u16> ord1518({1, 0});
      slog::Relation* readrel1519 = db->getRelation("ref");
      refindex1486 = readrel1519->getIndex(ord1518, false);
      std::vector<u16> ord1520({1, 2, 0});
      slog::Relation* readrel1521 = db->getRelation("lambda");
      lambdaindex1487 = readrel1521->getIndex(ord1520, false);
      std::vector<u16> ord1522({1, 0});
      slog::Relation* readrel1523 = db->getRelation("ref");
      refindex1488 = readrel1523->getIndex(ord1522, false);
      std::vector<u16> ord1524({1, 0});
      slog::Relation* readrel1525 = db->getRelation("ref");
      refindex1489 = readrel1525->getIndex(ord1524, false);
      std::vector<u16> ord1526({1, 0});
      slog::Relation* readrel1527 = db->getRelation("ref");
      refindex1490 = readrel1527->getIndex(ord1526, false);
      std::vector<u16> ord1528({1, 2, 0});
      slog::Relation* readrel1529 = db->getRelation("lambda");
      lambdaindex1491 = readrel1529->getIndex(ord1528, false);
      std::vector<u16> ord1530({1, 2, 0});
      slog::Relation* readrel1531 = db->getRelation("lambda");
      lambdaindex1492 = readrel1531->getIndex(ord1530, false);
      std::vector<u16> ord1532({1, 2, 0});
      slog::Relation* readrel1533 = db->getRelation("lambda");
      lambdaindex1493 = readrel1533->getIndex(ord1532, false);
      std::vector<u16> ord1534({1, 2, 0});
      slog::Relation* readrel1535 = db->getRelation("lambda");
      lambdaindex1494 = readrel1535->getIndex(ord1534, false);
      std::vector<u16> ord1536({1, 0});
      slog::Relation* readrel1537 = db->getRelation("ref");
      refindex1495 = readrel1537->getIndex(ord1536, false);
      std::vector<u16> ord1538({1, 2, 0});
      slog::Relation* readrel1539 = db->getRelation("lambda");
      lambdaindex1496 = readrel1539->getIndex(ord1538, false);
      std::vector<u16> ord1540({1, 0});
      slog::Relation* readrel1541 = db->getRelation("ref");
      refindex1497 = readrel1541->getIndex(ord1540, false);
      std::vector<u16> ord1542({1, 2, 0});
      slog::Relation* readrel1543 = db->getRelation("lambda");
      lambdaindex1498 = readrel1543->getIndex(ord1542, false);
      std::vector<u16> ord1544({1, 0});
      slog::Relation* readrel1545 = db->getRelation("ref");
      refindex1499 = readrel1545->getIndex(ord1544, false);
      std::vector<u16> ord1546({2, 0, 1});
      slog::Relation* readrel1547 = db->getRelation("app");
      appindex1500 = readrel1547->getIndex(ord1546, false);
      std::vector<u16> ord1548({1, 0});
      slog::Relation* readrel1549 = db->getRelation("ref");
      refindex1501 = readrel1549->getIndex(ord1548, false);
      std::vector<u16> ord1550({1, 2, 0});
      slog::Relation* readrel1551 = db->getRelation("app");
      appindex1502 = readrel1551->getIndex(ord1550, false);
      std::vector<u16> ord1552({1, 0});
      slog::Relation* readrel1553 = db->getRelation("ref");
      refindex1503 = readrel1553->getIndex(ord1552, false);
      std::vector<u16> ord1554({1, 2, 0});
      slog::Relation* readrel1555 = db->getRelation("app");
      appindex1504 = readrel1555->getIndex(ord1554, false);
      std::vector<u16> ord1556({1, 2, 0});
      slog::Relation* readrel1557 = db->getRelation("app");
      appindex1505 = readrel1557->getIndex(ord1556, false);
      std::vector<u16> ord1558({1, 2, 0});
      slog::Relation* readrel1559 = db->getRelation("lambda");
      lambdaindex1506 = readrel1559->getIndex(ord1558, false);
      std::vector<u16> ord1560({1, 2, 0});
      slog::Relation* readrel1561 = db->getRelation("lambda");
      lambdaindex1507 = readrel1561->getIndex(ord1560, false);
      std::vector<u16> ord1562({1, 2, 0});
      slog::Relation* readrel1563 = db->getRelation("lambda");
      lambdaindex1508 = readrel1563->getIndex(ord1562, false);
  
    }
    ReadTask1509(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c144 = v_constaaaad65142343c54348db5d0;
      u64 v_c146 = v_consteb793a6f75d6cfe49d3c2c90;
      u64 v_c142 = v_const7b8fd91ee9ff10cfbb8066bf;
      u64 v_c143 = v_const615ad01b1c532bb6634df115;
      u64 v_c145 = v_const4492fd5fa4baacfebd29f5e5;
      u64 v_c147 = v_consta32d5a443def48e6d64c6f4b;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex1483, std::array<u64,2>{v_c145, 0}, [&](const std::array<u64,2>& m1564) {
        u64 v_c154 = m1564[1];
        if (!slog::exists_probe<2,1>(refindex1484, std::array<u64,2>{v_c143, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1485, std::array<u64,3>{v_c143, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1486, std::array<u64,2>{v_c142, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1487, std::array<u64,3>{v_c142, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1488, std::array<u64,2>{v_c147, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1489, std::array<u64,2>{v_c144, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1490, std::array<u64,2>{v_c146, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1491, std::array<u64,3>{v_c147, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1492, std::array<u64,3>{v_c146, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1493, std::array<u64,3>{v_c144, 0, 0})) return;
        slog::join_probe<3,2>(lambdaindex1494, std::array<u64,3>{v_c145, v_c154, 0}, [&](const std::array<u64,3>& m1565) {
          u64 v_c155 = m1565[2];
          slog::join_probe<2,1>(refindex1495, std::array<u64,2>{v_c143, 0}, [&](const std::array<u64,2>& m1566) {
            u64 v_c151 = m1566[1];
            slog::join_probe<3,2>(lambdaindex1496, std::array<u64,3>{v_c143, v_c151, 0}, [&](const std::array<u64,3>& m1567) {
              u64 v_c150 = m1567[2];
              slog::join_probe<2,1>(refindex1497, std::array<u64,2>{v_c142, 0}, [&](const std::array<u64,2>& m1568) {
                u64 v_c152 = m1568[1];
                slog::join_probe<3,2>(lambdaindex1498, std::array<u64,3>{v_c142, v_c152, 0}, [&](const std::array<u64,3>& m1569) {
                  u64 v_c153 = m1569[2];
                  slog::join_probe<2,1>(refindex1499, std::array<u64,2>{v_c147, 0}, [&](const std::array<u64,2>& m1570) {
                    u64 v_c160 = m1570[1];
                    if (!slog::exists_probe<3,1>(appindex1500, std::array<u64,3>{v_c160, 0, 0})) return;
                    slog::join_probe<2,1>(refindex1501, std::array<u64,2>{v_c144, 0}, [&](const std::array<u64,2>& m1571) {
                      u64 v_c162 = m1571[1];
                      if (!slog::exists_probe<3,1>(appindex1502, std::array<u64,3>{v_c162, 0, 0})) return;
                      slog::join_probe<2,1>(refindex1503, std::array<u64,2>{v_c146, 0}, [&](const std::array<u64,2>& m1572) {
                        u64 v_c163 = m1572[1];
                        slog::join_probe<3,2>(appindex1504, std::array<u64,3>{v_c162, v_c163, 0}, [&](const std::array<u64,3>& m1573) {
                          u64 v_c161 = m1573[2];
                          slog::join_probe<3,2>(appindex1505, std::array<u64,3>{v_c161, v_c160, 0}, [&](const std::array<u64,3>& m1574) {
                            u64 v_c159 = m1574[2];
                            slog::join_probe<3,2>(lambdaindex1506, std::array<u64,3>{v_c147, v_c159, 0}, [&](const std::array<u64,3>& m1575) {
                              u64 v_c158 = m1575[2];
                              slog::join_probe<3,2>(lambdaindex1507, std::array<u64,3>{v_c146, v_c158, 0}, [&](const std::array<u64,3>& m1576) {
                                u64 v_c157 = m1576[2];
                                slog::join_probe<3,2>(lambdaindex1508, std::array<u64,3>{v_c144, v_c157, 0}, [&](const std::array<u64,3>& m1577) {
                                  u64 v_c156 = m1577[2];
                                  ++_fires;
                                  slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c156, v_c155}, std::array<u16,3>{1, 2, 0});
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
  
      if (_fires) db->bumpFires("mcfa-counting.slog:272", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask1509(db,b));
  // (crule (pre (let __tconst1pJW313 constb49bea2fcccd8f4301a347ed) (let __tconst7LWP310 const66518c0c1b3a5a0b09ae2ef1) (let __tconst5PoN291 constc85eae03730a4f4cf1d66a0c) (let __tconst2Yzp284 const8ca682693a0738a0641c6956) (let __tconst0sqO307 const4a8acfc71441e0695ffcf5b3) (let __tconst9rZO295 const576506f61f53440f1edd95d2) (let __tconst2CSv302 const229c0b7aa8a7eb4055f5a3d0)) (probe lambda (1 2 0) 1 __tconst7LWP310 __t6t9L309 __t5T0g311) (body (exists lambda (1 2 0) 1 __tconst2Yzp284) (exists ref (1 0) 1 __tconst7LWP310) (exists ref (1 0) 1 __tconst1pJW313) (exists ref (1 0) 1 __tconst9rZO295) (exists lambda (1 2 0) 1 __tconst9rZO295) (exists lambda (1 2 0) 1 __tconst0sqO307) (exists lambda (1 2 0) 1 __tconst2CSv302) (exists ref (1 0) 1 __tconst2CSv302) (exists lambda (1 2 0) 1 __tconst5PoN291) (join ref (1 0) 1 __tconst2Yzp284 __t248W283) (join lambda (1 2 0) 2 __tconst2Yzp284 __t248W283 __t0oFu285) (join ref (1 0) 1 __tconst7LWP310 __t91H2298) (exists app (1 2 0) 1 __t91H2298) (join ref (1 0) 1 __tconst1pJW313 __t165O287) (exists app (1 2 0) 1 __t165O287) (join ref (1 0) 1 __tconst9rZO295 __t71w7294) (join lambda (1 2 0) 2 __tconst9rZO295 __t71w7294 __t3dkk296) (join app (1 2 0) 2 __t91H2298 __t3dkk296 __t4LtH299) (join app (2 0 1) 2 __t4LtH299 __t6t9L309 __t0vn1308) (join lambda (0 1 2) 2 __t0vn1308 __tconst0sqO307 __t4HUX306) (join app (0 1 2) 2 __t4HUX306 __t91H2298 __t7EW2303) (join lambda (0 1 2) 2 __t7EW2303 __tconst2CSv302 __t6lXa301) (join ref (0 1) 2 __t6lXa301 __tconst2CSv302) (join app (1 2 0) 1 __t165O287 dup0IQf383 __t30Ec290) (eq __t165O287 dup0IQf383) (join lambda (1 2 0) 2 __tconst5PoN291 __t30Ec290 __t7aCZ292)) (head (mkstruct app (1 2 0) __t3Izn312 __t5T0g311 __t7aCZ292)) mcfa-counting.slog:194 #f)
  class ReadTask1603 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** lambdaindex1578;  slog::Index** refindex1579;  slog::Index** refindex1580;  slog::Index** refindex1581;  slog::Index** lambdaindex1582;  slog::Index** lambdaindex1583;  slog::Index** lambdaindex1584;  slog::Index** refindex1585;  slog::Index** lambdaindex1586;  slog::Index** refindex1587;  slog::Index** lambdaindex1588;  slog::Index** refindex1589;  slog::Index** appindex1590;  slog::Index** refindex1591;  slog::Index** appindex1592;  slog::Index** refindex1593;  slog::Index** lambdaindex1594;  slog::Index** appindex1595;  slog::Index** appindex1596;  slog::Index** lambdaindex1597;  slog::Index** appindex1598;  slog::Index** lambdaindex1599;  slog::Index** refindex1600;  slog::Index** appindex1601;  slog::Index** lambdaindex1602;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord1604({1, 2, 0});
      slog::Relation* readrel1605 = db->getRelation("lambda");
      driver_index = readrel1605->getIndex(ord1604, true);
      std::vector<u16> ord1606({1, 2, 0});
      slog::Relation* readrel1607 = db->getRelation("lambda");
      lambdaindex1578 = readrel1607->getIndex(ord1606, false);
      std::vector<u16> ord1608({1, 0});
      slog::Relation* readrel1609 = db->getRelation("ref");
      refindex1579 = readrel1609->getIndex(ord1608, false);
      std::vector<u16> ord1610({1, 0});
      slog::Relation* readrel1611 = db->getRelation("ref");
      refindex1580 = readrel1611->getIndex(ord1610, false);
      std::vector<u16> ord1612({1, 0});
      slog::Relation* readrel1613 = db->getRelation("ref");
      refindex1581 = readrel1613->getIndex(ord1612, false);
      std::vector<u16> ord1614({1, 2, 0});
      slog::Relation* readrel1615 = db->getRelation("lambda");
      lambdaindex1582 = readrel1615->getIndex(ord1614, false);
      std::vector<u16> ord1616({1, 2, 0});
      slog::Relation* readrel1617 = db->getRelation("lambda");
      lambdaindex1583 = readrel1617->getIndex(ord1616, false);
      std::vector<u16> ord1618({1, 2, 0});
      slog::Relation* readrel1619 = db->getRelation("lambda");
      lambdaindex1584 = readrel1619->getIndex(ord1618, false);
      std::vector<u16> ord1620({1, 0});
      slog::Relation* readrel1621 = db->getRelation("ref");
      refindex1585 = readrel1621->getIndex(ord1620, false);
      std::vector<u16> ord1622({1, 2, 0});
      slog::Relation* readrel1623 = db->getRelation("lambda");
      lambdaindex1586 = readrel1623->getIndex(ord1622, false);
      std::vector<u16> ord1624({1, 0});
      slog::Relation* readrel1625 = db->getRelation("ref");
      refindex1587 = readrel1625->getIndex(ord1624, false);
      std::vector<u16> ord1626({1, 2, 0});
      slog::Relation* readrel1627 = db->getRelation("lambda");
      lambdaindex1588 = readrel1627->getIndex(ord1626, false);
      std::vector<u16> ord1628({1, 0});
      slog::Relation* readrel1629 = db->getRelation("ref");
      refindex1589 = readrel1629->getIndex(ord1628, false);
      std::vector<u16> ord1630({1, 2, 0});
      slog::Relation* readrel1631 = db->getRelation("app");
      appindex1590 = readrel1631->getIndex(ord1630, false);
      std::vector<u16> ord1632({1, 0});
      slog::Relation* readrel1633 = db->getRelation("ref");
      refindex1591 = readrel1633->getIndex(ord1632, false);
      std::vector<u16> ord1634({1, 2, 0});
      slog::Relation* readrel1635 = db->getRelation("app");
      appindex1592 = readrel1635->getIndex(ord1634, false);
      std::vector<u16> ord1636({1, 0});
      slog::Relation* readrel1637 = db->getRelation("ref");
      refindex1593 = readrel1637->getIndex(ord1636, false);
      std::vector<u16> ord1638({1, 2, 0});
      slog::Relation* readrel1639 = db->getRelation("lambda");
      lambdaindex1594 = readrel1639->getIndex(ord1638, false);
      std::vector<u16> ord1640({1, 2, 0});
      slog::Relation* readrel1641 = db->getRelation("app");
      appindex1595 = readrel1641->getIndex(ord1640, false);
      std::vector<u16> ord1642({2, 0, 1});
      slog::Relation* readrel1643 = db->getRelation("app");
      appindex1596 = readrel1643->getIndex(ord1642, false);
      std::vector<u16> ord1644({0, 1, 2});
      slog::Relation* readrel1645 = db->getRelation("lambda");
      lambdaindex1597 = readrel1645->getIndex(ord1644, false);
      std::vector<u16> ord1646({0, 1, 2});
      slog::Relation* readrel1647 = db->getRelation("app");
      appindex1598 = readrel1647->getIndex(ord1646, false);
      std::vector<u16> ord1648({0, 1, 2});
      slog::Relation* readrel1649 = db->getRelation("lambda");
      lambdaindex1599 = readrel1649->getIndex(ord1648, false);
      std::vector<u16> ord1650({0, 1});
      slog::Relation* readrel1651 = db->getRelation("ref");
      refindex1600 = readrel1651->getIndex(ord1650, false);
      std::vector<u16> ord1652({1, 2, 0});
      slog::Relation* readrel1653 = db->getRelation("app");
      appindex1601 = readrel1653->getIndex(ord1652, false);
      std::vector<u16> ord1654({1, 2, 0});
      slog::Relation* readrel1655 = db->getRelation("lambda");
      lambdaindex1602 = readrel1655->getIndex(ord1654, false);
  
    }
    ReadTask1603(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c89 = v_constb49bea2fcccd8f4301a347ed;
      u64 v_c91 = v_const66518c0c1b3a5a0b09ae2ef1;
      u64 v_c92 = v_constc85eae03730a4f4cf1d66a0c;
      u64 v_c90 = v_const8ca682693a0738a0641c6956;
      u64 v_c93 = v_const4a8acfc71441e0695ffcf5b3;
      u64 v_c94 = v_const576506f61f53440f1edd95d2;
      u64 v_c95 = v_const229c0b7aa8a7eb4055f5a3d0;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c91, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1656) {
        u64 v_c107 = m1656[1];
        u64 v_c108 = m1656[2];
        if (buckethash(v_c107) != bucket) return;
        if (!slog::exists_probe<3,1>(lambdaindex1578, std::array<u64,3>{v_c90, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1579, std::array<u64,2>{v_c91, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1580, std::array<u64,2>{v_c89, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1581, std::array<u64,2>{v_c94, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1582, std::array<u64,3>{v_c94, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1583, std::array<u64,3>{v_c93, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1584, std::array<u64,3>{v_c95, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1585, std::array<u64,2>{v_c95, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1586, std::array<u64,3>{v_c92, 0, 0})) return;
        slog::join_probe<2,1>(refindex1587, std::array<u64,2>{v_c90, 0}, [&](const std::array<u64,2>& m1657) {
          u64 v_c96 = m1657[1];
          slog::join_probe<3,2>(lambdaindex1588, std::array<u64,3>{v_c90, v_c96, 0}, [&](const std::array<u64,3>& m1658) {
            u64 v_c97 = m1658[2];
            slog::join_probe<2,1>(refindex1589, std::array<u64,2>{v_c91, 0}, [&](const std::array<u64,2>& m1659) {
              u64 v_c99 = m1659[1];
              if (!slog::exists_probe<3,1>(appindex1590, std::array<u64,3>{v_c99, 0, 0})) return;
              slog::join_probe<2,1>(refindex1591, std::array<u64,2>{v_c89, 0}, [&](const std::array<u64,2>& m1660) {
                u64 v_c98 = m1660[1];
                if (!slog::exists_probe<3,1>(appindex1592, std::array<u64,3>{v_c98, 0, 0})) return;
                slog::join_probe<2,1>(refindex1593, std::array<u64,2>{v_c94, 0}, [&](const std::array<u64,2>& m1661) {
                  u64 v_c100 = m1661[1];
                  slog::join_probe<3,2>(lambdaindex1594, std::array<u64,3>{v_c94, v_c100, 0}, [&](const std::array<u64,3>& m1662) {
                    u64 v_c101 = m1662[2];
                    slog::join_probe<3,2>(appindex1595, std::array<u64,3>{v_c99, v_c101, 0}, [&](const std::array<u64,3>& m1663) {
                      u64 v_c102 = m1663[2];
                      slog::join_probe<3,2>(appindex1596, std::array<u64,3>{v_c102, v_c107, 0}, [&](const std::array<u64,3>& m1664) {
                        u64 v_c106 = m1664[2];
                        slog::join_probe<3,2>(lambdaindex1597, std::array<u64,3>{v_c106, v_c93, 0}, [&](const std::array<u64,3>& m1665) {
                          u64 v_c105 = m1665[2];
                          slog::join_probe<3,2>(appindex1598, std::array<u64,3>{v_c105, v_c99, 0}, [&](const std::array<u64,3>& m1666) {
                            u64 v_c104 = m1666[2];
                            slog::join_probe<3,2>(lambdaindex1599, std::array<u64,3>{v_c104, v_c95, 0}, [&](const std::array<u64,3>& m1667) {
                              u64 v_c103 = m1667[2];
                              slog::join_probe<2,2>(refindex1600, std::array<u64,2>{v_c103, v_c95}, [&](const std::array<u64,2>& m1668) {
                                slog::join_probe<3,1>(appindex1601, std::array<u64,3>{v_c98, 0, 0}, [&](const std::array<u64,3>& m1669) {
                                  u64 v_c171 = m1669[1]; u64 v_c110 = m1669[2];
                                  if (v_c98 != v_c171) return;
                                  slog::join_probe<3,2>(lambdaindex1602, std::array<u64,3>{v_c92, v_c110, 0}, [&](const std::array<u64,3>& m1670) {
                                    u64 v_c111 = m1670[2];
                                    ++_fires;
                                    slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c108, v_c111}, std::array<u16,3>{1, 2, 0});
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
  
      if (_fires) db->bumpFires("mcfa-counting.slog:194", "delta:lambda", _fires);
  
      if (!_done)
      {
        ReadTask1603* _cont = new ReadTask1603(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1603(db,b), false);
}

