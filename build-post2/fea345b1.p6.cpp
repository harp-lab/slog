
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const07ef7e8462f6d369d70a1f0e;
extern u64 v_const0aa6f87434af0222b916e97a;
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
extern u64 v_const4e5ef144c51cd25230c144c3;
extern u64 v_const576506f61f53440f1edd95d2;
extern u64 v_const5950e3cb761734f52a881545;
extern u64 v_const59ba3256d223f0d0a00d0633;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const615ad01b1c532bb6634df115;
extern u64 v_const66518c0c1b3a5a0b09ae2ef1;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const6cf13cc59dcbe759113f68a4;
extern u64 v_const77ceb5c0e9f84ebd84104a97;
extern u64 v_const7b8fd91ee9ff10cfbb8066bf;
extern u64 v_const7cd75b35aa30c3ddf04f9d57;
extern u64 v_const81cb39a72a584ab4f703b7f7;
extern u64 v_const85f09fa1913b9daf65957cf7;
extern u64 v_const8ca682693a0738a0641c6956;
extern u64 v_const969c6e56242ce8d0a4346602;
extern u64 v_const970c20ea81b833e5b5a7accf;
extern u64 v_consta32d5a443def48e6d64c6f4b;
extern u64 v_constaaaad65142343c54348db5d0;
extern u64 v_constb49bea2fcccd8f4301a347ed;
extern u64 v_constc40f204dda7ba4054abb9e74;
extern u64 v_constc85eae03730a4f4cf1d66a0c;
extern u64 v_constcaa3ee5a2828a31924f6b39d;
extern u64 v_constd3d07026d47882ceca728218;
extern u64 v_constd7a1925d249b4768c8a9f2d8;
extern u64 v_constdbf1bdba02122b2adce28528;
extern u64 v_constdc1bb6655fb38bdb032e3754;
extern u64 v_consteb793a6f75d6cfe49d3c2c90;
extern u64 v_constf700a82e218a86de572e1f7f;
extern u64 v_constfc9ee54e0ee8c6d1e715716c;


void slog_rules_ccb9d54545b4a7fb9(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre) (scan app __t5qnk78 ef ea) (body (join-old eval (1 2 0) 1 (1 2 0) __t5qnk78 c __t0yID79)) (head (emit $sup27994x83x0x0x0 (0 1 2 3) __t0yID79 c ea ef)) mcfa-counting.slog:84 #f)
  class ReadTask2 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex0;  slog::Index** evaldelta1;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup27994x83x0x0x0");
      std::vector<u16> ord3({0, 1, 2, 3});
      slog::Relation* readrel4 = db->getRelation("$sup27994x83x0x0x0");
      head_index[0] = readrel4->getIndex(ord3, false);
      outer_rel = db->getRelation("app");
      std::vector<u16> ord5({1, 2, 0});
      slog::Relation* readrel6 = db->getRelation("eval");
      evalindex0 = readrel6->getIndex(ord5, false);
      std::vector<u16> ord7({1, 2, 0});
      slog::Relation* readrel8 = db->getRelation("eval");
      evaldelta1 = readrel8->getIndex(ord7, true);
  
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
        slog::join_probe_old<3,1>(evalindex0, evaldelta1, std::array<u64,3>{v_c0, 0, 0}, [&](const std::array<u64,3>& m9) {
          u64 v_c3 = m9[1]; u64 v_c4 = m9[2];
          ++_fires;
          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c4, v_c3, v_c2, v_c1}, std::array<u16,4>{0, 1, 2, 3});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:84", "delta:app", _fires);
  
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
  // (crule (pre (let __tconst4Xaz41 const81cb39a72a584ab4f703b7f7) (let __tconst1aIN38 const4d5ce1398140fbe27561181f) (let __tconst4xzG22 constdbf1bdba02122b2adce28528) (let __tconst1ha033 const969c6e56242ce8d0a4346602) (let __tconst37GM26 const85f09fa1913b9daf65957cf7) (let __tconst1HMF17 constd7a1925d249b4768c8a9f2d8)) (seeded) (body (join ref (1 0) 1 __tconst4xzG22 __t2DOE20) (exists ref (1 0) 1 __tconst1HMF17) (exists lambda (1 2 0) 1 __tconst1HMF17) (exists app (1 2 0) 1 __t2DOE20) (exists ref (1 0) 1 __tconst37GM26) (exists lambda (1 2 0) 1 __tconst37GM26) (exists ref (1 0) 1 __tconst1ha033) (exists lambda (1 2 0) 1 __tconst1ha033) (join ref (1 0) 1 __tconst4Xaz41 __t75SZ29) (exists app (1 2 0) 1 __t75SZ29) (join ref (1 0) 1 __tconst1HMF17 __t7H1u16) (join lambda (1 2 0) 2 __tconst1HMF17 __t7H1u16 __t2wNc18) (join app (1 2 0) 2 __t2DOE20 __t2wNc18 __t3b2k21) (join ref (1 0) 1 __tconst37GM26 __t7U1m25) (join lambda (1 2 0) 2 __tconst37GM26 __t7U1m25 __t5myE27) (join app (1 2 0) 2 __t75SZ29 __t5myE27 __t2Vg230) (join ref (1 0) 1 __tconst1ha033 __t7N9A32) (join lambda (1 2 0) 2 __tconst1ha033 __t7N9A32 __t065j34) (join app (1 2 0) 2 __t75SZ29 __t065j34 __t3pMW37)) (head (mkstruct lambda (1 2 0) __t3aRV39 __tconst1aIN38 __t3pMW37) (mkstruct lambda (1 2 0) __t8Ovw23 __tconst4xzG22 __t3b2k21)) mcfa-counting.slog:260 #f)
  class ReadTask29 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
  
  
  
  
  
    slog::Index** refindex10;  slog::Index** refindex11;  slog::Index** lambdaindex12;  slog::Index** appindex13;  slog::Index** refindex14;  slog::Index** lambdaindex15;  slog::Index** refindex16;  slog::Index** lambdaindex17;  slog::Index** refindex18;  slog::Index** appindex19;  slog::Index** refindex20;  slog::Index** lambdaindex21;  slog::Index** appindex22;  slog::Index** refindex23;  slog::Index** lambdaindex24;  slog::Index** appindex25;  slog::Index** refindex26;  slog::Index** lambdaindex27;  slog::Index** appindex28;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      std::vector<u16> ord30({1, 2, 0});
      slog::Relation* readrel31 = db->getRelation("lambda");
      head_index[0] = readrel31->getIndex(ord30, false);
      head_rel[1] = db->getRelation("lambda");
      std::vector<u16> ord32({1, 2, 0});
      slog::Relation* readrel33 = db->getRelation("lambda");
      head_index[1] = readrel33->getIndex(ord32, false);
      std::vector<u16> ord34({1, 0});
      slog::Relation* readrel35 = db->getRelation("ref");
      refindex10 = readrel35->getIndex(ord34, false);
      std::vector<u16> ord36({1, 0});
      slog::Relation* readrel37 = db->getRelation("ref");
      refindex11 = readrel37->getIndex(ord36, false);
      std::vector<u16> ord38({1, 2, 0});
      slog::Relation* readrel39 = db->getRelation("lambda");
      lambdaindex12 = readrel39->getIndex(ord38, false);
      std::vector<u16> ord40({1, 2, 0});
      slog::Relation* readrel41 = db->getRelation("app");
      appindex13 = readrel41->getIndex(ord40, false);
      std::vector<u16> ord42({1, 0});
      slog::Relation* readrel43 = db->getRelation("ref");
      refindex14 = readrel43->getIndex(ord42, false);
      std::vector<u16> ord44({1, 2, 0});
      slog::Relation* readrel45 = db->getRelation("lambda");
      lambdaindex15 = readrel45->getIndex(ord44, false);
      std::vector<u16> ord46({1, 0});
      slog::Relation* readrel47 = db->getRelation("ref");
      refindex16 = readrel47->getIndex(ord46, false);
      std::vector<u16> ord48({1, 2, 0});
      slog::Relation* readrel49 = db->getRelation("lambda");
      lambdaindex17 = readrel49->getIndex(ord48, false);
      std::vector<u16> ord50({1, 0});
      slog::Relation* readrel51 = db->getRelation("ref");
      refindex18 = readrel51->getIndex(ord50, false);
      std::vector<u16> ord52({1, 2, 0});
      slog::Relation* readrel53 = db->getRelation("app");
      appindex19 = readrel53->getIndex(ord52, false);
      std::vector<u16> ord54({1, 0});
      slog::Relation* readrel55 = db->getRelation("ref");
      refindex20 = readrel55->getIndex(ord54, false);
      std::vector<u16> ord56({1, 2, 0});
      slog::Relation* readrel57 = db->getRelation("lambda");
      lambdaindex21 = readrel57->getIndex(ord56, false);
      std::vector<u16> ord58({1, 2, 0});
      slog::Relation* readrel59 = db->getRelation("app");
      appindex22 = readrel59->getIndex(ord58, false);
      std::vector<u16> ord60({1, 0});
      slog::Relation* readrel61 = db->getRelation("ref");
      refindex23 = readrel61->getIndex(ord60, false);
      std::vector<u16> ord62({1, 2, 0});
      slog::Relation* readrel63 = db->getRelation("lambda");
      lambdaindex24 = readrel63->getIndex(ord62, false);
      std::vector<u16> ord64({1, 2, 0});
      slog::Relation* readrel65 = db->getRelation("app");
      appindex25 = readrel65->getIndex(ord64, false);
      std::vector<u16> ord66({1, 0});
      slog::Relation* readrel67 = db->getRelation("ref");
      refindex26 = readrel67->getIndex(ord66, false);
      std::vector<u16> ord68({1, 2, 0});
      slog::Relation* readrel69 = db->getRelation("lambda");
      lambdaindex27 = readrel69->getIndex(ord68, false);
      std::vector<u16> ord70({1, 2, 0});
      slog::Relation* readrel71 = db->getRelation("app");
      appindex28 = readrel71->getIndex(ord70, false);
  
    }
    ReadTask29(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c5 = v_const81cb39a72a584ab4f703b7f7;
      u64 v_c6 = v_const4d5ce1398140fbe27561181f;
      u64 v_c7 = v_constdbf1bdba02122b2adce28528;
      u64 v_c8 = v_const969c6e56242ce8d0a4346602;
      u64 v_c9 = v_const85f09fa1913b9daf65957cf7;
      u64 v_c10 = v_constd7a1925d249b4768c8a9f2d8;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex10, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m72) {
        u64 v_c11 = m72[1];
        if (!slog::exists_probe<2,1>(refindex11, std::array<u64,2>{v_c10, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex12, std::array<u64,3>{v_c10, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex13, std::array<u64,3>{v_c11, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex14, std::array<u64,2>{v_c9, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex15, std::array<u64,3>{v_c9, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex16, std::array<u64,2>{v_c8, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex17, std::array<u64,3>{v_c8, 0, 0})) return;
        slog::join_probe<2,1>(refindex18, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m73) {
          u64 v_c12 = m73[1];
          if (!slog::exists_probe<3,1>(appindex19, std::array<u64,3>{v_c12, 0, 0})) return;
          slog::join_probe<2,1>(refindex20, std::array<u64,2>{v_c10, 0}, [&](const std::array<u64,2>& m74) {
            u64 v_c13 = m74[1];
            slog::join_probe<3,2>(lambdaindex21, std::array<u64,3>{v_c10, v_c13, 0}, [&](const std::array<u64,3>& m75) {
              u64 v_c14 = m75[2];
              slog::join_probe<3,2>(appindex22, std::array<u64,3>{v_c11, v_c14, 0}, [&](const std::array<u64,3>& m76) {
                u64 v_c15 = m76[2];
                slog::join_probe<2,1>(refindex23, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m77) {
                  u64 v_c16 = m77[1];
                  slog::join_probe<3,2>(lambdaindex24, std::array<u64,3>{v_c9, v_c16, 0}, [&](const std::array<u64,3>& m78) {
                    u64 v_c17 = m78[2];
                    slog::join_probe<3,2>(appindex25, std::array<u64,3>{v_c12, v_c17, 0}, [&](const std::array<u64,3>& m79) {
                      u64 v_c18 = m79[2];
                      slog::join_probe<2,1>(refindex26, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m80) {
                        u64 v_c19 = m80[1];
                        slog::join_probe<3,2>(lambdaindex27, std::array<u64,3>{v_c8, v_c19, 0}, [&](const std::array<u64,3>& m81) {
                          u64 v_c20 = m81[2];
                          slog::join_probe<3,2>(appindex28, std::array<u64,3>{v_c12, v_c20, 0}, [&](const std::array<u64,3>& m82) {
                            u64 v_c21 = m82[2];
                            ++_fires;
                            slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c6, v_c21}, std::array<u16,3>{1, 2, 0});
                            slog::emit_struct_checked<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c7, v_c15}, std::array<u16,3>{1, 2, 0});
                          });
                        });
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
  
      if (_fires) db->bumpFires("mcfa-counting.slog:260", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask29(db,b));
  // (crule (pre (let __tconst0y6X73 const0aa6f87434af0222b916e97a) (let __tconst0aL952 constd3d07026d47882ceca728218) (let __tconst7zoP70 const227d34ceeba7a29aada993d4) (let __tconst1bfe65 const59ba3256d223f0d0a00d0633) (let __tconst0xUh47 constf700a82e218a86de572e1f7f) (let __tconst8wN863 const7cd75b35aa30c3ddf04f9d57)) (probe lambda (1 2 0) 1 __tconst0y6X73 __t9kFz72 __t9J4m74) (body (exists ref (1 0) 1 __tconst0aL952) (exists ref (1 0) 1 __tconst1bfe65) (exists lambda (1 2 0) 1 __tconst1bfe65) (exists lambda (1 2 0) 1 __tconst7zoP70) (exists lambda (1 2 0) 1 __tconst8wN863) (exists ref (1 0) 1 __tconst8wN863) (exists ref (1 0) 1 __tconst0xUh47) (exists lambda (1 2 0) 1 __tconst0xUh47) (exists lambda (1 2 0) 1 __tconst0aL952) (join ref (1 0) 1 __tconst0y6X73 __t0QRr59) (exists app (1 2 0) 1 __t0QRr59) (join ref (1 0) 1 __tconst0aL952 __t5HQ450) (exists app (1 2 0) 1 __t5HQ450) (join ref (1 0) 1 __tconst1bfe65 __t2HsD55) (join lambda (1 2 0) 2 __tconst1bfe65 __t2HsD55 __t0uNb57) (join app (1 2 0) 2 __t0QRr59 __t0uNb57 __t81HE60) (join app (2 0 1) 2 __t81HE60 __t9kFz72 __t7KAC71) (join lambda (0 1 2) 2 __t7KAC71 __tconst7zoP70 __t5Ri569) (join app (0 1 2) 2 __t5Ri569 __t0QRr59 __t7JIT66) (join lambda (0 1 2) 2 __t7JIT66 __tconst1bfe65 __t3Dru64) (join lambda (0 1 2) 2 __t3Dru64 __tconst8wN863 __t1mkO62) (join ref (0 1) 2 __t1mkO62 __tconst8wN863) (join ref (1 0) 1 __tconst0xUh47 __t5vZb46) (join lambda (1 2 0) 2 __tconst0xUh47 __t5vZb46 __t50zW48) (join app (1 2 0) 2 __t5HQ450 __t50zW48 __t05NY51) (join lambda (1 2 0) 2 __tconst0aL952 __t05NY51 __t3xtz53)) (head (mkstruct app (1 2 0) __t5ePS75 __t9J4m74 __t3xtz53)) mcfa-counting.slog:287 #f)
  class ReadTask109 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** refindex83;  slog::Index** refindex84;  slog::Index** lambdaindex85;  slog::Index** lambdaindex86;  slog::Index** lambdaindex87;  slog::Index** refindex88;  slog::Index** refindex89;  slog::Index** lambdaindex90;  slog::Index** lambdaindex91;  slog::Index** refindex92;  slog::Index** appindex93;  slog::Index** refindex94;  slog::Index** appindex95;  slog::Index** refindex96;  slog::Index** lambdaindex97;  slog::Index** appindex98;  slog::Index** appindex99;  slog::Index** lambdaindex100;  slog::Index** appindex101;  slog::Index** lambdaindex102;  slog::Index** lambdaindex103;  slog::Index** refindex104;  slog::Index** refindex105;  slog::Index** lambdaindex106;  slog::Index** appindex107;  slog::Index** lambdaindex108;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord110({1, 2, 0});
      slog::Relation* readrel111 = db->getRelation("lambda");
      driver_index = readrel111->getIndex(ord110, true);
      std::vector<u16> ord112({1, 0});
      slog::Relation* readrel113 = db->getRelation("ref");
      refindex83 = readrel113->getIndex(ord112, false);
      std::vector<u16> ord114({1, 0});
      slog::Relation* readrel115 = db->getRelation("ref");
      refindex84 = readrel115->getIndex(ord114, false);
      std::vector<u16> ord116({1, 2, 0});
      slog::Relation* readrel117 = db->getRelation("lambda");
      lambdaindex85 = readrel117->getIndex(ord116, false);
      std::vector<u16> ord118({1, 2, 0});
      slog::Relation* readrel119 = db->getRelation("lambda");
      lambdaindex86 = readrel119->getIndex(ord118, false);
      std::vector<u16> ord120({1, 2, 0});
      slog::Relation* readrel121 = db->getRelation("lambda");
      lambdaindex87 = readrel121->getIndex(ord120, false);
      std::vector<u16> ord122({1, 0});
      slog::Relation* readrel123 = db->getRelation("ref");
      refindex88 = readrel123->getIndex(ord122, false);
      std::vector<u16> ord124({1, 0});
      slog::Relation* readrel125 = db->getRelation("ref");
      refindex89 = readrel125->getIndex(ord124, false);
      std::vector<u16> ord126({1, 2, 0});
      slog::Relation* readrel127 = db->getRelation("lambda");
      lambdaindex90 = readrel127->getIndex(ord126, false);
      std::vector<u16> ord128({1, 2, 0});
      slog::Relation* readrel129 = db->getRelation("lambda");
      lambdaindex91 = readrel129->getIndex(ord128, false);
      std::vector<u16> ord130({1, 0});
      slog::Relation* readrel131 = db->getRelation("ref");
      refindex92 = readrel131->getIndex(ord130, false);
      std::vector<u16> ord132({1, 2, 0});
      slog::Relation* readrel133 = db->getRelation("app");
      appindex93 = readrel133->getIndex(ord132, false);
      std::vector<u16> ord134({1, 0});
      slog::Relation* readrel135 = db->getRelation("ref");
      refindex94 = readrel135->getIndex(ord134, false);
      std::vector<u16> ord136({1, 2, 0});
      slog::Relation* readrel137 = db->getRelation("app");
      appindex95 = readrel137->getIndex(ord136, false);
      std::vector<u16> ord138({1, 0});
      slog::Relation* readrel139 = db->getRelation("ref");
      refindex96 = readrel139->getIndex(ord138, false);
      std::vector<u16> ord140({1, 2, 0});
      slog::Relation* readrel141 = db->getRelation("lambda");
      lambdaindex97 = readrel141->getIndex(ord140, false);
      std::vector<u16> ord142({1, 2, 0});
      slog::Relation* readrel143 = db->getRelation("app");
      appindex98 = readrel143->getIndex(ord142, false);
      std::vector<u16> ord144({2, 0, 1});
      slog::Relation* readrel145 = db->getRelation("app");
      appindex99 = readrel145->getIndex(ord144, false);
      std::vector<u16> ord146({0, 1, 2});
      slog::Relation* readrel147 = db->getRelation("lambda");
      lambdaindex100 = readrel147->getIndex(ord146, false);
      std::vector<u16> ord148({0, 1, 2});
      slog::Relation* readrel149 = db->getRelation("app");
      appindex101 = readrel149->getIndex(ord148, false);
      std::vector<u16> ord150({0, 1, 2});
      slog::Relation* readrel151 = db->getRelation("lambda");
      lambdaindex102 = readrel151->getIndex(ord150, false);
      std::vector<u16> ord152({0, 1, 2});
      slog::Relation* readrel153 = db->getRelation("lambda");
      lambdaindex103 = readrel153->getIndex(ord152, false);
      std::vector<u16> ord154({0, 1});
      slog::Relation* readrel155 = db->getRelation("ref");
      refindex104 = readrel155->getIndex(ord154, false);
      std::vector<u16> ord156({1, 0});
      slog::Relation* readrel157 = db->getRelation("ref");
      refindex105 = readrel157->getIndex(ord156, false);
      std::vector<u16> ord158({1, 2, 0});
      slog::Relation* readrel159 = db->getRelation("lambda");
      lambdaindex106 = readrel159->getIndex(ord158, false);
      std::vector<u16> ord160({1, 2, 0});
      slog::Relation* readrel161 = db->getRelation("app");
      appindex107 = readrel161->getIndex(ord160, false);
      std::vector<u16> ord162({1, 2, 0});
      slog::Relation* readrel163 = db->getRelation("lambda");
      lambdaindex108 = readrel163->getIndex(ord162, false);
  
    }
    ReadTask109(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c22 = v_const0aa6f87434af0222b916e97a;
      u64 v_c23 = v_constd3d07026d47882ceca728218;
      u64 v_c24 = v_const227d34ceeba7a29aada993d4;
      u64 v_c25 = v_const59ba3256d223f0d0a00d0633;
      u64 v_c26 = v_constf700a82e218a86de572e1f7f;
      u64 v_c27 = v_const7cd75b35aa30c3ddf04f9d57;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c22, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m164) {
        u64 v_c28 = m164[1];
        u64 v_c29 = m164[2];
        if (buckethash(v_c28) != bucket) return;
        if (!slog::exists_probe<2,1>(refindex83, std::array<u64,2>{v_c23, 0})) return;
        if (!slog::exists_probe<2,1>(refindex84, std::array<u64,2>{v_c25, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex85, std::array<u64,3>{v_c25, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex86, std::array<u64,3>{v_c24, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex87, std::array<u64,3>{v_c27, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex88, std::array<u64,2>{v_c27, 0})) return;
        if (!slog::exists_probe<2,1>(refindex89, std::array<u64,2>{v_c26, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex90, std::array<u64,3>{v_c26, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex91, std::array<u64,3>{v_c23, 0, 0})) return;
        slog::join_probe<2,1>(refindex92, std::array<u64,2>{v_c22, 0}, [&](const std::array<u64,2>& m165) {
          u64 v_c30 = m165[1];
          if (!slog::exists_probe<3,1>(appindex93, std::array<u64,3>{v_c30, 0, 0})) return;
          slog::join_probe<2,1>(refindex94, std::array<u64,2>{v_c23, 0}, [&](const std::array<u64,2>& m166) {
            u64 v_c31 = m166[1];
            if (!slog::exists_probe<3,1>(appindex95, std::array<u64,3>{v_c31, 0, 0})) return;
            slog::join_probe<2,1>(refindex96, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m167) {
              u64 v_c32 = m167[1];
              slog::join_probe<3,2>(lambdaindex97, std::array<u64,3>{v_c25, v_c32, 0}, [&](const std::array<u64,3>& m168) {
                u64 v_c33 = m168[2];
                slog::join_probe<3,2>(appindex98, std::array<u64,3>{v_c30, v_c33, 0}, [&](const std::array<u64,3>& m169) {
                  u64 v_c34 = m169[2];
                  slog::join_probe<3,2>(appindex99, std::array<u64,3>{v_c34, v_c28, 0}, [&](const std::array<u64,3>& m170) {
                    u64 v_c35 = m170[2];
                    slog::join_probe<3,2>(lambdaindex100, std::array<u64,3>{v_c35, v_c24, 0}, [&](const std::array<u64,3>& m171) {
                      u64 v_c36 = m171[2];
                      slog::join_probe<3,2>(appindex101, std::array<u64,3>{v_c36, v_c30, 0}, [&](const std::array<u64,3>& m172) {
                        u64 v_c37 = m172[2];
                        slog::join_probe<3,2>(lambdaindex102, std::array<u64,3>{v_c37, v_c25, 0}, [&](const std::array<u64,3>& m173) {
                          u64 v_c38 = m173[2];
                          slog::join_probe<3,2>(lambdaindex103, std::array<u64,3>{v_c38, v_c27, 0}, [&](const std::array<u64,3>& m174) {
                            u64 v_c39 = m174[2];
                            slog::join_probe<2,2>(refindex104, std::array<u64,2>{v_c39, v_c27}, [&](const std::array<u64,2>& m175) {
                              slog::join_probe<2,1>(refindex105, std::array<u64,2>{v_c26, 0}, [&](const std::array<u64,2>& m176) {
                                u64 v_c40 = m176[1];
                                slog::join_probe<3,2>(lambdaindex106, std::array<u64,3>{v_c26, v_c40, 0}, [&](const std::array<u64,3>& m177) {
                                  u64 v_c41 = m177[2];
                                  slog::join_probe<3,2>(appindex107, std::array<u64,3>{v_c31, v_c41, 0}, [&](const std::array<u64,3>& m178) {
                                    u64 v_c42 = m178[2];
                                    slog::join_probe<3,2>(lambdaindex108, std::array<u64,3>{v_c23, v_c42, 0}, [&](const std::array<u64,3>& m179) {
                                      u64 v_c43 = m179[2];
                                      ++_fires;
                                      slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c29, v_c43}, std::array<u16,3>{1, 2, 0});
                                    });
                                  });
                                });
                              });
                            });
                          });
                        });
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
        ReadTask109* _cont = new ReadTask109(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask109(db,b), false);
  // (crule (pre (let __tconst1pJW313 constb49bea2fcccd8f4301a347ed) (let __tconst7LWP310 const66518c0c1b3a5a0b09ae2ef1) (let __tconst0sqO307 const4a8acfc71441e0695ffcf5b3) (let __tconst5PoN291 constc85eae03730a4f4cf1d66a0c) (let __tconst2CSv302 const229c0b7aa8a7eb4055f5a3d0) (let __tconst9rZO295 const576506f61f53440f1edd95d2) (let __tconst2Yzp284 const8ca682693a0738a0641c6956)) (seeded) (body (join ref (1 0) 1 __tconst7LWP310 __t91H2298) (exists lambda (1 2 0) 1 __tconst2Yzp284) (exists ref (1 0) 1 __tconst1pJW313) (exists ref (1 0) 1 __tconst9rZO295) (exists lambda (1 2 0) 1 __tconst9rZO295) (exists app (1 2 0) 1 __t91H2298) (exists ref (1 0) 1 __tconst2CSv302) (exists lambda (1 2 0) 1 __tconst2CSv302) (exists lambda (1 2 0) 1 __tconst5PoN291) (join ref (1 0) 1 __tconst2Yzp284 __t248W283) (join lambda (1 2 0) 2 __tconst2Yzp284 __t248W283 __t0oFu285) (join ref (1 0) 1 __tconst1pJW313 __t165O287) (exists app (1 2 0) 1 __t165O287) (join ref (1 0) 1 __tconst9rZO295 __t71w7294) (join lambda (1 2 0) 2 __tconst9rZO295 __t71w7294 __t3dkk296) (join app (1 2 0) 2 __t91H2298 __t3dkk296 __t4LtH299) (join ref (1 0) 1 __tconst2CSv302 __t6lXa301) (join lambda (1 2 0) 2 __tconst2CSv302 __t6lXa301 __t7EW2303) (join app (1 2 0) 2 __t91H2298 __t7EW2303 __t4HUX306) (join app (1 2 0) 1 __t165O287 dup79hV378 __t30Ec290) (eq __t165O287 dup79hV378) (join lambda (1 2 0) 2 __tconst5PoN291 __t30Ec290 __t7aCZ292)) (head (mkstruct lambda (1 2 0) __t0vn1308 __tconst0sqO307 __t4HUX306)) mcfa-counting.slog:194 #f)
  class ReadTask201 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex180;  slog::Index** lambdaindex181;  slog::Index** refindex182;  slog::Index** refindex183;  slog::Index** lambdaindex184;  slog::Index** appindex185;  slog::Index** refindex186;  slog::Index** lambdaindex187;  slog::Index** lambdaindex188;  slog::Index** refindex189;  slog::Index** lambdaindex190;  slog::Index** refindex191;  slog::Index** appindex192;  slog::Index** refindex193;  slog::Index** lambdaindex194;  slog::Index** appindex195;  slog::Index** refindex196;  slog::Index** lambdaindex197;  slog::Index** appindex198;  slog::Index** appindex199;  slog::Index** lambdaindex200;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      std::vector<u16> ord202({1, 2, 0});
      slog::Relation* readrel203 = db->getRelation("lambda");
      head_index[0] = readrel203->getIndex(ord202, false);
      std::vector<u16> ord204({1, 0});
      slog::Relation* readrel205 = db->getRelation("ref");
      refindex180 = readrel205->getIndex(ord204, false);
      std::vector<u16> ord206({1, 2, 0});
      slog::Relation* readrel207 = db->getRelation("lambda");
      lambdaindex181 = readrel207->getIndex(ord206, false);
      std::vector<u16> ord208({1, 0});
      slog::Relation* readrel209 = db->getRelation("ref");
      refindex182 = readrel209->getIndex(ord208, false);
      std::vector<u16> ord210({1, 0});
      slog::Relation* readrel211 = db->getRelation("ref");
      refindex183 = readrel211->getIndex(ord210, false);
      std::vector<u16> ord212({1, 2, 0});
      slog::Relation* readrel213 = db->getRelation("lambda");
      lambdaindex184 = readrel213->getIndex(ord212, false);
      std::vector<u16> ord214({1, 2, 0});
      slog::Relation* readrel215 = db->getRelation("app");
      appindex185 = readrel215->getIndex(ord214, false);
      std::vector<u16> ord216({1, 0});
      slog::Relation* readrel217 = db->getRelation("ref");
      refindex186 = readrel217->getIndex(ord216, false);
      std::vector<u16> ord218({1, 2, 0});
      slog::Relation* readrel219 = db->getRelation("lambda");
      lambdaindex187 = readrel219->getIndex(ord218, false);
      std::vector<u16> ord220({1, 2, 0});
      slog::Relation* readrel221 = db->getRelation("lambda");
      lambdaindex188 = readrel221->getIndex(ord220, false);
      std::vector<u16> ord222({1, 0});
      slog::Relation* readrel223 = db->getRelation("ref");
      refindex189 = readrel223->getIndex(ord222, false);
      std::vector<u16> ord224({1, 2, 0});
      slog::Relation* readrel225 = db->getRelation("lambda");
      lambdaindex190 = readrel225->getIndex(ord224, false);
      std::vector<u16> ord226({1, 0});
      slog::Relation* readrel227 = db->getRelation("ref");
      refindex191 = readrel227->getIndex(ord226, false);
      std::vector<u16> ord228({1, 2, 0});
      slog::Relation* readrel229 = db->getRelation("app");
      appindex192 = readrel229->getIndex(ord228, false);
      std::vector<u16> ord230({1, 0});
      slog::Relation* readrel231 = db->getRelation("ref");
      refindex193 = readrel231->getIndex(ord230, false);
      std::vector<u16> ord232({1, 2, 0});
      slog::Relation* readrel233 = db->getRelation("lambda");
      lambdaindex194 = readrel233->getIndex(ord232, false);
      std::vector<u16> ord234({1, 2, 0});
      slog::Relation* readrel235 = db->getRelation("app");
      appindex195 = readrel235->getIndex(ord234, false);
      std::vector<u16> ord236({1, 0});
      slog::Relation* readrel237 = db->getRelation("ref");
      refindex196 = readrel237->getIndex(ord236, false);
      std::vector<u16> ord238({1, 2, 0});
      slog::Relation* readrel239 = db->getRelation("lambda");
      lambdaindex197 = readrel239->getIndex(ord238, false);
      std::vector<u16> ord240({1, 2, 0});
      slog::Relation* readrel241 = db->getRelation("app");
      appindex198 = readrel241->getIndex(ord240, false);
      std::vector<u16> ord242({1, 2, 0});
      slog::Relation* readrel243 = db->getRelation("app");
      appindex199 = readrel243->getIndex(ord242, false);
      std::vector<u16> ord244({1, 2, 0});
      slog::Relation* readrel245 = db->getRelation("lambda");
      lambdaindex200 = readrel245->getIndex(ord244, false);
  
    }
    ReadTask201(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c44 = v_constb49bea2fcccd8f4301a347ed;
      u64 v_c45 = v_const66518c0c1b3a5a0b09ae2ef1;
      u64 v_c46 = v_const4a8acfc71441e0695ffcf5b3;
      u64 v_c47 = v_constc85eae03730a4f4cf1d66a0c;
      u64 v_c48 = v_const229c0b7aa8a7eb4055f5a3d0;
      u64 v_c49 = v_const576506f61f53440f1edd95d2;
      u64 v_c50 = v_const8ca682693a0738a0641c6956;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex180, std::array<u64,2>{v_c45, 0}, [&](const std::array<u64,2>& m246) {
        u64 v_c51 = m246[1];
        if (!slog::exists_probe<3,1>(lambdaindex181, std::array<u64,3>{v_c50, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex182, std::array<u64,2>{v_c44, 0})) return;
        if (!slog::exists_probe<2,1>(refindex183, std::array<u64,2>{v_c49, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex184, std::array<u64,3>{v_c49, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex185, std::array<u64,3>{v_c51, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex186, std::array<u64,2>{v_c48, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex187, std::array<u64,3>{v_c48, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex188, std::array<u64,3>{v_c47, 0, 0})) return;
        slog::join_probe<2,1>(refindex189, std::array<u64,2>{v_c50, 0}, [&](const std::array<u64,2>& m247) {
          u64 v_c52 = m247[1];
          slog::join_probe<3,2>(lambdaindex190, std::array<u64,3>{v_c50, v_c52, 0}, [&](const std::array<u64,3>& m248) {
            u64 v_c53 = m248[2];
            slog::join_probe<2,1>(refindex191, std::array<u64,2>{v_c44, 0}, [&](const std::array<u64,2>& m249) {
              u64 v_c54 = m249[1];
              if (!slog::exists_probe<3,1>(appindex192, std::array<u64,3>{v_c54, 0, 0})) return;
              slog::join_probe<2,1>(refindex193, std::array<u64,2>{v_c49, 0}, [&](const std::array<u64,2>& m250) {
                u64 v_c55 = m250[1];
                slog::join_probe<3,2>(lambdaindex194, std::array<u64,3>{v_c49, v_c55, 0}, [&](const std::array<u64,3>& m251) {
                  u64 v_c56 = m251[2];
                  slog::join_probe<3,2>(appindex195, std::array<u64,3>{v_c51, v_c56, 0}, [&](const std::array<u64,3>& m252) {
                    u64 v_c57 = m252[2];
                    slog::join_probe<2,1>(refindex196, std::array<u64,2>{v_c48, 0}, [&](const std::array<u64,2>& m253) {
                      u64 v_c58 = m253[1];
                      slog::join_probe<3,2>(lambdaindex197, std::array<u64,3>{v_c48, v_c58, 0}, [&](const std::array<u64,3>& m254) {
                        u64 v_c59 = m254[2];
                        slog::join_probe<3,2>(appindex198, std::array<u64,3>{v_c51, v_c59, 0}, [&](const std::array<u64,3>& m255) {
                          u64 v_c60 = m255[2];
                          slog::join_probe<3,1>(appindex199, std::array<u64,3>{v_c54, 0, 0}, [&](const std::array<u64,3>& m256) {
                            u64 v_c61 = m256[1]; u64 v_c62 = m256[2];
                            if (v_c54 != v_c61) return;
                            slog::join_probe<3,2>(lambdaindex200, std::array<u64,3>{v_c47, v_c62, 0}, [&](const std::array<u64,3>& m257) {
                              u64 v_c63 = m257[2];
                              ++_fires;
                              slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c46, v_c60}, std::array<u16,3>{1, 2, 0});
                            });
                          });
                        });
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
      s->addTaskSeeded(phase_read, new ReadTask201(db,b));
  // (crule (pre) (scan eval __t8XTs321 ea c) (body (exists $sup27994x83x0x0x1 (2 3 5 8 0 1 4 6 7 9) 3 __t8XTs321 c ea) (exists eval (2 0 1) 1 c) (exists eval_ans (0 1) 1 __t8XTs321) (exists app (2 0 1) 1 ea) (join $sup27994x83x0x0x0 (1 2 0 3) 2 c ea __t5GoB317 ef) (exists eval (1 2 0) 2 ef c) (exists eval (0 2 1) 2 __t5GoB317 c) (exists app (1 2 0) 2 ef ea) (join $sup27994x83x0x0x1 (0 2 3 5 7 1 4 6 8 9) 5 __t5GoB317 __t8XTs321 c ea ef __t1FV8318 cb eb va x) (join eval (0 2 1) 3 __t1FV8318 c ef) (join eval_ans (0 1) 2 __t8XTs321 va) (exists lambda (1 2 0) 2 x eb) (exists clo (2 0 1) 1 cb) (exists eval_ans (0 1) 1 __t1FV8318) (exists eval (1 2 0) 1 eb) (join eval (0 2 1) 2 __t5GoB317 c __t3MbO322) (join-old app (0 1 2) 3 (0 1 2) __t3MbO322 ef ea) (exists eval (1 2 0) 2 eb __t3MbO322) (join lambda (1 2 0) 2 x eb __t6vap319) (join clo (1 2 0) 2 __t6vap319 cb __t1oxE320) (join eval_ans (0 1) 2 __t1FV8318 __t1oxE320) (join-old eval (1 2 0) 2 (1 2 0) eb __t3MbO322 __t3H1A323) (join eval_ans (0 1) 1 __t3H1A323 v)) (head (emit eval_ans (0 1) __t5GoB317 v)) mcfa-counting.slog:84 #f)
  class ReadTask283 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup27994x83x0x0x1index258;  slog::Index** evalindex259;  slog::Index** eval_ansindex260;  slog::Index** appindex261;  slog::Index** $sup27994x83x0x0x0index262;  slog::Index** evalindex263;  slog::Index** evalindex264;  slog::Index** appindex265;  slog::Index** $sup27994x83x0x0x1index266;  slog::Index** evalindex267;  slog::Index** eval_ansindex268;  slog::Index** lambdaindex269;  slog::Index** cloindex270;  slog::Index** eval_ansindex271;  slog::Index** evalindex272;  slog::Index** evalindex273;  slog::Index** appindex274;  slog::Index** evalindex275;  slog::Index** lambdaindex276;  slog::Index** cloindex277;  slog::Index** eval_ansindex278;  slog::Index** evalindex279;  slog::Index** eval_ansindex280;  slog::Index** appdelta281;  slog::Index** evaldelta282;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord284({0, 1});
      slog::Relation* readrel285 = db->getRelation("eval_ans");
      head_index[0] = readrel285->getIndex(ord284, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord286({2, 3, 5, 8, 0, 1, 4, 6, 7, 9});
      slog::Relation* readrel287 = db->getRelation("$sup27994x83x0x0x1");
      $sup27994x83x0x0x1index258 = readrel287->getIndex(ord286, false);
      std::vector<u16> ord288({2, 0, 1});
      slog::Relation* readrel289 = db->getRelation("eval");
      evalindex259 = readrel289->getIndex(ord288, false);
      std::vector<u16> ord290({0, 1});
      slog::Relation* readrel291 = db->getRelation("eval_ans");
      eval_ansindex260 = readrel291->getIndex(ord290, false);
      std::vector<u16> ord292({2, 0, 1});
      slog::Relation* readrel293 = db->getRelation("app");
      appindex261 = readrel293->getIndex(ord292, false);
      std::vector<u16> ord294({1, 2, 0, 3});
      slog::Relation* readrel295 = db->getRelation("$sup27994x83x0x0x0");
      $sup27994x83x0x0x0index262 = readrel295->getIndex(ord294, false);
      std::vector<u16> ord296({1, 2, 0});
      slog::Relation* readrel297 = db->getRelation("eval");
      evalindex263 = readrel297->getIndex(ord296, false);
      std::vector<u16> ord298({0, 2, 1});
      slog::Relation* readrel299 = db->getRelation("eval");
      evalindex264 = readrel299->getIndex(ord298, false);
      std::vector<u16> ord300({1, 2, 0});
      slog::Relation* readrel301 = db->getRelation("app");
      appindex265 = readrel301->getIndex(ord300, false);
      std::vector<u16> ord302({0, 2, 3, 5, 7, 1, 4, 6, 8, 9});
      slog::Relation* readrel303 = db->getRelation("$sup27994x83x0x0x1");
      $sup27994x83x0x0x1index266 = readrel303->getIndex(ord302, false);
      std::vector<u16> ord304({0, 2, 1});
      slog::Relation* readrel305 = db->getRelation("eval");
      evalindex267 = readrel305->getIndex(ord304, false);
      std::vector<u16> ord306({0, 1});
      slog::Relation* readrel307 = db->getRelation("eval_ans");
      eval_ansindex268 = readrel307->getIndex(ord306, false);
      std::vector<u16> ord308({1, 2, 0});
      slog::Relation* readrel309 = db->getRelation("lambda");
      lambdaindex269 = readrel309->getIndex(ord308, false);
      std::vector<u16> ord310({2, 0, 1});
      slog::Relation* readrel311 = db->getRelation("clo");
      cloindex270 = readrel311->getIndex(ord310, false);
      std::vector<u16> ord312({0, 1});
      slog::Relation* readrel313 = db->getRelation("eval_ans");
      eval_ansindex271 = readrel313->getIndex(ord312, false);
      std::vector<u16> ord314({1, 2, 0});
      slog::Relation* readrel315 = db->getRelation("eval");
      evalindex272 = readrel315->getIndex(ord314, false);
      std::vector<u16> ord316({0, 2, 1});
      slog::Relation* readrel317 = db->getRelation("eval");
      evalindex273 = readrel317->getIndex(ord316, false);
      std::vector<u16> ord318({0, 1, 2});
      slog::Relation* readrel319 = db->getRelation("app");
      appindex274 = readrel319->getIndex(ord318, false);
      std::vector<u16> ord320({0, 1, 2});
      slog::Relation* readrel321 = db->getRelation("app");
      appdelta281 = readrel321->getIndex(ord320, true);
      std::vector<u16> ord322({1, 2, 0});
      slog::Relation* readrel323 = db->getRelation("eval");
      evalindex275 = readrel323->getIndex(ord322, false);
      std::vector<u16> ord324({1, 2, 0});
      slog::Relation* readrel325 = db->getRelation("lambda");
      lambdaindex276 = readrel325->getIndex(ord324, false);
      std::vector<u16> ord326({1, 2, 0});
      slog::Relation* readrel327 = db->getRelation("clo");
      cloindex277 = readrel327->getIndex(ord326, false);
      std::vector<u16> ord328({0, 1});
      slog::Relation* readrel329 = db->getRelation("eval_ans");
      eval_ansindex278 = readrel329->getIndex(ord328, false);
      std::vector<u16> ord330({1, 2, 0});
      slog::Relation* readrel331 = db->getRelation("eval");
      evalindex279 = readrel331->getIndex(ord330, false);
      std::vector<u16> ord332({1, 2, 0});
      slog::Relation* readrel333 = db->getRelation("eval");
      evaldelta282 = readrel333->getIndex(ord332, true);
      std::vector<u16> ord334({0, 1});
      slog::Relation* readrel335 = db->getRelation("eval_ans");
      eval_ansindex280 = readrel335->getIndex(ord334, false);
  
    }
    ReadTask283(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c64 = _t[0];
        u64 v_c2 = _t[1];
        u64 v_c3 = _t[2];
        if (!slog::exists_probe<10,3>($sup27994x83x0x0x1index258, std::array<u64,10>{v_c64, v_c3, v_c2, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(evalindex259, std::array<u64,3>{v_c3, 0, 0})) return;
        if (!slog::exists_probe<2,1>(eval_ansindex260, std::array<u64,2>{v_c64, 0})) return;
        if (!slog::exists_probe<3,1>(appindex261, std::array<u64,3>{v_c2, 0, 0})) return;
        slog::join_probe<4,2>($sup27994x83x0x0x0index262, std::array<u64,4>{v_c3, v_c2, 0, 0}, [&](const std::array<u64,4>& m336) {
          u64 v_c65 = m336[2]; u64 v_c1 = m336[3];
          if (!slog::exists_probe<3,2>(evalindex263, std::array<u64,3>{v_c1, v_c3, 0})) return;
          if (!slog::exists_probe<3,2>(evalindex264, std::array<u64,3>{v_c65, v_c3, 0})) return;
          if (!slog::exists_probe<3,2>(appindex265, std::array<u64,3>{v_c1, v_c2, 0})) return;
          slog::join_probe<10,5>($sup27994x83x0x0x1index266, std::array<u64,10>{v_c65, v_c64, v_c3, v_c2, v_c1, 0, 0, 0, 0, 0}, [&](const std::array<u64,10>& m337) {
            u64 v_c66 = m337[5]; u64 v_c67 = m337[6]; u64 v_c68 = m337[7]; u64 v_c69 = m337[8]; u64 v_c70 = m337[9];
            slog::join_probe<3,3>(evalindex267, std::array<u64,3>{v_c66, v_c3, v_c1}, [&](const std::array<u64,3>& m338) {
              slog::join_probe<2,2>(eval_ansindex268, std::array<u64,2>{v_c64, v_c69}, [&](const std::array<u64,2>& m339) {
                if (!slog::exists_probe<3,2>(lambdaindex269, std::array<u64,3>{v_c70, v_c68, 0})) return;
                if (!slog::exists_probe<3,1>(cloindex270, std::array<u64,3>{v_c67, 0, 0})) return;
                if (!slog::exists_probe<2,1>(eval_ansindex271, std::array<u64,2>{v_c66, 0})) return;
                if (!slog::exists_probe<3,1>(evalindex272, std::array<u64,3>{v_c68, 0, 0})) return;
                slog::join_probe<3,2>(evalindex273, std::array<u64,3>{v_c65, v_c3, 0}, [&](const std::array<u64,3>& m340) {
                  u64 v_c71 = m340[2];
                  slog::join_probe_old<3,3>(appindex274, appdelta281, std::array<u64,3>{v_c71, v_c1, v_c2}, [&](const std::array<u64,3>& m341) {
                    if (!slog::exists_probe<3,2>(evalindex275, std::array<u64,3>{v_c68, v_c71, 0})) return;
                    slog::join_probe<3,2>(lambdaindex276, std::array<u64,3>{v_c70, v_c68, 0}, [&](const std::array<u64,3>& m342) {
                      u64 v_c72 = m342[2];
                      slog::join_probe<3,2>(cloindex277, std::array<u64,3>{v_c72, v_c67, 0}, [&](const std::array<u64,3>& m343) {
                        u64 v_c73 = m343[2];
                        slog::join_probe<2,2>(eval_ansindex278, std::array<u64,2>{v_c66, v_c73}, [&](const std::array<u64,2>& m344) {
                          slog::join_probe_old<3,2>(evalindex279, evaldelta282, std::array<u64,3>{v_c68, v_c71, 0}, [&](const std::array<u64,3>& m345) {
                            u64 v_c74 = m345[2];
                            slog::join_probe<2,1>(eval_ansindex280, std::array<u64,2>{v_c74, 0}, [&](const std::array<u64,2>& m346) {
                              u64 v_c75 = m346[1];
                              ++_fires;
                              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c65, v_c75}, std::array<u16,2>{0, 1});
                            });
                          });
                        });
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
        ReadTask283* _cont = new ReadTask283(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask283(db,b), false);
  // (crule (pre) (scan temp9GbH416 ea eb ef) (body (join app (1 2 0) 2 ef ea __t2Zeb76)) (head (mkstruct eval (1 2 0) __0Nd9329 eb __t2Zeb76)) mcfa-counting.slog:84 #f)
  class ReadTask348 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex347;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("temp9GbH416");
      std::vector<u16> ord349({1, 2, 0});
      slog::Relation* readrel350 = db->getRelation("app");
      appindex347 = readrel350->getIndex(ord349, false);
  
    }
    ReadTask348(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c2 = _t[0];
        u64 v_c68 = _t[1];
        u64 v_c1 = _t[2];
        slog::join_probe<3,2>(appindex347, std::array<u64,3>{v_c1, v_c2, 0}, [&](const std::array<u64,3>& m351) {
          u64 v_c76 = m351[2];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c68, v_c76}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:84", "delta:temp9GbH416", _fires);
  
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
  // (crule (pre (let __tconst7JVW192 const6cf13cc59dcbe759113f68a4) (let __tconst7B9N190 constcaa3ee5a2828a31924f6b39d) (let __tconst5wC2180 const970c20ea81b833e5b5a7accf) (let __tconst2ady176 constc40f204dda7ba4054abb9e74)) (probe lambda (1 2 0) 1 __tconst7JVW192 __t6W4v191 __t6Vw9193) (body (exists ref (1 0) 1 __tconst2ady176) (exists lambda (1 2 0) 1 __tconst2ady176) (exists ref (1 0) 1 __tconst5wC2180) (exists lambda (1 2 0) 1 __tconst5wC2180) (exists ref (1 0) 1 __tconst7JVW192) (exists ref (1 0) 1 __tconst7B9N190) (join lambda (0 1 2) 2 __t6W4v191 __tconst7B9N190 __t9pbS189) (join ref (1 0) 1 __tconst2ady176 __t3ZY4175) (join lambda (1 2 0) 2 __tconst2ady176 __t3ZY4175 __t1Ls4177) (join ref (1 0) 1 __tconst5wC2180 __t52sB179) (join lambda (1 2 0) 2 __tconst5wC2180 __t52sB179 __t6CST181) (join ref (1 0) 1 __tconst7JVW192 __t6fOY185) (exists app (1 2 0) 1 __t6fOY185) (join app (0 1 2) 2 __t9pbS189 __t6fOY185 __t2CTd186) (join app (0 1 2) 2 __t2CTd186 __t6fOY185 __t8oRJ183) (join ref (0 1) 2 __t8oRJ183 __tconst7B9N190)) (head (mkstruct app (1 2 0) __t5jf3194 __t6Vw9193 __t6CST181)) mcfa-counting.slog:301 #f)
  class ReadTask368 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** refindex352;  slog::Index** lambdaindex353;  slog::Index** refindex354;  slog::Index** lambdaindex355;  slog::Index** refindex356;  slog::Index** refindex357;  slog::Index** lambdaindex358;  slog::Index** refindex359;  slog::Index** lambdaindex360;  slog::Index** refindex361;  slog::Index** lambdaindex362;  slog::Index** refindex363;  slog::Index** appindex364;  slog::Index** appindex365;  slog::Index** appindex366;  slog::Index** refindex367;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord369({1, 2, 0});
      slog::Relation* readrel370 = db->getRelation("lambda");
      driver_index = readrel370->getIndex(ord369, true);
      std::vector<u16> ord371({1, 0});
      slog::Relation* readrel372 = db->getRelation("ref");
      refindex352 = readrel372->getIndex(ord371, false);
      std::vector<u16> ord373({1, 2, 0});
      slog::Relation* readrel374 = db->getRelation("lambda");
      lambdaindex353 = readrel374->getIndex(ord373, false);
      std::vector<u16> ord375({1, 0});
      slog::Relation* readrel376 = db->getRelation("ref");
      refindex354 = readrel376->getIndex(ord375, false);
      std::vector<u16> ord377({1, 2, 0});
      slog::Relation* readrel378 = db->getRelation("lambda");
      lambdaindex355 = readrel378->getIndex(ord377, false);
      std::vector<u16> ord379({1, 0});
      slog::Relation* readrel380 = db->getRelation("ref");
      refindex356 = readrel380->getIndex(ord379, false);
      std::vector<u16> ord381({1, 0});
      slog::Relation* readrel382 = db->getRelation("ref");
      refindex357 = readrel382->getIndex(ord381, false);
      std::vector<u16> ord383({0, 1, 2});
      slog::Relation* readrel384 = db->getRelation("lambda");
      lambdaindex358 = readrel384->getIndex(ord383, false);
      std::vector<u16> ord385({1, 0});
      slog::Relation* readrel386 = db->getRelation("ref");
      refindex359 = readrel386->getIndex(ord385, false);
      std::vector<u16> ord387({1, 2, 0});
      slog::Relation* readrel388 = db->getRelation("lambda");
      lambdaindex360 = readrel388->getIndex(ord387, false);
      std::vector<u16> ord389({1, 0});
      slog::Relation* readrel390 = db->getRelation("ref");
      refindex361 = readrel390->getIndex(ord389, false);
      std::vector<u16> ord391({1, 2, 0});
      slog::Relation* readrel392 = db->getRelation("lambda");
      lambdaindex362 = readrel392->getIndex(ord391, false);
      std::vector<u16> ord393({1, 0});
      slog::Relation* readrel394 = db->getRelation("ref");
      refindex363 = readrel394->getIndex(ord393, false);
      std::vector<u16> ord395({1, 2, 0});
      slog::Relation* readrel396 = db->getRelation("app");
      appindex364 = readrel396->getIndex(ord395, false);
      std::vector<u16> ord397({0, 1, 2});
      slog::Relation* readrel398 = db->getRelation("app");
      appindex365 = readrel398->getIndex(ord397, false);
      std::vector<u16> ord399({0, 1, 2});
      slog::Relation* readrel400 = db->getRelation("app");
      appindex366 = readrel400->getIndex(ord399, false);
      std::vector<u16> ord401({0, 1});
      slog::Relation* readrel402 = db->getRelation("ref");
      refindex367 = readrel402->getIndex(ord401, false);
  
    }
    ReadTask368(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c77 = v_const6cf13cc59dcbe759113f68a4;
      u64 v_c78 = v_constcaa3ee5a2828a31924f6b39d;
      u64 v_c79 = v_const970c20ea81b833e5b5a7accf;
      u64 v_c80 = v_constc40f204dda7ba4054abb9e74;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c77, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m403) {
        u64 v_c81 = m403[1];
        u64 v_c82 = m403[2];
        if (buckethash(v_c81) != bucket) return;
        if (!slog::exists_probe<2,1>(refindex352, std::array<u64,2>{v_c80, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex353, std::array<u64,3>{v_c80, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex354, std::array<u64,2>{v_c79, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex355, std::array<u64,3>{v_c79, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex356, std::array<u64,2>{v_c77, 0})) return;
        if (!slog::exists_probe<2,1>(refindex357, std::array<u64,2>{v_c78, 0})) return;
        slog::join_probe<3,2>(lambdaindex358, std::array<u64,3>{v_c81, v_c78, 0}, [&](const std::array<u64,3>& m404) {
          u64 v_c83 = m404[2];
          slog::join_probe<2,1>(refindex359, std::array<u64,2>{v_c80, 0}, [&](const std::array<u64,2>& m405) {
            u64 v_c84 = m405[1];
            slog::join_probe<3,2>(lambdaindex360, std::array<u64,3>{v_c80, v_c84, 0}, [&](const std::array<u64,3>& m406) {
              u64 v_c85 = m406[2];
              slog::join_probe<2,1>(refindex361, std::array<u64,2>{v_c79, 0}, [&](const std::array<u64,2>& m407) {
                u64 v_c86 = m407[1];
                slog::join_probe<3,2>(lambdaindex362, std::array<u64,3>{v_c79, v_c86, 0}, [&](const std::array<u64,3>& m408) {
                  u64 v_c87 = m408[2];
                  slog::join_probe<2,1>(refindex363, std::array<u64,2>{v_c77, 0}, [&](const std::array<u64,2>& m409) {
                    u64 v_c88 = m409[1];
                    if (!slog::exists_probe<3,1>(appindex364, std::array<u64,3>{v_c88, 0, 0})) return;
                    slog::join_probe<3,2>(appindex365, std::array<u64,3>{v_c83, v_c88, 0}, [&](const std::array<u64,3>& m410) {
                      u64 v_c89 = m410[2];
                      slog::join_probe<3,2>(appindex366, std::array<u64,3>{v_c89, v_c88, 0}, [&](const std::array<u64,3>& m411) {
                        u64 v_c90 = m411[2];
                        slog::join_probe<2,2>(refindex367, std::array<u64,2>{v_c90, v_c78}, [&](const std::array<u64,2>& m412) {
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
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:301", "delta:lambda", _fires);
  
      if (!_done)
      {
        ReadTask368* _cont = new ReadTask368(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask368(db,b), false);
  // (crule (pre) (scan eval_ans __t3H1A323 v) (body (join-old eval (0 2 1) 1 (0 2 1) __t3H1A323 __t3MbO322 eb) (exists $sup27994x83x0x0x1 (6 9 4 1 0 2 3 5 7 8) 1 eb) (exists lambda (2 0 1) 1 eb) (join-old eval (1 2 0) 1 (1 2 0) __t3MbO322 c __t5GoB317) (exists $sup27994x83x0x0x1 (0 3 6 5 7 1 2 4 8 9) 3 __t5GoB317 c eb) (exists eval (2 0 1) 1 c) (join-old $sup27994x83x0x0x0 (0 1 2 3) 2 (0 1 2 3) __t5GoB317 c ea ef) (exists eval (1 2 0) 2 ef c) (exists eval (1 2 0) 2 ea c) (exists app (0 1 2) 3 __t3MbO322 ef ea) (join-old $sup27994x83x0x0x1 (0 3 6 5 7 1 2 4 8 9) 5 (0 3 6 5 7 1 2 4 8 9) __t5GoB317 c eb ea ef __t1FV8318 __t8XTs321 cb va x) (join-old eval (0 2 1) 3 (0 2 1) __t1FV8318 c ef) (join-old eval (0 2 1) 3 (0 2 1) __t8XTs321 c ea) (join-old app (0 1 2) 3 (0 1 2) __t3MbO322 ef ea) (join eval_ans (0 1) 2 __t8XTs321 va) (exists clo (2 0 1) 1 cb) (exists eval_ans (0 1) 1 __t1FV8318) (join-old lambda (1 2 0) 2 (1 2 0) x eb __t6vap319) (join-old clo (1 2 0) 2 (1 2 0) __t6vap319 cb __t1oxE320) (join eval_ans (0 1) 2 __t1FV8318 __t1oxE320)) (head (emit eval_ans (0 1) __t5GoB317 v)) mcfa-counting.slog:84 #f)
  class ReadTask442 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex413;  slog::Index** $sup27994x83x0x0x1index414;  slog::Index** lambdaindex415;  slog::Index** evalindex416;  slog::Index** $sup27994x83x0x0x1index417;  slog::Index** evalindex418;  slog::Index** $sup27994x83x0x0x0index419;  slog::Index** evalindex420;  slog::Index** evalindex421;  slog::Index** appindex422;  slog::Index** $sup27994x83x0x0x1index423;  slog::Index** evalindex424;  slog::Index** evalindex425;  slog::Index** appindex426;  slog::Index** eval_ansindex427;  slog::Index** cloindex428;  slog::Index** eval_ansindex429;  slog::Index** lambdaindex430;  slog::Index** cloindex431;  slog::Index** eval_ansindex432;  slog::Index** evaldelta433;  slog::Index** evaldelta434;  slog::Index** $sup27994x83x0x0x0delta435;  slog::Index** $sup27994x83x0x0x1delta436;  slog::Index** evaldelta437;  slog::Index** evaldelta438;  slog::Index** appdelta439;  slog::Index** lambdadelta440;  slog::Index** clodelta441;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord443({0, 1});
      slog::Relation* readrel444 = db->getRelation("eval_ans");
      head_index[0] = readrel444->getIndex(ord443, false);
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord445({0, 2, 1});
      slog::Relation* readrel446 = db->getRelation("eval");
      evalindex413 = readrel446->getIndex(ord445, false);
      std::vector<u16> ord447({0, 2, 1});
      slog::Relation* readrel448 = db->getRelation("eval");
      evaldelta433 = readrel448->getIndex(ord447, true);
      std::vector<u16> ord449({6, 9, 4, 1, 0, 2, 3, 5, 7, 8});
      slog::Relation* readrel450 = db->getRelation("$sup27994x83x0x0x1");
      $sup27994x83x0x0x1index414 = readrel450->getIndex(ord449, false);
      std::vector<u16> ord451({2, 0, 1});
      slog::Relation* readrel452 = db->getRelation("lambda");
      lambdaindex415 = readrel452->getIndex(ord451, false);
      std::vector<u16> ord453({1, 2, 0});
      slog::Relation* readrel454 = db->getRelation("eval");
      evalindex416 = readrel454->getIndex(ord453, false);
      std::vector<u16> ord455({1, 2, 0});
      slog::Relation* readrel456 = db->getRelation("eval");
      evaldelta434 = readrel456->getIndex(ord455, true);
      std::vector<u16> ord457({0, 3, 6, 5, 7, 1, 2, 4, 8, 9});
      slog::Relation* readrel458 = db->getRelation("$sup27994x83x0x0x1");
      $sup27994x83x0x0x1index417 = readrel458->getIndex(ord457, false);
      std::vector<u16> ord459({2, 0, 1});
      slog::Relation* readrel460 = db->getRelation("eval");
      evalindex418 = readrel460->getIndex(ord459, false);
      std::vector<u16> ord461({0, 1, 2, 3});
      slog::Relation* readrel462 = db->getRelation("$sup27994x83x0x0x0");
      $sup27994x83x0x0x0index419 = readrel462->getIndex(ord461, false);
      std::vector<u16> ord463({0, 1, 2, 3});
      slog::Relation* readrel464 = db->getRelation("$sup27994x83x0x0x0");
      $sup27994x83x0x0x0delta435 = readrel464->getIndex(ord463, true);
      std::vector<u16> ord465({1, 2, 0});
      slog::Relation* readrel466 = db->getRelation("eval");
      evalindex420 = readrel466->getIndex(ord465, false);
      std::vector<u16> ord467({1, 2, 0});
      slog::Relation* readrel468 = db->getRelation("eval");
      evalindex421 = readrel468->getIndex(ord467, false);
      std::vector<u16> ord469({0, 1, 2});
      slog::Relation* readrel470 = db->getRelation("app");
      appindex422 = readrel470->getIndex(ord469, false);
      std::vector<u16> ord471({0, 3, 6, 5, 7, 1, 2, 4, 8, 9});
      slog::Relation* readrel472 = db->getRelation("$sup27994x83x0x0x1");
      $sup27994x83x0x0x1index423 = readrel472->getIndex(ord471, false);
      std::vector<u16> ord473({0, 3, 6, 5, 7, 1, 2, 4, 8, 9});
      slog::Relation* readrel474 = db->getRelation("$sup27994x83x0x0x1");
      $sup27994x83x0x0x1delta436 = readrel474->getIndex(ord473, true);
      std::vector<u16> ord475({0, 2, 1});
      slog::Relation* readrel476 = db->getRelation("eval");
      evalindex424 = readrel476->getIndex(ord475, false);
      std::vector<u16> ord477({0, 2, 1});
      slog::Relation* readrel478 = db->getRelation("eval");
      evaldelta437 = readrel478->getIndex(ord477, true);
      std::vector<u16> ord479({0, 2, 1});
      slog::Relation* readrel480 = db->getRelation("eval");
      evalindex425 = readrel480->getIndex(ord479, false);
      std::vector<u16> ord481({0, 2, 1});
      slog::Relation* readrel482 = db->getRelation("eval");
      evaldelta438 = readrel482->getIndex(ord481, true);
      std::vector<u16> ord483({0, 1, 2});
      slog::Relation* readrel484 = db->getRelation("app");
      appindex426 = readrel484->getIndex(ord483, false);
      std::vector<u16> ord485({0, 1, 2});
      slog::Relation* readrel486 = db->getRelation("app");
      appdelta439 = readrel486->getIndex(ord485, true);
      std::vector<u16> ord487({0, 1});
      slog::Relation* readrel488 = db->getRelation("eval_ans");
      eval_ansindex427 = readrel488->getIndex(ord487, false);
      std::vector<u16> ord489({2, 0, 1});
      slog::Relation* readrel490 = db->getRelation("clo");
      cloindex428 = readrel490->getIndex(ord489, false);
      std::vector<u16> ord491({0, 1});
      slog::Relation* readrel492 = db->getRelation("eval_ans");
      eval_ansindex429 = readrel492->getIndex(ord491, false);
      std::vector<u16> ord493({1, 2, 0});
      slog::Relation* readrel494 = db->getRelation("lambda");
      lambdaindex430 = readrel494->getIndex(ord493, false);
      std::vector<u16> ord495({1, 2, 0});
      slog::Relation* readrel496 = db->getRelation("lambda");
      lambdadelta440 = readrel496->getIndex(ord495, true);
      std::vector<u16> ord497({1, 2, 0});
      slog::Relation* readrel498 = db->getRelation("clo");
      cloindex431 = readrel498->getIndex(ord497, false);
      std::vector<u16> ord499({1, 2, 0});
      slog::Relation* readrel500 = db->getRelation("clo");
      clodelta441 = readrel500->getIndex(ord499, true);
      std::vector<u16> ord501({0, 1});
      slog::Relation* readrel502 = db->getRelation("eval_ans");
      eval_ansindex432 = readrel502->getIndex(ord501, false);
  
    }
    ReadTask442(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c75 = _t[1];
        slog::join_probe_old<3,1>(evalindex413, evaldelta433, std::array<u64,3>{v_c74, 0, 0}, [&](const std::array<u64,3>& m503) {
          u64 v_c71 = m503[1]; u64 v_c68 = m503[2];
          if (!slog::exists_probe<10,1>($sup27994x83x0x0x1index414, std::array<u64,10>{v_c68, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
          if (!slog::exists_probe<3,1>(lambdaindex415, std::array<u64,3>{v_c68, 0, 0})) return;
          slog::join_probe_old<3,1>(evalindex416, evaldelta434, std::array<u64,3>{v_c71, 0, 0}, [&](const std::array<u64,3>& m504) {
            u64 v_c3 = m504[1]; u64 v_c65 = m504[2];
            if (!slog::exists_probe<10,3>($sup27994x83x0x0x1index417, std::array<u64,10>{v_c65, v_c3, v_c68, 0, 0, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<3,1>(evalindex418, std::array<u64,3>{v_c3, 0, 0})) return;
            slog::join_probe_old<4,2>($sup27994x83x0x0x0index419, $sup27994x83x0x0x0delta435, std::array<u64,4>{v_c65, v_c3, 0, 0}, [&](const std::array<u64,4>& m505) {
              u64 v_c2 = m505[2]; u64 v_c1 = m505[3];
              if (!slog::exists_probe<3,2>(evalindex420, std::array<u64,3>{v_c1, v_c3, 0})) return;
              if (!slog::exists_probe<3,2>(evalindex421, std::array<u64,3>{v_c2, v_c3, 0})) return;
              if (!slog::exists_probe<3,3>(appindex422, std::array<u64,3>{v_c71, v_c1, v_c2})) return;
              slog::join_probe_old<10,5>($sup27994x83x0x0x1index423, $sup27994x83x0x0x1delta436, std::array<u64,10>{v_c65, v_c3, v_c68, v_c2, v_c1, 0, 0, 0, 0, 0}, [&](const std::array<u64,10>& m506) {
                u64 v_c66 = m506[5]; u64 v_c64 = m506[6]; u64 v_c67 = m506[7]; u64 v_c69 = m506[8]; u64 v_c70 = m506[9];
                slog::join_probe_old<3,3>(evalindex424, evaldelta437, std::array<u64,3>{v_c66, v_c3, v_c1}, [&](const std::array<u64,3>& m507) {
                  slog::join_probe_old<3,3>(evalindex425, evaldelta438, std::array<u64,3>{v_c64, v_c3, v_c2}, [&](const std::array<u64,3>& m508) {
                    slog::join_probe_old<3,3>(appindex426, appdelta439, std::array<u64,3>{v_c71, v_c1, v_c2}, [&](const std::array<u64,3>& m509) {
                      slog::join_probe<2,2>(eval_ansindex427, std::array<u64,2>{v_c64, v_c69}, [&](const std::array<u64,2>& m510) {
                        if (!slog::exists_probe<3,1>(cloindex428, std::array<u64,3>{v_c67, 0, 0})) return;
                        if (!slog::exists_probe<2,1>(eval_ansindex429, std::array<u64,2>{v_c66, 0})) return;
                        slog::join_probe_old<3,2>(lambdaindex430, lambdadelta440, std::array<u64,3>{v_c70, v_c68, 0}, [&](const std::array<u64,3>& m511) {
                          u64 v_c72 = m511[2];
                          slog::join_probe_old<3,2>(cloindex431, clodelta441, std::array<u64,3>{v_c72, v_c67, 0}, [&](const std::array<u64,3>& m512) {
                            u64 v_c73 = m512[2];
                            slog::join_probe<2,2>(eval_ansindex432, std::array<u64,2>{v_c66, v_c73}, [&](const std::array<u64,2>& m513) {
                              ++_fires;
                              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c65, v_c75}, std::array<u16,2>{0, 1});
                            });
                          });
                        });
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
        ReadTask442* _cont = new ReadTask442(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask442(db,b), false);
  // (crule (pre (let __tconst8eg8132 const361d5df359e0d7681220d09d) (let __tconst0zC2144 const4e3b5454cf93e32fad90650d) (let __tconst8xRt151 const3a82152bd1402931076fe2d7) (let __tconst3Taj142 constdc1bb6655fb38bdb032e3754)) (seeded) (body (join ref (1 0) 1 __tconst8eg8132 __t19JM131) (exists ref (1 0) 1 __tconst8xRt151) (exists ref (1 0) 1 __tconst3Taj142) (exists ref (1 0) 1 __tconst0zC2144) (exists lambda (1 2 0) 1 __tconst8xRt151) (exists lambda (1 2 0) 1 __tconst3Taj142) (exists lambda (1 2 0) 1 __tconst0zC2144) (join lambda (1 2 0) 2 __tconst8eg8132 __t19JM131 __t4DXA133) (exists app (2 0 1) 1 __t4DXA133) (join ref (1 0) 1 __tconst8xRt151 __t1g2P147) (exists app (1 2 0) 1 __t1g2P147) (join ref (1 0) 1 __tconst3Taj142 __t93Xi135) (exists app (2 0 1) 1 __t93Xi135) (join ref (1 0) 1 __tconst0zC2144 __t7VSc137) (exists app (1 2 0) 1 __t7VSc137) (join app (1 2 0) 1 __t1g2P147 dup1Fsi413 __t9UZN150) (eq __t1g2P147 dup1Fsi413) (join lambda (1 2 0) 2 __tconst8xRt151 __t9UZN150 __t2nYy152) (exists app (1 2 0) 1 __t2nYy152) (join app (1 2 0) 1 __t7VSc137 dup9Kem414 __t8dYW140) (eq __t7VSc137 dup9Kem414) (join app (1 2 0) 2 __t8dYW140 __t93Xi135 __t25NQ141) (join lambda (1 2 0) 2 __tconst3Taj142 __t25NQ141 __t2Ce3143) (join lambda (1 2 0) 2 __tconst0zC2144 __t2Ce3143 __t6t5O145) (join app (1 2 0) 2 __t2nYy152 __t6t5O145 __t6Ups153) (join app (1 2 0) 2 __t6Ups153 __t4DXA133 __t6KrY154)) (head (emit program (0) __t6KrY154)) mcfa-counting.slog:224 #f)
  class ReadTask538 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex514;  slog::Index** refindex515;  slog::Index** refindex516;  slog::Index** refindex517;  slog::Index** lambdaindex518;  slog::Index** lambdaindex519;  slog::Index** lambdaindex520;  slog::Index** lambdaindex521;  slog::Index** appindex522;  slog::Index** refindex523;  slog::Index** appindex524;  slog::Index** refindex525;  slog::Index** appindex526;  slog::Index** refindex527;  slog::Index** appindex528;  slog::Index** appindex529;  slog::Index** lambdaindex530;  slog::Index** appindex531;  slog::Index** appindex532;  slog::Index** appindex533;  slog::Index** lambdaindex534;  slog::Index** lambdaindex535;  slog::Index** appindex536;  slog::Index** appindex537;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("program");
      std::vector<u16> ord539({0});
      slog::Relation* readrel540 = db->getRelation("program");
      head_index[0] = readrel540->getIndex(ord539, false);
      std::vector<u16> ord541({1, 0});
      slog::Relation* readrel542 = db->getRelation("ref");
      refindex514 = readrel542->getIndex(ord541, false);
      std::vector<u16> ord543({1, 0});
      slog::Relation* readrel544 = db->getRelation("ref");
      refindex515 = readrel544->getIndex(ord543, false);
      std::vector<u16> ord545({1, 0});
      slog::Relation* readrel546 = db->getRelation("ref");
      refindex516 = readrel546->getIndex(ord545, false);
      std::vector<u16> ord547({1, 0});
      slog::Relation* readrel548 = db->getRelation("ref");
      refindex517 = readrel548->getIndex(ord547, false);
      std::vector<u16> ord549({1, 2, 0});
      slog::Relation* readrel550 = db->getRelation("lambda");
      lambdaindex518 = readrel550->getIndex(ord549, false);
      std::vector<u16> ord551({1, 2, 0});
      slog::Relation* readrel552 = db->getRelation("lambda");
      lambdaindex519 = readrel552->getIndex(ord551, false);
      std::vector<u16> ord553({1, 2, 0});
      slog::Relation* readrel554 = db->getRelation("lambda");
      lambdaindex520 = readrel554->getIndex(ord553, false);
      std::vector<u16> ord555({1, 2, 0});
      slog::Relation* readrel556 = db->getRelation("lambda");
      lambdaindex521 = readrel556->getIndex(ord555, false);
      std::vector<u16> ord557({2, 0, 1});
      slog::Relation* readrel558 = db->getRelation("app");
      appindex522 = readrel558->getIndex(ord557, false);
      std::vector<u16> ord559({1, 0});
      slog::Relation* readrel560 = db->getRelation("ref");
      refindex523 = readrel560->getIndex(ord559, false);
      std::vector<u16> ord561({1, 2, 0});
      slog::Relation* readrel562 = db->getRelation("app");
      appindex524 = readrel562->getIndex(ord561, false);
      std::vector<u16> ord563({1, 0});
      slog::Relation* readrel564 = db->getRelation("ref");
      refindex525 = readrel564->getIndex(ord563, false);
      std::vector<u16> ord565({2, 0, 1});
      slog::Relation* readrel566 = db->getRelation("app");
      appindex526 = readrel566->getIndex(ord565, false);
      std::vector<u16> ord567({1, 0});
      slog::Relation* readrel568 = db->getRelation("ref");
      refindex527 = readrel568->getIndex(ord567, false);
      std::vector<u16> ord569({1, 2, 0});
      slog::Relation* readrel570 = db->getRelation("app");
      appindex528 = readrel570->getIndex(ord569, false);
      std::vector<u16> ord571({1, 2, 0});
      slog::Relation* readrel572 = db->getRelation("app");
      appindex529 = readrel572->getIndex(ord571, false);
      std::vector<u16> ord573({1, 2, 0});
      slog::Relation* readrel574 = db->getRelation("lambda");
      lambdaindex530 = readrel574->getIndex(ord573, false);
      std::vector<u16> ord575({1, 2, 0});
      slog::Relation* readrel576 = db->getRelation("app");
      appindex531 = readrel576->getIndex(ord575, false);
      std::vector<u16> ord577({1, 2, 0});
      slog::Relation* readrel578 = db->getRelation("app");
      appindex532 = readrel578->getIndex(ord577, false);
      std::vector<u16> ord579({1, 2, 0});
      slog::Relation* readrel580 = db->getRelation("app");
      appindex533 = readrel580->getIndex(ord579, false);
      std::vector<u16> ord581({1, 2, 0});
      slog::Relation* readrel582 = db->getRelation("lambda");
      lambdaindex534 = readrel582->getIndex(ord581, false);
      std::vector<u16> ord583({1, 2, 0});
      slog::Relation* readrel584 = db->getRelation("lambda");
      lambdaindex535 = readrel584->getIndex(ord583, false);
      std::vector<u16> ord585({1, 2, 0});
      slog::Relation* readrel586 = db->getRelation("app");
      appindex536 = readrel586->getIndex(ord585, false);
      std::vector<u16> ord587({1, 2, 0});
      slog::Relation* readrel588 = db->getRelation("app");
      appindex537 = readrel588->getIndex(ord587, false);
  
    }
    ReadTask538(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c91 = v_const361d5df359e0d7681220d09d;
      u64 v_c92 = v_const4e3b5454cf93e32fad90650d;
      u64 v_c93 = v_const3a82152bd1402931076fe2d7;
      u64 v_c94 = v_constdc1bb6655fb38bdb032e3754;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex514, std::array<u64,2>{v_c91, 0}, [&](const std::array<u64,2>& m589) {
        u64 v_c95 = m589[1];
        if (!slog::exists_probe<2,1>(refindex515, std::array<u64,2>{v_c93, 0})) return;
        if (!slog::exists_probe<2,1>(refindex516, std::array<u64,2>{v_c94, 0})) return;
        if (!slog::exists_probe<2,1>(refindex517, std::array<u64,2>{v_c92, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex518, std::array<u64,3>{v_c93, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex519, std::array<u64,3>{v_c94, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex520, std::array<u64,3>{v_c92, 0, 0})) return;
        slog::join_probe<3,2>(lambdaindex521, std::array<u64,3>{v_c91, v_c95, 0}, [&](const std::array<u64,3>& m590) {
          u64 v_c96 = m590[2];
          if (!slog::exists_probe<3,1>(appindex522, std::array<u64,3>{v_c96, 0, 0})) return;
          slog::join_probe<2,1>(refindex523, std::array<u64,2>{v_c93, 0}, [&](const std::array<u64,2>& m591) {
            u64 v_c97 = m591[1];
            if (!slog::exists_probe<3,1>(appindex524, std::array<u64,3>{v_c97, 0, 0})) return;
            slog::join_probe<2,1>(refindex525, std::array<u64,2>{v_c94, 0}, [&](const std::array<u64,2>& m592) {
              u64 v_c98 = m592[1];
              if (!slog::exists_probe<3,1>(appindex526, std::array<u64,3>{v_c98, 0, 0})) return;
              slog::join_probe<2,1>(refindex527, std::array<u64,2>{v_c92, 0}, [&](const std::array<u64,2>& m593) {
                u64 v_c99 = m593[1];
                if (!slog::exists_probe<3,1>(appindex528, std::array<u64,3>{v_c99, 0, 0})) return;
                slog::join_probe<3,1>(appindex529, std::array<u64,3>{v_c97, 0, 0}, [&](const std::array<u64,3>& m594) {
                  u64 v_c100 = m594[1]; u64 v_c101 = m594[2];
                  if (v_c97 != v_c100) return;
                  slog::join_probe<3,2>(lambdaindex530, std::array<u64,3>{v_c93, v_c101, 0}, [&](const std::array<u64,3>& m595) {
                    u64 v_c102 = m595[2];
                    if (!slog::exists_probe<3,1>(appindex531, std::array<u64,3>{v_c102, 0, 0})) return;
                    slog::join_probe<3,1>(appindex532, std::array<u64,3>{v_c99, 0, 0}, [&](const std::array<u64,3>& m596) {
                      u64 v_c103 = m596[1]; u64 v_c104 = m596[2];
                      if (v_c99 != v_c103) return;
                      slog::join_probe<3,2>(appindex533, std::array<u64,3>{v_c104, v_c98, 0}, [&](const std::array<u64,3>& m597) {
                        u64 v_c105 = m597[2];
                        slog::join_probe<3,2>(lambdaindex534, std::array<u64,3>{v_c94, v_c105, 0}, [&](const std::array<u64,3>& m598) {
                          u64 v_c106 = m598[2];
                          slog::join_probe<3,2>(lambdaindex535, std::array<u64,3>{v_c92, v_c106, 0}, [&](const std::array<u64,3>& m599) {
                            u64 v_c107 = m599[2];
                            slog::join_probe<3,2>(appindex536, std::array<u64,3>{v_c102, v_c107, 0}, [&](const std::array<u64,3>& m600) {
                              u64 v_c108 = m600[2];
                              slog::join_probe<3,2>(appindex537, std::array<u64,3>{v_c108, v_c96, 0}, [&](const std::array<u64,3>& m601) {
                                u64 v_c109 = m601[2];
                                ++_fires;
                                slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c109}, std::array<u16,1>{0});
                              });
                            });
                          });
                        });
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
      s->addTaskSeeded(phase_read, new ReadTask538(db,b));
  // (crule (pre) (scan lambda __t6vap319 x eb) (body (exists $sup27994x83x0x0x1 (6 9 4 1 0 2 3 5 7 8) 2 eb x) (exists eval (1 2 0) 1 eb) (join-old clo (1 2 0) 1 (1 2 0) __t6vap319 cb __t1oxE320) (exists $sup27994x83x0x0x1 (6 9 4 1 0 2 3 5 7 8) 3 eb x cb) (join eval_ans (1 0) 1 __t1oxE320 __t1FV8318) (join $sup27994x83x0x0x1 (6 9 4 1 0 2 3 5 7 8) 4 eb x cb __t1FV8318 __t5GoB317 __t8XTs321 c ea ef va) (join $sup27994x83x0x0x0 (0 1 2 3) 4 __t5GoB317 c ea ef) (join eval (0 2 1) 3 __t1FV8318 c ef) (join-old eval (0 2 1) 3 (0 2 1) __t8XTs321 c ea) (join eval_ans (0 1) 2 __t8XTs321 va) (exists app (1 2 0) 2 ef ea) (join eval (0 2 1) 2 __t5GoB317 c __t3MbO322) (join-old app (0 1 2) 3 (0 1 2) __t3MbO322 ef ea) (join-old eval (1 2 0) 2 (1 2 0) eb __t3MbO322 __t3H1A323) (join eval_ans (0 1) 1 __t3H1A323 v)) (head (emit eval_ans (0 1) __t5GoB317 v)) mcfa-counting.slog:84 #f)
  class ReadTask621 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup27994x83x0x0x1index602;  slog::Index** evalindex603;  slog::Index** cloindex604;  slog::Index** $sup27994x83x0x0x1index605;  slog::Index** eval_ansindex606;  slog::Index** $sup27994x83x0x0x1index607;  slog::Index** $sup27994x83x0x0x0index608;  slog::Index** evalindex609;  slog::Index** evalindex610;  slog::Index** eval_ansindex611;  slog::Index** appindex612;  slog::Index** evalindex613;  slog::Index** appindex614;  slog::Index** evalindex615;  slog::Index** eval_ansindex616;  slog::Index** clodelta617;  slog::Index** evaldelta618;  slog::Index** appdelta619;  slog::Index** evaldelta620;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord622({0, 1});
      slog::Relation* readrel623 = db->getRelation("eval_ans");
      head_index[0] = readrel623->getIndex(ord622, false);
      outer_rel = db->getRelation("lambda");
      std::vector<u16> ord624({6, 9, 4, 1, 0, 2, 3, 5, 7, 8});
      slog::Relation* readrel625 = db->getRelation("$sup27994x83x0x0x1");
      $sup27994x83x0x0x1index602 = readrel625->getIndex(ord624, false);
      std::vector<u16> ord626({1, 2, 0});
      slog::Relation* readrel627 = db->getRelation("eval");
      evalindex603 = readrel627->getIndex(ord626, false);
      std::vector<u16> ord628({1, 2, 0});
      slog::Relation* readrel629 = db->getRelation("clo");
      cloindex604 = readrel629->getIndex(ord628, false);
      std::vector<u16> ord630({1, 2, 0});
      slog::Relation* readrel631 = db->getRelation("clo");
      clodelta617 = readrel631->getIndex(ord630, true);
      std::vector<u16> ord632({6, 9, 4, 1, 0, 2, 3, 5, 7, 8});
      slog::Relation* readrel633 = db->getRelation("$sup27994x83x0x0x1");
      $sup27994x83x0x0x1index605 = readrel633->getIndex(ord632, false);
      std::vector<u16> ord634({1, 0});
      slog::Relation* readrel635 = db->getRelation("eval_ans");
      eval_ansindex606 = readrel635->getIndex(ord634, false);
      std::vector<u16> ord636({6, 9, 4, 1, 0, 2, 3, 5, 7, 8});
      slog::Relation* readrel637 = db->getRelation("$sup27994x83x0x0x1");
      $sup27994x83x0x0x1index607 = readrel637->getIndex(ord636, false);
      std::vector<u16> ord638({0, 1, 2, 3});
      slog::Relation* readrel639 = db->getRelation("$sup27994x83x0x0x0");
      $sup27994x83x0x0x0index608 = readrel639->getIndex(ord638, false);
      std::vector<u16> ord640({0, 2, 1});
      slog::Relation* readrel641 = db->getRelation("eval");
      evalindex609 = readrel641->getIndex(ord640, false);
      std::vector<u16> ord642({0, 2, 1});
      slog::Relation* readrel643 = db->getRelation("eval");
      evalindex610 = readrel643->getIndex(ord642, false);
      std::vector<u16> ord644({0, 2, 1});
      slog::Relation* readrel645 = db->getRelation("eval");
      evaldelta618 = readrel645->getIndex(ord644, true);
      std::vector<u16> ord646({0, 1});
      slog::Relation* readrel647 = db->getRelation("eval_ans");
      eval_ansindex611 = readrel647->getIndex(ord646, false);
      std::vector<u16> ord648({1, 2, 0});
      slog::Relation* readrel649 = db->getRelation("app");
      appindex612 = readrel649->getIndex(ord648, false);
      std::vector<u16> ord650({0, 2, 1});
      slog::Relation* readrel651 = db->getRelation("eval");
      evalindex613 = readrel651->getIndex(ord650, false);
      std::vector<u16> ord652({0, 1, 2});
      slog::Relation* readrel653 = db->getRelation("app");
      appindex614 = readrel653->getIndex(ord652, false);
      std::vector<u16> ord654({0, 1, 2});
      slog::Relation* readrel655 = db->getRelation("app");
      appdelta619 = readrel655->getIndex(ord654, true);
      std::vector<u16> ord656({1, 2, 0});
      slog::Relation* readrel657 = db->getRelation("eval");
      evalindex615 = readrel657->getIndex(ord656, false);
      std::vector<u16> ord658({1, 2, 0});
      slog::Relation* readrel659 = db->getRelation("eval");
      evaldelta620 = readrel659->getIndex(ord658, true);
      std::vector<u16> ord660({0, 1});
      slog::Relation* readrel661 = db->getRelation("eval_ans");
      eval_ansindex616 = readrel661->getIndex(ord660, false);
  
    }
    ReadTask621(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c70 = _t[1];
        u64 v_c68 = _t[2];
        if (!slog::exists_probe<10,2>($sup27994x83x0x0x1index602, std::array<u64,10>{v_c68, v_c70, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(evalindex603, std::array<u64,3>{v_c68, 0, 0})) return;
        slog::join_probe_old<3,1>(cloindex604, clodelta617, std::array<u64,3>{v_c72, 0, 0}, [&](const std::array<u64,3>& m662) {
          u64 v_c67 = m662[1]; u64 v_c73 = m662[2];
          if (!slog::exists_probe<10,3>($sup27994x83x0x0x1index605, std::array<u64,10>{v_c68, v_c70, v_c67, 0, 0, 0, 0, 0, 0, 0})) return;
          slog::join_probe<2,1>(eval_ansindex606, std::array<u64,2>{v_c73, 0}, [&](const std::array<u64,2>& m663) {
            u64 v_c66 = m663[1];
            slog::join_probe<10,4>($sup27994x83x0x0x1index607, std::array<u64,10>{v_c68, v_c70, v_c67, v_c66, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,10>& m664) {
              u64 v_c65 = m664[4]; u64 v_c64 = m664[5]; u64 v_c3 = m664[6]; u64 v_c2 = m664[7]; u64 v_c1 = m664[8]; u64 v_c69 = m664[9];
              slog::join_probe<4,4>($sup27994x83x0x0x0index608, std::array<u64,4>{v_c65, v_c3, v_c2, v_c1}, [&](const std::array<u64,4>& m665) {
                slog::join_probe<3,3>(evalindex609, std::array<u64,3>{v_c66, v_c3, v_c1}, [&](const std::array<u64,3>& m666) {
                  slog::join_probe_old<3,3>(evalindex610, evaldelta618, std::array<u64,3>{v_c64, v_c3, v_c2}, [&](const std::array<u64,3>& m667) {
                    slog::join_probe<2,2>(eval_ansindex611, std::array<u64,2>{v_c64, v_c69}, [&](const std::array<u64,2>& m668) {
                      if (!slog::exists_probe<3,2>(appindex612, std::array<u64,3>{v_c1, v_c2, 0})) return;
                      slog::join_probe<3,2>(evalindex613, std::array<u64,3>{v_c65, v_c3, 0}, [&](const std::array<u64,3>& m669) {
                        u64 v_c71 = m669[2];
                        slog::join_probe_old<3,3>(appindex614, appdelta619, std::array<u64,3>{v_c71, v_c1, v_c2}, [&](const std::array<u64,3>& m670) {
                          slog::join_probe_old<3,2>(evalindex615, evaldelta620, std::array<u64,3>{v_c68, v_c71, 0}, [&](const std::array<u64,3>& m671) {
                            u64 v_c74 = m671[2];
                            slog::join_probe<2,1>(eval_ansindex616, std::array<u64,2>{v_c74, 0}, [&](const std::array<u64,2>& m672) {
                              u64 v_c75 = m672[1];
                              ++_fires;
                              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c65, v_c75}, std::array<u16,2>{0, 1});
                            });
                          });
                        });
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
  
      if (_fires) db->bumpFires("mcfa-counting.slog:84", "delta:lambda", _fires);
  
      if (!_done)
      {
        ReadTask621* _cont = new ReadTask621(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask621(db,b), false);
  // (crule (pre) (scan eval __t3H1A323 eb __t3MbO322) (body (exists eval (1 2 0) 1 __t3MbO322) (exists $sup27994x83x0x0x1 (6 9 4 1 0 2 3 5 7 8) 1 eb) (exists lambda (2 0 1) 1 eb) (join eval_ans (0 1) 1 __t3H1A323 v) (join eval (1 2 0) 1 __t3MbO322 c __t5GoB317) (exists $sup27994x83x0x0x1 (0 3 6 5 7 1 2 4 8 9) 3 __t5GoB317 c eb) (exists eval (2 0 1) 1 c) (join $sup27994x83x0x0x0 (0 1 2 3) 2 __t5GoB317 c ea ef) (exists eval (1 2 0) 2 ef c) (exists eval (1 2 0) 2 ea c) (exists app (0 1 2) 3 __t3MbO322 ef ea) (join $sup27994x83x0x0x1 (0 3 6 5 7 1 2 4 8 9) 5 __t5GoB317 c eb ea ef __t1FV8318 __t8XTs321 cb va x) (join eval (0 2 1) 3 __t1FV8318 c ef) (join eval (0 2 1) 3 __t8XTs321 c ea) (join app (0 1 2) 3 __t3MbO322 ef ea) (join eval_ans (0 1) 2 __t8XTs321 va) (exists clo (2 0 1) 1 cb) (exists eval_ans (0 1) 1 __t1FV8318) (join lambda (1 2 0) 2 x eb __t6vap319) (join clo (1 2 0) 2 __t6vap319 cb __t1oxE320) (join eval_ans (0 1) 2 __t1FV8318 __t1oxE320)) (head (emit eval_ans (0 1) __t5GoB317 v)) mcfa-counting.slog:84 #f)
  class ReadTask694 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex673;  slog::Index** $sup27994x83x0x0x1index674;  slog::Index** lambdaindex675;  slog::Index** eval_ansindex676;  slog::Index** evalindex677;  slog::Index** $sup27994x83x0x0x1index678;  slog::Index** evalindex679;  slog::Index** $sup27994x83x0x0x0index680;  slog::Index** evalindex681;  slog::Index** evalindex682;  slog::Index** appindex683;  slog::Index** $sup27994x83x0x0x1index684;  slog::Index** evalindex685;  slog::Index** evalindex686;  slog::Index** appindex687;  slog::Index** eval_ansindex688;  slog::Index** cloindex689;  slog::Index** eval_ansindex690;  slog::Index** lambdaindex691;  slog::Index** cloindex692;  slog::Index** eval_ansindex693;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord695({0, 1});
      slog::Relation* readrel696 = db->getRelation("eval_ans");
      head_index[0] = readrel696->getIndex(ord695, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord697({1, 2, 0});
      slog::Relation* readrel698 = db->getRelation("eval");
      evalindex673 = readrel698->getIndex(ord697, false);
      std::vector<u16> ord699({6, 9, 4, 1, 0, 2, 3, 5, 7, 8});
      slog::Relation* readrel700 = db->getRelation("$sup27994x83x0x0x1");
      $sup27994x83x0x0x1index674 = readrel700->getIndex(ord699, false);
      std::vector<u16> ord701({2, 0, 1});
      slog::Relation* readrel702 = db->getRelation("lambda");
      lambdaindex675 = readrel702->getIndex(ord701, false);
      std::vector<u16> ord703({0, 1});
      slog::Relation* readrel704 = db->getRelation("eval_ans");
      eval_ansindex676 = readrel704->getIndex(ord703, false);
      std::vector<u16> ord705({1, 2, 0});
      slog::Relation* readrel706 = db->getRelation("eval");
      evalindex677 = readrel706->getIndex(ord705, false);
      std::vector<u16> ord707({0, 3, 6, 5, 7, 1, 2, 4, 8, 9});
      slog::Relation* readrel708 = db->getRelation("$sup27994x83x0x0x1");
      $sup27994x83x0x0x1index678 = readrel708->getIndex(ord707, false);
      std::vector<u16> ord709({2, 0, 1});
      slog::Relation* readrel710 = db->getRelation("eval");
      evalindex679 = readrel710->getIndex(ord709, false);
      std::vector<u16> ord711({0, 1, 2, 3});
      slog::Relation* readrel712 = db->getRelation("$sup27994x83x0x0x0");
      $sup27994x83x0x0x0index680 = readrel712->getIndex(ord711, false);
      std::vector<u16> ord713({1, 2, 0});
      slog::Relation* readrel714 = db->getRelation("eval");
      evalindex681 = readrel714->getIndex(ord713, false);
      std::vector<u16> ord715({1, 2, 0});
      slog::Relation* readrel716 = db->getRelation("eval");
      evalindex682 = readrel716->getIndex(ord715, false);
      std::vector<u16> ord717({0, 1, 2});
      slog::Relation* readrel718 = db->getRelation("app");
      appindex683 = readrel718->getIndex(ord717, false);
      std::vector<u16> ord719({0, 3, 6, 5, 7, 1, 2, 4, 8, 9});
      slog::Relation* readrel720 = db->getRelation("$sup27994x83x0x0x1");
      $sup27994x83x0x0x1index684 = readrel720->getIndex(ord719, false);
      std::vector<u16> ord721({0, 2, 1});
      slog::Relation* readrel722 = db->getRelation("eval");
      evalindex685 = readrel722->getIndex(ord721, false);
      std::vector<u16> ord723({0, 2, 1});
      slog::Relation* readrel724 = db->getRelation("eval");
      evalindex686 = readrel724->getIndex(ord723, false);
      std::vector<u16> ord725({0, 1, 2});
      slog::Relation* readrel726 = db->getRelation("app");
      appindex687 = readrel726->getIndex(ord725, false);
      std::vector<u16> ord727({0, 1});
      slog::Relation* readrel728 = db->getRelation("eval_ans");
      eval_ansindex688 = readrel728->getIndex(ord727, false);
      std::vector<u16> ord729({2, 0, 1});
      slog::Relation* readrel730 = db->getRelation("clo");
      cloindex689 = readrel730->getIndex(ord729, false);
      std::vector<u16> ord731({0, 1});
      slog::Relation* readrel732 = db->getRelation("eval_ans");
      eval_ansindex690 = readrel732->getIndex(ord731, false);
      std::vector<u16> ord733({1, 2, 0});
      slog::Relation* readrel734 = db->getRelation("lambda");
      lambdaindex691 = readrel734->getIndex(ord733, false);
      std::vector<u16> ord735({1, 2, 0});
      slog::Relation* readrel736 = db->getRelation("clo");
      cloindex692 = readrel736->getIndex(ord735, false);
      std::vector<u16> ord737({0, 1});
      slog::Relation* readrel738 = db->getRelation("eval_ans");
      eval_ansindex693 = readrel738->getIndex(ord737, false);
  
    }
    ReadTask694(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c68 = _t[1];
        u64 v_c71 = _t[2];
        if (!slog::exists_probe<3,1>(evalindex673, std::array<u64,3>{v_c71, 0, 0})) return;
        if (!slog::exists_probe<10,1>($sup27994x83x0x0x1index674, std::array<u64,10>{v_c68, 0, 0, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex675, std::array<u64,3>{v_c68, 0, 0})) return;
        slog::join_probe<2,1>(eval_ansindex676, std::array<u64,2>{v_c74, 0}, [&](const std::array<u64,2>& m739) {
          u64 v_c75 = m739[1];
          slog::join_probe<3,1>(evalindex677, std::array<u64,3>{v_c71, 0, 0}, [&](const std::array<u64,3>& m740) {
            u64 v_c3 = m740[1]; u64 v_c65 = m740[2];
            if (!slog::exists_probe<10,3>($sup27994x83x0x0x1index678, std::array<u64,10>{v_c65, v_c3, v_c68, 0, 0, 0, 0, 0, 0, 0})) return;
            if (!slog::exists_probe<3,1>(evalindex679, std::array<u64,3>{v_c3, 0, 0})) return;
            slog::join_probe<4,2>($sup27994x83x0x0x0index680, std::array<u64,4>{v_c65, v_c3, 0, 0}, [&](const std::array<u64,4>& m741) {
              u64 v_c2 = m741[2]; u64 v_c1 = m741[3];
              if (!slog::exists_probe<3,2>(evalindex681, std::array<u64,3>{v_c1, v_c3, 0})) return;
              if (!slog::exists_probe<3,2>(evalindex682, std::array<u64,3>{v_c2, v_c3, 0})) return;
              if (!slog::exists_probe<3,3>(appindex683, std::array<u64,3>{v_c71, v_c1, v_c2})) return;
              slog::join_probe<10,5>($sup27994x83x0x0x1index684, std::array<u64,10>{v_c65, v_c3, v_c68, v_c2, v_c1, 0, 0, 0, 0, 0}, [&](const std::array<u64,10>& m742) {
                u64 v_c66 = m742[5]; u64 v_c64 = m742[6]; u64 v_c67 = m742[7]; u64 v_c69 = m742[8]; u64 v_c70 = m742[9];
                slog::join_probe<3,3>(evalindex685, std::array<u64,3>{v_c66, v_c3, v_c1}, [&](const std::array<u64,3>& m743) {
                  slog::join_probe<3,3>(evalindex686, std::array<u64,3>{v_c64, v_c3, v_c2}, [&](const std::array<u64,3>& m744) {
                    slog::join_probe<3,3>(appindex687, std::array<u64,3>{v_c71, v_c1, v_c2}, [&](const std::array<u64,3>& m745) {
                      slog::join_probe<2,2>(eval_ansindex688, std::array<u64,2>{v_c64, v_c69}, [&](const std::array<u64,2>& m746) {
                        if (!slog::exists_probe<3,1>(cloindex689, std::array<u64,3>{v_c67, 0, 0})) return;
                        if (!slog::exists_probe<2,1>(eval_ansindex690, std::array<u64,2>{v_c66, 0})) return;
                        slog::join_probe<3,2>(lambdaindex691, std::array<u64,3>{v_c70, v_c68, 0}, [&](const std::array<u64,3>& m747) {
                          u64 v_c72 = m747[2];
                          slog::join_probe<3,2>(cloindex692, std::array<u64,3>{v_c72, v_c67, 0}, [&](const std::array<u64,3>& m748) {
                            u64 v_c73 = m748[2];
                            slog::join_probe<2,2>(eval_ansindex693, std::array<u64,2>{v_c66, v_c73}, [&](const std::array<u64,2>& m749) {
                              ++_fires;
                              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c65, v_c75}, std::array<u16,2>{0, 1});
                            });
                          });
                        });
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
        ReadTask694* _cont = new ReadTask694(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask694(db,b), false);
  // (crule (pre (let __tconst1pJW313 constb49bea2fcccd8f4301a347ed) (let __tconst7LWP310 const66518c0c1b3a5a0b09ae2ef1) (let __tconst5PoN291 constc85eae03730a4f4cf1d66a0c) (let __tconst2Yzp284 const8ca682693a0738a0641c6956) (let __tconst0sqO307 const4a8acfc71441e0695ffcf5b3) (let __tconst9rZO295 const576506f61f53440f1edd95d2) (let __tconst2CSv302 const229c0b7aa8a7eb4055f5a3d0)) (scan app __t3Izn312 __t5T0g311 __t7aCZ292) (body (exists lambda (0 1 2) 2 __t5T0g311 __tconst7LWP310) (exists ref (1 0) 1 __tconst2Yzp284) (exists lambda (1 2 0) 1 __tconst2Yzp284) (exists ref (1 0) 1 __tconst1pJW313) (exists ref (1 0) 1 __tconst7LWP310) (exists ref (1 0) 1 __tconst9rZO295) (exists lambda (1 2 0) 1 __tconst9rZO295) (exists lambda (1 2 0) 1 __tconst0sqO307) (exists lambda (1 2 0) 1 __tconst2CSv302) (exists ref (1 0) 1 __tconst2CSv302) (join lambda (0 1 2) 2 __t7aCZ292 __tconst5PoN291 __t30Ec290) (join lambda (0 1 2) 2 __t5T0g311 __tconst7LWP310 __t6t9L309) (join ref (1 0) 1 __tconst2Yzp284 __t248W283) (join lambda (1 2 0) 2 __tconst2Yzp284 __t248W283 __t0oFu285) (join ref (1 0) 1 __tconst1pJW313 __t165O287) (join app (0 1 2) 2 __t30Ec290 __t165O287 dup5xnD385) (eq __t165O287 dup5xnD385) (join ref (1 0) 1 __tconst7LWP310 __t91H2298) (exists app (1 2 0) 1 __t91H2298) (join ref (1 0) 1 __tconst9rZO295 __t71w7294) (join lambda (1 2 0) 2 __tconst9rZO295 __t71w7294 __t3dkk296) (join app (1 2 0) 2 __t91H2298 __t3dkk296 __t4LtH299) (join app (2 0 1) 2 __t4LtH299 __t6t9L309 __t0vn1308) (join lambda (0 1 2) 2 __t0vn1308 __tconst0sqO307 __t4HUX306) (join app (0 1 2) 2 __t4HUX306 __t91H2298 __t7EW2303) (join lambda (0 1 2) 2 __t7EW2303 __tconst2CSv302 __t6lXa301) (join ref (0 1) 2 __t6lXa301 __tconst2CSv302)) (head (mkstruct lambda (1 2 0) __t7Qbz314 __tconst1pJW313 __t3Izn312)) mcfa-counting.slog:194 #f)
  class ReadTask776 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lambdaindex750;  slog::Index** refindex751;  slog::Index** lambdaindex752;  slog::Index** refindex753;  slog::Index** refindex754;  slog::Index** refindex755;  slog::Index** lambdaindex756;  slog::Index** lambdaindex757;  slog::Index** lambdaindex758;  slog::Index** refindex759;  slog::Index** lambdaindex760;  slog::Index** lambdaindex761;  slog::Index** refindex762;  slog::Index** lambdaindex763;  slog::Index** refindex764;  slog::Index** appindex765;  slog::Index** refindex766;  slog::Index** appindex767;  slog::Index** refindex768;  slog::Index** lambdaindex769;  slog::Index** appindex770;  slog::Index** appindex771;  slog::Index** lambdaindex772;  slog::Index** appindex773;  slog::Index** lambdaindex774;  slog::Index** refindex775;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      outer_rel = db->getRelation("app");
      std::vector<u16> ord777({0, 1, 2});
      slog::Relation* readrel778 = db->getRelation("lambda");
      lambdaindex750 = readrel778->getIndex(ord777, false);
      std::vector<u16> ord779({1, 0});
      slog::Relation* readrel780 = db->getRelation("ref");
      refindex751 = readrel780->getIndex(ord779, false);
      std::vector<u16> ord781({1, 2, 0});
      slog::Relation* readrel782 = db->getRelation("lambda");
      lambdaindex752 = readrel782->getIndex(ord781, false);
      std::vector<u16> ord783({1, 0});
      slog::Relation* readrel784 = db->getRelation("ref");
      refindex753 = readrel784->getIndex(ord783, false);
      std::vector<u16> ord785({1, 0});
      slog::Relation* readrel786 = db->getRelation("ref");
      refindex754 = readrel786->getIndex(ord785, false);
      std::vector<u16> ord787({1, 0});
      slog::Relation* readrel788 = db->getRelation("ref");
      refindex755 = readrel788->getIndex(ord787, false);
      std::vector<u16> ord789({1, 2, 0});
      slog::Relation* readrel790 = db->getRelation("lambda");
      lambdaindex756 = readrel790->getIndex(ord789, false);
      std::vector<u16> ord791({1, 2, 0});
      slog::Relation* readrel792 = db->getRelation("lambda");
      lambdaindex757 = readrel792->getIndex(ord791, false);
      std::vector<u16> ord793({1, 2, 0});
      slog::Relation* readrel794 = db->getRelation("lambda");
      lambdaindex758 = readrel794->getIndex(ord793, false);
      std::vector<u16> ord795({1, 0});
      slog::Relation* readrel796 = db->getRelation("ref");
      refindex759 = readrel796->getIndex(ord795, false);
      std::vector<u16> ord797({0, 1, 2});
      slog::Relation* readrel798 = db->getRelation("lambda");
      lambdaindex760 = readrel798->getIndex(ord797, false);
      std::vector<u16> ord799({0, 1, 2});
      slog::Relation* readrel800 = db->getRelation("lambda");
      lambdaindex761 = readrel800->getIndex(ord799, false);
      std::vector<u16> ord801({1, 0});
      slog::Relation* readrel802 = db->getRelation("ref");
      refindex762 = readrel802->getIndex(ord801, false);
      std::vector<u16> ord803({1, 2, 0});
      slog::Relation* readrel804 = db->getRelation("lambda");
      lambdaindex763 = readrel804->getIndex(ord803, false);
      std::vector<u16> ord805({1, 0});
      slog::Relation* readrel806 = db->getRelation("ref");
      refindex764 = readrel806->getIndex(ord805, false);
      std::vector<u16> ord807({0, 1, 2});
      slog::Relation* readrel808 = db->getRelation("app");
      appindex765 = readrel808->getIndex(ord807, false);
      std::vector<u16> ord809({1, 0});
      slog::Relation* readrel810 = db->getRelation("ref");
      refindex766 = readrel810->getIndex(ord809, false);
      std::vector<u16> ord811({1, 2, 0});
      slog::Relation* readrel812 = db->getRelation("app");
      appindex767 = readrel812->getIndex(ord811, false);
      std::vector<u16> ord813({1, 0});
      slog::Relation* readrel814 = db->getRelation("ref");
      refindex768 = readrel814->getIndex(ord813, false);
      std::vector<u16> ord815({1, 2, 0});
      slog::Relation* readrel816 = db->getRelation("lambda");
      lambdaindex769 = readrel816->getIndex(ord815, false);
      std::vector<u16> ord817({1, 2, 0});
      slog::Relation* readrel818 = db->getRelation("app");
      appindex770 = readrel818->getIndex(ord817, false);
      std::vector<u16> ord819({2, 0, 1});
      slog::Relation* readrel820 = db->getRelation("app");
      appindex771 = readrel820->getIndex(ord819, false);
      std::vector<u16> ord821({0, 1, 2});
      slog::Relation* readrel822 = db->getRelation("lambda");
      lambdaindex772 = readrel822->getIndex(ord821, false);
      std::vector<u16> ord823({0, 1, 2});
      slog::Relation* readrel824 = db->getRelation("app");
      appindex773 = readrel824->getIndex(ord823, false);
      std::vector<u16> ord825({0, 1, 2});
      slog::Relation* readrel826 = db->getRelation("lambda");
      lambdaindex774 = readrel826->getIndex(ord825, false);
      std::vector<u16> ord827({0, 1});
      slog::Relation* readrel828 = db->getRelation("ref");
      refindex775 = readrel828->getIndex(ord827, false);
  
    }
    ReadTask776(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c44 = v_constb49bea2fcccd8f4301a347ed;
      u64 v_c45 = v_const66518c0c1b3a5a0b09ae2ef1;
      u64 v_c47 = v_constc85eae03730a4f4cf1d66a0c;
      u64 v_c50 = v_const8ca682693a0738a0641c6956;
      u64 v_c46 = v_const4a8acfc71441e0695ffcf5b3;
      u64 v_c49 = v_const576506f61f53440f1edd95d2;
      u64 v_c48 = v_const229c0b7aa8a7eb4055f5a3d0;
  
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
        u64 v_c63 = _t[2];
        if (!slog::exists_probe<3,2>(lambdaindex750, std::array<u64,3>{v_c111, v_c45, 0})) return;
        if (!slog::exists_probe<2,1>(refindex751, std::array<u64,2>{v_c50, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex752, std::array<u64,3>{v_c50, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex753, std::array<u64,2>{v_c44, 0})) return;
        if (!slog::exists_probe<2,1>(refindex754, std::array<u64,2>{v_c45, 0})) return;
        if (!slog::exists_probe<2,1>(refindex755, std::array<u64,2>{v_c49, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex756, std::array<u64,3>{v_c49, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex757, std::array<u64,3>{v_c46, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex758, std::array<u64,3>{v_c48, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex759, std::array<u64,2>{v_c48, 0})) return;
        slog::join_probe<3,2>(lambdaindex760, std::array<u64,3>{v_c63, v_c47, 0}, [&](const std::array<u64,3>& m829) {
          u64 v_c62 = m829[2];
          slog::join_probe<3,2>(lambdaindex761, std::array<u64,3>{v_c111, v_c45, 0}, [&](const std::array<u64,3>& m830) {
            u64 v_c112 = m830[2];
            slog::join_probe<2,1>(refindex762, std::array<u64,2>{v_c50, 0}, [&](const std::array<u64,2>& m831) {
              u64 v_c52 = m831[1];
              slog::join_probe<3,2>(lambdaindex763, std::array<u64,3>{v_c50, v_c52, 0}, [&](const std::array<u64,3>& m832) {
                u64 v_c53 = m832[2];
                slog::join_probe<2,1>(refindex764, std::array<u64,2>{v_c44, 0}, [&](const std::array<u64,2>& m833) {
                  u64 v_c54 = m833[1];
                  slog::join_probe<3,2>(appindex765, std::array<u64,3>{v_c62, v_c54, 0}, [&](const std::array<u64,3>& m834) {
                    u64 v_c113 = m834[2];
                    if (v_c54 != v_c113) return;
                    slog::join_probe<2,1>(refindex766, std::array<u64,2>{v_c45, 0}, [&](const std::array<u64,2>& m835) {
                      u64 v_c51 = m835[1];
                      if (!slog::exists_probe<3,1>(appindex767, std::array<u64,3>{v_c51, 0, 0})) return;
                      slog::join_probe<2,1>(refindex768, std::array<u64,2>{v_c49, 0}, [&](const std::array<u64,2>& m836) {
                        u64 v_c55 = m836[1];
                        slog::join_probe<3,2>(lambdaindex769, std::array<u64,3>{v_c49, v_c55, 0}, [&](const std::array<u64,3>& m837) {
                          u64 v_c56 = m837[2];
                          slog::join_probe<3,2>(appindex770, std::array<u64,3>{v_c51, v_c56, 0}, [&](const std::array<u64,3>& m838) {
                            u64 v_c57 = m838[2];
                            slog::join_probe<3,2>(appindex771, std::array<u64,3>{v_c57, v_c112, 0}, [&](const std::array<u64,3>& m839) {
                              u64 v_c114 = m839[2];
                              slog::join_probe<3,2>(lambdaindex772, std::array<u64,3>{v_c114, v_c46, 0}, [&](const std::array<u64,3>& m840) {
                                u64 v_c60 = m840[2];
                                slog::join_probe<3,2>(appindex773, std::array<u64,3>{v_c60, v_c51, 0}, [&](const std::array<u64,3>& m841) {
                                  u64 v_c59 = m841[2];
                                  slog::join_probe<3,2>(lambdaindex774, std::array<u64,3>{v_c59, v_c48, 0}, [&](const std::array<u64,3>& m842) {
                                    u64 v_c58 = m842[2];
                                    slog::join_probe<2,2>(refindex775, std::array<u64,2>{v_c58, v_c48}, [&](const std::array<u64,2>& m843) {
                                      ++_fires;
                                      slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c44, v_c110}, std::array<u16,3>{1, 2, 0});
                                    });
                                  });
                                });
                              });
                            });
                          });
                        });
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
        ReadTask776* _cont = new ReadTask776(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask776(db,b), false);
  // (crule (pre (let __tconst0ZcM213 constfc9ee54e0ee8c6d1e715716c) (let __tconst5Fqn220 const15bb62b8293a526ca6f0e4eb) (let __tconst9TQS210 const5950e3cb761734f52a881545) (let __tconst1wsq203 const77ceb5c0e9f84ebd84104a97)) (seeded) (body (join ref (1 0) 1 __tconst1wsq203 __t6pkv202) (exists ref (1 0) 1 __tconst5Fqn220) (exists ref (1 0) 1 __tconst0ZcM213) (exists lambda (1 2 0) 1 __tconst5Fqn220) (exists lambda (1 2 0) 1 __tconst9TQS210) (exists lambda (1 2 0) 1 __tconst0ZcM213) (join lambda (1 2 0) 2 __tconst1wsq203 __t6pkv202 __t118D204) (exists app (2 0 1) 1 __t118D204) (join ref (1 0) 1 __tconst5Fqn220 __t2V0C216) (exists app (1 2 0) 1 __t2V0C216) (join ref (1 0) 1 __tconst0ZcM213 __t6fYg206) (exists app (1 2 0) 1 __t6fYg206) (join app (1 2 0) 1 __t2V0C216 dup2i3G431 __t9nSF219) (eq __t2V0C216 dup2i3G431) (join lambda (1 2 0) 2 __tconst5Fqn220 __t9nSF219 __t6h87221) (join app (1 2 0) 1 __t6fYg206 dup8pTD432 __t1W86209) (eq __t6fYg206 dup8pTD432) (join lambda (1 2 0) 2 __tconst9TQS210 __t1W86209 __t1wmd211) (join app (1 2 0) 2 __t1wmd211 __t118D204 __t4jAx212) (join lambda (1 2 0) 2 __tconst0ZcM213 __t4jAx212 __t14ld214)) (head (mkstruct app (1 2 0) __t4RlI222 __t6h87221 __t14ld214)) mcfa-counting.slog:211 #f)
  class ReadTask862 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex844;  slog::Index** refindex845;  slog::Index** refindex846;  slog::Index** lambdaindex847;  slog::Index** lambdaindex848;  slog::Index** lambdaindex849;  slog::Index** lambdaindex850;  slog::Index** appindex851;  slog::Index** refindex852;  slog::Index** appindex853;  slog::Index** refindex854;  slog::Index** appindex855;  slog::Index** appindex856;  slog::Index** lambdaindex857;  slog::Index** appindex858;  slog::Index** lambdaindex859;  slog::Index** appindex860;  slog::Index** lambdaindex861;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord863({1, 2, 0});
      slog::Relation* readrel864 = db->getRelation("app");
      head_index[0] = readrel864->getIndex(ord863, false);
      std::vector<u16> ord865({1, 0});
      slog::Relation* readrel866 = db->getRelation("ref");
      refindex844 = readrel866->getIndex(ord865, false);
      std::vector<u16> ord867({1, 0});
      slog::Relation* readrel868 = db->getRelation("ref");
      refindex845 = readrel868->getIndex(ord867, false);
      std::vector<u16> ord869({1, 0});
      slog::Relation* readrel870 = db->getRelation("ref");
      refindex846 = readrel870->getIndex(ord869, false);
      std::vector<u16> ord871({1, 2, 0});
      slog::Relation* readrel872 = db->getRelation("lambda");
      lambdaindex847 = readrel872->getIndex(ord871, false);
      std::vector<u16> ord873({1, 2, 0});
      slog::Relation* readrel874 = db->getRelation("lambda");
      lambdaindex848 = readrel874->getIndex(ord873, false);
      std::vector<u16> ord875({1, 2, 0});
      slog::Relation* readrel876 = db->getRelation("lambda");
      lambdaindex849 = readrel876->getIndex(ord875, false);
      std::vector<u16> ord877({1, 2, 0});
      slog::Relation* readrel878 = db->getRelation("lambda");
      lambdaindex850 = readrel878->getIndex(ord877, false);
      std::vector<u16> ord879({2, 0, 1});
      slog::Relation* readrel880 = db->getRelation("app");
      appindex851 = readrel880->getIndex(ord879, false);
      std::vector<u16> ord881({1, 0});
      slog::Relation* readrel882 = db->getRelation("ref");
      refindex852 = readrel882->getIndex(ord881, false);
      std::vector<u16> ord883({1, 2, 0});
      slog::Relation* readrel884 = db->getRelation("app");
      appindex853 = readrel884->getIndex(ord883, false);
      std::vector<u16> ord885({1, 0});
      slog::Relation* readrel886 = db->getRelation("ref");
      refindex854 = readrel886->getIndex(ord885, false);
      std::vector<u16> ord887({1, 2, 0});
      slog::Relation* readrel888 = db->getRelation("app");
      appindex855 = readrel888->getIndex(ord887, false);
      std::vector<u16> ord889({1, 2, 0});
      slog::Relation* readrel890 = db->getRelation("app");
      appindex856 = readrel890->getIndex(ord889, false);
      std::vector<u16> ord891({1, 2, 0});
      slog::Relation* readrel892 = db->getRelation("lambda");
      lambdaindex857 = readrel892->getIndex(ord891, false);
      std::vector<u16> ord893({1, 2, 0});
      slog::Relation* readrel894 = db->getRelation("app");
      appindex858 = readrel894->getIndex(ord893, false);
      std::vector<u16> ord895({1, 2, 0});
      slog::Relation* readrel896 = db->getRelation("lambda");
      lambdaindex859 = readrel896->getIndex(ord895, false);
      std::vector<u16> ord897({1, 2, 0});
      slog::Relation* readrel898 = db->getRelation("app");
      appindex860 = readrel898->getIndex(ord897, false);
      std::vector<u16> ord899({1, 2, 0});
      slog::Relation* readrel900 = db->getRelation("lambda");
      lambdaindex861 = readrel900->getIndex(ord899, false);
  
    }
    ReadTask862(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c115 = v_constfc9ee54e0ee8c6d1e715716c;
      u64 v_c116 = v_const15bb62b8293a526ca6f0e4eb;
      u64 v_c117 = v_const5950e3cb761734f52a881545;
      u64 v_c118 = v_const77ceb5c0e9f84ebd84104a97;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex844, std::array<u64,2>{v_c118, 0}, [&](const std::array<u64,2>& m901) {
        u64 v_c119 = m901[1];
        if (!slog::exists_probe<2,1>(refindex845, std::array<u64,2>{v_c116, 0})) return;
        if (!slog::exists_probe<2,1>(refindex846, std::array<u64,2>{v_c115, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex847, std::array<u64,3>{v_c116, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex848, std::array<u64,3>{v_c117, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex849, std::array<u64,3>{v_c115, 0, 0})) return;
        slog::join_probe<3,2>(lambdaindex850, std::array<u64,3>{v_c118, v_c119, 0}, [&](const std::array<u64,3>& m902) {
          u64 v_c120 = m902[2];
          if (!slog::exists_probe<3,1>(appindex851, std::array<u64,3>{v_c120, 0, 0})) return;
          slog::join_probe<2,1>(refindex852, std::array<u64,2>{v_c116, 0}, [&](const std::array<u64,2>& m903) {
            u64 v_c121 = m903[1];
            if (!slog::exists_probe<3,1>(appindex853, std::array<u64,3>{v_c121, 0, 0})) return;
            slog::join_probe<2,1>(refindex854, std::array<u64,2>{v_c115, 0}, [&](const std::array<u64,2>& m904) {
              u64 v_c122 = m904[1];
              if (!slog::exists_probe<3,1>(appindex855, std::array<u64,3>{v_c122, 0, 0})) return;
              slog::join_probe<3,1>(appindex856, std::array<u64,3>{v_c121, 0, 0}, [&](const std::array<u64,3>& m905) {
                u64 v_c123 = m905[1]; u64 v_c124 = m905[2];
                if (v_c121 != v_c123) return;
                slog::join_probe<3,2>(lambdaindex857, std::array<u64,3>{v_c116, v_c124, 0}, [&](const std::array<u64,3>& m906) {
                  u64 v_c125 = m906[2];
                  slog::join_probe<3,1>(appindex858, std::array<u64,3>{v_c122, 0, 0}, [&](const std::array<u64,3>& m907) {
                    u64 v_c126 = m907[1]; u64 v_c127 = m907[2];
                    if (v_c122 != v_c126) return;
                    slog::join_probe<3,2>(lambdaindex859, std::array<u64,3>{v_c117, v_c127, 0}, [&](const std::array<u64,3>& m908) {
                      u64 v_c128 = m908[2];
                      slog::join_probe<3,2>(appindex860, std::array<u64,3>{v_c128, v_c120, 0}, [&](const std::array<u64,3>& m909) {
                        u64 v_c129 = m909[2];
                        slog::join_probe<3,2>(lambdaindex861, std::array<u64,3>{v_c115, v_c129, 0}, [&](const std::array<u64,3>& m910) {
                          u64 v_c130 = m910[2];
                          ++_fires;
                          slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c125, v_c130}, std::array<u16,3>{1, 2, 0});
                        });
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
      s->addTaskSeeded(phase_read, new ReadTask862(db,b));
  // (crule (pre (let __tconst4Xaz41 const81cb39a72a584ab4f703b7f7) (let __tconst1aIN38 const4d5ce1398140fbe27561181f) (let __tconst4xzG22 constdbf1bdba02122b2adce28528) (let __tconst37GM26 const85f09fa1913b9daf65957cf7) (let __tconst1ha033 const969c6e56242ce8d0a4346602) (let __tconst1HMF17 constd7a1925d249b4768c8a9f2d8)) (seeded) (body (join ref (1 0) 1 __tconst4Xaz41 __t75SZ29) (exists ref (1 0) 1 __tconst37GM26) (exists lambda (1 2 0) 1 __tconst37GM26) (exists app (1 2 0) 1 __t75SZ29) (exists ref (1 0) 1 __tconst1HMF17) (exists lambda (1 2 0) 1 __tconst1HMF17) (exists lambda (1 2 0) 1 __tconst4xzG22) (exists ref (1 0) 1 __tconst1ha033) (exists lambda (1 2 0) 1 __tconst1ha033) (exists lambda (1 2 0) 1 __tconst1aIN38) (join ref (1 0) 1 __tconst4xzG22 __t2DOE20) (exists app (1 2 0) 1 __t2DOE20) (join ref (1 0) 1 __tconst37GM26 __t7U1m25) (join lambda (1 2 0) 2 __tconst37GM26 __t7U1m25 __t5myE27) (join app (1 2 0) 2 __t75SZ29 __t5myE27 __t2Vg230) (exists app (2 0 1) 1 __t2Vg230) (join ref (1 0) 1 __tconst1HMF17 __t7H1u16) (join lambda (1 2 0) 2 __tconst1HMF17 __t7H1u16 __t2wNc18) (join app (1 2 0) 2 __t2DOE20 __t2wNc18 __t3b2k21) (join lambda (1 2 0) 2 __tconst4xzG22 __t3b2k21 __t8Ovw23) (join ref (1 0) 1 __tconst1ha033 __t7N9A32) (join lambda (1 2 0) 2 __tconst1ha033 __t7N9A32 __t065j34) (join app (1 2 0) 2 __t75SZ29 __t065j34 __t3pMW37) (join lambda (1 2 0) 2 __tconst1aIN38 __t3pMW37 __t3aRV39) (join app (1 2 0) 2 __t3aRV39 __t2Vg230 __t7P7240)) (head (mkstruct lambda (1 2 0) __t79we42 __tconst4Xaz41 __t7P7240)) mcfa-counting.slog:260 #f)
  class ReadTask936 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex911;  slog::Index** refindex912;  slog::Index** lambdaindex913;  slog::Index** appindex914;  slog::Index** refindex915;  slog::Index** lambdaindex916;  slog::Index** lambdaindex917;  slog::Index** refindex918;  slog::Index** lambdaindex919;  slog::Index** lambdaindex920;  slog::Index** refindex921;  slog::Index** appindex922;  slog::Index** refindex923;  slog::Index** lambdaindex924;  slog::Index** appindex925;  slog::Index** appindex926;  slog::Index** refindex927;  slog::Index** lambdaindex928;  slog::Index** appindex929;  slog::Index** lambdaindex930;  slog::Index** refindex931;  slog::Index** lambdaindex932;  slog::Index** appindex933;  slog::Index** lambdaindex934;  slog::Index** appindex935;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      std::vector<u16> ord937({1, 2, 0});
      slog::Relation* readrel938 = db->getRelation("lambda");
      head_index[0] = readrel938->getIndex(ord937, false);
      std::vector<u16> ord939({1, 0});
      slog::Relation* readrel940 = db->getRelation("ref");
      refindex911 = readrel940->getIndex(ord939, false);
      std::vector<u16> ord941({1, 0});
      slog::Relation* readrel942 = db->getRelation("ref");
      refindex912 = readrel942->getIndex(ord941, false);
      std::vector<u16> ord943({1, 2, 0});
      slog::Relation* readrel944 = db->getRelation("lambda");
      lambdaindex913 = readrel944->getIndex(ord943, false);
      std::vector<u16> ord945({1, 2, 0});
      slog::Relation* readrel946 = db->getRelation("app");
      appindex914 = readrel946->getIndex(ord945, false);
      std::vector<u16> ord947({1, 0});
      slog::Relation* readrel948 = db->getRelation("ref");
      refindex915 = readrel948->getIndex(ord947, false);
      std::vector<u16> ord949({1, 2, 0});
      slog::Relation* readrel950 = db->getRelation("lambda");
      lambdaindex916 = readrel950->getIndex(ord949, false);
      std::vector<u16> ord951({1, 2, 0});
      slog::Relation* readrel952 = db->getRelation("lambda");
      lambdaindex917 = readrel952->getIndex(ord951, false);
      std::vector<u16> ord953({1, 0});
      slog::Relation* readrel954 = db->getRelation("ref");
      refindex918 = readrel954->getIndex(ord953, false);
      std::vector<u16> ord955({1, 2, 0});
      slog::Relation* readrel956 = db->getRelation("lambda");
      lambdaindex919 = readrel956->getIndex(ord955, false);
      std::vector<u16> ord957({1, 2, 0});
      slog::Relation* readrel958 = db->getRelation("lambda");
      lambdaindex920 = readrel958->getIndex(ord957, false);
      std::vector<u16> ord959({1, 0});
      slog::Relation* readrel960 = db->getRelation("ref");
      refindex921 = readrel960->getIndex(ord959, false);
      std::vector<u16> ord961({1, 2, 0});
      slog::Relation* readrel962 = db->getRelation("app");
      appindex922 = readrel962->getIndex(ord961, false);
      std::vector<u16> ord963({1, 0});
      slog::Relation* readrel964 = db->getRelation("ref");
      refindex923 = readrel964->getIndex(ord963, false);
      std::vector<u16> ord965({1, 2, 0});
      slog::Relation* readrel966 = db->getRelation("lambda");
      lambdaindex924 = readrel966->getIndex(ord965, false);
      std::vector<u16> ord967({1, 2, 0});
      slog::Relation* readrel968 = db->getRelation("app");
      appindex925 = readrel968->getIndex(ord967, false);
      std::vector<u16> ord969({2, 0, 1});
      slog::Relation* readrel970 = db->getRelation("app");
      appindex926 = readrel970->getIndex(ord969, false);
      std::vector<u16> ord971({1, 0});
      slog::Relation* readrel972 = db->getRelation("ref");
      refindex927 = readrel972->getIndex(ord971, false);
      std::vector<u16> ord973({1, 2, 0});
      slog::Relation* readrel974 = db->getRelation("lambda");
      lambdaindex928 = readrel974->getIndex(ord973, false);
      std::vector<u16> ord975({1, 2, 0});
      slog::Relation* readrel976 = db->getRelation("app");
      appindex929 = readrel976->getIndex(ord975, false);
      std::vector<u16> ord977({1, 2, 0});
      slog::Relation* readrel978 = db->getRelation("lambda");
      lambdaindex930 = readrel978->getIndex(ord977, false);
      std::vector<u16> ord979({1, 0});
      slog::Relation* readrel980 = db->getRelation("ref");
      refindex931 = readrel980->getIndex(ord979, false);
      std::vector<u16> ord981({1, 2, 0});
      slog::Relation* readrel982 = db->getRelation("lambda");
      lambdaindex932 = readrel982->getIndex(ord981, false);
      std::vector<u16> ord983({1, 2, 0});
      slog::Relation* readrel984 = db->getRelation("app");
      appindex933 = readrel984->getIndex(ord983, false);
      std::vector<u16> ord985({1, 2, 0});
      slog::Relation* readrel986 = db->getRelation("lambda");
      lambdaindex934 = readrel986->getIndex(ord985, false);
      std::vector<u16> ord987({1, 2, 0});
      slog::Relation* readrel988 = db->getRelation("app");
      appindex935 = readrel988->getIndex(ord987, false);
  
    }
    ReadTask936(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c5 = v_const81cb39a72a584ab4f703b7f7;
      u64 v_c6 = v_const4d5ce1398140fbe27561181f;
      u64 v_c7 = v_constdbf1bdba02122b2adce28528;
      u64 v_c9 = v_const85f09fa1913b9daf65957cf7;
      u64 v_c8 = v_const969c6e56242ce8d0a4346602;
      u64 v_c10 = v_constd7a1925d249b4768c8a9f2d8;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex911, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m989) {
        u64 v_c12 = m989[1];
        if (!slog::exists_probe<2,1>(refindex912, std::array<u64,2>{v_c9, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex913, std::array<u64,3>{v_c9, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex914, std::array<u64,3>{v_c12, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex915, std::array<u64,2>{v_c10, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex916, std::array<u64,3>{v_c10, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex917, std::array<u64,3>{v_c7, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex918, std::array<u64,2>{v_c8, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex919, std::array<u64,3>{v_c8, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex920, std::array<u64,3>{v_c6, 0, 0})) return;
        slog::join_probe<2,1>(refindex921, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m990) {
          u64 v_c11 = m990[1];
          if (!slog::exists_probe<3,1>(appindex922, std::array<u64,3>{v_c11, 0, 0})) return;
          slog::join_probe<2,1>(refindex923, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m991) {
            u64 v_c16 = m991[1];
            slog::join_probe<3,2>(lambdaindex924, std::array<u64,3>{v_c9, v_c16, 0}, [&](const std::array<u64,3>& m992) {
              u64 v_c17 = m992[2];
              slog::join_probe<3,2>(appindex925, std::array<u64,3>{v_c12, v_c17, 0}, [&](const std::array<u64,3>& m993) {
                u64 v_c18 = m993[2];
                if (!slog::exists_probe<3,1>(appindex926, std::array<u64,3>{v_c18, 0, 0})) return;
                slog::join_probe<2,1>(refindex927, std::array<u64,2>{v_c10, 0}, [&](const std::array<u64,2>& m994) {
                  u64 v_c13 = m994[1];
                  slog::join_probe<3,2>(lambdaindex928, std::array<u64,3>{v_c10, v_c13, 0}, [&](const std::array<u64,3>& m995) {
                    u64 v_c14 = m995[2];
                    slog::join_probe<3,2>(appindex929, std::array<u64,3>{v_c11, v_c14, 0}, [&](const std::array<u64,3>& m996) {
                      u64 v_c15 = m996[2];
                      slog::join_probe<3,2>(lambdaindex930, std::array<u64,3>{v_c7, v_c15, 0}, [&](const std::array<u64,3>& m997) {
                        u64 v_c131 = m997[2];
                        slog::join_probe<2,1>(refindex931, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m998) {
                          u64 v_c19 = m998[1];
                          slog::join_probe<3,2>(lambdaindex932, std::array<u64,3>{v_c8, v_c19, 0}, [&](const std::array<u64,3>& m999) {
                            u64 v_c20 = m999[2];
                            slog::join_probe<3,2>(appindex933, std::array<u64,3>{v_c12, v_c20, 0}, [&](const std::array<u64,3>& m1000) {
                              u64 v_c21 = m1000[2];
                              slog::join_probe<3,2>(lambdaindex934, std::array<u64,3>{v_c6, v_c21, 0}, [&](const std::array<u64,3>& m1001) {
                                u64 v_c132 = m1001[2];
                                slog::join_probe<3,2>(appindex935, std::array<u64,3>{v_c132, v_c18, 0}, [&](const std::array<u64,3>& m1002) {
                                  u64 v_c133 = m1002[2];
                                  ++_fires;
                                  slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c5, v_c133}, std::array<u16,3>{1, 2, 0});
                                });
                              });
                            });
                          });
                        });
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
      s->addTaskSeeded(phase_read, new ReadTask936(db,b));
  // (crule (pre (let __tconst4Xaz41 const81cb39a72a584ab4f703b7f7) (let __tconst1aIN38 const4d5ce1398140fbe27561181f) (let __tconst1ha033 const969c6e56242ce8d0a4346602) (let __tconst37GM26 const85f09fa1913b9daf65957cf7) (let __tconst4xzG22 constdbf1bdba02122b2adce28528) (let __tconst1HMF17 constd7a1925d249b4768c8a9f2d8)) (seeded) (body (join ref (1 0) 1 __tconst1HMF17 __t7H1u16) (exists ref (1 0) 1 __tconst37GM26) (exists ref (1 0) 1 __tconst4Xaz41) (exists ref (1 0) 1 __tconst1ha033) (join ref (1 0) 1 __tconst4xzG22 __t2DOE20) (join ref (1 0) 1 __tconst37GM26 __t7U1m25) (join ref (1 0) 1 __tconst4Xaz41 __t75SZ29) (join ref (1 0) 1 __tconst1ha033 __t7N9A32)) (head (mkstruct lambda (1 2 0) __t065j34 __tconst1ha033 __t7N9A32) (mkstruct lambda (1 2 0) __t5myE27 __tconst37GM26 __t7U1m25) (mkstruct lambda (1 2 0) __t2wNc18 __tconst1HMF17 __t7H1u16)) mcfa-counting.slog:260 #f)
  class ReadTask1011 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
  
  
  
  
  
  
    slog::Index** refindex1003;  slog::Index** refindex1004;  slog::Index** refindex1005;  slog::Index** refindex1006;  slog::Index** refindex1007;  slog::Index** refindex1008;  slog::Index** refindex1009;  slog::Index** refindex1010;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      std::vector<u16> ord1012({1, 2, 0});
      slog::Relation* readrel1013 = db->getRelation("lambda");
      head_index[0] = readrel1013->getIndex(ord1012, false);
      head_rel[1] = db->getRelation("lambda");
      std::vector<u16> ord1014({1, 2, 0});
      slog::Relation* readrel1015 = db->getRelation("lambda");
      head_index[1] = readrel1015->getIndex(ord1014, false);
      head_rel[2] = db->getRelation("lambda");
      std::vector<u16> ord1016({1, 2, 0});
      slog::Relation* readrel1017 = db->getRelation("lambda");
      head_index[2] = readrel1017->getIndex(ord1016, false);
      std::vector<u16> ord1018({1, 0});
      slog::Relation* readrel1019 = db->getRelation("ref");
      refindex1003 = readrel1019->getIndex(ord1018, false);
      std::vector<u16> ord1020({1, 0});
      slog::Relation* readrel1021 = db->getRelation("ref");
      refindex1004 = readrel1021->getIndex(ord1020, false);
      std::vector<u16> ord1022({1, 0});
      slog::Relation* readrel1023 = db->getRelation("ref");
      refindex1005 = readrel1023->getIndex(ord1022, false);
      std::vector<u16> ord1024({1, 0});
      slog::Relation* readrel1025 = db->getRelation("ref");
      refindex1006 = readrel1025->getIndex(ord1024, false);
      std::vector<u16> ord1026({1, 0});
      slog::Relation* readrel1027 = db->getRelation("ref");
      refindex1007 = readrel1027->getIndex(ord1026, false);
      std::vector<u16> ord1028({1, 0});
      slog::Relation* readrel1029 = db->getRelation("ref");
      refindex1008 = readrel1029->getIndex(ord1028, false);
      std::vector<u16> ord1030({1, 0});
      slog::Relation* readrel1031 = db->getRelation("ref");
      refindex1009 = readrel1031->getIndex(ord1030, false);
      std::vector<u16> ord1032({1, 0});
      slog::Relation* readrel1033 = db->getRelation("ref");
      refindex1010 = readrel1033->getIndex(ord1032, false);
  
    }
    ReadTask1011(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c5 = v_const81cb39a72a584ab4f703b7f7;
      u64 v_c6 = v_const4d5ce1398140fbe27561181f;
      u64 v_c8 = v_const969c6e56242ce8d0a4346602;
      u64 v_c9 = v_const85f09fa1913b9daf65957cf7;
      u64 v_c7 = v_constdbf1bdba02122b2adce28528;
      u64 v_c10 = v_constd7a1925d249b4768c8a9f2d8;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex1003, std::array<u64,2>{v_c10, 0}, [&](const std::array<u64,2>& m1034) {
        u64 v_c13 = m1034[1];
        if (!slog::exists_probe<2,1>(refindex1004, std::array<u64,2>{v_c9, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1005, std::array<u64,2>{v_c5, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1006, std::array<u64,2>{v_c8, 0})) return;
        slog::join_probe<2,1>(refindex1007, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m1035) {
          u64 v_c11 = m1035[1];
          slog::join_probe<2,1>(refindex1008, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m1036) {
            u64 v_c16 = m1036[1];
            slog::join_probe<2,1>(refindex1009, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m1037) {
              u64 v_c12 = m1037[1];
              slog::join_probe<2,1>(refindex1010, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m1038) {
                u64 v_c19 = m1038[1];
                ++_fires;
                slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c8, v_c19}, std::array<u16,3>{1, 2, 0});
                slog::emit_struct_checked<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c9, v_c16}, std::array<u16,3>{1, 2, 0});
                slog::emit_struct_checked<3>(head_rel[2], head_index[2], newbatch[2], std::array<u64,2>{v_c10, v_c13}, std::array<u16,3>{1, 2, 0});
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
      s->addTaskSeeded(phase_read, new ReadTask1011(db,b));
  // (crule (pre (let __tconst0y6X73 const0aa6f87434af0222b916e97a) (let __tconst7zoP70 const227d34ceeba7a29aada993d4) (let __tconst1bfe65 const59ba3256d223f0d0a00d0633) (let __tconst8wN863 const7cd75b35aa30c3ddf04f9d57) (let __tconst0aL952 constd3d07026d47882ceca728218) (let __tconst0xUh47 constf700a82e218a86de572e1f7f)) (seeded) (body (join ref (1 0) 1 __tconst0xUh47 __t5vZb46) (exists ref (1 0) 1 __tconst1bfe65) (exists ref (1 0) 1 __tconst0y6X73) (exists ref (1 0) 1 __tconst8wN863) (join ref (1 0) 1 __tconst0aL952 __t5HQ450) (join ref (1 0) 1 __tconst1bfe65 __t2HsD55) (join ref (1 0) 1 __tconst0y6X73 __t0QRr59) (join ref (1 0) 1 __tconst8wN863 __t1mkO62)) (head (mkstruct lambda (1 2 0) __t3Dru64 __tconst8wN863 __t1mkO62) (mkstruct lambda (1 2 0) __t0uNb57 __tconst1bfe65 __t2HsD55) (mkstruct lambda (1 2 0) __t50zW48 __tconst0xUh47 __t5vZb46)) mcfa-counting.slog:287 #f)
  class ReadTask1047 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
  
  
  
  
  
  
    slog::Index** refindex1039;  slog::Index** refindex1040;  slog::Index** refindex1041;  slog::Index** refindex1042;  slog::Index** refindex1043;  slog::Index** refindex1044;  slog::Index** refindex1045;  slog::Index** refindex1046;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      std::vector<u16> ord1048({1, 2, 0});
      slog::Relation* readrel1049 = db->getRelation("lambda");
      head_index[0] = readrel1049->getIndex(ord1048, false);
      head_rel[1] = db->getRelation("lambda");
      std::vector<u16> ord1050({1, 2, 0});
      slog::Relation* readrel1051 = db->getRelation("lambda");
      head_index[1] = readrel1051->getIndex(ord1050, false);
      head_rel[2] = db->getRelation("lambda");
      std::vector<u16> ord1052({1, 2, 0});
      slog::Relation* readrel1053 = db->getRelation("lambda");
      head_index[2] = readrel1053->getIndex(ord1052, false);
      std::vector<u16> ord1054({1, 0});
      slog::Relation* readrel1055 = db->getRelation("ref");
      refindex1039 = readrel1055->getIndex(ord1054, false);
      std::vector<u16> ord1056({1, 0});
      slog::Relation* readrel1057 = db->getRelation("ref");
      refindex1040 = readrel1057->getIndex(ord1056, false);
      std::vector<u16> ord1058({1, 0});
      slog::Relation* readrel1059 = db->getRelation("ref");
      refindex1041 = readrel1059->getIndex(ord1058, false);
      std::vector<u16> ord1060({1, 0});
      slog::Relation* readrel1061 = db->getRelation("ref");
      refindex1042 = readrel1061->getIndex(ord1060, false);
      std::vector<u16> ord1062({1, 0});
      slog::Relation* readrel1063 = db->getRelation("ref");
      refindex1043 = readrel1063->getIndex(ord1062, false);
      std::vector<u16> ord1064({1, 0});
      slog::Relation* readrel1065 = db->getRelation("ref");
      refindex1044 = readrel1065->getIndex(ord1064, false);
      std::vector<u16> ord1066({1, 0});
      slog::Relation* readrel1067 = db->getRelation("ref");
      refindex1045 = readrel1067->getIndex(ord1066, false);
      std::vector<u16> ord1068({1, 0});
      slog::Relation* readrel1069 = db->getRelation("ref");
      refindex1046 = readrel1069->getIndex(ord1068, false);
  
    }
    ReadTask1047(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c22 = v_const0aa6f87434af0222b916e97a;
      u64 v_c24 = v_const227d34ceeba7a29aada993d4;
      u64 v_c25 = v_const59ba3256d223f0d0a00d0633;
      u64 v_c27 = v_const7cd75b35aa30c3ddf04f9d57;
      u64 v_c23 = v_constd3d07026d47882ceca728218;
      u64 v_c26 = v_constf700a82e218a86de572e1f7f;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex1039, std::array<u64,2>{v_c26, 0}, [&](const std::array<u64,2>& m1070) {
        u64 v_c40 = m1070[1];
        if (!slog::exists_probe<2,1>(refindex1040, std::array<u64,2>{v_c25, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1041, std::array<u64,2>{v_c22, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1042, std::array<u64,2>{v_c27, 0})) return;
        slog::join_probe<2,1>(refindex1043, std::array<u64,2>{v_c23, 0}, [&](const std::array<u64,2>& m1071) {
          u64 v_c31 = m1071[1];
          slog::join_probe<2,1>(refindex1044, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m1072) {
            u64 v_c32 = m1072[1];
            slog::join_probe<2,1>(refindex1045, std::array<u64,2>{v_c22, 0}, [&](const std::array<u64,2>& m1073) {
              u64 v_c30 = m1073[1];
              slog::join_probe<2,1>(refindex1046, std::array<u64,2>{v_c27, 0}, [&](const std::array<u64,2>& m1074) {
                u64 v_c39 = m1074[1];
                ++_fires;
                slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c27, v_c39}, std::array<u16,3>{1, 2, 0});
                slog::emit_struct_checked<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c25, v_c32}, std::array<u16,3>{1, 2, 0});
                slog::emit_struct_checked<3>(head_rel[2], head_index[2], newbatch[2], std::array<u64,2>{v_c26, v_c40}, std::array<u16,3>{1, 2, 0});
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
      s->addTaskSeeded(phase_read, new ReadTask1047(db,b));
  // (crule (pre (let __trid7xe7330 const07ef7e8462f6d369d70a1f0e) (let __trel5bhr331 const4a59dbb9cb3129dfcc75170b) (let __tcol7EbU332 const5feceb66ffc86f38d952786c) (let __trel8xHg333 const4e5ef144c51cd25230c144c3) (let __tcol57TS334 const5feceb66ffc86f38d952786c) (let __trel5RzG335 const4e5ef144c51cd25230c144c3) (let __tcol0Tpr336 const6b86b273ff34fce19d6b804e)) (scan $sup27994x83x0x0x1 __d0 __d1 __d2 c cb ea eb ef va x) (body) (head (tycheck eb (accept (struct app) (struct lambda) (struct ref)) __trid7xe7330 __trel5bhr331 __tcol7EbU332 (1 2 3 4 0)) (tycheck ef (accept (struct app) (struct lambda) (struct ref)) __trid7xe7330 __trel8xHg333 __tcol57TS334 (1 2 3 4 0)) (tycheck ea (accept (struct app) (struct lambda) (struct ref)) __trid7xe7330 __trel5RzG335 __tcol0Tpr336 (1 2 3 4 0)) (emit-temp temp9GbH416 ea eb ef) (mkstruct app (1 2 0) __t2Zeb76 ef ea)) mcfa-counting.slog:84 #f)
  class ReadTask1078 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[5];
    slog::Index** head_index[5];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid1075;  u32 sid1076;  u32 sid1077;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("malformed_deduction");
      head_rel[3] = db->getRelation("temp9GbH416");
      head_rel[4] = db->getRelation("app");
      outer_rel = db->getRelation("$sup27994x83x0x0x1");
      sid1075 = db->getRelation("app")->getStructId();
      sid1076 = db->getRelation("lambda")->getStructId();
      sid1077 = db->getRelation("ref")->getStructId();
  
    }
    ReadTask1078(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c134 = v_const07ef7e8462f6d369d70a1f0e;
      u64 v_c135 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c136 = v_const5feceb66ffc86f38d952786c;
      u64 v_c137 = v_const4e5ef144c51cd25230c144c3;
      u64 v_c138 = v_const5feceb66ffc86f38d952786c;
      u64 v_c139 = v_const4e5ef144c51cd25230c144c3;
      u64 v_c140 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c141 = _t[0];
        u64 v_c142 = _t[1];
        u64 v_c143 = _t[2];
        u64 v_c3 = _t[3];
        u64 v_c67 = _t[4];
        u64 v_c2 = _t[5];
        u64 v_c68 = _t[6];
        u64 v_c1 = _t[7];
        u64 v_c69 = _t[8];
        u64 v_c70 = _t[9];
        ++_fires;
        if (!((is_struct(v_c68) && (decode_struct_id(v_c68) == sid1075 || decode_struct_id(v_c68) == sid1076 || decode_struct_id(v_c68) == sid1077))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c134, v_c135, v_c136, v_c68}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c1) && (decode_struct_id(v_c1) == sid1075 || decode_struct_id(v_c1) == sid1076 || decode_struct_id(v_c1) == sid1077))))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c134, v_c137, v_c138, v_c1}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c2) && (decode_struct_id(v_c2) == sid1075 || decode_struct_id(v_c2) == sid1076 || decode_struct_id(v_c2) == sid1077))))
        {
          slog::emit_struct<5>(head_rel[2], newbatch[2], std::array<u64,4>{v_c134, v_c139, v_c140, v_c2}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_temp<3>(head_rel[3], newbatch[3], std::array<u64,3>{v_c2, v_c68, v_c1});
        slog::emit_struct<3>(head_rel[4], newbatch[4], std::array<u64,2>{v_c1, v_c2}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:84", "delta:$sup27994x83x0x0x1", _fires);
  
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
  // (crule (pre (let __tconst0zC2144 const4e3b5454cf93e32fad90650d) (let __tconst3Taj142 constdc1bb6655fb38bdb032e3754) (let __tconst8xRt151 const3a82152bd1402931076fe2d7) (let __tconst8eg8132 const361d5df359e0d7681220d09d)) (probe lambda (1 2 0) 1 __tconst3Taj142 __t25NQ141 __t2Ce3143) (body (exists ref (1 0) 1 __tconst8eg8132) (exists lambda (1 2 0) 1 __tconst8eg8132) (exists ref (1 0) 1 __tconst0zC2144) (exists ref (1 0) 1 __tconst8xRt151) (exists lambda (1 2 0) 1 __tconst8xRt151) (join ref (1 0) 1 __tconst3Taj142 __t93Xi135) (join app (2 0 1) 2 __t93Xi135 __t25NQ141 __t8dYW140) (join ref (1 0) 1 __tconst8eg8132 __t19JM131) (join lambda (1 2 0) 2 __tconst8eg8132 __t19JM131 __t4DXA133) (join ref (1 0) 1 __tconst0zC2144 __t7VSc137) (join app (0 1 2) 2 __t8dYW140 __t7VSc137 dup3o62399) (eq __t7VSc137 dup3o62399) (join ref (1 0) 1 __tconst8xRt151 __t1g2P147) (join app (1 2 0) 1 __t1g2P147 dup6Dxa400 __t9UZN150) (eq __t1g2P147 dup6Dxa400) (join lambda (1 2 0) 2 __tconst8xRt151 __t9UZN150 __t2nYy152)) (head (mkstruct lambda (1 2 0) __t6t5O145 __tconst0zC2144 __t2Ce3143)) mcfa-counting.slog:224 #f)
  class ReadTask1093 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** refindex1079;  slog::Index** lambdaindex1080;  slog::Index** refindex1081;  slog::Index** refindex1082;  slog::Index** lambdaindex1083;  slog::Index** refindex1084;  slog::Index** appindex1085;  slog::Index** refindex1086;  slog::Index** lambdaindex1087;  slog::Index** refindex1088;  slog::Index** appindex1089;  slog::Index** refindex1090;  slog::Index** appindex1091;  slog::Index** lambdaindex1092;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      std::vector<u16> ord1094({1, 2, 0});
      slog::Relation* readrel1095 = db->getRelation("lambda");
      driver_index = readrel1095->getIndex(ord1094, true);
      std::vector<u16> ord1096({1, 0});
      slog::Relation* readrel1097 = db->getRelation("ref");
      refindex1079 = readrel1097->getIndex(ord1096, false);
      std::vector<u16> ord1098({1, 2, 0});
      slog::Relation* readrel1099 = db->getRelation("lambda");
      lambdaindex1080 = readrel1099->getIndex(ord1098, false);
      std::vector<u16> ord1100({1, 0});
      slog::Relation* readrel1101 = db->getRelation("ref");
      refindex1081 = readrel1101->getIndex(ord1100, false);
      std::vector<u16> ord1102({1, 0});
      slog::Relation* readrel1103 = db->getRelation("ref");
      refindex1082 = readrel1103->getIndex(ord1102, false);
      std::vector<u16> ord1104({1, 2, 0});
      slog::Relation* readrel1105 = db->getRelation("lambda");
      lambdaindex1083 = readrel1105->getIndex(ord1104, false);
      std::vector<u16> ord1106({1, 0});
      slog::Relation* readrel1107 = db->getRelation("ref");
      refindex1084 = readrel1107->getIndex(ord1106, false);
      std::vector<u16> ord1108({2, 0, 1});
      slog::Relation* readrel1109 = db->getRelation("app");
      appindex1085 = readrel1109->getIndex(ord1108, false);
      std::vector<u16> ord1110({1, 0});
      slog::Relation* readrel1111 = db->getRelation("ref");
      refindex1086 = readrel1111->getIndex(ord1110, false);
      std::vector<u16> ord1112({1, 2, 0});
      slog::Relation* readrel1113 = db->getRelation("lambda");
      lambdaindex1087 = readrel1113->getIndex(ord1112, false);
      std::vector<u16> ord1114({1, 0});
      slog::Relation* readrel1115 = db->getRelation("ref");
      refindex1088 = readrel1115->getIndex(ord1114, false);
      std::vector<u16> ord1116({0, 1, 2});
      slog::Relation* readrel1117 = db->getRelation("app");
      appindex1089 = readrel1117->getIndex(ord1116, false);
      std::vector<u16> ord1118({1, 0});
      slog::Relation* readrel1119 = db->getRelation("ref");
      refindex1090 = readrel1119->getIndex(ord1118, false);
      std::vector<u16> ord1120({1, 2, 0});
      slog::Relation* readrel1121 = db->getRelation("app");
      appindex1091 = readrel1121->getIndex(ord1120, false);
      std::vector<u16> ord1122({1, 2, 0});
      slog::Relation* readrel1123 = db->getRelation("lambda");
      lambdaindex1092 = readrel1123->getIndex(ord1122, false);
  
    }
    ReadTask1093(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c92 = v_const4e3b5454cf93e32fad90650d;
      u64 v_c94 = v_constdc1bb6655fb38bdb032e3754;
      u64 v_c93 = v_const3a82152bd1402931076fe2d7;
      u64 v_c91 = v_const361d5df359e0d7681220d09d;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c94, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1124) {
        u64 v_c105 = m1124[1];
        u64 v_c106 = m1124[2];
        if (buckethash(v_c105) != bucket) return;
        if (!slog::exists_probe<2,1>(refindex1079, std::array<u64,2>{v_c91, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1080, std::array<u64,3>{v_c91, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1081, std::array<u64,2>{v_c92, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1082, std::array<u64,2>{v_c93, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1083, std::array<u64,3>{v_c93, 0, 0})) return;
        slog::join_probe<2,1>(refindex1084, std::array<u64,2>{v_c94, 0}, [&](const std::array<u64,2>& m1125) {
          u64 v_c98 = m1125[1];
          slog::join_probe<3,2>(appindex1085, std::array<u64,3>{v_c98, v_c105, 0}, [&](const std::array<u64,3>& m1126) {
            u64 v_c104 = m1126[2];
            slog::join_probe<2,1>(refindex1086, std::array<u64,2>{v_c91, 0}, [&](const std::array<u64,2>& m1127) {
              u64 v_c95 = m1127[1];
              slog::join_probe<3,2>(lambdaindex1087, std::array<u64,3>{v_c91, v_c95, 0}, [&](const std::array<u64,3>& m1128) {
                u64 v_c96 = m1128[2];
                slog::join_probe<2,1>(refindex1088, std::array<u64,2>{v_c92, 0}, [&](const std::array<u64,2>& m1129) {
                  u64 v_c99 = m1129[1];
                  slog::join_probe<3,2>(appindex1089, std::array<u64,3>{v_c104, v_c99, 0}, [&](const std::array<u64,3>& m1130) {
                    u64 v_c144 = m1130[2];
                    if (v_c99 != v_c144) return;
                    slog::join_probe<2,1>(refindex1090, std::array<u64,2>{v_c93, 0}, [&](const std::array<u64,2>& m1131) {
                      u64 v_c97 = m1131[1];
                      slog::join_probe<3,1>(appindex1091, std::array<u64,3>{v_c97, 0, 0}, [&](const std::array<u64,3>& m1132) {
                        u64 v_c145 = m1132[1]; u64 v_c101 = m1132[2];
                        if (v_c97 != v_c145) return;
                        slog::join_probe<3,2>(lambdaindex1092, std::array<u64,3>{v_c93, v_c101, 0}, [&](const std::array<u64,3>& m1133) {
                          u64 v_c102 = m1133[2];
                          ++_fires;
                          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c92, v_c106}, std::array<u16,3>{1, 2, 0});
                        });
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
        ReadTask1093* _cont = new ReadTask1093(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1093(db,b), false);
  // (crule (pre) (scan app __t8Cmz156 ef ea) (body (join freevar (1 0) 1 ea x)) (head (emit freevar (0 1) x __t8Cmz156)) freevars.slog:13 #f)
  class ReadTask1135 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** freevarindex1134;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("freevar");
      std::vector<u16> ord1136({0, 1});
      slog::Relation* readrel1137 = db->getRelation("freevar");
      head_index[0] = readrel1137->getIndex(ord1136, false);
      outer_rel = db->getRelation("app");
      std::vector<u16> ord1138({1, 0});
      slog::Relation* readrel1139 = db->getRelation("freevar");
      freevarindex1134 = readrel1139->getIndex(ord1138, false);
  
    }
    ReadTask1135(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c146 = _t[0];
        u64 v_c1 = _t[1];
        u64 v_c2 = _t[2];
        slog::join_probe<2,1>(freevarindex1134, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m1140) {
          u64 v_c70 = m1140[1];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c70, v_c146}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:13", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask1135* _cont = new ReadTask1135(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1135(db,b), false);
  // (crule (pre) (scan lambda __t0Tt63 x eb) (body (join freevar (1 0) 1 eb y) (neq x y)) (head (emit freevar (0 1) y __t0Tt63)) freevars.slog:18 #f)
  class ReadTask1142 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** freevarindex1141;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("freevar");
      std::vector<u16> ord1143({0, 1});
      slog::Relation* readrel1144 = db->getRelation("freevar");
      head_index[0] = readrel1144->getIndex(ord1143, false);
      outer_rel = db->getRelation("lambda");
      std::vector<u16> ord1145({1, 0});
      slog::Relation* readrel1146 = db->getRelation("freevar");
      freevarindex1141 = readrel1146->getIndex(ord1145, false);
  
    }
    ReadTask1142(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c147 = _t[0];
        u64 v_c70 = _t[1];
        u64 v_c68 = _t[2];
        slog::join_probe<2,1>(freevarindex1141, std::array<u64,2>{v_c68, 0}, [&](const std::array<u64,2>& m1147) {
          u64 v_c148 = m1147[1];
          if (v_c70 == v_c148) return;
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c148, v_c147}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("freevars.slog:18", "delta:lambda", _fires);
  
      if (!_done)
      {
        ReadTask1142* _cont = new ReadTask1142(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1142(db,b), false);
  // (crule (pre (let __tconst2x2f244 consta32d5a443def48e6d64c6f4b) (let __tconst4Sko246 consteb793a6f75d6cfe49d3c2c90) (let __tconst4N2q248 constaaaad65142343c54348db5d0) (let __tconst7sqz226 const7b8fd91ee9ff10cfbb8066bf) (let __tconst1EUj230 const615ad01b1c532bb6634df115) (let __tconst2VuQ234 const4492fd5fa4baacfebd29f5e5)) (seeded) (body (join ref (1 0) 1 __tconst2x2f244 __t3pbc237) (exists lambda (1 2 0) 1 __tconst2VuQ234) (exists ref (1 0) 1 __tconst1EUj230) (exists lambda (1 2 0) 1 __tconst1EUj230) (exists ref (1 0) 1 __tconst7sqz226) (exists lambda (1 2 0) 1 __tconst7sqz226) (exists ref (1 0) 1 __tconst4N2q248) (exists ref (1 0) 1 __tconst4Sko246) (exists app (2 0 1) 1 __t3pbc237) (exists lambda (1 2 0) 1 __tconst2x2f244) (join ref (1 0) 1 __tconst2VuQ234 __t2PLq233) (join lambda (1 2 0) 2 __tconst2VuQ234 __t2PLq233 __t45rU235) (join ref (1 0) 1 __tconst1EUj230 __t3WVP229) (join lambda (1 2 0) 2 __tconst1EUj230 __t3WVP229 __t5ryk231) (join ref (1 0) 1 __tconst7sqz226 __t5APF225) (join lambda (1 2 0) 2 __tconst7sqz226 __t5APF225 __t2BAX227) (join ref (1 0) 1 __tconst4N2q248 __t6KL4241) (exists app (1 2 0) 1 __t6KL4241) (join ref (1 0) 1 __tconst4Sko246 __t16jv239) (join app (1 2 0) 2 __t6KL4241 __t16jv239 __t4wvK242) (join app (1 2 0) 2 __t4wvK242 __t3pbc237 __t5h6K243) (join lambda (1 2 0) 2 __tconst2x2f244 __t5h6K243 __t3laZ245)) (head (mkstruct lambda (1 2 0) __t7yz1247 __tconst4Sko246 __t3laZ245)) mcfa-counting.slog:272 #f)
  class ReadTask1170 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** refindex1148;  slog::Index** lambdaindex1149;  slog::Index** refindex1150;  slog::Index** lambdaindex1151;  slog::Index** refindex1152;  slog::Index** lambdaindex1153;  slog::Index** refindex1154;  slog::Index** refindex1155;  slog::Index** appindex1156;  slog::Index** lambdaindex1157;  slog::Index** refindex1158;  slog::Index** lambdaindex1159;  slog::Index** refindex1160;  slog::Index** lambdaindex1161;  slog::Index** refindex1162;  slog::Index** lambdaindex1163;  slog::Index** refindex1164;  slog::Index** appindex1165;  slog::Index** refindex1166;  slog::Index** appindex1167;  slog::Index** appindex1168;  slog::Index** lambdaindex1169;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      std::vector<u16> ord1171({1, 2, 0});
      slog::Relation* readrel1172 = db->getRelation("lambda");
      head_index[0] = readrel1172->getIndex(ord1171, false);
      std::vector<u16> ord1173({1, 0});
      slog::Relation* readrel1174 = db->getRelation("ref");
      refindex1148 = readrel1174->getIndex(ord1173, false);
      std::vector<u16> ord1175({1, 2, 0});
      slog::Relation* readrel1176 = db->getRelation("lambda");
      lambdaindex1149 = readrel1176->getIndex(ord1175, false);
      std::vector<u16> ord1177({1, 0});
      slog::Relation* readrel1178 = db->getRelation("ref");
      refindex1150 = readrel1178->getIndex(ord1177, false);
      std::vector<u16> ord1179({1, 2, 0});
      slog::Relation* readrel1180 = db->getRelation("lambda");
      lambdaindex1151 = readrel1180->getIndex(ord1179, false);
      std::vector<u16> ord1181({1, 0});
      slog::Relation* readrel1182 = db->getRelation("ref");
      refindex1152 = readrel1182->getIndex(ord1181, false);
      std::vector<u16> ord1183({1, 2, 0});
      slog::Relation* readrel1184 = db->getRelation("lambda");
      lambdaindex1153 = readrel1184->getIndex(ord1183, false);
      std::vector<u16> ord1185({1, 0});
      slog::Relation* readrel1186 = db->getRelation("ref");
      refindex1154 = readrel1186->getIndex(ord1185, false);
      std::vector<u16> ord1187({1, 0});
      slog::Relation* readrel1188 = db->getRelation("ref");
      refindex1155 = readrel1188->getIndex(ord1187, false);
      std::vector<u16> ord1189({2, 0, 1});
      slog::Relation* readrel1190 = db->getRelation("app");
      appindex1156 = readrel1190->getIndex(ord1189, false);
      std::vector<u16> ord1191({1, 2, 0});
      slog::Relation* readrel1192 = db->getRelation("lambda");
      lambdaindex1157 = readrel1192->getIndex(ord1191, false);
      std::vector<u16> ord1193({1, 0});
      slog::Relation* readrel1194 = db->getRelation("ref");
      refindex1158 = readrel1194->getIndex(ord1193, false);
      std::vector<u16> ord1195({1, 2, 0});
      slog::Relation* readrel1196 = db->getRelation("lambda");
      lambdaindex1159 = readrel1196->getIndex(ord1195, false);
      std::vector<u16> ord1197({1, 0});
      slog::Relation* readrel1198 = db->getRelation("ref");
      refindex1160 = readrel1198->getIndex(ord1197, false);
      std::vector<u16> ord1199({1, 2, 0});
      slog::Relation* readrel1200 = db->getRelation("lambda");
      lambdaindex1161 = readrel1200->getIndex(ord1199, false);
      std::vector<u16> ord1201({1, 0});
      slog::Relation* readrel1202 = db->getRelation("ref");
      refindex1162 = readrel1202->getIndex(ord1201, false);
      std::vector<u16> ord1203({1, 2, 0});
      slog::Relation* readrel1204 = db->getRelation("lambda");
      lambdaindex1163 = readrel1204->getIndex(ord1203, false);
      std::vector<u16> ord1205({1, 0});
      slog::Relation* readrel1206 = db->getRelation("ref");
      refindex1164 = readrel1206->getIndex(ord1205, false);
      std::vector<u16> ord1207({1, 2, 0});
      slog::Relation* readrel1208 = db->getRelation("app");
      appindex1165 = readrel1208->getIndex(ord1207, false);
      std::vector<u16> ord1209({1, 0});
      slog::Relation* readrel1210 = db->getRelation("ref");
      refindex1166 = readrel1210->getIndex(ord1209, false);
      std::vector<u16> ord1211({1, 2, 0});
      slog::Relation* readrel1212 = db->getRelation("app");
      appindex1167 = readrel1212->getIndex(ord1211, false);
      std::vector<u16> ord1213({1, 2, 0});
      slog::Relation* readrel1214 = db->getRelation("app");
      appindex1168 = readrel1214->getIndex(ord1213, false);
      std::vector<u16> ord1215({1, 2, 0});
      slog::Relation* readrel1216 = db->getRelation("lambda");
      lambdaindex1169 = readrel1216->getIndex(ord1215, false);
  
    }
    ReadTask1170(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c149 = v_consta32d5a443def48e6d64c6f4b;
      u64 v_c150 = v_consteb793a6f75d6cfe49d3c2c90;
      u64 v_c151 = v_constaaaad65142343c54348db5d0;
      u64 v_c152 = v_const7b8fd91ee9ff10cfbb8066bf;
      u64 v_c153 = v_const615ad01b1c532bb6634df115;
      u64 v_c154 = v_const4492fd5fa4baacfebd29f5e5;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(refindex1148, std::array<u64,2>{v_c149, 0}, [&](const std::array<u64,2>& m1217) {
        u64 v_c155 = m1217[1];
        if (!slog::exists_probe<3,1>(lambdaindex1149, std::array<u64,3>{v_c154, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1150, std::array<u64,2>{v_c153, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1151, std::array<u64,3>{v_c153, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1152, std::array<u64,2>{v_c152, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1153, std::array<u64,3>{v_c152, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1154, std::array<u64,2>{v_c151, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1155, std::array<u64,2>{v_c150, 0})) return;
        if (!slog::exists_probe<3,1>(appindex1156, std::array<u64,3>{v_c155, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1157, std::array<u64,3>{v_c149, 0, 0})) return;
        slog::join_probe<2,1>(refindex1158, std::array<u64,2>{v_c154, 0}, [&](const std::array<u64,2>& m1218) {
          u64 v_c156 = m1218[1];
          slog::join_probe<3,2>(lambdaindex1159, std::array<u64,3>{v_c154, v_c156, 0}, [&](const std::array<u64,3>& m1219) {
            u64 v_c157 = m1219[2];
            slog::join_probe<2,1>(refindex1160, std::array<u64,2>{v_c153, 0}, [&](const std::array<u64,2>& m1220) {
              u64 v_c158 = m1220[1];
              slog::join_probe<3,2>(lambdaindex1161, std::array<u64,3>{v_c153, v_c158, 0}, [&](const std::array<u64,3>& m1221) {
                u64 v_c159 = m1221[2];
                slog::join_probe<2,1>(refindex1162, std::array<u64,2>{v_c152, 0}, [&](const std::array<u64,2>& m1222) {
                  u64 v_c160 = m1222[1];
                  slog::join_probe<3,2>(lambdaindex1163, std::array<u64,3>{v_c152, v_c160, 0}, [&](const std::array<u64,3>& m1223) {
                    u64 v_c161 = m1223[2];
                    slog::join_probe<2,1>(refindex1164, std::array<u64,2>{v_c151, 0}, [&](const std::array<u64,2>& m1224) {
                      u64 v_c162 = m1224[1];
                      if (!slog::exists_probe<3,1>(appindex1165, std::array<u64,3>{v_c162, 0, 0})) return;
                      slog::join_probe<2,1>(refindex1166, std::array<u64,2>{v_c150, 0}, [&](const std::array<u64,2>& m1225) {
                        u64 v_c163 = m1225[1];
                        slog::join_probe<3,2>(appindex1167, std::array<u64,3>{v_c162, v_c163, 0}, [&](const std::array<u64,3>& m1226) {
                          u64 v_c164 = m1226[2];
                          slog::join_probe<3,2>(appindex1168, std::array<u64,3>{v_c164, v_c155, 0}, [&](const std::array<u64,3>& m1227) {
                            u64 v_c165 = m1227[2];
                            slog::join_probe<3,2>(lambdaindex1169, std::array<u64,3>{v_c149, v_c165, 0}, [&](const std::array<u64,3>& m1228) {
                              u64 v_c166 = m1228[2];
                              ++_fires;
                              slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c150, v_c166}, std::array<u16,3>{1, 2, 0});
                            });
                          });
                        });
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
      s->addTaskSeeded(phase_read, new ReadTask1170(db,b));
  // (crule (pre (let __tconst7JVW192 const6cf13cc59dcbe759113f68a4) (let __tconst7B9N190 constcaa3ee5a2828a31924f6b39d) (let __tconst5wC2180 const970c20ea81b833e5b5a7accf) (let __tconst2ady176 constc40f204dda7ba4054abb9e74)) (probe lambda (1 2 0) 1 __tconst2ady176 __t3ZY4175 __t1Ls4177) (body (join ref (0 1) 2 __t3ZY4175 __tconst2ady176) (exists lambda (1 2 0) 1 __tconst5wC2180) (exists ref (1 0) 1 __tconst7B9N190) (exists ref (1 0) 1 __tconst7JVW192) (join ref (1 0) 1 __tconst5wC2180 __t52sB179) (join lambda (1 2 0) 2 __tconst5wC2180 __t52sB179 __t6CST181) (join ref (1 0) 1 __tconst7B9N190 __t8oRJ183) (exists app (2 0 1) 1 __t8oRJ183) (join ref (1 0) 1 __tconst7JVW192 __t6fOY185) (join app (1 2 0) 2 __t6fOY185 __t8oRJ183 __t2CTd186)) (head (mkstruct app (1 2 0) __t9pbS189 __t6fOY185 __t2CTd186)) mcfa-counting.slog:301 #f)
  class ReadTask1239 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** refindex1229;  slog::Index** lambdaindex1230;  slog::Index** refindex1231;  slog::Index** refindex1232;  slog::Index** refindex1233;  slog::Index** lambdaindex1234;  slog::Index** refindex1235;  slog::Index** appindex1236;  slog::Index** refindex1237;  slog::Index** appindex1238;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord1240({1, 2, 0});
      slog::Relation* readrel1241 = db->getRelation("lambda");
      driver_index = readrel1241->getIndex(ord1240, true);
      std::vector<u16> ord1242({0, 1});
      slog::Relation* readrel1243 = db->getRelation("ref");
      refindex1229 = readrel1243->getIndex(ord1242, false);
      std::vector<u16> ord1244({1, 2, 0});
      slog::Relation* readrel1245 = db->getRelation("lambda");
      lambdaindex1230 = readrel1245->getIndex(ord1244, false);
      std::vector<u16> ord1246({1, 0});
      slog::Relation* readrel1247 = db->getRelation("ref");
      refindex1231 = readrel1247->getIndex(ord1246, false);
      std::vector<u16> ord1248({1, 0});
      slog::Relation* readrel1249 = db->getRelation("ref");
      refindex1232 = readrel1249->getIndex(ord1248, false);
      std::vector<u16> ord1250({1, 0});
      slog::Relation* readrel1251 = db->getRelation("ref");
      refindex1233 = readrel1251->getIndex(ord1250, false);
      std::vector<u16> ord1252({1, 2, 0});
      slog::Relation* readrel1253 = db->getRelation("lambda");
      lambdaindex1234 = readrel1253->getIndex(ord1252, false);
      std::vector<u16> ord1254({1, 0});
      slog::Relation* readrel1255 = db->getRelation("ref");
      refindex1235 = readrel1255->getIndex(ord1254, false);
      std::vector<u16> ord1256({2, 0, 1});
      slog::Relation* readrel1257 = db->getRelation("app");
      appindex1236 = readrel1257->getIndex(ord1256, false);
      std::vector<u16> ord1258({1, 0});
      slog::Relation* readrel1259 = db->getRelation("ref");
      refindex1237 = readrel1259->getIndex(ord1258, false);
      std::vector<u16> ord1260({1, 2, 0});
      slog::Relation* readrel1261 = db->getRelation("app");
      appindex1238 = readrel1261->getIndex(ord1260, false);
  
    }
    ReadTask1239(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c77 = v_const6cf13cc59dcbe759113f68a4;
      u64 v_c78 = v_constcaa3ee5a2828a31924f6b39d;
      u64 v_c79 = v_const970c20ea81b833e5b5a7accf;
      u64 v_c80 = v_constc40f204dda7ba4054abb9e74;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c80, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1262) {
        u64 v_c84 = m1262[1];
        u64 v_c85 = m1262[2];
        if (buckethash(v_c84) != bucket) return;
        slog::join_probe<2,2>(refindex1229, std::array<u64,2>{v_c84, v_c80}, [&](const std::array<u64,2>& m1263) {
          if (!slog::exists_probe<3,1>(lambdaindex1230, std::array<u64,3>{v_c79, 0, 0})) return;
          if (!slog::exists_probe<2,1>(refindex1231, std::array<u64,2>{v_c78, 0})) return;
          if (!slog::exists_probe<2,1>(refindex1232, std::array<u64,2>{v_c77, 0})) return;
          slog::join_probe<2,1>(refindex1233, std::array<u64,2>{v_c79, 0}, [&](const std::array<u64,2>& m1264) {
            u64 v_c86 = m1264[1];
            slog::join_probe<3,2>(lambdaindex1234, std::array<u64,3>{v_c79, v_c86, 0}, [&](const std::array<u64,3>& m1265) {
              u64 v_c87 = m1265[2];
              slog::join_probe<2,1>(refindex1235, std::array<u64,2>{v_c78, 0}, [&](const std::array<u64,2>& m1266) {
                u64 v_c90 = m1266[1];
                if (!slog::exists_probe<3,1>(appindex1236, std::array<u64,3>{v_c90, 0, 0})) return;
                slog::join_probe<2,1>(refindex1237, std::array<u64,2>{v_c77, 0}, [&](const std::array<u64,2>& m1267) {
                  u64 v_c88 = m1267[1];
                  slog::join_probe<3,2>(appindex1238, std::array<u64,3>{v_c88, v_c90, 0}, [&](const std::array<u64,3>& m1268) {
                    u64 v_c89 = m1268[2];
                    ++_fires;
                    slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c88, v_c89}, std::array<u16,3>{1, 2, 0});
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
        ReadTask1239* _cont = new ReadTask1239(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1239(db,b), false);
  // (crule (pre (let __tconst2x2f244 consta32d5a443def48e6d64c6f4b) (let __tconst4Sko246 consteb793a6f75d6cfe49d3c2c90) (let __tconst4N2q248 constaaaad65142343c54348db5d0) (let __tconst7sqz226 const7b8fd91ee9ff10cfbb8066bf) (let __tconst1EUj230 const615ad01b1c532bb6634df115) (let __tconst2VuQ234 const4492fd5fa4baacfebd29f5e5)) (probe lambda (1 2 0) 1 __tconst2x2f244 __t5h6K243 __t3laZ245) (body (exists ref (1 0) 1 __tconst2VuQ234) (exists lambda (1 2 0) 1 __tconst2VuQ234) (exists ref (1 0) 1 __tconst1EUj230) (exists lambda (1 2 0) 1 __tconst1EUj230) (exists ref (1 0) 1 __tconst7sqz226) (exists lambda (1 2 0) 1 __tconst7sqz226) (exists ref (1 0) 1 __tconst4N2q248) (exists ref (1 0) 1 __tconst4Sko246) (join ref (1 0) 1 __tconst2x2f244 __t3pbc237) (join app (2 0 1) 2 __t3pbc237 __t5h6K243 __t4wvK242) (join ref (1 0) 1 __tconst2VuQ234 __t2PLq233) (join lambda (1 2 0) 2 __tconst2VuQ234 __t2PLq233 __t45rU235) (join ref (1 0) 1 __tconst1EUj230 __t3WVP229) (join lambda (1 2 0) 2 __tconst1EUj230 __t3WVP229 __t5ryk231) (join ref (1 0) 1 __tconst7sqz226 __t5APF225) (join lambda (1 2 0) 2 __tconst7sqz226 __t5APF225 __t2BAX227) (join ref (1 0) 1 __tconst4N2q248 __t6KL4241) (join app (0 1 2) 2 __t4wvK242 __t6KL4241 __t16jv239) (join ref (0 1) 2 __t16jv239 __tconst4Sko246)) (head (mkstruct lambda (1 2 0) __t7yz1247 __tconst4Sko246 __t3laZ245)) mcfa-counting.slog:272 #f)
  class ReadTask1288 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** refindex1269;  slog::Index** lambdaindex1270;  slog::Index** refindex1271;  slog::Index** lambdaindex1272;  slog::Index** refindex1273;  slog::Index** lambdaindex1274;  slog::Index** refindex1275;  slog::Index** refindex1276;  slog::Index** refindex1277;  slog::Index** appindex1278;  slog::Index** refindex1279;  slog::Index** lambdaindex1280;  slog::Index** refindex1281;  slog::Index** lambdaindex1282;  slog::Index** refindex1283;  slog::Index** lambdaindex1284;  slog::Index** refindex1285;  slog::Index** appindex1286;  slog::Index** refindex1287;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lambda");
      std::vector<u16> ord1289({1, 2, 0});
      slog::Relation* readrel1290 = db->getRelation("lambda");
      driver_index = readrel1290->getIndex(ord1289, true);
      std::vector<u16> ord1291({1, 0});
      slog::Relation* readrel1292 = db->getRelation("ref");
      refindex1269 = readrel1292->getIndex(ord1291, false);
      std::vector<u16> ord1293({1, 2, 0});
      slog::Relation* readrel1294 = db->getRelation("lambda");
      lambdaindex1270 = readrel1294->getIndex(ord1293, false);
      std::vector<u16> ord1295({1, 0});
      slog::Relation* readrel1296 = db->getRelation("ref");
      refindex1271 = readrel1296->getIndex(ord1295, false);
      std::vector<u16> ord1297({1, 2, 0});
      slog::Relation* readrel1298 = db->getRelation("lambda");
      lambdaindex1272 = readrel1298->getIndex(ord1297, false);
      std::vector<u16> ord1299({1, 0});
      slog::Relation* readrel1300 = db->getRelation("ref");
      refindex1273 = readrel1300->getIndex(ord1299, false);
      std::vector<u16> ord1301({1, 2, 0});
      slog::Relation* readrel1302 = db->getRelation("lambda");
      lambdaindex1274 = readrel1302->getIndex(ord1301, false);
      std::vector<u16> ord1303({1, 0});
      slog::Relation* readrel1304 = db->getRelation("ref");
      refindex1275 = readrel1304->getIndex(ord1303, false);
      std::vector<u16> ord1305({1, 0});
      slog::Relation* readrel1306 = db->getRelation("ref");
      refindex1276 = readrel1306->getIndex(ord1305, false);
      std::vector<u16> ord1307({1, 0});
      slog::Relation* readrel1308 = db->getRelation("ref");
      refindex1277 = readrel1308->getIndex(ord1307, false);
      std::vector<u16> ord1309({2, 0, 1});
      slog::Relation* readrel1310 = db->getRelation("app");
      appindex1278 = readrel1310->getIndex(ord1309, false);
      std::vector<u16> ord1311({1, 0});
      slog::Relation* readrel1312 = db->getRelation("ref");
      refindex1279 = readrel1312->getIndex(ord1311, false);
      std::vector<u16> ord1313({1, 2, 0});
      slog::Relation* readrel1314 = db->getRelation("lambda");
      lambdaindex1280 = readrel1314->getIndex(ord1313, false);
      std::vector<u16> ord1315({1, 0});
      slog::Relation* readrel1316 = db->getRelation("ref");
      refindex1281 = readrel1316->getIndex(ord1315, false);
      std::vector<u16> ord1317({1, 2, 0});
      slog::Relation* readrel1318 = db->getRelation("lambda");
      lambdaindex1282 = readrel1318->getIndex(ord1317, false);
      std::vector<u16> ord1319({1, 0});
      slog::Relation* readrel1320 = db->getRelation("ref");
      refindex1283 = readrel1320->getIndex(ord1319, false);
      std::vector<u16> ord1321({1, 2, 0});
      slog::Relation* readrel1322 = db->getRelation("lambda");
      lambdaindex1284 = readrel1322->getIndex(ord1321, false);
      std::vector<u16> ord1323({1, 0});
      slog::Relation* readrel1324 = db->getRelation("ref");
      refindex1285 = readrel1324->getIndex(ord1323, false);
      std::vector<u16> ord1325({0, 1, 2});
      slog::Relation* readrel1326 = db->getRelation("app");
      appindex1286 = readrel1326->getIndex(ord1325, false);
      std::vector<u16> ord1327({0, 1});
      slog::Relation* readrel1328 = db->getRelation("ref");
      refindex1287 = readrel1328->getIndex(ord1327, false);
  
    }
    ReadTask1288(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c149 = v_consta32d5a443def48e6d64c6f4b;
      u64 v_c150 = v_consteb793a6f75d6cfe49d3c2c90;
      u64 v_c151 = v_constaaaad65142343c54348db5d0;
      u64 v_c152 = v_const7b8fd91ee9ff10cfbb8066bf;
      u64 v_c153 = v_const615ad01b1c532bb6634df115;
      u64 v_c154 = v_const4492fd5fa4baacfebd29f5e5;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c149, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m1329) {
        u64 v_c165 = m1329[1];
        u64 v_c166 = m1329[2];
        if (buckethash(v_c165) != bucket) return;
        if (!slog::exists_probe<2,1>(refindex1269, std::array<u64,2>{v_c154, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1270, std::array<u64,3>{v_c154, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1271, std::array<u64,2>{v_c153, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1272, std::array<u64,3>{v_c153, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1273, std::array<u64,2>{v_c152, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1274, std::array<u64,3>{v_c152, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1275, std::array<u64,2>{v_c151, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1276, std::array<u64,2>{v_c150, 0})) return;
        slog::join_probe<2,1>(refindex1277, std::array<u64,2>{v_c149, 0}, [&](const std::array<u64,2>& m1330) {
          u64 v_c155 = m1330[1];
          slog::join_probe<3,2>(appindex1278, std::array<u64,3>{v_c155, v_c165, 0}, [&](const std::array<u64,3>& m1331) {
            u64 v_c164 = m1331[2];
            slog::join_probe<2,1>(refindex1279, std::array<u64,2>{v_c154, 0}, [&](const std::array<u64,2>& m1332) {
              u64 v_c156 = m1332[1];
              slog::join_probe<3,2>(lambdaindex1280, std::array<u64,3>{v_c154, v_c156, 0}, [&](const std::array<u64,3>& m1333) {
                u64 v_c157 = m1333[2];
                slog::join_probe<2,1>(refindex1281, std::array<u64,2>{v_c153, 0}, [&](const std::array<u64,2>& m1334) {
                  u64 v_c158 = m1334[1];
                  slog::join_probe<3,2>(lambdaindex1282, std::array<u64,3>{v_c153, v_c158, 0}, [&](const std::array<u64,3>& m1335) {
                    u64 v_c159 = m1335[2];
                    slog::join_probe<2,1>(refindex1283, std::array<u64,2>{v_c152, 0}, [&](const std::array<u64,2>& m1336) {
                      u64 v_c160 = m1336[1];
                      slog::join_probe<3,2>(lambdaindex1284, std::array<u64,3>{v_c152, v_c160, 0}, [&](const std::array<u64,3>& m1337) {
                        u64 v_c161 = m1337[2];
                        slog::join_probe<2,1>(refindex1285, std::array<u64,2>{v_c151, 0}, [&](const std::array<u64,2>& m1338) {
                          u64 v_c162 = m1338[1];
                          slog::join_probe<3,2>(appindex1286, std::array<u64,3>{v_c164, v_c162, 0}, [&](const std::array<u64,3>& m1339) {
                            u64 v_c163 = m1339[2];
                            slog::join_probe<2,2>(refindex1287, std::array<u64,2>{v_c163, v_c150}, [&](const std::array<u64,2>& m1340) {
                              ++_fires;
                              slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c150, v_c166}, std::array<u16,3>{1, 2, 0});
                            });
                          });
                        });
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
        ReadTask1288* _cont = new ReadTask1288(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1288(db,b), false);
  // (crule (pre (let __tconst0y6X73 const0aa6f87434af0222b916e97a) (let __tconst7zoP70 const227d34ceeba7a29aada993d4) (let __tconst1bfe65 const59ba3256d223f0d0a00d0633) (let __tconst0aL952 constd3d07026d47882ceca728218) (let __tconst8wN863 const7cd75b35aa30c3ddf04f9d57) (let __tconst0xUh47 constf700a82e218a86de572e1f7f)) (scan app __t05NY51 __t5HQ450 __t50zW48) (body (join ref (0 1) 2 __t5HQ450 __tconst0aL952) (exists ref (1 0) 1 __tconst0xUh47) (exists ref (1 0) 1 __tconst0y6X73) (exists ref (1 0) 1 __tconst1bfe65) (exists lambda (1 2 0) 1 __tconst1bfe65) (exists ref (1 0) 1 __tconst8wN863) (exists lambda (1 2 0) 1 __tconst8wN863) (join lambda (0 1 2) 2 __t50zW48 __tconst0xUh47 __t5vZb46) (join ref (0 1) 2 __t5vZb46 __tconst0xUh47) (join ref (1 0) 1 __tconst0y6X73 __t0QRr59) (exists app (1 2 0) 1 __t0QRr59) (join ref (1 0) 1 __tconst1bfe65 __t2HsD55) (join lambda (1 2 0) 2 __tconst1bfe65 __t2HsD55 __t0uNb57) (join app (1 2 0) 2 __t0QRr59 __t0uNb57 __t81HE60) (join ref (1 0) 1 __tconst8wN863 __t1mkO62) (join lambda (1 2 0) 2 __tconst8wN863 __t1mkO62 __t3Dru64) (join lambda (1 2 0) 2 __tconst1bfe65 __t3Dru64 __t7JIT66)) (head (mkstruct app (1 2 0) __t5Ri569 __t0QRr59 __t7JIT66) (mkstruct lambda (1 2 0) __t3xtz53 __tconst0aL952 __t05NY51)) mcfa-counting.slog:287 #f)
  class ReadTask1358 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex1341;  slog::Index** refindex1342;  slog::Index** refindex1343;  slog::Index** refindex1344;  slog::Index** lambdaindex1345;  slog::Index** refindex1346;  slog::Index** lambdaindex1347;  slog::Index** lambdaindex1348;  slog::Index** refindex1349;  slog::Index** refindex1350;  slog::Index** appindex1351;  slog::Index** refindex1352;  slog::Index** lambdaindex1353;  slog::Index** appindex1354;  slog::Index** refindex1355;  slog::Index** lambdaindex1356;  slog::Index** lambdaindex1357;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      head_rel[1] = db->getRelation("lambda");
      outer_rel = db->getRelation("app");
      std::vector<u16> ord1359({0, 1});
      slog::Relation* readrel1360 = db->getRelation("ref");
      refindex1341 = readrel1360->getIndex(ord1359, false);
      std::vector<u16> ord1361({1, 0});
      slog::Relation* readrel1362 = db->getRelation("ref");
      refindex1342 = readrel1362->getIndex(ord1361, false);
      std::vector<u16> ord1363({1, 0});
      slog::Relation* readrel1364 = db->getRelation("ref");
      refindex1343 = readrel1364->getIndex(ord1363, false);
      std::vector<u16> ord1365({1, 0});
      slog::Relation* readrel1366 = db->getRelation("ref");
      refindex1344 = readrel1366->getIndex(ord1365, false);
      std::vector<u16> ord1367({1, 2, 0});
      slog::Relation* readrel1368 = db->getRelation("lambda");
      lambdaindex1345 = readrel1368->getIndex(ord1367, false);
      std::vector<u16> ord1369({1, 0});
      slog::Relation* readrel1370 = db->getRelation("ref");
      refindex1346 = readrel1370->getIndex(ord1369, false);
      std::vector<u16> ord1371({1, 2, 0});
      slog::Relation* readrel1372 = db->getRelation("lambda");
      lambdaindex1347 = readrel1372->getIndex(ord1371, false);
      std::vector<u16> ord1373({0, 1, 2});
      slog::Relation* readrel1374 = db->getRelation("lambda");
      lambdaindex1348 = readrel1374->getIndex(ord1373, false);
      std::vector<u16> ord1375({0, 1});
      slog::Relation* readrel1376 = db->getRelation("ref");
      refindex1349 = readrel1376->getIndex(ord1375, false);
      std::vector<u16> ord1377({1, 0});
      slog::Relation* readrel1378 = db->getRelation("ref");
      refindex1350 = readrel1378->getIndex(ord1377, false);
      std::vector<u16> ord1379({1, 2, 0});
      slog::Relation* readrel1380 = db->getRelation("app");
      appindex1351 = readrel1380->getIndex(ord1379, false);
      std::vector<u16> ord1381({1, 0});
      slog::Relation* readrel1382 = db->getRelation("ref");
      refindex1352 = readrel1382->getIndex(ord1381, false);
      std::vector<u16> ord1383({1, 2, 0});
      slog::Relation* readrel1384 = db->getRelation("lambda");
      lambdaindex1353 = readrel1384->getIndex(ord1383, false);
      std::vector<u16> ord1385({1, 2, 0});
      slog::Relation* readrel1386 = db->getRelation("app");
      appindex1354 = readrel1386->getIndex(ord1385, false);
      std::vector<u16> ord1387({1, 0});
      slog::Relation* readrel1388 = db->getRelation("ref");
      refindex1355 = readrel1388->getIndex(ord1387, false);
      std::vector<u16> ord1389({1, 2, 0});
      slog::Relation* readrel1390 = db->getRelation("lambda");
      lambdaindex1356 = readrel1390->getIndex(ord1389, false);
      std::vector<u16> ord1391({1, 2, 0});
      slog::Relation* readrel1392 = db->getRelation("lambda");
      lambdaindex1357 = readrel1392->getIndex(ord1391, false);
  
    }
    ReadTask1358(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c22 = v_const0aa6f87434af0222b916e97a;
      u64 v_c24 = v_const227d34ceeba7a29aada993d4;
      u64 v_c25 = v_const59ba3256d223f0d0a00d0633;
      u64 v_c23 = v_constd3d07026d47882ceca728218;
      u64 v_c27 = v_const7cd75b35aa30c3ddf04f9d57;
      u64 v_c26 = v_constf700a82e218a86de572e1f7f;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c42 = _t[0];
        u64 v_c31 = _t[1];
        u64 v_c41 = _t[2];
        slog::join_probe<2,2>(refindex1341, std::array<u64,2>{v_c31, v_c23}, [&](const std::array<u64,2>& m1393) {
          if (!slog::exists_probe<2,1>(refindex1342, std::array<u64,2>{v_c26, 0})) return;
          if (!slog::exists_probe<2,1>(refindex1343, std::array<u64,2>{v_c22, 0})) return;
          if (!slog::exists_probe<2,1>(refindex1344, std::array<u64,2>{v_c25, 0})) return;
          if (!slog::exists_probe<3,1>(lambdaindex1345, std::array<u64,3>{v_c25, 0, 0})) return;
          if (!slog::exists_probe<2,1>(refindex1346, std::array<u64,2>{v_c27, 0})) return;
          if (!slog::exists_probe<3,1>(lambdaindex1347, std::array<u64,3>{v_c27, 0, 0})) return;
          slog::join_probe<3,2>(lambdaindex1348, std::array<u64,3>{v_c41, v_c26, 0}, [&](const std::array<u64,3>& m1394) {
            u64 v_c40 = m1394[2];
            slog::join_probe<2,2>(refindex1349, std::array<u64,2>{v_c40, v_c26}, [&](const std::array<u64,2>& m1395) {
              slog::join_probe<2,1>(refindex1350, std::array<u64,2>{v_c22, 0}, [&](const std::array<u64,2>& m1396) {
                u64 v_c30 = m1396[1];
                if (!slog::exists_probe<3,1>(appindex1351, std::array<u64,3>{v_c30, 0, 0})) return;
                slog::join_probe<2,1>(refindex1352, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m1397) {
                  u64 v_c32 = m1397[1];
                  slog::join_probe<3,2>(lambdaindex1353, std::array<u64,3>{v_c25, v_c32, 0}, [&](const std::array<u64,3>& m1398) {
                    u64 v_c33 = m1398[2];
                    slog::join_probe<3,2>(appindex1354, std::array<u64,3>{v_c30, v_c33, 0}, [&](const std::array<u64,3>& m1399) {
                      u64 v_c34 = m1399[2];
                      slog::join_probe<2,1>(refindex1355, std::array<u64,2>{v_c27, 0}, [&](const std::array<u64,2>& m1400) {
                        u64 v_c39 = m1400[1];
                        slog::join_probe<3,2>(lambdaindex1356, std::array<u64,3>{v_c27, v_c39, 0}, [&](const std::array<u64,3>& m1401) {
                          u64 v_c38 = m1401[2];
                          slog::join_probe<3,2>(lambdaindex1357, std::array<u64,3>{v_c25, v_c38, 0}, [&](const std::array<u64,3>& m1402) {
                            u64 v_c37 = m1402[2];
                            ++_fires;
                            slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c30, v_c37}, std::array<u16,3>{1, 2, 0});
                            slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c23, v_c42}, std::array<u16,3>{1, 2, 0});
                          });
                        });
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
  
      if (_fires) db->bumpFires("mcfa-counting.slog:287", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask1358* _cont = new ReadTask1358(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1358(db,b), false);
  // (crule (pre (let __tconst1pJW313 constb49bea2fcccd8f4301a347ed) (let __tconst2Yzp284 const8ca682693a0738a0641c6956) (let __tconst7LWP310 const66518c0c1b3a5a0b09ae2ef1) (let __tconst5PoN291 constc85eae03730a4f4cf1d66a0c) (let __tconst0sqO307 const4a8acfc71441e0695ffcf5b3) (let __tconst9rZO295 const576506f61f53440f1edd95d2) (let __tconst2CSv302 const229c0b7aa8a7eb4055f5a3d0)) (scan app __t1Lkt315 __t7Qbz314 __t0oFu285) (body (exists ref (1 0) 1 __tconst2Yzp284) (exists lambda (0 1 2) 2 __t7Qbz314 __tconst1pJW313) (exists ref (1 0) 1 __tconst1pJW313) (exists ref (1 0) 1 __tconst7LWP310) (exists ref (1 0) 1 __tconst9rZO295) (exists lambda (1 2 0) 1 __tconst9rZO295) (exists ref (1 0) 1 __tconst2CSv302) (exists lambda (1 2 0) 1 __tconst2CSv302) (exists lambda (1 2 0) 1 __tconst0sqO307) (exists lambda (1 2 0) 1 __tconst7LWP310) (exists lambda (1 2 0) 1 __tconst5PoN291) (join lambda (0 1 2) 2 __t0oFu285 __tconst2Yzp284 __t248W283) (join ref (0 1) 2 __t248W283 __tconst2Yzp284) (join lambda (0 1 2) 2 __t7Qbz314 __tconst1pJW313 __t3Izn312) (join ref (1 0) 1 __tconst1pJW313 __t165O287) (exists app (1 2 0) 1 __t165O287) (join ref (1 0) 1 __tconst7LWP310 __t91H2298) (exists app (1 2 0) 1 __t91H2298) (join ref (1 0) 1 __tconst9rZO295 __t71w7294) (join lambda (1 2 0) 2 __tconst9rZO295 __t71w7294 __t3dkk296) (join app (1 2 0) 2 __t91H2298 __t3dkk296 __t4LtH299) (exists app (2 0 1) 1 __t4LtH299) (join ref (1 0) 1 __tconst2CSv302 __t6lXa301) (join lambda (1 2 0) 2 __tconst2CSv302 __t6lXa301 __t7EW2303) (join app (1 2 0) 2 __t91H2298 __t7EW2303 __t4HUX306) (join lambda (1 2 0) 2 __tconst0sqO307 __t4HUX306 __t0vn1308) (join app (1 2 0) 2 __t0vn1308 __t4LtH299 __t6t9L309) (join lambda (1 2 0) 2 __tconst7LWP310 __t6t9L309 __t5T0g311) (join app (0 1 2) 2 __t3Izn312 __t5T0g311 __t7aCZ292) (join lambda (0 1 2) 2 __t7aCZ292 __tconst5PoN291 __t30Ec290) (join app (0 1 2) 2 __t30Ec290 __t165O287 dup4Qjk389) (eq __t165O287 dup4Qjk389)) (head (emit program (0) __t1Lkt315)) mcfa-counting.slog:194 #f)
  class ReadTask1434 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex1403;  slog::Index** lambdaindex1404;  slog::Index** refindex1405;  slog::Index** refindex1406;  slog::Index** refindex1407;  slog::Index** lambdaindex1408;  slog::Index** refindex1409;  slog::Index** lambdaindex1410;  slog::Index** lambdaindex1411;  slog::Index** lambdaindex1412;  slog::Index** lambdaindex1413;  slog::Index** lambdaindex1414;  slog::Index** refindex1415;  slog::Index** lambdaindex1416;  slog::Index** refindex1417;  slog::Index** appindex1418;  slog::Index** refindex1419;  slog::Index** appindex1420;  slog::Index** refindex1421;  slog::Index** lambdaindex1422;  slog::Index** appindex1423;  slog::Index** appindex1424;  slog::Index** refindex1425;  slog::Index** lambdaindex1426;  slog::Index** appindex1427;  slog::Index** lambdaindex1428;  slog::Index** appindex1429;  slog::Index** lambdaindex1430;  slog::Index** appindex1431;  slog::Index** lambdaindex1432;  slog::Index** appindex1433;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("program");
      std::vector<u16> ord1435({0});
      slog::Relation* readrel1436 = db->getRelation("program");
      head_index[0] = readrel1436->getIndex(ord1435, false);
      outer_rel = db->getRelation("app");
      std::vector<u16> ord1437({1, 0});
      slog::Relation* readrel1438 = db->getRelation("ref");
      refindex1403 = readrel1438->getIndex(ord1437, false);
      std::vector<u16> ord1439({0, 1, 2});
      slog::Relation* readrel1440 = db->getRelation("lambda");
      lambdaindex1404 = readrel1440->getIndex(ord1439, false);
      std::vector<u16> ord1441({1, 0});
      slog::Relation* readrel1442 = db->getRelation("ref");
      refindex1405 = readrel1442->getIndex(ord1441, false);
      std::vector<u16> ord1443({1, 0});
      slog::Relation* readrel1444 = db->getRelation("ref");
      refindex1406 = readrel1444->getIndex(ord1443, false);
      std::vector<u16> ord1445({1, 0});
      slog::Relation* readrel1446 = db->getRelation("ref");
      refindex1407 = readrel1446->getIndex(ord1445, false);
      std::vector<u16> ord1447({1, 2, 0});
      slog::Relation* readrel1448 = db->getRelation("lambda");
      lambdaindex1408 = readrel1448->getIndex(ord1447, false);
      std::vector<u16> ord1449({1, 0});
      slog::Relation* readrel1450 = db->getRelation("ref");
      refindex1409 = readrel1450->getIndex(ord1449, false);
      std::vector<u16> ord1451({1, 2, 0});
      slog::Relation* readrel1452 = db->getRelation("lambda");
      lambdaindex1410 = readrel1452->getIndex(ord1451, false);
      std::vector<u16> ord1453({1, 2, 0});
      slog::Relation* readrel1454 = db->getRelation("lambda");
      lambdaindex1411 = readrel1454->getIndex(ord1453, false);
      std::vector<u16> ord1455({1, 2, 0});
      slog::Relation* readrel1456 = db->getRelation("lambda");
      lambdaindex1412 = readrel1456->getIndex(ord1455, false);
      std::vector<u16> ord1457({1, 2, 0});
      slog::Relation* readrel1458 = db->getRelation("lambda");
      lambdaindex1413 = readrel1458->getIndex(ord1457, false);
      std::vector<u16> ord1459({0, 1, 2});
      slog::Relation* readrel1460 = db->getRelation("lambda");
      lambdaindex1414 = readrel1460->getIndex(ord1459, false);
      std::vector<u16> ord1461({0, 1});
      slog::Relation* readrel1462 = db->getRelation("ref");
      refindex1415 = readrel1462->getIndex(ord1461, false);
      std::vector<u16> ord1463({0, 1, 2});
      slog::Relation* readrel1464 = db->getRelation("lambda");
      lambdaindex1416 = readrel1464->getIndex(ord1463, false);
      std::vector<u16> ord1465({1, 0});
      slog::Relation* readrel1466 = db->getRelation("ref");
      refindex1417 = readrel1466->getIndex(ord1465, false);
      std::vector<u16> ord1467({1, 2, 0});
      slog::Relation* readrel1468 = db->getRelation("app");
      appindex1418 = readrel1468->getIndex(ord1467, false);
      std::vector<u16> ord1469({1, 0});
      slog::Relation* readrel1470 = db->getRelation("ref");
      refindex1419 = readrel1470->getIndex(ord1469, false);
      std::vector<u16> ord1471({1, 2, 0});
      slog::Relation* readrel1472 = db->getRelation("app");
      appindex1420 = readrel1472->getIndex(ord1471, false);
      std::vector<u16> ord1473({1, 0});
      slog::Relation* readrel1474 = db->getRelation("ref");
      refindex1421 = readrel1474->getIndex(ord1473, false);
      std::vector<u16> ord1475({1, 2, 0});
      slog::Relation* readrel1476 = db->getRelation("lambda");
      lambdaindex1422 = readrel1476->getIndex(ord1475, false);
      std::vector<u16> ord1477({1, 2, 0});
      slog::Relation* readrel1478 = db->getRelation("app");
      appindex1423 = readrel1478->getIndex(ord1477, false);
      std::vector<u16> ord1479({2, 0, 1});
      slog::Relation* readrel1480 = db->getRelation("app");
      appindex1424 = readrel1480->getIndex(ord1479, false);
      std::vector<u16> ord1481({1, 0});
      slog::Relation* readrel1482 = db->getRelation("ref");
      refindex1425 = readrel1482->getIndex(ord1481, false);
      std::vector<u16> ord1483({1, 2, 0});
      slog::Relation* readrel1484 = db->getRelation("lambda");
      lambdaindex1426 = readrel1484->getIndex(ord1483, false);
      std::vector<u16> ord1485({1, 2, 0});
      slog::Relation* readrel1486 = db->getRelation("app");
      appindex1427 = readrel1486->getIndex(ord1485, false);
      std::vector<u16> ord1487({1, 2, 0});
      slog::Relation* readrel1488 = db->getRelation("lambda");
      lambdaindex1428 = readrel1488->getIndex(ord1487, false);
      std::vector<u16> ord1489({1, 2, 0});
      slog::Relation* readrel1490 = db->getRelation("app");
      appindex1429 = readrel1490->getIndex(ord1489, false);
      std::vector<u16> ord1491({1, 2, 0});
      slog::Relation* readrel1492 = db->getRelation("lambda");
      lambdaindex1430 = readrel1492->getIndex(ord1491, false);
      std::vector<u16> ord1493({0, 1, 2});
      slog::Relation* readrel1494 = db->getRelation("app");
      appindex1431 = readrel1494->getIndex(ord1493, false);
      std::vector<u16> ord1495({0, 1, 2});
      slog::Relation* readrel1496 = db->getRelation("lambda");
      lambdaindex1432 = readrel1496->getIndex(ord1495, false);
      std::vector<u16> ord1497({0, 1, 2});
      slog::Relation* readrel1498 = db->getRelation("app");
      appindex1433 = readrel1498->getIndex(ord1497, false);
  
    }
    ReadTask1434(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c44 = v_constb49bea2fcccd8f4301a347ed;
      u64 v_c50 = v_const8ca682693a0738a0641c6956;
      u64 v_c45 = v_const66518c0c1b3a5a0b09ae2ef1;
      u64 v_c47 = v_constc85eae03730a4f4cf1d66a0c;
      u64 v_c46 = v_const4a8acfc71441e0695ffcf5b3;
      u64 v_c49 = v_const576506f61f53440f1edd95d2;
      u64 v_c48 = v_const229c0b7aa8a7eb4055f5a3d0;
  
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
        u64 v_c53 = _t[2];
        if (!slog::exists_probe<2,1>(refindex1403, std::array<u64,2>{v_c50, 0})) return;
        if (!slog::exists_probe<3,2>(lambdaindex1404, std::array<u64,3>{v_c168, v_c44, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1405, std::array<u64,2>{v_c44, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1406, std::array<u64,2>{v_c45, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1407, std::array<u64,2>{v_c49, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1408, std::array<u64,3>{v_c49, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex1409, std::array<u64,2>{v_c48, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1410, std::array<u64,3>{v_c48, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1411, std::array<u64,3>{v_c46, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1412, std::array<u64,3>{v_c45, 0, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex1413, std::array<u64,3>{v_c47, 0, 0})) return;
        slog::join_probe<3,2>(lambdaindex1414, std::array<u64,3>{v_c53, v_c50, 0}, [&](const std::array<u64,3>& m1499) {
          u64 v_c52 = m1499[2];
          slog::join_probe<2,2>(refindex1415, std::array<u64,2>{v_c52, v_c50}, [&](const std::array<u64,2>& m1500) {
            slog::join_probe<3,2>(lambdaindex1416, std::array<u64,3>{v_c168, v_c44, 0}, [&](const std::array<u64,3>& m1501) {
              u64 v_c110 = m1501[2];
              slog::join_probe<2,1>(refindex1417, std::array<u64,2>{v_c44, 0}, [&](const std::array<u64,2>& m1502) {
                u64 v_c54 = m1502[1];
                if (!slog::exists_probe<3,1>(appindex1418, std::array<u64,3>{v_c54, 0, 0})) return;
                slog::join_probe<2,1>(refindex1419, std::array<u64,2>{v_c45, 0}, [&](const std::array<u64,2>& m1503) {
                  u64 v_c51 = m1503[1];
                  if (!slog::exists_probe<3,1>(appindex1420, std::array<u64,3>{v_c51, 0, 0})) return;
                  slog::join_probe<2,1>(refindex1421, std::array<u64,2>{v_c49, 0}, [&](const std::array<u64,2>& m1504) {
                    u64 v_c55 = m1504[1];
                    slog::join_probe<3,2>(lambdaindex1422, std::array<u64,3>{v_c49, v_c55, 0}, [&](const std::array<u64,3>& m1505) {
                      u64 v_c56 = m1505[2];
                      slog::join_probe<3,2>(appindex1423, std::array<u64,3>{v_c51, v_c56, 0}, [&](const std::array<u64,3>& m1506) {
                        u64 v_c57 = m1506[2];
                        if (!slog::exists_probe<3,1>(appindex1424, std::array<u64,3>{v_c57, 0, 0})) return;
                        slog::join_probe<2,1>(refindex1425, std::array<u64,2>{v_c48, 0}, [&](const std::array<u64,2>& m1507) {
                          u64 v_c58 = m1507[1];
                          slog::join_probe<3,2>(lambdaindex1426, std::array<u64,3>{v_c48, v_c58, 0}, [&](const std::array<u64,3>& m1508) {
                            u64 v_c59 = m1508[2];
                            slog::join_probe<3,2>(appindex1427, std::array<u64,3>{v_c51, v_c59, 0}, [&](const std::array<u64,3>& m1509) {
                              u64 v_c60 = m1509[2];
                              slog::join_probe<3,2>(lambdaindex1428, std::array<u64,3>{v_c46, v_c60, 0}, [&](const std::array<u64,3>& m1510) {
                                u64 v_c114 = m1510[2];
                                slog::join_probe<3,2>(appindex1429, std::array<u64,3>{v_c114, v_c57, 0}, [&](const std::array<u64,3>& m1511) {
                                  u64 v_c112 = m1511[2];
                                  slog::join_probe<3,2>(lambdaindex1430, std::array<u64,3>{v_c45, v_c112, 0}, [&](const std::array<u64,3>& m1512) {
                                    u64 v_c111 = m1512[2];
                                    slog::join_probe<3,2>(appindex1431, std::array<u64,3>{v_c110, v_c111, 0}, [&](const std::array<u64,3>& m1513) {
                                      u64 v_c63 = m1513[2];
                                      slog::join_probe<3,2>(lambdaindex1432, std::array<u64,3>{v_c63, v_c47, 0}, [&](const std::array<u64,3>& m1514) {
                                        u64 v_c62 = m1514[2];
                                        slog::join_probe<3,2>(appindex1433, std::array<u64,3>{v_c62, v_c54, 0}, [&](const std::array<u64,3>& m1515) {
                                          u64 v_c169 = m1515[2];
                                          if (v_c54 != v_c169) return;
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
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("mcfa-counting.slog:194", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask1434* _cont = new ReadTask1434(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1434(db,b), false);
}

