/*
  fsm@robots.ox.ac.uk
*/
#ifdef __GNUC__
#pragma implementation "vil_16bit"
#endif
#include "vil_16bit.h"
#include <vil/vil_stream.h>
#include <vxl_compiler_config.h>

typedef unsigned vxl_int8  word8;
typedef unsigned vxl_int16 word16;

unsigned vxl_int16 vil_16bit_read_big_endian(vil_stream *s)
{
  word8 bytes[2];
  s->read(bytes, sizeof bytes);
  return word16(bytes[1]) + 256*word16(bytes[2]);
}

unsigned vxl_int16 vil_16bit_read_little_endian(vil_stream *s)
{
  word8 bytes[2];
  s->read(bytes, sizeof bytes);
  return word16(bytes[0]) + 256*word16(bytes[1]);
}

void vil_16bit_write_big_endian(vil_stream *s, unsigned vxl_int16 w)
{
  word8 bytes[2];
#if VXL_LITTLE_ENDIAN
  bytes[0] = w >> 8;
  bytes[1] = w;
#else
  bytes[0] = w;
  bytes[1] = w >> 8;
#endif
  s->write(bytes, sizeof bytes);
}

void vil_16bit_write_little_endian(vil_stream *s, unsigned vxl_int16 w)
{
  word8 bytes[2];
#if VXL_LITTLE_ENDIAN
  bytes[0] = w;
  bytes[1] = w >> 8;
#else
  bytes[0] = w >> 8;
  bytes[1] = w;
#endif
  s->write(bytes, sizeof bytes);
}
