
#include "../daemon/daemon.h"
#include "../daemon/operators.h"


extern u64 v_const0122baa3ac55f1b433944eb1;
extern u64 v_const06abaa100ecef791ce028c56;
extern u64 v_const1064263932db82f2cf6d4ac2;
extern u64 v_const3fdba35f04dc8c462986c992;
extern u64 v_const4a44dc15364204a80fe80e90;
extern u64 v_const4a59dbb9cb3129dfcc75170b;
extern u64 v_const4e5ef144c51cd25230c144c3;
extern u64 v_const4fc82b26aecb47d2868c4efb;
extern u64 v_const52b5e20f559958f34e533431;
extern u64 v_const5d6ab4fefffae2e4c15033db;
extern u64 v_const5feceb66ffc86f38d952786c;
extern u64 v_const60e3114d9b4b6577eea8cbc0;
extern u64 v_const65c80aac3433a01ef8a7f298;
extern u64 v_const6b51d431df5d7f141cbececc;
extern u64 v_const6b86b273ff34fce19d6b804e;
extern u64 v_const846f120b6b6ab883fe02a53a;
extern u64 v_const8c6798fa821ed573f6b89759;
extern u64 v_consta22c7bfa7abc2d7d387fd7df;
extern u64 v_constac3fe12f2763ff95bc66dbed;
extern u64 v_constb9e118781cea1f9fa01462e0;
extern u64 v_constcd2a69ce5ca278db1d6da969;
extern u64 v_constd01925b37634a1a9d24159d8;
extern u64 v_constd4735e3a265e16eee03f5971;
extern u64 v_constdd7bbf31ce5f578b9805e840;


void slog_rules_cf6319a65a16091ed(slog::Database* db, slog::Stratum* s)
{
  // (crule (pre (let __trid2y2a1377 const846f120b6b6ab883fe02a53a) (let __trel50rt1378 const1064263932db82f2cf6d4ac2) (let __tcol9HAI1379 const5feceb66ffc86f38d952786c) (let __trel0HyW1380 const1064263932db82f2cf6d4ac2) (let __tcol6SPe1381 const6b86b273ff34fce19d6b804e)) (scan $sup5638x68x0x0x0 __d0 k t v) (body) (head (tycheck t (accept (struct mbranch) (struct _enum) (struct mleaf)) __trid2y2a1377 __trel50rt1378 __tcol9HAI1379 (1 2 3 4 0)) (tycheck k (accept int) __trid2y2a1377 __trel0HyW1380 __tcol6SPe1381 (1 2 3 4 0)) (mkstruct mp_put (1 2 3 0) __1vKN1376 t k v)) map.slog:69 #f)
  class ReadTask3 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid1;  u32 sid0;  u32 sid2;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("mp_put");
      outer_rel = db->getRelation("$sup5638x68x0x0x0");
      sid1 = db->getRelation("_enum")->getStructId();
      sid0 = db->getRelation("mbranch")->getStructId();
      sid2 = db->getRelation("mleaf")->getStructId();
  
    }
    ReadTask3(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c0 = v_const846f120b6b6ab883fe02a53a;
      u64 v_c1 = v_const1064263932db82f2cf6d4ac2;
      u64 v_c2 = v_const5feceb66ffc86f38d952786c;
      u64 v_c3 = v_const1064263932db82f2cf6d4ac2;
      u64 v_c4 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c5 = _t[0];
        u64 v_c6 = _t[1];
        u64 v_c7 = _t[2];
        u64 v_c8 = _t[3];
        ++_fires;
        if (!((is_struct(v_c7) && (decode_struct_id(v_c7) == sid0 || decode_struct_id(v_c7) == sid1 || decode_struct_id(v_c7) == sid2))))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c0, v_c1, v_c2, v_c7}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c6)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c0, v_c3, v_c4, v_c6}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<4>(head_rel[2], newbatch[2], std::array<u64,3>{v_c7, v_c6, v_c8}, std::array<u16,4>{1, 2, 3, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:69", "delta:$sup5638x68x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask3* _cont = new ReadTask3(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask3(db,b), false);
  // (crule (pre) (scan mp_msk __t2nZc836 k m) (body (exists mleaf (1 2 0) 1 k) (exists $sup5638x44x0x0x0 (1 3 7 0 2 4 5 6) 2 k m) (exists mbranch (2 0 1 3 4) 1 m) (exists mp_put (2 3 0 1) 1 k) (exists mp_join (1 2 3 4 0) 1 k) (join mp_msk_ans (0 1) 1 __t2nZc836 __v0) (join mleaf (1 2 0) 1 k v __t5lKq834) (exists mp_put (2 3 0 1) 2 k v) (exists mp_join (1 2 3 4 0) 2 k __t5lKq834) (join $sup5638x44x0x0x0 (1 3 7 0 2 4 5 6) 3 k m v __t6Fc5832 l p r __t6oBk833) (neq p __v0) (join mbranch (1 2 3 4 0) 5 p m l r __t6oBk833) (join mp_put (0 2 1 3) 4 __t6Fc5832 k __t6oBk833 v) (join mp_join (1 2 3 4 0) 4 k __t5lKq834 p __t6oBk833 __t6jFY835) (join mp_join_ans (0 1) 1 __t6jFY835 res)) (head (emit mp_put_ans (0 1) __t6Fc5832 res)) map.slog:45 #f)
  class ReadTask18 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mleafindex4;  slog::Index** $sup5638x44x0x0x0index5;  slog::Index** mbranchindex6;  slog::Index** mp_putindex7;  slog::Index** mp_joinindex8;  slog::Index** mp_msk_ansindex9;  slog::Index** mleafindex10;  slog::Index** mp_putindex11;  slog::Index** mp_joinindex12;  slog::Index** $sup5638x44x0x0x0index13;  slog::Index** mbranchindex14;  slog::Index** mp_putindex15;  slog::Index** mp_joinindex16;  slog::Index** mp_join_ansindex17;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_ans");
      std::vector<u16> ord19({0, 1});
      slog::Relation* readrel20 = db->getRelation("mp_put_ans");
      head_index[0] = readrel20->getIndex(ord19, false);
      outer_rel = db->getRelation("mp_msk");
      std::vector<u16> ord21({1, 2, 0});
      slog::Relation* readrel22 = db->getRelation("mleaf");
      mleafindex4 = readrel22->getIndex(ord21, false);
      std::vector<u16> ord23({1, 3, 7, 0, 2, 4, 5, 6});
      slog::Relation* readrel24 = db->getRelation("$sup5638x44x0x0x0");
      $sup5638x44x0x0x0index5 = readrel24->getIndex(ord23, false);
      std::vector<u16> ord25({2, 0, 1, 3, 4});
      slog::Relation* readrel26 = db->getRelation("mbranch");
      mbranchindex6 = readrel26->getIndex(ord25, false);
      std::vector<u16> ord27({2, 3, 0, 1});
      slog::Relation* readrel28 = db->getRelation("mp_put");
      mp_putindex7 = readrel28->getIndex(ord27, false);
      std::vector<u16> ord29({1, 2, 3, 4, 0});
      slog::Relation* readrel30 = db->getRelation("mp_join");
      mp_joinindex8 = readrel30->getIndex(ord29, false);
      std::vector<u16> ord31({0, 1});
      slog::Relation* readrel32 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex9 = readrel32->getIndex(ord31, false);
      std::vector<u16> ord33({1, 2, 0});
      slog::Relation* readrel34 = db->getRelation("mleaf");
      mleafindex10 = readrel34->getIndex(ord33, false);
      std::vector<u16> ord35({2, 3, 0, 1});
      slog::Relation* readrel36 = db->getRelation("mp_put");
      mp_putindex11 = readrel36->getIndex(ord35, false);
      std::vector<u16> ord37({1, 2, 3, 4, 0});
      slog::Relation* readrel38 = db->getRelation("mp_join");
      mp_joinindex12 = readrel38->getIndex(ord37, false);
      std::vector<u16> ord39({1, 3, 7, 0, 2, 4, 5, 6});
      slog::Relation* readrel40 = db->getRelation("$sup5638x44x0x0x0");
      $sup5638x44x0x0x0index13 = readrel40->getIndex(ord39, false);
      std::vector<u16> ord41({1, 2, 3, 4, 0});
      slog::Relation* readrel42 = db->getRelation("mbranch");
      mbranchindex14 = readrel42->getIndex(ord41, false);
      std::vector<u16> ord43({0, 2, 1, 3});
      slog::Relation* readrel44 = db->getRelation("mp_put");
      mp_putindex15 = readrel44->getIndex(ord43, false);
      std::vector<u16> ord45({1, 2, 3, 4, 0});
      slog::Relation* readrel46 = db->getRelation("mp_join");
      mp_joinindex16 = readrel46->getIndex(ord45, false);
      std::vector<u16> ord47({0, 1});
      slog::Relation* readrel48 = db->getRelation("mp_join_ans");
      mp_join_ansindex17 = readrel48->getIndex(ord47, false);
  
    }
    ReadTask18(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c9 = _t[0];
        u64 v_c6 = _t[1];
        u64 v_c10 = _t[2];
        if (!slog::exists_probe<3,1>(mleafindex4, std::array<u64,3>{v_c6, 0, 0})) return;
        if (!slog::exists_probe<8,2>($sup5638x44x0x0x0index5, std::array<u64,8>{v_c6, v_c10, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex6, std::array<u64,5>{v_c10, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(mp_putindex7, std::array<u64,4>{v_c6, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mp_joinindex8, std::array<u64,5>{v_c6, 0, 0, 0, 0})) return;
        slog::join_probe<2,1>(mp_msk_ansindex9, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m49) {
          u64 v_c11 = m49[1];
          slog::join_probe<3,1>(mleafindex10, std::array<u64,3>{v_c6, 0, 0}, [&](const std::array<u64,3>& m50) {
            u64 v_c8 = m50[1]; u64 v_c12 = m50[2];
            if (!slog::exists_probe<4,2>(mp_putindex11, std::array<u64,4>{v_c6, v_c8, 0, 0})) return;
            if (!slog::exists_probe<5,2>(mp_joinindex12, std::array<u64,5>{v_c6, v_c12, 0, 0, 0})) return;
            slog::join_probe<8,3>($sup5638x44x0x0x0index13, std::array<u64,8>{v_c6, v_c10, v_c8, 0, 0, 0, 0, 0}, [&](const std::array<u64,8>& m51) {
              u64 v_c13 = m51[3]; u64 v_c14 = m51[4]; u64 v_c15 = m51[5]; u64 v_c16 = m51[6]; u64 v_c17 = m51[7];
              if (v_c15 == v_c11) return;
              slog::join_probe<5,5>(mbranchindex14, std::array<u64,5>{v_c15, v_c10, v_c14, v_c16, v_c17}, [&](const std::array<u64,5>& m52) {
                slog::join_probe<4,4>(mp_putindex15, std::array<u64,4>{v_c13, v_c6, v_c17, v_c8}, [&](const std::array<u64,4>& m53) {
                  slog::join_probe<5,4>(mp_joinindex16, std::array<u64,5>{v_c6, v_c12, v_c15, v_c17, 0}, [&](const std::array<u64,5>& m54) {
                    u64 v_c18 = m54[4];
                    slog::join_probe<2,1>(mp_join_ansindex17, std::array<u64,2>{v_c18, 0}, [&](const std::array<u64,2>& m55) {
                      u64 v_c19 = m55[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c13, v_c19}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:45", "delta:mp_msk", _fires);
  
      if (!_done)
      {
        ReadTask18* _cont = new ReadTask18(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask18(db,b), false);
  // (crule (pre (let __tconst0xOc223 const5feceb66ffc86f38d952786c)) (scan mp_msk __t4NVE225 q m) (body (exists $sup5638x98x0x0x0 (2 5 4 0 1 3 6 7 8) 2 m q) (exists mbranch (2 0 1 3 4) 1 m) (exists mbranch (1 2 3 4 0) 1 q) (exists mp_msk_ans (0 1) 1 __t4NVE225) (join $sup5638x98x0x0x1 (1 3 6 5 0 2 4 7 8 9) 3 __t4NVE225 m q p __t14N0222 l n r u v) (cmp lt n m) (join $sup5638x98x0x0x0 (4 1 2 6 0 3 5 7 8) 9 p l m r __t14N0222 n q u v) (exists mbranch (1 2 3 4 0) 4 q n u v) (exists mp_msk_ans (0 1) 2 __t4NVE225 p) (exists mp_union (1 2 0) 1 r) (join mbranch (1 2 3 4 0) 4 p m l r __t006N221) (exists mp_union (0 1 2) 2 __t14N0222 __t006N221) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t5FeR226) (join mp_union (0 1 2) 3 __t14N0222 __t006N221 __t5FeR226) (join mp_msk_ans (0 1) 2 __t4NVE225 p) (join-old mp_union (1 2 0) 2 (1 2 0) r __t5FeR226 __t6Lp3227) (join mp_union_ans (0 1) 1 __t6Lp3227 __v0) (let __t91c5224 (band q m)) (cmp gt __t91c5224 __tconst0xOc223)) (head (emit-temp temp0Tjz1856 __t14N0222 __v0 l m p) (mkstruct mbranch (1 2 3 4 0) __t1O3D219 p m l __v0)) map.slog:99 #f)
  class ReadTask74 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x98x0x0x0index56;  slog::Index** mbranchindex57;  slog::Index** mbranchindex58;  slog::Index** mp_msk_ansindex59;  slog::Index** $sup5638x98x0x0x1index60;  slog::Index** $sup5638x98x0x0x0index61;  slog::Index** mbranchindex62;  slog::Index** mp_msk_ansindex63;  slog::Index** mp_unionindex64;  slog::Index** mbranchindex65;  slog::Index** mp_unionindex66;  slog::Index** mbranchindex67;  slog::Index** mp_unionindex68;  slog::Index** mp_msk_ansindex69;  slog::Index** mp_unionindex70;  slog::Index** mp_union_ansindex71;  slog::Index** mbranchdelta72;  slog::Index** mp_uniondelta73;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp0Tjz1856");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_msk");
      std::vector<u16> ord75({2, 5, 4, 0, 1, 3, 6, 7, 8});
      slog::Relation* readrel76 = db->getRelation("$sup5638x98x0x0x0");
      $sup5638x98x0x0x0index56 = readrel76->getIndex(ord75, false);
      std::vector<u16> ord77({2, 0, 1, 3, 4});
      slog::Relation* readrel78 = db->getRelation("mbranch");
      mbranchindex57 = readrel78->getIndex(ord77, false);
      std::vector<u16> ord79({1, 2, 3, 4, 0});
      slog::Relation* readrel80 = db->getRelation("mbranch");
      mbranchindex58 = readrel80->getIndex(ord79, false);
      std::vector<u16> ord81({0, 1});
      slog::Relation* readrel82 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex59 = readrel82->getIndex(ord81, false);
      std::vector<u16> ord83({1, 3, 6, 5, 0, 2, 4, 7, 8, 9});
      slog::Relation* readrel84 = db->getRelation("$sup5638x98x0x0x1");
      $sup5638x98x0x0x1index60 = readrel84->getIndex(ord83, false);
      std::vector<u16> ord85({4, 1, 2, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel86 = db->getRelation("$sup5638x98x0x0x0");
      $sup5638x98x0x0x0index61 = readrel86->getIndex(ord85, false);
      std::vector<u16> ord87({1, 2, 3, 4, 0});
      slog::Relation* readrel88 = db->getRelation("mbranch");
      mbranchindex62 = readrel88->getIndex(ord87, false);
      std::vector<u16> ord89({0, 1});
      slog::Relation* readrel90 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex63 = readrel90->getIndex(ord89, false);
      std::vector<u16> ord91({1, 2, 0});
      slog::Relation* readrel92 = db->getRelation("mp_union");
      mp_unionindex64 = readrel92->getIndex(ord91, false);
      std::vector<u16> ord93({1, 2, 3, 4, 0});
      slog::Relation* readrel94 = db->getRelation("mbranch");
      mbranchindex65 = readrel94->getIndex(ord93, false);
      std::vector<u16> ord95({0, 1, 2});
      slog::Relation* readrel96 = db->getRelation("mp_union");
      mp_unionindex66 = readrel96->getIndex(ord95, false);
      std::vector<u16> ord97({1, 2, 3, 4, 0});
      slog::Relation* readrel98 = db->getRelation("mbranch");
      mbranchindex67 = readrel98->getIndex(ord97, false);
      std::vector<u16> ord99({1, 2, 3, 4, 0});
      slog::Relation* readrel100 = db->getRelation("mbranch");
      mbranchdelta72 = readrel100->getIndex(ord99, true);
      std::vector<u16> ord101({0, 1, 2});
      slog::Relation* readrel102 = db->getRelation("mp_union");
      mp_unionindex68 = readrel102->getIndex(ord101, false);
      std::vector<u16> ord103({0, 1});
      slog::Relation* readrel104 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex69 = readrel104->getIndex(ord103, false);
      std::vector<u16> ord105({1, 2, 0});
      slog::Relation* readrel106 = db->getRelation("mp_union");
      mp_unionindex70 = readrel106->getIndex(ord105, false);
      std::vector<u16> ord107({1, 2, 0});
      slog::Relation* readrel108 = db->getRelation("mp_union");
      mp_uniondelta73 = readrel108->getIndex(ord107, true);
      std::vector<u16> ord109({0, 1});
      slog::Relation* readrel110 = db->getRelation("mp_union_ans");
      mp_union_ansindex71 = readrel110->getIndex(ord109, false);
  
    }
    ReadTask74(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c20 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c21 = _t[0];
        u64 v_c22 = _t[1];
        u64 v_c10 = _t[2];
        if (!slog::exists_probe<9,2>($sup5638x98x0x0x0index56, std::array<u64,9>{v_c10, v_c22, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex57, std::array<u64,5>{v_c10, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex58, std::array<u64,5>{v_c22, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex59, std::array<u64,2>{v_c21, 0})) return;
        slog::join_probe<10,3>($sup5638x98x0x0x1index60, std::array<u64,10>{v_c21, v_c10, v_c22, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,10>& m111) {
          u64 v_c15 = m111[3]; u64 v_c23 = m111[4]; u64 v_c14 = m111[5]; u64 v_c24 = m111[6]; u64 v_c16 = m111[7]; u64 v_c25 = m111[8]; u64 v_c8 = m111[9];
          u64 v_c26 = _prim_lt(db, v_c24, v_c10);
          if (v_c26 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
          if (!v_c26) return;
          slog::join_probe<9,9>($sup5638x98x0x0x0index61, std::array<u64,9>{v_c15, v_c14, v_c10, v_c16, v_c23, v_c24, v_c22, v_c25, v_c8}, [&](const std::array<u64,9>& m113) {
            if (!slog::exists_probe<5,4>(mbranchindex62, std::array<u64,5>{v_c22, v_c24, v_c25, v_c8, 0})) return;
            if (!slog::exists_probe<2,2>(mp_msk_ansindex63, std::array<u64,2>{v_c21, v_c15})) return;
            if (!slog::exists_probe<3,1>(mp_unionindex64, std::array<u64,3>{v_c16, 0, 0})) return;
            slog::join_probe<5,4>(mbranchindex65, std::array<u64,5>{v_c15, v_c10, v_c14, v_c16, 0}, [&](const std::array<u64,5>& m114) {
              u64 v_c27 = m114[4];
              if (!slog::exists_probe<3,2>(mp_unionindex66, std::array<u64,3>{v_c23, v_c27, 0})) return;
              slog::join_probe_old<5,4>(mbranchindex67, mbranchdelta72, std::array<u64,5>{v_c22, v_c24, v_c25, v_c8, 0}, [&](const std::array<u64,5>& m115) {
                u64 v_c28 = m115[4];
                slog::join_probe<3,3>(mp_unionindex68, std::array<u64,3>{v_c23, v_c27, v_c28}, [&](const std::array<u64,3>& m116) {
                  slog::join_probe<2,2>(mp_msk_ansindex69, std::array<u64,2>{v_c21, v_c15}, [&](const std::array<u64,2>& m117) {
                    slog::join_probe_old<3,2>(mp_unionindex70, mp_uniondelta73, std::array<u64,3>{v_c16, v_c28, 0}, [&](const std::array<u64,3>& m118) {
                      u64 v_c29 = m118[2];
                      slog::join_probe<2,1>(mp_union_ansindex71, std::array<u64,2>{v_c29, 0}, [&](const std::array<u64,2>& m119) {
                        u64 v_c11 = m119[1];
                        u64 v_c30 = _prim_band(db, v_c22, v_c10);
                        if (v_c30 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
                        u64 v_c31 = _prim_gt(db, v_c30, v_c20);
                        if (v_c31 == slog_error) { slog::emit_pending_error(db, "map.slog:99"); return; }
                        if (!v_c31) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c23, v_c11, v_c14, v_c10, v_c15});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c15, v_c10, v_c14, v_c11}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:99", "delta:mp_msk", _fires);
  
      if (!_done)
      {
        ReadTask74* _cont = new ReadTask74(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask74(db,b), false);
  // (crule (pre) (scan eval __t63JF360 eb rho2 t) (body (exists $sup70016x95x0x0x1 (2 5 6 3 0 1 4 7) 3 eb rho2 t) (exists $sup70016x95x0x0x0 (1 4 2 0 3 5) 2 eb t) (exists mp_put (3 0 2 1) 1 t) (exists letrec (3 0 1 2) 1 eb) (exists eval (3 1 0 2) 1 t) (exists mp_put_ans (1 0) 1 rho2) (exists eval_ans (0 1) 1 __t63JF360) (join eval (2 3 0 1) 2 rho2 t __t6HuT359 er) (exists $sup70016x95x0x0x0 (1 4 2 0 3 5) 3 eb t er) (exists letrec (2 3 0 1) 2 er eb) (exists eval_ans (0 1) 1 __t6HuT359) (join $sup70016x95x0x0x1 (2 5 6 3 0 1 4 7) 4 eb rho2 t er __t7DhJ358 __t0Rig361 rho x) (join $sup70016x95x0x0x0 (0 3 4 1 2 5) 6 __t7DhJ358 rho t eb er x) (join-old mp_put (0 2 1 3) 4 (0 2 1 3) __t0Rig361 x rho t) (exists eval (2 3 0 1) 3 rho t __t7DhJ358) (exists mp_put_ans (0 1) 2 __t0Rig361 rho2) (join letrec (1 2 3 0) 3 x er eb __t0Sks357) (join eval (2 3 0 1) 4 rho t __t7DhJ358 __t0Sks357) (join mp_put_ans (0 1) 2 __t0Rig361 rho2) (join eval_ans (0 1) 1 __t6HuT359 vr) (join eval_ans (0 1) 1 __t63JF360 v)) (head (emit eval_ans (0 1) __t7DhJ358 v)) interp.slog:96 #f)
  class ReadTask143 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup70016x95x0x0x1index121;  slog::Index** $sup70016x95x0x0x0index122;  slog::Index** mp_putindex123;  slog::Index** letrecindex124;  slog::Index** evalindex125;  slog::Index** mp_put_ansindex126;  slog::Index** eval_ansindex127;  slog::Index** evalindex128;  slog::Index** $sup70016x95x0x0x0index129;  slog::Index** letrecindex130;  slog::Index** eval_ansindex131;  slog::Index** $sup70016x95x0x0x1index132;  slog::Index** $sup70016x95x0x0x0index133;  slog::Index** mp_putindex134;  slog::Index** evalindex135;  slog::Index** mp_put_ansindex136;  slog::Index** letrecindex137;  slog::Index** evalindex138;  slog::Index** mp_put_ansindex139;  slog::Index** eval_ansindex140;  slog::Index** eval_ansindex141;  slog::Index** mp_putdelta142;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord144({0, 1});
      slog::Relation* readrel145 = db->getRelation("eval_ans");
      head_index[0] = readrel145->getIndex(ord144, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord146({2, 5, 6, 3, 0, 1, 4, 7});
      slog::Relation* readrel147 = db->getRelation("$sup70016x95x0x0x1");
      $sup70016x95x0x0x1index121 = readrel147->getIndex(ord146, false);
      std::vector<u16> ord148({1, 4, 2, 0, 3, 5});
      slog::Relation* readrel149 = db->getRelation("$sup70016x95x0x0x0");
      $sup70016x95x0x0x0index122 = readrel149->getIndex(ord148, false);
      std::vector<u16> ord150({3, 0, 2, 1});
      slog::Relation* readrel151 = db->getRelation("mp_put");
      mp_putindex123 = readrel151->getIndex(ord150, false);
      std::vector<u16> ord152({3, 0, 1, 2});
      slog::Relation* readrel153 = db->getRelation("letrec");
      letrecindex124 = readrel153->getIndex(ord152, false);
      std::vector<u16> ord154({3, 1, 0, 2});
      slog::Relation* readrel155 = db->getRelation("eval");
      evalindex125 = readrel155->getIndex(ord154, false);
      std::vector<u16> ord156({1, 0});
      slog::Relation* readrel157 = db->getRelation("mp_put_ans");
      mp_put_ansindex126 = readrel157->getIndex(ord156, false);
      std::vector<u16> ord158({0, 1});
      slog::Relation* readrel159 = db->getRelation("eval_ans");
      eval_ansindex127 = readrel159->getIndex(ord158, false);
      std::vector<u16> ord160({2, 3, 0, 1});
      slog::Relation* readrel161 = db->getRelation("eval");
      evalindex128 = readrel161->getIndex(ord160, false);
      std::vector<u16> ord162({1, 4, 2, 0, 3, 5});
      slog::Relation* readrel163 = db->getRelation("$sup70016x95x0x0x0");
      $sup70016x95x0x0x0index129 = readrel163->getIndex(ord162, false);
      std::vector<u16> ord164({2, 3, 0, 1});
      slog::Relation* readrel165 = db->getRelation("letrec");
      letrecindex130 = readrel165->getIndex(ord164, false);
      std::vector<u16> ord166({0, 1});
      slog::Relation* readrel167 = db->getRelation("eval_ans");
      eval_ansindex131 = readrel167->getIndex(ord166, false);
      std::vector<u16> ord168({2, 5, 6, 3, 0, 1, 4, 7});
      slog::Relation* readrel169 = db->getRelation("$sup70016x95x0x0x1");
      $sup70016x95x0x0x1index132 = readrel169->getIndex(ord168, false);
      std::vector<u16> ord170({0, 3, 4, 1, 2, 5});
      slog::Relation* readrel171 = db->getRelation("$sup70016x95x0x0x0");
      $sup70016x95x0x0x0index133 = readrel171->getIndex(ord170, false);
      std::vector<u16> ord172({0, 2, 1, 3});
      slog::Relation* readrel173 = db->getRelation("mp_put");
      mp_putindex134 = readrel173->getIndex(ord172, false);
      std::vector<u16> ord174({0, 2, 1, 3});
      slog::Relation* readrel175 = db->getRelation("mp_put");
      mp_putdelta142 = readrel175->getIndex(ord174, true);
      std::vector<u16> ord176({2, 3, 0, 1});
      slog::Relation* readrel177 = db->getRelation("eval");
      evalindex135 = readrel177->getIndex(ord176, false);
      std::vector<u16> ord178({0, 1});
      slog::Relation* readrel179 = db->getRelation("mp_put_ans");
      mp_put_ansindex136 = readrel179->getIndex(ord178, false);
      std::vector<u16> ord180({1, 2, 3, 0});
      slog::Relation* readrel181 = db->getRelation("letrec");
      letrecindex137 = readrel181->getIndex(ord180, false);
      std::vector<u16> ord182({2, 3, 0, 1});
      slog::Relation* readrel183 = db->getRelation("eval");
      evalindex138 = readrel183->getIndex(ord182, false);
      std::vector<u16> ord184({0, 1});
      slog::Relation* readrel185 = db->getRelation("mp_put_ans");
      mp_put_ansindex139 = readrel185->getIndex(ord184, false);
      std::vector<u16> ord186({0, 1});
      slog::Relation* readrel187 = db->getRelation("eval_ans");
      eval_ansindex140 = readrel187->getIndex(ord186, false);
      std::vector<u16> ord188({0, 1});
      slog::Relation* readrel189 = db->getRelation("eval_ans");
      eval_ansindex141 = readrel189->getIndex(ord188, false);
  
    }
    ReadTask143(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c7 = _t[3];
        if (!slog::exists_probe<8,3>($sup70016x95x0x0x1index121, std::array<u64,8>{v_c33, v_c34, v_c7, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<6,2>($sup70016x95x0x0x0index122, std::array<u64,6>{v_c33, v_c7, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(mp_putindex123, std::array<u64,4>{v_c7, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(letrecindex124, std::array<u64,4>{v_c33, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(evalindex125, std::array<u64,4>{v_c7, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_put_ansindex126, std::array<u64,2>{v_c34, 0})) return;
        if (!slog::exists_probe<2,1>(eval_ansindex127, std::array<u64,2>{v_c32, 0})) return;
        slog::join_probe<4,2>(evalindex128, std::array<u64,4>{v_c34, v_c7, 0, 0}, [&](const std::array<u64,4>& m190) {
          u64 v_c35 = m190[2]; u64 v_c36 = m190[3];
          if (!slog::exists_probe<6,3>($sup70016x95x0x0x0index129, std::array<u64,6>{v_c33, v_c7, v_c36, 0, 0, 0})) return;
          if (!slog::exists_probe<4,2>(letrecindex130, std::array<u64,4>{v_c36, v_c33, 0, 0})) return;
          if (!slog::exists_probe<2,1>(eval_ansindex131, std::array<u64,2>{v_c35, 0})) return;
          slog::join_probe<8,4>($sup70016x95x0x0x1index132, std::array<u64,8>{v_c33, v_c34, v_c7, v_c36, 0, 0, 0, 0}, [&](const std::array<u64,8>& m191) {
            u64 v_c37 = m191[4]; u64 v_c38 = m191[5]; u64 v_c39 = m191[6]; u64 v_c40 = m191[7];
            slog::join_probe<6,6>($sup70016x95x0x0x0index133, std::array<u64,6>{v_c37, v_c39, v_c7, v_c33, v_c36, v_c40}, [&](const std::array<u64,6>& m192) {
              slog::join_probe_old<4,4>(mp_putindex134, mp_putdelta142, std::array<u64,4>{v_c38, v_c40, v_c39, v_c7}, [&](const std::array<u64,4>& m193) {
                if (!slog::exists_probe<4,3>(evalindex135, std::array<u64,4>{v_c39, v_c7, v_c37, 0})) return;
                if (!slog::exists_probe<2,2>(mp_put_ansindex136, std::array<u64,2>{v_c38, v_c34})) return;
                slog::join_probe<4,3>(letrecindex137, std::array<u64,4>{v_c40, v_c36, v_c33, 0}, [&](const std::array<u64,4>& m194) {
                  u64 v_c41 = m194[3];
                  slog::join_probe<4,4>(evalindex138, std::array<u64,4>{v_c39, v_c7, v_c37, v_c41}, [&](const std::array<u64,4>& m195) {
                    slog::join_probe<2,2>(mp_put_ansindex139, std::array<u64,2>{v_c38, v_c34}, [&](const std::array<u64,2>& m196) {
                      slog::join_probe<2,1>(eval_ansindex140, std::array<u64,2>{v_c35, 0}, [&](const std::array<u64,2>& m197) {
                        u64 v_c42 = m197[1];
                        slog::join_probe<2,1>(eval_ansindex141, std::array<u64,2>{v_c32, 0}, [&](const std::array<u64,2>& m198) {
                          u64 v_c8 = m198[1];
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c37, v_c8}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:96", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask143* _cont = new ReadTask143(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask143(db,b), false);
  // (crule (pre) (scan eval __t3BcP671 eb __v0 t) (body (exists mp_put_ans (1 0) 1 __v0) (exists $sup70016x92x0x0x1 (3 4 7 2 0 1 5 6 8 9) 3 __v0 eb t) (exists $sup70016x92x0x0x0 (1 4 0 2 3 5) 2 eb t) (exists eval (3 1 0 2) 1 t) (exists mp_put (3 0 2 1) 1 t) (exists let (3 0 1 2) 1 eb) (join eval_ans (0 1) 1 __t3BcP671 v) (join mp_put_ans (1 0) 1 __v0 __t0mp6672) (exists mp_put (3 0 2 1) 2 t __t0mp6672) (join $sup70016x92x0x0x1 (3 4 7 2 0 1 5 6 8 9) 4 __v0 eb t __t0mp6672 __t5vg0669 __t7GLg670 er rho vr x) (join $sup70016x92x0x0x0 (0 3 4 1 2 5) 6 __t5vg0669 rho t eb er x) (join eval (2 3 0 1) 4 rho t __t7GLg670 er) (join-old mp_put (0 2 1 3) 4 (0 2 1 3) __t0mp6672 x rho t) (exists eval (2 3 0 1) 3 rho t __t5vg0669) (exists eval_ans (0 1) 2 __t7GLg670 vr) (join let (1 2 3 0) 3 x er eb __t2w2P668) (join eval (2 3 0 1) 4 rho t __t5vg0669 __t2w2P668) (join eval_ans (0 1) 2 __t7GLg670 vr)) (head (emit eval_ans (0 1) __t5vg0669 v)) interp.slog:93 #f)
  class ReadTask218 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_put_ansindex199;  slog::Index** $sup70016x92x0x0x1index200;  slog::Index** $sup70016x92x0x0x0index201;  slog::Index** evalindex202;  slog::Index** mp_putindex203;  slog::Index** letindex204;  slog::Index** eval_ansindex205;  slog::Index** mp_put_ansindex206;  slog::Index** mp_putindex207;  slog::Index** $sup70016x92x0x0x1index208;  slog::Index** $sup70016x92x0x0x0index209;  slog::Index** evalindex210;  slog::Index** mp_putindex211;  slog::Index** evalindex212;  slog::Index** eval_ansindex213;  slog::Index** letindex214;  slog::Index** evalindex215;  slog::Index** eval_ansindex216;  slog::Index** mp_putdelta217;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord219({0, 1});
      slog::Relation* readrel220 = db->getRelation("eval_ans");
      head_index[0] = readrel220->getIndex(ord219, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord221({1, 0});
      slog::Relation* readrel222 = db->getRelation("mp_put_ans");
      mp_put_ansindex199 = readrel222->getIndex(ord221, false);
      std::vector<u16> ord223({3, 4, 7, 2, 0, 1, 5, 6, 8, 9});
      slog::Relation* readrel224 = db->getRelation("$sup70016x92x0x0x1");
      $sup70016x92x0x0x1index200 = readrel224->getIndex(ord223, false);
      std::vector<u16> ord225({1, 4, 0, 2, 3, 5});
      slog::Relation* readrel226 = db->getRelation("$sup70016x92x0x0x0");
      $sup70016x92x0x0x0index201 = readrel226->getIndex(ord225, false);
      std::vector<u16> ord227({3, 1, 0, 2});
      slog::Relation* readrel228 = db->getRelation("eval");
      evalindex202 = readrel228->getIndex(ord227, false);
      std::vector<u16> ord229({3, 0, 2, 1});
      slog::Relation* readrel230 = db->getRelation("mp_put");
      mp_putindex203 = readrel230->getIndex(ord229, false);
      std::vector<u16> ord231({3, 0, 1, 2});
      slog::Relation* readrel232 = db->getRelation("let");
      letindex204 = readrel232->getIndex(ord231, false);
      std::vector<u16> ord233({0, 1});
      slog::Relation* readrel234 = db->getRelation("eval_ans");
      eval_ansindex205 = readrel234->getIndex(ord233, false);
      std::vector<u16> ord235({1, 0});
      slog::Relation* readrel236 = db->getRelation("mp_put_ans");
      mp_put_ansindex206 = readrel236->getIndex(ord235, false);
      std::vector<u16> ord237({3, 0, 2, 1});
      slog::Relation* readrel238 = db->getRelation("mp_put");
      mp_putindex207 = readrel238->getIndex(ord237, false);
      std::vector<u16> ord239({3, 4, 7, 2, 0, 1, 5, 6, 8, 9});
      slog::Relation* readrel240 = db->getRelation("$sup70016x92x0x0x1");
      $sup70016x92x0x0x1index208 = readrel240->getIndex(ord239, false);
      std::vector<u16> ord241({0, 3, 4, 1, 2, 5});
      slog::Relation* readrel242 = db->getRelation("$sup70016x92x0x0x0");
      $sup70016x92x0x0x0index209 = readrel242->getIndex(ord241, false);
      std::vector<u16> ord243({2, 3, 0, 1});
      slog::Relation* readrel244 = db->getRelation("eval");
      evalindex210 = readrel244->getIndex(ord243, false);
      std::vector<u16> ord245({0, 2, 1, 3});
      slog::Relation* readrel246 = db->getRelation("mp_put");
      mp_putindex211 = readrel246->getIndex(ord245, false);
      std::vector<u16> ord247({0, 2, 1, 3});
      slog::Relation* readrel248 = db->getRelation("mp_put");
      mp_putdelta217 = readrel248->getIndex(ord247, true);
      std::vector<u16> ord249({2, 3, 0, 1});
      slog::Relation* readrel250 = db->getRelation("eval");
      evalindex212 = readrel250->getIndex(ord249, false);
      std::vector<u16> ord251({0, 1});
      slog::Relation* readrel252 = db->getRelation("eval_ans");
      eval_ansindex213 = readrel252->getIndex(ord251, false);
      std::vector<u16> ord253({1, 2, 3, 0});
      slog::Relation* readrel254 = db->getRelation("let");
      letindex214 = readrel254->getIndex(ord253, false);
      std::vector<u16> ord255({2, 3, 0, 1});
      slog::Relation* readrel256 = db->getRelation("eval");
      evalindex215 = readrel256->getIndex(ord255, false);
      std::vector<u16> ord257({0, 1});
      slog::Relation* readrel258 = db->getRelation("eval_ans");
      eval_ansindex216 = readrel258->getIndex(ord257, false);
  
    }
    ReadTask218(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c43 = _t[0];
        u64 v_c33 = _t[1];
        u64 v_c11 = _t[2];
        u64 v_c7 = _t[3];
        if (!slog::exists_probe<2,1>(mp_put_ansindex199, std::array<u64,2>{v_c11, 0})) return;
        if (!slog::exists_probe<10,3>($sup70016x92x0x0x1index200, std::array<u64,10>{v_c11, v_c33, v_c7, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<6,2>($sup70016x92x0x0x0index201, std::array<u64,6>{v_c33, v_c7, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(evalindex202, std::array<u64,4>{v_c7, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(mp_putindex203, std::array<u64,4>{v_c7, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(letindex204, std::array<u64,4>{v_c33, 0, 0, 0})) return;
        slog::join_probe<2,1>(eval_ansindex205, std::array<u64,2>{v_c43, 0}, [&](const std::array<u64,2>& m259) {
          u64 v_c8 = m259[1];
          slog::join_probe<2,1>(mp_put_ansindex206, std::array<u64,2>{v_c11, 0}, [&](const std::array<u64,2>& m260) {
            u64 v_c44 = m260[1];
            if (!slog::exists_probe<4,2>(mp_putindex207, std::array<u64,4>{v_c7, v_c44, 0, 0})) return;
            slog::join_probe<10,4>($sup70016x92x0x0x1index208, std::array<u64,10>{v_c11, v_c33, v_c7, v_c44, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,10>& m261) {
              u64 v_c45 = m261[4]; u64 v_c46 = m261[5]; u64 v_c36 = m261[6]; u64 v_c39 = m261[7]; u64 v_c42 = m261[8]; u64 v_c40 = m261[9];
              slog::join_probe<6,6>($sup70016x92x0x0x0index209, std::array<u64,6>{v_c45, v_c39, v_c7, v_c33, v_c36, v_c40}, [&](const std::array<u64,6>& m262) {
                slog::join_probe<4,4>(evalindex210, std::array<u64,4>{v_c39, v_c7, v_c46, v_c36}, [&](const std::array<u64,4>& m263) {
                  slog::join_probe_old<4,4>(mp_putindex211, mp_putdelta217, std::array<u64,4>{v_c44, v_c40, v_c39, v_c7}, [&](const std::array<u64,4>& m264) {
                    if (!slog::exists_probe<4,3>(evalindex212, std::array<u64,4>{v_c39, v_c7, v_c45, 0})) return;
                    if (!slog::exists_probe<2,2>(eval_ansindex213, std::array<u64,2>{v_c46, v_c42})) return;
                    slog::join_probe<4,3>(letindex214, std::array<u64,4>{v_c40, v_c36, v_c33, 0}, [&](const std::array<u64,4>& m265) {
                      u64 v_c47 = m265[3];
                      slog::join_probe<4,4>(evalindex215, std::array<u64,4>{v_c39, v_c7, v_c45, v_c47}, [&](const std::array<u64,4>& m266) {
                        slog::join_probe<2,2>(eval_ansindex216, std::array<u64,2>{v_c46, v_c42}, [&](const std::array<u64,2>& m267) {
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c45, v_c8}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:93", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask218* _cont = new ReadTask218(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask218(db,b), false);
  // (crule (pre) (scan temp7Xjy1975 __t6Bbs459 __v0 l m p) (body (join mbranch (1 2 3 4 0) 4 p m l __v0 __t8oL5457)) (head (emit mp_put_ans (0 1) __t6Bbs459 __t8oL5457)) map.slog:43 #f)
  class ReadTask269 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex268;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_ans");
      std::vector<u16> ord270({0, 1});
      slog::Relation* readrel271 = db->getRelation("mp_put_ans");
      head_index[0] = readrel271->getIndex(ord270, false);
      outer_rel = db->getRelation("temp7Xjy1975");
      std::vector<u16> ord272({1, 2, 3, 4, 0});
      slog::Relation* readrel273 = db->getRelation("mbranch");
      mbranchindex268 = readrel273->getIndex(ord272, false);
  
    }
    ReadTask269(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c11 = _t[1];
        u64 v_c14 = _t[2];
        u64 v_c10 = _t[3];
        u64 v_c15 = _t[4];
        slog::join_probe<5,4>(mbranchindex268, std::array<u64,5>{v_c15, v_c10, v_c14, v_c11, 0}, [&](const std::array<u64,5>& m274) {
          u64 v_c49 = m274[4];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c48, v_c49}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:43", "delta:temp7Xjy1975", _fires);
  
      if (!_done)
      {
        ReadTask269* _cont = new ReadTask269(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask269(db,b), false);
  // (crule (pre) (scan eval __9j5V1330 __t4vgN655 rho t) (body (join-old app (0 1 2) 1 (0 1 2) __t4vgN655 ef es)) (head (mkstruct tick (1 2 0) __49qT1331 __t4vgN655 t)) interp.slog:59 #f)
  class ReadTask277 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** appindex275;  slog::Index** appdelta276;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("tick");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord278({0, 1, 2});
      slog::Relation* readrel279 = db->getRelation("app");
      appindex275 = readrel279->getIndex(ord278, false);
      std::vector<u16> ord280({0, 1, 2});
      slog::Relation* readrel281 = db->getRelation("app");
      appdelta276 = readrel281->getIndex(ord280, true);
  
    }
    ReadTask277(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c50 = _t[0];
        u64 v_c51 = _t[1];
        u64 v_c39 = _t[2];
        u64 v_c7 = _t[3];
        slog::join_probe_old<3,1>(appindex275, appdelta276, std::array<u64,3>{v_c51, 0, 0}, [&](const std::array<u64,3>& m282) {
          u64 v_c52 = m282[1]; u64 v_c53 = m282[2];
          ++_fires;
          slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c51, v_c7}, std::array<u16,3>{1, 2, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:59", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask277* _cont = new ReadTask277(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask277(db,b), false);
  // (crule (pre (let __trid5oq21297 consta22c7bfa7abc2d7d387fd7df) (let __trel8qC11298 constdd7bbf31ce5f578b9805e840) (let __tcol05lg1299 const5feceb66ffc86f38d952786c) (let __trel54fU1300 constdd7bbf31ce5f578b9805e840) (let __tcol924N1301 const6b86b273ff34fce19d6b804e)) (scan $sup5638x42x0x0x0 __d0 k l m p r v) (body) (head (tycheck k (accept int) __trid5oq21297 __trel8qC11298 __tcol05lg1299 (1 2 3 4 0)) (tycheck m (accept int) __trid5oq21297 __trel54fU1300 __tcol924N1301 (1 2 3 4 0)) (mkstruct mp_msk (1 2 0) __9CJE1296 k m)) map.slog:43 #f)
  class ReadTask283 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[3];
    slog::Index** head_index[3];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("mp_msk");
      outer_rel = db->getRelation("$sup5638x42x0x0x0");
  
    }
    ReadTask283(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c54 = v_consta22c7bfa7abc2d7d387fd7df;
      u64 v_c55 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c56 = v_const5feceb66ffc86f38d952786c;
      u64 v_c57 = v_constdd7bbf31ce5f578b9805e840;
      u64 v_c58 = v_const6b86b273ff34fce19d6b804e;
  
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
        u64 v_c5 = _t[0];
        u64 v_c6 = _t[1];
        u64 v_c14 = _t[2];
        u64 v_c10 = _t[3];
        u64 v_c15 = _t[4];
        u64 v_c16 = _t[5];
        u64 v_c8 = _t[6];
        ++_fires;
        if (!(is_int(v_c6)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c54, v_c55, v_c56, v_c6}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_int(v_c10)))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c54, v_c57, v_c58, v_c10}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_struct<3>(head_rel[2], newbatch[2], std::array<u64,2>{v_c6, v_c10}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
  
      if (_fires) db->bumpFires("map.slog:43", "delta:$sup5638x42x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask283* _cont = new ReadTask283(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask283(db,b), false);
  // (crule (pre) (scan mp_union __t4rVj386 s __t6x7f385) (body (join mleaf (0 1 2) 1 __t6x7f385 k v)) (head (mkstruct mp_put_soft (1 2 3 0) __6BWr1132 s k v)) map.slog:93 #f)
  class ReadTask285 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mleafindex284;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_soft");
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord286({0, 1, 2});
      slog::Relation* readrel287 = db->getRelation("mleaf");
      mleafindex284 = readrel287->getIndex(ord286, false);
  
    }
    ReadTask285(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c59 = _t[0];
        u64 v_c60 = _t[1];
        u64 v_c61 = _t[2];
        slog::join_probe<3,1>(mleafindex284, std::array<u64,3>{v_c61, 0, 0}, [&](const std::array<u64,3>& m288) {
          u64 v_c6 = m288[1]; u64 v_c8 = m288[2];
          ++_fires;
          slog::emit_struct<4>(head_rel[0], newbatch[0], std::array<u64,3>{v_c60, v_c6, v_c8}, std::array<u16,4>{1, 2, 3, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:93", "delta:mp_union", _fires);
  
      if (!_done)
      {
        ReadTask285* _cont = new ReadTask285(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask285(db,b), false);
  // (crule (pre (let __tconst5MNq94 const5feceb66ffc86f38d952786c)) (scan temp3mEP1989 __t39ek93 __t62tP83) (body (join let (1 2 3 0) 3 __tconst5MNq94 __t39ek93 __t62tP83 __t1QAZ95)) (head (emit program (0) __t1QAZ95)) kcfa.slog:16 #f)
  class ReadTask290 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letindex289;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("program");
      std::vector<u16> ord291({0});
      slog::Relation* readrel292 = db->getRelation("program");
      head_index[0] = readrel292->getIndex(ord291, false);
      outer_rel = db->getRelation("temp3mEP1989");
      std::vector<u16> ord293({1, 2, 3, 0});
      slog::Relation* readrel294 = db->getRelation("let");
      letindex289 = readrel294->getIndex(ord293, false);
  
    }
    ReadTask290(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c62 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c63 = _t[0];
        u64 v_c64 = _t[1];
        slog::join_probe<4,3>(letindex289, std::array<u64,4>{v_c62, v_c63, v_c64, 0}, [&](const std::array<u64,4>& m295) {
          u64 v_c65 = m295[3];
          ++_fires;
          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c65}, std::array<u16,1>{0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("kcfa.slog:16", "delta:temp3mEP1989", _fires);
  
      if (!_done)
      {
        ReadTask290* _cont = new ReadTask290(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask290(db,b), false);
  // (crule (pre (let __tconst7YVO1086 constb9e118781cea1f9fa01462e0) (let __tconst0qOo437 const60e3114d9b4b6577eea8cbc0) (let _00024sqc0uxV1007 const6b86b273ff34fce19d6b804e) (let _00024sqc0jY31008 const5feceb66ffc86f38d952786c) (let _00024sqo1OME1009 const5feceb66ffc86f38d952786c) (let _00024sqo3mx21010 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo1OME1009 v _00024seq0) (body (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo3mx21010 v _00024seq0) (exists _enum (1 0) 1 __tconst7YVO1086) (join delta (1 2 0) 2 __tconst0qOo437 _00024seq0 __t4KDF438) (join _enum (1 0) 1 __tconst7YVO1086 __t2dgW435) (join scheme_false (0) 0 fv) (neq v fv) (letp _00024sql5Lne1005 (aslst _00024seq0)) (let chk9zS01819 (llen _00024sql5Lne1005)) (eq _00024sqc0uxV1007 chk9zS01819) (letp chk6y0N1820 (lref _00024sql5Lne1005 _00024sqc0jY31008)) (eq v chk6y0N1820)) (head (emit-temp temp6YY41815 __t4KDF438) (mkstruct boolval (1 0) __t83Bj436 __t2dgW435)) interp.slog:119 #f)
  class ReadTask302 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atrindex296;  slog::Index** _enumindex297;  slog::Index** deltaindex298;  slog::Index** _enumindex299;  slog::Index** scheme_falseindex300;  slog::Index** $seq_atrdelta301;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp6YY41815");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord303({1, 0, 2});
      slog::Relation* readrel304 = db->getRelation("$seq_at");
      driver_index = readrel304->getIndex(ord303, true);
      std::vector<u16> ord305({1, 0, 2});
      slog::Relation* readrel306 = db->getRelation("$seq_atr");
      $seq_atrindex296 = readrel306->getIndex(ord305, false);
      std::vector<u16> ord307({1, 0, 2});
      slog::Relation* readrel308 = db->getRelation("$seq_atr");
      $seq_atrdelta301 = readrel308->getIndex(ord307, true);
      std::vector<u16> ord309({1, 0});
      slog::Relation* readrel310 = db->getRelation("_enum");
      _enumindex297 = readrel310->getIndex(ord309, false);
      std::vector<u16> ord311({1, 2, 0});
      slog::Relation* readrel312 = db->getRelation("delta");
      deltaindex298 = readrel312->getIndex(ord311, false);
      std::vector<u16> ord313({1, 0});
      slog::Relation* readrel314 = db->getRelation("_enum");
      _enumindex299 = readrel314->getIndex(ord313, false);
      std::vector<u16> ord315({0});
      slog::Relation* readrel316 = db->getRelation("scheme_false");
      scheme_falseindex300 = readrel316->getIndex(ord315, false);
  
    }
    ReadTask302(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c66 = v_constb9e118781cea1f9fa01462e0;
      u64 v_c67 = v_const60e3114d9b4b6577eea8cbc0;
      u64 v_c68 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c69 = v_const5feceb66ffc86f38d952786c;
      u64 v_c70 = v_const5feceb66ffc86f38d952786c;
      u64 v_c71 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c70, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m317) {
        u64 v_c8 = m317[1];
        u64 v_c72 = m317[2];
        if (buckethash(v_c8) != bucket) return;
        slog::join_probe_old<3,3>($seq_atrindex296, $seq_atrdelta301, std::array<u64,3>{v_c71, v_c8, v_c72}, [&](const std::array<u64,3>& m318) {
          if (!slog::exists_probe<2,1>(_enumindex297, std::array<u64,2>{v_c66, 0})) return;
          slog::join_probe<3,2>(deltaindex298, std::array<u64,3>{v_c67, v_c72, 0}, [&](const std::array<u64,3>& m319) {
            u64 v_c73 = m319[2];
            slog::join_probe<2,1>(_enumindex299, std::array<u64,2>{v_c66, 0}, [&](const std::array<u64,2>& m320) {
              u64 v_c74 = m320[1];
              slog::join_all<1>(scheme_falseindex300, [&](const std::array<u64,1>& m321) {
                u64 v_c75 = m321[0];
                if (v_c8 == v_c75) return;
                bool ok322 = true;
                u64 v_c76 = _prim_aslst(db, v_c72, &ok322);
                if (!ok322) return;
                u64 v_c77 = _prim_llen(db, v_c76);
                if (v_c77 == slog_error) { slog::emit_pending_error(db, "interp.slog:119"); return; }
                if (v_c68 != v_c77) return;
                bool ok323 = true;
                u64 v_c78 = _prim_lref(db, v_c76, v_c69, &ok323);
                if (!ok323) return;
                if (v_c8 != v_c78) return;
                ++_fires;
                slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c73});
                slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c74}, std::array<u16,2>{1, 0});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:119", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask302* _cont = new ReadTask302(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask302(db,b), false);
  // (crule (pre (let __tconst49eD1184 constcd2a69ce5ca278db1d6da969) (let __tconst7GbT659 const06abaa100ecef791ce028c56) (let _00024sqc0jJd1013 constd4735e3a265e16eee03f5971) (let _00024sqc54us1014 const5feceb66ffc86f38d952786c) (let _00024sqc6uOX1015 const6b86b273ff34fce19d6b804e) (let _00024sqo8ZRa1016 const5feceb66ffc86f38d952786c) (let _00024sqo9lkw1017 const6b86b273ff34fce19d6b804e) (let _00024sqo8so11018 const6b86b273ff34fce19d6b804e) (let _00024sqo0qa11019 const5feceb66ffc86f38d952786c)) (probe $seq_at (1 0 2) 1 _00024sqo8ZRa1016 __t013P662 _00024seq2) (body (join-old $seq_at (1 0 2) 3 (1 0 2) _00024sqo9lkw1017 __t013P662 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo8so11018 __t013P662 _00024seq2) (join-old $seq_atr (1 0 2) 3 (1 0 2) _00024sqo0qa11019 __t013P662 _00024seq2) (join _enum (0 1) 2 __t013P662 __tconst49eD1184) (join delta (1 2 0) 2 __tconst7GbT659 _00024seq2 __t6erK660) (join any_bool (0) 0 b) (letp _00024sql99Ol1011 (aslst _00024seq2)) (let chk2kc31781 (llen _00024sql99Ol1011)) (eq _00024sqc0jJd1013 chk2kc31781) (letp chk2RwA1782 (lref _00024sql99Ol1011 _00024sqc54us1014)) (eq __t013P662 chk2RwA1782) (letp chk9Qro1783 (lref _00024sql99Ol1011 _00024sqc6uOX1015)) (eq __t013P662 chk9Qro1783)) (head (emit-temp temp3q8l1778 __t6erK660 b) (mkstruct boolval (1 0) __t5eIx658 b)) interp.slog:125 #f)
  class ReadTask333 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
  
    slog::Index** driver_index;
  
  
    std::array<u64,3> resume_key{};
    bool has_resume = false;
    slog::Index** $seq_atindex324;  slog::Index** $seq_atrindex325;  slog::Index** $seq_atrindex326;  slog::Index** _enumindex327;  slog::Index** deltaindex328;  slog::Index** any_boolindex329;  slog::Index** $seq_atdelta330;  slog::Index** $seq_atrdelta331;  slog::Index** $seq_atrdelta332;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3q8l1778");
      head_rel[1] = db->getRelation("boolval");
      std::vector<u16> ord334({1, 0, 2});
      slog::Relation* readrel335 = db->getRelation("$seq_at");
      driver_index = readrel335->getIndex(ord334, true);
      std::vector<u16> ord336({1, 0, 2});
      slog::Relation* readrel337 = db->getRelation("$seq_at");
      $seq_atindex324 = readrel337->getIndex(ord336, false);
      std::vector<u16> ord338({1, 0, 2});
      slog::Relation* readrel339 = db->getRelation("$seq_at");
      $seq_atdelta330 = readrel339->getIndex(ord338, true);
      std::vector<u16> ord340({1, 0, 2});
      slog::Relation* readrel341 = db->getRelation("$seq_atr");
      $seq_atrindex325 = readrel341->getIndex(ord340, false);
      std::vector<u16> ord342({1, 0, 2});
      slog::Relation* readrel343 = db->getRelation("$seq_atr");
      $seq_atrdelta331 = readrel343->getIndex(ord342, true);
      std::vector<u16> ord344({1, 0, 2});
      slog::Relation* readrel345 = db->getRelation("$seq_atr");
      $seq_atrindex326 = readrel345->getIndex(ord344, false);
      std::vector<u16> ord346({1, 0, 2});
      slog::Relation* readrel347 = db->getRelation("$seq_atr");
      $seq_atrdelta332 = readrel347->getIndex(ord346, true);
      std::vector<u16> ord348({0, 1});
      slog::Relation* readrel349 = db->getRelation("_enum");
      _enumindex327 = readrel349->getIndex(ord348, false);
      std::vector<u16> ord350({1, 2, 0});
      slog::Relation* readrel351 = db->getRelation("delta");
      deltaindex328 = readrel351->getIndex(ord350, false);
      std::vector<u16> ord352({0});
      slog::Relation* readrel353 = db->getRelation("any_bool");
      any_boolindex329 = readrel353->getIndex(ord352, false);
  
    }
    ReadTask333(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c79 = v_constcd2a69ce5ca278db1d6da969;
      u64 v_c80 = v_const06abaa100ecef791ce028c56;
      u64 v_c81 = v_constd4735e3a265e16eee03f5971;
      u64 v_c82 = v_const5feceb66ffc86f38d952786c;
      u64 v_c83 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c84 = v_const5feceb66ffc86f38d952786c;
      u64 v_c85 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c86 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c87 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      std::array<u64,3> _rkey = resume_key; bool _hr = has_resume;
      bool _done = slog::join_probe_sliced<3,1>(driver_index, std::array<u64,3>{v_c84, 0, 0}, _sc, _rkey, _hr, [&](const std::array<u64,3>& m354) {
        u64 v_c88 = m354[1];
        u64 v_c89 = m354[2];
        if (buckethash(v_c88) != bucket) return;
        slog::join_probe_old<3,3>($seq_atindex324, $seq_atdelta330, std::array<u64,3>{v_c85, v_c88, v_c89}, [&](const std::array<u64,3>& m355) {
          slog::join_probe_old<3,3>($seq_atrindex325, $seq_atrdelta331, std::array<u64,3>{v_c86, v_c88, v_c89}, [&](const std::array<u64,3>& m356) {
            slog::join_probe_old<3,3>($seq_atrindex326, $seq_atrdelta332, std::array<u64,3>{v_c87, v_c88, v_c89}, [&](const std::array<u64,3>& m357) {
              slog::join_probe<2,2>(_enumindex327, std::array<u64,2>{v_c88, v_c79}, [&](const std::array<u64,2>& m358) {
                slog::join_probe<3,2>(deltaindex328, std::array<u64,3>{v_c80, v_c89, 0}, [&](const std::array<u64,3>& m359) {
                  u64 v_c90 = m359[2];
                  slog::join_all<1>(any_boolindex329, [&](const std::array<u64,1>& m360) {
                    u64 v_c91 = m360[0];
                    bool ok361 = true;
                    u64 v_c92 = _prim_aslst(db, v_c89, &ok361);
                    if (!ok361) return;
                    u64 v_c93 = _prim_llen(db, v_c92);
                    if (v_c93 == slog_error) { slog::emit_pending_error(db, "interp.slog:125"); return; }
                    if (v_c81 != v_c93) return;
                    bool ok362 = true;
                    u64 v_c94 = _prim_lref(db, v_c92, v_c82, &ok362);
                    if (!ok362) return;
                    if (v_c88 != v_c94) return;
                    bool ok363 = true;
                    u64 v_c95 = _prim_lref(db, v_c92, v_c83, &ok363);
                    if (!ok363) return;
                    if (v_c88 != v_c95) return;
                    ++_fires;
                    slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c90, v_c91});
                    slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c91}, std::array<u16,2>{1, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:125", "delta:$seq_at", _fires);
  
      if (!_done)
      {
        ReadTask333* _cont = new ReadTask333(db, bucket);
        _cont->resume_key = _rkey; _cont->has_resume = true;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask333(db,b), false);
  // (crule (pre) (scan mp_union __t2zhu601 __t04LR600 __t7y6C599) (body (join mbranch (0 1 2 3 4) 1 __t7y6C599 p m u v) (join mbranch (0 1 2 3 4) 3 __t04LR600 p m l r)) (head (emit $sup5638x93x0x0x0 (0 1 2 3 4 5 6) __t2zhu601 l m p r u v)) map.slog:94 #f)
  class ReadTask366 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex364;  slog::Index** mbranchindex365;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x93x0x0x0");
      std::vector<u16> ord367({0, 1, 2, 3, 4, 5, 6});
      slog::Relation* readrel368 = db->getRelation("$sup5638x93x0x0x0");
      head_index[0] = readrel368->getIndex(ord367, false);
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord369({0, 1, 2, 3, 4});
      slog::Relation* readrel370 = db->getRelation("mbranch");
      mbranchindex364 = readrel370->getIndex(ord369, false);
      std::vector<u16> ord371({0, 1, 2, 3, 4});
      slog::Relation* readrel372 = db->getRelation("mbranch");
      mbranchindex365 = readrel372->getIndex(ord371, false);
  
    }
    ReadTask366(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c96 = _t[0];
        u64 v_c97 = _t[1];
        u64 v_c98 = _t[2];
        slog::join_probe<5,1>(mbranchindex364, std::array<u64,5>{v_c98, 0, 0, 0, 0}, [&](const std::array<u64,5>& m373) {
          u64 v_c15 = m373[1]; u64 v_c10 = m373[2]; u64 v_c25 = m373[3]; u64 v_c8 = m373[4];
          slog::join_probe<5,3>(mbranchindex365, std::array<u64,5>{v_c97, v_c15, v_c10, 0, 0}, [&](const std::array<u64,5>& m374) {
            u64 v_c14 = m374[3]; u64 v_c16 = m374[4];
            ++_fires;
            slog::emit<7>(head_rel[0], head_index[0], newbatch[0], std::array<u64,7>{v_c96, v_c14, v_c10, v_c15, v_c16, v_c25, v_c8}, std::array<u16,7>{0, 1, 2, 3, 4, 5, 6});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:94", "delta:mp_union", _fires);
  
      if (!_done)
      {
        ReadTask366* _cont = new ReadTask366(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask366(db,b), false);
  // (crule (pre (let __tconst9Msd523 const6b86b273ff34fce19d6b804e)) (scan mp_union __t0OqE522 __t8ZnZ521 __t333H520) (body (join mbranch (0 1 2 3 4) 1 __t333H520 q n u v) (join mbranch (0 1 2 3 4) 1 __t8ZnZ521 p m l r) (cmp lt m n) (let __t9LcB524 (band p n)) (cmp lt __t9LcB524 __tconst9Msd523)) (head (emit $sup5638x104x0x0x0 (0 7 1 2 3 4 5 6 8) __t0OqE522 u l m n p q r v)) map.slog:105 #f)
  class ReadTask377 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex375;  slog::Index** mbranchindex376;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x104x0x0x0");
      std::vector<u16> ord378({0, 7, 1, 2, 3, 4, 5, 6, 8});
      slog::Relation* readrel379 = db->getRelation("$sup5638x104x0x0x0");
      head_index[0] = readrel379->getIndex(ord378, false);
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord380({0, 1, 2, 3, 4});
      slog::Relation* readrel381 = db->getRelation("mbranch");
      mbranchindex375 = readrel381->getIndex(ord380, false);
      std::vector<u16> ord382({0, 1, 2, 3, 4});
      slog::Relation* readrel383 = db->getRelation("mbranch");
      mbranchindex376 = readrel383->getIndex(ord382, false);
  
    }
    ReadTask377(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c99 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c100 = _t[0];
        u64 v_c101 = _t[1];
        u64 v_c102 = _t[2];
        slog::join_probe<5,1>(mbranchindex375, std::array<u64,5>{v_c102, 0, 0, 0, 0}, [&](const std::array<u64,5>& m384) {
          u64 v_c22 = m384[1]; u64 v_c24 = m384[2]; u64 v_c25 = m384[3]; u64 v_c8 = m384[4];
          slog::join_probe<5,1>(mbranchindex376, std::array<u64,5>{v_c101, 0, 0, 0, 0}, [&](const std::array<u64,5>& m385) {
            u64 v_c15 = m385[1]; u64 v_c10 = m385[2]; u64 v_c14 = m385[3]; u64 v_c16 = m385[4];
            u64 v_c103 = _prim_lt(db, v_c10, v_c24);
            if (v_c103 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
            if (!v_c103) return;
            u64 v_c104 = _prim_band(db, v_c15, v_c24);
            if (v_c104 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
            u64 v_c105 = _prim_lt(db, v_c104, v_c99);
            if (v_c105 == slog_error) { slog::emit_pending_error(db, "map.slog:105"); return; }
            if (!v_c105) return;
            ++_fires;
            slog::emit<9>(head_rel[0], head_index[0], newbatch[0], std::array<u64,9>{v_c100, v_c25, v_c14, v_c10, v_c24, v_c15, v_c22, v_c16, v_c8}, std::array<u16,9>{0, 7, 1, 2, 3, 4, 5, 6, 8});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:105", "delta:mp_union", _fires);
  
      if (!_done)
      {
        ReadTask377* _cont = new ReadTask377(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask377(db,b), false);
  // (crule (pre) (scan $sup5638x25x0x0x1 __d0 __d1 __v0 p0 p1 t0 t1) (body (let __t9Sw7529 (bxor p0 p1))) (head (emit-temp temp1sew1876 __t9Sw7529)) map.slog:26 #f)
  class ReadTask388 : public slog::Task
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
      head_rel[0] = db->getRelation("temp1sew1876");
      outer_rel = db->getRelation("$sup5638x25x0x0x1");
  
    }
    ReadTask388(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c5 = _t[0];
        u64 v_c106 = _t[1];
        u64 v_c11 = _t[2];
        u64 v_c107 = _t[3];
        u64 v_c108 = _t[4];
        u64 v_c109 = _t[5];
        u64 v_c110 = _t[6];
        u64 v_c111 = _prim_bxor(db, v_c107, v_c108);
        if (v_c111 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c111});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:26", "delta:$sup5638x25x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask388* _cont = new ReadTask388(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask388(db,b), false);
  // (crule (pre) (scan temp9IEi1871 __t0kfV144 __v0 n q v) (body (join mbranch (1 2 3 4 0) 4 q n __v0 v __t4DAr141)) (head (emit mp_union_ans (0 1) __t0kfV144 __t4DAr141)) map.slog:105 #f)
  class ReadTask390 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex389;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord391({0, 1});
      slog::Relation* readrel392 = db->getRelation("mp_union_ans");
      head_index[0] = readrel392->getIndex(ord391, false);
      outer_rel = db->getRelation("temp9IEi1871");
      std::vector<u16> ord393({1, 2, 3, 4, 0});
      slog::Relation* readrel394 = db->getRelation("mbranch");
      mbranchindex389 = readrel394->getIndex(ord393, false);
  
    }
    ReadTask390(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c112 = _t[0];
        u64 v_c11 = _t[1];
        u64 v_c24 = _t[2];
        u64 v_c22 = _t[3];
        u64 v_c8 = _t[4];
        slog::join_probe<5,4>(mbranchindex389, std::array<u64,5>{v_c22, v_c24, v_c11, v_c8, 0}, [&](const std::array<u64,5>& m395) {
          u64 v_c113 = m395[4];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c112, v_c113}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:105", "delta:temp9IEi1871", _fires);
  
      if (!_done)
      {
        ReadTask390* _cont = new ReadTask390(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask390(db,b), false);
  // (crule (pre) (scan eval_ans __t6oYx552 __t21iW553) (body (join-old prim (0 1) 1 (0 1) __t21iW553 op) (join-old eval (0 1 2 3) 1 (0 1 2 3) __t6oYx552 ef rho t) (exists eval_args (3 2 0 1) 2 t rho) (join $sup70016x75x0x0x0 (1 3 4 2 0) 3 ef rho t es __d0) (join-old eval_args (1 3 2 0) 3 (1 3 2 0) es t rho __t11mn554) (join-old eval_args_ans (0 1) 1 (0 1) __t11mn554 vs)) (head (mkstruct delta (1 2 0) __5Kx31559 op vs)) interp.slog:76 #f)
  class ReadTask406 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** primindex396;  slog::Index** evalindex397;  slog::Index** eval_argsindex398;  slog::Index** $sup70016x75x0x0x0index399;  slog::Index** eval_argsindex400;  slog::Index** eval_args_ansindex401;  slog::Index** primdelta402;  slog::Index** evaldelta403;  slog::Index** eval_argsdelta404;  slog::Index** eval_args_ansdelta405;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("delta");
      outer_rel = db->getRelation("eval_ans");
      std::vector<u16> ord407({0, 1});
      slog::Relation* readrel408 = db->getRelation("prim");
      primindex396 = readrel408->getIndex(ord407, false);
      std::vector<u16> ord409({0, 1});
      slog::Relation* readrel410 = db->getRelation("prim");
      primdelta402 = readrel410->getIndex(ord409, true);
      std::vector<u16> ord411({0, 1, 2, 3});
      slog::Relation* readrel412 = db->getRelation("eval");
      evalindex397 = readrel412->getIndex(ord411, false);
      std::vector<u16> ord413({0, 1, 2, 3});
      slog::Relation* readrel414 = db->getRelation("eval");
      evaldelta403 = readrel414->getIndex(ord413, true);
      std::vector<u16> ord415({3, 2, 0, 1});
      slog::Relation* readrel416 = db->getRelation("eval_args");
      eval_argsindex398 = readrel416->getIndex(ord415, false);
      std::vector<u16> ord417({1, 3, 4, 2, 0});
      slog::Relation* readrel418 = db->getRelation("$sup70016x75x0x0x0");
      $sup70016x75x0x0x0index399 = readrel418->getIndex(ord417, false);
      std::vector<u16> ord419({1, 3, 2, 0});
      slog::Relation* readrel420 = db->getRelation("eval_args");
      eval_argsindex400 = readrel420->getIndex(ord419, false);
      std::vector<u16> ord421({1, 3, 2, 0});
      slog::Relation* readrel422 = db->getRelation("eval_args");
      eval_argsdelta404 = readrel422->getIndex(ord421, true);
      std::vector<u16> ord423({0, 1});
      slog::Relation* readrel424 = db->getRelation("eval_args_ans");
      eval_args_ansindex401 = readrel424->getIndex(ord423, false);
      std::vector<u16> ord425({0, 1});
      slog::Relation* readrel426 = db->getRelation("eval_args_ans");
      eval_args_ansdelta405 = readrel426->getIndex(ord425, true);
  
    }
    ReadTask406(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c114 = _t[0];
        u64 v_c115 = _t[1];
        slog::join_probe_old<2,1>(primindex396, primdelta402, std::array<u64,2>{v_c115, 0}, [&](const std::array<u64,2>& m427) {
          u64 v_c116 = m427[1];
          slog::join_probe_old<4,1>(evalindex397, evaldelta403, std::array<u64,4>{v_c114, 0, 0, 0}, [&](const std::array<u64,4>& m428) {
            u64 v_c52 = m428[1]; u64 v_c39 = m428[2]; u64 v_c7 = m428[3];
            if (!slog::exists_probe<4,2>(eval_argsindex398, std::array<u64,4>{v_c7, v_c39, 0, 0})) return;
            slog::join_probe<5,3>($sup70016x75x0x0x0index399, std::array<u64,5>{v_c52, v_c39, v_c7, 0, 0}, [&](const std::array<u64,5>& m429) {
              u64 v_c53 = m429[3]; u64 v_c5 = m429[4];
              slog::join_probe_old<4,3>(eval_argsindex400, eval_argsdelta404, std::array<u64,4>{v_c53, v_c7, v_c39, 0}, [&](const std::array<u64,4>& m430) {
                u64 v_c117 = m430[3];
                slog::join_probe_old<2,1>(eval_args_ansindex401, eval_args_ansdelta405, std::array<u64,2>{v_c117, 0}, [&](const std::array<u64,2>& m431) {
                  u64 v_c118 = m431[1];
                  ++_fires;
                  slog::emit_struct<3>(head_rel[0], newbatch[0], std::array<u64,2>{v_c116, v_c118}, std::array<u16,3>{1, 2, 0});
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:76", "delta:eval_ans", _fires);
  
      if (!_done)
      {
        ReadTask406* _cont = new ReadTask406(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask406(db,b), false);
  // (crule (pre (let __trid3uoS1058 const5d6ab4fefffae2e4c15033db) (let __trel6yFB1059 const52b5e20f559958f34e533431) (let __tcol6Bcn1060 const6b86b273ff34fce19d6b804e) (let __trel6nqp1061 const65c80aac3433a01ef8a7f298) (let __tcol0oGB1062 const6b86b273ff34fce19d6b804e) (let __trel25zN1063 const65c80aac3433a01ef8a7f298) (let __tcol34iC1064 constd4735e3a265e16eee03f5971)) (scan letrec __t4cK3622 x er eb) (body (exists mp_put (2 3 0 1) 1 x) (exists eval (1 2 3 0) 1 er) (join eval (1 2 3 0) 1 __t4cK3622 rho t __7yeU1057) (exists eval (3 1 0 2) 2 t er) (join-old mp_put (1 2 3 0) 3 (1 2 3 0) rho x t __t5ODE624) (exists mp_put_ans (0 1) 1 __t5ODE624) (join-old eval (3 1 0 2) 2 (3 1 0 2) t er __t4Pyv623 rho2) (join mp_put_ans (0 1) 2 __t5ODE624 rho2) (join eval_ans (0 1) 1 __t4Pyv623 vr)) (head (tycheck t (accept seq) __trid3uoS1058 __trel6yFB1059 __tcol6Bcn1060 (1 2 3 4 0)) (tycheck t (accept seq) __trid3uoS1058 __trel6nqp1061 __tcol0oGB1062 (1 2 3 4 0)) (tycheck t (accept seq) __trid3uoS1058 __trel25zN1063 __tcol34iC1064 (1 2 3 4 0)) (emit store (0 1 2) x t vr) (emit binding_event (0 1 2) x t t)) interp.slog:98 #f)
  class ReadTask443 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[5];
    slog::Index** head_index[5];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_putindex432;  slog::Index** evalindex433;  slog::Index** evalindex434;  slog::Index** evalindex435;  slog::Index** mp_putindex436;  slog::Index** mp_put_ansindex437;  slog::Index** evalindex438;  slog::Index** mp_put_ansindex439;  slog::Index** eval_ansindex440;  slog::Index** mp_putdelta441;  slog::Index** evaldelta442;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("malformed_deduction");
      head_rel[3] = db->getRelation("store");
      std::vector<u16> ord444({0, 1, 2});
      slog::Relation* readrel445 = db->getRelation("store");
      head_index[3] = readrel445->getIndex(ord444, false);
      head_rel[4] = db->getRelation("binding_event");
      std::vector<u16> ord446({0, 1, 2});
      slog::Relation* readrel447 = db->getRelation("binding_event");
      head_index[4] = readrel447->getIndex(ord446, false);
      outer_rel = db->getRelation("letrec");
      std::vector<u16> ord448({2, 3, 0, 1});
      slog::Relation* readrel449 = db->getRelation("mp_put");
      mp_putindex432 = readrel449->getIndex(ord448, false);
      std::vector<u16> ord450({1, 2, 3, 0});
      slog::Relation* readrel451 = db->getRelation("eval");
      evalindex433 = readrel451->getIndex(ord450, false);
      std::vector<u16> ord452({1, 2, 3, 0});
      slog::Relation* readrel453 = db->getRelation("eval");
      evalindex434 = readrel453->getIndex(ord452, false);
      std::vector<u16> ord454({3, 1, 0, 2});
      slog::Relation* readrel455 = db->getRelation("eval");
      evalindex435 = readrel455->getIndex(ord454, false);
      std::vector<u16> ord456({1, 2, 3, 0});
      slog::Relation* readrel457 = db->getRelation("mp_put");
      mp_putindex436 = readrel457->getIndex(ord456, false);
      std::vector<u16> ord458({1, 2, 3, 0});
      slog::Relation* readrel459 = db->getRelation("mp_put");
      mp_putdelta441 = readrel459->getIndex(ord458, true);
      std::vector<u16> ord460({0, 1});
      slog::Relation* readrel461 = db->getRelation("mp_put_ans");
      mp_put_ansindex437 = readrel461->getIndex(ord460, false);
      std::vector<u16> ord462({3, 1, 0, 2});
      slog::Relation* readrel463 = db->getRelation("eval");
      evalindex438 = readrel463->getIndex(ord462, false);
      std::vector<u16> ord464({3, 1, 0, 2});
      slog::Relation* readrel465 = db->getRelation("eval");
      evaldelta442 = readrel465->getIndex(ord464, true);
      std::vector<u16> ord466({0, 1});
      slog::Relation* readrel467 = db->getRelation("mp_put_ans");
      mp_put_ansindex439 = readrel467->getIndex(ord466, false);
      std::vector<u16> ord468({0, 1});
      slog::Relation* readrel469 = db->getRelation("eval_ans");
      eval_ansindex440 = readrel469->getIndex(ord468, false);
  
    }
    ReadTask443(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c119 = v_const5d6ab4fefffae2e4c15033db;
      u64 v_c120 = v_const52b5e20f559958f34e533431;
      u64 v_c121 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c122 = v_const65c80aac3433a01ef8a7f298;
      u64 v_c123 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c124 = v_const65c80aac3433a01ef8a7f298;
      u64 v_c125 = v_constd4735e3a265e16eee03f5971;
  
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
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c126 = _t[0];
        u64 v_c40 = _t[1];
        u64 v_c36 = _t[2];
        u64 v_c33 = _t[3];
        if (!slog::exists_probe<4,1>(mp_putindex432, std::array<u64,4>{v_c40, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(evalindex433, std::array<u64,4>{v_c36, 0, 0, 0})) return;
        slog::join_probe<4,1>(evalindex434, std::array<u64,4>{v_c126, 0, 0, 0}, [&](const std::array<u64,4>& m470) {
          u64 v_c39 = m470[1]; u64 v_c7 = m470[2]; u64 v_c127 = m470[3];
          if (!slog::exists_probe<4,2>(evalindex435, std::array<u64,4>{v_c7, v_c36, 0, 0})) return;
          slog::join_probe_old<4,3>(mp_putindex436, mp_putdelta441, std::array<u64,4>{v_c39, v_c40, v_c7, 0}, [&](const std::array<u64,4>& m471) {
            u64 v_c128 = m471[3];
            if (!slog::exists_probe<2,1>(mp_put_ansindex437, std::array<u64,2>{v_c128, 0})) return;
            slog::join_probe_old<4,2>(evalindex438, evaldelta442, std::array<u64,4>{v_c7, v_c36, 0, 0}, [&](const std::array<u64,4>& m472) {
              u64 v_c129 = m472[2]; u64 v_c34 = m472[3];
              slog::join_probe<2,2>(mp_put_ansindex439, std::array<u64,2>{v_c128, v_c34}, [&](const std::array<u64,2>& m473) {
                slog::join_probe<2,1>(eval_ansindex440, std::array<u64,2>{v_c129, 0}, [&](const std::array<u64,2>& m474) {
                  u64 v_c42 = m474[1];
                  ++_fires;
                  if (!(is_seq(v_c7)))
                  {
                    slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c119, v_c120, v_c121, v_c7}, std::array<u16,5>{1, 2, 3, 4, 0});
                    return;
                  }
                  if (!(is_seq(v_c7)))
                  {
                    slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c119, v_c122, v_c123, v_c7}, std::array<u16,5>{1, 2, 3, 4, 0});
                    return;
                  }
                  if (!(is_seq(v_c7)))
                  {
                    slog::emit_struct<5>(head_rel[2], newbatch[2], std::array<u64,4>{v_c119, v_c124, v_c125, v_c7}, std::array<u16,5>{1, 2, 3, 4, 0});
                    return;
                  }
                  slog::emit<3>(head_rel[3], head_index[3], newbatch[3], std::array<u64,3>{v_c40, v_c7, v_c42}, std::array<u16,3>{0, 1, 2});
                  slog::emit<3>(head_rel[4], head_index[4], newbatch[4], std::array<u64,3>{v_c40, v_c7, v_c7}, std::array<u16,3>{0, 1, 2});
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
  
      if (_fires) db->bumpFires("interp.slog:98", "delta:letrec", _fires);
  
      if (!_done)
      {
        ReadTask443* _cont = new ReadTask443(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask443(db,b), false);
  // (crule (pre (let __tconst8HHZ1552 constb9e118781cea1f9fa01462e0)) (seeded) (body (join _enum (1 0) 1 __tconst8HHZ1552 __t7uDW271) (join boolval (1 0) 1 __t7uDW271 __t48JJ272)) (head (emit scheme_false (0) __t48JJ272)) interp.slog:82 #f)
  class ReadTask477 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
  
  
  
  
  
  
    slog::Index** _enumindex475;  slog::Index** boolvalindex476;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("scheme_false");
      std::vector<u16> ord478({0});
      slog::Relation* readrel479 = db->getRelation("scheme_false");
      head_index[0] = readrel479->getIndex(ord478, false);
      std::vector<u16> ord480({1, 0});
      slog::Relation* readrel481 = db->getRelation("_enum");
      _enumindex475 = readrel481->getIndex(ord480, false);
      std::vector<u16> ord482({1, 0});
      slog::Relation* readrel483 = db->getRelation("boolval");
      boolvalindex476 = readrel483->getIndex(ord482, false);
  
    }
    ReadTask477(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c130 = v_constb9e118781cea1f9fa01462e0;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      slog::join_probe<2,1>(_enumindex475, std::array<u64,2>{v_c130, 0}, [&](const std::array<u64,2>& m484) {
        u64 v_c131 = m484[1];
        slog::join_probe<2,1>(boolvalindex476, std::array<u64,2>{v_c131, 0}, [&](const std::array<u64,2>& m485) {
          u64 v_c132 = m485[1];
          ++_fires;
          slog::emit<1>(head_rel[0], head_index[0], newbatch[0], std::array<u64,1>{v_c132}, std::array<u16,1>{0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:82", "seeded", _fires);
  
      return true;
  
    }
    };
    for (u16 b = 0; b < 1; ++b)
      s->addTaskSeeded(phase_read, new ReadTask477(db,b));
  // (crule (pre) (scan sym __t4xHt652 s) (body (join-old eval (1 2 3 0) 1 (1 2 3 0) __t4xHt652 rho t __t5IFg653)) (head (emit-temp temp9x9w1897 __t5IFg653 s) (mkstruct symval (1 0) __t2tjI651 s)) interp.slog:32 #f)
  class ReadTask488 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex486;  slog::Index** evaldelta487;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9x9w1897");
      head_rel[1] = db->getRelation("symval");
      outer_rel = db->getRelation("sym");
      std::vector<u16> ord489({1, 2, 3, 0});
      slog::Relation* readrel490 = db->getRelation("eval");
      evalindex486 = readrel490->getIndex(ord489, false);
      std::vector<u16> ord491({1, 2, 3, 0});
      slog::Relation* readrel492 = db->getRelation("eval");
      evaldelta487 = readrel492->getIndex(ord491, true);
  
    }
    ReadTask488(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c133 = _t[0];
        u64 v_c60 = _t[1];
        slog::join_probe_old<4,1>(evalindex486, evaldelta487, std::array<u64,4>{v_c133, 0, 0, 0}, [&](const std::array<u64,4>& m493) {
          u64 v_c39 = m493[1]; u64 v_c7 = m493[2]; u64 v_c134 = m493[3];
          ++_fires;
          slog::emit_temp<2>(head_rel[0], newbatch[0], std::array<u64,2>{v_c134, v_c60});
          slog::emit_struct<2>(head_rel[1], newbatch[1], std::array<u64,1>{v_c60}, std::array<u16,2>{1, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:32", "delta:sym", _fires);
  
      if (!_done)
      {
        ReadTask488* _cont = new ReadTask488(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask488(db,b), false);
  // (crule (pre) (scan eval __1KGF1410 __t06G7423 rho t) (body (join-old letrec (0 1 2 3) 1 (0 1 2 3) __t06G7423 x er eb)) (head (mkstruct mp_put (1 2 3 0) __9PdX1411 rho x t)) interp.slog:98 #f)
  class ReadTask496 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letrecindex494;  slog::Index** letrecdelta495;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put");
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord497({0, 1, 2, 3});
      slog::Relation* readrel498 = db->getRelation("letrec");
      letrecindex494 = readrel498->getIndex(ord497, false);
      std::vector<u16> ord499({0, 1, 2, 3});
      slog::Relation* readrel500 = db->getRelation("letrec");
      letrecdelta495 = readrel500->getIndex(ord499, true);
  
    }
    ReadTask496(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c135 = _t[0];
        u64 v_c136 = _t[1];
        u64 v_c39 = _t[2];
        u64 v_c7 = _t[3];
        slog::join_probe_old<4,1>(letrecindex494, letrecdelta495, std::array<u64,4>{v_c136, 0, 0, 0}, [&](const std::array<u64,4>& m501) {
          u64 v_c40 = m501[1]; u64 v_c36 = m501[2]; u64 v_c33 = m501[3];
          ++_fires;
          slog::emit_struct<4>(head_rel[0], newbatch[0], std::array<u64,3>{v_c39, v_c40, v_c7}, std::array<u16,4>{1, 2, 3, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:98", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask496* _cont = new ReadTask496(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask496(db,b), false);
  // (crule (pre (let __trid3uoS1058 const5d6ab4fefffae2e4c15033db) (let __trel6yFB1059 const52b5e20f559958f34e533431) (let __tcol6Bcn1060 const6b86b273ff34fce19d6b804e) (let __trel6nqp1061 const65c80aac3433a01ef8a7f298) (let __tcol0oGB1062 const6b86b273ff34fce19d6b804e) (let __trel25zN1063 const65c80aac3433a01ef8a7f298) (let __tcol34iC1064 constd4735e3a265e16eee03f5971)) (scan mp_put __t5ODE624 rho x t) (body (exists letrec (1 2 3 0) 1 x) (exists eval (3 1 0 2) 1 t) (exists mp_put_ans (0 1) 1 __t5ODE624) (join eval (2 3 0 1) 2 rho t __7yeU1057 __t4cK3622) (join letrec (0 1 2 3) 2 __t4cK3622 x er eb) (join eval (3 1 0 2) 2 t er __t4Pyv623 rho2) (join mp_put_ans (0 1) 2 __t5ODE624 rho2) (join eval_ans (0 1) 1 __t4Pyv623 vr)) (head (tycheck t (accept seq) __trid3uoS1058 __trel6yFB1059 __tcol6Bcn1060 (1 2 3 4 0)) (tycheck t (accept seq) __trid3uoS1058 __trel6nqp1061 __tcol0oGB1062 (1 2 3 4 0)) (tycheck t (accept seq) __trid3uoS1058 __trel25zN1063 __tcol34iC1064 (1 2 3 4 0)) (emit store (0 1 2) x t vr) (emit binding_event (0 1 2) x t t)) interp.slog:98 #f)
  class ReadTask510 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[5];
    slog::Index** head_index[5];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letrecindex502;  slog::Index** evalindex503;  slog::Index** mp_put_ansindex504;  slog::Index** evalindex505;  slog::Index** letrecindex506;  slog::Index** evalindex507;  slog::Index** mp_put_ansindex508;  slog::Index** eval_ansindex509;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("malformed_deduction");
      head_rel[3] = db->getRelation("store");
      std::vector<u16> ord511({0, 1, 2});
      slog::Relation* readrel512 = db->getRelation("store");
      head_index[3] = readrel512->getIndex(ord511, false);
      head_rel[4] = db->getRelation("binding_event");
      std::vector<u16> ord513({0, 1, 2});
      slog::Relation* readrel514 = db->getRelation("binding_event");
      head_index[4] = readrel514->getIndex(ord513, false);
      outer_rel = db->getRelation("mp_put");
      std::vector<u16> ord515({1, 2, 3, 0});
      slog::Relation* readrel516 = db->getRelation("letrec");
      letrecindex502 = readrel516->getIndex(ord515, false);
      std::vector<u16> ord517({3, 1, 0, 2});
      slog::Relation* readrel518 = db->getRelation("eval");
      evalindex503 = readrel518->getIndex(ord517, false);
      std::vector<u16> ord519({0, 1});
      slog::Relation* readrel520 = db->getRelation("mp_put_ans");
      mp_put_ansindex504 = readrel520->getIndex(ord519, false);
      std::vector<u16> ord521({2, 3, 0, 1});
      slog::Relation* readrel522 = db->getRelation("eval");
      evalindex505 = readrel522->getIndex(ord521, false);
      std::vector<u16> ord523({0, 1, 2, 3});
      slog::Relation* readrel524 = db->getRelation("letrec");
      letrecindex506 = readrel524->getIndex(ord523, false);
      std::vector<u16> ord525({3, 1, 0, 2});
      slog::Relation* readrel526 = db->getRelation("eval");
      evalindex507 = readrel526->getIndex(ord525, false);
      std::vector<u16> ord527({0, 1});
      slog::Relation* readrel528 = db->getRelation("mp_put_ans");
      mp_put_ansindex508 = readrel528->getIndex(ord527, false);
      std::vector<u16> ord529({0, 1});
      slog::Relation* readrel530 = db->getRelation("eval_ans");
      eval_ansindex509 = readrel530->getIndex(ord529, false);
  
    }
    ReadTask510(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c119 = v_const5d6ab4fefffae2e4c15033db;
      u64 v_c120 = v_const52b5e20f559958f34e533431;
      u64 v_c121 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c122 = v_const65c80aac3433a01ef8a7f298;
      u64 v_c123 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c124 = v_const65c80aac3433a01ef8a7f298;
      u64 v_c125 = v_constd4735e3a265e16eee03f5971;
  
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
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c128 = _t[0];
        u64 v_c39 = _t[1];
        u64 v_c40 = _t[2];
        u64 v_c7 = _t[3];
        if (!slog::exists_probe<4,1>(letrecindex502, std::array<u64,4>{v_c40, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(evalindex503, std::array<u64,4>{v_c7, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_put_ansindex504, std::array<u64,2>{v_c128, 0})) return;
        slog::join_probe<4,2>(evalindex505, std::array<u64,4>{v_c39, v_c7, 0, 0}, [&](const std::array<u64,4>& m531) {
          u64 v_c127 = m531[2]; u64 v_c126 = m531[3];
          slog::join_probe<4,2>(letrecindex506, std::array<u64,4>{v_c126, v_c40, 0, 0}, [&](const std::array<u64,4>& m532) {
            u64 v_c36 = m532[2]; u64 v_c33 = m532[3];
            slog::join_probe<4,2>(evalindex507, std::array<u64,4>{v_c7, v_c36, 0, 0}, [&](const std::array<u64,4>& m533) {
              u64 v_c129 = m533[2]; u64 v_c34 = m533[3];
              slog::join_probe<2,2>(mp_put_ansindex508, std::array<u64,2>{v_c128, v_c34}, [&](const std::array<u64,2>& m534) {
                slog::join_probe<2,1>(eval_ansindex509, std::array<u64,2>{v_c129, 0}, [&](const std::array<u64,2>& m535) {
                  u64 v_c42 = m535[1];
                  ++_fires;
                  if (!(is_seq(v_c7)))
                  {
                    slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c119, v_c120, v_c121, v_c7}, std::array<u16,5>{1, 2, 3, 4, 0});
                    return;
                  }
                  if (!(is_seq(v_c7)))
                  {
                    slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c119, v_c122, v_c123, v_c7}, std::array<u16,5>{1, 2, 3, 4, 0});
                    return;
                  }
                  if (!(is_seq(v_c7)))
                  {
                    slog::emit_struct<5>(head_rel[2], newbatch[2], std::array<u64,4>{v_c119, v_c124, v_c125, v_c7}, std::array<u16,5>{1, 2, 3, 4, 0});
                    return;
                  }
                  slog::emit<3>(head_rel[3], head_index[3], newbatch[3], std::array<u64,3>{v_c40, v_c7, v_c42}, std::array<u16,3>{0, 1, 2});
                  slog::emit<3>(head_rel[4], head_index[4], newbatch[4], std::array<u64,3>{v_c40, v_c7, v_c7}, std::array<u16,3>{0, 1, 2});
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
  
      if (_fires) db->bumpFires("interp.slog:98", "delta:mp_put", _fires);
  
      if (!_done)
      {
        ReadTask510* _cont = new ReadTask510(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask510(db,b), false);
  // (crule (pre) (scan mp_put_ans __t42s0769 rho2) (body (join-old mp_put (0 2 1 3) 1 (0 2 1 3) __t42s0769 x rho t) (join $sup70016x95x0x0x0 (3 4 5 0 1 2) 3 rho t x __d0 eb er)) (head (emit $sup70016x95x0x0x1 (1 5 0 2 3 4 6 7) __t42s0769 rho2 __d0 eb er rho t x)) interp.slog:96 #f)
  class ReadTask539 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_putindex536;  slog::Index** $sup70016x95x0x0x0index537;  slog::Index** mp_putdelta538;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup70016x95x0x0x1");
      std::vector<u16> ord540({1, 5, 0, 2, 3, 4, 6, 7});
      slog::Relation* readrel541 = db->getRelation("$sup70016x95x0x0x1");
      head_index[0] = readrel541->getIndex(ord540, false);
      outer_rel = db->getRelation("mp_put_ans");
      std::vector<u16> ord542({0, 2, 1, 3});
      slog::Relation* readrel543 = db->getRelation("mp_put");
      mp_putindex536 = readrel543->getIndex(ord542, false);
      std::vector<u16> ord544({0, 2, 1, 3});
      slog::Relation* readrel545 = db->getRelation("mp_put");
      mp_putdelta538 = readrel545->getIndex(ord544, true);
      std::vector<u16> ord546({3, 4, 5, 0, 1, 2});
      slog::Relation* readrel547 = db->getRelation("$sup70016x95x0x0x0");
      $sup70016x95x0x0x0index537 = readrel547->getIndex(ord546, false);
  
    }
    ReadTask539(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c137 = _t[0];
        u64 v_c34 = _t[1];
        slog::join_probe_old<4,1>(mp_putindex536, mp_putdelta538, std::array<u64,4>{v_c137, 0, 0, 0}, [&](const std::array<u64,4>& m548) {
          u64 v_c40 = m548[1]; u64 v_c39 = m548[2]; u64 v_c7 = m548[3];
          slog::join_probe<6,3>($sup70016x95x0x0x0index537, std::array<u64,6>{v_c39, v_c7, v_c40, 0, 0, 0}, [&](const std::array<u64,6>& m549) {
            u64 v_c5 = m549[3]; u64 v_c33 = m549[4]; u64 v_c36 = m549[5];
            ++_fires;
            slog::emit<8>(head_rel[0], head_index[0], newbatch[0], std::array<u64,8>{v_c137, v_c34, v_c5, v_c33, v_c36, v_c39, v_c7, v_c40}, std::array<u16,8>{1, 5, 0, 2, 3, 4, 6, 7});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:96", "delta:mp_put_ans", _fires);
  
      if (!_done)
      {
        ReadTask539* _cont = new ReadTask539(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask539(db,b), false);
  // (crule (pre) (scan temp7xOk1832 __t1OhY558 __t4vLM557 rho) (body (join closure (1 2 0) 2 __t4vLM557 rho __t7c6K556)) (head (emit eval_ans (0 1) __t1OhY558 __t7c6K556)) interp.slog:33 #f)
  class ReadTask551 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** closureindex550;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord552({0, 1});
      slog::Relation* readrel553 = db->getRelation("eval_ans");
      head_index[0] = readrel553->getIndex(ord552, false);
      outer_rel = db->getRelation("temp7xOk1832");
      std::vector<u16> ord554({1, 2, 0});
      slog::Relation* readrel555 = db->getRelation("closure");
      closureindex550 = readrel555->getIndex(ord554, false);
  
    }
    ReadTask551(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c138 = _t[0];
        u64 v_c139 = _t[1];
        u64 v_c39 = _t[2];
        slog::join_probe<3,2>(closureindex550, std::array<u64,3>{v_c139, v_c39, 0}, [&](const std::array<u64,3>& m556) {
          u64 v_c140 = m556[2];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c138, v_c140}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:33", "delta:temp7xOk1832", _fires);
  
      if (!_done)
      {
        ReadTask551* _cont = new ReadTask551(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask551(db,b), false);
  // (crule (pre) (scan if __t0z7d550 e1 e2 e3) (body (join-old eval (1 2 3 0) 1 (1 2 3 0) __t0z7d550 rho t __t6IYB551)) (head (emit $sup70016x87x0x0x0 (2 3 1 0 4 5) e2 e3 e1 __t6IYB551 rho t)) interp.slog:88 #f)
  class ReadTask559 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex557;  slog::Index** evaldelta558;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup70016x87x0x0x0");
      std::vector<u16> ord560({2, 3, 1, 0, 4, 5});
      slog::Relation* readrel561 = db->getRelation("$sup70016x87x0x0x0");
      head_index[0] = readrel561->getIndex(ord560, false);
      outer_rel = db->getRelation("if");
      std::vector<u16> ord562({1, 2, 3, 0});
      slog::Relation* readrel563 = db->getRelation("eval");
      evalindex557 = readrel563->getIndex(ord562, false);
      std::vector<u16> ord564({1, 2, 3, 0});
      slog::Relation* readrel565 = db->getRelation("eval");
      evaldelta558 = readrel565->getIndex(ord564, true);
  
    }
    ReadTask559(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c141 = _t[0];
        u64 v_c142 = _t[1];
        u64 v_c143 = _t[2];
        u64 v_c144 = _t[3];
        slog::join_probe_old<4,1>(evalindex557, evaldelta558, std::array<u64,4>{v_c141, 0, 0, 0}, [&](const std::array<u64,4>& m566) {
          u64 v_c39 = m566[1]; u64 v_c7 = m566[2]; u64 v_c145 = m566[3];
          ++_fires;
          slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c143, v_c144, v_c142, v_c145, v_c39, v_c7}, std::array<u16,6>{2, 3, 1, 0, 4, 5});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:88", "delta:if", _fires);
  
      if (!_done)
      {
        ReadTask559* _cont = new ReadTask559(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask559(db,b), false);
  // (crule (pre) (scan temp3MZb2062 __t2hbE115 __v0 m p r) (body (join mbranch (1 2 3 4 0) 4 p m __v0 r __t9UHh112)) (head (emit mp_union_ans (0 1) __t2hbE115 __t9UHh112)) map.slog:96 #f)
  class ReadTask568 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex567;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord569({0, 1});
      slog::Relation* readrel570 = db->getRelation("mp_union_ans");
      head_index[0] = readrel570->getIndex(ord569, false);
      outer_rel = db->getRelation("temp3MZb2062");
      std::vector<u16> ord571({1, 2, 3, 4, 0});
      slog::Relation* readrel572 = db->getRelation("mbranch");
      mbranchindex567 = readrel572->getIndex(ord571, false);
  
    }
    ReadTask568(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c146 = _t[0];
        u64 v_c11 = _t[1];
        u64 v_c10 = _t[2];
        u64 v_c15 = _t[3];
        u64 v_c16 = _t[4];
        slog::join_probe<5,4>(mbranchindex567, std::array<u64,5>{v_c15, v_c10, v_c11, v_c16, 0}, [&](const std::array<u64,5>& m573) {
          u64 v_c147 = m573[4];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c146, v_c147}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:96", "delta:temp3MZb2062", _fires);
  
      if (!_done)
      {
        ReadTask568* _cont = new ReadTask568(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask568(db,b), false);
  // (crule (pre (let __tconst35Xg1071 const0122baa3ac55f1b433944eb1)) (scan temp1yql1955 __t8l3B107) (body (join _enum (1 0) 1 __tconst35Xg1071 __t6gQ5104) (join boolval (1 0) 1 __t6gQ5104 __t274c105)) (head (emit delta_ans (0 1) __t8l3B107 __t274c105)) interp.slog:122 #f)
  class ReadTask576 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex574;  slog::Index** boolvalindex575;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("delta_ans");
      std::vector<u16> ord577({0, 1});
      slog::Relation* readrel578 = db->getRelation("delta_ans");
      head_index[0] = readrel578->getIndex(ord577, false);
      outer_rel = db->getRelation("temp1yql1955");
      std::vector<u16> ord579({1, 0});
      slog::Relation* readrel580 = db->getRelation("_enum");
      _enumindex574 = readrel580->getIndex(ord579, false);
      std::vector<u16> ord581({1, 0});
      slog::Relation* readrel582 = db->getRelation("boolval");
      boolvalindex575 = readrel582->getIndex(ord581, false);
  
    }
    ReadTask576(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c148 = v_const0122baa3ac55f1b433944eb1;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c149 = _t[0];
        slog::join_probe<2,1>(_enumindex574, std::array<u64,2>{v_c148, 0}, [&](const std::array<u64,2>& m583) {
          u64 v_c150 = m583[1];
          slog::join_probe<2,1>(boolvalindex575, std::array<u64,2>{v_c150, 0}, [&](const std::array<u64,2>& m584) {
            u64 v_c151 = m584[1];
            ++_fires;
            slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c149, v_c151}, std::array<u16,2>{0, 1});
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:122", "delta:temp1yql1955", _fires);
  
      if (!_done)
      {
        ReadTask576* _cont = new ReadTask576(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask576(db,b), false);
  // (crule (pre (let __tconst9P2l620 const6b86b273ff34fce19d6b804e)) (scan mp_has0 __t645L619 __t9QVv618 k) (body (join mbranch (0 1 2 3 4) 1 __t9QVv618 p m l r) (let __t9jb4621 (band k m)) (cmp lt __t9jb4621 __tconst9P2l620)) (head (emit $sup5638x60x0x0x0 (4 2 3 5 0 1) p l m r __t645L619 k)) map.slog:61 #f)
  class ReadTask586 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex585;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x60x0x0x0");
      std::vector<u16> ord587({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel588 = db->getRelation("$sup5638x60x0x0x0");
      head_index[0] = readrel588->getIndex(ord587, false);
      outer_rel = db->getRelation("mp_has0");
      std::vector<u16> ord589({0, 1, 2, 3, 4});
      slog::Relation* readrel590 = db->getRelation("mbranch");
      mbranchindex585 = readrel590->getIndex(ord589, false);
  
    }
    ReadTask586(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c152 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c153 = _t[0];
        u64 v_c154 = _t[1];
        u64 v_c6 = _t[2];
        slog::join_probe<5,1>(mbranchindex585, std::array<u64,5>{v_c154, 0, 0, 0, 0}, [&](const std::array<u64,5>& m591) {
          u64 v_c15 = m591[1]; u64 v_c10 = m591[2]; u64 v_c14 = m591[3]; u64 v_c16 = m591[4];
          u64 v_c155 = _prim_band(db, v_c6, v_c10);
          if (v_c155 == slog_error) { slog::emit_pending_error(db, "map.slog:61"); return; }
          u64 v_c156 = _prim_lt(db, v_c155, v_c152);
          if (v_c156 == slog_error) { slog::emit_pending_error(db, "map.slog:61"); return; }
          if (!v_c156) return;
          ++_fires;
          slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c15, v_c14, v_c10, v_c16, v_c153, v_c6}, std::array<u16,6>{4, 2, 3, 5, 0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:61", "delta:mp_has0", _fires);
  
      if (!_done)
      {
        ReadTask586* _cont = new ReadTask586(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask586(db,b), false);
  // (crule (pre) (scan mp_join __t77mZ27 p __t7Hza25 q __t3dlR26) (body (neq p q) (exists mbranch (0 1 2 3 4) 2 __t7Hza25 p) (exists mbranch (0 1 2 3 4) 2 __t3dlR26 q) (exists mp_join_ans (0 1) 1 __t77mZ27) (join mp_union (1 2 0) 2 __t7Hza25 __t3dlR26 __t2vfE24) (join mbranch (0 1 2 3 4) 2 __t7Hza25 p m l r) (join mbranch (0 1 2 3 4) 3 __t3dlR26 q m u v) (join mp_join_ans (0 1) 1 __t77mZ27 res)) (head (emit mp_union_ans (0 1) __t2vfE24 res)) map.slog:114 #f)
  class ReadTask600 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex593;  slog::Index** mbranchindex594;  slog::Index** mp_join_ansindex595;  slog::Index** mp_unionindex596;  slog::Index** mbranchindex597;  slog::Index** mbranchindex598;  slog::Index** mp_join_ansindex599;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_union_ans");
      std::vector<u16> ord601({0, 1});
      slog::Relation* readrel602 = db->getRelation("mp_union_ans");
      head_index[0] = readrel602->getIndex(ord601, false);
      outer_rel = db->getRelation("mp_join");
      std::vector<u16> ord603({0, 1, 2, 3, 4});
      slog::Relation* readrel604 = db->getRelation("mbranch");
      mbranchindex593 = readrel604->getIndex(ord603, false);
      std::vector<u16> ord605({0, 1, 2, 3, 4});
      slog::Relation* readrel606 = db->getRelation("mbranch");
      mbranchindex594 = readrel606->getIndex(ord605, false);
      std::vector<u16> ord607({0, 1});
      slog::Relation* readrel608 = db->getRelation("mp_join_ans");
      mp_join_ansindex595 = readrel608->getIndex(ord607, false);
      std::vector<u16> ord609({1, 2, 0});
      slog::Relation* readrel610 = db->getRelation("mp_union");
      mp_unionindex596 = readrel610->getIndex(ord609, false);
      std::vector<u16> ord611({0, 1, 2, 3, 4});
      slog::Relation* readrel612 = db->getRelation("mbranch");
      mbranchindex597 = readrel612->getIndex(ord611, false);
      std::vector<u16> ord613({0, 1, 2, 3, 4});
      slog::Relation* readrel614 = db->getRelation("mbranch");
      mbranchindex598 = readrel614->getIndex(ord613, false);
      std::vector<u16> ord615({0, 1});
      slog::Relation* readrel616 = db->getRelation("mp_join_ans");
      mp_join_ansindex599 = readrel616->getIndex(ord615, false);
  
    }
    ReadTask600(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c157 = _t[0];
        u64 v_c15 = _t[1];
        u64 v_c158 = _t[2];
        u64 v_c22 = _t[3];
        u64 v_c159 = _t[4];
        if (v_c15 == v_c22) return;
        if (!slog::exists_probe<5,2>(mbranchindex593, std::array<u64,5>{v_c158, v_c15, 0, 0, 0})) return;
        if (!slog::exists_probe<5,2>(mbranchindex594, std::array<u64,5>{v_c159, v_c22, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_join_ansindex595, std::array<u64,2>{v_c157, 0})) return;
        slog::join_probe<3,2>(mp_unionindex596, std::array<u64,3>{v_c158, v_c159, 0}, [&](const std::array<u64,3>& m617) {
          u64 v_c160 = m617[2];
          slog::join_probe<5,2>(mbranchindex597, std::array<u64,5>{v_c158, v_c15, 0, 0, 0}, [&](const std::array<u64,5>& m618) {
            u64 v_c10 = m618[2]; u64 v_c14 = m618[3]; u64 v_c16 = m618[4];
            slog::join_probe<5,3>(mbranchindex598, std::array<u64,5>{v_c159, v_c22, v_c10, 0, 0}, [&](const std::array<u64,5>& m619) {
              u64 v_c25 = m619[3]; u64 v_c8 = m619[4];
              slog::join_probe<2,1>(mp_join_ansindex599, std::array<u64,2>{v_c157, 0}, [&](const std::array<u64,2>& m620) {
                u64 v_c19 = m620[1];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c160, v_c19}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:114", "delta:mp_join", _fires);
  
      if (!_done)
      {
        ReadTask600* _cont = new ReadTask600(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask600(db,b), false);
  // (crule (pre) (scan mp_union __t8pY8370 __t6Cxo369 t) (body (join mleaf (0 1 2) 1 __t6Cxo369 k v)) (head (mkstruct mp_put (1 2 3 0) __2kOd1560 t k v)) map.slog:92 #f)
  class ReadTask622 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mleafindex621;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put");
      outer_rel = db->getRelation("mp_union");
      std::vector<u16> ord623({0, 1, 2});
      slog::Relation* readrel624 = db->getRelation("mleaf");
      mleafindex621 = readrel624->getIndex(ord623, false);
  
    }
    ReadTask622(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c161 = _t[0];
        u64 v_c162 = _t[1];
        u64 v_c7 = _t[2];
        slog::join_probe<3,1>(mleafindex621, std::array<u64,3>{v_c162, 0, 0}, [&](const std::array<u64,3>& m625) {
          u64 v_c6 = m625[1]; u64 v_c8 = m625[2];
          ++_fires;
          slog::emit_struct<4>(head_rel[0], newbatch[0], std::array<u64,3>{v_c7, v_c6, v_c8}, std::array<u16,4>{1, 2, 3, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:92", "delta:mp_union", _fires);
  
      if (!_done)
      {
        ReadTask622* _cont = new ReadTask622(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask622(db,b), false);
  // (crule (pre (let __tconst6x3F256 const5feceb66ffc86f38d952786c)) (scan mp_del __t90gb255 __t1mbS254 k) (body (join mbranch (0 1 2 3 4) 1 __t1mbS254 p m l r) (let __t5ss7257 (band k m)) (cmp gt __t5ss7257 __tconst6x3F256)) (head (emit $sup5638x84x0x0x0 (4 2 3 5 0 1) p l m r __t90gb255 k)) map.slog:85 #f)
  class ReadTask627 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex626;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup5638x84x0x0x0");
      std::vector<u16> ord628({4, 2, 3, 5, 0, 1});
      slog::Relation* readrel629 = db->getRelation("$sup5638x84x0x0x0");
      head_index[0] = readrel629->getIndex(ord628, false);
      outer_rel = db->getRelation("mp_del");
      std::vector<u16> ord630({0, 1, 2, 3, 4});
      slog::Relation* readrel631 = db->getRelation("mbranch");
      mbranchindex626 = readrel631->getIndex(ord630, false);
  
    }
    ReadTask627(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c163 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c164 = _t[0];
        u64 v_c165 = _t[1];
        u64 v_c6 = _t[2];
        slog::join_probe<5,1>(mbranchindex626, std::array<u64,5>{v_c165, 0, 0, 0, 0}, [&](const std::array<u64,5>& m632) {
          u64 v_c15 = m632[1]; u64 v_c10 = m632[2]; u64 v_c14 = m632[3]; u64 v_c16 = m632[4];
          u64 v_c166 = _prim_band(db, v_c6, v_c10);
          if (v_c166 == slog_error) { slog::emit_pending_error(db, "map.slog:85"); return; }
          u64 v_c167 = _prim_gt(db, v_c166, v_c163);
          if (v_c167 == slog_error) { slog::emit_pending_error(db, "map.slog:85"); return; }
          if (!v_c167) return;
          ++_fires;
          slog::emit<6>(head_rel[0], head_index[0], newbatch[0], std::array<u64,6>{v_c15, v_c14, v_c10, v_c16, v_c164, v_c6}, std::array<u16,6>{4, 2, 3, 5, 0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:85", "delta:mp_del", _fires);
  
      if (!_done)
      {
        ReadTask627* _cont = new ReadTask627(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask627(db,b), false);
  // (crule (pre) (scan mp_join __t5fYY629 k __t6AYq628 j __t8ls4627) (body (neq j k) (exists mleaf (0 1 2) 2 __t6AYq628 k) (exists mp_put (1 2 3 0) 2 __t8ls4627 k) (exists mp_join_ans (0 1) 1 __t5fYY629) (join mleaf (0 1 2) 2 __t8ls4627 j w) (join mleaf (0 1 2) 2 __t6AYq628 k v) (join mp_put (1 2 3 0) 3 __t8ls4627 k v __t4a7n626) (join mp_join_ans (0 1) 1 __t5fYY629 r)) (head (emit mp_put_ans (0 1) __t4a7n626 r)) map.slog:39 #f)
  class ReadTask641 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mleafindex634;  slog::Index** mp_putindex635;  slog::Index** mp_join_ansindex636;  slog::Index** mleafindex637;  slog::Index** mleafindex638;  slog::Index** mp_putindex639;  slog::Index** mp_join_ansindex640;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_ans");
      std::vector<u16> ord642({0, 1});
      slog::Relation* readrel643 = db->getRelation("mp_put_ans");
      head_index[0] = readrel643->getIndex(ord642, false);
      outer_rel = db->getRelation("mp_join");
      std::vector<u16> ord644({0, 1, 2});
      slog::Relation* readrel645 = db->getRelation("mleaf");
      mleafindex634 = readrel645->getIndex(ord644, false);
      std::vector<u16> ord646({1, 2, 3, 0});
      slog::Relation* readrel647 = db->getRelation("mp_put");
      mp_putindex635 = readrel647->getIndex(ord646, false);
      std::vector<u16> ord648({0, 1});
      slog::Relation* readrel649 = db->getRelation("mp_join_ans");
      mp_join_ansindex636 = readrel649->getIndex(ord648, false);
      std::vector<u16> ord650({0, 1, 2});
      slog::Relation* readrel651 = db->getRelation("mleaf");
      mleafindex637 = readrel651->getIndex(ord650, false);
      std::vector<u16> ord652({0, 1, 2});
      slog::Relation* readrel653 = db->getRelation("mleaf");
      mleafindex638 = readrel653->getIndex(ord652, false);
      std::vector<u16> ord654({1, 2, 3, 0});
      slog::Relation* readrel655 = db->getRelation("mp_put");
      mp_putindex639 = readrel655->getIndex(ord654, false);
      std::vector<u16> ord656({0, 1});
      slog::Relation* readrel657 = db->getRelation("mp_join_ans");
      mp_join_ansindex640 = readrel657->getIndex(ord656, false);
  
    }
    ReadTask641(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c168 = _t[0];
        u64 v_c6 = _t[1];
        u64 v_c169 = _t[2];
        u64 v_c170 = _t[3];
        u64 v_c171 = _t[4];
        if (v_c170 == v_c6) return;
        if (!slog::exists_probe<3,2>(mleafindex634, std::array<u64,3>{v_c169, v_c6, 0})) return;
        if (!slog::exists_probe<4,2>(mp_putindex635, std::array<u64,4>{v_c171, v_c6, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_join_ansindex636, std::array<u64,2>{v_c168, 0})) return;
        slog::join_probe<3,2>(mleafindex637, std::array<u64,3>{v_c171, v_c170, 0}, [&](const std::array<u64,3>& m658) {
          u64 v_c172 = m658[2];
          slog::join_probe<3,2>(mleafindex638, std::array<u64,3>{v_c169, v_c6, 0}, [&](const std::array<u64,3>& m659) {
            u64 v_c8 = m659[2];
            slog::join_probe<4,3>(mp_putindex639, std::array<u64,4>{v_c171, v_c6, v_c8, 0}, [&](const std::array<u64,4>& m660) {
              u64 v_c173 = m660[3];
              slog::join_probe<2,1>(mp_join_ansindex640, std::array<u64,2>{v_c168, 0}, [&](const std::array<u64,2>& m661) {
                u64 v_c16 = m661[1];
                ++_fires;
                slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c173, v_c16}, std::array<u16,2>{0, 1});
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:39", "delta:mp_join", _fires);
  
      if (!_done)
      {
        ReadTask641* _cont = new ReadTask641(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask641(db,b), false);
  // (crule (pre) (scan ref __t6No4296 x) (body (join-old eval (1 2 3 0) 1 (1 2 3 0) __t6No4296 rho t __t3h00297)) (head (emit $sup70016x33x0x0x0 (3 1 0 2) x rho __t3h00297 t)) interp.slog:34 #f)
  class ReadTask664 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** evalindex662;  slog::Index** evaldelta663;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("$sup70016x33x0x0x0");
      std::vector<u16> ord665({3, 1, 0, 2});
      slog::Relation* readrel666 = db->getRelation("$sup70016x33x0x0x0");
      head_index[0] = readrel666->getIndex(ord665, false);
      outer_rel = db->getRelation("ref");
      std::vector<u16> ord667({1, 2, 3, 0});
      slog::Relation* readrel668 = db->getRelation("eval");
      evalindex662 = readrel668->getIndex(ord667, false);
      std::vector<u16> ord669({1, 2, 3, 0});
      slog::Relation* readrel670 = db->getRelation("eval");
      evaldelta663 = readrel670->getIndex(ord669, true);
  
    }
    ReadTask664(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c174 = _t[0];
        u64 v_c40 = _t[1];
        slog::join_probe_old<4,1>(evalindex662, evaldelta663, std::array<u64,4>{v_c174, 0, 0, 0}, [&](const std::array<u64,4>& m671) {
          u64 v_c39 = m671[1]; u64 v_c7 = m671[2]; u64 v_c175 = m671[3];
          ++_fires;
          slog::emit<4>(head_rel[0], head_index[0], newbatch[0], std::array<u64,4>{v_c40, v_c39, v_c175, v_c7}, std::array<u16,4>{3, 1, 0, 2});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:34", "delta:ref", _fires);
  
      if (!_done)
      {
        ReadTask664* _cont = new ReadTask664(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask664(db,b), false);
  // (crule (pre (let __tconst4UBH116 const6b86b273ff34fce19d6b804e)) (scan mp_msk __t27ag118 q m) (body (exists $sup5638x95x0x0x0 (2 5 4 0 1 3 6 7 8) 2 m q) (exists mbranch (2 0 1 3 4) 1 m) (exists mbranch (1 2 3 4 0) 1 q) (exists mp_msk_ans (0 1) 1 __t27ag118) (join $sup5638x95x0x0x1 (1 3 6 5 0 2 4 7 8 9) 3 __t27ag118 m q p __t2hbE115 l n r u v) (cmp lt n m) (join $sup5638x95x0x0x0 (1 2 4 6 0 3 5 7 8) 9 l m p r __t2hbE115 n q u v) (exists mbranch (1 2 3 4 0) 4 q n u v) (exists mp_msk_ans (0 1) 2 __t27ag118 p) (exists mp_union (1 2 0) 1 l) (join mbranch (1 2 3 4 0) 4 p m l r __t5EdF114) (exists mp_union (0 1 2) 2 __t2hbE115 __t5EdF114) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) q n u v __t8CES119) (join mp_union (0 1 2) 3 __t2hbE115 __t5EdF114 __t8CES119) (join mp_msk_ans (0 1) 2 __t27ag118 p) (join-old mp_union (1 2 0) 2 (1 2 0) l __t8CES119 __t7k4o120) (join mp_union_ans (0 1) 1 __t7k4o120 __v0) (let __t1JZU117 (band q m)) (cmp lt __t1JZU117 __tconst4UBH116)) (head (emit-temp temp3MZb2062 __t2hbE115 __v0 m p r) (mkstruct mbranch (1 2 3 4 0) __t9UHh112 p m __v0 r)) map.slog:96 #f)
  class ReadTask690 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x95x0x0x0index672;  slog::Index** mbranchindex673;  slog::Index** mbranchindex674;  slog::Index** mp_msk_ansindex675;  slog::Index** $sup5638x95x0x0x1index676;  slog::Index** $sup5638x95x0x0x0index677;  slog::Index** mbranchindex678;  slog::Index** mp_msk_ansindex679;  slog::Index** mp_unionindex680;  slog::Index** mbranchindex681;  slog::Index** mp_unionindex682;  slog::Index** mbranchindex683;  slog::Index** mp_unionindex684;  slog::Index** mp_msk_ansindex685;  slog::Index** mp_unionindex686;  slog::Index** mp_union_ansindex687;  slog::Index** mbranchdelta688;  slog::Index** mp_uniondelta689;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp3MZb2062");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("mp_msk");
      std::vector<u16> ord691({2, 5, 4, 0, 1, 3, 6, 7, 8});
      slog::Relation* readrel692 = db->getRelation("$sup5638x95x0x0x0");
      $sup5638x95x0x0x0index672 = readrel692->getIndex(ord691, false);
      std::vector<u16> ord693({2, 0, 1, 3, 4});
      slog::Relation* readrel694 = db->getRelation("mbranch");
      mbranchindex673 = readrel694->getIndex(ord693, false);
      std::vector<u16> ord695({1, 2, 3, 4, 0});
      slog::Relation* readrel696 = db->getRelation("mbranch");
      mbranchindex674 = readrel696->getIndex(ord695, false);
      std::vector<u16> ord697({0, 1});
      slog::Relation* readrel698 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex675 = readrel698->getIndex(ord697, false);
      std::vector<u16> ord699({1, 3, 6, 5, 0, 2, 4, 7, 8, 9});
      slog::Relation* readrel700 = db->getRelation("$sup5638x95x0x0x1");
      $sup5638x95x0x0x1index676 = readrel700->getIndex(ord699, false);
      std::vector<u16> ord701({1, 2, 4, 6, 0, 3, 5, 7, 8});
      slog::Relation* readrel702 = db->getRelation("$sup5638x95x0x0x0");
      $sup5638x95x0x0x0index677 = readrel702->getIndex(ord701, false);
      std::vector<u16> ord703({1, 2, 3, 4, 0});
      slog::Relation* readrel704 = db->getRelation("mbranch");
      mbranchindex678 = readrel704->getIndex(ord703, false);
      std::vector<u16> ord705({0, 1});
      slog::Relation* readrel706 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex679 = readrel706->getIndex(ord705, false);
      std::vector<u16> ord707({1, 2, 0});
      slog::Relation* readrel708 = db->getRelation("mp_union");
      mp_unionindex680 = readrel708->getIndex(ord707, false);
      std::vector<u16> ord709({1, 2, 3, 4, 0});
      slog::Relation* readrel710 = db->getRelation("mbranch");
      mbranchindex681 = readrel710->getIndex(ord709, false);
      std::vector<u16> ord711({0, 1, 2});
      slog::Relation* readrel712 = db->getRelation("mp_union");
      mp_unionindex682 = readrel712->getIndex(ord711, false);
      std::vector<u16> ord713({1, 2, 3, 4, 0});
      slog::Relation* readrel714 = db->getRelation("mbranch");
      mbranchindex683 = readrel714->getIndex(ord713, false);
      std::vector<u16> ord715({1, 2, 3, 4, 0});
      slog::Relation* readrel716 = db->getRelation("mbranch");
      mbranchdelta688 = readrel716->getIndex(ord715, true);
      std::vector<u16> ord717({0, 1, 2});
      slog::Relation* readrel718 = db->getRelation("mp_union");
      mp_unionindex684 = readrel718->getIndex(ord717, false);
      std::vector<u16> ord719({0, 1});
      slog::Relation* readrel720 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex685 = readrel720->getIndex(ord719, false);
      std::vector<u16> ord721({1, 2, 0});
      slog::Relation* readrel722 = db->getRelation("mp_union");
      mp_unionindex686 = readrel722->getIndex(ord721, false);
      std::vector<u16> ord723({1, 2, 0});
      slog::Relation* readrel724 = db->getRelation("mp_union");
      mp_uniondelta689 = readrel724->getIndex(ord723, true);
      std::vector<u16> ord725({0, 1});
      slog::Relation* readrel726 = db->getRelation("mp_union_ans");
      mp_union_ansindex687 = readrel726->getIndex(ord725, false);
  
    }
    ReadTask690(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c176 = v_const6b86b273ff34fce19d6b804e;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c177 = _t[0];
        u64 v_c22 = _t[1];
        u64 v_c10 = _t[2];
        if (!slog::exists_probe<9,2>($sup5638x95x0x0x0index672, std::array<u64,9>{v_c10, v_c22, 0, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex673, std::array<u64,5>{v_c10, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,1>(mbranchindex674, std::array<u64,5>{v_c22, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex675, std::array<u64,2>{v_c177, 0})) return;
        slog::join_probe<10,3>($sup5638x95x0x0x1index676, std::array<u64,10>{v_c177, v_c10, v_c22, 0, 0, 0, 0, 0, 0, 0}, [&](const std::array<u64,10>& m727) {
          u64 v_c15 = m727[3]; u64 v_c146 = m727[4]; u64 v_c14 = m727[5]; u64 v_c24 = m727[6]; u64 v_c16 = m727[7]; u64 v_c25 = m727[8]; u64 v_c8 = m727[9];
          u64 v_c178 = _prim_lt(db, v_c24, v_c10);
          if (v_c178 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
          if (!v_c178) return;
          slog::join_probe<9,9>($sup5638x95x0x0x0index677, std::array<u64,9>{v_c14, v_c10, v_c15, v_c16, v_c146, v_c24, v_c22, v_c25, v_c8}, [&](const std::array<u64,9>& m729) {
            if (!slog::exists_probe<5,4>(mbranchindex678, std::array<u64,5>{v_c22, v_c24, v_c25, v_c8, 0})) return;
            if (!slog::exists_probe<2,2>(mp_msk_ansindex679, std::array<u64,2>{v_c177, v_c15})) return;
            if (!slog::exists_probe<3,1>(mp_unionindex680, std::array<u64,3>{v_c14, 0, 0})) return;
            slog::join_probe<5,4>(mbranchindex681, std::array<u64,5>{v_c15, v_c10, v_c14, v_c16, 0}, [&](const std::array<u64,5>& m730) {
              u64 v_c179 = m730[4];
              if (!slog::exists_probe<3,2>(mp_unionindex682, std::array<u64,3>{v_c146, v_c179, 0})) return;
              slog::join_probe_old<5,4>(mbranchindex683, mbranchdelta688, std::array<u64,5>{v_c22, v_c24, v_c25, v_c8, 0}, [&](const std::array<u64,5>& m731) {
                u64 v_c180 = m731[4];
                slog::join_probe<3,3>(mp_unionindex684, std::array<u64,3>{v_c146, v_c179, v_c180}, [&](const std::array<u64,3>& m732) {
                  slog::join_probe<2,2>(mp_msk_ansindex685, std::array<u64,2>{v_c177, v_c15}, [&](const std::array<u64,2>& m733) {
                    slog::join_probe_old<3,2>(mp_unionindex686, mp_uniondelta689, std::array<u64,3>{v_c14, v_c180, 0}, [&](const std::array<u64,3>& m734) {
                      u64 v_c181 = m734[2];
                      slog::join_probe<2,1>(mp_union_ansindex687, std::array<u64,2>{v_c181, 0}, [&](const std::array<u64,2>& m735) {
                        u64 v_c11 = m735[1];
                        u64 v_c182 = _prim_band(db, v_c22, v_c10);
                        if (v_c182 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
                        u64 v_c183 = _prim_lt(db, v_c182, v_c176);
                        if (v_c183 == slog_error) { slog::emit_pending_error(db, "map.slog:96"); return; }
                        if (!v_c183) return;
                        ++_fires;
                        slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c146, v_c11, v_c10, v_c15, v_c16});
                        slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c15, v_c10, v_c11, v_c16}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:96", "delta:mp_msk", _fires);
  
      if (!_done)
      {
        ReadTask690* _cont = new ReadTask690(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask690(db,b), false);
  // (crule (pre (let __tconst6BXE233 const5feceb66ffc86f38d952786c)) (scan $sup5638x62x0x0x0 __t7cml232 k l m p r) (body (exists mp_has0 (0 2 1) 2 __t7cml232 k) (exists mp_has0 (1 2 0) 2 r k) (exists mp_msk (1 2 0) 2 k m) (exists mp_msk_ans (1 0) 1 p) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t5gI3231) (join-old mp_has0 (0 2 1) 3 (0 2 1) __t7cml232 k __t5gI3231) (join-old mp_has0 (1 2 0) 2 (1 2 0) r k __t2sXu235) (exists mp_has0_ans (0 1) 1 __t2sXu235) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t9BfR236) (join mp_msk_ans (0 1) 2 __t9BfR236 p) (join mp_has0_ans (0 1) 1 __t2sXu235 a) (let __t2LqG234 (band k m)) (cmp gt __t2LqG234 __tconst6BXE233)) (head (emit mp_has0_ans (0 1) __t7cml232 a)) map.slog:63 #f)
  class ReadTask752 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_has0index737;  slog::Index** mp_has0index738;  slog::Index** mp_mskindex739;  slog::Index** mp_msk_ansindex740;  slog::Index** mbranchindex741;  slog::Index** mp_has0index742;  slog::Index** mp_has0index743;  slog::Index** mp_has0_ansindex744;  slog::Index** mp_mskindex745;  slog::Index** mp_msk_ansindex746;  slog::Index** mp_has0_ansindex747;  slog::Index** mbranchdelta748;  slog::Index** mp_has0delta749;  slog::Index** mp_has0delta750;  slog::Index** mp_mskdelta751;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_has0_ans");
      std::vector<u16> ord753({0, 1});
      slog::Relation* readrel754 = db->getRelation("mp_has0_ans");
      head_index[0] = readrel754->getIndex(ord753, false);
      outer_rel = db->getRelation("$sup5638x62x0x0x0");
      std::vector<u16> ord755({0, 2, 1});
      slog::Relation* readrel756 = db->getRelation("mp_has0");
      mp_has0index737 = readrel756->getIndex(ord755, false);
      std::vector<u16> ord757({1, 2, 0});
      slog::Relation* readrel758 = db->getRelation("mp_has0");
      mp_has0index738 = readrel758->getIndex(ord757, false);
      std::vector<u16> ord759({1, 2, 0});
      slog::Relation* readrel760 = db->getRelation("mp_msk");
      mp_mskindex739 = readrel760->getIndex(ord759, false);
      std::vector<u16> ord761({1, 0});
      slog::Relation* readrel762 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex740 = readrel762->getIndex(ord761, false);
      std::vector<u16> ord763({1, 2, 3, 4, 0});
      slog::Relation* readrel764 = db->getRelation("mbranch");
      mbranchindex741 = readrel764->getIndex(ord763, false);
      std::vector<u16> ord765({1, 2, 3, 4, 0});
      slog::Relation* readrel766 = db->getRelation("mbranch");
      mbranchdelta748 = readrel766->getIndex(ord765, true);
      std::vector<u16> ord767({0, 2, 1});
      slog::Relation* readrel768 = db->getRelation("mp_has0");
      mp_has0index742 = readrel768->getIndex(ord767, false);
      std::vector<u16> ord769({0, 2, 1});
      slog::Relation* readrel770 = db->getRelation("mp_has0");
      mp_has0delta749 = readrel770->getIndex(ord769, true);
      std::vector<u16> ord771({1, 2, 0});
      slog::Relation* readrel772 = db->getRelation("mp_has0");
      mp_has0index743 = readrel772->getIndex(ord771, false);
      std::vector<u16> ord773({1, 2, 0});
      slog::Relation* readrel774 = db->getRelation("mp_has0");
      mp_has0delta750 = readrel774->getIndex(ord773, true);
      std::vector<u16> ord775({0, 1});
      slog::Relation* readrel776 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex744 = readrel776->getIndex(ord775, false);
      std::vector<u16> ord777({1, 2, 0});
      slog::Relation* readrel778 = db->getRelation("mp_msk");
      mp_mskindex745 = readrel778->getIndex(ord777, false);
      std::vector<u16> ord779({1, 2, 0});
      slog::Relation* readrel780 = db->getRelation("mp_msk");
      mp_mskdelta751 = readrel780->getIndex(ord779, true);
      std::vector<u16> ord781({0, 1});
      slog::Relation* readrel782 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex746 = readrel782->getIndex(ord781, false);
      std::vector<u16> ord783({0, 1});
      slog::Relation* readrel784 = db->getRelation("mp_has0_ans");
      mp_has0_ansindex747 = readrel784->getIndex(ord783, false);
  
    }
    ReadTask752(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c184 = v_const5feceb66ffc86f38d952786c;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c185 = _t[0];
        u64 v_c6 = _t[1];
        u64 v_c14 = _t[2];
        u64 v_c10 = _t[3];
        u64 v_c15 = _t[4];
        u64 v_c16 = _t[5];
        if (!slog::exists_probe<3,2>(mp_has0index737, std::array<u64,3>{v_c185, v_c6, 0})) return;
        if (!slog::exists_probe<3,2>(mp_has0index738, std::array<u64,3>{v_c16, v_c6, 0})) return;
        if (!slog::exists_probe<3,2>(mp_mskindex739, std::array<u64,3>{v_c6, v_c10, 0})) return;
        if (!slog::exists_probe<2,1>(mp_msk_ansindex740, std::array<u64,2>{v_c15, 0})) return;
        slog::join_probe_old<5,4>(mbranchindex741, mbranchdelta748, std::array<u64,5>{v_c15, v_c10, v_c14, v_c16, 0}, [&](const std::array<u64,5>& m785) {
          u64 v_c186 = m785[4];
          slog::join_probe_old<3,3>(mp_has0index742, mp_has0delta749, std::array<u64,3>{v_c185, v_c6, v_c186}, [&](const std::array<u64,3>& m786) {
            slog::join_probe_old<3,2>(mp_has0index743, mp_has0delta750, std::array<u64,3>{v_c16, v_c6, 0}, [&](const std::array<u64,3>& m787) {
              u64 v_c187 = m787[2];
              if (!slog::exists_probe<2,1>(mp_has0_ansindex744, std::array<u64,2>{v_c187, 0})) return;
              slog::join_probe_old<3,2>(mp_mskindex745, mp_mskdelta751, std::array<u64,3>{v_c6, v_c10, 0}, [&](const std::array<u64,3>& m788) {
                u64 v_c188 = m788[2];
                slog::join_probe<2,2>(mp_msk_ansindex746, std::array<u64,2>{v_c188, v_c15}, [&](const std::array<u64,2>& m789) {
                  slog::join_probe<2,1>(mp_has0_ansindex747, std::array<u64,2>{v_c187, 0}, [&](const std::array<u64,2>& m790) {
                    u64 v_c189 = m790[1];
                    u64 v_c190 = _prim_band(db, v_c6, v_c10);
                    if (v_c190 == slog_error) { slog::emit_pending_error(db, "map.slog:63"); return; }
                    u64 v_c191 = _prim_gt(db, v_c190, v_c184);
                    if (v_c191 == slog_error) { slog::emit_pending_error(db, "map.slog:63"); return; }
                    if (!v_c191) return;
                    ++_fires;
                    slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c185, v_c189}, std::array<u16,2>{0, 1});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:63", "delta:$sup5638x62x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask752* _cont = new ReadTask752(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask752(db,b), false);
  // (crule (pre) (scan $sup5638x25x0x0x1 __d0 __d1 __v0 p0 p1 t0 t1) (body (let __t53ZH245 (bxor p0 p1))) (head (emit-temp temp390O1909 __t53ZH245)) map.slog:26 #f)
  class ReadTask792 : public slog::Task
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
      head_rel[0] = db->getRelation("temp390O1909");
      outer_rel = db->getRelation("$sup5638x25x0x0x1");
  
    }
    ReadTask792(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c5 = _t[0];
        u64 v_c106 = _t[1];
        u64 v_c11 = _t[2];
        u64 v_c107 = _t[3];
        u64 v_c108 = _t[4];
        u64 v_c109 = _t[5];
        u64 v_c110 = _t[6];
        u64 v_c192 = _prim_bxor(db, v_c107, v_c108);
        if (v_c192 == slog_error) { slog::emit_pending_error(db, "map.slog:26"); return; }
        ++_fires;
        slog::emit_temp<1>(head_rel[0], newbatch[0], std::array<u64,1>{v_c192});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:26", "delta:$sup5638x25x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask792* _cont = new ReadTask792(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask792(db,b), false);
  // (crule (pre) (scan temp4rXE1997 __t7O3e781 __v2 __v3 t0 t1) (body (join mbranch (1 2 3 4 0) 4 __v2 __v3 t1 t0 __t6B7E780)) (head (emit mp_join_ans (0 1) __t7O3e781 __t6B7E780)) map.slog:30 #f)
  class ReadTask794 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex793;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_join_ans");
      std::vector<u16> ord795({0, 1});
      slog::Relation* readrel796 = db->getRelation("mp_join_ans");
      head_index[0] = readrel796->getIndex(ord795, false);
      outer_rel = db->getRelation("temp4rXE1997");
      std::vector<u16> ord797({1, 2, 3, 4, 0});
      slog::Relation* readrel798 = db->getRelation("mbranch");
      mbranchindex793 = readrel798->getIndex(ord797, false);
  
    }
    ReadTask794(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c193 = _t[0];
        u64 v_c194 = _t[1];
        u64 v_c195 = _t[2];
        u64 v_c109 = _t[3];
        u64 v_c110 = _t[4];
        slog::join_probe<5,4>(mbranchindex793, std::array<u64,5>{v_c194, v_c195, v_c110, v_c109, 0}, [&](const std::array<u64,5>& m799) {
          u64 v_c196 = m799[4];
          ++_fires;
          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c193, v_c196}, std::array<u16,2>{0, 1});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:30", "delta:temp4rXE1997", _fires);
  
      if (!_done)
      {
        ReadTask794* _cont = new ReadTask794(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask794(db,b), false);
  // (crule (pre (let __trid3uoS1058 const5d6ab4fefffae2e4c15033db) (let __trel6yFB1059 const52b5e20f559958f34e533431) (let __tcol6Bcn1060 const6b86b273ff34fce19d6b804e) (let __trel6nqp1061 const65c80aac3433a01ef8a7f298) (let __tcol0oGB1062 const6b86b273ff34fce19d6b804e) (let __trel25zN1063 const65c80aac3433a01ef8a7f298) (let __tcol34iC1064 constd4735e3a265e16eee03f5971)) (scan eval __t4Pyv623 er rho2 t) (body (exists mp_put_ans (1 0) 1 rho2) (exists mp_put (3 0 2 1) 1 t) (exists eval (3 1 0 2) 1 t) (exists letrec (2 3 0 1) 1 er) (join eval_ans (0 1) 1 __t4Pyv623 vr) (join mp_put_ans (1 0) 1 rho2 __t5ODE624) (join-old mp_put (3 0 2 1) 2 (3 0 2 1) t __t5ODE624 x rho) (exists letrec (1 2 3 0) 2 x er) (join eval (2 3 0 1) 2 rho t __7yeU1057 __t4cK3622) (join letrec (0 1 2 3) 3 __t4cK3622 x er eb)) (head (tycheck t (accept seq) __trid3uoS1058 __trel6yFB1059 __tcol6Bcn1060 (1 2 3 4 0)) (tycheck t (accept seq) __trid3uoS1058 __trel6nqp1061 __tcol0oGB1062 (1 2 3 4 0)) (tycheck t (accept seq) __trid3uoS1058 __trel25zN1063 __tcol34iC1064 (1 2 3 4 0)) (emit store (0 1 2) x t vr) (emit binding_event (0 1 2) x t t)) interp.slog:98 #f)
  class ReadTask811 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[5];
    slog::Index** head_index[5];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mp_put_ansindex800;  slog::Index** mp_putindex801;  slog::Index** evalindex802;  slog::Index** letrecindex803;  slog::Index** eval_ansindex804;  slog::Index** mp_put_ansindex805;  slog::Index** mp_putindex806;  slog::Index** letrecindex807;  slog::Index** evalindex808;  slog::Index** letrecindex809;  slog::Index** mp_putdelta810;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("malformed_deduction");
      head_rel[3] = db->getRelation("store");
      std::vector<u16> ord812({0, 1, 2});
      slog::Relation* readrel813 = db->getRelation("store");
      head_index[3] = readrel813->getIndex(ord812, false);
      head_rel[4] = db->getRelation("binding_event");
      std::vector<u16> ord814({0, 1, 2});
      slog::Relation* readrel815 = db->getRelation("binding_event");
      head_index[4] = readrel815->getIndex(ord814, false);
      outer_rel = db->getRelation("eval");
      std::vector<u16> ord816({1, 0});
      slog::Relation* readrel817 = db->getRelation("mp_put_ans");
      mp_put_ansindex800 = readrel817->getIndex(ord816, false);
      std::vector<u16> ord818({3, 0, 2, 1});
      slog::Relation* readrel819 = db->getRelation("mp_put");
      mp_putindex801 = readrel819->getIndex(ord818, false);
      std::vector<u16> ord820({3, 1, 0, 2});
      slog::Relation* readrel821 = db->getRelation("eval");
      evalindex802 = readrel821->getIndex(ord820, false);
      std::vector<u16> ord822({2, 3, 0, 1});
      slog::Relation* readrel823 = db->getRelation("letrec");
      letrecindex803 = readrel823->getIndex(ord822, false);
      std::vector<u16> ord824({0, 1});
      slog::Relation* readrel825 = db->getRelation("eval_ans");
      eval_ansindex804 = readrel825->getIndex(ord824, false);
      std::vector<u16> ord826({1, 0});
      slog::Relation* readrel827 = db->getRelation("mp_put_ans");
      mp_put_ansindex805 = readrel827->getIndex(ord826, false);
      std::vector<u16> ord828({3, 0, 2, 1});
      slog::Relation* readrel829 = db->getRelation("mp_put");
      mp_putindex806 = readrel829->getIndex(ord828, false);
      std::vector<u16> ord830({3, 0, 2, 1});
      slog::Relation* readrel831 = db->getRelation("mp_put");
      mp_putdelta810 = readrel831->getIndex(ord830, true);
      std::vector<u16> ord832({1, 2, 3, 0});
      slog::Relation* readrel833 = db->getRelation("letrec");
      letrecindex807 = readrel833->getIndex(ord832, false);
      std::vector<u16> ord834({2, 3, 0, 1});
      slog::Relation* readrel835 = db->getRelation("eval");
      evalindex808 = readrel835->getIndex(ord834, false);
      std::vector<u16> ord836({0, 1, 2, 3});
      slog::Relation* readrel837 = db->getRelation("letrec");
      letrecindex809 = readrel837->getIndex(ord836, false);
  
    }
    ReadTask811(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c119 = v_const5d6ab4fefffae2e4c15033db;
      u64 v_c120 = v_const52b5e20f559958f34e533431;
      u64 v_c121 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c122 = v_const65c80aac3433a01ef8a7f298;
      u64 v_c123 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c124 = v_const65c80aac3433a01ef8a7f298;
      u64 v_c125 = v_constd4735e3a265e16eee03f5971;
  
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
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c129 = _t[0];
        u64 v_c36 = _t[1];
        u64 v_c34 = _t[2];
        u64 v_c7 = _t[3];
        if (!slog::exists_probe<2,1>(mp_put_ansindex800, std::array<u64,2>{v_c34, 0})) return;
        if (!slog::exists_probe<4,1>(mp_putindex801, std::array<u64,4>{v_c7, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(evalindex802, std::array<u64,4>{v_c7, 0, 0, 0})) return;
        if (!slog::exists_probe<4,1>(letrecindex803, std::array<u64,4>{v_c36, 0, 0, 0})) return;
        slog::join_probe<2,1>(eval_ansindex804, std::array<u64,2>{v_c129, 0}, [&](const std::array<u64,2>& m838) {
          u64 v_c42 = m838[1];
          slog::join_probe<2,1>(mp_put_ansindex805, std::array<u64,2>{v_c34, 0}, [&](const std::array<u64,2>& m839) {
            u64 v_c128 = m839[1];
            slog::join_probe_old<4,2>(mp_putindex806, mp_putdelta810, std::array<u64,4>{v_c7, v_c128, 0, 0}, [&](const std::array<u64,4>& m840) {
              u64 v_c40 = m840[2]; u64 v_c39 = m840[3];
              if (!slog::exists_probe<4,2>(letrecindex807, std::array<u64,4>{v_c40, v_c36, 0, 0})) return;
              slog::join_probe<4,2>(evalindex808, std::array<u64,4>{v_c39, v_c7, 0, 0}, [&](const std::array<u64,4>& m841) {
                u64 v_c127 = m841[2]; u64 v_c126 = m841[3];
                slog::join_probe<4,3>(letrecindex809, std::array<u64,4>{v_c126, v_c40, v_c36, 0}, [&](const std::array<u64,4>& m842) {
                  u64 v_c33 = m842[3];
                  ++_fires;
                  if (!(is_seq(v_c7)))
                  {
                    slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c119, v_c120, v_c121, v_c7}, std::array<u16,5>{1, 2, 3, 4, 0});
                    return;
                  }
                  if (!(is_seq(v_c7)))
                  {
                    slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c119, v_c122, v_c123, v_c7}, std::array<u16,5>{1, 2, 3, 4, 0});
                    return;
                  }
                  if (!(is_seq(v_c7)))
                  {
                    slog::emit_struct<5>(head_rel[2], newbatch[2], std::array<u64,4>{v_c119, v_c124, v_c125, v_c7}, std::array<u16,5>{1, 2, 3, 4, 0});
                    return;
                  }
                  slog::emit<3>(head_rel[3], head_index[3], newbatch[3], std::array<u64,3>{v_c40, v_c7, v_c42}, std::array<u16,3>{0, 1, 2});
                  slog::emit<3>(head_rel[4], head_index[4], newbatch[4], std::array<u64,3>{v_c40, v_c7, v_c7}, std::array<u16,3>{0, 1, 2});
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
  
      if (_fires) db->bumpFires("interp.slog:98", "delta:eval", _fires);
  
      if (!_done)
      {
        ReadTask811* _cont = new ReadTask811(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask811(db,b), false);
  // (crule (pre (let __trid2vvZ1306 const8c6798fa821ed573f6b89759) (let __trel6KV01307 constac3fe12f2763ff95bc66dbed) (let __tcol87Vw1308 const6b86b273ff34fce19d6b804e) (let __trel3xuU1309 const4e5ef144c51cd25230c144c3) (let __tcol8xoF1310 const5feceb66ffc86f38d952786c) (let __trel9ppM1311 const4e5ef144c51cd25230c144c3) (let __tcol9pfA1312 const6b86b273ff34fce19d6b804e)) (scan $sup70016x51x0x0x0 __d0 ef es rho t) (body) (head (tycheck t (accept seq) __trid2vvZ1306 __trel6KV01307 __tcol87Vw1308 (1 2 3 4 0)) (tycheck ef (accept (struct app) (struct boolean) (struct if) (struct lambda) (struct let) (struct letrec) (struct num) (struct primref) (struct ref) (struct sym)) __trid2vvZ1306 __trel3xuU1309 __tcol8xoF1310 (1 2 3 4 0)) (tycheck es (accept seq) __trid2vvZ1306 __trel9ppM1311 __tcol9pfA1312 (1 2 3 4 0)) (emit-temp temp8M8t2030 ef es t) (mkstruct app (1 2 0) __t2e2U253 ef es)) interp.slog:52 #f)
  class ReadTask853 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[5];
    slog::Index** head_index[5];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
  
    u32 sid843;  u32 sid844;  u32 sid845;  u32 sid846;  u32 sid847;  u32 sid848;  u32 sid849;  u32 sid850;  u32 sid851;  u32 sid852;
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("malformed_deduction");
      head_rel[2] = db->getRelation("malformed_deduction");
      head_rel[3] = db->getRelation("temp8M8t2030");
      head_rel[4] = db->getRelation("app");
      outer_rel = db->getRelation("$sup70016x51x0x0x0");
      sid843 = db->getRelation("app")->getStructId();
      sid844 = db->getRelation("boolean")->getStructId();
      sid845 = db->getRelation("if")->getStructId();
      sid846 = db->getRelation("lambda")->getStructId();
      sid847 = db->getRelation("let")->getStructId();
      sid848 = db->getRelation("letrec")->getStructId();
      sid849 = db->getRelation("num")->getStructId();
      sid850 = db->getRelation("primref")->getStructId();
      sid851 = db->getRelation("ref")->getStructId();
      sid852 = db->getRelation("sym")->getStructId();
  
    }
    ReadTask853(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c197 = v_const8c6798fa821ed573f6b89759;
      u64 v_c198 = v_constac3fe12f2763ff95bc66dbed;
      u64 v_c199 = v_const6b86b273ff34fce19d6b804e;
      u64 v_c200 = v_const4e5ef144c51cd25230c144c3;
      u64 v_c201 = v_const5feceb66ffc86f38d952786c;
      u64 v_c202 = v_const4e5ef144c51cd25230c144c3;
      u64 v_c203 = v_const6b86b273ff34fce19d6b804e;
  
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
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c5 = _t[0];
        u64 v_c52 = _t[1];
        u64 v_c53 = _t[2];
        u64 v_c39 = _t[3];
        u64 v_c7 = _t[4];
        ++_fires;
        if (!(is_seq(v_c7)))
        {
          slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c197, v_c198, v_c199, v_c7}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!((is_struct(v_c52) && (decode_struct_id(v_c52) == sid843 || decode_struct_id(v_c52) == sid844 || decode_struct_id(v_c52) == sid845 || decode_struct_id(v_c52) == sid846 || decode_struct_id(v_c52) == sid847 || decode_struct_id(v_c52) == sid848 || decode_struct_id(v_c52) == sid849 || decode_struct_id(v_c52) == sid850 || decode_struct_id(v_c52) == sid851 || decode_struct_id(v_c52) == sid852))))
        {
          slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c197, v_c200, v_c201, v_c52}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        if (!(is_seq(v_c53)))
        {
          slog::emit_struct<5>(head_rel[2], newbatch[2], std::array<u64,4>{v_c197, v_c202, v_c203, v_c53}, std::array<u16,5>{1, 2, 3, 4, 0});
          return;
        }
        slog::emit_temp<3>(head_rel[3], newbatch[3], std::array<u64,3>{v_c52, v_c53, v_c7});
        slog::emit_struct<3>(head_rel[4], newbatch[4], std::array<u64,2>{v_c52, v_c53}, std::array<u16,3>{1, 2, 0});
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
        head_rel[2]->sendBatch(newbatch[2]);
        head_rel[3]->sendBatch(newbatch[3]);
        head_rel[4]->sendBatch(newbatch[4]);
  
      if (_fires) db->bumpFires("interp.slog:52", "delta:$sup70016x51x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask853* _cont = new ReadTask853(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask853(db,b), false);
  // (crule (pre) (scan $sup5638x93x0x0x0 __t70BJ454 l m p r u v) (body (exists mbranch (1 2 3 4 0) 4 p m l r) (exists mp_union (1 2 0) 2 l u) (exists mp_union (1 2 0) 2 r v) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m u v __t1p4P452) (exists mp_union (2 0 1) 2 __t1p4P452 __t70BJ454) (join-old mbranch (1 2 3 4 0) 4 (1 2 3 4 0) p m l r __t4xjy453) (join-old mp_union (0 1 2) 3 (0 1 2) __t70BJ454 __t4xjy453 __t1p4P452) (join-old mp_union (1 2 0) 2 (1 2 0) l u __t1OdF455) (exists mp_union_ans (0 1) 1 __t1OdF455) (join-old mp_union (1 2 0) 2 (1 2 0) r v __t4atM456) (exists mp_union_ans (0 1) 1 __t4atM456) (join mp_union_ans (0 1) 1 __t1OdF455 __v0) (join mp_union_ans (0 1) 1 __t4atM456 __v1)) (head (emit-temp temp9Yrn2045 __t70BJ454 __v0 __v1 m p) (mkstruct mbranch (1 2 3 4 0) __t8Q9x451 p m __v0 __v1)) map.slog:94 #f)
  class ReadTask872 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** mbranchindex854;  slog::Index** mp_unionindex855;  slog::Index** mp_unionindex856;  slog::Index** mbranchindex857;  slog::Index** mp_unionindex858;  slog::Index** mbranchindex859;  slog::Index** mp_unionindex860;  slog::Index** mp_unionindex861;  slog::Index** mp_union_ansindex862;  slog::Index** mp_unionindex863;  slog::Index** mp_union_ansindex864;  slog::Index** mp_union_ansindex865;  slog::Index** mp_union_ansindex866;  slog::Index** mbranchdelta867;  slog::Index** mbranchdelta868;  slog::Index** mp_uniondelta869;  slog::Index** mp_uniondelta870;  slog::Index** mp_uniondelta871;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp9Yrn2045");
      head_rel[1] = db->getRelation("mbranch");
      outer_rel = db->getRelation("$sup5638x93x0x0x0");
      std::vector<u16> ord873({1, 2, 3, 4, 0});
      slog::Relation* readrel874 = db->getRelation("mbranch");
      mbranchindex854 = readrel874->getIndex(ord873, false);
      std::vector<u16> ord875({1, 2, 0});
      slog::Relation* readrel876 = db->getRelation("mp_union");
      mp_unionindex855 = readrel876->getIndex(ord875, false);
      std::vector<u16> ord877({1, 2, 0});
      slog::Relation* readrel878 = db->getRelation("mp_union");
      mp_unionindex856 = readrel878->getIndex(ord877, false);
      std::vector<u16> ord879({1, 2, 3, 4, 0});
      slog::Relation* readrel880 = db->getRelation("mbranch");
      mbranchindex857 = readrel880->getIndex(ord879, false);
      std::vector<u16> ord881({1, 2, 3, 4, 0});
      slog::Relation* readrel882 = db->getRelation("mbranch");
      mbranchdelta867 = readrel882->getIndex(ord881, true);
      std::vector<u16> ord883({2, 0, 1});
      slog::Relation* readrel884 = db->getRelation("mp_union");
      mp_unionindex858 = readrel884->getIndex(ord883, false);
      std::vector<u16> ord885({1, 2, 3, 4, 0});
      slog::Relation* readrel886 = db->getRelation("mbranch");
      mbranchindex859 = readrel886->getIndex(ord885, false);
      std::vector<u16> ord887({1, 2, 3, 4, 0});
      slog::Relation* readrel888 = db->getRelation("mbranch");
      mbranchdelta868 = readrel888->getIndex(ord887, true);
      std::vector<u16> ord889({0, 1, 2});
      slog::Relation* readrel890 = db->getRelation("mp_union");
      mp_unionindex860 = readrel890->getIndex(ord889, false);
      std::vector<u16> ord891({0, 1, 2});
      slog::Relation* readrel892 = db->getRelation("mp_union");
      mp_uniondelta869 = readrel892->getIndex(ord891, true);
      std::vector<u16> ord893({1, 2, 0});
      slog::Relation* readrel894 = db->getRelation("mp_union");
      mp_unionindex861 = readrel894->getIndex(ord893, false);
      std::vector<u16> ord895({1, 2, 0});
      slog::Relation* readrel896 = db->getRelation("mp_union");
      mp_uniondelta870 = readrel896->getIndex(ord895, true);
      std::vector<u16> ord897({0, 1});
      slog::Relation* readrel898 = db->getRelation("mp_union_ans");
      mp_union_ansindex862 = readrel898->getIndex(ord897, false);
      std::vector<u16> ord899({1, 2, 0});
      slog::Relation* readrel900 = db->getRelation("mp_union");
      mp_unionindex863 = readrel900->getIndex(ord899, false);
      std::vector<u16> ord901({1, 2, 0});
      slog::Relation* readrel902 = db->getRelation("mp_union");
      mp_uniondelta871 = readrel902->getIndex(ord901, true);
      std::vector<u16> ord903({0, 1});
      slog::Relation* readrel904 = db->getRelation("mp_union_ans");
      mp_union_ansindex864 = readrel904->getIndex(ord903, false);
      std::vector<u16> ord905({0, 1});
      slog::Relation* readrel906 = db->getRelation("mp_union_ans");
      mp_union_ansindex865 = readrel906->getIndex(ord905, false);
      std::vector<u16> ord907({0, 1});
      slog::Relation* readrel908 = db->getRelation("mp_union_ans");
      mp_union_ansindex866 = readrel908->getIndex(ord907, false);
  
    }
    ReadTask872(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c204 = _t[0];
        u64 v_c14 = _t[1];
        u64 v_c10 = _t[2];
        u64 v_c15 = _t[3];
        u64 v_c16 = _t[4];
        u64 v_c25 = _t[5];
        u64 v_c8 = _t[6];
        if (!slog::exists_probe<5,4>(mbranchindex854, std::array<u64,5>{v_c15, v_c10, v_c14, v_c16, 0})) return;
        if (!slog::exists_probe<3,2>(mp_unionindex855, std::array<u64,3>{v_c14, v_c25, 0})) return;
        if (!slog::exists_probe<3,2>(mp_unionindex856, std::array<u64,3>{v_c16, v_c8, 0})) return;
        slog::join_probe_old<5,4>(mbranchindex857, mbranchdelta867, std::array<u64,5>{v_c15, v_c10, v_c25, v_c8, 0}, [&](const std::array<u64,5>& m909) {
          u64 v_c205 = m909[4];
          if (!slog::exists_probe<3,2>(mp_unionindex858, std::array<u64,3>{v_c205, v_c204, 0})) return;
          slog::join_probe_old<5,4>(mbranchindex859, mbranchdelta868, std::array<u64,5>{v_c15, v_c10, v_c14, v_c16, 0}, [&](const std::array<u64,5>& m910) {
            u64 v_c206 = m910[4];
            slog::join_probe_old<3,3>(mp_unionindex860, mp_uniondelta869, std::array<u64,3>{v_c204, v_c206, v_c205}, [&](const std::array<u64,3>& m911) {
              slog::join_probe_old<3,2>(mp_unionindex861, mp_uniondelta870, std::array<u64,3>{v_c14, v_c25, 0}, [&](const std::array<u64,3>& m912) {
                u64 v_c207 = m912[2];
                if (!slog::exists_probe<2,1>(mp_union_ansindex862, std::array<u64,2>{v_c207, 0})) return;
                slog::join_probe_old<3,2>(mp_unionindex863, mp_uniondelta871, std::array<u64,3>{v_c16, v_c8, 0}, [&](const std::array<u64,3>& m913) {
                  u64 v_c208 = m913[2];
                  if (!slog::exists_probe<2,1>(mp_union_ansindex864, std::array<u64,2>{v_c208, 0})) return;
                  slog::join_probe<2,1>(mp_union_ansindex865, std::array<u64,2>{v_c207, 0}, [&](const std::array<u64,2>& m914) {
                    u64 v_c11 = m914[1];
                    slog::join_probe<2,1>(mp_union_ansindex866, std::array<u64,2>{v_c208, 0}, [&](const std::array<u64,2>& m915) {
                      u64 v_c209 = m915[1];
                      ++_fires;
                      slog::emit_temp<5>(head_rel[0], newbatch[0], std::array<u64,5>{v_c204, v_c11, v_c209, v_c10, v_c15});
                      slog::emit_struct<5>(head_rel[1], newbatch[1], std::array<u64,4>{v_c15, v_c10, v_c11, v_c209}, std::array<u16,5>{1, 2, 3, 4, 0});
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
  
      if (_fires) db->bumpFires("map.slog:94", "delta:$sup5638x93x0x0x0", _fires);
  
      if (!_done)
      {
        ReadTask872* _cont = new ReadTask872(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask872(db,b), false);
  // (crule (pre) (scan mleaf __t5lKq834 k v) (body (exists $sup5638x44x0x0x0 (1 7 0 6 4 2 3 5) 2 k v) (exists mp_join (1 2 3 4 0) 2 k __t5lKq834) (exists mp_msk (1 2 0) 1 k) (join mp_put (2 3 0 1) 2 k v __t6Fc5832 __t6oBk833) (exists mp_join (1 4 2 0 3) 3 k __t6oBk833 __t5lKq834) (join $sup5638x44x0x0x0 (1 7 0 6 4 2 3 5) 4 k v __t6Fc5832 __t6oBk833 p l m r) (join mbranch (1 2 3 4 0) 5 p m l r __t6oBk833) (exists mp_msk (1 2 0) 2 k m) (join-old mp_join (1 2 3 4 0) 4 (1 2 3 4 0) k __t5lKq834 p __t6oBk833 __t6jFY835) (exists mp_join_ans (0 1) 1 __t6jFY835) (join-old mp_msk (1 2 0) 2 (1 2 0) k m __t2nZc836) (join mp_msk_ans (0 1) 1 __t2nZc836 __v0) (neq p __v0) (join mp_join_ans (0 1) 1 __t6jFY835 res)) (head (emit mp_put_ans (0 1) __t6Fc5832 res)) map.slog:45 #f)
  class ReadTask931 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup5638x44x0x0x0index916;  slog::Index** mp_joinindex917;  slog::Index** mp_mskindex918;  slog::Index** mp_putindex919;  slog::Index** mp_joinindex920;  slog::Index** $sup5638x44x0x0x0index921;  slog::Index** mbranchindex922;  slog::Index** mp_mskindex923;  slog::Index** mp_joinindex924;  slog::Index** mp_join_ansindex925;  slog::Index** mp_mskindex926;  slog::Index** mp_msk_ansindex927;  slog::Index** mp_join_ansindex928;  slog::Index** mp_joindelta929;  slog::Index** mp_mskdelta930;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("mp_put_ans");
      std::vector<u16> ord932({0, 1});
      slog::Relation* readrel933 = db->getRelation("mp_put_ans");
      head_index[0] = readrel933->getIndex(ord932, false);
      outer_rel = db->getRelation("mleaf");
      std::vector<u16> ord934({1, 7, 0, 6, 4, 2, 3, 5});
      slog::Relation* readrel935 = db->getRelation("$sup5638x44x0x0x0");
      $sup5638x44x0x0x0index916 = readrel935->getIndex(ord934, false);
      std::vector<u16> ord936({1, 2, 3, 4, 0});
      slog::Relation* readrel937 = db->getRelation("mp_join");
      mp_joinindex917 = readrel937->getIndex(ord936, false);
      std::vector<u16> ord938({1, 2, 0});
      slog::Relation* readrel939 = db->getRelation("mp_msk");
      mp_mskindex918 = readrel939->getIndex(ord938, false);
      std::vector<u16> ord940({2, 3, 0, 1});
      slog::Relation* readrel941 = db->getRelation("mp_put");
      mp_putindex919 = readrel941->getIndex(ord940, false);
      std::vector<u16> ord942({1, 4, 2, 0, 3});
      slog::Relation* readrel943 = db->getRelation("mp_join");
      mp_joinindex920 = readrel943->getIndex(ord942, false);
      std::vector<u16> ord944({1, 7, 0, 6, 4, 2, 3, 5});
      slog::Relation* readrel945 = db->getRelation("$sup5638x44x0x0x0");
      $sup5638x44x0x0x0index921 = readrel945->getIndex(ord944, false);
      std::vector<u16> ord946({1, 2, 3, 4, 0});
      slog::Relation* readrel947 = db->getRelation("mbranch");
      mbranchindex922 = readrel947->getIndex(ord946, false);
      std::vector<u16> ord948({1, 2, 0});
      slog::Relation* readrel949 = db->getRelation("mp_msk");
      mp_mskindex923 = readrel949->getIndex(ord948, false);
      std::vector<u16> ord950({1, 2, 3, 4, 0});
      slog::Relation* readrel951 = db->getRelation("mp_join");
      mp_joinindex924 = readrel951->getIndex(ord950, false);
      std::vector<u16> ord952({1, 2, 3, 4, 0});
      slog::Relation* readrel953 = db->getRelation("mp_join");
      mp_joindelta929 = readrel953->getIndex(ord952, true);
      std::vector<u16> ord954({0, 1});
      slog::Relation* readrel955 = db->getRelation("mp_join_ans");
      mp_join_ansindex925 = readrel955->getIndex(ord954, false);
      std::vector<u16> ord956({1, 2, 0});
      slog::Relation* readrel957 = db->getRelation("mp_msk");
      mp_mskindex926 = readrel957->getIndex(ord956, false);
      std::vector<u16> ord958({1, 2, 0});
      slog::Relation* readrel959 = db->getRelation("mp_msk");
      mp_mskdelta930 = readrel959->getIndex(ord958, true);
      std::vector<u16> ord960({0, 1});
      slog::Relation* readrel961 = db->getRelation("mp_msk_ans");
      mp_msk_ansindex927 = readrel961->getIndex(ord960, false);
      std::vector<u16> ord962({0, 1});
      slog::Relation* readrel963 = db->getRelation("mp_join_ans");
      mp_join_ansindex928 = readrel963->getIndex(ord962, false);
  
    }
    ReadTask931(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c12 = _t[0];
        u64 v_c6 = _t[1];
        u64 v_c8 = _t[2];
        if (!slog::exists_probe<8,2>($sup5638x44x0x0x0index916, std::array<u64,8>{v_c6, v_c8, 0, 0, 0, 0, 0, 0})) return;
        if (!slog::exists_probe<5,2>(mp_joinindex917, std::array<u64,5>{v_c6, v_c12, 0, 0, 0})) return;
        if (!slog::exists_probe<3,1>(mp_mskindex918, std::array<u64,3>{v_c6, 0, 0})) return;
        slog::join_probe<4,2>(mp_putindex919, std::array<u64,4>{v_c6, v_c8, 0, 0}, [&](const std::array<u64,4>& m964) {
          u64 v_c13 = m964[2]; u64 v_c17 = m964[3];
          if (!slog::exists_probe<5,3>(mp_joinindex920, std::array<u64,5>{v_c6, v_c17, v_c12, 0, 0})) return;
          slog::join_probe<8,4>($sup5638x44x0x0x0index921, std::array<u64,8>{v_c6, v_c8, v_c13, v_c17, 0, 0, 0, 0}, [&](const std::array<u64,8>& m965) {
            u64 v_c15 = m965[4]; u64 v_c14 = m965[5]; u64 v_c10 = m965[6]; u64 v_c16 = m965[7];
            slog::join_probe<5,5>(mbranchindex922, std::array<u64,5>{v_c15, v_c10, v_c14, v_c16, v_c17}, [&](const std::array<u64,5>& m966) {
              if (!slog::exists_probe<3,2>(mp_mskindex923, std::array<u64,3>{v_c6, v_c10, 0})) return;
              slog::join_probe_old<5,4>(mp_joinindex924, mp_joindelta929, std::array<u64,5>{v_c6, v_c12, v_c15, v_c17, 0}, [&](const std::array<u64,5>& m967) {
                u64 v_c18 = m967[4];
                if (!slog::exists_probe<2,1>(mp_join_ansindex925, std::array<u64,2>{v_c18, 0})) return;
                slog::join_probe_old<3,2>(mp_mskindex926, mp_mskdelta930, std::array<u64,3>{v_c6, v_c10, 0}, [&](const std::array<u64,3>& m968) {
                  u64 v_c9 = m968[2];
                  slog::join_probe<2,1>(mp_msk_ansindex927, std::array<u64,2>{v_c9, 0}, [&](const std::array<u64,2>& m969) {
                    u64 v_c11 = m969[1];
                    if (v_c15 == v_c11) return;
                    slog::join_probe<2,1>(mp_join_ansindex928, std::array<u64,2>{v_c18, 0}, [&](const std::array<u64,2>& m970) {
                      u64 v_c19 = m970[1];
                      ++_fires;
                      slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c13, v_c19}, std::array<u16,2>{0, 1});
                    });
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("map.slog:45", "delta:mleaf", _fires);
  
      if (!_done)
      {
        ReadTask931* _cont = new ReadTask931(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask931(db,b), false);
  // (crule (pre (let __tconst4dqx1210 constd01925b37634a1a9d24159d8) (let _00024seq0 (lempty))) (scan program e) (body (join _enum (1 0) 1 __tconst4dqx1210 __t1lYq698)) (head (mkstruct eval (1 2 3 0) __3qkA1209 e __t1lYq698 _00024seq0)) interp.slog:134 #f)
  class ReadTask972 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** _enumindex971;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval");
      outer_rel = db->getRelation("program");
      std::vector<u16> ord973({1, 0});
      slog::Relation* readrel974 = db->getRelation("_enum");
      _enumindex971 = readrel974->getIndex(ord973, false);
  
    }
    ReadTask972(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c210 = v_constd01925b37634a1a9d24159d8;
      u64 v_c72 = _prim_lempty(db);
      if (v_c72 == slog_error) { slog::emit_pending_error(db, "interp.slog:134"); return true; }
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[1];
      newbatch[0] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c211 = _t[0];
        slog::join_probe<2,1>(_enumindex971, std::array<u64,2>{v_c210, 0}, [&](const std::array<u64,2>& m975) {
          u64 v_c212 = m975[1];
          ++_fires;
          slog::emit_struct<4>(head_rel[0], newbatch[0], std::array<u64,3>{v_c211, v_c212, v_c72}, std::array<u16,4>{1, 2, 3, 0});
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
  
      if (_fires) db->bumpFires("interp.slog:134", "delta:program", _fires);
  
      if (!_done)
      {
        ReadTask972* _cont = new ReadTask972(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask972(db,b), false);
  // (crule (pre (let __tconst5vD0184 const4a44dc15364204a80fe80e90) (let __tconst5BWV176 const6b51d431df5d7f141cbececc) (let __tconst1XI2167 const3fdba35f04dc8c462986c992) (let __tconst2wxb180 const4fc82b26aecb47d2868c4efb) (let __tconst5TvD157 const06abaa100ecef791ce028c56)) (scan temp7sUm1992 __t1jRc182 __t39Ee172 __t7NO4156 __t9exo163) (body (exists ref (1 0) 1 __tconst5vD0184) (exists app (2 0 1) 1 __t9exo163) (exists app (2 0 1) 1 __t39Ee172) (exists ref (1 0) 1 __tconst2wxb180) (exists lambda (1 2 0) 1 __t1jRc182) (join primref (1 0) 1 __tconst5TvD157 __t2ZGf158) (join ref (1 0) 1 __tconst5vD0184 __t1od9165) (exists app (1 2 0) 2 __t1od9165 __t39Ee172) (join app (1 2 0) 2 __t1od9165 __t9exo163 __t3ORQ166) (join app (1 2 0) 2 __t1od9165 __t39Ee172 __t9GVo175) (join ref (1 0) 1 __tconst2wxb180 __t1BW9179) (join lambda (1 2 0) 2 __t1jRc182 __t1BW9179 __t9kRL183)) (head (emit-temp temp7BWu1993 __t3ORQ166 __t7NO4156 __t9GVo175 __t9kRL183) (mkstruct app (1 2 0) __t9KE7159 __t2ZGf158 __t7NO4156)) kcfa.slog:29 #f)
  class ReadTask988 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** refindex976;  slog::Index** appindex977;  slog::Index** appindex978;  slog::Index** refindex979;  slog::Index** lambdaindex980;  slog::Index** primrefindex981;  slog::Index** refindex982;  slog::Index** appindex983;  slog::Index** appindex984;  slog::Index** appindex985;  slog::Index** refindex986;  slog::Index** lambdaindex987;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("temp7BWu1993");
      head_rel[1] = db->getRelation("app");
      outer_rel = db->getRelation("temp7sUm1992");
      std::vector<u16> ord989({1, 0});
      slog::Relation* readrel990 = db->getRelation("ref");
      refindex976 = readrel990->getIndex(ord989, false);
      std::vector<u16> ord991({2, 0, 1});
      slog::Relation* readrel992 = db->getRelation("app");
      appindex977 = readrel992->getIndex(ord991, false);
      std::vector<u16> ord993({2, 0, 1});
      slog::Relation* readrel994 = db->getRelation("app");
      appindex978 = readrel994->getIndex(ord993, false);
      std::vector<u16> ord995({1, 0});
      slog::Relation* readrel996 = db->getRelation("ref");
      refindex979 = readrel996->getIndex(ord995, false);
      std::vector<u16> ord997({1, 2, 0});
      slog::Relation* readrel998 = db->getRelation("lambda");
      lambdaindex980 = readrel998->getIndex(ord997, false);
      std::vector<u16> ord999({1, 0});
      slog::Relation* readrel1000 = db->getRelation("primref");
      primrefindex981 = readrel1000->getIndex(ord999, false);
      std::vector<u16> ord1001({1, 0});
      slog::Relation* readrel1002 = db->getRelation("ref");
      refindex982 = readrel1002->getIndex(ord1001, false);
      std::vector<u16> ord1003({1, 2, 0});
      slog::Relation* readrel1004 = db->getRelation("app");
      appindex983 = readrel1004->getIndex(ord1003, false);
      std::vector<u16> ord1005({1, 2, 0});
      slog::Relation* readrel1006 = db->getRelation("app");
      appindex984 = readrel1006->getIndex(ord1005, false);
      std::vector<u16> ord1007({1, 2, 0});
      slog::Relation* readrel1008 = db->getRelation("app");
      appindex985 = readrel1008->getIndex(ord1007, false);
      std::vector<u16> ord1009({1, 0});
      slog::Relation* readrel1010 = db->getRelation("ref");
      refindex986 = readrel1010->getIndex(ord1009, false);
      std::vector<u16> ord1011({1, 2, 0});
      slog::Relation* readrel1012 = db->getRelation("lambda");
      lambdaindex987 = readrel1012->getIndex(ord1011, false);
  
    }
    ReadTask988(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c213 = v_const4a44dc15364204a80fe80e90;
      u64 v_c214 = v_const6b51d431df5d7f141cbececc;
      u64 v_c215 = v_const3fdba35f04dc8c462986c992;
      u64 v_c216 = v_const4fc82b26aecb47d2868c4efb;
      u64 v_c217 = v_const06abaa100ecef791ce028c56;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c218 = _t[0];
        u64 v_c219 = _t[1];
        u64 v_c220 = _t[2];
        u64 v_c221 = _t[3];
        if (!slog::exists_probe<2,1>(refindex976, std::array<u64,2>{v_c213, 0})) return;
        if (!slog::exists_probe<3,1>(appindex977, std::array<u64,3>{v_c221, 0, 0})) return;
        if (!slog::exists_probe<3,1>(appindex978, std::array<u64,3>{v_c219, 0, 0})) return;
        if (!slog::exists_probe<2,1>(refindex979, std::array<u64,2>{v_c216, 0})) return;
        if (!slog::exists_probe<3,1>(lambdaindex980, std::array<u64,3>{v_c218, 0, 0})) return;
        slog::join_probe<2,1>(primrefindex981, std::array<u64,2>{v_c217, 0}, [&](const std::array<u64,2>& m1013) {
          u64 v_c222 = m1013[1];
          slog::join_probe<2,1>(refindex982, std::array<u64,2>{v_c213, 0}, [&](const std::array<u64,2>& m1014) {
            u64 v_c223 = m1014[1];
            if (!slog::exists_probe<3,2>(appindex983, std::array<u64,3>{v_c223, v_c219, 0})) return;
            slog::join_probe<3,2>(appindex984, std::array<u64,3>{v_c223, v_c221, 0}, [&](const std::array<u64,3>& m1015) {
              u64 v_c224 = m1015[2];
              slog::join_probe<3,2>(appindex985, std::array<u64,3>{v_c223, v_c219, 0}, [&](const std::array<u64,3>& m1016) {
                u64 v_c225 = m1016[2];
                slog::join_probe<2,1>(refindex986, std::array<u64,2>{v_c216, 0}, [&](const std::array<u64,2>& m1017) {
                  u64 v_c226 = m1017[1];
                  slog::join_probe<3,2>(lambdaindex987, std::array<u64,3>{v_c218, v_c226, 0}, [&](const std::array<u64,3>& m1018) {
                    u64 v_c227 = m1018[2];
                    ++_fires;
                    slog::emit_temp<4>(head_rel[0], newbatch[0], std::array<u64,4>{v_c224, v_c220, v_c225, v_c227});
                    slog::emit_struct<3>(head_rel[1], newbatch[1], std::array<u64,2>{v_c222, v_c220}, std::array<u16,3>{1, 2, 0});
                  });
                });
              });
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("kcfa.slog:29", "delta:temp7sUm1992", _fires);
  
      if (!_done)
      {
        ReadTask988* _cont = new ReadTask988(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask988(db,b), false);
  // (crule (pre (let __trid9n3x1549 const5d6ab4fefffae2e4c15033db) (let __trel5eWq1550 const4a59dbb9cb3129dfcc75170b) (let __tcol6eZ31551 constd4735e3a265e16eee03f5971)) (scan mp_put __t9Rkj767 rho x t) (body (exists letrec (1 2 3 0) 1 x) (exists mp_put_ans (0 1) 1 __t9Rkj767) (join eval (2 3 0 1) 2 rho t __9QsM1547 __t7vAU766) (join letrec (0 1 2 3) 2 __t7vAU766 x er eb) (join mp_put_ans (0 1) 1 __t9Rkj767 rho2)) (head (tycheck t (accept seq) __trid9n3x1549 __trel5eWq1550 __tcol6eZ31551 (1 2 3 4 0)) (mkstruct eval (1 2 3 0) __6xaV1548 er rho2 t)) interp.slog:98 #f)
  class ReadTask1024 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[2];
    slog::Index** head_index[2];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** letrecindex1019;  slog::Index** mp_put_ansindex1020;  slog::Index** evalindex1021;  slog::Index** letrecindex1022;  slog::Index** mp_put_ansindex1023;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("malformed_deduction");
      head_rel[1] = db->getRelation("eval");
      outer_rel = db->getRelation("mp_put");
      std::vector<u16> ord1025({1, 2, 3, 0});
      slog::Relation* readrel1026 = db->getRelation("letrec");
      letrecindex1019 = readrel1026->getIndex(ord1025, false);
      std::vector<u16> ord1027({0, 1});
      slog::Relation* readrel1028 = db->getRelation("mp_put_ans");
      mp_put_ansindex1020 = readrel1028->getIndex(ord1027, false);
      std::vector<u16> ord1029({2, 3, 0, 1});
      slog::Relation* readrel1030 = db->getRelation("eval");
      evalindex1021 = readrel1030->getIndex(ord1029, false);
      std::vector<u16> ord1031({0, 1, 2, 3});
      slog::Relation* readrel1032 = db->getRelation("letrec");
      letrecindex1022 = readrel1032->getIndex(ord1031, false);
      std::vector<u16> ord1033({0, 1});
      slog::Relation* readrel1034 = db->getRelation("mp_put_ans");
      mp_put_ansindex1023 = readrel1034->getIndex(ord1033, false);
  
    }
    ReadTask1024(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
    virtual bool work()
    {
      u64 v_c228 = v_const5d6ab4fefffae2e4c15033db;
      u64 v_c229 = v_const4a59dbb9cb3129dfcc75170b;
      u64 v_c230 = v_constd4735e3a265e16eee03f5971;
  
      u64 _fires = 0;
      slog::InsertBatch* newbatch[2];
      newbatch[0] = new slog::InsertBatch();
      newbatch[1] = new slog::InsertBatch();
  
      auto _slice_deadline = std::min(db->runDeadline(),
        std::chrono::steady_clock::now() + std::chrono::milliseconds(db->runSliceMs()));
      slog::SliceCtx _sc{_slice_deadline, &db->runStopFlag()};
      u32 _rt = resume_t, _ri = resume_i;
      bool _done = slog::read_delta_sliced(outer_rel, bucket, db->getThreadCount(), _sc, _rt, _ri, [&](const u64* _t) {
        u64 v_c231 = _t[0];
        u64 v_c39 = _t[1];
        u64 v_c40 = _t[2];
        u64 v_c7 = _t[3];
        if (!slog::exists_probe<4,1>(letrecindex1019, std::array<u64,4>{v_c40, 0, 0, 0})) return;
        if (!slog::exists_probe<2,1>(mp_put_ansindex1020, std::array<u64,2>{v_c231, 0})) return;
        slog::join_probe<4,2>(evalindex1021, std::array<u64,4>{v_c39, v_c7, 0, 0}, [&](const std::array<u64,4>& m1035) {
          u64 v_c232 = m1035[2]; u64 v_c233 = m1035[3];
          slog::join_probe<4,2>(letrecindex1022, std::array<u64,4>{v_c233, v_c40, 0, 0}, [&](const std::array<u64,4>& m1036) {
            u64 v_c36 = m1036[2]; u64 v_c33 = m1036[3];
            slog::join_probe<2,1>(mp_put_ansindex1023, std::array<u64,2>{v_c231, 0}, [&](const std::array<u64,2>& m1037) {
              u64 v_c34 = m1037[1];
              ++_fires;
              if (!(is_seq(v_c7)))
              {
                slog::emit_struct<5>(head_rel[0], newbatch[0], std::array<u64,4>{v_c228, v_c229, v_c230, v_c7}, std::array<u16,5>{1, 2, 3, 4, 0});
                return;
              }
              slog::emit_struct<4>(head_rel[1], newbatch[1], std::array<u64,3>{v_c36, v_c34, v_c7}, std::array<u16,4>{1, 2, 3, 0});
            });
          });
        });
      });
  
        head_rel[0]->sendBatch(newbatch[0]);
        head_rel[1]->sendBatch(newbatch[1]);
  
      if (_fires) db->bumpFires("interp.slog:98", "delta:mp_put", _fires);
  
      if (!_done)
      {
        ReadTask1024* _cont = new ReadTask1024(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1024(db,b), false);
  // (crule (pre) (scan $sup70016x92x0x0x1 __t5vg0669 __t7GLg670 __t0mp6672 __v0 eb er rho t vr x) (body (join $sup70016x92x0x0x0 (0 3 4 1 2 5) 6 __t5vg0669 rho t eb er x) (join-old eval (2 3 0 1) 4 (2 3 0 1) rho t __t7GLg670 er) (join-old mp_put (0 2 1 3) 4 (0 2 1 3) __t0mp6672 x rho t) (exists eval (2 3 0 1) 3 rho t __t5vg0669) (exists eval (1 2 3 0) 3 eb __v0 t) (exists eval_ans (0 1) 2 __t7GLg670 vr) (exists mp_put_ans (0 1) 2 __t0mp6672 __v0) (join-old let (1 2 3 0) 3 (1 2 3 0) x er eb __t2w2P668) (join-old eval (2 3 0 1) 4 (2 3 0 1) rho t __t5vg0669 __t2w2P668) (join-old eval (1 2 3 0) 3 (1 2 3 0) eb __v0 t __t3BcP671) (join eval_ans (0 1) 2 __t7GLg670 vr) (join mp_put_ans (0 1) 2 __t0mp6672 __v0) (join eval_ans (0 1) 1 __t3BcP671 v)) (head (emit eval_ans (0 1) __t5vg0669 v)) interp.slog:93 #f)
  class ReadTask1056 : public slog::Task
  {
    slog::Database* db;
    u16 bucket;
    slog::Relation* head_rel[1];
    slog::Index** head_index[1];
    slog::Relation* outer_rel;
  
    u32 resume_t = 0;
    u32 resume_i = 0;
  
  
    slog::Index** $sup70016x92x0x0x0index1038;  slog::Index** evalindex1039;  slog::Index** mp_putindex1040;  slog::Index** evalindex1041;  slog::Index** evalindex1042;  slog::Index** eval_ansindex1043;  slog::Index** mp_put_ansindex1044;  slog::Index** letindex1045;  slog::Index** evalindex1046;  slog::Index** evalindex1047;  slog::Index** eval_ansindex1048;  slog::Index** mp_put_ansindex1049;  slog::Index** eval_ansindex1050;  slog::Index** evaldelta1051;  slog::Index** mp_putdelta1052;  slog::Index** letdelta1053;  slog::Index** evaldelta1054;  slog::Index** evaldelta1055;
  
  public:
    void bind(slog::Database* db)
    {
      head_rel[0] = db->getRelation("eval_ans");
      std::vector<u16> ord1057({0, 1});
      slog::Relation* readrel1058 = db->getRelation("eval_ans");
      head_index[0] = readrel1058->getIndex(ord1057, false);
      outer_rel = db->getRelation("$sup70016x92x0x0x1");
      std::vector<u16> ord1059({0, 3, 4, 1, 2, 5});
      slog::Relation* readrel1060 = db->getRelation("$sup70016x92x0x0x0");
      $sup70016x92x0x0x0index1038 = readrel1060->getIndex(ord1059, false);
      std::vector<u16> ord1061({2, 3, 0, 1});
      slog::Relation* readrel1062 = db->getRelation("eval");
      evalindex1039 = readrel1062->getIndex(ord1061, false);
      std::vector<u16> ord1063({2, 3, 0, 1});
      slog::Relation* readrel1064 = db->getRelation("eval");
      evaldelta1051 = readrel1064->getIndex(ord1063, true);
      std::vector<u16> ord1065({0, 2, 1, 3});
      slog::Relation* readrel1066 = db->getRelation("mp_put");
      mp_putindex1040 = readrel1066->getIndex(ord1065, false);
      std::vector<u16> ord1067({0, 2, 1, 3});
      slog::Relation* readrel1068 = db->getRelation("mp_put");
      mp_putdelta1052 = readrel1068->getIndex(ord1067, true);
      std::vector<u16> ord1069({2, 3, 0, 1});
      slog::Relation* readrel1070 = db->getRelation("eval");
      evalindex1041 = readrel1070->getIndex(ord1069, false);
      std::vector<u16> ord1071({1, 2, 3, 0});
      slog::Relation* readrel1072 = db->getRelation("eval");
      evalindex1042 = readrel1072->getIndex(ord1071, false);
      std::vector<u16> ord1073({0, 1});
      slog::Relation* readrel1074 = db->getRelation("eval_ans");
      eval_ansindex1043 = readrel1074->getIndex(ord1073, false);
      std::vector<u16> ord1075({0, 1});
      slog::Relation* readrel1076 = db->getRelation("mp_put_ans");
      mp_put_ansindex1044 = readrel1076->getIndex(ord1075, false);
      std::vector<u16> ord1077({1, 2, 3, 0});
      slog::Relation* readrel1078 = db->getRelation("let");
      letindex1045 = readrel1078->getIndex(ord1077, false);
      std::vector<u16> ord1079({1, 2, 3, 0});
      slog::Relation* readrel1080 = db->getRelation("let");
      letdelta1053 = readrel1080->getIndex(ord1079, true);
      std::vector<u16> ord1081({2, 3, 0, 1});
      slog::Relation* readrel1082 = db->getRelation("eval");
      evalindex1046 = readrel1082->getIndex(ord1081, false);
      std::vector<u16> ord1083({2, 3, 0, 1});
      slog::Relation* readrel1084 = db->getRelation("eval");
      evaldelta1054 = readrel1084->getIndex(ord1083, true);
      std::vector<u16> ord1085({1, 2, 3, 0});
      slog::Relation* readrel1086 = db->getRelation("eval");
      evalindex1047 = readrel1086->getIndex(ord1085, false);
      std::vector<u16> ord1087({1, 2, 3, 0});
      slog::Relation* readrel1088 = db->getRelation("eval");
      evaldelta1055 = readrel1088->getIndex(ord1087, true);
      std::vector<u16> ord1089({0, 1});
      slog::Relation* readrel1090 = db->getRelation("eval_ans");
      eval_ansindex1048 = readrel1090->getIndex(ord1089, false);
      std::vector<u16> ord1091({0, 1});
      slog::Relation* readrel1092 = db->getRelation("mp_put_ans");
      mp_put_ansindex1049 = readrel1092->getIndex(ord1091, false);
      std::vector<u16> ord1093({0, 1});
      slog::Relation* readrel1094 = db->getRelation("eval_ans");
      eval_ansindex1050 = readrel1094->getIndex(ord1093, false);
  
    }
    ReadTask1056(slog::Database* _db, u16 _b) : db(_db), bucket(_b) { bind(_db); }
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
        u64 v_c44 = _t[2];
        u64 v_c11 = _t[3];
        u64 v_c33 = _t[4];
        u64 v_c36 = _t[5];
        u64 v_c39 = _t[6];
        u64 v_c7 = _t[7];
        u64 v_c42 = _t[8];
        u64 v_c40 = _t[9];
        slog::join_probe<6,6>($sup70016x92x0x0x0index1038, std::array<u64,6>{v_c45, v_c39, v_c7, v_c33, v_c36, v_c40}, [&](const std::array<u64,6>& m1095) {
          slog::join_probe_old<4,4>(evalindex1039, evaldelta1051, std::array<u64,4>{v_c39, v_c7, v_c46, v_c36}, [&](const std::array<u64,4>& m1096) {
            slog::join_probe_old<4,4>(mp_putindex1040, mp_putdelta1052, std::array<u64,4>{v_c44, v_c40, v_c39, v_c7}, [&](const std::array<u64,4>& m1097) {
              if (!slog::exists_probe<4,3>(evalindex1041, std::array<u64,4>{v_c39, v_c7, v_c45, 0})) return;
              if (!slog::exists_probe<4,3>(evalindex1042, std::array<u64,4>{v_c33, v_c11, v_c7, 0})) return;
              if (!slog::exists_probe<2,2>(eval_ansindex1043, std::array<u64,2>{v_c46, v_c42})) return;
              if (!slog::exists_probe<2,2>(mp_put_ansindex1044, std::array<u64,2>{v_c44, v_c11})) return;
              slog::join_probe_old<4,3>(letindex1045, letdelta1053, std::array<u64,4>{v_c40, v_c36, v_c33, 0}, [&](const std::array<u64,4>& m1098) {
                u64 v_c47 = m1098[3];
                slog::join_probe_old<4,4>(evalindex1046, evaldelta1054, std::array<u64,4>{v_c39, v_c7, v_c45, v_c47}, [&](const std::array<u64,4>& m1099) {
                  slog::join_probe_old<4,3>(evalindex1047, evaldelta1055, std::array<u64,4>{v_c33, v_c11, v_c7, 0}, [&](const std::array<u64,4>& m1100) {
                    u64 v_c43 = m1100[3];
                    slog::join_probe<2,2>(eval_ansindex1048, std::array<u64,2>{v_c46, v_c42}, [&](const std::array<u64,2>& m1101) {
                      slog::join_probe<2,2>(mp_put_ansindex1049, std::array<u64,2>{v_c44, v_c11}, [&](const std::array<u64,2>& m1102) {
                        slog::join_probe<2,1>(eval_ansindex1050, std::array<u64,2>{v_c43, 0}, [&](const std::array<u64,2>& m1103) {
                          u64 v_c8 = m1103[1];
                          ++_fires;
                          slog::emit<2>(head_rel[0], head_index[0], newbatch[0], std::array<u64,2>{v_c45, v_c8}, std::array<u16,2>{0, 1});
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
  
      if (_fires) db->bumpFires("interp.slog:93", "delta:$sup70016x92x0x0x1", _fires);
  
      if (!_done)
      {
        ReadTask1056* _cont = new ReadTask1056(db, bucket);
        _cont->resume_t = _rt; _cont->resume_i = _ri;
        db->pushPaused(phase_read, _cont);
        return false;
      }
      return true;
  
    }
    };
    for (u16 b = 0; b < 32; ++b)
      s->addTask(phase_read, new ReadTask1056(db,b), false);
}

