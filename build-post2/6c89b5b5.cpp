
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const6b86b273ff34fce19d6b804e;
u64 v_constd4735e3a265e16eee03f5971;
u64 v_const4e07408562bedb8b60ce05c1;
u64 v_const4b227777d4dd1fc61c6f884f;
u64 v_constef2d127de37b942baad06145;
u64 v_constb85d38dc71a8027700bebd3c;
u64 v_const4a44dc15364204a80fe80e90;
u64 v_const4fc82b26aecb47d2868c4efb;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("6c89b5b5");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  v_constd4735e3a265e16eee03f5971 = s32_encode(2);
  v_const4e07408562bedb8b60ce05c1 = s32_encode(3);
  v_const4b227777d4dd1fc61c6f884f = s32_encode(4);
  v_constef2d127de37b942baad06145 = s32_encode(5);
  v_constb85d38dc71a8027700bebd3c = db->encodeString("two");
  v_const4a44dc15364204a80fe80e90 = s32_encode(10);
  v_const4fc82b26aecb47d2868c4efb = s32_encode(11);
  r = db->getRelation("vstr");
  if (r == 0) db->addStruct("vstr", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("vstr");
      std::vector<u16> ord52({1, 0});
    
    r->addIndex<2>(ord52, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord53({0, 1});
    
    r->addIndex<2>(ord53, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord54({1, 0});
    
    r->addIndex<2>(ord54, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("vstr"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("vnum");
  if (r == 0) db->addStruct("vnum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("vnum");
      std::vector<u16> ord55({1, 0});
    
    r->addIndex<2>(ord55, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord56({0, 1});
    
    r->addIndex<2>(ord56, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("vnum"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord57({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord57, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord58({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord58, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord59({1, 2, 0});
    
    r->addIndex<3>(ord59, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord60({0, 1, 2});
    
    r->addIndex<3>(ord60, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord61({1, 2, 0});
    
    r->addIndex<3>(ord61, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord62({0, 1, 2});
    
    r->addIndex<3>(ord62, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("regval");
  if (r == 0) db->addRelation("regval", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("regval");
  r->setLattice(LAT_FLAT, false, 0, false, 0, "flat-value", db->collections());
      std::vector<u16> ord63({0, 1, 2});
    
    r->addMapIndex<3>(ord63);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::MapWriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::LatticeInternTask<3>(db, db->getRelation("regval"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("nonconst");
  if (r == 0) db->addRelation("nonconst", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nonconst");
      std::vector<u16> ord64({0, 1});
    
    r->addIndex<2>(ord64, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("nonconst"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord65({1, 2, 3, 0});
    
    r->addIndex<4>(ord65, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord66({0, 1, 2, 3});
    
    r->addIndex<4>(ord66, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord67({1, 2, 0});
    
    r->addIndex<3>(ord67, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord68({0, 1, 2});
    
    r->addIndex<3>(ord68, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord69({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord69, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord70({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord70, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord71({1, 2, 0});
    
    r->addIndex<3>(ord71, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord72({0, 1, 2});
    
    r->addIndex<3>(ord72, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord73({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord73, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord74({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord74, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord75({1, 2, 3, 0});
    
    r->addIndex<4>(ord75, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord76({0, 1, 2, 3});
    
    r->addIndex<4>(ord76, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("flow");
  if (r == 0) db->addRelation("flow", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("flow");
      std::vector<u16> ord77({0, 1});
    
    r->addIndex<2>(ord77, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("flow"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord78({0});
    
    r->addIndex<1>(ord78, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord79({1, 2, 0});
    
    r->addIndex<3>(ord79, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord80({0, 1, 2});
    
    r->addIndex<3>(ord80, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("constat");
  if (r == 0) db->addRelation("constat", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("constat");
      std::vector<u16> ord81({0, 1, 2});
    
    r->addIndex<3>(ord81, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("constat"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("assignc");
  if (r == 0) db->addRelation("assignc", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("assignc");
      std::vector<u16> ord82({0, 1, 2});
    
    r->addIndex<3>(ord82, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("assignc"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord83({1, 0});
    
    r->addIndex<2>(ord83, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord84({0, 1});
    
    r->addIndex<2>(ord84, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  // (crule (pre (let __tconst7Jj34 constef2d127de37b942baad06145) (let __tconst3uWN6 const4a44dc15364204a80fe80e90) (let __tconst67dm12 constb85d38dc71a8027700bebd3c) (let __tconst6HGt14 const4fc82b26aecb47d2868c4efb) (let __tconst1KfF19 const6b86b273ff34fce19d6b804e) (let __tconst87f421 constd4735e3a265e16eee03f5971) (let __tconst1I8623 const4e07408562bedb8b60ce05c1)) (probe vstr (1 0) 1 __tconst67dm12 __t6pZS13) (body (exists vnum (1 0) 1 __tconst7Jj34) (join vnum (1 0) 1 __tconst1KfF19 __t4Kle9) (join vnum (1 0) 1 __tconst7Jj34 __t0htQ5)) (head (emit assignc (0 1 2) __tconst1KfF19 __tconst3uWN6 __t0htQ5) (emit assignc (0 1 2) __tconst87f421 __tconst6HGt14 __t4Kle9) (emit assignc (0 1 2) __tconst1I8623 __tconst6HGt14 __t6pZS13)) lat_constprop.slog:16 #f)
  class ReadTask3 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** vnumindex0;  slog::Index** vnumindex1;  slog::Index** vnumindex2;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("assignc");
      std::vector<u16> ord4({0, 1, 2});
      slog::Relation* readrel5 = db->getRelation("assignc");
      head_index[0] = readrel5->getIndex(ord4, false);
      head_rel[1] = db->getRelation("assignc");
      std::vector<u16> ord6({0, 1, 2});
      slog::Relation* readrel7 = db->getRelation("assignc");
      head_index[1] = readrel7->getIndex(ord6, false);
      head_rel[2] = db->getRelation("assignc");
      std::vector<u16> ord8({0, 1, 2});
      slog::Relation* readrel9 = db->getRelation("assignc");
      head_index[2] = readrel9->getIndex(ord8, false);
      std::vector<u16> ord10({1, 0});
      slog::Relation* readrel11 = db->getRelation("vstr");
      driver_index = readrel11->getIndex(ord10, true);
      std::vector<u16> ord12({1, 0});
      slog::Relation* readrel13 = db->getRelation("vnum");
      vnumindex0 = readrel13->getIndex(ord12, false);
      std::vector<u16> ord14({1, 0});
      slog::Relation* readrel15 = db->getRelation("vnum");
      vnumindex1 = readrel15->getIndex(ord14, false);
      std::vector<u16> ord16({1, 0});
      slog::Relation* readrel17 = db->getRelation("vnum");
      vnumindex2 = readrel17->getIndex(ord16, false);
  
    }
    ReadTask3(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_constef2d127de37b942baad06145;
      u64 v_c1 = v_const4a44dc15364204a80fe80e90;
      u64 v_c2 = v_constb85d38dc71a8027700bebd3c;
      u64 v_c3 = v_const4fc82b26aecb47d2868c4efb;
      u64 v_c4 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c5 = v_constd4735e3a265e16eee03f5971;
      u64 v_c6 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c2, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m18) {
        u64 v_c7 = m18[1];
        if (buckethash(v_c7) != bucket) return;
        if (!slog::exists_probe<2,1>(vnumindex0, std::array<u64,2>{v_c0, 0})) return;
        slog::join_probe<2,1>(vnumindex1, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m19) {
          u64 v_c8 = m19[1];
          slog::join_probe<2,1>(vnumindex2, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m20) {
            u64 v_c9 = m20[1];
            ++_fires;
            slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c4, v_c1, v_c9}, std::array<u16,3>{0, 1, 2});
            slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c5, v_c3, v_c8}, std::array<u16,3>{0, 1, 2});
            slog::emit<3>(head_rel[2], head_index[2], newbatch[2], std::array<u64,3>{v_c6, v_c3, v_c7}, std::array<u16,3>{0, 1, 2});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("lat_constprop.slog:16", "delta:vstr", _fires);
  
      if (!_done)
      {
        ReadTask3* _cont = new ReadTask3(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask3(db,b), false);
  // (crule (pre (let __tconst7Jj34 constef2d127de37b942baad06145) (let __tconst3uWN6 const4a44dc15364204a80fe80e90) (let __tconst67dm12 constb85d38dc71a8027700bebd3c) (let __tconst6HGt14 const4fc82b26aecb47d2868c4efb) (let __tconst1KfF19 const6b86b273ff34fce19d6b804e) (let __tconst87f421 constd4735e3a265e16eee03f5971) (let __tconst6shm22 const4b227777d4dd1fc61c6f884f) (let __tconst1I8623 const4e07408562bedb8b60ce05c1)) (once) (body) (head (emit flow (0 1) __tconst1KfF19 __tconst87f421) (emit flow (0 1) __tconst1KfF19 __tconst1I8623) (emit flow (0 1) __tconst87f421 __tconst6shm22) (emit flow (0 1) __tconst1I8623 __tconst6shm22) (mkstruct vnum (1 0) __t0htQ5 __tconst7Jj34) (mkstruct vnum (1 0) __t4Kle9 __tconst1KfF19) (mkstruct vstr (1 0) __t6pZS13 __tconst67dm12)) lat_constprop.slog:16 #f)
  class ReadTask21 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[7];
    slog::Index** head_index[7];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("flow");
      std::vector<u16> ord22({0, 1});
      slog::Relation* readrel23 = db->getRelation("flow");
      head_index[0] = readrel23->getIndex(ord22, false);
      head_rel[1] = db->getRelation("flow");
      std::vector<u16> ord24({0, 1});
      slog::Relation* readrel25 = db->getRelation("flow");
      head_index[1] = readrel25->getIndex(ord24, false);
      head_rel[2] = db->getRelation("flow");
      std::vector<u16> ord26({0, 1});
      slog::Relation* readrel27 = db->getRelation("flow");
      head_index[2] = readrel27->getIndex(ord26, false);
      head_rel[3] = db->getRelation("flow");
      std::vector<u16> ord28({0, 1});
      slog::Relation* readrel29 = db->getRelation("flow");
      head_index[3] = readrel29->getIndex(ord28, false);
      head_rel[4] = db->getRelation("vnum");
      head_rel[5] = db->getRelation("vnum");
      head_rel[6] = db->getRelation("vstr");
  
    }
    ReadTask21(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_constef2d127de37b942baad06145;
      u64 v_c1 = v_const4a44dc15364204a80fe80e90;
      u64 v_c2 = v_constb85d38dc71a8027700bebd3c;
      u64 v_c3 = v_const4fc82b26aecb47d2868c4efb;
      u64 v_c4 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c5 = v_constd4735e3a265e16eee03f5971;
      u64 v_c10 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c6 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[7];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
      newbatch[4] = new slog::InsertBatch();
      newbatch[5] = new slog::InsertBatch();
      newbatch[6] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c4, v_c5}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c4, v_c6}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[2], head_index[2], newbatch[2], std::array<u64,2>{v_c5, v_c10}, std::array<u16,2>{0, 1});
      slog::emit<2>(head_rel[3], head_index[3], newbatch[3], std::array<u64,2>{v_c6, v_c10}, std::array<u16,2>{0, 1});
      slog::emit_struct<2>(head_rel[4], newbatch[4], std::array<u64,1>{v_c0}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[5], newbatch[5], std::array<u64,1>{v_c4}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[6], newbatch[6], std::array<u64,1>{v_c2}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
        head_rel[5]->sendBatch(newbatch[5]);
        head_rel[6]->sendBatch(newbatch[6]);
  
      if (_fires) db->bumpFires("lat_constprop.slog:16", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask21(db,b), true);
  // (crule (pre (let __tconst7Jj34 constef2d127de37b942baad06145) (let __tconst3uWN6 const4a44dc15364204a80fe80e90) (let __tconst67dm12 constb85d38dc71a8027700bebd3c) (let __tconst6HGt14 const4fc82b26aecb47d2868c4efb) (let __tconst1KfF19 const6b86b273ff34fce19d6b804e) (let __tconst87f421 constd4735e3a265e16eee03f5971) (let __tconst1I8623 const4e07408562bedb8b60ce05c1)) (seeded) (body (join vstr (1 0) 1 __tconst67dm12 __t6pZS13) (exists vnum (1 0) 1 __tconst7Jj34) (join vnum (1 0) 1 __tconst1KfF19 __t4Kle9) (join vnum (1 0) 1 __tconst7Jj34 __t0htQ5)) (head (emit assignc (0 1 2) __tconst1KfF19 __tconst3uWN6 __t0htQ5) (emit assignc (0 1 2) __tconst87f421 __tconst6HGt14 __t4Kle9) (emit assignc (0 1 2) __tconst1I8623 __tconst6HGt14 __t6pZS13)) lat_constprop.slog:16 #f)
  class ReadTask34 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
  
  
  
  
  
  
    slog::Index** vstrindex30;  slog::Index** vnumindex31;  slog::Index** vnumindex32;  slog::Index** vnumindex33;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("assignc");
      std::vector<u16> ord35({0, 1, 2});
      slog::Relation* readrel36 = db->getRelation("assignc");
      head_index[0] = readrel36->getIndex(ord35, false);
      head_rel[1] = db->getRelation("assignc");
      std::vector<u16> ord37({0, 1, 2});
      slog::Relation* readrel38 = db->getRelation("assignc");
      head_index[1] = readrel38->getIndex(ord37, false);
      head_rel[2] = db->getRelation("assignc");
      std::vector<u16> ord39({0, 1, 2});
      slog::Relation* readrel40 = db->getRelation("assignc");
      head_index[2] = readrel40->getIndex(ord39, false);
      std::vector<u16> ord41({1, 0});
      slog::Relation* readrel42 = db->getRelation("vstr");
      vstrindex30 = readrel42->getIndex(ord41, false);
      std::vector<u16> ord43({1, 0});
      slog::Relation* readrel44 = db->getRelation("vnum");
      vnumindex31 = readrel44->getIndex(ord43, false);
      std::vector<u16> ord45({1, 0});
      slog::Relation* readrel46 = db->getRelation("vnum");
      vnumindex32 = readrel46->getIndex(ord45, false);
      std::vector<u16> ord47({1, 0});
      slog::Relation* readrel48 = db->getRelation("vnum");
      vnumindex33 = readrel48->getIndex(ord47, false);
  
    }
    ReadTask34(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_constef2d127de37b942baad06145;
      u64 v_c1 = v_const4a44dc15364204a80fe80e90;
      u64 v_c2 = v_constb85d38dc71a8027700bebd3c;
      u64 v_c3 = v_const4fc82b26aecb47d2868c4efb;
      u64 v_c4 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c5 = v_constd4735e3a265e16eee03f5971;
      u64 v_c6 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(vstrindex30, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m49) {
        u64 v_c7 = m49[1];
        if (!slog::exists_probe<2,1>(vnumindex31, std::array<u64,2>{v_c0, 0})) return;
        slog::join_probe<2,1>(vnumindex32, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m50) {
          u64 v_c8 = m50[1];
          slog::join_probe<2,1>(vnumindex33, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m51) {
            u64 v_c9 = m51[1];
            ++_fires;
            slog::emit<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,3>{v_c4, v_c1, v_c9}, std::array<u16,3>{0, 1, 2});
            slog::emit<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,3>{v_c5, v_c3, v_c8}, std::array<u16,3>{0, 1, 2});
            slog::emit<3>(head_rel[2], head_index[2], newbatch[2], std::array<u64,3>{v_c6, v_c3, v_c7}, std::array<u16,3>{0, 1, 2});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("lat_constprop.slog:16", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask34(db,b));
  s->addReadRel("vnum");
  s->addReadRel("vstr");
  s->addDynamicRel("assignc");
  s->addDynamicRel("flow");
  s->addDynamicRel("vnum");
  s->addDynamicRel("vstr");
  d->push(s);
  d->continueRun();
}

