/*
** server.h for MyIRC in /home/jibb/rendu/PSU_2014_myirc/src/server
**
** Made by Jean-Baptiste Grégoire
** Login   <jibb@epitech.net>
**
** Started on  Wed Apr  8 00:02:55 2015 Jean-Baptiste Grégoire
** Last update Thu Apr  9 03:45:19 2015 Jean-Baptiste Grégoire
*/

#ifndef SERVER_H_
# define SERVER_H_

# include <sys/socket.h>
# include <netdb.h>
# include <arpa/inet.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>
# include <dirent.h>
# include <sys/ioctl.h>
# include "interface.h"
# include "list.h"

# define MAX_CONNEXION	100

enum			e_state
  {
    READY = 0, SENDING, RECEIVING, WAITING
  };

enum			e_right
  {
    CHANOP = 0, USER
  };

typedef enum e_state	t_state;
typedef enum e_state	t_right;
typedef struct timeval	t_timeval;

typedef struct		s_client
{
  int			fd;
  t_state		state;
  t_right		perms;
  char			login[32];
  char			user[32];
  char			chan[32];
  struct s_client	*next;
}			t_client;

typedef struct		s_chan
{
  char			name[32];
  t_client		*client_list;
}			t_chan;

typedef struct	s_server
{
  unsigned int	bfd;
  t_list	*client_list;
  t_list	*chan_list;
  int		serv_sock;
}		t_server;

#endif /* !SERVER_H_ */
