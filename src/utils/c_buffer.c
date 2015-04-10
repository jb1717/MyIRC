/*
** circular_buffer.c for MyIRC in /home/jibb/rendu/PSU_2014_myirc/src
**
** Made by Jean-Baptiste Grégoire
** Login   <jibb@epitech.net>
**
** Started on  Wed Apr  8 16:51:52 2015 Jean-Baptiste Grégoire
** Last update Fri Apr 10 15:33:33 2015 Jean-Baptiste Grégoire
*/

#include "c_buffer.h"

void		cbuffer__init(t_cbuffer *cbuf)
{
  bzero(cbuf->buf, CBUF_SIZE);
  cbuf->write_pos = 0;
  cbuf->read_pos = 0;
}

void		cbuffer__write(t_cbuffer *cbuf, char *str, size_t size)
{
  unsigned int	rest;
  unsigned int	pos;
  unsigned int	to_write;
  char		turn;

  pos = 0;
  turn = 0;
  while (size > 0)
    {
      rest = (CBUF_SIZE - cbuf->write_pos);
      if (rest >= size)
	to_write = size;
      else
	to_write = rest;
      memcpy((void *)((size_t)(cbuf->buf) + cbuf->write_pos),
	     (void *)((size_t)(str) + pos), to_write);
      pos += rest;
      size -= to_write;
      cbuf->write_pos = (cbuf->write_pos + to_write) % CBUF_SIZE;
      if (cbuf->write_pos > cbuf->read_pos && turn)
	cbuf->read_pos = cbuf->write_pos;
      turn = 1;
    }
}

void		cbuffer__put_back(t_cbuffer *cbuf, char *str, size_t size)
{
  int		pos_tmp;

  pos_tmp = cbuf->write_pos;
  pos_tmp -= (pos_tmp % CBUF_SIZE);
  if (pos_tmp < 0)
    pos_tmp += CBUF_SIZE;
  cbuf->write_pos = pos_tmp;
  cbuffer__write(cbuf, str, size);
}

char		*cbuffer__read(t_cbuffer *cbuf, size_t size)
{
  char		*ret;
  char		*buf;
  unsigned int	rest;
  unsigned int	to_read;

  ret = NULL;
  while (size > 0)
    {
      rest = (CBUF_SIZE - cbuf->read_pos);
      if (rest >= size)
	to_read = size;
      else
	to_read = rest;
      if ((buf = malloc(sizeof(char) * (to_read + 1))) == NULL)
	return (NULL);
      bzero(buf, to_read + 1);
      memcpy(buf, (void *)((size_t)(cbuf->buf) + cbuf->read_pos),
	     to_read);
      bzero((void *)((size_t)(cbuf->buf) + cbuf->read_pos), to_read);
      ret = m_strcat(ret, buf);
      size -= to_read;
      cbuf->read_pos = (cbuf->read_pos + to_read) % CBUF_SIZE;
      free(buf);
    }
  return (ret);
}
