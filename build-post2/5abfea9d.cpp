
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const5feceb66ffc86f38d952786c;
u64 v_constb17ef6d19c7a5b1ee83b907c;
u64 v_conste29c9c180c6279b0b02abd6a;
u64 v_const98010bd9270f9b100b6214a2;
u64 v_const6b86b273ff34fce19d6b804e;
u64 v_const4523540f1504cd17100c4835;
u64 v_constc6f3ac57944a531490cd3990;
u64 v_const0e17daca5f3e175f448bacac;
u64 v_constd4735e3a265e16eee03f5971;
u64 v_const4ec9599fc203d176a301536c;
u64 v_const86e50149658661312a9e0b35;
u64 v_const1a6562590ef19d1045d06c40;
u64 v_const4e07408562bedb8b60ce05c1;
u64 v_const9400f1b21cb527d7fa3d3eab;
u64 v_const9f14025af0065b30e47e23eb;
u64 v_const4b227777d4dd1fc61c6f884f;
u64 v_constf5ca38f748a1d6eaf726b8a4;
u64 v_const76a50887d8f1c2e930175542;
u64 v_constef2d127de37b942baad06145;
u64 v_const6f4b6612125fb3a0daecd279;
u64 v_const7a61b53701befdae0eeeffae;
u64 v_conste7f6c011776e8db7cd330b54;
u64 v_const785f3ec7eb32f30b90cd0fcf;
u64 v_constaea92132c4cbeb263e6ac2bf;
u64 v_const7902699be42c8a8e46fbbb45;
u64 v_const535fa30d7e25dd8a49f15367;
u64 v_const0b918943df0962bc7a1824c0;
u64 v_const2c624232cdd221771294dfbb;
u64 v_constc2356069e9d1e79ca9243781;
u64 v_constd59eced1ded07f84c145592f;
u64 v_const19581e27de7ced00ff1ce50b;
u64 v_constb7a56873cd771f2c446d369b;
u64 v_const3d914f9348c9cc0ff8a79716;
u64 v_const4a44dc15364204a80fe80e90;
u64 v_const5f9c4ab08cac7457e9111a30;
u64 v_const73475cb40a568e8da8a045ce;
u64 v_const4fc82b26aecb47d2868c4efb;
u64 v_const670671cd97404156226e5079;
u64 v_const44cb730c420480a0477b505a;
u64 v_const6b51d431df5d7f141cbececc;
u64 v_const59e19706d51d39f66711c265;
u64 v_const71ee45a3c0db9a9865f7313d;
u64 v_const3fdba35f04dc8c462986c992;
u64 v_const35135aaa6cc23891b40cb3f3;
u64 v_const811786ad1ae74adfdd20dd03;
u64 v_const8527a891e224136950ff32ca;
u64 v_const624b60c58c9d8bfb6ff1886c;
u64 v_const25fc0e7096fc653718202dc3;
u64 v_conste629fa6598d732768f7c726b;
u64 v_consteb1e33e8a81b697b75855af6;
u64 v_const31489056e0916d59fe3add79;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("5abfea9d");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const5feceb66ffc86f38d952786c = s32_encode(0);
  v_constb17ef6d19c7a5b1ee83b907c = s32_encode(16);
  v_conste29c9c180c6279b0b02abd6a = s32_encode(32);
  v_const98010bd9270f9b100b6214a2 = s32_encode(48);
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  v_const4523540f1504cd17100c4835 = s32_encode(17);
  v_constc6f3ac57944a531490cd3990 = s32_encode(33);
  v_const0e17daca5f3e175f448bacac = s32_encode(49);
  v_constd4735e3a265e16eee03f5971 = s32_encode(2);
  v_const4ec9599fc203d176a301536c = s32_encode(18);
  v_const86e50149658661312a9e0b35 = s32_encode(34);
  v_const1a6562590ef19d1045d06c40 = s32_encode(50);
  v_const4e07408562bedb8b60ce05c1 = s32_encode(3);
  v_const9400f1b21cb527d7fa3d3eab = s32_encode(19);
  v_const9f14025af0065b30e47e23eb = s32_encode(35);
  v_const4b227777d4dd1fc61c6f884f = s32_encode(4);
  v_constf5ca38f748a1d6eaf726b8a4 = s32_encode(20);
  v_const76a50887d8f1c2e930175542 = s32_encode(36);
  v_constef2d127de37b942baad06145 = s32_encode(5);
  v_const6f4b6612125fb3a0daecd279 = s32_encode(21);
  v_const7a61b53701befdae0eeeffae = s32_encode(37);
  v_conste7f6c011776e8db7cd330b54 = s32_encode(6);
  v_const785f3ec7eb32f30b90cd0fcf = s32_encode(22);
  v_constaea92132c4cbeb263e6ac2bf = s32_encode(38);
  v_const7902699be42c8a8e46fbbb45 = s32_encode(7);
  v_const535fa30d7e25dd8a49f15367 = s32_encode(23);
  v_const0b918943df0962bc7a1824c0 = s32_encode(39);
  v_const2c624232cdd221771294dfbb = s32_encode(8);
  v_constc2356069e9d1e79ca9243781 = s32_encode(24);
  v_constd59eced1ded07f84c145592f = s32_encode(40);
  v_const19581e27de7ced00ff1ce50b = s32_encode(9);
  v_constb7a56873cd771f2c446d369b = s32_encode(25);
  v_const3d914f9348c9cc0ff8a79716 = s32_encode(41);
  v_const4a44dc15364204a80fe80e90 = s32_encode(10);
  v_const5f9c4ab08cac7457e9111a30 = s32_encode(26);
  v_const73475cb40a568e8da8a045ce = s32_encode(42);
  v_const4fc82b26aecb47d2868c4efb = s32_encode(11);
  v_const670671cd97404156226e5079 = s32_encode(27);
  v_const44cb730c420480a0477b505a = s32_encode(43);
  v_const6b51d431df5d7f141cbececc = s32_encode(12);
  v_const59e19706d51d39f66711c265 = s32_encode(28);
  v_const71ee45a3c0db9a9865f7313d = s32_encode(44);
  v_const3fdba35f04dc8c462986c992 = s32_encode(13);
  v_const35135aaa6cc23891b40cb3f3 = s32_encode(29);
  v_const811786ad1ae74adfdd20dd03 = s32_encode(45);
  v_const8527a891e224136950ff32ca = s32_encode(14);
  v_const624b60c58c9d8bfb6ff1886c = s32_encode(30);
  v_const25fc0e7096fc653718202dc3 = s32_encode(46);
  v_conste629fa6598d732768f7c726b = s32_encode(15);
  v_consteb1e33e8a81b697b75855af6 = s32_encode(31);
  v_const31489056e0916d59fe3add79 = s32_encode(47);
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord201({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord201, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord202({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord202, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord203({1, 2, 0});
    
    r->addIndex<3>(ord203, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord204({0, 1, 2});
    
    r->addIndex<3>(ord204, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord205({1, 2, 0});
    
    r->addIndex<3>(ord205, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord206({0, 1, 2});
    
    r->addIndex<3>(ord206, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("path");
  if (r == 0) db->addRelation("path", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("path");
      std::vector<u16> ord207({0, 1});
    
    r->addIndex<2>(ord207, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("path"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord208({1, 2, 3, 0});
    
    r->addIndex<4>(ord208, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord209({0, 1, 2, 3});
    
    r->addIndex<4>(ord209, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord210({1, 2, 0});
    
    r->addIndex<3>(ord210, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord211({0, 1, 2});
    
    r->addIndex<3>(ord211, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord212({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord212, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord213({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord213, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord214({1, 2, 0});
    
    r->addIndex<3>(ord214, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord215({0, 1, 2});
    
    r->addIndex<3>(ord215, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord216({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord216, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord217({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord217, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord218({1, 2, 3, 0});
    
    r->addIndex<4>(ord218, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord219({0, 1, 2, 3});
    
    r->addIndex<4>(ord219, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord220({0});
    
    r->addIndex<1>(ord220, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("edge");
  if (r == 0) db->addRelation("edge", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("edge");
      std::vector<u16> ord221({0, 1});
    
    r->addIndex<2>(ord221, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("edge"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord222({1, 2, 0});
    
    r->addIndex<3>(ord222, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord223({0, 1, 2});
    
    r->addIndex<3>(ord223, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord224({1, 0});
    
    r->addIndex<2>(ord224, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord225({0, 1});
    
    r->addIndex<2>(ord225, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  // (crule (pre (let __tconst6Rrp4 const6b86b273ff34fce19d6b804e) (let __tconst7I9S8 constd4735e3a265e16eee03f5971) (let __tconst2DKk12 const4e07408562bedb8b60ce05c1) (let __tconst4K5f16 const4b227777d4dd1fc61c6f884f) (let __tconst8vnl20 constef2d127de37b942baad06145) (let __tconst4S6B24 conste7f6c011776e8db7cd330b54) (let __tconst5MpT28 const7902699be42c8a8e46fbbb45) (let __tconst4oy732 const2c624232cdd221771294dfbb) (let __tconst1gcV36 const19581e27de7ced00ff1ce50b) (let __tconst7DvQ40 const4a44dc15364204a80fe80e90) (let __tconst0lsV44 const4fc82b26aecb47d2868c4efb) (let __tconst8WDD48 const6b51d431df5d7f141cbececc) (let __tconst9OpU52 const3fdba35f04dc8c462986c992) (let __tconst7G5Z56 const8527a891e224136950ff32ca) (let __tconst8OVI60 conste629fa6598d732768f7c726b) (let __tconst6PM664 constb17ef6d19c7a5b1ee83b907c) (let __tconst3iCu68 const4523540f1504cd17100c4835) (let __tconst3qo272 const4ec9599fc203d176a301536c) (let __tconst0Vvk76 const9400f1b21cb527d7fa3d3eab) (let __tconst4b1P80 constf5ca38f748a1d6eaf726b8a4) (let __tconst7Fqh84 const6f4b6612125fb3a0daecd279) (let __tconst9Muz88 const785f3ec7eb32f30b90cd0fcf) (let __tconst0ER892 const535fa30d7e25dd8a49f15367) (let __tconst8Ab396 constc2356069e9d1e79ca9243781) (let __tconst4CTo100 constb7a56873cd771f2c446d369b) (let __tconst6uxh104 const5f9c4ab08cac7457e9111a30) (let __tconst16iF108 const670671cd97404156226e5079) (let __tconst0a0d112 const59e19706d51d39f66711c265) (let __tconst9il5116 const35135aaa6cc23891b40cb3f3) (let __tconst7WQZ120 const624b60c58c9d8bfb6ff1886c) (let __tconst9nQS124 consteb1e33e8a81b697b75855af6) (let __tconst2Rz6128 conste29c9c180c6279b0b02abd6a) (let __tconst1vIN132 constc6f3ac57944a531490cd3990) (let __tconst02kw136 const86e50149658661312a9e0b35) (let __tconst6yfn140 const9f14025af0065b30e47e23eb) (let __tconst9dkW144 const76a50887d8f1c2e930175542) (let __tconst5pM2148 const7a61b53701befdae0eeeffae) (let __tconst7uoa152 constaea92132c4cbeb263e6ac2bf) (let __tconst0Rpe156 const0b918943df0962bc7a1824c0) (let __tconst55rM160 constd59eced1ded07f84c145592f) (let __tconst1UXc164 const3d914f9348c9cc0ff8a79716) (let __tconst0tQI168 const73475cb40a568e8da8a045ce) (let __tconst0lFS172 const44cb730c420480a0477b505a) (let __tconst4Zgh176 const71ee45a3c0db9a9865f7313d) (let __tconst7tvD180 const811786ad1ae74adfdd20dd03) (let __tconst59bW184 const25fc0e7096fc653718202dc3) (let __tconst9vjq188 const31489056e0916d59fe3add79) (let __tconst8R0M192 const98010bd9270f9b100b6214a2) (let __tconst8YyM196 const0e17daca5f3e175f448bacac) (let __tconst9kQR199 const5feceb66ffc86f38d952786c) (let __tconst9GYB200 const1a6562590ef19d1045d06c40)) (once) (body) (head (emit edge (0 1) __tconst9kQR199 __tconst6Rrp4) (emit edge (0 1) __tconst6Rrp4 __tconst9kQR199) (emit edge (0 1) __tconst9kQR199 __tconst7I9S8) (emit edge (0 1) __tconst7I9S8 __tconst9kQR199) (emit edge (0 1) __tconst9kQR199 __tconst2DKk12) (emit edge (0 1) __tconst2DKk12 __tconst9kQR199) (emit edge (0 1) __tconst9kQR199 __tconst4K5f16) (emit edge (0 1) __tconst4K5f16 __tconst9kQR199) (emit edge (0 1) __tconst9kQR199 __tconst8vnl20) (emit edge (0 1) __tconst8vnl20 __tconst9kQR199) (emit edge (0 1) __tconst9kQR199 __tconst4S6B24) (emit edge (0 1) __tconst4S6B24 __tconst9kQR199) (emit edge (0 1) __tconst9kQR199 __tconst5MpT28) (emit edge (0 1) __tconst5MpT28 __tconst9kQR199) (emit edge (0 1) __tconst9kQR199 __tconst4oy732) (emit edge (0 1) __tconst4oy732 __tconst9kQR199) (emit edge (0 1) __tconst9kQR199 __tconst1gcV36) (emit edge (0 1) __tconst1gcV36 __tconst9kQR199) (emit edge (0 1) __tconst9kQR199 __tconst7DvQ40) (emit edge (0 1) __tconst7DvQ40 __tconst9kQR199) (emit edge (0 1) __tconst9kQR199 __tconst0lsV44) (emit edge (0 1) __tconst0lsV44 __tconst9kQR199) (emit edge (0 1) __tconst9kQR199 __tconst8WDD48) (emit edge (0 1) __tconst8WDD48 __tconst9kQR199) (emit edge (0 1) __tconst9kQR199 __tconst9OpU52) (emit edge (0 1) __tconst9OpU52 __tconst9kQR199) (emit edge (0 1) __tconst9kQR199 __tconst7G5Z56) (emit edge (0 1) __tconst7G5Z56 __tconst9kQR199) (emit edge (0 1) __tconst9kQR199 __tconst8OVI60) (emit edge (0 1) __tconst8OVI60 __tconst9kQR199) (emit edge (0 1) __tconst9kQR199 __tconst6PM664) (emit edge (0 1) __tconst6PM664 __tconst9kQR199) (emit edge (0 1) __tconst9kQR199 __tconst3iCu68) (emit edge (0 1) __tconst3iCu68 __tconst9kQR199) (emit edge (0 1) __tconst9kQR199 __tconst3qo272) (emit edge (0 1) __tconst3qo272 __tconst9kQR199) (emit edge (0 1) __tconst9kQR199 __tconst0Vvk76) (emit edge (0 1) __tconst0Vvk76 __tconst9kQR199) (emit edge (0 1) __tconst9kQR199 __tconst4b1P80) (emit edge (0 1) __tconst4b1P80 __tconst9kQR199) (emit edge (0 1) __tconst9kQR199 __tconst7Fqh84) (emit edge (0 1) __tconst7Fqh84 __tconst9kQR199) (emit edge (0 1) __tconst9kQR199 __tconst9Muz88) (emit edge (0 1) __tconst9Muz88 __tconst9kQR199) (emit edge (0 1) __tconst9kQR199 __tconst0ER892) (emit edge (0 1) __tconst0ER892 __tconst9kQR199) (emit edge (0 1) __tconst9kQR199 __tconst8Ab396) (emit edge (0 1) __tconst8Ab396 __tconst9kQR199) (emit edge (0 1) __tconst9kQR199 __tconst4CTo100) (emit edge (0 1) __tconst4CTo100 __tconst9kQR199) (emit edge (0 1) __tconst9kQR199 __tconst6uxh104) (emit edge (0 1) __tconst6uxh104 __tconst9kQR199) (emit edge (0 1) __tconst9kQR199 __tconst16iF108) (emit edge (0 1) __tconst16iF108 __tconst9kQR199) (emit edge (0 1) __tconst9kQR199 __tconst0a0d112) (emit edge (0 1) __tconst0a0d112 __tconst9kQR199) (emit edge (0 1) __tconst9kQR199 __tconst9il5116) (emit edge (0 1) __tconst9il5116 __tconst9kQR199) (emit edge (0 1) __tconst9kQR199 __tconst7WQZ120) (emit edge (0 1) __tconst7WQZ120 __tconst9kQR199) (emit edge (0 1) __tconst9kQR199 __tconst9nQS124) (emit edge (0 1) __tconst9nQS124 __tconst9kQR199) (emit edge (0 1) __tconst9kQR199 __tconst2Rz6128) (emit edge (0 1) __tconst2Rz6128 __tconst9kQR199) (emit edge (0 1) __tconst9kQR199 __tconst1vIN132) (emit edge (0 1) __tconst1vIN132 __tconst9kQR199) (emit edge (0 1) __tconst9kQR199 __tconst02kw136) (emit edge (0 1) __tconst02kw136 __tconst9kQR199) (emit edge (0 1) __tconst9kQR199 __tconst6yfn140) (emit edge (0 1) __tconst6yfn140 __tconst9kQR199) (emit edge (0 1) __tconst9kQR199 __tconst9dkW144) (emit edge (0 1) __tconst9dkW144 __tconst9kQR199) (emit edge (0 1) __tconst9kQR199 __tconst5pM2148) (emit edge (0 1) __tconst5pM2148 __tconst9kQR199) (emit edge (0 1) __tconst9kQR199 __tconst7uoa152) (emit edge (0 1) __tconst7uoa152 __tconst9kQR199) (emit edge (0 1) __tconst9kQR199 __tconst0Rpe156) (emit edge (0 1) __tconst0Rpe156 __tconst9kQR199) (emit edge (0 1) __tconst9kQR199 __tconst55rM160) (emit edge (0 1) __tconst55rM160 __tconst9kQR199) (emit edge (0 1) __tconst9kQR199 __tconst1UXc164) (emit edge (0 1) __tconst1UXc164 __tconst9kQR199) (emit edge (0 1) __tconst9kQR199 __tconst0tQI168) (emit edge (0 1) __tconst0tQI168 __tconst9kQR199) (emit edge (0 1) __tconst9kQR199 __tconst0lFS172) (emit edge (0 1) __tconst0lFS172 __tconst9kQR199) (emit edge (0 1) __tconst9kQR199 __tconst4Zgh176) (emit edge (0 1) __tconst4Zgh176 __tconst9kQR199) (emit edge (0 1) __tconst9kQR199 __tconst7tvD180) (emit edge (0 1) __tconst7tvD180 __tconst9kQR199) (emit edge (0 1) __tconst9kQR199 __tconst59bW184) (emit edge (0 1) __tconst59bW184 __tconst9kQR199) (emit edge (0 1) __tconst9kQR199 __tconst9vjq188) (emit edge (0 1) __tconst9vjq188 __tconst9kQR199) (emit edge (0 1) __tconst9kQR199 __tconst8R0M192) (emit edge (0 1) __tconst8R0M192 __tconst9kQR199) (emit edge (0 1) __tconst9kQR199 __tconst8YyM196) (emit edge (0 1) __tconst8YyM196 __tconst9kQR199) (emit edge (0 1) __tconst9kQR199 __tconst9GYB200) (emit edge (0 1) __tconst9GYB200 __tconst9kQR199)) hub.slog:4 #f)
  class ReadTask0 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[100];
    slog::Index** head_index[100];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("edge");
      std::vector<u16> ord1({0, 1});
      slog::Relation* readrel2 = db->getRelation("edge");
      head_index[0] = readrel2->getIndex(ord1, false);
      head_rel[1] = db->getRelation("edge");
      std::vector<u16> ord3({0, 1});
      slog::Relation* readrel4 = db->getRelation("edge");
      head_index[1] = readrel4->getIndex(ord3, false);
      head_rel[2] = db->getRelation("edge");
      std::vector<u16> ord5({0, 1});
      slog::Relation* readrel6 = db->getRelation("edge");
      head_index[2] = readrel6->getIndex(ord5, false);
      head_rel[3] = db->getRelation("edge");
      std::vector<u16> ord7({0, 1});
      slog::Relation* readrel8 = db->getRelation("edge");
      head_index[3] = readrel8->getIndex(ord7, false);
      head_rel[4] = db->getRelation("edge");
      std::vector<u16> ord9({0, 1});
      slog::Relation* readrel10 = db->getRelation("edge");
      head_index[4] = readrel10->getIndex(ord9, false);
      head_rel[5] = db->getRelation("edge");
      std::vector<u16> ord11({0, 1});
      slog::Relation* readrel12 = db->getRelation("edge");
      head_index[5] = readrel12->getIndex(ord11, false);
      head_rel[6] = db->getRelation("edge");
      std::vector<u16> ord13({0, 1});
      slog::Relation* readrel14 = db->getRelation("edge");
      head_index[6] = readrel14->getIndex(ord13, false);
      head_rel[7] = db->getRelation("edge");
      std::vector<u16> ord15({0, 1});
      slog::Relation* readrel16 = db->getRelation("edge");
      head_index[7] = readrel16->getIndex(ord15, false);
      head_rel[8] = db->getRelation("edge");
      std::vector<u16> ord17({0, 1});
      slog::Relation* readrel18 = db->getRelation("edge");
      head_index[8] = readrel18->getIndex(ord17, false);
      head_rel[9] = db->getRelation("edge");
      std::vector<u16> ord19({0, 1});
      slog::Relation* readrel20 = db->getRelation("edge");
      head_index[9] = readrel20->getIndex(ord19, false);
      head_rel[10] = db->getRelation("edge");
      std::vector<u16> ord21({0, 1});
      slog::Relation* readrel22 = db->getRelation("edge");
      head_index[10] = readrel22->getIndex(ord21, false);
      head_rel[11] = db->getRelation("edge");
      std::vector<u16> ord23({0, 1});
      slog::Relation* readrel24 = db->getRelation("edge");
      head_index[11] = readrel24->getIndex(ord23, false);
      head_rel[12] = db->getRelation("edge");
      std::vector<u16> ord25({0, 1});
      slog::Relation* readrel26 = db->getRelation("edge");
      head_index[12] = readrel26->getIndex(ord25, false);
      head_rel[13] = db->getRelation("edge");
      std::vector<u16> ord27({0, 1});
      slog::Relation* readrel28 = db->getRelation("edge");
      head_index[13] = readrel28->getIndex(ord27, false);
      head_rel[14] = db->getRelation("edge");
      std::vector<u16> ord29({0, 1});
      slog::Relation* readrel30 = db->getRelation("edge");
      head_index[14] = readrel30->getIndex(ord29, false);
      head_rel[15] = db->getRelation("edge");
      std::vector<u16> ord31({0, 1});
      slog::Relation* readrel32 = db->getRelation("edge");
      head_index[15] = readrel32->getIndex(ord31, false);
      head_rel[16] = db->getRelation("edge");
      std::vector<u16> ord33({0, 1});
      slog::Relation* readrel34 = db->getRelation("edge");
      head_index[16] = readrel34->getIndex(ord33, false);
      head_rel[17] = db->getRelation("edge");
      std::vector<u16> ord35({0, 1});
      slog::Relation* readrel36 = db->getRelation("edge");
      head_index[17] = readrel36->getIndex(ord35, false);
      head_rel[18] = db->getRelation("edge");
      std::vector<u16> ord37({0, 1});
      slog::Relation* readrel38 = db->getRelation("edge");
      head_index[18] = readrel38->getIndex(ord37, false);
      head_rel[19] = db->getRelation("edge");
      std::vector<u16> ord39({0, 1});
      slog::Relation* readrel40 = db->getRelation("edge");
      head_index[19] = readrel40->getIndex(ord39, false);
      head_rel[20] = db->getRelation("edge");
      std::vector<u16> ord41({0, 1});
      slog::Relation* readrel42 = db->getRelation("edge");
      head_index[20] = readrel42->getIndex(ord41, false);
      head_rel[21] = db->getRelation("edge");
      std::vector<u16> ord43({0, 1});
      slog::Relation* readrel44 = db->getRelation("edge");
      head_index[21] = readrel44->getIndex(ord43, false);
      head_rel[22] = db->getRelation("edge");
      std::vector<u16> ord45({0, 1});
      slog::Relation* readrel46 = db->getRelation("edge");
      head_index[22] = readrel46->getIndex(ord45, false);
      head_rel[23] = db->getRelation("edge");
      std::vector<u16> ord47({0, 1});
      slog::Relation* readrel48 = db->getRelation("edge");
      head_index[23] = readrel48->getIndex(ord47, false);
      head_rel[24] = db->getRelation("edge");
      std::vector<u16> ord49({0, 1});
      slog::Relation* readrel50 = db->getRelation("edge");
      head_index[24] = readrel50->getIndex(ord49, false);
      head_rel[25] = db->getRelation("edge");
      std::vector<u16> ord51({0, 1});
      slog::Relation* readrel52 = db->getRelation("edge");
      head_index[25] = readrel52->getIndex(ord51, false);
      head_rel[26] = db->getRelation("edge");
      std::vector<u16> ord53({0, 1});
      slog::Relation* readrel54 = db->getRelation("edge");
      head_index[26] = readrel54->getIndex(ord53, false);
      head_rel[27] = db->getRelation("edge");
      std::vector<u16> ord55({0, 1});
      slog::Relation* readrel56 = db->getRelation("edge");
      head_index[27] = readrel56->getIndex(ord55, false);
      head_rel[28] = db->getRelation("edge");
      std::vector<u16> ord57({0, 1});
      slog::Relation* readrel58 = db->getRelation("edge");
      head_index[28] = readrel58->getIndex(ord57, false);
      head_rel[29] = db->getRelation("edge");
      std::vector<u16> ord59({0, 1});
      slog::Relation* readrel60 = db->getRelation("edge");
      head_index[29] = readrel60->getIndex(ord59, false);
      head_rel[30] = db->getRelation("edge");
      std::vector<u16> ord61({0, 1});
      slog::Relation* readrel62 = db->getRelation("edge");
      head_index[30] = readrel62->getIndex(ord61, false);
      head_rel[31] = db->getRelation("edge");
      std::vector<u16> ord63({0, 1});
      slog::Relation* readrel64 = db->getRelation("edge");
      head_index[31] = readrel64->getIndex(ord63, false);
      head_rel[32] = db->getRelation("edge");
      std::vector<u16> ord65({0, 1});
      slog::Relation* readrel66 = db->getRelation("edge");
      head_index[32] = readrel66->getIndex(ord65, false);
      head_rel[33] = db->getRelation("edge");
      std::vector<u16> ord67({0, 1});
      slog::Relation* readrel68 = db->getRelation("edge");
      head_index[33] = readrel68->getIndex(ord67, false);
      head_rel[34] = db->getRelation("edge");
      std::vector<u16> ord69({0, 1});
      slog::Relation* readrel70 = db->getRelation("edge");
      head_index[34] = readrel70->getIndex(ord69, false);
      head_rel[35] = db->getRelation("edge");
      std::vector<u16> ord71({0, 1});
      slog::Relation* readrel72 = db->getRelation("edge");
      head_index[35] = readrel72->getIndex(ord71, false);
      head_rel[36] = db->getRelation("edge");
      std::vector<u16> ord73({0, 1});
      slog::Relation* readrel74 = db->getRelation("edge");
      head_index[36] = readrel74->getIndex(ord73, false);
      head_rel[37] = db->getRelation("edge");
      std::vector<u16> ord75({0, 1});
      slog::Relation* readrel76 = db->getRelation("edge");
      head_index[37] = readrel76->getIndex(ord75, false);
      head_rel[38] = db->getRelation("edge");
      std::vector<u16> ord77({0, 1});
      slog::Relation* readrel78 = db->getRelation("edge");
      head_index[38] = readrel78->getIndex(ord77, false);
      head_rel[39] = db->getRelation("edge");
      std::vector<u16> ord79({0, 1});
      slog::Relation* readrel80 = db->getRelation("edge");
      head_index[39] = readrel80->getIndex(ord79, false);
      head_rel[40] = db->getRelation("edge");
      std::vector<u16> ord81({0, 1});
      slog::Relation* readrel82 = db->getRelation("edge");
      head_index[40] = readrel82->getIndex(ord81, false);
      head_rel[41] = db->getRelation("edge");
      std::vector<u16> ord83({0, 1});
      slog::Relation* readrel84 = db->getRelation("edge");
      head_index[41] = readrel84->getIndex(ord83, false);
      head_rel[42] = db->getRelation("edge");
      std::vector<u16> ord85({0, 1});
      slog::Relation* readrel86 = db->getRelation("edge");
      head_index[42] = readrel86->getIndex(ord85, false);
      head_rel[43] = db->getRelation("edge");
      std::vector<u16> ord87({0, 1});
      slog::Relation* readrel88 = db->getRelation("edge");
      head_index[43] = readrel88->getIndex(ord87, false);
      head_rel[44] = db->getRelation("edge");
      std::vector<u16> ord89({0, 1});
      slog::Relation* readrel90 = db->getRelation("edge");
      head_index[44] = readrel90->getIndex(ord89, false);
      head_rel[45] = db->getRelation("edge");
      std::vector<u16> ord91({0, 1});
      slog::Relation* readrel92 = db->getRelation("edge");
      head_index[45] = readrel92->getIndex(ord91, false);
      head_rel[46] = db->getRelation("edge");
      std::vector<u16> ord93({0, 1});
      slog::Relation* readrel94 = db->getRelation("edge");
      head_index[46] = readrel94->getIndex(ord93, false);
      head_rel[47] = db->getRelation("edge");
      std::vector<u16> ord95({0, 1});
      slog::Relation* readrel96 = db->getRelation("edge");
      head_index[47] = readrel96->getIndex(ord95, false);
      head_rel[48] = db->getRelation("edge");
      std::vector<u16> ord97({0, 1});
      slog::Relation* readrel98 = db->getRelation("edge");
      head_index[48] = readrel98->getIndex(ord97, false);
      head_rel[49] = db->getRelation("edge");
      std::vector<u16> ord99({0, 1});
      slog::Relation* readrel100 = db->getRelation("edge");
      head_index[49] = readrel100->getIndex(ord99, false);
      head_rel[50] = db->getRelation("edge");
      std::vector<u16> ord101({0, 1});
      slog::Relation* readrel102 = db->getRelation("edge");
      head_index[50] = readrel102->getIndex(ord101, false);
      head_rel[51] = db->getRelation("edge");
      std::vector<u16> ord103({0, 1});
      slog::Relation* readrel104 = db->getRelation("edge");
      head_index[51] = readrel104->getIndex(ord103, false);
      head_rel[52] = db->getRelation("edge");
      std::vector<u16> ord105({0, 1});
      slog::Relation* readrel106 = db->getRelation("edge");
      head_index[52] = readrel106->getIndex(ord105, false);
      head_rel[53] = db->getRelation("edge");
      std::vector<u16> ord107({0, 1});
      slog::Relation* readrel108 = db->getRelation("edge");
      head_index[53] = readrel108->getIndex(ord107, false);
      head_rel[54] = db->getRelation("edge");
      std::vector<u16> ord109({0, 1});
      slog::Relation* readrel110 = db->getRelation("edge");
      head_index[54] = readrel110->getIndex(ord109, false);
      head_rel[55] = db->getRelation("edge");
      std::vector<u16> ord111({0, 1});
      slog::Relation* readrel112 = db->getRelation("edge");
      head_index[55] = readrel112->getIndex(ord111, false);
      head_rel[56] = db->getRelation("edge");
      std::vector<u16> ord113({0, 1});
      slog::Relation* readrel114 = db->getRelation("edge");
      head_index[56] = readrel114->getIndex(ord113, false);
      head_rel[57] = db->getRelation("edge");
      std::vector<u16> ord115({0, 1});
      slog::Relation* readrel116 = db->getRelation("edge");
      head_index[57] = readrel116->getIndex(ord115, false);
      head_rel[58] = db->getRelation("edge");
      std::vector<u16> ord117({0, 1});
      slog::Relation* readrel118 = db->getRelation("edge");
      head_index[58] = readrel118->getIndex(ord117, false);
      head_rel[59] = db->getRelation("edge");
      std::vector<u16> ord119({0, 1});
      slog::Relation* readrel120 = db->getRelation("edge");
      head_index[59] = readrel120->getIndex(ord119, false);
      head_rel[60] = db->getRelation("edge");
      std::vector<u16> ord121({0, 1});
      slog::Relation* readrel122 = db->getRelation("edge");
      head_index[60] = readrel122->getIndex(ord121, false);
      head_rel[61] = db->getRelation("edge");
      std::vector<u16> ord123({0, 1});
      slog::Relation* readrel124 = db->getRelation("edge");
      head_index[61] = readrel124->getIndex(ord123, false);
      head_rel[62] = db->getRelation("edge");
      std::vector<u16> ord125({0, 1});
      slog::Relation* readrel126 = db->getRelation("edge");
      head_index[62] = readrel126->getIndex(ord125, false);
      head_rel[63] = db->getRelation("edge");
      std::vector<u16> ord127({0, 1});
      slog::Relation* readrel128 = db->getRelation("edge");
      head_index[63] = readrel128->getIndex(ord127, false);
      head_rel[64] = db->getRelation("edge");
      std::vector<u16> ord129({0, 1});
      slog::Relation* readrel130 = db->getRelation("edge");
      head_index[64] = readrel130->getIndex(ord129, false);
      head_rel[65] = db->getRelation("edge");
      std::vector<u16> ord131({0, 1});
      slog::Relation* readrel132 = db->getRelation("edge");
      head_index[65] = readrel132->getIndex(ord131, false);
      head_rel[66] = db->getRelation("edge");
      std::vector<u16> ord133({0, 1});
      slog::Relation* readrel134 = db->getRelation("edge");
      head_index[66] = readrel134->getIndex(ord133, false);
      head_rel[67] = db->getRelation("edge");
      std::vector<u16> ord135({0, 1});
      slog::Relation* readrel136 = db->getRelation("edge");
      head_index[67] = readrel136->getIndex(ord135, false);
      head_rel[68] = db->getRelation("edge");
      std::vector<u16> ord137({0, 1});
      slog::Relation* readrel138 = db->getRelation("edge");
      head_index[68] = readrel138->getIndex(ord137, false);
      head_rel[69] = db->getRelation("edge");
      std::vector<u16> ord139({0, 1});
      slog::Relation* readrel140 = db->getRelation("edge");
      head_index[69] = readrel140->getIndex(ord139, false);
      head_rel[70] = db->getRelation("edge");
      std::vector<u16> ord141({0, 1});
      slog::Relation* readrel142 = db->getRelation("edge");
      head_index[70] = readrel142->getIndex(ord141, false);
      head_rel[71] = db->getRelation("edge");
      std::vector<u16> ord143({0, 1});
      slog::Relation* readrel144 = db->getRelation("edge");
      head_index[71] = readrel144->getIndex(ord143, false);
      head_rel[72] = db->getRelation("edge");
      std::vector<u16> ord145({0, 1});
      slog::Relation* readrel146 = db->getRelation("edge");
      head_index[72] = readrel146->getIndex(ord145, false);
      head_rel[73] = db->getRelation("edge");
      std::vector<u16> ord147({0, 1});
      slog::Relation* readrel148 = db->getRelation("edge");
      head_index[73] = readrel148->getIndex(ord147, false);
      head_rel[74] = db->getRelation("edge");
      std::vector<u16> ord149({0, 1});
      slog::Relation* readrel150 = db->getRelation("edge");
      head_index[74] = readrel150->getIndex(ord149, false);
      head_rel[75] = db->getRelation("edge");
      std::vector<u16> ord151({0, 1});
      slog::Relation* readrel152 = db->getRelation("edge");
      head_index[75] = readrel152->getIndex(ord151, false);
      head_rel[76] = db->getRelation("edge");
      std::vector<u16> ord153({0, 1});
      slog::Relation* readrel154 = db->getRelation("edge");
      head_index[76] = readrel154->getIndex(ord153, false);
      head_rel[77] = db->getRelation("edge");
      std::vector<u16> ord155({0, 1});
      slog::Relation* readrel156 = db->getRelation("edge");
      head_index[77] = readrel156->getIndex(ord155, false);
      head_rel[78] = db->getRelation("edge");
      std::vector<u16> ord157({0, 1});
      slog::Relation* readrel158 = db->getRelation("edge");
      head_index[78] = readrel158->getIndex(ord157, false);
      head_rel[79] = db->getRelation("edge");
      std::vector<u16> ord159({0, 1});
      slog::Relation* readrel160 = db->getRelation("edge");
      head_index[79] = readrel160->getIndex(ord159, false);
      head_rel[80] = db->getRelation("edge");
      std::vector<u16> ord161({0, 1});
      slog::Relation* readrel162 = db->getRelation("edge");
      head_index[80] = readrel162->getIndex(ord161, false);
      head_rel[81] = db->getRelation("edge");
      std::vector<u16> ord163({0, 1});
      slog::Relation* readrel164 = db->getRelation("edge");
      head_index[81] = readrel164->getIndex(ord163, false);
      head_rel[82] = db->getRelation("edge");
      std::vector<u16> ord165({0, 1});
      slog::Relation* readrel166 = db->getRelation("edge");
      head_index[82] = readrel166->getIndex(ord165, false);
      head_rel[83] = db->getRelation("edge");
      std::vector<u16> ord167({0, 1});
      slog::Relation* readrel168 = db->getRelation("edge");
      head_index[83] = readrel168->getIndex(ord167, false);
      head_rel[84] = db->getRelation("edge");
      std::vector<u16> ord169({0, 1});
      slog::Relation* readrel170 = db->getRelation("edge");
      head_index[84] = readrel170->getIndex(ord169, false);
      head_rel[85] = db->getRelation("edge");
      std::vector<u16> ord171({0, 1});
      slog::Relation* readrel172 = db->getRelation("edge");
      head_index[85] = readrel172->getIndex(ord171, false);
      head_rel[86] = db->getRelation("edge");
      std::vector<u16> ord173({0, 1});
      slog::Relation* readrel174 = db->getRelation("edge");
      head_index[86] = readrel174->getIndex(ord173, false);
      head_rel[87] = db->getRelation("edge");
      std::vector<u16> ord175({0, 1});
      slog::Relation* readrel176 = db->getRelation("edge");
      head_index[87] = readrel176->getIndex(ord175, false);
      head_rel[88] = db->getRelation("edge");
      std::vector<u16> ord177({0, 1});
      slog::Relation* readrel178 = db->getRelation("edge");
      head_index[88] = readrel178->getIndex(ord177, false);
      head_rel[89] = db->getRelation("edge");
      std::vector<u16> ord179({0, 1});
      slog::Relation* readrel180 = db->getRelation("edge");
      head_index[89] = readrel180->getIndex(ord179, false);
      head_rel[90] = db->getRelation("edge");
      std::vector<u16> ord181({0, 1});
      slog::Relation* readrel182 = db->getRelation("edge");
      head_index[90] = readrel182->getIndex(ord181, false);
      head_rel[91] = db->getRelation("edge");
      std::vector<u16> ord183({0, 1});
      slog::Relation* readrel184 = db->getRelation("edge");
      head_index[91] = readrel184->getIndex(ord183, false);
      head_rel[92] = db->getRelation("edge");
      std::vector<u16> ord185({0, 1});
      slog::Relation* readrel186 = db->getRelation("edge");
      head_index[92] = readrel186->getIndex(ord185, false);
      head_rel[93] = db->getRelation("edge");
      std::vector<u16> ord187({0, 1});
      slog::Relation* readrel188 = db->getRelation("edge");
      head_index[93] = readrel188->getIndex(ord187, false);
      head_rel[94] = db->getRelation("edge");
      std::vector<u16> ord189({0, 1});
      slog::Relation* readrel190 = db->getRelation("edge");
      head_index[94] = readrel190->getIndex(ord189, false);
      head_rel[95] = db->getRelation("edge");
      std::vector<u16> ord191({0, 1});
      slog::Relation* readrel192 = db->getRelation("edge");
      head_index[95] = readrel192->getIndex(ord191, false);
      head_rel[96] = db->getRelation("edge");
      std::vector<u16> ord193({0, 1});
      slog::Relation* readrel194 = db->getRelation("edge");
      head_index[96] = readrel194->getIndex(ord193, false);
      head_rel[97] = db->getRelation("edge");
      std::vector<u16> ord195({0, 1});
      slog::Relation* readrel196 = db->getRelation("edge");
      head_index[97] = readrel196->getIndex(ord195, false);
      head_rel[98] = db->getRelation("edge");
      std::vector<u16> ord197({0, 1});
      slog::Relation* readrel198 = db->getRelation("edge");
      head_index[98] = readrel198->getIndex(ord197, false);
      head_rel[99] = db->getRelation("edge");
      std::vector<u16> ord199({0, 1});
      slog::Relation* readrel200 = db->getRelation("edge");
      head_index[99] = readrel200->getIndex(ord199, false);
  
    }
    ReadTask0(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c1 = v_constd4735e3a265e16eee03f5971;
      u64 v_c2 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c3 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c4 = v_constef2d127de37b942baad06145;
      u64 v_c5 = v_conste7f6c011776e8db7cd330b54;
      u64 v_c6 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c7 = v_const2c624232cdd221771294dfbb;
      u64 v_c8 = v_const19581e27de7ced00ff1ce50b;
      u64 v_c9 = v_const4a44dc15364204a80fe80e90;
      u64 v_c10 = v_const4fc82b26aecb47d2868c4efb;
      u64 v_c11 = v_const6b51d431df5d7f141cbececc;
      u64 v_c12 = v_const3fdba35f04dc8c462986c992;
      u64 v_c13 = v_const8527a891e224136950ff32ca;
      u64 v_c14 = v_conste629fa6598d732768f7c726b;
      u64 v_c15 = v_constb17ef6d19c7a5b1ee83b907c;
      u64 v_c16 = v_const4523540f1504cd17100c4835;
      u64 v_c17 = v_const4ec9599fc203d176a301536c;
      u64 v_c18 = v_const9400f1b21cb527d7fa3d3eab;
      u64 v_c19 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c20 = v_const6f4b6612125fb3a0daecd279;
      u64 v_c21 = v_const785f3ec7eb32f30b90cd0fcf;
      u64 v_c22 = v_const535fa30d7e25dd8a49f15367;
      u64 v_c23 = v_constc2356069e9d1e79ca9243781;
      u64 v_c24 = v_constb7a56873cd771f2c446d369b;
      u64 v_c25 = v_const5f9c4ab08cac7457e9111a30;
      u64 v_c26 = v_const670671cd97404156226e5079;
      u64 v_c27 = v_const59e19706d51d39f66711c265;
      u64 v_c28 = v_const35135aaa6cc23891b40cb3f3;
      u64 v_c29 = v_const624b60c58c9d8bfb6ff1886c;
      u64 v_c30 = v_consteb1e33e8a81b697b75855af6;
      u64 v_c31 = v_conste29c9c180c6279b0b02abd6a;
      u64 v_c32 = v_constc6f3ac57944a531490cd3990;
      u64 v_c33 = v_const86e50149658661312a9e0b35;
      u64 v_c34 = v_const9f14025af0065b30e47e23eb;
      u64 v_c35 = v_const76a50887d8f1c2e930175542;
      u64 v_c36 = v_const7a61b53701befdae0eeeffae;
      u64 v_c37 = v_constaea92132c4cbeb263e6ac2bf;
      u64 v_c38 = v_const0b918943df0962bc7a1824c0;
      u64 v_c39 = v_constd59eced1ded07f84c145592f;
      u64 v_c40 = v_const3d914f9348c9cc0ff8a79716;
      u64 v_c41 = v_const73475cb40a568e8da8a045ce;
      u64 v_c42 = v_const44cb730c420480a0477b505a;
      u64 v_c43 = v_const71ee45a3c0db9a9865f7313d;
      u64 v_c44 = v_const811786ad1ae74adfdd20dd03;
      u64 v_c45 = v_const25fc0e7096fc653718202dc3;
      u64 v_c46 = v_const31489056e0916d59fe3add79;
      u64 v_c47 = v_const98010bd9270f9b100b6214a2;
      u64 v_c48 = v_const0e17daca5f3e175f448bacac;
      u64 v_c49 = v_const5feceb66ffc86f38d952786c;
      u64 v_c50 = v_const1a6562590ef19d1045d06c40;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[100];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
      newbatch[4] = new slog::InsertBatch();
      newbatch[5] = new slog::InsertBatch();
      newbatch[6] = new slog::InsertBatch();
      newbatch[7] = new slog::InsertBatch();
      newbatch[8] = new slog::InsertBatch();
      newbatch[9] = new slog::InsertBatch();
      newbatch[10] = new slog::InsertBatch();
      newbatch[11] = new slog::InsertBatch();
      newbatch[12] = new slog::InsertBatch();
      newbatch[13] = new slog::InsertBatch();
      newbatch[14] = new slog::InsertBatch();
      newbatch[15] = new slog::InsertBatch();
      newbatch[16] = new slog::InsertBatch();
      newbatch[17] = new slog::InsertBatch();
      newbatch[18] = new slog::InsertBatch();
      newbatch[19] = new slog::InsertBatch();
      newbatch[20] = new slog::InsertBatch();
      newbatch[21] = new slog::InsertBatch();
      newbatch[22] = new slog::InsertBatch();
      newbatch[23] = new slog::InsertBatch();
      newbatch[24] = new slog::InsertBatch();
      newbatch[25] = new slog::InsertBatch();
      newbatch[26] = new slog::InsertBatch();
      newbatch[27] = new slog::InsertBatch();
      newbatch[28] = new slog::InsertBatch();
      newbatch[29] = new slog::InsertBatch();
      newbatch[30] = new slog::InsertBatch();
      newbatch[31] = new slog::InsertBatch();
      newbatch[32] = new slog::InsertBatch();
      newbatch[33] = new slog::InsertBatch();
      newbatch[34] = new slog::InsertBatch();
      newbatch[35] = new slog::InsertBatch();
      newbatch[36] = new slog::InsertBatch();
      newbatch[37] = new slog::InsertBatch();
      newbatch[38] = new slog::InsertBatch();
      newbatch[39] = new slog::InsertBatch();
      newbatch[40] = new slog::InsertBatch();
      newbatch[41] = new slog::InsertBatch();
      newbatch[42] = new slog::InsertBatch();
      newbatch[43] = new slog::InsertBatch();
      newbatch[44] = new slog::InsertBatch();
      newbatch[45] = new slog::InsertBatch();
      newbatch[46] = new slog::InsertBatch();
      newbatch[47] = new slog::InsertBatch();
      newbatch[48] = new slog::InsertBatch();
      newbatch[49] = new slog::InsertBatch();
      newbatch[50] = new slog::InsertBatch();
      newbatch[51] = new slog::InsertBatch();
      newbatch[52] = new slog::InsertBatch();
      newbatch[53] = new slog::InsertBatch();
      newbatch[54] = new slog::InsertBatch();
      newbatch[55] = new slog::InsertBatch();
      newbatch[56] = new slog::InsertBatch();
      newbatch[57] = new slog::InsertBatch();
      newbatch[58] = new slog::InsertBatch();
      newbatch[59] = new slog::InsertBatch();
      newbatch[60] = new slog::InsertBatch();
      newbatch[61] = new slog::InsertBatch();
      newbatch[62] = new slog::InsertBatch();
      newbatch[63] = new slog::InsertBatch();
      newbatch[64] = new slog::InsertBatch();
      newbatch[65] = new slog::InsertBatch();
      newbatch[66] = new slog::InsertBatch();
      newbatch[67] = new slog::InsertBatch();
      newbatch[68] = new slog::InsertBatch();
      newbatch[69] = new slog::InsertBatch();
      newbatch[70] = new slog::InsertBatch();
      newbatch[71] = new slog::InsertBatch();
      newbatch[72] = new slog::InsertBatch();
      newbatch[73] = new slog::InsertBatch();
      newbatch[74] = new slog::InsertBatch();
      newbatch[75] = new slog::InsertBatch();
      newbatch[76] = new slog::InsertBatch();
      newbatch[77] = new slog::InsertBatch();
      newbatch[78] = new slog::InsertBatch();
      newbatch[79] = new slog::InsertBatch();
      newbatch[80] = new slog::InsertBatch();
      newbatch[81] = new slog::InsertBatch();
      newbatch[82] = new slog::InsertBatch();
      newbatch[83] = new slog::InsertBatch();
      newbatch[84] = new slog::InsertBatch();
      newbatch[85] = new slog::InsertBatch();
      newbatch[86] = new slog::InsertBatch();
      newbatch[87] = new slog::InsertBatch();
      newbatch[88] = new slog::InsertBatch();
      newbatch[89] = new slog::InsertBatch();
      newbatch[90] = new slog::InsertBatch();
      newbatch[91] = new slog::InsertBatch();
      newbatch[92] = new slog::InsertBatch();
      newbatch[93] = new slog::InsertBatch();
      newbatch[94] = new slog::InsertBatch();
      newbatch[95] = new slog::InsertBatch();
      newbatch[96] = new slog::InsertBatch();
      newbatch[97] = new slog::InsertBatch();
      newbatch[98] = new slog::InsertBatch();
      newbatch[99] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c49, v_c0}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c0, v_c49}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[2], head_index[2], newbatch[2], std::array<u64,2>{v_c49, v_c1}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[3], head_index[3], newbatch[3], std::array<u64,2>{v_c1, v_c49}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[4], head_index[4], newbatch[4], std::array<u64,2>{v_c49, v_c2}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[5], head_index[5], newbatch[5], std::array<u64,2>{v_c2, v_c49}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[6], head_index[6], newbatch[6], std::array<u64,2>{v_c49, v_c3}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[7], head_index[7], newbatch[7], std::array<u64,2>{v_c3, v_c49}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[8], head_index[8], newbatch[8], std::array<u64,2>{v_c49, v_c4}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[9], head_index[9], newbatch[9], std::array<u64,2>{v_c4, v_c49}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[10], head_index[10], newbatch[10], std::array<u64,2>{v_c49, v_c5}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[11], head_index[11], newbatch[11], std::array<u64,2>{v_c5, v_c49}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[12], head_index[12], newbatch[12], std::array<u64,2>{v_c49, v_c6}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[13], head_index[13], newbatch[13], std::array<u64,2>{v_c6, v_c49}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[14], head_index[14], newbatch[14], std::array<u64,2>{v_c49, v_c7}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[15], head_index[15], newbatch[15], std::array<u64,2>{v_c7, v_c49}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[16], head_index[16], newbatch[16], std::array<u64,2>{v_c49, v_c8}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[17], head_index[17], newbatch[17], std::array<u64,2>{v_c8, v_c49}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[18], head_index[18], newbatch[18], std::array<u64,2>{v_c49, v_c9}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[19], head_index[19], newbatch[19], std::array<u64,2>{v_c9, v_c49}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[20], head_index[20], newbatch[20], std::array<u64,2>{v_c49, v_c10}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[21], head_index[21], newbatch[21], std::array<u64,2>{v_c10, v_c49}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[22], head_index[22], newbatch[22], std::array<u64,2>{v_c49, v_c11}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[23], head_index[23], newbatch[23], std::array<u64,2>{v_c11, v_c49}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[24], head_index[24], newbatch[24], std::array<u64,2>{v_c49, v_c12}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[25], head_index[25], newbatch[25], std::array<u64,2>{v_c12, v_c49}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[26], head_index[26], newbatch[26], std::array<u64,2>{v_c49, v_c13}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[27], head_index[27], newbatch[27], std::array<u64,2>{v_c13, v_c49}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[28], head_index[28], newbatch[28], std::array<u64,2>{v_c49, v_c14}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[29], head_index[29], newbatch[29], std::array<u64,2>{v_c14, v_c49}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[30], head_index[30], newbatch[30], std::array<u64,2>{v_c49, v_c15}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[31], head_index[31], newbatch[31], std::array<u64,2>{v_c15, v_c49}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[32], head_index[32], newbatch[32], std::array<u64,2>{v_c49, v_c16}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[33], head_index[33], newbatch[33], std::array<u64,2>{v_c16, v_c49}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[34], head_index[34], newbatch[34], std::array<u64,2>{v_c49, v_c17}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[35], head_index[35], newbatch[35], std::array<u64,2>{v_c17, v_c49}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[36], head_index[36], newbatch[36], std::array<u64,2>{v_c49, v_c18}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[37], head_index[37], newbatch[37], std::array<u64,2>{v_c18, v_c49}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[38], head_index[38], newbatch[38], std::array<u64,2>{v_c49, v_c19}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[39], head_index[39], newbatch[39], std::array<u64,2>{v_c19, v_c49}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[40], head_index[40], newbatch[40], std::array<u64,2>{v_c49, v_c20}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[41], head_index[41], newbatch[41], std::array<u64,2>{v_c20, v_c49}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[42], head_index[42], newbatch[42], std::array<u64,2>{v_c49, v_c21}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[43], head_index[43], newbatch[43], std::array<u64,2>{v_c21, v_c49}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[44], head_index[44], newbatch[44], std::array<u64,2>{v_c49, v_c22}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[45], head_index[45], newbatch[45], std::array<u64,2>{v_c22, v_c49}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[46], head_index[46], newbatch[46], std::array<u64,2>{v_c49, v_c23}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[47], head_index[47], newbatch[47], std::array<u64,2>{v_c23, v_c49}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[48], head_index[48], newbatch[48], std::array<u64,2>{v_c49, v_c24}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[49], head_index[49], newbatch[49], std::array<u64,2>{v_c24, v_c49}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[50], head_index[50], newbatch[50], std::array<u64,2>{v_c49, v_c25}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[51], head_index[51], newbatch[51], std::array<u64,2>{v_c25, v_c49}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[52], head_index[52], newbatch[52], std::array<u64,2>{v_c49, v_c26}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[53], head_index[53], newbatch[53], std::array<u64,2>{v_c26, v_c49}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[54], head_index[54], newbatch[54], std::array<u64,2>{v_c49, v_c27}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[55], head_index[55], newbatch[55], std::array<u64,2>{v_c27, v_c49}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[56], head_index[56], newbatch[56], std::array<u64,2>{v_c49, v_c28}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[57], head_index[57], newbatch[57], std::array<u64,2>{v_c28, v_c49}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[58], head_index[58], newbatch[58], std::array<u64,2>{v_c49, v_c29}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[59], head_index[59], newbatch[59], std::array<u64,2>{v_c29, v_c49}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[60], head_index[60], newbatch[60], std::array<u64,2>{v_c49, v_c30}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[61], head_index[61], newbatch[61], std::array<u64,2>{v_c30, v_c49}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[62], head_index[62], newbatch[62], std::array<u64,2>{v_c49, v_c31}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[63], head_index[63], newbatch[63], std::array<u64,2>{v_c31, v_c49}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[64], head_index[64], newbatch[64], std::array<u64,2>{v_c49, v_c32}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[65], head_index[65], newbatch[65], std::array<u64,2>{v_c32, v_c49}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[66], head_index[66], newbatch[66], std::array<u64,2>{v_c49, v_c33}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[67], head_index[67], newbatch[67], std::array<u64,2>{v_c33, v_c49}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[68], head_index[68], newbatch[68], std::array<u64,2>{v_c49, v_c34}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[69], head_index[69], newbatch[69], std::array<u64,2>{v_c34, v_c49}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[70], head_index[70], newbatch[70], std::array<u64,2>{v_c49, v_c35}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[71], head_index[71], newbatch[71], std::array<u64,2>{v_c35, v_c49}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[72], head_index[72], newbatch[72], std::array<u64,2>{v_c49, v_c36}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[73], head_index[73], newbatch[73], std::array<u64,2>{v_c36, v_c49}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[74], head_index[74], newbatch[74], std::array<u64,2>{v_c49, v_c37}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[75], head_index[75], newbatch[75], std::array<u64,2>{v_c37, v_c49}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[76], head_index[76], newbatch[76], std::array<u64,2>{v_c49, v_c38}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[77], head_index[77], newbatch[77], std::array<u64,2>{v_c38, v_c49}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[78], head_index[78], newbatch[78], std::array<u64,2>{v_c49, v_c39}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[79], head_index[79], newbatch[79], std::array<u64,2>{v_c39, v_c49}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[80], head_index[80], newbatch[80], std::array<u64,2>{v_c49, v_c40}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[81], head_index[81], newbatch[81], std::array<u64,2>{v_c40, v_c49}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[82], head_index[82], newbatch[82], std::array<u64,2>{v_c49, v_c41}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[83], head_index[83], newbatch[83], std::array<u64,2>{v_c41, v_c49}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[84], head_index[84], newbatch[84], std::array<u64,2>{v_c49, v_c42}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[85], head_index[85], newbatch[85], std::array<u64,2>{v_c42, v_c49}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[86], head_index[86], newbatch[86], std::array<u64,2>{v_c49, v_c43}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[87], head_index[87], newbatch[87], std::array<u64,2>{v_c43, v_c49}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[88], head_index[88], newbatch[88], std::array<u64,2>{v_c49, v_c44}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[89], head_index[89], newbatch[89], std::array<u64,2>{v_c44, v_c49}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[90], head_index[90], newbatch[90], std::array<u64,2>{v_c49, v_c45}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[91], head_index[91], newbatch[91], std::array<u64,2>{v_c45, v_c49}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[92], head_index[92], newbatch[92], std::array<u64,2>{v_c49, v_c46}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[93], head_index[93], newbatch[93], std::array<u64,2>{v_c46, v_c49}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[94], head_index[94], newbatch[94], std::array<u64,2>{v_c49, v_c47}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[95], head_index[95], newbatch[95], std::array<u64,2>{v_c47, v_c49}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[96], head_index[96], newbatch[96], std::array<u64,2>{v_c49, v_c48}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[97], head_index[97], newbatch[97], std::array<u64,2>{v_c48, v_c49}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[98], head_index[98], newbatch[98], std::array<u64,2>{v_c49, v_c50}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[99], head_index[99], newbatch[99], std::array<u64,2>{v_c50, v_c49}, std::array<u16,2>{0, 1});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
        head_rel[5]->sendBatch(newbatch[5]);
        head_rel[6]->sendBatch(newbatch[6]);
        head_rel[7]->sendBatch(newbatch[7]);
        head_rel[8]->sendBatch(newbatch[8]);
        head_rel[9]->sendBatch(newbatch[9]);
        head_rel[10]->sendBatch(newbatch[10]);
        head_rel[11]->sendBatch(newbatch[11]);
        head_rel[12]->sendBatch(newbatch[12]);
        head_rel[13]->sendBatch(newbatch[13]);
        head_rel[14]->sendBatch(newbatch[14]);
        head_rel[15]->sendBatch(newbatch[15]);
        head_rel[16]->sendBatch(newbatch[16]);
        head_rel[17]->sendBatch(newbatch[17]);
        head_rel[18]->sendBatch(newbatch[18]);
        head_rel[19]->sendBatch(newbatch[19]);
        head_rel[20]->sendBatch(newbatch[20]);
        head_rel[21]->sendBatch(newbatch[21]);
        head_rel[22]->sendBatch(newbatch[22]);
        head_rel[23]->sendBatch(newbatch[23]);
        head_rel[24]->sendBatch(newbatch[24]);
        head_rel[25]->sendBatch(newbatch[25]);
        head_rel[26]->sendBatch(newbatch[26]);
        head_rel[27]->sendBatch(newbatch[27]);
        head_rel[28]->sendBatch(newbatch[28]);
        head_rel[29]->sendBatch(newbatch[29]);
        head_rel[30]->sendBatch(newbatch[30]);
        head_rel[31]->sendBatch(newbatch[31]);
        head_rel[32]->sendBatch(newbatch[32]);
        head_rel[33]->sendBatch(newbatch[33]);
        head_rel[34]->sendBatch(newbatch[34]);
        head_rel[35]->sendBatch(newbatch[35]);
        head_rel[36]->sendBatch(newbatch[36]);
        head_rel[37]->sendBatch(newbatch[37]);
        head_rel[38]->sendBatch(newbatch[38]);
        head_rel[39]->sendBatch(newbatch[39]);
        head_rel[40]->sendBatch(newbatch[40]);
        head_rel[41]->sendBatch(newbatch[41]);
        head_rel[42]->sendBatch(newbatch[42]);
        head_rel[43]->sendBatch(newbatch[43]);
        head_rel[44]->sendBatch(newbatch[44]);
        head_rel[45]->sendBatch(newbatch[45]);
        head_rel[46]->sendBatch(newbatch[46]);
        head_rel[47]->sendBatch(newbatch[47]);
        head_rel[48]->sendBatch(newbatch[48]);
        head_rel[49]->sendBatch(newbatch[49]);
        head_rel[50]->sendBatch(newbatch[50]);
        head_rel[51]->sendBatch(newbatch[51]);
        head_rel[52]->sendBatch(newbatch[52]);
        head_rel[53]->sendBatch(newbatch[53]);
        head_rel[54]->sendBatch(newbatch[54]);
        head_rel[55]->sendBatch(newbatch[55]);
        head_rel[56]->sendBatch(newbatch[56]);
        head_rel[57]->sendBatch(newbatch[57]);
        head_rel[58]->sendBatch(newbatch[58]);
        head_rel[59]->sendBatch(newbatch[59]);
        head_rel[60]->sendBatch(newbatch[60]);
        head_rel[61]->sendBatch(newbatch[61]);
        head_rel[62]->sendBatch(newbatch[62]);
        head_rel[63]->sendBatch(newbatch[63]);
        head_rel[64]->sendBatch(newbatch[64]);
        head_rel[65]->sendBatch(newbatch[65]);
        head_rel[66]->sendBatch(newbatch[66]);
        head_rel[67]->sendBatch(newbatch[67]);
        head_rel[68]->sendBatch(newbatch[68]);
        head_rel[69]->sendBatch(newbatch[69]);
        head_rel[70]->sendBatch(newbatch[70]);
        head_rel[71]->sendBatch(newbatch[71]);
        head_rel[72]->sendBatch(newbatch[72]);
        head_rel[73]->sendBatch(newbatch[73]);
        head_rel[74]->sendBatch(newbatch[74]);
        head_rel[75]->sendBatch(newbatch[75]);
        head_rel[76]->sendBatch(newbatch[76]);
        head_rel[77]->sendBatch(newbatch[77]);
        head_rel[78]->sendBatch(newbatch[78]);
        head_rel[79]->sendBatch(newbatch[79]);
        head_rel[80]->sendBatch(newbatch[80]);
        head_rel[81]->sendBatch(newbatch[81]);
        head_rel[82]->sendBatch(newbatch[82]);
        head_rel[83]->sendBatch(newbatch[83]);
        head_rel[84]->sendBatch(newbatch[84]);
        head_rel[85]->sendBatch(newbatch[85]);
        head_rel[86]->sendBatch(newbatch[86]);
        head_rel[87]->sendBatch(newbatch[87]);
        head_rel[88]->sendBatch(newbatch[88]);
        head_rel[89]->sendBatch(newbatch[89]);
        head_rel[90]->sendBatch(newbatch[90]);
        head_rel[91]->sendBatch(newbatch[91]);
        head_rel[92]->sendBatch(newbatch[92]);
        head_rel[93]->sendBatch(newbatch[93]);
        head_rel[94]->sendBatch(newbatch[94]);
        head_rel[95]->sendBatch(newbatch[95]);
        head_rel[96]->sendBatch(newbatch[96]);
        head_rel[97]->sendBatch(newbatch[97]);
        head_rel[98]->sendBatch(newbatch[98]);
        head_rel[99]->sendBatch(newbatch[99]);
  
      if (_fires) db->bumpFires("hub.slog:4", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask0(db,b), true);
  s->addDynamicRel("edge");
  d->push(s);
  d->continueRun();
}

