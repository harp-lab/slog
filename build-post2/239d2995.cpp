
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_constd4735e3a265e16eee03f5971;
u64 v_const3cd26ab9ce3085a816a74a29;
u64 v_const624b60c58c9d8bfb6ff1886c;
u64 v_const5feceb66ffc86f38d952786c;
u64 v_const1064263932db82f2cf6d4ac2;
u64 v_const6b86b273ff34fce19d6b804e;
u64 v_const72bac24066bb34077c1f6e71;
u64 v_const4e07408562bedb8b60ce05c1;
u64 v_const8c1f1046219ddd216a023f79;
u64 v_const1ca60a80dbae6414bef23d65;
u64 v_const1b2483991f3f37e4463261cd;
u64 v_consta22c7bfa7abc2d7d387fd7df;
u64 v_consteca796f75a14387c3a7674e7;
u64 v_constbb851acf11177e0e526ed8e5;
u64 v_constef2d127de37b942baad06145;
u64 v_const20347926ddb307a8e2bdb71b;
u64 v_const3a655602588fe6d8c59d4a5a;
u64 v_constff5a1ae012afa5d4c889c50a;
u64 v_constd01925b37634a1a9d24159d8;
u64 v_constdd7bbf31ce5f578b9805e840;
u64 v_const7902699be42c8a8e46fbbb45;
u64 v_consta24220c5193376967f1fa95e;
u64 v_const6c3d8aa344844f80a370de02;
u64 v_const11445e6556bc59ce1e80cdf7;
u64 v_const5f7e60cb3d02e4170101c2bc;
u64 v_constd9f3167b950244706dc6dbb2;
u64 v_const1ef5dd96b7ac876a994a9ca1;
u64 v_const7f254967624b26d820569bd6;
u64 v_const4a44dc15364204a80fe80e90;
u64 v_constc99bf3037b4c2fce0fbaab85;
u64 v_constc742e02805b99df617265a41;
u64 v_const9cfb09b7c00913be7566a50e;
u64 v_const721c36ff691f951d83718d83;
u64 v_consta0e8b3efb8cecb7adf11ee61;
u64 v_const5fedc35d1451fa93f8022abf;
u64 v_const07d7fbed0aba019c07f7eb8a;
u64 v_const3b5b774db59f55c2fdaef73a;
u64 v_constfee494ff4827aeb0635bb714;
u64 v_consta2d3b5b64cd0c50598de1133;
u64 v_const76237108756d80d8c9f21f56;
u64 v_const846f120b6b6ab883fe02a53a;

void slog_rules_cc6157e7c6a73b0a1(slog::Database* db, slog::Stratum* s);
void slog_rules_c7adbd30ff68a90cb(slog::Database* db, slog::Stratum* s);
void slog_rules_cae5e53883d639a44(slog::Database* db, slog::Stratum* s);
void slog_rules_cb43d5e633d046d7f(slog::Database* db, slog::Stratum* s);
void slog_rules_c5e507d0827aa73d6(slog::Database* db, slog::Stratum* s);
void slog_rules_cf1315b147c9a2b4b(slog::Database* db, slog::Stratum* s);
void slog_rules_c53642b523c6cca89(slog::Database* db, slog::Stratum* s);
void slog_rules_ca0ddd135f242cff4(slog::Database* db, slog::Stratum* s);
void slog_rules_cb145c2cedadd9aea(slog::Database* db, slog::Stratum* s);
void slog_rules_c135f00f5c4b371c2(slog::Database* db, slog::Stratum* s);
void slog_rules_c6ea2ad2d2425c003(slog::Database* db, slog::Stratum* s);
void slog_rules_c738f16f39e0507e0(slog::Database* db, slog::Stratum* s);
void slog_rules_c04f93a1558b3b6fd(slog::Database* db, slog::Stratum* s);
void slog_rules_ce117930327306c0d(slog::Database* db, slog::Stratum* s);
void slog_rules_cfd10cb788fe91aa2(slog::Database* db, slog::Stratum* s);
void slog_rules_c692e503ff718572d(slog::Database* db, slog::Stratum* s);


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("239d2995");
  if (s == nullptr) return;
  slog::Relation* r;
  v_constd4735e3a265e16eee03f5971 = s32_encode(2);
  v_const3cd26ab9ce3085a816a74a29 = db->encodeString("mp_del");
  v_const624b60c58c9d8bfb6ff1886c = s32_encode(30);
  v_const5feceb66ffc86f38d952786c = s32_encode(0);
  v_const1064263932db82f2cf6d4ac2 = db->encodeString("mp_put");
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  v_const72bac24066bb34077c1f6e71 = db->encodeString("mbranch");
  v_const4e07408562bedb8b60ce05c1 = s32_encode(3);
  v_const8c1f1046219ddd216a023f79 = s32_encode(99);
  v_const1ca60a80dbae6414bef23d65 = db->encodeString("map.slog:45");
  v_const1b2483991f3f37e4463261cd = db->encodeString("map.slog:41");
  v_consta22c7bfa7abc2d7d387fd7df = db->encodeString("map.slog:43");
  v_consteca796f75a14387c3a7674e7 = db->encodeString("map.slog:30");
  v_constbb851acf11177e0e526ed8e5 = db->encodeString("map.slog:26");
  v_constef2d127de37b942baad06145 = s32_encode(5);
  v_const20347926ddb307a8e2bdb71b = db->encodeString("mp_bld");
  v_const3a655602588fe6d8c59d4a5a = db->encodeString("mp_has0");
  v_constff5a1ae012afa5d4c889c50a = s32_encode(70);
  v_constd01925b37634a1a9d24159d8 = db->encodeString("mempty");
  v_constdd7bbf31ce5f578b9805e840 = db->encodeString("mp_msk");
  v_const7902699be42c8a8e46fbbb45 = s32_encode(7);
  v_consta24220c5193376967f1fa95e = db->encodeString("mp_join");
  v_const6c3d8aa344844f80a370de02 = db->encodeString("map.slog:102");
  v_const11445e6556bc59ce1e80cdf7 = db->encodeString("map.slog:111");
  v_const5f7e60cb3d02e4170101c2bc = db->encodeString("map.slog:105");
  v_constd9f3167b950244706dc6dbb2 = db->encodeString("map.slog:108");
  v_const1ef5dd96b7ac876a994a9ca1 = db->encodeString("map.slog:128");
  v_const7f254967624b26d820569bd6 = db->encodeString("mp_union");
  v_const4a44dc15364204a80fe80e90 = s32_encode(10);
  v_constc99bf3037b4c2fce0fbaab85 = db->encodeString("map.slog:99");
  v_constc742e02805b99df617265a41 = db->encodeString("map.slog:96");
  v_const9cfb09b7c00913be7566a50e = db->encodeString("map.slog:94");
  v_const721c36ff691f951d83718d83 = db->encodeString("map.slog:82");
  v_consta0e8b3efb8cecb7adf11ee61 = db->encodeString("map.slog:60");
  v_const5fedc35d1451fa93f8022abf = db->encodeString("map.slog:68");
  v_const07d7fbed0aba019c07f7eb8a = db->encodeString("map.slog:83");
  v_const3b5b774db59f55c2fdaef73a = db->encodeString("map.slog:63");
  v_constfee494ff4827aeb0635bb714 = db->encodeString("map.slog:85");
  v_consta2d3b5b64cd0c50598de1133 = db->encodeString("map.slog:61");
  v_const76237108756d80d8c9f21f56 = db->encodeString("mleaf");
  v_const846f120b6b6ab883fe02a53a = db->encodeString("map.slog:69");
  r = db->getRelation("upd");
  if (r == 0) db->addRelation("upd", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("upd");
      std::vector<u16> ord0({0});
    
    r->addIndex<1>(ord0, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("upd"), std::array<u16,1>{0}, b));
  r = db->getRelation("uni");
  if (r == 0) db->addRelation("uni", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("uni");
      std::vector<u16> ord1({0});
    
    r->addIndex<1>(ord1, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("uni"), std::array<u16,1>{0}, b));
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord2({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord2, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord3({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord3, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord4({1, 2, 0});
    
    r->addIndex<3>(ord4, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord5({0, 1, 2});
    
    r->addIndex<3>(ord5, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("temp9B581035");
  if (r == 0) db->addTempRelation("temp9B581035", 5);
  else if (r->getArity() != 5) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp8y4n1085");
  if (r == 0) db->addTempRelation("temp8y4n1085", 4);
  else if (r->getArity() != 4) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp8fvz1067");
  if (r == 0) db->addTempRelation("temp8fvz1067", 3);
  else if (r->getArity() != 3) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp8GS31028");
  if (r == 0) db->addTempRelation("temp8GS31028", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp7KpW1055");
  if (r == 0) db->addTempRelation("temp7KpW1055", 5);
  else if (r->getArity() != 5) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp7FV11078");
  if (r == 0) db->addTempRelation("temp7FV11078", 5);
  else if (r->getArity() != 5) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp6y6l1036");
  if (r == 0) db->addTempRelation("temp6y6l1036", 5);
  else if (r->getArity() != 5) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp6KDK1090");
  if (r == 0) db->addTempRelation("temp6KDK1090", 5);
  else if (r->getArity() != 5) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp61Si1083");
  if (r == 0) db->addTempRelation("temp61Si1083", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp5z0Y1074");
  if (r == 0) db->addTempRelation("temp5z0Y1074", 5);
  else if (r->getArity() != 5) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp5uMp1022");
  if (r == 0) db->addTempRelation("temp5uMp1022", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp5jzw1068");
  if (r == 0) db->addTempRelation("temp5jzw1068", 5);
  else if (r->getArity() != 5) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp5R2q1072");
  if (r == 0) db->addTempRelation("temp5R2q1072", 4);
  else if (r->getArity() != 4) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp5A4p1059");
  if (r == 0) db->addTempRelation("temp5A4p1059", 5);
  else if (r->getArity() != 5) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp4kFO1073");
  if (r == 0) db->addTempRelation("temp4kFO1073", 5);
  else if (r->getArity() != 5) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp4cOw1069");
  if (r == 0) db->addTempRelation("temp4cOw1069", 3);
  else if (r->getArity() != 3) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp4Eqs1025");
  if (r == 0) db->addTempRelation("temp4Eqs1025", 3);
  else if (r->getArity() != 3) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp2ytq1023");
  if (r == 0) db->addTempRelation("temp2ytq1023", 5);
  else if (r->getArity() != 5) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp2xeX1033");
  if (r == 0) db->addTempRelation("temp2xeX1033", 5);
  else if (r->getArity() != 5) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp2oEt1084");
  if (r == 0) db->addTempRelation("temp2oEt1084", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp2mZ61026");
  if (r == 0) db->addTempRelation("temp2mZ61026", 3);
  else if (r->getArity() != 3) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp2PlQ1027");
  if (r == 0) db->addTempRelation("temp2PlQ1027", 2);
  else if (r->getArity() != 2) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp2Hkq1086");
  if (r == 0) db->addTempRelation("temp2Hkq1086", 2);
  else if (r->getArity() != 2) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp1bhg1089");
  if (r == 0) db->addTempRelation("temp1bhg1089", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp1Yd51020");
  if (r == 0) db->addTempRelation("temp1Yd51020", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp1XD61034");
  if (r == 0) db->addTempRelation("temp1XD61034", 5);
  else if (r->getArity() != 5) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp1Gnx1042");
  if (r == 0) db->addTempRelation("temp1Gnx1042", 5);
  else if (r->getArity() != 5) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp0EGL1024");
  if (r == 0) db->addTempRelation("temp0EGL1024", 5);
  else if (r->getArity() != 5) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp03QX1021");
  if (r == 0) db->addTempRelation("temp03QX1021", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord6({1, 2, 0});
    
    r->addIndex<3>(ord6, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord7({0, 1, 2});
    
    r->addIndex<3>(ord7, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord8({1, 2, 3, 0});
    
    r->addIndex<4>(ord8, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord9({0, 1, 2, 3});
    
    r->addIndex<4>(ord9, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord10({1, 2, 0});
    
    r->addIndex<3>(ord10, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord11({0, 1, 2});
    
    r->addIndex<3>(ord11, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord12({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord12, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord13({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord13, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("mp_union_ans");
  if (r == 0) db->addRelation("mp_union_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_union_ans");
      std::vector<u16> ord14({0, 1});
    
    r->addIndex<2>(ord14, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
      std::vector<u16> ord15({0, 1});
    
    r->addIndex<2>(ord15, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_union_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_union");
  if (r == 0) db->addStruct("mp_union", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_union");
      std::vector<u16> ord16({1, 2, 0});
    
    r->addIndex<3>(ord16, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord17({0, 1, 2});
    
    r->addIndex<3>(ord17, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
      std::vector<u16> ord18({2, 0, 1});
    
    r->addIndex<3>(ord18, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, false, b), false);
      std::vector<u16> ord19({0, 1, 2});
    
    r->addIndex<3>(ord19, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, true, b), false);
      std::vector<u16> ord20({1, 2, 0});
    
    r->addIndex<3>(ord20, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, true, b), false);
      std::vector<u16> ord21({2, 0, 1});
    
    r->addIndex<3>(ord21, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mp_union"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mp_size_ans");
  if (r == 0) db->addRelation("mp_size_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_size_ans");
      std::vector<u16> ord22({0, 1});
    
    r->addIndex<2>(ord22, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_size_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_size");
  if (r == 0) db->addStruct("mp_size", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_size");
      std::vector<u16> ord23({1, 0});
    
    r->addIndex<2>(ord23, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord24({0, 1});
    
    r->addIndex<2>(ord24, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("mp_size"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("mp_put_soft_ans");
  if (r == 0) db->addRelation("mp_put_soft_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_put_soft_ans");
      std::vector<u16> ord25({0, 1});
    
    r->addIndex<2>(ord25, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_put_soft_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_put_soft");
  if (r == 0) db->addStruct("mp_put_soft", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_put_soft");
      std::vector<u16> ord26({1, 2, 3, 0});
    
    r->addIndex<4>(ord26, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord27({0, 1, 2, 3});
    
    r->addIndex<4>(ord27, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
      std::vector<u16> ord28({2, 3, 0, 1});
    
    r->addIndex<4>(ord28, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{2, 3, 0, 1}, false, b), false);
      std::vector<u16> ord29({0, 1, 2, 3});
    
    r->addIndex<4>(ord29, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, true, b), false);
      std::vector<u16> ord30({1, 2, 3, 0});
    
    r->addIndex<4>(ord30, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, true, b), false);
      std::vector<u16> ord31({2, 3, 0, 1});
    
    r->addIndex<4>(ord31, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{2, 3, 0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("mp_put_soft"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mp_put_ans");
  if (r == 0) db->addRelation("mp_put_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_put_ans");
      std::vector<u16> ord32({0, 1});
    
    r->addIndex<2>(ord32, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
      std::vector<u16> ord33({1, 0});
    
    r->addIndex<2>(ord33, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), false);
      std::vector<u16> ord34({0, 1});
    
    r->addIndex<2>(ord34, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_put_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_put");
  if (r == 0) db->addStruct("mp_put", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_put");
      std::vector<u16> ord35({1, 2, 3, 0});
    
    r->addIndex<4>(ord35, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord36({0, 1, 2, 3});
    
    r->addIndex<4>(ord36, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
      std::vector<u16> ord37({1, 2, 0, 3});
    
    r->addIndex<4>(ord37, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 0, 3}, false, b), false);
      std::vector<u16> ord38({2, 3, 0, 1});
    
    r->addIndex<4>(ord38, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{2, 3, 0, 1}, false, b), false);
      std::vector<u16> ord39({0, 1, 2, 3});
    
    r->addIndex<4>(ord39, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, true, b), false);
      std::vector<u16> ord40({1, 2, 0, 3});
    
    r->addIndex<4>(ord40, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 0, 3}, true, b), false);
      std::vector<u16> ord41({1, 2, 3, 0});
    
    r->addIndex<4>(ord41, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, true, b), false);
      std::vector<u16> ord42({2, 3, 0, 1});
    
    r->addIndex<4>(ord42, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{2, 3, 0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("mp_put"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mp_msk_ans");
  if (r == 0) db->addRelation("mp_msk_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_msk_ans");
      std::vector<u16> ord43({0, 1});
    
    r->addIndex<2>(ord43, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
      std::vector<u16> ord44({1, 0});
    
    r->addIndex<2>(ord44, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), false);
      std::vector<u16> ord45({0, 1});
    
    r->addIndex<2>(ord45, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_msk_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_msk");
  if (r == 0) db->addStruct("mp_msk", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_msk");
      std::vector<u16> ord46({1, 2, 0});
    
    r->addIndex<3>(ord46, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord47({0, 1, 2});
    
    r->addIndex<3>(ord47, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
      std::vector<u16> ord48({2, 0, 1});
    
    r->addIndex<3>(ord48, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, false, b), false);
      std::vector<u16> ord49({0, 1, 2});
    
    r->addIndex<3>(ord49, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, true, b), false);
      std::vector<u16> ord50({1, 2, 0});
    
    r->addIndex<3>(ord50, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mp_msk"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mp_join_ans");
  if (r == 0) db->addRelation("mp_join_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_join_ans");
      std::vector<u16> ord51({0, 1});
    
    r->addIndex<2>(ord51, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_join_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_join");
  if (r == 0) db->addStruct("mp_join", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_join");
      std::vector<u16> ord52({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord52, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord53({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord53, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
      std::vector<u16> ord54({1, 4, 2, 0, 3});
    
    r->addIndex<5>(ord54, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 4, 2, 0, 3}, false, b), false);
      std::vector<u16> ord55({2, 4, 0, 1, 3});
    
    r->addIndex<5>(ord55, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{2, 4, 0, 1, 3}, false, b), false);
      std::vector<u16> ord56({3, 4, 1, 0, 2});
    
    r->addIndex<5>(ord56, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{3, 4, 1, 0, 2}, false, b), false);
      std::vector<u16> ord57({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord57, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, true, b), false);
      std::vector<u16> ord58({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord58, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, true, b), false);
      std::vector<u16> ord59({1, 4, 2, 0, 3});
    
    r->addIndex<5>(ord59, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 4, 2, 0, 3}, true, b), false);
      std::vector<u16> ord60({2, 4, 0, 1, 3});
    
    r->addIndex<5>(ord60, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{2, 4, 0, 1, 3}, true, b), false);
      std::vector<u16> ord61({3, 4, 1, 0, 2});
    
    r->addIndex<5>(ord61, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{3, 4, 1, 0, 2}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mp_join"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("mp_hsb_ans");
  if (r == 0) db->addRelation("mp_hsb_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_hsb_ans");
      std::vector<u16> ord62({0, 1});
    
    r->addIndex<2>(ord62, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
      std::vector<u16> ord63({1, 0});
    
    r->addIndex<2>(ord63, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), false);
      std::vector<u16> ord64({0, 1});
    
    r->addIndex<2>(ord64, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, true, b), false);
      std::vector<u16> ord65({1, 0});
    
    r->addIndex<2>(ord65, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_hsb_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_hsb");
  if (r == 0) db->addStruct("mp_hsb", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_hsb");
      std::vector<u16> ord66({1, 0});
    
    r->addIndex<2>(ord66, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord67({0, 1});
    
    r->addIndex<2>(ord67, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord68({0, 1});
    
    r->addIndex<2>(ord68, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, true, b), false);
      std::vector<u16> ord69({1, 0});
    
    r->addIndex<2>(ord69, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("mp_hsb"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("mp_has0_ans");
  if (r == 0) db->addRelation("mp_has0_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_has0_ans");
      std::vector<u16> ord70({0, 1});
    
    r->addIndex<2>(ord70, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
      std::vector<u16> ord71({1, 0});
    
    r->addIndex<2>(ord71, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), false);
      std::vector<u16> ord72({1, 0});
    
    r->addIndex<2>(ord72, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_has0_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_has0");
  if (r == 0) db->addStruct("mp_has0", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_has0");
      std::vector<u16> ord73({1, 2, 0});
    
    r->addIndex<3>(ord73, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord74({0, 2, 1});
    
    r->addIndex<3>(ord74, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 2, 1}, false, b), false);
      std::vector<u16> ord75({2, 0, 1});
    
    r->addIndex<3>(ord75, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, false, b), false);
      std::vector<u16> ord76({0, 2, 1});
    
    r->addIndex<3>(ord76, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 2, 1}, true, b), false);
      std::vector<u16> ord77({1, 2, 0});
    
    r->addIndex<3>(ord77, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mp_has0"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mp_get_ans");
  if (r == 0) db->addRelation("mp_get_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_get_ans");
      std::vector<u16> ord78({0, 1});
    
    r->addIndex<2>(ord78, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_get_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_get");
  if (r == 0) db->addStruct("mp_get", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_get");
      std::vector<u16> ord79({1, 2, 0});
    
    r->addIndex<3>(ord79, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord80({0, 1, 2});
    
    r->addIndex<3>(ord80, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mp_get"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mp_fromlist_ans");
  if (r == 0) db->addRelation("mp_fromlist_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_fromlist_ans");
      std::vector<u16> ord81({1, 0});
    
    r->addIndex<2>(ord81, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_fromlist_ans"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("mp_fromlist");
  if (r == 0) db->addStruct("mp_fromlist", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_fromlist");
      std::vector<u16> ord82({1, 0});
    
    r->addIndex<2>(ord82, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord83({0, 1});
    
    r->addIndex<2>(ord83, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("mp_fromlist"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("mp_del_ans");
  if (r == 0) db->addRelation("mp_del_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_del_ans");
      std::vector<u16> ord84({0, 1});
    
    r->addIndex<2>(ord84, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
      std::vector<u16> ord85({1, 0});
    
    r->addIndex<2>(ord85, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), false);
      std::vector<u16> ord86({0, 1});
    
    r->addIndex<2>(ord86, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_del_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_del");
  if (r == 0) db->addStruct("mp_del", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_del");
      std::vector<u16> ord87({1, 2, 0});
    
    r->addIndex<3>(ord87, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord88({0, 2, 1});
    
    r->addIndex<3>(ord88, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 2, 1}, false, b), false);
      std::vector<u16> ord89({2, 0, 1});
    
    r->addIndex<3>(ord89, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, false, b), false);
      std::vector<u16> ord90({0, 2, 1});
    
    r->addIndex<3>(ord90, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 2, 1}, true, b), false);
      std::vector<u16> ord91({1, 2, 0});
    
    r->addIndex<3>(ord91, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mp_del"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mp_bld_ans");
  if (r == 0) db->addRelation("mp_bld_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_bld_ans");
      std::vector<u16> ord92({0, 1});
    
    r->addIndex<2>(ord92, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mp_bld_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mp_bld");
  if (r == 0) db->addStruct("mp_bld", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mp_bld");
      std::vector<u16> ord93({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord93, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord94({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord94, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
      std::vector<u16> ord95({2, 1, 4, 0, 3});
    
    r->addIndex<5>(ord95, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{2, 1, 4, 0, 3}, false, b), false);
      std::vector<u16> ord96({3, 0, 1, 2, 4});
    
    r->addIndex<5>(ord96, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{3, 0, 1, 2, 4}, false, b), false);
      std::vector<u16> ord97({4, 0, 1, 2, 3});
    
    r->addIndex<5>(ord97, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{4, 0, 1, 2, 3}, false, b), false);
      std::vector<u16> ord98({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord98, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, true, b), false);
      std::vector<u16> ord99({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord99, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, true, b), false);
      std::vector<u16> ord100({2, 1, 4, 0, 3});
    
    r->addIndex<5>(ord100, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{2, 1, 4, 0, 3}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mp_bld"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord101({1, 2, 0});
    
    r->addIndex<3>(ord101, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord102({0, 1, 2});
    
    r->addIndex<3>(ord102, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mleaf");
  if (r == 0) db->addStruct("mleaf", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mleaf");
      std::vector<u16> ord103({1, 2, 0});
    
    r->addIndex<3>(ord103, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord104({0, 1, 2});
    
    r->addIndex<3>(ord104, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
      std::vector<u16> ord105({0, 1, 2});
    
    r->addIndex<3>(ord105, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, true, b), false);
      std::vector<u16> ord106({1, 2, 0});
    
    r->addIndex<3>(ord106, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mleaf"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mbranch");
  if (r == 0) db->addStruct("mbranch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mbranch");
      std::vector<u16> ord107({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord107, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord108({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord108, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
      std::vector<u16> ord109({1, 2, 4, 0, 3});
    
    r->addIndex<5>(ord109, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 4, 0, 3}, false, b), false);
      std::vector<u16> ord110({2, 0, 1, 3, 4});
    
    r->addIndex<5>(ord110, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{2, 0, 1, 3, 4}, false, b), false);
      std::vector<u16> ord111({3, 0, 1, 2, 4});
    
    r->addIndex<5>(ord111, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{3, 0, 1, 2, 4}, false, b), false);
      std::vector<u16> ord112({4, 0, 1, 2, 3});
    
    r->addIndex<5>(ord112, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{4, 0, 1, 2, 3}, false, b), false);
      std::vector<u16> ord113({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord113, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, true, b), false);
      std::vector<u16> ord114({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord114, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, true, b), false);
      std::vector<u16> ord115({1, 2, 4, 0, 3});
    
    r->addIndex<5>(ord115, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 4, 0, 3}, true, b), false);
      std::vector<u16> ord116({2, 0, 1, 3, 4});
    
    r->addIndex<5>(ord116, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{2, 0, 1, 3, 4}, true, b), false);
      std::vector<u16> ord117({3, 0, 1, 2, 4});
    
    r->addIndex<5>(ord117, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{3, 0, 1, 2, 4}, true, b), false);
      std::vector<u16> ord118({4, 0, 1, 2, 3});
    
    r->addIndex<5>(ord118, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{4, 0, 1, 2, 3}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mbranch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord119({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord119, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord120({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord120, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord121({1, 2, 3, 0});
    
    r->addIndex<4>(ord121, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord122({0, 1, 2, 3});
    
    r->addIndex<4>(ord122, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("has");
  if (r == 0) db->addRelation("has", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("has");
      std::vector<u16> ord123({0, 1});
    
    r->addIndex<2>(ord123, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("has"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("got");
  if (r == 0) db->addRelation("got", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("got");
      std::vector<u16> ord124({0, 1});
    
    r->addIndex<2>(ord124, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("got"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord125({0});
    
    r->addIndex<1>(ord125, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord126({1, 2, 0});
    
    r->addIndex<3>(ord126, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord127({0, 1, 2});
    
    r->addIndex<3>(ord127, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("canon");
  if (r == 0) db->addRelation("canon", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("canon");
      std::vector<u16> ord128({0});
    
    r->addIndex<1>(ord128, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("canon"), std::array<u16,1>{0}, b));
  r = db->getRelation("afterdel");
  if (r == 0) db->addRelation("afterdel", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("afterdel");
      std::vector<u16> ord129({0});
    
    r->addIndex<1>(ord129, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("afterdel"), std::array<u16,1>{0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord130({1, 0});
    
    r->addIndex<2>(ord130, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord131({0, 1});
    
    r->addIndex<2>(ord131, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord132({1, 0});
    
    r->addIndex<2>(ord132, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("$sup5638x98x0x0x1");
  if (r == 0) db->addRelation("$sup5638x98x0x0x1", 10);
  else if (r->getArity() != 10)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x98x0x0x1");
      std::vector<u16> ord133({0, 7, 1, 2, 3, 4, 5, 6, 8, 9});
    
    r->addIndex<10>(ord133, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{0, 7, 1, 2, 3, 4, 5, 6, 8, 9}, false, b), true);
      std::vector<u16> ord134({1, 3, 6, 5, 0, 2, 4, 7, 8, 9});
    
    r->addIndex<10>(ord134, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{1, 3, 6, 5, 0, 2, 4, 7, 8, 9}, false, b), false);
      std::vector<u16> ord135({1, 5, 0, 2, 3, 4, 6, 7, 8, 9});
    
    r->addIndex<10>(ord135, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{1, 5, 0, 2, 3, 4, 6, 7, 8, 9}, false, b), false);
      std::vector<u16> ord136({4, 6, 8, 9, 0, 1, 2, 3, 5, 7});
    
    r->addIndex<10>(ord136, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{4, 6, 8, 9, 0, 1, 2, 3, 5, 7}, false, b), false);
      std::vector<u16> ord137({7, 2, 3, 5, 0, 4, 6, 8, 9, 1});
    
    r->addIndex<10>(ord137, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{7, 2, 3, 5, 0, 4, 6, 8, 9, 1}, false, b), false);
      std::vector<u16> ord138({1, 3, 6, 5, 0, 2, 4, 7, 8, 9});
    
    r->addIndex<10>(ord138, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{1, 3, 6, 5, 0, 2, 4, 7, 8, 9}, true, b), false);
      std::vector<u16> ord139({7, 2, 3, 5, 0, 4, 6, 8, 9, 1});
    
    r->addIndex<10>(ord139, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{7, 2, 3, 5, 0, 4, 6, 8, 9, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<10>(db, db->getRelation("$sup5638x98x0x0x1"), std::array<u16,10>{0, 7, 1, 2, 3, 4, 5, 6, 8, 9}, b));
  r = db->getRelation("$sup5638x98x0x0x0");
  if (r == 0) db->addRelation("$sup5638x98x0x0x0", 9);
  else if (r->getArity() != 9)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x98x0x0x0");
      std::vector<u16> ord140({0, 6, 1, 2, 3, 4, 5, 7, 8});
    
    r->addIndex<9>(ord140, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{0, 6, 1, 2, 3, 4, 5, 7, 8}, false, b), true);
      std::vector<u16> ord141({2, 5, 4, 0, 1, 3, 6, 7, 8});
    
    r->addIndex<9>(ord141, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{2, 5, 4, 0, 1, 3, 6, 7, 8}, false, b), false);
      std::vector<u16> ord142({3, 5, 7, 8, 0, 1, 2, 4, 6});
    
    r->addIndex<9>(ord142, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{3, 5, 7, 8, 0, 1, 2, 4, 6}, false, b), false);
      std::vector<u16> ord143({4, 1, 2, 6, 0, 3, 5, 7, 8});
    
    r->addIndex<9>(ord143, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{4, 1, 2, 6, 0, 3, 5, 7, 8}, false, b), false);
      std::vector<u16> ord144({6, 0, 1, 2, 3, 4, 5, 7, 8});
    
    r->addIndex<9>(ord144, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{6, 0, 1, 2, 3, 4, 5, 7, 8}, false, b), false);
      std::vector<u16> ord145({4, 1, 2, 6, 0, 3, 5, 7, 8});
    
    r->addIndex<9>(ord145, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{4, 1, 2, 6, 0, 3, 5, 7, 8}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<9>(db, db->getRelation("$sup5638x98x0x0x0"), std::array<u16,9>{0, 6, 1, 2, 3, 4, 5, 7, 8}, b));
  r = db->getRelation("$sup5638x95x0x0x1");
  if (r == 0) db->addRelation("$sup5638x95x0x0x1", 10);
  else if (r->getArity() != 10)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x95x0x0x1");
      std::vector<u16> ord146({0, 2, 1, 3, 4, 5, 6, 7, 8, 9});
    
    r->addIndex<10>(ord146, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{0, 2, 1, 3, 4, 5, 6, 7, 8, 9}, false, b), true);
      std::vector<u16> ord147({1, 3, 6, 5, 0, 2, 4, 7, 8, 9});
    
    r->addIndex<10>(ord147, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{1, 3, 6, 5, 0, 2, 4, 7, 8, 9}, false, b), false);
      std::vector<u16> ord148({1, 5, 0, 2, 3, 4, 6, 7, 8, 9});
    
    r->addIndex<10>(ord148, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{1, 5, 0, 2, 3, 4, 6, 7, 8, 9}, false, b), false);
      std::vector<u16> ord149({2, 3, 5, 7, 0, 4, 6, 8, 9, 1});
    
    r->addIndex<10>(ord149, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{2, 3, 5, 7, 0, 4, 6, 8, 9, 1}, false, b), false);
      std::vector<u16> ord150({4, 6, 8, 9, 0, 1, 2, 3, 5, 7});
    
    r->addIndex<10>(ord150, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{4, 6, 8, 9, 0, 1, 2, 3, 5, 7}, false, b), false);
      std::vector<u16> ord151({1, 3, 6, 5, 0, 2, 4, 7, 8, 9});
    
    r->addIndex<10>(ord151, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{1, 3, 6, 5, 0, 2, 4, 7, 8, 9}, true, b), false);
      std::vector<u16> ord152({2, 3, 5, 7, 0, 4, 6, 8, 9, 1});
    
    r->addIndex<10>(ord152, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{2, 3, 5, 7, 0, 4, 6, 8, 9, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<10>(db, db->getRelation("$sup5638x95x0x0x1"), std::array<u16,10>{0, 2, 1, 3, 4, 5, 6, 7, 8, 9}, b));
  r = db->getRelation("$sup5638x95x0x0x0");
  if (r == 0) db->addRelation("$sup5638x95x0x0x0", 9);
  else if (r->getArity() != 9)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x95x0x0x0");
      std::vector<u16> ord153({0, 1, 2, 3, 4, 5, 6, 7, 8});
    
    r->addIndex<9>(ord153, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, false, b), true);
      std::vector<u16> ord154({1, 2, 4, 6, 0, 3, 5, 7, 8});
    
    r->addIndex<9>(ord154, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{1, 2, 4, 6, 0, 3, 5, 7, 8}, false, b), false);
      std::vector<u16> ord155({2, 5, 4, 0, 1, 3, 6, 7, 8});
    
    r->addIndex<9>(ord155, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{2, 5, 4, 0, 1, 3, 6, 7, 8}, false, b), false);
      std::vector<u16> ord156({3, 5, 7, 8, 0, 1, 2, 4, 6});
    
    r->addIndex<9>(ord156, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{3, 5, 7, 8, 0, 1, 2, 4, 6}, false, b), false);
      std::vector<u16> ord157({4, 0, 1, 2, 3, 5, 6, 7, 8});
    
    r->addIndex<9>(ord157, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{4, 0, 1, 2, 3, 5, 6, 7, 8}, false, b), false);
      std::vector<u16> ord158({1, 2, 4, 6, 0, 3, 5, 7, 8});
    
    r->addIndex<9>(ord158, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{1, 2, 4, 6, 0, 3, 5, 7, 8}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<9>(db, db->getRelation("$sup5638x95x0x0x0"), std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, b));
  r = db->getRelation("$sup5638x93x0x0x0");
  if (r == 0) db->addRelation("$sup5638x93x0x0x0", 7);
  else if (r->getArity() != 7)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x93x0x0x0");
      std::vector<u16> ord159({0, 1, 2, 3, 4, 5, 6});
    
    r->addIndex<7>(ord159, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, false, b), true);
      std::vector<u16> ord160({1, 2, 3, 4, 0, 5, 6});
    
    r->addIndex<7>(ord160, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{1, 2, 3, 4, 0, 5, 6}, false, b), false);
      std::vector<u16> ord161({1, 5, 0, 2, 3, 4, 6});
    
    r->addIndex<7>(ord161, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{1, 5, 0, 2, 3, 4, 6}, false, b), false);
      std::vector<u16> ord162({2, 3, 5, 6, 0, 1, 4});
    
    r->addIndex<7>(ord162, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{2, 3, 5, 6, 0, 1, 4}, false, b), false);
      std::vector<u16> ord163({4, 6, 0, 1, 2, 3, 5});
    
    r->addIndex<7>(ord163, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{4, 6, 0, 1, 2, 3, 5}, false, b), false);
      std::vector<u16> ord164({1, 5, 0, 2, 3, 4, 6});
    
    r->addIndex<7>(ord164, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{1, 5, 0, 2, 3, 4, 6}, true, b), false);
      std::vector<u16> ord165({4, 6, 0, 1, 2, 3, 5});
    
    r->addIndex<7>(ord165, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{4, 6, 0, 1, 2, 3, 5}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<7>(db, db->getRelation("$sup5638x93x0x0x0"), std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, b));
  r = db->getRelation("$sup5638x84x0x0x0");
  if (r == 0) db->addRelation("$sup5638x84x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x84x0x0x0");
      std::vector<u16> ord166({4, 2, 3, 5, 0, 1});
    
    r->addIndex<6>(ord166, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{4, 2, 3, 5, 0, 1}, false, b), true);
      std::vector<u16> ord167({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord167, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), false);
      std::vector<u16> ord168({1, 3, 4, 0, 2, 5});
    
    r->addIndex<6>(ord168, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{1, 3, 4, 0, 2, 5}, false, b), false);
      std::vector<u16> ord169({1, 5, 0, 2, 3, 4});
    
    r->addIndex<6>(ord169, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{1, 5, 0, 2, 3, 4}, false, b), false);
      std::vector<u16> ord170({1, 3, 4, 0, 2, 5});
    
    r->addIndex<6>(ord170, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{1, 3, 4, 0, 2, 5}, true, b), false);
      std::vector<u16> ord171({1, 5, 0, 2, 3, 4});
    
    r->addIndex<6>(ord171, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{1, 5, 0, 2, 3, 4}, true, b), false);
      std::vector<u16> ord172({4, 2, 3, 5, 0, 1});
    
    r->addIndex<6>(ord172, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{4, 2, 3, 5, 0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup5638x84x0x0x0"), std::array<u16,6>{4, 2, 3, 5, 0, 1}, b));
  r = db->getRelation("$sup5638x82x0x0x0");
  if (r == 0) db->addRelation("$sup5638x82x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x82x0x0x0");
      std::vector<u16> ord173({4, 3, 5, 2, 0, 1});
    
    r->addIndex<6>(ord173, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{4, 3, 5, 2, 0, 1}, false, b), true);
      std::vector<u16> ord174({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord174, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), false);
      std::vector<u16> ord175({1, 2, 0, 3, 4, 5});
    
    r->addIndex<6>(ord175, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{1, 2, 0, 3, 4, 5}, false, b), false);
      std::vector<u16> ord176({1, 3, 4, 0, 2, 5});
    
    r->addIndex<6>(ord176, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{1, 3, 4, 0, 2, 5}, false, b), false);
      std::vector<u16> ord177({1, 2, 0, 3, 4, 5});
    
    r->addIndex<6>(ord177, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{1, 2, 0, 3, 4, 5}, true, b), false);
      std::vector<u16> ord178({1, 3, 4, 0, 2, 5});
    
    r->addIndex<6>(ord178, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{1, 3, 4, 0, 2, 5}, true, b), false);
      std::vector<u16> ord179({4, 3, 5, 2, 0, 1});
    
    r->addIndex<6>(ord179, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{4, 3, 5, 2, 0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup5638x82x0x0x0"), std::array<u16,6>{4, 3, 5, 2, 0, 1}, b));
  r = db->getRelation("$sup5638x81x0x0x0");
  if (r == 0) db->addRelation("$sup5638x81x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x81x0x0x0");
      std::vector<u16> ord180({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord180, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
      std::vector<u16> ord181({1, 3, 0, 2, 4, 5});
    
    r->addIndex<6>(ord181, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{1, 3, 0, 2, 4, 5}, false, b), false);
      std::vector<u16> ord182({2, 3, 4, 5, 0, 1});
    
    r->addIndex<6>(ord182, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{2, 3, 4, 5, 0, 1}, false, b), false);
      std::vector<u16> ord183({1, 3, 0, 2, 4, 5});
    
    r->addIndex<6>(ord183, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{1, 3, 0, 2, 4, 5}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup5638x81x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup5638x68x0x0x0");
  if (r == 0) db->addRelation("$sup5638x68x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x68x0x0x0");
      std::vector<u16> ord184({1, 2, 3, 0});
    
    r->addIndex<4>(ord184, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord185({1, 2, 3, 0});
    
    r->addIndex<4>(ord185, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup5638x68x0x0x0"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("$sup5638x67x0x0x0");
  if (r == 0) db->addRelation("$sup5638x67x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x67x0x0x0");
      std::vector<u16> ord186({1, 2, 0, 3});
    
    r->addIndex<4>(ord186, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 0, 3}, false, b), true);
      std::vector<u16> ord187({1, 2, 0, 3});
    
    r->addIndex<4>(ord187, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 0, 3}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup5638x67x0x0x0"), std::array<u16,4>{1, 2, 0, 3}, b));
  r = db->getRelation("$sup5638x62x0x0x0");
  if (r == 0) db->addRelation("$sup5638x62x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x62x0x0x0");
      std::vector<u16> ord188({4, 2, 3, 5, 0, 1});
    
    r->addIndex<6>(ord188, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{4, 2, 3, 5, 0, 1}, false, b), true);
      std::vector<u16> ord189({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord189, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), false);
      std::vector<u16> ord190({1, 3, 4, 0, 2, 5});
    
    r->addIndex<6>(ord190, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{1, 3, 4, 0, 2, 5}, false, b), false);
      std::vector<u16> ord191({1, 5, 0, 2, 3, 4});
    
    r->addIndex<6>(ord191, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{1, 5, 0, 2, 3, 4}, false, b), false);
      std::vector<u16> ord192({1, 3, 4, 0, 2, 5});
    
    r->addIndex<6>(ord192, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{1, 3, 4, 0, 2, 5}, true, b), false);
      std::vector<u16> ord193({1, 5, 0, 2, 3, 4});
    
    r->addIndex<6>(ord193, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{1, 5, 0, 2, 3, 4}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup5638x62x0x0x0"), std::array<u16,6>{4, 2, 3, 5, 0, 1}, b));
  r = db->getRelation("$sup5638x60x0x0x0");
  if (r == 0) db->addRelation("$sup5638x60x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x60x0x0x0");
      std::vector<u16> ord194({4, 2, 3, 5, 0, 1});
    
    r->addIndex<6>(ord194, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{4, 2, 3, 5, 0, 1}, false, b), true);
      std::vector<u16> ord195({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord195, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), false);
      std::vector<u16> ord196({1, 2, 0, 3, 4, 5});
    
    r->addIndex<6>(ord196, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{1, 2, 0, 3, 4, 5}, false, b), false);
      std::vector<u16> ord197({1, 3, 4, 0, 2, 5});
    
    r->addIndex<6>(ord197, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{1, 3, 4, 0, 2, 5}, false, b), false);
      std::vector<u16> ord198({1, 2, 0, 3, 4, 5});
    
    r->addIndex<6>(ord198, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{1, 2, 0, 3, 4, 5}, true, b), false);
      std::vector<u16> ord199({1, 3, 4, 0, 2, 5});
    
    r->addIndex<6>(ord199, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{1, 3, 4, 0, 2, 5}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup5638x60x0x0x0"), std::array<u16,6>{4, 2, 3, 5, 0, 1}, b));
  r = db->getRelation("$sup5638x59x0x0x0");
  if (r == 0) db->addRelation("$sup5638x59x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x59x0x0x0");
      std::vector<u16> ord200({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord200, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
      std::vector<u16> ord201({1, 3, 0, 2, 4, 5});
    
    r->addIndex<6>(ord201, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{1, 3, 0, 2, 4, 5}, false, b), false);
      std::vector<u16> ord202({2, 3, 4, 5, 0, 1});
    
    r->addIndex<6>(ord202, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{2, 3, 4, 5, 0, 1}, false, b), false);
      std::vector<u16> ord203({1, 3, 0, 2, 4, 5});
    
    r->addIndex<6>(ord203, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{1, 3, 0, 2, 4, 5}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup5638x59x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup5638x52x0x0x0");
  if (r == 0) db->addRelation("$sup5638x52x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x52x0x0x0");
      std::vector<u16> ord204({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord204, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup5638x52x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup5638x51x0x0x0");
  if (r == 0) db->addRelation("$sup5638x51x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x51x0x0x0");
      std::vector<u16> ord205({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord205, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup5638x51x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup5638x44x0x0x0");
  if (r == 0) db->addRelation("$sup5638x44x0x0x0", 8);
  else if (r->getArity() != 8)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x44x0x0x0");
      std::vector<u16> ord206({1, 3, 7, 0, 2, 4, 5, 6});
    
    r->addIndex<8>(ord206, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<8>(db, r, std::array<u16,8>{1, 3, 7, 0, 2, 4, 5, 6}, false, b), true);
      std::vector<u16> ord207({1, 4, 6, 7, 0, 2, 3, 5});
    
    r->addIndex<8>(ord207, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<8>(db, r, std::array<u16,8>{1, 4, 6, 7, 0, 2, 3, 5}, false, b), false);
      std::vector<u16> ord208({1, 7, 0, 6, 4, 2, 3, 5});
    
    r->addIndex<8>(ord208, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<8>(db, r, std::array<u16,8>{1, 7, 0, 6, 4, 2, 3, 5}, false, b), false);
      std::vector<u16> ord209({2, 3, 4, 5, 6, 0, 1, 7});
    
    r->addIndex<8>(ord209, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<8>(db, r, std::array<u16,8>{2, 3, 4, 5, 6, 0, 1, 7}, false, b), false);
      std::vector<u16> ord210({1, 3, 7, 0, 2, 4, 5, 6});
    
    r->addIndex<8>(ord210, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<8>(db, r, std::array<u16,8>{1, 3, 7, 0, 2, 4, 5, 6}, true, b), false);
      std::vector<u16> ord211({1, 7, 0, 6, 4, 2, 3, 5});
    
    r->addIndex<8>(ord211, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<8>(db, r, std::array<u16,8>{1, 7, 0, 6, 4, 2, 3, 5}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<8>(db, db->getRelation("$sup5638x44x0x0x0"), std::array<u16,8>{1, 3, 7, 0, 2, 4, 5, 6}, b));
  r = db->getRelation("$sup5638x42x0x0x1");
  if (r == 0) db->addRelation("$sup5638x42x0x0x1", 8);
  else if (r->getArity() != 8)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x42x0x0x1");
      std::vector<u16> ord212({1, 5, 0, 2, 3, 4, 6, 7});
    
    r->addIndex<8>(ord212, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<8>(db, r, std::array<u16,8>{1, 5, 0, 2, 3, 4, 6, 7}, false, b), true);
      std::vector<u16> ord213({0, 2, 7, 1, 3, 4, 5, 6});
    
    r->addIndex<8>(ord213, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<8>(db, r, std::array<u16,8>{0, 2, 7, 1, 3, 4, 5, 6}, false, b), false);
      std::vector<u16> ord214({1, 2, 4, 5, 0, 3, 6, 7});
    
    r->addIndex<8>(ord214, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<8>(db, r, std::array<u16,8>{1, 2, 4, 5, 0, 3, 6, 7}, false, b), false);
      std::vector<u16> ord215({2, 6, 7, 0, 1, 3, 4, 5});
    
    r->addIndex<8>(ord215, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<8>(db, r, std::array<u16,8>{2, 6, 7, 0, 1, 3, 4, 5}, false, b), false);
      std::vector<u16> ord216({3, 4, 5, 6, 0, 2, 7, 1});
    
    r->addIndex<8>(ord216, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<8>(db, r, std::array<u16,8>{3, 4, 5, 6, 0, 2, 7, 1}, false, b), false);
      std::vector<u16> ord217({1, 2, 4, 5, 0, 3, 6, 7});
    
    r->addIndex<8>(ord217, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<8>(db, r, std::array<u16,8>{1, 2, 4, 5, 0, 3, 6, 7}, true, b), false);
      std::vector<u16> ord218({3, 4, 5, 6, 0, 2, 7, 1});
    
    r->addIndex<8>(ord218, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<8>(db, r, std::array<u16,8>{3, 4, 5, 6, 0, 2, 7, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<8>(db, db->getRelation("$sup5638x42x0x0x1"), std::array<u16,8>{1, 5, 0, 2, 3, 4, 6, 7}, b));
  r = db->getRelation("$sup5638x42x0x0x0");
  if (r == 0) db->addRelation("$sup5638x42x0x0x0", 7);
  else if (r->getArity() != 7)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x42x0x0x0");
      std::vector<u16> ord219({4, 2, 3, 5, 0, 1, 6});
    
    r->addIndex<7>(ord219, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{4, 2, 3, 5, 0, 1, 6}, false, b), true);
      std::vector<u16> ord220({0, 1, 6, 2, 3, 4, 5});
    
    r->addIndex<7>(ord220, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{0, 1, 6, 2, 3, 4, 5}, false, b), false);
      std::vector<u16> ord221({1, 3, 4, 0, 2, 5, 6});
    
    r->addIndex<7>(ord221, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{1, 3, 4, 0, 2, 5, 6}, false, b), false);
      std::vector<u16> ord222({1, 5, 6, 0, 2, 3, 4});
    
    r->addIndex<7>(ord222, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{1, 5, 6, 0, 2, 3, 4}, false, b), false);
      std::vector<u16> ord223({1, 5, 6, 0, 2, 3, 4});
    
    r->addIndex<7>(ord223, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{1, 5, 6, 0, 2, 3, 4}, true, b), false);
      std::vector<u16> ord224({4, 2, 3, 5, 0, 1, 6});
    
    r->addIndex<7>(ord224, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{4, 2, 3, 5, 0, 1, 6}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<7>(db, db->getRelation("$sup5638x42x0x0x0"), std::array<u16,7>{4, 2, 3, 5, 0, 1, 6}, b));
  r = db->getRelation("$sup5638x40x0x0x1");
  if (r == 0) db->addRelation("$sup5638x40x0x0x1", 8);
  else if (r->getArity() != 8)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x40x0x0x1");
      std::vector<u16> ord225({1, 5, 0, 2, 3, 4, 6, 7});
    
    r->addIndex<8>(ord225, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<8>(db, r, std::array<u16,8>{1, 5, 0, 2, 3, 4, 6, 7}, false, b), true);
      std::vector<u16> ord226({0, 2, 7, 1, 3, 4, 5, 6});
    
    r->addIndex<8>(ord226, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<8>(db, r, std::array<u16,8>{0, 2, 7, 1, 3, 4, 5, 6}, false, b), false);
      std::vector<u16> ord227({1, 2, 4, 5, 0, 3, 6, 7});
    
    r->addIndex<8>(ord227, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<8>(db, r, std::array<u16,8>{1, 2, 4, 5, 0, 3, 6, 7}, false, b), false);
      std::vector<u16> ord228({2, 3, 7, 0, 1, 4, 5, 6});
    
    r->addIndex<8>(ord228, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<8>(db, r, std::array<u16,8>{2, 3, 7, 0, 1, 4, 5, 6}, false, b), false);
      std::vector<u16> ord229({3, 4, 5, 6, 0, 2, 7, 1});
    
    r->addIndex<8>(ord229, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<8>(db, r, std::array<u16,8>{3, 4, 5, 6, 0, 2, 7, 1}, false, b), false);
      std::vector<u16> ord230({1, 2, 4, 5, 0, 3, 6, 7});
    
    r->addIndex<8>(ord230, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<8>(db, r, std::array<u16,8>{1, 2, 4, 5, 0, 3, 6, 7}, true, b), false);
      std::vector<u16> ord231({3, 4, 5, 6, 0, 2, 7, 1});
    
    r->addIndex<8>(ord231, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<8>(db, r, std::array<u16,8>{3, 4, 5, 6, 0, 2, 7, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<8>(db, db->getRelation("$sup5638x40x0x0x1"), std::array<u16,8>{1, 5, 0, 2, 3, 4, 6, 7}, b));
  r = db->getRelation("$sup5638x40x0x0x0");
  if (r == 0) db->addRelation("$sup5638x40x0x0x0", 7);
  else if (r->getArity() != 7)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x40x0x0x0");
      std::vector<u16> ord232({4, 2, 3, 5, 0, 1, 6});
    
    r->addIndex<7>(ord232, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{4, 2, 3, 5, 0, 1, 6}, false, b), true);
      std::vector<u16> ord233({0, 1, 6, 2, 3, 4, 5});
    
    r->addIndex<7>(ord233, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{0, 1, 6, 2, 3, 4, 5}, false, b), false);
      std::vector<u16> ord234({1, 2, 6, 0, 3, 4, 5});
    
    r->addIndex<7>(ord234, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{1, 2, 6, 0, 3, 4, 5}, false, b), false);
      std::vector<u16> ord235({1, 3, 4, 0, 2, 5, 6});
    
    r->addIndex<7>(ord235, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{1, 3, 4, 0, 2, 5, 6}, false, b), false);
      std::vector<u16> ord236({1, 2, 6, 0, 3, 4, 5});
    
    r->addIndex<7>(ord236, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{1, 2, 6, 0, 3, 4, 5}, true, b), false);
      std::vector<u16> ord237({4, 2, 3, 5, 0, 1, 6});
    
    r->addIndex<7>(ord237, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{4, 2, 3, 5, 0, 1, 6}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<7>(db, db->getRelation("$sup5638x40x0x0x0"), std::array<u16,7>{4, 2, 3, 5, 0, 1, 6}, b));
  r = db->getRelation("$sup5638x29x0x0x2");
  if (r == 0) db->addRelation("$sup5638x29x0x0x2", 11);
  else if (r->getArity() != 11)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x29x0x0x2");
      std::vector<u16> ord238({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
    
    r->addIndex<11>(ord238, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10}, false, b), true);
      std::vector<u16> ord239({0, 7, 8, 9, 10, 1, 4, 2, 3, 5, 6});
    
    r->addIndex<11>(ord239, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{0, 7, 8, 9, 10, 1, 4, 2, 3, 5, 6}, false, b), false);
      std::vector<u16> ord240({1, 5, 6, 7, 0, 2, 3, 4, 8, 9, 10});
    
    r->addIndex<11>(ord240, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{1, 5, 6, 7, 0, 2, 3, 4, 8, 9, 10}, false, b), false);
      std::vector<u16> ord241({1, 6, 0, 2, 3, 4, 5, 7, 8, 9, 10});
    
    r->addIndex<11>(ord241, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{1, 6, 0, 2, 3, 4, 5, 7, 8, 9, 10}, false, b), false);
      std::vector<u16> ord242({5, 7, 1, 0, 2, 3, 4, 6, 8, 9, 10});
    
    r->addIndex<11>(ord242, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{5, 7, 1, 0, 2, 3, 4, 6, 8, 9, 10}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<11>(db, db->getRelation("$sup5638x29x0x0x2"), std::array<u16,11>{1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10}, b));
  r = db->getRelation("$sup5638x29x0x0x1");
  if (r == 0) db->addRelation("$sup5638x29x0x0x1", 7);
  else if (r->getArity() != 7)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x29x0x0x1");
      std::vector<u16> ord243({1, 2, 0, 3, 4, 5, 6});
    
    r->addIndex<7>(ord243, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{1, 2, 0, 3, 4, 5, 6}, false, b), true);
      std::vector<u16> ord244({0, 3, 4, 5, 6, 1, 2});
    
    r->addIndex<7>(ord244, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{0, 3, 4, 5, 6, 1, 2}, false, b), false);
      std::vector<u16> ord245({3, 1, 0, 2, 4, 5, 6});
    
    r->addIndex<7>(ord245, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{3, 1, 0, 2, 4, 5, 6}, false, b), false);
      std::vector<u16> ord246({0, 3, 4, 5, 6, 1, 2});
    
    r->addIndex<7>(ord246, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{0, 3, 4, 5, 6, 1, 2}, true, b), false);
      std::vector<u16> ord247({1, 2, 0, 3, 4, 5, 6});
    
    r->addIndex<7>(ord247, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{1, 2, 0, 3, 4, 5, 6}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<7>(db, db->getRelation("$sup5638x29x0x0x1"), std::array<u16,7>{1, 2, 0, 3, 4, 5, 6}, b));
  r = db->getRelation("$sup5638x29x0x0x0");
  if (r == 0) db->addRelation("$sup5638x29x0x0x0", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x29x0x0x0");
      std::vector<u16> ord248({1, 0, 2, 3, 4});
    
    r->addIndex<5>(ord248, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 0, 2, 3, 4}, false, b), true);
      std::vector<u16> ord249({1, 0, 2, 3, 4});
    
    r->addIndex<5>(ord249, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 0, 2, 3, 4}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<5>(db, db->getRelation("$sup5638x29x0x0x0"), std::array<u16,5>{1, 0, 2, 3, 4}, b));
  r = db->getRelation("$sup5638x25x0x0x2");
  if (r == 0) db->addRelation("$sup5638x25x0x0x2", 11);
  else if (r->getArity() != 11)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x25x0x0x2");
      std::vector<u16> ord250({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
    
    r->addIndex<11>(ord250, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10}, false, b), true);
      std::vector<u16> ord251({0, 7, 8, 9, 10, 1, 4, 2, 3, 5, 6});
    
    r->addIndex<11>(ord251, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{0, 7, 8, 9, 10, 1, 4, 2, 3, 5, 6}, false, b), false);
      std::vector<u16> ord252({1, 5, 6, 7, 0, 2, 3, 4, 8, 9, 10});
    
    r->addIndex<11>(ord252, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{1, 5, 6, 7, 0, 2, 3, 4, 8, 9, 10}, false, b), false);
      std::vector<u16> ord253({1, 6, 0, 2, 3, 4, 5, 7, 8, 9, 10});
    
    r->addIndex<11>(ord253, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{1, 6, 0, 2, 3, 4, 5, 7, 8, 9, 10}, false, b), false);
      std::vector<u16> ord254({5, 7, 1, 0, 2, 3, 4, 6, 8, 9, 10});
    
    r->addIndex<11>(ord254, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{5, 7, 1, 0, 2, 3, 4, 6, 8, 9, 10}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<11>(db, db->getRelation("$sup5638x25x0x0x2"), std::array<u16,11>{1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10}, b));
  r = db->getRelation("$sup5638x25x0x0x1");
  if (r == 0) db->addRelation("$sup5638x25x0x0x1", 7);
  else if (r->getArity() != 7)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x25x0x0x1");
      std::vector<u16> ord255({1, 2, 0, 3, 4, 5, 6});
    
    r->addIndex<7>(ord255, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{1, 2, 0, 3, 4, 5, 6}, false, b), true);
      std::vector<u16> ord256({0, 3, 4, 5, 6, 1, 2});
    
    r->addIndex<7>(ord256, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{0, 3, 4, 5, 6, 1, 2}, false, b), false);
      std::vector<u16> ord257({3, 1, 0, 2, 4, 5, 6});
    
    r->addIndex<7>(ord257, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{3, 1, 0, 2, 4, 5, 6}, false, b), false);
      std::vector<u16> ord258({0, 3, 4, 5, 6, 1, 2});
    
    r->addIndex<7>(ord258, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{0, 3, 4, 5, 6, 1, 2}, true, b), false);
      std::vector<u16> ord259({1, 2, 0, 3, 4, 5, 6});
    
    r->addIndex<7>(ord259, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{1, 2, 0, 3, 4, 5, 6}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<7>(db, db->getRelation("$sup5638x25x0x0x1"), std::array<u16,7>{1, 2, 0, 3, 4, 5, 6}, b));
  r = db->getRelation("$sup5638x25x0x0x0");
  if (r == 0) db->addRelation("$sup5638x25x0x0x0", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x25x0x0x0");
      std::vector<u16> ord260({1, 0, 2, 3, 4});
    
    r->addIndex<5>(ord260, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 0, 2, 3, 4}, false, b), true);
      std::vector<u16> ord261({1, 0, 2, 3, 4});
    
    r->addIndex<5>(ord261, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 0, 2, 3, 4}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<5>(db, db->getRelation("$sup5638x25x0x0x0"), std::array<u16,5>{1, 0, 2, 3, 4}, b));
  r = db->getRelation("$sup5638x127x0x0x0");
  if (r == 0) db->addRelation("$sup5638x127x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x127x0x0x0");
      std::vector<u16> ord262({5, 0, 1, 2, 3, 4});
    
    r->addIndex<6>(ord262, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{5, 0, 1, 2, 3, 4}, false, b), true);
      std::vector<u16> ord263({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord263, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), false);
      std::vector<u16> ord264({3, 4, 5, 0, 1, 2});
    
    r->addIndex<6>(ord264, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{3, 4, 5, 0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup5638x127x0x0x0"), std::array<u16,6>{5, 0, 1, 2, 3, 4}, b));
  r = db->getRelation("$sup5638x121x0x0x0");
  if (r == 0) db->addRelation("$sup5638x121x0x0x0", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x121x0x0x0");
      std::vector<u16> ord265({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord265, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<5>(db, db->getRelation("$sup5638x121x0x0x0"), std::array<u16,5>{0, 1, 2, 3, 4}, b));
  r = db->getRelation("$sup5638x110x0x0x0");
  if (r == 0) db->addRelation("$sup5638x110x0x0x0", 11);
  else if (r->getArity() != 11)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x110x0x0x0");
      std::vector<u16> ord266({3, 4, 0, 1, 2, 5, 6, 7, 8, 9, 10});
    
    r->addIndex<11>(ord266, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{3, 4, 0, 1, 2, 5, 6, 7, 8, 9, 10}, false, b), true);
      std::vector<u16> ord267({0, 7, 8, 1, 2, 3, 4, 5, 6, 9, 10});
    
    r->addIndex<11>(ord267, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{0, 7, 8, 1, 2, 3, 4, 5, 6, 9, 10}, false, b), false);
      std::vector<u16> ord268({1, 2, 4, 6, 7, 3, 0, 5, 8, 9, 10});
    
    r->addIndex<11>(ord268, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{1, 2, 4, 6, 7, 3, 0, 5, 8, 9, 10}, false, b), false);
      std::vector<u16> ord269({3, 5, 8, 9, 10, 0, 1, 2, 4, 6, 7});
    
    r->addIndex<11>(ord269, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{3, 5, 8, 9, 10, 0, 1, 2, 4, 6, 7}, false, b), false);
      std::vector<u16> ord270({4, 5, 7, 8, 0, 1, 2, 3, 6, 9, 10});
    
    r->addIndex<11>(ord270, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{4, 5, 7, 8, 0, 1, 2, 3, 6, 9, 10}, false, b), false);
      std::vector<u16> ord271({1, 2, 4, 6, 7, 3, 0, 5, 8, 9, 10});
    
    r->addIndex<11>(ord271, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{1, 2, 4, 6, 7, 3, 0, 5, 8, 9, 10}, true, b), false);
      std::vector<u16> ord272({4, 5, 7, 8, 0, 1, 2, 3, 6, 9, 10});
    
    r->addIndex<11>(ord272, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{4, 5, 7, 8, 0, 1, 2, 3, 6, 9, 10}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<11>(db, db->getRelation("$sup5638x110x0x0x0"), std::array<u16,11>{3, 4, 0, 1, 2, 5, 6, 7, 8, 9, 10}, b));
  r = db->getRelation("$sup5638x107x0x0x1");
  if (r == 0) db->addRelation("$sup5638x107x0x0x1", 10);
  else if (r->getArity() != 10)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x107x0x0x1");
      std::vector<u16> ord273({0, 9, 1, 2, 3, 4, 5, 6, 7, 8});
    
    r->addIndex<10>(ord273, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{0, 9, 1, 2, 3, 4, 5, 6, 7, 8}, false, b), true);
      std::vector<u16> ord274({1, 4, 5, 6, 0, 2, 3, 7, 8, 9});
    
    r->addIndex<10>(ord274, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{1, 4, 5, 6, 0, 2, 3, 7, 8, 9}, false, b), false);
      std::vector<u16> ord275({1, 6, 0, 2, 3, 4, 5, 7, 8, 9});
    
    r->addIndex<10>(ord275, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{1, 6, 0, 2, 3, 4, 5, 7, 8, 9}, false, b), false);
      std::vector<u16> ord276({2, 3, 5, 7, 0, 1, 4, 6, 8, 9});
    
    r->addIndex<10>(ord276, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{2, 3, 5, 7, 0, 1, 4, 6, 8, 9}, false, b), false);
      std::vector<u16> ord277({9, 4, 6, 8, 0, 2, 3, 5, 7, 1});
    
    r->addIndex<10>(ord277, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{9, 4, 6, 8, 0, 2, 3, 5, 7, 1}, false, b), false);
      std::vector<u16> ord278({1, 4, 5, 6, 0, 2, 3, 7, 8, 9});
    
    r->addIndex<10>(ord278, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{1, 4, 5, 6, 0, 2, 3, 7, 8, 9}, true, b), false);
      std::vector<u16> ord279({9, 4, 6, 8, 0, 2, 3, 5, 7, 1});
    
    r->addIndex<10>(ord279, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{9, 4, 6, 8, 0, 2, 3, 5, 7, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<10>(db, db->getRelation("$sup5638x107x0x0x1"), std::array<u16,10>{0, 9, 1, 2, 3, 4, 5, 6, 7, 8}, b));
  r = db->getRelation("$sup5638x107x0x0x0");
  if (r == 0) db->addRelation("$sup5638x107x0x0x0", 9);
  else if (r->getArity() != 9)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x107x0x0x0");
      std::vector<u16> ord280({0, 8, 1, 2, 3, 4, 5, 6, 7});
    
    r->addIndex<9>(ord280, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{0, 8, 1, 2, 3, 4, 5, 6, 7}, false, b), true);
      std::vector<u16> ord281({1, 2, 4, 6, 0, 3, 5, 7, 8});
    
    r->addIndex<9>(ord281, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{1, 2, 4, 6, 0, 3, 5, 7, 8}, false, b), false);
      std::vector<u16> ord282({3, 4, 5, 0, 1, 2, 6, 7, 8});
    
    r->addIndex<9>(ord282, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{3, 4, 5, 0, 1, 2, 6, 7, 8}, false, b), false);
      std::vector<u16> ord283({5, 3, 7, 8, 0, 1, 2, 4, 6});
    
    r->addIndex<9>(ord283, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{5, 3, 7, 8, 0, 1, 2, 4, 6}, false, b), false);
      std::vector<u16> ord284({8, 0, 1, 2, 3, 4, 5, 6, 7});
    
    r->addIndex<9>(ord284, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{8, 0, 1, 2, 3, 4, 5, 6, 7}, false, b), false);
      std::vector<u16> ord285({5, 3, 7, 8, 0, 1, 2, 4, 6});
    
    r->addIndex<9>(ord285, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{5, 3, 7, 8, 0, 1, 2, 4, 6}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<9>(db, db->getRelation("$sup5638x107x0x0x0"), std::array<u16,9>{0, 8, 1, 2, 3, 4, 5, 6, 7}, b));
  r = db->getRelation("$sup5638x104x0x0x1");
  if (r == 0) db->addRelation("$sup5638x104x0x0x1", 10);
  else if (r->getArity() != 10)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x104x0x0x1");
      std::vector<u16> ord286({0, 8, 1, 2, 3, 4, 5, 6, 7, 9});
    
    r->addIndex<10>(ord286, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{0, 8, 1, 2, 3, 4, 5, 6, 7, 9}, false, b), true);
      std::vector<u16> ord287({1, 4, 5, 6, 0, 2, 3, 7, 8, 9});
    
    r->addIndex<10>(ord287, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{1, 4, 5, 6, 0, 2, 3, 7, 8, 9}, false, b), false);
      std::vector<u16> ord288({1, 6, 0, 2, 3, 4, 5, 7, 8, 9});
    
    r->addIndex<10>(ord288, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{1, 6, 0, 2, 3, 4, 5, 7, 8, 9}, false, b), false);
      std::vector<u16> ord289({2, 3, 5, 7, 0, 1, 4, 6, 8, 9});
    
    r->addIndex<10>(ord289, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{2, 3, 5, 7, 0, 1, 4, 6, 8, 9}, false, b), false);
      std::vector<u16> ord290({8, 4, 6, 9, 0, 2, 3, 5, 7, 1});
    
    r->addIndex<10>(ord290, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{8, 4, 6, 9, 0, 2, 3, 5, 7, 1}, false, b), false);
      std::vector<u16> ord291({1, 4, 5, 6, 0, 2, 3, 7, 8, 9});
    
    r->addIndex<10>(ord291, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{1, 4, 5, 6, 0, 2, 3, 7, 8, 9}, true, b), false);
      std::vector<u16> ord292({8, 4, 6, 9, 0, 2, 3, 5, 7, 1});
    
    r->addIndex<10>(ord292, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{8, 4, 6, 9, 0, 2, 3, 5, 7, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<10>(db, db->getRelation("$sup5638x104x0x0x1"), std::array<u16,10>{0, 8, 1, 2, 3, 4, 5, 6, 7, 9}, b));
  r = db->getRelation("$sup5638x104x0x0x0");
  if (r == 0) db->addRelation("$sup5638x104x0x0x0", 9);
  else if (r->getArity() != 9)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x104x0x0x0");
      std::vector<u16> ord293({0, 7, 1, 2, 3, 4, 5, 6, 8});
    
    r->addIndex<9>(ord293, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{0, 7, 1, 2, 3, 4, 5, 6, 8}, false, b), true);
      std::vector<u16> ord294({1, 2, 4, 6, 0, 3, 5, 7, 8});
    
    r->addIndex<9>(ord294, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{1, 2, 4, 6, 0, 3, 5, 7, 8}, false, b), false);
      std::vector<u16> ord295({3, 4, 5, 0, 1, 2, 6, 7, 8});
    
    r->addIndex<9>(ord295, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{3, 4, 5, 0, 1, 2, 6, 7, 8}, false, b), false);
      std::vector<u16> ord296({5, 3, 7, 8, 0, 1, 2, 4, 6});
    
    r->addIndex<9>(ord296, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{5, 3, 7, 8, 0, 1, 2, 4, 6}, false, b), false);
      std::vector<u16> ord297({7, 0, 1, 2, 3, 4, 5, 6, 8});
    
    r->addIndex<9>(ord297, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{7, 0, 1, 2, 3, 4, 5, 6, 8}, false, b), false);
      std::vector<u16> ord298({5, 3, 7, 8, 0, 1, 2, 4, 6});
    
    r->addIndex<9>(ord298, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{5, 3, 7, 8, 0, 1, 2, 4, 6}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<9>(db, db->getRelation("$sup5638x104x0x0x0"), std::array<u16,9>{0, 7, 1, 2, 3, 4, 5, 6, 8}, b));
  r = db->getRelation("$sup5638x101x0x0x0");
  if (r == 0) db->addRelation("$sup5638x101x0x0x0", 11);
  else if (r->getArity() != 11)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5638x101x0x0x0");
      std::vector<u16> ord299({2, 5, 0, 1, 3, 4, 6, 7, 8, 9, 10});
    
    r->addIndex<11>(ord299, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{2, 5, 0, 1, 3, 4, 6, 7, 8, 9, 10}, false, b), true);
      std::vector<u16> ord300({0, 7, 8, 1, 2, 3, 4, 5, 6, 9, 10});
    
    r->addIndex<11>(ord300, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{0, 7, 8, 1, 2, 3, 4, 5, 6, 9, 10}, false, b), false);
      std::vector<u16> ord301({1, 2, 4, 6, 7, 5, 0, 3, 8, 9, 10});
    
    r->addIndex<11>(ord301, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{1, 2, 4, 6, 7, 5, 0, 3, 8, 9, 10}, false, b), false);
      std::vector<u16> ord302({3, 5, 8, 9, 10, 0, 1, 2, 4, 6, 7});
    
    r->addIndex<11>(ord302, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{3, 5, 8, 9, 10, 0, 1, 2, 4, 6, 7}, false, b), false);
      std::vector<u16> ord303({4, 5, 7, 8, 0, 1, 2, 3, 6, 9, 10});
    
    r->addIndex<11>(ord303, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{4, 5, 7, 8, 0, 1, 2, 3, 6, 9, 10}, false, b), false);
      std::vector<u16> ord304({1, 2, 4, 6, 7, 5, 0, 3, 8, 9, 10});
    
    r->addIndex<11>(ord304, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{1, 2, 4, 6, 7, 5, 0, 3, 8, 9, 10}, true, b), false);
      std::vector<u16> ord305({4, 5, 7, 8, 0, 1, 2, 3, 6, 9, 10});
    
    r->addIndex<11>(ord305, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{4, 5, 7, 8, 0, 1, 2, 3, 6, 9, 10}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<11>(db, db->getRelation("$sup5638x101x0x0x0"), std::array<u16,11>{2, 5, 0, 1, 3, 4, 6, 7, 8, 9, 10}, b));
  r = db->getRelation("$seq_at");
  if (r == 0) db->addRelation("$seq_at", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$seq_at");
      std::vector<u16> ord306({1, 0, 2});
    
    r->addIndex<3>(ord306, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 0, 2}, false, b), true);
      std::vector<u16> ord307({1, 0, 2});
    
    r->addIndex<3>(ord307, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 0, 2}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$seq_at"), std::array<u16,3>{1, 0, 2}, b));
  {
    std::vector<u16> seqcols({1});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("mp_fromlist"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  slog_rules_cc6157e7c6a73b0a1(db, s);
  slog_rules_c7adbd30ff68a90cb(db, s);
  slog_rules_cae5e53883d639a44(db, s);
  slog_rules_cb43d5e633d046d7f(db, s);
  slog_rules_c5e507d0827aa73d6(db, s);
  slog_rules_cf1315b147c9a2b4b(db, s);
  slog_rules_c53642b523c6cca89(db, s);
  slog_rules_ca0ddd135f242cff4(db, s);
  slog_rules_cb145c2cedadd9aea(db, s);
  slog_rules_c135f00f5c4b371c2(db, s);
  slog_rules_c6ea2ad2d2425c003(db, s);
  slog_rules_c738f16f39e0507e0(db, s);
  slog_rules_c04f93a1558b3b6fd(db, s);
  slog_rules_ce117930327306c0d(db, s);
  slog_rules_cfd10cb788fe91aa2(db, s);
  slog_rules_c692e503ff718572d(db, s);
  s->addReadRel("$seq_at");
  s->addReadRel("$sup5638x101x0x0x0");
  s->addReadRel("$sup5638x104x0x0x0");
  s->addReadRel("$sup5638x104x0x0x1");
  s->addReadRel("$sup5638x107x0x0x0");
  s->addReadRel("$sup5638x107x0x0x1");
  s->addReadRel("$sup5638x110x0x0x0");
  s->addReadRel("$sup5638x127x0x0x0");
  s->addReadRel("$sup5638x25x0x0x0");
  s->addReadRel("$sup5638x25x0x0x1");
  s->addReadRel("$sup5638x25x0x0x2");
  s->addReadRel("$sup5638x29x0x0x0");
  s->addReadRel("$sup5638x29x0x0x1");
  s->addReadRel("$sup5638x29x0x0x2");
  s->addReadRel("$sup5638x40x0x0x0");
  s->addReadRel("$sup5638x40x0x0x1");
  s->addReadRel("$sup5638x42x0x0x0");
  s->addReadRel("$sup5638x42x0x0x1");
  s->addReadRel("$sup5638x44x0x0x0");
  s->addReadRel("$sup5638x59x0x0x0");
  s->addReadRel("$sup5638x60x0x0x0");
  s->addReadRel("$sup5638x62x0x0x0");
  s->addReadRel("$sup5638x67x0x0x0");
  s->addReadRel("$sup5638x68x0x0x0");
  s->addReadRel("$sup5638x81x0x0x0");
  s->addReadRel("$sup5638x82x0x0x0");
  s->addReadRel("$sup5638x84x0x0x0");
  s->addReadRel("$sup5638x93x0x0x0");
  s->addReadRel("$sup5638x95x0x0x0");
  s->addReadRel("$sup5638x95x0x0x1");
  s->addReadRel("$sup5638x98x0x0x0");
  s->addReadRel("$sup5638x98x0x0x1");
  s->addReadRel("_enum");
  s->addReadRel("canon");
  s->addReadRel("div_by_zero");
  s->addReadRel("int_overflow");
  s->addReadRel("malformed_deduction");
  s->addReadRel("mbranch");
  s->addReadRel("mleaf");
  s->addReadRel("modulo_by_zero");
  s->addReadRel("mp_bld");
  s->addReadRel("mp_bld_ans");
  s->addReadRel("mp_del");
  s->addReadRel("mp_del_ans");
  s->addReadRel("mp_fromlist");
  s->addReadRel("mp_fromlist_ans");
  s->addReadRel("mp_has0");
  s->addReadRel("mp_has0_ans");
  s->addReadRel("mp_hsb");
  s->addReadRel("mp_hsb_ans");
  s->addReadRel("mp_join");
  s->addReadRel("mp_join_ans");
  s->addReadRel("mp_msk");
  s->addReadRel("mp_msk_ans");
  s->addReadRel("mp_put");
  s->addReadRel("mp_put_ans");
  s->addReadRel("mp_put_soft");
  s->addReadRel("mp_put_soft_ans");
  s->addReadRel("mp_union");
  s->addReadRel("mp_union_ans");
  s->addReadRel("mpz_overflow");
  s->addReadRel("mpz_table_overflow");
  s->addReadRel("nan_result");
  s->addReadRel("temp03QX1021");
  s->addReadRel("temp0EGL1024");
  s->addReadRel("temp1Gnx1042");
  s->addReadRel("temp1XD61034");
  s->addReadRel("temp1Yd51020");
  s->addReadRel("temp1bhg1089");
  s->addReadRel("temp2Hkq1086");
  s->addReadRel("temp2PlQ1027");
  s->addReadRel("temp2mZ61026");
  s->addReadRel("temp2oEt1084");
  s->addReadRel("temp2xeX1033");
  s->addReadRel("temp2ytq1023");
  s->addReadRel("temp4Eqs1025");
  s->addReadRel("temp4cOw1069");
  s->addReadRel("temp4kFO1073");
  s->addReadRel("temp5A4p1059");
  s->addReadRel("temp5R2q1072");
  s->addReadRel("temp5jzw1068");
  s->addReadRel("temp5uMp1022");
  s->addReadRel("temp5z0Y1074");
  s->addReadRel("temp61Si1083");
  s->addReadRel("temp6KDK1090");
  s->addReadRel("temp6y6l1036");
  s->addReadRel("temp7FV11078");
  s->addReadRel("temp7KpW1055");
  s->addReadRel("temp8GS31028");
  s->addReadRel("temp8fvz1067");
  s->addReadRel("temp8y4n1085");
  s->addReadRel("temp9B581035");
  s->addReadRel("toint_range");
  s->addReadRel("type_mismatch");
  s->addDynamicRel("$seq_at");
  s->addDynamicRel("$sup5638x101x0x0x0");
  s->addDynamicRel("$sup5638x104x0x0x0");
  s->addDynamicRel("$sup5638x104x0x0x1");
  s->addDynamicRel("$sup5638x107x0x0x0");
  s->addDynamicRel("$sup5638x107x0x0x1");
  s->addDynamicRel("$sup5638x110x0x0x0");
  s->addDynamicRel("$sup5638x25x0x0x0");
  s->addDynamicRel("$sup5638x25x0x0x1");
  s->addDynamicRel("$sup5638x25x0x0x2");
  s->addDynamicRel("$sup5638x29x0x0x0");
  s->addDynamicRel("$sup5638x29x0x0x1");
  s->addDynamicRel("$sup5638x29x0x0x2");
  s->addDynamicRel("$sup5638x40x0x0x0");
  s->addDynamicRel("$sup5638x40x0x0x1");
  s->addDynamicRel("$sup5638x42x0x0x0");
  s->addDynamicRel("$sup5638x42x0x0x1");
  s->addDynamicRel("$sup5638x44x0x0x0");
  s->addDynamicRel("$sup5638x59x0x0x0");
  s->addDynamicRel("$sup5638x60x0x0x0");
  s->addDynamicRel("$sup5638x62x0x0x0");
  s->addDynamicRel("$sup5638x67x0x0x0");
  s->addDynamicRel("$sup5638x68x0x0x0");
  s->addDynamicRel("$sup5638x81x0x0x0");
  s->addDynamicRel("$sup5638x82x0x0x0");
  s->addDynamicRel("$sup5638x84x0x0x0");
  s->addDynamicRel("$sup5638x93x0x0x0");
  s->addDynamicRel("$sup5638x95x0x0x0");
  s->addDynamicRel("$sup5638x95x0x0x1");
  s->addDynamicRel("$sup5638x98x0x0x0");
  s->addDynamicRel("$sup5638x98x0x0x1");
  s->addDynamicRel("canon");
  s->addDynamicRel("div_by_zero");
  s->addDynamicRel("error");
  s->addDynamicRel("int_overflow");
  s->addDynamicRel("malformed_deduction");
  s->addDynamicRel("mbranch");
  s->addDynamicRel("mleaf");
  s->addDynamicRel("modulo_by_zero");
  s->addDynamicRel("mp_bld");
  s->addDynamicRel("mp_bld_ans");
  s->addDynamicRel("mp_del");
  s->addDynamicRel("mp_del_ans");
  s->addDynamicRel("mp_fromlist_ans");
  s->addDynamicRel("mp_has0");
  s->addDynamicRel("mp_has0_ans");
  s->addDynamicRel("mp_hsb");
  s->addDynamicRel("mp_hsb_ans");
  s->addDynamicRel("mp_join");
  s->addDynamicRel("mp_join_ans");
  s->addDynamicRel("mp_msk");
  s->addDynamicRel("mp_msk_ans");
  s->addDynamicRel("mp_put");
  s->addDynamicRel("mp_put_ans");
  s->addDynamicRel("mp_put_soft");
  s->addDynamicRel("mp_put_soft_ans");
  s->addDynamicRel("mp_union");
  s->addDynamicRel("mp_union_ans");
  s->addDynamicRel("mpz_overflow");
  s->addDynamicRel("mpz_table_overflow");
  s->addDynamicRel("nan_result");
  s->addDynamicRel("temp03QX1021");
  s->addDynamicRel("temp0EGL1024");
  s->addDynamicRel("temp1Gnx1042");
  s->addDynamicRel("temp1XD61034");
  s->addDynamicRel("temp1Yd51020");
  s->addDynamicRel("temp1bhg1089");
  s->addDynamicRel("temp2Hkq1086");
  s->addDynamicRel("temp2PlQ1027");
  s->addDynamicRel("temp2mZ61026");
  s->addDynamicRel("temp2oEt1084");
  s->addDynamicRel("temp2xeX1033");
  s->addDynamicRel("temp2ytq1023");
  s->addDynamicRel("temp4Eqs1025");
  s->addDynamicRel("temp4cOw1069");
  s->addDynamicRel("temp4kFO1073");
  s->addDynamicRel("temp5A4p1059");
  s->addDynamicRel("temp5R2q1072");
  s->addDynamicRel("temp5jzw1068");
  s->addDynamicRel("temp5uMp1022");
  s->addDynamicRel("temp5z0Y1074");
  s->addDynamicRel("temp61Si1083");
  s->addDynamicRel("temp6KDK1090");
  s->addDynamicRel("temp6y6l1036");
  s->addDynamicRel("temp7FV11078");
  s->addDynamicRel("temp7KpW1055");
  s->addDynamicRel("temp8GS31028");
  s->addDynamicRel("temp8fvz1067");
  s->addDynamicRel("temp8y4n1085");
  s->addDynamicRel("temp9B581035");
  s->addDynamicRel("toint_range");
  s->addDynamicRel("type_mismatch");
  s->addAccelRel("canon");
  s->addAccelRel("mp_bld_ans");
  s->addAccelRel("mp_del_ans");
  s->addAccelRel("mp_fromlist_ans");
  s->addAccelRel("mp_has0_ans");
  s->addAccelRel("mp_hsb_ans");
  s->addAccelRel("mp_join_ans");
  s->addAccelRel("mp_msk_ans");
  s->addAccelRel("mp_put_ans");
  s->addAccelRel("mp_put_soft_ans");
  s->addAccelRel("mp_union_ans");
  d->push(s);
  d->continueRun();
}

