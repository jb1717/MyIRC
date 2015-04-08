/*
** server.h for MyIRC in /home/jibb/rendu/PSU_2014_myirc/src/server
**
** Made by Jean-Baptiste Grégoire
** Login   <jibb@epitech.net>
**
** Started on  Wed Apr  8 00:02:55 2015 Jean-Baptiste Grégoire
** Last update Wed Apr  8 01:48:14 2015 Jean-Baptiste Grégoire
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

typedef struct	s_server
{
  int		serv_sock;
  t_client	*client_list;
  t_chan	*chan_list;
}		t_server;

#endif /* !SERVER_H_ */
