
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const0aa6f87434af0222b916e97a;
extern u64 v_const0f8748be649f8ee4066bb1d7;
extern u64 v_const227d34ceeba7a29aada993d4;
extern u64 v_const229c0b7aa8a7eb4055f5a3d0;
extern u64 v_const361d5df359e0d7681220d09d;
extern u64 v_const3a82152bd1402931076fe2d7;
extern u64 v_const4492fd5fa4baacfebd29f5e5;
extern u64 v_const4a8acfc71441e0695ffcf5b3;
extern u64 v_const4d5ce1398140fbe27561181f;
extern u64 v_const4e3b5454cf93e32fad90650d;
extern u64 v_const4f84f41d89b6b717419b4eaa;
extern u64 v_const576506f61f53440f1edd95d2;
extern u64 v_const59ba3256d223f0d0a00d0633;
extern u64 v_const615ad01b1c532bb6634df115;
extern u64 v_const66518c0c1b3a5a0b09ae2ef1;
extern u64 v_const6bc0ba365ada70df115e1785;
extern u64 v_const6cf13cc59dcbe759113f68a4;
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
extern u64 v_conste58dec6bca6f63ef79c3b755;
extern u64 v_consteb793a6f75d6cfe49d3c2c90;
extern u64 v_constf700a82e218a86de572e1f7f;


void slog_rules_c999a70626a4be699(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre) (scan app __t0neE161 ef ea) (body (join eval (1 2 0) 1 __t0neE161 c __9gNV361) (join freevar (0 1) 0 y __t3DWB162) (join store (0 1 2) 1 y cb vy) (join lambda (0 1 2) 1 __t3DWB162 x eb)) (head (mkstruct eval (1 2 0) __1Zia362 ef c)) mcfa-counting.slog:102 #f)
  class ReadTask4 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex0;  slog::Index** freevarindex1;  slog::Index** storeindex2;  slog::Index** lambdaindex3;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("app");
      std::vector<u16> ord5({1, 2, 0});
      slog::Relation* readrel6 = db->getRelation("eval");
      evalindex0 = readrel6->getIndex(ord5, false);
      std::vector<u16> ord7({0, 1});
      slog::Relation* readrel8 = db->getRelation("freevar");
      freevarindex1 = readrel8->getIndex(ord7, false);
      std::vector<u16> ord9({0, 1, 2});
      slog::Relation* readrel10 = db->getRelation("store");
      storeindex2 = readrel10->getIndex(ord9, false);
      std::vector<u16> ord11({0, 1, 2});
      slog::Relation* readrel12 = db->getRelation("lambda");
      lambdaindex3 = readrel12->getIndex(ord11, false);
  
    }
    ReadTask4(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        slog::join_probe<3,1>(evalindex0, std::array<u64,3>{v_c0, 0, 0}, [&](const std::array<u64,3>& m13) {
          u64 v_c3 = m13[1]; u64 v_c4 = m13[2];
          slog::join_all<2>(freevarindex1, [&](const std::array<u64,2>& m14) {
            u64 v_c5 = m14[0]; u64 v_c6 = m14[1];
            slog::join_probe<3,1>(storeindex2, std::array<u64,3>{v_c5, 0, 0}, [&](const std::array<u64,3>& m15) {
              u64 v_c7 = m15[1]; u64 v_c8 = m15[2];
              slog::join_probe<3,1>(lambdaindex3, std::array<u64,3>{v_c6, 0, 0}, [&](const std::array<u64,3>& m16) {
                u64 v_c9 = m16[1]; u64 v_c10 = m16[2];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c1, v_c3}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:102", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask4* _cont = new ReadTask4(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask4(db,b), false);
  // (crule (pre (let __tconst9zoW125 const7c7d2cfc66f4d976987d2d20) (let __tconst4V4L122 const6bc0ba365ada70df115e1785) (let __tconst82U8119 consta8180db1c2f300980314f910) (let __tconst3wDH116 constd5f017533ea574d5f9b3400c) (let __tconst3ktF111 const990b444cbd47632035b2fa1a) (let __tconst4BKz104 const0f8748be649f8ee4066bb1d7) (let __tconst5nWJ102 const4f84f41d89b6b717419b4eaa) (let __tconst4Zcr91 const9a67f28c6b77e842f439a84a) (let __tconst0vRf84 conste58dec6bca6f63ef79c3b755)) (once) (body) (head (mkstruct ref (1 0) __t3wir114 __tconst3wDH116) (mkstruct ref (1 0) __t7ohz110 __tconst3ktF111) (mkstruct ref (1 0) __t5MaG101 __tconst5nWJ102) (mkstruct ref (1 0) __t7aew98 __tconst4V4L122) (mkstruct ref (1 0) __t8C0a94 __tconst4BKz104) (mkstruct ref (1 0) __t3Q2G89 __tconst9zoW125) (mkstruct ref (1 0) __t0C9F87 __tconst4Zcr91) (mkstruct ref (1 0) __t2duR83 __tconst0vRf84)) mcfa-counting.slog:241 #f)
  class ReadTask17 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[8];
    slog::Index** head_index[8];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ref");
      head_rel[1] = db->getRelation("ref");
      head_rel[2] = db->getRelation("ref");
      head_rel[3] = db->getRelation("ref");
      head_rel[4] = db->getRelation("ref");
      head_rel[5] = db->getRelation("ref");
      head_rel[6] = db->getRelation("ref");
      head_rel[7] = db->getRelation("ref");
  
    }
    ReadTask17(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c11 = v_const7c7d2cfc66f4d976987d2d20;
      u64 v_c12 = v_const6bc0ba365ada70df115e1785;
      u64 v_c13 = v_consta8180db1c2f300980314f910;
      u64 v_c14 = v_constd5f017533ea574d5f9b3400c;
      u64 v_c15 = v_const990b444cbd47632035b2fa1a;
      u64 v_c16 = v_const0f8748be649f8ee4066bb1d7;
      u64 v_c17 = v_const4f84f41d89b6b717419b4eaa;
      u64 v_c18 = v_const9a67f28c6b77e842f439a84a;
      u64 v_c19 = v_conste58dec6bca6f63ef79c3b755;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[8];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
      newbatch[4] = new slog::InsertBatch();
      newbatch[5] = new slog::InsertBatch();
      newbatch[6] = new slog::InsertBatch();
      newbatch[7] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c14}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c15}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[2], newbatch[2], std::array<u64,1>{v_c17}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[3], newbatch[3], std::array<u64,1>{v_c12}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[4], newbatch[4], std::array<u64,1>{v_c16}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[5], newbatch[5], std::array<u64,1>{v_c11}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[6], newbatch[6], std::array<u64,1>{v_c18}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[7], newbatch[7], std::array<u64,1>{v_c19}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
        head_rel[5]->sendBatch(newbatch[5]);
        head_rel[6]->sendBatch(newbatch[6]);
        head_rel[7]->sendBatch(newbatch[7]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:241", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask17(db,b), true);
  // (crule (pre (let __tconst8xRt151 const3a82152bd1402931076fe2d7) (let __tconst0zC2144 const4e3b5454cf93e32fad90650d) (let __tconst3Taj142 constdc1bb6655fb38bdb032e3754) (let __tconst8eg8132 const361d5df359e0d7681220d09d)) (once) (body) (head (mkstruct ref (1 0) __t1g2P147 __tconst8xRt151) (mkstruct ref (1 0) __t7VSc137 __tconst0zC2144) (mkstruct ref (1 0) __t93Xi135 __tconst3Taj142) (mkstruct ref (1 0) __t19JM131 __tconst8eg8132)) mcfa-counting.slog:224 #f)
  class ReadTask18 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[4];
    slog::Index** head_index[4];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ref");
      head_rel[1] = db->getRelation("ref");
      head_rel[2] = db->getRelation("ref");
      head_rel[3] = db->getRelation("ref");
  
    }
    ReadTask18(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c20 = v_const3a82152bd1402931076fe2d7;
      u64 v_c21 = v_const4e3b5454cf93e32fad90650d;
      u64 v_c22 = v_constdc1bb6655fb38bdb032e3754;
      u64 v_c23 = v_const361d5df359e0d7681220d09d;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[4];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c20}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c21}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[2], newbatch[2], std::array<u64,1>{v_c22}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[3], newbatch[3], std::array<u64,1>{v_c23}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:224", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask18(db,b), true);
  // (crule (pre (let __tconst2x2f244 consta32d5a443def48e6d64c6f4b) (let __tconst4Sko246 consteb793a6f75d6cfe49d3c2c90) (let __tconst4N2q248 constaaaad65142343c54348db5d0) (let __tconst7sqz226 const7b8fd91ee9ff10cfbb8066bf) (let __tconst1EUj230 const615ad01b1c532bb6634df115) (let __tconst2VuQ234 const4492fd5fa4baacfebd29f5e5)) (scan app __t5h6K243 __t4wvK242 __t3pbc237) (body (join ref (0 1) 2 __t3pbc237 __tconst2x2f244) (exists ref (1 0) 1 __tconst4Sko246) (exists ref (1 0) 1 __tconst2VuQ234) (exists lambda (1 2 0) 1 __tconst2VuQ234) (exists ref (1 0) 1 __tconst1EUj230) (exists lambda (1 2 0) 1 __tconst1EUj230) (exists ref (1 0) 1 __tconst7sqz226) (exists lambda (1 2 0) 1 __tconst7sqz226) (join ref (1 0) 1 __tconst4N2q248 __t6KL4241) (join app (0 1 2) 2 __t4wvK242 __t6KL4241 __t16jv239) (join ref (0 1) 2 __t16jv239 __tconst4Sko246) (join ref (1 0) 1 __tconst2VuQ234 __t2PLq233) (join lambda (1 2 0) 2 __tconst2VuQ234 __t2PLq233 __t45rU235) (join ref (1 0) 1 __tconst1EUj230 __t3WVP229) (join lambda (1 2 0) 2 __tconst1EUj230 __t3WVP229 __t5ryk231) (join ref (1 0) 1 __tconst7sqz226 __t5APF225) (join lambda (1 2 0) 2 __tconst7sqz226 __t5APF225 __t2BAX227)) (head (mkstruct lambda (1 2 0) __t3laZ245 __tconst2x2f244 __t5h6K243)) mcfa-counting.slog:272 #f)
  class ReadTask36 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex19;  slog::Index** refindex20;  slog::Index** refindex21;  slog::Index** lambdaindex22;  slog::Index** refindex23;  slog::Index** lambdaindex24;  slog::Index** refindex25;  slog::Index** lambdaindex26;  slog::Index** refindex27;  slog::Index** appindex28;  slog::Index** refindex29;  slog::Index** refindex30;  slog::Index** lambdaindex31;  slog::Index** refindex32;  slog::Index** lambdaindex33;  slog::Index** refindex34;  slog::Index** lambdaindex35;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      outer_rel = db->getRelation("app");
      std::vector<u16> ord37({0, 1});
      slog::Relation* readrel38 = db->getRelation("ref");
      refindex19 = readrel38->getIndex(ord37, false);
      std::vector<u16> ord39({1, 0});
      slog::Relation* readrel40 = db->getRelation("ref");
      refindex20 = readrel40->getIndex(ord39, false);
      std::vector<u16> ord41({1, 0});
      slog::Relation* readrel42 = db->getRelation("ref");
      refindex21 = readrel42->getIndex(ord41, false);
      std::vector<u16> ord43({1, 2, 0});
      slog::Relation* readrel44 = db->getRelation("lambda");
      lambdaindex22 = readrel44->getIndex(ord43, false);
      std::vector<u16> ord45({1, 0});
      slog::Relation* readrel46 = db->getRelation("ref");
      refindex23 = readrel46->getIndex(ord45, false);
      std::vector<u16> ord47({1, 2, 0});
      slog::Relation* readrel48 = db->getRelation("lambda");
      lambdaindex24 = readrel48->getIndex(ord47, false);
      std::vector<u16> ord49({1, 0});
      slog::Relation* readrel50 = db->getRelation("ref");
      refindex25 = readrel50->getIndex(ord49, false);
      std::vector<u16> ord51({1, 2, 0});
      slog::Relation* readrel52 = db->getRelation("lambda");
      lambdaindex26 = readrel52->getIndex(ord51, false);
      std::vector<u16> ord53({1, 0});
      slog::Relation* readrel54 = db->getRelation("ref");
      refindex27 = readrel54->getIndex(ord53, false);
      std::vector<u16> ord55({0, 1, 2});
      slog::Relation* readrel56 = db->getRelation("app");
      appindex28 = readrel56->getIndex(ord55, false);
      std::vector<u16> ord57({0, 1});
      slog::Relation* readrel58 = db->getRelation("ref");
      refindex29 = readrel58->getIndex(ord57, false);
      std::vector<u16> ord59({1, 0});
      slog::Relation* readrel60 = db->getRelation("ref");
      refindex30 = readrel60->getIndex(ord59, false);
      std::vector<u16> ord61({1, 2, 0});
      slog::Relation* readrel62 = db->getRelation("lambda");
      lambdaindex31 = readrel62->getIndex(ord61, false);
      std::vector<u16> ord63({1, 0});
      slog::Relation* readrel64 = db->getRelation("ref");
      refindex32 = readrel64->getIndex(ord63, false);
      std::vector<u16> ord65({1, 2, 0});
      slog::Relation* readrel66 = db->getRelation("lambda");
      lambdaindex33 = readrel66->getIndex(ord65, false);
      std::vector<u16> ord67({1, 0});
      slog::Relation* readrel68 = db->getRelation("ref");
      refindex34 = readrel68->getIndex(ord67, false);
      std::vector<u16> ord69({1, 2, 0});
      slog::Relation* readrel70 = db->getRelation("lambda");
      lambdaindex35 = readrel70->getIndex(ord69, false);
  
    }
    ReadTask36(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c24 = v_consta32d5a443def48e6d64c6f4b;
      u64 v_c25 = v_consteb793a6f75d6cfe49d3c2c90;
      u64 v_c26 = v_constaaaad65142343c54348db5d0;
      u64 v_c27 = v_const7b8fd91ee9ff10cfbb8066bf;
      u64 v_c28 = v_const615ad01b1c532bb6634df115;
      u64 v_c29 = v_const4492fd5fa4baacfebd29f5e5;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c30 = _t[0];
        u64 v_c31 = _t[1];
        u64 v_c32 = _t[2];
        slog::join_probe<2,2>(refindex19, std::array<u64,2>{v_c32, v_c24}, [&](const std::array<u64,2>& m71) {
          if (!slog::exists_probe<2,1>(refindex20, std::array<u64,2>{v_c25, 0})) return;
          if (!slog::exists_probe<2,1>(refindex21, std::array<u64,2>{v_c29, 0})) return;
          if (!slog::exists_probe<3,1>(lambdaindex22, std::array<u64,3>{v_c29, 0, 0})) return;
          if (!slog::exists_probe<2,1>(refindex23, std::array<u64,2>{v_c28, 0})) return;
          if (!slog::exists_probe<3,1>(lambdaindex24, std::array<u64,3>{v_c28, 0, 0})) return;
          if (!slog::exists_probe<2,1>(refindex25, std::array<u64,2>{v_c27, 0})) return;
          if (!slog::exists_probe<3,1>(lambdaindex26, std::array<u64,3>{v_c27, 0, 0})) return;
          slog::join_probe<2,1>(refindex27, std::array<u64,2>{v_c26, 0}, [&](const std::array<u64,2>& m72) {
            u64 v_c33 = m72[1];
            slog::join_probe<3,2>(appindex28, std::array<u64,3>{v_c31, v_c33, 0}, [&](const std::array<u64,3>& m73) {
              u64 v_c34 = m73[2];
              slog::join_probe<2,2>(refindex29, std::array<u64,2>{v_c34, v_c25}, [&](const std::array<u64,2>& m74) {
                slog::join_probe<2,1>(refindex30, std::array<u64,2>{v_c29, 0}, [&](const std::array<u64,2>& m75) {
                  u64 v_c35 = m75[1];
                  slog::join_probe<3,2>(lambdaindex31, std::array<u64,3>{v_c29, v_c35, 0}, [&](const std::array<u64,3>& m76) {
                    u64 v_c36 = m76[2];
                    slog::join_probe<2,1>(refindex32, std::array<u64,2>{v_c28, 0}, [&](const std::array<u64,2>& m77) {
                      u64 v_c37 = m77[1];
                      slog::join_probe<3,2>(lambdaindex33, std::array<u64,3>{v_c28, v_c37, 0}, [&](const std::array<u64,3>& m78) {
                        u64 v_c38 = m78[2];
                        slog::join_probe<2,1>(refindex34, std::array<u64,2>{v_c27, 0}, [&](const std::array<u64,2>& m79) {
                          u64 v_c39 = m79[1];
                          slog::join_probe<3,2>(lambdaindex35, std::array<u64,3>{v_c27, v_c39, 0}, [&](const std::array<u64,3>& m80) {
                            u64 v_c40 = m80[2];
                            ++_fires;
                            slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c24, v_c30}, std::array<u16,3>{1, 2, 0});
                          });
                        });
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
        ReadTask36* _cont = new ReadTask36(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask36(db,b), false);
  // (crule (pre) (scan clo __t0zen261 __t4JNf263 cb) (body (exists freevar (1 0) 1 __t4JNf263) (exists store (1 0 2) 1 cb) (join eval_ans (1 0) 1 __t0zen261 __t7ceq259) (join freevar (1 0) 1 __t4JNf263 y) (join store (0 1 2) 2 y cb vy) (join eval (0 2 1) 1 __t7ceq259 c ef) (exists app (1 2 0) 1 ef) (exists eval (2 0 1) 1 c) (join eval (2 0 1) 1 c __5DEq344 __t6ooL258) (join app (0 1 2) 2 __t6ooL258 ef ea) (join-old eval (1 2 0) 2 (1 2 0) ea c __t2S0s262) (join eval_ans (0 1) 1 __t2S0s262 va) (join-old lambda (0 1 2) 1 (0 1 2) __t4JNf263 x eb)) (head (emit store (0 1 2) y __t6ooL258 vy) (emit bindev (0 1 2) y __t6ooL258 c)) mcfa-counting.slog:102 #f)
  class ReadTask96 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** freevarindex81;  slog::Index** storeindex82;  slog::Index** eval_ansindex83;  slog::Index** freevarindex84;  slog::Index** storeindex85;  slog::Index** evalindex86;  slog::Index** appindex87;  slog::Index** evalindex88;  slog::Index** evalindex89;  slog::Index** appindex90;  slog::Index** evalindex91;  slog::Index** eval_ansindex92;  slog::Index** lambdaindex93;  slog::Index** evaldelta94;  slog::Index** lambdadelta95;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("store");
      std::vector<u16> ord97({0, 1, 2});
      slog::Relation* readrel98 = db->getRelation("store");
      head_index[0] = readrel98->getIndex(ord97, false);
      head_rel[1] = db->getRelation("bindev");
      std::vector<u16> ord99({0, 1, 2});
      slog::Relation* readrel100 = db->getRelation("bindev");
      head_index[1] = readrel100->getIndex(ord99, false);
      outer_rel = db->getRelation("clo");
      std::vector<u16> ord101({1, 0});
      slog::Relation* readrel102 = db->getRelation("freevar");
      freevarindex81 = readrel102->getIndex(ord101, false);
      std::vector<u16> ord103({1, 0, 2});
      slog::Relation* readrel104 = db->getRelation("store");
      storeindex82 = readrel104->getIndex(ord103, false);
      std::vector<u16> ord105({1, 0});
      slog::Relation* readrel106 = db->getRelation("eval_ans");
      eval_ansindex83 = readrel106->getIndex(ord105, false);
      std::vector<u16> ord107({1, 0});
      slog::Relation* readrel108 = db->getRelation("freevar");
      freevarindex84 = readrel108->getIndex(ord107, false);
      std::vector<u16> ord109({0, 1, 2});
      slog::Relation* readrel110 = db->getRelation("store");
      storeindex85 = readrel110->getIndex(ord109, false);
      std::vector<u16> ord111({0, 2, 1});
      slog::Relation* readrel112 = db->getRelation("eval");
      evalindex86 = readrel112->getIndex(ord111, false);
      std::vector<u16> ord113({1, 2, 0});
      slog::Relation* readrel114 = db->getRelation("app");
      appindex87 = readrel114->getIndex(ord113, false);
      std::vector<u16> ord115({2, 0, 1});
      slog::Relation* readrel116 = db->getRelation("eval");
      evalindex88 = readrel116->getIndex(ord115, false);
      std::vector<u16> ord117({2, 0, 1});
      slog::Relation* readrel118 = db->getRelation("eval");
      evalindex89 = readrel118->getIndex(ord117, false);
      std::vector<u16> ord119({0, 1, 2});
      slog::Relation* readrel120 = db->getRelation("app");
      appindex90 = readrel120->getIndex(ord119, false);
      std::vector<u16> ord121({1, 2, 0});
      slog::Relation* readrel122 = db->getRelation("eval");
      evalindex91 = readrel122->getIndex(ord121, false);
      std::vector<u16> ord123({1, 2, 0});
      slog::Relation* readrel124 = db->getRelation("eval");
      evaldelta94 = readrel124->getIndex(ord123, true);
      std::vector<u16> ord125({0, 1});
      slog::Relation* readrel126 = db->getRelation("eval_ans");
      eval_ansindex92 = readrel126->getIndex(ord125, false);
      std::vector<u16> ord127({0, 1, 2});
      slog::Relation* readrel128 = db->getRelation("lambda");
      lambdaindex93 = readrel128->getIndex(ord127, false);
      std::vector<u16> ord129({0, 1, 2});
      slog::Relation* readrel130 = db->getRelation("lambda");
      lambdadelta95 = readrel130->getIndex(ord129, true);
  
    }
    ReadTask96(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c41 = _t[0];
        u64 v_c42 = _t[1];
        u64 v_c7 = _t[2];
        if (!slog::exists_probe<2,1>(freevarindex81, std::array<u64,2>{v_c42, 0})) return;
        if (!slog::exists_probe<3,1>(storeindex82, std::array<u64,3>{v_c7, 0, 0})) return;
        slog::join_probe<2,1>(eval_ansindex83, std::array<u64,2>{v_c41, 0}, [&](const std::array<u64,2>& m131) {
          u64 v_c43 = m131[1];
          slog::join_probe<2,1>(freevarindex84, std::array<u64,2>{v_c42, 0}, [&](const std::array<u64,2>& m132) {
            u64 v_c5 = m132[1];
            slog::join_probe<3,2>(storeindex85, std::array<u64,3>{v_c5, v_c7, 0}, [&](const std::array<u64,3>& m133) {
              u64 v_c8 = m133[2];
              slog::join_probe<3,1>(evalindex86, std::array<u64,3>{v_c43, 0, 0}, [&](const std::array<u64,3>& m134) {
                u64 v_c3 = m134[1]; u64 v_c1 = m134[2];
                if (!slog::exists_probe<3,1>(appindex87, std::array<u64,3>{v_c1, 0, 0})) return;
                if (!slog::exists_probe<3,1>(evalindex88, std::array<u64,3>{v_c3, 0, 0})) return;
                slog::join_probe<3,1>(evalindex89, std::array<u64,3>{v_c3, 0, 0}, [&](const std::array<u64,3>& m135) {
                  u64 v_c44 = m135[1]; u64 v_c45 = m135[2];
                  slog::join_probe<3,2>(appindex90, std::array<u64,3>{v_c45, v_c1, 0}, [&](const std::array<u64,3>& m136) {
                    u64 v_c2 = m136[2];
                    slog::join_probe_old<3,2>(evalindex91, evaldelta94, std::array<u64,3>{v_c2, v_c3, 0}, [&](const std::array<u64,3>& m137) {
                      u64 v_c46 = m137[2];
                      slog::join_probe<2,1>(eval_ansindex92, std::array<u64,2>{v_c46, 0}, [&](const std::array<u64,2>& m138) {
                        u64 v_c47 = m138[1];
                        slog::join_probe_old<3,1>(lambdaindex93, lambdadelta95, std::array<u64,3>{v_c42, 0, 0}, [&](const std::array<u64,3>& m139) {
                          u64 v_c9 = m139[1]; u64 v_c10 = m139[2];
                          ++_fires;
                          slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c5, v_c45, v_c8}, std::array<u16,3>{0, 1, 2});
                          slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c5, v_c45, v_c3}, std::array<u16,3>{0, 1, 2});
                        });
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
  
      if (_fires) db->bumpFires("mcfa-counting.slog:102", "delta:clo", _fires);
  
      if (!_done)
      {
        ReadTask96* _cont = new ReadTask96(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask96(db,b), false);
  // (crule (pre (let __tconst9zoW125 const7c7d2cfc66f4d976987d2d20) (let __tconst4V4L122 const6bc0ba365ada70df115e1785) (let __tconst4Zcr91 const9a67f28c6b77e842f439a84a) (let __tconst0vRf84 conste58dec6bca6f63ef79c3b755) (let __tconst82U8119 consta8180db1c2f300980314f910) (let __tconst4BKz104 const0f8748be649f8ee4066bb1d7) (let __tconst3wDH116 constd5f017533ea574d5f9b3400c) (let __tconst3ktF111 const990b444cbd47632035b2fa1a) (let __tconst5nWJ102 const4f84f41d89b6b717419b4eaa)) (seeded) (body (join ref (1 0) 1 __tconst0vRf84 __t2duR83) (exists ref (1 0) 1 __tconst4Zcr91) (exists ref (1 0) 1 __tconst9zoW125) (exists lambda (1 2 0) 1 __tconst4Zcr91) (exists ref (1 0) 1 __tconst4V4L122) (exists ref (1 0) 1 __tconst4BKz104) (exists lambda (1 2 0) 1 __tconst4BKz104) (exists ref (1 0) 1 __tconst3wDH116) (exists ref (1 0) 1 __tconst5nWJ102) (exists lambda (1 2 0) 1 __tconst5nWJ102) (exists ref (1 0) 1 __tconst3ktF111) (exists lambda (1 2 0) 1 __tconst3ktF111) (exists lambda (1 2 0) 1 __tconst3wDH116) (exists lambda (1 2 0) 1 __tconst82U8119) (exists lambda (1 2 0) 1 __tconst4V4L122) (join lambda (1 2 0) 2 __tconst0vRf84 __t2duR83 __t87vL85) (join ref (1 0) 1 __tconst4Zcr91 __t0C9F87) (exists app (2 0 1) 1 __t0C9F87) (join ref (1 0) 1 __tconst9zoW125 __t3Q2G89) (join app (1 2 0) 2 __t3Q2G89 __t0C9F87 __t2Eqd90) (join lambda (1 2 0) 2 __tconst4Zcr91 __t2Eqd90 __t3pgm92) (exists app (2 0 1) 1 __t3pgm92) (join ref (1 0) 1 __tconst4V4L122 __t7aew98) (exists app (1 2 0) 1 __t7aew98) (join ref (1 0) 1 __tconst4BKz104 __t8C0a94) (join lambda (1 2 0) 2 __tconst4BKz104 __t8C0a94 __t4fDK96) (join app (1 2 0) 2 __t7aew98 __t4fDK96 __t7TEO99) (exists app (2 0 1) 1 __t7TEO99) (join ref (1 0) 1 __tconst3wDH116 __t3wir114) (exists app (1 2 0) 1 __t3wir114) (join ref (1 0) 1 __tconst5nWJ102 __t5MaG101) (join lambda (1 2 0) 2 __tconst5nWJ102 __t5MaG101 __t35jA103) (join lambda (1 2 0) 2 __tconst4BKz104 __t35jA103 __t6RuY105) (join app (1 2 0) 2 __t7aew98 __t6RuY105 __t2Z7m108) (exists app (2 0 1) 1 __t2Z7m108) (join ref (1 0) 1 __tconst3ktF111 __t7ohz110) (join lambda (1 2 0) 2 __tconst3ktF111 __t7ohz110 __t8GWA112) (join app (1 2 0) 2 __t3wir114 __t8GWA112 __t44OM115) (join lambda (1 2 0) 2 __tconst3wDH116 __t44OM115 __t7CwH117) (join app (1 2 0) 2 __t7CwH117 __t2Z7m108 __t50Kk118) (join lambda (1 2 0) 2 __tconst82U8119 __t50Kk118 __t3SEs120) (join app (1 2 0) 2 __t3SEs120 __t7TEO99 __t1GdP121) (join lambda (1 2 0) 2 __tconst4V4L122 __t1GdP121 __t5iMg123) (join app (1 2 0) 2 __t5iMg123 __t3pgm92 __t3cyj124)) (head (mkstruct lambda (1 2 0) __t4GT8126 __tconst9zoW125 __t3cyj124)) mcfa-counting.slog:241 #f)
  class ReadTask184 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex140;  slog::Index** refindex141;  slog::Index** refindex142;  slog::Index** lambdaindex143;  slog::Index** refindex144;  slog::Index** refindex145;  slog::Index** lambdaindex146;  slog::Index** refindex147;  slog::Index** refindex148;  slog::Index** lambdaindex149;  slog::Index** refindex150;  slog::Index** lambdaindex151;  slog::Index** lambdaindex152;  slog::Index** lambdaindex153;  slog::Index** lambdaindex154;  slog::Index** lambdaindex155;  slog::Index** refindex156;  slog::Index** appindex157;  slog::Index** refindex158;  slog::Index** appindex159;  slog::Index** lambdaindex160;  slog::Index** appindex161;  slog::Index** refindex162;  slog::Index** appindex163;  slog::Index** refindex164;  slog::Index** lambdaindex165;  slog::Index** appindex166;  slog::Index** appindex167;  slog::Index** refindex168;  slog::Index** appindex169;  slog::Index** refindex170;  slog::Index** lambdaindex171;  slog::Index** lambdaindex172;  slog::Index** appindex173;  slog::Index** appindex174;  slog::Index** refindex175;  slog::Index** lambdaindex176;  slog::Index** appindex177;  slog::Index** lambdaindex178;  slog::Index** appindex179;  slog::Index** lambdaindex180;  slog::Index** appindex181;  slog::Index** lambdaindex182;  slog::Index** appindex183;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      std::vector<u16> ord185({1, 2, 0});
      slog::Relation* readrel186 = db->getRelation("lambda");
      head_index[0] = readrel186->getIndex(ord185, false);
      std::vector<u16> ord187({1, 0});
      slog::Relation* readrel188 = db->getRelation("ref");
      refindex140 = readrel188->getIndex(ord187, false);
      std::vector<u16> ord189({1, 0});
      slog::Relation* readrel190 = db->getRelation("ref");
      refindex141 = readrel190->getIndex(ord189, false);
      std::vector<u16> ord191({1, 0});
      slog::Relation* readrel192 = db->getRelation("ref");
      refindex142 = readrel192->getIndex(ord191, false);
      std::vector<u16> ord193({1, 2, 0});
      slog::Relation* readrel194 = db->getRelation("lambda");
      lambdaindex143 = readrel194->getIndex(ord193, false);
      std::vector<u16> ord195({1, 0});
      slog::Relation* readrel196 = db->getRelation("ref");
      refindex144 = readrel196->getIndex(ord195, false);
      std::vector<u16> ord197({1, 0});
      slog::Relation* readrel198 = db->getRelation("ref");
      refindex145 = readrel198->getIndex(ord197, false);
      std::vector<u16> ord199({1, 2, 0});
      slog::Relation* readrel200 = db->getRelation("lambda");
      lambdaindex146 = readrel200->getIndex(ord199, false);
      std::vector<u16> ord201({1, 0});
      slog::Relation* readrel202 = db->getRelation("ref");
      refindex147 = readrel202->getIndex(ord201, false);
      std::vector<u16> ord203({1, 0});
      slog::Relation* readrel204 = db->getRelation("ref");
      refindex148 = readrel204->getIndex(ord203, false);
      std::vector<u16> ord205({1, 2, 0});
      slog::Relation* readrel206 = db->getRelation("lambda");
      lambdaindex149 = readrel206->getIndex(ord205, false);
      std::vector<u16> ord207({1, 0});
      slog::Relation* readrel208 = db->getRelation("ref");
      refindex150 = readrel208->getIndex(ord207, false);
      std::vector<u16> ord209({1, 2, 0});
      slog::Relation* readrel210 = db->getRelation("lambda");
      lambdaindex151 = readrel210->getIndex(ord209, false);
      std::vector<u16> ord211({1, 2, 0});
      slog::Relation* readrel212 = db->getRelation("lambda");
      lambdaindex152 = readrel212->getIndex(ord211, false);
      std::vector<u16> ord213({1, 2, 0});
      slog::Relation* readrel214 = db->getRelation("lambda");
      lambdaindex153 = readrel214->getIndex(ord213, false);
      std::vector<u16> ord215({1, 2, 0});
      slog::Relation* readrel216 = db->getRelation("lambda");
      lambdaindex154 = readrel216->getIndex(ord215, false);
      std::vector<u16> ord217({1, 2, 0});
      slog::Relation* readrel218 = db->getRelation("lambda");
      lambdaindex155 = readrel218->getIndex(ord217, false);
      std::vector<u16> ord219({1, 0});
      slog::Relation* readrel220 = db->getRelation("ref");
      refindex156 = readrel220->getIndex(ord219, false);
      std::vector<u16> ord221({2, 0, 1});
      slog::Relation* readrel222 = db->getRelation("app");
      appindex157 = readrel222->getIndex(ord221, false);
      std::vector<u16> ord223({1, 0});
      slog::Relation* readrel224 = db->getRelation("ref");
      refindex158 = readrel224->getIndex(ord223, false);
      std::vector<u16> ord225({1, 2, 0});
      slog::Relation* readrel226 = db->getRelation("app");
      appindex159 = readrel226->getIndex(ord225, false);
      std::vector<u16> ord227({1, 2, 0});
      slog::Relation* readrel228 = db->getRelation("lambda");
      lambdaindex160 = readrel228->getIndex(ord227, false);
      std::vector<u16> ord229({2, 0, 1});
      slog::Relation* readrel230 = db->getRelation("app");
      appindex161 = readrel230->getIndex(ord229, false);
      std::vector<u16> ord231({1, 0});
      slog::Relation* readrel232 = db->getRelation("ref");
      refindex162 = readrel232->getIndex(ord231, false);
      std::vector<u16> ord233({1, 2, 0});
      slog::Relation* readrel234 = db->getRelation("app");
      appindex163 = readrel234->getIndex(ord233, false);
      std::vector<u16> ord235({1, 0});
      slog::Relation* readrel236 = db->getRelation("ref");
      refindex164 = readrel236->getIndex(ord235, false);
      std::vector<u16> ord237({1, 2, 0});
      slog::Relation* readrel238 = db->getRelation("lambda");
      lambdaindex165 = readrel238->getIndex(ord237, false);
      std::vector<u16> ord239({1, 2, 0});
      slog::Relation* readrel240 = db->getRelation("app");
      appindex166 = readrel240->getIndex(ord239, false);
      std::vector<u16> ord241({2, 0, 1});
      slog::Relation* readrel242 = db->getRelation("app");
      appindex167 = readrel242->getIndex(ord241, false);
      std::vector<u16> ord243({1, 0});
      slog::Relation* readrel244 = db->getRelation("ref");
      refindex168 = readrel244->getIndex(ord243, false);
      std::vector<u16> ord245({1, 2, 0});
      slog::Relation* readrel246 = db->getRelation("app");
      appindex169 = readrel246->getIndex(ord245, false);
      std::vector<u16> ord247({1, 0});
      slog::Relation* readrel248 = db->getRelation("ref");
      refindex170 = readrel248->getIndex(ord247, false);
      std::vector<u16> ord249({1, 2, 0});
      slog::Relation* readrel250 = db->getRelation("lambda");
      lambdaindex171 = readrel250->getIndex(ord249, false);
      std::vector<u16> ord251({1, 2, 0});
      slog::Relation* readrel252 = db->getRelation("lambda");
      lambdaindex172 = readrel252->getIndex(ord251, false);
      std::vector<u16> ord253({1, 2, 0});
      slog::Relation* readrel254 = db->getRelation("app");
      appindex173 = readrel254->getIndex(ord253, false);
      std::vector<u16> ord255({2, 0, 1});
      slog::Relation* readrel256 = db->getRelation("app");
      appindex174 = readrel256->getIndex(ord255, false);
      std::vector<u16> ord257({1, 0});
      slog::Relation* readrel258 = db->getRelation("ref");
      refindex175 = readrel258->getIndex(ord257, false);
      std::vector<u16> ord259({1, 2, 0});
      slog::Relation* readrel260 = db->getRelation("lambda");
      lambdaindex176 = readrel260->getIndex(ord259, false);
      std::vector<u16> ord261({1, 2, 0});
      slog::Relation* readrel262 = db->getRelation("app");
      appindex177 = readrel262->getIndex(ord261, false);
      std::vector<u16> ord263({1, 2, 0});
      slog::Relation* readrel264 = db->getRelation("lambda");
      lambdaindex178 = readrel264->getIndex(ord263, false);
      std::vector<u16> ord265({1, 2, 0});
      slog::Relation* readrel266 = db->getRelation("app");
      appindex179 = readrel266->getIndex(ord265, false);
      std::vector<u16> ord267({1, 2, 0});
      slog::Relation* readrel268 = db->getRelation("lambda");
      lambdaindex180 = readrel268->getIndex(ord267, false);
      std::vector<u16> ord269({1, 2, 0});
      slog::Relation* readrel270 = db->getRelation("app");
      appindex181 = readrel270->getIndex(ord269, false);
      std::vector<u16> ord271({1, 2, 0});
      slog::Relation* readrel272 = db->getRelation("lambda");
      lambdaindex182 = readrel272->getIndex(ord271, false);
      std::vector<u16> ord273({1, 2, 0});
      slog::Relation* readrel274 = db->getRelation("app");
      appindex183 = readrel274->getIndex(ord273, false);
  
    }
    ReadTask184(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c11 = v_const7c7d2cfc66f4d976987d2d20;
      u64 v_c12 = v_const6bc0ba365ada70df115e1785;
      u64 v_c18 = v_const9a67f28c6b77e842f439a84a;
      u64 v_c19 = v_conste58dec6bca6f63ef79c3b755;
      u64 v_c13 = v_consta8180db1c2f300980314f910;
      u64 v_c16 = v_const0f8748be649f8ee4066bb1d7;
      u64 v_c14 = v_constd5f017533ea574d5f9b3400c;
      u64 v_c15 = v_const990b444cbd47632035b2fa1a;
      u64 v_c17 = v_const4f84f41d89b6b717419b4eaa;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex140, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m275) {
        u64 v_c48 = m275[1];
        if (!slog::exists_probe<2,1>(refindex141, std::array<u64,2>{v_c18, 0})) return;
        if (!slog::exists_probe<2,1>(refindex142, std::array<u64,2>{v_c11, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex143, std::array<u64,3>{v_c18, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex144, std::array<u64,2>{v_c12, 0})) return;
        if (!slog::exists_probe<2,1>(refindex145, std::array<u64,2>{v_c16, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex146, std::array<u64,3>{v_c16, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex147, std::array<u64,2>{v_c14, 0})) return;
        if (!slog::exists_probe<2,1>(refindex148, std::array<u64,2>{v_c17, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex149, std::array<u64,3>{v_c17, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex150, std::array<u64,2>{v_c15, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex151, std::array<u64,3>{v_c15, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex152, std::array<u64,3>{v_c14, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex153, std::array<u64,3>{v_c13, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex154, std::array<u64,3>{v_c12, 0, 0})) return;
        slog::join_probe<3,2>(lambdaindex155, std::array<u64,3>{v_c19, v_c48, 0}, [&](const std::array<u64,3>& m276) {
          u64 v_c49 = m276[2];
          slog::join_probe<2,1>(refindex156, std::array<u64,2>{v_c18, 0}, [&](const std::array<u64,2>& m277) {
            u64 v_c50 = m277[1];
            if (!slog::exists_probe<3,1>(appindex157, std::array<u64,3>{v_c50, 0, 0})) return;
            slog::join_probe<2,1>(refindex158, std::array<u64,2>{v_c11, 0}, [&](const std::array<u64,2>& m278) {
              u64 v_c51 = m278[1];
              slog::join_probe<3,2>(appindex159, std::array<u64,3>{v_c51, v_c50, 0}, [&](const std::array<u64,3>& m279) {
                u64 v_c52 = m279[2];
                slog::join_probe<3,2>(lambdaindex160, std::array<u64,3>{v_c18, v_c52, 0}, [&](const std::array<u64,3>& m280) {
                  u64 v_c53 = m280[2];
                  if (!slog::exists_probe<3,1>(appindex161, std::array<u64,3>{v_c53, 0, 0})) return;
                  slog::join_probe<2,1>(refindex162, std::array<u64,2>{v_c12, 0}, [&](const std::array<u64,2>& m281) {
                    u64 v_c54 = m281[1];
                    if (!slog::exists_probe<3,1>(appindex163, std::array<u64,3>{v_c54, 0, 0})) return;
                    slog::join_probe<2,1>(refindex164, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m282) {
                      u64 v_c55 = m282[1];
                      slog::join_probe<3,2>(lambdaindex165, std::array<u64,3>{v_c16, v_c55, 0}, [&](const std::array<u64,3>& m283) {
                        u64 v_c56 = m283[2];
                        slog::join_probe<3,2>(appindex166, std::array<u64,3>{v_c54, v_c56, 0}, [&](const std::array<u64,3>& m284) {
                          u64 v_c57 = m284[2];
                          if (!slog::exists_probe<3,1>(appindex167, std::array<u64,3>{v_c57, 0, 0})) return;
                          slog::join_probe<2,1>(refindex168, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m285) {
                            u64 v_c58 = m285[1];
                            if (!slog::exists_probe<3,1>(appindex169, std::array<u64,3>{v_c58, 0, 0})) return;
                            slog::join_probe<2,1>(refindex170, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m286) {
                              u64 v_c59 = m286[1];
                              slog::join_probe<3,2>(lambdaindex171, std::array<u64,3>{v_c17, v_c59, 0}, [&](const std::array<u64,3>& m287) {
                                u64 v_c60 = m287[2];
                                slog::join_probe<3,2>(lambdaindex172, std::array<u64,3>{v_c16, v_c60, 0}, [&](const std::array<u64,3>& m288) {
                                  u64 v_c61 = m288[2];
                                  slog::join_probe<3,2>(appindex173, std::array<u64,3>{v_c54, v_c61, 0}, [&](const std::array<u64,3>& m289) {
                                    u64 v_c62 = m289[2];
                                    if (!slog::exists_probe<3,1>(appindex174, std::array<u64,3>{v_c62, 0, 0})) return;
                                    slog::join_probe<2,1>(refindex175, std::array<u64,2>{v_c15, 0}, [&](const std::array<u64,2>& m290) {
                                      u64 v_c63 = m290[1];
                                      slog::join_probe<3,2>(lambdaindex176, std::array<u64,3>{v_c15, v_c63, 0}, [&](const std::array<u64,3>& m291) {
                                        u64 v_c64 = m291[2];
                                        slog::join_probe<3,2>(appindex177, std::array<u64,3>{v_c58, v_c64, 0}, [&](const std::array<u64,3>& m292) {
                                          u64 v_c65 = m292[2];
                                          slog::join_probe<3,2>(lambdaindex178, std::array<u64,3>{v_c14, v_c65, 0}, [&](const std::array<u64,3>& m293) {
                                            u64 v_c66 = m293[2];
                                            slog::join_probe<3,2>(appindex179, std::array<u64,3>{v_c66, v_c62, 0}, [&](const std::array<u64,3>& m294) {
                                              u64 v_c67 = m294[2];
                                              slog::join_probe<3,2>(lambdaindex180, std::array<u64,3>{v_c13, v_c67, 0}, [&](const std::array<u64,3>& m295) {
                                                u64 v_c68 = m295[2];
                                                slog::join_probe<3,2>(appindex181, std::array<u64,3>{v_c68, v_c57, 0}, [&](const std::array<u64,3>& m296) {
                                                  u64 v_c69 = m296[2];
                                                  slog::join_probe<3,2>(lambdaindex182, std::array<u64,3>{v_c12, v_c69, 0}, [&](const std::array<u64,3>& m297) {
                                                    u64 v_c70 = m297[2];
                                                    slog::join_probe<3,2>(appindex183, std::array<u64,3>{v_c70, v_c53, 0}, [&](const std::array<u64,3>& m298) {
                                                      u64 v_c71 = m298[2];
                                                      ++_fires;
                                                      slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c11, v_c71}, std::array<u16,3>{1, 2, 0});
                                                    });
                                                  });
                                                });
                                              });
                                            });
                                          });
                                        });
                                      });
                                    });
                                  });
                                });
                              });
                            });
                          });
                        });
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
      s->addTaskSeeded(phase_read, new ReadTask184(db,b));
  // (crule (pre) (scan eval __t7ceq259 ef c) (body (exists eval (2 0 1) 1 c) (exists app (1 2 0) 1 ef) (join eval_ans (0 1) 1 __t7ceq259 __t0zen261) (join eval (2 0 1) 1 c __5DEq344 __t6ooL258) (join app (0 1 2) 2 __t6ooL258 ef ea) (join-old eval (1 2 0) 2 (1 2 0) ea c __t2S0s262) (join eval_ans (0 1) 1 __t2S0s262 va) (join-old clo (0 2 1) 1 (0 2 1) __t0zen261 cb __t4JNf263) (exists store (1 0 2) 1 cb) (join freevar (1 0) 1 __t4JNf263 y) (join store (0 1 2) 2 y cb vy) (join-old lambda (0 1 2) 1 (0 1 2) __t4JNf263 x eb)) (head (emit store (0 1 2) y __t6ooL258 vy) (emit bindev (0 1 2) y __t6ooL258 c)) mcfa-counting.slog:102 #f)
  class ReadTask314 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex299;  slog::Index** appindex300;  slog::Index** eval_ansindex301;  slog::Index** evalindex302;  slog::Index** appindex303;  slog::Index** evalindex304;  slog::Index** eval_ansindex305;  slog::Index** cloindex306;  slog::Index** storeindex307;  slog::Index** freevarindex308;  slog::Index** storeindex309;  slog::Index** lambdaindex310;  slog::Index** evaldelta311;  slog::Index** clodelta312;  slog::Index** lambdadelta313;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("store");
      std::vector<u16> ord315({0, 1, 2});
      slog::Relation* readrel316 = db->getRelation("store");
      head_index[0] = readrel316->getIndex(ord315, false);
      head_rel[1] = db->getRelation("bindev");
      std::vector<u16> ord317({0, 1, 2});
      slog::Relation* readrel318 = db->getRelation("bindev");
      head_index[1] = readrel318->getIndex(ord317, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord319({2, 0, 1});
      slog::Relation* readrel320 = db->getRelation("eval");
      evalindex299 = readrel320->getIndex(ord319, false);
      std::vector<u16> ord321({1, 2, 0});
      slog::Relation* readrel322 = db->getRelation("app");
      appindex300 = readrel322->getIndex(ord321, false);
      std::vector<u16> ord323({0, 1});
      slog::Relation* readrel324 = db->getRelation("eval_ans");
      eval_ansindex301 = readrel324->getIndex(ord323, false);
      std::vector<u16> ord325({2, 0, 1});
      slog::Relation* readrel326 = db->getRelation("eval");
      evalindex302 = readrel326->getIndex(ord325, false);
      std::vector<u16> ord327({0, 1, 2});
      slog::Relation* readrel328 = db->getRelation("app");
      appindex303 = readrel328->getIndex(ord327, false);
      std::vector<u16> ord329({1, 2, 0});
      slog::Relation* readrel330 = db->getRelation("eval");
      evalindex304 = readrel330->getIndex(ord329, false);
      std::vector<u16> ord331({1, 2, 0});
      slog::Relation* readrel332 = db->getRelation("eval");
      evaldelta311 = readrel332->getIndex(ord331, true);
      std::vector<u16> ord333({0, 1});
      slog::Relation* readrel334 = db->getRelation("eval_ans");
      eval_ansindex305 = readrel334->getIndex(ord333, false);
      std::vector<u16> ord335({0, 2, 1});
      slog::Relation* readrel336 = db->getRelation("clo");
      cloindex306 = readrel336->getIndex(ord335, false);
      std::vector<u16> ord337({0, 2, 1});
      slog::Relation* readrel338 = db->getRelation("clo");
      clodelta312 = readrel338->getIndex(ord337, true);
      std::vector<u16> ord339({1, 0, 2});
      slog::Relation* readrel340 = db->getRelation("store");
      storeindex307 = readrel340->getIndex(ord339, false);
      std::vector<u16> ord341({1, 0});
      slog::Relation* readrel342 = db->getRelation("freevar");
      freevarindex308 = readrel342->getIndex(ord341, false);
      std::vector<u16> ord343({0, 1, 2});
      slog::Relation* readrel344 = db->getRelation("store");
      storeindex309 = readrel344->getIndex(ord343, false);
      std::vector<u16> ord345({0, 1, 2});
      slog::Relation* readrel346 = db->getRelation("lambda");
      lambdaindex310 = readrel346->getIndex(ord345, false);
      std::vector<u16> ord347({0, 1, 2});
      slog::Relation* readrel348 = db->getRelation("lambda");
      lambdadelta313 = readrel348->getIndex(ord347, true);
  
    }
    ReadTask314(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c43 = _t[0];
        u64 v_c1 = _t[1];
        u64 v_c3 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex299, std::array<u64,3>{v_c3, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex300, std::array<u64,3>{v_c1, 0, 0})) return;
        slog::join_probe<2,1>(eval_ansindex301, std::array<u64,2>{v_c43, 0}, [&](const std::array<u64,2>& m349) {
          u64 v_c41 = m349[1];
          slog::join_probe<3,1>(evalindex302, std::array<u64,3>{v_c3, 0, 0}, [&](const std::array<u64,3>& m350) {
            u64 v_c44 = m350[1]; u64 v_c45 = m350[2];
            slog::join_probe<3,2>(appindex303, std::array<u64,3>{v_c45, v_c1, 0}, [&](const std::array<u64,3>& m351) {
              u64 v_c2 = m351[2];
              slog::join_probe_old<3,2>(evalindex304, evaldelta311, std::array<u64,3>{v_c2, v_c3, 0}, [&](const std::array<u64,3>& m352) {
                u64 v_c46 = m352[2];
                slog::join_probe<2,1>(eval_ansindex305, std::array<u64,2>{v_c46, 0}, [&](const std::array<u64,2>& m353) {
                  u64 v_c47 = m353[1];
                  slog::join_probe_old<3,1>(cloindex306, clodelta312, std::array<u64,3>{v_c41, 0, 0}, [&](const std::array<u64,3>& m354) {
                    u64 v_c7 = m354[1]; u64 v_c42 = m354[2];
                    if (!slog::exists_probe<3,1>(storeindex307, std::array<u64,3>{v_c7, 0, 0})) return;
                    slog::join_probe<2,1>(freevarindex308, std::array<u64,2>{v_c42, 0}, [&](const std::array<u64,2>& m355) {
                      u64 v_c5 = m355[1];
                      slog::join_probe<3,2>(storeindex309, std::array<u64,3>{v_c5, v_c7, 0}, [&](const std::array<u64,3>& m356) {
                        u64 v_c8 = m356[2];
                        slog::join_probe_old<3,1>(lambdaindex310, lambdadelta313, std::array<u64,3>{v_c42, 0, 0}, [&](const std::array<u64,3>& m357) {
                          u64 v_c9 = m357[1]; u64 v_c10 = m357[2];
                          ++_fires;
                          slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c5, v_c45, v_c8}, std::array<u16,3>{0, 1, 2});
                          slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c5, v_c45, v_c3}, std::array<u16,3>{0, 1, 2});
                        });
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
  
      if (_fires) db->bumpFires("mcfa-counting.slog:102", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask314* _cont = new ReadTask314(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask314(db,b), false);
  // (crule (pre) (scan app __t5Yh14 ef ea) (body (join eval (1 2 0) 1 __t5Yh14 c __4DdV347) (join freevar (0 1) 0 y __t4I265) (join store (0 1 2) 1 y cb vy) (join lambda (0 1 2) 1 __t4I265 x eb)) (head (mkstruct eval (1 2 0) __34Tv348 ea c)) mcfa-counting.slog:102 #f)
  class ReadTask362 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex358;  slog::Index** freevarindex359;  slog::Index** storeindex360;  slog::Index** lambdaindex361;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("app");
      std::vector<u16> ord363({1, 2, 0});
      slog::Relation* readrel364 = db->getRelation("eval");
      evalindex358 = readrel364->getIndex(ord363, false);
      std::vector<u16> ord365({0, 1});
      slog::Relation* readrel366 = db->getRelation("freevar");
      freevarindex359 = readrel366->getIndex(ord365, false);
      std::vector<u16> ord367({0, 1, 2});
      slog::Relation* readrel368 = db->getRelation("store");
      storeindex360 = readrel368->getIndex(ord367, false);
      std::vector<u16> ord369({0, 1, 2});
      slog::Relation* readrel370 = db->getRelation("lambda");
      lambdaindex361 = readrel370->getIndex(ord369, false);
  
    }
    ReadTask362(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c72 = _t[0];
        u64 v_c1 = _t[1];
        u64 v_c2 = _t[2];
        slog::join_probe<3,1>(evalindex358, std::array<u64,3>{v_c72, 0, 0}, [&](const std::array<u64,3>& m371) {
          u64 v_c3 = m371[1]; u64 v_c73 = m371[2];
          slog::join_all<2>(freevarindex359, [&](const std::array<u64,2>& m372) {
            u64 v_c5 = m372[0]; u64 v_c74 = m372[1];
            slog::join_probe<3,1>(storeindex360, std::array<u64,3>{v_c5, 0, 0}, [&](const std::array<u64,3>& m373) {
              u64 v_c7 = m373[1]; u64 v_c8 = m373[2];
              slog::join_probe<3,1>(lambdaindex361, std::array<u64,3>{v_c74, 0, 0}, [&](const std::array<u64,3>& m374) {
                u64 v_c9 = m374[1]; u64 v_c10 = m374[2];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c2, v_c3}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:102", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask362* _cont = new ReadTask362(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask362(db,b), false);
  // (crule (pre (let __tconst7JVW192 const6cf13cc59dcbe759113f68a4) (let __tconst7B9N190 constcaa3ee5a2828a31924f6b39d) (let __tconst5wC2180 const970c20ea81b833e5b5a7accf) (let __tconst2ady176 constc40f204dda7ba4054abb9e74)) (seeded) (body (join ref (1 0) 1 __tconst7JVW192 __t6fOY185) (exists lambda (1 2 0) 1 __tconst2ady176) (exists ref (1 0) 1 __tconst5wC2180) (exists lambda (1 2 0) 1 __tconst5wC2180) (exists ref (1 0) 1 __tconst7B9N190) (exists app (1 2 0) 1 __t6fOY185) (exists lambda (1 2 0) 1 __tconst7B9N190) (join ref (1 0) 1 __tconst2ady176 __t3ZY4175) (join lambda (1 2 0) 2 __tconst2ady176 __t3ZY4175 __t1Ls4177) (join ref (1 0) 1 __tconst5wC2180 __t52sB179) (join lambda (1 2 0) 2 __tconst5wC2180 __t52sB179 __t6CST181) (join ref (1 0) 1 __tconst7B9N190 __t8oRJ183) (join app (1 2 0) 2 __t6fOY185 __t8oRJ183 __t2CTd186) (join app (1 2 0) 2 __t6fOY185 __t2CTd186 __t9pbS189) (join lambda (1 2 0) 2 __tconst7B9N190 __t9pbS189 __t6W4v191)) (head (mkstruct lambda (1 2 0) __t6Vw9193 __tconst7JVW192 __t6W4v191)) mcfa-counting.slog:301 #f)
  class ReadTask390 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex375;  slog::Index** lambdaindex376;  slog::Index** refindex377;  slog::Index** lambdaindex378;  slog::Index** refindex379;  slog::Index** appindex380;  slog::Index** lambdaindex381;  slog::Index** refindex382;  slog::Index** lambdaindex383;  slog::Index** refindex384;  slog::Index** lambdaindex385;  slog::Index** refindex386;  slog::Index** appindex387;  slog::Index** appindex388;  slog::Index** lambdaindex389;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      std::vector<u16> ord391({1, 2, 0});
      slog::Relation* readrel392 = db->getRelation("lambda");
      head_index[0] = readrel392->getIndex(ord391, false);
      std::vector<u16> ord393({1, 0});
      slog::Relation* readrel394 = db->getRelation("ref");
      refindex375 = readrel394->getIndex(ord393, false);
      std::vector<u16> ord395({1, 2, 0});
      slog::Relation* readrel396 = db->getRelation("lambda");
      lambdaindex376 = readrel396->getIndex(ord395, false);
      std::vector<u16> ord397({1, 0});
      slog::Relation* readrel398 = db->getRelation("ref");
      refindex377 = readrel398->getIndex(ord397, false);
      std::vector<u16> ord399({1, 2, 0});
      slog::Relation* readrel400 = db->getRelation("lambda");
      lambdaindex378 = readrel400->getIndex(ord399, false);
      std::vector<u16> ord401({1, 0});
      slog::Relation* readrel402 = db->getRelation("ref");
      refindex379 = readrel402->getIndex(ord401, false);
      std::vector<u16> ord403({1, 2, 0});
      slog::Relation* readrel404 = db->getRelation("app");
      appindex380 = readrel404->getIndex(ord403, false);
      std::vector<u16> ord405({1, 2, 0});
      slog::Relation* readrel406 = db->getRelation("lambda");
      lambdaindex381 = readrel406->getIndex(ord405, false);
      std::vector<u16> ord407({1, 0});
      slog::Relation* readrel408 = db->getRelation("ref");
      refindex382 = readrel408->getIndex(ord407, false);
      std::vector<u16> ord409({1, 2, 0});
      slog::Relation* readrel410 = db->getRelation("lambda");
      lambdaindex383 = readrel410->getIndex(ord409, false);
      std::vector<u16> ord411({1, 0});
      slog::Relation* readrel412 = db->getRelation("ref");
      refindex384 = readrel412->getIndex(ord411, false);
      std::vector<u16> ord413({1, 2, 0});
      slog::Relation* readrel414 = db->getRelation("lambda");
      lambdaindex385 = readrel414->getIndex(ord413, false);
      std::vector<u16> ord415({1, 0});
      slog::Relation* readrel416 = db->getRelation("ref");
      refindex386 = readrel416->getIndex(ord415, false);
      std::vector<u16> ord417({1, 2, 0});
      slog::Relation* readrel418 = db->getRelation("app");
      appindex387 = readrel418->getIndex(ord417, false);
      std::vector<u16> ord419({1, 2, 0});
      slog::Relation* readrel420 = db->getRelation("app");
      appindex388 = readrel420->getIndex(ord419, false);
      std::vector<u16> ord421({1, 2, 0});
      slog::Relation* readrel422 = db->getRelation("lambda");
      lambdaindex389 = readrel422->getIndex(ord421, false);
  
    }
    ReadTask390(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c75 = v_const6cf13cc59dcbe759113f68a4;
      u64 v_c76 = v_constcaa3ee5a2828a31924f6b39d;
      u64 v_c77 = v_const970c20ea81b833e5b5a7accf;
      u64 v_c78 = v_constc40f204dda7ba4054abb9e74;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex375, std::array<u64,2>{v_c75, 0}, [&](const std::array<u64,2>& m423) {
        u64 v_c79 = m423[1];
        if (!slog::exists_probe<3,1>(lambdaindex376, std::array<u64,3>{v_c78, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex377, std::array<u64,2>{v_c77, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex378, std::array<u64,3>{v_c77, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex379, std::array<u64,2>{v_c76, 0})) return;
        if (!slog::exists_probe<3,1>(appindex380, std::array<u64,3>{v_c79, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex381, std::array<u64,3>{v_c76, 0, 0})) return;
        slog::join_probe<2,1>(refindex382, std::array<u64,2>{v_c78, 0}, [&](const std::array<u64,2>& m424) {
          u64 v_c80 = m424[1];
          slog::join_probe<3,2>(lambdaindex383, std::array<u64,3>{v_c78, v_c80, 0}, [&](const std::array<u64,3>& m425) {
            u64 v_c81 = m425[2];
            slog::join_probe<2,1>(refindex384, std::array<u64,2>{v_c77, 0}, [&](const std::array<u64,2>& m426) {
              u64 v_c82 = m426[1];
              slog::join_probe<3,2>(lambdaindex385, std::array<u64,3>{v_c77, v_c82, 0}, [&](const std::array<u64,3>& m427) {
                u64 v_c83 = m427[2];
                slog::join_probe<2,1>(refindex386, std::array<u64,2>{v_c76, 0}, [&](const std::array<u64,2>& m428) {
                  u64 v_c84 = m428[1];
                  slog::join_probe<3,2>(appindex387, std::array<u64,3>{v_c79, v_c84, 0}, [&](const std::array<u64,3>& m429) {
                    u64 v_c85 = m429[2];
                    slog::join_probe<3,2>(appindex388, std::array<u64,3>{v_c79, v_c85, 0}, [&](const std::array<u64,3>& m430) {
                      u64 v_c86 = m430[2];
                      slog::join_probe<3,2>(lambdaindex389, std::array<u64,3>{v_c76, v_c86, 0}, [&](const std::array<u64,3>& m431) {
                        u64 v_c87 = m431[2];
                        ++_fires;
                        slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c75, v_c87}, std::array<u16,3>{1, 2, 0});
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
      s->addTaskSeeded(phase_read, new ReadTask390(db,b));
  // (crule (pre (let __tconst4Xaz41 const81cb39a72a584ab4f703b7f7) (let __tconst1aIN38 const4d5ce1398140fbe27561181f) (let __tconst4xzG22 constdbf1bdba02122b2adce28528) (let __tconst1ha033 const969c6e56242ce8d0a4346602) (let __tconst37GM26 const85f09fa1913b9daf65957cf7) (let __tconst1HMF17 constd7a1925d249b4768c8a9f2d8)) (scan app __t3b2k21 __t2DOE20 __t2wNc18) (body (join ref (0 1) 2 __t2DOE20 __tconst4xzG22) (exists ref (1 0) 1 __tconst1HMF17) (exists ref (1 0) 1 __tconst4Xaz41) (exists ref (1 0) 1 __tconst37GM26) (exists lambda (1 2 0) 1 __tconst37GM26) (exists ref (1 0) 1 __tconst1ha033) (exists lambda (1 2 0) 1 __tconst1ha033) (join lambda (0 1 2) 2 __t2wNc18 __tconst1HMF17 __t7H1u16) (join ref (0 1) 2 __t7H1u16 __tconst1HMF17) (join ref (1 0) 1 __tconst4Xaz41 __t75SZ29) (exists app (1 2 0) 1 __t75SZ29) (join ref (1 0) 1 __tconst37GM26 __t7U1m25) (join lambda (1 2 0) 2 __tconst37GM26 __t7U1m25 __t5myE27) (join app (1 2 0) 2 __t75SZ29 __t5myE27 __t2Vg230) (join ref (1 0) 1 __tconst1ha033 __t7N9A32) (join lambda (1 2 0) 2 __tconst1ha033 __t7N9A32 __t065j34) (join app (1 2 0) 2 __t75SZ29 __t065j34 __t3pMW37)) (head (mkstruct lambda (1 2 0) __t3aRV39 __tconst1aIN38 __t3pMW37) (mkstruct lambda (1 2 0) __t8Ovw23 __tconst4xzG22 __t3b2k21)) mcfa-counting.slog:260 #f)
  class ReadTask449 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex432;  slog::Index** refindex433;  slog::Index** refindex434;  slog::Index** refindex435;  slog::Index** lambdaindex436;  slog::Index** refindex437;  slog::Index** lambdaindex438;  slog::Index** lambdaindex439;  slog::Index** refindex440;  slog::Index** refindex441;  slog::Index** appindex442;  slog::Index** refindex443;  slog::Index** lambdaindex444;  slog::Index** appindex445;  slog::Index** refindex446;  slog::Index** lambdaindex447;  slog::Index** appindex448;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      head_rel[1] = db->getRelation("lambda");
      outer_rel = db->getRelation("app");
      std::vector<u16> ord450({0, 1});
      slog::Relation* readrel451 = db->getRelation("ref");
      refindex432 = readrel451->getIndex(ord450, false);
      std::vector<u16> ord452({1, 0});
      slog::Relation* readrel453 = db->getRelation("ref");
      refindex433 = readrel453->getIndex(ord452, false);
      std::vector<u16> ord454({1, 0});
      slog::Relation* readrel455 = db->getRelation("ref");
      refindex434 = readrel455->getIndex(ord454, false);
      std::vector<u16> ord456({1, 0});
      slog::Relation* readrel457 = db->getRelation("ref");
      refindex435 = readrel457->getIndex(ord456, false);
      std::vector<u16> ord458({1, 2, 0});
      slog::Relation* readrel459 = db->getRelation("lambda");
      lambdaindex436 = readrel459->getIndex(ord458, false);
      std::vector<u16> ord460({1, 0});
      slog::Relation* readrel461 = db->getRelation("ref");
      refindex437 = readrel461->getIndex(ord460, false);
      std::vector<u16> ord462({1, 2, 0});
      slog::Relation* readrel463 = db->getRelation("lambda");
      lambdaindex438 = readrel463->getIndex(ord462, false);
      std::vector<u16> ord464({0, 1, 2});
      slog::Relation* readrel465 = db->getRelation("lambda");
      lambdaindex439 = readrel465->getIndex(ord464, false);
      std::vector<u16> ord466({0, 1});
      slog::Relation* readrel467 = db->getRelation("ref");
      refindex440 = readrel467->getIndex(ord466, false);
      std::vector<u16> ord468({1, 0});
      slog::Relation* readrel469 = db->getRelation("ref");
      refindex441 = readrel469->getIndex(ord468, false);
      std::vector<u16> ord470({1, 2, 0});
      slog::Relation* readrel471 = db->getRelation("app");
      appindex442 = readrel471->getIndex(ord470, false);
      std::vector<u16> ord472({1, 0});
      slog::Relation* readrel473 = db->getRelation("ref");
      refindex443 = readrel473->getIndex(ord472, false);
      std::vector<u16> ord474({1, 2, 0});
      slog::Relation* readrel475 = db->getRelation("lambda");
      lambdaindex444 = readrel475->getIndex(ord474, false);
      std::vector<u16> ord476({1, 2, 0});
      slog::Relation* readrel477 = db->getRelation("app");
      appindex445 = readrel477->getIndex(ord476, false);
      std::vector<u16> ord478({1, 0});
      slog::Relation* readrel479 = db->getRelation("ref");
      refindex446 = readrel479->getIndex(ord478, false);
      std::vector<u16> ord480({1, 2, 0});
      slog::Relation* readrel481 = db->getRelation("lambda");
      lambdaindex447 = readrel481->getIndex(ord480, false);
      std::vector<u16> ord482({1, 2, 0});
      slog::Relation* readrel483 = db->getRelation("app");
      appindex448 = readrel483->getIndex(ord482, false);
  
    }
    ReadTask449(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c88 = v_const81cb39a72a584ab4f703b7f7;
      u64 v_c89 = v_const4d5ce1398140fbe27561181f;
      u64 v_c90 = v_constdbf1bdba02122b2adce28528;
      u64 v_c91 = v_const969c6e56242ce8d0a4346602;
      u64 v_c92 = v_const85f09fa1913b9daf65957cf7;
      u64 v_c93 = v_constd7a1925d249b4768c8a9f2d8;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c94 = _t[0];
        u64 v_c95 = _t[1];
        u64 v_c96 = _t[2];
        slog::join_probe<2,2>(refindex432, std::array<u64,2>{v_c95, v_c90}, [&](const std::array<u64,2>& m484) {
          if (!slog::exists_probe<2,1>(refindex433, std::array<u64,2>{v_c93, 0})) return;
          if (!slog::exists_probe<2,1>(refindex434, std::array<u64,2>{v_c88, 0})) return;
          if (!slog::exists_probe<2,1>(refindex435, std::array<u64,2>{v_c92, 0})) return;
          if (!slog::exists_probe<3,1>(lambdaindex436, std::array<u64,3>{v_c92, 0, 0})) return;
          if (!slog::exists_probe<2,1>(refindex437, std::array<u64,2>{v_c91, 0})) return;
          if (!slog::exists_probe<3,1>(lambdaindex438, std::array<u64,3>{v_c91, 0, 0})) return;
          slog::join_probe<3,2>(lambdaindex439, std::array<u64,3>{v_c96, v_c93, 0}, [&](const std::array<u64,3>& m485) {
            u64 v_c97 = m485[2];
            slog::join_probe<2,2>(refindex440, std::array<u64,2>{v_c97, v_c93}, [&](const std::array<u64,2>& m486) {
              slog::join_probe<2,1>(refindex441, std::array<u64,2>{v_c88, 0}, [&](const std::array<u64,2>& m487) {
                u64 v_c98 = m487[1];
                if (!slog::exists_probe<3,1>(appindex442, std::array<u64,3>{v_c98, 0, 0})) return;
                slog::join_probe<2,1>(refindex443, std::array<u64,2>{v_c92, 0}, [&](const std::array<u64,2>& m488) {
                  u64 v_c99 = m488[1];
                  slog::join_probe<3,2>(lambdaindex444, std::array<u64,3>{v_c92, v_c99, 0}, [&](const std::array<u64,3>& m489) {
                    u64 v_c100 = m489[2];
                    slog::join_probe<3,2>(appindex445, std::array<u64,3>{v_c98, v_c100, 0}, [&](const std::array<u64,3>& m490) {
                      u64 v_c101 = m490[2];
                      slog::join_probe<2,1>(refindex446, std::array<u64,2>{v_c91, 0}, [&](const std::array<u64,2>& m491) {
                        u64 v_c102 = m491[1];
                        slog::join_probe<3,2>(lambdaindex447, std::array<u64,3>{v_c91, v_c102, 0}, [&](const std::array<u64,3>& m492) {
                          u64 v_c103 = m492[2];
                          slog::join_probe<3,2>(appindex448, std::array<u64,3>{v_c98, v_c103, 0}, [&](const std::array<u64,3>& m493) {
                            u64 v_c104 = m493[2];
                            ++_fires;
                            slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c89, v_c104}, std::array<u16,3>{1, 2, 0});
                            slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c90, v_c94}, std::array<u16,3>{1, 2, 0});
                          });
                        });
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
  
      if (_fires) db->bumpFires("mcfa-counting.slog:260", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask449* _cont = new ReadTask449(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask449(db,b), false);
  // (crule (pre) (scan eval_ans __t4j5Q160 va) (body (join-old eval (0 2 1) 1 (0 2 1) __t4j5Q160 c ea) (exists eval (2 0 1) 1 c) (join $sup27994x83x0x0x0 (1 2 0 3) 2 c ea __d0 ef) (join-old eval (1 2 0) 2 (1 2 0) ef c __t8nKY157) (join eval_ans (0 1) 1 __t8nKY157 __t3EGT159) (join-old clo (0 2 1) 1 (0 2 1) __t3EGT159 cb __t1L8v158) (join-old lambda (0 1 2) 1 (0 1 2) __t1L8v158 x eb)) (head (emit $sup27994x83x0x0x1 (1 4 0 2 3 5 6 7 8 9) __t8nKY157 cb __d0 __t4j5Q160 c ea eb ef va x)) mcfa-counting.slog:84 #f)
  class ReadTask505 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex494;  slog::Index** evalindex495;  slog::Index** $sup27994x83x0x0x0index496;  slog::Index** evalindex497;  slog::Index** eval_ansindex498;  slog::Index** cloindex499;  slog::Index** lambdaindex500;  slog::Index** evaldelta501;  slog::Index** evaldelta502;  slog::Index** clodelta503;  slog::Index** lambdadelta504;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup27994x83x0x0x1");
      std::vector<u16> ord506({1, 4, 0, 2, 3, 5, 6, 7, 8, 9});
      slog::Relation* readrel507 = db->getRelation("$sup27994x83x0x0x1");
      head_index[0] = readrel507->getIndex(ord506, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord508({0, 2, 1});
      slog::Relation* readrel509 = db->getRelation("eval");
      evalindex494 = readrel509->getIndex(ord508, false);
      std::vector<u16> ord510({0, 2, 1});
      slog::Relation* readrel511 = db->getRelation("eval");
      evaldelta501 = readrel511->getIndex(ord510, true);
      std::vector<u16> ord512({2, 0, 1});
      slog::Relation* readrel513 = db->getRelation("eval");
      evalindex495 = readrel513->getIndex(ord512, false);
      std::vector<u16> ord514({1, 2, 0, 3});
      slog::Relation* readrel515 = db->getRelation("$sup27994x83x0x0x0");
      $sup27994x83x0x0x0index496 = readrel515->getIndex(ord514, false);
      std::vector<u16> ord516({1, 2, 0});
      slog::Relation* readrel517 = db->getRelation("eval");
      evalindex497 = readrel517->getIndex(ord516, false);
      std::vector<u16> ord518({1, 2, 0});
      slog::Relation* readrel519 = db->getRelation("eval");
      evaldelta502 = readrel519->getIndex(ord518, true);
      std::vector<u16> ord520({0, 1});
      slog::Relation* readrel521 = db->getRelation("eval_ans");
      eval_ansindex498 = readrel521->getIndex(ord520, false);
      std::vector<u16> ord522({0, 2, 1});
      slog::Relation* readrel523 = db->getRelation("clo");
      cloindex499 = readrel523->getIndex(ord522, false);
      std::vector<u16> ord524({0, 2, 1});
      slog::Relation* readrel525 = db->getRelation("clo");
      clodelta503 = readrel525->getIndex(ord524, true);
      std::vector<u16> ord526({0, 1, 2});
      slog::Relation* readrel527 = db->getRelation("lambda");
      lambdaindex500 = readrel527->getIndex(ord526, false);
      std::vector<u16> ord528({0, 1, 2});
      slog::Relation* readrel529 = db->getRelation("lambda");
      lambdadelta504 = readrel529->getIndex(ord528, true);
  
    }
    ReadTask505(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c105 = _t[0];
        u64 v_c47 = _t[1];
        slog::join_probe_old<3,1>(evalindex494, evaldelta501, std::array<u64,3>{v_c105, 0, 0}, [&](const std::array<u64,3>& m530) {
          u64 v_c3 = m530[1]; u64 v_c2 = m530[2];
          if (!slog::exists_probe<3,1>(evalindex495, std::array<u64,3>{v_c3, 0, 0})) return;
          slog::join_probe<4,2>($sup27994x83x0x0x0index496, std::array<u64,4>{v_c3, v_c2, 0, 0}, [&](const std::array<u64,4>& m531) {
            u64 v_c106 = m531[2]; u64 v_c1 = m531[3];
            slog::join_probe_old<3,2>(evalindex497, evaldelta502, std::array<u64,3>{v_c1, v_c3, 0}, [&](const std::array<u64,3>& m532) {
              u64 v_c107 = m532[2];
              slog::join_probe<2,1>(eval_ansindex498, std::array<u64,2>{v_c107, 0}, [&](const std::array<u64,2>& m533) {
                u64 v_c108 = m533[1];
                slog::join_probe_old<3,1>(cloindex499, clodelta503, std::array<u64,3>{v_c108, 0, 0}, [&](const std::array<u64,3>& m534) {
                  u64 v_c7 = m534[1]; u64 v_c109 = m534[2];
                  slog::join_probe_old<3,1>(lambdaindex500, lambdadelta504, std::array<u64,3>{v_c109, 0, 0}, [&](const std::array<u64,3>& m535) {
                    u64 v_c9 = m535[1]; u64 v_c10 = m535[2];
                    ++_fires;
                    slog::emit<10>(head_rel[0], head_index[0], newbatch[0], std::array<u64,10>{v_c107, v_c7, v_c106, v_c105, v_c3, v_c2, v_c10, v_c1, v_c47, v_c9}, std::array<u16,10>{1, 4, 0, 2, 3, 5, 6, 7, 8, 9});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:84", "delta:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask505* _cont = new ReadTask505(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask505(db,b), false);
  // (crule (pre (let __tconst1pJW313 constb49bea2fcccd8f4301a347ed) (let __tconst7LWP310 const66518c0c1b3a5a0b09ae2ef1) (let __tconst5PoN291 constc85eae03730a4f4cf1d66a0c) (let __tconst2Yzp284 const8ca682693a0738a0641c6956) (let __tconst0sqO307 const4a8acfc71441e0695ffcf5b3) (let __tconst9rZO295 const576506f61f53440f1edd95d2) (let __tconst2CSv302 const229c0b7aa8a7eb4055f5a3d0)) (seeded) (body (join ref (1 0) 1 __tconst2Yzp284 __t248W283) (exists ref (1 0) 1 __tconst1pJW313) (exists ref (1 0) 1 __tconst7LWP310) (exists ref (1 0) 1 __tconst9rZO295) (exists lambda (1 2 0) 1 __tconst9rZO295) (exists ref (1 0) 1 __tconst2CSv302) (exists lambda (1 2 0) 1 __tconst2CSv302) (exists lambda (1 2 0) 1 __tconst0sqO307) (exists lambda (1 2 0) 1 __tconst7LWP310) (exists lambda (1 2 0) 1 __tconst5PoN291) (join lambda (1 2 0) 2 __tconst2Yzp284 __t248W283 __t0oFu285) (join ref (1 0) 1 __tconst1pJW313 __t165O287) (exists app (1 2 0) 1 __t165O287) (join ref (1 0) 1 __tconst7LWP310 __t91H2298) (exists app (1 2 0) 1 __t91H2298) (join ref (1 0) 1 __tconst9rZO295 __t71w7294) (join lambda (1 2 0) 2 __tconst9rZO295 __t71w7294 __t3dkk296) (join app (1 2 0) 2 __t91H2298 __t3dkk296 __t4LtH299) (exists app (2 0 1) 1 __t4LtH299) (join ref (1 0) 1 __tconst2CSv302 __t6lXa301) (join lambda (1 2 0) 2 __tconst2CSv302 __t6lXa301 __t7EW2303) (join app (1 2 0) 2 __t91H2298 __t7EW2303 __t4HUX306) (join lambda (1 2 0) 2 __tconst0sqO307 __t4HUX306 __t0vn1308) (join app (1 2 0) 2 __t0vn1308 __t4LtH299 __t6t9L309) (join lambda (1 2 0) 2 __tconst7LWP310 __t6t9L309 __t5T0g311) (exists app (1 2 0) 1 __t5T0g311) (join app (1 2 0) 1 __t165O287 dup8TUu386 __t30Ec290) (eq __t165O287 dup8TUu386) (join lambda (1 2 0) 2 __tconst5PoN291 __t30Ec290 __t7aCZ292) (join app (1 2 0) 2 __t5T0g311 __t7aCZ292 __t3Izn312)) (head (mkstruct lambda (1 2 0) __t7Qbz314 __tconst1pJW313 __t3Izn312)) mcfa-counting.slog:194 #f)
  class ReadTask565 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex536;  slog::Index** refindex537;  slog::Index** refindex538;  slog::Index** refindex539;  slog::Index** lambdaindex540;  slog::Index** refindex541;  slog::Index** lambdaindex542;  slog::Index** lambdaindex543;  slog::Index** lambdaindex544;  slog::Index** lambdaindex545;  slog::Index** lambdaindex546;  slog::Index** refindex547;  slog::Index** appindex548;  slog::Index** refindex549;  slog::Index** appindex550;  slog::Index** refindex551;  slog::Index** lambdaindex552;  slog::Index** appindex553;  slog::Index** appindex554;  slog::Index** refindex555;  slog::Index** lambdaindex556;  slog::Index** appindex557;  slog::Index** lambdaindex558;  slog::Index** appindex559;  slog::Index** lambdaindex560;  slog::Index** appindex561;  slog::Index** appindex562;  slog::Index** lambdaindex563;  slog::Index** appindex564;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      std::vector<u16> ord566({1, 2, 0});
      slog::Relation* readrel567 = db->getRelation("lambda");
      head_index[0] = readrel567->getIndex(ord566, false);
      std::vector<u16> ord568({1, 0});
      slog::Relation* readrel569 = db->getRelation("ref");
      refindex536 = readrel569->getIndex(ord568, false);
      std::vector<u16> ord570({1, 0});
      slog::Relation* readrel571 = db->getRelation("ref");
      refindex537 = readrel571->getIndex(ord570, false);
      std::vector<u16> ord572({1, 0});
      slog::Relation* readrel573 = db->getRelation("ref");
      refindex538 = readrel573->getIndex(ord572, false);
      std::vector<u16> ord574({1, 0});
      slog::Relation* readrel575 = db->getRelation("ref");
      refindex539 = readrel575->getIndex(ord574, false);
      std::vector<u16> ord576({1, 2, 0});
      slog::Relation* readrel577 = db->getRelation("lambda");
      lambdaindex540 = readrel577->getIndex(ord576, false);
      std::vector<u16> ord578({1, 0});
      slog::Relation* readrel579 = db->getRelation("ref");
      refindex541 = readrel579->getIndex(ord578, false);
      std::vector<u16> ord580({1, 2, 0});
      slog::Relation* readrel581 = db->getRelation("lambda");
      lambdaindex542 = readrel581->getIndex(ord580, false);
      std::vector<u16> ord582({1, 2, 0});
      slog::Relation* readrel583 = db->getRelation("lambda");
      lambdaindex543 = readrel583->getIndex(ord582, false);
      std::vector<u16> ord584({1, 2, 0});
      slog::Relation* readrel585 = db->getRelation("lambda");
      lambdaindex544 = readrel585->getIndex(ord584, false);
      std::vector<u16> ord586({1, 2, 0});
      slog::Relation* readrel587 = db->getRelation("lambda");
      lambdaindex545 = readrel587->getIndex(ord586, false);
      std::vector<u16> ord588({1, 2, 0});
      slog::Relation* readrel589 = db->getRelation("lambda");
      lambdaindex546 = readrel589->getIndex(ord588, false);
      std::vector<u16> ord590({1, 0});
      slog::Relation* readrel591 = db->getRelation("ref");
      refindex547 = readrel591->getIndex(ord590, false);
      std::vector<u16> ord592({1, 2, 0});
      slog::Relation* readrel593 = db->getRelation("app");
      appindex548 = readrel593->getIndex(ord592, false);
      std::vector<u16> ord594({1, 0});
      slog::Relation* readrel595 = db->getRelation("ref");
      refindex549 = readrel595->getIndex(ord594, false);
      std::vector<u16> ord596({1, 2, 0});
      slog::Relation* readrel597 = db->getRelation("app");
      appindex550 = readrel597->getIndex(ord596, false);
      std::vector<u16> ord598({1, 0});
      slog::Relation* readrel599 = db->getRelation("ref");
      refindex551 = readrel599->getIndex(ord598, false);
      std::vector<u16> ord600({1, 2, 0});
      slog::Relation* readrel601 = db->getRelation("lambda");
      lambdaindex552 = readrel601->getIndex(ord600, false);
      std::vector<u16> ord602({1, 2, 0});
      slog::Relation* readrel603 = db->getRelation("app");
      appindex553 = readrel603->getIndex(ord602, false);
      std::vector<u16> ord604({2, 0, 1});
      slog::Relation* readrel605 = db->getRelation("app");
      appindex554 = readrel605->getIndex(ord604, false);
      std::vector<u16> ord606({1, 0});
      slog::Relation* readrel607 = db->getRelation("ref");
      refindex555 = readrel607->getIndex(ord606, false);
      std::vector<u16> ord608({1, 2, 0});
      slog::Relation* readrel609 = db->getRelation("lambda");
      lambdaindex556 = readrel609->getIndex(ord608, false);
      std::vector<u16> ord610({1, 2, 0});
      slog::Relation* readrel611 = db->getRelation("app");
      appindex557 = readrel611->getIndex(ord610, false);
      std::vector<u16> ord612({1, 2, 0});
      slog::Relation* readrel613 = db->getRelation("lambda");
      lambdaindex558 = readrel613->getIndex(ord612, false);
      std::vector<u16> ord614({1, 2, 0});
      slog::Relation* readrel615 = db->getRelation("app");
      appindex559 = readrel615->getIndex(ord614, false);
      std::vector<u16> ord616({1, 2, 0});
      slog::Relation* readrel617 = db->getRelation("lambda");
      lambdaindex560 = readrel617->getIndex(ord616, false);
      std::vector<u16> ord618({1, 2, 0});
      slog::Relation* readrel619 = db->getRelation("app");
      appindex561 = readrel619->getIndex(ord618, false);
      std::vector<u16> ord620({1, 2, 0});
      slog::Relation* readrel621 = db->getRelation("app");
      appindex562 = readrel621->getIndex(ord620, false);
      std::vector<u16> ord622({1, 2, 0});
      slog::Relation* readrel623 = db->getRelation("lambda");
      lambdaindex563 = readrel623->getIndex(ord622, false);
      std::vector<u16> ord624({1, 2, 0});
      slog::Relation* readrel625 = db->getRelation("app");
      appindex564 = readrel625->getIndex(ord624, false);
  
    }
    ReadTask565(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c110 = v_constb49bea2fcccd8f4301a347ed;
      u64 v_c111 = v_const66518c0c1b3a5a0b09ae2ef1;
      u64 v_c112 = v_constc85eae03730a4f4cf1d66a0c;
      u64 v_c113 = v_const8ca682693a0738a0641c6956;
      u64 v_c114 = v_const4a8acfc71441e0695ffcf5b3;
      u64 v_c115 = v_const576506f61f53440f1edd95d2;
      u64 v_c116 = v_const229c0b7aa8a7eb4055f5a3d0;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex536, std::array<u64,2>{v_c113, 0}, [&](const std::array<u64,2>& m626) {
        u64 v_c117 = m626[1];
        if (!slog::exists_probe<2,1>(refindex537, std::array<u64,2>{v_c110, 0})) return;
        if (!slog::exists_probe<2,1>(refindex538, std::array<u64,2>{v_c111, 0})) return;
        if (!slog::exists_probe<2,1>(refindex539, std::array<u64,2>{v_c115, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex540, std::array<u64,3>{v_c115, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex541, std::array<u64,2>{v_c116, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex542, std::array<u64,3>{v_c116, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex543, std::array<u64,3>{v_c114, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex544, std::array<u64,3>{v_c111, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex545, std::array<u64,3>{v_c112, 0, 0})) return;
        slog::join_probe<3,2>(lambdaindex546, std::array<u64,3>{v_c113, v_c117, 0}, [&](const std::array<u64,3>& m627) {
          u64 v_c118 = m627[2];
          slog::join_probe<2,1>(refindex547, std::array<u64,2>{v_c110, 0}, [&](const std::array<u64,2>& m628) {
            u64 v_c119 = m628[1];
            if (!slog::exists_probe<3,1>(appindex548, std::array<u64,3>{v_c119, 0, 0})) return;
            slog::join_probe<2,1>(refindex549, std::array<u64,2>{v_c111, 0}, [&](const std::array<u64,2>& m629) {
              u64 v_c120 = m629[1];
              if (!slog::exists_probe<3,1>(appindex550, std::array<u64,3>{v_c120, 0, 0})) return;
              slog::join_probe<2,1>(refindex551, std::array<u64,2>{v_c115, 0}, [&](const std::array<u64,2>& m630) {
                u64 v_c121 = m630[1];
                slog::join_probe<3,2>(lambdaindex552, std::array<u64,3>{v_c115, v_c121, 0}, [&](const std::array<u64,3>& m631) {
                  u64 v_c122 = m631[2];
                  slog::join_probe<3,2>(appindex553, std::array<u64,3>{v_c120, v_c122, 0}, [&](const std::array<u64,3>& m632) {
                    u64 v_c123 = m632[2];
                    if (!slog::exists_probe<3,1>(appindex554, std::array<u64,3>{v_c123, 0, 0})) return;
                    slog::join_probe<2,1>(refindex555, std::array<u64,2>{v_c116, 0}, [&](const std::array<u64,2>& m633) {
                      u64 v_c124 = m633[1];
                      slog::join_probe<3,2>(lambdaindex556, std::array<u64,3>{v_c116, v_c124, 0}, [&](const std::array<u64,3>& m634) {
                        u64 v_c125 = m634[2];
                        slog::join_probe<3,2>(appindex557, std::array<u64,3>{v_c120, v_c125, 0}, [&](const std::array<u64,3>& m635) {
                          u64 v_c126 = m635[2];
                          slog::join_probe<3,2>(lambdaindex558, std::array<u64,3>{v_c114, v_c126, 0}, [&](const std::array<u64,3>& m636) {
                            u64 v_c127 = m636[2];
                            slog::join_probe<3,2>(appindex559, std::array<u64,3>{v_c127, v_c123, 0}, [&](const std::array<u64,3>& m637) {
                              u64 v_c128 = m637[2];
                              slog::join_probe<3,2>(lambdaindex560, std::array<u64,3>{v_c111, v_c128, 0}, [&](const std::array<u64,3>& m638) {
                                u64 v_c129 = m638[2];
                                if (!slog::exists_probe<3,1>(appindex561, std::array<u64,3>{v_c129, 0, 0})) return;
                                slog::join_probe<3,1>(appindex562, std::array<u64,3>{v_c119, 0, 0}, [&](const std::array<u64,3>& m639) {
                                  u64 v_c130 = m639[1]; u64 v_c131 = m639[2];
                                  if (v_c119 != v_c130) return;
                                  slog::join_probe<3,2>(lambdaindex563, std::array<u64,3>{v_c112, v_c131, 0}, [&](const std::array<u64,3>& m640) {
                                    u64 v_c132 = m640[2];
                                    slog::join_probe<3,2>(appindex564, std::array<u64,3>{v_c129, v_c132, 0}, [&](const std::array<u64,3>& m641) {
                                      u64 v_c133 = m641[2];
                                      ++_fires;
                                      slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c110, v_c133}, std::array<u16,3>{1, 2, 0});
                                    });
                                  });
                                });
                              });
                            });
                          });
                        });
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
      s->addTaskSeeded(phase_read, new ReadTask565(db,b));
  // (crule (pre) (scan $sup27994x83x0x0x1 __t5GoB317 __t1FV8318 __t8XTs321 c cb ea eb ef va x) (body (join $sup27994x83x0x0x0 (0 1 2 3) 4 __t5GoB317 c ea ef) (join-old eval (0 2 1) 3 (0 2 1) __t1FV8318 c ef) (join-old eval (0 2 1) 3 (0 2 1) __t8XTs321 c ea) (join eval_ans (0 1) 2 __t8XTs321 va) (exists app (1 2 0) 2 ef ea) (exists lambda (1 2 0) 2 x eb) (exists clo (2 0 1) 1 cb) (exists eval_ans (0 1) 1 __t1FV8318) (exists eval (1 2 0) 1 eb) (join-old eval (0 2 1) 2 (0 2 1) __t5GoB317 c __t3MbO322) (join-old app (0 1 2) 3 (0 1 2) __t3MbO322 ef ea) (exists eval (1 2 0) 2 eb __t3MbO322) (join-old lambda (1 2 0) 2 (1 2 0) x eb __t6vap319) (join-old clo (1 2 0) 2 (1 2 0) __t6vap319 cb __t1oxE320) (join eval_ans (0 1) 2 __t1FV8318 __t1oxE320) (join-old eval (1 2 0) 2 (1 2 0) eb __t3MbO322 __t3H1A323) (join eval_ans (0 1) 1 __t3H1A323 v)) (head (emit eval_ans (0 1) __t5GoB317 v)) mcfa-counting.slog:84 #f)
  class ReadTask666 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup27994x83x0x0x0index642;  slog::Index** evalindex643;  slog::Index** evalindex644;  slog::Index** eval_ansindex645;  slog::Index** appindex646;  slog::Index** lambdaindex647;  slog::Index** cloindex648;  slog::Index** eval_ansindex649;  slog::Index** evalindex650;  slog::Index** evalindex651;  slog::Index** appindex652;  slog::Index** evalindex653;  slog::Index** lambdaindex654;  slog::Index** cloindex655;  slog::Index** eval_ansindex656;  slog::Index** evalindex657;  slog::Index** eval_ansindex658;  slog::Index** evaldelta659;  slog::Index** evaldelta660;  slog::Index** evaldelta661;  slog::Index** appdelta662;  slog::Index** lambdadelta663;  slog::Index** clodelta664;  slog::Index** evaldelta665;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord667({0, 1});
      slog::Relation* readrel668 = db->getRelation("eval_ans");
      head_index[0] = readrel668->getIndex(ord667, false);
      outer_rel = db->getRelation("$sup27994x83x0x0x1");
      std::vector<u16> ord669({0, 1, 2, 3});
      slog::Relation* readrel670 = db->getRelation("$sup27994x83x0x0x0");
      $sup27994x83x0x0x0index642 = readrel670->getIndex(ord669, false);
      std::vector<u16> ord671({0, 2, 1});
      slog::Relation* readrel672 = db->getRelation("eval");
      evalindex643 = readrel672->getIndex(ord671, false);
      std::vector<u16> ord673({0, 2, 1});
      slog::Relation* readrel674 = db->getRelation("eval");
      evaldelta659 = readrel674->getIndex(ord673, true);
      std::vector<u16> ord675({0, 2, 1});
      slog::Relation* readrel676 = db->getRelation("eval");
      evalindex644 = readrel676->getIndex(ord675, false);
      std::vector<u16> ord677({0, 2, 1});
      slog::Relation* readrel678 = db->getRelation("eval");
      evaldelta660 = readrel678->getIndex(ord677, true);
      std::vector<u16> ord679({0, 1});
      slog::Relation* readrel680 = db->getRelation("eval_ans");
      eval_ansindex645 = readrel680->getIndex(ord679, false);
      std::vector<u16> ord681({1, 2, 0});
      slog::Relation* readrel682 = db->getRelation("app");
      appindex646 = readrel682->getIndex(ord681, false);
      std::vector<u16> ord683({1, 2, 0});
      slog::Relation* readrel684 = db->getRelation("lambda");
      lambdaindex647 = readrel684->getIndex(ord683, false);
      std::vector<u16> ord685({2, 0, 1});
      slog::Relation* readrel686 = db->getRelation("clo");
      cloindex648 = readrel686->getIndex(ord685, false);
      std::vector<u16> ord687({0, 1});
      slog::Relation* readrel688 = db->getRelation("eval_ans");
      eval_ansindex649 = readrel688->getIndex(ord687, false);
      std::vector<u16> ord689({1, 2, 0});
      slog::Relation* readrel690 = db->getRelation("eval");
      evalindex650 = readrel690->getIndex(ord689, false);
      std::vector<u16> ord691({0, 2, 1});
      slog::Relation* readrel692 = db->getRelation("eval");
      evalindex651 = readrel692->getIndex(ord691, false);
      std::vector<u16> ord693({0, 2, 1});
      slog::Relation* readrel694 = db->getRelation("eval");
      evaldelta661 = readrel694->getIndex(ord693, true);
      std::vector<u16> ord695({0, 1, 2});
      slog::Relation* readrel696 = db->getRelation("app");
      appindex652 = readrel696->getIndex(ord695, false);
      std::vector<u16> ord697({0, 1, 2});
      slog::Relation* readrel698 = db->getRelation("app");
      appdelta662 = readrel698->getIndex(ord697, true);
      std::vector<u16> ord699({1, 2, 0});
      slog::Relation* readrel700 = db->getRelation("eval");
      evalindex653 = readrel700->getIndex(ord699, false);
      std::vector<u16> ord701({1, 2, 0});
      slog::Relation* readrel702 = db->getRelation("lambda");
      lambdaindex654 = readrel702->getIndex(ord701, false);
      std::vector<u16> ord703({1, 2, 0});
      slog::Relation* readrel704 = db->getRelation("lambda");
      lambdadelta663 = readrel704->getIndex(ord703, true);
      std::vector<u16> ord705({1, 2, 0});
      slog::Relation* readrel706 = db->getRelation("clo");
      cloindex655 = readrel706->getIndex(ord705, false);
      std::vector<u16> ord707({1, 2, 0});
      slog::Relation* readrel708 = db->getRelation("clo");
      clodelta664 = readrel708->getIndex(ord707, true);
      std::vector<u16> ord709({0, 1});
      slog::Relation* readrel710 = db->getRelation("eval_ans");
      eval_ansindex656 = readrel710->getIndex(ord709, false);
      std::vector<u16> ord711({1, 2, 0});
      slog::Relation* readrel712 = db->getRelation("eval");
      evalindex657 = readrel712->getIndex(ord711, false);
      std::vector<u16> ord713({1, 2, 0});
      slog::Relation* readrel714 = db->getRelation("eval");
      evaldelta665 = readrel714->getIndex(ord713, true);
      std::vector<u16> ord715({0, 1});
      slog::Relation* readrel716 = db->getRelation("eval_ans");
      eval_ansindex658 = readrel716->getIndex(ord715, false);
  
    }
    ReadTask666(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c135 = _t[1];
        u64 v_c136 = _t[2];
        u64 v_c3 = _t[3];
        u64 v_c7 = _t[4];
        u64 v_c2 = _t[5];
        u64 v_c10 = _t[6];
        u64 v_c1 = _t[7];
        u64 v_c47 = _t[8];
        u64 v_c9 = _t[9];
        slog::join_probe<4,4>($sup27994x83x0x0x0index642, std::array<u64,4>{v_c134, v_c3, v_c2, v_c1}, [&](const std::array<u64,4>& m717) {
          slog::join_probe_old<3,3>(evalindex643, evaldelta659, std::array<u64,3>{v_c135, v_c3, v_c1}, [&](const std::array<u64,3>& m718) {
            slog::join_probe_old<3,3>(evalindex644, evaldelta660, std::array<u64,3>{v_c136, v_c3, v_c2}, [&](const std::array<u64,3>& m719) {
              slog::join_probe<2,2>(eval_ansindex645, std::array<u64,2>{v_c136, v_c47}, [&](const std::array<u64,2>& m720) {
                if (!slog::exists_probe<3,2>(appindex646, std::array<u64,3>{v_c1, v_c2, 0})) return;
                if (!slog::exists_probe<3,2>(lambdaindex647, std::array<u64,3>{v_c9, v_c10, 0})) return;
                if (!slog::exists_probe<3,1>(cloindex648, std::array<u64,3>{v_c7, 0, 0})) return;
                if (!slog::exists_probe<2,1>(eval_ansindex649, std::array<u64,2>{v_c135, 0})) return;
                if (!slog::exists_probe<3,1>(evalindex650, std::array<u64,3>{v_c10, 0, 0})) return;
                slog::join_probe_old<3,2>(evalindex651, evaldelta661, std::array<u64,3>{v_c134, v_c3, 0}, [&](const std::array<u64,3>& m721) {
                  u64 v_c137 = m721[2];
                  slog::join_probe_old<3,3>(appindex652, appdelta662, std::array<u64,3>{v_c137, v_c1, v_c2}, [&](const std::array<u64,3>& m722) {
                    if (!slog::exists_probe<3,2>(evalindex653, std::array<u64,3>{v_c10, v_c137, 0})) return;
                    slog::join_probe_old<3,2>(lambdaindex654, lambdadelta663, std::array<u64,3>{v_c9, v_c10, 0}, [&](const std::array<u64,3>& m723) {
                      u64 v_c138 = m723[2];
                      slog::join_probe_old<3,2>(cloindex655, clodelta664, std::array<u64,3>{v_c138, v_c7, 0}, [&](const std::array<u64,3>& m724) {
                        u64 v_c139 = m724[2];
                        slog::join_probe<2,2>(eval_ansindex656, std::array<u64,2>{v_c135, v_c139}, [&](const std::array<u64,2>& m725) {
                          slog::join_probe_old<3,2>(evalindex657, evaldelta665, std::array<u64,3>{v_c10, v_c137, 0}, [&](const std::array<u64,3>& m726) {
                            u64 v_c140 = m726[2];
                            slog::join_probe<2,1>(eval_ansindex658, std::array<u64,2>{v_c140, 0}, [&](const std::array<u64,2>& m727) {
                              u64 v_c141 = m727[1];
                              ++_fires;
                              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c134, v_c141}, std::array<u16,2>{0, 1});
                            });
                          });
                        });
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
  
      if (_fires) db->bumpFires("mcfa-counting.slog:84", "delta:$sup27994x83x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask666* _cont = new ReadTask666(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask666(db,b), false);
  // (crule (pre) (scan eval_ans __t1JPZ173 va) (body (join-old eval (0 2 1) 1 (0 2 1) __t1JPZ173 c ea) (exists app (2 0 1) 1 ea) (exists eval (2 0 1) 1 c) (join eval (2 0 1) 1 c __6tlE337 __t5SBy169) (join-old app (2 0 1) 2 (2 0 1) ea __t5SBy169 ef) (join-old eval (1 2 0) 2 (1 2 0) ef c __t6CRg170) (join eval_ans (0 1) 1 __t6CRg170 __t2Hqj172) (join-old clo (0 2 1) 1 (0 2 1) __t2Hqj172 cb __t0RD6171) (join-old lambda (0 1 2) 1 (0 1 2) __t0RD6171 x eb)) (head (emit store (0 1 2) x __t5SBy169 va) (emit callev (0 1) __t5SBy169 c) (emit bindev (0 1 2) x __t5SBy169 c)) mcfa-counting.slog:92 #f)
  class ReadTask742 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex728;  slog::Index** appindex729;  slog::Index** evalindex730;  slog::Index** evalindex731;  slog::Index** appindex732;  slog::Index** evalindex733;  slog::Index** eval_ansindex734;  slog::Index** cloindex735;  slog::Index** lambdaindex736;  slog::Index** evaldelta737;  slog::Index** appdelta738;  slog::Index** evaldelta739;  slog::Index** clodelta740;  slog::Index** lambdadelta741;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("store");
      std::vector<u16> ord743({0, 1, 2});
      slog::Relation* readrel744 = db->getRelation("store");
      head_index[0] = readrel744->getIndex(ord743, false);
      head_rel[1] = db->getRelation("callev");
      std::vector<u16> ord745({0, 1});
      slog::Relation* readrel746 = db->getRelation("callev");
      head_index[1] = readrel746->getIndex(ord745, false);
      head_rel[2] = db->getRelation("bindev");
      std::vector<u16> ord747({0, 1, 2});
      slog::Relation* readrel748 = db->getRelation("bindev");
      head_index[2] = readrel748->getIndex(ord747, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord749({0, 2, 1});
      slog::Relation* readrel750 = db->getRelation("eval");
      evalindex728 = readrel750->getIndex(ord749, false);
      std::vector<u16> ord751({0, 2, 1});
      slog::Relation* readrel752 = db->getRelation("eval");
      evaldelta737 = readrel752->getIndex(ord751, true);
      std::vector<u16> ord753({2, 0, 1});
      slog::Relation* readrel754 = db->getRelation("app");
      appindex729 = readrel754->getIndex(ord753, false);
      std::vector<u16> ord755({2, 0, 1});
      slog::Relation* readrel756 = db->getRelation("eval");
      evalindex730 = readrel756->getIndex(ord755, false);
      std::vector<u16> ord757({2, 0, 1});
      slog::Relation* readrel758 = db->getRelation("eval");
      evalindex731 = readrel758->getIndex(ord757, false);
      std::vector<u16> ord759({2, 0, 1});
      slog::Relation* readrel760 = db->getRelation("app");
      appindex732 = readrel760->getIndex(ord759, false);
      std::vector<u16> ord761({2, 0, 1});
      slog::Relation* readrel762 = db->getRelation("app");
      appdelta738 = readrel762->getIndex(ord761, true);
      std::vector<u16> ord763({1, 2, 0});
      slog::Relation* readrel764 = db->getRelation("eval");
      evalindex733 = readrel764->getIndex(ord763, false);
      std::vector<u16> ord765({1, 2, 0});
      slog::Relation* readrel766 = db->getRelation("eval");
      evaldelta739 = readrel766->getIndex(ord765, true);
      std::vector<u16> ord767({0, 1});
      slog::Relation* readrel768 = db->getRelation("eval_ans");
      eval_ansindex734 = readrel768->getIndex(ord767, false);
      std::vector<u16> ord769({0, 2, 1});
      slog::Relation* readrel770 = db->getRelation("clo");
      cloindex735 = readrel770->getIndex(ord769, false);
      std::vector<u16> ord771({0, 2, 1});
      slog::Relation* readrel772 = db->getRelation("clo");
      clodelta740 = readrel772->getIndex(ord771, true);
      std::vector<u16> ord773({0, 1, 2});
      slog::Relation* readrel774 = db->getRelation("lambda");
      lambdaindex736 = readrel774->getIndex(ord773, false);
      std::vector<u16> ord775({0, 1, 2});
      slog::Relation* readrel776 = db->getRelation("lambda");
      lambdadelta741 = readrel776->getIndex(ord775, true);
  
    }
    ReadTask742(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c142 = _t[0];
        u64 v_c47 = _t[1];
        slog::join_probe_old<3,1>(evalindex728, evaldelta737, std::array<u64,3>{v_c142, 0, 0}, [&](const std::array<u64,3>& m777) {
          u64 v_c3 = m777[1]; u64 v_c2 = m777[2];
          if (!slog::exists_probe<3,1>(appindex729, std::array<u64,3>{v_c2, 0, 0})) return;
          if (!slog::exists_probe<3,1>(evalindex730, std::array<u64,3>{v_c3, 0, 0})) return;
          slog::join_probe<3,1>(evalindex731, std::array<u64,3>{v_c3, 0, 0}, [&](const std::array<u64,3>& m778) {
            u64 v_c143 = m778[1]; u64 v_c144 = m778[2];
            slog::join_probe_old<3,2>(appindex732, appdelta738, std::array<u64,3>{v_c2, v_c144, 0}, [&](const std::array<u64,3>& m779) {
              u64 v_c1 = m779[2];
              slog::join_probe_old<3,2>(evalindex733, evaldelta739, std::array<u64,3>{v_c1, v_c3, 0}, [&](const std::array<u64,3>& m780) {
                u64 v_c145 = m780[2];
                slog::join_probe<2,1>(eval_ansindex734, std::array<u64,2>{v_c145, 0}, [&](const std::array<u64,2>& m781) {
                  u64 v_c146 = m781[1];
                  slog::join_probe_old<3,1>(cloindex735, clodelta740, std::array<u64,3>{v_c146, 0, 0}, [&](const std::array<u64,3>& m782) {
                    u64 v_c7 = m782[1]; u64 v_c147 = m782[2];
                    slog::join_probe_old<3,1>(lambdaindex736, lambdadelta741, std::array<u64,3>{v_c147, 0, 0}, [&](const std::array<u64,3>& m783) {
                      u64 v_c9 = m783[1]; u64 v_c10 = m783[2];
                      ++_fires;
                      slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c9, v_c144, v_c47}, std::array<u16,3>{0, 1, 2});
                      slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c144, v_c3}, std::array<u16,2>{0, 1});
                      slog::emit<3>(head_rel[2], head_index[2], newbatch[2], std::array<u64,3>{v_c9, v_c144, v_c3}, std::array<u16,3>{0, 1, 2});
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
  
      if (_fires) db->bumpFires("mcfa-counting.slog:92", "delta:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask742* _cont = new ReadTask742(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask742(db,b), false);
  // (crule (pre) (scan eval __t1FV8318 ef c) (body (exists $sup27994x83x0x0x1 (1 3 7 4 0 2 5 6 8 9) 3 __t1FV8318 c ef) (exists eval (2 0 1) 1 c) (exists app (1 2 0) 1 ef) (exists eval_ans (0 1) 1 __t1FV8318) (join $sup27994x83x0x0x0 (1 3 0 2) 2 c ef __t5GoB317 ea) (exists eval (1 2 0) 2 ea c) (exists eval (0 2 1) 2 __t5GoB317 c) (exists app (1 2 0) 2 ef ea) (join $sup27994x83x0x0x1 (5 7 0 3 1 2 4 6 8 9) 5 ea ef __t5GoB317 c __t1FV8318 __t8XTs321 cb eb va x) (join-old eval (0 2 1) 3 (0 2 1) __t8XTs321 c ea) (join eval_ans (0 1) 2 __t8XTs321 va) (exists lambda (1 2 0) 2 x eb) (exists clo (2 0 1) 1 cb) (exists eval (1 2 0) 1 eb) (join eval (0 2 1) 2 __t5GoB317 c __t3MbO322) (join-old app (0 1 2) 3 (0 1 2) __t3MbO322 ef ea) (exists eval (1 2 0) 2 eb __t3MbO322) (join-old lambda (1 2 0) 2 (1 2 0) x eb __t6vap319) (join-old clo (1 2 0) 2 (1 2 0) __t6vap319 cb __t1oxE320) (join eval_ans (0 1) 2 __t1FV8318 __t1oxE320) (join-old eval (1 2 0) 2 (1 2 0) eb __t3MbO322 __t3H1A323) (join eval_ans (0 1) 1 __t3H1A323 v)) (head (emit eval_ans (0 1) __t5GoB317 v)) mcfa-counting.slog:84 #f)
  class ReadTask811 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup27994x83x0x0x1index784;  slog::Index** evalindex785;  slog::Index** appindex786;  slog::Index** eval_ansindex787;  slog::Index** $sup27994x83x0x0x0index788;  slog::Index** evalindex789;  slog::Index** evalindex790;  slog::Index** appindex791;  slog::Index** $sup27994x83x0x0x1index792;  slog::Index** evalindex793;  slog::Index** eval_ansindex794;  slog::Index** lambdaindex795;  slog::Index** cloindex796;  slog::Index** evalindex797;  slog::Index** evalindex798;  slog::Index** appindex799;  slog::Index** evalindex800;  slog::Index** lambdaindex801;  slog::Index** cloindex802;  slog::Index** eval_ansindex803;  slog::Index** evalindex804;  slog::Index** eval_ansindex805;  slog::Index** evaldelta806;  slog::Index** appdelta807;  slog::Index** lambdadelta808;  slog::Index** clodelta809;  slog::Index** evaldelta810;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord812({0, 1});
      slog::Relation* readrel813 = db->getRelation("eval_ans");
      head_index[0] = readrel813->getIndex(ord812, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord814({1, 3, 7, 4, 0, 2, 5, 6, 8, 9});
      slog::Relation* readrel815 = db->getRelation("$sup27994x83x0x0x1");
      $sup27994x83x0x0x1index784 = readrel815->getIndex(ord814, false);
      std::vector<u16> ord816({2, 0, 1});
      slog::Relation* readrel817 = db->getRelation("eval");
      evalindex785 = readrel817->getIndex(ord816, false);
      std::vector<u16> ord818({1, 2, 0});
      slog::Relation* readrel819 = db->getRelation("app");
      appindex786 = readrel819->getIndex(ord818, false);
      std::vector<u16> ord820({0, 1});
      slog::Relation* readrel821 = db->getRelation("eval_ans");
      eval_ansindex787 = readrel821->getIndex(ord820, false);
      std::vector<u16> ord822({1, 3, 0, 2});
      slog::Relation* readrel823 = db->getRelation("$sup27994x83x0x0x0");
      $sup27994x83x0x0x0index788 = readrel823->getIndex(ord822, false);
      std::vector<u16> ord824({1, 2, 0});
      slog::Relation* readrel825 = db->getRelation("eval");
      evalindex789 = readrel825->getIndex(ord824, false);
      std::vector<u16> ord826({0, 2, 1});
      slog::Relation* readrel827 = db->getRelation("eval");
      evalindex790 = readrel827->getIndex(ord826, false);
      std::vector<u16> ord828({1, 2, 0});
      slog::Relation* readrel829 = db->getRelation("app");
      appindex791 = readrel829->getIndex(ord828, false);
      std::vector<u16> ord830({5, 7, 0, 3, 1, 2, 4, 6, 8, 9});
      slog::Relation* readrel831 = db->getRelation("$sup27994x83x0x0x1");
      $sup27994x83x0x0x1index792 = readrel831->getIndex(ord830, false);
      std::vector<u16> ord832({0, 2, 1});
      slog::Relation* readrel833 = db->getRelation("eval");
      evalindex793 = readrel833->getIndex(ord832, false);
      std::vector<u16> ord834({0, 2, 1});
      slog::Relation* readrel835 = db->getRelation("eval");
      evaldelta806 = readrel835->getIndex(ord834, true);
      std::vector<u16> ord836({0, 1});
      slog::Relation* readrel837 = db->getRelation("eval_ans");
      eval_ansindex794 = readrel837->getIndex(ord836, false);
      std::vector<u16> ord838({1, 2, 0});
      slog::Relation* readrel839 = db->getRelation("lambda");
      lambdaindex795 = readrel839->getIndex(ord838, false);
      std::vector<u16> ord840({2, 0, 1});
      slog::Relation* readrel841 = db->getRelation("clo");
      cloindex796 = readrel841->getIndex(ord840, false);
      std::vector<u16> ord842({1, 2, 0});
      slog::Relation* readrel843 = db->getRelation("eval");
      evalindex797 = readrel843->getIndex(ord842, false);
      std::vector<u16> ord844({0, 2, 1});
      slog::Relation* readrel845 = db->getRelation("eval");
      evalindex798 = readrel845->getIndex(ord844, false);
      std::vector<u16> ord846({0, 1, 2});
      slog::Relation* readrel847 = db->getRelation("app");
      appindex799 = readrel847->getIndex(ord846, false);
      std::vector<u16> ord848({0, 1, 2});
      slog::Relation* readrel849 = db->getRelation("app");
      appdelta807 = readrel849->getIndex(ord848, true);
      std::vector<u16> ord850({1, 2, 0});
      slog::Relation* readrel851 = db->getRelation("eval");
      evalindex800 = readrel851->getIndex(ord850, false);
      std::vector<u16> ord852({1, 2, 0});
      slog::Relation* readrel853 = db->getRelation("lambda");
      lambdaindex801 = readrel853->getIndex(ord852, false);
      std::vector<u16> ord854({1, 2, 0});
      slog::Relation* readrel855 = db->getRelation("lambda");
      lambdadelta808 = readrel855->getIndex(ord854, true);
      std::vector<u16> ord856({1, 2, 0});
      slog::Relation* readrel857 = db->getRelation("clo");
      cloindex802 = readrel857->getIndex(ord856, false);
      std::vector<u16> ord858({1, 2, 0});
      slog::Relation* readrel859 = db->getRelation("clo");
      clodelta809 = readrel859->getIndex(ord858, true);
      std::vector<u16> ord860({0, 1});
      slog::Relation* readrel861 = db->getRelation("eval_ans");
      eval_ansindex803 = readrel861->getIndex(ord860, false);
      std::vector<u16> ord862({1, 2, 0});
      slog::Relation* readrel863 = db->getRelation("eval");
      evalindex804 = readrel863->getIndex(ord862, false);
      std::vector<u16> ord864({1, 2, 0});
      slog::Relation* readrel865 = db->getRelation("eval");
      evaldelta810 = readrel865->getIndex(ord864, true);
      std::vector<u16> ord866({0, 1});
      slog::Relation* readrel867 = db->getRelation("eval_ans");
      eval_ansindex805 = readrel867->getIndex(ord866, false);
  
    }
    ReadTask811(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c135 = _t[0];
        u64 v_c1 = _t[1];
        u64 v_c3 = _t[2];
        if (!slog::exists_probe<10,3>($sup27994x83x0x0x1index784, std::array<u64,10>{v_c135, v_c3, v_c1, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(evalindex785, std::array<u64,3>{v_c3, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex786, std::array<u64,3>{v_c1, 0, 0})) return;
        if (!slog::exists_probe<2,1>(eval_ansindex787, std::array<u64,2>{v_c135, 0})) return;
        slog::join_probe<4,2>($sup27994x83x0x0x0index788, std::array<u64,4>{v_c3, v_c1, 0, 0}, [&](const std::array<u64,4>& m868) {
          u64 v_c134 = m868[2]; u64 v_c2 = m868[3];
          if (!slog::exists_probe<3,2>(evalindex789, std::array<u64,3>{v_c2, v_c3, 0})) return;
          if (!slog::exists_probe<3,2>(evalindex790, std::array<u64,3>{v_c134, v_c3, 0})) return;
          if (!slog::exists_probe<3,2>(appindex791, std::array<u64,3>{v_c1, v_c2, 0})) return;
          slog::join_probe<10,5>($sup27994x83x0x0x1index792, std::array<u64,10>{v_c2, v_c1, v_c134, v_c3, v_c135, 0, 0, 0, 0, 0}, [&](const std::array<u64,10>& m869) {
            u64 v_c136 = m869[5]; u64 v_c7 = m869[6]; u64 v_c10 = m869[7]; u64 v_c47 = m869[8]; u64 v_c9 = m869[9];
            slog::join_probe_old<3,3>(evalindex793, evaldelta806, std::array<u64,3>{v_c136, v_c3, v_c2}, [&](const std::array<u64,3>& m870) {
              slog::join_probe<2,2>(eval_ansindex794, std::array<u64,2>{v_c136, v_c47}, [&](const std::array<u64,2>& m871) {
                if (!slog::exists_probe<3,2>(lambdaindex795, std::array<u64,3>{v_c9, v_c10, 0})) return;
                if (!slog::exists_probe<3,1>(cloindex796, std::array<u64,3>{v_c7, 0, 0})) return;
                if (!slog::exists_probe<3,1>(evalindex797, std::array<u64,3>{v_c10, 0, 0})) return;
                slog::join_probe<3,2>(evalindex798, std::array<u64,3>{v_c134, v_c3, 0}, [&](const std::array<u64,3>& m872) {
                  u64 v_c137 = m872[2];
                  slog::join_probe_old<3,3>(appindex799, appdelta807, std::array<u64,3>{v_c137, v_c1, v_c2}, [&](const std::array<u64,3>& m873) {
                    if (!slog::exists_probe<3,2>(evalindex800, std::array<u64,3>{v_c10, v_c137, 0})) return;
                    slog::join_probe_old<3,2>(lambdaindex801, lambdadelta808, std::array<u64,3>{v_c9, v_c10, 0}, [&](const std::array<u64,3>& m874) {
                      u64 v_c138 = m874[2];
                      slog::join_probe_old<3,2>(cloindex802, clodelta809, std::array<u64,3>{v_c138, v_c7, 0}, [&](const std::array<u64,3>& m875) {
                        u64 v_c139 = m875[2];
                        slog::join_probe<2,2>(eval_ansindex803, std::array<u64,2>{v_c135, v_c139}, [&](const std::array<u64,2>& m876) {
                          slog::join_probe_old<3,2>(evalindex804, evaldelta810, std::array<u64,3>{v_c10, v_c137, 0}, [&](const std::array<u64,3>& m877) {
                            u64 v_c140 = m877[2];
                            slog::join_probe<2,1>(eval_ansindex805, std::array<u64,2>{v_c140, 0}, [&](const std::array<u64,2>& m878) {
                              u64 v_c141 = m878[1];
                              ++_fires;
                              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c134, v_c141}, std::array<u16,2>{0, 1});
                            });
                          });
                        });
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
  
      if (_fires) db->bumpFires("mcfa-counting.slog:84", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask811* _cont = new ReadTask811(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask811(db,b), false);
  // (crule (pre (let __tconst7sqz226 const7b8fd91ee9ff10cfbb8066bf) (let __tconst1EUj230 const615ad01b1c532bb6634df115) (let __tconst4N2q248 constaaaad65142343c54348db5d0) (let __tconst2VuQ234 const4492fd5fa4baacfebd29f5e5) (let __tconst4Sko246 consteb793a6f75d6cfe49d3c2c90) (let __tconst2x2f244 consta32d5a443def48e6d64c6f4b)) (seeded) (body (join ref (1 0) 1 __tconst7sqz226 __t5APF225) (exists ref (1 0) 1 __tconst1EUj230) (exists lambda (1 2 0) 1 __tconst1EUj230) (exists ref (1 0) 1 __tconst2VuQ234) (exists lambda (1 2 0) 1 __tconst2VuQ234) (exists ref (1 0) 1 __tconst2x2f244) (exists ref (1 0) 1 __tconst4N2q248) (exists ref (1 0) 1 __tconst4Sko246) (exists lambda (1 2 0) 1 __tconst2x2f244) (exists lambda (1 2 0) 1 __tconst4Sko246) (exists lambda (1 2 0) 1 __tconst4N2q248) (join lambda (1 2 0) 2 __tconst7sqz226 __t5APF225 __t2BAX227) (exists app (2 0 1) 1 __t2BAX227) (join ref (1 0) 1 __tconst1EUj230 __t3WVP229) (join lambda (1 2 0) 2 __tconst1EUj230 __t3WVP229 __t5ryk231) (exists app (2 0 1) 1 __t5ryk231) (join ref (1 0) 1 __tconst2VuQ234 __t2PLq233) (join lambda (1 2 0) 2 __tconst2VuQ234 __t2PLq233 __t45rU235) (exists app (2 0 1) 1 __t45rU235) (join ref (1 0) 1 __tconst2x2f244 __t3pbc237) (exists app (2 0 1) 1 __t3pbc237) (join ref (1 0) 1 __tconst4N2q248 __t6KL4241) (exists app (1 2 0) 1 __t6KL4241) (join ref (1 0) 1 __tconst4Sko246 __t16jv239) (join app (1 2 0) 2 __t6KL4241 __t16jv239 __t4wvK242) (join app (1 2 0) 2 __t4wvK242 __t3pbc237 __t5h6K243) (join lambda (1 2 0) 2 __tconst2x2f244 __t5h6K243 __t3laZ245) (join lambda (1 2 0) 2 __tconst4Sko246 __t3laZ245 __t7yz1247) (join lambda (1 2 0) 2 __tconst4N2q248 __t7yz1247 __t5uyC249) (join app (1 2 0) 2 __t5uyC249 __t45rU235 __t5pZU250) (join app (1 2 0) 2 __t5pZU250 __t5ryk231 __t9bBp251) (join app (1 2 0) 2 __t9bBp251 __t2BAX227 __t7iVu252)) (head (emit program (0) __t7iVu252)) mcfa-counting.slog:272 #f)
  class ReadTask911 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex879;  slog::Index** refindex880;  slog::Index** lambdaindex881;  slog::Index** refindex882;  slog::Index** lambdaindex883;  slog::Index** refindex884;  slog::Index** refindex885;  slog::Index** refindex886;  slog::Index** lambdaindex887;  slog::Index** lambdaindex888;  slog::Index** lambdaindex889;  slog::Index** lambdaindex890;  slog::Index** appindex891;  slog::Index** refindex892;  slog::Index** lambdaindex893;  slog::Index** appindex894;  slog::Index** refindex895;  slog::Index** lambdaindex896;  slog::Index** appindex897;  slog::Index** refindex898;  slog::Index** appindex899;  slog::Index** refindex900;  slog::Index** appindex901;  slog::Index** refindex902;  slog::Index** appindex903;  slog::Index** appindex904;  slog::Index** lambdaindex905;  slog::Index** lambdaindex906;  slog::Index** lambdaindex907;  slog::Index** appindex908;  slog::Index** appindex909;  slog::Index** appindex910;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("program");
      std::vector<u16> ord912({0});
      slog::Relation* readrel913 = db->getRelation("program");
      head_index[0] = readrel913->getIndex(ord912, false);
      std::vector<u16> ord914({1, 0});
      slog::Relation* readrel915 = db->getRelation("ref");
      refindex879 = readrel915->getIndex(ord914, false);
      std::vector<u16> ord916({1, 0});
      slog::Relation* readrel917 = db->getRelation("ref");
      refindex880 = readrel917->getIndex(ord916, false);
      std::vector<u16> ord918({1, 2, 0});
      slog::Relation* readrel919 = db->getRelation("lambda");
      lambdaindex881 = readrel919->getIndex(ord918, false);
      std::vector<u16> ord920({1, 0});
      slog::Relation* readrel921 = db->getRelation("ref");
      refindex882 = readrel921->getIndex(ord920, false);
      std::vector<u16> ord922({1, 2, 0});
      slog::Relation* readrel923 = db->getRelation("lambda");
      lambdaindex883 = readrel923->getIndex(ord922, false);
      std::vector<u16> ord924({1, 0});
      slog::Relation* readrel925 = db->getRelation("ref");
      refindex884 = readrel925->getIndex(ord924, false);
      std::vector<u16> ord926({1, 0});
      slog::Relation* readrel927 = db->getRelation("ref");
      refindex885 = readrel927->getIndex(ord926, false);
      std::vector<u16> ord928({1, 0});
      slog::Relation* readrel929 = db->getRelation("ref");
      refindex886 = readrel929->getIndex(ord928, false);
      std::vector<u16> ord930({1, 2, 0});
      slog::Relation* readrel931 = db->getRelation("lambda");
      lambdaindex887 = readrel931->getIndex(ord930, false);
      std::vector<u16> ord932({1, 2, 0});
      slog::Relation* readrel933 = db->getRelation("lambda");
      lambdaindex888 = readrel933->getIndex(ord932, false);
      std::vector<u16> ord934({1, 2, 0});
      slog::Relation* readrel935 = db->getRelation("lambda");
      lambdaindex889 = readrel935->getIndex(ord934, false);
      std::vector<u16> ord936({1, 2, 0});
      slog::Relation* readrel937 = db->getRelation("lambda");
      lambdaindex890 = readrel937->getIndex(ord936, false);
      std::vector<u16> ord938({2, 0, 1});
      slog::Relation* readrel939 = db->getRelation("app");
      appindex891 = readrel939->getIndex(ord938, false);
      std::vector<u16> ord940({1, 0});
      slog::Relation* readrel941 = db->getRelation("ref");
      refindex892 = readrel941->getIndex(ord940, false);
      std::vector<u16> ord942({1, 2, 0});
      slog::Relation* readrel943 = db->getRelation("lambda");
      lambdaindex893 = readrel943->getIndex(ord942, false);
      std::vector<u16> ord944({2, 0, 1});
      slog::Relation* readrel945 = db->getRelation("app");
      appindex894 = readrel945->getIndex(ord944, false);
      std::vector<u16> ord946({1, 0});
      slog::Relation* readrel947 = db->getRelation("ref");
      refindex895 = readrel947->getIndex(ord946, false);
      std::vector<u16> ord948({1, 2, 0});
      slog::Relation* readrel949 = db->getRelation("lambda");
      lambdaindex896 = readrel949->getIndex(ord948, false);
      std::vector<u16> ord950({2, 0, 1});
      slog::Relation* readrel951 = db->getRelation("app");
      appindex897 = readrel951->getIndex(ord950, false);
      std::vector<u16> ord952({1, 0});
      slog::Relation* readrel953 = db->getRelation("ref");
      refindex898 = readrel953->getIndex(ord952, false);
      std::vector<u16> ord954({2, 0, 1});
      slog::Relation* readrel955 = db->getRelation("app");
      appindex899 = readrel955->getIndex(ord954, false);
      std::vector<u16> ord956({1, 0});
      slog::Relation* readrel957 = db->getRelation("ref");
      refindex900 = readrel957->getIndex(ord956, false);
      std::vector<u16> ord958({1, 2, 0});
      slog::Relation* readrel959 = db->getRelation("app");
      appindex901 = readrel959->getIndex(ord958, false);
      std::vector<u16> ord960({1, 0});
      slog::Relation* readrel961 = db->getRelation("ref");
      refindex902 = readrel961->getIndex(ord960, false);
      std::vector<u16> ord962({1, 2, 0});
      slog::Relation* readrel963 = db->getRelation("app");
      appindex903 = readrel963->getIndex(ord962, false);
      std::vector<u16> ord964({1, 2, 0});
      slog::Relation* readrel965 = db->getRelation("app");
      appindex904 = readrel965->getIndex(ord964, false);
      std::vector<u16> ord966({1, 2, 0});
      slog::Relation* readrel967 = db->getRelation("lambda");
      lambdaindex905 = readrel967->getIndex(ord966, false);
      std::vector<u16> ord968({1, 2, 0});
      slog::Relation* readrel969 = db->getRelation("lambda");
      lambdaindex906 = readrel969->getIndex(ord968, false);
      std::vector<u16> ord970({1, 2, 0});
      slog::Relation* readrel971 = db->getRelation("lambda");
      lambdaindex907 = readrel971->getIndex(ord970, false);
      std::vector<u16> ord972({1, 2, 0});
      slog::Relation* readrel973 = db->getRelation("app");
      appindex908 = readrel973->getIndex(ord972, false);
      std::vector<u16> ord974({1, 2, 0});
      slog::Relation* readrel975 = db->getRelation("app");
      appindex909 = readrel975->getIndex(ord974, false);
      std::vector<u16> ord976({1, 2, 0});
      slog::Relation* readrel977 = db->getRelation("app");
      appindex910 = readrel977->getIndex(ord976, false);
  
    }
    ReadTask911(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c27 = v_const7b8fd91ee9ff10cfbb8066bf;
      u64 v_c28 = v_const615ad01b1c532bb6634df115;
      u64 v_c26 = v_constaaaad65142343c54348db5d0;
      u64 v_c29 = v_const4492fd5fa4baacfebd29f5e5;
      u64 v_c25 = v_consteb793a6f75d6cfe49d3c2c90;
      u64 v_c24 = v_consta32d5a443def48e6d64c6f4b;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex879, std::array<u64,2>{v_c27, 0}, [&](const std::array<u64,2>& m978) {
        u64 v_c39 = m978[1];
        if (!slog::exists_probe<2,1>(refindex880, std::array<u64,2>{v_c28, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex881, std::array<u64,3>{v_c28, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex882, std::array<u64,2>{v_c29, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex883, std::array<u64,3>{v_c29, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex884, std::array<u64,2>{v_c24, 0})) return;
        if (!slog::exists_probe<2,1>(refindex885, std::array<u64,2>{v_c26, 0})) return;
        if (!slog::exists_probe<2,1>(refindex886, std::array<u64,2>{v_c25, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex887, std::array<u64,3>{v_c24, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex888, std::array<u64,3>{v_c25, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex889, std::array<u64,3>{v_c26, 0, 0})) return;
        slog::join_probe<3,2>(lambdaindex890, std::array<u64,3>{v_c27, v_c39, 0}, [&](const std::array<u64,3>& m979) {
          u64 v_c40 = m979[2];
          if (!slog::exists_probe<3,1>(appindex891, std::array<u64,3>{v_c40, 0, 0})) return;
          slog::join_probe<2,1>(refindex892, std::array<u64,2>{v_c28, 0}, [&](const std::array<u64,2>& m980) {
            u64 v_c37 = m980[1];
            slog::join_probe<3,2>(lambdaindex893, std::array<u64,3>{v_c28, v_c37, 0}, [&](const std::array<u64,3>& m981) {
              u64 v_c38 = m981[2];
              if (!slog::exists_probe<3,1>(appindex894, std::array<u64,3>{v_c38, 0, 0})) return;
              slog::join_probe<2,1>(refindex895, std::array<u64,2>{v_c29, 0}, [&](const std::array<u64,2>& m982) {
                u64 v_c35 = m982[1];
                slog::join_probe<3,2>(lambdaindex896, std::array<u64,3>{v_c29, v_c35, 0}, [&](const std::array<u64,3>& m983) {
                  u64 v_c36 = m983[2];
                  if (!slog::exists_probe<3,1>(appindex897, std::array<u64,3>{v_c36, 0, 0})) return;
                  slog::join_probe<2,1>(refindex898, std::array<u64,2>{v_c24, 0}, [&](const std::array<u64,2>& m984) {
                    u64 v_c32 = m984[1];
                    if (!slog::exists_probe<3,1>(appindex899, std::array<u64,3>{v_c32, 0, 0})) return;
                    slog::join_probe<2,1>(refindex900, std::array<u64,2>{v_c26, 0}, [&](const std::array<u64,2>& m985) {
                      u64 v_c33 = m985[1];
                      if (!slog::exists_probe<3,1>(appindex901, std::array<u64,3>{v_c33, 0, 0})) return;
                      slog::join_probe<2,1>(refindex902, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m986) {
                        u64 v_c34 = m986[1];
                        slog::join_probe<3,2>(appindex903, std::array<u64,3>{v_c33, v_c34, 0}, [&](const std::array<u64,3>& m987) {
                          u64 v_c31 = m987[2];
                          slog::join_probe<3,2>(appindex904, std::array<u64,3>{v_c31, v_c32, 0}, [&](const std::array<u64,3>& m988) {
                            u64 v_c30 = m988[2];
                            slog::join_probe<3,2>(lambdaindex905, std::array<u64,3>{v_c24, v_c30, 0}, [&](const std::array<u64,3>& m989) {
                              u64 v_c148 = m989[2];
                              slog::join_probe<3,2>(lambdaindex906, std::array<u64,3>{v_c25, v_c148, 0}, [&](const std::array<u64,3>& m990) {
                                u64 v_c149 = m990[2];
                                slog::join_probe<3,2>(lambdaindex907, std::array<u64,3>{v_c26, v_c149, 0}, [&](const std::array<u64,3>& m991) {
                                  u64 v_c150 = m991[2];
                                  slog::join_probe<3,2>(appindex908, std::array<u64,3>{v_c150, v_c36, 0}, [&](const std::array<u64,3>& m992) {
                                    u64 v_c151 = m992[2];
                                    slog::join_probe<3,2>(appindex909, std::array<u64,3>{v_c151, v_c38, 0}, [&](const std::array<u64,3>& m993) {
                                      u64 v_c152 = m993[2];
                                      slog::join_probe<3,2>(appindex910, std::array<u64,3>{v_c152, v_c40, 0}, [&](const std::array<u64,3>& m994) {
                                        u64 v_c153 = m994[2];
                                        ++_fires;
                                        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c153}, std::array<u16,1>{0});
                                      });
                                    });
                                  });
                                });
                              });
                            });
                          });
                        });
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
      s->addTaskSeeded(phase_read, new ReadTask911(db,b));
  // (crule (pre (let __tconst0y6X73 const0aa6f87434af0222b916e97a) (let __tconst7zoP70 const227d34ceeba7a29aada993d4) (let __tconst1bfe65 const59ba3256d223f0d0a00d0633) (let __tconst8wN863 const7cd75b35aa30c3ddf04f9d57) (let __tconst0aL952 constd3d07026d47882ceca728218) (let __tconst0xUh47 constf700a82e218a86de572e1f7f)) (probe lambda (1 2 0) 1 __tconst0xUh47 __t5vZb46 __t50zW48) (body (join ref (0 1) 2 __t5vZb46 __tconst0xUh47) (exists ref (1 0) 1 __tconst1bfe65) (exists lambda (1 2 0) 1 __tconst1bfe65) (exists ref (1 0) 1 __tconst0y6X73) (exists ref (1 0) 1 __tconst8wN863) (exists lambda (1 2 0) 1 __tconst8wN863) (join ref (1 0) 1 __tconst0aL952 __t5HQ450) (join ref (1 0) 1 __tconst1bfe65 __t2HsD55) (join lambda (1 2 0) 2 __tconst1bfe65 __t2HsD55 __t0uNb57) (join ref (1 0) 1 __tconst0y6X73 __t0QRr59) (join ref (1 0) 1 __tconst8wN863 __t1mkO62) (join lambda (1 2 0) 2 __tconst8wN863 __t1mkO62 __t3Dru64)) (head (mkstruct lambda (1 2 0) __t7JIT66 __tconst1bfe65 __t3Dru64) (mkstruct app (1 2 0) __t81HE60 __t0QRr59 __t0uNb57) (mkstruct app (1 2 0) __t05NY51 __t5HQ450 __t50zW48)) mcfa-counting.slog:287 #f)
  class ReadTask1007 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** refindex995;  slog::Index** refindex996;  slog::Index** lambdaindex997;  slog::Index** refindex998;  slog::Index** refindex999;  slog::Index** lambdaindex1000;  slog::Index** refindex1001;  slog::Index** refindex1002;  slog::Index** lambdaindex1003;  slog::Index** refindex1004;  slog::Index** refindex1005;  slog::Index** lambdaindex1006;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      head_rel[1] = db->getRelation("app");
      head_rel[2] = db->getRelation("app");
      std::vector<u16> ord1008({1, 2, 0});
      slog::Relation* readrel1009 = db->getRelation("lambda");
      driver_index = readrel1009->getIndex(ord1008, true);
      std::vector<u16> ord1010({0, 1});
      slog::Relation* readrel1011 = db->getRelation("ref");
      refindex995 = readrel1011->getIndex(ord1010, false);
      std::vector<u16> ord1012({1, 0});
      slog::Relation* readrel1013 = db->getRelation("ref");
      refindex996 = readrel1013->getIndex(ord1012, false);
      std::vector<u16> ord1014({1, 2, 0});
      slog::Relation* readrel1015 = db->getRelation("lambda");
      lambdaindex997 = readrel1015->getIndex(ord1014, false);
      std::vector<u16> ord1016({1, 0});
      slog::Relation* readrel1017 = db->getRelation("ref");
      refindex998 = readrel1017->getIndex(ord1016, false);
      std::vector<u16> ord1018({1, 0});
      slog::Relation* readrel1019 = db->getRelation("ref");
      refindex999 = readrel1019->getIndex(ord1018, false);
      std::vector<u16> ord1020({1, 2, 0});
      slog::Relation* readrel1021 = db->getRelation("lambda");
      lambdaindex1000 = readrel1021->getIndex(ord1020, false);
      std::vector<u16> ord1022({1, 0});
      slog::Relation* readrel1023 = db->getRelation("ref");
      refindex1001 = readrel1023->getIndex(ord1022, false);
      std::vector<u16> ord1024({1, 0});
      slog::Relation* readrel1025 = db->getRelation("ref");
      refindex1002 = readrel1025->getIndex(ord1024, false);
      std::vector<u16> ord1026({1, 2, 0});
      slog::Relation* readrel1027 = db->getRelation("lambda");
      lambdaindex1003 = readrel1027->getIndex(ord1026, false);
      std::vector<u16> ord1028({1, 0});
      slog::Relation* readrel1029 = db->getRelation("ref");
      refindex1004 = readrel1029->getIndex(ord1028, false);
      std::vector<u16> ord1030({1, 0});
      slog::Relation* readrel1031 = db->getRelation("ref");
      refindex1005 = readrel1031->getIndex(ord1030, false);
      std::vector<u16> ord1032({1, 2, 0});
      slog::Relation* readrel1033 = db->getRelation("lambda");
      lambdaindex1006 = readrel1033->getIndex(ord1032, false);
  
    }
    ReadTask1007(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c154 = v_const0aa6f87434af0222b916e97a;
      u64 v_c155 = v_const227d34ceeba7a29aada993d4;
      u64 v_c156 = v_const59ba3256d223f0d0a00d0633;
      u64 v_c157 = v_const7cd75b35aa30c3ddf04f9d57;
      u64 v_c158 = v_constd3d07026d47882ceca728218;
      u64 v_c159 = v_constf700a82e218a86de572e1f7f;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c159, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1034) {
        u64 v_c160 = m1034[1];
        u64 v_c161 = m1034[2];
        if (buckethash(v_c160) != bucket) return;
        slog::join_probe<2,2>(refindex995, std::array<u64,2>{v_c160, v_c159}, [&](const std::array<u64,2>& m1035) {
          if (!slog::exists_probe<2,1>(refindex996, std::array<u64,2>{v_c156, 0})) return;
          if (!slog::exists_probe<3,1>(lambdaindex997, std::array<u64,3>{v_c156, 0, 0})) return;
          if (!slog::exists_probe<2,1>(refindex998, std::array<u64,2>{v_c154, 0})) return;
          if (!slog::exists_probe<2,1>(refindex999, std::array<u64,2>{v_c157, 0})) return;
          if (!slog::exists_probe<3,1>(lambdaindex1000, std::array<u64,3>{v_c157, 0, 0})) return;
          slog::join_probe<2,1>(refindex1001, std::array<u64,2>{v_c158, 0}, [&](const std::array<u64,2>& m1036) {
            u64 v_c162 = m1036[1];
            slog::join_probe<2,1>(refindex1002, std::array<u64,2>{v_c156, 0}, [&](const std::array<u64,2>& m1037) {
              u64 v_c163 = m1037[1];
              slog::join_probe<3,2>(lambdaindex1003, std::array<u64,3>{v_c156, v_c163, 0}, [&](const std::array<u64,3>& m1038) {
                u64 v_c164 = m1038[2];
                slog::join_probe<2,1>(refindex1004, std::array<u64,2>{v_c154, 0}, [&](const std::array<u64,2>& m1039) {
                  u64 v_c165 = m1039[1];
                  slog::join_probe<2,1>(refindex1005, std::array<u64,2>{v_c157, 0}, [&](const std::array<u64,2>& m1040) {
                    u64 v_c166 = m1040[1];
                    slog::join_probe<3,2>(lambdaindex1006, std::array<u64,3>{v_c157, v_c166, 0}, [&](const std::array<u64,3>& m1041) {
                      u64 v_c167 = m1041[2];
                      ++_fires;
                      slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c156, v_c167}, std::array<u16,3>{1, 2, 0});
                      slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c165, v_c164}, std::array<u16,3>{1, 2, 0});
                      slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c162, v_c161}, std::array<u16,3>{1, 2, 0});
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
  
      if (_fires) db->bumpFires("mcfa-counting.slog:287", "delta:lambda", _fires);
  
      if (!_done)
      {
        ReadTask1007* _cont = new ReadTask1007(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1007(db,b), false);
  // (crule (pre) (scan temp0sJH415 __t3GAu9 __t3mrW8 c) (body (join clo (1 2 0) 2 __t3mrW8 c __t4Sp77)) (head (emit eval_ans (0 1) __t3GAu9 __t4Sp77)) mcfa-counting.slog:78 #f)
  class ReadTask1043 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** cloindex1042;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1044({0, 1});
      slog::Relation* readrel1045 = db->getRelation("eval_ans");
      head_index[0] = readrel1045->getIndex(ord1044, false);
      outer_rel = db->getRelation("temp0sJH415");
      std::vector<u16> ord1046({1, 2, 0});
      slog::Relation* readrel1047 = db->getRelation("clo");
      cloindex1042 = readrel1047->getIndex(ord1046, false);
  
    }
    ReadTask1043(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c168 = _t[0];
        u64 v_c169 = _t[1];
        u64 v_c3 = _t[2];
        slog::join_probe<3,2>(cloindex1042, std::array<u64,3>{v_c169, v_c3, 0}, [&](const std::array<u64,3>& m1048) {
          u64 v_c170 = m1048[2];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c168, v_c170}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:78", "delta:temp0sJH415", _fires);
  
      if (!_done)
      {
        ReadTask1043* _cont = new ReadTask1043(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1043(db,b), false);
  // (crule (pre (let __tconst1pJW313 constb49bea2fcccd8f4301a347ed) (let __tconst7LWP310 const66518c0c1b3a5a0b09ae2ef1) (let __tconst5PoN291 constc85eae03730a4f4cf1d66a0c) (let __tconst2Yzp284 const8ca682693a0738a0641c6956) (let __tconst0sqO307 const4a8acfc71441e0695ffcf5b3) (let __tconst9rZO295 const576506f61f53440f1edd95d2) (let __tconst2CSv302 const229c0b7aa8a7eb4055f5a3d0)) (seeded) (body (join ref (1 0) 1 __tconst2Yzp284 __t248W283) (exists ref (1 0) 1 __tconst7LWP310) (exists ref (1 0) 1 __tconst1pJW313) (exists ref (1 0) 1 __tconst9rZO295) (exists lambda (1 2 0) 1 __tconst9rZO295) (exists ref (1 0) 1 __tconst2CSv302) (exists lambda (1 2 0) 1 __tconst2CSv302) (exists lambda (1 2 0) 1 __tconst0sqO307) (exists lambda (1 2 0) 1 __tconst7LWP310) (exists lambda (1 2 0) 1 __tconst5PoN291) (join lambda (1 2 0) 2 __tconst2Yzp284 __t248W283 __t0oFu285) (join ref (1 0) 1 __tconst7LWP310 __t91H2298) (exists app (1 2 0) 1 __t91H2298) (join ref (1 0) 1 __tconst1pJW313 __t165O287) (exists app (1 2 0) 1 __t165O287) (join ref (1 0) 1 __tconst9rZO295 __t71w7294) (join lambda (1 2 0) 2 __tconst9rZO295 __t71w7294 __t3dkk296) (join app (1 2 0) 2 __t91H2298 __t3dkk296 __t4LtH299) (exists app (2 0 1) 1 __t4LtH299) (join ref (1 0) 1 __tconst2CSv302 __t6lXa301) (join lambda (1 2 0) 2 __tconst2CSv302 __t6lXa301 __t7EW2303) (join app (1 2 0) 2 __t91H2298 __t7EW2303 __t4HUX306) (join lambda (1 2 0) 2 __tconst0sqO307 __t4HUX306 __t0vn1308) (join app (1 2 0) 2 __t0vn1308 __t4LtH299 __t6t9L309) (join lambda (1 2 0) 2 __tconst7LWP310 __t6t9L309 __t5T0g311) (join app (1 2 0) 1 __t165O287 dup1Usx384 __t30Ec290) (eq __t165O287 dup1Usx384) (join lambda (1 2 0) 2 __tconst5PoN291 __t30Ec290 __t7aCZ292)) (head (mkstruct app (1 2 0) __t3Izn312 __t5T0g311 __t7aCZ292)) mcfa-counting.slog:194 #f)
  class ReadTask1076 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex1049;  slog::Index** refindex1050;  slog::Index** refindex1051;  slog::Index** refindex1052;  slog::Index** lambdaindex1053;  slog::Index** refindex1054;  slog::Index** lambdaindex1055;  slog::Index** lambdaindex1056;  slog::Index** lambdaindex1057;  slog::Index** lambdaindex1058;  slog::Index** lambdaindex1059;  slog::Index** refindex1060;  slog::Index** appindex1061;  slog::Index** refindex1062;  slog::Index** appindex1063;  slog::Index** refindex1064;  slog::Index** lambdaindex1065;  slog::Index** appindex1066;  slog::Index** appindex1067;  slog::Index** refindex1068;  slog::Index** lambdaindex1069;  slog::Index** appindex1070;  slog::Index** lambdaindex1071;  slog::Index** appindex1072;  slog::Index** lambdaindex1073;  slog::Index** appindex1074;  slog::Index** lambdaindex1075;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord1077({1, 2, 0});
      slog::Relation* readrel1078 = db->getRelation("app");
      head_index[0] = readrel1078->getIndex(ord1077, false);
      std::vector<u16> ord1079({1, 0});
      slog::Relation* readrel1080 = db->getRelation("ref");
      refindex1049 = readrel1080->getIndex(ord1079, false);
      std::vector<u16> ord1081({1, 0});
      slog::Relation* readrel1082 = db->getRelation("ref");
      refindex1050 = readrel1082->getIndex(ord1081, false);
      std::vector<u16> ord1083({1, 0});
      slog::Relation* readrel1084 = db->getRelation("ref");
      refindex1051 = readrel1084->getIndex(ord1083, false);
      std::vector<u16> ord1085({1, 0});
      slog::Relation* readrel1086 = db->getRelation("ref");
      refindex1052 = readrel1086->getIndex(ord1085, false);
      std::vector<u16> ord1087({1, 2, 0});
      slog::Relation* readrel1088 = db->getRelation("lambda");
      lambdaindex1053 = readrel1088->getIndex(ord1087, false);
      std::vector<u16> ord1089({1, 0});
      slog::Relation* readrel1090 = db->getRelation("ref");
      refindex1054 = readrel1090->getIndex(ord1089, false);
      std::vector<u16> ord1091({1, 2, 0});
      slog::Relation* readrel1092 = db->getRelation("lambda");
      lambdaindex1055 = readrel1092->getIndex(ord1091, false);
      std::vector<u16> ord1093({1, 2, 0});
      slog::Relation* readrel1094 = db->getRelation("lambda");
      lambdaindex1056 = readrel1094->getIndex(ord1093, false);
      std::vector<u16> ord1095({1, 2, 0});
      slog::Relation* readrel1096 = db->getRelation("lambda");
      lambdaindex1057 = readrel1096->getIndex(ord1095, false);
      std::vector<u16> ord1097({1, 2, 0});
      slog::Relation* readrel1098 = db->getRelation("lambda");
      lambdaindex1058 = readrel1098->getIndex(ord1097, false);
      std::vector<u16> ord1099({1, 2, 0});
      slog::Relation* readrel1100 = db->getRelation("lambda");
      lambdaindex1059 = readrel1100->getIndex(ord1099, false);
      std::vector<u16> ord1101({1, 0});
      slog::Relation* readrel1102 = db->getRelation("ref");
      refindex1060 = readrel1102->getIndex(ord1101, false);
      std::vector<u16> ord1103({1, 2, 0});
      slog::Relation* readrel1104 = db->getRelation("app");
      appindex1061 = readrel1104->getIndex(ord1103, false);
      std::vector<u16> ord1105({1, 0});
      slog::Relation* readrel1106 = db->getRelation("ref");
      refindex1062 = readrel1106->getIndex(ord1105, false);
      std::vector<u16> ord1107({1, 2, 0});
      slog::Relation* readrel1108 = db->getRelation("app");
      appindex1063 = readrel1108->getIndex(ord1107, false);
      std::vector<u16> ord1109({1, 0});
      slog::Relation* readrel1110 = db->getRelation("ref");
      refindex1064 = readrel1110->getIndex(ord1109, false);
      std::vector<u16> ord1111({1, 2, 0});
      slog::Relation* readrel1112 = db->getRelation("lambda");
      lambdaindex1065 = readrel1112->getIndex(ord1111, false);
      std::vector<u16> ord1113({1, 2, 0});
      slog::Relation* readrel1114 = db->getRelation("app");
      appindex1066 = readrel1114->getIndex(ord1113, false);
      std::vector<u16> ord1115({2, 0, 1});
      slog::Relation* readrel1116 = db->getRelation("app");
      appindex1067 = readrel1116->getIndex(ord1115, false);
      std::vector<u16> ord1117({1, 0});
      slog::Relation* readrel1118 = db->getRelation("ref");
      refindex1068 = readrel1118->getIndex(ord1117, false);
      std::vector<u16> ord1119({1, 2, 0});
      slog::Relation* readrel1120 = db->getRelation("lambda");
      lambdaindex1069 = readrel1120->getIndex(ord1119, false);
      std::vector<u16> ord1121({1, 2, 0});
      slog::Relation* readrel1122 = db->getRelation("app");
      appindex1070 = readrel1122->getIndex(ord1121, false);
      std::vector<u16> ord1123({1, 2, 0});
      slog::Relation* readrel1124 = db->getRelation("lambda");
      lambdaindex1071 = readrel1124->getIndex(ord1123, false);
      std::vector<u16> ord1125({1, 2, 0});
      slog::Relation* readrel1126 = db->getRelation("app");
      appindex1072 = readrel1126->getIndex(ord1125, false);
      std::vector<u16> ord1127({1, 2, 0});
      slog::Relation* readrel1128 = db->getRelation("lambda");
      lambdaindex1073 = readrel1128->getIndex(ord1127, false);
      std::vector<u16> ord1129({1, 2, 0});
      slog::Relation* readrel1130 = db->getRelation("app");
      appindex1074 = readrel1130->getIndex(ord1129, false);
      std::vector<u16> ord1131({1, 2, 0});
      slog::Relation* readrel1132 = db->getRelation("lambda");
      lambdaindex1075 = readrel1132->getIndex(ord1131, false);
  
    }
    ReadTask1076(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c110 = v_constb49bea2fcccd8f4301a347ed;
      u64 v_c111 = v_const66518c0c1b3a5a0b09ae2ef1;
      u64 v_c112 = v_constc85eae03730a4f4cf1d66a0c;
      u64 v_c113 = v_const8ca682693a0738a0641c6956;
      u64 v_c114 = v_const4a8acfc71441e0695ffcf5b3;
      u64 v_c115 = v_const576506f61f53440f1edd95d2;
      u64 v_c116 = v_const229c0b7aa8a7eb4055f5a3d0;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex1049, std::array<u64,2>{v_c113, 0}, [&](const std::array<u64,2>& m1133) {
        u64 v_c117 = m1133[1];
        if (!slog::exists_probe<2,1>(refindex1050, std::array<u64,2>{v_c111, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1051, std::array<u64,2>{v_c110, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1052, std::array<u64,2>{v_c115, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1053, std::array<u64,3>{v_c115, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1054, std::array<u64,2>{v_c116, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1055, std::array<u64,3>{v_c116, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1056, std::array<u64,3>{v_c114, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1057, std::array<u64,3>{v_c111, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1058, std::array<u64,3>{v_c112, 0, 0})) return;
        slog::join_probe<3,2>(lambdaindex1059, std::array<u64,3>{v_c113, v_c117, 0}, [&](const std::array<u64,3>& m1134) {
          u64 v_c118 = m1134[2];
          slog::join_probe<2,1>(refindex1060, std::array<u64,2>{v_c111, 0}, [&](const std::array<u64,2>& m1135) {
            u64 v_c120 = m1135[1];
            if (!slog::exists_probe<3,1>(appindex1061, std::array<u64,3>{v_c120, 0, 0})) return;
            slog::join_probe<2,1>(refindex1062, std::array<u64,2>{v_c110, 0}, [&](const std::array<u64,2>& m1136) {
              u64 v_c119 = m1136[1];
              if (!slog::exists_probe<3,1>(appindex1063, std::array<u64,3>{v_c119, 0, 0})) return;
              slog::join_probe<2,1>(refindex1064, std::array<u64,2>{v_c115, 0}, [&](const std::array<u64,2>& m1137) {
                u64 v_c121 = m1137[1];
                slog::join_probe<3,2>(lambdaindex1065, std::array<u64,3>{v_c115, v_c121, 0}, [&](const std::array<u64,3>& m1138) {
                  u64 v_c122 = m1138[2];
                  slog::join_probe<3,2>(appindex1066, std::array<u64,3>{v_c120, v_c122, 0}, [&](const std::array<u64,3>& m1139) {
                    u64 v_c123 = m1139[2];
                    if (!slog::exists_probe<3,1>(appindex1067, std::array<u64,3>{v_c123, 0, 0})) return;
                    slog::join_probe<2,1>(refindex1068, std::array<u64,2>{v_c116, 0}, [&](const std::array<u64,2>& m1140) {
                      u64 v_c124 = m1140[1];
                      slog::join_probe<3,2>(lambdaindex1069, std::array<u64,3>{v_c116, v_c124, 0}, [&](const std::array<u64,3>& m1141) {
                        u64 v_c125 = m1141[2];
                        slog::join_probe<3,2>(appindex1070, std::array<u64,3>{v_c120, v_c125, 0}, [&](const std::array<u64,3>& m1142) {
                          u64 v_c126 = m1142[2];
                          slog::join_probe<3,2>(lambdaindex1071, std::array<u64,3>{v_c114, v_c126, 0}, [&](const std::array<u64,3>& m1143) {
                            u64 v_c127 = m1143[2];
                            slog::join_probe<3,2>(appindex1072, std::array<u64,3>{v_c127, v_c123, 0}, [&](const std::array<u64,3>& m1144) {
                              u64 v_c128 = m1144[2];
                              slog::join_probe<3,2>(lambdaindex1073, std::array<u64,3>{v_c111, v_c128, 0}, [&](const std::array<u64,3>& m1145) {
                                u64 v_c129 = m1145[2];
                                slog::join_probe<3,1>(appindex1074, std::array<u64,3>{v_c119, 0, 0}, [&](const std::array<u64,3>& m1146) {
                                  u64 v_c171 = m1146[1]; u64 v_c131 = m1146[2];
                                  if (v_c119 != v_c171) return;
                                  slog::join_probe<3,2>(lambdaindex1075, std::array<u64,3>{v_c112, v_c131, 0}, [&](const std::array<u64,3>& m1147) {
                                    u64 v_c132 = m1147[2];
                                    ++_fires;
                                    slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c129, v_c132}, std::array<u16,3>{1, 2, 0});
                                  });
                                });
                              });
                            });
                          });
                        });
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
      s->addTaskSeeded(phase_read, new ReadTask1076(db,b));
  // (crule (pre (let __tconst7sqz226 const7b8fd91ee9ff10cfbb8066bf) (let __tconst1EUj230 const615ad01b1c532bb6634df115) (let __tconst2VuQ234 const4492fd5fa4baacfebd29f5e5) (let __tconst2x2f244 consta32d5a443def48e6d64c6f4b) (let __tconst4Sko246 consteb793a6f75d6cfe49d3c2c90) (let __tconst4N2q248 constaaaad65142343c54348db5d0)) (scan app __t4wvK242 __t6KL4241 __t16jv239) (body (join ref (0 1) 2 __t6KL4241 __tconst4N2q248) (join ref (0 1) 2 __t16jv239 __tconst4Sko246) (exists ref (1 0) 1 __tconst2VuQ234) (exists lambda (1 2 0) 1 __tconst2VuQ234) (exists ref (1 0) 1 __tconst1EUj230) (exists lambda (1 2 0) 1 __tconst1EUj230) (exists ref (1 0) 1 __tconst7sqz226) (exists lambda (1 2 0) 1 __tconst7sqz226) (join ref (1 0) 1 __tconst2x2f244 __t3pbc237) (join ref (1 0) 1 __tconst2VuQ234 __t2PLq233) (join lambda (1 2 0) 2 __tconst2VuQ234 __t2PLq233 __t45rU235) (join ref (1 0) 1 __tconst1EUj230 __t3WVP229) (join lambda (1 2 0) 2 __tconst1EUj230 __t3WVP229 __t5ryk231) (join ref (1 0) 1 __tconst7sqz226 __t5APF225) (join lambda (1 2 0) 2 __tconst7sqz226 __t5APF225 __t2BAX227)) (head (mkstruct app (1 2 0) __t5h6K243 __t4wvK242 __t3pbc237)) mcfa-counting.slog:272 #f)
  class ReadTask1163 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex1148;  slog::Index** refindex1149;  slog::Index** refindex1150;  slog::Index** lambdaindex1151;  slog::Index** refindex1152;  slog::Index** lambdaindex1153;  slog::Index** refindex1154;  slog::Index** lambdaindex1155;  slog::Index** refindex1156;  slog::Index** refindex1157;  slog::Index** lambdaindex1158;  slog::Index** refindex1159;  slog::Index** lambdaindex1160;  slog::Index** refindex1161;  slog::Index** lambdaindex1162;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      outer_rel = db->getRelation("app");
      std::vector<u16> ord1164({0, 1});
      slog::Relation* readrel1165 = db->getRelation("ref");
      refindex1148 = readrel1165->getIndex(ord1164, false);
      std::vector<u16> ord1166({0, 1});
      slog::Relation* readrel1167 = db->getRelation("ref");
      refindex1149 = readrel1167->getIndex(ord1166, false);
      std::vector<u16> ord1168({1, 0});
      slog::Relation* readrel1169 = db->getRelation("ref");
      refindex1150 = readrel1169->getIndex(ord1168, false);
      std::vector<u16> ord1170({1, 2, 0});
      slog::Relation* readrel1171 = db->getRelation("lambda");
      lambdaindex1151 = readrel1171->getIndex(ord1170, false);
      std::vector<u16> ord1172({1, 0});
      slog::Relation* readrel1173 = db->getRelation("ref");
      refindex1152 = readrel1173->getIndex(ord1172, false);
      std::vector<u16> ord1174({1, 2, 0});
      slog::Relation* readrel1175 = db->getRelation("lambda");
      lambdaindex1153 = readrel1175->getIndex(ord1174, false);
      std::vector<u16> ord1176({1, 0});
      slog::Relation* readrel1177 = db->getRelation("ref");
      refindex1154 = readrel1177->getIndex(ord1176, false);
      std::vector<u16> ord1178({1, 2, 0});
      slog::Relation* readrel1179 = db->getRelation("lambda");
      lambdaindex1155 = readrel1179->getIndex(ord1178, false);
      std::vector<u16> ord1180({1, 0});
      slog::Relation* readrel1181 = db->getRelation("ref");
      refindex1156 = readrel1181->getIndex(ord1180, false);
      std::vector<u16> ord1182({1, 0});
      slog::Relation* readrel1183 = db->getRelation("ref");
      refindex1157 = readrel1183->getIndex(ord1182, false);
      std::vector<u16> ord1184({1, 2, 0});
      slog::Relation* readrel1185 = db->getRelation("lambda");
      lambdaindex1158 = readrel1185->getIndex(ord1184, false);
      std::vector<u16> ord1186({1, 0});
      slog::Relation* readrel1187 = db->getRelation("ref");
      refindex1159 = readrel1187->getIndex(ord1186, false);
      std::vector<u16> ord1188({1, 2, 0});
      slog::Relation* readrel1189 = db->getRelation("lambda");
      lambdaindex1160 = readrel1189->getIndex(ord1188, false);
      std::vector<u16> ord1190({1, 0});
      slog::Relation* readrel1191 = db->getRelation("ref");
      refindex1161 = readrel1191->getIndex(ord1190, false);
      std::vector<u16> ord1192({1, 2, 0});
      slog::Relation* readrel1193 = db->getRelation("lambda");
      lambdaindex1162 = readrel1193->getIndex(ord1192, false);
  
    }
    ReadTask1163(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c27 = v_const7b8fd91ee9ff10cfbb8066bf;
      u64 v_c28 = v_const615ad01b1c532bb6634df115;
      u64 v_c29 = v_const4492fd5fa4baacfebd29f5e5;
      u64 v_c24 = v_consta32d5a443def48e6d64c6f4b;
      u64 v_c25 = v_consteb793a6f75d6cfe49d3c2c90;
      u64 v_c26 = v_constaaaad65142343c54348db5d0;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c31 = _t[0];
        u64 v_c33 = _t[1];
        u64 v_c34 = _t[2];
        slog::join_probe<2,2>(refindex1148, std::array<u64,2>{v_c33, v_c26}, [&](const std::array<u64,2>& m1194) {
          slog::join_probe<2,2>(refindex1149, std::array<u64,2>{v_c34, v_c25}, [&](const std::array<u64,2>& m1195) {
            if (!slog::exists_probe<2,1>(refindex1150, std::array<u64,2>{v_c29, 0})) return;
            if (!slog::exists_probe<3,1>(lambdaindex1151, std::array<u64,3>{v_c29, 0, 0})) return;
            if (!slog::exists_probe<2,1>(refindex1152, std::array<u64,2>{v_c28, 0})) return;
            if (!slog::exists_probe<3,1>(lambdaindex1153, std::array<u64,3>{v_c28, 0, 0})) return;
            if (!slog::exists_probe<2,1>(refindex1154, std::array<u64,2>{v_c27, 0})) return;
            if (!slog::exists_probe<3,1>(lambdaindex1155, std::array<u64,3>{v_c27, 0, 0})) return;
            slog::join_probe<2,1>(refindex1156, std::array<u64,2>{v_c24, 0}, [&](const std::array<u64,2>& m1196) {
              u64 v_c32 = m1196[1];
              slog::join_probe<2,1>(refindex1157, std::array<u64,2>{v_c29, 0}, [&](const std::array<u64,2>& m1197) {
                u64 v_c35 = m1197[1];
                slog::join_probe<3,2>(lambdaindex1158, std::array<u64,3>{v_c29, v_c35, 0}, [&](const std::array<u64,3>& m1198) {
                  u64 v_c36 = m1198[2];
                  slog::join_probe<2,1>(refindex1159, std::array<u64,2>{v_c28, 0}, [&](const std::array<u64,2>& m1199) {
                    u64 v_c37 = m1199[1];
                    slog::join_probe<3,2>(lambdaindex1160, std::array<u64,3>{v_c28, v_c37, 0}, [&](const std::array<u64,3>& m1200) {
                      u64 v_c38 = m1200[2];
                      slog::join_probe<2,1>(refindex1161, std::array<u64,2>{v_c27, 0}, [&](const std::array<u64,2>& m1201) {
                        u64 v_c39 = m1201[1];
                        slog::join_probe<3,2>(lambdaindex1162, std::array<u64,3>{v_c27, v_c39, 0}, [&](const std::array<u64,3>& m1202) {
                          u64 v_c40 = m1202[2];
                          ++_fires;
                          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c31, v_c32}, std::array<u16,3>{1, 2, 0});
                        });
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
        ReadTask1163* _cont = new ReadTask1163(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1163(db,b), false);
}

