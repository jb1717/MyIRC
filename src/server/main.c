
/*
** main.c for MyIRC in /home/jibb/rendu/PSU_2014_myirc/src/server
**
** Made by Jean-Baptiste Grégoire
** Login   <jibb@epitech.net>
**
** Started on  Tue Apr  7 23:30:03 2015 Jean-Baptiste Grégoire
** Last update Sat Apr 11 01:59:18 2015 Jean-Baptiste Grégoire
*/

#include "server.h"

int		serv_init(t_server *s, int port)
{
  if (!(s->serv_sock = inet__create_sock(port, "TCP", AF_INET, MAX_CONNEXION)))
    return (-1);
  FD_ZERO(&(s->active_fd_read));
  FD_ZERO(&(s->active_fd_write));
  s->client_list = NULL;
  s->chan_list = NULL;
  s->bfd = s->serv_sock;
  s->input = NULL;
  return (0);
}

void		display_clients(t_list *clients)
{
  t_list	*it;
  t_client	*client;

  it = clients;
  printf("LIST DES CLIENTS\n");
  while (it)
    {
      client = it->data;
      printf("fd = %d // login = %s // user = %s\n",
	     client->fd, client->login, client->user);
      it = it->next;
    }
  printf("*** FIN ***\n");
}

int		serv_loop(t_server *s)
{
  int		err;
  fd_set	readfds;
  fd_set	writefds;
  t_timeval	timeout;

  err = 1;
  FD_SET(s->serv_sock, &(s->active_fd_read));
  FD_ZERO(&readfds);
  FD_ZERO(&writefds);
  while (err != -1)
    {
      readfds = s->active_fd_read;
      writefds = s->active_fd_write;
      timeout.tv_sec = 120;
      timeout.tv_usec = 0;
      err = select(s->bfd + 1, &readfds, &writefds, NULL, &timeout);
      if (handle_event(s, &readfds, &writefds) == -1)
	err = -1;
      display_clients(s->client_list);
    }
  return (-1);
}

int		main(int argc, char **argv)
{
  t_server	server;

  if (argc != 2)
    {
      fprintf(stderr, "Usage: %s [port]\n", argv[0]);
      return (EXIT_FAILURE);
    }
  bzero(&server, sizeof(t_server));
  if (serv_init(&server, atoi(argv[1])) == -1)
    {
      perror("Initialisation failed");
      return (EXIT_FAILURE);
    }
  if (serv_loop(&server) == -1)
    {
      perror("Runtime error");
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
