
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


u64 v_const5feceb66ffc86f38d952786c;
u64 v_const6b86b273ff34fce19d6b804e;


extern "C" void slog_plugin(slog::Daemon* d)
{
  slog::Database* db = d->db();
  slog::Stratum* s = d->beginStratum("1a2be43b");
  if (s == nullptr) return;
  slog::Relation* r;
  v_const5feceb66ffc86f38d952786c = s32_encode(0);
  v_const6b86b273ff34fce19d6b804e = s32_encode(1);
  r = db->getRelation("type_mismatch");
  if (r == 0) db->addStruct("type_mismatch", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("type_mismatch");
      std::vector<u16> ord92({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord92, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord93({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord93, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("type_mismatch"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("total");
  if (r == 0) db->addRelation("total", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("total");
      std::vector<u16> ord94({0});
    
    r->addIndex<1>(ord94, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("total"), std::array<u16,1>{0}, b));
  r = db->getRelation("toint_range");
  if (r == 0) db->addStruct("toint_range", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("toint_range");
      std::vector<u16> ord95({1, 2, 0});
    
    r->addIndex<3>(ord95, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord96({0, 1, 2});
    
    r->addIndex<3>(ord96, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("toint_range"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("temp4rzj276");
  if (r == 0) db->addTempRelation("temp4rzj276", 2);
  else if (r->getArity() != 2) slog::fatal("Temp rel arity mismatch.");
  r = db->getRelation("sum_ans");
  if (r == 0) db->addRelation("sum_ans", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("sum_ans");
      std::vector<u16> ord97({0, 1});
    
    r->addIndex<2>(ord97, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<2>(db, db->getRelation("sum_ans"), std::array<u16,2>{0, 1}, b));
  r = db->getRelation("sum");
  if (r == 0) db->addStruct("sum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("sum");
      std::vector<u16> ord98({1, 0});
    
    r->addIndex<2>(ord98, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord99({0, 1});
    
    r->addIndex<2>(ord99, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("sum"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("smt_bad_formula");
  if (r == 0) db->addStruct("smt_bad_formula", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("smt_bad_formula");
      std::vector<u16> ord100({1, 2, 0});
    
    r->addIndex<3>(ord100, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord101({0, 1, 2});
    
    r->addIndex<3>(ord101, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("smt_bad_formula"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("pairs");
  if (r == 0) db->addRelation("pairs", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("pairs");
      std::vector<u16> ord102({0});
    
    r->addIndex<1>(ord102, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("pairs"), std::array<u16,1>{0}, b));
  r = db->getRelation("nan_result");
  if (r == 0) db->addStruct("nan_result", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("nan_result");
      std::vector<u16> ord103({1, 2, 3, 0});
    
    r->addIndex<4>(ord103, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{1, 2, 3, 0}, false, b), true);
      std::vector<u16> ord104({0, 1, 2, 3});
    
    r->addIndex<4>(ord104, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{0, 1, 2, 3}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<4>(db, db->getRelation("nan_result"), std::array<u16,4>{1, 2, 3, 0}, b));
  r = db->getRelation("mpz_table_overflow");
  if (r == 0) db->addStruct("mpz_table_overflow", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_table_overflow");
      std::vector<u16> ord105({1, 2, 0});
    
    r->addIndex<3>(ord105, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord106({0, 1, 2});
    
    r->addIndex<3>(ord106, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("mpz_table_overflow"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("mpz_overflow");
  if (r == 0) db->addStruct("mpz_overflow", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("mpz_overflow");
      std::vector<u16> ord107({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord107, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord108({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord108, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("mpz_overflow"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
  r = db->getRelation("modulo_by_zero");
  if (r == 0) db->addStruct("modulo_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("modulo_by_zero");
      std::vector<u16> ord109({1, 2, 0});
    
    r->addIndex<3>(ord109, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord110({0, 1, 2});
    
    r->addIndex<3>(ord110, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("modulo_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("malformed_deduction");
  if (r == 0) db->addStruct("malformed_deduction", 5);
  else if (r->getArity() != 5)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("malformed_deduction");
      std::vector<u16> ord111({1, 2, 3, 4, 0});
    
    r->addIndex<5>(ord111, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{1, 2, 3, 4, 0}, false, b), true);
      std::vector<u16> ord112({0, 1, 2, 3, 4});
    
    r->addIndex<5>(ord112, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<5>(db, r, std::array<u16,5>{0, 1, 2, 3, 4}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<5>(db, db->getRelation("malformed_deduction"), std::array<u16,5>{1, 2, 3, 4, 0}, b));
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
  r = db->getRelation("input");
  if (r == 0) db->addRelation("input", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("input");
      std::vector<u16> ord115({0});
    
    r->addIndex<1>(ord115, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("input"), std::array<u16,1>{0}, b));
  r = db->getRelation("heads");
  if (r == 0) db->addRelation("heads", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("heads");
      std::vector<u16> ord116({0});
    
    r->addIndex<1>(ord116, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("heads"), std::array<u16,1>{0}, b));
  r = db->getRelation("error");
  if (r == 0) db->addRelation("error", 1);
  else if (r->getArity() != 1)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("error");
      std::vector<u16> ord117({0});
    
    r->addIndex<1>(ord117, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<1>(db, r, std::array<u16,1>{0}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<1>(db, db->getRelation("error"), std::array<u16,1>{0}, b));
  r = db->getRelation("div_by_zero");
  if (r == 0) db->addStruct("div_by_zero", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("div_by_zero");
      std::vector<u16> ord118({1, 2, 0});
    
    r->addIndex<3>(ord118, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 2, 0}, false, b), true);
      std::vector<u16> ord119({0, 1, 2});
    
    r->addIndex<3>(ord119, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{0, 1, 2}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<3>(db, db->getRelation("div_by_zero"), std::array<u16,3>{1, 2, 0}, b));
  r = db->getRelation("_enum");
  if (r == 0) db->addStruct("_enum", 2);
  else if (r->getArity() != 2)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("_enum");
      std::vector<u16> ord120({1, 0});
    
    r->addIndex<2>(ord120, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{1, 0}, false, b), true);
      std::vector<u16> ord121({0, 1});
    
    r->addIndex<2>(ord121, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<2>(db, r, std::array<u16,2>{0, 1}, false, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternStructTask<2>(db, db->getRelation("_enum"), std::array<u16,2>{1, 0}, b));
  r = db->getRelation("$sup5242x12x0x0x0");
  if (r == 0) db->addRelation("$sup5242x12x0x0x0", 4);
  else if (r->getArity() != 4)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$sup5242x12x0x0x0");
      std::vector<u16> ord122({3, 0, 2, 1});
    
    r->addIndex<4>(ord122, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<4>(db, r, std::array<u16,4>{3, 0, 2, 1}, false, b), true);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<4>(db, db->getRelation("$sup5242x12x0x0x0"), std::array<u16,4>{3, 0, 2, 1}, b));
  r = db->getRelation("$seq_at");
  if (r == 0) db->addRelation("$seq_at", 3);
  else if (r->getArity() != 3)
    slog::fatal("Relation already exists at incorrect arity.");
  r = db->getRelation("$seq_at");
      std::vector<u16> ord123({1, 0, 2});
    
    r->addIndex<3>(ord123, false);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 0, 2}, false, b), true);
      std::vector<u16> ord124({1, 0, 2});
    
    r->addIndex<3>(ord124, true);
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_write, new slog::WriteTask<3>(db, r, std::array<u16,3>{1, 0, 2}, true, b), false);
  

  for (u16 b = 0; b < 32; ++b)
    s->addTask(phase_intern, new slog::InternTask<3>(db, db->getRelation("$seq_at"), std::array<u16,3>{1, 0, 2}, b));
  {
    std::vector<u16> seqcols({0});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("input"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({0});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("pairs"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  {
    std::vector<u16> seqcols({1});
    s->addTask(phase_write, new slog::SeqIndexTask(db, db->getRelation("sum"), seqcols, db->getRelation("$seq_at"), db->getRelation("$seq_atr")), false);
  }
  // (crule (pre (let _00024sqc8YJi30 const6b86b273ff34fce19d6b804e) (let _00024sqc5EFd31 const5feceb66ffc86f38d952786c) (let _00024sqc4j8S32 const6b86b273ff34fce19d6b804e) (let _00024sqc7Mbr33 const5feceb66ffc86f38d952786c) (let _00024sqo4qiz38 const5feceb66ffc86f38d952786c)) (scan sum_ans __t0LBx3 __v0) (body (exists $seq_at (1 0 2) 1 _00024sqo4qiz38) (join sum (0 1) 1 __t0LBx3 xs) (exists $sup5242x12x0x0x0 (3 0 2 1) 1 xs) (join-old $seq_at (1 0 2) 1 (1 0 2) _00024sqo4qiz38 x _00024seq0) (exists sum (1 0) 1 _00024seq0) (join $sup5242x12x0x0x0 (3 0 2 1) 3 xs _00024seq0 x __t2v0n2) (join sum (0 1) 2 __t2v0n2 _00024seq0) (letp _00024sql3ast28 (aslst _00024seq0)) (let _00024sqn4UXW29 (llen _00024sql3ast28)) (cmp ge _00024sqn4UXW29 _00024sqc8YJi30) (letp chk9iqL277 (lref _00024sql3ast28 _00024sqc5EFd31)) (eq x chk9iqL277) (let _00024sqp4Mi534 (_0002d _00024sqn4UXW29 _00024sqc7Mbr33)) (let chk1hMY278 (lslice _00024sql3ast28 _00024sqc4j8S32 _00024sqp4Mi534)) (eq xs chk1hMY278) (let __t7ODS1 (_0002b __v0 x))) (head (emit-temp temp4rzj276 __t2v0n2 __t7ODS1)) lst_typed.slog:13 #f)
  class ReadTask8 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $seq_atindex0;  slog::Index** sumindex1;  slog::Index** $sup5242x12x0x0x0index2;  slog::Index** $seq_atindex3;  slog::Index** sumindex4;  slog::Index** $sup5242x12x0x0x0index5;  slog::Index** sumindex6;  slog::Index** $seq_atdelta7;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4rzj276");
      outer_rel = db->getRelation("sum_ans");
      std::vector<u16> ord9({1, 0, 2});
      slog::Relation* readrel10 = db->getRelation("$seq_at");
      $seq_atindex0 = readrel10->getIndex(ord9, false);
      std::vector<u16> ord11({0, 1});
      slog::Relation* readrel12 = db->getRelation("sum");
      sumindex1 = readrel12->getIndex(ord11, false);
      std::vector<u16> ord13({3, 0, 2, 1});
      slog::Relation* readrel14 = db->getRelation("$sup5242x12x0x0x0");
      $sup5242x12x0x0x0index2 = readrel14->getIndex(ord13, false);
      std::vector<u16> ord15({1, 0, 2});
      slog::Relation* readrel16 = db->getRelation("$seq_at");
      $seq_atindex3 = readrel16->getIndex(ord15, false);
      std::vector<u16> ord17({1, 0, 2});
      slog::Relation* readrel18 = db->getRelation("$seq_at");
      $seq_atdelta7 = readrel18->getIndex(ord17, true);
      std::vector<u16> ord19({1, 0});
      slog::Relation* readrel20 = db->getRelation("sum");
      sumindex4 = readrel20->getIndex(ord19, false);
      std::vector<u16> ord21({3, 0, 2, 1});
      slog::Relation* readrel22 = db->getRelation("$sup5242x12x0x0x0");
      $sup5242x12x0x0x0index5 = readrel22->getIndex(ord21, false);
      std::vector<u16> ord23({0, 1});
      slog::Relation* readrel24 = db->getRelation("sum");
      sumindex6 = readrel24->getIndex(ord23, false);
  
    }
    ReadTask8(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c1 = v_const5feceb66ffc86f38d952786c;
      u64 v_c2 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c3 = v_const5feceb66ffc86f38d952786c;
      u64 v_c4 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c5 = _t[0];
        u64 v_c6 = _t[1];
        if (!slog::exists_probe<3,1>($seq_atindex0, std::array<u64,3>{v_c4, 0, 0})) return;
        slog::join_probe<2,1>(sumindex1, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m25) {
          u64 v_c7 = m25[1];
          if (!slog::exists_probe<4,1>($sup5242x12x0x0x0index2, std::array<u64,4>{v_c7, 0, 0, 0})) return;
          slog::join_probe_old<3,1>($seq_atindex3, $seq_atdelta7, std::array<u64,3>{v_c4, 0, 0}, [&](const std::array<u64,3>& m26) {
            u64 v_c8 = m26[1]; u64 v_c9 = m26[2];
            if (!slog::exists_probe<2,1>(sumindex4, std::array<u64,2>{v_c9, 0})) return;
            slog::join_probe<4,3>($sup5242x12x0x0x0index5, std::array<u64,4>{v_c7, v_c9, v_c8, 0}, [&](const std::array<u64,4>& m27) {
              u64 v_c10 = m27[3];
              slog::join_probe<2,2>(sumindex6, std::array<u64,2>{v_c10, v_c9}, [&](const std::array<u64,2>& m28) {
                bool ok29 = true;
                u64 v_c11 = _prim_aslst(db, v_c9, &ok29);
                if (!ok29) return;
                u64 v_c12 = _prim_llen(db, v_c11);
                if (v_c12 == slog_error) { slog::emit_pending_error(db, "lst_typed.slog:13"); return; }
                u64 v_c13 = _prim_ge(db, v_c12, v_c0);
                if (v_c13 == slog_error) { slog::emit_pending_error(db, "lst_typed.slog:13"); return; }
                if (!v_c13) return;
                bool ok31 = true;
                u64 v_c14 = _prim_lref(db, v_c11, v_c1, &ok31);
                if (!ok31) return;
                if (v_c8 != v_c14) return;
                u64 v_c15 = _prim__0002d(db, v_c12, v_c3);
                if (v_c15 == slog_error) { slog::emit_pending_error(db, "lst_typed.slog:13"); return; }
                u64 v_c16 = _prim_lslice(db, v_c11, v_c2, v_c15);
                if (v_c16 == slog_error) { slog::emit_pending_error(db, "lst_typed.slog:13"); return; }
                if (v_c7 != v_c16) return;
                u64 v_c17 = _prim__0002b(db, v_c6, v_c8);
                if (v_c17 == slog_error) { slog::emit_pending_error(db, "lst_typed.slog:13"); return; }
                ++_fires;
                slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c10, v_c17});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_typed.slog:13", "delta:sum_ans", _fires);
  
      if (!_done)
      {
        ReadTask8* _cont = new ReadTask8(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask8(db,b), false);
  // (crule (pre (let _00024sqc6jEi60 const5feceb66ffc86f38d952786c) (let __tconst7cx325 const5feceb66ffc86f38d952786c)) (scan sum __t3YrA26 _00024seq0) (body (letp _00024sql45ux58 (aslst _00024seq0)) (let chk4O0F280 (llen _00024sql45ux58)) (eq _00024sqc6jEi60 chk4O0F280)) (head (emit sum_ans (0 1) __t3YrA26 __tconst7cx325)) lst_typed.slog:12 #f)
  class ReadTask32 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("sum_ans");
      std::vector<u16> ord33({0, 1});
      slog::Relation* readrel34 = db->getRelation("sum_ans");
      head_index[0] = readrel34->getIndex(ord33, false);
      outer_rel = db->getRelation("sum");
  
    }
    ReadTask32(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c18 = v_const5feceb66ffc86f38d952786c;
      u64 v_c19 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c20 = _t[0];
        u64 v_c9 = _t[1];
        bool ok35 = true;
        u64 v_c21 = _prim_aslst(db, v_c9, &ok35);
        if (!ok35) return;
        u64 v_c22 = _prim_llen(db, v_c21);
        if (v_c22 == slog_error) { slog::emit_pending_error(db, "lst_typed.slog:12"); return; }
        if (v_c18 != v_c22) return;
        ++_fires;
        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c20, v_c19}, std::array<u16,2>{0, 1});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_typed.slog:12", "all:sum", _fires);
  
      if (!_done)
      {
        ReadTask32* _cont = new ReadTask32(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask32(db,b), true);
  // (crule (pre) (scan toint_range __erre2akp260 __errf0und261 __errf52ru262) (body) (head (emit error (0) __erre2akp260)) <internal>:1 #f)
  class ReadTask36 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("error");
      std::vector<u16> ord37({0});
      slog::Relation* readrel38 = db->getRelation("error");
      head_index[0] = readrel38->getIndex(ord37, false);
      outer_rel = db->getRelation("toint_range");
  
    }
    ReadTask36(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c23 = _t[0];
        u64 v_c24 = _t[1];
        u64 v_c25 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c23}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:toint_range", _fires);
  
      if (!_done)
      {
        ReadTask36* _cont = new ReadTask36(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask36(db,b), false);
  // (crule (pre) (scan mpz_table_overflow __erre7bEZ273 __errf6D4p274 __errf78hQ275) (body) (head (emit error (0) __erre7bEZ273)) <internal>:1 #f)
  class ReadTask39 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("error");
      std::vector<u16> ord40({0});
      slog::Relation* readrel41 = db->getRelation("error");
      head_index[0] = readrel41->getIndex(ord40, false);
      outer_rel = db->getRelation("mpz_table_overflow");
  
    }
    ReadTask39(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c26 = _t[0];
        u64 v_c27 = _t[1];
        u64 v_c28 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c26}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_table_overflow", _fires);
  
      if (!_done)
      {
        ReadTask39* _cont = new ReadTask39(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask39(db,b), false);
  // (crule (pre) (scan div_by_zero __erre8wC5246 __errf5qNG247 __errf5ogg248) (body) (head (emit error (0) __erre8wC5246)) <internal>:1 #f)
  class ReadTask42 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("error");
      std::vector<u16> ord43({0});
      slog::Relation* readrel44 = db->getRelation("error");
      head_index[0] = readrel44->getIndex(ord43, false);
      outer_rel = db->getRelation("div_by_zero");
  
    }
    ReadTask42(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c29 = _t[0];
        u64 v_c30 = _t[1];
        u64 v_c31 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c29}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:div_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask42* _cont = new ReadTask42(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask42(db,b), false);
  // (crule (pre) (scan temp4rzj276 __t2v0n2 __t7ODS1) (body) (head (emit sum_ans (0 1) __t2v0n2 __t7ODS1)) lst_typed.slog:13 #f)
  class ReadTask45 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("sum_ans");
      std::vector<u16> ord46({0, 1});
      slog::Relation* readrel47 = db->getRelation("sum_ans");
      head_index[0] = readrel47->getIndex(ord46, false);
      outer_rel = db->getRelation("temp4rzj276");
  
    }
    ReadTask45(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c10 = _t[0];
        u64 v_c17 = _t[1];
        ++_fires;
        slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c10, v_c17}, std::array<u16,2>{0, 1});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_typed.slog:13", "delta:temp4rzj276", _fires);
  
      if (!_done)
      {
        ReadTask45* _cont = new ReadTask45(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask45(db,b), false);
  // (crule (pre) (scan nan_result __erre5Vtf256 __errf9Khy257 __errf1pMn258 __errf5Cmq259) (body) (head (emit error (0) __erre5Vtf256)) <internal>:1 #f)
  class ReadTask48 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("error");
      std::vector<u16> ord49({0});
      slog::Relation* readrel50 = db->getRelation("error");
      head_index[0] = readrel50->getIndex(ord49, false);
      outer_rel = db->getRelation("nan_result");
  
    }
    ReadTask48(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c32 = _t[0];
        u64 v_c33 = _t[1];
        u64 v_c34 = _t[2];
        u64 v_c35 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c32}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:nan_result", _fires);
  
      if (!_done)
      {
        ReadTask48* _cont = new ReadTask48(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask48(db,b), false);
  // (crule (pre) (scan int_overflow __erre1xK0252 __errf5yQD253 __errf4V63254 __errf7weS255) (body) (head (emit error (0) __erre1xK0252)) <internal>:1 #f)
  class ReadTask51 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("error");
      std::vector<u16> ord52({0});
      slog::Relation* readrel53 = db->getRelation("error");
      head_index[0] = readrel53->getIndex(ord52, false);
      outer_rel = db->getRelation("int_overflow");
  
    }
    ReadTask51(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c36 = _t[0];
        u64 v_c37 = _t[1];
        u64 v_c38 = _t[2];
        u64 v_c39 = _t[3];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c36}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:int_overflow", _fires);
  
      if (!_done)
      {
        ReadTask51* _cont = new ReadTask51(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask51(db,b), false);
  // (crule (pre) (scan mpz_overflow __erre9OrR268 __errf5aPd269 __errf4mnN270 __errf5VaU271 __errf8XRl272) (body) (head (emit error (0) __erre9OrR268)) <internal>:1 #f)
  class ReadTask54 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("error");
      std::vector<u16> ord55({0});
      slog::Relation* readrel56 = db->getRelation("error");
      head_index[0] = readrel56->getIndex(ord55, false);
      outer_rel = db->getRelation("mpz_overflow");
  
    }
    ReadTask54(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c40 = _t[0];
        u64 v_c41 = _t[1];
        u64 v_c42 = _t[2];
        u64 v_c43 = _t[3];
        u64 v_c44 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c40}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:mpz_overflow", _fires);
  
      if (!_done)
      {
        ReadTask54* _cont = new ReadTask54(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask54(db,b), false);
  // (crule (pre) (scan modulo_by_zero __erre2QNi249 __errf02DI250 __errf3Phe251) (body) (head (emit error (0) __erre2QNi249)) <internal>:1 #f)
  class ReadTask57 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("error");
      std::vector<u16> ord58({0});
      slog::Relation* readrel59 = db->getRelation("error");
      head_index[0] = readrel59->getIndex(ord58, false);
      outer_rel = db->getRelation("modulo_by_zero");
  
    }
    ReadTask57(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c45 = _t[0];
        u64 v_c46 = _t[1];
        u64 v_c47 = _t[2];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c45}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:modulo_by_zero", _fires);
  
      if (!_done)
      {
        ReadTask57* _cont = new ReadTask57(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask57(db,b), false);
  // (crule (pre) (scan type_mismatch __erre0fvW263 __errf8uXC264 __errf0bWh265 __errf1ulX266 __errf5Amp267) (body) (head (emit error (0) __erre0fvW263)) <internal>:1 #f)
  class ReadTask60 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("error");
      std::vector<u16> ord61({0});
      slog::Relation* readrel62 = db->getRelation("error");
      head_index[0] = readrel62->getIndex(ord61, false);
      outer_rel = db->getRelation("type_mismatch");
  
    }
    ReadTask60(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c48 = _t[0];
        u64 v_c49 = _t[1];
        u64 v_c50 = _t[2];
        u64 v_c51 = _t[3];
        u64 v_c52 = _t[4];
        ++_fires;
        slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c48}, std::array<u16,1>{0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("<internal>:1", "delta:type_mismatch", _fires);
  
      if (!_done)
      {
        ReadTask60* _cont = new ReadTask60(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask60(db,b), false);
  // (crule (pre (let _00024sqc8YJi30 const6b86b273ff34fce19d6b804e) (let _00024sqc5EFd31 const5feceb66ffc86f38d952786c) (let _00024sqc4j8S32 const6b86b273ff34fce19d6b804e) (let _00024sqc7Mbr33 const5feceb66ffc86f38d952786c) (let _00024sqo4qiz38 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo4qiz38 x _00024seq0) (body (letp _00024sql3ast28 (aslst _00024seq0)) (let _00024sqn4UXW29 (llen _00024sql3ast28)) (cmp ge _00024sqn4UXW29 _00024sqc8YJi30) (let _00024sqp4Mi534 (_0002d _00024sqn4UXW29 _00024sqc7Mbr33)) (let xs (lslice _00024sql3ast28 _00024sqc4j8S32 _00024sqp4Mi534)) (exists sum (1 0) 1 _00024seq0) (exists sum (1 0) 1 xs) (join $sup5242x12x0x0x0 (3 0 2 1) 3 xs _00024seq0 x __t2v0n2) (join sum (0 1) 2 __t2v0n2 _00024seq0) (join sum (1 0) 1 xs __t0LBx3) (join sum_ans (0 1) 1 __t0LBx3 __v0) (letp chk0IRm279 (lref _00024sql3ast28 _00024sqc5EFd31)) (eq x chk0IRm279) (let __t7ODS1 (_0002b __v0 x))) (head (emit-temp temp4rzj276 __t2v0n2 __t7ODS1)) lst_typed.slog:13 #f)
  class ReadTask69 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** sumindex63;  slog::Index** sumindex64;  slog::Index** $sup5242x12x0x0x0index65;  slog::Index** sumindex66;  slog::Index** sumindex67;  slog::Index** sum_ansindex68;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp4rzj276");
      std::vector<u16> ord70({1, 0, 2});
      slog::Relation* readrel71 = db->getRelation("$seq_at");
      driver_index = readrel71->getIndex(ord70, true);
      std::vector<u16> ord72({1, 0});
      slog::Relation* readrel73 = db->getRelation("sum");
      sumindex63 = readrel73->getIndex(ord72, false);
      std::vector<u16> ord74({1, 0});
      slog::Relation* readrel75 = db->getRelation("sum");
      sumindex64 = readrel75->getIndex(ord74, false);
      std::vector<u16> ord76({3, 0, 2, 1});
      slog::Relation* readrel77 = db->getRelation("$sup5242x12x0x0x0");
      $sup5242x12x0x0x0index65 = readrel77->getIndex(ord76, false);
      std::vector<u16> ord78({0, 1});
      slog::Relation* readrel79 = db->getRelation("sum");
      sumindex66 = readrel79->getIndex(ord78, false);
      std::vector<u16> ord80({1, 0});
      slog::Relation* readrel81 = db->getRelation("sum");
      sumindex67 = readrel81->getIndex(ord80, false);
      std::vector<u16> ord82({0, 1});
      slog::Relation* readrel83 = db->getRelation("sum_ans");
      sum_ansindex68 = readrel83->getIndex(ord82, false);
  
    }
    ReadTask69(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c1 = v_const5feceb66ffc86f38d952786c;
      u64 v_c2 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c3 = v_const5feceb66ffc86f38d952786c;
      u64 v_c4 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c4, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m84) {
        u64 v_c8 = m84[1];
        u64 v_c9 = m84[2];
        if (buckethash(v_c8) != bucket) return;
        bool ok85 = true;
        u64 v_c11 = _prim_aslst(db, v_c9, &ok85);
        if (!ok85) return;
        u64 v_c12 = _prim_llen(db, v_c11);
        if (v_c12 == slog_error) { slog::emit_pending_error(db, "lst_typed.slog:13"); return; }
        u64 v_c53 = _prim_ge(db, v_c12, v_c0);
        if (v_c53 == slog_error) { slog::emit_pending_error(db, "lst_typed.slog:13"); return; }
        if (!v_c53) return;
        u64 v_c15 = _prim__0002d(db, v_c12, v_c3);
        if (v_c15 == slog_error) { slog::emit_pending_error(db, "lst_typed.slog:13"); return; }
        u64 v_c7 = _prim_lslice(db, v_c11, v_c2, v_c15);
        if (v_c7 == slog_error) { slog::emit_pending_error(db, "lst_typed.slog:13"); return; }
        if (!slog::exists_probe<2,1>(sumindex63, std::array<u64,2>{v_c9, 0})) return;
        if (!slog::exists_probe<2,1>(sumindex64, std::array<u64,2>{v_c7, 0})) return;
        slog::join_probe<4,3>($sup5242x12x0x0x0index65, std::array<u64,4>{v_c7, v_c9, v_c8, 0}, [&](const std::array<u64,4>& m87) {
          u64 v_c10 = m87[3];
          slog::join_probe<2,2>(sumindex66, std::array<u64,2>{v_c10, v_c9}, [&](const std::array<u64,2>& m88) {
            slog::join_probe<2,1>(sumindex67, std::array<u64,2>{v_c7, 0}, [&](const std::array<u64,2>& m89) {
              u64 v_c5 = m89[1];
              slog::join_probe<2,1>(sum_ansindex68, std::array<u64,2>{v_c5, 0}, [&](const std::array<u64,2>& m90) {
                u64 v_c6 = m90[1];
                bool ok91 = true;
                u64 v_c54 = _prim_lref(db, v_c11, v_c1, &ok91);
                if (!ok91) return;
                if (v_c8 != v_c54) return;
                u64 v_c17 = _prim__0002b(db, v_c6, v_c8);
                if (v_c17 == slog_error) { slog::emit_pending_error(db, "lst_typed.slog:13"); return; }
                ++_fires;
                slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c10, v_c17});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("lst_typed.slog:13", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask69* _cont = new ReadTask69(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask69(db,b), false);
  s->addReadRel("$seq_at");
  s->addReadRel("$sup5242x12x0x0x0");
  s->addReadRel("div_by_zero");
  s->addReadRel("int_overflow");
  s->addReadRel("modulo_by_zero");
  s->addReadRel("mpz_overflow");
  s->addReadRel("mpz_table_overflow");
  s->addReadRel("nan_result");
  s->addReadRel("sum");
  s->addReadRel("sum_ans");
  s->addReadRel("temp4rzj276");
  s->addReadRel("toint_range");
  s->addReadRel("type_mismatch");
  s->addDynamicRel("$seq_at");
  s->addDynamicRel("div_by_zero");
  s->addDynamicRel("error");
  s->addDynamicRel("int_overflow");
  s->addDynamicRel("modulo_by_zero");
  s->addDynamicRel("mpz_overflow");
  s->addDynamicRel("mpz_table_overflow");
  s->addDynamicRel("nan_result");
  s->addDynamicRel("sum_ans");
  s->addDynamicRel("temp4rzj276");
  s->addDynamicRel("toint_range");
  s->addDynamicRel("type_mismatch");
  s->addAccelRel("sum_ans");
  d->push(s);
  d->continueRun();
}

