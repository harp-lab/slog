
#include "../daemon/daemon.h"
#include "../daemon/operators.h"




extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("4d37cad0");
  if (s == nullptr) return;
  slog::Relation* r;
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord47({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord47, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord48({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord48, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord49({1, 2, 0});
    
    r->addIndex<3>(ord49, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord50({0, 1, 2});
    
    r->addIndex<3>(ord50, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("t");
  if (r == 0) db->addRelation("t", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("t");
      std::vector<u16> ord51({0});
    
    r->addIndex<1>(ord51, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("t"), std::array<u16,1>{0}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord52({1, 2, 0});
    
    r->addIndex<3>(ord52, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord53({0, 1, 2});
    
    r->addIndex<3>(ord53, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord54({1, 2, 3, 0});
    
    r->addIndex<4>(ord54, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord55({0, 1, 2, 3});
    
    r->addIndex<4>(ord55, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord56({1, 2, 0});
    
    r->addIndex<3>(ord56, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord57({0, 1, 2});
    
    r->addIndex<3>(ord57, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord58({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord58, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord59({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord59, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord60({1, 2, 0});
    
    r->addIndex<3>(ord60, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord61({0, 1, 2});
    
    r->addIndex<3>(ord61, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord62({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord62, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord63({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord63, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord64({1, 2, 3, 0});
    
    r->addIndex<4>(ord64, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord65({0, 1, 2, 3});
    
    r->addIndex<4>(ord65, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord66({0});
    
    r->addIndex<1>(ord66, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord67({1, 2, 0});
    
    r->addIndex<3>(ord67, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord68({0, 1, 2});
    
    r->addIndex<3>(ord68, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("corners");
  if (r == 0) db->addRelation("corners", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("corners");
      std::vector<u16> ord69({0, 1});
    
    r->addIndex<2>(ord69, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("corners"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord70({1, 0});
    
    r->addIndex<2>(ord70, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord71({0, 1});
    
    r->addIndex<2>(ord71, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("Nd");
  if (r == 0) db->addStruct("Nd", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("Nd");
      std::vector<u16> ord72({1, 2, 0});
    
    r->addIndex<3>(ord72, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord73({0, 1, 2});
    
    r->addIndex<3>(ord73, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("Nd"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("Lf");
  if (r == 0) db->addStruct("Lf", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("Lf");
      std::vector<u16> ord74({1, 0});
    
    r->addIndex<2>(ord74, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord75({0, 1});
    
    r->addIndex<2>(ord75, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("Lf"), std::array<u16,2>{1, 0}, b));
  // (crule (pre) (scan t __t9vhV11) (body (join Nd (0 1 2) 1 __t9vhV11 __t3lcP10 __t7gJo5) (join Nd (0 1 2) 1 __t3lcP10 __t1Jy89 ____3Cml12) (join Nd (0 1 2) 1 __t1Jy89 __t59d88 ____8ESo13) (join Nd (0 1 2) 1 __t59d88 __t5NME7 ____8JOC14) (join Nd (0 1 2) 1 __t5NME7 __t5xrg6 ____88t015) (join Lf (0 1) 1 __t5xrg6 a) (join Nd (0 1 2) 1 __t7gJo5 ____4ZLA16 __t1p4d4) (join Nd (0 1 2) 1 __t1p4d4 ____4X1817 __t9P0v3) (join Nd (0 1 2) 1 __t9P0v3 ____9TgH18 __t8cVD2) (join Nd (0 1 2) 1 __t8cVD2 ____9P6k19 __t1ufI1) (join Lf (0 1) 1 __t1ufI1 b)) (head (emit corners (0 1) a b)) deep_fact.slog:11 #f)
  class ReadTask11 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** Ndindex0;  slog::Index** Ndindex1;  slog::Index** Ndindex2;  slog::Index** Ndindex3;  slog::Index** Ndindex4;  slog::Index** Lfindex5;  slog::Index** Ndindex6;  slog::Index** Ndindex7;  slog::Index** Ndindex8;  slog::Index** Ndindex9;  slog::Index** Lfindex10;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("corners");
      std::vector<u16> ord12({0, 1});
      slog::Relation* readrel13 = db->getRelation("corners");
      head_index[0] = readrel13->getIndex(ord12, false);
      outer_rel = db->getRelation("t");
      std::vector<u16> ord14({0, 1, 2});
      slog::Relation* readrel15 = db->getRelation("Nd");
      Ndindex0 = readrel15->getIndex(ord14, false);
      std::vector<u16> ord16({0, 1, 2});
      slog::Relation* readrel17 = db->getRelation("Nd");
      Ndindex1 = readrel17->getIndex(ord16, false);
      std::vector<u16> ord18({0, 1, 2});
      slog::Relation* readrel19 = db->getRelation("Nd");
      Ndindex2 = readrel19->getIndex(ord18, false);
      std::vector<u16> ord20({0, 1, 2});
      slog::Relation* readrel21 = db->getRelation("Nd");
      Ndindex3 = readrel21->getIndex(ord20, false);
      std::vector<u16> ord22({0, 1, 2});
      slog::Relation* readrel23 = db->getRelation("Nd");
      Ndindex4 = readrel23->getIndex(ord22, false);
      std::vector<u16> ord24({0, 1});
      slog::Relation* readrel25 = db->getRelation("Lf");
      Lfindex5 = readrel25->getIndex(ord24, false);
      std::vector<u16> ord26({0, 1, 2});
      slog::Relation* readrel27 = db->getRelation("Nd");
      Ndindex6 = readrel27->getIndex(ord26, false);
      std::vector<u16> ord28({0, 1, 2});
      slog::Relation* readrel29 = db->getRelation("Nd");
      Ndindex7 = readrel29->getIndex(ord28, false);
      std::vector<u16> ord30({0, 1, 2});
      slog::Relation* readrel31 = db->getRelation("Nd");
      Ndindex8 = readrel31->getIndex(ord30, false);
      std::vector<u16> ord32({0, 1, 2});
      slog::Relation* readrel33 = db->getRelation("Nd");
      Ndindex9 = readrel33->getIndex(ord32, false);
      std::vector<u16> ord34({0, 1});
      slog::Relation* readrel35 = db->getRelation("Lf");
      Lfindex10 = readrel35->getIndex(ord34, false);
  
    }
    ReadTask11(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c0 = _t[0];
        slog::join_probe<3,1>(Ndindex0, std::array<u64,3>{v_c0, 0, 0}, [&](const std::array<u64,3>& m36) {
          u64 v_c1 = m36[1]; u64 v_c2 = m36[2];
          slog::join_probe<3,1>(Ndindex1, std::array<u64,3>{v_c1, 0, 0}, [&](const std::array<u64,3>& m37) {
            u64 v_c3 = m37[1]; u64 v_c4 = m37[2];
            slog::join_probe<3,1>(Ndindex2, std::array<u64,3>{v_c3, 0, 0}, [&](const std::array<u64,3>& m38) {
              u64 v_c5 = m38[1]; u64 v_c6 = m38[2];
              slog::join_probe<3,1>(Ndindex3, std::array<u64,3>{v_c5, 0, 0}, [&](const std::array<u64,3>& m39) {
                u64 v_c7 = m39[1]; u64 v_c8 = m39[2];
                slog::join_probe<3,1>(Ndindex4, std::array<u64,3>{v_c7, 0, 0}, [&](const std::array<u64,3>& m40) {
                  u64 v_c9 = m40[1]; u64 v_c10 = m40[2];
                  slog::join_probe<2,1>(Lfindex5, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m41) {
                    u64 v_c11 = m41[1];
                    slog::join_probe<3,1>(Ndindex6, std::array<u64,3>{v_c2, 0, 0}, [&](const std::array<u64,3>& m42) {
                      u64 v_c12 = m42[1]; u64 v_c13 = m42[2];
                      slog::join_probe<3,1>(Ndindex7, std::array<u64,3>{v_c13, 0, 0}, [&](const std::array<u64,3>& m43) {
                        u64 v_c14 = m43[1]; u64 v_c15 = m43[2];
                        slog::join_probe<3,1>(Ndindex8, std::array<u64,3>{v_c15, 0, 0}, [&](const std::array<u64,3>& m44) {
                          u64 v_c16 = m44[1]; u64 v_c17 = m44[2];
                          slog::join_probe<3,1>(Ndindex9, std::array<u64,3>{v_c17, 0, 0}, [&](const std::array<u64,3>& m45) {
                            u64 v_c18 = m45[1]; u64 v_c19 = m45[2];
                            slog::join_probe<2,1>(Lfindex10, std::array<u64,2>{v_c19, 0}, [&](const std::array<u64,2>& m46) {
                              u64 v_c20 = m46[1];
                              ++_fires;
                              slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c11, v_c20}, std::array<u16,2>{0, 1});
                            });
                          });
                        });
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
  
      if (_fires) db->bumpFires("deep_fact.slog:11", "all:t", _fires);
  
      if (!_done)
      {
        ReadTask11* _cont = new ReadTask11(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask11(db,b), true);
  s->addReadRel("Lf");
  s->addReadRel("Nd");
  s->addReadRel("t");
  s->addDynamicRel("corners");
  d->push(s);
  d->continueRun();
}

