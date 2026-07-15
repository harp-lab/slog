
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const6b86b273ff34fce19d6b804e;
u64 v_constd4735e3a265e16eee03f5971;
u64 v_const4e07408562bedb8b60ce05c1;
u64 v_const4b227777d4dd1fc61c6f884f;
u64 v_constef2d127de37b942baad06145;
u64 v_conste7f6c011776e8db7cd330b54;
u64 v_const7902699be42c8a8e46fbbb45;
u64 v_const4a44dc15364204a80fe80e90;
u64 v_const0e7683d757ca8c3c9dd2ce1c;
u64 v_const854e3d8da0f8c6840ab6bf20;
u64 v_constce5208a4d8e3ad359735ff65;
u64 v_const340b4b7905ede74af7cf7dd0;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("c8854b3d");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  v_constd4735e3a265e16eee03f5971 = s32_encode(2);
  v_const4e07408562bedb8b60ce05c1 = s32_encode(3);
  v_const4b227777d4dd1fc61c6f884f = s32_encode(4);
  v_constef2d127de37b942baad06145 = s32_encode(5);
  v_conste7f6c011776e8db7cd330b54 = s32_encode(6);
  v_const7902699be42c8a8e46fbbb45 = s32_encode(7);
  v_const4a44dc15364204a80fe80e90 = s32_encode(10);
  v_const0e7683d757ca8c3c9dd2ce1c = db->encodeString("e1");
  v_const854e3d8da0f8c6840ab6bf20 = db->encodeString("e4");
  v_constce5208a4d8e3ad359735ff65 = db->encodeString("e3");
  v_const340b4b7905ede74af7cf7dd0 = db->encodeString("e2");
  r = db->getRelation("val");
  if (r == 0) db->addRelation("val", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("val");
      std::vector<u16> ord528({0, 1});
    
    r->addIndex<2>(ord528, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("val"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord529({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord529, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord530({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord530, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord531({1, 2, 0});
    
    r->addIndex<3>(ord531, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord532({0, 1, 2});
    
    r->addIndex<3>(ord532, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("times");
  if (r == 0) db->addStruct("times", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("times");
      std::vector<u16> ord533({1, 2, 0});
    
    r->addIndex<3>(ord533, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord534({0, 1, 2});
    
    r->addIndex<3>(ord534, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
      std::vector<u16> ord535({2, 0, 1});
    
    r->addIndex<3>(ord535, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("times"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord536({1, 2, 0});
    
    r->addIndex<3>(ord536, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord537({0, 1, 2});
    
    r->addIndex<3>(ord537, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("prog");
  if (r == 0) db->addRelation("prog", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("prog");
      std::vector<u16> ord538({0, 1});
    
    r->addIndex<2>(ord538, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("prog"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("plus");
  if (r == 0) db->addStruct("plus", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("plus");
      std::vector<u16> ord539({1, 2, 0});
    
    r->addIndex<3>(ord539, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord540({0, 1, 2});
    
    r->addIndex<3>(ord540, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
      std::vector<u16> ord541({2, 0, 1});
    
    r->addIndex<3>(ord541, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("plus"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord542({1, 2, 3, 0});
    
    r->addIndex<4>(ord542, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord543({0, 1, 2, 3});
    
    r->addIndex<4>(ord543, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord544({1, 2, 0});
    
    r->addIndex<3>(ord544, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord545({0, 1, 2});
    
    r->addIndex<3>(ord545, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord546({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord546, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord547({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord547, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord548({1, 2, 0});
    
    r->addIndex<3>(ord548, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord549({0, 1, 2});
    
    r->addIndex<3>(ord549, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord550({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord550, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord551({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord551, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("lit");
  if (r == 0) db->addStruct("lit", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lit");
      std::vector<u16> ord552({1, 0});
    
    r->addIndex<2>(ord552, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord553({0, 1});
    
    r->addIndex<2>(ord553, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord554({1, 0});
    
    r->addIndex<2>(ord554, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("lit"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord555({1, 2, 3, 0});
    
    r->addIndex<4>(ord555, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord556({0, 1, 2, 3});
    
    r->addIndex<4>(ord556, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord557({0});
    
    r->addIndex<1>(ord557, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord558({1, 2, 0});
    
    r->addIndex<3>(ord558, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord559({0, 1, 2});
    
    r->addIndex<3>(ord559, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("answer");
  if (r == 0) db->addRelation("answer", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("answer");
      std::vector<u16> ord560({0, 1});
    
    r->addIndex<2>(ord560, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("answer"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord561({1, 0});
    
    r->addIndex<2>(ord561, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord562({0, 1});
    
    r->addIndex<2>(ord562, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  // (crule (pre (let __tconst22Sy37 const854e3d8da0f8c6840ab6bf20) (let __tconst7CTK22 const340b4b7905ede74af7cf7dd0) (let __tconst27QU10 const0e7683d757ca8c3c9dd2ce1c) (let __tconst7egK34 constef2d127de37b942baad06145) (let __tconst844K31 conste7f6c011776e8db7cd330b54) (let __tconst5mAV28 constd4735e3a265e16eee03f5971) (let __tconst2e4F26 const4a44dc15364204a80fe80e90) (let __tconst3EmL18 const6b86b273ff34fce19d6b804e) (let __tconst4Q6u13 const4e07408562bedb8b60ce05c1) (let __tconst2o1y11 const4b227777d4dd1fc61c6f884f)) (scan times __t4lem6 __t0lk75 __t36Sz3) (body (join lit (0 1) 2 __t36Sz3 __tconst2o1y11) (join lit (0 1) 2 __t0lk75 __tconst4Q6u13) (exists lit (1 0) 1 __tconst5mAV28) (exists lit (1 0) 1 __tconst3EmL18) (exists lit (1 0) 1 __tconst2e4F26) (exists lit (1 0) 1 __tconst844K31) (exists lit (1 0) 1 __tconst7egK34) (join plus (1 2 0) 2 __t0lk75 __t36Sz3 __t0w3e15) (join lit (1 0) 1 __tconst5mAV28 __t7PXS8) (exists plus (2 0 1) 1 __t7PXS8) (exists times (1 2 0) 1 __t7PXS8) (join lit (1 0) 1 __tconst3EmL18 __t0tK819) (join plus (1 2 0) 2 __t0tK819 __t7PXS8 __t2MCe20) (join lit (1 0) 1 __tconst2e4F26 __t8jEg27) (join times (1 2 0) 2 __t7PXS8 __t8jEg27 __t7gIa30) (join lit (1 0) 1 __tconst844K31 __t5DXw32) (join lit (1 0) 1 __tconst7egK34 __t7ixh35)) (head (mkstruct plus (1 2 0) __t9yPt33 __t5DXw32 __t7gIa30) (mkstruct times (1 2 0) __t0LfU21 __t2MCe20 __t0w3e15) (mkstruct plus (1 2 0) __t0AqD9 __t7PXS8 __t4lem6)) ex_eval.slog:13 #f)
  class ReadTask17 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** litindex0;  slog::Index** litindex1;  slog::Index** litindex2;  slog::Index** litindex3;  slog::Index** litindex4;  slog::Index** litindex5;  slog::Index** litindex6;  slog::Index** plusindex7;  slog::Index** litindex8;  slog::Index** plusindex9;  slog::Index** timesindex10;  slog::Index** litindex11;  slog::Index** plusindex12;  slog::Index** litindex13;  slog::Index** timesindex14;  slog::Index** litindex15;  slog::Index** litindex16;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("plus");
      head_rel[1] = db->getRelation("times");
      head_rel[2] = db->getRelation("plus");
      outer_rel = db->getRelation("times");
      std::vector<u16> ord18({0, 1});
      slog::Relation* readrel19 = db->getRelation("lit");
      litindex0 = readrel19->getIndex(ord18, false);
      std::vector<u16> ord20({0, 1});
      slog::Relation* readrel21 = db->getRelation("lit");
      litindex1 = readrel21->getIndex(ord20, false);
      std::vector<u16> ord22({1, 0});
      slog::Relation* readrel23 = db->getRelation("lit");
      litindex2 = readrel23->getIndex(ord22, false);
      std::vector<u16> ord24({1, 0});
      slog::Relation* readrel25 = db->getRelation("lit");
      litindex3 = readrel25->getIndex(ord24, false);
      std::vector<u16> ord26({1, 0});
      slog::Relation* readrel27 = db->getRelation("lit");
      litindex4 = readrel27->getIndex(ord26, false);
      std::vector<u16> ord28({1, 0});
      slog::Relation* readrel29 = db->getRelation("lit");
      litindex5 = readrel29->getIndex(ord28, false);
      std::vector<u16> ord30({1, 0});
      slog::Relation* readrel31 = db->getRelation("lit");
      litindex6 = readrel31->getIndex(ord30, false);
      std::vector<u16> ord32({1, 2, 0});
      slog::Relation* readrel33 = db->getRelation("plus");
      plusindex7 = readrel33->getIndex(ord32, false);
      std::vector<u16> ord34({1, 0});
      slog::Relation* readrel35 = db->getRelation("lit");
      litindex8 = readrel35->getIndex(ord34, false);
      std::vector<u16> ord36({2, 0, 1});
      slog::Relation* readrel37 = db->getRelation("plus");
      plusindex9 = readrel37->getIndex(ord36, false);
      std::vector<u16> ord38({1, 2, 0});
      slog::Relation* readrel39 = db->getRelation("times");
      timesindex10 = readrel39->getIndex(ord38, false);
      std::vector<u16> ord40({1, 0});
      slog::Relation* readrel41 = db->getRelation("lit");
      litindex11 = readrel41->getIndex(ord40, false);
      std::vector<u16> ord42({1, 2, 0});
      slog::Relation* readrel43 = db->getRelation("plus");
      plusindex12 = readrel43->getIndex(ord42, false);
      std::vector<u16> ord44({1, 0});
      slog::Relation* readrel45 = db->getRelation("lit");
      litindex13 = readrel45->getIndex(ord44, false);
      std::vector<u16> ord46({1, 2, 0});
      slog::Relation* readrel47 = db->getRelation("times");
      timesindex14 = readrel47->getIndex(ord46, false);
      std::vector<u16> ord48({1, 0});
      slog::Relation* readrel49 = db->getRelation("lit");
      litindex15 = readrel49->getIndex(ord48, false);
      std::vector<u16> ord50({1, 0});
      slog::Relation* readrel51 = db->getRelation("lit");
      litindex16 = readrel51->getIndex(ord50, false);
  
    }
    ReadTask17(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const854e3d8da0f8c6840ab6bf20;
      u64 v_c1 = v_const340b4b7905ede74af7cf7dd0;
      u64 v_c2 = v_const0e7683d757ca8c3c9dd2ce1c;
      u64 v_c3 = v_constef2d127de37b942baad06145;
      u64 v_c4 = v_conste7f6c011776e8db7cd330b54;
      u64 v_c5 = v_constd4735e3a265e16eee03f5971;
      u64 v_c6 = v_const4a44dc15364204a80fe80e90;
      u64 v_c7 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c8 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c9 = v_const4b227777d4dd1fc61c6f884f;
  
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
        u64 v_c10 = _t[0];
        u64 v_c11 = _t[1];
        u64 v_c12 = _t[2];
        slog::join_probe<2,2>(litindex0, std::array<u64,2>{v_c12, v_c9}, [&](const std::array<u64,2>& m52) {
          slog::join_probe<2,2>(litindex1, std::array<u64,2>{v_c11, v_c8}, [&](const std::array<u64,2>& m53) {
            if (!slog::exists_probe<2,1>(litindex2, std::array<u64,2>{v_c5, 0})) return;
            if (!slog::exists_probe<2,1>(litindex3, std::array<u64,2>{v_c7, 0})) return;
            if (!slog::exists_probe<2,1>(litindex4, std::array<u64,2>{v_c6, 0})) return;
            if (!slog::exists_probe<2,1>(litindex5, std::array<u64,2>{v_c4, 0})) return;
            if (!slog::exists_probe<2,1>(litindex6, std::array<u64,2>{v_c3, 0})) return;
            slog::join_probe<3,2>(plusindex7, std::array<u64,3>{v_c11, v_c12, 0}, [&](const std::array<u64,3>& m54) {
              u64 v_c13 = m54[2];
              slog::join_probe<2,1>(litindex8, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m55) {
                u64 v_c14 = m55[1];
                if (!slog::exists_probe<3,1>(plusindex9, std::array<u64,3>{v_c14, 0, 0})) return;
                if (!slog::exists_probe<3,1>(timesindex10, std::array<u64,3>{v_c14, 0, 0})) return;
                slog::join_probe<2,1>(litindex11, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m56) {
                  u64 v_c15 = m56[1];
                  slog::join_probe<3,2>(plusindex12, std::array<u64,3>{v_c15, v_c14, 0}, [&](const std::array<u64,3>& m57) {
                    u64 v_c16 = m57[2];
                    slog::join_probe<2,1>(litindex13, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m58) {
                      u64 v_c17 = m58[1];
                      slog::join_probe<3,2>(timesindex14, std::array<u64,3>{v_c14, v_c17, 0}, [&](const std::array<u64,3>& m59) {
                        u64 v_c18 = m59[2];
                        slog::join_probe<2,1>(litindex15, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m60) {
                          u64 v_c19 = m60[1];
                          slog::join_probe<2,1>(litindex16, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m61) {
                            u64 v_c20 = m61[1];
                            ++_fires;
                            slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c19, v_c18}, std::array<u16,3>{1, 2, 0});
                            slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c16, v_c13}, std::array<u16,3>{1, 2, 0});
                            slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c14, v_c10}, std::array<u16,3>{1, 2, 0});
                          });
                        });
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
  
      if (_fires) db->bumpFires("ex_eval.slog:13", "delta:times", _fires);
  
      if (!_done)
      {
        ReadTask17* _cont = new ReadTask17(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask17(db,b), false);
  // (crule (pre (let __tconst22Sy37 const854e3d8da0f8c6840ab6bf20) (let __tconst7egK34 constef2d127de37b942baad06145) (let __tconst844K31 conste7f6c011776e8db7cd330b54) (let __tconst5mAV28 constd4735e3a265e16eee03f5971) (let __tconst2e4F26 const4a44dc15364204a80fe80e90) (let __tconst9oGh25 constce5208a4d8e3ad359735ff65) (let __tconst86AO23 const7902699be42c8a8e46fbbb45) (let __tconst7CTK22 const340b4b7905ede74af7cf7dd0) (let __tconst3EmL18 const6b86b273ff34fce19d6b804e) (let __tconst4Q6u13 const4e07408562bedb8b60ce05c1) (let __tconst2o1y11 const4b227777d4dd1fc61c6f884f) (let __tconst27QU10 const0e7683d757ca8c3c9dd2ce1c)) (seeded) (body (join lit (1 0) 1 __tconst2o1y11 __t36Sz3) (exists lit (1 0) 1 __tconst5mAV28) (exists lit (1 0) 1 __tconst3EmL18) (exists lit (1 0) 1 __tconst86AO23) (exists lit (1 0) 1 __tconst2e4F26) (exists lit (1 0) 1 __tconst844K31) (exists lit (1 0) 1 __tconst7egK34) (join lit (1 0) 1 __tconst4Q6u13 __t0lk75) (join lit (1 0) 1 __tconst5mAV28 __t7PXS8) (join lit (1 0) 1 __tconst3EmL18 __t0tK819) (join lit (1 0) 1 __tconst86AO23 __t7kGe24) (join lit (1 0) 1 __tconst2e4F26 __t8jEg27) (join lit (1 0) 1 __tconst844K31 __t5DXw32) (join lit (1 0) 1 __tconst7egK34 __t7ixh35)) (head (emit prog (0 1) __tconst9oGh25 __t7kGe24) (mkstruct times (1 2 0) __t7gIa30 __t7PXS8 __t8jEg27) (mkstruct plus (1 2 0) __t2MCe20 __t0tK819 __t7PXS8) (mkstruct plus (1 2 0) __t0w3e15 __t0lk75 __t36Sz3) (mkstruct times (1 2 0) __t4lem6 __t0lk75 __t36Sz3)) ex_eval.slog:13 #f)
  class ReadTask76 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[5];
    slog::Index** head_index[5];
  
  
  
  
  
  
    slog::Index** litindex62;  slog::Index** litindex63;  slog::Index** litindex64;  slog::Index** litindex65;  slog::Index** litindex66;  slog::Index** litindex67;  slog::Index** litindex68;  slog::Index** litindex69;  slog::Index** litindex70;  slog::Index** litindex71;  slog::Index** litindex72;  slog::Index** litindex73;  slog::Index** litindex74;  slog::Index** litindex75;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("prog");
      std::vector<u16> ord77({0, 1});
      slog::Relation* readrel78 = db->getRelation("prog");
      head_index[0] = readrel78->getIndex(ord77, false);
      head_rel[1] = db->getRelation("times");
      std::vector<u16> ord79({1, 2, 0});
      slog::Relation* readrel80 = db->getRelation("times");
      head_index[1] = readrel80->getIndex(ord79, false);
      head_rel[2] = db->getRelation("plus");
      std::vector<u16> ord81({1, 2, 0});
      slog::Relation* readrel82 = db->getRelation("plus");
      head_index[2] = readrel82->getIndex(ord81, false);
      head_rel[3] = db->getRelation("plus");
      std::vector<u16> ord83({1, 2, 0});
      slog::Relation* readrel84 = db->getRelation("plus");
      head_index[3] = readrel84->getIndex(ord83, false);
      head_rel[4] = db->getRelation("times");
      std::vector<u16> ord85({1, 2, 0});
      slog::Relation* readrel86 = db->getRelation("times");
      head_index[4] = readrel86->getIndex(ord85, false);
      std::vector<u16> ord87({1, 0});
      slog::Relation* readrel88 = db->getRelation("lit");
      litindex62 = readrel88->getIndex(ord87, false);
      std::vector<u16> ord89({1, 0});
      slog::Relation* readrel90 = db->getRelation("lit");
      litindex63 = readrel90->getIndex(ord89, false);
      std::vector<u16> ord91({1, 0});
      slog::Relation* readrel92 = db->getRelation("lit");
      litindex64 = readrel92->getIndex(ord91, false);
      std::vector<u16> ord93({1, 0});
      slog::Relation* readrel94 = db->getRelation("lit");
      litindex65 = readrel94->getIndex(ord93, false);
      std::vector<u16> ord95({1, 0});
      slog::Relation* readrel96 = db->getRelation("lit");
      litindex66 = readrel96->getIndex(ord95, false);
      std::vector<u16> ord97({1, 0});
      slog::Relation* readrel98 = db->getRelation("lit");
      litindex67 = readrel98->getIndex(ord97, false);
      std::vector<u16> ord99({1, 0});
      slog::Relation* readrel100 = db->getRelation("lit");
      litindex68 = readrel100->getIndex(ord99, false);
      std::vector<u16> ord101({1, 0});
      slog::Relation* readrel102 = db->getRelation("lit");
      litindex69 = readrel102->getIndex(ord101, false);
      std::vector<u16> ord103({1, 0});
      slog::Relation* readrel104 = db->getRelation("lit");
      litindex70 = readrel104->getIndex(ord103, false);
      std::vector<u16> ord105({1, 0});
      slog::Relation* readrel106 = db->getRelation("lit");
      litindex71 = readrel106->getIndex(ord105, false);
      std::vector<u16> ord107({1, 0});
      slog::Relation* readrel108 = db->getRelation("lit");
      litindex72 = readrel108->getIndex(ord107, false);
      std::vector<u16> ord109({1, 0});
      slog::Relation* readrel110 = db->getRelation("lit");
      litindex73 = readrel110->getIndex(ord109, false);
      std::vector<u16> ord111({1, 0});
      slog::Relation* readrel112 = db->getRelation("lit");
      litindex74 = readrel112->getIndex(ord111, false);
      std::vector<u16> ord113({1, 0});
      slog::Relation* readrel114 = db->getRelation("lit");
      litindex75 = readrel114->getIndex(ord113, false);
  
    }
    ReadTask76(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const854e3d8da0f8c6840ab6bf20;
      u64 v_c3 = v_constef2d127de37b942baad06145;
      u64 v_c4 = v_conste7f6c011776e8db7cd330b54;
      u64 v_c5 = v_constd4735e3a265e16eee03f5971;
      u64 v_c6 = v_const4a44dc15364204a80fe80e90;
      u64 v_c21 = v_constce5208a4d8e3ad359735ff65;
      u64 v_c22 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c1 = v_const340b4b7905ede74af7cf7dd0;
      u64 v_c7 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c8 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c9 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c2 = v_const0e7683d757ca8c3c9dd2ce1c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[5];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
      newbatch[4] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(litindex62, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m115) {
        u64 v_c12 = m115[1];
        if (!slog::exists_probe<2,1>(litindex63, std::array<u64,2>{v_c5, 0})) return;
        if (!slog::exists_probe<2,1>(litindex64, std::array<u64,2>{v_c7, 0})) return;
        if (!slog::exists_probe<2,1>(litindex65, std::array<u64,2>{v_c22, 0})) return;
        if (!slog::exists_probe<2,1>(litindex66, std::array<u64,2>{v_c6, 0})) return;
        if (!slog::exists_probe<2,1>(litindex67, std::array<u64,2>{v_c4, 0})) return;
        if (!slog::exists_probe<2,1>(litindex68, std::array<u64,2>{v_c3, 0})) return;
        slog::join_probe<2,1>(litindex69, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m116) {
          u64 v_c11 = m116[1];
          slog::join_probe<2,1>(litindex70, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m117) {
            u64 v_c14 = m117[1];
            slog::join_probe<2,1>(litindex71, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m118) {
              u64 v_c15 = m118[1];
              slog::join_probe<2,1>(litindex72, std::array<u64,2>{v_c22, 0}, [&](const std::array<u64,2>& m119) {
                u64 v_c23 = m119[1];
                slog::join_probe<2,1>(litindex73, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m120) {
                  u64 v_c17 = m120[1];
                  slog::join_probe<2,1>(litindex74, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m121) {
                    u64 v_c19 = m121[1];
                    slog::join_probe<2,1>(litindex75, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m122) {
                      u64 v_c20 = m122[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c21, v_c23}, std::array<u16,2>{0, 1});
                      slog::emit_struct_checked<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c14, v_c17}, std::array<u16,3>{1, 2, 0});
                      slog::emit_struct_checked<3>(head_rel[2], head_index[2], newbatch[2], std::array<u64,2>{v_c15, v_c14}, std::array<u16,3>{1, 2, 0});
                      slog::emit_struct_checked<3>(head_rel[3], head_index[3], newbatch[3], std::array<u64,2>{v_c11, v_c12}, std::array<u16,3>{1, 2, 0});
                      slog::emit_struct_checked<3>(head_rel[4], head_index[4], newbatch[4], std::array<u64,2>{v_c11, v_c12}, std::array<u16,3>{1, 2, 0});
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
  
      if (_fires) db->bumpFires("ex_eval.slog:13", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask76(db,b));
  // (crule (pre (let __tconst22Sy37 const854e3d8da0f8c6840ab6bf20) (let __tconst7CTK22 const340b4b7905ede74af7cf7dd0) (let __tconst27QU10 const0e7683d757ca8c3c9dd2ce1c) (let __tconst7egK34 constef2d127de37b942baad06145) (let __tconst844K31 conste7f6c011776e8db7cd330b54) (let __tconst5mAV28 constd4735e3a265e16eee03f5971) (let __tconst2e4F26 const4a44dc15364204a80fe80e90) (let __tconst3EmL18 const6b86b273ff34fce19d6b804e) (let __tconst4Q6u13 const4e07408562bedb8b60ce05c1) (let __tconst2o1y11 const4b227777d4dd1fc61c6f884f)) (seeded) (body (join lit (1 0) 1 __tconst5mAV28 __t7PXS8) (exists lit (1 0) 1 __tconst7egK34) (exists lit (1 0) 1 __tconst2o1y11) (exists lit (1 0) 1 __tconst4Q6u13) (exists plus (1 2 0) 1 __t7PXS8) (exists lit (1 0) 1 __tconst3EmL18) (exists plus (2 0 1) 1 __t7PXS8) (exists lit (1 0) 1 __tconst2e4F26) (exists times (1 2 0) 1 __t7PXS8) (join lit (1 0) 1 __tconst844K31 __t5DXw32) (exists plus (1 2 0) 1 __t5DXw32) (join lit (1 0) 1 __tconst7egK34 __t7ixh35) (join lit (1 0) 1 __tconst2o1y11 __t36Sz3) (exists times (2 0 1) 1 __t36Sz3) (exists plus (2 0 1) 1 __t36Sz3) (join lit (1 0) 1 __tconst4Q6u13 __t0lk75) (exists plus (1 2 0) 2 __t0lk75 __t36Sz3) (join times (1 2 0) 2 __t0lk75 __t36Sz3 __t4lem6) (exists plus (1 2 0) 2 __t7PXS8 __t4lem6) (join plus (1 2 0) 2 __t0lk75 __t36Sz3 __t0w3e15) (exists times (2 0 1) 1 __t0w3e15) (join plus (1 2 0) 2 __t7PXS8 __t4lem6 __t0AqD9) (join lit (1 0) 1 __tconst3EmL18 __t0tK819) (join plus (1 2 0) 2 __t0tK819 __t7PXS8 __t2MCe20) (join times (1 2 0) 2 __t2MCe20 __t0w3e15 __t0LfU21) (join lit (1 0) 1 __tconst2e4F26 __t8jEg27) (join times (1 2 0) 2 __t7PXS8 __t8jEg27 __t7gIa30) (join plus (1 2 0) 2 __t5DXw32 __t7gIa30 __t9yPt33)) (head (emit prog (0 1) __tconst7CTK22 __t0LfU21) (emit prog (0 1) __tconst27QU10 __t0AqD9) (mkstruct times (1 2 0) __t2ip036 __t7ixh35 __t9yPt33)) ex_eval.slog:13 #f)
  class ReadTask151 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
  
  
  
  
  
  
    slog::Index** litindex123;  slog::Index** litindex124;  slog::Index** litindex125;  slog::Index** litindex126;  slog::Index** plusindex127;  slog::Index** litindex128;  slog::Index** plusindex129;  slog::Index** litindex130;  slog::Index** timesindex131;  slog::Index** litindex132;  slog::Index** plusindex133;  slog::Index** litindex134;  slog::Index** litindex135;  slog::Index** timesindex136;  slog::Index** plusindex137;  slog::Index** litindex138;  slog::Index** plusindex139;  slog::Index** timesindex140;  slog::Index** plusindex141;  slog::Index** plusindex142;  slog::Index** timesindex143;  slog::Index** plusindex144;  slog::Index** litindex145;  slog::Index** plusindex146;  slog::Index** timesindex147;  slog::Index** litindex148;  slog::Index** timesindex149;  slog::Index** plusindex150;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("prog");
      std::vector<u16> ord152({0, 1});
      slog::Relation* readrel153 = db->getRelation("prog");
      head_index[0] = readrel153->getIndex(ord152, false);
      head_rel[1] = db->getRelation("prog");
      std::vector<u16> ord154({0, 1});
      slog::Relation* readrel155 = db->getRelation("prog");
      head_index[1] = readrel155->getIndex(ord154, false);
      head_rel[2] = db->getRelation("times");
      std::vector<u16> ord156({1, 2, 0});
      slog::Relation* readrel157 = db->getRelation("times");
      head_index[2] = readrel157->getIndex(ord156, false);
      std::vector<u16> ord158({1, 0});
      slog::Relation* readrel159 = db->getRelation("lit");
      litindex123 = readrel159->getIndex(ord158, false);
      std::vector<u16> ord160({1, 0});
      slog::Relation* readrel161 = db->getRelation("lit");
      litindex124 = readrel161->getIndex(ord160, false);
      std::vector<u16> ord162({1, 0});
      slog::Relation* readrel163 = db->getRelation("lit");
      litindex125 = readrel163->getIndex(ord162, false);
      std::vector<u16> ord164({1, 0});
      slog::Relation* readrel165 = db->getRelation("lit");
      litindex126 = readrel165->getIndex(ord164, false);
      std::vector<u16> ord166({1, 2, 0});
      slog::Relation* readrel167 = db->getRelation("plus");
      plusindex127 = readrel167->getIndex(ord166, false);
      std::vector<u16> ord168({1, 0});
      slog::Relation* readrel169 = db->getRelation("lit");
      litindex128 = readrel169->getIndex(ord168, false);
      std::vector<u16> ord170({2, 0, 1});
      slog::Relation* readrel171 = db->getRelation("plus");
      plusindex129 = readrel171->getIndex(ord170, false);
      std::vector<u16> ord172({1, 0});
      slog::Relation* readrel173 = db->getRelation("lit");
      litindex130 = readrel173->getIndex(ord172, false);
      std::vector<u16> ord174({1, 2, 0});
      slog::Relation* readrel175 = db->getRelation("times");
      timesindex131 = readrel175->getIndex(ord174, false);
      std::vector<u16> ord176({1, 0});
      slog::Relation* readrel177 = db->getRelation("lit");
      litindex132 = readrel177->getIndex(ord176, false);
      std::vector<u16> ord178({1, 2, 0});
      slog::Relation* readrel179 = db->getRelation("plus");
      plusindex133 = readrel179->getIndex(ord178, false);
      std::vector<u16> ord180({1, 0});
      slog::Relation* readrel181 = db->getRelation("lit");
      litindex134 = readrel181->getIndex(ord180, false);
      std::vector<u16> ord182({1, 0});
      slog::Relation* readrel183 = db->getRelation("lit");
      litindex135 = readrel183->getIndex(ord182, false);
      std::vector<u16> ord184({2, 0, 1});
      slog::Relation* readrel185 = db->getRelation("times");
      timesindex136 = readrel185->getIndex(ord184, false);
      std::vector<u16> ord186({2, 0, 1});
      slog::Relation* readrel187 = db->getRelation("plus");
      plusindex137 = readrel187->getIndex(ord186, false);
      std::vector<u16> ord188({1, 0});
      slog::Relation* readrel189 = db->getRelation("lit");
      litindex138 = readrel189->getIndex(ord188, false);
      std::vector<u16> ord190({1, 2, 0});
      slog::Relation* readrel191 = db->getRelation("plus");
      plusindex139 = readrel191->getIndex(ord190, false);
      std::vector<u16> ord192({1, 2, 0});
      slog::Relation* readrel193 = db->getRelation("times");
      timesindex140 = readrel193->getIndex(ord192, false);
      std::vector<u16> ord194({1, 2, 0});
      slog::Relation* readrel195 = db->getRelation("plus");
      plusindex141 = readrel195->getIndex(ord194, false);
      std::vector<u16> ord196({1, 2, 0});
      slog::Relation* readrel197 = db->getRelation("plus");
      plusindex142 = readrel197->getIndex(ord196, false);
      std::vector<u16> ord198({2, 0, 1});
      slog::Relation* readrel199 = db->getRelation("times");
      timesindex143 = readrel199->getIndex(ord198, false);
      std::vector<u16> ord200({1, 2, 0});
      slog::Relation* readrel201 = db->getRelation("plus");
      plusindex144 = readrel201->getIndex(ord200, false);
      std::vector<u16> ord202({1, 0});
      slog::Relation* readrel203 = db->getRelation("lit");
      litindex145 = readrel203->getIndex(ord202, false);
      std::vector<u16> ord204({1, 2, 0});
      slog::Relation* readrel205 = db->getRelation("plus");
      plusindex146 = readrel205->getIndex(ord204, false);
      std::vector<u16> ord206({1, 2, 0});
      slog::Relation* readrel207 = db->getRelation("times");
      timesindex147 = readrel207->getIndex(ord206, false);
      std::vector<u16> ord208({1, 0});
      slog::Relation* readrel209 = db->getRelation("lit");
      litindex148 = readrel209->getIndex(ord208, false);
      std::vector<u16> ord210({1, 2, 0});
      slog::Relation* readrel211 = db->getRelation("times");
      timesindex149 = readrel211->getIndex(ord210, false);
      std::vector<u16> ord212({1, 2, 0});
      slog::Relation* readrel213 = db->getRelation("plus");
      plusindex150 = readrel213->getIndex(ord212, false);
  
    }
    ReadTask151(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const854e3d8da0f8c6840ab6bf20;
      u64 v_c1 = v_const340b4b7905ede74af7cf7dd0;
      u64 v_c2 = v_const0e7683d757ca8c3c9dd2ce1c;
      u64 v_c3 = v_constef2d127de37b942baad06145;
      u64 v_c4 = v_conste7f6c011776e8db7cd330b54;
      u64 v_c5 = v_constd4735e3a265e16eee03f5971;
      u64 v_c6 = v_const4a44dc15364204a80fe80e90;
      u64 v_c7 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c8 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c9 = v_const4b227777d4dd1fc61c6f884f;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(litindex123, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m214) {
        u64 v_c14 = m214[1];
        if (!slog::exists_probe<2,1>(litindex124, std::array<u64,2>{v_c3, 0})) return;
        if (!slog::exists_probe<2,1>(litindex125, std::array<u64,2>{v_c9, 0})) return;
        if (!slog::exists_probe<2,1>(litindex126, std::array<u64,2>{v_c8, 0})) return;
        if (!slog::exists_probe<3,1>(plusindex127, std::array<u64,3>{v_c14, 0, 0})) return;
        if (!slog::exists_probe<2,1>(litindex128, std::array<u64,2>{v_c7, 0})) return;
        if (!slog::exists_probe<3,1>(plusindex129, std::array<u64,3>{v_c14, 0, 0})) return;
        if (!slog::exists_probe<2,1>(litindex130, std::array<u64,2>{v_c6, 0})) return;
        if (!slog::exists_probe<3,1>(timesindex131, std::array<u64,3>{v_c14, 0, 0})) return;
        slog::join_probe<2,1>(litindex132, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m215) {
          u64 v_c19 = m215[1];
          if (!slog::exists_probe<3,1>(plusindex133, std::array<u64,3>{v_c19, 0, 0})) return;
          slog::join_probe<2,1>(litindex134, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m216) {
            u64 v_c20 = m216[1];
            slog::join_probe<2,1>(litindex135, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m217) {
              u64 v_c12 = m217[1];
              if (!slog::exists_probe<3,1>(timesindex136, std::array<u64,3>{v_c12, 0, 0})) return;
              if (!slog::exists_probe<3,1>(plusindex137, std::array<u64,3>{v_c12, 0, 0})) return;
              slog::join_probe<2,1>(litindex138, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m218) {
                u64 v_c11 = m218[1];
                if (!slog::exists_probe<3,2>(plusindex139, std::array<u64,3>{v_c11, v_c12, 0})) return;
                slog::join_probe<3,2>(timesindex140, std::array<u64,3>{v_c11, v_c12, 0}, [&](const std::array<u64,3>& m219) {
                  u64 v_c10 = m219[2];
                  if (!slog::exists_probe<3,2>(plusindex141, std::array<u64,3>{v_c14, v_c10, 0})) return;
                  slog::join_probe<3,2>(plusindex142, std::array<u64,3>{v_c11, v_c12, 0}, [&](const std::array<u64,3>& m220) {
                    u64 v_c13 = m220[2];
                    if (!slog::exists_probe<3,1>(timesindex143, std::array<u64,3>{v_c13, 0, 0})) return;
                    slog::join_probe<3,2>(plusindex144, std::array<u64,3>{v_c14, v_c10, 0}, [&](const std::array<u64,3>& m221) {
                      u64 v_c24 = m221[2];
                      slog::join_probe<2,1>(litindex145, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m222) {
                        u64 v_c15 = m222[1];
                        slog::join_probe<3,2>(plusindex146, std::array<u64,3>{v_c15, v_c14, 0}, [&](const std::array<u64,3>& m223) {
                          u64 v_c16 = m223[2];
                          slog::join_probe<3,2>(timesindex147, std::array<u64,3>{v_c16, v_c13, 0}, [&](const std::array<u64,3>& m224) {
                            u64 v_c25 = m224[2];
                            slog::join_probe<2,1>(litindex148, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m225) {
                              u64 v_c17 = m225[1];
                              slog::join_probe<3,2>(timesindex149, std::array<u64,3>{v_c14, v_c17, 0}, [&](const std::array<u64,3>& m226) {
                                u64 v_c18 = m226[2];
                                slog::join_probe<3,2>(plusindex150, std::array<u64,3>{v_c19, v_c18, 0}, [&](const std::array<u64,3>& m227) {
                                  u64 v_c26 = m227[2];
                                  ++_fires;
                                  slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c1, v_c25}, std::array<u16,2>{0, 1});
                                  slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c2, v_c24}, std::array<u16,2>{0, 1});
                                  slog::emit_struct_checked<3>(head_rel[2], head_index[2], newbatch[2], std::array<u64,2>{v_c20, v_c26}, std::array<u16,3>{1, 2, 0});
                                });
                              });
                            });
                          });
                        });
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
  
      if (_fires) db->bumpFires("ex_eval.slog:13", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask151(db,b));
  // (crule (pre (let __tconst22Sy37 const854e3d8da0f8c6840ab6bf20) (let __tconst7egK34 constef2d127de37b942baad06145) (let __tconst844K31 conste7f6c011776e8db7cd330b54) (let __tconst5mAV28 constd4735e3a265e16eee03f5971) (let __tconst2e4F26 const4a44dc15364204a80fe80e90)) (seeded) (body (join lit (1 0) 1 __tconst7egK34 __t7ixh35) (exists lit (1 0) 1 __tconst5mAV28) (exists lit (1 0) 1 __tconst2e4F26) (exists times (1 2 0) 1 __t7ixh35) (join lit (1 0) 1 __tconst844K31 __t5DXw32) (exists plus (1 2 0) 1 __t5DXw32) (join lit (1 0) 1 __tconst5mAV28 __t7PXS8) (exists times (1 2 0) 1 __t7PXS8) (join lit (1 0) 1 __tconst2e4F26 __t8jEg27) (join times (1 2 0) 2 __t7PXS8 __t8jEg27 __t7gIa30) (join plus (1 2 0) 2 __t5DXw32 __t7gIa30 __t9yPt33) (join times (1 2 0) 2 __t7ixh35 __t9yPt33 __t2ip036)) (head (emit prog (0 1) __tconst22Sy37 __t2ip036)) ex_eval.slog:13 #f)
  class ReadTask240 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** litindex228;  slog::Index** litindex229;  slog::Index** litindex230;  slog::Index** timesindex231;  slog::Index** litindex232;  slog::Index** plusindex233;  slog::Index** litindex234;  slog::Index** timesindex235;  slog::Index** litindex236;  slog::Index** timesindex237;  slog::Index** plusindex238;  slog::Index** timesindex239;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("prog");
      std::vector<u16> ord241({0, 1});
      slog::Relation* readrel242 = db->getRelation("prog");
      head_index[0] = readrel242->getIndex(ord241, false);
      std::vector<u16> ord243({1, 0});
      slog::Relation* readrel244 = db->getRelation("lit");
      litindex228 = readrel244->getIndex(ord243, false);
      std::vector<u16> ord245({1, 0});
      slog::Relation* readrel246 = db->getRelation("lit");
      litindex229 = readrel246->getIndex(ord245, false);
      std::vector<u16> ord247({1, 0});
      slog::Relation* readrel248 = db->getRelation("lit");
      litindex230 = readrel248->getIndex(ord247, false);
      std::vector<u16> ord249({1, 2, 0});
      slog::Relation* readrel250 = db->getRelation("times");
      timesindex231 = readrel250->getIndex(ord249, false);
      std::vector<u16> ord251({1, 0});
      slog::Relation* readrel252 = db->getRelation("lit");
      litindex232 = readrel252->getIndex(ord251, false);
      std::vector<u16> ord253({1, 2, 0});
      slog::Relation* readrel254 = db->getRelation("plus");
      plusindex233 = readrel254->getIndex(ord253, false);
      std::vector<u16> ord255({1, 0});
      slog::Relation* readrel256 = db->getRelation("lit");
      litindex234 = readrel256->getIndex(ord255, false);
      std::vector<u16> ord257({1, 2, 0});
      slog::Relation* readrel258 = db->getRelation("times");
      timesindex235 = readrel258->getIndex(ord257, false);
      std::vector<u16> ord259({1, 0});
      slog::Relation* readrel260 = db->getRelation("lit");
      litindex236 = readrel260->getIndex(ord259, false);
      std::vector<u16> ord261({1, 2, 0});
      slog::Relation* readrel262 = db->getRelation("times");
      timesindex237 = readrel262->getIndex(ord261, false);
      std::vector<u16> ord263({1, 2, 0});
      slog::Relation* readrel264 = db->getRelation("plus");
      plusindex238 = readrel264->getIndex(ord263, false);
      std::vector<u16> ord265({1, 2, 0});
      slog::Relation* readrel266 = db->getRelation("times");
      timesindex239 = readrel266->getIndex(ord265, false);
  
    }
    ReadTask240(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const854e3d8da0f8c6840ab6bf20;
      u64 v_c3 = v_constef2d127de37b942baad06145;
      u64 v_c4 = v_conste7f6c011776e8db7cd330b54;
      u64 v_c5 = v_constd4735e3a265e16eee03f5971;
      u64 v_c6 = v_const4a44dc15364204a80fe80e90;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(litindex228, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m267) {
        u64 v_c20 = m267[1];
        if (!slog::exists_probe<2,1>(litindex229, std::array<u64,2>{v_c5, 0})) return;
        if (!slog::exists_probe<2,1>(litindex230, std::array<u64,2>{v_c6, 0})) return;
        if (!slog::exists_probe<3,1>(timesindex231, std::array<u64,3>{v_c20, 0, 0})) return;
        slog::join_probe<2,1>(litindex232, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m268) {
          u64 v_c19 = m268[1];
          if (!slog::exists_probe<3,1>(plusindex233, std::array<u64,3>{v_c19, 0, 0})) return;
          slog::join_probe<2,1>(litindex234, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m269) {
            u64 v_c14 = m269[1];
            if (!slog::exists_probe<3,1>(timesindex235, std::array<u64,3>{v_c14, 0, 0})) return;
            slog::join_probe<2,1>(litindex236, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m270) {
              u64 v_c17 = m270[1];
              slog::join_probe<3,2>(timesindex237, std::array<u64,3>{v_c14, v_c17, 0}, [&](const std::array<u64,3>& m271) {
                u64 v_c18 = m271[2];
                slog::join_probe<3,2>(plusindex238, std::array<u64,3>{v_c19, v_c18, 0}, [&](const std::array<u64,3>& m272) {
                  u64 v_c26 = m272[2];
                  slog::join_probe<3,2>(timesindex239, std::array<u64,3>{v_c20, v_c26, 0}, [&](const std::array<u64,3>& m273) {
                    u64 v_c27 = m273[2];
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c0, v_c27}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("ex_eval.slog:13", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask240(db,b));
  // (crule (pre (let __tconst22Sy37 const854e3d8da0f8c6840ab6bf20) (let __tconst7egK34 constef2d127de37b942baad06145) (let __tconst844K31 conste7f6c011776e8db7cd330b54) (let __tconst5mAV28 constd4735e3a265e16eee03f5971) (let __tconst2e4F26 const4a44dc15364204a80fe80e90)) (scan times __t2ip036 __t7ixh35 __t9yPt33) (body (join lit (0 1) 2 __t7ixh35 __tconst7egK34) (exists lit (1 0) 1 __tconst5mAV28) (exists lit (1 0) 1 __tconst2e4F26) (join lit (1 0) 1 __tconst844K31 __t5DXw32) (join plus (0 1 2) 2 __t9yPt33 __t5DXw32 __t7gIa30) (join lit (1 0) 1 __tconst5mAV28 __t7PXS8) (join times (0 1 2) 2 __t7gIa30 __t7PXS8 __t8jEg27) (join lit (0 1) 2 __t8jEg27 __tconst2e4F26)) (head (emit prog (0 1) __tconst22Sy37 __t2ip036)) ex_eval.slog:13 #f)
  class ReadTask282 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** litindex274;  slog::Index** litindex275;  slog::Index** litindex276;  slog::Index** litindex277;  slog::Index** plusindex278;  slog::Index** litindex279;  slog::Index** timesindex280;  slog::Index** litindex281;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("prog");
      std::vector<u16> ord283({0, 1});
      slog::Relation* readrel284 = db->getRelation("prog");
      head_index[0] = readrel284->getIndex(ord283, false);
      outer_rel = db->getRelation("times");
      std::vector<u16> ord285({0, 1});
      slog::Relation* readrel286 = db->getRelation("lit");
      litindex274 = readrel286->getIndex(ord285, false);
      std::vector<u16> ord287({1, 0});
      slog::Relation* readrel288 = db->getRelation("lit");
      litindex275 = readrel288->getIndex(ord287, false);
      std::vector<u16> ord289({1, 0});
      slog::Relation* readrel290 = db->getRelation("lit");
      litindex276 = readrel290->getIndex(ord289, false);
      std::vector<u16> ord291({1, 0});
      slog::Relation* readrel292 = db->getRelation("lit");
      litindex277 = readrel292->getIndex(ord291, false);
      std::vector<u16> ord293({0, 1, 2});
      slog::Relation* readrel294 = db->getRelation("plus");
      plusindex278 = readrel294->getIndex(ord293, false);
      std::vector<u16> ord295({1, 0});
      slog::Relation* readrel296 = db->getRelation("lit");
      litindex279 = readrel296->getIndex(ord295, false);
      std::vector<u16> ord297({0, 1, 2});
      slog::Relation* readrel298 = db->getRelation("times");
      timesindex280 = readrel298->getIndex(ord297, false);
      std::vector<u16> ord299({0, 1});
      slog::Relation* readrel300 = db->getRelation("lit");
      litindex281 = readrel300->getIndex(ord299, false);
  
    }
    ReadTask282(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const854e3d8da0f8c6840ab6bf20;
      u64 v_c3 = v_constef2d127de37b942baad06145;
      u64 v_c4 = v_conste7f6c011776e8db7cd330b54;
      u64 v_c5 = v_constd4735e3a265e16eee03f5971;
      u64 v_c6 = v_const4a44dc15364204a80fe80e90;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c27 = _t[0];
        u64 v_c20 = _t[1];
        u64 v_c26 = _t[2];
        slog::join_probe<2,2>(litindex274, std::array<u64,2>{v_c20, v_c3}, [&](const std::array<u64,2>& m301) {
          if (!slog::exists_probe<2,1>(litindex275, std::array<u64,2>{v_c5, 0})) return;
          if (!slog::exists_probe<2,1>(litindex276, std::array<u64,2>{v_c6, 0})) return;
          slog::join_probe<2,1>(litindex277, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m302) {
            u64 v_c19 = m302[1];
            slog::join_probe<3,2>(plusindex278, std::array<u64,3>{v_c26, v_c19, 0}, [&](const std::array<u64,3>& m303) {
              u64 v_c18 = m303[2];
              slog::join_probe<2,1>(litindex279, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m304) {
                u64 v_c14 = m304[1];
                slog::join_probe<3,2>(timesindex280, std::array<u64,3>{v_c18, v_c14, 0}, [&](const std::array<u64,3>& m305) {
                  u64 v_c17 = m305[2];
                  slog::join_probe<2,2>(litindex281, std::array<u64,2>{v_c17, v_c6}, [&](const std::array<u64,2>& m306) {
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c0, v_c27}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("ex_eval.slog:13", "delta:times", _fires);
  
      if (!_done)
      {
        ReadTask282* _cont = new ReadTask282(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask282(db,b), false);
  // (crule (pre (let __tconst22Sy37 const854e3d8da0f8c6840ab6bf20) (let __tconst7CTK22 const340b4b7905ede74af7cf7dd0) (let __tconst27QU10 const0e7683d757ca8c3c9dd2ce1c) (let __tconst7egK34 constef2d127de37b942baad06145) (let __tconst844K31 conste7f6c011776e8db7cd330b54) (let __tconst5mAV28 constd4735e3a265e16eee03f5971) (let __tconst2e4F26 const4a44dc15364204a80fe80e90) (let __tconst3EmL18 const6b86b273ff34fce19d6b804e) (let __tconst4Q6u13 const4e07408562bedb8b60ce05c1) (let __tconst2o1y11 const4b227777d4dd1fc61c6f884f)) (seeded) (body (join lit (1 0) 1 __tconst2o1y11 __t36Sz3) (exists times (2 0 1) 1 __t36Sz3) (exists plus (2 0 1) 1 __t36Sz3) (exists lit (1 0) 1 __tconst5mAV28) (exists lit (1 0) 1 __tconst3EmL18) (exists lit (1 0) 1 __tconst2e4F26) (exists lit (1 0) 1 __tconst844K31) (exists lit (1 0) 1 __tconst7egK34) (join lit (1 0) 1 __tconst4Q6u13 __t0lk75) (exists plus (1 2 0) 2 __t0lk75 __t36Sz3) (join times (1 2 0) 2 __t0lk75 __t36Sz3 __t4lem6) (join plus (1 2 0) 2 __t0lk75 __t36Sz3 __t0w3e15) (join lit (1 0) 1 __tconst5mAV28 __t7PXS8) (exists plus (2 0 1) 1 __t7PXS8) (exists times (1 2 0) 1 __t7PXS8) (join lit (1 0) 1 __tconst3EmL18 __t0tK819) (join plus (1 2 0) 2 __t0tK819 __t7PXS8 __t2MCe20) (join lit (1 0) 1 __tconst2e4F26 __t8jEg27) (join times (1 2 0) 2 __t7PXS8 __t8jEg27 __t7gIa30) (join lit (1 0) 1 __tconst844K31 __t5DXw32) (join lit (1 0) 1 __tconst7egK34 __t7ixh35)) (head (mkstruct plus (1 2 0) __t9yPt33 __t5DXw32 __t7gIa30) (mkstruct times (1 2 0) __t0LfU21 __t2MCe20 __t0w3e15) (mkstruct plus (1 2 0) __t0AqD9 __t7PXS8 __t4lem6)) ex_eval.slog:13 #f)
  class ReadTask328 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
  
  
  
  
  
  
    slog::Index** litindex307;  slog::Index** timesindex308;  slog::Index** plusindex309;  slog::Index** litindex310;  slog::Index** litindex311;  slog::Index** litindex312;  slog::Index** litindex313;  slog::Index** litindex314;  slog::Index** litindex315;  slog::Index** plusindex316;  slog::Index** timesindex317;  slog::Index** plusindex318;  slog::Index** litindex319;  slog::Index** plusindex320;  slog::Index** timesindex321;  slog::Index** litindex322;  slog::Index** plusindex323;  slog::Index** litindex324;  slog::Index** timesindex325;  slog::Index** litindex326;  slog::Index** litindex327;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("plus");
      std::vector<u16> ord329({1, 2, 0});
      slog::Relation* readrel330 = db->getRelation("plus");
      head_index[0] = readrel330->getIndex(ord329, false);
      head_rel[1] = db->getRelation("times");
      std::vector<u16> ord331({1, 2, 0});
      slog::Relation* readrel332 = db->getRelation("times");
      head_index[1] = readrel332->getIndex(ord331, false);
      head_rel[2] = db->getRelation("plus");
      std::vector<u16> ord333({1, 2, 0});
      slog::Relation* readrel334 = db->getRelation("plus");
      head_index[2] = readrel334->getIndex(ord333, false);
      std::vector<u16> ord335({1, 0});
      slog::Relation* readrel336 = db->getRelation("lit");
      litindex307 = readrel336->getIndex(ord335, false);
      std::vector<u16> ord337({2, 0, 1});
      slog::Relation* readrel338 = db->getRelation("times");
      timesindex308 = readrel338->getIndex(ord337, false);
      std::vector<u16> ord339({2, 0, 1});
      slog::Relation* readrel340 = db->getRelation("plus");
      plusindex309 = readrel340->getIndex(ord339, false);
      std::vector<u16> ord341({1, 0});
      slog::Relation* readrel342 = db->getRelation("lit");
      litindex310 = readrel342->getIndex(ord341, false);
      std::vector<u16> ord343({1, 0});
      slog::Relation* readrel344 = db->getRelation("lit");
      litindex311 = readrel344->getIndex(ord343, false);
      std::vector<u16> ord345({1, 0});
      slog::Relation* readrel346 = db->getRelation("lit");
      litindex312 = readrel346->getIndex(ord345, false);
      std::vector<u16> ord347({1, 0});
      slog::Relation* readrel348 = db->getRelation("lit");
      litindex313 = readrel348->getIndex(ord347, false);
      std::vector<u16> ord349({1, 0});
      slog::Relation* readrel350 = db->getRelation("lit");
      litindex314 = readrel350->getIndex(ord349, false);
      std::vector<u16> ord351({1, 0});
      slog::Relation* readrel352 = db->getRelation("lit");
      litindex315 = readrel352->getIndex(ord351, false);
      std::vector<u16> ord353({1, 2, 0});
      slog::Relation* readrel354 = db->getRelation("plus");
      plusindex316 = readrel354->getIndex(ord353, false);
      std::vector<u16> ord355({1, 2, 0});
      slog::Relation* readrel356 = db->getRelation("times");
      timesindex317 = readrel356->getIndex(ord355, false);
      std::vector<u16> ord357({1, 2, 0});
      slog::Relation* readrel358 = db->getRelation("plus");
      plusindex318 = readrel358->getIndex(ord357, false);
      std::vector<u16> ord359({1, 0});
      slog::Relation* readrel360 = db->getRelation("lit");
      litindex319 = readrel360->getIndex(ord359, false);
      std::vector<u16> ord361({2, 0, 1});
      slog::Relation* readrel362 = db->getRelation("plus");
      plusindex320 = readrel362->getIndex(ord361, false);
      std::vector<u16> ord363({1, 2, 0});
      slog::Relation* readrel364 = db->getRelation("times");
      timesindex321 = readrel364->getIndex(ord363, false);
      std::vector<u16> ord365({1, 0});
      slog::Relation* readrel366 = db->getRelation("lit");
      litindex322 = readrel366->getIndex(ord365, false);
      std::vector<u16> ord367({1, 2, 0});
      slog::Relation* readrel368 = db->getRelation("plus");
      plusindex323 = readrel368->getIndex(ord367, false);
      std::vector<u16> ord369({1, 0});
      slog::Relation* readrel370 = db->getRelation("lit");
      litindex324 = readrel370->getIndex(ord369, false);
      std::vector<u16> ord371({1, 2, 0});
      slog::Relation* readrel372 = db->getRelation("times");
      timesindex325 = readrel372->getIndex(ord371, false);
      std::vector<u16> ord373({1, 0});
      slog::Relation* readrel374 = db->getRelation("lit");
      litindex326 = readrel374->getIndex(ord373, false);
      std::vector<u16> ord375({1, 0});
      slog::Relation* readrel376 = db->getRelation("lit");
      litindex327 = readrel376->getIndex(ord375, false);
  
    }
    ReadTask328(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const854e3d8da0f8c6840ab6bf20;
      u64 v_c1 = v_const340b4b7905ede74af7cf7dd0;
      u64 v_c2 = v_const0e7683d757ca8c3c9dd2ce1c;
      u64 v_c3 = v_constef2d127de37b942baad06145;
      u64 v_c4 = v_conste7f6c011776e8db7cd330b54;
      u64 v_c5 = v_constd4735e3a265e16eee03f5971;
      u64 v_c6 = v_const4a44dc15364204a80fe80e90;
      u64 v_c7 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c8 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c9 = v_const4b227777d4dd1fc61c6f884f;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(litindex307, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m377) {
        u64 v_c12 = m377[1];
        if (!slog::exists_probe<3,1>(timesindex308, std::array<u64,3>{v_c12, 0, 0})) return;
        if (!slog::exists_probe<3,1>(plusindex309, std::array<u64,3>{v_c12, 0, 0})) return;
        if (!slog::exists_probe<2,1>(litindex310, std::array<u64,2>{v_c5, 0})) return;
        if (!slog::exists_probe<2,1>(litindex311, std::array<u64,2>{v_c7, 0})) return;
        if (!slog::exists_probe<2,1>(litindex312, std::array<u64,2>{v_c6, 0})) return;
        if (!slog::exists_probe<2,1>(litindex313, std::array<u64,2>{v_c4, 0})) return;
        if (!slog::exists_probe<2,1>(litindex314, std::array<u64,2>{v_c3, 0})) return;
        slog::join_probe<2,1>(litindex315, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m378) {
          u64 v_c11 = m378[1];
          if (!slog::exists_probe<3,2>(plusindex316, std::array<u64,3>{v_c11, v_c12, 0})) return;
          slog::join_probe<3,2>(timesindex317, std::array<u64,3>{v_c11, v_c12, 0}, [&](const std::array<u64,3>& m379) {
            u64 v_c10 = m379[2];
            slog::join_probe<3,2>(plusindex318, std::array<u64,3>{v_c11, v_c12, 0}, [&](const std::array<u64,3>& m380) {
              u64 v_c13 = m380[2];
              slog::join_probe<2,1>(litindex319, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m381) {
                u64 v_c14 = m381[1];
                if (!slog::exists_probe<3,1>(plusindex320, std::array<u64,3>{v_c14, 0, 0})) return;
                if (!slog::exists_probe<3,1>(timesindex321, std::array<u64,3>{v_c14, 0, 0})) return;
                slog::join_probe<2,1>(litindex322, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m382) {
                  u64 v_c15 = m382[1];
                  slog::join_probe<3,2>(plusindex323, std::array<u64,3>{v_c15, v_c14, 0}, [&](const std::array<u64,3>& m383) {
                    u64 v_c16 = m383[2];
                    slog::join_probe<2,1>(litindex324, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m384) {
                      u64 v_c17 = m384[1];
                      slog::join_probe<3,2>(timesindex325, std::array<u64,3>{v_c14, v_c17, 0}, [&](const std::array<u64,3>& m385) {
                        u64 v_c18 = m385[2];
                        slog::join_probe<2,1>(litindex326, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m386) {
                          u64 v_c19 = m386[1];
                          slog::join_probe<2,1>(litindex327, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m387) {
                            u64 v_c20 = m387[1];
                            ++_fires;
                            slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c19, v_c18}, std::array<u16,3>{1, 2, 0});
                            slog::emit_struct_checked<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c16, v_c13}, std::array<u16,3>{1, 2, 0});
                            slog::emit_struct_checked<3>(head_rel[2], head_index[2], newbatch[2], std::array<u64,2>{v_c14, v_c10}, std::array<u16,3>{1, 2, 0});
                          });
                        });
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
  
      if (_fires) db->bumpFires("ex_eval.slog:13", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask328(db,b));
  // (crule (pre (let __tconst22Sy37 const854e3d8da0f8c6840ab6bf20) (let __tconst7egK34 constef2d127de37b942baad06145) (let __tconst844K31 conste7f6c011776e8db7cd330b54) (let __tconst5mAV28 constd4735e3a265e16eee03f5971) (let __tconst2e4F26 const4a44dc15364204a80fe80e90) (let __tconst9oGh25 constce5208a4d8e3ad359735ff65) (let __tconst86AO23 const7902699be42c8a8e46fbbb45) (let __tconst7CTK22 const340b4b7905ede74af7cf7dd0) (let __tconst3EmL18 const6b86b273ff34fce19d6b804e) (let __tconst4Q6u13 const4e07408562bedb8b60ce05c1) (let __tconst2o1y11 const4b227777d4dd1fc61c6f884f) (let __tconst27QU10 const0e7683d757ca8c3c9dd2ce1c)) (probe lit (1 0) 1 __tconst2o1y11 __t36Sz3) (body (exists lit (1 0) 1 __tconst5mAV28) (exists lit (1 0) 1 __tconst3EmL18) (exists lit (1 0) 1 __tconst86AO23) (exists lit (1 0) 1 __tconst2e4F26) (exists lit (1 0) 1 __tconst844K31) (exists lit (1 0) 1 __tconst7egK34) (join lit (1 0) 1 __tconst4Q6u13 __t0lk75) (join lit (1 0) 1 __tconst5mAV28 __t7PXS8) (join lit (1 0) 1 __tconst3EmL18 __t0tK819) (join lit (1 0) 1 __tconst86AO23 __t7kGe24) (join lit (1 0) 1 __tconst2e4F26 __t8jEg27) (join lit (1 0) 1 __tconst844K31 __t5DXw32) (join lit (1 0) 1 __tconst7egK34 __t7ixh35)) (head (emit prog (0 1) __tconst9oGh25 __t7kGe24) (mkstruct times (1 2 0) __t7gIa30 __t7PXS8 __t8jEg27) (mkstruct plus (1 2 0) __t2MCe20 __t0tK819 __t7PXS8) (mkstruct plus (1 2 0) __t0w3e15 __t0lk75 __t36Sz3) (mkstruct times (1 2 0) __t4lem6 __t0lk75 __t36Sz3)) ex_eval.slog:13 #f)
  class ReadTask401 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[5];
    slog::Index** head_index[5];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** litindex388;  slog::Index** litindex389;  slog::Index** litindex390;  slog::Index** litindex391;  slog::Index** litindex392;  slog::Index** litindex393;  slog::Index** litindex394;  slog::Index** litindex395;  slog::Index** litindex396;  slog::Index** litindex397;  slog::Index** litindex398;  slog::Index** litindex399;  slog::Index** litindex400;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("prog");
      std::vector<u16> ord402({0, 1});
      slog::Relation* readrel403 = db->getRelation("prog");
      head_index[0] = readrel403->getIndex(ord402, false);
      head_rel[1] = db->getRelation("times");
      head_rel[2] = db->getRelation("plus");
      head_rel[3] = db->getRelation("plus");
      head_rel[4] = db->getRelation("times");
      std::vector<u16> ord404({1, 0});
      slog::Relation* readrel405 = db->getRelation("lit");
      driver_index = readrel405->getIndex(ord404, true);
      std::vector<u16> ord406({1, 0});
      slog::Relation* readrel407 = db->getRelation("lit");
      litindex388 = readrel407->getIndex(ord406, false);
      std::vector<u16> ord408({1, 0});
      slog::Relation* readrel409 = db->getRelation("lit");
      litindex389 = readrel409->getIndex(ord408, false);
      std::vector<u16> ord410({1, 0});
      slog::Relation* readrel411 = db->getRelation("lit");
      litindex390 = readrel411->getIndex(ord410, false);
      std::vector<u16> ord412({1, 0});
      slog::Relation* readrel413 = db->getRelation("lit");
      litindex391 = readrel413->getIndex(ord412, false);
      std::vector<u16> ord414({1, 0});
      slog::Relation* readrel415 = db->getRelation("lit");
      litindex392 = readrel415->getIndex(ord414, false);
      std::vector<u16> ord416({1, 0});
      slog::Relation* readrel417 = db->getRelation("lit");
      litindex393 = readrel417->getIndex(ord416, false);
      std::vector<u16> ord418({1, 0});
      slog::Relation* readrel419 = db->getRelation("lit");
      litindex394 = readrel419->getIndex(ord418, false);
      std::vector<u16> ord420({1, 0});
      slog::Relation* readrel421 = db->getRelation("lit");
      litindex395 = readrel421->getIndex(ord420, false);
      std::vector<u16> ord422({1, 0});
      slog::Relation* readrel423 = db->getRelation("lit");
      litindex396 = readrel423->getIndex(ord422, false);
      std::vector<u16> ord424({1, 0});
      slog::Relation* readrel425 = db->getRelation("lit");
      litindex397 = readrel425->getIndex(ord424, false);
      std::vector<u16> ord426({1, 0});
      slog::Relation* readrel427 = db->getRelation("lit");
      litindex398 = readrel427->getIndex(ord426, false);
      std::vector<u16> ord428({1, 0});
      slog::Relation* readrel429 = db->getRelation("lit");
      litindex399 = readrel429->getIndex(ord428, false);
      std::vector<u16> ord430({1, 0});
      slog::Relation* readrel431 = db->getRelation("lit");
      litindex400 = readrel431->getIndex(ord430, false);
  
    }
    ReadTask401(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const854e3d8da0f8c6840ab6bf20;
      u64 v_c3 = v_constef2d127de37b942baad06145;
      u64 v_c4 = v_conste7f6c011776e8db7cd330b54;
      u64 v_c5 = v_constd4735e3a265e16eee03f5971;
      u64 v_c6 = v_const4a44dc15364204a80fe80e90;
      u64 v_c21 = v_constce5208a4d8e3ad359735ff65;
      u64 v_c22 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c1 = v_const340b4b7905ede74af7cf7dd0;
      u64 v_c7 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c8 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c9 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c2 = v_const0e7683d757ca8c3c9dd2ce1c;
  
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
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c9, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m432) {
        u64 v_c12 = m432[1];
        if (buckethash(v_c12) != bucket) return;
        if (!slog::exists_probe<2,1>(litindex388, std::array<u64,2>{v_c5, 0})) return;
        if (!slog::exists_probe<2,1>(litindex389, std::array<u64,2>{v_c7, 0})) return;
        if (!slog::exists_probe<2,1>(litindex390, std::array<u64,2>{v_c22, 0})) return;
        if (!slog::exists_probe<2,1>(litindex391, std::array<u64,2>{v_c6, 0})) return;
        if (!slog::exists_probe<2,1>(litindex392, std::array<u64,2>{v_c4, 0})) return;
        if (!slog::exists_probe<2,1>(litindex393, std::array<u64,2>{v_c3, 0})) return;
        slog::join_probe<2,1>(litindex394, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m433) {
          u64 v_c11 = m433[1];
          slog::join_probe<2,1>(litindex395, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m434) {
            u64 v_c14 = m434[1];
            slog::join_probe<2,1>(litindex396, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m435) {
              u64 v_c15 = m435[1];
              slog::join_probe<2,1>(litindex397, std::array<u64,2>{v_c22, 0}, [&](const std::array<u64,2>& m436) {
                u64 v_c23 = m436[1];
                slog::join_probe<2,1>(litindex398, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m437) {
                  u64 v_c17 = m437[1];
                  slog::join_probe<2,1>(litindex399, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m438) {
                    u64 v_c19 = m438[1];
                    slog::join_probe<2,1>(litindex400, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m439) {
                      u64 v_c20 = m439[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c21, v_c23}, std::array<u16,2>{0, 1});
                      slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c14, v_c17}, std::array<u16,3>{1, 2, 0});
                      slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c15, v_c14}, std::array<u16,3>{1, 2, 0});
                      slog::emit_struct<3>(head_rel[3], newbatch[3], std::array<u64,2>{v_c11, v_c12}, std::array<u16,3>{1, 2, 0});
                      slog::emit_struct<3>(head_rel[4], newbatch[4], std::array<u64,2>{v_c11, v_c12}, std::array<u16,3>{1, 2, 0});
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
  
      if (_fires) db->bumpFires("ex_eval.slog:13", "delta:lit", _fires);
  
      if (!_done)
      {
        ReadTask401* _cont = new ReadTask401(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask401(db,b), false);
  // (crule (pre (let __tconst22Sy37 const854e3d8da0f8c6840ab6bf20) (let __tconst7egK34 constef2d127de37b942baad06145) (let __tconst844K31 conste7f6c011776e8db7cd330b54) (let __tconst5mAV28 constd4735e3a265e16eee03f5971) (let __tconst2e4F26 const4a44dc15364204a80fe80e90) (let __tconst9oGh25 constce5208a4d8e3ad359735ff65) (let __tconst86AO23 const7902699be42c8a8e46fbbb45) (let __tconst7CTK22 const340b4b7905ede74af7cf7dd0) (let __tconst3EmL18 const6b86b273ff34fce19d6b804e) (let __tconst4Q6u13 const4e07408562bedb8b60ce05c1) (let __tconst2o1y11 const4b227777d4dd1fc61c6f884f) (let __tconst27QU10 const0e7683d757ca8c3c9dd2ce1c)) (once) (body) (head (mkstruct lit (1 0) __t7ixh35 __tconst7egK34) (mkstruct lit (1 0) __t5DXw32 __tconst844K31) (mkstruct lit (1 0) __t8jEg27 __tconst2e4F26) (mkstruct lit (1 0) __t7kGe24 __tconst86AO23) (mkstruct lit (1 0) __t0tK819 __tconst3EmL18) (mkstruct lit (1 0) __t7PXS8 __tconst5mAV28) (mkstruct lit (1 0) __t0lk75 __tconst4Q6u13) (mkstruct lit (1 0) __t36Sz3 __tconst2o1y11)) ex_eval.slog:13 #f)
  class ReadTask440 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[8];
    slog::Index** head_index[8];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lit");
      head_rel[1] = db->getRelation("lit");
      head_rel[2] = db->getRelation("lit");
      head_rel[3] = db->getRelation("lit");
      head_rel[4] = db->getRelation("lit");
      head_rel[5] = db->getRelation("lit");
      head_rel[6] = db->getRelation("lit");
      head_rel[7] = db->getRelation("lit");
  
    }
    ReadTask440(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const854e3d8da0f8c6840ab6bf20;
      u64 v_c3 = v_constef2d127de37b942baad06145;
      u64 v_c4 = v_conste7f6c011776e8db7cd330b54;
      u64 v_c5 = v_constd4735e3a265e16eee03f5971;
      u64 v_c6 = v_const4a44dc15364204a80fe80e90;
      u64 v_c21 = v_constce5208a4d8e3ad359735ff65;
      u64 v_c22 = v_const7902699be42c8a8e46fbbb45;
      u64 v_c1 = v_const340b4b7905ede74af7cf7dd0;
      u64 v_c7 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c8 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c9 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c2 = v_const0e7683d757ca8c3c9dd2ce1c;
  
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
  
      ++_fires;
      slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c3}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c4}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[2], newbatch[2], std::array<u64,1>{v_c6}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[3], newbatch[3], std::array<u64,1>{v_c22}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[4], newbatch[4], std::array<u64,1>{v_c7}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[5], newbatch[5], std::array<u64,1>{v_c5}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[6], newbatch[6], std::array<u64,1>{v_c8}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[7], newbatch[7], std::array<u64,1>{v_c9}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
        head_rel[5]->sendBatch(newbatch[5]);
        head_rel[6]->sendBatch(newbatch[6]);
        head_rel[7]->sendBatch(newbatch[7]);
  
      if (_fires) db->bumpFires("ex_eval.slog:13", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask440(db,b), true);
  // (crule (pre (let __tconst22Sy37 const854e3d8da0f8c6840ab6bf20) (let __tconst7CTK22 const340b4b7905ede74af7cf7dd0) (let __tconst27QU10 const0e7683d757ca8c3c9dd2ce1c) (let __tconst7egK34 constef2d127de37b942baad06145) (let __tconst844K31 conste7f6c011776e8db7cd330b54) (let __tconst5mAV28 constd4735e3a265e16eee03f5971) (let __tconst2e4F26 const4a44dc15364204a80fe80e90) (let __tconst3EmL18 const6b86b273ff34fce19d6b804e) (let __tconst4Q6u13 const4e07408562bedb8b60ce05c1) (let __tconst2o1y11 const4b227777d4dd1fc61c6f884f)) (scan plus __t0AqD9 __t7PXS8 __t4lem6) (body (join lit (0 1) 2 __t7PXS8 __tconst5mAV28) (exists lit (1 0) 1 __tconst7egK34) (exists lit (1 0) 1 __tconst2o1y11) (exists lit (1 0) 1 __tconst4Q6u13) (exists lit (1 0) 1 __tconst3EmL18) (exists plus (2 0 1) 1 __t7PXS8) (exists lit (1 0) 1 __tconst2e4F26) (exists times (1 2 0) 1 __t7PXS8) (join lit (1 0) 1 __tconst844K31 __t5DXw32) (exists plus (1 2 0) 1 __t5DXw32) (join lit (1 0) 1 __tconst7egK34 __t7ixh35) (join lit (1 0) 1 __tconst2o1y11 __t36Sz3) (exists plus (2 0 1) 1 __t36Sz3) (join times (2 0 1) 2 __t36Sz3 __t4lem6 __t0lk75) (join lit (0 1) 2 __t0lk75 __tconst4Q6u13) (join plus (1 2 0) 2 __t0lk75 __t36Sz3 __t0w3e15) (exists times (2 0 1) 1 __t0w3e15) (join lit (1 0) 1 __tconst3EmL18 __t0tK819) (join plus (1 2 0) 2 __t0tK819 __t7PXS8 __t2MCe20) (join times (1 2 0) 2 __t2MCe20 __t0w3e15 __t0LfU21) (join lit (1 0) 1 __tconst2e4F26 __t8jEg27) (join times (1 2 0) 2 __t7PXS8 __t8jEg27 __t7gIa30) (join plus (1 2 0) 2 __t5DXw32 __t7gIa30 __t9yPt33)) (head (emit prog (0 1) __tconst7CTK22 __t0LfU21) (emit prog (0 1) __tconst27QU10 __t0AqD9) (mkstruct times (1 2 0) __t2ip036 __t7ixh35 __t9yPt33)) ex_eval.slog:13 #f)
  class ReadTask464 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** litindex441;  slog::Index** litindex442;  slog::Index** litindex443;  slog::Index** litindex444;  slog::Index** litindex445;  slog::Index** plusindex446;  slog::Index** litindex447;  slog::Index** timesindex448;  slog::Index** litindex449;  slog::Index** plusindex450;  slog::Index** litindex451;  slog::Index** litindex452;  slog::Index** plusindex453;  slog::Index** timesindex454;  slog::Index** litindex455;  slog::Index** plusindex456;  slog::Index** timesindex457;  slog::Index** litindex458;  slog::Index** plusindex459;  slog::Index** timesindex460;  slog::Index** litindex461;  slog::Index** timesindex462;  slog::Index** plusindex463;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("prog");
      std::vector<u16> ord465({0, 1});
      slog::Relation* readrel466 = db->getRelation("prog");
      head_index[0] = readrel466->getIndex(ord465, false);
      head_rel[1] = db->getRelation("prog");
      std::vector<u16> ord467({0, 1});
      slog::Relation* readrel468 = db->getRelation("prog");
      head_index[1] = readrel468->getIndex(ord467, false);
      head_rel[2] = db->getRelation("times");
      outer_rel = db->getRelation("plus");
      std::vector<u16> ord469({0, 1});
      slog::Relation* readrel470 = db->getRelation("lit");
      litindex441 = readrel470->getIndex(ord469, false);
      std::vector<u16> ord471({1, 0});
      slog::Relation* readrel472 = db->getRelation("lit");
      litindex442 = readrel472->getIndex(ord471, false);
      std::vector<u16> ord473({1, 0});
      slog::Relation* readrel474 = db->getRelation("lit");
      litindex443 = readrel474->getIndex(ord473, false);
      std::vector<u16> ord475({1, 0});
      slog::Relation* readrel476 = db->getRelation("lit");
      litindex444 = readrel476->getIndex(ord475, false);
      std::vector<u16> ord477({1, 0});
      slog::Relation* readrel478 = db->getRelation("lit");
      litindex445 = readrel478->getIndex(ord477, false);
      std::vector<u16> ord479({2, 0, 1});
      slog::Relation* readrel480 = db->getRelation("plus");
      plusindex446 = readrel480->getIndex(ord479, false);
      std::vector<u16> ord481({1, 0});
      slog::Relation* readrel482 = db->getRelation("lit");
      litindex447 = readrel482->getIndex(ord481, false);
      std::vector<u16> ord483({1, 2, 0});
      slog::Relation* readrel484 = db->getRelation("times");
      timesindex448 = readrel484->getIndex(ord483, false);
      std::vector<u16> ord485({1, 0});
      slog::Relation* readrel486 = db->getRelation("lit");
      litindex449 = readrel486->getIndex(ord485, false);
      std::vector<u16> ord487({1, 2, 0});
      slog::Relation* readrel488 = db->getRelation("plus");
      plusindex450 = readrel488->getIndex(ord487, false);
      std::vector<u16> ord489({1, 0});
      slog::Relation* readrel490 = db->getRelation("lit");
      litindex451 = readrel490->getIndex(ord489, false);
      std::vector<u16> ord491({1, 0});
      slog::Relation* readrel492 = db->getRelation("lit");
      litindex452 = readrel492->getIndex(ord491, false);
      std::vector<u16> ord493({2, 0, 1});
      slog::Relation* readrel494 = db->getRelation("plus");
      plusindex453 = readrel494->getIndex(ord493, false);
      std::vector<u16> ord495({2, 0, 1});
      slog::Relation* readrel496 = db->getRelation("times");
      timesindex454 = readrel496->getIndex(ord495, false);
      std::vector<u16> ord497({0, 1});
      slog::Relation* readrel498 = db->getRelation("lit");
      litindex455 = readrel498->getIndex(ord497, false);
      std::vector<u16> ord499({1, 2, 0});
      slog::Relation* readrel500 = db->getRelation("plus");
      plusindex456 = readrel500->getIndex(ord499, false);
      std::vector<u16> ord501({2, 0, 1});
      slog::Relation* readrel502 = db->getRelation("times");
      timesindex457 = readrel502->getIndex(ord501, false);
      std::vector<u16> ord503({1, 0});
      slog::Relation* readrel504 = db->getRelation("lit");
      litindex458 = readrel504->getIndex(ord503, false);
      std::vector<u16> ord505({1, 2, 0});
      slog::Relation* readrel506 = db->getRelation("plus");
      plusindex459 = readrel506->getIndex(ord505, false);
      std::vector<u16> ord507({1, 2, 0});
      slog::Relation* readrel508 = db->getRelation("times");
      timesindex460 = readrel508->getIndex(ord507, false);
      std::vector<u16> ord509({1, 0});
      slog::Relation* readrel510 = db->getRelation("lit");
      litindex461 = readrel510->getIndex(ord509, false);
      std::vector<u16> ord511({1, 2, 0});
      slog::Relation* readrel512 = db->getRelation("times");
      timesindex462 = readrel512->getIndex(ord511, false);
      std::vector<u16> ord513({1, 2, 0});
      slog::Relation* readrel514 = db->getRelation("plus");
      plusindex463 = readrel514->getIndex(ord513, false);
  
    }
    ReadTask464(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const854e3d8da0f8c6840ab6bf20;
      u64 v_c1 = v_const340b4b7905ede74af7cf7dd0;
      u64 v_c2 = v_const0e7683d757ca8c3c9dd2ce1c;
      u64 v_c3 = v_constef2d127de37b942baad06145;
      u64 v_c4 = v_conste7f6c011776e8db7cd330b54;
      u64 v_c5 = v_constd4735e3a265e16eee03f5971;
      u64 v_c6 = v_const4a44dc15364204a80fe80e90;
      u64 v_c7 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c8 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c9 = v_const4b227777d4dd1fc61c6f884f;
  
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
        u64 v_c24 = _t[0];
        u64 v_c14 = _t[1];
        u64 v_c10 = _t[2];
        slog::join_probe<2,2>(litindex441, std::array<u64,2>{v_c14, v_c5}, [&](const std::array<u64,2>& m515) {
          if (!slog::exists_probe<2,1>(litindex442, std::array<u64,2>{v_c3, 0})) return;
          if (!slog::exists_probe<2,1>(litindex443, std::array<u64,2>{v_c9, 0})) return;
          if (!slog::exists_probe<2,1>(litindex444, std::array<u64,2>{v_c8, 0})) return;
          if (!slog::exists_probe<2,1>(litindex445, std::array<u64,2>{v_c7, 0})) return;
          if (!slog::exists_probe<3,1>(plusindex446, std::array<u64,3>{v_c14, 0, 0})) return;
          if (!slog::exists_probe<2,1>(litindex447, std::array<u64,2>{v_c6, 0})) return;
          if (!slog::exists_probe<3,1>(timesindex448, std::array<u64,3>{v_c14, 0, 0})) return;
          slog::join_probe<2,1>(litindex449, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m516) {
            u64 v_c19 = m516[1];
            if (!slog::exists_probe<3,1>(plusindex450, std::array<u64,3>{v_c19, 0, 0})) return;
            slog::join_probe<2,1>(litindex451, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m517) {
              u64 v_c20 = m517[1];
              slog::join_probe<2,1>(litindex452, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m518) {
                u64 v_c12 = m518[1];
                if (!slog::exists_probe<3,1>(plusindex453, std::array<u64,3>{v_c12, 0, 0})) return;
                slog::join_probe<3,2>(timesindex454, std::array<u64,3>{v_c12, v_c10, 0}, [&](const std::array<u64,3>& m519) {
                  u64 v_c11 = m519[2];
                  slog::join_probe<2,2>(litindex455, std::array<u64,2>{v_c11, v_c8}, [&](const std::array<u64,2>& m520) {
                    slog::join_probe<3,2>(plusindex456, std::array<u64,3>{v_c11, v_c12, 0}, [&](const std::array<u64,3>& m521) {
                      u64 v_c13 = m521[2];
                      if (!slog::exists_probe<3,1>(timesindex457, std::array<u64,3>{v_c13, 0, 0})) return;
                      slog::join_probe<2,1>(litindex458, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m522) {
                        u64 v_c15 = m522[1];
                        slog::join_probe<3,2>(plusindex459, std::array<u64,3>{v_c15, v_c14, 0}, [&](const std::array<u64,3>& m523) {
                          u64 v_c16 = m523[2];
                          slog::join_probe<3,2>(timesindex460, std::array<u64,3>{v_c16, v_c13, 0}, [&](const std::array<u64,3>& m524) {
                            u64 v_c25 = m524[2];
                            slog::join_probe<2,1>(litindex461, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m525) {
                              u64 v_c17 = m525[1];
                              slog::join_probe<3,2>(timesindex462, std::array<u64,3>{v_c14, v_c17, 0}, [&](const std::array<u64,3>& m526) {
                                u64 v_c18 = m526[2];
                                slog::join_probe<3,2>(plusindex463, std::array<u64,3>{v_c19, v_c18, 0}, [&](const std::array<u64,3>& m527) {
                                  u64 v_c26 = m527[2];
                                  ++_fires;
                                  slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c1, v_c25}, std::array<u16,2>{0, 1});
                                  slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c2, v_c24}, std::array<u16,2>{0, 1});
                                  slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c20, v_c26}, std::array<u16,3>{1, 2, 0});
                                });
                              });
                            });
                          });
                        });
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
  
      if (_fires) db->bumpFires("ex_eval.slog:13", "delta:plus", _fires);
  
      if (!_done)
      {
        ReadTask464* _cont = new ReadTask464(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask464(db,b), false);
  s->addReadRel("lit");
  s->addReadRel("plus");
  s->addReadRel("times");
  s->addDynamicRel("lit");
  s->addDynamicRel("plus");
  s->addDynamicRel("prog");
  s->addDynamicRel("times");
  d->push(s);
  d->continueRun();
}

