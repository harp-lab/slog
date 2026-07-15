
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const0aa6f87434af0222b916e97a;
extern u64 v_const0f8748be649f8ee4066bb1d7;
extern u64 v_const15bb62b8293a526ca6f0e4eb;
extern u64 v_const227d34ceeba7a29aada993d4;
extern u64 v_const229c0b7aa8a7eb4055f5a3d0;
extern u64 v_const361d5df359e0d7681220d09d;
extern u64 v_const3a82152bd1402931076fe2d7;
extern u64 v_const4a8acfc71441e0695ffcf5b3;
extern u64 v_const4d5ce1398140fbe27561181f;
extern u64 v_const4e3b5454cf93e32fad90650d;
extern u64 v_const4f84f41d89b6b717419b4eaa;
extern u64 v_const50a95ec20b9767e468d04917;
extern u64 v_const576506f61f53440f1edd95d2;
extern u64 v_const5950e3cb761734f52a881545;
extern u64 v_const59ba3256d223f0d0a00d0633;
extern u64 v_const66518c0c1b3a5a0b09ae2ef1;
extern u64 v_const6bc0ba365ada70df115e1785;
extern u64 v_const6cf13cc59dcbe759113f68a4;
extern u64 v_const77ceb5c0e9f84ebd84104a97;
extern u64 v_const7c7d2cfc66f4d976987d2d20;
extern u64 v_const7cd75b35aa30c3ddf04f9d57;
extern u64 v_const81cb39a72a584ab4f703b7f7;
extern u64 v_const85f09fa1913b9daf65957cf7;
extern u64 v_const8ca682693a0738a0641c6956;
extern u64 v_const969c6e56242ce8d0a4346602;
extern u64 v_const970c20ea81b833e5b5a7accf;
extern u64 v_const990b444cbd47632035b2fa1a;
extern u64 v_const9a67f28c6b77e842f439a84a;
extern u64 v_consta8180db1c2f300980314f910;
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
extern u64 v_constf0a25c0401304c51b5ee9c5e;
extern u64 v_constf700a82e218a86de572e1f7f;
extern u64 v_constfc9ee54e0ee8c6d1e715716c;


void slog_rules_cbec5ced43d8b89e5(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre (let __tconst9zoW125 const7c7d2cfc66f4d976987d2d20) (let __tconst4V4L122 const6bc0ba365ada70df115e1785) (let __tconst82U8119 consta8180db1c2f300980314f910) (let __tconst3wDH116 constd5f017533ea574d5f9b3400c) (let __tconst3ktF111 const990b444cbd47632035b2fa1a) (let __tconst4BKz104 const0f8748be649f8ee4066bb1d7) (let __tconst5nWJ102 const4f84f41d89b6b717419b4eaa) (let __tconst4Zcr91 const9a67f28c6b77e842f439a84a) (let __tconst0vRf84 conste58dec6bca6f63ef79c3b755)) (seeded) (body (join ref (1 0) 1 __tconst0vRf84 __t2duR83) (exists ref (1 0) 1 __tconst9zoW125) (exists ref (1 0) 1 __tconst4BKz104) (exists ref (1 0) 1 __tconst4V4L122) (exists ref (1 0) 1 __tconst5nWJ102) (exists ref (1 0) 1 __tconst3ktF111) (exists ref (1 0) 1 __tconst3wDH116) (join ref (1 0) 1 __tconst4Zcr91 __t0C9F87) (join ref (1 0) 1 __tconst9zoW125 __t3Q2G89) (join ref (1 0) 1 __tconst4BKz104 __t8C0a94) (join ref (1 0) 1 __tconst4V4L122 __t7aew98) (join ref (1 0) 1 __tconst5nWJ102 __t5MaG101) (join ref (1 0) 1 __tconst3ktF111 __t7ohz110) (join ref (1 0) 1 __tconst3wDH116 __t3wir114)) (head (mkstruct lambda (1 2 0) __t8GWA112 __tconst3ktF111 __t7ohz110) (mkstruct lambda (1 2 0) __t35jA103 __tconst5nWJ102 __t5MaG101) (mkstruct lambda (1 2 0) __t4fDK96 __tconst4BKz104 __t8C0a94) (mkstruct app (1 2 0) __t2Eqd90 __t3Q2G89 __t0C9F87) (mkstruct lambda (1 2 0) __t87vL85 __tconst0vRf84 __t2duR83)) mcfa-counting.slog:241 #f)
  class ReadTask14 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[5];
    slog::Index** head_index[5];
  
  
  
  
  
  
    slog::Index** refindex0;  slog::Index** refindex1;  slog::Index** refindex2;  slog::Index** refindex3;  slog::Index** refindex4;  slog::Index** refindex5;  slog::Index** refindex6;  slog::Index** refindex7;  slog::Index** refindex8;  slog::Index** refindex9;  slog::Index** refindex10;  slog::Index** refindex11;  slog::Index** refindex12;  slog::Index** refindex13;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      std::vector<u16> ord15({1, 2, 0});
      slog::Relation* readrel16 = db->getRelation("lambda");
      head_index[0] = readrel16->getIndex(ord15, false);
      head_rel[1] = db->getRelation("lambda");
      std::vector<u16> ord17({1, 2, 0});
      slog::Relation* readrel18 = db->getRelation("lambda");
      head_index[1] = readrel18->getIndex(ord17, false);
      head_rel[2] = db->getRelation("lambda");
      std::vector<u16> ord19({1, 2, 0});
      slog::Relation* readrel20 = db->getRelation("lambda");
      head_index[2] = readrel20->getIndex(ord19, false);
      head_rel[3] = db->getRelation("app");
      std::vector<u16> ord21({1, 2, 0});
      slog::Relation* readrel22 = db->getRelation("app");
      head_index[3] = readrel22->getIndex(ord21, false);
      head_rel[4] = db->getRelation("lambda");
      std::vector<u16> ord23({1, 2, 0});
      slog::Relation* readrel24 = db->getRelation("lambda");
      head_index[4] = readrel24->getIndex(ord23, false);
      std::vector<u16> ord25({1, 0});
      slog::Relation* readrel26 = db->getRelation("ref");
      refindex0 = readrel26->getIndex(ord25, false);
      std::vector<u16> ord27({1, 0});
      slog::Relation* readrel28 = db->getRelation("ref");
      refindex1 = readrel28->getIndex(ord27, false);
      std::vector<u16> ord29({1, 0});
      slog::Relation* readrel30 = db->getRelation("ref");
      refindex2 = readrel30->getIndex(ord29, false);
      std::vector<u16> ord31({1, 0});
      slog::Relation* readrel32 = db->getRelation("ref");
      refindex3 = readrel32->getIndex(ord31, false);
      std::vector<u16> ord33({1, 0});
      slog::Relation* readrel34 = db->getRelation("ref");
      refindex4 = readrel34->getIndex(ord33, false);
      std::vector<u16> ord35({1, 0});
      slog::Relation* readrel36 = db->getRelation("ref");
      refindex5 = readrel36->getIndex(ord35, false);
      std::vector<u16> ord37({1, 0});
      slog::Relation* readrel38 = db->getRelation("ref");
      refindex6 = readrel38->getIndex(ord37, false);
      std::vector<u16> ord39({1, 0});
      slog::Relation* readrel40 = db->getRelation("ref");
      refindex7 = readrel40->getIndex(ord39, false);
      std::vector<u16> ord41({1, 0});
      slog::Relation* readrel42 = db->getRelation("ref");
      refindex8 = readrel42->getIndex(ord41, false);
      std::vector<u16> ord43({1, 0});
      slog::Relation* readrel44 = db->getRelation("ref");
      refindex9 = readrel44->getIndex(ord43, false);
      std::vector<u16> ord45({1, 0});
      slog::Relation* readrel46 = db->getRelation("ref");
      refindex10 = readrel46->getIndex(ord45, false);
      std::vector<u16> ord47({1, 0});
      slog::Relation* readrel48 = db->getRelation("ref");
      refindex11 = readrel48->getIndex(ord47, false);
      std::vector<u16> ord49({1, 0});
      slog::Relation* readrel50 = db->getRelation("ref");
      refindex12 = readrel50->getIndex(ord49, false);
      std::vector<u16> ord51({1, 0});
      slog::Relation* readrel52 = db->getRelation("ref");
      refindex13 = readrel52->getIndex(ord51, false);
  
    }
    ReadTask14(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const7c7d2cfc66f4d976987d2d20;
      u64 v_c1 = v_const6bc0ba365ada70df115e1785;
      u64 v_c2 = v_consta8180db1c2f300980314f910;
      u64 v_c3 = v_constd5f017533ea574d5f9b3400c;
      u64 v_c4 = v_const990b444cbd47632035b2fa1a;
      u64 v_c5 = v_const0f8748be649f8ee4066bb1d7;
      u64 v_c6 = v_const4f84f41d89b6b717419b4eaa;
      u64 v_c7 = v_const9a67f28c6b77e842f439a84a;
      u64 v_c8 = v_conste58dec6bca6f63ef79c3b755;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[5];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
      newbatch[4] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex0, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m53) {
        u64 v_c9 = m53[1];
        if (!slog::exists_probe<2,1>(refindex1, std::array<u64,2>{v_c0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex2, std::array<u64,2>{v_c5, 0})) return;
        if (!slog::exists_probe<2,1>(refindex3, std::array<u64,2>{v_c1, 0})) return;
        if (!slog::exists_probe<2,1>(refindex4, std::array<u64,2>{v_c6, 0})) return;
        if (!slog::exists_probe<2,1>(refindex5, std::array<u64,2>{v_c4, 0})) return;
        if (!slog::exists_probe<2,1>(refindex6, std::array<u64,2>{v_c3, 0})) return;
        slog::join_probe<2,1>(refindex7, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m54) {
          u64 v_c10 = m54[1];
          slog::join_probe<2,1>(refindex8, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m55) {
            u64 v_c11 = m55[1];
            slog::join_probe<2,1>(refindex9, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m56) {
              u64 v_c12 = m56[1];
              slog::join_probe<2,1>(refindex10, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m57) {
                u64 v_c13 = m57[1];
                slog::join_probe<2,1>(refindex11, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m58) {
                  u64 v_c14 = m58[1];
                  slog::join_probe<2,1>(refindex12, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m59) {
                    u64 v_c15 = m59[1];
                    slog::join_probe<2,1>(refindex13, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m60) {
                      u64 v_c16 = m60[1];
                      ++_fires;
                      slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c4, v_c15}, std::array<u16,3>{1, 2, 0});
                      slog::emit_struct_checked<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c6, v_c14}, std::array<u16,3>{1, 2, 0});
                      slog::emit_struct_checked<3>(head_rel[2], head_index[2], newbatch[2], std::array<u64,2>{v_c5, v_c12}, std::array<u16,3>{1, 2, 0});
                      slog::emit_struct_checked<3>(head_rel[3], head_index[3], newbatch[3], std::array<u64,2>{v_c11, v_c10}, std::array<u16,3>{1, 2, 0});
                      slog::emit_struct_checked<3>(head_rel[4], head_index[4], newbatch[4], std::array<u64,2>{v_c8, v_c9}, std::array<u16,3>{1, 2, 0});
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
  
      if (_fires) db->bumpFires("mcfa-counting.slog:241", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask14(db,b));
  // (crule (pre (let __tconst7JVW192 const6cf13cc59dcbe759113f68a4) (let __tconst7B9N190 constcaa3ee5a2828a31924f6b39d) (let __tconst5wC2180 const970c20ea81b833e5b5a7accf) (let __tconst2ady176 constc40f204dda7ba4054abb9e74)) (probe lambda (1 2 0) 1 __tconst7B9N190 __t9pbS189 __t6W4v191) (body (exists ref (1 0) 1 __tconst7B9N190) (exists ref (1 0) 1 __tconst2ady176) (exists lambda (1 2 0) 1 __tconst2ady176) (exists ref (1 0) 1 __tconst5wC2180) (exists lambda (1 2 0) 1 __tconst5wC2180) (join ref (1 0) 1 __tconst7JVW192 __t6fOY185) (exists app (1 2 0) 1 __t6fOY185) (join app (0 1 2) 2 __t9pbS189 __t6fOY185 __t2CTd186) (join app (0 1 2) 2 __t2CTd186 __t6fOY185 __t8oRJ183) (join ref (0 1) 2 __t8oRJ183 __tconst7B9N190) (join ref (1 0) 1 __tconst2ady176 __t3ZY4175) (join lambda (1 2 0) 2 __tconst2ady176 __t3ZY4175 __t1Ls4177) (join ref (1 0) 1 __tconst5wC2180 __t52sB179) (join lambda (1 2 0) 2 __tconst5wC2180 __t52sB179 __t6CST181)) (head (mkstruct lambda (1 2 0) __t6Vw9193 __tconst7JVW192 __t6W4v191)) mcfa-counting.slog:301 #f)
  class ReadTask75 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** refindex61;  slog::Index** refindex62;  slog::Index** lambdaindex63;  slog::Index** refindex64;  slog::Index** lambdaindex65;  slog::Index** refindex66;  slog::Index** appindex67;  slog::Index** appindex68;  slog::Index** appindex69;  slog::Index** refindex70;  slog::Index** refindex71;  slog::Index** lambdaindex72;  slog::Index** refindex73;  slog::Index** lambdaindex74;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      std::vector<u16> ord76({1, 2, 0});
      slog::Relation* readrel77 = db->getRelation("lambda");
      driver_index = readrel77->getIndex(ord76, true);
      std::vector<u16> ord78({1, 0});
      slog::Relation* readrel79 = db->getRelation("ref");
      refindex61 = readrel79->getIndex(ord78, false);
      std::vector<u16> ord80({1, 0});
      slog::Relation* readrel81 = db->getRelation("ref");
      refindex62 = readrel81->getIndex(ord80, false);
      std::vector<u16> ord82({1, 2, 0});
      slog::Relation* readrel83 = db->getRelation("lambda");
      lambdaindex63 = readrel83->getIndex(ord82, false);
      std::vector<u16> ord84({1, 0});
      slog::Relation* readrel85 = db->getRelation("ref");
      refindex64 = readrel85->getIndex(ord84, false);
      std::vector<u16> ord86({1, 2, 0});
      slog::Relation* readrel87 = db->getRelation("lambda");
      lambdaindex65 = readrel87->getIndex(ord86, false);
      std::vector<u16> ord88({1, 0});
      slog::Relation* readrel89 = db->getRelation("ref");
      refindex66 = readrel89->getIndex(ord88, false);
      std::vector<u16> ord90({1, 2, 0});
      slog::Relation* readrel91 = db->getRelation("app");
      appindex67 = readrel91->getIndex(ord90, false);
      std::vector<u16> ord92({0, 1, 2});
      slog::Relation* readrel93 = db->getRelation("app");
      appindex68 = readrel93->getIndex(ord92, false);
      std::vector<u16> ord94({0, 1, 2});
      slog::Relation* readrel95 = db->getRelation("app");
      appindex69 = readrel95->getIndex(ord94, false);
      std::vector<u16> ord96({0, 1});
      slog::Relation* readrel97 = db->getRelation("ref");
      refindex70 = readrel97->getIndex(ord96, false);
      std::vector<u16> ord98({1, 0});
      slog::Relation* readrel99 = db->getRelation("ref");
      refindex71 = readrel99->getIndex(ord98, false);
      std::vector<u16> ord100({1, 2, 0});
      slog::Relation* readrel101 = db->getRelation("lambda");
      lambdaindex72 = readrel101->getIndex(ord100, false);
      std::vector<u16> ord102({1, 0});
      slog::Relation* readrel103 = db->getRelation("ref");
      refindex73 = readrel103->getIndex(ord102, false);
      std::vector<u16> ord104({1, 2, 0});
      slog::Relation* readrel105 = db->getRelation("lambda");
      lambdaindex74 = readrel105->getIndex(ord104, false);
  
    }
    ReadTask75(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c17 = v_const6cf13cc59dcbe759113f68a4;
      u64 v_c18 = v_constcaa3ee5a2828a31924f6b39d;
      u64 v_c19 = v_const970c20ea81b833e5b5a7accf;
      u64 v_c20 = v_constc40f204dda7ba4054abb9e74;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c18, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m106) {
        u64 v_c21 = m106[1];
        u64 v_c22 = m106[2];
        if (buckethash(v_c21) != bucket) return;
        if (!slog::exists_probe<2,1>(refindex61, std::array<u64,2>{v_c18, 0})) return;
        if (!slog::exists_probe<2,1>(refindex62, std::array<u64,2>{v_c20, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex63, std::array<u64,3>{v_c20, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex64, std::array<u64,2>{v_c19, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex65, std::array<u64,3>{v_c19, 0, 0})) return;
        slog::join_probe<2,1>(refindex66, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m107) {
          u64 v_c23 = m107[1];
          if (!slog::exists_probe<3,1>(appindex67, std::array<u64,3>{v_c23, 0, 0})) return;
          slog::join_probe<3,2>(appindex68, std::array<u64,3>{v_c21, v_c23, 0}, [&](const std::array<u64,3>& m108) {
            u64 v_c24 = m108[2];
            slog::join_probe<3,2>(appindex69, std::array<u64,3>{v_c24, v_c23, 0}, [&](const std::array<u64,3>& m109) {
              u64 v_c25 = m109[2];
              slog::join_probe<2,2>(refindex70, std::array<u64,2>{v_c25, v_c18}, [&](const std::array<u64,2>& m110) {
                slog::join_probe<2,1>(refindex71, std::array<u64,2>{v_c20, 0}, [&](const std::array<u64,2>& m111) {
                  u64 v_c26 = m111[1];
                  slog::join_probe<3,2>(lambdaindex72, std::array<u64,3>{v_c20, v_c26, 0}, [&](const std::array<u64,3>& m112) {
                    u64 v_c27 = m112[2];
                    slog::join_probe<2,1>(refindex73, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m113) {
                      u64 v_c28 = m113[1];
                      slog::join_probe<3,2>(lambdaindex74, std::array<u64,3>{v_c19, v_c28, 0}, [&](const std::array<u64,3>& m114) {
                        u64 v_c29 = m114[2];
                        ++_fires;
                        slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c17, v_c22}, std::array<u16,3>{1, 2, 0});
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
  
      if (_fires) db->bumpFires("mcfa-counting.slog:301", "delta:lambda", _fires);
  
      if (!_done)
      {
        ReadTask75* _cont = new ReadTask75(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask75(db,b), false);
  // (crule (pre (let __tconst8xRt151 const3a82152bd1402931076fe2d7) (let __tconst0zC2144 const4e3b5454cf93e32fad90650d) (let __tconst3Taj142 constdc1bb6655fb38bdb032e3754) (let __tconst8eg8132 const361d5df359e0d7681220d09d)) (probe lambda (1 2 0) 1 __tconst8eg8132 __t19JM131 __t4DXA133) (body (join ref (0 1) 2 __t19JM131 __tconst8eg8132) (exists ref (1 0) 1 __tconst0zC2144) (exists ref (1 0) 1 __tconst8xRt151) (join ref (1 0) 1 __tconst3Taj142 __t93Xi135) (join ref (1 0) 1 __tconst0zC2144 __t7VSc137) (exists app (1 2 0) 1 __t7VSc137) (join ref (1 0) 1 __tconst8xRt151 __t1g2P147) (exists app (1 2 0) 1 __t1g2P147) (join app (1 2 0) 1 __t7VSc137 dup5jEp391 __t8dYW140) (eq __t7VSc137 dup5jEp391) (join app (1 2 0) 1 __t1g2P147 dup7WmO392 __t9UZN150) (eq __t1g2P147 dup7WmO392)) (head (mkstruct lambda (1 2 0) __t2nYy152 __tconst8xRt151 __t9UZN150) (mkstruct app (1 2 0) __t25NQ141 __t8dYW140 __t93Xi135)) mcfa-counting.slog:224 #f)
  class ReadTask125 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** refindex115;  slog::Index** refindex116;  slog::Index** refindex117;  slog::Index** refindex118;  slog::Index** refindex119;  slog::Index** appindex120;  slog::Index** refindex121;  slog::Index** appindex122;  slog::Index** appindex123;  slog::Index** appindex124;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      head_rel[1] = db->getRelation("app");
      std::vector<u16> ord126({1, 2, 0});
      slog::Relation* readrel127 = db->getRelation("lambda");
      driver_index = readrel127->getIndex(ord126, true);
      std::vector<u16> ord128({0, 1});
      slog::Relation* readrel129 = db->getRelation("ref");
      refindex115 = readrel129->getIndex(ord128, false);
      std::vector<u16> ord130({1, 0});
      slog::Relation* readrel131 = db->getRelation("ref");
      refindex116 = readrel131->getIndex(ord130, false);
      std::vector<u16> ord132({1, 0});
      slog::Relation* readrel133 = db->getRelation("ref");
      refindex117 = readrel133->getIndex(ord132, false);
      std::vector<u16> ord134({1, 0});
      slog::Relation* readrel135 = db->getRelation("ref");
      refindex118 = readrel135->getIndex(ord134, false);
      std::vector<u16> ord136({1, 0});
      slog::Relation* readrel137 = db->getRelation("ref");
      refindex119 = readrel137->getIndex(ord136, false);
      std::vector<u16> ord138({1, 2, 0});
      slog::Relation* readrel139 = db->getRelation("app");
      appindex120 = readrel139->getIndex(ord138, false);
      std::vector<u16> ord140({1, 0});
      slog::Relation* readrel141 = db->getRelation("ref");
      refindex121 = readrel141->getIndex(ord140, false);
      std::vector<u16> ord142({1, 2, 0});
      slog::Relation* readrel143 = db->getRelation("app");
      appindex122 = readrel143->getIndex(ord142, false);
      std::vector<u16> ord144({1, 2, 0});
      slog::Relation* readrel145 = db->getRelation("app");
      appindex123 = readrel145->getIndex(ord144, false);
      std::vector<u16> ord146({1, 2, 0});
      slog::Relation* readrel147 = db->getRelation("app");
      appindex124 = readrel147->getIndex(ord146, false);
  
    }
    ReadTask125(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c30 = v_const3a82152bd1402931076fe2d7;
      u64 v_c31 = v_const4e3b5454cf93e32fad90650d;
      u64 v_c32 = v_constdc1bb6655fb38bdb032e3754;
      u64 v_c33 = v_const361d5df359e0d7681220d09d;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c33, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m148) {
        u64 v_c34 = m148[1];
        u64 v_c35 = m148[2];
        if (buckethash(v_c34) != bucket) return;
        slog::join_probe<2,2>(refindex115, std::array<u64,2>{v_c34, v_c33}, [&](const std::array<u64,2>& m149) {
          if (!slog::exists_probe<2,1>(refindex116, std::array<u64,2>{v_c31, 0})) return;
          if (!slog::exists_probe<2,1>(refindex117, std::array<u64,2>{v_c30, 0})) return;
          slog::join_probe<2,1>(refindex118, std::array<u64,2>{v_c32, 0}, [&](const std::array<u64,2>& m150) {
            u64 v_c36 = m150[1];
            slog::join_probe<2,1>(refindex119, std::array<u64,2>{v_c31, 0}, [&](const std::array<u64,2>& m151) {
              u64 v_c37 = m151[1];
              if (!slog::exists_probe<3,1>(appindex120, std::array<u64,3>{v_c37, 0, 0})) return;
              slog::join_probe<2,1>(refindex121, std::array<u64,2>{v_c30, 0}, [&](const std::array<u64,2>& m152) {
                u64 v_c38 = m152[1];
                if (!slog::exists_probe<3,1>(appindex122, std::array<u64,3>{v_c38, 0, 0})) return;
                slog::join_probe<3,1>(appindex123, std::array<u64,3>{v_c37, 0, 0}, [&](const std::array<u64,3>& m153) {
                  u64 v_c39 = m153[1]; u64 v_c40 = m153[2];
                  if (v_c37 != v_c39) return;
                  slog::join_probe<3,1>(appindex124, std::array<u64,3>{v_c38, 0, 0}, [&](const std::array<u64,3>& m154) {
                    u64 v_c41 = m154[1]; u64 v_c42 = m154[2];
                    if (v_c38 != v_c41) return;
                    ++_fires;
                    slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c30, v_c42}, std::array<u16,3>{1, 2, 0});
                    slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c40, v_c36}, std::array<u16,3>{1, 2, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:224", "delta:lambda", _fires);
  
      if (!_done)
      {
        ReadTask125* _cont = new ReadTask125(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask125(db,b), false);
  // (crule (pre) (scan eval __t4j5Q160 ea c) (body (exists eval (2 0 1) 1 c) (exists eval_ans (0 1) 1 __t4j5Q160) (join $sup27994x83x0x0x0 (1 2 0 3) 2 c ea __d0 ef) (join eval (1 2 0) 2 ef c __t8nKY157) (join eval_ans (0 1) 1 __t8nKY157 __t3EGT159) (join eval_ans (0 1) 1 __t4j5Q160 va) (join clo (0 2 1) 1 __t3EGT159 cb __t1L8v158) (join lambda (0 1 2) 1 __t1L8v158 x eb)) (head (emit $sup27994x83x0x0x1 (1 4 0 2 3 5 6 7 8 9) __t8nKY157 cb __d0 __t4j5Q160 c ea eb ef va x)) mcfa-counting.slog:84 #f)
  class ReadTask163 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex155;  slog::Index** eval_ansindex156;  slog::Index** $sup27994x83x0x0x0index157;  slog::Index** evalindex158;  slog::Index** eval_ansindex159;  slog::Index** eval_ansindex160;  slog::Index** cloindex161;  slog::Index** lambdaindex162;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup27994x83x0x0x1");
      std::vector<u16> ord164({1, 4, 0, 2, 3, 5, 6, 7, 8, 9});
      slog::Relation* readrel165 = db->getRelation("$sup27994x83x0x0x1");
      head_index[0] = readrel165->getIndex(ord164, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord166({2, 0, 1});
      slog::Relation* readrel167 = db->getRelation("eval");
      evalindex155 = readrel167->getIndex(ord166, false);
      std::vector<u16> ord168({0, 1});
      slog::Relation* readrel169 = db->getRelation("eval_ans");
      eval_ansindex156 = readrel169->getIndex(ord168, false);
      std::vector<u16> ord170({1, 2, 0, 3});
      slog::Relation* readrel171 = db->getRelation("$sup27994x83x0x0x0");
      $sup27994x83x0x0x0index157 = readrel171->getIndex(ord170, false);
      std::vector<u16> ord172({1, 2, 0});
      slog::Relation* readrel173 = db->getRelation("eval");
      evalindex158 = readrel173->getIndex(ord172, false);
      std::vector<u16> ord174({0, 1});
      slog::Relation* readrel175 = db->getRelation("eval_ans");
      eval_ansindex159 = readrel175->getIndex(ord174, false);
      std::vector<u16> ord176({0, 1});
      slog::Relation* readrel177 = db->getRelation("eval_ans");
      eval_ansindex160 = readrel177->getIndex(ord176, false);
      std::vector<u16> ord178({0, 2, 1});
      slog::Relation* readrel179 = db->getRelation("clo");
      cloindex161 = readrel179->getIndex(ord178, false);
      std::vector<u16> ord180({0, 1, 2});
      slog::Relation* readrel181 = db->getRelation("lambda");
      lambdaindex162 = readrel181->getIndex(ord180, false);
  
    }
    ReadTask163(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c44 = _t[1];
        u64 v_c45 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex155, std::array<u64,3>{v_c45, 0, 0})) return;
        if (!slog::exists_probe<2,1>(eval_ansindex156, std::array<u64,2>{v_c43, 0})) return;
        slog::join_probe<4,2>($sup27994x83x0x0x0index157, std::array<u64,4>{v_c45, v_c44, 0, 0}, [&](const std::array<u64,4>& m182) {
          u64 v_c46 = m182[2]; u64 v_c47 = m182[3];
          slog::join_probe<3,2>(evalindex158, std::array<u64,3>{v_c47, v_c45, 0}, [&](const std::array<u64,3>& m183) {
            u64 v_c48 = m183[2];
            slog::join_probe<2,1>(eval_ansindex159, std::array<u64,2>{v_c48, 0}, [&](const std::array<u64,2>& m184) {
              u64 v_c49 = m184[1];
              slog::join_probe<2,1>(eval_ansindex160, std::array<u64,2>{v_c43, 0}, [&](const std::array<u64,2>& m185) {
                u64 v_c50 = m185[1];
                slog::join_probe<3,1>(cloindex161, std::array<u64,3>{v_c49, 0, 0}, [&](const std::array<u64,3>& m186) {
                  u64 v_c51 = m186[1]; u64 v_c52 = m186[2];
                  slog::join_probe<3,1>(lambdaindex162, std::array<u64,3>{v_c52, 0, 0}, [&](const std::array<u64,3>& m187) {
                    u64 v_c53 = m187[1]; u64 v_c54 = m187[2];
                    ++_fires;
                    slog::emit<10>(head_rel[0], head_index[0], newbatch[0], std::array<u64,10>{v_c48, v_c51, v_c46, v_c43, v_c45, v_c44, v_c54, v_c47, v_c50, v_c53}, std::array<u16,10>{1, 4, 0, 2, 3, 5, 6, 7, 8, 9});
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
        ReadTask163* _cont = new ReadTask163(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask163(db,b), false);
  // (crule (pre (let __tconst7JVW192 const6cf13cc59dcbe759113f68a4) (let __tconst7B9N190 constcaa3ee5a2828a31924f6b39d) (let __tconst5wC2180 const970c20ea81b833e5b5a7accf) (let __tconst2ady176 constc40f204dda7ba4054abb9e74)) (seeded) (body (join ref (1 0) 1 __tconst2ady176 __t3ZY4175) (exists ref (1 0) 1 __tconst5wC2180) (exists lambda (1 2 0) 1 __tconst5wC2180) (exists ref (1 0) 1 __tconst7JVW192) (exists ref (1 0) 1 __tconst7B9N190) (exists lambda (1 2 0) 1 __tconst7B9N190) (exists lambda (1 2 0) 1 __tconst7JVW192) (join lambda (1 2 0) 2 __tconst2ady176 __t3ZY4175 __t1Ls4177) (join ref (1 0) 1 __tconst5wC2180 __t52sB179) (join lambda (1 2 0) 2 __tconst5wC2180 __t52sB179 __t6CST181) (join ref (1 0) 1 __tconst7JVW192 __t6fOY185) (exists app (1 2 0) 1 __t6fOY185) (join ref (1 0) 1 __tconst7B9N190 __t8oRJ183) (join app (1 2 0) 2 __t6fOY185 __t8oRJ183 __t2CTd186) (join app (1 2 0) 2 __t6fOY185 __t2CTd186 __t9pbS189) (join lambda (1 2 0) 2 __tconst7B9N190 __t9pbS189 __t6W4v191) (join lambda (1 2 0) 2 __tconst7JVW192 __t6W4v191 __t6Vw9193)) (head (mkstruct app (1 2 0) __t5jf3194 __t6Vw9193 __t6CST181)) mcfa-counting.slog:301 #f)
  class ReadTask205 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex188;  slog::Index** refindex189;  slog::Index** lambdaindex190;  slog::Index** refindex191;  slog::Index** refindex192;  slog::Index** lambdaindex193;  slog::Index** lambdaindex194;  slog::Index** lambdaindex195;  slog::Index** refindex196;  slog::Index** lambdaindex197;  slog::Index** refindex198;  slog::Index** appindex199;  slog::Index** refindex200;  slog::Index** appindex201;  slog::Index** appindex202;  slog::Index** lambdaindex203;  slog::Index** lambdaindex204;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord206({1, 2, 0});
      slog::Relation* readrel207 = db->getRelation("app");
      head_index[0] = readrel207->getIndex(ord206, false);
      std::vector<u16> ord208({1, 0});
      slog::Relation* readrel209 = db->getRelation("ref");
      refindex188 = readrel209->getIndex(ord208, false);
      std::vector<u16> ord210({1, 0});
      slog::Relation* readrel211 = db->getRelation("ref");
      refindex189 = readrel211->getIndex(ord210, false);
      std::vector<u16> ord212({1, 2, 0});
      slog::Relation* readrel213 = db->getRelation("lambda");
      lambdaindex190 = readrel213->getIndex(ord212, false);
      std::vector<u16> ord214({1, 0});
      slog::Relation* readrel215 = db->getRelation("ref");
      refindex191 = readrel215->getIndex(ord214, false);
      std::vector<u16> ord216({1, 0});
      slog::Relation* readrel217 = db->getRelation("ref");
      refindex192 = readrel217->getIndex(ord216, false);
      std::vector<u16> ord218({1, 2, 0});
      slog::Relation* readrel219 = db->getRelation("lambda");
      lambdaindex193 = readrel219->getIndex(ord218, false);
      std::vector<u16> ord220({1, 2, 0});
      slog::Relation* readrel221 = db->getRelation("lambda");
      lambdaindex194 = readrel221->getIndex(ord220, false);
      std::vector<u16> ord222({1, 2, 0});
      slog::Relation* readrel223 = db->getRelation("lambda");
      lambdaindex195 = readrel223->getIndex(ord222, false);
      std::vector<u16> ord224({1, 0});
      slog::Relation* readrel225 = db->getRelation("ref");
      refindex196 = readrel225->getIndex(ord224, false);
      std::vector<u16> ord226({1, 2, 0});
      slog::Relation* readrel227 = db->getRelation("lambda");
      lambdaindex197 = readrel227->getIndex(ord226, false);
      std::vector<u16> ord228({1, 0});
      slog::Relation* readrel229 = db->getRelation("ref");
      refindex198 = readrel229->getIndex(ord228, false);
      std::vector<u16> ord230({1, 2, 0});
      slog::Relation* readrel231 = db->getRelation("app");
      appindex199 = readrel231->getIndex(ord230, false);
      std::vector<u16> ord232({1, 0});
      slog::Relation* readrel233 = db->getRelation("ref");
      refindex200 = readrel233->getIndex(ord232, false);
      std::vector<u16> ord234({1, 2, 0});
      slog::Relation* readrel235 = db->getRelation("app");
      appindex201 = readrel235->getIndex(ord234, false);
      std::vector<u16> ord236({1, 2, 0});
      slog::Relation* readrel237 = db->getRelation("app");
      appindex202 = readrel237->getIndex(ord236, false);
      std::vector<u16> ord238({1, 2, 0});
      slog::Relation* readrel239 = db->getRelation("lambda");
      lambdaindex203 = readrel239->getIndex(ord238, false);
      std::vector<u16> ord240({1, 2, 0});
      slog::Relation* readrel241 = db->getRelation("lambda");
      lambdaindex204 = readrel241->getIndex(ord240, false);
  
    }
    ReadTask205(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c17 = v_const6cf13cc59dcbe759113f68a4;
      u64 v_c18 = v_constcaa3ee5a2828a31924f6b39d;
      u64 v_c19 = v_const970c20ea81b833e5b5a7accf;
      u64 v_c20 = v_constc40f204dda7ba4054abb9e74;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex188, std::array<u64,2>{v_c20, 0}, [&](const std::array<u64,2>& m242) {
        u64 v_c26 = m242[1];
        if (!slog::exists_probe<2,1>(refindex189, std::array<u64,2>{v_c19, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex190, std::array<u64,3>{v_c19, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex191, std::array<u64,2>{v_c17, 0})) return;
        if (!slog::exists_probe<2,1>(refindex192, std::array<u64,2>{v_c18, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex193, std::array<u64,3>{v_c18, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex194, std::array<u64,3>{v_c17, 0, 0})) return;
        slog::join_probe<3,2>(lambdaindex195, std::array<u64,3>{v_c20, v_c26, 0}, [&](const std::array<u64,3>& m243) {
          u64 v_c27 = m243[2];
          slog::join_probe<2,1>(refindex196, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m244) {
            u64 v_c28 = m244[1];
            slog::join_probe<3,2>(lambdaindex197, std::array<u64,3>{v_c19, v_c28, 0}, [&](const std::array<u64,3>& m245) {
              u64 v_c29 = m245[2];
              slog::join_probe<2,1>(refindex198, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m246) {
                u64 v_c23 = m246[1];
                if (!slog::exists_probe<3,1>(appindex199, std::array<u64,3>{v_c23, 0, 0})) return;
                slog::join_probe<2,1>(refindex200, std::array<u64,2>{v_c18, 0}, [&](const std::array<u64,2>& m247) {
                  u64 v_c25 = m247[1];
                  slog::join_probe<3,2>(appindex201, std::array<u64,3>{v_c23, v_c25, 0}, [&](const std::array<u64,3>& m248) {
                    u64 v_c24 = m248[2];
                    slog::join_probe<3,2>(appindex202, std::array<u64,3>{v_c23, v_c24, 0}, [&](const std::array<u64,3>& m249) {
                      u64 v_c21 = m249[2];
                      slog::join_probe<3,2>(lambdaindex203, std::array<u64,3>{v_c18, v_c21, 0}, [&](const std::array<u64,3>& m250) {
                        u64 v_c22 = m250[2];
                        slog::join_probe<3,2>(lambdaindex204, std::array<u64,3>{v_c17, v_c22, 0}, [&](const std::array<u64,3>& m251) {
                          u64 v_c55 = m251[2];
                          ++_fires;
                          slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c55, v_c29}, std::array<u16,3>{1, 2, 0});
                        });
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
      s->addTaskSeeded(phase_read, new ReadTask205(db,b));
  // (crule (pre) (scan eval __5DEq344 __t6ooL258 c) (body (exists eval (2 0 1) 1 c) (join-old app (0 1 2) 1 (0 1 2) __t6ooL258 ef ea) (exists eval (1 2 0) 2 ea c) (join-old eval (1 2 0) 2 (1 2 0) ef c __t7ceq259) (exists eval_ans (0 1) 1 __t7ceq259) (join-old eval (1 2 0) 2 (1 2 0) ea c __t2S0s262) (exists eval_ans (0 1) 1 __t2S0s262) (join-old eval_ans (0 1) 1 (0 1) __t7ceq259 __t0zen261) (join-old eval_ans (0 1) 1 (0 1) __t2S0s262 va) (join-old clo (0 2 1) 1 (0 2 1) __t0zen261 cb __t4JNf263) (exists store (1 0 2) 1 cb) (join-old freevar (1 0) 1 (1 0) __t4JNf263 y) (join-old store (0 1 2) 2 (0 1 2) y cb vy) (join-old lambda (0 1 2) 1 (0 1 2) __t4JNf263 x eb)) (head (emit store (0 1 2) y __t6ooL258 vy) (emit bindev (0 1 2) y __t6ooL258 c)) mcfa-counting.slog:102 #f)
  class ReadTask275 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex252;  slog::Index** appindex253;  slog::Index** evalindex254;  slog::Index** evalindex255;  slog::Index** eval_ansindex256;  slog::Index** evalindex257;  slog::Index** eval_ansindex258;  slog::Index** eval_ansindex259;  slog::Index** eval_ansindex260;  slog::Index** cloindex261;  slog::Index** storeindex262;  slog::Index** freevarindex263;  slog::Index** storeindex264;  slog::Index** lambdaindex265;  slog::Index** appdelta266;  slog::Index** evaldelta267;  slog::Index** evaldelta268;  slog::Index** eval_ansdelta269;  slog::Index** eval_ansdelta270;  slog::Index** clodelta271;  slog::Index** freevardelta272;  slog::Index** storedelta273;  slog::Index** lambdadelta274;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("store");
      std::vector<u16> ord276({0, 1, 2});
      slog::Relation* readrel277 = db->getRelation("store");
      head_index[0] = readrel277->getIndex(ord276, false);
      head_rel[1] = db->getRelation("bindev");
      std::vector<u16> ord278({0, 1, 2});
      slog::Relation* readrel279 = db->getRelation("bindev");
      head_index[1] = readrel279->getIndex(ord278, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord280({2, 0, 1});
      slog::Relation* readrel281 = db->getRelation("eval");
      evalindex252 = readrel281->getIndex(ord280, false);
      std::vector<u16> ord282({0, 1, 2});
      slog::Relation* readrel283 = db->getRelation("app");
      appindex253 = readrel283->getIndex(ord282, false);
      std::vector<u16> ord284({0, 1, 2});
      slog::Relation* readrel285 = db->getRelation("app");
      appdelta266 = readrel285->getIndex(ord284, true);
      std::vector<u16> ord286({1, 2, 0});
      slog::Relation* readrel287 = db->getRelation("eval");
      evalindex254 = readrel287->getIndex(ord286, false);
      std::vector<u16> ord288({1, 2, 0});
      slog::Relation* readrel289 = db->getRelation("eval");
      evalindex255 = readrel289->getIndex(ord288, false);
      std::vector<u16> ord290({1, 2, 0});
      slog::Relation* readrel291 = db->getRelation("eval");
      evaldelta267 = readrel291->getIndex(ord290, true);
      std::vector<u16> ord292({0, 1});
      slog::Relation* readrel293 = db->getRelation("eval_ans");
      eval_ansindex256 = readrel293->getIndex(ord292, false);
      std::vector<u16> ord294({1, 2, 0});
      slog::Relation* readrel295 = db->getRelation("eval");
      evalindex257 = readrel295->getIndex(ord294, false);
      std::vector<u16> ord296({1, 2, 0});
      slog::Relation* readrel297 = db->getRelation("eval");
      evaldelta268 = readrel297->getIndex(ord296, true);
      std::vector<u16> ord298({0, 1});
      slog::Relation* readrel299 = db->getRelation("eval_ans");
      eval_ansindex258 = readrel299->getIndex(ord298, false);
      std::vector<u16> ord300({0, 1});
      slog::Relation* readrel301 = db->getRelation("eval_ans");
      eval_ansindex259 = readrel301->getIndex(ord300, false);
      std::vector<u16> ord302({0, 1});
      slog::Relation* readrel303 = db->getRelation("eval_ans");
      eval_ansdelta269 = readrel303->getIndex(ord302, true);
      std::vector<u16> ord304({0, 1});
      slog::Relation* readrel305 = db->getRelation("eval_ans");
      eval_ansindex260 = readrel305->getIndex(ord304, false);
      std::vector<u16> ord306({0, 1});
      slog::Relation* readrel307 = db->getRelation("eval_ans");
      eval_ansdelta270 = readrel307->getIndex(ord306, true);
      std::vector<u16> ord308({0, 2, 1});
      slog::Relation* readrel309 = db->getRelation("clo");
      cloindex261 = readrel309->getIndex(ord308, false);
      std::vector<u16> ord310({0, 2, 1});
      slog::Relation* readrel311 = db->getRelation("clo");
      clodelta271 = readrel311->getIndex(ord310, true);
      std::vector<u16> ord312({1, 0, 2});
      slog::Relation* readrel313 = db->getRelation("store");
      storeindex262 = readrel313->getIndex(ord312, false);
      std::vector<u16> ord314({1, 0});
      slog::Relation* readrel315 = db->getRelation("freevar");
      freevarindex263 = readrel315->getIndex(ord314, false);
      std::vector<u16> ord316({1, 0});
      slog::Relation* readrel317 = db->getRelation("freevar");
      freevardelta272 = readrel317->getIndex(ord316, true);
      std::vector<u16> ord318({0, 1, 2});
      slog::Relation* readrel319 = db->getRelation("store");
      storeindex264 = readrel319->getIndex(ord318, false);
      std::vector<u16> ord320({0, 1, 2});
      slog::Relation* readrel321 = db->getRelation("store");
      storedelta273 = readrel321->getIndex(ord320, true);
      std::vector<u16> ord322({0, 1, 2});
      slog::Relation* readrel323 = db->getRelation("lambda");
      lambdaindex265 = readrel323->getIndex(ord322, false);
      std::vector<u16> ord324({0, 1, 2});
      slog::Relation* readrel325 = db->getRelation("lambda");
      lambdadelta274 = readrel325->getIndex(ord324, true);
  
    }
    ReadTask275(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c56 = _t[0];
        u64 v_c57 = _t[1];
        u64 v_c45 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex252, std::array<u64,3>{v_c45, 0, 0})) return;
        slog::join_probe_old<3,1>(appindex253, appdelta266, std::array<u64,3>{v_c57, 0, 0}, [&](const std::array<u64,3>& m326) {
          u64 v_c47 = m326[1]; u64 v_c44 = m326[2];
          if (!slog::exists_probe<3,2>(evalindex254, std::array<u64,3>{v_c44, v_c45, 0})) return;
          slog::join_probe_old<3,2>(evalindex255, evaldelta267, std::array<u64,3>{v_c47, v_c45, 0}, [&](const std::array<u64,3>& m327) {
            u64 v_c58 = m327[2];
            if (!slog::exists_probe<2,1>(eval_ansindex256, std::array<u64,2>{v_c58, 0})) return;
            slog::join_probe_old<3,2>(evalindex257, evaldelta268, std::array<u64,3>{v_c44, v_c45, 0}, [&](const std::array<u64,3>& m328) {
              u64 v_c59 = m328[2];
              if (!slog::exists_probe<2,1>(eval_ansindex258, std::array<u64,2>{v_c59, 0})) return;
              slog::join_probe_old<2,1>(eval_ansindex259, eval_ansdelta269, std::array<u64,2>{v_c58, 0}, [&](const std::array<u64,2>& m329) {
                u64 v_c60 = m329[1];
                slog::join_probe_old<2,1>(eval_ansindex260, eval_ansdelta270, std::array<u64,2>{v_c59, 0}, [&](const std::array<u64,2>& m330) {
                  u64 v_c50 = m330[1];
                  slog::join_probe_old<3,1>(cloindex261, clodelta271, std::array<u64,3>{v_c60, 0, 0}, [&](const std::array<u64,3>& m331) {
                    u64 v_c51 = m331[1]; u64 v_c61 = m331[2];
                    if (!slog::exists_probe<3,1>(storeindex262, std::array<u64,3>{v_c51, 0, 0})) return;
                    slog::join_probe_old<2,1>(freevarindex263, freevardelta272, std::array<u64,2>{v_c61, 0}, [&](const std::array<u64,2>& m332) {
                      u64 v_c62 = m332[1];
                      slog::join_probe_old<3,2>(storeindex264, storedelta273, std::array<u64,3>{v_c62, v_c51, 0}, [&](const std::array<u64,3>& m333) {
                        u64 v_c63 = m333[2];
                        slog::join_probe_old<3,1>(lambdaindex265, lambdadelta274, std::array<u64,3>{v_c61, 0, 0}, [&](const std::array<u64,3>& m334) {
                          u64 v_c53 = m334[1]; u64 v_c54 = m334[2];
                          ++_fires;
                          slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c62, v_c57, v_c63}, std::array<u16,3>{0, 1, 2});
                          slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c62, v_c57, v_c45}, std::array<u16,3>{0, 1, 2});
                        });
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
        ReadTask275* _cont = new ReadTask275(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask275(db,b), false);
  // (crule (pre) (scan eval __t2S0s262 ea c) (body (exists eval (2 0 1) 1 c) (exists app (2 0 1) 1 ea) (join eval_ans (0 1) 1 __t2S0s262 va) (join eval (2 0 1) 1 c __5DEq344 __t6ooL258) (join app (2 0 1) 2 ea __t6ooL258 ef) (join eval (1 2 0) 2 ef c __t7ceq259) (join eval_ans (0 1) 1 __t7ceq259 __t0zen261) (join clo (0 2 1) 1 __t0zen261 cb __t4JNf263) (exists store (1 0 2) 1 cb) (join freevar (1 0) 1 __t4JNf263 y) (join store (0 1 2) 2 y cb vy) (join-old lambda (0 1 2) 1 (0 1 2) __t4JNf263 x eb)) (head (emit store (0 1 2) y __t6ooL258 vy) (emit bindev (0 1 2) y __t6ooL258 c)) mcfa-counting.slog:102 #f)
  class ReadTask348 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex335;  slog::Index** appindex336;  slog::Index** eval_ansindex337;  slog::Index** evalindex338;  slog::Index** appindex339;  slog::Index** evalindex340;  slog::Index** eval_ansindex341;  slog::Index** cloindex342;  slog::Index** storeindex343;  slog::Index** freevarindex344;  slog::Index** storeindex345;  slog::Index** lambdaindex346;  slog::Index** lambdadelta347;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("store");
      std::vector<u16> ord349({0, 1, 2});
      slog::Relation* readrel350 = db->getRelation("store");
      head_index[0] = readrel350->getIndex(ord349, false);
      head_rel[1] = db->getRelation("bindev");
      std::vector<u16> ord351({0, 1, 2});
      slog::Relation* readrel352 = db->getRelation("bindev");
      head_index[1] = readrel352->getIndex(ord351, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord353({2, 0, 1});
      slog::Relation* readrel354 = db->getRelation("eval");
      evalindex335 = readrel354->getIndex(ord353, false);
      std::vector<u16> ord355({2, 0, 1});
      slog::Relation* readrel356 = db->getRelation("app");
      appindex336 = readrel356->getIndex(ord355, false);
      std::vector<u16> ord357({0, 1});
      slog::Relation* readrel358 = db->getRelation("eval_ans");
      eval_ansindex337 = readrel358->getIndex(ord357, false);
      std::vector<u16> ord359({2, 0, 1});
      slog::Relation* readrel360 = db->getRelation("eval");
      evalindex338 = readrel360->getIndex(ord359, false);
      std::vector<u16> ord361({2, 0, 1});
      slog::Relation* readrel362 = db->getRelation("app");
      appindex339 = readrel362->getIndex(ord361, false);
      std::vector<u16> ord363({1, 2, 0});
      slog::Relation* readrel364 = db->getRelation("eval");
      evalindex340 = readrel364->getIndex(ord363, false);
      std::vector<u16> ord365({0, 1});
      slog::Relation* readrel366 = db->getRelation("eval_ans");
      eval_ansindex341 = readrel366->getIndex(ord365, false);
      std::vector<u16> ord367({0, 2, 1});
      slog::Relation* readrel368 = db->getRelation("clo");
      cloindex342 = readrel368->getIndex(ord367, false);
      std::vector<u16> ord369({1, 0, 2});
      slog::Relation* readrel370 = db->getRelation("store");
      storeindex343 = readrel370->getIndex(ord369, false);
      std::vector<u16> ord371({1, 0});
      slog::Relation* readrel372 = db->getRelation("freevar");
      freevarindex344 = readrel372->getIndex(ord371, false);
      std::vector<u16> ord373({0, 1, 2});
      slog::Relation* readrel374 = db->getRelation("store");
      storeindex345 = readrel374->getIndex(ord373, false);
      std::vector<u16> ord375({0, 1, 2});
      slog::Relation* readrel376 = db->getRelation("lambda");
      lambdaindex346 = readrel376->getIndex(ord375, false);
      std::vector<u16> ord377({0, 1, 2});
      slog::Relation* readrel378 = db->getRelation("lambda");
      lambdadelta347 = readrel378->getIndex(ord377, true);
  
    }
    ReadTask348(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c59 = _t[0];
        u64 v_c44 = _t[1];
        u64 v_c45 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex335, std::array<u64,3>{v_c45, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex336, std::array<u64,3>{v_c44, 0, 0})) return;
        slog::join_probe<2,1>(eval_ansindex337, std::array<u64,2>{v_c59, 0}, [&](const std::array<u64,2>& m379) {
          u64 v_c50 = m379[1];
          slog::join_probe<3,1>(evalindex338, std::array<u64,3>{v_c45, 0, 0}, [&](const std::array<u64,3>& m380) {
            u64 v_c56 = m380[1]; u64 v_c57 = m380[2];
            slog::join_probe<3,2>(appindex339, std::array<u64,3>{v_c44, v_c57, 0}, [&](const std::array<u64,3>& m381) {
              u64 v_c47 = m381[2];
              slog::join_probe<3,2>(evalindex340, std::array<u64,3>{v_c47, v_c45, 0}, [&](const std::array<u64,3>& m382) {
                u64 v_c58 = m382[2];
                slog::join_probe<2,1>(eval_ansindex341, std::array<u64,2>{v_c58, 0}, [&](const std::array<u64,2>& m383) {
                  u64 v_c60 = m383[1];
                  slog::join_probe<3,1>(cloindex342, std::array<u64,3>{v_c60, 0, 0}, [&](const std::array<u64,3>& m384) {
                    u64 v_c51 = m384[1]; u64 v_c61 = m384[2];
                    if (!slog::exists_probe<3,1>(storeindex343, std::array<u64,3>{v_c51, 0, 0})) return;
                    slog::join_probe<2,1>(freevarindex344, std::array<u64,2>{v_c61, 0}, [&](const std::array<u64,2>& m385) {
                      u64 v_c62 = m385[1];
                      slog::join_probe<3,2>(storeindex345, std::array<u64,3>{v_c62, v_c51, 0}, [&](const std::array<u64,3>& m386) {
                        u64 v_c63 = m386[2];
                        slog::join_probe_old<3,1>(lambdaindex346, lambdadelta347, std::array<u64,3>{v_c61, 0, 0}, [&](const std::array<u64,3>& m387) {
                          u64 v_c53 = m387[1]; u64 v_c54 = m387[2];
                          ++_fires;
                          slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c62, v_c57, v_c63}, std::array<u16,3>{0, 1, 2});
                          slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c62, v_c57, v_c45}, std::array<u16,3>{0, 1, 2});
                        });
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
        ReadTask348* _cont = new ReadTask348(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask348(db,b), false);
  // (crule (pre (let __tconst4she277 const50a95ec20b9767e468d04917) (let __tconst0ZLv270 constf0a25c0401304c51b5ee9c5e)) (scan app __t8kx2269 __t9L3S266 dup60Aa437) (body (eq __t9L3S266 dup60Aa437) (join ref (0 1) 2 __t9L3S266 __tconst0ZLv270) (join ref (1 0) 1 __tconst4she277 __t28CO273) (join app (1 2 0) 1 __t28CO273 dup4ILG438 __t6FnS276) (eq __t28CO273 dup4ILG438)) (head (mkstruct lambda (1 2 0) __t6zNR278 __tconst4she277 __t6FnS276) (mkstruct lambda (1 2 0) __t3oIn271 __tconst0ZLv270 __t8kx2269)) mcfa-counting.slog:183 #f)
  class ReadTask391 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex388;  slog::Index** refindex389;  slog::Index** appindex390;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      head_rel[1] = db->getRelation("lambda");
      outer_rel = db->getRelation("app");
      std::vector<u16> ord392({0, 1});
      slog::Relation* readrel393 = db->getRelation("ref");
      refindex388 = readrel393->getIndex(ord392, false);
      std::vector<u16> ord394({1, 0});
      slog::Relation* readrel395 = db->getRelation("ref");
      refindex389 = readrel395->getIndex(ord394, false);
      std::vector<u16> ord396({1, 2, 0});
      slog::Relation* readrel397 = db->getRelation("app");
      appindex390 = readrel397->getIndex(ord396, false);
  
    }
    ReadTask391(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c64 = v_const50a95ec20b9767e468d04917;
      u64 v_c65 = v_constf0a25c0401304c51b5ee9c5e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c66 = _t[0];
        u64 v_c67 = _t[1];
        u64 v_c68 = _t[2];
        if (v_c67 != v_c68) return;
        slog::join_probe<2,2>(refindex388, std::array<u64,2>{v_c67, v_c65}, [&](const std::array<u64,2>& m398) {
          slog::join_probe<2,1>(refindex389, std::array<u64,2>{v_c64, 0}, [&](const std::array<u64,2>& m399) {
            u64 v_c69 = m399[1];
            slog::join_probe<3,1>(appindex390, std::array<u64,3>{v_c69, 0, 0}, [&](const std::array<u64,3>& m400) {
              u64 v_c70 = m400[1]; u64 v_c71 = m400[2];
              if (v_c69 != v_c70) return;
              ++_fires;
              slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c64, v_c71}, std::array<u16,3>{1, 2, 0});
              slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c65, v_c66}, std::array<u16,3>{1, 2, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:183", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask391* _cont = new ReadTask391(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask391(db,b), false);
  // (crule (pre (let __tconst7JVW192 const6cf13cc59dcbe759113f68a4) (let __tconst7B9N190 constcaa3ee5a2828a31924f6b39d) (let __tconst5wC2180 const970c20ea81b833e5b5a7accf) (let __tconst2ady176 constc40f204dda7ba4054abb9e74)) (once) (body) (head (mkstruct ref (1 0) __t6fOY185 __tconst7JVW192) (mkstruct ref (1 0) __t8oRJ183 __tconst7B9N190) (mkstruct ref (1 0) __t52sB179 __tconst5wC2180) (mkstruct ref (1 0) __t3ZY4175 __tconst2ady176)) mcfa-counting.slog:301 #f)
  class ReadTask401 : public slog::Task
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
    ReadTask401(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c17 = v_const6cf13cc59dcbe759113f68a4;
      u64 v_c18 = v_constcaa3ee5a2828a31924f6b39d;
      u64 v_c19 = v_const970c20ea81b833e5b5a7accf;
      u64 v_c20 = v_constc40f204dda7ba4054abb9e74;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[4];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c17}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c18}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[2], newbatch[2], std::array<u64,1>{v_c19}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[3], newbatch[3], std::array<u64,1>{v_c20}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:301", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask401(db,b), true);
  // (crule (pre) (scan eval_ans __t8XTs321 va) (body (exists $sup27994x83x0x0x1 (2 8 0 1 3 4 5 6 7 9) 2 __t8XTs321 va) (join-old eval (0 2 1) 1 (0 2 1) __t8XTs321 c ea) (exists $sup27994x83x0x0x0 (1 2 0 3) 2 c ea) (exists eval (2 0 1) 1 c) (exists app (2 0 1) 1 ea) (join-old $sup27994x83x0x0x1 (2 3 5 8 0 1 4 6 7 9) 4 (2 3 5 8 0 1 4 6 7 9) __t8XTs321 c ea va __t5GoB317 __t1FV8318 cb eb ef x) (join-old $sup27994x83x0x0x0 (0 1 2 3) 4 (0 1 2 3) __t5GoB317 c ea ef) (join-old eval (0 2 1) 3 (0 2 1) __t1FV8318 c ef) (exists app (1 2 0) 2 ef ea) (exists lambda (1 2 0) 2 x eb) (exists clo (2 0 1) 1 cb) (exists eval_ans (0 1) 1 __t1FV8318) (exists eval (1 2 0) 1 eb) (join-old eval (0 2 1) 2 (0 2 1) __t5GoB317 c __t3MbO322) (join-old app (0 1 2) 3 (0 1 2) __t3MbO322 ef ea) (exists eval (1 2 0) 2 eb __t3MbO322) (join-old lambda (1 2 0) 2 (1 2 0) x eb __t6vap319) (join-old clo (1 2 0) 2 (1 2 0) __t6vap319 cb __t1oxE320) (join eval_ans (0 1) 2 __t1FV8318 __t1oxE320) (join-old eval (1 2 0) 2 (1 2 0) eb __t3MbO322 __t3H1A323) (join-old eval_ans (0 1) 1 (0 1) __t3H1A323 v)) (head (emit eval_ans (0 1) __t5GoB317 v)) mcfa-counting.slog:84 #f)
  class ReadTask433 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup27994x83x0x0x1index402;  slog::Index** evalindex403;  slog::Index** $sup27994x83x0x0x0index404;  slog::Index** evalindex405;  slog::Index** appindex406;  slog::Index** $sup27994x83x0x0x1index407;  slog::Index** $sup27994x83x0x0x0index408;  slog::Index** evalindex409;  slog::Index** appindex410;  slog::Index** lambdaindex411;  slog::Index** cloindex412;  slog::Index** eval_ansindex413;  slog::Index** evalindex414;  slog::Index** evalindex415;  slog::Index** appindex416;  slog::Index** evalindex417;  slog::Index** lambdaindex418;  slog::Index** cloindex419;  slog::Index** eval_ansindex420;  slog::Index** evalindex421;  slog::Index** eval_ansindex422;  slog::Index** evaldelta423;  slog::Index** $sup27994x83x0x0x1delta424;  slog::Index** $sup27994x83x0x0x0delta425;  slog::Index** evaldelta426;  slog::Index** evaldelta427;  slog::Index** appdelta428;  slog::Index** lambdadelta429;  slog::Index** clodelta430;  slog::Index** evaldelta431;  slog::Index** eval_ansdelta432;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord434({0, 1});
      slog::Relation* readrel435 = db->getRelation("eval_ans");
      head_index[0] = readrel435->getIndex(ord434, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord436({2, 8, 0, 1, 3, 4, 5, 6, 7, 9});
      slog::Relation* readrel437 = db->getRelation("$sup27994x83x0x0x1");
      $sup27994x83x0x0x1index402 = readrel437->getIndex(ord436, false);
      std::vector<u16> ord438({0, 2, 1});
      slog::Relation* readrel439 = db->getRelation("eval");
      evalindex403 = readrel439->getIndex(ord438, false);
      std::vector<u16> ord440({0, 2, 1});
      slog::Relation* readrel441 = db->getRelation("eval");
      evaldelta423 = readrel441->getIndex(ord440, true);
      std::vector<u16> ord442({1, 2, 0, 3});
      slog::Relation* readrel443 = db->getRelation("$sup27994x83x0x0x0");
      $sup27994x83x0x0x0index404 = readrel443->getIndex(ord442, false);
      std::vector<u16> ord444({2, 0, 1});
      slog::Relation* readrel445 = db->getRelation("eval");
      evalindex405 = readrel445->getIndex(ord444, false);
      std::vector<u16> ord446({2, 0, 1});
      slog::Relation* readrel447 = db->getRelation("app");
      appindex406 = readrel447->getIndex(ord446, false);
      std::vector<u16> ord448({2, 3, 5, 8, 0, 1, 4, 6, 7, 9});
      slog::Relation* readrel449 = db->getRelation("$sup27994x83x0x0x1");
      $sup27994x83x0x0x1index407 = readrel449->getIndex(ord448, false);
      std::vector<u16> ord450({2, 3, 5, 8, 0, 1, 4, 6, 7, 9});
      slog::Relation* readrel451 = db->getRelation("$sup27994x83x0x0x1");
      $sup27994x83x0x0x1delta424 = readrel451->getIndex(ord450, true);
      std::vector<u16> ord452({0, 1, 2, 3});
      slog::Relation* readrel453 = db->getRelation("$sup27994x83x0x0x0");
      $sup27994x83x0x0x0index408 = readrel453->getIndex(ord452, false);
      std::vector<u16> ord454({0, 1, 2, 3});
      slog::Relation* readrel455 = db->getRelation("$sup27994x83x0x0x0");
      $sup27994x83x0x0x0delta425 = readrel455->getIndex(ord454, true);
      std::vector<u16> ord456({0, 2, 1});
      slog::Relation* readrel457 = db->getRelation("eval");
      evalindex409 = readrel457->getIndex(ord456, false);
      std::vector<u16> ord458({0, 2, 1});
      slog::Relation* readrel459 = db->getRelation("eval");
      evaldelta426 = readrel459->getIndex(ord458, true);
      std::vector<u16> ord460({1, 2, 0});
      slog::Relation* readrel461 = db->getRelation("app");
      appindex410 = readrel461->getIndex(ord460, false);
      std::vector<u16> ord462({1, 2, 0});
      slog::Relation* readrel463 = db->getRelation("lambda");
      lambdaindex411 = readrel463->getIndex(ord462, false);
      std::vector<u16> ord464({2, 0, 1});
      slog::Relation* readrel465 = db->getRelation("clo");
      cloindex412 = readrel465->getIndex(ord464, false);
      std::vector<u16> ord466({0, 1});
      slog::Relation* readrel467 = db->getRelation("eval_ans");
      eval_ansindex413 = readrel467->getIndex(ord466, false);
      std::vector<u16> ord468({1, 2, 0});
      slog::Relation* readrel469 = db->getRelation("eval");
      evalindex414 = readrel469->getIndex(ord468, false);
      std::vector<u16> ord470({0, 2, 1});
      slog::Relation* readrel471 = db->getRelation("eval");
      evalindex415 = readrel471->getIndex(ord470, false);
      std::vector<u16> ord472({0, 2, 1});
      slog::Relation* readrel473 = db->getRelation("eval");
      evaldelta427 = readrel473->getIndex(ord472, true);
      std::vector<u16> ord474({0, 1, 2});
      slog::Relation* readrel475 = db->getRelation("app");
      appindex416 = readrel475->getIndex(ord474, false);
      std::vector<u16> ord476({0, 1, 2});
      slog::Relation* readrel477 = db->getRelation("app");
      appdelta428 = readrel477->getIndex(ord476, true);
      std::vector<u16> ord478({1, 2, 0});
      slog::Relation* readrel479 = db->getRelation("eval");
      evalindex417 = readrel479->getIndex(ord478, false);
      std::vector<u16> ord480({1, 2, 0});
      slog::Relation* readrel481 = db->getRelation("lambda");
      lambdaindex418 = readrel481->getIndex(ord480, false);
      std::vector<u16> ord482({1, 2, 0});
      slog::Relation* readrel483 = db->getRelation("lambda");
      lambdadelta429 = readrel483->getIndex(ord482, true);
      std::vector<u16> ord484({1, 2, 0});
      slog::Relation* readrel485 = db->getRelation("clo");
      cloindex419 = readrel485->getIndex(ord484, false);
      std::vector<u16> ord486({1, 2, 0});
      slog::Relation* readrel487 = db->getRelation("clo");
      clodelta430 = readrel487->getIndex(ord486, true);
      std::vector<u16> ord488({0, 1});
      slog::Relation* readrel489 = db->getRelation("eval_ans");
      eval_ansindex420 = readrel489->getIndex(ord488, false);
      std::vector<u16> ord490({1, 2, 0});
      slog::Relation* readrel491 = db->getRelation("eval");
      evalindex421 = readrel491->getIndex(ord490, false);
      std::vector<u16> ord492({1, 2, 0});
      slog::Relation* readrel493 = db->getRelation("eval");
      evaldelta431 = readrel493->getIndex(ord492, true);
      std::vector<u16> ord494({0, 1});
      slog::Relation* readrel495 = db->getRelation("eval_ans");
      eval_ansindex422 = readrel495->getIndex(ord494, false);
      std::vector<u16> ord496({0, 1});
      slog::Relation* readrel497 = db->getRelation("eval_ans");
      eval_ansdelta432 = readrel497->getIndex(ord496, true);
  
    }
    ReadTask433(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c50 = _t[1];
        if (!slog::exists_probe<10,2>($sup27994x83x0x0x1index402, std::array<u64,10>{v_c72, v_c50, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        slog::join_probe_old<3,1>(evalindex403, evaldelta423, std::array<u64,3>{v_c72, 0, 0}, [&](const std::array<u64,3>& m498) {
          u64 v_c45 = m498[1]; u64 v_c44 = m498[2];
          if (!slog::exists_probe<4,2>($sup27994x83x0x0x0index404, std::array<u64,4>{v_c45, v_c44, 0, 0})) return;
          if (!slog::exists_probe<3,1>(evalindex405, std::array<u64,3>{v_c45, 0, 0})) return;
          if (!slog::exists_probe<3,1>(appindex406, std::array<u64,3>{v_c44, 0, 0})) return;
          slog::join_probe_old<10,4>($sup27994x83x0x0x1index407, $sup27994x83x0x0x1delta424, std::array<u64,10>{v_c72, v_c45, v_c44, v_c50, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,10>& m499) {
            u64 v_c73 = m499[4]; u64 v_c74 = m499[5]; u64 v_c51 = m499[6]; u64 v_c54 = m499[7]; u64 v_c47 = m499[8]; u64 v_c53 = m499[9];
            slog::join_probe_old<4,4>($sup27994x83x0x0x0index408, $sup27994x83x0x0x0delta425, std::array<u64,4>{v_c73, v_c45, v_c44, v_c47}, [&](const std::array<u64,4>& m500) {
              slog::join_probe_old<3,3>(evalindex409, evaldelta426, std::array<u64,3>{v_c74, v_c45, v_c47}, [&](const std::array<u64,3>& m501) {
                if (!slog::exists_probe<3,2>(appindex410, std::array<u64,3>{v_c47, v_c44, 0})) return;
                if (!slog::exists_probe<3,2>(lambdaindex411, std::array<u64,3>{v_c53, v_c54, 0})) return;
                if (!slog::exists_probe<3,1>(cloindex412, std::array<u64,3>{v_c51, 0, 0})) return;
                if (!slog::exists_probe<2,1>(eval_ansindex413, std::array<u64,2>{v_c74, 0})) return;
                if (!slog::exists_probe<3,1>(evalindex414, std::array<u64,3>{v_c54, 0, 0})) return;
                slog::join_probe_old<3,2>(evalindex415, evaldelta427, std::array<u64,3>{v_c73, v_c45, 0}, [&](const std::array<u64,3>& m502) {
                  u64 v_c75 = m502[2];
                  slog::join_probe_old<3,3>(appindex416, appdelta428, std::array<u64,3>{v_c75, v_c47, v_c44}, [&](const std::array<u64,3>& m503) {
                    if (!slog::exists_probe<3,2>(evalindex417, std::array<u64,3>{v_c54, v_c75, 0})) return;
                    slog::join_probe_old<3,2>(lambdaindex418, lambdadelta429, std::array<u64,3>{v_c53, v_c54, 0}, [&](const std::array<u64,3>& m504) {
                      u64 v_c76 = m504[2];
                      slog::join_probe_old<3,2>(cloindex419, clodelta430, std::array<u64,3>{v_c76, v_c51, 0}, [&](const std::array<u64,3>& m505) {
                        u64 v_c77 = m505[2];
                        slog::join_probe<2,2>(eval_ansindex420, std::array<u64,2>{v_c74, v_c77}, [&](const std::array<u64,2>& m506) {
                          slog::join_probe_old<3,2>(evalindex421, evaldelta431, std::array<u64,3>{v_c54, v_c75, 0}, [&](const std::array<u64,3>& m507) {
                            u64 v_c78 = m507[2];
                            slog::join_probe_old<2,1>(eval_ansindex422, eval_ansdelta432, std::array<u64,2>{v_c78, 0}, [&](const std::array<u64,2>& m508) {
                              u64 v_c79 = m508[1];
                              ++_fires;
                              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c73, v_c79}, std::array<u16,2>{0, 1});
                            });
                          });
                        });
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
        ReadTask433* _cont = new ReadTask433(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask433(db,b), false);
  // (crule (pre) (scan eval __t8FVl165 __t2jDL164 c) (body (exists store (1 0 2) 1 c) (join ref (0 1) 1 __t2jDL164 x) (join store (0 1 2) 2 x c v)) (head (emit eval_ans (0 1) __t8FVl165 v)) mcfa-counting.slog:81 #f)
  class ReadTask512 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** storeindex509;  slog::Index** refindex510;  slog::Index** storeindex511;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord513({0, 1});
      slog::Relation* readrel514 = db->getRelation("eval_ans");
      head_index[0] = readrel514->getIndex(ord513, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord515({1, 0, 2});
      slog::Relation* readrel516 = db->getRelation("store");
      storeindex509 = readrel516->getIndex(ord515, false);
      std::vector<u16> ord517({0, 1});
      slog::Relation* readrel518 = db->getRelation("ref");
      refindex510 = readrel518->getIndex(ord517, false);
      std::vector<u16> ord519({0, 1, 2});
      slog::Relation* readrel520 = db->getRelation("store");
      storeindex511 = readrel520->getIndex(ord519, false);
  
    }
    ReadTask512(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c80 = _t[0];
        u64 v_c81 = _t[1];
        u64 v_c45 = _t[2];
        if (!slog::exists_probe<3,1>(storeindex509, std::array<u64,3>{v_c45, 0, 0})) return;
        slog::join_probe<2,1>(refindex510, std::array<u64,2>{v_c81, 0}, [&](const std::array<u64,2>& m521) {
          u64 v_c53 = m521[1];
          slog::join_probe<3,2>(storeindex511, std::array<u64,3>{v_c53, v_c45, 0}, [&](const std::array<u64,3>& m522) {
            u64 v_c79 = m522[2];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c80, v_c79}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:81", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask512* _cont = new ReadTask512(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask512(db,b), false);
  // (crule (pre (let __tconst0y6X73 const0aa6f87434af0222b916e97a) (let __tconst7zoP70 const227d34ceeba7a29aada993d4) (let __tconst1bfe65 const59ba3256d223f0d0a00d0633) (let __tconst8wN863 const7cd75b35aa30c3ddf04f9d57) (let __tconst0aL952 constd3d07026d47882ceca728218) (let __tconst0xUh47 constf700a82e218a86de572e1f7f)) (seeded) (body (join ref (1 0) 1 __tconst0xUh47 __t5vZb46) (exists ref (1 0) 1 __tconst0aL952) (exists ref (1 0) 1 __tconst1bfe65) (exists lambda (1 2 0) 1 __tconst1bfe65) (exists ref (1 0) 1 __tconst0y6X73) (exists ref (1 0) 1 __tconst8wN863) (exists lambda (1 2 0) 1 __tconst8wN863) (join lambda (1 2 0) 2 __tconst0xUh47 __t5vZb46 __t50zW48) (join ref (1 0) 1 __tconst0aL952 __t5HQ450) (join ref (1 0) 1 __tconst1bfe65 __t2HsD55) (join lambda (1 2 0) 2 __tconst1bfe65 __t2HsD55 __t0uNb57) (join ref (1 0) 1 __tconst0y6X73 __t0QRr59) (join ref (1 0) 1 __tconst8wN863 __t1mkO62) (join lambda (1 2 0) 2 __tconst8wN863 __t1mkO62 __t3Dru64)) (head (mkstruct lambda (1 2 0) __t7JIT66 __tconst1bfe65 __t3Dru64) (mkstruct app (1 2 0) __t81HE60 __t0QRr59 __t0uNb57) (mkstruct app (1 2 0) __t05NY51 __t5HQ450 __t50zW48)) mcfa-counting.slog:287 #f)
  class ReadTask537 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
  
  
  
  
  
  
    slog::Index** refindex523;  slog::Index** refindex524;  slog::Index** refindex525;  slog::Index** lambdaindex526;  slog::Index** refindex527;  slog::Index** refindex528;  slog::Index** lambdaindex529;  slog::Index** lambdaindex530;  slog::Index** refindex531;  slog::Index** refindex532;  slog::Index** lambdaindex533;  slog::Index** refindex534;  slog::Index** refindex535;  slog::Index** lambdaindex536;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      std::vector<u16> ord538({1, 2, 0});
      slog::Relation* readrel539 = db->getRelation("lambda");
      head_index[0] = readrel539->getIndex(ord538, false);
      head_rel[1] = db->getRelation("app");
      std::vector<u16> ord540({1, 2, 0});
      slog::Relation* readrel541 = db->getRelation("app");
      head_index[1] = readrel541->getIndex(ord540, false);
      head_rel[2] = db->getRelation("app");
      std::vector<u16> ord542({1, 2, 0});
      slog::Relation* readrel543 = db->getRelation("app");
      head_index[2] = readrel543->getIndex(ord542, false);
      std::vector<u16> ord544({1, 0});
      slog::Relation* readrel545 = db->getRelation("ref");
      refindex523 = readrel545->getIndex(ord544, false);
      std::vector<u16> ord546({1, 0});
      slog::Relation* readrel547 = db->getRelation("ref");
      refindex524 = readrel547->getIndex(ord546, false);
      std::vector<u16> ord548({1, 0});
      slog::Relation* readrel549 = db->getRelation("ref");
      refindex525 = readrel549->getIndex(ord548, false);
      std::vector<u16> ord550({1, 2, 0});
      slog::Relation* readrel551 = db->getRelation("lambda");
      lambdaindex526 = readrel551->getIndex(ord550, false);
      std::vector<u16> ord552({1, 0});
      slog::Relation* readrel553 = db->getRelation("ref");
      refindex527 = readrel553->getIndex(ord552, false);
      std::vector<u16> ord554({1, 0});
      slog::Relation* readrel555 = db->getRelation("ref");
      refindex528 = readrel555->getIndex(ord554, false);
      std::vector<u16> ord556({1, 2, 0});
      slog::Relation* readrel557 = db->getRelation("lambda");
      lambdaindex529 = readrel557->getIndex(ord556, false);
      std::vector<u16> ord558({1, 2, 0});
      slog::Relation* readrel559 = db->getRelation("lambda");
      lambdaindex530 = readrel559->getIndex(ord558, false);
      std::vector<u16> ord560({1, 0});
      slog::Relation* readrel561 = db->getRelation("ref");
      refindex531 = readrel561->getIndex(ord560, false);
      std::vector<u16> ord562({1, 0});
      slog::Relation* readrel563 = db->getRelation("ref");
      refindex532 = readrel563->getIndex(ord562, false);
      std::vector<u16> ord564({1, 2, 0});
      slog::Relation* readrel565 = db->getRelation("lambda");
      lambdaindex533 = readrel565->getIndex(ord564, false);
      std::vector<u16> ord566({1, 0});
      slog::Relation* readrel567 = db->getRelation("ref");
      refindex534 = readrel567->getIndex(ord566, false);
      std::vector<u16> ord568({1, 0});
      slog::Relation* readrel569 = db->getRelation("ref");
      refindex535 = readrel569->getIndex(ord568, false);
      std::vector<u16> ord570({1, 2, 0});
      slog::Relation* readrel571 = db->getRelation("lambda");
      lambdaindex536 = readrel571->getIndex(ord570, false);
  
    }
    ReadTask537(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c82 = v_const0aa6f87434af0222b916e97a;
      u64 v_c83 = v_const227d34ceeba7a29aada993d4;
      u64 v_c84 = v_const59ba3256d223f0d0a00d0633;
      u64 v_c85 = v_const7cd75b35aa30c3ddf04f9d57;
      u64 v_c86 = v_constd3d07026d47882ceca728218;
      u64 v_c87 = v_constf700a82e218a86de572e1f7f;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex523, std::array<u64,2>{v_c87, 0}, [&](const std::array<u64,2>& m572) {
        u64 v_c88 = m572[1];
        if (!slog::exists_probe<2,1>(refindex524, std::array<u64,2>{v_c86, 0})) return;
        if (!slog::exists_probe<2,1>(refindex525, std::array<u64,2>{v_c84, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex526, std::array<u64,3>{v_c84, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex527, std::array<u64,2>{v_c82, 0})) return;
        if (!slog::exists_probe<2,1>(refindex528, std::array<u64,2>{v_c85, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex529, std::array<u64,3>{v_c85, 0, 0})) return;
        slog::join_probe<3,2>(lambdaindex530, std::array<u64,3>{v_c87, v_c88, 0}, [&](const std::array<u64,3>& m573) {
          u64 v_c89 = m573[2];
          slog::join_probe<2,1>(refindex531, std::array<u64,2>{v_c86, 0}, [&](const std::array<u64,2>& m574) {
            u64 v_c90 = m574[1];
            slog::join_probe<2,1>(refindex532, std::array<u64,2>{v_c84, 0}, [&](const std::array<u64,2>& m575) {
              u64 v_c91 = m575[1];
              slog::join_probe<3,2>(lambdaindex533, std::array<u64,3>{v_c84, v_c91, 0}, [&](const std::array<u64,3>& m576) {
                u64 v_c92 = m576[2];
                slog::join_probe<2,1>(refindex534, std::array<u64,2>{v_c82, 0}, [&](const std::array<u64,2>& m577) {
                  u64 v_c93 = m577[1];
                  slog::join_probe<2,1>(refindex535, std::array<u64,2>{v_c85, 0}, [&](const std::array<u64,2>& m578) {
                    u64 v_c94 = m578[1];
                    slog::join_probe<3,2>(lambdaindex536, std::array<u64,3>{v_c85, v_c94, 0}, [&](const std::array<u64,3>& m579) {
                      u64 v_c95 = m579[2];
                      ++_fires;
                      slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c84, v_c95}, std::array<u16,3>{1, 2, 0});
                      slog::emit_struct_checked<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c93, v_c92}, std::array<u16,3>{1, 2, 0});
                      slog::emit_struct_checked<3>(head_rel[2], head_index[2], newbatch[2], std::array<u64,2>{v_c90, v_c89}, std::array<u16,3>{1, 2, 0});
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
  
      if (_fires) db->bumpFires("mcfa-counting.slog:287", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask537(db,b));
  // (crule (pre (let __tconst9zoW125 const7c7d2cfc66f4d976987d2d20) (let __tconst4V4L122 const6bc0ba365ada70df115e1785) (let __tconst82U8119 consta8180db1c2f300980314f910) (let __tconst3wDH116 constd5f017533ea574d5f9b3400c) (let __tconst4BKz104 const0f8748be649f8ee4066bb1d7) (let __tconst4Zcr91 const9a67f28c6b77e842f439a84a) (let __tconst3ktF111 const990b444cbd47632035b2fa1a) (let __tconst5nWJ102 const4f84f41d89b6b717419b4eaa) (let __tconst0vRf84 conste58dec6bca6f63ef79c3b755)) (probe lambda (1 2 0) 1 __tconst4Zcr91 __t2Eqd90 __t3pgm92) (body (exists ref (1 0) 1 __tconst3wDH116) (exists ref (1 0) 1 __tconst0vRf84) (exists lambda (1 2 0) 1 __tconst0vRf84) (exists ref (1 0) 1 __tconst4Zcr91) (exists ref (1 0) 1 __tconst9zoW125) (exists ref (1 0) 1 __tconst4BKz104) (exists lambda (1 2 0) 1 __tconst4BKz104) (exists ref (1 0) 1 __tconst5nWJ102) (exists lambda (1 2 0) 1 __tconst5nWJ102) (exists ref (1 0) 1 __tconst3ktF111) (exists lambda (1 2 0) 1 __tconst3ktF111) (join ref (1 0) 1 __tconst4V4L122 __t7aew98) (exists app (1 2 0) 1 __t7aew98) (join ref (1 0) 1 __tconst3wDH116 __t3wir114) (exists app (1 2 0) 1 __t3wir114) (join ref (1 0) 1 __tconst0vRf84 __t2duR83) (join lambda (1 2 0) 2 __tconst0vRf84 __t2duR83 __t87vL85) (join ref (1 0) 1 __tconst4Zcr91 __t0C9F87) (join app (2 0 1) 2 __t0C9F87 __t2Eqd90 __t3Q2G89) (join ref (0 1) 2 __t3Q2G89 __tconst9zoW125) (join ref (1 0) 1 __tconst4BKz104 __t8C0a94) (join lambda (1 2 0) 2 __tconst4BKz104 __t8C0a94 __t4fDK96) (join app (1 2 0) 2 __t7aew98 __t4fDK96 __t7TEO99) (join ref (1 0) 1 __tconst5nWJ102 __t5MaG101) (join lambda (1 2 0) 2 __tconst5nWJ102 __t5MaG101 __t35jA103) (join lambda (1 2 0) 2 __tconst4BKz104 __t35jA103 __t6RuY105) (join ref (1 0) 1 __tconst3ktF111 __t7ohz110) (join lambda (1 2 0) 2 __tconst3ktF111 __t7ohz110 __t8GWA112) (join app (1 2 0) 2 __t3wir114 __t8GWA112 __t44OM115)) (head (mkstruct lambda (1 2 0) __t7CwH117 __tconst3wDH116 __t44OM115) (mkstruct app (1 2 0) __t2Z7m108 __t7aew98 __t6RuY105)) mcfa-counting.slog:241 #f)
  class ReadTask609 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** refindex580;  slog::Index** refindex581;  slog::Index** lambdaindex582;  slog::Index** refindex583;  slog::Index** refindex584;  slog::Index** refindex585;  slog::Index** lambdaindex586;  slog::Index** refindex587;  slog::Index** lambdaindex588;  slog::Index** refindex589;  slog::Index** lambdaindex590;  slog::Index** refindex591;  slog::Index** appindex592;  slog::Index** refindex593;  slog::Index** appindex594;  slog::Index** refindex595;  slog::Index** lambdaindex596;  slog::Index** refindex597;  slog::Index** appindex598;  slog::Index** refindex599;  slog::Index** refindex600;  slog::Index** lambdaindex601;  slog::Index** appindex602;  slog::Index** refindex603;  slog::Index** lambdaindex604;  slog::Index** lambdaindex605;  slog::Index** refindex606;  slog::Index** lambdaindex607;  slog::Index** appindex608;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      head_rel[1] = db->getRelation("app");
      std::vector<u16> ord610({1, 2, 0});
      slog::Relation* readrel611 = db->getRelation("lambda");
      driver_index = readrel611->getIndex(ord610, true);
      std::vector<u16> ord612({1, 0});
      slog::Relation* readrel613 = db->getRelation("ref");
      refindex580 = readrel613->getIndex(ord612, false);
      std::vector<u16> ord614({1, 0});
      slog::Relation* readrel615 = db->getRelation("ref");
      refindex581 = readrel615->getIndex(ord614, false);
      std::vector<u16> ord616({1, 2, 0});
      slog::Relation* readrel617 = db->getRelation("lambda");
      lambdaindex582 = readrel617->getIndex(ord616, false);
      std::vector<u16> ord618({1, 0});
      slog::Relation* readrel619 = db->getRelation("ref");
      refindex583 = readrel619->getIndex(ord618, false);
      std::vector<u16> ord620({1, 0});
      slog::Relation* readrel621 = db->getRelation("ref");
      refindex584 = readrel621->getIndex(ord620, false);
      std::vector<u16> ord622({1, 0});
      slog::Relation* readrel623 = db->getRelation("ref");
      refindex585 = readrel623->getIndex(ord622, false);
      std::vector<u16> ord624({1, 2, 0});
      slog::Relation* readrel625 = db->getRelation("lambda");
      lambdaindex586 = readrel625->getIndex(ord624, false);
      std::vector<u16> ord626({1, 0});
      slog::Relation* readrel627 = db->getRelation("ref");
      refindex587 = readrel627->getIndex(ord626, false);
      std::vector<u16> ord628({1, 2, 0});
      slog::Relation* readrel629 = db->getRelation("lambda");
      lambdaindex588 = readrel629->getIndex(ord628, false);
      std::vector<u16> ord630({1, 0});
      slog::Relation* readrel631 = db->getRelation("ref");
      refindex589 = readrel631->getIndex(ord630, false);
      std::vector<u16> ord632({1, 2, 0});
      slog::Relation* readrel633 = db->getRelation("lambda");
      lambdaindex590 = readrel633->getIndex(ord632, false);
      std::vector<u16> ord634({1, 0});
      slog::Relation* readrel635 = db->getRelation("ref");
      refindex591 = readrel635->getIndex(ord634, false);
      std::vector<u16> ord636({1, 2, 0});
      slog::Relation* readrel637 = db->getRelation("app");
      appindex592 = readrel637->getIndex(ord636, false);
      std::vector<u16> ord638({1, 0});
      slog::Relation* readrel639 = db->getRelation("ref");
      refindex593 = readrel639->getIndex(ord638, false);
      std::vector<u16> ord640({1, 2, 0});
      slog::Relation* readrel641 = db->getRelation("app");
      appindex594 = readrel641->getIndex(ord640, false);
      std::vector<u16> ord642({1, 0});
      slog::Relation* readrel643 = db->getRelation("ref");
      refindex595 = readrel643->getIndex(ord642, false);
      std::vector<u16> ord644({1, 2, 0});
      slog::Relation* readrel645 = db->getRelation("lambda");
      lambdaindex596 = readrel645->getIndex(ord644, false);
      std::vector<u16> ord646({1, 0});
      slog::Relation* readrel647 = db->getRelation("ref");
      refindex597 = readrel647->getIndex(ord646, false);
      std::vector<u16> ord648({2, 0, 1});
      slog::Relation* readrel649 = db->getRelation("app");
      appindex598 = readrel649->getIndex(ord648, false);
      std::vector<u16> ord650({0, 1});
      slog::Relation* readrel651 = db->getRelation("ref");
      refindex599 = readrel651->getIndex(ord650, false);
      std::vector<u16> ord652({1, 0});
      slog::Relation* readrel653 = db->getRelation("ref");
      refindex600 = readrel653->getIndex(ord652, false);
      std::vector<u16> ord654({1, 2, 0});
      slog::Relation* readrel655 = db->getRelation("lambda");
      lambdaindex601 = readrel655->getIndex(ord654, false);
      std::vector<u16> ord656({1, 2, 0});
      slog::Relation* readrel657 = db->getRelation("app");
      appindex602 = readrel657->getIndex(ord656, false);
      std::vector<u16> ord658({1, 0});
      slog::Relation* readrel659 = db->getRelation("ref");
      refindex603 = readrel659->getIndex(ord658, false);
      std::vector<u16> ord660({1, 2, 0});
      slog::Relation* readrel661 = db->getRelation("lambda");
      lambdaindex604 = readrel661->getIndex(ord660, false);
      std::vector<u16> ord662({1, 2, 0});
      slog::Relation* readrel663 = db->getRelation("lambda");
      lambdaindex605 = readrel663->getIndex(ord662, false);
      std::vector<u16> ord664({1, 0});
      slog::Relation* readrel665 = db->getRelation("ref");
      refindex606 = readrel665->getIndex(ord664, false);
      std::vector<u16> ord666({1, 2, 0});
      slog::Relation* readrel667 = db->getRelation("lambda");
      lambdaindex607 = readrel667->getIndex(ord666, false);
      std::vector<u16> ord668({1, 2, 0});
      slog::Relation* readrel669 = db->getRelation("app");
      appindex608 = readrel669->getIndex(ord668, false);
  
    }
    ReadTask609(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const7c7d2cfc66f4d976987d2d20;
      u64 v_c1 = v_const6bc0ba365ada70df115e1785;
      u64 v_c2 = v_consta8180db1c2f300980314f910;
      u64 v_c3 = v_constd5f017533ea574d5f9b3400c;
      u64 v_c5 = v_const0f8748be649f8ee4066bb1d7;
      u64 v_c7 = v_const9a67f28c6b77e842f439a84a;
      u64 v_c4 = v_const990b444cbd47632035b2fa1a;
      u64 v_c6 = v_const4f84f41d89b6b717419b4eaa;
      u64 v_c8 = v_conste58dec6bca6f63ef79c3b755;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c7, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m670) {
        u64 v_c96 = m670[1];
        u64 v_c97 = m670[2];
        if (buckethash(v_c96) != bucket) return;
        if (!slog::exists_probe<2,1>(refindex580, std::array<u64,2>{v_c3, 0})) return;
        if (!slog::exists_probe<2,1>(refindex581, std::array<u64,2>{v_c8, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex582, std::array<u64,3>{v_c8, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex583, std::array<u64,2>{v_c7, 0})) return;
        if (!slog::exists_probe<2,1>(refindex584, std::array<u64,2>{v_c0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex585, std::array<u64,2>{v_c5, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex586, std::array<u64,3>{v_c5, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex587, std::array<u64,2>{v_c6, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex588, std::array<u64,3>{v_c6, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex589, std::array<u64,2>{v_c4, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex590, std::array<u64,3>{v_c4, 0, 0})) return;
        slog::join_probe<2,1>(refindex591, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m671) {
          u64 v_c13 = m671[1];
          if (!slog::exists_probe<3,1>(appindex592, std::array<u64,3>{v_c13, 0, 0})) return;
          slog::join_probe<2,1>(refindex593, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m672) {
            u64 v_c16 = m672[1];
            if (!slog::exists_probe<3,1>(appindex594, std::array<u64,3>{v_c16, 0, 0})) return;
            slog::join_probe<2,1>(refindex595, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m673) {
              u64 v_c9 = m673[1];
              slog::join_probe<3,2>(lambdaindex596, std::array<u64,3>{v_c8, v_c9, 0}, [&](const std::array<u64,3>& m674) {
                u64 v_c98 = m674[2];
                slog::join_probe<2,1>(refindex597, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m675) {
                  u64 v_c10 = m675[1];
                  slog::join_probe<3,2>(appindex598, std::array<u64,3>{v_c10, v_c96, 0}, [&](const std::array<u64,3>& m676) {
                    u64 v_c11 = m676[2];
                    slog::join_probe<2,2>(refindex599, std::array<u64,2>{v_c11, v_c0}, [&](const std::array<u64,2>& m677) {
                      slog::join_probe<2,1>(refindex600, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m678) {
                        u64 v_c12 = m678[1];
                        slog::join_probe<3,2>(lambdaindex601, std::array<u64,3>{v_c5, v_c12, 0}, [&](const std::array<u64,3>& m679) {
                          u64 v_c99 = m679[2];
                          slog::join_probe<3,2>(appindex602, std::array<u64,3>{v_c13, v_c99, 0}, [&](const std::array<u64,3>& m680) {
                            u64 v_c100 = m680[2];
                            slog::join_probe<2,1>(refindex603, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m681) {
                              u64 v_c14 = m681[1];
                              slog::join_probe<3,2>(lambdaindex604, std::array<u64,3>{v_c6, v_c14, 0}, [&](const std::array<u64,3>& m682) {
                                u64 v_c101 = m682[2];
                                slog::join_probe<3,2>(lambdaindex605, std::array<u64,3>{v_c5, v_c101, 0}, [&](const std::array<u64,3>& m683) {
                                  u64 v_c102 = m683[2];
                                  slog::join_probe<2,1>(refindex606, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m684) {
                                    u64 v_c15 = m684[1];
                                    slog::join_probe<3,2>(lambdaindex607, std::array<u64,3>{v_c4, v_c15, 0}, [&](const std::array<u64,3>& m685) {
                                      u64 v_c103 = m685[2];
                                      slog::join_probe<3,2>(appindex608, std::array<u64,3>{v_c16, v_c103, 0}, [&](const std::array<u64,3>& m686) {
                                        u64 v_c104 = m686[2];
                                        ++_fires;
                                        slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c3, v_c104}, std::array<u16,3>{1, 2, 0});
                                        slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c13, v_c102}, std::array<u16,3>{1, 2, 0});
                                      });
                                    });
                                  });
                                });
                              });
                            });
                          });
                        });
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
  
      if (_fires) db->bumpFires("mcfa-counting.slog:241", "delta:lambda", _fires);
  
      if (!_done)
      {
        ReadTask609* _cont = new ReadTask609(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask609(db,b), false);
  // (crule (pre) (scan store y cb vy) (body (join-old freevar (0 1) 1 (0 1) y __t3DWB162) (join-old lambda (0 1 2) 1 (0 1 2) __t3DWB162 x eb) (join-old eval (0 2 1) 0 (0 2 1) __9gNV361 c __t0neE161) (join-old app (0 1 2) 1 (0 1 2) __t0neE161 ef ea)) (head (mkstruct eval (1 2 0) __1Zia362 ef c)) mcfa-counting.slog:102 #f)
  class ReadTask695 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** freevarindex687;  slog::Index** lambdaindex688;  slog::Index** evalindex689;  slog::Index** appindex690;  slog::Index** freevardelta691;  slog::Index** lambdadelta692;  slog::Index** evaldelta693;  slog::Index** appdelta694;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("store");
      std::vector<u16> ord696({0, 1});
      slog::Relation* readrel697 = db->getRelation("freevar");
      freevarindex687 = readrel697->getIndex(ord696, false);
      std::vector<u16> ord698({0, 1});
      slog::Relation* readrel699 = db->getRelation("freevar");
      freevardelta691 = readrel699->getIndex(ord698, true);
      std::vector<u16> ord700({0, 1, 2});
      slog::Relation* readrel701 = db->getRelation("lambda");
      lambdaindex688 = readrel701->getIndex(ord700, false);
      std::vector<u16> ord702({0, 1, 2});
      slog::Relation* readrel703 = db->getRelation("lambda");
      lambdadelta692 = readrel703->getIndex(ord702, true);
      std::vector<u16> ord704({0, 2, 1});
      slog::Relation* readrel705 = db->getRelation("eval");
      evalindex689 = readrel705->getIndex(ord704, false);
      std::vector<u16> ord706({0, 2, 1});
      slog::Relation* readrel707 = db->getRelation("eval");
      evaldelta693 = readrel707->getIndex(ord706, true);
      std::vector<u16> ord708({0, 1, 2});
      slog::Relation* readrel709 = db->getRelation("app");
      appindex690 = readrel709->getIndex(ord708, false);
      std::vector<u16> ord710({0, 1, 2});
      slog::Relation* readrel711 = db->getRelation("app");
      appdelta694 = readrel711->getIndex(ord710, true);
  
    }
    ReadTask695(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c62 = _t[0];
        u64 v_c51 = _t[1];
        u64 v_c63 = _t[2];
        slog::join_probe_old<2,1>(freevarindex687, freevardelta691, std::array<u64,2>{v_c62, 0}, [&](const std::array<u64,2>& m712) {
          u64 v_c105 = m712[1];
          slog::join_probe_old<3,1>(lambdaindex688, lambdadelta692, std::array<u64,3>{v_c105, 0, 0}, [&](const std::array<u64,3>& m713) {
            u64 v_c53 = m713[1]; u64 v_c54 = m713[2];
            slog::join_all_old<3>(evalindex689, evaldelta693, [&](const std::array<u64,3>& m714) {
              u64 v_c106 = m714[0]; u64 v_c45 = m714[1]; u64 v_c107 = m714[2];
              slog::join_probe_old<3,1>(appindex690, appdelta694, std::array<u64,3>{v_c107, 0, 0}, [&](const std::array<u64,3>& m715) {
                u64 v_c47 = m715[1]; u64 v_c44 = m715[2];
                ++_fires;
                slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c47, v_c45}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:102", "delta:store", _fires);
  
      if (!_done)
      {
        ReadTask695* _cont = new ReadTask695(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask695(db,b), false);
  // (crule (pre (let __tconst1pJW313 constb49bea2fcccd8f4301a347ed) (let __tconst7LWP310 const66518c0c1b3a5a0b09ae2ef1) (let __tconst0sqO307 const4a8acfc71441e0695ffcf5b3) (let __tconst2CSv302 const229c0b7aa8a7eb4055f5a3d0) (let __tconst9rZO295 const576506f61f53440f1edd95d2) (let __tconst5PoN291 constc85eae03730a4f4cf1d66a0c) (let __tconst2Yzp284 const8ca682693a0738a0641c6956)) (seeded) (body (join ref (1 0) 1 __tconst2Yzp284 __t248W283) (exists ref (1 0) 1 __tconst9rZO295) (exists ref (1 0) 1 __tconst7LWP310) (exists ref (1 0) 1 __tconst2CSv302) (join ref (1 0) 1 __tconst1pJW313 __t165O287) (join ref (1 0) 1 __tconst9rZO295 __t71w7294) (join ref (1 0) 1 __tconst7LWP310 __t91H2298) (join ref (1 0) 1 __tconst2CSv302 __t6lXa301)) (head (mkstruct lambda (1 2 0) __t7EW2303 __tconst2CSv302 __t6lXa301) (mkstruct lambda (1 2 0) __t3dkk296 __tconst9rZO295 __t71w7294) (mkstruct app (1 2 0) __t30Ec290 __t165O287 __t165O287) (mkstruct lambda (1 2 0) __t0oFu285 __tconst2Yzp284 __t248W283)) mcfa-counting.slog:194 #f)
  class ReadTask724 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[4];
    slog::Index** head_index[4];
  
  
  
  
  
  
    slog::Index** refindex716;  slog::Index** refindex717;  slog::Index** refindex718;  slog::Index** refindex719;  slog::Index** refindex720;  slog::Index** refindex721;  slog::Index** refindex722;  slog::Index** refindex723;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      std::vector<u16> ord725({1, 2, 0});
      slog::Relation* readrel726 = db->getRelation("lambda");
      head_index[0] = readrel726->getIndex(ord725, false);
      head_rel[1] = db->getRelation("lambda");
      std::vector<u16> ord727({1, 2, 0});
      slog::Relation* readrel728 = db->getRelation("lambda");
      head_index[1] = readrel728->getIndex(ord727, false);
      head_rel[2] = db->getRelation("app");
      std::vector<u16> ord729({1, 2, 0});
      slog::Relation* readrel730 = db->getRelation("app");
      head_index[2] = readrel730->getIndex(ord729, false);
      head_rel[3] = db->getRelation("lambda");
      std::vector<u16> ord731({1, 2, 0});
      slog::Relation* readrel732 = db->getRelation("lambda");
      head_index[3] = readrel732->getIndex(ord731, false);
      std::vector<u16> ord733({1, 0});
      slog::Relation* readrel734 = db->getRelation("ref");
      refindex716 = readrel734->getIndex(ord733, false);
      std::vector<u16> ord735({1, 0});
      slog::Relation* readrel736 = db->getRelation("ref");
      refindex717 = readrel736->getIndex(ord735, false);
      std::vector<u16> ord737({1, 0});
      slog::Relation* readrel738 = db->getRelation("ref");
      refindex718 = readrel738->getIndex(ord737, false);
      std::vector<u16> ord739({1, 0});
      slog::Relation* readrel740 = db->getRelation("ref");
      refindex719 = readrel740->getIndex(ord739, false);
      std::vector<u16> ord741({1, 0});
      slog::Relation* readrel742 = db->getRelation("ref");
      refindex720 = readrel742->getIndex(ord741, false);
      std::vector<u16> ord743({1, 0});
      slog::Relation* readrel744 = db->getRelation("ref");
      refindex721 = readrel744->getIndex(ord743, false);
      std::vector<u16> ord745({1, 0});
      slog::Relation* readrel746 = db->getRelation("ref");
      refindex722 = readrel746->getIndex(ord745, false);
      std::vector<u16> ord747({1, 0});
      slog::Relation* readrel748 = db->getRelation("ref");
      refindex723 = readrel748->getIndex(ord747, false);
  
    }
    ReadTask724(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c108 = v_constb49bea2fcccd8f4301a347ed;
      u64 v_c109 = v_const66518c0c1b3a5a0b09ae2ef1;
      u64 v_c110 = v_const4a8acfc71441e0695ffcf5b3;
      u64 v_c111 = v_const229c0b7aa8a7eb4055f5a3d0;
      u64 v_c112 = v_const576506f61f53440f1edd95d2;
      u64 v_c113 = v_constc85eae03730a4f4cf1d66a0c;
      u64 v_c114 = v_const8ca682693a0738a0641c6956;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[4];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex716, std::array<u64,2>{v_c114, 0}, [&](const std::array<u64,2>& m749) {
        u64 v_c115 = m749[1];
        if (!slog::exists_probe<2,1>(refindex717, std::array<u64,2>{v_c112, 0})) return;
        if (!slog::exists_probe<2,1>(refindex718, std::array<u64,2>{v_c109, 0})) return;
        if (!slog::exists_probe<2,1>(refindex719, std::array<u64,2>{v_c111, 0})) return;
        slog::join_probe<2,1>(refindex720, std::array<u64,2>{v_c108, 0}, [&](const std::array<u64,2>& m750) {
          u64 v_c116 = m750[1];
          slog::join_probe<2,1>(refindex721, std::array<u64,2>{v_c112, 0}, [&](const std::array<u64,2>& m751) {
            u64 v_c117 = m751[1];
            slog::join_probe<2,1>(refindex722, std::array<u64,2>{v_c109, 0}, [&](const std::array<u64,2>& m752) {
              u64 v_c118 = m752[1];
              slog::join_probe<2,1>(refindex723, std::array<u64,2>{v_c111, 0}, [&](const std::array<u64,2>& m753) {
                u64 v_c119 = m753[1];
                ++_fires;
                slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c111, v_c119}, std::array<u16,3>{1, 2, 0});
                slog::emit_struct_checked<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c112, v_c117}, std::array<u16,3>{1, 2, 0});
                slog::emit_struct_checked<3>(head_rel[2], head_index[2], newbatch[2], std::array<u64,2>{v_c116, v_c116}, std::array<u16,3>{1, 2, 0});
                slog::emit_struct_checked<3>(head_rel[3], head_index[3], newbatch[3], std::array<u64,2>{v_c114, v_c115}, std::array<u16,3>{1, 2, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:194", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask724(db,b));
  // (crule (pre (let __tconst9zoW125 const7c7d2cfc66f4d976987d2d20) (let __tconst4V4L122 const6bc0ba365ada70df115e1785) (let __tconst82U8119 consta8180db1c2f300980314f910) (let __tconst4Zcr91 const9a67f28c6b77e842f439a84a) (let __tconst0vRf84 conste58dec6bca6f63ef79c3b755) (let __tconst4BKz104 const0f8748be649f8ee4066bb1d7) (let __tconst3wDH116 constd5f017533ea574d5f9b3400c) (let __tconst3ktF111 const990b444cbd47632035b2fa1a) (let __tconst5nWJ102 const4f84f41d89b6b717419b4eaa)) (seeded) (body (join ref (1 0) 1 __tconst4V4L122 __t7aew98) (exists lambda (1 2 0) 1 __tconst0vRf84) (exists ref (1 0) 1 __tconst4Zcr91) (exists ref (1 0) 1 __tconst9zoW125) (exists lambda (1 2 0) 1 __tconst4Zcr91) (exists ref (1 0) 1 __tconst4BKz104) (exists lambda (1 2 0) 1 __tconst4BKz104) (exists app (1 2 0) 1 __t7aew98) (exists ref (1 0) 1 __tconst3wDH116) (exists ref (1 0) 1 __tconst5nWJ102) (exists lambda (1 2 0) 1 __tconst5nWJ102) (exists ref (1 0) 1 __tconst3ktF111) (exists lambda (1 2 0) 1 __tconst3ktF111) (exists lambda (1 2 0) 1 __tconst3wDH116) (exists lambda (1 2 0) 1 __tconst82U8119) (join ref (1 0) 1 __tconst0vRf84 __t2duR83) (join lambda (1 2 0) 2 __tconst0vRf84 __t2duR83 __t87vL85) (join ref (1 0) 1 __tconst4Zcr91 __t0C9F87) (exists app (2 0 1) 1 __t0C9F87) (join ref (1 0) 1 __tconst9zoW125 __t3Q2G89) (join app (1 2 0) 2 __t3Q2G89 __t0C9F87 __t2Eqd90) (join lambda (1 2 0) 2 __tconst4Zcr91 __t2Eqd90 __t3pgm92) (join ref (1 0) 1 __tconst4BKz104 __t8C0a94) (join lambda (1 2 0) 2 __tconst4BKz104 __t8C0a94 __t4fDK96) (join app (1 2 0) 2 __t7aew98 __t4fDK96 __t7TEO99) (exists app (2 0 1) 1 __t7TEO99) (join ref (1 0) 1 __tconst3wDH116 __t3wir114) (exists app (1 2 0) 1 __t3wir114) (join ref (1 0) 1 __tconst5nWJ102 __t5MaG101) (join lambda (1 2 0) 2 __tconst5nWJ102 __t5MaG101 __t35jA103) (join lambda (1 2 0) 2 __tconst4BKz104 __t35jA103 __t6RuY105) (join app (1 2 0) 2 __t7aew98 __t6RuY105 __t2Z7m108) (exists app (2 0 1) 1 __t2Z7m108) (join ref (1 0) 1 __tconst3ktF111 __t7ohz110) (join lambda (1 2 0) 2 __tconst3ktF111 __t7ohz110 __t8GWA112) (join app (1 2 0) 2 __t3wir114 __t8GWA112 __t44OM115) (join lambda (1 2 0) 2 __tconst3wDH116 __t44OM115 __t7CwH117) (join app (1 2 0) 2 __t7CwH117 __t2Z7m108 __t50Kk118) (join lambda (1 2 0) 2 __tconst82U8119 __t50Kk118 __t3SEs120) (join app (1 2 0) 2 __t3SEs120 __t7TEO99 __t1GdP121)) (head (mkstruct lambda (1 2 0) __t5iMg123 __tconst4V4L122 __t1GdP121)) mcfa-counting.slog:241 #f)
  class ReadTask794 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex754;  slog::Index** lambdaindex755;  slog::Index** refindex756;  slog::Index** refindex757;  slog::Index** lambdaindex758;  slog::Index** refindex759;  slog::Index** lambdaindex760;  slog::Index** appindex761;  slog::Index** refindex762;  slog::Index** refindex763;  slog::Index** lambdaindex764;  slog::Index** refindex765;  slog::Index** lambdaindex766;  slog::Index** lambdaindex767;  slog::Index** lambdaindex768;  slog::Index** refindex769;  slog::Index** lambdaindex770;  slog::Index** refindex771;  slog::Index** appindex772;  slog::Index** refindex773;  slog::Index** appindex774;  slog::Index** lambdaindex775;  slog::Index** refindex776;  slog::Index** lambdaindex777;  slog::Index** appindex778;  slog::Index** appindex779;  slog::Index** refindex780;  slog::Index** appindex781;  slog::Index** refindex782;  slog::Index** lambdaindex783;  slog::Index** lambdaindex784;  slog::Index** appindex785;  slog::Index** appindex786;  slog::Index** refindex787;  slog::Index** lambdaindex788;  slog::Index** appindex789;  slog::Index** lambdaindex790;  slog::Index** appindex791;  slog::Index** lambdaindex792;  slog::Index** appindex793;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      std::vector<u16> ord795({1, 2, 0});
      slog::Relation* readrel796 = db->getRelation("lambda");
      head_index[0] = readrel796->getIndex(ord795, false);
      std::vector<u16> ord797({1, 0});
      slog::Relation* readrel798 = db->getRelation("ref");
      refindex754 = readrel798->getIndex(ord797, false);
      std::vector<u16> ord799({1, 2, 0});
      slog::Relation* readrel800 = db->getRelation("lambda");
      lambdaindex755 = readrel800->getIndex(ord799, false);
      std::vector<u16> ord801({1, 0});
      slog::Relation* readrel802 = db->getRelation("ref");
      refindex756 = readrel802->getIndex(ord801, false);
      std::vector<u16> ord803({1, 0});
      slog::Relation* readrel804 = db->getRelation("ref");
      refindex757 = readrel804->getIndex(ord803, false);
      std::vector<u16> ord805({1, 2, 0});
      slog::Relation* readrel806 = db->getRelation("lambda");
      lambdaindex758 = readrel806->getIndex(ord805, false);
      std::vector<u16> ord807({1, 0});
      slog::Relation* readrel808 = db->getRelation("ref");
      refindex759 = readrel808->getIndex(ord807, false);
      std::vector<u16> ord809({1, 2, 0});
      slog::Relation* readrel810 = db->getRelation("lambda");
      lambdaindex760 = readrel810->getIndex(ord809, false);
      std::vector<u16> ord811({1, 2, 0});
      slog::Relation* readrel812 = db->getRelation("app");
      appindex761 = readrel812->getIndex(ord811, false);
      std::vector<u16> ord813({1, 0});
      slog::Relation* readrel814 = db->getRelation("ref");
      refindex762 = readrel814->getIndex(ord813, false);
      std::vector<u16> ord815({1, 0});
      slog::Relation* readrel816 = db->getRelation("ref");
      refindex763 = readrel816->getIndex(ord815, false);
      std::vector<u16> ord817({1, 2, 0});
      slog::Relation* readrel818 = db->getRelation("lambda");
      lambdaindex764 = readrel818->getIndex(ord817, false);
      std::vector<u16> ord819({1, 0});
      slog::Relation* readrel820 = db->getRelation("ref");
      refindex765 = readrel820->getIndex(ord819, false);
      std::vector<u16> ord821({1, 2, 0});
      slog::Relation* readrel822 = db->getRelation("lambda");
      lambdaindex766 = readrel822->getIndex(ord821, false);
      std::vector<u16> ord823({1, 2, 0});
      slog::Relation* readrel824 = db->getRelation("lambda");
      lambdaindex767 = readrel824->getIndex(ord823, false);
      std::vector<u16> ord825({1, 2, 0});
      slog::Relation* readrel826 = db->getRelation("lambda");
      lambdaindex768 = readrel826->getIndex(ord825, false);
      std::vector<u16> ord827({1, 0});
      slog::Relation* readrel828 = db->getRelation("ref");
      refindex769 = readrel828->getIndex(ord827, false);
      std::vector<u16> ord829({1, 2, 0});
      slog::Relation* readrel830 = db->getRelation("lambda");
      lambdaindex770 = readrel830->getIndex(ord829, false);
      std::vector<u16> ord831({1, 0});
      slog::Relation* readrel832 = db->getRelation("ref");
      refindex771 = readrel832->getIndex(ord831, false);
      std::vector<u16> ord833({2, 0, 1});
      slog::Relation* readrel834 = db->getRelation("app");
      appindex772 = readrel834->getIndex(ord833, false);
      std::vector<u16> ord835({1, 0});
      slog::Relation* readrel836 = db->getRelation("ref");
      refindex773 = readrel836->getIndex(ord835, false);
      std::vector<u16> ord837({1, 2, 0});
      slog::Relation* readrel838 = db->getRelation("app");
      appindex774 = readrel838->getIndex(ord837, false);
      std::vector<u16> ord839({1, 2, 0});
      slog::Relation* readrel840 = db->getRelation("lambda");
      lambdaindex775 = readrel840->getIndex(ord839, false);
      std::vector<u16> ord841({1, 0});
      slog::Relation* readrel842 = db->getRelation("ref");
      refindex776 = readrel842->getIndex(ord841, false);
      std::vector<u16> ord843({1, 2, 0});
      slog::Relation* readrel844 = db->getRelation("lambda");
      lambdaindex777 = readrel844->getIndex(ord843, false);
      std::vector<u16> ord845({1, 2, 0});
      slog::Relation* readrel846 = db->getRelation("app");
      appindex778 = readrel846->getIndex(ord845, false);
      std::vector<u16> ord847({2, 0, 1});
      slog::Relation* readrel848 = db->getRelation("app");
      appindex779 = readrel848->getIndex(ord847, false);
      std::vector<u16> ord849({1, 0});
      slog::Relation* readrel850 = db->getRelation("ref");
      refindex780 = readrel850->getIndex(ord849, false);
      std::vector<u16> ord851({1, 2, 0});
      slog::Relation* readrel852 = db->getRelation("app");
      appindex781 = readrel852->getIndex(ord851, false);
      std::vector<u16> ord853({1, 0});
      slog::Relation* readrel854 = db->getRelation("ref");
      refindex782 = readrel854->getIndex(ord853, false);
      std::vector<u16> ord855({1, 2, 0});
      slog::Relation* readrel856 = db->getRelation("lambda");
      lambdaindex783 = readrel856->getIndex(ord855, false);
      std::vector<u16> ord857({1, 2, 0});
      slog::Relation* readrel858 = db->getRelation("lambda");
      lambdaindex784 = readrel858->getIndex(ord857, false);
      std::vector<u16> ord859({1, 2, 0});
      slog::Relation* readrel860 = db->getRelation("app");
      appindex785 = readrel860->getIndex(ord859, false);
      std::vector<u16> ord861({2, 0, 1});
      slog::Relation* readrel862 = db->getRelation("app");
      appindex786 = readrel862->getIndex(ord861, false);
      std::vector<u16> ord863({1, 0});
      slog::Relation* readrel864 = db->getRelation("ref");
      refindex787 = readrel864->getIndex(ord863, false);
      std::vector<u16> ord865({1, 2, 0});
      slog::Relation* readrel866 = db->getRelation("lambda");
      lambdaindex788 = readrel866->getIndex(ord865, false);
      std::vector<u16> ord867({1, 2, 0});
      slog::Relation* readrel868 = db->getRelation("app");
      appindex789 = readrel868->getIndex(ord867, false);
      std::vector<u16> ord869({1, 2, 0});
      slog::Relation* readrel870 = db->getRelation("lambda");
      lambdaindex790 = readrel870->getIndex(ord869, false);
      std::vector<u16> ord871({1, 2, 0});
      slog::Relation* readrel872 = db->getRelation("app");
      appindex791 = readrel872->getIndex(ord871, false);
      std::vector<u16> ord873({1, 2, 0});
      slog::Relation* readrel874 = db->getRelation("lambda");
      lambdaindex792 = readrel874->getIndex(ord873, false);
      std::vector<u16> ord875({1, 2, 0});
      slog::Relation* readrel876 = db->getRelation("app");
      appindex793 = readrel876->getIndex(ord875, false);
  
    }
    ReadTask794(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const7c7d2cfc66f4d976987d2d20;
      u64 v_c1 = v_const6bc0ba365ada70df115e1785;
      u64 v_c2 = v_consta8180db1c2f300980314f910;
      u64 v_c7 = v_const9a67f28c6b77e842f439a84a;
      u64 v_c8 = v_conste58dec6bca6f63ef79c3b755;
      u64 v_c5 = v_const0f8748be649f8ee4066bb1d7;
      u64 v_c3 = v_constd5f017533ea574d5f9b3400c;
      u64 v_c4 = v_const990b444cbd47632035b2fa1a;
      u64 v_c6 = v_const4f84f41d89b6b717419b4eaa;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex754, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m877) {
        u64 v_c13 = m877[1];
        if (!slog::exists_probe<3,1>(lambdaindex755, std::array<u64,3>{v_c8, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex756, std::array<u64,2>{v_c7, 0})) return;
        if (!slog::exists_probe<2,1>(refindex757, std::array<u64,2>{v_c0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex758, std::array<u64,3>{v_c7, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex759, std::array<u64,2>{v_c5, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex760, std::array<u64,3>{v_c5, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex761, std::array<u64,3>{v_c13, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex762, std::array<u64,2>{v_c3, 0})) return;
        if (!slog::exists_probe<2,1>(refindex763, std::array<u64,2>{v_c6, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex764, std::array<u64,3>{v_c6, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex765, std::array<u64,2>{v_c4, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex766, std::array<u64,3>{v_c4, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex767, std::array<u64,3>{v_c3, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex768, std::array<u64,3>{v_c2, 0, 0})) return;
        slog::join_probe<2,1>(refindex769, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m878) {
          u64 v_c9 = m878[1];
          slog::join_probe<3,2>(lambdaindex770, std::array<u64,3>{v_c8, v_c9, 0}, [&](const std::array<u64,3>& m879) {
            u64 v_c98 = m879[2];
            slog::join_probe<2,1>(refindex771, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m880) {
              u64 v_c10 = m880[1];
              if (!slog::exists_probe<3,1>(appindex772, std::array<u64,3>{v_c10, 0, 0})) return;
              slog::join_probe<2,1>(refindex773, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m881) {
                u64 v_c11 = m881[1];
                slog::join_probe<3,2>(appindex774, std::array<u64,3>{v_c11, v_c10, 0}, [&](const std::array<u64,3>& m882) {
                  u64 v_c96 = m882[2];
                  slog::join_probe<3,2>(lambdaindex775, std::array<u64,3>{v_c7, v_c96, 0}, [&](const std::array<u64,3>& m883) {
                    u64 v_c97 = m883[2];
                    slog::join_probe<2,1>(refindex776, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m884) {
                      u64 v_c12 = m884[1];
                      slog::join_probe<3,2>(lambdaindex777, std::array<u64,3>{v_c5, v_c12, 0}, [&](const std::array<u64,3>& m885) {
                        u64 v_c99 = m885[2];
                        slog::join_probe<3,2>(appindex778, std::array<u64,3>{v_c13, v_c99, 0}, [&](const std::array<u64,3>& m886) {
                          u64 v_c100 = m886[2];
                          if (!slog::exists_probe<3,1>(appindex779, std::array<u64,3>{v_c100, 0, 0})) return;
                          slog::join_probe<2,1>(refindex780, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m887) {
                            u64 v_c16 = m887[1];
                            if (!slog::exists_probe<3,1>(appindex781, std::array<u64,3>{v_c16, 0, 0})) return;
                            slog::join_probe<2,1>(refindex782, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m888) {
                              u64 v_c14 = m888[1];
                              slog::join_probe<3,2>(lambdaindex783, std::array<u64,3>{v_c6, v_c14, 0}, [&](const std::array<u64,3>& m889) {
                                u64 v_c101 = m889[2];
                                slog::join_probe<3,2>(lambdaindex784, std::array<u64,3>{v_c5, v_c101, 0}, [&](const std::array<u64,3>& m890) {
                                  u64 v_c102 = m890[2];
                                  slog::join_probe<3,2>(appindex785, std::array<u64,3>{v_c13, v_c102, 0}, [&](const std::array<u64,3>& m891) {
                                    u64 v_c120 = m891[2];
                                    if (!slog::exists_probe<3,1>(appindex786, std::array<u64,3>{v_c120, 0, 0})) return;
                                    slog::join_probe<2,1>(refindex787, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m892) {
                                      u64 v_c15 = m892[1];
                                      slog::join_probe<3,2>(lambdaindex788, std::array<u64,3>{v_c4, v_c15, 0}, [&](const std::array<u64,3>& m893) {
                                        u64 v_c103 = m893[2];
                                        slog::join_probe<3,2>(appindex789, std::array<u64,3>{v_c16, v_c103, 0}, [&](const std::array<u64,3>& m894) {
                                          u64 v_c104 = m894[2];
                                          slog::join_probe<3,2>(lambdaindex790, std::array<u64,3>{v_c3, v_c104, 0}, [&](const std::array<u64,3>& m895) {
                                            u64 v_c121 = m895[2];
                                            slog::join_probe<3,2>(appindex791, std::array<u64,3>{v_c121, v_c120, 0}, [&](const std::array<u64,3>& m896) {
                                              u64 v_c122 = m896[2];
                                              slog::join_probe<3,2>(lambdaindex792, std::array<u64,3>{v_c2, v_c122, 0}, [&](const std::array<u64,3>& m897) {
                                                u64 v_c123 = m897[2];
                                                slog::join_probe<3,2>(appindex793, std::array<u64,3>{v_c123, v_c100, 0}, [&](const std::array<u64,3>& m898) {
                                                  u64 v_c124 = m898[2];
                                                  ++_fires;
                                                  slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c1, v_c124}, std::array<u16,3>{1, 2, 0});
                                                });
                                              });
                                            });
                                          });
                                        });
                                      });
                                    });
                                  });
                                });
                              });
                            });
                          });
                        });
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
      s->addTaskSeeded(phase_read, new ReadTask794(db,b));
  // (crule (pre) (scan eval __3rQu352 __t9WN8163 c) (body (join-old app (0 1 2) 1 (0 1 2) __t9WN8163 ef ea)) (head (mkstruct eval (1 2 0) __4G7Z353 ef c)) mcfa-counting.slog:92 #f)
  class ReadTask901 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex899;  slog::Index** appdelta900;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord902({0, 1, 2});
      slog::Relation* readrel903 = db->getRelation("app");
      appindex899 = readrel903->getIndex(ord902, false);
      std::vector<u16> ord904({0, 1, 2});
      slog::Relation* readrel905 = db->getRelation("app");
      appdelta900 = readrel905->getIndex(ord904, true);
  
    }
    ReadTask901(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c126 = _t[1];
        u64 v_c45 = _t[2];
        slog::join_probe_old<3,1>(appindex899, appdelta900, std::array<u64,3>{v_c126, 0, 0}, [&](const std::array<u64,3>& m906) {
          u64 v_c47 = m906[1]; u64 v_c44 = m906[2];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c47, v_c45}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:92", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask901* _cont = new ReadTask901(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask901(db,b), false);
  // (crule (pre (let __tconst0zC2144 const4e3b5454cf93e32fad90650d) (let __tconst3Taj142 constdc1bb6655fb38bdb032e3754) (let __tconst8xRt151 const3a82152bd1402931076fe2d7) (let __tconst8eg8132 const361d5df359e0d7681220d09d)) (seeded) (body (join ref (1 0) 1 __tconst8eg8132 __t19JM131) (exists ref (1 0) 1 __tconst3Taj142) (exists ref (1 0) 1 __tconst8xRt151) (exists ref (1 0) 1 __tconst0zC2144) (exists lambda (1 2 0) 1 __tconst8xRt151) (exists lambda (1 2 0) 1 __tconst3Taj142) (exists lambda (1 2 0) 1 __tconst0zC2144) (join lambda (1 2 0) 2 __tconst8eg8132 __t19JM131 __t4DXA133) (join ref (1 0) 1 __tconst3Taj142 __t93Xi135) (exists app (2 0 1) 1 __t93Xi135) (join ref (1 0) 1 __tconst8xRt151 __t1g2P147) (exists app (1 2 0) 1 __t1g2P147) (join ref (1 0) 1 __tconst0zC2144 __t7VSc137) (exists app (1 2 0) 1 __t7VSc137) (join app (1 2 0) 1 __t1g2P147 dup9wpU405 __t9UZN150) (eq __t1g2P147 dup9wpU405) (join lambda (1 2 0) 2 __tconst8xRt151 __t9UZN150 __t2nYy152) (join app (1 2 0) 1 __t7VSc137 dup8pyK406 __t8dYW140) (eq __t7VSc137 dup8pyK406) (join app (1 2 0) 2 __t8dYW140 __t93Xi135 __t25NQ141) (join lambda (1 2 0) 2 __tconst3Taj142 __t25NQ141 __t2Ce3143) (join lambda (1 2 0) 2 __tconst0zC2144 __t2Ce3143 __t6t5O145)) (head (mkstruct app (1 2 0) __t6Ups153 __t2nYy152 __t6t5O145)) mcfa-counting.slog:224 #f)
  class ReadTask927 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex907;  slog::Index** refindex908;  slog::Index** refindex909;  slog::Index** refindex910;  slog::Index** lambdaindex911;  slog::Index** lambdaindex912;  slog::Index** lambdaindex913;  slog::Index** lambdaindex914;  slog::Index** refindex915;  slog::Index** appindex916;  slog::Index** refindex917;  slog::Index** appindex918;  slog::Index** refindex919;  slog::Index** appindex920;  slog::Index** appindex921;  slog::Index** lambdaindex922;  slog::Index** appindex923;  slog::Index** appindex924;  slog::Index** lambdaindex925;  slog::Index** lambdaindex926;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord928({1, 2, 0});
      slog::Relation* readrel929 = db->getRelation("app");
      head_index[0] = readrel929->getIndex(ord928, false);
      std::vector<u16> ord930({1, 0});
      slog::Relation* readrel931 = db->getRelation("ref");
      refindex907 = readrel931->getIndex(ord930, false);
      std::vector<u16> ord932({1, 0});
      slog::Relation* readrel933 = db->getRelation("ref");
      refindex908 = readrel933->getIndex(ord932, false);
      std::vector<u16> ord934({1, 0});
      slog::Relation* readrel935 = db->getRelation("ref");
      refindex909 = readrel935->getIndex(ord934, false);
      std::vector<u16> ord936({1, 0});
      slog::Relation* readrel937 = db->getRelation("ref");
      refindex910 = readrel937->getIndex(ord936, false);
      std::vector<u16> ord938({1, 2, 0});
      slog::Relation* readrel939 = db->getRelation("lambda");
      lambdaindex911 = readrel939->getIndex(ord938, false);
      std::vector<u16> ord940({1, 2, 0});
      slog::Relation* readrel941 = db->getRelation("lambda");
      lambdaindex912 = readrel941->getIndex(ord940, false);
      std::vector<u16> ord942({1, 2, 0});
      slog::Relation* readrel943 = db->getRelation("lambda");
      lambdaindex913 = readrel943->getIndex(ord942, false);
      std::vector<u16> ord944({1, 2, 0});
      slog::Relation* readrel945 = db->getRelation("lambda");
      lambdaindex914 = readrel945->getIndex(ord944, false);
      std::vector<u16> ord946({1, 0});
      slog::Relation* readrel947 = db->getRelation("ref");
      refindex915 = readrel947->getIndex(ord946, false);
      std::vector<u16> ord948({2, 0, 1});
      slog::Relation* readrel949 = db->getRelation("app");
      appindex916 = readrel949->getIndex(ord948, false);
      std::vector<u16> ord950({1, 0});
      slog::Relation* readrel951 = db->getRelation("ref");
      refindex917 = readrel951->getIndex(ord950, false);
      std::vector<u16> ord952({1, 2, 0});
      slog::Relation* readrel953 = db->getRelation("app");
      appindex918 = readrel953->getIndex(ord952, false);
      std::vector<u16> ord954({1, 0});
      slog::Relation* readrel955 = db->getRelation("ref");
      refindex919 = readrel955->getIndex(ord954, false);
      std::vector<u16> ord956({1, 2, 0});
      slog::Relation* readrel957 = db->getRelation("app");
      appindex920 = readrel957->getIndex(ord956, false);
      std::vector<u16> ord958({1, 2, 0});
      slog::Relation* readrel959 = db->getRelation("app");
      appindex921 = readrel959->getIndex(ord958, false);
      std::vector<u16> ord960({1, 2, 0});
      slog::Relation* readrel961 = db->getRelation("lambda");
      lambdaindex922 = readrel961->getIndex(ord960, false);
      std::vector<u16> ord962({1, 2, 0});
      slog::Relation* readrel963 = db->getRelation("app");
      appindex923 = readrel963->getIndex(ord962, false);
      std::vector<u16> ord964({1, 2, 0});
      slog::Relation* readrel965 = db->getRelation("app");
      appindex924 = readrel965->getIndex(ord964, false);
      std::vector<u16> ord966({1, 2, 0});
      slog::Relation* readrel967 = db->getRelation("lambda");
      lambdaindex925 = readrel967->getIndex(ord966, false);
      std::vector<u16> ord968({1, 2, 0});
      slog::Relation* readrel969 = db->getRelation("lambda");
      lambdaindex926 = readrel969->getIndex(ord968, false);
  
    }
    ReadTask927(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c31 = v_const4e3b5454cf93e32fad90650d;
      u64 v_c32 = v_constdc1bb6655fb38bdb032e3754;
      u64 v_c30 = v_const3a82152bd1402931076fe2d7;
      u64 v_c33 = v_const361d5df359e0d7681220d09d;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex907, std::array<u64,2>{v_c33, 0}, [&](const std::array<u64,2>& m970) {
        u64 v_c34 = m970[1];
        if (!slog::exists_probe<2,1>(refindex908, std::array<u64,2>{v_c32, 0})) return;
        if (!slog::exists_probe<2,1>(refindex909, std::array<u64,2>{v_c30, 0})) return;
        if (!slog::exists_probe<2,1>(refindex910, std::array<u64,2>{v_c31, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex911, std::array<u64,3>{v_c30, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex912, std::array<u64,3>{v_c32, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex913, std::array<u64,3>{v_c31, 0, 0})) return;
        slog::join_probe<3,2>(lambdaindex914, std::array<u64,3>{v_c33, v_c34, 0}, [&](const std::array<u64,3>& m971) {
          u64 v_c35 = m971[2];
          slog::join_probe<2,1>(refindex915, std::array<u64,2>{v_c32, 0}, [&](const std::array<u64,2>& m972) {
            u64 v_c36 = m972[1];
            if (!slog::exists_probe<3,1>(appindex916, std::array<u64,3>{v_c36, 0, 0})) return;
            slog::join_probe<2,1>(refindex917, std::array<u64,2>{v_c30, 0}, [&](const std::array<u64,2>& m973) {
              u64 v_c38 = m973[1];
              if (!slog::exists_probe<3,1>(appindex918, std::array<u64,3>{v_c38, 0, 0})) return;
              slog::join_probe<2,1>(refindex919, std::array<u64,2>{v_c31, 0}, [&](const std::array<u64,2>& m974) {
                u64 v_c37 = m974[1];
                if (!slog::exists_probe<3,1>(appindex920, std::array<u64,3>{v_c37, 0, 0})) return;
                slog::join_probe<3,1>(appindex921, std::array<u64,3>{v_c38, 0, 0}, [&](const std::array<u64,3>& m975) {
                  u64 v_c127 = m975[1]; u64 v_c42 = m975[2];
                  if (v_c38 != v_c127) return;
                  slog::join_probe<3,2>(lambdaindex922, std::array<u64,3>{v_c30, v_c42, 0}, [&](const std::array<u64,3>& m976) {
                    u64 v_c128 = m976[2];
                    slog::join_probe<3,1>(appindex923, std::array<u64,3>{v_c37, 0, 0}, [&](const std::array<u64,3>& m977) {
                      u64 v_c129 = m977[1]; u64 v_c40 = m977[2];
                      if (v_c37 != v_c129) return;
                      slog::join_probe<3,2>(appindex924, std::array<u64,3>{v_c40, v_c36, 0}, [&](const std::array<u64,3>& m978) {
                        u64 v_c130 = m978[2];
                        slog::join_probe<3,2>(lambdaindex925, std::array<u64,3>{v_c32, v_c130, 0}, [&](const std::array<u64,3>& m979) {
                          u64 v_c131 = m979[2];
                          slog::join_probe<3,2>(lambdaindex926, std::array<u64,3>{v_c31, v_c131, 0}, [&](const std::array<u64,3>& m980) {
                            u64 v_c132 = m980[2];
                            ++_fires;
                            slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c128, v_c132}, std::array<u16,3>{1, 2, 0});
                          });
                        });
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
      s->addTaskSeeded(phase_read, new ReadTask927(db,b));
  // (crule (pre (let __tconst4Xaz41 const81cb39a72a584ab4f703b7f7) (let __tconst1aIN38 const4d5ce1398140fbe27561181f) (let __tconst4xzG22 constdbf1bdba02122b2adce28528) (let __tconst37GM26 const85f09fa1913b9daf65957cf7) (let __tconst1ha033 const969c6e56242ce8d0a4346602) (let __tconst1HMF17 constd7a1925d249b4768c8a9f2d8)) (scan app __t7P7240 __t3aRV39 __t2Vg230) (body (exists ref (1 0) 1 __tconst4Xaz41) (exists lambda (1 2 0) 1 __tconst37GM26) (exists ref (1 0) 1 __tconst37GM26) (exists lambda (1 2 0) 1 __tconst1ha033) (exists ref (1 0) 1 __tconst1ha033) (exists ref (1 0) 1 __tconst4xzG22) (exists ref (1 0) 1 __tconst1HMF17) (exists lambda (1 2 0) 1 __tconst1HMF17) (exists lambda (1 2 0) 1 __tconst4xzG22) (join lambda (0 1 2) 2 __t3aRV39 __tconst1aIN38 __t3pMW37) (join ref (1 0) 1 __tconst4Xaz41 __t75SZ29) (exists app (0 1 2) 2 __t3pMW37 __t75SZ29) (join app (0 1 2) 2 __t2Vg230 __t75SZ29 __t5myE27) (join lambda (0 1 2) 2 __t5myE27 __tconst37GM26 __t7U1m25) (join ref (0 1) 2 __t7U1m25 __tconst37GM26) (join app (0 1 2) 2 __t3pMW37 __t75SZ29 __t065j34) (join lambda (0 1 2) 2 __t065j34 __tconst1ha033 __t7N9A32) (join ref (0 1) 2 __t7N9A32 __tconst1ha033) (join ref (1 0) 1 __tconst4xzG22 __t2DOE20) (exists app (1 2 0) 1 __t2DOE20) (join ref (1 0) 1 __tconst1HMF17 __t7H1u16) (join lambda (1 2 0) 2 __tconst1HMF17 __t7H1u16 __t2wNc18) (join app (1 2 0) 2 __t2DOE20 __t2wNc18 __t3b2k21) (join lambda (1 2 0) 2 __tconst4xzG22 __t3b2k21 __t8Ovw23)) (head (mkstruct lambda (1 2 0) __t79we42 __tconst4Xaz41 __t7P7240)) mcfa-counting.slog:260 #f)
  class ReadTask1005 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex981;  slog::Index** lambdaindex982;  slog::Index** refindex983;  slog::Index** lambdaindex984;  slog::Index** refindex985;  slog::Index** refindex986;  slog::Index** refindex987;  slog::Index** lambdaindex988;  slog::Index** lambdaindex989;  slog::Index** lambdaindex990;  slog::Index** refindex991;  slog::Index** appindex992;  slog::Index** appindex993;  slog::Index** lambdaindex994;  slog::Index** refindex995;  slog::Index** appindex996;  slog::Index** lambdaindex997;  slog::Index** refindex998;  slog::Index** refindex999;  slog::Index** appindex1000;  slog::Index** refindex1001;  slog::Index** lambdaindex1002;  slog::Index** appindex1003;  slog::Index** lambdaindex1004;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      outer_rel = db->getRelation("app");
      std::vector<u16> ord1006({1, 0});
      slog::Relation* readrel1007 = db->getRelation("ref");
      refindex981 = readrel1007->getIndex(ord1006, false);
      std::vector<u16> ord1008({1, 2, 0});
      slog::Relation* readrel1009 = db->getRelation("lambda");
      lambdaindex982 = readrel1009->getIndex(ord1008, false);
      std::vector<u16> ord1010({1, 0});
      slog::Relation* readrel1011 = db->getRelation("ref");
      refindex983 = readrel1011->getIndex(ord1010, false);
      std::vector<u16> ord1012({1, 2, 0});
      slog::Relation* readrel1013 = db->getRelation("lambda");
      lambdaindex984 = readrel1013->getIndex(ord1012, false);
      std::vector<u16> ord1014({1, 0});
      slog::Relation* readrel1015 = db->getRelation("ref");
      refindex985 = readrel1015->getIndex(ord1014, false);
      std::vector<u16> ord1016({1, 0});
      slog::Relation* readrel1017 = db->getRelation("ref");
      refindex986 = readrel1017->getIndex(ord1016, false);
      std::vector<u16> ord1018({1, 0});
      slog::Relation* readrel1019 = db->getRelation("ref");
      refindex987 = readrel1019->getIndex(ord1018, false);
      std::vector<u16> ord1020({1, 2, 0});
      slog::Relation* readrel1021 = db->getRelation("lambda");
      lambdaindex988 = readrel1021->getIndex(ord1020, false);
      std::vector<u16> ord1022({1, 2, 0});
      slog::Relation* readrel1023 = db->getRelation("lambda");
      lambdaindex989 = readrel1023->getIndex(ord1022, false);
      std::vector<u16> ord1024({0, 1, 2});
      slog::Relation* readrel1025 = db->getRelation("lambda");
      lambdaindex990 = readrel1025->getIndex(ord1024, false);
      std::vector<u16> ord1026({1, 0});
      slog::Relation* readrel1027 = db->getRelation("ref");
      refindex991 = readrel1027->getIndex(ord1026, false);
      std::vector<u16> ord1028({0, 1, 2});
      slog::Relation* readrel1029 = db->getRelation("app");
      appindex992 = readrel1029->getIndex(ord1028, false);
      std::vector<u16> ord1030({0, 1, 2});
      slog::Relation* readrel1031 = db->getRelation("app");
      appindex993 = readrel1031->getIndex(ord1030, false);
      std::vector<u16> ord1032({0, 1, 2});
      slog::Relation* readrel1033 = db->getRelation("lambda");
      lambdaindex994 = readrel1033->getIndex(ord1032, false);
      std::vector<u16> ord1034({0, 1});
      slog::Relation* readrel1035 = db->getRelation("ref");
      refindex995 = readrel1035->getIndex(ord1034, false);
      std::vector<u16> ord1036({0, 1, 2});
      slog::Relation* readrel1037 = db->getRelation("app");
      appindex996 = readrel1037->getIndex(ord1036, false);
      std::vector<u16> ord1038({0, 1, 2});
      slog::Relation* readrel1039 = db->getRelation("lambda");
      lambdaindex997 = readrel1039->getIndex(ord1038, false);
      std::vector<u16> ord1040({0, 1});
      slog::Relation* readrel1041 = db->getRelation("ref");
      refindex998 = readrel1041->getIndex(ord1040, false);
      std::vector<u16> ord1042({1, 0});
      slog::Relation* readrel1043 = db->getRelation("ref");
      refindex999 = readrel1043->getIndex(ord1042, false);
      std::vector<u16> ord1044({1, 2, 0});
      slog::Relation* readrel1045 = db->getRelation("app");
      appindex1000 = readrel1045->getIndex(ord1044, false);
      std::vector<u16> ord1046({1, 0});
      slog::Relation* readrel1047 = db->getRelation("ref");
      refindex1001 = readrel1047->getIndex(ord1046, false);
      std::vector<u16> ord1048({1, 2, 0});
      slog::Relation* readrel1049 = db->getRelation("lambda");
      lambdaindex1002 = readrel1049->getIndex(ord1048, false);
      std::vector<u16> ord1050({1, 2, 0});
      slog::Relation* readrel1051 = db->getRelation("app");
      appindex1003 = readrel1051->getIndex(ord1050, false);
      std::vector<u16> ord1052({1, 2, 0});
      slog::Relation* readrel1053 = db->getRelation("lambda");
      lambdaindex1004 = readrel1053->getIndex(ord1052, false);
  
    }
    ReadTask1005(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c133 = v_const81cb39a72a584ab4f703b7f7;
      u64 v_c134 = v_const4d5ce1398140fbe27561181f;
      u64 v_c135 = v_constdbf1bdba02122b2adce28528;
      u64 v_c136 = v_const85f09fa1913b9daf65957cf7;
      u64 v_c137 = v_const969c6e56242ce8d0a4346602;
      u64 v_c138 = v_constd7a1925d249b4768c8a9f2d8;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c139 = _t[0];
        u64 v_c140 = _t[1];
        u64 v_c141 = _t[2];
        if (!slog::exists_probe<2,1>(refindex981, std::array<u64,2>{v_c133, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex982, std::array<u64,3>{v_c136, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex983, std::array<u64,2>{v_c136, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex984, std::array<u64,3>{v_c137, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex985, std::array<u64,2>{v_c137, 0})) return;
        if (!slog::exists_probe<2,1>(refindex986, std::array<u64,2>{v_c135, 0})) return;
        if (!slog::exists_probe<2,1>(refindex987, std::array<u64,2>{v_c138, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex988, std::array<u64,3>{v_c138, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex989, std::array<u64,3>{v_c135, 0, 0})) return;
        slog::join_probe<3,2>(lambdaindex990, std::array<u64,3>{v_c140, v_c134, 0}, [&](const std::array<u64,3>& m1054) {
          u64 v_c142 = m1054[2];
          slog::join_probe<2,1>(refindex991, std::array<u64,2>{v_c133, 0}, [&](const std::array<u64,2>& m1055) {
            u64 v_c143 = m1055[1];
            if (!slog::exists_probe<3,2>(appindex992, std::array<u64,3>{v_c142, v_c143, 0})) return;
            slog::join_probe<3,2>(appindex993, std::array<u64,3>{v_c141, v_c143, 0}, [&](const std::array<u64,3>& m1056) {
              u64 v_c144 = m1056[2];
              slog::join_probe<3,2>(lambdaindex994, std::array<u64,3>{v_c144, v_c136, 0}, [&](const std::array<u64,3>& m1057) {
                u64 v_c145 = m1057[2];
                slog::join_probe<2,2>(refindex995, std::array<u64,2>{v_c145, v_c136}, [&](const std::array<u64,2>& m1058) {
                  slog::join_probe<3,2>(appindex996, std::array<u64,3>{v_c142, v_c143, 0}, [&](const std::array<u64,3>& m1059) {
                    u64 v_c146 = m1059[2];
                    slog::join_probe<3,2>(lambdaindex997, std::array<u64,3>{v_c146, v_c137, 0}, [&](const std::array<u64,3>& m1060) {
                      u64 v_c147 = m1060[2];
                      slog::join_probe<2,2>(refindex998, std::array<u64,2>{v_c147, v_c137}, [&](const std::array<u64,2>& m1061) {
                        slog::join_probe<2,1>(refindex999, std::array<u64,2>{v_c135, 0}, [&](const std::array<u64,2>& m1062) {
                          u64 v_c148 = m1062[1];
                          if (!slog::exists_probe<3,1>(appindex1000, std::array<u64,3>{v_c148, 0, 0})) return;
                          slog::join_probe<2,1>(refindex1001, std::array<u64,2>{v_c138, 0}, [&](const std::array<u64,2>& m1063) {
                            u64 v_c149 = m1063[1];
                            slog::join_probe<3,2>(lambdaindex1002, std::array<u64,3>{v_c138, v_c149, 0}, [&](const std::array<u64,3>& m1064) {
                              u64 v_c150 = m1064[2];
                              slog::join_probe<3,2>(appindex1003, std::array<u64,3>{v_c148, v_c150, 0}, [&](const std::array<u64,3>& m1065) {
                                u64 v_c151 = m1065[2];
                                slog::join_probe<3,2>(lambdaindex1004, std::array<u64,3>{v_c135, v_c151, 0}, [&](const std::array<u64,3>& m1066) {
                                  u64 v_c152 = m1066[2];
                                  ++_fires;
                                  slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c133, v_c139}, std::array<u16,3>{1, 2, 0});
                                });
                              });
                            });
                          });
                        });
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
        ReadTask1005* _cont = new ReadTask1005(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1005(db,b), false);
  // (crule (pre) (scan app __t9WN8163 ef ea) (body (join eval (1 2 0) 1 __t9WN8163 c __3rQu352)) (head (mkstruct eval (1 2 0) __4G7Z353 ef c)) mcfa-counting.slog:92 #f)
  class ReadTask1068 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex1067;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("app");
      std::vector<u16> ord1069({1, 2, 0});
      slog::Relation* readrel1070 = db->getRelation("eval");
      evalindex1067 = readrel1070->getIndex(ord1069, false);
  
    }
    ReadTask1068(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c126 = _t[0];
        u64 v_c47 = _t[1];
        u64 v_c44 = _t[2];
        slog::join_probe<3,1>(evalindex1067, std::array<u64,3>{v_c126, 0, 0}, [&](const std::array<u64,3>& m1071) {
          u64 v_c45 = m1071[1]; u64 v_c125 = m1071[2];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c47, v_c45}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:92", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask1068* _cont = new ReadTask1068(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1068(db,b), false);
  // (crule (pre (let __tconst8xRt151 const3a82152bd1402931076fe2d7) (let __tconst0zC2144 const4e3b5454cf93e32fad90650d) (let __tconst3Taj142 constdc1bb6655fb38bdb032e3754) (let __tconst8eg8132 const361d5df359e0d7681220d09d)) (seeded) (body (join ref (1 0) 1 __tconst8eg8132 __t19JM131) (exists ref (1 0) 1 __tconst0zC2144) (exists ref (1 0) 1 __tconst8xRt151) (join ref (1 0) 1 __tconst3Taj142 __t93Xi135) (join ref (1 0) 1 __tconst0zC2144 __t7VSc137) (join ref (1 0) 1 __tconst8xRt151 __t1g2P147)) (head (mkstruct app (1 2 0) __t9UZN150 __t1g2P147 __t1g2P147) (mkstruct app (1 2 0) __t8dYW140 __t7VSc137 __t7VSc137) (mkstruct lambda (1 2 0) __t4DXA133 __tconst8eg8132 __t19JM131)) mcfa-counting.slog:224 #f)
  class ReadTask1078 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
  
  
  
  
  
  
    slog::Index** refindex1072;  slog::Index** refindex1073;  slog::Index** refindex1074;  slog::Index** refindex1075;  slog::Index** refindex1076;  slog::Index** refindex1077;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord1079({1, 2, 0});
      slog::Relation* readrel1080 = db->getRelation("app");
      head_index[0] = readrel1080->getIndex(ord1079, false);
      head_rel[1] = db->getRelation("app");
      std::vector<u16> ord1081({1, 2, 0});
      slog::Relation* readrel1082 = db->getRelation("app");
      head_index[1] = readrel1082->getIndex(ord1081, false);
      head_rel[2] = db->getRelation("lambda");
      std::vector<u16> ord1083({1, 2, 0});
      slog::Relation* readrel1084 = db->getRelation("lambda");
      head_index[2] = readrel1084->getIndex(ord1083, false);
      std::vector<u16> ord1085({1, 0});
      slog::Relation* readrel1086 = db->getRelation("ref");
      refindex1072 = readrel1086->getIndex(ord1085, false);
      std::vector<u16> ord1087({1, 0});
      slog::Relation* readrel1088 = db->getRelation("ref");
      refindex1073 = readrel1088->getIndex(ord1087, false);
      std::vector<u16> ord1089({1, 0});
      slog::Relation* readrel1090 = db->getRelation("ref");
      refindex1074 = readrel1090->getIndex(ord1089, false);
      std::vector<u16> ord1091({1, 0});
      slog::Relation* readrel1092 = db->getRelation("ref");
      refindex1075 = readrel1092->getIndex(ord1091, false);
      std::vector<u16> ord1093({1, 0});
      slog::Relation* readrel1094 = db->getRelation("ref");
      refindex1076 = readrel1094->getIndex(ord1093, false);
      std::vector<u16> ord1095({1, 0});
      slog::Relation* readrel1096 = db->getRelation("ref");
      refindex1077 = readrel1096->getIndex(ord1095, false);
  
    }
    ReadTask1078(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c30 = v_const3a82152bd1402931076fe2d7;
      u64 v_c31 = v_const4e3b5454cf93e32fad90650d;
      u64 v_c32 = v_constdc1bb6655fb38bdb032e3754;
      u64 v_c33 = v_const361d5df359e0d7681220d09d;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex1072, std::array<u64,2>{v_c33, 0}, [&](const std::array<u64,2>& m1097) {
        u64 v_c34 = m1097[1];
        if (!slog::exists_probe<2,1>(refindex1073, std::array<u64,2>{v_c31, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1074, std::array<u64,2>{v_c30, 0})) return;
        slog::join_probe<2,1>(refindex1075, std::array<u64,2>{v_c32, 0}, [&](const std::array<u64,2>& m1098) {
          u64 v_c36 = m1098[1];
          slog::join_probe<2,1>(refindex1076, std::array<u64,2>{v_c31, 0}, [&](const std::array<u64,2>& m1099) {
            u64 v_c37 = m1099[1];
            slog::join_probe<2,1>(refindex1077, std::array<u64,2>{v_c30, 0}, [&](const std::array<u64,2>& m1100) {
              u64 v_c38 = m1100[1];
              ++_fires;
              slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c38, v_c38}, std::array<u16,3>{1, 2, 0});
              slog::emit_struct_checked<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c37, v_c37}, std::array<u16,3>{1, 2, 0});
              slog::emit_struct_checked<3>(head_rel[2], head_index[2], newbatch[2], std::array<u64,2>{v_c33, v_c34}, std::array<u16,3>{1, 2, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:224", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask1078(db,b));
  // (crule (pre (let __tconst0ZcM213 constfc9ee54e0ee8c6d1e715716c) (let __tconst5Fqn220 const15bb62b8293a526ca6f0e4eb) (let __tconst9TQS210 const5950e3cb761734f52a881545) (let __tconst1wsq203 const77ceb5c0e9f84ebd84104a97)) (scan app __t4jAx212 __t1wmd211 __t118D204) (body (exists ref (1 0) 1 __tconst1wsq203) (exists lambda (0 1 2) 2 __t1wmd211 __tconst9TQS210) (exists ref (1 0) 1 __tconst0ZcM213) (exists ref (1 0) 1 __tconst5Fqn220) (exists lambda (1 2 0) 1 __tconst5Fqn220) (join lambda (0 1 2) 2 __t118D204 __tconst1wsq203 __t6pkv202) (join ref (0 1) 2 __t6pkv202 __tconst1wsq203) (join lambda (0 1 2) 2 __t1wmd211 __tconst9TQS210 __t1W86209) (join ref (1 0) 1 __tconst0ZcM213 __t6fYg206) (join app (0 1 2) 2 __t1W86209 __t6fYg206 dup8Ef9425) (eq __t6fYg206 dup8Ef9425) (join ref (1 0) 1 __tconst5Fqn220 __t2V0C216) (join app (1 2 0) 1 __t2V0C216 dup843z426 __t9nSF219) (eq __t2V0C216 dup843z426) (join lambda (1 2 0) 2 __tconst5Fqn220 __t9nSF219 __t6h87221)) (head (mkstruct lambda (1 2 0) __t14ld214 __tconst0ZcM213 __t4jAx212)) mcfa-counting.slog:211 #f)
  class ReadTask1114 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex1101;  slog::Index** lambdaindex1102;  slog::Index** refindex1103;  slog::Index** refindex1104;  slog::Index** lambdaindex1105;  slog::Index** lambdaindex1106;  slog::Index** refindex1107;  slog::Index** lambdaindex1108;  slog::Index** refindex1109;  slog::Index** appindex1110;  slog::Index** refindex1111;  slog::Index** appindex1112;  slog::Index** lambdaindex1113;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      outer_rel = db->getRelation("app");
      std::vector<u16> ord1115({1, 0});
      slog::Relation* readrel1116 = db->getRelation("ref");
      refindex1101 = readrel1116->getIndex(ord1115, false);
      std::vector<u16> ord1117({0, 1, 2});
      slog::Relation* readrel1118 = db->getRelation("lambda");
      lambdaindex1102 = readrel1118->getIndex(ord1117, false);
      std::vector<u16> ord1119({1, 0});
      slog::Relation* readrel1120 = db->getRelation("ref");
      refindex1103 = readrel1120->getIndex(ord1119, false);
      std::vector<u16> ord1121({1, 0});
      slog::Relation* readrel1122 = db->getRelation("ref");
      refindex1104 = readrel1122->getIndex(ord1121, false);
      std::vector<u16> ord1123({1, 2, 0});
      slog::Relation* readrel1124 = db->getRelation("lambda");
      lambdaindex1105 = readrel1124->getIndex(ord1123, false);
      std::vector<u16> ord1125({0, 1, 2});
      slog::Relation* readrel1126 = db->getRelation("lambda");
      lambdaindex1106 = readrel1126->getIndex(ord1125, false);
      std::vector<u16> ord1127({0, 1});
      slog::Relation* readrel1128 = db->getRelation("ref");
      refindex1107 = readrel1128->getIndex(ord1127, false);
      std::vector<u16> ord1129({0, 1, 2});
      slog::Relation* readrel1130 = db->getRelation("lambda");
      lambdaindex1108 = readrel1130->getIndex(ord1129, false);
      std::vector<u16> ord1131({1, 0});
      slog::Relation* readrel1132 = db->getRelation("ref");
      refindex1109 = readrel1132->getIndex(ord1131, false);
      std::vector<u16> ord1133({0, 1, 2});
      slog::Relation* readrel1134 = db->getRelation("app");
      appindex1110 = readrel1134->getIndex(ord1133, false);
      std::vector<u16> ord1135({1, 0});
      slog::Relation* readrel1136 = db->getRelation("ref");
      refindex1111 = readrel1136->getIndex(ord1135, false);
      std::vector<u16> ord1137({1, 2, 0});
      slog::Relation* readrel1138 = db->getRelation("app");
      appindex1112 = readrel1138->getIndex(ord1137, false);
      std::vector<u16> ord1139({1, 2, 0});
      slog::Relation* readrel1140 = db->getRelation("lambda");
      lambdaindex1113 = readrel1140->getIndex(ord1139, false);
  
    }
    ReadTask1114(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c153 = v_constfc9ee54e0ee8c6d1e715716c;
      u64 v_c154 = v_const15bb62b8293a526ca6f0e4eb;
      u64 v_c155 = v_const5950e3cb761734f52a881545;
      u64 v_c156 = v_const77ceb5c0e9f84ebd84104a97;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c157 = _t[0];
        u64 v_c158 = _t[1];
        u64 v_c159 = _t[2];
        if (!slog::exists_probe<2,1>(refindex1101, std::array<u64,2>{v_c156, 0})) return;
        if (!slog::exists_probe<3,2>(lambdaindex1102, std::array<u64,3>{v_c158, v_c155, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1103, std::array<u64,2>{v_c153, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1104, std::array<u64,2>{v_c154, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1105, std::array<u64,3>{v_c154, 0, 0})) return;
        slog::join_probe<3,2>(lambdaindex1106, std::array<u64,3>{v_c159, v_c156, 0}, [&](const std::array<u64,3>& m1141) {
          u64 v_c160 = m1141[2];
          slog::join_probe<2,2>(refindex1107, std::array<u64,2>{v_c160, v_c156}, [&](const std::array<u64,2>& m1142) {
            slog::join_probe<3,2>(lambdaindex1108, std::array<u64,3>{v_c158, v_c155, 0}, [&](const std::array<u64,3>& m1143) {
              u64 v_c161 = m1143[2];
              slog::join_probe<2,1>(refindex1109, std::array<u64,2>{v_c153, 0}, [&](const std::array<u64,2>& m1144) {
                u64 v_c162 = m1144[1];
                slog::join_probe<3,2>(appindex1110, std::array<u64,3>{v_c161, v_c162, 0}, [&](const std::array<u64,3>& m1145) {
                  u64 v_c163 = m1145[2];
                  if (v_c162 != v_c163) return;
                  slog::join_probe<2,1>(refindex1111, std::array<u64,2>{v_c154, 0}, [&](const std::array<u64,2>& m1146) {
                    u64 v_c164 = m1146[1];
                    slog::join_probe<3,1>(appindex1112, std::array<u64,3>{v_c164, 0, 0}, [&](const std::array<u64,3>& m1147) {
                      u64 v_c165 = m1147[1]; u64 v_c166 = m1147[2];
                      if (v_c164 != v_c165) return;
                      slog::join_probe<3,2>(lambdaindex1113, std::array<u64,3>{v_c154, v_c166, 0}, [&](const std::array<u64,3>& m1148) {
                        u64 v_c167 = m1148[2];
                        ++_fires;
                        slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c153, v_c157}, std::array<u16,3>{1, 2, 0});
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
        ReadTask1114* _cont = new ReadTask1114(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1114(db,b), false);
  // (crule (pre (let __tconst9zoW125 const7c7d2cfc66f4d976987d2d20) (let __tconst4V4L122 const6bc0ba365ada70df115e1785) (let __tconst82U8119 consta8180db1c2f300980314f910) (let __tconst3wDH116 constd5f017533ea574d5f9b3400c) (let __tconst4BKz104 const0f8748be649f8ee4066bb1d7) (let __tconst4Zcr91 const9a67f28c6b77e842f439a84a) (let __tconst0vRf84 conste58dec6bca6f63ef79c3b755) (let __tconst3ktF111 const990b444cbd47632035b2fa1a) (let __tconst5nWJ102 const4f84f41d89b6b717419b4eaa)) (scan app __t2Z7m108 __t7aew98 __t6RuY105) (body (join ref (0 1) 2 __t7aew98 __tconst4V4L122) (exists lambda (1 2 0) 1 __tconst5nWJ102) (exists ref (1 0) 1 __tconst5nWJ102) (exists ref (1 0) 1 __tconst3wDH116) (exists ref (1 0) 1 __tconst0vRf84) (exists lambda (1 2 0) 1 __tconst0vRf84) (exists ref (1 0) 1 __tconst4Zcr91) (exists ref (1 0) 1 __tconst9zoW125) (exists lambda (1 2 0) 1 __tconst4Zcr91) (exists ref (1 0) 1 __tconst4BKz104) (exists lambda (1 2 0) 1 __tconst4BKz104) (exists app (1 2 0) 1 __t7aew98) (exists ref (1 0) 1 __tconst3ktF111) (exists lambda (1 2 0) 1 __tconst3ktF111) (exists lambda (1 2 0) 1 __tconst3wDH116) (join lambda (0 1 2) 2 __t6RuY105 __tconst4BKz104 __t35jA103) (join lambda (0 1 2) 2 __t35jA103 __tconst5nWJ102 __t5MaG101) (join ref (0 1) 2 __t5MaG101 __tconst5nWJ102) (join ref (1 0) 1 __tconst3wDH116 __t3wir114) (exists app (1 2 0) 1 __t3wir114) (join ref (1 0) 1 __tconst0vRf84 __t2duR83) (join lambda (1 2 0) 2 __tconst0vRf84 __t2duR83 __t87vL85) (join ref (1 0) 1 __tconst4Zcr91 __t0C9F87) (exists app (2 0 1) 1 __t0C9F87) (join ref (1 0) 1 __tconst9zoW125 __t3Q2G89) (join app (1 2 0) 2 __t3Q2G89 __t0C9F87 __t2Eqd90) (join lambda (1 2 0) 2 __tconst4Zcr91 __t2Eqd90 __t3pgm92) (join ref (1 0) 1 __tconst4BKz104 __t8C0a94) (join lambda (1 2 0) 2 __tconst4BKz104 __t8C0a94 __t4fDK96) (join app (1 2 0) 2 __t7aew98 __t4fDK96 __t7TEO99) (join ref (1 0) 1 __tconst3ktF111 __t7ohz110) (join lambda (1 2 0) 2 __tconst3ktF111 __t7ohz110 __t8GWA112) (join app (1 2 0) 2 __t3wir114 __t8GWA112 __t44OM115) (join lambda (1 2 0) 2 __tconst3wDH116 __t44OM115 __t7CwH117)) (head (mkstruct app (1 2 0) __t50Kk118 __t7CwH117 __t2Z7m108)) mcfa-counting.slog:241 #f)
  class ReadTask1183 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex1149;  slog::Index** lambdaindex1150;  slog::Index** refindex1151;  slog::Index** refindex1152;  slog::Index** refindex1153;  slog::Index** lambdaindex1154;  slog::Index** refindex1155;  slog::Index** refindex1156;  slog::Index** lambdaindex1157;  slog::Index** refindex1158;  slog::Index** lambdaindex1159;  slog::Index** appindex1160;  slog::Index** refindex1161;  slog::Index** lambdaindex1162;  slog::Index** lambdaindex1163;  slog::Index** lambdaindex1164;  slog::Index** lambdaindex1165;  slog::Index** refindex1166;  slog::Index** refindex1167;  slog::Index** appindex1168;  slog::Index** refindex1169;  slog::Index** lambdaindex1170;  slog::Index** refindex1171;  slog::Index** appindex1172;  slog::Index** refindex1173;  slog::Index** appindex1174;  slog::Index** lambdaindex1175;  slog::Index** refindex1176;  slog::Index** lambdaindex1177;  slog::Index** appindex1178;  slog::Index** refindex1179;  slog::Index** lambdaindex1180;  slog::Index** appindex1181;  slog::Index** lambdaindex1182;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      outer_rel = db->getRelation("app");
      std::vector<u16> ord1184({0, 1});
      slog::Relation* readrel1185 = db->getRelation("ref");
      refindex1149 = readrel1185->getIndex(ord1184, false);
      std::vector<u16> ord1186({1, 2, 0});
      slog::Relation* readrel1187 = db->getRelation("lambda");
      lambdaindex1150 = readrel1187->getIndex(ord1186, false);
      std::vector<u16> ord1188({1, 0});
      slog::Relation* readrel1189 = db->getRelation("ref");
      refindex1151 = readrel1189->getIndex(ord1188, false);
      std::vector<u16> ord1190({1, 0});
      slog::Relation* readrel1191 = db->getRelation("ref");
      refindex1152 = readrel1191->getIndex(ord1190, false);
      std::vector<u16> ord1192({1, 0});
      slog::Relation* readrel1193 = db->getRelation("ref");
      refindex1153 = readrel1193->getIndex(ord1192, false);
      std::vector<u16> ord1194({1, 2, 0});
      slog::Relation* readrel1195 = db->getRelation("lambda");
      lambdaindex1154 = readrel1195->getIndex(ord1194, false);
      std::vector<u16> ord1196({1, 0});
      slog::Relation* readrel1197 = db->getRelation("ref");
      refindex1155 = readrel1197->getIndex(ord1196, false);
      std::vector<u16> ord1198({1, 0});
      slog::Relation* readrel1199 = db->getRelation("ref");
      refindex1156 = readrel1199->getIndex(ord1198, false);
      std::vector<u16> ord1200({1, 2, 0});
      slog::Relation* readrel1201 = db->getRelation("lambda");
      lambdaindex1157 = readrel1201->getIndex(ord1200, false);
      std::vector<u16> ord1202({1, 0});
      slog::Relation* readrel1203 = db->getRelation("ref");
      refindex1158 = readrel1203->getIndex(ord1202, false);
      std::vector<u16> ord1204({1, 2, 0});
      slog::Relation* readrel1205 = db->getRelation("lambda");
      lambdaindex1159 = readrel1205->getIndex(ord1204, false);
      std::vector<u16> ord1206({1, 2, 0});
      slog::Relation* readrel1207 = db->getRelation("app");
      appindex1160 = readrel1207->getIndex(ord1206, false);
      std::vector<u16> ord1208({1, 0});
      slog::Relation* readrel1209 = db->getRelation("ref");
      refindex1161 = readrel1209->getIndex(ord1208, false);
      std::vector<u16> ord1210({1, 2, 0});
      slog::Relation* readrel1211 = db->getRelation("lambda");
      lambdaindex1162 = readrel1211->getIndex(ord1210, false);
      std::vector<u16> ord1212({1, 2, 0});
      slog::Relation* readrel1213 = db->getRelation("lambda");
      lambdaindex1163 = readrel1213->getIndex(ord1212, false);
      std::vector<u16> ord1214({0, 1, 2});
      slog::Relation* readrel1215 = db->getRelation("lambda");
      lambdaindex1164 = readrel1215->getIndex(ord1214, false);
      std::vector<u16> ord1216({0, 1, 2});
      slog::Relation* readrel1217 = db->getRelation("lambda");
      lambdaindex1165 = readrel1217->getIndex(ord1216, false);
      std::vector<u16> ord1218({0, 1});
      slog::Relation* readrel1219 = db->getRelation("ref");
      refindex1166 = readrel1219->getIndex(ord1218, false);
      std::vector<u16> ord1220({1, 0});
      slog::Relation* readrel1221 = db->getRelation("ref");
      refindex1167 = readrel1221->getIndex(ord1220, false);
      std::vector<u16> ord1222({1, 2, 0});
      slog::Relation* readrel1223 = db->getRelation("app");
      appindex1168 = readrel1223->getIndex(ord1222, false);
      std::vector<u16> ord1224({1, 0});
      slog::Relation* readrel1225 = db->getRelation("ref");
      refindex1169 = readrel1225->getIndex(ord1224, false);
      std::vector<u16> ord1226({1, 2, 0});
      slog::Relation* readrel1227 = db->getRelation("lambda");
      lambdaindex1170 = readrel1227->getIndex(ord1226, false);
      std::vector<u16> ord1228({1, 0});
      slog::Relation* readrel1229 = db->getRelation("ref");
      refindex1171 = readrel1229->getIndex(ord1228, false);
      std::vector<u16> ord1230({2, 0, 1});
      slog::Relation* readrel1231 = db->getRelation("app");
      appindex1172 = readrel1231->getIndex(ord1230, false);
      std::vector<u16> ord1232({1, 0});
      slog::Relation* readrel1233 = db->getRelation("ref");
      refindex1173 = readrel1233->getIndex(ord1232, false);
      std::vector<u16> ord1234({1, 2, 0});
      slog::Relation* readrel1235 = db->getRelation("app");
      appindex1174 = readrel1235->getIndex(ord1234, false);
      std::vector<u16> ord1236({1, 2, 0});
      slog::Relation* readrel1237 = db->getRelation("lambda");
      lambdaindex1175 = readrel1237->getIndex(ord1236, false);
      std::vector<u16> ord1238({1, 0});
      slog::Relation* readrel1239 = db->getRelation("ref");
      refindex1176 = readrel1239->getIndex(ord1238, false);
      std::vector<u16> ord1240({1, 2, 0});
      slog::Relation* readrel1241 = db->getRelation("lambda");
      lambdaindex1177 = readrel1241->getIndex(ord1240, false);
      std::vector<u16> ord1242({1, 2, 0});
      slog::Relation* readrel1243 = db->getRelation("app");
      appindex1178 = readrel1243->getIndex(ord1242, false);
      std::vector<u16> ord1244({1, 0});
      slog::Relation* readrel1245 = db->getRelation("ref");
      refindex1179 = readrel1245->getIndex(ord1244, false);
      std::vector<u16> ord1246({1, 2, 0});
      slog::Relation* readrel1247 = db->getRelation("lambda");
      lambdaindex1180 = readrel1247->getIndex(ord1246, false);
      std::vector<u16> ord1248({1, 2, 0});
      slog::Relation* readrel1249 = db->getRelation("app");
      appindex1181 = readrel1249->getIndex(ord1248, false);
      std::vector<u16> ord1250({1, 2, 0});
      slog::Relation* readrel1251 = db->getRelation("lambda");
      lambdaindex1182 = readrel1251->getIndex(ord1250, false);
  
    }
    ReadTask1183(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const7c7d2cfc66f4d976987d2d20;
      u64 v_c1 = v_const6bc0ba365ada70df115e1785;
      u64 v_c2 = v_consta8180db1c2f300980314f910;
      u64 v_c3 = v_constd5f017533ea574d5f9b3400c;
      u64 v_c5 = v_const0f8748be649f8ee4066bb1d7;
      u64 v_c7 = v_const9a67f28c6b77e842f439a84a;
      u64 v_c8 = v_conste58dec6bca6f63ef79c3b755;
      u64 v_c4 = v_const990b444cbd47632035b2fa1a;
      u64 v_c6 = v_const4f84f41d89b6b717419b4eaa;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c120 = _t[0];
        u64 v_c13 = _t[1];
        u64 v_c102 = _t[2];
        slog::join_probe<2,2>(refindex1149, std::array<u64,2>{v_c13, v_c1}, [&](const std::array<u64,2>& m1252) {
          if (!slog::exists_probe<3,1>(lambdaindex1150, std::array<u64,3>{v_c6, 0, 0})) return;
          if (!slog::exists_probe<2,1>(refindex1151, std::array<u64,2>{v_c6, 0})) return;
          if (!slog::exists_probe<2,1>(refindex1152, std::array<u64,2>{v_c3, 0})) return;
          if (!slog::exists_probe<2,1>(refindex1153, std::array<u64,2>{v_c8, 0})) return;
          if (!slog::exists_probe<3,1>(lambdaindex1154, std::array<u64,3>{v_c8, 0, 0})) return;
          if (!slog::exists_probe<2,1>(refindex1155, std::array<u64,2>{v_c7, 0})) return;
          if (!slog::exists_probe<2,1>(refindex1156, std::array<u64,2>{v_c0, 0})) return;
          if (!slog::exists_probe<3,1>(lambdaindex1157, std::array<u64,3>{v_c7, 0, 0})) return;
          if (!slog::exists_probe<2,1>(refindex1158, std::array<u64,2>{v_c5, 0})) return;
          if (!slog::exists_probe<3,1>(lambdaindex1159, std::array<u64,3>{v_c5, 0, 0})) return;
          if (!slog::exists_probe<3,1>(appindex1160, std::array<u64,3>{v_c13, 0, 0})) return;
          if (!slog::exists_probe<2,1>(refindex1161, std::array<u64,2>{v_c4, 0})) return;
          if (!slog::exists_probe<3,1>(lambdaindex1162, std::array<u64,3>{v_c4, 0, 0})) return;
          if (!slog::exists_probe<3,1>(lambdaindex1163, std::array<u64,3>{v_c3, 0, 0})) return;
          slog::join_probe<3,2>(lambdaindex1164, std::array<u64,3>{v_c102, v_c5, 0}, [&](const std::array<u64,3>& m1253) {
            u64 v_c101 = m1253[2];
            slog::join_probe<3,2>(lambdaindex1165, std::array<u64,3>{v_c101, v_c6, 0}, [&](const std::array<u64,3>& m1254) {
              u64 v_c14 = m1254[2];
              slog::join_probe<2,2>(refindex1166, std::array<u64,2>{v_c14, v_c6}, [&](const std::array<u64,2>& m1255) {
                slog::join_probe<2,1>(refindex1167, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m1256) {
                  u64 v_c16 = m1256[1];
                  if (!slog::exists_probe<3,1>(appindex1168, std::array<u64,3>{v_c16, 0, 0})) return;
                  slog::join_probe<2,1>(refindex1169, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m1257) {
                    u64 v_c9 = m1257[1];
                    slog::join_probe<3,2>(lambdaindex1170, std::array<u64,3>{v_c8, v_c9, 0}, [&](const std::array<u64,3>& m1258) {
                      u64 v_c98 = m1258[2];
                      slog::join_probe<2,1>(refindex1171, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m1259) {
                        u64 v_c10 = m1259[1];
                        if (!slog::exists_probe<3,1>(appindex1172, std::array<u64,3>{v_c10, 0, 0})) return;
                        slog::join_probe<2,1>(refindex1173, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m1260) {
                          u64 v_c11 = m1260[1];
                          slog::join_probe<3,2>(appindex1174, std::array<u64,3>{v_c11, v_c10, 0}, [&](const std::array<u64,3>& m1261) {
                            u64 v_c96 = m1261[2];
                            slog::join_probe<3,2>(lambdaindex1175, std::array<u64,3>{v_c7, v_c96, 0}, [&](const std::array<u64,3>& m1262) {
                              u64 v_c97 = m1262[2];
                              slog::join_probe<2,1>(refindex1176, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m1263) {
                                u64 v_c12 = m1263[1];
                                slog::join_probe<3,2>(lambdaindex1177, std::array<u64,3>{v_c5, v_c12, 0}, [&](const std::array<u64,3>& m1264) {
                                  u64 v_c99 = m1264[2];
                                  slog::join_probe<3,2>(appindex1178, std::array<u64,3>{v_c13, v_c99, 0}, [&](const std::array<u64,3>& m1265) {
                                    u64 v_c100 = m1265[2];
                                    slog::join_probe<2,1>(refindex1179, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m1266) {
                                      u64 v_c15 = m1266[1];
                                      slog::join_probe<3,2>(lambdaindex1180, std::array<u64,3>{v_c4, v_c15, 0}, [&](const std::array<u64,3>& m1267) {
                                        u64 v_c103 = m1267[2];
                                        slog::join_probe<3,2>(appindex1181, std::array<u64,3>{v_c16, v_c103, 0}, [&](const std::array<u64,3>& m1268) {
                                          u64 v_c104 = m1268[2];
                                          slog::join_probe<3,2>(lambdaindex1182, std::array<u64,3>{v_c3, v_c104, 0}, [&](const std::array<u64,3>& m1269) {
                                            u64 v_c121 = m1269[2];
                                            ++_fires;
                                            slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c121, v_c120}, std::array<u16,3>{1, 2, 0});
                                          });
                                        });
                                      });
                                    });
                                  });
                                });
                              });
                            });
                          });
                        });
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
        ReadTask1183* _cont = new ReadTask1183(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1183(db,b), false);
}

