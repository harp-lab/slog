
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const07ef7e8462f6d369d70a1f0e;
extern u64 v_const0aa6f87434af0222b916e97a;
extern u64 v_const0f8748be649f8ee4066bb1d7;
extern u64 v_const15bb62b8293a526ca6f0e4eb;
extern u64 v_const227d34ceeba7a29aada993d4;
extern u64 v_const229c0b7aa8a7eb4055f5a3d0;
extern u64 v_const361d5df359e0d7681220d09d;
extern u64 v_const3a82152bd1402931076fe2d7;
extern u64 v_const4492fd5fa4baacfebd29f5e5;
extern u64 v_const4a59dbb9cb3129dfcc75170b;
extern u64 v_const4a8acfc71441e0695ffcf5b3;
extern u64 v_const4d5ce1398140fbe27561181f;
extern u64 v_const4e3b5454cf93e32fad90650d;
extern u64 v_const4f84f41d89b6b717419b4eaa;
extern u64 v_const576506f61f53440f1edd95d2;
extern u64 v_const5950e3cb761734f52a881545;
extern u64 v_const59ba3256d223f0d0a00d0633;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const615ad01b1c532bb6634df115;
extern u64 v_const66518c0c1b3a5a0b09ae2ef1;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const6bc0ba365ada70df115e1785;
extern u64 v_const6cf13cc59dcbe759113f68a4;
extern u64 v_const77ceb5c0e9f84ebd84104a97;
extern u64 v_const7b8fd91ee9ff10cfbb8066bf;
extern u64 v_const7c7d2cfc66f4d976987d2d20;
extern u64 v_const7cd75b35aa30c3ddf04f9d57;
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
extern u64 v_constd3d07026d47882ceca728218;
extern u64 v_constd5f017533ea574d5f9b3400c;
extern u64 v_constd7a1925d249b4768c8a9f2d8;
extern u64 v_constdbf1bdba02122b2adce28528;
extern u64 v_constdc1bb6655fb38bdb032e3754;
extern u64 v_conste4a9e4d8baa71a9d8ebf56ec;
extern u64 v_conste58dec6bca6f63ef79c3b755;
extern u64 v_consteb793a6f75d6cfe49d3c2c90;
extern u64 v_constf700a82e218a86de572e1f7f;
extern u64 v_constfc9ee54e0ee8c6d1e715716c;


void slog_rules_c963a753083f78321(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre) (scan freevar x ea) (body (join-old app (2 0 1) 1 (2 0 1) ea __t8Cmz156 ef)) (head (emit freevar (0 1) x __t8Cmz156)) freevars.slog:13 #f)
  class ReadTask2 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex0;  slog::Index** appdelta1;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("freevar");
      std::vector<u16> ord3({0, 1});
      slog::Relation* readrel4 = db->getRelation("freevar");
      head_index[0] = readrel4->getIndex(ord3, false);
      outer_rel = db->getRelation("freevar");
      std::vector<u16> ord5({2, 0, 1});
      slog::Relation* readrel6 = db->getRelation("app");
      appindex0 = readrel6->getIndex(ord5, false);
      std::vector<u16> ord7({2, 0, 1});
      slog::Relation* readrel8 = db->getRelation("app");
      appdelta1 = readrel8->getIndex(ord7, true);
  
    }
    ReadTask2(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe_old<3,1>(appindex0, appdelta1, std::array<u64,3>{v_c1, 0, 0}, [&](const std::array<u64,3>& m9) {
          u64 v_c2 = m9[1]; u64 v_c3 = m9[2];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c0, v_c2}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:13", "delta:freevar", _fires);
  
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
  // (crule (pre (let __tconst0zC2144 const4e3b5454cf93e32fad90650d) (let __tconst3Taj142 constdc1bb6655fb38bdb032e3754) (let __tconst8xRt151 const3a82152bd1402931076fe2d7) (let __tconst8eg8132 const361d5df359e0d7681220d09d)) (seeded) (body (join ref (1 0) 1 __tconst3Taj142 __t93Xi135) (exists lambda (1 2 0) 1 __tconst8eg8132) (exists ref (1 0) 1 __tconst0zC2144) (exists ref (1 0) 1 __tconst8xRt151) (exists app (2 0 1) 1 __t93Xi135) (exists lambda (1 2 0) 1 __tconst3Taj142) (exists lambda (1 2 0) 1 __tconst8xRt151) (join ref (1 0) 1 __tconst8eg8132 __t19JM131) (join lambda (1 2 0) 2 __tconst8eg8132 __t19JM131 __t4DXA133) (join ref (1 0) 1 __tconst0zC2144 __t7VSc137) (exists app (1 2 0) 1 __t7VSc137) (join ref (1 0) 1 __tconst8xRt151 __t1g2P147) (exists app (1 2 0) 1 __t1g2P147) (join app (1 2 0) 1 __t7VSc137 dup3Ccy401 __t8dYW140) (eq __t7VSc137 dup3Ccy401) (join app (1 2 0) 2 __t8dYW140 __t93Xi135 __t25NQ141) (join lambda (1 2 0) 2 __tconst3Taj142 __t25NQ141 __t2Ce3143) (join app (1 2 0) 1 __t1g2P147 dup8xYT402 __t9UZN150) (eq __t1g2P147 dup8xYT402) (join lambda (1 2 0) 2 __tconst8xRt151 __t9UZN150 __t2nYy152)) (head (mkstruct lambda (1 2 0) __t6t5O145 __tconst0zC2144 __t2Ce3143)) mcfa-counting.slog:224 #f)
  class ReadTask28 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex10;  slog::Index** lambdaindex11;  slog::Index** refindex12;  slog::Index** refindex13;  slog::Index** appindex14;  slog::Index** lambdaindex15;  slog::Index** lambdaindex16;  slog::Index** refindex17;  slog::Index** lambdaindex18;  slog::Index** refindex19;  slog::Index** appindex20;  slog::Index** refindex21;  slog::Index** appindex22;  slog::Index** appindex23;  slog::Index** appindex24;  slog::Index** lambdaindex25;  slog::Index** appindex26;  slog::Index** lambdaindex27;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      std::vector<u16> ord29({1, 2, 0});
      slog::Relation* readrel30 = db->getRelation("lambda");
      head_index[0] = readrel30->getIndex(ord29, false);
      std::vector<u16> ord31({1, 0});
      slog::Relation* readrel32 = db->getRelation("ref");
      refindex10 = readrel32->getIndex(ord31, false);
      std::vector<u16> ord33({1, 2, 0});
      slog::Relation* readrel34 = db->getRelation("lambda");
      lambdaindex11 = readrel34->getIndex(ord33, false);
      std::vector<u16> ord35({1, 0});
      slog::Relation* readrel36 = db->getRelation("ref");
      refindex12 = readrel36->getIndex(ord35, false);
      std::vector<u16> ord37({1, 0});
      slog::Relation* readrel38 = db->getRelation("ref");
      refindex13 = readrel38->getIndex(ord37, false);
      std::vector<u16> ord39({2, 0, 1});
      slog::Relation* readrel40 = db->getRelation("app");
      appindex14 = readrel40->getIndex(ord39, false);
      std::vector<u16> ord41({1, 2, 0});
      slog::Relation* readrel42 = db->getRelation("lambda");
      lambdaindex15 = readrel42->getIndex(ord41, false);
      std::vector<u16> ord43({1, 2, 0});
      slog::Relation* readrel44 = db->getRelation("lambda");
      lambdaindex16 = readrel44->getIndex(ord43, false);
      std::vector<u16> ord45({1, 0});
      slog::Relation* readrel46 = db->getRelation("ref");
      refindex17 = readrel46->getIndex(ord45, false);
      std::vector<u16> ord47({1, 2, 0});
      slog::Relation* readrel48 = db->getRelation("lambda");
      lambdaindex18 = readrel48->getIndex(ord47, false);
      std::vector<u16> ord49({1, 0});
      slog::Relation* readrel50 = db->getRelation("ref");
      refindex19 = readrel50->getIndex(ord49, false);
      std::vector<u16> ord51({1, 2, 0});
      slog::Relation* readrel52 = db->getRelation("app");
      appindex20 = readrel52->getIndex(ord51, false);
      std::vector<u16> ord53({1, 0});
      slog::Relation* readrel54 = db->getRelation("ref");
      refindex21 = readrel54->getIndex(ord53, false);
      std::vector<u16> ord55({1, 2, 0});
      slog::Relation* readrel56 = db->getRelation("app");
      appindex22 = readrel56->getIndex(ord55, false);
      std::vector<u16> ord57({1, 2, 0});
      slog::Relation* readrel58 = db->getRelation("app");
      appindex23 = readrel58->getIndex(ord57, false);
      std::vector<u16> ord59({1, 2, 0});
      slog::Relation* readrel60 = db->getRelation("app");
      appindex24 = readrel60->getIndex(ord59, false);
      std::vector<u16> ord61({1, 2, 0});
      slog::Relation* readrel62 = db->getRelation("lambda");
      lambdaindex25 = readrel62->getIndex(ord61, false);
      std::vector<u16> ord63({1, 2, 0});
      slog::Relation* readrel64 = db->getRelation("app");
      appindex26 = readrel64->getIndex(ord63, false);
      std::vector<u16> ord65({1, 2, 0});
      slog::Relation* readrel66 = db->getRelation("lambda");
      lambdaindex27 = readrel66->getIndex(ord65, false);
  
    }
    ReadTask28(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c4 = v_const4e3b5454cf93e32fad90650d;
      u64 v_c5 = v_constdc1bb6655fb38bdb032e3754;
      u64 v_c6 = v_const3a82152bd1402931076fe2d7;
      u64 v_c7 = v_const361d5df359e0d7681220d09d;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex10, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m67) {
        u64 v_c8 = m67[1];
        if (!slog::exists_probe<3,1>(lambdaindex11, std::array<u64,3>{v_c7, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex12, std::array<u64,2>{v_c4, 0})) return;
        if (!slog::exists_probe<2,1>(refindex13, std::array<u64,2>{v_c6, 0})) return;
        if (!slog::exists_probe<3,1>(appindex14, std::array<u64,3>{v_c8, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex15, std::array<u64,3>{v_c5, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex16, std::array<u64,3>{v_c6, 0, 0})) return;
        slog::join_probe<2,1>(refindex17, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m68) {
          u64 v_c9 = m68[1];
          slog::join_probe<3,2>(lambdaindex18, std::array<u64,3>{v_c7, v_c9, 0}, [&](const std::array<u64,3>& m69) {
            u64 v_c10 = m69[2];
            slog::join_probe<2,1>(refindex19, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m70) {
              u64 v_c11 = m70[1];
              if (!slog::exists_probe<3,1>(appindex20, std::array<u64,3>{v_c11, 0, 0})) return;
              slog::join_probe<2,1>(refindex21, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m71) {
                u64 v_c12 = m71[1];
                if (!slog::exists_probe<3,1>(appindex22, std::array<u64,3>{v_c12, 0, 0})) return;
                slog::join_probe<3,1>(appindex23, std::array<u64,3>{v_c11, 0, 0}, [&](const std::array<u64,3>& m72) {
                  u64 v_c13 = m72[1]; u64 v_c14 = m72[2];
                  if (v_c11 != v_c13) return;
                  slog::join_probe<3,2>(appindex24, std::array<u64,3>{v_c14, v_c8, 0}, [&](const std::array<u64,3>& m73) {
                    u64 v_c15 = m73[2];
                    slog::join_probe<3,2>(lambdaindex25, std::array<u64,3>{v_c5, v_c15, 0}, [&](const std::array<u64,3>& m74) {
                      u64 v_c16 = m74[2];
                      slog::join_probe<3,1>(appindex26, std::array<u64,3>{v_c12, 0, 0}, [&](const std::array<u64,3>& m75) {
                        u64 v_c17 = m75[1]; u64 v_c18 = m75[2];
                        if (v_c12 != v_c17) return;
                        slog::join_probe<3,2>(lambdaindex27, std::array<u64,3>{v_c6, v_c18, 0}, [&](const std::array<u64,3>& m76) {
                          u64 v_c19 = m76[2];
                          ++_fires;
                          slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c4, v_c16}, std::array<u16,3>{1, 2, 0});
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
  
      if (_fires) db->bumpFires("mcfa-counting.slog:224", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask28(db,b));
  // (crule (pre) (scan eval __t6CRg170 ef c) (body (exists eval (2 0 1) 1 c) (exists app (1 2 0) 1 ef) (join eval_ans (0 1) 1 __t6CRg170 __t2Hqj172) (join eval (2 0 1) 1 c __6tlE337 __t5SBy169) (join app (0 1 2) 2 __t5SBy169 ef ea) (join-old eval (1 2 0) 2 (1 2 0) ea c __t1JPZ173) (join eval_ans (0 1) 1 __t1JPZ173 va) (join-old clo (0 2 1) 1 (0 2 1) __t2Hqj172 cb __t0RD6171) (join-old lambda (0 1 2) 1 (0 1 2) __t0RD6171 x eb)) (head (emit store (0 1 2) x __t5SBy169 va) (emit callev (0 1) __t5SBy169 c) (emit bindev (0 1 2) x __t5SBy169 c)) mcfa-counting.slog:92 #f)
  class ReadTask89 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex77;  slog::Index** appindex78;  slog::Index** eval_ansindex79;  slog::Index** evalindex80;  slog::Index** appindex81;  slog::Index** evalindex82;  slog::Index** eval_ansindex83;  slog::Index** cloindex84;  slog::Index** lambdaindex85;  slog::Index** evaldelta86;  slog::Index** clodelta87;  slog::Index** lambdadelta88;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("store");
      std::vector<u16> ord90({0, 1, 2});
      slog::Relation* readrel91 = db->getRelation("store");
      head_index[0] = readrel91->getIndex(ord90, false);
      head_rel[1] = db->getRelation("callev");
      std::vector<u16> ord92({0, 1});
      slog::Relation* readrel93 = db->getRelation("callev");
      head_index[1] = readrel93->getIndex(ord92, false);
      head_rel[2] = db->getRelation("bindev");
      std::vector<u16> ord94({0, 1, 2});
      slog::Relation* readrel95 = db->getRelation("bindev");
      head_index[2] = readrel95->getIndex(ord94, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord96({2, 0, 1});
      slog::Relation* readrel97 = db->getRelation("eval");
      evalindex77 = readrel97->getIndex(ord96, false);
      std::vector<u16> ord98({1, 2, 0});
      slog::Relation* readrel99 = db->getRelation("app");
      appindex78 = readrel99->getIndex(ord98, false);
      std::vector<u16> ord100({0, 1});
      slog::Relation* readrel101 = db->getRelation("eval_ans");
      eval_ansindex79 = readrel101->getIndex(ord100, false);
      std::vector<u16> ord102({2, 0, 1});
      slog::Relation* readrel103 = db->getRelation("eval");
      evalindex80 = readrel103->getIndex(ord102, false);
      std::vector<u16> ord104({0, 1, 2});
      slog::Relation* readrel105 = db->getRelation("app");
      appindex81 = readrel105->getIndex(ord104, false);
      std::vector<u16> ord106({1, 2, 0});
      slog::Relation* readrel107 = db->getRelation("eval");
      evalindex82 = readrel107->getIndex(ord106, false);
      std::vector<u16> ord108({1, 2, 0});
      slog::Relation* readrel109 = db->getRelation("eval");
      evaldelta86 = readrel109->getIndex(ord108, true);
      std::vector<u16> ord110({0, 1});
      slog::Relation* readrel111 = db->getRelation("eval_ans");
      eval_ansindex83 = readrel111->getIndex(ord110, false);
      std::vector<u16> ord112({0, 2, 1});
      slog::Relation* readrel113 = db->getRelation("clo");
      cloindex84 = readrel113->getIndex(ord112, false);
      std::vector<u16> ord114({0, 2, 1});
      slog::Relation* readrel115 = db->getRelation("clo");
      clodelta87 = readrel115->getIndex(ord114, true);
      std::vector<u16> ord116({0, 1, 2});
      slog::Relation* readrel117 = db->getRelation("lambda");
      lambdaindex85 = readrel117->getIndex(ord116, false);
      std::vector<u16> ord118({0, 1, 2});
      slog::Relation* readrel119 = db->getRelation("lambda");
      lambdadelta88 = readrel119->getIndex(ord118, true);
  
    }
    ReadTask89(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
  
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
        u64 v_c20 = _t[0];
        u64 v_c3 = _t[1];
        u64 v_c21 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex77, std::array<u64,3>{v_c21, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex78, std::array<u64,3>{v_c3, 0, 0})) return;
        slog::join_probe<2,1>(eval_ansindex79, std::array<u64,2>{v_c20, 0}, [&](const std::array<u64,2>& m120) {
          u64 v_c22 = m120[1];
          slog::join_probe<3,1>(evalindex80, std::array<u64,3>{v_c21, 0, 0}, [&](const std::array<u64,3>& m121) {
            u64 v_c23 = m121[1]; u64 v_c24 = m121[2];
            slog::join_probe<3,2>(appindex81, std::array<u64,3>{v_c24, v_c3, 0}, [&](const std::array<u64,3>& m122) {
              u64 v_c1 = m122[2];
              slog::join_probe_old<3,2>(evalindex82, evaldelta86, std::array<u64,3>{v_c1, v_c21, 0}, [&](const std::array<u64,3>& m123) {
                u64 v_c25 = m123[2];
                slog::join_probe<2,1>(eval_ansindex83, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m124) {
                  u64 v_c26 = m124[1];
                  slog::join_probe_old<3,1>(cloindex84, clodelta87, std::array<u64,3>{v_c22, 0, 0}, [&](const std::array<u64,3>& m125) {
                    u64 v_c27 = m125[1]; u64 v_c28 = m125[2];
                    slog::join_probe_old<3,1>(lambdaindex85, lambdadelta88, std::array<u64,3>{v_c28, 0, 0}, [&](const std::array<u64,3>& m126) {
                      u64 v_c0 = m126[1]; u64 v_c29 = m126[2];
                      ++_fires;
                      slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c0, v_c24, v_c26}, std::array<u16,3>{0, 1, 2});
                      slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c24, v_c21}, std::array<u16,2>{0, 1});
                      slog::emit<3>(head_rel[2], head_index[2], newbatch[2], std::array<u64,3>{v_c0, v_c24, v_c21}, std::array<u16,3>{0, 1, 2});
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
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:92", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask89* _cont = new ReadTask89(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask89(db,b), false);
  // (crule (pre (let __tconst7JVW192 const6cf13cc59dcbe759113f68a4) (let __tconst5wC2180 const970c20ea81b833e5b5a7accf) (let __tconst2ady176 constc40f204dda7ba4054abb9e74) (let __tconst7B9N190 constcaa3ee5a2828a31924f6b39d)) (seeded) (body (join ref (1 0) 1 __tconst2ady176 __t3ZY4175) (exists ref (1 0) 1 __tconst5wC2180) (exists lambda (1 2 0) 1 __tconst5wC2180) (exists ref (1 0) 1 __tconst7JVW192) (exists ref (1 0) 1 __tconst7B9N190) (exists lambda (1 2 0) 1 __tconst7B9N190) (exists lambda (1 2 0) 1 __tconst7JVW192) (join lambda (1 2 0) 2 __tconst2ady176 __t3ZY4175 __t1Ls4177) (join ref (1 0) 1 __tconst5wC2180 __t52sB179) (join lambda (1 2 0) 2 __tconst5wC2180 __t52sB179 __t6CST181) (exists app (2 0 1) 1 __t6CST181) (join ref (1 0) 1 __tconst7JVW192 __t6fOY185) (exists app (1 2 0) 1 __t6fOY185) (join ref (1 0) 1 __tconst7B9N190 __t8oRJ183) (join app (1 2 0) 2 __t6fOY185 __t8oRJ183 __t2CTd186) (join app (1 2 0) 2 __t6fOY185 __t2CTd186 __t9pbS189) (join lambda (1 2 0) 2 __tconst7B9N190 __t9pbS189 __t6W4v191) (join lambda (1 2 0) 2 __tconst7JVW192 __t6W4v191 __t6Vw9193) (join app (1 2 0) 2 __t6Vw9193 __t6CST181 __t5jf3194)) (head (mkstruct app (1 2 0) __t3W4r195 __t5jf3194 __t1Ls4177)) mcfa-counting.slog:301 #f)
  class ReadTask146 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex127;  slog::Index** refindex128;  slog::Index** lambdaindex129;  slog::Index** refindex130;  slog::Index** refindex131;  slog::Index** lambdaindex132;  slog::Index** lambdaindex133;  slog::Index** lambdaindex134;  slog::Index** refindex135;  slog::Index** lambdaindex136;  slog::Index** appindex137;  slog::Index** refindex138;  slog::Index** appindex139;  slog::Index** refindex140;  slog::Index** appindex141;  slog::Index** appindex142;  slog::Index** lambdaindex143;  slog::Index** lambdaindex144;  slog::Index** appindex145;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord147({1, 2, 0});
      slog::Relation* readrel148 = db->getRelation("app");
      head_index[0] = readrel148->getIndex(ord147, false);
      std::vector<u16> ord149({1, 0});
      slog::Relation* readrel150 = db->getRelation("ref");
      refindex127 = readrel150->getIndex(ord149, false);
      std::vector<u16> ord151({1, 0});
      slog::Relation* readrel152 = db->getRelation("ref");
      refindex128 = readrel152->getIndex(ord151, false);
      std::vector<u16> ord153({1, 2, 0});
      slog::Relation* readrel154 = db->getRelation("lambda");
      lambdaindex129 = readrel154->getIndex(ord153, false);
      std::vector<u16> ord155({1, 0});
      slog::Relation* readrel156 = db->getRelation("ref");
      refindex130 = readrel156->getIndex(ord155, false);
      std::vector<u16> ord157({1, 0});
      slog::Relation* readrel158 = db->getRelation("ref");
      refindex131 = readrel158->getIndex(ord157, false);
      std::vector<u16> ord159({1, 2, 0});
      slog::Relation* readrel160 = db->getRelation("lambda");
      lambdaindex132 = readrel160->getIndex(ord159, false);
      std::vector<u16> ord161({1, 2, 0});
      slog::Relation* readrel162 = db->getRelation("lambda");
      lambdaindex133 = readrel162->getIndex(ord161, false);
      std::vector<u16> ord163({1, 2, 0});
      slog::Relation* readrel164 = db->getRelation("lambda");
      lambdaindex134 = readrel164->getIndex(ord163, false);
      std::vector<u16> ord165({1, 0});
      slog::Relation* readrel166 = db->getRelation("ref");
      refindex135 = readrel166->getIndex(ord165, false);
      std::vector<u16> ord167({1, 2, 0});
      slog::Relation* readrel168 = db->getRelation("lambda");
      lambdaindex136 = readrel168->getIndex(ord167, false);
      std::vector<u16> ord169({2, 0, 1});
      slog::Relation* readrel170 = db->getRelation("app");
      appindex137 = readrel170->getIndex(ord169, false);
      std::vector<u16> ord171({1, 0});
      slog::Relation* readrel172 = db->getRelation("ref");
      refindex138 = readrel172->getIndex(ord171, false);
      std::vector<u16> ord173({1, 2, 0});
      slog::Relation* readrel174 = db->getRelation("app");
      appindex139 = readrel174->getIndex(ord173, false);
      std::vector<u16> ord175({1, 0});
      slog::Relation* readrel176 = db->getRelation("ref");
      refindex140 = readrel176->getIndex(ord175, false);
      std::vector<u16> ord177({1, 2, 0});
      slog::Relation* readrel178 = db->getRelation("app");
      appindex141 = readrel178->getIndex(ord177, false);
      std::vector<u16> ord179({1, 2, 0});
      slog::Relation* readrel180 = db->getRelation("app");
      appindex142 = readrel180->getIndex(ord179, false);
      std::vector<u16> ord181({1, 2, 0});
      slog::Relation* readrel182 = db->getRelation("lambda");
      lambdaindex143 = readrel182->getIndex(ord181, false);
      std::vector<u16> ord183({1, 2, 0});
      slog::Relation* readrel184 = db->getRelation("lambda");
      lambdaindex144 = readrel184->getIndex(ord183, false);
      std::vector<u16> ord185({1, 2, 0});
      slog::Relation* readrel186 = db->getRelation("app");
      appindex145 = readrel186->getIndex(ord185, false);
  
    }
    ReadTask146(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c30 = v_const6cf13cc59dcbe759113f68a4;
      u64 v_c31 = v_const970c20ea81b833e5b5a7accf;
      u64 v_c32 = v_constc40f204dda7ba4054abb9e74;
      u64 v_c33 = v_constcaa3ee5a2828a31924f6b39d;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex127, std::array<u64,2>{v_c32, 0}, [&](const std::array<u64,2>& m187) {
        u64 v_c34 = m187[1];
        if (!slog::exists_probe<2,1>(refindex128, std::array<u64,2>{v_c31, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex129, std::array<u64,3>{v_c31, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex130, std::array<u64,2>{v_c30, 0})) return;
        if (!slog::exists_probe<2,1>(refindex131, std::array<u64,2>{v_c33, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex132, std::array<u64,3>{v_c33, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex133, std::array<u64,3>{v_c30, 0, 0})) return;
        slog::join_probe<3,2>(lambdaindex134, std::array<u64,3>{v_c32, v_c34, 0}, [&](const std::array<u64,3>& m188) {
          u64 v_c35 = m188[2];
          slog::join_probe<2,1>(refindex135, std::array<u64,2>{v_c31, 0}, [&](const std::array<u64,2>& m189) {
            u64 v_c36 = m189[1];
            slog::join_probe<3,2>(lambdaindex136, std::array<u64,3>{v_c31, v_c36, 0}, [&](const std::array<u64,3>& m190) {
              u64 v_c37 = m190[2];
              if (!slog::exists_probe<3,1>(appindex137, std::array<u64,3>{v_c37, 0, 0})) return;
              slog::join_probe<2,1>(refindex138, std::array<u64,2>{v_c30, 0}, [&](const std::array<u64,2>& m191) {
                u64 v_c38 = m191[1];
                if (!slog::exists_probe<3,1>(appindex139, std::array<u64,3>{v_c38, 0, 0})) return;
                slog::join_probe<2,1>(refindex140, std::array<u64,2>{v_c33, 0}, [&](const std::array<u64,2>& m192) {
                  u64 v_c39 = m192[1];
                  slog::join_probe<3,2>(appindex141, std::array<u64,3>{v_c38, v_c39, 0}, [&](const std::array<u64,3>& m193) {
                    u64 v_c40 = m193[2];
                    slog::join_probe<3,2>(appindex142, std::array<u64,3>{v_c38, v_c40, 0}, [&](const std::array<u64,3>& m194) {
                      u64 v_c41 = m194[2];
                      slog::join_probe<3,2>(lambdaindex143, std::array<u64,3>{v_c33, v_c41, 0}, [&](const std::array<u64,3>& m195) {
                        u64 v_c42 = m195[2];
                        slog::join_probe<3,2>(lambdaindex144, std::array<u64,3>{v_c30, v_c42, 0}, [&](const std::array<u64,3>& m196) {
                          u64 v_c43 = m196[2];
                          slog::join_probe<3,2>(appindex145, std::array<u64,3>{v_c43, v_c37, 0}, [&](const std::array<u64,3>& m197) {
                            u64 v_c44 = m197[2];
                            ++_fires;
                            slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c44, v_c35}, std::array<u16,3>{1, 2, 0});
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
  
      if (_fires) db->bumpFires("mcfa-counting.slog:301", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask146(db,b));
  // (crule (pre (let __tconst0y6X73 const0aa6f87434af0222b916e97a) (let __tconst0aL952 constd3d07026d47882ceca728218) (let __tconst7zoP70 const227d34ceeba7a29aada993d4) (let __tconst0xUh47 constf700a82e218a86de572e1f7f) (let __tconst1bfe65 const59ba3256d223f0d0a00d0633) (let __tconst8wN863 const7cd75b35aa30c3ddf04f9d57)) (seeded) (body (join ref (1 0) 1 __tconst0aL952 __t5HQ450) (exists ref (1 0) 1 __tconst0xUh47) (exists lambda (1 2 0) 1 __tconst0xUh47) (exists app (1 2 0) 1 __t5HQ450) (exists lambda (1 2 0) 1 __tconst0aL952) (exists ref (1 0) 1 __tconst1bfe65) (exists lambda (1 2 0) 1 __tconst1bfe65) (exists ref (1 0) 1 __tconst8wN863) (exists lambda (1 2 0) 1 __tconst8wN863) (exists lambda (1 2 0) 1 __tconst7zoP70) (exists lambda (1 2 0) 1 __tconst0y6X73) (join ref (1 0) 1 __tconst0y6X73 __t0QRr59) (exists app (1 2 0) 1 __t0QRr59) (join ref (1 0) 1 __tconst0xUh47 __t5vZb46) (join lambda (1 2 0) 2 __tconst0xUh47 __t5vZb46 __t50zW48) (join app (1 2 0) 2 __t5HQ450 __t50zW48 __t05NY51) (join lambda (1 2 0) 2 __tconst0aL952 __t05NY51 __t3xtz53) (exists app (2 0 1) 1 __t3xtz53) (join ref (1 0) 1 __tconst1bfe65 __t2HsD55) (join lambda (1 2 0) 2 __tconst1bfe65 __t2HsD55 __t0uNb57) (join app (1 2 0) 2 __t0QRr59 __t0uNb57 __t81HE60) (exists app (2 0 1) 1 __t81HE60) (join ref (1 0) 1 __tconst8wN863 __t1mkO62) (join lambda (1 2 0) 2 __tconst8wN863 __t1mkO62 __t3Dru64) (join lambda (1 2 0) 2 __tconst1bfe65 __t3Dru64 __t7JIT66) (join app (1 2 0) 2 __t0QRr59 __t7JIT66 __t5Ri569) (join lambda (1 2 0) 2 __tconst7zoP70 __t5Ri569 __t7KAC71) (join app (1 2 0) 2 __t7KAC71 __t81HE60 __t9kFz72) (join lambda (1 2 0) 2 __tconst0y6X73 __t9kFz72 __t9J4m74) (join app (1 2 0) 2 __t9J4m74 __t3xtz53 __t5ePS75)) (head (emit program (0) __t5ePS75)) mcfa-counting.slog:287 #f)
  class ReadTask228 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex198;  slog::Index** refindex199;  slog::Index** lambdaindex200;  slog::Index** appindex201;  slog::Index** lambdaindex202;  slog::Index** refindex203;  slog::Index** lambdaindex204;  slog::Index** refindex205;  slog::Index** lambdaindex206;  slog::Index** lambdaindex207;  slog::Index** lambdaindex208;  slog::Index** refindex209;  slog::Index** appindex210;  slog::Index** refindex211;  slog::Index** lambdaindex212;  slog::Index** appindex213;  slog::Index** lambdaindex214;  slog::Index** appindex215;  slog::Index** refindex216;  slog::Index** lambdaindex217;  slog::Index** appindex218;  slog::Index** appindex219;  slog::Index** refindex220;  slog::Index** lambdaindex221;  slog::Index** lambdaindex222;  slog::Index** appindex223;  slog::Index** lambdaindex224;  slog::Index** appindex225;  slog::Index** lambdaindex226;  slog::Index** appindex227;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("program");
      std::vector<u16> ord229({0});
      slog::Relation* readrel230 = db->getRelation("program");
      head_index[0] = readrel230->getIndex(ord229, false);
      std::vector<u16> ord231({1, 0});
      slog::Relation* readrel232 = db->getRelation("ref");
      refindex198 = readrel232->getIndex(ord231, false);
      std::vector<u16> ord233({1, 0});
      slog::Relation* readrel234 = db->getRelation("ref");
      refindex199 = readrel234->getIndex(ord233, false);
      std::vector<u16> ord235({1, 2, 0});
      slog::Relation* readrel236 = db->getRelation("lambda");
      lambdaindex200 = readrel236->getIndex(ord235, false);
      std::vector<u16> ord237({1, 2, 0});
      slog::Relation* readrel238 = db->getRelation("app");
      appindex201 = readrel238->getIndex(ord237, false);
      std::vector<u16> ord239({1, 2, 0});
      slog::Relation* readrel240 = db->getRelation("lambda");
      lambdaindex202 = readrel240->getIndex(ord239, false);
      std::vector<u16> ord241({1, 0});
      slog::Relation* readrel242 = db->getRelation("ref");
      refindex203 = readrel242->getIndex(ord241, false);
      std::vector<u16> ord243({1, 2, 0});
      slog::Relation* readrel244 = db->getRelation("lambda");
      lambdaindex204 = readrel244->getIndex(ord243, false);
      std::vector<u16> ord245({1, 0});
      slog::Relation* readrel246 = db->getRelation("ref");
      refindex205 = readrel246->getIndex(ord245, false);
      std::vector<u16> ord247({1, 2, 0});
      slog::Relation* readrel248 = db->getRelation("lambda");
      lambdaindex206 = readrel248->getIndex(ord247, false);
      std::vector<u16> ord249({1, 2, 0});
      slog::Relation* readrel250 = db->getRelation("lambda");
      lambdaindex207 = readrel250->getIndex(ord249, false);
      std::vector<u16> ord251({1, 2, 0});
      slog::Relation* readrel252 = db->getRelation("lambda");
      lambdaindex208 = readrel252->getIndex(ord251, false);
      std::vector<u16> ord253({1, 0});
      slog::Relation* readrel254 = db->getRelation("ref");
      refindex209 = readrel254->getIndex(ord253, false);
      std::vector<u16> ord255({1, 2, 0});
      slog::Relation* readrel256 = db->getRelation("app");
      appindex210 = readrel256->getIndex(ord255, false);
      std::vector<u16> ord257({1, 0});
      slog::Relation* readrel258 = db->getRelation("ref");
      refindex211 = readrel258->getIndex(ord257, false);
      std::vector<u16> ord259({1, 2, 0});
      slog::Relation* readrel260 = db->getRelation("lambda");
      lambdaindex212 = readrel260->getIndex(ord259, false);
      std::vector<u16> ord261({1, 2, 0});
      slog::Relation* readrel262 = db->getRelation("app");
      appindex213 = readrel262->getIndex(ord261, false);
      std::vector<u16> ord263({1, 2, 0});
      slog::Relation* readrel264 = db->getRelation("lambda");
      lambdaindex214 = readrel264->getIndex(ord263, false);
      std::vector<u16> ord265({2, 0, 1});
      slog::Relation* readrel266 = db->getRelation("app");
      appindex215 = readrel266->getIndex(ord265, false);
      std::vector<u16> ord267({1, 0});
      slog::Relation* readrel268 = db->getRelation("ref");
      refindex216 = readrel268->getIndex(ord267, false);
      std::vector<u16> ord269({1, 2, 0});
      slog::Relation* readrel270 = db->getRelation("lambda");
      lambdaindex217 = readrel270->getIndex(ord269, false);
      std::vector<u16> ord271({1, 2, 0});
      slog::Relation* readrel272 = db->getRelation("app");
      appindex218 = readrel272->getIndex(ord271, false);
      std::vector<u16> ord273({2, 0, 1});
      slog::Relation* readrel274 = db->getRelation("app");
      appindex219 = readrel274->getIndex(ord273, false);
      std::vector<u16> ord275({1, 0});
      slog::Relation* readrel276 = db->getRelation("ref");
      refindex220 = readrel276->getIndex(ord275, false);
      std::vector<u16> ord277({1, 2, 0});
      slog::Relation* readrel278 = db->getRelation("lambda");
      lambdaindex221 = readrel278->getIndex(ord277, false);
      std::vector<u16> ord279({1, 2, 0});
      slog::Relation* readrel280 = db->getRelation("lambda");
      lambdaindex222 = readrel280->getIndex(ord279, false);
      std::vector<u16> ord281({1, 2, 0});
      slog::Relation* readrel282 = db->getRelation("app");
      appindex223 = readrel282->getIndex(ord281, false);
      std::vector<u16> ord283({1, 2, 0});
      slog::Relation* readrel284 = db->getRelation("lambda");
      lambdaindex224 = readrel284->getIndex(ord283, false);
      std::vector<u16> ord285({1, 2, 0});
      slog::Relation* readrel286 = db->getRelation("app");
      appindex225 = readrel286->getIndex(ord285, false);
      std::vector<u16> ord287({1, 2, 0});
      slog::Relation* readrel288 = db->getRelation("lambda");
      lambdaindex226 = readrel288->getIndex(ord287, false);
      std::vector<u16> ord289({1, 2, 0});
      slog::Relation* readrel290 = db->getRelation("app");
      appindex227 = readrel290->getIndex(ord289, false);
  
    }
    ReadTask228(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c45 = v_const0aa6f87434af0222b916e97a;
      u64 v_c46 = v_constd3d07026d47882ceca728218;
      u64 v_c47 = v_const227d34ceeba7a29aada993d4;
      u64 v_c48 = v_constf700a82e218a86de572e1f7f;
      u64 v_c49 = v_const59ba3256d223f0d0a00d0633;
      u64 v_c50 = v_const7cd75b35aa30c3ddf04f9d57;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex198, std::array<u64,2>{v_c46, 0}, [&](const std::array<u64,2>& m291) {
        u64 v_c51 = m291[1];
        if (!slog::exists_probe<2,1>(refindex199, std::array<u64,2>{v_c48, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex200, std::array<u64,3>{v_c48, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex201, std::array<u64,3>{v_c51, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex202, std::array<u64,3>{v_c46, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex203, std::array<u64,2>{v_c49, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex204, std::array<u64,3>{v_c49, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex205, std::array<u64,2>{v_c50, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex206, std::array<u64,3>{v_c50, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex207, std::array<u64,3>{v_c47, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex208, std::array<u64,3>{v_c45, 0, 0})) return;
        slog::join_probe<2,1>(refindex209, std::array<u64,2>{v_c45, 0}, [&](const std::array<u64,2>& m292) {
          u64 v_c52 = m292[1];
          if (!slog::exists_probe<3,1>(appindex210, std::array<u64,3>{v_c52, 0, 0})) return;
          slog::join_probe<2,1>(refindex211, std::array<u64,2>{v_c48, 0}, [&](const std::array<u64,2>& m293) {
            u64 v_c53 = m293[1];
            slog::join_probe<3,2>(lambdaindex212, std::array<u64,3>{v_c48, v_c53, 0}, [&](const std::array<u64,3>& m294) {
              u64 v_c54 = m294[2];
              slog::join_probe<3,2>(appindex213, std::array<u64,3>{v_c51, v_c54, 0}, [&](const std::array<u64,3>& m295) {
                u64 v_c55 = m295[2];
                slog::join_probe<3,2>(lambdaindex214, std::array<u64,3>{v_c46, v_c55, 0}, [&](const std::array<u64,3>& m296) {
                  u64 v_c56 = m296[2];
                  if (!slog::exists_probe<3,1>(appindex215, std::array<u64,3>{v_c56, 0, 0})) return;
                  slog::join_probe<2,1>(refindex216, std::array<u64,2>{v_c49, 0}, [&](const std::array<u64,2>& m297) {
                    u64 v_c57 = m297[1];
                    slog::join_probe<3,2>(lambdaindex217, std::array<u64,3>{v_c49, v_c57, 0}, [&](const std::array<u64,3>& m298) {
                      u64 v_c58 = m298[2];
                      slog::join_probe<3,2>(appindex218, std::array<u64,3>{v_c52, v_c58, 0}, [&](const std::array<u64,3>& m299) {
                        u64 v_c59 = m299[2];
                        if (!slog::exists_probe<3,1>(appindex219, std::array<u64,3>{v_c59, 0, 0})) return;
                        slog::join_probe<2,1>(refindex220, std::array<u64,2>{v_c50, 0}, [&](const std::array<u64,2>& m300) {
                          u64 v_c60 = m300[1];
                          slog::join_probe<3,2>(lambdaindex221, std::array<u64,3>{v_c50, v_c60, 0}, [&](const std::array<u64,3>& m301) {
                            u64 v_c61 = m301[2];
                            slog::join_probe<3,2>(lambdaindex222, std::array<u64,3>{v_c49, v_c61, 0}, [&](const std::array<u64,3>& m302) {
                              u64 v_c62 = m302[2];
                              slog::join_probe<3,2>(appindex223, std::array<u64,3>{v_c52, v_c62, 0}, [&](const std::array<u64,3>& m303) {
                                u64 v_c63 = m303[2];
                                slog::join_probe<3,2>(lambdaindex224, std::array<u64,3>{v_c47, v_c63, 0}, [&](const std::array<u64,3>& m304) {
                                  u64 v_c64 = m304[2];
                                  slog::join_probe<3,2>(appindex225, std::array<u64,3>{v_c64, v_c59, 0}, [&](const std::array<u64,3>& m305) {
                                    u64 v_c65 = m305[2];
                                    slog::join_probe<3,2>(lambdaindex226, std::array<u64,3>{v_c45, v_c65, 0}, [&](const std::array<u64,3>& m306) {
                                      u64 v_c66 = m306[2];
                                      slog::join_probe<3,2>(appindex227, std::array<u64,3>{v_c66, v_c56, 0}, [&](const std::array<u64,3>& m307) {
                                        u64 v_c67 = m307[2];
                                        ++_fires;
                                        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c67}, std::array<u16,1>{0});
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
  
      if (_fires) db->bumpFires("mcfa-counting.slog:287", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask228(db,b));
  // (crule (pre (let __tconst4dpc328 conste4a9e4d8baa71a9d8ebf56ec)) (scan program e) (body (join _enum (1 0) 1 __tconst4dpc328 __t9J4i253)) (head (mkstruct eval (1 2 0) __6NiV327 e __t9J4i253)) mcfa-counting.slog:111 #f)
  class ReadTask309 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex308;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("program");
      std::vector<u16> ord310({1, 0});
      slog::Relation* readrel311 = db->getRelation("_enum");
      _enumindex308 = readrel311->getIndex(ord310, false);
  
    }
    ReadTask309(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c68 = v_conste4a9e4d8baa71a9d8ebf56ec;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c69 = _t[0];
        slog::join_probe<2,1>(_enumindex308, std::array<u64,2>{v_c68, 0}, [&](const std::array<u64,2>& m312) {
          u64 v_c70 = m312[1];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c69, v_c70}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:111", "delta:program", _fires);
  
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
  // (crule (pre (let __tconst0y6X73 const0aa6f87434af0222b916e97a) (let __tconst7zoP70 const227d34ceeba7a29aada993d4) (let __tconst1bfe65 const59ba3256d223f0d0a00d0633) (let __tconst8wN863 const7cd75b35aa30c3ddf04f9d57) (let __tconst0aL952 constd3d07026d47882ceca728218) (let __tconst0xUh47 constf700a82e218a86de572e1f7f)) (probe ref (1 0) 1 __tconst0xUh47 __t5vZb46) (body (exists ref (1 0) 1 __tconst1bfe65) (exists ref (1 0) 1 __tconst0y6X73) (exists ref (1 0) 1 __tconst8wN863) (join ref (1 0) 1 __tconst0aL952 __t5HQ450) (join ref (1 0) 1 __tconst1bfe65 __t2HsD55) (join ref (1 0) 1 __tconst0y6X73 __t0QRr59) (join ref (1 0) 1 __tconst8wN863 __t1mkO62)) (head (mkstruct lambda (1 2 0) __t3Dru64 __tconst8wN863 __t1mkO62) (mkstruct lambda (1 2 0) __t0uNb57 __tconst1bfe65 __t2HsD55) (mkstruct lambda (1 2 0) __t50zW48 __tconst0xUh47 __t5vZb46)) mcfa-counting.slog:287 #f)
  class ReadTask320 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** refindex313;  slog::Index** refindex314;  slog::Index** refindex315;  slog::Index** refindex316;  slog::Index** refindex317;  slog::Index** refindex318;  slog::Index** refindex319;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      head_rel[1] = db->getRelation("lambda");
      head_rel[2] = db->getRelation("lambda");
      std::vector<u16> ord321({1, 0});
      slog::Relation* readrel322 = db->getRelation("ref");
      driver_index = readrel322->getIndex(ord321, true);
      std::vector<u16> ord323({1, 0});
      slog::Relation* readrel324 = db->getRelation("ref");
      refindex313 = readrel324->getIndex(ord323, false);
      std::vector<u16> ord325({1, 0});
      slog::Relation* readrel326 = db->getRelation("ref");
      refindex314 = readrel326->getIndex(ord325, false);
      std::vector<u16> ord327({1, 0});
      slog::Relation* readrel328 = db->getRelation("ref");
      refindex315 = readrel328->getIndex(ord327, false);
      std::vector<u16> ord329({1, 0});
      slog::Relation* readrel330 = db->getRelation("ref");
      refindex316 = readrel330->getIndex(ord329, false);
      std::vector<u16> ord331({1, 0});
      slog::Relation* readrel332 = db->getRelation("ref");
      refindex317 = readrel332->getIndex(ord331, false);
      std::vector<u16> ord333({1, 0});
      slog::Relation* readrel334 = db->getRelation("ref");
      refindex318 = readrel334->getIndex(ord333, false);
      std::vector<u16> ord335({1, 0});
      slog::Relation* readrel336 = db->getRelation("ref");
      refindex319 = readrel336->getIndex(ord335, false);
  
    }
    ReadTask320(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c45 = v_const0aa6f87434af0222b916e97a;
      u64 v_c47 = v_const227d34ceeba7a29aada993d4;
      u64 v_c49 = v_const59ba3256d223f0d0a00d0633;
      u64 v_c50 = v_const7cd75b35aa30c3ddf04f9d57;
      u64 v_c46 = v_constd3d07026d47882ceca728218;
      u64 v_c48 = v_constf700a82e218a86de572e1f7f;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c48, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m337) {
        u64 v_c53 = m337[1];
        if (buckethash(v_c53) != bucket) return;
        if (!slog::exists_probe<2,1>(refindex313, std::array<u64,2>{v_c49, 0})) return;
        if (!slog::exists_probe<2,1>(refindex314, std::array<u64,2>{v_c45, 0})) return;
        if (!slog::exists_probe<2,1>(refindex315, std::array<u64,2>{v_c50, 0})) return;
        slog::join_probe<2,1>(refindex316, std::array<u64,2>{v_c46, 0}, [&](const std::array<u64,2>& m338) {
          u64 v_c51 = m338[1];
          slog::join_probe<2,1>(refindex317, std::array<u64,2>{v_c49, 0}, [&](const std::array<u64,2>& m339) {
            u64 v_c57 = m339[1];
            slog::join_probe<2,1>(refindex318, std::array<u64,2>{v_c45, 0}, [&](const std::array<u64,2>& m340) {
              u64 v_c52 = m340[1];
              slog::join_probe<2,1>(refindex319, std::array<u64,2>{v_c50, 0}, [&](const std::array<u64,2>& m341) {
                u64 v_c60 = m341[1];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c50, v_c60}, std::array<u16,3>{1, 2, 0});
                slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c49, v_c57}, std::array<u16,3>{1, 2, 0});
                slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c48, v_c53}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:287", "delta:ref", _fires);
  
      if (!_done)
      {
        ReadTask320* _cont = new ReadTask320(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask320(db,b), false);
  // (crule (pre) (scan freevar y eb) (body (join-old lambda (2 0 1) 1 (2 0 1) eb __t0Tt63 x) (neq x y)) (head (emit freevar (0 1) y __t0Tt63)) freevars.slog:18 #f)
  class ReadTask344 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lambdaindex342;  slog::Index** lambdadelta343;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("freevar");
      std::vector<u16> ord345({0, 1});
      slog::Relation* readrel346 = db->getRelation("freevar");
      head_index[0] = readrel346->getIndex(ord345, false);
      outer_rel = db->getRelation("freevar");
      std::vector<u16> ord347({2, 0, 1});
      slog::Relation* readrel348 = db->getRelation("lambda");
      lambdaindex342 = readrel348->getIndex(ord347, false);
      std::vector<u16> ord349({2, 0, 1});
      slog::Relation* readrel350 = db->getRelation("lambda");
      lambdadelta343 = readrel350->getIndex(ord349, true);
  
    }
    ReadTask344(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c29 = _t[1];
        slog::join_probe_old<3,1>(lambdaindex342, lambdadelta343, std::array<u64,3>{v_c29, 0, 0}, [&](const std::array<u64,3>& m351) {
          u64 v_c72 = m351[1]; u64 v_c0 = m351[2];
          if (v_c0 == v_c71) return;
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c71, v_c72}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:18", "delta:freevar", _fires);
  
      if (!_done)
      {
        ReadTask344* _cont = new ReadTask344(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask344(db,b), false);
  // (crule (pre (let __tconst4N2q248 constaaaad65142343c54348db5d0) (let __tconst4Sko246 consteb793a6f75d6cfe49d3c2c90) (let __tconst7sqz226 const7b8fd91ee9ff10cfbb8066bf) (let __tconst1EUj230 const615ad01b1c532bb6634df115) (let __tconst2VuQ234 const4492fd5fa4baacfebd29f5e5) (let __tconst2x2f244 consta32d5a443def48e6d64c6f4b)) (probe lambda (1 2 0) 1 __tconst4N2q248 __t7yz1247 __t5uyC249) (body (exists lambda (1 2 0) 1 __tconst2x2f244) (exists ref (1 0) 1 __tconst2VuQ234) (exists lambda (1 2 0) 1 __tconst2VuQ234) (exists ref (1 0) 1 __tconst1EUj230) (exists lambda (1 2 0) 1 __tconst1EUj230) (exists ref (1 0) 1 __tconst7sqz226) (exists lambda (1 2 0) 1 __tconst7sqz226) (exists ref (1 0) 1 __tconst2x2f244) (exists ref (1 0) 1 __tconst4N2q248) (exists ref (1 0) 1 __tconst4Sko246) (join lambda (0 1 2) 2 __t7yz1247 __tconst4Sko246 __t3laZ245) (join lambda (0 1 2) 2 __t3laZ245 __tconst2x2f244 __t5h6K243) (join ref (1 0) 1 __tconst2VuQ234 __t2PLq233) (join lambda (1 2 0) 2 __tconst2VuQ234 __t2PLq233 __t45rU235) (join ref (1 0) 1 __tconst1EUj230 __t3WVP229) (join lambda (1 2 0) 2 __tconst1EUj230 __t3WVP229 __t5ryk231) (join ref (1 0) 1 __tconst7sqz226 __t5APF225) (join lambda (1 2 0) 2 __tconst7sqz226 __t5APF225 __t2BAX227) (join ref (1 0) 1 __tconst2x2f244 __t3pbc237) (join app (2 0 1) 2 __t3pbc237 __t5h6K243 __t4wvK242) (join ref (1 0) 1 __tconst4N2q248 __t6KL4241) (join app (0 1 2) 2 __t4wvK242 __t6KL4241 __t16jv239) (join ref (0 1) 2 __t16jv239 __tconst4Sko246)) (head (mkstruct app (1 2 0) __t5pZU250 __t5uyC249 __t45rU235)) mcfa-counting.slog:272 #f)
  class ReadTask375 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** lambdaindex352;  slog::Index** refindex353;  slog::Index** lambdaindex354;  slog::Index** refindex355;  slog::Index** lambdaindex356;  slog::Index** refindex357;  slog::Index** lambdaindex358;  slog::Index** refindex359;  slog::Index** refindex360;  slog::Index** refindex361;  slog::Index** lambdaindex362;  slog::Index** lambdaindex363;  slog::Index** refindex364;  slog::Index** lambdaindex365;  slog::Index** refindex366;  slog::Index** lambdaindex367;  slog::Index** refindex368;  slog::Index** lambdaindex369;  slog::Index** refindex370;  slog::Index** appindex371;  slog::Index** refindex372;  slog::Index** appindex373;  slog::Index** refindex374;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord376({1, 2, 0});
      slog::Relation* readrel377 = db->getRelation("lambda");
      driver_index = readrel377->getIndex(ord376, true);
      std::vector<u16> ord378({1, 2, 0});
      slog::Relation* readrel379 = db->getRelation("lambda");
      lambdaindex352 = readrel379->getIndex(ord378, false);
      std::vector<u16> ord380({1, 0});
      slog::Relation* readrel381 = db->getRelation("ref");
      refindex353 = readrel381->getIndex(ord380, false);
      std::vector<u16> ord382({1, 2, 0});
      slog::Relation* readrel383 = db->getRelation("lambda");
      lambdaindex354 = readrel383->getIndex(ord382, false);
      std::vector<u16> ord384({1, 0});
      slog::Relation* readrel385 = db->getRelation("ref");
      refindex355 = readrel385->getIndex(ord384, false);
      std::vector<u16> ord386({1, 2, 0});
      slog::Relation* readrel387 = db->getRelation("lambda");
      lambdaindex356 = readrel387->getIndex(ord386, false);
      std::vector<u16> ord388({1, 0});
      slog::Relation* readrel389 = db->getRelation("ref");
      refindex357 = readrel389->getIndex(ord388, false);
      std::vector<u16> ord390({1, 2, 0});
      slog::Relation* readrel391 = db->getRelation("lambda");
      lambdaindex358 = readrel391->getIndex(ord390, false);
      std::vector<u16> ord392({1, 0});
      slog::Relation* readrel393 = db->getRelation("ref");
      refindex359 = readrel393->getIndex(ord392, false);
      std::vector<u16> ord394({1, 0});
      slog::Relation* readrel395 = db->getRelation("ref");
      refindex360 = readrel395->getIndex(ord394, false);
      std::vector<u16> ord396({1, 0});
      slog::Relation* readrel397 = db->getRelation("ref");
      refindex361 = readrel397->getIndex(ord396, false);
      std::vector<u16> ord398({0, 1, 2});
      slog::Relation* readrel399 = db->getRelation("lambda");
      lambdaindex362 = readrel399->getIndex(ord398, false);
      std::vector<u16> ord400({0, 1, 2});
      slog::Relation* readrel401 = db->getRelation("lambda");
      lambdaindex363 = readrel401->getIndex(ord400, false);
      std::vector<u16> ord402({1, 0});
      slog::Relation* readrel403 = db->getRelation("ref");
      refindex364 = readrel403->getIndex(ord402, false);
      std::vector<u16> ord404({1, 2, 0});
      slog::Relation* readrel405 = db->getRelation("lambda");
      lambdaindex365 = readrel405->getIndex(ord404, false);
      std::vector<u16> ord406({1, 0});
      slog::Relation* readrel407 = db->getRelation("ref");
      refindex366 = readrel407->getIndex(ord406, false);
      std::vector<u16> ord408({1, 2, 0});
      slog::Relation* readrel409 = db->getRelation("lambda");
      lambdaindex367 = readrel409->getIndex(ord408, false);
      std::vector<u16> ord410({1, 0});
      slog::Relation* readrel411 = db->getRelation("ref");
      refindex368 = readrel411->getIndex(ord410, false);
      std::vector<u16> ord412({1, 2, 0});
      slog::Relation* readrel413 = db->getRelation("lambda");
      lambdaindex369 = readrel413->getIndex(ord412, false);
      std::vector<u16> ord414({1, 0});
      slog::Relation* readrel415 = db->getRelation("ref");
      refindex370 = readrel415->getIndex(ord414, false);
      std::vector<u16> ord416({2, 0, 1});
      slog::Relation* readrel417 = db->getRelation("app");
      appindex371 = readrel417->getIndex(ord416, false);
      std::vector<u16> ord418({1, 0});
      slog::Relation* readrel419 = db->getRelation("ref");
      refindex372 = readrel419->getIndex(ord418, false);
      std::vector<u16> ord420({0, 1, 2});
      slog::Relation* readrel421 = db->getRelation("app");
      appindex373 = readrel421->getIndex(ord420, false);
      std::vector<u16> ord422({0, 1});
      slog::Relation* readrel423 = db->getRelation("ref");
      refindex374 = readrel423->getIndex(ord422, false);
  
    }
    ReadTask375(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c73 = v_constaaaad65142343c54348db5d0;
      u64 v_c74 = v_consteb793a6f75d6cfe49d3c2c90;
      u64 v_c75 = v_const7b8fd91ee9ff10cfbb8066bf;
      u64 v_c76 = v_const615ad01b1c532bb6634df115;
      u64 v_c77 = v_const4492fd5fa4baacfebd29f5e5;
      u64 v_c78 = v_consta32d5a443def48e6d64c6f4b;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c73, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m424) {
        u64 v_c79 = m424[1];
        u64 v_c80 = m424[2];
        if (buckethash(v_c79) != bucket) return;
        if (!slog::exists_probe<3,1>(lambdaindex352, std::array<u64,3>{v_c78, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex353, std::array<u64,2>{v_c77, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex354, std::array<u64,3>{v_c77, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex355, std::array<u64,2>{v_c76, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex356, std::array<u64,3>{v_c76, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex357, std::array<u64,2>{v_c75, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex358, std::array<u64,3>{v_c75, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex359, std::array<u64,2>{v_c78, 0})) return;
        if (!slog::exists_probe<2,1>(refindex360, std::array<u64,2>{v_c73, 0})) return;
        if (!slog::exists_probe<2,1>(refindex361, std::array<u64,2>{v_c74, 0})) return;
        slog::join_probe<3,2>(lambdaindex362, std::array<u64,3>{v_c79, v_c74, 0}, [&](const std::array<u64,3>& m425) {
          u64 v_c81 = m425[2];
          slog::join_probe<3,2>(lambdaindex363, std::array<u64,3>{v_c81, v_c78, 0}, [&](const std::array<u64,3>& m426) {
            u64 v_c82 = m426[2];
            slog::join_probe<2,1>(refindex364, std::array<u64,2>{v_c77, 0}, [&](const std::array<u64,2>& m427) {
              u64 v_c83 = m427[1];
              slog::join_probe<3,2>(lambdaindex365, std::array<u64,3>{v_c77, v_c83, 0}, [&](const std::array<u64,3>& m428) {
                u64 v_c84 = m428[2];
                slog::join_probe<2,1>(refindex366, std::array<u64,2>{v_c76, 0}, [&](const std::array<u64,2>& m429) {
                  u64 v_c85 = m429[1];
                  slog::join_probe<3,2>(lambdaindex367, std::array<u64,3>{v_c76, v_c85, 0}, [&](const std::array<u64,3>& m430) {
                    u64 v_c86 = m430[2];
                    slog::join_probe<2,1>(refindex368, std::array<u64,2>{v_c75, 0}, [&](const std::array<u64,2>& m431) {
                      u64 v_c87 = m431[1];
                      slog::join_probe<3,2>(lambdaindex369, std::array<u64,3>{v_c75, v_c87, 0}, [&](const std::array<u64,3>& m432) {
                        u64 v_c88 = m432[2];
                        slog::join_probe<2,1>(refindex370, std::array<u64,2>{v_c78, 0}, [&](const std::array<u64,2>& m433) {
                          u64 v_c89 = m433[1];
                          slog::join_probe<3,2>(appindex371, std::array<u64,3>{v_c89, v_c82, 0}, [&](const std::array<u64,3>& m434) {
                            u64 v_c90 = m434[2];
                            slog::join_probe<2,1>(refindex372, std::array<u64,2>{v_c73, 0}, [&](const std::array<u64,2>& m435) {
                              u64 v_c91 = m435[1];
                              slog::join_probe<3,2>(appindex373, std::array<u64,3>{v_c90, v_c91, 0}, [&](const std::array<u64,3>& m436) {
                                u64 v_c92 = m436[2];
                                slog::join_probe<2,2>(refindex374, std::array<u64,2>{v_c92, v_c74}, [&](const std::array<u64,2>& m437) {
                                  ++_fires;
                                  slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c80, v_c84}, std::array<u16,3>{1, 2, 0});
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
  
      if (_fires) db->bumpFires("mcfa-counting.slog:272", "delta:lambda", _fires);
  
      if (!_done)
      {
        ReadTask375* _cont = new ReadTask375(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask375(db,b), false);
  // (crule (pre (let __tconst9zoW125 const7c7d2cfc66f4d976987d2d20) (let __tconst4V4L122 const6bc0ba365ada70df115e1785) (let __tconst82U8119 consta8180db1c2f300980314f910) (let __tconst4Zcr91 const9a67f28c6b77e842f439a84a) (let __tconst0vRf84 conste58dec6bca6f63ef79c3b755) (let __tconst4BKz104 const0f8748be649f8ee4066bb1d7) (let __tconst3wDH116 constd5f017533ea574d5f9b3400c) (let __tconst3ktF111 const990b444cbd47632035b2fa1a) (let __tconst5nWJ102 const4f84f41d89b6b717419b4eaa)) (scan app __t1GdP121 __t3SEs120 __t7TEO99) (body (exists ref (1 0) 1 __tconst4V4L122) (exists lambda (1 2 0) 1 __tconst4BKz104) (exists ref (1 0) 1 __tconst4BKz104) (exists ref (1 0) 1 __tconst0vRf84) (exists lambda (1 2 0) 1 __tconst0vRf84) (exists ref (1 0) 1 __tconst4Zcr91) (exists ref (1 0) 1 __tconst9zoW125) (exists lambda (1 2 0) 1 __tconst4Zcr91) (exists ref (1 0) 1 __tconst3wDH116) (exists ref (1 0) 1 __tconst5nWJ102) (exists lambda (1 2 0) 1 __tconst5nWJ102) (exists lambda (1 2 0) 1 __tconst3wDH116) (exists lambda (1 2 0) 1 __tconst3ktF111) (exists ref (1 0) 1 __tconst3ktF111) (join lambda (0 1 2) 2 __t3SEs120 __tconst82U8119 __t50Kk118) (join ref (1 0) 1 __tconst4V4L122 __t7aew98) (exists app (1 2 0) 1 __t7aew98) (join app (0 1 2) 2 __t7TEO99 __t7aew98 __t4fDK96) (join lambda (0 1 2) 2 __t4fDK96 __tconst4BKz104 __t8C0a94) (join ref (0 1) 2 __t8C0a94 __tconst4BKz104) (join ref (1 0) 1 __tconst0vRf84 __t2duR83) (join lambda (1 2 0) 2 __tconst0vRf84 __t2duR83 __t87vL85) (join ref (1 0) 1 __tconst4Zcr91 __t0C9F87) (exists app (2 0 1) 1 __t0C9F87) (join ref (1 0) 1 __tconst9zoW125 __t3Q2G89) (join app (1 2 0) 2 __t3Q2G89 __t0C9F87 __t2Eqd90) (join lambda (1 2 0) 2 __tconst4Zcr91 __t2Eqd90 __t3pgm92) (join ref (1 0) 1 __tconst3wDH116 __t3wir114) (exists app (1 2 0) 1 __t3wir114) (join ref (1 0) 1 __tconst5nWJ102 __t5MaG101) (join lambda (1 2 0) 2 __tconst5nWJ102 __t5MaG101 __t35jA103) (join lambda (1 2 0) 2 __tconst4BKz104 __t35jA103 __t6RuY105) (join app (1 2 0) 2 __t7aew98 __t6RuY105 __t2Z7m108) (join app (2 0 1) 2 __t2Z7m108 __t50Kk118 __t7CwH117) (join lambda (0 1 2) 2 __t7CwH117 __tconst3wDH116 __t44OM115) (join app (0 1 2) 2 __t44OM115 __t3wir114 __t8GWA112) (join lambda (0 1 2) 2 __t8GWA112 __tconst3ktF111 __t7ohz110) (join ref (0 1) 2 __t7ohz110 __tconst3ktF111)) (head (mkstruct lambda (1 2 0) __t5iMg123 __tconst4V4L122 __t1GdP121)) mcfa-counting.slog:241 #f)
  class ReadTask476 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex438;  slog::Index** lambdaindex439;  slog::Index** refindex440;  slog::Index** refindex441;  slog::Index** lambdaindex442;  slog::Index** refindex443;  slog::Index** refindex444;  slog::Index** lambdaindex445;  slog::Index** refindex446;  slog::Index** refindex447;  slog::Index** lambdaindex448;  slog::Index** lambdaindex449;  slog::Index** lambdaindex450;  slog::Index** refindex451;  slog::Index** lambdaindex452;  slog::Index** refindex453;  slog::Index** appindex454;  slog::Index** appindex455;  slog::Index** lambdaindex456;  slog::Index** refindex457;  slog::Index** refindex458;  slog::Index** lambdaindex459;  slog::Index** refindex460;  slog::Index** appindex461;  slog::Index** refindex462;  slog::Index** appindex463;  slog::Index** lambdaindex464;  slog::Index** refindex465;  slog::Index** appindex466;  slog::Index** refindex467;  slog::Index** lambdaindex468;  slog::Index** lambdaindex469;  slog::Index** appindex470;  slog::Index** appindex471;  slog::Index** lambdaindex472;  slog::Index** appindex473;  slog::Index** lambdaindex474;  slog::Index** refindex475;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      outer_rel = db->getRelation("app");
      std::vector<u16> ord477({1, 0});
      slog::Relation* readrel478 = db->getRelation("ref");
      refindex438 = readrel478->getIndex(ord477, false);
      std::vector<u16> ord479({1, 2, 0});
      slog::Relation* readrel480 = db->getRelation("lambda");
      lambdaindex439 = readrel480->getIndex(ord479, false);
      std::vector<u16> ord481({1, 0});
      slog::Relation* readrel482 = db->getRelation("ref");
      refindex440 = readrel482->getIndex(ord481, false);
      std::vector<u16> ord483({1, 0});
      slog::Relation* readrel484 = db->getRelation("ref");
      refindex441 = readrel484->getIndex(ord483, false);
      std::vector<u16> ord485({1, 2, 0});
      slog::Relation* readrel486 = db->getRelation("lambda");
      lambdaindex442 = readrel486->getIndex(ord485, false);
      std::vector<u16> ord487({1, 0});
      slog::Relation* readrel488 = db->getRelation("ref");
      refindex443 = readrel488->getIndex(ord487, false);
      std::vector<u16> ord489({1, 0});
      slog::Relation* readrel490 = db->getRelation("ref");
      refindex444 = readrel490->getIndex(ord489, false);
      std::vector<u16> ord491({1, 2, 0});
      slog::Relation* readrel492 = db->getRelation("lambda");
      lambdaindex445 = readrel492->getIndex(ord491, false);
      std::vector<u16> ord493({1, 0});
      slog::Relation* readrel494 = db->getRelation("ref");
      refindex446 = readrel494->getIndex(ord493, false);
      std::vector<u16> ord495({1, 0});
      slog::Relation* readrel496 = db->getRelation("ref");
      refindex447 = readrel496->getIndex(ord495, false);
      std::vector<u16> ord497({1, 2, 0});
      slog::Relation* readrel498 = db->getRelation("lambda");
      lambdaindex448 = readrel498->getIndex(ord497, false);
      std::vector<u16> ord499({1, 2, 0});
      slog::Relation* readrel500 = db->getRelation("lambda");
      lambdaindex449 = readrel500->getIndex(ord499, false);
      std::vector<u16> ord501({1, 2, 0});
      slog::Relation* readrel502 = db->getRelation("lambda");
      lambdaindex450 = readrel502->getIndex(ord501, false);
      std::vector<u16> ord503({1, 0});
      slog::Relation* readrel504 = db->getRelation("ref");
      refindex451 = readrel504->getIndex(ord503, false);
      std::vector<u16> ord505({0, 1, 2});
      slog::Relation* readrel506 = db->getRelation("lambda");
      lambdaindex452 = readrel506->getIndex(ord505, false);
      std::vector<u16> ord507({1, 0});
      slog::Relation* readrel508 = db->getRelation("ref");
      refindex453 = readrel508->getIndex(ord507, false);
      std::vector<u16> ord509({1, 2, 0});
      slog::Relation* readrel510 = db->getRelation("app");
      appindex454 = readrel510->getIndex(ord509, false);
      std::vector<u16> ord511({0, 1, 2});
      slog::Relation* readrel512 = db->getRelation("app");
      appindex455 = readrel512->getIndex(ord511, false);
      std::vector<u16> ord513({0, 1, 2});
      slog::Relation* readrel514 = db->getRelation("lambda");
      lambdaindex456 = readrel514->getIndex(ord513, false);
      std::vector<u16> ord515({0, 1});
      slog::Relation* readrel516 = db->getRelation("ref");
      refindex457 = readrel516->getIndex(ord515, false);
      std::vector<u16> ord517({1, 0});
      slog::Relation* readrel518 = db->getRelation("ref");
      refindex458 = readrel518->getIndex(ord517, false);
      std::vector<u16> ord519({1, 2, 0});
      slog::Relation* readrel520 = db->getRelation("lambda");
      lambdaindex459 = readrel520->getIndex(ord519, false);
      std::vector<u16> ord521({1, 0});
      slog::Relation* readrel522 = db->getRelation("ref");
      refindex460 = readrel522->getIndex(ord521, false);
      std::vector<u16> ord523({2, 0, 1});
      slog::Relation* readrel524 = db->getRelation("app");
      appindex461 = readrel524->getIndex(ord523, false);
      std::vector<u16> ord525({1, 0});
      slog::Relation* readrel526 = db->getRelation("ref");
      refindex462 = readrel526->getIndex(ord525, false);
      std::vector<u16> ord527({1, 2, 0});
      slog::Relation* readrel528 = db->getRelation("app");
      appindex463 = readrel528->getIndex(ord527, false);
      std::vector<u16> ord529({1, 2, 0});
      slog::Relation* readrel530 = db->getRelation("lambda");
      lambdaindex464 = readrel530->getIndex(ord529, false);
      std::vector<u16> ord531({1, 0});
      slog::Relation* readrel532 = db->getRelation("ref");
      refindex465 = readrel532->getIndex(ord531, false);
      std::vector<u16> ord533({1, 2, 0});
      slog::Relation* readrel534 = db->getRelation("app");
      appindex466 = readrel534->getIndex(ord533, false);
      std::vector<u16> ord535({1, 0});
      slog::Relation* readrel536 = db->getRelation("ref");
      refindex467 = readrel536->getIndex(ord535, false);
      std::vector<u16> ord537({1, 2, 0});
      slog::Relation* readrel538 = db->getRelation("lambda");
      lambdaindex468 = readrel538->getIndex(ord537, false);
      std::vector<u16> ord539({1, 2, 0});
      slog::Relation* readrel540 = db->getRelation("lambda");
      lambdaindex469 = readrel540->getIndex(ord539, false);
      std::vector<u16> ord541({1, 2, 0});
      slog::Relation* readrel542 = db->getRelation("app");
      appindex470 = readrel542->getIndex(ord541, false);
      std::vector<u16> ord543({2, 0, 1});
      slog::Relation* readrel544 = db->getRelation("app");
      appindex471 = readrel544->getIndex(ord543, false);
      std::vector<u16> ord545({0, 1, 2});
      slog::Relation* readrel546 = db->getRelation("lambda");
      lambdaindex472 = readrel546->getIndex(ord545, false);
      std::vector<u16> ord547({0, 1, 2});
      slog::Relation* readrel548 = db->getRelation("app");
      appindex473 = readrel548->getIndex(ord547, false);
      std::vector<u16> ord549({0, 1, 2});
      slog::Relation* readrel550 = db->getRelation("lambda");
      lambdaindex474 = readrel550->getIndex(ord549, false);
      std::vector<u16> ord551({0, 1});
      slog::Relation* readrel552 = db->getRelation("ref");
      refindex475 = readrel552->getIndex(ord551, false);
  
    }
    ReadTask476(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c93 = v_const7c7d2cfc66f4d976987d2d20;
      u64 v_c94 = v_const6bc0ba365ada70df115e1785;
      u64 v_c95 = v_consta8180db1c2f300980314f910;
      u64 v_c96 = v_const9a67f28c6b77e842f439a84a;
      u64 v_c97 = v_conste58dec6bca6f63ef79c3b755;
      u64 v_c98 = v_const0f8748be649f8ee4066bb1d7;
      u64 v_c99 = v_constd5f017533ea574d5f9b3400c;
      u64 v_c100 = v_const990b444cbd47632035b2fa1a;
      u64 v_c101 = v_const4f84f41d89b6b717419b4eaa;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c102 = _t[0];
        u64 v_c103 = _t[1];
        u64 v_c104 = _t[2];
        if (!slog::exists_probe<2,1>(refindex438, std::array<u64,2>{v_c94, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex439, std::array<u64,3>{v_c98, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex440, std::array<u64,2>{v_c98, 0})) return;
        if (!slog::exists_probe<2,1>(refindex441, std::array<u64,2>{v_c97, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex442, std::array<u64,3>{v_c97, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex443, std::array<u64,2>{v_c96, 0})) return;
        if (!slog::exists_probe<2,1>(refindex444, std::array<u64,2>{v_c93, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex445, std::array<u64,3>{v_c96, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex446, std::array<u64,2>{v_c99, 0})) return;
        if (!slog::exists_probe<2,1>(refindex447, std::array<u64,2>{v_c101, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex448, std::array<u64,3>{v_c101, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex449, std::array<u64,3>{v_c99, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex450, std::array<u64,3>{v_c100, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex451, std::array<u64,2>{v_c100, 0})) return;
        slog::join_probe<3,2>(lambdaindex452, std::array<u64,3>{v_c103, v_c95, 0}, [&](const std::array<u64,3>& m553) {
          u64 v_c105 = m553[2];
          slog::join_probe<2,1>(refindex453, std::array<u64,2>{v_c94, 0}, [&](const std::array<u64,2>& m554) {
            u64 v_c106 = m554[1];
            if (!slog::exists_probe<3,1>(appindex454, std::array<u64,3>{v_c106, 0, 0})) return;
            slog::join_probe<3,2>(appindex455, std::array<u64,3>{v_c104, v_c106, 0}, [&](const std::array<u64,3>& m555) {
              u64 v_c107 = m555[2];
              slog::join_probe<3,2>(lambdaindex456, std::array<u64,3>{v_c107, v_c98, 0}, [&](const std::array<u64,3>& m556) {
                u64 v_c108 = m556[2];
                slog::join_probe<2,2>(refindex457, std::array<u64,2>{v_c108, v_c98}, [&](const std::array<u64,2>& m557) {
                  slog::join_probe<2,1>(refindex458, std::array<u64,2>{v_c97, 0}, [&](const std::array<u64,2>& m558) {
                    u64 v_c109 = m558[1];
                    slog::join_probe<3,2>(lambdaindex459, std::array<u64,3>{v_c97, v_c109, 0}, [&](const std::array<u64,3>& m559) {
                      u64 v_c110 = m559[2];
                      slog::join_probe<2,1>(refindex460, std::array<u64,2>{v_c96, 0}, [&](const std::array<u64,2>& m560) {
                        u64 v_c111 = m560[1];
                        if (!slog::exists_probe<3,1>(appindex461, std::array<u64,3>{v_c111, 0, 0})) return;
                        slog::join_probe<2,1>(refindex462, std::array<u64,2>{v_c93, 0}, [&](const std::array<u64,2>& m561) {
                          u64 v_c112 = m561[1];
                          slog::join_probe<3,2>(appindex463, std::array<u64,3>{v_c112, v_c111, 0}, [&](const std::array<u64,3>& m562) {
                            u64 v_c113 = m562[2];
                            slog::join_probe<3,2>(lambdaindex464, std::array<u64,3>{v_c96, v_c113, 0}, [&](const std::array<u64,3>& m563) {
                              u64 v_c114 = m563[2];
                              slog::join_probe<2,1>(refindex465, std::array<u64,2>{v_c99, 0}, [&](const std::array<u64,2>& m564) {
                                u64 v_c115 = m564[1];
                                if (!slog::exists_probe<3,1>(appindex466, std::array<u64,3>{v_c115, 0, 0})) return;
                                slog::join_probe<2,1>(refindex467, std::array<u64,2>{v_c101, 0}, [&](const std::array<u64,2>& m565) {
                                  u64 v_c116 = m565[1];
                                  slog::join_probe<3,2>(lambdaindex468, std::array<u64,3>{v_c101, v_c116, 0}, [&](const std::array<u64,3>& m566) {
                                    u64 v_c117 = m566[2];
                                    slog::join_probe<3,2>(lambdaindex469, std::array<u64,3>{v_c98, v_c117, 0}, [&](const std::array<u64,3>& m567) {
                                      u64 v_c118 = m567[2];
                                      slog::join_probe<3,2>(appindex470, std::array<u64,3>{v_c106, v_c118, 0}, [&](const std::array<u64,3>& m568) {
                                        u64 v_c119 = m568[2];
                                        slog::join_probe<3,2>(appindex471, std::array<u64,3>{v_c119, v_c105, 0}, [&](const std::array<u64,3>& m569) {
                                          u64 v_c120 = m569[2];
                                          slog::join_probe<3,2>(lambdaindex472, std::array<u64,3>{v_c120, v_c99, 0}, [&](const std::array<u64,3>& m570) {
                                            u64 v_c121 = m570[2];
                                            slog::join_probe<3,2>(appindex473, std::array<u64,3>{v_c121, v_c115, 0}, [&](const std::array<u64,3>& m571) {
                                              u64 v_c122 = m571[2];
                                              slog::join_probe<3,2>(lambdaindex474, std::array<u64,3>{v_c122, v_c100, 0}, [&](const std::array<u64,3>& m572) {
                                                u64 v_c123 = m572[2];
                                                slog::join_probe<2,2>(refindex475, std::array<u64,2>{v_c123, v_c100}, [&](const std::array<u64,2>& m573) {
                                                  ++_fires;
                                                  slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c94, v_c102}, std::array<u16,3>{1, 2, 0});
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
  
      if (_fires) db->bumpFires("mcfa-counting.slog:241", "delta:app", _fires);
  
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
  // (crule (pre (let __tconst9zoW125 const7c7d2cfc66f4d976987d2d20) (let __tconst4V4L122 const6bc0ba365ada70df115e1785) (let __tconst82U8119 consta8180db1c2f300980314f910) (let __tconst3wDH116 constd5f017533ea574d5f9b3400c) (let __tconst4BKz104 const0f8748be649f8ee4066bb1d7) (let __tconst4Zcr91 const9a67f28c6b77e842f439a84a) (let __tconst0vRf84 conste58dec6bca6f63ef79c3b755) (let __tconst3ktF111 const990b444cbd47632035b2fa1a) (let __tconst5nWJ102 const4f84f41d89b6b717419b4eaa)) (seeded) (body (join ref (1 0) 1 __tconst4V4L122 __t7aew98) (exists ref (1 0) 1 __tconst0vRf84) (exists lambda (1 2 0) 1 __tconst0vRf84) (exists ref (1 0) 1 __tconst4Zcr91) (exists ref (1 0) 1 __tconst9zoW125) (exists lambda (1 2 0) 1 __tconst4Zcr91) (exists ref (1 0) 1 __tconst4BKz104) (exists lambda (1 2 0) 1 __tconst4BKz104) (exists app (1 2 0) 1 __t7aew98) (exists ref (1 0) 1 __tconst5nWJ102) (exists lambda (1 2 0) 1 __tconst5nWJ102) (exists ref (1 0) 1 __tconst3ktF111) (exists lambda (1 2 0) 1 __tconst3ktF111) (exists lambda (1 2 0) 1 __tconst3wDH116) (join ref (1 0) 1 __tconst3wDH116 __t3wir114) (exists app (1 2 0) 1 __t3wir114) (join ref (1 0) 1 __tconst0vRf84 __t2duR83) (join lambda (1 2 0) 2 __tconst0vRf84 __t2duR83 __t87vL85) (join ref (1 0) 1 __tconst4Zcr91 __t0C9F87) (exists app (2 0 1) 1 __t0C9F87) (join ref (1 0) 1 __tconst9zoW125 __t3Q2G89) (join app (1 2 0) 2 __t3Q2G89 __t0C9F87 __t2Eqd90) (join lambda (1 2 0) 2 __tconst4Zcr91 __t2Eqd90 __t3pgm92) (join ref (1 0) 1 __tconst4BKz104 __t8C0a94) (join lambda (1 2 0) 2 __tconst4BKz104 __t8C0a94 __t4fDK96) (join app (1 2 0) 2 __t7aew98 __t4fDK96 __t7TEO99) (join ref (1 0) 1 __tconst5nWJ102 __t5MaG101) (join lambda (1 2 0) 2 __tconst5nWJ102 __t5MaG101 __t35jA103) (join lambda (1 2 0) 2 __tconst4BKz104 __t35jA103 __t6RuY105) (join app (1 2 0) 2 __t7aew98 __t6RuY105 __t2Z7m108) (join ref (1 0) 1 __tconst3ktF111 __t7ohz110) (join lambda (1 2 0) 2 __tconst3ktF111 __t7ohz110 __t8GWA112) (join app (1 2 0) 2 __t3wir114 __t8GWA112 __t44OM115) (join lambda (1 2 0) 2 __tconst3wDH116 __t44OM115 __t7CwH117)) (head (mkstruct app (1 2 0) __t50Kk118 __t7CwH117 __t2Z7m108)) mcfa-counting.slog:241 #f)
  class ReadTask608 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex574;  slog::Index** refindex575;  slog::Index** lambdaindex576;  slog::Index** refindex577;  slog::Index** refindex578;  slog::Index** lambdaindex579;  slog::Index** refindex580;  slog::Index** lambdaindex581;  slog::Index** appindex582;  slog::Index** refindex583;  slog::Index** lambdaindex584;  slog::Index** refindex585;  slog::Index** lambdaindex586;  slog::Index** lambdaindex587;  slog::Index** refindex588;  slog::Index** appindex589;  slog::Index** refindex590;  slog::Index** lambdaindex591;  slog::Index** refindex592;  slog::Index** appindex593;  slog::Index** refindex594;  slog::Index** appindex595;  slog::Index** lambdaindex596;  slog::Index** refindex597;  slog::Index** lambdaindex598;  slog::Index** appindex599;  slog::Index** refindex600;  slog::Index** lambdaindex601;  slog::Index** lambdaindex602;  slog::Index** appindex603;  slog::Index** refindex604;  slog::Index** lambdaindex605;  slog::Index** appindex606;  slog::Index** lambdaindex607;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord609({1, 2, 0});
      slog::Relation* readrel610 = db->getRelation("app");
      head_index[0] = readrel610->getIndex(ord609, false);
      std::vector<u16> ord611({1, 0});
      slog::Relation* readrel612 = db->getRelation("ref");
      refindex574 = readrel612->getIndex(ord611, false);
      std::vector<u16> ord613({1, 0});
      slog::Relation* readrel614 = db->getRelation("ref");
      refindex575 = readrel614->getIndex(ord613, false);
      std::vector<u16> ord615({1, 2, 0});
      slog::Relation* readrel616 = db->getRelation("lambda");
      lambdaindex576 = readrel616->getIndex(ord615, false);
      std::vector<u16> ord617({1, 0});
      slog::Relation* readrel618 = db->getRelation("ref");
      refindex577 = readrel618->getIndex(ord617, false);
      std::vector<u16> ord619({1, 0});
      slog::Relation* readrel620 = db->getRelation("ref");
      refindex578 = readrel620->getIndex(ord619, false);
      std::vector<u16> ord621({1, 2, 0});
      slog::Relation* readrel622 = db->getRelation("lambda");
      lambdaindex579 = readrel622->getIndex(ord621, false);
      std::vector<u16> ord623({1, 0});
      slog::Relation* readrel624 = db->getRelation("ref");
      refindex580 = readrel624->getIndex(ord623, false);
      std::vector<u16> ord625({1, 2, 0});
      slog::Relation* readrel626 = db->getRelation("lambda");
      lambdaindex581 = readrel626->getIndex(ord625, false);
      std::vector<u16> ord627({1, 2, 0});
      slog::Relation* readrel628 = db->getRelation("app");
      appindex582 = readrel628->getIndex(ord627, false);
      std::vector<u16> ord629({1, 0});
      slog::Relation* readrel630 = db->getRelation("ref");
      refindex583 = readrel630->getIndex(ord629, false);
      std::vector<u16> ord631({1, 2, 0});
      slog::Relation* readrel632 = db->getRelation("lambda");
      lambdaindex584 = readrel632->getIndex(ord631, false);
      std::vector<u16> ord633({1, 0});
      slog::Relation* readrel634 = db->getRelation("ref");
      refindex585 = readrel634->getIndex(ord633, false);
      std::vector<u16> ord635({1, 2, 0});
      slog::Relation* readrel636 = db->getRelation("lambda");
      lambdaindex586 = readrel636->getIndex(ord635, false);
      std::vector<u16> ord637({1, 2, 0});
      slog::Relation* readrel638 = db->getRelation("lambda");
      lambdaindex587 = readrel638->getIndex(ord637, false);
      std::vector<u16> ord639({1, 0});
      slog::Relation* readrel640 = db->getRelation("ref");
      refindex588 = readrel640->getIndex(ord639, false);
      std::vector<u16> ord641({1, 2, 0});
      slog::Relation* readrel642 = db->getRelation("app");
      appindex589 = readrel642->getIndex(ord641, false);
      std::vector<u16> ord643({1, 0});
      slog::Relation* readrel644 = db->getRelation("ref");
      refindex590 = readrel644->getIndex(ord643, false);
      std::vector<u16> ord645({1, 2, 0});
      slog::Relation* readrel646 = db->getRelation("lambda");
      lambdaindex591 = readrel646->getIndex(ord645, false);
      std::vector<u16> ord647({1, 0});
      slog::Relation* readrel648 = db->getRelation("ref");
      refindex592 = readrel648->getIndex(ord647, false);
      std::vector<u16> ord649({2, 0, 1});
      slog::Relation* readrel650 = db->getRelation("app");
      appindex593 = readrel650->getIndex(ord649, false);
      std::vector<u16> ord651({1, 0});
      slog::Relation* readrel652 = db->getRelation("ref");
      refindex594 = readrel652->getIndex(ord651, false);
      std::vector<u16> ord653({1, 2, 0});
      slog::Relation* readrel654 = db->getRelation("app");
      appindex595 = readrel654->getIndex(ord653, false);
      std::vector<u16> ord655({1, 2, 0});
      slog::Relation* readrel656 = db->getRelation("lambda");
      lambdaindex596 = readrel656->getIndex(ord655, false);
      std::vector<u16> ord657({1, 0});
      slog::Relation* readrel658 = db->getRelation("ref");
      refindex597 = readrel658->getIndex(ord657, false);
      std::vector<u16> ord659({1, 2, 0});
      slog::Relation* readrel660 = db->getRelation("lambda");
      lambdaindex598 = readrel660->getIndex(ord659, false);
      std::vector<u16> ord661({1, 2, 0});
      slog::Relation* readrel662 = db->getRelation("app");
      appindex599 = readrel662->getIndex(ord661, false);
      std::vector<u16> ord663({1, 0});
      slog::Relation* readrel664 = db->getRelation("ref");
      refindex600 = readrel664->getIndex(ord663, false);
      std::vector<u16> ord665({1, 2, 0});
      slog::Relation* readrel666 = db->getRelation("lambda");
      lambdaindex601 = readrel666->getIndex(ord665, false);
      std::vector<u16> ord667({1, 2, 0});
      slog::Relation* readrel668 = db->getRelation("lambda");
      lambdaindex602 = readrel668->getIndex(ord667, false);
      std::vector<u16> ord669({1, 2, 0});
      slog::Relation* readrel670 = db->getRelation("app");
      appindex603 = readrel670->getIndex(ord669, false);
      std::vector<u16> ord671({1, 0});
      slog::Relation* readrel672 = db->getRelation("ref");
      refindex604 = readrel672->getIndex(ord671, false);
      std::vector<u16> ord673({1, 2, 0});
      slog::Relation* readrel674 = db->getRelation("lambda");
      lambdaindex605 = readrel674->getIndex(ord673, false);
      std::vector<u16> ord675({1, 2, 0});
      slog::Relation* readrel676 = db->getRelation("app");
      appindex606 = readrel676->getIndex(ord675, false);
      std::vector<u16> ord677({1, 2, 0});
      slog::Relation* readrel678 = db->getRelation("lambda");
      lambdaindex607 = readrel678->getIndex(ord677, false);
  
    }
    ReadTask608(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c93 = v_const7c7d2cfc66f4d976987d2d20;
      u64 v_c94 = v_const6bc0ba365ada70df115e1785;
      u64 v_c95 = v_consta8180db1c2f300980314f910;
      u64 v_c99 = v_constd5f017533ea574d5f9b3400c;
      u64 v_c98 = v_const0f8748be649f8ee4066bb1d7;
      u64 v_c96 = v_const9a67f28c6b77e842f439a84a;
      u64 v_c97 = v_conste58dec6bca6f63ef79c3b755;
      u64 v_c100 = v_const990b444cbd47632035b2fa1a;
      u64 v_c101 = v_const4f84f41d89b6b717419b4eaa;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex574, std::array<u64,2>{v_c94, 0}, [&](const std::array<u64,2>& m679) {
        u64 v_c106 = m679[1];
        if (!slog::exists_probe<2,1>(refindex575, std::array<u64,2>{v_c97, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex576, std::array<u64,3>{v_c97, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex577, std::array<u64,2>{v_c96, 0})) return;
        if (!slog::exists_probe<2,1>(refindex578, std::array<u64,2>{v_c93, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex579, std::array<u64,3>{v_c96, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex580, std::array<u64,2>{v_c98, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex581, std::array<u64,3>{v_c98, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex582, std::array<u64,3>{v_c106, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex583, std::array<u64,2>{v_c101, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex584, std::array<u64,3>{v_c101, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex585, std::array<u64,2>{v_c100, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex586, std::array<u64,3>{v_c100, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex587, std::array<u64,3>{v_c99, 0, 0})) return;
        slog::join_probe<2,1>(refindex588, std::array<u64,2>{v_c99, 0}, [&](const std::array<u64,2>& m680) {
          u64 v_c115 = m680[1];
          if (!slog::exists_probe<3,1>(appindex589, std::array<u64,3>{v_c115, 0, 0})) return;
          slog::join_probe<2,1>(refindex590, std::array<u64,2>{v_c97, 0}, [&](const std::array<u64,2>& m681) {
            u64 v_c109 = m681[1];
            slog::join_probe<3,2>(lambdaindex591, std::array<u64,3>{v_c97, v_c109, 0}, [&](const std::array<u64,3>& m682) {
              u64 v_c110 = m682[2];
              slog::join_probe<2,1>(refindex592, std::array<u64,2>{v_c96, 0}, [&](const std::array<u64,2>& m683) {
                u64 v_c111 = m683[1];
                if (!slog::exists_probe<3,1>(appindex593, std::array<u64,3>{v_c111, 0, 0})) return;
                slog::join_probe<2,1>(refindex594, std::array<u64,2>{v_c93, 0}, [&](const std::array<u64,2>& m684) {
                  u64 v_c112 = m684[1];
                  slog::join_probe<3,2>(appindex595, std::array<u64,3>{v_c112, v_c111, 0}, [&](const std::array<u64,3>& m685) {
                    u64 v_c113 = m685[2];
                    slog::join_probe<3,2>(lambdaindex596, std::array<u64,3>{v_c96, v_c113, 0}, [&](const std::array<u64,3>& m686) {
                      u64 v_c114 = m686[2];
                      slog::join_probe<2,1>(refindex597, std::array<u64,2>{v_c98, 0}, [&](const std::array<u64,2>& m687) {
                        u64 v_c108 = m687[1];
                        slog::join_probe<3,2>(lambdaindex598, std::array<u64,3>{v_c98, v_c108, 0}, [&](const std::array<u64,3>& m688) {
                          u64 v_c107 = m688[2];
                          slog::join_probe<3,2>(appindex599, std::array<u64,3>{v_c106, v_c107, 0}, [&](const std::array<u64,3>& m689) {
                            u64 v_c104 = m689[2];
                            slog::join_probe<2,1>(refindex600, std::array<u64,2>{v_c101, 0}, [&](const std::array<u64,2>& m690) {
                              u64 v_c116 = m690[1];
                              slog::join_probe<3,2>(lambdaindex601, std::array<u64,3>{v_c101, v_c116, 0}, [&](const std::array<u64,3>& m691) {
                                u64 v_c117 = m691[2];
                                slog::join_probe<3,2>(lambdaindex602, std::array<u64,3>{v_c98, v_c117, 0}, [&](const std::array<u64,3>& m692) {
                                  u64 v_c118 = m692[2];
                                  slog::join_probe<3,2>(appindex603, std::array<u64,3>{v_c106, v_c118, 0}, [&](const std::array<u64,3>& m693) {
                                    u64 v_c119 = m693[2];
                                    slog::join_probe<2,1>(refindex604, std::array<u64,2>{v_c100, 0}, [&](const std::array<u64,2>& m694) {
                                      u64 v_c123 = m694[1];
                                      slog::join_probe<3,2>(lambdaindex605, std::array<u64,3>{v_c100, v_c123, 0}, [&](const std::array<u64,3>& m695) {
                                        u64 v_c122 = m695[2];
                                        slog::join_probe<3,2>(appindex606, std::array<u64,3>{v_c115, v_c122, 0}, [&](const std::array<u64,3>& m696) {
                                          u64 v_c121 = m696[2];
                                          slog::join_probe<3,2>(lambdaindex607, std::array<u64,3>{v_c99, v_c121, 0}, [&](const std::array<u64,3>& m697) {
                                            u64 v_c120 = m697[2];
                                            ++_fires;
                                            slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c120, v_c119}, std::array<u16,3>{1, 2, 0});
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
      s->addTaskSeeded(phase_read, new ReadTask608(db,b));
  // (crule (pre (let __tconst1pJW313 constb49bea2fcccd8f4301a347ed) (let __tconst2Yzp284 const8ca682693a0738a0641c6956) (let __tconst7LWP310 const66518c0c1b3a5a0b09ae2ef1) (let __tconst5PoN291 constc85eae03730a4f4cf1d66a0c) (let __tconst0sqO307 const4a8acfc71441e0695ffcf5b3) (let __tconst9rZO295 const576506f61f53440f1edd95d2) (let __tconst2CSv302 const229c0b7aa8a7eb4055f5a3d0)) (seeded) (body (join ref (1 0) 1 __tconst2Yzp284 __t248W283) (exists ref (1 0) 1 __tconst1pJW313) (exists ref (1 0) 1 __tconst7LWP310) (exists ref (1 0) 1 __tconst9rZO295) (exists lambda (1 2 0) 1 __tconst9rZO295) (exists ref (1 0) 1 __tconst2CSv302) (exists lambda (1 2 0) 1 __tconst2CSv302) (exists lambda (1 2 0) 1 __tconst0sqO307) (exists lambda (1 2 0) 1 __tconst7LWP310) (exists lambda (1 2 0) 1 __tconst5PoN291) (exists lambda (1 2 0) 1 __tconst1pJW313) (join lambda (1 2 0) 2 __tconst2Yzp284 __t248W283 __t0oFu285) (join ref (1 0) 1 __tconst1pJW313 __t165O287) (exists app (1 2 0) 1 __t165O287) (join ref (1 0) 1 __tconst7LWP310 __t91H2298) (exists app (1 2 0) 1 __t91H2298) (join ref (1 0) 1 __tconst9rZO295 __t71w7294) (join lambda (1 2 0) 2 __tconst9rZO295 __t71w7294 __t3dkk296) (join app (1 2 0) 2 __t91H2298 __t3dkk296 __t4LtH299) (exists app (2 0 1) 1 __t4LtH299) (join ref (1 0) 1 __tconst2CSv302 __t6lXa301) (join lambda (1 2 0) 2 __tconst2CSv302 __t6lXa301 __t7EW2303) (join app (1 2 0) 2 __t91H2298 __t7EW2303 __t4HUX306) (join lambda (1 2 0) 2 __tconst0sqO307 __t4HUX306 __t0vn1308) (join app (1 2 0) 2 __t0vn1308 __t4LtH299 __t6t9L309) (join lambda (1 2 0) 2 __tconst7LWP310 __t6t9L309 __t5T0g311) (exists app (1 2 0) 1 __t5T0g311) (join app (1 2 0) 1 __t165O287 dup1kqj388 __t30Ec290) (eq __t165O287 dup1kqj388) (join lambda (1 2 0) 2 __tconst5PoN291 __t30Ec290 __t7aCZ292) (join app (1 2 0) 2 __t5T0g311 __t7aCZ292 __t3Izn312) (join lambda (1 2 0) 2 __tconst1pJW313 __t3Izn312 __t7Qbz314)) (head (mkstruct app (1 2 0) __t1Lkt315 __t7Qbz314 __t0oFu285)) mcfa-counting.slog:194 #f)
  class ReadTask729 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex698;  slog::Index** refindex699;  slog::Index** refindex700;  slog::Index** refindex701;  slog::Index** lambdaindex702;  slog::Index** refindex703;  slog::Index** lambdaindex704;  slog::Index** lambdaindex705;  slog::Index** lambdaindex706;  slog::Index** lambdaindex707;  slog::Index** lambdaindex708;  slog::Index** lambdaindex709;  slog::Index** refindex710;  slog::Index** appindex711;  slog::Index** refindex712;  slog::Index** appindex713;  slog::Index** refindex714;  slog::Index** lambdaindex715;  slog::Index** appindex716;  slog::Index** appindex717;  slog::Index** refindex718;  slog::Index** lambdaindex719;  slog::Index** appindex720;  slog::Index** lambdaindex721;  slog::Index** appindex722;  slog::Index** lambdaindex723;  slog::Index** appindex724;  slog::Index** appindex725;  slog::Index** lambdaindex726;  slog::Index** appindex727;  slog::Index** lambdaindex728;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord730({1, 2, 0});
      slog::Relation* readrel731 = db->getRelation("app");
      head_index[0] = readrel731->getIndex(ord730, false);
      std::vector<u16> ord732({1, 0});
      slog::Relation* readrel733 = db->getRelation("ref");
      refindex698 = readrel733->getIndex(ord732, false);
      std::vector<u16> ord734({1, 0});
      slog::Relation* readrel735 = db->getRelation("ref");
      refindex699 = readrel735->getIndex(ord734, false);
      std::vector<u16> ord736({1, 0});
      slog::Relation* readrel737 = db->getRelation("ref");
      refindex700 = readrel737->getIndex(ord736, false);
      std::vector<u16> ord738({1, 0});
      slog::Relation* readrel739 = db->getRelation("ref");
      refindex701 = readrel739->getIndex(ord738, false);
      std::vector<u16> ord740({1, 2, 0});
      slog::Relation* readrel741 = db->getRelation("lambda");
      lambdaindex702 = readrel741->getIndex(ord740, false);
      std::vector<u16> ord742({1, 0});
      slog::Relation* readrel743 = db->getRelation("ref");
      refindex703 = readrel743->getIndex(ord742, false);
      std::vector<u16> ord744({1, 2, 0});
      slog::Relation* readrel745 = db->getRelation("lambda");
      lambdaindex704 = readrel745->getIndex(ord744, false);
      std::vector<u16> ord746({1, 2, 0});
      slog::Relation* readrel747 = db->getRelation("lambda");
      lambdaindex705 = readrel747->getIndex(ord746, false);
      std::vector<u16> ord748({1, 2, 0});
      slog::Relation* readrel749 = db->getRelation("lambda");
      lambdaindex706 = readrel749->getIndex(ord748, false);
      std::vector<u16> ord750({1, 2, 0});
      slog::Relation* readrel751 = db->getRelation("lambda");
      lambdaindex707 = readrel751->getIndex(ord750, false);
      std::vector<u16> ord752({1, 2, 0});
      slog::Relation* readrel753 = db->getRelation("lambda");
      lambdaindex708 = readrel753->getIndex(ord752, false);
      std::vector<u16> ord754({1, 2, 0});
      slog::Relation* readrel755 = db->getRelation("lambda");
      lambdaindex709 = readrel755->getIndex(ord754, false);
      std::vector<u16> ord756({1, 0});
      slog::Relation* readrel757 = db->getRelation("ref");
      refindex710 = readrel757->getIndex(ord756, false);
      std::vector<u16> ord758({1, 2, 0});
      slog::Relation* readrel759 = db->getRelation("app");
      appindex711 = readrel759->getIndex(ord758, false);
      std::vector<u16> ord760({1, 0});
      slog::Relation* readrel761 = db->getRelation("ref");
      refindex712 = readrel761->getIndex(ord760, false);
      std::vector<u16> ord762({1, 2, 0});
      slog::Relation* readrel763 = db->getRelation("app");
      appindex713 = readrel763->getIndex(ord762, false);
      std::vector<u16> ord764({1, 0});
      slog::Relation* readrel765 = db->getRelation("ref");
      refindex714 = readrel765->getIndex(ord764, false);
      std::vector<u16> ord766({1, 2, 0});
      slog::Relation* readrel767 = db->getRelation("lambda");
      lambdaindex715 = readrel767->getIndex(ord766, false);
      std::vector<u16> ord768({1, 2, 0});
      slog::Relation* readrel769 = db->getRelation("app");
      appindex716 = readrel769->getIndex(ord768, false);
      std::vector<u16> ord770({2, 0, 1});
      slog::Relation* readrel771 = db->getRelation("app");
      appindex717 = readrel771->getIndex(ord770, false);
      std::vector<u16> ord772({1, 0});
      slog::Relation* readrel773 = db->getRelation("ref");
      refindex718 = readrel773->getIndex(ord772, false);
      std::vector<u16> ord774({1, 2, 0});
      slog::Relation* readrel775 = db->getRelation("lambda");
      lambdaindex719 = readrel775->getIndex(ord774, false);
      std::vector<u16> ord776({1, 2, 0});
      slog::Relation* readrel777 = db->getRelation("app");
      appindex720 = readrel777->getIndex(ord776, false);
      std::vector<u16> ord778({1, 2, 0});
      slog::Relation* readrel779 = db->getRelation("lambda");
      lambdaindex721 = readrel779->getIndex(ord778, false);
      std::vector<u16> ord780({1, 2, 0});
      slog::Relation* readrel781 = db->getRelation("app");
      appindex722 = readrel781->getIndex(ord780, false);
      std::vector<u16> ord782({1, 2, 0});
      slog::Relation* readrel783 = db->getRelation("lambda");
      lambdaindex723 = readrel783->getIndex(ord782, false);
      std::vector<u16> ord784({1, 2, 0});
      slog::Relation* readrel785 = db->getRelation("app");
      appindex724 = readrel785->getIndex(ord784, false);
      std::vector<u16> ord786({1, 2, 0});
      slog::Relation* readrel787 = db->getRelation("app");
      appindex725 = readrel787->getIndex(ord786, false);
      std::vector<u16> ord788({1, 2, 0});
      slog::Relation* readrel789 = db->getRelation("lambda");
      lambdaindex726 = readrel789->getIndex(ord788, false);
      std::vector<u16> ord790({1, 2, 0});
      slog::Relation* readrel791 = db->getRelation("app");
      appindex727 = readrel791->getIndex(ord790, false);
      std::vector<u16> ord792({1, 2, 0});
      slog::Relation* readrel793 = db->getRelation("lambda");
      lambdaindex728 = readrel793->getIndex(ord792, false);
  
    }
    ReadTask729(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c124 = v_constb49bea2fcccd8f4301a347ed;
      u64 v_c125 = v_const8ca682693a0738a0641c6956;
      u64 v_c126 = v_const66518c0c1b3a5a0b09ae2ef1;
      u64 v_c127 = v_constc85eae03730a4f4cf1d66a0c;
      u64 v_c128 = v_const4a8acfc71441e0695ffcf5b3;
      u64 v_c129 = v_const576506f61f53440f1edd95d2;
      u64 v_c130 = v_const229c0b7aa8a7eb4055f5a3d0;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex698, std::array<u64,2>{v_c125, 0}, [&](const std::array<u64,2>& m794) {
        u64 v_c131 = m794[1];
        if (!slog::exists_probe<2,1>(refindex699, std::array<u64,2>{v_c124, 0})) return;
        if (!slog::exists_probe<2,1>(refindex700, std::array<u64,2>{v_c126, 0})) return;
        if (!slog::exists_probe<2,1>(refindex701, std::array<u64,2>{v_c129, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex702, std::array<u64,3>{v_c129, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex703, std::array<u64,2>{v_c130, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex704, std::array<u64,3>{v_c130, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex705, std::array<u64,3>{v_c128, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex706, std::array<u64,3>{v_c126, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex707, std::array<u64,3>{v_c127, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex708, std::array<u64,3>{v_c124, 0, 0})) return;
        slog::join_probe<3,2>(lambdaindex709, std::array<u64,3>{v_c125, v_c131, 0}, [&](const std::array<u64,3>& m795) {
          u64 v_c132 = m795[2];
          slog::join_probe<2,1>(refindex710, std::array<u64,2>{v_c124, 0}, [&](const std::array<u64,2>& m796) {
            u64 v_c133 = m796[1];
            if (!slog::exists_probe<3,1>(appindex711, std::array<u64,3>{v_c133, 0, 0})) return;
            slog::join_probe<2,1>(refindex712, std::array<u64,2>{v_c126, 0}, [&](const std::array<u64,2>& m797) {
              u64 v_c134 = m797[1];
              if (!slog::exists_probe<3,1>(appindex713, std::array<u64,3>{v_c134, 0, 0})) return;
              slog::join_probe<2,1>(refindex714, std::array<u64,2>{v_c129, 0}, [&](const std::array<u64,2>& m798) {
                u64 v_c135 = m798[1];
                slog::join_probe<3,2>(lambdaindex715, std::array<u64,3>{v_c129, v_c135, 0}, [&](const std::array<u64,3>& m799) {
                  u64 v_c136 = m799[2];
                  slog::join_probe<3,2>(appindex716, std::array<u64,3>{v_c134, v_c136, 0}, [&](const std::array<u64,3>& m800) {
                    u64 v_c137 = m800[2];
                    if (!slog::exists_probe<3,1>(appindex717, std::array<u64,3>{v_c137, 0, 0})) return;
                    slog::join_probe<2,1>(refindex718, std::array<u64,2>{v_c130, 0}, [&](const std::array<u64,2>& m801) {
                      u64 v_c138 = m801[1];
                      slog::join_probe<3,2>(lambdaindex719, std::array<u64,3>{v_c130, v_c138, 0}, [&](const std::array<u64,3>& m802) {
                        u64 v_c139 = m802[2];
                        slog::join_probe<3,2>(appindex720, std::array<u64,3>{v_c134, v_c139, 0}, [&](const std::array<u64,3>& m803) {
                          u64 v_c140 = m803[2];
                          slog::join_probe<3,2>(lambdaindex721, std::array<u64,3>{v_c128, v_c140, 0}, [&](const std::array<u64,3>& m804) {
                            u64 v_c141 = m804[2];
                            slog::join_probe<3,2>(appindex722, std::array<u64,3>{v_c141, v_c137, 0}, [&](const std::array<u64,3>& m805) {
                              u64 v_c142 = m805[2];
                              slog::join_probe<3,2>(lambdaindex723, std::array<u64,3>{v_c126, v_c142, 0}, [&](const std::array<u64,3>& m806) {
                                u64 v_c143 = m806[2];
                                if (!slog::exists_probe<3,1>(appindex724, std::array<u64,3>{v_c143, 0, 0})) return;
                                slog::join_probe<3,1>(appindex725, std::array<u64,3>{v_c133, 0, 0}, [&](const std::array<u64,3>& m807) {
                                  u64 v_c144 = m807[1]; u64 v_c145 = m807[2];
                                  if (v_c133 != v_c144) return;
                                  slog::join_probe<3,2>(lambdaindex726, std::array<u64,3>{v_c127, v_c145, 0}, [&](const std::array<u64,3>& m808) {
                                    u64 v_c146 = m808[2];
                                    slog::join_probe<3,2>(appindex727, std::array<u64,3>{v_c143, v_c146, 0}, [&](const std::array<u64,3>& m809) {
                                      u64 v_c147 = m809[2];
                                      slog::join_probe<3,2>(lambdaindex728, std::array<u64,3>{v_c124, v_c147, 0}, [&](const std::array<u64,3>& m810) {
                                        u64 v_c148 = m810[2];
                                        ++_fires;
                                        slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c148, v_c132}, std::array<u16,3>{1, 2, 0});
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
      s->addTaskSeeded(phase_read, new ReadTask729(db,b));
  // (crule (pre (let __tconst8xRt151 const3a82152bd1402931076fe2d7) (let __tconst0zC2144 const4e3b5454cf93e32fad90650d) (let __tconst3Taj142 constdc1bb6655fb38bdb032e3754) (let __tconst8eg8132 const361d5df359e0d7681220d09d)) (scan app __t25NQ141 __t8dYW140 __t93Xi135) (body (join ref (0 1) 2 __t93Xi135 __tconst3Taj142) (exists lambda (1 2 0) 1 __tconst8eg8132) (exists ref (1 0) 1 __tconst0zC2144) (exists ref (1 0) 1 __tconst8xRt151) (exists lambda (1 2 0) 1 __tconst8xRt151) (join ref (1 0) 1 __tconst8eg8132 __t19JM131) (join lambda (1 2 0) 2 __tconst8eg8132 __t19JM131 __t4DXA133) (join ref (1 0) 1 __tconst0zC2144 __t7VSc137) (join app (0 1 2) 2 __t8dYW140 __t7VSc137 dup29id395) (eq __t7VSc137 dup29id395) (join ref (1 0) 1 __tconst8xRt151 __t1g2P147) (join app (1 2 0) 1 __t1g2P147 dup8FLm396 __t9UZN150) (eq __t1g2P147 dup8FLm396) (join lambda (1 2 0) 2 __tconst8xRt151 __t9UZN150 __t2nYy152)) (head (mkstruct lambda (1 2 0) __t2Ce3143 __tconst3Taj142 __t25NQ141)) mcfa-counting.slog:224 #f)
  class ReadTask823 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex811;  slog::Index** lambdaindex812;  slog::Index** refindex813;  slog::Index** refindex814;  slog::Index** lambdaindex815;  slog::Index** refindex816;  slog::Index** lambdaindex817;  slog::Index** refindex818;  slog::Index** appindex819;  slog::Index** refindex820;  slog::Index** appindex821;  slog::Index** lambdaindex822;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      outer_rel = db->getRelation("app");
      std::vector<u16> ord824({0, 1});
      slog::Relation* readrel825 = db->getRelation("ref");
      refindex811 = readrel825->getIndex(ord824, false);
      std::vector<u16> ord826({1, 2, 0});
      slog::Relation* readrel827 = db->getRelation("lambda");
      lambdaindex812 = readrel827->getIndex(ord826, false);
      std::vector<u16> ord828({1, 0});
      slog::Relation* readrel829 = db->getRelation("ref");
      refindex813 = readrel829->getIndex(ord828, false);
      std::vector<u16> ord830({1, 0});
      slog::Relation* readrel831 = db->getRelation("ref");
      refindex814 = readrel831->getIndex(ord830, false);
      std::vector<u16> ord832({1, 2, 0});
      slog::Relation* readrel833 = db->getRelation("lambda");
      lambdaindex815 = readrel833->getIndex(ord832, false);
      std::vector<u16> ord834({1, 0});
      slog::Relation* readrel835 = db->getRelation("ref");
      refindex816 = readrel835->getIndex(ord834, false);
      std::vector<u16> ord836({1, 2, 0});
      slog::Relation* readrel837 = db->getRelation("lambda");
      lambdaindex817 = readrel837->getIndex(ord836, false);
      std::vector<u16> ord838({1, 0});
      slog::Relation* readrel839 = db->getRelation("ref");
      refindex818 = readrel839->getIndex(ord838, false);
      std::vector<u16> ord840({0, 1, 2});
      slog::Relation* readrel841 = db->getRelation("app");
      appindex819 = readrel841->getIndex(ord840, false);
      std::vector<u16> ord842({1, 0});
      slog::Relation* readrel843 = db->getRelation("ref");
      refindex820 = readrel843->getIndex(ord842, false);
      std::vector<u16> ord844({1, 2, 0});
      slog::Relation* readrel845 = db->getRelation("app");
      appindex821 = readrel845->getIndex(ord844, false);
      std::vector<u16> ord846({1, 2, 0});
      slog::Relation* readrel847 = db->getRelation("lambda");
      lambdaindex822 = readrel847->getIndex(ord846, false);
  
    }
    ReadTask823(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c6 = v_const3a82152bd1402931076fe2d7;
      u64 v_c4 = v_const4e3b5454cf93e32fad90650d;
      u64 v_c5 = v_constdc1bb6655fb38bdb032e3754;
      u64 v_c7 = v_const361d5df359e0d7681220d09d;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c15 = _t[0];
        u64 v_c14 = _t[1];
        u64 v_c8 = _t[2];
        slog::join_probe<2,2>(refindex811, std::array<u64,2>{v_c8, v_c5}, [&](const std::array<u64,2>& m848) {
          if (!slog::exists_probe<3,1>(lambdaindex812, std::array<u64,3>{v_c7, 0, 0})) return;
          if (!slog::exists_probe<2,1>(refindex813, std::array<u64,2>{v_c4, 0})) return;
          if (!slog::exists_probe<2,1>(refindex814, std::array<u64,2>{v_c6, 0})) return;
          if (!slog::exists_probe<3,1>(lambdaindex815, std::array<u64,3>{v_c6, 0, 0})) return;
          slog::join_probe<2,1>(refindex816, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m849) {
            u64 v_c9 = m849[1];
            slog::join_probe<3,2>(lambdaindex817, std::array<u64,3>{v_c7, v_c9, 0}, [&](const std::array<u64,3>& m850) {
              u64 v_c10 = m850[2];
              slog::join_probe<2,1>(refindex818, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m851) {
                u64 v_c11 = m851[1];
                slog::join_probe<3,2>(appindex819, std::array<u64,3>{v_c14, v_c11, 0}, [&](const std::array<u64,3>& m852) {
                  u64 v_c149 = m852[2];
                  if (v_c11 != v_c149) return;
                  slog::join_probe<2,1>(refindex820, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m853) {
                    u64 v_c12 = m853[1];
                    slog::join_probe<3,1>(appindex821, std::array<u64,3>{v_c12, 0, 0}, [&](const std::array<u64,3>& m854) {
                      u64 v_c150 = m854[1]; u64 v_c18 = m854[2];
                      if (v_c12 != v_c150) return;
                      slog::join_probe<3,2>(lambdaindex822, std::array<u64,3>{v_c6, v_c18, 0}, [&](const std::array<u64,3>& m855) {
                        u64 v_c19 = m855[2];
                        ++_fires;
                        slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c5, v_c15}, std::array<u16,3>{1, 2, 0});
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
        ReadTask823* _cont = new ReadTask823(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask823(db,b), false);
  // (crule (pre) (scan eval __t8nKY157 ef c) (body (exists eval (2 0 1) 1 c) (exists eval_ans (0 1) 1 __t8nKY157) (join $sup27994x83x0x0x0 (1 3 0 2) 2 c ef __d0 ea) (join-old eval (1 2 0) 2 (1 2 0) ea c __t4j5Q160) (exists eval_ans (0 1) 1 __t4j5Q160) (join eval_ans (0 1) 1 __t8nKY157 __t3EGT159) (join eval_ans (0 1) 1 __t4j5Q160 va) (join-old clo (0 2 1) 1 (0 2 1) __t3EGT159 cb __t1L8v158) (join-old lambda (0 1 2) 1 (0 1 2) __t1L8v158 x eb)) (head (emit $sup27994x83x0x0x1 (1 4 0 2 3 5 6 7 8 9) __t8nKY157 cb __d0 __t4j5Q160 c ea eb ef va x)) mcfa-counting.slog:84 #f)
  class ReadTask868 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex856;  slog::Index** eval_ansindex857;  slog::Index** $sup27994x83x0x0x0index858;  slog::Index** evalindex859;  slog::Index** eval_ansindex860;  slog::Index** eval_ansindex861;  slog::Index** eval_ansindex862;  slog::Index** cloindex863;  slog::Index** lambdaindex864;  slog::Index** evaldelta865;  slog::Index** clodelta866;  slog::Index** lambdadelta867;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup27994x83x0x0x1");
      std::vector<u16> ord869({1, 4, 0, 2, 3, 5, 6, 7, 8, 9});
      slog::Relation* readrel870 = db->getRelation("$sup27994x83x0x0x1");
      head_index[0] = readrel870->getIndex(ord869, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord871({2, 0, 1});
      slog::Relation* readrel872 = db->getRelation("eval");
      evalindex856 = readrel872->getIndex(ord871, false);
      std::vector<u16> ord873({0, 1});
      slog::Relation* readrel874 = db->getRelation("eval_ans");
      eval_ansindex857 = readrel874->getIndex(ord873, false);
      std::vector<u16> ord875({1, 3, 0, 2});
      slog::Relation* readrel876 = db->getRelation("$sup27994x83x0x0x0");
      $sup27994x83x0x0x0index858 = readrel876->getIndex(ord875, false);
      std::vector<u16> ord877({1, 2, 0});
      slog::Relation* readrel878 = db->getRelation("eval");
      evalindex859 = readrel878->getIndex(ord877, false);
      std::vector<u16> ord879({1, 2, 0});
      slog::Relation* readrel880 = db->getRelation("eval");
      evaldelta865 = readrel880->getIndex(ord879, true);
      std::vector<u16> ord881({0, 1});
      slog::Relation* readrel882 = db->getRelation("eval_ans");
      eval_ansindex860 = readrel882->getIndex(ord881, false);
      std::vector<u16> ord883({0, 1});
      slog::Relation* readrel884 = db->getRelation("eval_ans");
      eval_ansindex861 = readrel884->getIndex(ord883, false);
      std::vector<u16> ord885({0, 1});
      slog::Relation* readrel886 = db->getRelation("eval_ans");
      eval_ansindex862 = readrel886->getIndex(ord885, false);
      std::vector<u16> ord887({0, 2, 1});
      slog::Relation* readrel888 = db->getRelation("clo");
      cloindex863 = readrel888->getIndex(ord887, false);
      std::vector<u16> ord889({0, 2, 1});
      slog::Relation* readrel890 = db->getRelation("clo");
      clodelta866 = readrel890->getIndex(ord889, true);
      std::vector<u16> ord891({0, 1, 2});
      slog::Relation* readrel892 = db->getRelation("lambda");
      lambdaindex864 = readrel892->getIndex(ord891, false);
      std::vector<u16> ord893({0, 1, 2});
      slog::Relation* readrel894 = db->getRelation("lambda");
      lambdadelta867 = readrel894->getIndex(ord893, true);
  
    }
    ReadTask868(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c3 = _t[1];
        u64 v_c21 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex856, std::array<u64,3>{v_c21, 0, 0})) return;
        if (!slog::exists_probe<2,1>(eval_ansindex857, std::array<u64,2>{v_c151, 0})) return;
        slog::join_probe<4,2>($sup27994x83x0x0x0index858, std::array<u64,4>{v_c21, v_c3, 0, 0}, [&](const std::array<u64,4>& m895) {
          u64 v_c152 = m895[2]; u64 v_c1 = m895[3];
          slog::join_probe_old<3,2>(evalindex859, evaldelta865, std::array<u64,3>{v_c1, v_c21, 0}, [&](const std::array<u64,3>& m896) {
            u64 v_c153 = m896[2];
            if (!slog::exists_probe<2,1>(eval_ansindex860, std::array<u64,2>{v_c153, 0})) return;
            slog::join_probe<2,1>(eval_ansindex861, std::array<u64,2>{v_c151, 0}, [&](const std::array<u64,2>& m897) {
              u64 v_c154 = m897[1];
              slog::join_probe<2,1>(eval_ansindex862, std::array<u64,2>{v_c153, 0}, [&](const std::array<u64,2>& m898) {
                u64 v_c26 = m898[1];
                slog::join_probe_old<3,1>(cloindex863, clodelta866, std::array<u64,3>{v_c154, 0, 0}, [&](const std::array<u64,3>& m899) {
                  u64 v_c27 = m899[1]; u64 v_c155 = m899[2];
                  slog::join_probe_old<3,1>(lambdaindex864, lambdadelta867, std::array<u64,3>{v_c155, 0, 0}, [&](const std::array<u64,3>& m900) {
                    u64 v_c0 = m900[1]; u64 v_c29 = m900[2];
                    ++_fires;
                    slog::emit<10>(head_rel[0], head_index[0], newbatch[0], std::array<u64,10>{v_c151, v_c27, v_c152, v_c153, v_c21, v_c1, v_c29, v_c3, v_c26, v_c0}, std::array<u16,10>{1, 4, 0, 2, 3, 5, 6, 7, 8, 9});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:84", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask868* _cont = new ReadTask868(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask868(db,b), false);
  // (crule (pre (let __tconst4Xaz41 const81cb39a72a584ab4f703b7f7) (let __tconst1aIN38 const4d5ce1398140fbe27561181f) (let __tconst1ha033 const969c6e56242ce8d0a4346602) (let __tconst37GM26 const85f09fa1913b9daf65957cf7) (let __tconst4xzG22 constdbf1bdba02122b2adce28528) (let __tconst1HMF17 constd7a1925d249b4768c8a9f2d8)) (seeded) (body (join ref (1 0) 1 __tconst1HMF17 __t7H1u16) (exists ref (1 0) 1 __tconst4xzG22) (exists ref (1 0) 1 __tconst37GM26) (exists lambda (1 2 0) 1 __tconst37GM26) (exists ref (1 0) 1 __tconst4Xaz41) (exists ref (1 0) 1 __tconst1ha033) (exists lambda (1 2 0) 1 __tconst1ha033) (join lambda (1 2 0) 2 __tconst1HMF17 __t7H1u16 __t2wNc18) (join ref (1 0) 1 __tconst4xzG22 __t2DOE20) (join ref (1 0) 1 __tconst37GM26 __t7U1m25) (join lambda (1 2 0) 2 __tconst37GM26 __t7U1m25 __t5myE27) (join ref (1 0) 1 __tconst4Xaz41 __t75SZ29) (join ref (1 0) 1 __tconst1ha033 __t7N9A32) (join lambda (1 2 0) 2 __tconst1ha033 __t7N9A32 __t065j34)) (head (mkstruct app (1 2 0) __t3pMW37 __t75SZ29 __t065j34) (mkstruct app (1 2 0) __t2Vg230 __t75SZ29 __t5myE27) (mkstruct app (1 2 0) __t3b2k21 __t2DOE20 __t2wNc18)) mcfa-counting.slog:260 #f)
  class ReadTask915 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
  
  
  
  
  
  
    slog::Index** refindex901;  slog::Index** refindex902;  slog::Index** refindex903;  slog::Index** lambdaindex904;  slog::Index** refindex905;  slog::Index** refindex906;  slog::Index** lambdaindex907;  slog::Index** lambdaindex908;  slog::Index** refindex909;  slog::Index** refindex910;  slog::Index** lambdaindex911;  slog::Index** refindex912;  slog::Index** refindex913;  slog::Index** lambdaindex914;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord916({1, 2, 0});
      slog::Relation* readrel917 = db->getRelation("app");
      head_index[0] = readrel917->getIndex(ord916, false);
      head_rel[1] = db->getRelation("app");
      std::vector<u16> ord918({1, 2, 0});
      slog::Relation* readrel919 = db->getRelation("app");
      head_index[1] = readrel919->getIndex(ord918, false);
      head_rel[2] = db->getRelation("app");
      std::vector<u16> ord920({1, 2, 0});
      slog::Relation* readrel921 = db->getRelation("app");
      head_index[2] = readrel921->getIndex(ord920, false);
      std::vector<u16> ord922({1, 0});
      slog::Relation* readrel923 = db->getRelation("ref");
      refindex901 = readrel923->getIndex(ord922, false);
      std::vector<u16> ord924({1, 0});
      slog::Relation* readrel925 = db->getRelation("ref");
      refindex902 = readrel925->getIndex(ord924, false);
      std::vector<u16> ord926({1, 0});
      slog::Relation* readrel927 = db->getRelation("ref");
      refindex903 = readrel927->getIndex(ord926, false);
      std::vector<u16> ord928({1, 2, 0});
      slog::Relation* readrel929 = db->getRelation("lambda");
      lambdaindex904 = readrel929->getIndex(ord928, false);
      std::vector<u16> ord930({1, 0});
      slog::Relation* readrel931 = db->getRelation("ref");
      refindex905 = readrel931->getIndex(ord930, false);
      std::vector<u16> ord932({1, 0});
      slog::Relation* readrel933 = db->getRelation("ref");
      refindex906 = readrel933->getIndex(ord932, false);
      std::vector<u16> ord934({1, 2, 0});
      slog::Relation* readrel935 = db->getRelation("lambda");
      lambdaindex907 = readrel935->getIndex(ord934, false);
      std::vector<u16> ord936({1, 2, 0});
      slog::Relation* readrel937 = db->getRelation("lambda");
      lambdaindex908 = readrel937->getIndex(ord936, false);
      std::vector<u16> ord938({1, 0});
      slog::Relation* readrel939 = db->getRelation("ref");
      refindex909 = readrel939->getIndex(ord938, false);
      std::vector<u16> ord940({1, 0});
      slog::Relation* readrel941 = db->getRelation("ref");
      refindex910 = readrel941->getIndex(ord940, false);
      std::vector<u16> ord942({1, 2, 0});
      slog::Relation* readrel943 = db->getRelation("lambda");
      lambdaindex911 = readrel943->getIndex(ord942, false);
      std::vector<u16> ord944({1, 0});
      slog::Relation* readrel945 = db->getRelation("ref");
      refindex912 = readrel945->getIndex(ord944, false);
      std::vector<u16> ord946({1, 0});
      slog::Relation* readrel947 = db->getRelation("ref");
      refindex913 = readrel947->getIndex(ord946, false);
      std::vector<u16> ord948({1, 2, 0});
      slog::Relation* readrel949 = db->getRelation("lambda");
      lambdaindex914 = readrel949->getIndex(ord948, false);
  
    }
    ReadTask915(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c156 = v_const81cb39a72a584ab4f703b7f7;
      u64 v_c157 = v_const4d5ce1398140fbe27561181f;
      u64 v_c158 = v_const969c6e56242ce8d0a4346602;
      u64 v_c159 = v_const85f09fa1913b9daf65957cf7;
      u64 v_c160 = v_constdbf1bdba02122b2adce28528;
      u64 v_c161 = v_constd7a1925d249b4768c8a9f2d8;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex901, std::array<u64,2>{v_c161, 0}, [&](const std::array<u64,2>& m950) {
        u64 v_c162 = m950[1];
        if (!slog::exists_probe<2,1>(refindex902, std::array<u64,2>{v_c160, 0})) return;
        if (!slog::exists_probe<2,1>(refindex903, std::array<u64,2>{v_c159, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex904, std::array<u64,3>{v_c159, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex905, std::array<u64,2>{v_c156, 0})) return;
        if (!slog::exists_probe<2,1>(refindex906, std::array<u64,2>{v_c158, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex907, std::array<u64,3>{v_c158, 0, 0})) return;
        slog::join_probe<3,2>(lambdaindex908, std::array<u64,3>{v_c161, v_c162, 0}, [&](const std::array<u64,3>& m951) {
          u64 v_c163 = m951[2];
          slog::join_probe<2,1>(refindex909, std::array<u64,2>{v_c160, 0}, [&](const std::array<u64,2>& m952) {
            u64 v_c164 = m952[1];
            slog::join_probe<2,1>(refindex910, std::array<u64,2>{v_c159, 0}, [&](const std::array<u64,2>& m953) {
              u64 v_c165 = m953[1];
              slog::join_probe<3,2>(lambdaindex911, std::array<u64,3>{v_c159, v_c165, 0}, [&](const std::array<u64,3>& m954) {
                u64 v_c166 = m954[2];
                slog::join_probe<2,1>(refindex912, std::array<u64,2>{v_c156, 0}, [&](const std::array<u64,2>& m955) {
                  u64 v_c167 = m955[1];
                  slog::join_probe<2,1>(refindex913, std::array<u64,2>{v_c158, 0}, [&](const std::array<u64,2>& m956) {
                    u64 v_c168 = m956[1];
                    slog::join_probe<3,2>(lambdaindex914, std::array<u64,3>{v_c158, v_c168, 0}, [&](const std::array<u64,3>& m957) {
                      u64 v_c169 = m957[2];
                      ++_fires;
                      slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c167, v_c169}, std::array<u16,3>{1, 2, 0});
                      slog::emit_struct_checked<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c167, v_c166}, std::array<u16,3>{1, 2, 0});
                      slog::emit_struct_checked<3>(head_rel[2], head_index[2], newbatch[2], std::array<u64,2>{v_c164, v_c163}, std::array<u16,3>{1, 2, 0});
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
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:260", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask915(db,b));
  // (crule (pre (let __tconst9zoW125 const7c7d2cfc66f4d976987d2d20) (let __tconst4V4L122 const6bc0ba365ada70df115e1785) (let __tconst82U8119 consta8180db1c2f300980314f910) (let __tconst3wDH116 constd5f017533ea574d5f9b3400c) (let __tconst3ktF111 const990b444cbd47632035b2fa1a) (let __tconst4BKz104 const0f8748be649f8ee4066bb1d7) (let __tconst5nWJ102 const4f84f41d89b6b717419b4eaa) (let __tconst4Zcr91 const9a67f28c6b77e842f439a84a) (let __tconst0vRf84 conste58dec6bca6f63ef79c3b755)) (seeded) (body (join ref (1 0) 1 __tconst0vRf84 __t2duR83) (exists ref (1 0) 1 __tconst4Zcr91) (exists ref (1 0) 1 __tconst9zoW125) (exists ref (1 0) 1 __tconst4BKz104) (exists lambda (1 2 0) 1 __tconst4BKz104) (exists ref (1 0) 1 __tconst4V4L122) (exists ref (1 0) 1 __tconst5nWJ102) (exists lambda (1 2 0) 1 __tconst5nWJ102) (exists ref (1 0) 1 __tconst3ktF111) (exists lambda (1 2 0) 1 __tconst3ktF111) (exists ref (1 0) 1 __tconst3wDH116) (join lambda (1 2 0) 2 __tconst0vRf84 __t2duR83 __t87vL85) (join ref (1 0) 1 __tconst4Zcr91 __t0C9F87) (exists app (2 0 1) 1 __t0C9F87) (join ref (1 0) 1 __tconst9zoW125 __t3Q2G89) (join app (1 2 0) 2 __t3Q2G89 __t0C9F87 __t2Eqd90) (join ref (1 0) 1 __tconst4BKz104 __t8C0a94) (join lambda (1 2 0) 2 __tconst4BKz104 __t8C0a94 __t4fDK96) (join ref (1 0) 1 __tconst4V4L122 __t7aew98) (join ref (1 0) 1 __tconst5nWJ102 __t5MaG101) (join lambda (1 2 0) 2 __tconst5nWJ102 __t5MaG101 __t35jA103) (join ref (1 0) 1 __tconst3ktF111 __t7ohz110) (join lambda (1 2 0) 2 __tconst3ktF111 __t7ohz110 __t8GWA112) (join ref (1 0) 1 __tconst3wDH116 __t3wir114)) (head (mkstruct app (1 2 0) __t44OM115 __t3wir114 __t8GWA112) (mkstruct lambda (1 2 0) __t6RuY105 __tconst4BKz104 __t35jA103) (mkstruct app (1 2 0) __t7TEO99 __t7aew98 __t4fDK96) (mkstruct lambda (1 2 0) __t3pgm92 __tconst4Zcr91 __t2Eqd90)) mcfa-counting.slog:241 #f)
  class ReadTask982 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[4];
    slog::Index** head_index[4];
  
  
  
  
  
  
    slog::Index** refindex958;  slog::Index** refindex959;  slog::Index** refindex960;  slog::Index** refindex961;  slog::Index** lambdaindex962;  slog::Index** refindex963;  slog::Index** refindex964;  slog::Index** lambdaindex965;  slog::Index** refindex966;  slog::Index** lambdaindex967;  slog::Index** refindex968;  slog::Index** lambdaindex969;  slog::Index** refindex970;  slog::Index** appindex971;  slog::Index** refindex972;  slog::Index** appindex973;  slog::Index** refindex974;  slog::Index** lambdaindex975;  slog::Index** refindex976;  slog::Index** refindex977;  slog::Index** lambdaindex978;  slog::Index** refindex979;  slog::Index** lambdaindex980;  slog::Index** refindex981;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord983({1, 2, 0});
      slog::Relation* readrel984 = db->getRelation("app");
      head_index[0] = readrel984->getIndex(ord983, false);
      head_rel[1] = db->getRelation("lambda");
      std::vector<u16> ord985({1, 2, 0});
      slog::Relation* readrel986 = db->getRelation("lambda");
      head_index[1] = readrel986->getIndex(ord985, false);
      head_rel[2] = db->getRelation("app");
      std::vector<u16> ord987({1, 2, 0});
      slog::Relation* readrel988 = db->getRelation("app");
      head_index[2] = readrel988->getIndex(ord987, false);
      head_rel[3] = db->getRelation("lambda");
      std::vector<u16> ord989({1, 2, 0});
      slog::Relation* readrel990 = db->getRelation("lambda");
      head_index[3] = readrel990->getIndex(ord989, false);
      std::vector<u16> ord991({1, 0});
      slog::Relation* readrel992 = db->getRelation("ref");
      refindex958 = readrel992->getIndex(ord991, false);
      std::vector<u16> ord993({1, 0});
      slog::Relation* readrel994 = db->getRelation("ref");
      refindex959 = readrel994->getIndex(ord993, false);
      std::vector<u16> ord995({1, 0});
      slog::Relation* readrel996 = db->getRelation("ref");
      refindex960 = readrel996->getIndex(ord995, false);
      std::vector<u16> ord997({1, 0});
      slog::Relation* readrel998 = db->getRelation("ref");
      refindex961 = readrel998->getIndex(ord997, false);
      std::vector<u16> ord999({1, 2, 0});
      slog::Relation* readrel1000 = db->getRelation("lambda");
      lambdaindex962 = readrel1000->getIndex(ord999, false);
      std::vector<u16> ord1001({1, 0});
      slog::Relation* readrel1002 = db->getRelation("ref");
      refindex963 = readrel1002->getIndex(ord1001, false);
      std::vector<u16> ord1003({1, 0});
      slog::Relation* readrel1004 = db->getRelation("ref");
      refindex964 = readrel1004->getIndex(ord1003, false);
      std::vector<u16> ord1005({1, 2, 0});
      slog::Relation* readrel1006 = db->getRelation("lambda");
      lambdaindex965 = readrel1006->getIndex(ord1005, false);
      std::vector<u16> ord1007({1, 0});
      slog::Relation* readrel1008 = db->getRelation("ref");
      refindex966 = readrel1008->getIndex(ord1007, false);
      std::vector<u16> ord1009({1, 2, 0});
      slog::Relation* readrel1010 = db->getRelation("lambda");
      lambdaindex967 = readrel1010->getIndex(ord1009, false);
      std::vector<u16> ord1011({1, 0});
      slog::Relation* readrel1012 = db->getRelation("ref");
      refindex968 = readrel1012->getIndex(ord1011, false);
      std::vector<u16> ord1013({1, 2, 0});
      slog::Relation* readrel1014 = db->getRelation("lambda");
      lambdaindex969 = readrel1014->getIndex(ord1013, false);
      std::vector<u16> ord1015({1, 0});
      slog::Relation* readrel1016 = db->getRelation("ref");
      refindex970 = readrel1016->getIndex(ord1015, false);
      std::vector<u16> ord1017({2, 0, 1});
      slog::Relation* readrel1018 = db->getRelation("app");
      appindex971 = readrel1018->getIndex(ord1017, false);
      std::vector<u16> ord1019({1, 0});
      slog::Relation* readrel1020 = db->getRelation("ref");
      refindex972 = readrel1020->getIndex(ord1019, false);
      std::vector<u16> ord1021({1, 2, 0});
      slog::Relation* readrel1022 = db->getRelation("app");
      appindex973 = readrel1022->getIndex(ord1021, false);
      std::vector<u16> ord1023({1, 0});
      slog::Relation* readrel1024 = db->getRelation("ref");
      refindex974 = readrel1024->getIndex(ord1023, false);
      std::vector<u16> ord1025({1, 2, 0});
      slog::Relation* readrel1026 = db->getRelation("lambda");
      lambdaindex975 = readrel1026->getIndex(ord1025, false);
      std::vector<u16> ord1027({1, 0});
      slog::Relation* readrel1028 = db->getRelation("ref");
      refindex976 = readrel1028->getIndex(ord1027, false);
      std::vector<u16> ord1029({1, 0});
      slog::Relation* readrel1030 = db->getRelation("ref");
      refindex977 = readrel1030->getIndex(ord1029, false);
      std::vector<u16> ord1031({1, 2, 0});
      slog::Relation* readrel1032 = db->getRelation("lambda");
      lambdaindex978 = readrel1032->getIndex(ord1031, false);
      std::vector<u16> ord1033({1, 0});
      slog::Relation* readrel1034 = db->getRelation("ref");
      refindex979 = readrel1034->getIndex(ord1033, false);
      std::vector<u16> ord1035({1, 2, 0});
      slog::Relation* readrel1036 = db->getRelation("lambda");
      lambdaindex980 = readrel1036->getIndex(ord1035, false);
      std::vector<u16> ord1037({1, 0});
      slog::Relation* readrel1038 = db->getRelation("ref");
      refindex981 = readrel1038->getIndex(ord1037, false);
  
    }
    ReadTask982(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c93 = v_const7c7d2cfc66f4d976987d2d20;
      u64 v_c94 = v_const6bc0ba365ada70df115e1785;
      u64 v_c95 = v_consta8180db1c2f300980314f910;
      u64 v_c99 = v_constd5f017533ea574d5f9b3400c;
      u64 v_c100 = v_const990b444cbd47632035b2fa1a;
      u64 v_c98 = v_const0f8748be649f8ee4066bb1d7;
      u64 v_c101 = v_const4f84f41d89b6b717419b4eaa;
      u64 v_c96 = v_const9a67f28c6b77e842f439a84a;
      u64 v_c97 = v_conste58dec6bca6f63ef79c3b755;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[4];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex958, std::array<u64,2>{v_c97, 0}, [&](const std::array<u64,2>& m1039) {
        u64 v_c109 = m1039[1];
        if (!slog::exists_probe<2,1>(refindex959, std::array<u64,2>{v_c96, 0})) return;
        if (!slog::exists_probe<2,1>(refindex960, std::array<u64,2>{v_c93, 0})) return;
        if (!slog::exists_probe<2,1>(refindex961, std::array<u64,2>{v_c98, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex962, std::array<u64,3>{v_c98, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex963, std::array<u64,2>{v_c94, 0})) return;
        if (!slog::exists_probe<2,1>(refindex964, std::array<u64,2>{v_c101, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex965, std::array<u64,3>{v_c101, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex966, std::array<u64,2>{v_c100, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex967, std::array<u64,3>{v_c100, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex968, std::array<u64,2>{v_c99, 0})) return;
        slog::join_probe<3,2>(lambdaindex969, std::array<u64,3>{v_c97, v_c109, 0}, [&](const std::array<u64,3>& m1040) {
          u64 v_c110 = m1040[2];
          slog::join_probe<2,1>(refindex970, std::array<u64,2>{v_c96, 0}, [&](const std::array<u64,2>& m1041) {
            u64 v_c111 = m1041[1];
            if (!slog::exists_probe<3,1>(appindex971, std::array<u64,3>{v_c111, 0, 0})) return;
            slog::join_probe<2,1>(refindex972, std::array<u64,2>{v_c93, 0}, [&](const std::array<u64,2>& m1042) {
              u64 v_c112 = m1042[1];
              slog::join_probe<3,2>(appindex973, std::array<u64,3>{v_c112, v_c111, 0}, [&](const std::array<u64,3>& m1043) {
                u64 v_c113 = m1043[2];
                slog::join_probe<2,1>(refindex974, std::array<u64,2>{v_c98, 0}, [&](const std::array<u64,2>& m1044) {
                  u64 v_c108 = m1044[1];
                  slog::join_probe<3,2>(lambdaindex975, std::array<u64,3>{v_c98, v_c108, 0}, [&](const std::array<u64,3>& m1045) {
                    u64 v_c107 = m1045[2];
                    slog::join_probe<2,1>(refindex976, std::array<u64,2>{v_c94, 0}, [&](const std::array<u64,2>& m1046) {
                      u64 v_c106 = m1046[1];
                      slog::join_probe<2,1>(refindex977, std::array<u64,2>{v_c101, 0}, [&](const std::array<u64,2>& m1047) {
                        u64 v_c116 = m1047[1];
                        slog::join_probe<3,2>(lambdaindex978, std::array<u64,3>{v_c101, v_c116, 0}, [&](const std::array<u64,3>& m1048) {
                          u64 v_c117 = m1048[2];
                          slog::join_probe<2,1>(refindex979, std::array<u64,2>{v_c100, 0}, [&](const std::array<u64,2>& m1049) {
                            u64 v_c123 = m1049[1];
                            slog::join_probe<3,2>(lambdaindex980, std::array<u64,3>{v_c100, v_c123, 0}, [&](const std::array<u64,3>& m1050) {
                              u64 v_c122 = m1050[2];
                              slog::join_probe<2,1>(refindex981, std::array<u64,2>{v_c99, 0}, [&](const std::array<u64,2>& m1051) {
                                u64 v_c115 = m1051[1];
                                ++_fires;
                                slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c115, v_c122}, std::array<u16,3>{1, 2, 0});
                                slog::emit_struct_checked<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c98, v_c117}, std::array<u16,3>{1, 2, 0});
                                slog::emit_struct_checked<3>(head_rel[2], head_index[2], newbatch[2], std::array<u64,2>{v_c106, v_c107}, std::array<u16,3>{1, 2, 0});
                                slog::emit_struct_checked<3>(head_rel[3], head_index[3], newbatch[3], std::array<u64,2>{v_c96, v_c113}, std::array<u16,3>{1, 2, 0});
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
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:241", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask982(db,b));
  // (crule (pre (let __tconst8xRt151 const3a82152bd1402931076fe2d7) (let __tconst0zC2144 const4e3b5454cf93e32fad90650d) (let __tconst3Taj142 constdc1bb6655fb38bdb032e3754) (let __tconst8eg8132 const361d5df359e0d7681220d09d)) (seeded) (body (join ref (1 0) 1 __tconst3Taj142 __t93Xi135) (exists lambda (1 2 0) 1 __tconst8eg8132) (exists ref (1 0) 1 __tconst0zC2144) (exists ref (1 0) 1 __tconst8xRt151) (exists app (2 0 1) 1 __t93Xi135) (exists lambda (1 2 0) 1 __tconst8xRt151) (join ref (1 0) 1 __tconst8eg8132 __t19JM131) (join lambda (1 2 0) 2 __tconst8eg8132 __t19JM131 __t4DXA133) (join ref (1 0) 1 __tconst0zC2144 __t7VSc137) (exists app (1 2 0) 1 __t7VSc137) (join ref (1 0) 1 __tconst8xRt151 __t1g2P147) (exists app (1 2 0) 1 __t1g2P147) (join app (1 2 0) 1 __t7VSc137 dup7OVy397 __t8dYW140) (eq __t7VSc137 dup7OVy397) (join app (1 2 0) 2 __t8dYW140 __t93Xi135 __t25NQ141) (join app (1 2 0) 1 __t1g2P147 dup6dB4398 __t9UZN150) (eq __t1g2P147 dup6dB4398) (join lambda (1 2 0) 2 __tconst8xRt151 __t9UZN150 __t2nYy152)) (head (mkstruct lambda (1 2 0) __t2Ce3143 __tconst3Taj142 __t25NQ141)) mcfa-counting.slog:224 #f)
  class ReadTask1068 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex1052;  slog::Index** lambdaindex1053;  slog::Index** refindex1054;  slog::Index** refindex1055;  slog::Index** appindex1056;  slog::Index** lambdaindex1057;  slog::Index** refindex1058;  slog::Index** lambdaindex1059;  slog::Index** refindex1060;  slog::Index** appindex1061;  slog::Index** refindex1062;  slog::Index** appindex1063;  slog::Index** appindex1064;  slog::Index** appindex1065;  slog::Index** appindex1066;  slog::Index** lambdaindex1067;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      std::vector<u16> ord1069({1, 2, 0});
      slog::Relation* readrel1070 = db->getRelation("lambda");
      head_index[0] = readrel1070->getIndex(ord1069, false);
      std::vector<u16> ord1071({1, 0});
      slog::Relation* readrel1072 = db->getRelation("ref");
      refindex1052 = readrel1072->getIndex(ord1071, false);
      std::vector<u16> ord1073({1, 2, 0});
      slog::Relation* readrel1074 = db->getRelation("lambda");
      lambdaindex1053 = readrel1074->getIndex(ord1073, false);
      std::vector<u16> ord1075({1, 0});
      slog::Relation* readrel1076 = db->getRelation("ref");
      refindex1054 = readrel1076->getIndex(ord1075, false);
      std::vector<u16> ord1077({1, 0});
      slog::Relation* readrel1078 = db->getRelation("ref");
      refindex1055 = readrel1078->getIndex(ord1077, false);
      std::vector<u16> ord1079({2, 0, 1});
      slog::Relation* readrel1080 = db->getRelation("app");
      appindex1056 = readrel1080->getIndex(ord1079, false);
      std::vector<u16> ord1081({1, 2, 0});
      slog::Relation* readrel1082 = db->getRelation("lambda");
      lambdaindex1057 = readrel1082->getIndex(ord1081, false);
      std::vector<u16> ord1083({1, 0});
      slog::Relation* readrel1084 = db->getRelation("ref");
      refindex1058 = readrel1084->getIndex(ord1083, false);
      std::vector<u16> ord1085({1, 2, 0});
      slog::Relation* readrel1086 = db->getRelation("lambda");
      lambdaindex1059 = readrel1086->getIndex(ord1085, false);
      std::vector<u16> ord1087({1, 0});
      slog::Relation* readrel1088 = db->getRelation("ref");
      refindex1060 = readrel1088->getIndex(ord1087, false);
      std::vector<u16> ord1089({1, 2, 0});
      slog::Relation* readrel1090 = db->getRelation("app");
      appindex1061 = readrel1090->getIndex(ord1089, false);
      std::vector<u16> ord1091({1, 0});
      slog::Relation* readrel1092 = db->getRelation("ref");
      refindex1062 = readrel1092->getIndex(ord1091, false);
      std::vector<u16> ord1093({1, 2, 0});
      slog::Relation* readrel1094 = db->getRelation("app");
      appindex1063 = readrel1094->getIndex(ord1093, false);
      std::vector<u16> ord1095({1, 2, 0});
      slog::Relation* readrel1096 = db->getRelation("app");
      appindex1064 = readrel1096->getIndex(ord1095, false);
      std::vector<u16> ord1097({1, 2, 0});
      slog::Relation* readrel1098 = db->getRelation("app");
      appindex1065 = readrel1098->getIndex(ord1097, false);
      std::vector<u16> ord1099({1, 2, 0});
      slog::Relation* readrel1100 = db->getRelation("app");
      appindex1066 = readrel1100->getIndex(ord1099, false);
      std::vector<u16> ord1101({1, 2, 0});
      slog::Relation* readrel1102 = db->getRelation("lambda");
      lambdaindex1067 = readrel1102->getIndex(ord1101, false);
  
    }
    ReadTask1068(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c6 = v_const3a82152bd1402931076fe2d7;
      u64 v_c4 = v_const4e3b5454cf93e32fad90650d;
      u64 v_c5 = v_constdc1bb6655fb38bdb032e3754;
      u64 v_c7 = v_const361d5df359e0d7681220d09d;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex1052, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m1103) {
        u64 v_c8 = m1103[1];
        if (!slog::exists_probe<3,1>(lambdaindex1053, std::array<u64,3>{v_c7, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1054, std::array<u64,2>{v_c4, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1055, std::array<u64,2>{v_c6, 0})) return;
        if (!slog::exists_probe<3,1>(appindex1056, std::array<u64,3>{v_c8, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1057, std::array<u64,3>{v_c6, 0, 0})) return;
        slog::join_probe<2,1>(refindex1058, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m1104) {
          u64 v_c9 = m1104[1];
          slog::join_probe<3,2>(lambdaindex1059, std::array<u64,3>{v_c7, v_c9, 0}, [&](const std::array<u64,3>& m1105) {
            u64 v_c10 = m1105[2];
            slog::join_probe<2,1>(refindex1060, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m1106) {
              u64 v_c11 = m1106[1];
              if (!slog::exists_probe<3,1>(appindex1061, std::array<u64,3>{v_c11, 0, 0})) return;
              slog::join_probe<2,1>(refindex1062, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m1107) {
                u64 v_c12 = m1107[1];
                if (!slog::exists_probe<3,1>(appindex1063, std::array<u64,3>{v_c12, 0, 0})) return;
                slog::join_probe<3,1>(appindex1064, std::array<u64,3>{v_c11, 0, 0}, [&](const std::array<u64,3>& m1108) {
                  u64 v_c170 = m1108[1]; u64 v_c14 = m1108[2];
                  if (v_c11 != v_c170) return;
                  slog::join_probe<3,2>(appindex1065, std::array<u64,3>{v_c14, v_c8, 0}, [&](const std::array<u64,3>& m1109) {
                    u64 v_c15 = m1109[2];
                    slog::join_probe<3,1>(appindex1066, std::array<u64,3>{v_c12, 0, 0}, [&](const std::array<u64,3>& m1110) {
                      u64 v_c171 = m1110[1]; u64 v_c18 = m1110[2];
                      if (v_c12 != v_c171) return;
                      slog::join_probe<3,2>(lambdaindex1067, std::array<u64,3>{v_c6, v_c18, 0}, [&](const std::array<u64,3>& m1111) {
                        u64 v_c19 = m1111[2];
                        ++_fires;
                        slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c5, v_c15}, std::array<u16,3>{1, 2, 0});
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
  
      if (_fires) db->bumpFires("mcfa-counting.slog:224", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask1068(db,b));
  // (crule (pre) (scan clo __t2Hqj172 __t0RD6171 cb) (body (join eval_ans (1 0) 1 __t2Hqj172 __t6CRg170) (join eval (0 2 1) 1 __t6CRg170 c ef) (exists app (1 2 0) 1 ef) (exists eval (2 0 1) 1 c) (join eval (2 0 1) 1 c __6tlE337 __t5SBy169) (join app (0 1 2) 2 __t5SBy169 ef ea) (join-old eval (1 2 0) 2 (1 2 0) ea c __t1JPZ173) (join eval_ans (0 1) 1 __t1JPZ173 va) (join lambda (0 1 2) 1 __t0RD6171 x eb)) (head (emit store (0 1 2) x __t5SBy169 va) (emit callev (0 1) __t5SBy169 c) (emit bindev (0 1 2) x __t5SBy169 c)) mcfa-counting.slog:92 #f)
  class ReadTask1122 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eval_ansindex1112;  slog::Index** evalindex1113;  slog::Index** appindex1114;  slog::Index** evalindex1115;  slog::Index** evalindex1116;  slog::Index** appindex1117;  slog::Index** evalindex1118;  slog::Index** eval_ansindex1119;  slog::Index** lambdaindex1120;  slog::Index** evaldelta1121;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("store");
      std::vector<u16> ord1123({0, 1, 2});
      slog::Relation* readrel1124 = db->getRelation("store");
      head_index[0] = readrel1124->getIndex(ord1123, false);
      head_rel[1] = db->getRelation("callev");
      std::vector<u16> ord1125({0, 1});
      slog::Relation* readrel1126 = db->getRelation("callev");
      head_index[1] = readrel1126->getIndex(ord1125, false);
      head_rel[2] = db->getRelation("bindev");
      std::vector<u16> ord1127({0, 1, 2});
      slog::Relation* readrel1128 = db->getRelation("bindev");
      head_index[2] = readrel1128->getIndex(ord1127, false);
      outer_rel = db->getRelation("clo");
      std::vector<u16> ord1129({1, 0});
      slog::Relation* readrel1130 = db->getRelation("eval_ans");
      eval_ansindex1112 = readrel1130->getIndex(ord1129, false);
      std::vector<u16> ord1131({0, 2, 1});
      slog::Relation* readrel1132 = db->getRelation("eval");
      evalindex1113 = readrel1132->getIndex(ord1131, false);
      std::vector<u16> ord1133({1, 2, 0});
      slog::Relation* readrel1134 = db->getRelation("app");
      appindex1114 = readrel1134->getIndex(ord1133, false);
      std::vector<u16> ord1135({2, 0, 1});
      slog::Relation* readrel1136 = db->getRelation("eval");
      evalindex1115 = readrel1136->getIndex(ord1135, false);
      std::vector<u16> ord1137({2, 0, 1});
      slog::Relation* readrel1138 = db->getRelation("eval");
      evalindex1116 = readrel1138->getIndex(ord1137, false);
      std::vector<u16> ord1139({0, 1, 2});
      slog::Relation* readrel1140 = db->getRelation("app");
      appindex1117 = readrel1140->getIndex(ord1139, false);
      std::vector<u16> ord1141({1, 2, 0});
      slog::Relation* readrel1142 = db->getRelation("eval");
      evalindex1118 = readrel1142->getIndex(ord1141, false);
      std::vector<u16> ord1143({1, 2, 0});
      slog::Relation* readrel1144 = db->getRelation("eval");
      evaldelta1121 = readrel1144->getIndex(ord1143, true);
      std::vector<u16> ord1145({0, 1});
      slog::Relation* readrel1146 = db->getRelation("eval_ans");
      eval_ansindex1119 = readrel1146->getIndex(ord1145, false);
      std::vector<u16> ord1147({0, 1, 2});
      slog::Relation* readrel1148 = db->getRelation("lambda");
      lambdaindex1120 = readrel1148->getIndex(ord1147, false);
  
    }
    ReadTask1122(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
  
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
        u64 v_c22 = _t[0];
        u64 v_c28 = _t[1];
        u64 v_c27 = _t[2];
        slog::join_probe<2,1>(eval_ansindex1112, std::array<u64,2>{v_c22, 0}, [&](const std::array<u64,2>& m1149) {
          u64 v_c20 = m1149[1];
          slog::join_probe<3,1>(evalindex1113, std::array<u64,3>{v_c20, 0, 0}, [&](const std::array<u64,3>& m1150) {
            u64 v_c21 = m1150[1]; u64 v_c3 = m1150[2];
            if (!slog::exists_probe<3,1>(appindex1114, std::array<u64,3>{v_c3, 0, 0})) return;
            if (!slog::exists_probe<3,1>(evalindex1115, std::array<u64,3>{v_c21, 0, 0})) return;
            slog::join_probe<3,1>(evalindex1116, std::array<u64,3>{v_c21, 0, 0}, [&](const std::array<u64,3>& m1151) {
              u64 v_c23 = m1151[1]; u64 v_c24 = m1151[2];
              slog::join_probe<3,2>(appindex1117, std::array<u64,3>{v_c24, v_c3, 0}, [&](const std::array<u64,3>& m1152) {
                u64 v_c1 = m1152[2];
                slog::join_probe_old<3,2>(evalindex1118, evaldelta1121, std::array<u64,3>{v_c1, v_c21, 0}, [&](const std::array<u64,3>& m1153) {
                  u64 v_c25 = m1153[2];
                  slog::join_probe<2,1>(eval_ansindex1119, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m1154) {
                    u64 v_c26 = m1154[1];
                    slog::join_probe<3,1>(lambdaindex1120, std::array<u64,3>{v_c28, 0, 0}, [&](const std::array<u64,3>& m1155) {
                      u64 v_c0 = m1155[1]; u64 v_c29 = m1155[2];
                      ++_fires;
                      slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c0, v_c24, v_c26}, std::array<u16,3>{0, 1, 2});
                      slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c24, v_c21}, std::array<u16,2>{0, 1});
                      slog::emit<3>(head_rel[2], head_index[2], newbatch[2], std::array<u64,3>{v_c0, v_c24, v_c21}, std::array<u16,3>{0, 1, 2});
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
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:92", "delta:clo", _fires);
  
      if (!_done)
      {
        ReadTask1122* _cont = new ReadTask1122(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1122(db,b), false);
  // (crule (pre (let __tconst1pJW313 constb49bea2fcccd8f4301a347ed) (let __tconst7LWP310 const66518c0c1b3a5a0b09ae2ef1) (let __tconst0sqO307 const4a8acfc71441e0695ffcf5b3) (let __tconst2CSv302 const229c0b7aa8a7eb4055f5a3d0) (let __tconst9rZO295 const576506f61f53440f1edd95d2) (let __tconst5PoN291 constc85eae03730a4f4cf1d66a0c) (let __tconst2Yzp284 const8ca682693a0738a0641c6956)) (seeded) (body (join ref (1 0) 1 __tconst2Yzp284 __t248W283) (exists ref (1 0) 1 __tconst1pJW313) (exists ref (1 0) 1 __tconst9rZO295) (exists lambda (1 2 0) 1 __tconst9rZO295) (exists ref (1 0) 1 __tconst7LWP310) (exists ref (1 0) 1 __tconst2CSv302) (exists lambda (1 2 0) 1 __tconst2CSv302) (join lambda (1 2 0) 2 __tconst2Yzp284 __t248W283 __t0oFu285) (join ref (1 0) 1 __tconst1pJW313 __t165O287) (exists app (1 2 0) 1 __t165O287) (join ref (1 0) 1 __tconst9rZO295 __t71w7294) (join lambda (1 2 0) 2 __tconst9rZO295 __t71w7294 __t3dkk296) (join ref (1 0) 1 __tconst7LWP310 __t91H2298) (join ref (1 0) 1 __tconst2CSv302 __t6lXa301) (join lambda (1 2 0) 2 __tconst2CSv302 __t6lXa301 __t7EW2303) (join app (1 2 0) 1 __t165O287 dup6Pm0376 __t30Ec290) (eq __t165O287 dup6Pm0376)) (head (mkstruct app (1 2 0) __t4HUX306 __t91H2298 __t7EW2303) (mkstruct app (1 2 0) __t4LtH299 __t91H2298 __t3dkk296) (mkstruct lambda (1 2 0) __t7aCZ292 __tconst5PoN291 __t30Ec290)) mcfa-counting.slog:194 #f)
  class ReadTask1172 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
  
  
  
  
  
  
    slog::Index** refindex1156;  slog::Index** refindex1157;  slog::Index** refindex1158;  slog::Index** lambdaindex1159;  slog::Index** refindex1160;  slog::Index** refindex1161;  slog::Index** lambdaindex1162;  slog::Index** lambdaindex1163;  slog::Index** refindex1164;  slog::Index** appindex1165;  slog::Index** refindex1166;  slog::Index** lambdaindex1167;  slog::Index** refindex1168;  slog::Index** refindex1169;  slog::Index** lambdaindex1170;  slog::Index** appindex1171;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord1173({1, 2, 0});
      slog::Relation* readrel1174 = db->getRelation("app");
      head_index[0] = readrel1174->getIndex(ord1173, false);
      head_rel[1] = db->getRelation("app");
      std::vector<u16> ord1175({1, 2, 0});
      slog::Relation* readrel1176 = db->getRelation("app");
      head_index[1] = readrel1176->getIndex(ord1175, false);
      head_rel[2] = db->getRelation("lambda");
      std::vector<u16> ord1177({1, 2, 0});
      slog::Relation* readrel1178 = db->getRelation("lambda");
      head_index[2] = readrel1178->getIndex(ord1177, false);
      std::vector<u16> ord1179({1, 0});
      slog::Relation* readrel1180 = db->getRelation("ref");
      refindex1156 = readrel1180->getIndex(ord1179, false);
      std::vector<u16> ord1181({1, 0});
      slog::Relation* readrel1182 = db->getRelation("ref");
      refindex1157 = readrel1182->getIndex(ord1181, false);
      std::vector<u16> ord1183({1, 0});
      slog::Relation* readrel1184 = db->getRelation("ref");
      refindex1158 = readrel1184->getIndex(ord1183, false);
      std::vector<u16> ord1185({1, 2, 0});
      slog::Relation* readrel1186 = db->getRelation("lambda");
      lambdaindex1159 = readrel1186->getIndex(ord1185, false);
      std::vector<u16> ord1187({1, 0});
      slog::Relation* readrel1188 = db->getRelation("ref");
      refindex1160 = readrel1188->getIndex(ord1187, false);
      std::vector<u16> ord1189({1, 0});
      slog::Relation* readrel1190 = db->getRelation("ref");
      refindex1161 = readrel1190->getIndex(ord1189, false);
      std::vector<u16> ord1191({1, 2, 0});
      slog::Relation* readrel1192 = db->getRelation("lambda");
      lambdaindex1162 = readrel1192->getIndex(ord1191, false);
      std::vector<u16> ord1193({1, 2, 0});
      slog::Relation* readrel1194 = db->getRelation("lambda");
      lambdaindex1163 = readrel1194->getIndex(ord1193, false);
      std::vector<u16> ord1195({1, 0});
      slog::Relation* readrel1196 = db->getRelation("ref");
      refindex1164 = readrel1196->getIndex(ord1195, false);
      std::vector<u16> ord1197({1, 2, 0});
      slog::Relation* readrel1198 = db->getRelation("app");
      appindex1165 = readrel1198->getIndex(ord1197, false);
      std::vector<u16> ord1199({1, 0});
      slog::Relation* readrel1200 = db->getRelation("ref");
      refindex1166 = readrel1200->getIndex(ord1199, false);
      std::vector<u16> ord1201({1, 2, 0});
      slog::Relation* readrel1202 = db->getRelation("lambda");
      lambdaindex1167 = readrel1202->getIndex(ord1201, false);
      std::vector<u16> ord1203({1, 0});
      slog::Relation* readrel1204 = db->getRelation("ref");
      refindex1168 = readrel1204->getIndex(ord1203, false);
      std::vector<u16> ord1205({1, 0});
      slog::Relation* readrel1206 = db->getRelation("ref");
      refindex1169 = readrel1206->getIndex(ord1205, false);
      std::vector<u16> ord1207({1, 2, 0});
      slog::Relation* readrel1208 = db->getRelation("lambda");
      lambdaindex1170 = readrel1208->getIndex(ord1207, false);
      std::vector<u16> ord1209({1, 2, 0});
      slog::Relation* readrel1210 = db->getRelation("app");
      appindex1171 = readrel1210->getIndex(ord1209, false);
  
    }
    ReadTask1172(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c124 = v_constb49bea2fcccd8f4301a347ed;
      u64 v_c126 = v_const66518c0c1b3a5a0b09ae2ef1;
      u64 v_c128 = v_const4a8acfc71441e0695ffcf5b3;
      u64 v_c130 = v_const229c0b7aa8a7eb4055f5a3d0;
      u64 v_c129 = v_const576506f61f53440f1edd95d2;
      u64 v_c127 = v_constc85eae03730a4f4cf1d66a0c;
      u64 v_c125 = v_const8ca682693a0738a0641c6956;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex1156, std::array<u64,2>{v_c125, 0}, [&](const std::array<u64,2>& m1211) {
        u64 v_c131 = m1211[1];
        if (!slog::exists_probe<2,1>(refindex1157, std::array<u64,2>{v_c124, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1158, std::array<u64,2>{v_c129, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1159, std::array<u64,3>{v_c129, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1160, std::array<u64,2>{v_c126, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1161, std::array<u64,2>{v_c130, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1162, std::array<u64,3>{v_c130, 0, 0})) return;
        slog::join_probe<3,2>(lambdaindex1163, std::array<u64,3>{v_c125, v_c131, 0}, [&](const std::array<u64,3>& m1212) {
          u64 v_c132 = m1212[2];
          slog::join_probe<2,1>(refindex1164, std::array<u64,2>{v_c124, 0}, [&](const std::array<u64,2>& m1213) {
            u64 v_c133 = m1213[1];
            if (!slog::exists_probe<3,1>(appindex1165, std::array<u64,3>{v_c133, 0, 0})) return;
            slog::join_probe<2,1>(refindex1166, std::array<u64,2>{v_c129, 0}, [&](const std::array<u64,2>& m1214) {
              u64 v_c135 = m1214[1];
              slog::join_probe<3,2>(lambdaindex1167, std::array<u64,3>{v_c129, v_c135, 0}, [&](const std::array<u64,3>& m1215) {
                u64 v_c136 = m1215[2];
                slog::join_probe<2,1>(refindex1168, std::array<u64,2>{v_c126, 0}, [&](const std::array<u64,2>& m1216) {
                  u64 v_c134 = m1216[1];
                  slog::join_probe<2,1>(refindex1169, std::array<u64,2>{v_c130, 0}, [&](const std::array<u64,2>& m1217) {
                    u64 v_c138 = m1217[1];
                    slog::join_probe<3,2>(lambdaindex1170, std::array<u64,3>{v_c130, v_c138, 0}, [&](const std::array<u64,3>& m1218) {
                      u64 v_c139 = m1218[2];
                      slog::join_probe<3,1>(appindex1171, std::array<u64,3>{v_c133, 0, 0}, [&](const std::array<u64,3>& m1219) {
                        u64 v_c172 = m1219[1]; u64 v_c145 = m1219[2];
                        if (v_c133 != v_c172) return;
                        ++_fires;
                        slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c134, v_c139}, std::array<u16,3>{1, 2, 0});
                        slog::emit_struct_checked<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c134, v_c136}, std::array<u16,3>{1, 2, 0});
                        slog::emit_struct_checked<3>(head_rel[2], head_index[2], newbatch[2], std::array<u64,2>{v_c127, v_c145}, std::array<u16,3>{1, 2, 0});
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
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:194", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask1172(db,b));
  // (crule (pre (let __tconst7JVW192 const6cf13cc59dcbe759113f68a4) (let __tconst7B9N190 constcaa3ee5a2828a31924f6b39d) (let __tconst5wC2180 const970c20ea81b833e5b5a7accf) (let __tconst2ady176 constc40f204dda7ba4054abb9e74)) (scan app __t9pbS189 __t6fOY185 __t2CTd186) (body (join ref (0 1) 2 __t6fOY185 __tconst7JVW192) (exists ref (1 0) 1 __tconst7B9N190) (exists ref (1 0) 1 __tconst2ady176) (exists lambda (1 2 0) 1 __tconst2ady176) (exists ref (1 0) 1 __tconst5wC2180) (exists lambda (1 2 0) 1 __tconst5wC2180) (join app (0 1 2) 2 __t2CTd186 __t6fOY185 __t8oRJ183) (join ref (0 1) 2 __t8oRJ183 __tconst7B9N190) (join ref (1 0) 1 __tconst2ady176 __t3ZY4175) (join lambda (1 2 0) 2 __tconst2ady176 __t3ZY4175 __t1Ls4177) (join ref (1 0) 1 __tconst5wC2180 __t52sB179) (join lambda (1 2 0) 2 __tconst5wC2180 __t52sB179 __t6CST181)) (head (mkstruct lambda (1 2 0) __t6W4v191 __tconst7B9N190 __t9pbS189)) mcfa-counting.slog:301 #f)
  class ReadTask1232 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex1220;  slog::Index** refindex1221;  slog::Index** refindex1222;  slog::Index** lambdaindex1223;  slog::Index** refindex1224;  slog::Index** lambdaindex1225;  slog::Index** appindex1226;  slog::Index** refindex1227;  slog::Index** refindex1228;  slog::Index** lambdaindex1229;  slog::Index** refindex1230;  slog::Index** lambdaindex1231;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      outer_rel = db->getRelation("app");
      std::vector<u16> ord1233({0, 1});
      slog::Relation* readrel1234 = db->getRelation("ref");
      refindex1220 = readrel1234->getIndex(ord1233, false);
      std::vector<u16> ord1235({1, 0});
      slog::Relation* readrel1236 = db->getRelation("ref");
      refindex1221 = readrel1236->getIndex(ord1235, false);
      std::vector<u16> ord1237({1, 0});
      slog::Relation* readrel1238 = db->getRelation("ref");
      refindex1222 = readrel1238->getIndex(ord1237, false);
      std::vector<u16> ord1239({1, 2, 0});
      slog::Relation* readrel1240 = db->getRelation("lambda");
      lambdaindex1223 = readrel1240->getIndex(ord1239, false);
      std::vector<u16> ord1241({1, 0});
      slog::Relation* readrel1242 = db->getRelation("ref");
      refindex1224 = readrel1242->getIndex(ord1241, false);
      std::vector<u16> ord1243({1, 2, 0});
      slog::Relation* readrel1244 = db->getRelation("lambda");
      lambdaindex1225 = readrel1244->getIndex(ord1243, false);
      std::vector<u16> ord1245({0, 1, 2});
      slog::Relation* readrel1246 = db->getRelation("app");
      appindex1226 = readrel1246->getIndex(ord1245, false);
      std::vector<u16> ord1247({0, 1});
      slog::Relation* readrel1248 = db->getRelation("ref");
      refindex1227 = readrel1248->getIndex(ord1247, false);
      std::vector<u16> ord1249({1, 0});
      slog::Relation* readrel1250 = db->getRelation("ref");
      refindex1228 = readrel1250->getIndex(ord1249, false);
      std::vector<u16> ord1251({1, 2, 0});
      slog::Relation* readrel1252 = db->getRelation("lambda");
      lambdaindex1229 = readrel1252->getIndex(ord1251, false);
      std::vector<u16> ord1253({1, 0});
      slog::Relation* readrel1254 = db->getRelation("ref");
      refindex1230 = readrel1254->getIndex(ord1253, false);
      std::vector<u16> ord1255({1, 2, 0});
      slog::Relation* readrel1256 = db->getRelation("lambda");
      lambdaindex1231 = readrel1256->getIndex(ord1255, false);
  
    }
    ReadTask1232(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c30 = v_const6cf13cc59dcbe759113f68a4;
      u64 v_c33 = v_constcaa3ee5a2828a31924f6b39d;
      u64 v_c31 = v_const970c20ea81b833e5b5a7accf;
      u64 v_c32 = v_constc40f204dda7ba4054abb9e74;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c41 = _t[0];
        u64 v_c38 = _t[1];
        u64 v_c40 = _t[2];
        slog::join_probe<2,2>(refindex1220, std::array<u64,2>{v_c38, v_c30}, [&](const std::array<u64,2>& m1257) {
          if (!slog::exists_probe<2,1>(refindex1221, std::array<u64,2>{v_c33, 0})) return;
          if (!slog::exists_probe<2,1>(refindex1222, std::array<u64,2>{v_c32, 0})) return;
          if (!slog::exists_probe<3,1>(lambdaindex1223, std::array<u64,3>{v_c32, 0, 0})) return;
          if (!slog::exists_probe<2,1>(refindex1224, std::array<u64,2>{v_c31, 0})) return;
          if (!slog::exists_probe<3,1>(lambdaindex1225, std::array<u64,3>{v_c31, 0, 0})) return;
          slog::join_probe<3,2>(appindex1226, std::array<u64,3>{v_c40, v_c38, 0}, [&](const std::array<u64,3>& m1258) {
            u64 v_c39 = m1258[2];
            slog::join_probe<2,2>(refindex1227, std::array<u64,2>{v_c39, v_c33}, [&](const std::array<u64,2>& m1259) {
              slog::join_probe<2,1>(refindex1228, std::array<u64,2>{v_c32, 0}, [&](const std::array<u64,2>& m1260) {
                u64 v_c34 = m1260[1];
                slog::join_probe<3,2>(lambdaindex1229, std::array<u64,3>{v_c32, v_c34, 0}, [&](const std::array<u64,3>& m1261) {
                  u64 v_c35 = m1261[2];
                  slog::join_probe<2,1>(refindex1230, std::array<u64,2>{v_c31, 0}, [&](const std::array<u64,2>& m1262) {
                    u64 v_c36 = m1262[1];
                    slog::join_probe<3,2>(lambdaindex1231, std::array<u64,3>{v_c31, v_c36, 0}, [&](const std::array<u64,3>& m1263) {
                      u64 v_c37 = m1263[2];
                      ++_fires;
                      slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c33, v_c41}, std::array<u16,3>{1, 2, 0});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:301", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask1232* _cont = new ReadTask1232(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1232(db,b), false);
  // (crule (pre) (scan lambda __t1L8v158 x eb) (body (join-old clo (1 2 0) 1 (1 2 0) __t1L8v158 cb __t3EGT159) (join eval_ans (1 0) 1 __t3EGT159 __t8nKY157) (join eval (0 2 1) 1 __t8nKY157 c ef) (exists eval (2 0 1) 1 c) (join $sup27994x83x0x0x0 (1 3 0 2) 2 c ef __d0 ea) (join-old eval (1 2 0) 2 (1 2 0) ea c __t4j5Q160) (join eval_ans (0 1) 1 __t4j5Q160 va)) (head (emit $sup27994x83x0x0x1 (1 4 0 2 3 5 6 7 8 9) __t8nKY157 cb __d0 __t4j5Q160 c ea eb ef va x)) mcfa-counting.slog:84 #f)
  class ReadTask1273 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** cloindex1264;  slog::Index** eval_ansindex1265;  slog::Index** evalindex1266;  slog::Index** evalindex1267;  slog::Index** $sup27994x83x0x0x0index1268;  slog::Index** evalindex1269;  slog::Index** eval_ansindex1270;  slog::Index** clodelta1271;  slog::Index** evaldelta1272;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup27994x83x0x0x1");
      std::vector<u16> ord1274({1, 4, 0, 2, 3, 5, 6, 7, 8, 9});
      slog::Relation* readrel1275 = db->getRelation("$sup27994x83x0x0x1");
      head_index[0] = readrel1275->getIndex(ord1274, false);
      outer_rel = db->getRelation("lambda");
      std::vector<u16> ord1276({1, 2, 0});
      slog::Relation* readrel1277 = db->getRelation("clo");
      cloindex1264 = readrel1277->getIndex(ord1276, false);
      std::vector<u16> ord1278({1, 2, 0});
      slog::Relation* readrel1279 = db->getRelation("clo");
      clodelta1271 = readrel1279->getIndex(ord1278, true);
      std::vector<u16> ord1280({1, 0});
      slog::Relation* readrel1281 = db->getRelation("eval_ans");
      eval_ansindex1265 = readrel1281->getIndex(ord1280, false);
      std::vector<u16> ord1282({0, 2, 1});
      slog::Relation* readrel1283 = db->getRelation("eval");
      evalindex1266 = readrel1283->getIndex(ord1282, false);
      std::vector<u16> ord1284({2, 0, 1});
      slog::Relation* readrel1285 = db->getRelation("eval");
      evalindex1267 = readrel1285->getIndex(ord1284, false);
      std::vector<u16> ord1286({1, 3, 0, 2});
      slog::Relation* readrel1287 = db->getRelation("$sup27994x83x0x0x0");
      $sup27994x83x0x0x0index1268 = readrel1287->getIndex(ord1286, false);
      std::vector<u16> ord1288({1, 2, 0});
      slog::Relation* readrel1289 = db->getRelation("eval");
      evalindex1269 = readrel1289->getIndex(ord1288, false);
      std::vector<u16> ord1290({1, 2, 0});
      slog::Relation* readrel1291 = db->getRelation("eval");
      evaldelta1272 = readrel1291->getIndex(ord1290, true);
      std::vector<u16> ord1292({0, 1});
      slog::Relation* readrel1293 = db->getRelation("eval_ans");
      eval_ansindex1270 = readrel1293->getIndex(ord1292, false);
  
    }
    ReadTask1273(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c0 = _t[1];
        u64 v_c29 = _t[2];
        slog::join_probe_old<3,1>(cloindex1264, clodelta1271, std::array<u64,3>{v_c155, 0, 0}, [&](const std::array<u64,3>& m1294) {
          u64 v_c27 = m1294[1]; u64 v_c154 = m1294[2];
          slog::join_probe<2,1>(eval_ansindex1265, std::array<u64,2>{v_c154, 0}, [&](const std::array<u64,2>& m1295) {
            u64 v_c151 = m1295[1];
            slog::join_probe<3,1>(evalindex1266, std::array<u64,3>{v_c151, 0, 0}, [&](const std::array<u64,3>& m1296) {
              u64 v_c21 = m1296[1]; u64 v_c3 = m1296[2];
              if (!slog::exists_probe<3,1>(evalindex1267, std::array<u64,3>{v_c21, 0, 0})) return;
              slog::join_probe<4,2>($sup27994x83x0x0x0index1268, std::array<u64,4>{v_c21, v_c3, 0, 0}, [&](const std::array<u64,4>& m1297) {
                u64 v_c152 = m1297[2]; u64 v_c1 = m1297[3];
                slog::join_probe_old<3,2>(evalindex1269, evaldelta1272, std::array<u64,3>{v_c1, v_c21, 0}, [&](const std::array<u64,3>& m1298) {
                  u64 v_c153 = m1298[2];
                  slog::join_probe<2,1>(eval_ansindex1270, std::array<u64,2>{v_c153, 0}, [&](const std::array<u64,2>& m1299) {
                    u64 v_c26 = m1299[1];
                    ++_fires;
                    slog::emit<10>(head_rel[0], head_index[0], newbatch[0], std::array<u64,10>{v_c151, v_c27, v_c152, v_c153, v_c21, v_c1, v_c29, v_c3, v_c26, v_c0}, std::array<u16,10>{1, 4, 0, 2, 3, 5, 6, 7, 8, 9});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:84", "delta:lambda", _fires);
  
      if (!_done)
      {
        ReadTask1273* _cont = new ReadTask1273(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1273(db,b), false);
  // (crule (pre (let __tconst9zoW125 const7c7d2cfc66f4d976987d2d20) (let __tconst0vRf84 conste58dec6bca6f63ef79c3b755) (let __tconst4V4L122 const6bc0ba365ada70df115e1785) (let __tconst4Zcr91 const9a67f28c6b77e842f439a84a) (let __tconst82U8119 consta8180db1c2f300980314f910) (let __tconst4BKz104 const0f8748be649f8ee4066bb1d7) (let __tconst3wDH116 constd5f017533ea574d5f9b3400c) (let __tconst3ktF111 const990b444cbd47632035b2fa1a) (let __tconst5nWJ102 const4f84f41d89b6b717419b4eaa)) (seeded) (body (join ref (1 0) 1 __tconst0vRf84 __t2duR83) (exists ref (1 0) 1 __tconst4Zcr91) (exists ref (1 0) 1 __tconst9zoW125) (exists lambda (1 2 0) 1 __tconst4Zcr91) (exists ref (1 0) 1 __tconst4V4L122) (exists ref (1 0) 1 __tconst4BKz104) (exists lambda (1 2 0) 1 __tconst4BKz104) (exists ref (1 0) 1 __tconst3wDH116) (exists ref (1 0) 1 __tconst5nWJ102) (exists lambda (1 2 0) 1 __tconst5nWJ102) (exists ref (1 0) 1 __tconst3ktF111) (exists lambda (1 2 0) 1 __tconst3ktF111) (exists lambda (1 2 0) 1 __tconst3wDH116) (exists lambda (1 2 0) 1 __tconst82U8119) (exists lambda (1 2 0) 1 __tconst4V4L122) (exists lambda (1 2 0) 1 __tconst9zoW125) (join lambda (1 2 0) 2 __tconst0vRf84 __t2duR83 __t87vL85) (exists app (2 0 1) 1 __t87vL85) (join ref (1 0) 1 __tconst4Zcr91 __t0C9F87) (exists app (2 0 1) 1 __t0C9F87) (join ref (1 0) 1 __tconst9zoW125 __t3Q2G89) (join app (1 2 0) 2 __t3Q2G89 __t0C9F87 __t2Eqd90) (join lambda (1 2 0) 2 __tconst4Zcr91 __t2Eqd90 __t3pgm92) (exists app (2 0 1) 1 __t3pgm92) (join ref (1 0) 1 __tconst4V4L122 __t7aew98) (exists app (1 2 0) 1 __t7aew98) (join ref (1 0) 1 __tconst4BKz104 __t8C0a94) (join lambda (1 2 0) 2 __tconst4BKz104 __t8C0a94 __t4fDK96) (join app (1 2 0) 2 __t7aew98 __t4fDK96 __t7TEO99) (exists app (2 0 1) 1 __t7TEO99) (join ref (1 0) 1 __tconst3wDH116 __t3wir114) (exists app (1 2 0) 1 __t3wir114) (join ref (1 0) 1 __tconst5nWJ102 __t5MaG101) (join lambda (1 2 0) 2 __tconst5nWJ102 __t5MaG101 __t35jA103) (join lambda (1 2 0) 2 __tconst4BKz104 __t35jA103 __t6RuY105) (join app (1 2 0) 2 __t7aew98 __t6RuY105 __t2Z7m108) (exists app (2 0 1) 1 __t2Z7m108) (join ref (1 0) 1 __tconst3ktF111 __t7ohz110) (join lambda (1 2 0) 2 __tconst3ktF111 __t7ohz110 __t8GWA112) (join app (1 2 0) 2 __t3wir114 __t8GWA112 __t44OM115) (join lambda (1 2 0) 2 __tconst3wDH116 __t44OM115 __t7CwH117) (join app (1 2 0) 2 __t7CwH117 __t2Z7m108 __t50Kk118) (join lambda (1 2 0) 2 __tconst82U8119 __t50Kk118 __t3SEs120) (join app (1 2 0) 2 __t3SEs120 __t7TEO99 __t1GdP121) (join lambda (1 2 0) 2 __tconst4V4L122 __t1GdP121 __t5iMg123) (join app (1 2 0) 2 __t5iMg123 __t3pgm92 __t3cyj124) (join lambda (1 2 0) 2 __tconst9zoW125 __t3cyj124 __t4GT8126) (join app (1 2 0) 2 __t4GT8126 __t87vL85 __t6xIu127)) (head (emit program (0) __t6xIu127)) mcfa-counting.slog:241 #f)
  class ReadTask1348 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex1300;  slog::Index** refindex1301;  slog::Index** refindex1302;  slog::Index** lambdaindex1303;  slog::Index** refindex1304;  slog::Index** refindex1305;  slog::Index** lambdaindex1306;  slog::Index** refindex1307;  slog::Index** refindex1308;  slog::Index** lambdaindex1309;  slog::Index** refindex1310;  slog::Index** lambdaindex1311;  slog::Index** lambdaindex1312;  slog::Index** lambdaindex1313;  slog::Index** lambdaindex1314;  slog::Index** lambdaindex1315;  slog::Index** lambdaindex1316;  slog::Index** appindex1317;  slog::Index** refindex1318;  slog::Index** appindex1319;  slog::Index** refindex1320;  slog::Index** appindex1321;  slog::Index** lambdaindex1322;  slog::Index** appindex1323;  slog::Index** refindex1324;  slog::Index** appindex1325;  slog::Index** refindex1326;  slog::Index** lambdaindex1327;  slog::Index** appindex1328;  slog::Index** appindex1329;  slog::Index** refindex1330;  slog::Index** appindex1331;  slog::Index** refindex1332;  slog::Index** lambdaindex1333;  slog::Index** lambdaindex1334;  slog::Index** appindex1335;  slog::Index** appindex1336;  slog::Index** refindex1337;  slog::Index** lambdaindex1338;  slog::Index** appindex1339;  slog::Index** lambdaindex1340;  slog::Index** appindex1341;  slog::Index** lambdaindex1342;  slog::Index** appindex1343;  slog::Index** lambdaindex1344;  slog::Index** appindex1345;  slog::Index** lambdaindex1346;  slog::Index** appindex1347;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("program");
      std::vector<u16> ord1349({0});
      slog::Relation* readrel1350 = db->getRelation("program");
      head_index[0] = readrel1350->getIndex(ord1349, false);
      std::vector<u16> ord1351({1, 0});
      slog::Relation* readrel1352 = db->getRelation("ref");
      refindex1300 = readrel1352->getIndex(ord1351, false);
      std::vector<u16> ord1353({1, 0});
      slog::Relation* readrel1354 = db->getRelation("ref");
      refindex1301 = readrel1354->getIndex(ord1353, false);
      std::vector<u16> ord1355({1, 0});
      slog::Relation* readrel1356 = db->getRelation("ref");
      refindex1302 = readrel1356->getIndex(ord1355, false);
      std::vector<u16> ord1357({1, 2, 0});
      slog::Relation* readrel1358 = db->getRelation("lambda");
      lambdaindex1303 = readrel1358->getIndex(ord1357, false);
      std::vector<u16> ord1359({1, 0});
      slog::Relation* readrel1360 = db->getRelation("ref");
      refindex1304 = readrel1360->getIndex(ord1359, false);
      std::vector<u16> ord1361({1, 0});
      slog::Relation* readrel1362 = db->getRelation("ref");
      refindex1305 = readrel1362->getIndex(ord1361, false);
      std::vector<u16> ord1363({1, 2, 0});
      slog::Relation* readrel1364 = db->getRelation("lambda");
      lambdaindex1306 = readrel1364->getIndex(ord1363, false);
      std::vector<u16> ord1365({1, 0});
      slog::Relation* readrel1366 = db->getRelation("ref");
      refindex1307 = readrel1366->getIndex(ord1365, false);
      std::vector<u16> ord1367({1, 0});
      slog::Relation* readrel1368 = db->getRelation("ref");
      refindex1308 = readrel1368->getIndex(ord1367, false);
      std::vector<u16> ord1369({1, 2, 0});
      slog::Relation* readrel1370 = db->getRelation("lambda");
      lambdaindex1309 = readrel1370->getIndex(ord1369, false);
      std::vector<u16> ord1371({1, 0});
      slog::Relation* readrel1372 = db->getRelation("ref");
      refindex1310 = readrel1372->getIndex(ord1371, false);
      std::vector<u16> ord1373({1, 2, 0});
      slog::Relation* readrel1374 = db->getRelation("lambda");
      lambdaindex1311 = readrel1374->getIndex(ord1373, false);
      std::vector<u16> ord1375({1, 2, 0});
      slog::Relation* readrel1376 = db->getRelation("lambda");
      lambdaindex1312 = readrel1376->getIndex(ord1375, false);
      std::vector<u16> ord1377({1, 2, 0});
      slog::Relation* readrel1378 = db->getRelation("lambda");
      lambdaindex1313 = readrel1378->getIndex(ord1377, false);
      std::vector<u16> ord1379({1, 2, 0});
      slog::Relation* readrel1380 = db->getRelation("lambda");
      lambdaindex1314 = readrel1380->getIndex(ord1379, false);
      std::vector<u16> ord1381({1, 2, 0});
      slog::Relation* readrel1382 = db->getRelation("lambda");
      lambdaindex1315 = readrel1382->getIndex(ord1381, false);
      std::vector<u16> ord1383({1, 2, 0});
      slog::Relation* readrel1384 = db->getRelation("lambda");
      lambdaindex1316 = readrel1384->getIndex(ord1383, false);
      std::vector<u16> ord1385({2, 0, 1});
      slog::Relation* readrel1386 = db->getRelation("app");
      appindex1317 = readrel1386->getIndex(ord1385, false);
      std::vector<u16> ord1387({1, 0});
      slog::Relation* readrel1388 = db->getRelation("ref");
      refindex1318 = readrel1388->getIndex(ord1387, false);
      std::vector<u16> ord1389({2, 0, 1});
      slog::Relation* readrel1390 = db->getRelation("app");
      appindex1319 = readrel1390->getIndex(ord1389, false);
      std::vector<u16> ord1391({1, 0});
      slog::Relation* readrel1392 = db->getRelation("ref");
      refindex1320 = readrel1392->getIndex(ord1391, false);
      std::vector<u16> ord1393({1, 2, 0});
      slog::Relation* readrel1394 = db->getRelation("app");
      appindex1321 = readrel1394->getIndex(ord1393, false);
      std::vector<u16> ord1395({1, 2, 0});
      slog::Relation* readrel1396 = db->getRelation("lambda");
      lambdaindex1322 = readrel1396->getIndex(ord1395, false);
      std::vector<u16> ord1397({2, 0, 1});
      slog::Relation* readrel1398 = db->getRelation("app");
      appindex1323 = readrel1398->getIndex(ord1397, false);
      std::vector<u16> ord1399({1, 0});
      slog::Relation* readrel1400 = db->getRelation("ref");
      refindex1324 = readrel1400->getIndex(ord1399, false);
      std::vector<u16> ord1401({1, 2, 0});
      slog::Relation* readrel1402 = db->getRelation("app");
      appindex1325 = readrel1402->getIndex(ord1401, false);
      std::vector<u16> ord1403({1, 0});
      slog::Relation* readrel1404 = db->getRelation("ref");
      refindex1326 = readrel1404->getIndex(ord1403, false);
      std::vector<u16> ord1405({1, 2, 0});
      slog::Relation* readrel1406 = db->getRelation("lambda");
      lambdaindex1327 = readrel1406->getIndex(ord1405, false);
      std::vector<u16> ord1407({1, 2, 0});
      slog::Relation* readrel1408 = db->getRelation("app");
      appindex1328 = readrel1408->getIndex(ord1407, false);
      std::vector<u16> ord1409({2, 0, 1});
      slog::Relation* readrel1410 = db->getRelation("app");
      appindex1329 = readrel1410->getIndex(ord1409, false);
      std::vector<u16> ord1411({1, 0});
      slog::Relation* readrel1412 = db->getRelation("ref");
      refindex1330 = readrel1412->getIndex(ord1411, false);
      std::vector<u16> ord1413({1, 2, 0});
      slog::Relation* readrel1414 = db->getRelation("app");
      appindex1331 = readrel1414->getIndex(ord1413, false);
      std::vector<u16> ord1415({1, 0});
      slog::Relation* readrel1416 = db->getRelation("ref");
      refindex1332 = readrel1416->getIndex(ord1415, false);
      std::vector<u16> ord1417({1, 2, 0});
      slog::Relation* readrel1418 = db->getRelation("lambda");
      lambdaindex1333 = readrel1418->getIndex(ord1417, false);
      std::vector<u16> ord1419({1, 2, 0});
      slog::Relation* readrel1420 = db->getRelation("lambda");
      lambdaindex1334 = readrel1420->getIndex(ord1419, false);
      std::vector<u16> ord1421({1, 2, 0});
      slog::Relation* readrel1422 = db->getRelation("app");
      appindex1335 = readrel1422->getIndex(ord1421, false);
      std::vector<u16> ord1423({2, 0, 1});
      slog::Relation* readrel1424 = db->getRelation("app");
      appindex1336 = readrel1424->getIndex(ord1423, false);
      std::vector<u16> ord1425({1, 0});
      slog::Relation* readrel1426 = db->getRelation("ref");
      refindex1337 = readrel1426->getIndex(ord1425, false);
      std::vector<u16> ord1427({1, 2, 0});
      slog::Relation* readrel1428 = db->getRelation("lambda");
      lambdaindex1338 = readrel1428->getIndex(ord1427, false);
      std::vector<u16> ord1429({1, 2, 0});
      slog::Relation* readrel1430 = db->getRelation("app");
      appindex1339 = readrel1430->getIndex(ord1429, false);
      std::vector<u16> ord1431({1, 2, 0});
      slog::Relation* readrel1432 = db->getRelation("lambda");
      lambdaindex1340 = readrel1432->getIndex(ord1431, false);
      std::vector<u16> ord1433({1, 2, 0});
      slog::Relation* readrel1434 = db->getRelation("app");
      appindex1341 = readrel1434->getIndex(ord1433, false);
      std::vector<u16> ord1435({1, 2, 0});
      slog::Relation* readrel1436 = db->getRelation("lambda");
      lambdaindex1342 = readrel1436->getIndex(ord1435, false);
      std::vector<u16> ord1437({1, 2, 0});
      slog::Relation* readrel1438 = db->getRelation("app");
      appindex1343 = readrel1438->getIndex(ord1437, false);
      std::vector<u16> ord1439({1, 2, 0});
      slog::Relation* readrel1440 = db->getRelation("lambda");
      lambdaindex1344 = readrel1440->getIndex(ord1439, false);
      std::vector<u16> ord1441({1, 2, 0});
      slog::Relation* readrel1442 = db->getRelation("app");
      appindex1345 = readrel1442->getIndex(ord1441, false);
      std::vector<u16> ord1443({1, 2, 0});
      slog::Relation* readrel1444 = db->getRelation("lambda");
      lambdaindex1346 = readrel1444->getIndex(ord1443, false);
      std::vector<u16> ord1445({1, 2, 0});
      slog::Relation* readrel1446 = db->getRelation("app");
      appindex1347 = readrel1446->getIndex(ord1445, false);
  
    }
    ReadTask1348(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c93 = v_const7c7d2cfc66f4d976987d2d20;
      u64 v_c97 = v_conste58dec6bca6f63ef79c3b755;
      u64 v_c94 = v_const6bc0ba365ada70df115e1785;
      u64 v_c96 = v_const9a67f28c6b77e842f439a84a;
      u64 v_c95 = v_consta8180db1c2f300980314f910;
      u64 v_c98 = v_const0f8748be649f8ee4066bb1d7;
      u64 v_c99 = v_constd5f017533ea574d5f9b3400c;
      u64 v_c100 = v_const990b444cbd47632035b2fa1a;
      u64 v_c101 = v_const4f84f41d89b6b717419b4eaa;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex1300, std::array<u64,2>{v_c97, 0}, [&](const std::array<u64,2>& m1447) {
        u64 v_c109 = m1447[1];
        if (!slog::exists_probe<2,1>(refindex1301, std::array<u64,2>{v_c96, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1302, std::array<u64,2>{v_c93, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1303, std::array<u64,3>{v_c96, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1304, std::array<u64,2>{v_c94, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1305, std::array<u64,2>{v_c98, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1306, std::array<u64,3>{v_c98, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1307, std::array<u64,2>{v_c99, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1308, std::array<u64,2>{v_c101, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1309, std::array<u64,3>{v_c101, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1310, std::array<u64,2>{v_c100, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1311, std::array<u64,3>{v_c100, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1312, std::array<u64,3>{v_c99, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1313, std::array<u64,3>{v_c95, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1314, std::array<u64,3>{v_c94, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1315, std::array<u64,3>{v_c93, 0, 0})) return;
        slog::join_probe<3,2>(lambdaindex1316, std::array<u64,3>{v_c97, v_c109, 0}, [&](const std::array<u64,3>& m1448) {
          u64 v_c110 = m1448[2];
          if (!slog::exists_probe<3,1>(appindex1317, std::array<u64,3>{v_c110, 0, 0})) return;
          slog::join_probe<2,1>(refindex1318, std::array<u64,2>{v_c96, 0}, [&](const std::array<u64,2>& m1449) {
            u64 v_c111 = m1449[1];
            if (!slog::exists_probe<3,1>(appindex1319, std::array<u64,3>{v_c111, 0, 0})) return;
            slog::join_probe<2,1>(refindex1320, std::array<u64,2>{v_c93, 0}, [&](const std::array<u64,2>& m1450) {
              u64 v_c112 = m1450[1];
              slog::join_probe<3,2>(appindex1321, std::array<u64,3>{v_c112, v_c111, 0}, [&](const std::array<u64,3>& m1451) {
                u64 v_c113 = m1451[2];
                slog::join_probe<3,2>(lambdaindex1322, std::array<u64,3>{v_c96, v_c113, 0}, [&](const std::array<u64,3>& m1452) {
                  u64 v_c114 = m1452[2];
                  if (!slog::exists_probe<3,1>(appindex1323, std::array<u64,3>{v_c114, 0, 0})) return;
                  slog::join_probe<2,1>(refindex1324, std::array<u64,2>{v_c94, 0}, [&](const std::array<u64,2>& m1453) {
                    u64 v_c106 = m1453[1];
                    if (!slog::exists_probe<3,1>(appindex1325, std::array<u64,3>{v_c106, 0, 0})) return;
                    slog::join_probe<2,1>(refindex1326, std::array<u64,2>{v_c98, 0}, [&](const std::array<u64,2>& m1454) {
                      u64 v_c108 = m1454[1];
                      slog::join_probe<3,2>(lambdaindex1327, std::array<u64,3>{v_c98, v_c108, 0}, [&](const std::array<u64,3>& m1455) {
                        u64 v_c107 = m1455[2];
                        slog::join_probe<3,2>(appindex1328, std::array<u64,3>{v_c106, v_c107, 0}, [&](const std::array<u64,3>& m1456) {
                          u64 v_c104 = m1456[2];
                          if (!slog::exists_probe<3,1>(appindex1329, std::array<u64,3>{v_c104, 0, 0})) return;
                          slog::join_probe<2,1>(refindex1330, std::array<u64,2>{v_c99, 0}, [&](const std::array<u64,2>& m1457) {
                            u64 v_c115 = m1457[1];
                            if (!slog::exists_probe<3,1>(appindex1331, std::array<u64,3>{v_c115, 0, 0})) return;
                            slog::join_probe<2,1>(refindex1332, std::array<u64,2>{v_c101, 0}, [&](const std::array<u64,2>& m1458) {
                              u64 v_c116 = m1458[1];
                              slog::join_probe<3,2>(lambdaindex1333, std::array<u64,3>{v_c101, v_c116, 0}, [&](const std::array<u64,3>& m1459) {
                                u64 v_c117 = m1459[2];
                                slog::join_probe<3,2>(lambdaindex1334, std::array<u64,3>{v_c98, v_c117, 0}, [&](const std::array<u64,3>& m1460) {
                                  u64 v_c118 = m1460[2];
                                  slog::join_probe<3,2>(appindex1335, std::array<u64,3>{v_c106, v_c118, 0}, [&](const std::array<u64,3>& m1461) {
                                    u64 v_c119 = m1461[2];
                                    if (!slog::exists_probe<3,1>(appindex1336, std::array<u64,3>{v_c119, 0, 0})) return;
                                    slog::join_probe<2,1>(refindex1337, std::array<u64,2>{v_c100, 0}, [&](const std::array<u64,2>& m1462) {
                                      u64 v_c123 = m1462[1];
                                      slog::join_probe<3,2>(lambdaindex1338, std::array<u64,3>{v_c100, v_c123, 0}, [&](const std::array<u64,3>& m1463) {
                                        u64 v_c122 = m1463[2];
                                        slog::join_probe<3,2>(appindex1339, std::array<u64,3>{v_c115, v_c122, 0}, [&](const std::array<u64,3>& m1464) {
                                          u64 v_c121 = m1464[2];
                                          slog::join_probe<3,2>(lambdaindex1340, std::array<u64,3>{v_c99, v_c121, 0}, [&](const std::array<u64,3>& m1465) {
                                            u64 v_c120 = m1465[2];
                                            slog::join_probe<3,2>(appindex1341, std::array<u64,3>{v_c120, v_c119, 0}, [&](const std::array<u64,3>& m1466) {
                                              u64 v_c105 = m1466[2];
                                              slog::join_probe<3,2>(lambdaindex1342, std::array<u64,3>{v_c95, v_c105, 0}, [&](const std::array<u64,3>& m1467) {
                                                u64 v_c103 = m1467[2];
                                                slog::join_probe<3,2>(appindex1343, std::array<u64,3>{v_c103, v_c104, 0}, [&](const std::array<u64,3>& m1468) {
                                                  u64 v_c102 = m1468[2];
                                                  slog::join_probe<3,2>(lambdaindex1344, std::array<u64,3>{v_c94, v_c102, 0}, [&](const std::array<u64,3>& m1469) {
                                                    u64 v_c173 = m1469[2];
                                                    slog::join_probe<3,2>(appindex1345, std::array<u64,3>{v_c173, v_c114, 0}, [&](const std::array<u64,3>& m1470) {
                                                      u64 v_c174 = m1470[2];
                                                      slog::join_probe<3,2>(lambdaindex1346, std::array<u64,3>{v_c93, v_c174, 0}, [&](const std::array<u64,3>& m1471) {
                                                        u64 v_c175 = m1471[2];
                                                        slog::join_probe<3,2>(appindex1347, std::array<u64,3>{v_c175, v_c110, 0}, [&](const std::array<u64,3>& m1472) {
                                                          u64 v_c176 = m1472[2];
                                                          ++_fires;
                                                          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c176}, std::array<u16,1>{0});
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
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:241", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask1348(db,b));
  // (crule (pre (let __tconst4Xaz41 const81cb39a72a584ab4f703b7f7) (let __tconst1aIN38 const4d5ce1398140fbe27561181f) (let __tconst1ha033 const969c6e56242ce8d0a4346602) (let __tconst37GM26 const85f09fa1913b9daf65957cf7) (let __tconst4xzG22 constdbf1bdba02122b2adce28528) (let __tconst1HMF17 constd7a1925d249b4768c8a9f2d8)) (probe lambda (1 2 0) 1 __tconst1HMF17 __t7H1u16 __t2wNc18) (body (join ref (0 1) 2 __t7H1u16 __tconst1HMF17) (exists ref (1 0) 1 __tconst37GM26) (exists lambda (1 2 0) 1 __tconst37GM26) (exists ref (1 0) 1 __tconst4Xaz41) (exists ref (1 0) 1 __tconst1ha033) (exists lambda (1 2 0) 1 __tconst1ha033) (join ref (1 0) 1 __tconst4xzG22 __t2DOE20) (join ref (1 0) 1 __tconst37GM26 __t7U1m25) (join lambda (1 2 0) 2 __tconst37GM26 __t7U1m25 __t5myE27) (join ref (1 0) 1 __tconst4Xaz41 __t75SZ29) (join ref (1 0) 1 __tconst1ha033 __t7N9A32) (join lambda (1 2 0) 2 __tconst1ha033 __t7N9A32 __t065j34)) (head (mkstruct app (1 2 0) __t3pMW37 __t75SZ29 __t065j34) (mkstruct app (1 2 0) __t2Vg230 __t75SZ29 __t5myE27) (mkstruct app (1 2 0) __t3b2k21 __t2DOE20 __t2wNc18)) mcfa-counting.slog:260 #f)
  class ReadTask1485 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** refindex1473;  slog::Index** refindex1474;  slog::Index** lambdaindex1475;  slog::Index** refindex1476;  slog::Index** refindex1477;  slog::Index** lambdaindex1478;  slog::Index** refindex1479;  slog::Index** refindex1480;  slog::Index** lambdaindex1481;  slog::Index** refindex1482;  slog::Index** refindex1483;  slog::Index** lambdaindex1484;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      head_rel[1] = db->getRelation("app");
      head_rel[2] = db->getRelation("app");
      std::vector<u16> ord1486({1, 2, 0});
      slog::Relation* readrel1487 = db->getRelation("lambda");
      driver_index = readrel1487->getIndex(ord1486, true);
      std::vector<u16> ord1488({0, 1});
      slog::Relation* readrel1489 = db->getRelation("ref");
      refindex1473 = readrel1489->getIndex(ord1488, false);
      std::vector<u16> ord1490({1, 0});
      slog::Relation* readrel1491 = db->getRelation("ref");
      refindex1474 = readrel1491->getIndex(ord1490, false);
      std::vector<u16> ord1492({1, 2, 0});
      slog::Relation* readrel1493 = db->getRelation("lambda");
      lambdaindex1475 = readrel1493->getIndex(ord1492, false);
      std::vector<u16> ord1494({1, 0});
      slog::Relation* readrel1495 = db->getRelation("ref");
      refindex1476 = readrel1495->getIndex(ord1494, false);
      std::vector<u16> ord1496({1, 0});
      slog::Relation* readrel1497 = db->getRelation("ref");
      refindex1477 = readrel1497->getIndex(ord1496, false);
      std::vector<u16> ord1498({1, 2, 0});
      slog::Relation* readrel1499 = db->getRelation("lambda");
      lambdaindex1478 = readrel1499->getIndex(ord1498, false);
      std::vector<u16> ord1500({1, 0});
      slog::Relation* readrel1501 = db->getRelation("ref");
      refindex1479 = readrel1501->getIndex(ord1500, false);
      std::vector<u16> ord1502({1, 0});
      slog::Relation* readrel1503 = db->getRelation("ref");
      refindex1480 = readrel1503->getIndex(ord1502, false);
      std::vector<u16> ord1504({1, 2, 0});
      slog::Relation* readrel1505 = db->getRelation("lambda");
      lambdaindex1481 = readrel1505->getIndex(ord1504, false);
      std::vector<u16> ord1506({1, 0});
      slog::Relation* readrel1507 = db->getRelation("ref");
      refindex1482 = readrel1507->getIndex(ord1506, false);
      std::vector<u16> ord1508({1, 0});
      slog::Relation* readrel1509 = db->getRelation("ref");
      refindex1483 = readrel1509->getIndex(ord1508, false);
      std::vector<u16> ord1510({1, 2, 0});
      slog::Relation* readrel1511 = db->getRelation("lambda");
      lambdaindex1484 = readrel1511->getIndex(ord1510, false);
  
    }
    ReadTask1485(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c156 = v_const81cb39a72a584ab4f703b7f7;
      u64 v_c157 = v_const4d5ce1398140fbe27561181f;
      u64 v_c158 = v_const969c6e56242ce8d0a4346602;
      u64 v_c159 = v_const85f09fa1913b9daf65957cf7;
      u64 v_c160 = v_constdbf1bdba02122b2adce28528;
      u64 v_c161 = v_constd7a1925d249b4768c8a9f2d8;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c161, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1512) {
        u64 v_c162 = m1512[1];
        u64 v_c163 = m1512[2];
        if (buckethash(v_c162) != bucket) return;
        slog::join_probe<2,2>(refindex1473, std::array<u64,2>{v_c162, v_c161}, [&](const std::array<u64,2>& m1513) {
          if (!slog::exists_probe<2,1>(refindex1474, std::array<u64,2>{v_c159, 0})) return;
          if (!slog::exists_probe<3,1>(lambdaindex1475, std::array<u64,3>{v_c159, 0, 0})) return;
          if (!slog::exists_probe<2,1>(refindex1476, std::array<u64,2>{v_c156, 0})) return;
          if (!slog::exists_probe<2,1>(refindex1477, std::array<u64,2>{v_c158, 0})) return;
          if (!slog::exists_probe<3,1>(lambdaindex1478, std::array<u64,3>{v_c158, 0, 0})) return;
          slog::join_probe<2,1>(refindex1479, std::array<u64,2>{v_c160, 0}, [&](const std::array<u64,2>& m1514) {
            u64 v_c164 = m1514[1];
            slog::join_probe<2,1>(refindex1480, std::array<u64,2>{v_c159, 0}, [&](const std::array<u64,2>& m1515) {
              u64 v_c165 = m1515[1];
              slog::join_probe<3,2>(lambdaindex1481, std::array<u64,3>{v_c159, v_c165, 0}, [&](const std::array<u64,3>& m1516) {
                u64 v_c166 = m1516[2];
                slog::join_probe<2,1>(refindex1482, std::array<u64,2>{v_c156, 0}, [&](const std::array<u64,2>& m1517) {
                  u64 v_c167 = m1517[1];
                  slog::join_probe<2,1>(refindex1483, std::array<u64,2>{v_c158, 0}, [&](const std::array<u64,2>& m1518) {
                    u64 v_c168 = m1518[1];
                    slog::join_probe<3,2>(lambdaindex1484, std::array<u64,3>{v_c158, v_c168, 0}, [&](const std::array<u64,3>& m1519) {
                      u64 v_c169 = m1519[2];
                      ++_fires;
                      slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c167, v_c169}, std::array<u16,3>{1, 2, 0});
                      slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c167, v_c166}, std::array<u16,3>{1, 2, 0});
                      slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c164, v_c163}, std::array<u16,3>{1, 2, 0});
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
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:260", "delta:lambda", _fires);
  
      if (!_done)
      {
        ReadTask1485* _cont = new ReadTask1485(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1485(db,b), false);
  // (crule (pre (let __tconst9zoW125 const7c7d2cfc66f4d976987d2d20) (let __tconst4V4L122 const6bc0ba365ada70df115e1785) (let __tconst82U8119 consta8180db1c2f300980314f910) (let __tconst3wDH116 constd5f017533ea574d5f9b3400c) (let __tconst3ktF111 const990b444cbd47632035b2fa1a) (let __tconst4BKz104 const0f8748be649f8ee4066bb1d7) (let __tconst5nWJ102 const4f84f41d89b6b717419b4eaa) (let __tconst4Zcr91 const9a67f28c6b77e842f439a84a) (let __tconst0vRf84 conste58dec6bca6f63ef79c3b755)) (probe lambda (1 2 0) 1 __tconst0vRf84 __t2duR83 __t87vL85) (body (join ref (0 1) 2 __t2duR83 __tconst0vRf84) (exists ref (1 0) 1 __tconst9zoW125) (exists ref (1 0) 1 __tconst4BKz104) (exists lambda (1 2 0) 1 __tconst4BKz104) (exists ref (1 0) 1 __tconst4V4L122) (exists ref (1 0) 1 __tconst5nWJ102) (exists lambda (1 2 0) 1 __tconst5nWJ102) (exists ref (1 0) 1 __tconst3ktF111) (exists lambda (1 2 0) 1 __tconst3ktF111) (exists ref (1 0) 1 __tconst3wDH116) (join ref (1 0) 1 __tconst4Zcr91 __t0C9F87) (exists app (2 0 1) 1 __t0C9F87) (join ref (1 0) 1 __tconst9zoW125 __t3Q2G89) (join app (1 2 0) 2 __t3Q2G89 __t0C9F87 __t2Eqd90) (join ref (1 0) 1 __tconst4BKz104 __t8C0a94) (join lambda (1 2 0) 2 __tconst4BKz104 __t8C0a94 __t4fDK96) (join ref (1 0) 1 __tconst4V4L122 __t7aew98) (join ref (1 0) 1 __tconst5nWJ102 __t5MaG101) (join lambda (1 2 0) 2 __tconst5nWJ102 __t5MaG101 __t35jA103) (join ref (1 0) 1 __tconst3ktF111 __t7ohz110) (join lambda (1 2 0) 2 __tconst3ktF111 __t7ohz110 __t8GWA112) (join ref (1 0) 1 __tconst3wDH116 __t3wir114)) (head (mkstruct app (1 2 0) __t44OM115 __t3wir114 __t8GWA112) (mkstruct lambda (1 2 0) __t6RuY105 __tconst4BKz104 __t35jA103) (mkstruct app (1 2 0) __t7TEO99 __t7aew98 __t4fDK96) (mkstruct lambda (1 2 0) __t3pgm92 __tconst4Zcr91 __t2Eqd90)) mcfa-counting.slog:241 #f)
  class ReadTask1542 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[4];
    slog::Index** head_index[4];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** refindex1520;  slog::Index** refindex1521;  slog::Index** refindex1522;  slog::Index** lambdaindex1523;  slog::Index** refindex1524;  slog::Index** refindex1525;  slog::Index** lambdaindex1526;  slog::Index** refindex1527;  slog::Index** lambdaindex1528;  slog::Index** refindex1529;  slog::Index** refindex1530;  slog::Index** appindex1531;  slog::Index** refindex1532;  slog::Index** appindex1533;  slog::Index** refindex1534;  slog::Index** lambdaindex1535;  slog::Index** refindex1536;  slog::Index** refindex1537;  slog::Index** lambdaindex1538;  slog::Index** refindex1539;  slog::Index** lambdaindex1540;  slog::Index** refindex1541;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      head_rel[1] = db->getRelation("lambda");
      head_rel[2] = db->getRelation("app");
      head_rel[3] = db->getRelation("lambda");
      std::vector<u16> ord1543({1, 2, 0});
      slog::Relation* readrel1544 = db->getRelation("lambda");
      driver_index = readrel1544->getIndex(ord1543, true);
      std::vector<u16> ord1545({0, 1});
      slog::Relation* readrel1546 = db->getRelation("ref");
      refindex1520 = readrel1546->getIndex(ord1545, false);
      std::vector<u16> ord1547({1, 0});
      slog::Relation* readrel1548 = db->getRelation("ref");
      refindex1521 = readrel1548->getIndex(ord1547, false);
      std::vector<u16> ord1549({1, 0});
      slog::Relation* readrel1550 = db->getRelation("ref");
      refindex1522 = readrel1550->getIndex(ord1549, false);
      std::vector<u16> ord1551({1, 2, 0});
      slog::Relation* readrel1552 = db->getRelation("lambda");
      lambdaindex1523 = readrel1552->getIndex(ord1551, false);
      std::vector<u16> ord1553({1, 0});
      slog::Relation* readrel1554 = db->getRelation("ref");
      refindex1524 = readrel1554->getIndex(ord1553, false);
      std::vector<u16> ord1555({1, 0});
      slog::Relation* readrel1556 = db->getRelation("ref");
      refindex1525 = readrel1556->getIndex(ord1555, false);
      std::vector<u16> ord1557({1, 2, 0});
      slog::Relation* readrel1558 = db->getRelation("lambda");
      lambdaindex1526 = readrel1558->getIndex(ord1557, false);
      std::vector<u16> ord1559({1, 0});
      slog::Relation* readrel1560 = db->getRelation("ref");
      refindex1527 = readrel1560->getIndex(ord1559, false);
      std::vector<u16> ord1561({1, 2, 0});
      slog::Relation* readrel1562 = db->getRelation("lambda");
      lambdaindex1528 = readrel1562->getIndex(ord1561, false);
      std::vector<u16> ord1563({1, 0});
      slog::Relation* readrel1564 = db->getRelation("ref");
      refindex1529 = readrel1564->getIndex(ord1563, false);
      std::vector<u16> ord1565({1, 0});
      slog::Relation* readrel1566 = db->getRelation("ref");
      refindex1530 = readrel1566->getIndex(ord1565, false);
      std::vector<u16> ord1567({2, 0, 1});
      slog::Relation* readrel1568 = db->getRelation("app");
      appindex1531 = readrel1568->getIndex(ord1567, false);
      std::vector<u16> ord1569({1, 0});
      slog::Relation* readrel1570 = db->getRelation("ref");
      refindex1532 = readrel1570->getIndex(ord1569, false);
      std::vector<u16> ord1571({1, 2, 0});
      slog::Relation* readrel1572 = db->getRelation("app");
      appindex1533 = readrel1572->getIndex(ord1571, false);
      std::vector<u16> ord1573({1, 0});
      slog::Relation* readrel1574 = db->getRelation("ref");
      refindex1534 = readrel1574->getIndex(ord1573, false);
      std::vector<u16> ord1575({1, 2, 0});
      slog::Relation* readrel1576 = db->getRelation("lambda");
      lambdaindex1535 = readrel1576->getIndex(ord1575, false);
      std::vector<u16> ord1577({1, 0});
      slog::Relation* readrel1578 = db->getRelation("ref");
      refindex1536 = readrel1578->getIndex(ord1577, false);
      std::vector<u16> ord1579({1, 0});
      slog::Relation* readrel1580 = db->getRelation("ref");
      refindex1537 = readrel1580->getIndex(ord1579, false);
      std::vector<u16> ord1581({1, 2, 0});
      slog::Relation* readrel1582 = db->getRelation("lambda");
      lambdaindex1538 = readrel1582->getIndex(ord1581, false);
      std::vector<u16> ord1583({1, 0});
      slog::Relation* readrel1584 = db->getRelation("ref");
      refindex1539 = readrel1584->getIndex(ord1583, false);
      std::vector<u16> ord1585({1, 2, 0});
      slog::Relation* readrel1586 = db->getRelation("lambda");
      lambdaindex1540 = readrel1586->getIndex(ord1585, false);
      std::vector<u16> ord1587({1, 0});
      slog::Relation* readrel1588 = db->getRelation("ref");
      refindex1541 = readrel1588->getIndex(ord1587, false);
  
    }
    ReadTask1542(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c93 = v_const7c7d2cfc66f4d976987d2d20;
      u64 v_c94 = v_const6bc0ba365ada70df115e1785;
      u64 v_c95 = v_consta8180db1c2f300980314f910;
      u64 v_c99 = v_constd5f017533ea574d5f9b3400c;
      u64 v_c100 = v_const990b444cbd47632035b2fa1a;
      u64 v_c98 = v_const0f8748be649f8ee4066bb1d7;
      u64 v_c101 = v_const4f84f41d89b6b717419b4eaa;
      u64 v_c96 = v_const9a67f28c6b77e842f439a84a;
      u64 v_c97 = v_conste58dec6bca6f63ef79c3b755;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[4];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c97, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1589) {
        u64 v_c109 = m1589[1];
        u64 v_c110 = m1589[2];
        if (buckethash(v_c109) != bucket) return;
        slog::join_probe<2,2>(refindex1520, std::array<u64,2>{v_c109, v_c97}, [&](const std::array<u64,2>& m1590) {
          if (!slog::exists_probe<2,1>(refindex1521, std::array<u64,2>{v_c93, 0})) return;
          if (!slog::exists_probe<2,1>(refindex1522, std::array<u64,2>{v_c98, 0})) return;
          if (!slog::exists_probe<3,1>(lambdaindex1523, std::array<u64,3>{v_c98, 0, 0})) return;
          if (!slog::exists_probe<2,1>(refindex1524, std::array<u64,2>{v_c94, 0})) return;
          if (!slog::exists_probe<2,1>(refindex1525, std::array<u64,2>{v_c101, 0})) return;
          if (!slog::exists_probe<3,1>(lambdaindex1526, std::array<u64,3>{v_c101, 0, 0})) return;
          if (!slog::exists_probe<2,1>(refindex1527, std::array<u64,2>{v_c100, 0})) return;
          if (!slog::exists_probe<3,1>(lambdaindex1528, std::array<u64,3>{v_c100, 0, 0})) return;
          if (!slog::exists_probe<2,1>(refindex1529, std::array<u64,2>{v_c99, 0})) return;
          slog::join_probe<2,1>(refindex1530, std::array<u64,2>{v_c96, 0}, [&](const std::array<u64,2>& m1591) {
            u64 v_c111 = m1591[1];
            if (!slog::exists_probe<3,1>(appindex1531, std::array<u64,3>{v_c111, 0, 0})) return;
            slog::join_probe<2,1>(refindex1532, std::array<u64,2>{v_c93, 0}, [&](const std::array<u64,2>& m1592) {
              u64 v_c112 = m1592[1];
              slog::join_probe<3,2>(appindex1533, std::array<u64,3>{v_c112, v_c111, 0}, [&](const std::array<u64,3>& m1593) {
                u64 v_c113 = m1593[2];
                slog::join_probe<2,1>(refindex1534, std::array<u64,2>{v_c98, 0}, [&](const std::array<u64,2>& m1594) {
                  u64 v_c108 = m1594[1];
                  slog::join_probe<3,2>(lambdaindex1535, std::array<u64,3>{v_c98, v_c108, 0}, [&](const std::array<u64,3>& m1595) {
                    u64 v_c107 = m1595[2];
                    slog::join_probe<2,1>(refindex1536, std::array<u64,2>{v_c94, 0}, [&](const std::array<u64,2>& m1596) {
                      u64 v_c106 = m1596[1];
                      slog::join_probe<2,1>(refindex1537, std::array<u64,2>{v_c101, 0}, [&](const std::array<u64,2>& m1597) {
                        u64 v_c116 = m1597[1];
                        slog::join_probe<3,2>(lambdaindex1538, std::array<u64,3>{v_c101, v_c116, 0}, [&](const std::array<u64,3>& m1598) {
                          u64 v_c117 = m1598[2];
                          slog::join_probe<2,1>(refindex1539, std::array<u64,2>{v_c100, 0}, [&](const std::array<u64,2>& m1599) {
                            u64 v_c123 = m1599[1];
                            slog::join_probe<3,2>(lambdaindex1540, std::array<u64,3>{v_c100, v_c123, 0}, [&](const std::array<u64,3>& m1600) {
                              u64 v_c122 = m1600[2];
                              slog::join_probe<2,1>(refindex1541, std::array<u64,2>{v_c99, 0}, [&](const std::array<u64,2>& m1601) {
                                u64 v_c115 = m1601[1];
                                ++_fires;
                                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c115, v_c122}, std::array<u16,3>{1, 2, 0});
                                slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c98, v_c117}, std::array<u16,3>{1, 2, 0});
                                slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c106, v_c107}, std::array<u16,3>{1, 2, 0});
                                slog::emit_struct<3>(head_rel[3], newbatch[3], std::array<u64,2>{v_c96, v_c113}, std::array<u16,3>{1, 2, 0});
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
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:241", "delta:lambda", _fires);
  
      if (!_done)
      {
        ReadTask1542* _cont = new ReadTask1542(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1542(db,b), false);
  // (crule (pre (let __tconst9zoW125 const7c7d2cfc66f4d976987d2d20) (let __tconst4V4L122 const6bc0ba365ada70df115e1785) (let __tconst4Zcr91 const9a67f28c6b77e842f439a84a) (let __tconst0vRf84 conste58dec6bca6f63ef79c3b755) (let __tconst82U8119 consta8180db1c2f300980314f910) (let __tconst4BKz104 const0f8748be649f8ee4066bb1d7) (let __tconst3wDH116 constd5f017533ea574d5f9b3400c) (let __tconst3ktF111 const990b444cbd47632035b2fa1a) (let __tconst5nWJ102 const4f84f41d89b6b717419b4eaa)) (scan app __t3cyj124 __t5iMg123 __t3pgm92) (body (exists lambda (0 1 2) 2 __t5iMg123 __tconst4V4L122) (exists ref (1 0) 1 __tconst0vRf84) (exists lambda (1 2 0) 1 __tconst0vRf84) (exists ref (1 0) 1 __tconst4Zcr91) (exists ref (1 0) 1 __tconst9zoW125) (exists ref (1 0) 1 __tconst4V4L122) (exists ref (1 0) 1 __tconst4BKz104) (exists lambda (1 2 0) 1 __tconst4BKz104) (exists lambda (1 2 0) 1 __tconst82U8119) (exists ref (1 0) 1 __tconst3wDH116) (exists ref (1 0) 1 __tconst5nWJ102) (exists lambda (1 2 0) 1 __tconst5nWJ102) (exists lambda (1 2 0) 1 __tconst3wDH116) (exists lambda (1 2 0) 1 __tconst3ktF111) (exists ref (1 0) 1 __tconst3ktF111) (join lambda (0 1 2) 2 __t3pgm92 __tconst4Zcr91 __t2Eqd90) (join lambda (0 1 2) 2 __t5iMg123 __tconst4V4L122 __t1GdP121) (join ref (1 0) 1 __tconst0vRf84 __t2duR83) (join lambda (1 2 0) 2 __tconst0vRf84 __t2duR83 __t87vL85) (join ref (1 0) 1 __tconst4Zcr91 __t0C9F87) (join app (2 0 1) 2 __t0C9F87 __t2Eqd90 __t3Q2G89) (join ref (0 1) 2 __t3Q2G89 __tconst9zoW125) (join ref (1 0) 1 __tconst4V4L122 __t7aew98) (exists app (1 2 0) 1 __t7aew98) (join ref (1 0) 1 __tconst4BKz104 __t8C0a94) (join lambda (1 2 0) 2 __tconst4BKz104 __t8C0a94 __t4fDK96) (join app (1 2 0) 2 __t7aew98 __t4fDK96 __t7TEO99) (join app (2 0 1) 2 __t7TEO99 __t1GdP121 __t3SEs120) (join lambda (0 1 2) 2 __t3SEs120 __tconst82U8119 __t50Kk118) (join ref (1 0) 1 __tconst3wDH116 __t3wir114) (exists app (1 2 0) 1 __t3wir114) (join ref (1 0) 1 __tconst5nWJ102 __t5MaG101) (join lambda (1 2 0) 2 __tconst5nWJ102 __t5MaG101 __t35jA103) (join lambda (1 2 0) 2 __tconst4BKz104 __t35jA103 __t6RuY105) (join app (1 2 0) 2 __t7aew98 __t6RuY105 __t2Z7m108) (join app (2 0 1) 2 __t2Z7m108 __t50Kk118 __t7CwH117) (join lambda (0 1 2) 2 __t7CwH117 __tconst3wDH116 __t44OM115) (join app (0 1 2) 2 __t44OM115 __t3wir114 __t8GWA112) (join lambda (0 1 2) 2 __t8GWA112 __tconst3ktF111 __t7ohz110) (join ref (0 1) 2 __t7ohz110 __tconst3ktF111)) (head (mkstruct lambda (1 2 0) __t4GT8126 __tconst9zoW125 __t3cyj124)) mcfa-counting.slog:241 #f)
  class ReadTask1642 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lambdaindex1602;  slog::Index** refindex1603;  slog::Index** lambdaindex1604;  slog::Index** refindex1605;  slog::Index** refindex1606;  slog::Index** refindex1607;  slog::Index** refindex1608;  slog::Index** lambdaindex1609;  slog::Index** lambdaindex1610;  slog::Index** refindex1611;  slog::Index** refindex1612;  slog::Index** lambdaindex1613;  slog::Index** lambdaindex1614;  slog::Index** lambdaindex1615;  slog::Index** refindex1616;  slog::Index** lambdaindex1617;  slog::Index** lambdaindex1618;  slog::Index** refindex1619;  slog::Index** lambdaindex1620;  slog::Index** refindex1621;  slog::Index** appindex1622;  slog::Index** refindex1623;  slog::Index** refindex1624;  slog::Index** appindex1625;  slog::Index** refindex1626;  slog::Index** lambdaindex1627;  slog::Index** appindex1628;  slog::Index** appindex1629;  slog::Index** lambdaindex1630;  slog::Index** refindex1631;  slog::Index** appindex1632;  slog::Index** refindex1633;  slog::Index** lambdaindex1634;  slog::Index** lambdaindex1635;  slog::Index** appindex1636;  slog::Index** appindex1637;  slog::Index** lambdaindex1638;  slog::Index** appindex1639;  slog::Index** lambdaindex1640;  slog::Index** refindex1641;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      outer_rel = db->getRelation("app");
      std::vector<u16> ord1643({0, 1, 2});
      slog::Relation* readrel1644 = db->getRelation("lambda");
      lambdaindex1602 = readrel1644->getIndex(ord1643, false);
      std::vector<u16> ord1645({1, 0});
      slog::Relation* readrel1646 = db->getRelation("ref");
      refindex1603 = readrel1646->getIndex(ord1645, false);
      std::vector<u16> ord1647({1, 2, 0});
      slog::Relation* readrel1648 = db->getRelation("lambda");
      lambdaindex1604 = readrel1648->getIndex(ord1647, false);
      std::vector<u16> ord1649({1, 0});
      slog::Relation* readrel1650 = db->getRelation("ref");
      refindex1605 = readrel1650->getIndex(ord1649, false);
      std::vector<u16> ord1651({1, 0});
      slog::Relation* readrel1652 = db->getRelation("ref");
      refindex1606 = readrel1652->getIndex(ord1651, false);
      std::vector<u16> ord1653({1, 0});
      slog::Relation* readrel1654 = db->getRelation("ref");
      refindex1607 = readrel1654->getIndex(ord1653, false);
      std::vector<u16> ord1655({1, 0});
      slog::Relation* readrel1656 = db->getRelation("ref");
      refindex1608 = readrel1656->getIndex(ord1655, false);
      std::vector<u16> ord1657({1, 2, 0});
      slog::Relation* readrel1658 = db->getRelation("lambda");
      lambdaindex1609 = readrel1658->getIndex(ord1657, false);
      std::vector<u16> ord1659({1, 2, 0});
      slog::Relation* readrel1660 = db->getRelation("lambda");
      lambdaindex1610 = readrel1660->getIndex(ord1659, false);
      std::vector<u16> ord1661({1, 0});
      slog::Relation* readrel1662 = db->getRelation("ref");
      refindex1611 = readrel1662->getIndex(ord1661, false);
      std::vector<u16> ord1663({1, 0});
      slog::Relation* readrel1664 = db->getRelation("ref");
      refindex1612 = readrel1664->getIndex(ord1663, false);
      std::vector<u16> ord1665({1, 2, 0});
      slog::Relation* readrel1666 = db->getRelation("lambda");
      lambdaindex1613 = readrel1666->getIndex(ord1665, false);
      std::vector<u16> ord1667({1, 2, 0});
      slog::Relation* readrel1668 = db->getRelation("lambda");
      lambdaindex1614 = readrel1668->getIndex(ord1667, false);
      std::vector<u16> ord1669({1, 2, 0});
      slog::Relation* readrel1670 = db->getRelation("lambda");
      lambdaindex1615 = readrel1670->getIndex(ord1669, false);
      std::vector<u16> ord1671({1, 0});
      slog::Relation* readrel1672 = db->getRelation("ref");
      refindex1616 = readrel1672->getIndex(ord1671, false);
      std::vector<u16> ord1673({0, 1, 2});
      slog::Relation* readrel1674 = db->getRelation("lambda");
      lambdaindex1617 = readrel1674->getIndex(ord1673, false);
      std::vector<u16> ord1675({0, 1, 2});
      slog::Relation* readrel1676 = db->getRelation("lambda");
      lambdaindex1618 = readrel1676->getIndex(ord1675, false);
      std::vector<u16> ord1677({1, 0});
      slog::Relation* readrel1678 = db->getRelation("ref");
      refindex1619 = readrel1678->getIndex(ord1677, false);
      std::vector<u16> ord1679({1, 2, 0});
      slog::Relation* readrel1680 = db->getRelation("lambda");
      lambdaindex1620 = readrel1680->getIndex(ord1679, false);
      std::vector<u16> ord1681({1, 0});
      slog::Relation* readrel1682 = db->getRelation("ref");
      refindex1621 = readrel1682->getIndex(ord1681, false);
      std::vector<u16> ord1683({2, 0, 1});
      slog::Relation* readrel1684 = db->getRelation("app");
      appindex1622 = readrel1684->getIndex(ord1683, false);
      std::vector<u16> ord1685({0, 1});
      slog::Relation* readrel1686 = db->getRelation("ref");
      refindex1623 = readrel1686->getIndex(ord1685, false);
      std::vector<u16> ord1687({1, 0});
      slog::Relation* readrel1688 = db->getRelation("ref");
      refindex1624 = readrel1688->getIndex(ord1687, false);
      std::vector<u16> ord1689({1, 2, 0});
      slog::Relation* readrel1690 = db->getRelation("app");
      appindex1625 = readrel1690->getIndex(ord1689, false);
      std::vector<u16> ord1691({1, 0});
      slog::Relation* readrel1692 = db->getRelation("ref");
      refindex1626 = readrel1692->getIndex(ord1691, false);
      std::vector<u16> ord1693({1, 2, 0});
      slog::Relation* readrel1694 = db->getRelation("lambda");
      lambdaindex1627 = readrel1694->getIndex(ord1693, false);
      std::vector<u16> ord1695({1, 2, 0});
      slog::Relation* readrel1696 = db->getRelation("app");
      appindex1628 = readrel1696->getIndex(ord1695, false);
      std::vector<u16> ord1697({2, 0, 1});
      slog::Relation* readrel1698 = db->getRelation("app");
      appindex1629 = readrel1698->getIndex(ord1697, false);
      std::vector<u16> ord1699({0, 1, 2});
      slog::Relation* readrel1700 = db->getRelation("lambda");
      lambdaindex1630 = readrel1700->getIndex(ord1699, false);
      std::vector<u16> ord1701({1, 0});
      slog::Relation* readrel1702 = db->getRelation("ref");
      refindex1631 = readrel1702->getIndex(ord1701, false);
      std::vector<u16> ord1703({1, 2, 0});
      slog::Relation* readrel1704 = db->getRelation("app");
      appindex1632 = readrel1704->getIndex(ord1703, false);
      std::vector<u16> ord1705({1, 0});
      slog::Relation* readrel1706 = db->getRelation("ref");
      refindex1633 = readrel1706->getIndex(ord1705, false);
      std::vector<u16> ord1707({1, 2, 0});
      slog::Relation* readrel1708 = db->getRelation("lambda");
      lambdaindex1634 = readrel1708->getIndex(ord1707, false);
      std::vector<u16> ord1709({1, 2, 0});
      slog::Relation* readrel1710 = db->getRelation("lambda");
      lambdaindex1635 = readrel1710->getIndex(ord1709, false);
      std::vector<u16> ord1711({1, 2, 0});
      slog::Relation* readrel1712 = db->getRelation("app");
      appindex1636 = readrel1712->getIndex(ord1711, false);
      std::vector<u16> ord1713({2, 0, 1});
      slog::Relation* readrel1714 = db->getRelation("app");
      appindex1637 = readrel1714->getIndex(ord1713, false);
      std::vector<u16> ord1715({0, 1, 2});
      slog::Relation* readrel1716 = db->getRelation("lambda");
      lambdaindex1638 = readrel1716->getIndex(ord1715, false);
      std::vector<u16> ord1717({0, 1, 2});
      slog::Relation* readrel1718 = db->getRelation("app");
      appindex1639 = readrel1718->getIndex(ord1717, false);
      std::vector<u16> ord1719({0, 1, 2});
      slog::Relation* readrel1720 = db->getRelation("lambda");
      lambdaindex1640 = readrel1720->getIndex(ord1719, false);
      std::vector<u16> ord1721({0, 1});
      slog::Relation* readrel1722 = db->getRelation("ref");
      refindex1641 = readrel1722->getIndex(ord1721, false);
  
    }
    ReadTask1642(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c93 = v_const7c7d2cfc66f4d976987d2d20;
      u64 v_c94 = v_const6bc0ba365ada70df115e1785;
      u64 v_c96 = v_const9a67f28c6b77e842f439a84a;
      u64 v_c97 = v_conste58dec6bca6f63ef79c3b755;
      u64 v_c95 = v_consta8180db1c2f300980314f910;
      u64 v_c98 = v_const0f8748be649f8ee4066bb1d7;
      u64 v_c99 = v_constd5f017533ea574d5f9b3400c;
      u64 v_c100 = v_const990b444cbd47632035b2fa1a;
      u64 v_c101 = v_const4f84f41d89b6b717419b4eaa;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c174 = _t[0];
        u64 v_c173 = _t[1];
        u64 v_c114 = _t[2];
        if (!slog::exists_probe<3,2>(lambdaindex1602, std::array<u64,3>{v_c173, v_c94, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1603, std::array<u64,2>{v_c97, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1604, std::array<u64,3>{v_c97, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1605, std::array<u64,2>{v_c96, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1606, std::array<u64,2>{v_c93, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1607, std::array<u64,2>{v_c94, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1608, std::array<u64,2>{v_c98, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1609, std::array<u64,3>{v_c98, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1610, std::array<u64,3>{v_c95, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1611, std::array<u64,2>{v_c99, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1612, std::array<u64,2>{v_c101, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1613, std::array<u64,3>{v_c101, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1614, std::array<u64,3>{v_c99, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1615, std::array<u64,3>{v_c100, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1616, std::array<u64,2>{v_c100, 0})) return;
        slog::join_probe<3,2>(lambdaindex1617, std::array<u64,3>{v_c114, v_c96, 0}, [&](const std::array<u64,3>& m1723) {
          u64 v_c113 = m1723[2];
          slog::join_probe<3,2>(lambdaindex1618, std::array<u64,3>{v_c173, v_c94, 0}, [&](const std::array<u64,3>& m1724) {
            u64 v_c102 = m1724[2];
            slog::join_probe<2,1>(refindex1619, std::array<u64,2>{v_c97, 0}, [&](const std::array<u64,2>& m1725) {
              u64 v_c109 = m1725[1];
              slog::join_probe<3,2>(lambdaindex1620, std::array<u64,3>{v_c97, v_c109, 0}, [&](const std::array<u64,3>& m1726) {
                u64 v_c110 = m1726[2];
                slog::join_probe<2,1>(refindex1621, std::array<u64,2>{v_c96, 0}, [&](const std::array<u64,2>& m1727) {
                  u64 v_c111 = m1727[1];
                  slog::join_probe<3,2>(appindex1622, std::array<u64,3>{v_c111, v_c113, 0}, [&](const std::array<u64,3>& m1728) {
                    u64 v_c112 = m1728[2];
                    slog::join_probe<2,2>(refindex1623, std::array<u64,2>{v_c112, v_c93}, [&](const std::array<u64,2>& m1729) {
                      slog::join_probe<2,1>(refindex1624, std::array<u64,2>{v_c94, 0}, [&](const std::array<u64,2>& m1730) {
                        u64 v_c106 = m1730[1];
                        if (!slog::exists_probe<3,1>(appindex1625, std::array<u64,3>{v_c106, 0, 0})) return;
                        slog::join_probe<2,1>(refindex1626, std::array<u64,2>{v_c98, 0}, [&](const std::array<u64,2>& m1731) {
                          u64 v_c108 = m1731[1];
                          slog::join_probe<3,2>(lambdaindex1627, std::array<u64,3>{v_c98, v_c108, 0}, [&](const std::array<u64,3>& m1732) {
                            u64 v_c107 = m1732[2];
                            slog::join_probe<3,2>(appindex1628, std::array<u64,3>{v_c106, v_c107, 0}, [&](const std::array<u64,3>& m1733) {
                              u64 v_c104 = m1733[2];
                              slog::join_probe<3,2>(appindex1629, std::array<u64,3>{v_c104, v_c102, 0}, [&](const std::array<u64,3>& m1734) {
                                u64 v_c103 = m1734[2];
                                slog::join_probe<3,2>(lambdaindex1630, std::array<u64,3>{v_c103, v_c95, 0}, [&](const std::array<u64,3>& m1735) {
                                  u64 v_c105 = m1735[2];
                                  slog::join_probe<2,1>(refindex1631, std::array<u64,2>{v_c99, 0}, [&](const std::array<u64,2>& m1736) {
                                    u64 v_c115 = m1736[1];
                                    if (!slog::exists_probe<3,1>(appindex1632, std::array<u64,3>{v_c115, 0, 0})) return;
                                    slog::join_probe<2,1>(refindex1633, std::array<u64,2>{v_c101, 0}, [&](const std::array<u64,2>& m1737) {
                                      u64 v_c116 = m1737[1];
                                      slog::join_probe<3,2>(lambdaindex1634, std::array<u64,3>{v_c101, v_c116, 0}, [&](const std::array<u64,3>& m1738) {
                                        u64 v_c117 = m1738[2];
                                        slog::join_probe<3,2>(lambdaindex1635, std::array<u64,3>{v_c98, v_c117, 0}, [&](const std::array<u64,3>& m1739) {
                                          u64 v_c118 = m1739[2];
                                          slog::join_probe<3,2>(appindex1636, std::array<u64,3>{v_c106, v_c118, 0}, [&](const std::array<u64,3>& m1740) {
                                            u64 v_c119 = m1740[2];
                                            slog::join_probe<3,2>(appindex1637, std::array<u64,3>{v_c119, v_c105, 0}, [&](const std::array<u64,3>& m1741) {
                                              u64 v_c120 = m1741[2];
                                              slog::join_probe<3,2>(lambdaindex1638, std::array<u64,3>{v_c120, v_c99, 0}, [&](const std::array<u64,3>& m1742) {
                                                u64 v_c121 = m1742[2];
                                                slog::join_probe<3,2>(appindex1639, std::array<u64,3>{v_c121, v_c115, 0}, [&](const std::array<u64,3>& m1743) {
                                                  u64 v_c122 = m1743[2];
                                                  slog::join_probe<3,2>(lambdaindex1640, std::array<u64,3>{v_c122, v_c100, 0}, [&](const std::array<u64,3>& m1744) {
                                                    u64 v_c123 = m1744[2];
                                                    slog::join_probe<2,2>(refindex1641, std::array<u64,2>{v_c123, v_c100}, [&](const std::array<u64,2>& m1745) {
                                                      ++_fires;
                                                      slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c93, v_c174}, std::array<u16,3>{1, 2, 0});
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
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:241", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask1642* _cont = new ReadTask1642(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1642(db,b), false);
  // (crule (pre (let __tconst7JVW192 const6cf13cc59dcbe759113f68a4) (let __tconst7B9N190 constcaa3ee5a2828a31924f6b39d) (let __tconst5wC2180 const970c20ea81b833e5b5a7accf) (let __tconst2ady176 constc40f204dda7ba4054abb9e74)) (seeded) (body (join ref (1 0) 1 __tconst2ady176 __t3ZY4175) (exists ref (1 0) 1 __tconst5wC2180) (exists lambda (1 2 0) 1 __tconst5wC2180) (exists ref (1 0) 1 __tconst7B9N190) (exists ref (1 0) 1 __tconst7JVW192) (join lambda (1 2 0) 2 __tconst2ady176 __t3ZY4175 __t1Ls4177) (join ref (1 0) 1 __tconst5wC2180 __t52sB179) (join lambda (1 2 0) 2 __tconst5wC2180 __t52sB179 __t6CST181) (join ref (1 0) 1 __tconst7B9N190 __t8oRJ183) (exists app (2 0 1) 1 __t8oRJ183) (join ref (1 0) 1 __tconst7JVW192 __t6fOY185) (join app (1 2 0) 2 __t6fOY185 __t8oRJ183 __t2CTd186)) (head (mkstruct app (1 2 0) __t9pbS189 __t6fOY185 __t2CTd186)) mcfa-counting.slog:301 #f)
  class ReadTask1758 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex1746;  slog::Index** refindex1747;  slog::Index** lambdaindex1748;  slog::Index** refindex1749;  slog::Index** refindex1750;  slog::Index** lambdaindex1751;  slog::Index** refindex1752;  slog::Index** lambdaindex1753;  slog::Index** refindex1754;  slog::Index** appindex1755;  slog::Index** refindex1756;  slog::Index** appindex1757;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord1759({1, 2, 0});
      slog::Relation* readrel1760 = db->getRelation("app");
      head_index[0] = readrel1760->getIndex(ord1759, false);
      std::vector<u16> ord1761({1, 0});
      slog::Relation* readrel1762 = db->getRelation("ref");
      refindex1746 = readrel1762->getIndex(ord1761, false);
      std::vector<u16> ord1763({1, 0});
      slog::Relation* readrel1764 = db->getRelation("ref");
      refindex1747 = readrel1764->getIndex(ord1763, false);
      std::vector<u16> ord1765({1, 2, 0});
      slog::Relation* readrel1766 = db->getRelation("lambda");
      lambdaindex1748 = readrel1766->getIndex(ord1765, false);
      std::vector<u16> ord1767({1, 0});
      slog::Relation* readrel1768 = db->getRelation("ref");
      refindex1749 = readrel1768->getIndex(ord1767, false);
      std::vector<u16> ord1769({1, 0});
      slog::Relation* readrel1770 = db->getRelation("ref");
      refindex1750 = readrel1770->getIndex(ord1769, false);
      std::vector<u16> ord1771({1, 2, 0});
      slog::Relation* readrel1772 = db->getRelation("lambda");
      lambdaindex1751 = readrel1772->getIndex(ord1771, false);
      std::vector<u16> ord1773({1, 0});
      slog::Relation* readrel1774 = db->getRelation("ref");
      refindex1752 = readrel1774->getIndex(ord1773, false);
      std::vector<u16> ord1775({1, 2, 0});
      slog::Relation* readrel1776 = db->getRelation("lambda");
      lambdaindex1753 = readrel1776->getIndex(ord1775, false);
      std::vector<u16> ord1777({1, 0});
      slog::Relation* readrel1778 = db->getRelation("ref");
      refindex1754 = readrel1778->getIndex(ord1777, false);
      std::vector<u16> ord1779({2, 0, 1});
      slog::Relation* readrel1780 = db->getRelation("app");
      appindex1755 = readrel1780->getIndex(ord1779, false);
      std::vector<u16> ord1781({1, 0});
      slog::Relation* readrel1782 = db->getRelation("ref");
      refindex1756 = readrel1782->getIndex(ord1781, false);
      std::vector<u16> ord1783({1, 2, 0});
      slog::Relation* readrel1784 = db->getRelation("app");
      appindex1757 = readrel1784->getIndex(ord1783, false);
  
    }
    ReadTask1758(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c30 = v_const6cf13cc59dcbe759113f68a4;
      u64 v_c33 = v_constcaa3ee5a2828a31924f6b39d;
      u64 v_c31 = v_const970c20ea81b833e5b5a7accf;
      u64 v_c32 = v_constc40f204dda7ba4054abb9e74;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex1746, std::array<u64,2>{v_c32, 0}, [&](const std::array<u64,2>& m1785) {
        u64 v_c34 = m1785[1];
        if (!slog::exists_probe<2,1>(refindex1747, std::array<u64,2>{v_c31, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1748, std::array<u64,3>{v_c31, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1749, std::array<u64,2>{v_c33, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1750, std::array<u64,2>{v_c30, 0})) return;
        slog::join_probe<3,2>(lambdaindex1751, std::array<u64,3>{v_c32, v_c34, 0}, [&](const std::array<u64,3>& m1786) {
          u64 v_c35 = m1786[2];
          slog::join_probe<2,1>(refindex1752, std::array<u64,2>{v_c31, 0}, [&](const std::array<u64,2>& m1787) {
            u64 v_c36 = m1787[1];
            slog::join_probe<3,2>(lambdaindex1753, std::array<u64,3>{v_c31, v_c36, 0}, [&](const std::array<u64,3>& m1788) {
              u64 v_c37 = m1788[2];
              slog::join_probe<2,1>(refindex1754, std::array<u64,2>{v_c33, 0}, [&](const std::array<u64,2>& m1789) {
                u64 v_c39 = m1789[1];
                if (!slog::exists_probe<3,1>(appindex1755, std::array<u64,3>{v_c39, 0, 0})) return;
                slog::join_probe<2,1>(refindex1756, std::array<u64,2>{v_c30, 0}, [&](const std::array<u64,2>& m1790) {
                  u64 v_c38 = m1790[1];
                  slog::join_probe<3,2>(appindex1757, std::array<u64,3>{v_c38, v_c39, 0}, [&](const std::array<u64,3>& m1791) {
                    u64 v_c40 = m1791[2];
                    ++_fires;
                    slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c38, v_c40}, std::array<u16,3>{1, 2, 0});
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
      s->addTaskSeeded(phase_read, new ReadTask1758(db,b));
  // (crule (pre) (scan store y cb vy) (body (exists clo (2 0 1) 1 cb) (join freevar (0 1) 1 y __t4JNf263) (join-old clo (1 2 0) 2 (1 2 0) __t4JNf263 cb __t0zen261) (join eval_ans (1 0) 1 __t0zen261 __t7ceq259) (join-old eval (0 2 1) 1 (0 2 1) __t7ceq259 c ef) (exists app (1 2 0) 1 ef) (exists eval (2 0 1) 1 c) (join eval (2 0 1) 1 c __5DEq344 __t6ooL258) (join-old app (0 1 2) 2 (0 1 2) __t6ooL258 ef ea) (join-old eval (1 2 0) 2 (1 2 0) ea c __t2S0s262) (join eval_ans (0 1) 1 __t2S0s262 va) (join-old lambda (0 1 2) 1 (0 1 2) __t4JNf263 x eb)) (head (emit store (0 1 2) y __t6ooL258 vy) (emit bindev (0 1 2) y __t6ooL258 c)) mcfa-counting.slog:102 #f)
  class ReadTask1809 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** cloindex1792;  slog::Index** freevarindex1793;  slog::Index** cloindex1794;  slog::Index** eval_ansindex1795;  slog::Index** evalindex1796;  slog::Index** appindex1797;  slog::Index** evalindex1798;  slog::Index** evalindex1799;  slog::Index** appindex1800;  slog::Index** evalindex1801;  slog::Index** eval_ansindex1802;  slog::Index** lambdaindex1803;  slog::Index** clodelta1804;  slog::Index** evaldelta1805;  slog::Index** appdelta1806;  slog::Index** evaldelta1807;  slog::Index** lambdadelta1808;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("store");
      std::vector<u16> ord1810({0, 1, 2});
      slog::Relation* readrel1811 = db->getRelation("store");
      head_index[0] = readrel1811->getIndex(ord1810, false);
      head_rel[1] = db->getRelation("bindev");
      std::vector<u16> ord1812({0, 1, 2});
      slog::Relation* readrel1813 = db->getRelation("bindev");
      head_index[1] = readrel1813->getIndex(ord1812, false);
      outer_rel = db->getRelation("store");
      std::vector<u16> ord1814({2, 0, 1});
      slog::Relation* readrel1815 = db->getRelation("clo");
      cloindex1792 = readrel1815->getIndex(ord1814, false);
      std::vector<u16> ord1816({0, 1});
      slog::Relation* readrel1817 = db->getRelation("freevar");
      freevarindex1793 = readrel1817->getIndex(ord1816, false);
      std::vector<u16> ord1818({1, 2, 0});
      slog::Relation* readrel1819 = db->getRelation("clo");
      cloindex1794 = readrel1819->getIndex(ord1818, false);
      std::vector<u16> ord1820({1, 2, 0});
      slog::Relation* readrel1821 = db->getRelation("clo");
      clodelta1804 = readrel1821->getIndex(ord1820, true);
      std::vector<u16> ord1822({1, 0});
      slog::Relation* readrel1823 = db->getRelation("eval_ans");
      eval_ansindex1795 = readrel1823->getIndex(ord1822, false);
      std::vector<u16> ord1824({0, 2, 1});
      slog::Relation* readrel1825 = db->getRelation("eval");
      evalindex1796 = readrel1825->getIndex(ord1824, false);
      std::vector<u16> ord1826({0, 2, 1});
      slog::Relation* readrel1827 = db->getRelation("eval");
      evaldelta1805 = readrel1827->getIndex(ord1826, true);
      std::vector<u16> ord1828({1, 2, 0});
      slog::Relation* readrel1829 = db->getRelation("app");
      appindex1797 = readrel1829->getIndex(ord1828, false);
      std::vector<u16> ord1830({2, 0, 1});
      slog::Relation* readrel1831 = db->getRelation("eval");
      evalindex1798 = readrel1831->getIndex(ord1830, false);
      std::vector<u16> ord1832({2, 0, 1});
      slog::Relation* readrel1833 = db->getRelation("eval");
      evalindex1799 = readrel1833->getIndex(ord1832, false);
      std::vector<u16> ord1834({0, 1, 2});
      slog::Relation* readrel1835 = db->getRelation("app");
      appindex1800 = readrel1835->getIndex(ord1834, false);
      std::vector<u16> ord1836({0, 1, 2});
      slog::Relation* readrel1837 = db->getRelation("app");
      appdelta1806 = readrel1837->getIndex(ord1836, true);
      std::vector<u16> ord1838({1, 2, 0});
      slog::Relation* readrel1839 = db->getRelation("eval");
      evalindex1801 = readrel1839->getIndex(ord1838, false);
      std::vector<u16> ord1840({1, 2, 0});
      slog::Relation* readrel1841 = db->getRelation("eval");
      evaldelta1807 = readrel1841->getIndex(ord1840, true);
      std::vector<u16> ord1842({0, 1});
      slog::Relation* readrel1843 = db->getRelation("eval_ans");
      eval_ansindex1802 = readrel1843->getIndex(ord1842, false);
      std::vector<u16> ord1844({0, 1, 2});
      slog::Relation* readrel1845 = db->getRelation("lambda");
      lambdaindex1803 = readrel1845->getIndex(ord1844, false);
      std::vector<u16> ord1846({0, 1, 2});
      slog::Relation* readrel1847 = db->getRelation("lambda");
      lambdadelta1808 = readrel1847->getIndex(ord1846, true);
  
    }
    ReadTask1809(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c71 = _t[0];
        u64 v_c27 = _t[1];
        u64 v_c177 = _t[2];
        if (!slog::exists_probe<3,1>(cloindex1792, std::array<u64,3>{v_c27, 0, 0})) return;
        slog::join_probe<2,1>(freevarindex1793, std::array<u64,2>{v_c71, 0}, [&](const std::array<u64,2>& m1848) {
          u64 v_c178 = m1848[1];
          slog::join_probe_old<3,2>(cloindex1794, clodelta1804, std::array<u64,3>{v_c178, v_c27, 0}, [&](const std::array<u64,3>& m1849) {
            u64 v_c179 = m1849[2];
            slog::join_probe<2,1>(eval_ansindex1795, std::array<u64,2>{v_c179, 0}, [&](const std::array<u64,2>& m1850) {
              u64 v_c180 = m1850[1];
              slog::join_probe_old<3,1>(evalindex1796, evaldelta1805, std::array<u64,3>{v_c180, 0, 0}, [&](const std::array<u64,3>& m1851) {
                u64 v_c21 = m1851[1]; u64 v_c3 = m1851[2];
                if (!slog::exists_probe<3,1>(appindex1797, std::array<u64,3>{v_c3, 0, 0})) return;
                if (!slog::exists_probe<3,1>(evalindex1798, std::array<u64,3>{v_c21, 0, 0})) return;
                slog::join_probe<3,1>(evalindex1799, std::array<u64,3>{v_c21, 0, 0}, [&](const std::array<u64,3>& m1852) {
                  u64 v_c181 = m1852[1]; u64 v_c182 = m1852[2];
                  slog::join_probe_old<3,2>(appindex1800, appdelta1806, std::array<u64,3>{v_c182, v_c3, 0}, [&](const std::array<u64,3>& m1853) {
                    u64 v_c1 = m1853[2];
                    slog::join_probe_old<3,2>(evalindex1801, evaldelta1807, std::array<u64,3>{v_c1, v_c21, 0}, [&](const std::array<u64,3>& m1854) {
                      u64 v_c183 = m1854[2];
                      slog::join_probe<2,1>(eval_ansindex1802, std::array<u64,2>{v_c183, 0}, [&](const std::array<u64,2>& m1855) {
                        u64 v_c26 = m1855[1];
                        slog::join_probe_old<3,1>(lambdaindex1803, lambdadelta1808, std::array<u64,3>{v_c178, 0, 0}, [&](const std::array<u64,3>& m1856) {
                          u64 v_c0 = m1856[1]; u64 v_c29 = m1856[2];
                          ++_fires;
                          slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c71, v_c182, v_c177}, std::array<u16,3>{0, 1, 2});
                          slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c71, v_c182, v_c21}, std::array<u16,3>{0, 1, 2});
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
  
      if (_fires) db->bumpFires("mcfa-counting.slog:102", "delta:store", _fires);
  
      if (!_done)
      {
        ReadTask1809* _cont = new ReadTask1809(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1809(db,b), false);
  // (crule (pre) (scan app __t5bzC44 ef ea) (body (join eval (1 2 0) 1 __t5bzC44 c __5K9i345)) (head (mkstruct eval (1 2 0) __4C0T346 ea c)) mcfa-counting.slog:92 #f)
  class ReadTask1858 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1857;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("app");
      std::vector<u16> ord1859({1, 2, 0});
      slog::Relation* readrel1860 = db->getRelation("eval");
      evalindex1857 = readrel1860->getIndex(ord1859, false);
  
    }
    ReadTask1858(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c3 = _t[1];
        u64 v_c1 = _t[2];
        slog::join_probe<3,1>(evalindex1857, std::array<u64,3>{v_c184, 0, 0}, [&](const std::array<u64,3>& m1861) {
          u64 v_c21 = m1861[1]; u64 v_c185 = m1861[2];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c1, v_c21}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:92", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask1858* _cont = new ReadTask1858(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1858(db,b), false);
  // (crule (pre (let __tconst7sqz226 const7b8fd91ee9ff10cfbb8066bf) (let __tconst1EUj230 const615ad01b1c532bb6634df115) (let __tconst4N2q248 constaaaad65142343c54348db5d0) (let __tconst2VuQ234 const4492fd5fa4baacfebd29f5e5) (let __tconst4Sko246 consteb793a6f75d6cfe49d3c2c90) (let __tconst2x2f244 consta32d5a443def48e6d64c6f4b)) (scan app __t7iVu252 __t9bBp251 __t2BAX227) (body (exists ref (1 0) 1 __tconst7sqz226) (exists ref (1 0) 1 __tconst1EUj230) (exists lambda (1 2 0) 1 __tconst1EUj230) (exists ref (1 0) 1 __tconst2VuQ234) (exists lambda (1 2 0) 1 __tconst2VuQ234) (exists lambda (1 2 0) 1 __tconst4N2q248) (exists lambda (1 2 0) 1 __tconst4Sko246) (exists lambda (1 2 0) 1 __tconst2x2f244) (exists ref (1 0) 1 __tconst2x2f244) (exists ref (1 0) 1 __tconst4N2q248) (exists ref (1 0) 1 __tconst4Sko246) (join lambda (0 1 2) 2 __t2BAX227 __tconst7sqz226 __t5APF225) (join ref (0 1) 2 __t5APF225 __tconst7sqz226) (join ref (1 0) 1 __tconst1EUj230 __t3WVP229) (join lambda (1 2 0) 2 __tconst1EUj230 __t3WVP229 __t5ryk231) (join app (2 0 1) 2 __t5ryk231 __t9bBp251 __t5pZU250) (join ref (1 0) 1 __tconst2VuQ234 __t2PLq233) (join lambda (1 2 0) 2 __tconst2VuQ234 __t2PLq233 __t45rU235) (join app (2 0 1) 2 __t45rU235 __t5pZU250 __t5uyC249) (join lambda (0 1 2) 2 __t5uyC249 __tconst4N2q248 __t7yz1247) (join lambda (0 1 2) 2 __t7yz1247 __tconst4Sko246 __t3laZ245) (join lambda (0 1 2) 2 __t3laZ245 __tconst2x2f244 __t5h6K243) (join ref (1 0) 1 __tconst2x2f244 __t3pbc237) (join app (2 0 1) 2 __t3pbc237 __t5h6K243 __t4wvK242) (join ref (1 0) 1 __tconst4N2q248 __t6KL4241) (join app (0 1 2) 2 __t4wvK242 __t6KL4241 __t16jv239) (join ref (0 1) 2 __t16jv239 __tconst4Sko246)) (head (emit program (0) __t7iVu252)) mcfa-counting.slog:272 #f)
  class ReadTask1889 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex1862;  slog::Index** refindex1863;  slog::Index** lambdaindex1864;  slog::Index** refindex1865;  slog::Index** lambdaindex1866;  slog::Index** lambdaindex1867;  slog::Index** lambdaindex1868;  slog::Index** lambdaindex1869;  slog::Index** refindex1870;  slog::Index** refindex1871;  slog::Index** refindex1872;  slog::Index** lambdaindex1873;  slog::Index** refindex1874;  slog::Index** refindex1875;  slog::Index** lambdaindex1876;  slog::Index** appindex1877;  slog::Index** refindex1878;  slog::Index** lambdaindex1879;  slog::Index** appindex1880;  slog::Index** lambdaindex1881;  slog::Index** lambdaindex1882;  slog::Index** lambdaindex1883;  slog::Index** refindex1884;  slog::Index** appindex1885;  slog::Index** refindex1886;  slog::Index** appindex1887;  slog::Index** refindex1888;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("program");
      std::vector<u16> ord1890({0});
      slog::Relation* readrel1891 = db->getRelation("program");
      head_index[0] = readrel1891->getIndex(ord1890, false);
      outer_rel = db->getRelation("app");
      std::vector<u16> ord1892({1, 0});
      slog::Relation* readrel1893 = db->getRelation("ref");
      refindex1862 = readrel1893->getIndex(ord1892, false);
      std::vector<u16> ord1894({1, 0});
      slog::Relation* readrel1895 = db->getRelation("ref");
      refindex1863 = readrel1895->getIndex(ord1894, false);
      std::vector<u16> ord1896({1, 2, 0});
      slog::Relation* readrel1897 = db->getRelation("lambda");
      lambdaindex1864 = readrel1897->getIndex(ord1896, false);
      std::vector<u16> ord1898({1, 0});
      slog::Relation* readrel1899 = db->getRelation("ref");
      refindex1865 = readrel1899->getIndex(ord1898, false);
      std::vector<u16> ord1900({1, 2, 0});
      slog::Relation* readrel1901 = db->getRelation("lambda");
      lambdaindex1866 = readrel1901->getIndex(ord1900, false);
      std::vector<u16> ord1902({1, 2, 0});
      slog::Relation* readrel1903 = db->getRelation("lambda");
      lambdaindex1867 = readrel1903->getIndex(ord1902, false);
      std::vector<u16> ord1904({1, 2, 0});
      slog::Relation* readrel1905 = db->getRelation("lambda");
      lambdaindex1868 = readrel1905->getIndex(ord1904, false);
      std::vector<u16> ord1906({1, 2, 0});
      slog::Relation* readrel1907 = db->getRelation("lambda");
      lambdaindex1869 = readrel1907->getIndex(ord1906, false);
      std::vector<u16> ord1908({1, 0});
      slog::Relation* readrel1909 = db->getRelation("ref");
      refindex1870 = readrel1909->getIndex(ord1908, false);
      std::vector<u16> ord1910({1, 0});
      slog::Relation* readrel1911 = db->getRelation("ref");
      refindex1871 = readrel1911->getIndex(ord1910, false);
      std::vector<u16> ord1912({1, 0});
      slog::Relation* readrel1913 = db->getRelation("ref");
      refindex1872 = readrel1913->getIndex(ord1912, false);
      std::vector<u16> ord1914({0, 1, 2});
      slog::Relation* readrel1915 = db->getRelation("lambda");
      lambdaindex1873 = readrel1915->getIndex(ord1914, false);
      std::vector<u16> ord1916({0, 1});
      slog::Relation* readrel1917 = db->getRelation("ref");
      refindex1874 = readrel1917->getIndex(ord1916, false);
      std::vector<u16> ord1918({1, 0});
      slog::Relation* readrel1919 = db->getRelation("ref");
      refindex1875 = readrel1919->getIndex(ord1918, false);
      std::vector<u16> ord1920({1, 2, 0});
      slog::Relation* readrel1921 = db->getRelation("lambda");
      lambdaindex1876 = readrel1921->getIndex(ord1920, false);
      std::vector<u16> ord1922({2, 0, 1});
      slog::Relation* readrel1923 = db->getRelation("app");
      appindex1877 = readrel1923->getIndex(ord1922, false);
      std::vector<u16> ord1924({1, 0});
      slog::Relation* readrel1925 = db->getRelation("ref");
      refindex1878 = readrel1925->getIndex(ord1924, false);
      std::vector<u16> ord1926({1, 2, 0});
      slog::Relation* readrel1927 = db->getRelation("lambda");
      lambdaindex1879 = readrel1927->getIndex(ord1926, false);
      std::vector<u16> ord1928({2, 0, 1});
      slog::Relation* readrel1929 = db->getRelation("app");
      appindex1880 = readrel1929->getIndex(ord1928, false);
      std::vector<u16> ord1930({0, 1, 2});
      slog::Relation* readrel1931 = db->getRelation("lambda");
      lambdaindex1881 = readrel1931->getIndex(ord1930, false);
      std::vector<u16> ord1932({0, 1, 2});
      slog::Relation* readrel1933 = db->getRelation("lambda");
      lambdaindex1882 = readrel1933->getIndex(ord1932, false);
      std::vector<u16> ord1934({0, 1, 2});
      slog::Relation* readrel1935 = db->getRelation("lambda");
      lambdaindex1883 = readrel1935->getIndex(ord1934, false);
      std::vector<u16> ord1936({1, 0});
      slog::Relation* readrel1937 = db->getRelation("ref");
      refindex1884 = readrel1937->getIndex(ord1936, false);
      std::vector<u16> ord1938({2, 0, 1});
      slog::Relation* readrel1939 = db->getRelation("app");
      appindex1885 = readrel1939->getIndex(ord1938, false);
      std::vector<u16> ord1940({1, 0});
      slog::Relation* readrel1941 = db->getRelation("ref");
      refindex1886 = readrel1941->getIndex(ord1940, false);
      std::vector<u16> ord1942({0, 1, 2});
      slog::Relation* readrel1943 = db->getRelation("app");
      appindex1887 = readrel1943->getIndex(ord1942, false);
      std::vector<u16> ord1944({0, 1});
      slog::Relation* readrel1945 = db->getRelation("ref");
      refindex1888 = readrel1945->getIndex(ord1944, false);
  
    }
    ReadTask1889(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c75 = v_const7b8fd91ee9ff10cfbb8066bf;
      u64 v_c76 = v_const615ad01b1c532bb6634df115;
      u64 v_c73 = v_constaaaad65142343c54348db5d0;
      u64 v_c77 = v_const4492fd5fa4baacfebd29f5e5;
      u64 v_c74 = v_consteb793a6f75d6cfe49d3c2c90;
      u64 v_c78 = v_consta32d5a443def48e6d64c6f4b;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c186 = _t[0];
        u64 v_c187 = _t[1];
        u64 v_c88 = _t[2];
        if (!slog::exists_probe<2,1>(refindex1862, std::array<u64,2>{v_c75, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1863, std::array<u64,2>{v_c76, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1864, std::array<u64,3>{v_c76, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1865, std::array<u64,2>{v_c77, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1866, std::array<u64,3>{v_c77, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1867, std::array<u64,3>{v_c73, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1868, std::array<u64,3>{v_c74, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1869, std::array<u64,3>{v_c78, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1870, std::array<u64,2>{v_c78, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1871, std::array<u64,2>{v_c73, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1872, std::array<u64,2>{v_c74, 0})) return;
        slog::join_probe<3,2>(lambdaindex1873, std::array<u64,3>{v_c88, v_c75, 0}, [&](const std::array<u64,3>& m1946) {
          u64 v_c87 = m1946[2];
          slog::join_probe<2,2>(refindex1874, std::array<u64,2>{v_c87, v_c75}, [&](const std::array<u64,2>& m1947) {
            slog::join_probe<2,1>(refindex1875, std::array<u64,2>{v_c76, 0}, [&](const std::array<u64,2>& m1948) {
              u64 v_c85 = m1948[1];
              slog::join_probe<3,2>(lambdaindex1876, std::array<u64,3>{v_c76, v_c85, 0}, [&](const std::array<u64,3>& m1949) {
                u64 v_c86 = m1949[2];
                slog::join_probe<3,2>(appindex1877, std::array<u64,3>{v_c86, v_c187, 0}, [&](const std::array<u64,3>& m1950) {
                  u64 v_c188 = m1950[2];
                  slog::join_probe<2,1>(refindex1878, std::array<u64,2>{v_c77, 0}, [&](const std::array<u64,2>& m1951) {
                    u64 v_c83 = m1951[1];
                    slog::join_probe<3,2>(lambdaindex1879, std::array<u64,3>{v_c77, v_c83, 0}, [&](const std::array<u64,3>& m1952) {
                      u64 v_c84 = m1952[2];
                      slog::join_probe<3,2>(appindex1880, std::array<u64,3>{v_c84, v_c188, 0}, [&](const std::array<u64,3>& m1953) {
                        u64 v_c80 = m1953[2];
                        slog::join_probe<3,2>(lambdaindex1881, std::array<u64,3>{v_c80, v_c73, 0}, [&](const std::array<u64,3>& m1954) {
                          u64 v_c79 = m1954[2];
                          slog::join_probe<3,2>(lambdaindex1882, std::array<u64,3>{v_c79, v_c74, 0}, [&](const std::array<u64,3>& m1955) {
                            u64 v_c81 = m1955[2];
                            slog::join_probe<3,2>(lambdaindex1883, std::array<u64,3>{v_c81, v_c78, 0}, [&](const std::array<u64,3>& m1956) {
                              u64 v_c82 = m1956[2];
                              slog::join_probe<2,1>(refindex1884, std::array<u64,2>{v_c78, 0}, [&](const std::array<u64,2>& m1957) {
                                u64 v_c89 = m1957[1];
                                slog::join_probe<3,2>(appindex1885, std::array<u64,3>{v_c89, v_c82, 0}, [&](const std::array<u64,3>& m1958) {
                                  u64 v_c90 = m1958[2];
                                  slog::join_probe<2,1>(refindex1886, std::array<u64,2>{v_c73, 0}, [&](const std::array<u64,2>& m1959) {
                                    u64 v_c91 = m1959[1];
                                    slog::join_probe<3,2>(appindex1887, std::array<u64,3>{v_c90, v_c91, 0}, [&](const std::array<u64,3>& m1960) {
                                      u64 v_c92 = m1960[2];
                                      slog::join_probe<2,2>(refindex1888, std::array<u64,2>{v_c92, v_c74}, [&](const std::array<u64,2>& m1961) {
                                        ++_fires;
                                        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c186}, std::array<u16,1>{0});
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
  
      if (_fires) db->bumpFires("mcfa-counting.slog:272", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask1889* _cont = new ReadTask1889(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1889(db,b), false);
  // (crule (pre (let __tconst0y6X73 const0aa6f87434af0222b916e97a) (let __tconst7zoP70 const227d34ceeba7a29aada993d4) (let __tconst0aL952 constd3d07026d47882ceca728218) (let __tconst1bfe65 const59ba3256d223f0d0a00d0633) (let __tconst8wN863 const7cd75b35aa30c3ddf04f9d57) (let __tconst0xUh47 constf700a82e218a86de572e1f7f)) (probe lambda (1 2 0) 1 __tconst7zoP70 __t5Ri569 __t7KAC71) (body (exists lambda (1 2 0) 1 __tconst1bfe65) (exists lambda (1 2 0) 1 __tconst8wN863) (exists ref (1 0) 1 __tconst8wN863) (exists ref (1 0) 1 __tconst0aL952) (exists ref (1 0) 1 __tconst1bfe65) (exists ref (1 0) 1 __tconst0xUh47) (exists lambda (1 2 0) 1 __tconst0xUh47) (exists lambda (1 2 0) 1 __tconst0aL952) (join ref (1 0) 1 __tconst0y6X73 __t0QRr59) (exists app (1 2 0) 1 __t0QRr59) (join app (0 1 2) 2 __t5Ri569 __t0QRr59 __t7JIT66) (join lambda (0 1 2) 2 __t7JIT66 __tconst1bfe65 __t3Dru64) (join lambda (0 1 2) 2 __t3Dru64 __tconst8wN863 __t1mkO62) (join ref (0 1) 2 __t1mkO62 __tconst8wN863) (join ref (1 0) 1 __tconst0aL952 __t5HQ450) (exists app (1 2 0) 1 __t5HQ450) (join ref (1 0) 1 __tconst1bfe65 __t2HsD55) (join lambda (1 2 0) 2 __tconst1bfe65 __t2HsD55 __t0uNb57) (join app (1 2 0) 2 __t0QRr59 __t0uNb57 __t81HE60) (join ref (1 0) 1 __tconst0xUh47 __t5vZb46) (join lambda (1 2 0) 2 __tconst0xUh47 __t5vZb46 __t50zW48) (join app (1 2 0) 2 __t5HQ450 __t50zW48 __t05NY51) (join lambda (1 2 0) 2 __tconst0aL952 __t05NY51 __t3xtz53)) (head (mkstruct app (1 2 0) __t9kFz72 __t7KAC71 __t81HE60)) mcfa-counting.slog:287 #f)
  class ReadTask1985 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** lambdaindex1962;  slog::Index** lambdaindex1963;  slog::Index** refindex1964;  slog::Index** refindex1965;  slog::Index** refindex1966;  slog::Index** refindex1967;  slog::Index** lambdaindex1968;  slog::Index** lambdaindex1969;  slog::Index** refindex1970;  slog::Index** appindex1971;  slog::Index** appindex1972;  slog::Index** lambdaindex1973;  slog::Index** lambdaindex1974;  slog::Index** refindex1975;  slog::Index** refindex1976;  slog::Index** appindex1977;  slog::Index** refindex1978;  slog::Index** lambdaindex1979;  slog::Index** appindex1980;  slog::Index** refindex1981;  slog::Index** lambdaindex1982;  slog::Index** appindex1983;  slog::Index** lambdaindex1984;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord1986({1, 2, 0});
      slog::Relation* readrel1987 = db->getRelation("lambda");
      driver_index = readrel1987->getIndex(ord1986, true);
      std::vector<u16> ord1988({1, 2, 0});
      slog::Relation* readrel1989 = db->getRelation("lambda");
      lambdaindex1962 = readrel1989->getIndex(ord1988, false);
      std::vector<u16> ord1990({1, 2, 0});
      slog::Relation* readrel1991 = db->getRelation("lambda");
      lambdaindex1963 = readrel1991->getIndex(ord1990, false);
      std::vector<u16> ord1992({1, 0});
      slog::Relation* readrel1993 = db->getRelation("ref");
      refindex1964 = readrel1993->getIndex(ord1992, false);
      std::vector<u16> ord1994({1, 0});
      slog::Relation* readrel1995 = db->getRelation("ref");
      refindex1965 = readrel1995->getIndex(ord1994, false);
      std::vector<u16> ord1996({1, 0});
      slog::Relation* readrel1997 = db->getRelation("ref");
      refindex1966 = readrel1997->getIndex(ord1996, false);
      std::vector<u16> ord1998({1, 0});
      slog::Relation* readrel1999 = db->getRelation("ref");
      refindex1967 = readrel1999->getIndex(ord1998, false);
      std::vector<u16> ord2000({1, 2, 0});
      slog::Relation* readrel2001 = db->getRelation("lambda");
      lambdaindex1968 = readrel2001->getIndex(ord2000, false);
      std::vector<u16> ord2002({1, 2, 0});
      slog::Relation* readrel2003 = db->getRelation("lambda");
      lambdaindex1969 = readrel2003->getIndex(ord2002, false);
      std::vector<u16> ord2004({1, 0});
      slog::Relation* readrel2005 = db->getRelation("ref");
      refindex1970 = readrel2005->getIndex(ord2004, false);
      std::vector<u16> ord2006({1, 2, 0});
      slog::Relation* readrel2007 = db->getRelation("app");
      appindex1971 = readrel2007->getIndex(ord2006, false);
      std::vector<u16> ord2008({0, 1, 2});
      slog::Relation* readrel2009 = db->getRelation("app");
      appindex1972 = readrel2009->getIndex(ord2008, false);
      std::vector<u16> ord2010({0, 1, 2});
      slog::Relation* readrel2011 = db->getRelation("lambda");
      lambdaindex1973 = readrel2011->getIndex(ord2010, false);
      std::vector<u16> ord2012({0, 1, 2});
      slog::Relation* readrel2013 = db->getRelation("lambda");
      lambdaindex1974 = readrel2013->getIndex(ord2012, false);
      std::vector<u16> ord2014({0, 1});
      slog::Relation* readrel2015 = db->getRelation("ref");
      refindex1975 = readrel2015->getIndex(ord2014, false);
      std::vector<u16> ord2016({1, 0});
      slog::Relation* readrel2017 = db->getRelation("ref");
      refindex1976 = readrel2017->getIndex(ord2016, false);
      std::vector<u16> ord2018({1, 2, 0});
      slog::Relation* readrel2019 = db->getRelation("app");
      appindex1977 = readrel2019->getIndex(ord2018, false);
      std::vector<u16> ord2020({1, 0});
      slog::Relation* readrel2021 = db->getRelation("ref");
      refindex1978 = readrel2021->getIndex(ord2020, false);
      std::vector<u16> ord2022({1, 2, 0});
      slog::Relation* readrel2023 = db->getRelation("lambda");
      lambdaindex1979 = readrel2023->getIndex(ord2022, false);
      std::vector<u16> ord2024({1, 2, 0});
      slog::Relation* readrel2025 = db->getRelation("app");
      appindex1980 = readrel2025->getIndex(ord2024, false);
      std::vector<u16> ord2026({1, 0});
      slog::Relation* readrel2027 = db->getRelation("ref");
      refindex1981 = readrel2027->getIndex(ord2026, false);
      std::vector<u16> ord2028({1, 2, 0});
      slog::Relation* readrel2029 = db->getRelation("lambda");
      lambdaindex1982 = readrel2029->getIndex(ord2028, false);
      std::vector<u16> ord2030({1, 2, 0});
      slog::Relation* readrel2031 = db->getRelation("app");
      appindex1983 = readrel2031->getIndex(ord2030, false);
      std::vector<u16> ord2032({1, 2, 0});
      slog::Relation* readrel2033 = db->getRelation("lambda");
      lambdaindex1984 = readrel2033->getIndex(ord2032, false);
  
    }
    ReadTask1985(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c45 = v_const0aa6f87434af0222b916e97a;
      u64 v_c47 = v_const227d34ceeba7a29aada993d4;
      u64 v_c46 = v_constd3d07026d47882ceca728218;
      u64 v_c49 = v_const59ba3256d223f0d0a00d0633;
      u64 v_c50 = v_const7cd75b35aa30c3ddf04f9d57;
      u64 v_c48 = v_constf700a82e218a86de572e1f7f;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c47, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m2034) {
        u64 v_c63 = m2034[1];
        u64 v_c64 = m2034[2];
        if (buckethash(v_c63) != bucket) return;
        if (!slog::exists_probe<3,1>(lambdaindex1962, std::array<u64,3>{v_c49, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1963, std::array<u64,3>{v_c50, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1964, std::array<u64,2>{v_c50, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1965, std::array<u64,2>{v_c46, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1966, std::array<u64,2>{v_c49, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1967, std::array<u64,2>{v_c48, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1968, std::array<u64,3>{v_c48, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1969, std::array<u64,3>{v_c46, 0, 0})) return;
        slog::join_probe<2,1>(refindex1970, std::array<u64,2>{v_c45, 0}, [&](const std::array<u64,2>& m2035) {
          u64 v_c52 = m2035[1];
          if (!slog::exists_probe<3,1>(appindex1971, std::array<u64,3>{v_c52, 0, 0})) return;
          slog::join_probe<3,2>(appindex1972, std::array<u64,3>{v_c63, v_c52, 0}, [&](const std::array<u64,3>& m2036) {
            u64 v_c62 = m2036[2];
            slog::join_probe<3,2>(lambdaindex1973, std::array<u64,3>{v_c62, v_c49, 0}, [&](const std::array<u64,3>& m2037) {
              u64 v_c61 = m2037[2];
              slog::join_probe<3,2>(lambdaindex1974, std::array<u64,3>{v_c61, v_c50, 0}, [&](const std::array<u64,3>& m2038) {
                u64 v_c60 = m2038[2];
                slog::join_probe<2,2>(refindex1975, std::array<u64,2>{v_c60, v_c50}, [&](const std::array<u64,2>& m2039) {
                  slog::join_probe<2,1>(refindex1976, std::array<u64,2>{v_c46, 0}, [&](const std::array<u64,2>& m2040) {
                    u64 v_c51 = m2040[1];
                    if (!slog::exists_probe<3,1>(appindex1977, std::array<u64,3>{v_c51, 0, 0})) return;
                    slog::join_probe<2,1>(refindex1978, std::array<u64,2>{v_c49, 0}, [&](const std::array<u64,2>& m2041) {
                      u64 v_c57 = m2041[1];
                      slog::join_probe<3,2>(lambdaindex1979, std::array<u64,3>{v_c49, v_c57, 0}, [&](const std::array<u64,3>& m2042) {
                        u64 v_c58 = m2042[2];
                        slog::join_probe<3,2>(appindex1980, std::array<u64,3>{v_c52, v_c58, 0}, [&](const std::array<u64,3>& m2043) {
                          u64 v_c59 = m2043[2];
                          slog::join_probe<2,1>(refindex1981, std::array<u64,2>{v_c48, 0}, [&](const std::array<u64,2>& m2044) {
                            u64 v_c53 = m2044[1];
                            slog::join_probe<3,2>(lambdaindex1982, std::array<u64,3>{v_c48, v_c53, 0}, [&](const std::array<u64,3>& m2045) {
                              u64 v_c54 = m2045[2];
                              slog::join_probe<3,2>(appindex1983, std::array<u64,3>{v_c51, v_c54, 0}, [&](const std::array<u64,3>& m2046) {
                                u64 v_c55 = m2046[2];
                                slog::join_probe<3,2>(lambdaindex1984, std::array<u64,3>{v_c46, v_c55, 0}, [&](const std::array<u64,3>& m2047) {
                                  u64 v_c56 = m2047[2];
                                  ++_fires;
                                  slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c64, v_c59}, std::array<u16,3>{1, 2, 0});
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
  
      if (_fires) db->bumpFires("mcfa-counting.slog:287", "delta:lambda", _fires);
  
      if (!_done)
      {
        ReadTask1985* _cont = new ReadTask1985(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1985(db,b), false);
  // (crule (pre) (scan clo __t1oxE320 __t6vap319 cb) (body (exists $sup27994x83x0x0x1 (4 0 1 2 3 5 6 7 8 9) 1 cb) (join eval_ans (1 0) 1 __t1oxE320 __t1FV8318) (exists $sup27994x83x0x0x1 (1 4 0 2 3 5 6 7 8 9) 2 __t1FV8318 cb) (join eval (0 2 1) 1 __t1FV8318 c ef) (exists $sup27994x83x0x0x0 (1 3 0 2) 2 c ef) (exists eval (2 0 1) 1 c) (exists app (1 2 0) 1 ef) (join $sup27994x83x0x0x1 (1 3 7 4 0 2 5 6 8 9) 4 __t1FV8318 c ef cb __t5GoB317 __t8XTs321 ea eb va x) (join $sup27994x83x0x0x0 (0 1 2 3) 4 __t5GoB317 c ea ef) (join lambda (0 1 2) 3 __t6vap319 x eb) (join-old eval (0 2 1) 3 (0 2 1) __t8XTs321 c ea) (join eval_ans (0 1) 2 __t8XTs321 va) (exists app (1 2 0) 2 ef ea) (exists eval (1 2 0) 1 eb) (join eval (0 2 1) 2 __t5GoB317 c __t3MbO322) (join-old app (0 1 2) 3 (0 1 2) __t3MbO322 ef ea) (join-old eval (1 2 0) 2 (1 2 0) eb __t3MbO322 __t3H1A323) (join eval_ans (0 1) 1 __t3H1A323 v)) (head (emit eval_ans (0 1) __t5GoB317 v)) mcfa-counting.slog:84 #f)
  class ReadTask2069 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup27994x83x0x0x1index2048;  slog::Index** eval_ansindex2049;  slog::Index** $sup27994x83x0x0x1index2050;  slog::Index** evalindex2051;  slog::Index** $sup27994x83x0x0x0index2052;  slog::Index** evalindex2053;  slog::Index** appindex2054;  slog::Index** $sup27994x83x0x0x1index2055;  slog::Index** $sup27994x83x0x0x0index2056;  slog::Index** lambdaindex2057;  slog::Index** evalindex2058;  slog::Index** eval_ansindex2059;  slog::Index** appindex2060;  slog::Index** evalindex2061;  slog::Index** evalindex2062;  slog::Index** appindex2063;  slog::Index** evalindex2064;  slog::Index** eval_ansindex2065;  slog::Index** evaldelta2066;  slog::Index** appdelta2067;  slog::Index** evaldelta2068;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord2070({0, 1});
      slog::Relation* readrel2071 = db->getRelation("eval_ans");
      head_index[0] = readrel2071->getIndex(ord2070, false);
      outer_rel = db->getRelation("clo");
      std::vector<u16> ord2072({4, 0, 1, 2, 3, 5, 6, 7, 8, 9});
      slog::Relation* readrel2073 = db->getRelation("$sup27994x83x0x0x1");
      $sup27994x83x0x0x1index2048 = readrel2073->getIndex(ord2072, false);
      std::vector<u16> ord2074({1, 0});
      slog::Relation* readrel2075 = db->getRelation("eval_ans");
      eval_ansindex2049 = readrel2075->getIndex(ord2074, false);
      std::vector<u16> ord2076({1, 4, 0, 2, 3, 5, 6, 7, 8, 9});
      slog::Relation* readrel2077 = db->getRelation("$sup27994x83x0x0x1");
      $sup27994x83x0x0x1index2050 = readrel2077->getIndex(ord2076, false);
      std::vector<u16> ord2078({0, 2, 1});
      slog::Relation* readrel2079 = db->getRelation("eval");
      evalindex2051 = readrel2079->getIndex(ord2078, false);
      std::vector<u16> ord2080({1, 3, 0, 2});
      slog::Relation* readrel2081 = db->getRelation("$sup27994x83x0x0x0");
      $sup27994x83x0x0x0index2052 = readrel2081->getIndex(ord2080, false);
      std::vector<u16> ord2082({2, 0, 1});
      slog::Relation* readrel2083 = db->getRelation("eval");
      evalindex2053 = readrel2083->getIndex(ord2082, false);
      std::vector<u16> ord2084({1, 2, 0});
      slog::Relation* readrel2085 = db->getRelation("app");
      appindex2054 = readrel2085->getIndex(ord2084, false);
      std::vector<u16> ord2086({1, 3, 7, 4, 0, 2, 5, 6, 8, 9});
      slog::Relation* readrel2087 = db->getRelation("$sup27994x83x0x0x1");
      $sup27994x83x0x0x1index2055 = readrel2087->getIndex(ord2086, false);
      std::vector<u16> ord2088({0, 1, 2, 3});
      slog::Relation* readrel2089 = db->getRelation("$sup27994x83x0x0x0");
      $sup27994x83x0x0x0index2056 = readrel2089->getIndex(ord2088, false);
      std::vector<u16> ord2090({0, 1, 2});
      slog::Relation* readrel2091 = db->getRelation("lambda");
      lambdaindex2057 = readrel2091->getIndex(ord2090, false);
      std::vector<u16> ord2092({0, 2, 1});
      slog::Relation* readrel2093 = db->getRelation("eval");
      evalindex2058 = readrel2093->getIndex(ord2092, false);
      std::vector<u16> ord2094({0, 2, 1});
      slog::Relation* readrel2095 = db->getRelation("eval");
      evaldelta2066 = readrel2095->getIndex(ord2094, true);
      std::vector<u16> ord2096({0, 1});
      slog::Relation* readrel2097 = db->getRelation("eval_ans");
      eval_ansindex2059 = readrel2097->getIndex(ord2096, false);
      std::vector<u16> ord2098({1, 2, 0});
      slog::Relation* readrel2099 = db->getRelation("app");
      appindex2060 = readrel2099->getIndex(ord2098, false);
      std::vector<u16> ord2100({1, 2, 0});
      slog::Relation* readrel2101 = db->getRelation("eval");
      evalindex2061 = readrel2101->getIndex(ord2100, false);
      std::vector<u16> ord2102({0, 2, 1});
      slog::Relation* readrel2103 = db->getRelation("eval");
      evalindex2062 = readrel2103->getIndex(ord2102, false);
      std::vector<u16> ord2104({0, 1, 2});
      slog::Relation* readrel2105 = db->getRelation("app");
      appindex2063 = readrel2105->getIndex(ord2104, false);
      std::vector<u16> ord2106({0, 1, 2});
      slog::Relation* readrel2107 = db->getRelation("app");
      appdelta2067 = readrel2107->getIndex(ord2106, true);
      std::vector<u16> ord2108({1, 2, 0});
      slog::Relation* readrel2109 = db->getRelation("eval");
      evalindex2064 = readrel2109->getIndex(ord2108, false);
      std::vector<u16> ord2110({1, 2, 0});
      slog::Relation* readrel2111 = db->getRelation("eval");
      evaldelta2068 = readrel2111->getIndex(ord2110, true);
      std::vector<u16> ord2112({0, 1});
      slog::Relation* readrel2113 = db->getRelation("eval_ans");
      eval_ansindex2065 = readrel2113->getIndex(ord2112, false);
  
    }
    ReadTask2069(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c189 = _t[0];
        u64 v_c190 = _t[1];
        u64 v_c27 = _t[2];
        if (!slog::exists_probe<10,1>($sup27994x83x0x0x1index2048, std::array<u64,10>{v_c27, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(eval_ansindex2049, std::array<u64,2>{v_c189, 0}, [&](const std::array<u64,2>& m2114) {
          u64 v_c191 = m2114[1];
          if (!slog::exists_probe<10,2>($sup27994x83x0x0x1index2050, std::array<u64,10>{v_c191, v_c27, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          slog::join_probe<3,1>(evalindex2051, std::array<u64,3>{v_c191, 0, 0}, [&](const std::array<u64,3>& m2115) {
            u64 v_c21 = m2115[1]; u64 v_c3 = m2115[2];
            if (!slog::exists_probe<4,2>($sup27994x83x0x0x0index2052, std::array<u64,4>{v_c21, v_c3, 0, 0})) return;
            if (!slog::exists_probe<3,1>(evalindex2053, std::array<u64,3>{v_c21, 0, 0})) return;
            if (!slog::exists_probe<3,1>(appindex2054, std::array<u64,3>{v_c3, 0, 0})) return;
            slog::join_probe<10,4>($sup27994x83x0x0x1index2055, std::array<u64,10>{v_c191, v_c21, v_c3, v_c27, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,10>& m2116) {
              u64 v_c192 = m2116[4]; u64 v_c193 = m2116[5]; u64 v_c1 = m2116[6]; u64 v_c29 = m2116[7]; u64 v_c26 = m2116[8]; u64 v_c0 = m2116[9];
              slog::join_probe<4,4>($sup27994x83x0x0x0index2056, std::array<u64,4>{v_c192, v_c21, v_c1, v_c3}, [&](const std::array<u64,4>& m2117) {
                slog::join_probe<3,3>(lambdaindex2057, std::array<u64,3>{v_c190, v_c0, v_c29}, [&](const std::array<u64,3>& m2118) {
                  slog::join_probe_old<3,3>(evalindex2058, evaldelta2066, std::array<u64,3>{v_c193, v_c21, v_c1}, [&](const std::array<u64,3>& m2119) {
                    slog::join_probe<2,2>(eval_ansindex2059, std::array<u64,2>{v_c193, v_c26}, [&](const std::array<u64,2>& m2120) {
                      if (!slog::exists_probe<3,2>(appindex2060, std::array<u64,3>{v_c3, v_c1, 0})) return;
                      if (!slog::exists_probe<3,1>(evalindex2061, std::array<u64,3>{v_c29, 0, 0})) return;
                      slog::join_probe<3,2>(evalindex2062, std::array<u64,3>{v_c192, v_c21, 0}, [&](const std::array<u64,3>& m2121) {
                        u64 v_c194 = m2121[2];
                        slog::join_probe_old<3,3>(appindex2063, appdelta2067, std::array<u64,3>{v_c194, v_c3, v_c1}, [&](const std::array<u64,3>& m2122) {
                          slog::join_probe_old<3,2>(evalindex2064, evaldelta2068, std::array<u64,3>{v_c29, v_c194, 0}, [&](const std::array<u64,3>& m2123) {
                            u64 v_c195 = m2123[2];
                            slog::join_probe<2,1>(eval_ansindex2065, std::array<u64,2>{v_c195, 0}, [&](const std::array<u64,2>& m2124) {
                              u64 v_c196 = m2124[1];
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
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:84", "delta:clo", _fires);
  
      if (!_done)
      {
        ReadTask2069* _cont = new ReadTask2069(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask2069(db,b), false);
  // (crule (pre (let __tconst0y6X73 const0aa6f87434af0222b916e97a) (let __tconst7zoP70 const227d34ceeba7a29aada993d4) (let __tconst0aL952 constd3d07026d47882ceca728218) (let __tconst1bfe65 const59ba3256d223f0d0a00d0633) (let __tconst0xUh47 constf700a82e218a86de572e1f7f) (let __tconst8wN863 const7cd75b35aa30c3ddf04f9d57)) (seeded) (body (join ref (1 0) 1 __tconst0y6X73 __t0QRr59) (exists ref (1 0) 1 __tconst1bfe65) (exists lambda (1 2 0) 1 __tconst1bfe65) (exists app (1 2 0) 1 __t0QRr59) (exists ref (1 0) 1 __tconst0xUh47) (exists lambda (1 2 0) 1 __tconst0xUh47) (exists lambda (1 2 0) 1 __tconst0aL952) (exists ref (1 0) 1 __tconst8wN863) (exists lambda (1 2 0) 1 __tconst8wN863) (exists lambda (1 2 0) 1 __tconst7zoP70) (join ref (1 0) 1 __tconst0aL952 __t5HQ450) (exists app (1 2 0) 1 __t5HQ450) (join ref (1 0) 1 __tconst1bfe65 __t2HsD55) (join lambda (1 2 0) 2 __tconst1bfe65 __t2HsD55 __t0uNb57) (join app (1 2 0) 2 __t0QRr59 __t0uNb57 __t81HE60) (exists app (2 0 1) 1 __t81HE60) (join ref (1 0) 1 __tconst0xUh47 __t5vZb46) (join lambda (1 2 0) 2 __tconst0xUh47 __t5vZb46 __t50zW48) (join app (1 2 0) 2 __t5HQ450 __t50zW48 __t05NY51) (join lambda (1 2 0) 2 __tconst0aL952 __t05NY51 __t3xtz53) (join ref (1 0) 1 __tconst8wN863 __t1mkO62) (join lambda (1 2 0) 2 __tconst8wN863 __t1mkO62 __t3Dru64) (join lambda (1 2 0) 2 __tconst1bfe65 __t3Dru64 __t7JIT66) (join app (1 2 0) 2 __t0QRr59 __t7JIT66 __t5Ri569) (join lambda (1 2 0) 2 __tconst7zoP70 __t5Ri569 __t7KAC71) (join app (1 2 0) 2 __t7KAC71 __t81HE60 __t9kFz72)) (head (mkstruct lambda (1 2 0) __t9J4m74 __tconst0y6X73 __t9kFz72)) mcfa-counting.slog:287 #f)
  class ReadTask2151 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex2125;  slog::Index** refindex2126;  slog::Index** lambdaindex2127;  slog::Index** appindex2128;  slog::Index** refindex2129;  slog::Index** lambdaindex2130;  slog::Index** lambdaindex2131;  slog::Index** refindex2132;  slog::Index** lambdaindex2133;  slog::Index** lambdaindex2134;  slog::Index** refindex2135;  slog::Index** appindex2136;  slog::Index** refindex2137;  slog::Index** lambdaindex2138;  slog::Index** appindex2139;  slog::Index** appindex2140;  slog::Index** refindex2141;  slog::Index** lambdaindex2142;  slog::Index** appindex2143;  slog::Index** lambdaindex2144;  slog::Index** refindex2145;  slog::Index** lambdaindex2146;  slog::Index** lambdaindex2147;  slog::Index** appindex2148;  slog::Index** lambdaindex2149;  slog::Index** appindex2150;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      std::vector<u16> ord2152({1, 2, 0});
      slog::Relation* readrel2153 = db->getRelation("lambda");
      head_index[0] = readrel2153->getIndex(ord2152, false);
      std::vector<u16> ord2154({1, 0});
      slog::Relation* readrel2155 = db->getRelation("ref");
      refindex2125 = readrel2155->getIndex(ord2154, false);
      std::vector<u16> ord2156({1, 0});
      slog::Relation* readrel2157 = db->getRelation("ref");
      refindex2126 = readrel2157->getIndex(ord2156, false);
      std::vector<u16> ord2158({1, 2, 0});
      slog::Relation* readrel2159 = db->getRelation("lambda");
      lambdaindex2127 = readrel2159->getIndex(ord2158, false);
      std::vector<u16> ord2160({1, 2, 0});
      slog::Relation* readrel2161 = db->getRelation("app");
      appindex2128 = readrel2161->getIndex(ord2160, false);
      std::vector<u16> ord2162({1, 0});
      slog::Relation* readrel2163 = db->getRelation("ref");
      refindex2129 = readrel2163->getIndex(ord2162, false);
      std::vector<u16> ord2164({1, 2, 0});
      slog::Relation* readrel2165 = db->getRelation("lambda");
      lambdaindex2130 = readrel2165->getIndex(ord2164, false);
      std::vector<u16> ord2166({1, 2, 0});
      slog::Relation* readrel2167 = db->getRelation("lambda");
      lambdaindex2131 = readrel2167->getIndex(ord2166, false);
      std::vector<u16> ord2168({1, 0});
      slog::Relation* readrel2169 = db->getRelation("ref");
      refindex2132 = readrel2169->getIndex(ord2168, false);
      std::vector<u16> ord2170({1, 2, 0});
      slog::Relation* readrel2171 = db->getRelation("lambda");
      lambdaindex2133 = readrel2171->getIndex(ord2170, false);
      std::vector<u16> ord2172({1, 2, 0});
      slog::Relation* readrel2173 = db->getRelation("lambda");
      lambdaindex2134 = readrel2173->getIndex(ord2172, false);
      std::vector<u16> ord2174({1, 0});
      slog::Relation* readrel2175 = db->getRelation("ref");
      refindex2135 = readrel2175->getIndex(ord2174, false);
      std::vector<u16> ord2176({1, 2, 0});
      slog::Relation* readrel2177 = db->getRelation("app");
      appindex2136 = readrel2177->getIndex(ord2176, false);
      std::vector<u16> ord2178({1, 0});
      slog::Relation* readrel2179 = db->getRelation("ref");
      refindex2137 = readrel2179->getIndex(ord2178, false);
      std::vector<u16> ord2180({1, 2, 0});
      slog::Relation* readrel2181 = db->getRelation("lambda");
      lambdaindex2138 = readrel2181->getIndex(ord2180, false);
      std::vector<u16> ord2182({1, 2, 0});
      slog::Relation* readrel2183 = db->getRelation("app");
      appindex2139 = readrel2183->getIndex(ord2182, false);
      std::vector<u16> ord2184({2, 0, 1});
      slog::Relation* readrel2185 = db->getRelation("app");
      appindex2140 = readrel2185->getIndex(ord2184, false);
      std::vector<u16> ord2186({1, 0});
      slog::Relation* readrel2187 = db->getRelation("ref");
      refindex2141 = readrel2187->getIndex(ord2186, false);
      std::vector<u16> ord2188({1, 2, 0});
      slog::Relation* readrel2189 = db->getRelation("lambda");
      lambdaindex2142 = readrel2189->getIndex(ord2188, false);
      std::vector<u16> ord2190({1, 2, 0});
      slog::Relation* readrel2191 = db->getRelation("app");
      appindex2143 = readrel2191->getIndex(ord2190, false);
      std::vector<u16> ord2192({1, 2, 0});
      slog::Relation* readrel2193 = db->getRelation("lambda");
      lambdaindex2144 = readrel2193->getIndex(ord2192, false);
      std::vector<u16> ord2194({1, 0});
      slog::Relation* readrel2195 = db->getRelation("ref");
      refindex2145 = readrel2195->getIndex(ord2194, false);
      std::vector<u16> ord2196({1, 2, 0});
      slog::Relation* readrel2197 = db->getRelation("lambda");
      lambdaindex2146 = readrel2197->getIndex(ord2196, false);
      std::vector<u16> ord2198({1, 2, 0});
      slog::Relation* readrel2199 = db->getRelation("lambda");
      lambdaindex2147 = readrel2199->getIndex(ord2198, false);
      std::vector<u16> ord2200({1, 2, 0});
      slog::Relation* readrel2201 = db->getRelation("app");
      appindex2148 = readrel2201->getIndex(ord2200, false);
      std::vector<u16> ord2202({1, 2, 0});
      slog::Relation* readrel2203 = db->getRelation("lambda");
      lambdaindex2149 = readrel2203->getIndex(ord2202, false);
      std::vector<u16> ord2204({1, 2, 0});
      slog::Relation* readrel2205 = db->getRelation("app");
      appindex2150 = readrel2205->getIndex(ord2204, false);
  
    }
    ReadTask2151(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c45 = v_const0aa6f87434af0222b916e97a;
      u64 v_c47 = v_const227d34ceeba7a29aada993d4;
      u64 v_c46 = v_constd3d07026d47882ceca728218;
      u64 v_c49 = v_const59ba3256d223f0d0a00d0633;
      u64 v_c48 = v_constf700a82e218a86de572e1f7f;
      u64 v_c50 = v_const7cd75b35aa30c3ddf04f9d57;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex2125, std::array<u64,2>{v_c45, 0}, [&](const std::array<u64,2>& m2206) {
        u64 v_c52 = m2206[1];
        if (!slog::exists_probe<2,1>(refindex2126, std::array<u64,2>{v_c49, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex2127, std::array<u64,3>{v_c49, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex2128, std::array<u64,3>{v_c52, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex2129, std::array<u64,2>{v_c48, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex2130, std::array<u64,3>{v_c48, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex2131, std::array<u64,3>{v_c46, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex2132, std::array<u64,2>{v_c50, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex2133, std::array<u64,3>{v_c50, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex2134, std::array<u64,3>{v_c47, 0, 0})) return;
        slog::join_probe<2,1>(refindex2135, std::array<u64,2>{v_c46, 0}, [&](const std::array<u64,2>& m2207) {
          u64 v_c51 = m2207[1];
          if (!slog::exists_probe<3,1>(appindex2136, std::array<u64,3>{v_c51, 0, 0})) return;
          slog::join_probe<2,1>(refindex2137, std::array<u64,2>{v_c49, 0}, [&](const std::array<u64,2>& m2208) {
            u64 v_c57 = m2208[1];
            slog::join_probe<3,2>(lambdaindex2138, std::array<u64,3>{v_c49, v_c57, 0}, [&](const std::array<u64,3>& m2209) {
              u64 v_c58 = m2209[2];
              slog::join_probe<3,2>(appindex2139, std::array<u64,3>{v_c52, v_c58, 0}, [&](const std::array<u64,3>& m2210) {
                u64 v_c59 = m2210[2];
                if (!slog::exists_probe<3,1>(appindex2140, std::array<u64,3>{v_c59, 0, 0})) return;
                slog::join_probe<2,1>(refindex2141, std::array<u64,2>{v_c48, 0}, [&](const std::array<u64,2>& m2211) {
                  u64 v_c53 = m2211[1];
                  slog::join_probe<3,2>(lambdaindex2142, std::array<u64,3>{v_c48, v_c53, 0}, [&](const std::array<u64,3>& m2212) {
                    u64 v_c54 = m2212[2];
                    slog::join_probe<3,2>(appindex2143, std::array<u64,3>{v_c51, v_c54, 0}, [&](const std::array<u64,3>& m2213) {
                      u64 v_c55 = m2213[2];
                      slog::join_probe<3,2>(lambdaindex2144, std::array<u64,3>{v_c46, v_c55, 0}, [&](const std::array<u64,3>& m2214) {
                        u64 v_c56 = m2214[2];
                        slog::join_probe<2,1>(refindex2145, std::array<u64,2>{v_c50, 0}, [&](const std::array<u64,2>& m2215) {
                          u64 v_c60 = m2215[1];
                          slog::join_probe<3,2>(lambdaindex2146, std::array<u64,3>{v_c50, v_c60, 0}, [&](const std::array<u64,3>& m2216) {
                            u64 v_c61 = m2216[2];
                            slog::join_probe<3,2>(lambdaindex2147, std::array<u64,3>{v_c49, v_c61, 0}, [&](const std::array<u64,3>& m2217) {
                              u64 v_c62 = m2217[2];
                              slog::join_probe<3,2>(appindex2148, std::array<u64,3>{v_c52, v_c62, 0}, [&](const std::array<u64,3>& m2218) {
                                u64 v_c63 = m2218[2];
                                slog::join_probe<3,2>(lambdaindex2149, std::array<u64,3>{v_c47, v_c63, 0}, [&](const std::array<u64,3>& m2219) {
                                  u64 v_c64 = m2219[2];
                                  slog::join_probe<3,2>(appindex2150, std::array<u64,3>{v_c64, v_c59, 0}, [&](const std::array<u64,3>& m2220) {
                                    u64 v_c65 = m2220[2];
                                    ++_fires;
                                    slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c45, v_c65}, std::array<u16,3>{1, 2, 0});
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
  
      if (_fires) db->bumpFires("mcfa-counting.slog:287", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask2151(db,b));
  // (crule (pre (let __tconst0zC2144 const4e3b5454cf93e32fad90650d) (let __tconst8xRt151 const3a82152bd1402931076fe2d7) (let __tconst8eg8132 const361d5df359e0d7681220d09d) (let __tconst3Taj142 constdc1bb6655fb38bdb032e3754)) (seeded) (body (join ref (1 0) 1 __tconst8eg8132 __t19JM131) (exists ref (1 0) 1 __tconst8xRt151) (exists ref (1 0) 1 __tconst3Taj142) (exists ref (1 0) 1 __tconst0zC2144) (exists lambda (1 2 0) 1 __tconst8xRt151) (exists lambda (1 2 0) 1 __tconst3Taj142) (exists lambda (1 2 0) 1 __tconst0zC2144) (join lambda (1 2 0) 2 __tconst8eg8132 __t19JM131 __t4DXA133) (join ref (1 0) 1 __tconst8xRt151 __t1g2P147) (exists app (1 2 0) 1 __t1g2P147) (join ref (1 0) 1 __tconst3Taj142 __t93Xi135) (exists app (2 0 1) 1 __t93Xi135) (join ref (1 0) 1 __tconst0zC2144 __t7VSc137) (exists app (1 2 0) 1 __t7VSc137) (join app (1 2 0) 1 __t1g2P147 dup4s8e409 __t9UZN150) (eq __t1g2P147 dup4s8e409) (join lambda (1 2 0) 2 __tconst8xRt151 __t9UZN150 __t2nYy152) (exists app (1 2 0) 1 __t2nYy152) (join app (1 2 0) 1 __t7VSc137 dup2aUj410 __t8dYW140) (eq __t7VSc137 dup2aUj410) (join app (1 2 0) 2 __t8dYW140 __t93Xi135 __t25NQ141) (join lambda (1 2 0) 2 __tconst3Taj142 __t25NQ141 __t2Ce3143) (join lambda (1 2 0) 2 __tconst0zC2144 __t2Ce3143 __t6t5O145) (join app (1 2 0) 2 __t2nYy152 __t6t5O145 __t6Ups153)) (head (mkstruct app (1 2 0) __t6KrY154 __t6Ups153 __t4DXA133)) mcfa-counting.slog:224 #f)
  class ReadTask2243 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex2221;  slog::Index** refindex2222;  slog::Index** refindex2223;  slog::Index** refindex2224;  slog::Index** lambdaindex2225;  slog::Index** lambdaindex2226;  slog::Index** lambdaindex2227;  slog::Index** lambdaindex2228;  slog::Index** refindex2229;  slog::Index** appindex2230;  slog::Index** refindex2231;  slog::Index** appindex2232;  slog::Index** refindex2233;  slog::Index** appindex2234;  slog::Index** appindex2235;  slog::Index** lambdaindex2236;  slog::Index** appindex2237;  slog::Index** appindex2238;  slog::Index** appindex2239;  slog::Index** lambdaindex2240;  slog::Index** lambdaindex2241;  slog::Index** appindex2242;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord2244({1, 2, 0});
      slog::Relation* readrel2245 = db->getRelation("app");
      head_index[0] = readrel2245->getIndex(ord2244, false);
      std::vector<u16> ord2246({1, 0});
      slog::Relation* readrel2247 = db->getRelation("ref");
      refindex2221 = readrel2247->getIndex(ord2246, false);
      std::vector<u16> ord2248({1, 0});
      slog::Relation* readrel2249 = db->getRelation("ref");
      refindex2222 = readrel2249->getIndex(ord2248, false);
      std::vector<u16> ord2250({1, 0});
      slog::Relation* readrel2251 = db->getRelation("ref");
      refindex2223 = readrel2251->getIndex(ord2250, false);
      std::vector<u16> ord2252({1, 0});
      slog::Relation* readrel2253 = db->getRelation("ref");
      refindex2224 = readrel2253->getIndex(ord2252, false);
      std::vector<u16> ord2254({1, 2, 0});
      slog::Relation* readrel2255 = db->getRelation("lambda");
      lambdaindex2225 = readrel2255->getIndex(ord2254, false);
      std::vector<u16> ord2256({1, 2, 0});
      slog::Relation* readrel2257 = db->getRelation("lambda");
      lambdaindex2226 = readrel2257->getIndex(ord2256, false);
      std::vector<u16> ord2258({1, 2, 0});
      slog::Relation* readrel2259 = db->getRelation("lambda");
      lambdaindex2227 = readrel2259->getIndex(ord2258, false);
      std::vector<u16> ord2260({1, 2, 0});
      slog::Relation* readrel2261 = db->getRelation("lambda");
      lambdaindex2228 = readrel2261->getIndex(ord2260, false);
      std::vector<u16> ord2262({1, 0});
      slog::Relation* readrel2263 = db->getRelation("ref");
      refindex2229 = readrel2263->getIndex(ord2262, false);
      std::vector<u16> ord2264({1, 2, 0});
      slog::Relation* readrel2265 = db->getRelation("app");
      appindex2230 = readrel2265->getIndex(ord2264, false);
      std::vector<u16> ord2266({1, 0});
      slog::Relation* readrel2267 = db->getRelation("ref");
      refindex2231 = readrel2267->getIndex(ord2266, false);
      std::vector<u16> ord2268({2, 0, 1});
      slog::Relation* readrel2269 = db->getRelation("app");
      appindex2232 = readrel2269->getIndex(ord2268, false);
      std::vector<u16> ord2270({1, 0});
      slog::Relation* readrel2271 = db->getRelation("ref");
      refindex2233 = readrel2271->getIndex(ord2270, false);
      std::vector<u16> ord2272({1, 2, 0});
      slog::Relation* readrel2273 = db->getRelation("app");
      appindex2234 = readrel2273->getIndex(ord2272, false);
      std::vector<u16> ord2274({1, 2, 0});
      slog::Relation* readrel2275 = db->getRelation("app");
      appindex2235 = readrel2275->getIndex(ord2274, false);
      std::vector<u16> ord2276({1, 2, 0});
      slog::Relation* readrel2277 = db->getRelation("lambda");
      lambdaindex2236 = readrel2277->getIndex(ord2276, false);
      std::vector<u16> ord2278({1, 2, 0});
      slog::Relation* readrel2279 = db->getRelation("app");
      appindex2237 = readrel2279->getIndex(ord2278, false);
      std::vector<u16> ord2280({1, 2, 0});
      slog::Relation* readrel2281 = db->getRelation("app");
      appindex2238 = readrel2281->getIndex(ord2280, false);
      std::vector<u16> ord2282({1, 2, 0});
      slog::Relation* readrel2283 = db->getRelation("app");
      appindex2239 = readrel2283->getIndex(ord2282, false);
      std::vector<u16> ord2284({1, 2, 0});
      slog::Relation* readrel2285 = db->getRelation("lambda");
      lambdaindex2240 = readrel2285->getIndex(ord2284, false);
      std::vector<u16> ord2286({1, 2, 0});
      slog::Relation* readrel2287 = db->getRelation("lambda");
      lambdaindex2241 = readrel2287->getIndex(ord2286, false);
      std::vector<u16> ord2288({1, 2, 0});
      slog::Relation* readrel2289 = db->getRelation("app");
      appindex2242 = readrel2289->getIndex(ord2288, false);
  
    }
    ReadTask2243(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c4 = v_const4e3b5454cf93e32fad90650d;
      u64 v_c6 = v_const3a82152bd1402931076fe2d7;
      u64 v_c7 = v_const361d5df359e0d7681220d09d;
      u64 v_c5 = v_constdc1bb6655fb38bdb032e3754;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex2221, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m2290) {
        u64 v_c9 = m2290[1];
        if (!slog::exists_probe<2,1>(refindex2222, std::array<u64,2>{v_c6, 0})) return;
        if (!slog::exists_probe<2,1>(refindex2223, std::array<u64,2>{v_c5, 0})) return;
        if (!slog::exists_probe<2,1>(refindex2224, std::array<u64,2>{v_c4, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex2225, std::array<u64,3>{v_c6, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex2226, std::array<u64,3>{v_c5, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex2227, std::array<u64,3>{v_c4, 0, 0})) return;
        slog::join_probe<3,2>(lambdaindex2228, std::array<u64,3>{v_c7, v_c9, 0}, [&](const std::array<u64,3>& m2291) {
          u64 v_c10 = m2291[2];
          slog::join_probe<2,1>(refindex2229, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m2292) {
            u64 v_c12 = m2292[1];
            if (!slog::exists_probe<3,1>(appindex2230, std::array<u64,3>{v_c12, 0, 0})) return;
            slog::join_probe<2,1>(refindex2231, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m2293) {
              u64 v_c8 = m2293[1];
              if (!slog::exists_probe<3,1>(appindex2232, std::array<u64,3>{v_c8, 0, 0})) return;
              slog::join_probe<2,1>(refindex2233, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m2294) {
                u64 v_c11 = m2294[1];
                if (!slog::exists_probe<3,1>(appindex2234, std::array<u64,3>{v_c11, 0, 0})) return;
                slog::join_probe<3,1>(appindex2235, std::array<u64,3>{v_c12, 0, 0}, [&](const std::array<u64,3>& m2295) {
                  u64 v_c197 = m2295[1]; u64 v_c18 = m2295[2];
                  if (v_c12 != v_c197) return;
                  slog::join_probe<3,2>(lambdaindex2236, std::array<u64,3>{v_c6, v_c18, 0}, [&](const std::array<u64,3>& m2296) {
                    u64 v_c19 = m2296[2];
                    if (!slog::exists_probe<3,1>(appindex2237, std::array<u64,3>{v_c19, 0, 0})) return;
                    slog::join_probe<3,1>(appindex2238, std::array<u64,3>{v_c11, 0, 0}, [&](const std::array<u64,3>& m2297) {
                      u64 v_c198 = m2297[1]; u64 v_c14 = m2297[2];
                      if (v_c11 != v_c198) return;
                      slog::join_probe<3,2>(appindex2239, std::array<u64,3>{v_c14, v_c8, 0}, [&](const std::array<u64,3>& m2298) {
                        u64 v_c15 = m2298[2];
                        slog::join_probe<3,2>(lambdaindex2240, std::array<u64,3>{v_c5, v_c15, 0}, [&](const std::array<u64,3>& m2299) {
                          u64 v_c16 = m2299[2];
                          slog::join_probe<3,2>(lambdaindex2241, std::array<u64,3>{v_c4, v_c16, 0}, [&](const std::array<u64,3>& m2300) {
                            u64 v_c199 = m2300[2];
                            slog::join_probe<3,2>(appindex2242, std::array<u64,3>{v_c19, v_c199, 0}, [&](const std::array<u64,3>& m2301) {
                              u64 v_c200 = m2301[2];
                              ++_fires;
                              slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c200, v_c10}, std::array<u16,3>{1, 2, 0});
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
  
      if (_fires) db->bumpFires("mcfa-counting.slog:224", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask2243(db,b));
  // (crule (pre (let __tconst7sqz226 const7b8fd91ee9ff10cfbb8066bf) (let __tconst1EUj230 const615ad01b1c532bb6634df115) (let __tconst2VuQ234 const4492fd5fa4baacfebd29f5e5) (let __tconst2x2f244 consta32d5a443def48e6d64c6f4b) (let __tconst4Sko246 consteb793a6f75d6cfe49d3c2c90) (let __tconst4N2q248 constaaaad65142343c54348db5d0)) (once) (body) (head (mkstruct ref (1 0) __t5APF225 __tconst7sqz226) (mkstruct ref (1 0) __t3WVP229 __tconst1EUj230) (mkstruct ref (1 0) __t2PLq233 __tconst2VuQ234) (mkstruct ref (1 0) __t3pbc237 __tconst2x2f244) (mkstruct ref (1 0) __t16jv239 __tconst4Sko246) (mkstruct ref (1 0) __t6KL4241 __tconst4N2q248)) mcfa-counting.slog:272 #f)
  class ReadTask2302 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[6];
    slog::Index** head_index[6];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ref");
      head_rel[1] = db->getRelation("ref");
      head_rel[2] = db->getRelation("ref");
      head_rel[3] = db->getRelation("ref");
      head_rel[4] = db->getRelation("ref");
      head_rel[5] = db->getRelation("ref");
  
    }
    ReadTask2302(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c75 = v_const7b8fd91ee9ff10cfbb8066bf;
      u64 v_c76 = v_const615ad01b1c532bb6634df115;
      u64 v_c77 = v_const4492fd5fa4baacfebd29f5e5;
      u64 v_c78 = v_consta32d5a443def48e6d64c6f4b;
      u64 v_c74 = v_consteb793a6f75d6cfe49d3c2c90;
      u64 v_c73 = v_constaaaad65142343c54348db5d0;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[6];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
      newbatch[4] = new slog::InsertBatch();
      newbatch[5] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c75}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c76}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[2], newbatch[2], std::array<u64,1>{v_c77}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[3], newbatch[3], std::array<u64,1>{v_c78}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[4], newbatch[4], std::array<u64,1>{v_c74}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[5], newbatch[5], std::array<u64,1>{v_c73}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
        head_rel[5]->sendBatch(newbatch[5]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:272", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask2302(db,b), true);
  // (crule (pre (let __trid26iU356 const07ef7e8462f6d369d70a1f0e) (let __trel2XVx357 const4a59dbb9cb3129dfcc75170b) (let __tcol8Ls8358 const5feceb66ffc86f38d952786c) (let __trel0xDC359 const4a59dbb9cb3129dfcc75170b) (let __tcol3KnN360 const6b86b273ff34fce19d6b804e)) (scan $sup27994x83x0x0x0 __d0 c ea ef) (body) (head (tycheck ea (accept (struct app) (struct lambda) (struct ref)) __trid26iU356 __trel2XVx357 __tcol8Ls8358 (1 2 3 4 0)) (tycheck c (accept (struct app) (struct _enum)) __trid26iU356 __trel0xDC359 __tcol3KnN360 (1 2 3 4 0)) (mkstruct eval (1 2 0) __8HHI355 ea c)) mcfa-counting.slog:84 #f)
  class ReadTask2307 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid2306;  u32 sid2303;  u32 sid2304;  u32 sid2305;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("eval");
      outer_rel = db->getRelation("$sup27994x83x0x0x0");
      sid2306 = db->getRelation("_enum")->getStructId();
      sid2303 = db->getRelation("app")->getStructId();
      sid2304 = db->getRelation("lambda")->getStructId();
      sid2305 = db->getRelation("ref")->getStructId();
  
    }
    ReadTask2307(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c201 = v_const07ef7e8462f6d369d70a1f0e;
      u64 v_c202 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c203 = v_const5feceb66ffc86f38d952786c;
      u64 v_c204 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c205 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c152 = _t[0];
        u64 v_c21 = _t[1];
        u64 v_c1 = _t[2];
        u64 v_c3 = _t[3];
        ++_fires;
        if (!((is_struct(v_c1) && (decode_struct_id(v_c1) == sid2303 || decode_struct_id(v_c1) == sid2304 || decode_struct_id(v_c1) == sid2305))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c201, v_c202, v_c203, v_c1}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c21) && (decode_struct_id(v_c21) == sid2303 || decode_struct_id(v_c21) == sid2306))))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c201, v_c204, v_c205, v_c21}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c1, v_c21}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:84", "delta:$sup27994x83x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask2307* _cont = new ReadTask2307(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask2307(db,b), false);
  // (crule (pre (let __tconst5Fqn220 const15bb62b8293a526ca6f0e4eb) (let __tconst0ZcM213 constfc9ee54e0ee8c6d1e715716c) (let __tconst9TQS210 const5950e3cb761734f52a881545) (let __tconst1wsq203 const77ceb5c0e9f84ebd84104a97)) (seeded) (body (join ref (1 0) 1 __tconst1wsq203 __t6pkv202) (exists ref (1 0) 1 __tconst5Fqn220) (join ref (1 0) 1 __tconst0ZcM213 __t6fYg206) (join ref (1 0) 1 __tconst5Fqn220 __t2V0C216)) (head (mkstruct app (1 2 0) __t9nSF219 __t2V0C216 __t2V0C216) (mkstruct app (1 2 0) __t1W86209 __t6fYg206 __t6fYg206) (mkstruct lambda (1 2 0) __t118D204 __tconst1wsq203 __t6pkv202)) mcfa-counting.slog:211 #f)
  class ReadTask2312 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
  
  
  
  
  
  
    slog::Index** refindex2308;  slog::Index** refindex2309;  slog::Index** refindex2310;  slog::Index** refindex2311;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord2313({1, 2, 0});
      slog::Relation* readrel2314 = db->getRelation("app");
      head_index[0] = readrel2314->getIndex(ord2313, false);
      head_rel[1] = db->getRelation("app");
      std::vector<u16> ord2315({1, 2, 0});
      slog::Relation* readrel2316 = db->getRelation("app");
      head_index[1] = readrel2316->getIndex(ord2315, false);
      head_rel[2] = db->getRelation("lambda");
      std::vector<u16> ord2317({1, 2, 0});
      slog::Relation* readrel2318 = db->getRelation("lambda");
      head_index[2] = readrel2318->getIndex(ord2317, false);
      std::vector<u16> ord2319({1, 0});
      slog::Relation* readrel2320 = db->getRelation("ref");
      refindex2308 = readrel2320->getIndex(ord2319, false);
      std::vector<u16> ord2321({1, 0});
      slog::Relation* readrel2322 = db->getRelation("ref");
      refindex2309 = readrel2322->getIndex(ord2321, false);
      std::vector<u16> ord2323({1, 0});
      slog::Relation* readrel2324 = db->getRelation("ref");
      refindex2310 = readrel2324->getIndex(ord2323, false);
      std::vector<u16> ord2325({1, 0});
      slog::Relation* readrel2326 = db->getRelation("ref");
      refindex2311 = readrel2326->getIndex(ord2325, false);
  
    }
    ReadTask2312(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c206 = v_const15bb62b8293a526ca6f0e4eb;
      u64 v_c207 = v_constfc9ee54e0ee8c6d1e715716c;
      u64 v_c208 = v_const5950e3cb761734f52a881545;
      u64 v_c209 = v_const77ceb5c0e9f84ebd84104a97;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex2308, std::array<u64,2>{v_c209, 0}, [&](const std::array<u64,2>& m2327) {
        u64 v_c210 = m2327[1];
        if (!slog::exists_probe<2,1>(refindex2309, std::array<u64,2>{v_c206, 0})) return;
        slog::join_probe<2,1>(refindex2310, std::array<u64,2>{v_c207, 0}, [&](const std::array<u64,2>& m2328) {
          u64 v_c211 = m2328[1];
          slog::join_probe<2,1>(refindex2311, std::array<u64,2>{v_c206, 0}, [&](const std::array<u64,2>& m2329) {
            u64 v_c212 = m2329[1];
            ++_fires;
            slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c212, v_c212}, std::array<u16,3>{1, 2, 0});
            slog::emit_struct_checked<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c211, v_c211}, std::array<u16,3>{1, 2, 0});
            slog::emit_struct_checked<3>(head_rel[2], head_index[2], newbatch[2], std::array<u64,2>{v_c209, v_c210}, std::array<u16,3>{1, 2, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:211", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask2312(db,b));
  // (crule (pre) (scan $sup27994x83x0x0x0 __d0 c ea ef) (body (exists eval (1 2 0) 2 ea c) (join-old eval (1 2 0) 2 (1 2 0) ef c __t8nKY157) (exists eval_ans (0 1) 1 __t8nKY157) (join-old eval (1 2 0) 2 (1 2 0) ea c __t4j5Q160) (exists eval_ans (0 1) 1 __t4j5Q160) (join-old eval_ans (0 1) 1 (0 1) __t8nKY157 __t3EGT159) (join-old eval_ans (0 1) 1 (0 1) __t4j5Q160 va) (join-old clo (0 2 1) 1 (0 2 1) __t3EGT159 cb __t1L8v158) (join-old lambda (0 1 2) 1 (0 1 2) __t1L8v158 x eb)) (head (emit $sup27994x83x0x0x1 (1 4 0 2 3 5 6 7 8 9) __t8nKY157 cb __d0 __t4j5Q160 c ea eb ef va x)) mcfa-counting.slog:84 #f)
  class ReadTask2345 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex2330;  slog::Index** evalindex2331;  slog::Index** eval_ansindex2332;  slog::Index** evalindex2333;  slog::Index** eval_ansindex2334;  slog::Index** eval_ansindex2335;  slog::Index** eval_ansindex2336;  slog::Index** cloindex2337;  slog::Index** lambdaindex2338;  slog::Index** evaldelta2339;  slog::Index** evaldelta2340;  slog::Index** eval_ansdelta2341;  slog::Index** eval_ansdelta2342;  slog::Index** clodelta2343;  slog::Index** lambdadelta2344;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup27994x83x0x0x1");
      std::vector<u16> ord2346({1, 4, 0, 2, 3, 5, 6, 7, 8, 9});
      slog::Relation* readrel2347 = db->getRelation("$sup27994x83x0x0x1");
      head_index[0] = readrel2347->getIndex(ord2346, false);
      outer_rel = db->getRelation("$sup27994x83x0x0x0");
      std::vector<u16> ord2348({1, 2, 0});
      slog::Relation* readrel2349 = db->getRelation("eval");
      evalindex2330 = readrel2349->getIndex(ord2348, false);
      std::vector<u16> ord2350({1, 2, 0});
      slog::Relation* readrel2351 = db->getRelation("eval");
      evalindex2331 = readrel2351->getIndex(ord2350, false);
      std::vector<u16> ord2352({1, 2, 0});
      slog::Relation* readrel2353 = db->getRelation("eval");
      evaldelta2339 = readrel2353->getIndex(ord2352, true);
      std::vector<u16> ord2354({0, 1});
      slog::Relation* readrel2355 = db->getRelation("eval_ans");
      eval_ansindex2332 = readrel2355->getIndex(ord2354, false);
      std::vector<u16> ord2356({1, 2, 0});
      slog::Relation* readrel2357 = db->getRelation("eval");
      evalindex2333 = readrel2357->getIndex(ord2356, false);
      std::vector<u16> ord2358({1, 2, 0});
      slog::Relation* readrel2359 = db->getRelation("eval");
      evaldelta2340 = readrel2359->getIndex(ord2358, true);
      std::vector<u16> ord2360({0, 1});
      slog::Relation* readrel2361 = db->getRelation("eval_ans");
      eval_ansindex2334 = readrel2361->getIndex(ord2360, false);
      std::vector<u16> ord2362({0, 1});
      slog::Relation* readrel2363 = db->getRelation("eval_ans");
      eval_ansindex2335 = readrel2363->getIndex(ord2362, false);
      std::vector<u16> ord2364({0, 1});
      slog::Relation* readrel2365 = db->getRelation("eval_ans");
      eval_ansdelta2341 = readrel2365->getIndex(ord2364, true);
      std::vector<u16> ord2366({0, 1});
      slog::Relation* readrel2367 = db->getRelation("eval_ans");
      eval_ansindex2336 = readrel2367->getIndex(ord2366, false);
      std::vector<u16> ord2368({0, 1});
      slog::Relation* readrel2369 = db->getRelation("eval_ans");
      eval_ansdelta2342 = readrel2369->getIndex(ord2368, true);
      std::vector<u16> ord2370({0, 2, 1});
      slog::Relation* readrel2371 = db->getRelation("clo");
      cloindex2337 = readrel2371->getIndex(ord2370, false);
      std::vector<u16> ord2372({0, 2, 1});
      slog::Relation* readrel2373 = db->getRelation("clo");
      clodelta2343 = readrel2373->getIndex(ord2372, true);
      std::vector<u16> ord2374({0, 1, 2});
      slog::Relation* readrel2375 = db->getRelation("lambda");
      lambdaindex2338 = readrel2375->getIndex(ord2374, false);
      std::vector<u16> ord2376({0, 1, 2});
      slog::Relation* readrel2377 = db->getRelation("lambda");
      lambdadelta2344 = readrel2377->getIndex(ord2376, true);
  
    }
    ReadTask2345(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c152 = _t[0];
        u64 v_c21 = _t[1];
        u64 v_c1 = _t[2];
        u64 v_c3 = _t[3];
        if (!slog::exists_probe<3,2>(evalindex2330, std::array<u64,3>{v_c1, v_c21, 0})) return;
        slog::join_probe_old<3,2>(evalindex2331, evaldelta2339, std::array<u64,3>{v_c3, v_c21, 0}, [&](const std::array<u64,3>& m2378) {
          u64 v_c151 = m2378[2];
          if (!slog::exists_probe<2,1>(eval_ansindex2332, std::array<u64,2>{v_c151, 0})) return;
          slog::join_probe_old<3,2>(evalindex2333, evaldelta2340, std::array<u64,3>{v_c1, v_c21, 0}, [&](const std::array<u64,3>& m2379) {
            u64 v_c153 = m2379[2];
            if (!slog::exists_probe<2,1>(eval_ansindex2334, std::array<u64,2>{v_c153, 0})) return;
            slog::join_probe_old<2,1>(eval_ansindex2335, eval_ansdelta2341, std::array<u64,2>{v_c151, 0}, [&](const std::array<u64,2>& m2380) {
              u64 v_c154 = m2380[1];
              slog::join_probe_old<2,1>(eval_ansindex2336, eval_ansdelta2342, std::array<u64,2>{v_c153, 0}, [&](const std::array<u64,2>& m2381) {
                u64 v_c26 = m2381[1];
                slog::join_probe_old<3,1>(cloindex2337, clodelta2343, std::array<u64,3>{v_c154, 0, 0}, [&](const std::array<u64,3>& m2382) {
                  u64 v_c27 = m2382[1]; u64 v_c155 = m2382[2];
                  slog::join_probe_old<3,1>(lambdaindex2338, lambdadelta2344, std::array<u64,3>{v_c155, 0, 0}, [&](const std::array<u64,3>& m2383) {
                    u64 v_c0 = m2383[1]; u64 v_c29 = m2383[2];
                    ++_fires;
                    slog::emit<10>(head_rel[0], head_index[0], newbatch[0], std::array<u64,10>{v_c151, v_c27, v_c152, v_c153, v_c21, v_c1, v_c29, v_c3, v_c26, v_c0}, std::array<u16,10>{1, 4, 0, 2, 3, 5, 6, 7, 8, 9});
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
        ReadTask2345* _cont = new ReadTask2345(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask2345(db,b), false);
  // (crule (pre) (scan eval_ans __t7ceq259 __t0zen261) (body (join-old eval (0 2 1) 1 (0 2 1) __t7ceq259 c ef) (exists app (1 2 0) 1 ef) (exists eval (2 0 1) 1 c) (join eval (2 0 1) 1 c __5DEq344 __t6ooL258) (join-old app (0 1 2) 2 (0 1 2) __t6ooL258 ef ea) (join-old eval (1 2 0) 2 (1 2 0) ea c __t2S0s262) (join-old eval_ans (0 1) 1 (0 1) __t2S0s262 va) (join-old clo (0 2 1) 1 (0 2 1) __t0zen261 cb __t4JNf263) (exists store (1 0 2) 1 cb) (join-old freevar (1 0) 1 (1 0) __t4JNf263 y) (join-old store (0 1 2) 2 (0 1 2) y cb vy) (join-old lambda (0 1 2) 1 (0 1 2) __t4JNf263 x eb)) (head (emit store (0 1 2) y __t6ooL258 vy) (emit bindev (0 1 2) y __t6ooL258 c)) mcfa-counting.slog:102 #f)
  class ReadTask2404 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex2384;  slog::Index** appindex2385;  slog::Index** evalindex2386;  slog::Index** evalindex2387;  slog::Index** appindex2388;  slog::Index** evalindex2389;  slog::Index** eval_ansindex2390;  slog::Index** cloindex2391;  slog::Index** storeindex2392;  slog::Index** freevarindex2393;  slog::Index** storeindex2394;  slog::Index** lambdaindex2395;  slog::Index** evaldelta2396;  slog::Index** appdelta2397;  slog::Index** evaldelta2398;  slog::Index** eval_ansdelta2399;  slog::Index** clodelta2400;  slog::Index** freevardelta2401;  slog::Index** storedelta2402;  slog::Index** lambdadelta2403;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("store");
      std::vector<u16> ord2405({0, 1, 2});
      slog::Relation* readrel2406 = db->getRelation("store");
      head_index[0] = readrel2406->getIndex(ord2405, false);
      head_rel[1] = db->getRelation("bindev");
      std::vector<u16> ord2407({0, 1, 2});
      slog::Relation* readrel2408 = db->getRelation("bindev");
      head_index[1] = readrel2408->getIndex(ord2407, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord2409({0, 2, 1});
      slog::Relation* readrel2410 = db->getRelation("eval");
      evalindex2384 = readrel2410->getIndex(ord2409, false);
      std::vector<u16> ord2411({0, 2, 1});
      slog::Relation* readrel2412 = db->getRelation("eval");
      evaldelta2396 = readrel2412->getIndex(ord2411, true);
      std::vector<u16> ord2413({1, 2, 0});
      slog::Relation* readrel2414 = db->getRelation("app");
      appindex2385 = readrel2414->getIndex(ord2413, false);
      std::vector<u16> ord2415({2, 0, 1});
      slog::Relation* readrel2416 = db->getRelation("eval");
      evalindex2386 = readrel2416->getIndex(ord2415, false);
      std::vector<u16> ord2417({2, 0, 1});
      slog::Relation* readrel2418 = db->getRelation("eval");
      evalindex2387 = readrel2418->getIndex(ord2417, false);
      std::vector<u16> ord2419({0, 1, 2});
      slog::Relation* readrel2420 = db->getRelation("app");
      appindex2388 = readrel2420->getIndex(ord2419, false);
      std::vector<u16> ord2421({0, 1, 2});
      slog::Relation* readrel2422 = db->getRelation("app");
      appdelta2397 = readrel2422->getIndex(ord2421, true);
      std::vector<u16> ord2423({1, 2, 0});
      slog::Relation* readrel2424 = db->getRelation("eval");
      evalindex2389 = readrel2424->getIndex(ord2423, false);
      std::vector<u16> ord2425({1, 2, 0});
      slog::Relation* readrel2426 = db->getRelation("eval");
      evaldelta2398 = readrel2426->getIndex(ord2425, true);
      std::vector<u16> ord2427({0, 1});
      slog::Relation* readrel2428 = db->getRelation("eval_ans");
      eval_ansindex2390 = readrel2428->getIndex(ord2427, false);
      std::vector<u16> ord2429({0, 1});
      slog::Relation* readrel2430 = db->getRelation("eval_ans");
      eval_ansdelta2399 = readrel2430->getIndex(ord2429, true);
      std::vector<u16> ord2431({0, 2, 1});
      slog::Relation* readrel2432 = db->getRelation("clo");
      cloindex2391 = readrel2432->getIndex(ord2431, false);
      std::vector<u16> ord2433({0, 2, 1});
      slog::Relation* readrel2434 = db->getRelation("clo");
      clodelta2400 = readrel2434->getIndex(ord2433, true);
      std::vector<u16> ord2435({1, 0, 2});
      slog::Relation* readrel2436 = db->getRelation("store");
      storeindex2392 = readrel2436->getIndex(ord2435, false);
      std::vector<u16> ord2437({1, 0});
      slog::Relation* readrel2438 = db->getRelation("freevar");
      freevarindex2393 = readrel2438->getIndex(ord2437, false);
      std::vector<u16> ord2439({1, 0});
      slog::Relation* readrel2440 = db->getRelation("freevar");
      freevardelta2401 = readrel2440->getIndex(ord2439, true);
      std::vector<u16> ord2441({0, 1, 2});
      slog::Relation* readrel2442 = db->getRelation("store");
      storeindex2394 = readrel2442->getIndex(ord2441, false);
      std::vector<u16> ord2443({0, 1, 2});
      slog::Relation* readrel2444 = db->getRelation("store");
      storedelta2402 = readrel2444->getIndex(ord2443, true);
      std::vector<u16> ord2445({0, 1, 2});
      slog::Relation* readrel2446 = db->getRelation("lambda");
      lambdaindex2395 = readrel2446->getIndex(ord2445, false);
      std::vector<u16> ord2447({0, 1, 2});
      slog::Relation* readrel2448 = db->getRelation("lambda");
      lambdadelta2403 = readrel2448->getIndex(ord2447, true);
  
    }
    ReadTask2404(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c180 = _t[0];
        u64 v_c179 = _t[1];
        slog::join_probe_old<3,1>(evalindex2384, evaldelta2396, std::array<u64,3>{v_c180, 0, 0}, [&](const std::array<u64,3>& m2449) {
          u64 v_c21 = m2449[1]; u64 v_c3 = m2449[2];
          if (!slog::exists_probe<3,1>(appindex2385, std::array<u64,3>{v_c3, 0, 0})) return;
          if (!slog::exists_probe<3,1>(evalindex2386, std::array<u64,3>{v_c21, 0, 0})) return;
          slog::join_probe<3,1>(evalindex2387, std::array<u64,3>{v_c21, 0, 0}, [&](const std::array<u64,3>& m2450) {
            u64 v_c181 = m2450[1]; u64 v_c182 = m2450[2];
            slog::join_probe_old<3,2>(appindex2388, appdelta2397, std::array<u64,3>{v_c182, v_c3, 0}, [&](const std::array<u64,3>& m2451) {
              u64 v_c1 = m2451[2];
              slog::join_probe_old<3,2>(evalindex2389, evaldelta2398, std::array<u64,3>{v_c1, v_c21, 0}, [&](const std::array<u64,3>& m2452) {
                u64 v_c183 = m2452[2];
                slog::join_probe_old<2,1>(eval_ansindex2390, eval_ansdelta2399, std::array<u64,2>{v_c183, 0}, [&](const std::array<u64,2>& m2453) {
                  u64 v_c26 = m2453[1];
                  slog::join_probe_old<3,1>(cloindex2391, clodelta2400, std::array<u64,3>{v_c179, 0, 0}, [&](const std::array<u64,3>& m2454) {
                    u64 v_c27 = m2454[1]; u64 v_c178 = m2454[2];
                    if (!slog::exists_probe<3,1>(storeindex2392, std::array<u64,3>{v_c27, 0, 0})) return;
                    slog::join_probe_old<2,1>(freevarindex2393, freevardelta2401, std::array<u64,2>{v_c178, 0}, [&](const std::array<u64,2>& m2455) {
                      u64 v_c71 = m2455[1];
                      slog::join_probe_old<3,2>(storeindex2394, storedelta2402, std::array<u64,3>{v_c71, v_c27, 0}, [&](const std::array<u64,3>& m2456) {
                        u64 v_c177 = m2456[2];
                        slog::join_probe_old<3,1>(lambdaindex2395, lambdadelta2403, std::array<u64,3>{v_c178, 0, 0}, [&](const std::array<u64,3>& m2457) {
                          u64 v_c0 = m2457[1]; u64 v_c29 = m2457[2];
                          ++_fires;
                          slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c71, v_c182, v_c177}, std::array<u16,3>{0, 1, 2});
                          slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c71, v_c182, v_c21}, std::array<u16,3>{0, 1, 2});
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
  
      if (_fires) db->bumpFires("mcfa-counting.slog:102", "delta:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask2404* _cont = new ReadTask2404(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask2404(db,b), false);
  // (crule (pre (let __tconst9zoW125 const7c7d2cfc66f4d976987d2d20) (let __tconst0vRf84 conste58dec6bca6f63ef79c3b755) (let __tconst4V4L122 const6bc0ba365ada70df115e1785) (let __tconst4Zcr91 const9a67f28c6b77e842f439a84a) (let __tconst82U8119 consta8180db1c2f300980314f910) (let __tconst4BKz104 const0f8748be649f8ee4066bb1d7) (let __tconst3wDH116 constd5f017533ea574d5f9b3400c) (let __tconst3ktF111 const990b444cbd47632035b2fa1a) (let __tconst5nWJ102 const4f84f41d89b6b717419b4eaa)) (seeded) (body (join ref (1 0) 1 __tconst0vRf84 __t2duR83) (exists ref (1 0) 1 __tconst4Zcr91) (exists ref (1 0) 1 __tconst9zoW125) (exists lambda (1 2 0) 1 __tconst4Zcr91) (exists ref (1 0) 1 __tconst4V4L122) (exists ref (1 0) 1 __tconst4BKz104) (exists lambda (1 2 0) 1 __tconst4BKz104) (exists ref (1 0) 1 __tconst3wDH116) (exists ref (1 0) 1 __tconst5nWJ102) (exists lambda (1 2 0) 1 __tconst5nWJ102) (exists ref (1 0) 1 __tconst3ktF111) (exists lambda (1 2 0) 1 __tconst3ktF111) (exists lambda (1 2 0) 1 __tconst3wDH116) (exists lambda (1 2 0) 1 __tconst82U8119) (exists lambda (1 2 0) 1 __tconst4V4L122) (exists lambda (1 2 0) 1 __tconst9zoW125) (join lambda (1 2 0) 2 __tconst0vRf84 __t2duR83 __t87vL85) (join ref (1 0) 1 __tconst4Zcr91 __t0C9F87) (exists app (2 0 1) 1 __t0C9F87) (join ref (1 0) 1 __tconst9zoW125 __t3Q2G89) (join app (1 2 0) 2 __t3Q2G89 __t0C9F87 __t2Eqd90) (join lambda (1 2 0) 2 __tconst4Zcr91 __t2Eqd90 __t3pgm92) (exists app (2 0 1) 1 __t3pgm92) (join ref (1 0) 1 __tconst4V4L122 __t7aew98) (exists app (1 2 0) 1 __t7aew98) (join ref (1 0) 1 __tconst4BKz104 __t8C0a94) (join lambda (1 2 0) 2 __tconst4BKz104 __t8C0a94 __t4fDK96) (join app (1 2 0) 2 __t7aew98 __t4fDK96 __t7TEO99) (exists app (2 0 1) 1 __t7TEO99) (join ref (1 0) 1 __tconst3wDH116 __t3wir114) (exists app (1 2 0) 1 __t3wir114) (join ref (1 0) 1 __tconst5nWJ102 __t5MaG101) (join lambda (1 2 0) 2 __tconst5nWJ102 __t5MaG101 __t35jA103) (join lambda (1 2 0) 2 __tconst4BKz104 __t35jA103 __t6RuY105) (join app (1 2 0) 2 __t7aew98 __t6RuY105 __t2Z7m108) (exists app (2 0 1) 1 __t2Z7m108) (join ref (1 0) 1 __tconst3ktF111 __t7ohz110) (join lambda (1 2 0) 2 __tconst3ktF111 __t7ohz110 __t8GWA112) (join app (1 2 0) 2 __t3wir114 __t8GWA112 __t44OM115) (join lambda (1 2 0) 2 __tconst3wDH116 __t44OM115 __t7CwH117) (join app (1 2 0) 2 __t7CwH117 __t2Z7m108 __t50Kk118) (join lambda (1 2 0) 2 __tconst82U8119 __t50Kk118 __t3SEs120) (join app (1 2 0) 2 __t3SEs120 __t7TEO99 __t1GdP121) (join lambda (1 2 0) 2 __tconst4V4L122 __t1GdP121 __t5iMg123) (join app (1 2 0) 2 __t5iMg123 __t3pgm92 __t3cyj124) (join lambda (1 2 0) 2 __tconst9zoW125 __t3cyj124 __t4GT8126)) (head (mkstruct app (1 2 0) __t6xIu127 __t4GT8126 __t87vL85)) mcfa-counting.slog:241 #f)
  class ReadTask2504 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex2458;  slog::Index** refindex2459;  slog::Index** refindex2460;  slog::Index** lambdaindex2461;  slog::Index** refindex2462;  slog::Index** refindex2463;  slog::Index** lambdaindex2464;  slog::Index** refindex2465;  slog::Index** refindex2466;  slog::Index** lambdaindex2467;  slog::Index** refindex2468;  slog::Index** lambdaindex2469;  slog::Index** lambdaindex2470;  slog::Index** lambdaindex2471;  slog::Index** lambdaindex2472;  slog::Index** lambdaindex2473;  slog::Index** lambdaindex2474;  slog::Index** refindex2475;  slog::Index** appindex2476;  slog::Index** refindex2477;  slog::Index** appindex2478;  slog::Index** lambdaindex2479;  slog::Index** appindex2480;  slog::Index** refindex2481;  slog::Index** appindex2482;  slog::Index** refindex2483;  slog::Index** lambdaindex2484;  slog::Index** appindex2485;  slog::Index** appindex2486;  slog::Index** refindex2487;  slog::Index** appindex2488;  slog::Index** refindex2489;  slog::Index** lambdaindex2490;  slog::Index** lambdaindex2491;  slog::Index** appindex2492;  slog::Index** appindex2493;  slog::Index** refindex2494;  slog::Index** lambdaindex2495;  slog::Index** appindex2496;  slog::Index** lambdaindex2497;  slog::Index** appindex2498;  slog::Index** lambdaindex2499;  slog::Index** appindex2500;  slog::Index** lambdaindex2501;  slog::Index** appindex2502;  slog::Index** lambdaindex2503;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord2505({1, 2, 0});
      slog::Relation* readrel2506 = db->getRelation("app");
      head_index[0] = readrel2506->getIndex(ord2505, false);
      std::vector<u16> ord2507({1, 0});
      slog::Relation* readrel2508 = db->getRelation("ref");
      refindex2458 = readrel2508->getIndex(ord2507, false);
      std::vector<u16> ord2509({1, 0});
      slog::Relation* readrel2510 = db->getRelation("ref");
      refindex2459 = readrel2510->getIndex(ord2509, false);
      std::vector<u16> ord2511({1, 0});
      slog::Relation* readrel2512 = db->getRelation("ref");
      refindex2460 = readrel2512->getIndex(ord2511, false);
      std::vector<u16> ord2513({1, 2, 0});
      slog::Relation* readrel2514 = db->getRelation("lambda");
      lambdaindex2461 = readrel2514->getIndex(ord2513, false);
      std::vector<u16> ord2515({1, 0});
      slog::Relation* readrel2516 = db->getRelation("ref");
      refindex2462 = readrel2516->getIndex(ord2515, false);
      std::vector<u16> ord2517({1, 0});
      slog::Relation* readrel2518 = db->getRelation("ref");
      refindex2463 = readrel2518->getIndex(ord2517, false);
      std::vector<u16> ord2519({1, 2, 0});
      slog::Relation* readrel2520 = db->getRelation("lambda");
      lambdaindex2464 = readrel2520->getIndex(ord2519, false);
      std::vector<u16> ord2521({1, 0});
      slog::Relation* readrel2522 = db->getRelation("ref");
      refindex2465 = readrel2522->getIndex(ord2521, false);
      std::vector<u16> ord2523({1, 0});
      slog::Relation* readrel2524 = db->getRelation("ref");
      refindex2466 = readrel2524->getIndex(ord2523, false);
      std::vector<u16> ord2525({1, 2, 0});
      slog::Relation* readrel2526 = db->getRelation("lambda");
      lambdaindex2467 = readrel2526->getIndex(ord2525, false);
      std::vector<u16> ord2527({1, 0});
      slog::Relation* readrel2528 = db->getRelation("ref");
      refindex2468 = readrel2528->getIndex(ord2527, false);
      std::vector<u16> ord2529({1, 2, 0});
      slog::Relation* readrel2530 = db->getRelation("lambda");
      lambdaindex2469 = readrel2530->getIndex(ord2529, false);
      std::vector<u16> ord2531({1, 2, 0});
      slog::Relation* readrel2532 = db->getRelation("lambda");
      lambdaindex2470 = readrel2532->getIndex(ord2531, false);
      std::vector<u16> ord2533({1, 2, 0});
      slog::Relation* readrel2534 = db->getRelation("lambda");
      lambdaindex2471 = readrel2534->getIndex(ord2533, false);
      std::vector<u16> ord2535({1, 2, 0});
      slog::Relation* readrel2536 = db->getRelation("lambda");
      lambdaindex2472 = readrel2536->getIndex(ord2535, false);
      std::vector<u16> ord2537({1, 2, 0});
      slog::Relation* readrel2538 = db->getRelation("lambda");
      lambdaindex2473 = readrel2538->getIndex(ord2537, false);
      std::vector<u16> ord2539({1, 2, 0});
      slog::Relation* readrel2540 = db->getRelation("lambda");
      lambdaindex2474 = readrel2540->getIndex(ord2539, false);
      std::vector<u16> ord2541({1, 0});
      slog::Relation* readrel2542 = db->getRelation("ref");
      refindex2475 = readrel2542->getIndex(ord2541, false);
      std::vector<u16> ord2543({2, 0, 1});
      slog::Relation* readrel2544 = db->getRelation("app");
      appindex2476 = readrel2544->getIndex(ord2543, false);
      std::vector<u16> ord2545({1, 0});
      slog::Relation* readrel2546 = db->getRelation("ref");
      refindex2477 = readrel2546->getIndex(ord2545, false);
      std::vector<u16> ord2547({1, 2, 0});
      slog::Relation* readrel2548 = db->getRelation("app");
      appindex2478 = readrel2548->getIndex(ord2547, false);
      std::vector<u16> ord2549({1, 2, 0});
      slog::Relation* readrel2550 = db->getRelation("lambda");
      lambdaindex2479 = readrel2550->getIndex(ord2549, false);
      std::vector<u16> ord2551({2, 0, 1});
      slog::Relation* readrel2552 = db->getRelation("app");
      appindex2480 = readrel2552->getIndex(ord2551, false);
      std::vector<u16> ord2553({1, 0});
      slog::Relation* readrel2554 = db->getRelation("ref");
      refindex2481 = readrel2554->getIndex(ord2553, false);
      std::vector<u16> ord2555({1, 2, 0});
      slog::Relation* readrel2556 = db->getRelation("app");
      appindex2482 = readrel2556->getIndex(ord2555, false);
      std::vector<u16> ord2557({1, 0});
      slog::Relation* readrel2558 = db->getRelation("ref");
      refindex2483 = readrel2558->getIndex(ord2557, false);
      std::vector<u16> ord2559({1, 2, 0});
      slog::Relation* readrel2560 = db->getRelation("lambda");
      lambdaindex2484 = readrel2560->getIndex(ord2559, false);
      std::vector<u16> ord2561({1, 2, 0});
      slog::Relation* readrel2562 = db->getRelation("app");
      appindex2485 = readrel2562->getIndex(ord2561, false);
      std::vector<u16> ord2563({2, 0, 1});
      slog::Relation* readrel2564 = db->getRelation("app");
      appindex2486 = readrel2564->getIndex(ord2563, false);
      std::vector<u16> ord2565({1, 0});
      slog::Relation* readrel2566 = db->getRelation("ref");
      refindex2487 = readrel2566->getIndex(ord2565, false);
      std::vector<u16> ord2567({1, 2, 0});
      slog::Relation* readrel2568 = db->getRelation("app");
      appindex2488 = readrel2568->getIndex(ord2567, false);
      std::vector<u16> ord2569({1, 0});
      slog::Relation* readrel2570 = db->getRelation("ref");
      refindex2489 = readrel2570->getIndex(ord2569, false);
      std::vector<u16> ord2571({1, 2, 0});
      slog::Relation* readrel2572 = db->getRelation("lambda");
      lambdaindex2490 = readrel2572->getIndex(ord2571, false);
      std::vector<u16> ord2573({1, 2, 0});
      slog::Relation* readrel2574 = db->getRelation("lambda");
      lambdaindex2491 = readrel2574->getIndex(ord2573, false);
      std::vector<u16> ord2575({1, 2, 0});
      slog::Relation* readrel2576 = db->getRelation("app");
      appindex2492 = readrel2576->getIndex(ord2575, false);
      std::vector<u16> ord2577({2, 0, 1});
      slog::Relation* readrel2578 = db->getRelation("app");
      appindex2493 = readrel2578->getIndex(ord2577, false);
      std::vector<u16> ord2579({1, 0});
      slog::Relation* readrel2580 = db->getRelation("ref");
      refindex2494 = readrel2580->getIndex(ord2579, false);
      std::vector<u16> ord2581({1, 2, 0});
      slog::Relation* readrel2582 = db->getRelation("lambda");
      lambdaindex2495 = readrel2582->getIndex(ord2581, false);
      std::vector<u16> ord2583({1, 2, 0});
      slog::Relation* readrel2584 = db->getRelation("app");
      appindex2496 = readrel2584->getIndex(ord2583, false);
      std::vector<u16> ord2585({1, 2, 0});
      slog::Relation* readrel2586 = db->getRelation("lambda");
      lambdaindex2497 = readrel2586->getIndex(ord2585, false);
      std::vector<u16> ord2587({1, 2, 0});
      slog::Relation* readrel2588 = db->getRelation("app");
      appindex2498 = readrel2588->getIndex(ord2587, false);
      std::vector<u16> ord2589({1, 2, 0});
      slog::Relation* readrel2590 = db->getRelation("lambda");
      lambdaindex2499 = readrel2590->getIndex(ord2589, false);
      std::vector<u16> ord2591({1, 2, 0});
      slog::Relation* readrel2592 = db->getRelation("app");
      appindex2500 = readrel2592->getIndex(ord2591, false);
      std::vector<u16> ord2593({1, 2, 0});
      slog::Relation* readrel2594 = db->getRelation("lambda");
      lambdaindex2501 = readrel2594->getIndex(ord2593, false);
      std::vector<u16> ord2595({1, 2, 0});
      slog::Relation* readrel2596 = db->getRelation("app");
      appindex2502 = readrel2596->getIndex(ord2595, false);
      std::vector<u16> ord2597({1, 2, 0});
      slog::Relation* readrel2598 = db->getRelation("lambda");
      lambdaindex2503 = readrel2598->getIndex(ord2597, false);
  
    }
    ReadTask2504(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c93 = v_const7c7d2cfc66f4d976987d2d20;
      u64 v_c97 = v_conste58dec6bca6f63ef79c3b755;
      u64 v_c94 = v_const6bc0ba365ada70df115e1785;
      u64 v_c96 = v_const9a67f28c6b77e842f439a84a;
      u64 v_c95 = v_consta8180db1c2f300980314f910;
      u64 v_c98 = v_const0f8748be649f8ee4066bb1d7;
      u64 v_c99 = v_constd5f017533ea574d5f9b3400c;
      u64 v_c100 = v_const990b444cbd47632035b2fa1a;
      u64 v_c101 = v_const4f84f41d89b6b717419b4eaa;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex2458, std::array<u64,2>{v_c97, 0}, [&](const std::array<u64,2>& m2599) {
        u64 v_c109 = m2599[1];
        if (!slog::exists_probe<2,1>(refindex2459, std::array<u64,2>{v_c96, 0})) return;
        if (!slog::exists_probe<2,1>(refindex2460, std::array<u64,2>{v_c93, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex2461, std::array<u64,3>{v_c96, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex2462, std::array<u64,2>{v_c94, 0})) return;
        if (!slog::exists_probe<2,1>(refindex2463, std::array<u64,2>{v_c98, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex2464, std::array<u64,3>{v_c98, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex2465, std::array<u64,2>{v_c99, 0})) return;
        if (!slog::exists_probe<2,1>(refindex2466, std::array<u64,2>{v_c101, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex2467, std::array<u64,3>{v_c101, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex2468, std::array<u64,2>{v_c100, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex2469, std::array<u64,3>{v_c100, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex2470, std::array<u64,3>{v_c99, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex2471, std::array<u64,3>{v_c95, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex2472, std::array<u64,3>{v_c94, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex2473, std::array<u64,3>{v_c93, 0, 0})) return;
        slog::join_probe<3,2>(lambdaindex2474, std::array<u64,3>{v_c97, v_c109, 0}, [&](const std::array<u64,3>& m2600) {
          u64 v_c110 = m2600[2];
          slog::join_probe<2,1>(refindex2475, std::array<u64,2>{v_c96, 0}, [&](const std::array<u64,2>& m2601) {
            u64 v_c111 = m2601[1];
            if (!slog::exists_probe<3,1>(appindex2476, std::array<u64,3>{v_c111, 0, 0})) return;
            slog::join_probe<2,1>(refindex2477, std::array<u64,2>{v_c93, 0}, [&](const std::array<u64,2>& m2602) {
              u64 v_c112 = m2602[1];
              slog::join_probe<3,2>(appindex2478, std::array<u64,3>{v_c112, v_c111, 0}, [&](const std::array<u64,3>& m2603) {
                u64 v_c113 = m2603[2];
                slog::join_probe<3,2>(lambdaindex2479, std::array<u64,3>{v_c96, v_c113, 0}, [&](const std::array<u64,3>& m2604) {
                  u64 v_c114 = m2604[2];
                  if (!slog::exists_probe<3,1>(appindex2480, std::array<u64,3>{v_c114, 0, 0})) return;
                  slog::join_probe<2,1>(refindex2481, std::array<u64,2>{v_c94, 0}, [&](const std::array<u64,2>& m2605) {
                    u64 v_c106 = m2605[1];
                    if (!slog::exists_probe<3,1>(appindex2482, std::array<u64,3>{v_c106, 0, 0})) return;
                    slog::join_probe<2,1>(refindex2483, std::array<u64,2>{v_c98, 0}, [&](const std::array<u64,2>& m2606) {
                      u64 v_c108 = m2606[1];
                      slog::join_probe<3,2>(lambdaindex2484, std::array<u64,3>{v_c98, v_c108, 0}, [&](const std::array<u64,3>& m2607) {
                        u64 v_c107 = m2607[2];
                        slog::join_probe<3,2>(appindex2485, std::array<u64,3>{v_c106, v_c107, 0}, [&](const std::array<u64,3>& m2608) {
                          u64 v_c104 = m2608[2];
                          if (!slog::exists_probe<3,1>(appindex2486, std::array<u64,3>{v_c104, 0, 0})) return;
                          slog::join_probe<2,1>(refindex2487, std::array<u64,2>{v_c99, 0}, [&](const std::array<u64,2>& m2609) {
                            u64 v_c115 = m2609[1];
                            if (!slog::exists_probe<3,1>(appindex2488, std::array<u64,3>{v_c115, 0, 0})) return;
                            slog::join_probe<2,1>(refindex2489, std::array<u64,2>{v_c101, 0}, [&](const std::array<u64,2>& m2610) {
                              u64 v_c116 = m2610[1];
                              slog::join_probe<3,2>(lambdaindex2490, std::array<u64,3>{v_c101, v_c116, 0}, [&](const std::array<u64,3>& m2611) {
                                u64 v_c117 = m2611[2];
                                slog::join_probe<3,2>(lambdaindex2491, std::array<u64,3>{v_c98, v_c117, 0}, [&](const std::array<u64,3>& m2612) {
                                  u64 v_c118 = m2612[2];
                                  slog::join_probe<3,2>(appindex2492, std::array<u64,3>{v_c106, v_c118, 0}, [&](const std::array<u64,3>& m2613) {
                                    u64 v_c119 = m2613[2];
                                    if (!slog::exists_probe<3,1>(appindex2493, std::array<u64,3>{v_c119, 0, 0})) return;
                                    slog::join_probe<2,1>(refindex2494, std::array<u64,2>{v_c100, 0}, [&](const std::array<u64,2>& m2614) {
                                      u64 v_c123 = m2614[1];
                                      slog::join_probe<3,2>(lambdaindex2495, std::array<u64,3>{v_c100, v_c123, 0}, [&](const std::array<u64,3>& m2615) {
                                        u64 v_c122 = m2615[2];
                                        slog::join_probe<3,2>(appindex2496, std::array<u64,3>{v_c115, v_c122, 0}, [&](const std::array<u64,3>& m2616) {
                                          u64 v_c121 = m2616[2];
                                          slog::join_probe<3,2>(lambdaindex2497, std::array<u64,3>{v_c99, v_c121, 0}, [&](const std::array<u64,3>& m2617) {
                                            u64 v_c120 = m2617[2];
                                            slog::join_probe<3,2>(appindex2498, std::array<u64,3>{v_c120, v_c119, 0}, [&](const std::array<u64,3>& m2618) {
                                              u64 v_c105 = m2618[2];
                                              slog::join_probe<3,2>(lambdaindex2499, std::array<u64,3>{v_c95, v_c105, 0}, [&](const std::array<u64,3>& m2619) {
                                                u64 v_c103 = m2619[2];
                                                slog::join_probe<3,2>(appindex2500, std::array<u64,3>{v_c103, v_c104, 0}, [&](const std::array<u64,3>& m2620) {
                                                  u64 v_c102 = m2620[2];
                                                  slog::join_probe<3,2>(lambdaindex2501, std::array<u64,3>{v_c94, v_c102, 0}, [&](const std::array<u64,3>& m2621) {
                                                    u64 v_c173 = m2621[2];
                                                    slog::join_probe<3,2>(appindex2502, std::array<u64,3>{v_c173, v_c114, 0}, [&](const std::array<u64,3>& m2622) {
                                                      u64 v_c174 = m2622[2];
                                                      slog::join_probe<3,2>(lambdaindex2503, std::array<u64,3>{v_c93, v_c174, 0}, [&](const std::array<u64,3>& m2623) {
                                                        u64 v_c175 = m2623[2];
                                                        ++_fires;
                                                        slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c175, v_c110}, std::array<u16,3>{1, 2, 0});
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
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:241", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask2504(db,b));
}

