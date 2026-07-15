
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const4e07408562bedb8b60ce05c1;
u64 v_const4b227777d4dd1fc61c6f884f;
u64 v_constef2d127de37b942baad06145;
u64 v_const47dbebec5d6543d84309f992;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("b4905825");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const4e07408562bedb8b60ce05c1 = s32_encode(3);
  v_const4b227777d4dd1fc61c6f884f = s32_encode(4);
  v_constef2d127de37b942baad06145 = s32_encode(5);
  v_const47dbebec5d6543d84309f992 = db->encodeString("nothing");
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord49({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord49, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord50({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord50, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord51({1, 2, 0});
    
    r->addIndex<3>(ord51, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord52({0, 1, 2});
    
    r->addIndex<3>(ord52, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("square");
  if (r == 0) db->addStruct("square", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("square");
      std::vector<u16> ord53({1, 0});
    
    r->addIndex<2>(ord53, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord54({0, 1});
    
    r->addIndex<2>(ord54, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("square"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord55({1, 2, 0});
    
    r->addIndex<3>(ord55, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord56({0, 1, 2});
    
    r->addIndex<3>(ord56, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord57({1, 2, 3, 0});
    
    r->addIndex<4>(ord57, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord58({0, 1, 2, 3});
    
    r->addIndex<4>(ord58, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord59({1, 2, 0});
    
    r->addIndex<3>(ord59, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord60({0, 1, 2});
    
    r->addIndex<3>(ord60, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord61({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord61, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord62({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord62, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord63({1, 2, 0});
    
    r->addIndex<3>(ord63, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord64({0, 1, 2});
    
    r->addIndex<3>(ord64, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord65({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord65, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord66({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord66, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord67({1, 2, 3, 0});
    
    r->addIndex<4>(ord67, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord68({0, 1, 2, 3});
    
    r->addIndex<4>(ord68, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord69({0});
    
    r->addIndex<1>(ord69, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("empty_seen");
  if (r == 0) db->addRelation("empty_seen", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("empty_seen");
      std::vector<u16> ord70({0});
    
    r->addIndex<1>(ord70, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("empty_seen"), std::array<u16,1>{0}, b));
  r = db->getRelation("drawn");
  if (r == 0) db->addRelation("drawn", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("drawn");
      std::vector<u16> ord71({0});
    
    r->addIndex<1>(ord71, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("drawn"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord72({1, 2, 0});
    
    r->addIndex<3>(ord72, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord73({0, 1, 2});
    
    r->addIndex<3>(ord73, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("circles");
  if (r == 0) db->addRelation("circles", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("circles");
      std::vector<u16> ord74({0});
    
    r->addIndex<1>(ord74, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("circles"), std::array<u16,1>{0}, b));
  r = db->getRelation("circle");
  if (r == 0) db->addStruct("circle", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("circle");
      std::vector<u16> ord75({1, 0});
    
    r->addIndex<2>(ord75, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord76({0, 1});
    
    r->addIndex<2>(ord76, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord77({1, 0});
    
    r->addIndex<2>(ord77, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("circle"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("circ_r");
  if (r == 0) db->addRelation("circ_r", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("circ_r");
      std::vector<u16> ord78({0});
    
    r->addIndex<1>(ord78, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("circ_r"), std::array<u16,1>{0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord79({1, 0});
    
    r->addIndex<2>(ord79, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord80({0, 1});
    
    r->addIndex<2>(ord80, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord81({1, 0});
    
    r->addIndex<2>(ord81, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  // (crule (pre (let __tconst30LZ7 constef2d127de37b942baad06145) (let __tconst375N5 const4b227777d4dd1fc61c6f884f) (let __tconst2d5a3 const4e07408562bedb8b60ce05c1)) (seeded) (body (join circle (1 0) 1 __tconst2d5a3 __t8DiF4) (exists circle (1 0) 1 __tconst30LZ7) (join square (1 0) 1 __tconst375N5 __t11zh6) (join circle (1 0) 1 __tconst30LZ7 __t6pDO8)) (head (emit drawn (0) __t6pDO8) (emit drawn (0) __t11zh6) (emit drawn (0) __t8DiF4)) enum_union_direct.slog:12 #f)
  class ReadTask4 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
  
  
  
  
  
  
    slog::Index** circleindex0;  slog::Index** circleindex1;  slog::Index** squareindex2;  slog::Index** circleindex3;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("drawn");
      std::vector<u16> ord5({0});
      slog::Relation* readrel6 = db->getRelation("drawn");
      head_index[0] = readrel6->getIndex(ord5, false);
      head_rel[1] = db->getRelation("drawn");
      std::vector<u16> ord7({0});
      slog::Relation* readrel8 = db->getRelation("drawn");
      head_index[1] = readrel8->getIndex(ord7, false);
      head_rel[2] = db->getRelation("drawn");
      std::vector<u16> ord9({0});
      slog::Relation* readrel10 = db->getRelation("drawn");
      head_index[2] = readrel10->getIndex(ord9, false);
      std::vector<u16> ord11({1, 0});
      slog::Relation* readrel12 = db->getRelation("circle");
      circleindex0 = readrel12->getIndex(ord11, false);
      std::vector<u16> ord13({1, 0});
      slog::Relation* readrel14 = db->getRelation("circle");
      circleindex1 = readrel14->getIndex(ord13, false);
      std::vector<u16> ord15({1, 0});
      slog::Relation* readrel16 = db->getRelation("square");
      squareindex2 = readrel16->getIndex(ord15, false);
      std::vector<u16> ord17({1, 0});
      slog::Relation* readrel18 = db->getRelation("circle");
      circleindex3 = readrel18->getIndex(ord17, false);
  
    }
    ReadTask4(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_constef2d127de37b942baad06145;
      u64 v_c1 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c2 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(circleindex0, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m19) {
        u64 v_c3 = m19[1];
        if (!slog::exists_probe<2,1>(circleindex1, std::array<u64,2>{v_c0, 0})) return;
        slog::join_probe<2,1>(squareindex2, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m20) {
          u64 v_c4 = m20[1];
          slog::join_probe<2,1>(circleindex3, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m21) {
            u64 v_c5 = m21[1];
            ++_fires;
            slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c5}, std::array<u16,1>{0});
            slog::emit<1>(head_rel[1], head_index[1], newbatch[1], std::array<u64,1>{v_c4}, std::array<u16,1>{0});
            slog::emit<1>(head_rel[2], head_index[2], newbatch[2], std::array<u64,1>{v_c3}, std::array<u16,1>{0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("enum_union_direct.slog:12", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask4(db,b));
  // (crule (pre (let __tconst5sdz13 const47dbebec5d6543d84309f992) (let __tconst30LZ7 constef2d127de37b942baad06145) (let __tconst375N5 const4b227777d4dd1fc61c6f884f) (let __tconst2d5a3 const4e07408562bedb8b60ce05c1)) (probe _enum (1 0) 1 __tconst5sdz13 __t3cS19) (body) (head (emit drawn (0) __t3cS19) (mkstruct circle (1 0) __t6pDO8 __tconst30LZ7) (mkstruct square (1 0) __t11zh6 __tconst375N5) (mkstruct circle (1 0) __t8DiF4 __tconst2d5a3)) enum_union_direct.slog:12 #f)
  class ReadTask22 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[4];
    slog::Index** head_index[4];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("drawn");
      std::vector<u16> ord23({0});
      slog::Relation* readrel24 = db->getRelation("drawn");
      head_index[0] = readrel24->getIndex(ord23, false);
      head_rel[1] = db->getRelation("circle");
      head_rel[2] = db->getRelation("square");
      head_rel[3] = db->getRelation("circle");
      std::vector<u16> ord25({1, 0});
      slog::Relation* readrel26 = db->getRelation("_enum");
      driver_index = readrel26->getIndex(ord25, true);
  
    }
    ReadTask22(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c6 = v_const47dbebec5d6543d84309f992;
      u64 v_c0 = v_constef2d127de37b942baad06145;
      u64 v_c1 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c2 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[4];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
      newbatch[3] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c6, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m27) {
        u64 v_c7 = m27[1];
        if (buckethash(v_c7) != bucket) return;
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c7}, std::array<u16,1>{0});
        slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c0}, std::array<u16,2>{1, 0});
        slog::emit_struct<2>(head_rel[2], newbatch[2], std::array<u64,1>{v_c1}, std::array<u16,2>{1, 0});
        slog::emit_struct<2>(head_rel[3], newbatch[3], std::array<u64,1>{v_c2}, std::array<u16,2>{1, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
  
      if (_fires) db->bumpFires("enum_union_direct.slog:12", "all:_enum", _fires);
  
      if (!_done)
      {
        ReadTask22* _cont = new ReadTask22(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask22(db,b), true);
  // (crule (pre (let __tconst30LZ7 constef2d127de37b942baad06145) (let __tconst375N5 const4b227777d4dd1fc61c6f884f) (let __tconst2d5a3 const4e07408562bedb8b60ce05c1)) (probe circle (1 0) 1 __tconst2d5a3 __t8DiF4) (body (exists circle (1 0) 1 __tconst30LZ7) (join square (1 0) 1 __tconst375N5 __t11zh6) (join circle (1 0) 1 __tconst30LZ7 __t6pDO8)) (head (emit drawn (0) __t6pDO8) (emit drawn (0) __t11zh6) (emit drawn (0) __t8DiF4)) enum_union_direct.slog:12 #f)
  class ReadTask31 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** circleindex28;  slog::Index** squareindex29;  slog::Index** circleindex30;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("drawn");
      std::vector<u16> ord32({0});
      slog::Relation* readrel33 = db->getRelation("drawn");
      head_index[0] = readrel33->getIndex(ord32, false);
      head_rel[1] = db->getRelation("drawn");
      std::vector<u16> ord34({0});
      slog::Relation* readrel35 = db->getRelation("drawn");
      head_index[1] = readrel35->getIndex(ord34, false);
      head_rel[2] = db->getRelation("drawn");
      std::vector<u16> ord36({0});
      slog::Relation* readrel37 = db->getRelation("drawn");
      head_index[2] = readrel37->getIndex(ord36, false);
      std::vector<u16> ord38({1, 0});
      slog::Relation* readrel39 = db->getRelation("circle");
      driver_index = readrel39->getIndex(ord38, true);
      std::vector<u16> ord40({1, 0});
      slog::Relation* readrel41 = db->getRelation("circle");
      circleindex28 = readrel41->getIndex(ord40, false);
      std::vector<u16> ord42({1, 0});
      slog::Relation* readrel43 = db->getRelation("square");
      squareindex29 = readrel43->getIndex(ord42, false);
      std::vector<u16> ord44({1, 0});
      slog::Relation* readrel45 = db->getRelation("circle");
      circleindex30 = readrel45->getIndex(ord44, false);
  
    }
    ReadTask31(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_constef2d127de37b942baad06145;
      u64 v_c1 = v_const4b227777d4dd1fc61c6f884f;
      u64 v_c2 = v_const4e07408562bedb8b60ce05c1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c2, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m46) {
        u64 v_c3 = m46[1];
        if (buckethash(v_c3) != bucket) return;
        if (!slog::exists_probe<2,1>(circleindex28, std::array<u64,2>{v_c0, 0})) return;
        slog::join_probe<2,1>(squareindex29, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m47) {
          u64 v_c4 = m47[1];
          slog::join_probe<2,1>(circleindex30, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m48) {
            u64 v_c5 = m48[1];
            ++_fires;
            slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c5}, std::array<u16,1>{0});
            slog::emit<1>(head_rel[1], head_index[1], newbatch[1], std::array<u64,1>{v_c4}, std::array<u16,1>{0});
            slog::emit<1>(head_rel[2], head_index[2], newbatch[2], std::array<u64,1>{v_c3}, std::array<u16,1>{0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("enum_union_direct.slog:12", "delta:circle", _fires);
  
      if (!_done)
      {
        ReadTask31* _cont = new ReadTask31(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask31(db,b), false);
  s->addReadRel("_enum");
  s->addReadRel("circle");
  s->addReadRel("square");
  s->addDynamicRel("circle");
  s->addDynamicRel("drawn");
  s->addDynamicRel("square");
  d->push(s);
  d->continueRun();
}

