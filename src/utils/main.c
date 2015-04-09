#include <stdio.h>
#include <unistd.h>
#include "c_buffer.h"

int		main(void)
{
  t_cbuffer	cbuf;
  char		*ret;

  cbuffer__init(&cbuf);
  cbuffer__write(&cbuf, "bon", 3);
  ret = cbuffer__read(&cbuf, 2);
  printf("[%s]\n", ret);
  cbuffer__write(&cbuf, "jour", 4);
  free(ret);
  ret = cbuffer__read(&cbuf, 4);
  write(1, cbuf. buf, 8);
  printf("\n");
  printf("ret = [%s]\n", ret);
  free(ret);
  return (0);
}
