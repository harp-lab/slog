
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const0aa6f87434af0222b916e97a;
extern u64 v_const0f8748be649f8ee4066bb1d7;
extern u64 v_const15bb62b8293a526ca6f0e4eb;
extern u64 v_const227d34ceeba7a29aada993d4;
extern u64 v_const229c0b7aa8a7eb4055f5a3d0;
extern u64 v_const3f20de5ef71f7ccc981391b7;
extern u64 v_const4492fd5fa4baacfebd29f5e5;
extern u64 v_const4a8acfc71441e0695ffcf5b3;
extern u64 v_const4d5ce1398140fbe27561181f;
extern u64 v_const4f84f41d89b6b717419b4eaa;
extern u64 v_const50a95ec20b9767e468d04917;
extern u64 v_const576506f61f53440f1edd95d2;
extern u64 v_const5950e3cb761734f52a881545;
extern u64 v_const59ba3256d223f0d0a00d0633;
extern u64 v_const5feceb66ffc86f38d952786c;
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
extern u64 v_const8d8bcc50ea388ca2a2cd3f92;
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
extern u64 v_conste58dec6bca6f63ef79c3b755;
extern u64 v_consteb793a6f75d6cfe49d3c2c90;
extern u64 v_constf0a25c0401304c51b5ee9c5e;
extern u64 v_constf700a82e218a86de572e1f7f;
extern u64 v_constfc9ee54e0ee8c6d1e715716c;


void slog_rules_cd6e75b04dee3450c(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre (let __tconst4she277 const50a95ec20b9767e468d04917) (let __tconst0ZLv270 constf0a25c0401304c51b5ee9c5e)) (seeded) (body (join ref (1 0) 1 __tconst0ZLv270 __t9L3S266) (join ref (1 0) 1 __tconst4she277 __t28CO273)) (head (mkstruct app (1 2 0) __t6FnS276 __t28CO273 __t28CO273) (mkstruct app (1 2 0) __t8kx2269 __t9L3S266 __t9L3S266)) mcfa-counting.slog:183 #f)
  class ReadTask2 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
  
  
  
  
  
    slog::Index** refindex0;  slog::Index** refindex1;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord3({1, 2, 0});
      slog::Relation* readrel4 = db->getRelation("app");
      head_index[0] = readrel4->getIndex(ord3, false);
      head_rel[1] = db->getRelation("app");
      std::vector<u16> ord5({1, 2, 0});
      slog::Relation* readrel6 = db->getRelation("app");
      head_index[1] = readrel6->getIndex(ord5, false);
      std::vector<u16> ord7({1, 0});
      slog::Relation* readrel8 = db->getRelation("ref");
      refindex0 = readrel8->getIndex(ord7, false);
      std::vector<u16> ord9({1, 0});
      slog::Relation* readrel10 = db->getRelation("ref");
      refindex1 = readrel10->getIndex(ord9, false);
  
    }
    ReadTask2(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const50a95ec20b9767e468d04917;
      u64 v_c1 = v_constf0a25c0401304c51b5ee9c5e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex0, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m11) {
        u64 v_c2 = m11[1];
        slog::join_probe<2,1>(refindex1, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m12) {
          u64 v_c3 = m12[1];
          ++_fires;
          slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c3, v_c3}, std::array<u16,3>{1, 2, 0});
          slog::emit_struct_checked<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c2, v_c2}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:183", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask2(db,b));
  // (crule (pre (let __tconst5Fqn220 const15bb62b8293a526ca6f0e4eb) (let __tconst0ZcM213 constfc9ee54e0ee8c6d1e715716c) (let __tconst9TQS210 const5950e3cb761734f52a881545) (let __tconst1wsq203 const77ceb5c0e9f84ebd84104a97)) (probe lambda (1 2 0) 1 __tconst1wsq203 __t6pkv202 __t118D204) (body (join ref (0 1) 2 __t6pkv202 __tconst1wsq203) (exists ref (1 0) 1 __tconst5Fqn220) (join ref (1 0) 1 __tconst0ZcM213 __t6fYg206) (exists app (1 2 0) 1 __t6fYg206) (join ref (1 0) 1 __tconst5Fqn220 __t2V0C216) (exists app (1 2 0) 1 __t2V0C216) (join app (1 2 0) 1 __t6fYg206 dup86m7417 __t1W86209) (eq __t6fYg206 dup86m7417) (join app (1 2 0) 1 __t2V0C216 dup76Ti418 __t9nSF219) (eq __t2V0C216 dup76Ti418)) (head (mkstruct lambda (1 2 0) __t6h87221 __tconst5Fqn220 __t9nSF219) (mkstruct lambda (1 2 0) __t1wmd211 __tconst9TQS210 __t1W86209)) mcfa-counting.slog:211 #f)
  class ReadTask21 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** refindex13;  slog::Index** refindex14;  slog::Index** refindex15;  slog::Index** appindex16;  slog::Index** refindex17;  slog::Index** appindex18;  slog::Index** appindex19;  slog::Index** appindex20;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      head_rel[1] = db->getRelation("lambda");
      std::vector<u16> ord22({1, 2, 0});
      slog::Relation* readrel23 = db->getRelation("lambda");
      driver_index = readrel23->getIndex(ord22, true);
      std::vector<u16> ord24({0, 1});
      slog::Relation* readrel25 = db->getRelation("ref");
      refindex13 = readrel25->getIndex(ord24, false);
      std::vector<u16> ord26({1, 0});
      slog::Relation* readrel27 = db->getRelation("ref");
      refindex14 = readrel27->getIndex(ord26, false);
      std::vector<u16> ord28({1, 0});
      slog::Relation* readrel29 = db->getRelation("ref");
      refindex15 = readrel29->getIndex(ord28, false);
      std::vector<u16> ord30({1, 2, 0});
      slog::Relation* readrel31 = db->getRelation("app");
      appindex16 = readrel31->getIndex(ord30, false);
      std::vector<u16> ord32({1, 0});
      slog::Relation* readrel33 = db->getRelation("ref");
      refindex17 = readrel33->getIndex(ord32, false);
      std::vector<u16> ord34({1, 2, 0});
      slog::Relation* readrel35 = db->getRelation("app");
      appindex18 = readrel35->getIndex(ord34, false);
      std::vector<u16> ord36({1, 2, 0});
      slog::Relation* readrel37 = db->getRelation("app");
      appindex19 = readrel37->getIndex(ord36, false);
      std::vector<u16> ord38({1, 2, 0});
      slog::Relation* readrel39 = db->getRelation("app");
      appindex20 = readrel39->getIndex(ord38, false);
  
    }
    ReadTask21(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c4 = v_const15bb62b8293a526ca6f0e4eb;
      u64 v_c5 = v_constfc9ee54e0ee8c6d1e715716c;
      u64 v_c6 = v_const5950e3cb761734f52a881545;
      u64 v_c7 = v_const77ceb5c0e9f84ebd84104a97;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c7, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m40) {
        u64 v_c8 = m40[1];
        u64 v_c9 = m40[2];
        if (buckethash(v_c8) != bucket) return;
        slog::join_probe<2,2>(refindex13, std::array<u64,2>{v_c8, v_c7}, [&](const std::array<u64,2>& m41) {
          if (!slog::exists_probe<2,1>(refindex14, std::array<u64,2>{v_c4, 0})) return;
          slog::join_probe<2,1>(refindex15, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m42) {
            u64 v_c10 = m42[1];
            if (!slog::exists_probe<3,1>(appindex16, std::array<u64,3>{v_c10, 0, 0})) return;
            slog::join_probe<2,1>(refindex17, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m43) {
              u64 v_c11 = m43[1];
              if (!slog::exists_probe<3,1>(appindex18, std::array<u64,3>{v_c11, 0, 0})) return;
              slog::join_probe<3,1>(appindex19, std::array<u64,3>{v_c10, 0, 0}, [&](const std::array<u64,3>& m44) {
                u64 v_c12 = m44[1]; u64 v_c13 = m44[2];
                if (v_c10 != v_c12) return;
                slog::join_probe<3,1>(appindex20, std::array<u64,3>{v_c11, 0, 0}, [&](const std::array<u64,3>& m45) {
                  u64 v_c14 = m45[1]; u64 v_c15 = m45[2];
                  if (v_c11 != v_c14) return;
                  ++_fires;
                  slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c4, v_c15}, std::array<u16,3>{1, 2, 0});
                  slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c6, v_c13}, std::array<u16,3>{1, 2, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:211", "delta:lambda", _fires);
  
      if (!_done)
      {
        ReadTask21* _cont = new ReadTask21(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask21(db,b), false);
  // (crule (pre (let __tconst9zoW125 const7c7d2cfc66f4d976987d2d20) (let __tconst4V4L122 const6bc0ba365ada70df115e1785) (let __tconst4Zcr91 const9a67f28c6b77e842f439a84a) (let __tconst0vRf84 conste58dec6bca6f63ef79c3b755) (let __tconst82U8119 consta8180db1c2f300980314f910) (let __tconst4BKz104 const0f8748be649f8ee4066bb1d7) (let __tconst3wDH116 constd5f017533ea574d5f9b3400c) (let __tconst3ktF111 const990b444cbd47632035b2fa1a) (let __tconst5nWJ102 const4f84f41d89b6b717419b4eaa)) (probe lambda (1 2 0) 1 __tconst4V4L122 __t1GdP121 __t5iMg123) (body (exists lambda (1 2 0) 1 __tconst0vRf84) (exists ref (1 0) 1 __tconst4V4L122) (exists ref (1 0) 1 __tconst4Zcr91) (exists ref (1 0) 1 __tconst9zoW125) (exists lambda (1 2 0) 1 __tconst4Zcr91) (exists ref (1 0) 1 __tconst4BKz104) (exists lambda (1 2 0) 1 __tconst4BKz104) (exists lambda (1 2 0) 1 __tconst82U8119) (exists ref (1 0) 1 __tconst3wDH116) (exists ref (1 0) 1 __tconst5nWJ102) (exists lambda (1 2 0) 1 __tconst5nWJ102) (exists lambda (1 2 0) 1 __tconst3wDH116) (exists lambda (1 2 0) 1 __tconst3ktF111) (exists ref (1 0) 1 __tconst3ktF111) (join ref (1 0) 1 __tconst0vRf84 __t2duR83) (join lambda (1 2 0) 2 __tconst0vRf84 __t2duR83 __t87vL85) (join ref (1 0) 1 __tconst4V4L122 __t7aew98) (exists app (1 2 0) 1 __t7aew98) (join ref (1 0) 1 __tconst4Zcr91 __t0C9F87) (exists app (2 0 1) 1 __t0C9F87) (join ref (1 0) 1 __tconst9zoW125 __t3Q2G89) (join app (1 2 0) 2 __t3Q2G89 __t0C9F87 __t2Eqd90) (join lambda (1 2 0) 2 __tconst4Zcr91 __t2Eqd90 __t3pgm92) (join ref (1 0) 1 __tconst4BKz104 __t8C0a94) (join lambda (1 2 0) 2 __tconst4BKz104 __t8C0a94 __t4fDK96) (join app (1 2 0) 2 __t7aew98 __t4fDK96 __t7TEO99) (join app (2 0 1) 2 __t7TEO99 __t1GdP121 __t3SEs120) (join lambda (0 1 2) 2 __t3SEs120 __tconst82U8119 __t50Kk118) (join ref (1 0) 1 __tconst3wDH116 __t3wir114) (exists app (1 2 0) 1 __t3wir114) (join ref (1 0) 1 __tconst5nWJ102 __t5MaG101) (join lambda (1 2 0) 2 __tconst5nWJ102 __t5MaG101 __t35jA103) (join lambda (1 2 0) 2 __tconst4BKz104 __t35jA103 __t6RuY105) (join app (1 2 0) 2 __t7aew98 __t6RuY105 __t2Z7m108) (join app (2 0 1) 2 __t2Z7m108 __t50Kk118 __t7CwH117) (join lambda (0 1 2) 2 __t7CwH117 __tconst3wDH116 __t44OM115) (join app (0 1 2) 2 __t44OM115 __t3wir114 __t8GWA112) (join lambda (0 1 2) 2 __t8GWA112 __tconst3ktF111 __t7ohz110) (join ref (0 1) 2 __t7ohz110 __tconst3ktF111)) (head (mkstruct app (1 2 0) __t3cyj124 __t5iMg123 __t3pgm92)) mcfa-counting.slog:241 #f)
  class ReadTask85 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** lambdaindex46;  slog::Index** refindex47;  slog::Index** refindex48;  slog::Index** refindex49;  slog::Index** lambdaindex50;  slog::Index** refindex51;  slog::Index** lambdaindex52;  slog::Index** lambdaindex53;  slog::Index** refindex54;  slog::Index** refindex55;  slog::Index** lambdaindex56;  slog::Index** lambdaindex57;  slog::Index** lambdaindex58;  slog::Index** refindex59;  slog::Index** refindex60;  slog::Index** lambdaindex61;  slog::Index** refindex62;  slog::Index** appindex63;  slog::Index** refindex64;  slog::Index** appindex65;  slog::Index** refindex66;  slog::Index** appindex67;  slog::Index** lambdaindex68;  slog::Index** refindex69;  slog::Index** lambdaindex70;  slog::Index** appindex71;  slog::Index** appindex72;  slog::Index** lambdaindex73;  slog::Index** refindex74;  slog::Index** appindex75;  slog::Index** refindex76;  slog::Index** lambdaindex77;  slog::Index** lambdaindex78;  slog::Index** appindex79;  slog::Index** appindex80;  slog::Index** lambdaindex81;  slog::Index** appindex82;  slog::Index** lambdaindex83;  slog::Index** refindex84;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord86({1, 2, 0});
      slog::Relation* readrel87 = db->getRelation("lambda");
      driver_index = readrel87->getIndex(ord86, true);
      std::vector<u16> ord88({1, 2, 0});
      slog::Relation* readrel89 = db->getRelation("lambda");
      lambdaindex46 = readrel89->getIndex(ord88, false);
      std::vector<u16> ord90({1, 0});
      slog::Relation* readrel91 = db->getRelation("ref");
      refindex47 = readrel91->getIndex(ord90, false);
      std::vector<u16> ord92({1, 0});
      slog::Relation* readrel93 = db->getRelation("ref");
      refindex48 = readrel93->getIndex(ord92, false);
      std::vector<u16> ord94({1, 0});
      slog::Relation* readrel95 = db->getRelation("ref");
      refindex49 = readrel95->getIndex(ord94, false);
      std::vector<u16> ord96({1, 2, 0});
      slog::Relation* readrel97 = db->getRelation("lambda");
      lambdaindex50 = readrel97->getIndex(ord96, false);
      std::vector<u16> ord98({1, 0});
      slog::Relation* readrel99 = db->getRelation("ref");
      refindex51 = readrel99->getIndex(ord98, false);
      std::vector<u16> ord100({1, 2, 0});
      slog::Relation* readrel101 = db->getRelation("lambda");
      lambdaindex52 = readrel101->getIndex(ord100, false);
      std::vector<u16> ord102({1, 2, 0});
      slog::Relation* readrel103 = db->getRelation("lambda");
      lambdaindex53 = readrel103->getIndex(ord102, false);
      std::vector<u16> ord104({1, 0});
      slog::Relation* readrel105 = db->getRelation("ref");
      refindex54 = readrel105->getIndex(ord104, false);
      std::vector<u16> ord106({1, 0});
      slog::Relation* readrel107 = db->getRelation("ref");
      refindex55 = readrel107->getIndex(ord106, false);
      std::vector<u16> ord108({1, 2, 0});
      slog::Relation* readrel109 = db->getRelation("lambda");
      lambdaindex56 = readrel109->getIndex(ord108, false);
      std::vector<u16> ord110({1, 2, 0});
      slog::Relation* readrel111 = db->getRelation("lambda");
      lambdaindex57 = readrel111->getIndex(ord110, false);
      std::vector<u16> ord112({1, 2, 0});
      slog::Relation* readrel113 = db->getRelation("lambda");
      lambdaindex58 = readrel113->getIndex(ord112, false);
      std::vector<u16> ord114({1, 0});
      slog::Relation* readrel115 = db->getRelation("ref");
      refindex59 = readrel115->getIndex(ord114, false);
      std::vector<u16> ord116({1, 0});
      slog::Relation* readrel117 = db->getRelation("ref");
      refindex60 = readrel117->getIndex(ord116, false);
      std::vector<u16> ord118({1, 2, 0});
      slog::Relation* readrel119 = db->getRelation("lambda");
      lambdaindex61 = readrel119->getIndex(ord118, false);
      std::vector<u16> ord120({1, 0});
      slog::Relation* readrel121 = db->getRelation("ref");
      refindex62 = readrel121->getIndex(ord120, false);
      std::vector<u16> ord122({1, 2, 0});
      slog::Relation* readrel123 = db->getRelation("app");
      appindex63 = readrel123->getIndex(ord122, false);
      std::vector<u16> ord124({1, 0});
      slog::Relation* readrel125 = db->getRelation("ref");
      refindex64 = readrel125->getIndex(ord124, false);
      std::vector<u16> ord126({2, 0, 1});
      slog::Relation* readrel127 = db->getRelation("app");
      appindex65 = readrel127->getIndex(ord126, false);
      std::vector<u16> ord128({1, 0});
      slog::Relation* readrel129 = db->getRelation("ref");
      refindex66 = readrel129->getIndex(ord128, false);
      std::vector<u16> ord130({1, 2, 0});
      slog::Relation* readrel131 = db->getRelation("app");
      appindex67 = readrel131->getIndex(ord130, false);
      std::vector<u16> ord132({1, 2, 0});
      slog::Relation* readrel133 = db->getRelation("lambda");
      lambdaindex68 = readrel133->getIndex(ord132, false);
      std::vector<u16> ord134({1, 0});
      slog::Relation* readrel135 = db->getRelation("ref");
      refindex69 = readrel135->getIndex(ord134, false);
      std::vector<u16> ord136({1, 2, 0});
      slog::Relation* readrel137 = db->getRelation("lambda");
      lambdaindex70 = readrel137->getIndex(ord136, false);
      std::vector<u16> ord138({1, 2, 0});
      slog::Relation* readrel139 = db->getRelation("app");
      appindex71 = readrel139->getIndex(ord138, false);
      std::vector<u16> ord140({2, 0, 1});
      slog::Relation* readrel141 = db->getRelation("app");
      appindex72 = readrel141->getIndex(ord140, false);
      std::vector<u16> ord142({0, 1, 2});
      slog::Relation* readrel143 = db->getRelation("lambda");
      lambdaindex73 = readrel143->getIndex(ord142, false);
      std::vector<u16> ord144({1, 0});
      slog::Relation* readrel145 = db->getRelation("ref");
      refindex74 = readrel145->getIndex(ord144, false);
      std::vector<u16> ord146({1, 2, 0});
      slog::Relation* readrel147 = db->getRelation("app");
      appindex75 = readrel147->getIndex(ord146, false);
      std::vector<u16> ord148({1, 0});
      slog::Relation* readrel149 = db->getRelation("ref");
      refindex76 = readrel149->getIndex(ord148, false);
      std::vector<u16> ord150({1, 2, 0});
      slog::Relation* readrel151 = db->getRelation("lambda");
      lambdaindex77 = readrel151->getIndex(ord150, false);
      std::vector<u16> ord152({1, 2, 0});
      slog::Relation* readrel153 = db->getRelation("lambda");
      lambdaindex78 = readrel153->getIndex(ord152, false);
      std::vector<u16> ord154({1, 2, 0});
      slog::Relation* readrel155 = db->getRelation("app");
      appindex79 = readrel155->getIndex(ord154, false);
      std::vector<u16> ord156({2, 0, 1});
      slog::Relation* readrel157 = db->getRelation("app");
      appindex80 = readrel157->getIndex(ord156, false);
      std::vector<u16> ord158({0, 1, 2});
      slog::Relation* readrel159 = db->getRelation("lambda");
      lambdaindex81 = readrel159->getIndex(ord158, false);
      std::vector<u16> ord160({0, 1, 2});
      slog::Relation* readrel161 = db->getRelation("app");
      appindex82 = readrel161->getIndex(ord160, false);
      std::vector<u16> ord162({0, 1, 2});
      slog::Relation* readrel163 = db->getRelation("lambda");
      lambdaindex83 = readrel163->getIndex(ord162, false);
      std::vector<u16> ord164({0, 1});
      slog::Relation* readrel165 = db->getRelation("ref");
      refindex84 = readrel165->getIndex(ord164, false);
  
    }
    ReadTask85(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c16 = v_const7c7d2cfc66f4d976987d2d20;
      u64 v_c17 = v_const6bc0ba365ada70df115e1785;
      u64 v_c18 = v_const9a67f28c6b77e842f439a84a;
      u64 v_c19 = v_conste58dec6bca6f63ef79c3b755;
      u64 v_c20 = v_consta8180db1c2f300980314f910;
      u64 v_c21 = v_const0f8748be649f8ee4066bb1d7;
      u64 v_c22 = v_constd5f017533ea574d5f9b3400c;
      u64 v_c23 = v_const990b444cbd47632035b2fa1a;
      u64 v_c24 = v_const4f84f41d89b6b717419b4eaa;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c17, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m166) {
        u64 v_c25 = m166[1];
        u64 v_c26 = m166[2];
        if (buckethash(v_c25) != bucket) return;
        if (!slog::exists_probe<3,1>(lambdaindex46, std::array<u64,3>{v_c19, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex47, std::array<u64,2>{v_c17, 0})) return;
        if (!slog::exists_probe<2,1>(refindex48, std::array<u64,2>{v_c18, 0})) return;
        if (!slog::exists_probe<2,1>(refindex49, std::array<u64,2>{v_c16, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex50, std::array<u64,3>{v_c18, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex51, std::array<u64,2>{v_c21, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex52, std::array<u64,3>{v_c21, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex53, std::array<u64,3>{v_c20, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex54, std::array<u64,2>{v_c22, 0})) return;
        if (!slog::exists_probe<2,1>(refindex55, std::array<u64,2>{v_c24, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex56, std::array<u64,3>{v_c24, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex57, std::array<u64,3>{v_c22, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex58, std::array<u64,3>{v_c23, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex59, std::array<u64,2>{v_c23, 0})) return;
        slog::join_probe<2,1>(refindex60, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m167) {
          u64 v_c27 = m167[1];
          slog::join_probe<3,2>(lambdaindex61, std::array<u64,3>{v_c19, v_c27, 0}, [&](const std::array<u64,3>& m168) {
            u64 v_c28 = m168[2];
            slog::join_probe<2,1>(refindex62, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m169) {
              u64 v_c29 = m169[1];
              if (!slog::exists_probe<3,1>(appindex63, std::array<u64,3>{v_c29, 0, 0})) return;
              slog::join_probe<2,1>(refindex64, std::array<u64,2>{v_c18, 0}, [&](const std::array<u64,2>& m170) {
                u64 v_c30 = m170[1];
                if (!slog::exists_probe<3,1>(appindex65, std::array<u64,3>{v_c30, 0, 0})) return;
                slog::join_probe<2,1>(refindex66, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m171) {
                  u64 v_c31 = m171[1];
                  slog::join_probe<3,2>(appindex67, std::array<u64,3>{v_c31, v_c30, 0}, [&](const std::array<u64,3>& m172) {
                    u64 v_c32 = m172[2];
                    slog::join_probe<3,2>(lambdaindex68, std::array<u64,3>{v_c18, v_c32, 0}, [&](const std::array<u64,3>& m173) {
                      u64 v_c33 = m173[2];
                      slog::join_probe<2,1>(refindex69, std::array<u64,2>{v_c21, 0}, [&](const std::array<u64,2>& m174) {
                        u64 v_c34 = m174[1];
                        slog::join_probe<3,2>(lambdaindex70, std::array<u64,3>{v_c21, v_c34, 0}, [&](const std::array<u64,3>& m175) {
                          u64 v_c35 = m175[2];
                          slog::join_probe<3,2>(appindex71, std::array<u64,3>{v_c29, v_c35, 0}, [&](const std::array<u64,3>& m176) {
                            u64 v_c36 = m176[2];
                            slog::join_probe<3,2>(appindex72, std::array<u64,3>{v_c36, v_c25, 0}, [&](const std::array<u64,3>& m177) {
                              u64 v_c37 = m177[2];
                              slog::join_probe<3,2>(lambdaindex73, std::array<u64,3>{v_c37, v_c20, 0}, [&](const std::array<u64,3>& m178) {
                                u64 v_c38 = m178[2];
                                slog::join_probe<2,1>(refindex74, std::array<u64,2>{v_c22, 0}, [&](const std::array<u64,2>& m179) {
                                  u64 v_c39 = m179[1];
                                  if (!slog::exists_probe<3,1>(appindex75, std::array<u64,3>{v_c39, 0, 0})) return;
                                  slog::join_probe<2,1>(refindex76, std::array<u64,2>{v_c24, 0}, [&](const std::array<u64,2>& m180) {
                                    u64 v_c40 = m180[1];
                                    slog::join_probe<3,2>(lambdaindex77, std::array<u64,3>{v_c24, v_c40, 0}, [&](const std::array<u64,3>& m181) {
                                      u64 v_c41 = m181[2];
                                      slog::join_probe<3,2>(lambdaindex78, std::array<u64,3>{v_c21, v_c41, 0}, [&](const std::array<u64,3>& m182) {
                                        u64 v_c42 = m182[2];
                                        slog::join_probe<3,2>(appindex79, std::array<u64,3>{v_c29, v_c42, 0}, [&](const std::array<u64,3>& m183) {
                                          u64 v_c43 = m183[2];
                                          slog::join_probe<3,2>(appindex80, std::array<u64,3>{v_c43, v_c38, 0}, [&](const std::array<u64,3>& m184) {
                                            u64 v_c44 = m184[2];
                                            slog::join_probe<3,2>(lambdaindex81, std::array<u64,3>{v_c44, v_c22, 0}, [&](const std::array<u64,3>& m185) {
                                              u64 v_c45 = m185[2];
                                              slog::join_probe<3,2>(appindex82, std::array<u64,3>{v_c45, v_c39, 0}, [&](const std::array<u64,3>& m186) {
                                                u64 v_c46 = m186[2];
                                                slog::join_probe<3,2>(lambdaindex83, std::array<u64,3>{v_c46, v_c23, 0}, [&](const std::array<u64,3>& m187) {
                                                  u64 v_c47 = m187[2];
                                                  slog::join_probe<2,2>(refindex84, std::array<u64,2>{v_c47, v_c23}, [&](const std::array<u64,2>& m188) {
                                                    ++_fires;
                                                    slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c26, v_c33}, std::array<u16,3>{1, 2, 0});
                                                  });
                                                });
                                              });
                                            });
                                          });
                                        });
                                      });
                                    });
                                  });
                                });
                              });
                            });
                          });
                        });
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
        ReadTask85* _cont = new ReadTask85(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask85(db,b), false);
  // (crule (pre (let __tconst0y6X73 const0aa6f87434af0222b916e97a) (let __tconst7zoP70 const227d34ceeba7a29aada993d4) (let __tconst0aL952 constd3d07026d47882ceca728218) (let __tconst1bfe65 const59ba3256d223f0d0a00d0633) (let __tconst8wN863 const7cd75b35aa30c3ddf04f9d57) (let __tconst0xUh47 constf700a82e218a86de572e1f7f)) (seeded) (body (join ref (1 0) 1 __tconst0y6X73 __t0QRr59) (exists ref (1 0) 1 __tconst0xUh47) (exists lambda (1 2 0) 1 __tconst0xUh47) (exists lambda (1 2 0) 1 __tconst0aL952) (exists ref (1 0) 1 __tconst1bfe65) (exists lambda (1 2 0) 1 __tconst1bfe65) (exists app (1 2 0) 1 __t0QRr59) (exists ref (1 0) 1 __tconst8wN863) (exists lambda (1 2 0) 1 __tconst8wN863) (join ref (1 0) 1 __tconst0aL952 __t5HQ450) (exists app (1 2 0) 1 __t5HQ450) (join ref (1 0) 1 __tconst0xUh47 __t5vZb46) (join lambda (1 2 0) 2 __tconst0xUh47 __t5vZb46 __t50zW48) (join app (1 2 0) 2 __t5HQ450 __t50zW48 __t05NY51) (join lambda (1 2 0) 2 __tconst0aL952 __t05NY51 __t3xtz53) (join ref (1 0) 1 __tconst1bfe65 __t2HsD55) (join lambda (1 2 0) 2 __tconst1bfe65 __t2HsD55 __t0uNb57) (join app (1 2 0) 2 __t0QRr59 __t0uNb57 __t81HE60) (join ref (1 0) 1 __tconst8wN863 __t1mkO62) (join lambda (1 2 0) 2 __tconst8wN863 __t1mkO62 __t3Dru64) (join lambda (1 2 0) 2 __tconst1bfe65 __t3Dru64 __t7JIT66) (join app (1 2 0) 2 __t0QRr59 __t7JIT66 __t5Ri569)) (head (mkstruct lambda (1 2 0) __t7KAC71 __tconst7zoP70 __t5Ri569)) mcfa-counting.slog:287 #f)
  class ReadTask211 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex189;  slog::Index** refindex190;  slog::Index** lambdaindex191;  slog::Index** lambdaindex192;  slog::Index** refindex193;  slog::Index** lambdaindex194;  slog::Index** appindex195;  slog::Index** refindex196;  slog::Index** lambdaindex197;  slog::Index** refindex198;  slog::Index** appindex199;  slog::Index** refindex200;  slog::Index** lambdaindex201;  slog::Index** appindex202;  slog::Index** lambdaindex203;  slog::Index** refindex204;  slog::Index** lambdaindex205;  slog::Index** appindex206;  slog::Index** refindex207;  slog::Index** lambdaindex208;  slog::Index** lambdaindex209;  slog::Index** appindex210;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      std::vector<u16> ord212({1, 2, 0});
      slog::Relation* readrel213 = db->getRelation("lambda");
      head_index[0] = readrel213->getIndex(ord212, false);
      std::vector<u16> ord214({1, 0});
      slog::Relation* readrel215 = db->getRelation("ref");
      refindex189 = readrel215->getIndex(ord214, false);
      std::vector<u16> ord216({1, 0});
      slog::Relation* readrel217 = db->getRelation("ref");
      refindex190 = readrel217->getIndex(ord216, false);
      std::vector<u16> ord218({1, 2, 0});
      slog::Relation* readrel219 = db->getRelation("lambda");
      lambdaindex191 = readrel219->getIndex(ord218, false);
      std::vector<u16> ord220({1, 2, 0});
      slog::Relation* readrel221 = db->getRelation("lambda");
      lambdaindex192 = readrel221->getIndex(ord220, false);
      std::vector<u16> ord222({1, 0});
      slog::Relation* readrel223 = db->getRelation("ref");
      refindex193 = readrel223->getIndex(ord222, false);
      std::vector<u16> ord224({1, 2, 0});
      slog::Relation* readrel225 = db->getRelation("lambda");
      lambdaindex194 = readrel225->getIndex(ord224, false);
      std::vector<u16> ord226({1, 2, 0});
      slog::Relation* readrel227 = db->getRelation("app");
      appindex195 = readrel227->getIndex(ord226, false);
      std::vector<u16> ord228({1, 0});
      slog::Relation* readrel229 = db->getRelation("ref");
      refindex196 = readrel229->getIndex(ord228, false);
      std::vector<u16> ord230({1, 2, 0});
      slog::Relation* readrel231 = db->getRelation("lambda");
      lambdaindex197 = readrel231->getIndex(ord230, false);
      std::vector<u16> ord232({1, 0});
      slog::Relation* readrel233 = db->getRelation("ref");
      refindex198 = readrel233->getIndex(ord232, false);
      std::vector<u16> ord234({1, 2, 0});
      slog::Relation* readrel235 = db->getRelation("app");
      appindex199 = readrel235->getIndex(ord234, false);
      std::vector<u16> ord236({1, 0});
      slog::Relation* readrel237 = db->getRelation("ref");
      refindex200 = readrel237->getIndex(ord236, false);
      std::vector<u16> ord238({1, 2, 0});
      slog::Relation* readrel239 = db->getRelation("lambda");
      lambdaindex201 = readrel239->getIndex(ord238, false);
      std::vector<u16> ord240({1, 2, 0});
      slog::Relation* readrel241 = db->getRelation("app");
      appindex202 = readrel241->getIndex(ord240, false);
      std::vector<u16> ord242({1, 2, 0});
      slog::Relation* readrel243 = db->getRelation("lambda");
      lambdaindex203 = readrel243->getIndex(ord242, false);
      std::vector<u16> ord244({1, 0});
      slog::Relation* readrel245 = db->getRelation("ref");
      refindex204 = readrel245->getIndex(ord244, false);
      std::vector<u16> ord246({1, 2, 0});
      slog::Relation* readrel247 = db->getRelation("lambda");
      lambdaindex205 = readrel247->getIndex(ord246, false);
      std::vector<u16> ord248({1, 2, 0});
      slog::Relation* readrel249 = db->getRelation("app");
      appindex206 = readrel249->getIndex(ord248, false);
      std::vector<u16> ord250({1, 0});
      slog::Relation* readrel251 = db->getRelation("ref");
      refindex207 = readrel251->getIndex(ord250, false);
      std::vector<u16> ord252({1, 2, 0});
      slog::Relation* readrel253 = db->getRelation("lambda");
      lambdaindex208 = readrel253->getIndex(ord252, false);
      std::vector<u16> ord254({1, 2, 0});
      slog::Relation* readrel255 = db->getRelation("lambda");
      lambdaindex209 = readrel255->getIndex(ord254, false);
      std::vector<u16> ord256({1, 2, 0});
      slog::Relation* readrel257 = db->getRelation("app");
      appindex210 = readrel257->getIndex(ord256, false);
  
    }
    ReadTask211(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c48 = v_const0aa6f87434af0222b916e97a;
      u64 v_c49 = v_const227d34ceeba7a29aada993d4;
      u64 v_c50 = v_constd3d07026d47882ceca728218;
      u64 v_c51 = v_const59ba3256d223f0d0a00d0633;
      u64 v_c52 = v_const7cd75b35aa30c3ddf04f9d57;
      u64 v_c53 = v_constf700a82e218a86de572e1f7f;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex189, std::array<u64,2>{v_c48, 0}, [&](const std::array<u64,2>& m258) {
        u64 v_c54 = m258[1];
        if (!slog::exists_probe<2,1>(refindex190, std::array<u64,2>{v_c53, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex191, std::array<u64,3>{v_c53, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex192, std::array<u64,3>{v_c50, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex193, std::array<u64,2>{v_c51, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex194, std::array<u64,3>{v_c51, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex195, std::array<u64,3>{v_c54, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex196, std::array<u64,2>{v_c52, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex197, std::array<u64,3>{v_c52, 0, 0})) return;
        slog::join_probe<2,1>(refindex198, std::array<u64,2>{v_c50, 0}, [&](const std::array<u64,2>& m259) {
          u64 v_c55 = m259[1];
          if (!slog::exists_probe<3,1>(appindex199, std::array<u64,3>{v_c55, 0, 0})) return;
          slog::join_probe<2,1>(refindex200, std::array<u64,2>{v_c53, 0}, [&](const std::array<u64,2>& m260) {
            u64 v_c56 = m260[1];
            slog::join_probe<3,2>(lambdaindex201, std::array<u64,3>{v_c53, v_c56, 0}, [&](const std::array<u64,3>& m261) {
              u64 v_c57 = m261[2];
              slog::join_probe<3,2>(appindex202, std::array<u64,3>{v_c55, v_c57, 0}, [&](const std::array<u64,3>& m262) {
                u64 v_c58 = m262[2];
                slog::join_probe<3,2>(lambdaindex203, std::array<u64,3>{v_c50, v_c58, 0}, [&](const std::array<u64,3>& m263) {
                  u64 v_c59 = m263[2];
                  slog::join_probe<2,1>(refindex204, std::array<u64,2>{v_c51, 0}, [&](const std::array<u64,2>& m264) {
                    u64 v_c60 = m264[1];
                    slog::join_probe<3,2>(lambdaindex205, std::array<u64,3>{v_c51, v_c60, 0}, [&](const std::array<u64,3>& m265) {
                      u64 v_c61 = m265[2];
                      slog::join_probe<3,2>(appindex206, std::array<u64,3>{v_c54, v_c61, 0}, [&](const std::array<u64,3>& m266) {
                        u64 v_c62 = m266[2];
                        slog::join_probe<2,1>(refindex207, std::array<u64,2>{v_c52, 0}, [&](const std::array<u64,2>& m267) {
                          u64 v_c63 = m267[1];
                          slog::join_probe<3,2>(lambdaindex208, std::array<u64,3>{v_c52, v_c63, 0}, [&](const std::array<u64,3>& m268) {
                            u64 v_c64 = m268[2];
                            slog::join_probe<3,2>(lambdaindex209, std::array<u64,3>{v_c51, v_c64, 0}, [&](const std::array<u64,3>& m269) {
                              u64 v_c65 = m269[2];
                              slog::join_probe<3,2>(appindex210, std::array<u64,3>{v_c54, v_c65, 0}, [&](const std::array<u64,3>& m270) {
                                u64 v_c66 = m270[2];
                                ++_fires;
                                slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c49, v_c66}, std::array<u16,3>{1, 2, 0});
                              });
                            });
                          });
                        });
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
      s->addTaskSeeded(phase_read, new ReadTask211(db,b));
  // (crule (pre) (scan app __t5SBy169 ef ea) (body (exists eval (1 2 0) 1 ef) (exists eval (1 2 0) 1 ea) (join eval (1 2 0) 1 __t5SBy169 c __6tlE337) (exists eval (1 2 0) 2 ea c) (join-old eval (1 2 0) 2 (1 2 0) ef c __t6CRg170) (exists eval_ans (0 1) 1 __t6CRg170) (join-old eval (1 2 0) 2 (1 2 0) ea c __t1JPZ173) (exists eval_ans (0 1) 1 __t1JPZ173) (join eval_ans (0 1) 1 __t6CRg170 __t2Hqj172) (join eval_ans (0 1) 1 __t1JPZ173 va) (join-old clo (0 2 1) 1 (0 2 1) __t2Hqj172 cb __t0RD6171) (join-old lambda (0 1 2) 1 (0 1 2) __t0RD6171 x eb)) (head (emit store (0 1 2) x __t5SBy169 va) (emit callev (0 1) __t5SBy169 c) (emit bindev (0 1 2) x __t5SBy169 c)) mcfa-counting.slog:92 #f)
  class ReadTask287 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex271;  slog::Index** evalindex272;  slog::Index** evalindex273;  slog::Index** evalindex274;  slog::Index** evalindex275;  slog::Index** eval_ansindex276;  slog::Index** evalindex277;  slog::Index** eval_ansindex278;  slog::Index** eval_ansindex279;  slog::Index** eval_ansindex280;  slog::Index** cloindex281;  slog::Index** lambdaindex282;  slog::Index** evaldelta283;  slog::Index** evaldelta284;  slog::Index** clodelta285;  slog::Index** lambdadelta286;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("store");
      std::vector<u16> ord288({0, 1, 2});
      slog::Relation* readrel289 = db->getRelation("store");
      head_index[0] = readrel289->getIndex(ord288, false);
      head_rel[1] = db->getRelation("callev");
      std::vector<u16> ord290({0, 1});
      slog::Relation* readrel291 = db->getRelation("callev");
      head_index[1] = readrel291->getIndex(ord290, false);
      head_rel[2] = db->getRelation("bindev");
      std::vector<u16> ord292({0, 1, 2});
      slog::Relation* readrel293 = db->getRelation("bindev");
      head_index[2] = readrel293->getIndex(ord292, false);
      outer_rel = db->getRelation("app");
      std::vector<u16> ord294({1, 2, 0});
      slog::Relation* readrel295 = db->getRelation("eval");
      evalindex271 = readrel295->getIndex(ord294, false);
      std::vector<u16> ord296({1, 2, 0});
      slog::Relation* readrel297 = db->getRelation("eval");
      evalindex272 = readrel297->getIndex(ord296, false);
      std::vector<u16> ord298({1, 2, 0});
      slog::Relation* readrel299 = db->getRelation("eval");
      evalindex273 = readrel299->getIndex(ord298, false);
      std::vector<u16> ord300({1, 2, 0});
      slog::Relation* readrel301 = db->getRelation("eval");
      evalindex274 = readrel301->getIndex(ord300, false);
      std::vector<u16> ord302({1, 2, 0});
      slog::Relation* readrel303 = db->getRelation("eval");
      evalindex275 = readrel303->getIndex(ord302, false);
      std::vector<u16> ord304({1, 2, 0});
      slog::Relation* readrel305 = db->getRelation("eval");
      evaldelta283 = readrel305->getIndex(ord304, true);
      std::vector<u16> ord306({0, 1});
      slog::Relation* readrel307 = db->getRelation("eval_ans");
      eval_ansindex276 = readrel307->getIndex(ord306, false);
      std::vector<u16> ord308({1, 2, 0});
      slog::Relation* readrel309 = db->getRelation("eval");
      evalindex277 = readrel309->getIndex(ord308, false);
      std::vector<u16> ord310({1, 2, 0});
      slog::Relation* readrel311 = db->getRelation("eval");
      evaldelta284 = readrel311->getIndex(ord310, true);
      std::vector<u16> ord312({0, 1});
      slog::Relation* readrel313 = db->getRelation("eval_ans");
      eval_ansindex278 = readrel313->getIndex(ord312, false);
      std::vector<u16> ord314({0, 1});
      slog::Relation* readrel315 = db->getRelation("eval_ans");
      eval_ansindex279 = readrel315->getIndex(ord314, false);
      std::vector<u16> ord316({0, 1});
      slog::Relation* readrel317 = db->getRelation("eval_ans");
      eval_ansindex280 = readrel317->getIndex(ord316, false);
      std::vector<u16> ord318({0, 2, 1});
      slog::Relation* readrel319 = db->getRelation("clo");
      cloindex281 = readrel319->getIndex(ord318, false);
      std::vector<u16> ord320({0, 2, 1});
      slog::Relation* readrel321 = db->getRelation("clo");
      clodelta285 = readrel321->getIndex(ord320, true);
      std::vector<u16> ord322({0, 1, 2});
      slog::Relation* readrel323 = db->getRelation("lambda");
      lambdaindex282 = readrel323->getIndex(ord322, false);
      std::vector<u16> ord324({0, 1, 2});
      slog::Relation* readrel325 = db->getRelation("lambda");
      lambdadelta286 = readrel325->getIndex(ord324, true);
  
    }
    ReadTask287(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c67 = _t[0];
        u64 v_c68 = _t[1];
        u64 v_c69 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex271, std::array<u64,3>{v_c68, 0, 0})) return;
        if (!slog::exists_probe<3,1>(evalindex272, std::array<u64,3>{v_c69, 0, 0})) return;
        slog::join_probe<3,1>(evalindex273, std::array<u64,3>{v_c67, 0, 0}, [&](const std::array<u64,3>& m326) {
          u64 v_c70 = m326[1]; u64 v_c71 = m326[2];
          if (!slog::exists_probe<3,2>(evalindex274, std::array<u64,3>{v_c69, v_c70, 0})) return;
          slog::join_probe_old<3,2>(evalindex275, evaldelta283, std::array<u64,3>{v_c68, v_c70, 0}, [&](const std::array<u64,3>& m327) {
            u64 v_c72 = m327[2];
            if (!slog::exists_probe<2,1>(eval_ansindex276, std::array<u64,2>{v_c72, 0})) return;
            slog::join_probe_old<3,2>(evalindex277, evaldelta284, std::array<u64,3>{v_c69, v_c70, 0}, [&](const std::array<u64,3>& m328) {
              u64 v_c73 = m328[2];
              if (!slog::exists_probe<2,1>(eval_ansindex278, std::array<u64,2>{v_c73, 0})) return;
              slog::join_probe<2,1>(eval_ansindex279, std::array<u64,2>{v_c72, 0}, [&](const std::array<u64,2>& m329) {
                u64 v_c74 = m329[1];
                slog::join_probe<2,1>(eval_ansindex280, std::array<u64,2>{v_c73, 0}, [&](const std::array<u64,2>& m330) {
                  u64 v_c75 = m330[1];
                  slog::join_probe_old<3,1>(cloindex281, clodelta285, std::array<u64,3>{v_c74, 0, 0}, [&](const std::array<u64,3>& m331) {
                    u64 v_c76 = m331[1]; u64 v_c77 = m331[2];
                    slog::join_probe_old<3,1>(lambdaindex282, lambdadelta286, std::array<u64,3>{v_c77, 0, 0}, [&](const std::array<u64,3>& m332) {
                      u64 v_c78 = m332[1]; u64 v_c79 = m332[2];
                      ++_fires;
                      slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c78, v_c67, v_c75}, std::array<u16,3>{0, 1, 2});
                      slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c67, v_c70}, std::array<u16,2>{0, 1});
                      slog::emit<3>(head_rel[2], head_index[2], newbatch[2], std::array<u64,3>{v_c78, v_c67, v_c70}, std::array<u16,3>{0, 1, 2});
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
  
      if (_fires) db->bumpFires("mcfa-counting.slog:92", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask287* _cont = new ReadTask287(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask287(db,b), false);
  // (crule (pre (let __tconst1pJW313 constb49bea2fcccd8f4301a347ed) (let __tconst7LWP310 const66518c0c1b3a5a0b09ae2ef1) (let __tconst0sqO307 const4a8acfc71441e0695ffcf5b3) (let __tconst5PoN291 constc85eae03730a4f4cf1d66a0c) (let __tconst2Yzp284 const8ca682693a0738a0641c6956) (let __tconst2CSv302 const229c0b7aa8a7eb4055f5a3d0) (let __tconst9rZO295 const576506f61f53440f1edd95d2)) (probe lambda (1 2 0) 1 __tconst0sqO307 __t4HUX306 __t0vn1308) (body (exists lambda (1 2 0) 1 __tconst2CSv302) (exists ref (1 0) 1 __tconst2CSv302) (exists ref (1 0) 1 __tconst2Yzp284) (exists lambda (1 2 0) 1 __tconst2Yzp284) (exists ref (1 0) 1 __tconst1pJW313) (exists ref (1 0) 1 __tconst9rZO295) (exists lambda (1 2 0) 1 __tconst9rZO295) (exists lambda (1 2 0) 1 __tconst5PoN291) (join ref (1 0) 1 __tconst7LWP310 __t91H2298) (exists app (1 2 0) 1 __t91H2298) (join app (0 1 2) 2 __t4HUX306 __t91H2298 __t7EW2303) (join lambda (0 1 2) 2 __t7EW2303 __tconst2CSv302 __t6lXa301) (join ref (0 1) 2 __t6lXa301 __tconst2CSv302) (join ref (1 0) 1 __tconst2Yzp284 __t248W283) (join lambda (1 2 0) 2 __tconst2Yzp284 __t248W283 __t0oFu285) (join ref (1 0) 1 __tconst1pJW313 __t165O287) (exists app (1 2 0) 1 __t165O287) (join ref (1 0) 1 __tconst9rZO295 __t71w7294) (join lambda (1 2 0) 2 __tconst9rZO295 __t71w7294 __t3dkk296) (join app (1 2 0) 2 __t91H2298 __t3dkk296 __t4LtH299) (join app (1 2 0) 1 __t165O287 dup68Nj379 __t30Ec290) (eq __t165O287 dup68Nj379) (join lambda (1 2 0) 2 __tconst5PoN291 __t30Ec290 __t7aCZ292)) (head (mkstruct app (1 2 0) __t6t9L309 __t0vn1308 __t4LtH299)) mcfa-counting.slog:194 #f)
  class ReadTask355 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** lambdaindex333;  slog::Index** refindex334;  slog::Index** refindex335;  slog::Index** lambdaindex336;  slog::Index** refindex337;  slog::Index** refindex338;  slog::Index** lambdaindex339;  slog::Index** lambdaindex340;  slog::Index** refindex341;  slog::Index** appindex342;  slog::Index** appindex343;  slog::Index** lambdaindex344;  slog::Index** refindex345;  slog::Index** refindex346;  slog::Index** lambdaindex347;  slog::Index** refindex348;  slog::Index** appindex349;  slog::Index** refindex350;  slog::Index** lambdaindex351;  slog::Index** appindex352;  slog::Index** appindex353;  slog::Index** lambdaindex354;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord356({1, 2, 0});
      slog::Relation* readrel357 = db->getRelation("lambda");
      driver_index = readrel357->getIndex(ord356, true);
      std::vector<u16> ord358({1, 2, 0});
      slog::Relation* readrel359 = db->getRelation("lambda");
      lambdaindex333 = readrel359->getIndex(ord358, false);
      std::vector<u16> ord360({1, 0});
      slog::Relation* readrel361 = db->getRelation("ref");
      refindex334 = readrel361->getIndex(ord360, false);
      std::vector<u16> ord362({1, 0});
      slog::Relation* readrel363 = db->getRelation("ref");
      refindex335 = readrel363->getIndex(ord362, false);
      std::vector<u16> ord364({1, 2, 0});
      slog::Relation* readrel365 = db->getRelation("lambda");
      lambdaindex336 = readrel365->getIndex(ord364, false);
      std::vector<u16> ord366({1, 0});
      slog::Relation* readrel367 = db->getRelation("ref");
      refindex337 = readrel367->getIndex(ord366, false);
      std::vector<u16> ord368({1, 0});
      slog::Relation* readrel369 = db->getRelation("ref");
      refindex338 = readrel369->getIndex(ord368, false);
      std::vector<u16> ord370({1, 2, 0});
      slog::Relation* readrel371 = db->getRelation("lambda");
      lambdaindex339 = readrel371->getIndex(ord370, false);
      std::vector<u16> ord372({1, 2, 0});
      slog::Relation* readrel373 = db->getRelation("lambda");
      lambdaindex340 = readrel373->getIndex(ord372, false);
      std::vector<u16> ord374({1, 0});
      slog::Relation* readrel375 = db->getRelation("ref");
      refindex341 = readrel375->getIndex(ord374, false);
      std::vector<u16> ord376({1, 2, 0});
      slog::Relation* readrel377 = db->getRelation("app");
      appindex342 = readrel377->getIndex(ord376, false);
      std::vector<u16> ord378({0, 1, 2});
      slog::Relation* readrel379 = db->getRelation("app");
      appindex343 = readrel379->getIndex(ord378, false);
      std::vector<u16> ord380({0, 1, 2});
      slog::Relation* readrel381 = db->getRelation("lambda");
      lambdaindex344 = readrel381->getIndex(ord380, false);
      std::vector<u16> ord382({0, 1});
      slog::Relation* readrel383 = db->getRelation("ref");
      refindex345 = readrel383->getIndex(ord382, false);
      std::vector<u16> ord384({1, 0});
      slog::Relation* readrel385 = db->getRelation("ref");
      refindex346 = readrel385->getIndex(ord384, false);
      std::vector<u16> ord386({1, 2, 0});
      slog::Relation* readrel387 = db->getRelation("lambda");
      lambdaindex347 = readrel387->getIndex(ord386, false);
      std::vector<u16> ord388({1, 0});
      slog::Relation* readrel389 = db->getRelation("ref");
      refindex348 = readrel389->getIndex(ord388, false);
      std::vector<u16> ord390({1, 2, 0});
      slog::Relation* readrel391 = db->getRelation("app");
      appindex349 = readrel391->getIndex(ord390, false);
      std::vector<u16> ord392({1, 0});
      slog::Relation* readrel393 = db->getRelation("ref");
      refindex350 = readrel393->getIndex(ord392, false);
      std::vector<u16> ord394({1, 2, 0});
      slog::Relation* readrel395 = db->getRelation("lambda");
      lambdaindex351 = readrel395->getIndex(ord394, false);
      std::vector<u16> ord396({1, 2, 0});
      slog::Relation* readrel397 = db->getRelation("app");
      appindex352 = readrel397->getIndex(ord396, false);
      std::vector<u16> ord398({1, 2, 0});
      slog::Relation* readrel399 = db->getRelation("app");
      appindex353 = readrel399->getIndex(ord398, false);
      std::vector<u16> ord400({1, 2, 0});
      slog::Relation* readrel401 = db->getRelation("lambda");
      lambdaindex354 = readrel401->getIndex(ord400, false);
  
    }
    ReadTask355(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c80 = v_constb49bea2fcccd8f4301a347ed;
      u64 v_c81 = v_const66518c0c1b3a5a0b09ae2ef1;
      u64 v_c82 = v_const4a8acfc71441e0695ffcf5b3;
      u64 v_c83 = v_constc85eae03730a4f4cf1d66a0c;
      u64 v_c84 = v_const8ca682693a0738a0641c6956;
      u64 v_c85 = v_const229c0b7aa8a7eb4055f5a3d0;
      u64 v_c86 = v_const576506f61f53440f1edd95d2;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c82, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m402) {
        u64 v_c87 = m402[1];
        u64 v_c88 = m402[2];
        if (buckethash(v_c87) != bucket) return;
        if (!slog::exists_probe<3,1>(lambdaindex333, std::array<u64,3>{v_c85, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex334, std::array<u64,2>{v_c85, 0})) return;
        if (!slog::exists_probe<2,1>(refindex335, std::array<u64,2>{v_c84, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex336, std::array<u64,3>{v_c84, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex337, std::array<u64,2>{v_c80, 0})) return;
        if (!slog::exists_probe<2,1>(refindex338, std::array<u64,2>{v_c86, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex339, std::array<u64,3>{v_c86, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex340, std::array<u64,3>{v_c83, 0, 0})) return;
        slog::join_probe<2,1>(refindex341, std::array<u64,2>{v_c81, 0}, [&](const std::array<u64,2>& m403) {
          u64 v_c89 = m403[1];
          if (!slog::exists_probe<3,1>(appindex342, std::array<u64,3>{v_c89, 0, 0})) return;
          slog::join_probe<3,2>(appindex343, std::array<u64,3>{v_c87, v_c89, 0}, [&](const std::array<u64,3>& m404) {
            u64 v_c90 = m404[2];
            slog::join_probe<3,2>(lambdaindex344, std::array<u64,3>{v_c90, v_c85, 0}, [&](const std::array<u64,3>& m405) {
              u64 v_c91 = m405[2];
              slog::join_probe<2,2>(refindex345, std::array<u64,2>{v_c91, v_c85}, [&](const std::array<u64,2>& m406) {
                slog::join_probe<2,1>(refindex346, std::array<u64,2>{v_c84, 0}, [&](const std::array<u64,2>& m407) {
                  u64 v_c92 = m407[1];
                  slog::join_probe<3,2>(lambdaindex347, std::array<u64,3>{v_c84, v_c92, 0}, [&](const std::array<u64,3>& m408) {
                    u64 v_c93 = m408[2];
                    slog::join_probe<2,1>(refindex348, std::array<u64,2>{v_c80, 0}, [&](const std::array<u64,2>& m409) {
                      u64 v_c94 = m409[1];
                      if (!slog::exists_probe<3,1>(appindex349, std::array<u64,3>{v_c94, 0, 0})) return;
                      slog::join_probe<2,1>(refindex350, std::array<u64,2>{v_c86, 0}, [&](const std::array<u64,2>& m410) {
                        u64 v_c95 = m410[1];
                        slog::join_probe<3,2>(lambdaindex351, std::array<u64,3>{v_c86, v_c95, 0}, [&](const std::array<u64,3>& m411) {
                          u64 v_c96 = m411[2];
                          slog::join_probe<3,2>(appindex352, std::array<u64,3>{v_c89, v_c96, 0}, [&](const std::array<u64,3>& m412) {
                            u64 v_c97 = m412[2];
                            slog::join_probe<3,1>(appindex353, std::array<u64,3>{v_c94, 0, 0}, [&](const std::array<u64,3>& m413) {
                              u64 v_c98 = m413[1]; u64 v_c99 = m413[2];
                              if (v_c94 != v_c98) return;
                              slog::join_probe<3,2>(lambdaindex354, std::array<u64,3>{v_c83, v_c99, 0}, [&](const std::array<u64,3>& m414) {
                                u64 v_c100 = m414[2];
                                ++_fires;
                                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c88, v_c97}, std::array<u16,3>{1, 2, 0});
                              });
                            });
                          });
                        });
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
        ReadTask355* _cont = new ReadTask355(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask355(db,b), false);
  // (crule (pre (let __tconst0y6X73 const0aa6f87434af0222b916e97a) (let __tconst7zoP70 const227d34ceeba7a29aada993d4) (let __tconst0aL952 constd3d07026d47882ceca728218) (let __tconst1bfe65 const59ba3256d223f0d0a00d0633) (let __tconst8wN863 const7cd75b35aa30c3ddf04f9d57) (let __tconst0xUh47 constf700a82e218a86de572e1f7f)) (seeded) (body (join ref (1 0) 1 __tconst0y6X73 __t0QRr59) (exists ref (1 0) 1 __tconst1bfe65) (exists lambda (1 2 0) 1 __tconst1bfe65) (exists app (1 2 0) 1 __t0QRr59) (exists ref (1 0) 1 __tconst0xUh47) (exists lambda (1 2 0) 1 __tconst0xUh47) (exists lambda (1 2 0) 1 __tconst0aL952) (exists ref (1 0) 1 __tconst8wN863) (exists lambda (1 2 0) 1 __tconst8wN863) (exists lambda (1 2 0) 1 __tconst7zoP70) (join ref (1 0) 1 __tconst0aL952 __t5HQ450) (exists app (1 2 0) 1 __t5HQ450) (join ref (1 0) 1 __tconst1bfe65 __t2HsD55) (join lambda (1 2 0) 2 __tconst1bfe65 __t2HsD55 __t0uNb57) (join app (1 2 0) 2 __t0QRr59 __t0uNb57 __t81HE60) (join ref (1 0) 1 __tconst0xUh47 __t5vZb46) (join lambda (1 2 0) 2 __tconst0xUh47 __t5vZb46 __t50zW48) (join app (1 2 0) 2 __t5HQ450 __t50zW48 __t05NY51) (join lambda (1 2 0) 2 __tconst0aL952 __t05NY51 __t3xtz53) (join ref (1 0) 1 __tconst8wN863 __t1mkO62) (join lambda (1 2 0) 2 __tconst8wN863 __t1mkO62 __t3Dru64) (join lambda (1 2 0) 2 __tconst1bfe65 __t3Dru64 __t7JIT66) (join app (1 2 0) 2 __t0QRr59 __t7JIT66 __t5Ri569) (join lambda (1 2 0) 2 __tconst7zoP70 __t5Ri569 __t7KAC71)) (head (mkstruct app (1 2 0) __t9kFz72 __t7KAC71 __t81HE60)) mcfa-counting.slog:287 #f)
  class ReadTask439 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex415;  slog::Index** refindex416;  slog::Index** lambdaindex417;  slog::Index** appindex418;  slog::Index** refindex419;  slog::Index** lambdaindex420;  slog::Index** lambdaindex421;  slog::Index** refindex422;  slog::Index** lambdaindex423;  slog::Index** lambdaindex424;  slog::Index** refindex425;  slog::Index** appindex426;  slog::Index** refindex427;  slog::Index** lambdaindex428;  slog::Index** appindex429;  slog::Index** refindex430;  slog::Index** lambdaindex431;  slog::Index** appindex432;  slog::Index** lambdaindex433;  slog::Index** refindex434;  slog::Index** lambdaindex435;  slog::Index** lambdaindex436;  slog::Index** appindex437;  slog::Index** lambdaindex438;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord440({1, 2, 0});
      slog::Relation* readrel441 = db->getRelation("app");
      head_index[0] = readrel441->getIndex(ord440, false);
      std::vector<u16> ord442({1, 0});
      slog::Relation* readrel443 = db->getRelation("ref");
      refindex415 = readrel443->getIndex(ord442, false);
      std::vector<u16> ord444({1, 0});
      slog::Relation* readrel445 = db->getRelation("ref");
      refindex416 = readrel445->getIndex(ord444, false);
      std::vector<u16> ord446({1, 2, 0});
      slog::Relation* readrel447 = db->getRelation("lambda");
      lambdaindex417 = readrel447->getIndex(ord446, false);
      std::vector<u16> ord448({1, 2, 0});
      slog::Relation* readrel449 = db->getRelation("app");
      appindex418 = readrel449->getIndex(ord448, false);
      std::vector<u16> ord450({1, 0});
      slog::Relation* readrel451 = db->getRelation("ref");
      refindex419 = readrel451->getIndex(ord450, false);
      std::vector<u16> ord452({1, 2, 0});
      slog::Relation* readrel453 = db->getRelation("lambda");
      lambdaindex420 = readrel453->getIndex(ord452, false);
      std::vector<u16> ord454({1, 2, 0});
      slog::Relation* readrel455 = db->getRelation("lambda");
      lambdaindex421 = readrel455->getIndex(ord454, false);
      std::vector<u16> ord456({1, 0});
      slog::Relation* readrel457 = db->getRelation("ref");
      refindex422 = readrel457->getIndex(ord456, false);
      std::vector<u16> ord458({1, 2, 0});
      slog::Relation* readrel459 = db->getRelation("lambda");
      lambdaindex423 = readrel459->getIndex(ord458, false);
      std::vector<u16> ord460({1, 2, 0});
      slog::Relation* readrel461 = db->getRelation("lambda");
      lambdaindex424 = readrel461->getIndex(ord460, false);
      std::vector<u16> ord462({1, 0});
      slog::Relation* readrel463 = db->getRelation("ref");
      refindex425 = readrel463->getIndex(ord462, false);
      std::vector<u16> ord464({1, 2, 0});
      slog::Relation* readrel465 = db->getRelation("app");
      appindex426 = readrel465->getIndex(ord464, false);
      std::vector<u16> ord466({1, 0});
      slog::Relation* readrel467 = db->getRelation("ref");
      refindex427 = readrel467->getIndex(ord466, false);
      std::vector<u16> ord468({1, 2, 0});
      slog::Relation* readrel469 = db->getRelation("lambda");
      lambdaindex428 = readrel469->getIndex(ord468, false);
      std::vector<u16> ord470({1, 2, 0});
      slog::Relation* readrel471 = db->getRelation("app");
      appindex429 = readrel471->getIndex(ord470, false);
      std::vector<u16> ord472({1, 0});
      slog::Relation* readrel473 = db->getRelation("ref");
      refindex430 = readrel473->getIndex(ord472, false);
      std::vector<u16> ord474({1, 2, 0});
      slog::Relation* readrel475 = db->getRelation("lambda");
      lambdaindex431 = readrel475->getIndex(ord474, false);
      std::vector<u16> ord476({1, 2, 0});
      slog::Relation* readrel477 = db->getRelation("app");
      appindex432 = readrel477->getIndex(ord476, false);
      std::vector<u16> ord478({1, 2, 0});
      slog::Relation* readrel479 = db->getRelation("lambda");
      lambdaindex433 = readrel479->getIndex(ord478, false);
      std::vector<u16> ord480({1, 0});
      slog::Relation* readrel481 = db->getRelation("ref");
      refindex434 = readrel481->getIndex(ord480, false);
      std::vector<u16> ord482({1, 2, 0});
      slog::Relation* readrel483 = db->getRelation("lambda");
      lambdaindex435 = readrel483->getIndex(ord482, false);
      std::vector<u16> ord484({1, 2, 0});
      slog::Relation* readrel485 = db->getRelation("lambda");
      lambdaindex436 = readrel485->getIndex(ord484, false);
      std::vector<u16> ord486({1, 2, 0});
      slog::Relation* readrel487 = db->getRelation("app");
      appindex437 = readrel487->getIndex(ord486, false);
      std::vector<u16> ord488({1, 2, 0});
      slog::Relation* readrel489 = db->getRelation("lambda");
      lambdaindex438 = readrel489->getIndex(ord488, false);
  
    }
    ReadTask439(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c48 = v_const0aa6f87434af0222b916e97a;
      u64 v_c49 = v_const227d34ceeba7a29aada993d4;
      u64 v_c50 = v_constd3d07026d47882ceca728218;
      u64 v_c51 = v_const59ba3256d223f0d0a00d0633;
      u64 v_c52 = v_const7cd75b35aa30c3ddf04f9d57;
      u64 v_c53 = v_constf700a82e218a86de572e1f7f;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex415, std::array<u64,2>{v_c48, 0}, [&](const std::array<u64,2>& m490) {
        u64 v_c54 = m490[1];
        if (!slog::exists_probe<2,1>(refindex416, std::array<u64,2>{v_c51, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex417, std::array<u64,3>{v_c51, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex418, std::array<u64,3>{v_c54, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex419, std::array<u64,2>{v_c53, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex420, std::array<u64,3>{v_c53, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex421, std::array<u64,3>{v_c50, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex422, std::array<u64,2>{v_c52, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex423, std::array<u64,3>{v_c52, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex424, std::array<u64,3>{v_c49, 0, 0})) return;
        slog::join_probe<2,1>(refindex425, std::array<u64,2>{v_c50, 0}, [&](const std::array<u64,2>& m491) {
          u64 v_c55 = m491[1];
          if (!slog::exists_probe<3,1>(appindex426, std::array<u64,3>{v_c55, 0, 0})) return;
          slog::join_probe<2,1>(refindex427, std::array<u64,2>{v_c51, 0}, [&](const std::array<u64,2>& m492) {
            u64 v_c60 = m492[1];
            slog::join_probe<3,2>(lambdaindex428, std::array<u64,3>{v_c51, v_c60, 0}, [&](const std::array<u64,3>& m493) {
              u64 v_c61 = m493[2];
              slog::join_probe<3,2>(appindex429, std::array<u64,3>{v_c54, v_c61, 0}, [&](const std::array<u64,3>& m494) {
                u64 v_c62 = m494[2];
                slog::join_probe<2,1>(refindex430, std::array<u64,2>{v_c53, 0}, [&](const std::array<u64,2>& m495) {
                  u64 v_c56 = m495[1];
                  slog::join_probe<3,2>(lambdaindex431, std::array<u64,3>{v_c53, v_c56, 0}, [&](const std::array<u64,3>& m496) {
                    u64 v_c57 = m496[2];
                    slog::join_probe<3,2>(appindex432, std::array<u64,3>{v_c55, v_c57, 0}, [&](const std::array<u64,3>& m497) {
                      u64 v_c58 = m497[2];
                      slog::join_probe<3,2>(lambdaindex433, std::array<u64,3>{v_c50, v_c58, 0}, [&](const std::array<u64,3>& m498) {
                        u64 v_c59 = m498[2];
                        slog::join_probe<2,1>(refindex434, std::array<u64,2>{v_c52, 0}, [&](const std::array<u64,2>& m499) {
                          u64 v_c63 = m499[1];
                          slog::join_probe<3,2>(lambdaindex435, std::array<u64,3>{v_c52, v_c63, 0}, [&](const std::array<u64,3>& m500) {
                            u64 v_c64 = m500[2];
                            slog::join_probe<3,2>(lambdaindex436, std::array<u64,3>{v_c51, v_c64, 0}, [&](const std::array<u64,3>& m501) {
                              u64 v_c65 = m501[2];
                              slog::join_probe<3,2>(appindex437, std::array<u64,3>{v_c54, v_c65, 0}, [&](const std::array<u64,3>& m502) {
                                u64 v_c66 = m502[2];
                                slog::join_probe<3,2>(lambdaindex438, std::array<u64,3>{v_c49, v_c66, 0}, [&](const std::array<u64,3>& m503) {
                                  u64 v_c101 = m503[2];
                                  ++_fires;
                                  slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c101, v_c62}, std::array<u16,3>{1, 2, 0});
                                });
                              });
                            });
                          });
                        });
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
      s->addTaskSeeded(phase_read, new ReadTask439(db,b));
  // (crule (pre (let __tconst4Xaz41 const81cb39a72a584ab4f703b7f7) (let __tconst4xzG22 constdbf1bdba02122b2adce28528) (let __tconst1aIN38 const4d5ce1398140fbe27561181f) (let __tconst37GM26 const85f09fa1913b9daf65957cf7) (let __tconst1HMF17 constd7a1925d249b4768c8a9f2d8) (let __tconst1ha033 const969c6e56242ce8d0a4346602)) (probe lambda (1 2 0) 1 __tconst4Xaz41 __t7P7240 __t79we42) (body (exists ref (1 0) 1 __tconst4xzG22) (exists ref (1 0) 1 __tconst37GM26) (exists lambda (1 2 0) 1 __tconst37GM26) (exists lambda (1 2 0) 1 __tconst1aIN38) (exists lambda (1 2 0) 1 __tconst1ha033) (exists ref (1 0) 1 __tconst1ha033) (exists ref (1 0) 1 __tconst1HMF17) (exists lambda (1 2 0) 1 __tconst1HMF17) (exists lambda (1 2 0) 1 __tconst4xzG22) (join ref (1 0) 1 __tconst4Xaz41 __t75SZ29) (exists app (1 2 0) 1 __t75SZ29) (join ref (1 0) 1 __tconst4xzG22 __t2DOE20) (exists app (1 2 0) 1 __t2DOE20) (join ref (1 0) 1 __tconst37GM26 __t7U1m25) (join lambda (1 2 0) 2 __tconst37GM26 __t7U1m25 __t5myE27) (join app (1 2 0) 2 __t75SZ29 __t5myE27 __t2Vg230) (join app (2 0 1) 2 __t2Vg230 __t7P7240 __t3aRV39) (join lambda (0 1 2) 2 __t3aRV39 __tconst1aIN38 __t3pMW37) (join app (0 1 2) 2 __t3pMW37 __t75SZ29 __t065j34) (join lambda (0 1 2) 2 __t065j34 __tconst1ha033 __t7N9A32) (join ref (0 1) 2 __t7N9A32 __tconst1ha033) (join ref (1 0) 1 __tconst1HMF17 __t7H1u16) (join lambda (1 2 0) 2 __tconst1HMF17 __t7H1u16 __t2wNc18) (join app (1 2 0) 2 __t2DOE20 __t2wNc18 __t3b2k21) (join lambda (1 2 0) 2 __tconst4xzG22 __t3b2k21 __t8Ovw23)) (head (mkstruct app (1 2 0) __t9tGa43 __t79we42 __t8Ovw23)) mcfa-counting.slog:260 #f)
  class ReadTask529 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** refindex504;  slog::Index** refindex505;  slog::Index** lambdaindex506;  slog::Index** lambdaindex507;  slog::Index** lambdaindex508;  slog::Index** refindex509;  slog::Index** refindex510;  slog::Index** lambdaindex511;  slog::Index** lambdaindex512;  slog::Index** refindex513;  slog::Index** appindex514;  slog::Index** refindex515;  slog::Index** appindex516;  slog::Index** refindex517;  slog::Index** lambdaindex518;  slog::Index** appindex519;  slog::Index** appindex520;  slog::Index** lambdaindex521;  slog::Index** appindex522;  slog::Index** lambdaindex523;  slog::Index** refindex524;  slog::Index** refindex525;  slog::Index** lambdaindex526;  slog::Index** appindex527;  slog::Index** lambdaindex528;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord530({1, 2, 0});
      slog::Relation* readrel531 = db->getRelation("lambda");
      driver_index = readrel531->getIndex(ord530, true);
      std::vector<u16> ord532({1, 0});
      slog::Relation* readrel533 = db->getRelation("ref");
      refindex504 = readrel533->getIndex(ord532, false);
      std::vector<u16> ord534({1, 0});
      slog::Relation* readrel535 = db->getRelation("ref");
      refindex505 = readrel535->getIndex(ord534, false);
      std::vector<u16> ord536({1, 2, 0});
      slog::Relation* readrel537 = db->getRelation("lambda");
      lambdaindex506 = readrel537->getIndex(ord536, false);
      std::vector<u16> ord538({1, 2, 0});
      slog::Relation* readrel539 = db->getRelation("lambda");
      lambdaindex507 = readrel539->getIndex(ord538, false);
      std::vector<u16> ord540({1, 2, 0});
      slog::Relation* readrel541 = db->getRelation("lambda");
      lambdaindex508 = readrel541->getIndex(ord540, false);
      std::vector<u16> ord542({1, 0});
      slog::Relation* readrel543 = db->getRelation("ref");
      refindex509 = readrel543->getIndex(ord542, false);
      std::vector<u16> ord544({1, 0});
      slog::Relation* readrel545 = db->getRelation("ref");
      refindex510 = readrel545->getIndex(ord544, false);
      std::vector<u16> ord546({1, 2, 0});
      slog::Relation* readrel547 = db->getRelation("lambda");
      lambdaindex511 = readrel547->getIndex(ord546, false);
      std::vector<u16> ord548({1, 2, 0});
      slog::Relation* readrel549 = db->getRelation("lambda");
      lambdaindex512 = readrel549->getIndex(ord548, false);
      std::vector<u16> ord550({1, 0});
      slog::Relation* readrel551 = db->getRelation("ref");
      refindex513 = readrel551->getIndex(ord550, false);
      std::vector<u16> ord552({1, 2, 0});
      slog::Relation* readrel553 = db->getRelation("app");
      appindex514 = readrel553->getIndex(ord552, false);
      std::vector<u16> ord554({1, 0});
      slog::Relation* readrel555 = db->getRelation("ref");
      refindex515 = readrel555->getIndex(ord554, false);
      std::vector<u16> ord556({1, 2, 0});
      slog::Relation* readrel557 = db->getRelation("app");
      appindex516 = readrel557->getIndex(ord556, false);
      std::vector<u16> ord558({1, 0});
      slog::Relation* readrel559 = db->getRelation("ref");
      refindex517 = readrel559->getIndex(ord558, false);
      std::vector<u16> ord560({1, 2, 0});
      slog::Relation* readrel561 = db->getRelation("lambda");
      lambdaindex518 = readrel561->getIndex(ord560, false);
      std::vector<u16> ord562({1, 2, 0});
      slog::Relation* readrel563 = db->getRelation("app");
      appindex519 = readrel563->getIndex(ord562, false);
      std::vector<u16> ord564({2, 0, 1});
      slog::Relation* readrel565 = db->getRelation("app");
      appindex520 = readrel565->getIndex(ord564, false);
      std::vector<u16> ord566({0, 1, 2});
      slog::Relation* readrel567 = db->getRelation("lambda");
      lambdaindex521 = readrel567->getIndex(ord566, false);
      std::vector<u16> ord568({0, 1, 2});
      slog::Relation* readrel569 = db->getRelation("app");
      appindex522 = readrel569->getIndex(ord568, false);
      std::vector<u16> ord570({0, 1, 2});
      slog::Relation* readrel571 = db->getRelation("lambda");
      lambdaindex523 = readrel571->getIndex(ord570, false);
      std::vector<u16> ord572({0, 1});
      slog::Relation* readrel573 = db->getRelation("ref");
      refindex524 = readrel573->getIndex(ord572, false);
      std::vector<u16> ord574({1, 0});
      slog::Relation* readrel575 = db->getRelation("ref");
      refindex525 = readrel575->getIndex(ord574, false);
      std::vector<u16> ord576({1, 2, 0});
      slog::Relation* readrel577 = db->getRelation("lambda");
      lambdaindex526 = readrel577->getIndex(ord576, false);
      std::vector<u16> ord578({1, 2, 0});
      slog::Relation* readrel579 = db->getRelation("app");
      appindex527 = readrel579->getIndex(ord578, false);
      std::vector<u16> ord580({1, 2, 0});
      slog::Relation* readrel581 = db->getRelation("lambda");
      lambdaindex528 = readrel581->getIndex(ord580, false);
  
    }
    ReadTask529(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c102 = v_const81cb39a72a584ab4f703b7f7;
      u64 v_c103 = v_constdbf1bdba02122b2adce28528;
      u64 v_c104 = v_const4d5ce1398140fbe27561181f;
      u64 v_c105 = v_const85f09fa1913b9daf65957cf7;
      u64 v_c106 = v_constd7a1925d249b4768c8a9f2d8;
      u64 v_c107 = v_const969c6e56242ce8d0a4346602;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c102, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m582) {
        u64 v_c108 = m582[1];
        u64 v_c109 = m582[2];
        if (buckethash(v_c108) != bucket) return;
        if (!slog::exists_probe<2,1>(refindex504, std::array<u64,2>{v_c103, 0})) return;
        if (!slog::exists_probe<2,1>(refindex505, std::array<u64,2>{v_c105, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex506, std::array<u64,3>{v_c105, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex507, std::array<u64,3>{v_c104, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex508, std::array<u64,3>{v_c107, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex509, std::array<u64,2>{v_c107, 0})) return;
        if (!slog::exists_probe<2,1>(refindex510, std::array<u64,2>{v_c106, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex511, std::array<u64,3>{v_c106, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex512, std::array<u64,3>{v_c103, 0, 0})) return;
        slog::join_probe<2,1>(refindex513, std::array<u64,2>{v_c102, 0}, [&](const std::array<u64,2>& m583) {
          u64 v_c110 = m583[1];
          if (!slog::exists_probe<3,1>(appindex514, std::array<u64,3>{v_c110, 0, 0})) return;
          slog::join_probe<2,1>(refindex515, std::array<u64,2>{v_c103, 0}, [&](const std::array<u64,2>& m584) {
            u64 v_c111 = m584[1];
            if (!slog::exists_probe<3,1>(appindex516, std::array<u64,3>{v_c111, 0, 0})) return;
            slog::join_probe<2,1>(refindex517, std::array<u64,2>{v_c105, 0}, [&](const std::array<u64,2>& m585) {
              u64 v_c112 = m585[1];
              slog::join_probe<3,2>(lambdaindex518, std::array<u64,3>{v_c105, v_c112, 0}, [&](const std::array<u64,3>& m586) {
                u64 v_c113 = m586[2];
                slog::join_probe<3,2>(appindex519, std::array<u64,3>{v_c110, v_c113, 0}, [&](const std::array<u64,3>& m587) {
                  u64 v_c114 = m587[2];
                  slog::join_probe<3,2>(appindex520, std::array<u64,3>{v_c114, v_c108, 0}, [&](const std::array<u64,3>& m588) {
                    u64 v_c115 = m588[2];
                    slog::join_probe<3,2>(lambdaindex521, std::array<u64,3>{v_c115, v_c104, 0}, [&](const std::array<u64,3>& m589) {
                      u64 v_c116 = m589[2];
                      slog::join_probe<3,2>(appindex522, std::array<u64,3>{v_c116, v_c110, 0}, [&](const std::array<u64,3>& m590) {
                        u64 v_c117 = m590[2];
                        slog::join_probe<3,2>(lambdaindex523, std::array<u64,3>{v_c117, v_c107, 0}, [&](const std::array<u64,3>& m591) {
                          u64 v_c118 = m591[2];
                          slog::join_probe<2,2>(refindex524, std::array<u64,2>{v_c118, v_c107}, [&](const std::array<u64,2>& m592) {
                            slog::join_probe<2,1>(refindex525, std::array<u64,2>{v_c106, 0}, [&](const std::array<u64,2>& m593) {
                              u64 v_c119 = m593[1];
                              slog::join_probe<3,2>(lambdaindex526, std::array<u64,3>{v_c106, v_c119, 0}, [&](const std::array<u64,3>& m594) {
                                u64 v_c120 = m594[2];
                                slog::join_probe<3,2>(appindex527, std::array<u64,3>{v_c111, v_c120, 0}, [&](const std::array<u64,3>& m595) {
                                  u64 v_c121 = m595[2];
                                  slog::join_probe<3,2>(lambdaindex528, std::array<u64,3>{v_c103, v_c121, 0}, [&](const std::array<u64,3>& m596) {
                                    u64 v_c122 = m596[2];
                                    ++_fires;
                                    slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c109, v_c122}, std::array<u16,3>{1, 2, 0});
                                  });
                                });
                              });
                            });
                          });
                        });
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
  
      if (_fires) db->bumpFires("mcfa-counting.slog:260", "delta:lambda", _fires);
  
      if (!_done)
      {
        ReadTask529* _cont = new ReadTask529(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask529(db,b), false);
  // (crule (pre) (scan lambda __t0RD6171 x eb) (body (join-old clo (1 2 0) 1 (1 2 0) __t0RD6171 cb __t2Hqj172) (join eval_ans (1 0) 1 __t2Hqj172 __t6CRg170) (join eval (0 2 1) 1 __t6CRg170 c ef) (exists app (1 2 0) 1 ef) (exists eval (2 0 1) 1 c) (join eval (2 0 1) 1 c __6tlE337 __t5SBy169) (join app (0 1 2) 2 __t5SBy169 ef ea) (join-old eval (1 2 0) 2 (1 2 0) ea c __t1JPZ173) (join eval_ans (0 1) 1 __t1JPZ173 va)) (head (emit store (0 1 2) x __t5SBy169 va) (emit callev (0 1) __t5SBy169 c) (emit bindev (0 1 2) x __t5SBy169 c)) mcfa-counting.slog:92 #f)
  class ReadTask608 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** cloindex597;  slog::Index** eval_ansindex598;  slog::Index** evalindex599;  slog::Index** appindex600;  slog::Index** evalindex601;  slog::Index** evalindex602;  slog::Index** appindex603;  slog::Index** evalindex604;  slog::Index** eval_ansindex605;  slog::Index** clodelta606;  slog::Index** evaldelta607;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("store");
      std::vector<u16> ord609({0, 1, 2});
      slog::Relation* readrel610 = db->getRelation("store");
      head_index[0] = readrel610->getIndex(ord609, false);
      head_rel[1] = db->getRelation("callev");
      std::vector<u16> ord611({0, 1});
      slog::Relation* readrel612 = db->getRelation("callev");
      head_index[1] = readrel612->getIndex(ord611, false);
      head_rel[2] = db->getRelation("bindev");
      std::vector<u16> ord613({0, 1, 2});
      slog::Relation* readrel614 = db->getRelation("bindev");
      head_index[2] = readrel614->getIndex(ord613, false);
      outer_rel = db->getRelation("lambda");
      std::vector<u16> ord615({1, 2, 0});
      slog::Relation* readrel616 = db->getRelation("clo");
      cloindex597 = readrel616->getIndex(ord615, false);
      std::vector<u16> ord617({1, 2, 0});
      slog::Relation* readrel618 = db->getRelation("clo");
      clodelta606 = readrel618->getIndex(ord617, true);
      std::vector<u16> ord619({1, 0});
      slog::Relation* readrel620 = db->getRelation("eval_ans");
      eval_ansindex598 = readrel620->getIndex(ord619, false);
      std::vector<u16> ord621({0, 2, 1});
      slog::Relation* readrel622 = db->getRelation("eval");
      evalindex599 = readrel622->getIndex(ord621, false);
      std::vector<u16> ord623({1, 2, 0});
      slog::Relation* readrel624 = db->getRelation("app");
      appindex600 = readrel624->getIndex(ord623, false);
      std::vector<u16> ord625({2, 0, 1});
      slog::Relation* readrel626 = db->getRelation("eval");
      evalindex601 = readrel626->getIndex(ord625, false);
      std::vector<u16> ord627({2, 0, 1});
      slog::Relation* readrel628 = db->getRelation("eval");
      evalindex602 = readrel628->getIndex(ord627, false);
      std::vector<u16> ord629({0, 1, 2});
      slog::Relation* readrel630 = db->getRelation("app");
      appindex603 = readrel630->getIndex(ord629, false);
      std::vector<u16> ord631({1, 2, 0});
      slog::Relation* readrel632 = db->getRelation("eval");
      evalindex604 = readrel632->getIndex(ord631, false);
      std::vector<u16> ord633({1, 2, 0});
      slog::Relation* readrel634 = db->getRelation("eval");
      evaldelta607 = readrel634->getIndex(ord633, true);
      std::vector<u16> ord635({0, 1});
      slog::Relation* readrel636 = db->getRelation("eval_ans");
      eval_ansindex605 = readrel636->getIndex(ord635, false);
  
    }
    ReadTask608(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c77 = _t[0];
        u64 v_c78 = _t[1];
        u64 v_c79 = _t[2];
        slog::join_probe_old<3,1>(cloindex597, clodelta606, std::array<u64,3>{v_c77, 0, 0}, [&](const std::array<u64,3>& m637) {
          u64 v_c76 = m637[1]; u64 v_c74 = m637[2];
          slog::join_probe<2,1>(eval_ansindex598, std::array<u64,2>{v_c74, 0}, [&](const std::array<u64,2>& m638) {
            u64 v_c72 = m638[1];
            slog::join_probe<3,1>(evalindex599, std::array<u64,3>{v_c72, 0, 0}, [&](const std::array<u64,3>& m639) {
              u64 v_c70 = m639[1]; u64 v_c68 = m639[2];
              if (!slog::exists_probe<3,1>(appindex600, std::array<u64,3>{v_c68, 0, 0})) return;
              if (!slog::exists_probe<3,1>(evalindex601, std::array<u64,3>{v_c70, 0, 0})) return;
              slog::join_probe<3,1>(evalindex602, std::array<u64,3>{v_c70, 0, 0}, [&](const std::array<u64,3>& m640) {
                u64 v_c71 = m640[1]; u64 v_c67 = m640[2];
                slog::join_probe<3,2>(appindex603, std::array<u64,3>{v_c67, v_c68, 0}, [&](const std::array<u64,3>& m641) {
                  u64 v_c69 = m641[2];
                  slog::join_probe_old<3,2>(evalindex604, evaldelta607, std::array<u64,3>{v_c69, v_c70, 0}, [&](const std::array<u64,3>& m642) {
                    u64 v_c73 = m642[2];
                    slog::join_probe<2,1>(eval_ansindex605, std::array<u64,2>{v_c73, 0}, [&](const std::array<u64,2>& m643) {
                      u64 v_c75 = m643[1];
                      ++_fires;
                      slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c78, v_c67, v_c75}, std::array<u16,3>{0, 1, 2});
                      slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c67, v_c70}, std::array<u16,2>{0, 1});
                      slog::emit<3>(head_rel[2], head_index[2], newbatch[2], std::array<u64,3>{v_c78, v_c67, v_c70}, std::array<u16,3>{0, 1, 2});
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
  
      if (_fires) db->bumpFires("mcfa-counting.slog:92", "delta:lambda", _fires);
  
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
  // (crule (pre) (scan store y cb vy) (body (join-old freevar (0 1) 1 (0 1) y __t4I265) (join-old lambda (0 1 2) 1 (0 1 2) __t4I265 x eb) (join-old eval (0 2 1) 0 (0 2 1) __4DdV347 c __t5Yh14) (join-old app (0 1 2) 1 (0 1 2) __t5Yh14 ef ea)) (head (mkstruct eval (1 2 0) __34Tv348 ea c)) mcfa-counting.slog:102 #f)
  class ReadTask652 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** freevarindex644;  slog::Index** lambdaindex645;  slog::Index** evalindex646;  slog::Index** appindex647;  slog::Index** freevardelta648;  slog::Index** lambdadelta649;  slog::Index** evaldelta650;  slog::Index** appdelta651;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("store");
      std::vector<u16> ord653({0, 1});
      slog::Relation* readrel654 = db->getRelation("freevar");
      freevarindex644 = readrel654->getIndex(ord653, false);
      std::vector<u16> ord655({0, 1});
      slog::Relation* readrel656 = db->getRelation("freevar");
      freevardelta648 = readrel656->getIndex(ord655, true);
      std::vector<u16> ord657({0, 1, 2});
      slog::Relation* readrel658 = db->getRelation("lambda");
      lambdaindex645 = readrel658->getIndex(ord657, false);
      std::vector<u16> ord659({0, 1, 2});
      slog::Relation* readrel660 = db->getRelation("lambda");
      lambdadelta649 = readrel660->getIndex(ord659, true);
      std::vector<u16> ord661({0, 2, 1});
      slog::Relation* readrel662 = db->getRelation("eval");
      evalindex646 = readrel662->getIndex(ord661, false);
      std::vector<u16> ord663({0, 2, 1});
      slog::Relation* readrel664 = db->getRelation("eval");
      evaldelta650 = readrel664->getIndex(ord663, true);
      std::vector<u16> ord665({0, 1, 2});
      slog::Relation* readrel666 = db->getRelation("app");
      appindex647 = readrel666->getIndex(ord665, false);
      std::vector<u16> ord667({0, 1, 2});
      slog::Relation* readrel668 = db->getRelation("app");
      appdelta651 = readrel668->getIndex(ord667, true);
  
    }
    ReadTask652(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c76 = _t[1];
        u64 v_c124 = _t[2];
        slog::join_probe_old<2,1>(freevarindex644, freevardelta648, std::array<u64,2>{v_c123, 0}, [&](const std::array<u64,2>& m669) {
          u64 v_c125 = m669[1];
          slog::join_probe_old<3,1>(lambdaindex645, lambdadelta649, std::array<u64,3>{v_c125, 0, 0}, [&](const std::array<u64,3>& m670) {
            u64 v_c78 = m670[1]; u64 v_c79 = m670[2];
            slog::join_all_old<3>(evalindex646, evaldelta650, [&](const std::array<u64,3>& m671) {
              u64 v_c126 = m671[0]; u64 v_c70 = m671[1]; u64 v_c127 = m671[2];
              slog::join_probe_old<3,1>(appindex647, appdelta651, std::array<u64,3>{v_c127, 0, 0}, [&](const std::array<u64,3>& m672) {
                u64 v_c68 = m672[1]; u64 v_c69 = m672[2];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c69, v_c70}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:102", "delta:store", _fires);
  
      if (!_done)
      {
        ReadTask652* _cont = new ReadTask652(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask652(db,b), false);
  // (crule (pre (let __tconst4she277 const50a95ec20b9767e468d04917) (let __tconst0ZLv270 constf0a25c0401304c51b5ee9c5e)) (once) (body) (head (mkstruct ref (1 0) __t28CO273 __tconst4she277) (mkstruct ref (1 0) __t9L3S266 __tconst0ZLv270)) mcfa-counting.slog:183 #f)
  class ReadTask673 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ref");
      head_rel[1] = db->getRelation("ref");
  
    }
    ReadTask673(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const50a95ec20b9767e468d04917;
      u64 v_c1 = v_constf0a25c0401304c51b5ee9c5e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c0}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c1}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:183", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask673(db,b), true);
  // (crule (pre (let __tconst4she277 const50a95ec20b9767e468d04917) (let __tconst0ZLv270 constf0a25c0401304c51b5ee9c5e)) (seeded) (body (join ref (1 0) 1 __tconst0ZLv270 __t9L3S266) (exists app (1 2 0) 1 __t9L3S266) (exists lambda (1 2 0) 1 __tconst0ZLv270) (exists lambda (1 2 0) 1 __tconst4she277) (join ref (1 0) 1 __tconst4she277 __t28CO273) (exists app (1 2 0) 1 __t28CO273) (join app (1 2 0) 1 __t9L3S266 dup86DB443 __t8kx2269) (eq __t9L3S266 dup86DB443) (join lambda (1 2 0) 2 __tconst0ZLv270 __t8kx2269 __t3oIn271) (join app (1 2 0) 1 __t28CO273 dup8ICS444 __t6FnS276) (eq __t28CO273 dup8ICS444) (join lambda (1 2 0) 2 __tconst4she277 __t6FnS276 __t6zNR278)) (head (mkstruct app (1 2 0) __t4C0a279 __t6zNR278 __t3oIn271)) mcfa-counting.slog:183 #f)
  class ReadTask684 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex674;  slog::Index** appindex675;  slog::Index** lambdaindex676;  slog::Index** lambdaindex677;  slog::Index** refindex678;  slog::Index** appindex679;  slog::Index** appindex680;  slog::Index** lambdaindex681;  slog::Index** appindex682;  slog::Index** lambdaindex683;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord685({1, 2, 0});
      slog::Relation* readrel686 = db->getRelation("app");
      head_index[0] = readrel686->getIndex(ord685, false);
      std::vector<u16> ord687({1, 0});
      slog::Relation* readrel688 = db->getRelation("ref");
      refindex674 = readrel688->getIndex(ord687, false);
      std::vector<u16> ord689({1, 2, 0});
      slog::Relation* readrel690 = db->getRelation("app");
      appindex675 = readrel690->getIndex(ord689, false);
      std::vector<u16> ord691({1, 2, 0});
      slog::Relation* readrel692 = db->getRelation("lambda");
      lambdaindex676 = readrel692->getIndex(ord691, false);
      std::vector<u16> ord693({1, 2, 0});
      slog::Relation* readrel694 = db->getRelation("lambda");
      lambdaindex677 = readrel694->getIndex(ord693, false);
      std::vector<u16> ord695({1, 0});
      slog::Relation* readrel696 = db->getRelation("ref");
      refindex678 = readrel696->getIndex(ord695, false);
      std::vector<u16> ord697({1, 2, 0});
      slog::Relation* readrel698 = db->getRelation("app");
      appindex679 = readrel698->getIndex(ord697, false);
      std::vector<u16> ord699({1, 2, 0});
      slog::Relation* readrel700 = db->getRelation("app");
      appindex680 = readrel700->getIndex(ord699, false);
      std::vector<u16> ord701({1, 2, 0});
      slog::Relation* readrel702 = db->getRelation("lambda");
      lambdaindex681 = readrel702->getIndex(ord701, false);
      std::vector<u16> ord703({1, 2, 0});
      slog::Relation* readrel704 = db->getRelation("app");
      appindex682 = readrel704->getIndex(ord703, false);
      std::vector<u16> ord705({1, 2, 0});
      slog::Relation* readrel706 = db->getRelation("lambda");
      lambdaindex683 = readrel706->getIndex(ord705, false);
  
    }
    ReadTask684(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const50a95ec20b9767e468d04917;
      u64 v_c1 = v_constf0a25c0401304c51b5ee9c5e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex674, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m707) {
        u64 v_c2 = m707[1];
        if (!slog::exists_probe<3,1>(appindex675, std::array<u64,3>{v_c2, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex676, std::array<u64,3>{v_c1, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex677, std::array<u64,3>{v_c0, 0, 0})) return;
        slog::join_probe<2,1>(refindex678, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m708) {
          u64 v_c3 = m708[1];
          if (!slog::exists_probe<3,1>(appindex679, std::array<u64,3>{v_c3, 0, 0})) return;
          slog::join_probe<3,1>(appindex680, std::array<u64,3>{v_c2, 0, 0}, [&](const std::array<u64,3>& m709) {
            u64 v_c128 = m709[1]; u64 v_c129 = m709[2];
            if (v_c2 != v_c128) return;
            slog::join_probe<3,2>(lambdaindex681, std::array<u64,3>{v_c1, v_c129, 0}, [&](const std::array<u64,3>& m710) {
              u64 v_c130 = m710[2];
              slog::join_probe<3,1>(appindex682, std::array<u64,3>{v_c3, 0, 0}, [&](const std::array<u64,3>& m711) {
                u64 v_c131 = m711[1]; u64 v_c132 = m711[2];
                if (v_c3 != v_c131) return;
                slog::join_probe<3,2>(lambdaindex683, std::array<u64,3>{v_c0, v_c132, 0}, [&](const std::array<u64,3>& m712) {
                  u64 v_c133 = m712[2];
                  ++_fires;
                  slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c133, v_c130}, std::array<u16,3>{1, 2, 0});
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
      s->addTaskSeeded(phase_read, new ReadTask684(db,b));
  // (crule (pre (let __tconst7sqz226 const7b8fd91ee9ff10cfbb8066bf) (let __tconst1EUj230 const615ad01b1c532bb6634df115) (let __tconst4N2q248 constaaaad65142343c54348db5d0) (let __tconst2VuQ234 const4492fd5fa4baacfebd29f5e5) (let __tconst4Sko246 consteb793a6f75d6cfe49d3c2c90) (let __tconst2x2f244 consta32d5a443def48e6d64c6f4b)) (seeded) (body (join ref (1 0) 1 __tconst1EUj230 __t3WVP229) (exists ref (1 0) 1 __tconst7sqz226) (exists lambda (1 2 0) 1 __tconst7sqz226) (exists ref (1 0) 1 __tconst2VuQ234) (exists lambda (1 2 0) 1 __tconst2VuQ234) (exists ref (1 0) 1 __tconst2x2f244) (exists ref (1 0) 1 __tconst4N2q248) (exists ref (1 0) 1 __tconst4Sko246) (exists lambda (1 2 0) 1 __tconst2x2f244) (exists lambda (1 2 0) 1 __tconst4Sko246) (exists lambda (1 2 0) 1 __tconst4N2q248) (join lambda (1 2 0) 2 __tconst1EUj230 __t3WVP229 __t5ryk231) (exists app (2 0 1) 1 __t5ryk231) (join ref (1 0) 1 __tconst7sqz226 __t5APF225) (join lambda (1 2 0) 2 __tconst7sqz226 __t5APF225 __t2BAX227) (join ref (1 0) 1 __tconst2VuQ234 __t2PLq233) (join lambda (1 2 0) 2 __tconst2VuQ234 __t2PLq233 __t45rU235) (exists app (2 0 1) 1 __t45rU235) (join ref (1 0) 1 __tconst2x2f244 __t3pbc237) (exists app (2 0 1) 1 __t3pbc237) (join ref (1 0) 1 __tconst4N2q248 __t6KL4241) (exists app (1 2 0) 1 __t6KL4241) (join ref (1 0) 1 __tconst4Sko246 __t16jv239) (join app (1 2 0) 2 __t6KL4241 __t16jv239 __t4wvK242) (join app (1 2 0) 2 __t4wvK242 __t3pbc237 __t5h6K243) (join lambda (1 2 0) 2 __tconst2x2f244 __t5h6K243 __t3laZ245) (join lambda (1 2 0) 2 __tconst4Sko246 __t3laZ245 __t7yz1247) (join lambda (1 2 0) 2 __tconst4N2q248 __t7yz1247 __t5uyC249) (join app (1 2 0) 2 __t5uyC249 __t45rU235 __t5pZU250) (join app (1 2 0) 2 __t5pZU250 __t5ryk231 __t9bBp251)) (head (mkstruct app (1 2 0) __t7iVu252 __t9bBp251 __t2BAX227)) mcfa-counting.slog:272 #f)
  class ReadTask743 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex713;  slog::Index** refindex714;  slog::Index** lambdaindex715;  slog::Index** refindex716;  slog::Index** lambdaindex717;  slog::Index** refindex718;  slog::Index** refindex719;  slog::Index** refindex720;  slog::Index** lambdaindex721;  slog::Index** lambdaindex722;  slog::Index** lambdaindex723;  slog::Index** lambdaindex724;  slog::Index** appindex725;  slog::Index** refindex726;  slog::Index** lambdaindex727;  slog::Index** refindex728;  slog::Index** lambdaindex729;  slog::Index** appindex730;  slog::Index** refindex731;  slog::Index** appindex732;  slog::Index** refindex733;  slog::Index** appindex734;  slog::Index** refindex735;  slog::Index** appindex736;  slog::Index** appindex737;  slog::Index** lambdaindex738;  slog::Index** lambdaindex739;  slog::Index** lambdaindex740;  slog::Index** appindex741;  slog::Index** appindex742;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord744({1, 2, 0});
      slog::Relation* readrel745 = db->getRelation("app");
      head_index[0] = readrel745->getIndex(ord744, false);
      std::vector<u16> ord746({1, 0});
      slog::Relation* readrel747 = db->getRelation("ref");
      refindex713 = readrel747->getIndex(ord746, false);
      std::vector<u16> ord748({1, 0});
      slog::Relation* readrel749 = db->getRelation("ref");
      refindex714 = readrel749->getIndex(ord748, false);
      std::vector<u16> ord750({1, 2, 0});
      slog::Relation* readrel751 = db->getRelation("lambda");
      lambdaindex715 = readrel751->getIndex(ord750, false);
      std::vector<u16> ord752({1, 0});
      slog::Relation* readrel753 = db->getRelation("ref");
      refindex716 = readrel753->getIndex(ord752, false);
      std::vector<u16> ord754({1, 2, 0});
      slog::Relation* readrel755 = db->getRelation("lambda");
      lambdaindex717 = readrel755->getIndex(ord754, false);
      std::vector<u16> ord756({1, 0});
      slog::Relation* readrel757 = db->getRelation("ref");
      refindex718 = readrel757->getIndex(ord756, false);
      std::vector<u16> ord758({1, 0});
      slog::Relation* readrel759 = db->getRelation("ref");
      refindex719 = readrel759->getIndex(ord758, false);
      std::vector<u16> ord760({1, 0});
      slog::Relation* readrel761 = db->getRelation("ref");
      refindex720 = readrel761->getIndex(ord760, false);
      std::vector<u16> ord762({1, 2, 0});
      slog::Relation* readrel763 = db->getRelation("lambda");
      lambdaindex721 = readrel763->getIndex(ord762, false);
      std::vector<u16> ord764({1, 2, 0});
      slog::Relation* readrel765 = db->getRelation("lambda");
      lambdaindex722 = readrel765->getIndex(ord764, false);
      std::vector<u16> ord766({1, 2, 0});
      slog::Relation* readrel767 = db->getRelation("lambda");
      lambdaindex723 = readrel767->getIndex(ord766, false);
      std::vector<u16> ord768({1, 2, 0});
      slog::Relation* readrel769 = db->getRelation("lambda");
      lambdaindex724 = readrel769->getIndex(ord768, false);
      std::vector<u16> ord770({2, 0, 1});
      slog::Relation* readrel771 = db->getRelation("app");
      appindex725 = readrel771->getIndex(ord770, false);
      std::vector<u16> ord772({1, 0});
      slog::Relation* readrel773 = db->getRelation("ref");
      refindex726 = readrel773->getIndex(ord772, false);
      std::vector<u16> ord774({1, 2, 0});
      slog::Relation* readrel775 = db->getRelation("lambda");
      lambdaindex727 = readrel775->getIndex(ord774, false);
      std::vector<u16> ord776({1, 0});
      slog::Relation* readrel777 = db->getRelation("ref");
      refindex728 = readrel777->getIndex(ord776, false);
      std::vector<u16> ord778({1, 2, 0});
      slog::Relation* readrel779 = db->getRelation("lambda");
      lambdaindex729 = readrel779->getIndex(ord778, false);
      std::vector<u16> ord780({2, 0, 1});
      slog::Relation* readrel781 = db->getRelation("app");
      appindex730 = readrel781->getIndex(ord780, false);
      std::vector<u16> ord782({1, 0});
      slog::Relation* readrel783 = db->getRelation("ref");
      refindex731 = readrel783->getIndex(ord782, false);
      std::vector<u16> ord784({2, 0, 1});
      slog::Relation* readrel785 = db->getRelation("app");
      appindex732 = readrel785->getIndex(ord784, false);
      std::vector<u16> ord786({1, 0});
      slog::Relation* readrel787 = db->getRelation("ref");
      refindex733 = readrel787->getIndex(ord786, false);
      std::vector<u16> ord788({1, 2, 0});
      slog::Relation* readrel789 = db->getRelation("app");
      appindex734 = readrel789->getIndex(ord788, false);
      std::vector<u16> ord790({1, 0});
      slog::Relation* readrel791 = db->getRelation("ref");
      refindex735 = readrel791->getIndex(ord790, false);
      std::vector<u16> ord792({1, 2, 0});
      slog::Relation* readrel793 = db->getRelation("app");
      appindex736 = readrel793->getIndex(ord792, false);
      std::vector<u16> ord794({1, 2, 0});
      slog::Relation* readrel795 = db->getRelation("app");
      appindex737 = readrel795->getIndex(ord794, false);
      std::vector<u16> ord796({1, 2, 0});
      slog::Relation* readrel797 = db->getRelation("lambda");
      lambdaindex738 = readrel797->getIndex(ord796, false);
      std::vector<u16> ord798({1, 2, 0});
      slog::Relation* readrel799 = db->getRelation("lambda");
      lambdaindex739 = readrel799->getIndex(ord798, false);
      std::vector<u16> ord800({1, 2, 0});
      slog::Relation* readrel801 = db->getRelation("lambda");
      lambdaindex740 = readrel801->getIndex(ord800, false);
      std::vector<u16> ord802({1, 2, 0});
      slog::Relation* readrel803 = db->getRelation("app");
      appindex741 = readrel803->getIndex(ord802, false);
      std::vector<u16> ord804({1, 2, 0});
      slog::Relation* readrel805 = db->getRelation("app");
      appindex742 = readrel805->getIndex(ord804, false);
  
    }
    ReadTask743(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c134 = v_const7b8fd91ee9ff10cfbb8066bf;
      u64 v_c135 = v_const615ad01b1c532bb6634df115;
      u64 v_c136 = v_constaaaad65142343c54348db5d0;
      u64 v_c137 = v_const4492fd5fa4baacfebd29f5e5;
      u64 v_c138 = v_consteb793a6f75d6cfe49d3c2c90;
      u64 v_c139 = v_consta32d5a443def48e6d64c6f4b;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex713, std::array<u64,2>{v_c135, 0}, [&](const std::array<u64,2>& m806) {
        u64 v_c140 = m806[1];
        if (!slog::exists_probe<2,1>(refindex714, std::array<u64,2>{v_c134, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex715, std::array<u64,3>{v_c134, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex716, std::array<u64,2>{v_c137, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex717, std::array<u64,3>{v_c137, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex718, std::array<u64,2>{v_c139, 0})) return;
        if (!slog::exists_probe<2,1>(refindex719, std::array<u64,2>{v_c136, 0})) return;
        if (!slog::exists_probe<2,1>(refindex720, std::array<u64,2>{v_c138, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex721, std::array<u64,3>{v_c139, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex722, std::array<u64,3>{v_c138, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex723, std::array<u64,3>{v_c136, 0, 0})) return;
        slog::join_probe<3,2>(lambdaindex724, std::array<u64,3>{v_c135, v_c140, 0}, [&](const std::array<u64,3>& m807) {
          u64 v_c141 = m807[2];
          if (!slog::exists_probe<3,1>(appindex725, std::array<u64,3>{v_c141, 0, 0})) return;
          slog::join_probe<2,1>(refindex726, std::array<u64,2>{v_c134, 0}, [&](const std::array<u64,2>& m808) {
            u64 v_c142 = m808[1];
            slog::join_probe<3,2>(lambdaindex727, std::array<u64,3>{v_c134, v_c142, 0}, [&](const std::array<u64,3>& m809) {
              u64 v_c143 = m809[2];
              slog::join_probe<2,1>(refindex728, std::array<u64,2>{v_c137, 0}, [&](const std::array<u64,2>& m810) {
                u64 v_c144 = m810[1];
                slog::join_probe<3,2>(lambdaindex729, std::array<u64,3>{v_c137, v_c144, 0}, [&](const std::array<u64,3>& m811) {
                  u64 v_c145 = m811[2];
                  if (!slog::exists_probe<3,1>(appindex730, std::array<u64,3>{v_c145, 0, 0})) return;
                  slog::join_probe<2,1>(refindex731, std::array<u64,2>{v_c139, 0}, [&](const std::array<u64,2>& m812) {
                    u64 v_c146 = m812[1];
                    if (!slog::exists_probe<3,1>(appindex732, std::array<u64,3>{v_c146, 0, 0})) return;
                    slog::join_probe<2,1>(refindex733, std::array<u64,2>{v_c136, 0}, [&](const std::array<u64,2>& m813) {
                      u64 v_c147 = m813[1];
                      if (!slog::exists_probe<3,1>(appindex734, std::array<u64,3>{v_c147, 0, 0})) return;
                      slog::join_probe<2,1>(refindex735, std::array<u64,2>{v_c138, 0}, [&](const std::array<u64,2>& m814) {
                        u64 v_c148 = m814[1];
                        slog::join_probe<3,2>(appindex736, std::array<u64,3>{v_c147, v_c148, 0}, [&](const std::array<u64,3>& m815) {
                          u64 v_c149 = m815[2];
                          slog::join_probe<3,2>(appindex737, std::array<u64,3>{v_c149, v_c146, 0}, [&](const std::array<u64,3>& m816) {
                            u64 v_c150 = m816[2];
                            slog::join_probe<3,2>(lambdaindex738, std::array<u64,3>{v_c139, v_c150, 0}, [&](const std::array<u64,3>& m817) {
                              u64 v_c151 = m817[2];
                              slog::join_probe<3,2>(lambdaindex739, std::array<u64,3>{v_c138, v_c151, 0}, [&](const std::array<u64,3>& m818) {
                                u64 v_c152 = m818[2];
                                slog::join_probe<3,2>(lambdaindex740, std::array<u64,3>{v_c136, v_c152, 0}, [&](const std::array<u64,3>& m819) {
                                  u64 v_c153 = m819[2];
                                  slog::join_probe<3,2>(appindex741, std::array<u64,3>{v_c153, v_c145, 0}, [&](const std::array<u64,3>& m820) {
                                    u64 v_c154 = m820[2];
                                    slog::join_probe<3,2>(appindex742, std::array<u64,3>{v_c154, v_c141, 0}, [&](const std::array<u64,3>& m821) {
                                      u64 v_c155 = m821[2];
                                      ++_fires;
                                      slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c155, v_c143}, std::array<u16,3>{1, 2, 0});
                                    });
                                  });
                                });
                              });
                            });
                          });
                        });
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
      s->addTaskSeeded(phase_read, new ReadTask743(db,b));
  // (crule (pre (let __tconst1pJW313 constb49bea2fcccd8f4301a347ed) (let __tconst7LWP310 const66518c0c1b3a5a0b09ae2ef1) (let __tconst0sqO307 const4a8acfc71441e0695ffcf5b3) (let __tconst5PoN291 constc85eae03730a4f4cf1d66a0c) (let __tconst2CSv302 const229c0b7aa8a7eb4055f5a3d0) (let __tconst9rZO295 const576506f61f53440f1edd95d2) (let __tconst2Yzp284 const8ca682693a0738a0641c6956)) (probe lambda (1 2 0) 1 __tconst5PoN291 __t30Ec290 __t7aCZ292) (body (exists ref (1 0) 1 __tconst2Yzp284) (exists lambda (1 2 0) 1 __tconst2Yzp284) (exists ref (1 0) 1 __tconst1pJW313) (exists ref (1 0) 1 __tconst9rZO295) (exists lambda (1 2 0) 1 __tconst9rZO295) (exists ref (1 0) 1 __tconst2CSv302) (exists lambda (1 2 0) 1 __tconst2CSv302) (join ref (1 0) 1 __tconst7LWP310 __t91H2298) (exists app (1 2 0) 1 __t91H2298) (join ref (1 0) 1 __tconst2Yzp284 __t248W283) (join lambda (1 2 0) 2 __tconst2Yzp284 __t248W283 __t0oFu285) (join ref (1 0) 1 __tconst1pJW313 __t165O287) (join app (0 1 2) 2 __t30Ec290 __t165O287 dup1Xdo377) (eq __t165O287 dup1Xdo377) (join ref (1 0) 1 __tconst9rZO295 __t71w7294) (join lambda (1 2 0) 2 __tconst9rZO295 __t71w7294 __t3dkk296) (join app (1 2 0) 2 __t91H2298 __t3dkk296 __t4LtH299) (join ref (1 0) 1 __tconst2CSv302 __t6lXa301) (join lambda (1 2 0) 2 __tconst2CSv302 __t6lXa301 __t7EW2303) (join app (1 2 0) 2 __t91H2298 __t7EW2303 __t4HUX306)) (head (mkstruct lambda (1 2 0) __t0vn1308 __tconst0sqO307 __t4HUX306)) mcfa-counting.slog:194 #f)
  class ReadTask841 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** refindex822;  slog::Index** lambdaindex823;  slog::Index** refindex824;  slog::Index** refindex825;  slog::Index** lambdaindex826;  slog::Index** refindex827;  slog::Index** lambdaindex828;  slog::Index** refindex829;  slog::Index** appindex830;  slog::Index** refindex831;  slog::Index** lambdaindex832;  slog::Index** refindex833;  slog::Index** appindex834;  slog::Index** refindex835;  slog::Index** lambdaindex836;  slog::Index** appindex837;  slog::Index** refindex838;  slog::Index** lambdaindex839;  slog::Index** appindex840;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      std::vector<u16> ord842({1, 2, 0});
      slog::Relation* readrel843 = db->getRelation("lambda");
      driver_index = readrel843->getIndex(ord842, true);
      std::vector<u16> ord844({1, 0});
      slog::Relation* readrel845 = db->getRelation("ref");
      refindex822 = readrel845->getIndex(ord844, false);
      std::vector<u16> ord846({1, 2, 0});
      slog::Relation* readrel847 = db->getRelation("lambda");
      lambdaindex823 = readrel847->getIndex(ord846, false);
      std::vector<u16> ord848({1, 0});
      slog::Relation* readrel849 = db->getRelation("ref");
      refindex824 = readrel849->getIndex(ord848, false);
      std::vector<u16> ord850({1, 0});
      slog::Relation* readrel851 = db->getRelation("ref");
      refindex825 = readrel851->getIndex(ord850, false);
      std::vector<u16> ord852({1, 2, 0});
      slog::Relation* readrel853 = db->getRelation("lambda");
      lambdaindex826 = readrel853->getIndex(ord852, false);
      std::vector<u16> ord854({1, 0});
      slog::Relation* readrel855 = db->getRelation("ref");
      refindex827 = readrel855->getIndex(ord854, false);
      std::vector<u16> ord856({1, 2, 0});
      slog::Relation* readrel857 = db->getRelation("lambda");
      lambdaindex828 = readrel857->getIndex(ord856, false);
      std::vector<u16> ord858({1, 0});
      slog::Relation* readrel859 = db->getRelation("ref");
      refindex829 = readrel859->getIndex(ord858, false);
      std::vector<u16> ord860({1, 2, 0});
      slog::Relation* readrel861 = db->getRelation("app");
      appindex830 = readrel861->getIndex(ord860, false);
      std::vector<u16> ord862({1, 0});
      slog::Relation* readrel863 = db->getRelation("ref");
      refindex831 = readrel863->getIndex(ord862, false);
      std::vector<u16> ord864({1, 2, 0});
      slog::Relation* readrel865 = db->getRelation("lambda");
      lambdaindex832 = readrel865->getIndex(ord864, false);
      std::vector<u16> ord866({1, 0});
      slog::Relation* readrel867 = db->getRelation("ref");
      refindex833 = readrel867->getIndex(ord866, false);
      std::vector<u16> ord868({0, 1, 2});
      slog::Relation* readrel869 = db->getRelation("app");
      appindex834 = readrel869->getIndex(ord868, false);
      std::vector<u16> ord870({1, 0});
      slog::Relation* readrel871 = db->getRelation("ref");
      refindex835 = readrel871->getIndex(ord870, false);
      std::vector<u16> ord872({1, 2, 0});
      slog::Relation* readrel873 = db->getRelation("lambda");
      lambdaindex836 = readrel873->getIndex(ord872, false);
      std::vector<u16> ord874({1, 2, 0});
      slog::Relation* readrel875 = db->getRelation("app");
      appindex837 = readrel875->getIndex(ord874, false);
      std::vector<u16> ord876({1, 0});
      slog::Relation* readrel877 = db->getRelation("ref");
      refindex838 = readrel877->getIndex(ord876, false);
      std::vector<u16> ord878({1, 2, 0});
      slog::Relation* readrel879 = db->getRelation("lambda");
      lambdaindex839 = readrel879->getIndex(ord878, false);
      std::vector<u16> ord880({1, 2, 0});
      slog::Relation* readrel881 = db->getRelation("app");
      appindex840 = readrel881->getIndex(ord880, false);
  
    }
    ReadTask841(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c80 = v_constb49bea2fcccd8f4301a347ed;
      u64 v_c81 = v_const66518c0c1b3a5a0b09ae2ef1;
      u64 v_c82 = v_const4a8acfc71441e0695ffcf5b3;
      u64 v_c83 = v_constc85eae03730a4f4cf1d66a0c;
      u64 v_c85 = v_const229c0b7aa8a7eb4055f5a3d0;
      u64 v_c86 = v_const576506f61f53440f1edd95d2;
      u64 v_c84 = v_const8ca682693a0738a0641c6956;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c83, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m882) {
        u64 v_c99 = m882[1];
        u64 v_c100 = m882[2];
        if (buckethash(v_c99) != bucket) return;
        if (!slog::exists_probe<2,1>(refindex822, std::array<u64,2>{v_c84, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex823, std::array<u64,3>{v_c84, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex824, std::array<u64,2>{v_c80, 0})) return;
        if (!slog::exists_probe<2,1>(refindex825, std::array<u64,2>{v_c86, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex826, std::array<u64,3>{v_c86, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex827, std::array<u64,2>{v_c85, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex828, std::array<u64,3>{v_c85, 0, 0})) return;
        slog::join_probe<2,1>(refindex829, std::array<u64,2>{v_c81, 0}, [&](const std::array<u64,2>& m883) {
          u64 v_c89 = m883[1];
          if (!slog::exists_probe<3,1>(appindex830, std::array<u64,3>{v_c89, 0, 0})) return;
          slog::join_probe<2,1>(refindex831, std::array<u64,2>{v_c84, 0}, [&](const std::array<u64,2>& m884) {
            u64 v_c92 = m884[1];
            slog::join_probe<3,2>(lambdaindex832, std::array<u64,3>{v_c84, v_c92, 0}, [&](const std::array<u64,3>& m885) {
              u64 v_c93 = m885[2];
              slog::join_probe<2,1>(refindex833, std::array<u64,2>{v_c80, 0}, [&](const std::array<u64,2>& m886) {
                u64 v_c94 = m886[1];
                slog::join_probe<3,2>(appindex834, std::array<u64,3>{v_c99, v_c94, 0}, [&](const std::array<u64,3>& m887) {
                  u64 v_c156 = m887[2];
                  if (v_c94 != v_c156) return;
                  slog::join_probe<2,1>(refindex835, std::array<u64,2>{v_c86, 0}, [&](const std::array<u64,2>& m888) {
                    u64 v_c95 = m888[1];
                    slog::join_probe<3,2>(lambdaindex836, std::array<u64,3>{v_c86, v_c95, 0}, [&](const std::array<u64,3>& m889) {
                      u64 v_c96 = m889[2];
                      slog::join_probe<3,2>(appindex837, std::array<u64,3>{v_c89, v_c96, 0}, [&](const std::array<u64,3>& m890) {
                        u64 v_c97 = m890[2];
                        slog::join_probe<2,1>(refindex838, std::array<u64,2>{v_c85, 0}, [&](const std::array<u64,2>& m891) {
                          u64 v_c91 = m891[1];
                          slog::join_probe<3,2>(lambdaindex839, std::array<u64,3>{v_c85, v_c91, 0}, [&](const std::array<u64,3>& m892) {
                            u64 v_c90 = m892[2];
                            slog::join_probe<3,2>(appindex840, std::array<u64,3>{v_c89, v_c90, 0}, [&](const std::array<u64,3>& m893) {
                              u64 v_c87 = m893[2];
                              ++_fires;
                              slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c82, v_c87}, std::array<u16,3>{1, 2, 0});
                            });
                          });
                        });
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
        ReadTask841* _cont = new ReadTask841(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask841(db,b), false);
  // (crule (pre (let __trid2dX2349 const8d8bcc50ea388ca2a2cd3f92) (let __trel1hBV350 const3f20de5ef71f7ccc981391b7) (let __tcol61w5351 const5feceb66ffc86f38d952786c)) (scan eval __t3GAu9 __t3mrW8 c) (body (join lambda (0 1 2) 1 __t3mrW8 x eb)) (head (tycheck __t3mrW8 (accept (struct lambda)) __trid2dX2349 __trel1hBV350 __tcol61w5351 (1 2 3 4 0)) (emit-temp temp0sJH415 __t3GAu9 __t3mrW8 c) (mkstruct clo (1 2 0) __t4Sp77 __t3mrW8 c)) mcfa-counting.slog:78 #f)
  class ReadTask896 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lambdaindex894;
    u32 sid895;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("temp0sJH415");
      head_rel[2] = db->getRelation("clo");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord897({0, 1, 2});
      slog::Relation* readrel898 = db->getRelation("lambda");
      lambdaindex894 = readrel898->getIndex(ord897, false);
      sid895 = db->getRelation("lambda")->getStructId();
  
    }
    ReadTask896(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c157 = v_const8d8bcc50ea388ca2a2cd3f92;
      u64 v_c158 = v_const3f20de5ef71f7ccc981391b7;
      u64 v_c159 = v_const5feceb66ffc86f38d952786c;
  
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
        u64 v_c160 = _t[0];
        u64 v_c161 = _t[1];
        u64 v_c70 = _t[2];
        slog::join_probe<3,1>(lambdaindex894, std::array<u64,3>{v_c161, 0, 0}, [&](const std::array<u64,3>& m899) {
          u64 v_c78 = m899[1]; u64 v_c79 = m899[2];
          ++_fires;
          if (!((is_struct(v_c161) && (decode_struct_id(v_c161) == sid895))))
          {
            slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c157, v_c158, v_c159, v_c161}, std::array<u16,5>{1, 2, 3, 4, 0});
            return;
          }
          slog::emit_temp<3>(head_rel[1], newbatch[1], std::array<u64,3>{v_c160, v_c161, v_c70});
          slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c161, v_c70}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:78", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask896* _cont = new ReadTask896(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask896(db,b), false);
  // (crule (pre (let __tconst0ZcM213 constfc9ee54e0ee8c6d1e715716c) (let __tconst5Fqn220 const15bb62b8293a526ca6f0e4eb) (let __tconst9TQS210 const5950e3cb761734f52a881545) (let __tconst1wsq203 const77ceb5c0e9f84ebd84104a97)) (seeded) (body (join ref (1 0) 1 __tconst5Fqn220 __t2V0C216) (exists lambda (1 2 0) 1 __tconst1wsq203) (exists ref (1 0) 1 __tconst0ZcM213) (exists app (1 2 0) 1 __t2V0C216) (exists lambda (1 2 0) 1 __tconst5Fqn220) (exists lambda (1 2 0) 1 __tconst9TQS210) (exists lambda (1 2 0) 1 __tconst0ZcM213) (join ref (1 0) 1 __tconst1wsq203 __t6pkv202) (join lambda (1 2 0) 2 __tconst1wsq203 __t6pkv202 __t118D204) (exists app (2 0 1) 1 __t118D204) (join ref (1 0) 1 __tconst0ZcM213 __t6fYg206) (exists app (1 2 0) 1 __t6fYg206) (join app (1 2 0) 1 __t2V0C216 dup8u8a435 __t9nSF219) (eq __t2V0C216 dup8u8a435) (join lambda (1 2 0) 2 __tconst5Fqn220 __t9nSF219 __t6h87221) (exists app (1 2 0) 1 __t6h87221) (join app (1 2 0) 1 __t6fYg206 dup2tzt436 __t1W86209) (eq __t6fYg206 dup2tzt436) (join lambda (1 2 0) 2 __tconst9TQS210 __t1W86209 __t1wmd211) (join app (1 2 0) 2 __t1wmd211 __t118D204 __t4jAx212) (join lambda (1 2 0) 2 __tconst0ZcM213 __t4jAx212 __t14ld214) (join app (1 2 0) 2 __t6h87221 __t14ld214 __t4RlI222)) (head (emit program (0) __t4RlI222)) mcfa-counting.slog:211 #f)
  class ReadTask920 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex900;  slog::Index** lambdaindex901;  slog::Index** refindex902;  slog::Index** appindex903;  slog::Index** lambdaindex904;  slog::Index** lambdaindex905;  slog::Index** lambdaindex906;  slog::Index** refindex907;  slog::Index** lambdaindex908;  slog::Index** appindex909;  slog::Index** refindex910;  slog::Index** appindex911;  slog::Index** appindex912;  slog::Index** lambdaindex913;  slog::Index** appindex914;  slog::Index** appindex915;  slog::Index** lambdaindex916;  slog::Index** appindex917;  slog::Index** lambdaindex918;  slog::Index** appindex919;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("program");
      std::vector<u16> ord921({0});
      slog::Relation* readrel922 = db->getRelation("program");
      head_index[0] = readrel922->getIndex(ord921, false);
      std::vector<u16> ord923({1, 0});
      slog::Relation* readrel924 = db->getRelation("ref");
      refindex900 = readrel924->getIndex(ord923, false);
      std::vector<u16> ord925({1, 2, 0});
      slog::Relation* readrel926 = db->getRelation("lambda");
      lambdaindex901 = readrel926->getIndex(ord925, false);
      std::vector<u16> ord927({1, 0});
      slog::Relation* readrel928 = db->getRelation("ref");
      refindex902 = readrel928->getIndex(ord927, false);
      std::vector<u16> ord929({1, 2, 0});
      slog::Relation* readrel930 = db->getRelation("app");
      appindex903 = readrel930->getIndex(ord929, false);
      std::vector<u16> ord931({1, 2, 0});
      slog::Relation* readrel932 = db->getRelation("lambda");
      lambdaindex904 = readrel932->getIndex(ord931, false);
      std::vector<u16> ord933({1, 2, 0});
      slog::Relation* readrel934 = db->getRelation("lambda");
      lambdaindex905 = readrel934->getIndex(ord933, false);
      std::vector<u16> ord935({1, 2, 0});
      slog::Relation* readrel936 = db->getRelation("lambda");
      lambdaindex906 = readrel936->getIndex(ord935, false);
      std::vector<u16> ord937({1, 0});
      slog::Relation* readrel938 = db->getRelation("ref");
      refindex907 = readrel938->getIndex(ord937, false);
      std::vector<u16> ord939({1, 2, 0});
      slog::Relation* readrel940 = db->getRelation("lambda");
      lambdaindex908 = readrel940->getIndex(ord939, false);
      std::vector<u16> ord941({2, 0, 1});
      slog::Relation* readrel942 = db->getRelation("app");
      appindex909 = readrel942->getIndex(ord941, false);
      std::vector<u16> ord943({1, 0});
      slog::Relation* readrel944 = db->getRelation("ref");
      refindex910 = readrel944->getIndex(ord943, false);
      std::vector<u16> ord945({1, 2, 0});
      slog::Relation* readrel946 = db->getRelation("app");
      appindex911 = readrel946->getIndex(ord945, false);
      std::vector<u16> ord947({1, 2, 0});
      slog::Relation* readrel948 = db->getRelation("app");
      appindex912 = readrel948->getIndex(ord947, false);
      std::vector<u16> ord949({1, 2, 0});
      slog::Relation* readrel950 = db->getRelation("lambda");
      lambdaindex913 = readrel950->getIndex(ord949, false);
      std::vector<u16> ord951({1, 2, 0});
      slog::Relation* readrel952 = db->getRelation("app");
      appindex914 = readrel952->getIndex(ord951, false);
      std::vector<u16> ord953({1, 2, 0});
      slog::Relation* readrel954 = db->getRelation("app");
      appindex915 = readrel954->getIndex(ord953, false);
      std::vector<u16> ord955({1, 2, 0});
      slog::Relation* readrel956 = db->getRelation("lambda");
      lambdaindex916 = readrel956->getIndex(ord955, false);
      std::vector<u16> ord957({1, 2, 0});
      slog::Relation* readrel958 = db->getRelation("app");
      appindex917 = readrel958->getIndex(ord957, false);
      std::vector<u16> ord959({1, 2, 0});
      slog::Relation* readrel960 = db->getRelation("lambda");
      lambdaindex918 = readrel960->getIndex(ord959, false);
      std::vector<u16> ord961({1, 2, 0});
      slog::Relation* readrel962 = db->getRelation("app");
      appindex919 = readrel962->getIndex(ord961, false);
  
    }
    ReadTask920(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c5 = v_constfc9ee54e0ee8c6d1e715716c;
      u64 v_c4 = v_const15bb62b8293a526ca6f0e4eb;
      u64 v_c6 = v_const5950e3cb761734f52a881545;
      u64 v_c7 = v_const77ceb5c0e9f84ebd84104a97;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex900, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m963) {
        u64 v_c11 = m963[1];
        if (!slog::exists_probe<3,1>(lambdaindex901, std::array<u64,3>{v_c7, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex902, std::array<u64,2>{v_c5, 0})) return;
        if (!slog::exists_probe<3,1>(appindex903, std::array<u64,3>{v_c11, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex904, std::array<u64,3>{v_c4, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex905, std::array<u64,3>{v_c6, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex906, std::array<u64,3>{v_c5, 0, 0})) return;
        slog::join_probe<2,1>(refindex907, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m964) {
          u64 v_c8 = m964[1];
          slog::join_probe<3,2>(lambdaindex908, std::array<u64,3>{v_c7, v_c8, 0}, [&](const std::array<u64,3>& m965) {
            u64 v_c9 = m965[2];
            if (!slog::exists_probe<3,1>(appindex909, std::array<u64,3>{v_c9, 0, 0})) return;
            slog::join_probe<2,1>(refindex910, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m966) {
              u64 v_c10 = m966[1];
              if (!slog::exists_probe<3,1>(appindex911, std::array<u64,3>{v_c10, 0, 0})) return;
              slog::join_probe<3,1>(appindex912, std::array<u64,3>{v_c11, 0, 0}, [&](const std::array<u64,3>& m967) {
                u64 v_c162 = m967[1]; u64 v_c15 = m967[2];
                if (v_c11 != v_c162) return;
                slog::join_probe<3,2>(lambdaindex913, std::array<u64,3>{v_c4, v_c15, 0}, [&](const std::array<u64,3>& m968) {
                  u64 v_c163 = m968[2];
                  if (!slog::exists_probe<3,1>(appindex914, std::array<u64,3>{v_c163, 0, 0})) return;
                  slog::join_probe<3,1>(appindex915, std::array<u64,3>{v_c10, 0, 0}, [&](const std::array<u64,3>& m969) {
                    u64 v_c164 = m969[1]; u64 v_c13 = m969[2];
                    if (v_c10 != v_c164) return;
                    slog::join_probe<3,2>(lambdaindex916, std::array<u64,3>{v_c6, v_c13, 0}, [&](const std::array<u64,3>& m970) {
                      u64 v_c165 = m970[2];
                      slog::join_probe<3,2>(appindex917, std::array<u64,3>{v_c165, v_c9, 0}, [&](const std::array<u64,3>& m971) {
                        u64 v_c166 = m971[2];
                        slog::join_probe<3,2>(lambdaindex918, std::array<u64,3>{v_c5, v_c166, 0}, [&](const std::array<u64,3>& m972) {
                          u64 v_c167 = m972[2];
                          slog::join_probe<3,2>(appindex919, std::array<u64,3>{v_c163, v_c167, 0}, [&](const std::array<u64,3>& m973) {
                            u64 v_c168 = m973[2];
                            ++_fires;
                            slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c168}, std::array<u16,1>{0});
                          });
                        });
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
      s->addTaskSeeded(phase_read, new ReadTask920(db,b));
  // (crule (pre (let __tconst1pJW313 constb49bea2fcccd8f4301a347ed) (let __tconst7LWP310 const66518c0c1b3a5a0b09ae2ef1) (let __tconst0sqO307 const4a8acfc71441e0695ffcf5b3) (let __tconst2CSv302 const229c0b7aa8a7eb4055f5a3d0) (let __tconst9rZO295 const576506f61f53440f1edd95d2) (let __tconst5PoN291 constc85eae03730a4f4cf1d66a0c) (let __tconst2Yzp284 const8ca682693a0738a0641c6956)) (probe lambda (1 2 0) 1 __tconst2Yzp284 __t248W283 __t0oFu285) (body (join ref (0 1) 2 __t248W283 __tconst2Yzp284) (exists ref (1 0) 1 __tconst9rZO295) (exists lambda (1 2 0) 1 __tconst9rZO295) (exists ref (1 0) 1 __tconst7LWP310) (exists ref (1 0) 1 __tconst2CSv302) (exists lambda (1 2 0) 1 __tconst2CSv302) (join ref (1 0) 1 __tconst1pJW313 __t165O287) (exists app (1 2 0) 1 __t165O287) (join ref (1 0) 1 __tconst9rZO295 __t71w7294) (join lambda (1 2 0) 2 __tconst9rZO295 __t71w7294 __t3dkk296) (join ref (1 0) 1 __tconst7LWP310 __t91H2298) (join ref (1 0) 1 __tconst2CSv302 __t6lXa301) (join lambda (1 2 0) 2 __tconst2CSv302 __t6lXa301 __t7EW2303) (join app (1 2 0) 1 __t165O287 dup4A5M375 __t30Ec290) (eq __t165O287 dup4A5M375)) (head (mkstruct app (1 2 0) __t4HUX306 __t91H2298 __t7EW2303) (mkstruct app (1 2 0) __t4LtH299 __t91H2298 __t3dkk296) (mkstruct lambda (1 2 0) __t7aCZ292 __tconst5PoN291 __t30Ec290)) mcfa-counting.slog:194 #f)
  class ReadTask988 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** refindex974;  slog::Index** refindex975;  slog::Index** lambdaindex976;  slog::Index** refindex977;  slog::Index** refindex978;  slog::Index** lambdaindex979;  slog::Index** refindex980;  slog::Index** appindex981;  slog::Index** refindex982;  slog::Index** lambdaindex983;  slog::Index** refindex984;  slog::Index** refindex985;  slog::Index** lambdaindex986;  slog::Index** appindex987;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      head_rel[1] = db->getRelation("app");
      head_rel[2] = db->getRelation("lambda");
      std::vector<u16> ord989({1, 2, 0});
      slog::Relation* readrel990 = db->getRelation("lambda");
      driver_index = readrel990->getIndex(ord989, true);
      std::vector<u16> ord991({0, 1});
      slog::Relation* readrel992 = db->getRelation("ref");
      refindex974 = readrel992->getIndex(ord991, false);
      std::vector<u16> ord993({1, 0});
      slog::Relation* readrel994 = db->getRelation("ref");
      refindex975 = readrel994->getIndex(ord993, false);
      std::vector<u16> ord995({1, 2, 0});
      slog::Relation* readrel996 = db->getRelation("lambda");
      lambdaindex976 = readrel996->getIndex(ord995, false);
      std::vector<u16> ord997({1, 0});
      slog::Relation* readrel998 = db->getRelation("ref");
      refindex977 = readrel998->getIndex(ord997, false);
      std::vector<u16> ord999({1, 0});
      slog::Relation* readrel1000 = db->getRelation("ref");
      refindex978 = readrel1000->getIndex(ord999, false);
      std::vector<u16> ord1001({1, 2, 0});
      slog::Relation* readrel1002 = db->getRelation("lambda");
      lambdaindex979 = readrel1002->getIndex(ord1001, false);
      std::vector<u16> ord1003({1, 0});
      slog::Relation* readrel1004 = db->getRelation("ref");
      refindex980 = readrel1004->getIndex(ord1003, false);
      std::vector<u16> ord1005({1, 2, 0});
      slog::Relation* readrel1006 = db->getRelation("app");
      appindex981 = readrel1006->getIndex(ord1005, false);
      std::vector<u16> ord1007({1, 0});
      slog::Relation* readrel1008 = db->getRelation("ref");
      refindex982 = readrel1008->getIndex(ord1007, false);
      std::vector<u16> ord1009({1, 2, 0});
      slog::Relation* readrel1010 = db->getRelation("lambda");
      lambdaindex983 = readrel1010->getIndex(ord1009, false);
      std::vector<u16> ord1011({1, 0});
      slog::Relation* readrel1012 = db->getRelation("ref");
      refindex984 = readrel1012->getIndex(ord1011, false);
      std::vector<u16> ord1013({1, 0});
      slog::Relation* readrel1014 = db->getRelation("ref");
      refindex985 = readrel1014->getIndex(ord1013, false);
      std::vector<u16> ord1015({1, 2, 0});
      slog::Relation* readrel1016 = db->getRelation("lambda");
      lambdaindex986 = readrel1016->getIndex(ord1015, false);
      std::vector<u16> ord1017({1, 2, 0});
      slog::Relation* readrel1018 = db->getRelation("app");
      appindex987 = readrel1018->getIndex(ord1017, false);
  
    }
    ReadTask988(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c80 = v_constb49bea2fcccd8f4301a347ed;
      u64 v_c81 = v_const66518c0c1b3a5a0b09ae2ef1;
      u64 v_c82 = v_const4a8acfc71441e0695ffcf5b3;
      u64 v_c85 = v_const229c0b7aa8a7eb4055f5a3d0;
      u64 v_c86 = v_const576506f61f53440f1edd95d2;
      u64 v_c83 = v_constc85eae03730a4f4cf1d66a0c;
      u64 v_c84 = v_const8ca682693a0738a0641c6956;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c84, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1019) {
        u64 v_c92 = m1019[1];
        u64 v_c93 = m1019[2];
        if (buckethash(v_c92) != bucket) return;
        slog::join_probe<2,2>(refindex974, std::array<u64,2>{v_c92, v_c84}, [&](const std::array<u64,2>& m1020) {
          if (!slog::exists_probe<2,1>(refindex975, std::array<u64,2>{v_c86, 0})) return;
          if (!slog::exists_probe<3,1>(lambdaindex976, std::array<u64,3>{v_c86, 0, 0})) return;
          if (!slog::exists_probe<2,1>(refindex977, std::array<u64,2>{v_c81, 0})) return;
          if (!slog::exists_probe<2,1>(refindex978, std::array<u64,2>{v_c85, 0})) return;
          if (!slog::exists_probe<3,1>(lambdaindex979, std::array<u64,3>{v_c85, 0, 0})) return;
          slog::join_probe<2,1>(refindex980, std::array<u64,2>{v_c80, 0}, [&](const std::array<u64,2>& m1021) {
            u64 v_c94 = m1021[1];
            if (!slog::exists_probe<3,1>(appindex981, std::array<u64,3>{v_c94, 0, 0})) return;
            slog::join_probe<2,1>(refindex982, std::array<u64,2>{v_c86, 0}, [&](const std::array<u64,2>& m1022) {
              u64 v_c95 = m1022[1];
              slog::join_probe<3,2>(lambdaindex983, std::array<u64,3>{v_c86, v_c95, 0}, [&](const std::array<u64,3>& m1023) {
                u64 v_c96 = m1023[2];
                slog::join_probe<2,1>(refindex984, std::array<u64,2>{v_c81, 0}, [&](const std::array<u64,2>& m1024) {
                  u64 v_c89 = m1024[1];
                  slog::join_probe<2,1>(refindex985, std::array<u64,2>{v_c85, 0}, [&](const std::array<u64,2>& m1025) {
                    u64 v_c91 = m1025[1];
                    slog::join_probe<3,2>(lambdaindex986, std::array<u64,3>{v_c85, v_c91, 0}, [&](const std::array<u64,3>& m1026) {
                      u64 v_c90 = m1026[2];
                      slog::join_probe<3,1>(appindex987, std::array<u64,3>{v_c94, 0, 0}, [&](const std::array<u64,3>& m1027) {
                        u64 v_c169 = m1027[1]; u64 v_c99 = m1027[2];
                        if (v_c94 != v_c169) return;
                        ++_fires;
                        slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c89, v_c90}, std::array<u16,3>{1, 2, 0});
                        slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c89, v_c96}, std::array<u16,3>{1, 2, 0});
                        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c83, v_c99}, std::array<u16,3>{1, 2, 0});
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
  
      if (_fires) db->bumpFires("mcfa-counting.slog:194", "delta:lambda", _fires);
  
      if (!_done)
      {
        ReadTask988* _cont = new ReadTask988(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask988(db,b), false);
  // (crule (pre) (scan lambda __t4JNf263 x eb) (body (exists clo (1 2 0) 1 __t4JNf263) (join freevar (1 0) 1 __t4JNf263 y) (join store (0 1 2) 1 y cb vy) (join clo (1 2 0) 2 __t4JNf263 cb __t0zen261) (join eval_ans (1 0) 1 __t0zen261 __t7ceq259) (join eval (0 2 1) 1 __t7ceq259 c ef) (exists app (1 2 0) 1 ef) (exists eval (2 0 1) 1 c) (join eval (2 0 1) 1 c __5DEq344 __t6ooL258) (join app (0 1 2) 2 __t6ooL258 ef ea) (join eval (1 2 0) 2 ea c __t2S0s262) (join eval_ans (0 1) 1 __t2S0s262 va)) (head (emit store (0 1 2) y __t6ooL258 vy) (emit bindev (0 1 2) y __t6ooL258 c)) mcfa-counting.slog:102 #f)
  class ReadTask1040 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** cloindex1028;  slog::Index** freevarindex1029;  slog::Index** storeindex1030;  slog::Index** cloindex1031;  slog::Index** eval_ansindex1032;  slog::Index** evalindex1033;  slog::Index** appindex1034;  slog::Index** evalindex1035;  slog::Index** evalindex1036;  slog::Index** appindex1037;  slog::Index** evalindex1038;  slog::Index** eval_ansindex1039;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("store");
      std::vector<u16> ord1041({0, 1, 2});
      slog::Relation* readrel1042 = db->getRelation("store");
      head_index[0] = readrel1042->getIndex(ord1041, false);
      head_rel[1] = db->getRelation("bindev");
      std::vector<u16> ord1043({0, 1, 2});
      slog::Relation* readrel1044 = db->getRelation("bindev");
      head_index[1] = readrel1044->getIndex(ord1043, false);
      outer_rel = db->getRelation("lambda");
      std::vector<u16> ord1045({1, 2, 0});
      slog::Relation* readrel1046 = db->getRelation("clo");
      cloindex1028 = readrel1046->getIndex(ord1045, false);
      std::vector<u16> ord1047({1, 0});
      slog::Relation* readrel1048 = db->getRelation("freevar");
      freevarindex1029 = readrel1048->getIndex(ord1047, false);
      std::vector<u16> ord1049({0, 1, 2});
      slog::Relation* readrel1050 = db->getRelation("store");
      storeindex1030 = readrel1050->getIndex(ord1049, false);
      std::vector<u16> ord1051({1, 2, 0});
      slog::Relation* readrel1052 = db->getRelation("clo");
      cloindex1031 = readrel1052->getIndex(ord1051, false);
      std::vector<u16> ord1053({1, 0});
      slog::Relation* readrel1054 = db->getRelation("eval_ans");
      eval_ansindex1032 = readrel1054->getIndex(ord1053, false);
      std::vector<u16> ord1055({0, 2, 1});
      slog::Relation* readrel1056 = db->getRelation("eval");
      evalindex1033 = readrel1056->getIndex(ord1055, false);
      std::vector<u16> ord1057({1, 2, 0});
      slog::Relation* readrel1058 = db->getRelation("app");
      appindex1034 = readrel1058->getIndex(ord1057, false);
      std::vector<u16> ord1059({2, 0, 1});
      slog::Relation* readrel1060 = db->getRelation("eval");
      evalindex1035 = readrel1060->getIndex(ord1059, false);
      std::vector<u16> ord1061({2, 0, 1});
      slog::Relation* readrel1062 = db->getRelation("eval");
      evalindex1036 = readrel1062->getIndex(ord1061, false);
      std::vector<u16> ord1063({0, 1, 2});
      slog::Relation* readrel1064 = db->getRelation("app");
      appindex1037 = readrel1064->getIndex(ord1063, false);
      std::vector<u16> ord1065({1, 2, 0});
      slog::Relation* readrel1066 = db->getRelation("eval");
      evalindex1038 = readrel1066->getIndex(ord1065, false);
      std::vector<u16> ord1067({0, 1});
      slog::Relation* readrel1068 = db->getRelation("eval_ans");
      eval_ansindex1039 = readrel1068->getIndex(ord1067, false);
  
    }
    ReadTask1040(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c170 = _t[0];
        u64 v_c78 = _t[1];
        u64 v_c79 = _t[2];
        if (!slog::exists_probe<3,1>(cloindex1028, std::array<u64,3>{v_c170, 0, 0})) return;
        slog::join_probe<2,1>(freevarindex1029, std::array<u64,2>{v_c170, 0}, [&](const std::array<u64,2>& m1069) {
          u64 v_c123 = m1069[1];
          slog::join_probe<3,1>(storeindex1030, std::array<u64,3>{v_c123, 0, 0}, [&](const std::array<u64,3>& m1070) {
            u64 v_c76 = m1070[1]; u64 v_c124 = m1070[2];
            slog::join_probe<3,2>(cloindex1031, std::array<u64,3>{v_c170, v_c76, 0}, [&](const std::array<u64,3>& m1071) {
              u64 v_c171 = m1071[2];
              slog::join_probe<2,1>(eval_ansindex1032, std::array<u64,2>{v_c171, 0}, [&](const std::array<u64,2>& m1072) {
                u64 v_c172 = m1072[1];
                slog::join_probe<3,1>(evalindex1033, std::array<u64,3>{v_c172, 0, 0}, [&](const std::array<u64,3>& m1073) {
                  u64 v_c70 = m1073[1]; u64 v_c68 = m1073[2];
                  if (!slog::exists_probe<3,1>(appindex1034, std::array<u64,3>{v_c68, 0, 0})) return;
                  if (!slog::exists_probe<3,1>(evalindex1035, std::array<u64,3>{v_c70, 0, 0})) return;
                  slog::join_probe<3,1>(evalindex1036, std::array<u64,3>{v_c70, 0, 0}, [&](const std::array<u64,3>& m1074) {
                    u64 v_c173 = m1074[1]; u64 v_c174 = m1074[2];
                    slog::join_probe<3,2>(appindex1037, std::array<u64,3>{v_c174, v_c68, 0}, [&](const std::array<u64,3>& m1075) {
                      u64 v_c69 = m1075[2];
                      slog::join_probe<3,2>(evalindex1038, std::array<u64,3>{v_c69, v_c70, 0}, [&](const std::array<u64,3>& m1076) {
                        u64 v_c175 = m1076[2];
                        slog::join_probe<2,1>(eval_ansindex1039, std::array<u64,2>{v_c175, 0}, [&](const std::array<u64,2>& m1077) {
                          u64 v_c75 = m1077[1];
                          ++_fires;
                          slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c123, v_c174, v_c124}, std::array<u16,3>{0, 1, 2});
                          slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c123, v_c174, v_c70}, std::array<u16,3>{0, 1, 2});
                        });
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
  
      if (_fires) db->bumpFires("mcfa-counting.slog:102", "delta:lambda", _fires);
  
      if (!_done)
      {
        ReadTask1040* _cont = new ReadTask1040(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1040(db,b), false);
  // (crule (pre) (scan ref __t7pMH77 x) (body) (head (emit freevar (0 1) x __t7pMH77)) freevars.slog:9 #f)
  class ReadTask1078 : public slog::Task
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
      head_rel[0] = db->getRelation("freevar");
      std::vector<u16> ord1079({0, 1});
      slog::Relation* readrel1080 = db->getRelation("freevar");
      head_index[0] = readrel1080->getIndex(ord1079, false);
      outer_rel = db->getRelation("ref");
  
    }
    ReadTask1078(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c176 = _t[0];
        u64 v_c78 = _t[1];
        ++_fires;
        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c78, v_c176}, std::array<u16,2>{0, 1});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:9", "delta:ref", _fires);
  
      if (!_done)
      {
        ReadTask1078* _cont = new ReadTask1078(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1078(db,b), false);
  // (crule (pre (let __tconst2ady176 constc40f204dda7ba4054abb9e74) (let __tconst7JVW192 const6cf13cc59dcbe759113f68a4) (let __tconst5wC2180 const970c20ea81b833e5b5a7accf) (let __tconst7B9N190 constcaa3ee5a2828a31924f6b39d)) (seeded) (body (join ref (1 0) 1 __tconst2ady176 __t3ZY4175) (exists ref (1 0) 1 __tconst5wC2180) (exists lambda (1 2 0) 1 __tconst5wC2180) (exists ref (1 0) 1 __tconst7JVW192) (exists ref (1 0) 1 __tconst7B9N190) (exists lambda (1 2 0) 1 __tconst7B9N190) (exists lambda (1 2 0) 1 __tconst7JVW192) (join lambda (1 2 0) 2 __tconst2ady176 __t3ZY4175 __t1Ls4177) (exists app (2 0 1) 1 __t1Ls4177) (join ref (1 0) 1 __tconst5wC2180 __t52sB179) (join lambda (1 2 0) 2 __tconst5wC2180 __t52sB179 __t6CST181) (exists app (2 0 1) 1 __t6CST181) (join ref (1 0) 1 __tconst7JVW192 __t6fOY185) (exists app (1 2 0) 1 __t6fOY185) (join ref (1 0) 1 __tconst7B9N190 __t8oRJ183) (join app (1 2 0) 2 __t6fOY185 __t8oRJ183 __t2CTd186) (join app (1 2 0) 2 __t6fOY185 __t2CTd186 __t9pbS189) (join lambda (1 2 0) 2 __tconst7B9N190 __t9pbS189 __t6W4v191) (join lambda (1 2 0) 2 __tconst7JVW192 __t6W4v191 __t6Vw9193) (join app (1 2 0) 2 __t6Vw9193 __t6CST181 __t5jf3194) (join app (1 2 0) 2 __t5jf3194 __t1Ls4177 __t3W4r195)) (head (emit program (0) __t3W4r195)) mcfa-counting.slog:301 #f)
  class ReadTask1102 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex1081;  slog::Index** refindex1082;  slog::Index** lambdaindex1083;  slog::Index** refindex1084;  slog::Index** refindex1085;  slog::Index** lambdaindex1086;  slog::Index** lambdaindex1087;  slog::Index** lambdaindex1088;  slog::Index** appindex1089;  slog::Index** refindex1090;  slog::Index** lambdaindex1091;  slog::Index** appindex1092;  slog::Index** refindex1093;  slog::Index** appindex1094;  slog::Index** refindex1095;  slog::Index** appindex1096;  slog::Index** appindex1097;  slog::Index** lambdaindex1098;  slog::Index** lambdaindex1099;  slog::Index** appindex1100;  slog::Index** appindex1101;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("program");
      std::vector<u16> ord1103({0});
      slog::Relation* readrel1104 = db->getRelation("program");
      head_index[0] = readrel1104->getIndex(ord1103, false);
      std::vector<u16> ord1105({1, 0});
      slog::Relation* readrel1106 = db->getRelation("ref");
      refindex1081 = readrel1106->getIndex(ord1105, false);
      std::vector<u16> ord1107({1, 0});
      slog::Relation* readrel1108 = db->getRelation("ref");
      refindex1082 = readrel1108->getIndex(ord1107, false);
      std::vector<u16> ord1109({1, 2, 0});
      slog::Relation* readrel1110 = db->getRelation("lambda");
      lambdaindex1083 = readrel1110->getIndex(ord1109, false);
      std::vector<u16> ord1111({1, 0});
      slog::Relation* readrel1112 = db->getRelation("ref");
      refindex1084 = readrel1112->getIndex(ord1111, false);
      std::vector<u16> ord1113({1, 0});
      slog::Relation* readrel1114 = db->getRelation("ref");
      refindex1085 = readrel1114->getIndex(ord1113, false);
      std::vector<u16> ord1115({1, 2, 0});
      slog::Relation* readrel1116 = db->getRelation("lambda");
      lambdaindex1086 = readrel1116->getIndex(ord1115, false);
      std::vector<u16> ord1117({1, 2, 0});
      slog::Relation* readrel1118 = db->getRelation("lambda");
      lambdaindex1087 = readrel1118->getIndex(ord1117, false);
      std::vector<u16> ord1119({1, 2, 0});
      slog::Relation* readrel1120 = db->getRelation("lambda");
      lambdaindex1088 = readrel1120->getIndex(ord1119, false);
      std::vector<u16> ord1121({2, 0, 1});
      slog::Relation* readrel1122 = db->getRelation("app");
      appindex1089 = readrel1122->getIndex(ord1121, false);
      std::vector<u16> ord1123({1, 0});
      slog::Relation* readrel1124 = db->getRelation("ref");
      refindex1090 = readrel1124->getIndex(ord1123, false);
      std::vector<u16> ord1125({1, 2, 0});
      slog::Relation* readrel1126 = db->getRelation("lambda");
      lambdaindex1091 = readrel1126->getIndex(ord1125, false);
      std::vector<u16> ord1127({2, 0, 1});
      slog::Relation* readrel1128 = db->getRelation("app");
      appindex1092 = readrel1128->getIndex(ord1127, false);
      std::vector<u16> ord1129({1, 0});
      slog::Relation* readrel1130 = db->getRelation("ref");
      refindex1093 = readrel1130->getIndex(ord1129, false);
      std::vector<u16> ord1131({1, 2, 0});
      slog::Relation* readrel1132 = db->getRelation("app");
      appindex1094 = readrel1132->getIndex(ord1131, false);
      std::vector<u16> ord1133({1, 0});
      slog::Relation* readrel1134 = db->getRelation("ref");
      refindex1095 = readrel1134->getIndex(ord1133, false);
      std::vector<u16> ord1135({1, 2, 0});
      slog::Relation* readrel1136 = db->getRelation("app");
      appindex1096 = readrel1136->getIndex(ord1135, false);
      std::vector<u16> ord1137({1, 2, 0});
      slog::Relation* readrel1138 = db->getRelation("app");
      appindex1097 = readrel1138->getIndex(ord1137, false);
      std::vector<u16> ord1139({1, 2, 0});
      slog::Relation* readrel1140 = db->getRelation("lambda");
      lambdaindex1098 = readrel1140->getIndex(ord1139, false);
      std::vector<u16> ord1141({1, 2, 0});
      slog::Relation* readrel1142 = db->getRelation("lambda");
      lambdaindex1099 = readrel1142->getIndex(ord1141, false);
      std::vector<u16> ord1143({1, 2, 0});
      slog::Relation* readrel1144 = db->getRelation("app");
      appindex1100 = readrel1144->getIndex(ord1143, false);
      std::vector<u16> ord1145({1, 2, 0});
      slog::Relation* readrel1146 = db->getRelation("app");
      appindex1101 = readrel1146->getIndex(ord1145, false);
  
    }
    ReadTask1102(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c177 = v_constc40f204dda7ba4054abb9e74;
      u64 v_c178 = v_const6cf13cc59dcbe759113f68a4;
      u64 v_c179 = v_const970c20ea81b833e5b5a7accf;
      u64 v_c180 = v_constcaa3ee5a2828a31924f6b39d;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex1081, std::array<u64,2>{v_c177, 0}, [&](const std::array<u64,2>& m1147) {
        u64 v_c181 = m1147[1];
        if (!slog::exists_probe<2,1>(refindex1082, std::array<u64,2>{v_c179, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1083, std::array<u64,3>{v_c179, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1084, std::array<u64,2>{v_c178, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1085, std::array<u64,2>{v_c180, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1086, std::array<u64,3>{v_c180, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1087, std::array<u64,3>{v_c178, 0, 0})) return;
        slog::join_probe<3,2>(lambdaindex1088, std::array<u64,3>{v_c177, v_c181, 0}, [&](const std::array<u64,3>& m1148) {
          u64 v_c182 = m1148[2];
          if (!slog::exists_probe<3,1>(appindex1089, std::array<u64,3>{v_c182, 0, 0})) return;
          slog::join_probe<2,1>(refindex1090, std::array<u64,2>{v_c179, 0}, [&](const std::array<u64,2>& m1149) {
            u64 v_c183 = m1149[1];
            slog::join_probe<3,2>(lambdaindex1091, std::array<u64,3>{v_c179, v_c183, 0}, [&](const std::array<u64,3>& m1150) {
              u64 v_c184 = m1150[2];
              if (!slog::exists_probe<3,1>(appindex1092, std::array<u64,3>{v_c184, 0, 0})) return;
              slog::join_probe<2,1>(refindex1093, std::array<u64,2>{v_c178, 0}, [&](const std::array<u64,2>& m1151) {
                u64 v_c185 = m1151[1];
                if (!slog::exists_probe<3,1>(appindex1094, std::array<u64,3>{v_c185, 0, 0})) return;
                slog::join_probe<2,1>(refindex1095, std::array<u64,2>{v_c180, 0}, [&](const std::array<u64,2>& m1152) {
                  u64 v_c186 = m1152[1];
                  slog::join_probe<3,2>(appindex1096, std::array<u64,3>{v_c185, v_c186, 0}, [&](const std::array<u64,3>& m1153) {
                    u64 v_c187 = m1153[2];
                    slog::join_probe<3,2>(appindex1097, std::array<u64,3>{v_c185, v_c187, 0}, [&](const std::array<u64,3>& m1154) {
                      u64 v_c188 = m1154[2];
                      slog::join_probe<3,2>(lambdaindex1098, std::array<u64,3>{v_c180, v_c188, 0}, [&](const std::array<u64,3>& m1155) {
                        u64 v_c189 = m1155[2];
                        slog::join_probe<3,2>(lambdaindex1099, std::array<u64,3>{v_c178, v_c189, 0}, [&](const std::array<u64,3>& m1156) {
                          u64 v_c190 = m1156[2];
                          slog::join_probe<3,2>(appindex1100, std::array<u64,3>{v_c190, v_c184, 0}, [&](const std::array<u64,3>& m1157) {
                            u64 v_c191 = m1157[2];
                            slog::join_probe<3,2>(appindex1101, std::array<u64,3>{v_c191, v_c182, 0}, [&](const std::array<u64,3>& m1158) {
                              u64 v_c192 = m1158[2];
                              ++_fires;
                              slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c192}, std::array<u16,1>{0});
                            });
                          });
                        });
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
      s->addTaskSeeded(phase_read, new ReadTask1102(db,b));
  // (crule (pre (let __tconst4Xaz41 const81cb39a72a584ab4f703b7f7) (let __tconst1aIN38 const4d5ce1398140fbe27561181f) (let __tconst4xzG22 constdbf1bdba02122b2adce28528) (let __tconst1ha033 const969c6e56242ce8d0a4346602) (let __tconst37GM26 const85f09fa1913b9daf65957cf7) (let __tconst1HMF17 constd7a1925d249b4768c8a9f2d8)) (probe lambda (1 2 0) 1 __tconst4xzG22 __t3b2k21 __t8Ovw23) (body (exists lambda (1 2 0) 1 __tconst1HMF17) (exists ref (1 0) 1 __tconst1HMF17) (exists ref (1 0) 1 __tconst4Xaz41) (exists ref (1 0) 1 __tconst37GM26) (exists lambda (1 2 0) 1 __tconst37GM26) (exists ref (1 0) 1 __tconst1ha033) (exists lambda (1 2 0) 1 __tconst1ha033) (exists lambda (1 2 0) 1 __tconst1aIN38) (join ref (1 0) 1 __tconst4xzG22 __t2DOE20) (join app (0 1 2) 2 __t3b2k21 __t2DOE20 __t2wNc18) (join lambda (0 1 2) 2 __t2wNc18 __tconst1HMF17 __t7H1u16) (join ref (0 1) 2 __t7H1u16 __tconst1HMF17) (join ref (1 0) 1 __tconst4Xaz41 __t75SZ29) (exists app (1 2 0) 1 __t75SZ29) (join ref (1 0) 1 __tconst37GM26 __t7U1m25) (join lambda (1 2 0) 2 __tconst37GM26 __t7U1m25 __t5myE27) (join app (1 2 0) 2 __t75SZ29 __t5myE27 __t2Vg230) (join ref (1 0) 1 __tconst1ha033 __t7N9A32) (join lambda (1 2 0) 2 __tconst1ha033 __t7N9A32 __t065j34) (join app (1 2 0) 2 __t75SZ29 __t065j34 __t3pMW37) (join lambda (1 2 0) 2 __tconst1aIN38 __t3pMW37 __t3aRV39)) (head (mkstruct app (1 2 0) __t7P7240 __t3aRV39 __t2Vg230)) mcfa-counting.slog:260 #f)
  class ReadTask1180 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** lambdaindex1159;  slog::Index** refindex1160;  slog::Index** refindex1161;  slog::Index** refindex1162;  slog::Index** lambdaindex1163;  slog::Index** refindex1164;  slog::Index** lambdaindex1165;  slog::Index** lambdaindex1166;  slog::Index** refindex1167;  slog::Index** appindex1168;  slog::Index** lambdaindex1169;  slog::Index** refindex1170;  slog::Index** refindex1171;  slog::Index** appindex1172;  slog::Index** refindex1173;  slog::Index** lambdaindex1174;  slog::Index** appindex1175;  slog::Index** refindex1176;  slog::Index** lambdaindex1177;  slog::Index** appindex1178;  slog::Index** lambdaindex1179;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord1181({1, 2, 0});
      slog::Relation* readrel1182 = db->getRelation("lambda");
      driver_index = readrel1182->getIndex(ord1181, true);
      std::vector<u16> ord1183({1, 2, 0});
      slog::Relation* readrel1184 = db->getRelation("lambda");
      lambdaindex1159 = readrel1184->getIndex(ord1183, false);
      std::vector<u16> ord1185({1, 0});
      slog::Relation* readrel1186 = db->getRelation("ref");
      refindex1160 = readrel1186->getIndex(ord1185, false);
      std::vector<u16> ord1187({1, 0});
      slog::Relation* readrel1188 = db->getRelation("ref");
      refindex1161 = readrel1188->getIndex(ord1187, false);
      std::vector<u16> ord1189({1, 0});
      slog::Relation* readrel1190 = db->getRelation("ref");
      refindex1162 = readrel1190->getIndex(ord1189, false);
      std::vector<u16> ord1191({1, 2, 0});
      slog::Relation* readrel1192 = db->getRelation("lambda");
      lambdaindex1163 = readrel1192->getIndex(ord1191, false);
      std::vector<u16> ord1193({1, 0});
      slog::Relation* readrel1194 = db->getRelation("ref");
      refindex1164 = readrel1194->getIndex(ord1193, false);
      std::vector<u16> ord1195({1, 2, 0});
      slog::Relation* readrel1196 = db->getRelation("lambda");
      lambdaindex1165 = readrel1196->getIndex(ord1195, false);
      std::vector<u16> ord1197({1, 2, 0});
      slog::Relation* readrel1198 = db->getRelation("lambda");
      lambdaindex1166 = readrel1198->getIndex(ord1197, false);
      std::vector<u16> ord1199({1, 0});
      slog::Relation* readrel1200 = db->getRelation("ref");
      refindex1167 = readrel1200->getIndex(ord1199, false);
      std::vector<u16> ord1201({0, 1, 2});
      slog::Relation* readrel1202 = db->getRelation("app");
      appindex1168 = readrel1202->getIndex(ord1201, false);
      std::vector<u16> ord1203({0, 1, 2});
      slog::Relation* readrel1204 = db->getRelation("lambda");
      lambdaindex1169 = readrel1204->getIndex(ord1203, false);
      std::vector<u16> ord1205({0, 1});
      slog::Relation* readrel1206 = db->getRelation("ref");
      refindex1170 = readrel1206->getIndex(ord1205, false);
      std::vector<u16> ord1207({1, 0});
      slog::Relation* readrel1208 = db->getRelation("ref");
      refindex1171 = readrel1208->getIndex(ord1207, false);
      std::vector<u16> ord1209({1, 2, 0});
      slog::Relation* readrel1210 = db->getRelation("app");
      appindex1172 = readrel1210->getIndex(ord1209, false);
      std::vector<u16> ord1211({1, 0});
      slog::Relation* readrel1212 = db->getRelation("ref");
      refindex1173 = readrel1212->getIndex(ord1211, false);
      std::vector<u16> ord1213({1, 2, 0});
      slog::Relation* readrel1214 = db->getRelation("lambda");
      lambdaindex1174 = readrel1214->getIndex(ord1213, false);
      std::vector<u16> ord1215({1, 2, 0});
      slog::Relation* readrel1216 = db->getRelation("app");
      appindex1175 = readrel1216->getIndex(ord1215, false);
      std::vector<u16> ord1217({1, 0});
      slog::Relation* readrel1218 = db->getRelation("ref");
      refindex1176 = readrel1218->getIndex(ord1217, false);
      std::vector<u16> ord1219({1, 2, 0});
      slog::Relation* readrel1220 = db->getRelation("lambda");
      lambdaindex1177 = readrel1220->getIndex(ord1219, false);
      std::vector<u16> ord1221({1, 2, 0});
      slog::Relation* readrel1222 = db->getRelation("app");
      appindex1178 = readrel1222->getIndex(ord1221, false);
      std::vector<u16> ord1223({1, 2, 0});
      slog::Relation* readrel1224 = db->getRelation("lambda");
      lambdaindex1179 = readrel1224->getIndex(ord1223, false);
  
    }
    ReadTask1180(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c102 = v_const81cb39a72a584ab4f703b7f7;
      u64 v_c104 = v_const4d5ce1398140fbe27561181f;
      u64 v_c103 = v_constdbf1bdba02122b2adce28528;
      u64 v_c107 = v_const969c6e56242ce8d0a4346602;
      u64 v_c105 = v_const85f09fa1913b9daf65957cf7;
      u64 v_c106 = v_constd7a1925d249b4768c8a9f2d8;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c103, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1225) {
        u64 v_c121 = m1225[1];
        u64 v_c122 = m1225[2];
        if (buckethash(v_c121) != bucket) return;
        if (!slog::exists_probe<3,1>(lambdaindex1159, std::array<u64,3>{v_c106, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1160, std::array<u64,2>{v_c106, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1161, std::array<u64,2>{v_c102, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1162, std::array<u64,2>{v_c105, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1163, std::array<u64,3>{v_c105, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1164, std::array<u64,2>{v_c107, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1165, std::array<u64,3>{v_c107, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1166, std::array<u64,3>{v_c104, 0, 0})) return;
        slog::join_probe<2,1>(refindex1167, std::array<u64,2>{v_c103, 0}, [&](const std::array<u64,2>& m1226) {
          u64 v_c111 = m1226[1];
          slog::join_probe<3,2>(appindex1168, std::array<u64,3>{v_c121, v_c111, 0}, [&](const std::array<u64,3>& m1227) {
            u64 v_c120 = m1227[2];
            slog::join_probe<3,2>(lambdaindex1169, std::array<u64,3>{v_c120, v_c106, 0}, [&](const std::array<u64,3>& m1228) {
              u64 v_c119 = m1228[2];
              slog::join_probe<2,2>(refindex1170, std::array<u64,2>{v_c119, v_c106}, [&](const std::array<u64,2>& m1229) {
                slog::join_probe<2,1>(refindex1171, std::array<u64,2>{v_c102, 0}, [&](const std::array<u64,2>& m1230) {
                  u64 v_c110 = m1230[1];
                  if (!slog::exists_probe<3,1>(appindex1172, std::array<u64,3>{v_c110, 0, 0})) return;
                  slog::join_probe<2,1>(refindex1173, std::array<u64,2>{v_c105, 0}, [&](const std::array<u64,2>& m1231) {
                    u64 v_c112 = m1231[1];
                    slog::join_probe<3,2>(lambdaindex1174, std::array<u64,3>{v_c105, v_c112, 0}, [&](const std::array<u64,3>& m1232) {
                      u64 v_c113 = m1232[2];
                      slog::join_probe<3,2>(appindex1175, std::array<u64,3>{v_c110, v_c113, 0}, [&](const std::array<u64,3>& m1233) {
                        u64 v_c114 = m1233[2];
                        slog::join_probe<2,1>(refindex1176, std::array<u64,2>{v_c107, 0}, [&](const std::array<u64,2>& m1234) {
                          u64 v_c118 = m1234[1];
                          slog::join_probe<3,2>(lambdaindex1177, std::array<u64,3>{v_c107, v_c118, 0}, [&](const std::array<u64,3>& m1235) {
                            u64 v_c117 = m1235[2];
                            slog::join_probe<3,2>(appindex1178, std::array<u64,3>{v_c110, v_c117, 0}, [&](const std::array<u64,3>& m1236) {
                              u64 v_c116 = m1236[2];
                              slog::join_probe<3,2>(lambdaindex1179, std::array<u64,3>{v_c104, v_c116, 0}, [&](const std::array<u64,3>& m1237) {
                                u64 v_c115 = m1237[2];
                                ++_fires;
                                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c115, v_c114}, std::array<u16,3>{1, 2, 0});
                              });
                            });
                          });
                        });
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
  
      if (_fires) db->bumpFires("mcfa-counting.slog:260", "delta:lambda", _fires);
  
      if (!_done)
      {
        ReadTask1180* _cont = new ReadTask1180(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1180(db,b), false);
  // (crule (pre) (scan malformed_deduction __erre5uT8370 __errf7iFt371 __errf8IJZ372 __errf3q0b373 __errf7mzV374) (body) (head (emit error (0) __erre5uT8370)) <internal>:1 #f)
  class ReadTask1238 : public slog::Task
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
      std::vector<u16> ord1239({0});
      slog::Relation* readrel1240 = db->getRelation("error");
      head_index[0] = readrel1240->getIndex(ord1239, false);
      outer_rel = db->getRelation("malformed_deduction");
  
    }
    ReadTask1238(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c194 = _t[1];
        u64 v_c195 = _t[2];
        u64 v_c196 = _t[3];
        u64 v_c197 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c193}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:malformed_deduction", _fires);
  
      if (!_done)
      {
        ReadTask1238* _cont = new ReadTask1238(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1238(db,b), false);
  // (crule (pre) (scan app __t3MbO322 ef ea) (body (exists eval (1 2 0) 1 __t3MbO322) (exists $sup27994x83x0x0x1 (5 7 0 3 1 2 4 6 8 9) 2 ea ef) (exists eval (1 2 0) 1 ef) (exists eval (1 2 0) 1 ea) (exists eval (2 0 1) 1 __t3MbO322) (join $sup27994x83x0x0x0 (2 3 0 1) 2 ea ef __t5GoB317 c) (join eval (0 2 1) 3 __t5GoB317 c __t3MbO322) (exists eval (1 2 0) 2 ef c) (exists eval (1 2 0) 2 ea c) (join $sup27994x83x0x0x1 (5 7 0 3 1 2 4 6 8 9) 4 ea ef __t5GoB317 c __t1FV8318 __t8XTs321 cb eb va x) (join eval (0 2 1) 3 __t1FV8318 c ef) (join eval (0 2 1) 3 __t8XTs321 c ea) (join eval_ans (0 1) 2 __t8XTs321 va) (exists clo (2 0 1) 1 cb) (exists eval_ans (0 1) 1 __t1FV8318) (exists eval (1 2 0) 2 eb __t3MbO322) (join lambda (1 2 0) 2 x eb __t6vap319) (join clo (1 2 0) 2 __t6vap319 cb __t1oxE320) (join eval_ans (0 1) 2 __t1FV8318 __t1oxE320) (join-old eval (1 2 0) 2 (1 2 0) eb __t3MbO322 __t3H1A323) (join eval_ans (0 1) 1 __t3H1A323 v)) (head (emit eval_ans (0 1) __t5GoB317 v)) mcfa-counting.slog:84 #f)
  class ReadTask1263 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1241;  slog::Index** $sup27994x83x0x0x1index1242;  slog::Index** evalindex1243;  slog::Index** evalindex1244;  slog::Index** evalindex1245;  slog::Index** $sup27994x83x0x0x0index1246;  slog::Index** evalindex1247;  slog::Index** evalindex1248;  slog::Index** evalindex1249;  slog::Index** $sup27994x83x0x0x1index1250;  slog::Index** evalindex1251;  slog::Index** evalindex1252;  slog::Index** eval_ansindex1253;  slog::Index** cloindex1254;  slog::Index** eval_ansindex1255;  slog::Index** evalindex1256;  slog::Index** lambdaindex1257;  slog::Index** cloindex1258;  slog::Index** eval_ansindex1259;  slog::Index** evalindex1260;  slog::Index** eval_ansindex1261;  slog::Index** evaldelta1262;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1264({0, 1});
      slog::Relation* readrel1265 = db->getRelation("eval_ans");
      head_index[0] = readrel1265->getIndex(ord1264, false);
      outer_rel = db->getRelation("app");
      std::vector<u16> ord1266({1, 2, 0});
      slog::Relation* readrel1267 = db->getRelation("eval");
      evalindex1241 = readrel1267->getIndex(ord1266, false);
      std::vector<u16> ord1268({5, 7, 0, 3, 1, 2, 4, 6, 8, 9});
      slog::Relation* readrel1269 = db->getRelation("$sup27994x83x0x0x1");
      $sup27994x83x0x0x1index1242 = readrel1269->getIndex(ord1268, false);
      std::vector<u16> ord1270({1, 2, 0});
      slog::Relation* readrel1271 = db->getRelation("eval");
      evalindex1243 = readrel1271->getIndex(ord1270, false);
      std::vector<u16> ord1272({1, 2, 0});
      slog::Relation* readrel1273 = db->getRelation("eval");
      evalindex1244 = readrel1273->getIndex(ord1272, false);
      std::vector<u16> ord1274({2, 0, 1});
      slog::Relation* readrel1275 = db->getRelation("eval");
      evalindex1245 = readrel1275->getIndex(ord1274, false);
      std::vector<u16> ord1276({2, 3, 0, 1});
      slog::Relation* readrel1277 = db->getRelation("$sup27994x83x0x0x0");
      $sup27994x83x0x0x0index1246 = readrel1277->getIndex(ord1276, false);
      std::vector<u16> ord1278({0, 2, 1});
      slog::Relation* readrel1279 = db->getRelation("eval");
      evalindex1247 = readrel1279->getIndex(ord1278, false);
      std::vector<u16> ord1280({1, 2, 0});
      slog::Relation* readrel1281 = db->getRelation("eval");
      evalindex1248 = readrel1281->getIndex(ord1280, false);
      std::vector<u16> ord1282({1, 2, 0});
      slog::Relation* readrel1283 = db->getRelation("eval");
      evalindex1249 = readrel1283->getIndex(ord1282, false);
      std::vector<u16> ord1284({5, 7, 0, 3, 1, 2, 4, 6, 8, 9});
      slog::Relation* readrel1285 = db->getRelation("$sup27994x83x0x0x1");
      $sup27994x83x0x0x1index1250 = readrel1285->getIndex(ord1284, false);
      std::vector<u16> ord1286({0, 2, 1});
      slog::Relation* readrel1287 = db->getRelation("eval");
      evalindex1251 = readrel1287->getIndex(ord1286, false);
      std::vector<u16> ord1288({0, 2, 1});
      slog::Relation* readrel1289 = db->getRelation("eval");
      evalindex1252 = readrel1289->getIndex(ord1288, false);
      std::vector<u16> ord1290({0, 1});
      slog::Relation* readrel1291 = db->getRelation("eval_ans");
      eval_ansindex1253 = readrel1291->getIndex(ord1290, false);
      std::vector<u16> ord1292({2, 0, 1});
      slog::Relation* readrel1293 = db->getRelation("clo");
      cloindex1254 = readrel1293->getIndex(ord1292, false);
      std::vector<u16> ord1294({0, 1});
      slog::Relation* readrel1295 = db->getRelation("eval_ans");
      eval_ansindex1255 = readrel1295->getIndex(ord1294, false);
      std::vector<u16> ord1296({1, 2, 0});
      slog::Relation* readrel1297 = db->getRelation("eval");
      evalindex1256 = readrel1297->getIndex(ord1296, false);
      std::vector<u16> ord1298({1, 2, 0});
      slog::Relation* readrel1299 = db->getRelation("lambda");
      lambdaindex1257 = readrel1299->getIndex(ord1298, false);
      std::vector<u16> ord1300({1, 2, 0});
      slog::Relation* readrel1301 = db->getRelation("clo");
      cloindex1258 = readrel1301->getIndex(ord1300, false);
      std::vector<u16> ord1302({0, 1});
      slog::Relation* readrel1303 = db->getRelation("eval_ans");
      eval_ansindex1259 = readrel1303->getIndex(ord1302, false);
      std::vector<u16> ord1304({1, 2, 0});
      slog::Relation* readrel1305 = db->getRelation("eval");
      evalindex1260 = readrel1305->getIndex(ord1304, false);
      std::vector<u16> ord1306({1, 2, 0});
      slog::Relation* readrel1307 = db->getRelation("eval");
      evaldelta1262 = readrel1307->getIndex(ord1306, true);
      std::vector<u16> ord1308({0, 1});
      slog::Relation* readrel1309 = db->getRelation("eval_ans");
      eval_ansindex1261 = readrel1309->getIndex(ord1308, false);
  
    }
    ReadTask1263(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c68 = _t[1];
        u64 v_c69 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex1241, std::array<u64,3>{v_c198, 0, 0})) return;
        if (!slog::exists_probe<10,2>($sup27994x83x0x0x1index1242, std::array<u64,10>{v_c69, v_c68, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(evalindex1243, std::array<u64,3>{v_c68, 0, 0})) return;
        if (!slog::exists_probe<3,1>(evalindex1244, std::array<u64,3>{v_c69, 0, 0})) return;
        if (!slog::exists_probe<3,1>(evalindex1245, std::array<u64,3>{v_c198, 0, 0})) return;
        slog::join_probe<4,2>($sup27994x83x0x0x0index1246, std::array<u64,4>{v_c69, v_c68, 0, 0}, [&](const std::array<u64,4>& m1310) {
          u64 v_c199 = m1310[2]; u64 v_c70 = m1310[3];
          slog::join_probe<3,3>(evalindex1247, std::array<u64,3>{v_c199, v_c70, v_c198}, [&](const std::array<u64,3>& m1311) {
            if (!slog::exists_probe<3,2>(evalindex1248, std::array<u64,3>{v_c68, v_c70, 0})) return;
            if (!slog::exists_probe<3,2>(evalindex1249, std::array<u64,3>{v_c69, v_c70, 0})) return;
            slog::join_probe<10,4>($sup27994x83x0x0x1index1250, std::array<u64,10>{v_c69, v_c68, v_c199, v_c70, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,10>& m1312) {
              u64 v_c200 = m1312[4]; u64 v_c201 = m1312[5]; u64 v_c76 = m1312[6]; u64 v_c79 = m1312[7]; u64 v_c75 = m1312[8]; u64 v_c78 = m1312[9];
              slog::join_probe<3,3>(evalindex1251, std::array<u64,3>{v_c200, v_c70, v_c68}, [&](const std::array<u64,3>& m1313) {
                slog::join_probe<3,3>(evalindex1252, std::array<u64,3>{v_c201, v_c70, v_c69}, [&](const std::array<u64,3>& m1314) {
                  slog::join_probe<2,2>(eval_ansindex1253, std::array<u64,2>{v_c201, v_c75}, [&](const std::array<u64,2>& m1315) {
                    if (!slog::exists_probe<3,1>(cloindex1254, std::array<u64,3>{v_c76, 0, 0})) return;
                    if (!slog::exists_probe<2,1>(eval_ansindex1255, std::array<u64,2>{v_c200, 0})) return;
                    if (!slog::exists_probe<3,2>(evalindex1256, std::array<u64,3>{v_c79, v_c198, 0})) return;
                    slog::join_probe<3,2>(lambdaindex1257, std::array<u64,3>{v_c78, v_c79, 0}, [&](const std::array<u64,3>& m1316) {
                      u64 v_c202 = m1316[2];
                      slog::join_probe<3,2>(cloindex1258, std::array<u64,3>{v_c202, v_c76, 0}, [&](const std::array<u64,3>& m1317) {
                        u64 v_c203 = m1317[2];
                        slog::join_probe<2,2>(eval_ansindex1259, std::array<u64,2>{v_c200, v_c203}, [&](const std::array<u64,2>& m1318) {
                          slog::join_probe_old<3,2>(evalindex1260, evaldelta1262, std::array<u64,3>{v_c79, v_c198, 0}, [&](const std::array<u64,3>& m1319) {
                            u64 v_c204 = m1319[2];
                            slog::join_probe<2,1>(eval_ansindex1261, std::array<u64,2>{v_c204, 0}, [&](const std::array<u64,2>& m1320) {
                              u64 v_c205 = m1320[1];
                              ++_fires;
                              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c199, v_c205}, std::array<u16,2>{0, 1});
                            });
                          });
                        });
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
  
      if (_fires) db->bumpFires("mcfa-counting.slog:84", "delta:app", _fires);
  
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
  // (crule (pre (let __tconst0y6X73 const0aa6f87434af0222b916e97a) (let __tconst7zoP70 const227d34ceeba7a29aada993d4) (let __tconst1bfe65 const59ba3256d223f0d0a00d0633) (let __tconst8wN863 const7cd75b35aa30c3ddf04f9d57) (let __tconst0aL952 constd3d07026d47882ceca728218) (let __tconst0xUh47 constf700a82e218a86de572e1f7f)) (once) (body) (head (mkstruct ref (1 0) __t1mkO62 __tconst8wN863) (mkstruct ref (1 0) __t0QRr59 __tconst0y6X73) (mkstruct ref (1 0) __t2HsD55 __tconst1bfe65) (mkstruct ref (1 0) __t5HQ450 __tconst0aL952) (mkstruct ref (1 0) __t5vZb46 __tconst0xUh47)) mcfa-counting.slog:287 #f)
  class ReadTask1321 : public slog::Task
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
    ReadTask1321(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c48 = v_const0aa6f87434af0222b916e97a;
      u64 v_c49 = v_const227d34ceeba7a29aada993d4;
      u64 v_c51 = v_const59ba3256d223f0d0a00d0633;
      u64 v_c52 = v_const7cd75b35aa30c3ddf04f9d57;
      u64 v_c50 = v_constd3d07026d47882ceca728218;
      u64 v_c53 = v_constf700a82e218a86de572e1f7f;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[5];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
      newbatch[4] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c52}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c48}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[2], newbatch[2], std::array<u64,1>{v_c51}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[3], newbatch[3], std::array<u64,1>{v_c50}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[4], newbatch[4], std::array<u64,1>{v_c53}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:287", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask1321(db,b), true);
  // (crule (pre) (scan eval __t1JPZ173 ea c) (body (exists eval (2 0 1) 1 c) (exists app (2 0 1) 1 ea) (join eval_ans (0 1) 1 __t1JPZ173 va) (join eval (2 0 1) 1 c __6tlE337 __t5SBy169) (join app (2 0 1) 2 ea __t5SBy169 ef) (join eval (1 2 0) 2 ef c __t6CRg170) (join eval_ans (0 1) 1 __t6CRg170 __t2Hqj172) (join clo (0 2 1) 1 __t2Hqj172 cb __t0RD6171) (join lambda (0 1 2) 1 __t0RD6171 x eb)) (head (emit store (0 1 2) x __t5SBy169 va) (emit callev (0 1) __t5SBy169 c) (emit bindev (0 1 2) x __t5SBy169 c)) mcfa-counting.slog:92 #f)
  class ReadTask1331 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1322;  slog::Index** appindex1323;  slog::Index** eval_ansindex1324;  slog::Index** evalindex1325;  slog::Index** appindex1326;  slog::Index** evalindex1327;  slog::Index** eval_ansindex1328;  slog::Index** cloindex1329;  slog::Index** lambdaindex1330;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("store");
      std::vector<u16> ord1332({0, 1, 2});
      slog::Relation* readrel1333 = db->getRelation("store");
      head_index[0] = readrel1333->getIndex(ord1332, false);
      head_rel[1] = db->getRelation("callev");
      std::vector<u16> ord1334({0, 1});
      slog::Relation* readrel1335 = db->getRelation("callev");
      head_index[1] = readrel1335->getIndex(ord1334, false);
      head_rel[2] = db->getRelation("bindev");
      std::vector<u16> ord1336({0, 1, 2});
      slog::Relation* readrel1337 = db->getRelation("bindev");
      head_index[2] = readrel1337->getIndex(ord1336, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord1338({2, 0, 1});
      slog::Relation* readrel1339 = db->getRelation("eval");
      evalindex1322 = readrel1339->getIndex(ord1338, false);
      std::vector<u16> ord1340({2, 0, 1});
      slog::Relation* readrel1341 = db->getRelation("app");
      appindex1323 = readrel1341->getIndex(ord1340, false);
      std::vector<u16> ord1342({0, 1});
      slog::Relation* readrel1343 = db->getRelation("eval_ans");
      eval_ansindex1324 = readrel1343->getIndex(ord1342, false);
      std::vector<u16> ord1344({2, 0, 1});
      slog::Relation* readrel1345 = db->getRelation("eval");
      evalindex1325 = readrel1345->getIndex(ord1344, false);
      std::vector<u16> ord1346({2, 0, 1});
      slog::Relation* readrel1347 = db->getRelation("app");
      appindex1326 = readrel1347->getIndex(ord1346, false);
      std::vector<u16> ord1348({1, 2, 0});
      slog::Relation* readrel1349 = db->getRelation("eval");
      evalindex1327 = readrel1349->getIndex(ord1348, false);
      std::vector<u16> ord1350({0, 1});
      slog::Relation* readrel1351 = db->getRelation("eval_ans");
      eval_ansindex1328 = readrel1351->getIndex(ord1350, false);
      std::vector<u16> ord1352({0, 2, 1});
      slog::Relation* readrel1353 = db->getRelation("clo");
      cloindex1329 = readrel1353->getIndex(ord1352, false);
      std::vector<u16> ord1354({0, 1, 2});
      slog::Relation* readrel1355 = db->getRelation("lambda");
      lambdaindex1330 = readrel1355->getIndex(ord1354, false);
  
    }
    ReadTask1331(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c73 = _t[0];
        u64 v_c69 = _t[1];
        u64 v_c70 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex1322, std::array<u64,3>{v_c70, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex1323, std::array<u64,3>{v_c69, 0, 0})) return;
        slog::join_probe<2,1>(eval_ansindex1324, std::array<u64,2>{v_c73, 0}, [&](const std::array<u64,2>& m1356) {
          u64 v_c75 = m1356[1];
          slog::join_probe<3,1>(evalindex1325, std::array<u64,3>{v_c70, 0, 0}, [&](const std::array<u64,3>& m1357) {
            u64 v_c71 = m1357[1]; u64 v_c67 = m1357[2];
            slog::join_probe<3,2>(appindex1326, std::array<u64,3>{v_c69, v_c67, 0}, [&](const std::array<u64,3>& m1358) {
              u64 v_c68 = m1358[2];
              slog::join_probe<3,2>(evalindex1327, std::array<u64,3>{v_c68, v_c70, 0}, [&](const std::array<u64,3>& m1359) {
                u64 v_c72 = m1359[2];
                slog::join_probe<2,1>(eval_ansindex1328, std::array<u64,2>{v_c72, 0}, [&](const std::array<u64,2>& m1360) {
                  u64 v_c74 = m1360[1];
                  slog::join_probe<3,1>(cloindex1329, std::array<u64,3>{v_c74, 0, 0}, [&](const std::array<u64,3>& m1361) {
                    u64 v_c76 = m1361[1]; u64 v_c77 = m1361[2];
                    slog::join_probe<3,1>(lambdaindex1330, std::array<u64,3>{v_c77, 0, 0}, [&](const std::array<u64,3>& m1362) {
                      u64 v_c78 = m1362[1]; u64 v_c79 = m1362[2];
                      ++_fires;
                      slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c78, v_c67, v_c75}, std::array<u16,3>{0, 1, 2});
                      slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c67, v_c70}, std::array<u16,2>{0, 1});
                      slog::emit<3>(head_rel[2], head_index[2], newbatch[2], std::array<u64,3>{v_c78, v_c67, v_c70}, std::array<u16,3>{0, 1, 2});
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
        ReadTask1331* _cont = new ReadTask1331(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1331(db,b), false);
  // (crule (pre (let __tconst5Fqn220 const15bb62b8293a526ca6f0e4eb) (let __tconst0ZcM213 constfc9ee54e0ee8c6d1e715716c) (let __tconst9TQS210 const5950e3cb761734f52a881545) (let __tconst1wsq203 const77ceb5c0e9f84ebd84104a97)) (once) (body) (head (mkstruct ref (1 0) __t2V0C216 __tconst5Fqn220) (mkstruct ref (1 0) __t6fYg206 __tconst0ZcM213) (mkstruct ref (1 0) __t6pkv202 __tconst1wsq203)) mcfa-counting.slog:211 #f)
  class ReadTask1363 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("ref");
      head_rel[1] = db->getRelation("ref");
      head_rel[2] = db->getRelation("ref");
  
    }
    ReadTask1363(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c4 = v_const15bb62b8293a526ca6f0e4eb;
      u64 v_c5 = v_constfc9ee54e0ee8c6d1e715716c;
      u64 v_c6 = v_const5950e3cb761734f52a881545;
      u64 v_c7 = v_const77ceb5c0e9f84ebd84104a97;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c4}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c5}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[2], newbatch[2], std::array<u64,1>{v_c7}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:211", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask1363(db,b), true);
  // (crule (pre (let __tconst0ZcM213 constfc9ee54e0ee8c6d1e715716c) (let __tconst5Fqn220 const15bb62b8293a526ca6f0e4eb) (let __tconst9TQS210 const5950e3cb761734f52a881545) (let __tconst1wsq203 const77ceb5c0e9f84ebd84104a97)) (scan app __t4RlI222 __t6h87221 __t14ld214) (body (exists lambda (0 1 2) 2 __t14ld214 __tconst0ZcM213) (exists ref (1 0) 1 __tconst5Fqn220) (exists ref (1 0) 1 __tconst1wsq203) (exists lambda (1 2 0) 1 __tconst1wsq203) (exists lambda (1 2 0) 1 __tconst9TQS210) (exists ref (1 0) 1 __tconst0ZcM213) (join lambda (0 1 2) 2 __t6h87221 __tconst5Fqn220 __t9nSF219) (join lambda (0 1 2) 2 __t14ld214 __tconst0ZcM213 __t4jAx212) (join ref (1 0) 1 __tconst5Fqn220 __t2V0C216) (join app (0 1 2) 2 __t9nSF219 __t2V0C216 dup8TEZ433) (eq __t2V0C216 dup8TEZ433) (join ref (1 0) 1 __tconst1wsq203 __t6pkv202) (join lambda (1 2 0) 2 __tconst1wsq203 __t6pkv202 __t118D204) (join app (2 0 1) 2 __t118D204 __t4jAx212 __t1wmd211) (join lambda (0 1 2) 2 __t1wmd211 __tconst9TQS210 __t1W86209) (join ref (1 0) 1 __tconst0ZcM213 __t6fYg206) (join app (0 1 2) 2 __t1W86209 __t6fYg206 dup1AU3434) (eq __t6fYg206 dup1AU3434)) (head (emit program (0) __t4RlI222)) mcfa-counting.slog:211 #f)
  class ReadTask1380 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lambdaindex1364;  slog::Index** refindex1365;  slog::Index** refindex1366;  slog::Index** lambdaindex1367;  slog::Index** lambdaindex1368;  slog::Index** refindex1369;  slog::Index** lambdaindex1370;  slog::Index** lambdaindex1371;  slog::Index** refindex1372;  slog::Index** appindex1373;  slog::Index** refindex1374;  slog::Index** lambdaindex1375;  slog::Index** appindex1376;  slog::Index** lambdaindex1377;  slog::Index** refindex1378;  slog::Index** appindex1379;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("program");
      std::vector<u16> ord1381({0});
      slog::Relation* readrel1382 = db->getRelation("program");
      head_index[0] = readrel1382->getIndex(ord1381, false);
      outer_rel = db->getRelation("app");
      std::vector<u16> ord1383({0, 1, 2});
      slog::Relation* readrel1384 = db->getRelation("lambda");
      lambdaindex1364 = readrel1384->getIndex(ord1383, false);
      std::vector<u16> ord1385({1, 0});
      slog::Relation* readrel1386 = db->getRelation("ref");
      refindex1365 = readrel1386->getIndex(ord1385, false);
      std::vector<u16> ord1387({1, 0});
      slog::Relation* readrel1388 = db->getRelation("ref");
      refindex1366 = readrel1388->getIndex(ord1387, false);
      std::vector<u16> ord1389({1, 2, 0});
      slog::Relation* readrel1390 = db->getRelation("lambda");
      lambdaindex1367 = readrel1390->getIndex(ord1389, false);
      std::vector<u16> ord1391({1, 2, 0});
      slog::Relation* readrel1392 = db->getRelation("lambda");
      lambdaindex1368 = readrel1392->getIndex(ord1391, false);
      std::vector<u16> ord1393({1, 0});
      slog::Relation* readrel1394 = db->getRelation("ref");
      refindex1369 = readrel1394->getIndex(ord1393, false);
      std::vector<u16> ord1395({0, 1, 2});
      slog::Relation* readrel1396 = db->getRelation("lambda");
      lambdaindex1370 = readrel1396->getIndex(ord1395, false);
      std::vector<u16> ord1397({0, 1, 2});
      slog::Relation* readrel1398 = db->getRelation("lambda");
      lambdaindex1371 = readrel1398->getIndex(ord1397, false);
      std::vector<u16> ord1399({1, 0});
      slog::Relation* readrel1400 = db->getRelation("ref");
      refindex1372 = readrel1400->getIndex(ord1399, false);
      std::vector<u16> ord1401({0, 1, 2});
      slog::Relation* readrel1402 = db->getRelation("app");
      appindex1373 = readrel1402->getIndex(ord1401, false);
      std::vector<u16> ord1403({1, 0});
      slog::Relation* readrel1404 = db->getRelation("ref");
      refindex1374 = readrel1404->getIndex(ord1403, false);
      std::vector<u16> ord1405({1, 2, 0});
      slog::Relation* readrel1406 = db->getRelation("lambda");
      lambdaindex1375 = readrel1406->getIndex(ord1405, false);
      std::vector<u16> ord1407({2, 0, 1});
      slog::Relation* readrel1408 = db->getRelation("app");
      appindex1376 = readrel1408->getIndex(ord1407, false);
      std::vector<u16> ord1409({0, 1, 2});
      slog::Relation* readrel1410 = db->getRelation("lambda");
      lambdaindex1377 = readrel1410->getIndex(ord1409, false);
      std::vector<u16> ord1411({1, 0});
      slog::Relation* readrel1412 = db->getRelation("ref");
      refindex1378 = readrel1412->getIndex(ord1411, false);
      std::vector<u16> ord1413({0, 1, 2});
      slog::Relation* readrel1414 = db->getRelation("app");
      appindex1379 = readrel1414->getIndex(ord1413, false);
  
    }
    ReadTask1380(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c5 = v_constfc9ee54e0ee8c6d1e715716c;
      u64 v_c4 = v_const15bb62b8293a526ca6f0e4eb;
      u64 v_c6 = v_const5950e3cb761734f52a881545;
      u64 v_c7 = v_const77ceb5c0e9f84ebd84104a97;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c168 = _t[0];
        u64 v_c163 = _t[1];
        u64 v_c167 = _t[2];
        if (!slog::exists_probe<3,2>(lambdaindex1364, std::array<u64,3>{v_c167, v_c5, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1365, std::array<u64,2>{v_c4, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1366, std::array<u64,2>{v_c7, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1367, std::array<u64,3>{v_c7, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1368, std::array<u64,3>{v_c6, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1369, std::array<u64,2>{v_c5, 0})) return;
        slog::join_probe<3,2>(lambdaindex1370, std::array<u64,3>{v_c163, v_c4, 0}, [&](const std::array<u64,3>& m1415) {
          u64 v_c15 = m1415[2];
          slog::join_probe<3,2>(lambdaindex1371, std::array<u64,3>{v_c167, v_c5, 0}, [&](const std::array<u64,3>& m1416) {
            u64 v_c166 = m1416[2];
            slog::join_probe<2,1>(refindex1372, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m1417) {
              u64 v_c11 = m1417[1];
              slog::join_probe<3,2>(appindex1373, std::array<u64,3>{v_c15, v_c11, 0}, [&](const std::array<u64,3>& m1418) {
                u64 v_c206 = m1418[2];
                if (v_c11 != v_c206) return;
                slog::join_probe<2,1>(refindex1374, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m1419) {
                  u64 v_c8 = m1419[1];
                  slog::join_probe<3,2>(lambdaindex1375, std::array<u64,3>{v_c7, v_c8, 0}, [&](const std::array<u64,3>& m1420) {
                    u64 v_c9 = m1420[2];
                    slog::join_probe<3,2>(appindex1376, std::array<u64,3>{v_c9, v_c166, 0}, [&](const std::array<u64,3>& m1421) {
                      u64 v_c165 = m1421[2];
                      slog::join_probe<3,2>(lambdaindex1377, std::array<u64,3>{v_c165, v_c6, 0}, [&](const std::array<u64,3>& m1422) {
                        u64 v_c13 = m1422[2];
                        slog::join_probe<2,1>(refindex1378, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m1423) {
                          u64 v_c10 = m1423[1];
                          slog::join_probe<3,2>(appindex1379, std::array<u64,3>{v_c13, v_c10, 0}, [&](const std::array<u64,3>& m1424) {
                            u64 v_c207 = m1424[2];
                            if (v_c10 != v_c207) return;
                            ++_fires;
                            slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c168}, std::array<u16,1>{0});
                          });
                        });
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
  
      if (_fires) db->bumpFires("mcfa-counting.slog:211", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask1380* _cont = new ReadTask1380(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1380(db,b), false);
  // (crule (pre (let __tconst4Xaz41 const81cb39a72a584ab4f703b7f7) (let __tconst4xzG22 constdbf1bdba02122b2adce28528) (let __tconst1aIN38 const4d5ce1398140fbe27561181f) (let __tconst37GM26 const85f09fa1913b9daf65957cf7) (let __tconst1HMF17 constd7a1925d249b4768c8a9f2d8) (let __tconst1ha033 const969c6e56242ce8d0a4346602)) (seeded) (body (join ref (1 0) 1 __tconst4Xaz41 __t75SZ29) (exists ref (1 0) 1 __tconst37GM26) (exists lambda (1 2 0) 1 __tconst37GM26) (exists app (1 2 0) 1 __t75SZ29) (exists ref (1 0) 1 __tconst1HMF17) (exists lambda (1 2 0) 1 __tconst1HMF17) (exists lambda (1 2 0) 1 __tconst4xzG22) (exists ref (1 0) 1 __tconst1ha033) (exists lambda (1 2 0) 1 __tconst1ha033) (exists lambda (1 2 0) 1 __tconst1aIN38) (exists lambda (1 2 0) 1 __tconst4Xaz41) (join ref (1 0) 1 __tconst4xzG22 __t2DOE20) (exists app (1 2 0) 1 __t2DOE20) (join ref (1 0) 1 __tconst37GM26 __t7U1m25) (join lambda (1 2 0) 2 __tconst37GM26 __t7U1m25 __t5myE27) (join app (1 2 0) 2 __t75SZ29 __t5myE27 __t2Vg230) (exists app (2 0 1) 1 __t2Vg230) (join ref (1 0) 1 __tconst1HMF17 __t7H1u16) (join lambda (1 2 0) 2 __tconst1HMF17 __t7H1u16 __t2wNc18) (join app (1 2 0) 2 __t2DOE20 __t2wNc18 __t3b2k21) (join lambda (1 2 0) 2 __tconst4xzG22 __t3b2k21 __t8Ovw23) (join ref (1 0) 1 __tconst1ha033 __t7N9A32) (join lambda (1 2 0) 2 __tconst1ha033 __t7N9A32 __t065j34) (join app (1 2 0) 2 __t75SZ29 __t065j34 __t3pMW37) (join lambda (1 2 0) 2 __tconst1aIN38 __t3pMW37 __t3aRV39) (join app (1 2 0) 2 __t3aRV39 __t2Vg230 __t7P7240) (join lambda (1 2 0) 2 __tconst4Xaz41 __t7P7240 __t79we42)) (head (mkstruct app (1 2 0) __t9tGa43 __t79we42 __t8Ovw23)) mcfa-counting.slog:260 #f)
  class ReadTask1452 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex1425;  slog::Index** refindex1426;  slog::Index** lambdaindex1427;  slog::Index** appindex1428;  slog::Index** refindex1429;  slog::Index** lambdaindex1430;  slog::Index** lambdaindex1431;  slog::Index** refindex1432;  slog::Index** lambdaindex1433;  slog::Index** lambdaindex1434;  slog::Index** lambdaindex1435;  slog::Index** refindex1436;  slog::Index** appindex1437;  slog::Index** refindex1438;  slog::Index** lambdaindex1439;  slog::Index** appindex1440;  slog::Index** appindex1441;  slog::Index** refindex1442;  slog::Index** lambdaindex1443;  slog::Index** appindex1444;  slog::Index** lambdaindex1445;  slog::Index** refindex1446;  slog::Index** lambdaindex1447;  slog::Index** appindex1448;  slog::Index** lambdaindex1449;  slog::Index** appindex1450;  slog::Index** lambdaindex1451;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord1453({1, 2, 0});
      slog::Relation* readrel1454 = db->getRelation("app");
      head_index[0] = readrel1454->getIndex(ord1453, false);
      std::vector<u16> ord1455({1, 0});
      slog::Relation* readrel1456 = db->getRelation("ref");
      refindex1425 = readrel1456->getIndex(ord1455, false);
      std::vector<u16> ord1457({1, 0});
      slog::Relation* readrel1458 = db->getRelation("ref");
      refindex1426 = readrel1458->getIndex(ord1457, false);
      std::vector<u16> ord1459({1, 2, 0});
      slog::Relation* readrel1460 = db->getRelation("lambda");
      lambdaindex1427 = readrel1460->getIndex(ord1459, false);
      std::vector<u16> ord1461({1, 2, 0});
      slog::Relation* readrel1462 = db->getRelation("app");
      appindex1428 = readrel1462->getIndex(ord1461, false);
      std::vector<u16> ord1463({1, 0});
      slog::Relation* readrel1464 = db->getRelation("ref");
      refindex1429 = readrel1464->getIndex(ord1463, false);
      std::vector<u16> ord1465({1, 2, 0});
      slog::Relation* readrel1466 = db->getRelation("lambda");
      lambdaindex1430 = readrel1466->getIndex(ord1465, false);
      std::vector<u16> ord1467({1, 2, 0});
      slog::Relation* readrel1468 = db->getRelation("lambda");
      lambdaindex1431 = readrel1468->getIndex(ord1467, false);
      std::vector<u16> ord1469({1, 0});
      slog::Relation* readrel1470 = db->getRelation("ref");
      refindex1432 = readrel1470->getIndex(ord1469, false);
      std::vector<u16> ord1471({1, 2, 0});
      slog::Relation* readrel1472 = db->getRelation("lambda");
      lambdaindex1433 = readrel1472->getIndex(ord1471, false);
      std::vector<u16> ord1473({1, 2, 0});
      slog::Relation* readrel1474 = db->getRelation("lambda");
      lambdaindex1434 = readrel1474->getIndex(ord1473, false);
      std::vector<u16> ord1475({1, 2, 0});
      slog::Relation* readrel1476 = db->getRelation("lambda");
      lambdaindex1435 = readrel1476->getIndex(ord1475, false);
      std::vector<u16> ord1477({1, 0});
      slog::Relation* readrel1478 = db->getRelation("ref");
      refindex1436 = readrel1478->getIndex(ord1477, false);
      std::vector<u16> ord1479({1, 2, 0});
      slog::Relation* readrel1480 = db->getRelation("app");
      appindex1437 = readrel1480->getIndex(ord1479, false);
      std::vector<u16> ord1481({1, 0});
      slog::Relation* readrel1482 = db->getRelation("ref");
      refindex1438 = readrel1482->getIndex(ord1481, false);
      std::vector<u16> ord1483({1, 2, 0});
      slog::Relation* readrel1484 = db->getRelation("lambda");
      lambdaindex1439 = readrel1484->getIndex(ord1483, false);
      std::vector<u16> ord1485({1, 2, 0});
      slog::Relation* readrel1486 = db->getRelation("app");
      appindex1440 = readrel1486->getIndex(ord1485, false);
      std::vector<u16> ord1487({2, 0, 1});
      slog::Relation* readrel1488 = db->getRelation("app");
      appindex1441 = readrel1488->getIndex(ord1487, false);
      std::vector<u16> ord1489({1, 0});
      slog::Relation* readrel1490 = db->getRelation("ref");
      refindex1442 = readrel1490->getIndex(ord1489, false);
      std::vector<u16> ord1491({1, 2, 0});
      slog::Relation* readrel1492 = db->getRelation("lambda");
      lambdaindex1443 = readrel1492->getIndex(ord1491, false);
      std::vector<u16> ord1493({1, 2, 0});
      slog::Relation* readrel1494 = db->getRelation("app");
      appindex1444 = readrel1494->getIndex(ord1493, false);
      std::vector<u16> ord1495({1, 2, 0});
      slog::Relation* readrel1496 = db->getRelation("lambda");
      lambdaindex1445 = readrel1496->getIndex(ord1495, false);
      std::vector<u16> ord1497({1, 0});
      slog::Relation* readrel1498 = db->getRelation("ref");
      refindex1446 = readrel1498->getIndex(ord1497, false);
      std::vector<u16> ord1499({1, 2, 0});
      slog::Relation* readrel1500 = db->getRelation("lambda");
      lambdaindex1447 = readrel1500->getIndex(ord1499, false);
      std::vector<u16> ord1501({1, 2, 0});
      slog::Relation* readrel1502 = db->getRelation("app");
      appindex1448 = readrel1502->getIndex(ord1501, false);
      std::vector<u16> ord1503({1, 2, 0});
      slog::Relation* readrel1504 = db->getRelation("lambda");
      lambdaindex1449 = readrel1504->getIndex(ord1503, false);
      std::vector<u16> ord1505({1, 2, 0});
      slog::Relation* readrel1506 = db->getRelation("app");
      appindex1450 = readrel1506->getIndex(ord1505, false);
      std::vector<u16> ord1507({1, 2, 0});
      slog::Relation* readrel1508 = db->getRelation("lambda");
      lambdaindex1451 = readrel1508->getIndex(ord1507, false);
  
    }
    ReadTask1452(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c102 = v_const81cb39a72a584ab4f703b7f7;
      u64 v_c103 = v_constdbf1bdba02122b2adce28528;
      u64 v_c104 = v_const4d5ce1398140fbe27561181f;
      u64 v_c105 = v_const85f09fa1913b9daf65957cf7;
      u64 v_c106 = v_constd7a1925d249b4768c8a9f2d8;
      u64 v_c107 = v_const969c6e56242ce8d0a4346602;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex1425, std::array<u64,2>{v_c102, 0}, [&](const std::array<u64,2>& m1509) {
        u64 v_c110 = m1509[1];
        if (!slog::exists_probe<2,1>(refindex1426, std::array<u64,2>{v_c105, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1427, std::array<u64,3>{v_c105, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex1428, std::array<u64,3>{v_c110, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1429, std::array<u64,2>{v_c106, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1430, std::array<u64,3>{v_c106, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1431, std::array<u64,3>{v_c103, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1432, std::array<u64,2>{v_c107, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1433, std::array<u64,3>{v_c107, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1434, std::array<u64,3>{v_c104, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1435, std::array<u64,3>{v_c102, 0, 0})) return;
        slog::join_probe<2,1>(refindex1436, std::array<u64,2>{v_c103, 0}, [&](const std::array<u64,2>& m1510) {
          u64 v_c111 = m1510[1];
          if (!slog::exists_probe<3,1>(appindex1437, std::array<u64,3>{v_c111, 0, 0})) return;
          slog::join_probe<2,1>(refindex1438, std::array<u64,2>{v_c105, 0}, [&](const std::array<u64,2>& m1511) {
            u64 v_c112 = m1511[1];
            slog::join_probe<3,2>(lambdaindex1439, std::array<u64,3>{v_c105, v_c112, 0}, [&](const std::array<u64,3>& m1512) {
              u64 v_c113 = m1512[2];
              slog::join_probe<3,2>(appindex1440, std::array<u64,3>{v_c110, v_c113, 0}, [&](const std::array<u64,3>& m1513) {
                u64 v_c114 = m1513[2];
                if (!slog::exists_probe<3,1>(appindex1441, std::array<u64,3>{v_c114, 0, 0})) return;
                slog::join_probe<2,1>(refindex1442, std::array<u64,2>{v_c106, 0}, [&](const std::array<u64,2>& m1514) {
                  u64 v_c119 = m1514[1];
                  slog::join_probe<3,2>(lambdaindex1443, std::array<u64,3>{v_c106, v_c119, 0}, [&](const std::array<u64,3>& m1515) {
                    u64 v_c120 = m1515[2];
                    slog::join_probe<3,2>(appindex1444, std::array<u64,3>{v_c111, v_c120, 0}, [&](const std::array<u64,3>& m1516) {
                      u64 v_c121 = m1516[2];
                      slog::join_probe<3,2>(lambdaindex1445, std::array<u64,3>{v_c103, v_c121, 0}, [&](const std::array<u64,3>& m1517) {
                        u64 v_c122 = m1517[2];
                        slog::join_probe<2,1>(refindex1446, std::array<u64,2>{v_c107, 0}, [&](const std::array<u64,2>& m1518) {
                          u64 v_c118 = m1518[1];
                          slog::join_probe<3,2>(lambdaindex1447, std::array<u64,3>{v_c107, v_c118, 0}, [&](const std::array<u64,3>& m1519) {
                            u64 v_c117 = m1519[2];
                            slog::join_probe<3,2>(appindex1448, std::array<u64,3>{v_c110, v_c117, 0}, [&](const std::array<u64,3>& m1520) {
                              u64 v_c116 = m1520[2];
                              slog::join_probe<3,2>(lambdaindex1449, std::array<u64,3>{v_c104, v_c116, 0}, [&](const std::array<u64,3>& m1521) {
                                u64 v_c115 = m1521[2];
                                slog::join_probe<3,2>(appindex1450, std::array<u64,3>{v_c115, v_c114, 0}, [&](const std::array<u64,3>& m1522) {
                                  u64 v_c108 = m1522[2];
                                  slog::join_probe<3,2>(lambdaindex1451, std::array<u64,3>{v_c102, v_c108, 0}, [&](const std::array<u64,3>& m1523) {
                                    u64 v_c109 = m1523[2];
                                    ++_fires;
                                    slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c109, v_c122}, std::array<u16,3>{1, 2, 0});
                                  });
                                });
                              });
                            });
                          });
                        });
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
      s->addTaskSeeded(phase_read, new ReadTask1452(db,b));
  // (crule (pre) (scan freevar y __t4I265) (body (join store (0 1 2) 1 y cb vy) (join-old lambda (0 1 2) 1 (0 1 2) __t4I265 x eb) (join-old eval (0 2 1) 0 (0 2 1) __4DdV347 c __t5Yh14) (join-old app (0 1 2) 1 (0 1 2) __t5Yh14 ef ea)) (head (mkstruct eval (1 2 0) __34Tv348 ea c)) mcfa-counting.slog:102 #f)
  class ReadTask1531 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** storeindex1524;  slog::Index** lambdaindex1525;  slog::Index** evalindex1526;  slog::Index** appindex1527;  slog::Index** lambdadelta1528;  slog::Index** evaldelta1529;  slog::Index** appdelta1530;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("freevar");
      std::vector<u16> ord1532({0, 1, 2});
      slog::Relation* readrel1533 = db->getRelation("store");
      storeindex1524 = readrel1533->getIndex(ord1532, false);
      std::vector<u16> ord1534({0, 1, 2});
      slog::Relation* readrel1535 = db->getRelation("lambda");
      lambdaindex1525 = readrel1535->getIndex(ord1534, false);
      std::vector<u16> ord1536({0, 1, 2});
      slog::Relation* readrel1537 = db->getRelation("lambda");
      lambdadelta1528 = readrel1537->getIndex(ord1536, true);
      std::vector<u16> ord1538({0, 2, 1});
      slog::Relation* readrel1539 = db->getRelation("eval");
      evalindex1526 = readrel1539->getIndex(ord1538, false);
      std::vector<u16> ord1540({0, 2, 1});
      slog::Relation* readrel1541 = db->getRelation("eval");
      evaldelta1529 = readrel1541->getIndex(ord1540, true);
      std::vector<u16> ord1542({0, 1, 2});
      slog::Relation* readrel1543 = db->getRelation("app");
      appindex1527 = readrel1543->getIndex(ord1542, false);
      std::vector<u16> ord1544({0, 1, 2});
      slog::Relation* readrel1545 = db->getRelation("app");
      appdelta1530 = readrel1545->getIndex(ord1544, true);
  
    }
    ReadTask1531(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c125 = _t[1];
        slog::join_probe<3,1>(storeindex1524, std::array<u64,3>{v_c123, 0, 0}, [&](const std::array<u64,3>& m1546) {
          u64 v_c76 = m1546[1]; u64 v_c124 = m1546[2];
          slog::join_probe_old<3,1>(lambdaindex1525, lambdadelta1528, std::array<u64,3>{v_c125, 0, 0}, [&](const std::array<u64,3>& m1547) {
            u64 v_c78 = m1547[1]; u64 v_c79 = m1547[2];
            slog::join_all_old<3>(evalindex1526, evaldelta1529, [&](const std::array<u64,3>& m1548) {
              u64 v_c126 = m1548[0]; u64 v_c70 = m1548[1]; u64 v_c127 = m1548[2];
              slog::join_probe_old<3,1>(appindex1527, appdelta1530, std::array<u64,3>{v_c127, 0, 0}, [&](const std::array<u64,3>& m1549) {
                u64 v_c68 = m1549[1]; u64 v_c69 = m1549[2];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c69, v_c70}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:102", "delta:freevar", _fires);
  
      if (!_done)
      {
        ReadTask1531* _cont = new ReadTask1531(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1531(db,b), false);
  // (crule (pre) (scan eval __t0yID79 __t5qnk78 c) (body (join app (0 1 2) 1 __t5qnk78 ef ea)) (head (emit $sup27994x83x0x0x0 (0 1 2 3) __t0yID79 c ea ef)) mcfa-counting.slog:84 #f)
  class ReadTask1551 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex1550;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup27994x83x0x0x0");
      std::vector<u16> ord1552({0, 1, 2, 3});
      slog::Relation* readrel1553 = db->getRelation("$sup27994x83x0x0x0");
      head_index[0] = readrel1553->getIndex(ord1552, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord1554({0, 1, 2});
      slog::Relation* readrel1555 = db->getRelation("app");
      appindex1550 = readrel1555->getIndex(ord1554, false);
  
    }
    ReadTask1551(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c208 = _t[0];
        u64 v_c209 = _t[1];
        u64 v_c70 = _t[2];
        slog::join_probe<3,1>(appindex1550, std::array<u64,3>{v_c209, 0, 0}, [&](const std::array<u64,3>& m1556) {
          u64 v_c68 = m1556[1]; u64 v_c69 = m1556[2];
          ++_fires;
          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c208, v_c70, v_c69, v_c68}, std::array<u16,4>{0, 1, 2, 3});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:84", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask1551* _cont = new ReadTask1551(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1551(db,b), false);
  // (crule (pre (let __tconst0y6X73 const0aa6f87434af0222b916e97a) (let __tconst7zoP70 const227d34ceeba7a29aada993d4) (let __tconst0aL952 constd3d07026d47882ceca728218) (let __tconst1bfe65 const59ba3256d223f0d0a00d0633) (let __tconst8wN863 const7cd75b35aa30c3ddf04f9d57) (let __tconst0xUh47 constf700a82e218a86de572e1f7f)) (probe lambda (1 2 0) 1 __tconst0aL952 __t05NY51 __t3xtz53) (body (exists ref (1 0) 1 __tconst0aL952) (exists lambda (1 2 0) 1 __tconst0xUh47) (exists ref (1 0) 1 __tconst0xUh47) (exists ref (1 0) 1 __tconst1bfe65) (exists lambda (1 2 0) 1 __tconst1bfe65) (exists ref (1 0) 1 __tconst8wN863) (exists lambda (1 2 0) 1 __tconst8wN863) (join ref (1 0) 1 __tconst0y6X73 __t0QRr59) (exists app (1 2 0) 1 __t0QRr59) (join ref (1 0) 1 __tconst0aL952 __t5HQ450) (join app (0 1 2) 2 __t05NY51 __t5HQ450 __t50zW48) (join lambda (0 1 2) 2 __t50zW48 __tconst0xUh47 __t5vZb46) (join ref (0 1) 2 __t5vZb46 __tconst0xUh47) (join ref (1 0) 1 __tconst1bfe65 __t2HsD55) (join lambda (1 2 0) 2 __tconst1bfe65 __t2HsD55 __t0uNb57) (join app (1 2 0) 2 __t0QRr59 __t0uNb57 __t81HE60) (join ref (1 0) 1 __tconst8wN863 __t1mkO62) (join lambda (1 2 0) 2 __tconst8wN863 __t1mkO62 __t3Dru64) (join lambda (1 2 0) 2 __tconst1bfe65 __t3Dru64 __t7JIT66) (join app (1 2 0) 2 __t0QRr59 __t7JIT66 __t5Ri569)) (head (mkstruct lambda (1 2 0) __t7KAC71 __tconst7zoP70 __t5Ri569)) mcfa-counting.slog:287 #f)
  class ReadTask1577 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** refindex1557;  slog::Index** lambdaindex1558;  slog::Index** refindex1559;  slog::Index** refindex1560;  slog::Index** lambdaindex1561;  slog::Index** refindex1562;  slog::Index** lambdaindex1563;  slog::Index** refindex1564;  slog::Index** appindex1565;  slog::Index** refindex1566;  slog::Index** appindex1567;  slog::Index** lambdaindex1568;  slog::Index** refindex1569;  slog::Index** refindex1570;  slog::Index** lambdaindex1571;  slog::Index** appindex1572;  slog::Index** refindex1573;  slog::Index** lambdaindex1574;  slog::Index** lambdaindex1575;  slog::Index** appindex1576;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      std::vector<u16> ord1578({1, 2, 0});
      slog::Relation* readrel1579 = db->getRelation("lambda");
      driver_index = readrel1579->getIndex(ord1578, true);
      std::vector<u16> ord1580({1, 0});
      slog::Relation* readrel1581 = db->getRelation("ref");
      refindex1557 = readrel1581->getIndex(ord1580, false);
      std::vector<u16> ord1582({1, 2, 0});
      slog::Relation* readrel1583 = db->getRelation("lambda");
      lambdaindex1558 = readrel1583->getIndex(ord1582, false);
      std::vector<u16> ord1584({1, 0});
      slog::Relation* readrel1585 = db->getRelation("ref");
      refindex1559 = readrel1585->getIndex(ord1584, false);
      std::vector<u16> ord1586({1, 0});
      slog::Relation* readrel1587 = db->getRelation("ref");
      refindex1560 = readrel1587->getIndex(ord1586, false);
      std::vector<u16> ord1588({1, 2, 0});
      slog::Relation* readrel1589 = db->getRelation("lambda");
      lambdaindex1561 = readrel1589->getIndex(ord1588, false);
      std::vector<u16> ord1590({1, 0});
      slog::Relation* readrel1591 = db->getRelation("ref");
      refindex1562 = readrel1591->getIndex(ord1590, false);
      std::vector<u16> ord1592({1, 2, 0});
      slog::Relation* readrel1593 = db->getRelation("lambda");
      lambdaindex1563 = readrel1593->getIndex(ord1592, false);
      std::vector<u16> ord1594({1, 0});
      slog::Relation* readrel1595 = db->getRelation("ref");
      refindex1564 = readrel1595->getIndex(ord1594, false);
      std::vector<u16> ord1596({1, 2, 0});
      slog::Relation* readrel1597 = db->getRelation("app");
      appindex1565 = readrel1597->getIndex(ord1596, false);
      std::vector<u16> ord1598({1, 0});
      slog::Relation* readrel1599 = db->getRelation("ref");
      refindex1566 = readrel1599->getIndex(ord1598, false);
      std::vector<u16> ord1600({0, 1, 2});
      slog::Relation* readrel1601 = db->getRelation("app");
      appindex1567 = readrel1601->getIndex(ord1600, false);
      std::vector<u16> ord1602({0, 1, 2});
      slog::Relation* readrel1603 = db->getRelation("lambda");
      lambdaindex1568 = readrel1603->getIndex(ord1602, false);
      std::vector<u16> ord1604({0, 1});
      slog::Relation* readrel1605 = db->getRelation("ref");
      refindex1569 = readrel1605->getIndex(ord1604, false);
      std::vector<u16> ord1606({1, 0});
      slog::Relation* readrel1607 = db->getRelation("ref");
      refindex1570 = readrel1607->getIndex(ord1606, false);
      std::vector<u16> ord1608({1, 2, 0});
      slog::Relation* readrel1609 = db->getRelation("lambda");
      lambdaindex1571 = readrel1609->getIndex(ord1608, false);
      std::vector<u16> ord1610({1, 2, 0});
      slog::Relation* readrel1611 = db->getRelation("app");
      appindex1572 = readrel1611->getIndex(ord1610, false);
      std::vector<u16> ord1612({1, 0});
      slog::Relation* readrel1613 = db->getRelation("ref");
      refindex1573 = readrel1613->getIndex(ord1612, false);
      std::vector<u16> ord1614({1, 2, 0});
      slog::Relation* readrel1615 = db->getRelation("lambda");
      lambdaindex1574 = readrel1615->getIndex(ord1614, false);
      std::vector<u16> ord1616({1, 2, 0});
      slog::Relation* readrel1617 = db->getRelation("lambda");
      lambdaindex1575 = readrel1617->getIndex(ord1616, false);
      std::vector<u16> ord1618({1, 2, 0});
      slog::Relation* readrel1619 = db->getRelation("app");
      appindex1576 = readrel1619->getIndex(ord1618, false);
  
    }
    ReadTask1577(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c48 = v_const0aa6f87434af0222b916e97a;
      u64 v_c49 = v_const227d34ceeba7a29aada993d4;
      u64 v_c50 = v_constd3d07026d47882ceca728218;
      u64 v_c51 = v_const59ba3256d223f0d0a00d0633;
      u64 v_c52 = v_const7cd75b35aa30c3ddf04f9d57;
      u64 v_c53 = v_constf700a82e218a86de572e1f7f;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c50, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1620) {
        u64 v_c58 = m1620[1];
        u64 v_c59 = m1620[2];
        if (buckethash(v_c58) != bucket) return;
        if (!slog::exists_probe<2,1>(refindex1557, std::array<u64,2>{v_c50, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1558, std::array<u64,3>{v_c53, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1559, std::array<u64,2>{v_c53, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1560, std::array<u64,2>{v_c51, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1561, std::array<u64,3>{v_c51, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1562, std::array<u64,2>{v_c52, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1563, std::array<u64,3>{v_c52, 0, 0})) return;
        slog::join_probe<2,1>(refindex1564, std::array<u64,2>{v_c48, 0}, [&](const std::array<u64,2>& m1621) {
          u64 v_c54 = m1621[1];
          if (!slog::exists_probe<3,1>(appindex1565, std::array<u64,3>{v_c54, 0, 0})) return;
          slog::join_probe<2,1>(refindex1566, std::array<u64,2>{v_c50, 0}, [&](const std::array<u64,2>& m1622) {
            u64 v_c55 = m1622[1];
            slog::join_probe<3,2>(appindex1567, std::array<u64,3>{v_c58, v_c55, 0}, [&](const std::array<u64,3>& m1623) {
              u64 v_c57 = m1623[2];
              slog::join_probe<3,2>(lambdaindex1568, std::array<u64,3>{v_c57, v_c53, 0}, [&](const std::array<u64,3>& m1624) {
                u64 v_c56 = m1624[2];
                slog::join_probe<2,2>(refindex1569, std::array<u64,2>{v_c56, v_c53}, [&](const std::array<u64,2>& m1625) {
                  slog::join_probe<2,1>(refindex1570, std::array<u64,2>{v_c51, 0}, [&](const std::array<u64,2>& m1626) {
                    u64 v_c60 = m1626[1];
                    slog::join_probe<3,2>(lambdaindex1571, std::array<u64,3>{v_c51, v_c60, 0}, [&](const std::array<u64,3>& m1627) {
                      u64 v_c61 = m1627[2];
                      slog::join_probe<3,2>(appindex1572, std::array<u64,3>{v_c54, v_c61, 0}, [&](const std::array<u64,3>& m1628) {
                        u64 v_c62 = m1628[2];
                        slog::join_probe<2,1>(refindex1573, std::array<u64,2>{v_c52, 0}, [&](const std::array<u64,2>& m1629) {
                          u64 v_c63 = m1629[1];
                          slog::join_probe<3,2>(lambdaindex1574, std::array<u64,3>{v_c52, v_c63, 0}, [&](const std::array<u64,3>& m1630) {
                            u64 v_c64 = m1630[2];
                            slog::join_probe<3,2>(lambdaindex1575, std::array<u64,3>{v_c51, v_c64, 0}, [&](const std::array<u64,3>& m1631) {
                              u64 v_c65 = m1631[2];
                              slog::join_probe<3,2>(appindex1576, std::array<u64,3>{v_c54, v_c65, 0}, [&](const std::array<u64,3>& m1632) {
                                u64 v_c66 = m1632[2];
                                ++_fires;
                                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c49, v_c66}, std::array<u16,3>{1, 2, 0});
                              });
                            });
                          });
                        });
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
        ReadTask1577* _cont = new ReadTask1577(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1577(db,b), false);
  // (crule (pre (let __tconst1pJW313 constb49bea2fcccd8f4301a347ed) (let __tconst2Yzp284 const8ca682693a0738a0641c6956) (let __tconst7LWP310 const66518c0c1b3a5a0b09ae2ef1) (let __tconst5PoN291 constc85eae03730a4f4cf1d66a0c) (let __tconst0sqO307 const4a8acfc71441e0695ffcf5b3) (let __tconst9rZO295 const576506f61f53440f1edd95d2) (let __tconst2CSv302 const229c0b7aa8a7eb4055f5a3d0)) (probe lambda (1 2 0) 1 __tconst1pJW313 __t3Izn312 __t7Qbz314) (body (exists lambda (1 2 0) 1 __tconst2Yzp284) (exists ref (1 0) 1 __tconst1pJW313) (exists ref (1 0) 1 __tconst7LWP310) (exists ref (1 0) 1 __tconst9rZO295) (exists lambda (1 2 0) 1 __tconst9rZO295) (exists ref (1 0) 1 __tconst2CSv302) (exists lambda (1 2 0) 1 __tconst2CSv302) (exists lambda (1 2 0) 1 __tconst0sqO307) (exists lambda (1 2 0) 1 __tconst7LWP310) (exists lambda (1 2 0) 1 __tconst5PoN291) (join ref (1 0) 1 __tconst2Yzp284 __t248W283) (join lambda (1 2 0) 2 __tconst2Yzp284 __t248W283 __t0oFu285) (join ref (1 0) 1 __tconst1pJW313 __t165O287) (exists app (1 2 0) 1 __t165O287) (join ref (1 0) 1 __tconst7LWP310 __t91H2298) (exists app (1 2 0) 1 __t91H2298) (join ref (1 0) 1 __tconst9rZO295 __t71w7294) (join lambda (1 2 0) 2 __tconst9rZO295 __t71w7294 __t3dkk296) (join app (1 2 0) 2 __t91H2298 __t3dkk296 __t4LtH299) (exists app (2 0 1) 1 __t4LtH299) (join ref (1 0) 1 __tconst2CSv302 __t6lXa301) (join lambda (1 2 0) 2 __tconst2CSv302 __t6lXa301 __t7EW2303) (join app (1 2 0) 2 __t91H2298 __t7EW2303 __t4HUX306) (join lambda (1 2 0) 2 __tconst0sqO307 __t4HUX306 __t0vn1308) (join app (1 2 0) 2 __t0vn1308 __t4LtH299 __t6t9L309) (join lambda (1 2 0) 2 __tconst7LWP310 __t6t9L309 __t5T0g311) (join app (0 1 2) 2 __t3Izn312 __t5T0g311 __t7aCZ292) (join lambda (0 1 2) 2 __t7aCZ292 __tconst5PoN291 __t30Ec290) (join app (0 1 2) 2 __t30Ec290 __t165O287 dup2AUt387) (eq __t165O287 dup2AUt387)) (head (mkstruct app (1 2 0) __t1Lkt315 __t7Qbz314 __t0oFu285)) mcfa-counting.slog:194 #f)
  class ReadTask1662 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** lambdaindex1633;  slog::Index** refindex1634;  slog::Index** refindex1635;  slog::Index** refindex1636;  slog::Index** lambdaindex1637;  slog::Index** refindex1638;  slog::Index** lambdaindex1639;  slog::Index** lambdaindex1640;  slog::Index** lambdaindex1641;  slog::Index** lambdaindex1642;  slog::Index** refindex1643;  slog::Index** lambdaindex1644;  slog::Index** refindex1645;  slog::Index** appindex1646;  slog::Index** refindex1647;  slog::Index** appindex1648;  slog::Index** refindex1649;  slog::Index** lambdaindex1650;  slog::Index** appindex1651;  slog::Index** appindex1652;  slog::Index** refindex1653;  slog::Index** lambdaindex1654;  slog::Index** appindex1655;  slog::Index** lambdaindex1656;  slog::Index** appindex1657;  slog::Index** lambdaindex1658;  slog::Index** appindex1659;  slog::Index** lambdaindex1660;  slog::Index** appindex1661;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord1663({1, 2, 0});
      slog::Relation* readrel1664 = db->getRelation("lambda");
      driver_index = readrel1664->getIndex(ord1663, true);
      std::vector<u16> ord1665({1, 2, 0});
      slog::Relation* readrel1666 = db->getRelation("lambda");
      lambdaindex1633 = readrel1666->getIndex(ord1665, false);
      std::vector<u16> ord1667({1, 0});
      slog::Relation* readrel1668 = db->getRelation("ref");
      refindex1634 = readrel1668->getIndex(ord1667, false);
      std::vector<u16> ord1669({1, 0});
      slog::Relation* readrel1670 = db->getRelation("ref");
      refindex1635 = readrel1670->getIndex(ord1669, false);
      std::vector<u16> ord1671({1, 0});
      slog::Relation* readrel1672 = db->getRelation("ref");
      refindex1636 = readrel1672->getIndex(ord1671, false);
      std::vector<u16> ord1673({1, 2, 0});
      slog::Relation* readrel1674 = db->getRelation("lambda");
      lambdaindex1637 = readrel1674->getIndex(ord1673, false);
      std::vector<u16> ord1675({1, 0});
      slog::Relation* readrel1676 = db->getRelation("ref");
      refindex1638 = readrel1676->getIndex(ord1675, false);
      std::vector<u16> ord1677({1, 2, 0});
      slog::Relation* readrel1678 = db->getRelation("lambda");
      lambdaindex1639 = readrel1678->getIndex(ord1677, false);
      std::vector<u16> ord1679({1, 2, 0});
      slog::Relation* readrel1680 = db->getRelation("lambda");
      lambdaindex1640 = readrel1680->getIndex(ord1679, false);
      std::vector<u16> ord1681({1, 2, 0});
      slog::Relation* readrel1682 = db->getRelation("lambda");
      lambdaindex1641 = readrel1682->getIndex(ord1681, false);
      std::vector<u16> ord1683({1, 2, 0});
      slog::Relation* readrel1684 = db->getRelation("lambda");
      lambdaindex1642 = readrel1684->getIndex(ord1683, false);
      std::vector<u16> ord1685({1, 0});
      slog::Relation* readrel1686 = db->getRelation("ref");
      refindex1643 = readrel1686->getIndex(ord1685, false);
      std::vector<u16> ord1687({1, 2, 0});
      slog::Relation* readrel1688 = db->getRelation("lambda");
      lambdaindex1644 = readrel1688->getIndex(ord1687, false);
      std::vector<u16> ord1689({1, 0});
      slog::Relation* readrel1690 = db->getRelation("ref");
      refindex1645 = readrel1690->getIndex(ord1689, false);
      std::vector<u16> ord1691({1, 2, 0});
      slog::Relation* readrel1692 = db->getRelation("app");
      appindex1646 = readrel1692->getIndex(ord1691, false);
      std::vector<u16> ord1693({1, 0});
      slog::Relation* readrel1694 = db->getRelation("ref");
      refindex1647 = readrel1694->getIndex(ord1693, false);
      std::vector<u16> ord1695({1, 2, 0});
      slog::Relation* readrel1696 = db->getRelation("app");
      appindex1648 = readrel1696->getIndex(ord1695, false);
      std::vector<u16> ord1697({1, 0});
      slog::Relation* readrel1698 = db->getRelation("ref");
      refindex1649 = readrel1698->getIndex(ord1697, false);
      std::vector<u16> ord1699({1, 2, 0});
      slog::Relation* readrel1700 = db->getRelation("lambda");
      lambdaindex1650 = readrel1700->getIndex(ord1699, false);
      std::vector<u16> ord1701({1, 2, 0});
      slog::Relation* readrel1702 = db->getRelation("app");
      appindex1651 = readrel1702->getIndex(ord1701, false);
      std::vector<u16> ord1703({2, 0, 1});
      slog::Relation* readrel1704 = db->getRelation("app");
      appindex1652 = readrel1704->getIndex(ord1703, false);
      std::vector<u16> ord1705({1, 0});
      slog::Relation* readrel1706 = db->getRelation("ref");
      refindex1653 = readrel1706->getIndex(ord1705, false);
      std::vector<u16> ord1707({1, 2, 0});
      slog::Relation* readrel1708 = db->getRelation("lambda");
      lambdaindex1654 = readrel1708->getIndex(ord1707, false);
      std::vector<u16> ord1709({1, 2, 0});
      slog::Relation* readrel1710 = db->getRelation("app");
      appindex1655 = readrel1710->getIndex(ord1709, false);
      std::vector<u16> ord1711({1, 2, 0});
      slog::Relation* readrel1712 = db->getRelation("lambda");
      lambdaindex1656 = readrel1712->getIndex(ord1711, false);
      std::vector<u16> ord1713({1, 2, 0});
      slog::Relation* readrel1714 = db->getRelation("app");
      appindex1657 = readrel1714->getIndex(ord1713, false);
      std::vector<u16> ord1715({1, 2, 0});
      slog::Relation* readrel1716 = db->getRelation("lambda");
      lambdaindex1658 = readrel1716->getIndex(ord1715, false);
      std::vector<u16> ord1717({0, 1, 2});
      slog::Relation* readrel1718 = db->getRelation("app");
      appindex1659 = readrel1718->getIndex(ord1717, false);
      std::vector<u16> ord1719({0, 1, 2});
      slog::Relation* readrel1720 = db->getRelation("lambda");
      lambdaindex1660 = readrel1720->getIndex(ord1719, false);
      std::vector<u16> ord1721({0, 1, 2});
      slog::Relation* readrel1722 = db->getRelation("app");
      appindex1661 = readrel1722->getIndex(ord1721, false);
  
    }
    ReadTask1662(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c80 = v_constb49bea2fcccd8f4301a347ed;
      u64 v_c84 = v_const8ca682693a0738a0641c6956;
      u64 v_c81 = v_const66518c0c1b3a5a0b09ae2ef1;
      u64 v_c83 = v_constc85eae03730a4f4cf1d66a0c;
      u64 v_c82 = v_const4a8acfc71441e0695ffcf5b3;
      u64 v_c86 = v_const576506f61f53440f1edd95d2;
      u64 v_c85 = v_const229c0b7aa8a7eb4055f5a3d0;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c80, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1723) {
        u64 v_c210 = m1723[1];
        u64 v_c211 = m1723[2];
        if (buckethash(v_c210) != bucket) return;
        if (!slog::exists_probe<3,1>(lambdaindex1633, std::array<u64,3>{v_c84, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1634, std::array<u64,2>{v_c80, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1635, std::array<u64,2>{v_c81, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1636, std::array<u64,2>{v_c86, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1637, std::array<u64,3>{v_c86, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1638, std::array<u64,2>{v_c85, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1639, std::array<u64,3>{v_c85, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1640, std::array<u64,3>{v_c82, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1641, std::array<u64,3>{v_c81, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1642, std::array<u64,3>{v_c83, 0, 0})) return;
        slog::join_probe<2,1>(refindex1643, std::array<u64,2>{v_c84, 0}, [&](const std::array<u64,2>& m1724) {
          u64 v_c92 = m1724[1];
          slog::join_probe<3,2>(lambdaindex1644, std::array<u64,3>{v_c84, v_c92, 0}, [&](const std::array<u64,3>& m1725) {
            u64 v_c93 = m1725[2];
            slog::join_probe<2,1>(refindex1645, std::array<u64,2>{v_c80, 0}, [&](const std::array<u64,2>& m1726) {
              u64 v_c94 = m1726[1];
              if (!slog::exists_probe<3,1>(appindex1646, std::array<u64,3>{v_c94, 0, 0})) return;
              slog::join_probe<2,1>(refindex1647, std::array<u64,2>{v_c81, 0}, [&](const std::array<u64,2>& m1727) {
                u64 v_c89 = m1727[1];
                if (!slog::exists_probe<3,1>(appindex1648, std::array<u64,3>{v_c89, 0, 0})) return;
                slog::join_probe<2,1>(refindex1649, std::array<u64,2>{v_c86, 0}, [&](const std::array<u64,2>& m1728) {
                  u64 v_c95 = m1728[1];
                  slog::join_probe<3,2>(lambdaindex1650, std::array<u64,3>{v_c86, v_c95, 0}, [&](const std::array<u64,3>& m1729) {
                    u64 v_c96 = m1729[2];
                    slog::join_probe<3,2>(appindex1651, std::array<u64,3>{v_c89, v_c96, 0}, [&](const std::array<u64,3>& m1730) {
                      u64 v_c97 = m1730[2];
                      if (!slog::exists_probe<3,1>(appindex1652, std::array<u64,3>{v_c97, 0, 0})) return;
                      slog::join_probe<2,1>(refindex1653, std::array<u64,2>{v_c85, 0}, [&](const std::array<u64,2>& m1731) {
                        u64 v_c91 = m1731[1];
                        slog::join_probe<3,2>(lambdaindex1654, std::array<u64,3>{v_c85, v_c91, 0}, [&](const std::array<u64,3>& m1732) {
                          u64 v_c90 = m1732[2];
                          slog::join_probe<3,2>(appindex1655, std::array<u64,3>{v_c89, v_c90, 0}, [&](const std::array<u64,3>& m1733) {
                            u64 v_c87 = m1733[2];
                            slog::join_probe<3,2>(lambdaindex1656, std::array<u64,3>{v_c82, v_c87, 0}, [&](const std::array<u64,3>& m1734) {
                              u64 v_c88 = m1734[2];
                              slog::join_probe<3,2>(appindex1657, std::array<u64,3>{v_c88, v_c97, 0}, [&](const std::array<u64,3>& m1735) {
                                u64 v_c212 = m1735[2];
                                slog::join_probe<3,2>(lambdaindex1658, std::array<u64,3>{v_c81, v_c212, 0}, [&](const std::array<u64,3>& m1736) {
                                  u64 v_c213 = m1736[2];
                                  slog::join_probe<3,2>(appindex1659, std::array<u64,3>{v_c210, v_c213, 0}, [&](const std::array<u64,3>& m1737) {
                                    u64 v_c100 = m1737[2];
                                    slog::join_probe<3,2>(lambdaindex1660, std::array<u64,3>{v_c100, v_c83, 0}, [&](const std::array<u64,3>& m1738) {
                                      u64 v_c99 = m1738[2];
                                      slog::join_probe<3,2>(appindex1661, std::array<u64,3>{v_c99, v_c94, 0}, [&](const std::array<u64,3>& m1739) {
                                        u64 v_c214 = m1739[2];
                                        if (v_c94 != v_c214) return;
                                        ++_fires;
                                        slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c211, v_c93}, std::array<u16,3>{1, 2, 0});
                                      });
                                    });
                                  });
                                });
                              });
                            });
                          });
                        });
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
        ReadTask1662* _cont = new ReadTask1662(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1662(db,b), false);
  // (crule (pre (let __tconst0y6X73 const0aa6f87434af0222b916e97a) (let __tconst0aL952 constd3d07026d47882ceca728218) (let __tconst7zoP70 const227d34ceeba7a29aada993d4) (let __tconst1bfe65 const59ba3256d223f0d0a00d0633) (let __tconst0xUh47 constf700a82e218a86de572e1f7f) (let __tconst8wN863 const7cd75b35aa30c3ddf04f9d57)) (seeded) (body (join ref (1 0) 1 __tconst0y6X73 __t0QRr59) (exists ref (1 0) 1 __tconst1bfe65) (exists lambda (1 2 0) 1 __tconst1bfe65) (exists app (1 2 0) 1 __t0QRr59) (exists ref (1 0) 1 __tconst0xUh47) (exists lambda (1 2 0) 1 __tconst0xUh47) (exists lambda (1 2 0) 1 __tconst0aL952) (exists ref (1 0) 1 __tconst8wN863) (exists lambda (1 2 0) 1 __tconst8wN863) (exists lambda (1 2 0) 1 __tconst7zoP70) (exists lambda (1 2 0) 1 __tconst0y6X73) (join ref (1 0) 1 __tconst0aL952 __t5HQ450) (exists app (1 2 0) 1 __t5HQ450) (join ref (1 0) 1 __tconst1bfe65 __t2HsD55) (join lambda (1 2 0) 2 __tconst1bfe65 __t2HsD55 __t0uNb57) (join app (1 2 0) 2 __t0QRr59 __t0uNb57 __t81HE60) (exists app (2 0 1) 1 __t81HE60) (join ref (1 0) 1 __tconst0xUh47 __t5vZb46) (join lambda (1 2 0) 2 __tconst0xUh47 __t5vZb46 __t50zW48) (join app (1 2 0) 2 __t5HQ450 __t50zW48 __t05NY51) (join lambda (1 2 0) 2 __tconst0aL952 __t05NY51 __t3xtz53) (join ref (1 0) 1 __tconst8wN863 __t1mkO62) (join lambda (1 2 0) 2 __tconst8wN863 __t1mkO62 __t3Dru64) (join lambda (1 2 0) 2 __tconst1bfe65 __t3Dru64 __t7JIT66) (join app (1 2 0) 2 __t0QRr59 __t7JIT66 __t5Ri569) (join lambda (1 2 0) 2 __tconst7zoP70 __t5Ri569 __t7KAC71) (join app (1 2 0) 2 __t7KAC71 __t81HE60 __t9kFz72) (join lambda (1 2 0) 2 __tconst0y6X73 __t9kFz72 __t9J4m74)) (head (mkstruct app (1 2 0) __t5ePS75 __t9J4m74 __t3xtz53)) mcfa-counting.slog:287 #f)
  class ReadTask1768 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex1740;  slog::Index** refindex1741;  slog::Index** lambdaindex1742;  slog::Index** appindex1743;  slog::Index** refindex1744;  slog::Index** lambdaindex1745;  slog::Index** lambdaindex1746;  slog::Index** refindex1747;  slog::Index** lambdaindex1748;  slog::Index** lambdaindex1749;  slog::Index** lambdaindex1750;  slog::Index** refindex1751;  slog::Index** appindex1752;  slog::Index** refindex1753;  slog::Index** lambdaindex1754;  slog::Index** appindex1755;  slog::Index** appindex1756;  slog::Index** refindex1757;  slog::Index** lambdaindex1758;  slog::Index** appindex1759;  slog::Index** lambdaindex1760;  slog::Index** refindex1761;  slog::Index** lambdaindex1762;  slog::Index** lambdaindex1763;  slog::Index** appindex1764;  slog::Index** lambdaindex1765;  slog::Index** appindex1766;  slog::Index** lambdaindex1767;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord1769({1, 2, 0});
      slog::Relation* readrel1770 = db->getRelation("app");
      head_index[0] = readrel1770->getIndex(ord1769, false);
      std::vector<u16> ord1771({1, 0});
      slog::Relation* readrel1772 = db->getRelation("ref");
      refindex1740 = readrel1772->getIndex(ord1771, false);
      std::vector<u16> ord1773({1, 0});
      slog::Relation* readrel1774 = db->getRelation("ref");
      refindex1741 = readrel1774->getIndex(ord1773, false);
      std::vector<u16> ord1775({1, 2, 0});
      slog::Relation* readrel1776 = db->getRelation("lambda");
      lambdaindex1742 = readrel1776->getIndex(ord1775, false);
      std::vector<u16> ord1777({1, 2, 0});
      slog::Relation* readrel1778 = db->getRelation("app");
      appindex1743 = readrel1778->getIndex(ord1777, false);
      std::vector<u16> ord1779({1, 0});
      slog::Relation* readrel1780 = db->getRelation("ref");
      refindex1744 = readrel1780->getIndex(ord1779, false);
      std::vector<u16> ord1781({1, 2, 0});
      slog::Relation* readrel1782 = db->getRelation("lambda");
      lambdaindex1745 = readrel1782->getIndex(ord1781, false);
      std::vector<u16> ord1783({1, 2, 0});
      slog::Relation* readrel1784 = db->getRelation("lambda");
      lambdaindex1746 = readrel1784->getIndex(ord1783, false);
      std::vector<u16> ord1785({1, 0});
      slog::Relation* readrel1786 = db->getRelation("ref");
      refindex1747 = readrel1786->getIndex(ord1785, false);
      std::vector<u16> ord1787({1, 2, 0});
      slog::Relation* readrel1788 = db->getRelation("lambda");
      lambdaindex1748 = readrel1788->getIndex(ord1787, false);
      std::vector<u16> ord1789({1, 2, 0});
      slog::Relation* readrel1790 = db->getRelation("lambda");
      lambdaindex1749 = readrel1790->getIndex(ord1789, false);
      std::vector<u16> ord1791({1, 2, 0});
      slog::Relation* readrel1792 = db->getRelation("lambda");
      lambdaindex1750 = readrel1792->getIndex(ord1791, false);
      std::vector<u16> ord1793({1, 0});
      slog::Relation* readrel1794 = db->getRelation("ref");
      refindex1751 = readrel1794->getIndex(ord1793, false);
      std::vector<u16> ord1795({1, 2, 0});
      slog::Relation* readrel1796 = db->getRelation("app");
      appindex1752 = readrel1796->getIndex(ord1795, false);
      std::vector<u16> ord1797({1, 0});
      slog::Relation* readrel1798 = db->getRelation("ref");
      refindex1753 = readrel1798->getIndex(ord1797, false);
      std::vector<u16> ord1799({1, 2, 0});
      slog::Relation* readrel1800 = db->getRelation("lambda");
      lambdaindex1754 = readrel1800->getIndex(ord1799, false);
      std::vector<u16> ord1801({1, 2, 0});
      slog::Relation* readrel1802 = db->getRelation("app");
      appindex1755 = readrel1802->getIndex(ord1801, false);
      std::vector<u16> ord1803({2, 0, 1});
      slog::Relation* readrel1804 = db->getRelation("app");
      appindex1756 = readrel1804->getIndex(ord1803, false);
      std::vector<u16> ord1805({1, 0});
      slog::Relation* readrel1806 = db->getRelation("ref");
      refindex1757 = readrel1806->getIndex(ord1805, false);
      std::vector<u16> ord1807({1, 2, 0});
      slog::Relation* readrel1808 = db->getRelation("lambda");
      lambdaindex1758 = readrel1808->getIndex(ord1807, false);
      std::vector<u16> ord1809({1, 2, 0});
      slog::Relation* readrel1810 = db->getRelation("app");
      appindex1759 = readrel1810->getIndex(ord1809, false);
      std::vector<u16> ord1811({1, 2, 0});
      slog::Relation* readrel1812 = db->getRelation("lambda");
      lambdaindex1760 = readrel1812->getIndex(ord1811, false);
      std::vector<u16> ord1813({1, 0});
      slog::Relation* readrel1814 = db->getRelation("ref");
      refindex1761 = readrel1814->getIndex(ord1813, false);
      std::vector<u16> ord1815({1, 2, 0});
      slog::Relation* readrel1816 = db->getRelation("lambda");
      lambdaindex1762 = readrel1816->getIndex(ord1815, false);
      std::vector<u16> ord1817({1, 2, 0});
      slog::Relation* readrel1818 = db->getRelation("lambda");
      lambdaindex1763 = readrel1818->getIndex(ord1817, false);
      std::vector<u16> ord1819({1, 2, 0});
      slog::Relation* readrel1820 = db->getRelation("app");
      appindex1764 = readrel1820->getIndex(ord1819, false);
      std::vector<u16> ord1821({1, 2, 0});
      slog::Relation* readrel1822 = db->getRelation("lambda");
      lambdaindex1765 = readrel1822->getIndex(ord1821, false);
      std::vector<u16> ord1823({1, 2, 0});
      slog::Relation* readrel1824 = db->getRelation("app");
      appindex1766 = readrel1824->getIndex(ord1823, false);
      std::vector<u16> ord1825({1, 2, 0});
      slog::Relation* readrel1826 = db->getRelation("lambda");
      lambdaindex1767 = readrel1826->getIndex(ord1825, false);
  
    }
    ReadTask1768(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c48 = v_const0aa6f87434af0222b916e97a;
      u64 v_c50 = v_constd3d07026d47882ceca728218;
      u64 v_c49 = v_const227d34ceeba7a29aada993d4;
      u64 v_c51 = v_const59ba3256d223f0d0a00d0633;
      u64 v_c53 = v_constf700a82e218a86de572e1f7f;
      u64 v_c52 = v_const7cd75b35aa30c3ddf04f9d57;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex1740, std::array<u64,2>{v_c48, 0}, [&](const std::array<u64,2>& m1827) {
        u64 v_c54 = m1827[1];
        if (!slog::exists_probe<2,1>(refindex1741, std::array<u64,2>{v_c51, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1742, std::array<u64,3>{v_c51, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex1743, std::array<u64,3>{v_c54, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1744, std::array<u64,2>{v_c53, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1745, std::array<u64,3>{v_c53, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1746, std::array<u64,3>{v_c50, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1747, std::array<u64,2>{v_c52, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1748, std::array<u64,3>{v_c52, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1749, std::array<u64,3>{v_c49, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1750, std::array<u64,3>{v_c48, 0, 0})) return;
        slog::join_probe<2,1>(refindex1751, std::array<u64,2>{v_c50, 0}, [&](const std::array<u64,2>& m1828) {
          u64 v_c55 = m1828[1];
          if (!slog::exists_probe<3,1>(appindex1752, std::array<u64,3>{v_c55, 0, 0})) return;
          slog::join_probe<2,1>(refindex1753, std::array<u64,2>{v_c51, 0}, [&](const std::array<u64,2>& m1829) {
            u64 v_c60 = m1829[1];
            slog::join_probe<3,2>(lambdaindex1754, std::array<u64,3>{v_c51, v_c60, 0}, [&](const std::array<u64,3>& m1830) {
              u64 v_c61 = m1830[2];
              slog::join_probe<3,2>(appindex1755, std::array<u64,3>{v_c54, v_c61, 0}, [&](const std::array<u64,3>& m1831) {
                u64 v_c62 = m1831[2];
                if (!slog::exists_probe<3,1>(appindex1756, std::array<u64,3>{v_c62, 0, 0})) return;
                slog::join_probe<2,1>(refindex1757, std::array<u64,2>{v_c53, 0}, [&](const std::array<u64,2>& m1832) {
                  u64 v_c56 = m1832[1];
                  slog::join_probe<3,2>(lambdaindex1758, std::array<u64,3>{v_c53, v_c56, 0}, [&](const std::array<u64,3>& m1833) {
                    u64 v_c57 = m1833[2];
                    slog::join_probe<3,2>(appindex1759, std::array<u64,3>{v_c55, v_c57, 0}, [&](const std::array<u64,3>& m1834) {
                      u64 v_c58 = m1834[2];
                      slog::join_probe<3,2>(lambdaindex1760, std::array<u64,3>{v_c50, v_c58, 0}, [&](const std::array<u64,3>& m1835) {
                        u64 v_c59 = m1835[2];
                        slog::join_probe<2,1>(refindex1761, std::array<u64,2>{v_c52, 0}, [&](const std::array<u64,2>& m1836) {
                          u64 v_c63 = m1836[1];
                          slog::join_probe<3,2>(lambdaindex1762, std::array<u64,3>{v_c52, v_c63, 0}, [&](const std::array<u64,3>& m1837) {
                            u64 v_c64 = m1837[2];
                            slog::join_probe<3,2>(lambdaindex1763, std::array<u64,3>{v_c51, v_c64, 0}, [&](const std::array<u64,3>& m1838) {
                              u64 v_c65 = m1838[2];
                              slog::join_probe<3,2>(appindex1764, std::array<u64,3>{v_c54, v_c65, 0}, [&](const std::array<u64,3>& m1839) {
                                u64 v_c66 = m1839[2];
                                slog::join_probe<3,2>(lambdaindex1765, std::array<u64,3>{v_c49, v_c66, 0}, [&](const std::array<u64,3>& m1840) {
                                  u64 v_c101 = m1840[2];
                                  slog::join_probe<3,2>(appindex1766, std::array<u64,3>{v_c101, v_c62, 0}, [&](const std::array<u64,3>& m1841) {
                                    u64 v_c215 = m1841[2];
                                    slog::join_probe<3,2>(lambdaindex1767, std::array<u64,3>{v_c48, v_c215, 0}, [&](const std::array<u64,3>& m1842) {
                                      u64 v_c216 = m1842[2];
                                      ++_fires;
                                      slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c216, v_c59}, std::array<u16,3>{1, 2, 0});
                                    });
                                  });
                                });
                              });
                            });
                          });
                        });
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
      s->addTaskSeeded(phase_read, new ReadTask1768(db,b));
}

