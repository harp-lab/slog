
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const6b86b273ff34fce19d6b804e;
u64 v_constd4735e3a265e16eee03f5971;
u64 v_const4e07408562bedb8b60ce05c1;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("54ce0c44");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  v_constd4735e3a265e16eee03f5971 = s32_encode(2);
  v_const4e07408562bedb8b60ce05c1 = s32_encode(3);
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord88({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord88, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord89({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord89, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord90({1, 2, 0});
    
    r->addIndex<3>(ord90, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord91({0, 1, 2});
    
    r->addIndex<3>(ord91, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("t");
  if (r == 0) db->addRelation("t", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("t");
      std::vector<u16> ord92({0});
    
    r->addIndex<1>(ord92, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("t"), std::array<u16,1>{0}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord93({1, 2, 0});
    
    r->addIndex<3>(ord93, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord94({0, 1, 2});
    
    r->addIndex<3>(ord94, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("samepair");
  if (r == 0) db->addRelation("samepair", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("samepair");
      std::vector<u16> ord95({0});
    
    r->addIndex<1>(ord95, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("samepair"), std::array<u16,1>{0}, b));
  r = db->getRelation("node");
  if (r == 0) db->addStruct("node", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("node");
      std::vector<u16> ord96({1, 2, 0});
    
    r->addIndex<3>(ord96, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord97({0, 1, 2});
    
    r->addIndex<3>(ord97, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
      std::vector<u16> ord98({2, 0, 1});
    
    r->addIndex<3>(ord98, false, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTaskSeeded(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{2, 0, 1}, false, b));
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("node"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord99({1, 2, 3, 0});
    
    r->addIndex<4>(ord99, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord100({0, 1, 2, 3});
    
    r->addIndex<4>(ord100, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord101({1, 2, 0});
    
    r->addIndex<3>(ord101, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord102({0, 1, 2});
    
    r->addIndex<3>(ord102, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord103({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord103, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord104({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord104, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord105({1, 2, 0});
    
    r->addIndex<3>(ord105, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord106({0, 1, 2});
    
    r->addIndex<3>(ord106, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord107({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord107, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord108({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord108, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("lefts");
  if (r == 0) db->addRelation("lefts", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("lefts");
      std::vector<u16> ord109({0});
    
    r->addIndex<1>(ord109, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("lefts"), std::array<u16,1>{0}, b));
  r = db->getRelation("leaf2");
  if (r == 0) db->addStruct("leaf2", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("leaf2");
      std::vector<u16> ord110({1, 0});
    
    r->addIndex<2>(ord110, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord111({0, 1});
    
    r->addIndex<2>(ord111, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
      std::vector<u16> ord112({1, 0});
    
    r->addIndex<2>(ord112, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("leaf2"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord113({1, 2, 3, 0});
    
    r->addIndex<4>(ord113, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord114({0, 1, 2, 3});
    
    r->addIndex<4>(ord114, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord115({0});
    
    r->addIndex<1>(ord115, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord116({1, 2, 0});
    
    r->addIndex<3>(ord116, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord117({0, 1, 2});
    
    r->addIndex<3>(ord117, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("both");
  if (r == 0) db->addRelation("both", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("both");
      std::vector<u16> ord118({0, 1, 2});
    
    r->addIndex<3>(ord118, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("both"), std::array<u16,3>{0, 1, 2}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord119({1, 0});
    
    r->addIndex<2>(ord119, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord120({0, 1});
    
    r->addIndex<2>(ord120, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  // (crule (pre (let __tconst0YKh11 const4e07408562bedb8b60ce05c1) (let __tconst4SqU6 const6b86b273ff34fce19d6b804e) (let __tconst4P4P4 constd4735e3a265e16eee03f5971)) (probe leaf2 (1 0) 1 __tconst4P4P4 __t4AGs5) (body (exists leaf2 (1 0) 1 __tconst0YKh11) (join leaf2 (1 0) 1 __tconst4SqU6 __t4vma7) (join leaf2 (1 0) 1 __tconst0YKh11 __t5BzA10)) (head (mkstruct node (1 2 0) __t5SM213 __t5BzA10 __t5BzA10) (mkstruct node (1 2 0) __t9wOt8 __t4vma7 __t4AGs5)) sdeep_idbind.slog:13 #f)
  class ReadTask3 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,2> resume_key{};
    bool has_resume = false;
    slog::Index** leaf2index0;  slog::Index** leaf2index1;  slog::Index** leaf2index2;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("node");
      head_rel[1] = db->getRelation("node");
      std::vector<u16> ord4({1, 0});
      slog::Relation* readrel5 = db->getRelation("leaf2");
      driver_index = readrel5->getIndex(ord4, true);
      std::vector<u16> ord6({1, 0});
      slog::Relation* readrel7 = db->getRelation("leaf2");
      leaf2index0 = readrel7->getIndex(ord6, false);
      std::vector<u16> ord8({1, 0});
      slog::Relation* readrel9 = db->getRelation("leaf2");
      leaf2index1 = readrel9->getIndex(ord8, false);
      std::vector<u16> ord10({1, 0});
      slog::Relation* readrel11 = db->getRelation("leaf2");
      leaf2index2 = readrel11->getIndex(ord10, false);
  
    }
    ReadTask3(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c1 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c2 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,2> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<2,1>(driver_index, std::array<u64,2>{v_c2, 0}, _sc, _rkey, _hr, [&](const std::array<u64,2>& m12) {
        u64 v_c3 = m12[1];
        if (buckethash(v_c3) != bucket) return;
        if (!slog::exists_probe<2,1>(leaf2index0, std::array<u64,2>{v_c0, 0})) return;
        slog::join_probe<2,1>(leaf2index1, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m13) {
          u64 v_c4 = m13[1];
          slog::join_probe<2,1>(leaf2index2, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m14) {
            u64 v_c5 = m14[1];
            ++_fires;
            slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c5, v_c5}, std::array<u16,3>{1, 2, 0});
            slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c4, v_c3}, std::array<u16,3>{1, 2, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("sdeep_idbind.slog:13", "delta:leaf2", _fires);
  
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
  // (crule (pre (let __tconst0YKh11 const4e07408562bedb8b60ce05c1) (let __tconst4SqU6 const6b86b273ff34fce19d6b804e) (let __tconst4P4P4 constd4735e3a265e16eee03f5971)) (once) (body) (head (mkstruct leaf2 (1 0) __t5BzA10 __tconst0YKh11) (mkstruct leaf2 (1 0) __t4vma7 __tconst4SqU6) (mkstruct leaf2 (1 0) __t4AGs5 __tconst4P4P4)) sdeep_idbind.slog:13 #f)
  class ReadTask15 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
  
  
  
  
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("leaf2");
      head_rel[1] = db->getRelation("leaf2");
      head_rel[2] = db->getRelation("leaf2");
  
    }
    ReadTask15(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c1 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c2 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[3];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
      newbatch[2] = new slog::InsertBatch();
  
      ++_fires;
      slog::emit_struct<2>(head_rel[0], newbatch[0], std::array<u64,1>{v_c0}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c1}, std::array<u16,2>{1, 0});
      slog::emit_struct<2>(head_rel[2], newbatch[2], std::array<u64,1>{v_c2}, std::array<u16,2>{1, 0});
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("sdeep_idbind.slog:13", "once", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTask(phase_read, new ReadTask15(db,b), true);
  // (crule (pre (let __tconst0YKh11 const4e07408562bedb8b60ce05c1) (let __tconst4SqU6 const6b86b273ff34fce19d6b804e) (let __tconst4P4P4 constd4735e3a265e16eee03f5971)) (scan node __t9wOt8 __t4vma7 __t4AGs5) (body (join leaf2 (0 1) 2 __t4AGs5 __tconst4P4P4) (join leaf2 (0 1) 2 __t4vma7 __tconst4SqU6) (join leaf2 (1 0) 1 __tconst0YKh11 __t5BzA10) (join node (1 2 0) 1 __t5BzA10 dup5YP518 __t5SM213) (eq __t5BzA10 dup5YP518)) (head (emit t (0) __t5SM213) (emit t (0) __t9wOt8)) sdeep_idbind.slog:13 #f)
  class ReadTask20 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** leaf2index16;  slog::Index** leaf2index17;  slog::Index** leaf2index18;  slog::Index** nodeindex19;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("t");
      std::vector<u16> ord21({0});
      slog::Relation* readrel22 = db->getRelation("t");
      head_index[0] = readrel22->getIndex(ord21, false);
      head_rel[1] = db->getRelation("t");
      std::vector<u16> ord23({0});
      slog::Relation* readrel24 = db->getRelation("t");
      head_index[1] = readrel24->getIndex(ord23, false);
      outer_rel = db->getRelation("node");
      std::vector<u16> ord25({0, 1});
      slog::Relation* readrel26 = db->getRelation("leaf2");
      leaf2index16 = readrel26->getIndex(ord25, false);
      std::vector<u16> ord27({0, 1});
      slog::Relation* readrel28 = db->getRelation("leaf2");
      leaf2index17 = readrel28->getIndex(ord27, false);
      std::vector<u16> ord29({1, 0});
      slog::Relation* readrel30 = db->getRelation("leaf2");
      leaf2index18 = readrel30->getIndex(ord29, false);
      std::vector<u16> ord31({1, 2, 0});
      slog::Relation* readrel32 = db->getRelation("node");
      nodeindex19 = readrel32->getIndex(ord31, false);
  
    }
    ReadTask20(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c1 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c2 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c6 = _t[0];
        u64 v_c4 = _t[1];
        u64 v_c3 = _t[2];
        slog::join_probe<2,2>(leaf2index16, std::array<u64,2>{v_c3, v_c2}, [&](const std::array<u64,2>& m33) {
          slog::join_probe<2,2>(leaf2index17, std::array<u64,2>{v_c4, v_c1}, [&](const std::array<u64,2>& m34) {
            slog::join_probe<2,1>(leaf2index18, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m35) {
              u64 v_c5 = m35[1];
              slog::join_probe<3,1>(nodeindex19, std::array<u64,3>{v_c5, 0, 0}, [&](const std::array<u64,3>& m36) {
                u64 v_c7 = m36[1]; u64 v_c8 = m36[2];
                if (v_c5 != v_c7) return;
                ++_fires;
                slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c8}, std::array<u16,1>{0});
                slog::emit<1>(head_rel[1], head_index[1], newbatch[1], std::array<u64,1>{v_c6}, std::array<u16,1>{0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("sdeep_idbind.slog:13", "delta:node", _fires);
  
      if (!_done)
      {
        ReadTask20* _cont = new ReadTask20(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask20(db,b), false);
  // (crule (pre (let __tconst0YKh11 const4e07408562bedb8b60ce05c1) (let __tconst4SqU6 const6b86b273ff34fce19d6b804e) (let __tconst4P4P4 constd4735e3a265e16eee03f5971)) (seeded) (body (join leaf2 (1 0) 1 __tconst4P4P4 __t4AGs5) (exists leaf2 (1 0) 1 __tconst0YKh11) (join leaf2 (1 0) 1 __tconst4SqU6 __t4vma7) (join leaf2 (1 0) 1 __tconst0YKh11 __t5BzA10)) (head (mkstruct node (1 2 0) __t5SM213 __t5BzA10 __t5BzA10) (mkstruct node (1 2 0) __t9wOt8 __t4vma7 __t4AGs5)) sdeep_idbind.slog:13 #f)
  class ReadTask41 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
  
  
  
  
  
    slog::Index** leaf2index37;  slog::Index** leaf2index38;  slog::Index** leaf2index39;  slog::Index** leaf2index40;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("node");
      std::vector<u16> ord42({1, 2, 0});
      slog::Relation* readrel43 = db->getRelation("node");
      head_index[0] = readrel43->getIndex(ord42, false);
      head_rel[1] = db->getRelation("node");
      std::vector<u16> ord44({1, 2, 0});
      slog::Relation* readrel45 = db->getRelation("node");
      head_index[1] = readrel45->getIndex(ord44, false);
      std::vector<u16> ord46({1, 0});
      slog::Relation* readrel47 = db->getRelation("leaf2");
      leaf2index37 = readrel47->getIndex(ord46, false);
      std::vector<u16> ord48({1, 0});
      slog::Relation* readrel49 = db->getRelation("leaf2");
      leaf2index38 = readrel49->getIndex(ord48, false);
      std::vector<u16> ord50({1, 0});
      slog::Relation* readrel51 = db->getRelation("leaf2");
      leaf2index39 = readrel51->getIndex(ord50, false);
      std::vector<u16> ord52({1, 0});
      slog::Relation* readrel53 = db->getRelation("leaf2");
      leaf2index40 = readrel53->getIndex(ord52, false);
  
    }
    ReadTask41(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c1 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c2 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(leaf2index37, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m54) {
        u64 v_c3 = m54[1];
        if (!slog::exists_probe<2,1>(leaf2index38, std::array<u64,2>{v_c0, 0})) return;
        slog::join_probe<2,1>(leaf2index39, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m55) {
          u64 v_c4 = m55[1];
          slog::join_probe<2,1>(leaf2index40, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m56) {
            u64 v_c5 = m56[1];
            ++_fires;
            slog::emit_struct_checked<3>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c5, v_c5}, std::array<u16,3>{1, 2, 0});
            slog::emit_struct_checked<3>(head_rel[1], head_index[1], newbatch[1], std::array<u64,2>{v_c4, v_c3}, std::array<u16,3>{1, 2, 0});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("sdeep_idbind.slog:13", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask41(db,b));
  // (crule (pre (let __tconst0YKh11 const4e07408562bedb8b60ce05c1) (let __tconst4SqU6 const6b86b273ff34fce19d6b804e) (let __tconst4P4P4 constd4735e3a265e16eee03f5971)) (seeded) (body (join leaf2 (1 0) 1 __tconst4P4P4 __t4AGs5) (exists node (2 0 1) 1 __t4AGs5) (exists leaf2 (1 0) 1 __tconst0YKh11) (join leaf2 (1 0) 1 __tconst4SqU6 __t4vma7) (join node (1 2 0) 2 __t4vma7 __t4AGs5 __t9wOt8) (join leaf2 (1 0) 1 __tconst0YKh11 __t5BzA10) (join node (1 2 0) 1 __t5BzA10 dup04iK19 __t5SM213) (eq __t5BzA10 dup04iK19)) (head (emit t (0) __t5SM213) (emit t (0) __t9wOt8)) sdeep_idbind.slog:13 #f)
  class ReadTask64 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
  
  
  
  
  
    slog::Index** leaf2index57;  slog::Index** nodeindex58;  slog::Index** leaf2index59;  slog::Index** leaf2index60;  slog::Index** nodeindex61;  slog::Index** leaf2index62;  slog::Index** nodeindex63;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("t");
      std::vector<u16> ord65({0});
      slog::Relation* readrel66 = db->getRelation("t");
      head_index[0] = readrel66->getIndex(ord65, false);
      head_rel[1] = db->getRelation("t");
      std::vector<u16> ord67({0});
      slog::Relation* readrel68 = db->getRelation("t");
      head_index[1] = readrel68->getIndex(ord67, false);
      std::vector<u16> ord69({1, 0});
      slog::Relation* readrel70 = db->getRelation("leaf2");
      leaf2index57 = readrel70->getIndex(ord69, false);
      std::vector<u16> ord71({2, 0, 1});
      slog::Relation* readrel72 = db->getRelation("node");
      nodeindex58 = readrel72->getIndex(ord71, false);
      std::vector<u16> ord73({1, 0});
      slog::Relation* readrel74 = db->getRelation("leaf2");
      leaf2index59 = readrel74->getIndex(ord73, false);
      std::vector<u16> ord75({1, 0});
      slog::Relation* readrel76 = db->getRelation("leaf2");
      leaf2index60 = readrel76->getIndex(ord75, false);
      std::vector<u16> ord77({1, 2, 0});
      slog::Relation* readrel78 = db->getRelation("node");
      nodeindex61 = readrel78->getIndex(ord77, false);
      std::vector<u16> ord79({1, 0});
      slog::Relation* readrel80 = db->getRelation("leaf2");
      leaf2index62 = readrel80->getIndex(ord79, false);
      std::vector<u16> ord81({1, 2, 0});
      slog::Relation* readrel82 = db->getRelation("node");
      nodeindex63 = readrel82->getIndex(ord81, false);
  
    }
    ReadTask64(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const4e07408562bedb8b60ce05c1;
      u64 v_c1 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c2 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(leaf2index57, std::array<u64,2>{v_c2, 0}, [&](const std::array<u64,2>& m83) {
        u64 v_c3 = m83[1];
        if (!slog::exists_probe<3,1>(nodeindex58, std::array<u64,3>{v_c3, 0, 0})) return;
        if (!slog::exists_probe<2,1>(leaf2index59, std::array<u64,2>{v_c0, 0})) return;
        slog::join_probe<2,1>(leaf2index60, std::array<u64,2>{v_c1, 0}, [&](const std::array<u64,2>& m84) {
          u64 v_c4 = m84[1];
          slog::join_probe<3,2>(nodeindex61, std::array<u64,3>{v_c4, v_c3, 0}, [&](const std::array<u64,3>& m85) {
            u64 v_c6 = m85[2];
            slog::join_probe<2,1>(leaf2index62, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m86) {
              u64 v_c5 = m86[1];
              slog::join_probe<3,1>(nodeindex63, std::array<u64,3>{v_c5, 0, 0}, [&](const std::array<u64,3>& m87) {
                u64 v_c9 = m87[1]; u64 v_c8 = m87[2];
                if (v_c5 != v_c9) return;
                ++_fires;
                slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c8}, std::array<u16,1>{0});
                slog::emit<1>(head_rel[1], head_index[1], newbatch[1], std::array<u64,1>{v_c6}, std::array<u16,1>{0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("sdeep_idbind.slog:13", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask64(db,b));
  s->addReadRel("leaf2");
  s->addReadRel("node");
  s->addDynamicRel("leaf2");
  s->addDynamicRel("node");
  s->addDynamicRel("t");
  d->push(s);
  d->continueRun();
}

