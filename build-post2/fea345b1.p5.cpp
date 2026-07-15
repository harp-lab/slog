
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const07ef7e8462f6d369d70a1f0e;
extern u64 v_const0aa6f87434af0222b916e97a;
extern u64 v_const0f8748be649f8ee4066bb1d7;
extern u64 v_const227d34ceeba7a29aada993d4;
extern u64 v_const229c0b7aa8a7eb4055f5a3d0;
extern u64 v_const361d5df359e0d7681220d09d;
extern u64 v_const3a82152bd1402931076fe2d7;
extern u64 v_const3f20de5ef71f7ccc981391b7;
extern u64 v_const4492fd5fa4baacfebd29f5e5;
extern u64 v_const4a59dbb9cb3129dfcc75170b;
extern u64 v_const4a8acfc71441e0695ffcf5b3;
extern u64 v_const4e3b5454cf93e32fad90650d;
extern u64 v_const4f84f41d89b6b717419b4eaa;
extern u64 v_const50a95ec20b9767e468d04917;
extern u64 v_const576506f61f53440f1edd95d2;
extern u64 v_const59ba3256d223f0d0a00d0633;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const615ad01b1c532bb6634df115;
extern u64 v_const66518c0c1b3a5a0b09ae2ef1;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const6bc0ba365ada70df115e1785;
extern u64 v_const6cf13cc59dcbe759113f68a4;
extern u64 v_const7b8fd91ee9ff10cfbb8066bf;
extern u64 v_const7c7d2cfc66f4d976987d2d20;
extern u64 v_const7cd75b35aa30c3ddf04f9d57;
extern u64 v_const8ca682693a0738a0641c6956;
extern u64 v_const8d8bcc50ea388ca2a2cd3f92;
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
extern u64 v_constdc1bb6655fb38bdb032e3754;
extern u64 v_conste4a9e4d8baa71a9d8ebf56ec;
extern u64 v_conste58dec6bca6f63ef79c3b755;
extern u64 v_consteb793a6f75d6cfe49d3c2c90;
extern u64 v_constf0a25c0401304c51b5ee9c5e;
extern u64 v_constf700a82e218a86de572e1f7f;


void slog_rules_ca4cf3c4f8d65074b(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre) (scan eval __5K9i345 __t5bzC44 c) (body (join-old app (0 1 2) 1 (0 1 2) __t5bzC44 ef ea)) (head (mkstruct eval (1 2 0) __4C0T346 ea c)) mcfa-counting.slog:92 #f)
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
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord3({0, 1, 2});
      slog::Relation* readrel4 = db->getRelation("app");
      appindex0 = readrel4->getIndex(ord3, false);
      std::vector<u16> ord5({0, 1, 2});
      slog::Relation* readrel6 = db->getRelation("app");
      appdelta1 = readrel6->getIndex(ord5, true);
  
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
        u64 v_c2 = _t[2];
        slog::join_probe_old<3,1>(appindex0, appdelta1, std::array<u64,3>{v_c1, 0, 0}, [&](const std::array<u64,3>& m7) {
          u64 v_c3 = m7[1]; u64 v_c4 = m7[2];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c4, v_c2}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:92", "delta:eval", _fires);
  
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
  // (crule (pre) (scan app __t2veU155 ef ea) (body (join freevar (1 0) 1 ef x)) (head (emit freevar (0 1) x __t2veU155)) freevars.slog:13 #f)
  class ReadTask9 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** freevarindex8;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("freevar");
      std::vector<u16> ord10({0, 1});
      slog::Relation* readrel11 = db->getRelation("freevar");
      head_index[0] = readrel11->getIndex(ord10, false);
      outer_rel = db->getRelation("app");
      std::vector<u16> ord12({1, 0});
      slog::Relation* readrel13 = db->getRelation("freevar");
      freevarindex8 = readrel13->getIndex(ord12, false);
  
    }
    ReadTask9(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c4 = _t[2];
        slog::join_probe<2,1>(freevarindex8, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m14) {
          u64 v_c6 = m14[1];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c6, v_c5}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:13", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask9* _cont = new ReadTask9(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask9(db,b), false);
  // (crule (pre (let __tconst7JVW192 const6cf13cc59dcbe759113f68a4) (let __tconst5wC2180 const970c20ea81b833e5b5a7accf) (let __tconst2ady176 constc40f204dda7ba4054abb9e74) (let __tconst7B9N190 constcaa3ee5a2828a31924f6b39d)) (scan app __t5jf3194 __t6Vw9193 __t6CST181) (body (exists ref (1 0) 1 __tconst5wC2180) (exists lambda (0 1 2) 2 __t6Vw9193 __tconst7JVW192) (exists lambda (1 2 0) 1 __tconst7B9N190) (exists ref (1 0) 1 __tconst2ady176) (exists lambda (1 2 0) 1 __tconst2ady176) (exists ref (1 0) 1 __tconst7JVW192) (exists ref (1 0) 1 __tconst7B9N190) (join lambda (0 1 2) 2 __t6CST181 __tconst5wC2180 __t52sB179) (join ref (0 1) 2 __t52sB179 __tconst5wC2180) (join lambda (0 1 2) 2 __t6Vw9193 __tconst7JVW192 __t6W4v191) (join lambda (0 1 2) 2 __t6W4v191 __tconst7B9N190 __t9pbS189) (join ref (1 0) 1 __tconst2ady176 __t3ZY4175) (join lambda (1 2 0) 2 __tconst2ady176 __t3ZY4175 __t1Ls4177) (join ref (1 0) 1 __tconst7JVW192 __t6fOY185) (exists app (1 2 0) 1 __t6fOY185) (join app (0 1 2) 2 __t9pbS189 __t6fOY185 __t2CTd186) (join app (0 1 2) 2 __t2CTd186 __t6fOY185 __t8oRJ183) (join ref (0 1) 2 __t8oRJ183 __tconst7B9N190)) (head (mkstruct app (1 2 0) __t3W4r195 __t5jf3194 __t1Ls4177)) mcfa-counting.slog:301 #f)
  class ReadTask33 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex15;  slog::Index** lambdaindex16;  slog::Index** lambdaindex17;  slog::Index** refindex18;  slog::Index** lambdaindex19;  slog::Index** refindex20;  slog::Index** refindex21;  slog::Index** lambdaindex22;  slog::Index** refindex23;  slog::Index** lambdaindex24;  slog::Index** lambdaindex25;  slog::Index** refindex26;  slog::Index** lambdaindex27;  slog::Index** refindex28;  slog::Index** appindex29;  slog::Index** appindex30;  slog::Index** appindex31;  slog::Index** refindex32;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      outer_rel = db->getRelation("app");
      std::vector<u16> ord34({1, 0});
      slog::Relation* readrel35 = db->getRelation("ref");
      refindex15 = readrel35->getIndex(ord34, false);
      std::vector<u16> ord36({0, 1, 2});
      slog::Relation* readrel37 = db->getRelation("lambda");
      lambdaindex16 = readrel37->getIndex(ord36, false);
      std::vector<u16> ord38({1, 2, 0});
      slog::Relation* readrel39 = db->getRelation("lambda");
      lambdaindex17 = readrel39->getIndex(ord38, false);
      std::vector<u16> ord40({1, 0});
      slog::Relation* readrel41 = db->getRelation("ref");
      refindex18 = readrel41->getIndex(ord40, false);
      std::vector<u16> ord42({1, 2, 0});
      slog::Relation* readrel43 = db->getRelation("lambda");
      lambdaindex19 = readrel43->getIndex(ord42, false);
      std::vector<u16> ord44({1, 0});
      slog::Relation* readrel45 = db->getRelation("ref");
      refindex20 = readrel45->getIndex(ord44, false);
      std::vector<u16> ord46({1, 0});
      slog::Relation* readrel47 = db->getRelation("ref");
      refindex21 = readrel47->getIndex(ord46, false);
      std::vector<u16> ord48({0, 1, 2});
      slog::Relation* readrel49 = db->getRelation("lambda");
      lambdaindex22 = readrel49->getIndex(ord48, false);
      std::vector<u16> ord50({0, 1});
      slog::Relation* readrel51 = db->getRelation("ref");
      refindex23 = readrel51->getIndex(ord50, false);
      std::vector<u16> ord52({0, 1, 2});
      slog::Relation* readrel53 = db->getRelation("lambda");
      lambdaindex24 = readrel53->getIndex(ord52, false);
      std::vector<u16> ord54({0, 1, 2});
      slog::Relation* readrel55 = db->getRelation("lambda");
      lambdaindex25 = readrel55->getIndex(ord54, false);
      std::vector<u16> ord56({1, 0});
      slog::Relation* readrel57 = db->getRelation("ref");
      refindex26 = readrel57->getIndex(ord56, false);
      std::vector<u16> ord58({1, 2, 0});
      slog::Relation* readrel59 = db->getRelation("lambda");
      lambdaindex27 = readrel59->getIndex(ord58, false);
      std::vector<u16> ord60({1, 0});
      slog::Relation* readrel61 = db->getRelation("ref");
      refindex28 = readrel61->getIndex(ord60, false);
      std::vector<u16> ord62({1, 2, 0});
      slog::Relation* readrel63 = db->getRelation("app");
      appindex29 = readrel63->getIndex(ord62, false);
      std::vector<u16> ord64({0, 1, 2});
      slog::Relation* readrel65 = db->getRelation("app");
      appindex30 = readrel65->getIndex(ord64, false);
      std::vector<u16> ord66({0, 1, 2});
      slog::Relation* readrel67 = db->getRelation("app");
      appindex31 = readrel67->getIndex(ord66, false);
      std::vector<u16> ord68({0, 1});
      slog::Relation* readrel69 = db->getRelation("ref");
      refindex32 = readrel69->getIndex(ord68, false);
  
    }
    ReadTask33(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c7 = v_const6cf13cc59dcbe759113f68a4;
      u64 v_c8 = v_const970c20ea81b833e5b5a7accf;
      u64 v_c9 = v_constc40f204dda7ba4054abb9e74;
      u64 v_c10 = v_constcaa3ee5a2828a31924f6b39d;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c11 = _t[0];
        u64 v_c12 = _t[1];
        u64 v_c13 = _t[2];
        if (!slog::exists_probe<2,1>(refindex15, std::array<u64,2>{v_c8, 0})) return;
        if (!slog::exists_probe<3,2>(lambdaindex16, std::array<u64,3>{v_c12, v_c7, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex17, std::array<u64,3>{v_c10, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex18, std::array<u64,2>{v_c9, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex19, std::array<u64,3>{v_c9, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex20, std::array<u64,2>{v_c7, 0})) return;
        if (!slog::exists_probe<2,1>(refindex21, std::array<u64,2>{v_c10, 0})) return;
        slog::join_probe<3,2>(lambdaindex22, std::array<u64,3>{v_c13, v_c8, 0}, [&](const std::array<u64,3>& m70) {
          u64 v_c14 = m70[2];
          slog::join_probe<2,2>(refindex23, std::array<u64,2>{v_c14, v_c8}, [&](const std::array<u64,2>& m71) {
            slog::join_probe<3,2>(lambdaindex24, std::array<u64,3>{v_c12, v_c7, 0}, [&](const std::array<u64,3>& m72) {
              u64 v_c15 = m72[2];
              slog::join_probe<3,2>(lambdaindex25, std::array<u64,3>{v_c15, v_c10, 0}, [&](const std::array<u64,3>& m73) {
                u64 v_c16 = m73[2];
                slog::join_probe<2,1>(refindex26, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m74) {
                  u64 v_c17 = m74[1];
                  slog::join_probe<3,2>(lambdaindex27, std::array<u64,3>{v_c9, v_c17, 0}, [&](const std::array<u64,3>& m75) {
                    u64 v_c18 = m75[2];
                    slog::join_probe<2,1>(refindex28, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m76) {
                      u64 v_c19 = m76[1];
                      if (!slog::exists_probe<3,1>(appindex29, std::array<u64,3>{v_c19, 0, 0})) return;
                      slog::join_probe<3,2>(appindex30, std::array<u64,3>{v_c16, v_c19, 0}, [&](const std::array<u64,3>& m77) {
                        u64 v_c20 = m77[2];
                        slog::join_probe<3,2>(appindex31, std::array<u64,3>{v_c20, v_c19, 0}, [&](const std::array<u64,3>& m78) {
                          u64 v_c21 = m78[2];
                          slog::join_probe<2,2>(refindex32, std::array<u64,2>{v_c21, v_c10}, [&](const std::array<u64,2>& m79) {
                            ++_fires;
                            slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c11, v_c18}, std::array<u16,3>{1, 2, 0});
                          });
                        });
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
        ReadTask33* _cont = new ReadTask33(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask33(db,b), false);
  // (crule (pre (let __tconst4she277 const50a95ec20b9767e468d04917) (let __tconst0ZLv270 constf0a25c0401304c51b5ee9c5e)) (scan app __t4C0a279 __t6zNR278 __t3oIn271) (body (exists lambda (0 1 2) 2 __t6zNR278 __tconst4she277) (exists ref (1 0) 1 __tconst0ZLv270) (exists ref (1 0) 1 __tconst4she277) (join lambda (0 1 2) 2 __t3oIn271 __tconst0ZLv270 __t8kx2269) (join lambda (0 1 2) 2 __t6zNR278 __tconst4she277 __t6FnS276) (join ref (1 0) 1 __tconst0ZLv270 __t9L3S266) (join app (0 1 2) 2 __t8kx2269 __t9L3S266 dup70Vn445) (eq __t9L3S266 dup70Vn445) (join ref (1 0) 1 __tconst4she277 __t28CO273) (join app (0 1 2) 2 __t6FnS276 __t28CO273 dup6QMk446) (eq __t28CO273 dup6QMk446)) (head (emit program (0) __t4C0a279)) mcfa-counting.slog:183 #f)
  class ReadTask89 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lambdaindex80;  slog::Index** refindex81;  slog::Index** refindex82;  slog::Index** lambdaindex83;  slog::Index** lambdaindex84;  slog::Index** refindex85;  slog::Index** appindex86;  slog::Index** refindex87;  slog::Index** appindex88;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("program");
      std::vector<u16> ord90({0});
      slog::Relation* readrel91 = db->getRelation("program");
      head_index[0] = readrel91->getIndex(ord90, false);
      outer_rel = db->getRelation("app");
      std::vector<u16> ord92({0, 1, 2});
      slog::Relation* readrel93 = db->getRelation("lambda");
      lambdaindex80 = readrel93->getIndex(ord92, false);
      std::vector<u16> ord94({1, 0});
      slog::Relation* readrel95 = db->getRelation("ref");
      refindex81 = readrel95->getIndex(ord94, false);
      std::vector<u16> ord96({1, 0});
      slog::Relation* readrel97 = db->getRelation("ref");
      refindex82 = readrel97->getIndex(ord96, false);
      std::vector<u16> ord98({0, 1, 2});
      slog::Relation* readrel99 = db->getRelation("lambda");
      lambdaindex83 = readrel99->getIndex(ord98, false);
      std::vector<u16> ord100({0, 1, 2});
      slog::Relation* readrel101 = db->getRelation("lambda");
      lambdaindex84 = readrel101->getIndex(ord100, false);
      std::vector<u16> ord102({1, 0});
      slog::Relation* readrel103 = db->getRelation("ref");
      refindex85 = readrel103->getIndex(ord102, false);
      std::vector<u16> ord104({0, 1, 2});
      slog::Relation* readrel105 = db->getRelation("app");
      appindex86 = readrel105->getIndex(ord104, false);
      std::vector<u16> ord106({1, 0});
      slog::Relation* readrel107 = db->getRelation("ref");
      refindex87 = readrel107->getIndex(ord106, false);
      std::vector<u16> ord108({0, 1, 2});
      slog::Relation* readrel109 = db->getRelation("app");
      appindex88 = readrel109->getIndex(ord108, false);
  
    }
    ReadTask89(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c22 = v_const50a95ec20b9767e468d04917;
      u64 v_c23 = v_constf0a25c0401304c51b5ee9c5e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c24 = _t[0];
        u64 v_c25 = _t[1];
        u64 v_c26 = _t[2];
        if (!slog::exists_probe<3,2>(lambdaindex80, std::array<u64,3>{v_c25, v_c22, 0})) return;
        if (!slog::exists_probe<2,1>(refindex81, std::array<u64,2>{v_c23, 0})) return;
        if (!slog::exists_probe<2,1>(refindex82, std::array<u64,2>{v_c22, 0})) return;
        slog::join_probe<3,2>(lambdaindex83, std::array<u64,3>{v_c26, v_c23, 0}, [&](const std::array<u64,3>& m110) {
          u64 v_c27 = m110[2];
          slog::join_probe<3,2>(lambdaindex84, std::array<u64,3>{v_c25, v_c22, 0}, [&](const std::array<u64,3>& m111) {
            u64 v_c28 = m111[2];
            slog::join_probe<2,1>(refindex85, std::array<u64,2>{v_c23, 0}, [&](const std::array<u64,2>& m112) {
              u64 v_c29 = m112[1];
              slog::join_probe<3,2>(appindex86, std::array<u64,3>{v_c27, v_c29, 0}, [&](const std::array<u64,3>& m113) {
                u64 v_c30 = m113[2];
                if (v_c29 != v_c30) return;
                slog::join_probe<2,1>(refindex87, std::array<u64,2>{v_c22, 0}, [&](const std::array<u64,2>& m114) {
                  u64 v_c31 = m114[1];
                  slog::join_probe<3,2>(appindex88, std::array<u64,3>{v_c28, v_c31, 0}, [&](const std::array<u64,3>& m115) {
                    u64 v_c32 = m115[2];
                    if (v_c31 != v_c32) return;
                    ++_fires;
                    slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c24}, std::array<u16,1>{0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:183", "delta:app", _fires);
  
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
  // (crule (pre (let __tconst9zoW125 const7c7d2cfc66f4d976987d2d20) (let __tconst4V4L122 const6bc0ba365ada70df115e1785) (let __tconst82U8119 consta8180db1c2f300980314f910) (let __tconst4Zcr91 const9a67f28c6b77e842f439a84a) (let __tconst0vRf84 conste58dec6bca6f63ef79c3b755) (let __tconst3wDH116 constd5f017533ea574d5f9b3400c) (let __tconst4BKz104 const0f8748be649f8ee4066bb1d7) (let __tconst3ktF111 const990b444cbd47632035b2fa1a) (let __tconst5nWJ102 const4f84f41d89b6b717419b4eaa)) (seeded) (body (join ref (1 0) 1 __tconst4V4L122 __t7aew98) (exists lambda (1 2 0) 1 __tconst0vRf84) (exists ref (1 0) 1 __tconst4Zcr91) (exists ref (1 0) 1 __tconst9zoW125) (exists lambda (1 2 0) 1 __tconst4Zcr91) (exists ref (1 0) 1 __tconst4BKz104) (exists lambda (1 2 0) 1 __tconst4BKz104) (exists app (1 2 0) 1 __t7aew98) (exists ref (1 0) 1 __tconst3wDH116) (exists ref (1 0) 1 __tconst5nWJ102) (exists lambda (1 2 0) 1 __tconst5nWJ102) (exists ref (1 0) 1 __tconst3ktF111) (exists lambda (1 2 0) 1 __tconst3ktF111) (exists lambda (1 2 0) 1 __tconst3wDH116) (exists lambda (1 2 0) 1 __tconst82U8119) (join ref (1 0) 1 __tconst0vRf84 __t2duR83) (join lambda (1 2 0) 2 __tconst0vRf84 __t2duR83 __t87vL85) (join ref (1 0) 1 __tconst4Zcr91 __t0C9F87) (exists app (2 0 1) 1 __t0C9F87) (join ref (1 0) 1 __tconst9zoW125 __t3Q2G89) (join app (1 2 0) 2 __t3Q2G89 __t0C9F87 __t2Eqd90) (join lambda (1 2 0) 2 __tconst4Zcr91 __t2Eqd90 __t3pgm92) (join ref (1 0) 1 __tconst4BKz104 __t8C0a94) (join lambda (1 2 0) 2 __tconst4BKz104 __t8C0a94 __t4fDK96) (join app (1 2 0) 2 __t7aew98 __t4fDK96 __t7TEO99) (join ref (1 0) 1 __tconst3wDH116 __t3wir114) (exists app (1 2 0) 1 __t3wir114) (join ref (1 0) 1 __tconst5nWJ102 __t5MaG101) (join lambda (1 2 0) 2 __tconst5nWJ102 __t5MaG101 __t35jA103) (join lambda (1 2 0) 2 __tconst4BKz104 __t35jA103 __t6RuY105) (join app (1 2 0) 2 __t7aew98 __t6RuY105 __t2Z7m108) (exists app (2 0 1) 1 __t2Z7m108) (join ref (1 0) 1 __tconst3ktF111 __t7ohz110) (join lambda (1 2 0) 2 __tconst3ktF111 __t7ohz110 __t8GWA112) (join app (1 2 0) 2 __t3wir114 __t8GWA112 __t44OM115) (join lambda (1 2 0) 2 __tconst3wDH116 __t44OM115 __t7CwH117) (join app (1 2 0) 2 __t7CwH117 __t2Z7m108 __t50Kk118) (join lambda (1 2 0) 2 __tconst82U8119 __t50Kk118 __t3SEs120)) (head (mkstruct app (1 2 0) __t1GdP121 __t3SEs120 __t7TEO99)) mcfa-counting.slog:241 #f)
  class ReadTask154 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex116;  slog::Index** lambdaindex117;  slog::Index** refindex118;  slog::Index** refindex119;  slog::Index** lambdaindex120;  slog::Index** refindex121;  slog::Index** lambdaindex122;  slog::Index** appindex123;  slog::Index** refindex124;  slog::Index** refindex125;  slog::Index** lambdaindex126;  slog::Index** refindex127;  slog::Index** lambdaindex128;  slog::Index** lambdaindex129;  slog::Index** lambdaindex130;  slog::Index** refindex131;  slog::Index** lambdaindex132;  slog::Index** refindex133;  slog::Index** appindex134;  slog::Index** refindex135;  slog::Index** appindex136;  slog::Index** lambdaindex137;  slog::Index** refindex138;  slog::Index** lambdaindex139;  slog::Index** appindex140;  slog::Index** refindex141;  slog::Index** appindex142;  slog::Index** refindex143;  slog::Index** lambdaindex144;  slog::Index** lambdaindex145;  slog::Index** appindex146;  slog::Index** appindex147;  slog::Index** refindex148;  slog::Index** lambdaindex149;  slog::Index** appindex150;  slog::Index** lambdaindex151;  slog::Index** appindex152;  slog::Index** lambdaindex153;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord155({1, 2, 0});
      slog::Relation* readrel156 = db->getRelation("app");
      head_index[0] = readrel156->getIndex(ord155, false);
      std::vector<u16> ord157({1, 0});
      slog::Relation* readrel158 = db->getRelation("ref");
      refindex116 = readrel158->getIndex(ord157, false);
      std::vector<u16> ord159({1, 2, 0});
      slog::Relation* readrel160 = db->getRelation("lambda");
      lambdaindex117 = readrel160->getIndex(ord159, false);
      std::vector<u16> ord161({1, 0});
      slog::Relation* readrel162 = db->getRelation("ref");
      refindex118 = readrel162->getIndex(ord161, false);
      std::vector<u16> ord163({1, 0});
      slog::Relation* readrel164 = db->getRelation("ref");
      refindex119 = readrel164->getIndex(ord163, false);
      std::vector<u16> ord165({1, 2, 0});
      slog::Relation* readrel166 = db->getRelation("lambda");
      lambdaindex120 = readrel166->getIndex(ord165, false);
      std::vector<u16> ord167({1, 0});
      slog::Relation* readrel168 = db->getRelation("ref");
      refindex121 = readrel168->getIndex(ord167, false);
      std::vector<u16> ord169({1, 2, 0});
      slog::Relation* readrel170 = db->getRelation("lambda");
      lambdaindex122 = readrel170->getIndex(ord169, false);
      std::vector<u16> ord171({1, 2, 0});
      slog::Relation* readrel172 = db->getRelation("app");
      appindex123 = readrel172->getIndex(ord171, false);
      std::vector<u16> ord173({1, 0});
      slog::Relation* readrel174 = db->getRelation("ref");
      refindex124 = readrel174->getIndex(ord173, false);
      std::vector<u16> ord175({1, 0});
      slog::Relation* readrel176 = db->getRelation("ref");
      refindex125 = readrel176->getIndex(ord175, false);
      std::vector<u16> ord177({1, 2, 0});
      slog::Relation* readrel178 = db->getRelation("lambda");
      lambdaindex126 = readrel178->getIndex(ord177, false);
      std::vector<u16> ord179({1, 0});
      slog::Relation* readrel180 = db->getRelation("ref");
      refindex127 = readrel180->getIndex(ord179, false);
      std::vector<u16> ord181({1, 2, 0});
      slog::Relation* readrel182 = db->getRelation("lambda");
      lambdaindex128 = readrel182->getIndex(ord181, false);
      std::vector<u16> ord183({1, 2, 0});
      slog::Relation* readrel184 = db->getRelation("lambda");
      lambdaindex129 = readrel184->getIndex(ord183, false);
      std::vector<u16> ord185({1, 2, 0});
      slog::Relation* readrel186 = db->getRelation("lambda");
      lambdaindex130 = readrel186->getIndex(ord185, false);
      std::vector<u16> ord187({1, 0});
      slog::Relation* readrel188 = db->getRelation("ref");
      refindex131 = readrel188->getIndex(ord187, false);
      std::vector<u16> ord189({1, 2, 0});
      slog::Relation* readrel190 = db->getRelation("lambda");
      lambdaindex132 = readrel190->getIndex(ord189, false);
      std::vector<u16> ord191({1, 0});
      slog::Relation* readrel192 = db->getRelation("ref");
      refindex133 = readrel192->getIndex(ord191, false);
      std::vector<u16> ord193({2, 0, 1});
      slog::Relation* readrel194 = db->getRelation("app");
      appindex134 = readrel194->getIndex(ord193, false);
      std::vector<u16> ord195({1, 0});
      slog::Relation* readrel196 = db->getRelation("ref");
      refindex135 = readrel196->getIndex(ord195, false);
      std::vector<u16> ord197({1, 2, 0});
      slog::Relation* readrel198 = db->getRelation("app");
      appindex136 = readrel198->getIndex(ord197, false);
      std::vector<u16> ord199({1, 2, 0});
      slog::Relation* readrel200 = db->getRelation("lambda");
      lambdaindex137 = readrel200->getIndex(ord199, false);
      std::vector<u16> ord201({1, 0});
      slog::Relation* readrel202 = db->getRelation("ref");
      refindex138 = readrel202->getIndex(ord201, false);
      std::vector<u16> ord203({1, 2, 0});
      slog::Relation* readrel204 = db->getRelation("lambda");
      lambdaindex139 = readrel204->getIndex(ord203, false);
      std::vector<u16> ord205({1, 2, 0});
      slog::Relation* readrel206 = db->getRelation("app");
      appindex140 = readrel206->getIndex(ord205, false);
      std::vector<u16> ord207({1, 0});
      slog::Relation* readrel208 = db->getRelation("ref");
      refindex141 = readrel208->getIndex(ord207, false);
      std::vector<u16> ord209({1, 2, 0});
      slog::Relation* readrel210 = db->getRelation("app");
      appindex142 = readrel210->getIndex(ord209, false);
      std::vector<u16> ord211({1, 0});
      slog::Relation* readrel212 = db->getRelation("ref");
      refindex143 = readrel212->getIndex(ord211, false);
      std::vector<u16> ord213({1, 2, 0});
      slog::Relation* readrel214 = db->getRelation("lambda");
      lambdaindex144 = readrel214->getIndex(ord213, false);
      std::vector<u16> ord215({1, 2, 0});
      slog::Relation* readrel216 = db->getRelation("lambda");
      lambdaindex145 = readrel216->getIndex(ord215, false);
      std::vector<u16> ord217({1, 2, 0});
      slog::Relation* readrel218 = db->getRelation("app");
      appindex146 = readrel218->getIndex(ord217, false);
      std::vector<u16> ord219({2, 0, 1});
      slog::Relation* readrel220 = db->getRelation("app");
      appindex147 = readrel220->getIndex(ord219, false);
      std::vector<u16> ord221({1, 0});
      slog::Relation* readrel222 = db->getRelation("ref");
      refindex148 = readrel222->getIndex(ord221, false);
      std::vector<u16> ord223({1, 2, 0});
      slog::Relation* readrel224 = db->getRelation("lambda");
      lambdaindex149 = readrel224->getIndex(ord223, false);
      std::vector<u16> ord225({1, 2, 0});
      slog::Relation* readrel226 = db->getRelation("app");
      appindex150 = readrel226->getIndex(ord225, false);
      std::vector<u16> ord227({1, 2, 0});
      slog::Relation* readrel228 = db->getRelation("lambda");
      lambdaindex151 = readrel228->getIndex(ord227, false);
      std::vector<u16> ord229({1, 2, 0});
      slog::Relation* readrel230 = db->getRelation("app");
      appindex152 = readrel230->getIndex(ord229, false);
      std::vector<u16> ord231({1, 2, 0});
      slog::Relation* readrel232 = db->getRelation("lambda");
      lambdaindex153 = readrel232->getIndex(ord231, false);
  
    }
    ReadTask154(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c33 = v_const7c7d2cfc66f4d976987d2d20;
      u64 v_c34 = v_const6bc0ba365ada70df115e1785;
      u64 v_c35 = v_consta8180db1c2f300980314f910;
      u64 v_c36 = v_const9a67f28c6b77e842f439a84a;
      u64 v_c37 = v_conste58dec6bca6f63ef79c3b755;
      u64 v_c38 = v_constd5f017533ea574d5f9b3400c;
      u64 v_c39 = v_const0f8748be649f8ee4066bb1d7;
      u64 v_c40 = v_const990b444cbd47632035b2fa1a;
      u64 v_c41 = v_const4f84f41d89b6b717419b4eaa;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex116, std::array<u64,2>{v_c34, 0}, [&](const std::array<u64,2>& m233) {
        u64 v_c42 = m233[1];
        if (!slog::exists_probe<3,1>(lambdaindex117, std::array<u64,3>{v_c37, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex118, std::array<u64,2>{v_c36, 0})) return;
        if (!slog::exists_probe<2,1>(refindex119, std::array<u64,2>{v_c33, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex120, std::array<u64,3>{v_c36, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex121, std::array<u64,2>{v_c39, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex122, std::array<u64,3>{v_c39, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex123, std::array<u64,3>{v_c42, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex124, std::array<u64,2>{v_c38, 0})) return;
        if (!slog::exists_probe<2,1>(refindex125, std::array<u64,2>{v_c41, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex126, std::array<u64,3>{v_c41, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex127, std::array<u64,2>{v_c40, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex128, std::array<u64,3>{v_c40, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex129, std::array<u64,3>{v_c38, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex130, std::array<u64,3>{v_c35, 0, 0})) return;
        slog::join_probe<2,1>(refindex131, std::array<u64,2>{v_c37, 0}, [&](const std::array<u64,2>& m234) {
          u64 v_c43 = m234[1];
          slog::join_probe<3,2>(lambdaindex132, std::array<u64,3>{v_c37, v_c43, 0}, [&](const std::array<u64,3>& m235) {
            u64 v_c44 = m235[2];
            slog::join_probe<2,1>(refindex133, std::array<u64,2>{v_c36, 0}, [&](const std::array<u64,2>& m236) {
              u64 v_c45 = m236[1];
              if (!slog::exists_probe<3,1>(appindex134, std::array<u64,3>{v_c45, 0, 0})) return;
              slog::join_probe<2,1>(refindex135, std::array<u64,2>{v_c33, 0}, [&](const std::array<u64,2>& m237) {
                u64 v_c46 = m237[1];
                slog::join_probe<3,2>(appindex136, std::array<u64,3>{v_c46, v_c45, 0}, [&](const std::array<u64,3>& m238) {
                  u64 v_c47 = m238[2];
                  slog::join_probe<3,2>(lambdaindex137, std::array<u64,3>{v_c36, v_c47, 0}, [&](const std::array<u64,3>& m239) {
                    u64 v_c48 = m239[2];
                    slog::join_probe<2,1>(refindex138, std::array<u64,2>{v_c39, 0}, [&](const std::array<u64,2>& m240) {
                      u64 v_c49 = m240[1];
                      slog::join_probe<3,2>(lambdaindex139, std::array<u64,3>{v_c39, v_c49, 0}, [&](const std::array<u64,3>& m241) {
                        u64 v_c50 = m241[2];
                        slog::join_probe<3,2>(appindex140, std::array<u64,3>{v_c42, v_c50, 0}, [&](const std::array<u64,3>& m242) {
                          u64 v_c51 = m242[2];
                          slog::join_probe<2,1>(refindex141, std::array<u64,2>{v_c38, 0}, [&](const std::array<u64,2>& m243) {
                            u64 v_c52 = m243[1];
                            if (!slog::exists_probe<3,1>(appindex142, std::array<u64,3>{v_c52, 0, 0})) return;
                            slog::join_probe<2,1>(refindex143, std::array<u64,2>{v_c41, 0}, [&](const std::array<u64,2>& m244) {
                              u64 v_c53 = m244[1];
                              slog::join_probe<3,2>(lambdaindex144, std::array<u64,3>{v_c41, v_c53, 0}, [&](const std::array<u64,3>& m245) {
                                u64 v_c54 = m245[2];
                                slog::join_probe<3,2>(lambdaindex145, std::array<u64,3>{v_c39, v_c54, 0}, [&](const std::array<u64,3>& m246) {
                                  u64 v_c55 = m246[2];
                                  slog::join_probe<3,2>(appindex146, std::array<u64,3>{v_c42, v_c55, 0}, [&](const std::array<u64,3>& m247) {
                                    u64 v_c56 = m247[2];
                                    if (!slog::exists_probe<3,1>(appindex147, std::array<u64,3>{v_c56, 0, 0})) return;
                                    slog::join_probe<2,1>(refindex148, std::array<u64,2>{v_c40, 0}, [&](const std::array<u64,2>& m248) {
                                      u64 v_c57 = m248[1];
                                      slog::join_probe<3,2>(lambdaindex149, std::array<u64,3>{v_c40, v_c57, 0}, [&](const std::array<u64,3>& m249) {
                                        u64 v_c58 = m249[2];
                                        slog::join_probe<3,2>(appindex150, std::array<u64,3>{v_c52, v_c58, 0}, [&](const std::array<u64,3>& m250) {
                                          u64 v_c59 = m250[2];
                                          slog::join_probe<3,2>(lambdaindex151, std::array<u64,3>{v_c38, v_c59, 0}, [&](const std::array<u64,3>& m251) {
                                            u64 v_c60 = m251[2];
                                            slog::join_probe<3,2>(appindex152, std::array<u64,3>{v_c60, v_c56, 0}, [&](const std::array<u64,3>& m252) {
                                              u64 v_c61 = m252[2];
                                              slog::join_probe<3,2>(lambdaindex153, std::array<u64,3>{v_c35, v_c61, 0}, [&](const std::array<u64,3>& m253) {
                                                u64 v_c62 = m253[2];
                                                ++_fires;
                                                slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c62, v_c51}, std::array<u16,3>{1, 2, 0});
                                              });
                                            });
                                          });
                                        });
                                      });
                                    });
                                  });
                                });
                              });
                            });
                          });
                        });
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
      s->addTaskSeeded(phase_read, new ReadTask154(db,b));
  // (crule (pre (let __tconst9zoW125 const7c7d2cfc66f4d976987d2d20) (let __tconst4V4L122 const6bc0ba365ada70df115e1785) (let __tconst82U8119 consta8180db1c2f300980314f910) (let __tconst3wDH116 constd5f017533ea574d5f9b3400c) (let __tconst3ktF111 const990b444cbd47632035b2fa1a) (let __tconst4BKz104 const0f8748be649f8ee4066bb1d7) (let __tconst5nWJ102 const4f84f41d89b6b717419b4eaa) (let __tconst4Zcr91 const9a67f28c6b77e842f439a84a) (let __tconst0vRf84 conste58dec6bca6f63ef79c3b755)) (probe ref (1 0) 1 __tconst0vRf84 __t2duR83) (body (exists ref (1 0) 1 __tconst9zoW125) (exists ref (1 0) 1 __tconst4BKz104) (exists ref (1 0) 1 __tconst4V4L122) (exists ref (1 0) 1 __tconst5nWJ102) (exists ref (1 0) 1 __tconst3ktF111) (exists ref (1 0) 1 __tconst3wDH116) (join ref (1 0) 1 __tconst4Zcr91 __t0C9F87) (join ref (1 0) 1 __tconst9zoW125 __t3Q2G89) (join ref (1 0) 1 __tconst4BKz104 __t8C0a94) (join ref (1 0) 1 __tconst4V4L122 __t7aew98) (join ref (1 0) 1 __tconst5nWJ102 __t5MaG101) (join ref (1 0) 1 __tconst3ktF111 __t7ohz110) (join ref (1 0) 1 __tconst3wDH116 __t3wir114)) (head (mkstruct lambda (1 2 0) __t8GWA112 __tconst3ktF111 __t7ohz110) (mkstruct lambda (1 2 0) __t35jA103 __tconst5nWJ102 __t5MaG101) (mkstruct lambda (1 2 0) __t4fDK96 __tconst4BKz104 __t8C0a94) (mkstruct app (1 2 0) __t2Eqd90 __t3Q2G89 __t0C9F87) (mkstruct lambda (1 2 0) __t87vL85 __tconst0vRf84 __t2duR83)) mcfa-counting.slog:241 #f)
  class ReadTask267 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[5];
    slog::Index** head_index[5];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** refindex254;  slog::Index** refindex255;  slog::Index** refindex256;  slog::Index** refindex257;  slog::Index** refindex258;  slog::Index** refindex259;  slog::Index** refindex260;  slog::Index** refindex261;  slog::Index** refindex262;  slog::Index** refindex263;  slog::Index** refindex264;  slog::Index** refindex265;  slog::Index** refindex266;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      head_rel[1] = db->getRelation("lambda");
      head_rel[2] = db->getRelation("lambda");
      head_rel[3] = db->getRelation("app");
      head_rel[4] = db->getRelation("lambda");
      std::vector<u16> ord268({1, 0});
      slog::Relation* readrel269 = db->getRelation("ref");
      driver_index = readrel269->getIndex(ord268, true);
      std::vector<u16> ord270({1, 0});
      slog::Relation* readrel271 = db->getRelation("ref");
      refindex254 = readrel271->getIndex(ord270, false);
      std::vector<u16> ord272({1, 0});
      slog::Relation* readrel273 = db->getRelation("ref");
      refindex255 = readrel273->getIndex(ord272, false);
      std::vector<u16> ord274({1, 0});
      slog::Relation* readrel275 = db->getRelation("ref");
      refindex256 = readrel275->getIndex(ord274, false);
      std::vector<u16> ord276({1, 0});
      slog::Relation* readrel277 = db->getRelation("ref");
      refindex257 = readrel277->getIndex(ord276, false);
      std::vector<u16> ord278({1, 0});
      slog::Relation* readrel279 = db->getRelation("ref");
      refindex258 = readrel279->getIndex(ord278, false);
      std::vector<u16> ord280({1, 0});
      slog::Relation* readrel281 = db->getRelation("ref");
      refindex259 = readrel281->getIndex(ord280, false);
      std::vector<u16> ord282({1, 0});
      slog::Relation* readrel283 = db->getRelation("ref");
      refindex260 = readrel283->getIndex(ord282, false);
      std::vector<u16> ord284({1, 0});
      slog::Relation* readrel285 = db->getRelation("ref");
      refindex261 = readrel285->getIndex(ord284, false);
      std::vector<u16> ord286({1, 0});
      slog::Relation* readrel287 = db->getRelation("ref");
      refindex262 = readrel287->getIndex(ord286, false);
      std::vector<u16> ord288({1, 0});
      slog::Relation* readrel289 = db->getRelation("ref");
      refindex263 = readrel289->getIndex(ord288, false);
      std::vector<u16> ord290({1, 0});
      slog::Relation* readrel291 = db->getRelation("ref");
      refindex264 = readrel291->getIndex(ord290, false);
      std::vector<u16> ord292({1, 0});
      slog::Relation* readrel293 = db->getRelation("ref");
      refindex265 = readrel293->getIndex(ord292, false);
      std::vector<u16> ord294({1, 0});
      slog::Relation* readrel295 = db->getRelation("ref");
      refindex266 = readrel295->getIndex(ord294, false);
  
    }
    ReadTask267(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c33 = v_const7c7d2cfc66f4d976987d2d20;
      u64 v_c34 = v_const6bc0ba365ada70df115e1785;
      u64 v_c35 = v_consta8180db1c2f300980314f910;
      u64 v_c38 = v_constd5f017533ea574d5f9b3400c;
      u64 v_c40 = v_const990b444cbd47632035b2fa1a;
      u64 v_c39 = v_const0f8748be649f8ee4066bb1d7;
      u64 v_c41 = v_const4f84f41d89b6b717419b4eaa;
      u64 v_c36 = v_const9a67f28c6b77e842f439a84a;
      u64 v_c37 = v_conste58dec6bca6f63ef79c3b755;
  
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
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c37, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m296) {
        u64 v_c43 = m296[1];
        if (buckethash(v_c43) != bucket) return;
        if (!slog::exists_probe<2,1>(refindex254, std::array<u64,2>{v_c33, 0})) return;
        if (!slog::exists_probe<2,1>(refindex255, std::array<u64,2>{v_c39, 0})) return;
        if (!slog::exists_probe<2,1>(refindex256, std::array<u64,2>{v_c34, 0})) return;
        if (!slog::exists_probe<2,1>(refindex257, std::array<u64,2>{v_c41, 0})) return;
        if (!slog::exists_probe<2,1>(refindex258, std::array<u64,2>{v_c40, 0})) return;
        if (!slog::exists_probe<2,1>(refindex259, std::array<u64,2>{v_c38, 0})) return;
        slog::join_probe<2,1>(refindex260, std::array<u64,2>{v_c36, 0}, [&](const std::array<u64,2>& m297) {
          u64 v_c45 = m297[1];
          slog::join_probe<2,1>(refindex261, std::array<u64,2>{v_c33, 0}, [&](const std::array<u64,2>& m298) {
            u64 v_c46 = m298[1];
            slog::join_probe<2,1>(refindex262, std::array<u64,2>{v_c39, 0}, [&](const std::array<u64,2>& m299) {
              u64 v_c49 = m299[1];
              slog::join_probe<2,1>(refindex263, std::array<u64,2>{v_c34, 0}, [&](const std::array<u64,2>& m300) {
                u64 v_c42 = m300[1];
                slog::join_probe<2,1>(refindex264, std::array<u64,2>{v_c41, 0}, [&](const std::array<u64,2>& m301) {
                  u64 v_c53 = m301[1];
                  slog::join_probe<2,1>(refindex265, std::array<u64,2>{v_c40, 0}, [&](const std::array<u64,2>& m302) {
                    u64 v_c57 = m302[1];
                    slog::join_probe<2,1>(refindex266, std::array<u64,2>{v_c38, 0}, [&](const std::array<u64,2>& m303) {
                      u64 v_c52 = m303[1];
                      ++_fires;
                      slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c40, v_c57}, std::array<u16,3>{1, 2, 0});
                      slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c41, v_c53}, std::array<u16,3>{1, 2, 0});
                      slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c39, v_c49}, std::array<u16,3>{1, 2, 0});
                      slog::emit_struct<3>(head_rel[3], newbatch[3], std::array<u64,2>{v_c46, v_c45}, std::array<u16,3>{1, 2, 0});
                      slog::emit_struct<3>(head_rel[4], newbatch[4], std::array<u64,2>{v_c37, v_c43}, std::array<u16,3>{1, 2, 0});
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
        head_rel[4]->sendBatch(newbatch[4]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:241", "delta:ref", _fires);
  
      if (!_done)
      {
        ReadTask267* _cont = new ReadTask267(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask267(db,b), false);
  // (crule (pre (let __tconst8eg8132 const361d5df359e0d7681220d09d) (let __tconst0zC2144 const4e3b5454cf93e32fad90650d) (let __tconst8xRt151 const3a82152bd1402931076fe2d7) (let __tconst3Taj142 constdc1bb6655fb38bdb032e3754)) (scan app __t6KrY154 __t6Ups153 __t4DXA133) (body (exists ref (1 0) 1 __tconst8eg8132) (exists ref (1 0) 1 __tconst8xRt151) (exists ref (1 0) 1 __tconst3Taj142) (exists ref (1 0) 1 __tconst0zC2144) (exists lambda (1 2 0) 1 __tconst8xRt151) (exists lambda (1 2 0) 1 __tconst0zC2144) (exists lambda (1 2 0) 1 __tconst3Taj142) (join lambda (0 1 2) 2 __t4DXA133 __tconst8eg8132 __t19JM131) (join ref (0 1) 2 __t19JM131 __tconst8eg8132) (join ref (1 0) 1 __tconst8xRt151 __t1g2P147) (exists app (1 2 0) 1 __t1g2P147) (join ref (1 0) 1 __tconst3Taj142 __t93Xi135) (exists app (2 0 1) 1 __t93Xi135) (join ref (1 0) 1 __tconst0zC2144 __t7VSc137) (exists app (1 2 0) 1 __t7VSc137) (join app (1 2 0) 1 __t1g2P147 dup61ba411 __t9UZN150) (eq __t1g2P147 dup61ba411) (join lambda (1 2 0) 2 __tconst8xRt151 __t9UZN150 __t2nYy152) (join app (0 1 2) 2 __t6Ups153 __t2nYy152 __t6t5O145) (join lambda (0 1 2) 2 __t6t5O145 __tconst0zC2144 __t2Ce3143) (join lambda (0 1 2) 2 __t2Ce3143 __tconst3Taj142 __t25NQ141) (join app (2 0 1) 2 __t93Xi135 __t25NQ141 __t8dYW140) (join app (0 1 2) 2 __t8dYW140 __t7VSc137 dup5irv412) (eq __t7VSc137 dup5irv412)) (head (emit program (0) __t6KrY154)) mcfa-counting.slog:224 #f)
  class ReadTask326 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex304;  slog::Index** refindex305;  slog::Index** refindex306;  slog::Index** refindex307;  slog::Index** lambdaindex308;  slog::Index** lambdaindex309;  slog::Index** lambdaindex310;  slog::Index** lambdaindex311;  slog::Index** refindex312;  slog::Index** refindex313;  slog::Index** appindex314;  slog::Index** refindex315;  slog::Index** appindex316;  slog::Index** refindex317;  slog::Index** appindex318;  slog::Index** appindex319;  slog::Index** lambdaindex320;  slog::Index** appindex321;  slog::Index** lambdaindex322;  slog::Index** lambdaindex323;  slog::Index** appindex324;  slog::Index** appindex325;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("program");
      std::vector<u16> ord327({0});
      slog::Relation* readrel328 = db->getRelation("program");
      head_index[0] = readrel328->getIndex(ord327, false);
      outer_rel = db->getRelation("app");
      std::vector<u16> ord329({1, 0});
      slog::Relation* readrel330 = db->getRelation("ref");
      refindex304 = readrel330->getIndex(ord329, false);
      std::vector<u16> ord331({1, 0});
      slog::Relation* readrel332 = db->getRelation("ref");
      refindex305 = readrel332->getIndex(ord331, false);
      std::vector<u16> ord333({1, 0});
      slog::Relation* readrel334 = db->getRelation("ref");
      refindex306 = readrel334->getIndex(ord333, false);
      std::vector<u16> ord335({1, 0});
      slog::Relation* readrel336 = db->getRelation("ref");
      refindex307 = readrel336->getIndex(ord335, false);
      std::vector<u16> ord337({1, 2, 0});
      slog::Relation* readrel338 = db->getRelation("lambda");
      lambdaindex308 = readrel338->getIndex(ord337, false);
      std::vector<u16> ord339({1, 2, 0});
      slog::Relation* readrel340 = db->getRelation("lambda");
      lambdaindex309 = readrel340->getIndex(ord339, false);
      std::vector<u16> ord341({1, 2, 0});
      slog::Relation* readrel342 = db->getRelation("lambda");
      lambdaindex310 = readrel342->getIndex(ord341, false);
      std::vector<u16> ord343({0, 1, 2});
      slog::Relation* readrel344 = db->getRelation("lambda");
      lambdaindex311 = readrel344->getIndex(ord343, false);
      std::vector<u16> ord345({0, 1});
      slog::Relation* readrel346 = db->getRelation("ref");
      refindex312 = readrel346->getIndex(ord345, false);
      std::vector<u16> ord347({1, 0});
      slog::Relation* readrel348 = db->getRelation("ref");
      refindex313 = readrel348->getIndex(ord347, false);
      std::vector<u16> ord349({1, 2, 0});
      slog::Relation* readrel350 = db->getRelation("app");
      appindex314 = readrel350->getIndex(ord349, false);
      std::vector<u16> ord351({1, 0});
      slog::Relation* readrel352 = db->getRelation("ref");
      refindex315 = readrel352->getIndex(ord351, false);
      std::vector<u16> ord353({2, 0, 1});
      slog::Relation* readrel354 = db->getRelation("app");
      appindex316 = readrel354->getIndex(ord353, false);
      std::vector<u16> ord355({1, 0});
      slog::Relation* readrel356 = db->getRelation("ref");
      refindex317 = readrel356->getIndex(ord355, false);
      std::vector<u16> ord357({1, 2, 0});
      slog::Relation* readrel358 = db->getRelation("app");
      appindex318 = readrel358->getIndex(ord357, false);
      std::vector<u16> ord359({1, 2, 0});
      slog::Relation* readrel360 = db->getRelation("app");
      appindex319 = readrel360->getIndex(ord359, false);
      std::vector<u16> ord361({1, 2, 0});
      slog::Relation* readrel362 = db->getRelation("lambda");
      lambdaindex320 = readrel362->getIndex(ord361, false);
      std::vector<u16> ord363({0, 1, 2});
      slog::Relation* readrel364 = db->getRelation("app");
      appindex321 = readrel364->getIndex(ord363, false);
      std::vector<u16> ord365({0, 1, 2});
      slog::Relation* readrel366 = db->getRelation("lambda");
      lambdaindex322 = readrel366->getIndex(ord365, false);
      std::vector<u16> ord367({0, 1, 2});
      slog::Relation* readrel368 = db->getRelation("lambda");
      lambdaindex323 = readrel368->getIndex(ord367, false);
      std::vector<u16> ord369({2, 0, 1});
      slog::Relation* readrel370 = db->getRelation("app");
      appindex324 = readrel370->getIndex(ord369, false);
      std::vector<u16> ord371({0, 1, 2});
      slog::Relation* readrel372 = db->getRelation("app");
      appindex325 = readrel372->getIndex(ord371, false);
  
    }
    ReadTask326(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c63 = v_const361d5df359e0d7681220d09d;
      u64 v_c64 = v_const4e3b5454cf93e32fad90650d;
      u64 v_c65 = v_const3a82152bd1402931076fe2d7;
      u64 v_c66 = v_constdc1bb6655fb38bdb032e3754;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c67 = _t[0];
        u64 v_c68 = _t[1];
        u64 v_c69 = _t[2];
        if (!slog::exists_probe<2,1>(refindex304, std::array<u64,2>{v_c63, 0})) return;
        if (!slog::exists_probe<2,1>(refindex305, std::array<u64,2>{v_c65, 0})) return;
        if (!slog::exists_probe<2,1>(refindex306, std::array<u64,2>{v_c66, 0})) return;
        if (!slog::exists_probe<2,1>(refindex307, std::array<u64,2>{v_c64, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex308, std::array<u64,3>{v_c65, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex309, std::array<u64,3>{v_c64, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex310, std::array<u64,3>{v_c66, 0, 0})) return;
        slog::join_probe<3,2>(lambdaindex311, std::array<u64,3>{v_c69, v_c63, 0}, [&](const std::array<u64,3>& m373) {
          u64 v_c70 = m373[2];
          slog::join_probe<2,2>(refindex312, std::array<u64,2>{v_c70, v_c63}, [&](const std::array<u64,2>& m374) {
            slog::join_probe<2,1>(refindex313, std::array<u64,2>{v_c65, 0}, [&](const std::array<u64,2>& m375) {
              u64 v_c71 = m375[1];
              if (!slog::exists_probe<3,1>(appindex314, std::array<u64,3>{v_c71, 0, 0})) return;
              slog::join_probe<2,1>(refindex315, std::array<u64,2>{v_c66, 0}, [&](const std::array<u64,2>& m376) {
                u64 v_c72 = m376[1];
                if (!slog::exists_probe<3,1>(appindex316, std::array<u64,3>{v_c72, 0, 0})) return;
                slog::join_probe<2,1>(refindex317, std::array<u64,2>{v_c64, 0}, [&](const std::array<u64,2>& m377) {
                  u64 v_c73 = m377[1];
                  if (!slog::exists_probe<3,1>(appindex318, std::array<u64,3>{v_c73, 0, 0})) return;
                  slog::join_probe<3,1>(appindex319, std::array<u64,3>{v_c71, 0, 0}, [&](const std::array<u64,3>& m378) {
                    u64 v_c74 = m378[1]; u64 v_c75 = m378[2];
                    if (v_c71 != v_c74) return;
                    slog::join_probe<3,2>(lambdaindex320, std::array<u64,3>{v_c65, v_c75, 0}, [&](const std::array<u64,3>& m379) {
                      u64 v_c76 = m379[2];
                      slog::join_probe<3,2>(appindex321, std::array<u64,3>{v_c68, v_c76, 0}, [&](const std::array<u64,3>& m380) {
                        u64 v_c77 = m380[2];
                        slog::join_probe<3,2>(lambdaindex322, std::array<u64,3>{v_c77, v_c64, 0}, [&](const std::array<u64,3>& m381) {
                          u64 v_c78 = m381[2];
                          slog::join_probe<3,2>(lambdaindex323, std::array<u64,3>{v_c78, v_c66, 0}, [&](const std::array<u64,3>& m382) {
                            u64 v_c79 = m382[2];
                            slog::join_probe<3,2>(appindex324, std::array<u64,3>{v_c72, v_c79, 0}, [&](const std::array<u64,3>& m383) {
                              u64 v_c80 = m383[2];
                              slog::join_probe<3,2>(appindex325, std::array<u64,3>{v_c80, v_c73, 0}, [&](const std::array<u64,3>& m384) {
                                u64 v_c81 = m384[2];
                                if (v_c73 != v_c81) return;
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
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:224", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask326* _cont = new ReadTask326(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask326(db,b), false);
  // (crule (pre (let __tconst7sqz226 const7b8fd91ee9ff10cfbb8066bf) (let __tconst1EUj230 const615ad01b1c532bb6634df115) (let __tconst2VuQ234 const4492fd5fa4baacfebd29f5e5) (let __tconst2x2f244 consta32d5a443def48e6d64c6f4b) (let __tconst4Sko246 consteb793a6f75d6cfe49d3c2c90) (let __tconst4N2q248 constaaaad65142343c54348db5d0)) (seeded) (body (join ref (1 0) 1 __tconst4N2q248 __t6KL4241) (exists app (1 2 0) 1 __t6KL4241) (exists ref (1 0) 1 __tconst2x2f244) (exists ref (1 0) 1 __tconst2VuQ234) (exists lambda (1 2 0) 1 __tconst2VuQ234) (exists ref (1 0) 1 __tconst1EUj230) (exists lambda (1 2 0) 1 __tconst1EUj230) (exists ref (1 0) 1 __tconst7sqz226) (exists lambda (1 2 0) 1 __tconst7sqz226) (join ref (1 0) 1 __tconst4Sko246 __t16jv239) (join app (1 2 0) 2 __t6KL4241 __t16jv239 __t4wvK242) (join ref (1 0) 1 __tconst2x2f244 __t3pbc237) (join ref (1 0) 1 __tconst2VuQ234 __t2PLq233) (join lambda (1 2 0) 2 __tconst2VuQ234 __t2PLq233 __t45rU235) (join ref (1 0) 1 __tconst1EUj230 __t3WVP229) (join lambda (1 2 0) 2 __tconst1EUj230 __t3WVP229 __t5ryk231) (join ref (1 0) 1 __tconst7sqz226 __t5APF225) (join lambda (1 2 0) 2 __tconst7sqz226 __t5APF225 __t2BAX227)) (head (mkstruct app (1 2 0) __t5h6K243 __t4wvK242 __t3pbc237)) mcfa-counting.slog:272 #f)
  class ReadTask403 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex385;  slog::Index** appindex386;  slog::Index** refindex387;  slog::Index** refindex388;  slog::Index** lambdaindex389;  slog::Index** refindex390;  slog::Index** lambdaindex391;  slog::Index** refindex392;  slog::Index** lambdaindex393;  slog::Index** refindex394;  slog::Index** appindex395;  slog::Index** refindex396;  slog::Index** refindex397;  slog::Index** lambdaindex398;  slog::Index** refindex399;  slog::Index** lambdaindex400;  slog::Index** refindex401;  slog::Index** lambdaindex402;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord404({1, 2, 0});
      slog::Relation* readrel405 = db->getRelation("app");
      head_index[0] = readrel405->getIndex(ord404, false);
      std::vector<u16> ord406({1, 0});
      slog::Relation* readrel407 = db->getRelation("ref");
      refindex385 = readrel407->getIndex(ord406, false);
      std::vector<u16> ord408({1, 2, 0});
      slog::Relation* readrel409 = db->getRelation("app");
      appindex386 = readrel409->getIndex(ord408, false);
      std::vector<u16> ord410({1, 0});
      slog::Relation* readrel411 = db->getRelation("ref");
      refindex387 = readrel411->getIndex(ord410, false);
      std::vector<u16> ord412({1, 0});
      slog::Relation* readrel413 = db->getRelation("ref");
      refindex388 = readrel413->getIndex(ord412, false);
      std::vector<u16> ord414({1, 2, 0});
      slog::Relation* readrel415 = db->getRelation("lambda");
      lambdaindex389 = readrel415->getIndex(ord414, false);
      std::vector<u16> ord416({1, 0});
      slog::Relation* readrel417 = db->getRelation("ref");
      refindex390 = readrel417->getIndex(ord416, false);
      std::vector<u16> ord418({1, 2, 0});
      slog::Relation* readrel419 = db->getRelation("lambda");
      lambdaindex391 = readrel419->getIndex(ord418, false);
      std::vector<u16> ord420({1, 0});
      slog::Relation* readrel421 = db->getRelation("ref");
      refindex392 = readrel421->getIndex(ord420, false);
      std::vector<u16> ord422({1, 2, 0});
      slog::Relation* readrel423 = db->getRelation("lambda");
      lambdaindex393 = readrel423->getIndex(ord422, false);
      std::vector<u16> ord424({1, 0});
      slog::Relation* readrel425 = db->getRelation("ref");
      refindex394 = readrel425->getIndex(ord424, false);
      std::vector<u16> ord426({1, 2, 0});
      slog::Relation* readrel427 = db->getRelation("app");
      appindex395 = readrel427->getIndex(ord426, false);
      std::vector<u16> ord428({1, 0});
      slog::Relation* readrel429 = db->getRelation("ref");
      refindex396 = readrel429->getIndex(ord428, false);
      std::vector<u16> ord430({1, 0});
      slog::Relation* readrel431 = db->getRelation("ref");
      refindex397 = readrel431->getIndex(ord430, false);
      std::vector<u16> ord432({1, 2, 0});
      slog::Relation* readrel433 = db->getRelation("lambda");
      lambdaindex398 = readrel433->getIndex(ord432, false);
      std::vector<u16> ord434({1, 0});
      slog::Relation* readrel435 = db->getRelation("ref");
      refindex399 = readrel435->getIndex(ord434, false);
      std::vector<u16> ord436({1, 2, 0});
      slog::Relation* readrel437 = db->getRelation("lambda");
      lambdaindex400 = readrel437->getIndex(ord436, false);
      std::vector<u16> ord438({1, 0});
      slog::Relation* readrel439 = db->getRelation("ref");
      refindex401 = readrel439->getIndex(ord438, false);
      std::vector<u16> ord440({1, 2, 0});
      slog::Relation* readrel441 = db->getRelation("lambda");
      lambdaindex402 = readrel441->getIndex(ord440, false);
  
    }
    ReadTask403(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c82 = v_const7b8fd91ee9ff10cfbb8066bf;
      u64 v_c83 = v_const615ad01b1c532bb6634df115;
      u64 v_c84 = v_const4492fd5fa4baacfebd29f5e5;
      u64 v_c85 = v_consta32d5a443def48e6d64c6f4b;
      u64 v_c86 = v_consteb793a6f75d6cfe49d3c2c90;
      u64 v_c87 = v_constaaaad65142343c54348db5d0;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex385, std::array<u64,2>{v_c87, 0}, [&](const std::array<u64,2>& m442) {
        u64 v_c88 = m442[1];
        if (!slog::exists_probe<3,1>(appindex386, std::array<u64,3>{v_c88, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex387, std::array<u64,2>{v_c85, 0})) return;
        if (!slog::exists_probe<2,1>(refindex388, std::array<u64,2>{v_c84, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex389, std::array<u64,3>{v_c84, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex390, std::array<u64,2>{v_c83, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex391, std::array<u64,3>{v_c83, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex392, std::array<u64,2>{v_c82, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex393, std::array<u64,3>{v_c82, 0, 0})) return;
        slog::join_probe<2,1>(refindex394, std::array<u64,2>{v_c86, 0}, [&](const std::array<u64,2>& m443) {
          u64 v_c89 = m443[1];
          slog::join_probe<3,2>(appindex395, std::array<u64,3>{v_c88, v_c89, 0}, [&](const std::array<u64,3>& m444) {
            u64 v_c90 = m444[2];
            slog::join_probe<2,1>(refindex396, std::array<u64,2>{v_c85, 0}, [&](const std::array<u64,2>& m445) {
              u64 v_c91 = m445[1];
              slog::join_probe<2,1>(refindex397, std::array<u64,2>{v_c84, 0}, [&](const std::array<u64,2>& m446) {
                u64 v_c92 = m446[1];
                slog::join_probe<3,2>(lambdaindex398, std::array<u64,3>{v_c84, v_c92, 0}, [&](const std::array<u64,3>& m447) {
                  u64 v_c93 = m447[2];
                  slog::join_probe<2,1>(refindex399, std::array<u64,2>{v_c83, 0}, [&](const std::array<u64,2>& m448) {
                    u64 v_c94 = m448[1];
                    slog::join_probe<3,2>(lambdaindex400, std::array<u64,3>{v_c83, v_c94, 0}, [&](const std::array<u64,3>& m449) {
                      u64 v_c95 = m449[2];
                      slog::join_probe<2,1>(refindex401, std::array<u64,2>{v_c82, 0}, [&](const std::array<u64,2>& m450) {
                        u64 v_c96 = m450[1];
                        slog::join_probe<3,2>(lambdaindex402, std::array<u64,3>{v_c82, v_c96, 0}, [&](const std::array<u64,3>& m451) {
                          u64 v_c97 = m451[2];
                          ++_fires;
                          slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c90, v_c91}, std::array<u16,3>{1, 2, 0});
                        });
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
      s->addTaskSeeded(phase_read, new ReadTask403(db,b));
  // (crule (pre (let __tconst9zoW125 const7c7d2cfc66f4d976987d2d20) (let __tconst4V4L122 const6bc0ba365ada70df115e1785) (let __tconst82U8119 consta8180db1c2f300980314f910) (let __tconst4Zcr91 const9a67f28c6b77e842f439a84a) (let __tconst0vRf84 conste58dec6bca6f63ef79c3b755) (let __tconst3wDH116 constd5f017533ea574d5f9b3400c) (let __tconst4BKz104 const0f8748be649f8ee4066bb1d7) (let __tconst3ktF111 const990b444cbd47632035b2fa1a) (let __tconst5nWJ102 const4f84f41d89b6b717419b4eaa)) (probe lambda (1 2 0) 1 __tconst82U8119 __t50Kk118 __t3SEs120) (body (exists ref (1 0) 1 __tconst0vRf84) (exists lambda (1 2 0) 1 __tconst0vRf84) (exists ref (1 0) 1 __tconst4Zcr91) (exists ref (1 0) 1 __tconst9zoW125) (exists lambda (1 2 0) 1 __tconst4Zcr91) (exists ref (1 0) 1 __tconst4BKz104) (exists lambda (1 2 0) 1 __tconst4BKz104) (exists ref (1 0) 1 __tconst3wDH116) (exists ref (1 0) 1 __tconst5nWJ102) (exists lambda (1 2 0) 1 __tconst5nWJ102) (exists lambda (1 2 0) 1 __tconst3wDH116) (exists lambda (1 2 0) 1 __tconst3ktF111) (exists ref (1 0) 1 __tconst3ktF111) (join ref (1 0) 1 __tconst4V4L122 __t7aew98) (exists app (1 2 0) 1 __t7aew98) (join ref (1 0) 1 __tconst0vRf84 __t2duR83) (join lambda (1 2 0) 2 __tconst0vRf84 __t2duR83 __t87vL85) (join ref (1 0) 1 __tconst4Zcr91 __t0C9F87) (exists app (2 0 1) 1 __t0C9F87) (join ref (1 0) 1 __tconst9zoW125 __t3Q2G89) (join app (1 2 0) 2 __t3Q2G89 __t0C9F87 __t2Eqd90) (join lambda (1 2 0) 2 __tconst4Zcr91 __t2Eqd90 __t3pgm92) (join ref (1 0) 1 __tconst4BKz104 __t8C0a94) (join lambda (1 2 0) 2 __tconst4BKz104 __t8C0a94 __t4fDK96) (join app (1 2 0) 2 __t7aew98 __t4fDK96 __t7TEO99) (join ref (1 0) 1 __tconst3wDH116 __t3wir114) (exists app (1 2 0) 1 __t3wir114) (join ref (1 0) 1 __tconst5nWJ102 __t5MaG101) (join lambda (1 2 0) 2 __tconst5nWJ102 __t5MaG101 __t35jA103) (join lambda (1 2 0) 2 __tconst4BKz104 __t35jA103 __t6RuY105) (join app (1 2 0) 2 __t7aew98 __t6RuY105 __t2Z7m108) (join app (2 0 1) 2 __t2Z7m108 __t50Kk118 __t7CwH117) (join lambda (0 1 2) 2 __t7CwH117 __tconst3wDH116 __t44OM115) (join app (0 1 2) 2 __t44OM115 __t3wir114 __t8GWA112) (join lambda (0 1 2) 2 __t8GWA112 __tconst3ktF111 __t7ohz110) (join ref (0 1) 2 __t7ohz110 __tconst3ktF111)) (head (mkstruct app (1 2 0) __t1GdP121 __t3SEs120 __t7TEO99)) mcfa-counting.slog:241 #f)
  class ReadTask488 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** refindex452;  slog::Index** lambdaindex453;  slog::Index** refindex454;  slog::Index** refindex455;  slog::Index** lambdaindex456;  slog::Index** refindex457;  slog::Index** lambdaindex458;  slog::Index** refindex459;  slog::Index** refindex460;  slog::Index** lambdaindex461;  slog::Index** lambdaindex462;  slog::Index** lambdaindex463;  slog::Index** refindex464;  slog::Index** refindex465;  slog::Index** appindex466;  slog::Index** refindex467;  slog::Index** lambdaindex468;  slog::Index** refindex469;  slog::Index** appindex470;  slog::Index** refindex471;  slog::Index** appindex472;  slog::Index** lambdaindex473;  slog::Index** refindex474;  slog::Index** lambdaindex475;  slog::Index** appindex476;  slog::Index** refindex477;  slog::Index** appindex478;  slog::Index** refindex479;  slog::Index** lambdaindex480;  slog::Index** lambdaindex481;  slog::Index** appindex482;  slog::Index** appindex483;  slog::Index** lambdaindex484;  slog::Index** appindex485;  slog::Index** lambdaindex486;  slog::Index** refindex487;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord489({1, 2, 0});
      slog::Relation* readrel490 = db->getRelation("lambda");
      driver_index = readrel490->getIndex(ord489, true);
      std::vector<u16> ord491({1, 0});
      slog::Relation* readrel492 = db->getRelation("ref");
      refindex452 = readrel492->getIndex(ord491, false);
      std::vector<u16> ord493({1, 2, 0});
      slog::Relation* readrel494 = db->getRelation("lambda");
      lambdaindex453 = readrel494->getIndex(ord493, false);
      std::vector<u16> ord495({1, 0});
      slog::Relation* readrel496 = db->getRelation("ref");
      refindex454 = readrel496->getIndex(ord495, false);
      std::vector<u16> ord497({1, 0});
      slog::Relation* readrel498 = db->getRelation("ref");
      refindex455 = readrel498->getIndex(ord497, false);
      std::vector<u16> ord499({1, 2, 0});
      slog::Relation* readrel500 = db->getRelation("lambda");
      lambdaindex456 = readrel500->getIndex(ord499, false);
      std::vector<u16> ord501({1, 0});
      slog::Relation* readrel502 = db->getRelation("ref");
      refindex457 = readrel502->getIndex(ord501, false);
      std::vector<u16> ord503({1, 2, 0});
      slog::Relation* readrel504 = db->getRelation("lambda");
      lambdaindex458 = readrel504->getIndex(ord503, false);
      std::vector<u16> ord505({1, 0});
      slog::Relation* readrel506 = db->getRelation("ref");
      refindex459 = readrel506->getIndex(ord505, false);
      std::vector<u16> ord507({1, 0});
      slog::Relation* readrel508 = db->getRelation("ref");
      refindex460 = readrel508->getIndex(ord507, false);
      std::vector<u16> ord509({1, 2, 0});
      slog::Relation* readrel510 = db->getRelation("lambda");
      lambdaindex461 = readrel510->getIndex(ord509, false);
      std::vector<u16> ord511({1, 2, 0});
      slog::Relation* readrel512 = db->getRelation("lambda");
      lambdaindex462 = readrel512->getIndex(ord511, false);
      std::vector<u16> ord513({1, 2, 0});
      slog::Relation* readrel514 = db->getRelation("lambda");
      lambdaindex463 = readrel514->getIndex(ord513, false);
      std::vector<u16> ord515({1, 0});
      slog::Relation* readrel516 = db->getRelation("ref");
      refindex464 = readrel516->getIndex(ord515, false);
      std::vector<u16> ord517({1, 0});
      slog::Relation* readrel518 = db->getRelation("ref");
      refindex465 = readrel518->getIndex(ord517, false);
      std::vector<u16> ord519({1, 2, 0});
      slog::Relation* readrel520 = db->getRelation("app");
      appindex466 = readrel520->getIndex(ord519, false);
      std::vector<u16> ord521({1, 0});
      slog::Relation* readrel522 = db->getRelation("ref");
      refindex467 = readrel522->getIndex(ord521, false);
      std::vector<u16> ord523({1, 2, 0});
      slog::Relation* readrel524 = db->getRelation("lambda");
      lambdaindex468 = readrel524->getIndex(ord523, false);
      std::vector<u16> ord525({1, 0});
      slog::Relation* readrel526 = db->getRelation("ref");
      refindex469 = readrel526->getIndex(ord525, false);
      std::vector<u16> ord527({2, 0, 1});
      slog::Relation* readrel528 = db->getRelation("app");
      appindex470 = readrel528->getIndex(ord527, false);
      std::vector<u16> ord529({1, 0});
      slog::Relation* readrel530 = db->getRelation("ref");
      refindex471 = readrel530->getIndex(ord529, false);
      std::vector<u16> ord531({1, 2, 0});
      slog::Relation* readrel532 = db->getRelation("app");
      appindex472 = readrel532->getIndex(ord531, false);
      std::vector<u16> ord533({1, 2, 0});
      slog::Relation* readrel534 = db->getRelation("lambda");
      lambdaindex473 = readrel534->getIndex(ord533, false);
      std::vector<u16> ord535({1, 0});
      slog::Relation* readrel536 = db->getRelation("ref");
      refindex474 = readrel536->getIndex(ord535, false);
      std::vector<u16> ord537({1, 2, 0});
      slog::Relation* readrel538 = db->getRelation("lambda");
      lambdaindex475 = readrel538->getIndex(ord537, false);
      std::vector<u16> ord539({1, 2, 0});
      slog::Relation* readrel540 = db->getRelation("app");
      appindex476 = readrel540->getIndex(ord539, false);
      std::vector<u16> ord541({1, 0});
      slog::Relation* readrel542 = db->getRelation("ref");
      refindex477 = readrel542->getIndex(ord541, false);
      std::vector<u16> ord543({1, 2, 0});
      slog::Relation* readrel544 = db->getRelation("app");
      appindex478 = readrel544->getIndex(ord543, false);
      std::vector<u16> ord545({1, 0});
      slog::Relation* readrel546 = db->getRelation("ref");
      refindex479 = readrel546->getIndex(ord545, false);
      std::vector<u16> ord547({1, 2, 0});
      slog::Relation* readrel548 = db->getRelation("lambda");
      lambdaindex480 = readrel548->getIndex(ord547, false);
      std::vector<u16> ord549({1, 2, 0});
      slog::Relation* readrel550 = db->getRelation("lambda");
      lambdaindex481 = readrel550->getIndex(ord549, false);
      std::vector<u16> ord551({1, 2, 0});
      slog::Relation* readrel552 = db->getRelation("app");
      appindex482 = readrel552->getIndex(ord551, false);
      std::vector<u16> ord553({2, 0, 1});
      slog::Relation* readrel554 = db->getRelation("app");
      appindex483 = readrel554->getIndex(ord553, false);
      std::vector<u16> ord555({0, 1, 2});
      slog::Relation* readrel556 = db->getRelation("lambda");
      lambdaindex484 = readrel556->getIndex(ord555, false);
      std::vector<u16> ord557({0, 1, 2});
      slog::Relation* readrel558 = db->getRelation("app");
      appindex485 = readrel558->getIndex(ord557, false);
      std::vector<u16> ord559({0, 1, 2});
      slog::Relation* readrel560 = db->getRelation("lambda");
      lambdaindex486 = readrel560->getIndex(ord559, false);
      std::vector<u16> ord561({0, 1});
      slog::Relation* readrel562 = db->getRelation("ref");
      refindex487 = readrel562->getIndex(ord561, false);
  
    }
    ReadTask488(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c33 = v_const7c7d2cfc66f4d976987d2d20;
      u64 v_c34 = v_const6bc0ba365ada70df115e1785;
      u64 v_c35 = v_consta8180db1c2f300980314f910;
      u64 v_c36 = v_const9a67f28c6b77e842f439a84a;
      u64 v_c37 = v_conste58dec6bca6f63ef79c3b755;
      u64 v_c38 = v_constd5f017533ea574d5f9b3400c;
      u64 v_c39 = v_const0f8748be649f8ee4066bb1d7;
      u64 v_c40 = v_const990b444cbd47632035b2fa1a;
      u64 v_c41 = v_const4f84f41d89b6b717419b4eaa;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c35, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m563) {
        u64 v_c61 = m563[1];
        u64 v_c62 = m563[2];
        if (buckethash(v_c61) != bucket) return;
        if (!slog::exists_probe<2,1>(refindex452, std::array<u64,2>{v_c37, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex453, std::array<u64,3>{v_c37, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex454, std::array<u64,2>{v_c36, 0})) return;
        if (!slog::exists_probe<2,1>(refindex455, std::array<u64,2>{v_c33, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex456, std::array<u64,3>{v_c36, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex457, std::array<u64,2>{v_c39, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex458, std::array<u64,3>{v_c39, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex459, std::array<u64,2>{v_c38, 0})) return;
        if (!slog::exists_probe<2,1>(refindex460, std::array<u64,2>{v_c41, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex461, std::array<u64,3>{v_c41, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex462, std::array<u64,3>{v_c38, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex463, std::array<u64,3>{v_c40, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex464, std::array<u64,2>{v_c40, 0})) return;
        slog::join_probe<2,1>(refindex465, std::array<u64,2>{v_c34, 0}, [&](const std::array<u64,2>& m564) {
          u64 v_c42 = m564[1];
          if (!slog::exists_probe<3,1>(appindex466, std::array<u64,3>{v_c42, 0, 0})) return;
          slog::join_probe<2,1>(refindex467, std::array<u64,2>{v_c37, 0}, [&](const std::array<u64,2>& m565) {
            u64 v_c43 = m565[1];
            slog::join_probe<3,2>(lambdaindex468, std::array<u64,3>{v_c37, v_c43, 0}, [&](const std::array<u64,3>& m566) {
              u64 v_c44 = m566[2];
              slog::join_probe<2,1>(refindex469, std::array<u64,2>{v_c36, 0}, [&](const std::array<u64,2>& m567) {
                u64 v_c45 = m567[1];
                if (!slog::exists_probe<3,1>(appindex470, std::array<u64,3>{v_c45, 0, 0})) return;
                slog::join_probe<2,1>(refindex471, std::array<u64,2>{v_c33, 0}, [&](const std::array<u64,2>& m568) {
                  u64 v_c46 = m568[1];
                  slog::join_probe<3,2>(appindex472, std::array<u64,3>{v_c46, v_c45, 0}, [&](const std::array<u64,3>& m569) {
                    u64 v_c47 = m569[2];
                    slog::join_probe<3,2>(lambdaindex473, std::array<u64,3>{v_c36, v_c47, 0}, [&](const std::array<u64,3>& m570) {
                      u64 v_c48 = m570[2];
                      slog::join_probe<2,1>(refindex474, std::array<u64,2>{v_c39, 0}, [&](const std::array<u64,2>& m571) {
                        u64 v_c49 = m571[1];
                        slog::join_probe<3,2>(lambdaindex475, std::array<u64,3>{v_c39, v_c49, 0}, [&](const std::array<u64,3>& m572) {
                          u64 v_c50 = m572[2];
                          slog::join_probe<3,2>(appindex476, std::array<u64,3>{v_c42, v_c50, 0}, [&](const std::array<u64,3>& m573) {
                            u64 v_c51 = m573[2];
                            slog::join_probe<2,1>(refindex477, std::array<u64,2>{v_c38, 0}, [&](const std::array<u64,2>& m574) {
                              u64 v_c52 = m574[1];
                              if (!slog::exists_probe<3,1>(appindex478, std::array<u64,3>{v_c52, 0, 0})) return;
                              slog::join_probe<2,1>(refindex479, std::array<u64,2>{v_c41, 0}, [&](const std::array<u64,2>& m575) {
                                u64 v_c53 = m575[1];
                                slog::join_probe<3,2>(lambdaindex480, std::array<u64,3>{v_c41, v_c53, 0}, [&](const std::array<u64,3>& m576) {
                                  u64 v_c54 = m576[2];
                                  slog::join_probe<3,2>(lambdaindex481, std::array<u64,3>{v_c39, v_c54, 0}, [&](const std::array<u64,3>& m577) {
                                    u64 v_c55 = m577[2];
                                    slog::join_probe<3,2>(appindex482, std::array<u64,3>{v_c42, v_c55, 0}, [&](const std::array<u64,3>& m578) {
                                      u64 v_c56 = m578[2];
                                      slog::join_probe<3,2>(appindex483, std::array<u64,3>{v_c56, v_c61, 0}, [&](const std::array<u64,3>& m579) {
                                        u64 v_c60 = m579[2];
                                        slog::join_probe<3,2>(lambdaindex484, std::array<u64,3>{v_c60, v_c38, 0}, [&](const std::array<u64,3>& m580) {
                                          u64 v_c59 = m580[2];
                                          slog::join_probe<3,2>(appindex485, std::array<u64,3>{v_c59, v_c52, 0}, [&](const std::array<u64,3>& m581) {
                                            u64 v_c58 = m581[2];
                                            slog::join_probe<3,2>(lambdaindex486, std::array<u64,3>{v_c58, v_c40, 0}, [&](const std::array<u64,3>& m582) {
                                              u64 v_c57 = m582[2];
                                              slog::join_probe<2,2>(refindex487, std::array<u64,2>{v_c57, v_c40}, [&](const std::array<u64,2>& m583) {
                                                ++_fires;
                                                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c62, v_c51}, std::array<u16,3>{1, 2, 0});
                                              });
                                            });
                                          });
                                        });
                                      });
                                    });
                                  });
                                });
                              });
                            });
                          });
                        });
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
        ReadTask488* _cont = new ReadTask488(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask488(db,b), false);
  // (crule (pre) (scan ref __t2jDL164 x) (body (exists eval (1 2 0) 1 __t2jDL164) (join store (0 1 2) 1 x c v) (join-old eval (1 2 0) 2 (1 2 0) __t2jDL164 c __t8FVl165)) (head (emit eval_ans (0 1) __t8FVl165 v)) mcfa-counting.slog:81 #f)
  class ReadTask588 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex584;  slog::Index** storeindex585;  slog::Index** evalindex586;  slog::Index** evaldelta587;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord589({0, 1});
      slog::Relation* readrel590 = db->getRelation("eval_ans");
      head_index[0] = readrel590->getIndex(ord589, false);
      outer_rel = db->getRelation("ref");
      std::vector<u16> ord591({1, 2, 0});
      slog::Relation* readrel592 = db->getRelation("eval");
      evalindex584 = readrel592->getIndex(ord591, false);
      std::vector<u16> ord593({0, 1, 2});
      slog::Relation* readrel594 = db->getRelation("store");
      storeindex585 = readrel594->getIndex(ord593, false);
      std::vector<u16> ord595({1, 2, 0});
      slog::Relation* readrel596 = db->getRelation("eval");
      evalindex586 = readrel596->getIndex(ord595, false);
      std::vector<u16> ord597({1, 2, 0});
      slog::Relation* readrel598 = db->getRelation("eval");
      evaldelta587 = readrel598->getIndex(ord597, true);
  
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
        u64 v_c98 = _t[0];
        u64 v_c6 = _t[1];
        if (!slog::exists_probe<3,1>(evalindex584, std::array<u64,3>{v_c98, 0, 0})) return;
        slog::join_probe<3,1>(storeindex585, std::array<u64,3>{v_c6, 0, 0}, [&](const std::array<u64,3>& m599) {
          u64 v_c2 = m599[1]; u64 v_c99 = m599[2];
          slog::join_probe_old<3,2>(evalindex586, evaldelta587, std::array<u64,3>{v_c98, v_c2, 0}, [&](const std::array<u64,3>& m600) {
            u64 v_c100 = m600[2];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c100, v_c99}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:81", "delta:ref", _fires);
  
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
  // (crule (pre (let __tconst1pJW313 constb49bea2fcccd8f4301a347ed) (let __tconst7LWP310 const66518c0c1b3a5a0b09ae2ef1) (let __tconst0sqO307 const4a8acfc71441e0695ffcf5b3) (let __tconst2CSv302 const229c0b7aa8a7eb4055f5a3d0) (let __tconst9rZO295 const576506f61f53440f1edd95d2) (let __tconst5PoN291 constc85eae03730a4f4cf1d66a0c) (let __tconst2Yzp284 const8ca682693a0738a0641c6956)) (probe ref (1 0) 1 __tconst2Yzp284 __t248W283) (body (exists ref (1 0) 1 __tconst9rZO295) (exists ref (1 0) 1 __tconst7LWP310) (exists ref (1 0) 1 __tconst2CSv302) (join ref (1 0) 1 __tconst1pJW313 __t165O287) (join ref (1 0) 1 __tconst9rZO295 __t71w7294) (join ref (1 0) 1 __tconst7LWP310 __t91H2298) (join ref (1 0) 1 __tconst2CSv302 __t6lXa301)) (head (mkstruct lambda (1 2 0) __t7EW2303 __tconst2CSv302 __t6lXa301) (mkstruct lambda (1 2 0) __t3dkk296 __tconst9rZO295 __t71w7294) (mkstruct app (1 2 0) __t30Ec290 __t165O287 __t165O287) (mkstruct lambda (1 2 0) __t0oFu285 __tconst2Yzp284 __t248W283)) mcfa-counting.slog:194 #f)
  class ReadTask608 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[4];
    slog::Index** head_index[4];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** refindex601;  slog::Index** refindex602;  slog::Index** refindex603;  slog::Index** refindex604;  slog::Index** refindex605;  slog::Index** refindex606;  slog::Index** refindex607;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      head_rel[1] = db->getRelation("lambda");
      head_rel[2] = db->getRelation("app");
      head_rel[3] = db->getRelation("lambda");
      std::vector<u16> ord609({1, 0});
      slog::Relation* readrel610 = db->getRelation("ref");
      driver_index = readrel610->getIndex(ord609, true);
      std::vector<u16> ord611({1, 0});
      slog::Relation* readrel612 = db->getRelation("ref");
      refindex601 = readrel612->getIndex(ord611, false);
      std::vector<u16> ord613({1, 0});
      slog::Relation* readrel614 = db->getRelation("ref");
      refindex602 = readrel614->getIndex(ord613, false);
      std::vector<u16> ord615({1, 0});
      slog::Relation* readrel616 = db->getRelation("ref");
      refindex603 = readrel616->getIndex(ord615, false);
      std::vector<u16> ord617({1, 0});
      slog::Relation* readrel618 = db->getRelation("ref");
      refindex604 = readrel618->getIndex(ord617, false);
      std::vector<u16> ord619({1, 0});
      slog::Relation* readrel620 = db->getRelation("ref");
      refindex605 = readrel620->getIndex(ord619, false);
      std::vector<u16> ord621({1, 0});
      slog::Relation* readrel622 = db->getRelation("ref");
      refindex606 = readrel622->getIndex(ord621, false);
      std::vector<u16> ord623({1, 0});
      slog::Relation* readrel624 = db->getRelation("ref");
      refindex607 = readrel624->getIndex(ord623, false);
  
    }
    ReadTask608(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c101 = v_constb49bea2fcccd8f4301a347ed;
      u64 v_c102 = v_const66518c0c1b3a5a0b09ae2ef1;
      u64 v_c103 = v_const4a8acfc71441e0695ffcf5b3;
      u64 v_c104 = v_const229c0b7aa8a7eb4055f5a3d0;
      u64 v_c105 = v_const576506f61f53440f1edd95d2;
      u64 v_c106 = v_constc85eae03730a4f4cf1d66a0c;
      u64 v_c107 = v_const8ca682693a0738a0641c6956;
  
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
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c107, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m625) {
        u64 v_c108 = m625[1];
        if (buckethash(v_c108) != bucket) return;
        if (!slog::exists_probe<2,1>(refindex601, std::array<u64,2>{v_c105, 0})) return;
        if (!slog::exists_probe<2,1>(refindex602, std::array<u64,2>{v_c102, 0})) return;
        if (!slog::exists_probe<2,1>(refindex603, std::array<u64,2>{v_c104, 0})) return;
        slog::join_probe<2,1>(refindex604, std::array<u64,2>{v_c101, 0}, [&](const std::array<u64,2>& m626) {
          u64 v_c109 = m626[1];
          slog::join_probe<2,1>(refindex605, std::array<u64,2>{v_c105, 0}, [&](const std::array<u64,2>& m627) {
            u64 v_c110 = m627[1];
            slog::join_probe<2,1>(refindex606, std::array<u64,2>{v_c102, 0}, [&](const std::array<u64,2>& m628) {
              u64 v_c111 = m628[1];
              slog::join_probe<2,1>(refindex607, std::array<u64,2>{v_c104, 0}, [&](const std::array<u64,2>& m629) {
                u64 v_c112 = m629[1];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c104, v_c112}, std::array<u16,3>{1, 2, 0});
                slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c105, v_c110}, std::array<u16,3>{1, 2, 0});
                slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c109, v_c109}, std::array<u16,3>{1, 2, 0});
                slog::emit_struct<3>(head_rel[3], newbatch[3], std::array<u64,2>{v_c107, v_c108}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:194", "delta:ref", _fires);
  
      if (!_done)
      {
        ReadTask608* _cont = new ReadTask608(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask608(db,b), false);
  // (crule (pre) (scan eval __t5GoB317 __t3MbO322 c) (body (exists $sup27994x83x0x0x1 (0 3 6 5 7 1 2 4 8 9) 2 __t5GoB317 c) (exists eval (2 0 1) 1 c) (exists eval (2 0 1) 1 __t3MbO322) (join $sup27994x83x0x0x0 (0 1 2 3) 2 __t5GoB317 c ea ef) (join-old app (0 1 2) 3 (0 1 2) __t3MbO322 ef ea) (exists eval (1 2 0) 2 ef c) (exists eval (1 2 0) 2 ea c) (join $sup27994x83x0x0x1 (5 7 0 3 1 2 4 6 8 9) 4 ea ef __t5GoB317 c __t1FV8318 __t8XTs321 cb eb va x) (join-old eval (0 2 1) 3 (0 2 1) __t1FV8318 c ef) (join-old eval (0 2 1) 3 (0 2 1) __t8XTs321 c ea) (join eval_ans (0 1) 2 __t8XTs321 va) (exists clo (2 0 1) 1 cb) (exists eval_ans (0 1) 1 __t1FV8318) (exists eval (1 2 0) 2 eb __t3MbO322) (join-old lambda (1 2 0) 2 (1 2 0) x eb __t6vap319) (join-old clo (1 2 0) 2 (1 2 0) __t6vap319 cb __t1oxE320) (join eval_ans (0 1) 2 __t1FV8318 __t1oxE320) (join-old eval (1 2 0) 2 (1 2 0) eb __t3MbO322 __t3H1A323) (join eval_ans (0 1) 1 __t3H1A323 v)) (head (emit eval_ans (0 1) __t5GoB317 v)) mcfa-counting.slog:84 #f)
  class ReadTask655 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup27994x83x0x0x1index630;  slog::Index** evalindex631;  slog::Index** evalindex632;  slog::Index** $sup27994x83x0x0x0index633;  slog::Index** appindex634;  slog::Index** evalindex635;  slog::Index** evalindex636;  slog::Index** $sup27994x83x0x0x1index637;  slog::Index** evalindex638;  slog::Index** evalindex639;  slog::Index** eval_ansindex640;  slog::Index** cloindex641;  slog::Index** eval_ansindex642;  slog::Index** evalindex643;  slog::Index** lambdaindex644;  slog::Index** cloindex645;  slog::Index** eval_ansindex646;  slog::Index** evalindex647;  slog::Index** eval_ansindex648;  slog::Index** appdelta649;  slog::Index** evaldelta650;  slog::Index** evaldelta651;  slog::Index** lambdadelta652;  slog::Index** clodelta653;  slog::Index** evaldelta654;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord656({0, 1});
      slog::Relation* readrel657 = db->getRelation("eval_ans");
      head_index[0] = readrel657->getIndex(ord656, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord658({0, 3, 6, 5, 7, 1, 2, 4, 8, 9});
      slog::Relation* readrel659 = db->getRelation("$sup27994x83x0x0x1");
      $sup27994x83x0x0x1index630 = readrel659->getIndex(ord658, false);
      std::vector<u16> ord660({2, 0, 1});
      slog::Relation* readrel661 = db->getRelation("eval");
      evalindex631 = readrel661->getIndex(ord660, false);
      std::vector<u16> ord662({2, 0, 1});
      slog::Relation* readrel663 = db->getRelation("eval");
      evalindex632 = readrel663->getIndex(ord662, false);
      std::vector<u16> ord664({0, 1, 2, 3});
      slog::Relation* readrel665 = db->getRelation("$sup27994x83x0x0x0");
      $sup27994x83x0x0x0index633 = readrel665->getIndex(ord664, false);
      std::vector<u16> ord666({0, 1, 2});
      slog::Relation* readrel667 = db->getRelation("app");
      appindex634 = readrel667->getIndex(ord666, false);
      std::vector<u16> ord668({0, 1, 2});
      slog::Relation* readrel669 = db->getRelation("app");
      appdelta649 = readrel669->getIndex(ord668, true);
      std::vector<u16> ord670({1, 2, 0});
      slog::Relation* readrel671 = db->getRelation("eval");
      evalindex635 = readrel671->getIndex(ord670, false);
      std::vector<u16> ord672({1, 2, 0});
      slog::Relation* readrel673 = db->getRelation("eval");
      evalindex636 = readrel673->getIndex(ord672, false);
      std::vector<u16> ord674({5, 7, 0, 3, 1, 2, 4, 6, 8, 9});
      slog::Relation* readrel675 = db->getRelation("$sup27994x83x0x0x1");
      $sup27994x83x0x0x1index637 = readrel675->getIndex(ord674, false);
      std::vector<u16> ord676({0, 2, 1});
      slog::Relation* readrel677 = db->getRelation("eval");
      evalindex638 = readrel677->getIndex(ord676, false);
      std::vector<u16> ord678({0, 2, 1});
      slog::Relation* readrel679 = db->getRelation("eval");
      evaldelta650 = readrel679->getIndex(ord678, true);
      std::vector<u16> ord680({0, 2, 1});
      slog::Relation* readrel681 = db->getRelation("eval");
      evalindex639 = readrel681->getIndex(ord680, false);
      std::vector<u16> ord682({0, 2, 1});
      slog::Relation* readrel683 = db->getRelation("eval");
      evaldelta651 = readrel683->getIndex(ord682, true);
      std::vector<u16> ord684({0, 1});
      slog::Relation* readrel685 = db->getRelation("eval_ans");
      eval_ansindex640 = readrel685->getIndex(ord684, false);
      std::vector<u16> ord686({2, 0, 1});
      slog::Relation* readrel687 = db->getRelation("clo");
      cloindex641 = readrel687->getIndex(ord686, false);
      std::vector<u16> ord688({0, 1});
      slog::Relation* readrel689 = db->getRelation("eval_ans");
      eval_ansindex642 = readrel689->getIndex(ord688, false);
      std::vector<u16> ord690({1, 2, 0});
      slog::Relation* readrel691 = db->getRelation("eval");
      evalindex643 = readrel691->getIndex(ord690, false);
      std::vector<u16> ord692({1, 2, 0});
      slog::Relation* readrel693 = db->getRelation("lambda");
      lambdaindex644 = readrel693->getIndex(ord692, false);
      std::vector<u16> ord694({1, 2, 0});
      slog::Relation* readrel695 = db->getRelation("lambda");
      lambdadelta652 = readrel695->getIndex(ord694, true);
      std::vector<u16> ord696({1, 2, 0});
      slog::Relation* readrel697 = db->getRelation("clo");
      cloindex645 = readrel697->getIndex(ord696, false);
      std::vector<u16> ord698({1, 2, 0});
      slog::Relation* readrel699 = db->getRelation("clo");
      clodelta653 = readrel699->getIndex(ord698, true);
      std::vector<u16> ord700({0, 1});
      slog::Relation* readrel701 = db->getRelation("eval_ans");
      eval_ansindex646 = readrel701->getIndex(ord700, false);
      std::vector<u16> ord702({1, 2, 0});
      slog::Relation* readrel703 = db->getRelation("eval");
      evalindex647 = readrel703->getIndex(ord702, false);
      std::vector<u16> ord704({1, 2, 0});
      slog::Relation* readrel705 = db->getRelation("eval");
      evaldelta654 = readrel705->getIndex(ord704, true);
      std::vector<u16> ord706({0, 1});
      slog::Relation* readrel707 = db->getRelation("eval_ans");
      eval_ansindex648 = readrel707->getIndex(ord706, false);
  
    }
    ReadTask655(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c2 = _t[2];
        if (!slog::exists_probe<10,2>($sup27994x83x0x0x1index630, std::array<u64,10>{v_c113, v_c2, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(evalindex631, std::array<u64,3>{v_c2, 0, 0})) return;
        if (!slog::exists_probe<3,1>(evalindex632, std::array<u64,3>{v_c114, 0, 0})) return;
        slog::join_probe<4,2>($sup27994x83x0x0x0index633, std::array<u64,4>{v_c113, v_c2, 0, 0}, [&](const std::array<u64,4>& m708) {
          u64 v_c4 = m708[2]; u64 v_c3 = m708[3];
          slog::join_probe_old<3,3>(appindex634, appdelta649, std::array<u64,3>{v_c114, v_c3, v_c4}, [&](const std::array<u64,3>& m709) {
            if (!slog::exists_probe<3,2>(evalindex635, std::array<u64,3>{v_c3, v_c2, 0})) return;
            if (!slog::exists_probe<3,2>(evalindex636, std::array<u64,3>{v_c4, v_c2, 0})) return;
            slog::join_probe<10,4>($sup27994x83x0x0x1index637, std::array<u64,10>{v_c4, v_c3, v_c113, v_c2, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,10>& m710) {
              u64 v_c115 = m710[4]; u64 v_c116 = m710[5]; u64 v_c117 = m710[6]; u64 v_c118 = m710[7]; u64 v_c119 = m710[8]; u64 v_c6 = m710[9];
              slog::join_probe_old<3,3>(evalindex638, evaldelta650, std::array<u64,3>{v_c115, v_c2, v_c3}, [&](const std::array<u64,3>& m711) {
                slog::join_probe_old<3,3>(evalindex639, evaldelta651, std::array<u64,3>{v_c116, v_c2, v_c4}, [&](const std::array<u64,3>& m712) {
                  slog::join_probe<2,2>(eval_ansindex640, std::array<u64,2>{v_c116, v_c119}, [&](const std::array<u64,2>& m713) {
                    if (!slog::exists_probe<3,1>(cloindex641, std::array<u64,3>{v_c117, 0, 0})) return;
                    if (!slog::exists_probe<2,1>(eval_ansindex642, std::array<u64,2>{v_c115, 0})) return;
                    if (!slog::exists_probe<3,2>(evalindex643, std::array<u64,3>{v_c118, v_c114, 0})) return;
                    slog::join_probe_old<3,2>(lambdaindex644, lambdadelta652, std::array<u64,3>{v_c6, v_c118, 0}, [&](const std::array<u64,3>& m714) {
                      u64 v_c120 = m714[2];
                      slog::join_probe_old<3,2>(cloindex645, clodelta653, std::array<u64,3>{v_c120, v_c117, 0}, [&](const std::array<u64,3>& m715) {
                        u64 v_c121 = m715[2];
                        slog::join_probe<2,2>(eval_ansindex646, std::array<u64,2>{v_c115, v_c121}, [&](const std::array<u64,2>& m716) {
                          slog::join_probe_old<3,2>(evalindex647, evaldelta654, std::array<u64,3>{v_c118, v_c114, 0}, [&](const std::array<u64,3>& m717) {
                            u64 v_c122 = m717[2];
                            slog::join_probe<2,1>(eval_ansindex648, std::array<u64,2>{v_c122, 0}, [&](const std::array<u64,2>& m718) {
                              u64 v_c99 = m718[1];
                              ++_fires;
                              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c113, v_c99}, std::array<u16,2>{0, 1});
                            });
                          });
                        });
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
        ReadTask655* _cont = new ReadTask655(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask655(db,b), false);
  // (crule (pre) (scan clo __t3EGT159 __t1L8v158 cb) (body (join eval_ans (1 0) 1 __t3EGT159 __t8nKY157) (join eval (0 2 1) 1 __t8nKY157 c ef) (exists eval (2 0 1) 1 c) (join $sup27994x83x0x0x0 (1 3 0 2) 2 c ef __d0 ea) (join-old eval (1 2 0) 2 (1 2 0) ea c __t4j5Q160) (join eval_ans (0 1) 1 __t4j5Q160 va) (join lambda (0 1 2) 1 __t1L8v158 x eb)) (head (emit $sup27994x83x0x0x1 (1 4 0 2 3 5 6 7 8 9) __t8nKY157 cb __d0 __t4j5Q160 c ea eb ef va x)) mcfa-counting.slog:84 #f)
  class ReadTask727 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** eval_ansindex719;  slog::Index** evalindex720;  slog::Index** evalindex721;  slog::Index** $sup27994x83x0x0x0index722;  slog::Index** evalindex723;  slog::Index** eval_ansindex724;  slog::Index** lambdaindex725;  slog::Index** evaldelta726;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup27994x83x0x0x1");
      std::vector<u16> ord728({1, 4, 0, 2, 3, 5, 6, 7, 8, 9});
      slog::Relation* readrel729 = db->getRelation("$sup27994x83x0x0x1");
      head_index[0] = readrel729->getIndex(ord728, false);
      outer_rel = db->getRelation("clo");
      std::vector<u16> ord730({1, 0});
      slog::Relation* readrel731 = db->getRelation("eval_ans");
      eval_ansindex719 = readrel731->getIndex(ord730, false);
      std::vector<u16> ord732({0, 2, 1});
      slog::Relation* readrel733 = db->getRelation("eval");
      evalindex720 = readrel733->getIndex(ord732, false);
      std::vector<u16> ord734({2, 0, 1});
      slog::Relation* readrel735 = db->getRelation("eval");
      evalindex721 = readrel735->getIndex(ord734, false);
      std::vector<u16> ord736({1, 3, 0, 2});
      slog::Relation* readrel737 = db->getRelation("$sup27994x83x0x0x0");
      $sup27994x83x0x0x0index722 = readrel737->getIndex(ord736, false);
      std::vector<u16> ord738({1, 2, 0});
      slog::Relation* readrel739 = db->getRelation("eval");
      evalindex723 = readrel739->getIndex(ord738, false);
      std::vector<u16> ord740({1, 2, 0});
      slog::Relation* readrel741 = db->getRelation("eval");
      evaldelta726 = readrel741->getIndex(ord740, true);
      std::vector<u16> ord742({0, 1});
      slog::Relation* readrel743 = db->getRelation("eval_ans");
      eval_ansindex724 = readrel743->getIndex(ord742, false);
      std::vector<u16> ord744({0, 1, 2});
      slog::Relation* readrel745 = db->getRelation("lambda");
      lambdaindex725 = readrel745->getIndex(ord744, false);
  
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
        u64 v_c123 = _t[0];
        u64 v_c124 = _t[1];
        u64 v_c117 = _t[2];
        slog::join_probe<2,1>(eval_ansindex719, std::array<u64,2>{v_c123, 0}, [&](const std::array<u64,2>& m746) {
          u64 v_c125 = m746[1];
          slog::join_probe<3,1>(evalindex720, std::array<u64,3>{v_c125, 0, 0}, [&](const std::array<u64,3>& m747) {
            u64 v_c2 = m747[1]; u64 v_c3 = m747[2];
            if (!slog::exists_probe<3,1>(evalindex721, std::array<u64,3>{v_c2, 0, 0})) return;
            slog::join_probe<4,2>($sup27994x83x0x0x0index722, std::array<u64,4>{v_c2, v_c3, 0, 0}, [&](const std::array<u64,4>& m748) {
              u64 v_c126 = m748[2]; u64 v_c4 = m748[3];
              slog::join_probe_old<3,2>(evalindex723, evaldelta726, std::array<u64,3>{v_c4, v_c2, 0}, [&](const std::array<u64,3>& m749) {
                u64 v_c127 = m749[2];
                slog::join_probe<2,1>(eval_ansindex724, std::array<u64,2>{v_c127, 0}, [&](const std::array<u64,2>& m750) {
                  u64 v_c119 = m750[1];
                  slog::join_probe<3,1>(lambdaindex725, std::array<u64,3>{v_c124, 0, 0}, [&](const std::array<u64,3>& m751) {
                    u64 v_c6 = m751[1]; u64 v_c118 = m751[2];
                    ++_fires;
                    slog::emit<10>(head_rel[0], head_index[0], newbatch[0], std::array<u64,10>{v_c125, v_c117, v_c126, v_c127, v_c2, v_c4, v_c118, v_c3, v_c119, v_c6}, std::array<u16,10>{1, 4, 0, 2, 3, 5, 6, 7, 8, 9});
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
  // (crule (pre (let __trid7xrX339 const07ef7e8462f6d369d70a1f0e) (let __trel02kV340 const4a59dbb9cb3129dfcc75170b) (let __tcol5aM8341 const5feceb66ffc86f38d952786c) (let __trel2pHh342 const4a59dbb9cb3129dfcc75170b) (let __tcol2eEq343 const6b86b273ff34fce19d6b804e)) (scan $sup27994x83x0x0x0 __d0 c ea ef) (body) (head (tycheck ef (accept (struct app) (struct lambda) (struct ref)) __trid7xrX339 __trel02kV340 __tcol5aM8341 (1 2 3 4 0)) (tycheck c (accept (struct app) (struct _enum)) __trid7xrX339 __trel2pHh342 __tcol2eEq343 (1 2 3 4 0)) (mkstruct eval (1 2 0) __9GSL338 ef c)) mcfa-counting.slog:84 #f)
  class ReadTask756 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid755;  u32 sid752;  u32 sid753;  u32 sid754;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("eval");
      outer_rel = db->getRelation("$sup27994x83x0x0x0");
      sid755 = db->getRelation("_enum")->getStructId();
      sid752 = db->getRelation("app")->getStructId();
      sid753 = db->getRelation("lambda")->getStructId();
      sid754 = db->getRelation("ref")->getStructId();
  
    }
    ReadTask756(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c128 = v_const07ef7e8462f6d369d70a1f0e;
      u64 v_c129 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c130 = v_const5feceb66ffc86f38d952786c;
      u64 v_c131 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c132 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c126 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c4 = _t[2];
        u64 v_c3 = _t[3];
        ++_fires;
        if (!((is_struct(v_c3) && (decode_struct_id(v_c3) == sid752 || decode_struct_id(v_c3) == sid753 || decode_struct_id(v_c3) == sid754))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c128, v_c129, v_c130, v_c3}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c2) && (decode_struct_id(v_c2) == sid752 || decode_struct_id(v_c2) == sid755))))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c128, v_c131, v_c132, v_c2}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c3, v_c2}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:84", "delta:$sup27994x83x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask756* _cont = new ReadTask756(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask756(db,b), false);
  // (crule (pre (let __tconst4N2q248 constaaaad65142343c54348db5d0) (let __tconst7sqz226 const7b8fd91ee9ff10cfbb8066bf) (let __tconst1EUj230 const615ad01b1c532bb6634df115) (let __tconst2VuQ234 const4492fd5fa4baacfebd29f5e5) (let __tconst4Sko246 consteb793a6f75d6cfe49d3c2c90) (let __tconst2x2f244 consta32d5a443def48e6d64c6f4b)) (scan app __t5pZU250 __t5uyC249 __t45rU235) (body (exists ref (1 0) 1 __tconst2VuQ234) (exists lambda (0 1 2) 2 __t5uyC249 __tconst4N2q248) (exists lambda (1 2 0) 1 __tconst4Sko246) (exists lambda (1 2 0) 1 __tconst2x2f244) (exists ref (1 0) 1 __tconst1EUj230) (exists lambda (1 2 0) 1 __tconst1EUj230) (exists ref (1 0) 1 __tconst7sqz226) (exists lambda (1 2 0) 1 __tconst7sqz226) (exists ref (1 0) 1 __tconst2x2f244) (exists ref (1 0) 1 __tconst4N2q248) (exists ref (1 0) 1 __tconst4Sko246) (join lambda (0 1 2) 2 __t45rU235 __tconst2VuQ234 __t2PLq233) (join ref (0 1) 2 __t2PLq233 __tconst2VuQ234) (join lambda (0 1 2) 2 __t5uyC249 __tconst4N2q248 __t7yz1247) (join lambda (0 1 2) 2 __t7yz1247 __tconst4Sko246 __t3laZ245) (join lambda (0 1 2) 2 __t3laZ245 __tconst2x2f244 __t5h6K243) (join ref (1 0) 1 __tconst1EUj230 __t3WVP229) (join lambda (1 2 0) 2 __tconst1EUj230 __t3WVP229 __t5ryk231) (join ref (1 0) 1 __tconst7sqz226 __t5APF225) (join lambda (1 2 0) 2 __tconst7sqz226 __t5APF225 __t2BAX227) (join ref (1 0) 1 __tconst2x2f244 __t3pbc237) (join app (2 0 1) 2 __t3pbc237 __t5h6K243 __t4wvK242) (join ref (1 0) 1 __tconst4N2q248 __t6KL4241) (join app (0 1 2) 2 __t4wvK242 __t6KL4241 __t16jv239) (join ref (0 1) 2 __t16jv239 __tconst4Sko246)) (head (mkstruct app (1 2 0) __t9bBp251 __t5pZU250 __t5ryk231)) mcfa-counting.slog:272 #f)
  class ReadTask782 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex757;  slog::Index** lambdaindex758;  slog::Index** lambdaindex759;  slog::Index** lambdaindex760;  slog::Index** refindex761;  slog::Index** lambdaindex762;  slog::Index** refindex763;  slog::Index** lambdaindex764;  slog::Index** refindex765;  slog::Index** refindex766;  slog::Index** refindex767;  slog::Index** lambdaindex768;  slog::Index** refindex769;  slog::Index** lambdaindex770;  slog::Index** lambdaindex771;  slog::Index** lambdaindex772;  slog::Index** refindex773;  slog::Index** lambdaindex774;  slog::Index** refindex775;  slog::Index** lambdaindex776;  slog::Index** refindex777;  slog::Index** appindex778;  slog::Index** refindex779;  slog::Index** appindex780;  slog::Index** refindex781;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      outer_rel = db->getRelation("app");
      std::vector<u16> ord783({1, 0});
      slog::Relation* readrel784 = db->getRelation("ref");
      refindex757 = readrel784->getIndex(ord783, false);
      std::vector<u16> ord785({0, 1, 2});
      slog::Relation* readrel786 = db->getRelation("lambda");
      lambdaindex758 = readrel786->getIndex(ord785, false);
      std::vector<u16> ord787({1, 2, 0});
      slog::Relation* readrel788 = db->getRelation("lambda");
      lambdaindex759 = readrel788->getIndex(ord787, false);
      std::vector<u16> ord789({1, 2, 0});
      slog::Relation* readrel790 = db->getRelation("lambda");
      lambdaindex760 = readrel790->getIndex(ord789, false);
      std::vector<u16> ord791({1, 0});
      slog::Relation* readrel792 = db->getRelation("ref");
      refindex761 = readrel792->getIndex(ord791, false);
      std::vector<u16> ord793({1, 2, 0});
      slog::Relation* readrel794 = db->getRelation("lambda");
      lambdaindex762 = readrel794->getIndex(ord793, false);
      std::vector<u16> ord795({1, 0});
      slog::Relation* readrel796 = db->getRelation("ref");
      refindex763 = readrel796->getIndex(ord795, false);
      std::vector<u16> ord797({1, 2, 0});
      slog::Relation* readrel798 = db->getRelation("lambda");
      lambdaindex764 = readrel798->getIndex(ord797, false);
      std::vector<u16> ord799({1, 0});
      slog::Relation* readrel800 = db->getRelation("ref");
      refindex765 = readrel800->getIndex(ord799, false);
      std::vector<u16> ord801({1, 0});
      slog::Relation* readrel802 = db->getRelation("ref");
      refindex766 = readrel802->getIndex(ord801, false);
      std::vector<u16> ord803({1, 0});
      slog::Relation* readrel804 = db->getRelation("ref");
      refindex767 = readrel804->getIndex(ord803, false);
      std::vector<u16> ord805({0, 1, 2});
      slog::Relation* readrel806 = db->getRelation("lambda");
      lambdaindex768 = readrel806->getIndex(ord805, false);
      std::vector<u16> ord807({0, 1});
      slog::Relation* readrel808 = db->getRelation("ref");
      refindex769 = readrel808->getIndex(ord807, false);
      std::vector<u16> ord809({0, 1, 2});
      slog::Relation* readrel810 = db->getRelation("lambda");
      lambdaindex770 = readrel810->getIndex(ord809, false);
      std::vector<u16> ord811({0, 1, 2});
      slog::Relation* readrel812 = db->getRelation("lambda");
      lambdaindex771 = readrel812->getIndex(ord811, false);
      std::vector<u16> ord813({0, 1, 2});
      slog::Relation* readrel814 = db->getRelation("lambda");
      lambdaindex772 = readrel814->getIndex(ord813, false);
      std::vector<u16> ord815({1, 0});
      slog::Relation* readrel816 = db->getRelation("ref");
      refindex773 = readrel816->getIndex(ord815, false);
      std::vector<u16> ord817({1, 2, 0});
      slog::Relation* readrel818 = db->getRelation("lambda");
      lambdaindex774 = readrel818->getIndex(ord817, false);
      std::vector<u16> ord819({1, 0});
      slog::Relation* readrel820 = db->getRelation("ref");
      refindex775 = readrel820->getIndex(ord819, false);
      std::vector<u16> ord821({1, 2, 0});
      slog::Relation* readrel822 = db->getRelation("lambda");
      lambdaindex776 = readrel822->getIndex(ord821, false);
      std::vector<u16> ord823({1, 0});
      slog::Relation* readrel824 = db->getRelation("ref");
      refindex777 = readrel824->getIndex(ord823, false);
      std::vector<u16> ord825({2, 0, 1});
      slog::Relation* readrel826 = db->getRelation("app");
      appindex778 = readrel826->getIndex(ord825, false);
      std::vector<u16> ord827({1, 0});
      slog::Relation* readrel828 = db->getRelation("ref");
      refindex779 = readrel828->getIndex(ord827, false);
      std::vector<u16> ord829({0, 1, 2});
      slog::Relation* readrel830 = db->getRelation("app");
      appindex780 = readrel830->getIndex(ord829, false);
      std::vector<u16> ord831({0, 1});
      slog::Relation* readrel832 = db->getRelation("ref");
      refindex781 = readrel832->getIndex(ord831, false);
  
    }
    ReadTask782(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c87 = v_constaaaad65142343c54348db5d0;
      u64 v_c82 = v_const7b8fd91ee9ff10cfbb8066bf;
      u64 v_c83 = v_const615ad01b1c532bb6634df115;
      u64 v_c84 = v_const4492fd5fa4baacfebd29f5e5;
      u64 v_c86 = v_consteb793a6f75d6cfe49d3c2c90;
      u64 v_c85 = v_consta32d5a443def48e6d64c6f4b;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c133 = _t[0];
        u64 v_c134 = _t[1];
        u64 v_c93 = _t[2];
        if (!slog::exists_probe<2,1>(refindex757, std::array<u64,2>{v_c84, 0})) return;
        if (!slog::exists_probe<3,2>(lambdaindex758, std::array<u64,3>{v_c134, v_c87, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex759, std::array<u64,3>{v_c86, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex760, std::array<u64,3>{v_c85, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex761, std::array<u64,2>{v_c83, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex762, std::array<u64,3>{v_c83, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex763, std::array<u64,2>{v_c82, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex764, std::array<u64,3>{v_c82, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex765, std::array<u64,2>{v_c85, 0})) return;
        if (!slog::exists_probe<2,1>(refindex766, std::array<u64,2>{v_c87, 0})) return;
        if (!slog::exists_probe<2,1>(refindex767, std::array<u64,2>{v_c86, 0})) return;
        slog::join_probe<3,2>(lambdaindex768, std::array<u64,3>{v_c93, v_c84, 0}, [&](const std::array<u64,3>& m833) {
          u64 v_c92 = m833[2];
          slog::join_probe<2,2>(refindex769, std::array<u64,2>{v_c92, v_c84}, [&](const std::array<u64,2>& m834) {
            slog::join_probe<3,2>(lambdaindex770, std::array<u64,3>{v_c134, v_c87, 0}, [&](const std::array<u64,3>& m835) {
              u64 v_c135 = m835[2];
              slog::join_probe<3,2>(lambdaindex771, std::array<u64,3>{v_c135, v_c86, 0}, [&](const std::array<u64,3>& m836) {
                u64 v_c136 = m836[2];
                slog::join_probe<3,2>(lambdaindex772, std::array<u64,3>{v_c136, v_c85, 0}, [&](const std::array<u64,3>& m837) {
                  u64 v_c137 = m837[2];
                  slog::join_probe<2,1>(refindex773, std::array<u64,2>{v_c83, 0}, [&](const std::array<u64,2>& m838) {
                    u64 v_c94 = m838[1];
                    slog::join_probe<3,2>(lambdaindex774, std::array<u64,3>{v_c83, v_c94, 0}, [&](const std::array<u64,3>& m839) {
                      u64 v_c95 = m839[2];
                      slog::join_probe<2,1>(refindex775, std::array<u64,2>{v_c82, 0}, [&](const std::array<u64,2>& m840) {
                        u64 v_c96 = m840[1];
                        slog::join_probe<3,2>(lambdaindex776, std::array<u64,3>{v_c82, v_c96, 0}, [&](const std::array<u64,3>& m841) {
                          u64 v_c97 = m841[2];
                          slog::join_probe<2,1>(refindex777, std::array<u64,2>{v_c85, 0}, [&](const std::array<u64,2>& m842) {
                            u64 v_c91 = m842[1];
                            slog::join_probe<3,2>(appindex778, std::array<u64,3>{v_c91, v_c137, 0}, [&](const std::array<u64,3>& m843) {
                              u64 v_c90 = m843[2];
                              slog::join_probe<2,1>(refindex779, std::array<u64,2>{v_c87, 0}, [&](const std::array<u64,2>& m844) {
                                u64 v_c88 = m844[1];
                                slog::join_probe<3,2>(appindex780, std::array<u64,3>{v_c90, v_c88, 0}, [&](const std::array<u64,3>& m845) {
                                  u64 v_c89 = m845[2];
                                  slog::join_probe<2,2>(refindex781, std::array<u64,2>{v_c89, v_c86}, [&](const std::array<u64,2>& m846) {
                                    ++_fires;
                                    slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c133, v_c95}, std::array<u16,3>{1, 2, 0});
                                  });
                                });
                              });
                            });
                          });
                        });
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
  // (crule (pre) (scan eval __6tlE337 __t5SBy169 c) (body (exists eval (2 0 1) 1 c) (join-old app (0 1 2) 1 (0 1 2) __t5SBy169 ef ea) (exists eval (1 2 0) 2 ea c) (join-old eval (1 2 0) 2 (1 2 0) ef c __t6CRg170) (exists eval_ans (0 1) 1 __t6CRg170) (join-old eval (1 2 0) 2 (1 2 0) ea c __t1JPZ173) (exists eval_ans (0 1) 1 __t1JPZ173) (join-old eval_ans (0 1) 1 (0 1) __t6CRg170 __t2Hqj172) (join-old eval_ans (0 1) 1 (0 1) __t1JPZ173 va) (join-old clo (0 2 1) 1 (0 2 1) __t2Hqj172 cb __t0RD6171) (join-old lambda (0 1 2) 1 (0 1 2) __t0RD6171 x eb)) (head (emit store (0 1 2) x __t5SBy169 va) (emit callev (0 1) __t5SBy169 c) (emit bindev (0 1 2) x __t5SBy169 c)) mcfa-counting.slog:92 #f)
  class ReadTask865 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex847;  slog::Index** appindex848;  slog::Index** evalindex849;  slog::Index** evalindex850;  slog::Index** eval_ansindex851;  slog::Index** evalindex852;  slog::Index** eval_ansindex853;  slog::Index** eval_ansindex854;  slog::Index** eval_ansindex855;  slog::Index** cloindex856;  slog::Index** lambdaindex857;  slog::Index** appdelta858;  slog::Index** evaldelta859;  slog::Index** evaldelta860;  slog::Index** eval_ansdelta861;  slog::Index** eval_ansdelta862;  slog::Index** clodelta863;  slog::Index** lambdadelta864;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("store");
      std::vector<u16> ord866({0, 1, 2});
      slog::Relation* readrel867 = db->getRelation("store");
      head_index[0] = readrel867->getIndex(ord866, false);
      head_rel[1] = db->getRelation("callev");
      std::vector<u16> ord868({0, 1});
      slog::Relation* readrel869 = db->getRelation("callev");
      head_index[1] = readrel869->getIndex(ord868, false);
      head_rel[2] = db->getRelation("bindev");
      std::vector<u16> ord870({0, 1, 2});
      slog::Relation* readrel871 = db->getRelation("bindev");
      head_index[2] = readrel871->getIndex(ord870, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord872({2, 0, 1});
      slog::Relation* readrel873 = db->getRelation("eval");
      evalindex847 = readrel873->getIndex(ord872, false);
      std::vector<u16> ord874({0, 1, 2});
      slog::Relation* readrel875 = db->getRelation("app");
      appindex848 = readrel875->getIndex(ord874, false);
      std::vector<u16> ord876({0, 1, 2});
      slog::Relation* readrel877 = db->getRelation("app");
      appdelta858 = readrel877->getIndex(ord876, true);
      std::vector<u16> ord878({1, 2, 0});
      slog::Relation* readrel879 = db->getRelation("eval");
      evalindex849 = readrel879->getIndex(ord878, false);
      std::vector<u16> ord880({1, 2, 0});
      slog::Relation* readrel881 = db->getRelation("eval");
      evalindex850 = readrel881->getIndex(ord880, false);
      std::vector<u16> ord882({1, 2, 0});
      slog::Relation* readrel883 = db->getRelation("eval");
      evaldelta859 = readrel883->getIndex(ord882, true);
      std::vector<u16> ord884({0, 1});
      slog::Relation* readrel885 = db->getRelation("eval_ans");
      eval_ansindex851 = readrel885->getIndex(ord884, false);
      std::vector<u16> ord886({1, 2, 0});
      slog::Relation* readrel887 = db->getRelation("eval");
      evalindex852 = readrel887->getIndex(ord886, false);
      std::vector<u16> ord888({1, 2, 0});
      slog::Relation* readrel889 = db->getRelation("eval");
      evaldelta860 = readrel889->getIndex(ord888, true);
      std::vector<u16> ord890({0, 1});
      slog::Relation* readrel891 = db->getRelation("eval_ans");
      eval_ansindex853 = readrel891->getIndex(ord890, false);
      std::vector<u16> ord892({0, 1});
      slog::Relation* readrel893 = db->getRelation("eval_ans");
      eval_ansindex854 = readrel893->getIndex(ord892, false);
      std::vector<u16> ord894({0, 1});
      slog::Relation* readrel895 = db->getRelation("eval_ans");
      eval_ansdelta861 = readrel895->getIndex(ord894, true);
      std::vector<u16> ord896({0, 1});
      slog::Relation* readrel897 = db->getRelation("eval_ans");
      eval_ansindex855 = readrel897->getIndex(ord896, false);
      std::vector<u16> ord898({0, 1});
      slog::Relation* readrel899 = db->getRelation("eval_ans");
      eval_ansdelta862 = readrel899->getIndex(ord898, true);
      std::vector<u16> ord900({0, 2, 1});
      slog::Relation* readrel901 = db->getRelation("clo");
      cloindex856 = readrel901->getIndex(ord900, false);
      std::vector<u16> ord902({0, 2, 1});
      slog::Relation* readrel903 = db->getRelation("clo");
      clodelta863 = readrel903->getIndex(ord902, true);
      std::vector<u16> ord904({0, 1, 2});
      slog::Relation* readrel905 = db->getRelation("lambda");
      lambdaindex857 = readrel905->getIndex(ord904, false);
      std::vector<u16> ord906({0, 1, 2});
      slog::Relation* readrel907 = db->getRelation("lambda");
      lambdadelta864 = readrel907->getIndex(ord906, true);
  
    }
    ReadTask865(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c138 = _t[0];
        u64 v_c139 = _t[1];
        u64 v_c2 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex847, std::array<u64,3>{v_c2, 0, 0})) return;
        slog::join_probe_old<3,1>(appindex848, appdelta858, std::array<u64,3>{v_c139, 0, 0}, [&](const std::array<u64,3>& m908) {
          u64 v_c3 = m908[1]; u64 v_c4 = m908[2];
          if (!slog::exists_probe<3,2>(evalindex849, std::array<u64,3>{v_c4, v_c2, 0})) return;
          slog::join_probe_old<3,2>(evalindex850, evaldelta859, std::array<u64,3>{v_c3, v_c2, 0}, [&](const std::array<u64,3>& m909) {
            u64 v_c140 = m909[2];
            if (!slog::exists_probe<2,1>(eval_ansindex851, std::array<u64,2>{v_c140, 0})) return;
            slog::join_probe_old<3,2>(evalindex852, evaldelta860, std::array<u64,3>{v_c4, v_c2, 0}, [&](const std::array<u64,3>& m910) {
              u64 v_c141 = m910[2];
              if (!slog::exists_probe<2,1>(eval_ansindex853, std::array<u64,2>{v_c141, 0})) return;
              slog::join_probe_old<2,1>(eval_ansindex854, eval_ansdelta861, std::array<u64,2>{v_c140, 0}, [&](const std::array<u64,2>& m911) {
                u64 v_c142 = m911[1];
                slog::join_probe_old<2,1>(eval_ansindex855, eval_ansdelta862, std::array<u64,2>{v_c141, 0}, [&](const std::array<u64,2>& m912) {
                  u64 v_c119 = m912[1];
                  slog::join_probe_old<3,1>(cloindex856, clodelta863, std::array<u64,3>{v_c142, 0, 0}, [&](const std::array<u64,3>& m913) {
                    u64 v_c117 = m913[1]; u64 v_c143 = m913[2];
                    slog::join_probe_old<3,1>(lambdaindex857, lambdadelta864, std::array<u64,3>{v_c143, 0, 0}, [&](const std::array<u64,3>& m914) {
                      u64 v_c6 = m914[1]; u64 v_c118 = m914[2];
                      ++_fires;
                      slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c6, v_c139, v_c119}, std::array<u16,3>{0, 1, 2});
                      slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c139, v_c2}, std::array<u16,2>{0, 1});
                      slog::emit<3>(head_rel[2], head_index[2], newbatch[2], std::array<u64,3>{v_c6, v_c139, v_c2}, std::array<u16,3>{0, 1, 2});
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
        ReadTask865* _cont = new ReadTask865(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask865(db,b), false);
  // (crule (pre (let __tconst4she277 const50a95ec20b9767e468d04917) (let __tconst0ZLv270 constf0a25c0401304c51b5ee9c5e)) (seeded) (body (join ref (1 0) 1 __tconst0ZLv270 __t9L3S266) (exists app (1 2 0) 1 __t9L3S266) (join ref (1 0) 1 __tconst4she277 __t28CO273) (exists app (1 2 0) 1 __t28CO273) (join app (1 2 0) 1 __t9L3S266 dup0IMY439 __t8kx2269) (eq __t9L3S266 dup0IMY439) (join app (1 2 0) 1 __t28CO273 dup5X9s440 __t6FnS276) (eq __t28CO273 dup5X9s440)) (head (mkstruct lambda (1 2 0) __t6zNR278 __tconst4she277 __t6FnS276) (mkstruct lambda (1 2 0) __t3oIn271 __tconst0ZLv270 __t8kx2269)) mcfa-counting.slog:183 #f)
  class ReadTask921 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
  
  
  
  
  
    slog::Index** refindex915;  slog::Index** appindex916;  slog::Index** refindex917;  slog::Index** appindex918;  slog::Index** appindex919;  slog::Index** appindex920;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      std::vector<u16> ord922({1, 2, 0});
      slog::Relation* readrel923 = db->getRelation("lambda");
      head_index[0] = readrel923->getIndex(ord922, false);
      head_rel[1] = db->getRelation("lambda");
      std::vector<u16> ord924({1, 2, 0});
      slog::Relation* readrel925 = db->getRelation("lambda");
      head_index[1] = readrel925->getIndex(ord924, false);
      std::vector<u16> ord926({1, 0});
      slog::Relation* readrel927 = db->getRelation("ref");
      refindex915 = readrel927->getIndex(ord926, false);
      std::vector<u16> ord928({1, 2, 0});
      slog::Relation* readrel929 = db->getRelation("app");
      appindex916 = readrel929->getIndex(ord928, false);
      std::vector<u16> ord930({1, 0});
      slog::Relation* readrel931 = db->getRelation("ref");
      refindex917 = readrel931->getIndex(ord930, false);
      std::vector<u16> ord932({1, 2, 0});
      slog::Relation* readrel933 = db->getRelation("app");
      appindex918 = readrel933->getIndex(ord932, false);
      std::vector<u16> ord934({1, 2, 0});
      slog::Relation* readrel935 = db->getRelation("app");
      appindex919 = readrel935->getIndex(ord934, false);
      std::vector<u16> ord936({1, 2, 0});
      slog::Relation* readrel937 = db->getRelation("app");
      appindex920 = readrel937->getIndex(ord936, false);
  
    }
    ReadTask921(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c22 = v_const50a95ec20b9767e468d04917;
      u64 v_c23 = v_constf0a25c0401304c51b5ee9c5e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex915, std::array<u64,2>{v_c23, 0}, [&](const std::array<u64,2>& m938) {
        u64 v_c29 = m938[1];
        if (!slog::exists_probe<3,1>(appindex916, std::array<u64,3>{v_c29, 0, 0})) return;
        slog::join_probe<2,1>(refindex917, std::array<u64,2>{v_c22, 0}, [&](const std::array<u64,2>& m939) {
          u64 v_c31 = m939[1];
          if (!slog::exists_probe<3,1>(appindex918, std::array<u64,3>{v_c31, 0, 0})) return;
          slog::join_probe<3,1>(appindex919, std::array<u64,3>{v_c29, 0, 0}, [&](const std::array<u64,3>& m940) {
            u64 v_c144 = m940[1]; u64 v_c27 = m940[2];
            if (v_c29 != v_c144) return;
            slog::join_probe<3,1>(appindex920, std::array<u64,3>{v_c31, 0, 0}, [&](const std::array<u64,3>& m941) {
              u64 v_c145 = m941[1]; u64 v_c28 = m941[2];
              if (v_c31 != v_c145) return;
              ++_fires;
              slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c22, v_c28}, std::array<u16,3>{1, 2, 0});
              slog::emit_struct_checked<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c23, v_c27}, std::array<u16,3>{1, 2, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:183", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask921(db,b));
  // (crule (pre) (scan eval_ans __t8nKY157 __t3EGT159) (body (join-old eval (0 2 1) 1 (0 2 1) __t8nKY157 c ef) (exists eval (2 0 1) 1 c) (join $sup27994x83x0x0x0 (1 3 0 2) 2 c ef __d0 ea) (join-old eval (1 2 0) 2 (1 2 0) ea c __t4j5Q160) (join-old eval_ans (0 1) 1 (0 1) __t4j5Q160 va) (join-old clo (0 2 1) 1 (0 2 1) __t3EGT159 cb __t1L8v158) (join-old lambda (0 1 2) 1 (0 1 2) __t1L8v158 x eb)) (head (emit $sup27994x83x0x0x1 (1 4 0 2 3 5 6 7 8 9) __t8nKY157 cb __d0 __t4j5Q160 c ea eb ef va x)) mcfa-counting.slog:84 #f)
  class ReadTask954 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex942;  slog::Index** evalindex943;  slog::Index** $sup27994x83x0x0x0index944;  slog::Index** evalindex945;  slog::Index** eval_ansindex946;  slog::Index** cloindex947;  slog::Index** lambdaindex948;  slog::Index** evaldelta949;  slog::Index** evaldelta950;  slog::Index** eval_ansdelta951;  slog::Index** clodelta952;  slog::Index** lambdadelta953;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup27994x83x0x0x1");
      std::vector<u16> ord955({1, 4, 0, 2, 3, 5, 6, 7, 8, 9});
      slog::Relation* readrel956 = db->getRelation("$sup27994x83x0x0x1");
      head_index[0] = readrel956->getIndex(ord955, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord957({0, 2, 1});
      slog::Relation* readrel958 = db->getRelation("eval");
      evalindex942 = readrel958->getIndex(ord957, false);
      std::vector<u16> ord959({0, 2, 1});
      slog::Relation* readrel960 = db->getRelation("eval");
      evaldelta949 = readrel960->getIndex(ord959, true);
      std::vector<u16> ord961({2, 0, 1});
      slog::Relation* readrel962 = db->getRelation("eval");
      evalindex943 = readrel962->getIndex(ord961, false);
      std::vector<u16> ord963({1, 3, 0, 2});
      slog::Relation* readrel964 = db->getRelation("$sup27994x83x0x0x0");
      $sup27994x83x0x0x0index944 = readrel964->getIndex(ord963, false);
      std::vector<u16> ord965({1, 2, 0});
      slog::Relation* readrel966 = db->getRelation("eval");
      evalindex945 = readrel966->getIndex(ord965, false);
      std::vector<u16> ord967({1, 2, 0});
      slog::Relation* readrel968 = db->getRelation("eval");
      evaldelta950 = readrel968->getIndex(ord967, true);
      std::vector<u16> ord969({0, 1});
      slog::Relation* readrel970 = db->getRelation("eval_ans");
      eval_ansindex946 = readrel970->getIndex(ord969, false);
      std::vector<u16> ord971({0, 1});
      slog::Relation* readrel972 = db->getRelation("eval_ans");
      eval_ansdelta951 = readrel972->getIndex(ord971, true);
      std::vector<u16> ord973({0, 2, 1});
      slog::Relation* readrel974 = db->getRelation("clo");
      cloindex947 = readrel974->getIndex(ord973, false);
      std::vector<u16> ord975({0, 2, 1});
      slog::Relation* readrel976 = db->getRelation("clo");
      clodelta952 = readrel976->getIndex(ord975, true);
      std::vector<u16> ord977({0, 1, 2});
      slog::Relation* readrel978 = db->getRelation("lambda");
      lambdaindex948 = readrel978->getIndex(ord977, false);
      std::vector<u16> ord979({0, 1, 2});
      slog::Relation* readrel980 = db->getRelation("lambda");
      lambdadelta953 = readrel980->getIndex(ord979, true);
  
    }
    ReadTask954(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c125 = _t[0];
        u64 v_c123 = _t[1];
        slog::join_probe_old<3,1>(evalindex942, evaldelta949, std::array<u64,3>{v_c125, 0, 0}, [&](const std::array<u64,3>& m981) {
          u64 v_c2 = m981[1]; u64 v_c3 = m981[2];
          if (!slog::exists_probe<3,1>(evalindex943, std::array<u64,3>{v_c2, 0, 0})) return;
          slog::join_probe<4,2>($sup27994x83x0x0x0index944, std::array<u64,4>{v_c2, v_c3, 0, 0}, [&](const std::array<u64,4>& m982) {
            u64 v_c126 = m982[2]; u64 v_c4 = m982[3];
            slog::join_probe_old<3,2>(evalindex945, evaldelta950, std::array<u64,3>{v_c4, v_c2, 0}, [&](const std::array<u64,3>& m983) {
              u64 v_c127 = m983[2];
              slog::join_probe_old<2,1>(eval_ansindex946, eval_ansdelta951, std::array<u64,2>{v_c127, 0}, [&](const std::array<u64,2>& m984) {
                u64 v_c119 = m984[1];
                slog::join_probe_old<3,1>(cloindex947, clodelta952, std::array<u64,3>{v_c123, 0, 0}, [&](const std::array<u64,3>& m985) {
                  u64 v_c117 = m985[1]; u64 v_c124 = m985[2];
                  slog::join_probe_old<3,1>(lambdaindex948, lambdadelta953, std::array<u64,3>{v_c124, 0, 0}, [&](const std::array<u64,3>& m986) {
                    u64 v_c6 = m986[1]; u64 v_c118 = m986[2];
                    ++_fires;
                    slog::emit<10>(head_rel[0], head_index[0], newbatch[0], std::array<u64,10>{v_c125, v_c117, v_c126, v_c127, v_c2, v_c4, v_c118, v_c3, v_c119, v_c6}, std::array<u16,10>{1, 4, 0, 2, 3, 5, 6, 7, 8, 9});
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
        ReadTask954* _cont = new ReadTask954(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask954(db,b), false);
  // (crule (pre (let __tconst0y6X73 const0aa6f87434af0222b916e97a) (let __tconst7zoP70 const227d34ceeba7a29aada993d4) (let __tconst0aL952 constd3d07026d47882ceca728218) (let __tconst1bfe65 const59ba3256d223f0d0a00d0633) (let __tconst0xUh47 constf700a82e218a86de572e1f7f) (let __tconst8wN863 const7cd75b35aa30c3ddf04f9d57)) (scan app __t9kFz72 __t7KAC71 __t81HE60) (body (exists ref (1 0) 1 __tconst0y6X73) (exists lambda (1 2 0) 1 __tconst1bfe65) (exists ref (1 0) 1 __tconst1bfe65) (exists lambda (1 2 0) 1 __tconst8wN863) (exists ref (1 0) 1 __tconst8wN863) (exists ref (1 0) 1 __tconst0aL952) (exists ref (1 0) 1 __tconst0xUh47) (exists lambda (1 2 0) 1 __tconst0xUh47) (exists lambda (1 2 0) 1 __tconst0aL952) (join lambda (0 1 2) 2 __t7KAC71 __tconst7zoP70 __t5Ri569) (join ref (1 0) 1 __tconst0y6X73 __t0QRr59) (exists app (0 1 2) 2 __t5Ri569 __t0QRr59) (join app (0 1 2) 2 __t81HE60 __t0QRr59 __t0uNb57) (join lambda (0 1 2) 2 __t0uNb57 __tconst1bfe65 __t2HsD55) (join ref (0 1) 2 __t2HsD55 __tconst1bfe65) (join app (0 1 2) 2 __t5Ri569 __t0QRr59 __t7JIT66) (join lambda (0 1 2) 2 __t7JIT66 __tconst1bfe65 __t3Dru64) (join lambda (0 1 2) 2 __t3Dru64 __tconst8wN863 __t1mkO62) (join ref (0 1) 2 __t1mkO62 __tconst8wN863) (join ref (1 0) 1 __tconst0aL952 __t5HQ450) (exists app (1 2 0) 1 __t5HQ450) (join ref (1 0) 1 __tconst0xUh47 __t5vZb46) (join lambda (1 2 0) 2 __tconst0xUh47 __t5vZb46 __t50zW48) (join app (1 2 0) 2 __t5HQ450 __t50zW48 __t05NY51) (join lambda (1 2 0) 2 __tconst0aL952 __t05NY51 __t3xtz53)) (head (mkstruct lambda (1 2 0) __t9J4m74 __tconst0y6X73 __t9kFz72)) mcfa-counting.slog:287 #f)
  class ReadTask1012 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex987;  slog::Index** lambdaindex988;  slog::Index** refindex989;  slog::Index** lambdaindex990;  slog::Index** refindex991;  slog::Index** refindex992;  slog::Index** refindex993;  slog::Index** lambdaindex994;  slog::Index** lambdaindex995;  slog::Index** lambdaindex996;  slog::Index** refindex997;  slog::Index** appindex998;  slog::Index** appindex999;  slog::Index** lambdaindex1000;  slog::Index** refindex1001;  slog::Index** appindex1002;  slog::Index** lambdaindex1003;  slog::Index** lambdaindex1004;  slog::Index** refindex1005;  slog::Index** refindex1006;  slog::Index** appindex1007;  slog::Index** refindex1008;  slog::Index** lambdaindex1009;  slog::Index** appindex1010;  slog::Index** lambdaindex1011;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      outer_rel = db->getRelation("app");
      std::vector<u16> ord1013({1, 0});
      slog::Relation* readrel1014 = db->getRelation("ref");
      refindex987 = readrel1014->getIndex(ord1013, false);
      std::vector<u16> ord1015({1, 2, 0});
      slog::Relation* readrel1016 = db->getRelation("lambda");
      lambdaindex988 = readrel1016->getIndex(ord1015, false);
      std::vector<u16> ord1017({1, 0});
      slog::Relation* readrel1018 = db->getRelation("ref");
      refindex989 = readrel1018->getIndex(ord1017, false);
      std::vector<u16> ord1019({1, 2, 0});
      slog::Relation* readrel1020 = db->getRelation("lambda");
      lambdaindex990 = readrel1020->getIndex(ord1019, false);
      std::vector<u16> ord1021({1, 0});
      slog::Relation* readrel1022 = db->getRelation("ref");
      refindex991 = readrel1022->getIndex(ord1021, false);
      std::vector<u16> ord1023({1, 0});
      slog::Relation* readrel1024 = db->getRelation("ref");
      refindex992 = readrel1024->getIndex(ord1023, false);
      std::vector<u16> ord1025({1, 0});
      slog::Relation* readrel1026 = db->getRelation("ref");
      refindex993 = readrel1026->getIndex(ord1025, false);
      std::vector<u16> ord1027({1, 2, 0});
      slog::Relation* readrel1028 = db->getRelation("lambda");
      lambdaindex994 = readrel1028->getIndex(ord1027, false);
      std::vector<u16> ord1029({1, 2, 0});
      slog::Relation* readrel1030 = db->getRelation("lambda");
      lambdaindex995 = readrel1030->getIndex(ord1029, false);
      std::vector<u16> ord1031({0, 1, 2});
      slog::Relation* readrel1032 = db->getRelation("lambda");
      lambdaindex996 = readrel1032->getIndex(ord1031, false);
      std::vector<u16> ord1033({1, 0});
      slog::Relation* readrel1034 = db->getRelation("ref");
      refindex997 = readrel1034->getIndex(ord1033, false);
      std::vector<u16> ord1035({0, 1, 2});
      slog::Relation* readrel1036 = db->getRelation("app");
      appindex998 = readrel1036->getIndex(ord1035, false);
      std::vector<u16> ord1037({0, 1, 2});
      slog::Relation* readrel1038 = db->getRelation("app");
      appindex999 = readrel1038->getIndex(ord1037, false);
      std::vector<u16> ord1039({0, 1, 2});
      slog::Relation* readrel1040 = db->getRelation("lambda");
      lambdaindex1000 = readrel1040->getIndex(ord1039, false);
      std::vector<u16> ord1041({0, 1});
      slog::Relation* readrel1042 = db->getRelation("ref");
      refindex1001 = readrel1042->getIndex(ord1041, false);
      std::vector<u16> ord1043({0, 1, 2});
      slog::Relation* readrel1044 = db->getRelation("app");
      appindex1002 = readrel1044->getIndex(ord1043, false);
      std::vector<u16> ord1045({0, 1, 2});
      slog::Relation* readrel1046 = db->getRelation("lambda");
      lambdaindex1003 = readrel1046->getIndex(ord1045, false);
      std::vector<u16> ord1047({0, 1, 2});
      slog::Relation* readrel1048 = db->getRelation("lambda");
      lambdaindex1004 = readrel1048->getIndex(ord1047, false);
      std::vector<u16> ord1049({0, 1});
      slog::Relation* readrel1050 = db->getRelation("ref");
      refindex1005 = readrel1050->getIndex(ord1049, false);
      std::vector<u16> ord1051({1, 0});
      slog::Relation* readrel1052 = db->getRelation("ref");
      refindex1006 = readrel1052->getIndex(ord1051, false);
      std::vector<u16> ord1053({1, 2, 0});
      slog::Relation* readrel1054 = db->getRelation("app");
      appindex1007 = readrel1054->getIndex(ord1053, false);
      std::vector<u16> ord1055({1, 0});
      slog::Relation* readrel1056 = db->getRelation("ref");
      refindex1008 = readrel1056->getIndex(ord1055, false);
      std::vector<u16> ord1057({1, 2, 0});
      slog::Relation* readrel1058 = db->getRelation("lambda");
      lambdaindex1009 = readrel1058->getIndex(ord1057, false);
      std::vector<u16> ord1059({1, 2, 0});
      slog::Relation* readrel1060 = db->getRelation("app");
      appindex1010 = readrel1060->getIndex(ord1059, false);
      std::vector<u16> ord1061({1, 2, 0});
      slog::Relation* readrel1062 = db->getRelation("lambda");
      lambdaindex1011 = readrel1062->getIndex(ord1061, false);
  
    }
    ReadTask1012(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c146 = v_const0aa6f87434af0222b916e97a;
      u64 v_c147 = v_const227d34ceeba7a29aada993d4;
      u64 v_c148 = v_constd3d07026d47882ceca728218;
      u64 v_c149 = v_const59ba3256d223f0d0a00d0633;
      u64 v_c150 = v_constf700a82e218a86de572e1f7f;
      u64 v_c151 = v_const7cd75b35aa30c3ddf04f9d57;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c152 = _t[0];
        u64 v_c153 = _t[1];
        u64 v_c154 = _t[2];
        if (!slog::exists_probe<2,1>(refindex987, std::array<u64,2>{v_c146, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex988, std::array<u64,3>{v_c149, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex989, std::array<u64,2>{v_c149, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex990, std::array<u64,3>{v_c151, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex991, std::array<u64,2>{v_c151, 0})) return;
        if (!slog::exists_probe<2,1>(refindex992, std::array<u64,2>{v_c148, 0})) return;
        if (!slog::exists_probe<2,1>(refindex993, std::array<u64,2>{v_c150, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex994, std::array<u64,3>{v_c150, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex995, std::array<u64,3>{v_c148, 0, 0})) return;
        slog::join_probe<3,2>(lambdaindex996, std::array<u64,3>{v_c153, v_c147, 0}, [&](const std::array<u64,3>& m1063) {
          u64 v_c155 = m1063[2];
          slog::join_probe<2,1>(refindex997, std::array<u64,2>{v_c146, 0}, [&](const std::array<u64,2>& m1064) {
            u64 v_c156 = m1064[1];
            if (!slog::exists_probe<3,2>(appindex998, std::array<u64,3>{v_c155, v_c156, 0})) return;
            slog::join_probe<3,2>(appindex999, std::array<u64,3>{v_c154, v_c156, 0}, [&](const std::array<u64,3>& m1065) {
              u64 v_c157 = m1065[2];
              slog::join_probe<3,2>(lambdaindex1000, std::array<u64,3>{v_c157, v_c149, 0}, [&](const std::array<u64,3>& m1066) {
                u64 v_c158 = m1066[2];
                slog::join_probe<2,2>(refindex1001, std::array<u64,2>{v_c158, v_c149}, [&](const std::array<u64,2>& m1067) {
                  slog::join_probe<3,2>(appindex1002, std::array<u64,3>{v_c155, v_c156, 0}, [&](const std::array<u64,3>& m1068) {
                    u64 v_c159 = m1068[2];
                    slog::join_probe<3,2>(lambdaindex1003, std::array<u64,3>{v_c159, v_c149, 0}, [&](const std::array<u64,3>& m1069) {
                      u64 v_c160 = m1069[2];
                      slog::join_probe<3,2>(lambdaindex1004, std::array<u64,3>{v_c160, v_c151, 0}, [&](const std::array<u64,3>& m1070) {
                        u64 v_c161 = m1070[2];
                        slog::join_probe<2,2>(refindex1005, std::array<u64,2>{v_c161, v_c151}, [&](const std::array<u64,2>& m1071) {
                          slog::join_probe<2,1>(refindex1006, std::array<u64,2>{v_c148, 0}, [&](const std::array<u64,2>& m1072) {
                            u64 v_c162 = m1072[1];
                            if (!slog::exists_probe<3,1>(appindex1007, std::array<u64,3>{v_c162, 0, 0})) return;
                            slog::join_probe<2,1>(refindex1008, std::array<u64,2>{v_c150, 0}, [&](const std::array<u64,2>& m1073) {
                              u64 v_c163 = m1073[1];
                              slog::join_probe<3,2>(lambdaindex1009, std::array<u64,3>{v_c150, v_c163, 0}, [&](const std::array<u64,3>& m1074) {
                                u64 v_c164 = m1074[2];
                                slog::join_probe<3,2>(appindex1010, std::array<u64,3>{v_c162, v_c164, 0}, [&](const std::array<u64,3>& m1075) {
                                  u64 v_c165 = m1075[2];
                                  slog::join_probe<3,2>(lambdaindex1011, std::array<u64,3>{v_c148, v_c165, 0}, [&](const std::array<u64,3>& m1076) {
                                    u64 v_c166 = m1076[2];
                                    ++_fires;
                                    slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c146, v_c152}, std::array<u16,3>{1, 2, 0});
                                  });
                                });
                              });
                            });
                          });
                        });
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
  
      if (_fires) db->bumpFires("mcfa-counting.slog:287", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask1012* _cont = new ReadTask1012(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1012(db,b), false);
  // (crule (pre (let __tconst4she277 const50a95ec20b9767e468d04917) (let __tconst0ZLv270 constf0a25c0401304c51b5ee9c5e)) (probe ref (1 0) 1 __tconst0ZLv270 __t9L3S266) (body (join ref (1 0) 1 __tconst4she277 __t28CO273)) (head (mkstruct app (1 2 0) __t6FnS276 __t28CO273 __t28CO273) (mkstruct app (1 2 0) __t8kx2269 __t9L3S266 __t9L3S266)) mcfa-counting.slog:183 #f)
  class ReadTask1078 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** refindex1077;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      head_rel[1] = db->getRelation("app");
      std::vector<u16> ord1079({1, 0});
      slog::Relation* readrel1080 = db->getRelation("ref");
      driver_index = readrel1080->getIndex(ord1079, true);
      std::vector<u16> ord1081({1, 0});
      slog::Relation* readrel1082 = db->getRelation("ref");
      refindex1077 = readrel1082->getIndex(ord1081, false);
  
    }
    ReadTask1078(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c22 = v_const50a95ec20b9767e468d04917;
      u64 v_c23 = v_constf0a25c0401304c51b5ee9c5e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c23, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m1083) {
        u64 v_c29 = m1083[1];
        if (buckethash(v_c29) != bucket) return;
        slog::join_probe<2,1>(refindex1077, std::array<u64,2>{v_c22, 0}, [&](const std::array<u64,2>& m1084) {
          u64 v_c31 = m1084[1];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c31, v_c31}, std::array<u16,3>{1, 2, 0});
          slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c29, v_c29}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:183", "delta:ref", _fires);
  
      if (!_done)
      {
        ReadTask1078* _cont = new ReadTask1078(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1078(db,b), false);
  // (crule (pre (let __tconst0y6X73 const0aa6f87434af0222b916e97a) (let __tconst0aL952 constd3d07026d47882ceca728218) (let __tconst7zoP70 const227d34ceeba7a29aada993d4) (let __tconst0xUh47 constf700a82e218a86de572e1f7f) (let __tconst1bfe65 const59ba3256d223f0d0a00d0633) (let __tconst8wN863 const7cd75b35aa30c3ddf04f9d57)) (scan app __t5ePS75 __t9J4m74 __t3xtz53) (body (exists lambda (0 1 2) 2 __t9J4m74 __tconst0y6X73) (exists ref (1 0) 1 __tconst0aL952) (exists lambda (1 2 0) 1 __tconst0xUh47) (exists ref (1 0) 1 __tconst0xUh47) (exists ref (1 0) 1 __tconst0y6X73) (exists ref (1 0) 1 __tconst1bfe65) (exists lambda (1 2 0) 1 __tconst1bfe65) (exists lambda (1 2 0) 1 __tconst7zoP70) (exists lambda (1 2 0) 1 __tconst8wN863) (exists ref (1 0) 1 __tconst8wN863) (join lambda (0 1 2) 2 __t3xtz53 __tconst0aL952 __t05NY51) (join lambda (0 1 2) 2 __t9J4m74 __tconst0y6X73 __t9kFz72) (join ref (1 0) 1 __tconst0aL952 __t5HQ450) (join app (0 1 2) 2 __t05NY51 __t5HQ450 __t50zW48) (join lambda (0 1 2) 2 __t50zW48 __tconst0xUh47 __t5vZb46) (join ref (0 1) 2 __t5vZb46 __tconst0xUh47) (join ref (1 0) 1 __tconst0y6X73 __t0QRr59) (exists app (1 2 0) 1 __t0QRr59) (join ref (1 0) 1 __tconst1bfe65 __t2HsD55) (join lambda (1 2 0) 2 __tconst1bfe65 __t2HsD55 __t0uNb57) (join app (1 2 0) 2 __t0QRr59 __t0uNb57 __t81HE60) (join app (2 0 1) 2 __t81HE60 __t9kFz72 __t7KAC71) (join lambda (0 1 2) 2 __t7KAC71 __tconst7zoP70 __t5Ri569) (join app (0 1 2) 2 __t5Ri569 __t0QRr59 __t7JIT66) (join lambda (0 1 2) 2 __t7JIT66 __tconst1bfe65 __t3Dru64) (join lambda (0 1 2) 2 __t3Dru64 __tconst8wN863 __t1mkO62) (join ref (0 1) 2 __t1mkO62 __tconst8wN863)) (head (emit program (0) __t5ePS75)) mcfa-counting.slog:287 #f)
  class ReadTask1112 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lambdaindex1085;  slog::Index** refindex1086;  slog::Index** lambdaindex1087;  slog::Index** refindex1088;  slog::Index** refindex1089;  slog::Index** refindex1090;  slog::Index** lambdaindex1091;  slog::Index** lambdaindex1092;  slog::Index** lambdaindex1093;  slog::Index** refindex1094;  slog::Index** lambdaindex1095;  slog::Index** lambdaindex1096;  slog::Index** refindex1097;  slog::Index** appindex1098;  slog::Index** lambdaindex1099;  slog::Index** refindex1100;  slog::Index** refindex1101;  slog::Index** appindex1102;  slog::Index** refindex1103;  slog::Index** lambdaindex1104;  slog::Index** appindex1105;  slog::Index** appindex1106;  slog::Index** lambdaindex1107;  slog::Index** appindex1108;  slog::Index** lambdaindex1109;  slog::Index** lambdaindex1110;  slog::Index** refindex1111;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("program");
      std::vector<u16> ord1113({0});
      slog::Relation* readrel1114 = db->getRelation("program");
      head_index[0] = readrel1114->getIndex(ord1113, false);
      outer_rel = db->getRelation("app");
      std::vector<u16> ord1115({0, 1, 2});
      slog::Relation* readrel1116 = db->getRelation("lambda");
      lambdaindex1085 = readrel1116->getIndex(ord1115, false);
      std::vector<u16> ord1117({1, 0});
      slog::Relation* readrel1118 = db->getRelation("ref");
      refindex1086 = readrel1118->getIndex(ord1117, false);
      std::vector<u16> ord1119({1, 2, 0});
      slog::Relation* readrel1120 = db->getRelation("lambda");
      lambdaindex1087 = readrel1120->getIndex(ord1119, false);
      std::vector<u16> ord1121({1, 0});
      slog::Relation* readrel1122 = db->getRelation("ref");
      refindex1088 = readrel1122->getIndex(ord1121, false);
      std::vector<u16> ord1123({1, 0});
      slog::Relation* readrel1124 = db->getRelation("ref");
      refindex1089 = readrel1124->getIndex(ord1123, false);
      std::vector<u16> ord1125({1, 0});
      slog::Relation* readrel1126 = db->getRelation("ref");
      refindex1090 = readrel1126->getIndex(ord1125, false);
      std::vector<u16> ord1127({1, 2, 0});
      slog::Relation* readrel1128 = db->getRelation("lambda");
      lambdaindex1091 = readrel1128->getIndex(ord1127, false);
      std::vector<u16> ord1129({1, 2, 0});
      slog::Relation* readrel1130 = db->getRelation("lambda");
      lambdaindex1092 = readrel1130->getIndex(ord1129, false);
      std::vector<u16> ord1131({1, 2, 0});
      slog::Relation* readrel1132 = db->getRelation("lambda");
      lambdaindex1093 = readrel1132->getIndex(ord1131, false);
      std::vector<u16> ord1133({1, 0});
      slog::Relation* readrel1134 = db->getRelation("ref");
      refindex1094 = readrel1134->getIndex(ord1133, false);
      std::vector<u16> ord1135({0, 1, 2});
      slog::Relation* readrel1136 = db->getRelation("lambda");
      lambdaindex1095 = readrel1136->getIndex(ord1135, false);
      std::vector<u16> ord1137({0, 1, 2});
      slog::Relation* readrel1138 = db->getRelation("lambda");
      lambdaindex1096 = readrel1138->getIndex(ord1137, false);
      std::vector<u16> ord1139({1, 0});
      slog::Relation* readrel1140 = db->getRelation("ref");
      refindex1097 = readrel1140->getIndex(ord1139, false);
      std::vector<u16> ord1141({0, 1, 2});
      slog::Relation* readrel1142 = db->getRelation("app");
      appindex1098 = readrel1142->getIndex(ord1141, false);
      std::vector<u16> ord1143({0, 1, 2});
      slog::Relation* readrel1144 = db->getRelation("lambda");
      lambdaindex1099 = readrel1144->getIndex(ord1143, false);
      std::vector<u16> ord1145({0, 1});
      slog::Relation* readrel1146 = db->getRelation("ref");
      refindex1100 = readrel1146->getIndex(ord1145, false);
      std::vector<u16> ord1147({1, 0});
      slog::Relation* readrel1148 = db->getRelation("ref");
      refindex1101 = readrel1148->getIndex(ord1147, false);
      std::vector<u16> ord1149({1, 2, 0});
      slog::Relation* readrel1150 = db->getRelation("app");
      appindex1102 = readrel1150->getIndex(ord1149, false);
      std::vector<u16> ord1151({1, 0});
      slog::Relation* readrel1152 = db->getRelation("ref");
      refindex1103 = readrel1152->getIndex(ord1151, false);
      std::vector<u16> ord1153({1, 2, 0});
      slog::Relation* readrel1154 = db->getRelation("lambda");
      lambdaindex1104 = readrel1154->getIndex(ord1153, false);
      std::vector<u16> ord1155({1, 2, 0});
      slog::Relation* readrel1156 = db->getRelation("app");
      appindex1105 = readrel1156->getIndex(ord1155, false);
      std::vector<u16> ord1157({2, 0, 1});
      slog::Relation* readrel1158 = db->getRelation("app");
      appindex1106 = readrel1158->getIndex(ord1157, false);
      std::vector<u16> ord1159({0, 1, 2});
      slog::Relation* readrel1160 = db->getRelation("lambda");
      lambdaindex1107 = readrel1160->getIndex(ord1159, false);
      std::vector<u16> ord1161({0, 1, 2});
      slog::Relation* readrel1162 = db->getRelation("app");
      appindex1108 = readrel1162->getIndex(ord1161, false);
      std::vector<u16> ord1163({0, 1, 2});
      slog::Relation* readrel1164 = db->getRelation("lambda");
      lambdaindex1109 = readrel1164->getIndex(ord1163, false);
      std::vector<u16> ord1165({0, 1, 2});
      slog::Relation* readrel1166 = db->getRelation("lambda");
      lambdaindex1110 = readrel1166->getIndex(ord1165, false);
      std::vector<u16> ord1167({0, 1});
      slog::Relation* readrel1168 = db->getRelation("ref");
      refindex1111 = readrel1168->getIndex(ord1167, false);
  
    }
    ReadTask1112(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c146 = v_const0aa6f87434af0222b916e97a;
      u64 v_c148 = v_constd3d07026d47882ceca728218;
      u64 v_c147 = v_const227d34ceeba7a29aada993d4;
      u64 v_c150 = v_constf700a82e218a86de572e1f7f;
      u64 v_c149 = v_const59ba3256d223f0d0a00d0633;
      u64 v_c151 = v_const7cd75b35aa30c3ddf04f9d57;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c167 = _t[0];
        u64 v_c168 = _t[1];
        u64 v_c166 = _t[2];
        if (!slog::exists_probe<3,2>(lambdaindex1085, std::array<u64,3>{v_c168, v_c146, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1086, std::array<u64,2>{v_c148, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1087, std::array<u64,3>{v_c150, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1088, std::array<u64,2>{v_c150, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1089, std::array<u64,2>{v_c146, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1090, std::array<u64,2>{v_c149, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1091, std::array<u64,3>{v_c149, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1092, std::array<u64,3>{v_c147, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1093, std::array<u64,3>{v_c151, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1094, std::array<u64,2>{v_c151, 0})) return;
        slog::join_probe<3,2>(lambdaindex1095, std::array<u64,3>{v_c166, v_c148, 0}, [&](const std::array<u64,3>& m1169) {
          u64 v_c165 = m1169[2];
          slog::join_probe<3,2>(lambdaindex1096, std::array<u64,3>{v_c168, v_c146, 0}, [&](const std::array<u64,3>& m1170) {
            u64 v_c152 = m1170[2];
            slog::join_probe<2,1>(refindex1097, std::array<u64,2>{v_c148, 0}, [&](const std::array<u64,2>& m1171) {
              u64 v_c162 = m1171[1];
              slog::join_probe<3,2>(appindex1098, std::array<u64,3>{v_c165, v_c162, 0}, [&](const std::array<u64,3>& m1172) {
                u64 v_c164 = m1172[2];
                slog::join_probe<3,2>(lambdaindex1099, std::array<u64,3>{v_c164, v_c150, 0}, [&](const std::array<u64,3>& m1173) {
                  u64 v_c163 = m1173[2];
                  slog::join_probe<2,2>(refindex1100, std::array<u64,2>{v_c163, v_c150}, [&](const std::array<u64,2>& m1174) {
                    slog::join_probe<2,1>(refindex1101, std::array<u64,2>{v_c146, 0}, [&](const std::array<u64,2>& m1175) {
                      u64 v_c156 = m1175[1];
                      if (!slog::exists_probe<3,1>(appindex1102, std::array<u64,3>{v_c156, 0, 0})) return;
                      slog::join_probe<2,1>(refindex1103, std::array<u64,2>{v_c149, 0}, [&](const std::array<u64,2>& m1176) {
                        u64 v_c158 = m1176[1];
                        slog::join_probe<3,2>(lambdaindex1104, std::array<u64,3>{v_c149, v_c158, 0}, [&](const std::array<u64,3>& m1177) {
                          u64 v_c157 = m1177[2];
                          slog::join_probe<3,2>(appindex1105, std::array<u64,3>{v_c156, v_c157, 0}, [&](const std::array<u64,3>& m1178) {
                            u64 v_c154 = m1178[2];
                            slog::join_probe<3,2>(appindex1106, std::array<u64,3>{v_c154, v_c152, 0}, [&](const std::array<u64,3>& m1179) {
                              u64 v_c153 = m1179[2];
                              slog::join_probe<3,2>(lambdaindex1107, std::array<u64,3>{v_c153, v_c147, 0}, [&](const std::array<u64,3>& m1180) {
                                u64 v_c155 = m1180[2];
                                slog::join_probe<3,2>(appindex1108, std::array<u64,3>{v_c155, v_c156, 0}, [&](const std::array<u64,3>& m1181) {
                                  u64 v_c159 = m1181[2];
                                  slog::join_probe<3,2>(lambdaindex1109, std::array<u64,3>{v_c159, v_c149, 0}, [&](const std::array<u64,3>& m1182) {
                                    u64 v_c160 = m1182[2];
                                    slog::join_probe<3,2>(lambdaindex1110, std::array<u64,3>{v_c160, v_c151, 0}, [&](const std::array<u64,3>& m1183) {
                                      u64 v_c161 = m1183[2];
                                      slog::join_probe<2,2>(refindex1111, std::array<u64,2>{v_c161, v_c151}, [&](const std::array<u64,2>& m1184) {
                                        ++_fires;
                                        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c167}, std::array<u16,1>{0});
                                      });
                                    });
                                  });
                                });
                              });
                            });
                          });
                        });
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
  
      if (_fires) db->bumpFires("mcfa-counting.slog:287", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask1112* _cont = new ReadTask1112(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1112(db,b), false);
  // (crule (pre (let __tconst1pJW313 constb49bea2fcccd8f4301a347ed) (let __tconst7LWP310 const66518c0c1b3a5a0b09ae2ef1) (let __tconst0sqO307 const4a8acfc71441e0695ffcf5b3) (let __tconst5PoN291 constc85eae03730a4f4cf1d66a0c) (let __tconst2Yzp284 const8ca682693a0738a0641c6956) (let __tconst9rZO295 const576506f61f53440f1edd95d2) (let __tconst2CSv302 const229c0b7aa8a7eb4055f5a3d0)) (seeded) (body (join ref (1 0) 1 __tconst7LWP310 __t91H2298) (exists lambda (1 2 0) 1 __tconst2Yzp284) (exists ref (1 0) 1 __tconst1pJW313) (exists ref (1 0) 1 __tconst9rZO295) (exists lambda (1 2 0) 1 __tconst9rZO295) (exists app (1 2 0) 1 __t91H2298) (exists ref (1 0) 1 __tconst2CSv302) (exists lambda (1 2 0) 1 __tconst2CSv302) (exists lambda (1 2 0) 1 __tconst0sqO307) (exists lambda (1 2 0) 1 __tconst5PoN291) (join ref (1 0) 1 __tconst2Yzp284 __t248W283) (join lambda (1 2 0) 2 __tconst2Yzp284 __t248W283 __t0oFu285) (join ref (1 0) 1 __tconst1pJW313 __t165O287) (exists app (1 2 0) 1 __t165O287) (join ref (1 0) 1 __tconst9rZO295 __t71w7294) (join lambda (1 2 0) 2 __tconst9rZO295 __t71w7294 __t3dkk296) (join app (1 2 0) 2 __t91H2298 __t3dkk296 __t4LtH299) (exists app (2 0 1) 1 __t4LtH299) (join ref (1 0) 1 __tconst2CSv302 __t6lXa301) (join lambda (1 2 0) 2 __tconst2CSv302 __t6lXa301 __t7EW2303) (join app (1 2 0) 2 __t91H2298 __t7EW2303 __t4HUX306) (join lambda (1 2 0) 2 __tconst0sqO307 __t4HUX306 __t0vn1308) (join app (1 2 0) 2 __t0vn1308 __t4LtH299 __t6t9L309) (join app (1 2 0) 1 __t165O287 dup95rC382 __t30Ec290) (eq __t165O287 dup95rC382) (join lambda (1 2 0) 2 __tconst5PoN291 __t30Ec290 __t7aCZ292)) (head (mkstruct lambda (1 2 0) __t5T0g311 __tconst7LWP310 __t6t9L309)) mcfa-counting.slog:194 #f)
  class ReadTask1210 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex1185;  slog::Index** lambdaindex1186;  slog::Index** refindex1187;  slog::Index** refindex1188;  slog::Index** lambdaindex1189;  slog::Index** appindex1190;  slog::Index** refindex1191;  slog::Index** lambdaindex1192;  slog::Index** lambdaindex1193;  slog::Index** lambdaindex1194;  slog::Index** refindex1195;  slog::Index** lambdaindex1196;  slog::Index** refindex1197;  slog::Index** appindex1198;  slog::Index** refindex1199;  slog::Index** lambdaindex1200;  slog::Index** appindex1201;  slog::Index** appindex1202;  slog::Index** refindex1203;  slog::Index** lambdaindex1204;  slog::Index** appindex1205;  slog::Index** lambdaindex1206;  slog::Index** appindex1207;  slog::Index** appindex1208;  slog::Index** lambdaindex1209;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      std::vector<u16> ord1211({1, 2, 0});
      slog::Relation* readrel1212 = db->getRelation("lambda");
      head_index[0] = readrel1212->getIndex(ord1211, false);
      std::vector<u16> ord1213({1, 0});
      slog::Relation* readrel1214 = db->getRelation("ref");
      refindex1185 = readrel1214->getIndex(ord1213, false);
      std::vector<u16> ord1215({1, 2, 0});
      slog::Relation* readrel1216 = db->getRelation("lambda");
      lambdaindex1186 = readrel1216->getIndex(ord1215, false);
      std::vector<u16> ord1217({1, 0});
      slog::Relation* readrel1218 = db->getRelation("ref");
      refindex1187 = readrel1218->getIndex(ord1217, false);
      std::vector<u16> ord1219({1, 0});
      slog::Relation* readrel1220 = db->getRelation("ref");
      refindex1188 = readrel1220->getIndex(ord1219, false);
      std::vector<u16> ord1221({1, 2, 0});
      slog::Relation* readrel1222 = db->getRelation("lambda");
      lambdaindex1189 = readrel1222->getIndex(ord1221, false);
      std::vector<u16> ord1223({1, 2, 0});
      slog::Relation* readrel1224 = db->getRelation("app");
      appindex1190 = readrel1224->getIndex(ord1223, false);
      std::vector<u16> ord1225({1, 0});
      slog::Relation* readrel1226 = db->getRelation("ref");
      refindex1191 = readrel1226->getIndex(ord1225, false);
      std::vector<u16> ord1227({1, 2, 0});
      slog::Relation* readrel1228 = db->getRelation("lambda");
      lambdaindex1192 = readrel1228->getIndex(ord1227, false);
      std::vector<u16> ord1229({1, 2, 0});
      slog::Relation* readrel1230 = db->getRelation("lambda");
      lambdaindex1193 = readrel1230->getIndex(ord1229, false);
      std::vector<u16> ord1231({1, 2, 0});
      slog::Relation* readrel1232 = db->getRelation("lambda");
      lambdaindex1194 = readrel1232->getIndex(ord1231, false);
      std::vector<u16> ord1233({1, 0});
      slog::Relation* readrel1234 = db->getRelation("ref");
      refindex1195 = readrel1234->getIndex(ord1233, false);
      std::vector<u16> ord1235({1, 2, 0});
      slog::Relation* readrel1236 = db->getRelation("lambda");
      lambdaindex1196 = readrel1236->getIndex(ord1235, false);
      std::vector<u16> ord1237({1, 0});
      slog::Relation* readrel1238 = db->getRelation("ref");
      refindex1197 = readrel1238->getIndex(ord1237, false);
      std::vector<u16> ord1239({1, 2, 0});
      slog::Relation* readrel1240 = db->getRelation("app");
      appindex1198 = readrel1240->getIndex(ord1239, false);
      std::vector<u16> ord1241({1, 0});
      slog::Relation* readrel1242 = db->getRelation("ref");
      refindex1199 = readrel1242->getIndex(ord1241, false);
      std::vector<u16> ord1243({1, 2, 0});
      slog::Relation* readrel1244 = db->getRelation("lambda");
      lambdaindex1200 = readrel1244->getIndex(ord1243, false);
      std::vector<u16> ord1245({1, 2, 0});
      slog::Relation* readrel1246 = db->getRelation("app");
      appindex1201 = readrel1246->getIndex(ord1245, false);
      std::vector<u16> ord1247({2, 0, 1});
      slog::Relation* readrel1248 = db->getRelation("app");
      appindex1202 = readrel1248->getIndex(ord1247, false);
      std::vector<u16> ord1249({1, 0});
      slog::Relation* readrel1250 = db->getRelation("ref");
      refindex1203 = readrel1250->getIndex(ord1249, false);
      std::vector<u16> ord1251({1, 2, 0});
      slog::Relation* readrel1252 = db->getRelation("lambda");
      lambdaindex1204 = readrel1252->getIndex(ord1251, false);
      std::vector<u16> ord1253({1, 2, 0});
      slog::Relation* readrel1254 = db->getRelation("app");
      appindex1205 = readrel1254->getIndex(ord1253, false);
      std::vector<u16> ord1255({1, 2, 0});
      slog::Relation* readrel1256 = db->getRelation("lambda");
      lambdaindex1206 = readrel1256->getIndex(ord1255, false);
      std::vector<u16> ord1257({1, 2, 0});
      slog::Relation* readrel1258 = db->getRelation("app");
      appindex1207 = readrel1258->getIndex(ord1257, false);
      std::vector<u16> ord1259({1, 2, 0});
      slog::Relation* readrel1260 = db->getRelation("app");
      appindex1208 = readrel1260->getIndex(ord1259, false);
      std::vector<u16> ord1261({1, 2, 0});
      slog::Relation* readrel1262 = db->getRelation("lambda");
      lambdaindex1209 = readrel1262->getIndex(ord1261, false);
  
    }
    ReadTask1210(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c101 = v_constb49bea2fcccd8f4301a347ed;
      u64 v_c102 = v_const66518c0c1b3a5a0b09ae2ef1;
      u64 v_c103 = v_const4a8acfc71441e0695ffcf5b3;
      u64 v_c106 = v_constc85eae03730a4f4cf1d66a0c;
      u64 v_c107 = v_const8ca682693a0738a0641c6956;
      u64 v_c105 = v_const576506f61f53440f1edd95d2;
      u64 v_c104 = v_const229c0b7aa8a7eb4055f5a3d0;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex1185, std::array<u64,2>{v_c102, 0}, [&](const std::array<u64,2>& m1263) {
        u64 v_c111 = m1263[1];
        if (!slog::exists_probe<3,1>(lambdaindex1186, std::array<u64,3>{v_c107, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1187, std::array<u64,2>{v_c101, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1188, std::array<u64,2>{v_c105, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1189, std::array<u64,3>{v_c105, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex1190, std::array<u64,3>{v_c111, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1191, std::array<u64,2>{v_c104, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1192, std::array<u64,3>{v_c104, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1193, std::array<u64,3>{v_c103, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1194, std::array<u64,3>{v_c106, 0, 0})) return;
        slog::join_probe<2,1>(refindex1195, std::array<u64,2>{v_c107, 0}, [&](const std::array<u64,2>& m1264) {
          u64 v_c108 = m1264[1];
          slog::join_probe<3,2>(lambdaindex1196, std::array<u64,3>{v_c107, v_c108, 0}, [&](const std::array<u64,3>& m1265) {
            u64 v_c169 = m1265[2];
            slog::join_probe<2,1>(refindex1197, std::array<u64,2>{v_c101, 0}, [&](const std::array<u64,2>& m1266) {
              u64 v_c109 = m1266[1];
              if (!slog::exists_probe<3,1>(appindex1198, std::array<u64,3>{v_c109, 0, 0})) return;
              slog::join_probe<2,1>(refindex1199, std::array<u64,2>{v_c105, 0}, [&](const std::array<u64,2>& m1267) {
                u64 v_c110 = m1267[1];
                slog::join_probe<3,2>(lambdaindex1200, std::array<u64,3>{v_c105, v_c110, 0}, [&](const std::array<u64,3>& m1268) {
                  u64 v_c170 = m1268[2];
                  slog::join_probe<3,2>(appindex1201, std::array<u64,3>{v_c111, v_c170, 0}, [&](const std::array<u64,3>& m1269) {
                    u64 v_c171 = m1269[2];
                    if (!slog::exists_probe<3,1>(appindex1202, std::array<u64,3>{v_c171, 0, 0})) return;
                    slog::join_probe<2,1>(refindex1203, std::array<u64,2>{v_c104, 0}, [&](const std::array<u64,2>& m1270) {
                      u64 v_c112 = m1270[1];
                      slog::join_probe<3,2>(lambdaindex1204, std::array<u64,3>{v_c104, v_c112, 0}, [&](const std::array<u64,3>& m1271) {
                        u64 v_c172 = m1271[2];
                        slog::join_probe<3,2>(appindex1205, std::array<u64,3>{v_c111, v_c172, 0}, [&](const std::array<u64,3>& m1272) {
                          u64 v_c173 = m1272[2];
                          slog::join_probe<3,2>(lambdaindex1206, std::array<u64,3>{v_c103, v_c173, 0}, [&](const std::array<u64,3>& m1273) {
                            u64 v_c174 = m1273[2];
                            slog::join_probe<3,2>(appindex1207, std::array<u64,3>{v_c174, v_c171, 0}, [&](const std::array<u64,3>& m1274) {
                              u64 v_c175 = m1274[2];
                              slog::join_probe<3,1>(appindex1208, std::array<u64,3>{v_c109, 0, 0}, [&](const std::array<u64,3>& m1275) {
                                u64 v_c176 = m1275[1]; u64 v_c177 = m1275[2];
                                if (v_c109 != v_c176) return;
                                slog::join_probe<3,2>(lambdaindex1209, std::array<u64,3>{v_c106, v_c177, 0}, [&](const std::array<u64,3>& m1276) {
                                  u64 v_c178 = m1276[2];
                                  ++_fires;
                                  slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c102, v_c175}, std::array<u16,3>{1, 2, 0});
                                });
                              });
                            });
                          });
                        });
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
      s->addTaskSeeded(phase_read, new ReadTask1210(db,b));
  // (crule (pre (let __tconst0zC2144 const4e3b5454cf93e32fad90650d) (let __tconst3Taj142 constdc1bb6655fb38bdb032e3754) (let __tconst8xRt151 const3a82152bd1402931076fe2d7) (let __tconst8eg8132 const361d5df359e0d7681220d09d)) (probe lambda (1 2 0) 1 __tconst0zC2144 __t2Ce3143 __t6t5O145) (body (exists ref (1 0) 1 __tconst8eg8132) (exists lambda (1 2 0) 1 __tconst8eg8132) (exists ref (1 0) 1 __tconst3Taj142) (exists ref (1 0) 1 __tconst8xRt151) (exists ref (1 0) 1 __tconst0zC2144) (exists lambda (1 2 0) 1 __tconst8xRt151) (join lambda (0 1 2) 2 __t2Ce3143 __tconst3Taj142 __t25NQ141) (join ref (1 0) 1 __tconst8eg8132 __t19JM131) (join lambda (1 2 0) 2 __tconst8eg8132 __t19JM131 __t4DXA133) (join ref (1 0) 1 __tconst3Taj142 __t93Xi135) (join app (2 0 1) 2 __t93Xi135 __t25NQ141 __t8dYW140) (join ref (1 0) 1 __tconst8xRt151 __t1g2P147) (exists app (1 2 0) 1 __t1g2P147) (join ref (1 0) 1 __tconst0zC2144 __t7VSc137) (join app (0 1 2) 2 __t8dYW140 __t7VSc137 dup4Z67404) (eq __t7VSc137 dup4Z67404) (join app (1 2 0) 1 __t1g2P147 dup4Yw8403 __t9UZN150) (eq __t1g2P147 dup4Yw8403) (join lambda (1 2 0) 2 __tconst8xRt151 __t9UZN150 __t2nYy152)) (head (mkstruct app (1 2 0) __t6Ups153 __t2nYy152 __t6t5O145)) mcfa-counting.slog:224 #f)
  class ReadTask1294 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** refindex1277;  slog::Index** lambdaindex1278;  slog::Index** refindex1279;  slog::Index** refindex1280;  slog::Index** refindex1281;  slog::Index** lambdaindex1282;  slog::Index** lambdaindex1283;  slog::Index** refindex1284;  slog::Index** lambdaindex1285;  slog::Index** refindex1286;  slog::Index** appindex1287;  slog::Index** refindex1288;  slog::Index** appindex1289;  slog::Index** refindex1290;  slog::Index** appindex1291;  slog::Index** appindex1292;  slog::Index** lambdaindex1293;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord1295({1, 2, 0});
      slog::Relation* readrel1296 = db->getRelation("lambda");
      driver_index = readrel1296->getIndex(ord1295, true);
      std::vector<u16> ord1297({1, 0});
      slog::Relation* readrel1298 = db->getRelation("ref");
      refindex1277 = readrel1298->getIndex(ord1297, false);
      std::vector<u16> ord1299({1, 2, 0});
      slog::Relation* readrel1300 = db->getRelation("lambda");
      lambdaindex1278 = readrel1300->getIndex(ord1299, false);
      std::vector<u16> ord1301({1, 0});
      slog::Relation* readrel1302 = db->getRelation("ref");
      refindex1279 = readrel1302->getIndex(ord1301, false);
      std::vector<u16> ord1303({1, 0});
      slog::Relation* readrel1304 = db->getRelation("ref");
      refindex1280 = readrel1304->getIndex(ord1303, false);
      std::vector<u16> ord1305({1, 0});
      slog::Relation* readrel1306 = db->getRelation("ref");
      refindex1281 = readrel1306->getIndex(ord1305, false);
      std::vector<u16> ord1307({1, 2, 0});
      slog::Relation* readrel1308 = db->getRelation("lambda");
      lambdaindex1282 = readrel1308->getIndex(ord1307, false);
      std::vector<u16> ord1309({0, 1, 2});
      slog::Relation* readrel1310 = db->getRelation("lambda");
      lambdaindex1283 = readrel1310->getIndex(ord1309, false);
      std::vector<u16> ord1311({1, 0});
      slog::Relation* readrel1312 = db->getRelation("ref");
      refindex1284 = readrel1312->getIndex(ord1311, false);
      std::vector<u16> ord1313({1, 2, 0});
      slog::Relation* readrel1314 = db->getRelation("lambda");
      lambdaindex1285 = readrel1314->getIndex(ord1313, false);
      std::vector<u16> ord1315({1, 0});
      slog::Relation* readrel1316 = db->getRelation("ref");
      refindex1286 = readrel1316->getIndex(ord1315, false);
      std::vector<u16> ord1317({2, 0, 1});
      slog::Relation* readrel1318 = db->getRelation("app");
      appindex1287 = readrel1318->getIndex(ord1317, false);
      std::vector<u16> ord1319({1, 0});
      slog::Relation* readrel1320 = db->getRelation("ref");
      refindex1288 = readrel1320->getIndex(ord1319, false);
      std::vector<u16> ord1321({1, 2, 0});
      slog::Relation* readrel1322 = db->getRelation("app");
      appindex1289 = readrel1322->getIndex(ord1321, false);
      std::vector<u16> ord1323({1, 0});
      slog::Relation* readrel1324 = db->getRelation("ref");
      refindex1290 = readrel1324->getIndex(ord1323, false);
      std::vector<u16> ord1325({0, 1, 2});
      slog::Relation* readrel1326 = db->getRelation("app");
      appindex1291 = readrel1326->getIndex(ord1325, false);
      std::vector<u16> ord1327({1, 2, 0});
      slog::Relation* readrel1328 = db->getRelation("app");
      appindex1292 = readrel1328->getIndex(ord1327, false);
      std::vector<u16> ord1329({1, 2, 0});
      slog::Relation* readrel1330 = db->getRelation("lambda");
      lambdaindex1293 = readrel1330->getIndex(ord1329, false);
  
    }
    ReadTask1294(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c64 = v_const4e3b5454cf93e32fad90650d;
      u64 v_c66 = v_constdc1bb6655fb38bdb032e3754;
      u64 v_c65 = v_const3a82152bd1402931076fe2d7;
      u64 v_c63 = v_const361d5df359e0d7681220d09d;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c64, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1331) {
        u64 v_c78 = m1331[1];
        u64 v_c77 = m1331[2];
        if (buckethash(v_c78) != bucket) return;
        if (!slog::exists_probe<2,1>(refindex1277, std::array<u64,2>{v_c63, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1278, std::array<u64,3>{v_c63, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1279, std::array<u64,2>{v_c66, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1280, std::array<u64,2>{v_c65, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1281, std::array<u64,2>{v_c64, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1282, std::array<u64,3>{v_c65, 0, 0})) return;
        slog::join_probe<3,2>(lambdaindex1283, std::array<u64,3>{v_c78, v_c66, 0}, [&](const std::array<u64,3>& m1332) {
          u64 v_c79 = m1332[2];
          slog::join_probe<2,1>(refindex1284, std::array<u64,2>{v_c63, 0}, [&](const std::array<u64,2>& m1333) {
            u64 v_c70 = m1333[1];
            slog::join_probe<3,2>(lambdaindex1285, std::array<u64,3>{v_c63, v_c70, 0}, [&](const std::array<u64,3>& m1334) {
              u64 v_c69 = m1334[2];
              slog::join_probe<2,1>(refindex1286, std::array<u64,2>{v_c66, 0}, [&](const std::array<u64,2>& m1335) {
                u64 v_c72 = m1335[1];
                slog::join_probe<3,2>(appindex1287, std::array<u64,3>{v_c72, v_c79, 0}, [&](const std::array<u64,3>& m1336) {
                  u64 v_c80 = m1336[2];
                  slog::join_probe<2,1>(refindex1288, std::array<u64,2>{v_c65, 0}, [&](const std::array<u64,2>& m1337) {
                    u64 v_c71 = m1337[1];
                    if (!slog::exists_probe<3,1>(appindex1289, std::array<u64,3>{v_c71, 0, 0})) return;
                    slog::join_probe<2,1>(refindex1290, std::array<u64,2>{v_c64, 0}, [&](const std::array<u64,2>& m1338) {
                      u64 v_c73 = m1338[1];
                      slog::join_probe<3,2>(appindex1291, std::array<u64,3>{v_c80, v_c73, 0}, [&](const std::array<u64,3>& m1339) {
                        u64 v_c179 = m1339[2];
                        if (v_c73 != v_c179) return;
                        slog::join_probe<3,1>(appindex1292, std::array<u64,3>{v_c71, 0, 0}, [&](const std::array<u64,3>& m1340) {
                          u64 v_c180 = m1340[1]; u64 v_c75 = m1340[2];
                          if (v_c71 != v_c180) return;
                          slog::join_probe<3,2>(lambdaindex1293, std::array<u64,3>{v_c65, v_c75, 0}, [&](const std::array<u64,3>& m1341) {
                            u64 v_c76 = m1341[2];
                            ++_fires;
                            slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c76, v_c77}, std::array<u16,3>{1, 2, 0});
                          });
                        });
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
  
      if (_fires) db->bumpFires("mcfa-counting.slog:224", "delta:lambda", _fires);
  
      if (!_done)
      {
        ReadTask1294* _cont = new ReadTask1294(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1294(db,b), false);
  // (crule (pre (let __trid2dX2349 const8d8bcc50ea388ca2a2cd3f92) (let __trel1hBV350 const3f20de5ef71f7ccc981391b7) (let __tcol61w5351 const5feceb66ffc86f38d952786c)) (scan lambda __t3mrW8 x eb) (body (join-old eval (1 2 0) 1 (1 2 0) __t3mrW8 c __t3GAu9)) (head (tycheck __t3mrW8 (accept (struct lambda)) __trid2dX2349 __trel1hBV350 __tcol61w5351 (1 2 3 4 0)) (emit-temp temp0sJH415 __t3GAu9 __t3mrW8 c) (mkstruct clo (1 2 0) __t4Sp77 __t3mrW8 c)) mcfa-counting.slog:78 #f)
  class ReadTask1345 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1342;  slog::Index** evaldelta1343;
    u32 sid1344;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("temp0sJH415");
      head_rel[2] = db->getRelation("clo");
      outer_rel = db->getRelation("lambda");
      std::vector<u16> ord1346({1, 2, 0});
      slog::Relation* readrel1347 = db->getRelation("eval");
      evalindex1342 = readrel1347->getIndex(ord1346, false);
      std::vector<u16> ord1348({1, 2, 0});
      slog::Relation* readrel1349 = db->getRelation("eval");
      evaldelta1343 = readrel1349->getIndex(ord1348, true);
      sid1344 = db->getRelation("lambda")->getStructId();
  
    }
    ReadTask1345(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c181 = v_const8d8bcc50ea388ca2a2cd3f92;
      u64 v_c182 = v_const3f20de5ef71f7ccc981391b7;
      u64 v_c183 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c184 = _t[0];
        u64 v_c6 = _t[1];
        u64 v_c118 = _t[2];
        slog::join_probe_old<3,1>(evalindex1342, evaldelta1343, std::array<u64,3>{v_c184, 0, 0}, [&](const std::array<u64,3>& m1350) {
          u64 v_c2 = m1350[1]; u64 v_c185 = m1350[2];
          ++_fires;
          if (!((is_struct(v_c184) && (decode_struct_id(v_c184) == sid1344))))
          {
            slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c181, v_c182, v_c183, v_c184}, std::array<u16,5>{1, 2, 3, 4, 0});
            return;
          }
          slog::emit_temp<3>(head_rel[1], newbatch[1], std::array<u64,3>{v_c185, v_c184, v_c2});
          slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c184, v_c2}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:78", "delta:lambda", _fires);
  
      if (!_done)
      {
        ReadTask1345* _cont = new ReadTask1345(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1345(db,b), false);
  // (crule (pre (let __tconst7sqz226 const7b8fd91ee9ff10cfbb8066bf) (let __tconst1EUj230 const615ad01b1c532bb6634df115) (let __tconst2VuQ234 const4492fd5fa4baacfebd29f5e5) (let __tconst2x2f244 consta32d5a443def48e6d64c6f4b) (let __tconst4Sko246 consteb793a6f75d6cfe49d3c2c90) (let __tconst4N2q248 constaaaad65142343c54348db5d0)) (seeded) (body (join ref (1 0) 1 __tconst4N2q248 __t6KL4241) (exists ref (1 0) 1 __tconst2x2f244) (exists ref (1 0) 1 __tconst2VuQ234) (exists ref (1 0) 1 __tconst1EUj230) (exists ref (1 0) 1 __tconst7sqz226) (join ref (1 0) 1 __tconst4Sko246 __t16jv239) (join ref (1 0) 1 __tconst2x2f244 __t3pbc237) (join ref (1 0) 1 __tconst2VuQ234 __t2PLq233) (join ref (1 0) 1 __tconst1EUj230 __t3WVP229) (join ref (1 0) 1 __tconst7sqz226 __t5APF225)) (head (mkstruct lambda (1 2 0) __t2BAX227 __tconst7sqz226 __t5APF225) (mkstruct lambda (1 2 0) __t5ryk231 __tconst1EUj230 __t3WVP229) (mkstruct lambda (1 2 0) __t45rU235 __tconst2VuQ234 __t2PLq233) (mkstruct app (1 2 0) __t4wvK242 __t6KL4241 __t16jv239)) mcfa-counting.slog:272 #f)
  class ReadTask1361 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[4];
    slog::Index** head_index[4];
  
  
  
  
  
  
    slog::Index** refindex1351;  slog::Index** refindex1352;  slog::Index** refindex1353;  slog::Index** refindex1354;  slog::Index** refindex1355;  slog::Index** refindex1356;  slog::Index** refindex1357;  slog::Index** refindex1358;  slog::Index** refindex1359;  slog::Index** refindex1360;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      std::vector<u16> ord1362({1, 2, 0});
      slog::Relation* readrel1363 = db->getRelation("lambda");
      head_index[0] = readrel1363->getIndex(ord1362, false);
      head_rel[1] = db->getRelation("lambda");
      std::vector<u16> ord1364({1, 2, 0});
      slog::Relation* readrel1365 = db->getRelation("lambda");
      head_index[1] = readrel1365->getIndex(ord1364, false);
      head_rel[2] = db->getRelation("lambda");
      std::vector<u16> ord1366({1, 2, 0});
      slog::Relation* readrel1367 = db->getRelation("lambda");
      head_index[2] = readrel1367->getIndex(ord1366, false);
      head_rel[3] = db->getRelation("app");
      std::vector<u16> ord1368({1, 2, 0});
      slog::Relation* readrel1369 = db->getRelation("app");
      head_index[3] = readrel1369->getIndex(ord1368, false);
      std::vector<u16> ord1370({1, 0});
      slog::Relation* readrel1371 = db->getRelation("ref");
      refindex1351 = readrel1371->getIndex(ord1370, false);
      std::vector<u16> ord1372({1, 0});
      slog::Relation* readrel1373 = db->getRelation("ref");
      refindex1352 = readrel1373->getIndex(ord1372, false);
      std::vector<u16> ord1374({1, 0});
      slog::Relation* readrel1375 = db->getRelation("ref");
      refindex1353 = readrel1375->getIndex(ord1374, false);
      std::vector<u16> ord1376({1, 0});
      slog::Relation* readrel1377 = db->getRelation("ref");
      refindex1354 = readrel1377->getIndex(ord1376, false);
      std::vector<u16> ord1378({1, 0});
      slog::Relation* readrel1379 = db->getRelation("ref");
      refindex1355 = readrel1379->getIndex(ord1378, false);
      std::vector<u16> ord1380({1, 0});
      slog::Relation* readrel1381 = db->getRelation("ref");
      refindex1356 = readrel1381->getIndex(ord1380, false);
      std::vector<u16> ord1382({1, 0});
      slog::Relation* readrel1383 = db->getRelation("ref");
      refindex1357 = readrel1383->getIndex(ord1382, false);
      std::vector<u16> ord1384({1, 0});
      slog::Relation* readrel1385 = db->getRelation("ref");
      refindex1358 = readrel1385->getIndex(ord1384, false);
      std::vector<u16> ord1386({1, 0});
      slog::Relation* readrel1387 = db->getRelation("ref");
      refindex1359 = readrel1387->getIndex(ord1386, false);
      std::vector<u16> ord1388({1, 0});
      slog::Relation* readrel1389 = db->getRelation("ref");
      refindex1360 = readrel1389->getIndex(ord1388, false);
  
    }
    ReadTask1361(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c82 = v_const7b8fd91ee9ff10cfbb8066bf;
      u64 v_c83 = v_const615ad01b1c532bb6634df115;
      u64 v_c84 = v_const4492fd5fa4baacfebd29f5e5;
      u64 v_c85 = v_consta32d5a443def48e6d64c6f4b;
      u64 v_c86 = v_consteb793a6f75d6cfe49d3c2c90;
      u64 v_c87 = v_constaaaad65142343c54348db5d0;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[4];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex1351, std::array<u64,2>{v_c87, 0}, [&](const std::array<u64,2>& m1390) {
        u64 v_c88 = m1390[1];
        if (!slog::exists_probe<2,1>(refindex1352, std::array<u64,2>{v_c85, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1353, std::array<u64,2>{v_c84, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1354, std::array<u64,2>{v_c83, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1355, std::array<u64,2>{v_c82, 0})) return;
        slog::join_probe<2,1>(refindex1356, std::array<u64,2>{v_c86, 0}, [&](const std::array<u64,2>& m1391) {
          u64 v_c89 = m1391[1];
          slog::join_probe<2,1>(refindex1357, std::array<u64,2>{v_c85, 0}, [&](const std::array<u64,2>& m1392) {
            u64 v_c91 = m1392[1];
            slog::join_probe<2,1>(refindex1358, std::array<u64,2>{v_c84, 0}, [&](const std::array<u64,2>& m1393) {
              u64 v_c92 = m1393[1];
              slog::join_probe<2,1>(refindex1359, std::array<u64,2>{v_c83, 0}, [&](const std::array<u64,2>& m1394) {
                u64 v_c94 = m1394[1];
                slog::join_probe<2,1>(refindex1360, std::array<u64,2>{v_c82, 0}, [&](const std::array<u64,2>& m1395) {
                  u64 v_c96 = m1395[1];
                  ++_fires;
                  slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c82, v_c96}, std::array<u16,3>{1, 2, 0});
                  slog::emit_struct_checked<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c83, v_c94}, std::array<u16,3>{1, 2, 0});
                  slog::emit_struct_checked<3>(head_rel[2], head_index[2], newbatch[2], std::array<u64,2>{v_c84, v_c92}, std::array<u16,3>{1, 2, 0});
                  slog::emit_struct_checked<3>(head_rel[3], head_index[3], newbatch[3], std::array<u64,2>{v_c88, v_c89}, std::array<u16,3>{1, 2, 0});
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
  
      if (_fires) db->bumpFires("mcfa-counting.slog:272", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask1361(db,b));
  // (crule (pre) (scan eval __4DdV347 __t5Yh14 c) (body (join-old app (0 1 2) 1 (0 1 2) __t5Yh14 ef ea) (join freevar (0 1) 0 y __t4I265) (join store (0 1 2) 1 y cb vy) (join lambda (0 1 2) 1 __t4I265 x eb)) (head (mkstruct eval (1 2 0) __34Tv348 ea c)) mcfa-counting.slog:102 #f)
  class ReadTask1401 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex1396;  slog::Index** freevarindex1397;  slog::Index** storeindex1398;  slog::Index** lambdaindex1399;  slog::Index** appdelta1400;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord1402({0, 1, 2});
      slog::Relation* readrel1403 = db->getRelation("app");
      appindex1396 = readrel1403->getIndex(ord1402, false);
      std::vector<u16> ord1404({0, 1, 2});
      slog::Relation* readrel1405 = db->getRelation("app");
      appdelta1400 = readrel1405->getIndex(ord1404, true);
      std::vector<u16> ord1406({0, 1});
      slog::Relation* readrel1407 = db->getRelation("freevar");
      freevarindex1397 = readrel1407->getIndex(ord1406, false);
      std::vector<u16> ord1408({0, 1, 2});
      slog::Relation* readrel1409 = db->getRelation("store");
      storeindex1398 = readrel1409->getIndex(ord1408, false);
      std::vector<u16> ord1410({0, 1, 2});
      slog::Relation* readrel1411 = db->getRelation("lambda");
      lambdaindex1399 = readrel1411->getIndex(ord1410, false);
  
    }
    ReadTask1401(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c186 = _t[0];
        u64 v_c187 = _t[1];
        u64 v_c2 = _t[2];
        slog::join_probe_old<3,1>(appindex1396, appdelta1400, std::array<u64,3>{v_c187, 0, 0}, [&](const std::array<u64,3>& m1412) {
          u64 v_c3 = m1412[1]; u64 v_c4 = m1412[2];
          slog::join_all<2>(freevarindex1397, [&](const std::array<u64,2>& m1413) {
            u64 v_c188 = m1413[0]; u64 v_c189 = m1413[1];
            slog::join_probe<3,1>(storeindex1398, std::array<u64,3>{v_c188, 0, 0}, [&](const std::array<u64,3>& m1414) {
              u64 v_c117 = m1414[1]; u64 v_c190 = m1414[2];
              slog::join_probe<3,1>(lambdaindex1399, std::array<u64,3>{v_c189, 0, 0}, [&](const std::array<u64,3>& m1415) {
                u64 v_c6 = m1415[1]; u64 v_c118 = m1415[2];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c4, v_c2}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:102", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask1401* _cont = new ReadTask1401(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1401(db,b), false);
  // (crule (pre) (scan freevar y __t3DWB162) (body (join store (0 1 2) 1 y cb vy) (join-old lambda (0 1 2) 1 (0 1 2) __t3DWB162 x eb) (join-old eval (0 2 1) 0 (0 2 1) __9gNV361 c __t0neE161) (join-old app (0 1 2) 1 (0 1 2) __t0neE161 ef ea)) (head (mkstruct eval (1 2 0) __1Zia362 ef c)) mcfa-counting.slog:102 #f)
  class ReadTask1423 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** storeindex1416;  slog::Index** lambdaindex1417;  slog::Index** evalindex1418;  slog::Index** appindex1419;  slog::Index** lambdadelta1420;  slog::Index** evaldelta1421;  slog::Index** appdelta1422;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("freevar");
      std::vector<u16> ord1424({0, 1, 2});
      slog::Relation* readrel1425 = db->getRelation("store");
      storeindex1416 = readrel1425->getIndex(ord1424, false);
      std::vector<u16> ord1426({0, 1, 2});
      slog::Relation* readrel1427 = db->getRelation("lambda");
      lambdaindex1417 = readrel1427->getIndex(ord1426, false);
      std::vector<u16> ord1428({0, 1, 2});
      slog::Relation* readrel1429 = db->getRelation("lambda");
      lambdadelta1420 = readrel1429->getIndex(ord1428, true);
      std::vector<u16> ord1430({0, 2, 1});
      slog::Relation* readrel1431 = db->getRelation("eval");
      evalindex1418 = readrel1431->getIndex(ord1430, false);
      std::vector<u16> ord1432({0, 2, 1});
      slog::Relation* readrel1433 = db->getRelation("eval");
      evaldelta1421 = readrel1433->getIndex(ord1432, true);
      std::vector<u16> ord1434({0, 1, 2});
      slog::Relation* readrel1435 = db->getRelation("app");
      appindex1419 = readrel1435->getIndex(ord1434, false);
      std::vector<u16> ord1436({0, 1, 2});
      slog::Relation* readrel1437 = db->getRelation("app");
      appdelta1422 = readrel1437->getIndex(ord1436, true);
  
    }
    ReadTask1423(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c188 = _t[0];
        u64 v_c191 = _t[1];
        slog::join_probe<3,1>(storeindex1416, std::array<u64,3>{v_c188, 0, 0}, [&](const std::array<u64,3>& m1438) {
          u64 v_c117 = m1438[1]; u64 v_c190 = m1438[2];
          slog::join_probe_old<3,1>(lambdaindex1417, lambdadelta1420, std::array<u64,3>{v_c191, 0, 0}, [&](const std::array<u64,3>& m1439) {
            u64 v_c6 = m1439[1]; u64 v_c118 = m1439[2];
            slog::join_all_old<3>(evalindex1418, evaldelta1421, [&](const std::array<u64,3>& m1440) {
              u64 v_c192 = m1440[0]; u64 v_c2 = m1440[1]; u64 v_c193 = m1440[2];
              slog::join_probe_old<3,1>(appindex1419, appdelta1422, std::array<u64,3>{v_c193, 0, 0}, [&](const std::array<u64,3>& m1441) {
                u64 v_c3 = m1441[1]; u64 v_c4 = m1441[2];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c3, v_c2}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:102", "delta:freevar", _fires);
  
      if (!_done)
      {
        ReadTask1423* _cont = new ReadTask1423(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1423(db,b), false);
  // (crule (pre (let __tconst8R53325 conste4a9e4d8baa71a9d8ebf56ec)) (scan program e) (body (join _enum (1 0) 1 __tconst8R53325 __t9JOI196)) (head (mkstruct eval (1 2 0) __4iFP324 e __t9JOI196)) mcfa-counting.slog:112 #f)
  class ReadTask1443 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex1442;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("program");
      std::vector<u16> ord1444({1, 0});
      slog::Relation* readrel1445 = db->getRelation("_enum");
      _enumindex1442 = readrel1445->getIndex(ord1444, false);
  
    }
    ReadTask1443(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c194 = v_conste4a9e4d8baa71a9d8ebf56ec;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c195 = _t[0];
        slog::join_probe<2,1>(_enumindex1442, std::array<u64,2>{v_c194, 0}, [&](const std::array<u64,2>& m1446) {
          u64 v_c196 = m1446[1];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c195, v_c196}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:112", "delta:program", _fires);
  
      if (!_done)
      {
        ReadTask1443* _cont = new ReadTask1443(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1443(db,b), false);
}

