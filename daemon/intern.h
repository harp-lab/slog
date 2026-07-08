/** Slog Intern Header
 * 
 * Defines global intern tables for heap values: strings, bigints, etc...
 *
 * Copyright (C) Thomas Gilray, Kristopher Micinski, Sidharth Kumar, et al., 2023 
 * Some rights reserved. See License.md for details.
 * 
 ******************************/


#pragma once


#include "types.h"
#include "debug.h"
#include <string>
#include <vector>
#include <atomic>
#include <format>
#include <iostream>
#include <map>


#define intern_buckets_bits 21 
#define intern_buckets (((u64)1) << intern_buckets_bits) 
#define intern_buckets_mask (intern_buckets - 1) 
#define intern_iterator_partitions 8 

#define decodeInner(x) ((InnerTable*)(void*)((u64)(x)&0xfffffffffffffffe))
#define hasInner(x) (((u64)((void*)(x)))&1)



namespace slog
{


template <typename T> u32 fasthash(const T& str);
template <>
inline u32 fasthash<slog::utf8string>(const slog::utf8string& str)
{
  u32 hash = 2166136261u;
  const char* cstr = str.c_str();
  for (u32 i = 0; i < str.byte_size(); ++i)
  {
    hash ^= (char)cstr[i];
    hash *= 16777619u;
  }
  
  return hash;
}

  
template <typename T>
class InternTable
{
private:

  class InnerTable
  {
  public:
    std::atomic<std::vector<T*>*> data[32];
    
    InnerTable()
    {
      for (u16 i = 0; i < 32; ++i)
	data[i] = 0;
    }

    ~InnerTable()
    {
      for (u16 i = 0; i < 32; ++i)
      {
	auto vec = data[i].load();
	if (vec)
	{
	  for (u16 j = 0; j < vec->size(); ++j)
	    delete vec->operator[](j);
	  delete vec;
	}
      }
    }

    void wipe()
    {
      // Clear without dropping the underlying T* values
      for (u16 i = 0; i < 32; ++i)
      {
	std::vector<T*>* vec = data[i].load();
	if (vec) delete vec;
	data[i] = 0;
      }
    }

    u64 intern_value(T* v, const u32 h, std::atomic<std::pair<void*,void*>*>& freelst)
    {
      const u64 pos = (h >> intern_buckets_bits) & 0x1f;
      u64 intern = (pos << intern_buckets_bits) | (h & intern_buckets_mask);
      std::vector<T*>* ptr = data[pos].load();
      if (ptr)
      {
	for (u16 i = 0; i < ptr->size(); ++i)
	  if (ptr->operator[](i)->operator==(*v))
	  {
	    // widen before shifting: u16 promotes to int, and i << 26
	    // overflows/sign-extends at i >= 32, corrupting the id
	    intern |= ((u64)i) << (5+intern_buckets_bits);
	    return intern;
	  }

	// the chain index has 9 bits of the 35-bit intern-id budget before
	// it overflows into the type-tag bits (silent id corruption)
	if (ptr->size() >= 512)
	  fatal("Intern collision chain overflow (512 entries in one slot)");
	auto vec = new std::vector<T*>(*ptr);
	intern |= ((u64)vec->size()) << (5+intern_buckets_bits);
	vec->push_back(v);
	if (!data[pos].compare_exchange_strong(ptr, vec))
	{
	  delete vec;
	  return intern_value(v, h, freelst);
	}
	/*
	// Delayed deletion of old vector ptr
	std::pair<void*,void*>* oldp;
	std::pair<void*,void*>* p = 0;
	do
	{  // Add pair to the usedpairs list atomically
	  oldp = freelst.load();
	  if (p) delete p;
	  p = new std::pair<void*,void*>((void*)ptr, (void*)oldp);
	}
	while (freelst.compare_exchange_strong(oldp,p));
	*/
	return intern;
      }
      else
      {
	auto vec = new std::vector<T*>();
	vec->push_back(v);
	if (!data[pos].compare_exchange_strong(ptr, vec))
	{
	  delete vec;
	  return intern_value(v, h, freelst);
	}
	return intern;
      }
    }
    
    T* lookup_value(const u64 intern)
    {
      const u32 pos = (intern >> intern_buckets_bits) & 0x1f;
      const u32 col = (intern >> (intern_buckets_bits+5));
      std::vector<T*>* vec = data[pos].load();
      if (vec && vec->size() > col)
        return vec->operator[](col);
      else
	return 0;
    }
  };

  std::atomic<std::pair<void*,void*>*> usedpairs[128];
  std::atomic<std::pair<void*,void*>*> usedvecs[128];
  std::atomic<void*> table[intern_buckets];
  
public:
  InternTable()
  {
    for (u32 i = 0; i < intern_buckets; ++i)
      table[i] = 0;
    for (u32 i = 0; i < 128; ++i)
      usedpairs[i] = 0;
    for (u32 i = 0; i < 128; ++i)
      usedvecs[i] = 0;
  }
  
  ~InternTable() 
  {
    for (u32 i = 0; i < intern_buckets; ++i)
      if (table[i].load())
      {
	if (hasInner(table[i].load()))
	  delete decodeInner(table[i].load());
        else delete (std::pair<u64,T*>*)table[i].load();
      }

    for (u32 i = 0; i < 128; ++i)
    {
      std::pair<void*,void*>* p = usedpairs[i].load();
      while (p)
      {
	delete (std::pair<u64,T*>*)p->first;
	p = (std::pair<void*,void*>*)p->second;
	delete p;
      }
      
      std::pair<void*,void*>* v = usedvecs[i].load();
      while (v)
      {
	delete (std::vector<T*>*)v->first;
	v = (std::pair<void*,void*>*)v->second;
	delete v;
      }
    }
  }

  u16 getWritePartitions()
  {
    return intern_iterator_partitions;
  }

  T* lookup_value(u64 intern)
  {
    // Takes an X_decode'ed u64 and looks up the T pointer
    void* outer = table[intern & intern_buckets_mask].load();
    if (outer && hasInner(outer))
      return decodeInner(outer)->lookup_value(intern);
    else if (outer)
    {
      auto p = (std::pair<u64,T*>*)outer;
      if (p->first == intern) return p->second;
    }
    
    return 0;
  }

  u64 intern_value(T* val, u32 hash = -1)
  {
    if (hash == -1) hash = fasthash<T>(*val);
    // Takes a T*, interns if 
    u32 tophash = intern_buckets_mask & hash;
    void* old = table[tophash].load();

    if (old && hasInner(old))
      return decodeInner(old)->intern_value(val, hash, usedvecs[tophash&0x7f]);
    else if (old)
    {
      auto pair = (std::pair<u64,T*>*)old;
      if (*pair->second == *val) return pair->first;
      
      auto node = new InnerTable();
      const u64 sameintern = node->intern_value(pair->second, pair->first, usedvecs[tophash&0x7f]);
      if (pair->first != sameintern) fatal("Bad interning collision..");
      
      u64 intern = node->intern_value(val, hash, usedvecs[tophash&0x7f]);
      void* tagnode = (void*)(((u64)(void*)node) | 1);
      if (!table[tophash].compare_exchange_strong(old, tagnode))
      {
	node->wipe();
	delete node;
	return intern_value(val, hash);
      }
      /* // Why does this not work?? It appears to deadlock.
      // Delayed deletion of this pair
      std::pair<void*,void*>* oldp;
      std::pair<void*,void*>* p = 0;
      do
      {  // Add pair to the usedpairs list atomically
	oldp = usedpairs[tophash%128].load();
	if (p) delete p;
	p = new std::pair<void*,void*>((void*)pair, (void*)oldp);
      }
      while (usedpairs[tophash%128].compare_exchange_strong(oldp,p));
      */
      return intern;
    }
    else
    {
      u64 intern = hash & (0xffffffff >> (32-5-intern_buckets_bits));
      void* pair = (void*)new std::pair<u64,T*>(intern, val);
      if (!table[tophash].compare_exchange_strong(old, pair))
      {
	delete (std::pair<u64,T*>*)pair;
	return intern_value(val, hash);
      }
      
      return intern;
    }
  }
  
  struct iterator  // Not thread-safe when operated on! For dumping the DB only.
  {
    InternTable* table;
    u32 outer_pos, inner_pos, innermost_pos, stop_pos;

    iterator(InternTable* t,  u32 p0)
      : table(t), outer_pos(p0), inner_pos(0), innermost_pos(0), stop_pos(intern_buckets)
    {
      if (!hasValue()) ++(*this);
    }

    iterator(InternTable* t,  u32 p0, u32 p1)
      : table(t), outer_pos(p0), inner_pos(0), innermost_pos(0), stop_pos(p1)
    {
      if (!hasValue()) ++(*this);
    }

    bool hasValue()
    {
      if (outer_pos == intern_buckets) return false;
      void* outer = table->table[outer_pos].load(); 
      return outer && (!hasInner(outer) || decodeInner(outer)->data[0].load());
    }

    void scan_outer()
    {
      inner_pos = 0;
      innermost_pos = 0;
      void* outer; 
      do
      {
	if (++outer_pos >= stop_pos)
	{
	  outer_pos = intern_buckets;
	  return;
	}
	outer = table->table[outer_pos].load(); 
      }
      while (outer == 0 && outer_pos < intern_buckets);
      
      if (outer_pos < intern_buckets && hasInner(outer))
      {
	// If it's a node and there is nothing in data[0], scan_inner()
	if (decodeInner(outer)->data[0].load() == 0)
	  scan_inner();
      }
    }

    void scan_inner()
    {
      void* outer = table->table[outer_pos].load();
      auto inner = decodeInner(outer);
      auto vec = inner->data[inner_pos].load();

      if (vec && vec->size() > ++innermost_pos) return;
      innermost_pos = 0;
      
      do
      {
	if (++inner_pos < 32)
	  vec = inner->data[inner_pos].load();
	else
	{
	  scan_outer();
	  return;
	}
      }
      while(vec == 0);
    }
        
    T& operator*() const
    {
      void* outer = table->table[outer_pos].load();
      if (hasInner(outer))
        return *decodeInner(outer)->data[inner_pos].load()->operator[](innermost_pos);
      else
	return *((std::pair<u64,T*>*)outer)->second;
    }
    
    iterator& operator ++()
    {
      if (outer_pos < stop_pos)
      {
	void* outer = table->table[outer_pos].load();
	if (outer == 0 || hasInner(outer) == 0)
	  scan_outer();
	else
	  scan_inner();
	return *this;
      }
      
      outer_pos = intern_buckets;
      return *this;
    }
    
    bool operator !=(const iterator& other) const
    {
      // only works for inequality with ->end()
      return outer_pos != other.outer_pos;
    }
  };
  
  iterator begin()
  {
    return iterator(this, 0);
  }

  iterator begin(u16 b)
  {
    if (b < intern_iterator_partitions - 1)
      return iterator(this, b*(intern_buckets/intern_iterator_partitions), (b+1)*(intern_buckets/intern_iterator_partitions));
    else
      return iterator(this, b*(intern_buckets/intern_iterator_partitions), intern_buckets);
  }
  
  iterator end()
  {
    return iterator(this, intern_buckets);
  }
  
};



 
} // namespace slog


