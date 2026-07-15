
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_constcea17e0b05e3e6ace77ec2d1;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("5d5ae8a6");
  if (s == nullptr) return;
  slog::Relation* r;
  v_constcea17e0b05e3e6ace77ec2d1 = db->encodeString("False");
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord77({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord77, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord78({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord78, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord79({1, 2, 0});
    
    r->addIndex<3>(ord79, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord80({0, 1, 2});
    
    r->addIndex<3>(ord80, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord81({1, 2, 0});
    
    r->addIndex<3>(ord81, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord82({0, 1, 2});
    
    r->addIndex<3>(ord82, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("outB");
  if (r == 0) db->addRelation("outB", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("outB");
      std::vector<u16> ord83({0});
    
    r->addIndex<1>(ord83, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("outB"), std::array<u16,1>{0}, b));
  r = db->getRelation("outA");
  if (r == 0) db->addRelation("outA", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("outA");
      std::vector<u16> ord84({0});
    
    r->addIndex<1>(ord84, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("outA"), std::array<u16,1>{0}, b));
  r = db->getRelation("normB_ans");
  if (r == 0) db->addRelation("normB_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("normB_ans");
      std::vector<u16> ord85({0, 1});
    
    r->addIndex<2>(ord85, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("normB_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("normB");
  if (r == 0) db->addStruct("normB", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("normB");
      std::vector<u16> ord86({1, 0});
    
    r->addIndex<2>(ord86, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord87({0, 1});
    
    r->addIndex<2>(ord87, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("normB"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("normA_ans");
  if (r == 0) db->addRelation("normA_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("normA_ans");
      std::vector<u16> ord88({0, 1});
    
    r->addIndex<2>(ord88, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("normA_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("normA");
  if (r == 0) db->addStruct("normA", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("normA");
      std::vector<u16> ord89({1, 0});
    
    r->addIndex<2>(ord89, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord90({0, 1});
    
    r->addIndex<2>(ord90, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("normA"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord91({1, 2, 3, 0});
    
    r->addIndex<4>(ord91, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord92({0, 1, 2, 3});
    
    r->addIndex<4>(ord92, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord93({1, 2, 0});
    
    r->addIndex<3>(ord93, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord94({0, 1, 2});
    
    r->addIndex<3>(ord94, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord95({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord95, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord96({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord96, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord97({1, 2, 0});
    
    r->addIndex<3>(ord97, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord98({0, 1, 2});
    
    r->addIndex<3>(ord98, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord99({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord99, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord100({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord100, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("int_overflow");
  if (r == 0) db->addStruct("int_overflow", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("int_overflow");
      std::vector<u16> ord101({1, 2, 3, 0});
    
    r->addIndex<4>(ord101, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord102({0, 1, 2, 3});
    
    r->addIndex<4>(ord102, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("int_overflow"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("fdat");
  if (r == 0) db->addRelation("fdat", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("fdat");
      std::vector<u16> ord103({0});
    
    r->addIndex<1>(ord103, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("fdat"), std::array<u16,1>{0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord104({0});
    
    r->addIndex<1>(ord104, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord105({1, 2, 0});
    
    r->addIndex<3>(ord105, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord106({0, 1, 2});
    
    r->addIndex<3>(ord106, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord107({1, 0});
    
    r->addIndex<2>(ord107, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord108({0, 1});
    
    r->addIndex<2>(ord108, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("Wrap");
  if (r == 0) db->addStruct("Wrap", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("Wrap");
      std::vector<u16> ord109({1, 0});
    
    r->addIndex<2>(ord109, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord110({0, 1});
    
    r->addIndex<2>(ord110, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("Wrap"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("DInt");
  if (r == 0) db->addStruct("DInt", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("DInt");
      std::vector<u16> ord111({1, 0});
    
    r->addIndex<2>(ord111, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord112({0, 1});
    
    r->addIndex<2>(ord112, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("DInt"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("DBool");
  if (r == 0) db->addStruct("DBool", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("DBool");
      std::vector<u16> ord113({1, 0});
    
    r->addIndex<2>(ord113, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord114({0, 1});
    
    r->addIndex<2>(ord114, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("DBool"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("$sup87077x26x0x0x0");
  if (r == 0) db->addRelation("$sup87077x26x0x0x0", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup87077x26x0x0x0");
      std::vector<u16> ord115({1, 0, 2});
    
    r->addIndex<3>(ord115, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 0, 2}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$sup87077x26x0x0x0"), std::array<u16,3>{1, 0, 2}, b));
  // (crule (pre) (scan DInt __t1gGL2 n) (body (join normA (1 0) 1 __t1gGL2 __t3Pno3)) (head (emit normA_ans (0 1) __t3Pno3 __t1gGL2)) dem_neq_literal.slog:17 #f)
  class ReadTask1 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** normAindex0;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("normA_ans");
      std::vector<u16> ord2({0, 1});
      slog::Relation* readrel3 = db->getRelation("normA_ans");
      head_index[0] = readrel3->getIndex(ord2, false);
      outer_rel = db->getRelation("DInt");
      std::vector<u16> ord4({1, 0});
      slog::Relation* readrel5 = db->getRelation("normA");
      normAindex0 = readrel5->getIndex(ord4, false);
  
    }
    ReadTask1(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c1 = _t[1];
        slog::join_probe<2,1>(normAindex0, std::array<u64,2>{v_c0, 0}, [&](const std::array<u64,2>& m6) {
          u64 v_c2 = m6[1];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c2, v_c0}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_neq_literal.slog:17", "all:DInt", _fires);
  
      if (!_done)
      {
        ReadTask1* _cont = new ReadTask1(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1(db,b), true);
  // (crule (pre (let __tconst7UD275 constcea17e0b05e3e6ace77ec2d1)) (scan normA_ans __t075112 r) (body (join _enum (1 0) 1 __tconst7UD275 __t5qLr13) (join DBool (1 0) 1 __t5qLr13 __t1nJF14) (neq r __t1nJF14) (join normA (0 1) 1 __t075112 d) (join Wrap (1 0) 1 d __t7cVN10) (join normA (1 0) 1 __t7cVN10 __t3pez11)) (head (emit normA_ans (0 1) __t3pez11 r)) dem_neq_literal.slog:18 #f)
  class ReadTask12 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex7;  slog::Index** DBoolindex8;  slog::Index** normAindex9;  slog::Index** Wrapindex10;  slog::Index** normAindex11;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("normA_ans");
      std::vector<u16> ord13({0, 1});
      slog::Relation* readrel14 = db->getRelation("normA_ans");
      head_index[0] = readrel14->getIndex(ord13, false);
      outer_rel = db->getRelation("normA_ans");
      std::vector<u16> ord15({1, 0});
      slog::Relation* readrel16 = db->getRelation("_enum");
      _enumindex7 = readrel16->getIndex(ord15, false);
      std::vector<u16> ord17({1, 0});
      slog::Relation* readrel18 = db->getRelation("DBool");
      DBoolindex8 = readrel18->getIndex(ord17, false);
      std::vector<u16> ord19({0, 1});
      slog::Relation* readrel20 = db->getRelation("normA");
      normAindex9 = readrel20->getIndex(ord19, false);
      std::vector<u16> ord21({1, 0});
      slog::Relation* readrel22 = db->getRelation("Wrap");
      Wrapindex10 = readrel22->getIndex(ord21, false);
      std::vector<u16> ord23({1, 0});
      slog::Relation* readrel24 = db->getRelation("normA");
      normAindex11 = readrel24->getIndex(ord23, false);
  
    }
    ReadTask12(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c3 = v_constcea17e0b05e3e6ace77ec2d1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c4 = _t[0];
        u64 v_c5 = _t[1];
        slog::join_probe<2,1>(_enumindex7, std::array<u64,2>{v_c3, 0}, [&](const std::array<u64,2>& m25) {
          u64 v_c6 = m25[1];
          slog::join_probe<2,1>(DBoolindex8, std::array<u64,2>{v_c6, 0}, [&](const std::array<u64,2>& m26) {
            u64 v_c7 = m26[1];
            if (v_c5 == v_c7) return;
            slog::join_probe<2,1>(normAindex9, std::array<u64,2>{v_c4, 0}, [&](const std::array<u64,2>& m27) {
              u64 v_c8 = m27[1];
              slog::join_probe<2,1>(Wrapindex10, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m28) {
                u64 v_c9 = m28[1];
                slog::join_probe<2,1>(normAindex11, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m29) {
                  u64 v_c10 = m29[1];
                  ++_fires;
                  slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c10, v_c5}, std::array<u16,2>{0, 1});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_neq_literal.slog:18", "delta:normA_ans", _fires);
  
      if (!_done)
      {
        ReadTask12* _cont = new ReadTask12(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask12(db,b), false);
  // (crule (pre) (scan DBool __t697j35 b) (body (join normB (1 0) 1 __t697j35 __t3Cd336)) (head (emit normB_ans (0 1) __t3Cd336 __t697j35)) dem_neq_literal.slog:25 #f)
  class ReadTask31 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** normBindex30;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("normB_ans");
      std::vector<u16> ord32({0, 1});
      slog::Relation* readrel33 = db->getRelation("normB_ans");
      head_index[0] = readrel33->getIndex(ord32, false);
      outer_rel = db->getRelation("DBool");
      std::vector<u16> ord34({1, 0});
      slog::Relation* readrel35 = db->getRelation("normB");
      normBindex30 = readrel35->getIndex(ord34, false);
  
    }
    ReadTask31(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c11 = _t[0];
        u64 v_c12 = _t[1];
        slog::join_probe<2,1>(normBindex30, std::array<u64,2>{v_c11, 0}, [&](const std::array<u64,2>& m36) {
          u64 v_c13 = m36[1];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c13, v_c11}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_neq_literal.slog:25", "all:DBool", _fires);
  
      if (!_done)
      {
        ReadTask31* _cont = new ReadTask31(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask31(db,b), true);
  // (crule (pre) (scan normB_ans __t6oha51 r) (body (join normB (0 1) 1 __t6oha51 d) (exists $sup87077x26x0x0x0 (1 0 2) 1 d) (join Wrap (1 0) 1 d __t8dWV49) (join normB (1 0) 1 __t8dWV49 __t2r2x50) (join $sup87077x26x0x0x0 (1 0 2) 2 d __t2r2x50 fd) (neq r fd) (join fdat (0) 1 fd)) (head (emit normB_ans (0 1) __t2r2x50 r)) dem_neq_literal.slog:27 #f)
  class ReadTask43 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** normBindex37;  slog::Index** $sup87077x26x0x0x0index38;  slog::Index** Wrapindex39;  slog::Index** normBindex40;  slog::Index** $sup87077x26x0x0x0index41;  slog::Index** fdatindex42;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("normB_ans");
      std::vector<u16> ord44({0, 1});
      slog::Relation* readrel45 = db->getRelation("normB_ans");
      head_index[0] = readrel45->getIndex(ord44, false);
      outer_rel = db->getRelation("normB_ans");
      std::vector<u16> ord46({0, 1});
      slog::Relation* readrel47 = db->getRelation("normB");
      normBindex37 = readrel47->getIndex(ord46, false);
      std::vector<u16> ord48({1, 0, 2});
      slog::Relation* readrel49 = db->getRelation("$sup87077x26x0x0x0");
      $sup87077x26x0x0x0index38 = readrel49->getIndex(ord48, false);
      std::vector<u16> ord50({1, 0});
      slog::Relation* readrel51 = db->getRelation("Wrap");
      Wrapindex39 = readrel51->getIndex(ord50, false);
      std::vector<u16> ord52({1, 0});
      slog::Relation* readrel53 = db->getRelation("normB");
      normBindex40 = readrel53->getIndex(ord52, false);
      std::vector<u16> ord54({1, 0, 2});
      slog::Relation* readrel55 = db->getRelation("$sup87077x26x0x0x0");
      $sup87077x26x0x0x0index41 = readrel55->getIndex(ord54, false);
      std::vector<u16> ord56({0});
      slog::Relation* readrel57 = db->getRelation("fdat");
      fdatindex42 = readrel57->getIndex(ord56, false);
  
    }
    ReadTask43(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c14 = _t[0];
        u64 v_c5 = _t[1];
        slog::join_probe<2,1>(normBindex37, std::array<u64,2>{v_c14, 0}, [&](const std::array<u64,2>& m58) {
          u64 v_c8 = m58[1];
          if (!slog::exists_probe<3,1>($sup87077x26x0x0x0index38, std::array<u64,3>{v_c8, 0, 0})) return;
          slog::join_probe<2,1>(Wrapindex39, std::array<u64,2>{v_c8, 0}, [&](const std::array<u64,2>& m59) {
            u64 v_c15 = m59[1];
            slog::join_probe<2,1>(normBindex40, std::array<u64,2>{v_c15, 0}, [&](const std::array<u64,2>& m60) {
              u64 v_c16 = m60[1];
              slog::join_probe<3,2>($sup87077x26x0x0x0index41, std::array<u64,3>{v_c8, v_c16, 0}, [&](const std::array<u64,3>& m61) {
                u64 v_c17 = m61[2];
                if (v_c5 == v_c17) return;
                slog::join_probe<1,1>(fdatindex42, std::array<u64,1>{v_c17}, [&](const std::array<u64,1>& m62) {
                  ++_fires;
                  slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c16, v_c5}, std::array<u16,2>{0, 1});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_neq_literal.slog:27", "delta:normB_ans", _fires);
  
      if (!_done)
      {
        ReadTask43* _cont = new ReadTask43(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask43(db,b), false);
  // (crule (pre) (scan DBool __t4ZYg58 b) (body (join normA (1 0) 1 __t4ZYg58 __t8xKL59)) (head (emit normA_ans (0 1) __t8xKL59 __t4ZYg58)) dem_neq_literal.slog:16 #f)
  class ReadTask64 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** normAindex63;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("normA_ans");
      std::vector<u16> ord65({0, 1});
      slog::Relation* readrel66 = db->getRelation("normA_ans");
      head_index[0] = readrel66->getIndex(ord65, false);
      outer_rel = db->getRelation("DBool");
      std::vector<u16> ord67({1, 0});
      slog::Relation* readrel68 = db->getRelation("normA");
      normAindex63 = readrel68->getIndex(ord67, false);
  
    }
    ReadTask64(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c18 = _t[0];
        u64 v_c12 = _t[1];
        slog::join_probe<2,1>(normAindex63, std::array<u64,2>{v_c18, 0}, [&](const std::array<u64,2>& m69) {
          u64 v_c19 = m69[1];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c19, v_c18}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_neq_literal.slog:16", "all:DBool", _fires);
  
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
      s->addTask(phase_read, new ReadTask64(db,b), true);
  // (crule (pre) (scan DInt __t3K3555 n) (body (join normB (1 0) 1 __t3K3555 __t4BUJ56)) (head (emit normB_ans (0 1) __t4BUJ56 __t3K3555)) dem_neq_literal.slog:26 #f)
  class ReadTask71 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** normBindex70;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("normB_ans");
      std::vector<u16> ord72({0, 1});
      slog::Relation* readrel73 = db->getRelation("normB_ans");
      head_index[0] = readrel73->getIndex(ord72, false);
      outer_rel = db->getRelation("DInt");
      std::vector<u16> ord74({1, 0});
      slog::Relation* readrel75 = db->getRelation("normB");
      normBindex70 = readrel75->getIndex(ord74, false);
  
    }
    ReadTask71(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c20 = _t[0];
        u64 v_c1 = _t[1];
        slog::join_probe<2,1>(normBindex70, std::array<u64,2>{v_c20, 0}, [&](const std::array<u64,2>& m76) {
          u64 v_c21 = m76[1];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c21, v_c20}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("dem_neq_literal.slog:26", "all:DInt", _fires);
  
      if (!_done)
      {
        ReadTask71* _cont = new ReadTask71(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask71(db,b), true);
  s->addReadRel("$sup87077x26x0x0x0");
  s->addReadRel("DBool");
  s->addReadRel("DInt");
  s->addReadRel("Wrap");
  s->addReadRel("_enum");
  s->addReadRel("fdat");
  s->addReadRel("normA");
  s->addReadRel("normA_ans");
  s->addReadRel("normB");
  s->addReadRel("normB_ans");
  s->addDynamicRel("normA_ans");
  s->addDynamicRel("normB_ans");
  s->addAccelRel("normA_ans");
  s->addAccelRel("normB_ans");
  d->push(s);
  d->continueRun();
}

