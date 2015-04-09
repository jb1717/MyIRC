/*
** circular_buffer.h for MyIRC in /home/jibb/rendu/PSU_2014_myirc/src
**
** Made by Jean-Baptiste Grégoire
** Login   <jibb@epitech.net>
**
** Started on  Wed Apr  8 16:51:44 2015 Jean-Baptiste Grégoire
** Last update Wed Apr  8 22:26:55 2015 Jean-Baptiste Grégoire
*/

#ifndef C_BUFFER_H_
# define C_BUFFER_H_

# include <string.h>
# include <strings.h>
# include <stdlib.h>
# include "utils.h"

# define BUF_SIZE	8

typedef struct	s_cbuffer
{
  char		buf[BUF_SIZE];
  unsigned int	write_pos;
  unsigned int	read_pos;
}		t_cbuffer;

void		cbuffer__init(t_cbuffer *cbuf);
void		cbuffer__write(t_cbuffer *cbuf, char *str, size_t size);
char		*cbuffer__read(t_cbuffer *cbuf, size_t size);

#endif /* !C_BUFFER_H_ */
