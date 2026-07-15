
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_constb17ef6d19c7a5b1ee83b907c;
u64 v_conste29c9c180c6279b0b02abd6a;
u64 v_const6b86b273ff34fce19d6b804e;
u64 v_const4523540f1504cd17100c4835;
u64 v_constd4735e3a265e16eee03f5971;
u64 v_const4ec9599fc203d176a301536c;
u64 v_const4e07408562bedb8b60ce05c1;
u64 v_const9400f1b21cb527d7fa3d3eab;
u64 v_const4b227777d4dd1fc61c6f884f;
u64 v_constf5ca38f748a1d6eaf726b8a4;
u64 v_constef2d127de37b942baad06145;
u64 v_const6f4b6612125fb3a0daecd279;
u64 v_conste7f6c011776e8db7cd330b54;
u64 v_const785f3ec7eb32f30b90cd0fcf;
u64 v_const7902699be42c8a8e46fbbb45;
u64 v_const535fa30d7e25dd8a49f15367;
u64 v_const2c624232cdd221771294dfbb;
u64 v_constc2356069e9d1e79ca9243781;
u64 v_const19581e27de7ced00ff1ce50b;
u64 v_constb7a56873cd771f2c446d369b;
u64 v_const4a44dc15364204a80fe80e90;
u64 v_const5f9c4ab08cac7457e9111a30;
u64 v_const4fc82b26aecb47d2868c4efb;
u64 v_const670671cd97404156226e5079;
u64 v_const6b51d431df5d7f141cbececc;
u64 v_const59e19706d51d39f66711c265;
u64 v_const3fdba35f04dc8c462986c992;
u64 v_const35135aaa6cc23891b40cb3f3;
u64 v_const8527a891e224136950ff32ca;
u64 v_const624b60c58c9d8bfb6ff1886c;
u64 v_conste629fa6598d732768f7c726b;
u64 v_consteb1e33e8a81b697b75855af6;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("25f234d6");
  if (s == nullptr) return;
  slog::Relation* r;
  v_constb17ef6d19c7a5b1ee83b907c = s32_encode(16);
  v_conste29c9c180c6279b0b02abd6a = s32_encode(32);
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  v_const4523540f1504cd17100c4835 = s32_encode(17);
  v_constd4735e3a265e16eee03f5971 = s32_encode(2);
  v_const4ec9599fc203d176a301536c = s32_encode(18);
  v_const4e07408562bedb8b60ce05c1 = s32_encode(3);
  v_const9400f1b21cb527d7fa3d3eab = s32_encode(19);
  v_const4b227777d4dd1fc61c6f884f = s32_encode(4);
  v_constf5ca38f748a1d6eaf726b8a4 = s32_encode(20);
  v_constef2d127de37b942baad06145 = s32_encode(5);
  v_const6f4b6612125fb3a0daecd279 = s32_encode(21);
  v_conste7f6c011776e8db7cd330b54 = s32_encode(6);
  v_const785f3ec7eb32f30b90cd0fcf = s32_encode(22);
  v_const7902699be42c8a8e46fbbb45 = s32_encode(7);
  v_const535fa30d7e25dd8a49f15367 = s32_encode(23);
  v_const2c624232cdd221771294dfbb = s32_encode(8);
  v_constc2356069e9d1e79ca9243781 = s32_encode(24);
  v_const19581e27de7ced00ff1ce50b = s32_encode(9);
  v_constb7a56873cd771f2c446d369b = s32_encode(25);
  v_const4a44dc15364204a80fe80e90 = s32_encode(10);
  v_const5f9c4ab08cac7457e9111a30 = s32_encode(26);
  v_const4fc82b26aecb47d2868c4efb = s32_encode(11);
  v_const670671cd97404156226e5079 = s32_encode(27);
  v_const6b51d431df5d7f141cbececc = s32_encode(12);
  v_const59e19706d51d39f66711c265 = s32_encode(28);
  v_const3fdba35f04dc8c462986c992 = s32_encode(13);
  v_const35135aaa6cc23891b40cb3f3 = s32_encode(29);
  v_const8527a891e224136950ff32ca = s32_encode(14);
  v_const624b60c58c9d8bfb6ff1886c = s32_encode(30);
  v_conste629fa6598d732768f7c726b = s32_encode(15);
  v_consteb1e33e8a81b697b75855af6 = s32_encode(31);
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord4414({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord4414, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord4415({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord4415, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord4416({1, 2, 0});
    
    r->addIndex<3>(ord4416, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord4417({0, 1, 2});
    
    r->addIndex<3>(ord4417, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("t");
  if (r == 0) db->addRelation("t", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("t");
      std::vector<u16> ord4418({0});
    
    r->addIndex<1>(ord4418, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("t"), std::array<u16,1>{0}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord4419({1, 2, 0});
    
    r->addIndex<3>(ord4419, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord4420({0, 1, 2});
    
    r->addIndex<3>(ord4420, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord4421({1, 2, 3, 0});
    
    r->addIndex<4>(ord4421, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord4422({0, 1, 2, 3});
    
    r->addIndex<4>(ord4422, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord4423({1, 2, 0});
    
    r->addIndex<3>(ord4423, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord4424({0, 1, 2});
    
    r->addIndex<3>(ord4424, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord4425({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord4425, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord4426({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord4426, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord4427({1, 2, 0});
    
    r->addIndex<3>(ord4427, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord4428({0, 1, 2});
    
    r->addIndex<3>(ord4428, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord4429({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord4429, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord4430({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord4430, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord4431({1, 2, 3, 0});
    
    r->addIndex<4>(ord4431, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord4432({0, 1, 2, 3});
    
    r->addIndex<4>(ord4432, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord4433({0});
    
    r->addIndex<1>(ord4433, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord4434({1, 2, 0});
    
    r->addIndex<3>(ord4434, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord4435({0, 1, 2});
    
    r->addIndex<3>(ord4435, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("corners");
  if (r == 0) db->addRelation("corners", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("corners");
      std::vector<u16> ord4436({0, 1});
    
    r->addIndex<2>(ord4436, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("corners"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord4437({1, 0});
    
    r->addIndex<2>(ord4437, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord4438({0, 1});
    
    r->addIndex<2>(ord4438, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("Nd");
  if (r == 0) db->addStruct("Nd", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("Nd");
      std::vector<u16> ord4439({2, 1, 0});
    
    r->addIndex<3>(ord4439, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 1, 0}, false, b), true);
      std::vector<u16> ord4440({0, 2, 1});
    
    r->addIndex<3>(ord4440, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 2, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("Nd"), std::array<u16,3>{2, 1, 0}, b));
  r = db->getRelation("Lf");
  if (r == 0) db->addStruct("Lf", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("Lf");
      std::vector<u16> ord4441({1, 0});
    
    r->addIndex<2>(ord4441, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord4442({0, 1});
    
    r->addIndex<2>(ord4442, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord4443({1, 0});
    
    r->addIndex<2>(ord4443, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("Lf"), std::array<u16,2>{1, 0}, b));
  // (crule (pre (let __tconst48SJ108 const6b86b273ff34fce19d6b804e) (let __tconst5Uhl106 constd4735e3a265e16eee03f5971) (let __tconst9YpM103 const4e07408562bedb8b60ce05c1) (let __tconst3iHp101 const4b227777d4dd1fc61c6f884f) (let __tconst0Emh97 constef2d127de37b942baad06145) (let __tconst29xA95 conste7f6c011776e8db7cd330b54) (let __tconst9mjQ92 const7902699be42c8a8e46fbbb45) (let __tconst9Yxv90 const2c624232cdd221771294dfbb) (let __tconst7wWY85 const19581e27de7ced00ff1ce50b) (let __tconst01Wl83 const4a44dc15364204a80fe80e90) (let __tconst42lR80 const4fc82b26aecb47d2868c4efb) (let __tconst3KyY78 const6b51d431df5d7f141cbececc) (let __tconst6a9N74 const3fdba35f04dc8c462986c992) (let __tconst74Qx72 const8527a891e224136950ff32ca) (let __tconst2hOw69 conste629fa6598d732768f7c726b) (let __tconst7kHD67 constb17ef6d19c7a5b1ee83b907c) (let __tconst5zmq61 const4523540f1504cd17100c4835) (let __tconst31qC59 const4ec9599fc203d176a301536c) (let __tconst4Vop56 const9400f1b21cb527d7fa3d3eab) (let __tconst51zc54 constf5ca38f748a1d6eaf726b8a4) (let __tconst6Qm150 const6f4b6612125fb3a0daecd279) (let __tconst6bEj48 const785f3ec7eb32f30b90cd0fcf) (let __tconst7AKN45 const535fa30d7e25dd8a49f15367) (let __tconst9j2a43 constc2356069e9d1e79ca9243781) (let __tconst1Mto38 constb7a56873cd771f2c446d369b) (let __tconst8u8i36 const5f9c4ab08cac7457e9111a30) (let __tconst2Isx33 const670671cd97404156226e5079) (let __tconst8J6R31 const59e19706d51d39f66711c265) (let __tconst88cs27 const35135aaa6cc23891b40cb3f3) (let __tconst0Uuf25 const624b60c58c9d8bfb6ff1886c) (let __tconst6sf622 consteb1e33e8a81b697b75855af6) (let __tconst5Run20 conste29c9c180c6279b0b02abd6a)) (scan Nd __t4LVF66 __t4uRs65 __t17Jm42) (body (exists Lf (1 0) 1 __tconst6sf622) (exists Lf (1 0) 1 __tconst0Uuf25) (exists Lf (1 0) 1 __tconst88cs27) (exists Lf (1 0) 1 __tconst8J6R31) (exists Lf (1 0) 1 __tconst2Isx33) (exists Lf (1 0) 1 __tconst8u8i36) (exists Lf (1 0) 1 __tconst1Mto38) (exists Lf (1 0) 1 __tconst9j2a43) (exists Lf (1 0) 1 __tconst7AKN45) (exists Lf (1 0) 1 __tconst6bEj48) (exists Lf (1 0) 1 __tconst6Qm150) (exists Lf (1 0) 1 __tconst51zc54) (exists Lf (1 0) 1 __tconst4Vop56) (exists Lf (1 0) 1 __tconst31qC59) (exists Lf (1 0) 1 __tconst5zmq61) (exists Lf (1 0) 1 __tconst7kHD67) (exists Lf (1 0) 1 __tconst2hOw69) (exists Lf (1 0) 1 __tconst74Qx72) (exists Lf (1 0) 1 __tconst6a9N74) (exists Lf (1 0) 1 __tconst3KyY78) (exists Lf (1 0) 1 __tconst42lR80) (exists Lf (1 0) 1 __tconst01Wl83) (exists Lf (1 0) 1 __tconst7wWY85) (exists Lf (1 0) 1 __tconst9Yxv90) (exists Lf (1 0) 1 __tconst9mjQ92) (exists Lf (1 0) 1 __tconst29xA95) (exists Lf (1 0) 1 __tconst0Emh97) (exists Lf (1 0) 1 __tconst3iHp101) (exists Lf (1 0) 1 __tconst9YpM103) (exists Lf (1 0) 1 __tconst5Uhl106) (exists Lf (1 0) 1 __tconst48SJ108) (join Lf (1 0) 1 __tconst5Run20 __t8mDO21) (exists Nd (2 1 0) 1 __t8mDO21) (join Lf (1 0) 1 __tconst6sf622 __t1M8o23) (join Nd (2 1 0) 2 __t8mDO21 __t1M8o23 __t7LF824) (exists Nd (2 1 0) 1 __t7LF824) (join Lf (1 0) 1 __tconst0Uuf25 __t1NQv26) (exists Nd (2 1 0) 1 __t1NQv26) (join Lf (1 0) 1 __tconst88cs27 __t7d0c28) (join Nd (2 1 0) 2 __t1NQv26 __t7d0c28 __t0kIY29) (join Nd (2 1 0) 2 __t7LF824 __t0kIY29 __t6JrG30) (join Nd (0 2 1) 2 __t17Jm42 __t6JrG30 __t2KtK41) (join Lf (1 0) 1 __tconst8J6R31 __t9vh832) (exists Nd (2 1 0) 1 __t9vh832) (join Lf (1 0) 1 __tconst2Isx33 __t5flt34) (join Nd (2 1 0) 2 __t9vh832 __t5flt34 __t3jHg35) (join Nd (0 2 1) 2 __t2KtK41 __t3jHg35 __t8qqV40) (join Lf (1 0) 1 __tconst8u8i36 __t27Zr37) (join Nd (0 2 1) 2 __t8qqV40 __t27Zr37 __t3UFu39) (join Lf (0 1) 2 __t3UFu39 __tconst1Mto38) (join Lf (1 0) 1 __tconst9j2a43 __t6IKq44) (exists Nd (2 1 0) 1 __t6IKq44) (join Lf (1 0) 1 __tconst7AKN45 __t6LIW46) (join Nd (2 1 0) 2 __t6IKq44 __t6LIW46 __t7C7d47) (exists Nd (2 1 0) 1 __t7C7d47) (join Lf (1 0) 1 __tconst6bEj48 __t9k7a49) (exists Nd (2 1 0) 1 __t9k7a49) (join Lf (1 0) 1 __tconst6Qm150 __t4MdC51) (join Nd (2 1 0) 2 __t9k7a49 __t4MdC51 __t8A9i52) (join Nd (2 1 0) 2 __t7C7d47 __t8A9i52 __t7DSY53) (join Nd (0 2 1) 2 __t4uRs65 __t7DSY53 __t6bZq64) (join Lf (1 0) 1 __tconst51zc54 __t3Yon55) (exists Nd (2 1 0) 1 __t3Yon55) (join Lf (1 0) 1 __tconst4Vop56 __t5ik157) (join Nd (2 1 0) 2 __t3Yon55 __t5ik157 __t4hi358) (join Nd (0 2 1) 2 __t6bZq64 __t4hi358 __t8TXU63) (join Lf (1 0) 1 __tconst31qC59 __t1nkJ60) (join Nd (0 2 1) 2 __t8TXU63 __t1nkJ60 __t4E3D62) (join Lf (0 1) 2 __t4E3D62 __tconst5zmq61) (join Lf (1 0) 1 __tconst7kHD67 __t4J2N68) (exists Nd (2 1 0) 1 __t4J2N68) (join Lf (1 0) 1 __tconst2hOw69 __t4izo70) (join Nd (2 1 0) 2 __t4J2N68 __t4izo70 __t14Ff71) (exists Nd (2 1 0) 1 __t14Ff71) (join Lf (1 0) 1 __tconst74Qx72 __t319l73) (exists Nd (2 1 0) 1 __t319l73) (join Lf (1 0) 1 __tconst6a9N74 __t0amQ75) (join Nd (2 1 0) 2 __t319l73 __t0amQ75 __t4MUf76) (join Nd (2 1 0) 2 __t14Ff71 __t4MUf76 __t13Wj77) (exists Nd (2 1 0) 1 __t13Wj77) (join Lf (1 0) 1 __tconst3KyY78 __t13gt79) (exists Nd (2 1 0) 1 __t13gt79) (join Lf (1 0) 1 __tconst42lR80 __t3ESz81) (join Nd (2 1 0) 2 __t13gt79 __t3ESz81 __t3WL082) (exists Nd (2 1 0) 1 __t3WL082) (join Lf (1 0) 1 __tconst01Wl83 __t4Da384) (exists Nd (2 1 0) 1 __t4Da384) (join Lf (1 0) 1 __tconst7wWY85 __t91gs86) (join Nd (2 1 0) 2 __t4Da384 __t91gs86 __t02Bu87) (join Nd (2 1 0) 2 __t3WL082 __t02Bu87 __t60KJ88) (join Nd (2 1 0) 2 __t13Wj77 __t60KJ88 __t4p4K89) (exists Nd (2 1 0) 1 __t4p4K89) (join Lf (1 0) 1 __tconst9Yxv90 __t7UaH91) (exists Nd (2 1 0) 1 __t7UaH91) (join Lf (1 0) 1 __tconst9mjQ92 __t6IMg93) (join Nd (2 1 0) 2 __t7UaH91 __t6IMg93 __t2T3i94) (exists Nd (2 1 0) 1 __t2T3i94) (join Lf (1 0) 1 __tconst29xA95 __t2oHE96) (exists Nd (2 1 0) 1 __t2oHE96) (join Lf (1 0) 1 __tconst0Emh97 __t7bue98) (join Nd (2 1 0) 2 __t2oHE96 __t7bue98 __t0HkS99) (join Nd (2 1 0) 2 __t2T3i94 __t0HkS99 __t7PLp100) (exists Nd (2 1 0) 1 __t7PLp100) (join Lf (1 0) 1 __tconst3iHp101 __t5yzC102) (exists Nd (2 1 0) 1 __t5yzC102) (join Lf (1 0) 1 __tconst9YpM103 __t7c21104) (join Nd (2 1 0) 2 __t5yzC102 __t7c21104 __t4bRV105) (exists Nd (2 1 0) 1 __t4bRV105) (join Lf (1 0) 1 __tconst5Uhl106 __t1IJA107) (exists Nd (2 1 0) 1 __t1IJA107) (join Lf (1 0) 1 __tconst48SJ108 __t0y5t109) (join Nd (2 1 0) 2 __t1IJA107 __t0y5t109 __t76VS110) (join Nd (2 1 0) 2 __t4bRV105 __t76VS110 __t3a3T111) (join Nd (2 1 0) 2 __t7PLp100 __t3a3T111 __t9dGZ112) (join Nd (2 1 0) 2 __t4p4K89 __t9dGZ112 __t09Ym113)) (head (mkstruct Nd (2 1 0) __t1U6n114 __t4LVF66 __t09Ym113)) deep_fact.slog:7 #f)
  class ReadTask115 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** Lfindex0;  slog::Index** Lfindex1;  slog::Index** Lfindex2;  slog::Index** Lfindex3;  slog::Index** Lfindex4;  slog::Index** Lfindex5;  slog::Index** Lfindex6;  slog::Index** Lfindex7;  slog::Index** Lfindex8;  slog::Index** Lfindex9;  slog::Index** Lfindex10;  slog::Index** Lfindex11;  slog::Index** Lfindex12;  slog::Index** Lfindex13;  slog::Index** Lfindex14;  slog::Index** Lfindex15;  slog::Index** Lfindex16;  slog::Index** Lfindex17;  slog::Index** Lfindex18;  slog::Index** Lfindex19;  slog::Index** Lfindex20;  slog::Index** Lfindex21;  slog::Index** Lfindex22;  slog::Index** Lfindex23;  slog::Index** Lfindex24;  slog::Index** Lfindex25;  slog::Index** Lfindex26;  slog::Index** Lfindex27;  slog::Index** Lfindex28;  slog::Index** Lfindex29;  slog::Index** Lfindex30;  slog::Index** Lfindex31;  slog::Index** Ndindex32;  slog::Index** Lfindex33;  slog::Index** Ndindex34;  slog::Index** Ndindex35;  slog::Index** Lfindex36;  slog::Index** Ndindex37;  slog::Index** Lfindex38;  slog::Index** Ndindex39;  slog::Index** Ndindex40;  slog::Index** Ndindex41;  slog::Index** Lfindex42;  slog::Index** Ndindex43;  slog::Index** Lfindex44;  slog::Index** Ndindex45;  slog::Index** Ndindex46;  slog::Index** Lfindex47;  slog::Index** Ndindex48;  slog::Index** Lfindex49;  slog::Index** Lfindex50;  slog::Index** Ndindex51;  slog::Index** Lfindex52;  slog::Index** Ndindex53;  slog::Index** Ndindex54;  slog::Index** Lfindex55;  slog::Index** Ndindex56;  slog::Index** Lfindex57;  slog::Index** Ndindex58;  slog::Index** Ndindex59;  slog::Index** Ndindex60;  slog::Index** Lfindex61;  slog::Index** Ndindex62;  slog::Index** Lfindex63;  slog::Index** Ndindex64;  slog::Index** Ndindex65;  slog::Index** Lfindex66;  slog::Index** Ndindex67;  slog::Index** Lfindex68;  slog::Index** Lfindex69;  slog::Index** Ndindex70;  slog::Index** Lfindex71;  slog::Index** Ndindex72;  slog::Index** Ndindex73;  slog::Index** Lfindex74;  slog::Index** Ndindex75;  slog::Index** Lfindex76;  slog::Index** Ndindex77;  slog::Index** Ndindex78;  slog::Index** Ndindex79;  slog::Index** Lfindex80;  slog::Index** Ndindex81;  slog::Index** Lfindex82;  slog::Index** Ndindex83;  slog::Index** Ndindex84;  slog::Index** Lfindex85;  slog::Index** Ndindex86;  slog::Index** Lfindex87;  slog::Index** Ndindex88;  slog::Index** Ndindex89;  slog::Index** Ndindex90;  slog::Index** Ndindex91;  slog::Index** Lfindex92;  slog::Index** Ndindex93;  slog::Index** Lfindex94;  slog::Index** Ndindex95;  slog::Index** Ndindex96;  slog::Index** Lfindex97;  slog::Index** Ndindex98;  slog::Index** Lfindex99;  slog::Index** Ndindex100;  slog::Index** Ndindex101;  slog::Index** Ndindex102;  slog::Index** Lfindex103;  slog::Index** Ndindex104;  slog::Index** Lfindex105;  slog::Index** Ndindex106;  slog::Index** Ndindex107;  slog::Index** Lfindex108;  slog::Index** Ndindex109;  slog::Index** Lfindex110;  slog::Index** Ndindex111;  slog::Index** Ndindex112;  slog::Index** Ndindex113;  slog::Index** Ndindex114;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("Nd");
      outer_rel = db->getRelation("Nd");
      std::vector<u16> ord116({1, 0});
      slog::Relation* readrel117 = db->getRelation("Lf");
      Lfindex0 = readrel117->getIndex(ord116, false);
      std::vector<u16> ord118({1, 0});
      slog::Relation* readrel119 = db->getRelation("Lf");
      Lfindex1 = readrel119->getIndex(ord118, false);
      std::vector<u16> ord120({1, 0});
      slog::Relation* readrel121 = db->getRelation("Lf");
      Lfindex2 = readrel121->getIndex(ord120, false);
      std::vector<u16> ord122({1, 0});
      slog::Relation* readrel123 = db->getRelation("Lf");
      Lfindex3 = readrel123->getIndex(ord122, false);
      std::vector<u16> ord124({1, 0});
      slog::Relation* readrel125 = db->getRelation("Lf");
      Lfindex4 = readrel125->getIndex(ord124, false);
      std::vector<u16> ord126({1, 0});
      slog::Relation* readrel127 = db->getRelation("Lf");
      Lfindex5 = readrel127->getIndex(ord126, false);
      std::vector<u16> ord128({1, 0});
      slog::Relation* readrel129 = db->getRelation("Lf");
      Lfindex6 = readrel129->getIndex(ord128, false);
      std::vector<u16> ord130({1, 0});
      slog::Relation* readrel131 = db->getRelation("Lf");
      Lfindex7 = readrel131->getIndex(ord130, false);
      std::vector<u16> ord132({1, 0});
      slog::Relation* readrel133 = db->getRelation("Lf");
      Lfindex8 = readrel133->getIndex(ord132, false);
      std::vector<u16> ord134({1, 0});
      slog::Relation* readrel135 = db->getRelation("Lf");
      Lfindex9 = readrel135->getIndex(ord134, false);
      std::vector<u16> ord136({1, 0});
      slog::Relation* readrel137 = db->getRelation("Lf");
      Lfindex10 = readrel137->getIndex(ord136, false);
      std::vector<u16> ord138({1, 0});
      slog::Relation* readrel139 = db->getRelation("Lf");
      Lfindex11 = readrel139->getIndex(ord138, false);
      std::vector<u16> ord140({1, 0});
      slog::Relation* readrel141 = db->getRelation("Lf");
      Lfindex12 = readrel141->getIndex(ord140, false);
      std::vector<u16> ord142({1, 0});
      slog::Relation* readrel143 = db->getRelation("Lf");
      Lfindex13 = readrel143->getIndex(ord142, false);
      std::vector<u16> ord144({1, 0});
      slog::Relation* readrel145 = db->getRelation("Lf");
      Lfindex14 = readrel145->getIndex(ord144, false);
      std::vector<u16> ord146({1, 0});
      slog::Relation* readrel147 = db->getRelation("Lf");
      Lfindex15 = readrel147->getIndex(ord146, false);
      std::vector<u16> ord148({1, 0});
      slog::Relation* readrel149 = db->getRelation("Lf");
      Lfindex16 = readrel149->getIndex(ord148, false);
      std::vector<u16> ord150({1, 0});
      slog::Relation* readrel151 = db->getRelation("Lf");
      Lfindex17 = readrel151->getIndex(ord150, false);
      std::vector<u16> ord152({1, 0});
      slog::Relation* readrel153 = db->getRelation("Lf");
      Lfindex18 = readrel153->getIndex(ord152, false);
      std::vector<u16> ord154({1, 0});
      slog::Relation* readrel155 = db->getRelation("Lf");
      Lfindex19 = readrel155->getIndex(ord154, false);
      std::vector<u16> ord156({1, 0});
      slog::Relation* readrel157 = db->getRelation("Lf");
      Lfindex20 = readrel157->getIndex(ord156, false);
      std::vector<u16> ord158({1, 0});
      slog::Relation* readrel159 = db->getRelation("Lf");
      Lfindex21 = readrel159->getIndex(ord158, false);
      std::vector<u16> ord160({1, 0});
      slog::Relation* readrel161 = db->getRelation("Lf");
      Lfindex22 = readrel161->getIndex(ord160, false);
      std::vector<u16> ord162({1, 0});
      slog::Relation* readrel163 = db->getRelation("Lf");
      Lfindex23 = readrel163->getIndex(ord162, false);
      std::vector<u16> ord164({1, 0});
      slog::Relation* readrel165 = db->getRelation("Lf");
      Lfindex24 = readrel165->getIndex(ord164, false);
      std::vector<u16> ord166({1, 0});
      slog::Relation* readrel167 = db->getRelation("Lf");
      Lfindex25 = readrel167->getIndex(ord166, false);
      std::vector<u16> ord168({1, 0});
      slog::Relation* readrel169 = db->getRelation("Lf");
      Lfindex26 = readrel169->getIndex(ord168, false);
      std::vector<u16> ord170({1, 0});
      slog::Relation* readrel171 = db->getRelation("Lf");
      Lfindex27 = readrel171->getIndex(ord170, false);
      std::vector<u16> ord172({1, 0});
      slog::Relation* readrel173 = db->getRelation("Lf");
      Lfindex28 = readrel173->getIndex(ord172, false);
      std::vector<u16> ord174({1, 0});
      slog::Relation* readrel175 = db->getRelation("Lf");
      Lfindex29 = readrel175->getIndex(ord174, false);
      std::vector<u16> ord176({1, 0});
      slog::Relation* readrel177 = db->getRelation("Lf");
      Lfindex30 = readrel177->getIndex(ord176, false);
      std::vector<u16> ord178({1, 0});
      slog::Relation* readrel179 = db->getRelation("Lf");
      Lfindex31 = readrel179->getIndex(ord178, false);
      std::vector<u16> ord180({2, 1, 0});
      slog::Relation* readrel181 = db->getRelation("Nd");
      Ndindex32 = readrel181->getIndex(ord180, false);
      std::vector<u16> ord182({1, 0});
      slog::Relation* readrel183 = db->getRelation("Lf");
      Lfindex33 = readrel183->getIndex(ord182, false);
      std::vector<u16> ord184({2, 1, 0});
      slog::Relation* readrel185 = db->getRelation("Nd");
      Ndindex34 = readrel185->getIndex(ord184, false);
      std::vector<u16> ord186({2, 1, 0});
      slog::Relation* readrel187 = db->getRelation("Nd");
      Ndindex35 = readrel187->getIndex(ord186, false);
      std::vector<u16> ord188({1, 0});
      slog::Relation* readrel189 = db->getRelation("Lf");
      Lfindex36 = readrel189->getIndex(ord188, false);
      std::vector<u16> ord190({2, 1, 0});
      slog::Relation* readrel191 = db->getRelation("Nd");
      Ndindex37 = readrel191->getIndex(ord190, false);
      std::vector<u16> ord192({1, 0});
      slog::Relation* readrel193 = db->getRelation("Lf");
      Lfindex38 = readrel193->getIndex(ord192, false);
      std::vector<u16> ord194({2, 1, 0});
      slog::Relation* readrel195 = db->getRelation("Nd");
      Ndindex39 = readrel195->getIndex(ord194, false);
      std::vector<u16> ord196({2, 1, 0});
      slog::Relation* readrel197 = db->getRelation("Nd");
      Ndindex40 = readrel197->getIndex(ord196, false);
      std::vector<u16> ord198({0, 2, 1});
      slog::Relation* readrel199 = db->getRelation("Nd");
      Ndindex41 = readrel199->getIndex(ord198, false);
      std::vector<u16> ord200({1, 0});
      slog::Relation* readrel201 = db->getRelation("Lf");
      Lfindex42 = readrel201->getIndex(ord200, false);
      std::vector<u16> ord202({2, 1, 0});
      slog::Relation* readrel203 = db->getRelation("Nd");
      Ndindex43 = readrel203->getIndex(ord202, false);
      std::vector<u16> ord204({1, 0});
      slog::Relation* readrel205 = db->getRelation("Lf");
      Lfindex44 = readrel205->getIndex(ord204, false);
      std::vector<u16> ord206({2, 1, 0});
      slog::Relation* readrel207 = db->getRelation("Nd");
      Ndindex45 = readrel207->getIndex(ord206, false);
      std::vector<u16> ord208({0, 2, 1});
      slog::Relation* readrel209 = db->getRelation("Nd");
      Ndindex46 = readrel209->getIndex(ord208, false);
      std::vector<u16> ord210({1, 0});
      slog::Relation* readrel211 = db->getRelation("Lf");
      Lfindex47 = readrel211->getIndex(ord210, false);
      std::vector<u16> ord212({0, 2, 1});
      slog::Relation* readrel213 = db->getRelation("Nd");
      Ndindex48 = readrel213->getIndex(ord212, false);
      std::vector<u16> ord214({0, 1});
      slog::Relation* readrel215 = db->getRelation("Lf");
      Lfindex49 = readrel215->getIndex(ord214, false);
      std::vector<u16> ord216({1, 0});
      slog::Relation* readrel217 = db->getRelation("Lf");
      Lfindex50 = readrel217->getIndex(ord216, false);
      std::vector<u16> ord218({2, 1, 0});
      slog::Relation* readrel219 = db->getRelation("Nd");
      Ndindex51 = readrel219->getIndex(ord218, false);
      std::vector<u16> ord220({1, 0});
      slog::Relation* readrel221 = db->getRelation("Lf");
      Lfindex52 = readrel221->getIndex(ord220, false);
      std::vector<u16> ord222({2, 1, 0});
      slog::Relation* readrel223 = db->getRelation("Nd");
      Ndindex53 = readrel223->getIndex(ord222, false);
      std::vector<u16> ord224({2, 1, 0});
      slog::Relation* readrel225 = db->getRelation("Nd");
      Ndindex54 = readrel225->getIndex(ord224, false);
      std::vector<u16> ord226({1, 0});
      slog::Relation* readrel227 = db->getRelation("Lf");
      Lfindex55 = readrel227->getIndex(ord226, false);
      std::vector<u16> ord228({2, 1, 0});
      slog::Relation* readrel229 = db->getRelation("Nd");
      Ndindex56 = readrel229->getIndex(ord228, false);
      std::vector<u16> ord230({1, 0});
      slog::Relation* readrel231 = db->getRelation("Lf");
      Lfindex57 = readrel231->getIndex(ord230, false);
      std::vector<u16> ord232({2, 1, 0});
      slog::Relation* readrel233 = db->getRelation("Nd");
      Ndindex58 = readrel233->getIndex(ord232, false);
      std::vector<u16> ord234({2, 1, 0});
      slog::Relation* readrel235 = db->getRelation("Nd");
      Ndindex59 = readrel235->getIndex(ord234, false);
      std::vector<u16> ord236({0, 2, 1});
      slog::Relation* readrel237 = db->getRelation("Nd");
      Ndindex60 = readrel237->getIndex(ord236, false);
      std::vector<u16> ord238({1, 0});
      slog::Relation* readrel239 = db->getRelation("Lf");
      Lfindex61 = readrel239->getIndex(ord238, false);
      std::vector<u16> ord240({2, 1, 0});
      slog::Relation* readrel241 = db->getRelation("Nd");
      Ndindex62 = readrel241->getIndex(ord240, false);
      std::vector<u16> ord242({1, 0});
      slog::Relation* readrel243 = db->getRelation("Lf");
      Lfindex63 = readrel243->getIndex(ord242, false);
      std::vector<u16> ord244({2, 1, 0});
      slog::Relation* readrel245 = db->getRelation("Nd");
      Ndindex64 = readrel245->getIndex(ord244, false);
      std::vector<u16> ord246({0, 2, 1});
      slog::Relation* readrel247 = db->getRelation("Nd");
      Ndindex65 = readrel247->getIndex(ord246, false);
      std::vector<u16> ord248({1, 0});
      slog::Relation* readrel249 = db->getRelation("Lf");
      Lfindex66 = readrel249->getIndex(ord248, false);
      std::vector<u16> ord250({0, 2, 1});
      slog::Relation* readrel251 = db->getRelation("Nd");
      Ndindex67 = readrel251->getIndex(ord250, false);
      std::vector<u16> ord252({0, 1});
      slog::Relation* readrel253 = db->getRelation("Lf");
      Lfindex68 = readrel253->getIndex(ord252, false);
      std::vector<u16> ord254({1, 0});
      slog::Relation* readrel255 = db->getRelation("Lf");
      Lfindex69 = readrel255->getIndex(ord254, false);
      std::vector<u16> ord256({2, 1, 0});
      slog::Relation* readrel257 = db->getRelation("Nd");
      Ndindex70 = readrel257->getIndex(ord256, false);
      std::vector<u16> ord258({1, 0});
      slog::Relation* readrel259 = db->getRelation("Lf");
      Lfindex71 = readrel259->getIndex(ord258, false);
      std::vector<u16> ord260({2, 1, 0});
      slog::Relation* readrel261 = db->getRelation("Nd");
      Ndindex72 = readrel261->getIndex(ord260, false);
      std::vector<u16> ord262({2, 1, 0});
      slog::Relation* readrel263 = db->getRelation("Nd");
      Ndindex73 = readrel263->getIndex(ord262, false);
      std::vector<u16> ord264({1, 0});
      slog::Relation* readrel265 = db->getRelation("Lf");
      Lfindex74 = readrel265->getIndex(ord264, false);
      std::vector<u16> ord266({2, 1, 0});
      slog::Relation* readrel267 = db->getRelation("Nd");
      Ndindex75 = readrel267->getIndex(ord266, false);
      std::vector<u16> ord268({1, 0});
      slog::Relation* readrel269 = db->getRelation("Lf");
      Lfindex76 = readrel269->getIndex(ord268, false);
      std::vector<u16> ord270({2, 1, 0});
      slog::Relation* readrel271 = db->getRelation("Nd");
      Ndindex77 = readrel271->getIndex(ord270, false);
      std::vector<u16> ord272({2, 1, 0});
      slog::Relation* readrel273 = db->getRelation("Nd");
      Ndindex78 = readrel273->getIndex(ord272, false);
      std::vector<u16> ord274({2, 1, 0});
      slog::Relation* readrel275 = db->getRelation("Nd");
      Ndindex79 = readrel275->getIndex(ord274, false);
      std::vector<u16> ord276({1, 0});
      slog::Relation* readrel277 = db->getRelation("Lf");
      Lfindex80 = readrel277->getIndex(ord276, false);
      std::vector<u16> ord278({2, 1, 0});
      slog::Relation* readrel279 = db->getRelation("Nd");
      Ndindex81 = readrel279->getIndex(ord278, false);
      std::vector<u16> ord280({1, 0});
      slog::Relation* readrel281 = db->getRelation("Lf");
      Lfindex82 = readrel281->getIndex(ord280, false);
      std::vector<u16> ord282({2, 1, 0});
      slog::Relation* readrel283 = db->getRelation("Nd");
      Ndindex83 = readrel283->getIndex(ord282, false);
      std::vector<u16> ord284({2, 1, 0});
      slog::Relation* readrel285 = db->getRelation("Nd");
      Ndindex84 = readrel285->getIndex(ord284, false);
      std::vector<u16> ord286({1, 0});
      slog::Relation* readrel287 = db->getRelation("Lf");
      Lfindex85 = readrel287->getIndex(ord286, false);
      std::vector<u16> ord288({2, 1, 0});
      slog::Relation* readrel289 = db->getRelation("Nd");
      Ndindex86 = readrel289->getIndex(ord288, false);
      std::vector<u16> ord290({1, 0});
      slog::Relation* readrel291 = db->getRelation("Lf");
      Lfindex87 = readrel291->getIndex(ord290, false);
      std::vector<u16> ord292({2, 1, 0});
      slog::Relation* readrel293 = db->getRelation("Nd");
      Ndindex88 = readrel293->getIndex(ord292, false);
      std::vector<u16> ord294({2, 1, 0});
      slog::Relation* readrel295 = db->getRelation("Nd");
      Ndindex89 = readrel295->getIndex(ord294, false);
      std::vector<u16> ord296({2, 1, 0});
      slog::Relation* readrel297 = db->getRelation("Nd");
      Ndindex90 = readrel297->getIndex(ord296, false);
      std::vector<u16> ord298({2, 1, 0});
      slog::Relation* readrel299 = db->getRelation("Nd");
      Ndindex91 = readrel299->getIndex(ord298, false);
      std::vector<u16> ord300({1, 0});
      slog::Relation* readrel301 = db->getRelation("Lf");
      Lfindex92 = readrel301->getIndex(ord300, false);
      std::vector<u16> ord302({2, 1, 0});
      slog::Relation* readrel303 = db->getRelation("Nd");
      Ndindex93 = readrel303->getIndex(ord302, false);
      std::vector<u16> ord304({1, 0});
      slog::Relation* readrel305 = db->getRelation("Lf");
      Lfindex94 = readrel305->getIndex(ord304, false);
      std::vector<u16> ord306({2, 1, 0});
      slog::Relation* readrel307 = db->getRelation("Nd");
      Ndindex95 = readrel307->getIndex(ord306, false);
      std::vector<u16> ord308({2, 1, 0});
      slog::Relation* readrel309 = db->getRelation("Nd");
      Ndindex96 = readrel309->getIndex(ord308, false);
      std::vector<u16> ord310({1, 0});
      slog::Relation* readrel311 = db->getRelation("Lf");
      Lfindex97 = readrel311->getIndex(ord310, false);
      std::vector<u16> ord312({2, 1, 0});
      slog::Relation* readrel313 = db->getRelation("Nd");
      Ndindex98 = readrel313->getIndex(ord312, false);
      std::vector<u16> ord314({1, 0});
      slog::Relation* readrel315 = db->getRelation("Lf");
      Lfindex99 = readrel315->getIndex(ord314, false);
      std::vector<u16> ord316({2, 1, 0});
      slog::Relation* readrel317 = db->getRelation("Nd");
      Ndindex100 = readrel317->getIndex(ord316, false);
      std::vector<u16> ord318({2, 1, 0});
      slog::Relation* readrel319 = db->getRelation("Nd");
      Ndindex101 = readrel319->getIndex(ord318, false);
      std::vector<u16> ord320({2, 1, 0});
      slog::Relation* readrel321 = db->getRelation("Nd");
      Ndindex102 = readrel321->getIndex(ord320, false);
      std::vector<u16> ord322({1, 0});
      slog::Relation* readrel323 = db->getRelation("Lf");
      Lfindex103 = readrel323->getIndex(ord322, false);
      std::vector<u16> ord324({2, 1, 0});
      slog::Relation* readrel325 = db->getRelation("Nd");
      Ndindex104 = readrel325->getIndex(ord324, false);
      std::vector<u16> ord326({1, 0});
      slog::Relation* readrel327 = db->getRelation("Lf");
      Lfindex105 = readrel327->getIndex(ord326, false);
      std::vector<u16> ord328({2, 1, 0});
      slog::Relation* readrel329 = db->getRelation("Nd");
      Ndindex106 = readrel329->getIndex(ord328, false);
      std::vector<u16> ord330({2, 1, 0});
      slog::Relation* readrel331 = db->getRelation("Nd");
      Ndindex107 = readrel331->getIndex(ord330, false);
      std::vector<u16> ord332({1, 0});
      slog::Relation* readrel333 = db->getRelation("Lf");
      Lfindex108 = readrel333->getIndex(ord332, false);
      std::vector<u16> ord334({2, 1, 0});
      slog::Relation* readrel335 = db->getRelation("Nd");
      Ndindex109 = readrel335->getIndex(ord334, false);
      std::vector<u16> ord336({1, 0});
      slog::Relation* readrel337 = db->getRelation("Lf");
      Lfindex110 = readrel337->getIndex(ord336, false);
      std::vector<u16> ord338({2, 1, 0});
      slog::Relation* readrel339 = db->getRelation("Nd");
      Ndindex111 = readrel339->getIndex(ord338, false);
      std::vector<u16> ord340({2, 1, 0});
      slog::Relation* readrel341 = db->getRelation("Nd");
      Ndindex112 = readrel341->getIndex(ord340, false);
      std::vector<u16> ord342({2, 1, 0});
      slog::Relation* readrel343 = db->getRelation("Nd");
      Ndindex113 = readrel343->getIndex(ord342, false);
      std::vector<u16> ord344({2, 1, 0});
      slog::Relation* readrel345 = db->getRelation("Nd");
      Ndindex114 = readrel345->getIndex(ord344, false);
  
    }
    ReadTask115(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c32 = _t[0];
        u64 v_c33 = _t[1];
        u64 v_c34 = _t[2];
        if (!slog::exists_probe<2,1>(Lfindex0, std::array<u64,2>{v_c30, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1, std::array<u64,2>{v_c29, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2, std::array<u64,2>{v_c28, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3, std::array<u64,2>{v_c27, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex4, std::array<u64,2>{v_c26, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex5, std::array<u64,2>{v_c25, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex6, std::array<u64,2>{v_c24, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex7, std::array<u64,2>{v_c23, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex8, std::array<u64,2>{v_c22, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex9, std::array<u64,2>{v_c21, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex10, std::array<u64,2>{v_c20, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex11, std::array<u64,2>{v_c19, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex12, std::array<u64,2>{v_c18, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex13, std::array<u64,2>{v_c17, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex14, std::array<u64,2>{v_c16, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex15, std::array<u64,2>{v_c15, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex16, std::array<u64,2>{v_c14, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex17, std::array<u64,2>{v_c13, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex18, std::array<u64,2>{v_c12, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex19, std::array<u64,2>{v_c11, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex20, std::array<u64,2>{v_c10, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex21, std::array<u64,2>{v_c9, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex22, std::array<u64,2>{v_c8, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex23, std::array<u64,2>{v_c7, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex24, std::array<u64,2>{v_c6, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex25, std::array<u64,2>{v_c5, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex26, std::array<u64,2>{v_c4, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex27, std::array<u64,2>{v_c3, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex28, std::array<u64,2>{v_c2, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex29, std::array<u64,2>{v_c1, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex30, std::array<u64,2>{v_c0, 0})) return;
        slog::join_probe<2,1>(Lfindex31, std::array<u64,2>{v_c31, 0}, [&](const std::array<u64,2>& m346) {
          u64 v_c35 = m346[1];
          if (!slog::exists_probe<3,1>(Ndindex32, std::array<u64,3>{v_c35, 0, 0})) return;
          slog::join_probe<2,1>(Lfindex33, std::array<u64,2>{v_c30, 0}, [&](const std::array<u64,2>& m347) {
            u64 v_c36 = m347[1];
            slog::join_probe<3,2>(Ndindex34, std::array<u64,3>{v_c35, v_c36, 0}, [&](const std::array<u64,3>& m348) {
              u64 v_c37 = m348[2];
              if (!slog::exists_probe<3,1>(Ndindex35, std::array<u64,3>{v_c37, 0, 0})) return;
              slog::join_probe<2,1>(Lfindex36, std::array<u64,2>{v_c29, 0}, [&](const std::array<u64,2>& m349) {
                u64 v_c38 = m349[1];
                if (!slog::exists_probe<3,1>(Ndindex37, std::array<u64,3>{v_c38, 0, 0})) return;
                slog::join_probe<2,1>(Lfindex38, std::array<u64,2>{v_c28, 0}, [&](const std::array<u64,2>& m350) {
                  u64 v_c39 = m350[1];
                  slog::join_probe<3,2>(Ndindex39, std::array<u64,3>{v_c38, v_c39, 0}, [&](const std::array<u64,3>& m351) {
                    u64 v_c40 = m351[2];
                    slog::join_probe<3,2>(Ndindex40, std::array<u64,3>{v_c37, v_c40, 0}, [&](const std::array<u64,3>& m352) {
                      u64 v_c41 = m352[2];
                      slog::join_probe<3,2>(Ndindex41, std::array<u64,3>{v_c34, v_c41, 0}, [&](const std::array<u64,3>& m353) {
                        u64 v_c42 = m353[2];
                        slog::join_probe<2,1>(Lfindex42, std::array<u64,2>{v_c27, 0}, [&](const std::array<u64,2>& m354) {
                          u64 v_c43 = m354[1];
                          if (!slog::exists_probe<3,1>(Ndindex43, std::array<u64,3>{v_c43, 0, 0})) return;
                          slog::join_probe<2,1>(Lfindex44, std::array<u64,2>{v_c26, 0}, [&](const std::array<u64,2>& m355) {
                            u64 v_c44 = m355[1];
                            slog::join_probe<3,2>(Ndindex45, std::array<u64,3>{v_c43, v_c44, 0}, [&](const std::array<u64,3>& m356) {
                              u64 v_c45 = m356[2];
                              slog::join_probe<3,2>(Ndindex46, std::array<u64,3>{v_c42, v_c45, 0}, [&](const std::array<u64,3>& m357) {
                                u64 v_c46 = m357[2];
                                slog::join_probe<2,1>(Lfindex47, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m358) {
                                  u64 v_c47 = m358[1];
                                  slog::join_probe<3,2>(Ndindex48, std::array<u64,3>{v_c46, v_c47, 0}, [&](const std::array<u64,3>& m359) {
                                    u64 v_c48 = m359[2];
                                    slog::join_probe<2,2>(Lfindex49, std::array<u64,2>{v_c48, v_c24}, [&](const std::array<u64,2>& m360) {
                                      slog::join_probe<2,1>(Lfindex50, std::array<u64,2>{v_c23, 0}, [&](const std::array<u64,2>& m361) {
                                        u64 v_c49 = m361[1];
                                        if (!slog::exists_probe<3,1>(Ndindex51, std::array<u64,3>{v_c49, 0, 0})) return;
                                        slog::join_probe<2,1>(Lfindex52, std::array<u64,2>{v_c22, 0}, [&](const std::array<u64,2>& m362) {
                                          u64 v_c50 = m362[1];
                                          slog::join_probe<3,2>(Ndindex53, std::array<u64,3>{v_c49, v_c50, 0}, [&](const std::array<u64,3>& m363) {
                                            u64 v_c51 = m363[2];
                                            if (!slog::exists_probe<3,1>(Ndindex54, std::array<u64,3>{v_c51, 0, 0})) return;
                                            slog::join_probe<2,1>(Lfindex55, std::array<u64,2>{v_c21, 0}, [&](const std::array<u64,2>& m364) {
                                              u64 v_c52 = m364[1];
                                              if (!slog::exists_probe<3,1>(Ndindex56, std::array<u64,3>{v_c52, 0, 0})) return;
                                              slog::join_probe<2,1>(Lfindex57, std::array<u64,2>{v_c20, 0}, [&](const std::array<u64,2>& m365) {
                                                u64 v_c53 = m365[1];
                                                slog::join_probe<3,2>(Ndindex58, std::array<u64,3>{v_c52, v_c53, 0}, [&](const std::array<u64,3>& m366) {
                                                  u64 v_c54 = m366[2];
                                                  slog::join_probe<3,2>(Ndindex59, std::array<u64,3>{v_c51, v_c54, 0}, [&](const std::array<u64,3>& m367) {
                                                    u64 v_c55 = m367[2];
                                                    slog::join_probe<3,2>(Ndindex60, std::array<u64,3>{v_c33, v_c55, 0}, [&](const std::array<u64,3>& m368) {
                                                      u64 v_c56 = m368[2];
                                                      slog::join_probe<2,1>(Lfindex61, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m369) {
                                                        u64 v_c57 = m369[1];
                                                        if (!slog::exists_probe<3,1>(Ndindex62, std::array<u64,3>{v_c57, 0, 0})) return;
                                                        slog::join_probe<2,1>(Lfindex63, std::array<u64,2>{v_c18, 0}, [&](const std::array<u64,2>& m370) {
                                                          u64 v_c58 = m370[1];
                                                          slog::join_probe<3,2>(Ndindex64, std::array<u64,3>{v_c57, v_c58, 0}, [&](const std::array<u64,3>& m371) {
                                                            u64 v_c59 = m371[2];
                                                            slog::join_probe<3,2>(Ndindex65, std::array<u64,3>{v_c56, v_c59, 0}, [&](const std::array<u64,3>& m372) {
                                                              u64 v_c60 = m372[2];
                                                              slog::join_probe<2,1>(Lfindex66, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m373) {
                                                                u64 v_c61 = m373[1];
                                                                slog::join_probe<3,2>(Ndindex67, std::array<u64,3>{v_c60, v_c61, 0}, [&](const std::array<u64,3>& m374) {
                                                                  u64 v_c62 = m374[2];
                                                                  slog::join_probe<2,2>(Lfindex68, std::array<u64,2>{v_c62, v_c16}, [&](const std::array<u64,2>& m375) {
                                                                    slog::join_probe<2,1>(Lfindex69, std::array<u64,2>{v_c15, 0}, [&](const std::array<u64,2>& m376) {
                                                                      u64 v_c63 = m376[1];
                                                                      if (!slog::exists_probe<3,1>(Ndindex70, std::array<u64,3>{v_c63, 0, 0})) return;
                                                                      slog::join_probe<2,1>(Lfindex71, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m377) {
                                                                        u64 v_c64 = m377[1];
                                                                        slog::join_probe<3,2>(Ndindex72, std::array<u64,3>{v_c63, v_c64, 0}, [&](const std::array<u64,3>& m378) {
                                                                          u64 v_c65 = m378[2];
                                                                          if (!slog::exists_probe<3,1>(Ndindex73, std::array<u64,3>{v_c65, 0, 0})) return;
                                                                          slog::join_probe<2,1>(Lfindex74, std::array<u64,2>{v_c13, 0}, [&](const std::array<u64,2>& m379) {
                                                                            u64 v_c66 = m379[1];
                                                                            if (!slog::exists_probe<3,1>(Ndindex75, std::array<u64,3>{v_c66, 0, 0})) return;
                                                                            slog::join_probe<2,1>(Lfindex76, std::array<u64,2>{v_c12, 0}, [&](const std::array<u64,2>& m380) {
                                                                              u64 v_c67 = m380[1];
                                                                              slog::join_probe<3,2>(Ndindex77, std::array<u64,3>{v_c66, v_c67, 0}, [&](const std::array<u64,3>& m381) {
                                                                                u64 v_c68 = m381[2];
                                                                                slog::join_probe<3,2>(Ndindex78, std::array<u64,3>{v_c65, v_c68, 0}, [&](const std::array<u64,3>& m382) {
                                                                                  u64 v_c69 = m382[2];
                                                                                  if (!slog::exists_probe<3,1>(Ndindex79, std::array<u64,3>{v_c69, 0, 0})) return;
                                                                                  slog::join_probe<2,1>(Lfindex80, std::array<u64,2>{v_c11, 0}, [&](const std::array<u64,2>& m383) {
                                                                                    u64 v_c70 = m383[1];
                                                                                    if (!slog::exists_probe<3,1>(Ndindex81, std::array<u64,3>{v_c70, 0, 0})) return;
                                                                                    slog::join_probe<2,1>(Lfindex82, std::array<u64,2>{v_c10, 0}, [&](const std::array<u64,2>& m384) {
                                                                                      u64 v_c71 = m384[1];
                                                                                      slog::join_probe<3,2>(Ndindex83, std::array<u64,3>{v_c70, v_c71, 0}, [&](const std::array<u64,3>& m385) {
                                                                                        u64 v_c72 = m385[2];
                                                                                        if (!slog::exists_probe<3,1>(Ndindex84, std::array<u64,3>{v_c72, 0, 0})) return;
                                                                                        slog::join_probe<2,1>(Lfindex85, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m386) {
                                                                                          u64 v_c73 = m386[1];
                                                                                          if (!slog::exists_probe<3,1>(Ndindex86, std::array<u64,3>{v_c73, 0, 0})) return;
                                                                                          slog::join_probe<2,1>(Lfindex87, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m387) {
                                                                                            u64 v_c74 = m387[1];
                                                                                            slog::join_probe<3,2>(Ndindex88, std::array<u64,3>{v_c73, v_c74, 0}, [&](const std::array<u64,3>& m388) {
                                                                                              u64 v_c75 = m388[2];
                                                                                              slog::join_probe<3,2>(Ndindex89, std::array<u64,3>{v_c72, v_c75, 0}, [&](const std::array<u64,3>& m389) {
                                                                                                u64 v_c76 = m389[2];
                                                                                                slog::join_probe<3,2>(Ndindex90, std::array<u64,3>{v_c69, v_c76, 0}, [&](const std::array<u64,3>& m390) {
                                                                                                  u64 v_c77 = m390[2];
                                                                                                  if (!slog::exists_probe<3,1>(Ndindex91, std::array<u64,3>{v_c77, 0, 0})) return;
                                                                                                  slog::join_probe<2,1>(Lfindex92, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m391) {
                                                                                                    u64 v_c78 = m391[1];
                                                                                                    if (!slog::exists_probe<3,1>(Ndindex93, std::array<u64,3>{v_c78, 0, 0})) return;
                                                                                                    slog::join_probe<2,1>(Lfindex94, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m392) {
                                                                                                      u64 v_c79 = m392[1];
                                                                                                      slog::join_probe<3,2>(Ndindex95, std::array<u64,3>{v_c78, v_c79, 0}, [&](const std::array<u64,3>& m393) {
                                                                                                        u64 v_c80 = m393[2];
                                                                                                        if (!slog::exists_probe<3,1>(Ndindex96, std::array<u64,3>{v_c80, 0, 0})) return;
                                                                                                        slog::join_probe<2,1>(Lfindex97, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m394) {
                                                                                                          u64 v_c81 = m394[1];
                                                                                                          if (!slog::exists_probe<3,1>(Ndindex98, std::array<u64,3>{v_c81, 0, 0})) return;
                                                                                                          slog::join_probe<2,1>(Lfindex99, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m395) {
                                                                                                            u64 v_c82 = m395[1];
                                                                                                            slog::join_probe<3,2>(Ndindex100, std::array<u64,3>{v_c81, v_c82, 0}, [&](const std::array<u64,3>& m396) {
                                                                                                              u64 v_c83 = m396[2];
                                                                                                              slog::join_probe<3,2>(Ndindex101, std::array<u64,3>{v_c80, v_c83, 0}, [&](const std::array<u64,3>& m397) {
                                                                                                                u64 v_c84 = m397[2];
                                                                                                                if (!slog::exists_probe<3,1>(Ndindex102, std::array<u64,3>{v_c84, 0, 0})) return;
                                                                                                                slog::join_probe<2,1>(Lfindex103, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m398) {
                                                                                                                  u64 v_c85 = m398[1];
                                                                                                                  if (!slog::exists_probe<3,1>(Ndindex104, std::array<u64,3>{v_c85, 0, 0})) return;
                                                                                                                  slog::join_probe<2,1>(Lfindex105, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m399) {
                                                                                                                    u64 v_c86 = m399[1];
                                                                                                                    slog::join_probe<3,2>(Ndindex106, std::array<u64,3>{v_c85, v_c86, 0}, [&](const std::array<u64,3>& m400) {
                                                                                                                      u64 v_c87 = m400[2];
                                                                                                                      if (!slog::exists_probe<3,1>(Ndindex107, std::array<u64,3>{v_c87, 0, 0})) return;
                                                                                                                      slog::join_probe<2,1>(Lfindex108, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m401) {
                                                                                                                        u64 v_c88 = m401[1];
                                                                                                                        if (!slog::exists_probe<3,1>(Ndindex109, std::array<u64,3>{v_c88, 0, 0})) return;
                                                                                                                        slog::join_probe<2,1>(Lfindex110, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m402) {
                                                                                                                          u64 v_c89 = m402[1];
                                                                                                                          slog::join_probe<3,2>(Ndindex111, std::array<u64,3>{v_c88, v_c89, 0}, [&](const std::array<u64,3>& m403) {
                                                                                                                            u64 v_c90 = m403[2];
                                                                                                                            slog::join_probe<3,2>(Ndindex112, std::array<u64,3>{v_c87, v_c90, 0}, [&](const std::array<u64,3>& m404) {
                                                                                                                              u64 v_c91 = m404[2];
                                                                                                                              slog::join_probe<3,2>(Ndindex113, std::array<u64,3>{v_c84, v_c91, 0}, [&](const std::array<u64,3>& m405) {
                                                                                                                                u64 v_c92 = m405[2];
                                                                                                                                slog::join_probe<3,2>(Ndindex114, std::array<u64,3>{v_c77, v_c92, 0}, [&](const std::array<u64,3>& m406) {
                                                                                                                                  u64 v_c93 = m406[2];
                                                                                                                                  ++_fires;
                                                                                                                                  slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c32, v_c93}, std::array<u16,3>{2, 1, 0});
                                                                                                                                });
                                                                                                                              });
                                                                                                                            });
                                                                                                                          });
                                                                                                                        });
                                                                                                                      });
                                                                                                                    });
                                                                                                                  });
                                                                                                                });
                                                                                                              });
                                                                                                            });
                                                                                                          });
                                                                                                        });
                                                                                                      });
                                                                                                    });
                                                                                                  });
                                                                                                });
                                                                                              });
                                                                                            });
                                                                                          });
                                                                                        });
                                                                                      });
                                                                                    });
                                                                                  });
                                                                                });
                                                                              });
                                                                            });
                                                                          });
                                                                        });
                                                                      });
                                                                    });
                                                                  });
                                                                });
                                                              });
                                                            });
                                                          });
                                                        });
                                                      });
                                                    });
                                                  });
                                                });
                                              });
                                            });
                                          });
                                        });
                                      });
                                    });
                                  });
                                });
                              });
                            });
                          });
                        });
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
  
      if (_fires) db->bumpFires("deep_fact.slog:7", "delta:Nd", _fires);
  
      if (!_done)
      {
        ReadTask115* _cont = new ReadTask115(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask115(db,b), false);
  // (crule (pre (let __tconst48SJ108 const6b86b273ff34fce19d6b804e) (let __tconst5Uhl106 constd4735e3a265e16eee03f5971) (let __tconst9YpM103 const4e07408562bedb8b60ce05c1) (let __tconst3iHp101 const4b227777d4dd1fc61c6f884f) (let __tconst0Emh97 constef2d127de37b942baad06145) (let __tconst29xA95 conste7f6c011776e8db7cd330b54) (let __tconst9mjQ92 const7902699be42c8a8e46fbbb45) (let __tconst9Yxv90 const2c624232cdd221771294dfbb) (let __tconst7wWY85 const19581e27de7ced00ff1ce50b) (let __tconst01Wl83 const4a44dc15364204a80fe80e90) (let __tconst42lR80 const4fc82b26aecb47d2868c4efb) (let __tconst3KyY78 const6b51d431df5d7f141cbececc) (let __tconst6a9N74 const3fdba35f04dc8c462986c992) (let __tconst74Qx72 const8527a891e224136950ff32ca) (let __tconst2hOw69 conste629fa6598d732768f7c726b) (let __tconst7kHD67 constb17ef6d19c7a5b1ee83b907c) (let __tconst5zmq61 const4523540f1504cd17100c4835) (let __tconst31qC59 const4ec9599fc203d176a301536c) (let __tconst4Vop56 const9400f1b21cb527d7fa3d3eab) (let __tconst51zc54 constf5ca38f748a1d6eaf726b8a4) (let __tconst6Qm150 const6f4b6612125fb3a0daecd279) (let __tconst6bEj48 const785f3ec7eb32f30b90cd0fcf) (let __tconst7AKN45 const535fa30d7e25dd8a49f15367) (let __tconst9j2a43 constc2356069e9d1e79ca9243781) (let __tconst1Mto38 constb7a56873cd771f2c446d369b) (let __tconst8u8i36 const5f9c4ab08cac7457e9111a30) (let __tconst2Isx33 const670671cd97404156226e5079) (let __tconst8J6R31 const59e19706d51d39f66711c265) (let __tconst88cs27 const35135aaa6cc23891b40cb3f3) (let __tconst0Uuf25 const624b60c58c9d8bfb6ff1886c) (let __tconst6sf622 consteb1e33e8a81b697b75855af6) (let __tconst5Run20 conste29c9c180c6279b0b02abd6a)) (seeded) (body (join Lf (1 0) 1 __tconst5Run20 __t8mDO21) (exists Nd (2 1 0) 1 __t8mDO21) (exists Lf (1 0) 1 __tconst0Uuf25) (exists Lf (1 0) 1 __tconst88cs27) (exists Lf (1 0) 1 __tconst8J6R31) (exists Lf (1 0) 1 __tconst2Isx33) (exists Lf (1 0) 1 __tconst8u8i36) (exists Lf (1 0) 1 __tconst1Mto38) (exists Lf (1 0) 1 __tconst9j2a43) (exists Lf (1 0) 1 __tconst7AKN45) (exists Lf (1 0) 1 __tconst6bEj48) (exists Lf (1 0) 1 __tconst6Qm150) (exists Lf (1 0) 1 __tconst51zc54) (exists Lf (1 0) 1 __tconst4Vop56) (exists Lf (1 0) 1 __tconst31qC59) (exists Lf (1 0) 1 __tconst5zmq61) (exists Lf (1 0) 1 __tconst7kHD67) (exists Lf (1 0) 1 __tconst2hOw69) (exists Lf (1 0) 1 __tconst74Qx72) (exists Lf (1 0) 1 __tconst6a9N74) (exists Lf (1 0) 1 __tconst3KyY78) (exists Lf (1 0) 1 __tconst42lR80) (exists Lf (1 0) 1 __tconst01Wl83) (exists Lf (1 0) 1 __tconst7wWY85) (exists Lf (1 0) 1 __tconst9Yxv90) (exists Lf (1 0) 1 __tconst9mjQ92) (exists Lf (1 0) 1 __tconst29xA95) (exists Lf (1 0) 1 __tconst0Emh97) (exists Lf (1 0) 1 __tconst3iHp101) (exists Lf (1 0) 1 __tconst9YpM103) (exists Lf (1 0) 1 __tconst5Uhl106) (exists Lf (1 0) 1 __tconst48SJ108) (join Lf (1 0) 1 __tconst6sf622 __t1M8o23) (join Nd (2 1 0) 2 __t8mDO21 __t1M8o23 __t7LF824) (exists Nd (2 1 0) 1 __t7LF824) (join Lf (1 0) 1 __tconst0Uuf25 __t1NQv26) (exists Nd (2 1 0) 1 __t1NQv26) (join Lf (1 0) 1 __tconst88cs27 __t7d0c28) (join Nd (2 1 0) 2 __t1NQv26 __t7d0c28 __t0kIY29) (join Nd (2 1 0) 2 __t7LF824 __t0kIY29 __t6JrG30) (exists Nd (2 1 0) 1 __t6JrG30) (join Lf (1 0) 1 __tconst8J6R31 __t9vh832) (exists Nd (2 1 0) 1 __t9vh832) (join Lf (1 0) 1 __tconst2Isx33 __t5flt34) (join Nd (2 1 0) 2 __t9vh832 __t5flt34 __t3jHg35) (exists Nd (2 1 0) 1 __t3jHg35) (join Lf (1 0) 1 __tconst8u8i36 __t27Zr37) (exists Nd (2 1 0) 1 __t27Zr37) (join Lf (1 0) 1 __tconst1Mto38 __t3UFu39) (join Nd (2 1 0) 2 __t27Zr37 __t3UFu39 __t8qqV40) (join Nd (2 1 0) 2 __t3jHg35 __t8qqV40 __t2KtK41) (join Nd (2 1 0) 2 __t6JrG30 __t2KtK41 __t17Jm42) (join Lf (1 0) 1 __tconst9j2a43 __t6IKq44) (exists Nd (2 1 0) 1 __t6IKq44) (join Lf (1 0) 1 __tconst7AKN45 __t6LIW46) (join Nd (2 1 0) 2 __t6IKq44 __t6LIW46 __t7C7d47) (exists Nd (2 1 0) 1 __t7C7d47) (join Lf (1 0) 1 __tconst6bEj48 __t9k7a49) (exists Nd (2 1 0) 1 __t9k7a49) (join Lf (1 0) 1 __tconst6Qm150 __t4MdC51) (join Nd (2 1 0) 2 __t9k7a49 __t4MdC51 __t8A9i52) (join Nd (2 1 0) 2 __t7C7d47 __t8A9i52 __t7DSY53) (exists Nd (2 1 0) 1 __t7DSY53) (join Lf (1 0) 1 __tconst51zc54 __t3Yon55) (exists Nd (2 1 0) 1 __t3Yon55) (join Lf (1 0) 1 __tconst4Vop56 __t5ik157) (join Nd (2 1 0) 2 __t3Yon55 __t5ik157 __t4hi358) (exists Nd (2 1 0) 1 __t4hi358) (join Lf (1 0) 1 __tconst31qC59 __t1nkJ60) (exists Nd (2 1 0) 1 __t1nkJ60) (join Lf (1 0) 1 __tconst5zmq61 __t4E3D62) (join Nd (2 1 0) 2 __t1nkJ60 __t4E3D62 __t8TXU63) (join Nd (2 1 0) 2 __t4hi358 __t8TXU63 __t6bZq64) (join Nd (2 1 0) 2 __t7DSY53 __t6bZq64 __t4uRs65) (join Lf (1 0) 1 __tconst7kHD67 __t4J2N68) (exists Nd (2 1 0) 1 __t4J2N68) (join Lf (1 0) 1 __tconst2hOw69 __t4izo70) (join Nd (2 1 0) 2 __t4J2N68 __t4izo70 __t14Ff71) (exists Nd (2 1 0) 1 __t14Ff71) (join Lf (1 0) 1 __tconst74Qx72 __t319l73) (exists Nd (2 1 0) 1 __t319l73) (join Lf (1 0) 1 __tconst6a9N74 __t0amQ75) (join Nd (2 1 0) 2 __t319l73 __t0amQ75 __t4MUf76) (join Nd (2 1 0) 2 __t14Ff71 __t4MUf76 __t13Wj77) (exists Nd (2 1 0) 1 __t13Wj77) (join Lf (1 0) 1 __tconst3KyY78 __t13gt79) (exists Nd (2 1 0) 1 __t13gt79) (join Lf (1 0) 1 __tconst42lR80 __t3ESz81) (join Nd (2 1 0) 2 __t13gt79 __t3ESz81 __t3WL082) (exists Nd (2 1 0) 1 __t3WL082) (join Lf (1 0) 1 __tconst01Wl83 __t4Da384) (exists Nd (2 1 0) 1 __t4Da384) (join Lf (1 0) 1 __tconst7wWY85 __t91gs86) (join Nd (2 1 0) 2 __t4Da384 __t91gs86 __t02Bu87) (join Nd (2 1 0) 2 __t3WL082 __t02Bu87 __t60KJ88) (join Nd (2 1 0) 2 __t13Wj77 __t60KJ88 __t4p4K89) (join Lf (1 0) 1 __tconst9Yxv90 __t7UaH91) (exists Nd (2 1 0) 1 __t7UaH91) (join Lf (1 0) 1 __tconst9mjQ92 __t6IMg93) (join Nd (2 1 0) 2 __t7UaH91 __t6IMg93 __t2T3i94) (exists Nd (2 1 0) 1 __t2T3i94) (join Lf (1 0) 1 __tconst29xA95 __t2oHE96) (exists Nd (2 1 0) 1 __t2oHE96) (join Lf (1 0) 1 __tconst0Emh97 __t7bue98) (join Nd (2 1 0) 2 __t2oHE96 __t7bue98 __t0HkS99) (join Nd (2 1 0) 2 __t2T3i94 __t0HkS99 __t7PLp100) (exists Nd (2 1 0) 1 __t7PLp100) (join Lf (1 0) 1 __tconst3iHp101 __t5yzC102) (exists Nd (2 1 0) 1 __t5yzC102) (join Lf (1 0) 1 __tconst9YpM103 __t7c21104) (join Nd (2 1 0) 2 __t5yzC102 __t7c21104 __t4bRV105) (exists Nd (2 1 0) 1 __t4bRV105) (join Lf (1 0) 1 __tconst5Uhl106 __t1IJA107) (exists Nd (2 1 0) 1 __t1IJA107) (join Lf (1 0) 1 __tconst48SJ108 __t0y5t109) (join Nd (2 1 0) 2 __t1IJA107 __t0y5t109 __t76VS110) (join Nd (2 1 0) 2 __t4bRV105 __t76VS110 __t3a3T111) (join Nd (2 1 0) 2 __t7PLp100 __t3a3T111 __t9dGZ112)) (head (mkstruct Nd (2 1 0) __t09Ym113 __t4p4K89 __t9dGZ112) (mkstruct Nd (2 1 0) __t4LVF66 __t17Jm42 __t4uRs65)) deep_fact.slog:7 #f)
  class ReadTask525 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
  
  
  
  
  
    slog::Index** Lfindex407;  slog::Index** Ndindex408;  slog::Index** Lfindex409;  slog::Index** Lfindex410;  slog::Index** Lfindex411;  slog::Index** Lfindex412;  slog::Index** Lfindex413;  slog::Index** Lfindex414;  slog::Index** Lfindex415;  slog::Index** Lfindex416;  slog::Index** Lfindex417;  slog::Index** Lfindex418;  slog::Index** Lfindex419;  slog::Index** Lfindex420;  slog::Index** Lfindex421;  slog::Index** Lfindex422;  slog::Index** Lfindex423;  slog::Index** Lfindex424;  slog::Index** Lfindex425;  slog::Index** Lfindex426;  slog::Index** Lfindex427;  slog::Index** Lfindex428;  slog::Index** Lfindex429;  slog::Index** Lfindex430;  slog::Index** Lfindex431;  slog::Index** Lfindex432;  slog::Index** Lfindex433;  slog::Index** Lfindex434;  slog::Index** Lfindex435;  slog::Index** Lfindex436;  slog::Index** Lfindex437;  slog::Index** Lfindex438;  slog::Index** Lfindex439;  slog::Index** Ndindex440;  slog::Index** Ndindex441;  slog::Index** Lfindex442;  slog::Index** Ndindex443;  slog::Index** Lfindex444;  slog::Index** Ndindex445;  slog::Index** Ndindex446;  slog::Index** Ndindex447;  slog::Index** Lfindex448;  slog::Index** Ndindex449;  slog::Index** Lfindex450;  slog::Index** Ndindex451;  slog::Index** Ndindex452;  slog::Index** Lfindex453;  slog::Index** Ndindex454;  slog::Index** Lfindex455;  slog::Index** Ndindex456;  slog::Index** Ndindex457;  slog::Index** Ndindex458;  slog::Index** Lfindex459;  slog::Index** Ndindex460;  slog::Index** Lfindex461;  slog::Index** Ndindex462;  slog::Index** Ndindex463;  slog::Index** Lfindex464;  slog::Index** Ndindex465;  slog::Index** Lfindex466;  slog::Index** Ndindex467;  slog::Index** Ndindex468;  slog::Index** Ndindex469;  slog::Index** Lfindex470;  slog::Index** Ndindex471;  slog::Index** Lfindex472;  slog::Index** Ndindex473;  slog::Index** Ndindex474;  slog::Index** Lfindex475;  slog::Index** Ndindex476;  slog::Index** Lfindex477;  slog::Index** Ndindex478;  slog::Index** Ndindex479;  slog::Index** Ndindex480;  slog::Index** Lfindex481;  slog::Index** Ndindex482;  slog::Index** Lfindex483;  slog::Index** Ndindex484;  slog::Index** Ndindex485;  slog::Index** Lfindex486;  slog::Index** Ndindex487;  slog::Index** Lfindex488;  slog::Index** Ndindex489;  slog::Index** Ndindex490;  slog::Index** Ndindex491;  slog::Index** Lfindex492;  slog::Index** Ndindex493;  slog::Index** Lfindex494;  slog::Index** Ndindex495;  slog::Index** Ndindex496;  slog::Index** Lfindex497;  slog::Index** Ndindex498;  slog::Index** Lfindex499;  slog::Index** Ndindex500;  slog::Index** Ndindex501;  slog::Index** Ndindex502;  slog::Index** Lfindex503;  slog::Index** Ndindex504;  slog::Index** Lfindex505;  slog::Index** Ndindex506;  slog::Index** Ndindex507;  slog::Index** Lfindex508;  slog::Index** Ndindex509;  slog::Index** Lfindex510;  slog::Index** Ndindex511;  slog::Index** Ndindex512;  slog::Index** Ndindex513;  slog::Index** Lfindex514;  slog::Index** Ndindex515;  slog::Index** Lfindex516;  slog::Index** Ndindex517;  slog::Index** Ndindex518;  slog::Index** Lfindex519;  slog::Index** Ndindex520;  slog::Index** Lfindex521;  slog::Index** Ndindex522;  slog::Index** Ndindex523;  slog::Index** Ndindex524;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("Nd");
      std::vector<u16> ord526({2, 1, 0});
      slog::Relation* readrel527 = db->getRelation("Nd");
      head_index[0] = readrel527->getIndex(ord526, false);
      head_rel[1] = db->getRelation("Nd");
      std::vector<u16> ord528({2, 1, 0});
      slog::Relation* readrel529 = db->getRelation("Nd");
      head_index[1] = readrel529->getIndex(ord528, false);
      std::vector<u16> ord530({1, 0});
      slog::Relation* readrel531 = db->getRelation("Lf");
      Lfindex407 = readrel531->getIndex(ord530, false);
      std::vector<u16> ord532({2, 1, 0});
      slog::Relation* readrel533 = db->getRelation("Nd");
      Ndindex408 = readrel533->getIndex(ord532, false);
      std::vector<u16> ord534({1, 0});
      slog::Relation* readrel535 = db->getRelation("Lf");
      Lfindex409 = readrel535->getIndex(ord534, false);
      std::vector<u16> ord536({1, 0});
      slog::Relation* readrel537 = db->getRelation("Lf");
      Lfindex410 = readrel537->getIndex(ord536, false);
      std::vector<u16> ord538({1, 0});
      slog::Relation* readrel539 = db->getRelation("Lf");
      Lfindex411 = readrel539->getIndex(ord538, false);
      std::vector<u16> ord540({1, 0});
      slog::Relation* readrel541 = db->getRelation("Lf");
      Lfindex412 = readrel541->getIndex(ord540, false);
      std::vector<u16> ord542({1, 0});
      slog::Relation* readrel543 = db->getRelation("Lf");
      Lfindex413 = readrel543->getIndex(ord542, false);
      std::vector<u16> ord544({1, 0});
      slog::Relation* readrel545 = db->getRelation("Lf");
      Lfindex414 = readrel545->getIndex(ord544, false);
      std::vector<u16> ord546({1, 0});
      slog::Relation* readrel547 = db->getRelation("Lf");
      Lfindex415 = readrel547->getIndex(ord546, false);
      std::vector<u16> ord548({1, 0});
      slog::Relation* readrel549 = db->getRelation("Lf");
      Lfindex416 = readrel549->getIndex(ord548, false);
      std::vector<u16> ord550({1, 0});
      slog::Relation* readrel551 = db->getRelation("Lf");
      Lfindex417 = readrel551->getIndex(ord550, false);
      std::vector<u16> ord552({1, 0});
      slog::Relation* readrel553 = db->getRelation("Lf");
      Lfindex418 = readrel553->getIndex(ord552, false);
      std::vector<u16> ord554({1, 0});
      slog::Relation* readrel555 = db->getRelation("Lf");
      Lfindex419 = readrel555->getIndex(ord554, false);
      std::vector<u16> ord556({1, 0});
      slog::Relation* readrel557 = db->getRelation("Lf");
      Lfindex420 = readrel557->getIndex(ord556, false);
      std::vector<u16> ord558({1, 0});
      slog::Relation* readrel559 = db->getRelation("Lf");
      Lfindex421 = readrel559->getIndex(ord558, false);
      std::vector<u16> ord560({1, 0});
      slog::Relation* readrel561 = db->getRelation("Lf");
      Lfindex422 = readrel561->getIndex(ord560, false);
      std::vector<u16> ord562({1, 0});
      slog::Relation* readrel563 = db->getRelation("Lf");
      Lfindex423 = readrel563->getIndex(ord562, false);
      std::vector<u16> ord564({1, 0});
      slog::Relation* readrel565 = db->getRelation("Lf");
      Lfindex424 = readrel565->getIndex(ord564, false);
      std::vector<u16> ord566({1, 0});
      slog::Relation* readrel567 = db->getRelation("Lf");
      Lfindex425 = readrel567->getIndex(ord566, false);
      std::vector<u16> ord568({1, 0});
      slog::Relation* readrel569 = db->getRelation("Lf");
      Lfindex426 = readrel569->getIndex(ord568, false);
      std::vector<u16> ord570({1, 0});
      slog::Relation* readrel571 = db->getRelation("Lf");
      Lfindex427 = readrel571->getIndex(ord570, false);
      std::vector<u16> ord572({1, 0});
      slog::Relation* readrel573 = db->getRelation("Lf");
      Lfindex428 = readrel573->getIndex(ord572, false);
      std::vector<u16> ord574({1, 0});
      slog::Relation* readrel575 = db->getRelation("Lf");
      Lfindex429 = readrel575->getIndex(ord574, false);
      std::vector<u16> ord576({1, 0});
      slog::Relation* readrel577 = db->getRelation("Lf");
      Lfindex430 = readrel577->getIndex(ord576, false);
      std::vector<u16> ord578({1, 0});
      slog::Relation* readrel579 = db->getRelation("Lf");
      Lfindex431 = readrel579->getIndex(ord578, false);
      std::vector<u16> ord580({1, 0});
      slog::Relation* readrel581 = db->getRelation("Lf");
      Lfindex432 = readrel581->getIndex(ord580, false);
      std::vector<u16> ord582({1, 0});
      slog::Relation* readrel583 = db->getRelation("Lf");
      Lfindex433 = readrel583->getIndex(ord582, false);
      std::vector<u16> ord584({1, 0});
      slog::Relation* readrel585 = db->getRelation("Lf");
      Lfindex434 = readrel585->getIndex(ord584, false);
      std::vector<u16> ord586({1, 0});
      slog::Relation* readrel587 = db->getRelation("Lf");
      Lfindex435 = readrel587->getIndex(ord586, false);
      std::vector<u16> ord588({1, 0});
      slog::Relation* readrel589 = db->getRelation("Lf");
      Lfindex436 = readrel589->getIndex(ord588, false);
      std::vector<u16> ord590({1, 0});
      slog::Relation* readrel591 = db->getRelation("Lf");
      Lfindex437 = readrel591->getIndex(ord590, false);
      std::vector<u16> ord592({1, 0});
      slog::Relation* readrel593 = db->getRelation("Lf");
      Lfindex438 = readrel593->getIndex(ord592, false);
      std::vector<u16> ord594({1, 0});
      slog::Relation* readrel595 = db->getRelation("Lf");
      Lfindex439 = readrel595->getIndex(ord594, false);
      std::vector<u16> ord596({2, 1, 0});
      slog::Relation* readrel597 = db->getRelation("Nd");
      Ndindex440 = readrel597->getIndex(ord596, false);
      std::vector<u16> ord598({2, 1, 0});
      slog::Relation* readrel599 = db->getRelation("Nd");
      Ndindex441 = readrel599->getIndex(ord598, false);
      std::vector<u16> ord600({1, 0});
      slog::Relation* readrel601 = db->getRelation("Lf");
      Lfindex442 = readrel601->getIndex(ord600, false);
      std::vector<u16> ord602({2, 1, 0});
      slog::Relation* readrel603 = db->getRelation("Nd");
      Ndindex443 = readrel603->getIndex(ord602, false);
      std::vector<u16> ord604({1, 0});
      slog::Relation* readrel605 = db->getRelation("Lf");
      Lfindex444 = readrel605->getIndex(ord604, false);
      std::vector<u16> ord606({2, 1, 0});
      slog::Relation* readrel607 = db->getRelation("Nd");
      Ndindex445 = readrel607->getIndex(ord606, false);
      std::vector<u16> ord608({2, 1, 0});
      slog::Relation* readrel609 = db->getRelation("Nd");
      Ndindex446 = readrel609->getIndex(ord608, false);
      std::vector<u16> ord610({2, 1, 0});
      slog::Relation* readrel611 = db->getRelation("Nd");
      Ndindex447 = readrel611->getIndex(ord610, false);
      std::vector<u16> ord612({1, 0});
      slog::Relation* readrel613 = db->getRelation("Lf");
      Lfindex448 = readrel613->getIndex(ord612, false);
      std::vector<u16> ord614({2, 1, 0});
      slog::Relation* readrel615 = db->getRelation("Nd");
      Ndindex449 = readrel615->getIndex(ord614, false);
      std::vector<u16> ord616({1, 0});
      slog::Relation* readrel617 = db->getRelation("Lf");
      Lfindex450 = readrel617->getIndex(ord616, false);
      std::vector<u16> ord618({2, 1, 0});
      slog::Relation* readrel619 = db->getRelation("Nd");
      Ndindex451 = readrel619->getIndex(ord618, false);
      std::vector<u16> ord620({2, 1, 0});
      slog::Relation* readrel621 = db->getRelation("Nd");
      Ndindex452 = readrel621->getIndex(ord620, false);
      std::vector<u16> ord622({1, 0});
      slog::Relation* readrel623 = db->getRelation("Lf");
      Lfindex453 = readrel623->getIndex(ord622, false);
      std::vector<u16> ord624({2, 1, 0});
      slog::Relation* readrel625 = db->getRelation("Nd");
      Ndindex454 = readrel625->getIndex(ord624, false);
      std::vector<u16> ord626({1, 0});
      slog::Relation* readrel627 = db->getRelation("Lf");
      Lfindex455 = readrel627->getIndex(ord626, false);
      std::vector<u16> ord628({2, 1, 0});
      slog::Relation* readrel629 = db->getRelation("Nd");
      Ndindex456 = readrel629->getIndex(ord628, false);
      std::vector<u16> ord630({2, 1, 0});
      slog::Relation* readrel631 = db->getRelation("Nd");
      Ndindex457 = readrel631->getIndex(ord630, false);
      std::vector<u16> ord632({2, 1, 0});
      slog::Relation* readrel633 = db->getRelation("Nd");
      Ndindex458 = readrel633->getIndex(ord632, false);
      std::vector<u16> ord634({1, 0});
      slog::Relation* readrel635 = db->getRelation("Lf");
      Lfindex459 = readrel635->getIndex(ord634, false);
      std::vector<u16> ord636({2, 1, 0});
      slog::Relation* readrel637 = db->getRelation("Nd");
      Ndindex460 = readrel637->getIndex(ord636, false);
      std::vector<u16> ord638({1, 0});
      slog::Relation* readrel639 = db->getRelation("Lf");
      Lfindex461 = readrel639->getIndex(ord638, false);
      std::vector<u16> ord640({2, 1, 0});
      slog::Relation* readrel641 = db->getRelation("Nd");
      Ndindex462 = readrel641->getIndex(ord640, false);
      std::vector<u16> ord642({2, 1, 0});
      slog::Relation* readrel643 = db->getRelation("Nd");
      Ndindex463 = readrel643->getIndex(ord642, false);
      std::vector<u16> ord644({1, 0});
      slog::Relation* readrel645 = db->getRelation("Lf");
      Lfindex464 = readrel645->getIndex(ord644, false);
      std::vector<u16> ord646({2, 1, 0});
      slog::Relation* readrel647 = db->getRelation("Nd");
      Ndindex465 = readrel647->getIndex(ord646, false);
      std::vector<u16> ord648({1, 0});
      slog::Relation* readrel649 = db->getRelation("Lf");
      Lfindex466 = readrel649->getIndex(ord648, false);
      std::vector<u16> ord650({2, 1, 0});
      slog::Relation* readrel651 = db->getRelation("Nd");
      Ndindex467 = readrel651->getIndex(ord650, false);
      std::vector<u16> ord652({2, 1, 0});
      slog::Relation* readrel653 = db->getRelation("Nd");
      Ndindex468 = readrel653->getIndex(ord652, false);
      std::vector<u16> ord654({2, 1, 0});
      slog::Relation* readrel655 = db->getRelation("Nd");
      Ndindex469 = readrel655->getIndex(ord654, false);
      std::vector<u16> ord656({1, 0});
      slog::Relation* readrel657 = db->getRelation("Lf");
      Lfindex470 = readrel657->getIndex(ord656, false);
      std::vector<u16> ord658({2, 1, 0});
      slog::Relation* readrel659 = db->getRelation("Nd");
      Ndindex471 = readrel659->getIndex(ord658, false);
      std::vector<u16> ord660({1, 0});
      slog::Relation* readrel661 = db->getRelation("Lf");
      Lfindex472 = readrel661->getIndex(ord660, false);
      std::vector<u16> ord662({2, 1, 0});
      slog::Relation* readrel663 = db->getRelation("Nd");
      Ndindex473 = readrel663->getIndex(ord662, false);
      std::vector<u16> ord664({2, 1, 0});
      slog::Relation* readrel665 = db->getRelation("Nd");
      Ndindex474 = readrel665->getIndex(ord664, false);
      std::vector<u16> ord666({1, 0});
      slog::Relation* readrel667 = db->getRelation("Lf");
      Lfindex475 = readrel667->getIndex(ord666, false);
      std::vector<u16> ord668({2, 1, 0});
      slog::Relation* readrel669 = db->getRelation("Nd");
      Ndindex476 = readrel669->getIndex(ord668, false);
      std::vector<u16> ord670({1, 0});
      slog::Relation* readrel671 = db->getRelation("Lf");
      Lfindex477 = readrel671->getIndex(ord670, false);
      std::vector<u16> ord672({2, 1, 0});
      slog::Relation* readrel673 = db->getRelation("Nd");
      Ndindex478 = readrel673->getIndex(ord672, false);
      std::vector<u16> ord674({2, 1, 0});
      slog::Relation* readrel675 = db->getRelation("Nd");
      Ndindex479 = readrel675->getIndex(ord674, false);
      std::vector<u16> ord676({2, 1, 0});
      slog::Relation* readrel677 = db->getRelation("Nd");
      Ndindex480 = readrel677->getIndex(ord676, false);
      std::vector<u16> ord678({1, 0});
      slog::Relation* readrel679 = db->getRelation("Lf");
      Lfindex481 = readrel679->getIndex(ord678, false);
      std::vector<u16> ord680({2, 1, 0});
      slog::Relation* readrel681 = db->getRelation("Nd");
      Ndindex482 = readrel681->getIndex(ord680, false);
      std::vector<u16> ord682({1, 0});
      slog::Relation* readrel683 = db->getRelation("Lf");
      Lfindex483 = readrel683->getIndex(ord682, false);
      std::vector<u16> ord684({2, 1, 0});
      slog::Relation* readrel685 = db->getRelation("Nd");
      Ndindex484 = readrel685->getIndex(ord684, false);
      std::vector<u16> ord686({2, 1, 0});
      slog::Relation* readrel687 = db->getRelation("Nd");
      Ndindex485 = readrel687->getIndex(ord686, false);
      std::vector<u16> ord688({1, 0});
      slog::Relation* readrel689 = db->getRelation("Lf");
      Lfindex486 = readrel689->getIndex(ord688, false);
      std::vector<u16> ord690({2, 1, 0});
      slog::Relation* readrel691 = db->getRelation("Nd");
      Ndindex487 = readrel691->getIndex(ord690, false);
      std::vector<u16> ord692({1, 0});
      slog::Relation* readrel693 = db->getRelation("Lf");
      Lfindex488 = readrel693->getIndex(ord692, false);
      std::vector<u16> ord694({2, 1, 0});
      slog::Relation* readrel695 = db->getRelation("Nd");
      Ndindex489 = readrel695->getIndex(ord694, false);
      std::vector<u16> ord696({2, 1, 0});
      slog::Relation* readrel697 = db->getRelation("Nd");
      Ndindex490 = readrel697->getIndex(ord696, false);
      std::vector<u16> ord698({2, 1, 0});
      slog::Relation* readrel699 = db->getRelation("Nd");
      Ndindex491 = readrel699->getIndex(ord698, false);
      std::vector<u16> ord700({1, 0});
      slog::Relation* readrel701 = db->getRelation("Lf");
      Lfindex492 = readrel701->getIndex(ord700, false);
      std::vector<u16> ord702({2, 1, 0});
      slog::Relation* readrel703 = db->getRelation("Nd");
      Ndindex493 = readrel703->getIndex(ord702, false);
      std::vector<u16> ord704({1, 0});
      slog::Relation* readrel705 = db->getRelation("Lf");
      Lfindex494 = readrel705->getIndex(ord704, false);
      std::vector<u16> ord706({2, 1, 0});
      slog::Relation* readrel707 = db->getRelation("Nd");
      Ndindex495 = readrel707->getIndex(ord706, false);
      std::vector<u16> ord708({2, 1, 0});
      slog::Relation* readrel709 = db->getRelation("Nd");
      Ndindex496 = readrel709->getIndex(ord708, false);
      std::vector<u16> ord710({1, 0});
      slog::Relation* readrel711 = db->getRelation("Lf");
      Lfindex497 = readrel711->getIndex(ord710, false);
      std::vector<u16> ord712({2, 1, 0});
      slog::Relation* readrel713 = db->getRelation("Nd");
      Ndindex498 = readrel713->getIndex(ord712, false);
      std::vector<u16> ord714({1, 0});
      slog::Relation* readrel715 = db->getRelation("Lf");
      Lfindex499 = readrel715->getIndex(ord714, false);
      std::vector<u16> ord716({2, 1, 0});
      slog::Relation* readrel717 = db->getRelation("Nd");
      Ndindex500 = readrel717->getIndex(ord716, false);
      std::vector<u16> ord718({2, 1, 0});
      slog::Relation* readrel719 = db->getRelation("Nd");
      Ndindex501 = readrel719->getIndex(ord718, false);
      std::vector<u16> ord720({2, 1, 0});
      slog::Relation* readrel721 = db->getRelation("Nd");
      Ndindex502 = readrel721->getIndex(ord720, false);
      std::vector<u16> ord722({1, 0});
      slog::Relation* readrel723 = db->getRelation("Lf");
      Lfindex503 = readrel723->getIndex(ord722, false);
      std::vector<u16> ord724({2, 1, 0});
      slog::Relation* readrel725 = db->getRelation("Nd");
      Ndindex504 = readrel725->getIndex(ord724, false);
      std::vector<u16> ord726({1, 0});
      slog::Relation* readrel727 = db->getRelation("Lf");
      Lfindex505 = readrel727->getIndex(ord726, false);
      std::vector<u16> ord728({2, 1, 0});
      slog::Relation* readrel729 = db->getRelation("Nd");
      Ndindex506 = readrel729->getIndex(ord728, false);
      std::vector<u16> ord730({2, 1, 0});
      slog::Relation* readrel731 = db->getRelation("Nd");
      Ndindex507 = readrel731->getIndex(ord730, false);
      std::vector<u16> ord732({1, 0});
      slog::Relation* readrel733 = db->getRelation("Lf");
      Lfindex508 = readrel733->getIndex(ord732, false);
      std::vector<u16> ord734({2, 1, 0});
      slog::Relation* readrel735 = db->getRelation("Nd");
      Ndindex509 = readrel735->getIndex(ord734, false);
      std::vector<u16> ord736({1, 0});
      slog::Relation* readrel737 = db->getRelation("Lf");
      Lfindex510 = readrel737->getIndex(ord736, false);
      std::vector<u16> ord738({2, 1, 0});
      slog::Relation* readrel739 = db->getRelation("Nd");
      Ndindex511 = readrel739->getIndex(ord738, false);
      std::vector<u16> ord740({2, 1, 0});
      slog::Relation* readrel741 = db->getRelation("Nd");
      Ndindex512 = readrel741->getIndex(ord740, false);
      std::vector<u16> ord742({2, 1, 0});
      slog::Relation* readrel743 = db->getRelation("Nd");
      Ndindex513 = readrel743->getIndex(ord742, false);
      std::vector<u16> ord744({1, 0});
      slog::Relation* readrel745 = db->getRelation("Lf");
      Lfindex514 = readrel745->getIndex(ord744, false);
      std::vector<u16> ord746({2, 1, 0});
      slog::Relation* readrel747 = db->getRelation("Nd");
      Ndindex515 = readrel747->getIndex(ord746, false);
      std::vector<u16> ord748({1, 0});
      slog::Relation* readrel749 = db->getRelation("Lf");
      Lfindex516 = readrel749->getIndex(ord748, false);
      std::vector<u16> ord750({2, 1, 0});
      slog::Relation* readrel751 = db->getRelation("Nd");
      Ndindex517 = readrel751->getIndex(ord750, false);
      std::vector<u16> ord752({2, 1, 0});
      slog::Relation* readrel753 = db->getRelation("Nd");
      Ndindex518 = readrel753->getIndex(ord752, false);
      std::vector<u16> ord754({1, 0});
      slog::Relation* readrel755 = db->getRelation("Lf");
      Lfindex519 = readrel755->getIndex(ord754, false);
      std::vector<u16> ord756({2, 1, 0});
      slog::Relation* readrel757 = db->getRelation("Nd");
      Ndindex520 = readrel757->getIndex(ord756, false);
      std::vector<u16> ord758({1, 0});
      slog::Relation* readrel759 = db->getRelation("Lf");
      Lfindex521 = readrel759->getIndex(ord758, false);
      std::vector<u16> ord760({2, 1, 0});
      slog::Relation* readrel761 = db->getRelation("Nd");
      Ndindex522 = readrel761->getIndex(ord760, false);
      std::vector<u16> ord762({2, 1, 0});
      slog::Relation* readrel763 = db->getRelation("Nd");
      Ndindex523 = readrel763->getIndex(ord762, false);
      std::vector<u16> ord764({2, 1, 0});
      slog::Relation* readrel765 = db->getRelation("Nd");
      Ndindex524 = readrel765->getIndex(ord764, false);
  
    }
    ReadTask525(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(Lfindex407, std::array<u64,2>{v_c31, 0}, [&](const std::array<u64,2>& m766) {
        u64 v_c35 = m766[1];
        if (!slog::exists_probe<3,1>(Ndindex408, std::array<u64,3>{v_c35, 0, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex409, std::array<u64,2>{v_c29, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex410, std::array<u64,2>{v_c28, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex411, std::array<u64,2>{v_c27, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex412, std::array<u64,2>{v_c26, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex413, std::array<u64,2>{v_c25, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex414, std::array<u64,2>{v_c24, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex415, std::array<u64,2>{v_c23, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex416, std::array<u64,2>{v_c22, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex417, std::array<u64,2>{v_c21, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex418, std::array<u64,2>{v_c20, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex419, std::array<u64,2>{v_c19, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex420, std::array<u64,2>{v_c18, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex421, std::array<u64,2>{v_c17, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex422, std::array<u64,2>{v_c16, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex423, std::array<u64,2>{v_c15, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex424, std::array<u64,2>{v_c14, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex425, std::array<u64,2>{v_c13, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex426, std::array<u64,2>{v_c12, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex427, std::array<u64,2>{v_c11, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex428, std::array<u64,2>{v_c10, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex429, std::array<u64,2>{v_c9, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex430, std::array<u64,2>{v_c8, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex431, std::array<u64,2>{v_c7, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex432, std::array<u64,2>{v_c6, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex433, std::array<u64,2>{v_c5, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex434, std::array<u64,2>{v_c4, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex435, std::array<u64,2>{v_c3, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex436, std::array<u64,2>{v_c2, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex437, std::array<u64,2>{v_c1, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex438, std::array<u64,2>{v_c0, 0})) return;
        slog::join_probe<2,1>(Lfindex439, std::array<u64,2>{v_c30, 0}, [&](const std::array<u64,2>& m767) {
          u64 v_c36 = m767[1];
          slog::join_probe<3,2>(Ndindex440, std::array<u64,3>{v_c35, v_c36, 0}, [&](const std::array<u64,3>& m768) {
            u64 v_c37 = m768[2];
            if (!slog::exists_probe<3,1>(Ndindex441, std::array<u64,3>{v_c37, 0, 0})) return;
            slog::join_probe<2,1>(Lfindex442, std::array<u64,2>{v_c29, 0}, [&](const std::array<u64,2>& m769) {
              u64 v_c38 = m769[1];
              if (!slog::exists_probe<3,1>(Ndindex443, std::array<u64,3>{v_c38, 0, 0})) return;
              slog::join_probe<2,1>(Lfindex444, std::array<u64,2>{v_c28, 0}, [&](const std::array<u64,2>& m770) {
                u64 v_c39 = m770[1];
                slog::join_probe<3,2>(Ndindex445, std::array<u64,3>{v_c38, v_c39, 0}, [&](const std::array<u64,3>& m771) {
                  u64 v_c40 = m771[2];
                  slog::join_probe<3,2>(Ndindex446, std::array<u64,3>{v_c37, v_c40, 0}, [&](const std::array<u64,3>& m772) {
                    u64 v_c41 = m772[2];
                    if (!slog::exists_probe<3,1>(Ndindex447, std::array<u64,3>{v_c41, 0, 0})) return;
                    slog::join_probe<2,1>(Lfindex448, std::array<u64,2>{v_c27, 0}, [&](const std::array<u64,2>& m773) {
                      u64 v_c43 = m773[1];
                      if (!slog::exists_probe<3,1>(Ndindex449, std::array<u64,3>{v_c43, 0, 0})) return;
                      slog::join_probe<2,1>(Lfindex450, std::array<u64,2>{v_c26, 0}, [&](const std::array<u64,2>& m774) {
                        u64 v_c44 = m774[1];
                        slog::join_probe<3,2>(Ndindex451, std::array<u64,3>{v_c43, v_c44, 0}, [&](const std::array<u64,3>& m775) {
                          u64 v_c45 = m775[2];
                          if (!slog::exists_probe<3,1>(Ndindex452, std::array<u64,3>{v_c45, 0, 0})) return;
                          slog::join_probe<2,1>(Lfindex453, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m776) {
                            u64 v_c47 = m776[1];
                            if (!slog::exists_probe<3,1>(Ndindex454, std::array<u64,3>{v_c47, 0, 0})) return;
                            slog::join_probe<2,1>(Lfindex455, std::array<u64,2>{v_c24, 0}, [&](const std::array<u64,2>& m777) {
                              u64 v_c48 = m777[1];
                              slog::join_probe<3,2>(Ndindex456, std::array<u64,3>{v_c47, v_c48, 0}, [&](const std::array<u64,3>& m778) {
                                u64 v_c46 = m778[2];
                                slog::join_probe<3,2>(Ndindex457, std::array<u64,3>{v_c45, v_c46, 0}, [&](const std::array<u64,3>& m779) {
                                  u64 v_c42 = m779[2];
                                  slog::join_probe<3,2>(Ndindex458, std::array<u64,3>{v_c41, v_c42, 0}, [&](const std::array<u64,3>& m780) {
                                    u64 v_c34 = m780[2];
                                    slog::join_probe<2,1>(Lfindex459, std::array<u64,2>{v_c23, 0}, [&](const std::array<u64,2>& m781) {
                                      u64 v_c49 = m781[1];
                                      if (!slog::exists_probe<3,1>(Ndindex460, std::array<u64,3>{v_c49, 0, 0})) return;
                                      slog::join_probe<2,1>(Lfindex461, std::array<u64,2>{v_c22, 0}, [&](const std::array<u64,2>& m782) {
                                        u64 v_c50 = m782[1];
                                        slog::join_probe<3,2>(Ndindex462, std::array<u64,3>{v_c49, v_c50, 0}, [&](const std::array<u64,3>& m783) {
                                          u64 v_c51 = m783[2];
                                          if (!slog::exists_probe<3,1>(Ndindex463, std::array<u64,3>{v_c51, 0, 0})) return;
                                          slog::join_probe<2,1>(Lfindex464, std::array<u64,2>{v_c21, 0}, [&](const std::array<u64,2>& m784) {
                                            u64 v_c52 = m784[1];
                                            if (!slog::exists_probe<3,1>(Ndindex465, std::array<u64,3>{v_c52, 0, 0})) return;
                                            slog::join_probe<2,1>(Lfindex466, std::array<u64,2>{v_c20, 0}, [&](const std::array<u64,2>& m785) {
                                              u64 v_c53 = m785[1];
                                              slog::join_probe<3,2>(Ndindex467, std::array<u64,3>{v_c52, v_c53, 0}, [&](const std::array<u64,3>& m786) {
                                                u64 v_c54 = m786[2];
                                                slog::join_probe<3,2>(Ndindex468, std::array<u64,3>{v_c51, v_c54, 0}, [&](const std::array<u64,3>& m787) {
                                                  u64 v_c55 = m787[2];
                                                  if (!slog::exists_probe<3,1>(Ndindex469, std::array<u64,3>{v_c55, 0, 0})) return;
                                                  slog::join_probe<2,1>(Lfindex470, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m788) {
                                                    u64 v_c57 = m788[1];
                                                    if (!slog::exists_probe<3,1>(Ndindex471, std::array<u64,3>{v_c57, 0, 0})) return;
                                                    slog::join_probe<2,1>(Lfindex472, std::array<u64,2>{v_c18, 0}, [&](const std::array<u64,2>& m789) {
                                                      u64 v_c58 = m789[1];
                                                      slog::join_probe<3,2>(Ndindex473, std::array<u64,3>{v_c57, v_c58, 0}, [&](const std::array<u64,3>& m790) {
                                                        u64 v_c59 = m790[2];
                                                        if (!slog::exists_probe<3,1>(Ndindex474, std::array<u64,3>{v_c59, 0, 0})) return;
                                                        slog::join_probe<2,1>(Lfindex475, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m791) {
                                                          u64 v_c61 = m791[1];
                                                          if (!slog::exists_probe<3,1>(Ndindex476, std::array<u64,3>{v_c61, 0, 0})) return;
                                                          slog::join_probe<2,1>(Lfindex477, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m792) {
                                                            u64 v_c62 = m792[1];
                                                            slog::join_probe<3,2>(Ndindex478, std::array<u64,3>{v_c61, v_c62, 0}, [&](const std::array<u64,3>& m793) {
                                                              u64 v_c60 = m793[2];
                                                              slog::join_probe<3,2>(Ndindex479, std::array<u64,3>{v_c59, v_c60, 0}, [&](const std::array<u64,3>& m794) {
                                                                u64 v_c56 = m794[2];
                                                                slog::join_probe<3,2>(Ndindex480, std::array<u64,3>{v_c55, v_c56, 0}, [&](const std::array<u64,3>& m795) {
                                                                  u64 v_c33 = m795[2];
                                                                  slog::join_probe<2,1>(Lfindex481, std::array<u64,2>{v_c15, 0}, [&](const std::array<u64,2>& m796) {
                                                                    u64 v_c63 = m796[1];
                                                                    if (!slog::exists_probe<3,1>(Ndindex482, std::array<u64,3>{v_c63, 0, 0})) return;
                                                                    slog::join_probe<2,1>(Lfindex483, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m797) {
                                                                      u64 v_c64 = m797[1];
                                                                      slog::join_probe<3,2>(Ndindex484, std::array<u64,3>{v_c63, v_c64, 0}, [&](const std::array<u64,3>& m798) {
                                                                        u64 v_c65 = m798[2];
                                                                        if (!slog::exists_probe<3,1>(Ndindex485, std::array<u64,3>{v_c65, 0, 0})) return;
                                                                        slog::join_probe<2,1>(Lfindex486, std::array<u64,2>{v_c13, 0}, [&](const std::array<u64,2>& m799) {
                                                                          u64 v_c66 = m799[1];
                                                                          if (!slog::exists_probe<3,1>(Ndindex487, std::array<u64,3>{v_c66, 0, 0})) return;
                                                                          slog::join_probe<2,1>(Lfindex488, std::array<u64,2>{v_c12, 0}, [&](const std::array<u64,2>& m800) {
                                                                            u64 v_c67 = m800[1];
                                                                            slog::join_probe<3,2>(Ndindex489, std::array<u64,3>{v_c66, v_c67, 0}, [&](const std::array<u64,3>& m801) {
                                                                              u64 v_c68 = m801[2];
                                                                              slog::join_probe<3,2>(Ndindex490, std::array<u64,3>{v_c65, v_c68, 0}, [&](const std::array<u64,3>& m802) {
                                                                                u64 v_c69 = m802[2];
                                                                                if (!slog::exists_probe<3,1>(Ndindex491, std::array<u64,3>{v_c69, 0, 0})) return;
                                                                                slog::join_probe<2,1>(Lfindex492, std::array<u64,2>{v_c11, 0}, [&](const std::array<u64,2>& m803) {
                                                                                  u64 v_c70 = m803[1];
                                                                                  if (!slog::exists_probe<3,1>(Ndindex493, std::array<u64,3>{v_c70, 0, 0})) return;
                                                                                  slog::join_probe<2,1>(Lfindex494, std::array<u64,2>{v_c10, 0}, [&](const std::array<u64,2>& m804) {
                                                                                    u64 v_c71 = m804[1];
                                                                                    slog::join_probe<3,2>(Ndindex495, std::array<u64,3>{v_c70, v_c71, 0}, [&](const std::array<u64,3>& m805) {
                                                                                      u64 v_c72 = m805[2];
                                                                                      if (!slog::exists_probe<3,1>(Ndindex496, std::array<u64,3>{v_c72, 0, 0})) return;
                                                                                      slog::join_probe<2,1>(Lfindex497, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m806) {
                                                                                        u64 v_c73 = m806[1];
                                                                                        if (!slog::exists_probe<3,1>(Ndindex498, std::array<u64,3>{v_c73, 0, 0})) return;
                                                                                        slog::join_probe<2,1>(Lfindex499, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m807) {
                                                                                          u64 v_c74 = m807[1];
                                                                                          slog::join_probe<3,2>(Ndindex500, std::array<u64,3>{v_c73, v_c74, 0}, [&](const std::array<u64,3>& m808) {
                                                                                            u64 v_c75 = m808[2];
                                                                                            slog::join_probe<3,2>(Ndindex501, std::array<u64,3>{v_c72, v_c75, 0}, [&](const std::array<u64,3>& m809) {
                                                                                              u64 v_c76 = m809[2];
                                                                                              slog::join_probe<3,2>(Ndindex502, std::array<u64,3>{v_c69, v_c76, 0}, [&](const std::array<u64,3>& m810) {
                                                                                                u64 v_c77 = m810[2];
                                                                                                slog::join_probe<2,1>(Lfindex503, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m811) {
                                                                                                  u64 v_c78 = m811[1];
                                                                                                  if (!slog::exists_probe<3,1>(Ndindex504, std::array<u64,3>{v_c78, 0, 0})) return;
                                                                                                  slog::join_probe<2,1>(Lfindex505, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m812) {
                                                                                                    u64 v_c79 = m812[1];
                                                                                                    slog::join_probe<3,2>(Ndindex506, std::array<u64,3>{v_c78, v_c79, 0}, [&](const std::array<u64,3>& m813) {
                                                                                                      u64 v_c80 = m813[2];
                                                                                                      if (!slog::exists_probe<3,1>(Ndindex507, std::array<u64,3>{v_c80, 0, 0})) return;
                                                                                                      slog::join_probe<2,1>(Lfindex508, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m814) {
                                                                                                        u64 v_c81 = m814[1];
                                                                                                        if (!slog::exists_probe<3,1>(Ndindex509, std::array<u64,3>{v_c81, 0, 0})) return;
                                                                                                        slog::join_probe<2,1>(Lfindex510, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m815) {
                                                                                                          u64 v_c82 = m815[1];
                                                                                                          slog::join_probe<3,2>(Ndindex511, std::array<u64,3>{v_c81, v_c82, 0}, [&](const std::array<u64,3>& m816) {
                                                                                                            u64 v_c83 = m816[2];
                                                                                                            slog::join_probe<3,2>(Ndindex512, std::array<u64,3>{v_c80, v_c83, 0}, [&](const std::array<u64,3>& m817) {
                                                                                                              u64 v_c84 = m817[2];
                                                                                                              if (!slog::exists_probe<3,1>(Ndindex513, std::array<u64,3>{v_c84, 0, 0})) return;
                                                                                                              slog::join_probe<2,1>(Lfindex514, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m818) {
                                                                                                                u64 v_c85 = m818[1];
                                                                                                                if (!slog::exists_probe<3,1>(Ndindex515, std::array<u64,3>{v_c85, 0, 0})) return;
                                                                                                                slog::join_probe<2,1>(Lfindex516, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m819) {
                                                                                                                  u64 v_c86 = m819[1];
                                                                                                                  slog::join_probe<3,2>(Ndindex517, std::array<u64,3>{v_c85, v_c86, 0}, [&](const std::array<u64,3>& m820) {
                                                                                                                    u64 v_c87 = m820[2];
                                                                                                                    if (!slog::exists_probe<3,1>(Ndindex518, std::array<u64,3>{v_c87, 0, 0})) return;
                                                                                                                    slog::join_probe<2,1>(Lfindex519, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m821) {
                                                                                                                      u64 v_c88 = m821[1];
                                                                                                                      if (!slog::exists_probe<3,1>(Ndindex520, std::array<u64,3>{v_c88, 0, 0})) return;
                                                                                                                      slog::join_probe<2,1>(Lfindex521, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m822) {
                                                                                                                        u64 v_c89 = m822[1];
                                                                                                                        slog::join_probe<3,2>(Ndindex522, std::array<u64,3>{v_c88, v_c89, 0}, [&](const std::array<u64,3>& m823) {
                                                                                                                          u64 v_c90 = m823[2];
                                                                                                                          slog::join_probe<3,2>(Ndindex523, std::array<u64,3>{v_c87, v_c90, 0}, [&](const std::array<u64,3>& m824) {
                                                                                                                            u64 v_c91 = m824[2];
                                                                                                                            slog::join_probe<3,2>(Ndindex524, std::array<u64,3>{v_c84, v_c91, 0}, [&](const std::array<u64,3>& m825) {
                                                                                                                              u64 v_c92 = m825[2];
                                                                                                                              ++_fires;
                                                                                                                              slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c77, v_c92}, std::array<u16,3>{2, 1, 0});
                                                                                                                              slog::emit_struct_checked<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c34, v_c33}, std::array<u16,3>{2, 1, 0});
                                                                                                                            });
                                                                                                                          });
                                                                                                                        });
                                                                                                                      });
                                                                                                                    });
                                                                                                                  });
                                                                                                                });
                                                                                                              });
                                                                                                            });
                                                                                                          });
                                                                                                        });
                                                                                                      });
                                                                                                    });
                                                                                                  });
                                                                                                });
                                                                                              });
                                                                                            });
                                                                                          });
                                                                                        });
                                                                                      });
                                                                                    });
                                                                                  });
                                                                                });
                                                                              });
                                                                            });
                                                                          });
                                                                        });
                                                                      });
                                                                    });
                                                                  });
                                                                });
                                                              });
                                                            });
                                                          });
                                                        });
                                                      });
                                                    });
                                                  });
                                                });
                                              });
                                            });
                                          });
                                        });
                                      });
                                    });
                                  });
                                });
                              });
                            });
                          });
                        });
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
  
      if (_fires) db->bumpFires("deep_fact.slog:7", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask525(db,b));
  // (crule (pre (let __tconst48SJ108 const6b86b273ff34fce19d6b804e) (let __tconst5Uhl106 constd4735e3a265e16eee03f5971) (let __tconst9YpM103 const4e07408562bedb8b60ce05c1) (let __tconst3iHp101 const4b227777d4dd1fc61c6f884f) (let __tconst0Emh97 constef2d127de37b942baad06145) (let __tconst29xA95 conste7f6c011776e8db7cd330b54) (let __tconst9mjQ92 const7902699be42c8a8e46fbbb45) (let __tconst9Yxv90 const2c624232cdd221771294dfbb) (let __tconst7wWY85 const19581e27de7ced00ff1ce50b) (let __tconst01Wl83 const4a44dc15364204a80fe80e90) (let __tconst42lR80 const4fc82b26aecb47d2868c4efb) (let __tconst3KyY78 const6b51d431df5d7f141cbececc) (let __tconst6a9N74 const3fdba35f04dc8c462986c992) (let __tconst74Qx72 const8527a891e224136950ff32ca) (let __tconst2hOw69 conste629fa6598d732768f7c726b) (let __tconst7kHD67 constb17ef6d19c7a5b1ee83b907c) (let __tconst5zmq61 const4523540f1504cd17100c4835) (let __tconst31qC59 const4ec9599fc203d176a301536c) (let __tconst4Vop56 const9400f1b21cb527d7fa3d3eab) (let __tconst51zc54 constf5ca38f748a1d6eaf726b8a4) (let __tconst6Qm150 const6f4b6612125fb3a0daecd279) (let __tconst6bEj48 const785f3ec7eb32f30b90cd0fcf) (let __tconst7AKN45 const535fa30d7e25dd8a49f15367) (let __tconst9j2a43 constc2356069e9d1e79ca9243781) (let __tconst1Mto38 constb7a56873cd771f2c446d369b) (let __tconst8u8i36 const5f9c4ab08cac7457e9111a30) (let __tconst2Isx33 const670671cd97404156226e5079) (let __tconst8J6R31 const59e19706d51d39f66711c265) (let __tconst88cs27 const35135aaa6cc23891b40cb3f3) (let __tconst0Uuf25 const624b60c58c9d8bfb6ff1886c) (let __tconst6sf622 consteb1e33e8a81b697b75855af6) (let __tconst5Run20 conste29c9c180c6279b0b02abd6a)) (once) (body) (head (mkstruct Lf (1 0) __t0y5t109 __tconst48SJ108) (mkstruct Lf (1 0) __t1IJA107 __tconst5Uhl106) (mkstruct Lf (1 0) __t7c21104 __tconst9YpM103) (mkstruct Lf (1 0) __t5yzC102 __tconst3iHp101) (mkstruct Lf (1 0) __t7bue98 __tconst0Emh97) (mkstruct Lf (1 0) __t2oHE96 __tconst29xA95) (mkstruct Lf (1 0) __t6IMg93 __tconst9mjQ92) (mkstruct Lf (1 0) __t7UaH91 __tconst9Yxv90) (mkstruct Lf (1 0) __t91gs86 __tconst7wWY85) (mkstruct Lf (1 0) __t4Da384 __tconst01Wl83) (mkstruct Lf (1 0) __t3ESz81 __tconst42lR80) (mkstruct Lf (1 0) __t13gt79 __tconst3KyY78) (mkstruct Lf (1 0) __t0amQ75 __tconst6a9N74) (mkstruct Lf (1 0) __t319l73 __tconst74Qx72) (mkstruct Lf (1 0) __t4izo70 __tconst2hOw69) (mkstruct Lf (1 0) __t4J2N68 __tconst7kHD67) (mkstruct Lf (1 0) __t4E3D62 __tconst5zmq61) (mkstruct Lf (1 0) __t1nkJ60 __tconst31qC59) (mkstruct Lf (1 0) __t5ik157 __tconst4Vop56) (mkstruct Lf (1 0) __t3Yon55 __tconst51zc54) (mkstruct Lf (1 0) __t4MdC51 __tconst6Qm150) (mkstruct Lf (1 0) __t9k7a49 __tconst6bEj48) (mkstruct Lf (1 0) __t6LIW46 __tconst7AKN45) (mkstruct Lf (1 0) __t6IKq44 __tconst9j2a43) (mkstruct Lf (1 0) __t3UFu39 __tconst1Mto38) (mkstruct Lf (1 0) __t27Zr37 __tconst8u8i36) (mkstruct Lf (1 0) __t5flt34 __tconst2Isx33) (mkstruct Lf (1 0) __t9vh832 __tconst8J6R31) (mkstruct Lf (1 0) __t7d0c28 __tconst88cs27) (mkstruct Lf (1 0) __t1NQv26 __tconst0Uuf25) (mkstruct Lf (1 0) __t1M8o23 __tconst6sf622) (mkstruct Lf (1 0) __t8mDO21 __tconst5Run20)) deep_fact.slog:7 #f)
  class ReadTask826 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[32];
    slog::Index** head_index[32];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("Lf");
      head_rel[1] = db->getRelation("Lf");
      head_rel[2] = db->getRelation("Lf");
      head_rel[3] = db->getRelation("Lf");
      head_rel[4] = db->getRelation("Lf");
      head_rel[5] = db->getRelation("Lf");
      head_rel[6] = db->getRelation("Lf");
      head_rel[7] = db->getRelation("Lf");
      head_rel[8] = db->getRelation("Lf");
      head_rel[9] = db->getRelation("Lf");
      head_rel[10] = db->getRelation("Lf");
      head_rel[11] = db->getRelation("Lf");
      head_rel[12] = db->getRelation("Lf");
      head_rel[13] = db->getRelation("Lf");
      head_rel[14] = db->getRelation("Lf");
      head_rel[15] = db->getRelation("Lf");
      head_rel[16] = db->getRelation("Lf");
      head_rel[17] = db->getRelation("Lf");
      head_rel[18] = db->getRelation("Lf");
      head_rel[19] = db->getRelation("Lf");
      head_rel[20] = db->getRelation("Lf");
      head_rel[21] = db->getRelation("Lf");
      head_rel[22] = db->getRelation("Lf");
      head_rel[23] = db->getRelation("Lf");
      head_rel[24] = db->getRelation("Lf");
      head_rel[25] = db->getRelation("Lf");
      head_rel[26] = db->getRelation("Lf");
      head_rel[27] = db->getRelation("Lf");
      head_rel[28] = db->getRelation("Lf");
      head_rel[29] = db->getRelation("Lf");
      head_rel[30] = db->getRelation("Lf");
      head_rel[31] = db->getRelation("Lf");
  
    }
    ReadTask826(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[32];
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
  
      ++_fires;
      slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c0}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c1}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[2], newbatch[2], std::array<u64,1>{v_c2}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[3], newbatch[3], std::array<u64,1>{v_c3}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[4], newbatch[4], std::array<u64,1>{v_c4}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[5], newbatch[5], std::array<u64,1>{v_c5}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[6], newbatch[6], std::array<u64,1>{v_c6}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[7], newbatch[7], std::array<u64,1>{v_c7}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[8], newbatch[8], std::array<u64,1>{v_c8}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[9], newbatch[9], std::array<u64,1>{v_c9}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[10], newbatch[10], std::array<u64,1>{v_c10}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[11], newbatch[11], std::array<u64,1>{v_c11}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[12], newbatch[12], std::array<u64,1>{v_c12}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[13], newbatch[13], std::array<u64,1>{v_c13}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[14], newbatch[14], std::array<u64,1>{v_c14}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[15], newbatch[15], std::array<u64,1>{v_c15}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[16], newbatch[16], std::array<u64,1>{v_c16}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[17], newbatch[17], std::array<u64,1>{v_c17}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[18], newbatch[18], std::array<u64,1>{v_c18}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[19], newbatch[19], std::array<u64,1>{v_c19}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[20], newbatch[20], std::array<u64,1>{v_c20}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[21], newbatch[21], std::array<u64,1>{v_c21}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[22], newbatch[22], std::array<u64,1>{v_c22}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[23], newbatch[23], std::array<u64,1>{v_c23}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[24], newbatch[24], std::array<u64,1>{v_c24}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[25], newbatch[25], std::array<u64,1>{v_c25}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[26], newbatch[26], std::array<u64,1>{v_c26}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[27], newbatch[27], std::array<u64,1>{v_c27}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[28], newbatch[28], std::array<u64,1>{v_c28}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[29], newbatch[29], std::array<u64,1>{v_c29}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[30], newbatch[30], std::array<u64,1>{v_c30}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[31], newbatch[31], std::array<u64,1>{v_c31}, std::array<u16,2>{1, 0});
  
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
  
      if (_fires) db->bumpFires("deep_fact.slog:7", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask826(db,b), true);
  // (crule (pre (let __tconst48SJ108 const6b86b273ff34fce19d6b804e) (let __tconst5Uhl106 constd4735e3a265e16eee03f5971) (let __tconst9YpM103 const4e07408562bedb8b60ce05c1) (let __tconst3iHp101 const4b227777d4dd1fc61c6f884f) (let __tconst0Emh97 constef2d127de37b942baad06145) (let __tconst29xA95 conste7f6c011776e8db7cd330b54) (let __tconst9mjQ92 const7902699be42c8a8e46fbbb45) (let __tconst9Yxv90 const2c624232cdd221771294dfbb) (let __tconst7wWY85 const19581e27de7ced00ff1ce50b) (let __tconst01Wl83 const4a44dc15364204a80fe80e90) (let __tconst42lR80 const4fc82b26aecb47d2868c4efb) (let __tconst3KyY78 const6b51d431df5d7f141cbececc) (let __tconst6a9N74 const3fdba35f04dc8c462986c992) (let __tconst74Qx72 const8527a891e224136950ff32ca) (let __tconst2hOw69 conste629fa6598d732768f7c726b) (let __tconst7kHD67 constb17ef6d19c7a5b1ee83b907c) (let __tconst5zmq61 const4523540f1504cd17100c4835) (let __tconst31qC59 const4ec9599fc203d176a301536c) (let __tconst4Vop56 const9400f1b21cb527d7fa3d3eab) (let __tconst51zc54 constf5ca38f748a1d6eaf726b8a4) (let __tconst6Qm150 const6f4b6612125fb3a0daecd279) (let __tconst6bEj48 const785f3ec7eb32f30b90cd0fcf) (let __tconst7AKN45 const535fa30d7e25dd8a49f15367) (let __tconst9j2a43 constc2356069e9d1e79ca9243781) (let __tconst1Mto38 constb7a56873cd771f2c446d369b) (let __tconst8u8i36 const5f9c4ab08cac7457e9111a30) (let __tconst2Isx33 const670671cd97404156226e5079) (let __tconst8J6R31 const59e19706d51d39f66711c265) (let __tconst88cs27 const35135aaa6cc23891b40cb3f3) (let __tconst0Uuf25 const624b60c58c9d8bfb6ff1886c) (let __tconst6sf622 consteb1e33e8a81b697b75855af6) (let __tconst5Run20 conste29c9c180c6279b0b02abd6a)) (scan Nd __t6JrG30 __t0kIY29 __t7LF824) (body (exists Lf (1 0) 1 __tconst6sf622) (exists Lf (1 0) 1 __tconst0Uuf25) (exists Lf (1 0) 1 __tconst88cs27) (exists Lf (1 0) 1 __tconst8J6R31) (exists Lf (1 0) 1 __tconst2Isx33) (exists Lf (1 0) 1 __tconst8u8i36) (exists Lf (1 0) 1 __tconst1Mto38) (exists Lf (1 0) 1 __tconst9j2a43) (exists Lf (1 0) 1 __tconst7AKN45) (exists Lf (1 0) 1 __tconst6bEj48) (exists Lf (1 0) 1 __tconst6Qm150) (exists Lf (1 0) 1 __tconst51zc54) (exists Lf (1 0) 1 __tconst4Vop56) (exists Lf (1 0) 1 __tconst31qC59) (exists Lf (1 0) 1 __tconst5zmq61) (exists Lf (1 0) 1 __tconst7kHD67) (exists Lf (1 0) 1 __tconst2hOw69) (exists Lf (1 0) 1 __tconst74Qx72) (exists Lf (1 0) 1 __tconst6a9N74) (exists Lf (1 0) 1 __tconst3KyY78) (exists Lf (1 0) 1 __tconst42lR80) (exists Lf (1 0) 1 __tconst01Wl83) (exists Lf (1 0) 1 __tconst7wWY85) (exists Lf (1 0) 1 __tconst9Yxv90) (exists Lf (1 0) 1 __tconst9mjQ92) (exists Lf (1 0) 1 __tconst29xA95) (exists Lf (1 0) 1 __tconst0Emh97) (exists Lf (1 0) 1 __tconst3iHp101) (exists Lf (1 0) 1 __tconst9YpM103) (exists Lf (1 0) 1 __tconst5Uhl106) (exists Lf (1 0) 1 __tconst48SJ108) (join Lf (1 0) 1 __tconst5Run20 __t8mDO21) (join Nd (0 2 1) 2 __t7LF824 __t8mDO21 __t1M8o23) (join Lf (0 1) 2 __t1M8o23 __tconst6sf622) (join Lf (1 0) 1 __tconst0Uuf25 __t1NQv26) (join Nd (0 2 1) 2 __t0kIY29 __t1NQv26 __t7d0c28) (join Lf (0 1) 2 __t7d0c28 __tconst88cs27) (join Lf (1 0) 1 __tconst8J6R31 __t9vh832) (exists Nd (2 1 0) 1 __t9vh832) (join Lf (1 0) 1 __tconst2Isx33 __t5flt34) (join Nd (2 1 0) 2 __t9vh832 __t5flt34 __t3jHg35) (exists Nd (2 1 0) 1 __t3jHg35) (join Lf (1 0) 1 __tconst8u8i36 __t27Zr37) (exists Nd (2 1 0) 1 __t27Zr37) (join Lf (1 0) 1 __tconst1Mto38 __t3UFu39) (join Nd (2 1 0) 2 __t27Zr37 __t3UFu39 __t8qqV40) (join Nd (2 1 0) 2 __t3jHg35 __t8qqV40 __t2KtK41) (join Lf (1 0) 1 __tconst9j2a43 __t6IKq44) (exists Nd (2 1 0) 1 __t6IKq44) (join Lf (1 0) 1 __tconst7AKN45 __t6LIW46) (join Nd (2 1 0) 2 __t6IKq44 __t6LIW46 __t7C7d47) (exists Nd (2 1 0) 1 __t7C7d47) (join Lf (1 0) 1 __tconst6bEj48 __t9k7a49) (exists Nd (2 1 0) 1 __t9k7a49) (join Lf (1 0) 1 __tconst6Qm150 __t4MdC51) (join Nd (2 1 0) 2 __t9k7a49 __t4MdC51 __t8A9i52) (join Nd (2 1 0) 2 __t7C7d47 __t8A9i52 __t7DSY53) (join Lf (1 0) 1 __tconst51zc54 __t3Yon55) (exists Nd (2 1 0) 1 __t3Yon55) (join Lf (1 0) 1 __tconst4Vop56 __t5ik157) (join Nd (2 1 0) 2 __t3Yon55 __t5ik157 __t4hi358) (exists Nd (2 1 0) 1 __t4hi358) (join Lf (1 0) 1 __tconst31qC59 __t1nkJ60) (exists Nd (2 1 0) 1 __t1nkJ60) (join Lf (1 0) 1 __tconst5zmq61 __t4E3D62) (join Nd (2 1 0) 2 __t1nkJ60 __t4E3D62 __t8TXU63) (join Nd (2 1 0) 2 __t4hi358 __t8TXU63 __t6bZq64) (join Lf (1 0) 1 __tconst7kHD67 __t4J2N68) (exists Nd (2 1 0) 1 __t4J2N68) (join Lf (1 0) 1 __tconst2hOw69 __t4izo70) (join Nd (2 1 0) 2 __t4J2N68 __t4izo70 __t14Ff71) (exists Nd (2 1 0) 1 __t14Ff71) (join Lf (1 0) 1 __tconst74Qx72 __t319l73) (exists Nd (2 1 0) 1 __t319l73) (join Lf (1 0) 1 __tconst6a9N74 __t0amQ75) (join Nd (2 1 0) 2 __t319l73 __t0amQ75 __t4MUf76) (join Nd (2 1 0) 2 __t14Ff71 __t4MUf76 __t13Wj77) (join Lf (1 0) 1 __tconst3KyY78 __t13gt79) (exists Nd (2 1 0) 1 __t13gt79) (join Lf (1 0) 1 __tconst42lR80 __t3ESz81) (join Nd (2 1 0) 2 __t13gt79 __t3ESz81 __t3WL082) (exists Nd (2 1 0) 1 __t3WL082) (join Lf (1 0) 1 __tconst01Wl83 __t4Da384) (exists Nd (2 1 0) 1 __t4Da384) (join Lf (1 0) 1 __tconst7wWY85 __t91gs86) (join Nd (2 1 0) 2 __t4Da384 __t91gs86 __t02Bu87) (join Nd (2 1 0) 2 __t3WL082 __t02Bu87 __t60KJ88) (join Lf (1 0) 1 __tconst9Yxv90 __t7UaH91) (exists Nd (2 1 0) 1 __t7UaH91) (join Lf (1 0) 1 __tconst9mjQ92 __t6IMg93) (join Nd (2 1 0) 2 __t7UaH91 __t6IMg93 __t2T3i94) (exists Nd (2 1 0) 1 __t2T3i94) (join Lf (1 0) 1 __tconst29xA95 __t2oHE96) (exists Nd (2 1 0) 1 __t2oHE96) (join Lf (1 0) 1 __tconst0Emh97 __t7bue98) (join Nd (2 1 0) 2 __t2oHE96 __t7bue98 __t0HkS99) (join Nd (2 1 0) 2 __t2T3i94 __t0HkS99 __t7PLp100) (join Lf (1 0) 1 __tconst3iHp101 __t5yzC102) (exists Nd (2 1 0) 1 __t5yzC102) (join Lf (1 0) 1 __tconst9YpM103 __t7c21104) (join Nd (2 1 0) 2 __t5yzC102 __t7c21104 __t4bRV105) (exists Nd (2 1 0) 1 __t4bRV105) (join Lf (1 0) 1 __tconst5Uhl106 __t1IJA107) (exists Nd (2 1 0) 1 __t1IJA107) (join Lf (1 0) 1 __tconst48SJ108 __t0y5t109) (join Nd (2 1 0) 2 __t1IJA107 __t0y5t109 __t76VS110) (join Nd (2 1 0) 2 __t4bRV105 __t76VS110 __t3a3T111)) (head (mkstruct Nd (2 1 0) __t9dGZ112 __t7PLp100 __t3a3T111) (mkstruct Nd (2 1 0) __t4p4K89 __t13Wj77 __t60KJ88) (mkstruct Nd (2 1 0) __t4uRs65 __t7DSY53 __t6bZq64) (mkstruct Nd (2 1 0) __t17Jm42 __t6JrG30 __t2KtK41)) deep_fact.slog:7 #f)
  class ReadTask934 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[4];
    slog::Index** head_index[4];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** Lfindex827;  slog::Index** Lfindex828;  slog::Index** Lfindex829;  slog::Index** Lfindex830;  slog::Index** Lfindex831;  slog::Index** Lfindex832;  slog::Index** Lfindex833;  slog::Index** Lfindex834;  slog::Index** Lfindex835;  slog::Index** Lfindex836;  slog::Index** Lfindex837;  slog::Index** Lfindex838;  slog::Index** Lfindex839;  slog::Index** Lfindex840;  slog::Index** Lfindex841;  slog::Index** Lfindex842;  slog::Index** Lfindex843;  slog::Index** Lfindex844;  slog::Index** Lfindex845;  slog::Index** Lfindex846;  slog::Index** Lfindex847;  slog::Index** Lfindex848;  slog::Index** Lfindex849;  slog::Index** Lfindex850;  slog::Index** Lfindex851;  slog::Index** Lfindex852;  slog::Index** Lfindex853;  slog::Index** Lfindex854;  slog::Index** Lfindex855;  slog::Index** Lfindex856;  slog::Index** Lfindex857;  slog::Index** Lfindex858;  slog::Index** Ndindex859;  slog::Index** Lfindex860;  slog::Index** Lfindex861;  slog::Index** Ndindex862;  slog::Index** Lfindex863;  slog::Index** Lfindex864;  slog::Index** Ndindex865;  slog::Index** Lfindex866;  slog::Index** Ndindex867;  slog::Index** Ndindex868;  slog::Index** Lfindex869;  slog::Index** Ndindex870;  slog::Index** Lfindex871;  slog::Index** Ndindex872;  slog::Index** Ndindex873;  slog::Index** Lfindex874;  slog::Index** Ndindex875;  slog::Index** Lfindex876;  slog::Index** Ndindex877;  slog::Index** Ndindex878;  slog::Index** Lfindex879;  slog::Index** Ndindex880;  slog::Index** Lfindex881;  slog::Index** Ndindex882;  slog::Index** Ndindex883;  slog::Index** Lfindex884;  slog::Index** Ndindex885;  slog::Index** Lfindex886;  slog::Index** Ndindex887;  slog::Index** Ndindex888;  slog::Index** Lfindex889;  slog::Index** Ndindex890;  slog::Index** Lfindex891;  slog::Index** Ndindex892;  slog::Index** Ndindex893;  slog::Index** Lfindex894;  slog::Index** Ndindex895;  slog::Index** Lfindex896;  slog::Index** Ndindex897;  slog::Index** Ndindex898;  slog::Index** Lfindex899;  slog::Index** Ndindex900;  slog::Index** Lfindex901;  slog::Index** Ndindex902;  slog::Index** Ndindex903;  slog::Index** Lfindex904;  slog::Index** Ndindex905;  slog::Index** Lfindex906;  slog::Index** Ndindex907;  slog::Index** Ndindex908;  slog::Index** Lfindex909;  slog::Index** Ndindex910;  slog::Index** Lfindex911;  slog::Index** Ndindex912;  slog::Index** Ndindex913;  slog::Index** Lfindex914;  slog::Index** Ndindex915;  slog::Index** Lfindex916;  slog::Index** Ndindex917;  slog::Index** Ndindex918;  slog::Index** Lfindex919;  slog::Index** Ndindex920;  slog::Index** Lfindex921;  slog::Index** Ndindex922;  slog::Index** Ndindex923;  slog::Index** Lfindex924;  slog::Index** Ndindex925;  slog::Index** Lfindex926;  slog::Index** Ndindex927;  slog::Index** Ndindex928;  slog::Index** Lfindex929;  slog::Index** Ndindex930;  slog::Index** Lfindex931;  slog::Index** Ndindex932;  slog::Index** Ndindex933;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("Nd");
      head_rel[1] = db->getRelation("Nd");
      head_rel[2] = db->getRelation("Nd");
      head_rel[3] = db->getRelation("Nd");
      outer_rel = db->getRelation("Nd");
      std::vector<u16> ord935({1, 0});
      slog::Relation* readrel936 = db->getRelation("Lf");
      Lfindex827 = readrel936->getIndex(ord935, false);
      std::vector<u16> ord937({1, 0});
      slog::Relation* readrel938 = db->getRelation("Lf");
      Lfindex828 = readrel938->getIndex(ord937, false);
      std::vector<u16> ord939({1, 0});
      slog::Relation* readrel940 = db->getRelation("Lf");
      Lfindex829 = readrel940->getIndex(ord939, false);
      std::vector<u16> ord941({1, 0});
      slog::Relation* readrel942 = db->getRelation("Lf");
      Lfindex830 = readrel942->getIndex(ord941, false);
      std::vector<u16> ord943({1, 0});
      slog::Relation* readrel944 = db->getRelation("Lf");
      Lfindex831 = readrel944->getIndex(ord943, false);
      std::vector<u16> ord945({1, 0});
      slog::Relation* readrel946 = db->getRelation("Lf");
      Lfindex832 = readrel946->getIndex(ord945, false);
      std::vector<u16> ord947({1, 0});
      slog::Relation* readrel948 = db->getRelation("Lf");
      Lfindex833 = readrel948->getIndex(ord947, false);
      std::vector<u16> ord949({1, 0});
      slog::Relation* readrel950 = db->getRelation("Lf");
      Lfindex834 = readrel950->getIndex(ord949, false);
      std::vector<u16> ord951({1, 0});
      slog::Relation* readrel952 = db->getRelation("Lf");
      Lfindex835 = readrel952->getIndex(ord951, false);
      std::vector<u16> ord953({1, 0});
      slog::Relation* readrel954 = db->getRelation("Lf");
      Lfindex836 = readrel954->getIndex(ord953, false);
      std::vector<u16> ord955({1, 0});
      slog::Relation* readrel956 = db->getRelation("Lf");
      Lfindex837 = readrel956->getIndex(ord955, false);
      std::vector<u16> ord957({1, 0});
      slog::Relation* readrel958 = db->getRelation("Lf");
      Lfindex838 = readrel958->getIndex(ord957, false);
      std::vector<u16> ord959({1, 0});
      slog::Relation* readrel960 = db->getRelation("Lf");
      Lfindex839 = readrel960->getIndex(ord959, false);
      std::vector<u16> ord961({1, 0});
      slog::Relation* readrel962 = db->getRelation("Lf");
      Lfindex840 = readrel962->getIndex(ord961, false);
      std::vector<u16> ord963({1, 0});
      slog::Relation* readrel964 = db->getRelation("Lf");
      Lfindex841 = readrel964->getIndex(ord963, false);
      std::vector<u16> ord965({1, 0});
      slog::Relation* readrel966 = db->getRelation("Lf");
      Lfindex842 = readrel966->getIndex(ord965, false);
      std::vector<u16> ord967({1, 0});
      slog::Relation* readrel968 = db->getRelation("Lf");
      Lfindex843 = readrel968->getIndex(ord967, false);
      std::vector<u16> ord969({1, 0});
      slog::Relation* readrel970 = db->getRelation("Lf");
      Lfindex844 = readrel970->getIndex(ord969, false);
      std::vector<u16> ord971({1, 0});
      slog::Relation* readrel972 = db->getRelation("Lf");
      Lfindex845 = readrel972->getIndex(ord971, false);
      std::vector<u16> ord973({1, 0});
      slog::Relation* readrel974 = db->getRelation("Lf");
      Lfindex846 = readrel974->getIndex(ord973, false);
      std::vector<u16> ord975({1, 0});
      slog::Relation* readrel976 = db->getRelation("Lf");
      Lfindex847 = readrel976->getIndex(ord975, false);
      std::vector<u16> ord977({1, 0});
      slog::Relation* readrel978 = db->getRelation("Lf");
      Lfindex848 = readrel978->getIndex(ord977, false);
      std::vector<u16> ord979({1, 0});
      slog::Relation* readrel980 = db->getRelation("Lf");
      Lfindex849 = readrel980->getIndex(ord979, false);
      std::vector<u16> ord981({1, 0});
      slog::Relation* readrel982 = db->getRelation("Lf");
      Lfindex850 = readrel982->getIndex(ord981, false);
      std::vector<u16> ord983({1, 0});
      slog::Relation* readrel984 = db->getRelation("Lf");
      Lfindex851 = readrel984->getIndex(ord983, false);
      std::vector<u16> ord985({1, 0});
      slog::Relation* readrel986 = db->getRelation("Lf");
      Lfindex852 = readrel986->getIndex(ord985, false);
      std::vector<u16> ord987({1, 0});
      slog::Relation* readrel988 = db->getRelation("Lf");
      Lfindex853 = readrel988->getIndex(ord987, false);
      std::vector<u16> ord989({1, 0});
      slog::Relation* readrel990 = db->getRelation("Lf");
      Lfindex854 = readrel990->getIndex(ord989, false);
      std::vector<u16> ord991({1, 0});
      slog::Relation* readrel992 = db->getRelation("Lf");
      Lfindex855 = readrel992->getIndex(ord991, false);
      std::vector<u16> ord993({1, 0});
      slog::Relation* readrel994 = db->getRelation("Lf");
      Lfindex856 = readrel994->getIndex(ord993, false);
      std::vector<u16> ord995({1, 0});
      slog::Relation* readrel996 = db->getRelation("Lf");
      Lfindex857 = readrel996->getIndex(ord995, false);
      std::vector<u16> ord997({1, 0});
      slog::Relation* readrel998 = db->getRelation("Lf");
      Lfindex858 = readrel998->getIndex(ord997, false);
      std::vector<u16> ord999({0, 2, 1});
      slog::Relation* readrel1000 = db->getRelation("Nd");
      Ndindex859 = readrel1000->getIndex(ord999, false);
      std::vector<u16> ord1001({0, 1});
      slog::Relation* readrel1002 = db->getRelation("Lf");
      Lfindex860 = readrel1002->getIndex(ord1001, false);
      std::vector<u16> ord1003({1, 0});
      slog::Relation* readrel1004 = db->getRelation("Lf");
      Lfindex861 = readrel1004->getIndex(ord1003, false);
      std::vector<u16> ord1005({0, 2, 1});
      slog::Relation* readrel1006 = db->getRelation("Nd");
      Ndindex862 = readrel1006->getIndex(ord1005, false);
      std::vector<u16> ord1007({0, 1});
      slog::Relation* readrel1008 = db->getRelation("Lf");
      Lfindex863 = readrel1008->getIndex(ord1007, false);
      std::vector<u16> ord1009({1, 0});
      slog::Relation* readrel1010 = db->getRelation("Lf");
      Lfindex864 = readrel1010->getIndex(ord1009, false);
      std::vector<u16> ord1011({2, 1, 0});
      slog::Relation* readrel1012 = db->getRelation("Nd");
      Ndindex865 = readrel1012->getIndex(ord1011, false);
      std::vector<u16> ord1013({1, 0});
      slog::Relation* readrel1014 = db->getRelation("Lf");
      Lfindex866 = readrel1014->getIndex(ord1013, false);
      std::vector<u16> ord1015({2, 1, 0});
      slog::Relation* readrel1016 = db->getRelation("Nd");
      Ndindex867 = readrel1016->getIndex(ord1015, false);
      std::vector<u16> ord1017({2, 1, 0});
      slog::Relation* readrel1018 = db->getRelation("Nd");
      Ndindex868 = readrel1018->getIndex(ord1017, false);
      std::vector<u16> ord1019({1, 0});
      slog::Relation* readrel1020 = db->getRelation("Lf");
      Lfindex869 = readrel1020->getIndex(ord1019, false);
      std::vector<u16> ord1021({2, 1, 0});
      slog::Relation* readrel1022 = db->getRelation("Nd");
      Ndindex870 = readrel1022->getIndex(ord1021, false);
      std::vector<u16> ord1023({1, 0});
      slog::Relation* readrel1024 = db->getRelation("Lf");
      Lfindex871 = readrel1024->getIndex(ord1023, false);
      std::vector<u16> ord1025({2, 1, 0});
      slog::Relation* readrel1026 = db->getRelation("Nd");
      Ndindex872 = readrel1026->getIndex(ord1025, false);
      std::vector<u16> ord1027({2, 1, 0});
      slog::Relation* readrel1028 = db->getRelation("Nd");
      Ndindex873 = readrel1028->getIndex(ord1027, false);
      std::vector<u16> ord1029({1, 0});
      slog::Relation* readrel1030 = db->getRelation("Lf");
      Lfindex874 = readrel1030->getIndex(ord1029, false);
      std::vector<u16> ord1031({2, 1, 0});
      slog::Relation* readrel1032 = db->getRelation("Nd");
      Ndindex875 = readrel1032->getIndex(ord1031, false);
      std::vector<u16> ord1033({1, 0});
      slog::Relation* readrel1034 = db->getRelation("Lf");
      Lfindex876 = readrel1034->getIndex(ord1033, false);
      std::vector<u16> ord1035({2, 1, 0});
      slog::Relation* readrel1036 = db->getRelation("Nd");
      Ndindex877 = readrel1036->getIndex(ord1035, false);
      std::vector<u16> ord1037({2, 1, 0});
      slog::Relation* readrel1038 = db->getRelation("Nd");
      Ndindex878 = readrel1038->getIndex(ord1037, false);
      std::vector<u16> ord1039({1, 0});
      slog::Relation* readrel1040 = db->getRelation("Lf");
      Lfindex879 = readrel1040->getIndex(ord1039, false);
      std::vector<u16> ord1041({2, 1, 0});
      slog::Relation* readrel1042 = db->getRelation("Nd");
      Ndindex880 = readrel1042->getIndex(ord1041, false);
      std::vector<u16> ord1043({1, 0});
      slog::Relation* readrel1044 = db->getRelation("Lf");
      Lfindex881 = readrel1044->getIndex(ord1043, false);
      std::vector<u16> ord1045({2, 1, 0});
      slog::Relation* readrel1046 = db->getRelation("Nd");
      Ndindex882 = readrel1046->getIndex(ord1045, false);
      std::vector<u16> ord1047({2, 1, 0});
      slog::Relation* readrel1048 = db->getRelation("Nd");
      Ndindex883 = readrel1048->getIndex(ord1047, false);
      std::vector<u16> ord1049({1, 0});
      slog::Relation* readrel1050 = db->getRelation("Lf");
      Lfindex884 = readrel1050->getIndex(ord1049, false);
      std::vector<u16> ord1051({2, 1, 0});
      slog::Relation* readrel1052 = db->getRelation("Nd");
      Ndindex885 = readrel1052->getIndex(ord1051, false);
      std::vector<u16> ord1053({1, 0});
      slog::Relation* readrel1054 = db->getRelation("Lf");
      Lfindex886 = readrel1054->getIndex(ord1053, false);
      std::vector<u16> ord1055({2, 1, 0});
      slog::Relation* readrel1056 = db->getRelation("Nd");
      Ndindex887 = readrel1056->getIndex(ord1055, false);
      std::vector<u16> ord1057({2, 1, 0});
      slog::Relation* readrel1058 = db->getRelation("Nd");
      Ndindex888 = readrel1058->getIndex(ord1057, false);
      std::vector<u16> ord1059({1, 0});
      slog::Relation* readrel1060 = db->getRelation("Lf");
      Lfindex889 = readrel1060->getIndex(ord1059, false);
      std::vector<u16> ord1061({2, 1, 0});
      slog::Relation* readrel1062 = db->getRelation("Nd");
      Ndindex890 = readrel1062->getIndex(ord1061, false);
      std::vector<u16> ord1063({1, 0});
      slog::Relation* readrel1064 = db->getRelation("Lf");
      Lfindex891 = readrel1064->getIndex(ord1063, false);
      std::vector<u16> ord1065({2, 1, 0});
      slog::Relation* readrel1066 = db->getRelation("Nd");
      Ndindex892 = readrel1066->getIndex(ord1065, false);
      std::vector<u16> ord1067({2, 1, 0});
      slog::Relation* readrel1068 = db->getRelation("Nd");
      Ndindex893 = readrel1068->getIndex(ord1067, false);
      std::vector<u16> ord1069({1, 0});
      slog::Relation* readrel1070 = db->getRelation("Lf");
      Lfindex894 = readrel1070->getIndex(ord1069, false);
      std::vector<u16> ord1071({2, 1, 0});
      slog::Relation* readrel1072 = db->getRelation("Nd");
      Ndindex895 = readrel1072->getIndex(ord1071, false);
      std::vector<u16> ord1073({1, 0});
      slog::Relation* readrel1074 = db->getRelation("Lf");
      Lfindex896 = readrel1074->getIndex(ord1073, false);
      std::vector<u16> ord1075({2, 1, 0});
      slog::Relation* readrel1076 = db->getRelation("Nd");
      Ndindex897 = readrel1076->getIndex(ord1075, false);
      std::vector<u16> ord1077({2, 1, 0});
      slog::Relation* readrel1078 = db->getRelation("Nd");
      Ndindex898 = readrel1078->getIndex(ord1077, false);
      std::vector<u16> ord1079({1, 0});
      slog::Relation* readrel1080 = db->getRelation("Lf");
      Lfindex899 = readrel1080->getIndex(ord1079, false);
      std::vector<u16> ord1081({2, 1, 0});
      slog::Relation* readrel1082 = db->getRelation("Nd");
      Ndindex900 = readrel1082->getIndex(ord1081, false);
      std::vector<u16> ord1083({1, 0});
      slog::Relation* readrel1084 = db->getRelation("Lf");
      Lfindex901 = readrel1084->getIndex(ord1083, false);
      std::vector<u16> ord1085({2, 1, 0});
      slog::Relation* readrel1086 = db->getRelation("Nd");
      Ndindex902 = readrel1086->getIndex(ord1085, false);
      std::vector<u16> ord1087({2, 1, 0});
      slog::Relation* readrel1088 = db->getRelation("Nd");
      Ndindex903 = readrel1088->getIndex(ord1087, false);
      std::vector<u16> ord1089({1, 0});
      slog::Relation* readrel1090 = db->getRelation("Lf");
      Lfindex904 = readrel1090->getIndex(ord1089, false);
      std::vector<u16> ord1091({2, 1, 0});
      slog::Relation* readrel1092 = db->getRelation("Nd");
      Ndindex905 = readrel1092->getIndex(ord1091, false);
      std::vector<u16> ord1093({1, 0});
      slog::Relation* readrel1094 = db->getRelation("Lf");
      Lfindex906 = readrel1094->getIndex(ord1093, false);
      std::vector<u16> ord1095({2, 1, 0});
      slog::Relation* readrel1096 = db->getRelation("Nd");
      Ndindex907 = readrel1096->getIndex(ord1095, false);
      std::vector<u16> ord1097({2, 1, 0});
      slog::Relation* readrel1098 = db->getRelation("Nd");
      Ndindex908 = readrel1098->getIndex(ord1097, false);
      std::vector<u16> ord1099({1, 0});
      slog::Relation* readrel1100 = db->getRelation("Lf");
      Lfindex909 = readrel1100->getIndex(ord1099, false);
      std::vector<u16> ord1101({2, 1, 0});
      slog::Relation* readrel1102 = db->getRelation("Nd");
      Ndindex910 = readrel1102->getIndex(ord1101, false);
      std::vector<u16> ord1103({1, 0});
      slog::Relation* readrel1104 = db->getRelation("Lf");
      Lfindex911 = readrel1104->getIndex(ord1103, false);
      std::vector<u16> ord1105({2, 1, 0});
      slog::Relation* readrel1106 = db->getRelation("Nd");
      Ndindex912 = readrel1106->getIndex(ord1105, false);
      std::vector<u16> ord1107({2, 1, 0});
      slog::Relation* readrel1108 = db->getRelation("Nd");
      Ndindex913 = readrel1108->getIndex(ord1107, false);
      std::vector<u16> ord1109({1, 0});
      slog::Relation* readrel1110 = db->getRelation("Lf");
      Lfindex914 = readrel1110->getIndex(ord1109, false);
      std::vector<u16> ord1111({2, 1, 0});
      slog::Relation* readrel1112 = db->getRelation("Nd");
      Ndindex915 = readrel1112->getIndex(ord1111, false);
      std::vector<u16> ord1113({1, 0});
      slog::Relation* readrel1114 = db->getRelation("Lf");
      Lfindex916 = readrel1114->getIndex(ord1113, false);
      std::vector<u16> ord1115({2, 1, 0});
      slog::Relation* readrel1116 = db->getRelation("Nd");
      Ndindex917 = readrel1116->getIndex(ord1115, false);
      std::vector<u16> ord1117({2, 1, 0});
      slog::Relation* readrel1118 = db->getRelation("Nd");
      Ndindex918 = readrel1118->getIndex(ord1117, false);
      std::vector<u16> ord1119({1, 0});
      slog::Relation* readrel1120 = db->getRelation("Lf");
      Lfindex919 = readrel1120->getIndex(ord1119, false);
      std::vector<u16> ord1121({2, 1, 0});
      slog::Relation* readrel1122 = db->getRelation("Nd");
      Ndindex920 = readrel1122->getIndex(ord1121, false);
      std::vector<u16> ord1123({1, 0});
      slog::Relation* readrel1124 = db->getRelation("Lf");
      Lfindex921 = readrel1124->getIndex(ord1123, false);
      std::vector<u16> ord1125({2, 1, 0});
      slog::Relation* readrel1126 = db->getRelation("Nd");
      Ndindex922 = readrel1126->getIndex(ord1125, false);
      std::vector<u16> ord1127({2, 1, 0});
      slog::Relation* readrel1128 = db->getRelation("Nd");
      Ndindex923 = readrel1128->getIndex(ord1127, false);
      std::vector<u16> ord1129({1, 0});
      slog::Relation* readrel1130 = db->getRelation("Lf");
      Lfindex924 = readrel1130->getIndex(ord1129, false);
      std::vector<u16> ord1131({2, 1, 0});
      slog::Relation* readrel1132 = db->getRelation("Nd");
      Ndindex925 = readrel1132->getIndex(ord1131, false);
      std::vector<u16> ord1133({1, 0});
      slog::Relation* readrel1134 = db->getRelation("Lf");
      Lfindex926 = readrel1134->getIndex(ord1133, false);
      std::vector<u16> ord1135({2, 1, 0});
      slog::Relation* readrel1136 = db->getRelation("Nd");
      Ndindex927 = readrel1136->getIndex(ord1135, false);
      std::vector<u16> ord1137({2, 1, 0});
      slog::Relation* readrel1138 = db->getRelation("Nd");
      Ndindex928 = readrel1138->getIndex(ord1137, false);
      std::vector<u16> ord1139({1, 0});
      slog::Relation* readrel1140 = db->getRelation("Lf");
      Lfindex929 = readrel1140->getIndex(ord1139, false);
      std::vector<u16> ord1141({2, 1, 0});
      slog::Relation* readrel1142 = db->getRelation("Nd");
      Ndindex930 = readrel1142->getIndex(ord1141, false);
      std::vector<u16> ord1143({1, 0});
      slog::Relation* readrel1144 = db->getRelation("Lf");
      Lfindex931 = readrel1144->getIndex(ord1143, false);
      std::vector<u16> ord1145({2, 1, 0});
      slog::Relation* readrel1146 = db->getRelation("Nd");
      Ndindex932 = readrel1146->getIndex(ord1145, false);
      std::vector<u16> ord1147({2, 1, 0});
      slog::Relation* readrel1148 = db->getRelation("Nd");
      Ndindex933 = readrel1148->getIndex(ord1147, false);
  
    }
    ReadTask934(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[4];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c41 = _t[0];
        u64 v_c40 = _t[1];
        u64 v_c37 = _t[2];
        if (!slog::exists_probe<2,1>(Lfindex827, std::array<u64,2>{v_c30, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex828, std::array<u64,2>{v_c29, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex829, std::array<u64,2>{v_c28, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex830, std::array<u64,2>{v_c27, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex831, std::array<u64,2>{v_c26, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex832, std::array<u64,2>{v_c25, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex833, std::array<u64,2>{v_c24, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex834, std::array<u64,2>{v_c23, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex835, std::array<u64,2>{v_c22, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex836, std::array<u64,2>{v_c21, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex837, std::array<u64,2>{v_c20, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex838, std::array<u64,2>{v_c19, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex839, std::array<u64,2>{v_c18, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex840, std::array<u64,2>{v_c17, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex841, std::array<u64,2>{v_c16, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex842, std::array<u64,2>{v_c15, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex843, std::array<u64,2>{v_c14, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex844, std::array<u64,2>{v_c13, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex845, std::array<u64,2>{v_c12, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex846, std::array<u64,2>{v_c11, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex847, std::array<u64,2>{v_c10, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex848, std::array<u64,2>{v_c9, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex849, std::array<u64,2>{v_c8, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex850, std::array<u64,2>{v_c7, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex851, std::array<u64,2>{v_c6, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex852, std::array<u64,2>{v_c5, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex853, std::array<u64,2>{v_c4, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex854, std::array<u64,2>{v_c3, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex855, std::array<u64,2>{v_c2, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex856, std::array<u64,2>{v_c1, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex857, std::array<u64,2>{v_c0, 0})) return;
        slog::join_probe<2,1>(Lfindex858, std::array<u64,2>{v_c31, 0}, [&](const std::array<u64,2>& m1149) {
          u64 v_c35 = m1149[1];
          slog::join_probe<3,2>(Ndindex859, std::array<u64,3>{v_c37, v_c35, 0}, [&](const std::array<u64,3>& m1150) {
            u64 v_c36 = m1150[2];
            slog::join_probe<2,2>(Lfindex860, std::array<u64,2>{v_c36, v_c30}, [&](const std::array<u64,2>& m1151) {
              slog::join_probe<2,1>(Lfindex861, std::array<u64,2>{v_c29, 0}, [&](const std::array<u64,2>& m1152) {
                u64 v_c38 = m1152[1];
                slog::join_probe<3,2>(Ndindex862, std::array<u64,3>{v_c40, v_c38, 0}, [&](const std::array<u64,3>& m1153) {
                  u64 v_c39 = m1153[2];
                  slog::join_probe<2,2>(Lfindex863, std::array<u64,2>{v_c39, v_c28}, [&](const std::array<u64,2>& m1154) {
                    slog::join_probe<2,1>(Lfindex864, std::array<u64,2>{v_c27, 0}, [&](const std::array<u64,2>& m1155) {
                      u64 v_c43 = m1155[1];
                      if (!slog::exists_probe<3,1>(Ndindex865, std::array<u64,3>{v_c43, 0, 0})) return;
                      slog::join_probe<2,1>(Lfindex866, std::array<u64,2>{v_c26, 0}, [&](const std::array<u64,2>& m1156) {
                        u64 v_c44 = m1156[1];
                        slog::join_probe<3,2>(Ndindex867, std::array<u64,3>{v_c43, v_c44, 0}, [&](const std::array<u64,3>& m1157) {
                          u64 v_c45 = m1157[2];
                          if (!slog::exists_probe<3,1>(Ndindex868, std::array<u64,3>{v_c45, 0, 0})) return;
                          slog::join_probe<2,1>(Lfindex869, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m1158) {
                            u64 v_c47 = m1158[1];
                            if (!slog::exists_probe<3,1>(Ndindex870, std::array<u64,3>{v_c47, 0, 0})) return;
                            slog::join_probe<2,1>(Lfindex871, std::array<u64,2>{v_c24, 0}, [&](const std::array<u64,2>& m1159) {
                              u64 v_c48 = m1159[1];
                              slog::join_probe<3,2>(Ndindex872, std::array<u64,3>{v_c47, v_c48, 0}, [&](const std::array<u64,3>& m1160) {
                                u64 v_c46 = m1160[2];
                                slog::join_probe<3,2>(Ndindex873, std::array<u64,3>{v_c45, v_c46, 0}, [&](const std::array<u64,3>& m1161) {
                                  u64 v_c42 = m1161[2];
                                  slog::join_probe<2,1>(Lfindex874, std::array<u64,2>{v_c23, 0}, [&](const std::array<u64,2>& m1162) {
                                    u64 v_c49 = m1162[1];
                                    if (!slog::exists_probe<3,1>(Ndindex875, std::array<u64,3>{v_c49, 0, 0})) return;
                                    slog::join_probe<2,1>(Lfindex876, std::array<u64,2>{v_c22, 0}, [&](const std::array<u64,2>& m1163) {
                                      u64 v_c50 = m1163[1];
                                      slog::join_probe<3,2>(Ndindex877, std::array<u64,3>{v_c49, v_c50, 0}, [&](const std::array<u64,3>& m1164) {
                                        u64 v_c51 = m1164[2];
                                        if (!slog::exists_probe<3,1>(Ndindex878, std::array<u64,3>{v_c51, 0, 0})) return;
                                        slog::join_probe<2,1>(Lfindex879, std::array<u64,2>{v_c21, 0}, [&](const std::array<u64,2>& m1165) {
                                          u64 v_c52 = m1165[1];
                                          if (!slog::exists_probe<3,1>(Ndindex880, std::array<u64,3>{v_c52, 0, 0})) return;
                                          slog::join_probe<2,1>(Lfindex881, std::array<u64,2>{v_c20, 0}, [&](const std::array<u64,2>& m1166) {
                                            u64 v_c53 = m1166[1];
                                            slog::join_probe<3,2>(Ndindex882, std::array<u64,3>{v_c52, v_c53, 0}, [&](const std::array<u64,3>& m1167) {
                                              u64 v_c54 = m1167[2];
                                              slog::join_probe<3,2>(Ndindex883, std::array<u64,3>{v_c51, v_c54, 0}, [&](const std::array<u64,3>& m1168) {
                                                u64 v_c55 = m1168[2];
                                                slog::join_probe<2,1>(Lfindex884, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m1169) {
                                                  u64 v_c57 = m1169[1];
                                                  if (!slog::exists_probe<3,1>(Ndindex885, std::array<u64,3>{v_c57, 0, 0})) return;
                                                  slog::join_probe<2,1>(Lfindex886, std::array<u64,2>{v_c18, 0}, [&](const std::array<u64,2>& m1170) {
                                                    u64 v_c58 = m1170[1];
                                                    slog::join_probe<3,2>(Ndindex887, std::array<u64,3>{v_c57, v_c58, 0}, [&](const std::array<u64,3>& m1171) {
                                                      u64 v_c59 = m1171[2];
                                                      if (!slog::exists_probe<3,1>(Ndindex888, std::array<u64,3>{v_c59, 0, 0})) return;
                                                      slog::join_probe<2,1>(Lfindex889, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m1172) {
                                                        u64 v_c61 = m1172[1];
                                                        if (!slog::exists_probe<3,1>(Ndindex890, std::array<u64,3>{v_c61, 0, 0})) return;
                                                        slog::join_probe<2,1>(Lfindex891, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m1173) {
                                                          u64 v_c62 = m1173[1];
                                                          slog::join_probe<3,2>(Ndindex892, std::array<u64,3>{v_c61, v_c62, 0}, [&](const std::array<u64,3>& m1174) {
                                                            u64 v_c60 = m1174[2];
                                                            slog::join_probe<3,2>(Ndindex893, std::array<u64,3>{v_c59, v_c60, 0}, [&](const std::array<u64,3>& m1175) {
                                                              u64 v_c56 = m1175[2];
                                                              slog::join_probe<2,1>(Lfindex894, std::array<u64,2>{v_c15, 0}, [&](const std::array<u64,2>& m1176) {
                                                                u64 v_c63 = m1176[1];
                                                                if (!slog::exists_probe<3,1>(Ndindex895, std::array<u64,3>{v_c63, 0, 0})) return;
                                                                slog::join_probe<2,1>(Lfindex896, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m1177) {
                                                                  u64 v_c64 = m1177[1];
                                                                  slog::join_probe<3,2>(Ndindex897, std::array<u64,3>{v_c63, v_c64, 0}, [&](const std::array<u64,3>& m1178) {
                                                                    u64 v_c65 = m1178[2];
                                                                    if (!slog::exists_probe<3,1>(Ndindex898, std::array<u64,3>{v_c65, 0, 0})) return;
                                                                    slog::join_probe<2,1>(Lfindex899, std::array<u64,2>{v_c13, 0}, [&](const std::array<u64,2>& m1179) {
                                                                      u64 v_c66 = m1179[1];
                                                                      if (!slog::exists_probe<3,1>(Ndindex900, std::array<u64,3>{v_c66, 0, 0})) return;
                                                                      slog::join_probe<2,1>(Lfindex901, std::array<u64,2>{v_c12, 0}, [&](const std::array<u64,2>& m1180) {
                                                                        u64 v_c67 = m1180[1];
                                                                        slog::join_probe<3,2>(Ndindex902, std::array<u64,3>{v_c66, v_c67, 0}, [&](const std::array<u64,3>& m1181) {
                                                                          u64 v_c68 = m1181[2];
                                                                          slog::join_probe<3,2>(Ndindex903, std::array<u64,3>{v_c65, v_c68, 0}, [&](const std::array<u64,3>& m1182) {
                                                                            u64 v_c69 = m1182[2];
                                                                            slog::join_probe<2,1>(Lfindex904, std::array<u64,2>{v_c11, 0}, [&](const std::array<u64,2>& m1183) {
                                                                              u64 v_c70 = m1183[1];
                                                                              if (!slog::exists_probe<3,1>(Ndindex905, std::array<u64,3>{v_c70, 0, 0})) return;
                                                                              slog::join_probe<2,1>(Lfindex906, std::array<u64,2>{v_c10, 0}, [&](const std::array<u64,2>& m1184) {
                                                                                u64 v_c71 = m1184[1];
                                                                                slog::join_probe<3,2>(Ndindex907, std::array<u64,3>{v_c70, v_c71, 0}, [&](const std::array<u64,3>& m1185) {
                                                                                  u64 v_c72 = m1185[2];
                                                                                  if (!slog::exists_probe<3,1>(Ndindex908, std::array<u64,3>{v_c72, 0, 0})) return;
                                                                                  slog::join_probe<2,1>(Lfindex909, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m1186) {
                                                                                    u64 v_c73 = m1186[1];
                                                                                    if (!slog::exists_probe<3,1>(Ndindex910, std::array<u64,3>{v_c73, 0, 0})) return;
                                                                                    slog::join_probe<2,1>(Lfindex911, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m1187) {
                                                                                      u64 v_c74 = m1187[1];
                                                                                      slog::join_probe<3,2>(Ndindex912, std::array<u64,3>{v_c73, v_c74, 0}, [&](const std::array<u64,3>& m1188) {
                                                                                        u64 v_c75 = m1188[2];
                                                                                        slog::join_probe<3,2>(Ndindex913, std::array<u64,3>{v_c72, v_c75, 0}, [&](const std::array<u64,3>& m1189) {
                                                                                          u64 v_c76 = m1189[2];
                                                                                          slog::join_probe<2,1>(Lfindex914, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m1190) {
                                                                                            u64 v_c78 = m1190[1];
                                                                                            if (!slog::exists_probe<3,1>(Ndindex915, std::array<u64,3>{v_c78, 0, 0})) return;
                                                                                            slog::join_probe<2,1>(Lfindex916, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m1191) {
                                                                                              u64 v_c79 = m1191[1];
                                                                                              slog::join_probe<3,2>(Ndindex917, std::array<u64,3>{v_c78, v_c79, 0}, [&](const std::array<u64,3>& m1192) {
                                                                                                u64 v_c80 = m1192[2];
                                                                                                if (!slog::exists_probe<3,1>(Ndindex918, std::array<u64,3>{v_c80, 0, 0})) return;
                                                                                                slog::join_probe<2,1>(Lfindex919, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m1193) {
                                                                                                  u64 v_c81 = m1193[1];
                                                                                                  if (!slog::exists_probe<3,1>(Ndindex920, std::array<u64,3>{v_c81, 0, 0})) return;
                                                                                                  slog::join_probe<2,1>(Lfindex921, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m1194) {
                                                                                                    u64 v_c82 = m1194[1];
                                                                                                    slog::join_probe<3,2>(Ndindex922, std::array<u64,3>{v_c81, v_c82, 0}, [&](const std::array<u64,3>& m1195) {
                                                                                                      u64 v_c83 = m1195[2];
                                                                                                      slog::join_probe<3,2>(Ndindex923, std::array<u64,3>{v_c80, v_c83, 0}, [&](const std::array<u64,3>& m1196) {
                                                                                                        u64 v_c84 = m1196[2];
                                                                                                        slog::join_probe<2,1>(Lfindex924, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m1197) {
                                                                                                          u64 v_c85 = m1197[1];
                                                                                                          if (!slog::exists_probe<3,1>(Ndindex925, std::array<u64,3>{v_c85, 0, 0})) return;
                                                                                                          slog::join_probe<2,1>(Lfindex926, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m1198) {
                                                                                                            u64 v_c86 = m1198[1];
                                                                                                            slog::join_probe<3,2>(Ndindex927, std::array<u64,3>{v_c85, v_c86, 0}, [&](const std::array<u64,3>& m1199) {
                                                                                                              u64 v_c87 = m1199[2];
                                                                                                              if (!slog::exists_probe<3,1>(Ndindex928, std::array<u64,3>{v_c87, 0, 0})) return;
                                                                                                              slog::join_probe<2,1>(Lfindex929, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m1200) {
                                                                                                                u64 v_c88 = m1200[1];
                                                                                                                if (!slog::exists_probe<3,1>(Ndindex930, std::array<u64,3>{v_c88, 0, 0})) return;
                                                                                                                slog::join_probe<2,1>(Lfindex931, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m1201) {
                                                                                                                  u64 v_c89 = m1201[1];
                                                                                                                  slog::join_probe<3,2>(Ndindex932, std::array<u64,3>{v_c88, v_c89, 0}, [&](const std::array<u64,3>& m1202) {
                                                                                                                    u64 v_c90 = m1202[2];
                                                                                                                    slog::join_probe<3,2>(Ndindex933, std::array<u64,3>{v_c87, v_c90, 0}, [&](const std::array<u64,3>& m1203) {
                                                                                                                      u64 v_c91 = m1203[2];
                                                                                                                      ++_fires;
                                                                                                                      slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c84, v_c91}, std::array<u16,3>{2, 1, 0});
                                                                                                                      slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c69, v_c76}, std::array<u16,3>{2, 1, 0});
                                                                                                                      slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c55, v_c56}, std::array<u16,3>{2, 1, 0});
                                                                                                                      slog::emit_struct<3>(head_rel[3], newbatch[3], std::array<u64,2>{v_c41, v_c42}, std::array<u16,3>{2, 1, 0});
                                                                                                                    });
                                                                                                                  });
                                                                                                                });
                                                                                                              });
                                                                                                            });
                                                                                                          });
                                                                                                        });
                                                                                                      });
                                                                                                    });
                                                                                                  });
                                                                                                });
                                                                                              });
                                                                                            });
                                                                                          });
                                                                                        });
                                                                                      });
                                                                                    });
                                                                                  });
                                                                                });
                                                                              });
                                                                            });
                                                                          });
                                                                        });
                                                                      });
                                                                    });
                                                                  });
                                                                });
                                                              });
                                                            });
                                                          });
                                                        });
                                                      });
                                                    });
                                                  });
                                                });
                                              });
                                            });
                                          });
                                        });
                                      });
                                    });
                                  });
                                });
                              });
                            });
                          });
                        });
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
  
      if (_fires) db->bumpFires("deep_fact.slog:7", "delta:Nd", _fires);
  
      if (!_done)
      {
        ReadTask934* _cont = new ReadTask934(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask934(db,b), false);
  // (crule (pre (let __tconst48SJ108 const6b86b273ff34fce19d6b804e) (let __tconst5Uhl106 constd4735e3a265e16eee03f5971) (let __tconst9YpM103 const4e07408562bedb8b60ce05c1) (let __tconst3iHp101 const4b227777d4dd1fc61c6f884f) (let __tconst0Emh97 constef2d127de37b942baad06145) (let __tconst29xA95 conste7f6c011776e8db7cd330b54) (let __tconst9mjQ92 const7902699be42c8a8e46fbbb45) (let __tconst9Yxv90 const2c624232cdd221771294dfbb) (let __tconst7wWY85 const19581e27de7ced00ff1ce50b) (let __tconst01Wl83 const4a44dc15364204a80fe80e90) (let __tconst42lR80 const4fc82b26aecb47d2868c4efb) (let __tconst3KyY78 const6b51d431df5d7f141cbececc) (let __tconst6a9N74 const3fdba35f04dc8c462986c992) (let __tconst74Qx72 const8527a891e224136950ff32ca) (let __tconst2hOw69 conste629fa6598d732768f7c726b) (let __tconst7kHD67 constb17ef6d19c7a5b1ee83b907c) (let __tconst5zmq61 const4523540f1504cd17100c4835) (let __tconst31qC59 const4ec9599fc203d176a301536c) (let __tconst4Vop56 const9400f1b21cb527d7fa3d3eab) (let __tconst51zc54 constf5ca38f748a1d6eaf726b8a4) (let __tconst6Qm150 const6f4b6612125fb3a0daecd279) (let __tconst6bEj48 const785f3ec7eb32f30b90cd0fcf) (let __tconst7AKN45 const535fa30d7e25dd8a49f15367) (let __tconst9j2a43 constc2356069e9d1e79ca9243781) (let __tconst1Mto38 constb7a56873cd771f2c446d369b) (let __tconst8u8i36 const5f9c4ab08cac7457e9111a30) (let __tconst2Isx33 const670671cd97404156226e5079) (let __tconst8J6R31 const59e19706d51d39f66711c265) (let __tconst88cs27 const35135aaa6cc23891b40cb3f3) (let __tconst0Uuf25 const624b60c58c9d8bfb6ff1886c) (let __tconst6sf622 consteb1e33e8a81b697b75855af6) (let __tconst5Run20 conste29c9c180c6279b0b02abd6a)) (seeded) (body (join Lf (1 0) 1 __tconst5Run20 __t8mDO21) (exists Nd (2 1 0) 1 __t8mDO21) (exists Lf (1 0) 1 __tconst0Uuf25) (exists Lf (1 0) 1 __tconst88cs27) (exists Lf (1 0) 1 __tconst8J6R31) (exists Lf (1 0) 1 __tconst2Isx33) (exists Lf (1 0) 1 __tconst8u8i36) (exists Lf (1 0) 1 __tconst1Mto38) (exists Lf (1 0) 1 __tconst9j2a43) (exists Lf (1 0) 1 __tconst7AKN45) (exists Lf (1 0) 1 __tconst6bEj48) (exists Lf (1 0) 1 __tconst6Qm150) (exists Lf (1 0) 1 __tconst51zc54) (exists Lf (1 0) 1 __tconst4Vop56) (exists Lf (1 0) 1 __tconst31qC59) (exists Lf (1 0) 1 __tconst5zmq61) (exists Lf (1 0) 1 __tconst7kHD67) (exists Lf (1 0) 1 __tconst2hOw69) (exists Lf (1 0) 1 __tconst74Qx72) (exists Lf (1 0) 1 __tconst6a9N74) (exists Lf (1 0) 1 __tconst3KyY78) (exists Lf (1 0) 1 __tconst42lR80) (exists Lf (1 0) 1 __tconst01Wl83) (exists Lf (1 0) 1 __tconst7wWY85) (exists Lf (1 0) 1 __tconst9Yxv90) (exists Lf (1 0) 1 __tconst9mjQ92) (exists Lf (1 0) 1 __tconst29xA95) (exists Lf (1 0) 1 __tconst0Emh97) (exists Lf (1 0) 1 __tconst3iHp101) (exists Lf (1 0) 1 __tconst9YpM103) (exists Lf (1 0) 1 __tconst5Uhl106) (exists Lf (1 0) 1 __tconst48SJ108) (join Lf (1 0) 1 __tconst6sf622 __t1M8o23) (join Nd (2 1 0) 2 __t8mDO21 __t1M8o23 __t7LF824) (exists Nd (2 1 0) 1 __t7LF824) (join Lf (1 0) 1 __tconst0Uuf25 __t1NQv26) (exists Nd (2 1 0) 1 __t1NQv26) (join Lf (1 0) 1 __tconst88cs27 __t7d0c28) (join Nd (2 1 0) 2 __t1NQv26 __t7d0c28 __t0kIY29) (join Nd (2 1 0) 2 __t7LF824 __t0kIY29 __t6JrG30) (exists Nd (2 1 0) 1 __t6JrG30) (join Lf (1 0) 1 __tconst8J6R31 __t9vh832) (exists Nd (2 1 0) 1 __t9vh832) (join Lf (1 0) 1 __tconst2Isx33 __t5flt34) (join Nd (2 1 0) 2 __t9vh832 __t5flt34 __t3jHg35) (exists Nd (2 1 0) 1 __t3jHg35) (join Lf (1 0) 1 __tconst8u8i36 __t27Zr37) (exists Nd (2 1 0) 1 __t27Zr37) (join Lf (1 0) 1 __tconst1Mto38 __t3UFu39) (join Nd (2 1 0) 2 __t27Zr37 __t3UFu39 __t8qqV40) (join Nd (2 1 0) 2 __t3jHg35 __t8qqV40 __t2KtK41) (join Nd (2 1 0) 2 __t6JrG30 __t2KtK41 __t17Jm42) (exists Nd (2 1 0) 1 __t17Jm42) (join Lf (1 0) 1 __tconst9j2a43 __t6IKq44) (exists Nd (2 1 0) 1 __t6IKq44) (join Lf (1 0) 1 __tconst7AKN45 __t6LIW46) (join Nd (2 1 0) 2 __t6IKq44 __t6LIW46 __t7C7d47) (exists Nd (2 1 0) 1 __t7C7d47) (join Lf (1 0) 1 __tconst6bEj48 __t9k7a49) (exists Nd (2 1 0) 1 __t9k7a49) (join Lf (1 0) 1 __tconst6Qm150 __t4MdC51) (join Nd (2 1 0) 2 __t9k7a49 __t4MdC51 __t8A9i52) (join Nd (2 1 0) 2 __t7C7d47 __t8A9i52 __t7DSY53) (exists Nd (2 1 0) 1 __t7DSY53) (join Lf (1 0) 1 __tconst51zc54 __t3Yon55) (exists Nd (2 1 0) 1 __t3Yon55) (join Lf (1 0) 1 __tconst4Vop56 __t5ik157) (join Nd (2 1 0) 2 __t3Yon55 __t5ik157 __t4hi358) (exists Nd (2 1 0) 1 __t4hi358) (join Lf (1 0) 1 __tconst31qC59 __t1nkJ60) (exists Nd (2 1 0) 1 __t1nkJ60) (join Lf (1 0) 1 __tconst5zmq61 __t4E3D62) (join Nd (2 1 0) 2 __t1nkJ60 __t4E3D62 __t8TXU63) (join Nd (2 1 0) 2 __t4hi358 __t8TXU63 __t6bZq64) (join Nd (2 1 0) 2 __t7DSY53 __t6bZq64 __t4uRs65) (join Nd (2 1 0) 2 __t17Jm42 __t4uRs65 __t4LVF66) (exists Nd (2 1 0) 1 __t4LVF66) (join Lf (1 0) 1 __tconst7kHD67 __t4J2N68) (exists Nd (2 1 0) 1 __t4J2N68) (join Lf (1 0) 1 __tconst2hOw69 __t4izo70) (join Nd (2 1 0) 2 __t4J2N68 __t4izo70 __t14Ff71) (exists Nd (2 1 0) 1 __t14Ff71) (join Lf (1 0) 1 __tconst74Qx72 __t319l73) (exists Nd (2 1 0) 1 __t319l73) (join Lf (1 0) 1 __tconst6a9N74 __t0amQ75) (join Nd (2 1 0) 2 __t319l73 __t0amQ75 __t4MUf76) (join Nd (2 1 0) 2 __t14Ff71 __t4MUf76 __t13Wj77) (exists Nd (2 1 0) 1 __t13Wj77) (join Lf (1 0) 1 __tconst3KyY78 __t13gt79) (exists Nd (2 1 0) 1 __t13gt79) (join Lf (1 0) 1 __tconst42lR80 __t3ESz81) (join Nd (2 1 0) 2 __t13gt79 __t3ESz81 __t3WL082) (exists Nd (2 1 0) 1 __t3WL082) (join Lf (1 0) 1 __tconst01Wl83 __t4Da384) (exists Nd (2 1 0) 1 __t4Da384) (join Lf (1 0) 1 __tconst7wWY85 __t91gs86) (join Nd (2 1 0) 2 __t4Da384 __t91gs86 __t02Bu87) (join Nd (2 1 0) 2 __t3WL082 __t02Bu87 __t60KJ88) (join Nd (2 1 0) 2 __t13Wj77 __t60KJ88 __t4p4K89) (exists Nd (2 1 0) 1 __t4p4K89) (join Lf (1 0) 1 __tconst9Yxv90 __t7UaH91) (exists Nd (2 1 0) 1 __t7UaH91) (join Lf (1 0) 1 __tconst9mjQ92 __t6IMg93) (join Nd (2 1 0) 2 __t7UaH91 __t6IMg93 __t2T3i94) (exists Nd (2 1 0) 1 __t2T3i94) (join Lf (1 0) 1 __tconst29xA95 __t2oHE96) (exists Nd (2 1 0) 1 __t2oHE96) (join Lf (1 0) 1 __tconst0Emh97 __t7bue98) (join Nd (2 1 0) 2 __t2oHE96 __t7bue98 __t0HkS99) (join Nd (2 1 0) 2 __t2T3i94 __t0HkS99 __t7PLp100) (exists Nd (2 1 0) 1 __t7PLp100) (join Lf (1 0) 1 __tconst3iHp101 __t5yzC102) (exists Nd (2 1 0) 1 __t5yzC102) (join Lf (1 0) 1 __tconst9YpM103 __t7c21104) (join Nd (2 1 0) 2 __t5yzC102 __t7c21104 __t4bRV105) (exists Nd (2 1 0) 1 __t4bRV105) (join Lf (1 0) 1 __tconst5Uhl106 __t1IJA107) (exists Nd (2 1 0) 1 __t1IJA107) (join Lf (1 0) 1 __tconst48SJ108 __t0y5t109) (join Nd (2 1 0) 2 __t1IJA107 __t0y5t109 __t76VS110) (join Nd (2 1 0) 2 __t4bRV105 __t76VS110 __t3a3T111) (join Nd (2 1 0) 2 __t7PLp100 __t3a3T111 __t9dGZ112) (join Nd (2 1 0) 2 __t4p4K89 __t9dGZ112 __t09Ym113) (join Nd (2 1 0) 2 __t4LVF66 __t09Ym113 __t1U6n114)) (head (emit t (0) __t1U6n114)) deep_fact.slog:7 #f)
  class ReadTask1328 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** Lfindex1204;  slog::Index** Ndindex1205;  slog::Index** Lfindex1206;  slog::Index** Lfindex1207;  slog::Index** Lfindex1208;  slog::Index** Lfindex1209;  slog::Index** Lfindex1210;  slog::Index** Lfindex1211;  slog::Index** Lfindex1212;  slog::Index** Lfindex1213;  slog::Index** Lfindex1214;  slog::Index** Lfindex1215;  slog::Index** Lfindex1216;  slog::Index** Lfindex1217;  slog::Index** Lfindex1218;  slog::Index** Lfindex1219;  slog::Index** Lfindex1220;  slog::Index** Lfindex1221;  slog::Index** Lfindex1222;  slog::Index** Lfindex1223;  slog::Index** Lfindex1224;  slog::Index** Lfindex1225;  slog::Index** Lfindex1226;  slog::Index** Lfindex1227;  slog::Index** Lfindex1228;  slog::Index** Lfindex1229;  slog::Index** Lfindex1230;  slog::Index** Lfindex1231;  slog::Index** Lfindex1232;  slog::Index** Lfindex1233;  slog::Index** Lfindex1234;  slog::Index** Lfindex1235;  slog::Index** Lfindex1236;  slog::Index** Ndindex1237;  slog::Index** Ndindex1238;  slog::Index** Lfindex1239;  slog::Index** Ndindex1240;  slog::Index** Lfindex1241;  slog::Index** Ndindex1242;  slog::Index** Ndindex1243;  slog::Index** Ndindex1244;  slog::Index** Lfindex1245;  slog::Index** Ndindex1246;  slog::Index** Lfindex1247;  slog::Index** Ndindex1248;  slog::Index** Ndindex1249;  slog::Index** Lfindex1250;  slog::Index** Ndindex1251;  slog::Index** Lfindex1252;  slog::Index** Ndindex1253;  slog::Index** Ndindex1254;  slog::Index** Ndindex1255;  slog::Index** Ndindex1256;  slog::Index** Lfindex1257;  slog::Index** Ndindex1258;  slog::Index** Lfindex1259;  slog::Index** Ndindex1260;  slog::Index** Ndindex1261;  slog::Index** Lfindex1262;  slog::Index** Ndindex1263;  slog::Index** Lfindex1264;  slog::Index** Ndindex1265;  slog::Index** Ndindex1266;  slog::Index** Ndindex1267;  slog::Index** Lfindex1268;  slog::Index** Ndindex1269;  slog::Index** Lfindex1270;  slog::Index** Ndindex1271;  slog::Index** Ndindex1272;  slog::Index** Lfindex1273;  slog::Index** Ndindex1274;  slog::Index** Lfindex1275;  slog::Index** Ndindex1276;  slog::Index** Ndindex1277;  slog::Index** Ndindex1278;  slog::Index** Ndindex1279;  slog::Index** Ndindex1280;  slog::Index** Lfindex1281;  slog::Index** Ndindex1282;  slog::Index** Lfindex1283;  slog::Index** Ndindex1284;  slog::Index** Ndindex1285;  slog::Index** Lfindex1286;  slog::Index** Ndindex1287;  slog::Index** Lfindex1288;  slog::Index** Ndindex1289;  slog::Index** Ndindex1290;  slog::Index** Ndindex1291;  slog::Index** Lfindex1292;  slog::Index** Ndindex1293;  slog::Index** Lfindex1294;  slog::Index** Ndindex1295;  slog::Index** Ndindex1296;  slog::Index** Lfindex1297;  slog::Index** Ndindex1298;  slog::Index** Lfindex1299;  slog::Index** Ndindex1300;  slog::Index** Ndindex1301;  slog::Index** Ndindex1302;  slog::Index** Ndindex1303;  slog::Index** Lfindex1304;  slog::Index** Ndindex1305;  slog::Index** Lfindex1306;  slog::Index** Ndindex1307;  slog::Index** Ndindex1308;  slog::Index** Lfindex1309;  slog::Index** Ndindex1310;  slog::Index** Lfindex1311;  slog::Index** Ndindex1312;  slog::Index** Ndindex1313;  slog::Index** Ndindex1314;  slog::Index** Lfindex1315;  slog::Index** Ndindex1316;  slog::Index** Lfindex1317;  slog::Index** Ndindex1318;  slog::Index** Ndindex1319;  slog::Index** Lfindex1320;  slog::Index** Ndindex1321;  slog::Index** Lfindex1322;  slog::Index** Ndindex1323;  slog::Index** Ndindex1324;  slog::Index** Ndindex1325;  slog::Index** Ndindex1326;  slog::Index** Ndindex1327;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("t");
      std::vector<u16> ord1329({0});
      slog::Relation* readrel1330 = db->getRelation("t");
      head_index[0] = readrel1330->getIndex(ord1329, false);
      std::vector<u16> ord1331({1, 0});
      slog::Relation* readrel1332 = db->getRelation("Lf");
      Lfindex1204 = readrel1332->getIndex(ord1331, false);
      std::vector<u16> ord1333({2, 1, 0});
      slog::Relation* readrel1334 = db->getRelation("Nd");
      Ndindex1205 = readrel1334->getIndex(ord1333, false);
      std::vector<u16> ord1335({1, 0});
      slog::Relation* readrel1336 = db->getRelation("Lf");
      Lfindex1206 = readrel1336->getIndex(ord1335, false);
      std::vector<u16> ord1337({1, 0});
      slog::Relation* readrel1338 = db->getRelation("Lf");
      Lfindex1207 = readrel1338->getIndex(ord1337, false);
      std::vector<u16> ord1339({1, 0});
      slog::Relation* readrel1340 = db->getRelation("Lf");
      Lfindex1208 = readrel1340->getIndex(ord1339, false);
      std::vector<u16> ord1341({1, 0});
      slog::Relation* readrel1342 = db->getRelation("Lf");
      Lfindex1209 = readrel1342->getIndex(ord1341, false);
      std::vector<u16> ord1343({1, 0});
      slog::Relation* readrel1344 = db->getRelation("Lf");
      Lfindex1210 = readrel1344->getIndex(ord1343, false);
      std::vector<u16> ord1345({1, 0});
      slog::Relation* readrel1346 = db->getRelation("Lf");
      Lfindex1211 = readrel1346->getIndex(ord1345, false);
      std::vector<u16> ord1347({1, 0});
      slog::Relation* readrel1348 = db->getRelation("Lf");
      Lfindex1212 = readrel1348->getIndex(ord1347, false);
      std::vector<u16> ord1349({1, 0});
      slog::Relation* readrel1350 = db->getRelation("Lf");
      Lfindex1213 = readrel1350->getIndex(ord1349, false);
      std::vector<u16> ord1351({1, 0});
      slog::Relation* readrel1352 = db->getRelation("Lf");
      Lfindex1214 = readrel1352->getIndex(ord1351, false);
      std::vector<u16> ord1353({1, 0});
      slog::Relation* readrel1354 = db->getRelation("Lf");
      Lfindex1215 = readrel1354->getIndex(ord1353, false);
      std::vector<u16> ord1355({1, 0});
      slog::Relation* readrel1356 = db->getRelation("Lf");
      Lfindex1216 = readrel1356->getIndex(ord1355, false);
      std::vector<u16> ord1357({1, 0});
      slog::Relation* readrel1358 = db->getRelation("Lf");
      Lfindex1217 = readrel1358->getIndex(ord1357, false);
      std::vector<u16> ord1359({1, 0});
      slog::Relation* readrel1360 = db->getRelation("Lf");
      Lfindex1218 = readrel1360->getIndex(ord1359, false);
      std::vector<u16> ord1361({1, 0});
      slog::Relation* readrel1362 = db->getRelation("Lf");
      Lfindex1219 = readrel1362->getIndex(ord1361, false);
      std::vector<u16> ord1363({1, 0});
      slog::Relation* readrel1364 = db->getRelation("Lf");
      Lfindex1220 = readrel1364->getIndex(ord1363, false);
      std::vector<u16> ord1365({1, 0});
      slog::Relation* readrel1366 = db->getRelation("Lf");
      Lfindex1221 = readrel1366->getIndex(ord1365, false);
      std::vector<u16> ord1367({1, 0});
      slog::Relation* readrel1368 = db->getRelation("Lf");
      Lfindex1222 = readrel1368->getIndex(ord1367, false);
      std::vector<u16> ord1369({1, 0});
      slog::Relation* readrel1370 = db->getRelation("Lf");
      Lfindex1223 = readrel1370->getIndex(ord1369, false);
      std::vector<u16> ord1371({1, 0});
      slog::Relation* readrel1372 = db->getRelation("Lf");
      Lfindex1224 = readrel1372->getIndex(ord1371, false);
      std::vector<u16> ord1373({1, 0});
      slog::Relation* readrel1374 = db->getRelation("Lf");
      Lfindex1225 = readrel1374->getIndex(ord1373, false);
      std::vector<u16> ord1375({1, 0});
      slog::Relation* readrel1376 = db->getRelation("Lf");
      Lfindex1226 = readrel1376->getIndex(ord1375, false);
      std::vector<u16> ord1377({1, 0});
      slog::Relation* readrel1378 = db->getRelation("Lf");
      Lfindex1227 = readrel1378->getIndex(ord1377, false);
      std::vector<u16> ord1379({1, 0});
      slog::Relation* readrel1380 = db->getRelation("Lf");
      Lfindex1228 = readrel1380->getIndex(ord1379, false);
      std::vector<u16> ord1381({1, 0});
      slog::Relation* readrel1382 = db->getRelation("Lf");
      Lfindex1229 = readrel1382->getIndex(ord1381, false);
      std::vector<u16> ord1383({1, 0});
      slog::Relation* readrel1384 = db->getRelation("Lf");
      Lfindex1230 = readrel1384->getIndex(ord1383, false);
      std::vector<u16> ord1385({1, 0});
      slog::Relation* readrel1386 = db->getRelation("Lf");
      Lfindex1231 = readrel1386->getIndex(ord1385, false);
      std::vector<u16> ord1387({1, 0});
      slog::Relation* readrel1388 = db->getRelation("Lf");
      Lfindex1232 = readrel1388->getIndex(ord1387, false);
      std::vector<u16> ord1389({1, 0});
      slog::Relation* readrel1390 = db->getRelation("Lf");
      Lfindex1233 = readrel1390->getIndex(ord1389, false);
      std::vector<u16> ord1391({1, 0});
      slog::Relation* readrel1392 = db->getRelation("Lf");
      Lfindex1234 = readrel1392->getIndex(ord1391, false);
      std::vector<u16> ord1393({1, 0});
      slog::Relation* readrel1394 = db->getRelation("Lf");
      Lfindex1235 = readrel1394->getIndex(ord1393, false);
      std::vector<u16> ord1395({1, 0});
      slog::Relation* readrel1396 = db->getRelation("Lf");
      Lfindex1236 = readrel1396->getIndex(ord1395, false);
      std::vector<u16> ord1397({2, 1, 0});
      slog::Relation* readrel1398 = db->getRelation("Nd");
      Ndindex1237 = readrel1398->getIndex(ord1397, false);
      std::vector<u16> ord1399({2, 1, 0});
      slog::Relation* readrel1400 = db->getRelation("Nd");
      Ndindex1238 = readrel1400->getIndex(ord1399, false);
      std::vector<u16> ord1401({1, 0});
      slog::Relation* readrel1402 = db->getRelation("Lf");
      Lfindex1239 = readrel1402->getIndex(ord1401, false);
      std::vector<u16> ord1403({2, 1, 0});
      slog::Relation* readrel1404 = db->getRelation("Nd");
      Ndindex1240 = readrel1404->getIndex(ord1403, false);
      std::vector<u16> ord1405({1, 0});
      slog::Relation* readrel1406 = db->getRelation("Lf");
      Lfindex1241 = readrel1406->getIndex(ord1405, false);
      std::vector<u16> ord1407({2, 1, 0});
      slog::Relation* readrel1408 = db->getRelation("Nd");
      Ndindex1242 = readrel1408->getIndex(ord1407, false);
      std::vector<u16> ord1409({2, 1, 0});
      slog::Relation* readrel1410 = db->getRelation("Nd");
      Ndindex1243 = readrel1410->getIndex(ord1409, false);
      std::vector<u16> ord1411({2, 1, 0});
      slog::Relation* readrel1412 = db->getRelation("Nd");
      Ndindex1244 = readrel1412->getIndex(ord1411, false);
      std::vector<u16> ord1413({1, 0});
      slog::Relation* readrel1414 = db->getRelation("Lf");
      Lfindex1245 = readrel1414->getIndex(ord1413, false);
      std::vector<u16> ord1415({2, 1, 0});
      slog::Relation* readrel1416 = db->getRelation("Nd");
      Ndindex1246 = readrel1416->getIndex(ord1415, false);
      std::vector<u16> ord1417({1, 0});
      slog::Relation* readrel1418 = db->getRelation("Lf");
      Lfindex1247 = readrel1418->getIndex(ord1417, false);
      std::vector<u16> ord1419({2, 1, 0});
      slog::Relation* readrel1420 = db->getRelation("Nd");
      Ndindex1248 = readrel1420->getIndex(ord1419, false);
      std::vector<u16> ord1421({2, 1, 0});
      slog::Relation* readrel1422 = db->getRelation("Nd");
      Ndindex1249 = readrel1422->getIndex(ord1421, false);
      std::vector<u16> ord1423({1, 0});
      slog::Relation* readrel1424 = db->getRelation("Lf");
      Lfindex1250 = readrel1424->getIndex(ord1423, false);
      std::vector<u16> ord1425({2, 1, 0});
      slog::Relation* readrel1426 = db->getRelation("Nd");
      Ndindex1251 = readrel1426->getIndex(ord1425, false);
      std::vector<u16> ord1427({1, 0});
      slog::Relation* readrel1428 = db->getRelation("Lf");
      Lfindex1252 = readrel1428->getIndex(ord1427, false);
      std::vector<u16> ord1429({2, 1, 0});
      slog::Relation* readrel1430 = db->getRelation("Nd");
      Ndindex1253 = readrel1430->getIndex(ord1429, false);
      std::vector<u16> ord1431({2, 1, 0});
      slog::Relation* readrel1432 = db->getRelation("Nd");
      Ndindex1254 = readrel1432->getIndex(ord1431, false);
      std::vector<u16> ord1433({2, 1, 0});
      slog::Relation* readrel1434 = db->getRelation("Nd");
      Ndindex1255 = readrel1434->getIndex(ord1433, false);
      std::vector<u16> ord1435({2, 1, 0});
      slog::Relation* readrel1436 = db->getRelation("Nd");
      Ndindex1256 = readrel1436->getIndex(ord1435, false);
      std::vector<u16> ord1437({1, 0});
      slog::Relation* readrel1438 = db->getRelation("Lf");
      Lfindex1257 = readrel1438->getIndex(ord1437, false);
      std::vector<u16> ord1439({2, 1, 0});
      slog::Relation* readrel1440 = db->getRelation("Nd");
      Ndindex1258 = readrel1440->getIndex(ord1439, false);
      std::vector<u16> ord1441({1, 0});
      slog::Relation* readrel1442 = db->getRelation("Lf");
      Lfindex1259 = readrel1442->getIndex(ord1441, false);
      std::vector<u16> ord1443({2, 1, 0});
      slog::Relation* readrel1444 = db->getRelation("Nd");
      Ndindex1260 = readrel1444->getIndex(ord1443, false);
      std::vector<u16> ord1445({2, 1, 0});
      slog::Relation* readrel1446 = db->getRelation("Nd");
      Ndindex1261 = readrel1446->getIndex(ord1445, false);
      std::vector<u16> ord1447({1, 0});
      slog::Relation* readrel1448 = db->getRelation("Lf");
      Lfindex1262 = readrel1448->getIndex(ord1447, false);
      std::vector<u16> ord1449({2, 1, 0});
      slog::Relation* readrel1450 = db->getRelation("Nd");
      Ndindex1263 = readrel1450->getIndex(ord1449, false);
      std::vector<u16> ord1451({1, 0});
      slog::Relation* readrel1452 = db->getRelation("Lf");
      Lfindex1264 = readrel1452->getIndex(ord1451, false);
      std::vector<u16> ord1453({2, 1, 0});
      slog::Relation* readrel1454 = db->getRelation("Nd");
      Ndindex1265 = readrel1454->getIndex(ord1453, false);
      std::vector<u16> ord1455({2, 1, 0});
      slog::Relation* readrel1456 = db->getRelation("Nd");
      Ndindex1266 = readrel1456->getIndex(ord1455, false);
      std::vector<u16> ord1457({2, 1, 0});
      slog::Relation* readrel1458 = db->getRelation("Nd");
      Ndindex1267 = readrel1458->getIndex(ord1457, false);
      std::vector<u16> ord1459({1, 0});
      slog::Relation* readrel1460 = db->getRelation("Lf");
      Lfindex1268 = readrel1460->getIndex(ord1459, false);
      std::vector<u16> ord1461({2, 1, 0});
      slog::Relation* readrel1462 = db->getRelation("Nd");
      Ndindex1269 = readrel1462->getIndex(ord1461, false);
      std::vector<u16> ord1463({1, 0});
      slog::Relation* readrel1464 = db->getRelation("Lf");
      Lfindex1270 = readrel1464->getIndex(ord1463, false);
      std::vector<u16> ord1465({2, 1, 0});
      slog::Relation* readrel1466 = db->getRelation("Nd");
      Ndindex1271 = readrel1466->getIndex(ord1465, false);
      std::vector<u16> ord1467({2, 1, 0});
      slog::Relation* readrel1468 = db->getRelation("Nd");
      Ndindex1272 = readrel1468->getIndex(ord1467, false);
      std::vector<u16> ord1469({1, 0});
      slog::Relation* readrel1470 = db->getRelation("Lf");
      Lfindex1273 = readrel1470->getIndex(ord1469, false);
      std::vector<u16> ord1471({2, 1, 0});
      slog::Relation* readrel1472 = db->getRelation("Nd");
      Ndindex1274 = readrel1472->getIndex(ord1471, false);
      std::vector<u16> ord1473({1, 0});
      slog::Relation* readrel1474 = db->getRelation("Lf");
      Lfindex1275 = readrel1474->getIndex(ord1473, false);
      std::vector<u16> ord1475({2, 1, 0});
      slog::Relation* readrel1476 = db->getRelation("Nd");
      Ndindex1276 = readrel1476->getIndex(ord1475, false);
      std::vector<u16> ord1477({2, 1, 0});
      slog::Relation* readrel1478 = db->getRelation("Nd");
      Ndindex1277 = readrel1478->getIndex(ord1477, false);
      std::vector<u16> ord1479({2, 1, 0});
      slog::Relation* readrel1480 = db->getRelation("Nd");
      Ndindex1278 = readrel1480->getIndex(ord1479, false);
      std::vector<u16> ord1481({2, 1, 0});
      slog::Relation* readrel1482 = db->getRelation("Nd");
      Ndindex1279 = readrel1482->getIndex(ord1481, false);
      std::vector<u16> ord1483({2, 1, 0});
      slog::Relation* readrel1484 = db->getRelation("Nd");
      Ndindex1280 = readrel1484->getIndex(ord1483, false);
      std::vector<u16> ord1485({1, 0});
      slog::Relation* readrel1486 = db->getRelation("Lf");
      Lfindex1281 = readrel1486->getIndex(ord1485, false);
      std::vector<u16> ord1487({2, 1, 0});
      slog::Relation* readrel1488 = db->getRelation("Nd");
      Ndindex1282 = readrel1488->getIndex(ord1487, false);
      std::vector<u16> ord1489({1, 0});
      slog::Relation* readrel1490 = db->getRelation("Lf");
      Lfindex1283 = readrel1490->getIndex(ord1489, false);
      std::vector<u16> ord1491({2, 1, 0});
      slog::Relation* readrel1492 = db->getRelation("Nd");
      Ndindex1284 = readrel1492->getIndex(ord1491, false);
      std::vector<u16> ord1493({2, 1, 0});
      slog::Relation* readrel1494 = db->getRelation("Nd");
      Ndindex1285 = readrel1494->getIndex(ord1493, false);
      std::vector<u16> ord1495({1, 0});
      slog::Relation* readrel1496 = db->getRelation("Lf");
      Lfindex1286 = readrel1496->getIndex(ord1495, false);
      std::vector<u16> ord1497({2, 1, 0});
      slog::Relation* readrel1498 = db->getRelation("Nd");
      Ndindex1287 = readrel1498->getIndex(ord1497, false);
      std::vector<u16> ord1499({1, 0});
      slog::Relation* readrel1500 = db->getRelation("Lf");
      Lfindex1288 = readrel1500->getIndex(ord1499, false);
      std::vector<u16> ord1501({2, 1, 0});
      slog::Relation* readrel1502 = db->getRelation("Nd");
      Ndindex1289 = readrel1502->getIndex(ord1501, false);
      std::vector<u16> ord1503({2, 1, 0});
      slog::Relation* readrel1504 = db->getRelation("Nd");
      Ndindex1290 = readrel1504->getIndex(ord1503, false);
      std::vector<u16> ord1505({2, 1, 0});
      slog::Relation* readrel1506 = db->getRelation("Nd");
      Ndindex1291 = readrel1506->getIndex(ord1505, false);
      std::vector<u16> ord1507({1, 0});
      slog::Relation* readrel1508 = db->getRelation("Lf");
      Lfindex1292 = readrel1508->getIndex(ord1507, false);
      std::vector<u16> ord1509({2, 1, 0});
      slog::Relation* readrel1510 = db->getRelation("Nd");
      Ndindex1293 = readrel1510->getIndex(ord1509, false);
      std::vector<u16> ord1511({1, 0});
      slog::Relation* readrel1512 = db->getRelation("Lf");
      Lfindex1294 = readrel1512->getIndex(ord1511, false);
      std::vector<u16> ord1513({2, 1, 0});
      slog::Relation* readrel1514 = db->getRelation("Nd");
      Ndindex1295 = readrel1514->getIndex(ord1513, false);
      std::vector<u16> ord1515({2, 1, 0});
      slog::Relation* readrel1516 = db->getRelation("Nd");
      Ndindex1296 = readrel1516->getIndex(ord1515, false);
      std::vector<u16> ord1517({1, 0});
      slog::Relation* readrel1518 = db->getRelation("Lf");
      Lfindex1297 = readrel1518->getIndex(ord1517, false);
      std::vector<u16> ord1519({2, 1, 0});
      slog::Relation* readrel1520 = db->getRelation("Nd");
      Ndindex1298 = readrel1520->getIndex(ord1519, false);
      std::vector<u16> ord1521({1, 0});
      slog::Relation* readrel1522 = db->getRelation("Lf");
      Lfindex1299 = readrel1522->getIndex(ord1521, false);
      std::vector<u16> ord1523({2, 1, 0});
      slog::Relation* readrel1524 = db->getRelation("Nd");
      Ndindex1300 = readrel1524->getIndex(ord1523, false);
      std::vector<u16> ord1525({2, 1, 0});
      slog::Relation* readrel1526 = db->getRelation("Nd");
      Ndindex1301 = readrel1526->getIndex(ord1525, false);
      std::vector<u16> ord1527({2, 1, 0});
      slog::Relation* readrel1528 = db->getRelation("Nd");
      Ndindex1302 = readrel1528->getIndex(ord1527, false);
      std::vector<u16> ord1529({2, 1, 0});
      slog::Relation* readrel1530 = db->getRelation("Nd");
      Ndindex1303 = readrel1530->getIndex(ord1529, false);
      std::vector<u16> ord1531({1, 0});
      slog::Relation* readrel1532 = db->getRelation("Lf");
      Lfindex1304 = readrel1532->getIndex(ord1531, false);
      std::vector<u16> ord1533({2, 1, 0});
      slog::Relation* readrel1534 = db->getRelation("Nd");
      Ndindex1305 = readrel1534->getIndex(ord1533, false);
      std::vector<u16> ord1535({1, 0});
      slog::Relation* readrel1536 = db->getRelation("Lf");
      Lfindex1306 = readrel1536->getIndex(ord1535, false);
      std::vector<u16> ord1537({2, 1, 0});
      slog::Relation* readrel1538 = db->getRelation("Nd");
      Ndindex1307 = readrel1538->getIndex(ord1537, false);
      std::vector<u16> ord1539({2, 1, 0});
      slog::Relation* readrel1540 = db->getRelation("Nd");
      Ndindex1308 = readrel1540->getIndex(ord1539, false);
      std::vector<u16> ord1541({1, 0});
      slog::Relation* readrel1542 = db->getRelation("Lf");
      Lfindex1309 = readrel1542->getIndex(ord1541, false);
      std::vector<u16> ord1543({2, 1, 0});
      slog::Relation* readrel1544 = db->getRelation("Nd");
      Ndindex1310 = readrel1544->getIndex(ord1543, false);
      std::vector<u16> ord1545({1, 0});
      slog::Relation* readrel1546 = db->getRelation("Lf");
      Lfindex1311 = readrel1546->getIndex(ord1545, false);
      std::vector<u16> ord1547({2, 1, 0});
      slog::Relation* readrel1548 = db->getRelation("Nd");
      Ndindex1312 = readrel1548->getIndex(ord1547, false);
      std::vector<u16> ord1549({2, 1, 0});
      slog::Relation* readrel1550 = db->getRelation("Nd");
      Ndindex1313 = readrel1550->getIndex(ord1549, false);
      std::vector<u16> ord1551({2, 1, 0});
      slog::Relation* readrel1552 = db->getRelation("Nd");
      Ndindex1314 = readrel1552->getIndex(ord1551, false);
      std::vector<u16> ord1553({1, 0});
      slog::Relation* readrel1554 = db->getRelation("Lf");
      Lfindex1315 = readrel1554->getIndex(ord1553, false);
      std::vector<u16> ord1555({2, 1, 0});
      slog::Relation* readrel1556 = db->getRelation("Nd");
      Ndindex1316 = readrel1556->getIndex(ord1555, false);
      std::vector<u16> ord1557({1, 0});
      slog::Relation* readrel1558 = db->getRelation("Lf");
      Lfindex1317 = readrel1558->getIndex(ord1557, false);
      std::vector<u16> ord1559({2, 1, 0});
      slog::Relation* readrel1560 = db->getRelation("Nd");
      Ndindex1318 = readrel1560->getIndex(ord1559, false);
      std::vector<u16> ord1561({2, 1, 0});
      slog::Relation* readrel1562 = db->getRelation("Nd");
      Ndindex1319 = readrel1562->getIndex(ord1561, false);
      std::vector<u16> ord1563({1, 0});
      slog::Relation* readrel1564 = db->getRelation("Lf");
      Lfindex1320 = readrel1564->getIndex(ord1563, false);
      std::vector<u16> ord1565({2, 1, 0});
      slog::Relation* readrel1566 = db->getRelation("Nd");
      Ndindex1321 = readrel1566->getIndex(ord1565, false);
      std::vector<u16> ord1567({1, 0});
      slog::Relation* readrel1568 = db->getRelation("Lf");
      Lfindex1322 = readrel1568->getIndex(ord1567, false);
      std::vector<u16> ord1569({2, 1, 0});
      slog::Relation* readrel1570 = db->getRelation("Nd");
      Ndindex1323 = readrel1570->getIndex(ord1569, false);
      std::vector<u16> ord1571({2, 1, 0});
      slog::Relation* readrel1572 = db->getRelation("Nd");
      Ndindex1324 = readrel1572->getIndex(ord1571, false);
      std::vector<u16> ord1573({2, 1, 0});
      slog::Relation* readrel1574 = db->getRelation("Nd");
      Ndindex1325 = readrel1574->getIndex(ord1573, false);
      std::vector<u16> ord1575({2, 1, 0});
      slog::Relation* readrel1576 = db->getRelation("Nd");
      Ndindex1326 = readrel1576->getIndex(ord1575, false);
      std::vector<u16> ord1577({2, 1, 0});
      slog::Relation* readrel1578 = db->getRelation("Nd");
      Ndindex1327 = readrel1578->getIndex(ord1577, false);
  
    }
    ReadTask1328(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(Lfindex1204, std::array<u64,2>{v_c31, 0}, [&](const std::array<u64,2>& m1579) {
        u64 v_c35 = m1579[1];
        if (!slog::exists_probe<3,1>(Ndindex1205, std::array<u64,3>{v_c35, 0, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1206, std::array<u64,2>{v_c29, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1207, std::array<u64,2>{v_c28, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1208, std::array<u64,2>{v_c27, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1209, std::array<u64,2>{v_c26, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1210, std::array<u64,2>{v_c25, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1211, std::array<u64,2>{v_c24, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1212, std::array<u64,2>{v_c23, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1213, std::array<u64,2>{v_c22, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1214, std::array<u64,2>{v_c21, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1215, std::array<u64,2>{v_c20, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1216, std::array<u64,2>{v_c19, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1217, std::array<u64,2>{v_c18, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1218, std::array<u64,2>{v_c17, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1219, std::array<u64,2>{v_c16, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1220, std::array<u64,2>{v_c15, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1221, std::array<u64,2>{v_c14, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1222, std::array<u64,2>{v_c13, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1223, std::array<u64,2>{v_c12, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1224, std::array<u64,2>{v_c11, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1225, std::array<u64,2>{v_c10, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1226, std::array<u64,2>{v_c9, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1227, std::array<u64,2>{v_c8, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1228, std::array<u64,2>{v_c7, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1229, std::array<u64,2>{v_c6, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1230, std::array<u64,2>{v_c5, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1231, std::array<u64,2>{v_c4, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1232, std::array<u64,2>{v_c3, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1233, std::array<u64,2>{v_c2, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1234, std::array<u64,2>{v_c1, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1235, std::array<u64,2>{v_c0, 0})) return;
        slog::join_probe<2,1>(Lfindex1236, std::array<u64,2>{v_c30, 0}, [&](const std::array<u64,2>& m1580) {
          u64 v_c36 = m1580[1];
          slog::join_probe<3,2>(Ndindex1237, std::array<u64,3>{v_c35, v_c36, 0}, [&](const std::array<u64,3>& m1581) {
            u64 v_c37 = m1581[2];
            if (!slog::exists_probe<3,1>(Ndindex1238, std::array<u64,3>{v_c37, 0, 0})) return;
            slog::join_probe<2,1>(Lfindex1239, std::array<u64,2>{v_c29, 0}, [&](const std::array<u64,2>& m1582) {
              u64 v_c38 = m1582[1];
              if (!slog::exists_probe<3,1>(Ndindex1240, std::array<u64,3>{v_c38, 0, 0})) return;
              slog::join_probe<2,1>(Lfindex1241, std::array<u64,2>{v_c28, 0}, [&](const std::array<u64,2>& m1583) {
                u64 v_c39 = m1583[1];
                slog::join_probe<3,2>(Ndindex1242, std::array<u64,3>{v_c38, v_c39, 0}, [&](const std::array<u64,3>& m1584) {
                  u64 v_c40 = m1584[2];
                  slog::join_probe<3,2>(Ndindex1243, std::array<u64,3>{v_c37, v_c40, 0}, [&](const std::array<u64,3>& m1585) {
                    u64 v_c41 = m1585[2];
                    if (!slog::exists_probe<3,1>(Ndindex1244, std::array<u64,3>{v_c41, 0, 0})) return;
                    slog::join_probe<2,1>(Lfindex1245, std::array<u64,2>{v_c27, 0}, [&](const std::array<u64,2>& m1586) {
                      u64 v_c43 = m1586[1];
                      if (!slog::exists_probe<3,1>(Ndindex1246, std::array<u64,3>{v_c43, 0, 0})) return;
                      slog::join_probe<2,1>(Lfindex1247, std::array<u64,2>{v_c26, 0}, [&](const std::array<u64,2>& m1587) {
                        u64 v_c44 = m1587[1];
                        slog::join_probe<3,2>(Ndindex1248, std::array<u64,3>{v_c43, v_c44, 0}, [&](const std::array<u64,3>& m1588) {
                          u64 v_c45 = m1588[2];
                          if (!slog::exists_probe<3,1>(Ndindex1249, std::array<u64,3>{v_c45, 0, 0})) return;
                          slog::join_probe<2,1>(Lfindex1250, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m1589) {
                            u64 v_c47 = m1589[1];
                            if (!slog::exists_probe<3,1>(Ndindex1251, std::array<u64,3>{v_c47, 0, 0})) return;
                            slog::join_probe<2,1>(Lfindex1252, std::array<u64,2>{v_c24, 0}, [&](const std::array<u64,2>& m1590) {
                              u64 v_c48 = m1590[1];
                              slog::join_probe<3,2>(Ndindex1253, std::array<u64,3>{v_c47, v_c48, 0}, [&](const std::array<u64,3>& m1591) {
                                u64 v_c46 = m1591[2];
                                slog::join_probe<3,2>(Ndindex1254, std::array<u64,3>{v_c45, v_c46, 0}, [&](const std::array<u64,3>& m1592) {
                                  u64 v_c42 = m1592[2];
                                  slog::join_probe<3,2>(Ndindex1255, std::array<u64,3>{v_c41, v_c42, 0}, [&](const std::array<u64,3>& m1593) {
                                    u64 v_c34 = m1593[2];
                                    if (!slog::exists_probe<3,1>(Ndindex1256, std::array<u64,3>{v_c34, 0, 0})) return;
                                    slog::join_probe<2,1>(Lfindex1257, std::array<u64,2>{v_c23, 0}, [&](const std::array<u64,2>& m1594) {
                                      u64 v_c49 = m1594[1];
                                      if (!slog::exists_probe<3,1>(Ndindex1258, std::array<u64,3>{v_c49, 0, 0})) return;
                                      slog::join_probe<2,1>(Lfindex1259, std::array<u64,2>{v_c22, 0}, [&](const std::array<u64,2>& m1595) {
                                        u64 v_c50 = m1595[1];
                                        slog::join_probe<3,2>(Ndindex1260, std::array<u64,3>{v_c49, v_c50, 0}, [&](const std::array<u64,3>& m1596) {
                                          u64 v_c51 = m1596[2];
                                          if (!slog::exists_probe<3,1>(Ndindex1261, std::array<u64,3>{v_c51, 0, 0})) return;
                                          slog::join_probe<2,1>(Lfindex1262, std::array<u64,2>{v_c21, 0}, [&](const std::array<u64,2>& m1597) {
                                            u64 v_c52 = m1597[1];
                                            if (!slog::exists_probe<3,1>(Ndindex1263, std::array<u64,3>{v_c52, 0, 0})) return;
                                            slog::join_probe<2,1>(Lfindex1264, std::array<u64,2>{v_c20, 0}, [&](const std::array<u64,2>& m1598) {
                                              u64 v_c53 = m1598[1];
                                              slog::join_probe<3,2>(Ndindex1265, std::array<u64,3>{v_c52, v_c53, 0}, [&](const std::array<u64,3>& m1599) {
                                                u64 v_c54 = m1599[2];
                                                slog::join_probe<3,2>(Ndindex1266, std::array<u64,3>{v_c51, v_c54, 0}, [&](const std::array<u64,3>& m1600) {
                                                  u64 v_c55 = m1600[2];
                                                  if (!slog::exists_probe<3,1>(Ndindex1267, std::array<u64,3>{v_c55, 0, 0})) return;
                                                  slog::join_probe<2,1>(Lfindex1268, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m1601) {
                                                    u64 v_c57 = m1601[1];
                                                    if (!slog::exists_probe<3,1>(Ndindex1269, std::array<u64,3>{v_c57, 0, 0})) return;
                                                    slog::join_probe<2,1>(Lfindex1270, std::array<u64,2>{v_c18, 0}, [&](const std::array<u64,2>& m1602) {
                                                      u64 v_c58 = m1602[1];
                                                      slog::join_probe<3,2>(Ndindex1271, std::array<u64,3>{v_c57, v_c58, 0}, [&](const std::array<u64,3>& m1603) {
                                                        u64 v_c59 = m1603[2];
                                                        if (!slog::exists_probe<3,1>(Ndindex1272, std::array<u64,3>{v_c59, 0, 0})) return;
                                                        slog::join_probe<2,1>(Lfindex1273, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m1604) {
                                                          u64 v_c61 = m1604[1];
                                                          if (!slog::exists_probe<3,1>(Ndindex1274, std::array<u64,3>{v_c61, 0, 0})) return;
                                                          slog::join_probe<2,1>(Lfindex1275, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m1605) {
                                                            u64 v_c62 = m1605[1];
                                                            slog::join_probe<3,2>(Ndindex1276, std::array<u64,3>{v_c61, v_c62, 0}, [&](const std::array<u64,3>& m1606) {
                                                              u64 v_c60 = m1606[2];
                                                              slog::join_probe<3,2>(Ndindex1277, std::array<u64,3>{v_c59, v_c60, 0}, [&](const std::array<u64,3>& m1607) {
                                                                u64 v_c56 = m1607[2];
                                                                slog::join_probe<3,2>(Ndindex1278, std::array<u64,3>{v_c55, v_c56, 0}, [&](const std::array<u64,3>& m1608) {
                                                                  u64 v_c33 = m1608[2];
                                                                  slog::join_probe<3,2>(Ndindex1279, std::array<u64,3>{v_c34, v_c33, 0}, [&](const std::array<u64,3>& m1609) {
                                                                    u64 v_c32 = m1609[2];
                                                                    if (!slog::exists_probe<3,1>(Ndindex1280, std::array<u64,3>{v_c32, 0, 0})) return;
                                                                    slog::join_probe<2,1>(Lfindex1281, std::array<u64,2>{v_c15, 0}, [&](const std::array<u64,2>& m1610) {
                                                                      u64 v_c63 = m1610[1];
                                                                      if (!slog::exists_probe<3,1>(Ndindex1282, std::array<u64,3>{v_c63, 0, 0})) return;
                                                                      slog::join_probe<2,1>(Lfindex1283, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m1611) {
                                                                        u64 v_c64 = m1611[1];
                                                                        slog::join_probe<3,2>(Ndindex1284, std::array<u64,3>{v_c63, v_c64, 0}, [&](const std::array<u64,3>& m1612) {
                                                                          u64 v_c65 = m1612[2];
                                                                          if (!slog::exists_probe<3,1>(Ndindex1285, std::array<u64,3>{v_c65, 0, 0})) return;
                                                                          slog::join_probe<2,1>(Lfindex1286, std::array<u64,2>{v_c13, 0}, [&](const std::array<u64,2>& m1613) {
                                                                            u64 v_c66 = m1613[1];
                                                                            if (!slog::exists_probe<3,1>(Ndindex1287, std::array<u64,3>{v_c66, 0, 0})) return;
                                                                            slog::join_probe<2,1>(Lfindex1288, std::array<u64,2>{v_c12, 0}, [&](const std::array<u64,2>& m1614) {
                                                                              u64 v_c67 = m1614[1];
                                                                              slog::join_probe<3,2>(Ndindex1289, std::array<u64,3>{v_c66, v_c67, 0}, [&](const std::array<u64,3>& m1615) {
                                                                                u64 v_c68 = m1615[2];
                                                                                slog::join_probe<3,2>(Ndindex1290, std::array<u64,3>{v_c65, v_c68, 0}, [&](const std::array<u64,3>& m1616) {
                                                                                  u64 v_c69 = m1616[2];
                                                                                  if (!slog::exists_probe<3,1>(Ndindex1291, std::array<u64,3>{v_c69, 0, 0})) return;
                                                                                  slog::join_probe<2,1>(Lfindex1292, std::array<u64,2>{v_c11, 0}, [&](const std::array<u64,2>& m1617) {
                                                                                    u64 v_c70 = m1617[1];
                                                                                    if (!slog::exists_probe<3,1>(Ndindex1293, std::array<u64,3>{v_c70, 0, 0})) return;
                                                                                    slog::join_probe<2,1>(Lfindex1294, std::array<u64,2>{v_c10, 0}, [&](const std::array<u64,2>& m1618) {
                                                                                      u64 v_c71 = m1618[1];
                                                                                      slog::join_probe<3,2>(Ndindex1295, std::array<u64,3>{v_c70, v_c71, 0}, [&](const std::array<u64,3>& m1619) {
                                                                                        u64 v_c72 = m1619[2];
                                                                                        if (!slog::exists_probe<3,1>(Ndindex1296, std::array<u64,3>{v_c72, 0, 0})) return;
                                                                                        slog::join_probe<2,1>(Lfindex1297, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m1620) {
                                                                                          u64 v_c73 = m1620[1];
                                                                                          if (!slog::exists_probe<3,1>(Ndindex1298, std::array<u64,3>{v_c73, 0, 0})) return;
                                                                                          slog::join_probe<2,1>(Lfindex1299, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m1621) {
                                                                                            u64 v_c74 = m1621[1];
                                                                                            slog::join_probe<3,2>(Ndindex1300, std::array<u64,3>{v_c73, v_c74, 0}, [&](const std::array<u64,3>& m1622) {
                                                                                              u64 v_c75 = m1622[2];
                                                                                              slog::join_probe<3,2>(Ndindex1301, std::array<u64,3>{v_c72, v_c75, 0}, [&](const std::array<u64,3>& m1623) {
                                                                                                u64 v_c76 = m1623[2];
                                                                                                slog::join_probe<3,2>(Ndindex1302, std::array<u64,3>{v_c69, v_c76, 0}, [&](const std::array<u64,3>& m1624) {
                                                                                                  u64 v_c77 = m1624[2];
                                                                                                  if (!slog::exists_probe<3,1>(Ndindex1303, std::array<u64,3>{v_c77, 0, 0})) return;
                                                                                                  slog::join_probe<2,1>(Lfindex1304, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m1625) {
                                                                                                    u64 v_c78 = m1625[1];
                                                                                                    if (!slog::exists_probe<3,1>(Ndindex1305, std::array<u64,3>{v_c78, 0, 0})) return;
                                                                                                    slog::join_probe<2,1>(Lfindex1306, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m1626) {
                                                                                                      u64 v_c79 = m1626[1];
                                                                                                      slog::join_probe<3,2>(Ndindex1307, std::array<u64,3>{v_c78, v_c79, 0}, [&](const std::array<u64,3>& m1627) {
                                                                                                        u64 v_c80 = m1627[2];
                                                                                                        if (!slog::exists_probe<3,1>(Ndindex1308, std::array<u64,3>{v_c80, 0, 0})) return;
                                                                                                        slog::join_probe<2,1>(Lfindex1309, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m1628) {
                                                                                                          u64 v_c81 = m1628[1];
                                                                                                          if (!slog::exists_probe<3,1>(Ndindex1310, std::array<u64,3>{v_c81, 0, 0})) return;
                                                                                                          slog::join_probe<2,1>(Lfindex1311, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m1629) {
                                                                                                            u64 v_c82 = m1629[1];
                                                                                                            slog::join_probe<3,2>(Ndindex1312, std::array<u64,3>{v_c81, v_c82, 0}, [&](const std::array<u64,3>& m1630) {
                                                                                                              u64 v_c83 = m1630[2];
                                                                                                              slog::join_probe<3,2>(Ndindex1313, std::array<u64,3>{v_c80, v_c83, 0}, [&](const std::array<u64,3>& m1631) {
                                                                                                                u64 v_c84 = m1631[2];
                                                                                                                if (!slog::exists_probe<3,1>(Ndindex1314, std::array<u64,3>{v_c84, 0, 0})) return;
                                                                                                                slog::join_probe<2,1>(Lfindex1315, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m1632) {
                                                                                                                  u64 v_c85 = m1632[1];
                                                                                                                  if (!slog::exists_probe<3,1>(Ndindex1316, std::array<u64,3>{v_c85, 0, 0})) return;
                                                                                                                  slog::join_probe<2,1>(Lfindex1317, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m1633) {
                                                                                                                    u64 v_c86 = m1633[1];
                                                                                                                    slog::join_probe<3,2>(Ndindex1318, std::array<u64,3>{v_c85, v_c86, 0}, [&](const std::array<u64,3>& m1634) {
                                                                                                                      u64 v_c87 = m1634[2];
                                                                                                                      if (!slog::exists_probe<3,1>(Ndindex1319, std::array<u64,3>{v_c87, 0, 0})) return;
                                                                                                                      slog::join_probe<2,1>(Lfindex1320, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m1635) {
                                                                                                                        u64 v_c88 = m1635[1];
                                                                                                                        if (!slog::exists_probe<3,1>(Ndindex1321, std::array<u64,3>{v_c88, 0, 0})) return;
                                                                                                                        slog::join_probe<2,1>(Lfindex1322, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m1636) {
                                                                                                                          u64 v_c89 = m1636[1];
                                                                                                                          slog::join_probe<3,2>(Ndindex1323, std::array<u64,3>{v_c88, v_c89, 0}, [&](const std::array<u64,3>& m1637) {
                                                                                                                            u64 v_c90 = m1637[2];
                                                                                                                            slog::join_probe<3,2>(Ndindex1324, std::array<u64,3>{v_c87, v_c90, 0}, [&](const std::array<u64,3>& m1638) {
                                                                                                                              u64 v_c91 = m1638[2];
                                                                                                                              slog::join_probe<3,2>(Ndindex1325, std::array<u64,3>{v_c84, v_c91, 0}, [&](const std::array<u64,3>& m1639) {
                                                                                                                                u64 v_c92 = m1639[2];
                                                                                                                                slog::join_probe<3,2>(Ndindex1326, std::array<u64,3>{v_c77, v_c92, 0}, [&](const std::array<u64,3>& m1640) {
                                                                                                                                  u64 v_c93 = m1640[2];
                                                                                                                                  slog::join_probe<3,2>(Ndindex1327, std::array<u64,3>{v_c32, v_c93, 0}, [&](const std::array<u64,3>& m1641) {
                                                                                                                                    u64 v_c94 = m1641[2];
                                                                                                                                    ++_fires;
                                                                                                                                    slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c94}, std::array<u16,1>{0});
                                                                                                                                  });
                                                                                                                                });
                                                                                                                              });
                                                                                                                            });
                                                                                                                          });
                                                                                                                        });
                                                                                                                      });
                                                                                                                    });
                                                                                                                  });
                                                                                                                });
                                                                                                              });
                                                                                                            });
                                                                                                          });
                                                                                                        });
                                                                                                      });
                                                                                                    });
                                                                                                  });
                                                                                                });
                                                                                              });
                                                                                            });
                                                                                          });
                                                                                        });
                                                                                      });
                                                                                    });
                                                                                  });
                                                                                });
                                                                              });
                                                                            });
                                                                          });
                                                                        });
                                                                      });
                                                                    });
                                                                  });
                                                                });
                                                              });
                                                            });
                                                          });
                                                        });
                                                      });
                                                    });
                                                  });
                                                });
                                              });
                                            });
                                          });
                                        });
                                      });
                                    });
                                  });
                                });
                              });
                            });
                          });
                        });
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
  
      if (_fires) db->bumpFires("deep_fact.slog:7", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask1328(db,b));
  // (crule (pre (let __tconst48SJ108 const6b86b273ff34fce19d6b804e) (let __tconst5Uhl106 constd4735e3a265e16eee03f5971) (let __tconst9YpM103 const4e07408562bedb8b60ce05c1) (let __tconst3iHp101 const4b227777d4dd1fc61c6f884f) (let __tconst0Emh97 constef2d127de37b942baad06145) (let __tconst29xA95 conste7f6c011776e8db7cd330b54) (let __tconst9mjQ92 const7902699be42c8a8e46fbbb45) (let __tconst9Yxv90 const2c624232cdd221771294dfbb) (let __tconst7wWY85 const19581e27de7ced00ff1ce50b) (let __tconst01Wl83 const4a44dc15364204a80fe80e90) (let __tconst42lR80 const4fc82b26aecb47d2868c4efb) (let __tconst3KyY78 const6b51d431df5d7f141cbececc) (let __tconst6a9N74 const3fdba35f04dc8c462986c992) (let __tconst74Qx72 const8527a891e224136950ff32ca) (let __tconst2hOw69 conste629fa6598d732768f7c726b) (let __tconst7kHD67 constb17ef6d19c7a5b1ee83b907c) (let __tconst5zmq61 const4523540f1504cd17100c4835) (let __tconst31qC59 const4ec9599fc203d176a301536c) (let __tconst4Vop56 const9400f1b21cb527d7fa3d3eab) (let __tconst51zc54 constf5ca38f748a1d6eaf726b8a4) (let __tconst6Qm150 const6f4b6612125fb3a0daecd279) (let __tconst6bEj48 const785f3ec7eb32f30b90cd0fcf) (let __tconst7AKN45 const535fa30d7e25dd8a49f15367) (let __tconst9j2a43 constc2356069e9d1e79ca9243781) (let __tconst1Mto38 constb7a56873cd771f2c446d369b) (let __tconst8u8i36 const5f9c4ab08cac7457e9111a30) (let __tconst2Isx33 const670671cd97404156226e5079) (let __tconst8J6R31 const59e19706d51d39f66711c265) (let __tconst88cs27 const35135aaa6cc23891b40cb3f3) (let __tconst0Uuf25 const624b60c58c9d8bfb6ff1886c) (let __tconst6sf622 consteb1e33e8a81b697b75855af6) (let __tconst5Run20 conste29c9c180c6279b0b02abd6a)) (seeded) (body (join Lf (1 0) 1 __tconst5Run20 __t8mDO21) (exists Nd (2 1 0) 1 __t8mDO21) (exists Lf (1 0) 1 __tconst0Uuf25) (exists Lf (1 0) 1 __tconst88cs27) (exists Lf (1 0) 1 __tconst8J6R31) (exists Lf (1 0) 1 __tconst2Isx33) (exists Lf (1 0) 1 __tconst8u8i36) (exists Lf (1 0) 1 __tconst1Mto38) (exists Lf (1 0) 1 __tconst9j2a43) (exists Lf (1 0) 1 __tconst7AKN45) (exists Lf (1 0) 1 __tconst6bEj48) (exists Lf (1 0) 1 __tconst6Qm150) (exists Lf (1 0) 1 __tconst51zc54) (exists Lf (1 0) 1 __tconst4Vop56) (exists Lf (1 0) 1 __tconst31qC59) (exists Lf (1 0) 1 __tconst5zmq61) (exists Lf (1 0) 1 __tconst7kHD67) (exists Lf (1 0) 1 __tconst2hOw69) (exists Lf (1 0) 1 __tconst74Qx72) (exists Lf (1 0) 1 __tconst6a9N74) (exists Lf (1 0) 1 __tconst3KyY78) (exists Lf (1 0) 1 __tconst42lR80) (exists Lf (1 0) 1 __tconst01Wl83) (exists Lf (1 0) 1 __tconst7wWY85) (exists Lf (1 0) 1 __tconst9Yxv90) (exists Lf (1 0) 1 __tconst9mjQ92) (exists Lf (1 0) 1 __tconst29xA95) (exists Lf (1 0) 1 __tconst0Emh97) (exists Lf (1 0) 1 __tconst3iHp101) (exists Lf (1 0) 1 __tconst9YpM103) (exists Lf (1 0) 1 __tconst5Uhl106) (exists Lf (1 0) 1 __tconst48SJ108) (join Lf (1 0) 1 __tconst6sf622 __t1M8o23) (join Nd (2 1 0) 2 __t8mDO21 __t1M8o23 __t7LF824) (exists Nd (2 1 0) 1 __t7LF824) (join Lf (1 0) 1 __tconst0Uuf25 __t1NQv26) (exists Nd (2 1 0) 1 __t1NQv26) (join Lf (1 0) 1 __tconst88cs27 __t7d0c28) (join Nd (2 1 0) 2 __t1NQv26 __t7d0c28 __t0kIY29) (join Nd (2 1 0) 2 __t7LF824 __t0kIY29 __t6JrG30) (join Lf (1 0) 1 __tconst8J6R31 __t9vh832) (exists Nd (2 1 0) 1 __t9vh832) (join Lf (1 0) 1 __tconst2Isx33 __t5flt34) (join Nd (2 1 0) 2 __t9vh832 __t5flt34 __t3jHg35) (exists Nd (2 1 0) 1 __t3jHg35) (join Lf (1 0) 1 __tconst8u8i36 __t27Zr37) (exists Nd (2 1 0) 1 __t27Zr37) (join Lf (1 0) 1 __tconst1Mto38 __t3UFu39) (join Nd (2 1 0) 2 __t27Zr37 __t3UFu39 __t8qqV40) (join Nd (2 1 0) 2 __t3jHg35 __t8qqV40 __t2KtK41) (join Lf (1 0) 1 __tconst9j2a43 __t6IKq44) (exists Nd (2 1 0) 1 __t6IKq44) (join Lf (1 0) 1 __tconst7AKN45 __t6LIW46) (join Nd (2 1 0) 2 __t6IKq44 __t6LIW46 __t7C7d47) (exists Nd (2 1 0) 1 __t7C7d47) (join Lf (1 0) 1 __tconst6bEj48 __t9k7a49) (exists Nd (2 1 0) 1 __t9k7a49) (join Lf (1 0) 1 __tconst6Qm150 __t4MdC51) (join Nd (2 1 0) 2 __t9k7a49 __t4MdC51 __t8A9i52) (join Nd (2 1 0) 2 __t7C7d47 __t8A9i52 __t7DSY53) (join Lf (1 0) 1 __tconst51zc54 __t3Yon55) (exists Nd (2 1 0) 1 __t3Yon55) (join Lf (1 0) 1 __tconst4Vop56 __t5ik157) (join Nd (2 1 0) 2 __t3Yon55 __t5ik157 __t4hi358) (exists Nd (2 1 0) 1 __t4hi358) (join Lf (1 0) 1 __tconst31qC59 __t1nkJ60) (exists Nd (2 1 0) 1 __t1nkJ60) (join Lf (1 0) 1 __tconst5zmq61 __t4E3D62) (join Nd (2 1 0) 2 __t1nkJ60 __t4E3D62 __t8TXU63) (join Nd (2 1 0) 2 __t4hi358 __t8TXU63 __t6bZq64) (join Lf (1 0) 1 __tconst7kHD67 __t4J2N68) (exists Nd (2 1 0) 1 __t4J2N68) (join Lf (1 0) 1 __tconst2hOw69 __t4izo70) (join Nd (2 1 0) 2 __t4J2N68 __t4izo70 __t14Ff71) (exists Nd (2 1 0) 1 __t14Ff71) (join Lf (1 0) 1 __tconst74Qx72 __t319l73) (exists Nd (2 1 0) 1 __t319l73) (join Lf (1 0) 1 __tconst6a9N74 __t0amQ75) (join Nd (2 1 0) 2 __t319l73 __t0amQ75 __t4MUf76) (join Nd (2 1 0) 2 __t14Ff71 __t4MUf76 __t13Wj77) (join Lf (1 0) 1 __tconst3KyY78 __t13gt79) (exists Nd (2 1 0) 1 __t13gt79) (join Lf (1 0) 1 __tconst42lR80 __t3ESz81) (join Nd (2 1 0) 2 __t13gt79 __t3ESz81 __t3WL082) (exists Nd (2 1 0) 1 __t3WL082) (join Lf (1 0) 1 __tconst01Wl83 __t4Da384) (exists Nd (2 1 0) 1 __t4Da384) (join Lf (1 0) 1 __tconst7wWY85 __t91gs86) (join Nd (2 1 0) 2 __t4Da384 __t91gs86 __t02Bu87) (join Nd (2 1 0) 2 __t3WL082 __t02Bu87 __t60KJ88) (join Lf (1 0) 1 __tconst9Yxv90 __t7UaH91) (exists Nd (2 1 0) 1 __t7UaH91) (join Lf (1 0) 1 __tconst9mjQ92 __t6IMg93) (join Nd (2 1 0) 2 __t7UaH91 __t6IMg93 __t2T3i94) (exists Nd (2 1 0) 1 __t2T3i94) (join Lf (1 0) 1 __tconst29xA95 __t2oHE96) (exists Nd (2 1 0) 1 __t2oHE96) (join Lf (1 0) 1 __tconst0Emh97 __t7bue98) (join Nd (2 1 0) 2 __t2oHE96 __t7bue98 __t0HkS99) (join Nd (2 1 0) 2 __t2T3i94 __t0HkS99 __t7PLp100) (join Lf (1 0) 1 __tconst3iHp101 __t5yzC102) (exists Nd (2 1 0) 1 __t5yzC102) (join Lf (1 0) 1 __tconst9YpM103 __t7c21104) (join Nd (2 1 0) 2 __t5yzC102 __t7c21104 __t4bRV105) (exists Nd (2 1 0) 1 __t4bRV105) (join Lf (1 0) 1 __tconst5Uhl106 __t1IJA107) (exists Nd (2 1 0) 1 __t1IJA107) (join Lf (1 0) 1 __tconst48SJ108 __t0y5t109) (join Nd (2 1 0) 2 __t1IJA107 __t0y5t109 __t76VS110) (join Nd (2 1 0) 2 __t4bRV105 __t76VS110 __t3a3T111)) (head (mkstruct Nd (2 1 0) __t9dGZ112 __t7PLp100 __t3a3T111) (mkstruct Nd (2 1 0) __t4p4K89 __t13Wj77 __t60KJ88) (mkstruct Nd (2 1 0) __t4uRs65 __t7DSY53 __t6bZq64) (mkstruct Nd (2 1 0) __t17Jm42 __t6JrG30 __t2KtK41)) deep_fact.slog:7 #f)
  class ReadTask1752 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[4];
    slog::Index** head_index[4];
  
  
  
  
  
  
    slog::Index** Lfindex1642;  slog::Index** Ndindex1643;  slog::Index** Lfindex1644;  slog::Index** Lfindex1645;  slog::Index** Lfindex1646;  slog::Index** Lfindex1647;  slog::Index** Lfindex1648;  slog::Index** Lfindex1649;  slog::Index** Lfindex1650;  slog::Index** Lfindex1651;  slog::Index** Lfindex1652;  slog::Index** Lfindex1653;  slog::Index** Lfindex1654;  slog::Index** Lfindex1655;  slog::Index** Lfindex1656;  slog::Index** Lfindex1657;  slog::Index** Lfindex1658;  slog::Index** Lfindex1659;  slog::Index** Lfindex1660;  slog::Index** Lfindex1661;  slog::Index** Lfindex1662;  slog::Index** Lfindex1663;  slog::Index** Lfindex1664;  slog::Index** Lfindex1665;  slog::Index** Lfindex1666;  slog::Index** Lfindex1667;  slog::Index** Lfindex1668;  slog::Index** Lfindex1669;  slog::Index** Lfindex1670;  slog::Index** Lfindex1671;  slog::Index** Lfindex1672;  slog::Index** Lfindex1673;  slog::Index** Lfindex1674;  slog::Index** Ndindex1675;  slog::Index** Ndindex1676;  slog::Index** Lfindex1677;  slog::Index** Ndindex1678;  slog::Index** Lfindex1679;  slog::Index** Ndindex1680;  slog::Index** Ndindex1681;  slog::Index** Lfindex1682;  slog::Index** Ndindex1683;  slog::Index** Lfindex1684;  slog::Index** Ndindex1685;  slog::Index** Ndindex1686;  slog::Index** Lfindex1687;  slog::Index** Ndindex1688;  slog::Index** Lfindex1689;  slog::Index** Ndindex1690;  slog::Index** Ndindex1691;  slog::Index** Lfindex1692;  slog::Index** Ndindex1693;  slog::Index** Lfindex1694;  slog::Index** Ndindex1695;  slog::Index** Ndindex1696;  slog::Index** Lfindex1697;  slog::Index** Ndindex1698;  slog::Index** Lfindex1699;  slog::Index** Ndindex1700;  slog::Index** Ndindex1701;  slog::Index** Lfindex1702;  slog::Index** Ndindex1703;  slog::Index** Lfindex1704;  slog::Index** Ndindex1705;  slog::Index** Ndindex1706;  slog::Index** Lfindex1707;  slog::Index** Ndindex1708;  slog::Index** Lfindex1709;  slog::Index** Ndindex1710;  slog::Index** Ndindex1711;  slog::Index** Lfindex1712;  slog::Index** Ndindex1713;  slog::Index** Lfindex1714;  slog::Index** Ndindex1715;  slog::Index** Ndindex1716;  slog::Index** Lfindex1717;  slog::Index** Ndindex1718;  slog::Index** Lfindex1719;  slog::Index** Ndindex1720;  slog::Index** Ndindex1721;  slog::Index** Lfindex1722;  slog::Index** Ndindex1723;  slog::Index** Lfindex1724;  slog::Index** Ndindex1725;  slog::Index** Ndindex1726;  slog::Index** Lfindex1727;  slog::Index** Ndindex1728;  slog::Index** Lfindex1729;  slog::Index** Ndindex1730;  slog::Index** Ndindex1731;  slog::Index** Lfindex1732;  slog::Index** Ndindex1733;  slog::Index** Lfindex1734;  slog::Index** Ndindex1735;  slog::Index** Ndindex1736;  slog::Index** Lfindex1737;  slog::Index** Ndindex1738;  slog::Index** Lfindex1739;  slog::Index** Ndindex1740;  slog::Index** Ndindex1741;  slog::Index** Lfindex1742;  slog::Index** Ndindex1743;  slog::Index** Lfindex1744;  slog::Index** Ndindex1745;  slog::Index** Ndindex1746;  slog::Index** Lfindex1747;  slog::Index** Ndindex1748;  slog::Index** Lfindex1749;  slog::Index** Ndindex1750;  slog::Index** Ndindex1751;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("Nd");
      std::vector<u16> ord1753({2, 1, 0});
      slog::Relation* readrel1754 = db->getRelation("Nd");
      head_index[0] = readrel1754->getIndex(ord1753, false);
      head_rel[1] = db->getRelation("Nd");
      std::vector<u16> ord1755({2, 1, 0});
      slog::Relation* readrel1756 = db->getRelation("Nd");
      head_index[1] = readrel1756->getIndex(ord1755, false);
      head_rel[2] = db->getRelation("Nd");
      std::vector<u16> ord1757({2, 1, 0});
      slog::Relation* readrel1758 = db->getRelation("Nd");
      head_index[2] = readrel1758->getIndex(ord1757, false);
      head_rel[3] = db->getRelation("Nd");
      std::vector<u16> ord1759({2, 1, 0});
      slog::Relation* readrel1760 = db->getRelation("Nd");
      head_index[3] = readrel1760->getIndex(ord1759, false);
      std::vector<u16> ord1761({1, 0});
      slog::Relation* readrel1762 = db->getRelation("Lf");
      Lfindex1642 = readrel1762->getIndex(ord1761, false);
      std::vector<u16> ord1763({2, 1, 0});
      slog::Relation* readrel1764 = db->getRelation("Nd");
      Ndindex1643 = readrel1764->getIndex(ord1763, false);
      std::vector<u16> ord1765({1, 0});
      slog::Relation* readrel1766 = db->getRelation("Lf");
      Lfindex1644 = readrel1766->getIndex(ord1765, false);
      std::vector<u16> ord1767({1, 0});
      slog::Relation* readrel1768 = db->getRelation("Lf");
      Lfindex1645 = readrel1768->getIndex(ord1767, false);
      std::vector<u16> ord1769({1, 0});
      slog::Relation* readrel1770 = db->getRelation("Lf");
      Lfindex1646 = readrel1770->getIndex(ord1769, false);
      std::vector<u16> ord1771({1, 0});
      slog::Relation* readrel1772 = db->getRelation("Lf");
      Lfindex1647 = readrel1772->getIndex(ord1771, false);
      std::vector<u16> ord1773({1, 0});
      slog::Relation* readrel1774 = db->getRelation("Lf");
      Lfindex1648 = readrel1774->getIndex(ord1773, false);
      std::vector<u16> ord1775({1, 0});
      slog::Relation* readrel1776 = db->getRelation("Lf");
      Lfindex1649 = readrel1776->getIndex(ord1775, false);
      std::vector<u16> ord1777({1, 0});
      slog::Relation* readrel1778 = db->getRelation("Lf");
      Lfindex1650 = readrel1778->getIndex(ord1777, false);
      std::vector<u16> ord1779({1, 0});
      slog::Relation* readrel1780 = db->getRelation("Lf");
      Lfindex1651 = readrel1780->getIndex(ord1779, false);
      std::vector<u16> ord1781({1, 0});
      slog::Relation* readrel1782 = db->getRelation("Lf");
      Lfindex1652 = readrel1782->getIndex(ord1781, false);
      std::vector<u16> ord1783({1, 0});
      slog::Relation* readrel1784 = db->getRelation("Lf");
      Lfindex1653 = readrel1784->getIndex(ord1783, false);
      std::vector<u16> ord1785({1, 0});
      slog::Relation* readrel1786 = db->getRelation("Lf");
      Lfindex1654 = readrel1786->getIndex(ord1785, false);
      std::vector<u16> ord1787({1, 0});
      slog::Relation* readrel1788 = db->getRelation("Lf");
      Lfindex1655 = readrel1788->getIndex(ord1787, false);
      std::vector<u16> ord1789({1, 0});
      slog::Relation* readrel1790 = db->getRelation("Lf");
      Lfindex1656 = readrel1790->getIndex(ord1789, false);
      std::vector<u16> ord1791({1, 0});
      slog::Relation* readrel1792 = db->getRelation("Lf");
      Lfindex1657 = readrel1792->getIndex(ord1791, false);
      std::vector<u16> ord1793({1, 0});
      slog::Relation* readrel1794 = db->getRelation("Lf");
      Lfindex1658 = readrel1794->getIndex(ord1793, false);
      std::vector<u16> ord1795({1, 0});
      slog::Relation* readrel1796 = db->getRelation("Lf");
      Lfindex1659 = readrel1796->getIndex(ord1795, false);
      std::vector<u16> ord1797({1, 0});
      slog::Relation* readrel1798 = db->getRelation("Lf");
      Lfindex1660 = readrel1798->getIndex(ord1797, false);
      std::vector<u16> ord1799({1, 0});
      slog::Relation* readrel1800 = db->getRelation("Lf");
      Lfindex1661 = readrel1800->getIndex(ord1799, false);
      std::vector<u16> ord1801({1, 0});
      slog::Relation* readrel1802 = db->getRelation("Lf");
      Lfindex1662 = readrel1802->getIndex(ord1801, false);
      std::vector<u16> ord1803({1, 0});
      slog::Relation* readrel1804 = db->getRelation("Lf");
      Lfindex1663 = readrel1804->getIndex(ord1803, false);
      std::vector<u16> ord1805({1, 0});
      slog::Relation* readrel1806 = db->getRelation("Lf");
      Lfindex1664 = readrel1806->getIndex(ord1805, false);
      std::vector<u16> ord1807({1, 0});
      slog::Relation* readrel1808 = db->getRelation("Lf");
      Lfindex1665 = readrel1808->getIndex(ord1807, false);
      std::vector<u16> ord1809({1, 0});
      slog::Relation* readrel1810 = db->getRelation("Lf");
      Lfindex1666 = readrel1810->getIndex(ord1809, false);
      std::vector<u16> ord1811({1, 0});
      slog::Relation* readrel1812 = db->getRelation("Lf");
      Lfindex1667 = readrel1812->getIndex(ord1811, false);
      std::vector<u16> ord1813({1, 0});
      slog::Relation* readrel1814 = db->getRelation("Lf");
      Lfindex1668 = readrel1814->getIndex(ord1813, false);
      std::vector<u16> ord1815({1, 0});
      slog::Relation* readrel1816 = db->getRelation("Lf");
      Lfindex1669 = readrel1816->getIndex(ord1815, false);
      std::vector<u16> ord1817({1, 0});
      slog::Relation* readrel1818 = db->getRelation("Lf");
      Lfindex1670 = readrel1818->getIndex(ord1817, false);
      std::vector<u16> ord1819({1, 0});
      slog::Relation* readrel1820 = db->getRelation("Lf");
      Lfindex1671 = readrel1820->getIndex(ord1819, false);
      std::vector<u16> ord1821({1, 0});
      slog::Relation* readrel1822 = db->getRelation("Lf");
      Lfindex1672 = readrel1822->getIndex(ord1821, false);
      std::vector<u16> ord1823({1, 0});
      slog::Relation* readrel1824 = db->getRelation("Lf");
      Lfindex1673 = readrel1824->getIndex(ord1823, false);
      std::vector<u16> ord1825({1, 0});
      slog::Relation* readrel1826 = db->getRelation("Lf");
      Lfindex1674 = readrel1826->getIndex(ord1825, false);
      std::vector<u16> ord1827({2, 1, 0});
      slog::Relation* readrel1828 = db->getRelation("Nd");
      Ndindex1675 = readrel1828->getIndex(ord1827, false);
      std::vector<u16> ord1829({2, 1, 0});
      slog::Relation* readrel1830 = db->getRelation("Nd");
      Ndindex1676 = readrel1830->getIndex(ord1829, false);
      std::vector<u16> ord1831({1, 0});
      slog::Relation* readrel1832 = db->getRelation("Lf");
      Lfindex1677 = readrel1832->getIndex(ord1831, false);
      std::vector<u16> ord1833({2, 1, 0});
      slog::Relation* readrel1834 = db->getRelation("Nd");
      Ndindex1678 = readrel1834->getIndex(ord1833, false);
      std::vector<u16> ord1835({1, 0});
      slog::Relation* readrel1836 = db->getRelation("Lf");
      Lfindex1679 = readrel1836->getIndex(ord1835, false);
      std::vector<u16> ord1837({2, 1, 0});
      slog::Relation* readrel1838 = db->getRelation("Nd");
      Ndindex1680 = readrel1838->getIndex(ord1837, false);
      std::vector<u16> ord1839({2, 1, 0});
      slog::Relation* readrel1840 = db->getRelation("Nd");
      Ndindex1681 = readrel1840->getIndex(ord1839, false);
      std::vector<u16> ord1841({1, 0});
      slog::Relation* readrel1842 = db->getRelation("Lf");
      Lfindex1682 = readrel1842->getIndex(ord1841, false);
      std::vector<u16> ord1843({2, 1, 0});
      slog::Relation* readrel1844 = db->getRelation("Nd");
      Ndindex1683 = readrel1844->getIndex(ord1843, false);
      std::vector<u16> ord1845({1, 0});
      slog::Relation* readrel1846 = db->getRelation("Lf");
      Lfindex1684 = readrel1846->getIndex(ord1845, false);
      std::vector<u16> ord1847({2, 1, 0});
      slog::Relation* readrel1848 = db->getRelation("Nd");
      Ndindex1685 = readrel1848->getIndex(ord1847, false);
      std::vector<u16> ord1849({2, 1, 0});
      slog::Relation* readrel1850 = db->getRelation("Nd");
      Ndindex1686 = readrel1850->getIndex(ord1849, false);
      std::vector<u16> ord1851({1, 0});
      slog::Relation* readrel1852 = db->getRelation("Lf");
      Lfindex1687 = readrel1852->getIndex(ord1851, false);
      std::vector<u16> ord1853({2, 1, 0});
      slog::Relation* readrel1854 = db->getRelation("Nd");
      Ndindex1688 = readrel1854->getIndex(ord1853, false);
      std::vector<u16> ord1855({1, 0});
      slog::Relation* readrel1856 = db->getRelation("Lf");
      Lfindex1689 = readrel1856->getIndex(ord1855, false);
      std::vector<u16> ord1857({2, 1, 0});
      slog::Relation* readrel1858 = db->getRelation("Nd");
      Ndindex1690 = readrel1858->getIndex(ord1857, false);
      std::vector<u16> ord1859({2, 1, 0});
      slog::Relation* readrel1860 = db->getRelation("Nd");
      Ndindex1691 = readrel1860->getIndex(ord1859, false);
      std::vector<u16> ord1861({1, 0});
      slog::Relation* readrel1862 = db->getRelation("Lf");
      Lfindex1692 = readrel1862->getIndex(ord1861, false);
      std::vector<u16> ord1863({2, 1, 0});
      slog::Relation* readrel1864 = db->getRelation("Nd");
      Ndindex1693 = readrel1864->getIndex(ord1863, false);
      std::vector<u16> ord1865({1, 0});
      slog::Relation* readrel1866 = db->getRelation("Lf");
      Lfindex1694 = readrel1866->getIndex(ord1865, false);
      std::vector<u16> ord1867({2, 1, 0});
      slog::Relation* readrel1868 = db->getRelation("Nd");
      Ndindex1695 = readrel1868->getIndex(ord1867, false);
      std::vector<u16> ord1869({2, 1, 0});
      slog::Relation* readrel1870 = db->getRelation("Nd");
      Ndindex1696 = readrel1870->getIndex(ord1869, false);
      std::vector<u16> ord1871({1, 0});
      slog::Relation* readrel1872 = db->getRelation("Lf");
      Lfindex1697 = readrel1872->getIndex(ord1871, false);
      std::vector<u16> ord1873({2, 1, 0});
      slog::Relation* readrel1874 = db->getRelation("Nd");
      Ndindex1698 = readrel1874->getIndex(ord1873, false);
      std::vector<u16> ord1875({1, 0});
      slog::Relation* readrel1876 = db->getRelation("Lf");
      Lfindex1699 = readrel1876->getIndex(ord1875, false);
      std::vector<u16> ord1877({2, 1, 0});
      slog::Relation* readrel1878 = db->getRelation("Nd");
      Ndindex1700 = readrel1878->getIndex(ord1877, false);
      std::vector<u16> ord1879({2, 1, 0});
      slog::Relation* readrel1880 = db->getRelation("Nd");
      Ndindex1701 = readrel1880->getIndex(ord1879, false);
      std::vector<u16> ord1881({1, 0});
      slog::Relation* readrel1882 = db->getRelation("Lf");
      Lfindex1702 = readrel1882->getIndex(ord1881, false);
      std::vector<u16> ord1883({2, 1, 0});
      slog::Relation* readrel1884 = db->getRelation("Nd");
      Ndindex1703 = readrel1884->getIndex(ord1883, false);
      std::vector<u16> ord1885({1, 0});
      slog::Relation* readrel1886 = db->getRelation("Lf");
      Lfindex1704 = readrel1886->getIndex(ord1885, false);
      std::vector<u16> ord1887({2, 1, 0});
      slog::Relation* readrel1888 = db->getRelation("Nd");
      Ndindex1705 = readrel1888->getIndex(ord1887, false);
      std::vector<u16> ord1889({2, 1, 0});
      slog::Relation* readrel1890 = db->getRelation("Nd");
      Ndindex1706 = readrel1890->getIndex(ord1889, false);
      std::vector<u16> ord1891({1, 0});
      slog::Relation* readrel1892 = db->getRelation("Lf");
      Lfindex1707 = readrel1892->getIndex(ord1891, false);
      std::vector<u16> ord1893({2, 1, 0});
      slog::Relation* readrel1894 = db->getRelation("Nd");
      Ndindex1708 = readrel1894->getIndex(ord1893, false);
      std::vector<u16> ord1895({1, 0});
      slog::Relation* readrel1896 = db->getRelation("Lf");
      Lfindex1709 = readrel1896->getIndex(ord1895, false);
      std::vector<u16> ord1897({2, 1, 0});
      slog::Relation* readrel1898 = db->getRelation("Nd");
      Ndindex1710 = readrel1898->getIndex(ord1897, false);
      std::vector<u16> ord1899({2, 1, 0});
      slog::Relation* readrel1900 = db->getRelation("Nd");
      Ndindex1711 = readrel1900->getIndex(ord1899, false);
      std::vector<u16> ord1901({1, 0});
      slog::Relation* readrel1902 = db->getRelation("Lf");
      Lfindex1712 = readrel1902->getIndex(ord1901, false);
      std::vector<u16> ord1903({2, 1, 0});
      slog::Relation* readrel1904 = db->getRelation("Nd");
      Ndindex1713 = readrel1904->getIndex(ord1903, false);
      std::vector<u16> ord1905({1, 0});
      slog::Relation* readrel1906 = db->getRelation("Lf");
      Lfindex1714 = readrel1906->getIndex(ord1905, false);
      std::vector<u16> ord1907({2, 1, 0});
      slog::Relation* readrel1908 = db->getRelation("Nd");
      Ndindex1715 = readrel1908->getIndex(ord1907, false);
      std::vector<u16> ord1909({2, 1, 0});
      slog::Relation* readrel1910 = db->getRelation("Nd");
      Ndindex1716 = readrel1910->getIndex(ord1909, false);
      std::vector<u16> ord1911({1, 0});
      slog::Relation* readrel1912 = db->getRelation("Lf");
      Lfindex1717 = readrel1912->getIndex(ord1911, false);
      std::vector<u16> ord1913({2, 1, 0});
      slog::Relation* readrel1914 = db->getRelation("Nd");
      Ndindex1718 = readrel1914->getIndex(ord1913, false);
      std::vector<u16> ord1915({1, 0});
      slog::Relation* readrel1916 = db->getRelation("Lf");
      Lfindex1719 = readrel1916->getIndex(ord1915, false);
      std::vector<u16> ord1917({2, 1, 0});
      slog::Relation* readrel1918 = db->getRelation("Nd");
      Ndindex1720 = readrel1918->getIndex(ord1917, false);
      std::vector<u16> ord1919({2, 1, 0});
      slog::Relation* readrel1920 = db->getRelation("Nd");
      Ndindex1721 = readrel1920->getIndex(ord1919, false);
      std::vector<u16> ord1921({1, 0});
      slog::Relation* readrel1922 = db->getRelation("Lf");
      Lfindex1722 = readrel1922->getIndex(ord1921, false);
      std::vector<u16> ord1923({2, 1, 0});
      slog::Relation* readrel1924 = db->getRelation("Nd");
      Ndindex1723 = readrel1924->getIndex(ord1923, false);
      std::vector<u16> ord1925({1, 0});
      slog::Relation* readrel1926 = db->getRelation("Lf");
      Lfindex1724 = readrel1926->getIndex(ord1925, false);
      std::vector<u16> ord1927({2, 1, 0});
      slog::Relation* readrel1928 = db->getRelation("Nd");
      Ndindex1725 = readrel1928->getIndex(ord1927, false);
      std::vector<u16> ord1929({2, 1, 0});
      slog::Relation* readrel1930 = db->getRelation("Nd");
      Ndindex1726 = readrel1930->getIndex(ord1929, false);
      std::vector<u16> ord1931({1, 0});
      slog::Relation* readrel1932 = db->getRelation("Lf");
      Lfindex1727 = readrel1932->getIndex(ord1931, false);
      std::vector<u16> ord1933({2, 1, 0});
      slog::Relation* readrel1934 = db->getRelation("Nd");
      Ndindex1728 = readrel1934->getIndex(ord1933, false);
      std::vector<u16> ord1935({1, 0});
      slog::Relation* readrel1936 = db->getRelation("Lf");
      Lfindex1729 = readrel1936->getIndex(ord1935, false);
      std::vector<u16> ord1937({2, 1, 0});
      slog::Relation* readrel1938 = db->getRelation("Nd");
      Ndindex1730 = readrel1938->getIndex(ord1937, false);
      std::vector<u16> ord1939({2, 1, 0});
      slog::Relation* readrel1940 = db->getRelation("Nd");
      Ndindex1731 = readrel1940->getIndex(ord1939, false);
      std::vector<u16> ord1941({1, 0});
      slog::Relation* readrel1942 = db->getRelation("Lf");
      Lfindex1732 = readrel1942->getIndex(ord1941, false);
      std::vector<u16> ord1943({2, 1, 0});
      slog::Relation* readrel1944 = db->getRelation("Nd");
      Ndindex1733 = readrel1944->getIndex(ord1943, false);
      std::vector<u16> ord1945({1, 0});
      slog::Relation* readrel1946 = db->getRelation("Lf");
      Lfindex1734 = readrel1946->getIndex(ord1945, false);
      std::vector<u16> ord1947({2, 1, 0});
      slog::Relation* readrel1948 = db->getRelation("Nd");
      Ndindex1735 = readrel1948->getIndex(ord1947, false);
      std::vector<u16> ord1949({2, 1, 0});
      slog::Relation* readrel1950 = db->getRelation("Nd");
      Ndindex1736 = readrel1950->getIndex(ord1949, false);
      std::vector<u16> ord1951({1, 0});
      slog::Relation* readrel1952 = db->getRelation("Lf");
      Lfindex1737 = readrel1952->getIndex(ord1951, false);
      std::vector<u16> ord1953({2, 1, 0});
      slog::Relation* readrel1954 = db->getRelation("Nd");
      Ndindex1738 = readrel1954->getIndex(ord1953, false);
      std::vector<u16> ord1955({1, 0});
      slog::Relation* readrel1956 = db->getRelation("Lf");
      Lfindex1739 = readrel1956->getIndex(ord1955, false);
      std::vector<u16> ord1957({2, 1, 0});
      slog::Relation* readrel1958 = db->getRelation("Nd");
      Ndindex1740 = readrel1958->getIndex(ord1957, false);
      std::vector<u16> ord1959({2, 1, 0});
      slog::Relation* readrel1960 = db->getRelation("Nd");
      Ndindex1741 = readrel1960->getIndex(ord1959, false);
      std::vector<u16> ord1961({1, 0});
      slog::Relation* readrel1962 = db->getRelation("Lf");
      Lfindex1742 = readrel1962->getIndex(ord1961, false);
      std::vector<u16> ord1963({2, 1, 0});
      slog::Relation* readrel1964 = db->getRelation("Nd");
      Ndindex1743 = readrel1964->getIndex(ord1963, false);
      std::vector<u16> ord1965({1, 0});
      slog::Relation* readrel1966 = db->getRelation("Lf");
      Lfindex1744 = readrel1966->getIndex(ord1965, false);
      std::vector<u16> ord1967({2, 1, 0});
      slog::Relation* readrel1968 = db->getRelation("Nd");
      Ndindex1745 = readrel1968->getIndex(ord1967, false);
      std::vector<u16> ord1969({2, 1, 0});
      slog::Relation* readrel1970 = db->getRelation("Nd");
      Ndindex1746 = readrel1970->getIndex(ord1969, false);
      std::vector<u16> ord1971({1, 0});
      slog::Relation* readrel1972 = db->getRelation("Lf");
      Lfindex1747 = readrel1972->getIndex(ord1971, false);
      std::vector<u16> ord1973({2, 1, 0});
      slog::Relation* readrel1974 = db->getRelation("Nd");
      Ndindex1748 = readrel1974->getIndex(ord1973, false);
      std::vector<u16> ord1975({1, 0});
      slog::Relation* readrel1976 = db->getRelation("Lf");
      Lfindex1749 = readrel1976->getIndex(ord1975, false);
      std::vector<u16> ord1977({2, 1, 0});
      slog::Relation* readrel1978 = db->getRelation("Nd");
      Ndindex1750 = readrel1978->getIndex(ord1977, false);
      std::vector<u16> ord1979({2, 1, 0});
      slog::Relation* readrel1980 = db->getRelation("Nd");
      Ndindex1751 = readrel1980->getIndex(ord1979, false);
  
    }
    ReadTask1752(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[4];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(Lfindex1642, std::array<u64,2>{v_c31, 0}, [&](const std::array<u64,2>& m1981) {
        u64 v_c35 = m1981[1];
        if (!slog::exists_probe<3,1>(Ndindex1643, std::array<u64,3>{v_c35, 0, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1644, std::array<u64,2>{v_c29, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1645, std::array<u64,2>{v_c28, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1646, std::array<u64,2>{v_c27, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1647, std::array<u64,2>{v_c26, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1648, std::array<u64,2>{v_c25, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1649, std::array<u64,2>{v_c24, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1650, std::array<u64,2>{v_c23, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1651, std::array<u64,2>{v_c22, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1652, std::array<u64,2>{v_c21, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1653, std::array<u64,2>{v_c20, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1654, std::array<u64,2>{v_c19, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1655, std::array<u64,2>{v_c18, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1656, std::array<u64,2>{v_c17, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1657, std::array<u64,2>{v_c16, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1658, std::array<u64,2>{v_c15, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1659, std::array<u64,2>{v_c14, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1660, std::array<u64,2>{v_c13, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1661, std::array<u64,2>{v_c12, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1662, std::array<u64,2>{v_c11, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1663, std::array<u64,2>{v_c10, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1664, std::array<u64,2>{v_c9, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1665, std::array<u64,2>{v_c8, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1666, std::array<u64,2>{v_c7, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1667, std::array<u64,2>{v_c6, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1668, std::array<u64,2>{v_c5, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1669, std::array<u64,2>{v_c4, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1670, std::array<u64,2>{v_c3, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1671, std::array<u64,2>{v_c2, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1672, std::array<u64,2>{v_c1, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex1673, std::array<u64,2>{v_c0, 0})) return;
        slog::join_probe<2,1>(Lfindex1674, std::array<u64,2>{v_c30, 0}, [&](const std::array<u64,2>& m1982) {
          u64 v_c36 = m1982[1];
          slog::join_probe<3,2>(Ndindex1675, std::array<u64,3>{v_c35, v_c36, 0}, [&](const std::array<u64,3>& m1983) {
            u64 v_c37 = m1983[2];
            if (!slog::exists_probe<3,1>(Ndindex1676, std::array<u64,3>{v_c37, 0, 0})) return;
            slog::join_probe<2,1>(Lfindex1677, std::array<u64,2>{v_c29, 0}, [&](const std::array<u64,2>& m1984) {
              u64 v_c38 = m1984[1];
              if (!slog::exists_probe<3,1>(Ndindex1678, std::array<u64,3>{v_c38, 0, 0})) return;
              slog::join_probe<2,1>(Lfindex1679, std::array<u64,2>{v_c28, 0}, [&](const std::array<u64,2>& m1985) {
                u64 v_c39 = m1985[1];
                slog::join_probe<3,2>(Ndindex1680, std::array<u64,3>{v_c38, v_c39, 0}, [&](const std::array<u64,3>& m1986) {
                  u64 v_c40 = m1986[2];
                  slog::join_probe<3,2>(Ndindex1681, std::array<u64,3>{v_c37, v_c40, 0}, [&](const std::array<u64,3>& m1987) {
                    u64 v_c41 = m1987[2];
                    slog::join_probe<2,1>(Lfindex1682, std::array<u64,2>{v_c27, 0}, [&](const std::array<u64,2>& m1988) {
                      u64 v_c43 = m1988[1];
                      if (!slog::exists_probe<3,1>(Ndindex1683, std::array<u64,3>{v_c43, 0, 0})) return;
                      slog::join_probe<2,1>(Lfindex1684, std::array<u64,2>{v_c26, 0}, [&](const std::array<u64,2>& m1989) {
                        u64 v_c44 = m1989[1];
                        slog::join_probe<3,2>(Ndindex1685, std::array<u64,3>{v_c43, v_c44, 0}, [&](const std::array<u64,3>& m1990) {
                          u64 v_c45 = m1990[2];
                          if (!slog::exists_probe<3,1>(Ndindex1686, std::array<u64,3>{v_c45, 0, 0})) return;
                          slog::join_probe<2,1>(Lfindex1687, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m1991) {
                            u64 v_c47 = m1991[1];
                            if (!slog::exists_probe<3,1>(Ndindex1688, std::array<u64,3>{v_c47, 0, 0})) return;
                            slog::join_probe<2,1>(Lfindex1689, std::array<u64,2>{v_c24, 0}, [&](const std::array<u64,2>& m1992) {
                              u64 v_c48 = m1992[1];
                              slog::join_probe<3,2>(Ndindex1690, std::array<u64,3>{v_c47, v_c48, 0}, [&](const std::array<u64,3>& m1993) {
                                u64 v_c46 = m1993[2];
                                slog::join_probe<3,2>(Ndindex1691, std::array<u64,3>{v_c45, v_c46, 0}, [&](const std::array<u64,3>& m1994) {
                                  u64 v_c42 = m1994[2];
                                  slog::join_probe<2,1>(Lfindex1692, std::array<u64,2>{v_c23, 0}, [&](const std::array<u64,2>& m1995) {
                                    u64 v_c49 = m1995[1];
                                    if (!slog::exists_probe<3,1>(Ndindex1693, std::array<u64,3>{v_c49, 0, 0})) return;
                                    slog::join_probe<2,1>(Lfindex1694, std::array<u64,2>{v_c22, 0}, [&](const std::array<u64,2>& m1996) {
                                      u64 v_c50 = m1996[1];
                                      slog::join_probe<3,2>(Ndindex1695, std::array<u64,3>{v_c49, v_c50, 0}, [&](const std::array<u64,3>& m1997) {
                                        u64 v_c51 = m1997[2];
                                        if (!slog::exists_probe<3,1>(Ndindex1696, std::array<u64,3>{v_c51, 0, 0})) return;
                                        slog::join_probe<2,1>(Lfindex1697, std::array<u64,2>{v_c21, 0}, [&](const std::array<u64,2>& m1998) {
                                          u64 v_c52 = m1998[1];
                                          if (!slog::exists_probe<3,1>(Ndindex1698, std::array<u64,3>{v_c52, 0, 0})) return;
                                          slog::join_probe<2,1>(Lfindex1699, std::array<u64,2>{v_c20, 0}, [&](const std::array<u64,2>& m1999) {
                                            u64 v_c53 = m1999[1];
                                            slog::join_probe<3,2>(Ndindex1700, std::array<u64,3>{v_c52, v_c53, 0}, [&](const std::array<u64,3>& m2000) {
                                              u64 v_c54 = m2000[2];
                                              slog::join_probe<3,2>(Ndindex1701, std::array<u64,3>{v_c51, v_c54, 0}, [&](const std::array<u64,3>& m2001) {
                                                u64 v_c55 = m2001[2];
                                                slog::join_probe<2,1>(Lfindex1702, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m2002) {
                                                  u64 v_c57 = m2002[1];
                                                  if (!slog::exists_probe<3,1>(Ndindex1703, std::array<u64,3>{v_c57, 0, 0})) return;
                                                  slog::join_probe<2,1>(Lfindex1704, std::array<u64,2>{v_c18, 0}, [&](const std::array<u64,2>& m2003) {
                                                    u64 v_c58 = m2003[1];
                                                    slog::join_probe<3,2>(Ndindex1705, std::array<u64,3>{v_c57, v_c58, 0}, [&](const std::array<u64,3>& m2004) {
                                                      u64 v_c59 = m2004[2];
                                                      if (!slog::exists_probe<3,1>(Ndindex1706, std::array<u64,3>{v_c59, 0, 0})) return;
                                                      slog::join_probe<2,1>(Lfindex1707, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m2005) {
                                                        u64 v_c61 = m2005[1];
                                                        if (!slog::exists_probe<3,1>(Ndindex1708, std::array<u64,3>{v_c61, 0, 0})) return;
                                                        slog::join_probe<2,1>(Lfindex1709, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m2006) {
                                                          u64 v_c62 = m2006[1];
                                                          slog::join_probe<3,2>(Ndindex1710, std::array<u64,3>{v_c61, v_c62, 0}, [&](const std::array<u64,3>& m2007) {
                                                            u64 v_c60 = m2007[2];
                                                            slog::join_probe<3,2>(Ndindex1711, std::array<u64,3>{v_c59, v_c60, 0}, [&](const std::array<u64,3>& m2008) {
                                                              u64 v_c56 = m2008[2];
                                                              slog::join_probe<2,1>(Lfindex1712, std::array<u64,2>{v_c15, 0}, [&](const std::array<u64,2>& m2009) {
                                                                u64 v_c63 = m2009[1];
                                                                if (!slog::exists_probe<3,1>(Ndindex1713, std::array<u64,3>{v_c63, 0, 0})) return;
                                                                slog::join_probe<2,1>(Lfindex1714, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m2010) {
                                                                  u64 v_c64 = m2010[1];
                                                                  slog::join_probe<3,2>(Ndindex1715, std::array<u64,3>{v_c63, v_c64, 0}, [&](const std::array<u64,3>& m2011) {
                                                                    u64 v_c65 = m2011[2];
                                                                    if (!slog::exists_probe<3,1>(Ndindex1716, std::array<u64,3>{v_c65, 0, 0})) return;
                                                                    slog::join_probe<2,1>(Lfindex1717, std::array<u64,2>{v_c13, 0}, [&](const std::array<u64,2>& m2012) {
                                                                      u64 v_c66 = m2012[1];
                                                                      if (!slog::exists_probe<3,1>(Ndindex1718, std::array<u64,3>{v_c66, 0, 0})) return;
                                                                      slog::join_probe<2,1>(Lfindex1719, std::array<u64,2>{v_c12, 0}, [&](const std::array<u64,2>& m2013) {
                                                                        u64 v_c67 = m2013[1];
                                                                        slog::join_probe<3,2>(Ndindex1720, std::array<u64,3>{v_c66, v_c67, 0}, [&](const std::array<u64,3>& m2014) {
                                                                          u64 v_c68 = m2014[2];
                                                                          slog::join_probe<3,2>(Ndindex1721, std::array<u64,3>{v_c65, v_c68, 0}, [&](const std::array<u64,3>& m2015) {
                                                                            u64 v_c69 = m2015[2];
                                                                            slog::join_probe<2,1>(Lfindex1722, std::array<u64,2>{v_c11, 0}, [&](const std::array<u64,2>& m2016) {
                                                                              u64 v_c70 = m2016[1];
                                                                              if (!slog::exists_probe<3,1>(Ndindex1723, std::array<u64,3>{v_c70, 0, 0})) return;
                                                                              slog::join_probe<2,1>(Lfindex1724, std::array<u64,2>{v_c10, 0}, [&](const std::array<u64,2>& m2017) {
                                                                                u64 v_c71 = m2017[1];
                                                                                slog::join_probe<3,2>(Ndindex1725, std::array<u64,3>{v_c70, v_c71, 0}, [&](const std::array<u64,3>& m2018) {
                                                                                  u64 v_c72 = m2018[2];
                                                                                  if (!slog::exists_probe<3,1>(Ndindex1726, std::array<u64,3>{v_c72, 0, 0})) return;
                                                                                  slog::join_probe<2,1>(Lfindex1727, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m2019) {
                                                                                    u64 v_c73 = m2019[1];
                                                                                    if (!slog::exists_probe<3,1>(Ndindex1728, std::array<u64,3>{v_c73, 0, 0})) return;
                                                                                    slog::join_probe<2,1>(Lfindex1729, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m2020) {
                                                                                      u64 v_c74 = m2020[1];
                                                                                      slog::join_probe<3,2>(Ndindex1730, std::array<u64,3>{v_c73, v_c74, 0}, [&](const std::array<u64,3>& m2021) {
                                                                                        u64 v_c75 = m2021[2];
                                                                                        slog::join_probe<3,2>(Ndindex1731, std::array<u64,3>{v_c72, v_c75, 0}, [&](const std::array<u64,3>& m2022) {
                                                                                          u64 v_c76 = m2022[2];
                                                                                          slog::join_probe<2,1>(Lfindex1732, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m2023) {
                                                                                            u64 v_c78 = m2023[1];
                                                                                            if (!slog::exists_probe<3,1>(Ndindex1733, std::array<u64,3>{v_c78, 0, 0})) return;
                                                                                            slog::join_probe<2,1>(Lfindex1734, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m2024) {
                                                                                              u64 v_c79 = m2024[1];
                                                                                              slog::join_probe<3,2>(Ndindex1735, std::array<u64,3>{v_c78, v_c79, 0}, [&](const std::array<u64,3>& m2025) {
                                                                                                u64 v_c80 = m2025[2];
                                                                                                if (!slog::exists_probe<3,1>(Ndindex1736, std::array<u64,3>{v_c80, 0, 0})) return;
                                                                                                slog::join_probe<2,1>(Lfindex1737, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m2026) {
                                                                                                  u64 v_c81 = m2026[1];
                                                                                                  if (!slog::exists_probe<3,1>(Ndindex1738, std::array<u64,3>{v_c81, 0, 0})) return;
                                                                                                  slog::join_probe<2,1>(Lfindex1739, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m2027) {
                                                                                                    u64 v_c82 = m2027[1];
                                                                                                    slog::join_probe<3,2>(Ndindex1740, std::array<u64,3>{v_c81, v_c82, 0}, [&](const std::array<u64,3>& m2028) {
                                                                                                      u64 v_c83 = m2028[2];
                                                                                                      slog::join_probe<3,2>(Ndindex1741, std::array<u64,3>{v_c80, v_c83, 0}, [&](const std::array<u64,3>& m2029) {
                                                                                                        u64 v_c84 = m2029[2];
                                                                                                        slog::join_probe<2,1>(Lfindex1742, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m2030) {
                                                                                                          u64 v_c85 = m2030[1];
                                                                                                          if (!slog::exists_probe<3,1>(Ndindex1743, std::array<u64,3>{v_c85, 0, 0})) return;
                                                                                                          slog::join_probe<2,1>(Lfindex1744, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m2031) {
                                                                                                            u64 v_c86 = m2031[1];
                                                                                                            slog::join_probe<3,2>(Ndindex1745, std::array<u64,3>{v_c85, v_c86, 0}, [&](const std::array<u64,3>& m2032) {
                                                                                                              u64 v_c87 = m2032[2];
                                                                                                              if (!slog::exists_probe<3,1>(Ndindex1746, std::array<u64,3>{v_c87, 0, 0})) return;
                                                                                                              slog::join_probe<2,1>(Lfindex1747, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m2033) {
                                                                                                                u64 v_c88 = m2033[1];
                                                                                                                if (!slog::exists_probe<3,1>(Ndindex1748, std::array<u64,3>{v_c88, 0, 0})) return;
                                                                                                                slog::join_probe<2,1>(Lfindex1749, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m2034) {
                                                                                                                  u64 v_c89 = m2034[1];
                                                                                                                  slog::join_probe<3,2>(Ndindex1750, std::array<u64,3>{v_c88, v_c89, 0}, [&](const std::array<u64,3>& m2035) {
                                                                                                                    u64 v_c90 = m2035[2];
                                                                                                                    slog::join_probe<3,2>(Ndindex1751, std::array<u64,3>{v_c87, v_c90, 0}, [&](const std::array<u64,3>& m2036) {
                                                                                                                      u64 v_c91 = m2036[2];
                                                                                                                      ++_fires;
                                                                                                                      slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c84, v_c91}, std::array<u16,3>{2, 1, 0});
                                                                                                                      slog::emit_struct_checked<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c69, v_c76}, std::array<u16,3>{2, 1, 0});
                                                                                                                      slog::emit_struct_checked<3>(head_rel[2], head_index[2], newbatch[2], std::array<u64,2>{v_c55, v_c56}, std::array<u16,3>{2, 1, 0});
                                                                                                                      slog::emit_struct_checked<3>(head_rel[3], head_index[3], newbatch[3], std::array<u64,2>{v_c41, v_c42}, std::array<u16,3>{2, 1, 0});
                                                                                                                    });
                                                                                                                  });
                                                                                                                });
                                                                                                              });
                                                                                                            });
                                                                                                          });
                                                                                                        });
                                                                                                      });
                                                                                                    });
                                                                                                  });
                                                                                                });
                                                                                              });
                                                                                            });
                                                                                          });
                                                                                        });
                                                                                      });
                                                                                    });
                                                                                  });
                                                                                });
                                                                              });
                                                                            });
                                                                          });
                                                                        });
                                                                      });
                                                                    });
                                                                  });
                                                                });
                                                              });
                                                            });
                                                          });
                                                        });
                                                      });
                                                    });
                                                  });
                                                });
                                              });
                                            });
                                          });
                                        });
                                      });
                                    });
                                  });
                                });
                              });
                            });
                          });
                        });
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
  
      if (_fires) db->bumpFires("deep_fact.slog:7", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask1752(db,b));
  // (crule (pre (let __tconst48SJ108 const6b86b273ff34fce19d6b804e) (let __tconst5Uhl106 constd4735e3a265e16eee03f5971) (let __tconst9YpM103 const4e07408562bedb8b60ce05c1) (let __tconst3iHp101 const4b227777d4dd1fc61c6f884f) (let __tconst0Emh97 constef2d127de37b942baad06145) (let __tconst29xA95 conste7f6c011776e8db7cd330b54) (let __tconst9mjQ92 const7902699be42c8a8e46fbbb45) (let __tconst9Yxv90 const2c624232cdd221771294dfbb) (let __tconst7wWY85 const19581e27de7ced00ff1ce50b) (let __tconst01Wl83 const4a44dc15364204a80fe80e90) (let __tconst42lR80 const4fc82b26aecb47d2868c4efb) (let __tconst3KyY78 const6b51d431df5d7f141cbececc) (let __tconst6a9N74 const3fdba35f04dc8c462986c992) (let __tconst74Qx72 const8527a891e224136950ff32ca) (let __tconst2hOw69 conste629fa6598d732768f7c726b) (let __tconst7kHD67 constb17ef6d19c7a5b1ee83b907c) (let __tconst5zmq61 const4523540f1504cd17100c4835) (let __tconst31qC59 const4ec9599fc203d176a301536c) (let __tconst4Vop56 const9400f1b21cb527d7fa3d3eab) (let __tconst51zc54 constf5ca38f748a1d6eaf726b8a4) (let __tconst6Qm150 const6f4b6612125fb3a0daecd279) (let __tconst6bEj48 const785f3ec7eb32f30b90cd0fcf) (let __tconst7AKN45 const535fa30d7e25dd8a49f15367) (let __tconst9j2a43 constc2356069e9d1e79ca9243781) (let __tconst1Mto38 constb7a56873cd771f2c446d369b) (let __tconst8u8i36 const5f9c4ab08cac7457e9111a30) (let __tconst2Isx33 const670671cd97404156226e5079) (let __tconst8J6R31 const59e19706d51d39f66711c265) (let __tconst88cs27 const35135aaa6cc23891b40cb3f3) (let __tconst0Uuf25 const624b60c58c9d8bfb6ff1886c) (let __tconst6sf622 consteb1e33e8a81b697b75855af6) (let __tconst5Run20 conste29c9c180c6279b0b02abd6a)) (seeded) (body (join Lf (1 0) 1 __tconst5Run20 __t8mDO21) (exists Nd (2 1 0) 1 __t8mDO21) (exists Lf (1 0) 1 __tconst0Uuf25) (exists Lf (1 0) 1 __tconst88cs27) (exists Lf (1 0) 1 __tconst8J6R31) (exists Lf (1 0) 1 __tconst2Isx33) (exists Lf (1 0) 1 __tconst8u8i36) (exists Lf (1 0) 1 __tconst1Mto38) (exists Lf (1 0) 1 __tconst9j2a43) (exists Lf (1 0) 1 __tconst7AKN45) (exists Lf (1 0) 1 __tconst6bEj48) (exists Lf (1 0) 1 __tconst6Qm150) (exists Lf (1 0) 1 __tconst51zc54) (exists Lf (1 0) 1 __tconst4Vop56) (exists Lf (1 0) 1 __tconst31qC59) (exists Lf (1 0) 1 __tconst5zmq61) (exists Lf (1 0) 1 __tconst7kHD67) (exists Lf (1 0) 1 __tconst2hOw69) (exists Lf (1 0) 1 __tconst74Qx72) (exists Lf (1 0) 1 __tconst6a9N74) (exists Lf (1 0) 1 __tconst3KyY78) (exists Lf (1 0) 1 __tconst42lR80) (exists Lf (1 0) 1 __tconst01Wl83) (exists Lf (1 0) 1 __tconst7wWY85) (exists Lf (1 0) 1 __tconst9Yxv90) (exists Lf (1 0) 1 __tconst9mjQ92) (exists Lf (1 0) 1 __tconst29xA95) (exists Lf (1 0) 1 __tconst0Emh97) (exists Lf (1 0) 1 __tconst3iHp101) (exists Lf (1 0) 1 __tconst9YpM103) (exists Lf (1 0) 1 __tconst5Uhl106) (exists Lf (1 0) 1 __tconst48SJ108) (join Lf (1 0) 1 __tconst6sf622 __t1M8o23) (join Nd (2 1 0) 2 __t8mDO21 __t1M8o23 __t7LF824) (exists Nd (2 1 0) 1 __t7LF824) (join Lf (1 0) 1 __tconst0Uuf25 __t1NQv26) (exists Nd (2 1 0) 1 __t1NQv26) (join Lf (1 0) 1 __tconst88cs27 __t7d0c28) (join Nd (2 1 0) 2 __t1NQv26 __t7d0c28 __t0kIY29) (join Nd (2 1 0) 2 __t7LF824 __t0kIY29 __t6JrG30) (exists Nd (2 1 0) 1 __t6JrG30) (join Lf (1 0) 1 __tconst8J6R31 __t9vh832) (exists Nd (2 1 0) 1 __t9vh832) (join Lf (1 0) 1 __tconst2Isx33 __t5flt34) (join Nd (2 1 0) 2 __t9vh832 __t5flt34 __t3jHg35) (exists Nd (2 1 0) 1 __t3jHg35) (join Lf (1 0) 1 __tconst8u8i36 __t27Zr37) (exists Nd (2 1 0) 1 __t27Zr37) (join Lf (1 0) 1 __tconst1Mto38 __t3UFu39) (join Nd (2 1 0) 2 __t27Zr37 __t3UFu39 __t8qqV40) (join Nd (2 1 0) 2 __t3jHg35 __t8qqV40 __t2KtK41) (join Nd (2 1 0) 2 __t6JrG30 __t2KtK41 __t17Jm42) (exists Nd (2 1 0) 1 __t17Jm42) (join Lf (1 0) 1 __tconst9j2a43 __t6IKq44) (exists Nd (2 1 0) 1 __t6IKq44) (join Lf (1 0) 1 __tconst7AKN45 __t6LIW46) (join Nd (2 1 0) 2 __t6IKq44 __t6LIW46 __t7C7d47) (exists Nd (2 1 0) 1 __t7C7d47) (join Lf (1 0) 1 __tconst6bEj48 __t9k7a49) (exists Nd (2 1 0) 1 __t9k7a49) (join Lf (1 0) 1 __tconst6Qm150 __t4MdC51) (join Nd (2 1 0) 2 __t9k7a49 __t4MdC51 __t8A9i52) (join Nd (2 1 0) 2 __t7C7d47 __t8A9i52 __t7DSY53) (exists Nd (2 1 0) 1 __t7DSY53) (join Lf (1 0) 1 __tconst51zc54 __t3Yon55) (exists Nd (2 1 0) 1 __t3Yon55) (join Lf (1 0) 1 __tconst4Vop56 __t5ik157) (join Nd (2 1 0) 2 __t3Yon55 __t5ik157 __t4hi358) (exists Nd (2 1 0) 1 __t4hi358) (join Lf (1 0) 1 __tconst31qC59 __t1nkJ60) (exists Nd (2 1 0) 1 __t1nkJ60) (join Lf (1 0) 1 __tconst5zmq61 __t4E3D62) (join Nd (2 1 0) 2 __t1nkJ60 __t4E3D62 __t8TXU63) (join Nd (2 1 0) 2 __t4hi358 __t8TXU63 __t6bZq64) (join Nd (2 1 0) 2 __t7DSY53 __t6bZq64 __t4uRs65) (join Nd (2 1 0) 2 __t17Jm42 __t4uRs65 __t4LVF66) (join Lf (1 0) 1 __tconst7kHD67 __t4J2N68) (exists Nd (2 1 0) 1 __t4J2N68) (join Lf (1 0) 1 __tconst2hOw69 __t4izo70) (join Nd (2 1 0) 2 __t4J2N68 __t4izo70 __t14Ff71) (exists Nd (2 1 0) 1 __t14Ff71) (join Lf (1 0) 1 __tconst74Qx72 __t319l73) (exists Nd (2 1 0) 1 __t319l73) (join Lf (1 0) 1 __tconst6a9N74 __t0amQ75) (join Nd (2 1 0) 2 __t319l73 __t0amQ75 __t4MUf76) (join Nd (2 1 0) 2 __t14Ff71 __t4MUf76 __t13Wj77) (exists Nd (2 1 0) 1 __t13Wj77) (join Lf (1 0) 1 __tconst3KyY78 __t13gt79) (exists Nd (2 1 0) 1 __t13gt79) (join Lf (1 0) 1 __tconst42lR80 __t3ESz81) (join Nd (2 1 0) 2 __t13gt79 __t3ESz81 __t3WL082) (exists Nd (2 1 0) 1 __t3WL082) (join Lf (1 0) 1 __tconst01Wl83 __t4Da384) (exists Nd (2 1 0) 1 __t4Da384) (join Lf (1 0) 1 __tconst7wWY85 __t91gs86) (join Nd (2 1 0) 2 __t4Da384 __t91gs86 __t02Bu87) (join Nd (2 1 0) 2 __t3WL082 __t02Bu87 __t60KJ88) (join Nd (2 1 0) 2 __t13Wj77 __t60KJ88 __t4p4K89) (exists Nd (2 1 0) 1 __t4p4K89) (join Lf (1 0) 1 __tconst9Yxv90 __t7UaH91) (exists Nd (2 1 0) 1 __t7UaH91) (join Lf (1 0) 1 __tconst9mjQ92 __t6IMg93) (join Nd (2 1 0) 2 __t7UaH91 __t6IMg93 __t2T3i94) (exists Nd (2 1 0) 1 __t2T3i94) (join Lf (1 0) 1 __tconst29xA95 __t2oHE96) (exists Nd (2 1 0) 1 __t2oHE96) (join Lf (1 0) 1 __tconst0Emh97 __t7bue98) (join Nd (2 1 0) 2 __t2oHE96 __t7bue98 __t0HkS99) (join Nd (2 1 0) 2 __t2T3i94 __t0HkS99 __t7PLp100) (exists Nd (2 1 0) 1 __t7PLp100) (join Lf (1 0) 1 __tconst3iHp101 __t5yzC102) (exists Nd (2 1 0) 1 __t5yzC102) (join Lf (1 0) 1 __tconst9YpM103 __t7c21104) (join Nd (2 1 0) 2 __t5yzC102 __t7c21104 __t4bRV105) (exists Nd (2 1 0) 1 __t4bRV105) (join Lf (1 0) 1 __tconst5Uhl106 __t1IJA107) (exists Nd (2 1 0) 1 __t1IJA107) (join Lf (1 0) 1 __tconst48SJ108 __t0y5t109) (join Nd (2 1 0) 2 __t1IJA107 __t0y5t109 __t76VS110) (join Nd (2 1 0) 2 __t4bRV105 __t76VS110 __t3a3T111) (join Nd (2 1 0) 2 __t7PLp100 __t3a3T111 __t9dGZ112) (join Nd (2 1 0) 2 __t4p4K89 __t9dGZ112 __t09Ym113)) (head (mkstruct Nd (2 1 0) __t1U6n114 __t4LVF66 __t09Ym113)) deep_fact.slog:7 #f)
  class ReadTask2159 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** Lfindex2037;  slog::Index** Ndindex2038;  slog::Index** Lfindex2039;  slog::Index** Lfindex2040;  slog::Index** Lfindex2041;  slog::Index** Lfindex2042;  slog::Index** Lfindex2043;  slog::Index** Lfindex2044;  slog::Index** Lfindex2045;  slog::Index** Lfindex2046;  slog::Index** Lfindex2047;  slog::Index** Lfindex2048;  slog::Index** Lfindex2049;  slog::Index** Lfindex2050;  slog::Index** Lfindex2051;  slog::Index** Lfindex2052;  slog::Index** Lfindex2053;  slog::Index** Lfindex2054;  slog::Index** Lfindex2055;  slog::Index** Lfindex2056;  slog::Index** Lfindex2057;  slog::Index** Lfindex2058;  slog::Index** Lfindex2059;  slog::Index** Lfindex2060;  slog::Index** Lfindex2061;  slog::Index** Lfindex2062;  slog::Index** Lfindex2063;  slog::Index** Lfindex2064;  slog::Index** Lfindex2065;  slog::Index** Lfindex2066;  slog::Index** Lfindex2067;  slog::Index** Lfindex2068;  slog::Index** Lfindex2069;  slog::Index** Ndindex2070;  slog::Index** Ndindex2071;  slog::Index** Lfindex2072;  slog::Index** Ndindex2073;  slog::Index** Lfindex2074;  slog::Index** Ndindex2075;  slog::Index** Ndindex2076;  slog::Index** Ndindex2077;  slog::Index** Lfindex2078;  slog::Index** Ndindex2079;  slog::Index** Lfindex2080;  slog::Index** Ndindex2081;  slog::Index** Ndindex2082;  slog::Index** Lfindex2083;  slog::Index** Ndindex2084;  slog::Index** Lfindex2085;  slog::Index** Ndindex2086;  slog::Index** Ndindex2087;  slog::Index** Ndindex2088;  slog::Index** Ndindex2089;  slog::Index** Lfindex2090;  slog::Index** Ndindex2091;  slog::Index** Lfindex2092;  slog::Index** Ndindex2093;  slog::Index** Ndindex2094;  slog::Index** Lfindex2095;  slog::Index** Ndindex2096;  slog::Index** Lfindex2097;  slog::Index** Ndindex2098;  slog::Index** Ndindex2099;  slog::Index** Ndindex2100;  slog::Index** Lfindex2101;  slog::Index** Ndindex2102;  slog::Index** Lfindex2103;  slog::Index** Ndindex2104;  slog::Index** Ndindex2105;  slog::Index** Lfindex2106;  slog::Index** Ndindex2107;  slog::Index** Lfindex2108;  slog::Index** Ndindex2109;  slog::Index** Ndindex2110;  slog::Index** Ndindex2111;  slog::Index** Ndindex2112;  slog::Index** Lfindex2113;  slog::Index** Ndindex2114;  slog::Index** Lfindex2115;  slog::Index** Ndindex2116;  slog::Index** Ndindex2117;  slog::Index** Lfindex2118;  slog::Index** Ndindex2119;  slog::Index** Lfindex2120;  slog::Index** Ndindex2121;  slog::Index** Ndindex2122;  slog::Index** Ndindex2123;  slog::Index** Lfindex2124;  slog::Index** Ndindex2125;  slog::Index** Lfindex2126;  slog::Index** Ndindex2127;  slog::Index** Ndindex2128;  slog::Index** Lfindex2129;  slog::Index** Ndindex2130;  slog::Index** Lfindex2131;  slog::Index** Ndindex2132;  slog::Index** Ndindex2133;  slog::Index** Ndindex2134;  slog::Index** Ndindex2135;  slog::Index** Lfindex2136;  slog::Index** Ndindex2137;  slog::Index** Lfindex2138;  slog::Index** Ndindex2139;  slog::Index** Ndindex2140;  slog::Index** Lfindex2141;  slog::Index** Ndindex2142;  slog::Index** Lfindex2143;  slog::Index** Ndindex2144;  slog::Index** Ndindex2145;  slog::Index** Ndindex2146;  slog::Index** Lfindex2147;  slog::Index** Ndindex2148;  slog::Index** Lfindex2149;  slog::Index** Ndindex2150;  slog::Index** Ndindex2151;  slog::Index** Lfindex2152;  slog::Index** Ndindex2153;  slog::Index** Lfindex2154;  slog::Index** Ndindex2155;  slog::Index** Ndindex2156;  slog::Index** Ndindex2157;  slog::Index** Ndindex2158;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("Nd");
      std::vector<u16> ord2160({2, 1, 0});
      slog::Relation* readrel2161 = db->getRelation("Nd");
      head_index[0] = readrel2161->getIndex(ord2160, false);
      std::vector<u16> ord2162({1, 0});
      slog::Relation* readrel2163 = db->getRelation("Lf");
      Lfindex2037 = readrel2163->getIndex(ord2162, false);
      std::vector<u16> ord2164({2, 1, 0});
      slog::Relation* readrel2165 = db->getRelation("Nd");
      Ndindex2038 = readrel2165->getIndex(ord2164, false);
      std::vector<u16> ord2166({1, 0});
      slog::Relation* readrel2167 = db->getRelation("Lf");
      Lfindex2039 = readrel2167->getIndex(ord2166, false);
      std::vector<u16> ord2168({1, 0});
      slog::Relation* readrel2169 = db->getRelation("Lf");
      Lfindex2040 = readrel2169->getIndex(ord2168, false);
      std::vector<u16> ord2170({1, 0});
      slog::Relation* readrel2171 = db->getRelation("Lf");
      Lfindex2041 = readrel2171->getIndex(ord2170, false);
      std::vector<u16> ord2172({1, 0});
      slog::Relation* readrel2173 = db->getRelation("Lf");
      Lfindex2042 = readrel2173->getIndex(ord2172, false);
      std::vector<u16> ord2174({1, 0});
      slog::Relation* readrel2175 = db->getRelation("Lf");
      Lfindex2043 = readrel2175->getIndex(ord2174, false);
      std::vector<u16> ord2176({1, 0});
      slog::Relation* readrel2177 = db->getRelation("Lf");
      Lfindex2044 = readrel2177->getIndex(ord2176, false);
      std::vector<u16> ord2178({1, 0});
      slog::Relation* readrel2179 = db->getRelation("Lf");
      Lfindex2045 = readrel2179->getIndex(ord2178, false);
      std::vector<u16> ord2180({1, 0});
      slog::Relation* readrel2181 = db->getRelation("Lf");
      Lfindex2046 = readrel2181->getIndex(ord2180, false);
      std::vector<u16> ord2182({1, 0});
      slog::Relation* readrel2183 = db->getRelation("Lf");
      Lfindex2047 = readrel2183->getIndex(ord2182, false);
      std::vector<u16> ord2184({1, 0});
      slog::Relation* readrel2185 = db->getRelation("Lf");
      Lfindex2048 = readrel2185->getIndex(ord2184, false);
      std::vector<u16> ord2186({1, 0});
      slog::Relation* readrel2187 = db->getRelation("Lf");
      Lfindex2049 = readrel2187->getIndex(ord2186, false);
      std::vector<u16> ord2188({1, 0});
      slog::Relation* readrel2189 = db->getRelation("Lf");
      Lfindex2050 = readrel2189->getIndex(ord2188, false);
      std::vector<u16> ord2190({1, 0});
      slog::Relation* readrel2191 = db->getRelation("Lf");
      Lfindex2051 = readrel2191->getIndex(ord2190, false);
      std::vector<u16> ord2192({1, 0});
      slog::Relation* readrel2193 = db->getRelation("Lf");
      Lfindex2052 = readrel2193->getIndex(ord2192, false);
      std::vector<u16> ord2194({1, 0});
      slog::Relation* readrel2195 = db->getRelation("Lf");
      Lfindex2053 = readrel2195->getIndex(ord2194, false);
      std::vector<u16> ord2196({1, 0});
      slog::Relation* readrel2197 = db->getRelation("Lf");
      Lfindex2054 = readrel2197->getIndex(ord2196, false);
      std::vector<u16> ord2198({1, 0});
      slog::Relation* readrel2199 = db->getRelation("Lf");
      Lfindex2055 = readrel2199->getIndex(ord2198, false);
      std::vector<u16> ord2200({1, 0});
      slog::Relation* readrel2201 = db->getRelation("Lf");
      Lfindex2056 = readrel2201->getIndex(ord2200, false);
      std::vector<u16> ord2202({1, 0});
      slog::Relation* readrel2203 = db->getRelation("Lf");
      Lfindex2057 = readrel2203->getIndex(ord2202, false);
      std::vector<u16> ord2204({1, 0});
      slog::Relation* readrel2205 = db->getRelation("Lf");
      Lfindex2058 = readrel2205->getIndex(ord2204, false);
      std::vector<u16> ord2206({1, 0});
      slog::Relation* readrel2207 = db->getRelation("Lf");
      Lfindex2059 = readrel2207->getIndex(ord2206, false);
      std::vector<u16> ord2208({1, 0});
      slog::Relation* readrel2209 = db->getRelation("Lf");
      Lfindex2060 = readrel2209->getIndex(ord2208, false);
      std::vector<u16> ord2210({1, 0});
      slog::Relation* readrel2211 = db->getRelation("Lf");
      Lfindex2061 = readrel2211->getIndex(ord2210, false);
      std::vector<u16> ord2212({1, 0});
      slog::Relation* readrel2213 = db->getRelation("Lf");
      Lfindex2062 = readrel2213->getIndex(ord2212, false);
      std::vector<u16> ord2214({1, 0});
      slog::Relation* readrel2215 = db->getRelation("Lf");
      Lfindex2063 = readrel2215->getIndex(ord2214, false);
      std::vector<u16> ord2216({1, 0});
      slog::Relation* readrel2217 = db->getRelation("Lf");
      Lfindex2064 = readrel2217->getIndex(ord2216, false);
      std::vector<u16> ord2218({1, 0});
      slog::Relation* readrel2219 = db->getRelation("Lf");
      Lfindex2065 = readrel2219->getIndex(ord2218, false);
      std::vector<u16> ord2220({1, 0});
      slog::Relation* readrel2221 = db->getRelation("Lf");
      Lfindex2066 = readrel2221->getIndex(ord2220, false);
      std::vector<u16> ord2222({1, 0});
      slog::Relation* readrel2223 = db->getRelation("Lf");
      Lfindex2067 = readrel2223->getIndex(ord2222, false);
      std::vector<u16> ord2224({1, 0});
      slog::Relation* readrel2225 = db->getRelation("Lf");
      Lfindex2068 = readrel2225->getIndex(ord2224, false);
      std::vector<u16> ord2226({1, 0});
      slog::Relation* readrel2227 = db->getRelation("Lf");
      Lfindex2069 = readrel2227->getIndex(ord2226, false);
      std::vector<u16> ord2228({2, 1, 0});
      slog::Relation* readrel2229 = db->getRelation("Nd");
      Ndindex2070 = readrel2229->getIndex(ord2228, false);
      std::vector<u16> ord2230({2, 1, 0});
      slog::Relation* readrel2231 = db->getRelation("Nd");
      Ndindex2071 = readrel2231->getIndex(ord2230, false);
      std::vector<u16> ord2232({1, 0});
      slog::Relation* readrel2233 = db->getRelation("Lf");
      Lfindex2072 = readrel2233->getIndex(ord2232, false);
      std::vector<u16> ord2234({2, 1, 0});
      slog::Relation* readrel2235 = db->getRelation("Nd");
      Ndindex2073 = readrel2235->getIndex(ord2234, false);
      std::vector<u16> ord2236({1, 0});
      slog::Relation* readrel2237 = db->getRelation("Lf");
      Lfindex2074 = readrel2237->getIndex(ord2236, false);
      std::vector<u16> ord2238({2, 1, 0});
      slog::Relation* readrel2239 = db->getRelation("Nd");
      Ndindex2075 = readrel2239->getIndex(ord2238, false);
      std::vector<u16> ord2240({2, 1, 0});
      slog::Relation* readrel2241 = db->getRelation("Nd");
      Ndindex2076 = readrel2241->getIndex(ord2240, false);
      std::vector<u16> ord2242({2, 1, 0});
      slog::Relation* readrel2243 = db->getRelation("Nd");
      Ndindex2077 = readrel2243->getIndex(ord2242, false);
      std::vector<u16> ord2244({1, 0});
      slog::Relation* readrel2245 = db->getRelation("Lf");
      Lfindex2078 = readrel2245->getIndex(ord2244, false);
      std::vector<u16> ord2246({2, 1, 0});
      slog::Relation* readrel2247 = db->getRelation("Nd");
      Ndindex2079 = readrel2247->getIndex(ord2246, false);
      std::vector<u16> ord2248({1, 0});
      slog::Relation* readrel2249 = db->getRelation("Lf");
      Lfindex2080 = readrel2249->getIndex(ord2248, false);
      std::vector<u16> ord2250({2, 1, 0});
      slog::Relation* readrel2251 = db->getRelation("Nd");
      Ndindex2081 = readrel2251->getIndex(ord2250, false);
      std::vector<u16> ord2252({2, 1, 0});
      slog::Relation* readrel2253 = db->getRelation("Nd");
      Ndindex2082 = readrel2253->getIndex(ord2252, false);
      std::vector<u16> ord2254({1, 0});
      slog::Relation* readrel2255 = db->getRelation("Lf");
      Lfindex2083 = readrel2255->getIndex(ord2254, false);
      std::vector<u16> ord2256({2, 1, 0});
      slog::Relation* readrel2257 = db->getRelation("Nd");
      Ndindex2084 = readrel2257->getIndex(ord2256, false);
      std::vector<u16> ord2258({1, 0});
      slog::Relation* readrel2259 = db->getRelation("Lf");
      Lfindex2085 = readrel2259->getIndex(ord2258, false);
      std::vector<u16> ord2260({2, 1, 0});
      slog::Relation* readrel2261 = db->getRelation("Nd");
      Ndindex2086 = readrel2261->getIndex(ord2260, false);
      std::vector<u16> ord2262({2, 1, 0});
      slog::Relation* readrel2263 = db->getRelation("Nd");
      Ndindex2087 = readrel2263->getIndex(ord2262, false);
      std::vector<u16> ord2264({2, 1, 0});
      slog::Relation* readrel2265 = db->getRelation("Nd");
      Ndindex2088 = readrel2265->getIndex(ord2264, false);
      std::vector<u16> ord2266({2, 1, 0});
      slog::Relation* readrel2267 = db->getRelation("Nd");
      Ndindex2089 = readrel2267->getIndex(ord2266, false);
      std::vector<u16> ord2268({1, 0});
      slog::Relation* readrel2269 = db->getRelation("Lf");
      Lfindex2090 = readrel2269->getIndex(ord2268, false);
      std::vector<u16> ord2270({2, 1, 0});
      slog::Relation* readrel2271 = db->getRelation("Nd");
      Ndindex2091 = readrel2271->getIndex(ord2270, false);
      std::vector<u16> ord2272({1, 0});
      slog::Relation* readrel2273 = db->getRelation("Lf");
      Lfindex2092 = readrel2273->getIndex(ord2272, false);
      std::vector<u16> ord2274({2, 1, 0});
      slog::Relation* readrel2275 = db->getRelation("Nd");
      Ndindex2093 = readrel2275->getIndex(ord2274, false);
      std::vector<u16> ord2276({2, 1, 0});
      slog::Relation* readrel2277 = db->getRelation("Nd");
      Ndindex2094 = readrel2277->getIndex(ord2276, false);
      std::vector<u16> ord2278({1, 0});
      slog::Relation* readrel2279 = db->getRelation("Lf");
      Lfindex2095 = readrel2279->getIndex(ord2278, false);
      std::vector<u16> ord2280({2, 1, 0});
      slog::Relation* readrel2281 = db->getRelation("Nd");
      Ndindex2096 = readrel2281->getIndex(ord2280, false);
      std::vector<u16> ord2282({1, 0});
      slog::Relation* readrel2283 = db->getRelation("Lf");
      Lfindex2097 = readrel2283->getIndex(ord2282, false);
      std::vector<u16> ord2284({2, 1, 0});
      slog::Relation* readrel2285 = db->getRelation("Nd");
      Ndindex2098 = readrel2285->getIndex(ord2284, false);
      std::vector<u16> ord2286({2, 1, 0});
      slog::Relation* readrel2287 = db->getRelation("Nd");
      Ndindex2099 = readrel2287->getIndex(ord2286, false);
      std::vector<u16> ord2288({2, 1, 0});
      slog::Relation* readrel2289 = db->getRelation("Nd");
      Ndindex2100 = readrel2289->getIndex(ord2288, false);
      std::vector<u16> ord2290({1, 0});
      slog::Relation* readrel2291 = db->getRelation("Lf");
      Lfindex2101 = readrel2291->getIndex(ord2290, false);
      std::vector<u16> ord2292({2, 1, 0});
      slog::Relation* readrel2293 = db->getRelation("Nd");
      Ndindex2102 = readrel2293->getIndex(ord2292, false);
      std::vector<u16> ord2294({1, 0});
      slog::Relation* readrel2295 = db->getRelation("Lf");
      Lfindex2103 = readrel2295->getIndex(ord2294, false);
      std::vector<u16> ord2296({2, 1, 0});
      slog::Relation* readrel2297 = db->getRelation("Nd");
      Ndindex2104 = readrel2297->getIndex(ord2296, false);
      std::vector<u16> ord2298({2, 1, 0});
      slog::Relation* readrel2299 = db->getRelation("Nd");
      Ndindex2105 = readrel2299->getIndex(ord2298, false);
      std::vector<u16> ord2300({1, 0});
      slog::Relation* readrel2301 = db->getRelation("Lf");
      Lfindex2106 = readrel2301->getIndex(ord2300, false);
      std::vector<u16> ord2302({2, 1, 0});
      slog::Relation* readrel2303 = db->getRelation("Nd");
      Ndindex2107 = readrel2303->getIndex(ord2302, false);
      std::vector<u16> ord2304({1, 0});
      slog::Relation* readrel2305 = db->getRelation("Lf");
      Lfindex2108 = readrel2305->getIndex(ord2304, false);
      std::vector<u16> ord2306({2, 1, 0});
      slog::Relation* readrel2307 = db->getRelation("Nd");
      Ndindex2109 = readrel2307->getIndex(ord2306, false);
      std::vector<u16> ord2308({2, 1, 0});
      slog::Relation* readrel2309 = db->getRelation("Nd");
      Ndindex2110 = readrel2309->getIndex(ord2308, false);
      std::vector<u16> ord2310({2, 1, 0});
      slog::Relation* readrel2311 = db->getRelation("Nd");
      Ndindex2111 = readrel2311->getIndex(ord2310, false);
      std::vector<u16> ord2312({2, 1, 0});
      slog::Relation* readrel2313 = db->getRelation("Nd");
      Ndindex2112 = readrel2313->getIndex(ord2312, false);
      std::vector<u16> ord2314({1, 0});
      slog::Relation* readrel2315 = db->getRelation("Lf");
      Lfindex2113 = readrel2315->getIndex(ord2314, false);
      std::vector<u16> ord2316({2, 1, 0});
      slog::Relation* readrel2317 = db->getRelation("Nd");
      Ndindex2114 = readrel2317->getIndex(ord2316, false);
      std::vector<u16> ord2318({1, 0});
      slog::Relation* readrel2319 = db->getRelation("Lf");
      Lfindex2115 = readrel2319->getIndex(ord2318, false);
      std::vector<u16> ord2320({2, 1, 0});
      slog::Relation* readrel2321 = db->getRelation("Nd");
      Ndindex2116 = readrel2321->getIndex(ord2320, false);
      std::vector<u16> ord2322({2, 1, 0});
      slog::Relation* readrel2323 = db->getRelation("Nd");
      Ndindex2117 = readrel2323->getIndex(ord2322, false);
      std::vector<u16> ord2324({1, 0});
      slog::Relation* readrel2325 = db->getRelation("Lf");
      Lfindex2118 = readrel2325->getIndex(ord2324, false);
      std::vector<u16> ord2326({2, 1, 0});
      slog::Relation* readrel2327 = db->getRelation("Nd");
      Ndindex2119 = readrel2327->getIndex(ord2326, false);
      std::vector<u16> ord2328({1, 0});
      slog::Relation* readrel2329 = db->getRelation("Lf");
      Lfindex2120 = readrel2329->getIndex(ord2328, false);
      std::vector<u16> ord2330({2, 1, 0});
      slog::Relation* readrel2331 = db->getRelation("Nd");
      Ndindex2121 = readrel2331->getIndex(ord2330, false);
      std::vector<u16> ord2332({2, 1, 0});
      slog::Relation* readrel2333 = db->getRelation("Nd");
      Ndindex2122 = readrel2333->getIndex(ord2332, false);
      std::vector<u16> ord2334({2, 1, 0});
      slog::Relation* readrel2335 = db->getRelation("Nd");
      Ndindex2123 = readrel2335->getIndex(ord2334, false);
      std::vector<u16> ord2336({1, 0});
      slog::Relation* readrel2337 = db->getRelation("Lf");
      Lfindex2124 = readrel2337->getIndex(ord2336, false);
      std::vector<u16> ord2338({2, 1, 0});
      slog::Relation* readrel2339 = db->getRelation("Nd");
      Ndindex2125 = readrel2339->getIndex(ord2338, false);
      std::vector<u16> ord2340({1, 0});
      slog::Relation* readrel2341 = db->getRelation("Lf");
      Lfindex2126 = readrel2341->getIndex(ord2340, false);
      std::vector<u16> ord2342({2, 1, 0});
      slog::Relation* readrel2343 = db->getRelation("Nd");
      Ndindex2127 = readrel2343->getIndex(ord2342, false);
      std::vector<u16> ord2344({2, 1, 0});
      slog::Relation* readrel2345 = db->getRelation("Nd");
      Ndindex2128 = readrel2345->getIndex(ord2344, false);
      std::vector<u16> ord2346({1, 0});
      slog::Relation* readrel2347 = db->getRelation("Lf");
      Lfindex2129 = readrel2347->getIndex(ord2346, false);
      std::vector<u16> ord2348({2, 1, 0});
      slog::Relation* readrel2349 = db->getRelation("Nd");
      Ndindex2130 = readrel2349->getIndex(ord2348, false);
      std::vector<u16> ord2350({1, 0});
      slog::Relation* readrel2351 = db->getRelation("Lf");
      Lfindex2131 = readrel2351->getIndex(ord2350, false);
      std::vector<u16> ord2352({2, 1, 0});
      slog::Relation* readrel2353 = db->getRelation("Nd");
      Ndindex2132 = readrel2353->getIndex(ord2352, false);
      std::vector<u16> ord2354({2, 1, 0});
      slog::Relation* readrel2355 = db->getRelation("Nd");
      Ndindex2133 = readrel2355->getIndex(ord2354, false);
      std::vector<u16> ord2356({2, 1, 0});
      slog::Relation* readrel2357 = db->getRelation("Nd");
      Ndindex2134 = readrel2357->getIndex(ord2356, false);
      std::vector<u16> ord2358({2, 1, 0});
      slog::Relation* readrel2359 = db->getRelation("Nd");
      Ndindex2135 = readrel2359->getIndex(ord2358, false);
      std::vector<u16> ord2360({1, 0});
      slog::Relation* readrel2361 = db->getRelation("Lf");
      Lfindex2136 = readrel2361->getIndex(ord2360, false);
      std::vector<u16> ord2362({2, 1, 0});
      slog::Relation* readrel2363 = db->getRelation("Nd");
      Ndindex2137 = readrel2363->getIndex(ord2362, false);
      std::vector<u16> ord2364({1, 0});
      slog::Relation* readrel2365 = db->getRelation("Lf");
      Lfindex2138 = readrel2365->getIndex(ord2364, false);
      std::vector<u16> ord2366({2, 1, 0});
      slog::Relation* readrel2367 = db->getRelation("Nd");
      Ndindex2139 = readrel2367->getIndex(ord2366, false);
      std::vector<u16> ord2368({2, 1, 0});
      slog::Relation* readrel2369 = db->getRelation("Nd");
      Ndindex2140 = readrel2369->getIndex(ord2368, false);
      std::vector<u16> ord2370({1, 0});
      slog::Relation* readrel2371 = db->getRelation("Lf");
      Lfindex2141 = readrel2371->getIndex(ord2370, false);
      std::vector<u16> ord2372({2, 1, 0});
      slog::Relation* readrel2373 = db->getRelation("Nd");
      Ndindex2142 = readrel2373->getIndex(ord2372, false);
      std::vector<u16> ord2374({1, 0});
      slog::Relation* readrel2375 = db->getRelation("Lf");
      Lfindex2143 = readrel2375->getIndex(ord2374, false);
      std::vector<u16> ord2376({2, 1, 0});
      slog::Relation* readrel2377 = db->getRelation("Nd");
      Ndindex2144 = readrel2377->getIndex(ord2376, false);
      std::vector<u16> ord2378({2, 1, 0});
      slog::Relation* readrel2379 = db->getRelation("Nd");
      Ndindex2145 = readrel2379->getIndex(ord2378, false);
      std::vector<u16> ord2380({2, 1, 0});
      slog::Relation* readrel2381 = db->getRelation("Nd");
      Ndindex2146 = readrel2381->getIndex(ord2380, false);
      std::vector<u16> ord2382({1, 0});
      slog::Relation* readrel2383 = db->getRelation("Lf");
      Lfindex2147 = readrel2383->getIndex(ord2382, false);
      std::vector<u16> ord2384({2, 1, 0});
      slog::Relation* readrel2385 = db->getRelation("Nd");
      Ndindex2148 = readrel2385->getIndex(ord2384, false);
      std::vector<u16> ord2386({1, 0});
      slog::Relation* readrel2387 = db->getRelation("Lf");
      Lfindex2149 = readrel2387->getIndex(ord2386, false);
      std::vector<u16> ord2388({2, 1, 0});
      slog::Relation* readrel2389 = db->getRelation("Nd");
      Ndindex2150 = readrel2389->getIndex(ord2388, false);
      std::vector<u16> ord2390({2, 1, 0});
      slog::Relation* readrel2391 = db->getRelation("Nd");
      Ndindex2151 = readrel2391->getIndex(ord2390, false);
      std::vector<u16> ord2392({1, 0});
      slog::Relation* readrel2393 = db->getRelation("Lf");
      Lfindex2152 = readrel2393->getIndex(ord2392, false);
      std::vector<u16> ord2394({2, 1, 0});
      slog::Relation* readrel2395 = db->getRelation("Nd");
      Ndindex2153 = readrel2395->getIndex(ord2394, false);
      std::vector<u16> ord2396({1, 0});
      slog::Relation* readrel2397 = db->getRelation("Lf");
      Lfindex2154 = readrel2397->getIndex(ord2396, false);
      std::vector<u16> ord2398({2, 1, 0});
      slog::Relation* readrel2399 = db->getRelation("Nd");
      Ndindex2155 = readrel2399->getIndex(ord2398, false);
      std::vector<u16> ord2400({2, 1, 0});
      slog::Relation* readrel2401 = db->getRelation("Nd");
      Ndindex2156 = readrel2401->getIndex(ord2400, false);
      std::vector<u16> ord2402({2, 1, 0});
      slog::Relation* readrel2403 = db->getRelation("Nd");
      Ndindex2157 = readrel2403->getIndex(ord2402, false);
      std::vector<u16> ord2404({2, 1, 0});
      slog::Relation* readrel2405 = db->getRelation("Nd");
      Ndindex2158 = readrel2405->getIndex(ord2404, false);
  
    }
    ReadTask2159(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(Lfindex2037, std::array<u64,2>{v_c31, 0}, [&](const std::array<u64,2>& m2406) {
        u64 v_c35 = m2406[1];
        if (!slog::exists_probe<3,1>(Ndindex2038, std::array<u64,3>{v_c35, 0, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2039, std::array<u64,2>{v_c29, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2040, std::array<u64,2>{v_c28, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2041, std::array<u64,2>{v_c27, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2042, std::array<u64,2>{v_c26, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2043, std::array<u64,2>{v_c25, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2044, std::array<u64,2>{v_c24, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2045, std::array<u64,2>{v_c23, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2046, std::array<u64,2>{v_c22, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2047, std::array<u64,2>{v_c21, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2048, std::array<u64,2>{v_c20, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2049, std::array<u64,2>{v_c19, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2050, std::array<u64,2>{v_c18, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2051, std::array<u64,2>{v_c17, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2052, std::array<u64,2>{v_c16, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2053, std::array<u64,2>{v_c15, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2054, std::array<u64,2>{v_c14, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2055, std::array<u64,2>{v_c13, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2056, std::array<u64,2>{v_c12, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2057, std::array<u64,2>{v_c11, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2058, std::array<u64,2>{v_c10, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2059, std::array<u64,2>{v_c9, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2060, std::array<u64,2>{v_c8, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2061, std::array<u64,2>{v_c7, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2062, std::array<u64,2>{v_c6, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2063, std::array<u64,2>{v_c5, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2064, std::array<u64,2>{v_c4, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2065, std::array<u64,2>{v_c3, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2066, std::array<u64,2>{v_c2, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2067, std::array<u64,2>{v_c1, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2068, std::array<u64,2>{v_c0, 0})) return;
        slog::join_probe<2,1>(Lfindex2069, std::array<u64,2>{v_c30, 0}, [&](const std::array<u64,2>& m2407) {
          u64 v_c36 = m2407[1];
          slog::join_probe<3,2>(Ndindex2070, std::array<u64,3>{v_c35, v_c36, 0}, [&](const std::array<u64,3>& m2408) {
            u64 v_c37 = m2408[2];
            if (!slog::exists_probe<3,1>(Ndindex2071, std::array<u64,3>{v_c37, 0, 0})) return;
            slog::join_probe<2,1>(Lfindex2072, std::array<u64,2>{v_c29, 0}, [&](const std::array<u64,2>& m2409) {
              u64 v_c38 = m2409[1];
              if (!slog::exists_probe<3,1>(Ndindex2073, std::array<u64,3>{v_c38, 0, 0})) return;
              slog::join_probe<2,1>(Lfindex2074, std::array<u64,2>{v_c28, 0}, [&](const std::array<u64,2>& m2410) {
                u64 v_c39 = m2410[1];
                slog::join_probe<3,2>(Ndindex2075, std::array<u64,3>{v_c38, v_c39, 0}, [&](const std::array<u64,3>& m2411) {
                  u64 v_c40 = m2411[2];
                  slog::join_probe<3,2>(Ndindex2076, std::array<u64,3>{v_c37, v_c40, 0}, [&](const std::array<u64,3>& m2412) {
                    u64 v_c41 = m2412[2];
                    if (!slog::exists_probe<3,1>(Ndindex2077, std::array<u64,3>{v_c41, 0, 0})) return;
                    slog::join_probe<2,1>(Lfindex2078, std::array<u64,2>{v_c27, 0}, [&](const std::array<u64,2>& m2413) {
                      u64 v_c43 = m2413[1];
                      if (!slog::exists_probe<3,1>(Ndindex2079, std::array<u64,3>{v_c43, 0, 0})) return;
                      slog::join_probe<2,1>(Lfindex2080, std::array<u64,2>{v_c26, 0}, [&](const std::array<u64,2>& m2414) {
                        u64 v_c44 = m2414[1];
                        slog::join_probe<3,2>(Ndindex2081, std::array<u64,3>{v_c43, v_c44, 0}, [&](const std::array<u64,3>& m2415) {
                          u64 v_c45 = m2415[2];
                          if (!slog::exists_probe<3,1>(Ndindex2082, std::array<u64,3>{v_c45, 0, 0})) return;
                          slog::join_probe<2,1>(Lfindex2083, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m2416) {
                            u64 v_c47 = m2416[1];
                            if (!slog::exists_probe<3,1>(Ndindex2084, std::array<u64,3>{v_c47, 0, 0})) return;
                            slog::join_probe<2,1>(Lfindex2085, std::array<u64,2>{v_c24, 0}, [&](const std::array<u64,2>& m2417) {
                              u64 v_c48 = m2417[1];
                              slog::join_probe<3,2>(Ndindex2086, std::array<u64,3>{v_c47, v_c48, 0}, [&](const std::array<u64,3>& m2418) {
                                u64 v_c46 = m2418[2];
                                slog::join_probe<3,2>(Ndindex2087, std::array<u64,3>{v_c45, v_c46, 0}, [&](const std::array<u64,3>& m2419) {
                                  u64 v_c42 = m2419[2];
                                  slog::join_probe<3,2>(Ndindex2088, std::array<u64,3>{v_c41, v_c42, 0}, [&](const std::array<u64,3>& m2420) {
                                    u64 v_c34 = m2420[2];
                                    if (!slog::exists_probe<3,1>(Ndindex2089, std::array<u64,3>{v_c34, 0, 0})) return;
                                    slog::join_probe<2,1>(Lfindex2090, std::array<u64,2>{v_c23, 0}, [&](const std::array<u64,2>& m2421) {
                                      u64 v_c49 = m2421[1];
                                      if (!slog::exists_probe<3,1>(Ndindex2091, std::array<u64,3>{v_c49, 0, 0})) return;
                                      slog::join_probe<2,1>(Lfindex2092, std::array<u64,2>{v_c22, 0}, [&](const std::array<u64,2>& m2422) {
                                        u64 v_c50 = m2422[1];
                                        slog::join_probe<3,2>(Ndindex2093, std::array<u64,3>{v_c49, v_c50, 0}, [&](const std::array<u64,3>& m2423) {
                                          u64 v_c51 = m2423[2];
                                          if (!slog::exists_probe<3,1>(Ndindex2094, std::array<u64,3>{v_c51, 0, 0})) return;
                                          slog::join_probe<2,1>(Lfindex2095, std::array<u64,2>{v_c21, 0}, [&](const std::array<u64,2>& m2424) {
                                            u64 v_c52 = m2424[1];
                                            if (!slog::exists_probe<3,1>(Ndindex2096, std::array<u64,3>{v_c52, 0, 0})) return;
                                            slog::join_probe<2,1>(Lfindex2097, std::array<u64,2>{v_c20, 0}, [&](const std::array<u64,2>& m2425) {
                                              u64 v_c53 = m2425[1];
                                              slog::join_probe<3,2>(Ndindex2098, std::array<u64,3>{v_c52, v_c53, 0}, [&](const std::array<u64,3>& m2426) {
                                                u64 v_c54 = m2426[2];
                                                slog::join_probe<3,2>(Ndindex2099, std::array<u64,3>{v_c51, v_c54, 0}, [&](const std::array<u64,3>& m2427) {
                                                  u64 v_c55 = m2427[2];
                                                  if (!slog::exists_probe<3,1>(Ndindex2100, std::array<u64,3>{v_c55, 0, 0})) return;
                                                  slog::join_probe<2,1>(Lfindex2101, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m2428) {
                                                    u64 v_c57 = m2428[1];
                                                    if (!slog::exists_probe<3,1>(Ndindex2102, std::array<u64,3>{v_c57, 0, 0})) return;
                                                    slog::join_probe<2,1>(Lfindex2103, std::array<u64,2>{v_c18, 0}, [&](const std::array<u64,2>& m2429) {
                                                      u64 v_c58 = m2429[1];
                                                      slog::join_probe<3,2>(Ndindex2104, std::array<u64,3>{v_c57, v_c58, 0}, [&](const std::array<u64,3>& m2430) {
                                                        u64 v_c59 = m2430[2];
                                                        if (!slog::exists_probe<3,1>(Ndindex2105, std::array<u64,3>{v_c59, 0, 0})) return;
                                                        slog::join_probe<2,1>(Lfindex2106, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m2431) {
                                                          u64 v_c61 = m2431[1];
                                                          if (!slog::exists_probe<3,1>(Ndindex2107, std::array<u64,3>{v_c61, 0, 0})) return;
                                                          slog::join_probe<2,1>(Lfindex2108, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m2432) {
                                                            u64 v_c62 = m2432[1];
                                                            slog::join_probe<3,2>(Ndindex2109, std::array<u64,3>{v_c61, v_c62, 0}, [&](const std::array<u64,3>& m2433) {
                                                              u64 v_c60 = m2433[2];
                                                              slog::join_probe<3,2>(Ndindex2110, std::array<u64,3>{v_c59, v_c60, 0}, [&](const std::array<u64,3>& m2434) {
                                                                u64 v_c56 = m2434[2];
                                                                slog::join_probe<3,2>(Ndindex2111, std::array<u64,3>{v_c55, v_c56, 0}, [&](const std::array<u64,3>& m2435) {
                                                                  u64 v_c33 = m2435[2];
                                                                  slog::join_probe<3,2>(Ndindex2112, std::array<u64,3>{v_c34, v_c33, 0}, [&](const std::array<u64,3>& m2436) {
                                                                    u64 v_c32 = m2436[2];
                                                                    slog::join_probe<2,1>(Lfindex2113, std::array<u64,2>{v_c15, 0}, [&](const std::array<u64,2>& m2437) {
                                                                      u64 v_c63 = m2437[1];
                                                                      if (!slog::exists_probe<3,1>(Ndindex2114, std::array<u64,3>{v_c63, 0, 0})) return;
                                                                      slog::join_probe<2,1>(Lfindex2115, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m2438) {
                                                                        u64 v_c64 = m2438[1];
                                                                        slog::join_probe<3,2>(Ndindex2116, std::array<u64,3>{v_c63, v_c64, 0}, [&](const std::array<u64,3>& m2439) {
                                                                          u64 v_c65 = m2439[2];
                                                                          if (!slog::exists_probe<3,1>(Ndindex2117, std::array<u64,3>{v_c65, 0, 0})) return;
                                                                          slog::join_probe<2,1>(Lfindex2118, std::array<u64,2>{v_c13, 0}, [&](const std::array<u64,2>& m2440) {
                                                                            u64 v_c66 = m2440[1];
                                                                            if (!slog::exists_probe<3,1>(Ndindex2119, std::array<u64,3>{v_c66, 0, 0})) return;
                                                                            slog::join_probe<2,1>(Lfindex2120, std::array<u64,2>{v_c12, 0}, [&](const std::array<u64,2>& m2441) {
                                                                              u64 v_c67 = m2441[1];
                                                                              slog::join_probe<3,2>(Ndindex2121, std::array<u64,3>{v_c66, v_c67, 0}, [&](const std::array<u64,3>& m2442) {
                                                                                u64 v_c68 = m2442[2];
                                                                                slog::join_probe<3,2>(Ndindex2122, std::array<u64,3>{v_c65, v_c68, 0}, [&](const std::array<u64,3>& m2443) {
                                                                                  u64 v_c69 = m2443[2];
                                                                                  if (!slog::exists_probe<3,1>(Ndindex2123, std::array<u64,3>{v_c69, 0, 0})) return;
                                                                                  slog::join_probe<2,1>(Lfindex2124, std::array<u64,2>{v_c11, 0}, [&](const std::array<u64,2>& m2444) {
                                                                                    u64 v_c70 = m2444[1];
                                                                                    if (!slog::exists_probe<3,1>(Ndindex2125, std::array<u64,3>{v_c70, 0, 0})) return;
                                                                                    slog::join_probe<2,1>(Lfindex2126, std::array<u64,2>{v_c10, 0}, [&](const std::array<u64,2>& m2445) {
                                                                                      u64 v_c71 = m2445[1];
                                                                                      slog::join_probe<3,2>(Ndindex2127, std::array<u64,3>{v_c70, v_c71, 0}, [&](const std::array<u64,3>& m2446) {
                                                                                        u64 v_c72 = m2446[2];
                                                                                        if (!slog::exists_probe<3,1>(Ndindex2128, std::array<u64,3>{v_c72, 0, 0})) return;
                                                                                        slog::join_probe<2,1>(Lfindex2129, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m2447) {
                                                                                          u64 v_c73 = m2447[1];
                                                                                          if (!slog::exists_probe<3,1>(Ndindex2130, std::array<u64,3>{v_c73, 0, 0})) return;
                                                                                          slog::join_probe<2,1>(Lfindex2131, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m2448) {
                                                                                            u64 v_c74 = m2448[1];
                                                                                            slog::join_probe<3,2>(Ndindex2132, std::array<u64,3>{v_c73, v_c74, 0}, [&](const std::array<u64,3>& m2449) {
                                                                                              u64 v_c75 = m2449[2];
                                                                                              slog::join_probe<3,2>(Ndindex2133, std::array<u64,3>{v_c72, v_c75, 0}, [&](const std::array<u64,3>& m2450) {
                                                                                                u64 v_c76 = m2450[2];
                                                                                                slog::join_probe<3,2>(Ndindex2134, std::array<u64,3>{v_c69, v_c76, 0}, [&](const std::array<u64,3>& m2451) {
                                                                                                  u64 v_c77 = m2451[2];
                                                                                                  if (!slog::exists_probe<3,1>(Ndindex2135, std::array<u64,3>{v_c77, 0, 0})) return;
                                                                                                  slog::join_probe<2,1>(Lfindex2136, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m2452) {
                                                                                                    u64 v_c78 = m2452[1];
                                                                                                    if (!slog::exists_probe<3,1>(Ndindex2137, std::array<u64,3>{v_c78, 0, 0})) return;
                                                                                                    slog::join_probe<2,1>(Lfindex2138, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m2453) {
                                                                                                      u64 v_c79 = m2453[1];
                                                                                                      slog::join_probe<3,2>(Ndindex2139, std::array<u64,3>{v_c78, v_c79, 0}, [&](const std::array<u64,3>& m2454) {
                                                                                                        u64 v_c80 = m2454[2];
                                                                                                        if (!slog::exists_probe<3,1>(Ndindex2140, std::array<u64,3>{v_c80, 0, 0})) return;
                                                                                                        slog::join_probe<2,1>(Lfindex2141, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m2455) {
                                                                                                          u64 v_c81 = m2455[1];
                                                                                                          if (!slog::exists_probe<3,1>(Ndindex2142, std::array<u64,3>{v_c81, 0, 0})) return;
                                                                                                          slog::join_probe<2,1>(Lfindex2143, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m2456) {
                                                                                                            u64 v_c82 = m2456[1];
                                                                                                            slog::join_probe<3,2>(Ndindex2144, std::array<u64,3>{v_c81, v_c82, 0}, [&](const std::array<u64,3>& m2457) {
                                                                                                              u64 v_c83 = m2457[2];
                                                                                                              slog::join_probe<3,2>(Ndindex2145, std::array<u64,3>{v_c80, v_c83, 0}, [&](const std::array<u64,3>& m2458) {
                                                                                                                u64 v_c84 = m2458[2];
                                                                                                                if (!slog::exists_probe<3,1>(Ndindex2146, std::array<u64,3>{v_c84, 0, 0})) return;
                                                                                                                slog::join_probe<2,1>(Lfindex2147, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m2459) {
                                                                                                                  u64 v_c85 = m2459[1];
                                                                                                                  if (!slog::exists_probe<3,1>(Ndindex2148, std::array<u64,3>{v_c85, 0, 0})) return;
                                                                                                                  slog::join_probe<2,1>(Lfindex2149, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m2460) {
                                                                                                                    u64 v_c86 = m2460[1];
                                                                                                                    slog::join_probe<3,2>(Ndindex2150, std::array<u64,3>{v_c85, v_c86, 0}, [&](const std::array<u64,3>& m2461) {
                                                                                                                      u64 v_c87 = m2461[2];
                                                                                                                      if (!slog::exists_probe<3,1>(Ndindex2151, std::array<u64,3>{v_c87, 0, 0})) return;
                                                                                                                      slog::join_probe<2,1>(Lfindex2152, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m2462) {
                                                                                                                        u64 v_c88 = m2462[1];
                                                                                                                        if (!slog::exists_probe<3,1>(Ndindex2153, std::array<u64,3>{v_c88, 0, 0})) return;
                                                                                                                        slog::join_probe<2,1>(Lfindex2154, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m2463) {
                                                                                                                          u64 v_c89 = m2463[1];
                                                                                                                          slog::join_probe<3,2>(Ndindex2155, std::array<u64,3>{v_c88, v_c89, 0}, [&](const std::array<u64,3>& m2464) {
                                                                                                                            u64 v_c90 = m2464[2];
                                                                                                                            slog::join_probe<3,2>(Ndindex2156, std::array<u64,3>{v_c87, v_c90, 0}, [&](const std::array<u64,3>& m2465) {
                                                                                                                              u64 v_c91 = m2465[2];
                                                                                                                              slog::join_probe<3,2>(Ndindex2157, std::array<u64,3>{v_c84, v_c91, 0}, [&](const std::array<u64,3>& m2466) {
                                                                                                                                u64 v_c92 = m2466[2];
                                                                                                                                slog::join_probe<3,2>(Ndindex2158, std::array<u64,3>{v_c77, v_c92, 0}, [&](const std::array<u64,3>& m2467) {
                                                                                                                                  u64 v_c93 = m2467[2];
                                                                                                                                  ++_fires;
                                                                                                                                  slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c32, v_c93}, std::array<u16,3>{2, 1, 0});
                                                                                                                                });
                                                                                                                              });
                                                                                                                            });
                                                                                                                          });
                                                                                                                        });
                                                                                                                      });
                                                                                                                    });
                                                                                                                  });
                                                                                                                });
                                                                                                              });
                                                                                                            });
                                                                                                          });
                                                                                                        });
                                                                                                      });
                                                                                                    });
                                                                                                  });
                                                                                                });
                                                                                              });
                                                                                            });
                                                                                          });
                                                                                        });
                                                                                      });
                                                                                    });
                                                                                  });
                                                                                });
                                                                              });
                                                                            });
                                                                          });
                                                                        });
                                                                      });
                                                                    });
                                                                  });
                                                                });
                                                              });
                                                            });
                                                          });
                                                        });
                                                      });
                                                    });
                                                  });
                                                });
                                              });
                                            });
                                          });
                                        });
                                      });
                                    });
                                  });
                                });
                              });
                            });
                          });
                        });
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
  
      if (_fires) db->bumpFires("deep_fact.slog:7", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask2159(db,b));
  // (crule (pre (let __tconst48SJ108 const6b86b273ff34fce19d6b804e) (let __tconst5Uhl106 constd4735e3a265e16eee03f5971) (let __tconst9YpM103 const4e07408562bedb8b60ce05c1) (let __tconst3iHp101 const4b227777d4dd1fc61c6f884f) (let __tconst0Emh97 constef2d127de37b942baad06145) (let __tconst29xA95 conste7f6c011776e8db7cd330b54) (let __tconst9mjQ92 const7902699be42c8a8e46fbbb45) (let __tconst9Yxv90 const2c624232cdd221771294dfbb) (let __tconst7wWY85 const19581e27de7ced00ff1ce50b) (let __tconst01Wl83 const4a44dc15364204a80fe80e90) (let __tconst42lR80 const4fc82b26aecb47d2868c4efb) (let __tconst3KyY78 const6b51d431df5d7f141cbececc) (let __tconst6a9N74 const3fdba35f04dc8c462986c992) (let __tconst74Qx72 const8527a891e224136950ff32ca) (let __tconst2hOw69 conste629fa6598d732768f7c726b) (let __tconst7kHD67 constb17ef6d19c7a5b1ee83b907c) (let __tconst5zmq61 const4523540f1504cd17100c4835) (let __tconst31qC59 const4ec9599fc203d176a301536c) (let __tconst4Vop56 const9400f1b21cb527d7fa3d3eab) (let __tconst51zc54 constf5ca38f748a1d6eaf726b8a4) (let __tconst6Qm150 const6f4b6612125fb3a0daecd279) (let __tconst6bEj48 const785f3ec7eb32f30b90cd0fcf) (let __tconst7AKN45 const535fa30d7e25dd8a49f15367) (let __tconst9j2a43 constc2356069e9d1e79ca9243781) (let __tconst1Mto38 constb7a56873cd771f2c446d369b) (let __tconst8u8i36 const5f9c4ab08cac7457e9111a30) (let __tconst2Isx33 const670671cd97404156226e5079) (let __tconst8J6R31 const59e19706d51d39f66711c265) (let __tconst88cs27 const35135aaa6cc23891b40cb3f3) (let __tconst0Uuf25 const624b60c58c9d8bfb6ff1886c) (let __tconst6sf622 consteb1e33e8a81b697b75855af6) (let __tconst5Run20 conste29c9c180c6279b0b02abd6a)) (scan Nd __t7LF824 __t1M8o23 __t8mDO21) (body (join Lf (0 1) 2 __t8mDO21 __tconst5Run20) (join Lf (0 1) 2 __t1M8o23 __tconst6sf622) (exists Lf (1 0) 1 __tconst88cs27) (exists Lf (1 0) 1 __tconst8J6R31) (exists Lf (1 0) 1 __tconst2Isx33) (exists Lf (1 0) 1 __tconst8u8i36) (exists Lf (1 0) 1 __tconst1Mto38) (exists Lf (1 0) 1 __tconst9j2a43) (exists Lf (1 0) 1 __tconst7AKN45) (exists Lf (1 0) 1 __tconst6bEj48) (exists Lf (1 0) 1 __tconst6Qm150) (exists Lf (1 0) 1 __tconst51zc54) (exists Lf (1 0) 1 __tconst4Vop56) (exists Lf (1 0) 1 __tconst31qC59) (exists Lf (1 0) 1 __tconst5zmq61) (exists Lf (1 0) 1 __tconst7kHD67) (exists Lf (1 0) 1 __tconst2hOw69) (exists Lf (1 0) 1 __tconst74Qx72) (exists Lf (1 0) 1 __tconst6a9N74) (exists Lf (1 0) 1 __tconst3KyY78) (exists Lf (1 0) 1 __tconst42lR80) (exists Lf (1 0) 1 __tconst01Wl83) (exists Lf (1 0) 1 __tconst7wWY85) (exists Lf (1 0) 1 __tconst9Yxv90) (exists Lf (1 0) 1 __tconst9mjQ92) (exists Lf (1 0) 1 __tconst29xA95) (exists Lf (1 0) 1 __tconst0Emh97) (exists Lf (1 0) 1 __tconst3iHp101) (exists Lf (1 0) 1 __tconst9YpM103) (exists Lf (1 0) 1 __tconst5Uhl106) (exists Lf (1 0) 1 __tconst48SJ108) (join Lf (1 0) 1 __tconst0Uuf25 __t1NQv26) (exists Nd (2 1 0) 1 __t1NQv26) (join Lf (1 0) 1 __tconst88cs27 __t7d0c28) (join Nd (2 1 0) 2 __t1NQv26 __t7d0c28 __t0kIY29) (join Lf (1 0) 1 __tconst8J6R31 __t9vh832) (exists Nd (2 1 0) 1 __t9vh832) (join Lf (1 0) 1 __tconst2Isx33 __t5flt34) (join Nd (2 1 0) 2 __t9vh832 __t5flt34 __t3jHg35) (join Lf (1 0) 1 __tconst8u8i36 __t27Zr37) (exists Nd (2 1 0) 1 __t27Zr37) (join Lf (1 0) 1 __tconst1Mto38 __t3UFu39) (join Nd (2 1 0) 2 __t27Zr37 __t3UFu39 __t8qqV40) (join Lf (1 0) 1 __tconst9j2a43 __t6IKq44) (exists Nd (2 1 0) 1 __t6IKq44) (join Lf (1 0) 1 __tconst7AKN45 __t6LIW46) (join Nd (2 1 0) 2 __t6IKq44 __t6LIW46 __t7C7d47) (join Lf (1 0) 1 __tconst6bEj48 __t9k7a49) (exists Nd (2 1 0) 1 __t9k7a49) (join Lf (1 0) 1 __tconst6Qm150 __t4MdC51) (join Nd (2 1 0) 2 __t9k7a49 __t4MdC51 __t8A9i52) (join Lf (1 0) 1 __tconst51zc54 __t3Yon55) (exists Nd (2 1 0) 1 __t3Yon55) (join Lf (1 0) 1 __tconst4Vop56 __t5ik157) (join Nd (2 1 0) 2 __t3Yon55 __t5ik157 __t4hi358) (join Lf (1 0) 1 __tconst31qC59 __t1nkJ60) (exists Nd (2 1 0) 1 __t1nkJ60) (join Lf (1 0) 1 __tconst5zmq61 __t4E3D62) (join Nd (2 1 0) 2 __t1nkJ60 __t4E3D62 __t8TXU63) (join Lf (1 0) 1 __tconst7kHD67 __t4J2N68) (exists Nd (2 1 0) 1 __t4J2N68) (join Lf (1 0) 1 __tconst2hOw69 __t4izo70) (join Nd (2 1 0) 2 __t4J2N68 __t4izo70 __t14Ff71) (join Lf (1 0) 1 __tconst74Qx72 __t319l73) (exists Nd (2 1 0) 1 __t319l73) (join Lf (1 0) 1 __tconst6a9N74 __t0amQ75) (join Nd (2 1 0) 2 __t319l73 __t0amQ75 __t4MUf76) (join Lf (1 0) 1 __tconst3KyY78 __t13gt79) (exists Nd (2 1 0) 1 __t13gt79) (join Lf (1 0) 1 __tconst42lR80 __t3ESz81) (join Nd (2 1 0) 2 __t13gt79 __t3ESz81 __t3WL082) (join Lf (1 0) 1 __tconst01Wl83 __t4Da384) (exists Nd (2 1 0) 1 __t4Da384) (join Lf (1 0) 1 __tconst7wWY85 __t91gs86) (join Nd (2 1 0) 2 __t4Da384 __t91gs86 __t02Bu87) (join Lf (1 0) 1 __tconst9Yxv90 __t7UaH91) (exists Nd (2 1 0) 1 __t7UaH91) (join Lf (1 0) 1 __tconst9mjQ92 __t6IMg93) (join Nd (2 1 0) 2 __t7UaH91 __t6IMg93 __t2T3i94) (join Lf (1 0) 1 __tconst29xA95 __t2oHE96) (exists Nd (2 1 0) 1 __t2oHE96) (join Lf (1 0) 1 __tconst0Emh97 __t7bue98) (join Nd (2 1 0) 2 __t2oHE96 __t7bue98 __t0HkS99) (join Lf (1 0) 1 __tconst3iHp101 __t5yzC102) (exists Nd (2 1 0) 1 __t5yzC102) (join Lf (1 0) 1 __tconst9YpM103 __t7c21104) (join Nd (2 1 0) 2 __t5yzC102 __t7c21104 __t4bRV105) (join Lf (1 0) 1 __tconst5Uhl106 __t1IJA107) (exists Nd (2 1 0) 1 __t1IJA107) (join Lf (1 0) 1 __tconst48SJ108 __t0y5t109) (join Nd (2 1 0) 2 __t1IJA107 __t0y5t109 __t76VS110)) (head (mkstruct Nd (2 1 0) __t3a3T111 __t4bRV105 __t76VS110) (mkstruct Nd (2 1 0) __t7PLp100 __t2T3i94 __t0HkS99) (mkstruct Nd (2 1 0) __t60KJ88 __t3WL082 __t02Bu87) (mkstruct Nd (2 1 0) __t13Wj77 __t14Ff71 __t4MUf76) (mkstruct Nd (2 1 0) __t6bZq64 __t4hi358 __t8TXU63) (mkstruct Nd (2 1 0) __t7DSY53 __t7C7d47 __t8A9i52) (mkstruct Nd (2 1 0) __t2KtK41 __t3jHg35 __t8qqV40) (mkstruct Nd (2 1 0) __t6JrG30 __t7LF824 __t0kIY29)) deep_fact.slog:7 #f)
  class ReadTask2559 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[8];
    slog::Index** head_index[8];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** Lfindex2468;  slog::Index** Lfindex2469;  slog::Index** Lfindex2470;  slog::Index** Lfindex2471;  slog::Index** Lfindex2472;  slog::Index** Lfindex2473;  slog::Index** Lfindex2474;  slog::Index** Lfindex2475;  slog::Index** Lfindex2476;  slog::Index** Lfindex2477;  slog::Index** Lfindex2478;  slog::Index** Lfindex2479;  slog::Index** Lfindex2480;  slog::Index** Lfindex2481;  slog::Index** Lfindex2482;  slog::Index** Lfindex2483;  slog::Index** Lfindex2484;  slog::Index** Lfindex2485;  slog::Index** Lfindex2486;  slog::Index** Lfindex2487;  slog::Index** Lfindex2488;  slog::Index** Lfindex2489;  slog::Index** Lfindex2490;  slog::Index** Lfindex2491;  slog::Index** Lfindex2492;  slog::Index** Lfindex2493;  slog::Index** Lfindex2494;  slog::Index** Lfindex2495;  slog::Index** Lfindex2496;  slog::Index** Lfindex2497;  slog::Index** Lfindex2498;  slog::Index** Lfindex2499;  slog::Index** Ndindex2500;  slog::Index** Lfindex2501;  slog::Index** Ndindex2502;  slog::Index** Lfindex2503;  slog::Index** Ndindex2504;  slog::Index** Lfindex2505;  slog::Index** Ndindex2506;  slog::Index** Lfindex2507;  slog::Index** Ndindex2508;  slog::Index** Lfindex2509;  slog::Index** Ndindex2510;  slog::Index** Lfindex2511;  slog::Index** Ndindex2512;  slog::Index** Lfindex2513;  slog::Index** Ndindex2514;  slog::Index** Lfindex2515;  slog::Index** Ndindex2516;  slog::Index** Lfindex2517;  slog::Index** Ndindex2518;  slog::Index** Lfindex2519;  slog::Index** Ndindex2520;  slog::Index** Lfindex2521;  slog::Index** Ndindex2522;  slog::Index** Lfindex2523;  slog::Index** Ndindex2524;  slog::Index** Lfindex2525;  slog::Index** Ndindex2526;  slog::Index** Lfindex2527;  slog::Index** Ndindex2528;  slog::Index** Lfindex2529;  slog::Index** Ndindex2530;  slog::Index** Lfindex2531;  slog::Index** Ndindex2532;  slog::Index** Lfindex2533;  slog::Index** Ndindex2534;  slog::Index** Lfindex2535;  slog::Index** Ndindex2536;  slog::Index** Lfindex2537;  slog::Index** Ndindex2538;  slog::Index** Lfindex2539;  slog::Index** Ndindex2540;  slog::Index** Lfindex2541;  slog::Index** Ndindex2542;  slog::Index** Lfindex2543;  slog::Index** Ndindex2544;  slog::Index** Lfindex2545;  slog::Index** Ndindex2546;  slog::Index** Lfindex2547;  slog::Index** Ndindex2548;  slog::Index** Lfindex2549;  slog::Index** Ndindex2550;  slog::Index** Lfindex2551;  slog::Index** Ndindex2552;  slog::Index** Lfindex2553;  slog::Index** Ndindex2554;  slog::Index** Lfindex2555;  slog::Index** Ndindex2556;  slog::Index** Lfindex2557;  slog::Index** Ndindex2558;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("Nd");
      head_rel[1] = db->getRelation("Nd");
      head_rel[2] = db->getRelation("Nd");
      head_rel[3] = db->getRelation("Nd");
      head_rel[4] = db->getRelation("Nd");
      head_rel[5] = db->getRelation("Nd");
      head_rel[6] = db->getRelation("Nd");
      head_rel[7] = db->getRelation("Nd");
      outer_rel = db->getRelation("Nd");
      std::vector<u16> ord2560({0, 1});
      slog::Relation* readrel2561 = db->getRelation("Lf");
      Lfindex2468 = readrel2561->getIndex(ord2560, false);
      std::vector<u16> ord2562({0, 1});
      slog::Relation* readrel2563 = db->getRelation("Lf");
      Lfindex2469 = readrel2563->getIndex(ord2562, false);
      std::vector<u16> ord2564({1, 0});
      slog::Relation* readrel2565 = db->getRelation("Lf");
      Lfindex2470 = readrel2565->getIndex(ord2564, false);
      std::vector<u16> ord2566({1, 0});
      slog::Relation* readrel2567 = db->getRelation("Lf");
      Lfindex2471 = readrel2567->getIndex(ord2566, false);
      std::vector<u16> ord2568({1, 0});
      slog::Relation* readrel2569 = db->getRelation("Lf");
      Lfindex2472 = readrel2569->getIndex(ord2568, false);
      std::vector<u16> ord2570({1, 0});
      slog::Relation* readrel2571 = db->getRelation("Lf");
      Lfindex2473 = readrel2571->getIndex(ord2570, false);
      std::vector<u16> ord2572({1, 0});
      slog::Relation* readrel2573 = db->getRelation("Lf");
      Lfindex2474 = readrel2573->getIndex(ord2572, false);
      std::vector<u16> ord2574({1, 0});
      slog::Relation* readrel2575 = db->getRelation("Lf");
      Lfindex2475 = readrel2575->getIndex(ord2574, false);
      std::vector<u16> ord2576({1, 0});
      slog::Relation* readrel2577 = db->getRelation("Lf");
      Lfindex2476 = readrel2577->getIndex(ord2576, false);
      std::vector<u16> ord2578({1, 0});
      slog::Relation* readrel2579 = db->getRelation("Lf");
      Lfindex2477 = readrel2579->getIndex(ord2578, false);
      std::vector<u16> ord2580({1, 0});
      slog::Relation* readrel2581 = db->getRelation("Lf");
      Lfindex2478 = readrel2581->getIndex(ord2580, false);
      std::vector<u16> ord2582({1, 0});
      slog::Relation* readrel2583 = db->getRelation("Lf");
      Lfindex2479 = readrel2583->getIndex(ord2582, false);
      std::vector<u16> ord2584({1, 0});
      slog::Relation* readrel2585 = db->getRelation("Lf");
      Lfindex2480 = readrel2585->getIndex(ord2584, false);
      std::vector<u16> ord2586({1, 0});
      slog::Relation* readrel2587 = db->getRelation("Lf");
      Lfindex2481 = readrel2587->getIndex(ord2586, false);
      std::vector<u16> ord2588({1, 0});
      slog::Relation* readrel2589 = db->getRelation("Lf");
      Lfindex2482 = readrel2589->getIndex(ord2588, false);
      std::vector<u16> ord2590({1, 0});
      slog::Relation* readrel2591 = db->getRelation("Lf");
      Lfindex2483 = readrel2591->getIndex(ord2590, false);
      std::vector<u16> ord2592({1, 0});
      slog::Relation* readrel2593 = db->getRelation("Lf");
      Lfindex2484 = readrel2593->getIndex(ord2592, false);
      std::vector<u16> ord2594({1, 0});
      slog::Relation* readrel2595 = db->getRelation("Lf");
      Lfindex2485 = readrel2595->getIndex(ord2594, false);
      std::vector<u16> ord2596({1, 0});
      slog::Relation* readrel2597 = db->getRelation("Lf");
      Lfindex2486 = readrel2597->getIndex(ord2596, false);
      std::vector<u16> ord2598({1, 0});
      slog::Relation* readrel2599 = db->getRelation("Lf");
      Lfindex2487 = readrel2599->getIndex(ord2598, false);
      std::vector<u16> ord2600({1, 0});
      slog::Relation* readrel2601 = db->getRelation("Lf");
      Lfindex2488 = readrel2601->getIndex(ord2600, false);
      std::vector<u16> ord2602({1, 0});
      slog::Relation* readrel2603 = db->getRelation("Lf");
      Lfindex2489 = readrel2603->getIndex(ord2602, false);
      std::vector<u16> ord2604({1, 0});
      slog::Relation* readrel2605 = db->getRelation("Lf");
      Lfindex2490 = readrel2605->getIndex(ord2604, false);
      std::vector<u16> ord2606({1, 0});
      slog::Relation* readrel2607 = db->getRelation("Lf");
      Lfindex2491 = readrel2607->getIndex(ord2606, false);
      std::vector<u16> ord2608({1, 0});
      slog::Relation* readrel2609 = db->getRelation("Lf");
      Lfindex2492 = readrel2609->getIndex(ord2608, false);
      std::vector<u16> ord2610({1, 0});
      slog::Relation* readrel2611 = db->getRelation("Lf");
      Lfindex2493 = readrel2611->getIndex(ord2610, false);
      std::vector<u16> ord2612({1, 0});
      slog::Relation* readrel2613 = db->getRelation("Lf");
      Lfindex2494 = readrel2613->getIndex(ord2612, false);
      std::vector<u16> ord2614({1, 0});
      slog::Relation* readrel2615 = db->getRelation("Lf");
      Lfindex2495 = readrel2615->getIndex(ord2614, false);
      std::vector<u16> ord2616({1, 0});
      slog::Relation* readrel2617 = db->getRelation("Lf");
      Lfindex2496 = readrel2617->getIndex(ord2616, false);
      std::vector<u16> ord2618({1, 0});
      slog::Relation* readrel2619 = db->getRelation("Lf");
      Lfindex2497 = readrel2619->getIndex(ord2618, false);
      std::vector<u16> ord2620({1, 0});
      slog::Relation* readrel2621 = db->getRelation("Lf");
      Lfindex2498 = readrel2621->getIndex(ord2620, false);
      std::vector<u16> ord2622({1, 0});
      slog::Relation* readrel2623 = db->getRelation("Lf");
      Lfindex2499 = readrel2623->getIndex(ord2622, false);
      std::vector<u16> ord2624({2, 1, 0});
      slog::Relation* readrel2625 = db->getRelation("Nd");
      Ndindex2500 = readrel2625->getIndex(ord2624, false);
      std::vector<u16> ord2626({1, 0});
      slog::Relation* readrel2627 = db->getRelation("Lf");
      Lfindex2501 = readrel2627->getIndex(ord2626, false);
      std::vector<u16> ord2628({2, 1, 0});
      slog::Relation* readrel2629 = db->getRelation("Nd");
      Ndindex2502 = readrel2629->getIndex(ord2628, false);
      std::vector<u16> ord2630({1, 0});
      slog::Relation* readrel2631 = db->getRelation("Lf");
      Lfindex2503 = readrel2631->getIndex(ord2630, false);
      std::vector<u16> ord2632({2, 1, 0});
      slog::Relation* readrel2633 = db->getRelation("Nd");
      Ndindex2504 = readrel2633->getIndex(ord2632, false);
      std::vector<u16> ord2634({1, 0});
      slog::Relation* readrel2635 = db->getRelation("Lf");
      Lfindex2505 = readrel2635->getIndex(ord2634, false);
      std::vector<u16> ord2636({2, 1, 0});
      slog::Relation* readrel2637 = db->getRelation("Nd");
      Ndindex2506 = readrel2637->getIndex(ord2636, false);
      std::vector<u16> ord2638({1, 0});
      slog::Relation* readrel2639 = db->getRelation("Lf");
      Lfindex2507 = readrel2639->getIndex(ord2638, false);
      std::vector<u16> ord2640({2, 1, 0});
      slog::Relation* readrel2641 = db->getRelation("Nd");
      Ndindex2508 = readrel2641->getIndex(ord2640, false);
      std::vector<u16> ord2642({1, 0});
      slog::Relation* readrel2643 = db->getRelation("Lf");
      Lfindex2509 = readrel2643->getIndex(ord2642, false);
      std::vector<u16> ord2644({2, 1, 0});
      slog::Relation* readrel2645 = db->getRelation("Nd");
      Ndindex2510 = readrel2645->getIndex(ord2644, false);
      std::vector<u16> ord2646({1, 0});
      slog::Relation* readrel2647 = db->getRelation("Lf");
      Lfindex2511 = readrel2647->getIndex(ord2646, false);
      std::vector<u16> ord2648({2, 1, 0});
      slog::Relation* readrel2649 = db->getRelation("Nd");
      Ndindex2512 = readrel2649->getIndex(ord2648, false);
      std::vector<u16> ord2650({1, 0});
      slog::Relation* readrel2651 = db->getRelation("Lf");
      Lfindex2513 = readrel2651->getIndex(ord2650, false);
      std::vector<u16> ord2652({2, 1, 0});
      slog::Relation* readrel2653 = db->getRelation("Nd");
      Ndindex2514 = readrel2653->getIndex(ord2652, false);
      std::vector<u16> ord2654({1, 0});
      slog::Relation* readrel2655 = db->getRelation("Lf");
      Lfindex2515 = readrel2655->getIndex(ord2654, false);
      std::vector<u16> ord2656({2, 1, 0});
      slog::Relation* readrel2657 = db->getRelation("Nd");
      Ndindex2516 = readrel2657->getIndex(ord2656, false);
      std::vector<u16> ord2658({1, 0});
      slog::Relation* readrel2659 = db->getRelation("Lf");
      Lfindex2517 = readrel2659->getIndex(ord2658, false);
      std::vector<u16> ord2660({2, 1, 0});
      slog::Relation* readrel2661 = db->getRelation("Nd");
      Ndindex2518 = readrel2661->getIndex(ord2660, false);
      std::vector<u16> ord2662({1, 0});
      slog::Relation* readrel2663 = db->getRelation("Lf");
      Lfindex2519 = readrel2663->getIndex(ord2662, false);
      std::vector<u16> ord2664({2, 1, 0});
      slog::Relation* readrel2665 = db->getRelation("Nd");
      Ndindex2520 = readrel2665->getIndex(ord2664, false);
      std::vector<u16> ord2666({1, 0});
      slog::Relation* readrel2667 = db->getRelation("Lf");
      Lfindex2521 = readrel2667->getIndex(ord2666, false);
      std::vector<u16> ord2668({2, 1, 0});
      slog::Relation* readrel2669 = db->getRelation("Nd");
      Ndindex2522 = readrel2669->getIndex(ord2668, false);
      std::vector<u16> ord2670({1, 0});
      slog::Relation* readrel2671 = db->getRelation("Lf");
      Lfindex2523 = readrel2671->getIndex(ord2670, false);
      std::vector<u16> ord2672({2, 1, 0});
      slog::Relation* readrel2673 = db->getRelation("Nd");
      Ndindex2524 = readrel2673->getIndex(ord2672, false);
      std::vector<u16> ord2674({1, 0});
      slog::Relation* readrel2675 = db->getRelation("Lf");
      Lfindex2525 = readrel2675->getIndex(ord2674, false);
      std::vector<u16> ord2676({2, 1, 0});
      slog::Relation* readrel2677 = db->getRelation("Nd");
      Ndindex2526 = readrel2677->getIndex(ord2676, false);
      std::vector<u16> ord2678({1, 0});
      slog::Relation* readrel2679 = db->getRelation("Lf");
      Lfindex2527 = readrel2679->getIndex(ord2678, false);
      std::vector<u16> ord2680({2, 1, 0});
      slog::Relation* readrel2681 = db->getRelation("Nd");
      Ndindex2528 = readrel2681->getIndex(ord2680, false);
      std::vector<u16> ord2682({1, 0});
      slog::Relation* readrel2683 = db->getRelation("Lf");
      Lfindex2529 = readrel2683->getIndex(ord2682, false);
      std::vector<u16> ord2684({2, 1, 0});
      slog::Relation* readrel2685 = db->getRelation("Nd");
      Ndindex2530 = readrel2685->getIndex(ord2684, false);
      std::vector<u16> ord2686({1, 0});
      slog::Relation* readrel2687 = db->getRelation("Lf");
      Lfindex2531 = readrel2687->getIndex(ord2686, false);
      std::vector<u16> ord2688({2, 1, 0});
      slog::Relation* readrel2689 = db->getRelation("Nd");
      Ndindex2532 = readrel2689->getIndex(ord2688, false);
      std::vector<u16> ord2690({1, 0});
      slog::Relation* readrel2691 = db->getRelation("Lf");
      Lfindex2533 = readrel2691->getIndex(ord2690, false);
      std::vector<u16> ord2692({2, 1, 0});
      slog::Relation* readrel2693 = db->getRelation("Nd");
      Ndindex2534 = readrel2693->getIndex(ord2692, false);
      std::vector<u16> ord2694({1, 0});
      slog::Relation* readrel2695 = db->getRelation("Lf");
      Lfindex2535 = readrel2695->getIndex(ord2694, false);
      std::vector<u16> ord2696({2, 1, 0});
      slog::Relation* readrel2697 = db->getRelation("Nd");
      Ndindex2536 = readrel2697->getIndex(ord2696, false);
      std::vector<u16> ord2698({1, 0});
      slog::Relation* readrel2699 = db->getRelation("Lf");
      Lfindex2537 = readrel2699->getIndex(ord2698, false);
      std::vector<u16> ord2700({2, 1, 0});
      slog::Relation* readrel2701 = db->getRelation("Nd");
      Ndindex2538 = readrel2701->getIndex(ord2700, false);
      std::vector<u16> ord2702({1, 0});
      slog::Relation* readrel2703 = db->getRelation("Lf");
      Lfindex2539 = readrel2703->getIndex(ord2702, false);
      std::vector<u16> ord2704({2, 1, 0});
      slog::Relation* readrel2705 = db->getRelation("Nd");
      Ndindex2540 = readrel2705->getIndex(ord2704, false);
      std::vector<u16> ord2706({1, 0});
      slog::Relation* readrel2707 = db->getRelation("Lf");
      Lfindex2541 = readrel2707->getIndex(ord2706, false);
      std::vector<u16> ord2708({2, 1, 0});
      slog::Relation* readrel2709 = db->getRelation("Nd");
      Ndindex2542 = readrel2709->getIndex(ord2708, false);
      std::vector<u16> ord2710({1, 0});
      slog::Relation* readrel2711 = db->getRelation("Lf");
      Lfindex2543 = readrel2711->getIndex(ord2710, false);
      std::vector<u16> ord2712({2, 1, 0});
      slog::Relation* readrel2713 = db->getRelation("Nd");
      Ndindex2544 = readrel2713->getIndex(ord2712, false);
      std::vector<u16> ord2714({1, 0});
      slog::Relation* readrel2715 = db->getRelation("Lf");
      Lfindex2545 = readrel2715->getIndex(ord2714, false);
      std::vector<u16> ord2716({2, 1, 0});
      slog::Relation* readrel2717 = db->getRelation("Nd");
      Ndindex2546 = readrel2717->getIndex(ord2716, false);
      std::vector<u16> ord2718({1, 0});
      slog::Relation* readrel2719 = db->getRelation("Lf");
      Lfindex2547 = readrel2719->getIndex(ord2718, false);
      std::vector<u16> ord2720({2, 1, 0});
      slog::Relation* readrel2721 = db->getRelation("Nd");
      Ndindex2548 = readrel2721->getIndex(ord2720, false);
      std::vector<u16> ord2722({1, 0});
      slog::Relation* readrel2723 = db->getRelation("Lf");
      Lfindex2549 = readrel2723->getIndex(ord2722, false);
      std::vector<u16> ord2724({2, 1, 0});
      slog::Relation* readrel2725 = db->getRelation("Nd");
      Ndindex2550 = readrel2725->getIndex(ord2724, false);
      std::vector<u16> ord2726({1, 0});
      slog::Relation* readrel2727 = db->getRelation("Lf");
      Lfindex2551 = readrel2727->getIndex(ord2726, false);
      std::vector<u16> ord2728({2, 1, 0});
      slog::Relation* readrel2729 = db->getRelation("Nd");
      Ndindex2552 = readrel2729->getIndex(ord2728, false);
      std::vector<u16> ord2730({1, 0});
      slog::Relation* readrel2731 = db->getRelation("Lf");
      Lfindex2553 = readrel2731->getIndex(ord2730, false);
      std::vector<u16> ord2732({2, 1, 0});
      slog::Relation* readrel2733 = db->getRelation("Nd");
      Ndindex2554 = readrel2733->getIndex(ord2732, false);
      std::vector<u16> ord2734({1, 0});
      slog::Relation* readrel2735 = db->getRelation("Lf");
      Lfindex2555 = readrel2735->getIndex(ord2734, false);
      std::vector<u16> ord2736({2, 1, 0});
      slog::Relation* readrel2737 = db->getRelation("Nd");
      Ndindex2556 = readrel2737->getIndex(ord2736, false);
      std::vector<u16> ord2738({1, 0});
      slog::Relation* readrel2739 = db->getRelation("Lf");
      Lfindex2557 = readrel2739->getIndex(ord2738, false);
      std::vector<u16> ord2740({2, 1, 0});
      slog::Relation* readrel2741 = db->getRelation("Nd");
      Ndindex2558 = readrel2741->getIndex(ord2740, false);
  
    }
    ReadTask2559(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c37 = _t[0];
        u64 v_c36 = _t[1];
        u64 v_c35 = _t[2];
        slog::join_probe<2,2>(Lfindex2468, std::array<u64,2>{v_c35, v_c31}, [&](const std::array<u64,2>& m2742) {
          slog::join_probe<2,2>(Lfindex2469, std::array<u64,2>{v_c36, v_c30}, [&](const std::array<u64,2>& m2743) {
            if (!slog::exists_probe<2,1>(Lfindex2470, std::array<u64,2>{v_c28, 0})) return;
            if (!slog::exists_probe<2,1>(Lfindex2471, std::array<u64,2>{v_c27, 0})) return;
            if (!slog::exists_probe<2,1>(Lfindex2472, std::array<u64,2>{v_c26, 0})) return;
            if (!slog::exists_probe<2,1>(Lfindex2473, std::array<u64,2>{v_c25, 0})) return;
            if (!slog::exists_probe<2,1>(Lfindex2474, std::array<u64,2>{v_c24, 0})) return;
            if (!slog::exists_probe<2,1>(Lfindex2475, std::array<u64,2>{v_c23, 0})) return;
            if (!slog::exists_probe<2,1>(Lfindex2476, std::array<u64,2>{v_c22, 0})) return;
            if (!slog::exists_probe<2,1>(Lfindex2477, std::array<u64,2>{v_c21, 0})) return;
            if (!slog::exists_probe<2,1>(Lfindex2478, std::array<u64,2>{v_c20, 0})) return;
            if (!slog::exists_probe<2,1>(Lfindex2479, std::array<u64,2>{v_c19, 0})) return;
            if (!slog::exists_probe<2,1>(Lfindex2480, std::array<u64,2>{v_c18, 0})) return;
            if (!slog::exists_probe<2,1>(Lfindex2481, std::array<u64,2>{v_c17, 0})) return;
            if (!slog::exists_probe<2,1>(Lfindex2482, std::array<u64,2>{v_c16, 0})) return;
            if (!slog::exists_probe<2,1>(Lfindex2483, std::array<u64,2>{v_c15, 0})) return;
            if (!slog::exists_probe<2,1>(Lfindex2484, std::array<u64,2>{v_c14, 0})) return;
            if (!slog::exists_probe<2,1>(Lfindex2485, std::array<u64,2>{v_c13, 0})) return;
            if (!slog::exists_probe<2,1>(Lfindex2486, std::array<u64,2>{v_c12, 0})) return;
            if (!slog::exists_probe<2,1>(Lfindex2487, std::array<u64,2>{v_c11, 0})) return;
            if (!slog::exists_probe<2,1>(Lfindex2488, std::array<u64,2>{v_c10, 0})) return;
            if (!slog::exists_probe<2,1>(Lfindex2489, std::array<u64,2>{v_c9, 0})) return;
            if (!slog::exists_probe<2,1>(Lfindex2490, std::array<u64,2>{v_c8, 0})) return;
            if (!slog::exists_probe<2,1>(Lfindex2491, std::array<u64,2>{v_c7, 0})) return;
            if (!slog::exists_probe<2,1>(Lfindex2492, std::array<u64,2>{v_c6, 0})) return;
            if (!slog::exists_probe<2,1>(Lfindex2493, std::array<u64,2>{v_c5, 0})) return;
            if (!slog::exists_probe<2,1>(Lfindex2494, std::array<u64,2>{v_c4, 0})) return;
            if (!slog::exists_probe<2,1>(Lfindex2495, std::array<u64,2>{v_c3, 0})) return;
            if (!slog::exists_probe<2,1>(Lfindex2496, std::array<u64,2>{v_c2, 0})) return;
            if (!slog::exists_probe<2,1>(Lfindex2497, std::array<u64,2>{v_c1, 0})) return;
            if (!slog::exists_probe<2,1>(Lfindex2498, std::array<u64,2>{v_c0, 0})) return;
            slog::join_probe<2,1>(Lfindex2499, std::array<u64,2>{v_c29, 0}, [&](const std::array<u64,2>& m2744) {
              u64 v_c38 = m2744[1];
              if (!slog::exists_probe<3,1>(Ndindex2500, std::array<u64,3>{v_c38, 0, 0})) return;
              slog::join_probe<2,1>(Lfindex2501, std::array<u64,2>{v_c28, 0}, [&](const std::array<u64,2>& m2745) {
                u64 v_c39 = m2745[1];
                slog::join_probe<3,2>(Ndindex2502, std::array<u64,3>{v_c38, v_c39, 0}, [&](const std::array<u64,3>& m2746) {
                  u64 v_c40 = m2746[2];
                  slog::join_probe<2,1>(Lfindex2503, std::array<u64,2>{v_c27, 0}, [&](const std::array<u64,2>& m2747) {
                    u64 v_c43 = m2747[1];
                    if (!slog::exists_probe<3,1>(Ndindex2504, std::array<u64,3>{v_c43, 0, 0})) return;
                    slog::join_probe<2,1>(Lfindex2505, std::array<u64,2>{v_c26, 0}, [&](const std::array<u64,2>& m2748) {
                      u64 v_c44 = m2748[1];
                      slog::join_probe<3,2>(Ndindex2506, std::array<u64,3>{v_c43, v_c44, 0}, [&](const std::array<u64,3>& m2749) {
                        u64 v_c45 = m2749[2];
                        slog::join_probe<2,1>(Lfindex2507, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m2750) {
                          u64 v_c47 = m2750[1];
                          if (!slog::exists_probe<3,1>(Ndindex2508, std::array<u64,3>{v_c47, 0, 0})) return;
                          slog::join_probe<2,1>(Lfindex2509, std::array<u64,2>{v_c24, 0}, [&](const std::array<u64,2>& m2751) {
                            u64 v_c48 = m2751[1];
                            slog::join_probe<3,2>(Ndindex2510, std::array<u64,3>{v_c47, v_c48, 0}, [&](const std::array<u64,3>& m2752) {
                              u64 v_c46 = m2752[2];
                              slog::join_probe<2,1>(Lfindex2511, std::array<u64,2>{v_c23, 0}, [&](const std::array<u64,2>& m2753) {
                                u64 v_c49 = m2753[1];
                                if (!slog::exists_probe<3,1>(Ndindex2512, std::array<u64,3>{v_c49, 0, 0})) return;
                                slog::join_probe<2,1>(Lfindex2513, std::array<u64,2>{v_c22, 0}, [&](const std::array<u64,2>& m2754) {
                                  u64 v_c50 = m2754[1];
                                  slog::join_probe<3,2>(Ndindex2514, std::array<u64,3>{v_c49, v_c50, 0}, [&](const std::array<u64,3>& m2755) {
                                    u64 v_c51 = m2755[2];
                                    slog::join_probe<2,1>(Lfindex2515, std::array<u64,2>{v_c21, 0}, [&](const std::array<u64,2>& m2756) {
                                      u64 v_c52 = m2756[1];
                                      if (!slog::exists_probe<3,1>(Ndindex2516, std::array<u64,3>{v_c52, 0, 0})) return;
                                      slog::join_probe<2,1>(Lfindex2517, std::array<u64,2>{v_c20, 0}, [&](const std::array<u64,2>& m2757) {
                                        u64 v_c53 = m2757[1];
                                        slog::join_probe<3,2>(Ndindex2518, std::array<u64,3>{v_c52, v_c53, 0}, [&](const std::array<u64,3>& m2758) {
                                          u64 v_c54 = m2758[2];
                                          slog::join_probe<2,1>(Lfindex2519, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m2759) {
                                            u64 v_c57 = m2759[1];
                                            if (!slog::exists_probe<3,1>(Ndindex2520, std::array<u64,3>{v_c57, 0, 0})) return;
                                            slog::join_probe<2,1>(Lfindex2521, std::array<u64,2>{v_c18, 0}, [&](const std::array<u64,2>& m2760) {
                                              u64 v_c58 = m2760[1];
                                              slog::join_probe<3,2>(Ndindex2522, std::array<u64,3>{v_c57, v_c58, 0}, [&](const std::array<u64,3>& m2761) {
                                                u64 v_c59 = m2761[2];
                                                slog::join_probe<2,1>(Lfindex2523, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m2762) {
                                                  u64 v_c61 = m2762[1];
                                                  if (!slog::exists_probe<3,1>(Ndindex2524, std::array<u64,3>{v_c61, 0, 0})) return;
                                                  slog::join_probe<2,1>(Lfindex2525, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m2763) {
                                                    u64 v_c62 = m2763[1];
                                                    slog::join_probe<3,2>(Ndindex2526, std::array<u64,3>{v_c61, v_c62, 0}, [&](const std::array<u64,3>& m2764) {
                                                      u64 v_c60 = m2764[2];
                                                      slog::join_probe<2,1>(Lfindex2527, std::array<u64,2>{v_c15, 0}, [&](const std::array<u64,2>& m2765) {
                                                        u64 v_c63 = m2765[1];
                                                        if (!slog::exists_probe<3,1>(Ndindex2528, std::array<u64,3>{v_c63, 0, 0})) return;
                                                        slog::join_probe<2,1>(Lfindex2529, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m2766) {
                                                          u64 v_c64 = m2766[1];
                                                          slog::join_probe<3,2>(Ndindex2530, std::array<u64,3>{v_c63, v_c64, 0}, [&](const std::array<u64,3>& m2767) {
                                                            u64 v_c65 = m2767[2];
                                                            slog::join_probe<2,1>(Lfindex2531, std::array<u64,2>{v_c13, 0}, [&](const std::array<u64,2>& m2768) {
                                                              u64 v_c66 = m2768[1];
                                                              if (!slog::exists_probe<3,1>(Ndindex2532, std::array<u64,3>{v_c66, 0, 0})) return;
                                                              slog::join_probe<2,1>(Lfindex2533, std::array<u64,2>{v_c12, 0}, [&](const std::array<u64,2>& m2769) {
                                                                u64 v_c67 = m2769[1];
                                                                slog::join_probe<3,2>(Ndindex2534, std::array<u64,3>{v_c66, v_c67, 0}, [&](const std::array<u64,3>& m2770) {
                                                                  u64 v_c68 = m2770[2];
                                                                  slog::join_probe<2,1>(Lfindex2535, std::array<u64,2>{v_c11, 0}, [&](const std::array<u64,2>& m2771) {
                                                                    u64 v_c70 = m2771[1];
                                                                    if (!slog::exists_probe<3,1>(Ndindex2536, std::array<u64,3>{v_c70, 0, 0})) return;
                                                                    slog::join_probe<2,1>(Lfindex2537, std::array<u64,2>{v_c10, 0}, [&](const std::array<u64,2>& m2772) {
                                                                      u64 v_c71 = m2772[1];
                                                                      slog::join_probe<3,2>(Ndindex2538, std::array<u64,3>{v_c70, v_c71, 0}, [&](const std::array<u64,3>& m2773) {
                                                                        u64 v_c72 = m2773[2];
                                                                        slog::join_probe<2,1>(Lfindex2539, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m2774) {
                                                                          u64 v_c73 = m2774[1];
                                                                          if (!slog::exists_probe<3,1>(Ndindex2540, std::array<u64,3>{v_c73, 0, 0})) return;
                                                                          slog::join_probe<2,1>(Lfindex2541, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m2775) {
                                                                            u64 v_c74 = m2775[1];
                                                                            slog::join_probe<3,2>(Ndindex2542, std::array<u64,3>{v_c73, v_c74, 0}, [&](const std::array<u64,3>& m2776) {
                                                                              u64 v_c75 = m2776[2];
                                                                              slog::join_probe<2,1>(Lfindex2543, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m2777) {
                                                                                u64 v_c78 = m2777[1];
                                                                                if (!slog::exists_probe<3,1>(Ndindex2544, std::array<u64,3>{v_c78, 0, 0})) return;
                                                                                slog::join_probe<2,1>(Lfindex2545, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m2778) {
                                                                                  u64 v_c79 = m2778[1];
                                                                                  slog::join_probe<3,2>(Ndindex2546, std::array<u64,3>{v_c78, v_c79, 0}, [&](const std::array<u64,3>& m2779) {
                                                                                    u64 v_c80 = m2779[2];
                                                                                    slog::join_probe<2,1>(Lfindex2547, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m2780) {
                                                                                      u64 v_c81 = m2780[1];
                                                                                      if (!slog::exists_probe<3,1>(Ndindex2548, std::array<u64,3>{v_c81, 0, 0})) return;
                                                                                      slog::join_probe<2,1>(Lfindex2549, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m2781) {
                                                                                        u64 v_c82 = m2781[1];
                                                                                        slog::join_probe<3,2>(Ndindex2550, std::array<u64,3>{v_c81, v_c82, 0}, [&](const std::array<u64,3>& m2782) {
                                                                                          u64 v_c83 = m2782[2];
                                                                                          slog::join_probe<2,1>(Lfindex2551, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m2783) {
                                                                                            u64 v_c85 = m2783[1];
                                                                                            if (!slog::exists_probe<3,1>(Ndindex2552, std::array<u64,3>{v_c85, 0, 0})) return;
                                                                                            slog::join_probe<2,1>(Lfindex2553, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m2784) {
                                                                                              u64 v_c86 = m2784[1];
                                                                                              slog::join_probe<3,2>(Ndindex2554, std::array<u64,3>{v_c85, v_c86, 0}, [&](const std::array<u64,3>& m2785) {
                                                                                                u64 v_c87 = m2785[2];
                                                                                                slog::join_probe<2,1>(Lfindex2555, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m2786) {
                                                                                                  u64 v_c88 = m2786[1];
                                                                                                  if (!slog::exists_probe<3,1>(Ndindex2556, std::array<u64,3>{v_c88, 0, 0})) return;
                                                                                                  slog::join_probe<2,1>(Lfindex2557, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m2787) {
                                                                                                    u64 v_c89 = m2787[1];
                                                                                                    slog::join_probe<3,2>(Ndindex2558, std::array<u64,3>{v_c88, v_c89, 0}, [&](const std::array<u64,3>& m2788) {
                                                                                                      u64 v_c90 = m2788[2];
                                                                                                      ++_fires;
                                                                                                      slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c87, v_c90}, std::array<u16,3>{2, 1, 0});
                                                                                                      slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c80, v_c83}, std::array<u16,3>{2, 1, 0});
                                                                                                      slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c72, v_c75}, std::array<u16,3>{2, 1, 0});
                                                                                                      slog::emit_struct<3>(head_rel[3], newbatch[3], std::array<u64,2>{v_c65, v_c68}, std::array<u16,3>{2, 1, 0});
                                                                                                      slog::emit_struct<3>(head_rel[4], newbatch[4], std::array<u64,2>{v_c59, v_c60}, std::array<u16,3>{2, 1, 0});
                                                                                                      slog::emit_struct<3>(head_rel[5], newbatch[5], std::array<u64,2>{v_c51, v_c54}, std::array<u16,3>{2, 1, 0});
                                                                                                      slog::emit_struct<3>(head_rel[6], newbatch[6], std::array<u64,2>{v_c45, v_c46}, std::array<u16,3>{2, 1, 0});
                                                                                                      slog::emit_struct<3>(head_rel[7], newbatch[7], std::array<u64,2>{v_c37, v_c40}, std::array<u16,3>{2, 1, 0});
                                                                                                    });
                                                                                                  });
                                                                                                });
                                                                                              });
                                                                                            });
                                                                                          });
                                                                                        });
                                                                                      });
                                                                                    });
                                                                                  });
                                                                                });
                                                                              });
                                                                            });
                                                                          });
                                                                        });
                                                                      });
                                                                    });
                                                                  });
                                                                });
                                                              });
                                                            });
                                                          });
                                                        });
                                                      });
                                                    });
                                                  });
                                                });
                                              });
                                            });
                                          });
                                        });
                                      });
                                    });
                                  });
                                });
                              });
                            });
                          });
                        });
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
        head_rel[4]->sendBatch(newbatch[4]);
        head_rel[5]->sendBatch(newbatch[5]);
        head_rel[6]->sendBatch(newbatch[6]);
        head_rel[7]->sendBatch(newbatch[7]);
  
      if (_fires) db->bumpFires("deep_fact.slog:7", "delta:Nd", _fires);
  
      if (!_done)
      {
        ReadTask2559* _cont = new ReadTask2559(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask2559(db,b), false);
  // (crule (pre (let __tconst48SJ108 const6b86b273ff34fce19d6b804e) (let __tconst5Uhl106 constd4735e3a265e16eee03f5971) (let __tconst9YpM103 const4e07408562bedb8b60ce05c1) (let __tconst3iHp101 const4b227777d4dd1fc61c6f884f) (let __tconst0Emh97 constef2d127de37b942baad06145) (let __tconst29xA95 conste7f6c011776e8db7cd330b54) (let __tconst9mjQ92 const7902699be42c8a8e46fbbb45) (let __tconst9Yxv90 const2c624232cdd221771294dfbb) (let __tconst7wWY85 const19581e27de7ced00ff1ce50b) (let __tconst01Wl83 const4a44dc15364204a80fe80e90) (let __tconst42lR80 const4fc82b26aecb47d2868c4efb) (let __tconst3KyY78 const6b51d431df5d7f141cbececc) (let __tconst6a9N74 const3fdba35f04dc8c462986c992) (let __tconst74Qx72 const8527a891e224136950ff32ca) (let __tconst2hOw69 conste629fa6598d732768f7c726b) (let __tconst7kHD67 constb17ef6d19c7a5b1ee83b907c) (let __tconst5zmq61 const4523540f1504cd17100c4835) (let __tconst31qC59 const4ec9599fc203d176a301536c) (let __tconst4Vop56 const9400f1b21cb527d7fa3d3eab) (let __tconst51zc54 constf5ca38f748a1d6eaf726b8a4) (let __tconst6Qm150 const6f4b6612125fb3a0daecd279) (let __tconst6bEj48 const785f3ec7eb32f30b90cd0fcf) (let __tconst7AKN45 const535fa30d7e25dd8a49f15367) (let __tconst9j2a43 constc2356069e9d1e79ca9243781) (let __tconst1Mto38 constb7a56873cd771f2c446d369b) (let __tconst8u8i36 const5f9c4ab08cac7457e9111a30) (let __tconst2Isx33 const670671cd97404156226e5079) (let __tconst8J6R31 const59e19706d51d39f66711c265) (let __tconst88cs27 const35135aaa6cc23891b40cb3f3) (let __tconst0Uuf25 const624b60c58c9d8bfb6ff1886c) (let __tconst6sf622 consteb1e33e8a81b697b75855af6) (let __tconst5Run20 conste29c9c180c6279b0b02abd6a)) (seeded) (body (join Lf (1 0) 1 __tconst5Run20 __t8mDO21) (exists Lf (1 0) 1 __tconst0Uuf25) (exists Lf (1 0) 1 __tconst88cs27) (exists Lf (1 0) 1 __tconst8J6R31) (exists Lf (1 0) 1 __tconst2Isx33) (exists Lf (1 0) 1 __tconst8u8i36) (exists Lf (1 0) 1 __tconst1Mto38) (exists Lf (1 0) 1 __tconst9j2a43) (exists Lf (1 0) 1 __tconst7AKN45) (exists Lf (1 0) 1 __tconst6bEj48) (exists Lf (1 0) 1 __tconst6Qm150) (exists Lf (1 0) 1 __tconst51zc54) (exists Lf (1 0) 1 __tconst4Vop56) (exists Lf (1 0) 1 __tconst31qC59) (exists Lf (1 0) 1 __tconst5zmq61) (exists Lf (1 0) 1 __tconst7kHD67) (exists Lf (1 0) 1 __tconst2hOw69) (exists Lf (1 0) 1 __tconst74Qx72) (exists Lf (1 0) 1 __tconst6a9N74) (exists Lf (1 0) 1 __tconst3KyY78) (exists Lf (1 0) 1 __tconst42lR80) (exists Lf (1 0) 1 __tconst01Wl83) (exists Lf (1 0) 1 __tconst7wWY85) (exists Lf (1 0) 1 __tconst9Yxv90) (exists Lf (1 0) 1 __tconst9mjQ92) (exists Lf (1 0) 1 __tconst29xA95) (exists Lf (1 0) 1 __tconst0Emh97) (exists Lf (1 0) 1 __tconst3iHp101) (exists Lf (1 0) 1 __tconst9YpM103) (exists Lf (1 0) 1 __tconst5Uhl106) (exists Lf (1 0) 1 __tconst48SJ108) (join Lf (1 0) 1 __tconst6sf622 __t1M8o23) (join Lf (1 0) 1 __tconst0Uuf25 __t1NQv26) (join Lf (1 0) 1 __tconst88cs27 __t7d0c28) (join Lf (1 0) 1 __tconst8J6R31 __t9vh832) (join Lf (1 0) 1 __tconst2Isx33 __t5flt34) (join Lf (1 0) 1 __tconst8u8i36 __t27Zr37) (join Lf (1 0) 1 __tconst1Mto38 __t3UFu39) (join Lf (1 0) 1 __tconst9j2a43 __t6IKq44) (join Lf (1 0) 1 __tconst7AKN45 __t6LIW46) (join Lf (1 0) 1 __tconst6bEj48 __t9k7a49) (join Lf (1 0) 1 __tconst6Qm150 __t4MdC51) (join Lf (1 0) 1 __tconst51zc54 __t3Yon55) (join Lf (1 0) 1 __tconst4Vop56 __t5ik157) (join Lf (1 0) 1 __tconst31qC59 __t1nkJ60) (join Lf (1 0) 1 __tconst5zmq61 __t4E3D62) (join Lf (1 0) 1 __tconst7kHD67 __t4J2N68) (join Lf (1 0) 1 __tconst2hOw69 __t4izo70) (join Lf (1 0) 1 __tconst74Qx72 __t319l73) (join Lf (1 0) 1 __tconst6a9N74 __t0amQ75) (join Lf (1 0) 1 __tconst3KyY78 __t13gt79) (join Lf (1 0) 1 __tconst42lR80 __t3ESz81) (join Lf (1 0) 1 __tconst01Wl83 __t4Da384) (join Lf (1 0) 1 __tconst7wWY85 __t91gs86) (join Lf (1 0) 1 __tconst9Yxv90 __t7UaH91) (join Lf (1 0) 1 __tconst9mjQ92 __t6IMg93) (join Lf (1 0) 1 __tconst29xA95 __t2oHE96) (join Lf (1 0) 1 __tconst0Emh97 __t7bue98) (join Lf (1 0) 1 __tconst3iHp101 __t5yzC102) (join Lf (1 0) 1 __tconst9YpM103 __t7c21104) (join Lf (1 0) 1 __tconst5Uhl106 __t1IJA107) (join Lf (1 0) 1 __tconst48SJ108 __t0y5t109)) (head (mkstruct Nd (2 1 0) __t76VS110 __t1IJA107 __t0y5t109) (mkstruct Nd (2 1 0) __t4bRV105 __t5yzC102 __t7c21104) (mkstruct Nd (2 1 0) __t0HkS99 __t2oHE96 __t7bue98) (mkstruct Nd (2 1 0) __t2T3i94 __t7UaH91 __t6IMg93) (mkstruct Nd (2 1 0) __t02Bu87 __t4Da384 __t91gs86) (mkstruct Nd (2 1 0) __t3WL082 __t13gt79 __t3ESz81) (mkstruct Nd (2 1 0) __t4MUf76 __t319l73 __t0amQ75) (mkstruct Nd (2 1 0) __t14Ff71 __t4J2N68 __t4izo70) (mkstruct Nd (2 1 0) __t8TXU63 __t1nkJ60 __t4E3D62) (mkstruct Nd (2 1 0) __t4hi358 __t3Yon55 __t5ik157) (mkstruct Nd (2 1 0) __t8A9i52 __t9k7a49 __t4MdC51) (mkstruct Nd (2 1 0) __t7C7d47 __t6IKq44 __t6LIW46) (mkstruct Nd (2 1 0) __t8qqV40 __t27Zr37 __t3UFu39) (mkstruct Nd (2 1 0) __t3jHg35 __t9vh832 __t5flt34) (mkstruct Nd (2 1 0) __t0kIY29 __t1NQv26 __t7d0c28) (mkstruct Nd (2 1 0) __t7LF824 __t8mDO21 __t1M8o23)) deep_fact.slog:7 #f)
  class ReadTask2851 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[16];
    slog::Index** head_index[16];
  
  
  
  
  
  
    slog::Index** Lfindex2789;  slog::Index** Lfindex2790;  slog::Index** Lfindex2791;  slog::Index** Lfindex2792;  slog::Index** Lfindex2793;  slog::Index** Lfindex2794;  slog::Index** Lfindex2795;  slog::Index** Lfindex2796;  slog::Index** Lfindex2797;  slog::Index** Lfindex2798;  slog::Index** Lfindex2799;  slog::Index** Lfindex2800;  slog::Index** Lfindex2801;  slog::Index** Lfindex2802;  slog::Index** Lfindex2803;  slog::Index** Lfindex2804;  slog::Index** Lfindex2805;  slog::Index** Lfindex2806;  slog::Index** Lfindex2807;  slog::Index** Lfindex2808;  slog::Index** Lfindex2809;  slog::Index** Lfindex2810;  slog::Index** Lfindex2811;  slog::Index** Lfindex2812;  slog::Index** Lfindex2813;  slog::Index** Lfindex2814;  slog::Index** Lfindex2815;  slog::Index** Lfindex2816;  slog::Index** Lfindex2817;  slog::Index** Lfindex2818;  slog::Index** Lfindex2819;  slog::Index** Lfindex2820;  slog::Index** Lfindex2821;  slog::Index** Lfindex2822;  slog::Index** Lfindex2823;  slog::Index** Lfindex2824;  slog::Index** Lfindex2825;  slog::Index** Lfindex2826;  slog::Index** Lfindex2827;  slog::Index** Lfindex2828;  slog::Index** Lfindex2829;  slog::Index** Lfindex2830;  slog::Index** Lfindex2831;  slog::Index** Lfindex2832;  slog::Index** Lfindex2833;  slog::Index** Lfindex2834;  slog::Index** Lfindex2835;  slog::Index** Lfindex2836;  slog::Index** Lfindex2837;  slog::Index** Lfindex2838;  slog::Index** Lfindex2839;  slog::Index** Lfindex2840;  slog::Index** Lfindex2841;  slog::Index** Lfindex2842;  slog::Index** Lfindex2843;  slog::Index** Lfindex2844;  slog::Index** Lfindex2845;  slog::Index** Lfindex2846;  slog::Index** Lfindex2847;  slog::Index** Lfindex2848;  slog::Index** Lfindex2849;  slog::Index** Lfindex2850;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("Nd");
      std::vector<u16> ord2852({2, 1, 0});
      slog::Relation* readrel2853 = db->getRelation("Nd");
      head_index[0] = readrel2853->getIndex(ord2852, false);
      head_rel[1] = db->getRelation("Nd");
      std::vector<u16> ord2854({2, 1, 0});
      slog::Relation* readrel2855 = db->getRelation("Nd");
      head_index[1] = readrel2855->getIndex(ord2854, false);
      head_rel[2] = db->getRelation("Nd");
      std::vector<u16> ord2856({2, 1, 0});
      slog::Relation* readrel2857 = db->getRelation("Nd");
      head_index[2] = readrel2857->getIndex(ord2856, false);
      head_rel[3] = db->getRelation("Nd");
      std::vector<u16> ord2858({2, 1, 0});
      slog::Relation* readrel2859 = db->getRelation("Nd");
      head_index[3] = readrel2859->getIndex(ord2858, false);
      head_rel[4] = db->getRelation("Nd");
      std::vector<u16> ord2860({2, 1, 0});
      slog::Relation* readrel2861 = db->getRelation("Nd");
      head_index[4] = readrel2861->getIndex(ord2860, false);
      head_rel[5] = db->getRelation("Nd");
      std::vector<u16> ord2862({2, 1, 0});
      slog::Relation* readrel2863 = db->getRelation("Nd");
      head_index[5] = readrel2863->getIndex(ord2862, false);
      head_rel[6] = db->getRelation("Nd");
      std::vector<u16> ord2864({2, 1, 0});
      slog::Relation* readrel2865 = db->getRelation("Nd");
      head_index[6] = readrel2865->getIndex(ord2864, false);
      head_rel[7] = db->getRelation("Nd");
      std::vector<u16> ord2866({2, 1, 0});
      slog::Relation* readrel2867 = db->getRelation("Nd");
      head_index[7] = readrel2867->getIndex(ord2866, false);
      head_rel[8] = db->getRelation("Nd");
      std::vector<u16> ord2868({2, 1, 0});
      slog::Relation* readrel2869 = db->getRelation("Nd");
      head_index[8] = readrel2869->getIndex(ord2868, false);
      head_rel[9] = db->getRelation("Nd");
      std::vector<u16> ord2870({2, 1, 0});
      slog::Relation* readrel2871 = db->getRelation("Nd");
      head_index[9] = readrel2871->getIndex(ord2870, false);
      head_rel[10] = db->getRelation("Nd");
      std::vector<u16> ord2872({2, 1, 0});
      slog::Relation* readrel2873 = db->getRelation("Nd");
      head_index[10] = readrel2873->getIndex(ord2872, false);
      head_rel[11] = db->getRelation("Nd");
      std::vector<u16> ord2874({2, 1, 0});
      slog::Relation* readrel2875 = db->getRelation("Nd");
      head_index[11] = readrel2875->getIndex(ord2874, false);
      head_rel[12] = db->getRelation("Nd");
      std::vector<u16> ord2876({2, 1, 0});
      slog::Relation* readrel2877 = db->getRelation("Nd");
      head_index[12] = readrel2877->getIndex(ord2876, false);
      head_rel[13] = db->getRelation("Nd");
      std::vector<u16> ord2878({2, 1, 0});
      slog::Relation* readrel2879 = db->getRelation("Nd");
      head_index[13] = readrel2879->getIndex(ord2878, false);
      head_rel[14] = db->getRelation("Nd");
      std::vector<u16> ord2880({2, 1, 0});
      slog::Relation* readrel2881 = db->getRelation("Nd");
      head_index[14] = readrel2881->getIndex(ord2880, false);
      head_rel[15] = db->getRelation("Nd");
      std::vector<u16> ord2882({2, 1, 0});
      slog::Relation* readrel2883 = db->getRelation("Nd");
      head_index[15] = readrel2883->getIndex(ord2882, false);
      std::vector<u16> ord2884({1, 0});
      slog::Relation* readrel2885 = db->getRelation("Lf");
      Lfindex2789 = readrel2885->getIndex(ord2884, false);
      std::vector<u16> ord2886({1, 0});
      slog::Relation* readrel2887 = db->getRelation("Lf");
      Lfindex2790 = readrel2887->getIndex(ord2886, false);
      std::vector<u16> ord2888({1, 0});
      slog::Relation* readrel2889 = db->getRelation("Lf");
      Lfindex2791 = readrel2889->getIndex(ord2888, false);
      std::vector<u16> ord2890({1, 0});
      slog::Relation* readrel2891 = db->getRelation("Lf");
      Lfindex2792 = readrel2891->getIndex(ord2890, false);
      std::vector<u16> ord2892({1, 0});
      slog::Relation* readrel2893 = db->getRelation("Lf");
      Lfindex2793 = readrel2893->getIndex(ord2892, false);
      std::vector<u16> ord2894({1, 0});
      slog::Relation* readrel2895 = db->getRelation("Lf");
      Lfindex2794 = readrel2895->getIndex(ord2894, false);
      std::vector<u16> ord2896({1, 0});
      slog::Relation* readrel2897 = db->getRelation("Lf");
      Lfindex2795 = readrel2897->getIndex(ord2896, false);
      std::vector<u16> ord2898({1, 0});
      slog::Relation* readrel2899 = db->getRelation("Lf");
      Lfindex2796 = readrel2899->getIndex(ord2898, false);
      std::vector<u16> ord2900({1, 0});
      slog::Relation* readrel2901 = db->getRelation("Lf");
      Lfindex2797 = readrel2901->getIndex(ord2900, false);
      std::vector<u16> ord2902({1, 0});
      slog::Relation* readrel2903 = db->getRelation("Lf");
      Lfindex2798 = readrel2903->getIndex(ord2902, false);
      std::vector<u16> ord2904({1, 0});
      slog::Relation* readrel2905 = db->getRelation("Lf");
      Lfindex2799 = readrel2905->getIndex(ord2904, false);
      std::vector<u16> ord2906({1, 0});
      slog::Relation* readrel2907 = db->getRelation("Lf");
      Lfindex2800 = readrel2907->getIndex(ord2906, false);
      std::vector<u16> ord2908({1, 0});
      slog::Relation* readrel2909 = db->getRelation("Lf");
      Lfindex2801 = readrel2909->getIndex(ord2908, false);
      std::vector<u16> ord2910({1, 0});
      slog::Relation* readrel2911 = db->getRelation("Lf");
      Lfindex2802 = readrel2911->getIndex(ord2910, false);
      std::vector<u16> ord2912({1, 0});
      slog::Relation* readrel2913 = db->getRelation("Lf");
      Lfindex2803 = readrel2913->getIndex(ord2912, false);
      std::vector<u16> ord2914({1, 0});
      slog::Relation* readrel2915 = db->getRelation("Lf");
      Lfindex2804 = readrel2915->getIndex(ord2914, false);
      std::vector<u16> ord2916({1, 0});
      slog::Relation* readrel2917 = db->getRelation("Lf");
      Lfindex2805 = readrel2917->getIndex(ord2916, false);
      std::vector<u16> ord2918({1, 0});
      slog::Relation* readrel2919 = db->getRelation("Lf");
      Lfindex2806 = readrel2919->getIndex(ord2918, false);
      std::vector<u16> ord2920({1, 0});
      slog::Relation* readrel2921 = db->getRelation("Lf");
      Lfindex2807 = readrel2921->getIndex(ord2920, false);
      std::vector<u16> ord2922({1, 0});
      slog::Relation* readrel2923 = db->getRelation("Lf");
      Lfindex2808 = readrel2923->getIndex(ord2922, false);
      std::vector<u16> ord2924({1, 0});
      slog::Relation* readrel2925 = db->getRelation("Lf");
      Lfindex2809 = readrel2925->getIndex(ord2924, false);
      std::vector<u16> ord2926({1, 0});
      slog::Relation* readrel2927 = db->getRelation("Lf");
      Lfindex2810 = readrel2927->getIndex(ord2926, false);
      std::vector<u16> ord2928({1, 0});
      slog::Relation* readrel2929 = db->getRelation("Lf");
      Lfindex2811 = readrel2929->getIndex(ord2928, false);
      std::vector<u16> ord2930({1, 0});
      slog::Relation* readrel2931 = db->getRelation("Lf");
      Lfindex2812 = readrel2931->getIndex(ord2930, false);
      std::vector<u16> ord2932({1, 0});
      slog::Relation* readrel2933 = db->getRelation("Lf");
      Lfindex2813 = readrel2933->getIndex(ord2932, false);
      std::vector<u16> ord2934({1, 0});
      slog::Relation* readrel2935 = db->getRelation("Lf");
      Lfindex2814 = readrel2935->getIndex(ord2934, false);
      std::vector<u16> ord2936({1, 0});
      slog::Relation* readrel2937 = db->getRelation("Lf");
      Lfindex2815 = readrel2937->getIndex(ord2936, false);
      std::vector<u16> ord2938({1, 0});
      slog::Relation* readrel2939 = db->getRelation("Lf");
      Lfindex2816 = readrel2939->getIndex(ord2938, false);
      std::vector<u16> ord2940({1, 0});
      slog::Relation* readrel2941 = db->getRelation("Lf");
      Lfindex2817 = readrel2941->getIndex(ord2940, false);
      std::vector<u16> ord2942({1, 0});
      slog::Relation* readrel2943 = db->getRelation("Lf");
      Lfindex2818 = readrel2943->getIndex(ord2942, false);
      std::vector<u16> ord2944({1, 0});
      slog::Relation* readrel2945 = db->getRelation("Lf");
      Lfindex2819 = readrel2945->getIndex(ord2944, false);
      std::vector<u16> ord2946({1, 0});
      slog::Relation* readrel2947 = db->getRelation("Lf");
      Lfindex2820 = readrel2947->getIndex(ord2946, false);
      std::vector<u16> ord2948({1, 0});
      slog::Relation* readrel2949 = db->getRelation("Lf");
      Lfindex2821 = readrel2949->getIndex(ord2948, false);
      std::vector<u16> ord2950({1, 0});
      slog::Relation* readrel2951 = db->getRelation("Lf");
      Lfindex2822 = readrel2951->getIndex(ord2950, false);
      std::vector<u16> ord2952({1, 0});
      slog::Relation* readrel2953 = db->getRelation("Lf");
      Lfindex2823 = readrel2953->getIndex(ord2952, false);
      std::vector<u16> ord2954({1, 0});
      slog::Relation* readrel2955 = db->getRelation("Lf");
      Lfindex2824 = readrel2955->getIndex(ord2954, false);
      std::vector<u16> ord2956({1, 0});
      slog::Relation* readrel2957 = db->getRelation("Lf");
      Lfindex2825 = readrel2957->getIndex(ord2956, false);
      std::vector<u16> ord2958({1, 0});
      slog::Relation* readrel2959 = db->getRelation("Lf");
      Lfindex2826 = readrel2959->getIndex(ord2958, false);
      std::vector<u16> ord2960({1, 0});
      slog::Relation* readrel2961 = db->getRelation("Lf");
      Lfindex2827 = readrel2961->getIndex(ord2960, false);
      std::vector<u16> ord2962({1, 0});
      slog::Relation* readrel2963 = db->getRelation("Lf");
      Lfindex2828 = readrel2963->getIndex(ord2962, false);
      std::vector<u16> ord2964({1, 0});
      slog::Relation* readrel2965 = db->getRelation("Lf");
      Lfindex2829 = readrel2965->getIndex(ord2964, false);
      std::vector<u16> ord2966({1, 0});
      slog::Relation* readrel2967 = db->getRelation("Lf");
      Lfindex2830 = readrel2967->getIndex(ord2966, false);
      std::vector<u16> ord2968({1, 0});
      slog::Relation* readrel2969 = db->getRelation("Lf");
      Lfindex2831 = readrel2969->getIndex(ord2968, false);
      std::vector<u16> ord2970({1, 0});
      slog::Relation* readrel2971 = db->getRelation("Lf");
      Lfindex2832 = readrel2971->getIndex(ord2970, false);
      std::vector<u16> ord2972({1, 0});
      slog::Relation* readrel2973 = db->getRelation("Lf");
      Lfindex2833 = readrel2973->getIndex(ord2972, false);
      std::vector<u16> ord2974({1, 0});
      slog::Relation* readrel2975 = db->getRelation("Lf");
      Lfindex2834 = readrel2975->getIndex(ord2974, false);
      std::vector<u16> ord2976({1, 0});
      slog::Relation* readrel2977 = db->getRelation("Lf");
      Lfindex2835 = readrel2977->getIndex(ord2976, false);
      std::vector<u16> ord2978({1, 0});
      slog::Relation* readrel2979 = db->getRelation("Lf");
      Lfindex2836 = readrel2979->getIndex(ord2978, false);
      std::vector<u16> ord2980({1, 0});
      slog::Relation* readrel2981 = db->getRelation("Lf");
      Lfindex2837 = readrel2981->getIndex(ord2980, false);
      std::vector<u16> ord2982({1, 0});
      slog::Relation* readrel2983 = db->getRelation("Lf");
      Lfindex2838 = readrel2983->getIndex(ord2982, false);
      std::vector<u16> ord2984({1, 0});
      slog::Relation* readrel2985 = db->getRelation("Lf");
      Lfindex2839 = readrel2985->getIndex(ord2984, false);
      std::vector<u16> ord2986({1, 0});
      slog::Relation* readrel2987 = db->getRelation("Lf");
      Lfindex2840 = readrel2987->getIndex(ord2986, false);
      std::vector<u16> ord2988({1, 0});
      slog::Relation* readrel2989 = db->getRelation("Lf");
      Lfindex2841 = readrel2989->getIndex(ord2988, false);
      std::vector<u16> ord2990({1, 0});
      slog::Relation* readrel2991 = db->getRelation("Lf");
      Lfindex2842 = readrel2991->getIndex(ord2990, false);
      std::vector<u16> ord2992({1, 0});
      slog::Relation* readrel2993 = db->getRelation("Lf");
      Lfindex2843 = readrel2993->getIndex(ord2992, false);
      std::vector<u16> ord2994({1, 0});
      slog::Relation* readrel2995 = db->getRelation("Lf");
      Lfindex2844 = readrel2995->getIndex(ord2994, false);
      std::vector<u16> ord2996({1, 0});
      slog::Relation* readrel2997 = db->getRelation("Lf");
      Lfindex2845 = readrel2997->getIndex(ord2996, false);
      std::vector<u16> ord2998({1, 0});
      slog::Relation* readrel2999 = db->getRelation("Lf");
      Lfindex2846 = readrel2999->getIndex(ord2998, false);
      std::vector<u16> ord3000({1, 0});
      slog::Relation* readrel3001 = db->getRelation("Lf");
      Lfindex2847 = readrel3001->getIndex(ord3000, false);
      std::vector<u16> ord3002({1, 0});
      slog::Relation* readrel3003 = db->getRelation("Lf");
      Lfindex2848 = readrel3003->getIndex(ord3002, false);
      std::vector<u16> ord3004({1, 0});
      slog::Relation* readrel3005 = db->getRelation("Lf");
      Lfindex2849 = readrel3005->getIndex(ord3004, false);
      std::vector<u16> ord3006({1, 0});
      slog::Relation* readrel3007 = db->getRelation("Lf");
      Lfindex2850 = readrel3007->getIndex(ord3006, false);
  
    }
    ReadTask2851(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[16];
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
  
      slog::join_probe<2,1>(Lfindex2789, std::array<u64,2>{v_c31, 0}, [&](const std::array<u64,2>& m3008) {
        u64 v_c35 = m3008[1];
        if (!slog::exists_probe<2,1>(Lfindex2790, std::array<u64,2>{v_c29, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2791, std::array<u64,2>{v_c28, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2792, std::array<u64,2>{v_c27, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2793, std::array<u64,2>{v_c26, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2794, std::array<u64,2>{v_c25, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2795, std::array<u64,2>{v_c24, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2796, std::array<u64,2>{v_c23, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2797, std::array<u64,2>{v_c22, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2798, std::array<u64,2>{v_c21, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2799, std::array<u64,2>{v_c20, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2800, std::array<u64,2>{v_c19, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2801, std::array<u64,2>{v_c18, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2802, std::array<u64,2>{v_c17, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2803, std::array<u64,2>{v_c16, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2804, std::array<u64,2>{v_c15, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2805, std::array<u64,2>{v_c14, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2806, std::array<u64,2>{v_c13, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2807, std::array<u64,2>{v_c12, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2808, std::array<u64,2>{v_c11, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2809, std::array<u64,2>{v_c10, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2810, std::array<u64,2>{v_c9, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2811, std::array<u64,2>{v_c8, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2812, std::array<u64,2>{v_c7, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2813, std::array<u64,2>{v_c6, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2814, std::array<u64,2>{v_c5, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2815, std::array<u64,2>{v_c4, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2816, std::array<u64,2>{v_c3, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2817, std::array<u64,2>{v_c2, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2818, std::array<u64,2>{v_c1, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex2819, std::array<u64,2>{v_c0, 0})) return;
        slog::join_probe<2,1>(Lfindex2820, std::array<u64,2>{v_c30, 0}, [&](const std::array<u64,2>& m3009) {
          u64 v_c36 = m3009[1];
          slog::join_probe<2,1>(Lfindex2821, std::array<u64,2>{v_c29, 0}, [&](const std::array<u64,2>& m3010) {
            u64 v_c38 = m3010[1];
            slog::join_probe<2,1>(Lfindex2822, std::array<u64,2>{v_c28, 0}, [&](const std::array<u64,2>& m3011) {
              u64 v_c39 = m3011[1];
              slog::join_probe<2,1>(Lfindex2823, std::array<u64,2>{v_c27, 0}, [&](const std::array<u64,2>& m3012) {
                u64 v_c43 = m3012[1];
                slog::join_probe<2,1>(Lfindex2824, std::array<u64,2>{v_c26, 0}, [&](const std::array<u64,2>& m3013) {
                  u64 v_c44 = m3013[1];
                  slog::join_probe<2,1>(Lfindex2825, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m3014) {
                    u64 v_c47 = m3014[1];
                    slog::join_probe<2,1>(Lfindex2826, std::array<u64,2>{v_c24, 0}, [&](const std::array<u64,2>& m3015) {
                      u64 v_c48 = m3015[1];
                      slog::join_probe<2,1>(Lfindex2827, std::array<u64,2>{v_c23, 0}, [&](const std::array<u64,2>& m3016) {
                        u64 v_c49 = m3016[1];
                        slog::join_probe<2,1>(Lfindex2828, std::array<u64,2>{v_c22, 0}, [&](const std::array<u64,2>& m3017) {
                          u64 v_c50 = m3017[1];
                          slog::join_probe<2,1>(Lfindex2829, std::array<u64,2>{v_c21, 0}, [&](const std::array<u64,2>& m3018) {
                            u64 v_c52 = m3018[1];
                            slog::join_probe<2,1>(Lfindex2830, std::array<u64,2>{v_c20, 0}, [&](const std::array<u64,2>& m3019) {
                              u64 v_c53 = m3019[1];
                              slog::join_probe<2,1>(Lfindex2831, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m3020) {
                                u64 v_c57 = m3020[1];
                                slog::join_probe<2,1>(Lfindex2832, std::array<u64,2>{v_c18, 0}, [&](const std::array<u64,2>& m3021) {
                                  u64 v_c58 = m3021[1];
                                  slog::join_probe<2,1>(Lfindex2833, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m3022) {
                                    u64 v_c61 = m3022[1];
                                    slog::join_probe<2,1>(Lfindex2834, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m3023) {
                                      u64 v_c62 = m3023[1];
                                      slog::join_probe<2,1>(Lfindex2835, std::array<u64,2>{v_c15, 0}, [&](const std::array<u64,2>& m3024) {
                                        u64 v_c63 = m3024[1];
                                        slog::join_probe<2,1>(Lfindex2836, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m3025) {
                                          u64 v_c64 = m3025[1];
                                          slog::join_probe<2,1>(Lfindex2837, std::array<u64,2>{v_c13, 0}, [&](const std::array<u64,2>& m3026) {
                                            u64 v_c66 = m3026[1];
                                            slog::join_probe<2,1>(Lfindex2838, std::array<u64,2>{v_c12, 0}, [&](const std::array<u64,2>& m3027) {
                                              u64 v_c67 = m3027[1];
                                              slog::join_probe<2,1>(Lfindex2839, std::array<u64,2>{v_c11, 0}, [&](const std::array<u64,2>& m3028) {
                                                u64 v_c70 = m3028[1];
                                                slog::join_probe<2,1>(Lfindex2840, std::array<u64,2>{v_c10, 0}, [&](const std::array<u64,2>& m3029) {
                                                  u64 v_c71 = m3029[1];
                                                  slog::join_probe<2,1>(Lfindex2841, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m3030) {
                                                    u64 v_c73 = m3030[1];
                                                    slog::join_probe<2,1>(Lfindex2842, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m3031) {
                                                      u64 v_c74 = m3031[1];
                                                      slog::join_probe<2,1>(Lfindex2843, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m3032) {
                                                        u64 v_c78 = m3032[1];
                                                        slog::join_probe<2,1>(Lfindex2844, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m3033) {
                                                          u64 v_c79 = m3033[1];
                                                          slog::join_probe<2,1>(Lfindex2845, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m3034) {
                                                            u64 v_c81 = m3034[1];
                                                            slog::join_probe<2,1>(Lfindex2846, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m3035) {
                                                              u64 v_c82 = m3035[1];
                                                              slog::join_probe<2,1>(Lfindex2847, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m3036) {
                                                                u64 v_c85 = m3036[1];
                                                                slog::join_probe<2,1>(Lfindex2848, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m3037) {
                                                                  u64 v_c86 = m3037[1];
                                                                  slog::join_probe<2,1>(Lfindex2849, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m3038) {
                                                                    u64 v_c88 = m3038[1];
                                                                    slog::join_probe<2,1>(Lfindex2850, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m3039) {
                                                                      u64 v_c89 = m3039[1];
                                                                      ++_fires;
                                                                      slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c88, v_c89}, std::array<u16,3>{2, 1, 0});
                                                                      slog::emit_struct_checked<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c85, v_c86}, std::array<u16,3>{2, 1, 0});
                                                                      slog::emit_struct_checked<3>(head_rel[2], head_index[2], newbatch[2], std::array<u64,2>{v_c81, v_c82}, std::array<u16,3>{2, 1, 0});
                                                                      slog::emit_struct_checked<3>(head_rel[3], head_index[3], newbatch[3], std::array<u64,2>{v_c78, v_c79}, std::array<u16,3>{2, 1, 0});
                                                                      slog::emit_struct_checked<3>(head_rel[4], head_index[4], newbatch[4], std::array<u64,2>{v_c73, v_c74}, std::array<u16,3>{2, 1, 0});
                                                                      slog::emit_struct_checked<3>(head_rel[5], head_index[5], newbatch[5], std::array<u64,2>{v_c70, v_c71}, std::array<u16,3>{2, 1, 0});
                                                                      slog::emit_struct_checked<3>(head_rel[6], head_index[6], newbatch[6], std::array<u64,2>{v_c66, v_c67}, std::array<u16,3>{2, 1, 0});
                                                                      slog::emit_struct_checked<3>(head_rel[7], head_index[7], newbatch[7], std::array<u64,2>{v_c63, v_c64}, std::array<u16,3>{2, 1, 0});
                                                                      slog::emit_struct_checked<3>(head_rel[8], head_index[8], newbatch[8], std::array<u64,2>{v_c61, v_c62}, std::array<u16,3>{2, 1, 0});
                                                                      slog::emit_struct_checked<3>(head_rel[9], head_index[9], newbatch[9], std::array<u64,2>{v_c57, v_c58}, std::array<u16,3>{2, 1, 0});
                                                                      slog::emit_struct_checked<3>(head_rel[10], head_index[10], newbatch[10], std::array<u64,2>{v_c52, v_c53}, std::array<u16,3>{2, 1, 0});
                                                                      slog::emit_struct_checked<3>(head_rel[11], head_index[11], newbatch[11], std::array<u64,2>{v_c49, v_c50}, std::array<u16,3>{2, 1, 0});
                                                                      slog::emit_struct_checked<3>(head_rel[12], head_index[12], newbatch[12], std::array<u64,2>{v_c47, v_c48}, std::array<u16,3>{2, 1, 0});
                                                                      slog::emit_struct_checked<3>(head_rel[13], head_index[13], newbatch[13], std::array<u64,2>{v_c43, v_c44}, std::array<u16,3>{2, 1, 0});
                                                                      slog::emit_struct_checked<3>(head_rel[14], head_index[14], newbatch[14], std::array<u64,2>{v_c38, v_c39}, std::array<u16,3>{2, 1, 0});
                                                                      slog::emit_struct_checked<3>(head_rel[15], head_index[15], newbatch[15], std::array<u64,2>{v_c35, v_c36}, std::array<u16,3>{2, 1, 0});
                                                                    });
                                                                  });
                                                                });
                                                              });
                                                            });
                                                          });
                                                        });
                                                      });
                                                    });
                                                  });
                                                });
                                              });
                                            });
                                          });
                                        });
                                      });
                                    });
                                  });
                                });
                              });
                            });
                          });
                        });
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
  
      if (_fires) db->bumpFires("deep_fact.slog:7", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask2851(db,b));
  // (crule (pre (let __tconst48SJ108 const6b86b273ff34fce19d6b804e) (let __tconst5Uhl106 constd4735e3a265e16eee03f5971) (let __tconst9YpM103 const4e07408562bedb8b60ce05c1) (let __tconst3iHp101 const4b227777d4dd1fc61c6f884f) (let __tconst0Emh97 constef2d127de37b942baad06145) (let __tconst29xA95 conste7f6c011776e8db7cd330b54) (let __tconst9mjQ92 const7902699be42c8a8e46fbbb45) (let __tconst9Yxv90 const2c624232cdd221771294dfbb) (let __tconst7wWY85 const19581e27de7ced00ff1ce50b) (let __tconst01Wl83 const4a44dc15364204a80fe80e90) (let __tconst42lR80 const4fc82b26aecb47d2868c4efb) (let __tconst3KyY78 const6b51d431df5d7f141cbececc) (let __tconst6a9N74 const3fdba35f04dc8c462986c992) (let __tconst74Qx72 const8527a891e224136950ff32ca) (let __tconst2hOw69 conste629fa6598d732768f7c726b) (let __tconst7kHD67 constb17ef6d19c7a5b1ee83b907c) (let __tconst5zmq61 const4523540f1504cd17100c4835) (let __tconst31qC59 const4ec9599fc203d176a301536c) (let __tconst4Vop56 const9400f1b21cb527d7fa3d3eab) (let __tconst51zc54 constf5ca38f748a1d6eaf726b8a4) (let __tconst6Qm150 const6f4b6612125fb3a0daecd279) (let __tconst6bEj48 const785f3ec7eb32f30b90cd0fcf) (let __tconst7AKN45 const535fa30d7e25dd8a49f15367) (let __tconst9j2a43 constc2356069e9d1e79ca9243781) (let __tconst1Mto38 constb7a56873cd771f2c446d369b) (let __tconst8u8i36 const5f9c4ab08cac7457e9111a30) (let __tconst2Isx33 const670671cd97404156226e5079) (let __tconst8J6R31 const59e19706d51d39f66711c265) (let __tconst88cs27 const35135aaa6cc23891b40cb3f3) (let __tconst0Uuf25 const624b60c58c9d8bfb6ff1886c) (let __tconst6sf622 consteb1e33e8a81b697b75855af6) (let __tconst5Run20 conste29c9c180c6279b0b02abd6a)) (scan Nd __t1U6n114 __t09Ym113 __t4LVF66) (body (exists Lf (1 0) 1 __tconst6sf622) (exists Lf (1 0) 1 __tconst0Uuf25) (exists Lf (1 0) 1 __tconst88cs27) (exists Lf (1 0) 1 __tconst8J6R31) (exists Lf (1 0) 1 __tconst2Isx33) (exists Lf (1 0) 1 __tconst8u8i36) (exists Lf (1 0) 1 __tconst1Mto38) (exists Lf (1 0) 1 __tconst9j2a43) (exists Lf (1 0) 1 __tconst7AKN45) (exists Lf (1 0) 1 __tconst6bEj48) (exists Lf (1 0) 1 __tconst6Qm150) (exists Lf (1 0) 1 __tconst51zc54) (exists Lf (1 0) 1 __tconst4Vop56) (exists Lf (1 0) 1 __tconst31qC59) (exists Lf (1 0) 1 __tconst5zmq61) (exists Lf (1 0) 1 __tconst7kHD67) (exists Lf (1 0) 1 __tconst2hOw69) (exists Lf (1 0) 1 __tconst74Qx72) (exists Lf (1 0) 1 __tconst6a9N74) (exists Lf (1 0) 1 __tconst3KyY78) (exists Lf (1 0) 1 __tconst42lR80) (exists Lf (1 0) 1 __tconst01Wl83) (exists Lf (1 0) 1 __tconst7wWY85) (exists Lf (1 0) 1 __tconst9Yxv90) (exists Lf (1 0) 1 __tconst9mjQ92) (exists Lf (1 0) 1 __tconst29xA95) (exists Lf (1 0) 1 __tconst0Emh97) (exists Lf (1 0) 1 __tconst3iHp101) (exists Lf (1 0) 1 __tconst9YpM103) (exists Lf (1 0) 1 __tconst5Uhl106) (exists Lf (1 0) 1 __tconst48SJ108) (join Lf (1 0) 1 __tconst5Run20 __t8mDO21) (exists Nd (2 1 0) 1 __t8mDO21) (join Lf (1 0) 1 __tconst6sf622 __t1M8o23) (join Nd (2 1 0) 2 __t8mDO21 __t1M8o23 __t7LF824) (exists Nd (2 1 0) 1 __t7LF824) (join Lf (1 0) 1 __tconst0Uuf25 __t1NQv26) (exists Nd (2 1 0) 1 __t1NQv26) (join Lf (1 0) 1 __tconst88cs27 __t7d0c28) (join Nd (2 1 0) 2 __t1NQv26 __t7d0c28 __t0kIY29) (join Nd (2 1 0) 2 __t7LF824 __t0kIY29 __t6JrG30) (exists Nd (2 1 0) 1 __t6JrG30) (join Lf (1 0) 1 __tconst8J6R31 __t9vh832) (exists Nd (2 1 0) 1 __t9vh832) (join Lf (1 0) 1 __tconst2Isx33 __t5flt34) (join Nd (2 1 0) 2 __t9vh832 __t5flt34 __t3jHg35) (exists Nd (2 1 0) 1 __t3jHg35) (join Lf (1 0) 1 __tconst8u8i36 __t27Zr37) (exists Nd (2 1 0) 1 __t27Zr37) (join Lf (1 0) 1 __tconst1Mto38 __t3UFu39) (join Nd (2 1 0) 2 __t27Zr37 __t3UFu39 __t8qqV40) (join Nd (2 1 0) 2 __t3jHg35 __t8qqV40 __t2KtK41) (join Nd (2 1 0) 2 __t6JrG30 __t2KtK41 __t17Jm42) (join Nd (0 2 1) 2 __t4LVF66 __t17Jm42 __t4uRs65) (join Lf (1 0) 1 __tconst9j2a43 __t6IKq44) (exists Nd (2 1 0) 1 __t6IKq44) (join Lf (1 0) 1 __tconst7AKN45 __t6LIW46) (join Nd (2 1 0) 2 __t6IKq44 __t6LIW46 __t7C7d47) (exists Nd (2 1 0) 1 __t7C7d47) (join Lf (1 0) 1 __tconst6bEj48 __t9k7a49) (exists Nd (2 1 0) 1 __t9k7a49) (join Lf (1 0) 1 __tconst6Qm150 __t4MdC51) (join Nd (2 1 0) 2 __t9k7a49 __t4MdC51 __t8A9i52) (join Nd (2 1 0) 2 __t7C7d47 __t8A9i52 __t7DSY53) (join Nd (0 2 1) 2 __t4uRs65 __t7DSY53 __t6bZq64) (join Lf (1 0) 1 __tconst51zc54 __t3Yon55) (exists Nd (2 1 0) 1 __t3Yon55) (join Lf (1 0) 1 __tconst4Vop56 __t5ik157) (join Nd (2 1 0) 2 __t3Yon55 __t5ik157 __t4hi358) (join Nd (0 2 1) 2 __t6bZq64 __t4hi358 __t8TXU63) (join Lf (1 0) 1 __tconst31qC59 __t1nkJ60) (join Nd (0 2 1) 2 __t8TXU63 __t1nkJ60 __t4E3D62) (join Lf (0 1) 2 __t4E3D62 __tconst5zmq61) (join Lf (1 0) 1 __tconst7kHD67 __t4J2N68) (exists Nd (2 1 0) 1 __t4J2N68) (join Lf (1 0) 1 __tconst2hOw69 __t4izo70) (join Nd (2 1 0) 2 __t4J2N68 __t4izo70 __t14Ff71) (exists Nd (2 1 0) 1 __t14Ff71) (join Lf (1 0) 1 __tconst74Qx72 __t319l73) (exists Nd (2 1 0) 1 __t319l73) (join Lf (1 0) 1 __tconst6a9N74 __t0amQ75) (join Nd (2 1 0) 2 __t319l73 __t0amQ75 __t4MUf76) (join Nd (2 1 0) 2 __t14Ff71 __t4MUf76 __t13Wj77) (exists Nd (2 1 0) 1 __t13Wj77) (join Lf (1 0) 1 __tconst3KyY78 __t13gt79) (exists Nd (2 1 0) 1 __t13gt79) (join Lf (1 0) 1 __tconst42lR80 __t3ESz81) (join Nd (2 1 0) 2 __t13gt79 __t3ESz81 __t3WL082) (exists Nd (2 1 0) 1 __t3WL082) (join Lf (1 0) 1 __tconst01Wl83 __t4Da384) (exists Nd (2 1 0) 1 __t4Da384) (join Lf (1 0) 1 __tconst7wWY85 __t91gs86) (join Nd (2 1 0) 2 __t4Da384 __t91gs86 __t02Bu87) (join Nd (2 1 0) 2 __t3WL082 __t02Bu87 __t60KJ88) (join Nd (2 1 0) 2 __t13Wj77 __t60KJ88 __t4p4K89) (join Nd (0 2 1) 2 __t09Ym113 __t4p4K89 __t9dGZ112) (join Lf (1 0) 1 __tconst9Yxv90 __t7UaH91) (exists Nd (2 1 0) 1 __t7UaH91) (join Lf (1 0) 1 __tconst9mjQ92 __t6IMg93) (join Nd (2 1 0) 2 __t7UaH91 __t6IMg93 __t2T3i94) (exists Nd (2 1 0) 1 __t2T3i94) (join Lf (1 0) 1 __tconst29xA95 __t2oHE96) (exists Nd (2 1 0) 1 __t2oHE96) (join Lf (1 0) 1 __tconst0Emh97 __t7bue98) (join Nd (2 1 0) 2 __t2oHE96 __t7bue98 __t0HkS99) (join Nd (2 1 0) 2 __t2T3i94 __t0HkS99 __t7PLp100) (join Nd (0 2 1) 2 __t9dGZ112 __t7PLp100 __t3a3T111) (join Lf (1 0) 1 __tconst3iHp101 __t5yzC102) (exists Nd (2 1 0) 1 __t5yzC102) (join Lf (1 0) 1 __tconst9YpM103 __t7c21104) (join Nd (2 1 0) 2 __t5yzC102 __t7c21104 __t4bRV105) (join Nd (0 2 1) 2 __t3a3T111 __t4bRV105 __t76VS110) (join Lf (1 0) 1 __tconst5Uhl106 __t1IJA107) (join Nd (0 2 1) 2 __t76VS110 __t1IJA107 __t0y5t109) (join Lf (0 1) 2 __t0y5t109 __tconst48SJ108)) (head (emit t (0) __t1U6n114)) deep_fact.slog:7 #f)
  class ReadTask3155 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** Lfindex3040;  slog::Index** Lfindex3041;  slog::Index** Lfindex3042;  slog::Index** Lfindex3043;  slog::Index** Lfindex3044;  slog::Index** Lfindex3045;  slog::Index** Lfindex3046;  slog::Index** Lfindex3047;  slog::Index** Lfindex3048;  slog::Index** Lfindex3049;  slog::Index** Lfindex3050;  slog::Index** Lfindex3051;  slog::Index** Lfindex3052;  slog::Index** Lfindex3053;  slog::Index** Lfindex3054;  slog::Index** Lfindex3055;  slog::Index** Lfindex3056;  slog::Index** Lfindex3057;  slog::Index** Lfindex3058;  slog::Index** Lfindex3059;  slog::Index** Lfindex3060;  slog::Index** Lfindex3061;  slog::Index** Lfindex3062;  slog::Index** Lfindex3063;  slog::Index** Lfindex3064;  slog::Index** Lfindex3065;  slog::Index** Lfindex3066;  slog::Index** Lfindex3067;  slog::Index** Lfindex3068;  slog::Index** Lfindex3069;  slog::Index** Lfindex3070;  slog::Index** Lfindex3071;  slog::Index** Ndindex3072;  slog::Index** Lfindex3073;  slog::Index** Ndindex3074;  slog::Index** Ndindex3075;  slog::Index** Lfindex3076;  slog::Index** Ndindex3077;  slog::Index** Lfindex3078;  slog::Index** Ndindex3079;  slog::Index** Ndindex3080;  slog::Index** Ndindex3081;  slog::Index** Lfindex3082;  slog::Index** Ndindex3083;  slog::Index** Lfindex3084;  slog::Index** Ndindex3085;  slog::Index** Ndindex3086;  slog::Index** Lfindex3087;  slog::Index** Ndindex3088;  slog::Index** Lfindex3089;  slog::Index** Ndindex3090;  slog::Index** Ndindex3091;  slog::Index** Ndindex3092;  slog::Index** Ndindex3093;  slog::Index** Lfindex3094;  slog::Index** Ndindex3095;  slog::Index** Lfindex3096;  slog::Index** Ndindex3097;  slog::Index** Ndindex3098;  slog::Index** Lfindex3099;  slog::Index** Ndindex3100;  slog::Index** Lfindex3101;  slog::Index** Ndindex3102;  slog::Index** Ndindex3103;  slog::Index** Ndindex3104;  slog::Index** Lfindex3105;  slog::Index** Ndindex3106;  slog::Index** Lfindex3107;  slog::Index** Ndindex3108;  slog::Index** Ndindex3109;  slog::Index** Lfindex3110;  slog::Index** Ndindex3111;  slog::Index** Lfindex3112;  slog::Index** Lfindex3113;  slog::Index** Ndindex3114;  slog::Index** Lfindex3115;  slog::Index** Ndindex3116;  slog::Index** Ndindex3117;  slog::Index** Lfindex3118;  slog::Index** Ndindex3119;  slog::Index** Lfindex3120;  slog::Index** Ndindex3121;  slog::Index** Ndindex3122;  slog::Index** Ndindex3123;  slog::Index** Lfindex3124;  slog::Index** Ndindex3125;  slog::Index** Lfindex3126;  slog::Index** Ndindex3127;  slog::Index** Ndindex3128;  slog::Index** Lfindex3129;  slog::Index** Ndindex3130;  slog::Index** Lfindex3131;  slog::Index** Ndindex3132;  slog::Index** Ndindex3133;  slog::Index** Ndindex3134;  slog::Index** Ndindex3135;  slog::Index** Lfindex3136;  slog::Index** Ndindex3137;  slog::Index** Lfindex3138;  slog::Index** Ndindex3139;  slog::Index** Ndindex3140;  slog::Index** Lfindex3141;  slog::Index** Ndindex3142;  slog::Index** Lfindex3143;  slog::Index** Ndindex3144;  slog::Index** Ndindex3145;  slog::Index** Ndindex3146;  slog::Index** Lfindex3147;  slog::Index** Ndindex3148;  slog::Index** Lfindex3149;  slog::Index** Ndindex3150;  slog::Index** Ndindex3151;  slog::Index** Lfindex3152;  slog::Index** Ndindex3153;  slog::Index** Lfindex3154;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("t");
      std::vector<u16> ord3156({0});
      slog::Relation* readrel3157 = db->getRelation("t");
      head_index[0] = readrel3157->getIndex(ord3156, false);
      outer_rel = db->getRelation("Nd");
      std::vector<u16> ord3158({1, 0});
      slog::Relation* readrel3159 = db->getRelation("Lf");
      Lfindex3040 = readrel3159->getIndex(ord3158, false);
      std::vector<u16> ord3160({1, 0});
      slog::Relation* readrel3161 = db->getRelation("Lf");
      Lfindex3041 = readrel3161->getIndex(ord3160, false);
      std::vector<u16> ord3162({1, 0});
      slog::Relation* readrel3163 = db->getRelation("Lf");
      Lfindex3042 = readrel3163->getIndex(ord3162, false);
      std::vector<u16> ord3164({1, 0});
      slog::Relation* readrel3165 = db->getRelation("Lf");
      Lfindex3043 = readrel3165->getIndex(ord3164, false);
      std::vector<u16> ord3166({1, 0});
      slog::Relation* readrel3167 = db->getRelation("Lf");
      Lfindex3044 = readrel3167->getIndex(ord3166, false);
      std::vector<u16> ord3168({1, 0});
      slog::Relation* readrel3169 = db->getRelation("Lf");
      Lfindex3045 = readrel3169->getIndex(ord3168, false);
      std::vector<u16> ord3170({1, 0});
      slog::Relation* readrel3171 = db->getRelation("Lf");
      Lfindex3046 = readrel3171->getIndex(ord3170, false);
      std::vector<u16> ord3172({1, 0});
      slog::Relation* readrel3173 = db->getRelation("Lf");
      Lfindex3047 = readrel3173->getIndex(ord3172, false);
      std::vector<u16> ord3174({1, 0});
      slog::Relation* readrel3175 = db->getRelation("Lf");
      Lfindex3048 = readrel3175->getIndex(ord3174, false);
      std::vector<u16> ord3176({1, 0});
      slog::Relation* readrel3177 = db->getRelation("Lf");
      Lfindex3049 = readrel3177->getIndex(ord3176, false);
      std::vector<u16> ord3178({1, 0});
      slog::Relation* readrel3179 = db->getRelation("Lf");
      Lfindex3050 = readrel3179->getIndex(ord3178, false);
      std::vector<u16> ord3180({1, 0});
      slog::Relation* readrel3181 = db->getRelation("Lf");
      Lfindex3051 = readrel3181->getIndex(ord3180, false);
      std::vector<u16> ord3182({1, 0});
      slog::Relation* readrel3183 = db->getRelation("Lf");
      Lfindex3052 = readrel3183->getIndex(ord3182, false);
      std::vector<u16> ord3184({1, 0});
      slog::Relation* readrel3185 = db->getRelation("Lf");
      Lfindex3053 = readrel3185->getIndex(ord3184, false);
      std::vector<u16> ord3186({1, 0});
      slog::Relation* readrel3187 = db->getRelation("Lf");
      Lfindex3054 = readrel3187->getIndex(ord3186, false);
      std::vector<u16> ord3188({1, 0});
      slog::Relation* readrel3189 = db->getRelation("Lf");
      Lfindex3055 = readrel3189->getIndex(ord3188, false);
      std::vector<u16> ord3190({1, 0});
      slog::Relation* readrel3191 = db->getRelation("Lf");
      Lfindex3056 = readrel3191->getIndex(ord3190, false);
      std::vector<u16> ord3192({1, 0});
      slog::Relation* readrel3193 = db->getRelation("Lf");
      Lfindex3057 = readrel3193->getIndex(ord3192, false);
      std::vector<u16> ord3194({1, 0});
      slog::Relation* readrel3195 = db->getRelation("Lf");
      Lfindex3058 = readrel3195->getIndex(ord3194, false);
      std::vector<u16> ord3196({1, 0});
      slog::Relation* readrel3197 = db->getRelation("Lf");
      Lfindex3059 = readrel3197->getIndex(ord3196, false);
      std::vector<u16> ord3198({1, 0});
      slog::Relation* readrel3199 = db->getRelation("Lf");
      Lfindex3060 = readrel3199->getIndex(ord3198, false);
      std::vector<u16> ord3200({1, 0});
      slog::Relation* readrel3201 = db->getRelation("Lf");
      Lfindex3061 = readrel3201->getIndex(ord3200, false);
      std::vector<u16> ord3202({1, 0});
      slog::Relation* readrel3203 = db->getRelation("Lf");
      Lfindex3062 = readrel3203->getIndex(ord3202, false);
      std::vector<u16> ord3204({1, 0});
      slog::Relation* readrel3205 = db->getRelation("Lf");
      Lfindex3063 = readrel3205->getIndex(ord3204, false);
      std::vector<u16> ord3206({1, 0});
      slog::Relation* readrel3207 = db->getRelation("Lf");
      Lfindex3064 = readrel3207->getIndex(ord3206, false);
      std::vector<u16> ord3208({1, 0});
      slog::Relation* readrel3209 = db->getRelation("Lf");
      Lfindex3065 = readrel3209->getIndex(ord3208, false);
      std::vector<u16> ord3210({1, 0});
      slog::Relation* readrel3211 = db->getRelation("Lf");
      Lfindex3066 = readrel3211->getIndex(ord3210, false);
      std::vector<u16> ord3212({1, 0});
      slog::Relation* readrel3213 = db->getRelation("Lf");
      Lfindex3067 = readrel3213->getIndex(ord3212, false);
      std::vector<u16> ord3214({1, 0});
      slog::Relation* readrel3215 = db->getRelation("Lf");
      Lfindex3068 = readrel3215->getIndex(ord3214, false);
      std::vector<u16> ord3216({1, 0});
      slog::Relation* readrel3217 = db->getRelation("Lf");
      Lfindex3069 = readrel3217->getIndex(ord3216, false);
      std::vector<u16> ord3218({1, 0});
      slog::Relation* readrel3219 = db->getRelation("Lf");
      Lfindex3070 = readrel3219->getIndex(ord3218, false);
      std::vector<u16> ord3220({1, 0});
      slog::Relation* readrel3221 = db->getRelation("Lf");
      Lfindex3071 = readrel3221->getIndex(ord3220, false);
      std::vector<u16> ord3222({2, 1, 0});
      slog::Relation* readrel3223 = db->getRelation("Nd");
      Ndindex3072 = readrel3223->getIndex(ord3222, false);
      std::vector<u16> ord3224({1, 0});
      slog::Relation* readrel3225 = db->getRelation("Lf");
      Lfindex3073 = readrel3225->getIndex(ord3224, false);
      std::vector<u16> ord3226({2, 1, 0});
      slog::Relation* readrel3227 = db->getRelation("Nd");
      Ndindex3074 = readrel3227->getIndex(ord3226, false);
      std::vector<u16> ord3228({2, 1, 0});
      slog::Relation* readrel3229 = db->getRelation("Nd");
      Ndindex3075 = readrel3229->getIndex(ord3228, false);
      std::vector<u16> ord3230({1, 0});
      slog::Relation* readrel3231 = db->getRelation("Lf");
      Lfindex3076 = readrel3231->getIndex(ord3230, false);
      std::vector<u16> ord3232({2, 1, 0});
      slog::Relation* readrel3233 = db->getRelation("Nd");
      Ndindex3077 = readrel3233->getIndex(ord3232, false);
      std::vector<u16> ord3234({1, 0});
      slog::Relation* readrel3235 = db->getRelation("Lf");
      Lfindex3078 = readrel3235->getIndex(ord3234, false);
      std::vector<u16> ord3236({2, 1, 0});
      slog::Relation* readrel3237 = db->getRelation("Nd");
      Ndindex3079 = readrel3237->getIndex(ord3236, false);
      std::vector<u16> ord3238({2, 1, 0});
      slog::Relation* readrel3239 = db->getRelation("Nd");
      Ndindex3080 = readrel3239->getIndex(ord3238, false);
      std::vector<u16> ord3240({2, 1, 0});
      slog::Relation* readrel3241 = db->getRelation("Nd");
      Ndindex3081 = readrel3241->getIndex(ord3240, false);
      std::vector<u16> ord3242({1, 0});
      slog::Relation* readrel3243 = db->getRelation("Lf");
      Lfindex3082 = readrel3243->getIndex(ord3242, false);
      std::vector<u16> ord3244({2, 1, 0});
      slog::Relation* readrel3245 = db->getRelation("Nd");
      Ndindex3083 = readrel3245->getIndex(ord3244, false);
      std::vector<u16> ord3246({1, 0});
      slog::Relation* readrel3247 = db->getRelation("Lf");
      Lfindex3084 = readrel3247->getIndex(ord3246, false);
      std::vector<u16> ord3248({2, 1, 0});
      slog::Relation* readrel3249 = db->getRelation("Nd");
      Ndindex3085 = readrel3249->getIndex(ord3248, false);
      std::vector<u16> ord3250({2, 1, 0});
      slog::Relation* readrel3251 = db->getRelation("Nd");
      Ndindex3086 = readrel3251->getIndex(ord3250, false);
      std::vector<u16> ord3252({1, 0});
      slog::Relation* readrel3253 = db->getRelation("Lf");
      Lfindex3087 = readrel3253->getIndex(ord3252, false);
      std::vector<u16> ord3254({2, 1, 0});
      slog::Relation* readrel3255 = db->getRelation("Nd");
      Ndindex3088 = readrel3255->getIndex(ord3254, false);
      std::vector<u16> ord3256({1, 0});
      slog::Relation* readrel3257 = db->getRelation("Lf");
      Lfindex3089 = readrel3257->getIndex(ord3256, false);
      std::vector<u16> ord3258({2, 1, 0});
      slog::Relation* readrel3259 = db->getRelation("Nd");
      Ndindex3090 = readrel3259->getIndex(ord3258, false);
      std::vector<u16> ord3260({2, 1, 0});
      slog::Relation* readrel3261 = db->getRelation("Nd");
      Ndindex3091 = readrel3261->getIndex(ord3260, false);
      std::vector<u16> ord3262({2, 1, 0});
      slog::Relation* readrel3263 = db->getRelation("Nd");
      Ndindex3092 = readrel3263->getIndex(ord3262, false);
      std::vector<u16> ord3264({0, 2, 1});
      slog::Relation* readrel3265 = db->getRelation("Nd");
      Ndindex3093 = readrel3265->getIndex(ord3264, false);
      std::vector<u16> ord3266({1, 0});
      slog::Relation* readrel3267 = db->getRelation("Lf");
      Lfindex3094 = readrel3267->getIndex(ord3266, false);
      std::vector<u16> ord3268({2, 1, 0});
      slog::Relation* readrel3269 = db->getRelation("Nd");
      Ndindex3095 = readrel3269->getIndex(ord3268, false);
      std::vector<u16> ord3270({1, 0});
      slog::Relation* readrel3271 = db->getRelation("Lf");
      Lfindex3096 = readrel3271->getIndex(ord3270, false);
      std::vector<u16> ord3272({2, 1, 0});
      slog::Relation* readrel3273 = db->getRelation("Nd");
      Ndindex3097 = readrel3273->getIndex(ord3272, false);
      std::vector<u16> ord3274({2, 1, 0});
      slog::Relation* readrel3275 = db->getRelation("Nd");
      Ndindex3098 = readrel3275->getIndex(ord3274, false);
      std::vector<u16> ord3276({1, 0});
      slog::Relation* readrel3277 = db->getRelation("Lf");
      Lfindex3099 = readrel3277->getIndex(ord3276, false);
      std::vector<u16> ord3278({2, 1, 0});
      slog::Relation* readrel3279 = db->getRelation("Nd");
      Ndindex3100 = readrel3279->getIndex(ord3278, false);
      std::vector<u16> ord3280({1, 0});
      slog::Relation* readrel3281 = db->getRelation("Lf");
      Lfindex3101 = readrel3281->getIndex(ord3280, false);
      std::vector<u16> ord3282({2, 1, 0});
      slog::Relation* readrel3283 = db->getRelation("Nd");
      Ndindex3102 = readrel3283->getIndex(ord3282, false);
      std::vector<u16> ord3284({2, 1, 0});
      slog::Relation* readrel3285 = db->getRelation("Nd");
      Ndindex3103 = readrel3285->getIndex(ord3284, false);
      std::vector<u16> ord3286({0, 2, 1});
      slog::Relation* readrel3287 = db->getRelation("Nd");
      Ndindex3104 = readrel3287->getIndex(ord3286, false);
      std::vector<u16> ord3288({1, 0});
      slog::Relation* readrel3289 = db->getRelation("Lf");
      Lfindex3105 = readrel3289->getIndex(ord3288, false);
      std::vector<u16> ord3290({2, 1, 0});
      slog::Relation* readrel3291 = db->getRelation("Nd");
      Ndindex3106 = readrel3291->getIndex(ord3290, false);
      std::vector<u16> ord3292({1, 0});
      slog::Relation* readrel3293 = db->getRelation("Lf");
      Lfindex3107 = readrel3293->getIndex(ord3292, false);
      std::vector<u16> ord3294({2, 1, 0});
      slog::Relation* readrel3295 = db->getRelation("Nd");
      Ndindex3108 = readrel3295->getIndex(ord3294, false);
      std::vector<u16> ord3296({0, 2, 1});
      slog::Relation* readrel3297 = db->getRelation("Nd");
      Ndindex3109 = readrel3297->getIndex(ord3296, false);
      std::vector<u16> ord3298({1, 0});
      slog::Relation* readrel3299 = db->getRelation("Lf");
      Lfindex3110 = readrel3299->getIndex(ord3298, false);
      std::vector<u16> ord3300({0, 2, 1});
      slog::Relation* readrel3301 = db->getRelation("Nd");
      Ndindex3111 = readrel3301->getIndex(ord3300, false);
      std::vector<u16> ord3302({0, 1});
      slog::Relation* readrel3303 = db->getRelation("Lf");
      Lfindex3112 = readrel3303->getIndex(ord3302, false);
      std::vector<u16> ord3304({1, 0});
      slog::Relation* readrel3305 = db->getRelation("Lf");
      Lfindex3113 = readrel3305->getIndex(ord3304, false);
      std::vector<u16> ord3306({2, 1, 0});
      slog::Relation* readrel3307 = db->getRelation("Nd");
      Ndindex3114 = readrel3307->getIndex(ord3306, false);
      std::vector<u16> ord3308({1, 0});
      slog::Relation* readrel3309 = db->getRelation("Lf");
      Lfindex3115 = readrel3309->getIndex(ord3308, false);
      std::vector<u16> ord3310({2, 1, 0});
      slog::Relation* readrel3311 = db->getRelation("Nd");
      Ndindex3116 = readrel3311->getIndex(ord3310, false);
      std::vector<u16> ord3312({2, 1, 0});
      slog::Relation* readrel3313 = db->getRelation("Nd");
      Ndindex3117 = readrel3313->getIndex(ord3312, false);
      std::vector<u16> ord3314({1, 0});
      slog::Relation* readrel3315 = db->getRelation("Lf");
      Lfindex3118 = readrel3315->getIndex(ord3314, false);
      std::vector<u16> ord3316({2, 1, 0});
      slog::Relation* readrel3317 = db->getRelation("Nd");
      Ndindex3119 = readrel3317->getIndex(ord3316, false);
      std::vector<u16> ord3318({1, 0});
      slog::Relation* readrel3319 = db->getRelation("Lf");
      Lfindex3120 = readrel3319->getIndex(ord3318, false);
      std::vector<u16> ord3320({2, 1, 0});
      slog::Relation* readrel3321 = db->getRelation("Nd");
      Ndindex3121 = readrel3321->getIndex(ord3320, false);
      std::vector<u16> ord3322({2, 1, 0});
      slog::Relation* readrel3323 = db->getRelation("Nd");
      Ndindex3122 = readrel3323->getIndex(ord3322, false);
      std::vector<u16> ord3324({2, 1, 0});
      slog::Relation* readrel3325 = db->getRelation("Nd");
      Ndindex3123 = readrel3325->getIndex(ord3324, false);
      std::vector<u16> ord3326({1, 0});
      slog::Relation* readrel3327 = db->getRelation("Lf");
      Lfindex3124 = readrel3327->getIndex(ord3326, false);
      std::vector<u16> ord3328({2, 1, 0});
      slog::Relation* readrel3329 = db->getRelation("Nd");
      Ndindex3125 = readrel3329->getIndex(ord3328, false);
      std::vector<u16> ord3330({1, 0});
      slog::Relation* readrel3331 = db->getRelation("Lf");
      Lfindex3126 = readrel3331->getIndex(ord3330, false);
      std::vector<u16> ord3332({2, 1, 0});
      slog::Relation* readrel3333 = db->getRelation("Nd");
      Ndindex3127 = readrel3333->getIndex(ord3332, false);
      std::vector<u16> ord3334({2, 1, 0});
      slog::Relation* readrel3335 = db->getRelation("Nd");
      Ndindex3128 = readrel3335->getIndex(ord3334, false);
      std::vector<u16> ord3336({1, 0});
      slog::Relation* readrel3337 = db->getRelation("Lf");
      Lfindex3129 = readrel3337->getIndex(ord3336, false);
      std::vector<u16> ord3338({2, 1, 0});
      slog::Relation* readrel3339 = db->getRelation("Nd");
      Ndindex3130 = readrel3339->getIndex(ord3338, false);
      std::vector<u16> ord3340({1, 0});
      slog::Relation* readrel3341 = db->getRelation("Lf");
      Lfindex3131 = readrel3341->getIndex(ord3340, false);
      std::vector<u16> ord3342({2, 1, 0});
      slog::Relation* readrel3343 = db->getRelation("Nd");
      Ndindex3132 = readrel3343->getIndex(ord3342, false);
      std::vector<u16> ord3344({2, 1, 0});
      slog::Relation* readrel3345 = db->getRelation("Nd");
      Ndindex3133 = readrel3345->getIndex(ord3344, false);
      std::vector<u16> ord3346({2, 1, 0});
      slog::Relation* readrel3347 = db->getRelation("Nd");
      Ndindex3134 = readrel3347->getIndex(ord3346, false);
      std::vector<u16> ord3348({0, 2, 1});
      slog::Relation* readrel3349 = db->getRelation("Nd");
      Ndindex3135 = readrel3349->getIndex(ord3348, false);
      std::vector<u16> ord3350({1, 0});
      slog::Relation* readrel3351 = db->getRelation("Lf");
      Lfindex3136 = readrel3351->getIndex(ord3350, false);
      std::vector<u16> ord3352({2, 1, 0});
      slog::Relation* readrel3353 = db->getRelation("Nd");
      Ndindex3137 = readrel3353->getIndex(ord3352, false);
      std::vector<u16> ord3354({1, 0});
      slog::Relation* readrel3355 = db->getRelation("Lf");
      Lfindex3138 = readrel3355->getIndex(ord3354, false);
      std::vector<u16> ord3356({2, 1, 0});
      slog::Relation* readrel3357 = db->getRelation("Nd");
      Ndindex3139 = readrel3357->getIndex(ord3356, false);
      std::vector<u16> ord3358({2, 1, 0});
      slog::Relation* readrel3359 = db->getRelation("Nd");
      Ndindex3140 = readrel3359->getIndex(ord3358, false);
      std::vector<u16> ord3360({1, 0});
      slog::Relation* readrel3361 = db->getRelation("Lf");
      Lfindex3141 = readrel3361->getIndex(ord3360, false);
      std::vector<u16> ord3362({2, 1, 0});
      slog::Relation* readrel3363 = db->getRelation("Nd");
      Ndindex3142 = readrel3363->getIndex(ord3362, false);
      std::vector<u16> ord3364({1, 0});
      slog::Relation* readrel3365 = db->getRelation("Lf");
      Lfindex3143 = readrel3365->getIndex(ord3364, false);
      std::vector<u16> ord3366({2, 1, 0});
      slog::Relation* readrel3367 = db->getRelation("Nd");
      Ndindex3144 = readrel3367->getIndex(ord3366, false);
      std::vector<u16> ord3368({2, 1, 0});
      slog::Relation* readrel3369 = db->getRelation("Nd");
      Ndindex3145 = readrel3369->getIndex(ord3368, false);
      std::vector<u16> ord3370({0, 2, 1});
      slog::Relation* readrel3371 = db->getRelation("Nd");
      Ndindex3146 = readrel3371->getIndex(ord3370, false);
      std::vector<u16> ord3372({1, 0});
      slog::Relation* readrel3373 = db->getRelation("Lf");
      Lfindex3147 = readrel3373->getIndex(ord3372, false);
      std::vector<u16> ord3374({2, 1, 0});
      slog::Relation* readrel3375 = db->getRelation("Nd");
      Ndindex3148 = readrel3375->getIndex(ord3374, false);
      std::vector<u16> ord3376({1, 0});
      slog::Relation* readrel3377 = db->getRelation("Lf");
      Lfindex3149 = readrel3377->getIndex(ord3376, false);
      std::vector<u16> ord3378({2, 1, 0});
      slog::Relation* readrel3379 = db->getRelation("Nd");
      Ndindex3150 = readrel3379->getIndex(ord3378, false);
      std::vector<u16> ord3380({0, 2, 1});
      slog::Relation* readrel3381 = db->getRelation("Nd");
      Ndindex3151 = readrel3381->getIndex(ord3380, false);
      std::vector<u16> ord3382({1, 0});
      slog::Relation* readrel3383 = db->getRelation("Lf");
      Lfindex3152 = readrel3383->getIndex(ord3382, false);
      std::vector<u16> ord3384({0, 2, 1});
      slog::Relation* readrel3385 = db->getRelation("Nd");
      Ndindex3153 = readrel3385->getIndex(ord3384, false);
      std::vector<u16> ord3386({0, 1});
      slog::Relation* readrel3387 = db->getRelation("Lf");
      Lfindex3154 = readrel3387->getIndex(ord3386, false);
  
    }
    ReadTask3155(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c94 = _t[0];
        u64 v_c93 = _t[1];
        u64 v_c32 = _t[2];
        if (!slog::exists_probe<2,1>(Lfindex3040, std::array<u64,2>{v_c30, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3041, std::array<u64,2>{v_c29, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3042, std::array<u64,2>{v_c28, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3043, std::array<u64,2>{v_c27, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3044, std::array<u64,2>{v_c26, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3045, std::array<u64,2>{v_c25, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3046, std::array<u64,2>{v_c24, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3047, std::array<u64,2>{v_c23, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3048, std::array<u64,2>{v_c22, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3049, std::array<u64,2>{v_c21, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3050, std::array<u64,2>{v_c20, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3051, std::array<u64,2>{v_c19, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3052, std::array<u64,2>{v_c18, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3053, std::array<u64,2>{v_c17, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3054, std::array<u64,2>{v_c16, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3055, std::array<u64,2>{v_c15, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3056, std::array<u64,2>{v_c14, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3057, std::array<u64,2>{v_c13, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3058, std::array<u64,2>{v_c12, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3059, std::array<u64,2>{v_c11, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3060, std::array<u64,2>{v_c10, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3061, std::array<u64,2>{v_c9, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3062, std::array<u64,2>{v_c8, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3063, std::array<u64,2>{v_c7, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3064, std::array<u64,2>{v_c6, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3065, std::array<u64,2>{v_c5, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3066, std::array<u64,2>{v_c4, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3067, std::array<u64,2>{v_c3, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3068, std::array<u64,2>{v_c2, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3069, std::array<u64,2>{v_c1, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3070, std::array<u64,2>{v_c0, 0})) return;
        slog::join_probe<2,1>(Lfindex3071, std::array<u64,2>{v_c31, 0}, [&](const std::array<u64,2>& m3388) {
          u64 v_c35 = m3388[1];
          if (!slog::exists_probe<3,1>(Ndindex3072, std::array<u64,3>{v_c35, 0, 0})) return;
          slog::join_probe<2,1>(Lfindex3073, std::array<u64,2>{v_c30, 0}, [&](const std::array<u64,2>& m3389) {
            u64 v_c36 = m3389[1];
            slog::join_probe<3,2>(Ndindex3074, std::array<u64,3>{v_c35, v_c36, 0}, [&](const std::array<u64,3>& m3390) {
              u64 v_c37 = m3390[2];
              if (!slog::exists_probe<3,1>(Ndindex3075, std::array<u64,3>{v_c37, 0, 0})) return;
              slog::join_probe<2,1>(Lfindex3076, std::array<u64,2>{v_c29, 0}, [&](const std::array<u64,2>& m3391) {
                u64 v_c38 = m3391[1];
                if (!slog::exists_probe<3,1>(Ndindex3077, std::array<u64,3>{v_c38, 0, 0})) return;
                slog::join_probe<2,1>(Lfindex3078, std::array<u64,2>{v_c28, 0}, [&](const std::array<u64,2>& m3392) {
                  u64 v_c39 = m3392[1];
                  slog::join_probe<3,2>(Ndindex3079, std::array<u64,3>{v_c38, v_c39, 0}, [&](const std::array<u64,3>& m3393) {
                    u64 v_c40 = m3393[2];
                    slog::join_probe<3,2>(Ndindex3080, std::array<u64,3>{v_c37, v_c40, 0}, [&](const std::array<u64,3>& m3394) {
                      u64 v_c41 = m3394[2];
                      if (!slog::exists_probe<3,1>(Ndindex3081, std::array<u64,3>{v_c41, 0, 0})) return;
                      slog::join_probe<2,1>(Lfindex3082, std::array<u64,2>{v_c27, 0}, [&](const std::array<u64,2>& m3395) {
                        u64 v_c43 = m3395[1];
                        if (!slog::exists_probe<3,1>(Ndindex3083, std::array<u64,3>{v_c43, 0, 0})) return;
                        slog::join_probe<2,1>(Lfindex3084, std::array<u64,2>{v_c26, 0}, [&](const std::array<u64,2>& m3396) {
                          u64 v_c44 = m3396[1];
                          slog::join_probe<3,2>(Ndindex3085, std::array<u64,3>{v_c43, v_c44, 0}, [&](const std::array<u64,3>& m3397) {
                            u64 v_c45 = m3397[2];
                            if (!slog::exists_probe<3,1>(Ndindex3086, std::array<u64,3>{v_c45, 0, 0})) return;
                            slog::join_probe<2,1>(Lfindex3087, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m3398) {
                              u64 v_c47 = m3398[1];
                              if (!slog::exists_probe<3,1>(Ndindex3088, std::array<u64,3>{v_c47, 0, 0})) return;
                              slog::join_probe<2,1>(Lfindex3089, std::array<u64,2>{v_c24, 0}, [&](const std::array<u64,2>& m3399) {
                                u64 v_c48 = m3399[1];
                                slog::join_probe<3,2>(Ndindex3090, std::array<u64,3>{v_c47, v_c48, 0}, [&](const std::array<u64,3>& m3400) {
                                  u64 v_c46 = m3400[2];
                                  slog::join_probe<3,2>(Ndindex3091, std::array<u64,3>{v_c45, v_c46, 0}, [&](const std::array<u64,3>& m3401) {
                                    u64 v_c42 = m3401[2];
                                    slog::join_probe<3,2>(Ndindex3092, std::array<u64,3>{v_c41, v_c42, 0}, [&](const std::array<u64,3>& m3402) {
                                      u64 v_c34 = m3402[2];
                                      slog::join_probe<3,2>(Ndindex3093, std::array<u64,3>{v_c32, v_c34, 0}, [&](const std::array<u64,3>& m3403) {
                                        u64 v_c33 = m3403[2];
                                        slog::join_probe<2,1>(Lfindex3094, std::array<u64,2>{v_c23, 0}, [&](const std::array<u64,2>& m3404) {
                                          u64 v_c49 = m3404[1];
                                          if (!slog::exists_probe<3,1>(Ndindex3095, std::array<u64,3>{v_c49, 0, 0})) return;
                                          slog::join_probe<2,1>(Lfindex3096, std::array<u64,2>{v_c22, 0}, [&](const std::array<u64,2>& m3405) {
                                            u64 v_c50 = m3405[1];
                                            slog::join_probe<3,2>(Ndindex3097, std::array<u64,3>{v_c49, v_c50, 0}, [&](const std::array<u64,3>& m3406) {
                                              u64 v_c51 = m3406[2];
                                              if (!slog::exists_probe<3,1>(Ndindex3098, std::array<u64,3>{v_c51, 0, 0})) return;
                                              slog::join_probe<2,1>(Lfindex3099, std::array<u64,2>{v_c21, 0}, [&](const std::array<u64,2>& m3407) {
                                                u64 v_c52 = m3407[1];
                                                if (!slog::exists_probe<3,1>(Ndindex3100, std::array<u64,3>{v_c52, 0, 0})) return;
                                                slog::join_probe<2,1>(Lfindex3101, std::array<u64,2>{v_c20, 0}, [&](const std::array<u64,2>& m3408) {
                                                  u64 v_c53 = m3408[1];
                                                  slog::join_probe<3,2>(Ndindex3102, std::array<u64,3>{v_c52, v_c53, 0}, [&](const std::array<u64,3>& m3409) {
                                                    u64 v_c54 = m3409[2];
                                                    slog::join_probe<3,2>(Ndindex3103, std::array<u64,3>{v_c51, v_c54, 0}, [&](const std::array<u64,3>& m3410) {
                                                      u64 v_c55 = m3410[2];
                                                      slog::join_probe<3,2>(Ndindex3104, std::array<u64,3>{v_c33, v_c55, 0}, [&](const std::array<u64,3>& m3411) {
                                                        u64 v_c56 = m3411[2];
                                                        slog::join_probe<2,1>(Lfindex3105, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m3412) {
                                                          u64 v_c57 = m3412[1];
                                                          if (!slog::exists_probe<3,1>(Ndindex3106, std::array<u64,3>{v_c57, 0, 0})) return;
                                                          slog::join_probe<2,1>(Lfindex3107, std::array<u64,2>{v_c18, 0}, [&](const std::array<u64,2>& m3413) {
                                                            u64 v_c58 = m3413[1];
                                                            slog::join_probe<3,2>(Ndindex3108, std::array<u64,3>{v_c57, v_c58, 0}, [&](const std::array<u64,3>& m3414) {
                                                              u64 v_c59 = m3414[2];
                                                              slog::join_probe<3,2>(Ndindex3109, std::array<u64,3>{v_c56, v_c59, 0}, [&](const std::array<u64,3>& m3415) {
                                                                u64 v_c60 = m3415[2];
                                                                slog::join_probe<2,1>(Lfindex3110, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m3416) {
                                                                  u64 v_c61 = m3416[1];
                                                                  slog::join_probe<3,2>(Ndindex3111, std::array<u64,3>{v_c60, v_c61, 0}, [&](const std::array<u64,3>& m3417) {
                                                                    u64 v_c62 = m3417[2];
                                                                    slog::join_probe<2,2>(Lfindex3112, std::array<u64,2>{v_c62, v_c16}, [&](const std::array<u64,2>& m3418) {
                                                                      slog::join_probe<2,1>(Lfindex3113, std::array<u64,2>{v_c15, 0}, [&](const std::array<u64,2>& m3419) {
                                                                        u64 v_c63 = m3419[1];
                                                                        if (!slog::exists_probe<3,1>(Ndindex3114, std::array<u64,3>{v_c63, 0, 0})) return;
                                                                        slog::join_probe<2,1>(Lfindex3115, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m3420) {
                                                                          u64 v_c64 = m3420[1];
                                                                          slog::join_probe<3,2>(Ndindex3116, std::array<u64,3>{v_c63, v_c64, 0}, [&](const std::array<u64,3>& m3421) {
                                                                            u64 v_c65 = m3421[2];
                                                                            if (!slog::exists_probe<3,1>(Ndindex3117, std::array<u64,3>{v_c65, 0, 0})) return;
                                                                            slog::join_probe<2,1>(Lfindex3118, std::array<u64,2>{v_c13, 0}, [&](const std::array<u64,2>& m3422) {
                                                                              u64 v_c66 = m3422[1];
                                                                              if (!slog::exists_probe<3,1>(Ndindex3119, std::array<u64,3>{v_c66, 0, 0})) return;
                                                                              slog::join_probe<2,1>(Lfindex3120, std::array<u64,2>{v_c12, 0}, [&](const std::array<u64,2>& m3423) {
                                                                                u64 v_c67 = m3423[1];
                                                                                slog::join_probe<3,2>(Ndindex3121, std::array<u64,3>{v_c66, v_c67, 0}, [&](const std::array<u64,3>& m3424) {
                                                                                  u64 v_c68 = m3424[2];
                                                                                  slog::join_probe<3,2>(Ndindex3122, std::array<u64,3>{v_c65, v_c68, 0}, [&](const std::array<u64,3>& m3425) {
                                                                                    u64 v_c69 = m3425[2];
                                                                                    if (!slog::exists_probe<3,1>(Ndindex3123, std::array<u64,3>{v_c69, 0, 0})) return;
                                                                                    slog::join_probe<2,1>(Lfindex3124, std::array<u64,2>{v_c11, 0}, [&](const std::array<u64,2>& m3426) {
                                                                                      u64 v_c70 = m3426[1];
                                                                                      if (!slog::exists_probe<3,1>(Ndindex3125, std::array<u64,3>{v_c70, 0, 0})) return;
                                                                                      slog::join_probe<2,1>(Lfindex3126, std::array<u64,2>{v_c10, 0}, [&](const std::array<u64,2>& m3427) {
                                                                                        u64 v_c71 = m3427[1];
                                                                                        slog::join_probe<3,2>(Ndindex3127, std::array<u64,3>{v_c70, v_c71, 0}, [&](const std::array<u64,3>& m3428) {
                                                                                          u64 v_c72 = m3428[2];
                                                                                          if (!slog::exists_probe<3,1>(Ndindex3128, std::array<u64,3>{v_c72, 0, 0})) return;
                                                                                          slog::join_probe<2,1>(Lfindex3129, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m3429) {
                                                                                            u64 v_c73 = m3429[1];
                                                                                            if (!slog::exists_probe<3,1>(Ndindex3130, std::array<u64,3>{v_c73, 0, 0})) return;
                                                                                            slog::join_probe<2,1>(Lfindex3131, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m3430) {
                                                                                              u64 v_c74 = m3430[1];
                                                                                              slog::join_probe<3,2>(Ndindex3132, std::array<u64,3>{v_c73, v_c74, 0}, [&](const std::array<u64,3>& m3431) {
                                                                                                u64 v_c75 = m3431[2];
                                                                                                slog::join_probe<3,2>(Ndindex3133, std::array<u64,3>{v_c72, v_c75, 0}, [&](const std::array<u64,3>& m3432) {
                                                                                                  u64 v_c76 = m3432[2];
                                                                                                  slog::join_probe<3,2>(Ndindex3134, std::array<u64,3>{v_c69, v_c76, 0}, [&](const std::array<u64,3>& m3433) {
                                                                                                    u64 v_c77 = m3433[2];
                                                                                                    slog::join_probe<3,2>(Ndindex3135, std::array<u64,3>{v_c93, v_c77, 0}, [&](const std::array<u64,3>& m3434) {
                                                                                                      u64 v_c92 = m3434[2];
                                                                                                      slog::join_probe<2,1>(Lfindex3136, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m3435) {
                                                                                                        u64 v_c78 = m3435[1];
                                                                                                        if (!slog::exists_probe<3,1>(Ndindex3137, std::array<u64,3>{v_c78, 0, 0})) return;
                                                                                                        slog::join_probe<2,1>(Lfindex3138, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m3436) {
                                                                                                          u64 v_c79 = m3436[1];
                                                                                                          slog::join_probe<3,2>(Ndindex3139, std::array<u64,3>{v_c78, v_c79, 0}, [&](const std::array<u64,3>& m3437) {
                                                                                                            u64 v_c80 = m3437[2];
                                                                                                            if (!slog::exists_probe<3,1>(Ndindex3140, std::array<u64,3>{v_c80, 0, 0})) return;
                                                                                                            slog::join_probe<2,1>(Lfindex3141, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m3438) {
                                                                                                              u64 v_c81 = m3438[1];
                                                                                                              if (!slog::exists_probe<3,1>(Ndindex3142, std::array<u64,3>{v_c81, 0, 0})) return;
                                                                                                              slog::join_probe<2,1>(Lfindex3143, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m3439) {
                                                                                                                u64 v_c82 = m3439[1];
                                                                                                                slog::join_probe<3,2>(Ndindex3144, std::array<u64,3>{v_c81, v_c82, 0}, [&](const std::array<u64,3>& m3440) {
                                                                                                                  u64 v_c83 = m3440[2];
                                                                                                                  slog::join_probe<3,2>(Ndindex3145, std::array<u64,3>{v_c80, v_c83, 0}, [&](const std::array<u64,3>& m3441) {
                                                                                                                    u64 v_c84 = m3441[2];
                                                                                                                    slog::join_probe<3,2>(Ndindex3146, std::array<u64,3>{v_c92, v_c84, 0}, [&](const std::array<u64,3>& m3442) {
                                                                                                                      u64 v_c91 = m3442[2];
                                                                                                                      slog::join_probe<2,1>(Lfindex3147, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m3443) {
                                                                                                                        u64 v_c85 = m3443[1];
                                                                                                                        if (!slog::exists_probe<3,1>(Ndindex3148, std::array<u64,3>{v_c85, 0, 0})) return;
                                                                                                                        slog::join_probe<2,1>(Lfindex3149, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m3444) {
                                                                                                                          u64 v_c86 = m3444[1];
                                                                                                                          slog::join_probe<3,2>(Ndindex3150, std::array<u64,3>{v_c85, v_c86, 0}, [&](const std::array<u64,3>& m3445) {
                                                                                                                            u64 v_c87 = m3445[2];
                                                                                                                            slog::join_probe<3,2>(Ndindex3151, std::array<u64,3>{v_c91, v_c87, 0}, [&](const std::array<u64,3>& m3446) {
                                                                                                                              u64 v_c90 = m3446[2];
                                                                                                                              slog::join_probe<2,1>(Lfindex3152, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m3447) {
                                                                                                                                u64 v_c88 = m3447[1];
                                                                                                                                slog::join_probe<3,2>(Ndindex3153, std::array<u64,3>{v_c90, v_c88, 0}, [&](const std::array<u64,3>& m3448) {
                                                                                                                                  u64 v_c89 = m3448[2];
                                                                                                                                  slog::join_probe<2,2>(Lfindex3154, std::array<u64,2>{v_c89, v_c0}, [&](const std::array<u64,2>& m3449) {
                                                                                                                                    ++_fires;
                                                                                                                                    slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c94}, std::array<u16,1>{0});
                                                                                                                                  });
                                                                                                                                });
                                                                                                                              });
                                                                                                                            });
                                                                                                                          });
                                                                                                                        });
                                                                                                                      });
                                                                                                                    });
                                                                                                                  });
                                                                                                                });
                                                                                                              });
                                                                                                            });
                                                                                                          });
                                                                                                        });
                                                                                                      });
                                                                                                    });
                                                                                                  });
                                                                                                });
                                                                                              });
                                                                                            });
                                                                                          });
                                                                                        });
                                                                                      });
                                                                                    });
                                                                                  });
                                                                                });
                                                                              });
                                                                            });
                                                                          });
                                                                        });
                                                                      });
                                                                    });
                                                                  });
                                                                });
                                                              });
                                                            });
                                                          });
                                                        });
                                                      });
                                                    });
                                                  });
                                                });
                                              });
                                            });
                                          });
                                        });
                                      });
                                    });
                                  });
                                });
                              });
                            });
                          });
                        });
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
  
      if (_fires) db->bumpFires("deep_fact.slog:7", "delta:Nd", _fires);
  
      if (!_done)
      {
        ReadTask3155* _cont = new ReadTask3155(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask3155(db,b), false);
  // (crule (pre (let __tconst48SJ108 const6b86b273ff34fce19d6b804e) (let __tconst5Uhl106 constd4735e3a265e16eee03f5971) (let __tconst9YpM103 const4e07408562bedb8b60ce05c1) (let __tconst3iHp101 const4b227777d4dd1fc61c6f884f) (let __tconst0Emh97 constef2d127de37b942baad06145) (let __tconst29xA95 conste7f6c011776e8db7cd330b54) (let __tconst9mjQ92 const7902699be42c8a8e46fbbb45) (let __tconst9Yxv90 const2c624232cdd221771294dfbb) (let __tconst7wWY85 const19581e27de7ced00ff1ce50b) (let __tconst01Wl83 const4a44dc15364204a80fe80e90) (let __tconst42lR80 const4fc82b26aecb47d2868c4efb) (let __tconst3KyY78 const6b51d431df5d7f141cbececc) (let __tconst6a9N74 const3fdba35f04dc8c462986c992) (let __tconst74Qx72 const8527a891e224136950ff32ca) (let __tconst2hOw69 conste629fa6598d732768f7c726b) (let __tconst7kHD67 constb17ef6d19c7a5b1ee83b907c) (let __tconst5zmq61 const4523540f1504cd17100c4835) (let __tconst31qC59 const4ec9599fc203d176a301536c) (let __tconst4Vop56 const9400f1b21cb527d7fa3d3eab) (let __tconst51zc54 constf5ca38f748a1d6eaf726b8a4) (let __tconst6Qm150 const6f4b6612125fb3a0daecd279) (let __tconst6bEj48 const785f3ec7eb32f30b90cd0fcf) (let __tconst7AKN45 const535fa30d7e25dd8a49f15367) (let __tconst9j2a43 constc2356069e9d1e79ca9243781) (let __tconst1Mto38 constb7a56873cd771f2c446d369b) (let __tconst8u8i36 const5f9c4ab08cac7457e9111a30) (let __tconst2Isx33 const670671cd97404156226e5079) (let __tconst8J6R31 const59e19706d51d39f66711c265) (let __tconst88cs27 const35135aaa6cc23891b40cb3f3) (let __tconst0Uuf25 const624b60c58c9d8bfb6ff1886c) (let __tconst6sf622 consteb1e33e8a81b697b75855af6) (let __tconst5Run20 conste29c9c180c6279b0b02abd6a)) (seeded) (body (join Lf (1 0) 1 __tconst5Run20 __t8mDO21) (exists Nd (2 1 0) 1 __t8mDO21) (exists Lf (1 0) 1 __tconst0Uuf25) (exists Lf (1 0) 1 __tconst88cs27) (exists Lf (1 0) 1 __tconst8J6R31) (exists Lf (1 0) 1 __tconst2Isx33) (exists Lf (1 0) 1 __tconst8u8i36) (exists Lf (1 0) 1 __tconst1Mto38) (exists Lf (1 0) 1 __tconst9j2a43) (exists Lf (1 0) 1 __tconst7AKN45) (exists Lf (1 0) 1 __tconst6bEj48) (exists Lf (1 0) 1 __tconst6Qm150) (exists Lf (1 0) 1 __tconst51zc54) (exists Lf (1 0) 1 __tconst4Vop56) (exists Lf (1 0) 1 __tconst31qC59) (exists Lf (1 0) 1 __tconst5zmq61) (exists Lf (1 0) 1 __tconst7kHD67) (exists Lf (1 0) 1 __tconst2hOw69) (exists Lf (1 0) 1 __tconst74Qx72) (exists Lf (1 0) 1 __tconst6a9N74) (exists Lf (1 0) 1 __tconst3KyY78) (exists Lf (1 0) 1 __tconst42lR80) (exists Lf (1 0) 1 __tconst01Wl83) (exists Lf (1 0) 1 __tconst7wWY85) (exists Lf (1 0) 1 __tconst9Yxv90) (exists Lf (1 0) 1 __tconst9mjQ92) (exists Lf (1 0) 1 __tconst29xA95) (exists Lf (1 0) 1 __tconst0Emh97) (exists Lf (1 0) 1 __tconst3iHp101) (exists Lf (1 0) 1 __tconst9YpM103) (exists Lf (1 0) 1 __tconst5Uhl106) (exists Lf (1 0) 1 __tconst48SJ108) (join Lf (1 0) 1 __tconst6sf622 __t1M8o23) (join Nd (2 1 0) 2 __t8mDO21 __t1M8o23 __t7LF824) (join Lf (1 0) 1 __tconst0Uuf25 __t1NQv26) (exists Nd (2 1 0) 1 __t1NQv26) (join Lf (1 0) 1 __tconst88cs27 __t7d0c28) (join Nd (2 1 0) 2 __t1NQv26 __t7d0c28 __t0kIY29) (join Lf (1 0) 1 __tconst8J6R31 __t9vh832) (exists Nd (2 1 0) 1 __t9vh832) (join Lf (1 0) 1 __tconst2Isx33 __t5flt34) (join Nd (2 1 0) 2 __t9vh832 __t5flt34 __t3jHg35) (join Lf (1 0) 1 __tconst8u8i36 __t27Zr37) (exists Nd (2 1 0) 1 __t27Zr37) (join Lf (1 0) 1 __tconst1Mto38 __t3UFu39) (join Nd (2 1 0) 2 __t27Zr37 __t3UFu39 __t8qqV40) (join Lf (1 0) 1 __tconst9j2a43 __t6IKq44) (exists Nd (2 1 0) 1 __t6IKq44) (join Lf (1 0) 1 __tconst7AKN45 __t6LIW46) (join Nd (2 1 0) 2 __t6IKq44 __t6LIW46 __t7C7d47) (join Lf (1 0) 1 __tconst6bEj48 __t9k7a49) (exists Nd (2 1 0) 1 __t9k7a49) (join Lf (1 0) 1 __tconst6Qm150 __t4MdC51) (join Nd (2 1 0) 2 __t9k7a49 __t4MdC51 __t8A9i52) (join Lf (1 0) 1 __tconst51zc54 __t3Yon55) (exists Nd (2 1 0) 1 __t3Yon55) (join Lf (1 0) 1 __tconst4Vop56 __t5ik157) (join Nd (2 1 0) 2 __t3Yon55 __t5ik157 __t4hi358) (join Lf (1 0) 1 __tconst31qC59 __t1nkJ60) (exists Nd (2 1 0) 1 __t1nkJ60) (join Lf (1 0) 1 __tconst5zmq61 __t4E3D62) (join Nd (2 1 0) 2 __t1nkJ60 __t4E3D62 __t8TXU63) (join Lf (1 0) 1 __tconst7kHD67 __t4J2N68) (exists Nd (2 1 0) 1 __t4J2N68) (join Lf (1 0) 1 __tconst2hOw69 __t4izo70) (join Nd (2 1 0) 2 __t4J2N68 __t4izo70 __t14Ff71) (join Lf (1 0) 1 __tconst74Qx72 __t319l73) (exists Nd (2 1 0) 1 __t319l73) (join Lf (1 0) 1 __tconst6a9N74 __t0amQ75) (join Nd (2 1 0) 2 __t319l73 __t0amQ75 __t4MUf76) (join Lf (1 0) 1 __tconst3KyY78 __t13gt79) (exists Nd (2 1 0) 1 __t13gt79) (join Lf (1 0) 1 __tconst42lR80 __t3ESz81) (join Nd (2 1 0) 2 __t13gt79 __t3ESz81 __t3WL082) (join Lf (1 0) 1 __tconst01Wl83 __t4Da384) (exists Nd (2 1 0) 1 __t4Da384) (join Lf (1 0) 1 __tconst7wWY85 __t91gs86) (join Nd (2 1 0) 2 __t4Da384 __t91gs86 __t02Bu87) (join Lf (1 0) 1 __tconst9Yxv90 __t7UaH91) (exists Nd (2 1 0) 1 __t7UaH91) (join Lf (1 0) 1 __tconst9mjQ92 __t6IMg93) (join Nd (2 1 0) 2 __t7UaH91 __t6IMg93 __t2T3i94) (join Lf (1 0) 1 __tconst29xA95 __t2oHE96) (exists Nd (2 1 0) 1 __t2oHE96) (join Lf (1 0) 1 __tconst0Emh97 __t7bue98) (join Nd (2 1 0) 2 __t2oHE96 __t7bue98 __t0HkS99) (join Lf (1 0) 1 __tconst3iHp101 __t5yzC102) (exists Nd (2 1 0) 1 __t5yzC102) (join Lf (1 0) 1 __tconst9YpM103 __t7c21104) (join Nd (2 1 0) 2 __t5yzC102 __t7c21104 __t4bRV105) (join Lf (1 0) 1 __tconst5Uhl106 __t1IJA107) (exists Nd (2 1 0) 1 __t1IJA107) (join Lf (1 0) 1 __tconst48SJ108 __t0y5t109) (join Nd (2 1 0) 2 __t1IJA107 __t0y5t109 __t76VS110)) (head (mkstruct Nd (2 1 0) __t3a3T111 __t4bRV105 __t76VS110) (mkstruct Nd (2 1 0) __t7PLp100 __t2T3i94 __t0HkS99) (mkstruct Nd (2 1 0) __t60KJ88 __t3WL082 __t02Bu87) (mkstruct Nd (2 1 0) __t13Wj77 __t14Ff71 __t4MUf76) (mkstruct Nd (2 1 0) __t6bZq64 __t4hi358 __t8TXU63) (mkstruct Nd (2 1 0) __t7DSY53 __t7C7d47 __t8A9i52) (mkstruct Nd (2 1 0) __t2KtK41 __t3jHg35 __t8qqV40) (mkstruct Nd (2 1 0) __t6JrG30 __t7LF824 __t0kIY29)) deep_fact.slog:7 #f)
  class ReadTask3544 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[8];
    slog::Index** head_index[8];
  
  
  
  
  
  
    slog::Index** Lfindex3450;  slog::Index** Ndindex3451;  slog::Index** Lfindex3452;  slog::Index** Lfindex3453;  slog::Index** Lfindex3454;  slog::Index** Lfindex3455;  slog::Index** Lfindex3456;  slog::Index** Lfindex3457;  slog::Index** Lfindex3458;  slog::Index** Lfindex3459;  slog::Index** Lfindex3460;  slog::Index** Lfindex3461;  slog::Index** Lfindex3462;  slog::Index** Lfindex3463;  slog::Index** Lfindex3464;  slog::Index** Lfindex3465;  slog::Index** Lfindex3466;  slog::Index** Lfindex3467;  slog::Index** Lfindex3468;  slog::Index** Lfindex3469;  slog::Index** Lfindex3470;  slog::Index** Lfindex3471;  slog::Index** Lfindex3472;  slog::Index** Lfindex3473;  slog::Index** Lfindex3474;  slog::Index** Lfindex3475;  slog::Index** Lfindex3476;  slog::Index** Lfindex3477;  slog::Index** Lfindex3478;  slog::Index** Lfindex3479;  slog::Index** Lfindex3480;  slog::Index** Lfindex3481;  slog::Index** Lfindex3482;  slog::Index** Ndindex3483;  slog::Index** Lfindex3484;  slog::Index** Ndindex3485;  slog::Index** Lfindex3486;  slog::Index** Ndindex3487;  slog::Index** Lfindex3488;  slog::Index** Ndindex3489;  slog::Index** Lfindex3490;  slog::Index** Ndindex3491;  slog::Index** Lfindex3492;  slog::Index** Ndindex3493;  slog::Index** Lfindex3494;  slog::Index** Ndindex3495;  slog::Index** Lfindex3496;  slog::Index** Ndindex3497;  slog::Index** Lfindex3498;  slog::Index** Ndindex3499;  slog::Index** Lfindex3500;  slog::Index** Ndindex3501;  slog::Index** Lfindex3502;  slog::Index** Ndindex3503;  slog::Index** Lfindex3504;  slog::Index** Ndindex3505;  slog::Index** Lfindex3506;  slog::Index** Ndindex3507;  slog::Index** Lfindex3508;  slog::Index** Ndindex3509;  slog::Index** Lfindex3510;  slog::Index** Ndindex3511;  slog::Index** Lfindex3512;  slog::Index** Ndindex3513;  slog::Index** Lfindex3514;  slog::Index** Ndindex3515;  slog::Index** Lfindex3516;  slog::Index** Ndindex3517;  slog::Index** Lfindex3518;  slog::Index** Ndindex3519;  slog::Index** Lfindex3520;  slog::Index** Ndindex3521;  slog::Index** Lfindex3522;  slog::Index** Ndindex3523;  slog::Index** Lfindex3524;  slog::Index** Ndindex3525;  slog::Index** Lfindex3526;  slog::Index** Ndindex3527;  slog::Index** Lfindex3528;  slog::Index** Ndindex3529;  slog::Index** Lfindex3530;  slog::Index** Ndindex3531;  slog::Index** Lfindex3532;  slog::Index** Ndindex3533;  slog::Index** Lfindex3534;  slog::Index** Ndindex3535;  slog::Index** Lfindex3536;  slog::Index** Ndindex3537;  slog::Index** Lfindex3538;  slog::Index** Ndindex3539;  slog::Index** Lfindex3540;  slog::Index** Ndindex3541;  slog::Index** Lfindex3542;  slog::Index** Ndindex3543;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("Nd");
      std::vector<u16> ord3545({2, 1, 0});
      slog::Relation* readrel3546 = db->getRelation("Nd");
      head_index[0] = readrel3546->getIndex(ord3545, false);
      head_rel[1] = db->getRelation("Nd");
      std::vector<u16> ord3547({2, 1, 0});
      slog::Relation* readrel3548 = db->getRelation("Nd");
      head_index[1] = readrel3548->getIndex(ord3547, false);
      head_rel[2] = db->getRelation("Nd");
      std::vector<u16> ord3549({2, 1, 0});
      slog::Relation* readrel3550 = db->getRelation("Nd");
      head_index[2] = readrel3550->getIndex(ord3549, false);
      head_rel[3] = db->getRelation("Nd");
      std::vector<u16> ord3551({2, 1, 0});
      slog::Relation* readrel3552 = db->getRelation("Nd");
      head_index[3] = readrel3552->getIndex(ord3551, false);
      head_rel[4] = db->getRelation("Nd");
      std::vector<u16> ord3553({2, 1, 0});
      slog::Relation* readrel3554 = db->getRelation("Nd");
      head_index[4] = readrel3554->getIndex(ord3553, false);
      head_rel[5] = db->getRelation("Nd");
      std::vector<u16> ord3555({2, 1, 0});
      slog::Relation* readrel3556 = db->getRelation("Nd");
      head_index[5] = readrel3556->getIndex(ord3555, false);
      head_rel[6] = db->getRelation("Nd");
      std::vector<u16> ord3557({2, 1, 0});
      slog::Relation* readrel3558 = db->getRelation("Nd");
      head_index[6] = readrel3558->getIndex(ord3557, false);
      head_rel[7] = db->getRelation("Nd");
      std::vector<u16> ord3559({2, 1, 0});
      slog::Relation* readrel3560 = db->getRelation("Nd");
      head_index[7] = readrel3560->getIndex(ord3559, false);
      std::vector<u16> ord3561({1, 0});
      slog::Relation* readrel3562 = db->getRelation("Lf");
      Lfindex3450 = readrel3562->getIndex(ord3561, false);
      std::vector<u16> ord3563({2, 1, 0});
      slog::Relation* readrel3564 = db->getRelation("Nd");
      Ndindex3451 = readrel3564->getIndex(ord3563, false);
      std::vector<u16> ord3565({1, 0});
      slog::Relation* readrel3566 = db->getRelation("Lf");
      Lfindex3452 = readrel3566->getIndex(ord3565, false);
      std::vector<u16> ord3567({1, 0});
      slog::Relation* readrel3568 = db->getRelation("Lf");
      Lfindex3453 = readrel3568->getIndex(ord3567, false);
      std::vector<u16> ord3569({1, 0});
      slog::Relation* readrel3570 = db->getRelation("Lf");
      Lfindex3454 = readrel3570->getIndex(ord3569, false);
      std::vector<u16> ord3571({1, 0});
      slog::Relation* readrel3572 = db->getRelation("Lf");
      Lfindex3455 = readrel3572->getIndex(ord3571, false);
      std::vector<u16> ord3573({1, 0});
      slog::Relation* readrel3574 = db->getRelation("Lf");
      Lfindex3456 = readrel3574->getIndex(ord3573, false);
      std::vector<u16> ord3575({1, 0});
      slog::Relation* readrel3576 = db->getRelation("Lf");
      Lfindex3457 = readrel3576->getIndex(ord3575, false);
      std::vector<u16> ord3577({1, 0});
      slog::Relation* readrel3578 = db->getRelation("Lf");
      Lfindex3458 = readrel3578->getIndex(ord3577, false);
      std::vector<u16> ord3579({1, 0});
      slog::Relation* readrel3580 = db->getRelation("Lf");
      Lfindex3459 = readrel3580->getIndex(ord3579, false);
      std::vector<u16> ord3581({1, 0});
      slog::Relation* readrel3582 = db->getRelation("Lf");
      Lfindex3460 = readrel3582->getIndex(ord3581, false);
      std::vector<u16> ord3583({1, 0});
      slog::Relation* readrel3584 = db->getRelation("Lf");
      Lfindex3461 = readrel3584->getIndex(ord3583, false);
      std::vector<u16> ord3585({1, 0});
      slog::Relation* readrel3586 = db->getRelation("Lf");
      Lfindex3462 = readrel3586->getIndex(ord3585, false);
      std::vector<u16> ord3587({1, 0});
      slog::Relation* readrel3588 = db->getRelation("Lf");
      Lfindex3463 = readrel3588->getIndex(ord3587, false);
      std::vector<u16> ord3589({1, 0});
      slog::Relation* readrel3590 = db->getRelation("Lf");
      Lfindex3464 = readrel3590->getIndex(ord3589, false);
      std::vector<u16> ord3591({1, 0});
      slog::Relation* readrel3592 = db->getRelation("Lf");
      Lfindex3465 = readrel3592->getIndex(ord3591, false);
      std::vector<u16> ord3593({1, 0});
      slog::Relation* readrel3594 = db->getRelation("Lf");
      Lfindex3466 = readrel3594->getIndex(ord3593, false);
      std::vector<u16> ord3595({1, 0});
      slog::Relation* readrel3596 = db->getRelation("Lf");
      Lfindex3467 = readrel3596->getIndex(ord3595, false);
      std::vector<u16> ord3597({1, 0});
      slog::Relation* readrel3598 = db->getRelation("Lf");
      Lfindex3468 = readrel3598->getIndex(ord3597, false);
      std::vector<u16> ord3599({1, 0});
      slog::Relation* readrel3600 = db->getRelation("Lf");
      Lfindex3469 = readrel3600->getIndex(ord3599, false);
      std::vector<u16> ord3601({1, 0});
      slog::Relation* readrel3602 = db->getRelation("Lf");
      Lfindex3470 = readrel3602->getIndex(ord3601, false);
      std::vector<u16> ord3603({1, 0});
      slog::Relation* readrel3604 = db->getRelation("Lf");
      Lfindex3471 = readrel3604->getIndex(ord3603, false);
      std::vector<u16> ord3605({1, 0});
      slog::Relation* readrel3606 = db->getRelation("Lf");
      Lfindex3472 = readrel3606->getIndex(ord3605, false);
      std::vector<u16> ord3607({1, 0});
      slog::Relation* readrel3608 = db->getRelation("Lf");
      Lfindex3473 = readrel3608->getIndex(ord3607, false);
      std::vector<u16> ord3609({1, 0});
      slog::Relation* readrel3610 = db->getRelation("Lf");
      Lfindex3474 = readrel3610->getIndex(ord3609, false);
      std::vector<u16> ord3611({1, 0});
      slog::Relation* readrel3612 = db->getRelation("Lf");
      Lfindex3475 = readrel3612->getIndex(ord3611, false);
      std::vector<u16> ord3613({1, 0});
      slog::Relation* readrel3614 = db->getRelation("Lf");
      Lfindex3476 = readrel3614->getIndex(ord3613, false);
      std::vector<u16> ord3615({1, 0});
      slog::Relation* readrel3616 = db->getRelation("Lf");
      Lfindex3477 = readrel3616->getIndex(ord3615, false);
      std::vector<u16> ord3617({1, 0});
      slog::Relation* readrel3618 = db->getRelation("Lf");
      Lfindex3478 = readrel3618->getIndex(ord3617, false);
      std::vector<u16> ord3619({1, 0});
      slog::Relation* readrel3620 = db->getRelation("Lf");
      Lfindex3479 = readrel3620->getIndex(ord3619, false);
      std::vector<u16> ord3621({1, 0});
      slog::Relation* readrel3622 = db->getRelation("Lf");
      Lfindex3480 = readrel3622->getIndex(ord3621, false);
      std::vector<u16> ord3623({1, 0});
      slog::Relation* readrel3624 = db->getRelation("Lf");
      Lfindex3481 = readrel3624->getIndex(ord3623, false);
      std::vector<u16> ord3625({1, 0});
      slog::Relation* readrel3626 = db->getRelation("Lf");
      Lfindex3482 = readrel3626->getIndex(ord3625, false);
      std::vector<u16> ord3627({2, 1, 0});
      slog::Relation* readrel3628 = db->getRelation("Nd");
      Ndindex3483 = readrel3628->getIndex(ord3627, false);
      std::vector<u16> ord3629({1, 0});
      slog::Relation* readrel3630 = db->getRelation("Lf");
      Lfindex3484 = readrel3630->getIndex(ord3629, false);
      std::vector<u16> ord3631({2, 1, 0});
      slog::Relation* readrel3632 = db->getRelation("Nd");
      Ndindex3485 = readrel3632->getIndex(ord3631, false);
      std::vector<u16> ord3633({1, 0});
      slog::Relation* readrel3634 = db->getRelation("Lf");
      Lfindex3486 = readrel3634->getIndex(ord3633, false);
      std::vector<u16> ord3635({2, 1, 0});
      slog::Relation* readrel3636 = db->getRelation("Nd");
      Ndindex3487 = readrel3636->getIndex(ord3635, false);
      std::vector<u16> ord3637({1, 0});
      slog::Relation* readrel3638 = db->getRelation("Lf");
      Lfindex3488 = readrel3638->getIndex(ord3637, false);
      std::vector<u16> ord3639({2, 1, 0});
      slog::Relation* readrel3640 = db->getRelation("Nd");
      Ndindex3489 = readrel3640->getIndex(ord3639, false);
      std::vector<u16> ord3641({1, 0});
      slog::Relation* readrel3642 = db->getRelation("Lf");
      Lfindex3490 = readrel3642->getIndex(ord3641, false);
      std::vector<u16> ord3643({2, 1, 0});
      slog::Relation* readrel3644 = db->getRelation("Nd");
      Ndindex3491 = readrel3644->getIndex(ord3643, false);
      std::vector<u16> ord3645({1, 0});
      slog::Relation* readrel3646 = db->getRelation("Lf");
      Lfindex3492 = readrel3646->getIndex(ord3645, false);
      std::vector<u16> ord3647({2, 1, 0});
      slog::Relation* readrel3648 = db->getRelation("Nd");
      Ndindex3493 = readrel3648->getIndex(ord3647, false);
      std::vector<u16> ord3649({1, 0});
      slog::Relation* readrel3650 = db->getRelation("Lf");
      Lfindex3494 = readrel3650->getIndex(ord3649, false);
      std::vector<u16> ord3651({2, 1, 0});
      slog::Relation* readrel3652 = db->getRelation("Nd");
      Ndindex3495 = readrel3652->getIndex(ord3651, false);
      std::vector<u16> ord3653({1, 0});
      slog::Relation* readrel3654 = db->getRelation("Lf");
      Lfindex3496 = readrel3654->getIndex(ord3653, false);
      std::vector<u16> ord3655({2, 1, 0});
      slog::Relation* readrel3656 = db->getRelation("Nd");
      Ndindex3497 = readrel3656->getIndex(ord3655, false);
      std::vector<u16> ord3657({1, 0});
      slog::Relation* readrel3658 = db->getRelation("Lf");
      Lfindex3498 = readrel3658->getIndex(ord3657, false);
      std::vector<u16> ord3659({2, 1, 0});
      slog::Relation* readrel3660 = db->getRelation("Nd");
      Ndindex3499 = readrel3660->getIndex(ord3659, false);
      std::vector<u16> ord3661({1, 0});
      slog::Relation* readrel3662 = db->getRelation("Lf");
      Lfindex3500 = readrel3662->getIndex(ord3661, false);
      std::vector<u16> ord3663({2, 1, 0});
      slog::Relation* readrel3664 = db->getRelation("Nd");
      Ndindex3501 = readrel3664->getIndex(ord3663, false);
      std::vector<u16> ord3665({1, 0});
      slog::Relation* readrel3666 = db->getRelation("Lf");
      Lfindex3502 = readrel3666->getIndex(ord3665, false);
      std::vector<u16> ord3667({2, 1, 0});
      slog::Relation* readrel3668 = db->getRelation("Nd");
      Ndindex3503 = readrel3668->getIndex(ord3667, false);
      std::vector<u16> ord3669({1, 0});
      slog::Relation* readrel3670 = db->getRelation("Lf");
      Lfindex3504 = readrel3670->getIndex(ord3669, false);
      std::vector<u16> ord3671({2, 1, 0});
      slog::Relation* readrel3672 = db->getRelation("Nd");
      Ndindex3505 = readrel3672->getIndex(ord3671, false);
      std::vector<u16> ord3673({1, 0});
      slog::Relation* readrel3674 = db->getRelation("Lf");
      Lfindex3506 = readrel3674->getIndex(ord3673, false);
      std::vector<u16> ord3675({2, 1, 0});
      slog::Relation* readrel3676 = db->getRelation("Nd");
      Ndindex3507 = readrel3676->getIndex(ord3675, false);
      std::vector<u16> ord3677({1, 0});
      slog::Relation* readrel3678 = db->getRelation("Lf");
      Lfindex3508 = readrel3678->getIndex(ord3677, false);
      std::vector<u16> ord3679({2, 1, 0});
      slog::Relation* readrel3680 = db->getRelation("Nd");
      Ndindex3509 = readrel3680->getIndex(ord3679, false);
      std::vector<u16> ord3681({1, 0});
      slog::Relation* readrel3682 = db->getRelation("Lf");
      Lfindex3510 = readrel3682->getIndex(ord3681, false);
      std::vector<u16> ord3683({2, 1, 0});
      slog::Relation* readrel3684 = db->getRelation("Nd");
      Ndindex3511 = readrel3684->getIndex(ord3683, false);
      std::vector<u16> ord3685({1, 0});
      slog::Relation* readrel3686 = db->getRelation("Lf");
      Lfindex3512 = readrel3686->getIndex(ord3685, false);
      std::vector<u16> ord3687({2, 1, 0});
      slog::Relation* readrel3688 = db->getRelation("Nd");
      Ndindex3513 = readrel3688->getIndex(ord3687, false);
      std::vector<u16> ord3689({1, 0});
      slog::Relation* readrel3690 = db->getRelation("Lf");
      Lfindex3514 = readrel3690->getIndex(ord3689, false);
      std::vector<u16> ord3691({2, 1, 0});
      slog::Relation* readrel3692 = db->getRelation("Nd");
      Ndindex3515 = readrel3692->getIndex(ord3691, false);
      std::vector<u16> ord3693({1, 0});
      slog::Relation* readrel3694 = db->getRelation("Lf");
      Lfindex3516 = readrel3694->getIndex(ord3693, false);
      std::vector<u16> ord3695({2, 1, 0});
      slog::Relation* readrel3696 = db->getRelation("Nd");
      Ndindex3517 = readrel3696->getIndex(ord3695, false);
      std::vector<u16> ord3697({1, 0});
      slog::Relation* readrel3698 = db->getRelation("Lf");
      Lfindex3518 = readrel3698->getIndex(ord3697, false);
      std::vector<u16> ord3699({2, 1, 0});
      slog::Relation* readrel3700 = db->getRelation("Nd");
      Ndindex3519 = readrel3700->getIndex(ord3699, false);
      std::vector<u16> ord3701({1, 0});
      slog::Relation* readrel3702 = db->getRelation("Lf");
      Lfindex3520 = readrel3702->getIndex(ord3701, false);
      std::vector<u16> ord3703({2, 1, 0});
      slog::Relation* readrel3704 = db->getRelation("Nd");
      Ndindex3521 = readrel3704->getIndex(ord3703, false);
      std::vector<u16> ord3705({1, 0});
      slog::Relation* readrel3706 = db->getRelation("Lf");
      Lfindex3522 = readrel3706->getIndex(ord3705, false);
      std::vector<u16> ord3707({2, 1, 0});
      slog::Relation* readrel3708 = db->getRelation("Nd");
      Ndindex3523 = readrel3708->getIndex(ord3707, false);
      std::vector<u16> ord3709({1, 0});
      slog::Relation* readrel3710 = db->getRelation("Lf");
      Lfindex3524 = readrel3710->getIndex(ord3709, false);
      std::vector<u16> ord3711({2, 1, 0});
      slog::Relation* readrel3712 = db->getRelation("Nd");
      Ndindex3525 = readrel3712->getIndex(ord3711, false);
      std::vector<u16> ord3713({1, 0});
      slog::Relation* readrel3714 = db->getRelation("Lf");
      Lfindex3526 = readrel3714->getIndex(ord3713, false);
      std::vector<u16> ord3715({2, 1, 0});
      slog::Relation* readrel3716 = db->getRelation("Nd");
      Ndindex3527 = readrel3716->getIndex(ord3715, false);
      std::vector<u16> ord3717({1, 0});
      slog::Relation* readrel3718 = db->getRelation("Lf");
      Lfindex3528 = readrel3718->getIndex(ord3717, false);
      std::vector<u16> ord3719({2, 1, 0});
      slog::Relation* readrel3720 = db->getRelation("Nd");
      Ndindex3529 = readrel3720->getIndex(ord3719, false);
      std::vector<u16> ord3721({1, 0});
      slog::Relation* readrel3722 = db->getRelation("Lf");
      Lfindex3530 = readrel3722->getIndex(ord3721, false);
      std::vector<u16> ord3723({2, 1, 0});
      slog::Relation* readrel3724 = db->getRelation("Nd");
      Ndindex3531 = readrel3724->getIndex(ord3723, false);
      std::vector<u16> ord3725({1, 0});
      slog::Relation* readrel3726 = db->getRelation("Lf");
      Lfindex3532 = readrel3726->getIndex(ord3725, false);
      std::vector<u16> ord3727({2, 1, 0});
      slog::Relation* readrel3728 = db->getRelation("Nd");
      Ndindex3533 = readrel3728->getIndex(ord3727, false);
      std::vector<u16> ord3729({1, 0});
      slog::Relation* readrel3730 = db->getRelation("Lf");
      Lfindex3534 = readrel3730->getIndex(ord3729, false);
      std::vector<u16> ord3731({2, 1, 0});
      slog::Relation* readrel3732 = db->getRelation("Nd");
      Ndindex3535 = readrel3732->getIndex(ord3731, false);
      std::vector<u16> ord3733({1, 0});
      slog::Relation* readrel3734 = db->getRelation("Lf");
      Lfindex3536 = readrel3734->getIndex(ord3733, false);
      std::vector<u16> ord3735({2, 1, 0});
      slog::Relation* readrel3736 = db->getRelation("Nd");
      Ndindex3537 = readrel3736->getIndex(ord3735, false);
      std::vector<u16> ord3737({1, 0});
      slog::Relation* readrel3738 = db->getRelation("Lf");
      Lfindex3538 = readrel3738->getIndex(ord3737, false);
      std::vector<u16> ord3739({2, 1, 0});
      slog::Relation* readrel3740 = db->getRelation("Nd");
      Ndindex3539 = readrel3740->getIndex(ord3739, false);
      std::vector<u16> ord3741({1, 0});
      slog::Relation* readrel3742 = db->getRelation("Lf");
      Lfindex3540 = readrel3742->getIndex(ord3741, false);
      std::vector<u16> ord3743({2, 1, 0});
      slog::Relation* readrel3744 = db->getRelation("Nd");
      Ndindex3541 = readrel3744->getIndex(ord3743, false);
      std::vector<u16> ord3745({1, 0});
      slog::Relation* readrel3746 = db->getRelation("Lf");
      Lfindex3542 = readrel3746->getIndex(ord3745, false);
      std::vector<u16> ord3747({2, 1, 0});
      slog::Relation* readrel3748 = db->getRelation("Nd");
      Ndindex3543 = readrel3748->getIndex(ord3747, false);
  
    }
    ReadTask3544(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
  
      slog::join_probe<2,1>(Lfindex3450, std::array<u64,2>{v_c31, 0}, [&](const std::array<u64,2>& m3749) {
        u64 v_c35 = m3749[1];
        if (!slog::exists_probe<3,1>(Ndindex3451, std::array<u64,3>{v_c35, 0, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3452, std::array<u64,2>{v_c29, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3453, std::array<u64,2>{v_c28, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3454, std::array<u64,2>{v_c27, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3455, std::array<u64,2>{v_c26, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3456, std::array<u64,2>{v_c25, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3457, std::array<u64,2>{v_c24, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3458, std::array<u64,2>{v_c23, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3459, std::array<u64,2>{v_c22, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3460, std::array<u64,2>{v_c21, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3461, std::array<u64,2>{v_c20, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3462, std::array<u64,2>{v_c19, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3463, std::array<u64,2>{v_c18, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3464, std::array<u64,2>{v_c17, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3465, std::array<u64,2>{v_c16, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3466, std::array<u64,2>{v_c15, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3467, std::array<u64,2>{v_c14, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3468, std::array<u64,2>{v_c13, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3469, std::array<u64,2>{v_c12, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3470, std::array<u64,2>{v_c11, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3471, std::array<u64,2>{v_c10, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3472, std::array<u64,2>{v_c9, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3473, std::array<u64,2>{v_c8, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3474, std::array<u64,2>{v_c7, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3475, std::array<u64,2>{v_c6, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3476, std::array<u64,2>{v_c5, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3477, std::array<u64,2>{v_c4, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3478, std::array<u64,2>{v_c3, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3479, std::array<u64,2>{v_c2, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3480, std::array<u64,2>{v_c1, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3481, std::array<u64,2>{v_c0, 0})) return;
        slog::join_probe<2,1>(Lfindex3482, std::array<u64,2>{v_c30, 0}, [&](const std::array<u64,2>& m3750) {
          u64 v_c36 = m3750[1];
          slog::join_probe<3,2>(Ndindex3483, std::array<u64,3>{v_c35, v_c36, 0}, [&](const std::array<u64,3>& m3751) {
            u64 v_c37 = m3751[2];
            slog::join_probe<2,1>(Lfindex3484, std::array<u64,2>{v_c29, 0}, [&](const std::array<u64,2>& m3752) {
              u64 v_c38 = m3752[1];
              if (!slog::exists_probe<3,1>(Ndindex3485, std::array<u64,3>{v_c38, 0, 0})) return;
              slog::join_probe<2,1>(Lfindex3486, std::array<u64,2>{v_c28, 0}, [&](const std::array<u64,2>& m3753) {
                u64 v_c39 = m3753[1];
                slog::join_probe<3,2>(Ndindex3487, std::array<u64,3>{v_c38, v_c39, 0}, [&](const std::array<u64,3>& m3754) {
                  u64 v_c40 = m3754[2];
                  slog::join_probe<2,1>(Lfindex3488, std::array<u64,2>{v_c27, 0}, [&](const std::array<u64,2>& m3755) {
                    u64 v_c43 = m3755[1];
                    if (!slog::exists_probe<3,1>(Ndindex3489, std::array<u64,3>{v_c43, 0, 0})) return;
                    slog::join_probe<2,1>(Lfindex3490, std::array<u64,2>{v_c26, 0}, [&](const std::array<u64,2>& m3756) {
                      u64 v_c44 = m3756[1];
                      slog::join_probe<3,2>(Ndindex3491, std::array<u64,3>{v_c43, v_c44, 0}, [&](const std::array<u64,3>& m3757) {
                        u64 v_c45 = m3757[2];
                        slog::join_probe<2,1>(Lfindex3492, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m3758) {
                          u64 v_c47 = m3758[1];
                          if (!slog::exists_probe<3,1>(Ndindex3493, std::array<u64,3>{v_c47, 0, 0})) return;
                          slog::join_probe<2,1>(Lfindex3494, std::array<u64,2>{v_c24, 0}, [&](const std::array<u64,2>& m3759) {
                            u64 v_c48 = m3759[1];
                            slog::join_probe<3,2>(Ndindex3495, std::array<u64,3>{v_c47, v_c48, 0}, [&](const std::array<u64,3>& m3760) {
                              u64 v_c46 = m3760[2];
                              slog::join_probe<2,1>(Lfindex3496, std::array<u64,2>{v_c23, 0}, [&](const std::array<u64,2>& m3761) {
                                u64 v_c49 = m3761[1];
                                if (!slog::exists_probe<3,1>(Ndindex3497, std::array<u64,3>{v_c49, 0, 0})) return;
                                slog::join_probe<2,1>(Lfindex3498, std::array<u64,2>{v_c22, 0}, [&](const std::array<u64,2>& m3762) {
                                  u64 v_c50 = m3762[1];
                                  slog::join_probe<3,2>(Ndindex3499, std::array<u64,3>{v_c49, v_c50, 0}, [&](const std::array<u64,3>& m3763) {
                                    u64 v_c51 = m3763[2];
                                    slog::join_probe<2,1>(Lfindex3500, std::array<u64,2>{v_c21, 0}, [&](const std::array<u64,2>& m3764) {
                                      u64 v_c52 = m3764[1];
                                      if (!slog::exists_probe<3,1>(Ndindex3501, std::array<u64,3>{v_c52, 0, 0})) return;
                                      slog::join_probe<2,1>(Lfindex3502, std::array<u64,2>{v_c20, 0}, [&](const std::array<u64,2>& m3765) {
                                        u64 v_c53 = m3765[1];
                                        slog::join_probe<3,2>(Ndindex3503, std::array<u64,3>{v_c52, v_c53, 0}, [&](const std::array<u64,3>& m3766) {
                                          u64 v_c54 = m3766[2];
                                          slog::join_probe<2,1>(Lfindex3504, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m3767) {
                                            u64 v_c57 = m3767[1];
                                            if (!slog::exists_probe<3,1>(Ndindex3505, std::array<u64,3>{v_c57, 0, 0})) return;
                                            slog::join_probe<2,1>(Lfindex3506, std::array<u64,2>{v_c18, 0}, [&](const std::array<u64,2>& m3768) {
                                              u64 v_c58 = m3768[1];
                                              slog::join_probe<3,2>(Ndindex3507, std::array<u64,3>{v_c57, v_c58, 0}, [&](const std::array<u64,3>& m3769) {
                                                u64 v_c59 = m3769[2];
                                                slog::join_probe<2,1>(Lfindex3508, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m3770) {
                                                  u64 v_c61 = m3770[1];
                                                  if (!slog::exists_probe<3,1>(Ndindex3509, std::array<u64,3>{v_c61, 0, 0})) return;
                                                  slog::join_probe<2,1>(Lfindex3510, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m3771) {
                                                    u64 v_c62 = m3771[1];
                                                    slog::join_probe<3,2>(Ndindex3511, std::array<u64,3>{v_c61, v_c62, 0}, [&](const std::array<u64,3>& m3772) {
                                                      u64 v_c60 = m3772[2];
                                                      slog::join_probe<2,1>(Lfindex3512, std::array<u64,2>{v_c15, 0}, [&](const std::array<u64,2>& m3773) {
                                                        u64 v_c63 = m3773[1];
                                                        if (!slog::exists_probe<3,1>(Ndindex3513, std::array<u64,3>{v_c63, 0, 0})) return;
                                                        slog::join_probe<2,1>(Lfindex3514, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m3774) {
                                                          u64 v_c64 = m3774[1];
                                                          slog::join_probe<3,2>(Ndindex3515, std::array<u64,3>{v_c63, v_c64, 0}, [&](const std::array<u64,3>& m3775) {
                                                            u64 v_c65 = m3775[2];
                                                            slog::join_probe<2,1>(Lfindex3516, std::array<u64,2>{v_c13, 0}, [&](const std::array<u64,2>& m3776) {
                                                              u64 v_c66 = m3776[1];
                                                              if (!slog::exists_probe<3,1>(Ndindex3517, std::array<u64,3>{v_c66, 0, 0})) return;
                                                              slog::join_probe<2,1>(Lfindex3518, std::array<u64,2>{v_c12, 0}, [&](const std::array<u64,2>& m3777) {
                                                                u64 v_c67 = m3777[1];
                                                                slog::join_probe<3,2>(Ndindex3519, std::array<u64,3>{v_c66, v_c67, 0}, [&](const std::array<u64,3>& m3778) {
                                                                  u64 v_c68 = m3778[2];
                                                                  slog::join_probe<2,1>(Lfindex3520, std::array<u64,2>{v_c11, 0}, [&](const std::array<u64,2>& m3779) {
                                                                    u64 v_c70 = m3779[1];
                                                                    if (!slog::exists_probe<3,1>(Ndindex3521, std::array<u64,3>{v_c70, 0, 0})) return;
                                                                    slog::join_probe<2,1>(Lfindex3522, std::array<u64,2>{v_c10, 0}, [&](const std::array<u64,2>& m3780) {
                                                                      u64 v_c71 = m3780[1];
                                                                      slog::join_probe<3,2>(Ndindex3523, std::array<u64,3>{v_c70, v_c71, 0}, [&](const std::array<u64,3>& m3781) {
                                                                        u64 v_c72 = m3781[2];
                                                                        slog::join_probe<2,1>(Lfindex3524, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m3782) {
                                                                          u64 v_c73 = m3782[1];
                                                                          if (!slog::exists_probe<3,1>(Ndindex3525, std::array<u64,3>{v_c73, 0, 0})) return;
                                                                          slog::join_probe<2,1>(Lfindex3526, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m3783) {
                                                                            u64 v_c74 = m3783[1];
                                                                            slog::join_probe<3,2>(Ndindex3527, std::array<u64,3>{v_c73, v_c74, 0}, [&](const std::array<u64,3>& m3784) {
                                                                              u64 v_c75 = m3784[2];
                                                                              slog::join_probe<2,1>(Lfindex3528, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m3785) {
                                                                                u64 v_c78 = m3785[1];
                                                                                if (!slog::exists_probe<3,1>(Ndindex3529, std::array<u64,3>{v_c78, 0, 0})) return;
                                                                                slog::join_probe<2,1>(Lfindex3530, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m3786) {
                                                                                  u64 v_c79 = m3786[1];
                                                                                  slog::join_probe<3,2>(Ndindex3531, std::array<u64,3>{v_c78, v_c79, 0}, [&](const std::array<u64,3>& m3787) {
                                                                                    u64 v_c80 = m3787[2];
                                                                                    slog::join_probe<2,1>(Lfindex3532, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m3788) {
                                                                                      u64 v_c81 = m3788[1];
                                                                                      if (!slog::exists_probe<3,1>(Ndindex3533, std::array<u64,3>{v_c81, 0, 0})) return;
                                                                                      slog::join_probe<2,1>(Lfindex3534, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m3789) {
                                                                                        u64 v_c82 = m3789[1];
                                                                                        slog::join_probe<3,2>(Ndindex3535, std::array<u64,3>{v_c81, v_c82, 0}, [&](const std::array<u64,3>& m3790) {
                                                                                          u64 v_c83 = m3790[2];
                                                                                          slog::join_probe<2,1>(Lfindex3536, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m3791) {
                                                                                            u64 v_c85 = m3791[1];
                                                                                            if (!slog::exists_probe<3,1>(Ndindex3537, std::array<u64,3>{v_c85, 0, 0})) return;
                                                                                            slog::join_probe<2,1>(Lfindex3538, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m3792) {
                                                                                              u64 v_c86 = m3792[1];
                                                                                              slog::join_probe<3,2>(Ndindex3539, std::array<u64,3>{v_c85, v_c86, 0}, [&](const std::array<u64,3>& m3793) {
                                                                                                u64 v_c87 = m3793[2];
                                                                                                slog::join_probe<2,1>(Lfindex3540, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m3794) {
                                                                                                  u64 v_c88 = m3794[1];
                                                                                                  if (!slog::exists_probe<3,1>(Ndindex3541, std::array<u64,3>{v_c88, 0, 0})) return;
                                                                                                  slog::join_probe<2,1>(Lfindex3542, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m3795) {
                                                                                                    u64 v_c89 = m3795[1];
                                                                                                    slog::join_probe<3,2>(Ndindex3543, std::array<u64,3>{v_c88, v_c89, 0}, [&](const std::array<u64,3>& m3796) {
                                                                                                      u64 v_c90 = m3796[2];
                                                                                                      ++_fires;
                                                                                                      slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c87, v_c90}, std::array<u16,3>{2, 1, 0});
                                                                                                      slog::emit_struct_checked<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c80, v_c83}, std::array<u16,3>{2, 1, 0});
                                                                                                      slog::emit_struct_checked<3>(head_rel[2], head_index[2], newbatch[2], std::array<u64,2>{v_c72, v_c75}, std::array<u16,3>{2, 1, 0});
                                                                                                      slog::emit_struct_checked<3>(head_rel[3], head_index[3], newbatch[3], std::array<u64,2>{v_c65, v_c68}, std::array<u16,3>{2, 1, 0});
                                                                                                      slog::emit_struct_checked<3>(head_rel[4], head_index[4], newbatch[4], std::array<u64,2>{v_c59, v_c60}, std::array<u16,3>{2, 1, 0});
                                                                                                      slog::emit_struct_checked<3>(head_rel[5], head_index[5], newbatch[5], std::array<u64,2>{v_c51, v_c54}, std::array<u16,3>{2, 1, 0});
                                                                                                      slog::emit_struct_checked<3>(head_rel[6], head_index[6], newbatch[6], std::array<u64,2>{v_c45, v_c46}, std::array<u16,3>{2, 1, 0});
                                                                                                      slog::emit_struct_checked<3>(head_rel[7], head_index[7], newbatch[7], std::array<u64,2>{v_c37, v_c40}, std::array<u16,3>{2, 1, 0});
                                                                                                    });
                                                                                                  });
                                                                                                });
                                                                                              });
                                                                                            });
                                                                                          });
                                                                                        });
                                                                                      });
                                                                                    });
                                                                                  });
                                                                                });
                                                                              });
                                                                            });
                                                                          });
                                                                        });
                                                                      });
                                                                    });
                                                                  });
                                                                });
                                                              });
                                                            });
                                                          });
                                                        });
                                                      });
                                                    });
                                                  });
                                                });
                                              });
                                            });
                                          });
                                        });
                                      });
                                    });
                                  });
                                });
                              });
                            });
                          });
                        });
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
        head_rel[4]->sendBatch(newbatch[4]);
        head_rel[5]->sendBatch(newbatch[5]);
        head_rel[6]->sendBatch(newbatch[6]);
        head_rel[7]->sendBatch(newbatch[7]);
  
      if (_fires) db->bumpFires("deep_fact.slog:7", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask3544(db,b));
  // (crule (pre (let __tconst48SJ108 const6b86b273ff34fce19d6b804e) (let __tconst5Uhl106 constd4735e3a265e16eee03f5971) (let __tconst9YpM103 const4e07408562bedb8b60ce05c1) (let __tconst3iHp101 const4b227777d4dd1fc61c6f884f) (let __tconst0Emh97 constef2d127de37b942baad06145) (let __tconst29xA95 conste7f6c011776e8db7cd330b54) (let __tconst9mjQ92 const7902699be42c8a8e46fbbb45) (let __tconst9Yxv90 const2c624232cdd221771294dfbb) (let __tconst7wWY85 const19581e27de7ced00ff1ce50b) (let __tconst01Wl83 const4a44dc15364204a80fe80e90) (let __tconst42lR80 const4fc82b26aecb47d2868c4efb) (let __tconst3KyY78 const6b51d431df5d7f141cbececc) (let __tconst6a9N74 const3fdba35f04dc8c462986c992) (let __tconst74Qx72 const8527a891e224136950ff32ca) (let __tconst2hOw69 conste629fa6598d732768f7c726b) (let __tconst7kHD67 constb17ef6d19c7a5b1ee83b907c) (let __tconst5zmq61 const4523540f1504cd17100c4835) (let __tconst31qC59 const4ec9599fc203d176a301536c) (let __tconst4Vop56 const9400f1b21cb527d7fa3d3eab) (let __tconst51zc54 constf5ca38f748a1d6eaf726b8a4) (let __tconst6Qm150 const6f4b6612125fb3a0daecd279) (let __tconst6bEj48 const785f3ec7eb32f30b90cd0fcf) (let __tconst7AKN45 const535fa30d7e25dd8a49f15367) (let __tconst9j2a43 constc2356069e9d1e79ca9243781) (let __tconst1Mto38 constb7a56873cd771f2c446d369b) (let __tconst8u8i36 const5f9c4ab08cac7457e9111a30) (let __tconst2Isx33 const670671cd97404156226e5079) (let __tconst8J6R31 const59e19706d51d39f66711c265) (let __tconst88cs27 const35135aaa6cc23891b40cb3f3) (let __tconst0Uuf25 const624b60c58c9d8bfb6ff1886c) (let __tconst6sf622 consteb1e33e8a81b697b75855af6) (let __tconst5Run20 conste29c9c180c6279b0b02abd6a)) (scan Nd __t17Jm42 __t2KtK41 __t6JrG30) (body (exists Lf (1 0) 1 __tconst6sf622) (exists Lf (1 0) 1 __tconst0Uuf25) (exists Lf (1 0) 1 __tconst88cs27) (exists Lf (1 0) 1 __tconst8J6R31) (exists Lf (1 0) 1 __tconst2Isx33) (exists Lf (1 0) 1 __tconst8u8i36) (exists Lf (1 0) 1 __tconst1Mto38) (exists Lf (1 0) 1 __tconst9j2a43) (exists Lf (1 0) 1 __tconst7AKN45) (exists Lf (1 0) 1 __tconst6bEj48) (exists Lf (1 0) 1 __tconst6Qm150) (exists Lf (1 0) 1 __tconst51zc54) (exists Lf (1 0) 1 __tconst4Vop56) (exists Lf (1 0) 1 __tconst31qC59) (exists Lf (1 0) 1 __tconst5zmq61) (exists Lf (1 0) 1 __tconst7kHD67) (exists Lf (1 0) 1 __tconst2hOw69) (exists Lf (1 0) 1 __tconst74Qx72) (exists Lf (1 0) 1 __tconst6a9N74) (exists Lf (1 0) 1 __tconst3KyY78) (exists Lf (1 0) 1 __tconst42lR80) (exists Lf (1 0) 1 __tconst01Wl83) (exists Lf (1 0) 1 __tconst7wWY85) (exists Lf (1 0) 1 __tconst9Yxv90) (exists Lf (1 0) 1 __tconst9mjQ92) (exists Lf (1 0) 1 __tconst29xA95) (exists Lf (1 0) 1 __tconst0Emh97) (exists Lf (1 0) 1 __tconst3iHp101) (exists Lf (1 0) 1 __tconst9YpM103) (exists Lf (1 0) 1 __tconst5Uhl106) (exists Lf (1 0) 1 __tconst48SJ108) (join Lf (1 0) 1 __tconst5Run20 __t8mDO21) (exists Nd (2 1 0) 1 __t8mDO21) (join Lf (1 0) 1 __tconst6sf622 __t1M8o23) (join Nd (2 1 0) 2 __t8mDO21 __t1M8o23 __t7LF824) (join Nd (0 2 1) 2 __t6JrG30 __t7LF824 __t0kIY29) (join Lf (1 0) 1 __tconst0Uuf25 __t1NQv26) (join Nd (0 2 1) 2 __t0kIY29 __t1NQv26 __t7d0c28) (join Lf (0 1) 2 __t7d0c28 __tconst88cs27) (join Lf (1 0) 1 __tconst8J6R31 __t9vh832) (exists Nd (2 1 0) 1 __t9vh832) (join Lf (1 0) 1 __tconst2Isx33 __t5flt34) (join Nd (2 1 0) 2 __t9vh832 __t5flt34 __t3jHg35) (join Nd (0 2 1) 2 __t2KtK41 __t3jHg35 __t8qqV40) (join Lf (1 0) 1 __tconst8u8i36 __t27Zr37) (join Nd (0 2 1) 2 __t8qqV40 __t27Zr37 __t3UFu39) (join Lf (0 1) 2 __t3UFu39 __tconst1Mto38) (join Lf (1 0) 1 __tconst9j2a43 __t6IKq44) (exists Nd (2 1 0) 1 __t6IKq44) (join Lf (1 0) 1 __tconst7AKN45 __t6LIW46) (join Nd (2 1 0) 2 __t6IKq44 __t6LIW46 __t7C7d47) (exists Nd (2 1 0) 1 __t7C7d47) (join Lf (1 0) 1 __tconst6bEj48 __t9k7a49) (exists Nd (2 1 0) 1 __t9k7a49) (join Lf (1 0) 1 __tconst6Qm150 __t4MdC51) (join Nd (2 1 0) 2 __t9k7a49 __t4MdC51 __t8A9i52) (join Nd (2 1 0) 2 __t7C7d47 __t8A9i52 __t7DSY53) (exists Nd (2 1 0) 1 __t7DSY53) (join Lf (1 0) 1 __tconst51zc54 __t3Yon55) (exists Nd (2 1 0) 1 __t3Yon55) (join Lf (1 0) 1 __tconst4Vop56 __t5ik157) (join Nd (2 1 0) 2 __t3Yon55 __t5ik157 __t4hi358) (exists Nd (2 1 0) 1 __t4hi358) (join Lf (1 0) 1 __tconst31qC59 __t1nkJ60) (exists Nd (2 1 0) 1 __t1nkJ60) (join Lf (1 0) 1 __tconst5zmq61 __t4E3D62) (join Nd (2 1 0) 2 __t1nkJ60 __t4E3D62 __t8TXU63) (join Nd (2 1 0) 2 __t4hi358 __t8TXU63 __t6bZq64) (join Nd (2 1 0) 2 __t7DSY53 __t6bZq64 __t4uRs65) (join Lf (1 0) 1 __tconst7kHD67 __t4J2N68) (exists Nd (2 1 0) 1 __t4J2N68) (join Lf (1 0) 1 __tconst2hOw69 __t4izo70) (join Nd (2 1 0) 2 __t4J2N68 __t4izo70 __t14Ff71) (exists Nd (2 1 0) 1 __t14Ff71) (join Lf (1 0) 1 __tconst74Qx72 __t319l73) (exists Nd (2 1 0) 1 __t319l73) (join Lf (1 0) 1 __tconst6a9N74 __t0amQ75) (join Nd (2 1 0) 2 __t319l73 __t0amQ75 __t4MUf76) (join Nd (2 1 0) 2 __t14Ff71 __t4MUf76 __t13Wj77) (exists Nd (2 1 0) 1 __t13Wj77) (join Lf (1 0) 1 __tconst3KyY78 __t13gt79) (exists Nd (2 1 0) 1 __t13gt79) (join Lf (1 0) 1 __tconst42lR80 __t3ESz81) (join Nd (2 1 0) 2 __t13gt79 __t3ESz81 __t3WL082) (exists Nd (2 1 0) 1 __t3WL082) (join Lf (1 0) 1 __tconst01Wl83 __t4Da384) (exists Nd (2 1 0) 1 __t4Da384) (join Lf (1 0) 1 __tconst7wWY85 __t91gs86) (join Nd (2 1 0) 2 __t4Da384 __t91gs86 __t02Bu87) (join Nd (2 1 0) 2 __t3WL082 __t02Bu87 __t60KJ88) (join Nd (2 1 0) 2 __t13Wj77 __t60KJ88 __t4p4K89) (join Lf (1 0) 1 __tconst9Yxv90 __t7UaH91) (exists Nd (2 1 0) 1 __t7UaH91) (join Lf (1 0) 1 __tconst9mjQ92 __t6IMg93) (join Nd (2 1 0) 2 __t7UaH91 __t6IMg93 __t2T3i94) (exists Nd (2 1 0) 1 __t2T3i94) (join Lf (1 0) 1 __tconst29xA95 __t2oHE96) (exists Nd (2 1 0) 1 __t2oHE96) (join Lf (1 0) 1 __tconst0Emh97 __t7bue98) (join Nd (2 1 0) 2 __t2oHE96 __t7bue98 __t0HkS99) (join Nd (2 1 0) 2 __t2T3i94 __t0HkS99 __t7PLp100) (exists Nd (2 1 0) 1 __t7PLp100) (join Lf (1 0) 1 __tconst3iHp101 __t5yzC102) (exists Nd (2 1 0) 1 __t5yzC102) (join Lf (1 0) 1 __tconst9YpM103 __t7c21104) (join Nd (2 1 0) 2 __t5yzC102 __t7c21104 __t4bRV105) (exists Nd (2 1 0) 1 __t4bRV105) (join Lf (1 0) 1 __tconst5Uhl106 __t1IJA107) (exists Nd (2 1 0) 1 __t1IJA107) (join Lf (1 0) 1 __tconst48SJ108 __t0y5t109) (join Nd (2 1 0) 2 __t1IJA107 __t0y5t109 __t76VS110) (join Nd (2 1 0) 2 __t4bRV105 __t76VS110 __t3a3T111) (join Nd (2 1 0) 2 __t7PLp100 __t3a3T111 __t9dGZ112)) (head (mkstruct Nd (2 1 0) __t09Ym113 __t4p4K89 __t9dGZ112) (mkstruct Nd (2 1 0) __t4LVF66 __t17Jm42 __t4uRs65)) deep_fact.slog:7 #f)
  class ReadTask3910 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** Lfindex3797;  slog::Index** Lfindex3798;  slog::Index** Lfindex3799;  slog::Index** Lfindex3800;  slog::Index** Lfindex3801;  slog::Index** Lfindex3802;  slog::Index** Lfindex3803;  slog::Index** Lfindex3804;  slog::Index** Lfindex3805;  slog::Index** Lfindex3806;  slog::Index** Lfindex3807;  slog::Index** Lfindex3808;  slog::Index** Lfindex3809;  slog::Index** Lfindex3810;  slog::Index** Lfindex3811;  slog::Index** Lfindex3812;  slog::Index** Lfindex3813;  slog::Index** Lfindex3814;  slog::Index** Lfindex3815;  slog::Index** Lfindex3816;  slog::Index** Lfindex3817;  slog::Index** Lfindex3818;  slog::Index** Lfindex3819;  slog::Index** Lfindex3820;  slog::Index** Lfindex3821;  slog::Index** Lfindex3822;  slog::Index** Lfindex3823;  slog::Index** Lfindex3824;  slog::Index** Lfindex3825;  slog::Index** Lfindex3826;  slog::Index** Lfindex3827;  slog::Index** Lfindex3828;  slog::Index** Ndindex3829;  slog::Index** Lfindex3830;  slog::Index** Ndindex3831;  slog::Index** Ndindex3832;  slog::Index** Lfindex3833;  slog::Index** Ndindex3834;  slog::Index** Lfindex3835;  slog::Index** Lfindex3836;  slog::Index** Ndindex3837;  slog::Index** Lfindex3838;  slog::Index** Ndindex3839;  slog::Index** Ndindex3840;  slog::Index** Lfindex3841;  slog::Index** Ndindex3842;  slog::Index** Lfindex3843;  slog::Index** Lfindex3844;  slog::Index** Ndindex3845;  slog::Index** Lfindex3846;  slog::Index** Ndindex3847;  slog::Index** Ndindex3848;  slog::Index** Lfindex3849;  slog::Index** Ndindex3850;  slog::Index** Lfindex3851;  slog::Index** Ndindex3852;  slog::Index** Ndindex3853;  slog::Index** Ndindex3854;  slog::Index** Lfindex3855;  slog::Index** Ndindex3856;  slog::Index** Lfindex3857;  slog::Index** Ndindex3858;  slog::Index** Ndindex3859;  slog::Index** Lfindex3860;  slog::Index** Ndindex3861;  slog::Index** Lfindex3862;  slog::Index** Ndindex3863;  slog::Index** Ndindex3864;  slog::Index** Ndindex3865;  slog::Index** Lfindex3866;  slog::Index** Ndindex3867;  slog::Index** Lfindex3868;  slog::Index** Ndindex3869;  slog::Index** Ndindex3870;  slog::Index** Lfindex3871;  slog::Index** Ndindex3872;  slog::Index** Lfindex3873;  slog::Index** Ndindex3874;  slog::Index** Ndindex3875;  slog::Index** Ndindex3876;  slog::Index** Lfindex3877;  slog::Index** Ndindex3878;  slog::Index** Lfindex3879;  slog::Index** Ndindex3880;  slog::Index** Ndindex3881;  slog::Index** Lfindex3882;  slog::Index** Ndindex3883;  slog::Index** Lfindex3884;  slog::Index** Ndindex3885;  slog::Index** Ndindex3886;  slog::Index** Ndindex3887;  slog::Index** Lfindex3888;  slog::Index** Ndindex3889;  slog::Index** Lfindex3890;  slog::Index** Ndindex3891;  slog::Index** Ndindex3892;  slog::Index** Lfindex3893;  slog::Index** Ndindex3894;  slog::Index** Lfindex3895;  slog::Index** Ndindex3896;  slog::Index** Ndindex3897;  slog::Index** Ndindex3898;  slog::Index** Lfindex3899;  slog::Index** Ndindex3900;  slog::Index** Lfindex3901;  slog::Index** Ndindex3902;  slog::Index** Ndindex3903;  slog::Index** Lfindex3904;  slog::Index** Ndindex3905;  slog::Index** Lfindex3906;  slog::Index** Ndindex3907;  slog::Index** Ndindex3908;  slog::Index** Ndindex3909;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("Nd");
      head_rel[1] = db->getRelation("Nd");
      outer_rel = db->getRelation("Nd");
      std::vector<u16> ord3911({1, 0});
      slog::Relation* readrel3912 = db->getRelation("Lf");
      Lfindex3797 = readrel3912->getIndex(ord3911, false);
      std::vector<u16> ord3913({1, 0});
      slog::Relation* readrel3914 = db->getRelation("Lf");
      Lfindex3798 = readrel3914->getIndex(ord3913, false);
      std::vector<u16> ord3915({1, 0});
      slog::Relation* readrel3916 = db->getRelation("Lf");
      Lfindex3799 = readrel3916->getIndex(ord3915, false);
      std::vector<u16> ord3917({1, 0});
      slog::Relation* readrel3918 = db->getRelation("Lf");
      Lfindex3800 = readrel3918->getIndex(ord3917, false);
      std::vector<u16> ord3919({1, 0});
      slog::Relation* readrel3920 = db->getRelation("Lf");
      Lfindex3801 = readrel3920->getIndex(ord3919, false);
      std::vector<u16> ord3921({1, 0});
      slog::Relation* readrel3922 = db->getRelation("Lf");
      Lfindex3802 = readrel3922->getIndex(ord3921, false);
      std::vector<u16> ord3923({1, 0});
      slog::Relation* readrel3924 = db->getRelation("Lf");
      Lfindex3803 = readrel3924->getIndex(ord3923, false);
      std::vector<u16> ord3925({1, 0});
      slog::Relation* readrel3926 = db->getRelation("Lf");
      Lfindex3804 = readrel3926->getIndex(ord3925, false);
      std::vector<u16> ord3927({1, 0});
      slog::Relation* readrel3928 = db->getRelation("Lf");
      Lfindex3805 = readrel3928->getIndex(ord3927, false);
      std::vector<u16> ord3929({1, 0});
      slog::Relation* readrel3930 = db->getRelation("Lf");
      Lfindex3806 = readrel3930->getIndex(ord3929, false);
      std::vector<u16> ord3931({1, 0});
      slog::Relation* readrel3932 = db->getRelation("Lf");
      Lfindex3807 = readrel3932->getIndex(ord3931, false);
      std::vector<u16> ord3933({1, 0});
      slog::Relation* readrel3934 = db->getRelation("Lf");
      Lfindex3808 = readrel3934->getIndex(ord3933, false);
      std::vector<u16> ord3935({1, 0});
      slog::Relation* readrel3936 = db->getRelation("Lf");
      Lfindex3809 = readrel3936->getIndex(ord3935, false);
      std::vector<u16> ord3937({1, 0});
      slog::Relation* readrel3938 = db->getRelation("Lf");
      Lfindex3810 = readrel3938->getIndex(ord3937, false);
      std::vector<u16> ord3939({1, 0});
      slog::Relation* readrel3940 = db->getRelation("Lf");
      Lfindex3811 = readrel3940->getIndex(ord3939, false);
      std::vector<u16> ord3941({1, 0});
      slog::Relation* readrel3942 = db->getRelation("Lf");
      Lfindex3812 = readrel3942->getIndex(ord3941, false);
      std::vector<u16> ord3943({1, 0});
      slog::Relation* readrel3944 = db->getRelation("Lf");
      Lfindex3813 = readrel3944->getIndex(ord3943, false);
      std::vector<u16> ord3945({1, 0});
      slog::Relation* readrel3946 = db->getRelation("Lf");
      Lfindex3814 = readrel3946->getIndex(ord3945, false);
      std::vector<u16> ord3947({1, 0});
      slog::Relation* readrel3948 = db->getRelation("Lf");
      Lfindex3815 = readrel3948->getIndex(ord3947, false);
      std::vector<u16> ord3949({1, 0});
      slog::Relation* readrel3950 = db->getRelation("Lf");
      Lfindex3816 = readrel3950->getIndex(ord3949, false);
      std::vector<u16> ord3951({1, 0});
      slog::Relation* readrel3952 = db->getRelation("Lf");
      Lfindex3817 = readrel3952->getIndex(ord3951, false);
      std::vector<u16> ord3953({1, 0});
      slog::Relation* readrel3954 = db->getRelation("Lf");
      Lfindex3818 = readrel3954->getIndex(ord3953, false);
      std::vector<u16> ord3955({1, 0});
      slog::Relation* readrel3956 = db->getRelation("Lf");
      Lfindex3819 = readrel3956->getIndex(ord3955, false);
      std::vector<u16> ord3957({1, 0});
      slog::Relation* readrel3958 = db->getRelation("Lf");
      Lfindex3820 = readrel3958->getIndex(ord3957, false);
      std::vector<u16> ord3959({1, 0});
      slog::Relation* readrel3960 = db->getRelation("Lf");
      Lfindex3821 = readrel3960->getIndex(ord3959, false);
      std::vector<u16> ord3961({1, 0});
      slog::Relation* readrel3962 = db->getRelation("Lf");
      Lfindex3822 = readrel3962->getIndex(ord3961, false);
      std::vector<u16> ord3963({1, 0});
      slog::Relation* readrel3964 = db->getRelation("Lf");
      Lfindex3823 = readrel3964->getIndex(ord3963, false);
      std::vector<u16> ord3965({1, 0});
      slog::Relation* readrel3966 = db->getRelation("Lf");
      Lfindex3824 = readrel3966->getIndex(ord3965, false);
      std::vector<u16> ord3967({1, 0});
      slog::Relation* readrel3968 = db->getRelation("Lf");
      Lfindex3825 = readrel3968->getIndex(ord3967, false);
      std::vector<u16> ord3969({1, 0});
      slog::Relation* readrel3970 = db->getRelation("Lf");
      Lfindex3826 = readrel3970->getIndex(ord3969, false);
      std::vector<u16> ord3971({1, 0});
      slog::Relation* readrel3972 = db->getRelation("Lf");
      Lfindex3827 = readrel3972->getIndex(ord3971, false);
      std::vector<u16> ord3973({1, 0});
      slog::Relation* readrel3974 = db->getRelation("Lf");
      Lfindex3828 = readrel3974->getIndex(ord3973, false);
      std::vector<u16> ord3975({2, 1, 0});
      slog::Relation* readrel3976 = db->getRelation("Nd");
      Ndindex3829 = readrel3976->getIndex(ord3975, false);
      std::vector<u16> ord3977({1, 0});
      slog::Relation* readrel3978 = db->getRelation("Lf");
      Lfindex3830 = readrel3978->getIndex(ord3977, false);
      std::vector<u16> ord3979({2, 1, 0});
      slog::Relation* readrel3980 = db->getRelation("Nd");
      Ndindex3831 = readrel3980->getIndex(ord3979, false);
      std::vector<u16> ord3981({0, 2, 1});
      slog::Relation* readrel3982 = db->getRelation("Nd");
      Ndindex3832 = readrel3982->getIndex(ord3981, false);
      std::vector<u16> ord3983({1, 0});
      slog::Relation* readrel3984 = db->getRelation("Lf");
      Lfindex3833 = readrel3984->getIndex(ord3983, false);
      std::vector<u16> ord3985({0, 2, 1});
      slog::Relation* readrel3986 = db->getRelation("Nd");
      Ndindex3834 = readrel3986->getIndex(ord3985, false);
      std::vector<u16> ord3987({0, 1});
      slog::Relation* readrel3988 = db->getRelation("Lf");
      Lfindex3835 = readrel3988->getIndex(ord3987, false);
      std::vector<u16> ord3989({1, 0});
      slog::Relation* readrel3990 = db->getRelation("Lf");
      Lfindex3836 = readrel3990->getIndex(ord3989, false);
      std::vector<u16> ord3991({2, 1, 0});
      slog::Relation* readrel3992 = db->getRelation("Nd");
      Ndindex3837 = readrel3992->getIndex(ord3991, false);
      std::vector<u16> ord3993({1, 0});
      slog::Relation* readrel3994 = db->getRelation("Lf");
      Lfindex3838 = readrel3994->getIndex(ord3993, false);
      std::vector<u16> ord3995({2, 1, 0});
      slog::Relation* readrel3996 = db->getRelation("Nd");
      Ndindex3839 = readrel3996->getIndex(ord3995, false);
      std::vector<u16> ord3997({0, 2, 1});
      slog::Relation* readrel3998 = db->getRelation("Nd");
      Ndindex3840 = readrel3998->getIndex(ord3997, false);
      std::vector<u16> ord3999({1, 0});
      slog::Relation* readrel4000 = db->getRelation("Lf");
      Lfindex3841 = readrel4000->getIndex(ord3999, false);
      std::vector<u16> ord4001({0, 2, 1});
      slog::Relation* readrel4002 = db->getRelation("Nd");
      Ndindex3842 = readrel4002->getIndex(ord4001, false);
      std::vector<u16> ord4003({0, 1});
      slog::Relation* readrel4004 = db->getRelation("Lf");
      Lfindex3843 = readrel4004->getIndex(ord4003, false);
      std::vector<u16> ord4005({1, 0});
      slog::Relation* readrel4006 = db->getRelation("Lf");
      Lfindex3844 = readrel4006->getIndex(ord4005, false);
      std::vector<u16> ord4007({2, 1, 0});
      slog::Relation* readrel4008 = db->getRelation("Nd");
      Ndindex3845 = readrel4008->getIndex(ord4007, false);
      std::vector<u16> ord4009({1, 0});
      slog::Relation* readrel4010 = db->getRelation("Lf");
      Lfindex3846 = readrel4010->getIndex(ord4009, false);
      std::vector<u16> ord4011({2, 1, 0});
      slog::Relation* readrel4012 = db->getRelation("Nd");
      Ndindex3847 = readrel4012->getIndex(ord4011, false);
      std::vector<u16> ord4013({2, 1, 0});
      slog::Relation* readrel4014 = db->getRelation("Nd");
      Ndindex3848 = readrel4014->getIndex(ord4013, false);
      std::vector<u16> ord4015({1, 0});
      slog::Relation* readrel4016 = db->getRelation("Lf");
      Lfindex3849 = readrel4016->getIndex(ord4015, false);
      std::vector<u16> ord4017({2, 1, 0});
      slog::Relation* readrel4018 = db->getRelation("Nd");
      Ndindex3850 = readrel4018->getIndex(ord4017, false);
      std::vector<u16> ord4019({1, 0});
      slog::Relation* readrel4020 = db->getRelation("Lf");
      Lfindex3851 = readrel4020->getIndex(ord4019, false);
      std::vector<u16> ord4021({2, 1, 0});
      slog::Relation* readrel4022 = db->getRelation("Nd");
      Ndindex3852 = readrel4022->getIndex(ord4021, false);
      std::vector<u16> ord4023({2, 1, 0});
      slog::Relation* readrel4024 = db->getRelation("Nd");
      Ndindex3853 = readrel4024->getIndex(ord4023, false);
      std::vector<u16> ord4025({2, 1, 0});
      slog::Relation* readrel4026 = db->getRelation("Nd");
      Ndindex3854 = readrel4026->getIndex(ord4025, false);
      std::vector<u16> ord4027({1, 0});
      slog::Relation* readrel4028 = db->getRelation("Lf");
      Lfindex3855 = readrel4028->getIndex(ord4027, false);
      std::vector<u16> ord4029({2, 1, 0});
      slog::Relation* readrel4030 = db->getRelation("Nd");
      Ndindex3856 = readrel4030->getIndex(ord4029, false);
      std::vector<u16> ord4031({1, 0});
      slog::Relation* readrel4032 = db->getRelation("Lf");
      Lfindex3857 = readrel4032->getIndex(ord4031, false);
      std::vector<u16> ord4033({2, 1, 0});
      slog::Relation* readrel4034 = db->getRelation("Nd");
      Ndindex3858 = readrel4034->getIndex(ord4033, false);
      std::vector<u16> ord4035({2, 1, 0});
      slog::Relation* readrel4036 = db->getRelation("Nd");
      Ndindex3859 = readrel4036->getIndex(ord4035, false);
      std::vector<u16> ord4037({1, 0});
      slog::Relation* readrel4038 = db->getRelation("Lf");
      Lfindex3860 = readrel4038->getIndex(ord4037, false);
      std::vector<u16> ord4039({2, 1, 0});
      slog::Relation* readrel4040 = db->getRelation("Nd");
      Ndindex3861 = readrel4040->getIndex(ord4039, false);
      std::vector<u16> ord4041({1, 0});
      slog::Relation* readrel4042 = db->getRelation("Lf");
      Lfindex3862 = readrel4042->getIndex(ord4041, false);
      std::vector<u16> ord4043({2, 1, 0});
      slog::Relation* readrel4044 = db->getRelation("Nd");
      Ndindex3863 = readrel4044->getIndex(ord4043, false);
      std::vector<u16> ord4045({2, 1, 0});
      slog::Relation* readrel4046 = db->getRelation("Nd");
      Ndindex3864 = readrel4046->getIndex(ord4045, false);
      std::vector<u16> ord4047({2, 1, 0});
      slog::Relation* readrel4048 = db->getRelation("Nd");
      Ndindex3865 = readrel4048->getIndex(ord4047, false);
      std::vector<u16> ord4049({1, 0});
      slog::Relation* readrel4050 = db->getRelation("Lf");
      Lfindex3866 = readrel4050->getIndex(ord4049, false);
      std::vector<u16> ord4051({2, 1, 0});
      slog::Relation* readrel4052 = db->getRelation("Nd");
      Ndindex3867 = readrel4052->getIndex(ord4051, false);
      std::vector<u16> ord4053({1, 0});
      slog::Relation* readrel4054 = db->getRelation("Lf");
      Lfindex3868 = readrel4054->getIndex(ord4053, false);
      std::vector<u16> ord4055({2, 1, 0});
      slog::Relation* readrel4056 = db->getRelation("Nd");
      Ndindex3869 = readrel4056->getIndex(ord4055, false);
      std::vector<u16> ord4057({2, 1, 0});
      slog::Relation* readrel4058 = db->getRelation("Nd");
      Ndindex3870 = readrel4058->getIndex(ord4057, false);
      std::vector<u16> ord4059({1, 0});
      slog::Relation* readrel4060 = db->getRelation("Lf");
      Lfindex3871 = readrel4060->getIndex(ord4059, false);
      std::vector<u16> ord4061({2, 1, 0});
      slog::Relation* readrel4062 = db->getRelation("Nd");
      Ndindex3872 = readrel4062->getIndex(ord4061, false);
      std::vector<u16> ord4063({1, 0});
      slog::Relation* readrel4064 = db->getRelation("Lf");
      Lfindex3873 = readrel4064->getIndex(ord4063, false);
      std::vector<u16> ord4065({2, 1, 0});
      slog::Relation* readrel4066 = db->getRelation("Nd");
      Ndindex3874 = readrel4066->getIndex(ord4065, false);
      std::vector<u16> ord4067({2, 1, 0});
      slog::Relation* readrel4068 = db->getRelation("Nd");
      Ndindex3875 = readrel4068->getIndex(ord4067, false);
      std::vector<u16> ord4069({2, 1, 0});
      slog::Relation* readrel4070 = db->getRelation("Nd");
      Ndindex3876 = readrel4070->getIndex(ord4069, false);
      std::vector<u16> ord4071({1, 0});
      slog::Relation* readrel4072 = db->getRelation("Lf");
      Lfindex3877 = readrel4072->getIndex(ord4071, false);
      std::vector<u16> ord4073({2, 1, 0});
      slog::Relation* readrel4074 = db->getRelation("Nd");
      Ndindex3878 = readrel4074->getIndex(ord4073, false);
      std::vector<u16> ord4075({1, 0});
      slog::Relation* readrel4076 = db->getRelation("Lf");
      Lfindex3879 = readrel4076->getIndex(ord4075, false);
      std::vector<u16> ord4077({2, 1, 0});
      slog::Relation* readrel4078 = db->getRelation("Nd");
      Ndindex3880 = readrel4078->getIndex(ord4077, false);
      std::vector<u16> ord4079({2, 1, 0});
      slog::Relation* readrel4080 = db->getRelation("Nd");
      Ndindex3881 = readrel4080->getIndex(ord4079, false);
      std::vector<u16> ord4081({1, 0});
      slog::Relation* readrel4082 = db->getRelation("Lf");
      Lfindex3882 = readrel4082->getIndex(ord4081, false);
      std::vector<u16> ord4083({2, 1, 0});
      slog::Relation* readrel4084 = db->getRelation("Nd");
      Ndindex3883 = readrel4084->getIndex(ord4083, false);
      std::vector<u16> ord4085({1, 0});
      slog::Relation* readrel4086 = db->getRelation("Lf");
      Lfindex3884 = readrel4086->getIndex(ord4085, false);
      std::vector<u16> ord4087({2, 1, 0});
      slog::Relation* readrel4088 = db->getRelation("Nd");
      Ndindex3885 = readrel4088->getIndex(ord4087, false);
      std::vector<u16> ord4089({2, 1, 0});
      slog::Relation* readrel4090 = db->getRelation("Nd");
      Ndindex3886 = readrel4090->getIndex(ord4089, false);
      std::vector<u16> ord4091({2, 1, 0});
      slog::Relation* readrel4092 = db->getRelation("Nd");
      Ndindex3887 = readrel4092->getIndex(ord4091, false);
      std::vector<u16> ord4093({1, 0});
      slog::Relation* readrel4094 = db->getRelation("Lf");
      Lfindex3888 = readrel4094->getIndex(ord4093, false);
      std::vector<u16> ord4095({2, 1, 0});
      slog::Relation* readrel4096 = db->getRelation("Nd");
      Ndindex3889 = readrel4096->getIndex(ord4095, false);
      std::vector<u16> ord4097({1, 0});
      slog::Relation* readrel4098 = db->getRelation("Lf");
      Lfindex3890 = readrel4098->getIndex(ord4097, false);
      std::vector<u16> ord4099({2, 1, 0});
      slog::Relation* readrel4100 = db->getRelation("Nd");
      Ndindex3891 = readrel4100->getIndex(ord4099, false);
      std::vector<u16> ord4101({2, 1, 0});
      slog::Relation* readrel4102 = db->getRelation("Nd");
      Ndindex3892 = readrel4102->getIndex(ord4101, false);
      std::vector<u16> ord4103({1, 0});
      slog::Relation* readrel4104 = db->getRelation("Lf");
      Lfindex3893 = readrel4104->getIndex(ord4103, false);
      std::vector<u16> ord4105({2, 1, 0});
      slog::Relation* readrel4106 = db->getRelation("Nd");
      Ndindex3894 = readrel4106->getIndex(ord4105, false);
      std::vector<u16> ord4107({1, 0});
      slog::Relation* readrel4108 = db->getRelation("Lf");
      Lfindex3895 = readrel4108->getIndex(ord4107, false);
      std::vector<u16> ord4109({2, 1, 0});
      slog::Relation* readrel4110 = db->getRelation("Nd");
      Ndindex3896 = readrel4110->getIndex(ord4109, false);
      std::vector<u16> ord4111({2, 1, 0});
      slog::Relation* readrel4112 = db->getRelation("Nd");
      Ndindex3897 = readrel4112->getIndex(ord4111, false);
      std::vector<u16> ord4113({2, 1, 0});
      slog::Relation* readrel4114 = db->getRelation("Nd");
      Ndindex3898 = readrel4114->getIndex(ord4113, false);
      std::vector<u16> ord4115({1, 0});
      slog::Relation* readrel4116 = db->getRelation("Lf");
      Lfindex3899 = readrel4116->getIndex(ord4115, false);
      std::vector<u16> ord4117({2, 1, 0});
      slog::Relation* readrel4118 = db->getRelation("Nd");
      Ndindex3900 = readrel4118->getIndex(ord4117, false);
      std::vector<u16> ord4119({1, 0});
      slog::Relation* readrel4120 = db->getRelation("Lf");
      Lfindex3901 = readrel4120->getIndex(ord4119, false);
      std::vector<u16> ord4121({2, 1, 0});
      slog::Relation* readrel4122 = db->getRelation("Nd");
      Ndindex3902 = readrel4122->getIndex(ord4121, false);
      std::vector<u16> ord4123({2, 1, 0});
      slog::Relation* readrel4124 = db->getRelation("Nd");
      Ndindex3903 = readrel4124->getIndex(ord4123, false);
      std::vector<u16> ord4125({1, 0});
      slog::Relation* readrel4126 = db->getRelation("Lf");
      Lfindex3904 = readrel4126->getIndex(ord4125, false);
      std::vector<u16> ord4127({2, 1, 0});
      slog::Relation* readrel4128 = db->getRelation("Nd");
      Ndindex3905 = readrel4128->getIndex(ord4127, false);
      std::vector<u16> ord4129({1, 0});
      slog::Relation* readrel4130 = db->getRelation("Lf");
      Lfindex3906 = readrel4130->getIndex(ord4129, false);
      std::vector<u16> ord4131({2, 1, 0});
      slog::Relation* readrel4132 = db->getRelation("Nd");
      Ndindex3907 = readrel4132->getIndex(ord4131, false);
      std::vector<u16> ord4133({2, 1, 0});
      slog::Relation* readrel4134 = db->getRelation("Nd");
      Ndindex3908 = readrel4134->getIndex(ord4133, false);
      std::vector<u16> ord4135({2, 1, 0});
      slog::Relation* readrel4136 = db->getRelation("Nd");
      Ndindex3909 = readrel4136->getIndex(ord4135, false);
  
    }
    ReadTask3910(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c34 = _t[0];
        u64 v_c42 = _t[1];
        u64 v_c41 = _t[2];
        if (!slog::exists_probe<2,1>(Lfindex3797, std::array<u64,2>{v_c30, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3798, std::array<u64,2>{v_c29, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3799, std::array<u64,2>{v_c28, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3800, std::array<u64,2>{v_c27, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3801, std::array<u64,2>{v_c26, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3802, std::array<u64,2>{v_c25, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3803, std::array<u64,2>{v_c24, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3804, std::array<u64,2>{v_c23, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3805, std::array<u64,2>{v_c22, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3806, std::array<u64,2>{v_c21, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3807, std::array<u64,2>{v_c20, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3808, std::array<u64,2>{v_c19, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3809, std::array<u64,2>{v_c18, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3810, std::array<u64,2>{v_c17, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3811, std::array<u64,2>{v_c16, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3812, std::array<u64,2>{v_c15, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3813, std::array<u64,2>{v_c14, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3814, std::array<u64,2>{v_c13, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3815, std::array<u64,2>{v_c12, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3816, std::array<u64,2>{v_c11, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3817, std::array<u64,2>{v_c10, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3818, std::array<u64,2>{v_c9, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3819, std::array<u64,2>{v_c8, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3820, std::array<u64,2>{v_c7, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3821, std::array<u64,2>{v_c6, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3822, std::array<u64,2>{v_c5, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3823, std::array<u64,2>{v_c4, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3824, std::array<u64,2>{v_c3, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3825, std::array<u64,2>{v_c2, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3826, std::array<u64,2>{v_c1, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex3827, std::array<u64,2>{v_c0, 0})) return;
        slog::join_probe<2,1>(Lfindex3828, std::array<u64,2>{v_c31, 0}, [&](const std::array<u64,2>& m4137) {
          u64 v_c35 = m4137[1];
          if (!slog::exists_probe<3,1>(Ndindex3829, std::array<u64,3>{v_c35, 0, 0})) return;
          slog::join_probe<2,1>(Lfindex3830, std::array<u64,2>{v_c30, 0}, [&](const std::array<u64,2>& m4138) {
            u64 v_c36 = m4138[1];
            slog::join_probe<3,2>(Ndindex3831, std::array<u64,3>{v_c35, v_c36, 0}, [&](const std::array<u64,3>& m4139) {
              u64 v_c37 = m4139[2];
              slog::join_probe<3,2>(Ndindex3832, std::array<u64,3>{v_c41, v_c37, 0}, [&](const std::array<u64,3>& m4140) {
                u64 v_c40 = m4140[2];
                slog::join_probe<2,1>(Lfindex3833, std::array<u64,2>{v_c29, 0}, [&](const std::array<u64,2>& m4141) {
                  u64 v_c38 = m4141[1];
                  slog::join_probe<3,2>(Ndindex3834, std::array<u64,3>{v_c40, v_c38, 0}, [&](const std::array<u64,3>& m4142) {
                    u64 v_c39 = m4142[2];
                    slog::join_probe<2,2>(Lfindex3835, std::array<u64,2>{v_c39, v_c28}, [&](const std::array<u64,2>& m4143) {
                      slog::join_probe<2,1>(Lfindex3836, std::array<u64,2>{v_c27, 0}, [&](const std::array<u64,2>& m4144) {
                        u64 v_c43 = m4144[1];
                        if (!slog::exists_probe<3,1>(Ndindex3837, std::array<u64,3>{v_c43, 0, 0})) return;
                        slog::join_probe<2,1>(Lfindex3838, std::array<u64,2>{v_c26, 0}, [&](const std::array<u64,2>& m4145) {
                          u64 v_c44 = m4145[1];
                          slog::join_probe<3,2>(Ndindex3839, std::array<u64,3>{v_c43, v_c44, 0}, [&](const std::array<u64,3>& m4146) {
                            u64 v_c45 = m4146[2];
                            slog::join_probe<3,2>(Ndindex3840, std::array<u64,3>{v_c42, v_c45, 0}, [&](const std::array<u64,3>& m4147) {
                              u64 v_c46 = m4147[2];
                              slog::join_probe<2,1>(Lfindex3841, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m4148) {
                                u64 v_c47 = m4148[1];
                                slog::join_probe<3,2>(Ndindex3842, std::array<u64,3>{v_c46, v_c47, 0}, [&](const std::array<u64,3>& m4149) {
                                  u64 v_c48 = m4149[2];
                                  slog::join_probe<2,2>(Lfindex3843, std::array<u64,2>{v_c48, v_c24}, [&](const std::array<u64,2>& m4150) {
                                    slog::join_probe<2,1>(Lfindex3844, std::array<u64,2>{v_c23, 0}, [&](const std::array<u64,2>& m4151) {
                                      u64 v_c49 = m4151[1];
                                      if (!slog::exists_probe<3,1>(Ndindex3845, std::array<u64,3>{v_c49, 0, 0})) return;
                                      slog::join_probe<2,1>(Lfindex3846, std::array<u64,2>{v_c22, 0}, [&](const std::array<u64,2>& m4152) {
                                        u64 v_c50 = m4152[1];
                                        slog::join_probe<3,2>(Ndindex3847, std::array<u64,3>{v_c49, v_c50, 0}, [&](const std::array<u64,3>& m4153) {
                                          u64 v_c51 = m4153[2];
                                          if (!slog::exists_probe<3,1>(Ndindex3848, std::array<u64,3>{v_c51, 0, 0})) return;
                                          slog::join_probe<2,1>(Lfindex3849, std::array<u64,2>{v_c21, 0}, [&](const std::array<u64,2>& m4154) {
                                            u64 v_c52 = m4154[1];
                                            if (!slog::exists_probe<3,1>(Ndindex3850, std::array<u64,3>{v_c52, 0, 0})) return;
                                            slog::join_probe<2,1>(Lfindex3851, std::array<u64,2>{v_c20, 0}, [&](const std::array<u64,2>& m4155) {
                                              u64 v_c53 = m4155[1];
                                              slog::join_probe<3,2>(Ndindex3852, std::array<u64,3>{v_c52, v_c53, 0}, [&](const std::array<u64,3>& m4156) {
                                                u64 v_c54 = m4156[2];
                                                slog::join_probe<3,2>(Ndindex3853, std::array<u64,3>{v_c51, v_c54, 0}, [&](const std::array<u64,3>& m4157) {
                                                  u64 v_c55 = m4157[2];
                                                  if (!slog::exists_probe<3,1>(Ndindex3854, std::array<u64,3>{v_c55, 0, 0})) return;
                                                  slog::join_probe<2,1>(Lfindex3855, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m4158) {
                                                    u64 v_c57 = m4158[1];
                                                    if (!slog::exists_probe<3,1>(Ndindex3856, std::array<u64,3>{v_c57, 0, 0})) return;
                                                    slog::join_probe<2,1>(Lfindex3857, std::array<u64,2>{v_c18, 0}, [&](const std::array<u64,2>& m4159) {
                                                      u64 v_c58 = m4159[1];
                                                      slog::join_probe<3,2>(Ndindex3858, std::array<u64,3>{v_c57, v_c58, 0}, [&](const std::array<u64,3>& m4160) {
                                                        u64 v_c59 = m4160[2];
                                                        if (!slog::exists_probe<3,1>(Ndindex3859, std::array<u64,3>{v_c59, 0, 0})) return;
                                                        slog::join_probe<2,1>(Lfindex3860, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m4161) {
                                                          u64 v_c61 = m4161[1];
                                                          if (!slog::exists_probe<3,1>(Ndindex3861, std::array<u64,3>{v_c61, 0, 0})) return;
                                                          slog::join_probe<2,1>(Lfindex3862, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m4162) {
                                                            u64 v_c62 = m4162[1];
                                                            slog::join_probe<3,2>(Ndindex3863, std::array<u64,3>{v_c61, v_c62, 0}, [&](const std::array<u64,3>& m4163) {
                                                              u64 v_c60 = m4163[2];
                                                              slog::join_probe<3,2>(Ndindex3864, std::array<u64,3>{v_c59, v_c60, 0}, [&](const std::array<u64,3>& m4164) {
                                                                u64 v_c56 = m4164[2];
                                                                slog::join_probe<3,2>(Ndindex3865, std::array<u64,3>{v_c55, v_c56, 0}, [&](const std::array<u64,3>& m4165) {
                                                                  u64 v_c33 = m4165[2];
                                                                  slog::join_probe<2,1>(Lfindex3866, std::array<u64,2>{v_c15, 0}, [&](const std::array<u64,2>& m4166) {
                                                                    u64 v_c63 = m4166[1];
                                                                    if (!slog::exists_probe<3,1>(Ndindex3867, std::array<u64,3>{v_c63, 0, 0})) return;
                                                                    slog::join_probe<2,1>(Lfindex3868, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m4167) {
                                                                      u64 v_c64 = m4167[1];
                                                                      slog::join_probe<3,2>(Ndindex3869, std::array<u64,3>{v_c63, v_c64, 0}, [&](const std::array<u64,3>& m4168) {
                                                                        u64 v_c65 = m4168[2];
                                                                        if (!slog::exists_probe<3,1>(Ndindex3870, std::array<u64,3>{v_c65, 0, 0})) return;
                                                                        slog::join_probe<2,1>(Lfindex3871, std::array<u64,2>{v_c13, 0}, [&](const std::array<u64,2>& m4169) {
                                                                          u64 v_c66 = m4169[1];
                                                                          if (!slog::exists_probe<3,1>(Ndindex3872, std::array<u64,3>{v_c66, 0, 0})) return;
                                                                          slog::join_probe<2,1>(Lfindex3873, std::array<u64,2>{v_c12, 0}, [&](const std::array<u64,2>& m4170) {
                                                                            u64 v_c67 = m4170[1];
                                                                            slog::join_probe<3,2>(Ndindex3874, std::array<u64,3>{v_c66, v_c67, 0}, [&](const std::array<u64,3>& m4171) {
                                                                              u64 v_c68 = m4171[2];
                                                                              slog::join_probe<3,2>(Ndindex3875, std::array<u64,3>{v_c65, v_c68, 0}, [&](const std::array<u64,3>& m4172) {
                                                                                u64 v_c69 = m4172[2];
                                                                                if (!slog::exists_probe<3,1>(Ndindex3876, std::array<u64,3>{v_c69, 0, 0})) return;
                                                                                slog::join_probe<2,1>(Lfindex3877, std::array<u64,2>{v_c11, 0}, [&](const std::array<u64,2>& m4173) {
                                                                                  u64 v_c70 = m4173[1];
                                                                                  if (!slog::exists_probe<3,1>(Ndindex3878, std::array<u64,3>{v_c70, 0, 0})) return;
                                                                                  slog::join_probe<2,1>(Lfindex3879, std::array<u64,2>{v_c10, 0}, [&](const std::array<u64,2>& m4174) {
                                                                                    u64 v_c71 = m4174[1];
                                                                                    slog::join_probe<3,2>(Ndindex3880, std::array<u64,3>{v_c70, v_c71, 0}, [&](const std::array<u64,3>& m4175) {
                                                                                      u64 v_c72 = m4175[2];
                                                                                      if (!slog::exists_probe<3,1>(Ndindex3881, std::array<u64,3>{v_c72, 0, 0})) return;
                                                                                      slog::join_probe<2,1>(Lfindex3882, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m4176) {
                                                                                        u64 v_c73 = m4176[1];
                                                                                        if (!slog::exists_probe<3,1>(Ndindex3883, std::array<u64,3>{v_c73, 0, 0})) return;
                                                                                        slog::join_probe<2,1>(Lfindex3884, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m4177) {
                                                                                          u64 v_c74 = m4177[1];
                                                                                          slog::join_probe<3,2>(Ndindex3885, std::array<u64,3>{v_c73, v_c74, 0}, [&](const std::array<u64,3>& m4178) {
                                                                                            u64 v_c75 = m4178[2];
                                                                                            slog::join_probe<3,2>(Ndindex3886, std::array<u64,3>{v_c72, v_c75, 0}, [&](const std::array<u64,3>& m4179) {
                                                                                              u64 v_c76 = m4179[2];
                                                                                              slog::join_probe<3,2>(Ndindex3887, std::array<u64,3>{v_c69, v_c76, 0}, [&](const std::array<u64,3>& m4180) {
                                                                                                u64 v_c77 = m4180[2];
                                                                                                slog::join_probe<2,1>(Lfindex3888, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m4181) {
                                                                                                  u64 v_c78 = m4181[1];
                                                                                                  if (!slog::exists_probe<3,1>(Ndindex3889, std::array<u64,3>{v_c78, 0, 0})) return;
                                                                                                  slog::join_probe<2,1>(Lfindex3890, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m4182) {
                                                                                                    u64 v_c79 = m4182[1];
                                                                                                    slog::join_probe<3,2>(Ndindex3891, std::array<u64,3>{v_c78, v_c79, 0}, [&](const std::array<u64,3>& m4183) {
                                                                                                      u64 v_c80 = m4183[2];
                                                                                                      if (!slog::exists_probe<3,1>(Ndindex3892, std::array<u64,3>{v_c80, 0, 0})) return;
                                                                                                      slog::join_probe<2,1>(Lfindex3893, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m4184) {
                                                                                                        u64 v_c81 = m4184[1];
                                                                                                        if (!slog::exists_probe<3,1>(Ndindex3894, std::array<u64,3>{v_c81, 0, 0})) return;
                                                                                                        slog::join_probe<2,1>(Lfindex3895, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m4185) {
                                                                                                          u64 v_c82 = m4185[1];
                                                                                                          slog::join_probe<3,2>(Ndindex3896, std::array<u64,3>{v_c81, v_c82, 0}, [&](const std::array<u64,3>& m4186) {
                                                                                                            u64 v_c83 = m4186[2];
                                                                                                            slog::join_probe<3,2>(Ndindex3897, std::array<u64,3>{v_c80, v_c83, 0}, [&](const std::array<u64,3>& m4187) {
                                                                                                              u64 v_c84 = m4187[2];
                                                                                                              if (!slog::exists_probe<3,1>(Ndindex3898, std::array<u64,3>{v_c84, 0, 0})) return;
                                                                                                              slog::join_probe<2,1>(Lfindex3899, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m4188) {
                                                                                                                u64 v_c85 = m4188[1];
                                                                                                                if (!slog::exists_probe<3,1>(Ndindex3900, std::array<u64,3>{v_c85, 0, 0})) return;
                                                                                                                slog::join_probe<2,1>(Lfindex3901, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m4189) {
                                                                                                                  u64 v_c86 = m4189[1];
                                                                                                                  slog::join_probe<3,2>(Ndindex3902, std::array<u64,3>{v_c85, v_c86, 0}, [&](const std::array<u64,3>& m4190) {
                                                                                                                    u64 v_c87 = m4190[2];
                                                                                                                    if (!slog::exists_probe<3,1>(Ndindex3903, std::array<u64,3>{v_c87, 0, 0})) return;
                                                                                                                    slog::join_probe<2,1>(Lfindex3904, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m4191) {
                                                                                                                      u64 v_c88 = m4191[1];
                                                                                                                      if (!slog::exists_probe<3,1>(Ndindex3905, std::array<u64,3>{v_c88, 0, 0})) return;
                                                                                                                      slog::join_probe<2,1>(Lfindex3906, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m4192) {
                                                                                                                        u64 v_c89 = m4192[1];
                                                                                                                        slog::join_probe<3,2>(Ndindex3907, std::array<u64,3>{v_c88, v_c89, 0}, [&](const std::array<u64,3>& m4193) {
                                                                                                                          u64 v_c90 = m4193[2];
                                                                                                                          slog::join_probe<3,2>(Ndindex3908, std::array<u64,3>{v_c87, v_c90, 0}, [&](const std::array<u64,3>& m4194) {
                                                                                                                            u64 v_c91 = m4194[2];
                                                                                                                            slog::join_probe<3,2>(Ndindex3909, std::array<u64,3>{v_c84, v_c91, 0}, [&](const std::array<u64,3>& m4195) {
                                                                                                                              u64 v_c92 = m4195[2];
                                                                                                                              ++_fires;
                                                                                                                              slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c77, v_c92}, std::array<u16,3>{2, 1, 0});
                                                                                                                              slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c34, v_c33}, std::array<u16,3>{2, 1, 0});
                                                                                                                            });
                                                                                                                          });
                                                                                                                        });
                                                                                                                      });
                                                                                                                    });
                                                                                                                  });
                                                                                                                });
                                                                                                              });
                                                                                                            });
                                                                                                          });
                                                                                                        });
                                                                                                      });
                                                                                                    });
                                                                                                  });
                                                                                                });
                                                                                              });
                                                                                            });
                                                                                          });
                                                                                        });
                                                                                      });
                                                                                    });
                                                                                  });
                                                                                });
                                                                              });
                                                                            });
                                                                          });
                                                                        });
                                                                      });
                                                                    });
                                                                  });
                                                                });
                                                              });
                                                            });
                                                          });
                                                        });
                                                      });
                                                    });
                                                  });
                                                });
                                              });
                                            });
                                          });
                                        });
                                      });
                                    });
                                  });
                                });
                              });
                            });
                          });
                        });
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
  
      if (_fires) db->bumpFires("deep_fact.slog:7", "delta:Nd", _fires);
  
      if (!_done)
      {
        ReadTask3910* _cont = new ReadTask3910(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask3910(db,b), false);
  // (crule (pre (let __tconst48SJ108 const6b86b273ff34fce19d6b804e) (let __tconst5Uhl106 constd4735e3a265e16eee03f5971) (let __tconst9YpM103 const4e07408562bedb8b60ce05c1) (let __tconst3iHp101 const4b227777d4dd1fc61c6f884f) (let __tconst0Emh97 constef2d127de37b942baad06145) (let __tconst29xA95 conste7f6c011776e8db7cd330b54) (let __tconst9mjQ92 const7902699be42c8a8e46fbbb45) (let __tconst9Yxv90 const2c624232cdd221771294dfbb) (let __tconst7wWY85 const19581e27de7ced00ff1ce50b) (let __tconst01Wl83 const4a44dc15364204a80fe80e90) (let __tconst42lR80 const4fc82b26aecb47d2868c4efb) (let __tconst3KyY78 const6b51d431df5d7f141cbececc) (let __tconst6a9N74 const3fdba35f04dc8c462986c992) (let __tconst74Qx72 const8527a891e224136950ff32ca) (let __tconst2hOw69 conste629fa6598d732768f7c726b) (let __tconst7kHD67 constb17ef6d19c7a5b1ee83b907c) (let __tconst5zmq61 const4523540f1504cd17100c4835) (let __tconst31qC59 const4ec9599fc203d176a301536c) (let __tconst4Vop56 const9400f1b21cb527d7fa3d3eab) (let __tconst51zc54 constf5ca38f748a1d6eaf726b8a4) (let __tconst6Qm150 const6f4b6612125fb3a0daecd279) (let __tconst6bEj48 const785f3ec7eb32f30b90cd0fcf) (let __tconst7AKN45 const535fa30d7e25dd8a49f15367) (let __tconst9j2a43 constc2356069e9d1e79ca9243781) (let __tconst1Mto38 constb7a56873cd771f2c446d369b) (let __tconst8u8i36 const5f9c4ab08cac7457e9111a30) (let __tconst2Isx33 const670671cd97404156226e5079) (let __tconst8J6R31 const59e19706d51d39f66711c265) (let __tconst88cs27 const35135aaa6cc23891b40cb3f3) (let __tconst0Uuf25 const624b60c58c9d8bfb6ff1886c) (let __tconst6sf622 consteb1e33e8a81b697b75855af6) (let __tconst5Run20 conste29c9c180c6279b0b02abd6a)) (probe Lf (1 0) 1 __tconst5Run20 __t8mDO21) (body (exists Lf (1 0) 1 __tconst0Uuf25) (exists Lf (1 0) 1 __tconst88cs27) (exists Lf (1 0) 1 __tconst8J6R31) (exists Lf (1 0) 1 __tconst2Isx33) (exists Lf (1 0) 1 __tconst8u8i36) (exists Lf (1 0) 1 __tconst1Mto38) (exists Lf (1 0) 1 __tconst9j2a43) (exists Lf (1 0) 1 __tconst7AKN45) (exists Lf (1 0) 1 __tconst6bEj48) (exists Lf (1 0) 1 __tconst6Qm150) (exists Lf (1 0) 1 __tconst51zc54) (exists Lf (1 0) 1 __tconst4Vop56) (exists Lf (1 0) 1 __tconst31qC59) (exists Lf (1 0) 1 __tconst5zmq61) (exists Lf (1 0) 1 __tconst7kHD67) (exists Lf (1 0) 1 __tconst2hOw69) (exists Lf (1 0) 1 __tconst74Qx72) (exists Lf (1 0) 1 __tconst6a9N74) (exists Lf (1 0) 1 __tconst3KyY78) (exists Lf (1 0) 1 __tconst42lR80) (exists Lf (1 0) 1 __tconst01Wl83) (exists Lf (1 0) 1 __tconst7wWY85) (exists Lf (1 0) 1 __tconst9Yxv90) (exists Lf (1 0) 1 __tconst9mjQ92) (exists Lf (1 0) 1 __tconst29xA95) (exists Lf (1 0) 1 __tconst0Emh97) (exists Lf (1 0) 1 __tconst3iHp101) (exists Lf (1 0) 1 __tconst9YpM103) (exists Lf (1 0) 1 __tconst5Uhl106) (exists Lf (1 0) 1 __tconst48SJ108) (join Lf (1 0) 1 __tconst6sf622 __t1M8o23) (join Lf (1 0) 1 __tconst0Uuf25 __t1NQv26) (join Lf (1 0) 1 __tconst88cs27 __t7d0c28) (join Lf (1 0) 1 __tconst8J6R31 __t9vh832) (join Lf (1 0) 1 __tconst2Isx33 __t5flt34) (join Lf (1 0) 1 __tconst8u8i36 __t27Zr37) (join Lf (1 0) 1 __tconst1Mto38 __t3UFu39) (join Lf (1 0) 1 __tconst9j2a43 __t6IKq44) (join Lf (1 0) 1 __tconst7AKN45 __t6LIW46) (join Lf (1 0) 1 __tconst6bEj48 __t9k7a49) (join Lf (1 0) 1 __tconst6Qm150 __t4MdC51) (join Lf (1 0) 1 __tconst51zc54 __t3Yon55) (join Lf (1 0) 1 __tconst4Vop56 __t5ik157) (join Lf (1 0) 1 __tconst31qC59 __t1nkJ60) (join Lf (1 0) 1 __tconst5zmq61 __t4E3D62) (join Lf (1 0) 1 __tconst7kHD67 __t4J2N68) (join Lf (1 0) 1 __tconst2hOw69 __t4izo70) (join Lf (1 0) 1 __tconst74Qx72 __t319l73) (join Lf (1 0) 1 __tconst6a9N74 __t0amQ75) (join Lf (1 0) 1 __tconst3KyY78 __t13gt79) (join Lf (1 0) 1 __tconst42lR80 __t3ESz81) (join Lf (1 0) 1 __tconst01Wl83 __t4Da384) (join Lf (1 0) 1 __tconst7wWY85 __t91gs86) (join Lf (1 0) 1 __tconst9Yxv90 __t7UaH91) (join Lf (1 0) 1 __tconst9mjQ92 __t6IMg93) (join Lf (1 0) 1 __tconst29xA95 __t2oHE96) (join Lf (1 0) 1 __tconst0Emh97 __t7bue98) (join Lf (1 0) 1 __tconst3iHp101 __t5yzC102) (join Lf (1 0) 1 __tconst9YpM103 __t7c21104) (join Lf (1 0) 1 __tconst5Uhl106 __t1IJA107) (join Lf (1 0) 1 __tconst48SJ108 __t0y5t109)) (head (mkstruct Nd (2 1 0) __t76VS110 __t1IJA107 __t0y5t109) (mkstruct Nd (2 1 0) __t4bRV105 __t5yzC102 __t7c21104) (mkstruct Nd (2 1 0) __t0HkS99 __t2oHE96 __t7bue98) (mkstruct Nd (2 1 0) __t2T3i94 __t7UaH91 __t6IMg93) (mkstruct Nd (2 1 0) __t02Bu87 __t4Da384 __t91gs86) (mkstruct Nd (2 1 0) __t3WL082 __t13gt79 __t3ESz81) (mkstruct Nd (2 1 0) __t4MUf76 __t319l73 __t0amQ75) (mkstruct Nd (2 1 0) __t14Ff71 __t4J2N68 __t4izo70) (mkstruct Nd (2 1 0) __t8TXU63 __t1nkJ60 __t4E3D62) (mkstruct Nd (2 1 0) __t4hi358 __t3Yon55 __t5ik157) (mkstruct Nd (2 1 0) __t8A9i52 __t9k7a49 __t4MdC51) (mkstruct Nd (2 1 0) __t7C7d47 __t6IKq44 __t6LIW46) (mkstruct Nd (2 1 0) __t8qqV40 __t27Zr37 __t3UFu39) (mkstruct Nd (2 1 0) __t3jHg35 __t9vh832 __t5flt34) (mkstruct Nd (2 1 0) __t0kIY29 __t1NQv26 __t7d0c28) (mkstruct Nd (2 1 0) __t7LF824 __t8mDO21 __t1M8o23)) deep_fact.slog:7 #f)
  class ReadTask4257 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[16];
    slog::Index** head_index[16];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** Lfindex4196;  slog::Index** Lfindex4197;  slog::Index** Lfindex4198;  slog::Index** Lfindex4199;  slog::Index** Lfindex4200;  slog::Index** Lfindex4201;  slog::Index** Lfindex4202;  slog::Index** Lfindex4203;  slog::Index** Lfindex4204;  slog::Index** Lfindex4205;  slog::Index** Lfindex4206;  slog::Index** Lfindex4207;  slog::Index** Lfindex4208;  slog::Index** Lfindex4209;  slog::Index** Lfindex4210;  slog::Index** Lfindex4211;  slog::Index** Lfindex4212;  slog::Index** Lfindex4213;  slog::Index** Lfindex4214;  slog::Index** Lfindex4215;  slog::Index** Lfindex4216;  slog::Index** Lfindex4217;  slog::Index** Lfindex4218;  slog::Index** Lfindex4219;  slog::Index** Lfindex4220;  slog::Index** Lfindex4221;  slog::Index** Lfindex4222;  slog::Index** Lfindex4223;  slog::Index** Lfindex4224;  slog::Index** Lfindex4225;  slog::Index** Lfindex4226;  slog::Index** Lfindex4227;  slog::Index** Lfindex4228;  slog::Index** Lfindex4229;  slog::Index** Lfindex4230;  slog::Index** Lfindex4231;  slog::Index** Lfindex4232;  slog::Index** Lfindex4233;  slog::Index** Lfindex4234;  slog::Index** Lfindex4235;  slog::Index** Lfindex4236;  slog::Index** Lfindex4237;  slog::Index** Lfindex4238;  slog::Index** Lfindex4239;  slog::Index** Lfindex4240;  slog::Index** Lfindex4241;  slog::Index** Lfindex4242;  slog::Index** Lfindex4243;  slog::Index** Lfindex4244;  slog::Index** Lfindex4245;  slog::Index** Lfindex4246;  slog::Index** Lfindex4247;  slog::Index** Lfindex4248;  slog::Index** Lfindex4249;  slog::Index** Lfindex4250;  slog::Index** Lfindex4251;  slog::Index** Lfindex4252;  slog::Index** Lfindex4253;  slog::Index** Lfindex4254;  slog::Index** Lfindex4255;  slog::Index** Lfindex4256;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("Nd");
      head_rel[1] = db->getRelation("Nd");
      head_rel[2] = db->getRelation("Nd");
      head_rel[3] = db->getRelation("Nd");
      head_rel[4] = db->getRelation("Nd");
      head_rel[5] = db->getRelation("Nd");
      head_rel[6] = db->getRelation("Nd");
      head_rel[7] = db->getRelation("Nd");
      head_rel[8] = db->getRelation("Nd");
      head_rel[9] = db->getRelation("Nd");
      head_rel[10] = db->getRelation("Nd");
      head_rel[11] = db->getRelation("Nd");
      head_rel[12] = db->getRelation("Nd");
      head_rel[13] = db->getRelation("Nd");
      head_rel[14] = db->getRelation("Nd");
      head_rel[15] = db->getRelation("Nd");
      std::vector<u16> ord4258({1, 0});
      slog::Relation* readrel4259 = db->getRelation("Lf");
      driver_index = readrel4259->getIndex(ord4258, true);
      std::vector<u16> ord4260({1, 0});
      slog::Relation* readrel4261 = db->getRelation("Lf");
      Lfindex4196 = readrel4261->getIndex(ord4260, false);
      std::vector<u16> ord4262({1, 0});
      slog::Relation* readrel4263 = db->getRelation("Lf");
      Lfindex4197 = readrel4263->getIndex(ord4262, false);
      std::vector<u16> ord4264({1, 0});
      slog::Relation* readrel4265 = db->getRelation("Lf");
      Lfindex4198 = readrel4265->getIndex(ord4264, false);
      std::vector<u16> ord4266({1, 0});
      slog::Relation* readrel4267 = db->getRelation("Lf");
      Lfindex4199 = readrel4267->getIndex(ord4266, false);
      std::vector<u16> ord4268({1, 0});
      slog::Relation* readrel4269 = db->getRelation("Lf");
      Lfindex4200 = readrel4269->getIndex(ord4268, false);
      std::vector<u16> ord4270({1, 0});
      slog::Relation* readrel4271 = db->getRelation("Lf");
      Lfindex4201 = readrel4271->getIndex(ord4270, false);
      std::vector<u16> ord4272({1, 0});
      slog::Relation* readrel4273 = db->getRelation("Lf");
      Lfindex4202 = readrel4273->getIndex(ord4272, false);
      std::vector<u16> ord4274({1, 0});
      slog::Relation* readrel4275 = db->getRelation("Lf");
      Lfindex4203 = readrel4275->getIndex(ord4274, false);
      std::vector<u16> ord4276({1, 0});
      slog::Relation* readrel4277 = db->getRelation("Lf");
      Lfindex4204 = readrel4277->getIndex(ord4276, false);
      std::vector<u16> ord4278({1, 0});
      slog::Relation* readrel4279 = db->getRelation("Lf");
      Lfindex4205 = readrel4279->getIndex(ord4278, false);
      std::vector<u16> ord4280({1, 0});
      slog::Relation* readrel4281 = db->getRelation("Lf");
      Lfindex4206 = readrel4281->getIndex(ord4280, false);
      std::vector<u16> ord4282({1, 0});
      slog::Relation* readrel4283 = db->getRelation("Lf");
      Lfindex4207 = readrel4283->getIndex(ord4282, false);
      std::vector<u16> ord4284({1, 0});
      slog::Relation* readrel4285 = db->getRelation("Lf");
      Lfindex4208 = readrel4285->getIndex(ord4284, false);
      std::vector<u16> ord4286({1, 0});
      slog::Relation* readrel4287 = db->getRelation("Lf");
      Lfindex4209 = readrel4287->getIndex(ord4286, false);
      std::vector<u16> ord4288({1, 0});
      slog::Relation* readrel4289 = db->getRelation("Lf");
      Lfindex4210 = readrel4289->getIndex(ord4288, false);
      std::vector<u16> ord4290({1, 0});
      slog::Relation* readrel4291 = db->getRelation("Lf");
      Lfindex4211 = readrel4291->getIndex(ord4290, false);
      std::vector<u16> ord4292({1, 0});
      slog::Relation* readrel4293 = db->getRelation("Lf");
      Lfindex4212 = readrel4293->getIndex(ord4292, false);
      std::vector<u16> ord4294({1, 0});
      slog::Relation* readrel4295 = db->getRelation("Lf");
      Lfindex4213 = readrel4295->getIndex(ord4294, false);
      std::vector<u16> ord4296({1, 0});
      slog::Relation* readrel4297 = db->getRelation("Lf");
      Lfindex4214 = readrel4297->getIndex(ord4296, false);
      std::vector<u16> ord4298({1, 0});
      slog::Relation* readrel4299 = db->getRelation("Lf");
      Lfindex4215 = readrel4299->getIndex(ord4298, false);
      std::vector<u16> ord4300({1, 0});
      slog::Relation* readrel4301 = db->getRelation("Lf");
      Lfindex4216 = readrel4301->getIndex(ord4300, false);
      std::vector<u16> ord4302({1, 0});
      slog::Relation* readrel4303 = db->getRelation("Lf");
      Lfindex4217 = readrel4303->getIndex(ord4302, false);
      std::vector<u16> ord4304({1, 0});
      slog::Relation* readrel4305 = db->getRelation("Lf");
      Lfindex4218 = readrel4305->getIndex(ord4304, false);
      std::vector<u16> ord4306({1, 0});
      slog::Relation* readrel4307 = db->getRelation("Lf");
      Lfindex4219 = readrel4307->getIndex(ord4306, false);
      std::vector<u16> ord4308({1, 0});
      slog::Relation* readrel4309 = db->getRelation("Lf");
      Lfindex4220 = readrel4309->getIndex(ord4308, false);
      std::vector<u16> ord4310({1, 0});
      slog::Relation* readrel4311 = db->getRelation("Lf");
      Lfindex4221 = readrel4311->getIndex(ord4310, false);
      std::vector<u16> ord4312({1, 0});
      slog::Relation* readrel4313 = db->getRelation("Lf");
      Lfindex4222 = readrel4313->getIndex(ord4312, false);
      std::vector<u16> ord4314({1, 0});
      slog::Relation* readrel4315 = db->getRelation("Lf");
      Lfindex4223 = readrel4315->getIndex(ord4314, false);
      std::vector<u16> ord4316({1, 0});
      slog::Relation* readrel4317 = db->getRelation("Lf");
      Lfindex4224 = readrel4317->getIndex(ord4316, false);
      std::vector<u16> ord4318({1, 0});
      slog::Relation* readrel4319 = db->getRelation("Lf");
      Lfindex4225 = readrel4319->getIndex(ord4318, false);
      std::vector<u16> ord4320({1, 0});
      slog::Relation* readrel4321 = db->getRelation("Lf");
      Lfindex4226 = readrel4321->getIndex(ord4320, false);
      std::vector<u16> ord4322({1, 0});
      slog::Relation* readrel4323 = db->getRelation("Lf");
      Lfindex4227 = readrel4323->getIndex(ord4322, false);
      std::vector<u16> ord4324({1, 0});
      slog::Relation* readrel4325 = db->getRelation("Lf");
      Lfindex4228 = readrel4325->getIndex(ord4324, false);
      std::vector<u16> ord4326({1, 0});
      slog::Relation* readrel4327 = db->getRelation("Lf");
      Lfindex4229 = readrel4327->getIndex(ord4326, false);
      std::vector<u16> ord4328({1, 0});
      slog::Relation* readrel4329 = db->getRelation("Lf");
      Lfindex4230 = readrel4329->getIndex(ord4328, false);
      std::vector<u16> ord4330({1, 0});
      slog::Relation* readrel4331 = db->getRelation("Lf");
      Lfindex4231 = readrel4331->getIndex(ord4330, false);
      std::vector<u16> ord4332({1, 0});
      slog::Relation* readrel4333 = db->getRelation("Lf");
      Lfindex4232 = readrel4333->getIndex(ord4332, false);
      std::vector<u16> ord4334({1, 0});
      slog::Relation* readrel4335 = db->getRelation("Lf");
      Lfindex4233 = readrel4335->getIndex(ord4334, false);
      std::vector<u16> ord4336({1, 0});
      slog::Relation* readrel4337 = db->getRelation("Lf");
      Lfindex4234 = readrel4337->getIndex(ord4336, false);
      std::vector<u16> ord4338({1, 0});
      slog::Relation* readrel4339 = db->getRelation("Lf");
      Lfindex4235 = readrel4339->getIndex(ord4338, false);
      std::vector<u16> ord4340({1, 0});
      slog::Relation* readrel4341 = db->getRelation("Lf");
      Lfindex4236 = readrel4341->getIndex(ord4340, false);
      std::vector<u16> ord4342({1, 0});
      slog::Relation* readrel4343 = db->getRelation("Lf");
      Lfindex4237 = readrel4343->getIndex(ord4342, false);
      std::vector<u16> ord4344({1, 0});
      slog::Relation* readrel4345 = db->getRelation("Lf");
      Lfindex4238 = readrel4345->getIndex(ord4344, false);
      std::vector<u16> ord4346({1, 0});
      slog::Relation* readrel4347 = db->getRelation("Lf");
      Lfindex4239 = readrel4347->getIndex(ord4346, false);
      std::vector<u16> ord4348({1, 0});
      slog::Relation* readrel4349 = db->getRelation("Lf");
      Lfindex4240 = readrel4349->getIndex(ord4348, false);
      std::vector<u16> ord4350({1, 0});
      slog::Relation* readrel4351 = db->getRelation("Lf");
      Lfindex4241 = readrel4351->getIndex(ord4350, false);
      std::vector<u16> ord4352({1, 0});
      slog::Relation* readrel4353 = db->getRelation("Lf");
      Lfindex4242 = readrel4353->getIndex(ord4352, false);
      std::vector<u16> ord4354({1, 0});
      slog::Relation* readrel4355 = db->getRelation("Lf");
      Lfindex4243 = readrel4355->getIndex(ord4354, false);
      std::vector<u16> ord4356({1, 0});
      slog::Relation* readrel4357 = db->getRelation("Lf");
      Lfindex4244 = readrel4357->getIndex(ord4356, false);
      std::vector<u16> ord4358({1, 0});
      slog::Relation* readrel4359 = db->getRelation("Lf");
      Lfindex4245 = readrel4359->getIndex(ord4358, false);
      std::vector<u16> ord4360({1, 0});
      slog::Relation* readrel4361 = db->getRelation("Lf");
      Lfindex4246 = readrel4361->getIndex(ord4360, false);
      std::vector<u16> ord4362({1, 0});
      slog::Relation* readrel4363 = db->getRelation("Lf");
      Lfindex4247 = readrel4363->getIndex(ord4362, false);
      std::vector<u16> ord4364({1, 0});
      slog::Relation* readrel4365 = db->getRelation("Lf");
      Lfindex4248 = readrel4365->getIndex(ord4364, false);
      std::vector<u16> ord4366({1, 0});
      slog::Relation* readrel4367 = db->getRelation("Lf");
      Lfindex4249 = readrel4367->getIndex(ord4366, false);
      std::vector<u16> ord4368({1, 0});
      slog::Relation* readrel4369 = db->getRelation("Lf");
      Lfindex4250 = readrel4369->getIndex(ord4368, false);
      std::vector<u16> ord4370({1, 0});
      slog::Relation* readrel4371 = db->getRelation("Lf");
      Lfindex4251 = readrel4371->getIndex(ord4370, false);
      std::vector<u16> ord4372({1, 0});
      slog::Relation* readrel4373 = db->getRelation("Lf");
      Lfindex4252 = readrel4373->getIndex(ord4372, false);
      std::vector<u16> ord4374({1, 0});
      slog::Relation* readrel4375 = db->getRelation("Lf");
      Lfindex4253 = readrel4375->getIndex(ord4374, false);
      std::vector<u16> ord4376({1, 0});
      slog::Relation* readrel4377 = db->getRelation("Lf");
      Lfindex4254 = readrel4377->getIndex(ord4376, false);
      std::vector<u16> ord4378({1, 0});
      slog::Relation* readrel4379 = db->getRelation("Lf");
      Lfindex4255 = readrel4379->getIndex(ord4378, false);
      std::vector<u16> ord4380({1, 0});
      slog::Relation* readrel4381 = db->getRelation("Lf");
      Lfindex4256 = readrel4381->getIndex(ord4380, false);
  
    }
    ReadTask4257(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[16];
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
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c31, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m4382) {
        u64 v_c35 = m4382[1];
        if (buckethash(v_c35) != bucket) return;
        if (!slog::exists_probe<2,1>(Lfindex4196, std::array<u64,2>{v_c29, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex4197, std::array<u64,2>{v_c28, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex4198, std::array<u64,2>{v_c27, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex4199, std::array<u64,2>{v_c26, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex4200, std::array<u64,2>{v_c25, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex4201, std::array<u64,2>{v_c24, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex4202, std::array<u64,2>{v_c23, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex4203, std::array<u64,2>{v_c22, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex4204, std::array<u64,2>{v_c21, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex4205, std::array<u64,2>{v_c20, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex4206, std::array<u64,2>{v_c19, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex4207, std::array<u64,2>{v_c18, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex4208, std::array<u64,2>{v_c17, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex4209, std::array<u64,2>{v_c16, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex4210, std::array<u64,2>{v_c15, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex4211, std::array<u64,2>{v_c14, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex4212, std::array<u64,2>{v_c13, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex4213, std::array<u64,2>{v_c12, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex4214, std::array<u64,2>{v_c11, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex4215, std::array<u64,2>{v_c10, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex4216, std::array<u64,2>{v_c9, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex4217, std::array<u64,2>{v_c8, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex4218, std::array<u64,2>{v_c7, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex4219, std::array<u64,2>{v_c6, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex4220, std::array<u64,2>{v_c5, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex4221, std::array<u64,2>{v_c4, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex4222, std::array<u64,2>{v_c3, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex4223, std::array<u64,2>{v_c2, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex4224, std::array<u64,2>{v_c1, 0})) return;
        if (!slog::exists_probe<2,1>(Lfindex4225, std::array<u64,2>{v_c0, 0})) return;
        slog::join_probe<2,1>(Lfindex4226, std::array<u64,2>{v_c30, 0}, [&](const std::array<u64,2>& m4383) {
          u64 v_c36 = m4383[1];
          slog::join_probe<2,1>(Lfindex4227, std::array<u64,2>{v_c29, 0}, [&](const std::array<u64,2>& m4384) {
            u64 v_c38 = m4384[1];
            slog::join_probe<2,1>(Lfindex4228, std::array<u64,2>{v_c28, 0}, [&](const std::array<u64,2>& m4385) {
              u64 v_c39 = m4385[1];
              slog::join_probe<2,1>(Lfindex4229, std::array<u64,2>{v_c27, 0}, [&](const std::array<u64,2>& m4386) {
                u64 v_c43 = m4386[1];
                slog::join_probe<2,1>(Lfindex4230, std::array<u64,2>{v_c26, 0}, [&](const std::array<u64,2>& m4387) {
                  u64 v_c44 = m4387[1];
                  slog::join_probe<2,1>(Lfindex4231, std::array<u64,2>{v_c25, 0}, [&](const std::array<u64,2>& m4388) {
                    u64 v_c47 = m4388[1];
                    slog::join_probe<2,1>(Lfindex4232, std::array<u64,2>{v_c24, 0}, [&](const std::array<u64,2>& m4389) {
                      u64 v_c48 = m4389[1];
                      slog::join_probe<2,1>(Lfindex4233, std::array<u64,2>{v_c23, 0}, [&](const std::array<u64,2>& m4390) {
                        u64 v_c49 = m4390[1];
                        slog::join_probe<2,1>(Lfindex4234, std::array<u64,2>{v_c22, 0}, [&](const std::array<u64,2>& m4391) {
                          u64 v_c50 = m4391[1];
                          slog::join_probe<2,1>(Lfindex4235, std::array<u64,2>{v_c21, 0}, [&](const std::array<u64,2>& m4392) {
                            u64 v_c52 = m4392[1];
                            slog::join_probe<2,1>(Lfindex4236, std::array<u64,2>{v_c20, 0}, [&](const std::array<u64,2>& m4393) {
                              u64 v_c53 = m4393[1];
                              slog::join_probe<2,1>(Lfindex4237, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m4394) {
                                u64 v_c57 = m4394[1];
                                slog::join_probe<2,1>(Lfindex4238, std::array<u64,2>{v_c18, 0}, [&](const std::array<u64,2>& m4395) {
                                  u64 v_c58 = m4395[1];
                                  slog::join_probe<2,1>(Lfindex4239, std::array<u64,2>{v_c17, 0}, [&](const std::array<u64,2>& m4396) {
                                    u64 v_c61 = m4396[1];
                                    slog::join_probe<2,1>(Lfindex4240, std::array<u64,2>{v_c16, 0}, [&](const std::array<u64,2>& m4397) {
                                      u64 v_c62 = m4397[1];
                                      slog::join_probe<2,1>(Lfindex4241, std::array<u64,2>{v_c15, 0}, [&](const std::array<u64,2>& m4398) {
                                        u64 v_c63 = m4398[1];
                                        slog::join_probe<2,1>(Lfindex4242, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m4399) {
                                          u64 v_c64 = m4399[1];
                                          slog::join_probe<2,1>(Lfindex4243, std::array<u64,2>{v_c13, 0}, [&](const std::array<u64,2>& m4400) {
                                            u64 v_c66 = m4400[1];
                                            slog::join_probe<2,1>(Lfindex4244, std::array<u64,2>{v_c12, 0}, [&](const std::array<u64,2>& m4401) {
                                              u64 v_c67 = m4401[1];
                                              slog::join_probe<2,1>(Lfindex4245, std::array<u64,2>{v_c11, 0}, [&](const std::array<u64,2>& m4402) {
                                                u64 v_c70 = m4402[1];
                                                slog::join_probe<2,1>(Lfindex4246, std::array<u64,2>{v_c10, 0}, [&](const std::array<u64,2>& m4403) {
                                                  u64 v_c71 = m4403[1];
                                                  slog::join_probe<2,1>(Lfindex4247, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m4404) {
                                                    u64 v_c73 = m4404[1];
                                                    slog::join_probe<2,1>(Lfindex4248, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m4405) {
                                                      u64 v_c74 = m4405[1];
                                                      slog::join_probe<2,1>(Lfindex4249, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m4406) {
                                                        u64 v_c78 = m4406[1];
                                                        slog::join_probe<2,1>(Lfindex4250, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m4407) {
                                                          u64 v_c79 = m4407[1];
                                                          slog::join_probe<2,1>(Lfindex4251, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m4408) {
                                                            u64 v_c81 = m4408[1];
                                                            slog::join_probe<2,1>(Lfindex4252, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m4409) {
                                                              u64 v_c82 = m4409[1];
                                                              slog::join_probe<2,1>(Lfindex4253, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m4410) {
                                                                u64 v_c85 = m4410[1];
                                                                slog::join_probe<2,1>(Lfindex4254, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m4411) {
                                                                  u64 v_c86 = m4411[1];
                                                                  slog::join_probe<2,1>(Lfindex4255, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m4412) {
                                                                    u64 v_c88 = m4412[1];
                                                                    slog::join_probe<2,1>(Lfindex4256, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m4413) {
                                                                      u64 v_c89 = m4413[1];
                                                                      ++_fires;
                                                                      slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c88, v_c89}, std::array<u16,3>{2, 1, 0});
                                                                      slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c85, v_c86}, std::array<u16,3>{2, 1, 0});
                                                                      slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c81, v_c82}, std::array<u16,3>{2, 1, 0});
                                                                      slog::emit_struct<3>(head_rel[3], newbatch[3], std::array<u64,2>{v_c78, v_c79}, std::array<u16,3>{2, 1, 0});
                                                                      slog::emit_struct<3>(head_rel[4], newbatch[4], std::array<u64,2>{v_c73, v_c74}, std::array<u16,3>{2, 1, 0});
                                                                      slog::emit_struct<3>(head_rel[5], newbatch[5], std::array<u64,2>{v_c70, v_c71}, std::array<u16,3>{2, 1, 0});
                                                                      slog::emit_struct<3>(head_rel[6], newbatch[6], std::array<u64,2>{v_c66, v_c67}, std::array<u16,3>{2, 1, 0});
                                                                      slog::emit_struct<3>(head_rel[7], newbatch[7], std::array<u64,2>{v_c63, v_c64}, std::array<u16,3>{2, 1, 0});
                                                                      slog::emit_struct<3>(head_rel[8], newbatch[8], std::array<u64,2>{v_c61, v_c62}, std::array<u16,3>{2, 1, 0});
                                                                      slog::emit_struct<3>(head_rel[9], newbatch[9], std::array<u64,2>{v_c57, v_c58}, std::array<u16,3>{2, 1, 0});
                                                                      slog::emit_struct<3>(head_rel[10], newbatch[10], std::array<u64,2>{v_c52, v_c53}, std::array<u16,3>{2, 1, 0});
                                                                      slog::emit_struct<3>(head_rel[11], newbatch[11], std::array<u64,2>{v_c49, v_c50}, std::array<u16,3>{2, 1, 0});
                                                                      slog::emit_struct<3>(head_rel[12], newbatch[12], std::array<u64,2>{v_c47, v_c48}, std::array<u16,3>{2, 1, 0});
                                                                      slog::emit_struct<3>(head_rel[13], newbatch[13], std::array<u64,2>{v_c43, v_c44}, std::array<u16,3>{2, 1, 0});
                                                                      slog::emit_struct<3>(head_rel[14], newbatch[14], std::array<u64,2>{v_c38, v_c39}, std::array<u16,3>{2, 1, 0});
                                                                      slog::emit_struct<3>(head_rel[15], newbatch[15], std::array<u64,2>{v_c35, v_c36}, std::array<u16,3>{2, 1, 0});
                                                                    });
                                                                  });
                                                                });
                                                              });
                                                            });
                                                          });
                                                        });
                                                      });
                                                    });
                                                  });
                                                });
                                              });
                                            });
                                          });
                                        });
                                      });
                                    });
                                  });
                                });
                              });
                            });
                          });
                        });
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
  
      if (_fires) db->bumpFires("deep_fact.slog:7", "delta:Lf", _fires);
  
      if (!_done)
      {
        ReadTask4257* _cont = new ReadTask4257(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask4257(db,b), false);
  s->addReadRel("Lf");
  s->addReadRel("Nd");
  s->addDynamicRel("Lf");
  s->addDynamicRel("Nd");
  s->addDynamicRel("t");
  d->push(s);
  d->continueRun();
}

