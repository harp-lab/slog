/** Slog gzip interface
 * 
 * Defines a minimal C++ interface to zlib for reading/writing gzipped database files
 *
 * Copyright (C) Thomas Gilray, Kristopher Micinski, Sidharth Kumar, et al., 2023 
 * Some rights reserved. See License.md for details.
 * 
 ******************************/


#pragma once


#include "slogd.h"
#include <zlib.h>
#include <fstream>



// To globally turn on write compression:
//#define db_out_ext ".bin.gz" 
//#define DBWriteFile GzWriteFile 


// or, to globally turn off write compression:
#define db_out_ext ".bin" 
#define DBWriteFile BinWriteFile




namespace slog
{
  
  static void *Zalloc(void *q, unsigned n, unsigned m)
  {
    (void)q;
    return calloc(n, m);
  }

  static void Zfree(void *q, void *p)
  {
    (void)q;
    free(p);
  }

  class GzWriteFile
  {    
  public:
    std::ofstream file;
    z_stream stream;
      
    GzWriteFile(const std::string& path)
      : file(path, std::ios::binary)
    {
      stream.zalloc = Zalloc;
      stream.zfree = Zfree;
      stream.opaque = Z_NULL;
      if (deflateInit2(&stream, -1, 8, 15 + 16, 8, 0) != Z_OK)
	fatal("DeflateInit2 failed when writing file!");
    }

    ~GzWriteFile()
    {
      static u8 outbuf[16384];
      stream.next_in = Z_NULL;
      stream.avail_in = 0;
      do
      {
	stream.next_out = outbuf;
	stream.avail_out = sizeof(outbuf);
	deflate(&stream, Z_FINISH);
	file.write((const char*)outbuf, sizeof(outbuf) - stream.avail_out);
      }
      while (stream.avail_out == 0);
      deflateEnd(&stream);
      file.close();
    }

    void write(u8* buf, u32 len)
    {
      static u8 outbuf[16384];	
      stream.next_in = buf;
      stream.avail_in = len;
      do
      {
	stream.next_out = outbuf;
	stream.avail_out = sizeof(outbuf);
	(void)deflate(&stream, Z_NO_FLUSH);
	file.write((const char*)outbuf, sizeof(outbuf) - stream.avail_out);
      }
      while (stream.avail_out == 0);
    }
  };

  class GzReadFile
  {    
  public:
    std::string path;
    std::ifstream file;
    z_stream stream;
      
    GzReadFile(const std::string& _path)
      : path(_path), file(path, std::ios::binary)
    {
      stream.zalloc = Zalloc;
      stream.zfree = Zfree;
      stream.opaque = Z_NULL;
      stream.next_in = 0;
      stream.avail_in = Z_NULL;
      if (inflateInit2(&stream, 15 + 16) != Z_OK)
	fatal("inflateInit2 failed when reading file!");
    }

    ~GzReadFile()
    {
      inflateEnd(&stream);
      file.close();
    }

    
    u32 read(u8* buf, u32 len)
    {
      u8 byte[1];
      stream.next_out = buf;
      stream.avail_out = len;
      do
      {
        if (!file.read((char*)byte, 1))
	  break;
        stream.next_in = byte;
        stream.avail_in = 1;
	int rcode = inflate(&stream, Z_NO_FLUSH);
	if (stream.msg != 0)
	  std::cout << stream.msg << std::endl;
        if (rcode == Z_DATA_ERROR)
	  fatal("Error running inflate from libz.");
        if (rcode == Z_STREAM_END)
	  inflateReset(&stream);
      }
      while (stream.avail_out > 0);
      return len - stream.avail_out;
    }
  };

  class BinWriteFile
  {    
  public:
    std::string path;
    std::ofstream file;
      
    BinWriteFile(const std::string& _path)
      : path(_path), file(path, std::ios::binary)
    {
    }

    ~BinWriteFile()
    {
      file.close();
    }

    void write(u8* buf, u32 len)
    {
      file.write((char*)buf, len);
    }
  };

  class BinReadFile
  {    
  public:
    std::string path;
    std::ifstream file;
      
    BinReadFile(const std::string& _path)
      : path(_path), file(path, std::ios::binary)
    {
    }

    ~BinReadFile()
    {
      file.close();
    }

    
    u32 read(u8* buf, u32 len)
    {
      return (bool)file.read((char*)buf,len);
    }
  };
  
} // namespace slog


