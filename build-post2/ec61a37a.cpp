
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_constb17ef6d19c7a5b1ee83b907c;
u64 v_conste29c9c180c6279b0b02abd6a;
u64 v_const6b86b273ff34fce19d6b804e;
u64 v_const4523540f1504cd17100c4835;
u64 v_constd4735e3a265e16eee03f5971;
u64 v_const4ec9599fc203d176a301536c;
u64 v_const7265b875feb0d1730ead43d3;
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
  slog::Stratum* s = d->beginStratum("ec61a37a");
  if (s == nullptr) return;
  slog::Relation* r;
  v_constb17ef6d19c7a5b1ee83b907c = s32_encode(16);
  v_conste29c9c180c6279b0b02abd6a = s32_encode(32);
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  v_const4523540f1504cd17100c4835 = s32_encode(17);
  v_constd4735e3a265e16eee03f5971 = s32_encode(2);
  v_const4ec9599fc203d176a301536c = s32_encode(18);
  v_const7265b875feb0d1730ead43d3 = db->encodeString("w");
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
  r = db->getRelation("wide");
  if (r == 0) db->addRelation("wide", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("wide");
      std::vector<u16> ord219({0, 1});
    
    r->addIndex<2>(ord219, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("wide"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord220({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord220, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord221({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord221, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord222({1, 2, 0});
    
    r->addIndex<3>(ord222, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord223({0, 1, 2});
    
    r->addIndex<3>(ord223, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord224({1, 2, 0});
    
    r->addIndex<3>(ord224, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord225({0, 1, 2});
    
    r->addIndex<3>(ord225, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord226({1, 2, 3, 0});
    
    r->addIndex<4>(ord226, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord227({0, 1, 2, 3});
    
    r->addIndex<4>(ord227, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("n4");
  if (r == 0) db->addStruct("n4", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("n4");
      std::vector<u16> ord228({2, 1, 0});
    
    r->addIndex<3>(ord228, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 1, 0}, false, b), true);
      std::vector<u16> ord229({0, 1, 2});
    
    r->addIndex<3>(ord229, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("n4"), std::array<u16,3>{2, 1, 0}, b));
  r = db->getRelation("n2");
  if (r == 0) db->addStruct("n2", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("n2");
      std::vector<u16> ord230({2, 1, 0});
    
    r->addIndex<3>(ord230, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 1, 0}, false, b), true);
      std::vector<u16> ord231({0, 2, 1});
    
    r->addIndex<3>(ord231, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 2, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("n2"), std::array<u16,3>{2, 1, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord232({1, 2, 0});
    
    r->addIndex<3>(ord232, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord233({0, 1, 2});
    
    r->addIndex<3>(ord233, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord234({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord234, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord235({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord235, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord236({1, 2, 0});
    
    r->addIndex<3>(ord236, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord237({0, 1, 2});
    
    r->addIndex<3>(ord237, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord238({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord238, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord239({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord239, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("l8");
  if (r == 0) db->addStruct("l8", 9);
  else if (r->getArity() != 9)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("l8");
      std::vector<u16> ord240({1, 2, 3, 4, 5, 6, 7, 8, 0});
    
    r->addIndex<9>(ord240, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{1, 2, 3, 4, 5, 6, 7, 8, 0}, false, b), true);
      std::vector<u16> ord241({0, 1, 2, 3, 4, 5, 6, 7, 8});
    
    r->addIndex<9>(ord241, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{0, 1, 2, 3, 4, 5, 6, 7, 8}, false, b), false);
      std::vector<u16> ord242({1, 2, 3, 4, 5, 6, 7, 8, 0});
    
    r->addIndex<9>(ord242, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<9>(db, r, std::array<u16,9>{1, 2, 3, 4, 5, 6, 7, 8, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<9>(db, db->getRelation("l8"), std::array<u16,9>{1, 2, 3, 4, 5, 6, 7, 8, 0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord243({1, 2, 3, 0});
    
    r->addIndex<4>(ord243, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord244({0, 1, 2, 3});
    
    r->addIndex<4>(ord244, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord245({0});
    
    r->addIndex<1>(ord245, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord246({1, 2, 0});
    
    r->addIndex<3>(ord246, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord247({0, 1, 2});
    
    r->addIndex<3>(ord247, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("corner");
  if (r == 0) db->addRelation("corner", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("corner");
      std::vector<u16> ord248({0, 1});
    
    r->addIndex<2>(ord248, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("corner"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord249({1, 0});
    
    r->addIndex<2>(ord249, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord250({0, 1});
    
    r->addIndex<2>(ord250, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  // (crule (pre (let __tconst3O4u40 const7265b875feb0d1730ead43d3) (let __tconst80ly36 const6b86b273ff34fce19d6b804e) (let __tconst5jtZ35 constd4735e3a265e16eee03f5971) (let __tconst83R834 const4e07408562bedb8b60ce05c1) (let __tconst4Vmv33 const4b227777d4dd1fc61c6f884f) (let __tconst4fQB32 constef2d127de37b942baad06145) (let __tconst40Ez31 conste7f6c011776e8db7cd330b54) (let __tconst7DGk30 const7902699be42c8a8e46fbbb45) (let __tconst1xMG29 const2c624232cdd221771294dfbb) (let __tconst9qC527 const19581e27de7ced00ff1ce50b) (let __tconst9Om326 const4a44dc15364204a80fe80e90) (let __tconst0Q4z25 const4fc82b26aecb47d2868c4efb) (let __tconst6M0p24 const6b51d431df5d7f141cbececc) (let __tconst2nEI23 const3fdba35f04dc8c462986c992) (let __tconst4Ied22 const8527a891e224136950ff32ca) (let __tconst2O9k21 conste629fa6598d732768f7c726b) (let __tconst755B20 constb17ef6d19c7a5b1ee83b907c) (let __tconst1Q3N17 const4523540f1504cd17100c4835) (let __tconst6IXa16 const4ec9599fc203d176a301536c) (let __tconst7vco15 const9400f1b21cb527d7fa3d3eab) (let __tconst02Ns14 constf5ca38f748a1d6eaf726b8a4) (let __tconst81Eh13 const6f4b6612125fb3a0daecd279) (let __tconst7mWH12 const785f3ec7eb32f30b90cd0fcf) (let __tconst5Hgw11 const535fa30d7e25dd8a49f15367) (let __tconst3TCY10 constc2356069e9d1e79ca9243781) (let __tconst7wrk8 constb7a56873cd771f2c446d369b) (let __tconst8h167 const5f9c4ab08cac7457e9111a30) (let __tconst2Zj26 const670671cd97404156226e5079) (let __tconst8Ade5 const59e19706d51d39f66711c265) (let __tconst6Ux94 const35135aaa6cc23891b40cb3f3) (let __tconst1s373 const624b60c58c9d8bfb6ff1886c) (let __tconst7Egh2 consteb1e33e8a81b697b75855af6) (let __tconst8ZZ61 conste29c9c180c6279b0b02abd6a)) (seeded) (body (join l8 (1 2 3 4 5 6 7 8 0) 8 __tconst7wrk8 __tconst8h167 __tconst2Zj26 __tconst8Ade5 __tconst6Ux94 __tconst1s373 __tconst7Egh2 __tconst8ZZ61 __t7tQU9) (exists l8 (1 2 3 4 5 6 7 8 0) 8 __tconst9qC527 __tconst9Om326 __tconst0Q4z25 __tconst6M0p24 __tconst2nEI23 __tconst4Ied22 __tconst2O9k21 __tconst755B20) (exists l8 (1 2 3 4 5 6 7 8 0) 8 __tconst80ly36 __tconst5jtZ35 __tconst83R834 __tconst4Vmv33 __tconst4fQB32 __tconst40Ez31 __tconst7DGk30 __tconst1xMG29) (exists n2 (2 1 0) 1 __t7tQU9) (join l8 (1 2 3 4 5 6 7 8 0) 8 __tconst1Q3N17 __tconst6IXa16 __tconst7vco15 __tconst02Ns14 __tconst81Eh13 __tconst7mWH12 __tconst5Hgw11 __tconst3TCY10 __t1W5d18) (exists n2 (2 1 0) 2 __t7tQU9 __t1W5d18) (join l8 (1 2 3 4 5 6 7 8 0) 8 __tconst9qC527 __tconst9Om326 __tconst0Q4z25 __tconst6M0p24 __tconst2nEI23 __tconst4Ied22 __tconst2O9k21 __tconst755B20 __t91OM28) (exists n2 (2 1 0) 1 __t91OM28) (join l8 (1 2 3 4 5 6 7 8 0) 8 __tconst80ly36 __tconst5jtZ35 __tconst83R834 __tconst4Vmv33 __tconst4fQB32 __tconst40Ez31 __tconst7DGk30 __tconst1xMG29 __t66rT37) (exists n2 (2 1 0) 2 __t91OM28 __t66rT37) (join n2 (2 1 0) 2 __t7tQU9 __t1W5d18 __t2YL419) (exists n4 (2 1 0) 1 __t2YL419) (join n2 (2 1 0) 2 __t91OM28 __t66rT37 __t61f638) (join n4 (2 1 0) 2 __t2YL419 __t61f638 __t7VhN39)) (head (emit wide (0 1) __tconst3O4u40 __t7VhN39)) wide_fact.slog:12 #f)
  class ReadTask14 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** l8index0;  slog::Index** l8index1;  slog::Index** l8index2;  slog::Index** n2index3;  slog::Index** l8index4;  slog::Index** n2index5;  slog::Index** l8index6;  slog::Index** n2index7;  slog::Index** l8index8;  slog::Index** n2index9;  slog::Index** n2index10;  slog::Index** n4index11;  slog::Index** n2index12;  slog::Index** n4index13;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("wide");
      std::vector<u16> ord15({0, 1});
      slog::Relation* readrel16 = db->getRelation("wide");
      head_index[0] = readrel16->getIndex(ord15, false);
      std::vector<u16> ord17({1, 2, 3, 4, 5, 6, 7, 8, 0});
      slog::Relation* readrel18 = db->getRelation("l8");
      l8index0 = readrel18->getIndex(ord17, false);
      std::vector<u16> ord19({1, 2, 3, 4, 5, 6, 7, 8, 0});
      slog::Relation* readrel20 = db->getRelation("l8");
      l8index1 = readrel20->getIndex(ord19, false);
      std::vector<u16> ord21({1, 2, 3, 4, 5, 6, 7, 8, 0});
      slog::Relation* readrel22 = db->getRelation("l8");
      l8index2 = readrel22->getIndex(ord21, false);
      std::vector<u16> ord23({2, 1, 0});
      slog::Relation* readrel24 = db->getRelation("n2");
      n2index3 = readrel24->getIndex(ord23, false);
      std::vector<u16> ord25({1, 2, 3, 4, 5, 6, 7, 8, 0});
      slog::Relation* readrel26 = db->getRelation("l8");
      l8index4 = readrel26->getIndex(ord25, false);
      std::vector<u16> ord27({2, 1, 0});
      slog::Relation* readrel28 = db->getRelation("n2");
      n2index5 = readrel28->getIndex(ord27, false);
      std::vector<u16> ord29({1, 2, 3, 4, 5, 6, 7, 8, 0});
      slog::Relation* readrel30 = db->getRelation("l8");
      l8index6 = readrel30->getIndex(ord29, false);
      std::vector<u16> ord31({2, 1, 0});
      slog::Relation* readrel32 = db->getRelation("n2");
      n2index7 = readrel32->getIndex(ord31, false);
      std::vector<u16> ord33({1, 2, 3, 4, 5, 6, 7, 8, 0});
      slog::Relation* readrel34 = db->getRelation("l8");
      l8index8 = readrel34->getIndex(ord33, false);
      std::vector<u16> ord35({2, 1, 0});
      slog::Relation* readrel36 = db->getRelation("n2");
      n2index9 = readrel36->getIndex(ord35, false);
      std::vector<u16> ord37({2, 1, 0});
      slog::Relation* readrel38 = db->getRelation("n2");
      n2index10 = readrel38->getIndex(ord37, false);
      std::vector<u16> ord39({2, 1, 0});
      slog::Relation* readrel40 = db->getRelation("n4");
      n4index11 = readrel40->getIndex(ord39, false);
      std::vector<u16> ord41({2, 1, 0});
      slog::Relation* readrel42 = db->getRelation("n2");
      n2index12 = readrel42->getIndex(ord41, false);
      std::vector<u16> ord43({2, 1, 0});
      slog::Relation* readrel44 = db->getRelation("n4");
      n4index13 = readrel44->getIndex(ord43, false);
  
    }
    ReadTask14(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const7265b875feb0d1730ead43d3;
      u64 v_c1 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c2 = v_constd4735e3a265e16eee03f5971;
      u64 v_c3 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c4 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c5 = v_constef2d127de37b942baad06145;
      u64 v_c6 = v_conste7f6c011776e8db7cd330b54;
      u64 v_c7 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c8 = v_const2c624232cdd221771294dfbb;
      u64 v_c9 = v_const19581e27de7ced00ff1ce50b;
      u64 v_c10 = v_const4a44dc15364204a80fe80e90;
      u64 v_c11 = v_const4fc82b26aecb47d2868c4efb;
      u64 v_c12 = v_const6b51d431df5d7f141cbececc;
      u64 v_c13 = v_const3fdba35f04dc8c462986c992;
      u64 v_c14 = v_const8527a891e224136950ff32ca;
      u64 v_c15 = v_conste629fa6598d732768f7c726b;
      u64 v_c16 = v_constb17ef6d19c7a5b1ee83b907c;
      u64 v_c17 = v_const4523540f1504cd17100c4835;
      u64 v_c18 = v_const4ec9599fc203d176a301536c;
      u64 v_c19 = v_const9400f1b21cb527d7fa3d3eab;
      u64 v_c20 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c21 = v_const6f4b6612125fb3a0daecd279;
      u64 v_c22 = v_const785f3ec7eb32f30b90cd0fcf;
      u64 v_c23 = v_const535fa30d7e25dd8a49f15367;
      u64 v_c24 = v_constc2356069e9d1e79ca9243781;
      u64 v_c25 = v_constb7a56873cd771f2c446d369b;
      u64 v_c26 = v_const5f9c4ab08cac7457e9111a30;
      u64 v_c27 = v_const670671cd97404156226e5079;
      u64 v_c28 = v_const59e19706d51d39f66711c265;
      u64 v_c29 = v_const35135aaa6cc23891b40cb3f3;
      u64 v_c30 = v_const624b60c58c9d8bfb6ff1886c;
      u64 v_c31 = v_consteb1e33e8a81b697b75855af6;
      u64 v_c32 = v_conste29c9c180c6279b0b02abd6a;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<9,8>(l8index0, std::array<u64,9>{v_c25, v_c26, v_c27, v_c28, v_c29, v_c30, v_c31, v_c32, 0}, [&](const std::array<u64,9>& m45) {
        u64 v_c33 = m45[8];
        if (!slog::exists_probe<9,8>(l8index1, std::array<u64,9>{v_c9, v_c10, v_c11, v_c12, v_c13, v_c14, v_c15, v_c16, 0})) return;
        if (!slog::exists_probe<9,8>(l8index2, std::array<u64,9>{v_c1, v_c2, v_c3, v_c4, v_c5, v_c6, v_c7, v_c8, 0})) return;
        if (!slog::exists_probe<3,1>(n2index3, std::array<u64,3>{v_c33, 0, 0})) return;
        slog::join_probe<9,8>(l8index4, std::array<u64,9>{v_c17, v_c18, v_c19, v_c20, v_c21, v_c22, v_c23, v_c24, 0}, [&](const std::array<u64,9>& m46) {
          u64 v_c34 = m46[8];
          if (!slog::exists_probe<3,2>(n2index5, std::array<u64,3>{v_c33, v_c34, 0})) return;
          slog::join_probe<9,8>(l8index6, std::array<u64,9>{v_c9, v_c10, v_c11, v_c12, v_c13, v_c14, v_c15, v_c16, 0}, [&](const std::array<u64,9>& m47) {
            u64 v_c35 = m47[8];
            if (!slog::exists_probe<3,1>(n2index7, std::array<u64,3>{v_c35, 0, 0})) return;
            slog::join_probe<9,8>(l8index8, std::array<u64,9>{v_c1, v_c2, v_c3, v_c4, v_c5, v_c6, v_c7, v_c8, 0}, [&](const std::array<u64,9>& m48) {
              u64 v_c36 = m48[8];
              if (!slog::exists_probe<3,2>(n2index9, std::array<u64,3>{v_c35, v_c36, 0})) return;
              slog::join_probe<3,2>(n2index10, std::array<u64,3>{v_c33, v_c34, 0}, [&](const std::array<u64,3>& m49) {
                u64 v_c37 = m49[2];
                if (!slog::exists_probe<3,1>(n4index11, std::array<u64,3>{v_c37, 0, 0})) return;
                slog::join_probe<3,2>(n2index12, std::array<u64,3>{v_c35, v_c36, 0}, [&](const std::array<u64,3>& m50) {
                  u64 v_c38 = m50[2];
                  slog::join_probe<3,2>(n4index13, std::array<u64,3>{v_c37, v_c38, 0}, [&](const std::array<u64,3>& m51) {
                    u64 v_c39 = m51[2];
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c0, v_c39}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("wide_fact.slog:12", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask14(db,b));
  // (crule (pre (let __tconst3O4u40 const7265b875feb0d1730ead43d3) (let __tconst80ly36 const6b86b273ff34fce19d6b804e) (let __tconst5jtZ35 constd4735e3a265e16eee03f5971) (let __tconst83R834 const4e07408562bedb8b60ce05c1) (let __tconst4Vmv33 const4b227777d4dd1fc61c6f884f) (let __tconst4fQB32 constef2d127de37b942baad06145) (let __tconst40Ez31 conste7f6c011776e8db7cd330b54) (let __tconst7DGk30 const7902699be42c8a8e46fbbb45) (let __tconst1xMG29 const2c624232cdd221771294dfbb) (let __tconst9qC527 const19581e27de7ced00ff1ce50b) (let __tconst9Om326 const4a44dc15364204a80fe80e90) (let __tconst0Q4z25 const4fc82b26aecb47d2868c4efb) (let __tconst6M0p24 const6b51d431df5d7f141cbececc) (let __tconst2nEI23 const3fdba35f04dc8c462986c992) (let __tconst4Ied22 const8527a891e224136950ff32ca) (let __tconst2O9k21 conste629fa6598d732768f7c726b) (let __tconst755B20 constb17ef6d19c7a5b1ee83b907c) (let __tconst1Q3N17 const4523540f1504cd17100c4835) (let __tconst6IXa16 const4ec9599fc203d176a301536c) (let __tconst7vco15 const9400f1b21cb527d7fa3d3eab) (let __tconst02Ns14 constf5ca38f748a1d6eaf726b8a4) (let __tconst81Eh13 const6f4b6612125fb3a0daecd279) (let __tconst7mWH12 const785f3ec7eb32f30b90cd0fcf) (let __tconst5Hgw11 const535fa30d7e25dd8a49f15367) (let __tconst3TCY10 constc2356069e9d1e79ca9243781) (let __tconst7wrk8 constb7a56873cd771f2c446d369b) (let __tconst8h167 const5f9c4ab08cac7457e9111a30) (let __tconst2Zj26 const670671cd97404156226e5079) (let __tconst8Ade5 const59e19706d51d39f66711c265) (let __tconst6Ux94 const35135aaa6cc23891b40cb3f3) (let __tconst1s373 const624b60c58c9d8bfb6ff1886c) (let __tconst7Egh2 consteb1e33e8a81b697b75855af6) (let __tconst8ZZ61 conste29c9c180c6279b0b02abd6a)) (once) (body) (head (mkstruct l8 (1 2 3 4 5 6 7 8 0) __t66rT37 __tconst80ly36 __tconst5jtZ35 __tconst83R834 __tconst4Vmv33 __tconst4fQB32 __tconst40Ez31 __tconst7DGk30 __tconst1xMG29) (mkstruct l8 (1 2 3 4 5 6 7 8 0) __t91OM28 __tconst9qC527 __tconst9Om326 __tconst0Q4z25 __tconst6M0p24 __tconst2nEI23 __tconst4Ied22 __tconst2O9k21 __tconst755B20) (mkstruct l8 (1 2 3 4 5 6 7 8 0) __t1W5d18 __tconst1Q3N17 __tconst6IXa16 __tconst7vco15 __tconst02Ns14 __tconst81Eh13 __tconst7mWH12 __tconst5Hgw11 __tconst3TCY10) (mkstruct l8 (1 2 3 4 5 6 7 8 0) __t7tQU9 __tconst7wrk8 __tconst8h167 __tconst2Zj26 __tconst8Ade5 __tconst6Ux94 __tconst1s373 __tconst7Egh2 __tconst8ZZ61)) wide_fact.slog:12 #f)
  class ReadTask52 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[4];
    slog::Index** head_index[4];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("l8");
      head_rel[1] = db->getRelation("l8");
      head_rel[2] = db->getRelation("l8");
      head_rel[3] = db->getRelation("l8");
  
    }
    ReadTask52(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const7265b875feb0d1730ead43d3;
      u64 v_c1 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c2 = v_constd4735e3a265e16eee03f5971;
      u64 v_c3 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c4 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c5 = v_constef2d127de37b942baad06145;
      u64 v_c6 = v_conste7f6c011776e8db7cd330b54;
      u64 v_c7 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c8 = v_const2c624232cdd221771294dfbb;
      u64 v_c9 = v_const19581e27de7ced00ff1ce50b;
      u64 v_c10 = v_const4a44dc15364204a80fe80e90;
      u64 v_c11 = v_const4fc82b26aecb47d2868c4efb;
      u64 v_c12 = v_const6b51d431df5d7f141cbececc;
      u64 v_c13 = v_const3fdba35f04dc8c462986c992;
      u64 v_c14 = v_const8527a891e224136950ff32ca;
      u64 v_c15 = v_conste629fa6598d732768f7c726b;
      u64 v_c16 = v_constb17ef6d19c7a5b1ee83b907c;
      u64 v_c17 = v_const4523540f1504cd17100c4835;
      u64 v_c18 = v_const4ec9599fc203d176a301536c;
      u64 v_c19 = v_const9400f1b21cb527d7fa3d3eab;
      u64 v_c20 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c21 = v_const6f4b6612125fb3a0daecd279;
      u64 v_c22 = v_const785f3ec7eb32f30b90cd0fcf;
      u64 v_c23 = v_const535fa30d7e25dd8a49f15367;
      u64 v_c24 = v_constc2356069e9d1e79ca9243781;
      u64 v_c25 = v_constb7a56873cd771f2c446d369b;
      u64 v_c26 = v_const5f9c4ab08cac7457e9111a30;
      u64 v_c27 = v_const670671cd97404156226e5079;
      u64 v_c28 = v_const59e19706d51d39f66711c265;
      u64 v_c29 = v_const35135aaa6cc23891b40cb3f3;
      u64 v_c30 = v_const624b60c58c9d8bfb6ff1886c;
      u64 v_c31 = v_consteb1e33e8a81b697b75855af6;
      u64 v_c32 = v_conste29c9c180c6279b0b02abd6a;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[4];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<9>(head_rel[0], newbatch[0], std::array<u64,8>{v_c1, v_c2, v_c3, v_c4, v_c5, v_c6, v_c7, v_c8}, std::array<u16,9>{1, 2, 3, 4, 5, 6, 7, 8, 0});
      slog::emit_struct<9>(head_rel[1], newbatch[1], std::array<u64,8>{v_c9, v_c10, v_c11, v_c12, v_c13, v_c14, v_c15, v_c16}, std::array<u16,9>{1, 2, 3, 4, 5, 6, 7, 8, 0});
      slog::emit_struct<9>(head_rel[2], newbatch[2], std::array<u64,8>{v_c17, v_c18, v_c19, v_c20, v_c21, v_c22, v_c23, v_c24}, std::array<u16,9>{1, 2, 3, 4, 5, 6, 7, 8, 0});
      slog::emit_struct<9>(head_rel[3], newbatch[3], std::array<u64,8>{v_c25, v_c26, v_c27, v_c28, v_c29, v_c30, v_c31, v_c32}, std::array<u16,9>{1, 2, 3, 4, 5, 6, 7, 8, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
  
      if (_fires) db->bumpFires("wide_fact.slog:12", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask52(db,b), true);
  // (crule (pre (let __tconst3O4u40 const7265b875feb0d1730ead43d3) (let __tconst80ly36 const6b86b273ff34fce19d6b804e) (let __tconst5jtZ35 constd4735e3a265e16eee03f5971) (let __tconst83R834 const4e07408562bedb8b60ce05c1) (let __tconst4Vmv33 const4b227777d4dd1fc61c6f884f) (let __tconst4fQB32 constef2d127de37b942baad06145) (let __tconst40Ez31 conste7f6c011776e8db7cd330b54) (let __tconst7DGk30 const7902699be42c8a8e46fbbb45) (let __tconst1xMG29 const2c624232cdd221771294dfbb) (let __tconst9qC527 const19581e27de7ced00ff1ce50b) (let __tconst9Om326 const4a44dc15364204a80fe80e90) (let __tconst0Q4z25 const4fc82b26aecb47d2868c4efb) (let __tconst6M0p24 const6b51d431df5d7f141cbececc) (let __tconst2nEI23 const3fdba35f04dc8c462986c992) (let __tconst4Ied22 const8527a891e224136950ff32ca) (let __tconst2O9k21 conste629fa6598d732768f7c726b) (let __tconst755B20 constb17ef6d19c7a5b1ee83b907c) (let __tconst1Q3N17 const4523540f1504cd17100c4835) (let __tconst6IXa16 const4ec9599fc203d176a301536c) (let __tconst7vco15 const9400f1b21cb527d7fa3d3eab) (let __tconst02Ns14 constf5ca38f748a1d6eaf726b8a4) (let __tconst81Eh13 const6f4b6612125fb3a0daecd279) (let __tconst7mWH12 const785f3ec7eb32f30b90cd0fcf) (let __tconst5Hgw11 const535fa30d7e25dd8a49f15367) (let __tconst3TCY10 constc2356069e9d1e79ca9243781) (let __tconst7wrk8 constb7a56873cd771f2c446d369b) (let __tconst8h167 const5f9c4ab08cac7457e9111a30) (let __tconst2Zj26 const670671cd97404156226e5079) (let __tconst8Ade5 const59e19706d51d39f66711c265) (let __tconst6Ux94 const35135aaa6cc23891b40cb3f3) (let __tconst1s373 const624b60c58c9d8bfb6ff1886c) (let __tconst7Egh2 consteb1e33e8a81b697b75855af6) (let __tconst8ZZ61 conste29c9c180c6279b0b02abd6a)) (probe l8 (1 2 3 4 5 6 7 8 0) 8 __tconst7wrk8 __tconst8h167 __tconst2Zj26 __tconst8Ade5 __tconst6Ux94 __tconst1s373 __tconst7Egh2 __tconst8ZZ61 __t7tQU9) (body (exists l8 (1 2 3 4 5 6 7 8 0) 8 __tconst9qC527 __tconst9Om326 __tconst0Q4z25 __tconst6M0p24 __tconst2nEI23 __tconst4Ied22 __tconst2O9k21 __tconst755B20) (exists l8 (1 2 3 4 5 6 7 8 0) 8 __tconst80ly36 __tconst5jtZ35 __tconst83R834 __tconst4Vmv33 __tconst4fQB32 __tconst40Ez31 __tconst7DGk30 __tconst1xMG29) (join l8 (1 2 3 4 5 6 7 8 0) 8 __tconst1Q3N17 __tconst6IXa16 __tconst7vco15 __tconst02Ns14 __tconst81Eh13 __tconst7mWH12 __tconst5Hgw11 __tconst3TCY10 __t1W5d18) (join l8 (1 2 3 4 5 6 7 8 0) 8 __tconst9qC527 __tconst9Om326 __tconst0Q4z25 __tconst6M0p24 __tconst2nEI23 __tconst4Ied22 __tconst2O9k21 __tconst755B20 __t91OM28) (join l8 (1 2 3 4 5 6 7 8 0) 8 __tconst80ly36 __tconst5jtZ35 __tconst83R834 __tconst4Vmv33 __tconst4fQB32 __tconst40Ez31 __tconst7DGk30 __tconst1xMG29 __t66rT37)) (head (mkstruct n2 (2 1 0) __t61f638 __t91OM28 __t66rT37) (mkstruct n2 (2 1 0) __t2YL419 __t7tQU9 __t1W5d18)) wide_fact.slog:12 #f)
  class ReadTask58 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,9> resume_key{};
    bool has_resume = false;
    slog::Index** l8index53;  slog::Index** l8index54;  slog::Index** l8index55;  slog::Index** l8index56;  slog::Index** l8index57;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("n2");
      head_rel[1] = db->getRelation("n2");
      std::vector<u16> ord59({1, 2, 3, 4, 5, 6, 7, 8, 0});
      slog::Relation* readrel60 = db->getRelation("l8");
      driver_index = readrel60->getIndex(ord59, true);
      std::vector<u16> ord61({1, 2, 3, 4, 5, 6, 7, 8, 0});
      slog::Relation* readrel62 = db->getRelation("l8");
      l8index53 = readrel62->getIndex(ord61, false);
      std::vector<u16> ord63({1, 2, 3, 4, 5, 6, 7, 8, 0});
      slog::Relation* readrel64 = db->getRelation("l8");
      l8index54 = readrel64->getIndex(ord63, false);
      std::vector<u16> ord65({1, 2, 3, 4, 5, 6, 7, 8, 0});
      slog::Relation* readrel66 = db->getRelation("l8");
      l8index55 = readrel66->getIndex(ord65, false);
      std::vector<u16> ord67({1, 2, 3, 4, 5, 6, 7, 8, 0});
      slog::Relation* readrel68 = db->getRelation("l8");
      l8index56 = readrel68->getIndex(ord67, false);
      std::vector<u16> ord69({1, 2, 3, 4, 5, 6, 7, 8, 0});
      slog::Relation* readrel70 = db->getRelation("l8");
      l8index57 = readrel70->getIndex(ord69, false);
  
    }
    ReadTask58(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const7265b875feb0d1730ead43d3;
      u64 v_c1 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c2 = v_constd4735e3a265e16eee03f5971;
      u64 v_c3 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c4 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c5 = v_constef2d127de37b942baad06145;
      u64 v_c6 = v_conste7f6c011776e8db7cd330b54;
      u64 v_c7 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c8 = v_const2c624232cdd221771294dfbb;
      u64 v_c9 = v_const19581e27de7ced00ff1ce50b;
      u64 v_c10 = v_const4a44dc15364204a80fe80e90;
      u64 v_c11 = v_const4fc82b26aecb47d2868c4efb;
      u64 v_c12 = v_const6b51d431df5d7f141cbececc;
      u64 v_c13 = v_const3fdba35f04dc8c462986c992;
      u64 v_c14 = v_const8527a891e224136950ff32ca;
      u64 v_c15 = v_conste629fa6598d732768f7c726b;
      u64 v_c16 = v_constb17ef6d19c7a5b1ee83b907c;
      u64 v_c17 = v_const4523540f1504cd17100c4835;
      u64 v_c18 = v_const4ec9599fc203d176a301536c;
      u64 v_c19 = v_const9400f1b21cb527d7fa3d3eab;
      u64 v_c20 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c21 = v_const6f4b6612125fb3a0daecd279;
      u64 v_c22 = v_const785f3ec7eb32f30b90cd0fcf;
      u64 v_c23 = v_const535fa30d7e25dd8a49f15367;
      u64 v_c24 = v_constc2356069e9d1e79ca9243781;
      u64 v_c25 = v_constb7a56873cd771f2c446d369b;
      u64 v_c26 = v_const5f9c4ab08cac7457e9111a30;
      u64 v_c27 = v_const670671cd97404156226e5079;
      u64 v_c28 = v_const59e19706d51d39f66711c265;
      u64 v_c29 = v_const35135aaa6cc23891b40cb3f3;
      u64 v_c30 = v_const624b60c58c9d8bfb6ff1886c;
      u64 v_c31 = v_consteb1e33e8a81b697b75855af6;
      u64 v_c32 = v_conste29c9c180c6279b0b02abd6a;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,9> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<9,8>(driver_index, std::array<u64,9>{v_c25, v_c26, v_c27, v_c28, v_c29, v_c30, v_c31, v_c32, 0}, _sc, _rkey, _hr, [&](const std::array<u64,9>& m71) {
        u64 v_c33 = m71[8];
        if (buckethash(v_c33) != bucket) return;
        if (!slog::exists_probe<9,8>(l8index53, std::array<u64,9>{v_c9, v_c10, v_c11, v_c12, v_c13, v_c14, v_c15, v_c16, 0})) return;
        if (!slog::exists_probe<9,8>(l8index54, std::array<u64,9>{v_c1, v_c2, v_c3, v_c4, v_c5, v_c6, v_c7, v_c8, 0})) return;
        slog::join_probe<9,8>(l8index55, std::array<u64,9>{v_c17, v_c18, v_c19, v_c20, v_c21, v_c22, v_c23, v_c24, 0}, [&](const std::array<u64,9>& m72) {
          u64 v_c34 = m72[8];
          slog::join_probe<9,8>(l8index56, std::array<u64,9>{v_c9, v_c10, v_c11, v_c12, v_c13, v_c14, v_c15, v_c16, 0}, [&](const std::array<u64,9>& m73) {
            u64 v_c35 = m73[8];
            slog::join_probe<9,8>(l8index57, std::array<u64,9>{v_c1, v_c2, v_c3, v_c4, v_c5, v_c6, v_c7, v_c8, 0}, [&](const std::array<u64,9>& m74) {
              u64 v_c36 = m74[8];
              ++_fires;
              slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c35, v_c36}, std::array<u16,3>{2, 1, 0});
              slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c33, v_c34}, std::array<u16,3>{2, 1, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("wide_fact.slog:12", "delta:l8", _fires);
  
      if (!_done)
      {
        ReadTask58* _cont = new ReadTask58(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask58(db,b), false);
  // (crule (pre (let __tconst3O4u40 const7265b875feb0d1730ead43d3) (let __tconst80ly36 const6b86b273ff34fce19d6b804e) (let __tconst5jtZ35 constd4735e3a265e16eee03f5971) (let __tconst83R834 const4e07408562bedb8b60ce05c1) (let __tconst4Vmv33 const4b227777d4dd1fc61c6f884f) (let __tconst4fQB32 constef2d127de37b942baad06145) (let __tconst40Ez31 conste7f6c011776e8db7cd330b54) (let __tconst7DGk30 const7902699be42c8a8e46fbbb45) (let __tconst1xMG29 const2c624232cdd221771294dfbb) (let __tconst9qC527 const19581e27de7ced00ff1ce50b) (let __tconst9Om326 const4a44dc15364204a80fe80e90) (let __tconst0Q4z25 const4fc82b26aecb47d2868c4efb) (let __tconst6M0p24 const6b51d431df5d7f141cbececc) (let __tconst2nEI23 const3fdba35f04dc8c462986c992) (let __tconst4Ied22 const8527a891e224136950ff32ca) (let __tconst2O9k21 conste629fa6598d732768f7c726b) (let __tconst755B20 constb17ef6d19c7a5b1ee83b907c) (let __tconst1Q3N17 const4523540f1504cd17100c4835) (let __tconst6IXa16 const4ec9599fc203d176a301536c) (let __tconst7vco15 const9400f1b21cb527d7fa3d3eab) (let __tconst02Ns14 constf5ca38f748a1d6eaf726b8a4) (let __tconst81Eh13 const6f4b6612125fb3a0daecd279) (let __tconst7mWH12 const785f3ec7eb32f30b90cd0fcf) (let __tconst5Hgw11 const535fa30d7e25dd8a49f15367) (let __tconst3TCY10 constc2356069e9d1e79ca9243781) (let __tconst7wrk8 constb7a56873cd771f2c446d369b) (let __tconst8h167 const5f9c4ab08cac7457e9111a30) (let __tconst2Zj26 const670671cd97404156226e5079) (let __tconst8Ade5 const59e19706d51d39f66711c265) (let __tconst6Ux94 const35135aaa6cc23891b40cb3f3) (let __tconst1s373 const624b60c58c9d8bfb6ff1886c) (let __tconst7Egh2 consteb1e33e8a81b697b75855af6) (let __tconst8ZZ61 conste29c9c180c6279b0b02abd6a)) (scan n4 __t7VhN39 __t61f638 __t2YL419) (body (exists l8 (1 2 3 4 5 6 7 8 0) 8 __tconst1Q3N17 __tconst6IXa16 __tconst7vco15 __tconst02Ns14 __tconst81Eh13 __tconst7mWH12 __tconst5Hgw11 __tconst3TCY10) (exists l8 (1 2 3 4 5 6 7 8 0) 8 __tconst9qC527 __tconst9Om326 __tconst0Q4z25 __tconst6M0p24 __tconst2nEI23 __tconst4Ied22 __tconst2O9k21 __tconst755B20) (exists l8 (1 2 3 4 5 6 7 8 0) 8 __tconst80ly36 __tconst5jtZ35 __tconst83R834 __tconst4Vmv33 __tconst4fQB32 __tconst40Ez31 __tconst7DGk30 __tconst1xMG29) (join l8 (1 2 3 4 5 6 7 8 0) 8 __tconst7wrk8 __tconst8h167 __tconst2Zj26 __tconst8Ade5 __tconst6Ux94 __tconst1s373 __tconst7Egh2 __tconst8ZZ61 __t7tQU9) (exists n2 (0 2 1) 2 __t2YL419 __t7tQU9) (join l8 (1 2 3 4 5 6 7 8 0) 8 __tconst1Q3N17 __tconst6IXa16 __tconst7vco15 __tconst02Ns14 __tconst81Eh13 __tconst7mWH12 __tconst5Hgw11 __tconst3TCY10 __t1W5d18) (exists n2 (0 2 1) 3 __t2YL419 __t7tQU9 __t1W5d18) (join l8 (1 2 3 4 5 6 7 8 0) 8 __tconst9qC527 __tconst9Om326 __tconst0Q4z25 __tconst6M0p24 __tconst2nEI23 __tconst4Ied22 __tconst2O9k21 __tconst755B20 __t91OM28) (exists n2 (0 2 1) 2 __t61f638 __t91OM28) (join l8 (1 2 3 4 5 6 7 8 0) 8 __tconst80ly36 __tconst5jtZ35 __tconst83R834 __tconst4Vmv33 __tconst4fQB32 __tconst40Ez31 __tconst7DGk30 __tconst1xMG29 __t66rT37) (join n2 (0 2 1) 3 __t2YL419 __t7tQU9 __t1W5d18) (join n2 (0 2 1) 3 __t61f638 __t91OM28 __t66rT37)) (head (emit wide (0 1) __tconst3O4u40 __t7VhN39)) wide_fact.slog:12 #f)
  class ReadTask87 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** l8index75;  slog::Index** l8index76;  slog::Index** l8index77;  slog::Index** l8index78;  slog::Index** n2index79;  slog::Index** l8index80;  slog::Index** n2index81;  slog::Index** l8index82;  slog::Index** n2index83;  slog::Index** l8index84;  slog::Index** n2index85;  slog::Index** n2index86;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("wide");
      std::vector<u16> ord88({0, 1});
      slog::Relation* readrel89 = db->getRelation("wide");
      head_index[0] = readrel89->getIndex(ord88, false);
      outer_rel = db->getRelation("n4");
      std::vector<u16> ord90({1, 2, 3, 4, 5, 6, 7, 8, 0});
      slog::Relation* readrel91 = db->getRelation("l8");
      l8index75 = readrel91->getIndex(ord90, false);
      std::vector<u16> ord92({1, 2, 3, 4, 5, 6, 7, 8, 0});
      slog::Relation* readrel93 = db->getRelation("l8");
      l8index76 = readrel93->getIndex(ord92, false);
      std::vector<u16> ord94({1, 2, 3, 4, 5, 6, 7, 8, 0});
      slog::Relation* readrel95 = db->getRelation("l8");
      l8index77 = readrel95->getIndex(ord94, false);
      std::vector<u16> ord96({1, 2, 3, 4, 5, 6, 7, 8, 0});
      slog::Relation* readrel97 = db->getRelation("l8");
      l8index78 = readrel97->getIndex(ord96, false);
      std::vector<u16> ord98({0, 2, 1});
      slog::Relation* readrel99 = db->getRelation("n2");
      n2index79 = readrel99->getIndex(ord98, false);
      std::vector<u16> ord100({1, 2, 3, 4, 5, 6, 7, 8, 0});
      slog::Relation* readrel101 = db->getRelation("l8");
      l8index80 = readrel101->getIndex(ord100, false);
      std::vector<u16> ord102({0, 2, 1});
      slog::Relation* readrel103 = db->getRelation("n2");
      n2index81 = readrel103->getIndex(ord102, false);
      std::vector<u16> ord104({1, 2, 3, 4, 5, 6, 7, 8, 0});
      slog::Relation* readrel105 = db->getRelation("l8");
      l8index82 = readrel105->getIndex(ord104, false);
      std::vector<u16> ord106({0, 2, 1});
      slog::Relation* readrel107 = db->getRelation("n2");
      n2index83 = readrel107->getIndex(ord106, false);
      std::vector<u16> ord108({1, 2, 3, 4, 5, 6, 7, 8, 0});
      slog::Relation* readrel109 = db->getRelation("l8");
      l8index84 = readrel109->getIndex(ord108, false);
      std::vector<u16> ord110({0, 2, 1});
      slog::Relation* readrel111 = db->getRelation("n2");
      n2index85 = readrel111->getIndex(ord110, false);
      std::vector<u16> ord112({0, 2, 1});
      slog::Relation* readrel113 = db->getRelation("n2");
      n2index86 = readrel113->getIndex(ord112, false);
  
    }
    ReadTask87(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const7265b875feb0d1730ead43d3;
      u64 v_c1 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c2 = v_constd4735e3a265e16eee03f5971;
      u64 v_c3 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c4 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c5 = v_constef2d127de37b942baad06145;
      u64 v_c6 = v_conste7f6c011776e8db7cd330b54;
      u64 v_c7 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c8 = v_const2c624232cdd221771294dfbb;
      u64 v_c9 = v_const19581e27de7ced00ff1ce50b;
      u64 v_c10 = v_const4a44dc15364204a80fe80e90;
      u64 v_c11 = v_const4fc82b26aecb47d2868c4efb;
      u64 v_c12 = v_const6b51d431df5d7f141cbececc;
      u64 v_c13 = v_const3fdba35f04dc8c462986c992;
      u64 v_c14 = v_const8527a891e224136950ff32ca;
      u64 v_c15 = v_conste629fa6598d732768f7c726b;
      u64 v_c16 = v_constb17ef6d19c7a5b1ee83b907c;
      u64 v_c17 = v_const4523540f1504cd17100c4835;
      u64 v_c18 = v_const4ec9599fc203d176a301536c;
      u64 v_c19 = v_const9400f1b21cb527d7fa3d3eab;
      u64 v_c20 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c21 = v_const6f4b6612125fb3a0daecd279;
      u64 v_c22 = v_const785f3ec7eb32f30b90cd0fcf;
      u64 v_c23 = v_const535fa30d7e25dd8a49f15367;
      u64 v_c24 = v_constc2356069e9d1e79ca9243781;
      u64 v_c25 = v_constb7a56873cd771f2c446d369b;
      u64 v_c26 = v_const5f9c4ab08cac7457e9111a30;
      u64 v_c27 = v_const670671cd97404156226e5079;
      u64 v_c28 = v_const59e19706d51d39f66711c265;
      u64 v_c29 = v_const35135aaa6cc23891b40cb3f3;
      u64 v_c30 = v_const624b60c58c9d8bfb6ff1886c;
      u64 v_c31 = v_consteb1e33e8a81b697b75855af6;
      u64 v_c32 = v_conste29c9c180c6279b0b02abd6a;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c39 = _t[0];
        u64 v_c38 = _t[1];
        u64 v_c37 = _t[2];
        if (!slog::exists_probe<9,8>(l8index75, std::array<u64,9>{v_c17, v_c18, v_c19, v_c20, v_c21, v_c22, v_c23, v_c24, 0})) return;
        if (!slog::exists_probe<9,8>(l8index76, std::array<u64,9>{v_c9, v_c10, v_c11, v_c12, v_c13, v_c14, v_c15, v_c16, 0})) return;
        if (!slog::exists_probe<9,8>(l8index77, std::array<u64,9>{v_c1, v_c2, v_c3, v_c4, v_c5, v_c6, v_c7, v_c8, 0})) return;
        slog::join_probe<9,8>(l8index78, std::array<u64,9>{v_c25, v_c26, v_c27, v_c28, v_c29, v_c30, v_c31, v_c32, 0}, [&](const std::array<u64,9>& m114) {
          u64 v_c33 = m114[8];
          if (!slog::exists_probe<3,2>(n2index79, std::array<u64,3>{v_c37, v_c33, 0})) return;
          slog::join_probe<9,8>(l8index80, std::array<u64,9>{v_c17, v_c18, v_c19, v_c20, v_c21, v_c22, v_c23, v_c24, 0}, [&](const std::array<u64,9>& m115) {
            u64 v_c34 = m115[8];
            if (!slog::exists_probe<3,3>(n2index81, std::array<u64,3>{v_c37, v_c33, v_c34})) return;
            slog::join_probe<9,8>(l8index82, std::array<u64,9>{v_c9, v_c10, v_c11, v_c12, v_c13, v_c14, v_c15, v_c16, 0}, [&](const std::array<u64,9>& m116) {
              u64 v_c35 = m116[8];
              if (!slog::exists_probe<3,2>(n2index83, std::array<u64,3>{v_c38, v_c35, 0})) return;
              slog::join_probe<9,8>(l8index84, std::array<u64,9>{v_c1, v_c2, v_c3, v_c4, v_c5, v_c6, v_c7, v_c8, 0}, [&](const std::array<u64,9>& m117) {
                u64 v_c36 = m117[8];
                slog::join_probe<3,3>(n2index85, std::array<u64,3>{v_c37, v_c33, v_c34}, [&](const std::array<u64,3>& m118) {
                  slog::join_probe<3,3>(n2index86, std::array<u64,3>{v_c38, v_c35, v_c36}, [&](const std::array<u64,3>& m119) {
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c0, v_c39}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("wide_fact.slog:12", "delta:n4", _fires);
  
      if (!_done)
      {
        ReadTask87* _cont = new ReadTask87(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask87(db,b), false);
  // (crule (pre (let __tconst3O4u40 const7265b875feb0d1730ead43d3) (let __tconst80ly36 const6b86b273ff34fce19d6b804e) (let __tconst5jtZ35 constd4735e3a265e16eee03f5971) (let __tconst83R834 const4e07408562bedb8b60ce05c1) (let __tconst4Vmv33 const4b227777d4dd1fc61c6f884f) (let __tconst4fQB32 constef2d127de37b942baad06145) (let __tconst40Ez31 conste7f6c011776e8db7cd330b54) (let __tconst7DGk30 const7902699be42c8a8e46fbbb45) (let __tconst1xMG29 const2c624232cdd221771294dfbb) (let __tconst9qC527 const19581e27de7ced00ff1ce50b) (let __tconst9Om326 const4a44dc15364204a80fe80e90) (let __tconst0Q4z25 const4fc82b26aecb47d2868c4efb) (let __tconst6M0p24 const6b51d431df5d7f141cbececc) (let __tconst2nEI23 const3fdba35f04dc8c462986c992) (let __tconst4Ied22 const8527a891e224136950ff32ca) (let __tconst2O9k21 conste629fa6598d732768f7c726b) (let __tconst755B20 constb17ef6d19c7a5b1ee83b907c) (let __tconst1Q3N17 const4523540f1504cd17100c4835) (let __tconst6IXa16 const4ec9599fc203d176a301536c) (let __tconst7vco15 const9400f1b21cb527d7fa3d3eab) (let __tconst02Ns14 constf5ca38f748a1d6eaf726b8a4) (let __tconst81Eh13 const6f4b6612125fb3a0daecd279) (let __tconst7mWH12 const785f3ec7eb32f30b90cd0fcf) (let __tconst5Hgw11 const535fa30d7e25dd8a49f15367) (let __tconst3TCY10 constc2356069e9d1e79ca9243781) (let __tconst7wrk8 constb7a56873cd771f2c446d369b) (let __tconst8h167 const5f9c4ab08cac7457e9111a30) (let __tconst2Zj26 const670671cd97404156226e5079) (let __tconst8Ade5 const59e19706d51d39f66711c265) (let __tconst6Ux94 const35135aaa6cc23891b40cb3f3) (let __tconst1s373 const624b60c58c9d8bfb6ff1886c) (let __tconst7Egh2 consteb1e33e8a81b697b75855af6) (let __tconst8ZZ61 conste29c9c180c6279b0b02abd6a)) (seeded) (body (join l8 (1 2 3 4 5 6 7 8 0) 8 __tconst7wrk8 __tconst8h167 __tconst2Zj26 __tconst8Ade5 __tconst6Ux94 __tconst1s373 __tconst7Egh2 __tconst8ZZ61 __t7tQU9) (exists l8 (1 2 3 4 5 6 7 8 0) 8 __tconst9qC527 __tconst9Om326 __tconst0Q4z25 __tconst6M0p24 __tconst2nEI23 __tconst4Ied22 __tconst2O9k21 __tconst755B20) (exists l8 (1 2 3 4 5 6 7 8 0) 8 __tconst80ly36 __tconst5jtZ35 __tconst83R834 __tconst4Vmv33 __tconst4fQB32 __tconst40Ez31 __tconst7DGk30 __tconst1xMG29) (exists n2 (2 1 0) 1 __t7tQU9) (join l8 (1 2 3 4 5 6 7 8 0) 8 __tconst1Q3N17 __tconst6IXa16 __tconst7vco15 __tconst02Ns14 __tconst81Eh13 __tconst7mWH12 __tconst5Hgw11 __tconst3TCY10 __t1W5d18) (exists n2 (2 1 0) 2 __t7tQU9 __t1W5d18) (join l8 (1 2 3 4 5 6 7 8 0) 8 __tconst9qC527 __tconst9Om326 __tconst0Q4z25 __tconst6M0p24 __tconst2nEI23 __tconst4Ied22 __tconst2O9k21 __tconst755B20 __t91OM28) (exists n2 (2 1 0) 1 __t91OM28) (join l8 (1 2 3 4 5 6 7 8 0) 8 __tconst80ly36 __tconst5jtZ35 __tconst83R834 __tconst4Vmv33 __tconst4fQB32 __tconst40Ez31 __tconst7DGk30 __tconst1xMG29 __t66rT37) (exists n2 (2 1 0) 2 __t91OM28 __t66rT37) (join n2 (2 1 0) 2 __t7tQU9 __t1W5d18 __t2YL419) (join n2 (2 1 0) 2 __t91OM28 __t66rT37 __t61f638)) (head (mkstruct n4 (2 1 0) __t7VhN39 __t2YL419 __t61f638)) wide_fact.slog:12 #f)
  class ReadTask132 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** l8index120;  slog::Index** l8index121;  slog::Index** l8index122;  slog::Index** n2index123;  slog::Index** l8index124;  slog::Index** n2index125;  slog::Index** l8index126;  slog::Index** n2index127;  slog::Index** l8index128;  slog::Index** n2index129;  slog::Index** n2index130;  slog::Index** n2index131;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("n4");
      std::vector<u16> ord133({2, 1, 0});
      slog::Relation* readrel134 = db->getRelation("n4");
      head_index[0] = readrel134->getIndex(ord133, false);
      std::vector<u16> ord135({1, 2, 3, 4, 5, 6, 7, 8, 0});
      slog::Relation* readrel136 = db->getRelation("l8");
      l8index120 = readrel136->getIndex(ord135, false);
      std::vector<u16> ord137({1, 2, 3, 4, 5, 6, 7, 8, 0});
      slog::Relation* readrel138 = db->getRelation("l8");
      l8index121 = readrel138->getIndex(ord137, false);
      std::vector<u16> ord139({1, 2, 3, 4, 5, 6, 7, 8, 0});
      slog::Relation* readrel140 = db->getRelation("l8");
      l8index122 = readrel140->getIndex(ord139, false);
      std::vector<u16> ord141({2, 1, 0});
      slog::Relation* readrel142 = db->getRelation("n2");
      n2index123 = readrel142->getIndex(ord141, false);
      std::vector<u16> ord143({1, 2, 3, 4, 5, 6, 7, 8, 0});
      slog::Relation* readrel144 = db->getRelation("l8");
      l8index124 = readrel144->getIndex(ord143, false);
      std::vector<u16> ord145({2, 1, 0});
      slog::Relation* readrel146 = db->getRelation("n2");
      n2index125 = readrel146->getIndex(ord145, false);
      std::vector<u16> ord147({1, 2, 3, 4, 5, 6, 7, 8, 0});
      slog::Relation* readrel148 = db->getRelation("l8");
      l8index126 = readrel148->getIndex(ord147, false);
      std::vector<u16> ord149({2, 1, 0});
      slog::Relation* readrel150 = db->getRelation("n2");
      n2index127 = readrel150->getIndex(ord149, false);
      std::vector<u16> ord151({1, 2, 3, 4, 5, 6, 7, 8, 0});
      slog::Relation* readrel152 = db->getRelation("l8");
      l8index128 = readrel152->getIndex(ord151, false);
      std::vector<u16> ord153({2, 1, 0});
      slog::Relation* readrel154 = db->getRelation("n2");
      n2index129 = readrel154->getIndex(ord153, false);
      std::vector<u16> ord155({2, 1, 0});
      slog::Relation* readrel156 = db->getRelation("n2");
      n2index130 = readrel156->getIndex(ord155, false);
      std::vector<u16> ord157({2, 1, 0});
      slog::Relation* readrel158 = db->getRelation("n2");
      n2index131 = readrel158->getIndex(ord157, false);
  
    }
    ReadTask132(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const7265b875feb0d1730ead43d3;
      u64 v_c1 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c2 = v_constd4735e3a265e16eee03f5971;
      u64 v_c3 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c4 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c5 = v_constef2d127de37b942baad06145;
      u64 v_c6 = v_conste7f6c011776e8db7cd330b54;
      u64 v_c7 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c8 = v_const2c624232cdd221771294dfbb;
      u64 v_c9 = v_const19581e27de7ced00ff1ce50b;
      u64 v_c10 = v_const4a44dc15364204a80fe80e90;
      u64 v_c11 = v_const4fc82b26aecb47d2868c4efb;
      u64 v_c12 = v_const6b51d431df5d7f141cbececc;
      u64 v_c13 = v_const3fdba35f04dc8c462986c992;
      u64 v_c14 = v_const8527a891e224136950ff32ca;
      u64 v_c15 = v_conste629fa6598d732768f7c726b;
      u64 v_c16 = v_constb17ef6d19c7a5b1ee83b907c;
      u64 v_c17 = v_const4523540f1504cd17100c4835;
      u64 v_c18 = v_const4ec9599fc203d176a301536c;
      u64 v_c19 = v_const9400f1b21cb527d7fa3d3eab;
      u64 v_c20 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c21 = v_const6f4b6612125fb3a0daecd279;
      u64 v_c22 = v_const785f3ec7eb32f30b90cd0fcf;
      u64 v_c23 = v_const535fa30d7e25dd8a49f15367;
      u64 v_c24 = v_constc2356069e9d1e79ca9243781;
      u64 v_c25 = v_constb7a56873cd771f2c446d369b;
      u64 v_c26 = v_const5f9c4ab08cac7457e9111a30;
      u64 v_c27 = v_const670671cd97404156226e5079;
      u64 v_c28 = v_const59e19706d51d39f66711c265;
      u64 v_c29 = v_const35135aaa6cc23891b40cb3f3;
      u64 v_c30 = v_const624b60c58c9d8bfb6ff1886c;
      u64 v_c31 = v_consteb1e33e8a81b697b75855af6;
      u64 v_c32 = v_conste29c9c180c6279b0b02abd6a;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<9,8>(l8index120, std::array<u64,9>{v_c25, v_c26, v_c27, v_c28, v_c29, v_c30, v_c31, v_c32, 0}, [&](const std::array<u64,9>& m159) {
        u64 v_c33 = m159[8];
        if (!slog::exists_probe<9,8>(l8index121, std::array<u64,9>{v_c9, v_c10, v_c11, v_c12, v_c13, v_c14, v_c15, v_c16, 0})) return;
        if (!slog::exists_probe<9,8>(l8index122, std::array<u64,9>{v_c1, v_c2, v_c3, v_c4, v_c5, v_c6, v_c7, v_c8, 0})) return;
        if (!slog::exists_probe<3,1>(n2index123, std::array<u64,3>{v_c33, 0, 0})) return;
        slog::join_probe<9,8>(l8index124, std::array<u64,9>{v_c17, v_c18, v_c19, v_c20, v_c21, v_c22, v_c23, v_c24, 0}, [&](const std::array<u64,9>& m160) {
          u64 v_c34 = m160[8];
          if (!slog::exists_probe<3,2>(n2index125, std::array<u64,3>{v_c33, v_c34, 0})) return;
          slog::join_probe<9,8>(l8index126, std::array<u64,9>{v_c9, v_c10, v_c11, v_c12, v_c13, v_c14, v_c15, v_c16, 0}, [&](const std::array<u64,9>& m161) {
            u64 v_c35 = m161[8];
            if (!slog::exists_probe<3,1>(n2index127, std::array<u64,3>{v_c35, 0, 0})) return;
            slog::join_probe<9,8>(l8index128, std::array<u64,9>{v_c1, v_c2, v_c3, v_c4, v_c5, v_c6, v_c7, v_c8, 0}, [&](const std::array<u64,9>& m162) {
              u64 v_c36 = m162[8];
              if (!slog::exists_probe<3,2>(n2index129, std::array<u64,3>{v_c35, v_c36, 0})) return;
              slog::join_probe<3,2>(n2index130, std::array<u64,3>{v_c33, v_c34, 0}, [&](const std::array<u64,3>& m163) {
                u64 v_c37 = m163[2];
                slog::join_probe<3,2>(n2index131, std::array<u64,3>{v_c35, v_c36, 0}, [&](const std::array<u64,3>& m164) {
                  u64 v_c38 = m164[2];
                  ++_fires;
                  slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c37, v_c38}, std::array<u16,3>{2, 1, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("wide_fact.slog:12", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask132(db,b));
  // (crule (pre (let __tconst3O4u40 const7265b875feb0d1730ead43d3) (let __tconst80ly36 const6b86b273ff34fce19d6b804e) (let __tconst5jtZ35 constd4735e3a265e16eee03f5971) (let __tconst83R834 const4e07408562bedb8b60ce05c1) (let __tconst4Vmv33 const4b227777d4dd1fc61c6f884f) (let __tconst4fQB32 constef2d127de37b942baad06145) (let __tconst40Ez31 conste7f6c011776e8db7cd330b54) (let __tconst7DGk30 const7902699be42c8a8e46fbbb45) (let __tconst1xMG29 const2c624232cdd221771294dfbb) (let __tconst9qC527 const19581e27de7ced00ff1ce50b) (let __tconst9Om326 const4a44dc15364204a80fe80e90) (let __tconst0Q4z25 const4fc82b26aecb47d2868c4efb) (let __tconst6M0p24 const6b51d431df5d7f141cbececc) (let __tconst2nEI23 const3fdba35f04dc8c462986c992) (let __tconst4Ied22 const8527a891e224136950ff32ca) (let __tconst2O9k21 conste629fa6598d732768f7c726b) (let __tconst755B20 constb17ef6d19c7a5b1ee83b907c) (let __tconst1Q3N17 const4523540f1504cd17100c4835) (let __tconst6IXa16 const4ec9599fc203d176a301536c) (let __tconst7vco15 const9400f1b21cb527d7fa3d3eab) (let __tconst02Ns14 constf5ca38f748a1d6eaf726b8a4) (let __tconst81Eh13 const6f4b6612125fb3a0daecd279) (let __tconst7mWH12 const785f3ec7eb32f30b90cd0fcf) (let __tconst5Hgw11 const535fa30d7e25dd8a49f15367) (let __tconst3TCY10 constc2356069e9d1e79ca9243781) (let __tconst7wrk8 constb7a56873cd771f2c446d369b) (let __tconst8h167 const5f9c4ab08cac7457e9111a30) (let __tconst2Zj26 const670671cd97404156226e5079) (let __tconst8Ade5 const59e19706d51d39f66711c265) (let __tconst6Ux94 const35135aaa6cc23891b40cb3f3) (let __tconst1s373 const624b60c58c9d8bfb6ff1886c) (let __tconst7Egh2 consteb1e33e8a81b697b75855af6) (let __tconst8ZZ61 conste29c9c180c6279b0b02abd6a)) (scan n2 __t2YL419 __t1W5d18 __t7tQU9) (body (join l8 (1 2 3 4 5 6 7 8 0) 9 __tconst7wrk8 __tconst8h167 __tconst2Zj26 __tconst8Ade5 __tconst6Ux94 __tconst1s373 __tconst7Egh2 __tconst8ZZ61 __t7tQU9) (join l8 (1 2 3 4 5 6 7 8 0) 9 __tconst1Q3N17 __tconst6IXa16 __tconst7vco15 __tconst02Ns14 __tconst81Eh13 __tconst7mWH12 __tconst5Hgw11 __tconst3TCY10 __t1W5d18) (exists l8 (1 2 3 4 5 6 7 8 0) 8 __tconst80ly36 __tconst5jtZ35 __tconst83R834 __tconst4Vmv33 __tconst4fQB32 __tconst40Ez31 __tconst7DGk30 __tconst1xMG29) (join l8 (1 2 3 4 5 6 7 8 0) 8 __tconst9qC527 __tconst9Om326 __tconst0Q4z25 __tconst6M0p24 __tconst2nEI23 __tconst4Ied22 __tconst2O9k21 __tconst755B20 __t91OM28) (exists n2 (2 1 0) 1 __t91OM28) (join l8 (1 2 3 4 5 6 7 8 0) 8 __tconst80ly36 __tconst5jtZ35 __tconst83R834 __tconst4Vmv33 __tconst4fQB32 __tconst40Ez31 __tconst7DGk30 __tconst1xMG29 __t66rT37) (join n2 (2 1 0) 2 __t91OM28 __t66rT37 __t61f638)) (head (mkstruct n4 (2 1 0) __t7VhN39 __t2YL419 __t61f638)) wide_fact.slog:12 #f)
  class ReadTask172 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** l8index165;  slog::Index** l8index166;  slog::Index** l8index167;  slog::Index** l8index168;  slog::Index** n2index169;  slog::Index** l8index170;  slog::Index** n2index171;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("n4");
      outer_rel = db->getRelation("n2");
      std::vector<u16> ord173({1, 2, 3, 4, 5, 6, 7, 8, 0});
      slog::Relation* readrel174 = db->getRelation("l8");
      l8index165 = readrel174->getIndex(ord173, false);
      std::vector<u16> ord175({1, 2, 3, 4, 5, 6, 7, 8, 0});
      slog::Relation* readrel176 = db->getRelation("l8");
      l8index166 = readrel176->getIndex(ord175, false);
      std::vector<u16> ord177({1, 2, 3, 4, 5, 6, 7, 8, 0});
      slog::Relation* readrel178 = db->getRelation("l8");
      l8index167 = readrel178->getIndex(ord177, false);
      std::vector<u16> ord179({1, 2, 3, 4, 5, 6, 7, 8, 0});
      slog::Relation* readrel180 = db->getRelation("l8");
      l8index168 = readrel180->getIndex(ord179, false);
      std::vector<u16> ord181({2, 1, 0});
      slog::Relation* readrel182 = db->getRelation("n2");
      n2index169 = readrel182->getIndex(ord181, false);
      std::vector<u16> ord183({1, 2, 3, 4, 5, 6, 7, 8, 0});
      slog::Relation* readrel184 = db->getRelation("l8");
      l8index170 = readrel184->getIndex(ord183, false);
      std::vector<u16> ord185({2, 1, 0});
      slog::Relation* readrel186 = db->getRelation("n2");
      n2index171 = readrel186->getIndex(ord185, false);
  
    }
    ReadTask172(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const7265b875feb0d1730ead43d3;
      u64 v_c1 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c2 = v_constd4735e3a265e16eee03f5971;
      u64 v_c3 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c4 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c5 = v_constef2d127de37b942baad06145;
      u64 v_c6 = v_conste7f6c011776e8db7cd330b54;
      u64 v_c7 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c8 = v_const2c624232cdd221771294dfbb;
      u64 v_c9 = v_const19581e27de7ced00ff1ce50b;
      u64 v_c10 = v_const4a44dc15364204a80fe80e90;
      u64 v_c11 = v_const4fc82b26aecb47d2868c4efb;
      u64 v_c12 = v_const6b51d431df5d7f141cbececc;
      u64 v_c13 = v_const3fdba35f04dc8c462986c992;
      u64 v_c14 = v_const8527a891e224136950ff32ca;
      u64 v_c15 = v_conste629fa6598d732768f7c726b;
      u64 v_c16 = v_constb17ef6d19c7a5b1ee83b907c;
      u64 v_c17 = v_const4523540f1504cd17100c4835;
      u64 v_c18 = v_const4ec9599fc203d176a301536c;
      u64 v_c19 = v_const9400f1b21cb527d7fa3d3eab;
      u64 v_c20 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c21 = v_const6f4b6612125fb3a0daecd279;
      u64 v_c22 = v_const785f3ec7eb32f30b90cd0fcf;
      u64 v_c23 = v_const535fa30d7e25dd8a49f15367;
      u64 v_c24 = v_constc2356069e9d1e79ca9243781;
      u64 v_c25 = v_constb7a56873cd771f2c446d369b;
      u64 v_c26 = v_const5f9c4ab08cac7457e9111a30;
      u64 v_c27 = v_const670671cd97404156226e5079;
      u64 v_c28 = v_const59e19706d51d39f66711c265;
      u64 v_c29 = v_const35135aaa6cc23891b40cb3f3;
      u64 v_c30 = v_const624b60c58c9d8bfb6ff1886c;
      u64 v_c31 = v_consteb1e33e8a81b697b75855af6;
      u64 v_c32 = v_conste29c9c180c6279b0b02abd6a;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c37 = _t[0];
        u64 v_c34 = _t[1];
        u64 v_c33 = _t[2];
        slog::join_probe<9,9>(l8index165, std::array<u64,9>{v_c25, v_c26, v_c27, v_c28, v_c29, v_c30, v_c31, v_c32, v_c33}, [&](const std::array<u64,9>& m187) {
          slog::join_probe<9,9>(l8index166, std::array<u64,9>{v_c17, v_c18, v_c19, v_c20, v_c21, v_c22, v_c23, v_c24, v_c34}, [&](const std::array<u64,9>& m188) {
            if (!slog::exists_probe<9,8>(l8index167, std::array<u64,9>{v_c1, v_c2, v_c3, v_c4, v_c5, v_c6, v_c7, v_c8, 0})) return;
            slog::join_probe<9,8>(l8index168, std::array<u64,9>{v_c9, v_c10, v_c11, v_c12, v_c13, v_c14, v_c15, v_c16, 0}, [&](const std::array<u64,9>& m189) {
              u64 v_c35 = m189[8];
              if (!slog::exists_probe<3,1>(n2index169, std::array<u64,3>{v_c35, 0, 0})) return;
              slog::join_probe<9,8>(l8index170, std::array<u64,9>{v_c1, v_c2, v_c3, v_c4, v_c5, v_c6, v_c7, v_c8, 0}, [&](const std::array<u64,9>& m190) {
                u64 v_c36 = m190[8];
                slog::join_probe<3,2>(n2index171, std::array<u64,3>{v_c35, v_c36, 0}, [&](const std::array<u64,3>& m191) {
                  u64 v_c38 = m191[2];
                  ++_fires;
                  slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c37, v_c38}, std::array<u16,3>{2, 1, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("wide_fact.slog:12", "delta:n2", _fires);
  
      if (!_done)
      {
        ReadTask172* _cont = new ReadTask172(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask172(db,b), false);
  // (crule (pre (let __tconst3O4u40 const7265b875feb0d1730ead43d3) (let __tconst80ly36 const6b86b273ff34fce19d6b804e) (let __tconst5jtZ35 constd4735e3a265e16eee03f5971) (let __tconst83R834 const4e07408562bedb8b60ce05c1) (let __tconst4Vmv33 const4b227777d4dd1fc61c6f884f) (let __tconst4fQB32 constef2d127de37b942baad06145) (let __tconst40Ez31 conste7f6c011776e8db7cd330b54) (let __tconst7DGk30 const7902699be42c8a8e46fbbb45) (let __tconst1xMG29 const2c624232cdd221771294dfbb) (let __tconst9qC527 const19581e27de7ced00ff1ce50b) (let __tconst9Om326 const4a44dc15364204a80fe80e90) (let __tconst0Q4z25 const4fc82b26aecb47d2868c4efb) (let __tconst6M0p24 const6b51d431df5d7f141cbececc) (let __tconst2nEI23 const3fdba35f04dc8c462986c992) (let __tconst4Ied22 const8527a891e224136950ff32ca) (let __tconst2O9k21 conste629fa6598d732768f7c726b) (let __tconst755B20 constb17ef6d19c7a5b1ee83b907c) (let __tconst1Q3N17 const4523540f1504cd17100c4835) (let __tconst6IXa16 const4ec9599fc203d176a301536c) (let __tconst7vco15 const9400f1b21cb527d7fa3d3eab) (let __tconst02Ns14 constf5ca38f748a1d6eaf726b8a4) (let __tconst81Eh13 const6f4b6612125fb3a0daecd279) (let __tconst7mWH12 const785f3ec7eb32f30b90cd0fcf) (let __tconst5Hgw11 const535fa30d7e25dd8a49f15367) (let __tconst3TCY10 constc2356069e9d1e79ca9243781) (let __tconst7wrk8 constb7a56873cd771f2c446d369b) (let __tconst8h167 const5f9c4ab08cac7457e9111a30) (let __tconst2Zj26 const670671cd97404156226e5079) (let __tconst8Ade5 const59e19706d51d39f66711c265) (let __tconst6Ux94 const35135aaa6cc23891b40cb3f3) (let __tconst1s373 const624b60c58c9d8bfb6ff1886c) (let __tconst7Egh2 consteb1e33e8a81b697b75855af6) (let __tconst8ZZ61 conste29c9c180c6279b0b02abd6a)) (seeded) (body (join l8 (1 2 3 4 5 6 7 8 0) 8 __tconst7wrk8 __tconst8h167 __tconst2Zj26 __tconst8Ade5 __tconst6Ux94 __tconst1s373 __tconst7Egh2 __tconst8ZZ61 __t7tQU9) (exists l8 (1 2 3 4 5 6 7 8 0) 8 __tconst9qC527 __tconst9Om326 __tconst0Q4z25 __tconst6M0p24 __tconst2nEI23 __tconst4Ied22 __tconst2O9k21 __tconst755B20) (exists l8 (1 2 3 4 5 6 7 8 0) 8 __tconst80ly36 __tconst5jtZ35 __tconst83R834 __tconst4Vmv33 __tconst4fQB32 __tconst40Ez31 __tconst7DGk30 __tconst1xMG29) (join l8 (1 2 3 4 5 6 7 8 0) 8 __tconst1Q3N17 __tconst6IXa16 __tconst7vco15 __tconst02Ns14 __tconst81Eh13 __tconst7mWH12 __tconst5Hgw11 __tconst3TCY10 __t1W5d18) (join l8 (1 2 3 4 5 6 7 8 0) 8 __tconst9qC527 __tconst9Om326 __tconst0Q4z25 __tconst6M0p24 __tconst2nEI23 __tconst4Ied22 __tconst2O9k21 __tconst755B20 __t91OM28) (join l8 (1 2 3 4 5 6 7 8 0) 8 __tconst80ly36 __tconst5jtZ35 __tconst83R834 __tconst4Vmv33 __tconst4fQB32 __tconst40Ez31 __tconst7DGk30 __tconst1xMG29 __t66rT37)) (head (mkstruct n2 (2 1 0) __t61f638 __t91OM28 __t66rT37) (mkstruct n2 (2 1 0) __t2YL419 __t7tQU9 __t1W5d18)) wide_fact.slog:12 #f)
  class ReadTask198 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
  
  
  
  
  
    slog::Index** l8index192;  slog::Index** l8index193;  slog::Index** l8index194;  slog::Index** l8index195;  slog::Index** l8index196;  slog::Index** l8index197;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("n2");
      std::vector<u16> ord199({2, 1, 0});
      slog::Relation* readrel200 = db->getRelation("n2");
      head_index[0] = readrel200->getIndex(ord199, false);
      head_rel[1] = db->getRelation("n2");
      std::vector<u16> ord201({2, 1, 0});
      slog::Relation* readrel202 = db->getRelation("n2");
      head_index[1] = readrel202->getIndex(ord201, false);
      std::vector<u16> ord203({1, 2, 3, 4, 5, 6, 7, 8, 0});
      slog::Relation* readrel204 = db->getRelation("l8");
      l8index192 = readrel204->getIndex(ord203, false);
      std::vector<u16> ord205({1, 2, 3, 4, 5, 6, 7, 8, 0});
      slog::Relation* readrel206 = db->getRelation("l8");
      l8index193 = readrel206->getIndex(ord205, false);
      std::vector<u16> ord207({1, 2, 3, 4, 5, 6, 7, 8, 0});
      slog::Relation* readrel208 = db->getRelation("l8");
      l8index194 = readrel208->getIndex(ord207, false);
      std::vector<u16> ord209({1, 2, 3, 4, 5, 6, 7, 8, 0});
      slog::Relation* readrel210 = db->getRelation("l8");
      l8index195 = readrel210->getIndex(ord209, false);
      std::vector<u16> ord211({1, 2, 3, 4, 5, 6, 7, 8, 0});
      slog::Relation* readrel212 = db->getRelation("l8");
      l8index196 = readrel212->getIndex(ord211, false);
      std::vector<u16> ord213({1, 2, 3, 4, 5, 6, 7, 8, 0});
      slog::Relation* readrel214 = db->getRelation("l8");
      l8index197 = readrel214->getIndex(ord213, false);
  
    }
    ReadTask198(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const7265b875feb0d1730ead43d3;
      u64 v_c1 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c2 = v_constd4735e3a265e16eee03f5971;
      u64 v_c3 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c4 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c5 = v_constef2d127de37b942baad06145;
      u64 v_c6 = v_conste7f6c011776e8db7cd330b54;
      u64 v_c7 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c8 = v_const2c624232cdd221771294dfbb;
      u64 v_c9 = v_const19581e27de7ced00ff1ce50b;
      u64 v_c10 = v_const4a44dc15364204a80fe80e90;
      u64 v_c11 = v_const4fc82b26aecb47d2868c4efb;
      u64 v_c12 = v_const6b51d431df5d7f141cbececc;
      u64 v_c13 = v_const3fdba35f04dc8c462986c992;
      u64 v_c14 = v_const8527a891e224136950ff32ca;
      u64 v_c15 = v_conste629fa6598d732768f7c726b;
      u64 v_c16 = v_constb17ef6d19c7a5b1ee83b907c;
      u64 v_c17 = v_const4523540f1504cd17100c4835;
      u64 v_c18 = v_const4ec9599fc203d176a301536c;
      u64 v_c19 = v_const9400f1b21cb527d7fa3d3eab;
      u64 v_c20 = v_constf5ca38f748a1d6eaf726b8a4;
      u64 v_c21 = v_const6f4b6612125fb3a0daecd279;
      u64 v_c22 = v_const785f3ec7eb32f30b90cd0fcf;
      u64 v_c23 = v_const535fa30d7e25dd8a49f15367;
      u64 v_c24 = v_constc2356069e9d1e79ca9243781;
      u64 v_c25 = v_constb7a56873cd771f2c446d369b;
      u64 v_c26 = v_const5f9c4ab08cac7457e9111a30;
      u64 v_c27 = v_const670671cd97404156226e5079;
      u64 v_c28 = v_const59e19706d51d39f66711c265;
      u64 v_c29 = v_const35135aaa6cc23891b40cb3f3;
      u64 v_c30 = v_const624b60c58c9d8bfb6ff1886c;
      u64 v_c31 = v_consteb1e33e8a81b697b75855af6;
      u64 v_c32 = v_conste29c9c180c6279b0b02abd6a;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      slog::join_probe<9,8>(l8index192, std::array<u64,9>{v_c25, v_c26, v_c27, v_c28, v_c29, v_c30, v_c31, v_c32, 0}, [&](const std::array<u64,9>& m215) {
        u64 v_c33 = m215[8];
        if (!slog::exists_probe<9,8>(l8index193, std::array<u64,9>{v_c9, v_c10, v_c11, v_c12, v_c13, v_c14, v_c15, v_c16, 0})) return;
        if (!slog::exists_probe<9,8>(l8index194, std::array<u64,9>{v_c1, v_c2, v_c3, v_c4, v_c5, v_c6, v_c7, v_c8, 0})) return;
        slog::join_probe<9,8>(l8index195, std::array<u64,9>{v_c17, v_c18, v_c19, v_c20, v_c21, v_c22, v_c23, v_c24, 0}, [&](const std::array<u64,9>& m216) {
          u64 v_c34 = m216[8];
          slog::join_probe<9,8>(l8index196, std::array<u64,9>{v_c9, v_c10, v_c11, v_c12, v_c13, v_c14, v_c15, v_c16, 0}, [&](const std::array<u64,9>& m217) {
            u64 v_c35 = m217[8];
            slog::join_probe<9,8>(l8index197, std::array<u64,9>{v_c1, v_c2, v_c3, v_c4, v_c5, v_c6, v_c7, v_c8, 0}, [&](const std::array<u64,9>& m218) {
              u64 v_c36 = m218[8];
              ++_fires;
              slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c35, v_c36}, std::array<u16,3>{2, 1, 0});
              slog::emit_struct_checked<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c33, v_c34}, std::array<u16,3>{2, 1, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("wide_fact.slog:12", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask198(db,b));
  s->addReadRel("l8");
  s->addReadRel("n2");
  s->addReadRel("n4");
  s->addDynamicRel("l8");
  s->addDynamicRel("n2");
  s->addDynamicRel("n4");
  s->addDynamicRel("wide");
  d->push(s);
  d->continueRun();
}

