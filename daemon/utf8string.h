/** Slog Intern Header
 * 
 * Defines a basic immutable unicode string class and some related functionality.
 *
 * Copyright (C) Thomas Gilray, Kristopher Micinski, Sidharth Kumar, et al., 2025 
 * Some rights reserved. See License.md for details.
 * 
 ******************************/


#pragma once


#include "types.h"
#include "utf8.h"
#include <string>
#include <cstring>



namespace slog
{



class utf8string
{
private:
  u32 cpsize, bytesize;
  char* data;
  
public:
  utf8string(char* cstr, u32 bs, u32 cps)
    : cpsize(cps), bytesize(bs), data(cstr)
  {}
  
  utf8string(const char* cstr)
  {
    bytesize = ((u32)0)-1;
    cpsize = 0;
    init(cstr);
  }
  
  utf8string(const char* cstr, u32 bytelen)
  {
    bytesize = bytelen;
    cpsize = 0;
    init(cstr);
  }

  utf8string(const std::string& str)
  {
    bytesize = str.size();
    cpsize = 0;
    init(str.c_str());
  }

  utf8string(utf8string&& str)
  {
    bytesize = str.bytesize;
    cpsize = str.cpsize;
    data = str.data;
    str.bytesize = 0;
    str.cpsize = 0;
    str.data = 0;
  }

  ~utf8string()
  {
    if (data) delete[] data;
  }

  void init(const char* cstr) 
  {
    if (bytesize == ((u32)0)-1)
      for (bytesize = 0; cstr[bytesize]; ++bytesize)
	;
    data = new char[bytesize+1];
    
    u32 codepoint;
    u32 state = 0;
    for (u32 i = 0; i < bytesize; ++i)
    {
      data[i] = cstr[i];
      if (utf8decode(&state, &codepoint, cstr[i]) == 0)
	cpsize++;
    }
    data[bytesize] = 0;
    
    if (state != 0) fatal("Bad utf8 string.");
  }

  utf8string substr(u32 start, u32 len = -1) const
  {
    start = std::min(cpsize, start);
    len = std::min(len, cpsize-start);
    if (len == 0) return utf8string("");
    
    u32 codepoint;
    u32 state = 0;
    u32 bytestart = 0;
    for (; start > 0; ++bytestart)
      if (utf8decode(&state, &codepoint, data[bytestart]) == 0)
	--start;
    u32 bytelen = 0;
    for (; len > 0; ++bytelen)
      if (utf8decode(&state, &codepoint, data[bytestart+bytelen]) == 0)
	--len;
    return utf8string(data+bytestart, bytelen);
  }

  utf8string operator+(const utf8string& str2)
  {
    char* cstr = new char[bytesize + str2.bytesize + 1];
    std::memcpy(cstr,data,bytesize);
    std::memcpy(cstr+bytesize,str2.data,str2.bytesize);
    cstr[bytesize + str2.bytesize] = 0;
    return utf8string(cstr,bytesize+str2.bytesize,cpsize+str2.cpsize);
  }

  u32 operator[](u32 pos) const
  {
    if (pos >= cpsize) return 0;
    
    u32 codepoint;
    u32 state = 0;
    u32 cppos = 0;
    for (u32 i = 0; cppos <= pos; ++i)
      if (utf8decode(&state, &codepoint, data[i]) == 0)
	++cppos;
    return codepoint;
  }

  bool operator==(const utf8string& str) const
  {
    if (bytesize != str.bytesize) return false;
    for (u32 i = 0; i < bytesize; ++i)
      if (data[i] != str.data[i])
	return false;
    return true;
  }

  bool operator!=(const utf8string& str) const
  {
    return !this->operator==(str);
  }

  u32 size() const
  {
    return cpsize;
  }

  u32 byte_size() const
  {
    return bytesize;
  }

  std::string cpp_str() const
  {
    return std::string(data);
  }
    
  const char* c_str() const
  {
    return data;
  }
};

  


}  // namespace slog  


