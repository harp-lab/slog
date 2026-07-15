
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const57e459adabad9fb762bf6769;
u64 v_const6b86b273ff34fce19d6b804e;
u64 v_const4b227777d4dd1fc61c6f884f;
u64 v_constd59eced1ded07f84c145592f;
u64 v_const38bd7d6129053ca193c79730;
u64 v_const6b51d431df5d7f141cbececc;
u64 v_constd4735e3a265e16eee03f5971;
u64 v_const86e50149658661312a9e0b35;
u64 v_const4e07408562bedb8b60ce05c1;
u64 v_const9400f1b21cb527d7fa3d3eab;
u64 v_const1b0ed536deb39ddcf8e689b3;
u64 v_conste852be0aa593e30e99f250e7;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("d8992639");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const57e459adabad9fb762bf6769 = db->encodeString("amy");
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  v_const4b227777d4dd1fc61c6f884f = s32_encode(4);
  v_constd59eced1ded07f84c145592f = s32_encode(40);
  v_const38bd7d6129053ca193c79730 = db->encodeString("dan");
  v_const6b51d431df5d7f141cbececc = s32_encode(12);
  v_constd4735e3a265e16eee03f5971 = s32_encode(2);
  v_const86e50149658661312a9e0b35 = s32_encode(34);
  v_const4e07408562bedb8b60ce05c1 = s32_encode(3);
  v_const9400f1b21cb527d7fa3d3eab = s32_encode(19);
  v_const1b0ed536deb39ddcf8e689b3 = db->encodeString("bob");
  v_conste852be0aa593e30e99f250e7 = db->encodeString("cat");
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord24({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord24, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord25({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord25, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord26({1, 2, 0});
    
    r->addIndex<3>(ord26, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord27({0, 1, 2});
    
    r->addIndex<3>(ord27, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord28({1, 2, 0});
    
    r->addIndex<3>(ord28, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord29({0, 1, 2});
    
    r->addIndex<3>(ord29, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("person");
  if (r == 0) db->addRelation("person", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("person");
      std::vector<u16> ord30({0, 1});
    
    r->addIndex<2>(ord30, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("person"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("num");
  if (r == 0) db->addRelation("num", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("num");
      std::vector<u16> ord31({0});
    
    r->addIndex<1>(ord31, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("num"), std::array<u16,1>{0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord32({1, 2, 3, 0});
    
    r->addIndex<4>(ord32, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord33({0, 1, 2, 3});
    
    r->addIndex<4>(ord33, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mutual");
  if (r == 0) db->addRelation("mutual", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mutual");
      std::vector<u16> ord34({0, 1});
    
    r->addIndex<2>(ord34, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("mutual"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord35({1, 2, 0});
    
    r->addIndex<3>(ord35, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord36({0, 1, 2});
    
    r->addIndex<3>(ord36, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord37({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord37, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord38({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord38, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord39({1, 2, 0});
    
    r->addIndex<3>(ord39, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord40({0, 1, 2});
    
    r->addIndex<3>(ord40, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord41({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord41, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord42({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord42, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("likes");
  if (r == 0) db->addRelation("likes", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("likes");
      std::vector<u16> ord43({0, 1});
    
    r->addIndex<2>(ord43, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("likes"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord44({1, 2, 3, 0});
    
    r->addIndex<4>(ord44, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord45({0, 1, 2, 3});
    
    r->addIndex<4>(ord45, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord46({0});
    
    r->addIndex<1>(ord46, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord47({1, 2, 0});
    
    r->addIndex<3>(ord47, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord48({0, 1, 2});
    
    r->addIndex<3>(ord48, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("bignum");
  if (r == 0) db->addRelation("bignum", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("bignum");
      std::vector<u16> ord49({0});
    
    r->addIndex<1>(ord49, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("bignum"), std::array<u16,1>{0}, b));
  r = db->getRelation("adult");
  if (r == 0) db->addRelation("adult", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("adult");
      std::vector<u16> ord50({0});
    
    r->addIndex<1>(ord50, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("adult"), std::array<u16,1>{0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord51({1, 0});
    
    r->addIndex<2>(ord51, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord52({0, 1});
    
    r->addIndex<2>(ord52, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  // (crule (pre (let __tconst2A7c3 const38bd7d6129053ca193c79730) (let __tconst2U7C2 constd59eced1ded07f84c145592f) (let __tconst2kT11 const4b227777d4dd1fc61c6f884f)) (once) (body) (head (emit person (0 1) __tconst2A7c3 __tconst2U7C2) (emit num (0) __tconst2kT11)) shape_facts.slog:31 #f)
  class ReadTask0 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("person");
      std::vector<u16> ord1({0, 1});
      slog::Relation* readrel2 = db->getRelation("person");
      head_index[0] = readrel2->getIndex(ord1, false);
      head_rel[1] = db->getRelation("num");
      std::vector<u16> ord3({0});
      slog::Relation* readrel4 = db->getRelation("num");
      head_index[1] = readrel4->getIndex(ord3, false);
  
    }
    ReadTask0(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const38bd7d6129053ca193c79730;
      u64 v_c1 = v_constd59eced1ded07f84c145592f;
      u64 v_c2 = v_const4b227777d4dd1fc61c6f884f;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c0, v_c1}, std::array<u16,2>{0, 1});
      slog::emit<1>(head_rel[1], head_index[1], newbatch[1], std::array<u64,1>{v_c2}, std::array<u16,1>{0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("shape_facts.slog:31", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask0(db,b), true);
  // (crule (pre (let __tconst7Nx44 const86e50149658661312a9e0b35) (let __tconst9Q1C6 const6b51d431df5d7f141cbececc) (let __tconst6IRF10 const6b86b273ff34fce19d6b804e) (let __tconst5tC911 const9400f1b21cb527d7fa3d3eab) (let __tconst3JJD14 const1b0ed536deb39ddcf8e689b3) (let __tconst99lY15 constd4735e3a265e16eee03f5971) (let __tconst8Qy416 conste852be0aa593e30e99f250e7) (let __tconst0p6W17 const57e459adabad9fb762bf6769) (let __tconst2Byq18 const4e07408562bedb8b60ce05c1)) (once) (body) (head (emit person (0 1) __tconst0p6W17 __tconst7Nx44) (emit person (0 1) __tconst3JJD14 __tconst9Q1C6) (emit likes (0 1) __tconst0p6W17 __tconst3JJD14) (emit num (0) __tconst6IRF10) (emit person (0 1) __tconst8Qy416 __tconst5tC911) (emit likes (0 1) __tconst3JJD14 __tconst0p6W17) (emit num (0) __tconst99lY15) (emit likes (0 1) __tconst0p6W17 __tconst8Qy416) (emit num (0) __tconst2Byq18)) shape_facts.slog:20 #f)
  class ReadTask5 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[9];
    slog::Index** head_index[9];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("person");
      std::vector<u16> ord6({0, 1});
      slog::Relation* readrel7 = db->getRelation("person");
      head_index[0] = readrel7->getIndex(ord6, false);
      head_rel[1] = db->getRelation("person");
      std::vector<u16> ord8({0, 1});
      slog::Relation* readrel9 = db->getRelation("person");
      head_index[1] = readrel9->getIndex(ord8, false);
      head_rel[2] = db->getRelation("likes");
      std::vector<u16> ord10({0, 1});
      slog::Relation* readrel11 = db->getRelation("likes");
      head_index[2] = readrel11->getIndex(ord10, false);
      head_rel[3] = db->getRelation("num");
      std::vector<u16> ord12({0});
      slog::Relation* readrel13 = db->getRelation("num");
      head_index[3] = readrel13->getIndex(ord12, false);
      head_rel[4] = db->getRelation("person");
      std::vector<u16> ord14({0, 1});
      slog::Relation* readrel15 = db->getRelation("person");
      head_index[4] = readrel15->getIndex(ord14, false);
      head_rel[5] = db->getRelation("likes");
      std::vector<u16> ord16({0, 1});
      slog::Relation* readrel17 = db->getRelation("likes");
      head_index[5] = readrel17->getIndex(ord16, false);
      head_rel[6] = db->getRelation("num");
      std::vector<u16> ord18({0});
      slog::Relation* readrel19 = db->getRelation("num");
      head_index[6] = readrel19->getIndex(ord18, false);
      head_rel[7] = db->getRelation("likes");
      std::vector<u16> ord20({0, 1});
      slog::Relation* readrel21 = db->getRelation("likes");
      head_index[7] = readrel21->getIndex(ord20, false);
      head_rel[8] = db->getRelation("num");
      std::vector<u16> ord22({0});
      slog::Relation* readrel23 = db->getRelation("num");
      head_index[8] = readrel23->getIndex(ord22, false);
  
    }
    ReadTask5(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c3 = v_const86e50149658661312a9e0b35;
      u64 v_c4 = v_const6b51d431df5d7f141cbececc;
      u64 v_c5 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c6 = v_const9400f1b21cb527d7fa3d3eab;
      u64 v_c7 = v_const1b0ed536deb39ddcf8e689b3;
      u64 v_c8 = v_constd4735e3a265e16eee03f5971;
      u64 v_c9 = v_conste852be0aa593e30e99f250e7;
      u64 v_c10 = v_const57e459adabad9fb762bf6769;
      u64 v_c11 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[9];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
      newbatch[4] = new slog::InsertBatch();
      newbatch[5] = new slog::InsertBatch();
      newbatch[6] = new slog::InsertBatch();
      newbatch[7] = new slog::InsertBatch();
      newbatch[8] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c10, v_c3}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c7, v_c4}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[2], head_index[2], newbatch[2], std::array<u64,2>{v_c10, v_c7}, std::array<u16,2>{0, 1});
      slog::emit<1>(head_rel[3], head_index[3], newbatch[3], std::array<u64,1>{v_c5}, std::array<u16,1>{0});
      slog::emit<2>(head_rel[4], head_index[4], newbatch[4], std::array<u64,2>{v_c9, v_c6}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[5], head_index[5], newbatch[5], std::array<u64,2>{v_c7, v_c10}, std::array<u16,2>{0, 1});
      slog::emit<1>(head_rel[6], head_index[6], newbatch[6], std::array<u64,1>{v_c8}, std::array<u16,1>{0});
      slog::emit<2>(head_rel[7], head_index[7], newbatch[7], std::array<u64,2>{v_c10, v_c9}, std::array<u16,2>{0, 1});
      slog::emit<1>(head_rel[8], head_index[8], newbatch[8], std::array<u64,1>{v_c11}, std::array<u16,1>{0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
        head_rel[5]->sendBatch(newbatch[5]);
        head_rel[6]->sendBatch(newbatch[6]);
        head_rel[7]->sendBatch(newbatch[7]);
        head_rel[8]->sendBatch(newbatch[8]);
  
      if (_fires) db->bumpFires("shape_facts.slog:20", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask5(db,b), true);
  s->addDynamicRel("likes");
  s->addDynamicRel("num");
  s->addDynamicRel("person");
  d->push(s);
  d->continueRun();
}

