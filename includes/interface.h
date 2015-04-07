/*
** interface.h for MyIRC in /home/jibb/rendu/PSU_2014_myirc/src/interface
**
** Made by Jean-Baptiste Grégoire
** Login   <jibb@epitech.net>
**
** Started on  Tue Apr  7 16:31:21 2015 Jean-Baptiste Grégoire
** Last update Tue Apr  7 16:58:12 2015 Jean-Baptiste Grégoire
*/

#ifndef INTERFACE_H_
# define INTERFACE_H_

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/socket.h>
# include <netdb.h>
# include <arpa/inet.h>
# include <sys/types.h>
# include <limits.h>
# include <errno.h>

# define UNUSED(a)	__attribute__((unused))a
# define BUF_SIZE	1024

enum		e_conversion
  {
    GET_PORT = 0, SET_PORT
  };

typedef struct	s_iport
{
  char		*ip;
  int		port;
  uint8_t	p1;
  uint8_t	p2;
  char		iport[24];
  char		padding[2];
}		t_iport;

int		inet__create_sock(int port, char *protocol, int domain,
				  int max_connexions);
int		inet__get_sock(char *ip, int port, char *protocol, int domain);
void		inet__format_ip_address(char *ip, int port, t_iport *s,
					enum e_conversion e);
void		inet__convert_port(uint8_t *p1, uint8_t *p2,
				   int *p, enum e_conversion e);

#endif /* !INTERFACE */
