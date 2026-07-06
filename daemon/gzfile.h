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
    // Compressed input buffered ACROSS read() calls.  The previous
    // implementation fed inflate one file byte per iteration with the byte
    // in a stack local: when inflate filled the caller's buffer from pending
    // window-match output without consuming the byte, the next call
    // overwrote next_in and the byte was silently dropped -- repetitive
    // (well-compressing) data lost rows with no error.  Keeping unconsumed
    // input in a member buffer makes that impossible (and reads the file in
    // 16K chunks instead of one byte per inflate call).
    u8 inbuf[16384];
    // false once inflate has consumed data past a member's end without
    // reaching Z_STREAM_END -- input exhaustion in that state = truncation
    bool at_member_end = true;

    GzReadFile(const std::string& _path)
      : path(_path), file(path, std::ios::binary)
    {
      stream.zalloc = Zalloc;
      stream.zfree = Zfree;
      stream.opaque = Z_NULL;
      stream.next_in = inbuf;
      stream.avail_in = 0;
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
      stream.next_out = buf;
      stream.avail_out = len;
      while (stream.avail_out > 0)
      {
	if (stream.avail_in == 0)
	{
	  file.read((char*)inbuf, sizeof(inbuf));
	  const std::streamsize got = file.gcount();
	  if (got <= 0)
	  {
	    // out of compressed input: mid-member means a truncated file
	    if (!at_member_end && stream.avail_out < len)
	      return len - stream.avail_out;  // flush what we produced first
	    if (!at_member_end)
	      fatal("Truncated gzip stream: " + path);
	    break;
	  }
	  stream.next_in = inbuf;
	  stream.avail_in = (u32)got;
	}
	const int rcode = inflate(&stream, Z_NO_FLUSH);
	if (rcode == Z_STREAM_END)
	{
	  at_member_end = true;
	  // support concatenated members: reset keeps next_in/avail_in
	  inflateReset(&stream);
	  continue;
	}
	if (rcode == Z_OK)
	{
	  at_member_end = false;
	  continue;
	}
	if (rcode == Z_BUF_ERROR && stream.avail_in == 0)
	  continue;  // benign: need more input, loop refills
	fatal("Error running inflate from libz on " + path
	      + (stream.msg ? std::string(": ") + stream.msg : ""));
      }
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


