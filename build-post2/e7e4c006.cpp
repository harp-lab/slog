
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const5feceb66ffc86f38d952786c;
u64 v_const7902699be42c8a8e46fbbb45;
u64 v_const2c624232cdd221771294dfbb;
u64 v_const1d9eff40314d54862fee3942;
u64 v_const6b86b273ff34fce19d6b804e;
u64 v_const26c89ee8ccc4ea998fd1a912;
u64 v_constd4735e3a265e16eee03f5971;
u64 v_const5df67abc0c9885765912ad3d;
u64 v_constd9f85eba98ed33f6c0ac9bf6;
u64 v_constb0e9a61bdf716031c5ca8c29;
u64 v_constb9bc7505101241ebf0c7cf59;
u64 v_const7d00193796cbe9983b9801f2;
u64 v_const4e07408562bedb8b60ce05c1;
u64 v_constdee70e0c1571644b5844be78;
u64 v_const4b227777d4dd1fc61c6f884f;
u64 v_conste3776bfed7f405de8017ecfa;
u64 v_const66633592860a63ea6408b433;
u64 v_constef2d127de37b942baad06145;
u64 v_constd2ed9ad006724fa952709457;
u64 v_conste19dc92e0d47b9f7f5bc6441;
u64 v_const76a4fedc25549f0939d52fb7;
u64 v_const1e44311dd5d36c3a7dc21dfa;
u64 v_conste09004dcc147461a8e3857fe;
u64 v_const8719959a9b35fbf66b391c9f;
u64 v_const9899bd1a9f17c17561973172;
u64 v_const6235871e739625dd33ac2813;
u64 v_constcbf5a4e983555adcacc7f2e9;
u64 v_conste5e223bf70bc83faf3ce3a31;
u64 v_const7ce11965015db325c92ba444;
u64 v_const2d2149bb550ad5e39952d8f4;
u64 v_constc49bf1a249fe0ece92ed8fd8;
u64 v_const987d6cf2e5032ff135cc0c65;
u64 v_constbeaae0387ae49b5204a99e32;
u64 v_constf2664e0abda1016213c9fa90;
u64 v_const4a5462bd8cd8940b1e58a782;
u64 v_const81906d9241165d9f6a541e47;
u64 v_consta10f76b4ec574de5d7b6908e;
u64 v_constf95dfec4ee2675891829b965;
u64 v_const35c71810897f279c2099acbb;
u64 v_const5d058eae1c2c75768f73b199;
u64 v_const22475024b8f1c7d620b83a7c;
u64 v_const78643ffd185a1863a6e6997e;
u64 v_const99e1cbf3d792d4a87847a801;
u64 v_const94d9c4e2675ef4bd8443d499;
u64 v_const5e6127cdd5ea2629462053c9;
u64 v_consteea677b485376be09c1a9cc9;

void slog_rules_c823fae8cf812f2da(slog::Database* db, slog::Stratum* s);
void slog_rules_cbabdb3c6024ae24d(slog::Database* db, slog::Stratum* s);
void slog_rules_cc67696b823a1d9b9(slog::Database* db, slog::Stratum* s);
void slog_rules_c8c9720fd6e0bc4f9(slog::Database* db, slog::Stratum* s);
void slog_rules_c65bbed1236339abd(slog::Database* db, slog::Stratum* s);
void slog_rules_c00af38e888f83b07(slog::Database* db, slog::Stratum* s);
void slog_rules_cb8ebc47edbdc47eb(slog::Database* db, slog::Stratum* s);
void slog_rules_c1a7954baa8c7a132(slog::Database* db, slog::Stratum* s);
void slog_rules_c7cf27517710f1393(slog::Database* db, slog::Stratum* s);
void slog_rules_c54d73746b0e79d0e(slog::Database* db, slog::Stratum* s);
void slog_rules_c73ff02b198ad68e4(slog::Database* db, slog::Stratum* s);
void slog_rules_c41f2ec6a574d4d3d(slog::Database* db, slog::Stratum* s);
void slog_rules_c66c32b0817855ec9(slog::Database* db, slog::Stratum* s);
void slog_rules_c6481f25fa5c8b850(slog::Database* db, slog::Stratum* s);
void slog_rules_cd02a570b13bbad42(slog::Database* db, slog::Stratum* s);
void slog_rules_c78f902bcfebb45d1(slog::Database* db, slog::Stratum* s);


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("e7e4c006");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const5feceb66ffc86f38d952786c = s32_encode(0);
  v_const7902699be42c8a8e46fbbb45 = s32_encode(7);
  v_const2c624232cdd221771294dfbb = s32_encode(8);
  v_const1d9eff40314d54862fee3942 = db->encodeString("st_diff");
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  v_const26c89ee8ccc4ea998fd1a912 = db->encodeString("st_bld");
  v_constd4735e3a265e16eee03f5971 = s32_encode(2);
  v_const5df67abc0c9885765912ad3d = db->encodeString("set.slog:37");
  v_constd9f85eba98ed33f6c0ac9bf6 = db->encodeString("set.slog:55");
  v_constb0e9a61bdf716031c5ca8c29 = db->encodeString("set.slog:53");
  v_constb9bc7505101241ebf0c7cf59 = db->encodeString("set.slog:41");
  v_const7d00193796cbe9983b9801f2 = db->encodeString("set.slog:51");
  v_const4e07408562bedb8b60ce05c1 = s32_encode(3);
  v_constdee70e0c1571644b5844be78 = db->encodeString("st_mem0");
  v_const4b227777d4dd1fc61c6f884f = s32_encode(4);
  v_conste3776bfed7f405de8017ecfa = db->encodeString("pempty");
  v_const66633592860a63ea6408b433 = db->encodeString("pbranch");
  v_constef2d127de37b942baad06145 = s32_encode(5);
  v_constd2ed9ad006724fa952709457 = db->encodeString("set.slog:70");
  v_conste19dc92e0d47b9f7f5bc6441 = db->encodeString("set.slog:73");
  v_const76a4fedc25549f0939d52fb7 = db->encodeString("set.slog:89");
  v_const1e44311dd5d36c3a7dc21dfa = db->encodeString("set.slog:91");
  v_conste09004dcc147461a8e3857fe = db->encodeString("set.slog:71");
  v_const8719959a9b35fbf66b391c9f = db->encodeString("set.slog:88");
  v_const9899bd1a9f17c17561973172 = db->encodeString("st_join");
  v_const6235871e739625dd33ac2813 = db->encodeString("set.slog:169");
  v_constcbf5a4e983555adcacc7f2e9 = db->encodeString("set.slog:152");
  v_conste5e223bf70bc83faf3ce3a31 = db->encodeString("set.slog:155");
  v_const7ce11965015db325c92ba444 = db->encodeString("set.slog:149");
  v_const2d2149bb550ad5e39952d8f4 = db->encodeString("set.slog:118");
  v_constc49bf1a249fe0ece92ed8fd8 = db->encodeString("set.slog:111");
  v_const987d6cf2e5032ff135cc0c65 = db->encodeString("set.slog:140");
  v_constbeaae0387ae49b5204a99e32 = db->encodeString("set.slog:146");
  v_constf2664e0abda1016213c9fa90 = db->encodeString("set.slog:137");
  v_const4a5462bd8cd8940b1e58a782 = db->encodeString("set.slog:121");
  v_const81906d9241165d9f6a541e47 = db->encodeString("set.slog:143");
  v_consta10f76b4ec574de5d7b6908e = db->encodeString("st_msk");
  v_constf95dfec4ee2675891829b965 = db->encodeString("set.slog:115");
  v_const35c71810897f279c2099acbb = db->encodeString("set.slog:101");
  v_const5d058eae1c2c75768f73b199 = db->encodeString("pleaf");
  v_const22475024b8f1c7d620b83a7c = db->encodeString("set.slog:107");
  v_const78643ffd185a1863a6e6997e = db->encodeString("set.slog:104");
  v_const99e1cbf3d792d4a87847a801 = db->encodeString("st_ins");
  v_const94d9c4e2675ef4bd8443d499 = db->encodeString("st_union");
  v_const5e6127cdd5ea2629462053c9 = db->encodeString("st_basic.slog:24");
  v_consteea677b485376be09c1a9cc9 = db->encodeString("st_del");
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
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord1({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord1, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord2({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord2, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord3({1, 2, 0});
    
    r->addIndex<3>(ord3, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord4({0, 1, 2});
    
    r->addIndex<3>(ord4, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("temp9eaB1343");
  if (r == 0) db->addTempRelation("temp9eaB1343", 5);
  else if (r->getArity() != 5) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp9CLY1403");
  if (r == 0) db->addTempRelation("temp9CLY1403", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp8v341350");
  if (r == 0) db->addTempRelation("temp8v341350", 5);
  else if (r->getArity() != 5) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp8kS01399");
  if (r == 0) db->addTempRelation("temp8kS01399", 5);
  else if (r->getArity() != 5) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp8c8A1414");
  if (r == 0) db->addTempRelation("temp8c8A1414", 3);
  else if (r->getArity() != 3) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp7u1Q1268");
  if (r == 0) db->addTempRelation("temp7u1Q1268", 2);
  else if (r->getArity() != 2) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp7aSv1347");
  if (r == 0) db->addTempRelation("temp7aSv1347", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp7LNh1339");
  if (r == 0) db->addTempRelation("temp7LNh1339", 5);
  else if (r->getArity() != 5) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp7DYO1402");
  if (r == 0) db->addTempRelation("temp7DYO1402", 3);
  else if (r->getArity() != 3) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp76Kg1410");
  if (r == 0) db->addTempRelation("temp76Kg1410", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp6bMv1274");
  if (r == 0) db->addTempRelation("temp6bMv1274", 5);
  else if (r->getArity() != 5) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp5blj1404");
  if (r == 0) db->addTempRelation("temp5blj1404", 5);
  else if (r->getArity() != 5) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp5IQT1412");
  if (r == 0) db->addTempRelation("temp5IQT1412", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp5Bov1275");
  if (r == 0) db->addTempRelation("temp5Bov1275", 5);
  else if (r->getArity() != 5) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp4rmF1269");
  if (r == 0) db->addTempRelation("temp4rmF1269", 5);
  else if (r->getArity() != 5) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp4p811353");
  if (r == 0) db->addTempRelation("temp4p811353", 5);
  else if (r->getArity() != 5) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp4PCZ1408");
  if (r == 0) db->addTempRelation("temp4PCZ1408", 5);
  else if (r->getArity() != 5) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp4FcU1416");
  if (r == 0) db->addTempRelation("temp4FcU1416", 3);
  else if (r->getArity() != 3) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp44eI1413");
  if (r == 0) db->addTempRelation("temp44eI1413", 3);
  else if (r->getArity() != 3) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp3xVH1332");
  if (r == 0) db->addTempRelation("temp3xVH1332", 5);
  else if (r->getArity() != 5) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp3vnE1273");
  if (r == 0) db->addTempRelation("temp3vnE1273", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp3V0b1338");
  if (r == 0) db->addTempRelation("temp3V0b1338", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp3Stv1345");
  if (r == 0) db->addTempRelation("temp3Stv1345", 5);
  else if (r->getArity() != 5) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp3LID1346");
  if (r == 0) db->addTempRelation("temp3LID1346", 5);
  else if (r->getArity() != 5) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp20p21276");
  if (r == 0) db->addTempRelation("temp20p21276", 5);
  else if (r->getArity() != 5) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp1pqw1409");
  if (r == 0) db->addTempRelation("temp1pqw1409", 5);
  else if (r->getArity() != 5) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp1gVy1270");
  if (r == 0) db->addTempRelation("temp1gVy1270", 2);
  else if (r->getArity() != 2) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp1foc1411");
  if (r == 0) db->addTempRelation("temp1foc1411", 1);
  else if (r->getArity() != 1) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp1Dk71281");
  if (r == 0) db->addTempRelation("temp1Dk71281", 5);
  else if (r->getArity() != 5) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp18xQ1344");
  if (r == 0) db->addTempRelation("temp18xQ1344", 5);
  else if (r->getArity() != 5) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp16ye1280");
  if (r == 0) db->addTempRelation("temp16ye1280", 5);
  else if (r->getArity() != 5) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("temp00v81415");
  if (r == 0) db->addTempRelation("temp00v81415", 2);
  else if (r->getArity() != 2) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("sz");
  if (r == 0) db->addRelation("sz", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("sz");
      std::vector<u16> ord5({0});
    
    r->addIndex<1>(ord5, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("sz"), std::array<u16,1>{0}, b));
  r = db->getRelation("st_union_ans");
  if (r == 0) db->addRelation("st_union_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_union_ans");
      std::vector<u16> ord6({0, 1});
    
    r->addIndex<2>(ord6, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
      std::vector<u16> ord7({0, 1});
    
    r->addIndex<2>(ord7, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("st_union_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("st_union");
  if (r == 0) db->addStruct("st_union", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_union");
      std::vector<u16> ord8({1, 2, 0});
    
    r->addIndex<3>(ord8, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord9({0, 1, 2});
    
    r->addIndex<3>(ord9, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
      std::vector<u16> ord10({2, 0, 1});
    
    r->addIndex<3>(ord10, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, false, b), false);
      std::vector<u16> ord11({0, 1, 2});
    
    r->addIndex<3>(ord11, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, true, b), false);
      std::vector<u16> ord12({1, 2, 0});
    
    r->addIndex<3>(ord12, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, true, b), false);
      std::vector<u16> ord13({2, 0, 1});
    
    r->addIndex<3>(ord13, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("st_union"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("st_size_ans");
  if (r == 0) db->addRelation("st_size_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_size_ans");
      std::vector<u16> ord14({0, 1});
    
    r->addIndex<2>(ord14, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("st_size_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("st_size");
  if (r == 0) db->addStruct("st_size", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_size");
      std::vector<u16> ord15({1, 0});
    
    r->addIndex<2>(ord15, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord16({0, 1});
    
    r->addIndex<2>(ord16, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("st_size"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("st_msk_ans");
  if (r == 0) db->addRelation("st_msk_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_msk_ans");
      std::vector<u16> ord17({0, 1});
    
    r->addIndex<2>(ord17, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
      std::vector<u16> ord18({1, 0});
    
    r->addIndex<2>(ord18, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), false);
      std::vector<u16> ord19({0, 1});
    
    r->addIndex<2>(ord19, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("st_msk_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("st_msk");
  if (r == 0) db->addStruct("st_msk", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_msk");
      std::vector<u16> ord20({1, 2, 0});
    
    r->addIndex<3>(ord20, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord21({0, 1, 2});
    
    r->addIndex<3>(ord21, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
      std::vector<u16> ord22({2, 0, 1});
    
    r->addIndex<3>(ord22, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, false, b), false);
      std::vector<u16> ord23({0, 1, 2});
    
    r->addIndex<3>(ord23, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, true, b), false);
      std::vector<u16> ord24({1, 2, 0});
    
    r->addIndex<3>(ord24, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("st_msk"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("st_mem_ans");
  if (r == 0) db->addRelation("st_mem_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_mem_ans");
      std::vector<u16> ord25({0, 1});
    
    r->addIndex<2>(ord25, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("st_mem_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("st_mem0_ans");
  if (r == 0) db->addRelation("st_mem0_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_mem0_ans");
      std::vector<u16> ord26({0, 1});
    
    r->addIndex<2>(ord26, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
      std::vector<u16> ord27({1, 0});
    
    r->addIndex<2>(ord27, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), false);
      std::vector<u16> ord28({1, 0});
    
    r->addIndex<2>(ord28, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("st_mem0_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("st_mem0");
  if (r == 0) db->addStruct("st_mem0", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_mem0");
      std::vector<u16> ord29({1, 2, 0});
    
    r->addIndex<3>(ord29, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord30({0, 1, 2});
    
    r->addIndex<3>(ord30, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
      std::vector<u16> ord31({2, 0, 1});
    
    r->addIndex<3>(ord31, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, false, b), false);
      std::vector<u16> ord32({0, 1, 2});
    
    r->addIndex<3>(ord32, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, true, b), false);
      std::vector<u16> ord33({1, 2, 0});
    
    r->addIndex<3>(ord33, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, true, b), false);
      std::vector<u16> ord34({2, 0, 1});
    
    r->addIndex<3>(ord34, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("st_mem0"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("st_mem");
  if (r == 0) db->addStruct("st_mem", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_mem");
      std::vector<u16> ord35({1, 2, 0});
    
    r->addIndex<3>(ord35, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord36({0, 1, 2});
    
    r->addIndex<3>(ord36, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("st_mem"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("st_join_ans");
  if (r == 0) db->addRelation("st_join_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_join_ans");
      std::vector<u16> ord37({0, 1});
    
    r->addIndex<2>(ord37, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("st_join_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("st_join");
  if (r == 0) db->addStruct("st_join", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_join");
      std::vector<u16> ord38({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord38, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord39({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord39, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
      std::vector<u16> ord40({1, 4, 3, 0, 2});
    
    r->addIndex<5>(ord40, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 4, 3, 0, 2}, false, b), false);
      std::vector<u16> ord41({2, 4, 0, 1, 3});
    
    r->addIndex<5>(ord41, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{2, 4, 0, 1, 3}, false, b), false);
      std::vector<u16> ord42({3, 4, 0, 1, 2});
    
    r->addIndex<5>(ord42, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{3, 4, 0, 1, 2}, false, b), false);
      std::vector<u16> ord43({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord43, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, true, b), false);
      std::vector<u16> ord44({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord44, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, true, b), false);
      std::vector<u16> ord45({1, 4, 3, 0, 2});
    
    r->addIndex<5>(ord45, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 4, 3, 0, 2}, true, b), false);
      std::vector<u16> ord46({2, 4, 0, 1, 3});
    
    r->addIndex<5>(ord46, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{2, 4, 0, 1, 3}, true, b), false);
      std::vector<u16> ord47({3, 4, 0, 1, 2});
    
    r->addIndex<5>(ord47, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{3, 4, 0, 1, 2}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("st_join"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("st_ins_ans");
  if (r == 0) db->addRelation("st_ins_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_ins_ans");
      std::vector<u16> ord48({0, 1});
    
    r->addIndex<2>(ord48, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
      std::vector<u16> ord49({1, 0});
    
    r->addIndex<2>(ord49, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), false);
      std::vector<u16> ord50({0, 1});
    
    r->addIndex<2>(ord50, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("st_ins_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("st_ins");
  if (r == 0) db->addStruct("st_ins", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_ins");
      std::vector<u16> ord51({1, 2, 0});
    
    r->addIndex<3>(ord51, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord52({0, 2, 1});
    
    r->addIndex<3>(ord52, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 2, 1}, false, b), false);
      std::vector<u16> ord53({2, 0, 1});
    
    r->addIndex<3>(ord53, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, false, b), false);
      std::vector<u16> ord54({0, 2, 1});
    
    r->addIndex<3>(ord54, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 2, 1}, true, b), false);
      std::vector<u16> ord55({1, 2, 0});
    
    r->addIndex<3>(ord55, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, true, b), false);
      std::vector<u16> ord56({2, 0, 1});
    
    r->addIndex<3>(ord56, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("st_ins"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("st_hsb_ans");
  if (r == 0) db->addRelation("st_hsb_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_hsb_ans");
      std::vector<u16> ord57({0, 1});
    
    r->addIndex<2>(ord57, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
      std::vector<u16> ord58({1, 0});
    
    r->addIndex<2>(ord58, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), false);
      std::vector<u16> ord59({0, 1});
    
    r->addIndex<2>(ord59, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, true, b), false);
      std::vector<u16> ord60({1, 0});
    
    r->addIndex<2>(ord60, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("st_hsb_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("st_hsb");
  if (r == 0) db->addStruct("st_hsb", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_hsb");
      std::vector<u16> ord61({1, 0});
    
    r->addIndex<2>(ord61, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord62({0, 1});
    
    r->addIndex<2>(ord62, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord63({0, 1});
    
    r->addIndex<2>(ord63, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, true, b), false);
      std::vector<u16> ord64({1, 0});
    
    r->addIndex<2>(ord64, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("st_hsb"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("st_fromlist_ans");
  if (r == 0) db->addRelation("st_fromlist_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_fromlist_ans");
      std::vector<u16> ord65({0, 1});
    
    r->addIndex<2>(ord65, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
      std::vector<u16> ord66({1, 0});
    
    r->addIndex<2>(ord66, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("st_fromlist_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("st_fromlist");
  if (r == 0) db->addStruct("st_fromlist", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_fromlist");
      std::vector<u16> ord67({1, 0});
    
    r->addIndex<2>(ord67, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord68({0, 1});
    
    r->addIndex<2>(ord68, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("st_fromlist"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("st_diff_ans");
  if (r == 0) db->addRelation("st_diff_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_diff_ans");
      std::vector<u16> ord69({0, 1});
    
    r->addIndex<2>(ord69, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
      std::vector<u16> ord70({1, 0});
    
    r->addIndex<2>(ord70, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), false);
      std::vector<u16> ord71({0, 1});
    
    r->addIndex<2>(ord71, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("st_diff_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("st_diff");
  if (r == 0) db->addStruct("st_diff", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_diff");
      std::vector<u16> ord72({1, 2, 0});
    
    r->addIndex<3>(ord72, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord73({0, 1, 2});
    
    r->addIndex<3>(ord73, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
      std::vector<u16> ord74({2, 0, 1});
    
    r->addIndex<3>(ord74, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, false, b), false);
      std::vector<u16> ord75({0, 1, 2});
    
    r->addIndex<3>(ord75, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, true, b), false);
      std::vector<u16> ord76({1, 2, 0});
    
    r->addIndex<3>(ord76, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, true, b), false);
      std::vector<u16> ord77({2, 0, 1});
    
    r->addIndex<3>(ord77, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("st_diff"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("st_del_ans");
  if (r == 0) db->addRelation("st_del_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_del_ans");
      std::vector<u16> ord78({0, 1});
    
    r->addIndex<2>(ord78, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
      std::vector<u16> ord79({1, 0});
    
    r->addIndex<2>(ord79, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), false);
      std::vector<u16> ord80({0, 1});
    
    r->addIndex<2>(ord80, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("st_del_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("st_del");
  if (r == 0) db->addStruct("st_del", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_del");
      std::vector<u16> ord81({1, 2, 0});
    
    r->addIndex<3>(ord81, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord82({0, 2, 1});
    
    r->addIndex<3>(ord82, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 2, 1}, false, b), false);
      std::vector<u16> ord83({2, 0, 1});
    
    r->addIndex<3>(ord83, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, false, b), false);
      std::vector<u16> ord84({0, 2, 1});
    
    r->addIndex<3>(ord84, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 2, 1}, true, b), false);
      std::vector<u16> ord85({1, 2, 0});
    
    r->addIndex<3>(ord85, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("st_del"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("st_bld_ans");
  if (r == 0) db->addRelation("st_bld_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_bld_ans");
      std::vector<u16> ord86({0, 1});
    
    r->addIndex<2>(ord86, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("st_bld_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("st_bld");
  if (r == 0) db->addStruct("st_bld", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("st_bld");
      std::vector<u16> ord87({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord87, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord88({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord88, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
      std::vector<u16> ord89({2, 1, 4, 0, 3});
    
    r->addIndex<5>(ord89, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{2, 1, 4, 0, 3}, false, b), false);
      std::vector<u16> ord90({3, 0, 1, 2, 4});
    
    r->addIndex<5>(ord90, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{3, 0, 1, 2, 4}, false, b), false);
      std::vector<u16> ord91({4, 0, 1, 2, 3});
    
    r->addIndex<5>(ord91, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{4, 0, 1, 2, 3}, false, b), false);
      std::vector<u16> ord92({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord92, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, true, b), false);
      std::vector<u16> ord93({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord93, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, true, b), false);
      std::vector<u16> ord94({2, 1, 4, 0, 3});
    
    r->addIndex<5>(ord94, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{2, 1, 4, 0, 3}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("st_bld"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord95({1, 2, 0});
    
    r->addIndex<3>(ord95, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord96({0, 1, 2});
    
    r->addIndex<3>(ord96, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("pleaf");
  if (r == 0) db->addStruct("pleaf", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("pleaf");
      std::vector<u16> ord97({1, 0});
    
    r->addIndex<2>(ord97, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord98({0, 1});
    
    r->addIndex<2>(ord98, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord99({0, 1});
    
    r->addIndex<2>(ord99, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, true, b), false);
      std::vector<u16> ord100({1, 0});
    
    r->addIndex<2>(ord100, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("pleaf"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("pbranch");
  if (r == 0) db->addStruct("pbranch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("pbranch");
      std::vector<u16> ord101({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord101, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord102({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord102, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
      std::vector<u16> ord103({1, 2, 4, 0, 3});
    
    r->addIndex<5>(ord103, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 4, 0, 3}, false, b), false);
      std::vector<u16> ord104({2, 0, 1, 3, 4});
    
    r->addIndex<5>(ord104, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{2, 0, 1, 3, 4}, false, b), false);
      std::vector<u16> ord105({3, 0, 1, 2, 4});
    
    r->addIndex<5>(ord105, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{3, 0, 1, 2, 4}, false, b), false);
      std::vector<u16> ord106({4, 0, 1, 2, 3});
    
    r->addIndex<5>(ord106, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{4, 0, 1, 2, 3}, false, b), false);
      std::vector<u16> ord107({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord107, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, true, b), false);
      std::vector<u16> ord108({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord108, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, true, b), false);
      std::vector<u16> ord109({1, 2, 4, 0, 3});
    
    r->addIndex<5>(ord109, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 4, 0, 3}, true, b), false);
      std::vector<u16> ord110({2, 0, 1, 3, 4});
    
    r->addIndex<5>(ord110, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{2, 0, 1, 3, 4}, true, b), false);
      std::vector<u16> ord111({3, 0, 1, 2, 4});
    
    r->addIndex<5>(ord111, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{3, 0, 1, 2, 4}, true, b), false);
      std::vector<u16> ord112({4, 0, 1, 2, 3});
    
    r->addIndex<5>(ord112, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{4, 0, 1, 2, 3}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("pbranch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord113({1, 2, 3, 0});
    
    r->addIndex<4>(ord113, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord114({0, 1, 2, 3});
    
    r->addIndex<4>(ord114, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord115({1, 2, 0});
    
    r->addIndex<3>(ord115, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord116({0, 1, 2});
    
    r->addIndex<3>(ord116, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord117({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord117, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord118({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord118, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord119({1, 2, 0});
    
    r->addIndex<3>(ord119, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord120({0, 1, 2});
    
    r->addIndex<3>(ord120, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord121({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord121, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord122({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord122, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("m");
  if (r == 0) db->addRelation("m", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("m");
      std::vector<u16> ord123({0, 1});
    
    r->addIndex<2>(ord123, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("m"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord124({1, 2, 3, 0});
    
    r->addIndex<4>(ord124, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord125({0, 1, 2, 3});
    
    r->addIndex<4>(ord125, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord126({0});
    
    r->addIndex<1>(ord126, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord127({1, 2, 0});
    
    r->addIndex<3>(ord127, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord128({0, 1, 2});
    
    r->addIndex<3>(ord128, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("dif");
  if (r == 0) db->addRelation("dif", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("dif");
      std::vector<u16> ord129({0});
    
    r->addIndex<1>(ord129, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("dif"), std::array<u16,1>{0}, b));
  r = db->getRelation("canon");
  if (r == 0) db->addRelation("canon", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("canon");
      std::vector<u16> ord130({0});
    
    r->addIndex<1>(ord130, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("canon"), std::array<u16,1>{0}, b));
  r = db->getRelation("afterdel");
  if (r == 0) db->addRelation("afterdel", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("afterdel");
      std::vector<u16> ord131({0});
    
    r->addIndex<1>(ord131, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("afterdel"), std::array<u16,1>{0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord132({1, 0});
    
    r->addIndex<2>(ord132, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord133({0, 1});
    
    r->addIndex<2>(ord133, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord134({1, 0});
    
    r->addIndex<2>(ord134, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("$sup97714x23x0x0x1");
  if (r == 0) db->addRelation("$sup97714x23x0x0x1", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup97714x23x0x0x1");
      std::vector<u16> ord135({1, 0, 2});
    
    r->addIndex<3>(ord135, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 0, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$sup97714x23x0x0x1"), std::array<u16,3>{1, 0, 2}, b));
  r = db->getRelation("$sup9688x90x0x0x0");
  if (r == 0) db->addRelation("$sup9688x90x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x90x0x0x0");
      std::vector<u16> ord136({4, 2, 3, 5, 0, 1});
    
    r->addIndex<6>(ord136, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{4, 2, 3, 5, 0, 1}, false, b), true);
      std::vector<u16> ord137({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord137, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), false);
      std::vector<u16> ord138({1, 3, 4, 0, 2, 5});
    
    r->addIndex<6>(ord138, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{1, 3, 4, 0, 2, 5}, false, b), false);
      std::vector<u16> ord139({1, 5, 0, 2, 3, 4});
    
    r->addIndex<6>(ord139, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{1, 5, 0, 2, 3, 4}, false, b), false);
      std::vector<u16> ord140({1, 3, 4, 0, 2, 5});
    
    r->addIndex<6>(ord140, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{1, 3, 4, 0, 2, 5}, true, b), false);
      std::vector<u16> ord141({1, 5, 0, 2, 3, 4});
    
    r->addIndex<6>(ord141, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{1, 5, 0, 2, 3, 4}, true, b), false);
      std::vector<u16> ord142({4, 2, 3, 5, 0, 1});
    
    r->addIndex<6>(ord142, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{4, 2, 3, 5, 0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup9688x90x0x0x0"), std::array<u16,6>{4, 2, 3, 5, 0, 1}, b));
  r = db->getRelation("$sup9688x88x0x0x0");
  if (r == 0) db->addRelation("$sup9688x88x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x88x0x0x0");
      std::vector<u16> ord143({4, 3, 5, 2, 0, 1});
    
    r->addIndex<6>(ord143, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{4, 3, 5, 2, 0, 1}, false, b), true);
      std::vector<u16> ord144({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord144, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), false);
      std::vector<u16> ord145({1, 2, 0, 3, 4, 5});
    
    r->addIndex<6>(ord145, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{1, 2, 0, 3, 4, 5}, false, b), false);
      std::vector<u16> ord146({1, 3, 4, 0, 2, 5});
    
    r->addIndex<6>(ord146, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{1, 3, 4, 0, 2, 5}, false, b), false);
      std::vector<u16> ord147({1, 2, 0, 3, 4, 5});
    
    r->addIndex<6>(ord147, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{1, 2, 0, 3, 4, 5}, true, b), false);
      std::vector<u16> ord148({1, 3, 4, 0, 2, 5});
    
    r->addIndex<6>(ord148, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{1, 3, 4, 0, 2, 5}, true, b), false);
      std::vector<u16> ord149({4, 3, 5, 2, 0, 1});
    
    r->addIndex<6>(ord149, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{4, 3, 5, 2, 0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup9688x88x0x0x0"), std::array<u16,6>{4, 3, 5, 2, 0, 1}, b));
  r = db->getRelation("$sup9688x87x0x0x0");
  if (r == 0) db->addRelation("$sup9688x87x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x87x0x0x0");
      std::vector<u16> ord150({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord150, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
      std::vector<u16> ord151({1, 3, 0, 2, 4, 5});
    
    r->addIndex<6>(ord151, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{1, 3, 0, 2, 4, 5}, false, b), false);
      std::vector<u16> ord152({2, 3, 4, 5, 0, 1});
    
    r->addIndex<6>(ord152, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{2, 3, 4, 5, 0, 1}, false, b), false);
      std::vector<u16> ord153({1, 3, 0, 2, 4, 5});
    
    r->addIndex<6>(ord153, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{1, 3, 0, 2, 4, 5}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup9688x87x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup9688x72x0x0x0");
  if (r == 0) db->addRelation("$sup9688x72x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x72x0x0x0");
      std::vector<u16> ord154({4, 2, 3, 5, 0, 1});
    
    r->addIndex<6>(ord154, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{4, 2, 3, 5, 0, 1}, false, b), true);
      std::vector<u16> ord155({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord155, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), false);
      std::vector<u16> ord156({1, 3, 4, 0, 2, 5});
    
    r->addIndex<6>(ord156, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{1, 3, 4, 0, 2, 5}, false, b), false);
      std::vector<u16> ord157({1, 5, 0, 2, 3, 4});
    
    r->addIndex<6>(ord157, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{1, 5, 0, 2, 3, 4}, false, b), false);
      std::vector<u16> ord158({1, 3, 4, 0, 2, 5});
    
    r->addIndex<6>(ord158, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{1, 3, 4, 0, 2, 5}, true, b), false);
      std::vector<u16> ord159({1, 5, 0, 2, 3, 4});
    
    r->addIndex<6>(ord159, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{1, 5, 0, 2, 3, 4}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup9688x72x0x0x0"), std::array<u16,6>{4, 2, 3, 5, 0, 1}, b));
  r = db->getRelation("$sup9688x70x0x0x0");
  if (r == 0) db->addRelation("$sup9688x70x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x70x0x0x0");
      std::vector<u16> ord160({4, 2, 3, 5, 0, 1});
    
    r->addIndex<6>(ord160, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{4, 2, 3, 5, 0, 1}, false, b), true);
      std::vector<u16> ord161({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord161, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), false);
      std::vector<u16> ord162({1, 2, 0, 3, 4, 5});
    
    r->addIndex<6>(ord162, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{1, 2, 0, 3, 4, 5}, false, b), false);
      std::vector<u16> ord163({1, 3, 4, 0, 2, 5});
    
    r->addIndex<6>(ord163, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{1, 3, 4, 0, 2, 5}, false, b), false);
      std::vector<u16> ord164({1, 2, 0, 3, 4, 5});
    
    r->addIndex<6>(ord164, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{1, 2, 0, 3, 4, 5}, true, b), false);
      std::vector<u16> ord165({1, 3, 4, 0, 2, 5});
    
    r->addIndex<6>(ord165, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{1, 3, 4, 0, 2, 5}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup9688x70x0x0x0"), std::array<u16,6>{4, 2, 3, 5, 0, 1}, b));
  r = db->getRelation("$sup9688x69x0x0x0");
  if (r == 0) db->addRelation("$sup9688x69x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x69x0x0x0");
      std::vector<u16> ord166({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord166, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
      std::vector<u16> ord167({1, 3, 0, 2, 4, 5});
    
    r->addIndex<6>(ord167, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{1, 3, 0, 2, 4, 5}, false, b), false);
      std::vector<u16> ord168({2, 3, 4, 5, 0, 1});
    
    r->addIndex<6>(ord168, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{2, 3, 4, 5, 0, 1}, false, b), false);
      std::vector<u16> ord169({1, 3, 0, 2, 4, 5});
    
    r->addIndex<6>(ord169, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{1, 3, 0, 2, 4, 5}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup9688x69x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup9688x62x0x0x0");
  if (r == 0) db->addRelation("$sup9688x62x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x62x0x0x0");
      std::vector<u16> ord170({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord170, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup9688x62x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup9688x61x0x0x0");
  if (r == 0) db->addRelation("$sup9688x61x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x61x0x0x0");
      std::vector<u16> ord171({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord171, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup9688x61x0x0x0"), std::array<u16,6>{0, 1, 2, 3, 4, 5}, b));
  r = db->getRelation("$sup9688x54x0x0x0");
  if (r == 0) db->addRelation("$sup9688x54x0x0x0", 7);
  else if (r->getArity() != 7)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x54x0x0x0");
      std::vector<u16> ord172({1, 3, 0, 2, 4, 5, 6});
    
    r->addIndex<7>(ord172, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{1, 3, 0, 2, 4, 5, 6}, false, b), true);
      std::vector<u16> ord173({0, 1, 6, 4, 2, 3, 5});
    
    r->addIndex<7>(ord173, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{0, 1, 6, 4, 2, 3, 5}, false, b), false);
      std::vector<u16> ord174({1, 4, 6, 3, 0, 2, 5});
    
    r->addIndex<7>(ord174, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{1, 4, 6, 3, 0, 2, 5}, false, b), false);
      std::vector<u16> ord175({2, 3, 4, 5, 6, 0, 1});
    
    r->addIndex<7>(ord175, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{2, 3, 4, 5, 6, 0, 1}, false, b), false);
      std::vector<u16> ord176({0, 1, 6, 4, 2, 3, 5});
    
    r->addIndex<7>(ord176, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{0, 1, 6, 4, 2, 3, 5}, true, b), false);
      std::vector<u16> ord177({1, 4, 6, 3, 0, 2, 5});
    
    r->addIndex<7>(ord177, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{1, 4, 6, 3, 0, 2, 5}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<7>(db, db->getRelation("$sup9688x54x0x0x0"), std::array<u16,7>{1, 3, 0, 2, 4, 5, 6}, b));
  r = db->getRelation("$sup9688x52x0x0x1");
  if (r == 0) db->addRelation("$sup9688x52x0x0x1", 7);
  else if (r->getArity() != 7)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x52x0x0x1");
      std::vector<u16> ord178({0, 2, 1, 3, 4, 5, 6});
    
    r->addIndex<7>(ord178, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{0, 2, 1, 3, 4, 5, 6}, false, b), true);
      std::vector<u16> ord179({1, 2, 4, 5, 0, 3, 6});
    
    r->addIndex<7>(ord179, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{1, 2, 4, 5, 0, 3, 6}, false, b), false);
      std::vector<u16> ord180({1, 5, 0, 2, 3, 4, 6});
    
    r->addIndex<7>(ord180, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{1, 5, 0, 2, 3, 4, 6}, false, b), false);
      std::vector<u16> ord181({2, 6, 0, 1, 3, 4, 5});
    
    r->addIndex<7>(ord181, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{2, 6, 0, 1, 3, 4, 5}, false, b), false);
      std::vector<u16> ord182({3, 4, 5, 6, 0, 2, 1});
    
    r->addIndex<7>(ord182, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{3, 4, 5, 6, 0, 2, 1}, false, b), false);
      std::vector<u16> ord183({1, 2, 4, 5, 0, 3, 6});
    
    r->addIndex<7>(ord183, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{1, 2, 4, 5, 0, 3, 6}, true, b), false);
      std::vector<u16> ord184({3, 4, 5, 6, 0, 2, 1});
    
    r->addIndex<7>(ord184, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{3, 4, 5, 6, 0, 2, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<7>(db, db->getRelation("$sup9688x52x0x0x1"), std::array<u16,7>{0, 2, 1, 3, 4, 5, 6}, b));
  r = db->getRelation("$sup9688x52x0x0x0");
  if (r == 0) db->addRelation("$sup9688x52x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x52x0x0x0");
      std::vector<u16> ord185({4, 2, 3, 5, 0, 1});
    
    r->addIndex<6>(ord185, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{4, 2, 3, 5, 0, 1}, false, b), true);
      std::vector<u16> ord186({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord186, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), false);
      std::vector<u16> ord187({1, 3, 4, 0, 2, 5});
    
    r->addIndex<6>(ord187, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{1, 3, 4, 0, 2, 5}, false, b), false);
      std::vector<u16> ord188({1, 5, 0, 2, 3, 4});
    
    r->addIndex<6>(ord188, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{1, 5, 0, 2, 3, 4}, false, b), false);
      std::vector<u16> ord189({1, 5, 0, 2, 3, 4});
    
    r->addIndex<6>(ord189, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{1, 5, 0, 2, 3, 4}, true, b), false);
      std::vector<u16> ord190({4, 2, 3, 5, 0, 1});
    
    r->addIndex<6>(ord190, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{4, 2, 3, 5, 0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup9688x52x0x0x0"), std::array<u16,6>{4, 2, 3, 5, 0, 1}, b));
  r = db->getRelation("$sup9688x50x0x0x1");
  if (r == 0) db->addRelation("$sup9688x50x0x0x1", 7);
  else if (r->getArity() != 7)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x50x0x0x1");
      std::vector<u16> ord191({0, 2, 1, 3, 4, 5, 6});
    
    r->addIndex<7>(ord191, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{0, 2, 1, 3, 4, 5, 6}, false, b), true);
      std::vector<u16> ord192({1, 2, 4, 5, 0, 3, 6});
    
    r->addIndex<7>(ord192, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{1, 2, 4, 5, 0, 3, 6}, false, b), false);
      std::vector<u16> ord193({1, 5, 0, 2, 3, 4, 6});
    
    r->addIndex<7>(ord193, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{1, 5, 0, 2, 3, 4, 6}, false, b), false);
      std::vector<u16> ord194({2, 3, 0, 1, 4, 5, 6});
    
    r->addIndex<7>(ord194, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{2, 3, 0, 1, 4, 5, 6}, false, b), false);
      std::vector<u16> ord195({3, 4, 5, 6, 0, 2, 1});
    
    r->addIndex<7>(ord195, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{3, 4, 5, 6, 0, 2, 1}, false, b), false);
      std::vector<u16> ord196({1, 2, 4, 5, 0, 3, 6});
    
    r->addIndex<7>(ord196, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{1, 2, 4, 5, 0, 3, 6}, true, b), false);
      std::vector<u16> ord197({3, 4, 5, 6, 0, 2, 1});
    
    r->addIndex<7>(ord197, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{3, 4, 5, 6, 0, 2, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<7>(db, db->getRelation("$sup9688x50x0x0x1"), std::array<u16,7>{0, 2, 1, 3, 4, 5, 6}, b));
  r = db->getRelation("$sup9688x50x0x0x0");
  if (r == 0) db->addRelation("$sup9688x50x0x0x0", 6);
  else if (r->getArity() != 6)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x50x0x0x0");
      std::vector<u16> ord198({4, 2, 3, 5, 0, 1});
    
    r->addIndex<6>(ord198, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{4, 2, 3, 5, 0, 1}, false, b), true);
      std::vector<u16> ord199({0, 1, 2, 3, 4, 5});
    
    r->addIndex<6>(ord199, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{0, 1, 2, 3, 4, 5}, false, b), false);
      std::vector<u16> ord200({1, 2, 0, 3, 4, 5});
    
    r->addIndex<6>(ord200, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{1, 2, 0, 3, 4, 5}, false, b), false);
      std::vector<u16> ord201({1, 3, 4, 0, 2, 5});
    
    r->addIndex<6>(ord201, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{1, 3, 4, 0, 2, 5}, false, b), false);
      std::vector<u16> ord202({1, 2, 0, 3, 4, 5});
    
    r->addIndex<6>(ord202, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{1, 2, 0, 3, 4, 5}, true, b), false);
      std::vector<u16> ord203({4, 2, 3, 5, 0, 1});
    
    r->addIndex<6>(ord203, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<6>(db, r, std::array<u16,6>{4, 2, 3, 5, 0, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<6>(db, db->getRelation("$sup9688x50x0x0x0"), std::array<u16,6>{4, 2, 3, 5, 0, 1}, b));
  r = db->getRelation("$sup9688x40x0x0x2");
  if (r == 0) db->addRelation("$sup9688x40x0x0x2", 11);
  else if (r->getArity() != 11)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x40x0x0x2");
      std::vector<u16> ord204({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
    
    r->addIndex<11>(ord204, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10}, false, b), true);
      std::vector<u16> ord205({0, 7, 8, 9, 10, 1, 4, 2, 3, 5, 6});
    
    r->addIndex<11>(ord205, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{0, 7, 8, 9, 10, 1, 4, 2, 3, 5, 6}, false, b), false);
      std::vector<u16> ord206({1, 5, 6, 7, 0, 2, 3, 4, 8, 9, 10});
    
    r->addIndex<11>(ord206, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{1, 5, 6, 7, 0, 2, 3, 4, 8, 9, 10}, false, b), false);
      std::vector<u16> ord207({1, 6, 0, 2, 3, 4, 5, 7, 8, 9, 10});
    
    r->addIndex<11>(ord207, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{1, 6, 0, 2, 3, 4, 5, 7, 8, 9, 10}, false, b), false);
      std::vector<u16> ord208({5, 7, 1, 0, 2, 3, 4, 6, 8, 9, 10});
    
    r->addIndex<11>(ord208, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{5, 7, 1, 0, 2, 3, 4, 6, 8, 9, 10}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<11>(db, db->getRelation("$sup9688x40x0x0x2"), std::array<u16,11>{1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10}, b));
  r = db->getRelation("$sup9688x40x0x0x1");
  if (r == 0) db->addRelation("$sup9688x40x0x0x1", 7);
  else if (r->getArity() != 7)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x40x0x0x1");
      std::vector<u16> ord209({1, 2, 0, 3, 4, 5, 6});
    
    r->addIndex<7>(ord209, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{1, 2, 0, 3, 4, 5, 6}, false, b), true);
      std::vector<u16> ord210({0, 3, 4, 5, 6, 1, 2});
    
    r->addIndex<7>(ord210, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{0, 3, 4, 5, 6, 1, 2}, false, b), false);
      std::vector<u16> ord211({3, 1, 0, 2, 4, 5, 6});
    
    r->addIndex<7>(ord211, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{3, 1, 0, 2, 4, 5, 6}, false, b), false);
      std::vector<u16> ord212({0, 3, 4, 5, 6, 1, 2});
    
    r->addIndex<7>(ord212, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{0, 3, 4, 5, 6, 1, 2}, true, b), false);
      std::vector<u16> ord213({1, 2, 0, 3, 4, 5, 6});
    
    r->addIndex<7>(ord213, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{1, 2, 0, 3, 4, 5, 6}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<7>(db, db->getRelation("$sup9688x40x0x0x1"), std::array<u16,7>{1, 2, 0, 3, 4, 5, 6}, b));
  r = db->getRelation("$sup9688x40x0x0x0");
  if (r == 0) db->addRelation("$sup9688x40x0x0x0", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x40x0x0x0");
      std::vector<u16> ord214({1, 0, 2, 3, 4});
    
    r->addIndex<5>(ord214, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 0, 2, 3, 4}, false, b), true);
      std::vector<u16> ord215({1, 0, 2, 3, 4});
    
    r->addIndex<5>(ord215, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 0, 2, 3, 4}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<5>(db, db->getRelation("$sup9688x40x0x0x0"), std::array<u16,5>{1, 0, 2, 3, 4}, b));
  r = db->getRelation("$sup9688x36x0x0x2");
  if (r == 0) db->addRelation("$sup9688x36x0x0x2", 11);
  else if (r->getArity() != 11)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x36x0x0x2");
      std::vector<u16> ord216({1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10});
    
    r->addIndex<11>(ord216, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10}, false, b), true);
      std::vector<u16> ord217({0, 7, 8, 9, 10, 1, 4, 2, 3, 5, 6});
    
    r->addIndex<11>(ord217, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{0, 7, 8, 9, 10, 1, 4, 2, 3, 5, 6}, false, b), false);
      std::vector<u16> ord218({1, 5, 6, 7, 0, 2, 3, 4, 8, 9, 10});
    
    r->addIndex<11>(ord218, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{1, 5, 6, 7, 0, 2, 3, 4, 8, 9, 10}, false, b), false);
      std::vector<u16> ord219({1, 6, 0, 2, 3, 4, 5, 7, 8, 9, 10});
    
    r->addIndex<11>(ord219, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{1, 6, 0, 2, 3, 4, 5, 7, 8, 9, 10}, false, b), false);
      std::vector<u16> ord220({5, 7, 1, 0, 2, 3, 4, 6, 8, 9, 10});
    
    r->addIndex<11>(ord220, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{5, 7, 1, 0, 2, 3, 4, 6, 8, 9, 10}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<11>(db, db->getRelation("$sup9688x36x0x0x2"), std::array<u16,11>{1, 4, 6, 5, 0, 2, 3, 7, 8, 9, 10}, b));
  r = db->getRelation("$sup9688x36x0x0x1");
  if (r == 0) db->addRelation("$sup9688x36x0x0x1", 7);
  else if (r->getArity() != 7)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x36x0x0x1");
      std::vector<u16> ord221({1, 2, 0, 3, 4, 5, 6});
    
    r->addIndex<7>(ord221, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{1, 2, 0, 3, 4, 5, 6}, false, b), true);
      std::vector<u16> ord222({0, 3, 4, 5, 6, 1, 2});
    
    r->addIndex<7>(ord222, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{0, 3, 4, 5, 6, 1, 2}, false, b), false);
      std::vector<u16> ord223({3, 1, 0, 2, 4, 5, 6});
    
    r->addIndex<7>(ord223, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{3, 1, 0, 2, 4, 5, 6}, false, b), false);
      std::vector<u16> ord224({0, 3, 4, 5, 6, 1, 2});
    
    r->addIndex<7>(ord224, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{0, 3, 4, 5, 6, 1, 2}, true, b), false);
      std::vector<u16> ord225({1, 2, 0, 3, 4, 5, 6});
    
    r->addIndex<7>(ord225, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{1, 2, 0, 3, 4, 5, 6}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<7>(db, db->getRelation("$sup9688x36x0x0x1"), std::array<u16,7>{1, 2, 0, 3, 4, 5, 6}, b));
  r = db->getRelation("$sup9688x36x0x0x0");
  if (r == 0) db->addRelation("$sup9688x36x0x0x0", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x36x0x0x0");
      std::vector<u16> ord226({1, 0, 2, 3, 4});
    
    r->addIndex<5>(ord226, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 0, 2, 3, 4}, false, b), true);
      std::vector<u16> ord227({1, 0, 2, 3, 4});
    
    r->addIndex<5>(ord227, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 0, 2, 3, 4}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<5>(db, db->getRelation("$sup9688x36x0x0x0"), std::array<u16,5>{1, 0, 2, 3, 4}, b));
  r = db->getRelation("$sup9688x168x0x0x0");
  if (r == 0) db->addRelation("$sup9688x168x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x168x0x0x0");
      std::vector<u16> ord228({2, 3, 0, 1});
    
    r->addIndex<4>(ord228, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{2, 3, 0, 1}, false, b), true);
      std::vector<u16> ord229({3, 0, 1, 2});
    
    r->addIndex<4>(ord229, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{3, 0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup9688x168x0x0x0"), std::array<u16,4>{2, 3, 0, 1}, b));
  r = db->getRelation("$sup9688x164x0x0x0");
  if (r == 0) db->addRelation("$sup9688x164x0x0x0", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x164x0x0x0");
      std::vector<u16> ord230({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord230, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<5>(db, db->getRelation("$sup9688x164x0x0x0"), std::array<u16,5>{0, 1, 2, 3, 4}, b));
  r = db->getRelation("$sup9688x154x0x0x0");
  if (r == 0) db->addRelation("$sup9688x154x0x0x0", 9);
  else if (r->getArity() != 9)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x154x0x0x0");
      std::vector<u16> ord231({0, 1, 2, 3, 4, 5, 6, 7, 8});
    
    r->addIndex<9>(ord231, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, false, b), true);
      std::vector<u16> ord232({1, 2, 4, 6, 0, 3, 5, 7, 8});
    
    r->addIndex<9>(ord232, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{1, 2, 4, 6, 0, 3, 5, 7, 8}, false, b), false);
      std::vector<u16> ord233({3, 4, 0, 1, 2, 5, 6, 7, 8});
    
    r->addIndex<9>(ord233, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{3, 4, 0, 1, 2, 5, 6, 7, 8}, false, b), false);
      std::vector<u16> ord234({3, 5, 7, 8, 0, 1, 2, 4, 6});
    
    r->addIndex<9>(ord234, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{3, 5, 7, 8, 0, 1, 2, 4, 6}, false, b), false);
      std::vector<u16> ord235({3, 4, 0, 1, 2, 5, 6, 7, 8});
    
    r->addIndex<9>(ord235, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{3, 4, 0, 1, 2, 5, 6, 7, 8}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<9>(db, db->getRelation("$sup9688x154x0x0x0"), std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, b));
  r = db->getRelation("$sup9688x151x0x0x0");
  if (r == 0) db->addRelation("$sup9688x151x0x0x0", 9);
  else if (r->getArity() != 9)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x151x0x0x0");
      std::vector<u16> ord236({0, 8, 1, 2, 3, 4, 5, 6, 7});
    
    r->addIndex<9>(ord236, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{0, 8, 1, 2, 3, 4, 5, 6, 7}, false, b), true);
      std::vector<u16> ord237({1, 2, 4, 6, 0, 3, 5, 7, 8});
    
    r->addIndex<9>(ord237, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{1, 2, 4, 6, 0, 3, 5, 7, 8}, false, b), false);
      std::vector<u16> ord238({3, 4, 5, 0, 1, 2, 6, 7, 8});
    
    r->addIndex<9>(ord238, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{3, 4, 5, 0, 1, 2, 6, 7, 8}, false, b), false);
      std::vector<u16> ord239({5, 3, 7, 8, 0, 1, 2, 4, 6});
    
    r->addIndex<9>(ord239, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{5, 3, 7, 8, 0, 1, 2, 4, 6}, false, b), false);
      std::vector<u16> ord240({8, 0, 1, 2, 3, 4, 5, 6, 7});
    
    r->addIndex<9>(ord240, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{8, 0, 1, 2, 3, 4, 5, 6, 7}, false, b), false);
      std::vector<u16> ord241({3, 4, 5, 0, 1, 2, 6, 7, 8});
    
    r->addIndex<9>(ord241, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{3, 4, 5, 0, 1, 2, 6, 7, 8}, true, b), false);
      std::vector<u16> ord242({5, 3, 7, 8, 0, 1, 2, 4, 6});
    
    r->addIndex<9>(ord242, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{5, 3, 7, 8, 0, 1, 2, 4, 6}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<9>(db, db->getRelation("$sup9688x151x0x0x0"), std::array<u16,9>{0, 8, 1, 2, 3, 4, 5, 6, 7}, b));
  r = db->getRelation("$sup9688x148x0x0x0");
  if (r == 0) db->addRelation("$sup9688x148x0x0x0", 9);
  else if (r->getArity() != 9)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x148x0x0x0");
      std::vector<u16> ord243({0, 7, 1, 2, 3, 4, 5, 6, 8});
    
    r->addIndex<9>(ord243, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{0, 7, 1, 2, 3, 4, 5, 6, 8}, false, b), true);
      std::vector<u16> ord244({1, 2, 4, 6, 0, 3, 5, 7, 8});
    
    r->addIndex<9>(ord244, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{1, 2, 4, 6, 0, 3, 5, 7, 8}, false, b), false);
      std::vector<u16> ord245({3, 4, 5, 0, 1, 2, 6, 7, 8});
    
    r->addIndex<9>(ord245, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{3, 4, 5, 0, 1, 2, 6, 7, 8}, false, b), false);
      std::vector<u16> ord246({5, 3, 7, 8, 0, 1, 2, 4, 6});
    
    r->addIndex<9>(ord246, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{5, 3, 7, 8, 0, 1, 2, 4, 6}, false, b), false);
      std::vector<u16> ord247({7, 0, 1, 2, 3, 4, 5, 6, 8});
    
    r->addIndex<9>(ord247, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{7, 0, 1, 2, 3, 4, 5, 6, 8}, false, b), false);
      std::vector<u16> ord248({3, 4, 5, 0, 1, 2, 6, 7, 8});
    
    r->addIndex<9>(ord248, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{3, 4, 5, 0, 1, 2, 6, 7, 8}, true, b), false);
      std::vector<u16> ord249({5, 3, 7, 8, 0, 1, 2, 4, 6});
    
    r->addIndex<9>(ord249, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{5, 3, 7, 8, 0, 1, 2, 4, 6}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<9>(db, db->getRelation("$sup9688x148x0x0x0"), std::array<u16,9>{0, 7, 1, 2, 3, 4, 5, 6, 8}, b));
  r = db->getRelation("$sup9688x145x0x0x0");
  if (r == 0) db->addRelation("$sup9688x145x0x0x0", 9);
  else if (r->getArity() != 9)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x145x0x0x0");
      std::vector<u16> ord250({0, 1, 2, 3, 4, 5, 6, 7, 8});
    
    r->addIndex<9>(ord250, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, false, b), true);
      std::vector<u16> ord251({1, 2, 4, 6, 0, 3, 5, 7, 8});
    
    r->addIndex<9>(ord251, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{1, 2, 4, 6, 0, 3, 5, 7, 8}, false, b), false);
      std::vector<u16> ord252({2, 5, 0, 1, 3, 4, 6, 7, 8});
    
    r->addIndex<9>(ord252, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{2, 5, 0, 1, 3, 4, 6, 7, 8}, false, b), false);
      std::vector<u16> ord253({3, 5, 7, 8, 0, 1, 2, 4, 6});
    
    r->addIndex<9>(ord253, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{3, 5, 7, 8, 0, 1, 2, 4, 6}, false, b), false);
      std::vector<u16> ord254({2, 5, 0, 1, 3, 4, 6, 7, 8});
    
    r->addIndex<9>(ord254, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{2, 5, 0, 1, 3, 4, 6, 7, 8}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<9>(db, db->getRelation("$sup9688x145x0x0x0"), std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, b));
  r = db->getRelation("$sup9688x142x0x0x0");
  if (r == 0) db->addRelation("$sup9688x142x0x0x0", 9);
  else if (r->getArity() != 9)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x142x0x0x0");
      std::vector<u16> ord255({0, 6, 1, 2, 3, 4, 5, 7, 8});
    
    r->addIndex<9>(ord255, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{0, 6, 1, 2, 3, 4, 5, 7, 8}, false, b), true);
      std::vector<u16> ord256({2, 5, 4, 0, 1, 3, 6, 7, 8});
    
    r->addIndex<9>(ord256, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{2, 5, 4, 0, 1, 3, 6, 7, 8}, false, b), false);
      std::vector<u16> ord257({3, 5, 7, 8, 6, 0, 1, 2, 4});
    
    r->addIndex<9>(ord257, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{3, 5, 7, 8, 6, 0, 1, 2, 4}, false, b), false);
      std::vector<u16> ord258({4, 1, 2, 6, 0, 3, 5, 7, 8});
    
    r->addIndex<9>(ord258, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{4, 1, 2, 6, 0, 3, 5, 7, 8}, false, b), false);
      std::vector<u16> ord259({6, 0, 1, 2, 3, 4, 5, 7, 8});
    
    r->addIndex<9>(ord259, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{6, 0, 1, 2, 3, 4, 5, 7, 8}, false, b), false);
      std::vector<u16> ord260({2, 5, 4, 0, 1, 3, 6, 7, 8});
    
    r->addIndex<9>(ord260, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{2, 5, 4, 0, 1, 3, 6, 7, 8}, true, b), false);
      std::vector<u16> ord261({4, 1, 2, 6, 0, 3, 5, 7, 8});
    
    r->addIndex<9>(ord261, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{4, 1, 2, 6, 0, 3, 5, 7, 8}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<9>(db, db->getRelation("$sup9688x142x0x0x0"), std::array<u16,9>{0, 6, 1, 2, 3, 4, 5, 7, 8}, b));
  r = db->getRelation("$sup9688x139x0x0x0");
  if (r == 0) db->addRelation("$sup9688x139x0x0x0", 9);
  else if (r->getArity() != 9)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x139x0x0x0");
      std::vector<u16> ord262({0, 1, 2, 3, 4, 5, 6, 7, 8});
    
    r->addIndex<9>(ord262, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, false, b), true);
      std::vector<u16> ord263({1, 0, 2, 3, 4, 5, 6, 7, 8});
    
    r->addIndex<9>(ord263, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{1, 0, 2, 3, 4, 5, 6, 7, 8}, false, b), false);
      std::vector<u16> ord264({2, 5, 4, 0, 1, 3, 6, 7, 8});
    
    r->addIndex<9>(ord264, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{2, 5, 4, 0, 1, 3, 6, 7, 8}, false, b), false);
      std::vector<u16> ord265({3, 5, 7, 8, 1, 0, 2, 4, 6});
    
    r->addIndex<9>(ord265, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{3, 5, 7, 8, 1, 0, 2, 4, 6}, false, b), false);
      std::vector<u16> ord266({4, 2, 6, 1, 0, 3, 5, 7, 8});
    
    r->addIndex<9>(ord266, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{4, 2, 6, 1, 0, 3, 5, 7, 8}, false, b), false);
      std::vector<u16> ord267({2, 5, 4, 0, 1, 3, 6, 7, 8});
    
    r->addIndex<9>(ord267, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{2, 5, 4, 0, 1, 3, 6, 7, 8}, true, b), false);
      std::vector<u16> ord268({4, 2, 6, 1, 0, 3, 5, 7, 8});
    
    r->addIndex<9>(ord268, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{4, 2, 6, 1, 0, 3, 5, 7, 8}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<9>(db, db->getRelation("$sup9688x139x0x0x0"), std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, b));
  r = db->getRelation("$sup9688x136x0x0x0");
  if (r == 0) db->addRelation("$sup9688x136x0x0x0", 7);
  else if (r->getArity() != 7)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x136x0x0x0");
      std::vector<u16> ord269({0, 1, 2, 3, 4, 5, 6});
    
    r->addIndex<7>(ord269, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, false, b), true);
      std::vector<u16> ord270({1, 5, 0, 2, 3, 4, 6});
    
    r->addIndex<7>(ord270, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{1, 5, 0, 2, 3, 4, 6}, false, b), false);
      std::vector<u16> ord271({2, 3, 1, 4, 0, 5, 6});
    
    r->addIndex<7>(ord271, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{2, 3, 1, 4, 0, 5, 6}, false, b), false);
      std::vector<u16> ord272({2, 3, 5, 6, 0, 1, 4});
    
    r->addIndex<7>(ord272, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{2, 3, 5, 6, 0, 1, 4}, false, b), false);
      std::vector<u16> ord273({4, 6, 0, 1, 2, 3, 5});
    
    r->addIndex<7>(ord273, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{4, 6, 0, 1, 2, 3, 5}, false, b), false);
      std::vector<u16> ord274({1, 5, 0, 2, 3, 4, 6});
    
    r->addIndex<7>(ord274, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{1, 5, 0, 2, 3, 4, 6}, true, b), false);
      std::vector<u16> ord275({2, 3, 5, 6, 0, 1, 4});
    
    r->addIndex<7>(ord275, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{2, 3, 5, 6, 0, 1, 4}, true, b), false);
      std::vector<u16> ord276({4, 6, 0, 1, 2, 3, 5});
    
    r->addIndex<7>(ord276, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{4, 6, 0, 1, 2, 3, 5}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<7>(db, db->getRelation("$sup9688x136x0x0x0"), std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, b));
  r = db->getRelation("$sup9688x120x0x0x0");
  if (r == 0) db->addRelation("$sup9688x120x0x0x0", 11);
  else if (r->getArity() != 11)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x120x0x0x0");
      std::vector<u16> ord277({3, 4, 0, 1, 2, 5, 6, 7, 8, 9, 10});
    
    r->addIndex<11>(ord277, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{3, 4, 0, 1, 2, 5, 6, 7, 8, 9, 10}, false, b), true);
      std::vector<u16> ord278({0, 7, 8, 1, 2, 3, 4, 5, 6, 9, 10});
    
    r->addIndex<11>(ord278, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{0, 7, 8, 1, 2, 3, 4, 5, 6, 9, 10}, false, b), false);
      std::vector<u16> ord279({1, 2, 4, 6, 7, 3, 0, 5, 8, 9, 10});
    
    r->addIndex<11>(ord279, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{1, 2, 4, 6, 7, 3, 0, 5, 8, 9, 10}, false, b), false);
      std::vector<u16> ord280({3, 5, 8, 9, 10, 0, 1, 2, 4, 6, 7});
    
    r->addIndex<11>(ord280, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{3, 5, 8, 9, 10, 0, 1, 2, 4, 6, 7}, false, b), false);
      std::vector<u16> ord281({4, 5, 7, 8, 0, 1, 2, 3, 6, 9, 10});
    
    r->addIndex<11>(ord281, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{4, 5, 7, 8, 0, 1, 2, 3, 6, 9, 10}, false, b), false);
      std::vector<u16> ord282({1, 2, 4, 6, 7, 3, 0, 5, 8, 9, 10});
    
    r->addIndex<11>(ord282, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{1, 2, 4, 6, 7, 3, 0, 5, 8, 9, 10}, true, b), false);
      std::vector<u16> ord283({4, 5, 7, 8, 0, 1, 2, 3, 6, 9, 10});
    
    r->addIndex<11>(ord283, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{4, 5, 7, 8, 0, 1, 2, 3, 6, 9, 10}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<11>(db, db->getRelation("$sup9688x120x0x0x0"), std::array<u16,11>{3, 4, 0, 1, 2, 5, 6, 7, 8, 9, 10}, b));
  r = db->getRelation("$sup9688x117x0x0x1");
  if (r == 0) db->addRelation("$sup9688x117x0x0x1", 10);
  else if (r->getArity() != 10)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x117x0x0x1");
      std::vector<u16> ord284({0, 9, 1, 2, 3, 4, 5, 6, 7, 8});
    
    r->addIndex<10>(ord284, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{0, 9, 1, 2, 3, 4, 5, 6, 7, 8}, false, b), true);
      std::vector<u16> ord285({1, 4, 5, 6, 0, 2, 3, 7, 8, 9});
    
    r->addIndex<10>(ord285, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{1, 4, 5, 6, 0, 2, 3, 7, 8, 9}, false, b), false);
      std::vector<u16> ord286({1, 6, 0, 2, 3, 4, 5, 7, 8, 9});
    
    r->addIndex<10>(ord286, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{1, 6, 0, 2, 3, 4, 5, 7, 8, 9}, false, b), false);
      std::vector<u16> ord287({2, 3, 5, 7, 0, 1, 4, 6, 8, 9});
    
    r->addIndex<10>(ord287, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{2, 3, 5, 7, 0, 1, 4, 6, 8, 9}, false, b), false);
      std::vector<u16> ord288({9, 4, 6, 8, 0, 2, 3, 5, 7, 1});
    
    r->addIndex<10>(ord288, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{9, 4, 6, 8, 0, 2, 3, 5, 7, 1}, false, b), false);
      std::vector<u16> ord289({1, 4, 5, 6, 0, 2, 3, 7, 8, 9});
    
    r->addIndex<10>(ord289, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{1, 4, 5, 6, 0, 2, 3, 7, 8, 9}, true, b), false);
      std::vector<u16> ord290({9, 4, 6, 8, 0, 2, 3, 5, 7, 1});
    
    r->addIndex<10>(ord290, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{9, 4, 6, 8, 0, 2, 3, 5, 7, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<10>(db, db->getRelation("$sup9688x117x0x0x1"), std::array<u16,10>{0, 9, 1, 2, 3, 4, 5, 6, 7, 8}, b));
  r = db->getRelation("$sup9688x117x0x0x0");
  if (r == 0) db->addRelation("$sup9688x117x0x0x0", 9);
  else if (r->getArity() != 9)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x117x0x0x0");
      std::vector<u16> ord291({0, 8, 1, 2, 3, 4, 5, 6, 7});
    
    r->addIndex<9>(ord291, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{0, 8, 1, 2, 3, 4, 5, 6, 7}, false, b), true);
      std::vector<u16> ord292({1, 2, 4, 6, 0, 3, 5, 7, 8});
    
    r->addIndex<9>(ord292, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{1, 2, 4, 6, 0, 3, 5, 7, 8}, false, b), false);
      std::vector<u16> ord293({3, 4, 5, 0, 1, 2, 6, 7, 8});
    
    r->addIndex<9>(ord293, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{3, 4, 5, 0, 1, 2, 6, 7, 8}, false, b), false);
      std::vector<u16> ord294({5, 3, 7, 8, 0, 1, 2, 4, 6});
    
    r->addIndex<9>(ord294, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{5, 3, 7, 8, 0, 1, 2, 4, 6}, false, b), false);
      std::vector<u16> ord295({8, 0, 1, 2, 3, 4, 5, 6, 7});
    
    r->addIndex<9>(ord295, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{8, 0, 1, 2, 3, 4, 5, 6, 7}, false, b), false);
      std::vector<u16> ord296({5, 3, 7, 8, 0, 1, 2, 4, 6});
    
    r->addIndex<9>(ord296, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{5, 3, 7, 8, 0, 1, 2, 4, 6}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<9>(db, db->getRelation("$sup9688x117x0x0x0"), std::array<u16,9>{0, 8, 1, 2, 3, 4, 5, 6, 7}, b));
  r = db->getRelation("$sup9688x114x0x0x1");
  if (r == 0) db->addRelation("$sup9688x114x0x0x1", 10);
  else if (r->getArity() != 10)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x114x0x0x1");
      std::vector<u16> ord297({0, 8, 1, 2, 3, 4, 5, 6, 7, 9});
    
    r->addIndex<10>(ord297, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{0, 8, 1, 2, 3, 4, 5, 6, 7, 9}, false, b), true);
      std::vector<u16> ord298({1, 4, 5, 6, 0, 2, 3, 7, 8, 9});
    
    r->addIndex<10>(ord298, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{1, 4, 5, 6, 0, 2, 3, 7, 8, 9}, false, b), false);
      std::vector<u16> ord299({1, 6, 0, 2, 3, 4, 5, 7, 8, 9});
    
    r->addIndex<10>(ord299, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{1, 6, 0, 2, 3, 4, 5, 7, 8, 9}, false, b), false);
      std::vector<u16> ord300({2, 3, 5, 7, 0, 1, 4, 6, 8, 9});
    
    r->addIndex<10>(ord300, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{2, 3, 5, 7, 0, 1, 4, 6, 8, 9}, false, b), false);
      std::vector<u16> ord301({8, 4, 6, 9, 0, 2, 3, 5, 7, 1});
    
    r->addIndex<10>(ord301, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{8, 4, 6, 9, 0, 2, 3, 5, 7, 1}, false, b), false);
      std::vector<u16> ord302({1, 4, 5, 6, 0, 2, 3, 7, 8, 9});
    
    r->addIndex<10>(ord302, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{1, 4, 5, 6, 0, 2, 3, 7, 8, 9}, true, b), false);
      std::vector<u16> ord303({8, 4, 6, 9, 0, 2, 3, 5, 7, 1});
    
    r->addIndex<10>(ord303, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{8, 4, 6, 9, 0, 2, 3, 5, 7, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<10>(db, db->getRelation("$sup9688x114x0x0x1"), std::array<u16,10>{0, 8, 1, 2, 3, 4, 5, 6, 7, 9}, b));
  r = db->getRelation("$sup9688x114x0x0x0");
  if (r == 0) db->addRelation("$sup9688x114x0x0x0", 9);
  else if (r->getArity() != 9)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x114x0x0x0");
      std::vector<u16> ord304({0, 7, 1, 2, 3, 4, 5, 6, 8});
    
    r->addIndex<9>(ord304, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{0, 7, 1, 2, 3, 4, 5, 6, 8}, false, b), true);
      std::vector<u16> ord305({1, 2, 4, 6, 0, 3, 5, 7, 8});
    
    r->addIndex<9>(ord305, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{1, 2, 4, 6, 0, 3, 5, 7, 8}, false, b), false);
      std::vector<u16> ord306({3, 4, 5, 0, 1, 2, 6, 7, 8});
    
    r->addIndex<9>(ord306, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{3, 4, 5, 0, 1, 2, 6, 7, 8}, false, b), false);
      std::vector<u16> ord307({5, 3, 7, 8, 0, 1, 2, 4, 6});
    
    r->addIndex<9>(ord307, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{5, 3, 7, 8, 0, 1, 2, 4, 6}, false, b), false);
      std::vector<u16> ord308({7, 0, 1, 2, 3, 4, 5, 6, 8});
    
    r->addIndex<9>(ord308, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{7, 0, 1, 2, 3, 4, 5, 6, 8}, false, b), false);
      std::vector<u16> ord309({5, 3, 7, 8, 0, 1, 2, 4, 6});
    
    r->addIndex<9>(ord309, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{5, 3, 7, 8, 0, 1, 2, 4, 6}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<9>(db, db->getRelation("$sup9688x114x0x0x0"), std::array<u16,9>{0, 7, 1, 2, 3, 4, 5, 6, 8}, b));
  r = db->getRelation("$sup9688x110x0x0x0");
  if (r == 0) db->addRelation("$sup9688x110x0x0x0", 11);
  else if (r->getArity() != 11)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x110x0x0x0");
      std::vector<u16> ord310({2, 5, 0, 1, 3, 4, 6, 7, 8, 9, 10});
    
    r->addIndex<11>(ord310, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{2, 5, 0, 1, 3, 4, 6, 7, 8, 9, 10}, false, b), true);
      std::vector<u16> ord311({0, 7, 8, 1, 2, 3, 4, 5, 6, 9, 10});
    
    r->addIndex<11>(ord311, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{0, 7, 8, 1, 2, 3, 4, 5, 6, 9, 10}, false, b), false);
      std::vector<u16> ord312({1, 2, 4, 6, 7, 5, 0, 3, 8, 9, 10});
    
    r->addIndex<11>(ord312, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{1, 2, 4, 6, 7, 5, 0, 3, 8, 9, 10}, false, b), false);
      std::vector<u16> ord313({3, 5, 8, 9, 10, 0, 1, 2, 4, 6, 7});
    
    r->addIndex<11>(ord313, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{3, 5, 8, 9, 10, 0, 1, 2, 4, 6, 7}, false, b), false);
      std::vector<u16> ord314({4, 5, 7, 8, 0, 1, 2, 3, 6, 9, 10});
    
    r->addIndex<11>(ord314, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{4, 5, 7, 8, 0, 1, 2, 3, 6, 9, 10}, false, b), false);
      std::vector<u16> ord315({1, 2, 4, 6, 7, 5, 0, 3, 8, 9, 10});
    
    r->addIndex<11>(ord315, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{1, 2, 4, 6, 7, 5, 0, 3, 8, 9, 10}, true, b), false);
      std::vector<u16> ord316({4, 5, 7, 8, 0, 1, 2, 3, 6, 9, 10});
    
    r->addIndex<11>(ord316, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<11>(db, r, std::array<u16,11>{4, 5, 7, 8, 0, 1, 2, 3, 6, 9, 10}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<11>(db, db->getRelation("$sup9688x110x0x0x0"), std::array<u16,11>{2, 5, 0, 1, 3, 4, 6, 7, 8, 9, 10}, b));
  r = db->getRelation("$sup9688x106x0x0x1");
  if (r == 0) db->addRelation("$sup9688x106x0x0x1", 10);
  else if (r->getArity() != 10)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x106x0x0x1");
      std::vector<u16> ord317({0, 7, 1, 2, 3, 4, 5, 6, 8, 9});
    
    r->addIndex<10>(ord317, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{0, 7, 1, 2, 3, 4, 5, 6, 8, 9}, false, b), true);
      std::vector<u16> ord318({1, 3, 6, 5, 0, 2, 4, 7, 8, 9});
    
    r->addIndex<10>(ord318, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{1, 3, 6, 5, 0, 2, 4, 7, 8, 9}, false, b), false);
      std::vector<u16> ord319({1, 5, 0, 2, 3, 4, 6, 7, 8, 9});
    
    r->addIndex<10>(ord319, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{1, 5, 0, 2, 3, 4, 6, 7, 8, 9}, false, b), false);
      std::vector<u16> ord320({4, 6, 8, 9, 0, 1, 2, 3, 5, 7});
    
    r->addIndex<10>(ord320, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{4, 6, 8, 9, 0, 1, 2, 3, 5, 7}, false, b), false);
      std::vector<u16> ord321({7, 2, 3, 5, 0, 4, 6, 8, 9, 1});
    
    r->addIndex<10>(ord321, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{7, 2, 3, 5, 0, 4, 6, 8, 9, 1}, false, b), false);
      std::vector<u16> ord322({1, 3, 6, 5, 0, 2, 4, 7, 8, 9});
    
    r->addIndex<10>(ord322, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{1, 3, 6, 5, 0, 2, 4, 7, 8, 9}, true, b), false);
      std::vector<u16> ord323({7, 2, 3, 5, 0, 4, 6, 8, 9, 1});
    
    r->addIndex<10>(ord323, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{7, 2, 3, 5, 0, 4, 6, 8, 9, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<10>(db, db->getRelation("$sup9688x106x0x0x1"), std::array<u16,10>{0, 7, 1, 2, 3, 4, 5, 6, 8, 9}, b));
  r = db->getRelation("$sup9688x106x0x0x0");
  if (r == 0) db->addRelation("$sup9688x106x0x0x0", 9);
  else if (r->getArity() != 9)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x106x0x0x0");
      std::vector<u16> ord324({0, 6, 1, 2, 3, 4, 5, 7, 8});
    
    r->addIndex<9>(ord324, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{0, 6, 1, 2, 3, 4, 5, 7, 8}, false, b), true);
      std::vector<u16> ord325({2, 5, 4, 0, 1, 3, 6, 7, 8});
    
    r->addIndex<9>(ord325, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{2, 5, 4, 0, 1, 3, 6, 7, 8}, false, b), false);
      std::vector<u16> ord326({3, 5, 7, 8, 0, 1, 2, 4, 6});
    
    r->addIndex<9>(ord326, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{3, 5, 7, 8, 0, 1, 2, 4, 6}, false, b), false);
      std::vector<u16> ord327({4, 1, 2, 6, 0, 3, 5, 7, 8});
    
    r->addIndex<9>(ord327, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{4, 1, 2, 6, 0, 3, 5, 7, 8}, false, b), false);
      std::vector<u16> ord328({6, 0, 1, 2, 3, 4, 5, 7, 8});
    
    r->addIndex<9>(ord328, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{6, 0, 1, 2, 3, 4, 5, 7, 8}, false, b), false);
      std::vector<u16> ord329({4, 1, 2, 6, 0, 3, 5, 7, 8});
    
    r->addIndex<9>(ord329, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{4, 1, 2, 6, 0, 3, 5, 7, 8}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<9>(db, db->getRelation("$sup9688x106x0x0x0"), std::array<u16,9>{0, 6, 1, 2, 3, 4, 5, 7, 8}, b));
  r = db->getRelation("$sup9688x103x0x0x1");
  if (r == 0) db->addRelation("$sup9688x103x0x0x1", 10);
  else if (r->getArity() != 10)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x103x0x0x1");
      std::vector<u16> ord330({0, 2, 1, 3, 4, 5, 6, 7, 8, 9});
    
    r->addIndex<10>(ord330, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{0, 2, 1, 3, 4, 5, 6, 7, 8, 9}, false, b), true);
      std::vector<u16> ord331({1, 3, 6, 5, 0, 2, 4, 7, 8, 9});
    
    r->addIndex<10>(ord331, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{1, 3, 6, 5, 0, 2, 4, 7, 8, 9}, false, b), false);
      std::vector<u16> ord332({1, 5, 0, 2, 3, 4, 6, 7, 8, 9});
    
    r->addIndex<10>(ord332, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{1, 5, 0, 2, 3, 4, 6, 7, 8, 9}, false, b), false);
      std::vector<u16> ord333({2, 3, 5, 7, 0, 4, 6, 8, 9, 1});
    
    r->addIndex<10>(ord333, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{2, 3, 5, 7, 0, 4, 6, 8, 9, 1}, false, b), false);
      std::vector<u16> ord334({4, 6, 8, 9, 0, 1, 2, 3, 5, 7});
    
    r->addIndex<10>(ord334, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{4, 6, 8, 9, 0, 1, 2, 3, 5, 7}, false, b), false);
      std::vector<u16> ord335({1, 3, 6, 5, 0, 2, 4, 7, 8, 9});
    
    r->addIndex<10>(ord335, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{1, 3, 6, 5, 0, 2, 4, 7, 8, 9}, true, b), false);
      std::vector<u16> ord336({2, 3, 5, 7, 0, 4, 6, 8, 9, 1});
    
    r->addIndex<10>(ord336, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<10>(db, r, std::array<u16,10>{2, 3, 5, 7, 0, 4, 6, 8, 9, 1}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<10>(db, db->getRelation("$sup9688x103x0x0x1"), std::array<u16,10>{0, 2, 1, 3, 4, 5, 6, 7, 8, 9}, b));
  r = db->getRelation("$sup9688x103x0x0x0");
  if (r == 0) db->addRelation("$sup9688x103x0x0x0", 9);
  else if (r->getArity() != 9)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x103x0x0x0");
      std::vector<u16> ord337({0, 1, 2, 3, 4, 5, 6, 7, 8});
    
    r->addIndex<9>(ord337, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, false, b), true);
      std::vector<u16> ord338({1, 2, 4, 6, 0, 3, 5, 7, 8});
    
    r->addIndex<9>(ord338, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{1, 2, 4, 6, 0, 3, 5, 7, 8}, false, b), false);
      std::vector<u16> ord339({2, 5, 4, 0, 1, 3, 6, 7, 8});
    
    r->addIndex<9>(ord339, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{2, 5, 4, 0, 1, 3, 6, 7, 8}, false, b), false);
      std::vector<u16> ord340({3, 5, 7, 8, 0, 1, 2, 4, 6});
    
    r->addIndex<9>(ord340, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{3, 5, 7, 8, 0, 1, 2, 4, 6}, false, b), false);
      std::vector<u16> ord341({4, 0, 1, 2, 3, 5, 6, 7, 8});
    
    r->addIndex<9>(ord341, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{4, 0, 1, 2, 3, 5, 6, 7, 8}, false, b), false);
      std::vector<u16> ord342({1, 2, 4, 6, 0, 3, 5, 7, 8});
    
    r->addIndex<9>(ord342, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{1, 2, 4, 6, 0, 3, 5, 7, 8}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<9>(db, db->getRelation("$sup9688x103x0x0x0"), std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, b));
  r = db->getRelation("$sup9688x100x0x0x0");
  if (r == 0) db->addRelation("$sup9688x100x0x0x0", 7);
  else if (r->getArity() != 7)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup9688x100x0x0x0");
      std::vector<u16> ord343({0, 1, 2, 3, 4, 5, 6});
    
    r->addIndex<7>(ord343, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, false, b), true);
      std::vector<u16> ord344({1, 2, 3, 4, 0, 5, 6});
    
    r->addIndex<7>(ord344, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{1, 2, 3, 4, 0, 5, 6}, false, b), false);
      std::vector<u16> ord345({1, 5, 0, 2, 3, 4, 6});
    
    r->addIndex<7>(ord345, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{1, 5, 0, 2, 3, 4, 6}, false, b), false);
      std::vector<u16> ord346({2, 3, 5, 6, 0, 1, 4});
    
    r->addIndex<7>(ord346, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{2, 3, 5, 6, 0, 1, 4}, false, b), false);
      std::vector<u16> ord347({4, 6, 0, 1, 2, 3, 5});
    
    r->addIndex<7>(ord347, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{4, 6, 0, 1, 2, 3, 5}, false, b), false);
      std::vector<u16> ord348({1, 5, 0, 2, 3, 4, 6});
    
    r->addIndex<7>(ord348, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{1, 5, 0, 2, 3, 4, 6}, true, b), false);
      std::vector<u16> ord349({4, 6, 0, 1, 2, 3, 5});
    
    r->addIndex<7>(ord349, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<7>(db, r, std::array<u16,7>{4, 6, 0, 1, 2, 3, 5}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<7>(db, db->getRelation("$sup9688x100x0x0x0"), std::array<u16,7>{0, 1, 2, 3, 4, 5, 6}, b));
  r = db->getRelation("$seq_atr");
  if (r == 0) db->addRelation("$seq_atr", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$seq_atr");
      std::vector<u16> ord350({0, 1, 2});
    
    r->addIndex<3>(ord350, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
      std::vector<u16> ord351({0, 1, 2});
    
    r->addIndex<3>(ord351, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$seq_atr"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("$seq_at");
  if (r == 0) db->addRelation("$seq_at", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$seq_at");
      std::vector<u16> ord352({1, 0, 2});
    
    r->addIndex<3>(ord352, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 0, 2}, false, b), true);
      std::vector<u16> ord353({1, 0, 2});
    
    r->addIndex<3>(ord353, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 0, 2}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$seq_at"), std::array<u16,3>{1, 0, 2}, b));
  {
    std::vector<u16> seqcols({1});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("st_fromlist"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  slog_rules_c823fae8cf812f2da(db, s);
  slog_rules_cbabdb3c6024ae24d(db, s);
  slog_rules_cc67696b823a1d9b9(db, s);
  slog_rules_c8c9720fd6e0bc4f9(db, s);
  slog_rules_c65bbed1236339abd(db, s);
  slog_rules_c00af38e888f83b07(db, s);
  slog_rules_cb8ebc47edbdc47eb(db, s);
  slog_rules_c1a7954baa8c7a132(db, s);
  slog_rules_c7cf27517710f1393(db, s);
  slog_rules_c54d73746b0e79d0e(db, s);
  slog_rules_c73ff02b198ad68e4(db, s);
  slog_rules_c41f2ec6a574d4d3d(db, s);
  slog_rules_c66c32b0817855ec9(db, s);
  slog_rules_c6481f25fa5c8b850(db, s);
  slog_rules_cd02a570b13bbad42(db, s);
  slog_rules_c78f902bcfebb45d1(db, s);
  s->addReadRel("$seq_at");
  s->addReadRel("$seq_atr");
  s->addReadRel("$sup9688x100x0x0x0");
  s->addReadRel("$sup9688x103x0x0x0");
  s->addReadRel("$sup9688x103x0x0x1");
  s->addReadRel("$sup9688x106x0x0x0");
  s->addReadRel("$sup9688x106x0x0x1");
  s->addReadRel("$sup9688x110x0x0x0");
  s->addReadRel("$sup9688x114x0x0x0");
  s->addReadRel("$sup9688x114x0x0x1");
  s->addReadRel("$sup9688x117x0x0x0");
  s->addReadRel("$sup9688x117x0x0x1");
  s->addReadRel("$sup9688x120x0x0x0");
  s->addReadRel("$sup9688x136x0x0x0");
  s->addReadRel("$sup9688x139x0x0x0");
  s->addReadRel("$sup9688x142x0x0x0");
  s->addReadRel("$sup9688x145x0x0x0");
  s->addReadRel("$sup9688x148x0x0x0");
  s->addReadRel("$sup9688x151x0x0x0");
  s->addReadRel("$sup9688x154x0x0x0");
  s->addReadRel("$sup9688x168x0x0x0");
  s->addReadRel("$sup9688x36x0x0x0");
  s->addReadRel("$sup9688x36x0x0x1");
  s->addReadRel("$sup9688x36x0x0x2");
  s->addReadRel("$sup9688x40x0x0x0");
  s->addReadRel("$sup9688x40x0x0x1");
  s->addReadRel("$sup9688x40x0x0x2");
  s->addReadRel("$sup9688x50x0x0x0");
  s->addReadRel("$sup9688x50x0x0x1");
  s->addReadRel("$sup9688x52x0x0x0");
  s->addReadRel("$sup9688x52x0x0x1");
  s->addReadRel("$sup9688x54x0x0x0");
  s->addReadRel("$sup9688x69x0x0x0");
  s->addReadRel("$sup9688x70x0x0x0");
  s->addReadRel("$sup9688x72x0x0x0");
  s->addReadRel("$sup9688x87x0x0x0");
  s->addReadRel("$sup9688x88x0x0x0");
  s->addReadRel("$sup9688x90x0x0x0");
  s->addReadRel("$sup97714x23x0x0x1");
  s->addReadRel("_enum");
  s->addReadRel("canon");
  s->addReadRel("div_by_zero");
  s->addReadRel("int_overflow");
  s->addReadRel("malformed_deduction");
  s->addReadRel("modulo_by_zero");
  s->addReadRel("mpz_overflow");
  s->addReadRel("mpz_table_overflow");
  s->addReadRel("nan_result");
  s->addReadRel("pbranch");
  s->addReadRel("pleaf");
  s->addReadRel("st_bld");
  s->addReadRel("st_bld_ans");
  s->addReadRel("st_del");
  s->addReadRel("st_del_ans");
  s->addReadRel("st_diff");
  s->addReadRel("st_diff_ans");
  s->addReadRel("st_fromlist");
  s->addReadRel("st_fromlist_ans");
  s->addReadRel("st_hsb");
  s->addReadRel("st_hsb_ans");
  s->addReadRel("st_ins");
  s->addReadRel("st_ins_ans");
  s->addReadRel("st_join");
  s->addReadRel("st_join_ans");
  s->addReadRel("st_mem0");
  s->addReadRel("st_mem0_ans");
  s->addReadRel("st_msk");
  s->addReadRel("st_msk_ans");
  s->addReadRel("st_union");
  s->addReadRel("st_union_ans");
  s->addReadRel("temp00v81415");
  s->addReadRel("temp16ye1280");
  s->addReadRel("temp18xQ1344");
  s->addReadRel("temp1Dk71281");
  s->addReadRel("temp1foc1411");
  s->addReadRel("temp1gVy1270");
  s->addReadRel("temp1pqw1409");
  s->addReadRel("temp20p21276");
  s->addReadRel("temp3LID1346");
  s->addReadRel("temp3Stv1345");
  s->addReadRel("temp3V0b1338");
  s->addReadRel("temp3vnE1273");
  s->addReadRel("temp3xVH1332");
  s->addReadRel("temp44eI1413");
  s->addReadRel("temp4FcU1416");
  s->addReadRel("temp4PCZ1408");
  s->addReadRel("temp4p811353");
  s->addReadRel("temp4rmF1269");
  s->addReadRel("temp5Bov1275");
  s->addReadRel("temp5IQT1412");
  s->addReadRel("temp5blj1404");
  s->addReadRel("temp6bMv1274");
  s->addReadRel("temp76Kg1410");
  s->addReadRel("temp7DYO1402");
  s->addReadRel("temp7LNh1339");
  s->addReadRel("temp7aSv1347");
  s->addReadRel("temp7u1Q1268");
  s->addReadRel("temp8c8A1414");
  s->addReadRel("temp8kS01399");
  s->addReadRel("temp8v341350");
  s->addReadRel("temp9CLY1403");
  s->addReadRel("temp9eaB1343");
  s->addReadRel("toint_range");
  s->addReadRel("type_mismatch");
  s->addDynamicRel("$seq_at");
  s->addDynamicRel("$seq_atr");
  s->addDynamicRel("$sup9688x100x0x0x0");
  s->addDynamicRel("$sup9688x103x0x0x0");
  s->addDynamicRel("$sup9688x103x0x0x1");
  s->addDynamicRel("$sup9688x106x0x0x0");
  s->addDynamicRel("$sup9688x106x0x0x1");
  s->addDynamicRel("$sup9688x110x0x0x0");
  s->addDynamicRel("$sup9688x114x0x0x0");
  s->addDynamicRel("$sup9688x114x0x0x1");
  s->addDynamicRel("$sup9688x117x0x0x0");
  s->addDynamicRel("$sup9688x117x0x0x1");
  s->addDynamicRel("$sup9688x120x0x0x0");
  s->addDynamicRel("$sup9688x136x0x0x0");
  s->addDynamicRel("$sup9688x139x0x0x0");
  s->addDynamicRel("$sup9688x142x0x0x0");
  s->addDynamicRel("$sup9688x145x0x0x0");
  s->addDynamicRel("$sup9688x148x0x0x0");
  s->addDynamicRel("$sup9688x151x0x0x0");
  s->addDynamicRel("$sup9688x154x0x0x0");
  s->addDynamicRel("$sup9688x36x0x0x0");
  s->addDynamicRel("$sup9688x36x0x0x1");
  s->addDynamicRel("$sup9688x36x0x0x2");
  s->addDynamicRel("$sup9688x40x0x0x0");
  s->addDynamicRel("$sup9688x40x0x0x1");
  s->addDynamicRel("$sup9688x40x0x0x2");
  s->addDynamicRel("$sup9688x50x0x0x0");
  s->addDynamicRel("$sup9688x50x0x0x1");
  s->addDynamicRel("$sup9688x52x0x0x0");
  s->addDynamicRel("$sup9688x52x0x0x1");
  s->addDynamicRel("$sup9688x54x0x0x0");
  s->addDynamicRel("$sup9688x69x0x0x0");
  s->addDynamicRel("$sup9688x70x0x0x0");
  s->addDynamicRel("$sup9688x72x0x0x0");
  s->addDynamicRel("$sup9688x87x0x0x0");
  s->addDynamicRel("$sup9688x88x0x0x0");
  s->addDynamicRel("$sup9688x90x0x0x0");
  s->addDynamicRel("$sup97714x23x0x0x1");
  s->addDynamicRel("canon");
  s->addDynamicRel("div_by_zero");
  s->addDynamicRel("error");
  s->addDynamicRel("int_overflow");
  s->addDynamicRel("malformed_deduction");
  s->addDynamicRel("modulo_by_zero");
  s->addDynamicRel("mpz_overflow");
  s->addDynamicRel("mpz_table_overflow");
  s->addDynamicRel("nan_result");
  s->addDynamicRel("pbranch");
  s->addDynamicRel("pleaf");
  s->addDynamicRel("st_bld");
  s->addDynamicRel("st_bld_ans");
  s->addDynamicRel("st_del");
  s->addDynamicRel("st_del_ans");
  s->addDynamicRel("st_diff");
  s->addDynamicRel("st_diff_ans");
  s->addDynamicRel("st_fromlist_ans");
  s->addDynamicRel("st_hsb");
  s->addDynamicRel("st_hsb_ans");
  s->addDynamicRel("st_ins");
  s->addDynamicRel("st_ins_ans");
  s->addDynamicRel("st_join");
  s->addDynamicRel("st_join_ans");
  s->addDynamicRel("st_mem0");
  s->addDynamicRel("st_mem0_ans");
  s->addDynamicRel("st_msk");
  s->addDynamicRel("st_msk_ans");
  s->addDynamicRel("st_union");
  s->addDynamicRel("st_union_ans");
  s->addDynamicRel("temp00v81415");
  s->addDynamicRel("temp16ye1280");
  s->addDynamicRel("temp18xQ1344");
  s->addDynamicRel("temp1Dk71281");
  s->addDynamicRel("temp1foc1411");
  s->addDynamicRel("temp1gVy1270");
  s->addDynamicRel("temp1pqw1409");
  s->addDynamicRel("temp20p21276");
  s->addDynamicRel("temp3LID1346");
  s->addDynamicRel("temp3Stv1345");
  s->addDynamicRel("temp3V0b1338");
  s->addDynamicRel("temp3vnE1273");
  s->addDynamicRel("temp3xVH1332");
  s->addDynamicRel("temp44eI1413");
  s->addDynamicRel("temp4FcU1416");
  s->addDynamicRel("temp4PCZ1408");
  s->addDynamicRel("temp4p811353");
  s->addDynamicRel("temp4rmF1269");
  s->addDynamicRel("temp5Bov1275");
  s->addDynamicRel("temp5IQT1412");
  s->addDynamicRel("temp5blj1404");
  s->addDynamicRel("temp6bMv1274");
  s->addDynamicRel("temp76Kg1410");
  s->addDynamicRel("temp7DYO1402");
  s->addDynamicRel("temp7LNh1339");
  s->addDynamicRel("temp7aSv1347");
  s->addDynamicRel("temp7u1Q1268");
  s->addDynamicRel("temp8c8A1414");
  s->addDynamicRel("temp8kS01399");
  s->addDynamicRel("temp8v341350");
  s->addDynamicRel("temp9CLY1403");
  s->addDynamicRel("temp9eaB1343");
  s->addDynamicRel("toint_range");
  s->addDynamicRel("type_mismatch");
  s->addAccelRel("canon");
  s->addAccelRel("st_bld_ans");
  s->addAccelRel("st_del_ans");
  s->addAccelRel("st_diff_ans");
  s->addAccelRel("st_fromlist_ans");
  s->addAccelRel("st_hsb_ans");
  s->addAccelRel("st_ins_ans");
  s->addAccelRel("st_join_ans");
  s->addAccelRel("st_mem0_ans");
  s->addAccelRel("st_msk_ans");
  s->addAccelRel("st_union_ans");
  d->push(s);
  d->continueRun();
}

