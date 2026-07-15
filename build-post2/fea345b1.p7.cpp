
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const0aa6f87434af0222b916e97a;
extern u64 v_const0f8748be649f8ee4066bb1d7;
extern u64 v_const15bb62b8293a526ca6f0e4eb;
extern u64 v_const227d34ceeba7a29aada993d4;
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
extern u64 v_const5950e3cb761734f52a881545;
extern u64 v_const59ba3256d223f0d0a00d0633;
extern u64 v_const615ad01b1c532bb6634df115;
extern u64 v_const66518c0c1b3a5a0b09ae2ef1;
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
extern u64 v_conste58dec6bca6f63ef79c3b755;
extern u64 v_consteb793a6f75d6cfe49d3c2c90;
extern u64 v_constf0a25c0401304c51b5ee9c5e;
extern u64 v_constf700a82e218a86de572e1f7f;
extern u64 v_constfc9ee54e0ee8c6d1e715716c;


void slog_rules_cc18c33fc14fb8b55(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre (let __tconst4Xaz41 const81cb39a72a584ab4f703b7f7) (let __tconst1aIN38 const4d5ce1398140fbe27561181f) (let __tconst1ha033 const969c6e56242ce8d0a4346602) (let __tconst37GM26 const85f09fa1913b9daf65957cf7) (let __tconst4xzG22 constdbf1bdba02122b2adce28528) (let __tconst1HMF17 constd7a1925d249b4768c8a9f2d8)) (once) (body) (head (mkstruct ref (1 0) __t7N9A32 __tconst1ha033) (mkstruct ref (1 0) __t75SZ29 __tconst4Xaz41) (mkstruct ref (1 0) __t7U1m25 __tconst37GM26) (mkstruct ref (1 0) __t2DOE20 __tconst4xzG22) (mkstruct ref (1 0) __t7H1u16 __tconst1HMF17)) mcfa-counting.slog:260 #f)
  class ReadTask0 : public slog::Task
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
    ReadTask0(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const81cb39a72a584ab4f703b7f7;
      u64 v_c1 = v_const4d5ce1398140fbe27561181f;
      u64 v_c2 = v_const969c6e56242ce8d0a4346602;
      u64 v_c3 = v_const85f09fa1913b9daf65957cf7;
      u64 v_c4 = v_constdbf1bdba02122b2adce28528;
      u64 v_c5 = v_constd7a1925d249b4768c8a9f2d8;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[5];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
      newbatch[4] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c2}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c0}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[2], newbatch[2], std::array<u64,1>{v_c3}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[3], newbatch[3], std::array<u64,1>{v_c4}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[4], newbatch[4], std::array<u64,1>{v_c5}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:260", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask0(db,b), true);
  // (crule (pre (let __tconst7sqz226 const7b8fd91ee9ff10cfbb8066bf) (let __tconst1EUj230 const615ad01b1c532bb6634df115) (let __tconst2VuQ234 const4492fd5fa4baacfebd29f5e5) (let __tconst2x2f244 consta32d5a443def48e6d64c6f4b) (let __tconst4Sko246 consteb793a6f75d6cfe49d3c2c90) (let __tconst4N2q248 constaaaad65142343c54348db5d0)) (probe ref (1 0) 1 __tconst4N2q248 __t6KL4241) (body (exists ref (1 0) 1 __tconst2x2f244) (exists ref (1 0) 1 __tconst2VuQ234) (exists ref (1 0) 1 __tconst1EUj230) (exists ref (1 0) 1 __tconst7sqz226) (join ref (1 0) 1 __tconst4Sko246 __t16jv239) (join ref (1 0) 1 __tconst2x2f244 __t3pbc237) (join ref (1 0) 1 __tconst2VuQ234 __t2PLq233) (join ref (1 0) 1 __tconst1EUj230 __t3WVP229) (join ref (1 0) 1 __tconst7sqz226 __t5APF225)) (head (mkstruct lambda (1 2 0) __t2BAX227 __tconst7sqz226 __t5APF225) (mkstruct lambda (1 2 0) __t5ryk231 __tconst1EUj230 __t3WVP229) (mkstruct lambda (1 2 0) __t45rU235 __tconst2VuQ234 __t2PLq233) (mkstruct app (1 2 0) __t4wvK242 __t6KL4241 __t16jv239)) mcfa-counting.slog:272 #f)
  class ReadTask10 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[4];
    slog::Index** head_index[4];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** refindex1;  slog::Index** refindex2;  slog::Index** refindex3;  slog::Index** refindex4;  slog::Index** refindex5;  slog::Index** refindex6;  slog::Index** refindex7;  slog::Index** refindex8;  slog::Index** refindex9;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      head_rel[1] = db->getRelation("lambda");
      head_rel[2] = db->getRelation("lambda");
      head_rel[3] = db->getRelation("app");
      std::vector<u16> ord11({1, 0});
      slog::Relation* readrel12 = db->getRelation("ref");
      driver_index = readrel12->getIndex(ord11, true);
      std::vector<u16> ord13({1, 0});
      slog::Relation* readrel14 = db->getRelation("ref");
      refindex1 = readrel14->getIndex(ord13, false);
      std::vector<u16> ord15({1, 0});
      slog::Relation* readrel16 = db->getRelation("ref");
      refindex2 = readrel16->getIndex(ord15, false);
      std::vector<u16> ord17({1, 0});
      slog::Relation* readrel18 = db->getRelation("ref");
      refindex3 = readrel18->getIndex(ord17, false);
      std::vector<u16> ord19({1, 0});
      slog::Relation* readrel20 = db->getRelation("ref");
      refindex4 = readrel20->getIndex(ord19, false);
      std::vector<u16> ord21({1, 0});
      slog::Relation* readrel22 = db->getRelation("ref");
      refindex5 = readrel22->getIndex(ord21, false);
      std::vector<u16> ord23({1, 0});
      slog::Relation* readrel24 = db->getRelation("ref");
      refindex6 = readrel24->getIndex(ord23, false);
      std::vector<u16> ord25({1, 0});
      slog::Relation* readrel26 = db->getRelation("ref");
      refindex7 = readrel26->getIndex(ord25, false);
      std::vector<u16> ord27({1, 0});
      slog::Relation* readrel28 = db->getRelation("ref");
      refindex8 = readrel28->getIndex(ord27, false);
      std::vector<u16> ord29({1, 0});
      slog::Relation* readrel30 = db->getRelation("ref");
      refindex9 = readrel30->getIndex(ord29, false);
  
    }
    ReadTask10(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c6 = v_const7b8fd91ee9ff10cfbb8066bf;
      u64 v_c7 = v_const615ad01b1c532bb6634df115;
      u64 v_c8 = v_const4492fd5fa4baacfebd29f5e5;
      u64 v_c9 = v_consta32d5a443def48e6d64c6f4b;
      u64 v_c10 = v_consteb793a6f75d6cfe49d3c2c90;
      u64 v_c11 = v_constaaaad65142343c54348db5d0;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[4];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c11, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m31) {
        u64 v_c12 = m31[1];
        if (buckethash(v_c12) != bucket) return;
        if (!slog::exists_probe<2,1>(refindex1, std::array<u64,2>{v_c9, 0})) return;
        if (!slog::exists_probe<2,1>(refindex2, std::array<u64,2>{v_c8, 0})) return;
        if (!slog::exists_probe<2,1>(refindex3, std::array<u64,2>{v_c7, 0})) return;
        if (!slog::exists_probe<2,1>(refindex4, std::array<u64,2>{v_c6, 0})) return;
        slog::join_probe<2,1>(refindex5, std::array<u64,2>{v_c10, 0}, [&](const std::array<u64,2>& m32) {
          u64 v_c13 = m32[1];
          slog::join_probe<2,1>(refindex6, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m33) {
            u64 v_c14 = m33[1];
            slog::join_probe<2,1>(refindex7, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m34) {
              u64 v_c15 = m34[1];
              slog::join_probe<2,1>(refindex8, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m35) {
                u64 v_c16 = m35[1];
                slog::join_probe<2,1>(refindex9, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m36) {
                  u64 v_c17 = m36[1];
                  ++_fires;
                  slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c6, v_c17}, std::array<u16,3>{1, 2, 0});
                  slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c7, v_c16}, std::array<u16,3>{1, 2, 0});
                  slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c8, v_c15}, std::array<u16,3>{1, 2, 0});
                  slog::emit_struct<3>(head_rel[3], newbatch[3], std::array<u64,2>{v_c12, v_c13}, std::array<u16,3>{1, 2, 0});
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
  
      if (_fires) db->bumpFires("mcfa-counting.slog:272", "delta:ref", _fires);
  
      if (!_done)
      {
        ReadTask10* _cont = new ReadTask10(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask10(db,b), false);
  // (crule (pre) (scan app __t6ooL258 ef ea) (body (exists eval (1 2 0) 1 ef) (exists eval (1 2 0) 1 ea) (join eval (1 2 0) 1 __t6ooL258 c __5DEq344) (exists eval (1 2 0) 2 ea c) (join-old eval (1 2 0) 2 (1 2 0) ef c __t7ceq259) (exists eval_ans (0 1) 1 __t7ceq259) (join-old eval (1 2 0) 2 (1 2 0) ea c __t2S0s262) (exists eval_ans (0 1) 1 __t2S0s262) (join eval_ans (0 1) 1 __t7ceq259 __t0zen261) (join eval_ans (0 1) 1 __t2S0s262 va) (join-old clo (0 2 1) 1 (0 2 1) __t0zen261 cb __t4JNf263) (exists store (1 0 2) 1 cb) (join freevar (1 0) 1 __t4JNf263 y) (join store (0 1 2) 2 y cb vy) (join-old lambda (0 1 2) 1 (0 1 2) __t4JNf263 x eb)) (head (emit store (0 1 2) y __t6ooL258 vy) (emit bindev (0 1 2) y __t6ooL258 c)) mcfa-counting.slog:102 #f)
  class ReadTask56 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex37;  slog::Index** evalindex38;  slog::Index** evalindex39;  slog::Index** evalindex40;  slog::Index** evalindex41;  slog::Index** eval_ansindex42;  slog::Index** evalindex43;  slog::Index** eval_ansindex44;  slog::Index** eval_ansindex45;  slog::Index** eval_ansindex46;  slog::Index** cloindex47;  slog::Index** storeindex48;  slog::Index** freevarindex49;  slog::Index** storeindex50;  slog::Index** lambdaindex51;  slog::Index** evaldelta52;  slog::Index** evaldelta53;  slog::Index** clodelta54;  slog::Index** lambdadelta55;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("store");
      std::vector<u16> ord57({0, 1, 2});
      slog::Relation* readrel58 = db->getRelation("store");
      head_index[0] = readrel58->getIndex(ord57, false);
      head_rel[1] = db->getRelation("bindev");
      std::vector<u16> ord59({0, 1, 2});
      slog::Relation* readrel60 = db->getRelation("bindev");
      head_index[1] = readrel60->getIndex(ord59, false);
      outer_rel = db->getRelation("app");
      std::vector<u16> ord61({1, 2, 0});
      slog::Relation* readrel62 = db->getRelation("eval");
      evalindex37 = readrel62->getIndex(ord61, false);
      std::vector<u16> ord63({1, 2, 0});
      slog::Relation* readrel64 = db->getRelation("eval");
      evalindex38 = readrel64->getIndex(ord63, false);
      std::vector<u16> ord65({1, 2, 0});
      slog::Relation* readrel66 = db->getRelation("eval");
      evalindex39 = readrel66->getIndex(ord65, false);
      std::vector<u16> ord67({1, 2, 0});
      slog::Relation* readrel68 = db->getRelation("eval");
      evalindex40 = readrel68->getIndex(ord67, false);
      std::vector<u16> ord69({1, 2, 0});
      slog::Relation* readrel70 = db->getRelation("eval");
      evalindex41 = readrel70->getIndex(ord69, false);
      std::vector<u16> ord71({1, 2, 0});
      slog::Relation* readrel72 = db->getRelation("eval");
      evaldelta52 = readrel72->getIndex(ord71, true);
      std::vector<u16> ord73({0, 1});
      slog::Relation* readrel74 = db->getRelation("eval_ans");
      eval_ansindex42 = readrel74->getIndex(ord73, false);
      std::vector<u16> ord75({1, 2, 0});
      slog::Relation* readrel76 = db->getRelation("eval");
      evalindex43 = readrel76->getIndex(ord75, false);
      std::vector<u16> ord77({1, 2, 0});
      slog::Relation* readrel78 = db->getRelation("eval");
      evaldelta53 = readrel78->getIndex(ord77, true);
      std::vector<u16> ord79({0, 1});
      slog::Relation* readrel80 = db->getRelation("eval_ans");
      eval_ansindex44 = readrel80->getIndex(ord79, false);
      std::vector<u16> ord81({0, 1});
      slog::Relation* readrel82 = db->getRelation("eval_ans");
      eval_ansindex45 = readrel82->getIndex(ord81, false);
      std::vector<u16> ord83({0, 1});
      slog::Relation* readrel84 = db->getRelation("eval_ans");
      eval_ansindex46 = readrel84->getIndex(ord83, false);
      std::vector<u16> ord85({0, 2, 1});
      slog::Relation* readrel86 = db->getRelation("clo");
      cloindex47 = readrel86->getIndex(ord85, false);
      std::vector<u16> ord87({0, 2, 1});
      slog::Relation* readrel88 = db->getRelation("clo");
      clodelta54 = readrel88->getIndex(ord87, true);
      std::vector<u16> ord89({1, 0, 2});
      slog::Relation* readrel90 = db->getRelation("store");
      storeindex48 = readrel90->getIndex(ord89, false);
      std::vector<u16> ord91({1, 0});
      slog::Relation* readrel92 = db->getRelation("freevar");
      freevarindex49 = readrel92->getIndex(ord91, false);
      std::vector<u16> ord93({0, 1, 2});
      slog::Relation* readrel94 = db->getRelation("store");
      storeindex50 = readrel94->getIndex(ord93, false);
      std::vector<u16> ord95({0, 1, 2});
      slog::Relation* readrel96 = db->getRelation("lambda");
      lambdaindex51 = readrel96->getIndex(ord95, false);
      std::vector<u16> ord97({0, 1, 2});
      slog::Relation* readrel98 = db->getRelation("lambda");
      lambdadelta55 = readrel98->getIndex(ord97, true);
  
    }
    ReadTask56(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c18 = _t[0];
        u64 v_c19 = _t[1];
        u64 v_c20 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex37, std::array<u64,3>{v_c19, 0, 0})) return;
        if (!slog::exists_probe<3,1>(evalindex38, std::array<u64,3>{v_c20, 0, 0})) return;
        slog::join_probe<3,1>(evalindex39, std::array<u64,3>{v_c18, 0, 0}, [&](const std::array<u64,3>& m99) {
          u64 v_c21 = m99[1]; u64 v_c22 = m99[2];
          if (!slog::exists_probe<3,2>(evalindex40, std::array<u64,3>{v_c20, v_c21, 0})) return;
          slog::join_probe_old<3,2>(evalindex41, evaldelta52, std::array<u64,3>{v_c19, v_c21, 0}, [&](const std::array<u64,3>& m100) {
            u64 v_c23 = m100[2];
            if (!slog::exists_probe<2,1>(eval_ansindex42, std::array<u64,2>{v_c23, 0})) return;
            slog::join_probe_old<3,2>(evalindex43, evaldelta53, std::array<u64,3>{v_c20, v_c21, 0}, [&](const std::array<u64,3>& m101) {
              u64 v_c24 = m101[2];
              if (!slog::exists_probe<2,1>(eval_ansindex44, std::array<u64,2>{v_c24, 0})) return;
              slog::join_probe<2,1>(eval_ansindex45, std::array<u64,2>{v_c23, 0}, [&](const std::array<u64,2>& m102) {
                u64 v_c25 = m102[1];
                slog::join_probe<2,1>(eval_ansindex46, std::array<u64,2>{v_c24, 0}, [&](const std::array<u64,2>& m103) {
                  u64 v_c26 = m103[1];
                  slog::join_probe_old<3,1>(cloindex47, clodelta54, std::array<u64,3>{v_c25, 0, 0}, [&](const std::array<u64,3>& m104) {
                    u64 v_c27 = m104[1]; u64 v_c28 = m104[2];
                    if (!slog::exists_probe<3,1>(storeindex48, std::array<u64,3>{v_c27, 0, 0})) return;
                    slog::join_probe<2,1>(freevarindex49, std::array<u64,2>{v_c28, 0}, [&](const std::array<u64,2>& m105) {
                      u64 v_c29 = m105[1];
                      slog::join_probe<3,2>(storeindex50, std::array<u64,3>{v_c29, v_c27, 0}, [&](const std::array<u64,3>& m106) {
                        u64 v_c30 = m106[2];
                        slog::join_probe_old<3,1>(lambdaindex51, lambdadelta55, std::array<u64,3>{v_c28, 0, 0}, [&](const std::array<u64,3>& m107) {
                          u64 v_c31 = m107[1]; u64 v_c32 = m107[2];
                          ++_fires;
                          slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c29, v_c18, v_c30}, std::array<u16,3>{0, 1, 2});
                          slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c29, v_c18, v_c21}, std::array<u16,3>{0, 1, 2});
                        });
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
  
      if (_fires) db->bumpFires("mcfa-counting.slog:102", "delta:app", _fires);
  
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
  // (crule (pre (let __tconst5Fqn220 const15bb62b8293a526ca6f0e4eb) (let __tconst0ZcM213 constfc9ee54e0ee8c6d1e715716c) (let __tconst9TQS210 const5950e3cb761734f52a881545) (let __tconst1wsq203 const77ceb5c0e9f84ebd84104a97)) (probe lambda (1 2 0) 1 __tconst9TQS210 __t1W86209 __t1wmd211) (body (exists lambda (1 2 0) 1 __tconst1wsq203) (exists ref (1 0) 1 __tconst0ZcM213) (exists ref (1 0) 1 __tconst5Fqn220) (exists lambda (1 2 0) 1 __tconst5Fqn220) (join ref (1 0) 1 __tconst1wsq203 __t6pkv202) (join lambda (1 2 0) 2 __tconst1wsq203 __t6pkv202 __t118D204) (join ref (1 0) 1 __tconst0ZcM213 __t6fYg206) (join app (0 1 2) 2 __t1W86209 __t6fYg206 dup64Fz421) (eq __t6fYg206 dup64Fz421) (join ref (1 0) 1 __tconst5Fqn220 __t2V0C216) (join app (1 2 0) 1 __t2V0C216 dup8ia4422 __t9nSF219) (eq __t2V0C216 dup8ia4422) (join lambda (1 2 0) 2 __tconst5Fqn220 __t9nSF219 __t6h87221)) (head (mkstruct app (1 2 0) __t4jAx212 __t1wmd211 __t118D204)) mcfa-counting.slog:211 #f)
  class ReadTask119 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** lambdaindex108;  slog::Index** refindex109;  slog::Index** refindex110;  slog::Index** lambdaindex111;  slog::Index** refindex112;  slog::Index** lambdaindex113;  slog::Index** refindex114;  slog::Index** appindex115;  slog::Index** refindex116;  slog::Index** appindex117;  slog::Index** lambdaindex118;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord120({1, 2, 0});
      slog::Relation* readrel121 = db->getRelation("lambda");
      driver_index = readrel121->getIndex(ord120, true);
      std::vector<u16> ord122({1, 2, 0});
      slog::Relation* readrel123 = db->getRelation("lambda");
      lambdaindex108 = readrel123->getIndex(ord122, false);
      std::vector<u16> ord124({1, 0});
      slog::Relation* readrel125 = db->getRelation("ref");
      refindex109 = readrel125->getIndex(ord124, false);
      std::vector<u16> ord126({1, 0});
      slog::Relation* readrel127 = db->getRelation("ref");
      refindex110 = readrel127->getIndex(ord126, false);
      std::vector<u16> ord128({1, 2, 0});
      slog::Relation* readrel129 = db->getRelation("lambda");
      lambdaindex111 = readrel129->getIndex(ord128, false);
      std::vector<u16> ord130({1, 0});
      slog::Relation* readrel131 = db->getRelation("ref");
      refindex112 = readrel131->getIndex(ord130, false);
      std::vector<u16> ord132({1, 2, 0});
      slog::Relation* readrel133 = db->getRelation("lambda");
      lambdaindex113 = readrel133->getIndex(ord132, false);
      std::vector<u16> ord134({1, 0});
      slog::Relation* readrel135 = db->getRelation("ref");
      refindex114 = readrel135->getIndex(ord134, false);
      std::vector<u16> ord136({0, 1, 2});
      slog::Relation* readrel137 = db->getRelation("app");
      appindex115 = readrel137->getIndex(ord136, false);
      std::vector<u16> ord138({1, 0});
      slog::Relation* readrel139 = db->getRelation("ref");
      refindex116 = readrel139->getIndex(ord138, false);
      std::vector<u16> ord140({1, 2, 0});
      slog::Relation* readrel141 = db->getRelation("app");
      appindex117 = readrel141->getIndex(ord140, false);
      std::vector<u16> ord142({1, 2, 0});
      slog::Relation* readrel143 = db->getRelation("lambda");
      lambdaindex118 = readrel143->getIndex(ord142, false);
  
    }
    ReadTask119(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c33 = v_const15bb62b8293a526ca6f0e4eb;
      u64 v_c34 = v_constfc9ee54e0ee8c6d1e715716c;
      u64 v_c35 = v_const5950e3cb761734f52a881545;
      u64 v_c36 = v_const77ceb5c0e9f84ebd84104a97;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c35, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m144) {
        u64 v_c37 = m144[1];
        u64 v_c38 = m144[2];
        if (buckethash(v_c37) != bucket) return;
        if (!slog::exists_probe<3,1>(lambdaindex108, std::array<u64,3>{v_c36, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex109, std::array<u64,2>{v_c34, 0})) return;
        if (!slog::exists_probe<2,1>(refindex110, std::array<u64,2>{v_c33, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex111, std::array<u64,3>{v_c33, 0, 0})) return;
        slog::join_probe<2,1>(refindex112, std::array<u64,2>{v_c36, 0}, [&](const std::array<u64,2>& m145) {
          u64 v_c39 = m145[1];
          slog::join_probe<3,2>(lambdaindex113, std::array<u64,3>{v_c36, v_c39, 0}, [&](const std::array<u64,3>& m146) {
            u64 v_c40 = m146[2];
            slog::join_probe<2,1>(refindex114, std::array<u64,2>{v_c34, 0}, [&](const std::array<u64,2>& m147) {
              u64 v_c41 = m147[1];
              slog::join_probe<3,2>(appindex115, std::array<u64,3>{v_c37, v_c41, 0}, [&](const std::array<u64,3>& m148) {
                u64 v_c42 = m148[2];
                if (v_c41 != v_c42) return;
                slog::join_probe<2,1>(refindex116, std::array<u64,2>{v_c33, 0}, [&](const std::array<u64,2>& m149) {
                  u64 v_c43 = m149[1];
                  slog::join_probe<3,1>(appindex117, std::array<u64,3>{v_c43, 0, 0}, [&](const std::array<u64,3>& m150) {
                    u64 v_c44 = m150[1]; u64 v_c45 = m150[2];
                    if (v_c43 != v_c44) return;
                    slog::join_probe<3,2>(lambdaindex118, std::array<u64,3>{v_c33, v_c45, 0}, [&](const std::array<u64,3>& m151) {
                      u64 v_c46 = m151[2];
                      ++_fires;
                      slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c38, v_c40}, std::array<u16,3>{1, 2, 0});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:211", "delta:lambda", _fires);
  
      if (!_done)
      {
        ReadTask119* _cont = new ReadTask119(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask119(db,b), false);
  // (crule (pre (let __tconst0ZcM213 constfc9ee54e0ee8c6d1e715716c) (let __tconst5Fqn220 const15bb62b8293a526ca6f0e4eb) (let __tconst9TQS210 const5950e3cb761734f52a881545) (let __tconst1wsq203 const77ceb5c0e9f84ebd84104a97)) (seeded) (body (join ref (1 0) 1 __tconst1wsq203 __t6pkv202) (exists ref (1 0) 1 __tconst0ZcM213) (exists ref (1 0) 1 __tconst5Fqn220) (exists lambda (1 2 0) 1 __tconst9TQS210) (exists lambda (1 2 0) 1 __tconst5Fqn220) (join lambda (1 2 0) 2 __tconst1wsq203 __t6pkv202 __t118D204) (exists app (2 0 1) 1 __t118D204) (join ref (1 0) 1 __tconst0ZcM213 __t6fYg206) (exists app (1 2 0) 1 __t6fYg206) (join ref (1 0) 1 __tconst5Fqn220 __t2V0C216) (exists app (1 2 0) 1 __t2V0C216) (join app (1 2 0) 1 __t6fYg206 dup59iU427 __t1W86209) (eq __t6fYg206 dup59iU427) (join lambda (1 2 0) 2 __tconst9TQS210 __t1W86209 __t1wmd211) (join app (1 2 0) 2 __t1wmd211 __t118D204 __t4jAx212) (join app (1 2 0) 1 __t2V0C216 dup5A0V428 __t9nSF219) (eq __t2V0C216 dup5A0V428) (join lambda (1 2 0) 2 __tconst5Fqn220 __t9nSF219 __t6h87221)) (head (mkstruct lambda (1 2 0) __t14ld214 __tconst0ZcM213 __t4jAx212)) mcfa-counting.slog:211 #f)
  class ReadTask168 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex152;  slog::Index** refindex153;  slog::Index** refindex154;  slog::Index** lambdaindex155;  slog::Index** lambdaindex156;  slog::Index** lambdaindex157;  slog::Index** appindex158;  slog::Index** refindex159;  slog::Index** appindex160;  slog::Index** refindex161;  slog::Index** appindex162;  slog::Index** appindex163;  slog::Index** lambdaindex164;  slog::Index** appindex165;  slog::Index** appindex166;  slog::Index** lambdaindex167;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      std::vector<u16> ord169({1, 2, 0});
      slog::Relation* readrel170 = db->getRelation("lambda");
      head_index[0] = readrel170->getIndex(ord169, false);
      std::vector<u16> ord171({1, 0});
      slog::Relation* readrel172 = db->getRelation("ref");
      refindex152 = readrel172->getIndex(ord171, false);
      std::vector<u16> ord173({1, 0});
      slog::Relation* readrel174 = db->getRelation("ref");
      refindex153 = readrel174->getIndex(ord173, false);
      std::vector<u16> ord175({1, 0});
      slog::Relation* readrel176 = db->getRelation("ref");
      refindex154 = readrel176->getIndex(ord175, false);
      std::vector<u16> ord177({1, 2, 0});
      slog::Relation* readrel178 = db->getRelation("lambda");
      lambdaindex155 = readrel178->getIndex(ord177, false);
      std::vector<u16> ord179({1, 2, 0});
      slog::Relation* readrel180 = db->getRelation("lambda");
      lambdaindex156 = readrel180->getIndex(ord179, false);
      std::vector<u16> ord181({1, 2, 0});
      slog::Relation* readrel182 = db->getRelation("lambda");
      lambdaindex157 = readrel182->getIndex(ord181, false);
      std::vector<u16> ord183({2, 0, 1});
      slog::Relation* readrel184 = db->getRelation("app");
      appindex158 = readrel184->getIndex(ord183, false);
      std::vector<u16> ord185({1, 0});
      slog::Relation* readrel186 = db->getRelation("ref");
      refindex159 = readrel186->getIndex(ord185, false);
      std::vector<u16> ord187({1, 2, 0});
      slog::Relation* readrel188 = db->getRelation("app");
      appindex160 = readrel188->getIndex(ord187, false);
      std::vector<u16> ord189({1, 0});
      slog::Relation* readrel190 = db->getRelation("ref");
      refindex161 = readrel190->getIndex(ord189, false);
      std::vector<u16> ord191({1, 2, 0});
      slog::Relation* readrel192 = db->getRelation("app");
      appindex162 = readrel192->getIndex(ord191, false);
      std::vector<u16> ord193({1, 2, 0});
      slog::Relation* readrel194 = db->getRelation("app");
      appindex163 = readrel194->getIndex(ord193, false);
      std::vector<u16> ord195({1, 2, 0});
      slog::Relation* readrel196 = db->getRelation("lambda");
      lambdaindex164 = readrel196->getIndex(ord195, false);
      std::vector<u16> ord197({1, 2, 0});
      slog::Relation* readrel198 = db->getRelation("app");
      appindex165 = readrel198->getIndex(ord197, false);
      std::vector<u16> ord199({1, 2, 0});
      slog::Relation* readrel200 = db->getRelation("app");
      appindex166 = readrel200->getIndex(ord199, false);
      std::vector<u16> ord201({1, 2, 0});
      slog::Relation* readrel202 = db->getRelation("lambda");
      lambdaindex167 = readrel202->getIndex(ord201, false);
  
    }
    ReadTask168(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c34 = v_constfc9ee54e0ee8c6d1e715716c;
      u64 v_c33 = v_const15bb62b8293a526ca6f0e4eb;
      u64 v_c35 = v_const5950e3cb761734f52a881545;
      u64 v_c36 = v_const77ceb5c0e9f84ebd84104a97;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex152, std::array<u64,2>{v_c36, 0}, [&](const std::array<u64,2>& m203) {
        u64 v_c39 = m203[1];
        if (!slog::exists_probe<2,1>(refindex153, std::array<u64,2>{v_c34, 0})) return;
        if (!slog::exists_probe<2,1>(refindex154, std::array<u64,2>{v_c33, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex155, std::array<u64,3>{v_c35, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex156, std::array<u64,3>{v_c33, 0, 0})) return;
        slog::join_probe<3,2>(lambdaindex157, std::array<u64,3>{v_c36, v_c39, 0}, [&](const std::array<u64,3>& m204) {
          u64 v_c40 = m204[2];
          if (!slog::exists_probe<3,1>(appindex158, std::array<u64,3>{v_c40, 0, 0})) return;
          slog::join_probe<2,1>(refindex159, std::array<u64,2>{v_c34, 0}, [&](const std::array<u64,2>& m205) {
            u64 v_c41 = m205[1];
            if (!slog::exists_probe<3,1>(appindex160, std::array<u64,3>{v_c41, 0, 0})) return;
            slog::join_probe<2,1>(refindex161, std::array<u64,2>{v_c33, 0}, [&](const std::array<u64,2>& m206) {
              u64 v_c43 = m206[1];
              if (!slog::exists_probe<3,1>(appindex162, std::array<u64,3>{v_c43, 0, 0})) return;
              slog::join_probe<3,1>(appindex163, std::array<u64,3>{v_c41, 0, 0}, [&](const std::array<u64,3>& m207) {
                u64 v_c47 = m207[1]; u64 v_c37 = m207[2];
                if (v_c41 != v_c47) return;
                slog::join_probe<3,2>(lambdaindex164, std::array<u64,3>{v_c35, v_c37, 0}, [&](const std::array<u64,3>& m208) {
                  u64 v_c38 = m208[2];
                  slog::join_probe<3,2>(appindex165, std::array<u64,3>{v_c38, v_c40, 0}, [&](const std::array<u64,3>& m209) {
                    u64 v_c48 = m209[2];
                    slog::join_probe<3,1>(appindex166, std::array<u64,3>{v_c43, 0, 0}, [&](const std::array<u64,3>& m210) {
                      u64 v_c49 = m210[1]; u64 v_c45 = m210[2];
                      if (v_c43 != v_c49) return;
                      slog::join_probe<3,2>(lambdaindex167, std::array<u64,3>{v_c33, v_c45, 0}, [&](const std::array<u64,3>& m211) {
                        u64 v_c46 = m211[2];
                        ++_fires;
                        slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c34, v_c48}, std::array<u16,3>{1, 2, 0});
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
  
      if (_fires) db->bumpFires("mcfa-counting.slog:211", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask168(db,b));
  // (crule (pre (let __tconst5Fqn220 const15bb62b8293a526ca6f0e4eb) (let __tconst0ZcM213 constfc9ee54e0ee8c6d1e715716c) (let __tconst9TQS210 const5950e3cb761734f52a881545) (let __tconst1wsq203 const77ceb5c0e9f84ebd84104a97)) (probe ref (1 0) 1 __tconst1wsq203 __t6pkv202) (body (exists ref (1 0) 1 __tconst5Fqn220) (join ref (1 0) 1 __tconst0ZcM213 __t6fYg206) (join ref (1 0) 1 __tconst5Fqn220 __t2V0C216)) (head (mkstruct app (1 2 0) __t9nSF219 __t2V0C216 __t2V0C216) (mkstruct app (1 2 0) __t1W86209 __t6fYg206 __t6fYg206) (mkstruct lambda (1 2 0) __t118D204 __tconst1wsq203 __t6pkv202)) mcfa-counting.slog:211 #f)
  class ReadTask215 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** refindex212;  slog::Index** refindex213;  slog::Index** refindex214;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      head_rel[1] = db->getRelation("app");
      head_rel[2] = db->getRelation("lambda");
      std::vector<u16> ord216({1, 0});
      slog::Relation* readrel217 = db->getRelation("ref");
      driver_index = readrel217->getIndex(ord216, true);
      std::vector<u16> ord218({1, 0});
      slog::Relation* readrel219 = db->getRelation("ref");
      refindex212 = readrel219->getIndex(ord218, false);
      std::vector<u16> ord220({1, 0});
      slog::Relation* readrel221 = db->getRelation("ref");
      refindex213 = readrel221->getIndex(ord220, false);
      std::vector<u16> ord222({1, 0});
      slog::Relation* readrel223 = db->getRelation("ref");
      refindex214 = readrel223->getIndex(ord222, false);
  
    }
    ReadTask215(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c33 = v_const15bb62b8293a526ca6f0e4eb;
      u64 v_c34 = v_constfc9ee54e0ee8c6d1e715716c;
      u64 v_c35 = v_const5950e3cb761734f52a881545;
      u64 v_c36 = v_const77ceb5c0e9f84ebd84104a97;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c36, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m224) {
        u64 v_c39 = m224[1];
        if (buckethash(v_c39) != bucket) return;
        if (!slog::exists_probe<2,1>(refindex212, std::array<u64,2>{v_c33, 0})) return;
        slog::join_probe<2,1>(refindex213, std::array<u64,2>{v_c34, 0}, [&](const std::array<u64,2>& m225) {
          u64 v_c41 = m225[1];
          slog::join_probe<2,1>(refindex214, std::array<u64,2>{v_c33, 0}, [&](const std::array<u64,2>& m226) {
            u64 v_c43 = m226[1];
            ++_fires;
            slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c43, v_c43}, std::array<u16,3>{1, 2, 0});
            slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c41, v_c41}, std::array<u16,3>{1, 2, 0});
            slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c36, v_c39}, std::array<u16,3>{1, 2, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:211", "delta:ref", _fires);
  
      if (!_done)
      {
        ReadTask215* _cont = new ReadTask215(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask215(db,b), false);
  // (crule (pre (let __tconst8xRt151 const3a82152bd1402931076fe2d7) (let __tconst0zC2144 const4e3b5454cf93e32fad90650d) (let __tconst3Taj142 constdc1bb6655fb38bdb032e3754) (let __tconst8eg8132 const361d5df359e0d7681220d09d)) (seeded) (body (join ref (1 0) 1 __tconst8eg8132 __t19JM131) (exists ref (1 0) 1 __tconst3Taj142) (exists ref (1 0) 1 __tconst0zC2144) (exists ref (1 0) 1 __tconst8xRt151) (join lambda (1 2 0) 2 __tconst8eg8132 __t19JM131 __t4DXA133) (join ref (1 0) 1 __tconst3Taj142 __t93Xi135) (join ref (1 0) 1 __tconst0zC2144 __t7VSc137) (exists app (1 2 0) 1 __t7VSc137) (join ref (1 0) 1 __tconst8xRt151 __t1g2P147) (exists app (1 2 0) 1 __t1g2P147) (join app (1 2 0) 1 __t7VSc137 dup0qxc393 __t8dYW140) (eq __t7VSc137 dup0qxc393) (join app (1 2 0) 1 __t1g2P147 dup0w3U394 __t9UZN150) (eq __t1g2P147 dup0w3U394)) (head (mkstruct lambda (1 2 0) __t2nYy152 __tconst8xRt151 __t9UZN150) (mkstruct app (1 2 0) __t25NQ141 __t8dYW140 __t93Xi135)) mcfa-counting.slog:224 #f)
  class ReadTask239 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
  
  
  
  
  
    slog::Index** refindex227;  slog::Index** refindex228;  slog::Index** refindex229;  slog::Index** refindex230;  slog::Index** lambdaindex231;  slog::Index** refindex232;  slog::Index** refindex233;  slog::Index** appindex234;  slog::Index** refindex235;  slog::Index** appindex236;  slog::Index** appindex237;  slog::Index** appindex238;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      std::vector<u16> ord240({1, 2, 0});
      slog::Relation* readrel241 = db->getRelation("lambda");
      head_index[0] = readrel241->getIndex(ord240, false);
      head_rel[1] = db->getRelation("app");
      std::vector<u16> ord242({1, 2, 0});
      slog::Relation* readrel243 = db->getRelation("app");
      head_index[1] = readrel243->getIndex(ord242, false);
      std::vector<u16> ord244({1, 0});
      slog::Relation* readrel245 = db->getRelation("ref");
      refindex227 = readrel245->getIndex(ord244, false);
      std::vector<u16> ord246({1, 0});
      slog::Relation* readrel247 = db->getRelation("ref");
      refindex228 = readrel247->getIndex(ord246, false);
      std::vector<u16> ord248({1, 0});
      slog::Relation* readrel249 = db->getRelation("ref");
      refindex229 = readrel249->getIndex(ord248, false);
      std::vector<u16> ord250({1, 0});
      slog::Relation* readrel251 = db->getRelation("ref");
      refindex230 = readrel251->getIndex(ord250, false);
      std::vector<u16> ord252({1, 2, 0});
      slog::Relation* readrel253 = db->getRelation("lambda");
      lambdaindex231 = readrel253->getIndex(ord252, false);
      std::vector<u16> ord254({1, 0});
      slog::Relation* readrel255 = db->getRelation("ref");
      refindex232 = readrel255->getIndex(ord254, false);
      std::vector<u16> ord256({1, 0});
      slog::Relation* readrel257 = db->getRelation("ref");
      refindex233 = readrel257->getIndex(ord256, false);
      std::vector<u16> ord258({1, 2, 0});
      slog::Relation* readrel259 = db->getRelation("app");
      appindex234 = readrel259->getIndex(ord258, false);
      std::vector<u16> ord260({1, 0});
      slog::Relation* readrel261 = db->getRelation("ref");
      refindex235 = readrel261->getIndex(ord260, false);
      std::vector<u16> ord262({1, 2, 0});
      slog::Relation* readrel263 = db->getRelation("app");
      appindex236 = readrel263->getIndex(ord262, false);
      std::vector<u16> ord264({1, 2, 0});
      slog::Relation* readrel265 = db->getRelation("app");
      appindex237 = readrel265->getIndex(ord264, false);
      std::vector<u16> ord266({1, 2, 0});
      slog::Relation* readrel267 = db->getRelation("app");
      appindex238 = readrel267->getIndex(ord266, false);
  
    }
    ReadTask239(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c50 = v_const3a82152bd1402931076fe2d7;
      u64 v_c51 = v_const4e3b5454cf93e32fad90650d;
      u64 v_c52 = v_constdc1bb6655fb38bdb032e3754;
      u64 v_c53 = v_const361d5df359e0d7681220d09d;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex227, std::array<u64,2>{v_c53, 0}, [&](const std::array<u64,2>& m268) {
        u64 v_c54 = m268[1];
        if (!slog::exists_probe<2,1>(refindex228, std::array<u64,2>{v_c52, 0})) return;
        if (!slog::exists_probe<2,1>(refindex229, std::array<u64,2>{v_c51, 0})) return;
        if (!slog::exists_probe<2,1>(refindex230, std::array<u64,2>{v_c50, 0})) return;
        slog::join_probe<3,2>(lambdaindex231, std::array<u64,3>{v_c53, v_c54, 0}, [&](const std::array<u64,3>& m269) {
          u64 v_c55 = m269[2];
          slog::join_probe<2,1>(refindex232, std::array<u64,2>{v_c52, 0}, [&](const std::array<u64,2>& m270) {
            u64 v_c56 = m270[1];
            slog::join_probe<2,1>(refindex233, std::array<u64,2>{v_c51, 0}, [&](const std::array<u64,2>& m271) {
              u64 v_c57 = m271[1];
              if (!slog::exists_probe<3,1>(appindex234, std::array<u64,3>{v_c57, 0, 0})) return;
              slog::join_probe<2,1>(refindex235, std::array<u64,2>{v_c50, 0}, [&](const std::array<u64,2>& m272) {
                u64 v_c58 = m272[1];
                if (!slog::exists_probe<3,1>(appindex236, std::array<u64,3>{v_c58, 0, 0})) return;
                slog::join_probe<3,1>(appindex237, std::array<u64,3>{v_c57, 0, 0}, [&](const std::array<u64,3>& m273) {
                  u64 v_c59 = m273[1]; u64 v_c60 = m273[2];
                  if (v_c57 != v_c59) return;
                  slog::join_probe<3,1>(appindex238, std::array<u64,3>{v_c58, 0, 0}, [&](const std::array<u64,3>& m274) {
                    u64 v_c61 = m274[1]; u64 v_c62 = m274[2];
                    if (v_c58 != v_c61) return;
                    ++_fires;
                    slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c50, v_c62}, std::array<u16,3>{1, 2, 0});
                    slog::emit_struct_checked<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c60, v_c56}, std::array<u16,3>{1, 2, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:224", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask239(db,b));
  // (crule (pre (let __tconst2x2f244 consta32d5a443def48e6d64c6f4b) (let __tconst4Sko246 consteb793a6f75d6cfe49d3c2c90) (let __tconst4N2q248 constaaaad65142343c54348db5d0) (let __tconst7sqz226 const7b8fd91ee9ff10cfbb8066bf) (let __tconst1EUj230 const615ad01b1c532bb6634df115) (let __tconst2VuQ234 const4492fd5fa4baacfebd29f5e5)) (seeded) (body (join ref (1 0) 1 __tconst2x2f244 __t3pbc237) (exists ref (1 0) 1 __tconst4Sko246) (exists app (2 0 1) 1 __t3pbc237) (exists ref (1 0) 1 __tconst2VuQ234) (exists lambda (1 2 0) 1 __tconst2VuQ234) (exists ref (1 0) 1 __tconst1EUj230) (exists lambda (1 2 0) 1 __tconst1EUj230) (exists ref (1 0) 1 __tconst7sqz226) (exists lambda (1 2 0) 1 __tconst7sqz226) (join ref (1 0) 1 __tconst4N2q248 __t6KL4241) (exists app (1 2 0) 1 __t6KL4241) (join ref (1 0) 1 __tconst4Sko246 __t16jv239) (join app (1 2 0) 2 __t6KL4241 __t16jv239 __t4wvK242) (join app (1 2 0) 2 __t4wvK242 __t3pbc237 __t5h6K243) (join ref (1 0) 1 __tconst2VuQ234 __t2PLq233) (join lambda (1 2 0) 2 __tconst2VuQ234 __t2PLq233 __t45rU235) (join ref (1 0) 1 __tconst1EUj230 __t3WVP229) (join lambda (1 2 0) 2 __tconst1EUj230 __t3WVP229 __t5ryk231) (join ref (1 0) 1 __tconst7sqz226 __t5APF225) (join lambda (1 2 0) 2 __tconst7sqz226 __t5APF225 __t2BAX227)) (head (mkstruct lambda (1 2 0) __t3laZ245 __tconst2x2f244 __t5h6K243)) mcfa-counting.slog:272 #f)
  class ReadTask295 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex275;  slog::Index** refindex276;  slog::Index** appindex277;  slog::Index** refindex278;  slog::Index** lambdaindex279;  slog::Index** refindex280;  slog::Index** lambdaindex281;  slog::Index** refindex282;  slog::Index** lambdaindex283;  slog::Index** refindex284;  slog::Index** appindex285;  slog::Index** refindex286;  slog::Index** appindex287;  slog::Index** appindex288;  slog::Index** refindex289;  slog::Index** lambdaindex290;  slog::Index** refindex291;  slog::Index** lambdaindex292;  slog::Index** refindex293;  slog::Index** lambdaindex294;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      std::vector<u16> ord296({1, 2, 0});
      slog::Relation* readrel297 = db->getRelation("lambda");
      head_index[0] = readrel297->getIndex(ord296, false);
      std::vector<u16> ord298({1, 0});
      slog::Relation* readrel299 = db->getRelation("ref");
      refindex275 = readrel299->getIndex(ord298, false);
      std::vector<u16> ord300({1, 0});
      slog::Relation* readrel301 = db->getRelation("ref");
      refindex276 = readrel301->getIndex(ord300, false);
      std::vector<u16> ord302({2, 0, 1});
      slog::Relation* readrel303 = db->getRelation("app");
      appindex277 = readrel303->getIndex(ord302, false);
      std::vector<u16> ord304({1, 0});
      slog::Relation* readrel305 = db->getRelation("ref");
      refindex278 = readrel305->getIndex(ord304, false);
      std::vector<u16> ord306({1, 2, 0});
      slog::Relation* readrel307 = db->getRelation("lambda");
      lambdaindex279 = readrel307->getIndex(ord306, false);
      std::vector<u16> ord308({1, 0});
      slog::Relation* readrel309 = db->getRelation("ref");
      refindex280 = readrel309->getIndex(ord308, false);
      std::vector<u16> ord310({1, 2, 0});
      slog::Relation* readrel311 = db->getRelation("lambda");
      lambdaindex281 = readrel311->getIndex(ord310, false);
      std::vector<u16> ord312({1, 0});
      slog::Relation* readrel313 = db->getRelation("ref");
      refindex282 = readrel313->getIndex(ord312, false);
      std::vector<u16> ord314({1, 2, 0});
      slog::Relation* readrel315 = db->getRelation("lambda");
      lambdaindex283 = readrel315->getIndex(ord314, false);
      std::vector<u16> ord316({1, 0});
      slog::Relation* readrel317 = db->getRelation("ref");
      refindex284 = readrel317->getIndex(ord316, false);
      std::vector<u16> ord318({1, 2, 0});
      slog::Relation* readrel319 = db->getRelation("app");
      appindex285 = readrel319->getIndex(ord318, false);
      std::vector<u16> ord320({1, 0});
      slog::Relation* readrel321 = db->getRelation("ref");
      refindex286 = readrel321->getIndex(ord320, false);
      std::vector<u16> ord322({1, 2, 0});
      slog::Relation* readrel323 = db->getRelation("app");
      appindex287 = readrel323->getIndex(ord322, false);
      std::vector<u16> ord324({1, 2, 0});
      slog::Relation* readrel325 = db->getRelation("app");
      appindex288 = readrel325->getIndex(ord324, false);
      std::vector<u16> ord326({1, 0});
      slog::Relation* readrel327 = db->getRelation("ref");
      refindex289 = readrel327->getIndex(ord326, false);
      std::vector<u16> ord328({1, 2, 0});
      slog::Relation* readrel329 = db->getRelation("lambda");
      lambdaindex290 = readrel329->getIndex(ord328, false);
      std::vector<u16> ord330({1, 0});
      slog::Relation* readrel331 = db->getRelation("ref");
      refindex291 = readrel331->getIndex(ord330, false);
      std::vector<u16> ord332({1, 2, 0});
      slog::Relation* readrel333 = db->getRelation("lambda");
      lambdaindex292 = readrel333->getIndex(ord332, false);
      std::vector<u16> ord334({1, 0});
      slog::Relation* readrel335 = db->getRelation("ref");
      refindex293 = readrel335->getIndex(ord334, false);
      std::vector<u16> ord336({1, 2, 0});
      slog::Relation* readrel337 = db->getRelation("lambda");
      lambdaindex294 = readrel337->getIndex(ord336, false);
  
    }
    ReadTask295(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c9 = v_consta32d5a443def48e6d64c6f4b;
      u64 v_c10 = v_consteb793a6f75d6cfe49d3c2c90;
      u64 v_c11 = v_constaaaad65142343c54348db5d0;
      u64 v_c6 = v_const7b8fd91ee9ff10cfbb8066bf;
      u64 v_c7 = v_const615ad01b1c532bb6634df115;
      u64 v_c8 = v_const4492fd5fa4baacfebd29f5e5;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex275, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m338) {
        u64 v_c14 = m338[1];
        if (!slog::exists_probe<2,1>(refindex276, std::array<u64,2>{v_c10, 0})) return;
        if (!slog::exists_probe<3,1>(appindex277, std::array<u64,3>{v_c14, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex278, std::array<u64,2>{v_c8, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex279, std::array<u64,3>{v_c8, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex280, std::array<u64,2>{v_c7, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex281, std::array<u64,3>{v_c7, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex282, std::array<u64,2>{v_c6, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex283, std::array<u64,3>{v_c6, 0, 0})) return;
        slog::join_probe<2,1>(refindex284, std::array<u64,2>{v_c11, 0}, [&](const std::array<u64,2>& m339) {
          u64 v_c12 = m339[1];
          if (!slog::exists_probe<3,1>(appindex285, std::array<u64,3>{v_c12, 0, 0})) return;
          slog::join_probe<2,1>(refindex286, std::array<u64,2>{v_c10, 0}, [&](const std::array<u64,2>& m340) {
            u64 v_c13 = m340[1];
            slog::join_probe<3,2>(appindex287, std::array<u64,3>{v_c12, v_c13, 0}, [&](const std::array<u64,3>& m341) {
              u64 v_c63 = m341[2];
              slog::join_probe<3,2>(appindex288, std::array<u64,3>{v_c63, v_c14, 0}, [&](const std::array<u64,3>& m342) {
                u64 v_c64 = m342[2];
                slog::join_probe<2,1>(refindex289, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m343) {
                  u64 v_c15 = m343[1];
                  slog::join_probe<3,2>(lambdaindex290, std::array<u64,3>{v_c8, v_c15, 0}, [&](const std::array<u64,3>& m344) {
                    u64 v_c65 = m344[2];
                    slog::join_probe<2,1>(refindex291, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m345) {
                      u64 v_c16 = m345[1];
                      slog::join_probe<3,2>(lambdaindex292, std::array<u64,3>{v_c7, v_c16, 0}, [&](const std::array<u64,3>& m346) {
                        u64 v_c66 = m346[2];
                        slog::join_probe<2,1>(refindex293, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m347) {
                          u64 v_c17 = m347[1];
                          slog::join_probe<3,2>(lambdaindex294, std::array<u64,3>{v_c6, v_c17, 0}, [&](const std::array<u64,3>& m348) {
                            u64 v_c67 = m348[2];
                            ++_fires;
                            slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c9, v_c64}, std::array<u16,3>{1, 2, 0});
                          });
                        });
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
      s->addTaskSeeded(phase_read, new ReadTask295(db,b));
  // (crule (pre) (scan eval_ans __t1FV8318 __t1oxE320) (body (exists $sup27994x83x0x0x1 (1 4 0 2 3 5 6 7 8 9) 1 __t1FV8318) (join-old eval (0 2 1) 1 (0 2 1) __t1FV8318 c ef) (exists $sup27994x83x0x0x1 (1 3 7 4 0 2 5 6 8 9) 3 __t1FV8318 c ef) (exists eval (2 0 1) 1 c) (exists app (1 2 0) 1 ef) (join-old $sup27994x83x0x0x0 (1 3 0 2) 2 (1 3 0 2) c ef __t5GoB317 ea) (exists eval (1 2 0) 2 ea c) (exists eval (0 2 1) 2 __t5GoB317 c) (exists app (1 2 0) 2 ef ea) (join-old $sup27994x83x0x0x1 (5 7 0 3 1 2 4 6 8 9) 5 (5 7 0 3 1 2 4 6 8 9) ea ef __t5GoB317 c __t1FV8318 __t8XTs321 cb eb va x) (join-old eval (0 2 1) 3 (0 2 1) __t8XTs321 c ea) (join-old eval_ans (0 1) 2 (0 1) __t8XTs321 va) (exists lambda (1 2 0) 2 x eb) (exists clo (0 2 1) 2 __t1oxE320 cb) (exists eval (1 2 0) 1 eb) (join-old eval (0 2 1) 2 (0 2 1) __t5GoB317 c __t3MbO322) (join-old app (0 1 2) 3 (0 1 2) __t3MbO322 ef ea) (exists eval (1 2 0) 2 eb __t3MbO322) (join-old lambda (1 2 0) 2 (1 2 0) x eb __t6vap319) (join-old clo (0 2 1) 3 (0 2 1) __t1oxE320 cb __t6vap319) (join-old eval (1 2 0) 2 (1 2 0) eb __t3MbO322 __t3H1A323) (join-old eval_ans (0 1) 1 (0 1) __t3H1A323 v)) (head (emit eval_ans (0 1) __t5GoB317 v)) mcfa-counting.slog:84 #f)
  class ReadTask382 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup27994x83x0x0x1index349;  slog::Index** evalindex350;  slog::Index** $sup27994x83x0x0x1index351;  slog::Index** evalindex352;  slog::Index** appindex353;  slog::Index** $sup27994x83x0x0x0index354;  slog::Index** evalindex355;  slog::Index** evalindex356;  slog::Index** appindex357;  slog::Index** $sup27994x83x0x0x1index358;  slog::Index** evalindex359;  slog::Index** eval_ansindex360;  slog::Index** lambdaindex361;  slog::Index** cloindex362;  slog::Index** evalindex363;  slog::Index** evalindex364;  slog::Index** appindex365;  slog::Index** evalindex366;  slog::Index** lambdaindex367;  slog::Index** cloindex368;  slog::Index** evalindex369;  slog::Index** eval_ansindex370;  slog::Index** evaldelta371;  slog::Index** $sup27994x83x0x0x0delta372;  slog::Index** $sup27994x83x0x0x1delta373;  slog::Index** evaldelta374;  slog::Index** eval_ansdelta375;  slog::Index** evaldelta376;  slog::Index** appdelta377;  slog::Index** lambdadelta378;  slog::Index** clodelta379;  slog::Index** evaldelta380;  slog::Index** eval_ansdelta381;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord383({0, 1});
      slog::Relation* readrel384 = db->getRelation("eval_ans");
      head_index[0] = readrel384->getIndex(ord383, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord385({1, 4, 0, 2, 3, 5, 6, 7, 8, 9});
      slog::Relation* readrel386 = db->getRelation("$sup27994x83x0x0x1");
      $sup27994x83x0x0x1index349 = readrel386->getIndex(ord385, false);
      std::vector<u16> ord387({0, 2, 1});
      slog::Relation* readrel388 = db->getRelation("eval");
      evalindex350 = readrel388->getIndex(ord387, false);
      std::vector<u16> ord389({0, 2, 1});
      slog::Relation* readrel390 = db->getRelation("eval");
      evaldelta371 = readrel390->getIndex(ord389, true);
      std::vector<u16> ord391({1, 3, 7, 4, 0, 2, 5, 6, 8, 9});
      slog::Relation* readrel392 = db->getRelation("$sup27994x83x0x0x1");
      $sup27994x83x0x0x1index351 = readrel392->getIndex(ord391, false);
      std::vector<u16> ord393({2, 0, 1});
      slog::Relation* readrel394 = db->getRelation("eval");
      evalindex352 = readrel394->getIndex(ord393, false);
      std::vector<u16> ord395({1, 2, 0});
      slog::Relation* readrel396 = db->getRelation("app");
      appindex353 = readrel396->getIndex(ord395, false);
      std::vector<u16> ord397({1, 3, 0, 2});
      slog::Relation* readrel398 = db->getRelation("$sup27994x83x0x0x0");
      $sup27994x83x0x0x0index354 = readrel398->getIndex(ord397, false);
      std::vector<u16> ord399({1, 3, 0, 2});
      slog::Relation* readrel400 = db->getRelation("$sup27994x83x0x0x0");
      $sup27994x83x0x0x0delta372 = readrel400->getIndex(ord399, true);
      std::vector<u16> ord401({1, 2, 0});
      slog::Relation* readrel402 = db->getRelation("eval");
      evalindex355 = readrel402->getIndex(ord401, false);
      std::vector<u16> ord403({0, 2, 1});
      slog::Relation* readrel404 = db->getRelation("eval");
      evalindex356 = readrel404->getIndex(ord403, false);
      std::vector<u16> ord405({1, 2, 0});
      slog::Relation* readrel406 = db->getRelation("app");
      appindex357 = readrel406->getIndex(ord405, false);
      std::vector<u16> ord407({5, 7, 0, 3, 1, 2, 4, 6, 8, 9});
      slog::Relation* readrel408 = db->getRelation("$sup27994x83x0x0x1");
      $sup27994x83x0x0x1index358 = readrel408->getIndex(ord407, false);
      std::vector<u16> ord409({5, 7, 0, 3, 1, 2, 4, 6, 8, 9});
      slog::Relation* readrel410 = db->getRelation("$sup27994x83x0x0x1");
      $sup27994x83x0x0x1delta373 = readrel410->getIndex(ord409, true);
      std::vector<u16> ord411({0, 2, 1});
      slog::Relation* readrel412 = db->getRelation("eval");
      evalindex359 = readrel412->getIndex(ord411, false);
      std::vector<u16> ord413({0, 2, 1});
      slog::Relation* readrel414 = db->getRelation("eval");
      evaldelta374 = readrel414->getIndex(ord413, true);
      std::vector<u16> ord415({0, 1});
      slog::Relation* readrel416 = db->getRelation("eval_ans");
      eval_ansindex360 = readrel416->getIndex(ord415, false);
      std::vector<u16> ord417({0, 1});
      slog::Relation* readrel418 = db->getRelation("eval_ans");
      eval_ansdelta375 = readrel418->getIndex(ord417, true);
      std::vector<u16> ord419({1, 2, 0});
      slog::Relation* readrel420 = db->getRelation("lambda");
      lambdaindex361 = readrel420->getIndex(ord419, false);
      std::vector<u16> ord421({0, 2, 1});
      slog::Relation* readrel422 = db->getRelation("clo");
      cloindex362 = readrel422->getIndex(ord421, false);
      std::vector<u16> ord423({1, 2, 0});
      slog::Relation* readrel424 = db->getRelation("eval");
      evalindex363 = readrel424->getIndex(ord423, false);
      std::vector<u16> ord425({0, 2, 1});
      slog::Relation* readrel426 = db->getRelation("eval");
      evalindex364 = readrel426->getIndex(ord425, false);
      std::vector<u16> ord427({0, 2, 1});
      slog::Relation* readrel428 = db->getRelation("eval");
      evaldelta376 = readrel428->getIndex(ord427, true);
      std::vector<u16> ord429({0, 1, 2});
      slog::Relation* readrel430 = db->getRelation("app");
      appindex365 = readrel430->getIndex(ord429, false);
      std::vector<u16> ord431({0, 1, 2});
      slog::Relation* readrel432 = db->getRelation("app");
      appdelta377 = readrel432->getIndex(ord431, true);
      std::vector<u16> ord433({1, 2, 0});
      slog::Relation* readrel434 = db->getRelation("eval");
      evalindex366 = readrel434->getIndex(ord433, false);
      std::vector<u16> ord435({1, 2, 0});
      slog::Relation* readrel436 = db->getRelation("lambda");
      lambdaindex367 = readrel436->getIndex(ord435, false);
      std::vector<u16> ord437({1, 2, 0});
      slog::Relation* readrel438 = db->getRelation("lambda");
      lambdadelta378 = readrel438->getIndex(ord437, true);
      std::vector<u16> ord439({0, 2, 1});
      slog::Relation* readrel440 = db->getRelation("clo");
      cloindex368 = readrel440->getIndex(ord439, false);
      std::vector<u16> ord441({0, 2, 1});
      slog::Relation* readrel442 = db->getRelation("clo");
      clodelta379 = readrel442->getIndex(ord441, true);
      std::vector<u16> ord443({1, 2, 0});
      slog::Relation* readrel444 = db->getRelation("eval");
      evalindex369 = readrel444->getIndex(ord443, false);
      std::vector<u16> ord445({1, 2, 0});
      slog::Relation* readrel446 = db->getRelation("eval");
      evaldelta380 = readrel446->getIndex(ord445, true);
      std::vector<u16> ord447({0, 1});
      slog::Relation* readrel448 = db->getRelation("eval_ans");
      eval_ansindex370 = readrel448->getIndex(ord447, false);
      std::vector<u16> ord449({0, 1});
      slog::Relation* readrel450 = db->getRelation("eval_ans");
      eval_ansdelta381 = readrel450->getIndex(ord449, true);
  
    }
    ReadTask382(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c68 = _t[0];
        u64 v_c69 = _t[1];
        if (!slog::exists_probe<10,1>($sup27994x83x0x0x1index349, std::array<u64,10>{v_c68, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(evalindex350, evaldelta371, std::array<u64,3>{v_c68, 0, 0}, [&](const std::array<u64,3>& m451) {
          u64 v_c21 = m451[1]; u64 v_c19 = m451[2];
          if (!slog::exists_probe<10,3>($sup27994x83x0x0x1index351, std::array<u64,10>{v_c68, v_c21, v_c19, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(evalindex352, std::array<u64,3>{v_c21, 0, 0})) return;
          if (!slog::exists_probe<3,1>(appindex353, std::array<u64,3>{v_c19, 0, 0})) return;
          slog::join_probe_old<4,2>($sup27994x83x0x0x0index354, $sup27994x83x0x0x0delta372, std::array<u64,4>{v_c21, v_c19, 0, 0}, [&](const std::array<u64,4>& m452) {
            u64 v_c70 = m452[2]; u64 v_c20 = m452[3];
            if (!slog::exists_probe<3,2>(evalindex355, std::array<u64,3>{v_c20, v_c21, 0})) return;
            if (!slog::exists_probe<3,2>(evalindex356, std::array<u64,3>{v_c70, v_c21, 0})) return;
            if (!slog::exists_probe<3,2>(appindex357, std::array<u64,3>{v_c19, v_c20, 0})) return;
            slog::join_probe_old<10,5>($sup27994x83x0x0x1index358, $sup27994x83x0x0x1delta373, std::array<u64,10>{v_c20, v_c19, v_c70, v_c21, v_c68, 0, 0, 0, 0, 0}, [&](const std::array<u64,10>& m453) {
              u64 v_c71 = m453[5]; u64 v_c27 = m453[6]; u64 v_c32 = m453[7]; u64 v_c26 = m453[8]; u64 v_c31 = m453[9];
              slog::join_probe_old<3,3>(evalindex359, evaldelta374, std::array<u64,3>{v_c71, v_c21, v_c20}, [&](const std::array<u64,3>& m454) {
                slog::join_probe_old<2,2>(eval_ansindex360, eval_ansdelta375, std::array<u64,2>{v_c71, v_c26}, [&](const std::array<u64,2>& m455) {
                  if (!slog::exists_probe<3,2>(lambdaindex361, std::array<u64,3>{v_c31, v_c32, 0})) return;
                  if (!slog::exists_probe<3,2>(cloindex362, std::array<u64,3>{v_c69, v_c27, 0})) return;
                  if (!slog::exists_probe<3,1>(evalindex363, std::array<u64,3>{v_c32, 0, 0})) return;
                  slog::join_probe_old<3,2>(evalindex364, evaldelta376, std::array<u64,3>{v_c70, v_c21, 0}, [&](const std::array<u64,3>& m456) {
                    u64 v_c72 = m456[2];
                    slog::join_probe_old<3,3>(appindex365, appdelta377, std::array<u64,3>{v_c72, v_c19, v_c20}, [&](const std::array<u64,3>& m457) {
                      if (!slog::exists_probe<3,2>(evalindex366, std::array<u64,3>{v_c32, v_c72, 0})) return;
                      slog::join_probe_old<3,2>(lambdaindex367, lambdadelta378, std::array<u64,3>{v_c31, v_c32, 0}, [&](const std::array<u64,3>& m458) {
                        u64 v_c73 = m458[2];
                        slog::join_probe_old<3,3>(cloindex368, clodelta379, std::array<u64,3>{v_c69, v_c27, v_c73}, [&](const std::array<u64,3>& m459) {
                          slog::join_probe_old<3,2>(evalindex369, evaldelta380, std::array<u64,3>{v_c32, v_c72, 0}, [&](const std::array<u64,3>& m460) {
                            u64 v_c74 = m460[2];
                            slog::join_probe_old<2,1>(eval_ansindex370, eval_ansdelta381, std::array<u64,2>{v_c74, 0}, [&](const std::array<u64,2>& m461) {
                              u64 v_c75 = m461[1];
                              ++_fires;
                              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c70, v_c75}, std::array<u16,2>{0, 1});
                            });
                          });
                        });
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
  
      if (_fires) db->bumpFires("mcfa-counting.slog:84", "delta:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask382* _cont = new ReadTask382(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask382(db,b), false);
  // (crule (pre) (scan eval_ans __t6CRg170 __t2Hqj172) (body (join-old eval (0 2 1) 1 (0 2 1) __t6CRg170 c ef) (exists app (1 2 0) 1 ef) (exists eval (2 0 1) 1 c) (join eval (2 0 1) 1 c __6tlE337 __t5SBy169) (join-old app (0 1 2) 2 (0 1 2) __t5SBy169 ef ea) (join-old eval (1 2 0) 2 (1 2 0) ea c __t1JPZ173) (join-old eval_ans (0 1) 1 (0 1) __t1JPZ173 va) (join-old clo (0 2 1) 1 (0 2 1) __t2Hqj172 cb __t0RD6171) (join-old lambda (0 1 2) 1 (0 1 2) __t0RD6171 x eb)) (head (emit store (0 1 2) x __t5SBy169 va) (emit callev (0 1) __t5SBy169 c) (emit bindev (0 1 2) x __t5SBy169 c)) mcfa-counting.slog:92 #f)
  class ReadTask477 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex462;  slog::Index** appindex463;  slog::Index** evalindex464;  slog::Index** evalindex465;  slog::Index** appindex466;  slog::Index** evalindex467;  slog::Index** eval_ansindex468;  slog::Index** cloindex469;  slog::Index** lambdaindex470;  slog::Index** evaldelta471;  slog::Index** appdelta472;  slog::Index** evaldelta473;  slog::Index** eval_ansdelta474;  slog::Index** clodelta475;  slog::Index** lambdadelta476;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("store");
      std::vector<u16> ord478({0, 1, 2});
      slog::Relation* readrel479 = db->getRelation("store");
      head_index[0] = readrel479->getIndex(ord478, false);
      head_rel[1] = db->getRelation("callev");
      std::vector<u16> ord480({0, 1});
      slog::Relation* readrel481 = db->getRelation("callev");
      head_index[1] = readrel481->getIndex(ord480, false);
      head_rel[2] = db->getRelation("bindev");
      std::vector<u16> ord482({0, 1, 2});
      slog::Relation* readrel483 = db->getRelation("bindev");
      head_index[2] = readrel483->getIndex(ord482, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord484({0, 2, 1});
      slog::Relation* readrel485 = db->getRelation("eval");
      evalindex462 = readrel485->getIndex(ord484, false);
      std::vector<u16> ord486({0, 2, 1});
      slog::Relation* readrel487 = db->getRelation("eval");
      evaldelta471 = readrel487->getIndex(ord486, true);
      std::vector<u16> ord488({1, 2, 0});
      slog::Relation* readrel489 = db->getRelation("app");
      appindex463 = readrel489->getIndex(ord488, false);
      std::vector<u16> ord490({2, 0, 1});
      slog::Relation* readrel491 = db->getRelation("eval");
      evalindex464 = readrel491->getIndex(ord490, false);
      std::vector<u16> ord492({2, 0, 1});
      slog::Relation* readrel493 = db->getRelation("eval");
      evalindex465 = readrel493->getIndex(ord492, false);
      std::vector<u16> ord494({0, 1, 2});
      slog::Relation* readrel495 = db->getRelation("app");
      appindex466 = readrel495->getIndex(ord494, false);
      std::vector<u16> ord496({0, 1, 2});
      slog::Relation* readrel497 = db->getRelation("app");
      appdelta472 = readrel497->getIndex(ord496, true);
      std::vector<u16> ord498({1, 2, 0});
      slog::Relation* readrel499 = db->getRelation("eval");
      evalindex467 = readrel499->getIndex(ord498, false);
      std::vector<u16> ord500({1, 2, 0});
      slog::Relation* readrel501 = db->getRelation("eval");
      evaldelta473 = readrel501->getIndex(ord500, true);
      std::vector<u16> ord502({0, 1});
      slog::Relation* readrel503 = db->getRelation("eval_ans");
      eval_ansindex468 = readrel503->getIndex(ord502, false);
      std::vector<u16> ord504({0, 1});
      slog::Relation* readrel505 = db->getRelation("eval_ans");
      eval_ansdelta474 = readrel505->getIndex(ord504, true);
      std::vector<u16> ord506({0, 2, 1});
      slog::Relation* readrel507 = db->getRelation("clo");
      cloindex469 = readrel507->getIndex(ord506, false);
      std::vector<u16> ord508({0, 2, 1});
      slog::Relation* readrel509 = db->getRelation("clo");
      clodelta475 = readrel509->getIndex(ord508, true);
      std::vector<u16> ord510({0, 1, 2});
      slog::Relation* readrel511 = db->getRelation("lambda");
      lambdaindex470 = readrel511->getIndex(ord510, false);
      std::vector<u16> ord512({0, 1, 2});
      slog::Relation* readrel513 = db->getRelation("lambda");
      lambdadelta476 = readrel513->getIndex(ord512, true);
  
    }
    ReadTask477(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c76 = _t[0];
        u64 v_c77 = _t[1];
        slog::join_probe_old<3,1>(evalindex462, evaldelta471, std::array<u64,3>{v_c76, 0, 0}, [&](const std::array<u64,3>& m514) {
          u64 v_c21 = m514[1]; u64 v_c19 = m514[2];
          if (!slog::exists_probe<3,1>(appindex463, std::array<u64,3>{v_c19, 0, 0})) return;
          if (!slog::exists_probe<3,1>(evalindex464, std::array<u64,3>{v_c21, 0, 0})) return;
          slog::join_probe<3,1>(evalindex465, std::array<u64,3>{v_c21, 0, 0}, [&](const std::array<u64,3>& m515) {
            u64 v_c78 = m515[1]; u64 v_c79 = m515[2];
            slog::join_probe_old<3,2>(appindex466, appdelta472, std::array<u64,3>{v_c79, v_c19, 0}, [&](const std::array<u64,3>& m516) {
              u64 v_c20 = m516[2];
              slog::join_probe_old<3,2>(evalindex467, evaldelta473, std::array<u64,3>{v_c20, v_c21, 0}, [&](const std::array<u64,3>& m517) {
                u64 v_c80 = m517[2];
                slog::join_probe_old<2,1>(eval_ansindex468, eval_ansdelta474, std::array<u64,2>{v_c80, 0}, [&](const std::array<u64,2>& m518) {
                  u64 v_c26 = m518[1];
                  slog::join_probe_old<3,1>(cloindex469, clodelta475, std::array<u64,3>{v_c77, 0, 0}, [&](const std::array<u64,3>& m519) {
                    u64 v_c27 = m519[1]; u64 v_c81 = m519[2];
                    slog::join_probe_old<3,1>(lambdaindex470, lambdadelta476, std::array<u64,3>{v_c81, 0, 0}, [&](const std::array<u64,3>& m520) {
                      u64 v_c31 = m520[1]; u64 v_c32 = m520[2];
                      ++_fires;
                      slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c31, v_c79, v_c26}, std::array<u16,3>{0, 1, 2});
                      slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c79, v_c21}, std::array<u16,2>{0, 1});
                      slog::emit<3>(head_rel[2], head_index[2], newbatch[2], std::array<u64,3>{v_c31, v_c79, v_c21}, std::array<u16,3>{0, 1, 2});
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
        ReadTask477* _cont = new ReadTask477(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask477(db,b), false);
  // (crule (pre (let __tconst2ady176 constc40f204dda7ba4054abb9e74) (let __tconst7JVW192 const6cf13cc59dcbe759113f68a4) (let __tconst5wC2180 const970c20ea81b833e5b5a7accf) (let __tconst7B9N190 constcaa3ee5a2828a31924f6b39d)) (scan app __t3W4r195 __t5jf3194 __t1Ls4177) (body (exists ref (1 0) 1 __tconst2ady176) (exists ref (1 0) 1 __tconst5wC2180) (exists lambda (1 2 0) 1 __tconst5wC2180) (exists lambda (1 2 0) 1 __tconst7JVW192) (exists lambda (1 2 0) 1 __tconst7B9N190) (exists ref (1 0) 1 __tconst7JVW192) (exists ref (1 0) 1 __tconst7B9N190) (join lambda (0 1 2) 2 __t1Ls4177 __tconst2ady176 __t3ZY4175) (join ref (0 1) 2 __t3ZY4175 __tconst2ady176) (join ref (1 0) 1 __tconst5wC2180 __t52sB179) (join lambda (1 2 0) 2 __tconst5wC2180 __t52sB179 __t6CST181) (join app (2 0 1) 2 __t6CST181 __t5jf3194 __t6Vw9193) (join lambda (0 1 2) 2 __t6Vw9193 __tconst7JVW192 __t6W4v191) (join lambda (0 1 2) 2 __t6W4v191 __tconst7B9N190 __t9pbS189) (join ref (1 0) 1 __tconst7JVW192 __t6fOY185) (exists app (1 2 0) 1 __t6fOY185) (join app (0 1 2) 2 __t9pbS189 __t6fOY185 __t2CTd186) (join app (0 1 2) 2 __t2CTd186 __t6fOY185 __t8oRJ183) (join ref (0 1) 2 __t8oRJ183 __tconst7B9N190)) (head (emit program (0) __t3W4r195)) mcfa-counting.slog:301 #f)
  class ReadTask540 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex521;  slog::Index** refindex522;  slog::Index** lambdaindex523;  slog::Index** lambdaindex524;  slog::Index** lambdaindex525;  slog::Index** refindex526;  slog::Index** refindex527;  slog::Index** lambdaindex528;  slog::Index** refindex529;  slog::Index** refindex530;  slog::Index** lambdaindex531;  slog::Index** appindex532;  slog::Index** lambdaindex533;  slog::Index** lambdaindex534;  slog::Index** refindex535;  slog::Index** appindex536;  slog::Index** appindex537;  slog::Index** appindex538;  slog::Index** refindex539;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("program");
      std::vector<u16> ord541({0});
      slog::Relation* readrel542 = db->getRelation("program");
      head_index[0] = readrel542->getIndex(ord541, false);
      outer_rel = db->getRelation("app");
      std::vector<u16> ord543({1, 0});
      slog::Relation* readrel544 = db->getRelation("ref");
      refindex521 = readrel544->getIndex(ord543, false);
      std::vector<u16> ord545({1, 0});
      slog::Relation* readrel546 = db->getRelation("ref");
      refindex522 = readrel546->getIndex(ord545, false);
      std::vector<u16> ord547({1, 2, 0});
      slog::Relation* readrel548 = db->getRelation("lambda");
      lambdaindex523 = readrel548->getIndex(ord547, false);
      std::vector<u16> ord549({1, 2, 0});
      slog::Relation* readrel550 = db->getRelation("lambda");
      lambdaindex524 = readrel550->getIndex(ord549, false);
      std::vector<u16> ord551({1, 2, 0});
      slog::Relation* readrel552 = db->getRelation("lambda");
      lambdaindex525 = readrel552->getIndex(ord551, false);
      std::vector<u16> ord553({1, 0});
      slog::Relation* readrel554 = db->getRelation("ref");
      refindex526 = readrel554->getIndex(ord553, false);
      std::vector<u16> ord555({1, 0});
      slog::Relation* readrel556 = db->getRelation("ref");
      refindex527 = readrel556->getIndex(ord555, false);
      std::vector<u16> ord557({0, 1, 2});
      slog::Relation* readrel558 = db->getRelation("lambda");
      lambdaindex528 = readrel558->getIndex(ord557, false);
      std::vector<u16> ord559({0, 1});
      slog::Relation* readrel560 = db->getRelation("ref");
      refindex529 = readrel560->getIndex(ord559, false);
      std::vector<u16> ord561({1, 0});
      slog::Relation* readrel562 = db->getRelation("ref");
      refindex530 = readrel562->getIndex(ord561, false);
      std::vector<u16> ord563({1, 2, 0});
      slog::Relation* readrel564 = db->getRelation("lambda");
      lambdaindex531 = readrel564->getIndex(ord563, false);
      std::vector<u16> ord565({2, 0, 1});
      slog::Relation* readrel566 = db->getRelation("app");
      appindex532 = readrel566->getIndex(ord565, false);
      std::vector<u16> ord567({0, 1, 2});
      slog::Relation* readrel568 = db->getRelation("lambda");
      lambdaindex533 = readrel568->getIndex(ord567, false);
      std::vector<u16> ord569({0, 1, 2});
      slog::Relation* readrel570 = db->getRelation("lambda");
      lambdaindex534 = readrel570->getIndex(ord569, false);
      std::vector<u16> ord571({1, 0});
      slog::Relation* readrel572 = db->getRelation("ref");
      refindex535 = readrel572->getIndex(ord571, false);
      std::vector<u16> ord573({1, 2, 0});
      slog::Relation* readrel574 = db->getRelation("app");
      appindex536 = readrel574->getIndex(ord573, false);
      std::vector<u16> ord575({0, 1, 2});
      slog::Relation* readrel576 = db->getRelation("app");
      appindex537 = readrel576->getIndex(ord575, false);
      std::vector<u16> ord577({0, 1, 2});
      slog::Relation* readrel578 = db->getRelation("app");
      appindex538 = readrel578->getIndex(ord577, false);
      std::vector<u16> ord579({0, 1});
      slog::Relation* readrel580 = db->getRelation("ref");
      refindex539 = readrel580->getIndex(ord579, false);
  
    }
    ReadTask540(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c82 = v_constc40f204dda7ba4054abb9e74;
      u64 v_c83 = v_const6cf13cc59dcbe759113f68a4;
      u64 v_c84 = v_const970c20ea81b833e5b5a7accf;
      u64 v_c85 = v_constcaa3ee5a2828a31924f6b39d;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c86 = _t[0];
        u64 v_c87 = _t[1];
        u64 v_c88 = _t[2];
        if (!slog::exists_probe<2,1>(refindex521, std::array<u64,2>{v_c82, 0})) return;
        if (!slog::exists_probe<2,1>(refindex522, std::array<u64,2>{v_c84, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex523, std::array<u64,3>{v_c84, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex524, std::array<u64,3>{v_c83, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex525, std::array<u64,3>{v_c85, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex526, std::array<u64,2>{v_c83, 0})) return;
        if (!slog::exists_probe<2,1>(refindex527, std::array<u64,2>{v_c85, 0})) return;
        slog::join_probe<3,2>(lambdaindex528, std::array<u64,3>{v_c88, v_c82, 0}, [&](const std::array<u64,3>& m581) {
          u64 v_c89 = m581[2];
          slog::join_probe<2,2>(refindex529, std::array<u64,2>{v_c89, v_c82}, [&](const std::array<u64,2>& m582) {
            slog::join_probe<2,1>(refindex530, std::array<u64,2>{v_c84, 0}, [&](const std::array<u64,2>& m583) {
              u64 v_c90 = m583[1];
              slog::join_probe<3,2>(lambdaindex531, std::array<u64,3>{v_c84, v_c90, 0}, [&](const std::array<u64,3>& m584) {
                u64 v_c91 = m584[2];
                slog::join_probe<3,2>(appindex532, std::array<u64,3>{v_c91, v_c87, 0}, [&](const std::array<u64,3>& m585) {
                  u64 v_c92 = m585[2];
                  slog::join_probe<3,2>(lambdaindex533, std::array<u64,3>{v_c92, v_c83, 0}, [&](const std::array<u64,3>& m586) {
                    u64 v_c93 = m586[2];
                    slog::join_probe<3,2>(lambdaindex534, std::array<u64,3>{v_c93, v_c85, 0}, [&](const std::array<u64,3>& m587) {
                      u64 v_c94 = m587[2];
                      slog::join_probe<2,1>(refindex535, std::array<u64,2>{v_c83, 0}, [&](const std::array<u64,2>& m588) {
                        u64 v_c95 = m588[1];
                        if (!slog::exists_probe<3,1>(appindex536, std::array<u64,3>{v_c95, 0, 0})) return;
                        slog::join_probe<3,2>(appindex537, std::array<u64,3>{v_c94, v_c95, 0}, [&](const std::array<u64,3>& m589) {
                          u64 v_c96 = m589[2];
                          slog::join_probe<3,2>(appindex538, std::array<u64,3>{v_c96, v_c95, 0}, [&](const std::array<u64,3>& m590) {
                            u64 v_c97 = m590[2];
                            slog::join_probe<2,2>(refindex539, std::array<u64,2>{v_c97, v_c85}, [&](const std::array<u64,2>& m591) {
                              ++_fires;
                              slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c86}, std::array<u16,1>{0});
                            });
                          });
                        });
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
  
      if (_fires) db->bumpFires("mcfa-counting.slog:301", "delta:app", _fires);
  
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
  // (crule (pre) (scan eval __9gNV361 __t0neE161 c) (body (join-old app (0 1 2) 1 (0 1 2) __t0neE161 ef ea) (join freevar (0 1) 0 y __t3DWB162) (join store (0 1 2) 1 y cb vy) (join lambda (0 1 2) 1 __t3DWB162 x eb)) (head (mkstruct eval (1 2 0) __1Zia362 ef c)) mcfa-counting.slog:102 #f)
  class ReadTask597 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex592;  slog::Index** freevarindex593;  slog::Index** storeindex594;  slog::Index** lambdaindex595;  slog::Index** appdelta596;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord598({0, 1, 2});
      slog::Relation* readrel599 = db->getRelation("app");
      appindex592 = readrel599->getIndex(ord598, false);
      std::vector<u16> ord600({0, 1, 2});
      slog::Relation* readrel601 = db->getRelation("app");
      appdelta596 = readrel601->getIndex(ord600, true);
      std::vector<u16> ord602({0, 1});
      slog::Relation* readrel603 = db->getRelation("freevar");
      freevarindex593 = readrel603->getIndex(ord602, false);
      std::vector<u16> ord604({0, 1, 2});
      slog::Relation* readrel605 = db->getRelation("store");
      storeindex594 = readrel605->getIndex(ord604, false);
      std::vector<u16> ord606({0, 1, 2});
      slog::Relation* readrel607 = db->getRelation("lambda");
      lambdaindex595 = readrel607->getIndex(ord606, false);
  
    }
    ReadTask597(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c21 = _t[2];
        slog::join_probe_old<3,1>(appindex592, appdelta596, std::array<u64,3>{v_c99, 0, 0}, [&](const std::array<u64,3>& m608) {
          u64 v_c19 = m608[1]; u64 v_c20 = m608[2];
          slog::join_all<2>(freevarindex593, [&](const std::array<u64,2>& m609) {
            u64 v_c29 = m609[0]; u64 v_c100 = m609[1];
            slog::join_probe<3,1>(storeindex594, std::array<u64,3>{v_c29, 0, 0}, [&](const std::array<u64,3>& m610) {
              u64 v_c27 = m610[1]; u64 v_c30 = m610[2];
              slog::join_probe<3,1>(lambdaindex595, std::array<u64,3>{v_c100, 0, 0}, [&](const std::array<u64,3>& m611) {
                u64 v_c31 = m611[1]; u64 v_c32 = m611[2];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c19, v_c21}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:102", "delta:eval", _fires);
  
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
  // (crule (pre (let __tconst9zoW125 const7c7d2cfc66f4d976987d2d20) (let __tconst0vRf84 conste58dec6bca6f63ef79c3b755) (let __tconst4V4L122 const6bc0ba365ada70df115e1785) (let __tconst4Zcr91 const9a67f28c6b77e842f439a84a) (let __tconst82U8119 consta8180db1c2f300980314f910) (let __tconst4BKz104 const0f8748be649f8ee4066bb1d7) (let __tconst3wDH116 constd5f017533ea574d5f9b3400c) (let __tconst3ktF111 const990b444cbd47632035b2fa1a) (let __tconst5nWJ102 const4f84f41d89b6b717419b4eaa)) (scan app __t6xIu127 __t4GT8126 __t87vL85) (body (exists ref (1 0) 1 __tconst0vRf84) (exists lambda (0 1 2) 2 __t4GT8126 __tconst9zoW125) (exists ref (1 0) 1 __tconst4Zcr91) (exists ref (1 0) 1 __tconst9zoW125) (exists lambda (1 2 0) 1 __tconst4Zcr91) (exists lambda (1 2 0) 1 __tconst4V4L122) (exists ref (1 0) 1 __tconst4V4L122) (exists ref (1 0) 1 __tconst4BKz104) (exists lambda (1 2 0) 1 __tconst4BKz104) (exists lambda (1 2 0) 1 __tconst82U8119) (exists ref (1 0) 1 __tconst3wDH116) (exists ref (1 0) 1 __tconst5nWJ102) (exists lambda (1 2 0) 1 __tconst5nWJ102) (exists lambda (1 2 0) 1 __tconst3wDH116) (exists lambda (1 2 0) 1 __tconst3ktF111) (exists ref (1 0) 1 __tconst3ktF111) (join lambda (0 1 2) 2 __t87vL85 __tconst0vRf84 __t2duR83) (join ref (0 1) 2 __t2duR83 __tconst0vRf84) (join lambda (0 1 2) 2 __t4GT8126 __tconst9zoW125 __t3cyj124) (join ref (1 0) 1 __tconst4Zcr91 __t0C9F87) (exists app (2 0 1) 1 __t0C9F87) (join ref (1 0) 1 __tconst9zoW125 __t3Q2G89) (join app (1 2 0) 2 __t3Q2G89 __t0C9F87 __t2Eqd90) (join lambda (1 2 0) 2 __tconst4Zcr91 __t2Eqd90 __t3pgm92) (join app (2 0 1) 2 __t3pgm92 __t3cyj124 __t5iMg123) (join lambda (0 1 2) 2 __t5iMg123 __tconst4V4L122 __t1GdP121) (join ref (1 0) 1 __tconst4V4L122 __t7aew98) (exists app (1 2 0) 1 __t7aew98) (join ref (1 0) 1 __tconst4BKz104 __t8C0a94) (join lambda (1 2 0) 2 __tconst4BKz104 __t8C0a94 __t4fDK96) (join app (1 2 0) 2 __t7aew98 __t4fDK96 __t7TEO99) (join app (2 0 1) 2 __t7TEO99 __t1GdP121 __t3SEs120) (join lambda (0 1 2) 2 __t3SEs120 __tconst82U8119 __t50Kk118) (join ref (1 0) 1 __tconst3wDH116 __t3wir114) (exists app (1 2 0) 1 __t3wir114) (join ref (1 0) 1 __tconst5nWJ102 __t5MaG101) (join lambda (1 2 0) 2 __tconst5nWJ102 __t5MaG101 __t35jA103) (join lambda (1 2 0) 2 __tconst4BKz104 __t35jA103 __t6RuY105) (join app (1 2 0) 2 __t7aew98 __t6RuY105 __t2Z7m108) (join app (2 0 1) 2 __t2Z7m108 __t50Kk118 __t7CwH117) (join lambda (0 1 2) 2 __t7CwH117 __tconst3wDH116 __t44OM115) (join app (0 1 2) 2 __t44OM115 __t3wir114 __t8GWA112) (join lambda (0 1 2) 2 __t8GWA112 __tconst3ktF111 __t7ohz110) (join ref (0 1) 2 __t7ohz110 __tconst3ktF111)) (head (emit program (0) __t6xIu127)) mcfa-counting.slog:241 #f)
  class ReadTask656 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex612;  slog::Index** lambdaindex613;  slog::Index** refindex614;  slog::Index** refindex615;  slog::Index** lambdaindex616;  slog::Index** lambdaindex617;  slog::Index** refindex618;  slog::Index** refindex619;  slog::Index** lambdaindex620;  slog::Index** lambdaindex621;  slog::Index** refindex622;  slog::Index** refindex623;  slog::Index** lambdaindex624;  slog::Index** lambdaindex625;  slog::Index** lambdaindex626;  slog::Index** refindex627;  slog::Index** lambdaindex628;  slog::Index** refindex629;  slog::Index** lambdaindex630;  slog::Index** refindex631;  slog::Index** appindex632;  slog::Index** refindex633;  slog::Index** appindex634;  slog::Index** lambdaindex635;  slog::Index** appindex636;  slog::Index** lambdaindex637;  slog::Index** refindex638;  slog::Index** appindex639;  slog::Index** refindex640;  slog::Index** lambdaindex641;  slog::Index** appindex642;  slog::Index** appindex643;  slog::Index** lambdaindex644;  slog::Index** refindex645;  slog::Index** appindex646;  slog::Index** refindex647;  slog::Index** lambdaindex648;  slog::Index** lambdaindex649;  slog::Index** appindex650;  slog::Index** appindex651;  slog::Index** lambdaindex652;  slog::Index** appindex653;  slog::Index** lambdaindex654;  slog::Index** refindex655;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("program");
      std::vector<u16> ord657({0});
      slog::Relation* readrel658 = db->getRelation("program");
      head_index[0] = readrel658->getIndex(ord657, false);
      outer_rel = db->getRelation("app");
      std::vector<u16> ord659({1, 0});
      slog::Relation* readrel660 = db->getRelation("ref");
      refindex612 = readrel660->getIndex(ord659, false);
      std::vector<u16> ord661({0, 1, 2});
      slog::Relation* readrel662 = db->getRelation("lambda");
      lambdaindex613 = readrel662->getIndex(ord661, false);
      std::vector<u16> ord663({1, 0});
      slog::Relation* readrel664 = db->getRelation("ref");
      refindex614 = readrel664->getIndex(ord663, false);
      std::vector<u16> ord665({1, 0});
      slog::Relation* readrel666 = db->getRelation("ref");
      refindex615 = readrel666->getIndex(ord665, false);
      std::vector<u16> ord667({1, 2, 0});
      slog::Relation* readrel668 = db->getRelation("lambda");
      lambdaindex616 = readrel668->getIndex(ord667, false);
      std::vector<u16> ord669({1, 2, 0});
      slog::Relation* readrel670 = db->getRelation("lambda");
      lambdaindex617 = readrel670->getIndex(ord669, false);
      std::vector<u16> ord671({1, 0});
      slog::Relation* readrel672 = db->getRelation("ref");
      refindex618 = readrel672->getIndex(ord671, false);
      std::vector<u16> ord673({1, 0});
      slog::Relation* readrel674 = db->getRelation("ref");
      refindex619 = readrel674->getIndex(ord673, false);
      std::vector<u16> ord675({1, 2, 0});
      slog::Relation* readrel676 = db->getRelation("lambda");
      lambdaindex620 = readrel676->getIndex(ord675, false);
      std::vector<u16> ord677({1, 2, 0});
      slog::Relation* readrel678 = db->getRelation("lambda");
      lambdaindex621 = readrel678->getIndex(ord677, false);
      std::vector<u16> ord679({1, 0});
      slog::Relation* readrel680 = db->getRelation("ref");
      refindex622 = readrel680->getIndex(ord679, false);
      std::vector<u16> ord681({1, 0});
      slog::Relation* readrel682 = db->getRelation("ref");
      refindex623 = readrel682->getIndex(ord681, false);
      std::vector<u16> ord683({1, 2, 0});
      slog::Relation* readrel684 = db->getRelation("lambda");
      lambdaindex624 = readrel684->getIndex(ord683, false);
      std::vector<u16> ord685({1, 2, 0});
      slog::Relation* readrel686 = db->getRelation("lambda");
      lambdaindex625 = readrel686->getIndex(ord685, false);
      std::vector<u16> ord687({1, 2, 0});
      slog::Relation* readrel688 = db->getRelation("lambda");
      lambdaindex626 = readrel688->getIndex(ord687, false);
      std::vector<u16> ord689({1, 0});
      slog::Relation* readrel690 = db->getRelation("ref");
      refindex627 = readrel690->getIndex(ord689, false);
      std::vector<u16> ord691({0, 1, 2});
      slog::Relation* readrel692 = db->getRelation("lambda");
      lambdaindex628 = readrel692->getIndex(ord691, false);
      std::vector<u16> ord693({0, 1});
      slog::Relation* readrel694 = db->getRelation("ref");
      refindex629 = readrel694->getIndex(ord693, false);
      std::vector<u16> ord695({0, 1, 2});
      slog::Relation* readrel696 = db->getRelation("lambda");
      lambdaindex630 = readrel696->getIndex(ord695, false);
      std::vector<u16> ord697({1, 0});
      slog::Relation* readrel698 = db->getRelation("ref");
      refindex631 = readrel698->getIndex(ord697, false);
      std::vector<u16> ord699({2, 0, 1});
      slog::Relation* readrel700 = db->getRelation("app");
      appindex632 = readrel700->getIndex(ord699, false);
      std::vector<u16> ord701({1, 0});
      slog::Relation* readrel702 = db->getRelation("ref");
      refindex633 = readrel702->getIndex(ord701, false);
      std::vector<u16> ord703({1, 2, 0});
      slog::Relation* readrel704 = db->getRelation("app");
      appindex634 = readrel704->getIndex(ord703, false);
      std::vector<u16> ord705({1, 2, 0});
      slog::Relation* readrel706 = db->getRelation("lambda");
      lambdaindex635 = readrel706->getIndex(ord705, false);
      std::vector<u16> ord707({2, 0, 1});
      slog::Relation* readrel708 = db->getRelation("app");
      appindex636 = readrel708->getIndex(ord707, false);
      std::vector<u16> ord709({0, 1, 2});
      slog::Relation* readrel710 = db->getRelation("lambda");
      lambdaindex637 = readrel710->getIndex(ord709, false);
      std::vector<u16> ord711({1, 0});
      slog::Relation* readrel712 = db->getRelation("ref");
      refindex638 = readrel712->getIndex(ord711, false);
      std::vector<u16> ord713({1, 2, 0});
      slog::Relation* readrel714 = db->getRelation("app");
      appindex639 = readrel714->getIndex(ord713, false);
      std::vector<u16> ord715({1, 0});
      slog::Relation* readrel716 = db->getRelation("ref");
      refindex640 = readrel716->getIndex(ord715, false);
      std::vector<u16> ord717({1, 2, 0});
      slog::Relation* readrel718 = db->getRelation("lambda");
      lambdaindex641 = readrel718->getIndex(ord717, false);
      std::vector<u16> ord719({1, 2, 0});
      slog::Relation* readrel720 = db->getRelation("app");
      appindex642 = readrel720->getIndex(ord719, false);
      std::vector<u16> ord721({2, 0, 1});
      slog::Relation* readrel722 = db->getRelation("app");
      appindex643 = readrel722->getIndex(ord721, false);
      std::vector<u16> ord723({0, 1, 2});
      slog::Relation* readrel724 = db->getRelation("lambda");
      lambdaindex644 = readrel724->getIndex(ord723, false);
      std::vector<u16> ord725({1, 0});
      slog::Relation* readrel726 = db->getRelation("ref");
      refindex645 = readrel726->getIndex(ord725, false);
      std::vector<u16> ord727({1, 2, 0});
      slog::Relation* readrel728 = db->getRelation("app");
      appindex646 = readrel728->getIndex(ord727, false);
      std::vector<u16> ord729({1, 0});
      slog::Relation* readrel730 = db->getRelation("ref");
      refindex647 = readrel730->getIndex(ord729, false);
      std::vector<u16> ord731({1, 2, 0});
      slog::Relation* readrel732 = db->getRelation("lambda");
      lambdaindex648 = readrel732->getIndex(ord731, false);
      std::vector<u16> ord733({1, 2, 0});
      slog::Relation* readrel734 = db->getRelation("lambda");
      lambdaindex649 = readrel734->getIndex(ord733, false);
      std::vector<u16> ord735({1, 2, 0});
      slog::Relation* readrel736 = db->getRelation("app");
      appindex650 = readrel736->getIndex(ord735, false);
      std::vector<u16> ord737({2, 0, 1});
      slog::Relation* readrel738 = db->getRelation("app");
      appindex651 = readrel738->getIndex(ord737, false);
      std::vector<u16> ord739({0, 1, 2});
      slog::Relation* readrel740 = db->getRelation("lambda");
      lambdaindex652 = readrel740->getIndex(ord739, false);
      std::vector<u16> ord741({0, 1, 2});
      slog::Relation* readrel742 = db->getRelation("app");
      appindex653 = readrel742->getIndex(ord741, false);
      std::vector<u16> ord743({0, 1, 2});
      slog::Relation* readrel744 = db->getRelation("lambda");
      lambdaindex654 = readrel744->getIndex(ord743, false);
      std::vector<u16> ord745({0, 1});
      slog::Relation* readrel746 = db->getRelation("ref");
      refindex655 = readrel746->getIndex(ord745, false);
  
    }
    ReadTask656(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c101 = v_const7c7d2cfc66f4d976987d2d20;
      u64 v_c102 = v_conste58dec6bca6f63ef79c3b755;
      u64 v_c103 = v_const6bc0ba365ada70df115e1785;
      u64 v_c104 = v_const9a67f28c6b77e842f439a84a;
      u64 v_c105 = v_consta8180db1c2f300980314f910;
      u64 v_c106 = v_const0f8748be649f8ee4066bb1d7;
      u64 v_c107 = v_constd5f017533ea574d5f9b3400c;
      u64 v_c108 = v_const990b444cbd47632035b2fa1a;
      u64 v_c109 = v_const4f84f41d89b6b717419b4eaa;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c110 = _t[0];
        u64 v_c111 = _t[1];
        u64 v_c112 = _t[2];
        if (!slog::exists_probe<2,1>(refindex612, std::array<u64,2>{v_c102, 0})) return;
        if (!slog::exists_probe<3,2>(lambdaindex613, std::array<u64,3>{v_c111, v_c101, 0})) return;
        if (!slog::exists_probe<2,1>(refindex614, std::array<u64,2>{v_c104, 0})) return;
        if (!slog::exists_probe<2,1>(refindex615, std::array<u64,2>{v_c101, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex616, std::array<u64,3>{v_c104, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex617, std::array<u64,3>{v_c103, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex618, std::array<u64,2>{v_c103, 0})) return;
        if (!slog::exists_probe<2,1>(refindex619, std::array<u64,2>{v_c106, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex620, std::array<u64,3>{v_c106, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex621, std::array<u64,3>{v_c105, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex622, std::array<u64,2>{v_c107, 0})) return;
        if (!slog::exists_probe<2,1>(refindex623, std::array<u64,2>{v_c109, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex624, std::array<u64,3>{v_c109, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex625, std::array<u64,3>{v_c107, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex626, std::array<u64,3>{v_c108, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex627, std::array<u64,2>{v_c108, 0})) return;
        slog::join_probe<3,2>(lambdaindex628, std::array<u64,3>{v_c112, v_c102, 0}, [&](const std::array<u64,3>& m747) {
          u64 v_c113 = m747[2];
          slog::join_probe<2,2>(refindex629, std::array<u64,2>{v_c113, v_c102}, [&](const std::array<u64,2>& m748) {
            slog::join_probe<3,2>(lambdaindex630, std::array<u64,3>{v_c111, v_c101, 0}, [&](const std::array<u64,3>& m749) {
              u64 v_c114 = m749[2];
              slog::join_probe<2,1>(refindex631, std::array<u64,2>{v_c104, 0}, [&](const std::array<u64,2>& m750) {
                u64 v_c115 = m750[1];
                if (!slog::exists_probe<3,1>(appindex632, std::array<u64,3>{v_c115, 0, 0})) return;
                slog::join_probe<2,1>(refindex633, std::array<u64,2>{v_c101, 0}, [&](const std::array<u64,2>& m751) {
                  u64 v_c116 = m751[1];
                  slog::join_probe<3,2>(appindex634, std::array<u64,3>{v_c116, v_c115, 0}, [&](const std::array<u64,3>& m752) {
                    u64 v_c117 = m752[2];
                    slog::join_probe<3,2>(lambdaindex635, std::array<u64,3>{v_c104, v_c117, 0}, [&](const std::array<u64,3>& m753) {
                      u64 v_c118 = m753[2];
                      slog::join_probe<3,2>(appindex636, std::array<u64,3>{v_c118, v_c114, 0}, [&](const std::array<u64,3>& m754) {
                        u64 v_c119 = m754[2];
                        slog::join_probe<3,2>(lambdaindex637, std::array<u64,3>{v_c119, v_c103, 0}, [&](const std::array<u64,3>& m755) {
                          u64 v_c120 = m755[2];
                          slog::join_probe<2,1>(refindex638, std::array<u64,2>{v_c103, 0}, [&](const std::array<u64,2>& m756) {
                            u64 v_c121 = m756[1];
                            if (!slog::exists_probe<3,1>(appindex639, std::array<u64,3>{v_c121, 0, 0})) return;
                            slog::join_probe<2,1>(refindex640, std::array<u64,2>{v_c106, 0}, [&](const std::array<u64,2>& m757) {
                              u64 v_c122 = m757[1];
                              slog::join_probe<3,2>(lambdaindex641, std::array<u64,3>{v_c106, v_c122, 0}, [&](const std::array<u64,3>& m758) {
                                u64 v_c123 = m758[2];
                                slog::join_probe<3,2>(appindex642, std::array<u64,3>{v_c121, v_c123, 0}, [&](const std::array<u64,3>& m759) {
                                  u64 v_c124 = m759[2];
                                  slog::join_probe<3,2>(appindex643, std::array<u64,3>{v_c124, v_c120, 0}, [&](const std::array<u64,3>& m760) {
                                    u64 v_c125 = m760[2];
                                    slog::join_probe<3,2>(lambdaindex644, std::array<u64,3>{v_c125, v_c105, 0}, [&](const std::array<u64,3>& m761) {
                                      u64 v_c126 = m761[2];
                                      slog::join_probe<2,1>(refindex645, std::array<u64,2>{v_c107, 0}, [&](const std::array<u64,2>& m762) {
                                        u64 v_c127 = m762[1];
                                        if (!slog::exists_probe<3,1>(appindex646, std::array<u64,3>{v_c127, 0, 0})) return;
                                        slog::join_probe<2,1>(refindex647, std::array<u64,2>{v_c109, 0}, [&](const std::array<u64,2>& m763) {
                                          u64 v_c128 = m763[1];
                                          slog::join_probe<3,2>(lambdaindex648, std::array<u64,3>{v_c109, v_c128, 0}, [&](const std::array<u64,3>& m764) {
                                            u64 v_c129 = m764[2];
                                            slog::join_probe<3,2>(lambdaindex649, std::array<u64,3>{v_c106, v_c129, 0}, [&](const std::array<u64,3>& m765) {
                                              u64 v_c130 = m765[2];
                                              slog::join_probe<3,2>(appindex650, std::array<u64,3>{v_c121, v_c130, 0}, [&](const std::array<u64,3>& m766) {
                                                u64 v_c131 = m766[2];
                                                slog::join_probe<3,2>(appindex651, std::array<u64,3>{v_c131, v_c126, 0}, [&](const std::array<u64,3>& m767) {
                                                  u64 v_c132 = m767[2];
                                                  slog::join_probe<3,2>(lambdaindex652, std::array<u64,3>{v_c132, v_c107, 0}, [&](const std::array<u64,3>& m768) {
                                                    u64 v_c133 = m768[2];
                                                    slog::join_probe<3,2>(appindex653, std::array<u64,3>{v_c133, v_c127, 0}, [&](const std::array<u64,3>& m769) {
                                                      u64 v_c134 = m769[2];
                                                      slog::join_probe<3,2>(lambdaindex654, std::array<u64,3>{v_c134, v_c108, 0}, [&](const std::array<u64,3>& m770) {
                                                        u64 v_c135 = m770[2];
                                                        slog::join_probe<2,2>(refindex655, std::array<u64,2>{v_c135, v_c108}, [&](const std::array<u64,2>& m771) {
                                                          ++_fires;
                                                          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c110}, std::array<u16,1>{0});
                                                        });
                                                      });
                                                    });
                                                  });
                                                });
                                              });
                                            });
                                          });
                                        });
                                      });
                                    });
                                  });
                                });
                              });
                            });
                          });
                        });
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
        ReadTask656* _cont = new ReadTask656(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask656(db,b), false);
  // (crule (pre) (scan lambda __t4I265 x eb) (body (join freevar (1 0) 1 __t4I265 y) (join store (0 1 2) 1 y cb vy) (join-old eval (0 2 1) 0 (0 2 1) __4DdV347 c __t5Yh14) (join-old app (0 1 2) 1 (0 1 2) __t5Yh14 ef ea)) (head (mkstruct eval (1 2 0) __34Tv348 ea c)) mcfa-counting.slog:102 #f)
  class ReadTask778 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** freevarindex772;  slog::Index** storeindex773;  slog::Index** evalindex774;  slog::Index** appindex775;  slog::Index** evaldelta776;  slog::Index** appdelta777;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("lambda");
      std::vector<u16> ord779({1, 0});
      slog::Relation* readrel780 = db->getRelation("freevar");
      freevarindex772 = readrel780->getIndex(ord779, false);
      std::vector<u16> ord781({0, 1, 2});
      slog::Relation* readrel782 = db->getRelation("store");
      storeindex773 = readrel782->getIndex(ord781, false);
      std::vector<u16> ord783({0, 2, 1});
      slog::Relation* readrel784 = db->getRelation("eval");
      evalindex774 = readrel784->getIndex(ord783, false);
      std::vector<u16> ord785({0, 2, 1});
      slog::Relation* readrel786 = db->getRelation("eval");
      evaldelta776 = readrel786->getIndex(ord785, true);
      std::vector<u16> ord787({0, 1, 2});
      slog::Relation* readrel788 = db->getRelation("app");
      appindex775 = readrel788->getIndex(ord787, false);
      std::vector<u16> ord789({0, 1, 2});
      slog::Relation* readrel790 = db->getRelation("app");
      appdelta777 = readrel790->getIndex(ord789, true);
  
    }
    ReadTask778(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c136 = _t[0];
        u64 v_c31 = _t[1];
        u64 v_c32 = _t[2];
        slog::join_probe<2,1>(freevarindex772, std::array<u64,2>{v_c136, 0}, [&](const std::array<u64,2>& m791) {
          u64 v_c29 = m791[1];
          slog::join_probe<3,1>(storeindex773, std::array<u64,3>{v_c29, 0, 0}, [&](const std::array<u64,3>& m792) {
            u64 v_c27 = m792[1]; u64 v_c30 = m792[2];
            slog::join_all_old<3>(evalindex774, evaldelta776, [&](const std::array<u64,3>& m793) {
              u64 v_c137 = m793[0]; u64 v_c21 = m793[1]; u64 v_c138 = m793[2];
              slog::join_probe_old<3,1>(appindex775, appdelta777, std::array<u64,3>{v_c138, 0, 0}, [&](const std::array<u64,3>& m794) {
                u64 v_c19 = m794[1]; u64 v_c20 = m794[2];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c20, v_c21}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:102", "delta:lambda", _fires);
  
      if (!_done)
      {
        ReadTask778* _cont = new ReadTask778(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask778(db,b), false);
  // (crule (pre (let __tconst4Xaz41 const81cb39a72a584ab4f703b7f7) (let __tconst1aIN38 const4d5ce1398140fbe27561181f) (let __tconst4xzG22 constdbf1bdba02122b2adce28528) (let __tconst1ha033 const969c6e56242ce8d0a4346602) (let __tconst37GM26 const85f09fa1913b9daf65957cf7) (let __tconst1HMF17 constd7a1925d249b4768c8a9f2d8)) (seeded) (body (join ref (1 0) 1 __tconst4xzG22 __t2DOE20) (exists ref (1 0) 1 __tconst1HMF17) (exists lambda (1 2 0) 1 __tconst1HMF17) (exists app (1 2 0) 1 __t2DOE20) (exists lambda (1 2 0) 1 __tconst4xzG22) (exists ref (1 0) 1 __tconst37GM26) (exists lambda (1 2 0) 1 __tconst37GM26) (exists ref (1 0) 1 __tconst1ha033) (exists lambda (1 2 0) 1 __tconst1ha033) (exists lambda (1 2 0) 1 __tconst1aIN38) (join ref (1 0) 1 __tconst4Xaz41 __t75SZ29) (exists app (1 2 0) 1 __t75SZ29) (join ref (1 0) 1 __tconst1HMF17 __t7H1u16) (join lambda (1 2 0) 2 __tconst1HMF17 __t7H1u16 __t2wNc18) (join app (1 2 0) 2 __t2DOE20 __t2wNc18 __t3b2k21) (join lambda (1 2 0) 2 __tconst4xzG22 __t3b2k21 __t8Ovw23) (join ref (1 0) 1 __tconst37GM26 __t7U1m25) (join lambda (1 2 0) 2 __tconst37GM26 __t7U1m25 __t5myE27) (join app (1 2 0) 2 __t75SZ29 __t5myE27 __t2Vg230) (join ref (1 0) 1 __tconst1ha033 __t7N9A32) (join lambda (1 2 0) 2 __tconst1ha033 __t7N9A32 __t065j34) (join app (1 2 0) 2 __t75SZ29 __t065j34 __t3pMW37) (join lambda (1 2 0) 2 __tconst1aIN38 __t3pMW37 __t3aRV39)) (head (mkstruct app (1 2 0) __t7P7240 __t3aRV39 __t2Vg230)) mcfa-counting.slog:260 #f)
  class ReadTask818 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex795;  slog::Index** refindex796;  slog::Index** lambdaindex797;  slog::Index** appindex798;  slog::Index** lambdaindex799;  slog::Index** refindex800;  slog::Index** lambdaindex801;  slog::Index** refindex802;  slog::Index** lambdaindex803;  slog::Index** lambdaindex804;  slog::Index** refindex805;  slog::Index** appindex806;  slog::Index** refindex807;  slog::Index** lambdaindex808;  slog::Index** appindex809;  slog::Index** lambdaindex810;  slog::Index** refindex811;  slog::Index** lambdaindex812;  slog::Index** appindex813;  slog::Index** refindex814;  slog::Index** lambdaindex815;  slog::Index** appindex816;  slog::Index** lambdaindex817;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord819({1, 2, 0});
      slog::Relation* readrel820 = db->getRelation("app");
      head_index[0] = readrel820->getIndex(ord819, false);
      std::vector<u16> ord821({1, 0});
      slog::Relation* readrel822 = db->getRelation("ref");
      refindex795 = readrel822->getIndex(ord821, false);
      std::vector<u16> ord823({1, 0});
      slog::Relation* readrel824 = db->getRelation("ref");
      refindex796 = readrel824->getIndex(ord823, false);
      std::vector<u16> ord825({1, 2, 0});
      slog::Relation* readrel826 = db->getRelation("lambda");
      lambdaindex797 = readrel826->getIndex(ord825, false);
      std::vector<u16> ord827({1, 2, 0});
      slog::Relation* readrel828 = db->getRelation("app");
      appindex798 = readrel828->getIndex(ord827, false);
      std::vector<u16> ord829({1, 2, 0});
      slog::Relation* readrel830 = db->getRelation("lambda");
      lambdaindex799 = readrel830->getIndex(ord829, false);
      std::vector<u16> ord831({1, 0});
      slog::Relation* readrel832 = db->getRelation("ref");
      refindex800 = readrel832->getIndex(ord831, false);
      std::vector<u16> ord833({1, 2, 0});
      slog::Relation* readrel834 = db->getRelation("lambda");
      lambdaindex801 = readrel834->getIndex(ord833, false);
      std::vector<u16> ord835({1, 0});
      slog::Relation* readrel836 = db->getRelation("ref");
      refindex802 = readrel836->getIndex(ord835, false);
      std::vector<u16> ord837({1, 2, 0});
      slog::Relation* readrel838 = db->getRelation("lambda");
      lambdaindex803 = readrel838->getIndex(ord837, false);
      std::vector<u16> ord839({1, 2, 0});
      slog::Relation* readrel840 = db->getRelation("lambda");
      lambdaindex804 = readrel840->getIndex(ord839, false);
      std::vector<u16> ord841({1, 0});
      slog::Relation* readrel842 = db->getRelation("ref");
      refindex805 = readrel842->getIndex(ord841, false);
      std::vector<u16> ord843({1, 2, 0});
      slog::Relation* readrel844 = db->getRelation("app");
      appindex806 = readrel844->getIndex(ord843, false);
      std::vector<u16> ord845({1, 0});
      slog::Relation* readrel846 = db->getRelation("ref");
      refindex807 = readrel846->getIndex(ord845, false);
      std::vector<u16> ord847({1, 2, 0});
      slog::Relation* readrel848 = db->getRelation("lambda");
      lambdaindex808 = readrel848->getIndex(ord847, false);
      std::vector<u16> ord849({1, 2, 0});
      slog::Relation* readrel850 = db->getRelation("app");
      appindex809 = readrel850->getIndex(ord849, false);
      std::vector<u16> ord851({1, 2, 0});
      slog::Relation* readrel852 = db->getRelation("lambda");
      lambdaindex810 = readrel852->getIndex(ord851, false);
      std::vector<u16> ord853({1, 0});
      slog::Relation* readrel854 = db->getRelation("ref");
      refindex811 = readrel854->getIndex(ord853, false);
      std::vector<u16> ord855({1, 2, 0});
      slog::Relation* readrel856 = db->getRelation("lambda");
      lambdaindex812 = readrel856->getIndex(ord855, false);
      std::vector<u16> ord857({1, 2, 0});
      slog::Relation* readrel858 = db->getRelation("app");
      appindex813 = readrel858->getIndex(ord857, false);
      std::vector<u16> ord859({1, 0});
      slog::Relation* readrel860 = db->getRelation("ref");
      refindex814 = readrel860->getIndex(ord859, false);
      std::vector<u16> ord861({1, 2, 0});
      slog::Relation* readrel862 = db->getRelation("lambda");
      lambdaindex815 = readrel862->getIndex(ord861, false);
      std::vector<u16> ord863({1, 2, 0});
      slog::Relation* readrel864 = db->getRelation("app");
      appindex816 = readrel864->getIndex(ord863, false);
      std::vector<u16> ord865({1, 2, 0});
      slog::Relation* readrel866 = db->getRelation("lambda");
      lambdaindex817 = readrel866->getIndex(ord865, false);
  
    }
    ReadTask818(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const81cb39a72a584ab4f703b7f7;
      u64 v_c1 = v_const4d5ce1398140fbe27561181f;
      u64 v_c4 = v_constdbf1bdba02122b2adce28528;
      u64 v_c2 = v_const969c6e56242ce8d0a4346602;
      u64 v_c3 = v_const85f09fa1913b9daf65957cf7;
      u64 v_c5 = v_constd7a1925d249b4768c8a9f2d8;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex795, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m867) {
        u64 v_c139 = m867[1];
        if (!slog::exists_probe<2,1>(refindex796, std::array<u64,2>{v_c5, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex797, std::array<u64,3>{v_c5, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex798, std::array<u64,3>{v_c139, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex799, std::array<u64,3>{v_c4, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex800, std::array<u64,2>{v_c3, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex801, std::array<u64,3>{v_c3, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex802, std::array<u64,2>{v_c2, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex803, std::array<u64,3>{v_c2, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex804, std::array<u64,3>{v_c1, 0, 0})) return;
        slog::join_probe<2,1>(refindex805, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m868) {
          u64 v_c140 = m868[1];
          if (!slog::exists_probe<3,1>(appindex806, std::array<u64,3>{v_c140, 0, 0})) return;
          slog::join_probe<2,1>(refindex807, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m869) {
            u64 v_c141 = m869[1];
            slog::join_probe<3,2>(lambdaindex808, std::array<u64,3>{v_c5, v_c141, 0}, [&](const std::array<u64,3>& m870) {
              u64 v_c142 = m870[2];
              slog::join_probe<3,2>(appindex809, std::array<u64,3>{v_c139, v_c142, 0}, [&](const std::array<u64,3>& m871) {
                u64 v_c143 = m871[2];
                slog::join_probe<3,2>(lambdaindex810, std::array<u64,3>{v_c4, v_c143, 0}, [&](const std::array<u64,3>& m872) {
                  u64 v_c144 = m872[2];
                  slog::join_probe<2,1>(refindex811, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m873) {
                    u64 v_c145 = m873[1];
                    slog::join_probe<3,2>(lambdaindex812, std::array<u64,3>{v_c3, v_c145, 0}, [&](const std::array<u64,3>& m874) {
                      u64 v_c146 = m874[2];
                      slog::join_probe<3,2>(appindex813, std::array<u64,3>{v_c140, v_c146, 0}, [&](const std::array<u64,3>& m875) {
                        u64 v_c147 = m875[2];
                        slog::join_probe<2,1>(refindex814, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m876) {
                          u64 v_c148 = m876[1];
                          slog::join_probe<3,2>(lambdaindex815, std::array<u64,3>{v_c2, v_c148, 0}, [&](const std::array<u64,3>& m877) {
                            u64 v_c149 = m877[2];
                            slog::join_probe<3,2>(appindex816, std::array<u64,3>{v_c140, v_c149, 0}, [&](const std::array<u64,3>& m878) {
                              u64 v_c150 = m878[2];
                              slog::join_probe<3,2>(lambdaindex817, std::array<u64,3>{v_c1, v_c150, 0}, [&](const std::array<u64,3>& m879) {
                                u64 v_c151 = m879[2];
                                ++_fires;
                                slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c151, v_c147}, std::array<u16,3>{1, 2, 0});
                              });
                            });
                          });
                        });
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
      s->addTaskSeeded(phase_read, new ReadTask818(db,b));
  // (crule (pre (let __tconst4Sko246 consteb793a6f75d6cfe49d3c2c90) (let __tconst4N2q248 constaaaad65142343c54348db5d0) (let __tconst2x2f244 consta32d5a443def48e6d64c6f4b) (let __tconst7sqz226 const7b8fd91ee9ff10cfbb8066bf) (let __tconst1EUj230 const615ad01b1c532bb6634df115) (let __tconst2VuQ234 const4492fd5fa4baacfebd29f5e5)) (probe lambda (1 2 0) 1 __tconst4Sko246 __t3laZ245 __t7yz1247) (body (exists ref (1 0) 1 __tconst2VuQ234) (exists lambda (1 2 0) 1 __tconst2VuQ234) (exists ref (1 0) 1 __tconst1EUj230) (exists lambda (1 2 0) 1 __tconst1EUj230) (exists ref (1 0) 1 __tconst7sqz226) (exists lambda (1 2 0) 1 __tconst7sqz226) (exists ref (1 0) 1 __tconst2x2f244) (exists ref (1 0) 1 __tconst4N2q248) (exists ref (1 0) 1 __tconst4Sko246) (join lambda (0 1 2) 2 __t3laZ245 __tconst2x2f244 __t5h6K243) (join ref (1 0) 1 __tconst2VuQ234 __t2PLq233) (join lambda (1 2 0) 2 __tconst2VuQ234 __t2PLq233 __t45rU235) (join ref (1 0) 1 __tconst1EUj230 __t3WVP229) (join lambda (1 2 0) 2 __tconst1EUj230 __t3WVP229 __t5ryk231) (join ref (1 0) 1 __tconst7sqz226 __t5APF225) (join lambda (1 2 0) 2 __tconst7sqz226 __t5APF225 __t2BAX227) (join ref (1 0) 1 __tconst2x2f244 __t3pbc237) (join app (2 0 1) 2 __t3pbc237 __t5h6K243 __t4wvK242) (join ref (1 0) 1 __tconst4N2q248 __t6KL4241) (join app (0 1 2) 2 __t4wvK242 __t6KL4241 __t16jv239) (join ref (0 1) 2 __t16jv239 __tconst4Sko246)) (head (mkstruct lambda (1 2 0) __t5uyC249 __tconst4N2q248 __t7yz1247)) mcfa-counting.slog:272 #f)
  class ReadTask901 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** refindex880;  slog::Index** lambdaindex881;  slog::Index** refindex882;  slog::Index** lambdaindex883;  slog::Index** refindex884;  slog::Index** lambdaindex885;  slog::Index** refindex886;  slog::Index** refindex887;  slog::Index** refindex888;  slog::Index** lambdaindex889;  slog::Index** refindex890;  slog::Index** lambdaindex891;  slog::Index** refindex892;  slog::Index** lambdaindex893;  slog::Index** refindex894;  slog::Index** lambdaindex895;  slog::Index** refindex896;  slog::Index** appindex897;  slog::Index** refindex898;  slog::Index** appindex899;  slog::Index** refindex900;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      std::vector<u16> ord902({1, 2, 0});
      slog::Relation* readrel903 = db->getRelation("lambda");
      driver_index = readrel903->getIndex(ord902, true);
      std::vector<u16> ord904({1, 0});
      slog::Relation* readrel905 = db->getRelation("ref");
      refindex880 = readrel905->getIndex(ord904, false);
      std::vector<u16> ord906({1, 2, 0});
      slog::Relation* readrel907 = db->getRelation("lambda");
      lambdaindex881 = readrel907->getIndex(ord906, false);
      std::vector<u16> ord908({1, 0});
      slog::Relation* readrel909 = db->getRelation("ref");
      refindex882 = readrel909->getIndex(ord908, false);
      std::vector<u16> ord910({1, 2, 0});
      slog::Relation* readrel911 = db->getRelation("lambda");
      lambdaindex883 = readrel911->getIndex(ord910, false);
      std::vector<u16> ord912({1, 0});
      slog::Relation* readrel913 = db->getRelation("ref");
      refindex884 = readrel913->getIndex(ord912, false);
      std::vector<u16> ord914({1, 2, 0});
      slog::Relation* readrel915 = db->getRelation("lambda");
      lambdaindex885 = readrel915->getIndex(ord914, false);
      std::vector<u16> ord916({1, 0});
      slog::Relation* readrel917 = db->getRelation("ref");
      refindex886 = readrel917->getIndex(ord916, false);
      std::vector<u16> ord918({1, 0});
      slog::Relation* readrel919 = db->getRelation("ref");
      refindex887 = readrel919->getIndex(ord918, false);
      std::vector<u16> ord920({1, 0});
      slog::Relation* readrel921 = db->getRelation("ref");
      refindex888 = readrel921->getIndex(ord920, false);
      std::vector<u16> ord922({0, 1, 2});
      slog::Relation* readrel923 = db->getRelation("lambda");
      lambdaindex889 = readrel923->getIndex(ord922, false);
      std::vector<u16> ord924({1, 0});
      slog::Relation* readrel925 = db->getRelation("ref");
      refindex890 = readrel925->getIndex(ord924, false);
      std::vector<u16> ord926({1, 2, 0});
      slog::Relation* readrel927 = db->getRelation("lambda");
      lambdaindex891 = readrel927->getIndex(ord926, false);
      std::vector<u16> ord928({1, 0});
      slog::Relation* readrel929 = db->getRelation("ref");
      refindex892 = readrel929->getIndex(ord928, false);
      std::vector<u16> ord930({1, 2, 0});
      slog::Relation* readrel931 = db->getRelation("lambda");
      lambdaindex893 = readrel931->getIndex(ord930, false);
      std::vector<u16> ord932({1, 0});
      slog::Relation* readrel933 = db->getRelation("ref");
      refindex894 = readrel933->getIndex(ord932, false);
      std::vector<u16> ord934({1, 2, 0});
      slog::Relation* readrel935 = db->getRelation("lambda");
      lambdaindex895 = readrel935->getIndex(ord934, false);
      std::vector<u16> ord936({1, 0});
      slog::Relation* readrel937 = db->getRelation("ref");
      refindex896 = readrel937->getIndex(ord936, false);
      std::vector<u16> ord938({2, 0, 1});
      slog::Relation* readrel939 = db->getRelation("app");
      appindex897 = readrel939->getIndex(ord938, false);
      std::vector<u16> ord940({1, 0});
      slog::Relation* readrel941 = db->getRelation("ref");
      refindex898 = readrel941->getIndex(ord940, false);
      std::vector<u16> ord942({0, 1, 2});
      slog::Relation* readrel943 = db->getRelation("app");
      appindex899 = readrel943->getIndex(ord942, false);
      std::vector<u16> ord944({0, 1});
      slog::Relation* readrel945 = db->getRelation("ref");
      refindex900 = readrel945->getIndex(ord944, false);
  
    }
    ReadTask901(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c10 = v_consteb793a6f75d6cfe49d3c2c90;
      u64 v_c11 = v_constaaaad65142343c54348db5d0;
      u64 v_c9 = v_consta32d5a443def48e6d64c6f4b;
      u64 v_c6 = v_const7b8fd91ee9ff10cfbb8066bf;
      u64 v_c7 = v_const615ad01b1c532bb6634df115;
      u64 v_c8 = v_const4492fd5fa4baacfebd29f5e5;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c10, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m946) {
        u64 v_c152 = m946[1];
        u64 v_c153 = m946[2];
        if (buckethash(v_c152) != bucket) return;
        if (!slog::exists_probe<2,1>(refindex880, std::array<u64,2>{v_c8, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex881, std::array<u64,3>{v_c8, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex882, std::array<u64,2>{v_c7, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex883, std::array<u64,3>{v_c7, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex884, std::array<u64,2>{v_c6, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex885, std::array<u64,3>{v_c6, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex886, std::array<u64,2>{v_c9, 0})) return;
        if (!slog::exists_probe<2,1>(refindex887, std::array<u64,2>{v_c11, 0})) return;
        if (!slog::exists_probe<2,1>(refindex888, std::array<u64,2>{v_c10, 0})) return;
        slog::join_probe<3,2>(lambdaindex889, std::array<u64,3>{v_c152, v_c9, 0}, [&](const std::array<u64,3>& m947) {
          u64 v_c64 = m947[2];
          slog::join_probe<2,1>(refindex890, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m948) {
            u64 v_c15 = m948[1];
            slog::join_probe<3,2>(lambdaindex891, std::array<u64,3>{v_c8, v_c15, 0}, [&](const std::array<u64,3>& m949) {
              u64 v_c65 = m949[2];
              slog::join_probe<2,1>(refindex892, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m950) {
                u64 v_c16 = m950[1];
                slog::join_probe<3,2>(lambdaindex893, std::array<u64,3>{v_c7, v_c16, 0}, [&](const std::array<u64,3>& m951) {
                  u64 v_c66 = m951[2];
                  slog::join_probe<2,1>(refindex894, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m952) {
                    u64 v_c17 = m952[1];
                    slog::join_probe<3,2>(lambdaindex895, std::array<u64,3>{v_c6, v_c17, 0}, [&](const std::array<u64,3>& m953) {
                      u64 v_c67 = m953[2];
                      slog::join_probe<2,1>(refindex896, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m954) {
                        u64 v_c14 = m954[1];
                        slog::join_probe<3,2>(appindex897, std::array<u64,3>{v_c14, v_c64, 0}, [&](const std::array<u64,3>& m955) {
                          u64 v_c63 = m955[2];
                          slog::join_probe<2,1>(refindex898, std::array<u64,2>{v_c11, 0}, [&](const std::array<u64,2>& m956) {
                            u64 v_c12 = m956[1];
                            slog::join_probe<3,2>(appindex899, std::array<u64,3>{v_c63, v_c12, 0}, [&](const std::array<u64,3>& m957) {
                              u64 v_c13 = m957[2];
                              slog::join_probe<2,2>(refindex900, std::array<u64,2>{v_c13, v_c10}, [&](const std::array<u64,2>& m958) {
                                ++_fires;
                                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c11, v_c153}, std::array<u16,3>{1, 2, 0});
                              });
                            });
                          });
                        });
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
        ReadTask901* _cont = new ReadTask901(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask901(db,b), false);
  // (crule (pre (let __tconst1pJW313 constb49bea2fcccd8f4301a347ed) (let __tconst7LWP310 const66518c0c1b3a5a0b09ae2ef1) (let __tconst0sqO307 const4a8acfc71441e0695ffcf5b3) (let __tconst5PoN291 constc85eae03730a4f4cf1d66a0c) (let __tconst2Yzp284 const8ca682693a0738a0641c6956) (let __tconst2CSv302 const229c0b7aa8a7eb4055f5a3d0) (let __tconst9rZO295 const576506f61f53440f1edd95d2)) (seeded) (body (join ref (1 0) 1 __tconst7LWP310 __t91H2298) (exists lambda (1 2 0) 1 __tconst2Yzp284) (exists ref (1 0) 1 __tconst1pJW313) (exists ref (1 0) 1 __tconst9rZO295) (exists lambda (1 2 0) 1 __tconst9rZO295) (exists app (1 2 0) 1 __t91H2298) (exists ref (1 0) 1 __tconst2CSv302) (exists lambda (1 2 0) 1 __tconst2CSv302) (exists lambda (1 2 0) 1 __tconst0sqO307) (exists lambda (1 2 0) 1 __tconst5PoN291) (join ref (1 0) 1 __tconst2Yzp284 __t248W283) (join lambda (1 2 0) 2 __tconst2Yzp284 __t248W283 __t0oFu285) (join ref (1 0) 1 __tconst1pJW313 __t165O287) (exists app (1 2 0) 1 __t165O287) (join ref (1 0) 1 __tconst9rZO295 __t71w7294) (join lambda (1 2 0) 2 __tconst9rZO295 __t71w7294 __t3dkk296) (join app (1 2 0) 2 __t91H2298 __t3dkk296 __t4LtH299) (join ref (1 0) 1 __tconst2CSv302 __t6lXa301) (join lambda (1 2 0) 2 __tconst2CSv302 __t6lXa301 __t7EW2303) (join app (1 2 0) 2 __t91H2298 __t7EW2303 __t4HUX306) (join lambda (1 2 0) 2 __tconst0sqO307 __t4HUX306 __t0vn1308) (join app (1 2 0) 1 __t165O287 dup8n5Y380 __t30Ec290) (eq __t165O287 dup8n5Y380) (join lambda (1 2 0) 2 __tconst5PoN291 __t30Ec290 __t7aCZ292)) (head (mkstruct app (1 2 0) __t6t9L309 __t0vn1308 __t4LtH299)) mcfa-counting.slog:194 #f)
  class ReadTask982 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex959;  slog::Index** lambdaindex960;  slog::Index** refindex961;  slog::Index** refindex962;  slog::Index** lambdaindex963;  slog::Index** appindex964;  slog::Index** refindex965;  slog::Index** lambdaindex966;  slog::Index** lambdaindex967;  slog::Index** lambdaindex968;  slog::Index** refindex969;  slog::Index** lambdaindex970;  slog::Index** refindex971;  slog::Index** appindex972;  slog::Index** refindex973;  slog::Index** lambdaindex974;  slog::Index** appindex975;  slog::Index** refindex976;  slog::Index** lambdaindex977;  slog::Index** appindex978;  slog::Index** lambdaindex979;  slog::Index** appindex980;  slog::Index** lambdaindex981;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord983({1, 2, 0});
      slog::Relation* readrel984 = db->getRelation("app");
      head_index[0] = readrel984->getIndex(ord983, false);
      std::vector<u16> ord985({1, 0});
      slog::Relation* readrel986 = db->getRelation("ref");
      refindex959 = readrel986->getIndex(ord985, false);
      std::vector<u16> ord987({1, 2, 0});
      slog::Relation* readrel988 = db->getRelation("lambda");
      lambdaindex960 = readrel988->getIndex(ord987, false);
      std::vector<u16> ord989({1, 0});
      slog::Relation* readrel990 = db->getRelation("ref");
      refindex961 = readrel990->getIndex(ord989, false);
      std::vector<u16> ord991({1, 0});
      slog::Relation* readrel992 = db->getRelation("ref");
      refindex962 = readrel992->getIndex(ord991, false);
      std::vector<u16> ord993({1, 2, 0});
      slog::Relation* readrel994 = db->getRelation("lambda");
      lambdaindex963 = readrel994->getIndex(ord993, false);
      std::vector<u16> ord995({1, 2, 0});
      slog::Relation* readrel996 = db->getRelation("app");
      appindex964 = readrel996->getIndex(ord995, false);
      std::vector<u16> ord997({1, 0});
      slog::Relation* readrel998 = db->getRelation("ref");
      refindex965 = readrel998->getIndex(ord997, false);
      std::vector<u16> ord999({1, 2, 0});
      slog::Relation* readrel1000 = db->getRelation("lambda");
      lambdaindex966 = readrel1000->getIndex(ord999, false);
      std::vector<u16> ord1001({1, 2, 0});
      slog::Relation* readrel1002 = db->getRelation("lambda");
      lambdaindex967 = readrel1002->getIndex(ord1001, false);
      std::vector<u16> ord1003({1, 2, 0});
      slog::Relation* readrel1004 = db->getRelation("lambda");
      lambdaindex968 = readrel1004->getIndex(ord1003, false);
      std::vector<u16> ord1005({1, 0});
      slog::Relation* readrel1006 = db->getRelation("ref");
      refindex969 = readrel1006->getIndex(ord1005, false);
      std::vector<u16> ord1007({1, 2, 0});
      slog::Relation* readrel1008 = db->getRelation("lambda");
      lambdaindex970 = readrel1008->getIndex(ord1007, false);
      std::vector<u16> ord1009({1, 0});
      slog::Relation* readrel1010 = db->getRelation("ref");
      refindex971 = readrel1010->getIndex(ord1009, false);
      std::vector<u16> ord1011({1, 2, 0});
      slog::Relation* readrel1012 = db->getRelation("app");
      appindex972 = readrel1012->getIndex(ord1011, false);
      std::vector<u16> ord1013({1, 0});
      slog::Relation* readrel1014 = db->getRelation("ref");
      refindex973 = readrel1014->getIndex(ord1013, false);
      std::vector<u16> ord1015({1, 2, 0});
      slog::Relation* readrel1016 = db->getRelation("lambda");
      lambdaindex974 = readrel1016->getIndex(ord1015, false);
      std::vector<u16> ord1017({1, 2, 0});
      slog::Relation* readrel1018 = db->getRelation("app");
      appindex975 = readrel1018->getIndex(ord1017, false);
      std::vector<u16> ord1019({1, 0});
      slog::Relation* readrel1020 = db->getRelation("ref");
      refindex976 = readrel1020->getIndex(ord1019, false);
      std::vector<u16> ord1021({1, 2, 0});
      slog::Relation* readrel1022 = db->getRelation("lambda");
      lambdaindex977 = readrel1022->getIndex(ord1021, false);
      std::vector<u16> ord1023({1, 2, 0});
      slog::Relation* readrel1024 = db->getRelation("app");
      appindex978 = readrel1024->getIndex(ord1023, false);
      std::vector<u16> ord1025({1, 2, 0});
      slog::Relation* readrel1026 = db->getRelation("lambda");
      lambdaindex979 = readrel1026->getIndex(ord1025, false);
      std::vector<u16> ord1027({1, 2, 0});
      slog::Relation* readrel1028 = db->getRelation("app");
      appindex980 = readrel1028->getIndex(ord1027, false);
      std::vector<u16> ord1029({1, 2, 0});
      slog::Relation* readrel1030 = db->getRelation("lambda");
      lambdaindex981 = readrel1030->getIndex(ord1029, false);
  
    }
    ReadTask982(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c154 = v_constb49bea2fcccd8f4301a347ed;
      u64 v_c155 = v_const66518c0c1b3a5a0b09ae2ef1;
      u64 v_c156 = v_const4a8acfc71441e0695ffcf5b3;
      u64 v_c157 = v_constc85eae03730a4f4cf1d66a0c;
      u64 v_c158 = v_const8ca682693a0738a0641c6956;
      u64 v_c159 = v_const229c0b7aa8a7eb4055f5a3d0;
      u64 v_c160 = v_const576506f61f53440f1edd95d2;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex959, std::array<u64,2>{v_c155, 0}, [&](const std::array<u64,2>& m1031) {
        u64 v_c161 = m1031[1];
        if (!slog::exists_probe<3,1>(lambdaindex960, std::array<u64,3>{v_c158, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex961, std::array<u64,2>{v_c154, 0})) return;
        if (!slog::exists_probe<2,1>(refindex962, std::array<u64,2>{v_c160, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex963, std::array<u64,3>{v_c160, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex964, std::array<u64,3>{v_c161, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex965, std::array<u64,2>{v_c159, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex966, std::array<u64,3>{v_c159, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex967, std::array<u64,3>{v_c156, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex968, std::array<u64,3>{v_c157, 0, 0})) return;
        slog::join_probe<2,1>(refindex969, std::array<u64,2>{v_c158, 0}, [&](const std::array<u64,2>& m1032) {
          u64 v_c162 = m1032[1];
          slog::join_probe<3,2>(lambdaindex970, std::array<u64,3>{v_c158, v_c162, 0}, [&](const std::array<u64,3>& m1033) {
            u64 v_c163 = m1033[2];
            slog::join_probe<2,1>(refindex971, std::array<u64,2>{v_c154, 0}, [&](const std::array<u64,2>& m1034) {
              u64 v_c164 = m1034[1];
              if (!slog::exists_probe<3,1>(appindex972, std::array<u64,3>{v_c164, 0, 0})) return;
              slog::join_probe<2,1>(refindex973, std::array<u64,2>{v_c160, 0}, [&](const std::array<u64,2>& m1035) {
                u64 v_c165 = m1035[1];
                slog::join_probe<3,2>(lambdaindex974, std::array<u64,3>{v_c160, v_c165, 0}, [&](const std::array<u64,3>& m1036) {
                  u64 v_c166 = m1036[2];
                  slog::join_probe<3,2>(appindex975, std::array<u64,3>{v_c161, v_c166, 0}, [&](const std::array<u64,3>& m1037) {
                    u64 v_c167 = m1037[2];
                    slog::join_probe<2,1>(refindex976, std::array<u64,2>{v_c159, 0}, [&](const std::array<u64,2>& m1038) {
                      u64 v_c168 = m1038[1];
                      slog::join_probe<3,2>(lambdaindex977, std::array<u64,3>{v_c159, v_c168, 0}, [&](const std::array<u64,3>& m1039) {
                        u64 v_c169 = m1039[2];
                        slog::join_probe<3,2>(appindex978, std::array<u64,3>{v_c161, v_c169, 0}, [&](const std::array<u64,3>& m1040) {
                          u64 v_c170 = m1040[2];
                          slog::join_probe<3,2>(lambdaindex979, std::array<u64,3>{v_c156, v_c170, 0}, [&](const std::array<u64,3>& m1041) {
                            u64 v_c171 = m1041[2];
                            slog::join_probe<3,1>(appindex980, std::array<u64,3>{v_c164, 0, 0}, [&](const std::array<u64,3>& m1042) {
                              u64 v_c172 = m1042[1]; u64 v_c173 = m1042[2];
                              if (v_c164 != v_c172) return;
                              slog::join_probe<3,2>(lambdaindex981, std::array<u64,3>{v_c157, v_c173, 0}, [&](const std::array<u64,3>& m1043) {
                                u64 v_c174 = m1043[2];
                                ++_fires;
                                slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c171, v_c167}, std::array<u16,3>{1, 2, 0});
                              });
                            });
                          });
                        });
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
      s->addTaskSeeded(phase_read, new ReadTask982(db,b));
  // (crule (pre (let __tconst5Fqn220 const15bb62b8293a526ca6f0e4eb) (let __tconst0ZcM213 constfc9ee54e0ee8c6d1e715716c) (let __tconst9TQS210 const5950e3cb761734f52a881545) (let __tconst1wsq203 const77ceb5c0e9f84ebd84104a97)) (seeded) (body (join ref (1 0) 1 __tconst1wsq203 __t6pkv202) (exists ref (1 0) 1 __tconst0ZcM213) (exists ref (1 0) 1 __tconst5Fqn220) (join lambda (1 2 0) 2 __tconst1wsq203 __t6pkv202 __t118D204) (join ref (1 0) 1 __tconst0ZcM213 __t6fYg206) (exists app (1 2 0) 1 __t6fYg206) (join ref (1 0) 1 __tconst5Fqn220 __t2V0C216) (exists app (1 2 0) 1 __t2V0C216) (join app (1 2 0) 1 __t6fYg206 dup79Xs419 __t1W86209) (eq __t6fYg206 dup79Xs419) (join app (1 2 0) 1 __t2V0C216 dup37dO420 __t9nSF219) (eq __t2V0C216 dup37dO420)) (head (mkstruct lambda (1 2 0) __t6h87221 __tconst5Fqn220 __t9nSF219) (mkstruct lambda (1 2 0) __t1wmd211 __tconst9TQS210 __t1W86209)) mcfa-counting.slog:211 #f)
  class ReadTask1054 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
  
  
  
  
  
    slog::Index** refindex1044;  slog::Index** refindex1045;  slog::Index** refindex1046;  slog::Index** lambdaindex1047;  slog::Index** refindex1048;  slog::Index** appindex1049;  slog::Index** refindex1050;  slog::Index** appindex1051;  slog::Index** appindex1052;  slog::Index** appindex1053;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      std::vector<u16> ord1055({1, 2, 0});
      slog::Relation* readrel1056 = db->getRelation("lambda");
      head_index[0] = readrel1056->getIndex(ord1055, false);
      head_rel[1] = db->getRelation("lambda");
      std::vector<u16> ord1057({1, 2, 0});
      slog::Relation* readrel1058 = db->getRelation("lambda");
      head_index[1] = readrel1058->getIndex(ord1057, false);
      std::vector<u16> ord1059({1, 0});
      slog::Relation* readrel1060 = db->getRelation("ref");
      refindex1044 = readrel1060->getIndex(ord1059, false);
      std::vector<u16> ord1061({1, 0});
      slog::Relation* readrel1062 = db->getRelation("ref");
      refindex1045 = readrel1062->getIndex(ord1061, false);
      std::vector<u16> ord1063({1, 0});
      slog::Relation* readrel1064 = db->getRelation("ref");
      refindex1046 = readrel1064->getIndex(ord1063, false);
      std::vector<u16> ord1065({1, 2, 0});
      slog::Relation* readrel1066 = db->getRelation("lambda");
      lambdaindex1047 = readrel1066->getIndex(ord1065, false);
      std::vector<u16> ord1067({1, 0});
      slog::Relation* readrel1068 = db->getRelation("ref");
      refindex1048 = readrel1068->getIndex(ord1067, false);
      std::vector<u16> ord1069({1, 2, 0});
      slog::Relation* readrel1070 = db->getRelation("app");
      appindex1049 = readrel1070->getIndex(ord1069, false);
      std::vector<u16> ord1071({1, 0});
      slog::Relation* readrel1072 = db->getRelation("ref");
      refindex1050 = readrel1072->getIndex(ord1071, false);
      std::vector<u16> ord1073({1, 2, 0});
      slog::Relation* readrel1074 = db->getRelation("app");
      appindex1051 = readrel1074->getIndex(ord1073, false);
      std::vector<u16> ord1075({1, 2, 0});
      slog::Relation* readrel1076 = db->getRelation("app");
      appindex1052 = readrel1076->getIndex(ord1075, false);
      std::vector<u16> ord1077({1, 2, 0});
      slog::Relation* readrel1078 = db->getRelation("app");
      appindex1053 = readrel1078->getIndex(ord1077, false);
  
    }
    ReadTask1054(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c33 = v_const15bb62b8293a526ca6f0e4eb;
      u64 v_c34 = v_constfc9ee54e0ee8c6d1e715716c;
      u64 v_c35 = v_const5950e3cb761734f52a881545;
      u64 v_c36 = v_const77ceb5c0e9f84ebd84104a97;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex1044, std::array<u64,2>{v_c36, 0}, [&](const std::array<u64,2>& m1079) {
        u64 v_c39 = m1079[1];
        if (!slog::exists_probe<2,1>(refindex1045, std::array<u64,2>{v_c34, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1046, std::array<u64,2>{v_c33, 0})) return;
        slog::join_probe<3,2>(lambdaindex1047, std::array<u64,3>{v_c36, v_c39, 0}, [&](const std::array<u64,3>& m1080) {
          u64 v_c40 = m1080[2];
          slog::join_probe<2,1>(refindex1048, std::array<u64,2>{v_c34, 0}, [&](const std::array<u64,2>& m1081) {
            u64 v_c41 = m1081[1];
            if (!slog::exists_probe<3,1>(appindex1049, std::array<u64,3>{v_c41, 0, 0})) return;
            slog::join_probe<2,1>(refindex1050, std::array<u64,2>{v_c33, 0}, [&](const std::array<u64,2>& m1082) {
              u64 v_c43 = m1082[1];
              if (!slog::exists_probe<3,1>(appindex1051, std::array<u64,3>{v_c43, 0, 0})) return;
              slog::join_probe<3,1>(appindex1052, std::array<u64,3>{v_c41, 0, 0}, [&](const std::array<u64,3>& m1083) {
                u64 v_c175 = m1083[1]; u64 v_c37 = m1083[2];
                if (v_c41 != v_c175) return;
                slog::join_probe<3,1>(appindex1053, std::array<u64,3>{v_c43, 0, 0}, [&](const std::array<u64,3>& m1084) {
                  u64 v_c176 = m1084[1]; u64 v_c45 = m1084[2];
                  if (v_c43 != v_c176) return;
                  ++_fires;
                  slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c33, v_c45}, std::array<u16,3>{1, 2, 0});
                  slog::emit_struct_checked<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c35, v_c37}, std::array<u16,3>{1, 2, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:211", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask1054(db,b));
  // (crule (pre) (scan eval_ans __t2S0s262 va) (body (join-old eval (0 2 1) 1 (0 2 1) __t2S0s262 c ea) (exists app (2 0 1) 1 ea) (exists eval (2 0 1) 1 c) (join eval (2 0 1) 1 c __5DEq344 __t6ooL258) (join-old app (2 0 1) 2 (2 0 1) ea __t6ooL258 ef) (join-old eval (1 2 0) 2 (1 2 0) ef c __t7ceq259) (join eval_ans (0 1) 1 __t7ceq259 __t0zen261) (join-old clo (0 2 1) 1 (0 2 1) __t0zen261 cb __t4JNf263) (exists store (1 0 2) 1 cb) (join-old freevar (1 0) 1 (1 0) __t4JNf263 y) (join-old store (0 1 2) 2 (0 1 2) y cb vy) (join-old lambda (0 1 2) 1 (0 1 2) __t4JNf263 x eb)) (head (emit store (0 1 2) y __t6ooL258 vy) (emit bindev (0 1 2) y __t6ooL258 c)) mcfa-counting.slog:102 #f)
  class ReadTask1104 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1085;  slog::Index** appindex1086;  slog::Index** evalindex1087;  slog::Index** evalindex1088;  slog::Index** appindex1089;  slog::Index** evalindex1090;  slog::Index** eval_ansindex1091;  slog::Index** cloindex1092;  slog::Index** storeindex1093;  slog::Index** freevarindex1094;  slog::Index** storeindex1095;  slog::Index** lambdaindex1096;  slog::Index** evaldelta1097;  slog::Index** appdelta1098;  slog::Index** evaldelta1099;  slog::Index** clodelta1100;  slog::Index** freevardelta1101;  slog::Index** storedelta1102;  slog::Index** lambdadelta1103;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("store");
      std::vector<u16> ord1105({0, 1, 2});
      slog::Relation* readrel1106 = db->getRelation("store");
      head_index[0] = readrel1106->getIndex(ord1105, false);
      head_rel[1] = db->getRelation("bindev");
      std::vector<u16> ord1107({0, 1, 2});
      slog::Relation* readrel1108 = db->getRelation("bindev");
      head_index[1] = readrel1108->getIndex(ord1107, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord1109({0, 2, 1});
      slog::Relation* readrel1110 = db->getRelation("eval");
      evalindex1085 = readrel1110->getIndex(ord1109, false);
      std::vector<u16> ord1111({0, 2, 1});
      slog::Relation* readrel1112 = db->getRelation("eval");
      evaldelta1097 = readrel1112->getIndex(ord1111, true);
      std::vector<u16> ord1113({2, 0, 1});
      slog::Relation* readrel1114 = db->getRelation("app");
      appindex1086 = readrel1114->getIndex(ord1113, false);
      std::vector<u16> ord1115({2, 0, 1});
      slog::Relation* readrel1116 = db->getRelation("eval");
      evalindex1087 = readrel1116->getIndex(ord1115, false);
      std::vector<u16> ord1117({2, 0, 1});
      slog::Relation* readrel1118 = db->getRelation("eval");
      evalindex1088 = readrel1118->getIndex(ord1117, false);
      std::vector<u16> ord1119({2, 0, 1});
      slog::Relation* readrel1120 = db->getRelation("app");
      appindex1089 = readrel1120->getIndex(ord1119, false);
      std::vector<u16> ord1121({2, 0, 1});
      slog::Relation* readrel1122 = db->getRelation("app");
      appdelta1098 = readrel1122->getIndex(ord1121, true);
      std::vector<u16> ord1123({1, 2, 0});
      slog::Relation* readrel1124 = db->getRelation("eval");
      evalindex1090 = readrel1124->getIndex(ord1123, false);
      std::vector<u16> ord1125({1, 2, 0});
      slog::Relation* readrel1126 = db->getRelation("eval");
      evaldelta1099 = readrel1126->getIndex(ord1125, true);
      std::vector<u16> ord1127({0, 1});
      slog::Relation* readrel1128 = db->getRelation("eval_ans");
      eval_ansindex1091 = readrel1128->getIndex(ord1127, false);
      std::vector<u16> ord1129({0, 2, 1});
      slog::Relation* readrel1130 = db->getRelation("clo");
      cloindex1092 = readrel1130->getIndex(ord1129, false);
      std::vector<u16> ord1131({0, 2, 1});
      slog::Relation* readrel1132 = db->getRelation("clo");
      clodelta1100 = readrel1132->getIndex(ord1131, true);
      std::vector<u16> ord1133({1, 0, 2});
      slog::Relation* readrel1134 = db->getRelation("store");
      storeindex1093 = readrel1134->getIndex(ord1133, false);
      std::vector<u16> ord1135({1, 0});
      slog::Relation* readrel1136 = db->getRelation("freevar");
      freevarindex1094 = readrel1136->getIndex(ord1135, false);
      std::vector<u16> ord1137({1, 0});
      slog::Relation* readrel1138 = db->getRelation("freevar");
      freevardelta1101 = readrel1138->getIndex(ord1137, true);
      std::vector<u16> ord1139({0, 1, 2});
      slog::Relation* readrel1140 = db->getRelation("store");
      storeindex1095 = readrel1140->getIndex(ord1139, false);
      std::vector<u16> ord1141({0, 1, 2});
      slog::Relation* readrel1142 = db->getRelation("store");
      storedelta1102 = readrel1142->getIndex(ord1141, true);
      std::vector<u16> ord1143({0, 1, 2});
      slog::Relation* readrel1144 = db->getRelation("lambda");
      lambdaindex1096 = readrel1144->getIndex(ord1143, false);
      std::vector<u16> ord1145({0, 1, 2});
      slog::Relation* readrel1146 = db->getRelation("lambda");
      lambdadelta1103 = readrel1146->getIndex(ord1145, true);
  
    }
    ReadTask1104(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c24 = _t[0];
        u64 v_c26 = _t[1];
        slog::join_probe_old<3,1>(evalindex1085, evaldelta1097, std::array<u64,3>{v_c24, 0, 0}, [&](const std::array<u64,3>& m1147) {
          u64 v_c21 = m1147[1]; u64 v_c20 = m1147[2];
          if (!slog::exists_probe<3,1>(appindex1086, std::array<u64,3>{v_c20, 0, 0})) return;
          if (!slog::exists_probe<3,1>(evalindex1087, std::array<u64,3>{v_c21, 0, 0})) return;
          slog::join_probe<3,1>(evalindex1088, std::array<u64,3>{v_c21, 0, 0}, [&](const std::array<u64,3>& m1148) {
            u64 v_c22 = m1148[1]; u64 v_c18 = m1148[2];
            slog::join_probe_old<3,2>(appindex1089, appdelta1098, std::array<u64,3>{v_c20, v_c18, 0}, [&](const std::array<u64,3>& m1149) {
              u64 v_c19 = m1149[2];
              slog::join_probe_old<3,2>(evalindex1090, evaldelta1099, std::array<u64,3>{v_c19, v_c21, 0}, [&](const std::array<u64,3>& m1150) {
                u64 v_c23 = m1150[2];
                slog::join_probe<2,1>(eval_ansindex1091, std::array<u64,2>{v_c23, 0}, [&](const std::array<u64,2>& m1151) {
                  u64 v_c25 = m1151[1];
                  slog::join_probe_old<3,1>(cloindex1092, clodelta1100, std::array<u64,3>{v_c25, 0, 0}, [&](const std::array<u64,3>& m1152) {
                    u64 v_c27 = m1152[1]; u64 v_c28 = m1152[2];
                    if (!slog::exists_probe<3,1>(storeindex1093, std::array<u64,3>{v_c27, 0, 0})) return;
                    slog::join_probe_old<2,1>(freevarindex1094, freevardelta1101, std::array<u64,2>{v_c28, 0}, [&](const std::array<u64,2>& m1153) {
                      u64 v_c29 = m1153[1];
                      slog::join_probe_old<3,2>(storeindex1095, storedelta1102, std::array<u64,3>{v_c29, v_c27, 0}, [&](const std::array<u64,3>& m1154) {
                        u64 v_c30 = m1154[2];
                        slog::join_probe_old<3,1>(lambdaindex1096, lambdadelta1103, std::array<u64,3>{v_c28, 0, 0}, [&](const std::array<u64,3>& m1155) {
                          u64 v_c31 = m1155[1]; u64 v_c32 = m1155[2];
                          ++_fires;
                          slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c29, v_c18, v_c30}, std::array<u16,3>{0, 1, 2});
                          slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c29, v_c18, v_c21}, std::array<u16,3>{0, 1, 2});
                        });
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
        ReadTask1104* _cont = new ReadTask1104(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1104(db,b), false);
  // (crule (pre (let __tconst0ZcM213 constfc9ee54e0ee8c6d1e715716c) (let __tconst5Fqn220 const15bb62b8293a526ca6f0e4eb) (let __tconst9TQS210 const5950e3cb761734f52a881545) (let __tconst1wsq203 const77ceb5c0e9f84ebd84104a97)) (probe lambda (1 2 0) 1 __tconst0ZcM213 __t4jAx212 __t14ld214) (body (exists lambda (1 2 0) 1 __tconst1wsq203) (exists lambda (1 2 0) 1 __tconst9TQS210) (exists ref (1 0) 1 __tconst5Fqn220) (exists ref (1 0) 1 __tconst0ZcM213) (exists lambda (1 2 0) 1 __tconst5Fqn220) (join ref (1 0) 1 __tconst1wsq203 __t6pkv202) (join lambda (1 2 0) 2 __tconst1wsq203 __t6pkv202 __t118D204) (join app (2 0 1) 2 __t118D204 __t4jAx212 __t1wmd211) (join lambda (0 1 2) 2 __t1wmd211 __tconst9TQS210 __t1W86209) (join ref (1 0) 1 __tconst5Fqn220 __t2V0C216) (exists app (1 2 0) 1 __t2V0C216) (join ref (1 0) 1 __tconst0ZcM213 __t6fYg206) (join app (0 1 2) 2 __t1W86209 __t6fYg206 dup0zel430) (eq __t6fYg206 dup0zel430) (join app (1 2 0) 1 __t2V0C216 dup0V86429 __t9nSF219) (eq __t2V0C216 dup0V86429) (join lambda (1 2 0) 2 __tconst5Fqn220 __t9nSF219 __t6h87221)) (head (mkstruct app (1 2 0) __t4RlI222 __t6h87221 __t14ld214)) mcfa-counting.slog:211 #f)
  class ReadTask1171 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** lambdaindex1156;  slog::Index** lambdaindex1157;  slog::Index** refindex1158;  slog::Index** refindex1159;  slog::Index** lambdaindex1160;  slog::Index** refindex1161;  slog::Index** lambdaindex1162;  slog::Index** appindex1163;  slog::Index** lambdaindex1164;  slog::Index** refindex1165;  slog::Index** appindex1166;  slog::Index** refindex1167;  slog::Index** appindex1168;  slog::Index** appindex1169;  slog::Index** lambdaindex1170;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord1172({1, 2, 0});
      slog::Relation* readrel1173 = db->getRelation("lambda");
      driver_index = readrel1173->getIndex(ord1172, true);
      std::vector<u16> ord1174({1, 2, 0});
      slog::Relation* readrel1175 = db->getRelation("lambda");
      lambdaindex1156 = readrel1175->getIndex(ord1174, false);
      std::vector<u16> ord1176({1, 2, 0});
      slog::Relation* readrel1177 = db->getRelation("lambda");
      lambdaindex1157 = readrel1177->getIndex(ord1176, false);
      std::vector<u16> ord1178({1, 0});
      slog::Relation* readrel1179 = db->getRelation("ref");
      refindex1158 = readrel1179->getIndex(ord1178, false);
      std::vector<u16> ord1180({1, 0});
      slog::Relation* readrel1181 = db->getRelation("ref");
      refindex1159 = readrel1181->getIndex(ord1180, false);
      std::vector<u16> ord1182({1, 2, 0});
      slog::Relation* readrel1183 = db->getRelation("lambda");
      lambdaindex1160 = readrel1183->getIndex(ord1182, false);
      std::vector<u16> ord1184({1, 0});
      slog::Relation* readrel1185 = db->getRelation("ref");
      refindex1161 = readrel1185->getIndex(ord1184, false);
      std::vector<u16> ord1186({1, 2, 0});
      slog::Relation* readrel1187 = db->getRelation("lambda");
      lambdaindex1162 = readrel1187->getIndex(ord1186, false);
      std::vector<u16> ord1188({2, 0, 1});
      slog::Relation* readrel1189 = db->getRelation("app");
      appindex1163 = readrel1189->getIndex(ord1188, false);
      std::vector<u16> ord1190({0, 1, 2});
      slog::Relation* readrel1191 = db->getRelation("lambda");
      lambdaindex1164 = readrel1191->getIndex(ord1190, false);
      std::vector<u16> ord1192({1, 0});
      slog::Relation* readrel1193 = db->getRelation("ref");
      refindex1165 = readrel1193->getIndex(ord1192, false);
      std::vector<u16> ord1194({1, 2, 0});
      slog::Relation* readrel1195 = db->getRelation("app");
      appindex1166 = readrel1195->getIndex(ord1194, false);
      std::vector<u16> ord1196({1, 0});
      slog::Relation* readrel1197 = db->getRelation("ref");
      refindex1167 = readrel1197->getIndex(ord1196, false);
      std::vector<u16> ord1198({0, 1, 2});
      slog::Relation* readrel1199 = db->getRelation("app");
      appindex1168 = readrel1199->getIndex(ord1198, false);
      std::vector<u16> ord1200({1, 2, 0});
      slog::Relation* readrel1201 = db->getRelation("app");
      appindex1169 = readrel1201->getIndex(ord1200, false);
      std::vector<u16> ord1202({1, 2, 0});
      slog::Relation* readrel1203 = db->getRelation("lambda");
      lambdaindex1170 = readrel1203->getIndex(ord1202, false);
  
    }
    ReadTask1171(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c34 = v_constfc9ee54e0ee8c6d1e715716c;
      u64 v_c33 = v_const15bb62b8293a526ca6f0e4eb;
      u64 v_c35 = v_const5950e3cb761734f52a881545;
      u64 v_c36 = v_const77ceb5c0e9f84ebd84104a97;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c34, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1204) {
        u64 v_c48 = m1204[1];
        u64 v_c177 = m1204[2];
        if (buckethash(v_c48) != bucket) return;
        if (!slog::exists_probe<3,1>(lambdaindex1156, std::array<u64,3>{v_c36, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1157, std::array<u64,3>{v_c35, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1158, std::array<u64,2>{v_c33, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1159, std::array<u64,2>{v_c34, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1160, std::array<u64,3>{v_c33, 0, 0})) return;
        slog::join_probe<2,1>(refindex1161, std::array<u64,2>{v_c36, 0}, [&](const std::array<u64,2>& m1205) {
          u64 v_c39 = m1205[1];
          slog::join_probe<3,2>(lambdaindex1162, std::array<u64,3>{v_c36, v_c39, 0}, [&](const std::array<u64,3>& m1206) {
            u64 v_c40 = m1206[2];
            slog::join_probe<3,2>(appindex1163, std::array<u64,3>{v_c40, v_c48, 0}, [&](const std::array<u64,3>& m1207) {
              u64 v_c38 = m1207[2];
              slog::join_probe<3,2>(lambdaindex1164, std::array<u64,3>{v_c38, v_c35, 0}, [&](const std::array<u64,3>& m1208) {
                u64 v_c37 = m1208[2];
                slog::join_probe<2,1>(refindex1165, std::array<u64,2>{v_c33, 0}, [&](const std::array<u64,2>& m1209) {
                  u64 v_c43 = m1209[1];
                  if (!slog::exists_probe<3,1>(appindex1166, std::array<u64,3>{v_c43, 0, 0})) return;
                  slog::join_probe<2,1>(refindex1167, std::array<u64,2>{v_c34, 0}, [&](const std::array<u64,2>& m1210) {
                    u64 v_c41 = m1210[1];
                    slog::join_probe<3,2>(appindex1168, std::array<u64,3>{v_c37, v_c41, 0}, [&](const std::array<u64,3>& m1211) {
                      u64 v_c178 = m1211[2];
                      if (v_c41 != v_c178) return;
                      slog::join_probe<3,1>(appindex1169, std::array<u64,3>{v_c43, 0, 0}, [&](const std::array<u64,3>& m1212) {
                        u64 v_c179 = m1212[1]; u64 v_c45 = m1212[2];
                        if (v_c43 != v_c179) return;
                        slog::join_probe<3,2>(lambdaindex1170, std::array<u64,3>{v_c33, v_c45, 0}, [&](const std::array<u64,3>& m1213) {
                          u64 v_c46 = m1213[2];
                          ++_fires;
                          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c46, v_c177}, std::array<u16,3>{1, 2, 0});
                        });
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
  
      if (_fires) db->bumpFires("mcfa-counting.slog:211", "delta:lambda", _fires);
  
      if (!_done)
      {
        ReadTask1171* _cont = new ReadTask1171(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1171(db,b), false);
  // (crule (pre (let __tconst5Fqn220 const15bb62b8293a526ca6f0e4eb) (let __tconst0ZcM213 constfc9ee54e0ee8c6d1e715716c) (let __tconst9TQS210 const5950e3cb761734f52a881545) (let __tconst1wsq203 const77ceb5c0e9f84ebd84104a97)) (seeded) (body (join ref (1 0) 1 __tconst1wsq203 __t6pkv202) (exists ref (1 0) 1 __tconst0ZcM213) (exists ref (1 0) 1 __tconst5Fqn220) (exists lambda (1 2 0) 1 __tconst9TQS210) (exists lambda (1 2 0) 1 __tconst5Fqn220) (join lambda (1 2 0) 2 __tconst1wsq203 __t6pkv202 __t118D204) (join ref (1 0) 1 __tconst0ZcM213 __t6fYg206) (exists app (1 2 0) 1 __t6fYg206) (join ref (1 0) 1 __tconst5Fqn220 __t2V0C216) (exists app (1 2 0) 1 __t2V0C216) (join app (1 2 0) 1 __t6fYg206 dup7q2s423 __t1W86209) (eq __t6fYg206 dup7q2s423) (join lambda (1 2 0) 2 __tconst9TQS210 __t1W86209 __t1wmd211) (join app (1 2 0) 1 __t2V0C216 dup7LM8424 __t9nSF219) (eq __t2V0C216 dup7LM8424) (join lambda (1 2 0) 2 __tconst5Fqn220 __t9nSF219 __t6h87221)) (head (mkstruct app (1 2 0) __t4jAx212 __t1wmd211 __t118D204)) mcfa-counting.slog:211 #f)
  class ReadTask1228 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex1214;  slog::Index** refindex1215;  slog::Index** refindex1216;  slog::Index** lambdaindex1217;  slog::Index** lambdaindex1218;  slog::Index** lambdaindex1219;  slog::Index** refindex1220;  slog::Index** appindex1221;  slog::Index** refindex1222;  slog::Index** appindex1223;  slog::Index** appindex1224;  slog::Index** lambdaindex1225;  slog::Index** appindex1226;  slog::Index** lambdaindex1227;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord1229({1, 2, 0});
      slog::Relation* readrel1230 = db->getRelation("app");
      head_index[0] = readrel1230->getIndex(ord1229, false);
      std::vector<u16> ord1231({1, 0});
      slog::Relation* readrel1232 = db->getRelation("ref");
      refindex1214 = readrel1232->getIndex(ord1231, false);
      std::vector<u16> ord1233({1, 0});
      slog::Relation* readrel1234 = db->getRelation("ref");
      refindex1215 = readrel1234->getIndex(ord1233, false);
      std::vector<u16> ord1235({1, 0});
      slog::Relation* readrel1236 = db->getRelation("ref");
      refindex1216 = readrel1236->getIndex(ord1235, false);
      std::vector<u16> ord1237({1, 2, 0});
      slog::Relation* readrel1238 = db->getRelation("lambda");
      lambdaindex1217 = readrel1238->getIndex(ord1237, false);
      std::vector<u16> ord1239({1, 2, 0});
      slog::Relation* readrel1240 = db->getRelation("lambda");
      lambdaindex1218 = readrel1240->getIndex(ord1239, false);
      std::vector<u16> ord1241({1, 2, 0});
      slog::Relation* readrel1242 = db->getRelation("lambda");
      lambdaindex1219 = readrel1242->getIndex(ord1241, false);
      std::vector<u16> ord1243({1, 0});
      slog::Relation* readrel1244 = db->getRelation("ref");
      refindex1220 = readrel1244->getIndex(ord1243, false);
      std::vector<u16> ord1245({1, 2, 0});
      slog::Relation* readrel1246 = db->getRelation("app");
      appindex1221 = readrel1246->getIndex(ord1245, false);
      std::vector<u16> ord1247({1, 0});
      slog::Relation* readrel1248 = db->getRelation("ref");
      refindex1222 = readrel1248->getIndex(ord1247, false);
      std::vector<u16> ord1249({1, 2, 0});
      slog::Relation* readrel1250 = db->getRelation("app");
      appindex1223 = readrel1250->getIndex(ord1249, false);
      std::vector<u16> ord1251({1, 2, 0});
      slog::Relation* readrel1252 = db->getRelation("app");
      appindex1224 = readrel1252->getIndex(ord1251, false);
      std::vector<u16> ord1253({1, 2, 0});
      slog::Relation* readrel1254 = db->getRelation("lambda");
      lambdaindex1225 = readrel1254->getIndex(ord1253, false);
      std::vector<u16> ord1255({1, 2, 0});
      slog::Relation* readrel1256 = db->getRelation("app");
      appindex1226 = readrel1256->getIndex(ord1255, false);
      std::vector<u16> ord1257({1, 2, 0});
      slog::Relation* readrel1258 = db->getRelation("lambda");
      lambdaindex1227 = readrel1258->getIndex(ord1257, false);
  
    }
    ReadTask1228(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c33 = v_const15bb62b8293a526ca6f0e4eb;
      u64 v_c34 = v_constfc9ee54e0ee8c6d1e715716c;
      u64 v_c35 = v_const5950e3cb761734f52a881545;
      u64 v_c36 = v_const77ceb5c0e9f84ebd84104a97;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex1214, std::array<u64,2>{v_c36, 0}, [&](const std::array<u64,2>& m1259) {
        u64 v_c39 = m1259[1];
        if (!slog::exists_probe<2,1>(refindex1215, std::array<u64,2>{v_c34, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1216, std::array<u64,2>{v_c33, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1217, std::array<u64,3>{v_c35, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1218, std::array<u64,3>{v_c33, 0, 0})) return;
        slog::join_probe<3,2>(lambdaindex1219, std::array<u64,3>{v_c36, v_c39, 0}, [&](const std::array<u64,3>& m1260) {
          u64 v_c40 = m1260[2];
          slog::join_probe<2,1>(refindex1220, std::array<u64,2>{v_c34, 0}, [&](const std::array<u64,2>& m1261) {
            u64 v_c41 = m1261[1];
            if (!slog::exists_probe<3,1>(appindex1221, std::array<u64,3>{v_c41, 0, 0})) return;
            slog::join_probe<2,1>(refindex1222, std::array<u64,2>{v_c33, 0}, [&](const std::array<u64,2>& m1262) {
              u64 v_c43 = m1262[1];
              if (!slog::exists_probe<3,1>(appindex1223, std::array<u64,3>{v_c43, 0, 0})) return;
              slog::join_probe<3,1>(appindex1224, std::array<u64,3>{v_c41, 0, 0}, [&](const std::array<u64,3>& m1263) {
                u64 v_c180 = m1263[1]; u64 v_c37 = m1263[2];
                if (v_c41 != v_c180) return;
                slog::join_probe<3,2>(lambdaindex1225, std::array<u64,3>{v_c35, v_c37, 0}, [&](const std::array<u64,3>& m1264) {
                  u64 v_c38 = m1264[2];
                  slog::join_probe<3,1>(appindex1226, std::array<u64,3>{v_c43, 0, 0}, [&](const std::array<u64,3>& m1265) {
                    u64 v_c181 = m1265[1]; u64 v_c45 = m1265[2];
                    if (v_c43 != v_c181) return;
                    slog::join_probe<3,2>(lambdaindex1227, std::array<u64,3>{v_c33, v_c45, 0}, [&](const std::array<u64,3>& m1266) {
                      u64 v_c46 = m1266[2];
                      ++_fires;
                      slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c38, v_c40}, std::array<u16,3>{1, 2, 0});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:211", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask1228(db,b));
  // (crule (pre (let __tconst4she277 const50a95ec20b9767e468d04917) (let __tconst0ZLv270 constf0a25c0401304c51b5ee9c5e)) (probe lambda (1 2 0) 1 __tconst0ZLv270 __t8kx2269 __t3oIn271) (body (exists ref (1 0) 1 __tconst4she277) (exists lambda (1 2 0) 1 __tconst4she277) (join ref (1 0) 1 __tconst0ZLv270 __t9L3S266) (join app (0 1 2) 2 __t8kx2269 __t9L3S266 dup1XAw441) (eq __t9L3S266 dup1XAw441) (join ref (1 0) 1 __tconst4she277 __t28CO273) (join app (1 2 0) 1 __t28CO273 dup3AOX442 __t6FnS276) (eq __t28CO273 dup3AOX442) (join lambda (1 2 0) 2 __tconst4she277 __t6FnS276 __t6zNR278)) (head (mkstruct app (1 2 0) __t4C0a279 __t6zNR278 __t3oIn271)) mcfa-counting.slog:183 #f)
  class ReadTask1274 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** refindex1267;  slog::Index** lambdaindex1268;  slog::Index** refindex1269;  slog::Index** appindex1270;  slog::Index** refindex1271;  slog::Index** appindex1272;  slog::Index** lambdaindex1273;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord1275({1, 2, 0});
      slog::Relation* readrel1276 = db->getRelation("lambda");
      driver_index = readrel1276->getIndex(ord1275, true);
      std::vector<u16> ord1277({1, 0});
      slog::Relation* readrel1278 = db->getRelation("ref");
      refindex1267 = readrel1278->getIndex(ord1277, false);
      std::vector<u16> ord1279({1, 2, 0});
      slog::Relation* readrel1280 = db->getRelation("lambda");
      lambdaindex1268 = readrel1280->getIndex(ord1279, false);
      std::vector<u16> ord1281({1, 0});
      slog::Relation* readrel1282 = db->getRelation("ref");
      refindex1269 = readrel1282->getIndex(ord1281, false);
      std::vector<u16> ord1283({0, 1, 2});
      slog::Relation* readrel1284 = db->getRelation("app");
      appindex1270 = readrel1284->getIndex(ord1283, false);
      std::vector<u16> ord1285({1, 0});
      slog::Relation* readrel1286 = db->getRelation("ref");
      refindex1271 = readrel1286->getIndex(ord1285, false);
      std::vector<u16> ord1287({1, 2, 0});
      slog::Relation* readrel1288 = db->getRelation("app");
      appindex1272 = readrel1288->getIndex(ord1287, false);
      std::vector<u16> ord1289({1, 2, 0});
      slog::Relation* readrel1290 = db->getRelation("lambda");
      lambdaindex1273 = readrel1290->getIndex(ord1289, false);
  
    }
    ReadTask1274(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c182 = v_const50a95ec20b9767e468d04917;
      u64 v_c183 = v_constf0a25c0401304c51b5ee9c5e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c183, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1291) {
        u64 v_c184 = m1291[1];
        u64 v_c185 = m1291[2];
        if (buckethash(v_c184) != bucket) return;
        if (!slog::exists_probe<2,1>(refindex1267, std::array<u64,2>{v_c182, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1268, std::array<u64,3>{v_c182, 0, 0})) return;
        slog::join_probe<2,1>(refindex1269, std::array<u64,2>{v_c183, 0}, [&](const std::array<u64,2>& m1292) {
          u64 v_c186 = m1292[1];
          slog::join_probe<3,2>(appindex1270, std::array<u64,3>{v_c184, v_c186, 0}, [&](const std::array<u64,3>& m1293) {
            u64 v_c187 = m1293[2];
            if (v_c186 != v_c187) return;
            slog::join_probe<2,1>(refindex1271, std::array<u64,2>{v_c182, 0}, [&](const std::array<u64,2>& m1294) {
              u64 v_c188 = m1294[1];
              slog::join_probe<3,1>(appindex1272, std::array<u64,3>{v_c188, 0, 0}, [&](const std::array<u64,3>& m1295) {
                u64 v_c189 = m1295[1]; u64 v_c190 = m1295[2];
                if (v_c188 != v_c189) return;
                slog::join_probe<3,2>(lambdaindex1273, std::array<u64,3>{v_c182, v_c190, 0}, [&](const std::array<u64,3>& m1296) {
                  u64 v_c191 = m1296[2];
                  ++_fires;
                  slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c191, v_c185}, std::array<u16,3>{1, 2, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:183", "delta:lambda", _fires);
  
      if (!_done)
      {
        ReadTask1274* _cont = new ReadTask1274(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1274(db,b), false);
  // (crule (pre (let __tconst4N2q248 constaaaad65142343c54348db5d0) (let __tconst7sqz226 const7b8fd91ee9ff10cfbb8066bf) (let __tconst1EUj230 const615ad01b1c532bb6634df115) (let __tconst2VuQ234 const4492fd5fa4baacfebd29f5e5) (let __tconst4Sko246 consteb793a6f75d6cfe49d3c2c90) (let __tconst2x2f244 consta32d5a443def48e6d64c6f4b)) (seeded) (body (join ref (1 0) 1 __tconst2VuQ234 __t2PLq233) (exists ref (1 0) 1 __tconst1EUj230) (exists lambda (1 2 0) 1 __tconst1EUj230) (exists ref (1 0) 1 __tconst7sqz226) (exists lambda (1 2 0) 1 __tconst7sqz226) (exists ref (1 0) 1 __tconst2x2f244) (exists ref (1 0) 1 __tconst4N2q248) (exists ref (1 0) 1 __tconst4Sko246) (exists lambda (1 2 0) 1 __tconst2x2f244) (exists lambda (1 2 0) 1 __tconst4Sko246) (exists lambda (1 2 0) 1 __tconst4N2q248) (join lambda (1 2 0) 2 __tconst2VuQ234 __t2PLq233 __t45rU235) (exists app (2 0 1) 1 __t45rU235) (join ref (1 0) 1 __tconst1EUj230 __t3WVP229) (join lambda (1 2 0) 2 __tconst1EUj230 __t3WVP229 __t5ryk231) (join ref (1 0) 1 __tconst7sqz226 __t5APF225) (join lambda (1 2 0) 2 __tconst7sqz226 __t5APF225 __t2BAX227) (join ref (1 0) 1 __tconst2x2f244 __t3pbc237) (exists app (2 0 1) 1 __t3pbc237) (join ref (1 0) 1 __tconst4N2q248 __t6KL4241) (exists app (1 2 0) 1 __t6KL4241) (join ref (1 0) 1 __tconst4Sko246 __t16jv239) (join app (1 2 0) 2 __t6KL4241 __t16jv239 __t4wvK242) (join app (1 2 0) 2 __t4wvK242 __t3pbc237 __t5h6K243) (join lambda (1 2 0) 2 __tconst2x2f244 __t5h6K243 __t3laZ245) (join lambda (1 2 0) 2 __tconst4Sko246 __t3laZ245 __t7yz1247) (join lambda (1 2 0) 2 __tconst4N2q248 __t7yz1247 __t5uyC249) (join app (1 2 0) 2 __t5uyC249 __t45rU235 __t5pZU250)) (head (mkstruct app (1 2 0) __t9bBp251 __t5pZU250 __t5ryk231)) mcfa-counting.slog:272 #f)
  class ReadTask1325 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex1297;  slog::Index** refindex1298;  slog::Index** lambdaindex1299;  slog::Index** refindex1300;  slog::Index** lambdaindex1301;  slog::Index** refindex1302;  slog::Index** refindex1303;  slog::Index** refindex1304;  slog::Index** lambdaindex1305;  slog::Index** lambdaindex1306;  slog::Index** lambdaindex1307;  slog::Index** lambdaindex1308;  slog::Index** appindex1309;  slog::Index** refindex1310;  slog::Index** lambdaindex1311;  slog::Index** refindex1312;  slog::Index** lambdaindex1313;  slog::Index** refindex1314;  slog::Index** appindex1315;  slog::Index** refindex1316;  slog::Index** appindex1317;  slog::Index** refindex1318;  slog::Index** appindex1319;  slog::Index** appindex1320;  slog::Index** lambdaindex1321;  slog::Index** lambdaindex1322;  slog::Index** lambdaindex1323;  slog::Index** appindex1324;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord1326({1, 2, 0});
      slog::Relation* readrel1327 = db->getRelation("app");
      head_index[0] = readrel1327->getIndex(ord1326, false);
      std::vector<u16> ord1328({1, 0});
      slog::Relation* readrel1329 = db->getRelation("ref");
      refindex1297 = readrel1329->getIndex(ord1328, false);
      std::vector<u16> ord1330({1, 0});
      slog::Relation* readrel1331 = db->getRelation("ref");
      refindex1298 = readrel1331->getIndex(ord1330, false);
      std::vector<u16> ord1332({1, 2, 0});
      slog::Relation* readrel1333 = db->getRelation("lambda");
      lambdaindex1299 = readrel1333->getIndex(ord1332, false);
      std::vector<u16> ord1334({1, 0});
      slog::Relation* readrel1335 = db->getRelation("ref");
      refindex1300 = readrel1335->getIndex(ord1334, false);
      std::vector<u16> ord1336({1, 2, 0});
      slog::Relation* readrel1337 = db->getRelation("lambda");
      lambdaindex1301 = readrel1337->getIndex(ord1336, false);
      std::vector<u16> ord1338({1, 0});
      slog::Relation* readrel1339 = db->getRelation("ref");
      refindex1302 = readrel1339->getIndex(ord1338, false);
      std::vector<u16> ord1340({1, 0});
      slog::Relation* readrel1341 = db->getRelation("ref");
      refindex1303 = readrel1341->getIndex(ord1340, false);
      std::vector<u16> ord1342({1, 0});
      slog::Relation* readrel1343 = db->getRelation("ref");
      refindex1304 = readrel1343->getIndex(ord1342, false);
      std::vector<u16> ord1344({1, 2, 0});
      slog::Relation* readrel1345 = db->getRelation("lambda");
      lambdaindex1305 = readrel1345->getIndex(ord1344, false);
      std::vector<u16> ord1346({1, 2, 0});
      slog::Relation* readrel1347 = db->getRelation("lambda");
      lambdaindex1306 = readrel1347->getIndex(ord1346, false);
      std::vector<u16> ord1348({1, 2, 0});
      slog::Relation* readrel1349 = db->getRelation("lambda");
      lambdaindex1307 = readrel1349->getIndex(ord1348, false);
      std::vector<u16> ord1350({1, 2, 0});
      slog::Relation* readrel1351 = db->getRelation("lambda");
      lambdaindex1308 = readrel1351->getIndex(ord1350, false);
      std::vector<u16> ord1352({2, 0, 1});
      slog::Relation* readrel1353 = db->getRelation("app");
      appindex1309 = readrel1353->getIndex(ord1352, false);
      std::vector<u16> ord1354({1, 0});
      slog::Relation* readrel1355 = db->getRelation("ref");
      refindex1310 = readrel1355->getIndex(ord1354, false);
      std::vector<u16> ord1356({1, 2, 0});
      slog::Relation* readrel1357 = db->getRelation("lambda");
      lambdaindex1311 = readrel1357->getIndex(ord1356, false);
      std::vector<u16> ord1358({1, 0});
      slog::Relation* readrel1359 = db->getRelation("ref");
      refindex1312 = readrel1359->getIndex(ord1358, false);
      std::vector<u16> ord1360({1, 2, 0});
      slog::Relation* readrel1361 = db->getRelation("lambda");
      lambdaindex1313 = readrel1361->getIndex(ord1360, false);
      std::vector<u16> ord1362({1, 0});
      slog::Relation* readrel1363 = db->getRelation("ref");
      refindex1314 = readrel1363->getIndex(ord1362, false);
      std::vector<u16> ord1364({2, 0, 1});
      slog::Relation* readrel1365 = db->getRelation("app");
      appindex1315 = readrel1365->getIndex(ord1364, false);
      std::vector<u16> ord1366({1, 0});
      slog::Relation* readrel1367 = db->getRelation("ref");
      refindex1316 = readrel1367->getIndex(ord1366, false);
      std::vector<u16> ord1368({1, 2, 0});
      slog::Relation* readrel1369 = db->getRelation("app");
      appindex1317 = readrel1369->getIndex(ord1368, false);
      std::vector<u16> ord1370({1, 0});
      slog::Relation* readrel1371 = db->getRelation("ref");
      refindex1318 = readrel1371->getIndex(ord1370, false);
      std::vector<u16> ord1372({1, 2, 0});
      slog::Relation* readrel1373 = db->getRelation("app");
      appindex1319 = readrel1373->getIndex(ord1372, false);
      std::vector<u16> ord1374({1, 2, 0});
      slog::Relation* readrel1375 = db->getRelation("app");
      appindex1320 = readrel1375->getIndex(ord1374, false);
      std::vector<u16> ord1376({1, 2, 0});
      slog::Relation* readrel1377 = db->getRelation("lambda");
      lambdaindex1321 = readrel1377->getIndex(ord1376, false);
      std::vector<u16> ord1378({1, 2, 0});
      slog::Relation* readrel1379 = db->getRelation("lambda");
      lambdaindex1322 = readrel1379->getIndex(ord1378, false);
      std::vector<u16> ord1380({1, 2, 0});
      slog::Relation* readrel1381 = db->getRelation("lambda");
      lambdaindex1323 = readrel1381->getIndex(ord1380, false);
      std::vector<u16> ord1382({1, 2, 0});
      slog::Relation* readrel1383 = db->getRelation("app");
      appindex1324 = readrel1383->getIndex(ord1382, false);
  
    }
    ReadTask1325(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c11 = v_constaaaad65142343c54348db5d0;
      u64 v_c6 = v_const7b8fd91ee9ff10cfbb8066bf;
      u64 v_c7 = v_const615ad01b1c532bb6634df115;
      u64 v_c8 = v_const4492fd5fa4baacfebd29f5e5;
      u64 v_c10 = v_consteb793a6f75d6cfe49d3c2c90;
      u64 v_c9 = v_consta32d5a443def48e6d64c6f4b;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex1297, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m1384) {
        u64 v_c15 = m1384[1];
        if (!slog::exists_probe<2,1>(refindex1298, std::array<u64,2>{v_c7, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1299, std::array<u64,3>{v_c7, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1300, std::array<u64,2>{v_c6, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1301, std::array<u64,3>{v_c6, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1302, std::array<u64,2>{v_c9, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1303, std::array<u64,2>{v_c11, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1304, std::array<u64,2>{v_c10, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1305, std::array<u64,3>{v_c9, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1306, std::array<u64,3>{v_c10, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1307, std::array<u64,3>{v_c11, 0, 0})) return;
        slog::join_probe<3,2>(lambdaindex1308, std::array<u64,3>{v_c8, v_c15, 0}, [&](const std::array<u64,3>& m1385) {
          u64 v_c65 = m1385[2];
          if (!slog::exists_probe<3,1>(appindex1309, std::array<u64,3>{v_c65, 0, 0})) return;
          slog::join_probe<2,1>(refindex1310, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m1386) {
            u64 v_c16 = m1386[1];
            slog::join_probe<3,2>(lambdaindex1311, std::array<u64,3>{v_c7, v_c16, 0}, [&](const std::array<u64,3>& m1387) {
              u64 v_c66 = m1387[2];
              slog::join_probe<2,1>(refindex1312, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m1388) {
                u64 v_c17 = m1388[1];
                slog::join_probe<3,2>(lambdaindex1313, std::array<u64,3>{v_c6, v_c17, 0}, [&](const std::array<u64,3>& m1389) {
                  u64 v_c67 = m1389[2];
                  slog::join_probe<2,1>(refindex1314, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m1390) {
                    u64 v_c14 = m1390[1];
                    if (!slog::exists_probe<3,1>(appindex1315, std::array<u64,3>{v_c14, 0, 0})) return;
                    slog::join_probe<2,1>(refindex1316, std::array<u64,2>{v_c11, 0}, [&](const std::array<u64,2>& m1391) {
                      u64 v_c12 = m1391[1];
                      if (!slog::exists_probe<3,1>(appindex1317, std::array<u64,3>{v_c12, 0, 0})) return;
                      slog::join_probe<2,1>(refindex1318, std::array<u64,2>{v_c10, 0}, [&](const std::array<u64,2>& m1392) {
                        u64 v_c13 = m1392[1];
                        slog::join_probe<3,2>(appindex1319, std::array<u64,3>{v_c12, v_c13, 0}, [&](const std::array<u64,3>& m1393) {
                          u64 v_c63 = m1393[2];
                          slog::join_probe<3,2>(appindex1320, std::array<u64,3>{v_c63, v_c14, 0}, [&](const std::array<u64,3>& m1394) {
                            u64 v_c64 = m1394[2];
                            slog::join_probe<3,2>(lambdaindex1321, std::array<u64,3>{v_c9, v_c64, 0}, [&](const std::array<u64,3>& m1395) {
                              u64 v_c152 = m1395[2];
                              slog::join_probe<3,2>(lambdaindex1322, std::array<u64,3>{v_c10, v_c152, 0}, [&](const std::array<u64,3>& m1396) {
                                u64 v_c153 = m1396[2];
                                slog::join_probe<3,2>(lambdaindex1323, std::array<u64,3>{v_c11, v_c153, 0}, [&](const std::array<u64,3>& m1397) {
                                  u64 v_c192 = m1397[2];
                                  slog::join_probe<3,2>(appindex1324, std::array<u64,3>{v_c192, v_c65, 0}, [&](const std::array<u64,3>& m1398) {
                                    u64 v_c193 = m1398[2];
                                    ++_fires;
                                    slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c193, v_c66}, std::array<u16,3>{1, 2, 0});
                                  });
                                });
                              });
                            });
                          });
                        });
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
      s->addTaskSeeded(phase_read, new ReadTask1325(db,b));
  // (crule (pre (let __tconst4Sko246 consteb793a6f75d6cfe49d3c2c90) (let __tconst4N2q248 constaaaad65142343c54348db5d0) (let __tconst2x2f244 consta32d5a443def48e6d64c6f4b) (let __tconst7sqz226 const7b8fd91ee9ff10cfbb8066bf) (let __tconst1EUj230 const615ad01b1c532bb6634df115) (let __tconst2VuQ234 const4492fd5fa4baacfebd29f5e5)) (seeded) (body (join ref (1 0) 1 __tconst2VuQ234 __t2PLq233) (exists ref (1 0) 1 __tconst1EUj230) (exists lambda (1 2 0) 1 __tconst1EUj230) (exists ref (1 0) 1 __tconst7sqz226) (exists lambda (1 2 0) 1 __tconst7sqz226) (exists ref (1 0) 1 __tconst2x2f244) (exists ref (1 0) 1 __tconst4N2q248) (exists ref (1 0) 1 __tconst4Sko246) (exists lambda (1 2 0) 1 __tconst2x2f244) (exists lambda (1 2 0) 1 __tconst4Sko246) (join lambda (1 2 0) 2 __tconst2VuQ234 __t2PLq233 __t45rU235) (join ref (1 0) 1 __tconst1EUj230 __t3WVP229) (join lambda (1 2 0) 2 __tconst1EUj230 __t3WVP229 __t5ryk231) (join ref (1 0) 1 __tconst7sqz226 __t5APF225) (join lambda (1 2 0) 2 __tconst7sqz226 __t5APF225 __t2BAX227) (join ref (1 0) 1 __tconst2x2f244 __t3pbc237) (exists app (2 0 1) 1 __t3pbc237) (join ref (1 0) 1 __tconst4N2q248 __t6KL4241) (exists app (1 2 0) 1 __t6KL4241) (join ref (1 0) 1 __tconst4Sko246 __t16jv239) (join app (1 2 0) 2 __t6KL4241 __t16jv239 __t4wvK242) (join app (1 2 0) 2 __t4wvK242 __t3pbc237 __t5h6K243) (join lambda (1 2 0) 2 __tconst2x2f244 __t5h6K243 __t3laZ245) (join lambda (1 2 0) 2 __tconst4Sko246 __t3laZ245 __t7yz1247)) (head (mkstruct lambda (1 2 0) __t5uyC249 __tconst4N2q248 __t7yz1247)) mcfa-counting.slog:272 #f)
  class ReadTask1423 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex1399;  slog::Index** refindex1400;  slog::Index** lambdaindex1401;  slog::Index** refindex1402;  slog::Index** lambdaindex1403;  slog::Index** refindex1404;  slog::Index** refindex1405;  slog::Index** refindex1406;  slog::Index** lambdaindex1407;  slog::Index** lambdaindex1408;  slog::Index** lambdaindex1409;  slog::Index** refindex1410;  slog::Index** lambdaindex1411;  slog::Index** refindex1412;  slog::Index** lambdaindex1413;  slog::Index** refindex1414;  slog::Index** appindex1415;  slog::Index** refindex1416;  slog::Index** appindex1417;  slog::Index** refindex1418;  slog::Index** appindex1419;  slog::Index** appindex1420;  slog::Index** lambdaindex1421;  slog::Index** lambdaindex1422;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      std::vector<u16> ord1424({1, 2, 0});
      slog::Relation* readrel1425 = db->getRelation("lambda");
      head_index[0] = readrel1425->getIndex(ord1424, false);
      std::vector<u16> ord1426({1, 0});
      slog::Relation* readrel1427 = db->getRelation("ref");
      refindex1399 = readrel1427->getIndex(ord1426, false);
      std::vector<u16> ord1428({1, 0});
      slog::Relation* readrel1429 = db->getRelation("ref");
      refindex1400 = readrel1429->getIndex(ord1428, false);
      std::vector<u16> ord1430({1, 2, 0});
      slog::Relation* readrel1431 = db->getRelation("lambda");
      lambdaindex1401 = readrel1431->getIndex(ord1430, false);
      std::vector<u16> ord1432({1, 0});
      slog::Relation* readrel1433 = db->getRelation("ref");
      refindex1402 = readrel1433->getIndex(ord1432, false);
      std::vector<u16> ord1434({1, 2, 0});
      slog::Relation* readrel1435 = db->getRelation("lambda");
      lambdaindex1403 = readrel1435->getIndex(ord1434, false);
      std::vector<u16> ord1436({1, 0});
      slog::Relation* readrel1437 = db->getRelation("ref");
      refindex1404 = readrel1437->getIndex(ord1436, false);
      std::vector<u16> ord1438({1, 0});
      slog::Relation* readrel1439 = db->getRelation("ref");
      refindex1405 = readrel1439->getIndex(ord1438, false);
      std::vector<u16> ord1440({1, 0});
      slog::Relation* readrel1441 = db->getRelation("ref");
      refindex1406 = readrel1441->getIndex(ord1440, false);
      std::vector<u16> ord1442({1, 2, 0});
      slog::Relation* readrel1443 = db->getRelation("lambda");
      lambdaindex1407 = readrel1443->getIndex(ord1442, false);
      std::vector<u16> ord1444({1, 2, 0});
      slog::Relation* readrel1445 = db->getRelation("lambda");
      lambdaindex1408 = readrel1445->getIndex(ord1444, false);
      std::vector<u16> ord1446({1, 2, 0});
      slog::Relation* readrel1447 = db->getRelation("lambda");
      lambdaindex1409 = readrel1447->getIndex(ord1446, false);
      std::vector<u16> ord1448({1, 0});
      slog::Relation* readrel1449 = db->getRelation("ref");
      refindex1410 = readrel1449->getIndex(ord1448, false);
      std::vector<u16> ord1450({1, 2, 0});
      slog::Relation* readrel1451 = db->getRelation("lambda");
      lambdaindex1411 = readrel1451->getIndex(ord1450, false);
      std::vector<u16> ord1452({1, 0});
      slog::Relation* readrel1453 = db->getRelation("ref");
      refindex1412 = readrel1453->getIndex(ord1452, false);
      std::vector<u16> ord1454({1, 2, 0});
      slog::Relation* readrel1455 = db->getRelation("lambda");
      lambdaindex1413 = readrel1455->getIndex(ord1454, false);
      std::vector<u16> ord1456({1, 0});
      slog::Relation* readrel1457 = db->getRelation("ref");
      refindex1414 = readrel1457->getIndex(ord1456, false);
      std::vector<u16> ord1458({2, 0, 1});
      slog::Relation* readrel1459 = db->getRelation("app");
      appindex1415 = readrel1459->getIndex(ord1458, false);
      std::vector<u16> ord1460({1, 0});
      slog::Relation* readrel1461 = db->getRelation("ref");
      refindex1416 = readrel1461->getIndex(ord1460, false);
      std::vector<u16> ord1462({1, 2, 0});
      slog::Relation* readrel1463 = db->getRelation("app");
      appindex1417 = readrel1463->getIndex(ord1462, false);
      std::vector<u16> ord1464({1, 0});
      slog::Relation* readrel1465 = db->getRelation("ref");
      refindex1418 = readrel1465->getIndex(ord1464, false);
      std::vector<u16> ord1466({1, 2, 0});
      slog::Relation* readrel1467 = db->getRelation("app");
      appindex1419 = readrel1467->getIndex(ord1466, false);
      std::vector<u16> ord1468({1, 2, 0});
      slog::Relation* readrel1469 = db->getRelation("app");
      appindex1420 = readrel1469->getIndex(ord1468, false);
      std::vector<u16> ord1470({1, 2, 0});
      slog::Relation* readrel1471 = db->getRelation("lambda");
      lambdaindex1421 = readrel1471->getIndex(ord1470, false);
      std::vector<u16> ord1472({1, 2, 0});
      slog::Relation* readrel1473 = db->getRelation("lambda");
      lambdaindex1422 = readrel1473->getIndex(ord1472, false);
  
    }
    ReadTask1423(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c10 = v_consteb793a6f75d6cfe49d3c2c90;
      u64 v_c11 = v_constaaaad65142343c54348db5d0;
      u64 v_c9 = v_consta32d5a443def48e6d64c6f4b;
      u64 v_c6 = v_const7b8fd91ee9ff10cfbb8066bf;
      u64 v_c7 = v_const615ad01b1c532bb6634df115;
      u64 v_c8 = v_const4492fd5fa4baacfebd29f5e5;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex1399, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m1474) {
        u64 v_c15 = m1474[1];
        if (!slog::exists_probe<2,1>(refindex1400, std::array<u64,2>{v_c7, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1401, std::array<u64,3>{v_c7, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1402, std::array<u64,2>{v_c6, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1403, std::array<u64,3>{v_c6, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1404, std::array<u64,2>{v_c9, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1405, std::array<u64,2>{v_c11, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1406, std::array<u64,2>{v_c10, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1407, std::array<u64,3>{v_c9, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1408, std::array<u64,3>{v_c10, 0, 0})) return;
        slog::join_probe<3,2>(lambdaindex1409, std::array<u64,3>{v_c8, v_c15, 0}, [&](const std::array<u64,3>& m1475) {
          u64 v_c65 = m1475[2];
          slog::join_probe<2,1>(refindex1410, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m1476) {
            u64 v_c16 = m1476[1];
            slog::join_probe<3,2>(lambdaindex1411, std::array<u64,3>{v_c7, v_c16, 0}, [&](const std::array<u64,3>& m1477) {
              u64 v_c66 = m1477[2];
              slog::join_probe<2,1>(refindex1412, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m1478) {
                u64 v_c17 = m1478[1];
                slog::join_probe<3,2>(lambdaindex1413, std::array<u64,3>{v_c6, v_c17, 0}, [&](const std::array<u64,3>& m1479) {
                  u64 v_c67 = m1479[2];
                  slog::join_probe<2,1>(refindex1414, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m1480) {
                    u64 v_c14 = m1480[1];
                    if (!slog::exists_probe<3,1>(appindex1415, std::array<u64,3>{v_c14, 0, 0})) return;
                    slog::join_probe<2,1>(refindex1416, std::array<u64,2>{v_c11, 0}, [&](const std::array<u64,2>& m1481) {
                      u64 v_c12 = m1481[1];
                      if (!slog::exists_probe<3,1>(appindex1417, std::array<u64,3>{v_c12, 0, 0})) return;
                      slog::join_probe<2,1>(refindex1418, std::array<u64,2>{v_c10, 0}, [&](const std::array<u64,2>& m1482) {
                        u64 v_c13 = m1482[1];
                        slog::join_probe<3,2>(appindex1419, std::array<u64,3>{v_c12, v_c13, 0}, [&](const std::array<u64,3>& m1483) {
                          u64 v_c63 = m1483[2];
                          slog::join_probe<3,2>(appindex1420, std::array<u64,3>{v_c63, v_c14, 0}, [&](const std::array<u64,3>& m1484) {
                            u64 v_c64 = m1484[2];
                            slog::join_probe<3,2>(lambdaindex1421, std::array<u64,3>{v_c9, v_c64, 0}, [&](const std::array<u64,3>& m1485) {
                              u64 v_c152 = m1485[2];
                              slog::join_probe<3,2>(lambdaindex1422, std::array<u64,3>{v_c10, v_c152, 0}, [&](const std::array<u64,3>& m1486) {
                                u64 v_c153 = m1486[2];
                                ++_fires;
                                slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c11, v_c153}, std::array<u16,3>{1, 2, 0});
                              });
                            });
                          });
                        });
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
      s->addTaskSeeded(phase_read, new ReadTask1423(db,b));
  // (crule (pre (let __tconst9zoW125 const7c7d2cfc66f4d976987d2d20) (let __tconst0vRf84 conste58dec6bca6f63ef79c3b755) (let __tconst4V4L122 const6bc0ba365ada70df115e1785) (let __tconst4Zcr91 const9a67f28c6b77e842f439a84a) (let __tconst82U8119 consta8180db1c2f300980314f910) (let __tconst4BKz104 const0f8748be649f8ee4066bb1d7) (let __tconst3wDH116 constd5f017533ea574d5f9b3400c) (let __tconst3ktF111 const990b444cbd47632035b2fa1a) (let __tconst5nWJ102 const4f84f41d89b6b717419b4eaa)) (probe lambda (1 2 0) 1 __tconst9zoW125 __t3cyj124 __t4GT8126) (body (exists lambda (1 2 0) 1 __tconst0vRf84) (exists ref (1 0) 1 __tconst4Zcr91) (exists ref (1 0) 1 __tconst9zoW125) (exists lambda (1 2 0) 1 __tconst4Zcr91) (exists lambda (1 2 0) 1 __tconst4V4L122) (exists ref (1 0) 1 __tconst4V4L122) (exists ref (1 0) 1 __tconst4BKz104) (exists lambda (1 2 0) 1 __tconst4BKz104) (exists lambda (1 2 0) 1 __tconst82U8119) (exists ref (1 0) 1 __tconst3wDH116) (exists ref (1 0) 1 __tconst5nWJ102) (exists lambda (1 2 0) 1 __tconst5nWJ102) (exists lambda (1 2 0) 1 __tconst3wDH116) (exists lambda (1 2 0) 1 __tconst3ktF111) (exists ref (1 0) 1 __tconst3ktF111) (join ref (1 0) 1 __tconst0vRf84 __t2duR83) (join lambda (1 2 0) 2 __tconst0vRf84 __t2duR83 __t87vL85) (join ref (1 0) 1 __tconst4Zcr91 __t0C9F87) (exists app (2 0 1) 1 __t0C9F87) (join ref (1 0) 1 __tconst9zoW125 __t3Q2G89) (join app (1 2 0) 2 __t3Q2G89 __t0C9F87 __t2Eqd90) (join lambda (1 2 0) 2 __tconst4Zcr91 __t2Eqd90 __t3pgm92) (join app (2 0 1) 2 __t3pgm92 __t3cyj124 __t5iMg123) (join lambda (0 1 2) 2 __t5iMg123 __tconst4V4L122 __t1GdP121) (join ref (1 0) 1 __tconst4V4L122 __t7aew98) (exists app (1 2 0) 1 __t7aew98) (join ref (1 0) 1 __tconst4BKz104 __t8C0a94) (join lambda (1 2 0) 2 __tconst4BKz104 __t8C0a94 __t4fDK96) (join app (1 2 0) 2 __t7aew98 __t4fDK96 __t7TEO99) (join app (2 0 1) 2 __t7TEO99 __t1GdP121 __t3SEs120) (join lambda (0 1 2) 2 __t3SEs120 __tconst82U8119 __t50Kk118) (join ref (1 0) 1 __tconst3wDH116 __t3wir114) (exists app (1 2 0) 1 __t3wir114) (join ref (1 0) 1 __tconst5nWJ102 __t5MaG101) (join lambda (1 2 0) 2 __tconst5nWJ102 __t5MaG101 __t35jA103) (join lambda (1 2 0) 2 __tconst4BKz104 __t35jA103 __t6RuY105) (join app (1 2 0) 2 __t7aew98 __t6RuY105 __t2Z7m108) (join app (2 0 1) 2 __t2Z7m108 __t50Kk118 __t7CwH117) (join lambda (0 1 2) 2 __t7CwH117 __tconst3wDH116 __t44OM115) (join app (0 1 2) 2 __t44OM115 __t3wir114 __t8GWA112) (join lambda (0 1 2) 2 __t8GWA112 __tconst3ktF111 __t7ohz110) (join ref (0 1) 2 __t7ohz110 __tconst3ktF111)) (head (mkstruct app (1 2 0) __t6xIu127 __t4GT8126 __t87vL85)) mcfa-counting.slog:241 #f)
  class ReadTask1529 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** lambdaindex1487;  slog::Index** refindex1488;  slog::Index** refindex1489;  slog::Index** lambdaindex1490;  slog::Index** lambdaindex1491;  slog::Index** refindex1492;  slog::Index** refindex1493;  slog::Index** lambdaindex1494;  slog::Index** lambdaindex1495;  slog::Index** refindex1496;  slog::Index** refindex1497;  slog::Index** lambdaindex1498;  slog::Index** lambdaindex1499;  slog::Index** lambdaindex1500;  slog::Index** refindex1501;  slog::Index** refindex1502;  slog::Index** lambdaindex1503;  slog::Index** refindex1504;  slog::Index** appindex1505;  slog::Index** refindex1506;  slog::Index** appindex1507;  slog::Index** lambdaindex1508;  slog::Index** appindex1509;  slog::Index** lambdaindex1510;  slog::Index** refindex1511;  slog::Index** appindex1512;  slog::Index** refindex1513;  slog::Index** lambdaindex1514;  slog::Index** appindex1515;  slog::Index** appindex1516;  slog::Index** lambdaindex1517;  slog::Index** refindex1518;  slog::Index** appindex1519;  slog::Index** refindex1520;  slog::Index** lambdaindex1521;  slog::Index** lambdaindex1522;  slog::Index** appindex1523;  slog::Index** appindex1524;  slog::Index** lambdaindex1525;  slog::Index** appindex1526;  slog::Index** lambdaindex1527;  slog::Index** refindex1528;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord1530({1, 2, 0});
      slog::Relation* readrel1531 = db->getRelation("lambda");
      driver_index = readrel1531->getIndex(ord1530, true);
      std::vector<u16> ord1532({1, 2, 0});
      slog::Relation* readrel1533 = db->getRelation("lambda");
      lambdaindex1487 = readrel1533->getIndex(ord1532, false);
      std::vector<u16> ord1534({1, 0});
      slog::Relation* readrel1535 = db->getRelation("ref");
      refindex1488 = readrel1535->getIndex(ord1534, false);
      std::vector<u16> ord1536({1, 0});
      slog::Relation* readrel1537 = db->getRelation("ref");
      refindex1489 = readrel1537->getIndex(ord1536, false);
      std::vector<u16> ord1538({1, 2, 0});
      slog::Relation* readrel1539 = db->getRelation("lambda");
      lambdaindex1490 = readrel1539->getIndex(ord1538, false);
      std::vector<u16> ord1540({1, 2, 0});
      slog::Relation* readrel1541 = db->getRelation("lambda");
      lambdaindex1491 = readrel1541->getIndex(ord1540, false);
      std::vector<u16> ord1542({1, 0});
      slog::Relation* readrel1543 = db->getRelation("ref");
      refindex1492 = readrel1543->getIndex(ord1542, false);
      std::vector<u16> ord1544({1, 0});
      slog::Relation* readrel1545 = db->getRelation("ref");
      refindex1493 = readrel1545->getIndex(ord1544, false);
      std::vector<u16> ord1546({1, 2, 0});
      slog::Relation* readrel1547 = db->getRelation("lambda");
      lambdaindex1494 = readrel1547->getIndex(ord1546, false);
      std::vector<u16> ord1548({1, 2, 0});
      slog::Relation* readrel1549 = db->getRelation("lambda");
      lambdaindex1495 = readrel1549->getIndex(ord1548, false);
      std::vector<u16> ord1550({1, 0});
      slog::Relation* readrel1551 = db->getRelation("ref");
      refindex1496 = readrel1551->getIndex(ord1550, false);
      std::vector<u16> ord1552({1, 0});
      slog::Relation* readrel1553 = db->getRelation("ref");
      refindex1497 = readrel1553->getIndex(ord1552, false);
      std::vector<u16> ord1554({1, 2, 0});
      slog::Relation* readrel1555 = db->getRelation("lambda");
      lambdaindex1498 = readrel1555->getIndex(ord1554, false);
      std::vector<u16> ord1556({1, 2, 0});
      slog::Relation* readrel1557 = db->getRelation("lambda");
      lambdaindex1499 = readrel1557->getIndex(ord1556, false);
      std::vector<u16> ord1558({1, 2, 0});
      slog::Relation* readrel1559 = db->getRelation("lambda");
      lambdaindex1500 = readrel1559->getIndex(ord1558, false);
      std::vector<u16> ord1560({1, 0});
      slog::Relation* readrel1561 = db->getRelation("ref");
      refindex1501 = readrel1561->getIndex(ord1560, false);
      std::vector<u16> ord1562({1, 0});
      slog::Relation* readrel1563 = db->getRelation("ref");
      refindex1502 = readrel1563->getIndex(ord1562, false);
      std::vector<u16> ord1564({1, 2, 0});
      slog::Relation* readrel1565 = db->getRelation("lambda");
      lambdaindex1503 = readrel1565->getIndex(ord1564, false);
      std::vector<u16> ord1566({1, 0});
      slog::Relation* readrel1567 = db->getRelation("ref");
      refindex1504 = readrel1567->getIndex(ord1566, false);
      std::vector<u16> ord1568({2, 0, 1});
      slog::Relation* readrel1569 = db->getRelation("app");
      appindex1505 = readrel1569->getIndex(ord1568, false);
      std::vector<u16> ord1570({1, 0});
      slog::Relation* readrel1571 = db->getRelation("ref");
      refindex1506 = readrel1571->getIndex(ord1570, false);
      std::vector<u16> ord1572({1, 2, 0});
      slog::Relation* readrel1573 = db->getRelation("app");
      appindex1507 = readrel1573->getIndex(ord1572, false);
      std::vector<u16> ord1574({1, 2, 0});
      slog::Relation* readrel1575 = db->getRelation("lambda");
      lambdaindex1508 = readrel1575->getIndex(ord1574, false);
      std::vector<u16> ord1576({2, 0, 1});
      slog::Relation* readrel1577 = db->getRelation("app");
      appindex1509 = readrel1577->getIndex(ord1576, false);
      std::vector<u16> ord1578({0, 1, 2});
      slog::Relation* readrel1579 = db->getRelation("lambda");
      lambdaindex1510 = readrel1579->getIndex(ord1578, false);
      std::vector<u16> ord1580({1, 0});
      slog::Relation* readrel1581 = db->getRelation("ref");
      refindex1511 = readrel1581->getIndex(ord1580, false);
      std::vector<u16> ord1582({1, 2, 0});
      slog::Relation* readrel1583 = db->getRelation("app");
      appindex1512 = readrel1583->getIndex(ord1582, false);
      std::vector<u16> ord1584({1, 0});
      slog::Relation* readrel1585 = db->getRelation("ref");
      refindex1513 = readrel1585->getIndex(ord1584, false);
      std::vector<u16> ord1586({1, 2, 0});
      slog::Relation* readrel1587 = db->getRelation("lambda");
      lambdaindex1514 = readrel1587->getIndex(ord1586, false);
      std::vector<u16> ord1588({1, 2, 0});
      slog::Relation* readrel1589 = db->getRelation("app");
      appindex1515 = readrel1589->getIndex(ord1588, false);
      std::vector<u16> ord1590({2, 0, 1});
      slog::Relation* readrel1591 = db->getRelation("app");
      appindex1516 = readrel1591->getIndex(ord1590, false);
      std::vector<u16> ord1592({0, 1, 2});
      slog::Relation* readrel1593 = db->getRelation("lambda");
      lambdaindex1517 = readrel1593->getIndex(ord1592, false);
      std::vector<u16> ord1594({1, 0});
      slog::Relation* readrel1595 = db->getRelation("ref");
      refindex1518 = readrel1595->getIndex(ord1594, false);
      std::vector<u16> ord1596({1, 2, 0});
      slog::Relation* readrel1597 = db->getRelation("app");
      appindex1519 = readrel1597->getIndex(ord1596, false);
      std::vector<u16> ord1598({1, 0});
      slog::Relation* readrel1599 = db->getRelation("ref");
      refindex1520 = readrel1599->getIndex(ord1598, false);
      std::vector<u16> ord1600({1, 2, 0});
      slog::Relation* readrel1601 = db->getRelation("lambda");
      lambdaindex1521 = readrel1601->getIndex(ord1600, false);
      std::vector<u16> ord1602({1, 2, 0});
      slog::Relation* readrel1603 = db->getRelation("lambda");
      lambdaindex1522 = readrel1603->getIndex(ord1602, false);
      std::vector<u16> ord1604({1, 2, 0});
      slog::Relation* readrel1605 = db->getRelation("app");
      appindex1523 = readrel1605->getIndex(ord1604, false);
      std::vector<u16> ord1606({2, 0, 1});
      slog::Relation* readrel1607 = db->getRelation("app");
      appindex1524 = readrel1607->getIndex(ord1606, false);
      std::vector<u16> ord1608({0, 1, 2});
      slog::Relation* readrel1609 = db->getRelation("lambda");
      lambdaindex1525 = readrel1609->getIndex(ord1608, false);
      std::vector<u16> ord1610({0, 1, 2});
      slog::Relation* readrel1611 = db->getRelation("app");
      appindex1526 = readrel1611->getIndex(ord1610, false);
      std::vector<u16> ord1612({0, 1, 2});
      slog::Relation* readrel1613 = db->getRelation("lambda");
      lambdaindex1527 = readrel1613->getIndex(ord1612, false);
      std::vector<u16> ord1614({0, 1});
      slog::Relation* readrel1615 = db->getRelation("ref");
      refindex1528 = readrel1615->getIndex(ord1614, false);
  
    }
    ReadTask1529(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c101 = v_const7c7d2cfc66f4d976987d2d20;
      u64 v_c102 = v_conste58dec6bca6f63ef79c3b755;
      u64 v_c103 = v_const6bc0ba365ada70df115e1785;
      u64 v_c104 = v_const9a67f28c6b77e842f439a84a;
      u64 v_c105 = v_consta8180db1c2f300980314f910;
      u64 v_c106 = v_const0f8748be649f8ee4066bb1d7;
      u64 v_c107 = v_constd5f017533ea574d5f9b3400c;
      u64 v_c108 = v_const990b444cbd47632035b2fa1a;
      u64 v_c109 = v_const4f84f41d89b6b717419b4eaa;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c101, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1616) {
        u64 v_c114 = m1616[1];
        u64 v_c111 = m1616[2];
        if (buckethash(v_c114) != bucket) return;
        if (!slog::exists_probe<3,1>(lambdaindex1487, std::array<u64,3>{v_c102, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1488, std::array<u64,2>{v_c104, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1489, std::array<u64,2>{v_c101, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1490, std::array<u64,3>{v_c104, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1491, std::array<u64,3>{v_c103, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1492, std::array<u64,2>{v_c103, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1493, std::array<u64,2>{v_c106, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1494, std::array<u64,3>{v_c106, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1495, std::array<u64,3>{v_c105, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1496, std::array<u64,2>{v_c107, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1497, std::array<u64,2>{v_c109, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1498, std::array<u64,3>{v_c109, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1499, std::array<u64,3>{v_c107, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1500, std::array<u64,3>{v_c108, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1501, std::array<u64,2>{v_c108, 0})) return;
        slog::join_probe<2,1>(refindex1502, std::array<u64,2>{v_c102, 0}, [&](const std::array<u64,2>& m1617) {
          u64 v_c113 = m1617[1];
          slog::join_probe<3,2>(lambdaindex1503, std::array<u64,3>{v_c102, v_c113, 0}, [&](const std::array<u64,3>& m1618) {
            u64 v_c112 = m1618[2];
            slog::join_probe<2,1>(refindex1504, std::array<u64,2>{v_c104, 0}, [&](const std::array<u64,2>& m1619) {
              u64 v_c115 = m1619[1];
              if (!slog::exists_probe<3,1>(appindex1505, std::array<u64,3>{v_c115, 0, 0})) return;
              slog::join_probe<2,1>(refindex1506, std::array<u64,2>{v_c101, 0}, [&](const std::array<u64,2>& m1620) {
                u64 v_c116 = m1620[1];
                slog::join_probe<3,2>(appindex1507, std::array<u64,3>{v_c116, v_c115, 0}, [&](const std::array<u64,3>& m1621) {
                  u64 v_c117 = m1621[2];
                  slog::join_probe<3,2>(lambdaindex1508, std::array<u64,3>{v_c104, v_c117, 0}, [&](const std::array<u64,3>& m1622) {
                    u64 v_c118 = m1622[2];
                    slog::join_probe<3,2>(appindex1509, std::array<u64,3>{v_c118, v_c114, 0}, [&](const std::array<u64,3>& m1623) {
                      u64 v_c119 = m1623[2];
                      slog::join_probe<3,2>(lambdaindex1510, std::array<u64,3>{v_c119, v_c103, 0}, [&](const std::array<u64,3>& m1624) {
                        u64 v_c120 = m1624[2];
                        slog::join_probe<2,1>(refindex1511, std::array<u64,2>{v_c103, 0}, [&](const std::array<u64,2>& m1625) {
                          u64 v_c121 = m1625[1];
                          if (!slog::exists_probe<3,1>(appindex1512, std::array<u64,3>{v_c121, 0, 0})) return;
                          slog::join_probe<2,1>(refindex1513, std::array<u64,2>{v_c106, 0}, [&](const std::array<u64,2>& m1626) {
                            u64 v_c122 = m1626[1];
                            slog::join_probe<3,2>(lambdaindex1514, std::array<u64,3>{v_c106, v_c122, 0}, [&](const std::array<u64,3>& m1627) {
                              u64 v_c123 = m1627[2];
                              slog::join_probe<3,2>(appindex1515, std::array<u64,3>{v_c121, v_c123, 0}, [&](const std::array<u64,3>& m1628) {
                                u64 v_c124 = m1628[2];
                                slog::join_probe<3,2>(appindex1516, std::array<u64,3>{v_c124, v_c120, 0}, [&](const std::array<u64,3>& m1629) {
                                  u64 v_c125 = m1629[2];
                                  slog::join_probe<3,2>(lambdaindex1517, std::array<u64,3>{v_c125, v_c105, 0}, [&](const std::array<u64,3>& m1630) {
                                    u64 v_c126 = m1630[2];
                                    slog::join_probe<2,1>(refindex1518, std::array<u64,2>{v_c107, 0}, [&](const std::array<u64,2>& m1631) {
                                      u64 v_c127 = m1631[1];
                                      if (!slog::exists_probe<3,1>(appindex1519, std::array<u64,3>{v_c127, 0, 0})) return;
                                      slog::join_probe<2,1>(refindex1520, std::array<u64,2>{v_c109, 0}, [&](const std::array<u64,2>& m1632) {
                                        u64 v_c128 = m1632[1];
                                        slog::join_probe<3,2>(lambdaindex1521, std::array<u64,3>{v_c109, v_c128, 0}, [&](const std::array<u64,3>& m1633) {
                                          u64 v_c129 = m1633[2];
                                          slog::join_probe<3,2>(lambdaindex1522, std::array<u64,3>{v_c106, v_c129, 0}, [&](const std::array<u64,3>& m1634) {
                                            u64 v_c130 = m1634[2];
                                            slog::join_probe<3,2>(appindex1523, std::array<u64,3>{v_c121, v_c130, 0}, [&](const std::array<u64,3>& m1635) {
                                              u64 v_c131 = m1635[2];
                                              slog::join_probe<3,2>(appindex1524, std::array<u64,3>{v_c131, v_c126, 0}, [&](const std::array<u64,3>& m1636) {
                                                u64 v_c132 = m1636[2];
                                                slog::join_probe<3,2>(lambdaindex1525, std::array<u64,3>{v_c132, v_c107, 0}, [&](const std::array<u64,3>& m1637) {
                                                  u64 v_c133 = m1637[2];
                                                  slog::join_probe<3,2>(appindex1526, std::array<u64,3>{v_c133, v_c127, 0}, [&](const std::array<u64,3>& m1638) {
                                                    u64 v_c134 = m1638[2];
                                                    slog::join_probe<3,2>(lambdaindex1527, std::array<u64,3>{v_c134, v_c108, 0}, [&](const std::array<u64,3>& m1639) {
                                                      u64 v_c135 = m1639[2];
                                                      slog::join_probe<2,2>(refindex1528, std::array<u64,2>{v_c135, v_c108}, [&](const std::array<u64,2>& m1640) {
                                                        ++_fires;
                                                        slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c111, v_c112}, std::array<u16,3>{1, 2, 0});
                                                      });
                                                    });
                                                  });
                                                });
                                              });
                                            });
                                          });
                                        });
                                      });
                                    });
                                  });
                                });
                              });
                            });
                          });
                        });
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
  
      if (_fires) db->bumpFires("mcfa-counting.slog:241", "delta:lambda", _fires);
  
      if (!_done)
      {
        ReadTask1529* _cont = new ReadTask1529(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1529(db,b), false);
  // (crule (pre (let __tconst0y6X73 const0aa6f87434af0222b916e97a) (let __tconst7zoP70 const227d34ceeba7a29aada993d4) (let __tconst1bfe65 const59ba3256d223f0d0a00d0633) (let __tconst0aL952 constd3d07026d47882ceca728218) (let __tconst8wN863 const7cd75b35aa30c3ddf04f9d57) (let __tconst0xUh47 constf700a82e218a86de572e1f7f)) (seeded) (body (join ref (1 0) 1 __tconst0aL952 __t5HQ450) (exists ref (1 0) 1 __tconst0xUh47) (exists lambda (1 2 0) 1 __tconst0xUh47) (exists app (1 2 0) 1 __t5HQ450) (exists ref (1 0) 1 __tconst1bfe65) (exists lambda (1 2 0) 1 __tconst1bfe65) (exists ref (1 0) 1 __tconst8wN863) (exists lambda (1 2 0) 1 __tconst8wN863) (join ref (1 0) 1 __tconst0y6X73 __t0QRr59) (exists app (1 2 0) 1 __t0QRr59) (join ref (1 0) 1 __tconst0xUh47 __t5vZb46) (join lambda (1 2 0) 2 __tconst0xUh47 __t5vZb46 __t50zW48) (join app (1 2 0) 2 __t5HQ450 __t50zW48 __t05NY51) (join ref (1 0) 1 __tconst1bfe65 __t2HsD55) (join lambda (1 2 0) 2 __tconst1bfe65 __t2HsD55 __t0uNb57) (join app (1 2 0) 2 __t0QRr59 __t0uNb57 __t81HE60) (join ref (1 0) 1 __tconst8wN863 __t1mkO62) (join lambda (1 2 0) 2 __tconst8wN863 __t1mkO62 __t3Dru64) (join lambda (1 2 0) 2 __tconst1bfe65 __t3Dru64 __t7JIT66)) (head (mkstruct app (1 2 0) __t5Ri569 __t0QRr59 __t7JIT66) (mkstruct lambda (1 2 0) __t3xtz53 __tconst0aL952 __t05NY51)) mcfa-counting.slog:287 #f)
  class ReadTask1660 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
  
  
  
  
  
    slog::Index** refindex1641;  slog::Index** refindex1642;  slog::Index** lambdaindex1643;  slog::Index** appindex1644;  slog::Index** refindex1645;  slog::Index** lambdaindex1646;  slog::Index** refindex1647;  slog::Index** lambdaindex1648;  slog::Index** refindex1649;  slog::Index** appindex1650;  slog::Index** refindex1651;  slog::Index** lambdaindex1652;  slog::Index** appindex1653;  slog::Index** refindex1654;  slog::Index** lambdaindex1655;  slog::Index** appindex1656;  slog::Index** refindex1657;  slog::Index** lambdaindex1658;  slog::Index** lambdaindex1659;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord1661({1, 2, 0});
      slog::Relation* readrel1662 = db->getRelation("app");
      head_index[0] = readrel1662->getIndex(ord1661, false);
      head_rel[1] = db->getRelation("lambda");
      std::vector<u16> ord1663({1, 2, 0});
      slog::Relation* readrel1664 = db->getRelation("lambda");
      head_index[1] = readrel1664->getIndex(ord1663, false);
      std::vector<u16> ord1665({1, 0});
      slog::Relation* readrel1666 = db->getRelation("ref");
      refindex1641 = readrel1666->getIndex(ord1665, false);
      std::vector<u16> ord1667({1, 0});
      slog::Relation* readrel1668 = db->getRelation("ref");
      refindex1642 = readrel1668->getIndex(ord1667, false);
      std::vector<u16> ord1669({1, 2, 0});
      slog::Relation* readrel1670 = db->getRelation("lambda");
      lambdaindex1643 = readrel1670->getIndex(ord1669, false);
      std::vector<u16> ord1671({1, 2, 0});
      slog::Relation* readrel1672 = db->getRelation("app");
      appindex1644 = readrel1672->getIndex(ord1671, false);
      std::vector<u16> ord1673({1, 0});
      slog::Relation* readrel1674 = db->getRelation("ref");
      refindex1645 = readrel1674->getIndex(ord1673, false);
      std::vector<u16> ord1675({1, 2, 0});
      slog::Relation* readrel1676 = db->getRelation("lambda");
      lambdaindex1646 = readrel1676->getIndex(ord1675, false);
      std::vector<u16> ord1677({1, 0});
      slog::Relation* readrel1678 = db->getRelation("ref");
      refindex1647 = readrel1678->getIndex(ord1677, false);
      std::vector<u16> ord1679({1, 2, 0});
      slog::Relation* readrel1680 = db->getRelation("lambda");
      lambdaindex1648 = readrel1680->getIndex(ord1679, false);
      std::vector<u16> ord1681({1, 0});
      slog::Relation* readrel1682 = db->getRelation("ref");
      refindex1649 = readrel1682->getIndex(ord1681, false);
      std::vector<u16> ord1683({1, 2, 0});
      slog::Relation* readrel1684 = db->getRelation("app");
      appindex1650 = readrel1684->getIndex(ord1683, false);
      std::vector<u16> ord1685({1, 0});
      slog::Relation* readrel1686 = db->getRelation("ref");
      refindex1651 = readrel1686->getIndex(ord1685, false);
      std::vector<u16> ord1687({1, 2, 0});
      slog::Relation* readrel1688 = db->getRelation("lambda");
      lambdaindex1652 = readrel1688->getIndex(ord1687, false);
      std::vector<u16> ord1689({1, 2, 0});
      slog::Relation* readrel1690 = db->getRelation("app");
      appindex1653 = readrel1690->getIndex(ord1689, false);
      std::vector<u16> ord1691({1, 0});
      slog::Relation* readrel1692 = db->getRelation("ref");
      refindex1654 = readrel1692->getIndex(ord1691, false);
      std::vector<u16> ord1693({1, 2, 0});
      slog::Relation* readrel1694 = db->getRelation("lambda");
      lambdaindex1655 = readrel1694->getIndex(ord1693, false);
      std::vector<u16> ord1695({1, 2, 0});
      slog::Relation* readrel1696 = db->getRelation("app");
      appindex1656 = readrel1696->getIndex(ord1695, false);
      std::vector<u16> ord1697({1, 0});
      slog::Relation* readrel1698 = db->getRelation("ref");
      refindex1657 = readrel1698->getIndex(ord1697, false);
      std::vector<u16> ord1699({1, 2, 0});
      slog::Relation* readrel1700 = db->getRelation("lambda");
      lambdaindex1658 = readrel1700->getIndex(ord1699, false);
      std::vector<u16> ord1701({1, 2, 0});
      slog::Relation* readrel1702 = db->getRelation("lambda");
      lambdaindex1659 = readrel1702->getIndex(ord1701, false);
  
    }
    ReadTask1660(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c194 = v_const0aa6f87434af0222b916e97a;
      u64 v_c195 = v_const227d34ceeba7a29aada993d4;
      u64 v_c196 = v_const59ba3256d223f0d0a00d0633;
      u64 v_c197 = v_constd3d07026d47882ceca728218;
      u64 v_c198 = v_const7cd75b35aa30c3ddf04f9d57;
      u64 v_c199 = v_constf700a82e218a86de572e1f7f;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex1641, std::array<u64,2>{v_c197, 0}, [&](const std::array<u64,2>& m1703) {
        u64 v_c200 = m1703[1];
        if (!slog::exists_probe<2,1>(refindex1642, std::array<u64,2>{v_c199, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1643, std::array<u64,3>{v_c199, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex1644, std::array<u64,3>{v_c200, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1645, std::array<u64,2>{v_c196, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1646, std::array<u64,3>{v_c196, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1647, std::array<u64,2>{v_c198, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1648, std::array<u64,3>{v_c198, 0, 0})) return;
        slog::join_probe<2,1>(refindex1649, std::array<u64,2>{v_c194, 0}, [&](const std::array<u64,2>& m1704) {
          u64 v_c201 = m1704[1];
          if (!slog::exists_probe<3,1>(appindex1650, std::array<u64,3>{v_c201, 0, 0})) return;
          slog::join_probe<2,1>(refindex1651, std::array<u64,2>{v_c199, 0}, [&](const std::array<u64,2>& m1705) {
            u64 v_c202 = m1705[1];
            slog::join_probe<3,2>(lambdaindex1652, std::array<u64,3>{v_c199, v_c202, 0}, [&](const std::array<u64,3>& m1706) {
              u64 v_c203 = m1706[2];
              slog::join_probe<3,2>(appindex1653, std::array<u64,3>{v_c200, v_c203, 0}, [&](const std::array<u64,3>& m1707) {
                u64 v_c204 = m1707[2];
                slog::join_probe<2,1>(refindex1654, std::array<u64,2>{v_c196, 0}, [&](const std::array<u64,2>& m1708) {
                  u64 v_c205 = m1708[1];
                  slog::join_probe<3,2>(lambdaindex1655, std::array<u64,3>{v_c196, v_c205, 0}, [&](const std::array<u64,3>& m1709) {
                    u64 v_c206 = m1709[2];
                    slog::join_probe<3,2>(appindex1656, std::array<u64,3>{v_c201, v_c206, 0}, [&](const std::array<u64,3>& m1710) {
                      u64 v_c207 = m1710[2];
                      slog::join_probe<2,1>(refindex1657, std::array<u64,2>{v_c198, 0}, [&](const std::array<u64,2>& m1711) {
                        u64 v_c208 = m1711[1];
                        slog::join_probe<3,2>(lambdaindex1658, std::array<u64,3>{v_c198, v_c208, 0}, [&](const std::array<u64,3>& m1712) {
                          u64 v_c209 = m1712[2];
                          slog::join_probe<3,2>(lambdaindex1659, std::array<u64,3>{v_c196, v_c209, 0}, [&](const std::array<u64,3>& m1713) {
                            u64 v_c210 = m1713[2];
                            ++_fires;
                            slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c201, v_c210}, std::array<u16,3>{1, 2, 0});
                            slog::emit_struct_checked<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c197, v_c204}, std::array<u16,3>{1, 2, 0});
                          });
                        });
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
  
      if (_fires) db->bumpFires("mcfa-counting.slog:287", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask1660(db,b));
  // (crule (pre) (scan store x c v) (body (exists eval (2 0 1) 1 c) (join-old ref (1 0) 1 (1 0) x __t2jDL164) (join-old eval (1 2 0) 2 (1 2 0) __t2jDL164 c __t8FVl165)) (head (emit eval_ans (0 1) __t8FVl165 v)) mcfa-counting.slog:81 #f)
  class ReadTask1719 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1714;  slog::Index** refindex1715;  slog::Index** evalindex1716;  slog::Index** refdelta1717;  slog::Index** evaldelta1718;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1720({0, 1});
      slog::Relation* readrel1721 = db->getRelation("eval_ans");
      head_index[0] = readrel1721->getIndex(ord1720, false);
      outer_rel = db->getRelation("store");
      std::vector<u16> ord1722({2, 0, 1});
      slog::Relation* readrel1723 = db->getRelation("eval");
      evalindex1714 = readrel1723->getIndex(ord1722, false);
      std::vector<u16> ord1724({1, 0});
      slog::Relation* readrel1725 = db->getRelation("ref");
      refindex1715 = readrel1725->getIndex(ord1724, false);
      std::vector<u16> ord1726({1, 0});
      slog::Relation* readrel1727 = db->getRelation("ref");
      refdelta1717 = readrel1727->getIndex(ord1726, true);
      std::vector<u16> ord1728({1, 2, 0});
      slog::Relation* readrel1729 = db->getRelation("eval");
      evalindex1716 = readrel1729->getIndex(ord1728, false);
      std::vector<u16> ord1730({1, 2, 0});
      slog::Relation* readrel1731 = db->getRelation("eval");
      evaldelta1718 = readrel1731->getIndex(ord1730, true);
  
    }
    ReadTask1719(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c31 = _t[0];
        u64 v_c21 = _t[1];
        u64 v_c75 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex1714, std::array<u64,3>{v_c21, 0, 0})) return;
        slog::join_probe_old<2,1>(refindex1715, refdelta1717, std::array<u64,2>{v_c31, 0}, [&](const std::array<u64,2>& m1732) {
          u64 v_c211 = m1732[1];
          slog::join_probe_old<3,2>(evalindex1716, evaldelta1718, std::array<u64,3>{v_c211, v_c21, 0}, [&](const std::array<u64,3>& m1733) {
            u64 v_c212 = m1733[2];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c212, v_c75}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:81", "delta:store", _fires);
  
      if (!_done)
      {
        ReadTask1719* _cont = new ReadTask1719(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1719(db,b), false);
}

