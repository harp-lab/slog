
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const6b86b273ff34fce19d6b804e;
u64 v_const7f2a66c4f14264a9066b1c36;
u64 v_constd4735e3a265e16eee03f5971;
u64 v_const20c400557af0eddc0be4d9e0;
u64 v_constba2df4903a2c14e86dc3bcca;
u64 v_const2bc983a5942276eb00a75e21;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("4e995b38");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  v_const7f2a66c4f14264a9066b1c36 = db->encodeString("oops");
  v_constd4735e3a265e16eee03f5971 = s32_encode(2);
  v_const20c400557af0eddc0be4d9e0 = db->encodeString("z");
  v_constba2df4903a2c14e86dc3bcca = db->encodeString("x");
  v_const2bc983a5942276eb00a75e21 = db->encodeString("y");
  r = db->getRelation("vals");
  if (r == 0) db->addRelation("vals", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("vals");
      std::vector<u16> ord73({0});
    
    r->addIndex<1>(ord73, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("vals"), std::array<u16,1>{0}, b));
  r = db->getRelation("typed");
  if (r == 0) db->addRelation("typed", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("typed");
      std::vector<u16> ord74({0});
    
    r->addIndex<1>(ord74, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("typed"), std::array<u16,1>{0}, b));
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord75({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord75, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord76({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord76, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord77({1, 2, 0});
    
    r->addIndex<3>(ord77, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord78({0, 1, 2});
    
    r->addIndex<3>(ord78, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord79({1, 2, 0});
    
    r->addIndex<3>(ord79, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord80({0, 1, 2});
    
    r->addIndex<3>(ord80, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("raw");
  if (r == 0) db->addRelation("raw", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("raw");
      std::vector<u16> ord81({0});
    
    r->addIndex<1>(ord81, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("raw"), std::array<u16,1>{0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord82({1, 2, 3, 0});
    
    r->addIndex<4>(ord82, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord83({0, 1, 2, 3});
    
    r->addIndex<4>(ord83, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord84({1, 2, 0});
    
    r->addIndex<3>(ord84, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord85({0, 1, 2});
    
    r->addIndex<3>(ord85, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord86({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord86, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord87({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord87, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord88({1, 2, 0});
    
    r->addIndex<3>(ord88, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord89({0, 1, 2});
    
    r->addIndex<3>(ord89, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord90({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord90, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord91({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord91, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("lam");
  if (r == 0) db->addStruct("lam", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lam");
      std::vector<u16> ord92({1, 0});
    
    r->addIndex<2>(ord92, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord93({0, 1});
    
    r->addIndex<2>(ord93, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord94({1, 0});
    
    r->addIndex<2>(ord94, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("lam"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord95({1, 2, 3, 0});
    
    r->addIndex<4>(ord95, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord96({0, 1, 2, 3});
    
    r->addIndex<4>(ord96, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("flow");
  if (r == 0) db->addRelation("flow", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("flow");
      std::vector<u16> ord97({0});
    
    r->addIndex<1>(ord97, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("flow"), std::array<u16,1>{0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord98({0});
    
    r->addIndex<1>(ord98, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord99({1, 2, 0});
    
    r->addIndex<3>(ord99, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord100({0, 1, 2});
    
    r->addIndex<3>(ord100, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("app");
  if (r == 0) db->addStruct("app", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("app");
      std::vector<u16> ord101({2, 1, 0});
    
    r->addIndex<3>(ord101, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 1, 0}, false, b), true);
      std::vector<u16> ord102({0, 1, 2});
    
    r->addIndex<3>(ord102, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("app"), std::array<u16,3>{2, 1, 0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord103({1, 0});
    
    r->addIndex<2>(ord103, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord104({0, 1});
    
    r->addIndex<2>(ord104, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  // (crule (pre (let __tconst7ATK8 const2bc983a5942276eb00a75e21) (let __tconst27BW6 const20c400557af0eddc0be4d9e0)) (seeded) (body (join lam (1 0) 1 __tconst27BW6 __t0x5D7) (exists app (2 1 0) 1 __t0x5D7) (join lam (1 0) 1 __tconst7ATK8 __t6ZoD9) (join app (2 1 0) 2 __t0x5D7 __t6ZoD9 __t3l7e10)) (head (emit flow (0) __t3l7e10)) tycheck_basic.slog:15 #f)
  class ReadTask4 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** lamindex0;  slog::Index** appindex1;  slog::Index** lamindex2;  slog::Index** appindex3;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("flow");
      std::vector<u16> ord5({0});
      slog::Relation* readrel6 = db->getRelation("flow");
      head_index[0] = readrel6->getIndex(ord5, false);
      std::vector<u16> ord7({1, 0});
      slog::Relation* readrel8 = db->getRelation("lam");
      lamindex0 = readrel8->getIndex(ord7, false);
      std::vector<u16> ord9({2, 1, 0});
      slog::Relation* readrel10 = db->getRelation("app");
      appindex1 = readrel10->getIndex(ord9, false);
      std::vector<u16> ord11({1, 0});
      slog::Relation* readrel12 = db->getRelation("lam");
      lamindex2 = readrel12->getIndex(ord11, false);
      std::vector<u16> ord13({2, 1, 0});
      slog::Relation* readrel14 = db->getRelation("app");
      appindex3 = readrel14->getIndex(ord13, false);
  
    }
    ReadTask4(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const2bc983a5942276eb00a75e21;
      u64 v_c1 = v_const20c400557af0eddc0be4d9e0;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(lamindex0, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m15) {
        u64 v_c2 = m15[1];
        if (!slog::exists_probe<3,1>(appindex1, std::array<u64,3>{v_c2, 0, 0})) return;
        slog::join_probe<2,1>(lamindex2, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m16) {
          u64 v_c3 = m16[1];
          slog::join_probe<3,2>(appindex3, std::array<u64,3>{v_c2, v_c3, 0}, [&](const std::array<u64,3>& m17) {
            u64 v_c4 = m17[2];
            ++_fires;
            slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c4}, std::array<u16,1>{0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("tycheck_basic.slog:15", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask4(db,b));
  // (crule (pre (let __tconst7ATK8 const2bc983a5942276eb00a75e21) (let __tconst27BW6 const20c400557af0eddc0be4d9e0) (let __tconst5dga4 constba2df4903a2c14e86dc3bcca) (let __tconst0beC3 const7f2a66c4f14264a9066b1c36) (let __tconst59S32 constd4735e3a265e16eee03f5971) (let __tconst1fXQ1 const6b86b273ff34fce19d6b804e)) (once) (body) (head (mkstruct lam (1 0) __t6ZoD9 __tconst7ATK8) (mkstruct lam (1 0) __t0x5D7 __tconst27BW6) (mkstruct lam (1 0) __t325d5 __tconst5dga4) (emit raw (0) __tconst0beC3) (emit raw (0) __tconst59S32) (emit raw (0) __tconst1fXQ1)) tycheck_basic.slog:15 #f)
  class ReadTask18 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[6];
    slog::Index** head_index[6];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("lam");
      head_rel[1] = db->getRelation("lam");
      head_rel[2] = db->getRelation("lam");
      head_rel[3] = db->getRelation("raw");
      std::vector<u16> ord19({0});
      slog::Relation* readrel20 = db->getRelation("raw");
      head_index[3] = readrel20->getIndex(ord19, false);
      head_rel[4] = db->getRelation("raw");
      std::vector<u16> ord21({0});
      slog::Relation* readrel22 = db->getRelation("raw");
      head_index[4] = readrel22->getIndex(ord21, false);
      head_rel[5] = db->getRelation("raw");
      std::vector<u16> ord23({0});
      slog::Relation* readrel24 = db->getRelation("raw");
      head_index[5] = readrel24->getIndex(ord23, false);
  
    }
    ReadTask18(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const2bc983a5942276eb00a75e21;
      u64 v_c1 = v_const20c400557af0eddc0be4d9e0;
      u64 v_c5 = v_constba2df4903a2c14e86dc3bcca;
      u64 v_c6 = v_const7f2a66c4f14264a9066b1c36;
      u64 v_c7 = v_constd4735e3a265e16eee03f5971;
      u64 v_c8 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[6];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
      newbatch[4] = new slog::InsertBatch();
      newbatch[5] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c0}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c1}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[2], newbatch[2], std::array<u64,1>{v_c5}, std::array<u16,2>{1, 0});
      slog::emit<1>(head_rel[3], head_index[3], newbatch[3], std::array<u64,1>{v_c6}, std::array<u16,1>{0});
      slog::emit<1>(head_rel[4], head_index[4], newbatch[4], std::array<u64,1>{v_c7}, std::array<u16,1>{0});
      slog::emit<1>(head_rel[5], head_index[5], newbatch[5], std::array<u64,1>{v_c8}, std::array<u16,1>{0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
        head_rel[5]->sendBatch(newbatch[5]);
  
      if (_fires) db->bumpFires("tycheck_basic.slog:15", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask18(db,b), true);
  // (crule (pre (let __tconst7ATK8 const2bc983a5942276eb00a75e21) (let __tconst27BW6 const20c400557af0eddc0be4d9e0) (let __tconst5dga4 constba2df4903a2c14e86dc3bcca)) (probe lam (1 0) 1 __tconst5dga4 __t325d5) (body (exists lam (1 0) 1 __tconst7ATK8) (join lam (1 0) 1 __tconst27BW6 __t0x5D7) (join lam (1 0) 1 __tconst7ATK8 __t6ZoD9)) (head (mkstruct app (2 1 0) __t3l7e10 __t0x5D7 __t6ZoD9) (emit flow (0) __t325d5)) tycheck_basic.slog:15 #f)
  class ReadTask28 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** lamindex25;  slog::Index** lamindex26;  slog::Index** lamindex27;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      head_rel[1] = db->getRelation("flow");
      std::vector<u16> ord29({0});
      slog::Relation* readrel30 = db->getRelation("flow");
      head_index[1] = readrel30->getIndex(ord29, false);
      std::vector<u16> ord31({1, 0});
      slog::Relation* readrel32 = db->getRelation("lam");
      driver_index = readrel32->getIndex(ord31, true);
      std::vector<u16> ord33({1, 0});
      slog::Relation* readrel34 = db->getRelation("lam");
      lamindex25 = readrel34->getIndex(ord33, false);
      std::vector<u16> ord35({1, 0});
      slog::Relation* readrel36 = db->getRelation("lam");
      lamindex26 = readrel36->getIndex(ord35, false);
      std::vector<u16> ord37({1, 0});
      slog::Relation* readrel38 = db->getRelation("lam");
      lamindex27 = readrel38->getIndex(ord37, false);
  
    }
    ReadTask28(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const2bc983a5942276eb00a75e21;
      u64 v_c1 = v_const20c400557af0eddc0be4d9e0;
      u64 v_c5 = v_constba2df4903a2c14e86dc3bcca;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c5, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m39) {
        u64 v_c9 = m39[1];
        if (buckethash(v_c9) != bucket) return;
        if (!slog::exists_probe<2,1>(lamindex25, std::array<u64,2>{v_c0, 0})) return;
        slog::join_probe<2,1>(lamindex26, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m40) {
          u64 v_c2 = m40[1];
          slog::join_probe<2,1>(lamindex27, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m41) {
            u64 v_c3 = m41[1];
            ++_fires;
            slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c2, v_c3}, std::array<u16,3>{2, 1, 0});
            slog::emit<1>(head_rel[1], head_index[1], newbatch[1], std::array<u64,1>{v_c9}, std::array<u16,1>{0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("tycheck_basic.slog:15", "delta:lam", _fires);
  
      if (!_done)
      {
        ReadTask28* _cont = new ReadTask28(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask28(db,b), false);
  // (crule (pre (let __tconst7ATK8 const2bc983a5942276eb00a75e21) (let __tconst27BW6 const20c400557af0eddc0be4d9e0) (let __tconst5dga4 constba2df4903a2c14e86dc3bcca)) (seeded) (body (join lam (1 0) 1 __tconst5dga4 __t325d5) (exists lam (1 0) 1 __tconst7ATK8) (join lam (1 0) 1 __tconst27BW6 __t0x5D7) (join lam (1 0) 1 __tconst7ATK8 __t6ZoD9)) (head (mkstruct app (2 1 0) __t3l7e10 __t0x5D7 __t6ZoD9) (emit flow (0) __t325d5)) tycheck_basic.slog:15 #f)
  class ReadTask46 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
  
  
  
  
  
    slog::Index** lamindex42;  slog::Index** lamindex43;  slog::Index** lamindex44;  slog::Index** lamindex45;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("app");
      std::vector<u16> ord47({2, 1, 0});
      slog::Relation* readrel48 = db->getRelation("app");
      head_index[0] = readrel48->getIndex(ord47, false);
      head_rel[1] = db->getRelation("flow");
      std::vector<u16> ord49({0});
      slog::Relation* readrel50 = db->getRelation("flow");
      head_index[1] = readrel50->getIndex(ord49, false);
      std::vector<u16> ord51({1, 0});
      slog::Relation* readrel52 = db->getRelation("lam");
      lamindex42 = readrel52->getIndex(ord51, false);
      std::vector<u16> ord53({1, 0});
      slog::Relation* readrel54 = db->getRelation("lam");
      lamindex43 = readrel54->getIndex(ord53, false);
      std::vector<u16> ord55({1, 0});
      slog::Relation* readrel56 = db->getRelation("lam");
      lamindex44 = readrel56->getIndex(ord55, false);
      std::vector<u16> ord57({1, 0});
      slog::Relation* readrel58 = db->getRelation("lam");
      lamindex45 = readrel58->getIndex(ord57, false);
  
    }
    ReadTask46(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const2bc983a5942276eb00a75e21;
      u64 v_c1 = v_const20c400557af0eddc0be4d9e0;
      u64 v_c5 = v_constba2df4903a2c14e86dc3bcca;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(lamindex42, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m59) {
        u64 v_c9 = m59[1];
        if (!slog::exists_probe<2,1>(lamindex43, std::array<u64,2>{v_c0, 0})) return;
        slog::join_probe<2,1>(lamindex44, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m60) {
          u64 v_c2 = m60[1];
          slog::join_probe<2,1>(lamindex45, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m61) {
            u64 v_c3 = m61[1];
            ++_fires;
            slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c2, v_c3}, std::array<u16,3>{2, 1, 0});
            slog::emit<1>(head_rel[1], head_index[1], newbatch[1], std::array<u64,1>{v_c9}, std::array<u16,1>{0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("tycheck_basic.slog:15", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask46(db,b));
  // (crule (pre (let __tconst7ATK8 const2bc983a5942276eb00a75e21) (let __tconst27BW6 const20c400557af0eddc0be4d9e0)) (scan app __t3l7e10 __t6ZoD9 __t0x5D7) (body (join lam (0 1) 2 __t0x5D7 __tconst27BW6) (join lam (0 1) 2 __t6ZoD9 __tconst7ATK8)) (head (emit flow (0) __t3l7e10)) tycheck_basic.slog:15 #f)
  class ReadTask64 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** lamindex62;  slog::Index** lamindex63;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("flow");
      std::vector<u16> ord65({0});
      slog::Relation* readrel66 = db->getRelation("flow");
      head_index[0] = readrel66->getIndex(ord65, false);
      outer_rel = db->getRelation("app");
      std::vector<u16> ord67({0, 1});
      slog::Relation* readrel68 = db->getRelation("lam");
      lamindex62 = readrel68->getIndex(ord67, false);
      std::vector<u16> ord69({0, 1});
      slog::Relation* readrel70 = db->getRelation("lam");
      lamindex63 = readrel70->getIndex(ord69, false);
  
    }
    ReadTask64(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const2bc983a5942276eb00a75e21;
      u64 v_c1 = v_const20c400557af0eddc0be4d9e0;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c4 = _t[0];
        u64 v_c3 = _t[1];
        u64 v_c2 = _t[2];
        slog::join_probe<2,2>(lamindex62, std::array<u64,2>{v_c2, v_c1}, [&](const std::array<u64,2>& m71) {
          slog::join_probe<2,2>(lamindex63, std::array<u64,2>{v_c3, v_c0}, [&](const std::array<u64,2>& m72) {
            ++_fires;
            slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c4}, std::array<u16,1>{0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("tycheck_basic.slog:15", "delta:app", _fires);
  
      if (!_done)
      {
        ReadTask64* _cont = new ReadTask64(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask64(db,b), false);
  s->addReadRel("app");
  s->addReadRel("lam");
  s->addDynamicRel("app");
  s->addDynamicRel("flow");
  s->addDynamicRel("lam");
  s->addDynamicRel("raw");
  d->push(s);
  d->continueRun();
}

