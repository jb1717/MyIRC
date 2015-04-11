/*
** server.h for MyIRC in /home/jibb/rendu/PSU_2014_myirc/src/server
**
** Made by Jean-Baptiste Grégoire
** Login   <jibb@epitech.net>
**
** Started on  Wed Apr  8 00:02:55 2015 Jean-Baptiste Grégoire
** Last update Sat Apr 11 03:24:10 2015 Jean-Baptiste Grégoire
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
# include "utils.h"
# include "c_buffer.h"

# define MAX_CONNEXION	100
# define BUF_READ	2048
# define MAX(a, b)	((a) > (b) ? (a) : (b))

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
  t_list		*chan_list;
  t_cbuffer		buf;
  struct s_client	*next;
}			t_client;

typedef struct		s_chan
{
  char			name[32];
  t_list		*client_list;
}			t_chan;

typedef struct	s_server
{
  fd_set	active_fd_read;
  fd_set	active_fd_write;
  t_list	*client_list;
  t_list	*chan_list;
  char		*input;
  int		bfd;
  int		serv_sock;
}		t_server;

typedef struct	s_func
{
  char		*name;
  int		(*func)(t_server *s, t_client *client, char **param);
  int		nb_args;
}		t_func;

typedef struct	s_rpl
{
  uint16_t	n;
  char		*msg;
}		t_rpl;

int		call_func(t_server *s, t_client *client, char *input);
int		handle_event(t_server *s, fd_set *rfds, fd_set *wfds);
int		cmp_elem__client(void *elem1, void *elem2);
int		nick_func(t_server *s, t_client *client, char **param);
int		user_func(t_server *s, t_client *client, char **param);
int		quit_func(t_server *s, t_client *client, char **param);
int		message_func(t_server *s, t_client *client, char **param);
int		list_func(t_server *s, t_client *client, char **param);
void		send_rpl(t_client *dest, int n, ...);
void		send_message(t_client *dest, char *message);

#endif /* !SERVER_H_ */
